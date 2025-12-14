// Created with ReClass.NET 1.2 by KN4CK3R

class CVolumeBrushFX
{
public:
	char pad_0000[56]; //0x0000
	int32_t m_bFogEnable; //0x0038
	float m_fFogFarZ; //0x003C
	float m_fFogNearZ; //0x0040
	D3DXVECTOR3 m_vFogColor; //0x0044
	D3DXVECTOR3 m_vTintColor; //0x0050
	D3DXVECTOR3 m_vLightAdd; //0x005C
	char m_nSoundFilterId[4]; //0x0068
	int32_t m_bCanPlayMoveSnds; //0x006C
	int32_t m_eSurfaceOverrideType; //0x0070
	D3DXVECTOR3 m_vCurrent; //0x0074
	float m_fGravity; //0x0080
	float m_fViscosity; //0x0084
	float m_fPlayerSpeedFactor; //0x0088
	float m_fFriction; //0x008C
	int32_t m_ePPhysicsModel; //0x0090
	int32_t m_eContainerCode; //0x0094
}; //Size: 0x0098

class CWeatherFX
{
public:
	CVolumeBrushFX baseclass_0; //0x0000
	__int32 m_bFirstUpdate; //0x0098
	uint32_t m_dwFlags; //0x009C
	float m_fFloorY; //0x00A0
	float m_fViewDist; //0x00A4
	double m_fArea; //0x00A8
	__int32 m_eSurfaceType; //0x00B0
	D3DXVECTOR3 m_vRainVel; //0x00B4
	D3DXVECTOR3 m_vSnowVel; //0x00C0
	D3DXVECTOR3 m_vRainPos; //0x00CC
	D3DXVECTOR3 m_vPos; //0x00D8
	D3DXVECTOR3 m_vDims; //0x00E4
}; //Size: 0x00F0