#include "halo3tagfiletest-private-pch.h"


#ifdef _DEBUG
static constexpr const char window_title[] = "Halo 3 Tag File Test Debug";
#else
static constexpr const char window_title[] = "Halo 3 Tag File Test";
#endif

static c_window* window;
static c_render_context* window_render_context;
static c_mandrill_user_interface* mandrill_user_interface;

static float4 graphics_background_color = { 0.16f, 0.10f, 0.16f, 1.0f };
static float4 window_background_color = { 0.130f, 0.141f, 0.167f, 1.0f };


#include <HighLevel/high_level_halo3/highlevel-halo3-public-pch.h>

static long _depth = -1;

struct s_single_tag_file_header;
class c_chunk;
class c_tag_group_layout_chunk;
class c_binary_data_chunk;

class c_tag_file_high_level_transplant
{
public:
	void* tag_file_data;
	unsigned long long tag_file_data_size;

	s_single_tag_file_header* header_data;
	c_single_tag_file_layout_reader* layout_reader;
	c_single_tag_file_reader* reader;

	s_engine_platform_build engine_platform_build;
	c_chunk* root_chunk;
	c_tag_group_layout_chunk* tag_group_layout_chunk;
	c_binary_data_chunk* binary_data_chunk;

	c_tag_file_high_level_transplant(const char* filepath)
	{
		BCS_FAIL_THROW(filesystem_read_file_to_memory(filepath, tag_file_data, tag_file_data_size));
		ASSERT(tag_file_data_size > (sizeof(s_single_tag_file_header) + sizeof(tag)));
		header_data = static_cast<s_single_tag_file_header*>(tag_file_data);
		ASSERT(header_data->blam == 'BLAM');

		static constexpr tag k_tag_file_root_data_stream_tag = 'tag!';
		tag root_node_tag = *reinterpret_cast<tag*>(header_data + 1);
		ASSERT(root_node_tag == k_tag_file_root_data_stream_tag);

		engine_platform_build = { _engine_type_halo3 };

		c_stopwatch s;
		s.start();

		root_chunk = new c_tag_header_chunk(header_data + 1);
		tag_group_layout_chunk = root_chunk->find_first_chunk<c_tag_group_layout_chunk>();
		binary_data_chunk = root_chunk->find_first_chunk<c_binary_data_chunk>();

		ASSERT(tag_group_layout_chunk != nullptr);
		ASSERT(binary_data_chunk != nullptr);

		layout_reader = new c_single_tag_file_layout_reader(*tag_group_layout_chunk);

		reader = new c_single_tag_file_reader(
			*header_data,
			engine_platform_build,
			*layout_reader,
			*binary_data_chunk);

		s.stop();
		float ms = s.get_miliseconds();
		console_write_line("Processed chunks in %.2f ms", ms);

		//tag_group_layout_chunk->log(layout_reader->string_data_chunk);
		//binary_data_chunk->log(layout_reader->string_data_chunk);

		h_tag* high_level_tag;
		reader->parse_high_level_object(high_level_tag);
		debug_point;
	}

	~c_tag_file_high_level_transplant()
	{

	}
};

int main()
{
	const wchar_t* launch_filepath_command_line_argument = nullptr; // #TODO: implement this with the command line API

	BCS_FAIL_RETURN(register_process_module_by_pointer(main));
	BCS_RESULT rs0 = init_command_line();
	BCS_RESULT rs1 = init_console();
	if (BCS_SUCCEEDED(rs1)) rs1 = BCS_SUCCEEDED(command_line_has_argument("console")) ? alloc_console("Halo 3 Tag File Test Console") : BCS_S_OK;

	const char* filepath;
	if (BCS_SUCCEEDED(command_line_get_argument("tagfilepath", filepath)))
	{
		c_tag_file_high_level_transplant high_level_transplant = c_tag_file_high_level_transplant(filepath);
		debug_point;
	}

	if (BCS_SUCCEEDED(rs1)) rs1 = deinit_console();
	if (BCS_SUCCEEDED(rs0)) rs0 = deinit_command_line();

	BCS_FAIL_RETURN(rs1);
	BCS_FAIL_RETURN(rs0);

	return 0;
}
