#include "Base.h"
#include "Files.h"
#include "Classes.h"

VOID AngleVectors( const float* angles, float* forward, float* right, float* up );
VOID GetAngleToTarget(D3DXVECTOR3 vTargetPos, D3DXVECTOR3 vCameraPos, D3DXVECTOR3& vAngles);
VOID VectorAngles( const float* forward, float* angles );
VOID DrawLine( float X, float Y, float X2, float Y2, DWORD dwColor );
VOID DrawBorder( float x, float y, float w, float h, DWORD color1, DWORD color2 );
VOID __cdecl MoveObject(int* Object , D3DXVECTOR3 Pos) ;
bool WorldToScreen( D3DXVECTOR3 Pos, D3DXVECTOR3 *Screen );
VOID SetCvar( DWORD CVarBase, float Value );
DWORD BuildFontByFontIndex( int index, int FontSize );
INT GetFontHandle( int index );
VOID AimCorrection(INT Correct);
VOID InstantDamage( int Correct );
float OgAwepData[20][500];
bool SetWepData, StoreWepData;
VOID OneClip(INT Correct);
float OgBwepData[1][500];
bool SetWepData2, StoreWepData2;

void SetCvar( DWORD CVarBase, float Value )
{
	*(float*)( CVarBase + 0x48 ) = Value;
}

int GetFontHandle( int index )
{
	void* vGetFontHandle = (void*)Getfonthand;
	DWORD dwECX			 = *(DWORD*)Fontecx;

	__asm
	{
		push 0
		push index
		mov ecx, dwECX
		call [vGetFontHandle]
	}
}

DWORD BuildFontByFontIndex( int index, int FontSize )
{
	void* vBuildFont    = (void*)Buildfont;
	void* dwFill	    = (void*)Fillfont;
	int FontHandle      = GetFontHandle( index );
	DWORD dwFontAddr	= 0;
	BYTE* FontBuffer	= new BYTE[0x228];

	__asm
	{	
		mov ecx, FontBuffer
		call [dwFill]
		mov dwFontAddr, eax	
		mov ecx, eax
		push	0
		push	0
		push	0 
		push	0
		push	FontSize
		push	FontHandle
		push	0
		push	0
		push	0
		call	[vBuildFont]
	}
	return dwFontAddr;
}


bool WorldToScreen( D3DXVECTOR3 Pos, D3DXVECTOR3 *Screen )
{
	float x = Pos.x;
	float y = Pos.y;
	float z = Pos.z;

	D3DXVECTOR3 Unk;

	_asm
	{
		mov ecx, dword ptr ds:[DrawPrimitive]
		lea  eax, Unk
		push eax
		push Screen
		push z
		push y
		push x
		mov eax, W2S
		call eax
	}

	return( Screen->z < 1.0f );	
}

void __cdecl MoveObject(int* Object , D3DXVECTOR3 Pos) 
{ 
    _asm 
    { 
        MOV ECX,DWORD PTR DS:[LTClientDLL] 
        MOV EDX,DWORD PTR DS:[ECX] 
        PUSH 1 
        LEA EAX,Pos 
        PUSH EAX 
        PUSH Object 
        MOV EDX,DWORD PTR DS:[EDX + 0xC4] 
        CALL EDX 
    } 
}

void AimCorrection( int Correct )
{
	if( !StoreWepData )
	{	
		cWeaponMgr* WepMgr = *(cWeaponMgr**)WeaponManager;
			
		if( WepMgr )
		{
			for( int i = 0; i < WepMgr->WeaponCount; i++ )
			{ 
				cWeaponInfo* Wep = WepMgr->Weapons[i];

				if( Wep ) 
				{	
					OgAwepData[0][i] = Wep->fDuckPerturb;
					OgAwepData[1][i] = Wep->fMoveDuckPerturb;
					OgAwepData[2][i] = Wep->fPerturbIncSpeed;
					OgAwepData[3][i] = Wep->fPerturbDecSpeed;
					OgAwepData[4][i] = Wep->fCameraSwayXFreq;
					OgAwepData[5][i] = Wep->fCameraSwayYFreq;
					OgAwepData[6][i] = Wep->fZoomedPerturbIncSpeed;
					OgAwepData[7][i] = Wep->fZoomedPerturbDecSpeed; 
					OgAwepData[8][i] = Wep->fTripleShotMaxCamRecoilPitch;
					OgAwepData[9][i] = Wep->fTripleShotBaseCamRecoilPitch;
					OgAwepData[10][i] = Wep->fTripleShotPerturbIncSpeed;
					OgAwepData[11][i] = Wep->fTripleShotPerturbDecSpeed;
					OgAwepData[12][i] = Wep->fBaseCamRecoilPitch;
					OgAwepData[13][i] = Wep->fBaseCamRecoilAccelPitch;
					OgAwepData[14][i] = Wep->dwTripleShotMinPerturb;
					OgAwepData[15][i] = Wep->dwTripleShotMaxPerturb;
					OgAwepData[16][i] = Wep->dwMaxPerturb;
					OgAwepData[17][i] = Wep->dwMinPerturb;
					OgAwepData[18][i] = Wep->dwZoomedMaxPerturb;
					OgAwepData[19][i] = Wep->dwZoomedMinPerturb;
				} 
			}
		}
		StoreWepData = true;
	}

	if( Correct )
	{
		if( SetWepData )
		{
			cWeaponMgr* WepMgr = *(cWeaponMgr**)WeaponManager;

			if( WepMgr )
			{
				for( int i = 0; i < WepMgr->WeaponCount; i++ )
				{ 
					cWeaponInfo* Wep = WepMgr->Weapons[i];

					if( Wep ) 
					{	
						Wep->fDuckPerturb = 0.0f;
						Wep->fMoveDuckPerturb = 0.0f;
						Wep->fPerturbIncSpeed = 0.0f;
						Wep->fPerturbDecSpeed = 0.0f;
						Wep->fCameraSwayXFreq = 0.0f;
						Wep->fCameraSwayYFreq = 0.0f;
						Wep->fZoomedPerturbIncSpeed = 0.0f;
						Wep->fZoomedPerturbDecSpeed = 0.0f; 
						Wep->fTripleShotMaxCamRecoilPitch = 0.0f;
						Wep->fTripleShotBaseCamRecoilPitch = 0.0f;
						Wep->fTripleShotPerturbIncSpeed = 0.0f;
						Wep->fTripleShotPerturbDecSpeed = 0.0f;
						Wep->fBaseCamRecoilPitch = 0.0f;
						Wep->fBaseCamRecoilAccelPitch = 0.0f;
						Wep->dwTripleShotMinPerturb = 0.0f;
						Wep->dwTripleShotMaxPerturb = 0.0f;
						Wep->dwMaxPerturb = 0.0f;
						Wep->dwMinPerturb = 0.0f;
						Wep->dwZoomedMaxPerturb = 0.0f;
						Wep->dwZoomedMinPerturb = 0.0f;
					} 
				}
			}
			SetWepData = false;
		}
	}
	else
	{	
		if( !SetWepData )
		{
			cWeaponMgr* WepMgr = *(cWeaponMgr**)WeaponManager;

			if( WepMgr )
			{
				for( int i = 0; i < WepMgr->WeaponCount; i++ )
				{ 
					cWeaponInfo* Wep = WepMgr->Weapons[i];

					if( Wep ) 
					{	
						Wep->fDuckPerturb = OgAwepData[0][i];
						Wep->fMoveDuckPerturb = OgAwepData[1][i];
						Wep->fPerturbIncSpeed = OgAwepData[2][i];
						Wep->fPerturbDecSpeed = OgAwepData[3][i];
						Wep->fCameraSwayXFreq = OgAwepData[4][i];
						Wep->fCameraSwayYFreq = OgAwepData[5][i];
						Wep->fZoomedPerturbIncSpeed = OgAwepData[6][i];
						Wep->fZoomedPerturbDecSpeed = OgAwepData[7][i]; 
						Wep->fTripleShotMaxCamRecoilPitch = OgAwepData[8][i];
						Wep->fTripleShotBaseCamRecoilPitch = OgAwepData[9][i];
						Wep->fTripleShotPerturbIncSpeed = OgAwepData[10][i];
						Wep->fTripleShotPerturbDecSpeed = OgAwepData[11][i];
						Wep->fBaseCamRecoilPitch = OgAwepData[12][i];
						Wep->fBaseCamRecoilAccelPitch = OgAwepData[13][i];
						Wep->dwTripleShotMinPerturb = OgAwepData[14][i];
						Wep->dwTripleShotMaxPerturb = OgAwepData[15][i];
						Wep->dwMaxPerturb = OgAwepData[16][i];
						Wep->dwMinPerturb = OgAwepData[17][i];
						Wep->dwZoomedMaxPerturb = OgAwepData[18][i];
						Wep->dwZoomedMinPerturb = OgAwepData[19][i];
					} 
				}
			}
			SetWepData = true;
		}
	}
}
void OneClip( int Correct ) 
{ 
    if( !StoreWepData2 ) 
    { 
        cWeaponMgr* WepMgr = *(cWeaponMgr**)WeaponManager; 
             
        if( WepMgr ) 
        { 
            for( int i = 0; i < WepMgr->WeaponCount; i++ ) 
            {  
                cWeaponInfo* Wep = WepMgr->Weapons[i]; 

                if( Wep )  
                {     
                    OgBwepData[0][i] = Wep->dwShotsPerClip; 
                }  
            } 
        } 
        StoreWepData2 = true; 
    } 

    if( Correct ) 
    { 
        if( SetWepData2 ) 
        { 
            cWeaponMgr* WepMgr = *(cWeaponMgr**)WeaponManager; 

            if( WepMgr ) 
            { 
                for( int i = 0; i < WepMgr->WeaponCount; i++ ) 
                {  
                    cWeaponInfo* Wep = WepMgr->Weapons[i]; 

                    if( Wep )  
                    {     
                        Wep->dwShotsPerClip = 999; 
                    }  
                } 
            } 
            SetWepData2 = false; 
        } 
    } 
    if(!Correct) 
    {     
        if( !SetWepData2 ) 
        { 
            cWeaponMgr* WepMgr = *(cWeaponMgr**)WeaponManager; 

            if( WepMgr ) 
            { 
                for( int i = 0; i < WepMgr->WeaponCount; i++ ) 
                {  
                    cWeaponInfo* Wep = WepMgr->Weapons[i]; 

                    if( Wep )  
                    {     
                        Wep->dwShotsPerClip = OgBwepData[0][i]; 
                    }  
                } 
            } 
            SetWepData2 = true; 
        } 
    } 
}
