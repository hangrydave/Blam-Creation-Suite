#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define BREAKABLE_SURFACE_KEY_TABLE_BLOCK_ID { 0x9815598B, 0x36884E51, 0x81CF6CB8, 0xAA8F19CD }
	TAG_BLOCK(
		breakable_surface_key_table_block,
		"breakable_surface_key_table_block",
		(SHORT_MAX),
		"s_strucure_physics_breakable_surface_key_value",
		BREAKABLE_SURFACE_KEY_TABLE_BLOCK_ID)
	{
		{ _field_short_integer, "instanced geometry index!*" },
		{ _field_byte_integer, "breakable surface set index!*" },
		{ _field_byte_integer, "breakable surface index!*" },
		{ _field_long_integer, "seed surface index!*" },
		{ _field_real, "x0!*" },
		{ _field_real, "x1!*" },
		{ _field_real, "y0!*" },
		{ _field_real, "y1!*" },
		{ _field_real, "z0!*" },
		{ _field_real, "z1!*" },
		{ _field_terminator }
	};

	#define SOFT_SURFACES_DEFINITION_BLOCK_ID { 0xBD13C0EA, 0x830B4239, 0xA55BF0F4, 0xCEC129A9 }
	TAG_BLOCK(
		soft_surfaces_definition_block,
		"soft_surfaces_definition_block",
		1,
		"s_soft_surfaces_definition",
		SOFT_SURFACES_DEFINITION_BLOCK_ID)
	{
		{ _field_pad, "CLASS_NONE", 4 },
		{ _field_real, "class biped#max - .2f" },
		{ _field_real, "class dead biped#max - .09f" },
		{ _field_real, "class crates + vehicles#max - .2f" },
		{ _field_real, "class debris#max - .04f" },
		{ _field_pad, "CLASS_ALL", 4 },
		{ _field_terminator }
	};

	#define STRUCTURE_SOFT_CEILING_BLOCK_ID { 0x51FDFC81, 0xC7EF4920, 0x8C353CCA, 0x2A23FF5D }
	TAG_BLOCK(
		structure_soft_ceiling_block,
		"structure_soft_ceiling_block",
		k_maximum_structure_soft_ceilings_count,
		"s_structure_soft_ceiling",
		STRUCTURE_SOFT_CEILING_BLOCK_ID)
	{
		{ _field_string_id, "name*!" },
		{ _field_enum, "type!*", &soft_ceiling_type_enum },
		{ _field_pad, "fresh", 2 },
		{ _field_block, "soft ceiling triangles!*", &structure_soft_ceiling_triangle_block },
		{ _field_terminator }
	};

	#define STRUCTURE_SOFT_CEILING_TRIANGLE_BLOCK_ID { 0xF75BE784, 0x41744702, 0xA1F258E9, 0x2CD5B9E4 }
	TAG_BLOCK(
		structure_soft_ceiling_triangle_block,
		"structure_soft_ceiling_triangle_block",
		k_maximum_structure_soft_ceiling_triangles,
		"s_structure_soft_ceiling_triangle",
		STRUCTURE_SOFT_CEILING_TRIANGLE_BLOCK_ID)
	{
		{ _field_real_plane_3d, "plane!*" },
		{ _field_real_point_3d, "bounding sphere center!*" },
		{ _field_real, "bounding sphere radius!*" },
		{ _field_real_point_3d, "vertex0!*" },
		{ _field_real_point_3d, "vertex1!*" },
		{ _field_real_point_3d, "vertex2!*" },
		{ _field_terminator }
	};

	#define STRUCTURE_WATER_GROUPS_BLOCK_ID { 0xA1FDFC81, 0x07EF4920, 0xBC353CCA, 0x1A23FF5D }
	TAG_BLOCK(
		structure_water_groups_block,
		"structure_water_groups_block",
		k_maximum_structure_water_groups,
		"s_structure_physics_water_group",
		STRUCTURE_WATER_GROUPS_BLOCK_ID)
	{
		{ _field_string_id, "name*!" },
		{ _field_terminator }
	};

	#define STRUCTURE_WATER_INSTANCES_BLOCK_ID { 0xA1FDFC80, 0x07EF4921, 0xBC353CC2, 0x1A23FF53 }
	TAG_BLOCK(
		structure_water_instances_block,
		"structure_water_instances_block",
		k_maximum_structure_water_instances,
		"s_structure_physics_water_instance",
		STRUCTURE_WATER_INSTANCES_BLOCK_ID)
	{
		{ _field_short_block_index, "group*!" },
		{ _field_pad, "PAD0", 2 },
		{ _field_real_vector_3d, "flow velocity*!" },
		{ _field_real_argb_color, "fog color*!" },
		{ _field_real, "fog murkiness*!" },
		{ _field_block, "water planes block!*", &structure_water_instance_planes_block },
		{ _field_block, "water debug triangles block!*", &structure_water_instance_debug_triangles_block },
		{ _field_real_bounds, "bounds x*" },
		{ _field_real_bounds, "bounds y*" },
		{ _field_real_bounds, "bounds z*" },
		{ _field_terminator }
	};

	#define STRUCTURE_WATER_INSTANCE_PLANES_BLOCK_ID { 0xAAFDFC81, 0x0BEF4920, 0xBC353CCA, 0x1D23FF5D }
	TAG_BLOCK(
		structure_water_instance_planes_block,
		"structure_water_instance_planes_block",
		k_maximum_structure_water_instance_planes,
		"real_plane3d",
		STRUCTURE_WATER_INSTANCE_PLANES_BLOCK_ID)
	{
		{ _field_real_plane_3d, "plane*!" },
		{ _field_terminator }
	};

	#define STRUCTURE_WATER_INSTANCE_DEBUG_TRIANGLES_BLOCK_ID { 0xAAFDFA81, 0x0BEF4B20, 0xBC3530CA, 0x1D23FD5D }
	TAG_BLOCK(
		structure_water_instance_debug_triangles_block,
		"structure_water_instance_debug_triangles_block",
		k_maximum_structure_water_instance_debug_triangles,
		"s_structure_physics_water_instance_debug_triangle",
		STRUCTURE_WATER_INSTANCE_DEBUG_TRIANGLES_BLOCK_ID)
	{
		{ _field_real_point_3d, "point0*!" },
		{ _field_real_point_3d, "point1*!" },
		{ _field_real_point_3d, "point2*!" },
		{ _field_terminator }
	};

	#define GLOBAL_STRUCTURE_PHYSICS_STRUCT_ID { 0x85AE0045, 0x53D34FA6, 0x8EF153FA, 0x77162294 }
	TAG_STRUCT(
		global_structure_physics_struct,
		"global_structure_physics_struct",
		"global_structure_physics_struct",
		GLOBAL_STRUCTURE_PHYSICS_STRUCT_ID)
	{
		{ _field_block, "breakable surfaces mopp code block!*", &mopp_code_definition_block },
		{ _field_block, "breakable surfaace key table", &breakable_surface_key_table_block },
		{ _field_terminator }
	};

	#define GLOBAL_STRUCTURE_PHYSICS_DESIGN_STRUCT_ID { 0x85AE0A45, 0x13D34FA6, 0x8EB153FA, 0xA7162294 }
	TAG_STRUCT(
		global_structure_physics_design_struct,
		"global_structure_physics_design_struct",
		"global_structure_physics_design_struct",
		GLOBAL_STRUCTURE_PHYSICS_DESIGN_STRUCT_ID)
	{
		{ _field_long_integer, "importer version*!" },
		{ _field_block, "soft ceiling mopp code block!*", &mopp_code_definition_block },
		{ _field_block, "soft ceilings block!*", &structure_soft_ceiling_block },
		{ _field_block, "water mopp code!*", &mopp_code_definition_block },
		{ _field_block, "water groups block!*", &structure_water_groups_block },
		{ _field_block, "water instances block!*", &structure_water_instances_block },
		{ _field_terminator }
	};

	STRINGS(soft_ceiling_type_enum)
	{
		"acceleration",
		"soft kill",
		"slip surface"
	};
	STRING_LIST(soft_ceiling_type_enum, soft_ceiling_type_enum_strings, _countof(soft_ceiling_type_enum_strings));

} // namespace macaque

} // namespace blofeld
