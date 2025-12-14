#include "ESP.h"
BOOL Ready = TRUE;

INT GetNearestToCrosshair(int FOV)
{
	FLOAT Distance = 0.0f; INT iAimAt = -1; FLOAT fNearest = (FLOAT)INT_MAX;
	if (ValidPointer(SFXMgr))
	{
		for (INT i = 0; i < SFXMgr->m_dynSFXLists[SFX_List::sfx_character].m_nElements; i++)
		{
			cCharacterFX* Player = (cCharacterFX*)SFXMgr->m_dynSFXLists[SFX_List::sfx_character].m_pAgeArray[i];
			if (ValidPointer(Player) && ValidPointer(Player->baseclass_0.p_hServerObject))
			{
				cCLIENT_INFO* pPlayer = GetPlayerByIndex(ulThisCustom, Player->m_nID);
				cCLIENT_INFO* pLocal = GetLocalPlayer(ulThisCustom);
				if (ValidPointer(pPlayer) && !pPlayer->baseclass_0.bDead)
				{
					D3DXVECTOR3 CameraPos = ConvertPosition(m_pPlayerMgr->m_hCamera); Transform AimTransform; oILTCSBase->ILTModel->GetNodeTransform((INT*)Player->baseclass_0.p_hServerObject, 8, &AimTransform, TRUE);
					if (pPlayer->baseclass_0.nTeam != pLocal->baseclass_0.nTeam)
					{
						if (Player->m_bNoDamagedPlayer) continue; if (!IsCamVisible(AimTransform.m_Pos)) continue;
						if (!GetAimbotFOV(FOV, ConvertPosition(m_pPlayerMgr->m_hCamera), AimTransform.m_Pos)) continue; D3DXVECTOR3 Out; if (!WorldToScreens(&AimTransform.m_Pos, &Out)) continue; Out.z = 0;
						D3DXVECTOR3 Screen((FLOAT)(ViewPort.Width / 2), (FLOAT)(ViewPort.Height / 2), 0.0f); D3DXVECTOR3 Pos = (Out - Screen); DOUBLE Dist = ((Pos.x * Pos.x) + (Pos.y * Pos.y) + (Pos.z * Pos.z));
						if (Dist < fNearest) { fNearest = Dist; iAimAt = i; }
					}
				}
			}
		}
	}return iAimAt;
}
VOID EnemyAimbot()
{
	INT NearestEnemy = -1;
	if (cheat::aimbot::Activation == 1)
	{
		if (GetAsyncKeyState(cheat::aimbot::AimKey) < 0)
		{
			if (NearestEnemy == -1 && Ready) { NearestEnemy = GetNearestToCrosshair(cheat::aimbot::AimFov); }
			if (NearestEnemy != -1 && Ready)
			{
				Transform AimTransform; D3DXVECTOR3 newAngles = { 0.0f, 0.0f, 0.0f }; D3DXVECTOR3 curAngles = { 0.0f, 0.0f, 0.0f };
				if (ValidPointer(SFXMgr))
				{
					cCharacterFX* pPlayer = (cCharacterFX*)SFXMgr->m_dynSFXLists[SFX_List::sfx_character].m_pAgeArray[NearestEnemy];
					if (ValidPointer(pPlayer) && ValidPointer(pPlayer->baseclass_0.p_hServerObject))
					{
						switch (cheat::aimbot::AimBone)
						{
						case 0: oILTCSBase->ILTModel->GetNodeTransform(pPlayer->baseclass_0.p_hServerObject, 8, &AimTransform, TRUE); AimTransform.m_Pos.y += 6.0f; break;
						case 1: oILTCSBase->ILTModel->GetNodeTransform(pPlayer->baseclass_0.p_hServerObject, 7, &AimTransform, TRUE); break;
						case 2: oILTCSBase->ILTModel->GetNodeTransform(pPlayer->baseclass_0.p_hServerObject, 6, &AimTransform, TRUE); AimTransform.m_Pos.y -= 2.0f; break;
						case 3: oILTCSBase->ILTModel->GetNodeTransform(pPlayer->baseclass_0.p_hServerObject, 4, &AimTransform, TRUE); AimTransform.m_Pos.y -= 6.0f; break;
						}
						GetAngleToTarget(AimTransform.m_Pos, ConvertPosition(m_pPlayerMgr->m_hCamera), newAngles);
						curAngles.x = D3DXToDegree(m_pPlayerMgr->m_fPitch); curAngles.y = D3DXToDegree(m_pPlayerMgr->m_fYaw);
						if (cheat::aimbot::SmoothAim) { cheat::aimbot::SmoothMax = 1.0f - cheat::aimbot::SmoothMin; LimitRotation(curAngles.y, curAngles.x, &newAngles.y, &newAngles.x, cheat::aimbot::SmoothMax); }
						m_pPlayerMgr->m_fYaw = DegToRad(newAngles.y); m_pPlayerMgr->m_fPitch = DegToRad(newAngles.x);
						Ready = TRUE; NearestEnemy = -1;
					}
				}
			}
			else { Ready = TRUE; NearestEnemy = -1; }
		}
	}
}

INT GetNearestNPCToCrosshair(INT FOV)
{
	INT iAimAt = -1; FLOAT fNearest = (FLOAT)INT_MAX;
	if (ValidPointer(SFXMgr))
	{
		for (INT i = 0; i < SFXMgr->m_dynSFXLists[SFX_List::sfx_character].m_nElements; i++)
		{
			cCharacterFX* Player = (cCharacterFX*)SFXMgr->m_dynSFXLists[SFX_List::sfx_character].m_pAgeArray[i];
			if (ValidPointer(Player) && ValidPointer(Player->baseclass_0.p_hServerObject))
			{
				Transform AimTransform; oILTCSBase->ILTModel->GetNodeTransform((INT*)Player->baseclass_0.p_hServerObject, 8, &AimTransform, TRUE); D3DXVECTOR3 CameraPos = ConvertPosition(m_pPlayerMgr->m_hCamera);
				if (!Player->m_cs.bIsPlayer)
				{
					if (!IsCamVisible(AimTransform.m_Pos)) continue; if (!GetAimbotFOV(FOV, ConvertPosition(m_pPlayerMgr->m_hCamera), AimTransform.m_Pos)) continue; D3DXVECTOR3 Out;
					if (!WorldToScreens(&AimTransform.m_Pos, &Out)) continue; Out.z = 0; D3DXVECTOR3 Screen((FLOAT)(ViewPort.Width / 2), (FLOAT)(ViewPort.Height / 2), 0.0f); D3DXVECTOR3 Pos = (Out - Screen); FLOAT Dist = sqrt((Pos.x * Pos.x) + (Pos.y * Pos.y) + (Pos.z * Pos.z));
					if (Dist < fNearest) { fNearest = Dist; iAimAt = i; }
				}
			}
		}
	}return iAimAt;
}
VOID NPCAimbot()
{
	INT BestNPC = -1;
	if (cheat::aimbot::Activation == 1)
	{
		if (GetAsyncKeyState(cheat::aimbot::AimKey) & 0x8000)
		{
			if (!ValidPointer(SFXMgr)) return;
			if (BestNPC == -1 && Ready) { BestNPC = GetNearestNPCToCrosshair(cheat::aimbot::AimFov); }
			if (BestNPC != -1 && Ready)
			{
				Transform AimTransform; D3DXVECTOR3 newAngles = { 0.0f, 0.0f, 0.0f }; D3DXVECTOR3 curAngles = { 0.0f, 0.0f, 0.0f };
				if (!ValidPointer(SFXMgr)) return;
				cCharacterFX* NPC = (cCharacterFX*)SFXMgr->m_dynSFXLists[SFX_List::sfx_character].m_pAgeArray[BestNPC];
				if (!ValidPointer(NPC)) return;
				switch (cheat::aimbot::AimBone)
				{
				case 0: oILTCSBase->ILTModel->GetNodeTransform(NPC->baseclass_0.p_hServerObject, 8, &AimTransform, TRUE); AimTransform.m_Pos.y += 6.0f; break;
				case 1: oILTCSBase->ILTModel->GetNodeTransform(NPC->baseclass_0.p_hServerObject, 7, &AimTransform, TRUE); break;
				case 2: oILTCSBase->ILTModel->GetNodeTransform(NPC->baseclass_0.p_hServerObject, 6, &AimTransform, TRUE); AimTransform.m_Pos.y -= 2.0f; break;
				case 3: oILTCSBase->ILTModel->GetNodeTransform(NPC->baseclass_0.p_hServerObject, 4, &AimTransform, TRUE); AimTransform.m_Pos.y -= 6.0f; break;
				}
				GetAngleToTarget(AimTransform.m_Pos, ConvertPosition(m_pPlayerMgr->m_hCamera), newAngles);
				curAngles.y = D3DXToDegree(m_pPlayerMgr->m_fYaw); curAngles.x = D3DXToDegree(m_pPlayerMgr->m_fPitch);
				if (cheat::aimbot::SmoothAim) { cheat::aimbot::SmoothMax = 1.0f - cheat::aimbot::SmoothMin; LimitRotation(curAngles.y, curAngles.x, &newAngles.y, &newAngles.x, cheat::aimbot::SmoothMax); }
				m_pPlayerMgr->m_fYaw = DegToRad(newAngles.y); m_pPlayerMgr->m_fPitch = DegToRad(newAngles.x);
				BestNPC = -1; Ready = TRUE;
			}
		}
		else { BestNPC = -1; Ready = TRUE; }
	}
}

void UseAimbot()
{
	__asm CALL[EnemyAimbot];
	__asm CALL[NPCAimbot];
}
typedef float(__fastcall* tModelNodeRadius)(void* pThis, int SkelModel, int ModelNode); tModelNodeRadius oModelNodeRadius;
float __fastcall Hook_CModelButeMgrGetSkeletonNodeHitRadius(void* pThis, void* edx, int SkelModel, int ModelNode)
{
	float returnHit = oModelNodeRadius(pThis, SkelModel, ModelNode);
	if (cheat::aimbot::Ghost::Radius::Activation)
	{
		returnHit = 100.0f;
	}
	return returnHit;
}
void InstallCModelButeMgrGetSkeletonNodeHitRadius()
{
	uintptr_t targetAddr = PatternScan(0, ___("8B 54 24 04 85 D2 7C 50"));
	if (MH_CreateHook((LPVOID)targetAddr, &Hook_CModelButeMgrGetSkeletonNodeHitRadius, (LPVOID*)&oModelNodeRadius) != MH_OK) { MessageBoxA(0, ___("[Error] Failed to create hook for CModelButeMgr::GetSkeletonNodeHitRadius"), "Information", MB_ICONWARNING); }
	if (MH_EnableHook((LPVOID)targetAddr) != MH_OK) { MessageBoxA(0, ___("[Error] Failed to enable hook for CModelButeMgr::GetSkeletonNodeHitRadius"), "Information", MB_ICONWARNING); }
}