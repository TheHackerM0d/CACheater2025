struct CGameSettings { };



class CInterfaceResMgr
{
public:
	char pad_0000[5736]; //0x0000
	float m_fXRatio; //0x1670
	float m_fYRatio; //0x1674
	uint32_t m_dwScreenWidth; //0x1670
	uint32_t m_dwScreenHeight; //0x1674
}; //Size: 0x2040

class CWeaponChooser
{
public:
	char pad_0000[4]; //0x0000
	uint16_t m_nWeaponIndex; //0x0004 char m_nWeaponIndex[2]
	uint16_t m_nWeapon; //0x0006
	uint32_t m_bIsOpen; //0x0008
	CTimer m_NextWeaponKeyDownTimer; //0x000C
	CTimer m_PrevWeaponKeyDownTimer; //0x001C
	CTimer m_AutoSwitchTimer; //0x002C
	CTimer m_AutoCloseTimer; //0x003C
}; //Size: 0x004C

class CAmmoChooser
{
public:
	char pad_0000[4]; //0x0000
	uint16_t m_nAmmo; //0x0004
	uint16_t m_bIsOpen; //0x0006
	CTimer m_NextAmmoKeyDownTimer; //0x0008
	CTimer m_AutoSwitchTimer; //0x0018
	CTimer m_AutoCloseTimer; //0x0028
}; //Size: 0x0038

class CInterfaceMgr;
struct /*VFT*/ CInterfaceMgr_vtbl
{
	void(__thiscall* RequestInterfaceSound)(void/*IUISoundInterfaceMgr*/* pthis, int);
	void(__thiscall * thinfs)(CInterfaceMgr* pthis);
	unsigned int(__thiscall* Init)(CInterfaceMgr* pthis);
	void(__thiscall* Term)(CInterfaceMgr* pthis);
	void(__thiscall* OnEnterWorld)(CInterfaceMgr* pthis, unsigned int);
	void(__thiscall* OnExitWorld)(CInterfaceMgr* pthis);
	bool(__thiscall* StartGame)(CInterfaceMgr* pthis, int, int, const wchar_t*, unsigned int, const char*, const char*, GamePlayType);
	unsigned int(__thiscall* OnCommandOn)(CInterfaceMgr* pthis, int);
	unsigned int(__thiscall* OnCommandOff)(CInterfaceMgr* pthis, int);
	unsigned int(__thiscall* HandleKeyDown)(CInterfaceMgr* pthis, int, int);
	unsigned int(__thiscall* HandleKeyUp)(CInterfaceMgr* pthis, int);
	unsigned int(__thiscall* OnMessage)(CInterfaceMgr* pthis, char, ILTMessage_Read*);
	unsigned int(__thiscall* OnEvent)(CInterfaceMgr* pthis, unsigned int, unsigned int);
	void(__thiscall* OnObjectRemove)(CInterfaceMgr* pthis, LTObject*);
	void(__thiscall* OnLButtonUp)(CInterfaceMgr* pthis, int, int);
	void(__thiscall* OnLButtonDown)(CInterfaceMgr* pthis, int, int);
	void(__thiscall* OnLButtonDblClick)(CInterfaceMgr* pthis, int, int);
	void(__thiscall* OnRButtonUp)(CInterfaceMgr* pthis, int, int);
	void(__thiscall* OnRButtonDown)(CInterfaceMgr* pthis, int, int);
	void(__thiscall* OnRButtonDblClick)(CInterfaceMgr* pthis, int, int);
	void(__thiscall* OnMouseMove)(CInterfaceMgr* pthis, int, int);
	void(__thiscall* HandleChar)(CInterfaceMgr* pthis, unsigned int);
	void(__thiscall* OnMouseWheel)(CInterfaceMgr* pthis, int, int, int);
	void(__thiscall* OnMouseMoveWhileLButtonDown)(CInterfaceMgr* pthis, int, int);
	void(__thiscall* OnMouseMoveWhileRButtonDown)(CInterfaceMgr* pthis, int, int);
	bool(__thiscall* OnImeProc)(CInterfaceMgr* pthis, unsigned int, unsigned int, int);
	CGameSettings* (__thiscall* GetSettings)(CInterfaceMgr* pthis);
	class CHUDMgr* (__thiscall* GetHUDMgr)(CInterfaceMgr* pthis);
	class CScreenMgr* (__thiscall* GetScreenMgr)(CInterfaceMgr* pthis);
	class CXMLPopupMgr* (__thiscall* GetPopupMgr)(CInterfaceMgr* pthis);
	CWeaponChooser* (__thiscall* GetWeaponChooser)(CInterfaceMgr* pthis);
	CAmmoChooser* (__thiscall* GetAmmoChooser)(CInterfaceMgr* pthis);
	unsigned int(__thiscall* AllowCameraMovement)(CInterfaceMgr* pthis);
	bool(__thiscall* GetObjectPlay)(CInterfaceMgr* pthis);
	void(__thiscall* UpdatePlayingState)(CInterfaceMgr* pthis);
	void(__thiscall* UpdateScreenFlashBang)(CInterfaceMgr* pthis);
	void(__thiscall* UpdateMotionBlur)(CInterfaceMgr* pthis);
	bool(__thiscall* PrevWeapon)(CInterfaceMgr* pthis);
	bool(__thiscall* NextWeapon)(CInterfaceMgr* pthis, int);
	bool(__thiscall* IsInWorld)(CInterfaceMgr* pthis);
	void(__thiscall* SetCurrentGame)(CInterfaceMgr* pthis, int);
	int(__thiscall* GetCurrentGame)(CInterfaceMgr* pthis);
	void(__thiscall* GetRoundResult)(CInterfaceMgr* pthis, int*, int*, int*);
	bool(__thiscall* OnSysKeyDown)(CInterfaceMgr* pthis);
	void(__thiscall* SetKickPlayerFlag)(CInterfaceMgr* pthis, bool);
	bool(__thiscall* GetAbuseGameFlag)(CInterfaceMgr* pthis);
	void(__thiscall* SetInterfaceWeaponIndex)(CInterfaceMgr* pthis, int, int, int);
	void(__thiscall* SetChangeWeaponIndex)(CInterfaceMgr* pthis, int);
	int* (__thiscall* GetClassWeaponIndex)(CInterfaceMgr* pthis, int);
	bool(__thiscall* SetChangeSubWeapon)(CInterfaceMgr* pthis, int, int, int);
};
struct CScreenSpriteMgr
{
	unsigned int m_bInitialized;
	std::vector<ScreenSpriteFrame*, std::allocator<ScreenSpriteFrame*> > m_FrameArray;
	std::vector<CScreenSprite*, std::allocator<CScreenSprite*> > m_SpriteArray;
	float m_fLastTime;
};

class CInterfaceMgr
{
public:
	CInterfaceMgr_vtbl* __vtbl; //0x0000
public:
	char pad_0000[120]; //0x0004
public:
	uint32_t m_bUseInterfaceCamera; //0x007C
	CWeaponChooser m_WeaponChooser; //0x0080
	CAmmoChooser m_AmmoChooser; //0x00CC
	GameState m_eGameState; //0x0104
	GamePlayType m_eLastGamePlayType; //0x0108
public:
	class CUseCashItemPopupMgr* m_UseCashItemMgr; //0x010C
private:
	char pad_010C[6828]; //0x010C
public:
	CInterfaceResMgr* m_InterfaceResMgr; //0x1BBC
private:
	char pad_1BC0[6540]; //0x1BC0
public:
	CScreenSpriteMgr* m_ScreenSpriteMgr; //0x354C CScreenSpriteMgr
private:
	char pad_3550[92]; //0x3550
public:
	CGameSettings* m_Settings; //0x35AC CGameSettings
private:
	char pad_35B0[60]; //0x35B0
public:
	__int32 m_eLastGameState; //0x35EC
private:
	char pad_35F0[400]; //0x35F0
public:
	bool m_bEnteredScreenState; //0x3780
	bool m_bIntentionalDisconnect; //0x3781
	bool m_bNormalDisconnect; //0x3782
	bool m_bWideDisplay; //0x3783
	bool m_bShutDownForceDisconnect; //0x3784
	bool m_bHasFocus; //0x3785
	bool m_bDialogBoxMode; //0x3786
	bool m_bVisibleWebBrowser; //0x3787
	__int32 m_bQuitAfterDemoScreens; //0x3788
	__int32 m_bSeenDemoScreens; //0x378C


	__forceinline bool InGame()		{ return m_eGameState == GameState::GS_PLAYING; }
	__forceinline bool IsLoading()  { return m_eGameState == GameState::GS_LOADINGLEVEL; }
	__forceinline bool InLobby()	{ return m_eGameState == GameState::GS_SCREEN; }
};	CInterfaceMgr* pInterfaceMgr;