/*
 * Copyright (C) 2021 Patrick Mours
 * Copyright (C) 2014-2025 Omar Cornut
 * SPDX-License-Identifier: BSD-3-Clause OR MIT
 */

#if defined(RESHADE_API_LIBRARY_EXPORT) && RESHADE_ADDON && RESHADE_GUI

#include <new>
#include "imgui_function_table_19191.hpp"

const imgui_function_table_19191 init_imgui_function_table_19191() { return {
	ImGui::GetIO,
	ImGui::GetStyle,
	ImGui::GetVersion,
	ImGui::Begin,
	ImGui::End,
	ImGui::BeginChild,
	ImGui::BeginChild,
	ImGui::EndChild,
	ImGui::IsWindowAppearing,
	ImGui::IsWindowCollapsed,
	ImGui::IsWindowFocused,
	ImGui::IsWindowHovered,
	ImGui::GetWindowDrawList,
	ImGui::GetWindowDpiScale,
	ImGui::GetWindowPos,
	ImGui::GetWindowSize,
	ImGui::GetWindowWidth,
	ImGui::GetWindowHeight,
	ImGui::SetNextWindowPos,
	ImGui::SetNextWindowSize,
	ImGui::SetNextWindowSizeConstraints,
	ImGui::SetNextWindowContentSize,
	ImGui::SetNextWindowCollapsed,
	ImGui::SetNextWindowFocus,
	ImGui::SetNextWindowScroll,
	ImGui::SetNextWindowBgAlpha,
	ImGui::SetWindowPos,
	ImGui::SetWindowSize,
	ImGui::SetWindowCollapsed,
	ImGui::SetWindowFocus,
	ImGui::SetWindowFontScale,
	ImGui::SetWindowPos,
	ImGui::SetWindowSize,
	ImGui::SetWindowCollapsed,
	ImGui::SetWindowFocus,
	ImGui::GetScrollX,
	ImGui::GetScrollY,
	ImGui::SetScrollX,
	ImGui::SetScrollY,
	ImGui::GetScrollMaxX,
	ImGui::GetScrollMaxY,
	ImGui::SetScrollHereX,
	ImGui::SetScrollHereY,
	ImGui::SetScrollFromPosX,
	ImGui::SetScrollFromPosY,
	ImGui::PushFont,
	ImGui::PopFont,
	ImGui::PushStyleColor,
	ImGui::PushStyleColor,
	ImGui::PopStyleColor,
	ImGui::PushStyleVar,
	ImGui::PushStyleVar,
	ImGui::PushStyleVarX,
	ImGui::PushStyleVarY,
	ImGui::PopStyleVar,
	ImGui::PushItemFlag,
	ImGui::PopItemFlag,
	ImGui::PushItemWidth,
	ImGui::PopItemWidth,
	ImGui::SetNextItemWidth,
	ImGui::CalcItemWidth,
	ImGui::PushTextWrapPos,
	ImGui::PopTextWrapPos,
	ImGui::GetFont,
	ImGui::GetFontSize,
	ImGui::GetFontTexUvWhitePixel,
	ImGui::GetColorU32,
	ImGui::GetColorU32,
	ImGui::GetColorU32,
	ImGui::GetStyleColorVec4,
	ImGui::GetCursorScreenPos,
	ImGui::SetCursorScreenPos,
	ImGui::GetContentRegionAvail,
	ImGui::GetCursorPos,
	ImGui::GetCursorPosX,
	ImGui::GetCursorPosY,
	ImGui::SetCursorPos,
	ImGui::SetCursorPosX,
	ImGui::SetCursorPosY,
	ImGui::GetCursorStartPos,
	ImGui::Separator,
	ImGui::SameLine,
	ImGui::NewLine,
	ImGui::Spacing,
	ImGui::Dummy,
	ImGui::Indent,
	ImGui::Unindent,
	ImGui::BeginGroup,
	ImGui::EndGroup,
	ImGui::AlignTextToFramePadding,
	ImGui::GetTextLineHeight,
	ImGui::GetTextLineHeightWithSpacing,
	ImGui::GetFrameHeight,
	ImGui::GetFrameHeightWithSpacing,
	ImGui::PushID,
	ImGui::PushID,
	ImGui::PushID,
	ImGui::PushID,
	ImGui::PopID,
	ImGui::GetID,
	ImGui::GetID,
	ImGui::GetID,
	ImGui::GetID,
	ImGui::TextUnformatted,
	ImGui::TextV,
	ImGui::TextColoredV,
	ImGui::TextDisabledV,
	ImGui::TextWrappedV,
	ImGui::LabelTextV,
	ImGui::BulletTextV,
	ImGui::SeparatorText,
	ImGui::Button,
	ImGui::SmallButton,
	ImGui::InvisibleButton,
	ImGui::ArrowButton,
	ImGui::Checkbox,
	ImGui::CheckboxFlags,
	ImGui::CheckboxFlags,
	ImGui::RadioButton,
	ImGui::RadioButton,
	ImGui::ProgressBar,
	ImGui::Bullet,
	ImGui::TextLink,
	ImGui::TextLinkOpenURL,
	ImGui::Image,
	ImGui::ImageWithBg,
	ImGui::ImageButton,
	ImGui::BeginCombo,
	ImGui::EndCombo,
	ImGui::Combo,
	ImGui::Combo,
	ImGui::Combo,
	ImGui::DragFloat,
	ImGui::DragFloat2,
	ImGui::DragFloat3,
	ImGui::DragFloat4,
	ImGui::DragFloatRange2,
	ImGui::DragInt,
	ImGui::DragInt2,
	ImGui::DragInt3,
	ImGui::DragInt4,
	ImGui::DragIntRange2,
	ImGui::DragScalar,
	ImGui::DragScalarN,
	ImGui::SliderFloat,
	ImGui::SliderFloat2,
	ImGui::SliderFloat3,
	ImGui::SliderFloat4,
	ImGui::SliderAngle,
	ImGui::SliderInt,
	ImGui::SliderInt2,
	ImGui::SliderInt3,
	ImGui::SliderInt4,
	ImGui::SliderScalar,
	ImGui::SliderScalarN,
	ImGui::VSliderFloat,
	ImGui::VSliderInt,
	ImGui::VSliderScalar,
	ImGui::InputText,
	ImGui::InputTextMultiline,
	ImGui::InputTextWithHint,
	ImGui::InputFloat,
	ImGui::InputFloat2,
	ImGui::InputFloat3,
	ImGui::InputFloat4,
	ImGui::InputInt,
	ImGui::InputInt2,
	ImGui::InputInt3,
	ImGui::InputInt4,
	ImGui::InputDouble,
	ImGui::InputScalar,
	ImGui::InputScalarN,
	ImGui::ColorEdit3,
	ImGui::ColorEdit4,
	ImGui::ColorPicker3,
	ImGui::ColorPicker4,
	ImGui::ColorButton,
	ImGui::SetColorEditOptions,
	ImGui::TreeNode,
	ImGui::TreeNodeV,
	ImGui::TreeNodeV,
	ImGui::TreeNodeEx,
	ImGui::TreeNodeExV,
	ImGui::TreeNodeExV,
	ImGui::TreePush,
	ImGui::TreePush,
	ImGui::TreePop,
	ImGui::GetTreeNodeToLabelSpacing,
	ImGui::CollapsingHeader,
	ImGui::CollapsingHeader,
	ImGui::SetNextItemOpen,
	ImGui::SetNextItemStorageID,
	ImGui::Selectable,
	ImGui::Selectable,
	ImGui::BeginMultiSelect,
	ImGui::EndMultiSelect,
	ImGui::SetNextItemSelectionUserData,
	ImGui::IsItemToggledSelection,
	ImGui::BeginListBox,
	ImGui::EndListBox,
	ImGui::ListBox,
	ImGui::ListBox,
	ImGui::PlotLines,
	ImGui::PlotLines,
	ImGui::PlotHistogram,
	ImGui::PlotHistogram,
	ImGui::Value,
	ImGui::Value,
	ImGui::Value,
	ImGui::Value,
	ImGui::BeginMenuBar,
	ImGui::EndMenuBar,
	ImGui::BeginMainMenuBar,
	ImGui::EndMainMenuBar,
	ImGui::BeginMenu,
	ImGui::EndMenu,
	ImGui::MenuItem,
	ImGui::MenuItem,
	ImGui::BeginTooltip,
	ImGui::EndTooltip,
	ImGui::SetTooltipV,
	ImGui::BeginItemTooltip,
	ImGui::SetItemTooltipV,
	ImGui::BeginPopup,
	ImGui::BeginPopupModal,
	ImGui::EndPopup,
	ImGui::OpenPopup,
	ImGui::OpenPopup,
	ImGui::OpenPopupOnItemClick,
	ImGui::CloseCurrentPopup,
	ImGui::BeginPopupContextItem,
	ImGui::BeginPopupContextWindow,
	ImGui::BeginPopupContextVoid,
	ImGui::IsPopupOpen,
	ImGui::BeginTable,
	ImGui::EndTable,
	ImGui::TableNextRow,
	ImGui::TableNextColumn,
	ImGui::TableSetColumnIndex,
	ImGui::TableSetupColumn,
	ImGui::TableSetupScrollFreeze,
	ImGui::TableHeader,
	ImGui::TableHeadersRow,
	ImGui::TableAngledHeadersRow,
	ImGui::TableGetSortSpecs,
	ImGui::TableGetColumnCount,
	ImGui::TableGetColumnIndex,
	ImGui::TableGetRowIndex,
	ImGui::TableGetColumnName,
	ImGui::TableGetColumnFlags,
	ImGui::TableSetColumnEnabled,
	ImGui::TableGetHoveredColumn,
	ImGui::TableSetBgColor,
	ImGui::Columns,
	ImGui::NextColumn,
	ImGui::GetColumnIndex,
	ImGui::GetColumnWidth,
	ImGui::SetColumnWidth,
	ImGui::GetColumnOffset,
	ImGui::SetColumnOffset,
	ImGui::GetColumnsCount,
	ImGui::BeginTabBar,
	ImGui::EndTabBar,
	ImGui::BeginTabItem,
	ImGui::EndTabItem,
	ImGui::TabItemButton,
	ImGui::SetTabItemClosed,
	ImGui::DockSpace,
	ImGui::SetNextWindowDockID,
	ImGui::SetNextWindowClass,
	ImGui::GetWindowDockID,
	ImGui::IsWindowDocked,
	ImGui::BeginDragDropSource,
	ImGui::SetDragDropPayload,
	ImGui::EndDragDropSource,
	ImGui::BeginDragDropTarget,
	ImGui::AcceptDragDropPayload,
	ImGui::EndDragDropTarget,
	ImGui::GetDragDropPayload,
	ImGui::BeginDisabled,
	ImGui::EndDisabled,
	ImGui::PushClipRect,
	ImGui::PopClipRect,
	ImGui::SetItemDefaultFocus,
	ImGui::SetKeyboardFocusHere,
	ImGui::SetNavCursorVisible,
	ImGui::SetNextItemAllowOverlap,
	ImGui::IsItemHovered,
	ImGui::IsItemActive,
	ImGui::IsItemFocused,
	ImGui::IsItemClicked,
	ImGui::IsItemVisible,
	ImGui::IsItemEdited,
	ImGui::IsItemActivated,
	ImGui::IsItemDeactivated,
	ImGui::IsItemDeactivatedAfterEdit,
	ImGui::IsItemToggledOpen,
	ImGui::IsAnyItemHovered,
	ImGui::IsAnyItemActive,
	ImGui::IsAnyItemFocused,
	ImGui::GetItemID,
	ImGui::GetItemRectMin,
	ImGui::GetItemRectMax,
	ImGui::GetItemRectSize,
	ImGui::GetBackgroundDrawList,
	ImGui::GetForegroundDrawList,
	ImGui::IsRectVisible,
	ImGui::IsRectVisible,
	ImGui::GetTime,
	ImGui::GetFrameCount,
	ImGui::GetDrawListSharedData,
	ImGui::GetStyleColorName,
	ImGui::SetStateStorage,
	ImGui::GetStateStorage,
	ImGui::CalcTextSize,
	ImGui::ColorConvertU32ToFloat4,
	ImGui::ColorConvertFloat4ToU32,
	ImGui::ColorConvertRGBtoHSV,
	ImGui::ColorConvertHSVtoRGB,
	ImGui::IsKeyDown,
	ImGui::IsKeyPressed,
	ImGui::IsKeyReleased,
	ImGui::IsKeyChordPressed,
	ImGui::GetKeyPressedAmount,
	ImGui::GetKeyName,
	ImGui::SetNextFrameWantCaptureKeyboard,
	ImGui::Shortcut,
	ImGui::SetNextItemShortcut,
	ImGui::SetItemKeyOwner,
	ImGui::IsMouseDown,
	ImGui::IsMouseClicked,
	ImGui::IsMouseReleased,
	ImGui::IsMouseDoubleClicked,
	ImGui::IsMouseReleasedWithDelay,
	ImGui::GetMouseClickedCount,
	ImGui::IsMouseHoveringRect,
	ImGui::IsMousePosValid,
	ImGui::IsAnyMouseDown,
	ImGui::GetMousePos,
	ImGui::GetMousePosOnOpeningCurrentPopup,
	ImGui::IsMouseDragging,
	ImGui::GetMouseDragDelta,
	ImGui::ResetMouseDragDelta,
	ImGui::GetMouseCursor,
	ImGui::SetMouseCursor,
	ImGui::SetNextFrameWantCaptureMouse,
	ImGui::GetClipboardText,
	ImGui::SetClipboardText,
	ImGui::SetAllocatorFunctions,
	ImGui::GetAllocatorFunctions,
	ImGui::MemAlloc,
	ImGui::MemFree,
	[](const imgui_storage_19191 *_this, ImGuiID key, int default_val) -> int { return _this->GetInt(key, default_val); },
	[](imgui_storage_19191 *_this, ImGuiID key, int val) -> void { _this->SetInt(key, val); },
	[](const imgui_storage_19191 *_this, ImGuiID key, bool default_val) -> bool { return _this->GetBool(key, default_val); },
	[](imgui_storage_19191 *_this, ImGuiID key, bool val) -> void { _this->SetBool(key, val); },
	[](const imgui_storage_19191 *_this, ImGuiID key, float default_val) -> float { return _this->GetFloat(key, default_val); },
	[](imgui_storage_19191 *_this, ImGuiID key, float val) -> void { _this->SetFloat(key, val); },
	[](const imgui_storage_19191 *_this, ImGuiID key) -> void *{ return _this->GetVoidPtr(key); },
	[](imgui_storage_19191 *_this, ImGuiID key, void *val) -> void { _this->SetVoidPtr(key, val); },
	[](imgui_storage_19191 *_this, ImGuiID key, int default_val) -> int *{ return _this->GetIntRef(key, default_val); },
	[](imgui_storage_19191 *_this, ImGuiID key, bool default_val) -> bool *{ return _this->GetBoolRef(key, default_val); },
	[](imgui_storage_19191 *_this, ImGuiID key, float default_val) -> float *{ return _this->GetFloatRef(key, default_val); },
	[](imgui_storage_19191 *_this, ImGuiID key, void *default_val) -> void **{ return _this->GetVoidPtrRef(key, default_val); },
	[](imgui_storage_19191 *_this) -> void { _this->BuildSortByKey(); },
	[](imgui_storage_19191 *_this, int val) -> void { _this->SetAllInt(val); },
	[](imgui_list_clipper_19191 *_this) -> void { new(_this) imgui_list_clipper_19191(); },
	[](imgui_list_clipper_19191 *_this) -> void { _this->~imgui_list_clipper_19191(); },
	[](imgui_list_clipper_19191 *_this, int items_count, float items_height) -> void { _this->Begin(items_count, items_height); },
	[](imgui_list_clipper_19191 *_this) -> void { _this->End(); },
	[](imgui_list_clipper_19191 *_this) -> bool { return _this->Step(); },
	[](imgui_list_clipper_19191 *_this, int item_begin, int item_end) -> void { _this->IncludeItemsByIndex(item_begin, item_end); },
	[](imgui_list_clipper_19191 *_this, int item_index) -> void { _this->SeekCursorForItem(item_index); },
	[](imgui_draw_list_19191 *_this, ImDrawListSharedData *shared_data) -> void { new(_this) imgui_draw_list_19191(shared_data); },
	[](imgui_draw_list_19191 *_this) -> void { _this->~imgui_draw_list_19191(); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &clip_rect_min, const ImVec2 &clip_rect_max, bool intersect_with_current_clip_rect) -> void { _this->PushClipRect(clip_rect_min, clip_rect_max, intersect_with_current_clip_rect); },
	[](imgui_draw_list_19191 *_this) -> void { _this->PushClipRectFullScreen(); },
	[](imgui_draw_list_19191 *_this) -> void { _this->PopClipRect(); },
	[](imgui_draw_list_19191 *_this, ImTextureID texture_id) -> void { _this->PushTextureID(texture_id); },
	[](imgui_draw_list_19191 *_this) -> void { _this->PopTextureID(); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &p1, const ImVec2 &p2, ImU32 col, float thickness) -> void { _this->AddLine(p1, p2, col, thickness); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &p_min, const ImVec2 &p_max, ImU32 col, float rounding, ImDrawFlags flags, float thickness) -> void { _this->AddRect(p_min, p_max, col, rounding, flags, thickness); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &p_min, const ImVec2 &p_max, ImU32 col, float rounding, ImDrawFlags flags) -> void { _this->AddRectFilled(p_min, p_max, col, rounding, flags); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &p_min, const ImVec2 &p_max, ImU32 col_upr_left, ImU32 col_upr_right, ImU32 col_bot_right, ImU32 col_bot_left) -> void { _this->AddRectFilledMultiColor(p_min, p_max, col_upr_left, col_upr_right, col_bot_right, col_bot_left); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &p1, const ImVec2 &p2, const ImVec2 &p3, const ImVec2 &p4, ImU32 col, float thickness) -> void { _this->AddQuad(p1, p2, p3, p4, col, thickness); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &p1, const ImVec2 &p2, const ImVec2 &p3, const ImVec2 &p4, ImU32 col) -> void { _this->AddQuadFilled(p1, p2, p3, p4, col); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &p1, const ImVec2 &p2, const ImVec2 &p3, ImU32 col, float thickness) -> void { _this->AddTriangle(p1, p2, p3, col, thickness); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &p1, const ImVec2 &p2, const ImVec2 &p3, ImU32 col) -> void { _this->AddTriangleFilled(p1, p2, p3, col); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &center, float radius, ImU32 col, int num_segments, float thickness) -> void { _this->AddCircle(center, radius, col, num_segments, thickness); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &center, float radius, ImU32 col, int num_segments) -> void { _this->AddCircleFilled(center, radius, col, num_segments); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &center, float radius, ImU32 col, int num_segments, float thickness) -> void { _this->AddNgon(center, radius, col, num_segments, thickness); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &center, float radius, ImU32 col, int num_segments) -> void { _this->AddNgonFilled(center, radius, col, num_segments); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &center, const ImVec2 &radius, ImU32 col, float rot, int num_segments, float thickness) -> void { _this->AddEllipse(center, radius, col, rot, num_segments, thickness); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &center, const ImVec2 &radius, ImU32 col, float rot, int num_segments) -> void { _this->AddEllipseFilled(center, radius, col, rot, num_segments); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &pos, ImU32 col, const char *text_begin, const char *text_end) -> void { _this->AddText(pos, col, text_begin, text_end); },
	[](imgui_draw_list_19191 *_this, imgui_font_19191 *font, float font_size, const ImVec2 &pos, ImU32 col, const char *text_begin, const char *text_end, float wrap_width, const ImVec4 *cpu_fine_clip_rect) -> void { _this->AddText(font, font_size, pos, col, text_begin, text_end, wrap_width, cpu_fine_clip_rect); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &p1, const ImVec2 &p2, const ImVec2 &p3, const ImVec2 &p4, ImU32 col, float thickness, int num_segments) -> void { _this->AddBezierCubic(p1, p2, p3, p4, col, thickness, num_segments); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &p1, const ImVec2 &p2, const ImVec2 &p3, ImU32 col, float thickness, int num_segments) -> void { _this->AddBezierQuadratic(p1, p2, p3, col, thickness, num_segments); },
	[](imgui_draw_list_19191 *_this, const ImVec2 *points, int num_points, ImU32 col, ImDrawFlags flags, float thickness) -> void { _this->AddPolyline(points, num_points, col, flags, thickness); },
	[](imgui_draw_list_19191 *_this, const ImVec2 *points, int num_points, ImU32 col) -> void { _this->AddConvexPolyFilled(points, num_points, col); },
	[](imgui_draw_list_19191 *_this, const ImVec2 *points, int num_points, ImU32 col) -> void { _this->AddConcavePolyFilled(points, num_points, col); },
	[](imgui_draw_list_19191 *_this, ImTextureID user_texture_id, const ImVec2 &p_min, const ImVec2 &p_max, const ImVec2 &uv_min, const ImVec2 &uv_max, ImU32 col) -> void { _this->AddImage(user_texture_id, p_min, p_max, uv_min, uv_max, col); },
	[](imgui_draw_list_19191 *_this, ImTextureID user_texture_id, const ImVec2 &p1, const ImVec2 &p2, const ImVec2 &p3, const ImVec2 &p4, const ImVec2 &uv1, const ImVec2 &uv2, const ImVec2 &uv3, const ImVec2 &uv4, ImU32 col) -> void { _this->AddImageQuad(user_texture_id, p1, p2, p3, p4, uv1, uv2, uv3, uv4, col); },
	[](imgui_draw_list_19191 *_this, ImTextureID user_texture_id, const ImVec2 &p_min, const ImVec2 &p_max, const ImVec2 &uv_min, const ImVec2 &uv_max, ImU32 col, float rounding, ImDrawFlags flags) -> void { _this->AddImageRounded(user_texture_id, p_min, p_max, uv_min, uv_max, col, rounding, flags); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &center, float radius, float a_min, float a_max, int num_segments) -> void { _this->PathArcTo(center, radius, a_min, a_max, num_segments); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &center, float radius, int a_min_of_12, int a_max_of_12) -> void { _this->PathArcToFast(center, radius, a_min_of_12, a_max_of_12); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &center, const ImVec2 &radius, float rot, float a_min, float a_max, int num_segments) -> void { _this->PathEllipticalArcTo(center, radius, rot, a_min, a_max, num_segments); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &p2, const ImVec2 &p3, const ImVec2 &p4, int num_segments) -> void { _this->PathBezierCubicCurveTo(p2, p3, p4, num_segments); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &p2, const ImVec2 &p3, int num_segments) -> void { _this->PathBezierQuadraticCurveTo(p2, p3, num_segments); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &rect_min, const ImVec2 &rect_max, float rounding, ImDrawFlags flags) -> void { _this->PathRect(rect_min, rect_max, rounding, flags); },
	[](imgui_draw_list_19191 *_this, ImDrawCallback callback, void *userdata, size_t userdata_size) -> void { _this->AddCallback(callback, userdata, userdata_size); },
	[](imgui_draw_list_19191 *_this) -> void { _this->AddDrawCmd(); },
	[](const imgui_draw_list_19191 *_this) -> imgui_draw_list_19191 *{ return _this->CloneOutput(); },
	[](imgui_draw_list_19191 *_this, int idx_count, int vtx_count) -> void { _this->PrimReserve(idx_count, vtx_count); },
	[](imgui_draw_list_19191 *_this, int idx_count, int vtx_count) -> void { _this->PrimUnreserve(idx_count, vtx_count); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &a, const ImVec2 &b, ImU32 col) -> void { _this->PrimRect(a, b, col); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &a, const ImVec2 &b, const ImVec2 &uv_a, const ImVec2 &uv_b, ImU32 col) -> void { _this->PrimRectUV(a, b, uv_a, uv_b, col); },
	[](imgui_draw_list_19191 *_this, const ImVec2 &a, const ImVec2 &b, const ImVec2 &c, const ImVec2 &d, const ImVec2 &uv_a, const ImVec2 &uv_b, const ImVec2 &uv_c, const ImVec2 &uv_d, ImU32 col) -> void { _this->PrimQuadUV(a, b, c, d, uv_a, uv_b, uv_c, uv_d, col); },
	[](imgui_font_19191 *_this) -> void { new(_this) imgui_font_19191(); },
	[](imgui_font_19191 *_this) -> void { _this->~imgui_font_19191(); },
	[](imgui_font_19191 *_this, ImWchar c) -> ImFontGlyph *{ return _this->FindGlyph(c); },
	[](imgui_font_19191 *_this, ImWchar c) -> ImFontGlyph *{ return _this->FindGlyphNoFallback(c); },
	[](imgui_font_19191 *_this, float size, float max_width, float wrap_width, const char *text_begin, const char *text_end, const char **remaining) -> ImVec2 { return _this->CalcTextSizeA(size, max_width, wrap_width, text_begin, text_end, remaining); },
	[](imgui_font_19191 *_this, float scale, const char *text, const char *text_end, float wrap_width) -> const char *{ return _this->CalcWordWrapPositionA(scale, text, text_end, wrap_width); },
	[](imgui_font_19191 *_this, imgui_draw_list_19191 *draw_list, float size, const ImVec2 &pos, ImU32 col, ImWchar c) -> void { _this->RenderChar(draw_list, size, pos, col, c); },
	[](imgui_font_19191 *_this, imgui_draw_list_19191 *draw_list, float size, const ImVec2 &pos, ImU32 col, const ImVec4 &clip_rect, const char *text_begin, const char *text_end, float wrap_width, bool cpu_fine_clip) -> void { _this->RenderText(draw_list, size, pos, col, clip_rect, text_begin, text_end, wrap_width, cpu_fine_clip); },

}; }

#endif
