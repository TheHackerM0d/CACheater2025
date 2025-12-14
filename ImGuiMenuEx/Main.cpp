#pragma warning(disable : 4244 4996 4477)  // possible data loss
#include "dx/dx9.h"
#include "Functions.h"
c_gui gui;
//==========================================================================================================================//
//                                                  Menu Render                                                              //
//==========================================================================================================================//
WNDPROC p_window_proc = nullptr; extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK wnd_proc(const HWND hwnd, const UINT u_msg, const WPARAM w_param, const LPARAM l_param)
{
    if (ImGui_ImplWin32_WndProcHandler(hwnd, u_msg, w_param, l_param) && GetAsyncKeyState(VK_INSERT) & 1) { return 1l;  }
    return CallWindowProc(p_window_proc, hwnd, u_msg, w_param, l_param);
}

void MenuFunctionMethod(LPDIRECT3DDEVICE9 pDevice)
{
    if (ModMenu::LoggingAddress)
    {
        if (processName == ___(L"Engine.exe"))
        {
            Logger::engine::Get_LTClientEXE     = PatternScan(1, Engine_LTClientEXE); 
            Logger::engine::Get_DrawPrimitive   = PatternScanAdder(1, Engine_DrawPrimitive, 0x1);
        }
        if (processName == ___(L"Engine2.exe"))
        {
            Logger::engine::Get_LTClientEXE     = PatternScan(2, Engine_LTClientEXE);
            Logger::engine::Get_DrawPrimitive   = PatternScanAdder(2, Engine_DrawPrimitive, 0x1); 
        }

        Logger::cshell::Get_GameClientShell     = PatternScanAdder(0, Cshell_GameClientShell, 0x1);
        Logger::cshell::Get_PlayerByIndex       = PatternScan(0, Cshell_PlayerByIndex);
        Logger::cshell::Get_LocalPlayer         = PatternScan(0, Cshell_LocalPlayer);
        Logger::cshell::Get_ClientInfoMgr       = PatternScanAdder(0, Cshell_ClientInfoMgr, 0x2);

        Logger::cshell::Get_WeaponMGR           = PatternScanAdder(0, Cshell_WeaponMGR, 0x2);
        Logger::cshell::Get_LongDistance        = PatternScanAdder(0, Cshell_LongDistance, 0x2);
        Logger::cshell::Get_cInterfaceMgr       = PatternScanAdder(0, Cshell_InterfaceMgr, 0x1); 
        Logger::cshell::Get_BuildGuid           = PatternScanAdder(0, Cshell_BuildGuid, 0x1);
        Logger::cshell::Get_LTCSBase            = Logger::cshell::Get_BuildGuid + 0x0010;
        Logger::cshell::Get_LTClientDLL         = Logger::cshell::Get_BuildGuid + 0x0028;
        InstallCHUDXMLRadioMsgShowRadioMsg();
        InstallCModelButeMgrGetSkeletonNodeHitRadius();
        InstallModelButeReaderToMessage(); 
        ModMenu::LoggingAddress = false;
    }
    CheckPointer(); Functions(pDevice);
    if (pFont == 0) D3DXCreateFont(pDevice, 14, 0, 400, 1, 0, 1, 0, 4, 0 | (0 << 1), FontMenu, &pFont);
    if (pLine == 0) D3DXCreateLine(pDevice, &pLine);
}
void __stdcall main_render(IDirect3DDevice9* pDevice)
{
    MenuFunctionMethod(pDevice); static bool do_init = true;
    if (do_init)
    {
        const auto window = GetForegroundWindow();
        DWORD pid;
        if (!window || !GetWindowThreadProcessId(window, &pid) || pid != GetCurrentProcessId()) return;  do_init = false;
        p_window_proc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(window, GWLP_WNDPROC, LONG_PTR(wnd_proc)));
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui_ImplWin32_Init(window);
        ImGui_ImplDX9_Init(pDevice);
    }
    ImGui_ImplDX9_NewFrame(); ImGui_ImplWin32_NewFrame(); ImGui::NewFrame();
    {
        static bool ShowMenu = true;
        static int VK_List = 45;
        if (GetAsyncKeyState(VK_List) & 1) { ShowMenu = !ShowMenu; }
        if (ShowMenu)
        {
            std::stringstream ss; ss << ___("Combat Arms:Cheater[FREE]") << ___("Made by TheHacker/Mod"); std::string windowTitle = ss.str();
            ImGui::Begin(windowTitle.c_str(), nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
            {
                static int X = 250; static int Y = 250;
                ImGui::SetWindowSize(ImVec2(670, 400));
                auto p = ImGui::GetWindowPos();  auto __draw = ImGui::GetWindowDrawList(); static int tab = 0;
                __draw->AddRectFilled(ImVec2(p.x + 0, p.y + 30), ImVec2(p.x + 150, p.y + 395), ImColor(31, 31, 41, 255));
                ImGui::SetCursorPos(ImVec2(0, 30));
                ImGui::BeginGroup();
                {
                    if (gui.tab(___("Special"), tab == 0, ImVec2(150, 25))) tab = 0;
                    if (gui.tab(___("Visual"), tab == 1, ImVec2(150, 25))) tab = 1;
                    if (gui.tab(___("Misc"), tab == 2, ImVec2(150, 25))) tab = 2;
                    if (gui.tab(___("Modification"), tab == 3, ImVec2(150, 25))) tab = 3;
                }
                ImGui::EndGroup();
                ImGui::SetCursorPos(ImVec2(156, 30));
                ImGui::BeginGroup();
                {
                    switch (tab)
                    {
                        /*Special*/      case 0:
                        {
                            ImGui::BeginChild(___("Generals"), ImVec2(250, 200), true);
                            {
                                ImGui::BeginGroup();
                                {
                                    ImGui::Checkbox(AIMBOT_Activation, &cheat::aimbot::Activation); ImGui::SameLine(); Hotkey(&cheat::aimbot::AimKey);
                                    ImGui::SliderFloat(AIMBOT_SmoothSpeed, &cheat::aimbot::SmoothMin, 0.4, 1, ___("%.2f"));
                                    ImGui::SliderInt(AIMBOT_AimFOV, &cheat::aimbot::AimFov, 1, 30, ___("%.2f"));
                                    ImGui::Combo(AIMBOT_AimBone, &cheat::aimbot::AimBone, ___("Head\0Neck\0Chest\0Dick\00"));
                                    ImGui::Text(___("------------Ghost Aim-------------"));
                                    ImGui::Checkbox(GAIM_Activation, &cheat::aimbot::Ghost::Radius::Activation);

                                }
                                ImGui::EndGroup();
                            }
                            ImGui::EndChild();
                            ImGui::SameLine();
                            ImGui::BeginChild(ESP_MENU_Main, ImVec2(250, 200), true);
                            {
                                ImGui::BeginGroup();
                                {
                                    if (ImGui::BeginTabBar(___("ESP's"), ImGuiTabBarFlags_None))
                                    {
                                        if (ImGui::BeginTabItem(ESP_TITLE_Enemy))
                                        {
                                            ImGui::Checkbox(ESP_ENEMY_Activation, &cheat::esp::Ennemy::Activation);
                                            ImGui::Checkbox(ESP_ENEMY_Line, &cheat::esp::Ennemy::Lines);
                                            ImGui::Checkbox(ESP_ENEMY_Box, &cheat::esp::Ennemy::Box);
                                            ImGui::Checkbox(ESP_ENEMY_Health, &cheat::esp::Ennemy::Health);
                                            ImGui::EndTabItem();
                                        }
                                        if (ImGui::BeginTabItem(ESP_TITLE_Allies))
                                        {
                                            ImGui::Checkbox(ESP_ALLY_Activation, &cheat::esp::Allies::Activation);
                                            ImGui::Checkbox(ESP_ALLY_Line, &cheat::esp::Allies::Lines);
                                            ImGui::Checkbox(ESP_ALLY_Box, &cheat::esp::Allies::Box);
                                            ImGui::Checkbox(ESP_ALLY_Health, &cheat::esp::Allies::Health);
                                            ImGui::EndTabItem();
                                        }
                                        ImGui::EndTabBar();
                                    }
                                }
                                ImGui::EndGroup();
                            }
                            ImGui::EndChild();

                            break;
                        }
                        /*Visual*/       case 1:
                        {
                            ImGui::BeginChild(___("Engine"), ImVec2(250, 365), true);
                            {
                                ImGui::BeginGroup();
                                {
                                    ImGui::Checkbox(WEAPON_BulletTracer, &cheat::weapon::BulletTracer);
                                    ImGui::Checkbox(NEXON_Chams, &cheat::visual::NxChams);
                                    ImGui::Checkbox(NEXON_REMOVE_Fog, &cheat::visual::NoFog);
                                    ImGui::Checkbox(NEXON_REMOVE_Smoke, &cheat::visual::NoSmoke);
                                    ImGui::Checkbox(NEXON_Glow, &cheat::visual::ScreenGlow);
                                    ImGui::Checkbox(NEXON_Texture, &cheat::visual::RemoveTexture);
                                    ImGui::Checkbox(NEXON_Bright, &cheat::visual::FullBrights);
                                    ImGui::Checkbox(NEXON_WorldBox, &cheat::visual::WorldBox);
                                    ImGui::Checkbox(NEXON_WorldTree, &cheat::visual::WorldTree);
                                }
                                ImGui::EndGroup();
                            }
                            ImGui::EndChild();
                            break;
                        }
                        /*Misc*/         case 2:
                        {
                            ImGui::BeginChild(PLAYER_TITLE_Movement, ImVec2(250, 180), true);
                            {
                                ImGui::BeginGroup();
                                {
                                    ImGui::Checkbox(PLAYER_Fly_Activation, &cheat::player::Fly);
                                    ImGui::Checkbox(PLAYER_AntiKnockback, &cheat::player::knockback);
                                    ImGui::Checkbox(SPOOF_Character, &cheat::spoofer::cosmetic::Character);
                                    if (cheat::spoofer::cosmetic::Character)
                                        ImGui::InputInt(SPOOF_Characters, &cheat::spoofer::cosmetic::CharacterID);

                                    ImGui::Checkbox(SPOOF_Helmet, &cheat::spoofer::cosmetic::Helmet);
                                    if (cheat::spoofer::cosmetic::Helmet)
                                        ImGui::InputInt(SPOOF_Helmets, &cheat::spoofer::cosmetic::HelmetID);
                                }
                                ImGui::EndGroup();
                            }
                            ImGui::EndChild();
                            ImGui::SameLine();
                            ImGui::BeginChild(WEAPON_TITLE_Basics, ImVec2(250, 180), true);
                            {
                                ImGui::BeginGroup();
                                {
                                    ImGui::Checkbox(WEAPON_Spread, &cheat::weapon::NoSpread); ImGui::SameLine(125); ImGui::Checkbox(WEAPON_Recoil, &cheat::weapon::NoRecoil);
                                    ImGui::Checkbox(WEAPON_Reload, &cheat::weapon::NoReload); ImGui::SameLine(125); ImGui::Checkbox(WEAPON_FastZoom, &cheat::weapon::ZoomTime);
                                    ImGui::Checkbox(WEAPON_Distance, &cheat::weapon::EDistance); ImGui::SameLine(125); ImGui::Checkbox(WEAPON_FastSwitch, &cheat::weapon::RemoveAnimation);
                                    ImGui::Checkbox(WEAPON_RemoveWeight, &cheat::weapon::MovePenalty); if (cheat::weapon::MovePenalty) { ImGui::SameLine(); ImGui::SliderInt(WEAPON_RemoveWeightValue, &cheat::weapon::MovePenaltys, 0, 10, ___("Value (-) %d")); cheat::weapon::MovePenaltys = std::clamp(cheat::weapon::MovePenaltys, 0, 10); }
                                }
                                ImGui::EndGroup();
                            }
                            ImGui::EndChild();
                            ImGui::SetCursorPos(ImVec2(156, 215));
                            ImGui::BeginChild(___("Special Misc"), ImVec2(250, 145), true);
                            {
                                ImGui::BeginGroup();
                                {
                                    ImGui::Checkbox(SPECIAL_RadioCooldown, &cheat::special::RadioSpam);
                                }
                                ImGui::EndGroup();
                            }
                            ImGui::EndChild();
                            break;
                        }
                        /*Modification*/ case 3:
                        {
                            ImGui::BeginChild(___("Menu"), ImVec2(250, 100), true);
                            {
                                ImGui::BeginGroup();
                                {
                                    ImGui::Text(___("Key Menu")); SameLine(); Hotkey(&VK_List);
                                    if (ImGui::Button("Close Game"))
                                    {
                                        KillProcessByName(___("GameMon.des"));
                                        KillProcessByName(___("GameMon64.des"));
                                        KillProcessByName(___("GameGuard.des"));
                                        KillProcessByName(___("Voicechat.exe"));
                                        exit(0);
                                    }
                                    if (ImGui::Button("Close VoiceChat"))
                                    {
                                        KillProcessByName(___("Voicechat.exe"));
                                    }
                                }
                                ImGui::EndGroup();
                            }
                            ImGui::EndChild(); ImGui::SameLine(0, 8);
                            ImGui::BeginChild(___("Design"), ImVec2(250, 153));
                            {
                                ImGui::BeginGroup();
                                {
                                    ImGui::Combo(___("Theme"), &ModMenu::MenuDesign::Theme, ___("Dark\0Classic\0Light\0Futuristic\00"));
                                    if (ModMenu::MenuDesign::Theme == 0) { ImGui::StyleColorsDark(); }
                                    else if (ModMenu::MenuDesign::Theme == 1) { ImGui::StyleColorsClassic(); }
                                    else if (ModMenu::MenuDesign::Theme == 2) { ImGui::StyleColorsLight(); }
                                    else if (ModMenu::MenuDesign::Theme == 3) { ImGui::StyleColorsFuturistic(); }
                                }
                                ImGui::EndGroup();
                            }
                            ImGui::EndChild();
                            break;
                        }
                    }
                }
                ImGui::EndGroup();
            }
            ImGui::End();
        }
    }
    ImGui::EndFrame(); ImGui::Render(); ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}
void do_thread() { dx9::set_frame_render(reinterpret_cast<void*>(main_render)); }
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        CleanTempFolder(); MH_Initialize();
        CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(do_thread), nullptr, 0, nullptr);
    }
    else if (ul_reason_for_call == DLL_PROCESS_DETACH) { MH_Uninitialize(); }
    return TRUE;
}