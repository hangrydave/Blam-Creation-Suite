#pragma once

BCS_DEBUG_API BCS_RESULT init_console();
BCS_DEBUG_API BCS_RESULT alloc_console(const char* console_window_title = nullptr);
BCS_DEBUG_API BCS_RESULT deinit_console();
BCS_DEBUG_API BCS_RESULT console_write(const char* format, ...);
BCS_DEBUG_API BCS_RESULT console_write_line(const char* format, ...);
BCS_DEBUG_API BCS_RESULT console_write_line_with_debug(const char* format, ...);
