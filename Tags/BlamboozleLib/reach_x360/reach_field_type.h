#pragma once

enum e_reach_x360_field_type : unsigned long
{
	_reach_x360_field_type_string,
	_reach_x360_field_type_long_string,
	_reach_x360_field_type_string_id,
	_reach_x360_field_type_old_string_id,
	_reach_x360_field_type_char_integer,
	_reach_x360_field_type_short_integer,
	_reach_x360_field_type_long_integer,
	_reach_x360_field_type_int64_integer,
	_reach_x360_field_type_angle,
	_reach_x360_field_type_tag,
	_reach_x360_field_type_char_enum,
	_reach_x360_field_type_short_enum,
	_reach_x360_field_type_long_enum,
	_reach_x360_field_type_long_flags,
	_reach_x360_field_type_word_flags,
	_reach_x360_field_type_byte_flags,
	_reach_x360_field_type_point_2d,
	_reach_x360_field_type_rectangle_2d,
	_reach_x360_field_type_rgb_color,
	_reach_x360_field_type_argb_color,
	_reach_x360_field_type_real,
	_reach_x360_field_type_real_fraction,
	_reach_x360_field_type_real_point_2d,
	_reach_x360_field_type_real_point_3d,
	_reach_x360_field_type_real_vector_2d,
	_reach_x360_field_type_real_vector_3d,
	_reach_x360_field_type_real_quaternion,
	_reach_x360_field_type_real_euler_angles_2d,
	_reach_x360_field_type_real_euler_angles_3d,
	_reach_x360_field_type_real_plane_2d,
	_reach_x360_field_type_real_plane_3d,
	_reach_x360_field_type_real_rgb_color,
	_reach_x360_field_type_real_argb_color,
	_reach_x360_field_type_real_hsv_color,
	_reach_x360_field_type_real_ahsv_color,
	_reach_x360_field_type_short_integer_bounds,
	_reach_x360_field_type_angle_bounds,
	_reach_x360_field_type_real_bounds,
	_reach_x360_field_type_fraction_bounds,
	_reach_x360_field_type_tag_reference,
	_reach_x360_field_type_block,
	_reach_x360_field_type_long_block_flags,
	_reach_x360_field_type_word_block_flags,
	_reach_x360_field_type_byte_block_flags,
	_reach_x360_field_type_char_block_index,
	_reach_x360_field_type_custom_char_block_index,
	_reach_x360_field_type_short_block_index,
	_reach_x360_field_type_custom_short_block_index,
	_reach_x360_field_type_long_block_index,
	_reach_x360_field_type_custom_long_block_index,
	_reach_x360_field_type_data,
	_reach_x360_field_type_vertex_buffer,
	_reach_x360_field_type_pad,
	_reach_x360_field_type_useless_pad,
	_reach_x360_field_type_skip,
	_reach_x360_field_type_explanation,
	_reach_x360_field_type_custom,
	_reach_x360_field_type_struct,
	_reach_x360_field_type_array,
	_reach_x360_field_type_pageable_resource,
	_reach_x360_field_type_api_interop,
	_reach_x360_field_type_terminator,
};

extern const char* reach_x360_field_type_to_string(e_reach_x360_field_type field_type);
extern const char* reach_x360_field_type_to_generic_field_type(e_reach_x360_field_type field_type);
