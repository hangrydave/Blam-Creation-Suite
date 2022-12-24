#pragma once

#include "platform-specific-define-platform.h"

#ifdef BCS_WIN32
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <shellapi.h>
#include <shlwapi.h>
#include <fileapi.h>
#include <ShlObj.h>
#include <strsafe.h>
#include <psapi.h>
#include <dbghelp.h>

#define __TBB_SOURCE_DIRECTLY_INCLUDED 1
#include <tbb/tbb.h>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
#endif