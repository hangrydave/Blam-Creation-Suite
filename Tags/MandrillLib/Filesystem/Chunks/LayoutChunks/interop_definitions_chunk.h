#pragma once

struct s_tag_persist_interop_definition
{
	s_tag_persist_string_character_index string_character_index;
	uint32_t structure_entry_index;
	blofeld::s_tag_persistent_identifier persistent_identifier;
};

class c_interop_definitions_chunk : public c_typed_chunk<']==[', false>
{
public:
	s_tag_persist_interop_definition* entries;
	uint32_t entry_count;

	c_interop_definitions_chunk(c_chunk& parent);
	~c_interop_definitions_chunk();

	BCS_RESULT read_chunk(void* userdata, const void* data, bool use_read_only, bool parse_children) override final;

	virtual void log_impl(c_tag_file_string_debugger* string_debugger) const override;
	virtual BCS_RESULT set_data(const void* data, uint32_t data_size) override;
	void read_entries();
};
