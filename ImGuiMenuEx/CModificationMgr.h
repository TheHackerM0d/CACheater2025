class WEAPON_MOD
{
public:
	unsigned int bInited;
	int nId;
	const char* szName;
	int nNumModIds;
	int* aModIds;
	int* aModModel;
	int m_nEnableTuningInfo[5];
}; //Size: 0x0004
class GEAR_MOD
{
public:
	unsigned int bInited;
	int nId;
	const char* szName;
	int nEnableTuningInfo[3];
}; //Size: 0x0044
class MOD_ITEM
{
public:
	unsigned int bInited;
	int nId;
	unsigned int eType;
	char* szSocket;
	const char* szName;
}; //Size: 0x0044
struct MOD_ICON
{
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > strBase;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > strEquip;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > strDisable;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > strOtherEquip;
	std::basic_string<char, std::char_traits<char>, std::allocator<char> > strNotUse;
	unsigned int bInited;
};

class CModificationMgr
{
public:
	char pad_0000[5600]; //0x0000
	WEAPON_MOD** m_pWeaponModList; //0x15E0
	__int32 m_nNumWeaponMods; //0x15E4
	GEAR_MOD** m_pHeadModList; //0x15E8
	__int32 m_nNumHeadMods; //0x15EC
	GEAR_MOD** m_pFaceModList; //0x15F0
	__int32 m_nNumFaceMods; //0x15F4
	GEAR_MOD** m_pVestModList; //0x15F8
	__int32 m_nNumVestMods; //0x15FC
	MOD_ITEM** m_pModItemList; //0x1600
	__int32 m_nNumModItems; //0x1604
	uint32 m_nFileCRC;
	MOD_ICON m_ModIcon[8];
}; //Size: 0x1608
