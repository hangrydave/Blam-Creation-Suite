#include "lightmapresearch-private-pch.h"

static float4 graphics_background_color = { 0.16f, 0.10f, 0.16f, 1.0f };
static float4 window_background_color = { 0.130f, 0.141f, 0.167f, 1.0f };

static c_window* window;
static c_render_context* window_render_context;

t_callback_handle render_user_interface_handle;
t_callback_handle render_graphics_handle;
t_callback_handle render_on_device_lost_handle;
t_callback_handle render_on_device_recover_handle;
c_graphics* graphics;

c_lightmap* lightmap;

BCS_RESULT window_register_callbacks()
{
	BCS_RESULT rs = BCS_S_OK;

	c_imgui_context* imgui_context;
	if (BCS_FAILED(rs = rs = window_render_context->get_imgui_context(imgui_context)))
	{
		return rs;
	}

	if (BCS_FAILED(rs = imgui_context->render_callback.add_callback(
		member_to_static_function(&c_lightmap::render_user_interface),
		lightmap,
		render_user_interface_handle)))
	{
		return rs;
	}

	if (BCS_FAILED(rs = graphics->render_callback.add_callback(
		member_to_static_function(&c_lightmap::render_graphics),
		lightmap,
		render_graphics_handle)))
	{
		return rs;
	}

	return rs;
}

BCS_RESULT window_unregister_callbacks()
{
	BCS_RESULT rs = BCS_S_OK;

	c_imgui_context* imgui_context;
	if (BCS_FAILED(rs = rs = window_render_context->get_imgui_context(imgui_context)))
	{
		return rs;
	}

	if (BCS_FAILED(rs = imgui_context->render_callback.remove_callback(render_user_interface_handle)))
	{
		return rs;
	}

	if (BCS_FAILED(rs = graphics->render_callback.remove_callback(render_graphics_handle)))
	{
		return rs;
	}

	return rs;
}

BCS_RESULT register_device_recovery_callbacks()
{
	BCS_RESULT rs = BCS_S_OK;

	BCS_FAIL_RETURN(rs = window_render_context->on_device_lost.add_callback(window_unregister_callbacks, render_on_device_lost_handle));
	BCS_FAIL_RETURN(rs = window_render_context->on_device_recover.add_callback(window_register_callbacks, render_on_device_recover_handle));

	return rs;
}

BCS_RESULT unregister_device_recovery_callbacks()
{
	BCS_RESULT rs = BCS_S_OK;

	BCS_FAIL_RETURN(rs = window_render_context->on_device_lost.remove_callback(render_on_device_lost_handle));
	BCS_FAIL_RETURN(rs = window_render_context->on_device_recover.remove_callback(render_on_device_recover_handle));

	return rs;
}

int main()
{
	BCS_FAIL_RETURN(register_process_module_by_pointer(main));
	BCS_RESULT platform_result = init_platform();
	BCS_RESULT command_line_result = init_command_line();
	BCS_RESULT console_result = init_console();
	if (BCS_SUCCEEDED(console_result)) console_result = BCS_SUCCEEDED(command_line_has_argument_internal("commandline")) ? alloc_console("Lightmap Research") : BCS_S_OK;
	BCS_RESULT rs2 = window_create("Lightmap Research", "lightmapresearch", _window_icon_mandrill, ULONG_MAX, ULONG_MAX, window_background_color, true, true, window);

	BCS_RESULT graphics_create_result = graphics_create(_graphics_architecture_d3d12_raytracing, true, graphics);
	ASSERT(BCS_SUCCEEDED(graphics_create_result));

	BCS_RESULT rs3 = render_context_window_create(*window, graphics_background_color, window_render_context, graphics);

	BCS_RESULT rs8 = window_render_context->get_graphics(graphics);

	BCS_RESULT rs4 = register_device_recovery_callbacks();

	ASSERT(BCS_SUCCEEDED(rs8));

	lightmap = new() c_lightmap(*graphics, 512);
	lightmap->init();

	BCS_RESULT rs5 = window_register_callbacks();

	BCS_RESULT render_result = window_render_context->render();

	BCS_RESULT rs6 = window_unregister_callbacks();

	lightmap->deinit();

	BCS_RESULT rs7 = unregister_device_recovery_callbacks();

cleanup:
	if (BCS_SUCCEEDED(rs3)) rs3 = render_context_destroy(window_render_context);
	if (BCS_SUCCEEDED(rs2)) rs2 = window_destroy(window);

	BCS_RESULT graphics_destroy_result = graphics_destroy(graphics);

	BCS_FAIL_RETURN(rs7);
	BCS_FAIL_RETURN(rs6);
	BCS_FAIL_RETURN(rs5);
	BCS_FAIL_RETURN(rs4);
	BCS_FAIL_RETURN(rs3);
	BCS_FAIL_RETURN(rs2);
	BCS_FAIL_RETURN(graphics_destroy_result);
	BCS_FAIL_RETURN(console_result);
	BCS_FAIL_RETURN(render_result);

	return 0;
}

#include <Windows.h>
int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	return main();
}
