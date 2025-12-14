#include "Xor.h"
#pragma once
DWORD PatternScan(int type, CONST CHAR* szSignature)
{
    static auto patternToByte = [](CONST CHAR* szPattern)
        {
            auto       bytes = std::vector<int>{};
            const auto start = const_cast<char*>(szPattern);
            const auto end = const_cast<char*>(szPattern) + strlen(szPattern);

            for (auto current = start; current < end; ++current)
            {
                if (*current == '?')
                {
                    ++current;
                    if (*current == '?') ++current;
                    bytes.push_back(-1);
                }
                else {
                    bytes.push_back(strtoul(current, &current, 16));
                }
            }

            return bytes;
        };
    if (type == 0)
    {
        DWORD dwCShellEntry = (DWORD)GetModuleHandleA(PROCESS_CSHELL);

        const auto dosHeader = (PIMAGE_DOS_HEADER)dwCShellEntry;
        const auto ntHeaders = (PIMAGE_NT_HEADERS)((PBYTE)dwCShellEntry + dosHeader->e_lfanew);
        const auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
        auto       patternBytes = patternToByte(szSignature);
        const auto scanBytes = reinterpret_cast<PBYTE>(dwCShellEntry);
        const auto s = patternBytes.size();
        const auto d = patternBytes.data();

        bool bFoundFirst = false;
        for (auto i = 0ul; i < sizeOfImage - s; ++i)
        {
            bool found = true;
            for (auto j = 0ul; j < s; ++j) { if (scanBytes[i + j] != d[j] && d[j] != -1) { found = false; break; } }
            if (found) {  return reinterpret_cast<DWORD>(&scanBytes[i]); }
        }
    }
    else if (type == 1)
    {
        DWORD dwEngineEntry = (DWORD)GetModuleHandleA(PROCESS_ENGINE);

        const auto dosHeader = (PIMAGE_DOS_HEADER)dwEngineEntry;
        const auto ntHeaders = (PIMAGE_NT_HEADERS)((PBYTE)dwEngineEntry + dosHeader->e_lfanew);
        const auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
        auto       patternBytes = patternToByte(szSignature);
        const auto scanBytes = reinterpret_cast<PBYTE>(dwEngineEntry);
        const auto s = patternBytes.size();
        const auto d = patternBytes.data();

        bool bFoundFirst = false;
        for (auto i = 0ul; i < sizeOfImage - s; ++i)
        {
            bool found = true;
            for (auto j = 0ul; j < s; ++j) { if (scanBytes[i + j] != d[j] && d[j] != -1) { found = false; break; } }
            if (found) { return reinterpret_cast<DWORD>(&scanBytes[i]); }
        }
    }
    else if (type == 2)
    {
        DWORD dwEngine2Entry = (DWORD)GetModuleHandleA(PROCESS_ENGINE2);

        const auto dosHeader = (PIMAGE_DOS_HEADER)dwEngine2Entry;
        const auto ntHeaders = (PIMAGE_NT_HEADERS)((PBYTE)dwEngine2Entry + dosHeader->e_lfanew);
        const auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
        auto       patternBytes = patternToByte(szSignature);
        const auto scanBytes = reinterpret_cast<PBYTE>(dwEngine2Entry);
        const auto s = patternBytes.size();
        const auto d = patternBytes.data();

        bool bFoundFirst = false;
        for (auto i = 0ul; i < sizeOfImage - s; ++i)
        {
            bool found = true;
            for (auto j = 0ul; j < s; ++j) { if (scanBytes[i + j] != d[j] && d[j] != -1) { found = false; break; } }
            if (found) { return reinterpret_cast<DWORD>(&scanBytes[i]); }
        }
    }
    return 0;
}
DWORD PatternScanAdder(int type, CONST CHAR* szSignature, DWORD Adder)
{
    DWORD pattern = PatternScan(type, szSignature);  if (pattern) pattern = *(DWORD*)(pattern + Adder);
    return pattern;
}



namespace Logger
{
    namespace engine
    {
        DWORD Get_LTClientEXE;
#define Engine_LTClientEXE	 /*8B 44 24 08 8B 4C 24 04 50 51 68 ? ? ? 00 E8 7C EE FF FF*/XorStr<0xC9,57,0x84D2C924>("\xF1\x88\xEB\xF8\xF9\xEE\xFD\xE4\xF1\xE2\xEB\xF4\xED\x94\xF7\xEC\x9A\xFA\xE9\xE8\xFD\xEE\xEB\xC0\xD4\xD2\xC3\xD1\xD4\xC6\xD1\xD0\xC9\xD5\xCB\xD3\xCD\xD1\xCF\xC0\xC1\xD2\xB6\xCC\xD5\xC1\xB4\xD8\xBC\xBF\xDB\xBA\xBB\xDE\xB9\x46"+0x84D2C924).s

        DWORD Get_DrawPrimitive;
#define Engine_DrawPrimitive /*A1 ? ? ? ? C3 CC CC CC CC CC CC CC CC CC CC A1 ? ? ? ? C3 CC CC CC CC CC CC CC CC CC CC A1 ? ? ? ? C3 CC CC CC CC CC CC CC CC CC CC A1 ? ? ? ? C3 CC CC CC CC CC CC CC CC CC CC A1 ? ? ? ? C3 CC CC CC CC CC CC CC CC CC CC 8B 44 24 04 83 EC 0C*/XorStr<0x7E,241,0x4BCB129E>("\x3F\x4E\xA0\xBE\xA2\xBC\xA4\xBA\xA6\xB8\xA8\xCA\xB9\xAB\xCF\xCE\xAE\xCC\xD3\xB1\xD1\xD0\xB4\xD6\xD5\xB7\xDB\xDA\xBA\xD8\xDF\xBD\xDD\xDC\x80\xE2\xE1\x83\xE7\xE6\x86\xE4\xEB\x89\xEB\x9A\x8C\x92\x8E\x90\x90\x8E\x92\x8C\x94\xF6\x85\x97\xFB\xFA\x9A\xF8\xFF\x9D\xFD\xFC\xE0\x82\x81\xE3\x87\x86\xE6\x84\x8B\xE9\x89\x88\xEC\x8E\x8D\xEF\x93\x92\xF2\x90\x97\xF5\x97\xE6\xF8\xE6\xFA\xE4\xFC\xE2\xFE\xE0\xC0\xA2\xD1\xC3\xA7\xA6\xC6\xA4\xAB\xC9\xA9\xA8\xCC\xAE\xAD\xCF\xB3\xB2\xD2\xB0\xB7\xD5\xB5\xB4\xD8\xBA\xB9\xDB\xBF\xBE\xDE\xBC\x43\x21\x43\x32\x24\x3A\x26\x38\x28\x36\x2A\x34\x2C\x4E\x3D\x2F\x53\x52\x32\x50\x57\x35\x55\x54\x38\x5A\x59\x3B\x5F\x5E\x3E\x5C\x63\x01\x61\x60\x04\x66\x65\x07\x6B\x6A\x0A\x68\x6F\x0D\x6F\x1E\x10\x0E\x12\x0C\x14\x0A\x16\x08\x18\x7A\x09\x1B\x7F\x7E\x1E\x7C\x03\x61\x01\x00\x64\x06\x05\x67\x0B\x0A\x6A\x08\x0F\x6D\x0D\x0C\x70\x12\x11\x73\x17\x16\x76\x14\x1B\x79\x62\x19\x7C\x69\x6A\x7F\x52\x55\x42\x53\x50\x45\x5E\x54\x48\x2C\x29\x4B\x5C\x2E"+0x4BCB129E).s
    }
    namespace cshell
    {
        DWORD Get_GameClientShell;
#define Cshell_GameClientShell /*A1 ? ? ? 38 8B 80 AC  92 ? ? 83 F8 01 74 30*/XorStr<0x70,44,0xBAC2D7A6>("\x31\x40\x52\x4C\x54\x4A\x56\x48\x58\x4A\x42\x5B\x44\x3F\x5E\x47\xB0\xA1\xC3\xC0\xA4\xA5\xBF\xB5\xA8\xB6\xAA\xB4\xAC\xB5\xBD\xAF\xD6\xA9\xB2\xA3\xA5\xB5\xA1\xA3\xB8\xAA\xAA"+0xBAC2D7A6).s

        DWORD Get_cInterfaceMgr;
#define Cshell_InterfaceMgr /*A1 ? ? ? ? 83 EC 08 53 55 8B A8 D0 52 00 00*/XorStr<0xFF,44,0x6697D9F1>("\xBE\x31\x21\x3D\x23\x3B\x25\x39\x27\x37\x29\x32\x38\x2C\x48\x4D\x2F\x20\x29\x32\x26\x27\x35\x23\x22\x38\x21\x58\x3B\x5D\x25\x3E\x5B\x10\x01\x17\x11\x04\x15\x16\x07\x18\x19"+0x6697D9F1).s

        DWORD Get_LocalPlayer;
#define Cshell_LocalPlayer /*83 EC 08 56 8B F1 83 7E 0C 00 74 2A*/XorStr<0x50,36,0x05B41D93>("\x68\x62\x72\x16\x17\x75\x66\x6F\x78\x6C\x6C\x7B\x64\x1F\x7E\x19\x51\x41\x5A\x50\x44\x52\x23\x47\x58\x2A\x4A\x5B\x5C\x4D\x59\x5B\x50\x43\x33"+0x05B41D93).s

        DWORD Get_ClientInfoMgr;
#define Cshell_ClientInfoMgr /*8B 0D ? ? ? ? 50 E8 ? ? ? ? 85 C0 74 6C*/XorStr<0xF0,40,0x7ABFB220>("\xC8\xB3\xD2\xC3\xB0\xD5\xC9\xD7\xC7\xD9\xC5\xDB\xC3\xDD\xCB\xCF\x20\x44\x3A\x23\x3B\x25\x39\x27\x37\x29\x35\x2B\x34\x38\x2E\x4C\x20\x31\x25\x27\x34\x23\x55"+0x7ABFB220).s

        DWORD Get_PlayerByIndex;
#define Cshell_PlayerByIndex /*51 56 8B F1 83 7E 0C 00 74 2B*/XorStr<0xC8,30,0xA49538A9>("\xFD\xF8\xEA\xFE\xFA\xED\xF6\x8D\xF0\x97\xE3\xF3\xEC\xE6\xF6\xE0\x9D\xF9\xEA\x98\xFC\xED\xEE\xFF\xD7\xD5\xC2\xD1\xA6"+0xA49538A9).s

        DWORD Get_WeaponMGR;
#define Cshell_WeaponMGR /*8B 0D ? ? ? ? E8 ? ? ? ? 85 C0 0F 84 ? ? ? ? 83 B8*/XorStr<0x30,51,0x4108840F>("\x08\x73\x12\x03\x70\x15\x09\x17\x07\x19\x05\x1B\x03\x1D\x7B\x07\x60\x7E\x62\x7C\x64\x7A\x66\x78\x68\x71\x7F\x6B\x0F\x7D\x6E\x7F\x16\x71\x6A\x67\x74\x6A\x76\x68\x78\x66\x7A\x64\x7C\x65\x6D\x7F\x22\x59"+0x4108840F).s

        DWORD Get_BuildGuid, Get_LTClientDLL, Get_LTCSBase;
#define Cshell_BuildGuid /*B8 ? ? ? ? C3 CC CC CC CC CC CC CC CC CC CC 8B C1 C7 00 ? ? ? ? C3 CC CC CC CC CC CC CC 6A FF*/XorStr<0xF5,94,0x65939D93>("\xB7\xCE\xD7\xC7\xD9\xC5\xDB\xC3\xDD\xC1\xDF\x43\x32\x22\x40\x47\x25\x45\x44\x28\x4A\x49\x2B\x4F\x4E\x2E\x4C\x53\x31\x51\x50\x34\x56\x55\x37\x5B\x5A\x3A\x58\x5F\x3D\x5D\x5C\x00\x19\x60\x03\x67\x14\x06\x64\x1F\x09\x1A\x1B\x0C\x12\x0E\x10\x10\x0E\x12\x0C\x14\x76\x05\x17\x7B\x7A\x1A\x78\x7F\x1D\x7D\x7C\x60\x02\x01\x63\x07\x06\x66\x04\x0B\x69\x09\x08\x6C\x7B\x0F\x6F\x16\x17"+0x65939D93).s

        DWORD Get_LongDistance;
#define Cshell_LongDistance /*D9 05 ? ? ? ? EB 02 D9 EE D9 5C 24 04 D9 46 28*/XorStr<0xE7,47,0xD214A4FF>("\xA3\xD1\xC9\xDA\xDE\xCC\xD2\xCE\xD0\xD0\xCE\xD2\xCC\xD4\xB0\xB4\xD7\xC8\xCB\xDA\xBF\xC5\xDD\xBB\xBA\x20\x45\x3B\x23\x31\x46\x26\x35\x3C\x29\x3A\x3F\x2C\x49\x37\x2F\x24\x27\x32\x21\x2C"+0xD214A4FF).s
    }
}
