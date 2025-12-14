// dear imgui: standalone example application for DirectX 9
// If you are new to dear imgui, see examples/README.txt and documentation at the top of imgui.cpp.
#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"
#include <d3d9.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <tchar.h>
#include "imgui_internal.h"
#include "custom_elements.hpp"
// Data
static LPDIRECT3D9              g_pD3D = NULL;
static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp = {};
namespace cheat
{
    namespace visual
    {
        bool NxChams = false;
        bool NoFog = false;
        bool NoSmoke = false;
        bool ScreenGlow = false;
        bool RemoveTexture = false;
        bool FullBrights = false;
    }
    namespace player
    {
        bool Invisible = false;
        bool CameraShake = false;
        bool knockback = false;
        bool JumpRequested = false;
        bool MovePenalty = false;
        bool Fly = false;
        namespace Clip
        {
            bool Activation = false;
            int NormalSpeed = 1;
        }
    }
    namespace weapon
    {
        bool EDistance = false;

        bool BackCam = true;

        bool NoSpread = false;
        bool NoRecoil = false;
        int RapidFires = false;
        float RapidLegit = 0.0f;

        bool ZoomTime = false;
        bool MovePenalty = false;
        int MovePenaltyValue = false;

        bool NoReload = false;

        bool RemoveAnimation = false;

        bool MultiBullet = false;
        int MultiBullets = 1;

        namespace Backups
        {
            bool DefaultWepMgrEffect = false;
            bool DefaultPlayerEffect = false;
            float DefaultWeapon[20];
            float DefaultSpread[20][2000];
            float DefaultRecoil[20][2000];
            float DefaultOther[20][2000];
        }
    }
    namespace special
    {
        bool NameFilter = false;
        bool KickHack = false;
    }
    namespace esp
    {
        namespace Ennemy
        {
            bool Activation = false;
            float Visible[] = { 1.000f, 1.000f, 0.000f, 1.000f };
            float NonVisible[] = { 1.000f, 1.000f, 0.800f, 0.000f };
        }
        namespace Allies
        {
            bool Activation = false;
            float Visible[] = { 1.000f, 0.569f, 0.824f, 1.00f };
            float NonVisible[] = { 1.000f, 1.000f, 1.000f, 1.000f };
        }
        namespace Other
        {
            bool Explosive = false;
            bool Weapon = false;
        }
        namespace radar
        {
            bool Activation = false;
            bool Enemy = false;
            bool Allies = false;
            bool Visible = false;
            bool Respawn = false;
        }
        bool Name = false;
        bool Lines = false;
        bool Box = false;
        bool Distance = false;
        bool Health = false;
        bool SpawnCheck = false;
        bool Bone = false;
        bool Armor = false;
        bool VisibleCheck = false;
    }
    namespace aimbot
    {
        //bool
        bool Activation = false;
        bool AutoAim = false;
        bool VisibleCheck = false;
        bool SpawnCheck = false;
        bool SmoothAim = true;
        bool Circle = false;
        //float
        float SmoothMax = 1.0f;
        float SmoothMin = 0.0f;
        //int
        int AimBone = 0;
        int AimFov = 1;
        int AimKey = 1;
        int AimType = 0;
        namespace Ghost
        {
            namespace Radius
            {
                bool Activation = false;
                int Bone;
                int Size = 1;
            }
        }
    }
    namespace remotekill
    {

        bool Activation = false;
        bool VisibleCheck = false;
        bool RespawnCheck = false;
        bool FOV_Check = false;
        bool ShowFOV = false;
        int FOV = 1;
        int Bone = 0;
    }
    namespace spoofer
    {
        namespace cosmetic
        {
            bool Activation = false;
            bool Character = false;
            bool Helmet = false;
            bool Goggle = false;
            bool Backpack = false;

            int CharacterID = false;
            int HelmetID = false;
            int GoggleID = false;
            int BackpackID = false;
        }
    }
}
namespace ModMenu
{
    bool LoggingAddress = true;
    bool Logger = false;
}
static const char* KeyNames[] = {
    "OFF",
    "VK_LBUTTON",
    "VK_RBUTTON",
    "VK_CANCEL",
    "VK_MBUTTON",
    "VK_XBUTTON1",
    "VK_XBUTTON2",
    "Unknown",
    "VK_BACK",
    "VK_TAB",
    "Unknown",
    "Unknown",
    "VK_CLEAR",
    "VK_RETURN",
    "Unknown",
    "Unknown",
    "VK_SHIFT",
    "VK_CONTROL",
    "VK_MENU",
    "VK_PAUSE",
    "VK_CAPITAL",
    "VK_KANA",
    "Unknown",
    "VK_JUNJA",
    "VK_FINAL",
    "VK_KANJI",
    "Unknown",
    "VK_ESCAPE",
    "VK_CONVERT",
    "VK_NONCONVERT",
    "VK_ACCEPT",
    "VK_MODECHANGE",
    "VK_SPACE",
    "VK_PRIOR",
    "VK_NEXT",
    "VK_END",
    "VK_HOME",
    "VK_LEFT",
    "VK_UP",
    "VK_RIGHT",
    "VK_DOWN",
    "VK_SELECT",
    "VK_PRINT",
    "VK_EXECUTE",
    "VK_SNAPSHOT",
    "VK_INSERT",
    "VK_DELETE",
    "VK_HELP",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "VK_LWIN",
    "VK_RWIN",
    "VK_APPS",
    "Unknown",
    "VK_SLEEP",
    "VK_NUMPAD0",
    "VK_NUMPAD1",
    "VK_NUMPAD2",
    "VK_NUMPAD3",
    "VK_NUMPAD4",
    "VK_NUMPAD5",
    "VK_NUMPAD6",
    "VK_NUMPAD7",
    "VK_NUMPAD8",
    "VK_NUMPAD9",
    "VK_MULTIPLY",
    "VK_ADD",
    "VK_SEPARATOR",
    "VK_SUBTRACT",
    "VK_DECIMAL",
    "VK_DIVIDE",
    "VK_F1",
    "VK_F2",
    "VK_F3",
    "VK_F4",
    "VK_F5",
    "VK_F6",
    "VK_F7",
    "VK_F8",
    "VK_F9",
    "VK_F10",
    "VK_F11",
    "VK_F12",
    "VK_F13",
    "VK_F14",
    "VK_F15",
    "VK_F16",
    "VK_F17",
    "VK_F18",
    "VK_F19",
    "VK_F20",
    "VK_F21",
    "VK_F22",
    "VK_F23",
    "VK_F24",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "VK_NUMLOCK",
    "VK_SCROLL",
    "VK_OEM_NEC_EQUAL",
    "VK_OEM_FJ_MASSHOU",
    "VK_OEM_FJ_TOUROKU",
    "VK_OEM_FJ_LOYA",
    "VK_OEM_FJ_ROYA",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "VK_LSHIFT",
    "VK_RSHIFT",
    "VK_LCONTROL",
    "VK_RCONTROL",
    "VK_LMENU",
    "VK_RMENU"
};
static const int KeyCodes[] = {
    0x0,  //Undefined
    0x01,
    0x02,
    0x03,
    0x04,
    0x05,
    0x06,
    0x07, //Undefined
    0x08,
    0x09,
    0x0A, //Reserved
    0x0B, //Reserved
    0x0C,
    0x0D,
    0x0E, //Undefined
    0x0F, //Undefined
    0x10,
    0x11,
    0x12,
    0x13,
    0x14,
    0x15,
    0x16, //IME On
    0x17,
    0x18,
    0x19,
    0x1A, //IME Off
    0x1B,
    0x1C,
    0x1D,
    0x1E,
    0x1F,
    0x20,
    0x21,
    0x22,
    0x23,
    0x24,
    0x25,
    0x26,
    0x27,
    0x28,
    0x29,
    0x2A,
    0x2B,
    0x2C,
    0x2D,
    0x2E,
    0x2F,
    0x30,
    0x31,
    0x32,
    0x33,
    0x34,
    0x35,
    0x36,
    0x37,
    0x38,
    0x39,
    0x3A, //Undefined
    0x3B, //Undefined
    0x3C, //Undefined
    0x3D, //Undefined
    0x3E, //Undefined
    0x3F, //Undefined
    0x40, //Undefined
    0x41,
    0x42,
    0x43,
    0x44,
    0x45,
    0x46,
    0x47,
    0x48,
    0x49,
    0x4A,
    0x4B,
    0x4C,
    0x4B,
    0x4E,
    0x4F,
    0x50,
    0x51,
    0x52,
    0x53,
    0x54,
    0x55,
    0x56,
    0x57,
    0x58,
    0x59,
    0x5A,
    0x5B,
    0x5C,
    0x5D,
    0x5E, //Rservered
    0x5F,
    0x60, //Numpad1
    0x61, //Numpad2
    0x62, //Numpad3
    0x63, //Numpad4
    0x64, //Numpad5
    0x65, //Numpad6
    0x66, //Numpad7
    0x67, //Numpad8
    0x68, //Numpad8
    0x69, //Numpad9
    0x6A,
    0x6B,
    0x6C,
    0x6D,
    0x6E,
    0x6F,
    0x70, //F1
    0x71, //F2
    0x72, //F3
    0x73, //F4
    0x74, //F5
    0x75, //F6
    0x76, //F7
    0x77, //F8
    0x78, //F9
    0x79, //F10
    0x7A, //F11
    0x7B, //F12
    0x7C, //F13
    0x7D, //F14
    0x7E, //F15
    0x7F, //F16
    0x80, //F17
    0x81, //F18
    0x82, //F19
    0x83, //F20
    0x84, //F21
    0x85, //F22
    0x86, //F23
    0x87, //F24
    0x88, //Unkown
    0x89, //Unkown
    0x8A, //Unkown
    0x8B, //Unkown
    0x8C, //Unkown
    0x8D, //Unkown
    0x8E, //Unkown
    0x8F, //Unkown
    0x90,
    0x91,
    0x92, //OEM Specific
    0x93, //OEM Specific
    0x94, //OEM Specific
    0x95, //OEM Specific
    0x96, //OEM Specific
    0x97, //Unkown
    0x98, //Unkown
    0x99, //Unkown
    0x9A, //Unkown
    0x9B, //Unkown
    0x9C, //Unkown
    0x9D, //Unkown
    0x9E, //Unkown 
    0x9F, //Unkown
    0xA0,
    0xA1,
    0xA2,
    0xA3,
    0xA4,
    0xA5
};

void Hotkey(int* k, const ImVec2& size_arg = ImVec2(0, 0))
{
    static bool waitingForKey = false;
    static int delayCounter = 0;

    if (!waitingForKey) {
        if (ImGui::Button(KeyNames[*k], size_arg)) {
            waitingForKey = true;
            delayCounter = 0;
        }
    }
    else {
        ImGui::Button("...", size_arg);

        if (++delayCounter > 3) {
            for (int i = 0; i < 256; i++) {
                if (GetAsyncKeyState(i) & 0x8000) {
                    *k = i;
                    waitingForKey = false;
                    delayCounter = 0;
                    break;
                }
            }
        }
    }
}

#include <psapi.h>
#include <string>
#include <sstream>
std::string GetWindowTitle()
{
    char title[256];
    HWND hwnd = GetForegroundWindow(); // or get the game HWND if you know it
    if (hwnd && GetWindowTextA(hwnd, title, sizeof(title)))
        return std::string(title);
    return "Unknown Game";
}

static int sizeX = 414;
static int sizeY = 274;
bool CreateDeviceD3D(HWND hWnd);
void CleanupDeviceD3D();
void ResetDevice();
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
c_gui gui;
int main(int, char**)
{
    WNDCLASSEX wc = { sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L, GetModuleHandle(NULL), NULL, NULL, NULL, NULL, _T("ImGui Example"), NULL };
    ::RegisterClassEx(&wc);
    HWND hwnd = ::CreateWindow(wc.lpszClassName, _T("Combat Arms Classic"), WS_OVERLAPPEDWINDOW, 100, 100, 1280, 800, NULL, NULL, wc.hInstance, NULL);
    if (!CreateDeviceD3D(hwnd))
    {
        CleanupDeviceD3D();
        ::UnregisterClass(wc.lpszClassName, wc.hInstance);
        return 1;
    }
    ::ShowWindow(hwnd, SW_SHOWDEFAULT);
    ::UpdateWindow(hwnd);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();

    ImGui_ImplWin32_Init(hwnd);
    ImGui_ImplDX9_Init(g_pd3dDevice);
    io.Fonts->AddFontFromFileTTF("../../misc/fonts/Myriad-Pro_31655.ttf", 13.0f);
    // Our state
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Main loop
    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            ::TranslateMessage(&msg);
            ::DispatchMessage(&msg);
            continue;
        }
        ImGui_ImplDX9_NewFrame();
        ImGui_ImplWin32_NewFrame();
        ImGui::NewFrame();
        {
            std::string gameName = GetWindowTitle(); // or GetWindowTitle()
            std::stringstream ss;
            ss << "Seppuku Project [Premium] [" << gameName << "]" << "[Build Version: 1.0.2]";
            std::string windowTitle = ss.str();

            ImGui::ShowDemoWindow(nullptr);

            //ImGui::Begin(windowTitle.c_str(), nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
            //{
            //    ImGui::SetWindowSize(ImVec2(670, 400));
            //    auto p = ImGui::GetWindowPos();  auto __draw = ImGui::GetWindowDrawList(); static int tab = 0;
            //    __draw->AddRectFilled(ImVec2(p.x + 0, p.y + 30), ImVec2(p.x + 150, p.y + 395), ImColor(31, 31, 41, 255));
            //    ImGui::SetCursorPos(ImVec2(0, 30));
            //    ImGui::BeginGroup();
            //    {
            //        if (gui.tab("Aimbot", tab == 0, ImVec2(150, 25))) tab = 0;
            //        if (gui.tab("ESP", tab == 1, ImVec2(150, 25))) tab = 1;
            //        if (gui.tab("Misc", tab == 2, ImVec2(150, 25))) tab = 2;
            //        if (gui.tab("Spoofer", tab == 3, ImVec2(150, 25))) tab = 3;
            //        if (gui.tab("Configuration", tab == 5, ImVec2(150, 25))) tab = 5;
            //    }
            //    ImGui::EndGroup();
            //    ImGui::SetCursorPos(ImVec2(156, 30));
            //    ImGui::BeginGroup();
            //    {
            //        switch (tab)
            //        {
            //        case 0:
            //        {
            //            ImGui::BeginChild("Generals", ImVec2(250, 190));
            //            {
            //                ImGui::BeginGroup();
            //                {
            //                    ImGui::Checkbox(AIMBOT_Activation, &cheat::aimbot::Activation);
            //                    ImGui::Checkbox(AIMBOT_AutoAim, &cheat::aimbot::AutoAim);
            //                    ImGui::Checkbox(AIMBOT_ActSmooth, &cheat::aimbot::SmoothAim);
            //                    ImGui::Checkbox(AIMBOT_VisibleCheck, &cheat::aimbot::VisibleCheck);
            //                    ImGui::Checkbox(AIMBOT_SpawnCheck, &cheat::aimbot::SpawnCheck);
            //                    ImGui::Text("Aim Key"); ImGui::SameLine(); Hotkey(&cheat::aimbot::AimKey);
            //                }
            //                ImGui::EndGroup();
            //            }
            //            ImGui::EndChild();
            //            ImGui::SameLine(0, 8);
            //            ImGui::BeginChild("Settings", ImVec2(250, 190));
            //            {
            //                ImGui::BeginGroup();
            //                {
            //                    ImGui::SliderInt(AIMBOT_AimFOV, &cheat::aimbot::AimFov, 1, 360);
            //                    ImGui::SliderFloat(AIMBOT_SmoothSpeed, &cheat::aimbot::SmoothMin, 0, 1);
            //                    ImGui::Combo(AIMBOT_AimType, &cheat::aimbot::AimType, "Close To Me\0Close To Crosshair");
            //                    ImGui::Combo(AIMBOT_AimBone, &cheat::aimbot::AimBone, "Head\0Neck\0Chest\0Dick");
            //                    ImGui::EndGroup();
            //                }
            //            }
            //            ImGui::EndChild();
            //            ImGui::BeginChild(GAIM_TITLE_Main, ImVec2(250, 170));
            //            {
            //                ImGui::BeginGroup();
            //                {
            //                    ImGui::Checkbox(GAIM_Activation, &cheat::aimbot::Ghost::Radius::Activation);
            //                    ImGui::Combo(GAIM_BONE_ID, &cheat::aimbot::Ghost::Radius::Bone, ___("General\0Head\0Neck\0Chest\0Dick"));
            //                    ImGui::SliderInt(GAIM_BONE_Size, &cheat::aimbot::Ghost::Radius::Size, 0, 300);
            //                }
            //                ImGui::EndGroup();
            //            }
            //            ImGui::EndChild();
            //            ImGui::SameLine(0, 8);
            //            ImGui::BeginChild(REMOTEKILL_TITLE_Main, ImVec2(250, 170));
            //            {
            //                ImGui::BeginGroup();
            //                {
            //                    ImGui::Checkbox(REMOTEKILL_Activation, &cheat::remotekill::Activation);
            //                    ImGui::Checkbox(REMOTEKILL_Visible, &cheat::remotekill::VisibleCheck);
            //                    ImGui::Checkbox(REMOTEKILL_Respawn, &cheat::remotekill::RespawnCheck);
            //                    ImGui::Checkbox(REMOTEKILL_FOV, &cheat::remotekill::FOV_Check);
            //                    if (cheat::remotekill::FOV_Check)
            //                        ImGui::SliderInt(REMOTEKILL_FOVs, &cheat::remotekill::FOV, 1, 360);
            //                    ImGui::Combo(REMOTEKILL_Bone, &cheat::remotekill::Bone, ___("Head\0Neck\0Chest\0Dick"));
            //                }
            //                ImGui::EndGroup();
            //            }
            //            ImGui::EndChild();
            //        }
            //        break;
            //        case 1:
            //        {
            //            ImGui::BeginChild("Generals", ImVec2(250, 280));
            //            {
            //                ImGui::BeginGroup();
            //                {
            //                    ImGui::Checkbox(ESP_TITLE_Enemy, &cheat::esp::Ennemy::Activation);
            //                    ImGui::Checkbox(ESP_TITLE_Allies, &cheat::esp::Allies::Activation);
            //                    ImGui::Checkbox(ESP_Name, &cheat::esp::Name);
            //                    ImGui::Checkbox(ESP_Line, &cheat::esp::Lines);
            //                    ImGui::Checkbox(ESP_Box, &cheat::esp::Box);
            //                    ImGui::Checkbox(ESP_Bone, &cheat::esp::Bone);
            //                    ImGui::Checkbox(ESP_Distance, &cheat::esp::Distance);
            //                    ImGui::Checkbox(ESP_Health, &cheat::esp::Health);
            //                    ImGui::Checkbox(ESP_Armor, &cheat::esp::Armor);
            //                    ImGui::Checkbox(ESP_CHECKER_Spawn, &cheat::esp::SpawnCheck);
            //                    ImGui::Checkbox(ESP_CHECKER_Visible, &cheat::esp::VisibleCheck);
            //                }
            //                ImGui::EndGroup();
            //            }
            //            ImGui::EndChild();
            //            ImGui::SameLine(0, 8);
            //            ImGui::BeginChild("Colors", ImVec2(250, 130));
            //            {
            //                ImGui::BeginGroup();
            //                {
            //                    ImGui::ColorEdit3(ESP_Ennemy_COLOR_Invisible, cheat::esp::Ennemy::NonVisible);
            //                    ImGui::ColorEdit3(ESP_Ennemy_COLOR_Visible, cheat::esp::Ennemy::Visible);
            //                    ImGui::ColorEdit3(ESP_Allies_COLOR_Invisible, cheat::esp::Allies::NonVisible);
            //                    ImGui::ColorEdit3(ESP_Allies_COLOR_Visible, cheat::esp::Allies::Visible);
            //                }
            //                ImGui::EndGroup();
            //            }
            //            ImGui::EndChild();
            //            ImGui::SetCursorPos(ImVec2(414, 270));

            //            ImGui::BeginChild("Others", ImVec2(250, 80));
            //            {
            //                ImGui::BeginGroup();
            //                {
            //                    ImGui::Checkbox(ESP_OTHER_Weapon, &cheat::esp::Other::Weapon);
            //                    ImGui::Checkbox(ESP_OTHER_Explosive, &cheat::esp::Other::Explosive);
            //                }
            //                ImGui::EndGroup();
            //            }
            //            ImGui::EndChild();
            //            ImGui::SetCursorPos(ImVec2(414, 164));
            //            ImGui::BeginChild(ESP_RADAR_MENU, ImVec2(250, 100));
            //            {
            //                ImGui::BeginGroup();
            //                {
            //                    ImGui::Checkbox(ESP_RADAR_Activation, &cheat::esp::radar::Activation);
            //                    ImGui::Checkbox(ESP_RADAR_Enemy, &cheat::esp::radar::Enemy);
            //                    ImGui::Checkbox(ESP_RADAR_Allies, &cheat::esp::radar::Allies);
            //                }
            //                ImGui::EndGroup();
            //            }
            //            ImGui::EndChild();
            //        }
            //        break;
            //        case 2:
            //        {
            //            ImGui::BeginChild(VISUAL_MENU, ImVec2(250, 170));
            //            {
            //                ImGui::BeginGroup();
            //                {
            //                    ImGui::Checkbox(NEXON_Chams, &cheat::visual::NxChams);
            //                    ImGui::Checkbox(NEXON_REMOVE_Fog, &cheat::visual::NoFog);
            //                    ImGui::Checkbox(NEXON_REMOVE_Smoke, &cheat::visual::NoSmoke);
            //                    ImGui::Checkbox(NEXON_Glow, &cheat::visual::ScreenGlow);
            //                    ImGui::Checkbox(NEXON_Texture, &cheat::visual::RemoveTexture);
            //                    ImGui::Checkbox(NEXON_Bright, &cheat::visual::FullBrights);
            //                }
            //                ImGui::EndGroup();
            //            }
            //            ImGui::EndChild();
            //            ImGui::SameLine(0, 8);
            //            ImGui::BeginChild(WEAPON_MENU, ImVec2(250, 250));
            //            {
            //                ImGui::BeginGroup();
            //                {
            //                    ImGui::Checkbox(WEAPON_Distance, &cheat::weapon::EDistance);
            //                    ImGui::Checkbox(WEAPON_Recoil, &cheat::weapon::NoSpread);
            //                    ImGui::Checkbox(WEAPON_Spread, &cheat::weapon::NoRecoil);
            //                    ImGui::Checkbox(WEAPON_FastZoom, &cheat::weapon::ZoomTime);
            //                    ImGui::Checkbox(WEAPON_Reload, &cheat::weapon::NoReload);
            //                    ImGui::Checkbox(WEAPON_FastSwitch, &cheat::weapon::RemoveAnimation);
            //                    ImGui::Checkbox(WEAPON_RemoveWeight, &cheat::weapon::MovePenalty);
            //                    if (cheat::weapon::MovePenalty) ImGui::SliderInt(WEAPON_RemoveWeightValue, &cheat::weapon::MovePenaltyValue, 0, 10);
            //                    ImGui::Checkbox(WEAPON_MultiBullet, &cheat::weapon::MultiBullet);
            //                    if (cheat::weapon::MultiBullet) ImGui::InputInt(WEAPON_MultiBulletValue, &cheat::weapon::MultiBullets);
            //                    ImGui::Combo(WEAPON_RapidFire_Activation, &cheat::weapon::RapidFires, ___("Normal\0Legit\0Rage"));
            //                    if (cheat::weapon::RapidFires == 1) ImGui::SliderFloat(WEAPON_RapidFire_Legit, &cheat::weapon::RapidLegit, 0, 1);
            //                }
            //                ImGui::EndGroup();
            //            }
            //            ImGui::EndChild();
            //            ImGui::SetCursorPos(ImVec2(156, 205));
            //            ImGui::BeginChild(PLAYER_MENU, ImVec2(250, 150));
            //            {
            //                ImGui::BeginGroup();
            //                {
            //                    ImGui::Checkbox(PLAYER_Invisible, &cheat::player::Invisible);
            //                    ImGui::Checkbox(PLAYER_Fly_Activation, &cheat::player::Fly);
            //                    ImGui::Checkbox(PLAYER_AntiKnockback, &cheat::player::knockback);
            //                    ImGui::Checkbox(PLAYER_BHOP, &cheat::player::JumpRequested);
            //                    ImGui::Checkbox(PLAYER_NoClip, &cheat::player::Clip::Activation);
            //                    if (cheat::player::Clip::Activation)
            //                        ImGui::SliderInt(PLAYER_NoClipSpeed, &cheat::player::Clip::NormalSpeed, 1, 10);
            //                }
            //                ImGui::EndGroup();
            //            }
            //            ImGui::EndChild();
            //            ImGui::SetCursorPos(ImVec2(414, 286));
            //            ImGui::BeginChild("Special", ImVec2(250, 80));
            //            {
            //                ImGui::BeginGroup();
            //                {
            //                    ImGui::Checkbox(SPECIAL_KickHack, &cheat::special::KickHack);
            //                    ImGui::Checkbox(SPECIAL_NameFilter, &cheat::special::NameFilter);
            //                }
            //                ImGui::EndGroup();
            //            }
            //            ImGui::EndChild();

            //        }
            //        break;
            //        case 3:
            //        {
            //            ImGui::BeginChild("Cosmetic", ImVec2(250, 145), true);
            //            {
            //                ImGui::BeginGroup();
            //                {
            //                    ImGui::Checkbox(SPOOF_Activation, &cheat::spoofer::cosmetic::Activation);
            //                    ImGui::Checkbox(SPOOF_Character, &cheat::spoofer::cosmetic::Character);
            //                    ImGui::Checkbox(SPOOF_Helmet, &cheat::spoofer::cosmetic::Helmet);
            //                    ImGui::Checkbox(SPOOF_Goggle, &cheat::spoofer::cosmetic::Goggle);
            //                    ImGui::Checkbox(SPOOF_Backpack, &cheat::spoofer::cosmetic::Backpack);
            //                }
            //                ImGui::EndGroup();
            //            }
            //            ImGui::EndChild();
            //            ImGui::SameLine(0, 8);
            //            ImGui::BeginChild("Cosmetic Settings", ImVec2(250, 145));
            //            {
            //                ImGui::BeginGroup();
            //                {
            //                    if (cheat::spoofer::cosmetic::Activation) ImGui::Text("Cosmetic Activated!"); else ImGui::Text("Cosmetic Offline!");
            //                    ImGui::InputInt(SPOOF_Characters, &cheat::spoofer::cosmetic::CharacterID);
            //                    ImGui::InputInt(SPOOF_Helmets, &cheat::spoofer::cosmetic::HelmetID);
            //                    ImGui::InputInt(SPOOF_Goggles, &cheat::spoofer::cosmetic::GoggleID);
            //                    ImGui::InputInt(SPOOF_Backpacks, &cheat::spoofer::cosmetic::BackpackID);
            //                }
            //                ImGui::EndGroup();
            //            }
            //            ImGui::EndChild();
            //        }
            //        break;
            //        case 4:
            //        {

            //        }
            //        break;
            //        case 5:
            //        {
            //            ImGui::BeginChild("Cheat Information", ImVec2(250, 145), true);
            //            {
            //                ImGui::BeginGroup();
            //                {
            //                    static bool qsddsq = false;
            //                    ImGui::Checkbox("Address Logger", &ModMenu::Logger);
            //                    ImGui::Checkbox("test lock", &qsddsq);
            //                    if (ImGui::Button("Delete.."))
            //                        ImGui::OpenPopup("Message 1");

            //                    if (ImGui::BeginPopupModal("Message 1", NULL, ImGuiWindowFlags_AlwaysAutoResize))
            //                    {
            //                        ImGui::Text("Message 2");
            //                        ImGui::Separator();

            //                        static bool dont_ask_me_next_time = false;
            //                        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(0, 0));
            //                        ImGui::Checkbox("Don't ask me next time", &dont_ask_me_next_time);
            //                        ImGui::PopStyleVar();

            //                        if (ImGui::Button("OK", ImVec2(120, 0))) { ImGui::CloseCurrentPopup(); }
            //                        ImGui::SetItemDefaultFocus();
            //                        ImGui::SameLine();
            //                        if (ImGui::Button("Cancel", ImVec2(120, 0))) { ImGui::CloseCurrentPopup(); }
            //                        ImGui::EndPopup();
            //                    }
            //                }
            //                ImGui::EndGroup();
            //            }
            //            ImGui::EndChild();
            //        }
            //        break;
            //        }
            //    }
            //    ImGui::EndGroup();
            //}
            //ImGui::End();

            ImGui::Begin("Settings's size", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
            {
                ImGui::InputInt("sizeX", &sizeX);
                ImGui::InputInt("sizeY", &sizeY);
            }
            ImGui::End();

        }
        // Rendering
        ImGui::EndFrame();
        g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, false);
        g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
        g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
        D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_color.x * 255.0f), (int)(clear_color.y * 255.0f), (int)(clear_color.z * 255.0f), (int)(clear_color.w * 255.0f));
        g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 1.0f, 0);
        if (g_pd3dDevice->BeginScene() >= 0)
        {
            ImGui::Render();
            ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
            g_pd3dDevice->EndScene();
        }
        HRESULT result = g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

        // Handle loss of D3D9 device
        if (result == D3DERR_DEVICELOST && g_pd3dDevice->TestCooperativeLevel() == D3DERR_DEVICENOTRESET)
            ResetDevice();
    }

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();

    CleanupDeviceD3D();
    ::DestroyWindow(hwnd);
    ::UnregisterClass(wc.lpszClassName, wc.hInstance);

    return 0;
}
// Helper functions
bool CreateDeviceD3D(HWND hWnd)
{
    if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
        return false;

    // Create the D3DDevice
    ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
    g_d3dpp.Windowed = TRUE;
    g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    g_d3dpp.EnableAutoDepthStencil = TRUE;
    g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
    g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;           // Present with vsync
    //g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   // Present without vsync, maximum unthrottled framerate
    if (g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
        return false;

    return true;
}
void CleanupDeviceD3D()
{
    if (g_pd3dDevice) { g_pd3dDevice->Release(); g_pd3dDevice = NULL; }
    if (g_pD3D) { g_pD3D->Release(); g_pD3D = NULL; }
}
void ResetDevice()
{
    ImGui_ImplDX9_InvalidateDeviceObjects();
    HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
    if (hr == D3DERR_INVALIDCALL)
        IM_ASSERT(0);
    ImGui_ImplDX9_CreateDeviceObjects();
}
extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (ImGui_ImplWin32_WndProcHandler(hWnd, msg, wParam, lParam))
        return true;

    switch (msg)
    {
    case WM_SIZE:
        if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
        {
            g_d3dpp.BackBufferWidth = LOWORD(lParam);
            g_d3dpp.BackBufferHeight = HIWORD(lParam);
            ResetDevice();
        }
        return 0;
    case WM_SYSCOMMAND:
        if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
            return 0;
        break;
    case WM_DESTROY:
        ::PostQuitMessage(0);
        return 0;
    }
    return ::DefWindowProc(hWnd, msg, wParam, lParam);
}
