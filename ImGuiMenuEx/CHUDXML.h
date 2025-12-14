class CHUDXMLVote
{
public:
	char pad_0000[60]; //0x0000
	__int32 m_eStep; //0x003C
	char pad_0040[16]; //0x0040
	__int32 m_nVoteType; //0x0050
	__int32 m_nVoteTargetID; //0x0054
	__int32 m_nVoteReason; //0x0058
	char pad_005C[56]; //0x005C
	__int32 m_nKickerLevel; //0x0094
	__int32 m_nTargetLevel; //0x0098
	float m_fKickerMMR; //0x009C
	float m_fTargetMMR; //0x00A0
	char pad_00A4[16]; //0x00A4
	__int32 m_bVote; //0x00B4
	__int32 m_bMyVote; //0x00B8
};
class CHUDXMLVoteReq
{
public:
	char pad_0000[60]; //0x0000
	eVoteStep** m_eStep; //0x003C
	char pad_0040[64]; //0x0040
	__int32 m_nSelectUser; //0x0080
	__int32 m_nSelectReason; //0x0084
	__int32 m_bEliteModerator; //0x0088
	__int32 m_nSameTeamNum; //0x008C
	__int32 m_nTotalUser; //0x0090
	__int32 m_nKickBlockReason; //0x0094
	__int32 m_nKickBlockFinishTime; //0x0098
	__int32 m_nSelectUserLevel; //0x009C
};



struct CHUDXMLObserver__UserInfo
{
	cCLIENT_INFO* _pInfo;
	__int32 _pCtrl; //CUIControl*
};

class CHUDXMLObserver
{
public:
	char pad_0000[16]; //0x0000
	int32_t m_pkHUDRoot; //0x0010
	char pad_0014[40]; //0x0014
	__int32 m_pAlphaList; //CUIListControl* //0x003C
	__int32 m_pBravoList; //CUIListControl* //0x0040
	__int32 m_pViewTarget; //CUIControl*
	CHUDXMLObserver__UserInfo m_UserList[16];
	__int32 m_nTargetUserID;
	bool  m_bNoTeam;
};


class CHUDXMLQurarantine
{
private:
	char pad_0000[136]; //0x0000
public:
	int32_t m_nHumanWin; //0x0088
	int32_t m_nZombiWin; //0x008C
	int32_t m_nHumanAlive; //0x0090
	int32_t m_nZombiAlive; //0x0094
	int32_t m_nCountDown; //0x0098
	int32_t m_bStartEndBGM; //0x009C
	THMCTimerEx m_RoundTime; //0x00A0
	THMCTimerEx m_BombTime; //0x00C0 CTimerEx
	class CUIControl* m_pkInfectedMercWnd;
	int m_nSelectedInfMerc;
	ItemInfoStr* m_pkChoosableInfectedMerc[3];
	bool m_bInitInfMercList;
}; //Size: 0x045C
class CHUDXMLFireteam
{
public:
	char pad_0000[136]; //0x0000
	int32_t m_nMaxRound; //0x0088
}; //Size: 0x0840
class CHUDXMLElimination
{
private:
	char pad_0000[136]; //0x0000
public:
	int32_t m_nAlphaKill; //0x0088
	int32_t m_nBravoKill; //0x008C
}; //Size: 0x0140
class CHUDXMLHealth
{
public:
	char pad_0000[508]; //0x0000
	int32_t m_nColor; //0x01FC
	int32_t m_nMaxRedColor; //0x0200
	int32_t m_nMinRedColor; //0x0204
	int32_t m_nTitleDefaultColor; //0x0208
	int32_t m_nDataDefaultColor; //0x020C
	int32_t m_nHealth; //0x0210
	int32_t m_nArmor; //0x0214
}; //Size: 0x0284
