class cILTDrawPrim
{
public:
	char CharSizer1[16184]; //0x0000
	D3DVIEWPORT9 ViewPort; //0x3F38
	D3DXMATRIX World[3]; //0x3F50
};
class cILTDrawPrim2
{
public:
	char unknown1[16184]; //0x0000
	D3DVIEWPORT9 ViewPort; //0x3F38
	D3DXMATRIX World; //0x3F50
	D3DXMATRIX View; //0x3F90
	D3DXMATRIX Projection; //0x3FD0
};//Size=0x4010



class CGenDrawPrim
{
public:
	ILTDrawPrim baseclass_0;
	LTObject* m_pCamera;
	SharedTexture* m_pTexture;
	SharedTexture* m_hAlphaTexture;
	ELTTransformType m_eTransType;
	ELTColorOp m_ColorOp;
	ELTBlendMode m_BlendMode;
	ELTZBufferMode m_eZBufferMode;
	ELTTestMode m_eTestMode;
	ELTClipMode m_eClipType;
	ELTDPFillMode m_eFillMode;
	ELTDPCullMode m_eCullMode;
	ELTDPAddrMode m_eAddrMode;
	bool m_bReallyClose;
	bool m_bFogEnable;
	unsigned int m_nEffectShaderID;
	unsigned int m_nEffectShaderPass;
};

class CD3DDrawPrim 
{
public:
	CGenDrawPrim baseclass_0;
	LT_VERTGTq m_VertBufGT[128];
	LT_VERTGq m_VertBufG[128];
	DRAWPRIM_D3DTRANS m_VertTransBuf[128];
	DRAWPRIM_D3DTRANS_TEX m_VertTransBufT[128];
	DRAWPRIM_D3DTRANS_TEX2 m_VertTransBufT2[128];
	unsigned int m_PrevColorOp;
	unsigned int m_PrevAlphaBlendEnable;
	unsigned int m_PrevSrcBlend;
	unsigned int m_PrevDstBlend;
	unsigned int m_PrevZEnable;
	unsigned int m_PrevZWriteEnable;
	unsigned int m_PrevAlphaTestEnable;
	unsigned int m_PrevAlphaTestFunc;
	unsigned int m_PrevFillMode;
	unsigned int m_PrevClipMode;
	unsigned int m_PrevCullMode;
	unsigned int m_PrevAddrModeU;
	unsigned int m_PrevAddrModeV;
	unsigned int m_PrevAddrModeW;
	unsigned int m_PrevFogMode;
	_D3DMATRIX m_PrevTransView;
	_D3DMATRIX m_PrevTransProj;
	_D3DVIEWPORT9 m_PrevViewport;
	_D3DVIEWPORT9 m_SavedViewport;
	bool m_bPrevReallyClose;
	bool m_bResetViewport;
	unsigned int m_nBlockCount;
	bool m_bIsScreenTransform;
	_D3DVIEWPORT9 m_kCachedViewport;
	D3DXMATRIX m_kCachedTransform[3];
};



//class cILTDrawPrim3
//{
//public:
//	char pad_0000[15936]; //0x0000
//	uint32_t m_PrevColorOp; //0x3E40
//	uint32_t m_PrevAlphaBlendEnable; //0x3E44
//	uint32_t m_PrevSrcBlend; //0x3E48
//	uint32_t m_PrevDstBlend; //0x3E4C
//	uint32_t m_PrevZEnable; //0x3E50
//	uint32_t m_PrevZWriteEnable; //0x3E54
//	uint32_t m_PrevAlphaTestEnable; //0x3E58
//	uint32_t m_PrevAlphaTestFunc; //0x3E5C
//	uint32_t m_PrevFillMode; //0x3E60
//	uint32_t m_PrevClipMode; //0x3E64
//	uint32_t m_PrevCullMode; //0x3E68
//	uint32_t m_PrevAddrModeU; //0x3E6C
//	uint32_t m_PrevAddrModeV; //0x3E70
//	uint32_t m_PrevAddrModeW; //0x3E74
//	uint32_t m_PrevFogMode; //0x3E78
//	D3DXMATRIX m_PrevTransView; //0x3E7C
//	D3DXMATRIX m_PrevTransProj; //0x3EBC
//	D3DVIEWPORT9 m_PrevViewport; //0x3EFC _D3DVIEWPORT9
//	D3DVIEWPORT9 m_SavedViewport; //0x3F14 _D3DVIEWPORT9
//	bool m_bPrevReallyClose; //0x3F2C
//	bool m_bResetViewport; //0x3F2D
//	char pad_3F2E[2]; //0x3F2E
//	uint32_t m_nBlockCount; //0x3F30
//	uint32_t m_bIsScreenTransform; //0x3F34
//	char pad_3F38[468]; //0x3F38
//	D3DVIEWPORT9 ViewPort; //0x3F38
//	D3DXMATRIX World; //0x3F50
//	D3DXMATRIX View; //0x3F90
//	D3DXMATRIX Projection; //0x3FD0
//};//Size=0x4010


//Engine's vtable
struct ILTDrawPrim_vtbl
{
	const char* (__thiscall* _InterfaceImplementation)(IBase* pthis);
	unsigned int(__thiscall* BeginDrawPrim)(cILTDrawPrim* pthis);
	unsigned int(__thiscall* EndDrawPrim)(cILTDrawPrim* pthis);
	unsigned int(__thiscall* SetCamera)(cILTDrawPrim* pthis, LTObject* const);
	unsigned int(__thiscall* SetTexture)(cILTDrawPrim* pthis, SharedTexture* const);
	unsigned int(__thiscall* SetAlphaTexture)(cILTDrawPrim* pthis, SharedTexture*, int);
	unsigned int(__thiscall* SetTransformType)(cILTDrawPrim* pthis, const ELTTransformType);
	unsigned int(__thiscall* SetViewOffset)(cILTDrawPrim* pthis, float, float);
	unsigned int(__thiscall* SetScissorRect)(cILTDrawPrim* pthis, LTRectq*);
	ELTTransformType(__thiscall* GetTransformType)(cILTDrawPrim* pthis);
	void(__thiscall* CacheViewParam)(cILTDrawPrim* pthis, void*);
	unsigned int(__thiscall* SetColorOp)(cILTDrawPrim* pthis, const ELTColorOp);
	ELTColorOp(__thiscall* GetColorOp)(cILTDrawPrim* pthis);
	unsigned int(__thiscall* SetAlphaBlendMode)(cILTDrawPrim* pthis, const ELTBlendMode);
	unsigned int(__thiscall* SetZBufferMode)(cILTDrawPrim* pthis, const ELTZBufferMode);
	unsigned int(__thiscall* SetAlphaTestMode)(cILTDrawPrim* pthis, const ELTTestMode);
	unsigned int(__thiscall* SetClipMode)(cILTDrawPrim* pthis, const ELTClipMode);
	unsigned int(__thiscall* SetFillMode)(cILTDrawPrim* pthis, ELTDPFillMode);
	unsigned int(__thiscall* SetCullMode)(cILTDrawPrim* pthis, ELTDPCullMode);
	unsigned int(__thiscall* SetAddrMode)(cILTDrawPrim* pthis, ELTDPAddrMode);
	ELTDPAddrMode(__thiscall* GetAddrMode)(cILTDrawPrim* pthis);
	unsigned int(__thiscall* SetFogEnable)(cILTDrawPrim* pthis, bool);
	unsigned int(__thiscall* SetReallyClose)(cILTDrawPrim* pthis, bool);
	unsigned int(__thiscall* SetEffectShaderID)(cILTDrawPrim* pthis, unsigned int);
	unsigned int(__thiscall* SetEffectShaderPass)(cILTDrawPrim* pthis, unsigned int);
	void(__thiscall* SaveViewport)(cILTDrawPrim* pthis);
	void(__thiscall* RestoreViewport)(cILTDrawPrim* pthis);
	unsigned int(__thiscall* DrawPrim1)(cILTDrawPrim* pthis, LT_LINEFq*, const unsigned int);
	unsigned int(__thiscall* DrawPrim2)(cILTDrawPrim* pthis, LT_LINEGq*, const unsigned int);
	unsigned int(__thiscall* DrawPrim3)(cILTDrawPrim* pthis, LT_LINEFTq*, const unsigned int);
	unsigned int(__thiscall* DrawPrim4)(cILTDrawPrim* pthis, LT_LINEGTq*, const unsigned int);
	unsigned int(__thiscall* DrawPrim5)(cILTDrawPrim* pthis, LT_POLYF4q*, const unsigned int);
	unsigned int(__thiscall* DrawPrim6)(cILTDrawPrim* pthis, LT_POLYG4q*, const unsigned int);
	unsigned int(__thiscall* DrawPrim7)(cILTDrawPrim* pthis, LT_POLYFT4q*, const unsigned int);
	unsigned int(__thiscall* DrawPrim8)(cILTDrawPrim* pthis, LT_POLYGT4q**, const unsigned int);
	unsigned int(__thiscall* DrawPrim9)(cILTDrawPrim* pthis, LT_POLYGT4q*, const unsigned int);
	unsigned int(__thiscall* DrawPrim10)(cILTDrawPrim* pthis, LT_POLYF3q*, const unsigned int);
	unsigned int(__thiscall* DrawPrim11)(cILTDrawPrim* pthis, LT_POLYG3q*, const unsigned int);
	unsigned int(__thiscall* DrawPrim12)(cILTDrawPrim* pthis, LT_POLYFT3q*, const unsigned int);
	unsigned int(__thiscall* DrawPrim13)(cILTDrawPrim* pthis, LT_POLYGT3q*, const unsigned int);
	unsigned int(__thiscall* DrawPrimPoint1)(cILTDrawPrim* pthis, LT_VERTGq*, const unsigned int);
	unsigned int(__thiscall* DrawPrimPoint2)(cILTDrawPrim* pthis, LT_VERTGTq*, const unsigned int);
	unsigned int(__thiscall* DrawPrimFan1)(cILTDrawPrim* pthis, LT_VERTFq*, const unsigned int, LT_VERTRGBAq);
	unsigned int(__thiscall* DrawPrimFan2)(cILTDrawPrim* pthis, LT_VERTGq*, const unsigned int);
	unsigned int(__thiscall* DrawPrimFan3)(cILTDrawPrim* pthis, LT_VERTFTq*, const unsigned int, LT_VERTRGBAq);
	unsigned int(__thiscall* DrawPrimFan4)(cILTDrawPrim* pthis, LT_VERTGTq*, const unsigned int);
	unsigned int(__thiscall* DrawPrimStrip1)(cILTDrawPrim* pthis, LT_VERTFq*, const unsigned int, LT_VERTRGBAq);
	unsigned int(__thiscall* DrawPrimStrip2)(cILTDrawPrim* pthis, LT_VERTGq*, const unsigned int);
	unsigned int(__thiscall* DrawPrimStrip3)(cILTDrawPrim* pthis, LT_VERTFTq*, const unsigned int, LT_VERTRGBAq);
	unsigned int(__thiscall* DrawPrimStrip4)(cILTDrawPrim* pthis, LT_VERTGTq*, const unsigned int);
	void(__thiscall* GetD3DXVec3Project)(cILTDrawPrim* pthis, TVector3<float>, TVector3<float>*, float*);
	unsigned int(__thiscall* InitFrustum)(cILTDrawPrim* pthis, LTObject*, TVector3<float>);
	void(__thiscall* SetXY41)(cILTDrawPrim* pthis, LT_POLYF4q*, float, float, float, float, float, float, float, float);
	void(__thiscall* SetXY42)(cILTDrawPrim* pthis, LT_POLYG4q*, float, float, float, float, float, float, float, float);
	void(__thiscall* SetXY43)(cILTDrawPrim* pthis, LT_POLYFT4q*, float, float, float, float, float, float, float, float);
	void(__thiscall* SetXY44)(cILTDrawPrim* pthis, LT_POLYGT4q*, float, float, float, float, float, float, float, float);
	void(__thiscall* SetXYWH1)(cILTDrawPrim* pthis, LT_POLYF4q*, float, float, float, float);
	void(__thiscall* SetXYWH2)(cILTDrawPrim* pthis, LT_POLYG4q*, float, float, float, float);
	void(__thiscall* SetXYWH3)(cILTDrawPrim* pthis, LT_POLYFT4q*, float, float, float, float);
	void(__thiscall* SetXYWH4)(cILTDrawPrim* pthis, LT_POLYGT4q*, float, float, float, float);
	void(__thiscall* SetUV41)(cILTDrawPrim* pthis, LT_POLYFT4q*, float, float, float, float, float, float, float, float);
	void(__thiscall* SetUV42)(cILTDrawPrim* pthis, LT_POLYGT4q*, float, float, float, float, float, float, float, float);
	void(__thiscall* SetUVWH1)(cILTDrawPrim* pthis, LT_POLYFT4q*, float, float, float, float);
	void(__thiscall* SetUVWH2)(cILTDrawPrim* pthis, LT_POLYGT4q*, SharedTexture*, float, float, float, float);
	void(__thiscall* SetUVWH3)(cILTDrawPrim* pthis, LT_POLYGT4q*, float, float, float, float);
	void(__thiscall* SetUVRect1)(cILTDrawPrim* pthis, LT_POLYFT4q*, float, float, float, float);
	void(__thiscall* SetUVRect2)(cILTDrawPrim* pthis, LT_POLYGT4q*, float, float, float, float);
	void(__thiscall* SetRGB1)(cILTDrawPrim* pthis, LT_POLYF4q*, unsigned int);
	void(__thiscall* SetRGB2)(cILTDrawPrim* pthis, LT_POLYG4q*, unsigned int);
	void(__thiscall* SetRGB3)(cILTDrawPrim* pthis, LT_POLYFT4q*, unsigned int);
	void(__thiscall* SetRGB4)(cILTDrawPrim* pthis, LT_POLYGT4q*, unsigned int);
	void(__thiscall* SetRGBA1)(cILTDrawPrim* pthis, LT_POLYF4q*, unsigned int);
	void(__thiscall* SetRGBA2)(cILTDrawPrim* pthis, LT_POLYG4q*, unsigned int);
	void(__thiscall* SetRGBA3)(cILTDrawPrim* pthis, LT_POLYFT4q*, unsigned int);
	void(__thiscall* SetRGBA4)(cILTDrawPrim* pthis, LT_POLYGT4q*, unsigned int);
	void(__thiscall* SetRGB41)(cILTDrawPrim* pthis, LT_POLYG4q*, unsigned int, unsigned int, unsigned int, unsigned int);
	void(__thiscall* SetRGB42)(cILTDrawPrim* pthis, LT_POLYGT4q*, unsigned int, unsigned int, unsigned int, unsigned int);
	void(__thiscall* SetRGBA5)(cILTDrawPrim* pthis, LT_POLYG4q*, unsigned int, unsigned int, unsigned int, unsigned int);
	void(__thiscall* SetRGBA6)(cILTDrawPrim* pthis, LT_POLYGT4q*, unsigned int, unsigned int, unsigned int, unsigned int);
	void(__thiscall* SetALPHA1)(cILTDrawPrim* pthis, LT_POLYF4q*, char);
	void(__thiscall* SetALPHA2)(cILTDrawPrim* pthis, LT_POLYFT4q*, char);
	void(__thiscall* SetALPHA3)(cILTDrawPrim* pthis, LT_POLYG4q*, char);
	void(__thiscall* SetALPHA4)(cILTDrawPrim* pthis, LT_POLYGT4q*, char);
	void(__thiscall* SetALPHA41)(cILTDrawPrim* pthis, LT_POLYG4q*, char, char, char, char);
	void(__thiscall* SetALPHA42)(cILTDrawPrim* pthis, LT_POLYGT4q*, char, char, char, char);
	IDirect3DDevice9* (__thiscall* GetD3DDevice)(cILTDrawPrim* pthis);
};
