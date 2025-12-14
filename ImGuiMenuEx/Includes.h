#ifndef _INCLUDES_
#define _INCLUDES_
// Standard C/C++ Libraries
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cwchar>
#include <ctime>
#include <cstdint>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <filesystem>
#include <bitset>

#include <windows.h>
#include <shlobj.h>
#include <chrono>

#include "TlHelp32.h"

// Windows API
#define WIN32_LEAN_AND_MEAN
#include <Lmcons.h>
#include <process.h>
#include <wininet.h>
#pragma comment(lib, "wininet.lib")

// DirectX 9
#include <d3d9.h>
#include <d3dx9.h>
#include <d3dcompiler.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3dcompiler.lib")

// ImGui
#include "imgui/imgui.h"
#include "imgui/imgui_internal.h"
#include "imgui/examples/imgui_impl_dx9.h"
#include "imgui/examples/imgui_impl_win32.h"
#include "ImGui/examples/example_win32_directx9/custom_elements.hpp"
#include <psapi.h>

#include "Xor.h"

#include "Minhook/include/MinHook.h"

// Hooking / Detour Libraries
#include <desvio.h>
#pragma comment(lib, "desvio.lib")

#include "NameSpaces.h"
#include "PatternScanner.h"
#include "Game_Info.h"

// Warnings
#pragma warning(disable : 4100)  // unreferenced formal parameter
#pragma warning(disable : 4018)  // signed/unsigned mismatch
#pragma warning(disable : 4838)  // narrowing conversion
#pragma warning(disable : 4477)  // format string mismatch
#pragma warning(disable : 4091)  // typedef ignored
#pragma warning(disable : 4996)  // deprecated functions
#pragma warning(disable : 4101)  // unreferenced local variable
#pragma warning(disable : 4244)  // possible data loss
#pragma warning(disable : 4482)  // nonstandard extension used: enum
#pragma warning(disable : 4390)  // empty controlled statement
#pragma warning(disable : 4552)  // possible data loss

// Text Draw Constants
#define TMenu DT_LEFT | DT_NOCLIP
#define TESP  DT_NOCLIP | DT_CENTER

#define M_PI 3.14159265358979323846f
#define DegToRad(degree)((degree) * (M_PI / 180.0f))
#define D3DCOLORCOLOR(c) D3DCOLOR_ARGB(255, int(c[0] * 255), int(c[1] * 255), int(c[2] * 255))
LPD3DXLINE pLine; LPD3DXFONT pFont; D3DVIEWPORT9 ViewPort;

#endif // _INCLUDES_