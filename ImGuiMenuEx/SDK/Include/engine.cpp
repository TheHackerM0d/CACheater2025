#include "engine.h"

cEngine*   engine	= NULL;

cEngine::cEngine( void )
{
	pClientShellBase	= NULL;
	pGameClientShell	= NULL;
	pClientInfoMgr		= NULL;
	pPlayerManager		= NULL;
	pLTDrawPrim			= NULL;
	pLTClient			= NULL;
	pLTModel			= NULL;
	pLTBase				= NULL;
	pLocal				= NULL;

	pWarningFont		= NULL;
	pSmallFont			= NULL;
	pMenuFont			= NULL;

	dwClientFxEntry		= (DWORD)GetModuleHandle( STRING_CLIENTFXDOTFXD );
}

void cEngine::InitEnginePointers( void )
{
#ifdef _DEBUG_
	tools->add_log( STRING_LOGFILE, "\nIniting Ptrs!->LoL( $$$$ )" );

	pClientShellBase	= (cLTClientShellBase*)ADDR_LTCSBASE;

	if( ValidPointer( pClientShellBase ) )
	{	
		pLTModel			= (cLTModel*)pClientShellBase->ILTModel;
		tools->add_log( STRING_LOGFILE, "cLTModel[ 0x%x ]", (DWORD)pLTModel );

		pLTDrawPrim			= *(cLTDrawPrim**)pClientShellBase->ILTDrawPrim;
		tools->add_log( STRING_LOGFILE, "DrawPrim1 0x%x DrawPrim2 0x%x", (DWORD)pLTDrawPrim, (DWORD)&pLTDrawPrim );

		pLTBase				= (cLTBase*)pClientShellBase->ILTBase;
		tools->add_log( STRING_LOGFILE, "cLTBase[ 0x%x ]", (DWORD)pLTBase );

		pGameClientShell	= *(cGameClientShell**)ADDR_GCS;
		tools->add_log( STRING_LOGFILE, "Game Client Shell[ 0x%x ]", (DWORD)pGameClientShell );
		tools->add_log( STRING_LOGFILE, "w2s 0x%x", (DWORD)&pLTDrawPrim->WorldToScreen );

		if( ValidPointer( pLTBase ) && ValidPointer( pGameClientShell ) )
		{
			pClientInfoMgr	= (cClientInfoMgr*)pGameClientShell->GetClientInfoMgr();
			tools->add_log( STRING_LOGFILE, "ClientInfoMgr[ 0x%x ]", (DWORD)pClientInfoMgr );

			pPlayerManager	= (cPlayerMgr*)pGameClientShell->GetPlayerManager();
			tools->add_log( STRING_LOGFILE, "PlayerManager[ 0x%x ]", (DWORD)pPlayerManager );

			pLTClient		= (cLTClient*)pLTBase->ILTClient;
			tools->add_log( STRING_LOGFILE, "cLTClient[ 0x%x ]", (DWORD)pLTClient );

			pLocal			= (LocalInfo*)ADDR_LOCALPTR;
			tools->add_log( STRING_LOGFILE, "Local[ 0x%x ]", (DWORD)pLocal );
		}
	}

#else
	pClientShellBase	= (cLTClientShellBase*)ADDR_LTCSBASE;
	
	if( ValidPointer( pClientShellBase ) )
	{
		pLTModel			= (cLTModel*)pClientShellBase->ILTModel;

		//pLTDrawPrim		= *(cLTDrawPrim**)pClientShellBase->ILTDrawPrim;

		pLTBase				= (cLTBase*)pClientShellBase->ILTBase;
		pGameClientShell	= *(cGameClientShell**)ADDR_GCS;

		if( ValidPointer( pLTBase ) && ValidPointer( pGameClientShell ) )
		{
			pClientInfoMgr		= (cClientInfoMgr*)pGameClientShell->GetClientInfoMgr();
			pPlayerManager		= (cPlayerMgr*)pGameClientShell->GetPlayerManager();
			pLTClient			= (cLTClient*)pLTBase->ILTClient;
			pLocal				= (LocalInfo*)ADDR_LOCALPTR;
		}
	}
#endif
}

void cEngine::InitFonts( void )
{
	pSmallFont		= (cFont*)BuildFontByFontIndex( 24, 12 );
	pWarningFont	= (cFont*)BuildFontByFontIndex( 15, 25 );
	pMenuFont		= (cFont*)BuildFontByFontIndex( 25, 13 );

#ifdef _DEBUG_
	tools->add_log( STRING_LOGFILE, STRING_DEBUG_FONTINIT );
#endif
}

int cEngine::GetFontHandle( int index )
{
	void* vGetFontHandle = (void*)ADDR_GETFONTHAND;
	DWORD dwECX			 = *(DWORD*)ADDR_FONTECX;

	__asm
	{
		push 0
		push index
		mov ecx, dwECX
		call [vGetFontHandle]
	}
}

DWORD cEngine::BuildFontByFontIndex( int index, int FontSize )
{
	void* vBuildFont    = (void*)ADDR_BUILDFONT;
	void* dwFill	    = (void*)ADDR_FILLFONT;
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

void cEngine::RenderString( cFont* Renderer, int x, int y, std::wstring text, DWORD color )
{
	if( Renderer )
	{
		Renderer->SetText( (unsigned short*)text.c_str(), 1 );
		Renderer->SetPos( x, y );
		Renderer->SetColor( color, color, color, (int)-1 );
		Renderer->Render();
	}
}

bool __cdecl cEngine::IsVisible( D3DXVECTOR3 Point )
{
	IntersectQuery iQuery;
	IntersectInfo iInfo;	

	memset( &iQuery, 0, sizeof(iQuery) );	

	iQuery.Start  = esp->local.CameraPos; 
	iQuery.End    = Point;

	return !engine->GetLTBase()->IntersectSegment( iQuery, &iInfo );
}

bool MyFilterObjects( int* hObj, void* pUser )
{
	cSFXMgr* SFXMgr = engine->GetGameClientShell()->GetSFXMgr();

	if( engine->ValidPointer( SFXMgr ) )
	{
		for( int i = 0; i < SFXMgr->SFXList[SFX_CHARACTER].Num; i++ )
		{
			cCharacterFX* fx = (cCharacterFX*)SFXMgr->SFXList[SFX_CHARACTER].List[i];

			if( engine->ValidPointer( fx ) && engine->ValidPointer( fx->Object ) )
				if( hObj == fx->hHitbox )
					return true;
		}
	}
	return false;
}

bool IntersectAndPenetrateSegment( IntersectQuery* iQuery, IntersectInfo* qInfo ) //erro aqui
{
	if((int)menu->iRemoteKill == 3)
	{
		int NearestEnemy;


			NearestEnemy = aimbot->GetNearestToCrosshair3( (int)menu->cBox[63].OnOff, 0, 0, (int)menu->cBox[62].OnOff );

		 	if( esp->bValidObject( NearestEnemy ) && esp->bValidCords( NearestEnemy ) && !esp->Players[NearestEnemy].bIsDead )
 			{
				if(esp->Players[NearestEnemy].Charector->pTeam != esp->local.iTeam)
 				{
						iQuery->Start    = esp->Players[NearestEnemy].AimTransform1.Pos + D3DXVECTOR3( 0.0f, 50.0f, 0.0f );
 						iQuery->End      = esp->Players[NearestEnemy].AimTransform1.Pos - D3DXVECTOR3( 0.0f, 50.0f, 0.0f );
 						iQuery->FilterFn = MyFilterObjects;
 
 						bool Result      = engine->GetLTBase()->IntersectSegment( *iQuery, qInfo );
 
 						if( Result )
 						{
 							qInfo->hObjImpact = esp->Players[NearestEnemy].SFXOBJ->hHitbox;
 							qInfo->vImpactPos = esp->Players[NearestEnemy].AimTransform1.Pos;
 						}
 						return Result;
				}
			}			
	    }

 	if((int)menu->iRemoteKill == 1)
 	{

		int NearestEnemy;

		if (menu->AimMode1 + 1 == 1)
			NearestEnemy = aimbot->GetNearestPlayer2( (int)menu->cBox[63].OnOff,  menu->AimBone1 + 1, 0, (int)menu->cBox[62].OnOff, 1 );
		else
			NearestEnemy = aimbot->GetNearestToCrosshair2( (int)menu->cBox[63].OnOff, 0, 0, (int)menu->cBox[62].OnOff );

		 	if( esp->bValidObject( NearestEnemy ) && esp->bValidCords( NearestEnemy ) && !esp->Players[NearestEnemy].bIsDead )
 			{
				if(esp->Players[NearestEnemy].Charector->pTeam != esp->local.iTeam)
 				{
						iQuery->Start    = esp->Players[NearestEnemy].AimTransform1.Pos + D3DXVECTOR3( 0.0f, 50.0f, 0.0f );
 						iQuery->End      = esp->Players[NearestEnemy].AimTransform1.Pos - D3DXVECTOR3( 0.0f, 50.0f, 0.0f );
 						iQuery->FilterFn = MyFilterObjects;
 
 						bool Result      = engine->GetLTBase()->IntersectSegment( *iQuery, qInfo );
 
 						if( Result )
 						{
 							qInfo->hObjImpact = esp->Players[NearestEnemy].SFXOBJ->hHitbox;
 							qInfo->vImpactPos = esp->Players[NearestEnemy].AimTransform1.Pos;
 						}
 						return Result;
				}
		   }		
 	  }

	if((int)menu->iRemoteKill == 2)
 	{
	
		int NearestEnemy;
		if (menu->AimMode1 + 1 == 1)
			NearestEnemy = aimbot->GetNearestNPC( (int)menu->cBox[63].OnOff, menu->AimBone1 + 1,1 );
		else
			NearestEnemy = aimbot->GetNearestNPCToCrosshair( (int)menu->cBox[63].OnOff, menu->AimBone1 + 1 );

		    cCharacterFX* Character = (cCharacterFX*)engine->GetGameClientShell()->GetSFXMgr()->SFXList[SFX_CHARACTER].List[NearestEnemy];

				if( engine->ValidPointer( Character ) && engine->ValidPointer( Character->Object ) )
				{
					Transform HeadTransform;
					unsigned int AimSpot;

					switch(  menu->AimBone1 + 1 )
					{
						case 1:
							AimSpot = engine->GetLTModel()->GetNodeTransform( Character->Object, 8, &HeadTransform,  true );
							HeadTransform.Pos.y += 5.8f;
							break;

						case 2:
							AimSpot = engine->GetLTModel()->GetNodeTransform( Character->Object, 6, &HeadTransform,  true );
							break;

						case 3:
							AimSpot = engine->GetLTModel()->GetNodeTransform( Character->Object, 7, &HeadTransform,  true );
							break;

						case 4:
							AimSpot = engine->GetLTModel()->GetNodeTransform( Character->Object, 4, &HeadTransform,  true );
							HeadTransform.Pos.y -= 6.0f;
							break;
					}


				iQuery->Start    = HeadTransform.Pos + D3DXVECTOR3( 0.0f, 50.0f, 0.0f );
 				iQuery->End      = HeadTransform.Pos - D3DXVECTOR3( 0.0f, 50.0f, 0.0f );
 				iQuery->FilterFn = MyFilterObjects;
 
 						bool Result      = engine->GetLTBase()->IntersectSegment( *iQuery, qInfo );
 
 				if( Result )
 				{
 					qInfo->hObjImpact = Character->hHitbox;
 					qInfo->vImpactPos = HeadTransform.Pos;
 				}
 				return Result;
		}
	}
}

bool cEngine::WorldToScreen( D3DXVECTOR3 Pos, D3DXVECTOR3 *Screen )
{
	float x = Pos.x;
	float y = Pos.y;
	float z = Pos.z;

	D3DXVECTOR3 Unk;

	_asm
	{
		mov ecx, dword ptr ds:[ADDR_DRAWPRIM]
		lea  eax, Unk
		push eax
		push Screen
		push z
		push y
		push x
		mov eax, ADDR_W2S
		call eax
	}

	return( Screen->z < 1.0f );	
}

int cEngine::GetConsoleInt( char* cmd, int value )
{
	_asm
	{
		push value
		push cmd
		mov eax, ADDR_GETCONSOLEINT
		call eax
		add esp, 8
	}
}

void __cdecl cEngine::RunConsoleCommand( char* cCommand )
{
	void* address = ( void* ) ADDR_CONSOLEUNWRAPPED;

	__asm
	{
		push cCommand
		call address
		add esp, 0x4
	}
}

void cEngine::SetLocalPlayerPosition( D3DXVECTOR3 Pos )
{
	DWORD dwClass = *(DWORD*)( dwClientFxEntry + ADDR_CLIENTFX );

	if( dwClass == NULL )
		return;

	*(float*)( dwClass + 0xC8 ) = Pos.x;
	*(float*)( dwClass + 0xCC ) = Pos.y;
	*(float*)( dwClass + 0xD0 ) = Pos.z;
}
D3DXVECTOR3 cEngine::GetLocalPlayerPosition()
{
DWORD dwClass = *(DWORD*)( dwClientFxEntry + ADDR_CLIENTFX );

	float x = *(float*)( dwClass + 0xC8 );
	float y = *(float*)( dwClass + 0xCC );
	float z = *(float*)( dwClass + 0xD0 );
	return (D3DXVECTOR3(x, y, z));
}

void __cdecl cEngine::MoveObject(int* Object , D3DXVECTOR3 Pos)
{
	_asm
	{
		MOV ECX,DWORD PTR DS: [ADDR_LTCLIENT]
		MOV EDX,DWORD PTR DS: [ECX]
		PUSH 1
		LEA EAX,Pos
		PUSH EAX
		PUSH Object
		MOV EDX,DWORD PTR DS: [EDX + 0xC4]
		CALL EDX
	}
}

void cEngine::SetCvar( DWORD CVarBase, float Value )
{
	*(float*)( CVarBase + 0x48 ) = Value;
}

bool cEngine::ValidGamePointers( void )
{
	if( ValidPointer( pClientShellBase )
	 && ValidPointer( pGameClientShell ) 
	 && ValidPointer( pLTModel ) 
	 && ValidPointer( pLTBase ) 
	 && ValidPointer( pLTClient )
	 && ValidPointer( pClientInfoMgr )

#ifdef _DEBUG
	 && ValidPointer( pLTDrawPrim )
#endif

	 && ValidPointer( pPlayerManager ) 
	 && ValidPointer( pLocal ) )
		return true;

	return false;
}