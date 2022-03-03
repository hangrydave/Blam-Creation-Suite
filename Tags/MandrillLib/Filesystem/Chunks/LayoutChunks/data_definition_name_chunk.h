#pragma once

class c_data_definition_name_chunk : public c_typed_chunk<'dtnm'>
{
public:
	s_tag_persist_string_character_index* offsets;
	unsigned long const entry_count;

	c_data_definition_name_chunk(const void* chunk_data, c_chunk& parent);
	~c_data_definition_name_chunk();

	void log_impl(c_single_tag_file_layout_reader* layout_reader) const override;

};
