

const char* blofeld::field_id_to_string(blofeld::e_field_id field)
{
	using namespace blofeld;
#define FIELD_ID_TO_STRING(_field) if(field == _field) return #_field;
	
	FIELD_ID_TO_STRING(_field_id_default);
	FIELD_ID_TO_STRING(_field_id_null);
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
	FIELD_ID_TO_STRING(_field_id_ascii);
	FIELD_ID_TO_STRING(_field_id_lflg);
	FIELD_ID_TO_STRING(_field_id_allg);
	FIELD_ID_TO_STRING(_field_id_bspX);
	FIELD_ID_TO_STRING(_field_id_bspY);
	FIELD_ID_TO_STRING(_field_id_rede);
	FIELD_ID_TO_STRING(_field_id_cflt);
	FIELD_ID_TO_STRING(_field_id_filx);
	FIELD_ID_TO_STRING(_field_id_auds);
	FIELD_ID_TO_STRING(_field_id_cseb);
	FIELD_ID_TO_STRING(_field_id_creb);
	FIELD_ID_TO_STRING(_field_id_prof);
	FIELD_ID_TO_STRING(_field_id_ghis);
	FIELD_ID_TO_STRING(_field_id_mply);
	FIELD_ID_TO_STRING(_field_id_uhis);
	FIELD_ID_TO_STRING(_field_id_pd64);
	FIELD_ID_TO_STRING(_field_id_pd32);
	FIELD_ID_TO_STRING(_field_id_align);
	FIELD_ID_TO_STRING(_field_id_sply);
	FIELD_ID_TO_STRING(_field_id_sobj);
	FIELD_ID_TO_STRING(_field_id_sper);
	FIELD_ID_TO_STRING(_field_id_sct3);
	FIELD_ID_TO_STRING(_field_id_ssct);
	FIELD_ID_TO_STRING(_field_id_sct2);
	FIELD_ID_TO_STRING(_field_id_swpt);
	FIELD_ID_TO_STRING(_field_id_sunt);
	FIELD_ID_TO_STRING(_field_id_sust);
	FIELD_ID_TO_STRING(_field_id_sdvt);
	FIELD_ID_TO_STRING(_field_id_slit);
	FIELD_ID_TO_STRING(_field_id_seqt);
	FIELD_ID_TO_STRING(_field_id__sc_);
	FIELD_ID_TO_STRING(_field_id_MAPP);
	FIELD_ID_TO_STRING(_field_id_BLOK);
	FIELD_ID_TO_STRING(_field_id_SCFN);
	FIELD_ID_TO_STRING(_field_id_CLFN);
	FIELD_ID_TO_STRING(_field_id_particle_property_scalar);
	FIELD_ID_TO_STRING(_field_id_particle_property_color);
	FIELD_ID_TO_STRING(_field_id_uncs);
	FIELD_ID_TO_STRING(_field_id_usas);
	FIELD_ID_TO_STRING(_field_id_uHnd);
	FIELD_ID_TO_STRING(_field_id_ubms);
	FIELD_ID_TO_STRING(_field_id_cmtb);
	FIELD_ID_TO_STRING(_field_id_unknown);
	FIELD_ID_TO_STRING(_field_id_ulYc);
	FIELD_ID_TO_STRING(_field_id_blod);
	FIELD_ID_TO_STRING(_field_id_chgr);
	FIELD_ID_TO_STRING(_field_id_chfl);
	FIELD_ID_TO_STRING(_field_id_chdd);
	FIELD_ID_TO_STRING(_field_id_chsn);
	FIELD_ID_TO_STRING(_field_id_chpy);
	FIELD_ID_TO_STRING(_field_id_nbmi);
	FIELD_ID_TO_STRING(_field_id_clpr);
	FIELD_ID_TO_STRING(_field_id_cbsp);
	FIELD_ID_TO_STRING(_field_id_DREZ);
	FIELD_ID_TO_STRING(_field_id_smht);
	FIELD_ID_TO_STRING(_field_id_sdst);
	FIELD_ID_TO_STRING(_field_id_sctt);
	FIELD_ID_TO_STRING(_field_id_slft);
	FIELD_ID_TO_STRING(_field_id_prli);
	FIELD_ID_TO_STRING(_field_id_scli);
	FIELD_ID_TO_STRING(_field_id_amli);
	FIELD_ID_TO_STRING(_field_id_lmsh);
	FIELD_ID_TO_STRING(_field_id_cnvs);
	FIELD_ID_TO_STRING(_field_id_ires);
	FIELD_ID_TO_STRING(_field_id_irem);
	FIELD_ID_TO_STRING(_field_id_MTLO);
	FIELD_ID_TO_STRING(_field_id_nhgs);
	FIELD_ID_TO_STRING(_field_id_aaim);
	FIELD_ID_TO_STRING(_field_id_apds);
	FIELD_ID_TO_STRING(_field_id_qoSS);
	FIELD_ID_TO_STRING(_field_id_MAgr);
	FIELD_ID_TO_STRING(_field_id_ANII);
	FIELD_ID_TO_STRING(_field_id_ATSS);
	FIELD_ID_TO_STRING(_field_id_MAgc);
	FIELD_ID_TO_STRING(_field_id_MArt);
	FIELD_ID_TO_STRING(_field_id_masd);
	FIELD_ID_TO_STRING(_field_id_SFDS);
	FIELD_ID_TO_STRING(_field_id_RFDS);
	FIELD_ID_TO_STRING(_field_id_RBDS);
	FIELD_ID_TO_STRING(_field_id_dsfx);
	FIELD_ID_TO_STRING(_field_id_SINF);
	FIELD_ID_TO_STRING(_field_id_SECT);
	FIELD_ID_TO_STRING(_field_id_mphp);
	FIELD_ID_TO_STRING(_field_id_msst);
	FIELD_ID_TO_STRING(_field_id_PDAT);
	FIELD_ID_TO_STRING(_field_id_ISQI);
	FIELD_ID_TO_STRING(_field_id_gapu);
	FIELD_ID_TO_STRING(_field_id_hwis);
	FIELD_ID_TO_STRING(_field_id_hwsd);
	FIELD_ID_TO_STRING(_field_id_hwef);
	FIELD_ID_TO_STRING(_field_id_nhd2);
	FIELD_ID_TO_STRING(_field_id_sebs);
	FIELD_ID_TO_STRING(_field_id_csbs);
	FIELD_ID_TO_STRING(_field_id_sd2s);
	FIELD_ID_TO_STRING(_field_id_avlb);
	FIELD_ID_TO_STRING(_field_id_shtb);
	FIELD_ID_TO_STRING(_field_id_GPUR);
	FIELD_ID_TO_STRING(_field_id_GPUS);
	FIELD_ID_TO_STRING(_field_id_scms);
	FIELD_ID_TO_STRING(_field_id_schs);
	FIELD_ID_TO_STRING(_field_id_svis);
	FIELD_ID_TO_STRING(_field_id_igri);
	FIELD_ID_TO_STRING(_field_id_spdf);
	FIELD_ID_TO_STRING(_field_id_rnli);
	FIELD_ID_TO_STRING(_field_id_ntor);
	FIELD_ID_TO_STRING(_field_id_sszd);
	FIELD_ID_TO_STRING(_field_id_spl1);
	FIELD_ID_TO_STRING(_field_id_ssfx);
	FIELD_ID_TO_STRING(_field_id_plsn);
	FIELD_ID_TO_STRING(_field_id_slpp);
	FIELD_ID_TO_STRING(_field_id_snsc);
	FIELD_ID_TO_STRING(_field_id_snpr);
	FIELD_ID_TO_STRING(_field_id_srpr);
	FIELD_ID_TO_STRING(_field_id_sngl);
	FIELD_ID_TO_STRING(_field_id_trcv);
	FIELD_ID_TO_STRING(_field_id_HVPH);
	FIELD_ID_TO_STRING(_field_id_mdps);
	FIELD_ID_TO_STRING(_field_id_easd);
	FIELD_ID_TO_STRING(_field_id_wtsf);
	FIELD_ID_TO_STRING(_field_id_wSiS);
	FIELD_ID_TO_STRING(_field_id_wItS);
	FIELD_ID_TO_STRING(_field_id_wtas);
	FIELD_ID_TO_STRING(_field_id_wtcs);
	FIELD_ID_TO_STRING(_field_id_wbde);
	FIELD_ID_TO_STRING(_field_id_WNDM);

	
#undef FIELD_ID_TO_STRING

	return nullptr;
}
