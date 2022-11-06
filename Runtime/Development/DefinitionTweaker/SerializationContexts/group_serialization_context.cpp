#include "definitiontweaker-private-pch.h"

c_group_serialization_context::c_group_serialization_context(c_definition_tweaker& _definition_tweaker, c_runtime_tag_group_definition& _runtime_tag_group_definition) :
	c_serialization_context(_definition_tweaker.engine_platform_build),
	definition_tweaker(_definition_tweaker),
	serialization_contexts(),
	runtime_tag_group_definition(_runtime_tag_group_definition),
	name(runtime_tag_group_definition.name),
	group_tag(runtime_tag_group_definition.group_tag)
{

}

c_group_serialization_context::~c_group_serialization_context()
{

}

void c_group_serialization_context::read()
{
	for (unsigned int tag_cache_offset_index = 0; tag_cache_offset_index < definition_tweaker.cache_file_tags_header->tag_count; tag_cache_offset_index++)
	{
		unsigned int tag_cache_offset = definition_tweaker.tag_cache_offsets[tag_cache_offset_index];
		if (tag_cache_offset == 0)
		{
			debug_point;
			continue;
		}

		const char* tag_data_start = static_cast<char*>(definition_tweaker.binary_data[_binary_tags]) + tag_cache_offset;
		const s_cache_file_tag_instance* tag_header = reinterpret_cast<const s_cache_file_tag_instance*>(tag_data_start);

		if (tag_header->group_tags[0] != runtime_tag_group_definition.group_tag)
		{
			continue;
		}

		c_tag_serialization_context* tag_serialization_context = new() c_tag_serialization_context(*this, tag_cache_offset_index, tag_data_start);
		serialization_contexts.push_back(tag_serialization_context);
	}

	for (c_tag_serialization_context* tag_serialization_context : serialization_contexts)
	{
		tag_serialization_context->read();
	}
}

void c_group_serialization_context::traverse()
{
	for (c_tag_serialization_context* tag_serialization_context : serialization_contexts)
	{
		tag_serialization_context->traverse();
	}
}

void c_group_serialization_context::render_tree()
{
	if (!serialization_contexts.empty())
	{
		ImGui::PushID(group_tag);

		ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[max_serialization_error_type]);

		ImGuiTreeNodeFlags flags =
			ImGuiTreeNodeFlags_SpanFullWidth;
		bool tree_node_result = ImGui::TreeNodeEx("##group", flags, "%s (%zu)", name.c_str(), serialization_contexts.size());
		render_hover_tooltip();
		definition_tweaker.render_definition_context_menu(_definition_type_group_definition, &runtime_tag_group_definition);
		if (tree_node_result)
		{
			for (c_tag_serialization_context* tag_serialization_context : serialization_contexts)
			{
				tag_serialization_context->render_tree();
			}

			ImGui::TreePop();
		}

		ImGui::PopStyleColor();

		ImGui::PopID();
	}
}
