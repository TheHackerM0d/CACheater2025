enum eCreateRoomEdit
{
	eInput_CreateTitle = 0x0,
	eInput_CreatePW = 0x1,
	eInput_CreateWeapon = 0x2,
	eInput_CreateWeapon_sec = 0x3,
	eInput_CreateWeapon_thr = 0x4,
	eInput_Max = 0x5,
};
enum PlayType
{
	ePlayType_Multi = 0x0,
	ePlayType_Single = 0x1,
	ePlayType_Max = 0x2,
};
enum GUIEditCtrl_eInputMode
{
	kInputAll = 0x0,
	kInputAlphaNumeric = 0x1,
	kInputAlphaOnly = 0x2,
	kInputNumberOnly = 0x4,
	kInputNotAllowSpace = 0x8,
};
enum eMsgSoundType
{
	MSG_SOUND_NOMAL = 0x0,
	MSG_SOUND_ERROR = 0x1,
	MSG_SOUND_MAX = 0x2,
};
enum eMBType
{
	LTMB_OK = 0x0,
	LTMB_YESNO = 0x1,
	LTMB_3BUTTON = 0x2,
	LTMB_EDIT = 0x3,
	LTMB_NONE = 0x4,
	LTMB_CANCEL = 0x5,
};
enum DamageType
{
	DT_UNSPECIFIED = 0,
	DT_BLEEDING = 1,
	DT_BULLET = 2,
	DT_BURN = 3,
	DT_CHOKE = 4,
	DT_CRUSH = 5,
	DT_ELECTROCUTE = 6,
	DT_EXPLODE = 7,
	DT_FREEZE = 8,
	DT_POISON = 9,
	DT_ENDLESS_FALL = 10,
	DT_SLEEPING = 11,
	DT_STUN = 12,
	DT_MELEE = 13,
	DT_CAMERA_DISABLER = 14,
	DT_GLUE = 15,
	DT_LAND_TRAP = 16,
	DT_LAUGHING = 17,
	DT_ASSS = 18,
	DT_GADGET_CODE_DECIPHERER = 19,
	DT_GADGET_POODLE = 20,
	DT_GADGET_LOCK_PICK = 21,
	DT_GADGET_WELDER = 22,
	DT_GADGET_LIGHTER = 23,
	DT_GADGET_CAMERA = 24,
	DT_WORLDONLY = 25,
	DT_GADGET_INFRA_RED = 26,
	DT_GADGET_DECAYPOWDER = 27,
	DT_GADGET_TIME_BOMB = 28,
	DT_GADGET_INK_REAGENT = 29,
	DT_GADGET_EAVESDROPBUG = 30,
	DT_SLIPPERY = 31,
	DT_SWORD = 32,
	DT_GADGET_TRACKER = 33,
	DT_FLASHBANG = 34,
	DT_CRUSH_ICE = 35,
	DT_INFECT = 36,
	DT_HEAL = 37,
	DT_CLAYMORE = 38,
	DT_STAMINA = 39,
	DT_INFECTED_EXPLODE = 40,
	DT_INFECTED_POISON = 41,
	DT_FAK_HEAL = 42,
	DT_BUMP = 43,
	DT_CAMERA_REVERSE = 44,
	DT_CROSSBOW = 45,
	DT_EMP_BOMB = 46,
	DT_SNOWBALL = 47,
	DT_ICEBALL_EXP = 48,
	DT_FIST = 49,
	kNumDamageTypes = 50
};
enum HitLocation
{
	HL_UNKNOWN = 0,
	HL_HEAD = 1,
	HL_TORSO = 2,
	HL_ARM = 3,
	HL_LEG = 4,
	HL_NUT = 5,
	HL_NUM_LOCS = 6
};
enum CLIENTSTATUS
{
	CS_NONE = 0,
	CS_ALIVE = 1,
	CS_DEAD = 2
};
enum GameType
{
	eGameTypeSingle = 0x0,
	eGameTypeTeamDeathMatch = 0x1,
	eGameTypeCombat = 0x2,
	eGameTypeClanDefault = 0x3,
	eGameTypeClanTeamDeathMatch = 0x4,
	eGameTypeCooperativeMission = 0x5,
	eGameTypeFreeForAll = 0x6,
	eGameTypeCapturetheFlag = 0x7,
	eGameTypeClanCapturetheFlag = 0x8,
	eGameTypeBountyHunter = 0x9,
	eGameTypeSnowballFight = 0xA,
	eGameTypeQuarantine = 0xB,
	eGameTypeSurvival = 0xC,
	eGameTypeClanSurvival = 0xD,
	eGameTypeLastManStanding = 0xE,
	eGameTypeSabotage = 0xF,
	eGameTypeTutorial = 0x10,
	eGameTypeHeadQuaters = 0x11,
	eGameTypeCreditOffice = 0x12,
	eGameTypeSquadMatch = 0x13,
	eGameTypeSquadMatch2 = 0x14,
	eGameTypeESL = 0x15,
	eGameTypeVIPWeaponRaceMode = 0x16,
	eGameTypeVIPEscort = 0x17,
	eGameTypeClanVIPEscort = 0x18,
	eGameTypeVIPElimination = 0x19,
	eGameTypeInfectedShip = 0x1A,
	eGameTypeCabinFever2 = 0x1B,
	eGameTypeBotDeathMatch = 0x1C,
	eGameTypeHungerGame = 0x1D,
	eGameTypeBotTutorial = 0x1E,
	eGameTypeMaxNum = 0x1F,
};
enum eQuestStatus
{
	eQuestStatus_Enable = 0,
	eQuestStatus_Disable = 1,
	eQuestStatus_InProgress = 2,
	eQuestStatus_Completed = 3,
	eQuestStatus_Finish = 4,
	eQuestStatus_Lock = 5,
	eQuestStatusNum = 6,
	eQuestStatusEX_Accept = 6,
	eQuestStatusEX_Decline = 7,
	eQuestStatusEX_Reward = 8,
	eQuestStatusEX_Cancel = 9,
	eQuestTotalStatusNum = 10
};
enum GameState
{
	GS_UNDEFINED = 0,
	GS_PLAYING = 1,
	GS_EXITINGLEVEL = 2,
	GS_LOADINGLEVEL = 3,
	GS_SPLASHSCREEN = 4,
	GS_SCREEN = 5,
	GS_PAUSED = 6,
	GS_DEMOSCREEN = 7,
	GS_MOVIE = 8
};
enum eTeam
{
	eTeam_Alpha = 0,
	eTeam_Bravo = 1,
	eTeam_Max = 2,
	eTeam_Observer = 3,
	eTeam_None = -1
};
enum PlayerState
{
	PS_UNKNOWN = 0,
	PS_ALIVE = 1,
	PS_DEAD = 2,
	PS_DYING = 3,
	PS_WAITING = 4,
	PS_MAX = 5,
	PS_SPECTACTOR = -5
};
enum eHUDMode
{
	HUDMode_Normal = 0x0,
	HUDMode_Robot = 0x1,
	HUDMode_RefereeObserver = 0x2,
	HUDMode_GMObserver = 0x3,
	HUDMode_Max = 0x4,
};
enum WeaponState
{
	W_INACTIVE = 0x0,
	W_IDLE = 0x1,
	W_BEGIN_FIRING = 0x2,
	W_FIRING = 0x3,
	W_FIRED = 0x4,
	W_END_FIRING = 0x5,
	W_SWAT_DEFENSE = 0x6,
	W_HOLD_DEFENSE = 0x7,
	W_ARM_DEFENSE = 0x8,
	W_RELOADING = 0x9,
	W_FIRING_NOAMMO = 0xA,
	W_SELECT = 0xB,
	W_DESELECT = 0xC,
	W_AUTO_SWITCH = 0xD,
	W_DASH = 0xE,
	W_ALT_FIREING = 0xF,
};
enum FX_PROPeDataType
{
	STRING = 0x0,
	INTEGER = 0x1,
	FLOATS = 0x2,
	COMBO = 0x3,
	VECTOR = 0x4,
	VECTOR4 = 0x5,
	CLRKEY = 0x6,
	PATH = 0x7,
	ENUM = 0x8,
};
enum CPWeaponStatusTyps
{
	WS_NONE = 0x0,
	WS_RELOADING = 0x1,
	WS_SELECT = 0x2,
	WS_DESELECT = 0x3,
	WS_HIT = 0x4,
	WS_IDLE = 0x5,
};
enum eModSpecialFuncType
{
	MODSF_INSTDAMAGE = 0x0,
	MODSF_KNOCKBACK = 0x1,
	MODSF_STUN = 0x2,
	MODSF_CRIT = 0x3,
	MAX_MODSF = 0x4,
};
enum eModTargetType
{
	TARGET_ALL = 0x0,
	TARGET_PLAYER = 0x1,
	TARGET_NPC = 0x2,
	TARGET_HUMAN = 0x3,
	TARGET_ZOMBIE = 0x4,
	TARGET_PH = 0x5,
	TARGET_PZ = 0x6,
	TARGET_NH = 0x7,
	TARGET_NZ = 0x8,
	MAX_TARGETTYPE = 0x9,
};
enum ModType
{
	SILENCER = 0x0,
	SCOPE = 0x1,
	DOTSIGHT = 0x2,
	FLASHHIDER = 0x3,
	MUZZLEATTACH = 0x4,
	MAGAZINE = 0x5,
	UNKNOWN_MOD_TYPE = 0x6,
};
enum ModKind
{
	KIND_MUZZLE = 0x0,
	KIND_SCOPE = 0x1,
	KIND_MAGAZINE = 0x2,
	MAX_SOCKETMOD = 0x3,
	KIND_BULLET = 0x3,
	KIND_MECH_SIGHT = 0x4,
	MAX_WEAPONMOD = 0x5,
	KIND_MOD_HAED = 0x5,
	KIND_MOD_FACE = 0x6,
	KIND_MOD_VEST = 0x7,
	MAX_MODKIND = 0x8,
};
enum DotSightColorType
{
	DSIGHT_RED = 0x0,
	DSIGHT_GREEN = 0x1,
	DSIGHT_WHITE = 0x2,
	UNKNOWN_DSIGHT_COLOR = 0x3,
};
enum SightSystemStyle
{
	SIGHT_NORMAL = 0x0,
	SIGHT_RANGE = 0x1,
	SIGHT_GAUGE = 0x2,
	UNKNOWN_SIGHT_SYSTEM = 0x3,
};
enum FireType
{
	FT_NORMAL_FIRE = 0x0,
	FT_ALT_FIRE = 0x1,
};
enum ScaleFXType
{
	SCALEFX_MODEL = 0x0,
	SCALEFX_SPRITE = 0x1,
};
enum ModelId
{
	eModelIdInvalid = 0xFFFF,
};
enum ModelNode
{
	eModelNodeInvalid = 0xFF,
};
enum SurfaceType
{
	ST_UNKNOWN = 0x0,
	ST_AIR = 0x1,
	ST_ADULTHEAD = 0x4,
	ST_TEENHEAD = 0x5,
	ST_ADULTBODY = 0x6,
	ST_TEENBODY = 0x7,
	ST_METAL = 0x14,
	ST_SKY = 0x6E,
	ST_LADDER = 0xC8,
	ST_LIQUID = 0xC9,
	ST_INVISIBLE = 0xCA,
	ST_WATER = 0xCC,
	ST_DEFAULT = 0x0,
};
enum ModelTrackingNodeGroup
{
	eModelTrackingNodeGroupInvalid = 0xFF,
};
enum ModelSex
{
	eModelSexMan = 0x0,
	eModelSexWoman = 0x1,
	eModelSexMax = 0x2,
};
enum ModelSkeleton
{
	eModelSkeletonInvalid = 0xFF,
};
enum ModelType
{
	eModelTypeHuman = 0x0,
	eModelTypeAnimal = 0x1,
	eModelTypeVehicle = 0x2,
	eModelTypeGenericProp = 0x3,
	eModelTypeInvalid = 0xFF,
};
enum ModelFigureType
{
	eModelFigureTypeStandard = 0x0,
	eModelFigureTypeSpeed = 0x1,
	eModelFigureTypeStrength = 0x2,
	eModelFigureTypeAccuracy = 0x3,
	eModelFigureTypeNum = 0x4,
	eModelFigureTypeInvalid = 0xFF,
};
enum ContainerCode
{
	CC_NO_CONTAINER = 0x0,
	CC_WATER = 0x1,
	CC_CORROSIVE_FLUID = 0x2,
	CC_ICE = 0x3,
	CC_FREEZING_WATER = 0x4,
	CC_POISON_GAS = 0x5,
	CC_ELECTRICITY = 0x6,
	CC_ENDLESS_FALL = 0x7,
	CC_WIND = 0x8,
	CC_COLDAIR = 0x9,
	CC_BURN = 0xA,
	CC_LADDER = 0xB,
	CC_WEATHER = 0xC,
	CC_VOLUME = 0xD,
	CC_FILTER = 0xE,
	CC_SAFTEY_NET = 0xF,
	CC_JUMP_VOLUME = 0x11,
	CC_DYNAMIC_OCCLUDER_VOLUME = 0x12,
	CC_GRAVITY = 0x13,
	CC_DAMAGE_VOLUME = 0x14,
	CC_WORLD_VOLUME = 0x15,
	CC_MAX_CONTAINER_CODES = 0x16,
};
enum PlayerPhysicsModel
{
	PPM_FIRST = 0x0,
	PPM_NORMAL = 0x0,
	PPM_NUM_MODELS = 0x1,
};
enum FacePieceId
{
	eFacePieceIdInvalid = 0xFF,
};
enum HeadPieceId
{
	eHeadPieceIdInvalid = 0xFFFF,
};
enum CBaseFXFXType
{
	eBaseFX = 0x0,
	eParticleSystemFX = 0x1,
	eSpriteFX = 0x2,
	eLTBModelFX = 0x3,
	eDynaLightFX = 0x4,
	ePlaySoundFX = 0x5,
	eCamJitterFX = 0x6,
	eCamWobbleFX = 0x7,
	eLTBBouncyChunkFX = 0x8,
	eNullFX = 0x9,
	ePolyTubeFX = 0xA,
	ePlayRandomSoundFX = 0xB,
	eSpriteSystem = 0xC,
	eCreateFX = 0xD,
	eFlareSpriteFX = 0xE,
	eLightningFX = 0xF,
	eLTBSystemFX = 0x10,
	eDamageSystemFX = 0x11,
};
enum WaveType
{
	Wave_Linear = 0x0,
	Wave_Sine = 0x1,
	Wave_SlowOff = 0x2,
	Wave_SlowOn = 0x3,
	NUM_WAVETYPES = 0x4,
};
enum GadgetTargetType
{
	eINVALID = 0x0,
	eKeyPad = 0x1,
	eCardReader = 0x2,
	eCodedText = 0x3,
	eComboLock = 0x4,
	ePadLock = 0x5,
	eDoorKnob = 0x6,
	eTelephone = 0x7,
	ePhotographable = 0x8,
	eBombable = 0x9,
	eInvisibleInk = 0xA,
	eMAX_GADGET_TARGET_TYPES = 0xB,
};
enum PlayerExtState
{
	PES_UNKNOWNq = 0x0,
	PES_GHOST = 0x1,
	PES_GM = 0x2,
	PES_MAX = 0x3,
};
enum CPlayerCameraCameraState
{
	SOUTH = 0x0,
	SOUTHEAST = 0x1,
	EAST = 0x2,
	NORTHEAST = 0x3,
	NORTH = 0x4,
	NORTHWEST = 0x5,
	WEST = 0x6,
	SOUTHWEST = 0x7,
	MLOOK = 0x8,
	HOLD = 0x9,
};
enum CPlayerCameraCameraMode
{
	FIRSTPERSON = 0x0,
	CHASE = 0x1,
	GOINGFIRSTPERSON = 0x2,
	CIRCLING = 0x3,
	STATIC_CHASE = 0x4,
	FIRSTPERSON_CHASE = 0x5,
	SCRIPT = 0x6,
	FIRST_CHASE = 0x7,
};
enum CPlayerCameraCameraPoint
{
	AT_POSITION = 0x0,
	IN_DIRECTION = 0x1,
	AUTOMATIC = 0x2,
};
enum TriggerType
{
	eDefaultTrigger = 0x0,
	eAmmoTrigger = 0x1,
	eBGMTrigger = 0x2,
	ePlayerTrigger = 0x3,
	eBombZoneTrigger = 0x4,
	eAmmoHealthTrigger = 0x5,
	eFlagZoneTrigger = 0x6,
	eTargetTrigger = 0x7,
	eActivateTrigger = 0x8,
	ePerkAmmoTrigger = 0x9,
	eEscapeZoneTrigger = 0xA,
};
enum eVoteStep
{
	VS_SelectNone = 0x0,
	VS_SelectUser = 0x1,
	VS_SelectReason = 0x2,
	VS_SelectConfirmation = 0x3,
	VS_SelectError = 0x4,
	VS_WaitingKicker = 0x5,
	VS_WaitingTarget = 0x6,
	VS_BeforVote = 0x7,
	VS_AfterVote = 0x8,
	VS_FailVoteKick = 0x9,
	VS_SuccessVoteKick = 0xA,
	VS_ResultEMKick = 0xB,
	VS_BeforEMKickVote = 0xC,
	VS_AfterEMKickVote = 0xD,
};
enum eEmotionType
{
	Emotion_None = 0xFFFFFFFF,
	Emotion_Death = 0x0,
	Emotion_Insult = 0x1,
	Emotion_Surrender = 0x2,
	Emotion_Dance = 0x3,
	Emotion_Salute = 0x4,
	Emotion_Max = 0x5,
};
enum eCrosshairShape
{
	Crosshair_Shape_Default = 0,
	Crosshair_Shape_Square = 1,
	Crosshair_Shape_Triangle = 2,
	Crosshair_Shape_Diaper = 3,
	Crosshair_Shape_Circle = 4,
	Crosshair_Shape_Double_Circle = 5,
	Crosshair_Shape_Double_Barrel = 6,
	Crosshair_Shape_Max = 7,
};
enum CAnimationSetWeapon
{
	eRifleF = 0x0,
	eRifleB = 0x1,
	eRifleH = 0x2,
	eSMG = 0x3,
	eSMGH = 0x4,
	eSniper = 0x5,
	eShotgunAuto = 0x6,
	eShotgun = 0x7,
	eMachineGun = 0x8,
	eVulcan = 0x9,
	ePistol = 0xA,
	eGrenade = 0xB,
	eRocketLauncher = 0xC,
	eTimeBomb = 0xD,
	eKnife = 0xE,
	eShotgunB = 0xF,
	eKnifeG = 0x10,
	eFlamethrower = 0x11,
	eHeartBeatSensor = 0x12,
	eRocketLauncherB = 0x13,
	eLandMine = 0x14,
	eClaymoreMine = 0x15,
	eClaymoreControl = 0x16,
	eRifleA = 0x17,
	eRevolver = 0x18,
	eSMG_P90 = 0x19,
	eSMG_FAMAS = 0x1A,
	eSG_DoubleBarrel = 0x1B,
	eChaingun = 0x1C,
	eSG_SnowBallGun = 0x1D,
	NPCWEAPONS = 0x1E,
	eNPCGrenade = 0x1F,
	eNPCMelee = 0x20,
	eNPCBossChainGun = 0x21,
	eNPCBossGrenade = 0x22,
	eNPCBossMelee = 0x23,
	eSpecialM32 = 0x24,
	eSpecialMili_PDA = 0x25,
	eSpecialMedicKit = 0x26,
	eQuarantineHand = 0x27,
	eFlamethrowerSide = 0x28,
	eRPG7 = 0x29,
	eMotherOfAllBombs = 0x2A,
	eFirstAidKit = 0x2B,
	eHornet = 0x2C,
	eAutoTurret = 0x2D,
	eTMP = 0x2E,
	eQuarantineClub = 0x2F,
	eMobileGrenade = 0x30,
	eMGController = 0x31,
	eKnuckle = 0x32,
	eM2_Browning = 0x33,
	eXM25 = 0x34,
	eFG42 = 0x35,
	eRemington = 0x36,
	eSuperShorty = 0x37,
	eM1Garand = 0x38,
	eDouble_Scorpion = 0x39,
	eMiddleRobot_SMG = 0x3A,
	eMiddleRobot_Pistol = 0x3B,
	eMiddleRobot_SR = 0x3C,
	eMiddleRobot_Melee = 0x3D,
	eMiddleRobot_Heal = 0x3E,
	eLargeRobot_MG = 0x3F,
	eLargeRobot_FG = 0x40,
	eNerveConfuseMine = 0x41,
	eNPCRobot_SMG = 0x42,
	eNPCRobot_Melee = 0x43,
	eNPCRealMelee = 0x44,
	eNPCStraightRush = 0x45,
	eNPCStrafe_R = 0x46,
	eNPCStrafe_L = 0x47,
	eNPCMultipleShot = 0x48,
	eNPCDamaged = 0x49,
	eChainsaw = 0x4A,
	kNumWeapons = 0x4B,
};
enum CAnimationSetPosture
{
	eAim = 0x0,
	ePreFire = 0x1,
	eFire = 0x2,
	ePostFire = 0x3,
	eSelect = 0x4,
	eReload = 0x5,
	eHit = 0x6,
	eHit2 = 0x7,
	eHit3 = 0x8,
	eAltFire = 0x9,
	NPCPOSTURE = 0xA,
	eTBLooseIdle1 = 0xB,
	eTBLooseIdle2 = 0xC,
	eNPCFire1 = 0xD,
	eNPCFire2 = 0xE,
	eNPCFire3 = 0xF,
	eNPCAppear = 0x10,
	eNPCSkill_ST = 0x11,
	eNPCSkill_LP = 0x12,
	eNPCSkill_ED = 0x13,
	kNumPostures = 0x14,
};
enum CAnimationSetMovement
{
	eWalking = 0x0,
	eRunning = 0x1,
	eCrouching = 0x2,
	eJumping = 0x3,
	eStandRot = 0x4,
	eSitRot = 0x5,
	eDash = 0x6,
	eDashJump = 0x7,
	eDirectLay = 0x8,
	NPCMOVEMENT = 0x9,
	eLooseWalking = 0xA,
	eInvestigate = 0xB,
	eTBHiding = 0xC,
	eBossGuard = 0xD,
	eBossReinforce = 0xE,
	eZombieCrouching = 0xF,
	eNoneWeaponWalking = 0x10,
	kNumMovements = 0x11,
};
enum CAnimationSetLowerAniType
{
	eLowerAni_Normal = 0x0,
	eLowerAni_Zombie = 0x1,
	eLowerAni_ZombieClub = 0x2,
	kNumLowerAnis = 0x3,
};
enum AntihackSubCommands
{
	AH_NONE = 0x0,
	AH_OPK_POS_SELF_TEST = 0x1,
	AH_OPK_POS_SELF_TEST_RESULT = 0x2,
	AH_OPK_POS_REQUEST = 0x3,
	AH_OPK_POS_RESPONSE = 0x4,
	AH_BEAST_PLAYERSTATE = 0x5,
	AH_MAX = 0x6,
};
enum WEAPON_USE_TYPE
{
	ALL_USE = 0x0,
	PISTOL_ONLY = 0x1,
	KNIFE_ONLY = 0x2,
	SNIPE_EXCEPT = 0x3,
	BOMB_EXCEPT = 0x4,
	BACKPACK_EXCEPT = 0x5,
	SNIPE_ONLY = 0x6,
	SHOTGUN_ONLY = 0x7,
	SHOTGUN_EXCEPT = 0x8,
	SPECIALIST_EXCEPT = 0x9,
	ESLITEMS_ONLY = 0xA,
	WEAPON_USE_TYPE_NUM = 0xB,
};
enum CHUDCrosshair__E_CROSSHAIR_COMPONENT
{
	CH_LEFT = 0x1,
	CH_RIGHT = 0x2,
	CH_TOP = 0x4,
	CH_BOTTOM = 0x8,
	CH_X_LEFT_TOP = 0x10,
	CH_X_LEFT_BOTTOM = 0x20,
	CH_X_RIGHT_TOP = 0x40,
	CH_X_RIGHT_BOTTOM = 0x80,
	CH_DOT = 0x100,
	CH_CIRCLE = 0x200,
	CH_LEFT_BRAKET = 0x400,
	CH_RIGHT_BRAKET = 0x800,
};
enum CLIENT_TYPE
{
	CLIENT_TYPE_NONE = 0x0,
	CLIENT_TYPE_USER = 0x1,
	CLIENT_TYPE_GM = 0x2,
	CLIENT_TYPE_REFEREE = 0x3,
	CLIENT_TYPE_GH = 0x4,
	CLIENT_TYPE_MAX = 0x5,
};
enum _CLIENT_WEAPON_TYPE
{
	CLIENT_WEAPON_TYPE_NONE = 0x0,
	CLIENT_WEAPON_TYPE_VECTOR = 0x1,
	CLIENT_WEAPON_TYPE_PROJECTILE = 0x2,
	NUM_CLIENT_WEAPON_TYPES = 0x3,
};
enum ITEM_GRADE
{
	ITEM_GRADE_NONE = 0x0,
	ITEM_GRADE_F = 0x1,
	ITEM_GRADE_E = 0x2,
	ITEM_GRADE_D = 0x3,
	ITEM_GRADE_C = 0x4,
	ITEM_GRADE_B = 0x5,
	ITEM_GRADE_A = 0x6,
	ITEM_GRADE_S = 0x7,
	ITEM_GRADE_SS = 0x8,
	ITEM_GRADE_SSS = 0x9,
	MAX_ITEM_GRADE = 0xA,
};
enum EQUIP_TYPE
{
	ITEM_RELEASE = 0xFFFFFFFF,
	ITEM_ASSULT_EQUIP = 0x0,
	ITEM_SUBGUN_EQUIP = 0x1,
	ITEM_KNIFE_EQUIP = 0x2,
	ITEM_BOMB_EQUIP = 0x3,
	ITEM_HELMET_EQUIP = 0x4,
	ITEM_FACE_EQUIP = 0x5,
	ITEM_GOGGLE_EQUIP = 0x6,
	ITEM_MUNIFORM_EQUIP = 0x7,
	ITEM_BUNIFORM_EQUIP = 0x8,
	ITEM_BACKPACK_EQUIP = 0x9,
	ITEM_BACKPACK_SLOT1 = 0xA,
	ITEM_BACKPACK_SLOT2 = 0xB,
	ITEM_BACKPACK_SLOT3 = 0xC,
	ITEM_BACKPACK_SLOT4 = 0xD,
	ITEM_FIGURE_EQUIP = 0xE,
	ITEM_COSMETIC_CHARACTER = 0xF,
	ITEM_COSMETIC_HEAD = 0x10,
	ITEM_COSMETIC_FACE = 0x11,
	ITEM_COSMETIC_VEST = 0x12,
	ITEM_COSMETIC_BACKPACK = 0x13,
	ITEM_EQUIP_NUM = 0x14,
	ITEM_FREEPASS_EQUIP_NUM = 0xF,
	ITEM_PERK_SLOT1 = 0x15,
	ITEM_PERK_SLOT2 = 0x16,
	ITEM_PERK_SLOT3 = 0x17,
	ITEM_OPTION_WEAPON = 0x18,
	ITEM_OPTION_GEAR = 0x19,
};
enum USEBOX_TYPE
{
	CLANNAME = 0x0,
	CLANMARK = 0x1,
	CLANSCORE = 0x2,
	USERNAME = 0x3,
	FACE = 0x4,
	GENDER = 0x5,
	USERNAMECOLOR = 0x6,
	CLANNAMECOLOR = 0x7,
	USERKILLDEATH = 0x8,
	CROSSHAIRCOLOR = 0x9,
	SUPERMASTER = 0xA,
	DEFAULTITEM = 0xB,
	PLUSGP_EXP = 0xC,
	FREEPASS_ITEM = 0xD,
	COUNTRYCHANGE = 0xE,
	PLUS_SLOT = 0xF,
	HISECKEY = 0x10,
	INFECTEDCHARACTER = 0x11,
	TOKEN = 0x12,
	MEGAPHONE = 0x13,
	MEGAPHONE_ACTIVATE = 0x14,
	EXTEND = 0x15,
	EXTEND_ACTIVATE = 0x16,
	KDR_USE = 0x17,
	BINGO_BOX = 0x18,
	PARTY_TOKEN = 0x19,
	NOSPECIALIST = 0x1A,
	CHANGE_WEAPON_SET = 0x1B,
	ROULETTE = 0x1C,
	GOLD_PAKAGE = 0x1D,
	GOLDPASS = 0x1E,
	HIDING_RANK = 0x1F,
	HIDING_NATION = 0x20,
	NAME_BG = 0x21,
	EXPASS = 0x22,
	SINGLEPLAY_TOKEN = 0x23,
	MARBLE_DICE = 0x24,
	MAX_USE_ITEM_BOX = 0x25,
};
enum CAM_TARGET_INFO__CHAR_INFO_TYPE
{
	CLIENT_CHAR_INFO = 0x0,
	BOT_CHAR_INFO = 0x1,
	CHAR_INFO_TYPE_MAX = 0x2,
};
enum eScreenCmds
{
	CMD_NONE = 0x0,
	CMD_BACK = 0x1,
	CMD_LEFT = 0x2,
	CMD_RIGHT = 0x3,
	CMD_PAUSE = 0x4,
	CMD_MAIN = 0x5,
	CMD_OK = 0x6,
	CMD_CANCEL = 0x7,
	CMD_UPDATE = 0x8,
	CMD_CLOSE = 0x9,
	CMD_QUIT = 0xA,
	CMD_LOGOUT = 0xB,
	CMD_SEARCH = 0xC,
	CMD_JOIN_GAME = 0xD,
	CMD_MULTI_PLAYER_LAN = 0xE,
	CMD_PLAYER = 0xF,
	CMD_HOST = 0x10,
	CMD_JOIN = 0x11,
	CMD_EDIT_NAME = 0x12,
	CMD_EDIT_PORT = 0x13,
	CMD_TOGGLE_PASS = 0x14,
	CMD_SET_OPTIONS = 0x15,
	CMD_CHOOSE_CAMPAIGN = 0x16,
	CMD_SET_LEVELS = 0x17,
	CMD_EDIT_BANDWIDTH = 0x18,
	CMD_LAUNCH = 0x19,
	CMD_APPLY = 0x1A,
	CMD_DISPLAY = 0x1B,
	CMD_AUDIO = 0x1C,
	CMD_CONTROLS = 0x1D,
	CMD_GAME = 0x1E,
	CMD_PERFORMANCE = 0x1F,
	CMD_LIGHT = 0x20,
	CMD_VSYNC = 0x21,
	CMD_INVERTY = 0x22,
	CMD_CONFIGURE = 0x23,
	CMD_MOUSE = 0x24,
	CMD_KEYBOARD = 0x25,
	CMD_JOYSTICK = 0x26,
	CMD_RESET_DEFAULTS = 0x27,
	CMD_CROSSHAIR = 0x28,
	CMD_SFX = 0x29,
	CMD_TEXTURE = 0x2A,
	CMD_MOVE_COM = 0x2B,
	CMD_INV_COM = 0x2C,
	CMD_VIEW_COM = 0x2D,
	CMD_MISC_COM = 0x2E,
	CMD_CHANGE_CONTROL = 0x2F,
	CMD_CHANGE_CONTROL_MOVE = 0x30,
	CMD_CHANGE_CONTROL_COMBAT = 0x31,
	CMD_CHANGE_CONTROL_WEAPON = 0x32,
	CMD_CHANGE_CONTROL_OTHERS = 0x33,
	CMD_LOAD = 0x34,
	CMD_CONFIRM = 0x35,
	CMD_DELETE = 0x36,
	CMD_RENAME = 0x37,
	CMD_EDIT = 0x38,
	CMD_NATION = 0x39,
	CMD_CHAR_INFO = 0x3A,
	CMD_SERVER_INFO = 0x3B,
	CMD_WAITING_ROOM = 0x3C,
	CMD_SHOP = 0x3D,
	CMD_COSMETIC = 0x3E,
	CMD_TRADE = 0x3F,
	CMD_CHANNEL = 0x40,
	CMD_RANK = 0x41,
	CMD_OPTIONS = 0x42,
	CMD_WND_CLOSE = 0x43,
	CMD_SERVER_SELECT = 0x44,
	CMD_DAILY_ATTANDANCE = 0x45,
	CMD_CINOR = 0x46,
	CMD_KRONOC = 0x47,
	CMD_CREATE = 0x48,
	CMD_OVERLAPPING = 0x49,
	CMD_CLAN_CREATE_JOIN = 0x4A,
	CMD_CLAN_CANCEL = 0x4B,
	CMD_SEX_MAN = 0x4C,
	CMD_SEX_WOMAN = 0x4D,
	CMD_BODY_BIG = 0x4E,
	CMD_BODY_STANDARD = 0x4F,
	CMD_FACE_SELECT = 0x50,
	CMD_HAIR_SELECT = 0x51,
	CMD_COVENANT = 0x52,
	CMD_PREV = 0x53,
	CMD_NEXT = 0x54,
	CMD_EDIT_PASS = 0x55,
	CMD_SERVER_NEW = 0x56,
	CMD_SERVER_FULL = 0x57,
	CMD_SERVER_PRE_JOIN = 0x58,
	CMD_SERVER_SEARCH = 0x59,
	CMD_LOBBY_JOIN = 0x5A,
	CMD_MAP_TYPE = 0x5B,
	CMD_SET_MODE = 0x5C,
	CMD_SET_BATTLE = 0x5D,
	CMD_SET_MATCH = 0x5E,
	CMD_PASSWORD = 0x5F,
	CMD_AUTOBALANCE_ON = 0x60,
	CMD_AUTOBALANCE_OFF = 0x61,
	CMD_BLOCK_GAME_ON = 0x62,
	CMD_BLOCK_GAME_OFF = 0x63,
	CMD_MIN_LEVEL = 0x64,
	CMD_MAX_LEVEL = 0x65,
	CMD_SORT = 0x66,
	CMD_CHANNEL_CUSTOM = 0x67,
	CMD_CHANNEL_CLAN = 0x68,
	CMD_CHANNEL_JOIN = 0x69,
	CMD_CHANNEL_JOIN_OK = 0x6A,
	CMD_CHANNEL_CREATE = 0x6B,
	CMD_CHANNEL_CREATE_OK = 0x6C,
	CMD_GAME_READY = 0x6D,
	CMD_GAME_KICK = 0x6E,
	CMD_GAME_CHANGE = 0x6F,
	CMD_TEAM_CHANGE = 0x70,
	CMD_TEAM_CHANGE_ON = 0x71,
	CMD_TEAM_CHANGE_OFF = 0x72,
	CMD_WHISPER = 0x73,
	CMD_SHOUT = 0x74,
	CMD_CUT_WHISPER = 0x75,
	CMD_CUT_SHOUT = 0x76,
	CMD_CHAT = 0x77,
	CMD_SHOW_ALL = 0x78,
	CMD_SHOW_WHISPER = 0x79,
	CMD_SHOW_SHOUT = 0x7A,
	CMD_SHOW_CLAN = 0x7B,
	CMD_FRIEND_FIND = 0x7C,
	CMD_FRIEND_FIND_OK = 0x7D,
	CMD_FRIEND_LIST = 0x7E,
	CMD_FRIEND_DELETE = 0x7F,
	CMD_FRIEND_DELETE_OK = 0x80,
	CMD_PLAYER_UP = 0x81,
	CMD_PLAYER_DOWN = 0x82,
	CMD_PLAYER_SELECT = 0x83,
	CMD_TRADE_CANCEL = 0x84,
	CMD_TRADE_CONFIRM = 0x85,
	CMD_PAGE_UP = 0x86,
	CMD_PAGE_DOWN = 0x87,
	CMD_LINE_UP = 0x88,
	CMD_LINE_DOWN = 0x89,
	CMD_CLAN_PAGE_UP = 0x8A,
	CMD_CLAN_PAGE_DOWN = 0x8B,
	CMD_SHOW_CHAR_INFO = 0x8C,
	CMD_SHOW_INVENTORY_INFO = 0x8D,
	CMD_HIDE_BOXINVENTORY = 0x8E,
	CMD_SHOW_BOXINVENTORY = 0x8F,
	CMD_SHOW_INVENTORY = 0x90,
	CMD_ITEM_SET = 0x91,
	CMD_MULTI_SET = 0x92,
	CMD_BUY = 0x93,
	CMD_BUY_OK = 0x94,
	CMD_BUY_CANCEL = 0x95,
	CMD_SELL = 0x96,
	CMD_SELL_OK = 0x97,
	CMD_SELL_CANCEL = 0x98,
	CMD_SELL_ITEM = 0x99,
	CMD_PRIMARY_WEAPON = 0x9A,
	CMD_SECONDARY_WEAPON = 0x9B,
	CMD_BASE_WEAPON = 0x9C,
	CMD_THROW_WEAPON = 0x9D,
	CMD_CLOTH = 0x9E,
	CMD_ARMOR = 0x9F,
	CMD_OPTION_WEAPON = 0xA0,
	CMD_SHOPPAGE_BACK = 0xA1,
	CMD_SHOPPAGE_NEXT = 0xA2,
	CMD_ITEMDETAIL = 0xA3,
	CMD_DOT_SELECT = 0xA4,
	CMD_DOT_BUY = 0xA5,
	CMD_DOT_BUY_OK = 0xA6,
	CMD_CHAR_ITEMDETAIL = 0xA7,
	CMD_ITEM_FORGE_MOVE = 0xA8,
	CMD_ITEM_FORGE_EQUIP = 0xA9,
	CMD_POPUP_SELL = 0xAA,
	CMD_HELPTOGGLE = 0xAB,
	CMD_CLAN = 0xAC,
	CMD_CLAN_LIST = 0xAD,
	CMD_CLAN_CREATE = 0xAE,
	CMD_CLAN_WAITING = 0xAF,
	CMD_CLAN_USER = 0xB0,
	CMD_CLAN_WAITER = 0xB1,
	CMD_CLAN_GAME_LIST = 0xB2,
	CMD_CLAN_GAME_CREATE = 0xB3,
	CMD_CLAN_GAME_WAIT = 0xB4,
	CMD_CLAN_JOIN = 0xB5,
	CMD_CLAN_SECEDE = 0xB6,
	CMD_CLAN_DELETE = 0xB7,
	CMD_MULTIINVEN_FULL = 0xB8,
	CMD_SHOW_NORMAL_INVENTORY = 0xB9,
	CMD_SHOW_CASH_INVENTORY = 0xBA,
	CMD_CASH_USE = 0xBB,
	CMD_TUNING = 0xBC,
	CMD_PLUE = 0xBD,
	CMD_WEB_BUY = 0xBE,
	CMD_WEB_BUY_BEFORE = 0xBF,
	CMD_LOGIN = 0xC0,
	CMD_LOGIN_TO_START = 0xC1,
	CMD_LOGIN_TEXT = 0xC2,
	CMD_GAME_START = 0xC3,
	CMD_START_COMBATARMS = 0xC4,
	CMD_CREDIT = 0xC5,
	CMD_CHARACTER_SELECT = 0xC6,
	CMD_ENTER_CHAR_PWD = 0xC7,
	CMD_CHARACTER_CREATE = 0xC8,
	CMD_DUPL = 0xC9,
	CMD_BODY_ARROW_LEFT = 0xCA,
	CMD_BODY_ARROW_RIGHT = 0xCB,
	CMD_FACE_ARROW_LEFT = 0xCC,
	CMD_FACE_ARROW_RIGHT = 0xCD,
	CMD_SHOWALL_GAMEROOM = 0xCE,
	CMD_SHOW_WAITINGROON = 0xCF,
	CMD_SERVER_CREATE = 0xD0,
	CMD_REFRESH = 0xD1,
	CMD_SERVER_QUICK_JOIN = 0xD2,
	CMD_SERVER_JOIN = 0xD3,
	CMD_ROOM_INDEX = 0xD4,
	CMD_MAP_NAME = 0xD5,
	CMD_GAME_TYPE = 0xD6,
	CMD_GAME_LEVEL_LIMIT = 0xD7,
	CMD_SET_MODE_PREV = 0xD8,
	CMD_SET_MODE_NEXT = 0xD9,
	CMD_CHAR_INFO_WEAPON = 0xDA,
	CMD_CHAR_INFO_CLOTH = 0xDB,
	CMD_CHAR_INFO_WEAPON_OPTION = 0xDC,
	CMD_CHAR_INFO_ITEM_TAB = 0xDD,
	CMD_CHAR_INFO_PREMIUM_TAB = 0xDE,
	CMD_CHAR_INFO_WAREHOUSE_TAB = 0xDF,
	CMD_CHANNEL_USERLIST = 0xE0,
	CMD_JOIN_USER = 0xE1,
	CMD_DETAIL_INFO = 0xE2,
	CMD_ADD_FRIEND = 0xE3,
	CMD_CUSTOM = 0xE4,
	CMD_WEAPON = 0xE5,
	CMD_SPEIAL_WEAPON = 0xE6,
	CMD_HEAD_ITEM = 0xE7,
	CMD_FACE_ITEM = 0xE8,
	CMD_CLOTH_ITEM = 0xE9,
	CMD_KIND_ITEM = 0xEA,
	CMD_BACK_BACK = 0xEB,
	CMD_OPEN_EQUIP = 0xEC,
	CMD_CLOSE_EQUIP = 0xED,
	CMD_OPTION_JOIN_ON = 0xEE,
	CMD_OPTION_JOIN_OFF = 0xEF,
	CMD_OPTION_TEAMKILL_ON = 0xF0,
	CMD_OPTION_TEAMKILL_OFF = 0xF1,
	CMD_OPTION_BALANCE_ON = 0xF2,
	CMD_OPTION_BALANCE_OFF = 0xF3,
	CMD_COMBOBOX_EVENT = 0xF4,
	CMD_MAP_NEXT = 0xF5,
	CMD_MODE_PREV = 0xF6,
	CMD_MODE_NEXT = 0xF7,
	CMD_GOAL_PREV = 0xF8,
	CMD_GOAL_NEXT = 0xF9,
	CMD_LIMIT_PREV = 0xFA,
	CMD_LIMIT_NEXT = 0xFB,
	CMD_GAME_RESULT = 0xFC,
	CMD_SHOP_WEAPON = 0xFD,
	CMD_SHOP_WEAPON_ALL = 0xFE,
	CMD_SHOP_WEAPON_PRIMARY = 0xFF,
	CMD_SHOP_WEAPON_SECONDARY = 0x100,
	CMD_SHOP_WEAPON_MELEE = 0x101,
	CMD_SHOP_WEAPON_THROW = 0x102,
	CMD_SHOP_WEAPON_CLASS = 0x103,
	CMD_SHOP_WEAPON_END = 0x104,
	CMD_SHOP_WAR = 0x105,
	CMD_SHOP_WAR_ALL = 0x106,
	CMD_SHOP_WAR_HEAD = 0x107,
	CMD_SHOP_WAR_FACE = 0x108,
	CMD_SHOP_WAR_CLOTH = 0x109,
	CMD_SHOP_WAR_CLASS = 0x10A,
	CMD_SHOP_WAR_BACKPACK = 0x10B,
	CMD_SHOP_WAR_END = 0x10C,
	CMD_EQUIP_WEAPON = 0x10D,
	CMD_SHOP_BUYITEM = 0x10E,
	CMD_SHOP_SENDITEM = 0x10F,
	CMD_SHOP_EQUIP_OK = 0x110,
	CMD_SHOP_EQUIP_CANCEL = 0x111,
	CMD_REMOVE_GUN = 0x112,
	CMD_REMOVE_PISTOL = 0x113,
	CMD_REMOVE_KNIFE = 0x114,
	CMD_REMOVE_BOMB = 0x115,
	CMD_WEAPON_SLOT = 0x116,
	CMD_BACKPACK_SLOT = 0x117,
	CMD_TUNING_STEP2 = 0x118,
	CMD_WEAPON_SELECT = 0x119,
	CMD_TUNING_ITEM = 0x11A,
	CMD_SLOT1_PREV = 0x11B,
	CMD_SLOT1_NEXT = 0x11C,
	CMD_SLOT2_PREV = 0x11D,
	CMD_SLOT2_NEXT = 0x11E,
	CMD_SLOT3_PREV = 0x11F,
	CMD_SLOT3_NEXT = 0x120,
	CMD_TUNING_OK = 0x121,
	CMD_WEAPON_TUNING = 0x122,
	CMD_OPTION_TUNING = 0x123,
	CMD_SHOP_WEAPON_ETC = 0x124,
	CMD_QUICKSTART = 0x12C,
	CMD_OPTION = 0x12D,
	CMD_HELP = 0x12E,
	CMD_EXIT = 0x12F,
	CMD_CHAR1SLOT = 0x130,
	CMD_CHAR2SLOT = 0x131,
	CMD_CHAR3SLOT = 0x132,
	CMD_CHAR_CREATE = 0x133,
	CMD_CHAR_DELETE = 0x134,
	CMD_CHAR_SELECT = 0x135,
	CMD_MESSENGER = 0x136,
	CMD_SCREEN_EXIT = 0x137,
	CMD_TUNNING_OK = 0x138,
	CMD_SHOP_TUNING = 0x1F4,
	CMD_SHOP_TUNING_ALL = 0x1F5,
	CMD_SHOP_TUNING_SILENCER = 0x1F6,
	CMD_SHOP_TUNING_SIGHT = 0x1F7,
	CMD_SHOP_TUNING_MAGAZINE = 0x1F8,
	CMD_SHOP_TUNING_END = 0x1F9,
	CMD_LIMITWEAPON_NEXT = 0x258,
	CMD_OPTION_VIEWENEMY_ON = 0x259,
	CMD_OPTION_VIEWENEMY_OFF = 0x25A,
	CMD_ERROR_WEAPON_MOVE = 0x25B,
	CMD_CLANMARK_NEXT_PAGE = 0x25C,
	CMD_CLANMARK_PRE_PAGE = 0x25D,
	CMD_CLANMARK_OK = 0x25E,
	CMD_CLANMARK_NEXT = 0x25F,
	CMD_CLANMARK_BACK = 0x260,
	CMD_CLANMARK_CANCEL = 0x261,
	CMD_CLANMARK_USE_OK = 0x262,
	CMD_CLANMARK_USE_BACK = 0x263,
	CMD_USERNAME_BUT_CHECK = 0x264,
	CMD_CLANNAME_BUT_CHECK = 0x265,
	CMD_CLANMARK_BUT_CHECK = 0x266,
	CMD_POPUP_ITEM_BUT_CANCEL = 0x267,
	CMD_POPUP_ITEM_BUT_OK = 0x268,
	CMD_POPUP_ITEM_EDIT_NAME = 0x269,
	CMD_POPUP_ITEM_EDIT_BACK = 0x26A,
	CMD_INBOX = 0x26B,
	CMD_EXIT_GOTO_BLACKMARKET = 0x26C,
	CMD_EXIT_GOTO_CHARGE = 0x26D,
	CMD_BLACKMARKET = 0x26E,
	CMD_CHARGENX = 0x26F,
	CMD_CENTER = 0x270,
	CMD_CONFIRM_CHECK_OK = 0x271,
	CMD_CONFIRM_CHECK_CANCEL = 0x272,
	CMD_REPORT = 0x273,
	CMD_SHOW_CHATMOD = 0x274,
	CMD_CHATMOD_COMBO_EVENT = 0x275,
	CMD_SELECT_COUNTRY = 0x276,
	CMD_SHOW_COUNTRYLIST = 0x277,
	CMD_SHOW_CHAT_INPUTMODE = 0x278,
	CMD_CHAT_INPUT_COMBO = 0x279,
	CMD_TEST_MIC = 0x27A,
	CMD_USE_VOICECHAT = 0x27B,
	CMD_SCREEN_TEST = 0x27C,
	CMD_HELPBOX_HELP = 0x27D,
	CMD_HELPBOX_GRADE = 0x27E,
	CMD_INPUT_EDIT = 0x27F,
	CMD_INPUT_EDIT_MSG = 0x280,
	CMD_EQUIP_FUNCTION = 0x281,
	CMD_INVITE = 0x282,
	CMD_ACCEPT = 0x283,
	CMD_MULTI_BUY_REQ = 0x284,
	CMD_MULTI_BUY_ACK = 0x285,
	CMD_MULTI_BUY_SHOW_SUPPLYBOX = 0x286,
	CMD_BUY_DAYS_OK = 0x287,
	CMD_SELL_DAYS_OK = 0x288,
	CMD_GS_SHOW_MAIN = 0x289,
	CMD_GS_NPC_TALK = 0x28A,
	CMD_GS_NPC_ANIMATION = 0x28B,
	CMD_GS_MONEY_REFRESH = 0x28C,
	CMD_GS_NX_CHARGE = 0x28D,
	CMD_STARTMENU_INBOX = 0x28E,
	CMD_STARTMENU_NX = 0x28F,
	CMD_STARTMENU_CODE = 0x290,
	CMD_STARTMENU_5SHOT = 0x291,
	CMD_STARTMENU_SEED = 0x292,
	CMD_STARTMENU_CALENDAR = 0x293,
	CMD_STARTMENU_VIDEO = 0x294,
	CMD_STARTMENU_REPORT = 0x295,
	CMD_STARTMENU_TUTORIAL = 0x296,
	CMD_STARTMENU_HELP = 0x297,
	CMD_STARTMENU_OPTION = 0x298,
	CMD_STARTMENU_DAILYATTENDANCE = 0x299,
	CMD_STARTMENU_RECOMMEND = 0x29A,
	CMD_STARTMENU_ROULETTE = 0x29B,
	CMD_STARTMENU_SA_Migration = 0x29C,
	CMD_STARTMENU_RANK = 0x29D,
	CMD_STARTMENU_COMBAT_MARBLE = 0x29E,
	CMD_STARTMENU_EXIT = 0x29F,
	CMD_STARTMENU_CLOSE = 0x2A0,
	CMD_VIDEO_OK = 0x2A1,
	CMD_VIDEO_CLOSE = 0x2A2,
	CMD_LOBBYFILTER_RED = 0x2A3,
	CMD_LOBBYFILTER_PASS = 0x2A4,
	CMD_ATTEMPT_CHAT_ACK = 0x2A5,
	CMD_CLOSE_CHAT = 0x2A6,
	CMD_SHOW_COMBATFRIEND = 0x2A7,
	CMD_SHOW_CHAT = 0x2A8,
	CMD_SHOW_CHAT_USER_UP = 0x2A9,
	CMD_SHOW_CHAT_USER_DOWN = 0x2AA,
	CMD_ADD_GROUP = 0x2AB,
	CMD_INVITE_FRIEND = 0x2AC,
	CMD_CHAT_USER = 0x2AD,
	CMD_BLOCK_USER = 0x2AE,
	CMD_DELETE_USER = 0x2AF,
	CMD_SEND_NOTE = 0x2B0,
	CMD_MOVE_GROUP = 0x2B1,
	CMD_SEND_CHATTING_MSG = 0x2B2,
	CMD_CLOSE_MESSENGER = 0x2B3,
	CMD_INVITE_GAME = 0x2B4,
	CMD_PARTICIPATE_GAME = 0x2B5,
	CMD_PARTICIPATE_CHANNEL = 0x2B6,
	CMD_GROUP_DELETE = 0x2B7,
	CMD_GROUP_NAMECHANGE = 0x2B8,
	CMD_EDIT_ROOMNAME = 0x2B9,
	CMD_SET_ROOMNAME = 0x2BA,
	CMD_GS_RUN_CHOICE_ITEM_CHEST = 0x2BB,
	CMD_OVER_END = 0x2BC,
};
enum ELTDPFillMode
{
	DRAWPRIM_WIRE = 0x0,
	DRAWPRIM_FILL = 0x1,
};
enum eDashGageState
{
	SP_INC = 0x0,
	SP_DEC = 0x1,
	SP_STOP = 0x2,
	SP_ETC = 0x3,
};
enum eUserTooltipMenu
{
	eAddFriend = 0x0,
	eShowCharInfo = 0x1,
	eChangeMaster = 0x2,
	eKickUser = 0x3,
	eInviteClan = 0x4,
	eNameCopy = 0x5,
	eGM_3rdView = 0x6,
	eGM_1stView = 0x7,
	eGM_Kick = 0x8,
	eGM_Ban = 0x9,
	eGM_Punish = 0xA,
	eGM_unPunish = 0xB,
	eGM_HWban = 0xC,
	eGM_Restrict = 0xD,
	eGM_unRestrict = 0xE,
	eGM_ScreenShotview = 0xF,
	eBlock = 0x10,
	eUnBlock = 0x11,
	eMoveChannel = 0x12,
	eMessengerChat = 0x13,
	eMessengerInvite = 0x14,
	eMessengerJoin = 0x15,
	eMessengerBlock = 0x16,
	eMessengerRemove = 0x17,
	eMessengerSendNote = 0x18,
	eGroupNameChange = 0x19,
	eGroupDelete = 0x1A,
	eRemoveMGM = 0x1B,
	eUserTooltipMenu_Max = 0x1C,
};
enum CCBAPlayerMgr__FreeCameraMode
{
	FREECAM_NONE = 0x0,
	FREECAM_NORMAL = 0x1,
	FREECAM_STATIC = 0x2,
	FREECAM_INSTANCE = 0x3,
};
enum CCBAPlayerMgr__DeadCameraMode
{
	DEADCAM_NONE = 0x0,
	DEADCAM_FREELOOK = 0x1,
	DEADCAM_CHASE = 0x2,
	DEADCAM_CHASE_1ST = 0x3,
	DEADCAM_FIRST_CHASE = 0x4,
};
enum CCBAPlayerMgr__ObserverMode
{
	OBSERVERMODE_NONE = 0x0,
	OBSERVERMODE_FREELOOK = 0x1,
	OBSERVERMODE_1ST = 0x2,
	OBSERVERMODE_3RD = 0x3,
};
enum SFX_List
{
	sfx_general = 0u,  // General FX (unused?)
	sfx_poly_grid = 1u,  // CPolyGridFX
	sfx_particle_trail = 2u,  // CParticleTrailFX
	sfx_particle_system = 3u,  // CParticleSystemFX
	sfx_particle_shower = 4u,  // CParticleShowerFX
	sfx_tracer = 5u,  // CTracerFX
	sfx_weapon = 6u,  // CWeaponFX
	sfx_dynamic_light = 7u,  // CDynamicLightFX
	sfx_particle_trail_segment = 8u,  // CParticleTrailSegmentFX
	sfx_smoke = 9u,  // CSmokeFX
	sfx_bullet_trail = 10u, // CBulletTrailFX
	sfx_volume_brush = 11u, // CVolumeBrushFX
	sfx_shell_casing = 12u, // CShellCasingFX
	sfx_camera = 13u, // CCameraFX
	sfx_particle_explosion = 14u, // CParticleExplosionFX
	sfx_base_scale = 15u, // CBaseScaleFX
	sfx_debris = 16u, // CDebrisFX
	sfx_death = 17u, // CDeathFX
	sfx_gib = 18u, // CGibFX
	sfx_projectile = 19u, // CProjectileFX
	sfx_mark = 20u, // CMarkSFX
	sfx_light = 21u, // CLightFX
	sfx_random_sparks = 22u, // CRandomSparksFX
	sfx_pickup_item = 23u, // CPickupItemFX
	sfx_character = 24u, // CCBACharacterFX
	sfx_player_sound = 25u, // CPlayerSoundFX
	sfx_node_lines = 26u, // CNodeLinesFX
	sfx_weather = 27u, // CWeatherFX
	sfx_lightning = 28u, // CLightningFX
	sfx_sprinkles = 29u, // SprinklesFX
	sfx_fire = 30u, // CFireFX
	sfx_lens_flare = 31u, // CLensFlareFX
	sfx_muzzle_flash = 32u, // CMuzzleFlashFX
	sfx_search_light = 33u, // CSearchLightFX
	sfx_polygon_debris = 34u, // CPolygonDebrisFX
	sfx_steam = 35u, // CSteamFX
	sfx_explosion = 36u, // CExplosionFX
	sfx_poly_line = 37u, // CPolyLineFX
	sfx_body = 38u, // CBodyFX
	sfx_laser_trigger = 39u, // CLaserTriggerFX
	sfx_mine = 40u, // CMineFX
	sfx_beam = 41u, // CBeamFX
	sfx_player_vehicle = 42u, // CPlayerVehicleFX
	sfx_sound = 43u, // CSoundFX
	sfx_obj_sprite = 44u, // CObjSpriteFX
	sfx_light_group = 45u, // CLightGroupFXMgr
	sfx_debug_line = 46u, // CDebugLineFX
	sfx_texture = 47u, // CTextureFXMgr
	sfx_snow = 48u, // CSnowFX
	sfx_jump_volume = 49u, // CJumpVolumeFX
	sfx_player_lure = 50u, // PlayerLureFX
	sfx_gadget_target = 51u, // CGadgetTargetFX
	sfx_display_timer = 52u, // DisplayTimer
	sfx_dynamic_occluder_volume = 53u, // CDynamicOccluderVolumeFX
	sfx_scatter = 54u, // CScatterFX
	sfx_trigger = 55u, // CTriggerFX
	sfx_radar_object = 56u, // CRadarObjectFX
	sfx_activate_object = 57u, // CActivateObjectFX
	sfx_doomsday_piece = 58u, // CDoomsdayPieceFX
	sfx_unknown = 59u, // unknown
	sfx_server = 60u, // CServerSFX
	sfx_guard_tower = 61u, // CGuardTowerFX
	sfx_pattern_object = 62u, // CPatternObjectFX
	sfx_weapon_model = 63u, // CHHWeaponModelFX

	sfx_max = 64u  // CSpecialFX - SFX_TOTAL_NUMBER + 1
};
enum class mb_type
{
	ok = 0,
	yes_no = 1,
	three_btn = 2,
	edit = 3,
	none = 4,
	cancel = 5
};
enum mb_button_id_
{
	mb_button_on = 1,
	mb_button_off = 2,
	mb_button_yes = 3,
	mb_button_no = 4,
	mb_button_create = 7,
	mb_button_ok = 8,
	mb_button_cancel = 9,
	mb_button_apply = 10
};
enum mb_input_mode_
{
	mb_input_mode_all = 0,
	mb_input_mode_alpha_numeric = 1 << 0,
	mb_input_mode_alpha_only = 1 << 1,
	mb_input_mode_number_only = 1 << 2,
	mb_input_mode_not_allow_space = 1 << 3
};
enum class mb_msg_sound_type
{
	normal = 0,
	error = 1,
	max = 2
};
struct c_mb_create
{
	/*
	   edit boxes return a pointer to their strings in data
	   yes_no and ok boxes return their passed data untouched
	*/
	using callback_fn = void(__cdecl*)(std::uint32_t result, void* p_data);

	mb_type           m_type = mb_type::ok;
	callback_fn       m_callback;
	callback_fn       m_center_callback;

	void* m_data;
	const wchar_t* m_string;
	std::uint16_t     m_max_chars = 256u;
	std::uint32_t     m_input_mode = mb_input_mode_all;
	bool              m_use_password;
	std::int32_t      m_edit_offset_x;
	std::int32_t      m_edit_offset_y;

	std::int32_t      m_id_title;
	std::int32_t      m_id_button_1 = mb_button_ok;
	std::int32_t      m_id_button_2;
	std::int32_t      m_id_button_3;

	mb_msg_sound_type m_sound_type = mb_msg_sound_type::normal;
	std::uint32_t     m_shutdown_time;
	std::uint32_t     m_text_flag;
	void* m_multi_ctrl;
	std::uint32_t     m_modal = 1u;
};
enum eQuestType
{
	eInvalidQuestType = 0xFFFFFFFF,
	eQuestType_Collect = 0x0,
	eQuestType_ItemUpgrade = 0x1,
	eQuestType_Daily = 0x2,
	eQuestTypeNum = 0x3,
};
enum PlayerSoundId
{
	PSI_INVALID = 0x0,
	PSI_RELOAD = 0x1,
	PSI_RELOAD2 = 0x2,
	PSI_RELOAD3 = 0x3,
	PSI_SELECT = 0x4,
	PSI_DESELECT = 0x5,
	PSI_FIRE = 0x6,
	PSI_DRY_FIRE = 0x7,
	PSI_ALT_FIRE = 0x8,
	PSI_SILENCED_FIRE = 0x9,
	PSI_WEAPON_MISC1 = 0xA,
	PSI_WEAPON_MISC2 = 0xB,
	PSI_WEAPON_MISC3 = 0xC,
	PSI_WEAPON_MISC4 = 0xD,
	PSI_WEAPON_MISC5 = 0xE,
	PSI_JUMP = 0xF,
	PSI_LAND = 0x10,
	PSI_DAMAGE = 0x11,
	PSI_TEAM3D = 0x12,
};
enum GamePlayType
{
	eGamePlayType_Normal = 0x0,
	eGamePlayType_Single = 0x1,
	eGamePlayType_Tutorial = 0x2,
	eGamePlayType_Ladder = 0x3,
	eGamePlayType_Max = 0x4,
};
enum WeaponSlot
{
	MainSlot = 0x0,
	PistolSlot = 0x1,
	MeleeSlot = 0x1,
	GrenadeSlot = 0x2,
	SlotA = 0x3,
	SlotB = 0x4,
	SlotC = 0x5,
	SlotD = 0x6,
	SlotSpecial = 0x7
};
enum NameType
{
	NameType_CharName = 0,
	NameType_ClanName = 1
};
enum SwitchingWorldsState
{
	eSwitchingWorldsStateNone = 0x0,
	eSwitchingWorldsStatePlayerHookup = 0x1,
	eSwitchingWorldsStateWaitForClient = 0x2,
	eSwitchingWorldsStateFinished = 0x3,
};
enum LTSurfaceBlend
{
	LTSURFACEBLEND_ALPHA = 0x0,
	LTSURFACEBLEND_SOLID = 0x1,
	LTSURFACEBLEND_ADD = 0x2,
	LTSURFACEBLEND_MULTIPLY = 0x3,
	LTSURFACEBLEND_MULTIPLY2 = 0x4,
	LTSURFACEBLEND_MASK = 0x5,
	LTSURFACEBLEND_MASKADD = 0x6,
};
enum VolumeEffectInfo_EffectType
{
	kUninitialized = 0x0,
	kDynamicParticles = 0x1,
};
enum VolumeEffectInfo_DynamicParticlePrimitive
{
	kTrilist = 0x0,
	kQuadlist = 0x1,
};
enum VolumeEffectInfo_DynamicParticleLighting
{
	kNone = 0x0,
	kSinglePointNonDirectional = 0x1,
};
enum CHUDXMLRespawnToken__E_RESPAWNTOKEN_STATUS
{
	eRT_None = 0x0,
	eRT_AskingToUse = 0x1,
	eRT_SelectItem = 0x2,
	eRT_Purchase = 0x3,
	eRT_CancelToUse = 0x4,
	eRT_Respawning = 0x5,
	eRT_CantUse = 0x6,
	eRT_EveryoneDied = 0x7,
	eRT_PartyTokenUsed = 0x8,
	eRT_Max = 0x9,
};
enum eHUDRenderLevel
{
	kHUDRenderNone = 0x0,
	kHUDRenderText = 0x1,
	kHUDRenderDead = 0x2,
	kHUDRenderFull = 0x3,
};
enum CBotInfoMgr_BotInfoType
{
	eBotInfo_Object = 0x0,
	eBotInfo_Kills = 0x1,
	eBotInfo_Deaths = 0x2,
	eBotInfo_Alive = 0x3,
	eBotInfo_KillMeCout = 0x4,
	eBotInfo_max = 0x5,
};

enum ScreenSpriteLayer
{
	SPRITELAYER_DEFAULT = 0x0,
	SPRITELAYER_SUBROUTINE_SHAPE = 0x1,
	SPRITELAYER_SUBROUTINE_BUILD = 0x2,
	SPRITELAYER_SUBROUTINE_CONDITION = 0x3,
	SPRITELAYER_ADDITIVE_SHAPE = 0x4,
	SPRITELAYER_ADDITIVE_GLOW = 0x5,
	SPRITELAYER_ADDITIVE_HIGHLIGHT = 0x6,
	SPRITELAYER_PROCEDURAL_SHAPE = 0x7,
	SPRITELAYER_PROCEDURAL_PROGRESS = 0x8,
	SPRITELAYER_PROCEDURAL_HIGHLIGHT = 0x9,
	SPRITELAYER_CURSOR_ADDITIVE = 0xA,
	SPRITELAYER_CURSOR_BACKGROUND = 0xB,
	SPRITELAYER_CURSOR_FOREGROUND = 0xC,
};
enum eKindRadioMsg
{
	eRadioMsg_Report = 0x0,
	eRadioMsg_Answer = 0x1,
	eRadioMsg_Request = 0x2,
	eRadioMsg_Emotion = 0x3,
	eRadioMsg_MaxNum = 0x4,
};
enum ItemType
{
	ITEMTYPE_AR = 0x0,
	ITEMTYPE_SMG = 0x1,
	ITEMTYPE_SR = 0x2,
	ITEMTYPE_MG = 0x3,
	ITEMTYPE_PISTOL = 0x4,
	ITEMTYPE_SG = 0x5,
	ITEMTYPE_THW = 0x6,
	ITEMTYPE_KNIFE = 0x7,
	ITEMTYPE_ROCKET = 0x8,
	ITEMTYPE_FLAME = 0x9,
	ITEMTYPE_CROSSBOW = 0xA,
	ITEMTYPE_HEADGEAR = 0xB,
	ITEMTYPE_FACEATTACH = 0xC,
	ITEMTYPE_FACEMODEL = 0xD,
	ITEMTYPE_CLOTHE = 0xE,
	ITEMTYPE_CLASSKIT = 0xF,
	ITEMTYPE_BACKPACK = 0x10,
	ITEMTYPE_SILENCER = 0x11,
	ITEMTYPE_SIGHT = 0x12,
	ITEMTYPE_MAGAZINE = 0x13,
	ITEMTYPE_GACHAPON = 0x14,
	ITEMTYPE_FUNCTION = 0x15,
	ITEMTYPE_CHARACTER = 0x16,
	ITEMTYPE_PLUS = 0x17,
	ITEMTYPE_SET = 0x18,
	ITEMTYPE_GP_COUPON = 0x19,
	ITEMTYPE_SG_PRIMARY = 0x1A,
	ITEMTYPE_HEARTBEAT = 0x1B,
	ITEMTYPE_NOTITEM = 0x1C,
	ITEMTYPE_SPECIAL = 0x1D,
	ITEMTYPE_SPECIALLIST = 0x1E,
	ITEMTYPE_SERVER_DUMMY = 0x1F,
	ITEMTYPE_COLLECTITEM = 0x20,
	ITEMTYPE_CONVERT = 0x21,
	ITEMTYPE_EVENTITEM = 0x22,
	ITEMTYPE_PERSKILL = 0x23,
	ITEMTYPE_ASSASSIN_WEAPON = 0x24,
	ITEMTYPE_ASSASSIN = 0x25,
	ITEMTYPE_COSMETIC_CHARACTER = 0x26,
	ITEMTYPE_COSMETIC_CHARACTER_WITH_OTHER = 0x27,
	ITEMTYPE_COSMETIC_HEAD = 0x28,
	ITEMTYPE_COSMETIC_FACE = 0x29,
	ITEMTYPE_COSMETIC_VEST = 0x2A,
	ITEMTYPE_COSMETIC_BACKPACK = 0x2B,
	ITEMTYPE_ROULETTE = 0x2C,
	ITEMTYPE_DISCOUNT_COUPON = 0x2D,
	ITEMTYPE_MOD_HAED = 0x2E,
	ITEMTYPE_MOD_FACE = 0x2F,
	ITEMTYPE_MOD_VEST = 0x30,
	ITEMTYPE_BULLET = 0x31,
	ITEMTYPE_MECH_SIGHT = 0x32,
	ITEMTYPE_EXP_COUPON = 0x33,
	ITEMTYPE_MAX_NUM = 0x34,
};
enum eScreenID
{
	SCREEN_ID_NONE = 0x0,
	SCREEN_ID_MAIN = 0x1,
	SCREEN_ID_MULTI = 0x2,
	SCREEN_ID_CHARACTER_SELECT = 0x3,
	SCREEN_ID_HOST = 0x4,
	SCREEN_ID_JOIN_LAN = 0x5,
	SCREEN_ID_WEAPON_SETTING = 0x6,
	SCREEN_ID_LOGIN = 0x7,
	SCREEN_ID_SERVER_SELECT = 0x8,
	SCREEN_ID_CHANNEL_SELECT = 0x9,
	SCREEN_ID_CHARACTER_CREATE = 0xA,
	SCREEN_ID_NICKNAME = 0xB,
	SCREEN_ID_SERVER_JOIN = 0xC,
	SCREEN_ID_SERVER_CREATE = 0xD,
	SCREEN_ID_WAITING_ROOM = 0xE,
	SCREEN_ID_MAP_LIST = 0xF,
	SCREEN_ID_INVENTORY = 0x10,
	SCREEN_ID_GUNSMITH = 0x11,
	SCREEN_ID_CLAN = 0x12,
	SCREEN_ID_QUEST = 0x13,
	SCREEN_ID_GAME_START = 0x14,
	SCREEN_ID_GAME_END = 0x15,
	SCREEN_ID_RESULT = 0x16,
	SCREEN_ID_GAME_OPTION = 0x17,
	SCREEN_ID_MESSENGER = 0x18,
	SCREEN_ID_CHAT = 0x19,
	SCREEN_ID_EMPTY = 0x1A,
	SCREEN_ID_SCREEN_TEST = 0x1B,
	SCREEN_ID_RANK = 0x1C,
	SCREEN_ID_UNASSIGNED = 0x1D,
};
enum ELTTransformType
{
	DRAWPRIM_TRANSFORM_CAMERA = 0x0,
	DRAWPRIM_TRANSFORM_SCREEN = 0x1,
	DRAWPRIM_TRANSFORM_WORLD = 0x2,
	DRAWPRIM_TRANSFORM_ORTHO = 0x3,
};
enum ELTColorOp
{
	DRAWPRIM_NOCOLOROP = 0x0,
	DRAWPRIM_MODULATE = 0x1,
	DRAWPRIM_ADD = 0x2,
	DRAWPRIM_DECAL = 0x3,
	DRAWPRIM_MULTITEXTURE = 0x4,
	DRAWPRIM_ALPHAOP_MODULATE = 0x5,
	DRAWPRIM_COLOROP_ADD = 0x6,
	DRAWPRIM_COLOROP_MODULATE = 0x7,
	DRAWPRIM_COLOROP_MODULATE2X = 0x8,
	DRAWPRIM_COLOROP_MODULATE4X = 0x9,
	DRAWPRIM_COLOROP_MULTIPLYADD = 0xA,
	DRAWPRIM_COLOROP_CHANGE = 0xB,
	DRAWPRIM_ALPHAONLY_FONT = 0xC,
};
enum ELTBlendMode
{
	DRAWPRIM_NOBLEND = 0x0,
	DRAWPRIM_BLEND_ADD = 0x1,
	DRAWPRIM_BLEND_SATURATE = 0x2,
	DRAWPRIM_BLEND_MOD_SRCALPHA = 0x3,
	DRAWPRIM_BLEND_MOD_SRCCOLOR = 0x4,
	DRAWPRIM_BLEND_MOD_DSTCOLOR = 0x5,
	DRAWPRIM_BLEND_MUL_SRCCOL_DSTCOL = 0x6,
	DRAWPRIM_BLEND_MUL_SRCALPHA_ONE = 0x7,
	DRAWPRIM_BLEND_MUL_SRCALPHA = 0x8,
	DRAWPRIM_BLEND_MUL_SRCCOL_ONE = 0x9,
	DRAWPRIM_BLEND_MUL_DSTCOL_ZERO = 0xA,
};
enum ELTZBufferMode
{
	DRAWPRIM_ZRW = 0x0,
	DRAWPRIM_ZRO = 0x1,
	DRAWPRIM_NOZ = 0x2,
};
enum ELTTestMode
{
	DRAWPRIM_NOALPHATEST = 0x0,
	DRAWPRIM_ALPHATEST_LESS = 0x1,
	DRAWPRIM_ALPHATEST_LESSEQUAL = 0x2,
	DRAWPRIM_ALPHATEST_GREATER = 0x3,
	DRAWPRIM_ALPHATEST_GREATEREQUAL = 0x4,
	DRAWPRIM_ALPHATEST_EQUAL = 0x5,
	DRAWPRIM_ALPHATEST_NOTEQUAL = 0x6,
};
enum ELTClipMode
{
	DRAWPRIM_NOCLIP = 0x0,
	DRAWPRIM_FASTCLIP = 0x1,
	DRAWPRIM_FULLCLIP = 0x2,
};
enum ELTDPCullMode
{
	DRAWPRIM_CULL_NONE = 0x0,
	DRAWPRIM_CULL_CCW = 0x1,
	DRAWPRIM_CULL_CW = 0x2,
};
enum ELTDPAddrMode
{
	DRAWPRIM_ADDR_WRAP = 0x0,
	DRAWPRIM_ADDR_MIRROR = 0x1,
	DRAWPRIM_ADDR_CLAMP = 0x2,
	DRAWPRIM_ADDR_BORDER = 0x3,
	DRAWPRIM_ADDR_MIRRORONCE = 0x4,
};

enum ERenStyle_BlendMode
{
	RENDERSTYLE_NOBLEND = 0x0,
	RENDERSTYLE_BLEND_ADD = 0x1,
	RENDERSTYLE_BLEND_SATURATE = 0x2,
	RENDERSTYLE_BLEND_MOD_SRCALPHA = 0x3,
	RENDERSTYLE_BLEND_MOD_SRCCOLOR = 0x4,
	RENDERSTYLE_BLEND_MOD_DSTCOLOR = 0x5,
	RENDERSTYLE_BLEND_MUL_SRCCOL_DSTCOL = 0x6,
	RENDERSTYLE_BLEND_MUL_SRCCOL_ONE = 0x7,
	RENDERSTYLE_BLEND_MUL_SRCALPHA_ZERO = 0x8,
	RENDERSTYLE_BLEND_MUL_SRCALPHA_ONE = 0x9,
	RENDERSTYLE_BLEND_MUL_DSTCOL_ZERO = 0xA,
	RENDERSTYLE_BLENDMODE_TYPE_COUNT = 0xB,
	RENDERSTYLE_BLENDMODE_TYPE_FORCE_32BIT = 0x7FFFFFFF,
};

enum ERenStyle_ZBufferMode
{
	RENDERSTYLE_ZRW = 0x0,
	RENDERSTYLE_ZRO = 0x1,
	RENDERSTYLE_NOZ = 0x2,
	RENDERSTYLE_ZBUFFERMODE_TYPE_COUNT = 0x3,
	RENDERSTYLE_ZBUFFERMODE_TYPE_FORCE_32BIT = 0x7FFFFFFF,
};
enum ERenStyle_CullMode
{
	RENDERSTYLE_CULL_NONE = 0x0,
	RENDERSTYLE_CULL_CCW = 0x1,
	RENDERSTYLE_CULL_CW = 0x2,
	RENDERSTYLE_CULLMODE_TYPE_COUNT = 0x3,
	RENDERSTYLE_CULLMODE_TYPE_FORCE_32BIT = 0x7FFFFFFF,
};
enum ERenStyle_TestMode
{
	RENDERSTYLE_NOALPHATEST = 0x0,
	RENDERSTYLE_ALPHATEST_LESS = 0x1,
	RENDERSTYLE_ALPHATEST_LESSEQUAL = 0x2,
	RENDERSTYLE_ALPHATEST_GREATER = 0x3,
	RENDERSTYLE_ALPHATEST_GREATEREQUAL = 0x4,
	RENDERSTYLE_ALPHATEST_EQUAL = 0x5,
	RENDERSTYLE_ALPHATEST_NOTEQUAL = 0x6,
	RENDERSTYLE_TESTMODE_TYPE_COUNT = 0x7,
	RENDERSTYLE_TESTMODE_TYPE_FORCE_32BIT = 0x7FFFFFFF,
};
enum ERenStyle_FillMode
{
	RENDERSTYLE_WIRE = 0x0,
	RENDERSTYLE_FILL = 0x1,
	RENDERSTYLE_FILLMODE_TYPE_COUNT = 0x2,
	RENDERSTYLE_FILLMODE_TYPE_FORCE_32BIT = 0x7FFFFFFF,
};
enum ERenStyle_TextureParam
{
	RENDERSTYLE_NOTEXTURE = 0x0,
	RENDERSTYLE_USE_TEXTURE1 = 0x1,
	RENDERSTYLE_USE_TEXTURE2 = 0x2,
	RENDERSTYLE_USE_TEXTURE3 = 0x3,
	RENDERSTYLE_USE_TEXTURE4 = 0x4,
	RENDERSTYLE_TEXTUREPARAM_TYPE_COUNT = 0x5,
	RENDERSTYLE_TEXTUREPARAM_TYPE_FORCE_32BIT = 0x7FFFFFFF,
};
enum ERenStyle_ColorOp
{
	RENDERSTYLE_COLOROP_DISABLE = 0x0,
	RENDERSTYLE_COLOROP_SELECTARG1 = 0x1,
	RENDERSTYLE_COLOROP_SELECTARG2 = 0x2,
	RENDERSTYLE_COLOROP_MODULATE = 0x3,
	RENDERSTYLE_COLOROP_MODULATE2X = 0x4,
	RENDERSTYLE_COLOROP_MODULATEALPHA = 0x5,
	RENDERSTYLE_COLOROP_MODULATETFACTOR = 0x6,
	RENDERSTYLE_COLOROP_ADD = 0x7,
	RENDERSTYLE_COLOROP_DOTPRODUCT3 = 0x8,
	RENDERSTYLE_COLOROP_BUMPENVMAP = 0x9,
	RENDERSTYLE_COLOROP_BUMPENVMAPLUM = 0xA,
	RENDERSTYLE_COLOROP_ADDSIGNED = 0xB,
	RENDERSTYLE_COLOROP_ADDSIGNED2X = 0xC,
	RENDERSTYLE_COLOROP_SUBTRACT = 0xD,
	RENDERSTYLE_COLOROP_ADDMODALPHA = 0xE,
	RENDERSTYLE_COLOROP_ADDMODINVALPHA = 0xF,
	RENDERSTYLE_COLOROP_MODULATETEXALPHA = 0x10,
	RENDERSTYLE_COLOROP_TYPE_COUNT = 0x11,
	RENDERSTYLE_COLOROP_TYPE_FORCE_32BIT = 0x7FFFFFFF,
};
enum ERenStyle_ColorArg
{
	RENDERSTYLE_COLORARG_CURRENT = 0x0,
	RENDERSTYLE_COLORARG_DIFFUSE = 0x1,
	RENDERSTYLE_COLORARG_TEXTURE = 0x2,
	RENDERSTYLE_COLORARG_TFACTOR = 0x3,
	RENDERSTYLE_COLORARG_TYPE_COUNT = 0x4,
	RENDERSTYLE_COLORARG_TYPE_FORCE_32BIT = 0x7FFFFFFF,
};
enum ERenStyle_AlphaOp
{
	RENDERSTYLE_ALPHAOP_DISABLE = 0x0,
	RENDERSTYLE_ALPHAOP_SELECTARG1 = 0x1,
	RENDERSTYLE_ALPHAOP_SELECTARG2 = 0x2,
	RENDERSTYLE_ALPHAOP_MODULATE = 0x3,
	RENDERSTYLE_ALPHAOP_MODULATEALPHA = 0x4,
	RENDERSTYLE_ALPHAOP_MODULATETFACTOR = 0x5,
	RENDERSTYLE_ALPHAOP_ADD = 0x6,
	RENDERSTYLE_ALPHAOP_ADDSIGNED = 0x7,
	RENDERSTYLE_ALPHAOP_ADDSIGNED2X = 0x8,
	RENDERSTYLE_ALPHAOP_SUBTRACT = 0x9,
	RENDERSTYLE_ALPHAOP_MODULATETEXALPHA = 0xA,
	RENDERSTYLE_ALPHAOP_TYPE_COUNT = 0xB,
	RENDERSTYLE_ALPHAOP_TYPE_FORCE_32BIT = 0x7FFFFFFF,
};
enum ERenStyle_AlphaArg
{
	RENDERSTYLE_ALPHAARG_CURRENT = 0x0,
	RENDERSTYLE_ALPHAARG_DIFFUSE = 0x1,
	RENDERSTYLE_ALPHAARG_TEXTURE = 0x2,
	RENDERSTYLE_ALPHAARG_TFACTOR = 0x3,
	RENDERSTYLE_ALPHAARG_TYPE_COUNT = 0x4,
	RENDERSTYLE_ALPHAARG_TYPE_FORCE_32BIT = 0x7FFFFFFF,
};
enum ERenStyle_UV_Source
{
	RENDERSTYLE_UVFROM_MODELDATA_UVSET1 = 0x0,
	RENDERSTYLE_UVFROM_MODELDATA_UVSET2 = 0x1,
	RENDERSTYLE_UVFROM_MODELDATA_UVSET3 = 0x2,
	RENDERSTYLE_UVFROM_MODELDATA_UVSET4 = 0x3,
	RENDERSTYLE_UVFROM_CAMERASPACENORMAL = 0x4,
	RENDERSTYLE_UVFROM_CAMERASPACEPOSITION = 0x5,
	RENDERSTYLE_UVFROM_CAMERASPACEREFLTVECT = 0x6,
	RENDERSTYLE_UVFROM_WORLDSPACENORMAL = 0x7,
	RENDERSTYLE_UVFROM_WORLDSPACEPOSITION = 0x8,
	RENDERSTYLE_UVFROM_WORLDSPACEREFLTVECT = 0x9,
	RENDERSTYLE_UVSOURCE_TYPE_COUNT = 0xA,
	RENDERSTYLE_UVSOURCE_TYPE_FORCE_32BIT = 0x7FFFFFFF,
};
enum ERenStyle_UV_Address
{
	RENDERSTYLE_UVADDR_WRAP = 0x0,
	RENDERSTYLE_UVADDR_CLAMP = 0x1,
	RENDERSTYLE_UVADDR_MIRROR = 0x2,
	RENDERSTYLE_UVADDR_MIRRORONCE = 0x3,
	RENDERSTYLE_UVADDRESS_TYPE_COUNT = 0x4,
	RENDERSTYLE_UVADDRESS_TYPE_FORCE_32BIT = 0x7FFFFFFF,
};
enum ERenStyle_TexFilter
{
	RENDERSTYLE_TEXFILTER_POINT = 0x0,
	RENDERSTYLE_TEXFILTER_BILINEAR = 0x1,
	RENDERSTYLE_TEXFILTER_TRILINEAR = 0x2,
	RENDERSTYLE_TEXFILTER_ANISOTROPIC = 0x3,
	RENDERSTYLE_TEXFILTER_POINT_PTMIP = 0x4,
	RENDERSTYLE_TEXFILTER_TYPE_COUNT = 0x5,
	RENDERSTYLE_TEXFILTER_TYPE_FORCE_32BIT = 0x7FFFFFFF,
};
enum LTShaderDeviceState_LTMatrixType
{
	MATRIXTYPE_WORLD0 = 0x0,
	MATRIXTYPE_WORLD1 = 0x1,
	MATRIXTYPE_WORLD2 = 0x2,
	MATRIXTYPE_WORLD3 = 0x3,
	MATRIXTYPE_VIEW = 0x4,
	MATRIXTYPE_PROJECTION = 0x5,
	MATRIXTYPE_VIEWPROJECTION = 0x6,
	MATRIXTYPE_TEXTURE0 = 0x7,
	MATRIXTYPE_TEXTURE1 = 0x8,
	MATRIXTYPE_TEXTURE2 = 0x9,
	MATRIXTYPE_TEXTURE3 = 0xA,
	MATRIXTYPE_TEXTURE4 = 0xB,
	MATRIXTYPE_TEXTURE5 = 0xC,
	MATRIXTYPE_TEXTURE6 = 0xD,
	MATRIXTYPE_TEXTURE7 = 0xE,
};
enum LTShaderDeviceState_LTLightType
{
	LIGHTTYPE_POINT = 0x0,
	LIGHTTYPE_SPOT = 0x1,
	LIGHTTYPE_DIRECTIONAL = 0x2,
};
