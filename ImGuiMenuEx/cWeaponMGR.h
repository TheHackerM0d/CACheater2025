extern D3DCOLOR FLOAT4TOD3DCOLOR(float Col[]);


namespace cheat
{
	namespace weapon
	{
		bool BulletTracer = false;
		bool EDistance = false;
		bool BackCam = true;

		bool NoSpread = false;
		bool NoRecoil = false;
		bool LegitFire = false; float LegitFires = 0.0f;
		bool RageFire = false;
		bool ZoomTime = false;
		bool MovePenalty = false; int MovePenaltys = 0;

		bool CrosshairColor = 0; float Crosshair[] = { 1.000f, 0.569f, 0.824f, 1.000f };

		bool NoReload = false;

		bool RemoveAnimation = false;

		bool MultiBullet = false;
		int MultiBullets = 1;

		namespace Backups
		{
			namespace Weapons
			{
				bool DefaultWepMgrEffect = false;
				float DefaultWeapon[20];
				float DefaultSpread[20][2000];
				float DefaultRecoil[20][2000];
				float DefaultOther[20][2000];
			}
		}
		namespace Teleport
		{
			bool Activation = false;
			int PosX = 30;
			int PosY = 50;
			int PosZ = 0;
		}
	} 
}


class CParticleMuzzleFX
{
public:
	char pad_0000[32]; //0x0000
	__int32 nId; //0x0020
	char pad_0024[24]; //0x0024
	float fLength; //0x003C
	float fDuration; //0x0040
	float fRadius; //0x0044
	float fMaxScale; //0x0048
	__int32 nNumParticles; //0x004C
	char pad_0050[64]; //0x0050
	__int32 bAdditive; //0x0090
	__int32 bMultiply; //0x0094
};
class CScaleFX
{
public:
	__int32 nId; //0x0000
	__int32 eType; //0x0004 enum ScaleFXType
	char pad_0008[184]; //0x0008
	__int32 bUseColors; //0x00C0
	__int32 bUseLight; //0x00C4
	__int32 bLoop; //0x00C8
	__int32 bAlignToSurface; //0x00CC
	__int32 bNoZ; //0x00D0
	__int32 bReallyClose; //0x00D4
	__int32 bAdditive; //0x00D8
	__int32 bMultiply; //0x00DC
	__int32 bFaceCamera; //0x00E0
	char pad_00E4[4]; //0x00E4
	__int32 bRotate; //0x00E8
	char pad_00EC[24]; //0x00EC
	float fInitialAlpha; //0x0104
	float fFinalAlpha; //0x0108
	float fDirOffset; //0x010C
	float fDirROffset; //0x0110
	float fDirUOffset; //0x0114
	float fMinRotVel; //0x0118
	float fMaxRotVel; //0x011C
	char pad_0120[12]; //0x0120
	float fLifeTime; //0x012C
	float fDelayTime; //0x0130
}; //Size: 0x0134
class DLIGHTFX
{
public:
	__int32 nId; //0x0000
	char pad_0004[44]; //0x0004
	float fMinRadius; //0x0030
	float fMaxRadius; //0x0034
	float fMinTime; //0x0038
	float fMaxTime; //0x003C
	float fRampUpTime; //0x0040
	float fRampDownTime; //0x0044
}; //Size: 0x0048
class CMuzzleFX
{
public:
	char pad_0000[32]; //0x0000
	__int32 nId; //0x0020
	float fDuration; //0x0024
	CParticleMuzzleFX* pPMuzzleFX; //0x0028
	CScaleFX* pScaleFX; //0x002C
	DLIGHTFX* pDLightFX; //0x0030
}; //Size: 0x0034
class WEAPON
{
public:
	__int32 bInited; //0x0000
	__int32 nId; //0x0004
	__int32 nClientWeaponType; //0x0008
	__int32 nAniType; //0x000C
	__int32 nLowerAniType; //0x0010
	D3DXVECTOR3 vPos; //0x0014
	D3DXVECTOR3 vMuzzlePos; //0x0020
	D3DXVECTOR3 vBreachOffset; //0x002C
	D3DXVECTOR3 vLeftHandRotOffset; //0x0044
	const char* szName; //0x0050
	const char* szPVModel; //0x0054
	const char* szHHModel; //0x0058
	const char* szLeftHHModel; //0x005C
	char aszSilencedFireSound[40]; //0x0060
	const char* szAltFireSound; //0x0088
	const char* szFireSound; //0x008C
	const char* szDryFireSound; //0x0090
	char szReloadSounds[12]; //0x0094
	const char* szSelectSound; //0x00A0
	const char* szDeselectSound; //0x00A4
	char szMiscSounds[20]; //0x00A8
	const char* szDotSight; //0x00BC
	const char* szPVMuzzleFxName; //0x00C0
	const char* szHHMuzzleFxName; //0x00C4
	const char* szWeaponImg; //0x00C8
	int32_t cDefaultScopeVisible; //0x00CC
	char szDefaultModAttach[20]; //0x00D0
	char szPVAttachClientFX[40]; //0x00E4
	int32_t szHHAttachClientFX; //0x010C
	const char* szHolsterAttachment; //0x0110
	char aszPVFlashHiderFXName[40]; //0x0114
	char aszHHFlashHiderFXName[40]; //0x013C
	char pad_0164[28]; //0x0164
	CButeListReader blrPVSkins; //0x0180 CButeListReader
	CButeListReader blrHHSkins; //0x0188 CButeListReader
	CButeListReader blrPVRenderStyles; //0x0190 CButeListReader
	CButeListReader blrHHRenderStyles; //0x0198 CButeListReader
	__int32 m_HHAniFrame[10]; //0x01A0 [10]
	__int32 m_HHReload_1Frame; //0x01C8
	char pad_01CC[44]; //0x01CC
	CButeListReader blrHiddenPieceNames; //0x01F8 CButeListReader
	D3DXVECTOR3 vHHScale; //0x0200
	D3DXVECTOR3 vLeftHHScale; //0x020C
	__int32 aSilencedFireRadius; //0x0218 [10]
	char pad_021C[36]; //0x021C
	__int32 nFireSoundRadius; //0x0240
	__int32 nFireSoundVolume; //0x0244
	bool bReloadAfterFire; //0x0248
	bool bDamageWeapon; //0x0249
	bool bCheckReloadAniTime; //0x024A
	bool bAIPrimaryWeapon; //0x024B
	bool bOnceActivate; //0x024C
	bool bHidden; //0x024D
	char pad_024E[2]; //0x024E
	__int32 nCrossHairOffset; //0x0250
	__int32 nCrossHairColor; //0x0254
	__int32 bTripleShotMode; //0x0258
	__int32 nTripleShotRoundNum; //0x025C
	float fDamageRFacter; //0x0260
	__int32 nSensorOption; //0x0264
	__int32 pSubControlWeaponName; //0x0268
	__int32 nSubControlWeaponID; //0x026C
	__int32 nSubControlleeWeaponID; //0x0270
	__int32 nReloadSoundRadius; //0x0274
	__int32 nSelectSoundRadius; //0x0278
	__int32 bInfiniteAmmo; //0x027C
	__int32 bHideWhenEmpty; //0x0280
	__int32 bUseUWMuzzleFX; //0x0284
	__int32 nShotsPerClip; //0x0288
	__int32 bReloadPerBullet; //0x028C
	__int32 nNumAmmoIds; //0x0290
	__int32 aAmmoIds; //0x0294
	__int32 nDefaultAmmoId; //0x0298
	__int32 nNumPVFXTypes; //0x029C
	__int32 aPVFXTypes; //0x02A0
	float fDynamicPerturbFactor; //0x02A4
	float fDynamicPerturbFactorRun; //0x02A8
	float fDynamicPerturbFactorWalk; //0x02AC
	float fDynamicPerturbFactorJump; //0x02B0
	float fZoomTime; //0x02B4
	__int32 nMinPerturb; //0x02B8
	__int32 nMaxPerturb; //0x02BC
	__int32 nDuckPerturb; //0x02C0
	__int32 nDuckMovePerturb; //0x02C4
	__int32 nZoomedMinPerturb; //0x02C8
	__int32 nZoomedMaxPerturb; //0x02CC
	__int32 nRange; //0x02D0
	D3DXVECTOR3 vRecoil; //0x02D4
	__int32 nVectorsPerRound; //0x02E0
	__int32 nAIWeaponType; //0x02E4
	float fAIMinBurstInterval; //0x02E8
	float fAIMaxBurstInterval; //0x02EC
	__int32 nAIMinBurstShots; //0x02F0
	__int32 nAIMaxBurstShots; //0x02F4
	__int32 bAIAnimatesReloads; //0x02F8
	class FullCMuzzleFX* pPVMuzzleFX; //0x02FC
	__int32 bPVAttachFXAlwaysShow; //0x0300
	__int32 m_nFireDelay; //0x0304
	float m_fFireAniRate; //0x0308
	float fMovePenalty; //0x030C
	float fPerturbIncSpeed; //0x0310
	float fPerturbDecSpeed; //0x0314
	float fZoomedMovePenalty; //0x0318
	float fZoomedPerturbIncSpeed; //0x031C
	float fZoomedPerturbDecSpeed; //0x0320
	float fMaxCamRecoilPitch; //0x0324
	float fBaseCamRecoilPitch; //0x0328
	float fBaseCamRecoilAccelPitch; //0x032C
	float fMaxCamRecoilYaw; //0x0330
	float fBaseCamRecoilYaw; //0x0334
	float fMaxCamRecoilWag; //0x0338
	float fBaseCamRecoilWagR; //0x033C
	float fBaseCamRecoilWagL; //0x0340
	float fMaxRandomPitch; //0x0344
	float fMaxRandomWag; //0x0348
	float fWhiteScreenDecl; //0x034C
	float fCapturedDecl; //0x0350
	float fTripleShotMaxCamRecoilPitch; //0x0354
	float fTripleShotBaseCamRecoilPitch; //0x0358
	float fBaseCamBackJitter; //0x035C
	float fBackJitterRecover; //0x0360
	__int32 nTripleShotMinPerturb; //0x0364
	__int32 nTripleShotMaxPerturb; //0x0368
	float fTripleShotPerturbIncSpeed; //0x036C
	float fTripleShotPerturbDecSpeed; //0x0370
	__int32 nHudFireMode; //0x0374
	D3DXVECTOR3 vMuzzlePVPosOff; //0x0378
	D3DXVECTOR3 vMuzzlePVRotOff; //0x0384
	D3DXVECTOR3 vMuzzleHHPosOff; //0x0390
	D3DXVECTOR3 vMuzzleHHRotOff; //0x039C
	D3DXVECTOR3 vScopePVPosOff; //0x03A8
	D3DXVECTOR3 vScopePVRotOff; //0x03B4
	D3DXVECTOR3 vScopeHHPosOff; //0x03C0
	D3DXVECTOR3 vScopeHHRotOff; //0x03CC
	__int32 nTripleShotDelay; //0x03D8
	__int32 nTripleShotSelectDelay; //0x03DC
	__int32 bDisableCrosshair; //0x03E0
	__int32 nRapidFireCount; //0x03E4
	__int32 bContinuousFire; //0x03E8
	__int32 bNoSelect; //0x03EC
	__int32 bForcedSelect; //0x03F0
	float fCameraSwayXSpeed; //0x03F4
	float fCameraSwayYSpeed; //0x03F8
	float fCameraSwayXFreq; //0x03FC
	float fCameraSwayYFreq; //0x0400
	float fGrenadeSpeed; //0x0404
	__int32 nGrenadeAttach; //0x0408
	char pad_040C[8]; //0x040C
	__int32 eGunType; //0x0414
	__int32 m_nAirStrikeID; //0x0418
	__int32 m_nAirDropNum; //0x041C
	float m_fAirDropHeight; //0x0420
	__int32 m_nAirDropDelay; //0x0424
	char pad_0428[36]; //0x0428
	float fChangeTextureTime; //0x044C
	char pad_0450[16]; //0x0450
	__int32 nShoutMsgShowTime; //0x0460
	__int32 nScanSendTime; //0x0464
	__int32 nScanDist; //0x0468
	__int32 nBatteryRefillQuantity; //0x046C
	__int32 nBatteryUsingQuantity; //0x0470
	__int32 nBatteryMaxQuantity; //0x0474
	__int32 nBatteryRefillTime; //0x0478
	char pad_047C[4]; //0x047C
	__int32 nAccumPreFire; //0x0480
	char pad_0484[60]; //0x0484
	__int32 dwWorldCoolTime; //0x04C0
	D3DXVECTOR3 vAirstrikeGaugeColor; //0x04C4
	D3DXVECTOR3 vAirstrikeGaugeBackColor; //0x04D0
	__int32 nAirstrikeGaugeType; //0x04DC
	__int32 nBuffID; //0x04E0
	__int32 nNerfID; //0x04E4
	char pad_04E8[4]; //0x04E8
	__int32 m_nWideFireMaxNum; //0x04EC
	__int32 m_nWideFireAngleDegree; //0x04F0
	__int32 m_dwCrossHairType; //0x04F4
	char pad_04F8[4]; //0x04F8
	D3DXVECTOR3 vLeftMuzzlePos; //0x04FC
	D3DXVECTOR3 vLeftBreachOffset; //0x0508
	char* pDualGunDropModel; //0x0514
	char* pHUDEffectOverride; //0x0518
	float fPriorityTargetDistance; //0x051C
	__int32 m_nSpecialFunction; //0x0520
}; //Size: 0x0524
class AMMO
{
public:
	__int32 eInstDamageType; //0x0000 enum DamageType
	__int32 bInited; //0x0004
	__int32 nId; //0x0008
	__int32 eType; //0x000C enum AmmoType
	float fPriority; //0x0010
	const char* szName; //0x0014
	__int32 nSpawnedAmount; //0x0018
	__int32 nSelectionAmount; //0x001C
	__int32 Alt_nInstDamage; //0x0020
	__int32 nInstDamage; //0x0024
	__int32 nAreaDamage; //0x0028
	__int32 nAreaDamageRadius; //0x002C
	__int32 nSensorAreaRadius; //0x0030
	__int32 eAreaDamageType; //0x0034 enum DamageType
	__int32 nAreaDamageTickDamage; //0x0038
	float fAreaDamageTickTime; //0x003C
	__int32 nAreaDamageTotal; //0x0040
	__int32 nAreaArcDamageRadius; //0x0044
	float fAreaArcDamageAngle; //0x0048
	__int32 nAreaArcDamage; //0x004C
	float fProgDamage; //0x0050
	float fProgDamageDuration; //0x0054
	float fProgDamageRadius; //0x0058
	float fProgDamageHeight; //0x005C
	float fProgDamageLifetime; //0x0060
	float fProgDamageSlowSpeed; //0x0064
	__int32 eProgDamageType; //0x0068 enum DamageType
	float fStunnedTime; //0x006C
	float fStunnedMovePanalty; //0x0070
	char pad_0074[72]; //0x0074
	float fJumpPerturb; //0x00BC
	float fWalkPerturb; //0x00C0
	float fRunPerturb; //0x00C4
	float fFireMoveDuckPerturb; //0x00C8
	float fFireMovePerturb; //0x00CC
	float fFireDuckPerturb; //0x00D0
	float fFirePerturb; //0x00D4
	float fPerturbRecoil; //0x00D8
	float fZoomedJumpPerturb; //0x00DC
	float fZoomedWalkPerturb; //0x00E0
	float fZoomedRunPerturb; //0x00E4
	float fZoomedFireMoveDuckPerturb; //0x00E8
	float fZoomedFireMovePerturb; //0x00EC
	float fZoomedFireDuckPerturb; //0x00F0
	float fZoomedFirePerturb; //0x00F4
	float fZoomedPerturbRecoil; //0x00F8
	float fDamageMovePenalty; //0x00FC
	float fDamageMovePenaltyDuration; //0x0100
	__int32 nDecDelay; //0x0104
	float nJitterDecDelay; //0x0108
	float fJitterWaitRecover; //0x010C
	float fJitterRecover; //0x0110
	__int32 nMaxAmount; //0x0114
	char pad_0118[44]; //0x0118
	float fHealth; //0x0144
	__int32 nBuffID; //0x0148
	__int32 nNerfID; //0x014C
}; //Size: 0x0150
class GEAR
{
public:
	__int32 m_bInited; //0x0000
	__int32 m_nId; //0x0004
	const char* szName; //0x0008
	char pad_0008[100]; //0x0008
	float m_fArmor; //0x0070
	float m_fHealth; //0x0074
	__int32 m_bExclusive; //0x0078
}; //Size: 0x007C
class DSIGHTSTYLE
{
public:
	__int32 bInited; //0x0000
	__int32 nId; //0x0004
	const char* szName; //0x0004
}; //Size: 0x0008
class cWeaponMGR
{
public:
	char pad_0000[5600]; //0x0000
	WEAPON** m_pWeaponList; //0x15E0
	__int32 m_nNumWeapons; //0x15E4
	AMMO** m_pAmmoList; //0x15E8
	__int32 m_nNumAmmos; //0x15EC
	GEAR** m_pGearList; //0x15F0
	__int32 m_nNumGear; //0x15F4
	char pad_15F8[24]; //0x15F8
	DSIGHTSTYLE** m_pDSightStyleList; //0x1610
	__int32 m_nNumDSightStyle; //0x1614
	__int32 m_pWeaponOrder; //0x1618
	__int32 m_nFirstPlayerWeapon; //0x161C
	__int32 m_nLastPlayerWeapon; //0x1620
	char pad_1624[16]; //0x1624
	__int32 m_nFileCRC; //0x1634
	float m_fMovementPerturbIncreaseSpeed; //0x1638
	float m_fMovementPerturbDecreaseSpeed; //0x163C
	float m_fFiringPerturbIncreaseSpeed; //0x1640
	float m_fFiringPerturbDecreaseSpeed; //0x1644
	float m_fPerturbRotationEffect; //0x1648
	char pad_164C[64]; //0x164C
	__int32 m_nCurrentBuffID; //0x168C
	__int32 m_nCurrentNerfID; //0x1690
}; //Size: 0x1694


struct WEAPONs
{
	// 0x0000
	int bInited;                 // 4 bytes
	int nId;                     // 4 bytes
	int nClientWeaponType;       // 4 bytes
	int nAniType;                // 4 bytes
	int nLowerAniType;           // 4 bytes

	// 0x0014 - D3DXVECTOR3 vPos
	D3DXVECTOR3 vPos;        // 12 bytes (0x14-0x1F)
	// 0x0020
	D3DXVECTOR3 vMuzzlePos;      // 12 bytes
	// 0x002C
	D3DXVECTOR3 vBreachOffset;   // 12 bytes
	// 0x0038
	D3DXVECTOR3 vLeftHandPosOffset; // 12 bytes
	// 0x0044
	D3DXVECTOR3 vLeftHandRotOffset; // 12 bytes
	const char* szName; //0x0050
	char pad_0054[0x78]; // 120 bytes padding
	char pad_00CC_0250[0x184]; // 0x0250 - 0x00CC = 0x184 (388 bytes)
	// 0x0250 int nCrossHairOffset
	int nCrossHairOffset;
	// 0x0254 int nCrossHairColor
	int nCrossHairColor;
	// 0x0258 bool bTripleShotMode (1 byte) + 3 padding
	char bTripleShotMode;
	char pad_0259[3];
	// 0x025C int nTripleShotRoundNum
	int nTripleShotRoundNum;
	// 0x0260 float fDamageRFacter
	float fDamageRFacter;
	// 0x0264 int nSensorOption
	int nSensorOption;
	// 0x0268 pointeur (skip) + 4 bytes padding
	char pad_0268[8];

	// 0x0270 int nSubControlWeaponID
	int nSubControlWeaponID;

	// 0x0274 int nSubControlleeWeaponID
	int nSubControlleeWeaponID;

	// 0x0278 int nReloadSoundRadius
	int nReloadSoundRadius;

	// 0x027C int nSelectSoundRadius
	int nSelectSoundRadius;

	// 0x0280 int bInfiniteAmmo
	int bInfiniteAmmo;

	// 0x0284 int bHideWhenEmpty
	int bHideWhenEmpty;

	// 0x0288 int bUseUWMuzzleFX
	int bUseUWMuzzleFX;

	// 0x028C int nShotsPerClip
	int nShotsPerClip;

	// 0x0290 int nNumAmmoIds
	int nNumAmmoIds;

	// 0x0294 pointeur aAmmoIds, on skip
	char pad_0294[4];

	// 0x0298 int nDefaultAmmoId
	int nDefaultAmmoId;

	// 0x029C int nNumPVFXTypes
	int nNumPVFXTypes;

	// 0x02A0 pointeur aPVFXTypes (skip)
	char pad_02A0[4];

	// 0x02A4 float fDynamicPerturbFactor
	float fDynamicPerturbFactor;

	// 0x02A8 float fDynamicPerturbFactorRun
	float fDynamicPerturbFactorRun;

	// 0x02AC float fDynamicPerturbFactorWalk
	float fDynamicPerturbFactorWalk;

	// 0x02B0 float fDynamicPerturbFactorJump
	float fDynamicPerturbFactorJump;

	// 0x02B4 float fZoomTime
	float fZoomTime;

	// 0x02B8 int nMinPerturb
	int nMinPerturb;

	// 0x02BC int nMaxPerturb
	int nMaxPerturb;

	// 0x02C0 int nDuckPerturb
	int nDuckPerturb;

	// 0x02C4 int nDuckMovePerturb
	int nDuckMovePerturb;

	// 0x02C8 int nZoomedMinPerturb
	int nZoomedMinPerturb;

	// 0x02CC int nZoomedMaxPerturb
	int nZoomedMaxPerturb;

	// 0x02D0 int nRange
	int nRange;

	// 0x02D4 D3DXVECTOR3 vRecoil
	D3DXVECTOR3 vRecoil;

	// 0x02E0 int nVectorsPerRound
	int nVectorsPerRound;

	// 0x02E4 int nAIWeaponType
	int nAIWeaponType;

	// 0x02E8 float fAIMinBurstInterval
	float fAIMinBurstInterval;

	// 0x02EC float fAIMaxBurstInterval
	float fAIMaxBurstInterval;

	// 0x02F0 int nAIMinBurstShots
	int nAIMinBurstShots;

	// 0x02F4 int nAIMaxBurstShots
	int nAIMaxBurstShots;

	// 0x02F8 int bAIAnimatesReloads
	int bAIAnimatesReloads;

	// 0x02FC pointeur pPVMuzzleFX (skip)
	char pad_02FC[4];

	// 0x0300 int bPVAttachFXAlwaysShow
	int bPVAttachFXAlwaysShow;

	// 0x0304 int m_nFireDelay
	int m_nFireDelay;

	// 0x0308 float m_fFireAniRate
	float m_fFireAniRate;

	// 0x030C float fMovePenalty
	float fMovePenalty;

	// 0x0310 float fPerturbIncSpeed
	float fPerturbIncSpeed;

	// 0x0314 float fPerturbDecSpeed
	float fPerturbDecSpeed;

	// 0x0318 float fZoomedMovePenalty
	float fZoomedMovePenalty;

	// 0x031C float fZoomedPerturbIncSpeed
	float fZoomedPerturbIncSpeed;

	// 0x0320 float fZoomedPerturbDecSpeed
	float fZoomedPerturbDecSpeed;

	// 0x0324 float fMaxCamRecoilPitch
	float fMaxCamRecoilPitch;

	// 0x0328 float fBaseCamRecoilPitch
	float fBaseCamRecoilPitch;

	// 0x032C float fBaseCamRecoilAccelPitch
	float fBaseCamRecoilAccelPitch;

	// 0x0330 float fMaxCamRecoilYaw
	float fMaxCamRecoilYaw;

	// 0x0334 float fBaseCamRecoilYaw
	float fBaseCamRecoilYaw;

	// 0x0338 float fMaxCamRecoilWag
	float fMaxCamRecoilWag;

	// 0x033C float fBaseCamRecoilWagR
	float fBaseCamRecoilWagR;

	// 0x0340 float fBaseCamRecoilWagL
	float fBaseCamRecoilWagL;

	// 0x0344 float fMaxRandomPitch
	float fMaxRandomPitch;

	// 0x0348 float fMaxRandomWag
	float fMaxRandomWag;

	// 0x034C float fWhiteScreenDecl
	float fWhiteScreenDecl;

	// 0x0350 float fCapturedDecl
	float fCapturedDecl;

	// 0x0354 float fTripleShotMaxCamRecoilPitch
	float fTripleShotMaxCamRecoilPitch;

	// 0x0358 float fTripleShotBaseCamRecoilPitch
	float fTripleShotBaseCamRecoilPitch;

	// 0x035C float fBaseCamBackJitter
	float fBaseCamBackJitter;

	// 0x0360 float fBackJitterRecover
	float fBackJitterRecover;

	// 0x0364 int nTripleShotMinPerturb
	int nTripleShotMinPerturb;

	// 0x0368 int nTripleShotMaxPerturb
	int nTripleShotMaxPerturb;

	// 0x036C float fTripleShotPerturbIncSpeed
	float fTripleShotPerturbIncSpeed;

	// 0x0370 float fTripleShotPerturbDecSpeed
	float fTripleShotPerturbDecSpeed;

	// 0x0374 int nHudFireMode
	int nHudFireMode;

	// 0x0378 D3DXVECTOR3 vMuzzlePVPosOff
	D3DXVECTOR3 vMuzzlePVPosOff;

	// 0x0384 D3DXVECTOR3 vMuzzlePVRotOff
	D3DXVECTOR3 vMuzzlePVRotOff;

	// 0x0390 D3DXVECTOR3 vMuzzleHHPosOff
	D3DXVECTOR3 vMuzzleHHPosOff;

	// 0x039C D3DXVECTOR3 vMuzzleHHRotOff
	D3DXVECTOR3 vMuzzleHHRotOff;

	// 0x03A8 D3DXVECTOR3 vScopePVPosOff
	D3DXVECTOR3 vScopePVPosOff;

	// 0x03B4 D3DXVECTOR3 vScopePVRotOff
	D3DXVECTOR3 vScopePVRotOff;

	// 0x03C0 D3DXVECTOR3 vScopeHHPosOff
	D3DXVECTOR3 vScopeHHPosOff;

	// 0x03CC D3DXVECTOR3 vScopeHHRotOff
	D3DXVECTOR3 vScopeHHRotOff;

	// 0x03D8 int nTripleShotDelay
	int nTripleShotDelay;

	// 0x03DC int nTripleShotSelectDelay
	int nTripleShotSelectDelay;

	// 0x03E0 bool bDisableCrosshair (1 byte) + 3 padding
	char bDisableCrosshair;
	char pad_03E1[3];

	// 0x03E4 int nRapidFireCount
	int nRapidFireCount;

	// 0x03E8 bool bContinuousFire (1 byte) + 3 padding
	char bContinuousFire;
	char pad_03E9[3];

	// 0x03EC int bNoSelect
	int bNoSelect;

	// 0x03F0 bool bForcedSelect (1 byte) + 3 padding
	char bForcedSelect;
	char pad_03F1[3];

	// 0x03F4 float fCameraSwayXSpeed
	float fCameraSwayXSpeed;

	// 0x03F8 float fCameraSwayYSpeed
	float fCameraSwayYSpeed;

	// 0x03FC float fCameraSwayXFreq
	float fCameraSwayXFreq;

	// 0x0400 float fCameraSwayYFreq
	float fCameraSwayYFreq;

	// 0x0404 float fGrenadeSpeed
	float fGrenadeSpeed;

	// 0x0408 int nGrenadeAttach
	int nGrenadeAttach;

	// 0x040C CButeListReader blrEffectrange (skip)
	char pad_040C[4];

	// 0x0410 int eGunType
	int eGunType;

	// 0x0414 int m_nAirStrikeID
	int m_nAirStrikeID;

	// 0x0418 int m_nAirDropNum
	int m_nAirDropNum;

	// 0x041C float m_fAirDropHeight
	float m_fAirDropHeight;

	// 0x0420 int m_nAirDropDelay
	int m_nAirDropDelay;

	// 0x0424 std::vector m_vAirDropPoint (skip)
	char pad_0424[20];

	// 0x0438 offset string etc. skip
	char pad_0438[140];

	// 0x04C0 int dwWorldCoolTime
	int dwWorldCoolTime;

	// 0x04C4 D3DXVECTOR3 vAirstrikeGaugeColor
	D3DXVECTOR3 vAirstrikeGaugeColor;

	// 0x04D0 D3DXVECTOR3 vAirstrikeGaugeBackColor
	D3DXVECTOR3 vAirstrikeGaugeBackColor;

	// 0x04DC int nAirstrikeGaugeType
	int nAirstrikeGaugeType;

	// 0x04E0 int nBuffID
	int nBuffID;

	// 0x04E4 int nNerfID
	int nNerfID;

	// 0x04E8 bool bDropByPlayerDead (1 byte) + 3 padding
	char bDropByPlayerDead;
	char pad_04E9[3];

	// 0x04EC int m_nWideFireMaxNum
	int m_nWideFireMaxNum;

	// 0x04F0 int m_nWideFireAngleDegree
	int m_nWideFireAngleDegree;

	// 0x04F4 int m_dwCrossHairType
	int m_dwCrossHairType;

	// 0x04F8 pointer pLeftMuzzleFXName (skip)
	char pad_04F8[4];

	// 0x04FC D3DXVECTOR3 vLeftMuzzlePos
	D3DXVECTOR3 vLeftMuzzlePos;

	// 0x0508 D3DXVECTOR3 vLeftBreachOffset
	D3DXVECTOR3 vLeftBreachOffset;

	// 0x0514 pointer pDualGunDropModel (skip)
	char pad_0514[4];

	// 0x0518 pointer pHUDEffectOverride (skip)
	char pad_0518[4];

	// 0x051C float m_fPriorityTargetDistance
	float m_fPriorityTargetDistance;

	// 0x0520 int m_nSpecialFunction
	int m_nSpecialFunction;
};

//class WEAPONs
//{
//public:
//	__int32 bInited; //0x0000
//	__int32 nId; //0x0004
//	__int32 nClientWeaponType; //0x0008
//	__int32 nAniType; //0x000C
//	__int32 nLowerAniType; //0x0010
//	D3DXVECTOR3 vPos; //0x0014
//	char pad_0020[48]; //0x0020
//public:
//	const char* szName; //0x0050
//private:
//	char pad_0054[512]; //0x0054
//public:
//	int32_t nCrossHairColor; //0x0254
//	__int32 bTripleShotMode; //0x0258
//	__int32 nTripleShotRoundNum; //0x025C
//private:
//	char pad_0260[40]; //0x0260
//public:
//	__int32 nShotsPerClip; //0x0288
//private:
//	char pad_028C[24]; //0x028C
//public:
//	float fDynamicPerturbFactor; //0x02A4
//	float fDynamicPerturbFactorRun; //0x02A8
//	float fDynamicPerturbFactorWalk; //0x02AC
//	float fDynamicPerturbFactorJump; //0x02B0
//	float fZoomTime; //0x02B4
//	__int32 nMinPerturb; //0x02B8
//	__int32 nMaxPerturb; //0x02BC
//	__int32 nDuckPerturb; //0x02C0
//	__int32 nDuckMovePerturb; //0x02C4
//	__int32 nZoomedMinPerturb; //0x02C8
//	__int32 nZoomedMaxPerturb; //0x02CC
//	__int32 nRange; //0x02D0
//	D3DXVECTOR3 vRecoil;
//	__int32 nVectorsPerRound; //0x02E0
//private:
//	char pad_02E4[36]; //0x02E4
//public:
//	float AniRate; //0x0308
//	float fMovePenalty; //0x030C
//	float fPerturbIncSpeed; //0x0310
//	float fPerturbDecSpeed; //0x0x314
//	float fZoomedMovePenalty; //0x0318
//	float fZoomedPerturbIncSpeed; //0x031C
//	float fZoomedPerturbDecSpeed; //0x0320
//	float fMaxCamRecoilPitch; //0x0324
//	float fBaseCamRecoilPitch; //0x0328
//	float fBaseCamRecoilAccelPitch; //0x032C
//private:
//	char pad_0330[32]; //0x0330
//public:
//	float fCapturedDecl; //0x0350
//	float fTripleShotMaxCamRecoilPitch; //0x354
//	float fTripleShotBaseCamRecoilPitch; //0x0358
//	float fBaseCamBackJitter; //0x035C
//	float fBackJitterRecover; //0x0360
//	__int32 nTripleShotMinPerturb; //0x0364
//	__int32 nTripleShotMaxPerturb; //0x0368
//	float fTripleShotPerturbIncSpeed; //0x036C
//	float fTripleShotPerturbDecSpeed; //0x0370
//private:
//	char pad_0374[128]; //0x0374
//public:
//	float fCameraSwayXSpeed; //0x03F4
//	float fCameraSwayYSpeed; //0x03F8
//	float fCameraSwayXFreq; //0x03FC
//	float fCameraSwayYFreq; //0x0400
//private:
//	char pad_0404[240]; //0x0404
//public:
//	__int32 m_dwCrossHairType; //0x04F4
//
//}; //Size: 0x04F8

class cWeaponmgr
{
public:
	char pad_0000[5600]; //0x0000
	WEAPONs** m_pWeaponList; //0x15E0
	__int32 m_nNumWeapons; //0x15E4
	AMMO** m_pAmmoList; //0x15E8
	__int32 m_nNumAmmos; // 0x15EC
	GEAR** m_pGearList;
	__int32 m_nNumGear;
	char pad_15F8[24]; //0x15F8
	DSIGHTSTYLE** m_pDSightStyleList; //0x1610
	__int32 m_nNumDSightStyle; //0x1614
};

void BackupWeaponStats(WEAPONs* weapon, int index)
{
	// Backup Spread
	cheat::weapon::Backups::Weapons::DefaultSpread[0][index] = weapon->fDynamicPerturbFactor;
	cheat::weapon::Backups::Weapons::DefaultSpread[1][index] = weapon->fDynamicPerturbFactorRun;
	cheat::weapon::Backups::Weapons::DefaultSpread[2][index] = weapon->fDynamicPerturbFactorJump;
	cheat::weapon::Backups::Weapons::DefaultSpread[3][index] = weapon->nMinPerturb;
	cheat::weapon::Backups::Weapons::DefaultSpread[4][index] = weapon->nMaxPerturb;
	cheat::weapon::Backups::Weapons::DefaultSpread[5][index] = weapon->nDuckPerturb;
	cheat::weapon::Backups::Weapons::DefaultSpread[6][index] = weapon->nDuckMovePerturb;
	cheat::weapon::Backups::Weapons::DefaultSpread[7][index] = weapon->nZoomedMinPerturb;
	cheat::weapon::Backups::Weapons::DefaultSpread[8][index] = weapon->nZoomedMaxPerturb;
	cheat::weapon::Backups::Weapons::DefaultSpread[9][index] = weapon->nTripleShotMinPerturb;
	cheat::weapon::Backups::Weapons::DefaultSpread[10][index] = weapon->nTripleShotMaxPerturb;
	cheat::weapon::Backups::Weapons::DefaultSpread[11][index] = weapon->fTripleShotPerturbIncSpeed;
	cheat::weapon::Backups::Weapons::DefaultSpread[12][index] = weapon->fTripleShotPerturbDecSpeed;
	cheat::weapon::Backups::Weapons::DefaultSpread[13][index] = weapon->fPerturbIncSpeed;
	cheat::weapon::Backups::Weapons::DefaultSpread[14][index] = weapon->fZoomedPerturbIncSpeed;

	// Backup Recoil
	cheat::weapon::Backups::Weapons::DefaultRecoil[0][index] = weapon->fBaseCamRecoilPitch;
	cheat::weapon::Backups::Weapons::DefaultRecoil[1][index] = weapon->fCameraSwayXSpeed;
	cheat::weapon::Backups::Weapons::DefaultRecoil[2][index] = weapon->fCameraSwayYSpeed;
	cheat::weapon::Backups::Weapons::DefaultRecoil[3][index] = weapon->fTripleShotMaxCamRecoilPitch;
	cheat::weapon::Backups::Weapons::DefaultRecoil[4][index] = weapon->fTripleShotBaseCamRecoilPitch;

	// Backup Other
	cheat::weapon::Backups::Weapons::DefaultOther[0][index] = weapon->fMovePenalty;
	cheat::weapon::Backups::Weapons::DefaultOther[1][index] = weapon->fZoomTime;
	cheat::weapon::Backups::Weapons::DefaultOther[2][index] = weapon->nCrossHairColor;
	cheat::weapon::Backups::Weapons::DefaultOther[3][index] = weapon->fZoomedMovePenalty;
}
void ApplyNoRecoil(WEAPONs* weapon, int index)
{
	if (cheat::weapon::NoRecoil)
	{
		weapon->fBaseCamRecoilPitch = 0;
		weapon->fCameraSwayXSpeed = 0;
		weapon->fCameraSwayYSpeed = 0;
		weapon->fTripleShotMaxCamRecoilPitch = 0;
		weapon->fTripleShotBaseCamRecoilPitch = 0;
	}
	else
	{
		weapon->fBaseCamRecoilPitch = cheat::weapon::Backups::Weapons::DefaultRecoil[0][index];
		weapon->fCameraSwayXSpeed = cheat::weapon::Backups::Weapons::DefaultRecoil[1][index];
		weapon->fCameraSwayYSpeed = cheat::weapon::Backups::Weapons::DefaultRecoil[2][index];
		weapon->fTripleShotMaxCamRecoilPitch = cheat::weapon::Backups::Weapons::DefaultRecoil[3][index];
		weapon->fTripleShotBaseCamRecoilPitch = cheat::weapon::Backups::Weapons::DefaultRecoil[4][index];
	}
}
void ApplyNoSpread(WEAPONs* weapon, int index)
{
	if (cheat::weapon::NoSpread)
	{
		weapon->fDynamicPerturbFactor = 0;
		weapon->fDynamicPerturbFactorRun = 0;
		weapon->fDynamicPerturbFactorJump = 0;
		weapon->nMinPerturb = 0;
		weapon->nMaxPerturb = 0;
		weapon->nDuckPerturb = 0;
		weapon->nDuckMovePerturb = 0;
		weapon->nZoomedMinPerturb = 0;
		weapon->nZoomedMaxPerturb = 0;
		weapon->nTripleShotMinPerturb = 0;
		weapon->nTripleShotMaxPerturb = 0;
		weapon->fTripleShotPerturbIncSpeed = 0;
		weapon->fTripleShotPerturbDecSpeed = 0;
		weapon->fPerturbIncSpeed = 0;
		weapon->fZoomedPerturbIncSpeed = 0;
	}
	else
	{
		weapon->fDynamicPerturbFactor = cheat::weapon::Backups::Weapons::DefaultSpread[0][index];
		weapon->fDynamicPerturbFactorRun = cheat::weapon::Backups::Weapons::DefaultSpread[1][index];
		weapon->fDynamicPerturbFactorJump = cheat::weapon::Backups::Weapons::DefaultSpread[2][index];
		weapon->nMinPerturb = cheat::weapon::Backups::Weapons::DefaultSpread[3][index];
		weapon->nMaxPerturb = cheat::weapon::Backups::Weapons::DefaultSpread[4][index];
		weapon->nDuckPerturb = cheat::weapon::Backups::Weapons::DefaultSpread[5][index];
		weapon->nDuckMovePerturb = cheat::weapon::Backups::Weapons::DefaultSpread[6][index];
		weapon->nZoomedMinPerturb = cheat::weapon::Backups::Weapons::DefaultSpread[7][index];
		weapon->nZoomedMaxPerturb = cheat::weapon::Backups::Weapons::DefaultSpread[8][index];
		weapon->nTripleShotMinPerturb = cheat::weapon::Backups::Weapons::DefaultSpread[9][index];
		weapon->nTripleShotMaxPerturb = cheat::weapon::Backups::Weapons::DefaultSpread[10][index];
		weapon->fTripleShotPerturbIncSpeed = cheat::weapon::Backups::Weapons::DefaultSpread[11][index];
		weapon->fTripleShotPerturbDecSpeed = cheat::weapon::Backups::Weapons::DefaultSpread[12][index];
		weapon->fPerturbIncSpeed = cheat::weapon::Backups::Weapons::DefaultSpread[13][index];
		weapon->fZoomedPerturbIncSpeed = cheat::weapon::Backups::Weapons::DefaultSpread[14][index];
	}
}
void ApplyZoomTime(WEAPONs* weapon, int index)
{
	if (cheat::weapon::ZoomTime) weapon->fZoomTime = 0;
	else weapon->fZoomTime = cheat::weapon::Backups::Weapons::DefaultOther[1][index];
}
void ApplyMovePenalty(WEAPONs* weapon, int index)
{
	if (cheat::weapon::MovePenalty)
	{
		weapon->fMovePenalty = 0 - cheat::weapon::MovePenaltys;
		weapon->fZoomedMovePenalty = 0;
	}
	else
	{
		weapon->fMovePenalty = cheat::weapon::Backups::Weapons::DefaultOther[0][index];
		weapon->fZoomedMovePenalty = cheat::weapon::Backups::Weapons::DefaultOther[3][index];
	}
}