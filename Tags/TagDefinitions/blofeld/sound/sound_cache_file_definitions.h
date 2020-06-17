#pragma once

namespace blofeld
{

	constexpr unsigned long CACHE_FILE_SOUND_TAG = '$#!+';

	extern s_tag_group cache_file_sound_group;
	constexpr unsigned long SOUND_CACHE_FILE_GESTALT_TAG = 'ugh!';

	extern s_tag_group sound_cache_file_gestalt_group;

	extern s_tag_block_definition cache_file_sound_block_block;
	extern s_tag_struct_definition sound_gestalt_codec_block_block_struct;
	extern s_tag_block_definition sound_gestalt_codec_block_block;
	extern s_tag_struct_definition sound_gestalt_playback_block_block_struct;
	extern s_tag_block_definition sound_gestalt_playback_block_block;
	extern s_tag_struct_definition sound_gestalt_scale_block_block_struct;
	extern s_tag_block_definition sound_gestalt_scale_block_block;
	extern s_tag_struct_definition sound_gestalt_import_names_block_block_struct;
	extern s_tag_block_definition sound_gestalt_import_names_block_block;
	extern s_tag_struct_definition sound_gestalt_pitch_range_parameters_block_block_struct;
	extern s_tag_block_definition sound_gestalt_pitch_range_parameters_block_block;
	extern s_tag_struct_definition sound_gestalt_pitch_ranges_block_block_struct;
	extern s_tag_block_definition sound_gestalt_pitch_ranges_block_block;
	extern s_tag_struct_definition sound_gestalt_permutations_block_block_struct;
	extern s_tag_block_definition sound_gestalt_permutations_block_block;
	extern s_tag_struct_definition sound_gestalt_permutation_languages_block_block_struct;
	extern s_tag_block_definition sound_gestalt_permutation_languages_block_block;
	extern s_tag_struct_definition sound_gestalt_custom_playback_block_block_struct;
	extern s_tag_block_definition sound_gestalt_custom_playback_block_block;
	extern s_tag_struct_definition sound_gestalt_runtime_permutation_bit_vector_block_block_struct;
	extern s_tag_block_definition sound_gestalt_runtime_permutation_bit_vector_block_block;
	extern s_tag_struct_definition sound_gestalt_promotions_block_block_struct;
	extern s_tag_block_definition sound_gestalt_promotions_block_block;
	extern s_tag_struct_definition sound_gestalt_facial_animation_block_block_struct;
	extern s_tag_block_definition sound_gestalt_facial_animation_block_block;
	extern s_tag_struct_definition sound_gestalt_layer_markers_block_block_struct;
	extern s_tag_block_definition sound_gestalt_layer_markers_block_block;
	extern s_tag_block_definition sound_cache_file_gestalt_block_block;

	extern s_tag_struct_definition cache_file_sound_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition sound_cache_file_gestalt_struct_definition_struct_definition; // tag group

} // namespace blofeld
