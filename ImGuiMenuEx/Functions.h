#include "Aimbot.h"
void VisualFunction()
{
	if (cheat::visual::NxChams) { Console(XorStr<0xB2, 20, 0x2BB73623>("\x99\xE0\xDF\xD0\xDA\xFA\xD7\xDD\xDF\xD7\xEF\xC9\xDB\xD1\xA3\xA8\xAE\xE3\xF5" + 0x2BB73623).s); }
	else { Console(XorStr<0x40, 20, 0x132C35CC>("\x6B\x12\x29\x26\x28\x08\x29\x23\x2D\x25\x19\x3F\x29\x23\x2D\x26\x3C\x71\x62" + 0x132C35CC).s); }
	if (cheat::visual::NoFog) { Console(XorStr<0x06, 13, 0x91055EF8>("\x2D\x41\x67\x6E\x4F\x65\x6D\x6F\x62\x6A\x30\x21" + 0x91055EF8).s); }
	else { Console(XorStr<0x9D, 13, 0x246D76B0>("\xB6\xD8\xF0\xC7\xE4\xCC\xC2\xC6\xC9\xC3\x87\x99" + 0x246D76B0).s); }
	if (cheat::visual::NoSmoke) { Console(XorStr<0x6A, 16, 0xF41A225E>("\x2E\x19\x0D\x1A\x3E\x0E\x02\x05\x1B\x10\x18\x10\x05\x57\x48" + 0xF41A225E).s); }
	else { Console(XorStr<0x70, 16, 0x9867DB50>("\x34\x03\x13\x04\x24\x14\x04\x03\x11\x1A\x16\x1E\x0F\x5D\x4F" + 0x9867DB50).s); }
	if (cheat::visual::ScreenGlow) { Console(XorStr<0x2D, 20, 0xB27E5469>("\x06\x7D\x4C\x42\x54\x57\x5D\x73\x59\x59\x40\x7D\x57\x5B\x59\x50\x58\x1E\x0E" + 0xB27E5469).s); }
	else { Console(XorStr<0x01, 20, 0xBF80E04E>("\x2A\x51\x60\x76\x60\x63\x69\x4F\x65\x65\x7C\x49\x63\x6F\x6D\x7C\x74\x32\x23" + 0xBF80E04E).s); }
	if (cheat::visual::RemoveTexture) { Console(XorStr<0x31, 17, 0xF8E0EC98>("\x1A\x66\x56\x4C\x41\x43\x45\x5D\x74\x55\x5F\x59\x51\x4D\x1F\x70" + 0xF8E0EC98).s); }
	else { Console(XorStr<0x62, 17, 0xDC5DCFA5>("\x49\x37\x01\x1D\x12\x12\x1A\x0C\x27\x04\x08\x08\x02\x1C\x50\x40" + 0xDC5DCFA5).s); }
	if (cheat::visual::FullBrights) { Console(XorStr<0x5C, 14, 0xD3C690B9>("\x77\x1B\x2B\x33\x0C\x23\x10\x0A\x03\x0D\x12\x47\x59" + 0xD3C690B9).s); }
	else { Console(XorStr<0x2C, 14, 0xBC87C053>("\x07\x6B\x5B\x43\x5C\x73\x40\x5A\x53\x5D\x42\x17\x08" + 0xBC87C053).s); }
	if (cheat::visual::WorldTree) { Console(XorStr<0x0E, 16, 0x8617CC70>("\x4A\x7D\x71\x66\x45\x7C\x66\x79\x72\x43\x6A\x7C\x7F\x3B\x2D" + 0x8617CC70).s); }
	else { Console(XorStr<0x08, 16, 0xE29BC137>("\x4C\x7B\x6B\x7C\x5B\x62\x7C\x63\x74\x45\x60\x76\x71\x35\x26" + 0xE29BC137).s); }
	if (cheat::visual::WorldBox) { Console(XorStr<0x14, 19, 0x3E72A190>("\x50\x67\x77\x60\x4A\x7C\x74\x7F\x79\x6F\x5C\x73\x4F\x42\x49\x50\x04\x14" + 0x3E72A190).s); }
	else { Console(XorStr<0x4B, 19, 0x2BFD3DE2>("\x0F\x3E\x2C\x39\x1D\x35\x3F\x36\x36\x26\x17\x3A\x38\x3B\x32\x29\x7B\x6C" + 0x2BFD3DE2).s); }
}
void WeaponFunction()
{
	cWeaponmgr* Weapons = *(cWeaponmgr**)Logger::cshell::Get_WeaponMGR;	if (!Weapons) return;

	if (cheat::weapon::EDistance) *(float*)Logger::cshell::Get_LongDistance = FLT_MAX; else *(float*)Logger::cshell::Get_LongDistance = 100.0f;
	if (!cheat::weapon::Backups::Weapons::DefaultWepMgrEffect)
	{
		for (int i = 0; i < Weapons->m_nNumWeapons; i++)
		{
			WEAPONs* weapon = Weapons->m_pWeaponList[i];
			if (!weapon) continue; BackupWeaponStats(weapon, i);
		}
		cheat::weapon::Backups::Weapons::DefaultWepMgrEffect = true;
	}
	for (int i = 0; i < Weapons->m_nNumWeapons; i++)
	{
		WEAPONs* weapon = Weapons->m_pWeaponList[i]; if (!weapon) continue;
		ApplyNoRecoil(weapon, i);
		ApplyNoSpread(weapon, i);
		ApplyZoomTime(weapon, i);
		ApplyMovePenalty(weapon, i);
		if (cheat::weapon::BackCam) weapon->fBaseCamBackJitter = 0;
	}
	if (!m_pPlayerMgr) return;
	if (cheat::weapon::RemoveAnimation) m_pPlayerMgr->GetCurrentWeapon()->m_nSelectAni = -1;
}
void PlayerFunction()
{
	if (cheat::player::Fly && GetAsyncKeyState(VK_SPACE)) { m_pPlayerMgr->m_pMoveMgr->m_fGravity = 1100.0f; } else { m_pPlayerMgr->m_pMoveMgr->m_fGravity = -1100.0f; }
}
void Functions(LPDIRECT3DDEVICE9 pDevice)
{
	pDevice->GetViewport(&ViewPort);
	if (pInterfaceMgr->InGame())
	{
		__asm CALL[VisualFunction];
		__asm CALL[PlayerFunction];
		__asm CALL[WeaponFunction];
		ESP_Functions(pDevice);
		UseAimbot();
	}
}
typedef void(__thiscall* tShowRadioMsg)(CHUDXMLRadioMsg* pThis, eKindRadioMsg eKind); tShowRadioMsg oShowRadioMsg;
void __fastcall Hook_CHUDXMLRadioMsgShowRadioMsg(CHUDXMLRadioMsg* pThis, void* /*edx*/, eKindRadioMsg eKind)
{
	if (cheat::special::RadioSpam) { pThis->m_nLastCommandTick = 0; oShowRadioMsg(pThis, eKind); }
	else { oShowRadioMsg(pThis, eKind); }
}
void InstallCHUDXMLRadioMsgShowRadioMsg()
{
	uintptr_t targetAddr = PatternScan(0, ___("A1 ? ? ? ? 83 78 38 01 56"));
	if (MH_CreateHook((LPVOID)targetAddr, &Hook_CHUDXMLRadioMsgShowRadioMsg, (LPVOID*)&oShowRadioMsg) != MH_OK) { MessageBoxA(0, ___("[Error] Failed to create hook for CHUDXMLRadioMsg::ShowRadioMsg"), "Information", MB_ICONWARNING); }
	if (MH_EnableHook((LPVOID)targetAddr) != MH_OK) { MessageBoxA(0, ___("[Error] Failed to enable hook for CHUDXMLRadioMsg::ShowRadioMsg"), "Information", MB_ICONWARNING); }
}