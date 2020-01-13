/**
 * Copyright (C) 2014 Patrick Mours. All rights reserved.
 * License: https://github.com/crosire/reshade#license
 */

#include "hook_manager.hpp"
#include "dll_log.hpp"
#include <d3d9.h>

HOOK_EXPORT int WINAPI D3DPERF_BeginEvent(D3DCOLOR col, LPCWSTR wszName)
{
	UNREFERENCED_PARAMETER(col);
	UNREFERENCED_PARAMETER(wszName);
	//LOG(INFO) << "Event Name:"<< wszName;
	return 0;
}
HOOK_EXPORT int WINAPI D3DPERF_EndEvent()
{
	return 0;
}

HOOK_EXPORT void WINAPI D3DPERF_SetMarker(D3DCOLOR col, LPCWSTR wszName)
{
	UNREFERENCED_PARAMETER(col);
	UNREFERENCED_PARAMETER(wszName);
	//LOG(INFO) << "	Marker Name:" << wszName;
}
HOOK_EXPORT void WINAPI D3DPERF_SetRegion(D3DCOLOR col, LPCWSTR wszName)
{
	UNREFERENCED_PARAMETER(col);
	UNREFERENCED_PARAMETER(wszName);
	//LOG(INFO) << "	Region Name:" << wszName;
}
HOOK_EXPORT void WINAPI D3DPERF_SetOptions(DWORD dwOptions)
{
	UNREFERENCED_PARAMETER(dwOptions);

#ifdef _DEBUG // Enable PIX in debug builds (calling 'D3DPERF_SetOptions(1)' disables profiling/analysis tools, so revert that)
	reshade::hooks::call(D3DPERF_SetOptions)(0);
#endif
}

HOOK_EXPORT BOOL WINAPI D3DPERF_QueryRepeatFrame()
{
	return FALSE;
}

HOOK_EXPORT DWORD WINAPI D3DPERF_GetStatus()
{
	return 0;
}
