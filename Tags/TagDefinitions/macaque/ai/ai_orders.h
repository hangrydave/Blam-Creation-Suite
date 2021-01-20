#pragma once

namespace blofeld
{

namespace macaque
{

	extern s_tag_block_definition trigger_references_block;
	extern s_tag_struct_definition trigger_references_block_struct_definition; // trigger_references_block
	extern s_tag_block_definition orders_block;
	extern s_tag_struct_definition orders_block_struct_definition; // orders_block
	extern s_tag_block_definition secondary_set_trigger_block;
	extern s_tag_struct_definition secondary_set_trigger_block_struct_definition; // secondary_set_trigger_block
	extern s_tag_block_definition order_ending_block;
	extern s_tag_struct_definition order_ending_block_struct_definition; // order_ending_block
	extern s_tag_block_definition triggers_block;
	extern s_tag_struct_definition triggers_block_struct_definition; // triggers_block
	extern s_tag_block_definition order_completion_condition_block;
	extern s_tag_struct_definition order_completion_condition_block_struct_definition; // order_completion_condition_block


	extern c_versioned_string_list condition_type_enum_strings;
	extern s_string_list_definition condition_type_enum;
	extern c_versioned_string_list completion_condition_flags_strings;
	extern s_string_list_definition completion_condition_flags;
	extern c_versioned_string_list combination_rules_enum_strings;
	extern s_string_list_definition combination_rules_enum;
	extern c_versioned_string_list trigger_flags_strings;
	extern s_string_list_definition trigger_flags;
	extern c_versioned_string_list trigger_ref_flags_strings;
	extern s_string_list_definition trigger_ref_flags;
	extern c_versioned_string_list order_ending_dialogue_enum_strings;
	extern s_string_list_definition order_ending_dialogue_enum;
	extern c_versioned_string_list order_flags_strings;
	extern s_string_list_definition order_flags;
	extern c_versioned_string_list force_combat_status_enum_strings;
	extern s_string_list_definition force_combat_status_enum;

} // namespace macaque

} // namespace blofeld
