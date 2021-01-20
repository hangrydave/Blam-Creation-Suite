#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		imposter_model_group,
		IMPOSTER_MODEL_TAG,
		nullptr,
		INVALID_TAG,
		imposter_model_block );

	#define RENDER_MODEL_STRUCT_DEFINITION_ID { 0x69FF7DC3, 0x07F94EB6, 0xA4788DFF, 0xBBF9621C }
	TAG_BLOCK(
		render_model_block,
		"render_model_block",
		1,
		"render_model_definition",
		RENDER_MODEL_STRUCT_DEFINITION_ID)
	{
		{ _field_string_id, "name*" },
		{ _field_word_flags, "flags*", &render_model_flags_definition },
		{ _field_word_integer, "version!" },
		FIELD_CUSTOM(nullptr, _custom_field_unknown_checksum_begin),
		{ _field_long_integer, "runtime import info checksum!" },
		FIELD_CUSTOM(nullptr, _custom_field_unknown_checksum_end),
		{ _field_block, "regions*", &render_model_region_block },
		{ _field_char_integer, "L1 section group index*:(low)" },
		{ _field_char_integer, "L2 section group index*:(high)" },
		{ _field_pad, "PUJJ", 2 },
		{ _field_long_block_index, "instance mesh index*" },
		{ _field_block, "instance placements", &global_render_model_instance_placement_block },
		{ _field_long_integer, "node list checksum*" },
		{ _field_block, "nodes*", &render_model_node_block },
		{ _field_block, "marker groups*", &render_model_marker_group_block },
		{ _field_block, "materials", &global_geometry_material_block },
		{ _field_block, "errors*", &global_error_report_categories_block },
		{ _field_real, "don\'t draw over camera cosine angle#dont draw fp model when camera > this angle cosine (-1,1) Sugg. -0.2. 0 disables." },
		{ _field_struct, "render geometry*", &global_render_geometry_struct },
		{ _field_block, "node map mapping*", &instance_node_map_mapping_block },
		{ _field_block, "volume samples", &volume_samples_block },
		{ _field_block, "runtime node orientations!", &default_node_orientations_block },
		{ _field_block, "bone groups", &RenderModelBoneGroupBlock_block },
		{ _field_explanation, "Static Lightmap", "" },
		{ _field_tag_reference, "structure meta data*", &Tag::Reference<struct StructureMetadata>::s_defaultDefinition },
		{ _field_tag_reference, "lightmap bsp data reference", &scenario_lightmap_bsp_data_reference },
		{ _field_tag_reference, "forge lightmap atlases", &RenderModelLightmapAtlasReference },
		{ _field_terminator }
	};

	TAG_GROUP(
		render_model_group,
		RENDER_MODEL_TAG,
		nullptr,
		INVALID_TAG,
		render_model_block );

	TAG_GROUP(
		render_model_lightmap_atlas_group,
		RENDER_MODEL_LIGHTMAP_ATLAS_TAG,
		nullptr,
		INVALID_TAG,
		render_model_lightmap_atlas_block );

	TAG_BLOCK_FROM_STRUCT(
		imposter_model_block,
		"imposter_model_block",
		1,
		imposter_model_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		render_model_lightmap_atlas_block,
		"render_model_lightmap_atlas_block",
		1,
		render_model_lightmap_atlas_struct_definition);

	#define IMPOSTER_MODE_NODE_BLOCK_ID { 0xAA9DAC5D, 0x8B574A67, 0xA94FD4D9, 0xE2D76CB1 }
	TAG_BLOCK(
		imposter_mode_node_block,
		"imposter_mode_node_block",
		k_kilo,
		"s_model_node_map_node",
		IMPOSTER_MODE_NODE_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_short_integer, "base node index" },
		{ _field_pad, "WAXI", 2 },
		{ _field_terminator }
	};

	#define RENDER_MODEL_REGION_BLOCK_ID { 0x5F23BC11, 0xB76B42D7, 0xA38C6C46, 0x1DEE5813 }
	TAG_BLOCK(
		render_model_region_block,
		"region",
		MAXIMUM_REGIONS_PER_MODEL,
		"render_model_region",
		RENDER_MODEL_REGION_BLOCK_ID)
	{
		{ _field_string_id, "name^*" },
		{ _field_block, "permutations*", &render_model_permutation_block },
		{ _field_terminator }
	};

	#define RENDER_MODEL_PERMUTATION_BLOCK_ID { 0x7900DDE2, 0x064B40BE, 0x8F806330, 0x878B35EB }
	TAG_BLOCK(
		render_model_permutation_block,
		"permutation",
		MAXIMUM_PERMUTATIONS_PER_MODEL_REGION,
		"render_model_permutation",
		RENDER_MODEL_PERMUTATION_BLOCK_ID)
	{
		{ _field_string_id, "name^*" },
		{ _field_short_integer, "mesh index*" },
		{ _field_short_integer, "mesh count*" },
		{ _field_string_id, "clone name*" },
		{ _field_long_flags, "instance mask 0-31*", &render_model_instance_bitfield_flags_definition },
		{ _field_long_flags, "instance mask 32-63*", &render_model_instance_bitfield_flags_definition },
		{ _field_long_flags, "instance mask 64-95*", &render_model_instance_bitfield_flags_definition },
		{ _field_long_flags, "instance mask 96-127*", &render_model_instance_bitfield_flags_definition },
		{ _field_terminator }
	};

	#define RENDER_MODEL_NODE_BLOCK_ID { 0xB74453B7, 0xD6E3402E, 0x8A1587D0, 0xEFBF22EA }
	TAG_BLOCK(
		render_model_node_block,
		"node",
		MAXIMUM_NODES_PER_MODEL,
		"render_model_node",
		RENDER_MODEL_NODE_BLOCK_ID)
	{
		{ _field_string_id, "name^*" },
		{ _field_short_block_index, "parent node*" },
		{ _field_short_block_index, "first child node*" },
		{ _field_short_block_index, "next sibling node*" },
		{ _field_pad, "RELFLFLLE", 2 },
		{ _field_real_point_3d, "default translation*" },
		{ _field_real_quaternion, "default rotation*" },
		{ _field_real_vector_3d, "inverse forward*" },
		{ _field_real_vector_3d, "inverse left*" },
		{ _field_real_vector_3d, "inverse up*" },
		{ _field_real_point_3d, "inverse position*" },
		{ _field_real, "inverse scale*" },
		{ _field_real, "distance from parent*" },
		FIELD_CUSTOM("Procedural Joint", _custom_field_function_group_begin),
		{ _field_char_enum, "procedure", &procedure_enum_definition },
		{ _field_char_enum, "procedure axis", &procedure_axis_enum_definition },
		{ _field_pad, "pad", 2 },
		{ _field_short_block_index, "procedure node A" },
		{ _field_short_block_index, "procedure node B" },
		{ _field_real, "procedure var 1" },
		{ _field_real, "procedure var 2" },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		{ _field_terminator }
	};

	#define RENDER_MODEL_MARKER_GROUP_BLOCK_ID { 0xE60694FA, 0xA9EC4D0D, 0x89E6238C, 0xF66CBE15 }
	TAG_BLOCK(
		render_model_marker_group_block,
		"marker group",
		MAXIMUM_MARKER_GROUPS_PER_RENDER_MODEL,
		"render_model_marker_group",
		RENDER_MODEL_MARKER_GROUP_BLOCK_ID)
	{
		{ _field_string_id, "name^*" },
		{ _field_block, "markers*", &render_model_marker_block },
		{ _field_terminator }
	};

	#define RENDER_MODEL_MARKER_BLOCK_ID { 0xD7CC940F, 0x39874D92, 0x808A0C39, 0x0AF0AC68 }
	TAG_BLOCK(
		render_model_marker_block,
		"marker",
		MAXIMUM_MARKERS_PER_RENDER_MODEL_MARKER_GROUP,
		"render_model_marker",
		RENDER_MODEL_MARKER_BLOCK_ID)
	{
		{ _field_char_integer, "region index*" },
		{ _field_char_integer, "permutation index*" },
		{ _field_byte_integer, "node index*" },
		{ _field_byte_flags, "flags", &render_model_marker_flags_definition },
		{ _field_real_point_3d, "translation*" },
		{ _field_real_quaternion, "rotation*" },
		{ _field_real, "scale" },
		{ _field_real_vector_3d, "direction*" },
		{ _field_terminator }
	};

	#define INSTANCE_NODE_MAP_MAPPING_BLOCK_ID { 0x1119ACFD, 0x0221F3EF, 0x38131BEE, 0x8441FBB8 }
	TAG_BLOCK(
		instance_node_map_mapping_block,
		"instance_node_map_mapping_block",
		MAXIMUM_NODES_PER_MODEL,
		"short",
		INSTANCE_NODE_MAP_MAPPING_BLOCK_ID)
	{
		{ _field_short_integer, "instance_node map region node index*" },
		{ _field_terminator }
	};

	#define VOLUME_SAMPLES_BLOCK_ID { 0x069D0DD6, 0x55E6413E, 0xAABD61B5, 0x3168B3C9 }
	TAG_BLOCK(
		volume_samples_block,
		"volume_samples_block",
		k_max_volume_samples_per_render_model,
		"s_volume_sample",
		VOLUME_SAMPLES_BLOCK_ID)
	{
		{ _field_real_vector_3d, "position" },
		{ _field_array, "radiance transfer matrix*", &radiance_transfer_matrix_array },
		{ _field_terminator }
	};

	#define DEFAULT_NODE_ORIENTATIONS_BLOCK_ID { 0xA3A5979B, 0x41D84244, 0xA1400226, 0xA5CD38C9 }
	TAG_BLOCK(
		default_node_orientations_block,
		"default_node_orientations_block",
		MAXIMUM_NODES_PER_MODEL,
		"real_orientation",
		DEFAULT_NODE_ORIENTATIONS_BLOCK_ID,
		4)
	{
		{ _field_real_quaternion, "rotation*" },
		{ _field_real_point_3d, "translation*" },
		{ _field_real, "scale*" },
		{ _field_terminator }
	};

	#define RENDERMODELBONEGROUPBLOCK_ID { 0x0CECE183, 0xA7D74D0A, 0xA78A641B, 0x0A8E8A6D }
	TAG_BLOCK(
		RenderModelBoneGroupBlock_block,
		"bone_group",
		MAXIMUM_BONE_GROUPS_PER_MODEL,
		"RenderModelBoneGroup",
		RENDERMODELBONEGROUPBLOCK_ID)
	{
		{ _field_string_id, "name^*" },
		{ _field_block, "bones*", &RenderModelNodeIndexBlock_block },
		{ _field_terminator }
	};

	#define RENDERMODELNODEINDEXBLOCK_ID { 0xEA52C9C3, 0x6EAF447E, 0x8B78348F, 0x9B765F30 }
	TAG_BLOCK(
		RenderModelNodeIndexBlock_block,
		"node_index",
		MAXIMUM_NODES_PER_MODEL,
		"short",
		RENDERMODELNODEINDEXBLOCK_ID)
	{
		{ _field_short_block_index, "node index^*" },
		{ _field_terminator }
	};

	#define RADIANCE_TRANSFER_MATRIX_ID { 0x0FA34AD9, 0x785D45B5, 0xA12B1861, 0x7B84E30C }
	TAG_ARRAY(
		radiance_transfer_matrix_array,
		"radiance_transfer_matrix",
		9*9,
		"real",
		RADIANCE_TRANSFER_MATRIX_ID)
	{
		{ _field_real, "element*!" },
		{ _field_terminator }
	};

	#define IMPOSTER_MODEL_STRUCT_DEFINITION_ID { 0x2A12A29F, 0xCF1C431E, 0x9FA1D5D2, 0xB805F111 }
	TAG_STRUCT(
		imposter_model_struct_definition,
		"imposter_model_struct_definition",
		"s_imposter_model",
		IMPOSTER_MODEL_STRUCT_DEFINITION_ID)
	{
		{ _field_string_id, "name*" },
		{ _field_short_integer, "quality" },
		{ _field_pad, "NBOML", 2 },
		{ _field_real, "brightness adjustment" },
		{ _field_block, "node maps", &imposter_mode_node_block },
		{ _field_block, "regions*", &render_model_region_block },
		FIELD_CUSTOM("render geometry", _custom_field_function_group_begin),
		{ _field_struct, "geometry*", &global_render_geometry_struct },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		{ _field_terminator }
	};

	#define RENDER_MODEL_LIGHTMAP_ATLAS_STRUCT_DEFINITION_ID { 0x00CA337E, 0x43CE7697, 0x0ABE1E3E, 0x1D862276 }
	TAG_STRUCT(
		render_model_lightmap_atlas_struct_definition,
		"render_model_lightmap_atlas_struct_definition",
		"RenderModelLightmapAtlas",
		RENDER_MODEL_LIGHTMAP_ATLAS_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "atlas geometry*", &global_render_geometry_struct },
		{ _field_real, "world scale ratio" },
		{ _field_terminator }
	};

	STRINGS(procedure_enum_definition)
	{
		"NONE",
		"multiply rotation"
	};
	STRING_LIST(procedure_enum_definition, procedure_enum_definition_strings, _countof(procedure_enum_definition_strings));

	STRINGS(procedure_axis_enum_definition)
	{
		"ALL",
		"Yaw (Maya Y)",
		"Pitch (Maya X)",
		"Roll (Maya Z)"
	};
	STRING_LIST(procedure_axis_enum_definition, procedure_axis_enum_definition_strings, _countof(procedure_axis_enum_definition_strings));

	STRINGS(render_model_flags_definition)
	{
		"is hologram",
		"UNUSED2",
		"has node maps",
		"has fur shader"
	};
	STRING_LIST(render_model_flags_definition, render_model_flags_definition_strings, _countof(render_model_flags_definition_strings));

	STRINGS(render_model_instance_bitfield_flags_definition)
	{
		"0",
		"1",
		"2",
		"3",
		"4",
		"5",
		"6",
		"7",
		"8",
		"9",
		"10",
		"11",
		"12",
		"13",
		"14",
		"15",
		"16",
		"17",
		"18",
		"19",
		"20",
		"21",
		"22",
		"23",
		"24",
		"25",
		"26",
		"27",
		"28",
		"29",
		"30",
		"31"
	};
	STRING_LIST(render_model_instance_bitfield_flags_definition, render_model_instance_bitfield_flags_definition_strings, _countof(render_model_instance_bitfield_flags_definition_strings));

	STRINGS(render_model_marker_flags_definition)
	{
		"has node relative direction"
	};
	STRING_LIST(render_model_marker_flags_definition, render_model_marker_flags_definition_strings, _countof(render_model_marker_flags_definition_strings));

	TAG_REFERENCE(RenderModelLightmapAtlasReference, RENDER_MODEL_LIGHTMAP_ATLAS_TAG);

} // namespace macaque

} // namespace blofeld
