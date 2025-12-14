#include "Engine.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////
void DrawEnemyESP(LPDIRECT3DDEVICE9 pDevice)
{
	if (!cheat::esp::Ennemy::Activation || !ValidPointer(SFXMgr)) return;
	cCLIENT_INFO* pLocal = GetLocalPlayer(ulThisCustom);
	if (!ValidPointer(pLocal)) return;
	for (INT i = 0; i < SFXMgr->m_dynSFXLists[sfx_character].m_nElements; i++)
	{
		cCharacterFX* playerFx = reinterpret_cast<cCharacterFX*>(SFXMgr->m_dynSFXLists[sfx_character].m_pAgeArray[i]);
		if (!ValidPointer(playerFx) || !ValidPointer(playerFx->baseclass_0.p_hServerObject))continue;
		cCLIENT_INFO* pPlayer = GetPlayerByIndex(ulThisCustom, playerFx->m_nID);
		if (!ValidPointer(pPlayer) || pPlayer->baseclass_0.bDead)continue;
		if (pPlayer->baseclass_0.nTeam == pLocal->baseclass_0.nTeam)continue;
		Transform headTf, footTf;
		oILTCSBase->ILTModel->GetNodeTransform((INT*)playerFx->baseclass_0.p_hServerObject, 8, &headTf, TRUE);
		oILTCSBase->ILTModel->GetNodeTransform((INT*)playerFx->baseclass_0.p_hServerObject, 4, &footTf, TRUE);
		headTf.m_Pos.y += 5.8f;
		D3DXVECTOR3 headScreen, footScreen, footWorld;
		footWorld = D3DXVECTOR3(headTf.m_Pos.x, headTf.m_Pos.y - 74.0f, headTf.m_Pos.z);
		if (!WorldToScreen(pDevice, headTf.m_Pos, &headScreen) || !WorldToScreen(pDevice, footWorld, &footScreen))continue;
		bool bVisible = IsCamVisible(headTf.m_Pos);
		bool bSpawnShield = playerFx->m_bNoDamagedPlayer;
		D3DCOLOR espColor = D3DCOLORCOLOR(cheat::esp::Ennemy::NonVisible); // par défaut : rouge foncé
		if (bVisible) espColor = D3DCOLORCOLOR(cheat::esp::Ennemy::Visible);
		if (bSpawnShield) espColor = D3DCOLORCOLOR(cheat::esp::Ennemy::Respawn);
		float height = footScreen.y - headScreen.y; float width = height / 2.0f;
		float x = headScreen.x - (width / 2.0f); float y = headScreen.y;
		if (cheat::esp::Ennemy::Box) DrawESPBox(x, y, width, height, espColor, pDevice); // Rouge vif
		if (cheat::esp::Ennemy::Health) DrawHealthBars(headScreen, footScreen, playerFx->m_nHealth, pDevice);
		if (cheat::esp::Ennemy::Lines) DrawLine(0, 0, footScreen.x, footScreen.y + 3.0f, 1, espColor, pDevice);
	}
}
void DrawAlliesESP(LPDIRECT3DDEVICE9 pDevice)
{
	if (!cheat::esp::Allies::Activation || !ValidPointer(SFXMgr))return;
	cCLIENT_INFO* pLocal = GetLocalPlayer(ulThisCustom);
	if (!ValidPointer(pLocal))return;
	for (INT i = 0; i < SFXMgr->m_dynSFXLists[sfx_character].m_nElements; i++)
	{
		cCharacterFX* playerFx = reinterpret_cast<cCharacterFX*>(SFXMgr->m_dynSFXLists[sfx_character].m_pAgeArray[i]);
		if (!ValidPointer(playerFx) || !ValidPointer(playerFx->baseclass_0.p_hServerObject))continue;
		cCLIENT_INFO* pPlayer = GetPlayerByIndex(ulThisCustom, playerFx->m_nID);
		if (!ValidPointer(pPlayer) || pPlayer->baseclass_0.bDead)continue;
		if (pPlayer->baseclass_0.nTeam != pLocal->baseclass_0.nTeam || pPlayer->baseclass_0.nID == pLocal->baseclass_0.nID)continue;
		Transform headTf, footTf;
		oILTCSBase->ILTModel->GetNodeTransform((INT*)playerFx->baseclass_0.p_hServerObject, 8, &headTf, TRUE);
		oILTCSBase->ILTModel->GetNodeTransform((INT*)playerFx->baseclass_0.p_hServerObject, 4, &footTf, TRUE);
		headTf.m_Pos.y += 5.8f;
		D3DXVECTOR3 headScreen, footScreen, footWorld;
		footWorld = D3DXVECTOR3(headTf.m_Pos.x, headTf.m_Pos.y - 74.0f, headTf.m_Pos.z);
		if (!WorldToScreen(pDevice, headTf.m_Pos, &headScreen) || !WorldToScreen(pDevice, footWorld, &footScreen)) continue;
		bool bVisible = IsCamVisible(headTf.m_Pos); bool bSpawnShield = playerFx->m_bNoDamagedPlayer;
		D3DCOLOR espColor = D3DCOLORCOLOR(cheat::esp::Allies::NonVisible); // par défaut : rouge foncé
		if (bVisible) espColor = D3DCOLORCOLOR(cheat::esp::Allies::Visible);
		if (bSpawnShield ) espColor = D3DCOLORCOLOR(cheat::esp::Allies::Respawn);
		float height = footScreen.y - headScreen.y;
		float width = height / 2.0f; float x = headScreen.x - (width / 2.0f); float y = headScreen.y;
		if (cheat::esp::Allies::Box) DrawESPBox(x, y, width, height, espColor, pDevice);
		if (cheat::esp::Allies::Health) DrawHealthBars(headScreen, footScreen, playerFx->m_nHealth, pDevice);
		if (cheat::esp::Allies::Lines) DrawLine(0, 0, footScreen.x, footScreen.y + 3.0f, 1, espColor, pDevice);
	}
}
void DrawNPCESP(LPDIRECT3DDEVICE9 pDevice)
{
	if (!cheat::esp::Ennemy::Activation || !ValidPointer(SFXMgr) || !pDevice)return;
	cCLIENT_INFO* pLocal = GetLocalPlayer(ulThisCustom);
	if (!ValidPointer(pLocal))return;

	for (int i = 0; i < SFXMgr->m_dynSFXLists[sfx_character].m_nElements; i++)
	{
		cCharacterFX* npcFx = reinterpret_cast<cCharacterFX*>(SFXMgr->m_dynSFXLists[sfx_character].m_pAgeArray[i]);
		if (!ValidPointer(npcFx) || !ValidPointer(npcFx->baseclass_0.p_hServerObject))continue;
		if (npcFx->m_cs.bIsPlayer)continue;
		Transform headTf, footTf;
		oILTCSBase->ILTModel->GetNodeTransform((INT*)npcFx->baseclass_0.p_hServerObject, 8, &headTf, TRUE);
		oILTCSBase->ILTModel->GetNodeTransform((INT*)npcFx->baseclass_0.p_hServerObject, 4, &footTf, TRUE);
		headTf.m_Pos.y += 5.8f;
		D3DXVECTOR3 footWorld(headTf.m_Pos.x, headTf.m_Pos.y - 74.0f, headTf.m_Pos.z);
		D3DXVECTOR3 headScreen, footScreen;
		if (!WorldToScreen(pDevice, headTf.m_Pos, &headScreen) || !WorldToScreen(pDevice, footWorld, &footScreen))continue;
		bool bVisible = IsCamVisible(headTf.m_Pos);
		D3DCOLOR espColor = D3DCOLORCOLOR(cheat::esp::Ennemy::NonVisible); 
		if (bVisible) espColor = D3DCOLORCOLOR(cheat::esp::Ennemy::Visible);

		float height = footScreen.y - headScreen.y;
		float width = height / 2.0f;
		float x = headScreen.x - (width / 2.0f);
		float y = headScreen.y;
		if (cheat::esp::Ennemy::Box)DrawESPBox(x, y, width, height, espColor, pDevice);
		if (!pLocal->baseclass_0.bDead && cheat::esp::Ennemy::Lines)
		{
			float screenX = (float)GetSystemMetrics(SM_CXSCREEN) / 2.0f;
			float screenY = (float)GetSystemMetrics(SM_CYSCREEN);
			DrawLine(screenX, screenY, footScreen.x, footScreen.y + 3.0f, 1, espColor, pDevice);
		}
	}
}
void ESP_Functions(LPDIRECT3DDEVICE9 pDevice)
{
	//if (pInterfaceMgr->InGame())
	//{
		DrawNPCESP(pDevice);
		DrawEnemyESP(pDevice);
		DrawAlliesESP(pDevice);
	//}
}