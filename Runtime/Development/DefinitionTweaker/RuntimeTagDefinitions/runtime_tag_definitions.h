#pragma once

class c_runtime_tag_group_definition;
class c_runtime_tag_block_definition;
class c_runtime_tag_struct_definition;
class c_runtime_tag_array_definition;
class c_runtime_tag_string_list_definition;
class c_runtime_tag_reference_definition;
class c_runtime_tag_resource_definition;
class c_runtime_tag_interop_definition;
class c_runtime_tag_data_definition;
class c_runtime_block_index_custom_search_definition;

class c_runtime_tag_definitions
{
public:
	c_runtime_tag_definitions(s_engine_platform_build engine_platform_build);

	s_engine_platform_build engine_platform_build;
	int next_runtime_unique_id;

	std::vector<c_runtime_tag_group_definition*> group_definitions;
	std::vector<c_runtime_tag_block_definition*> block_definitions;
	std::vector<c_runtime_tag_struct_definition*> struct_definitions;
	std::vector<c_runtime_tag_array_definition*> array_definitions;
	std::vector<c_runtime_tag_string_list_definition*> string_list_definitions;
	std::vector<c_runtime_tag_reference_definition*> reference_definitions;
	std::vector<c_runtime_tag_resource_definition*> resource_definitions;
	std::vector<c_runtime_tag_interop_definition*> interop_definitions;
	std::vector<c_runtime_tag_data_definition*> data_definitions;
	std::vector<c_runtime_block_index_custom_search_definition*> block_index_custom_search_definitions;

	c_runtime_tag_group_definition* get_tag_group_by_group_tag(tag group_tag);

	c_runtime_tag_group_definition& create_tag_group_definition();
	c_runtime_tag_block_definition& create_tag_block_definition();
	c_runtime_tag_struct_definition& create_tag_struct_definition();
	c_runtime_tag_array_definition& create_tag_array_definition();
	c_runtime_tag_string_list_definition& create_string_list_definition();
	c_runtime_tag_reference_definition& create_tag_reference_definition();
	c_runtime_tag_resource_definition& create_tag_resource_definition();
	c_runtime_tag_interop_definition& create_tag_interop_definition();
	c_runtime_tag_data_definition& create_tag_data_definition();
	c_runtime_block_index_custom_search_definition& create_block_index_custom_search_definition();

	c_runtime_tag_group_definition& enqueue_tag_group_definition(const blofeld::s_tag_group& tag_group_definition);
	c_runtime_tag_block_definition& enqueue_tag_block_definition(const blofeld::s_tag_block_definition& tag_block_definition);
	c_runtime_tag_struct_definition& enqueue_tag_struct_definition(const blofeld::s_tag_struct_definition& tag_struct_definition);
	c_runtime_tag_array_definition& enqueue_tag_array_definition(const blofeld::s_tag_array_definition& tag_array_definition);
	c_runtime_tag_string_list_definition& enqueue_string_list_definition(const blofeld::s_string_list_definition& string_list_definition);
	c_runtime_tag_reference_definition& enqueue_tag_reference_definition(const blofeld::s_tag_reference_definition& tag_reference_definition);
	c_runtime_tag_resource_definition& enqueue_tag_resource_definition(const blofeld::s_tag_resource_definition& tag_resource_definition);
	c_runtime_tag_interop_definition& enqueue_tag_interop_definition(const blofeld::s_tag_interop_definition& tag_interop_definition);
	c_runtime_tag_data_definition& enqueue_tag_data_definition(const blofeld::s_tag_data_definition& tag_data_definition);
	c_runtime_block_index_custom_search_definition& enqueue_block_index_custom_search_definition(const blofeld::s_block_index_custom_search_definition& block_index_custom_search_definition);
};
