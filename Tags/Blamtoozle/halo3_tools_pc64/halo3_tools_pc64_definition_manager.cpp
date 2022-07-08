#include <blamtoozle-private-pch.h>

#define coerce_underlying_map(map_name) reinterpret_cast<decltype(map_name)&>(c_blamtoozle_tag_definition_manager::map_name)

//#define tag_group_definitions 
//#define tag_struct_definitions reinterpret_cast<std::map<ptr64, c_halo3_tools_pc64_tag_struct_definition*>&>(tag_struct_definitions)

c_halo3_tools_pc64_tag_definition_manager::c_halo3_tools_pc64_tag_definition_manager(const wchar_t* minidump_file_path) :
	c_blamtoozle_minidump_tag_definition_reader(minidump_file_path),
	tag_group_definitions(coerce_underlying_map(tag_group_definitions)),
	tag_struct_definitions(coerce_underlying_map(tag_struct_definitions)),
	tag_block_definitions(coerce_underlying_map(tag_block_definitions)),
	tag_reference_definitions(coerce_underlying_map(tag_reference_definitions)),
	tag_array_definitions(coerce_underlying_map(tag_array_definitions)),
	string_list_definitions(coerce_underlying_map(string_list_definitions)),
	tag_resource_definitions(coerce_underlying_map(tag_resource_definitions)),
	tag_data_definitions(coerce_underlying_map(tag_data_definitions)),
	tag_api_interop_definitions(coerce_underlying_map(tag_api_interop_definitions)),
	block_index_custom_search_definitions(coerce_underlying_map(block_index_custom_search_definitions)),
	tag_group_definitions_lookup(coerce_underlying_map(tag_group_definitions_lookup)),
	tag_struct_definitions_lookup(coerce_underlying_map(tag_struct_definitions_lookup)),
	tag_block_definitions_lookup(coerce_underlying_map(tag_block_definitions_lookup)),
	tag_reference_definitions_lookup(coerce_underlying_map(tag_reference_definitions_lookup)),
	tag_array_definitions_lookup(coerce_underlying_map(tag_array_definitions_lookup)),
	string_list_definitions_lookup(coerce_underlying_map(string_list_definitions_lookup)),
	tag_resource_definitions_lookup(coerce_underlying_map(tag_resource_definitions_lookup)),
	tag_data_definitions_lookup(coerce_underlying_map(tag_data_definitions_lookup)),
	tag_api_interop_definitions_lookup(coerce_underlying_map(tag_api_interop_definitions_lookup)),
	block_index_custom_search_definitions_lookup(coerce_underlying_map(block_index_custom_search_definitions_lookup))
{
	set_is_big_endian(false);
}

c_halo3_tools_pc64_tag_definition_manager::~c_halo3_tools_pc64_tag_definition_manager()
{
}

void c_halo3_tools_pc64_tag_definition_manager::traverse()
{
	ptr64 group_table_address = 0x0000000140EC2C90;
	unsigned long num_tag_layouts = 182;

	const ptr64* groups = va_to_pointer2<ptr64>(group_table_address);
	for (unsigned long tag_group_index = 0; tag_group_index < num_tag_layouts; tag_group_index++)
	{
		ptr64 group_pointer = groups[tag_group_index];
		byteswap_inplace(group_pointer);

		c_halo3_tools_pc64_tag_group_definition& group_definition = eval_group(group_pointer);

		debug_point;
	}

	for (c_halo3_tools_pc64_tag_group_definition* tag_group_definition : tag_group_definitions)
	{
		tag_group_definition->traverse();
	}

	debug_point;
}

c_halo3_tools_pc64_tag_group_definition& c_halo3_tools_pc64_tag_definition_manager::eval_group(ptr64 definition_address)
{
	return eval_definition<c_halo3_tools_pc64_tag_definition_manager>(definition_address, tag_group_definitions, tag_group_definitions_lookup);
}

c_halo3_tools_pc64_tag_block_definition& c_halo3_tools_pc64_tag_definition_manager::eval_block(ptr64 definition_address)
{
	return eval_definition<c_halo3_tools_pc64_tag_definition_manager>(definition_address, tag_block_definitions, tag_block_definitions_lookup);
}

c_halo3_tools_pc64_tag_reference_definition& c_halo3_tools_pc64_tag_definition_manager::eval_tag_reference(ptr64 definition_address)
{
	return eval_definition<c_halo3_tools_pc64_tag_definition_manager>(definition_address, tag_reference_definitions, tag_reference_definitions_lookup);
}

c_halo3_tools_pc64_tag_struct_definition& c_halo3_tools_pc64_tag_definition_manager::eval_struct(ptr64 definition_address)
{
	ASSERT(definition_address != 0);

	auto tag_type_definition_iterator = tag_struct_definitions_lookup.find(definition_address);

	if (tag_type_definition_iterator != tag_struct_definitions_lookup.end())
	{
		return *tag_type_definition_iterator->second;
	}

	s_halo3_tools_pc64_tag_struct_definition struct_definition = read_structure<s_halo3_tools_pc64_tag_struct_definition>(definition_address);
	c_halo3_tools_pc64_tag_struct_definition* existing_definition = dynamic_cast<c_halo3_tools_pc64_tag_struct_definition*>(get_tag_struct_definition_by_persistent_id(struct_definition.type.persistent_identifier));

	c_halo3_tools_pc64_tag_struct_definition* new_tag_type_definition = reinterpret_cast<c_halo3_tools_pc64_tag_struct_definition*>(tracked_malloc(sizeof(c_halo3_tools_pc64_tag_struct_definition)));
	if (existing_definition == nullptr)
	{
		tag_struct_definitions_lookup[definition_address] = new_tag_type_definition;
		tag_struct_definitions.push_back(new_tag_type_definition);
	}
	else
	{
		tag_struct_definitions_lookup[definition_address] = existing_definition; // make sure that anything referencing the new structure points to the existing
	}
	
	new_tag_type_definition = new(new_tag_type_definition) c_halo3_tools_pc64_tag_struct_definition(*this, definition_address);

	if (existing_definition != nullptr)
	{
		existing_definition->handle_conflict(*new_tag_type_definition);
		delete new_tag_type_definition; // no longer needed
		new_tag_type_definition = existing_definition;
	}

	return *new_tag_type_definition;
}

c_halo3_tools_pc64_tag_array_definition& c_halo3_tools_pc64_tag_definition_manager::eval_array(ptr64 definition_address)
{
	return eval_definition<c_halo3_tools_pc64_tag_definition_manager>(definition_address, tag_array_definitions, tag_array_definitions_lookup);
}

c_halo3_tools_pc64_string_list_definition& c_halo3_tools_pc64_tag_definition_manager::eval_string_list(ptr64 definition_address)
{
	return eval_definition<c_halo3_tools_pc64_tag_definition_manager>(definition_address, string_list_definitions, string_list_definitions_lookup);
}

c_halo3_tools_pc64_tag_resource_definition& c_halo3_tools_pc64_tag_definition_manager::eval_pageable_resource(ptr64 definition_address)
{
	return eval_definition<c_halo3_tools_pc64_tag_definition_manager>(definition_address, tag_resource_definitions, tag_resource_definitions_lookup);
}

c_halo3_tools_pc64_tag_data_definition& c_halo3_tools_pc64_tag_definition_manager::eval_data(ptr64 definition_address)
{
	return eval_definition<c_halo3_tools_pc64_tag_definition_manager>(definition_address, tag_data_definitions, tag_data_definitions_lookup);
}

c_halo3_tools_pc64_tag_api_interop_definition& c_halo3_tools_pc64_tag_definition_manager::eval_api_interop(ptr64 definition_address)
{
	return eval_definition<c_halo3_tools_pc64_tag_definition_manager>(definition_address, tag_api_interop_definitions, tag_api_interop_definitions_lookup);
}

c_halo3_tools_pc64_tag_block_index_custom_search_definition& c_halo3_tools_pc64_tag_definition_manager::eval_block_index_custom_search(ptr64 definition_address)
{
	return eval_definition<c_halo3_tools_pc64_tag_definition_manager>(definition_address, block_index_custom_search_definitions, block_index_custom_search_definitions_lookup);
}
