class cModelButeReader
{
public:
	int m_eModelId;
	int m_eModelFigureType;
	int m_eHeadPieceId;
	int m_eFacePieceId;
	int m_nLevel;
	int m_nClanMarkId;
	int m_nTeamMarkId;
	int m_nBackPack;
	int m_nGoggle;
	bool m_bGoggleDefault;
	char m_nCamoIndex;
	char m_szClanEmblem[128];
	char m_szClanBackGround[128];
	int m_nClanEmblemID;
	int m_nClanBackGroundID;
	int m_nOveridableModel;
	int m_nCosmeticCharacter;
	int m_nCosmeticHelmet;
	int m_nCosmeticGoggle;
	int m_nCosmeticVest;
	int m_nCosmeticBackPack;
	char m_nModelColor;
	char m_nHelmetColor;
	char m_nGoggleColor;
	char m_nBackpackColor;
};


class CCharModelInfoMgr;
class Grade
{
public:
	unsigned int nLeadClass; //0x0000
	unsigned int nClass; //0x0004
}; //Size: 0x0008
struct /*VFT*/ CCharModelInfoMgr_vtbl
{
	void(__thiscall* CCharModelInfoMgrs)(CCharModelInfoMgr* pthis);
};

class CCharModelInfoMgr
{
public:
	CCharModelInfoMgr_vtbl* __vtbl;//0x0000
	cModelButeReader ModelButeReader;//0x0004
	__int32 m_eModelFigureType; //0x0150 enum ModelFigureType
	__int32 m_eModelId; //0x0154 enum ModelId
	__int32 m_eHeadPieceId; //0x0158 enum HeadPieceId
	__int32 m_eFacePieceId; //0x015C enum FacePieceId
	__int32 m_eDefaultFaceId; //0x0160 enum FacePieceId
	Grade m_Grade; //0x0164
	__int32 m_nSpecialMarkId; //0x016C
	__int32 m_nClanMarkId; //0x0170
	__int32 m_nTeam; //0x0174
	__int32 m_nBackPackId; //0x0178
	__int32 m_nGoggleId; //0x017C
	__int32 m_bGoggleTakeOff; //0x0180
	__int32 m_nBranchUniform; //0x0184
	__int32 m_nBranchHelmet; //0x0188
	__int32 m_nMilitaryUniform; //0x018C
	__int32 m_nFaceId; //0x0190
	__int32 m_nMercenaryID; //0x0194
	__int32 m_nCosmeticCharacter; //0x0198
	__int32 m_nCosmeticHelmet; //0x019C
	__int32 m_nCosmeticGoggle; //0x01A0
	__int32 m_nCosmeticVest; //0x01A4
	__int32 m_nCosmeticBackPack; //0x01A8
	__int32 m_nModelColor; //0x01AC
	__int32 m_nHelmetColor; //0x01B0
	__int32 m_nGoggleColor; //0x01B4
	__int32 m_nBackpackColor; //0x01B8
	__int32 m_nDashGauge; //0x01BC
	__int32 m_nDashGaugeRec; //0x01C0
	__int32 m_nDashMaxStamina; //0x01C4
	float m_fMaxVelocity; //0x01C8
	char m_szClanEmblem[128]; //0x01CC
	char m_szClanBackGround[128]; //0x024C
	__int32 m_nClanEmblemID; //0x02CC
	__int32 m_nClanBackGroundID; //0x02D0
	__int32 m_nOveridableModel; //0x02D4
}; //Size: 0x02D8

namespace Spoofer
{
	namespace nModelButeReader
	{
		namespace Cosmetic
		{
			typedef void(__thiscall* vToMessage)(cModelButeReader*, void*); vToMessage	Cos_vToMessage;
			void __fastcall ToMessage(cModelButeReader* pThis, DWORD ECX, void* p_msg);
		}
	}
}


//Cosmetic Hook Edition
void __fastcall Spoofer::nModelButeReader::Cosmetic::ToMessage(cModelButeReader* pThis, DWORD ECX, void* p_msg)
{
	if (!cheat::spoofer::cosmetic::Backup::DefaultCharacterMode)
	{
		if (pThis)
		{
			cheat::spoofer::cosmetic::Backup::DefaultCharacter[1] = pThis->m_nCosmeticHelmet;
			cheat::spoofer::cosmetic::Backup::DefaultCharacter[4] = pThis->m_nCosmeticVest;
		}
		cheat::spoofer::cosmetic::Backup::DefaultCharacterMode = true;
	}
	if (pThis)
	{
		if (cheat::spoofer::cosmetic::Helmet) { pThis->m_nCosmeticHelmet = cheat::spoofer::cosmetic::HelmetID; }
		else { pThis->m_nCosmeticHelmet = cheat::spoofer::cosmetic::Backup::DefaultCharacter[1]; }

		if (cheat::spoofer::cosmetic::Character) { pThis->m_nCosmeticVest = cheat::spoofer::cosmetic::CharacterID; }
		else { pThis->m_nCosmeticVest = cheat::spoofer::cosmetic::Backup::DefaultCharacter[4]; }
	}
	return Cos_vToMessage(pThis, p_msg);
}
void InstallModelButeReaderToMessage()
{
	uintptr_t targetAddr = PatternScan(0, ___("56 8B 74 24 08 8B 06 8B 90 80 00 00 00"));
	if (MH_CreateHook((LPVOID)targetAddr, &Spoofer::nModelButeReader::Cosmetic::ToMessage, (LPVOID*)&Spoofer::nModelButeReader::Cosmetic::Cos_vToMessage) != MH_OK) { MessageBoxA(0,___("[Error] Failed to create hook for ModelButeReader::ToMessage"),"Information", MB_ICONWARNING); }
	if (MH_EnableHook((LPVOID)targetAddr) != MH_OK) { MessageBoxA(0, ___("[Error] Failed to enable hook for ModelButeReader::ToMessage"), "Information", MB_ICONWARNING); }
}