#pragma once
#include <map>
#include <set>





template<typename T>
struct bitflag_t
{
	/// <summary>
	/// Creates a default bitflag object
	/// </summary>
	bitflag_t() = default;

	/// <summary>
	/// Creates a bitflag object with the given flags
	/// </summary>
	bitflag_t(T flags) : m_flags(flags) {}

	/// <summary>
	/// Destroys the bitflag object
	/// </summary>
	~bitflag_t() = default;

	/// <summary>
	/// Stored flags
	/// </summary>
	T m_flags{};

	/// <summary>
	/// Checks whether the given flag is present in the stored flags
	/// </summary>
	/// <param name="flag">Flag that will be checked</param>
	/// <returns>Returns true if the flag is present in the stored flags</returns>
	inline bool has_flag(T flag)
	{
		return m_flags & flag;
	}

	/// <summary>
	/// Adds the given flag to the stored flags
	/// </summary>
	/// <param name="flag">Flag that will be added</param>
	inline void add_flag(T flag)
	{
		m_flags |= flag;
	}

	/// <summary>
	/// Removes the given flag to the stored flags
	/// </summary>
	/// <param name="flag">Flag that will be removed</param>
	inline void remove_flag(T flag)
	{
		m_flags &= ~flag;
	}

	/// <summary>
	/// Checks if there are no flags stored
	/// </summary>
	/// <returns>True if no flags stored</returns>
	inline bool is_empty()
	{
		return !m_flags;
	}

	inline T get()
	{
		return m_flags;
	}
};
enum WeaponClassType
{
	eAssultClass = 0x1,
	eSubGunClass = 0x2,
	eKnifeClass = 0x3,
	eBombClass = 0x4,
	eSpecialClass = 0x5,
	eMissionClass = 0x6,
	eEtcClass = 0x7,
	eWeaponClassMax = 0x8,
};
enum client_update_
{
	client_update_camera_offset_saver = (1 << 0),  // m_camera_offset_saver
	client_update_alt_firing = (1 << 1),  // m_weapon_alt_firing
	client_update_3rd_person = (1 << 2),  // m_player_camera != last_sent_3rd_person
	client_update_3rd_chased = (1 << 3),  // camera_mode == chase || camera_mode == static_chase
	client_update_allow_input = (1 << 4),  // m_allow_player_movement != m_last_allow_player_movement
	client_update_player_rot = (1 << 5),  // m_server_accurate_rotation
	client_update_accurate_player_rot = (1 << 6),  // !m_server_accurate_rotation
	client_update_send_comp_camera_rot = (1 << 7),  // ?
	client_update_send_camera_rot = (1 << 8),  // m_send_camera_rot_to_server && m_last_camera_rot != camera_rot
	client_update_send_dynamic_perturb = (1 << 9),  // m_player_state == alive ) && last_dynamic_perturb != dynamic_perturb
	client_update_send_camera_pos = (1 << 10), // m_send_camera_rot_to_server && m_last_camera_pos != camera_pos
	client_update_zooming = (1 << 11), // m_zoom > 0 || m_zooming
	client_update_dot_sighted = (1 << 12), // m_dot_sighted
	client_update_firing = (1 << 13), // c_client_weapon::get_firing
	client_update_control_flags_saver = (1 << 14), // m_control_flags_saver
	client_update_bomb_plant = (1 << 15), // get_bomb_plant_flag
	client_update_alt_fire = (1 << 16), // m_fire_type == fire_type_alt_fire
};
using client_update_t = bitflag_t< std::uint32_t >;
enum control_flags_
{
	control_flag_idle = 0,
	control_flag_forward = (1 << 0),
	control_flag_backward = (1 << 1),
	control_flag_jump = (1 << 2),
	control_flag_duck = (1 << 3),
	control_flag_left = (1 << 4),
	control_flag_right = (1 << 5),
	control_flag_walk = (1 << 6),
	control_flag_fire = (1 << 7),
	control_flag_move = (1 << 8), // forward || backward || jump || left || right
	control_flag_unk9 = (1 << 9),
	control_flag_alt_fire = (1 << 10),
	control_flag_run = (1 << 11),
	control_flag_unk12 = (1 << 12),
	control_flag_unk13 = (1 << 13),
	control_flag_unk14 = (1 << 14),
	control_flag_unk15 = (1 << 15),
};
using control_flags_t = bitflag_t< std::uint32_t >;
enum uc_
{
	uc_client_move = (1 << 0),
	uc_movement = (1 << 1),
	uc_standing = (1 << 3),
	uc_crouch = (1 << 4)
};
using uc_t = bitflag_t< std::uint8_t >;
enum surface_type_
{
	surface_type_unknown = 0,
	surface_type_air = 1,
	surface_type_flesh = 2,
	surface_type_armor = 3,
	surface_type_impact_adult_head = 4,
	surface_type_impact_teen_head = 5,
	surface_type_impact_adult_body = 6,
	surface_type_impact_teen_body = 7,
	surface_type_eletronics = 8,
	surface_type_chain_link_fence = 9,
	surface_type_ceramic_tile = 10,
	surface_type_cement = 11,
	surface_type_plaster_and_stucco = 12,
	surface_type_porcelain = 13,
	surface_type_impact_abnormal_body_boss = 14,
	surface_type_impact_abnormal_body = 16,
	surface_type_impact_abnormal_head = 18,
	surface_type_metal = 20,
	surface_type_tin = 21,
	surface_type_metal_door = 22,
	surface_type_trussing = 23,
	surface_type_metal_pipe_steam = 24,
	surface_type_metal_drum_lava = 25,
	surface_type_wood = 30,
	surface_type_drywall = 31,
	surface_type_plywood = 32,
	surface_type_glass = 40,
	surface_type_bullet_proof_glass = 41,
	surface_type_glass_facade = 42,
	surface_type_shooting_range_targets_hole = 50,
	surface_type_water_container = 51,
	surface_type_trashbag = 52,
	surface_type_paper = 53,
	surface_type_generic = 54,
	surface_type_desert_sand = 60,
	surface_type_ice = 69,
	surface_type_dirt = 70,
	surface_type_snow = 71,
	surface_type_mud = 72,
	surface_type_grass = 73,
	surface_type_dirt_road = 74,
	surface_type_rock = 75,
	surface_type_can_shoot_through = 76,
	surface_type_foliage = 77,
	surface_type_snowy_gravel = 78,
	surface_type_snowy_dirt = 79,
	surface_type_carpet = 80,
	surface_type_cloth_can_shoot_through = 81,
	surface_type_linoleum = 90,
	surface_type_rubber = 91,
	surface_type_wood_door = 100,
	surface_type_metal_door2 = 101,
	surface_type_stone_door = 102,
	surface_type_metal_file_cabinet = 103,
	surface_type_sky = 110,
	surface_type_impact_green_body = 150,
	surface_type_ladder = 200,
	surface_type_liquid = 201,
	surface_type_invisible = 202,
	surface_type_lava = 203,
	surface_type_water = 204,
	surface_type_force_field = 205,
	surface_type_invisible_metal = 206,
	surface_type_wood_ladder = 207,
	surface_type_sword_deflect = 210
};
using surface_type_t = bitflag_t< std::uint32_t >;
struct c_pui
{
	client_update_t m_player_info_change_flags;
	std::uint8_t    m_allow_movement;
	std::uint32_t   m_client_game_time_ms;
	std::uint32_t   m_game_time_ms;
	float           m_game_time;
	std::uint32_t   m_last_send_frame;
	std::uint8_t    m_yaw;
	std::uint8_t    m_aim_pitch;
	std::uint8_t    m_twist_yaw;
	std::uint16_t   m_camera_comp;
	LTRotation		m_camera;
	std::uint8_t    m_camera_offset_y;
	float           m_last_dynamic_perturb;
	TVector3<float> m_camera_pos;
	control_flags_t m_control_flags;
	uc_t            m_uc_flags;
	std::uint8_t    m_client_move_code;
	TVector3<float> m_pos;
	TVector3<float> m_vel;
	float           m_gravity;
	std::uint32_t   m_standing_on_surface;
	std::uint8_t    m_crouch_rate;
};
enum class send_message
{
	unguaranteed = 0,
	guaranteed = 1 << 0,
	ordered_guaranteed = 1 << 1
};
struct c_wfi
{
	// c_weapon_vector
	struct c_wv
	{
		TVector3<float>   m_direction;
		bool              m_hit_player;
		DWORD* m_victim;
		uint8_t      m_model_node;
		TVector3<float>             m_object_pos;
		float             m_impact_distance;
		std::uint32_t     m_piece_visible;

		bool              m_has_normal_x;
		bool              m_has_normal_y;
		bool              m_has_normal_z;
		TVector3<float>             m_normal;

		/*
		   maybe unused
		*/
		TVector3<float>             m_impact_point;

		std::uint32_t     m_object_generation;
		bool              m_impact_point_narrow;
		std::uint32_t     m_visible_game_time_ms;
		std::uint32_t     m_sequence_no;
		bool              m_weapon_fire_debug;
		std::uint32_t     m_view_time_ms;
		std::uint32_t     m_previous_discrete_sequence_no;
		std::uint32_t     m_discrete_sequence_no;
		std::uint32_t     m_previous_from_sequence_no;
		std::uint32_t     m_from_sequence_no;
		std::uint32_t     m_to_sequence_no;
		bool              m_hit_me;
		bool              m_object;
		float             m_throw_fire_force;
		bool              m_is_dual_left_fire;
		bool              m_write_debug;
	};

	std::int32_t				m_game_type;
	std::uint16_t        m_weapon_id;
	std::uint16_t        m_ammo_id;
	std::uint16_t        m_mod_item_id;
	TVector3<float>                m_flash_pos;
	TVector3<float>                m_fire_pos;
	LTRotation				m_camera;
	float                m_yaw;
	bool                 m_zooming;
	bool                 m_triple_shot_mode;
	bool                 m_last_fire_type;
	std::uint8_t         m_perturb;
	float                m_dynamic_perturb_factor;
	std::uint32_t        m_time_factor;
	std::uint8_t         m_vectors_per_round;
	std::vector< c_wv >  m_vectors;
};






enum uvgen_ : std::int32_t {
	uvgen_none,
	uvgen_tracer,
	uvgen_max
};
enum plws_ : std::uint32_t {
	plws_big_to_small = 1,
	plws_small_to_big,
	plws_small_to_small,
	plws_constant
};
struct sfx_create_struct_t {
	virtual ~sfx_create_struct_t() {}
	virtual void write([[ maybe_unused ]] void* message) {}
	virtual void read([[ maybe_unused ]] void* message) {}

	void* m_object;
};
struct poly_line_fx_cs_t : sfx_create_struct_t {
	poly_line_fx_cs_t() = default;

	TVector3<float>			 m_start_pos;
	TVector3<float>          m_end_pos;
	TVector3<float>          m_inner_color_start;
	TVector3<float>          m_inner_color_end;
	TVector3<float>          m_outer_color_start;
	TVector3<float>          m_outer_color_end;
	float         m_alpha_start;
	float         m_alpha_end;
	float         m_min_width;
	float         m_max_width;
	float         m_life_time;
	float         m_alpha_life_time;
	float         m_perturb;
	float         m_min_dist_mult;
	float         m_max_dist_mult;
	std::uint32_t m_use_object_rotation;
	std::uint32_t m_dont_fade_alpha_at_edge;
	std::uint8_t  m_width_style;
	std::uint8_t  m_num_segments;
	std::uint32_t m_align_flat;
	std::uint32_t m_align_up;
	std::uint32_t m_align_using_rot;
	std::uint32_t m_additive;
	std::uint32_t m_multiply;
	std::uint32_t m_no_z;
	std::uint32_t m_lines_share_normal;
	const char* m_texture;
	std::uint32_t m_tex_addr;
	std::uint32_t m_color_op;
	uvgen_        m_uvgen;
};


class cSFXListq
{
public:
	DWORD unk0;
	DWORD* List;
	DWORD unk1;
	INT Num;
};

class cSFXMgrq
{
public:
	cSFXListq SFXList[0x43];
};

struct CSFXMgr_vtblq;
class CSpecialFXq;
struct CSpecialFX_vtblq;
struct CSFXMgrq
{
	CSFXMgr_vtblq* __vftable /*VFT*/;
	cSFXListq m_dynSFXLists[64];
};
struct CSFXMgr_vtblq
{
	void(__thiscall* PreRender)(CSFXMgrq*);
	CSpecialFXq* (__thiscall* CreateSFX)(CSFXMgrq*, unsigned __int8, DWORD*, ILTMessage_Read*, LTObject*);
};
class CSpecialFXq
{
public:
	CSpecialFX_vtblq* __vftable /*VFT*/;
	float m_fNextUpdateTime;
	DWORD* m_pClientDE;
	LTObject* m_hObject;
	LTObject* m_hServerObject;
	TVector3<float> m_vLastServPos;
	TVector3<float> m_vVel;
	unsigned int m_bWantRemove;
	float m_fUpdateDelta;
	unsigned __int8 m_nMenuLayer;
};
struct CSpecialFX_vtblq
{
	void(__thiscall* Destructor)(CSpecialFXq*);
	void(__thiscall* Term)(CSpecialFXq*);
	unsigned int(__thiscall* CreateObject)(CSpecialFXq*, DWORD*);
	unsigned int(__thiscall* Init)(CSpecialFXq*, DWORD*);
	unsigned int(__thiscall* Init2)(CSpecialFXq*, LTObject*, ILTMessage_Read*);
	unsigned int(__thiscall* Update)(CSpecialFXq*);
	void(__thiscall* Render)(CSpecialFXq*, LTObject*);
	void(__thiscall* WantRemove)(CSpecialFXq*, unsigned int);
	void(__thiscall* OnObjectFileNames)(CSpecialFXq*);
	void(__thiscall* HandleTouch)(CSpecialFXq*, const CollisionInfo*);
	void(__thiscall* OnModelKey)(CSpecialFXq*, LTObject*, ArgList*);
	unsigned int(__thiscall* OnServerMessage)(CSpecialFXq*, ILTMessage_Read*);
	unsigned int(__thiscall* GetSFXID)(CSpecialFXq*);
	unsigned __int8(__thiscall* GetMenuLayer)(CSpecialFXq*);
};
class CCharModelInfoMgr_New
{
public:
	char pad_0000[336]; //0x0000
	int32_t m_eModelFigureType; //0x0150
	int32_t m_eModelId; //0x0154
	int32_t m_eHeadPieceId; //0x0158
	int32_t m_eFacePieceId; //0x015C
	int32_t m_eDefaultFaceId; //0x0160
	int32_t m_Grade; //0x0164
	char pad_0168[4]; //0x0168
	int32_t m_nSpecialMarkId; //0x016C
	int32_t m_nClanMarkId; //0x0170
	int32_t m_nTeam; //0x0174
	int32_t m_nBackPackId; //0x0178
	int32_t m_nGoggleId; //0x017C
	int32_t m_bGoggleTakeOff; //0x0180
	int32_t m_nBranchUniform; //0x0184
	int32_t m_nBranchHelmet; //0x0188
	int32_t m_nMilitaryUniform; //0x018C
	int32_t m_nFaceId; //0x0190
	int32_t m_nMercenaryID; //0x0194
	int32_t m_nCosmeticCharacter; //0x0198
	int32_t m_nCosmeticHelmet; //0x019C
	int32_t m_nCosmeticGoggle; //0x01A0
	int32_t m_nCosmeticVest; //0x01A4
	int32_t m_nCosmeticBackPack; //0x01A8
	int32_t m_nModelColor; //0x01AC
	int32_t m_nHelmetColor; //0x01B0
	int32_t m_nGoggleColor; //0x01B4
	int32_t m_nBackpackColor; //0x01B8
	int32_t m_nDashGauge; //0x01BC
	int32_t m_nDashGaugeRec; //0x01C0
	int32_t m_nDashMaxStamina; //0x01C4
	float m_fMaxVelocity; //0x01C8
	char pad_01CC[256]; //0x01CC
	int32_t m_nClanEmblemID; //0x02CC
	int32_t m_nClanBackGroundID; //0x02D0
	int32_t m_nOveridableModel; //0x02D4
}; //Size: 0x02D8

struct CNumericButeListReader
{
	unsigned int m_dwItems;
	std::vector<int, std::allocator<int> > m_vItems;
};
struct UpgradeQuestInfo
{
	int nUpgradeItemNo;
	int nUpgradeItemNeedKill;
	int nUpgradeItemCurKill;
	bool nUpgradeItemDeleteWhenDone;
	bool bRecvReward;
	std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > wstrException;
};

struct CollectQuestInfo
{
	CNumericButeListReader  lCollectItemNo;
	CNumericButeListReader  lCollectItemNum;
	CNumericButeListReader  lCollectItemDeleteWhenDone;
	bool bRecvReward;
};
struct SelectRewardInfo
{
	int nLevelMin;
	int nLevelMax;
	int nProductID;
};
struct DailyQuestInfo
{
	int nSeqNo;
	unsigned int nQuestID;
	int nQuestType;
	int nMissionType;
	int nQuestLevel;
	int nNPCID;
	int nGoalCount;
	int nProgressCount;
	int nStepNo;
	int nUserState;
	bool bRecvReward;
	std::vector<int, std::allocator<int> > DefaultReward;
	std::vector<SelectRewardInfo, std::allocator<SelectRewardInfo> > SelectReward;
	std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > wstrStep;
	std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > wstrRestrict;
	std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > wstrException;
};
class QUESTINFO
{
	unsigned int nID;
	std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > wstrName;
	std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t> > wstrDesc;
	bool bEnableReUse;
	bool bNew;
	bool bEvent;
	bool bOverlap;
	bool bShowHUD;
	eQuestType eType;
	int nGradeMin;
	int nGradeMax;
	bool bGradeLimitHide;
	CNumericButeListReader  lRewardItemNo;
	CNumericButeListReader  lRewardItemConsumeType;
	CNumericButeListReader  lRewardItemPeriod;
	CNumericButeListReader  lRewardProductID;
	CollectQuestInfo CollectInfo;
	UpgradeQuestInfo UpgradeInfo;
	DailyQuestInfo* DailyInfo;
};
struct _REWARD_SELECTION
{
	unsigned int m_MinGrade;
	unsigned int m_MaxGrade;
	unsigned int m_dwProductID;
};

struct DETAIL_DAILY_QUEST
{
	unsigned int m_dwDefaultSize;
	unsigned int m_dwDefaultProductID[5];
	unsigned int m_dwSelectionSize;
	_REWARD_SELECTION m_rSelection[5];
};
struct CQuestMgr__GunEmporiumSendInfo
{
	bool bAcceptOrDecline;
	bool bDecline;
	unsigned int nAcceptOrDeclineQuestID;
	bool bComplete;
	unsigned int nCompleteQuestID;
};
struct CButeListReader
{
	unsigned __int16 m_cItems;
	char** m_szItems;
};
struct SharedTexture {};
class CQuestMgr
{
	std::map<unsigned long, QUESTINFO*, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, QUESTINFO*> > > m_QuestMap;
	std::vector<QUESTINFO*, std::allocator<QUESTINFO*> > m_QuestVector;
	std::set<unsigned long, std::less<unsigned long>, std::allocator<unsigned long> > m_AcceptedQuestSet;
	CButeListReader m_WarningMsg;
	std::set<int, std::less<int>, std::allocator<int> > m_UpgradeWeaponSet;
	CButeListReader lJobNPCDialog[12];
	std::map<unsigned long, DETAIL_DAILY_QUEST, std::less<unsigned long>, std::allocator<std::pair<unsigned long const, DETAIL_DAILY_QUEST> > > m_DailyQuestInfoMap;
	_FILETIME m_ftDailyBegin;
	_FILETIME m_ftDailyEnd;
	unsigned int m_nDailyCompleteID;
	int m_nDailyQuestMainID;
	unsigned int m_dwDailyQuestSeqNo;
	bool m_bUpdateDailyQuest;
	bool m_bEnableDailyQuest;
	bool m_bRewardDailyQuest;
	std::map<std::basic_string<char, std::char_traits<char>, std::allocator<char> >, SharedTexture*, std::less<std::basic_string<char, std::char_traits<char>, std::allocator<char> > >, std::allocator<std::pair<std::basic_string<char, std::char_traits<char>, std::allocator<char> > const, SharedTexture*> > > m_faceType;
	std::set<unsigned long, std::less<unsigned long>, std::allocator<unsigned long> > m_setUserDailyQuestID;
	CQuestMgr__GunEmporiumSendInfo m_GunEmporiumSendInfo;
};
struct _INVEN_ITEM_SUPPLY
{
	int m_nItemNo;
	unsigned int m_dwUItemID;
	_FILETIME m_ftEndTime;
	unsigned int m_dwQuantity;
};
struct CLR_CompleteQuest
{
	unsigned int m_dwQuestID;
	unsigned int m_dwTargetWeaponUItemID;
	_INVEN_ITEM_SUPPLY m_NewWeapon;
};