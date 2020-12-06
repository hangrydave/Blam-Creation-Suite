#include "tagcodegen-private-pch.h"

using namespace blofeld;

c_high_level_tag_source_generator::c_high_level_tag_source_generator(e_engine_type engine_type, e_platform_type platform_type, e_build build) :
	engine_type(engine_type),
	platform_type(platform_type),
	build(build)
{

}

const blofeld::s_tag_group* c_high_level_tag_source_generator::get_tag_struct_tag_group(const blofeld::s_tag_struct_definition& tag_struct_definition)
{
	for (const s_tag_group** tag_group = tag_groups; *tag_group; tag_group++)
	{
		const s_tag_struct_definition& current_struct_definition = (*tag_group)->block_definition.struct_definition;

		if (&current_struct_definition == &tag_struct_definition)
		{
			return *tag_group;
		}
	}
	return nullptr;
}

const char* c_high_level_tag_source_generator::field_type_to_high_level_source_type(e_platform_type platform_type, blofeld::e_field field_type)
{
	switch (field_type)
	{
	case _field_string:								return "c_fixed_string_32";
	case _field_long_string:						return "c_fixed_string_256";
	case _field_string_id:							return "c_fixed_string_2048";
	case _field_old_string_id:						return "c_fixed_string_2048";
	case _field_char_integer:						return "char";
	case _field_short_integer:						return "short";
	case _field_long_integer:						return "long";
	case _field_int64_integer:						return "long long";
	case _field_angle:								return "angle";
	case _field_tag:								return "tag";
	case _field_char_enum:							return "char";
	case _field_enum:								return "short";
	case _field_long_enum:							return "long";
	case _field_long_flags:							return "long";
	case _field_word_flags:							return "word";
	case _field_byte_flags:							return "byte";
	case _field_point_2d:							return "s_point2d";
	case _field_rectangle_2d:						return "s_rectangle2d";
	case _field_rgb_color:							return "pixel32";
	case _field_argb_color:							return "pixel32";
	case _field_real:								return "real";
	case _field_real_fraction:						return "real_fraction";
	case _field_real_point_2d:						return "real_point2d";
	case _field_real_point_3d:						return "real_point3d";
	case _field_real_vector_2d:						return "real_vector2d";
	case _field_real_vector_3d:						return "real_vector3d";
	case _field_real_quaternion:					return "real_quaternion";
	case _field_real_euler_angles_2d:				return "real_euler_angles2d";
	case _field_real_euler_angles_3d:				return "real_euler_angles3d";
	case _field_real_plane_2d:						return "real_plane2d";
	case _field_real_plane_3d:						return "real_plane3d";
	case _field_real_rgb_color:						return "rgb_color";
	case _field_real_argb_color:					return "argb_color";
	case _field_real_hsv_color:						return "real_hsv_color";
	case _field_real_ahsv_color:					return "real_ahsv_color";
	case _field_short_bounds:						return "short_bounds";
	case _field_angle_bounds:						return "angle_bounds";
	case _field_real_bounds:						return "real_bounds";
	case _field_real_fraction_bounds:				return "real_bounds";
	case _field_tag_reference:						return "s_tag_reference";
	case _field_block:								return "s_tag_block";
	case _field_long_block_flags:					return "long";
	case _field_word_block_flags:					return "word";
	case _field_byte_block_flags:					return "byte";
	case _field_char_block_index:					return "char";
	case _field_custom_char_block_index:			return "char";
	case _field_short_block_index:					return "short";
	case _field_custom_short_block_index:			return "short";
	case _field_long_block_index:					return "long";
	case _field_custom_long_block_index:			return "long";
	case _field_data:								return "s_tag_data";
	case _field_vertex_buffer:						return "s_tag_d3d_vertex_buffer";
	case _field_pad:								return nullptr;	// dynamic
	case _field_useless_pad:						return nullptr;	// dynamic
	case _field_skip:								return nullptr;	// dynamic
	case _field_non_cache_runtime_value:			return "long";
	case _field_explanation:						return nullptr;	// empty
	case _field_custom:								return nullptr;	// empty
	case _field_struct:								return nullptr;	// dynamic
	case _field_array:								return nullptr;	// dynamic
	case _field_pageable:							return "s_tag_resource";
	case _field_api_interop:						return "s_tag_interop";
	case _field_terminator:							return nullptr;	// empty
	case _field_byte_integer:						return "byte";
	case _field_word_integer:						return "word";
	case _field_dword_integer:						return "dword";
	case _field_qword_integer:						return "qword";
	case _field_pointer: // #NONSTANDARD
	{
		switch (get_platform_pointer_size(platform_type))
		{
		case 8: return "long long";
		case 4: return "long";
		default: FATAL_ERROR(L"bad pointer size");
		}
		break;
	}
	case _field_half:						return "short";
	default: FATAL_ERROR(L"Unknown field type");
	}
}

void c_high_level_tag_source_generator::generate_header()
{
	std::stringstream stream;

	const char* namespace_name = engine_type_to_folder_name<const char*>(engine_type);

	stream << "#pragma once" << std::endl;
	stream << std::endl;
	stream << std::endl;

	stream << "namespace blofeld" << std::endl;
	stream << "{" << std::endl;
	stream << "\tnamespace " << namespace_name << std::endl;
	stream << "\t{" << std::endl << std::endl;

	stream << "\t\tc_high_level_tag* create_high_level_tag(const blofeld::s_tag_group& tag_group, const char* tag_filepath);" << std::endl << std::endl;
	stream << "\t\tc_high_level_type* create_high_level_type(const blofeld::s_tag_struct_definition& struct_definition);" << std::endl << std::endl;

	std::map<std::string, int> field_name_unique_counter;
	for (const s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions)
	{
		const s_tag_group* tag_group = get_tag_struct_tag_group(*tag_struct_definition);

		stream << "\t\t" << "class c_" << tag_struct_definition->name << " : " << std::endl;
		if (tag_group != nullptr)
		{
			stream << "\t\t\t" << "public c_high_level_tag" << std::endl;
		}
		else
		{
			stream << "\t\t\t" << "public c_high_level_type" << std::endl;
		}
		stream << "\t\t" << "{" << std::endl;
		stream << "\t\t\t" << "public:" << std::endl;
		if (tag_group != nullptr)
		{
			stream << "\t\t\t\t" << "c_" << tag_struct_definition->name << "(const char* tag_filepath);" << std::endl;
			stream << "\t\t\t\t" << "c_" << tag_struct_definition->name << "();" << std::endl;
		}
		else
		{
			stream << "\t\t\t\t" << "c_" << tag_struct_definition->name << "();" << std::endl;
		}
		stream << std::endl;

		stream << "\t\t\t\t" << "virtual void* get_field_pointer(const blofeld::s_tag_field& field) final;" << std::endl;
		stream << std::endl;

		for (const s_tag_field* current_field = tag_struct_definition->fields; current_field->field_type != _field_terminator; current_field++)
		{
			uint32_t field_skip_count;
			if (skip_tag_field_version(*current_field, engine_type, platform_type, build, field_skip_count))
			{
				current_field += field_skip_count;
				continue;
			}

			c_blamlib_string_parser field_formatter = c_blamlib_string_parser(current_field->name, current_field->field_type == blofeld::_field_block, &field_name_unique_counter);

			if (current_field->field_type > _field_type_non_standard)
			{
				continue;
			}

			switch (current_field->field_type)
			{
			case _field_pad:
			case _field_skip:
			case _field_useless_pad:
			case _field_custom:
			case _field_terminator:
			case _field_explanation:
				continue;
			}

			switch (current_field->field_type)
			{
			case _field_array:
			{
				const char* field_source_type = current_field->array_definition->struct_definition.name;
				stream << "\t\t\t\t" << "c_" << field_source_type << " (" << field_formatter.code_name.c_str() << ")[" << current_field->array_definition->count(engine_type) << "];";
				break;
			}
			case _field_struct:
			{
				const char* field_source_type = current_field->struct_definition->name;
				stream << "\t\t\t\t" << "c_" << field_source_type << " " << field_formatter.code_name.c_str() << ";";
				break;
			}
			case _field_block:
			{
				const char* field_source_type = current_field->block_definition->struct_definition.name;
				stream << "\t\t\t\t" << "std::vector<c_" << field_source_type << "*> " << field_formatter.code_name.c_str() << ";";
				break;
			}
			case _field_data:
			{
				stream << "\t\t\t\t" << "std::vector<char> " << field_formatter.code_name.c_str() << ";";
				break;
			}
			case _field_tag_reference:
			{
				stream << "\t\t\t\t" << "c_high_level_tag* " << field_formatter.code_name.c_str() << ";";
				break;
			}
			default:
			{
				const char* field_source_type = field_type_to_high_level_source_type(platform_type, current_field->field_type);
				ASSERT(field_source_type != nullptr);
				stream << "\t\t\t\t" << field_source_type << " " << field_formatter.code_name.c_str() << ";";
			}
			}
			stream << std::endl;

		}
		field_name_unique_counter.clear();

		stream << "\t\t" << "};" << std::endl;

		stream << std::endl;
	}

	stream << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	stream << std::endl << "} // end namespace blofeld" << std::endl;

	std::string source_code = stream.str();
	std::string output_filepath = c_command_line::get_command_line_arg("-output") + "HighLevel/high_level_" + namespace_name + "/" + namespace_name + "_high_level.h";
	bool write_output = true;
	size_t existing_file_size;
	const char* existing_file_data;
	if (filesystem_read_file_to_memory(output_filepath.c_str(), &existing_file_data, &existing_file_size))
	{
		if (source_code.size() == existing_file_size && strncmp(existing_file_data, source_code.c_str(), existing_file_size) == 0)
		{
			write_output = false;
		}
		delete[] existing_file_data;
	}

	if (write_output)
	{
		bool filesystem_write_file_from_memory_result = filesystem_write_file_from_memory(output_filepath.c_str(), source_code.data(), source_code.size());
		ASSERT(filesystem_write_file_from_memory_result);
	}
}

void c_high_level_tag_source_generator::generate_tag_constructor_params(std::stringstream& stream, const s_tag_struct_definition& tag_struct_definition)
{
	std::map<std::string, int> field_name_unique_counter;
	for (const s_tag_field* current_field = tag_struct_definition.fields; current_field->field_type != _field_terminator; current_field++)
	{
		uint32_t field_skip_count;
		if (skip_tag_field_version(*current_field, engine_type, platform_type, build, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		c_blamlib_string_parser field_formatter = c_blamlib_string_parser(current_field->name, current_field->field_type == blofeld::_field_block, &field_name_unique_counter);

		if (current_field->field_type > _field_type_non_standard)
		{
			continue;
		}

		switch (current_field->field_type)
		{
		case _field_pad:
		case _field_skip:
		case _field_useless_pad:
		case _field_custom:
		case _field_terminator:
		case _field_explanation:
			continue;
		}


		switch (current_field->field_type)
		{
		case _field_array:
		{
			const s_tag_group* tag_group = get_tag_struct_tag_group(current_field->array_definition->struct_definition);

			const char* field_source_type = current_field->array_definition->struct_definition.name;
			if (tag_group)
			{
				stream << "\t\t\t\t, " << field_formatter.code_name.c_str() << "()" << std::endl;
			}
			else
			{
				stream << "\t\t\t\t, " << field_formatter.code_name.c_str() << "()" << std::endl;
			}
			
			break;
		}
		case _field_struct:
		{
			const s_tag_group* tag_group = get_tag_struct_tag_group(*current_field->struct_definition);

			const char* field_source_type = current_field->struct_definition->name;
			if (tag_group)
			{
				stream << "\t\t\t\t, " << field_formatter.code_name.c_str() << "()" << std::endl;
			}
			else
			{
				stream << "\t\t\t\t, " << field_formatter.code_name.c_str() << "()" << std::endl;
			}

			break;
		}
		default:
		{
			stream << "\t\t\t\t, " << field_formatter.code_name.c_str() << "()" << std::endl;
			break;
		}
		}
	}
}

void c_high_level_tag_source_generator::generate_source()
{
	std::stringstream stream;

	const char* source_namespace_name = engine_type_to_source_name<const char*>(engine_type);
	const char* namespace_name = engine_type_to_folder_name<const char*>(engine_type);

	stream << "#include <highlevel-" << source_namespace_name << "-private-pch.h>" << std::endl << std::endl;
	stream << std::endl;

	stream << "#pragma warning(disable : 4065)" << std::endl;
	stream << "#pragma warning(error : 4172)" << std::endl;
	stream << std::endl;

	stream << "namespace blofeld" << std::endl;
	stream << "{" << std::endl;
	stream << "\tnamespace " << namespace_name << std::endl;
	stream << "\t{" << std::endl << std::endl;

	stream << "\t\t" << "c_high_level_tag* create_high_level_tag(const blofeld::s_tag_group& tag_group, const char* tag_filepath)" << std::endl;
	stream << "\t\t" << "{" << std::endl;
	for (const s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions)
	{
		const s_tag_group* tag_group = get_tag_struct_tag_group(*tag_struct_definition);
		if (tag_group == nullptr) continue;

		stream << "\t\t\t" << "if (&tag_group == &" << tag_group->symbol->symbol_name << ")";
		stream << " " << "return new c_" << tag_struct_definition->name << "(tag_filepath);" << std::endl;
	}
	stream << std::endl;
	stream << "\t\t\t" << "return nullptr;" << std::endl;
	stream << "\t\t" << "}" << std::endl;
	stream << std::endl;

	stream << "\t\t" << "c_high_level_type* create_high_level_type(const blofeld::s_tag_struct_definition& struct_definition)" << std::endl;
	stream << "\t\t" << "{" << std::endl;
	for (const s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions)
	{
		const s_tag_group* tag_group = get_tag_struct_tag_group(*tag_struct_definition);

		stream << "\t\t\t" << "if (&struct_definition == &" << tag_struct_definition->symbol->symbol_name << ")";
		if (tag_group != nullptr)
		{
			stream << " " << "return new c_" << tag_struct_definition->name << "();" << std::endl;
		}
		else
		{
			stream << " " << "return new c_" << tag_struct_definition->name << "();" << std::endl;
		}
	}
	stream << std::endl;
	stream << "\t\t\t" << "return nullptr;" << std::endl;
	stream << "\t\t" << "}" << std::endl;
	stream << std::endl;

	stream << std::endl;
	stream << "#ifndef __INTELLISENSE__" << std::endl;
	stream << std::endl;

	std::map<std::string, int> field_name_unique_counter;
	for (const s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions)
	{
		const s_tag_group* tag_group = get_tag_struct_tag_group(*tag_struct_definition);

		
		if (tag_group != nullptr)
		{
			stream << "\t\t" << "c_" << tag_struct_definition->name << "::c_" << tag_struct_definition->name;
			stream << "(const char* tag_filepath) :" << std::endl;
			stream << "\t\t\t" << "c_high_level_tag(" << tag_group->symbol->symbol_name << ", tag_filepath, sizeof(c_" << tag_struct_definition->name << "))" << std::endl;
			generate_tag_constructor_params(stream, *tag_struct_definition);
			stream << "\t\t" << "{" << std::endl;
			stream << "\t\t\t" << "high_level_tag_ctor(this);" << std::endl;
			stream << "\t\t" << "}" << std::endl;
			stream << std::endl;

			stream << "\t\t" << "c_" << tag_struct_definition->name << "::c_" << tag_struct_definition->name;
			stream << "() :" << std::endl;
			stream << "\t\t\t" << "c_high_level_tag(" << tag_group->symbol->symbol_name << ", nullptr, sizeof(c_" << tag_struct_definition->name << "))" << std::endl;
			generate_tag_constructor_params(stream, *tag_struct_definition);
			stream << "\t\t" << "{" << std::endl;
			stream << "\t\t\t" << "high_level_tag_ctor(this);" << std::endl;
			stream << "\t\t" << "}" << std::endl;
			stream << std::endl;
		}
		else
		{
			stream << "\t\t" << "c_" << tag_struct_definition->name << "::c_" << tag_struct_definition->name;
			stream << "() :" << std::endl;
			stream << "\t\t\t" << "c_high_level_type(" << tag_struct_definition->symbol->symbol_name << ", sizeof(c_" << tag_struct_definition->name << "))" << std::endl;
			generate_tag_constructor_params(stream, *tag_struct_definition);
			stream << "\t\t" << "{" << std::endl;
			stream << "\t\t\t" << "high_level_tag_ctor(this);" << std::endl;
			stream << "\t\t" << "}" << std::endl;
		}

		stream << std::endl;

		stream << "\t\t" << "void* c_" << tag_struct_definition->name << "::get_field_pointer(const blofeld::s_tag_field& field)" << std::endl;
		stream << "\t\t{" << std::endl;
		stream << "\t\t\tuintptr_t const _field_address = reinterpret_cast<uintptr_t>(&field);" << std::endl;
		stream << "\t\t\tuintptr_t const _fields_address = reinterpret_cast<uintptr_t>(struct_definition.fields);" << std::endl;
		stream << "\t\t\tuintptr_t const _bytes_offset = _field_address - _fields_address;" << std::endl;
		stream << "\t\t\tuintptr_t const _index = _bytes_offset / sizeof(blofeld::s_tag_field);" << std::endl;
		stream << std::endl;
		stream << "\t\t\tswitch (_index)" << std::endl;
		stream << "\t\t\t{" << std::endl;


		field_name_unique_counter.clear();
		uint32_t field_index = 0;
		for (const s_tag_field* current_field = tag_struct_definition->fields; current_field->field_type != _field_terminator; current_field++, field_index++)
		{
			uint32_t field_skip_count;
			if (skip_tag_field_version(*current_field, engine_type, platform_type, build, field_skip_count))
			{
				current_field += field_skip_count;
				field_index += field_skip_count;
				continue;
			}

			c_blamlib_string_parser field_formatter = c_blamlib_string_parser(current_field->name, current_field->field_type == blofeld::_field_block, &field_name_unique_counter);

			if (current_field->field_type > _field_type_non_standard)
			{
				continue;
			}

			switch (current_field->field_type)
			{
			case _field_pad:
			case _field_skip:
			case _field_useless_pad:
			case _field_custom:
			case _field_terminator:
			case _field_explanation:
				continue;
			}

			stream << "\t\t\t\tcase " << field_index << ": return &" << field_formatter.code_name.c_str() << ";" << std::endl;
		}
		stream << "\t\t\t\tdefault: return nullptr;" << std::endl;

		stream << "\t\t\t}" << std::endl;
		stream << std::endl;

		stream << "\t\t}" << std::endl;
		stream << std::endl;


	}

	stream << std::endl;
	stream << "#endif" << std::endl;
	stream << std::endl;

	stream << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	stream << std::endl << "} // end namespace blofeld" << std::endl;

	std::string source_code = stream.str();
	std::string output_filepath = c_command_line::get_command_line_arg("-output") + "HighLevel/high_level_" + namespace_name + "/" + namespace_name + "_high_level.cpp";
	bool write_output = true;
	size_t existing_file_size;
	const char* existing_file_data;
	if (filesystem_read_file_to_memory(output_filepath.c_str(), &existing_file_data, &existing_file_size))
	{
		if (source_code.size() == existing_file_size && strncmp(existing_file_data, source_code.c_str(), existing_file_size) == 0)
		{
			write_output = false;
		}
		delete[] existing_file_data;
	}

	if (write_output)
	{
		bool filesystem_write_file_from_memory_result = filesystem_write_file_from_memory(output_filepath.c_str(), source_code.data(), source_code.size());
		ASSERT(filesystem_write_file_from_memory_result);
	}
}