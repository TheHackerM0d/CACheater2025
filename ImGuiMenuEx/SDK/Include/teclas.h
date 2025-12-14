#ifndef _Class
#define _Class

//#include "stdafx.h"
//#include "targetver.h"

class cPlayerMgr;
class cClientWeapon;
class cClientWeaponMgr;
class PlayerInfo;
class CILTDrawPrim;
#define M_PI 3.14159265358979323846f
#define DegToRad( degree ) ( (degree) * (3.141592654f / 180.0f) )
#define PITCH 0
#define YAW 1
#define ROLL 2
LPDIRECT3DDEVICE9 pDevice;
LPD3DXLINE pLine;

#pragma warning(disable: 4244)


#define DrawPrimitive		0x818A34

typedef PlayerInfo *(__thiscall *lpGetPlayerByIndex2)(unsigned long ulThis, INT index, INT unk);
lpGetPlayerByIndex2 GetPlayerByIndex2;

typedef PlayerInfo *(__thiscall *lpGetLocalPlayer2)(unsigned long ulThis);
lpGetLocalPlayer2 GetLocalPlayer2;

class cCharacterFX
{
public:
			char	unk1[16];
	int*	Object;			//0x10
			char	unk2[44];
	int		IsPlayer;		//0x40
			char	unk3[40];
	unsigned char	Index;	//0x6C
			char unknown112[8]; //0x0070
	float fStartPitch; //0x0078  
	float fStartYaw; //0x007C  
			char unknown128[1224]; //0x0080
			BYTE unk1287; //0x0548  
	bool bIsDead; //0x0549  
	bool bSpawnSheild; //0x054A  
			BYTE unk5563; //0x054B  
			char unknown1356[12]; //0x054C
	int* hHitbox; //0x0558  
			char unknown1372[96]; //0x055C
			WORD wUnk; //0x05BC  
	WORD wHealth; //0x05BE  
	WORD wArmor; //0x05C0  
};

class cSFXList
{
public:
			unsigned long	unk0;
	unsigned long*	List;
			unsigned long	unk1;
	int				Num;
};

class cSFXMgr
{
public:
	cSFXList		SFXList[0x3D];
};

class cGameClientShell
{
public:
			virtual void Function0();
			virtual void Function1();
			virtual void Function2();
			virtual void Function3();
			virtual void Function4();
			virtual void Function5();
			virtual void Function6();
			virtual void Function7();
			virtual void Function8();
			virtual void Function9();
			virtual void Function10();
			virtual void Function11();
			virtual void Function12();
			virtual void Function13();
			virtual void Function14();
			virtual void Function15();
			virtual void Function16();
			virtual void Function17();
			virtual void Function18();
			virtual void Function19();
			virtual void Function20();
			virtual void Function21();
			virtual void Function22();
			virtual void Function23();
			virtual void Function24();
			virtual void Function25();
			virtual void Function26();
			virtual void Function27();
			virtual void Function28();
			virtual void Function29();
			virtual void Function30();
			virtual void Function31();
			virtual void Function32();
			virtual void Function33();
			virtual void Function34();
			virtual void Function35();
			virtual void Function36();
			virtual void Function37();
			virtual void Function38();
			virtual void Function39();
			virtual void Function40();
			virtual void Function41();
			virtual void Function42();
			virtual void Function43();
			virtual void Function44();
			virtual void Function45();
	virtual DWORD GetClientInfoMgr();
	virtual DWORD GetInterfaceManager();
    virtual DWORD GetPlayerManager();
			virtual void Function49();
			virtual void Function50();
			virtual void Function51();
			virtual void Function52();
			virtual void Function53();
			virtual void Function54();
			virtual void Function55();
			virtual void Function56();
	virtual cSFXMgr* GetSFXMgr();
};

class cClientInfo
{
public:
	__int32 pPing; //0x0000 
	__int32 Index; //0x0004 
char _0x0008[8];
	char pName[12]; //0x0010 
char _0x001C[12];
	int* Object; //0x0028 
	__int32 pKills; //0x002C 
	__int32 pDeaths; //0x0030 
char _0x0034[52];
	__int32 pFTMission; //0x0068 
char _0x006C[4];
	__int32 pTeam; //0x0070 
char _0x0074[4];
	BYTE pIsDead; //0x0078 
char _0x0079[319];
	__int32 pRank; //0x01B8 
char _0x01BC[80];
	__int32 pFTScore; //0x020C 
	BYTE pFTSpawn; //0x0210 
char _0x0211[3];
	__int32 pFTLongestLife; //0x0214 
	__int32 pFTKill; //0x0218 
char _0x021C[84];
	cClientInfo* PlayerNext; //0x0270 
};//Size=0x0274



class PointerTo;
class _Object;
class CILTDrawPrim;


class PointerTo 
{
public:
   CHAR pad[4];
   PlayerInfo *first;
   __int32 index;
};

class _Object
{
public:
   CHAR Pad[4];
   D3DXVECTOR3 origin;
};
// i know it's same this 

class cWeaponInfo
{
public:
			char unknown0[12]; //0x0000
	DWORD dwClientWeaponType; //0x000C  
			char unknown16[16]; //0x0010
	DWORD dwAlt_InstDamage; //0x0020  
	DWORD dwInstDamage; //0x0024  
			DWORD UNK; //0x0028  
			char unknown44[104]; //0x002C
	DWORD dwFireSnd; //0x0094  
			char unknown152[108]; //0x0098
			float fFireDelay1; //0x0104  
			float ffiredelay1; //0x0108  
			DWORD dwMaxAmmo3; //0x010C  
			DWORD dwMaxAmmo2; //0x0110  
			char unknown276[276]; //0x0114
	DWORD dwCrossHairA; //0x0228  
	DWORD dwCrossHairR; //0x022C  
	DWORD dwCrossHairG; //0x0230  
	DWORD dwCrossHairB; //0x0234  
	BYTE TripleShotMode; //0x0238  
			char unknown569[3]; //0x0239
	DWORD dwTripleShotRoundNum; //0x023C  
	float fDamageRFacter; //0x0240  
			char unknown580[28]; //0x0244
			DWORD dwInfiAmmo2;
	DWORD dwInfiniteAmmo; //0x0264  
	DWORD dwHideWhenEmpty; //0x0268  
	DWORD dwIsAmmo; //0x026C  
			char unknown624[4]; //0x0270
	DWORD dwShotsPerClip; //0x0274  
			char unknown632[52]; //0x0278
	float fZoomTime; //0x02AC  
	DWORD dwMinPerturb; //0x02B0  
	DWORD dwMaxPerturb; //0x02B4  
	float fDuckPerturb; //0x02B8  
	float fMoveDuckPerturb; //0x02BC  
	DWORD dwZoomedMinPerturb; //0x02C0  
	DWORD dwZoomedMaxPerturb; //0x02C4  
	DWORD dwRange; //0x02C8  
			char unknown716[12]; //0x02CC
	DWORD VectorsPerRound; //0x02D8  
			char unknown732[40]; //0x02DC
	float fPerturbIncSpeed; //0x0304  
	float fPerturbDecSpeed; //0x0308  
			char unknown780[4]; //0x030C
	float fZoomedPerturbIncSpeed; //0x0310  
	float fZoomedPerturbDecSpeed; //0x0314  
			char unknown792[4]; //0x0318
	float fBaseCamRecoilPitch; //0x031C  
	float fBaseCamRecoilAccelPitch; //0x0320  
			char unknown804[36]; //0x0324
	float fTripleShotMaxCamRecoilPitch; //0x0348  
	float fTripleShotBaseCamRecoilPitch; //0x034C  
			char unknown848[8]; //0x0350
	DWORD dwTripleShotMinPerturb; //0x0358  
	DWORD dwTripleShotMaxPerturb; //0x035C  
	float fTripleShotPerturbIncSpeed; //0x0360  
	float fTripleShotPerturbDecSpeed; //0x0364  
			char unknown872[112]; //0x0368
	DWORD dwFireRate; //0x03D8  
	DWORD dwMoveSpeed; //0x03DC  
			DWORD ID03B39CC0; //0x03E0  
			char unknown996[32]; //0x03E4
	BYTE DisableCrosshair; //0x0404  
			char unknown1029[27]; //0x0405
	float fCameraSwayXFreq; //0x0420  
	float fCameraSwayYFreq; //0x0424  
			char unknown1064[12]; //0x0428
	DWORD dwTargetCrosshairFlag; //0x0434  
	DWORD dwEffectRange; //0x0438  
			char unknown1084[192]; //0x043C
	DWORD dwFireDelay; //0x04FC  
};

class cWeaponMgr
{
public:
			char unknown0[5564];
	cWeaponInfo** Weapons; //15BC
	__int32 WeaponCount; //15C0
};

class cClientWeaponMgr{
public:

	cClientWeapon** WeaponList;   //0000
	__int32 MaxWeapons;			  //0004
	__int32 WeapIndex;			  //0008
	cClientWeapon* CurrentWeapon; //000C
	BYTE WeaponsEnabled;		  //0010
	BYTE WeaponsVisible;		  //0011	
			char unknown16[20];				
	__int32 nCurrentWeaponID;	 //0x0024
};
class cPlayerMgr
{
public:
			char pad[24];
	cClientWeaponMgr* WeaponMgr; //0018
			char unknown0[48];
	float Pitch; //0048
	float Yaw; //004C
	float Roll;
			char unknown3[220];
	int* CameraObject; //012C

	__inline cClientWeapon* GetCurrentWeapon()
	{
		if( WeaponMgr && WeaponMgr->CurrentWeapon )
			return WeaponMgr->CurrentWeapon;

		return NULL;
	}
};

D3DXVECTOR3 Angles, FinalAimSpot;
#define SFX_NADE				0x13
#define SFX_PICKUP				0x17
#define SFX_CHARACTER			0x18
#define SFX_MAX					0x3B
bool bAimbot = false;
class cLTCientShellBase;
class cLTClient;
class cLTDrawPrim;
class cGameClientShell;
class cLTModel;
class cLTCommon;
class cLTMessage;
class cFont;
class cClientWeapon;
class cObjName;
class cBaseFX;
//class cPlayerInfo;
class cLTMessage;
class cLTBase;
class cClientInfoMgr;
class cMoveMgr;



class cLTClientShellBase
{
public:
	cLTBase* ILTBase;		                //0x0000  
			char unknown4[16];					  
	cLTDrawPrim** ILTDrawPrim;			    //0x0014  
			char unknown24[4];					  
	cLTModel** ILTModel;				    //0x001C  
			char unknown32[136];				  
	cGameClientShell* ILTGameClientShell;	//0x00A8  
};


class CILTDrawPrim
{ 
public:
    virtual VOID function0();
    virtual VOID function1();
    virtual VOID function2();
    virtual VOID function3();
    virtual VOID function4();
    virtual VOID function5();
    virtual VOID function6();
    virtual VOID function7();
    virtual VOID function8();
	virtual VOID function9();
	virtual VOID function10();
    virtual VOID function11();
    virtual VOID function12();
    virtual VOID function13();
    virtual VOID function14();
    virtual VOID function15();
    virtual VOID function16();
    virtual VOID function17();
    virtual VOID function18();
    virtual VOID function19();
    virtual VOID function20();
    virtual VOID function21();
    virtual VOID function22();
    virtual VOID function23();
    virtual VOID function24();
    virtual VOID function25();
    virtual VOID function26();
    virtual VOID function27();
    virtual VOID function28();
    virtual VOID function29();
    virtual VOID function30();
    virtual VOID function31();
    virtual VOID function32();
    virtual VOID function33();
    virtual VOID function34();
    virtual VOID function35();
    virtual VOID function36();
    virtual VOID function37();
    virtual VOID function38();
    virtual VOID function39();
    virtual VOID function40();
    virtual VOID function41();
    virtual VOID function42();
    virtual VOID function43();
    virtual VOID function44();
    virtual VOID function45();
    virtual VOID function46();
    virtual VOID function47();
    virtual VOID function48();
    virtual VOID function49();
    virtual HRESULT Project(FLOAT x, FLOAT y, FLOAT z, D3DXVECTOR3 *pProjectOut, D3DXVECTOR3 *pTransformOut);
    CHAR unknown[17232];
    D3DXMATRIX World; 
    D3DXMATRIX View;
    D3DXMATRIX Projection;
};




class Something
{
public:
	bool bIsAlive; //0000
};

class WepInfo
{
public:
	__int32 iBackPackABulletsLeft;  //0000
	__int32 i2ndaryBulletsLeft;		//0004
			__int32 Unknown0;	    
	__int32 iGrenadesLeft;			//000C
	__int32 iBackPackBBulletsLeft;  //0010
};

class Info
{
public:
			char unknown0[12];		//0x0000
	__int32 iHP;					//0x000C  
	__int32 iAP;					//0x0010  
	__int32 iMaxHP;					//0x0014  
	__int32 iMaxAP;					//0x0018  
	WepInfo* gotoWepInfo;			//0x001C  
	Something* goToSomething;		//0x0020  
			char unknown36[352];	
	float fStamina;					//0x0184  
	__int32 iIsRunning;				//0x0188  
	__int32 iIsJumping;				//0x018C  
	__int32 iWeaponSlotInUse;		//0x0190  
			char unknown404[44];	//0x0194
	PlayerInfo* goToPlayers;			//0x01C0  		
};

class LocalInfo
{
public:
	Info* goToInfoClass; //0000
};



class cMoveMgr {
public:

	char offset0[0x60];
	bool bIsInAir;

};
	cLTClientShellBase*	pClientShellBase;
	cGameClientShell*	pGameClientShell;
	cClientInfoMgr*		pClientInfoMgr;
	cPlayerMgr*			pPlayerManager;
	cLTDrawPrim*		pLTDrawPrim;
	cLTClient*			pLTClient;
	cLTModel*			pLTModel;
	cLTBase*			pLTBase;
	LocalInfo*			pLocal;

	cFont*				pWarningFont;
	cFont*				pSmallFont;
	cFont*				pMenuFont;

	DWORD				dwClientFxEntry;
cLTClientShellBase* GetClientShellBase()
	{
		return pClientShellBase;
	}

	cGameClientShell* GetGameClientShell()
	{
		return pGameClientShell;
	}

	cClientInfoMgr* GetClientInfoMgr()
	{
		return pClientInfoMgr;
	}

	cPlayerMgr* GetPlayerMgr()
	{
		return pPlayerManager;
	}

	cLTBase* GetLTBase()
	{
		return pLTBase;
	}

	cLTModel* GetLTModel()
	{
		return pLTModel;
	}

	cLTClient* GetLTClient()
	{
		return pLTClient;
	}

	cLTDrawPrim* GetLTDrawPrim()
	{
		return pLTDrawPrim;
	}

	LocalInfo* GetLocal()
	{
		return pLocal;
	}

	//////////////////////////////////////////////////////////////////////////
	//								Font Pointers							//
	//////////////////////////////////////////////////////////////////////////

 	cFont* GetSmallFont()
 	{
 		return pSmallFont;
 	}

	cFont* GetWarningFont()
	{
		return pWarningFont;
	}

	cFont* GetMenuFont()
	{
		return pMenuFont;
	}



	//////////////////////////////////////////////////////////////////////////
	//																		//
	//////////////////////////////////////////////////////////////////////////

class PlayerInfo
{
public:
	__int32 Unknown0;
	__int32 index;
	__int32 Unknown1;
	__int32 Unknown2;
	CHAR Name[12];
	CHAR unknown3[12];
	_Object *obj;
	CHAR unknown4[68];
	__int32 Team; 
	__int32 unknown5;
	__int8 IsDead;
};

class cPlayerInfo
{
public:
	__int32 Unknown0;
	__int32 index;
	__int32 Unknown1;
	__int32 Unknown2;
	CHAR Name[12];
	CHAR unknown3[12];
	int *obj;
	CHAR unknown4[68];
	__int32 Team; 
	__int32 unknown5;
	__int8 IsDead;
};



/*class cPlayerInfo{
public:
	char _0x0000[4];
	     __int32 Index; //0x0004 
    char _0x0008[8];
	char pName[12]; //0x0010 
    char _0x001C[12];
	int* Object; //0x0028 
	     __int32 pKills; //0x002C 
	     __int32 pDeaths; //0x0030 
    char _0x0034[48];
	     __int32 pFTMission; //0x0064 FireTeam Misson
    char _0x0068[8];
	     __int32 pTeam; //0x0070 
    char _0x0074[4];
	     BYTE pIsDead; //0x0078 
    char _0x0079[307];
	     __int32 pRank; //0x01AC 
    char _0x01B0[80];
	     __int32 pFTScore; //0x0200 FiteTeam Score 
    char _0x0204[4];
	     __int32 pFTLongestLife; //0x0208 FireTeam LongestLife  : Value / 60 = time
	     __int32 pFTKill; //0x020C FireTeam Kill score
    char _0x0210[80];
	cPlayerInfo* PlayerNext; //0x0260 

};*/

VOID DrawLine(LONG Xa, LONG Ya, LONG Xb, LONG Yb, DWORD dwWidth, D3DCOLOR Color)
{   
	D3DXVECTOR2 vLine[2];
	pLine->SetAntialias(0);

	pLine->SetWidth(dwWidth);
	pLine->Begin();

	vLine[0][0] = Xa;
	vLine[0][1] = Ya;
	vLine[1][0] = Xb;
	vLine[1][1] = Yb;

	pLine->Draw(vLine, 2, Color);
	pLine->End();
}

FLOAT FindDistance(D3DXVECTOR3 my, D3DXVECTOR3 other, PlayerInfo *pPlayer, PlayerInfo *pLocal)
{
	return sqrt((pLocal->obj->origin.x-pPlayer->obj->origin.x) * (pLocal->obj->origin.x-pPlayer->obj->origin.x) +
				(pLocal->obj->origin.y-pPlayer->obj->origin.y) * (pLocal->obj->origin.y-pPlayer->obj->origin.y) +
				(pLocal->obj->origin.z-pPlayer->obj->origin.z) * (pLocal->obj->origin.z-pPlayer->obj->origin.z));
}

BOOL WorldToScreen(LPDIRECT3DDEVICE9 pDevice, PlayerInfo *pPlayer, D3DXVECTOR3 *pScreen)
{
	D3DVIEWPORT9 oViewport;
	D3DXVECTOR3 dvWorld(pPlayer->obj->origin.x, pPlayer->obj->origin.y, pPlayer->obj->origin.z);
	pDevice->GetViewport(&oViewport);
	CILTDrawPrim *pDrawPrim = *(CILTDrawPrim **)DrawPrimitive;
	D3DXVec3Project(pScreen, &dvWorld, &oViewport, &pDrawPrim->Projection, &pDrawPrim->View, &pDrawPrim->World);

	if(pScreen->z < 1) {
		return TRUE;
	}
	return FALSE;	
}


void AngleVectors( const float* angles, float* forward, float* right, float* up )
{
	
	float angle;
	static float	sr, sp, sy, cr, cp, cy, t;

	angle = angles[YAW];
	sy = sin(angle);
	cy = cos(angle);

	angle = angles[PITCH];
	sp = sin(angle);
	cp = cos(angle);

	angle =  angles[ROLL];
	sr = sin(angle);
	cr = cos(angle);

	if( forward )
	{
		forward[0] = cp*cy;
		forward[1] = cp*sy;
		forward[2] = -sp;
	}
	if( right )
	{
		t = sr*sp;
		right[0] = ( -1*t*cy+-1*cr*-sy );
		right[1] = ( -1*t*sy+-1*cr*cy );
		right[2] = -1*sr*cp;
	}
	if( up )
	{
		t = cr*sp;
		up[0] = ( t*cy+-sr*-sy );
		up[1] = ( t*sy+-sr*cy );
		up[2] = cr*cp;
	}
}

void VectorAngles( const float* forward, float* angles )
{
	float tmp, yaw, pitch;

	if( forward[2] == 0 && forward[0] == 0 )
	{
		yaw = 0;

		if( forward[2] > 0 )
			pitch = 90;
		else
			pitch = 270;
	}
	else 
	{
		yaw = ( atan2( forward[2], -forward[0] ) * 179 / M_PI )-90;

		if( yaw < 0 )
			yaw += 359;

		tmp = sqrt( forward[0] * forward[0] + forward[2] * forward[2] );
		pitch = ( atan2( forward[1], tmp) * 179 / M_PI );

		if( pitch < 0 )
			pitch += 359; 
	}

	angles[0] = -pitch;
	angles[1] = yaw;
	angles[2] = 0;
}

void GetAngleToTarget(D3DXVECTOR3 vTargetPos, D3DXVECTOR3 vCameraPos, D3DXVECTOR3& vAngles)
{
	D3DXVECTOR3 vDelta;
	vDelta.x = vTargetPos.x - vCameraPos.x;
	vDelta.y = vTargetPos.y - vCameraPos.y;
	vDelta.z = vTargetPos.z - vCameraPos.z;

	VectorAngles( (float*)&vDelta, (float*)&vAngles );

	if( vAngles.x > 179.0f )          
		vAngles.x  -= 359.0f; 
	else if( vAngles.x < -179.0f )    
		vAngles.x   += 359.0f; 

	if( vAngles.y > 179.0f )            
		vAngles.y     -= 359.0f; 
	else if( vAngles.y < -179.0f )      
		vAngles.y    += 359.0f; 
}

D3DXVECTOR3 MyGetObjectMaxPos( 	int *obj ) 
{
	return *(D3DXVECTOR3*)( obj + 0x4 );
}

void DrawString(int x, int y, DWORD color, LPD3DXFONT Directx_Font, const char *fmt, ...)
{
	RECT FontPos = { x, y, x + 120, y + 16 };
	char buf[1024] = {'\0'};
	va_list va_alist;

	va_start(va_alist, fmt);
	vsprintf_s(buf, fmt, va_alist);
	va_end(va_alist);

	Directx_Font->DrawText(NULL, buf, -1, &FontPos, DT_NOCLIP, color);
}

void EspRGB( int x, int y, int w, int h, D3DCOLOR color, IDirect3DDevice9* pDevice )
{
	D3DRECT rec = { x, y, x + w, y + h };
	pDevice->Clear( 1, &rec, D3DCLEAR_TARGET, color, 0, 0 );
}

void PrintText(char pString[], int x, int y, D3DCOLOR col, ID3DXFont *font)
{
    RECT FontRect = { x, y, x+500, y+30 };
    font->DrawText( NULL, pString, -1, &FontRect, DT_LEFT | DT_WORDBREAK, col);
}

void EspBorder( int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice)
{
	EspRGB( x, (y + h - px), w, px,	BorderColor, pDevice );
	EspRGB( x, y, px, h,				BorderColor, pDevice );
	EspRGB( x, y, w, px,				BorderColor, pDevice );
	EspRGB( (x + w - px), y, px, h,	BorderColor, pDevice );
}

void Border( int x, int y, int w, int h, int px, D3DCOLOR BorderColor, IDirect3DDevice9* pDevice)
{
	EspRGB(x,(y + h - px), w, px, BorderColor, pDevice);
	EspRGB(x, y, px, h, BorderColor, pDevice);
	EspRGB(x, y, w, px, BorderColor, pDevice);
	EspRGB(x + w - px, y, px, h, BorderColor, pDevice);
}

#endif