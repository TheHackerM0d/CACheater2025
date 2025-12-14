class HLTLINE_tq;
class HLTFONT_tq;
class HCONSOLEVAR_tq;
class HSURFACE_tq;
class HLTSOUND_tq;
class VolumeEffectInfo;
class LTVersionInfoExt_tq;
class LTPerformanceInfo_tq;
class LTObjRefq;
class LTLinkq;
class CheapLTLinkq;
class LT_LINEFq;
class LT_LINEGq;
class LT_VERTGTq;

struct FourFloatColor
{
	float r;
	float g;
	float b;
	float a;
};
struct LTShaderDeviceState_LTLightDesc
{
	LTShaderDeviceState_LTLightType m_LightType;
	bool m_Active;
	LTRGB m_Diffuse;
	LTRGB m_Specular;
	LTRGB m_Ambient;
	TVector3<float> m_Position;
	TVector3<float> m_Direction;
	float m_Range;
	float m_Falloff;
	float m_Atten0;
	float m_Atten1;
	float m_Atten2;
	float m_Theta;
	float m_Phi;
};
struct LTPixelShader;
struct /*VFT*/ LTPixelShader_vtbl
{
	bool(__thiscall* IsValidShader)(LTPixelShader* qthis);
	bool(__thiscall* GetConstant)(LTPixelShader* qthis, unsigned int, float*, float*, float*, float*);
	bool(__thiscall* SetConstant)(LTPixelShader* qthis, unsigned int, const LTMatrix*);
	bool(__thiscall* SetConstant2)(LTPixelShader* qthis, unsigned int, float, float, float, float);
	float* (__thiscall* GetConstants)(LTPixelShader* qthis);
};

struct LTPixelShader
{
	LTPixelShader_vtbl* __vftable /*VFT*/;
	int m_ShaderID;
	char m_FileName[260];
	LTPixelShader* m_pNext;
};

struct LTShaderDeviceState_LTCameraDesc
{
	TVector3<float> m_Position;
	LTRotation m_Rotation;
	float m_xFov;
	float m_yFov;
};

const struct LTShaderDeviceState;
struct /*VFT*/ LTShaderDeviceState_vtbl
{
	bool(__thiscall* GetMatrix)(LTShaderDeviceState* pthis, LTShaderDeviceState_LTMatrixType lol, bool, LTMatrix*);
	bool(__thiscall* GetLight)(LTShaderDeviceState* pthis, unsigned int, LTShaderDeviceState_LTLightDesc*);
	bool(__thiscall* GetCamera)(LTShaderDeviceState* pthis, LTShaderDeviceState_LTCameraDesc*);
};

const struct LTShaderDeviceState
{
	LTShaderDeviceState_vtbl* __vftable /*VFT*/;
};

const struct LightingMaterial
{
	FourFloatColor Ambient;
	FourFloatColor Diffuse;
	FourFloatColor Emissive;
	FourFloatColor Specular;
	float SpecularPower;
};
struct TextureStageOps
{
	ERenStyle_TextureParam TextureParam;
	ERenStyle_ColorOp ColorOp;
	ERenStyle_ColorArg ColorArg1;
	ERenStyle_ColorArg ColorArg2;
	ERenStyle_AlphaOp AlphaOp;
	ERenStyle_AlphaArg AlphaArg1;
	ERenStyle_AlphaArg AlphaArg2;
	ERenStyle_UV_Source UVSource;
	ERenStyle_UV_Address UAddress;
	ERenStyle_UV_Address VAddress;
	ERenStyle_TexFilter TexFilter;
	bool UVTransform_Enable;
	float UVTransform_Matrix[16];
	bool ProjectTexCoord;
	unsigned int TexCoordCount;
};

const struct RenderPassOp
{
	TextureStageOps TextureStages[4];
	ERenStyle_BlendMode BlendMode;
	ERenStyle_ZBufferMode ZBufferMode;
	ERenStyle_CullMode CullMode;
	unsigned int TextureFactor;
	unsigned int AlphaRef;
	bool DynamicLight;
	ERenStyle_TestMode ZBufferTestMode;
	ERenStyle_TestMode AlphaTestMode;
	ERenStyle_FillMode FillMode;
	bool bUseBumpEnvMap;
	unsigned int BumpEnvMapStage;
	float fBumpEnvMap_Scale;
	float fBumpEnvMap_Offset;
};
const struct RSD3DOptions
{
	bool bUseEffectShader;
	int EffectShaderID;
};
const struct RSD3DRenderPass
{
	bool bUseVertexShader;
	int VertexShaderID;
	bool bUsePixelShader;
	int PixelShaderID;
};
struct ILTStream;

struct /*VFT*/ ILTStream_vtbl
{
	void(__thiscall * qILTStream)(ILTStream* qthis);
	void(__thiscall* Release)(ILTStream* qthis);
	unsigned int(__thiscall* Read)(ILTStream* qthis, void*, unsigned int);
	unsigned int(__thiscall* ReadString)(ILTStream* qthis, char*, unsigned int);
	unsigned int(__thiscall* ReadWString)(ILTStream* qthis, wchar_t*, unsigned int);
	unsigned int(__thiscall* ErrorStatus)(ILTStream* qthis);
	unsigned int(__thiscall* SeekTo)(ILTStream* qthis, unsigned int);
	unsigned int(__thiscall* GetPos)(ILTStream* qthis, unsigned int*);
	unsigned int(__thiscall* GetLen)(ILTStream* qthis, unsigned int*);
	unsigned int(__thiscall* WriteStream)(ILTStream* qthis, ILTStream*, unsigned int, unsigned int);
	unsigned int(__thiscall* Write)(ILTStream* qthis, const void*, unsigned int);
	unsigned int(__thiscall* WriteString)(ILTStream* qthis, const char*);
	unsigned int(__thiscall* WriteWString)(ILTStream* qthis, const wchar_t*);
};

struct ILTStream
{
	ILTStream_vtbl* __vftable /*VFT*/;
};

struct CRenderStyle;
struct /*VFT*/ CRenderStyle_vtbl
{
	void(__thiscall * tesqd)(CRenderStyle* pthis);
	bool(__thiscall* SetLightingMaterial)(CRenderStyle* pthis, const LightingMaterial*);
	bool(__thiscall* GetLightingMaterial)(CRenderStyle* pthis, LightingMaterial*);
	bool(__thiscall* AddRenderPass)(CRenderStyle* pthis, const RenderPassOp*);
	bool(__thiscall* RemoveRenderPass)(CRenderStyle* pthis, unsigned int);
	bool(__thiscall* SetRenderPass)(CRenderStyle* pthis, unsigned int, const RenderPassOp*);
	bool(__thiscall* GetRenderPass)(CRenderStyle* pthis, unsigned int, RenderPassOp*);
	unsigned int(__thiscall* GetRenderPassCount)(CRenderStyle* pthis);
	bool(__thiscall* SetDirect3D_Options)(CRenderStyle* pthis, const RSD3DOptions*);
	bool(__thiscall* GetDirect3D_Options)(CRenderStyle* pthis, RSD3DOptions*);
	bool(__thiscall* SetRenderPass_D3DOptions)(CRenderStyle* pthis, unsigned int, const RSD3DRenderPass*);
	bool(__thiscall* GetRenderPass_D3DOptions)(CRenderStyle* pthis, unsigned int, RSD3DRenderPass*);
	bool(__thiscall* Load_LTBData)(CRenderStyle* pthis, ILTStream*);
	bool(__thiscall* Compile)(CRenderStyle* pthis);
	void(__thiscall* SetDefaults)(CRenderStyle* pthis);
	bool(__thiscall* CopyRenderStyle)(CRenderStyle* pthis, const CRenderStyle*);
	bool(__thiscall* IsSupportedOnDevice)(CRenderStyle* pthis);
	unsigned int(__thiscall* GetRefCount)(CRenderStyle* pthis);
	unsigned int(__thiscall* IncRefCount)(CRenderStyle* pthis);
	unsigned int(__thiscall* DecRefCount)(CRenderStyle* pthis);
};

struct CRenderStyle
{
	CRenderStyle_vtbl* __vftable /*VFT*/;
	unsigned int m_iRefCnt;
	char* m_pFilename;
};
struct LTVertexShader;
struct /*VFT*/ LTVertexShader_vtbl
{
	bool(__thiscall* IsValidShader)(LTVertexShader* pthis);
	bool(__thiscall* GetConstant)(LTVertexShader* pthis, unsigned int, float*, float*, float*, float*);
	bool(__thiscall* SetConstant)(LTVertexShader* pthis, unsigned int, const LTMatrix*);
	bool(__thiscall* SetConstant1)(LTVertexShader* pthis, unsigned int, float, float, float, float);
	float* (__thiscall* GetConstants)(LTVertexShader* pthis);
};

struct LTVertexShader
{
	LTVertexShader_vtbl* __vftable /*VFT*/;
	int m_ShaderID;
	char m_FileName[260];
	LTVertexShader* m_pNext;
};

struct CConsolePrintData
{
	LTRGB m_Color;
	int m_nFilterLevel;
	const char* m_pMessage;
};

class HPOLYq
{
public:
	unsigned int m_nPolyIndex;
	unsigned int m_nWorldIndex;
};
struct LTRectq
{
	int left;
	int top;
	int right;
	int bottom;
};
struct DeviceInputq
{
	unsigned int m_DeviceType;
	char m_DeviceName[128];
	unsigned int m_ControlType;
	char m_ControlName[64];
	unsigned __int16 m_ControlCode;
	unsigned int m_nObjectId;
	unsigned int m_InputValue;
}; struct LTIntPtq
{
	int x;
	int y;
}; struct SkyDef
{
	D3DXVECTOR3 m_Min;
	D3DXVECTOR3 m_Max;
	D3DXVECTOR3 m_ViewMin;
	D3DXVECTOR3 m_ViewMax;
};
struct LTLinePtq
{
	D3DXVECTOR3 m_Pos;
	float r;
	float g;
	float b;
	float a;
};
struct PGColor
{
	float x;
	float y;
	float z;
	float a;
};

struct LT_VERTFq
{
	float x;
	float y;
	float z;
};

struct DRAWPRIM_D3DTRANS
{
	float x;
	float y;
	float z;
	float rhw;
	unsigned int rgba;
};
struct DRAWPRIM_D3DTRANS_TEX
{
	float x;
	float y;
	float z;
	float rhw;
	unsigned int rgba;
	float u;
	float v;
};
struct DRAWPRIM_D3DTRANS_TEX2
{
	float x;
	float y;
	float z;
	float rhw;
	unsigned int rgba;
	float u;
	float v;
	float u2;
	float v2;
};

class LT_VERTFTq
{
public:
	float x;
	float y;
	float z;
	float u;
	float v;
};

class LT_VERTRGBAq
{
public:
	char b;
	char g;
	char r;
	char a;
};

class LT_VERTGq
{
public:
	float x;
	float y;
	float z;
	LT_VERTRGBAq rgba;
};
class LT_VERTGTq
{
public:
	float x;
	float y;
	float z;
	LT_VERTRGBAq rgba;
	float u;
	float v;
};


class LT_POLYGT3q
{
public:
	LT_VERTGTq verts[3];
};
class LT_POLYFT3q
{
public:
	LT_VERTFTq verts[3];
	LT_VERTRGBAq rgba;
};
class LT_POLYG3q
{
public:
	LT_VERTGq verts[3];
};
class LT_POLYF3q
{
public:
	LT_VERTFq verts[3];
	LT_VERTRGBAq rgba;
};
class LT_POLYFT4q
{
	LT_VERTFTq verts[4];
	LT_VERTRGBAq rgba;
};

class LT_POLYG4q
{
	LT_VERTGq verts[4];
};
class LT_POLYF4q
{
	LT_VERTFq verts[4];
	LT_VERTRGBAq rgba;
};

class LT_LINEGTq
{
public:
	LT_VERTGTq verts[2];
};


class LT_LINEFTq
{
	LT_VERTFTq verts[2];
	LT_VERTRGBAq rgba;
};



class LT_LINEGq
{
public:
	LT_VERTGq verts[2];
};

class LT_LINEFq
{
public:
	LT_VERTFq verts[2];
	LT_VERTRGBAq rgba;
};
class CheapLTLinkq
{
public:
	LTLinkq* m_pPrev;
	LTLinkq* m_pNext;
};
class LTLinkq
{
public:
	CheapLTLinkq baseclass_0;
	void* m_pData;
};


class ILTObjRefReceiverq
{
	class ILTObjRefReceiverq_vtbl* __vftable;
};


struct /*VFT*/ LTObjRef_vtbl
{
	void(__thiscall* LTObjRefq1)(LTObjRefq* pthis);
	void(__thiscall* OnObjDelete)(LTObjRefq* pthis);
	void(__thiscall* SetReceiver)(LTObjRefq* pthis, ILTObjRefReceiverq*);
	ILTObjRefReceiverq* (__thiscall* GetReceiver)(LTObjRefq* pthis);
};

class LTObjRefq
{
public:
	LTObjRef_vtbl* __vftable; //0x0000
	LTLinkq baseclass_4;
};

struct GameAction
{
	int nActionCode;
	char strActionName[30];
	float nRangeLow;
	float nRangeHigh;
	GameAction* pNext;
};
struct UdpPacketSaver_unsigned_char
{
	char m_LastSentValue;
	int m_nUnchangedTickCount;
	int m_nNextSendTickCount;
};

struct DeviceBinding
{
	char strDeviceName[100];
	char strTriggerName[100];
	char strRealName[100];
	unsigned int m_nObjectId;
	float nScale;
	float nRangeScaleMin;
	float nRangeScaleMax;
	float nRangeScalePreCenterOffset;
	GameAction* pActionHead;
	DeviceBinding* pNext;
};
struct DeviceObject
{
	unsigned int m_DeviceType;
	char m_DeviceName[128];
	unsigned int m_ObjectType;
	char m_ObjectName[64];
	unsigned int m_nObjectId;
	float m_RangeLow;
	float m_RangeHigh;
	DeviceObject* m_pNext;
};



struct ModelHookData
{
	int* m_hObject;
	unsigned int m_HookFlags;
	unsigned int m_ObjectFlags;
	D3DXVECTOR3 m_LightAdd;
	D3DXVECTOR3 m_ObjectColor;
};
struct LTGraphicsCaps
{
	unsigned int VertexShaderVersion;
	unsigned int PixelShaderVersion;
};


struct stPreLoadListItem
{
	char szFileName[260];
	int nFileType;
};

struct LTLineq
{
	LTLinePtq m_Points[2];
};


struct LTWarpPtq
{
	float source_x;
	float source_y;
	float dest_x;
	float dest_y;
};
struct LTCounterq
{
	unsigned int m_Data[4];
};

struct LTFloatPtq
{
	float x;
	float y;
};



struct LTParticle
{
	D3DXVECTOR3 m_Pos;
	D3DXVECTOR3 m_Velocity;
	float m_Size;
	D3DXVECTOR3 m_Color;
	float m_Alpha;
	float m_fAngle;
	float m_fAngularVelocity;
	float m_Lifetime;
	float m_TotalLifetime;
	unsigned int m_nUserData;
	LTParticle* m_pNext;
	LTParticle* m_pPrev;
};







class LT_POLYGT4q
{
public:
	LT_VERTGTq verts[4];
};


class LTPoly_GT4q
{
	LT_POLYGT4q baseclass0;
};




class IClientShellStub;
class IClientShell;

struct IXignCodeInstance_vtbl
{
	void(__thiscall* Probe)(const void*, unsigned int);
	void(__thiscall* SendProbeResponse)(void(__stdcall*)(const void*, unsigned int));
};
struct IXignCodeInstance
{
	IXignCodeInstance_vtbl* __vftable /*VFT*/;
};
struct CWSInterface;
struct CWSInterface_vtbl
{
	void(__thiscall* Crypt)(CWSInterface* pthis, char*, int);
	void(__thiscall* Decrypt)(CWSInterface* pthis, char*, int);
	bool(__thiscall* GetHWID)(CWSInterface* pthis, char*, int);
	bool(__thiscall* GetHWIDForNGS)(CWSInterface* pthis, char*, int);
	void (*Log)(CWSInterface* pthis, const char*, ...);
};

struct CWSInterface
{
	CWSInterface_vtbl* __vftable /*VFT*/;
};
struct LTTechniqueInfo
{
	char szName[128];
	int nPasses;
};

struct LTEffectShader;
struct /*VFT*/ LTEffectShader_vtbl
{
	unsigned int(__thiscall* SetBool)(LTEffectShader* pthis, const char*, unsigned int);
	unsigned int(__thiscall* SetBoolArray)(LTEffectShader* pthis, const char*, unsigned int*, int);
	unsigned int(__thiscall* SetFloat)(LTEffectShader* pthis, const char*, float);
	unsigned int(__thiscall* SetFloatArray)(LTEffectShader* pthis, const char*, float*, int);
	unsigned int(__thiscall* SetInt)(LTEffectShader* pthis, const char*, int);
	unsigned int(__thiscall* SetIntArray)(LTEffectShader* pthis, const char*, int*, int);
	unsigned int(__thiscall* SetMatrix)(LTEffectShader* pthis, const char*, LTMatrix*);
	unsigned int(__thiscall* SetMatrixArray)(LTEffectShader* pthis, const char*, LTMatrix*, int);
	unsigned int(__thiscall* SetMatrixTranspose)(LTEffectShader* pthis, const char*, LTMatrix*);
	unsigned int(__thiscall* SetMatrixTransposeArray)(LTEffectShader* pthis, const char*, LTMatrix*, int);
	unsigned int(__thiscall* SetString)(LTEffectShader* pthis, const char*, const char*);
	unsigned int(__thiscall* SetTechnique)(LTEffectShader* pthis, const char*);
	unsigned int(__thiscall* ValidateTechnique)(LTEffectShader* pthis, const char*);
	unsigned int(__thiscall* FindFirstValidTechnique)(LTEffectShader* pthis, LTTechniqueInfo*);
	unsigned int(__thiscall* SetTexture)(LTEffectShader* pthis, const char*, struct SharedTexture*);
	unsigned int(__thiscall* SetTextureRT)(LTEffectShader* pthis, const char*, unsigned int);
	unsigned int(__thiscall* SetVector)(LTEffectShader* pthis, const char*, float*);
	unsigned int(__thiscall* SetVectorArray)(LTEffectShader* pthis, const char*, float*, int);
};

struct LTEffectShader
{
	LTEffectShader_vtbl* __vftable /*VFT*/;
	int m_ShaderID;
	char m_FileName[260];
	LTEffectShader* m_pNext;
};