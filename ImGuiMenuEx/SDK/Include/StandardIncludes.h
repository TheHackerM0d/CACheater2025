#pragma once

#include <Windows.h>
#include <iostream>
#include <time.h>
#include <string>
#include <tchar.h>
#include <sstream>
#include <fstream>
#include <time.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <wininet.h>
#include <vector>
#include <stdio.h>
#include <intrin.h>
#include <Psapi.h>
#include <tlhelp32.h>

#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "wininet.lib")
#pragma comment(lib, "psapi.lib")
#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "d3d9.lib")


using namespace std;

#pragma warning(disable: 4244)
#pragma warning(disable: 4700)
#pragma warning(disable: 4996)
#pragma warning(disable: 4748)
#pragma warning(disable: 4305)

#define CANA
#define VIP

#define ASM_STATIC_BIT \
        _asm push eax \
        _asm push ebx \
        _asm push ecx \
        _asm push esi \
        _asm xor ebx, eax \
        _asm and esi, 0xFFFFFFFF \
        _asm and eax, 0xFFFFFFFF \
        _asm or esi, 0x0 \
        _asm xchg ebx, eax \
        _asm mov eax, ebx \
        _asm or ebx, 0x0 \
        _asm xor esi, ecx \
        _asm xchg esi, ebx \
        _asm mov ebx, ecx \
        _asm or eax, 0x0 \
        _asm mov esi, ecx \
        _asm xchg ecx, eax \
        _asm xor ecx, esi \
        _asm pop esi \
        _asm pop ecx \
        _asm pop ebx \
        _asm pop eax \

#define ASM_STATIC_BYTE ASM_STATIC_BIT ASM_STATIC_BIT ASM_STATIC_BIT
#define ASM_STATIC_CHUNK ASM_STATIC_BYTE ASM_STATIC_BYTE
#define ASM_LOL ASM_STATIC_CHUNK ASM_STATIC_CHUNK ASM_STATIC_CHUNK