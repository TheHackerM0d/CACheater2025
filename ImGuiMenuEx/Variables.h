#include "Includes.h"
BOOL KillProcessByName(char* szProcessToKill)
{
    HANDLE hProcessSnap; HANDLE hProcess; PROCESSENTRY32 pe32; hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); if (hProcessSnap == INVALID_HANDLE_VALUE) { return(FALSE); }pe32.dwSize = sizeof(PROCESSENTRY32);
    if (!Process32First(hProcessSnap, &pe32)) { CloseHandle(hProcessSnap); return(FALSE); }
    do { if (!strcmp(pe32.szExeFile, szProcessToKill)) { hProcess = OpenProcess(PROCESS_TERMINATE, 0, pe32.th32ProcessID); TerminateProcess(hProcess, 0); CloseHandle(hProcess); } } while (Process32Next(hProcessSnap, &pe32));
    CloseHandle(hProcessSnap); return(TRUE);
}
D3DCOLOR FLOAT4TOD3DCOLOR(float Col[])
{
    ImU32 col32_no_alpha = ImGui::ColorConvertFloat4ToU32(ImVec4(Col[0], Col[1], Col[2], Col[3]));
    float a = (col32_no_alpha >> 24) & 255;
    float r = (col32_no_alpha >> 16) & 255;
    float g = (col32_no_alpha >> 8) & 255;
    float b = col32_no_alpha & 255;
    return D3DCOLOR_ARGB((int)a, (int)b, (int)g, (int)r);
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
void Hotkey(int* k)
{
    static bool waitingForKey = false;
    static int delayCounter = 0;

    if (!waitingForKey)
    {
        if (ImGui::Button(KeyNames[*k]))
        {
            waitingForKey = true;
            delayCounter = 0;
        }
    }
    else
    {
        ImGui::Button("<Press a key>");
        if (++delayCounter > 10)
        {
            for (int i = 0; i < 256; i++)
            {
                if (GetAsyncKeyState(i) & 0x8000)
                {
                    *k = i;
                    waitingForKey = false;
                    delayCounter = 0;
                    break;
                }
            }
        }
    }
}

bool ValidPointer(void* Pointer) { return !IsBadReadPtr(Pointer, 4) && Pointer; }
D3DXVECTOR3 ConvertPosition(INT* Object) { return *(D3DXVECTOR3*)(Object + 0x4); }

D3DXMATRIX* MatrixMultiply(D3DXMATRIX* pout, const D3DXMATRIX* pm1, const D3DXMATRIX* pm2)
{
    D3DXMATRIX out; int i, j; for (i = 0; i < 4; i++) { for (j = 0; j < 4; j++) { out.m[i][j] = pm1->m[i][0] * pm2->m[0][j] + pm1->m[i][1] * pm2->m[1][j] + pm1->m[i][2] * pm2->m[2][j] + pm1->m[i][3] * pm2->m[3][j]; } } *pout = out;
    return pout;
}
D3DXVECTOR3* Vec3Project(D3DXVECTOR3* pout, D3DXVECTOR3* pv, D3DVIEWPORT9* pviewport, D3DXMATRIX* pprojection, D3DXMATRIX* pview, D3DXMATRIX* pworld)
{
    D3DXMATRIX m; D3DXMATRIX* pm; D3DXVECTOR3 out; FLOAT norm;
    pm = &m;
    pm->m[0][1] = 0.0f; pm->m[0][2] = 0.0f; pm->m[0][3] = 0.0f;
    pm->m[1][0] = 0.0f; pm->m[1][2] = 0.0f; pm->m[1][3] = 0.0f;
    pm->m[2][0] = 0.0f;  pm->m[2][1] = 0.0f; pm->m[2][3] = 0.0f;
    pm->m[3][0] = 0.0f;  pm->m[3][1] = 0.0f; pm->m[3][2] = 0.0f;
    pm->m[0][0] = 1.0f; pm->m[1][1] = 1.0f;  pm->m[2][2] = 1.0f; pm->m[3][3] = 1.0f;
    if (pworld) MatrixMultiply(&m, &m, pworld); if (pview) MatrixMultiply(&m, &m, pview); if (pprojection) MatrixMultiply(&m, &m, pprojection);
    norm = pm->m[0][3] * pv->x + pm->m[1][3] * pv->y + pm->m[2][3] * pv->z + pm->m[3][3];
    out.x = (pm->m[0][0] * pv->x + pm->m[1][0] * pv->y + pm->m[2][0] * pv->z + pm->m[3][0]) / norm;
    out.y = (pm->m[0][1] * pv->x + pm->m[1][1] * pv->y + pm->m[2][1] * pv->z + pm->m[3][1]) / norm;
    out.z = (pm->m[0][2] * pv->x + pm->m[1][2] * pv->y + pm->m[2][2] * pv->z + pm->m[3][2]) / norm;
    *pout = out;
    if (pviewport)
    {
        pout->x = pviewport->X + (1.0f + pout->x) * pviewport->Width / 2.0f;
        pout->y = pviewport->Y + (1.0f - pout->y) * pviewport->Height / 2.0f;
        pout->z = pviewport->MinZ + pout->z * (pviewport->MaxZ - pviewport->MinZ);
    }
    return pout;
}
BOOL WorldToScreen(LPDIRECT3DDEVICE9 pDevice, D3DXVECTOR3 Pos, D3DXVECTOR3* pScreen)
{
    D3DVIEWPORT9 oViewport;
    D3DXVECTOR3 dvWorld(Pos.x, Pos.y, Pos.z);
    pDevice->GetViewport(&oViewport);
    cILTDrawPrim2* pDrawPrim = *(cILTDrawPrim2**)Logger::engine::Get_DrawPrimitive;
    D3DXVec3Project(pScreen, &dvWorld, &oViewport, &pDrawPrim->Projection, &pDrawPrim->View, &pDrawPrim->World);
    if (pScreen->z < 1) return TRUE;
    return FALSE;
}
bool WorldToScreens(D3DXVECTOR3* Pos, D3DXVECTOR3* Screen)
{
    cILTDrawPrim* pDrawPrim = *(cILTDrawPrim**)Logger::engine::Get_DrawPrimitive;
    Vec3Project(Screen, Pos, &pDrawPrim->ViewPort, &pDrawPrim->World[2], &pDrawPrim->World[1], &pDrawPrim->World[0]); return(Screen->z < 1.0f);
}
FLOAT CalculDistance(D3DXVECTOR3 Camera, D3DXVECTOR3 Player)
{
    return sqrt((Camera.x - Player.x) * (Camera.x - Player.x) + (Camera.y - Player.y) * (Camera.y - Player.y) + (Camera.z - Player.z) * (Camera.z - Player.z));
}

void DrawTextCentered(LPD3DXFONT font, int x, int y, D3DCOLOR color, LPDIRECT3DDEVICE9 pDevice, const char* fmt, ...)
{
    pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
    char buffer[256];
    va_list args;
    va_start(args, fmt);
    vsprintf_s(buffer, sizeof(buffer), fmt, args);
    va_end(args);

    RECT rect = { 0, 0, 1000, 100 };
    font->DrawTextA(nullptr, buffer, -1, &rect, DT_CALCRECT, 0);

    int width = rect.right - rect.left; int height = rect.bottom - rect.top;
    int centeredX = x - width / 2; int centeredY = y;

    RECT rectShadow = { centeredX + 1, centeredY + 1, centeredX + 1 + width, centeredY + 1 + height };
    RECT rectText = { centeredX,     centeredY,     centeredX + width,     centeredY + height };

    // Ombre noire
    font->DrawTextA(nullptr, buffer, -1, &rectShadow, DT_NOCLIP, D3DCOLOR_ARGB(255, 0, 0, 0));

    // Texte principal
    font->DrawTextA(nullptr, buffer, -1, &rectText, DT_NOCLIP, color);
    pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
}
VOID CustomDrawText(INT Type, LPD3DXFONT g_pFont, INT x, INT y, DWORD Color, DWORD Flags, CHAR* Text, ...)
{
    RECT rect;
    SetRect(&rect, x, y, x, y);
    RECT rect2;
    SetRect(&rect2, x + 1, y + 1, x + 1, y + 1);
    switch (Type)
    {
    case 0:
        g_pFont->DrawTextA(NULL, Text, -1, &rect, Flags, Color);
        break;

    case 1:
        g_pFont->DrawTextA(NULL, Text, -1, &rect2, Flags, 0xFF000000);
        g_pFont->DrawTextA(NULL, Text, -1, &rect, Flags, Color);
        break;
    }
}
VOID DrawLine(LONG Xa, LONG Ya, LONG Xb, LONG Yb, DWORD dwWidth, D3DCOLOR Color, LPDIRECT3DDEVICE9 pDevice)
{
    pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
    D3DXVECTOR2 vLine[2];
    pLine->SetAntialias(1); pLine->SetWidth(dwWidth); pLine->Begin();
    vLine[0][0] = Xa;
    vLine[0][1] = Ya;
    vLine[1][0] = Xb;
    vLine[1][1] = Yb;
    pLine->Draw(vLine, 2, Color); pLine->End();
    pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
}
void DrawESPBox(float x, float y, float width, float height, D3DCOLOR color, LPDIRECT3DDEVICE9 pDevice)
{
    pDevice->SetRenderState(D3DRS_ZENABLE, FALSE); 
    float thickness = 1.5f; 
    DrawLine(x, y, x + width, y, thickness, color, pDevice);             // Top
    DrawLine(x, y, x, y + height, thickness, color, pDevice);            // Left
    DrawLine(x + width, y, x + width, y + height, thickness, color, pDevice); // Right
    DrawLine(x, y + height, x + width, y + height, thickness, color, pDevice); // Bottom
    pDevice->SetRenderState(D3DRS_ZENABLE, TRUE); 
}
VOID FillRGB(INT x, INT y, INT w, INT h, D3DCOLOR Color, LPDIRECT3DDEVICE9 pDevice) { D3DRECT rec = { x, y, x + w, y + h }; pDevice->Clear(1, &rec, D3DCLEAR_TARGET, Color, 0, 0); }
VOID DrawHealthBars(D3DXVECTOR3 Head, D3DXVECTOR3 Foot, WORD Health, LPDIRECT3DDEVICE9 pDevice)
{
    pDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
    DWORD dwColor;

    D3DXVECTOR3 Box = Head - Foot;
    if (Box.y < 0)
        Box.y *= -1;

    int BoxWidth = (int)Box.y / 2;
    int DrawX = (int)Head.x - (BoxWidth / 2);
    int DrawY = (int)Head.y;

    DWORD dwDrawWidth = Health * (Foot.y - Head.y) / 100;

    if (Health > 100)
        Health = 100;

    if (Health > 75)
        dwColor = 0xFF00FF00;
    else if (Health > 40)
        dwColor = 0xFFFF9B00;
    else
        dwColor = 0xFFFF0000;

    FillRGB(DrawX - 6, DrawY - 1, 1, dwDrawWidth, dwColor, pDevice);
    pDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
}
void pMemoria(LPVOID andress, LPVOID ByteMemcpy, INT Len)
{
    DWORD dwBack;
    VirtualProtect((LPVOID)andress, Len, 0x40, &dwBack);
    memcpy((LPVOID)andress, ByteMemcpy, Len);
    VirtualProtect((LPVOID)andress, Len, dwBack, &dwBack);
}
VOID DrawBorder(INT x, INT y, INT w, INT h, INT px, D3DCOLOR BorderColor, LPDIRECT3DDEVICE9 pDevice)
{
    FillRGB(x, (y + h - px), w, px, BorderColor, pDevice);
    FillRGB(x, y, px, h, BorderColor, pDevice);
    FillRGB(x, y, w, px, BorderColor, pDevice);
    FillRGB(x + w - px, y, px, h, BorderColor, pDevice);
}
VOID D3D_DrawBox(INT x, INT y, INT w, INT h, INT px, DWORD Color, DWORD Border, LPDIRECT3DDEVICE9 pDevice)
{
    FillRGB(x, y, w, h, Color, pDevice); DrawBorder(x, y, w, h, px, Border, pDevice);
}
void PrintText(LPD3DXFONT pFont, INT x, INT y, DWORD Flags, DWORD Color, CHAR* text, ...)
{
    RECT rec;
    SetRect(&rec, x, y, x, y);
    CHAR logbuf[512] = { 0 };
    va_list va_alist;
    va_start(va_alist, text);
    vsnprintf(logbuf + strlen(logbuf), sizeof(logbuf) - strlen(logbuf), text, va_alist);
    va_end(va_alist);
    pFont->DrawTextA(NULL, logbuf, -1, &rec, Flags, Color);
}
void CleanTempFolder()
{
    wchar_t tempPath[MAX_PATH]; DWORD pathLen = GetTempPathW(MAX_PATH, tempPath); if (pathLen == 0 || pathLen > MAX_PATH) return;
    std::wstring tempDir = tempPath;
    for (const auto& entry : std::filesystem::directory_iterator(tempDir))
    {
        std::error_code ec;
        if (entry.is_directory()) { std::filesystem::remove_all(entry.path(), ec); }
        else { std::filesystem::remove(entry.path(), ec); }
    }
}