/*
 * Copyright (C) 2021 Patrick Mours
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "d3d12_impl_device.hpp"
#include "d3d12_impl_command_list_immediate.hpp"
#include "d3d12_impl_type_convert.hpp"
#include "dll_log.hpp" // Include late to get 'hr_to_string' helper function

thread_local reshade::d3d12::command_list_immediate_impl *reshade::d3d12::command_list_immediate_impl::s_last_immediate_command_list = nullptr;

reshade::d3d12::command_list_immediate_impl::command_list_immediate_impl(device_impl *device, ID3D12CommandQueue *queue) :
	command_list_impl(device, nullptr),
	_parent_queue(queue)
{
	// Create multiple command allocators to buffer for multiple frames
	for (uint32_t i = 0; i < NUM_COMMAND_FRAMES; ++i)
	{
		_fence_value[i] = i;

		if (FAILED(_device_impl->_orig->CreateFence(_fence_value[i], D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&_fence[i]))))
			return;
		if (FAILED(_device_impl->_orig->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&_cmd_alloc[i]))))
			return;
	}

	// Create auto-reset event for synchronization
	_fence_event = CreateEvent(nullptr, FALSE, FALSE, nullptr);
	if (_fence_event == nullptr)
		return;

	// Create and open the command list for recording
	if (SUCCEEDED(_device_impl->_orig->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, _cmd_alloc[_cmd_index].get(), nullptr, IID_PPV_ARGS(&_orig))))
	{
		_orig->SetName(L"ReShade immediate command list");
		on_init();
	}

	s_last_immediate_command_list = this;
}
reshade::d3d12::command_list_immediate_impl::~command_list_immediate_impl()
{
	if (this == s_last_immediate_command_list)
		s_last_immediate_command_list = nullptr;

	if (_orig != nullptr)
		_orig->Release();
	if (_fence_event != nullptr)
		CloseHandle(_fence_event);

	// Signal to 'command_list_impl' destructor that this is an immediate command list
	_orig = nullptr;
}

void reshade::d3d12::command_list_immediate_impl::end_query(api::query_heap heap, api::query_type type, uint32_t index)
{
	command_list_impl::end_query(heap, type, index);

	const auto heap_object = reinterpret_cast<ID3D12QueryHeap *>(heap.handle);

	query_heap_extra_data extra_data;
	UINT extra_data_size = sizeof(extra_data);
	if (SUCCEEDED(heap_object->GetPrivateData(extra_data_guid, &extra_data_size, &extra_data)))
	{
		assert(extra_data.type == type);

		_orig->ResolveQueryData(heap_object, convert_query_type(type), index, 1, extra_data.readback_resource, static_cast<UINT64>(index) * get_query_size(type).first);

		extra_data.fences[index].second++;
		_current_query_fences.push_back(extra_data.fences[index]);
	}
}
void reshade::d3d12::command_list_immediate_impl::query_acceleration_structures(uint32_t count, const api::resource_view *acceleration_structures, api::query_heap heap, api::query_type type, uint32_t first)
{
	command_list_impl::query_acceleration_structures(count, acceleration_structures, heap, type, first);

	const auto heap_object = reinterpret_cast<ID3D12Resource *>(heap.handle);

	query_heap_extra_data extra_data;
	UINT extra_data_size = sizeof(extra_data);
	if (SUCCEEDED(heap_object->GetPrivateData(extra_data_guid, &extra_data_size, &extra_data)))
	{
		assert(extra_data.type == type);

		const uint32_t query_size = get_query_size(type).first;

		for (uint32_t i = 0; i < std::min(count, extra_data.count); ++i)
		{
			D3D12_RESOURCE_BARRIER barrier = { D3D12_RESOURCE_BARRIER_TYPE_TRANSITION };
			barrier.Transition.pResource = heap_object;
			barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
			barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_UNORDERED_ACCESS;
			barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_COPY_SOURCE;
			_orig->ResourceBarrier(1, &barrier);

			_orig->CopyBufferRegion(extra_data.readback_resource, static_cast<UINT64>(first) * query_size, heap_object, static_cast<UINT64>(first) * query_size, query_size);

			std::swap(barrier.Transition.StateBefore, barrier.Transition.StateAfter);
			_orig->ResourceBarrier(1, &barrier);

			extra_data.fences[first + i].second++;
			_current_query_fences.push_back(extra_data.fences[first + i]);
		}
	}
}

bool reshade::d3d12::command_list_immediate_impl::flush()
{
	s_last_immediate_command_list = this;

	if (!_has_commands)
		return true;
	_has_commands = false;

	_current_root_signature[0] = nullptr;
	_current_root_signature[1] = nullptr;
	_current_descriptor_heaps[0] = nullptr;
	_current_descriptor_heaps[1] = nullptr;

	assert(_orig != nullptr);

	if (const HRESULT hr = _orig->Close(); FAILED(hr))
	{
		log::message(log::level::error, "Failed to close immediate command list with error code %s!", reshade::log::hr_to_string(hr).c_str());

		_current_query_fences.clear();

		// A command list that failed to close can never be reset, so destroy it and create a new one
		_orig->Release(); _orig = nullptr;
		if (SUCCEEDED(_device_impl->_orig->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, _cmd_alloc[_cmd_index].get(), nullptr, IID_PPV_ARGS(&_orig))))
		{
			_orig->SetName(L"ReShade immediate command list");
			on_init();
		}

		return false;
	}

	_parent_queue->ExecuteCommandLists(1, reinterpret_cast<ID3D12CommandList *const *>(&_orig));

	if (const UINT64 sync_value = _fence_value[_cmd_index] + NUM_COMMAND_FRAMES;
		SUCCEEDED(_parent_queue->Signal(_fence[_cmd_index].get(), sync_value)))
		_fence_value[_cmd_index] = sync_value;

	// Signal all the fences associated with queries that ran with this command list
	for (const std::pair<ID3D12Fence *, UINT64> &fence : _current_query_fences)
		_parent_queue->Signal(fence.first, fence.second);
	_current_query_fences.clear();

	// Continue with next command list now that the current one was submitted
	_cmd_index = (_cmd_index + 1) % NUM_COMMAND_FRAMES;

	// Make sure all commands for the next command allocator have finished executing before reseting it
	if (_fence[_cmd_index]->GetCompletedValue() < _fence_value[_cmd_index])
	{
		if (SUCCEEDED(_fence[_cmd_index]->SetEventOnCompletion(_fence_value[_cmd_index], _fence_event)))
			WaitForSingleObject(_fence_event, INFINITE); // Event is automatically reset after this wait is released
	}

	// Reset command allocator before using it this frame again
	_cmd_alloc[_cmd_index]->Reset();

	// Reset command list using current command allocator and put it into the recording state
	if (const HRESULT hr = _orig->Reset(_cmd_alloc[_cmd_index].get(), nullptr); FAILED(hr))
	{
		log::message(log::level::error, "Failed to reset immediate command list with error code %s!", reshade::log::hr_to_string(hr).c_str());
		return false;
	}

	return true;
}
bool reshade::d3d12::command_list_immediate_impl::flush_and_wait()
{
	if (!_has_commands)
		return true;

	// Index is updated during flush below, so keep track of the current one to wait on
	const UINT cmd_index_to_wait_on = _cmd_index;

	if (!flush())
		return false;

	if (FAILED(_fence[cmd_index_to_wait_on]->SetEventOnCompletion(_fence_value[cmd_index_to_wait_on], _fence_event)))
		return false;
	return WaitForSingleObject(_fence_event, INFINITE) == WAIT_OBJECT_0;
}
