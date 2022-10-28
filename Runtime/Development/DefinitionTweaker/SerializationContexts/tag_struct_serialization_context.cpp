#include "definitiontweaker-private-pch.h"

bool c_tag_struct_serialization_context::_execute_tag_field_versioning(
	blofeld::s_tag_field_versioning const& versioning,
	s_engine_platform_build engine_platform_build,
	uint32_t struct_version,
	uint32_t& skip_count)
{
	bool skip_versioning_field = false;
	skip_count = versioning.version_field_skip_count;

	constexpr tag group_tag = blofeld::ANY_TAG;

	switch (versioning.mode)
	{
	case blofeld::_version_mode_invalid:
		FATAL_ERROR("Invalid version mode");
		break;
	case blofeld::_version_mode_custom:
		ASSERT(versioning.custom_version_callback);
		skip_count = versioning.custom_version_callback(engine_platform_build);
		skip_versioning_field = false;
		break;
	case blofeld::_version_mode_platform_include:
		if (versioning.engine_platform_build.platform_type != _platform_type_not_set && engine_platform_build.platform_type != _platform_type_not_set)
		{
			skip_versioning_field = (versioning.engine_platform_build.platform_type & engine_platform_build.platform_type) != 0;
		}
		break;
	case blofeld::_version_mode_platform_exclude:
		if (versioning.engine_platform_build.platform_type != _platform_type_not_set && engine_platform_build.platform_type != _platform_type_not_set)
		{
			skip_versioning_field = (versioning.engine_platform_build.platform_type & engine_platform_build.platform_type) != 0;
		}
		break;
	case blofeld::_version_mode_equal:
		skip_versioning_field = engine_platform_build == versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_not_equal:
		skip_versioning_field = engine_platform_build != versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_less:
		skip_versioning_field = engine_platform_build < versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_greater:
		skip_versioning_field = engine_platform_build > versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_less_or_equal:
		skip_versioning_field = engine_platform_build <= versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_greater_or_equal:
		skip_versioning_field = engine_platform_build >= versioning.engine_platform_build;
		break;
	case blofeld::_version_mode_tag_group_equal:
		skip_versioning_field = group_tag == blofeld::ANY_TAG || versioning.group->group_tag == group_tag;
		break;
	case blofeld::_version_mode_tag_group_not_equal:
		skip_versioning_field = group_tag == blofeld::ANY_TAG || versioning.group->group_tag != group_tag;
		break;
	case blofeld::_struct_version_mode_equal:
		skip_versioning_field = struct_version == tag_field_version_all || struct_version == versioning.struct_version;
		break;
	case blofeld::_struct_version_mode_greater_or_equal:
		skip_versioning_field = struct_version == tag_field_version_all || struct_version >= versioning.struct_version;
		break;
	}

	if (skip_versioning_field)
	{
		skip_count = 0;
	}

	return true;
}

bool c_tag_struct_serialization_context::_execute_tag_field_versioning(
	c_runtime_tag_field_definition& tag_field,
	s_engine_platform_build engine_platform_build,
	uint32_t struct_version,
	uint32_t& skip_count)
{
	if (tag_field.field_type != blofeld::_field_version)
	{
		skip_count = 0;
		return false;
	}

	return _execute_tag_field_versioning(tag_field.versioning, engine_platform_build, struct_version, skip_count);
}

unsigned int c_tag_struct_serialization_context::_tag_field_iterator_versioning(c_runtime_tag_field_definition& field, size_t& tag_field_index, s_engine_platform_build engine_platform_build, unsigned int struct_version)
{
	uint32_t _field_skip_count;
	if (_execute_tag_field_versioning(field, engine_platform_build, struct_version, _field_skip_count))
	{
		tag_field_index += _field_skip_count;
		return true;
	}
	return false;
}

c_tag_struct_serialization_context::c_tag_struct_serialization_context(
	c_tag_serialization_context& _tag_serialization_context,
	const char* _struct_data,
	c_runtime_tag_struct_definition& _struct_definition,
	unsigned int _expected_struct_size) :
	c_serialization_context(_tag_serialization_context),
	tag_serialization_context(_tag_serialization_context),
	struct_data(_struct_data),
	expected_struct_size(_expected_struct_size),
	struct_size(),
	struct_definition(_struct_definition),
	field_serialization_contexts()
{
	if (struct_definition.fields.empty())
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_tag_serialization_state_error, 
			"struct '%' has no fields", 
			struct_definition.name.c_str());
	}
	else
	{
		struct_size = calculate_struct_size(*this, struct_definition);
	}
	debug_point;
}

c_tag_struct_serialization_context::~c_tag_struct_serialization_context()
{
	for (c_tag_field_serialization_context* field_serialization_context : field_serialization_contexts)
	{
		delete field_serialization_context;
	}
}

void c_tag_struct_serialization_context::read()
{
	if (!serialization_errors.empty())
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_tag_serialization_state_warning,
			"skipping read due to issues");
		return;
	}

	const char* read_position = struct_data;
	for (size_t field_index = 0; field_index < struct_definition.fields.size(); field_index++)
	{
		t_blamtoozle_tag_field& blamtoozle_field = *struct_definition.fields[field_index];
		if (c_runtime_tag_field_definition* runtime_field = dynamic_cast<c_runtime_tag_field_definition*>(&blamtoozle_field))
		{
			c_runtime_tag_field_definition* max_version_field = dynamic_cast<c_runtime_tag_field_definition*>(struct_definition.fields.front());
			if (_tag_field_iterator_versioning(*runtime_field, field_index, engine_platform_build, max_version_field->versioning.struct_version))
			{
				continue;
			}

			c_tag_field_serialization_context* tag_field_serialization_context = new() c_tag_field_serialization_context(*this, read_position, *runtime_field);
			field_serialization_contexts.push_back(tag_field_serialization_context);

			read_position += tag_field_serialization_context->field_size;
		}
	}

	for (c_tag_field_serialization_context* field_serialization_context : field_serialization_contexts)
	{
		field_serialization_context->read();
	}

	for (c_tag_field_serialization_context* field_serialization_context : field_serialization_contexts)
	{
		field_serialization_context->traverse();
	}

	debug_point;
}

void c_tag_struct_serialization_context::traverse()
{
	if (!serialization_errors.empty())
	{
		enqueue_serialization_error<c_generic_serialization_error>(
			_tag_serialization_state_warning,
			"skipping traverse due to issues");
		return;
	}

	debug_point;
}

unsigned int c_tag_struct_serialization_context::calculate_struct_size(c_serialization_context& serialization_context, c_runtime_tag_struct_definition& struct_definition)
{
	unsigned int struct_size = 0;

	for (size_t field_index = 0; field_index < struct_definition.fields.size(); field_index++)
	{
		t_blamtoozle_tag_field& blamtoozle_field = *struct_definition.fields[field_index];
		if (c_runtime_tag_field_definition* runtime_field = dynamic_cast<c_runtime_tag_field_definition*>(&blamtoozle_field))
		{
			c_runtime_tag_field_definition* max_version_field = dynamic_cast<c_runtime_tag_field_definition*>(struct_definition.fields.front());
			if (runtime_field->field_type == blofeld::_field_version && (max_version_field == nullptr || max_version_field->field_type != blofeld::_field_version))
			{
				serialization_context.enqueue_serialization_error<c_generic_serialization_error>(
					_tag_serialization_state_error,
					"versioned struct '%' doesn't start with a versioned runtime_field. unable to determine max version",
					runtime_field->name.c_str());
				return 0;
			}

			if (_tag_field_iterator_versioning(*runtime_field, field_index, serialization_context.engine_platform_build, max_version_field->versioning.struct_version))
			{
				continue;
			}

			unsigned int field_size = c_tag_field_serialization_context::calculate_field_size(serialization_context, *runtime_field);
			struct_size += field_size;
		}
	}

	return struct_size;
}

void c_tag_struct_serialization_context::render_tree()
{
	ImGui::PushID(this);
	ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[max_serialization_error_type]);

	static ImGuiTreeNodeFlags flags =
		ImGuiTreeNodeFlags_SpanFullWidth;
	if (field_serialization_contexts.empty())
	{
		flags = flags | ImGuiTreeNodeFlags_Leaf;
	}
	const char* struct_name = struct_definition.name.c_str();
	bool tree_node_result = ImGui::TreeNodeEx(this, flags, "%s", struct_name);
	render_hover_tooltip();
	if (ImGui::IsItemClicked() && ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left))
	{
		debug_point;
	}
	if (tree_node_result)
	{
		e_serialization_error_type field_max_serialization_error_type = _tag_serialization_state_good;
		for (c_tag_field_serialization_context* field_serialization_context : field_serialization_contexts)
		{
			field_max_serialization_error_type = __max(field_max_serialization_error_type, field_serialization_context->max_serialization_error_type);
		}
		ImGui::PushStyleColor(ImGuiCol_Text, serialization_error_colors[field_max_serialization_error_type]);
		if (!field_serialization_contexts.empty())
		{
			if (ImGui::TreeNodeEx(this, flags, "fields"))
			{
				for (c_tag_field_serialization_context* field_serialization_context : field_serialization_contexts)
				{
					field_serialization_context->render_tree();
				}
				ImGui::TreePop();
			}
		}
		ImGui::PopStyleColor();

		//if (c_tag_struct_serialization_context* struct_serialization_context = root_struct_serialization_context)
		//{
		//	struct_serialization_context->render_tree();
		//}
		ImGui::TreePop();
	}

	ImGui::PopStyleColor();
	ImGui::PopID();
}
