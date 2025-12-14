class cSFXList
{
public:
	DWORD m_pArray;
	DWORD* m_pAgeArray;
	DWORD m_nArraySize;
	DWORD m_nElements;
};
class SFXCREATESTRUCT_vtbl
{
public:
	virtual void Init();
	virtual void Write( ILTMessage_Write*);
	virtual void Read( ILTMessage_Read*);
};
class SFXCREATESTRUCT
{
public:
	SFXCREATESTRUCT_vtbl* __vftable /*VFT*/;
	LTObject* hServerObj;
};
class CSpecialFX
{
public:
	class CSpecialFX_vtbl* __vftable; //0x0000
	float m_fNextUpdateTime; //0x0004
	LTObject* m_pClientDE; //0x0008
	LTObject* m_hObject; //0x000C
	LTObject* m_hServerObject; //0x0010
	D3DXVECTOR3 m_vLastServPos; //0x0014
	D3DXVECTOR3 m_vVel; //0x0020
	int32_t m_bWantRemove; //0x002C
	float m_fUpdateDelta; //0x0030
	int32_t m_nMenuLayer; //0x0034
}; //Size: 0x0038
class CSFXMgr_vtbl
{
public:
	virtual void PreRender();
	virtual CSpecialFX* CreateSFX(char, SFXCREATESTRUCT*, ILTMessage_Read*, LTObject*);
};
class cSFXMgr //: public CSFXMgr_vtbl
{
public:
	cSFXList m_dynSFXLists[SFX_List::sfx_max];
}; cSFXMgr* SFXMgr;
