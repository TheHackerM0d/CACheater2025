#include "cPlayerMGR_vtbl.h"
class MissionStats;
class MissionStats_vtbl
{
public:
	void(__thiscall* MissionStatsq)(MissionStats* pthis);
	void(__thiscall* Init)(MissionStats* pthis);
};
class MissionStats
{
public:
	MissionStats_vtbl* __vftable; //0x0000
	__int32 dwNumEnemyKills; //0x0004
	__int32 dwNumTimesKilled; //0x0008
	__int32 dwNumFriendKills; //0x000C
	__int32 dwInGameLevel; //0x0010
	__int32 dwUpdatedNumEnemyKills; //0x0014
	__int32 dwUpdatedNumTimesKilled; //0x0018
	__int32 dwUpdatedRoundPoint; //0x001C
	__int32 dwUpdatedKillExp; //0x0020
	__int32 dwUpdatedGainMoney; //0x0024
	__int32 dwHeadShot; //0x0028
	__int32 dwFirstKill; //0x002C
	__int32 dwFirstDeath; //0x0030
	__int32 dwDoubleKill; //0x0034
	__int32 dwMultiKill; //0x0038
	__int32 dwUnbelievable; //0x003C
	__int32 dwUltraKill; //0x0040
	__int32 dwFantasticKill; //0x0044
	__int32 dwUnbelievablePlus; //0x0048
	__int32 dwKillNutShot; //0x004C
	__int32 dwDeadNutShot; //0x0050
	__int32 dwKillFinalSpy; //0x0054
	__int32 dwDeadFinalSpy; //0x0058
	__int32 dwIntelUpLoaded; //0x005C
	__int32 dwWinCount; //0x0060
	__int32 dwLoseCount; //0x0064
	__int32 dwBombPlanted; //0x0068
	__int32 dwBombDefused; //0x006C
	__int32 dwBombDetonated; //0x0070
	__int32 dwSuicideTimes; //0x0074
	__int32 dwMissionPoint; //0x0078
	__int32 dwBossKillNum; //0x007C
	__int32 dwTriggerBossKillNum; //0x0080
	char pad_0084[4]; //0x0084
	__int32 dwSurviveBonus; //0x0088
	__int32 dwTimeBonus; //0x008C
	__int32 dwLifeCount; //0x0090
	__int32 dwLongestLifeTime; //0x0094
	__int32 dwMaxKillCountPerLife; //0x0098
	__int32 dwCurrentCombo; //0x009C
	__int32 dwTotalCombo; //0x00A0
	__int32 dwMaxCombo; //0x00A4
	__int32 dwTotalPlayTime; //0x00A8
	__int32 dwTotalLifeTime; //0x00AC
	__int32 dwLastSpawnTime; //0x00B0
	__int32 dwCurrentKillCount; //0x00B4
	__int32 dwRespawnCount; //0x00B8
	__int32 dwBonusLifeCount; //0x00BC
	__int32 dwMissionCompleteCount; //0x00C0
	__int32 bMissionSuccess; //0x00C4
	char pad_00C8[8]; //0x00C8
	__int32 dwCoopRanking; //0x00D0
	__int32 dwCapturetheFlag; //0x00D4
	__int32 dwRetrievetheFlag; //0x00D8
	bool dwbSendExitMsg; //0x00DC
	bool dwbSendRankMsg; //0x00DD
	bool undefined1; //0x00DE
	bool undefined2; //0x00DF
	__int32 dwKillStreak; //0x00E0
	__int32 dwMaxKillStreak; //0x00E4
	__int32 dwDeathStreak; //0x00E8
	int64_t dwMaxDeathStreak; //0x00EC
	int64_t dwIamHuman_KillInfect; //0x00F4
	__int32 dwIamInfect_DeadByHuman; //0x00FC
	__int32 dwIamInfect_InfectHuman; //0x0100
	__int32 dwIamHuman_InfectedByInfect; //0x0104
	__int32 dwWin_IamInfection; //0x0108
	__int32 dwWin_IamHuman; //0x010C
	__int32 dwRoundHumanLifeTime; //0x0110
	__int32 dwHumanLifeTime; //0x0114
	__int32 dwRoundHumanKill; //0x0118
	__int32 dwRoundInfectedKill; //0x011C
	__int32 dwRoundInfectedDeath; //0x0120
	__int32 dwRoundHumanDeath; //0x0124
	__int32 dwSaveBullionAmount; //0x0128
	__int32 dwSaveBullionNum; //0x012C
	__int32 dwNumVIPKilles; //0x0130
	__int32 dwNumVIPKilled; //0x0134
	__int32 dwNumVIPExit; //0x0138
	__int32 dwVIPRank; //0x013C
}; //Size: 0x0140
class CBAMissionStats
{
public:
	MissionStats* baseclass_0; //0x0000
	char pad_0004[308]; //0x0004
	__int32 dwMoney; //0x0138
	__int32 dwEnemyKillExp; //0x013C
	__int32 dwRoundExp; //0x0140
	bool bMoneyDouble; //0x0144
	bool bExpDouble; //0x0145
	bool bPcRoom; //0x0146
	bool undefined; //0x0147
}; //Size: 0x0148
class CCBAPlayerStats
{
public:
	char pad_0000[4]; //0x0000
	__int32 m_bPickupItem; //0x0004
	__int32 m_nAmmoInClip; //0x0008
	__int32 m_nHealth; //0x000C
	__int32 m_nArmor; //0x0010
	__int32 m_nMaxHealth; //0x0014
	__int32 m_nMaxArmor; //0x0018
	uint32* m_pnAmmo; //0x001C
	uint32* m_pbHaveAmmo; //0x0020
	uint32* m_pbHaveWeapon; //0x0024
	__int32 m_nCurrentWeapon; //0x0028
	uint32* m_pbHaveMod; //0x002C
	uint32* m_pbHaveGear; //0x0030
	uint32* m_pbCanUseAmmo; //0x0034
	uint32* m_pbCanUseWeapon; //0x0038
	uint32* m_pbCanUseMod; //0x003C
	uint32* m_pbCanUseGear; //0x0040
	__int32 m_nDamage; //0x0044
	CBAMissionStats* m_MissionStats; //0x0048
	char pad_004C[324]; //0x004C
	__int32 m_dwProgress; //0x0190
	__int32 m_dwMaxProgress; //0x0194
	__int32 m_bDash; //0x0198
	__int32 m_nFirstDash; //0x019C
	__int32 m_nDashStartTime; //0x01A0
	__int32 m_nDashGauge; //0x01A4
	__int32 m_nDashGaugeRec; //0x01A8
	float m_fDashCurrentStamina; //0x01AC
	eDashGageState m_eSPstate; //0x01B0 eDashGageState
	__int32 m_bJumped; //0x01B4
	__int32 nCurrentAmmoIndex; //0x01B8
}; //Size: 0x01BC
class __Objectqq
{
public:
	DWORD Unknown; //0x0000
	float xBound1; //0x0004
	float yBound1; //0x0008
	float zBound1; //0x000C
	float xBound2; //0x0010
	float yBound2; //0x0014
	float zBound2; //0x0018
	char unknown28[172]; //0x001C
	D3DXVECTOR3 Pos; //0x00C8
	char unknown228[180]; //0x00E4
	CHAR Pad[4];
	D3DXVECTOR3 origin;
};
//class cCLIENT_INFO
//{
//public:
//	__int32 index; //0x0000 
//	union
//	{
//		__Objectqq* pObject; //0x0004 
//		int* Object; //0x0004 
//	};
//	unsigned int pIsDead; //0x0008 
//	__int32 pTeam; //0x000C 
//	char  _0x0010[8]; //0x0010 
//	__int32  ClientID; //0x0018 
//	char _0x001C[12]; //0x001C 
//	char pName[16]; //0x0028
//	char _0x0038[8]; //0x0038 
//	__int32 nKills; //0x0040
//	__int32 nDeaths; //0x0044
//	__int32 nKillStreak; //0x0048
//	__int32 nDeathStreak; //0x004C
//	__int32 nMaxKillStreak; //0x0050
//	__int32 nMaxDeathStreak; //0x0054
//	char pad_0058[28]; //0x0058
//	__int32 dwHeadShot; //0x0074
//	__int32 nMissionCount; //0x0078
//	__int32 nCaptureFlag; //0x007C
//	__int32 nRetrieveFlag; //0x0080
//	float m_fKDR; //0x0084
//	__int32 nPlayerBeforeExp; //0x0088
//	__int32 nPlayerGainExp; //0x008C
//	__int32 nPlayerGainMoney; //0x0090
//	__int32 nBonusExp; //0x0094
//	char pad_0098[60]; //0x0098
//	__int32 nBonusMoney; //0x00D4
//	char pad_00D8[60]; //0x00D8
//	__int32 nModelId; //0x0114
//	__int32 nLevel; //0x0118
//	bool bPcRoom; //0x011C
//	bool bEvent; //0x011D
//	bool bExpEvent; //0x011E
//	bool bHavePlusExpGPItem; //0x011F
//	__int32 m_bClanMember; //0x0120
//	char pad_0124[28]; //0x0124
//	__int32 dwClanID; //0x0140
//	__int32 dwClanMarkEmblem; //0x0144
//	__int32 dwClanMarkBack; //0x0148
//	__int32 nNameColor; //0x014C
//	__int32 nClanNameColor; //0x0150
//	char pad_0154[16]; //0x0154
//	__int32 m_bDash; //0x0164
//	__int32 m_dwScore; //0x0168
//	__int32 m_dwLifeCount; //0x016C
//	__int32 m_dwLongestLifeTime; //0x0170
//	__int32 m_dwMaxKillCountPerLife; //0x0174
//	__int32 m_dwMissionCompleteCount; //0x0178
//	__int32 m_dwTotalCombo; //0x017C
//	__int32 m_dwSerum; //0x0180
//	__int32 m_dwInGameLevel; //0x0184
//	__int32 m_bMiniMissionCompleted; //0x0188
//	__int32 m_nNationIndex; //0x018C
//	__int32 m_nMiniMissionIndex; //0x0190
//	__int32 m_nBombDetonate; //0x0194
//	__int32 m_nBombDefuse; //0x0198
//	__int32 m_nCurrentBuffID; //0x019C
//	__int32 m_nCurrentNerfID; //0x01A0
//	__int32 nIamHuman_KillInfect; //0x01A4
//	__int32 nIamInfect_DeadByHuman; //0x01A8
//	__int32 nIamInfect_InfectHuman; //0x01AC
//	__int32 nIamHuman_InfectedByInfect; //0x01B0
//	__int32 nWin_IamInfection; //0x01B4
//	__int32 nWin_IamHuman; //0x01B8
//	__int32 m_dwSuperMasterLevel; //0x01BC
//	__int32 m_dwAssistCount; //0x01C0
//	__int32 m_dwSubMissionCount; //0x01C4
//	__int32 m_dwSuperSpyKillCount; //0x01C8
//	__int32 m_dwIntelUploadCount; //0x01CC
//	__int32 m_dwHumanLifeTime; //0x01D0
//	__int32 m_dwVIPKillCount; //0x01D4
//	__int32 m_dwVIPExitCount; //0x01D8
//	__int32 m_bLastStageEnterUser; //0x01DC
//	__int32 m_dwGameTimeMilSec; //0x01E0
//	__int32 m_dwTotalHuntedTime; //0x01E4
//	__int32 m_bVIP; //0x01E8
//	__int32 m_dwVIPRank; //0x01EC
//	__int32 m_bGoldPackage; //0x01F0
//	__int32 m_nClientType; //0x01F4
//	__int32 m_nRankCoverID; //0x01F8
//	__int32 m_nNationCoverID; //0x01FC
//	__int32 m_nNameBG; //0x0200
//	__int32 m_nNameBGLine; //0x0204
//	__int32 m_bShowSnowballFrozen; //0x0208
//	float m_fMMR; //0x020C
//}; //Size: 0x0210
class CAM_TARGET_INFO
{
public:
	__int32 nID; //0x0000
	union
	{
		__Objectqq* pObj; //0x0004 
		int* hObj; //0x0004 
	};
	bool bDead; //0x0008
private:
	char IgnoreMe0; //0x0009
	char IgnoreMe1; //0x000A
	char IgnoreMe2; //0x000B
public:
	int nTeam; //0x000C
	int nKillMeCount;//0x0010
	CAM_TARGET_INFO__CHAR_INFO_TYPE eInfoType;//0x0014
};
class cCLIENT_INFO
{
public:
	CAM_TARGET_INFO baseclass_0; //0x0000
	char  m_Ping; //0x0018 
private:
	char IngoreMe[3]; //0x0019
public:
	unsigned int dwUID; //0x001C
	unsigned int dwSID; //0x0020
private:
	int IngoreMe0; //0x0024
public:
	char sName[16]; //0x0028
private:
	char pad_0034[8]; //0x0034
public:
	int nKills; //0x0040
	int nDeaths;//0x0044
	int nKillStreak; //0x0048
	int nDeathStreak; //0x004C
	int nMaxKillStreak; //0x0050
	int nMaxDeathStreak; //0x0054
	int rdwMultiKill[7]; //0x0058
	unsigned int dwHeadShot; //0x0074
	int nMissionCount; //0x0078
	int nCaptureFlag; //0x007C
	int nRetrieveFlag; //0x0080
	float m_fKDR; //0x0084
	int nPlayerBeforeExp; //0x0088
	int nPlayerGainExp; //0x008C
	int nPlayerGainMoney; //0x0090
	int nBonusExp[16]; //0x0094
	int nBonusMoney[16]; //0x00D4
	int nModelId; //0x0114
	int nLevel; //0x0118
	bool bPcRoom; //0x011C
	bool bEvent; //0x011D
	bool bExpEvent; //0x011E
	bool bHavePlusExpGPItem; //0x011F
	bool m_bClanMember; //0x0120
private:
	char IngoreMe1[3]; //0x00121
public:
	wchar_t wstrPlayerClanName[24]; //0x0124
	unsigned int dwClanID; //0x0140
	unsigned int dwClanMarkEmblem; //0x0144
	unsigned int dwClanMarkBack; //0x0148
	unsigned int nNameColor; //0x014C
	unsigned int nClanNameColor; //0x0150
	unsigned int m_dwCurrentDelay[3]; //0x0154
	unsigned int m_dwCurrentFPS; //0x0160
	bool m_bDash; //0x0164
private:
	char IngoreMe2[3]; //0x0165
public:
	unsigned int m_dwScore; //0x0168
	unsigned int m_dwLifeCount; //0x016C
	unsigned int m_dwLongestLifeTime; //0x0170
	unsigned int m_dwMaxKillCountPerLife; //0x0174
	unsigned int m_dwMissionCompleteCount; //0x0178
	unsigned int m_dwTotalCombo; //0x017C
	unsigned int m_dwSerum; //0x0180
	unsigned int m_dwInGameLevel; //0x0184
	bool m_bMiniMissionCompleted; //0x0188
private:
	char IngoreMe3[3]; //0x0189
public:
	int m_nNationIndex; //0x018C
	int m_nMiniMissionIndex; //0x0190
	int m_nBombDetonate; //0x0194
	int m_nBombDefuse; //0x0198
	int m_nCurrentBuffID; //0x019C
	int m_nCurrentNerfID; //0x01A0
	int nIamHuman_KillInfect; //0x01A4
	int nIamInfect_DeadByHuman; //0x01A8
	int nIamInfect_InfectHuman; //0x01AC
	int nIamHuman_InfectedByInfect; //0x01B0
	int nWin_IamInfection; //0x01B4
	int nWin_IamHuman; //0x01B8
	unsigned int m_dwSuperMasterLevel; //0x01BC
	unsigned int m_dwAssistCount; //0x01C0
	unsigned int m_dwSubMissionCount; //0x01C4
	unsigned int m_dwSuperSpyKillCount; //0x01C8
	unsigned int m_dwIntelUploadCount; //0x01CC
	unsigned int m_dwHumanLifeTime; //0x01D0
	unsigned int m_dwVIPKillCount; //0x01D4
	unsigned int m_dwVIPExitCount; //0x01D8
	bool m_bLastStageEnterUser; //0x01DC
private:
	char IngoreMe4[3]; //0x01DD
public:
	unsigned int m_dwGameTimeMilSec; //0x01E0
	unsigned int m_dwTotalHuntedTime; //0x01E4
	bool m_bVIP; //0x01E8
private:
	char IngoreMe5[3]; //0x01E9
public:
	unsigned int m_dwVIPRank; //0x01EC
	bool m_bGoldPackage; //0x01F0
private:
	char IngoreMe6[3]; //0x01F1
public:
	int m_nClientType; //0x01F4
	int m_nRankCoverID; //0x01F8
	int m_nNationCoverID; //0x01FC
	int m_nNameBG; //0x0200
	int m_nNameBGLine; //0x0204
	bool m_bShowSnowballFrozen; //0x0208
private:
	char IngoreMe7[3]; //0x0209
public:
	float m_fMMR; //0x020C
};
/*
class cCLIENT_INFO
{
public:
	CAM_TARGET_INFO baseclass_0; //0x0000
	__int32  ClientID; //0x0018
	char _0x001C[12]; //0x001C
	char pName[16]; //0x0028
	char _0x0038[8]; //0x0038
	__int32 Kills; //0x0040
	__int32 Deaths; //0x0044
	__int32 KillCombo; //0x0048
	__int32 TotalDeaths; //0x004C
	__int32 TotalKills; //0x0050
	char _0x0054[4]; //0x0054
	__int32 Suicides; //0x0058
	__int32 HeadShots; //0x005C
	char _0x0060[372]; //0x0060
	__int32 ExpReceived; //0x01D4
	__int32 GPReceived; //0x01D8
	char _0x01DC[132]; //0x01DC
	__int32 RankID; //0x0260
	char _0x0264[112]; //0x0264
	__int32 CountryID; //0x02D4
	char _0x02D8[48]; //0x02D8
	__int32 KillAssists; //0x0308
	char _0x030C[320]; //0x030C
	cCLIENT_INFO* pPlayerPrev; //0x044C
	cCLIENT_INFO* pPlayerNext; //0x044E
};//Size=0x0452
*/
class BOT_INFO
{
public:
	CAM_TARGET_INFO* baseclass_0; //0x0000 CAM_TARGET_INFO
	char pad_0004[28]; //0x0004
	__int32 dwLevel; //0x0020
	__int32 dwClanMarkEmblem; //0x0024
	__int32 dwClanMarkBackground; //0x0028
	__int32 dwNationIndex; //0x002C
	float fKDR; //0x0030
	__int32 nKills; //0x0034
	__int32 nDeaths; //0x0038
	__int32 nPlayerGainExp; //0x003C
	__int32 nPlayerGainMoney; //0x0040
	__int32 nChatDataIndex; //0x0044
	float fNextChatTimer; //0x0048
	float fNextChatTime; //0x004C
	BOT_INFO* pPrev; //0x0050
	BOT_INFO* pNext; //0x0054
}; //Size: 0x0058
class ClientFixedFrameUpdateInfo
{
	int IsFixedRate;
	int NumPlayerMovementFrames;
	int PlayerMovementFrameCode;
	int PlayerMovementFrameDeltaMS;
	float PlayerMovementFrameInterpolationFactor;
	unsigned int PlayerMovementGameTimeMS;
	bool NeedsSendingPeriodicUpdate;
};
class MissionStats;
class CPlayerStats
{
public:
	CPlayerStats_vtbl* __vftable /*VFT*/;
};
class CHeadBobMgr
{
public:
	float m_fBobHeight; //0x0000
	float m_fBobAmp; //0x0004
	float m_fBobPhase; //0x0008
	float m_fSwayPhase; //0x000C
}; //Size: 0x0010
class CCameraOffsetMgr
{
public:
	char pad_0000[7920]; //0x0000
	D3DXVECTOR3 m_vPitchYawRollDelta; //0x1EF0
	D3DXVECTOR3 m_vPosDelta; //0x1EFC
}; //Size: 0x0004
class CGTINFO
{
public:
	__int32 m_eTargetType; //0x0000 enum GadgetTargetType
	const char* m_pName; //0x0004 const char
	__int32 m_bShowTimeBar; //0x0008
	__int32 m_bResetTime; //0x000C
	__int32 m_bCanShoot; //0x0010
	__int32 m_bCanLockPick; //0x0014
	__int32 m_bCanWeld; //0x0018
	__int32 m_bCanCodeBreak; //0x001C
}; //Size: 0x0044
class CGadgetDisabler
{
public:
	CGTINFO* m_pGTInfo; //0x0000
	float m_fTimer; //0x0004
	char pad_0008[4]; //0x0008
	__int32 m_bShowTimeBar; //0x000C
	__int32 m_bDisabling; //0x0010
	float m_fTotalTime; //0x0014
}; //Size: 0x0018
class CContainerInfo
{
public:
	float m_fGravity; //0x0000
	float m_fViscosity; //0x0004
	float m_fPlayerSpeedFactor; //0x0008
	D3DXVECTOR3 m_Current; //0x000C
	ContainerCode m_ContainerCode; //0x0018
	__int32 m_bHidden; //0x001C
	__int32* m_hObject; //0x0020
	PlayerPhysicsModel m_ePPhysicsModel; //0x0024 enum PlayerPhysicsModel
}; //Size: 0x0028
class cMoveMgr_CrouchState
{
public:
	float m_fCrouchRate; //0x0000
	float m_fCrouchDownVelocity;//0x0004
	float m_fCrouchUpVelocity;//0x0008
	float m_fCrouchVelocityT0;//0x000C
	float m_fCrouchVelocityT1;//0x0010
	bool m_bStartedCrouchingUp;//0x0014
	bool m_bStartedCrouchingDown;//0x0015
	char pad_001C[2];//0x001C
	int m_ElapsedFromCrouchingUp;//0x0018
	int m_ElapsedFromCrouchingDown;//0x001C
};
class CrouchingMovementParameters
{
public:
	float CrouchingDuration; //0x0000
	float CrouchingTangent0; //0x0004
	float CrouchingTangent1; //0x0008
	__int32 EnableSlowdownPenalty; //0x000C
	float SlowdownSP_IncreaseDuration; //0x0010
	float SlowdownSP_IncreaseTangent0; //0x0014
	float SlowdownSP_IncreaseTangent1; //0x0018
	float SlowdownSP_DecreaseAmount; //0x001C
	float MaxSlowdownRate; //0x0020
	float MinSlowdownSP; //0x0024
	bool EnableDisableCrouchingPenalty; //0x0028
	bool DisableSP_DecreaseDuringJumpingCrouch; //0x0029
	bool DisableSP_DecreaseByKeyStroke; //0x002A
	bool DisableSP_DecreaseException_NoMovement; //0x002B
	float DisableSP_IncreaseDuration; //0x002C
	float DisableSP_IncreaseTangent0; //0x0030
	float DisableSP_IncreaseTangent1; //0x0034
	float DisableSP_DecreaseAmount; //0x0038
	float DisableSP_IncreaseDuration_InPenalty; //0x003C
	float DisableSP_IncreaseTangent0_InPenalty; //0x0040
	float DisableSP_IncreaseTangent1_InPenalty; //0x0044
	float DisableSP_DecreaseAmount_InPenalty; //0x0048
	float NoMovementTimeLimit; //0x004C
	float NoMovementDevationLimit; //0x0050
}; //Size: 0x0054
class cMoveMgrCrouchStaminaState
{
public:
	CrouchingMovementParameters m_Params; //0x0000
	float m_CrouchingSpeed; //0x0054
	float m_CurrentSlowdownSP; //0x0058
	float m_CurrentDisableSP; //0x005C
	__int32 m_IsInFullPenalty; //0x0060
	__int32 m_LastCrouchUpDownDirection; //0x0064
	uint32 m_ElapsedMilisecondsFromLastCrouchingDown; //0x0068
}; //Size: 0x0068
class __Object
{
public:
	DWORD Unknown; //0x0000
	D3DXVECTOR3 Pos1;
	D3DXVECTOR3 Pos2;
	//float xBound1; //0x0004
	//float yBound1; //0x0008
	//float zBound1; //0x000C
	//float xBound2; //0x0010
	//float yBound2; //0x0014
	//float zBound2; //0x0018
	char unknown28[172]; //0x001C
	D3DXVECTOR3 Pos; //0x00C8
	char unknown228[180]; //0x00E4
	CHAR Pad[4];
	D3DXVECTOR3 origin;
};
class NCon_VarTrack
{
public:
	unsigned int m_bInit;
	float m_fVal;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > m_strVal;
};
class CHARCREATESTRUCT
{
public:
	SFXCREATESTRUCT baseclass_0; //0x0000
	__int32 bIsPlayer; //0x0008
	__int32 bIsAI; //0x000C
	char byFXFlags[4]; //0x0010
	__int32 eModelId; //0x0014
	__int32 eFacePieceId; //0x0018
	__int32 eHeadPieceId; //0x001C
	__int32 eFigureType; //0x0020
	__int32 eModelSkeleton; //0x0024
	__int32 eCosmeticModelId; //0x0028
	__int32 nLevel; //0x002C
	unsigned int dwWeaponID; //0x0030
	int* hWeaponObj; //0x0034
	char nTrackers; //0x0038
	char nDimsTracker; //0x0039
private:
	char IgnoreMe1; //0x0039
	char IgnoreMe2; //0x0039
public:
	float fStealthPercent; //0x003C
	char nClientID; //0x0040
	char nUnitID; //0x0041
private:
	char IgnoreMe3; //0x0042
	char IgnoreMe4; //0x0043
	char IgnoreMe5; //0x0044
	char IgnoreMe6; //0x0045
	char IgnoreMe7; //0x0046
	char IgnoreMe8; //0x0047
public:
	unsigned __int64 nDamageFlags; //0x0048
	float fPitch; //0x0050
	float fYaw; //0X0054
	D3DXVECTOR3 vHitBoxDims; //0x0058
	D3DXVECTOR3 vHitBoxOffset; //0x0064
	__int32 nHealth; //0x0070
	__int32 nArmor; //0x0074
	bool bSnowballFrozen; //0x0078
	char nCamoIndex; //0x0079
private:
	char IgnoreMe9; //0x007A
	char IgnoreMe10; //0x007B
public:
	char strName[28]; //0x007C
	__int32 nTeam; //0x0098
	float fHPPercentage; //0x009C
	__int32 nNPCType; //0x00A0
	__int32 nBotID; //0x00A4
	bool bInfected; //0x00A8
private:
	char IgnoreMe11; //0x00A9
	char IgnoreMe12; //0x00AA
	char IgnoreMe13; //0x00AB
	char IgnoreMe14; //0x00AC
	char IgnoreMe15; //0x00AD
	char IgnoreMe16; //0x00AE
	char IgnoreMe17; //0x00AF
};
class CSpecialFXqq
{
public:
	CSpecialFX_vtblqq* __vftable;  //0x0000
	float m_fNextUpdateTime; //0x0004
	ILTClientDLL* m_pClientDE; //0x0008
	int* m_hObject; //0x000C
	union
	{
		__Object* m_hServerObject; //0x0010
		int* p_hServerObject; //0x0010
	};
	D3DXVECTOR3 m_vLastServPos; //0x0014
	D3DXVECTOR3 m_vVel; //0x0020
	unsigned int m_bWantRemove; //0x002C
	float m_fUpdateDelta; //0x0030
	char m_nMenuLayer; //0x0034
};
struct CLIENTFX_LINK_NODE
{
	unsigned int m_Link;
	CLIENTFX_LINK_NODE* m_pNext;
};
class CHitBox
{
public:
	int* m_hObject; //0x0000
	int* m_hModel; //0x0004
	D3DXVECTOR3 m_vDims; //0x0008
	D3DXVECTOR3 m_vOffset; //0x0014
	unsigned int m_FrameCode; //0x0020
	int* m_hBoundingBox; //0x0024
};
class cCharacterFX
{
public:
	CSpecialFXqq baseclass_0; //0x0000
	CHARCREATESTRUCT m_cs; //0x0038
	unsigned int m_bLeftFoot; //0x00E8
	unsigned int m_eLastSurface; //0x00EC
	float m_fNextDingTime[5]; //0x00F0
	char m_szInfoString[1024]; //0x0104
	HLTSOUND_tq* m_hWeaponLoopSound; //0x0504
	CLIENTFX_LINK_NODE m_AttachClientFX; //0x0508
	int m_pMovingFX; //0x0510 //CLIENTFX_LINK *
	int m_p3rdPersonDamageFX; //0x0514 //CLIENTFX_LINK *
	unsigned int m_nNum3rdPersonDamageFX; //0x00518
	int m_link3rdPersonInstFX; //0x051C //CLIENTFX_LINK *
	int m_AttachWeaponFX; //0x0520 //CLIENTFX_LINK *
	int* m_pStr; //0x0524
	D3DXVECTOR3 m_vStrPos; //0x0528
	D3DXVECTOR3 m_vLastPos; //0x0534
	unsigned __int64 m_nLastDamageFlags; //0x0540
	unsigned __int64 m_nInstantDamageFlags; //0x0548
	unsigned __int64 m_nProgressDamageEnable; //0x0550
	bool m_bWasPlayingSpecialDamageAni; //0x0558
	bool m_bPlayerDead; //0x0559
	bool m_bNoDamagedPlayer; //0x055A
private:
	char IgnoreMe0; //0x055B
public:
	unsigned int m_dwNoDamageTime; //0x055C
	bool m_bUpdateAttachments; //0x0560
private:
	char IgnoreMe1; //0x0561
	char IgnoreMe2; //0x0562
	char IgnoreMe3; //0x0563
public:
	CHitBox m_HitBox; //0x0564
	D3DXVECTOR4 m_rPlayerCameraRot; //0x058C
	int m_nCurrentWeaponID; //0x59C
	int* m_hCurrentWeaponObj; //0x05A0
	int m_nPlayerModID[5]; //0x5A4
	int m_bZoomedIn; //0x05B8
	D3DXVECTOR3 m_vPlayerCameraPos; //0x05BC
	bool m_bBombPlantProgress; //0x05C8
	bool m_bBombDefuseProgress; //0x05C9
	bool m_bDotSighted; //0X05CA
private:
	char IgnoreMe4; //0x05CB
public:
	unsigned __int16 m_nHealth; //0x05CC
	unsigned __int16 m_nArmor; //0x05CE
	int m_nTeam; //0x05D0
	int m_nID; //0x05D4
	bool m_bInfected; //0x05D8
	bool m_bHumanModel; //0x05D9
	bool m_bLocal; //0x05DA
	bool m_bIsEventEnemyModel; //0x05DB
	bool m_bNeedEnemyModelChange; //0x05DC
private:
	char IgnoreMe5; //0x05DD
	char IgnoreMe6; //0x05DE
	char IgnoreMe7; //0x05DF
};
class cMoveMgr
{
public:
	CMoveMgr_vtbl* __vtbl; //0x0000
	D3DXVECTOR3 m_DisplacementPushedByOtherObjects; //0x0004
	__int32 m_ClientMoveCode; //0x0010
	int* m_hObject; //0x0014
private:
	char pad_0018[12]; //0x0018
public:
	__int32 m_dwControlFlags; //0x0024
	__int32 m_dwLastControlFlags; //0x0028
	bool m_bCrouchingKeyPress; //0x002C
	bool m_bLastCrouchingKeyPress; //0x002D
private:
	char pad_002E[2]; //0x002E
public:
	__int32 m_eBodyContainerCode; //0x0030
	__int32 m_bBodyOnLadder; //0x0034
	__int32* m_hLadderObject; //0x0038
	__int32 m_bLoading; //0x003C
	D3DXVECTOR3 m_vSavedVel; //0x0040
	HPOLYq m_hStandingOnPoly; //0x004C
	__int32 m_bStandingOnObject; //0x0054
	__int32 m_eStandingOnSurface; //0x0058 enum SurfaceType
	D3DXVECTOR3 m_vGroundNormal; //0x005C
	__int32 m_bOnGround; //0x0068
	__int32 m_bOnLift; //0x006C
	__int32 m_bFalling; //0x0070
	__int32 m_bRunLock; //0x0074
	__int32 m_bDuckLock; //0x0078
	__int32 m_bCanDoFootstep; //0x007C
	__int32 m_bForceToServerPos; //0x0080
	__int32 m_bJumped; //0x0084
	__int32 m_bAllowJump; //0x0088
	__int32 m_bJumpRequested; //0x008C
	__int32 m_bJumpByJumpVolume; //0x0090
	D3DXVECTOR3 m_vJumpVolumeVel; //0x0094
	D3DXVECTOR3 m_vTotalCurrent; //0x00A0
	float m_fTotalViscosity; //0x00AC
	__int32 m_bGravityOverride; //0x00B0
	float m_fTotalContainerGravity; //0x00B4
	float m_fGravity; //0x00B8
	float m_fCurGravity; //0x00BC
	__int32 m_bFirstAniUpdate; //0x00C0
	__int32 m_bAllowMovement; //0x00C4
	ContainerCode m_eLastContainerCode; //0x00C8 enum ContainerCode
	ContainerCode m_eCurContainerCode; //0x00CC enum ContainerCode
	CContainerInfo m_Containers[16]; //0x00D0
	//private:
	//	char pad_00D4[636]; //0x00D4
	//public:
	__int32 m_nContainers; //0x0350

	NCon_VarTrack m_CV_SpectatorSpeedMul;//
	//private:
	//	char pad_0354[36]; //0x0354
	//public:
	cCharacterFX* m_pCharFX; //0x0378
	class PlayerClientAnimationUpdater* m_3rdPersonAnimator;//0x037C
	class PlayerClientMovementBuffer* m_MovementBuffer;//0x0380
	CTimer m_DamageTimer; //0x0384
	__int32 m_nKnockBackValue; //0x0394
	CTimer m_nStunnedTimer; //0x0398
	float m_fStunnedMovePenalty; //0x03A8
	__int32 m_bPlayerDimsInitted; //0x03AC
	D3DXVECTOR3 m_vCrouchDims; //0x03B0
	D3DXVECTOR3 m_vStandDims; //0x03BC
	__int32 m_bFrozen; //0x03C8
	D3DXVECTOR3 m_vFrozenPos; //0x03CC
	__int32 m_bSnowballFrozen; //0x3D8
	__int32 m_nCrouchDelay; //0x03DC
	cMoveMgr_CrouchState m_CrouchState; //0x03E0
	cMoveMgrCrouchStaminaState m_CrouchStaminaState; //0x0400
	float m_fLastForwardAccel; //0x046C
	float m_fLastRightAccel; //0x0470
	float m_fSpectModeAcc; //0x0474
	float m_fJumpDelay; //0x0478
	__int32 m_hStandAni; //0x047C
	__int32 m_hCrouchAni; //0x0480
	float m_fKeyVel; //0x0484
	char m_cDashFlag; //0x0488
	HLTSOUND_t* m_hsndIdleSound; //0x048C
	CTimer m_cIdleTimer; //0x0490
private:
	char pad_0488[38]; //0x04A0
public:
	float m_fCustomMovePenalty; //0x04D8
	__int32 m_bFirstUpdateInThisWorld; //0x04DC
	float m_fSpeedFactor; //0x04E0
	CTimer m_SlowTimer; //0x04E4
	float m_fSlowSpeedByDamage; //0x04F4
private:
	char pad_04F8[68]; //0x04F8
public:
	__int32 m_NumLastProcessedFrames; //0x053C
}; //Size: 0x0540
class CAttachButeMgrCBackPack
{
public:
	const char* m_szName; //0x0000
private:
	char pad_0004[124]; //0x0000
public:
	__int32 m_nType; //0x0080
private:
	char pad_0084[196]; //0x0084
public:
	float m_fMovePenalty; //0x0148
	float m_fMaxStamina; //0x014C
	float m_fDashSpeed; //0x0150
}; //Size: 0x0154
class CAttachButeMgrCGoggle
{
private:
	char pad_0000[128]; //0x0000
public:
	__int32 m_nType; //0x0080
private:
	char pad_0084[196]; //0x0084
public:
	__int32 m_nGoggleGearId; //0x0148
	float m_fMovePenalty; //0x014C
	float m_fMaxStamina; //0x0150
	float m_fDashSpeed; //0x0154
}; //Size: 0x0158
class CAttachButeMgrCFlag
{
private:
	char pad_0000[128]; //0x0000
public:
	__int32 m_nType; //0x0080
}; //Size: 0x0084
class CAttachButeMgr
{
private:
	char pad_0000[5600]; //0x0000
public:
	__int32 m_cAttachmentID; //0x15E0
	__int32 m_cRequirementID; //0x15E4
	__int32 m_cPVAttachmentID; //0x15E8
private:
	char pad_15EC[16]; //0x15EC
public:
	__int32 m_nGoggelGearId; //0x15FC
	CAttachButeMgrCBackPack* m_pBackPack; //0x1600
	__int32 m_cBackPackID; //0x1604
	CAttachButeMgrCGoggle** m_pGoggle; //0x1608
	__int32 m_cGoggleID; //0x160C
	CAttachButeMgrCFlag** m_pFlag; //0x1610
	__int32 m_cFlagID; //0x1614
}; //Size: 0x1618
class TRACERFX
{
public:
	int nId;
	char szName[32];
	char szTexture[64];
	int nFrequency;
	float fVelocity;
	float fWidth;
	float fInitialAlpha;
	float fFinalAlpha;
	float fLength;
	TVector3<float> vColor;
};
class SpecialFunc
{
public:
	eModSpecialFuncType eSFType;
	eModTargetType eSFTargetType;
	float fSFValue;
	float fSFDuration;
	float fSFProbability;
};
class MOD_ITEMs
{
public:
	unsigned int bInited;
	int nId;
	ModType eType;
	char* szSocket;
	char* szName;
	char* szZoomInSound;
	char* szZoomOutSound;
	char* szAttachModel[10];
	char* szPowerupModel;
	char* szPickUpSound;
	char* szRespawnSound;
	char* szZoomSpriteName;
	char* szHHModelSocket;
	char* szAttachHHModel[10];
	char* szFocusTexture;
	CButeListReader blrAttachSkins[10];
	CButeListReader blrPowerupSkins;
	CButeListReader blrAttachRenderStyles;
	CButeListReader blrHHAttachRenderStyles;
	CButeListReader blrPowerupRenderStyles;
	TVector3<float> vAttachScale;
	int nZoomLevel;
	int nPriority;
	unsigned int bIntegrated;
	float fPowerupScale;
	CButeListReader blrAttachHHSkin[10];
	TVector3<float> vAttachHHModelScale;
	ModKind eKinds;
	DotSightColorType eDSightColor;
	int nCrossHairA;
	int nCrossHairR;
	int nCrossHairG;
	int nCrossHairB;
	int nNumZoomFovs;
	float* aZoomFovs;
	float fZoomSpriteScale;
	int nTargetRange;
	SightSystemStyle eSightStyle;
	int nSilencerLevel;
	int nFlashHiderLevel;
	int nShotsPerClipPlus[10];
	int nMaxAmountPlus[10];
	int nSelectionAmountPlus[10];
	float fPerturbDecSpeedPer;
	float fPerturbIncSpeedPer;
	float fMinPerturbPer;
	float fRangePer;
	float fMaxCamRecoilPitchPer;
	float fBaseCamRecoilPitchPer;
	float fVectorsPerRoundPer;
	float fDamageMovePenaltyPer;
	float fDamageMovePenaltyDurationPer;
	TRACERFX* pTracerFX;
	float fMaxRandomPitch;
	float fBaseCamRecoilPitch;
	float fBaseCamRecoilAccelPitch;
	float fDynamicPerturbFactor;
	float fMaxCamRecoilWag;
	float fBaseCamRecoilWagL;
	float fBaseCamRecoilWagR;
	int nMinPerturb;
	int nDuckPerturb;
	float fFirePerturb;
	float fFireDuckPerturb;
	float fWalkPerturb;
	float fRunPerturb;
	float fPerturbIncSpeed;
	float fPerturbDecSpeed;
	float fDynamicLightRadius;
	char* pPVMuzzleFXName;
	char* pHHMuzzleFXName;
	float fInstDamage;
	float fInstDamagePer;
	float fFireAniRate;
	float fCameraSwayXSpeed;
	float fCameraSwayYSpeed;
	float fCameraSwayXFreq;
	float fCameraSwayYFreq;
	float fSelectAniRate;
	float fReloadAniRate;
	float fZoomedMinPerturb;
	float fZoomedMaxPerturb;
	float fZoomedPerturbIncSpeed;
	float fZoomedPerturbDesSpeed;
	int nGearId;
	float fMovePenalty;
	float fMaxStamina;
	float fDashSpeed;
	float fInfectedIncHPPer;
	std::vector<SpecialFunc, std::allocator<SpecialFunc> > vSpecialFunc;
	char* pSFCritFXName;
};
class CONVERT
{
public:
	int _nSlot;
	int _nType;
	int _nItemType;
	float _InstDamage;
	float _Alt_InstDamage;
	float _MovePenalty;
	float _FireRate;
	float _MinPerturb;
	float _MaxPerturb;
	float _DuckPerturb;
	float _MoveDuckPerturb;
	float _ZoomMinPerturb;
	float _ZoomMaxPerturb;
	float _TripleShotMinPerturb;
	float _TripleShotMaxPerturb;
	float _MaxRandomwag;
	float _MaxCamRecoilWag;
	float _BaseCamRecoilWagL;
	float _BaseCamRecoilWagR;
	float _MaxRandomPitch;
	float _MaxCamRecoilPitch;
	float _BaseCamRecoilPitch;
	float _BaseCamRecoilAccelPitch;
	float _TripleShotMaxCamRecoilPitch;
	float _TripleShotBaseCamRecoilPitch;
};
class IClientWeaponBase
{
public:
	IClientWeaponBase_vtbl* __vftable; //0x0000
};
class CClientWeapon_ModInfoStr
{
	__int32 nAttahcedModID; //0x0000
	int* hModModel; //0x0004
	unsigned int hModSocket; //0x0008
	D3DXVECTOR3 vModPosOffset; //0x000C
	D3DXVECTOR3 vModRotOffset; //0x0018
	bool bHaveMod; //0x0024
	bool bShowMod; //0x0025
private:
	char uselessstuff[2];
public:
	int nDotSightStyleID; //0x0028
};
class CClientWeapon
{
public:
	IClientWeaponBase* baseclass_0; //0x0000
	void(__cdecl* m_cbDeselect)(int, void*); //0x0004
	void* m_pcbData; //0x0008
	union
	{
		LTObject* pObject; //0x000C
		int* m_hObject;
	};
	unsigned int m_hBreachSocket; //0x0010
	CClientWeapon_ModInfoStr m_sPlayerHaveMods[5]; //0x0014
	__int32 m_nWeaponId; //0x00F0
	__int32 m_nAmmoId; //0x00F4
	WEAPON* m_pWeapon; //0x00F8
	AMMO* m_pAmmo; //0x00FC
	D3DXVECTOR3 m_vFlashPos; //0x0100
	D3DXVECTOR3 m_vFlashOffset; //0x010C
	float m_fFlashStartTime; //0x0118
	float m_fBobHeight; //0x011C
	float m_fBobWidth; //0x0120
	float m_fMovementPerturb; //0x0124
	float m_fFiringPerturb; //0x0128
	__int32 m_eLastFireType; //0x012C enum FireType
	__int32 m_bCanSetLastFire; //0x0130
	float m_fNextIdleTime; //0x0134
	__int32 m_bFire; //0x0138
	__int32 m_nAmmoInClip; //0x013C
	__int32 m_nNewAmmoInClip; //0x0140
	__int32 m_eState; //0x0144 enum WeaponState
	__int32 m_nSelectAni; //0x0148
	__int32 m_nDeselectAni; //0x014C
	__int32 m_nReloadAni; //0x0150
	__int32 m_nReloadAni1; //0x0154
	__int32 m_nPreReloadAni; //0x0158
	__int32 m_nPostReloadAni; //0x015C
	__int32 m_nDryFireAni; //0x0160
	__int32 m_nIdleAnis[2]; //0x0164
	__int32 m_nFireAni; //0x016C
	__int32 m_nAltFireAni; //0x0170
	__int32 m_nPreFireAni; //0x0174
	__int32 m_nPostFireAni; //0x0178
	__int32 m_nPreDashAni; //0x017C
	__int32 m_nDashAni; //0x0180
	__int32 m_nPostDashAni; //0x0184
	__int32 m_bFireKeyDownLastUpdate; //0x0188
	float m_fLastPitch; //0x018C
	float m_fLastYaw; //0x0190
	__int16 m_wIgnoreFX; //0x0194
	bool m_bWeaponDeselected; //0x0196
	bool m_bDisabled; //0x0197
	__int32 m_bVisible; //0x0198
	LTRotation m_rCamRot; //0x019C
	TVector3<float> m_vCamPos; //0x0AC
	__int32* m_hLoopSound; //0x1B8
	__int32 m_nLoopSoundId; //0x01BC
	__int32 m_nTracerNumber; //0x01C0
	class CLIENTFX_LINK* m_PVAttachClientFX[10]; //0x01C4
	bool m_bPVAttachClientFXHidden[10]; //0x01EC
private:
	char dsffdsfds[2];
public:
	class CLIENTFX_LINK* m_MuzzleFlashFX;//0x01F8
	bool m_bAutoSwitchEnabled; //0x01FC
	bool m_bAutoSwitch; //0x01FD
private:
	char pad_01FE[10]; //0x01FE
public:
	__int32 m_bPaused; //0x0208
	float m_fPerturbRecoil; //0x020C
	__int32 m_nPerturbDecFactor; //0x0210
	__int32 m_nRapidFiringCount; //0x0214
	LTObject* m_hVictimHitBox; //0x0218
	LTObject* m_hVictim; //0x021C
	//__int32* m_hVictimHitBox; //0x0218
	//__int32* m_hVictim; //0x021C
	bool m_bHitMe; //0x0220
	bool m_bHitPlayer; //0x0221
private:
	char pad_0222[2]; //0x0222
public:
	__int32 m_eModelNode; //0x0224 enum ModelNode
	__int32 m_eModelSkeleton; //0x0228 enum ModelSkeleton
	D3DXVECTOR3 m_vImpactPoint; //0x022C
	float m_fImpactDistance; //0x0238
	D3DXVECTOR3 m_vNormal; //0x023C
	D3DXVECTOR3 m_vFirePathForMultipleVectorsPerRoundBug; //0x0248
	__int32 m_bImpactPointNarrow; //0x0254
	__int32 m_n3PWeaponFireTime; //0x0258
	bool m_bTripleShotMode; //0x025C
	bool m_bContinuousFireMode; //0x025D
private:
	char pad_025E[2]; //0x0240
public:
	__int32 m_nTripleShotNum; //0x0260
	__int32 m_bTripleShotStart; //0x0264
	__int32 m_bTripleShotDelayStartTime; //0x0268
	__int32 m_nTripleShotSelectDelayStartTime; //0x026C
	float m_fDynamicPerturbFactor; //0x0270
	__int32 m_nWeaponIndex; //0x0274
	__int32 m_nAmmoIndex; //0x0278
	__int32 m_bReloadFire; //0x027C
	float m_fLastFired; //0x0280
	float m_fLastAltFire; //0x0284
	__int32 m_bInitClientWeapon; //0x0288
	__int32 eMilitaryPdaState; //0x028C enum eMiliPDAScaningState
	char pad_0290[116]; //0x0290
	D3DXVECTOR3 m_vLeftFlashPos; //0x0304
	D3DXVECTOR3 m_vLeftFlashOffset; //0x0310
	float m_fLeftFlashStartTime; //0x031C
	class CLIENTFX_LINK* m_LeftMuzzleFlashFX; //0x0320
	int32_t m_bIsDualLeftFire; //0x0324
	unsigned int m_hHandModel; //0x0328
	bool m_bForceUpdateSelect; //0x032C
	bool m_bAutoFire; //0x032D
private:
	char pad_032E[2]; //0x032E
public:
	int32_t m_3rdPersonState; //0x0330 CPWeaponStatusTyps
}; //Size: 0x0338

class CClientWeaponMgr
{
public:
	IClientWeaponBase** m_apClientWeapon; //0x0000
	IClientWeaponBase** m_apClientEmotion; //0x0004
	__int32 m_nMaxWeapons; //0x0008
	__int32 m_iCurrentWeapon; //0x000C
	CClientWeapon* m_ClientWeapon; //0x0010
	bool m_bWeaponsEnabled; //0x0014
	bool m_bWeaponsVisible; //0x0015
	char pad_0016[2]; //0x0016
	__int32 m_nDefaultWeaponId; //0x0018
	__int32 m_nHolsterWeaponId; //0x001C
	__int32 m_nRequestedWeaponId; //0x0020
	__int32 m_nRequestedAmmoId; //0x0024
	__int32 m_nLastWeaponId; //0x0028
	__int32 m_bWeaponsPaused; //0x002C
	__int32 m_nWeaponOrder; //0x0030 [7][32]
	char pad_0034[892]; //0x0034
	__int32 m_nLastChoosedWeaponID; //0x03B0 [7]
	char pad_03B4[24]; //0x03B4
	__int32 m_nTempChoosedWeaponID; //0x03CC [7]
	char pad_03D0[24]; //0x03D0
	__int32 m_nHaveWeaponCount; //0x03E8
	__int32 m_nWeaponIndex; //0x03EC
	__int32 m_nTempChoosedWeaponIndex; //0x03F0 [7]
}; //Size: 0x03F4

class CActivationData
{
public:
	D3DXVECTOR3 m_vPos; //0x0000
	D3DXVECTOR4 m_rRot; //0x000C
	char m_nType; //0x001C
private:
	char IgnoreMe[3];
public:
	LTObjRefq m_hTarget; //0x0020
	D3DXVECTOR3 m_vIntersect; //0x0030
	char m_nSurfaceType; //0x003C
private:
	char IgnoreMe2[3];
};
class CTargetMgr;
struct /*VFT*/ CTargetMgr_vtbl
{
	void(__thiscall* Init)(CTargetMgr* pthis);
	void(__thiscall* Update)(CTargetMgr* pthis);
	LTObject* (__thiscall* GetTargetObject)(CTargetMgr* pthis);
	float(__thiscall* GetTargetRange)(CTargetMgr* pthis);
	int(__thiscall* GetTargetActivateType)(CTargetMgr* pthis);
	const wchar_t* (__thiscall* GetTargetString)(CTargetMgr* pthis);
	const char* (__thiscall* GetDebugString)(CTargetMgr* pthis);
	CActivationData* (__thiscall* GetActivationData)(CTargetMgr* pthis, CActivationData* result);
	bool(__thiscall* IsMoveTarget)(CTargetMgr* pthis);
	bool(__thiscall* CanActivateTarget)(CTargetMgr* pthis);
	bool(__thiscall* IsTargetInRange)(CTargetMgr* pthis);
	bool(__thiscall* IsGadgetActivatable)(CTargetMgr* pthis, LTObject*);
	bool(__thiscall* IsTargetGadgetActivatable)(CTargetMgr* pthis);
	void(__thiscall* LockTarget)(CTargetMgr* pthis, LTObject*);
	LTObject* (__thiscall* GetLockedTarget)(CTargetMgr* pthis);
};
class CTargetMgr
{
public:
	CTargetMgr_vtbl* __vtbl; //0x0000
	int* m_hTarget; //0x0004
	char pad_0000[30]; //0x0008
	int* m_hLockedTarget; //0x0024
	float m_fTargetRange; //0x0028
	char m_szDebugString[1024]; //0x002C
	int16_t m_nString; //0x042C
private:
	char IngoreMe1[2]; //0x042E
public:
	__int32 m_nTargetActivatetype; //0x0430
	bool m_bMoveTarget; //0x0434
	bool m_bCanActivate; //0x0435
	bool m_bFirstUpdate; //0x0436
private:
	char IngoreMe2[1]; //0x0434
public:
	CActivationData* m_ActivationData; //0x0438
};
class CPlayerCamera
{
public:
	LTObject* m_hTarget; //0x0000
	ILTClientDLL* m_pClientDE;
	D3DXVECTOR4 m_rRotation; //0x0008
	D3DXVECTOR3 m_vPos; //0x0018
	D3DXVECTOR3 m_vLastTargetPos; //0x0024
	D3DXVECTOR3 m_vLastOptPos; //0x0030
	D3DXVECTOR4 m_rLastTargetRot; //0x003C
	__int32 m_eOrientation; //0x004C enum CPlayerCamera::CameraState
	__int32 m_eSaveOrientation; //0x0050 enum CPlayerCamera::CameraState
	__int32 m_eCameraMode; //0x0054 enum CPlayerCamera::CameraMode
	__int32 m_eSaveCameraMode; //0x0058 enum CPlayerCamera::CameraMode
	__int32 m_ePointType; //0x005C enum CPlayerCamera::CameraPoint
	D3DXVECTOR3 m_Opt; //0x0060
	float m_CameraDistBack; //0x006C
	float m_CameraDistUp; //0x0070
	float m_CameraDistDiag; //0x0074
	__int32 m_bSlide; //0x0078
	D3DXVECTOR3 m_TargetChaseOffset; //0x007C
	D3DXVECTOR3 m_TargetPointAtOffset; //0x0088
	D3DXVECTOR3 m_TargetStaticChaseOffset; //0x0094
	float m_fCustomOffset; //0x00A0
	float m_CircleHeightOffset; //0x00A4
	float m_CircleRadius; //0x00A8
	float m_CircleTime; //0x00AC
	float m_GoingFirstPersonStart; //0x00B0
	float m_GoingFirstPersonTransition; //0x00B4
	__int32 m_bStartCircle; //0x00B8
	float m_CircleStartTime; //0x00BC
	float m_SaveAnglesY; //0x00C0
	__int32 m_bRestoreFirstPerson; //0x00C4
	D3DXVECTOR3 m_TargetFirstPersonOffset; //0x00C8
	__int32* m_hCollisionObject; //0x00D4
	__int32 m_bPlayerDead; //0x00D8
	__int32 m_bModelView; //0x00DC
	float m_fCameraDist; //0x00E0
	__int32 m_hEyeSocket; //0x00E4
	__int32 m_hEyeNode; //0x00E8
	bool m_bFirstChaseTargetSet; //0x00EC
	bool m_bFirstChase; //0x00ED
	char pad_00EE[2]; //0x00EE
	D3DXVECTOR3 m_vFirstChasePos; //0x00F0
	D3DXVECTOR3 m_ScriptStartPos; //0x00FC
	D3DXVECTOR3 m_ScriptTargetPos; //0x0108
	float m_fScriptMoveTime; //0x0114
	float m_fScriptStartTime; //0x0118
}; //Size: 0x011C
class cPlayerMgr;
struct cPlayerMgr_vtbl
{
	void(__thiscall* cPlayerMgr1)(cPlayerMgr* pThis);
	unsigned int(__thiscall* Init)(cPlayerMgr* pThis);
	void(__thiscall* Term)(cPlayerMgr* pThis);
	void(__thiscall* OnEnterWorld)(cPlayerMgr* pThis);
	void(__thiscall* OnExitWorld)(cPlayerMgr* pThis);
	void(__thiscall* Update)(cPlayerMgr* pThis);
	void(__thiscall* UpdatePlayerInfoTransmition)(cPlayerMgr* pThis, const ClientFixedFrameUpdateInfo*);
	unsigned int(__thiscall* OnMessage)(cPlayerMgr* pThis, char, ILTMessage_Read*);
	unsigned int(__thiscall* OnCommandOn)(cPlayerMgr* pThis, int);
	unsigned int(__thiscall* OnCommandOff)(cPlayerMgr* pThis, int);
	CPlayerStats* (__thiscall* GetPlayerStats)(cPlayerMgr* pThis);
	void(__thiscall* UpdateCamera)(cPlayerMgr* pThis);
	void(__thiscall* DoActivate)(cPlayerMgr* pThis);
	void(__thiscall* TurnOffAlternativeCamera)(cPlayerMgr* pThis, char);
	void(__thiscall* SetExternalCamera)(cPlayerMgr* pThis, unsigned int);
	void(__thiscall* CheckChaseNextPlayer)(cPlayerMgr* pThis, int*); //int*->LTObject*
	int* (__thiscall* GetDeadCamTargetObj)(cPlayerMgr* pThis);//int*->LTObject*s
	int(__thiscall* GetDeadCamtargetID)(cPlayerMgr* pThis);
	int(__thiscall* GetTargetPlayerUID)(cPlayerMgr* pThis);
	void(__thiscall* SetPlayerKicked)(cPlayerMgr* pThis, int);
	void(__thiscall* SetBombPlantFlag)(cPlayerMgr* pThis, bool);
	bool(__thiscall* GetBombPlantFlag)(cPlayerMgr* pThis);
	void(__thiscall* SetLifeChargingFlag)(cPlayerMgr* pThis, bool);
	bool(__thiscall* GetLifeChargingFlag)(cPlayerMgr* pThis);
	void(__thiscall* SetAmmoChargingFlag)(cPlayerMgr* pThis, bool);
	bool(__thiscall* GetAmmoChargingFlag)(cPlayerMgr* pThis);
	void(__thiscall* DeathProcess)(cPlayerMgr* pThis);
	void(__thiscall* SetFirstDeadCameraMode)(cPlayerMgr* pThis, bool);
	void(__thiscall* SetScanEnemy)(cPlayerMgr* pThis, bool);
	bool(__thiscall* IsScanningEnemy)(cPlayerMgr* pThis);
	void(__thiscall* SetScanMilitaryPDA)(cPlayerMgr* pThis);
	bool(__thiscall* IsEnableRadarBattery)(cPlayerMgr* pThis);
	int(__thiscall* GetScanMilitaryBatteryGauge)(cPlayerMgr* pThis);
	bool(__thiscall* GetPDAState)(cPlayerMgr* pThis);
	void(__thiscall* UseWeaponRadarBatteryGauge)(cPlayerMgr* pThis);
	void(__thiscall* SetMilitaryPdaScaning)(cPlayerMgr* pThis, bool);
	bool(__thiscall* GetMilitaryPdaScaning)(cPlayerMgr* pThis);
	void(__thiscall* SetBomberPlantFlag)(cPlayerMgr* pThis, bool, unsigned int);
	bool(__thiscall* CanBomberPlant)(cPlayerMgr* pThis);
	void(__thiscall* SetBomberPlant)(cPlayerMgr* pThis, bool);
	void(__thiscall* SetUpBomberPlant)(cPlayerMgr* pThis, unsigned int, unsigned int);
	void(__thiscall* InstallMOAB)(cPlayerMgr* pThis, bool);
	bool(__thiscall* IsInstallMOAB)(cPlayerMgr* pThis);
	int(__thiscall* GetTeam)(cPlayerMgr* pThis);
	void(__thiscall* SetFastRespawn)(cPlayerMgr* pThis, bool);
	bool(__thiscall* RemoveTarget)(cPlayerMgr* pThis, CAM_TARGET_INFO*);
	void(__thiscall* HandleMsgShakeScreen)(cPlayerMgr* pThis, ILTMessage_Read*);
	void(__thiscall* HandleMsgPlayerStateChange)(cPlayerMgr* pThis, ILTMessage_Read*);
	void(__thiscall* HandleMsgClientPlayerUpdate)(cPlayerMgr* pThis, ILTMessage_Read*);
	void(__thiscall* HandleMsgWeaponChange)(cPlayerMgr* pThis, ILTMessage_Read*);
	void(__thiscall* HandleMsgPlayerDamage)(cPlayerMgr* pThis, ILTMessage_Read*);
	void(__thiscall* HandleMsgPlayerOrientation)(cPlayerMgr* pThis, ILTMessage_Read*);
	void(__thiscall* HandleMsgChangeWorldProperties)(cPlayerMgr* pThis, ILTMessage_Read*);
	void(__thiscall* HandleMsgGadgetTarget)(cPlayerMgr* pThis, ILTMessage_Read*);
	void(__thiscall* HandleMsgAddPusher)(cPlayerMgr* pThis, ILTMessage_Read*);
	void(__thiscall* HandleMsgCustomMovePenalty)(cPlayerMgr* pThis, ILTMessage_Read*);
	void(__thiscall* UpdateCameraZoom)(cPlayerMgr* pThis);
	void(__thiscall* UpdateCameraDisplacement)(cPlayerMgr* pThis);
	void(__thiscall* UpdateCameraShake)(cPlayerMgr* pThis, TVector3<float>*);
	void(__thiscall* UpdateCameraSway)(cPlayerMgr* pThis);
	void(__thiscall* InitPlayerCamera)(cPlayerMgr* pThis);
	unsigned int(__thiscall* UpdatePlayerCamera)(cPlayerMgr* pThis);
	void(__thiscall* UpdateCameraPosition)(cPlayerMgr* pThis);
	void(__thiscall* UpdateMultiplayerCameraPosition)(cPlayerMgr* pThis);
	void(__thiscall* CalculateCameraRotation)(cPlayerMgr* pThis);
	unsigned int(__thiscall* UpdateCameraRotation)(cPlayerMgr* pThis);
	void(__thiscall* UpdatePlayerInfo)(cPlayerMgr* pThis, bool);
	unsigned int(__thiscall* UpdateAlternativeCamera)(cPlayerMgr* pThis);
	void(__thiscall* UpdatePlayerRotation)(cPlayerMgr* pThis);
	void(__thiscall* InitTargetMgr)(cPlayerMgr* pThis);
};
class cPlayerMgr
{
public:
	cPlayerMgr_vtbl* __vftable; //0x0000
	CHeadBobMgr* m_pHeadBobMgr; //0x0004
	CCameraOffsetMgr* m_pCameraOffsetMgr; //0x0008
	CGadgetDisabler* m_pGadgetDisabler; //0x000C
	cMoveMgr* m_pMoveMgr; //0x0010
	CAttachButeMgr* m_pAttachButeMgr; //0x0014
	CClientWeaponMgr* m_pClientWeaponMgr; //0x0018
	CTargetMgr* m_pTargetMgr; //0x001C
	class CPlayerViewAttachmentMgr* m_pPVAttachmentMgr; //0x0020
	class PlayerClientAnimationUpdater* m_3rdPersonAnimator; //0x0024
	class PlayerClientMovementBuffer* m_pMovementBuffer; //0x0028
	float m_fYawBackup; //0x002C
	float m_fPitchBackup; //0x0030
	__int32 m_dwPlayerFlags; //0x0034
	__int32 m_ePlayerState; //0x0038 enum PlayerState // -> PlayerStatus
	__int32 m_ePlayerExtState; //0x003C enum PlayerExtState
	int32_t m_bLastSent3rdPerson; //0x0040
	D3DXVECTOR4 m_rRotation; //0x0044
	float m_fPitch; //0x0054
	float m_fYaw; //0x0058
	float m_fRoll; //0x005C
	float m_fFireJitterPitch; //0x0060
	float m_fFireJitterYaw; //0x0064
	__int32 m_bFirstWag; //0x0068
	__int32 m_nFireJitterTime; //0x006C
	float m_fFireBackJitter; //0x0070
	float m_fPlayerPitch; //0x0074
	float m_fPlayerYaw; //0x0078
	float m_fPlayerRoll; //0x007C
	D3DXVECTOR4 m_rStaticRotation; //0x0080
	D3DXVECTOR3 m_vStaticCameraPos; //0x0090
	float m_fModelAttachPitch; //0x009C
	float m_fModelAttachYaw; //0x00A0
	float m_fModelAttachRoll; //0x00A4
	__int32 m_bAllowPlayerMovement; //0x00A8
	__int32 m_bLastAllowPlayerMovement; //0x00AC
	__int32 m_bWasUsingExternalCamera; //0x00B0
	__int32 m_bUsingExternalCamera; //0x00B4
	__int32 m_bCamIsListener; //0x00B8
	__int32 m_bRestoreOrientation; //0x00BC
	__int32 m_bCameraPosInited; //0x00C0
	__int32 m_bStartedPlaying; //0x00C4
	__int32 m_bPlayingVideo; //0x00C8
	D3DXVECTOR3 m_vShakeAmount; //0x00CC
	__int32 m_bSpectatorMode; //0x00D8
	__int32 m_bInvisibleMode; //0x00DC
	D3DXVECTOR3 m_vCurModelGlow; //0x00E0
	D3DXVECTOR3 m_vMaxModelGlow; //0x00EC
	D3DXVECTOR3 m_vMinModelGlow; //0x00F8
	float m_fModelGlowCycleTime; //0x0104
	__int32 m_bModelGlowCycleUp; //0x0108
	ContainerCode m_eCurContainerCode; //0x010C enum ContainerCode
	float m_fContainerStartTime; //0x0110
	float m_fFovXFXDir; //0x0114
	__int32 m_nSoundFilterId; //0x0118
	__int32 m_nZoomView; //0x011C
	__int32 m_bZooming; //0x0120
	__int32 m_bZoomingIn; //0x0124
	float m_fSaveLODScale; //0x0128
	__int32 m_bCamera; //0x012C
	D3DXVECTOR3 m_vSVLightScale; //0x0130
	union
	{
		LTObject* pObject; //0x013C
		__int32* m_hCamera; //0x013C
	};

	//__int32* m_hCamera; //0x013C
	CPlayerCamera* m_pPlayerCamera; //0x0140
	__int32 m_bCameraAttachedToHead; //0x0144
	__int32 m_bFirstUpdate; //0x0148
	__int32 m_bPlayerUpdated; //0x014C
	__int32 m_bHoldingMouseLook; //0x0150
	__int32 m_nPlayerInfoChangeFlags; //0x0154
	float m_fPlayerInfoLastSendTime; //0x0158
	__int32 m_nPlayerInfoLastSendFrame; //0x015C
	__int32 m_nPlayerInfoLastSendTimeMS; //0x0160
	__int32 m_nPlayerInfoLastQueuedVisibleGameTimeMS; //0x0164
	__int32 m_bUseWorldFog; //0x0168
	int* m_hContainerSound; //0x016C
	float m_fDamage[12]; //0x0170
	float m_fLastDamageSector; //0x01A0
	__int32 m_eLastHitLocation; //0x01A4 enum HitLocation
	__int32 m_eDamageType; //0x01A8 enum DamageType
	float m_fLastDamage; //0x01AC
	bool m_bServerAccurateRotation; //0x01B0
	bool m_bSendCameraOffsetToServer;//0x01B1
	__int16 m_nPreGadgetWeapon;//0x01B2
	bool m_bChangingToGadget;//0x01B4
	bool m_bSwitchingWeapons;//0x01B5
private:
	char pad_01B6[2]; //0x01B6
public:
	float m_fMultiplayerDeathCamMoveTimer; //0x01B8
	float m_fMultiAttachDeathCamTimer; //0x01BC
	__int32 m_bReloadClipAfterZoom; //0x01C0
	bool m_bInterRoundWaitingMode; //0x01C4
	bool m_bJitterYaw; //0x01C5
	bool m_bJitterPitch; //0x01C6
	bool m_bHaveToZoomOut; //0x01C7
	__int32 m_nZoomOutStartTime; //0x01C8
	__int32 m_bPlayerKicked; //0x01CC
	__int32 m_nKickStartTime; //0x01D0
	__int32 m_nKickReason; //0x01D4
	bool m_bDotSighted; //0x01D8
	bool m_bFire; //0x01D9
	bool m_bFallLandDeath; //0x01DA
	bool m_bAIFreeze; //0x01DB
	bool m_bPlayerInfected; //0x01DC
	bool m_bCanBombPlant; //0x01DD
	bool m_bCanRechargeHealth; //0x01DE
	bool m_bCanRechargeAmmo; //0x01DF
	D3DXVECTOR3 m_vStartPoint; //0x01E0
	__int32 m_hEyeSocket; //0x01EC
	__int32 m_hFlashSocket; //0x01F0
	__int32 m_hPlayerHeadNode; //0x01F4
	__int32 m_nTeam; //0x01F8
	class CTriggerFX* m_pkCurrentSupplyItem; //0x01FC
	D3DXVECTOR3 m_vDeathVec; //0x0200
	FireType m_eFireType; //0x020C enum FireType
	__int32 m_nFireRandomSeed; //0x0210
	__int32 m_bSentRechargeReq; //0x0214
	int32_t m_nRechargeResult; //0x0218
	class CTriggerFX* m_pkRechargeObj; //0x021C
	D3DXVECTOR4 m_rLastCameraRot; //0x0220
	D3DXVECTOR4 m_rTargetCameraRot; //0x0230
	D3DXVECTOR4 m_rOriCameraRot; //0x0240
	D3DXVECTOR3 m_vLastCameraPos; //0x0250
	D3DXVECTOR3 m_vTargetCameraPos; //0x025C
	D3DXVECTOR3 m_vOriCameraPos; //0x0268
	int32_t m_bCinematic; //0x0274
	LTObject* m_hLastCameraTarget; //0x0278
	int32_t m_bCinecameraForceUpdate; //0x027C
	float m_fMouseX; //0x0280
	float m_fMouseY; //0x0284
	bool m_bCinematicClientUpdate; //0x0288
	bool m_bShowSelfCharacter; //0x0289
	bool m_bRechargeTriggerOn; //0x028A
	bool undefined10; //0x028B
	D3DXVECTOR3 m_vLocalObjDims; //0x028C
	int32_t m_bCheckObjDims; //0x0298
	int32_t m_nLastDamageAmmo; //0x029C
	char pad_02A0[84]; //0x02A0
	CCBAPlayerStats* m_stats; //0x02F4
	char pad_02F8[472]; //0x02F8
	int32_t m_eFreeCamerMode; //0x04D0 //CCBAPlayerMgr__FreeCameraMode
	__inline CClientWeapon* GetCurrentWeapon() { if (m_pClientWeaponMgr && m_pClientWeaponMgr->m_ClientWeapon)return m_pClientWeaponMgr->m_ClientWeapon; return 0; }
}; cPlayerMgr* m_pPlayerMgr;

class CCBAPlayerMgr
{
public:
	cPlayerMgr BaseClass0;
	char pad_02A0[72]; //0x02A0
	CCBAPlayerStats* m_stats; //0x02E8
	char pad_02EC[440]; //0x02EC
	float m_fAimYaw; //0x04A4
	float m_fAimPitch; //0x04A8
	float m_fTwistYaw; //0x04AC
	float m_fAimPitchVel; //0x04B0
	float m_fTwistYawVel; //0x04B4
	float m_fAimPitchAccel; //0x04B8
	float m_fTwistYawAccel; //0x04BC
	__int32 m_bDefuseEnable; //0x04C0
	CCBAPlayerMgr__FreeCameraMode m_eFreeCamerMode; //0x04C4 CCBAPlayerMgr::FreeCameraMode
	CCBAPlayerMgr__FreeCameraMode m_eSaveFreeCamerMode; //0x04C8 CCBAPlayerMgr::FreeCameraMode
	CCBAPlayerMgr__DeadCameraMode m_eDeadCameraMode; //0x04CC CCBAPlayerMgr::DeadCameraMode
	CCBAPlayerMgr__ObserverMode m_eObserverMode; //0x04D0 CCBAPlayerMgr::ObserverMode
	__int32 m_bFirstDeadCameraMode; //0x04D4
	CAM_TARGET_INFO* m_pDeadCameraTarget; //0x04D8
	cCLIENT_INFO* m_pOtherClientTarget; //0x04DC //CLIENT_INFO
	BOT_INFO* m_pOtherBotTarget; //0x04E0
	int* m_hTarget;
	__int32 m_bShopTradeable; //0x04E8
	__int32 m_nBombZoneNumber; //0x04EC
	__int32 m_nPlayerDeadTime; //0x04F0
	__int32 m_bHasPlayerDeadTime; //0x04F4
	__int32 m_nRespawnWaitStartTime; //0x04F8
	__int32 m_nRespawnDelayTime; //0x04FC
	__int32 m_bRespawnCount; //0x0500
	float m_fCameraReverseEndTime; //0x0504
	__int32 m_bSendCameraRotToServer; //0x0508
	float m_fCameraYaw; //0x050C
	bool m_bBombPlantFlag; //0x0510
	bool m_bLifeChargingFlag; //0x0511
	bool m_bAmmoChargingFlag; //0x0512
	bool m_bChangeDeadCamMode; //0x0513
	bool m_bEnemyCamera; //0x0514
	bool m_bShowBody; //0x0515
	bool m_bHideBody; //0x0516
	bool m_bAINonSolid; //0x0517
	bool m_bOnceAtivateTriggerLock; //0x0518
	bool m_bRotateCamera; //0x0519
	bool Undefined1; //0x051A
	bool Undefined2; //0x051B
	float m_OldfPitch; //0x051C
	float m_OldfYaw; //0x0520
	float m_OldfRoll; //0x0524
	__int32 m_bFirstchase; //0x0528
	__int32 qm_hPlayerHeadNode; //0x052C
	bool m_bScanEnemy; //0x0530
	bool m_bHoldingFlag; //0x0531
	bool m_bHoldingGold; //0x0532
	bool m_bHoldingSabotageBomb; //0x0533
	bool m_bMilitaryPdaScaning; //0x0534
	bool m_bBomberPlant; //0x0535
	bool undefined3; //0x0536
	bool undefined4; //0x0537
	__int32 m_dwBomberPlantTime; //0x0538
	bool m_bCanBomberPlant; //0x053C
	bool m_bInstallMOAB; //0x053D
	bool undefined5; //0x053E
	bool undefined6; //0x053F
	__int32 m_nCurrentMutationItemID; //0x0540
	D3DXVECTOR4 m_rLastCameraRotation; //0x0544
	D3DXVECTOR3 qm_vLastCameraPos; //0x0554
	D3DXVECTOR4 m_rSaveCamRotOfDeadTime; //0x0560
	bool bDebugObjectPos; //0x0570
	bool m_bActivateTriggerOn; //0x0571
	bool m_bActivateSend; //0x0572
	bool m_bLastFrozenState; //0x0573
	__int32 m_hAmmoSupplyStationGauge; //0x0574
	__int32 m_hsndChoiceVIPSound; //0x0578
	bool m_bUseFastRespawn; //0x057C
	bool m_bRespawnRequested; //0x057D
}; //Size: 0x0580
//CCBAPlayerMgr* m_pPlayerMgr;




typedef cCLIENT_INFO* (__thiscall* lpGetPlayerByIndex)(unsigned long ulThis, INT index); lpGetPlayerByIndex GetPlayerByIndex;
typedef cCLIENT_INFO* (__thiscall* lpGetLocalPlayer)(unsigned long ulThis); lpGetLocalPlayer GetLocalPlayer;