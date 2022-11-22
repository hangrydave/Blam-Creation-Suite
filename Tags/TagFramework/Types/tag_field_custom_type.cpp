#include "tagframework-private-pch.h"

const char* blofeld::tag_field_custom_type_to_string(blofeld::e_tag_field_custom_type tag_field_custom_type)
{
	using namespace blofeld;
#define TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type) \
	if(tag_field_custom_type == blofeld::e_tag_field_custom_type::_tag_field_custom_type) return #_tag_field_custom_type;

	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_null_type);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_unknown_type);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_bitmap_group);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_tool_command);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_tool_command_with_directory);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_import_particle_model_command);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_model_bulk_import_command);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_estimate_overdraw_command);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_function_editor);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_vertical_layout);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_horizontal_layout);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_group_begin);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_group_end);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_end_layout);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_hide_group_begin);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_hide_group_end);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_filter_on_next_field);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_filter_on_next_field_folder);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_filter_on_next_field_both);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_editor_command);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_tag_template_view_command);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_designer_zone_block_index_flags);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_custom_button);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_field_group_begin);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_field_group_end);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_sound_playback);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_sound_marker_playback);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_tag_group_template);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_cinematic_dynamic_light);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_cinematic_vmf_light);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_custom_chud_state_editor_block);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_custom_chud_render_editor_block);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_marker_name_attribute);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_matched_element_array);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_individual_field_preview_group_begin);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_individual_field_preview_group_end);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_custom_object_function_field);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_scenario_and_zone_set);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_cinematic_playback);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_cinematic_playback_loop_scene);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_cinematic_playback_loop_shot);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_slider);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_unknown_object_editor);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_unknown_environment);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_unknown_pathfinding);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_unknown_facing);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_unknown_lflg);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_unknown_allg);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_unknown_camera_matrix_editor);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_unknown_whis);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_unknown_ghis);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_unknown_uhis);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_unknown_sply);
	TAG_FIELD_CUSTOM_TYPE_TO_STRING(_tag_field_custom_type_unknown_biqu);

#undef TAG_FIELD_CUSTOM_TYPE_TO_STRING

	return nullptr;
}
