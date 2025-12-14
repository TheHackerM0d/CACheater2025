


class CGameClientShell_vtbl
{
public:
	virtual const char* __thiscall CCBAGameClientShell_InterfaceImplementation();
	virtual void __thiscall CGameClientShellPreUpdate(const ClientFixedFrameUpdateInfo* fixedFrameUpdateInfo);
	virtual void __thiscall CGameClientShellPostUpdate(const ClientFixedFrameUpdateInfo* fixedFrameUpdateInfo);
	virtual void __thiscall CCBAGameClientShellUpdate(const ClientFixedFrameUpdateInfo* fixedFrameUpdateInfo);
	virtual unsigned int __thiscall CGameClientShellOnObjectRotate(LTObject* hObj, bool bTeleport, const LTRotation* pNewRot);
	virtual unsigned int __thiscall CCBAGameClientShellOnEngineInitialized(RMode* pMode, LTGUID* pAppGuid);
	virtual void __thiscall CCBAGameClientShellOnEngineTerm();
	virtual void __thiscall CGameClientShellOnEvent(unsigned int dwEventID, unsigned int dwParam);
	virtual unsigned int __thiscall CGameClientShellOnTouchNotify(LTObject* hMain, const CollisionInfo* pInfo, float forceMag);
	virtual void __thiscall CGameClientShellOnPlaySound(PlaySoundInfo* pPSI);
	virtual void __thiscall CGameClientShellOnLockRenderer();
	virtual void __thiscall CGameClientShellOnUnLockRenderer();
	virtual void __thiscall IClientShellStubOnConsolePrint(IClientShellStub* pthis, CConsolePrintData* pData);
	virtual void __thiscall CGameClientShellOnKeyUp(int key);
	virtual void __thiscall CGameClientShellOnKeyDown(int key, int rep);
	virtual void __thiscall CGameClientShellOnCommandOff(int command);
	virtual void __thiscall CGameClientShellOnCommandOn(int command);
	virtual void __thiscall CGameClientShellOnModelKey(LTObject* hObj, ArgList* pArgs);
	virtual void __thiscall CCBAGameClientShellOnEnterWorld();
	virtual void __thiscall CCBAGameClientShellOnExitWorld();
	virtual void __thiscall CCBAGameClientShellOnMessage(ILTMessage_Read* pMsg);
	virtual void __thiscall CGameClientShellPreLoadWorld(const char* pWorldName);
	virtual unsigned int __thiscall CGameClientShellOnObjectMove(LTObject* hObj, bool bTeleport, const TVector3<float>* pPos);
	virtual void __thiscall CGameClientShellSpecialEffectNotify(LTObject* hObj, ILTMessage_Read* pMsg);
	virtual void __thiscall CGameClientShellOnObjectRemove(LTObject* hObj);
	virtual void __thiscall CGameClientShellSetServerVar(const char* pszAuthIP, const char* pszAuthPort, const char* pszPcRoom, const char* userId, const char* password, const char* pszPassport, const char* pszVer, const char* pszServerCode, const char* pszCountryCodeFromCmdLine);
	virtual void __thiscall IClientShellSetWSInstance(IClientShell* pthis, CWSInterface* pkInstance);
	virtual CWSInterface* __thiscall IClientShellGetWSInstance(IClientShell* pthis);
	virtual cPlayerMgr* __thiscall CCBAGameClientShellGetPlayerMgr1();
	virtual cSFXMgr* __thiscall CCBAGameClientShellGetSFXMgr1();
	virtual void __thiscall CCBAGameClientShellSetXignCodeInstance(IXignCodeInstance* instance);
	virtual IXignCodeInstance* __thiscall CCBAGameClientShellGetXignCodeInstance();
	virtual void __thiscall CCBAGameClientShellClearTCPConnections();
	virtual void __thiscall CCBAGameClientShellClearUDPConnections();
	virtual void unknow();
	virtual void __thiscall CGameClientShellPreEngineInitialized();
	virtual char __thiscall CGameClientShellPostInitializeResources();
	virtual bool __thiscall CGameClientShellIsRendererInitted();
	virtual void __thiscall CGameClientShellOnObjectFileNames(LTObject* hObj);
	virtual void __thiscall CCBAGameClientShellOnBlockConsoleCmd(int nBlockCmdIndex);
	virtual void __thiscall IClientShellOnVertexShaderSetConstants(IClientShell* pthis, LTVertexShader* pVertexShader, unsigned int iPass, CRenderStyle* pRenderStyle, LTObject* hObj, const LTShaderDeviceState* ShaderDeviceState);
	virtual void __thiscall IClientShellOnPixelShaderSetConstants(IClientShell* pthis, LTPixelShader* pPixelShader, unsigned int iPass, CRenderStyle* pRenderStyle, LTObject* hObj, const LTShaderDeviceState* ShaderDeviceState);
	virtual void __thiscall CGameClientShellOnEffectShaderSetParams(LTEffectShader* pEffect, CRenderStyle* pRenderStyle, LTObject* hObj, unsigned int nPass, const LTShaderDeviceState* ShaderDeviceState);
	virtual unsigned int __thiscall IClientShellStubOnTouchNotify(IClientShellStub* pthis, LTObject* hMain, CollisionInfo* pInfo, float forceMag);
	virtual void __thiscall IClientShellStubSRand(IClientShellStub* pthis);
	virtual DWORD* __thiscall CCBAGameClientShellGetAuthServer();
	virtual DWORD* __thiscall CCBAGameClientShellGetLobbyServer();
	virtual void __thiscall CGameClientShellPauseGame(bool bPause, bool bPauseSound);
	virtual int __thiscall CCBAGameClientShellOnWin32Message(HWND__* hWnd, unsigned int uMsg, unsigned int wParam, int lParam);
	virtual DWORD* __thiscall CCBAGameClientShellGetClientInfoMgr();
	virtual DWORD* __thiscall CCBAGameClientShellGetBotInfoMgr();
	virtual CInterfaceMgr* __thiscall CCBAGameClientShellGetInterfaceMgr();
	virtual cPlayerMgr* __thiscall CCBAGameClientShellGetPlayerMgr();
	virtual const CClientWeaponAllocator* __thiscall CCBAGameClientShellGetClientWeaponAllocator();
	virtual void __thiscall CGameClientShellPostLevelLoadFirstUpdate(const ClientFixedFrameUpdateInfo* fixedFrameUpdateInfo);
	virtual int __thiscall CGameClientShellGetLastKeyInputTime();
	virtual void __thiscall CGameClientShellRefreshLastKeyInputTime();
	virtual void __thiscall CCBAGameClientShellSetupClientConnectionMgr();
	virtual bool __thiscall CCBAGameClientShellSetupMissionStuff();
	virtual cSFXMgr* __thiscall CCBAGameClientShellGetSFXMgr();
	virtual void __thiscall CCBAGameClientShellEnterChannelReq();
	virtual void __thiscall CCBAGameClientShellUpdatePerformanceStatistics();
	virtual void __thiscall CCBAGameClientShellEnterChannelReq(const wchar_t* szName, int channel);
};


class cGameClientShell : public CGameClientShell_vtbl
{
public:
	char pad_0004[264]; //0x0000
	__int32 m_nPlayerState; //0x010C
	bool m_bShowNightVision; //0x0110
	bool m_bShowNightBlur; //0x0111
	char pad_0112[36006]; //0x0112
	bool m_bFlashScreen; //0x8DB8
	char pad_8DB9[3]; //0x8DB9
	float m_fFlashTime; //0x8DBC
	float m_fFlashStart; //0x8DC0
	float m_fFlashRampUp; //0x8DC4
	float m_fFlashRampDown; //0x8DC8
	D3DXVECTOR3 m_vFlashColor; //0x8DCC
	char pad_8DD8[4]; //0x8DD8
	float m_fFrameTime; //0x8DDC
	bool m_bRestoringGame; //0x8DE0
	bool m_bMainWindowMinimized; //0x8DE1
	bool m_bTweakingWeapon; //0x8DE2
	bool m_bTweakingWeaponMuzzle; //0x8DE3
	bool m_bTweakingWeaponBreachOffset; //0x8DE4
	bool m_bGamePaused; //0x8DE5
	bool m_bServerPaused; //0x8DE6
	char pad_8DE7[1]; //0x8DE7
	SwitchingWorldsState m_eSwitchingWorldsState; //0x8DE8 enum SwitchingWorldsState
	bool m_bMainWindowFocus; //0x8DEC
	bool m_bRendererInit; //0x8DED
	char pad_8DEE[94]; //0x8DEE
	bool m_bFirstUpdate; //0x8E4C
	char pad_8E4D[71]; //0x8E4D
	bool m_bShowPlayerPos; //0x8E94
	bool m_bShowCamPosRot; //0x8E95
	bool m_bAdjustLightScale; //0x8E96
	bool m_bAdjustLightAdd; //0x8E97
	bool m_bAdjustFOV; //0x8E98
	bool m_bAdjust1stPersonCamera; //0x8E99
	char pad_8E9A[1026]; //0x8E9A
	bool m_bSelectLobbyServer; //0x929C
	char pad_929D[3]; //0x929D
	__int32 m_nLastKeyInputTime; //0x92A0
	__int32 m_nPlayLastKeyInputTime; //0x92A4
	bool m_bRenderShader; //0x92A8
	char pad_92A9[3]; //0x92A9
	GameType m_eGameType; //0x92AC enum GameType
	char pad_92B0[24]; //0x92B0
	bool m_bInWorld; //0x92C8
	bool m_bInputState; //0x92C9
	char pad_92CA[56154]; //0x92CA
	float fCurrentFPS; //0x16E24
}; cGameClientShell* pGameClientShell;

/*
=== Class Dump: CGameClientShell (size: 0x10000) ===
+0x000 | int: 931472980 (0x37852654) | float: 0.0000  //CGameClientShell::`vtable'
+0x11C | int: 933603676 (0x37A5A95C) | float: 0.0000  //CGlobalClientMgr::`vftable'
+0x174 | int: 933585656 (0x37A562F8) | float: 0.0000  //CDamageFXMgr::`vftable'
+0x17C | int: 933553108 (0x37A4E3D4) | float: 0.0000  //CButeMgrEx::`vftable'
+0x598 | int: 927915312 (0x374EDD30) | float: 0.0000  //GBM_DisplayError(const char *szMsg)
+0x1694 | int: 931564644 (0x37868C64) | float: 0.0000 //const ObjectBank<CRect,NullCS>::`vftable'
+0x16B8 | int: 931564664 (0x37868C78) | float: 0.0000 //const ObjectBank<class CPoint, class NullCS>::`vftable'
+0x16DC | int: 931564684 (0x37868C8C) | float: 0.0000 //const ObjectBank<class CAVector, class NullCS>::`vftable'
+0x1700 | int: 931564704 (0x37868CA0) | float: 0.0000 //const ObjectBank<class CARange, class NullCS>::`vftable'
+0x1724 | int: 931564724 (0x37868CB4) | float: 0.0000 //const ObjectBank<class CButeMgr::CSymTabItem, class NullCS>::`vftable'
+0x17AC | int: 931508800 (0x3785B240) | float: 0.0000 //const CGunSmithNPCMgr::`vftable'
+0x3548 | int: 931508968 (0x3785B2E8) | float: 0.0000 //const CGunSmithRecipeMgr::`vftable'
+0x4B68 | int: 931565288 (0x37868EE8) | float: 0.0000 //const CButeMgr::`vftable'
+0x6134 | int: 931508984 (0x3785B2F8) | float: 0.0000 //SSong0815!1
+0x6138 | int: 933600072 (0x37A59B48) | float: 0.0000 //const CBGMSettingMgr::`vftable'
+0x775C | int: 933600244 (0x37A59BF4) | float: 0.0000 //const CBGMUserProfileMgr::`vftable'
+0xD1A8 | int: 926163747 (0x37342323) | float: 0.0000 //CXMLScreenOption::OnSoundUICommand(CUIControl *,UI_COMMANDS::E_COMMANDS)
==============================
*/