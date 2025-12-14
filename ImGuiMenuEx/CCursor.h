#pragma once



struct ScreenSpriteFrame
{
	int iFrameID;
	char* pName;
	struct SharedTexture* hTex;
	unsigned int iWidth;
	unsigned int iHeight;
};



class CScreenSprite
{
public:
	ScreenSpriteLayer m_eLayer;
	LTIntPtq m_Position;
	LTIntPtq m_Center;
	char* m_pName;
	int m_nFrames;
	int m_nFrameRate;
	float m_fOneFrameTime;
	unsigned int m_bExpires;
	float m_fLifeTime;
	unsigned int m_bShow;
	unsigned int m_bAdditive;
	LTPoly_GT4q m_DrawPrim;
	std::vector<ScreenSpriteFrame*, std::allocator<ScreenSpriteFrame*> > m_FrameArray;
	int m_iCurrentFrame;
	float m_fCurrentTime;
};
class ILTCursorInst;
class ILTCursorInst_vtbl
{
public:
	unsigned int(__thiscall* IsValid)(ILTCursorInst* pthis);
	void(__thiscall* SetData)(ILTCursorInst* pthis, const void*);
	void* (__thiscall* GetData)(ILTCursorInst* pthis);
};


class ILTCursorInst
{
public:
	ILTCursorInst_vtbl* __vftable;
};


class CCursorMgr
{
public:
	unsigned int m_bInitialized;
	unsigned int m_bUseCursor;
	unsigned int m_bUseHardwareCursor;
	LTIntPtq m_CursorCenter;
	ILTCursorInst* m_hCursor;
	HSURFACE_tq* m_hSurfCursor;
	std::vector<CScreenSprite*, std::allocator<CScreenSprite*> > m_SpriteArray;
	CScreenSprite* m_pCursorSprite;
	CScreenSprite* m_pCursorGlowSprite;
	CScreenSprite* m_pCursorBackgroundSprite;
};
