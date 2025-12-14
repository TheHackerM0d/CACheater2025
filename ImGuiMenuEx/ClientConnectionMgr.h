





struct CNetworkMessageMap;
struct CConnection;

struct /*VFT*/ CConnection_vtbl
{
	void(__thiscall* qsdsq)(CConnection* pthis);
};

struct /*VFT*/ CNetworkMessageMap_vtbl
{
	bool(__thiscall* ProcessNetworkMessage)(CNetworkMessageMap* pthis, unsigned int);
};

struct CNetworkMessageMap
{
	CNetworkMessageMap_vtbl* __vftable /*VFT*/;
};

struct CConnection
{
	CConnection_vtbl* __vftable /*VFT*/;
	HWND__* m_hWnd;
	int m_bUseRetryConnection;
	int m_bUseRedirectServerAddressByINIFile;
	int m_bConnected;
	sockaddr_in m_saServerOriginal;
	sockaddr_in m_saServerToConnect;
	unsigned int m_hSocket;
	char* m_pMsgBuf;
	_RTL_CRITICAL_SECTION m_cs;
	void* m_pkPacketUserData;
	void(__cdecl* m_fnPacketCallback)(unsigned int, char*, int, void*);
	bool m_bServerStressTest;
};

struct CAsyncConnection : CConnection, CNetworkMessageMap
{
	void* m_hThread;
	unsigned int m_dwThreadId;
	void* m_hEvent;
	void* m_hKillEvent;
	_RTL_CRITICAL_SECTION m_csRead;
	int m_bRun;
	_RTL_CRITICAL_SECTION m_Msgcs;
};

class CAuthServer : public CAsyncConnection {};


class ClientConnectionMgr;
struct /*VFT*/ ClientConnectionMgr_vtbl
{
	void(__thiscall* ClientConnectionMgr1)(ClientConnectionMgr* pthis);
	void(__thiscall* Update)(ClientConnectionMgr* pthis);
	bool(__thiscall* InitMultiPlayer)(ClientConnectionMgr* pthis);
	bool(__thiscall* InitSinglePlayer)(ClientConnectionMgr* pthis);
	bool(__thiscall* SetupClient)(ClientConnectionMgr* pthis, const char*, const char*, const char*);
	bool(__thiscall* SetupServerSinglePlayer)(ClientConnectionMgr* pthis);
	void(__thiscall* SetNetGameMapCycle)(ClientConnectionMgr* pthis, int);
	void(__thiscall* OnEvent)(ClientConnectionMgr* pthis, unsigned int, unsigned int);
	bool(__thiscall* OnMessage)(ClientConnectionMgr* pthis, char, ILTMessage_Read*);
	bool(__thiscall* SetService)(ClientConnectionMgr* pthis);
	bool(__thiscall* StartClientServer)(ClientConnectionMgr* pthis);
	void(__thiscall* SetDisconnectCode)(ClientConnectionMgr* pthis, unsigned int, const char*);
	bool(__thiscall* HandleMsgHandshake)(ClientConnectionMgr* pthis, ILTMessage_Read*);
	bool(__thiscall* HandleMsgMultiplayerData)(ClientConnectionMgr* pthis, ILTMessage_Read*);
	bool(__thiscall* HandleMsgPlayerMultiplayerInit)(ClientConnectionMgr* pthis, ILTMessage_Read*);
	bool(__thiscall* HandleMsgPlayerSingleplayerInit)(ClientConnectionMgr* pthis, ILTMessage_Read*);
	bool(__thiscall* StartServerAsSinglePlayer)(ClientConnectionMgr* pthis);
	bool(__thiscall* StartClient)(ClientConnectionMgr* pthis);
};


class ClientConnectionMgr
{
public:
	ClientConnectionMgr_vtbl* __vtbl; //0x0000
	char pad_0000[5224]; //0x0000
	__int32 m_bForceDisconnect; //0x146C
}; ClientConnectionMgr* oClientConnectionMgr;