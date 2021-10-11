

const char* blofeld::field_id_to_string(blofeld::e_field_id field)
{
	using namespace blofeld;
#define FIELD_ID_TO_STRING(_field) if(field == _field) return #_field;

	FIELD_ID_TO_STRING(_field_id_default);
	FIELD_ID_TO_STRING(_field_id_field_group_begin);
	FIELD_ID_TO_STRING(_field_id_field_group_end);
	FIELD_ID_TO_STRING(_field_id_point);
	FIELD_ID_TO_STRING(_field_id_orientation);
	FIELD_ID_TO_STRING(_field_id_scale);
	FIELD_ID_TO_STRING(_field_id_decibels);
	FIELD_ID_TO_STRING(_field_id_cents);
	FIELD_ID_TO_STRING(_field_id_zero_data);
	FIELD_ID_TO_STRING(_field_id_hide);
	FIELD_ID_TO_STRING(_field_id_hide_begin);
	FIELD_ID_TO_STRING(_field_id_hide_end);
	FIELD_ID_TO_STRING(_field_id_filter);
	FIELD_ID_TO_STRING(_field_id_type);
	FIELD_ID_TO_STRING(_field_id_name);
	FIELD_ID_TO_STRING(_field_id_marker);
	FIELD_ID_TO_STRING(_field_id_slider_editor);
	FIELD_ID_TO_STRING(_field_id_halo_script_block);
	FIELD_ID_TO_STRING(_field_id_unknown_facing);
	FIELD_ID_TO_STRING(_field_id_dont_checksum_begin);
	FIELD_ID_TO_STRING(_field_id_dont_checksum_end);
	FIELD_ID_TO_STRING(_field_id_cinematic_playback);
	FIELD_ID_TO_STRING(_field_id_cinematic_scene_flags);
	FIELD_ID_TO_STRING(_field_id_cinematic_frame_index);
	FIELD_ID_TO_STRING(_field_id_cinematic_version);
	FIELD_ID_TO_STRING(_field_id_cinematic_dynamic_light);
	FIELD_ID_TO_STRING(_field_id_camera_matrix_editor);
	FIELD_ID_TO_STRING(_field_id_loop_cinematic_shot);
	FIELD_ID_TO_STRING(_field_id_loop_cinematic_scene);
	FIELD_ID_TO_STRING(_field_id_function_input_scalar);
	FIELD_ID_TO_STRING(_field_id_function_input_range);
	FIELD_ID_TO_STRING(_field_id_function_output_modifier_input);
	FIELD_ID_TO_STRING(_field_id_function_unknown);
	FIELD_ID_TO_STRING(_field_id_pathfinding);
	FIELD_ID_TO_STRING(_field_id_object_id);
	FIELD_ID_TO_STRING(_field_id_object_variant);
	FIELD_ID_TO_STRING(_field_id_environment_unknown);
	FIELD_ID_TO_STRING(_field_id_squad_template);
	FIELD_ID_TO_STRING(_field_id_bitmap_show);
	FIELD_ID_TO_STRING(_field_id_manual_bsp_flags);
	FIELD_ID_TO_STRING(_field_id_scenario_zone_set_index);
	FIELD_ID_TO_STRING(_field_id_block_index_flags);
	FIELD_ID_TO_STRING(_field_id_block_flags_32bit);
	FIELD_ID_TO_STRING(_field_id_shader_template);
	FIELD_ID_TO_STRING(_field_id_shader_unknown);
	FIELD_ID_TO_STRING(_field_id_import_model);
	FIELD_ID_TO_STRING(_field_id_high_level_model_tag);
	FIELD_ID_TO_STRING(_field_id_sound_player);
	FIELD_ID_TO_STRING(_field_id_unknown_player);
	FIELD_ID_TO_STRING(_field_id_unknown_maeo);
	FIELD_ID_TO_STRING(_field_id_unknown_ohoc);
	FIELD_ID_TO_STRING(_field_id_unknown_function);
	FIELD_ID_TO_STRING(_field_id_unknown_compile);
	FIELD_ID_TO_STRING(_field_id_decorator_brush_unknown);
	FIELD_ID_TO_STRING(_field_id_text_unknown);
	FIELD_ID_TO_STRING(_field_id_unknown_ugh);
	FIELD_ID_TO_STRING(_field_id_unknown_mela);
	FIELD_ID_TO_STRING(_field_id_ifp_begin);
	FIELD_ID_TO_STRING(_field_id_ifp_end);
	FIELD_ID_TO_STRING(_field_id_authored_light_probe);
	FIELD_ID_TO_STRING(_field_id_particle_estimate_overdraw_unknown);
	FIELD_ID_TO_STRING(_field_id_hologram_light);
	FIELD_ID_TO_STRING(_field_id_object_editor);
	FIELD_ID_TO_STRING(_field_id_grid);
	FIELD_ID_TO_STRING(_field_id_sort);
	FIELD_ID_TO_STRING(_field_id_slap);
	FIELD_ID_TO_STRING(_field_id_wide);
	FIELD_ID_TO_STRING(_field_id_function_output_modifier);
	FIELD_ID_TO_STRING(_field_id_dumb);
	FIELD_ID_TO_STRING(_field_id_ugpc);
	FIELD_ID_TO_STRING(_field_id_enum);
	FIELD_ID_TO_STRING(_field_id_function_editor);
	FIELD_ID_TO_STRING(_field_id_archive_pointer);
	FIELD_ID_TO_STRING(_field_id_sted);
	FIELD_ID_TO_STRING(_field_id_parent);
	FIELD_ID_TO_STRING(_field_id_edit);
	FIELD_ID_TO_STRING(_field_id_npik);
	FIELD_ID_TO_STRING(_field_id_ai_point);
	FIELD_ID_TO_STRING(_field_id_function_constant_value);
	FIELD_ID_TO_STRING(_field_id_editablepropertybaseforceflags);
	FIELD_ID_TO_STRING(_field_id_bspf_unknown_bsp);
	FIELD_ID_TO_STRING(_field_id_usqd_unknown_squad);
	FIELD_ID_TO_STRING(_field_id_gnvb_unknown_graph_node);
	FIELD_ID_TO_STRING(_field_id_sky_lighting);
	FIELD_ID_TO_STRING(_field_id_malleablepropertybasefloat);
	FIELD_ID_TO_STRING(_field_id_malleablepropertybaseshort);
	FIELD_ID_TO_STRING(_field_id_malleablepropertybaseangle);
	
#undef FIELD_ID_TO_STRING

	return nullptr;
}
