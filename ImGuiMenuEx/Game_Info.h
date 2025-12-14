#include <iltmessage.h>
#include <ltbasedefs.h>
#include <iltcsbase.h>
#include <iltcommon.h>
#include "Enum_List.h"
#define ADDR_ClientFx		0x6BF34


class IBaseq;
struct /*VFT*/ IBase_vtbl { const char* (__thiscall* _InterfaceImplementation)(IBaseq* pthis); };

class IBaseq { public: IBase_vtbl* __vftable; };
class ILTDrawPrim { public: IBaseq baseclass_0; };
class Transform { public: D3DXVECTOR3 m_Pos; D3DXVECTOR4 m_Rot; D3DXVECTOR3 m_Scale; }; //Size: 0x0028
class CTimer { public: float m_t1; float m_dt; float m_tp; bool m_bOn; };
class c_timer_struct { public: bool  m_ignore; bool  m_enable; float m_duration; int m_value; };
typedef bool(*ObjectFilterFnA)(int* hObj, void* pUserData);
class IntersectQueryCA
{
public:
	D3DXVECTOR3 Start;
	D3DXVECTOR3 End;
	unsigned int Flags;
	ObjectFilterFnA FilterFn;
	void* FilterIntersectParam;
	ObjectFilterFnA FilterIntersectFn;
	void* FilterParam;
	void* PolyFilterParam;
};
class IntersectInfoCA
{
public:
	D3DXVECTOR3 m_Point; //0x0000
	D3DXVECTOR4 m_Plane; //0x000C
	int32_t m_hObject; //0x001C
	D3DXVECTOR2 m_hPoly; //0x0020
	int32_t m_SurfaceFlags; //0x0028
	int32_t m_hNode; //0x002C
};
struct CClientWeaponAllocator_vtbl {/* IClientWeaponBase* New(CClientWeaponAllocator* pthis, int);*/ };
const struct CClientWeaponAllocator { CClientWeaponAllocator_vtbl* __vftable; };


struct CClientInfoMgr;
struct CClientInfoMgr_vtbl
{
	void(__thiscall * qCClientInfoMgr)(CClientInfoMgr* pthis);
	void(__thiscall* Init)(CClientInfoMgr* pthis);
	void(__thiscall* RemoveAllClients)(CClientInfoMgr* pthis);
	unsigned int(__thiscall* OnMessage)(CClientInfoMgr* pthis, char, ILTMessage_Read*);
	void(__thiscall* OnEnterWorld)(CClientInfoMgr* pthis);
	void(__thiscall* PlayerDoDamage)(CClientInfoMgr* pthis, LTObject*, HitLocation bone);
};

struct CClientInfoMgr { CClientInfoMgr_vtbl* __vftable; };

struct _MsgPacket
{
	unsigned int nMsgType;
	unsigned int nPacketSize;
	char szPacket[32768];
};

#include "Class_Stuffs.h"
#include "Other_class.h"

#include "CWeatherFX.h"
#include "CharInfo.h"
#include "cILTDrawPrim.h"
#include "CCursor.h"
#include "cInterfaceMgr.h"
#include "cCharModelInfoMgr.h"
#include "cSFXMgr.h"
#include "ITLClient.h"
#include "CHUDMgr.h"
#include "cPlayerMGR.h"
#include "cWeaponMGR.h"
#include "cGameClientShell.h"
#include "CHUDXML.h"
#include "ClientConnectionMgr.h"
#include "CModificationMgr.h"
/////////////////////////////////////////
class CHUDXMLRespawnToken
{
public:
	char pad_0000[180]; //0x0000
	CHUDXMLRespawnToken__E_RESPAWNTOKEN_STATUS m_eStatus; //0x00B4
}; //Size: 0x0440

class cLTModel
{
public:
	virtual void* InterfaceImplementation();
	virtual unsigned int CacheModelDB(const char*, unsigned int*);
	virtual unsigned int UncacheModelDB(unsigned int*);
	virtual unsigned int IsModelDBLoaded(unsigned int);
	virtual unsigned int AddChildModelDB(int* Obj, unsigned int);
	virtual unsigned int GetSocket(int* Obj, const int, unsigned int*);
	virtual unsigned int GetSocket(int* Obj, const char*, unsigned int*);
	virtual unsigned int GetSocketTransform(int* Obj, unsigned int, Transform*, bool);
	virtual unsigned int getNearestSoketID(int* Obj, TVector3<float>*);
	virtual unsigned int GetNumPieces(int* Obj, unsigned int*);
	virtual unsigned int GetPiece(int* Obj, const char*, unsigned int*);
	virtual unsigned int GetPieceHideStatus(int* Obj, unsigned int, bool*);
	virtual unsigned int SetPieceHideStatus(int* Obj, unsigned int, bool);
	virtual unsigned int GetNode(int* Obj, const int, unsigned int*);
	virtual unsigned int GetBoneNode(int* Obj, const char* nodeName, unsigned int& Node); //0x0038
	virtual unsigned int GetNodeName(int* Obj, unsigned int Node, char* name, int maxlen); //0x003C
	virtual unsigned int GetNodeTransform(int* Obj, unsigned int hNode, Transform* trans, bool bWorldSpace); //0x0040
	virtual unsigned int GetModelNextNode(int* Obj, unsigned int Node, unsigned int& Next); //0x0044
};

class cClientInfoMgr;
class cILTCSBase
{
public:
	ILTClientDLL* ILTBase; //0x0000
	char pad_0004[16]; //0x0004
	__int32 ILTDrawPrim; //0x0014
	char pad_0018[4]; //0x0018
	cLTModel* ILTModel; //0x001C
	DWORD CClientMgr; //0x0020
}; cILTCSBase* oILTCSBase;


class PROJECTILECLASSDATA;
struct PROJECTILECLASSDATA_vtbl
{
	void(__thiscall* sPROJECTILECLASSDATA)(PROJECTILECLASSDATA* pthis);
	unsigned int(__thiscall* Init)(PROJECTILECLASSDATA* pthis, void/*CButeMgr*/*, char*);
	void(__thiscall* Cache)(PROJECTILECLASSDATA* pthis, void/*CFXButeMgr*/*);
};


class PROJECTILECLASSDATA
{
public:
	PROJECTILECLASSDATA_vtbl* __vftable /*VFT*/;
	char szName[32];
};
class TURRETFXq
{
public:
	int nId;
	char szName[32];
	char szModel[64];
	char szSkin[64];
	char szBottomLinkNodeName[32];
	char szTopLinkNodeName[32];
	char szReadySoundFXName[32];
	int nTopWeaponID;
	float fFireDelay;
	float fPerturb;
	int nMaxAmmo;
	TVector3<float> vModelScale;
	LTIntPtq ptShootingAngle;
	TVector3<float> vSensorOffset;
	float fFirePosUpOffset;
	float fFirePosFrontOffset;
};
class CNumericButeListReaders
{
public:
	unsigned int m_dwItems;
	std::vector<int, std::allocator<int> > m_vItems;
};

class PROJECTILEFXs
{
public:
	int nId;
	char szName[32];
	char szFlareSprite[64];
	char szClass[64];
	char szModel[64];
	char szCreateSound[64];
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > strSound[3];
	CButeListReader blrSkins;
	char szFXName[32];
	int dwFXFlags;
	char szZoneFX[32];
	bool bShowEnemyZoneFx;
	char szRicochetFXName[32];
	float fMaxRicochetAngle;
	int nMaxRicochets;
	int nVelocity;
	int nAltVelocity;
	int nDropVelocity;
	float fFireOffset;
	float fLifeTime;
	float fGravityOverride;
	float fFinishSndTime;
	int nFlags;
	D3DXVECTOR3 vLightColor;
	int nLightRadius;
	int nSoundRadius;
	int nCreateSoundRadius;
	float fFlareScale;
	float fFlareYOffset;
	unsigned int dwObjectFlags;
	D3DXVECTOR3 vModelScale;
	int nSmokeTrailType;
	int nDamageMaxCnt;
	int nCanImpactSameKind;
	float fFireDelayTime;
	bool bGuided;
	float fGuidedDelayTime;
	bool bAIAttackTarget;
	bool bAIDodgeTarget;
	CNumericButeListReaders ilWeakDamageType;
	CNumericButeListReaders flWeakDamageRate;
	PROJECTILECLASSDATA* pClassData;
	TURRETFXq* pTurretFX;
	std::map<int, float, std::less<int>, std::allocator<std::pair<int const, float> > > mapRechargeInfo;
	int nRechargeCount;
	float fExplosionDelayTime;
};




class cObjName
{
public:
	__int32 nID; //0x0000
	char Name[32]; //0x0004
};
class cBaseFX
{
public:
	char unknown1[16];
	int* Object; //0x0010
	D3DXVECTOR3 Pos; //0x0014
	char unknown2[28];
	cObjName* gotoObjName; //0x0034
	char unknown3[8];
	int NoGun; //0x0040
	char unknown4[4];
	BYTE Unknown5;
	int OwnerID; //0x004C
};
class CJumpVolumeFX
{
public:
	char pad_0000[56]; //0x0000
	D3DXVECTOR3 m_vVelocity; //0x0038
}; //Size: 0x0048


class CModelButeMgr_CHeadPiece
{
public:
	const char* m_szName; //0x0000
	char pad_0004[180]; //0x0004
	__int32 m_nGearId; //0x00B8
};
class CModelButeMgr_CFacePiece
{
public:
	__int32 m_nBodyType;
	const char m_szName[64]; //0x0000
};
class CModelButeMgr
{
public:
	char pad_0000[5640]; //0x0000
	__int32 m_cHeadPieces; //0x1608
	CModelButeMgr_CHeadPiece** m_aHeadPieces; //0x160C
	char pad_1610[24]; //0x1610
	__int32 m_cFacePieces; //0x1628
	CModelButeMgr_CFacePiece** m_aFacePieces; //0x160C


}; //Size: 0x166C







class CInvenCharacterModel
{
public:
	int32_t m_bShowCharacterModel; //0x0000
	int32_t m_nShowWeaponId; //0x0004
	int32_t m_nGoggleId; //0x0008
	int32_t m_nBackPackId; //0x000C
	int32_t m_eModelId; //0x0010
	int32_t m_bHaveLights; //0x0014
	char pad_0018[19436]; //0x0018
	CCharModelInfoMgr m_kCharModelInfoMgr; //0x4C04
}; //Size: 0x5040


class CXMLRoulettePopup
{
public:
	char pad_0000[296]; //0x0000
	int32_t m_nRotState; //0x0128
	char pad_012C[4]; //0x012C
	float m_fLastSpeed; //0x0130
	float m_fCurSpeed; //0x0134
	char pad_0138[68]; //0x0138
	float m_fRandomAngle; //0x017C
	char pad_0180[32]; //0x0180
	int32_t m_nSelectCoinNo; //0x01A0
}; //Size: 0x0140

struct CXMLCreateRoomPopup_CreateRoomInfo
{
	int mode;
	int map_id;
	int max_num;
	int room_id;
	int goal;
	int option;
	int sec_option;
	bool use_pw;
	bool bUseNoSpecial;
	bool bSEM;
	int nDifficulty;
	PlayType ePlayType;
	bool randommap;
	int country_option;
	int weapon_option[3];
	bool bOfficial;
	std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > wstrPW;
	std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > wstrName;
};
class CXMLCreateRoomPopup
{
public:
	char pad_0000[200]; //0x0000
	CXMLCreateRoomPopup_CreateRoomInfo m_RoomInfo;
};

struct MBCreate_t
{
	eMBType eType;
	void(__cdecl* pFn)(unsigned int, void*);
	void(__cdecl* pFn2)(unsigned int, void*);
	void* pData;
	const wchar_t* pString;
	unsigned __int16 nMaxChars;
	GUIEditCtrl_eInputMode eInput;
	bool bUsePassword;
	LTIntPtq editOffset;
	int strID_Title;
	int strID_Button_1;
	int strID_Button_2;
	int strID_Button_3;
	eMsgSoundType eSoundType;
	unsigned int dwShutdownTime;
	unsigned int dwTextFlag;
	void* pMultiCtrl;
	unsigned int m_bModal;
};

// Created with ReClass.NET 1.2 by KN4CK3R

class GameRoom
{
public:
	int32_t room_id; //0x0000
	wchar_t name[14]; //0x0004
	int32_t isLockRoom; //0x0020
	wchar_t password[14]; //0x0024
	int32_t map_id; //0x0040
	int32_t user_num; //0x0044
	int32_t player_num; //0x0048
	int32_t mode; //0x004C
	int32_t kill_num; //0x0050
	int32_t block_room; //0x0054
	int32_t state; //0x0058
	int32_t friendly_fire; //0x005C
	wchar_t alpha_clan[14]; //0x0060
	wchar_t bravo_clan[14]; //0x007C
	int32_t nMasterCID; //0x0098
	bool bView_enemy; //0x009C
	bool bMutation; //0x009D
	bool bPerkSkill; //0x009E
	bool bTeamChange; //0x009F
	int32_t nWeapon_use; //0x00A0
	int32_t nSecondWeaponOption; //0x00A4
	int32_t nSuperMaster; //0x00A8
	int32_t nNoSpecialist; //0x00AC
	int32_t nDifficulty; //0x00B0
	int32_t nTicketUItemID; //0x00B4
	int32_t bGoldPackage; //0x00B8
	int32_t nWeapon_option[3];
	int32_t nCountry_option; //0x00C8
	int32_t bRandommap; //0x00CC
}; //Size: 0x00D0

class CXMLScreenWaitingRoom
{
public:
	char pad_0000[21560]; //0x0000
	GameRoom m_GameRoomInfo; //0x5438
	char pad_5508[348]; //0x5508
	class Alphas* m_vAlphaUser_List; //0x5664
	char pad_5668[12]; //0x5668
	class Bravos* m_vBravoUser_List; //0x5674
}; //Size: 0x6140


class CHUDXMLRadioMsg
{
public:
	char pad_0000[100]; //0x0000
	int32_t m_nPage; //0x0064
	int32_t m_nListIdx; //0x0068
	int32_t m_nRandom; //0x006C
	int32_t m_nViewIdx; //0x0070
	int32_t m_nSoundTemplate; //0x0074
	int32_t m_nLastCommandTick; //0x0078
}; //Size: 0x0440
class CScreenCharacterModel
{
public:
	int32_t m_bShowCharacterModel; //0x0000
	int32_t m_nRenderIndex; //0x0004
	int32_t m_nShowWeaponId; //0x0008
	int32_t m_nGoggleId; //0x000C
	int32_t m_nBackPackId; //0x0010
	int32_t m_eModelId; //0x0014
	int32_t m_bHaveLights; //0x0018
	char pad_001C[272]; //0x001C
	LTVector m_vCharPos; //0x012C
	LTVector m_vMovePos; //0x0138
	LTVector m_vDefaultPos; //0x0144
	LTRotation m_rCharRot; //0x0150
}; //Size: 0x0864

class CServerConfigButeMgr
{
public:
	char pad_0000[6120]; //0x0000
	int32_t m_bFriendlyFire; //0x17E8
}; //Size: 0xA040

class CGameRoomButeMgr;

struct IProtocol
{
	unsigned int m_dwProtocolID;
	unsigned int m_dwSize;
};

struct _LEVEL_RANKER
{
	unsigned int m_dwExp;
	wchar_t m_szCharName[17];
	unsigned int m_dwIsClan;
	wchar_t m_szClanName[17];
	unsigned int m_dwNationIndex;
};

struct LC_GameroomStart
{
	IProtocol Protocol;
	wchar_t m_szIP[17];
	unsigned int m_dwPort;
	unsigned int m_dwRankerCount;
	_LEVEL_RANKER m_LevelRanker[20];
};

class CUISimpleStretchButton;
class CLayoutMgr;

class CHUDXMLChat
{
public:
	char pad_0000[144]; //0x0000
	uint32_t m_dwTempTime; //0x0090
	int32_t m_nInputCounter; //0x0094
	char pad_0098[40]; //0x0098
	wchar_t m_szChatStr[124];
	wchar_t m_TempWord[124];
}; //Size: 0x0140
class CLobbyServer
{
public:
};
class CCreateModelButesMgr;
class CButeMgr;
class CGameButeMgr
{
public:
	class  CGameButeMgr_vtbl* __vtable; //0x0000
	char pad_0004[4]; //0x0004
	CButeMgr* m_buteMgr; //0x0008
}; //Size: 0x0840


class CSurfaceMgr
{
public:
	CGameButeMgr baseclass_0;
};
class CClientButeMgr
{
public:
	char pad_0000[5600]; //0x0000
	uint32_t m_nNumGlowMappings; //0x15E0
	char m_nNumCheatAttributes; //0x15E4
	char pad_15E5[3]; //0x15E5
	int32_t m_nNumSingleWorldPaths; //0x15E8
	int32_t m_nNumMultiWorldPaths; //0x15EC
	int32_t m_nNumDebugKeys; //0x15F0
	int32_t m_aNumDebugLevels; //0x15F4 int *
	float m_fWeaponThrowBaseVel; //0x15F8
	float m_fWeaponThrowCurVel; //0x15FC
	float m_fPitchRotVel; //0x1600
	float m_fYawRotVel; //0x1604
	float m_fRollRotVel; //0x1608
	int32_t m_nAttendanceShowLimit; //0x160C
}; //Size: 0x2040
class CClientPerkSkill;



struct CWSInterfaceImpl : CWSInterface { };

struct WeaponPath
{
	unsigned __int16 nWeaponId;
	TVector3<float> vPath;
	TVector3<float> vU;
	TVector3<float> vR;
	float fPerturbU;
	float fPerturbR;
	bool bZoom;
	bool bTripleShot;
	float fDynamicPerturbFactor;
	float fMinPerturbPer;
	float fMod_ZoomInMinPerturb;
	float fMod_ZoomInMaxPerturb;
	const CONVERT* pConvert;
};

class CGamePlayCustomizeMgr
{
public:
	char pad_0000[5600]; //0x0000
	bool m_bActivate; //0x15E0
	bool m_bRecreation; //0x15E1
	char pad_15E2[35]; //0x15E2
	char m_nHitSphereRadius; //0x1605 char 
};
