//class cCharInfo
//{
//public:
//	DWORD m_bGMAccount; //0x0000
//	char pad_0004[4]; //0x0004
//	DWORD m_nUID; //0x0008
//	char pad_000C[316]; //0x000C
//	DWORD m_nMoney; //0x0148
//	char pad_014C[20]; //0x014C
//	DWORD m_dwPrepaidPoint; //0x0160
//	char pad_0164[40]; //0x0164
//	uint32_t m_nExperience; //0x018C
//	char pad_0190[20]; //0x0190
//	uint32_t m_bJoinClan; //0x01A4
//	char pad_01A8[4]; //0x01A8
//	uint32_t m_dwClanUID; //0x01AC
//	char pad_01B0[28]; //0x01B0
//	std::wstring m_sClanName; //0x01CC
//	char pad_01F0dqs[24]; //0x01CC
//	uint32_t m_nClanMarkEmblemID; //0x01E8
//	DWORD m_nClanMarkBackID; //0x01EC
//	char pad_01F0[112]; //0x01F0
//	cModelButeReader* m_pCharModelInfoMgr; //0x0260
//	char pad_0264[592]; //0x0264
//	DWORD m_bIsChannelInvited; //0x04B4
//	char pad_04B8[44]; //0x04B8
//	bool m_bEnableObserverMode; //0x04E4
//	bool m_bRefereeAccount; //0x04E5
//	bool m_bGameHelper; //0x04E6
//	char pad_04E7[5]; //0x04E7
//	DWORD m_dwUsedNXRank; //0x04EC
//	__int32 ColorName; //0x04F0
//	__int32 ColorClan; //0x04F4
//	char pad_04F8[204]; //0x04F8
//	__int32 Background; //0x05C4
//	__int32 BackgroundSlide; //0x05C8
//};

class cCharInfo
{
public:
	__int32 m_bGMAccount; //0x0000
	char pad_0004[108]; //0x0004
	wchar_t* m_sPwd; //0x0070
	char pad_0074[104]; //0x0074
	wchar_t* szName; //0x00DC
	char pad_00E0[104]; //0x00E0
	__int32 m_nMoney; //0x0148
	char pad_014C[64]; //0x014C
	__int32 m_nExperience; //0x018C
	char pad_0190[20]; //0x0190
	__int32 m_bJoinClan; //0x01A4
	char pad_01A8[36]; //0x01A8
	wchar_t* m_sClanName; //0x01CC
	char pad_01D0[24]; //0x01D0
	__int32 m_nClanMarkEmblemID; //0x01E8
	int32_t m_nClanMarkBackID; //0x01EC
	char pad_01F0[740]; //0x01F0
	int32_t bKicked; //0x04D4
	char pad_04D8[4]; //0x04D8
	int32_t m_bCanVoteReq; //0x04DC
	int32_t m_nLastVoteTime; //0x04E0
	char pad_04E4[12]; //0x04E4
	int32_t m_NameColor; //0x04F0
	uint32_t m_ClanNameColor; //0x04F4
	uint32_t m_CrosshairColor; //0x04F8
	char pad_04FC[200]; //0x04FC
	__int32 m_nNameBG; //0x05C4
	__int32 m_nNameBGLine; //0x05C8
};