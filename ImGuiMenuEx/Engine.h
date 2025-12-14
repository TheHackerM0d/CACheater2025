#include "Variables.h"
std::wstring GetCurrentProcessName()
{
	WCHAR fileName[MAX_PATH];
	GetModuleFileNameW(NULL, fileName, MAX_PATH);
	return std::filesystem::path(fileName).filename().wstring();
}
std::wstring processName = GetCurrentProcessName();
//==========================================================================================================================//
void Console(CONST CHAR* CMD)
{
	_asm
	{
		PUSH CMD
		MOV EAX, Logger::engine::Get_LTClientEXE
		CALL EAX
		ADD ESP, 0x4
	}
}

unsigned long ulThisCustom;
void CheckPointer()
{
	oILTCSBase = (cILTCSBase*)Logger::cshell::Get_LTCSBase;
	GetPlayerByIndex = (lpGetPlayerByIndex)(Logger::cshell::Get_PlayerByIndex);
	GetLocalPlayer = (lpGetLocalPlayer)Logger::cshell::Get_LocalPlayer;
	ulThisCustom = *(unsigned long*)(Logger::cshell::Get_ClientInfoMgr);
	pInterfaceMgr = *(CInterfaceMgr**)Logger::cshell::Get_cInterfaceMgr;

	pGameClientShell = *(cGameClientShell**)Logger::cshell::Get_GameClientShell;
	if (ValidPointer(pGameClientShell))
	{
		m_pPlayerMgr = (cPlayerMgr*)pGameClientShell->CCBAGameClientShellGetPlayerMgr();
		SFXMgr = (cSFXMgr*)pGameClientShell->CCBAGameClientShellGetSFXMgr();
	}
}
bool WINAPIV IsCamVisible(D3DXVECTOR3 Point)
{
	cILTCSBase* oILTCSBase = (cILTCSBase*)Logger::cshell::Get_LTCSBase;
	IntersectQueryCA iQuery; IntersectInfoCA iInfo; memset(&iQuery, 0, sizeof(iQuery));
	iQuery.Start = ConvertPosition(m_pPlayerMgr->m_hCamera); iQuery.End = Point;
	return !oILTCSBase->ILTBase->IntersectSegment(iQuery, iInfo);
	return 1;
}
void VectorAngles(CONST FLOAT* forward, FLOAT* angles)
{
	FLOAT tmp, yaw, pitch;
	if (forward[2] == 0 && forward[0] == 0) { yaw = 0; if (forward[2] > 0) pitch = 90; else pitch = 270; }
	else { yaw = (atan2(forward[2], -forward[0]) * 180 / M_PI) - 90; if (yaw < 0) yaw += 360; tmp = sqrt(forward[0] * forward[0] + forward[2] * forward[2]); pitch = (atan2(forward[1], tmp) * 180 / M_PI); if (pitch < 0) 	pitch += 360; }
	angles[0] = -pitch; angles[1] = yaw; angles[2] = 0;
}
void GetAngleToTarget(D3DXVECTOR3 vTargetPos, D3DXVECTOR3 vCameraPos, D3DXVECTOR3& vAngles)
{
	D3DXVECTOR3 vDelta; vDelta.x = vTargetPos.x - vCameraPos.x; vDelta.y = vTargetPos.y - vCameraPos.y; vDelta.z = vTargetPos.z - vCameraPos.z;
	VectorAngles((FLOAT*)&vDelta, (FLOAT*)&vAngles);
	if (vAngles.x > 180.0f) vAngles.x -= 360.0f;
	else if (vAngles.x < -180.0f) vAngles.x += 360.0f;

	if (vAngles.y > 180.0f) vAngles.y -= 360.0f;
	else if (vAngles.y < -180.0f) vAngles.y += 360.0f;
}
FLOAT AngleNormalize(FLOAT Angle) { while (Angle < -180) Angle += 360; while (Angle > 180) Angle -= 360; return Angle; }
bool GetAimbotFOV(FLOAT Angle, D3DXVECTOR3 Camera, D3DXVECTOR3 Target)
{
	Angle /= 2; D3DXVECTOR3 newAngles(NULL, NULL, NULL); D3DXVECTOR3 curAngles(NULL, NULL, NULL); GetAngleToTarget(Target, Camera, newAngles);
	newAngles[1] = AngleNormalize(newAngles[1]); newAngles[0] = AngleNormalize(newAngles[0]);
	curAngles[1] = AngleNormalize(D3DXToDegree(m_pPlayerMgr->m_fYaw)); curAngles[0] = AngleNormalize(D3DXToDegree(m_pPlayerMgr->m_fPitch));
	if (newAngles[1] >= (curAngles[1] - Angle) && newAngles[1] <= (curAngles[1] + Angle) && newAngles[0] >= (curAngles[0] - Angle) && newAngles[0] <= (curAngles[0] + Angle)) return TRUE;
	return FALSE;
}
bool LimitRotation(float& CurrentRotationYaw, float& CurrentRotationPitch, float* DesideredRotationYaw, float* DesideredRotationPitch, float rotationLimit)
{
	float RotationDifferenceYaw = AngleNormalize((*DesideredRotationYaw - CurrentRotationYaw)); float RotationDifferencePitch = AngleNormalize((*DesideredRotationPitch - CurrentRotationPitch));
	if (RotationDifferenceYaw < -rotationLimit)RotationDifferenceYaw = -rotationLimit; else if (RotationDifferenceYaw > rotationLimit)RotationDifferenceYaw = rotationLimit;
	if (RotationDifferencePitch < -rotationLimit)RotationDifferencePitch = -rotationLimit; else if (RotationDifferencePitch > rotationLimit)RotationDifferencePitch = rotationLimit;
	*DesideredRotationYaw = CurrentRotationYaw + RotationDifferenceYaw; *DesideredRotationPitch = CurrentRotationPitch + RotationDifferencePitch;
	return true;
}