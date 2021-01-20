#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		item_group,
		ITEM_TAG,
		&object_group,
		OBJECT_TAG,
		item_block );

	TAG_BLOCK_FROM_STRUCT(
		item_block,
		"item_block",
		1,
		item_struct_definition);

	#define PREDICTED_BITMAPS_BLOCK_ID { 0x7A456E83, 0x479F4218, 0xBEF99B2A, 0x0736B520 }
	TAG_BLOCK(
		predicted_bitmaps_block,
		"predicted_bitmaps_block",
		8,
		"s_tag_reference",
		PREDICTED_BITMAPS_BLOCK_ID)
	{
		{ _field_tag_reference, "bitmap", &global_bitmap_reference },
		{ _field_terminator }
	};

	#define ITEM_STRUCT_DEFINITION_ID { 0x21CDF7E3, 0xAD94443E, 0xAE80968D, 0x8CFBEBBF }
	TAG_STRUCT(
		item_struct_definition,
		"item_struct_definition",
		"_item_definition",
		ITEM_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "object", &object_struct_definition },
		FIELD_CUSTOM("$$$ ITEM $$$", _custom_field_function_group_begin),
		{ _field_long_flags, "flags", &item_definition_flags },
		{ _field_short_integer, "OLD message index" },
		{ _field_short_integer, "sort order" },
		{ _field_real, "OLD multiplayer on-ground scale" },
		{ _field_real, "OLD campaign on-ground scale" },
		{ _field_explanation, "NEW hud messages", "everything you need to display shite" },
		{ _field_string_id, "pickup message" },
		{ _field_string_id, "swap message" },
		{ _field_string_id, "pickup message (dual)" },
		{ _field_string_id, "swap message (dual)" },
		{ _field_string_id, "picked up msg" },
		{ _field_string_id, "switch-to msg" },
		{ _field_string_id, "switch-to from ai msg" },
		{ _field_string_id, "notify empty msg" },
		{ _field_string_id, "notify overheated message" },
		{ _field_tag_reference, "collision sound", &global_sound_reference },
		{ _field_block, "predicted bitmaps", &predicted_bitmaps_block },
		{ _field_tag_reference, "detonation damage effect", &global_damage_reference },
		{ _field_real_bounds, "detonation delay:seconds" },
		{ _field_tag_reference, "detonating effect", &global_effect_reference },
		{ _field_tag_reference, "detonation effect", &global_effect_reference },
		{ _field_explanation, "Item scale settings", "because grenades look better as coconuts. 0==1" },
		{ _field_real, "ground scale" },
		{ _field_real, "small unit (armed)" },
		{ _field_real, "small unit (stowed)" },
		{ _field_real, "medium unit (armed)" },
		{ _field_real, "medium unit (stowed)" },
		{ _field_real, "large unit (armed)" },
		{ _field_real, "large unit (stowed)" },
		{ _field_real, "huge unit (armed)" },
		{ _field_real, "huge unit (stowed)" },
		{ _field_tag_reference, "grounded friction settings#If not present, the default from global.globals is used.", &global_grounded_friction_reference },
		{ _field_tag_reference, "Tossed Override# Used to override the object tossed when item owner is killed.  Is overridden by tossed weapon override.", &object_reference$3 },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		{ _field_terminator }
	};

	STRINGS(item_definition_flags)
	{
		"always maintains z up",
		"blocks headshots#like jackal shield",
		"use ground scale for all unspecified attachments",
		"fixup position upon detaching from parent",
		"fixup position after attaching to parent"
	};
	STRING_LIST(item_definition_flags, item_definition_flags_strings, _countof(item_definition_flags_strings));

	TAG_REFERENCE(object_reference$3, OBJECT_TAG);

	TAG_REFERENCE(global_item_reference, ITEM_TAG);

} // namespace macaque

} // namespace blofeld
