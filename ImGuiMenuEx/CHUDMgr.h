namespace cheat
{
	namespace HUDCrosshair
	{
		namespace Backup
		{
			bool bDefaultEffect = false;
			float DefaultValue[20];
		}
		bool ShowRangeOfTarget = false;
		bool Enable_Target_HP = false;
		bool Enable_Target_FriendlyIndicator = false;


		bool DamageHUD = false;
		int iDamageHUD = false;

		bool ShowHUD = false;
		int iShowHUD = false;

		bool CrosshairGapMin = false;
		float fCrosshairGapMin = 0;

		bool CrosshairGapRange = false;
		float fCrosshairGapRange = 0;

		bool CrosshairBarMin = false;
		float fCrosshairBarMin = 0;

		bool CrosshairBarRange = false;
		float fCrosshairBarRange = 0;
	}
}


class CHUDMgr;
struct /*VFT*/ CHUDMgr_vtbl
{
	unsigned int(__thiscall* Init)(CHUDMgr* pthis);
	void(__thiscall* Term)(CHUDMgr* pthis);
	void(__thiscall* Render)(CHUDMgr* pthis);
	void(__thiscall* Update)(CHUDMgr* pthis);
	void(__thiscall* QueueUpdate)(CHUDMgr* pthis, unsigned int);
	unsigned int(__thiscall* QueryUpdateFlags)(CHUDMgr* pthis);
	void(__thiscall* ScreenDimsChanged)(CHUDMgr* pthis);
	void(__thiscall* NextLayout)(CHUDMgr* pthis);
	void(__thiscall* PrevLayout)(CHUDMgr* pthis);
	void(__thiscall* UpdateLayout)(CHUDMgr* pthis);
	void(__thiscall* Show)(CHUDMgr* pthis, unsigned int);
	unsigned int(__thiscall* IsShown)(CHUDMgr* pthis);
	void(__thiscall* ShowHUD)(CHUDMgr* pthis, unsigned int);
	unsigned int(__thiscall* IsShowHUD)(CHUDMgr* pthis);
	void(__thiscall* ShowHUDByServerMsg)(CHUDMgr* pthis, bool);
	void(__thiscall* SetRenderLevel)(CHUDMgr* pthis, eHUDRenderLevel);
	eHUDRenderLevel(__thiscall* GetRenderLevel)(CHUDMgr* pthis);
	unsigned int(__thiscall* OnMessage)(CHUDMgr* pthis, char, ILTMessage_Read*);
};
class CHUDItem;
struct /*VFT*/ CHUDItem_vtbl
{
	void(__thiscall * CHUDItem1)(CHUDItem* pthis);
	unsigned int(__thiscall* Init)(CHUDItem* pthis);
	void(__thiscall* Term)(CHUDItem* pthis);
	void(__thiscall* Render)(CHUDItem* pthis);
	void(__thiscall* Update)(CHUDItem* pthis);
	void(__thiscall* UpdateLayout)(CHUDItem* pthis);
	void(__thiscall* ScreenDimsChanged)(CHUDItem* pthis);
	unsigned int(__thiscall* GetUpdateFlags)(CHUDItem* pthis);
	eHUDRenderLevel(__thiscall* GetRenderLevel)(CHUDItem* pthis);
	bool(__thiscall* ShouldInitialize)(CHUDItem* pthis);
};

class CHUDItem
{
public:
	CHUDItem_vtbl* __vftable /*VFT*/;
	unsigned int m_UpdateFlags;
	eHUDRenderLevel m_eLevel;
	unsigned int m_bFirstUpdate;
};
class CHUDMgr
{
public:
	CHUDMgr_vtbl* __vftable; //0x0000
	__int32 m_nCurrentLayout; //0x0004
	__int32 m_bVisible; //0x0008
	bool m_bShowHUD; //0x000C
	bool m_bShowHUDByServerMsg; //0x000D
private:
	char pad_000E[2]; //0x000E
public:
	uint32_t m_UpdateFlags; //0x0010
	eHUDRenderLevel m_eLevel; //0x0014 enum eHUDRenderLevel
	class CHUDPaused* m_Paused; //0x0018
	std::vector<CHUDItem*, std::allocator<CHUDItem*> > m_itemArray;
	//std::vector<CHUDXMLBase*, std::allocator<CHUDXMLBase*> > m_HUDArray;
}; //Size: 0x001C
class stBotBase
{
public:
	unsigned int dwIndex;
	const char* sBrain;
	const char* sGoalSet;
	const char* sGuardGoalSet;
	const char* sTemplate;
	const char* sBotTemplate;
};
class stBotProfile
{
public:
	unsigned int dwIndex;
	unsigned int dwBotBaseIndex;
	std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > sNickName;
	std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > sClanName;
	unsigned int dwRank;
	unsigned int dwClanMarkEmblem;
	unsigned int dwClanMarkBackground;
	unsigned int dwNationIndex;
	unsigned int dwBaseModelID;
	float fKDR;
	float fNextChatTime;
	int nItemInfoIndexList;
};
class stBotInfo
{
public:
	stBotBase* pBotBase;
	stBotProfile* pBotProfile;
	unsigned int eModelID;
	unsigned int eFaceID;
	unsigned int eBackpack;
	unsigned int eHeadID;
	unsigned int eGoggleID;
	unsigned int dwWeaponID[6];
};
class CBotInfoMgr;
class /*VFT*/ CBotInfoMgr_vtbl
{
public:
	void(__thiscall * CBotInfoMgrq)(CBotInfoMgr* pthis);
	void(__thiscall* Init)(CBotInfoMgr* pthis);
	void(__thiscall* Term)(CBotInfoMgr* pthis);
	unsigned int(__thiscall* OnMessage)(CBotInfoMgr* pthis, char, ILTMessage_Read*);
	void(__thiscall* RemoveAllBots)(CBotInfoMgr* pthis);
	int(__thiscall* AddBot)(CBotInfoMgr* pthis, stBotInfo*, int);
	void(__thiscall* UpdateBot)(CBotInfoMgr* pthis, int, void*, CBotInfoMgr_BotInfoType);
	void(__thiscall* RemoveBot)(CBotInfoMgr* pthis, int);
};
class CBotInfoMgr
{
public:
	CBotInfoMgr_vtbl* __vftable /*VFT*/;
	class BOT_INFO* m_pBotInfos;
	int m_nBotInfoCount;
	class CBotInfoButeMgr* m_pBotInfoButeMgr;
};
class THMCTimer
{
public:
	float m_t1; //0x0000
	float m_dt; //0x0004
	float m_tp; //0x0008
	bool m_bOn; //0x000C
private:
	bool undefined1; //0x000D
	bool undefined2; //0x000E
	bool undefined3; //0x000F
}; //Size: 0x0010
class THMCTimerEx : public THMCTimer
{
public:
	float m_recordElapsetime; //0x0010
	float m_recordCountdownTime; //0x0014
	float m_fSpeed; //0x0018
	float m_fLastCheckTime; //0x001C
}; //Size: 0x0020
class ItemInfoStr
{
public:
	char pad_0000[4]; //0x0000
	int32_t eInfoType; //0x0004 enum ItemInfoType
	int32_t nClientItemNo; //0x0008
	int32_t m_nSubType; //0x000C
	int32_t m_nItemNo; //0x0010
}; //Size: 0x0040
struct stSnow_Ball_Info
{
	struct SharedTexture* hSnowBallTex;
	CTimer SnowBallTimer;
	int nAlpha;
	LT_POLYGT4q ploySnowBall;
	LTIntPtq SnowBallPos;
	LTIntPtq SnowBallSize;
};

struct CHUDCrosshair 
{
	CHUDItem pCHUDItem;
	unsigned int m_bVisible;
	LT_POLYGT4q m_Poly;
	float m_fCrosshairGapMin;
	float m_fCrosshairGapRange;
	float m_fCrosshairBarMin;
	float m_fCrosshairBarRange;
	unsigned int m_bDoDamage;
	unsigned int m_nDoDamageStartTime;
	LT_POLYGT4q m_PolyDamageIndicator;
	LT_POLYGT4q m_PolyDamaged;
	LT_POLYGT4q m_PolyFrozen;
	LT_POLYGT4q m_PolyInfected;
	struct SharedTexture* m_hDamagedTexture;
	struct SharedTexture* m_hDamageIndicatorTexture;
	LT_POLYGT4q m_PolySnowBall;
	LTIntPtq m_SnowBallPos;
	LTIntPtq m_SnowBallSize;
	struct SharedTexture* m_hSnowBallDamagedTexture[3];
	std::vector<stSnow_Ball_Info, std::allocator<stSnow_Ball_Info> > m_vecSnowBallInfo;
	struct SharedTexture* m_hFrozenTex;
	struct SharedTexture* m_hInfectedTex;
	LTIntPtq m_DamageIndicatorSize;
	LTIntPtq m_DamageIndicatorUVSize;
	bool m_bDrawDamaged;
	int m_nDamagedAlpha;
	unsigned int m_nDoDamagedStartTime;
	float m_fDamagedYaw;
	LT_POLYGT4q m_PolyDotSight;
	struct SharedTexture* m_hDotSight;
	char m_szDotSight[1024];
	unsigned int m_nCrossHairARGB;
	class GUITextCtrl* m_pRangeOfTarget;
	bool m_bShowRangeOfTarget;
	bool m_bEnable_Target_FriendlyIndicator;
	bool m_bEnable_Target_HP;
	float m_fVectorSlide;
	float m_fVectorBarSize;
	float m_fVectorTime;
	float m_fVectorPerturbMAX;
	class GUIFrame* m_pFriendlyInfoTex;
	class GUITextCtrl* m_pFriendlyHealth;
	CTimer m_cVectorTime;
	unsigned int m_dwWeaponCrosshair;
	unsigned int m_dwCustomCrosshair;
	unsigned int m_dwCustomCrosshairColor;
	std::vector<unsigned long, std::allocator<unsigned long> > m_dwCrosshairShapeList;
	bool m_bEnableUSV;
	bool m_bWeaponEnableUSV;
};




void BackupCrosshairStats(CHUDCrosshair* Crosshairs)
{
	cheat::HUDCrosshair::Backup::DefaultValue[0] = Crosshairs->m_bDrawDamaged;
	cheat::HUDCrosshair::Backup::DefaultValue[1] = Crosshairs->m_bVisible;

	cheat::HUDCrosshair::Backup::DefaultValue[2] = Crosshairs->m_fCrosshairGapMin;
	cheat::HUDCrosshair::Backup::DefaultValue[3] = Crosshairs->m_fCrosshairGapRange;

	cheat::HUDCrosshair::Backup::DefaultValue[4] = Crosshairs->m_fCrosshairBarMin;
	cheat::HUDCrosshair::Backup::DefaultValue[5] = Crosshairs->m_fCrosshairBarRange;


	cheat::HUDCrosshair::Backup::DefaultValue[6] = Crosshairs->m_bShowRangeOfTarget;
	cheat::HUDCrosshair::Backup::DefaultValue[7] = Crosshairs->m_bEnable_Target_FriendlyIndicator;
	cheat::HUDCrosshair::Backup::DefaultValue[8] = Crosshairs->m_bEnable_Target_HP;
}


void ApplyShowDamage(CHUDCrosshair* Crosshairs)
{
	if (cheat::HUDCrosshair::DamageHUD)
	{
		Crosshairs->m_bDrawDamaged = cheat::HUDCrosshair::iDamageHUD;
	}
	else
	{
		Crosshairs->m_bDrawDamaged = cheat::HUDCrosshair::Backup::DefaultValue[0];
	}
}
void ApplyVisibleHUD(CHUDCrosshair* Crosshairs)
{
	if (cheat::HUDCrosshair::ShowHUD)
	{
		Crosshairs->m_bVisible = cheat::HUDCrosshair::iShowHUD;
	}
	else
	{
		Crosshairs->m_bVisible = cheat::HUDCrosshair::Backup::DefaultValue[1];
	}
	if (cheat::HUDCrosshair::ShowRangeOfTarget)
	{
		Crosshairs->m_bShowRangeOfTarget = false;
	}
	else
	{
		Crosshairs->m_bShowRangeOfTarget = cheat::HUDCrosshair::Backup::DefaultValue[6];
	}
	if (cheat::HUDCrosshair::Enable_Target_FriendlyIndicator)
	{
		Crosshairs->m_bEnable_Target_FriendlyIndicator = false;
	}
	else
	{
		Crosshairs->m_bEnable_Target_FriendlyIndicator = cheat::HUDCrosshair::Backup::DefaultValue[7];
	}
	if (cheat::HUDCrosshair::Enable_Target_HP)
	{
		Crosshairs->m_bEnable_Target_HP = false;
	}
	else
	{
		Crosshairs->m_bEnable_Target_HP = cheat::HUDCrosshair::Backup::DefaultValue[8];
	}
}
void ApplyCrosshairGap(CHUDCrosshair* Crosshairs)
{
	if (cheat::HUDCrosshair::CrosshairGapMin)
	{
		Crosshairs->m_fCrosshairGapMin = cheat::HUDCrosshair::fCrosshairGapMin;
	}
	else
	{
		Crosshairs->m_fCrosshairGapMin = cheat::HUDCrosshair::Backup::DefaultValue[2];
	}
	if (cheat::HUDCrosshair::CrosshairGapRange)
	{
		Crosshairs->m_fCrosshairGapRange = cheat::HUDCrosshair::fCrosshairGapRange;
	}
	else
	{
		Crosshairs->m_fCrosshairGapRange = cheat::HUDCrosshair::Backup::DefaultValue[3];
	}

	if (cheat::HUDCrosshair::CrosshairBarMin)
	{
		Crosshairs->m_fCrosshairBarMin = cheat::HUDCrosshair::fCrosshairBarMin;
	}
	else
	{
		Crosshairs->m_fCrosshairBarMin = cheat::HUDCrosshair::Backup::DefaultValue[4];
	}
	if (cheat::HUDCrosshair::CrosshairBarRange)
	{
		Crosshairs->m_fCrosshairBarRange = cheat::HUDCrosshair::fCrosshairBarRange;
	}
	else
	{
		Crosshairs->m_fCrosshairBarRange = cheat::HUDCrosshair::Backup::DefaultValue[5];
	}
}