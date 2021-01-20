#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		rumble_group,
		RUMBLE_TAG,
		nullptr,
		INVALID_TAG,
		rumble_block );

	TAG_BLOCK_FROM_STRUCT(
		rumble_block,
		"rumble_block",
		1,
		rumble_struct_definition);

	#define RUMBLE_STRUCT_DEFINITION_ID { 0xA87A0F82, 0xD7044788, 0x8CCC9E6E, 0xC4B87FD1 }
	TAG_STRUCT(
		rumble_struct_definition,
		"rumble_struct_definition",
		"s_rumble_definition",
		RUMBLE_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "rumble", &rumble_definition_struct },
		{ _field_terminator }
	};

	#define RUMBLE_DEFINITION_STRUCT_ID { 0xF1DC7B29, 0x0B7B46B3, 0xBF03AEBC, 0x767187CF }
	TAG_STRUCT(
		rumble_definition_struct,
		"rumble_definition_struct",
		"s_rumble_definition",
		RUMBLE_DEFINITION_STRUCT_ID)
	{
		{ _field_explanation, "low frequency rumble", "" },
		{ _field_struct, "low frequency rumble", &rumble_frequency_definition_struct },
		{ _field_explanation, "high frequency rumble", "" },
		{ _field_struct, "high frequency rumble", &rumble_frequency_definition_struct },
		{ _field_terminator }
	};

	#define RUMBLE_FREQUENCY_DEFINITION_STRUCT_ID { 0xEA65C648, 0xFDA541ED, 0x98C4CA63, 0xC70E97CC }
	TAG_STRUCT(
		rumble_frequency_definition_struct,
		"rumble_frequency_definition_struct",
		"s_rumble_frequency_definition",
		RUMBLE_FREQUENCY_DEFINITION_STRUCT_ID)
	{
		{ _field_real, "duration:seconds" },
		FIELD_CUSTOM(nullptr, 0),
		{ _field_struct, "dirty whore", &mapping_function },
		{ _field_useless_pad },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_rumble_reference, RUMBLE_TAG);

} // namespace macaque

} // namespace blofeld
