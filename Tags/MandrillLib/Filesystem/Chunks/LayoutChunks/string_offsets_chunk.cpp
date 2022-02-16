#include "mandrilllib-private-pch.h"

c_string_offsets_chunk::c_string_offsets_chunk(void* chunk_data, c_chunk& parent) :
	c_typed_chunk(chunk_data, &parent),
	offsets(reinterpret_cast<s_tag_persist_string_character_index*>(chunk_data_begin)),
	entry_count(chunk_size / sizeof(*offsets))
{
	debug_point;
}

void c_string_offsets_chunk::log_impl(c_single_tag_file_layout_reader* layout_reader) const
{
	log_signature();
	console_write_line_verbose("count:0x%08X", entry_count);
	for (unsigned long index = 0; index < entry_count; index++)
	{
		s_tag_persist_string_character_index string_character_index = offsets[index];
		if (layout_reader)
		{
			const char* string = layout_reader->get_string_by_string_character_index(string_character_index);
			log_pad(); console_write_line_verbose("\t0x%08X\t0x%08X\t%s", index, string_character_index.offset, string);
		}
		else
		{
			log_pad(); console_write_line_verbose("\t0x%08X\t0x%08X", index, string_character_index.offset);
		}
	}
}
