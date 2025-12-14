#pragma once
#include <string>
#include <array>
#include <cstdarg>
#include <utility>
namespace { constexpr int const_atoi(char c) { return c - '0'; } }
#define ALWAYS_INLINE __forceinline
template<typename _string_type, size_t _length>
class _Basic_XorStr
{
	using value_type = typename _string_type::value_type;
	static constexpr auto _length_minus_one = _length - 1;
public:
	constexpr ALWAYS_INLINE _Basic_XorStr(value_type const (&str)[_length]) : _Basic_XorStr(str, std::make_index_sequence<_length_minus_one>()) {}
	inline auto c_str() const { decrypt(); return data; }
	inline auto str() const { decrypt(); return _string_type(data, data + _length_minus_one); }
	inline operator _string_type() const { return str(); }
private:
	template<size_t... indices>
	constexpr ALWAYS_INLINE _Basic_XorStr(value_type const (&str)[_length], std::index_sequence<indices...>) : data{ crypt(str[indices], indices)..., '\0' }, encrypted(true) {}
	static constexpr auto XOR_KEY = static_cast<value_type>(const_atoi(__TIME__[7]) + const_atoi(__TIME__[6]) * 10 + const_atoi(__TIME__[4]) * 60 + const_atoi(__TIME__[3]) * 600 + const_atoi(__TIME__[1]) * 3600 + const_atoi(__TIME__[0]) * 36000);
	static ALWAYS_INLINE constexpr auto crypt(value_type c, size_t i) { return static_cast<value_type>(c ^ (XOR_KEY + i)); }
	inline void decrypt() const { if (encrypted) { for (size_t t = 0; t < _length_minus_one; t++) { data[t] = crypt(data[t], t); }encrypted = false; } }
	mutable value_type data[_length];
	mutable bool encrypted;
};
//---------------------------------------------------------------------------
template<size_t _length>
using XorStrA = class _Basic_XorStr<std::string, _length>;
template<size_t _length>
using XorStrW = class _Basic_XorStr<std::wstring, _length>;
template<size_t _length>
using XorStrU16 = class _Basic_XorStr<std::u16string, _length>;
template<size_t _length>
using XorStrU32 = class _Basic_XorStr<std::u32string, _length>;
//---------------------------------------------------------------------------
template<typename _string_type, size_t _length, size_t _length2>
inline auto operator==(const _Basic_XorStr<_string_type, _length>& lhs, const _Basic_XorStr<_string_type, _length2>& rhs) { static_assert(_length == _length2, "XorStr== different length"); return _length == _length2 && lhs.str() == rhs.str(); }
//---------------------------------------------------------------------------
template<typename _string_type, size_t _length>
inline auto operator==(const _string_type& lhs, const _Basic_XorStr<_string_type, _length>& rhs) { return lhs.size() == _length && lhs == rhs.str(); }
//---------------------------------------------------------------------------
template<typename _stream_type, typename _string_type, size_t _length>
inline auto& operator<<(_stream_type& lhs, const _Basic_XorStr<_string_type, _length>& rhs) { lhs << rhs.c_str(); return lhs; }
//---------------------------------------------------------------------------
template<typename _string_type, size_t _length, size_t _length2>
inline auto operator+(const _Basic_XorStr<_string_type, _length>& lhs, const _Basic_XorStr<_string_type, _length2>& rhs) { return lhs.str() + rhs.str(); }
//---------------------------------------------------------------------------
template<typename _string_type, size_t _length>
inline auto operator+(const _string_type& lhs, const _Basic_XorStr<_string_type, _length>& rhs) { return lhs + rhs.str(); }
//---------------------------------------------------------------------------
template<size_t _length>
constexpr ALWAYS_INLINE auto _xor_(char const (&str)[_length]) { return XorStrA<_length>(str); }
//---------------------------------------------------------------------------
template<size_t _length>
constexpr ALWAYS_INLINE auto _xor_(wchar_t const (&str)[_length]) { return XorStrW<_length>(str); }
//---------------------------------------------------------------------------
template<size_t _length>
constexpr ALWAYS_INLINE auto _xor_(char16_t const (&str)[_length]) { return XorStrU16<_length>(str); }
//---------------------------------------------------------------------------
template<size_t _length>
constexpr ALWAYS_INLINE auto _xor_(char32_t const (&str)[_length]) { return XorStrU32<_length>(str); }
//---------------------------------------------------------------------------
#define ___(text)  _xor_(text).c_str()


template <int XORSTART, int BUFLEN, int XREFKILLER>
class XorStr
{
private: XorStr();
public: char s[BUFLEN]; XorStr(const char* xs); ~XorStr() { for (int i = 0; i < BUFLEN; i++)s[i] = 0; }
};
template <int XORSTART, int BUFLEN, int XREFKILLER>
XorStr<XORSTART, BUFLEN, XREFKILLER>::XorStr(const char* xs)
{
	int xvalue = XORSTART; int i = 0; for (; i < (BUFLEN - 1); i++) { s[i] = xs[i - XREFKILLER] ^ xvalue; xvalue += 1; xvalue %= 256; }s[BUFLEN - 1] = 0;
}

#pragma region PROCESS
#define PROCESS_D3D9				/*D3D9.dll*/				XorStr<0x51,9,0x84D3BAB5>("\x15\x61\x17\x6D\x7B\x32\x3B\x34"+0x84D3BAB5).s
#define PROCESS_CLIENTFX			/*ClientFX.fxd*/			XorStr<0xD0,13,0x1E7A0B85>("\x93\xBD\xBB\xB6\xBA\xA1\x90\x8F\xF6\xBF\xA2\xBF"+0x1E7A0B85).s
#define PROCESS_CSHELL				/*CShell.dll*/				XorStr<0xD0,11,0x4F8C74E1>("\x93\x82\xBA\xB6\xB8\xB9\xF8\xB3\xB4\xB5"+0x4F8C74E1).s
#define PROCESS_ENGINE				/*Engine.exe*/				XorStr<0xB3,11,0x7FBD06BD>("\xF6\xDA\xD2\xDF\xD9\xDD\x97\xDF\xC3\xD9"+0x7FBD06BD).s
#define PROCESS_ENGINE2				/*Engine2.exe*/				XorStr<0x5E,12,0xF24B77BF>("\x1B\x31\x07\x08\x0C\x06\x56\x4B\x03\x1F\x0D"+0xF24B77BF).s
#pragma endregion
#pragma region AIMBOT MENU
//Menu
#define AIMBOT_TITLE_Menu			/*Aimbot*/					XorStr<0x0D,7,0x1C095025>("\x4C\x67\x62\x72\x7E\x66"+0x1C095025).s
//Activation
#define AIMBOT_Activation			/*Activate Aimbot*/			XorStr<0x41,16,0x605AE430>("\x00\x21\x37\x2D\x33\x27\x33\x2D\x69\x0B\x22\x21\x2F\x21\x3B"+0x605AE430).s
#define AIMBOT_AutoAim				/*Auto Aim*/				XorStr<0xF1,9,0x7CF52E4E>("\xB0\x87\x87\x9B\xD5\xB7\x9E\x95"+0x7CF52E4E).s
#define AIMBOT_VisibleCheck			/*Visible Check*/			XorStr<0x50,14,0x007B3AE7>("\x06\x38\x21\x3A\x36\x39\x33\x77\x1B\x31\x3F\x38\x37"+0x007B3AE7).s
#define AIMBOT_SpawnCheck			/*Spawn Check*/				XorStr<0xD7,12,0x4BB414D7>("\x84\xA8\xB8\xAD\xB5\xFC\x9E\xB6\xBA\x83\x8A"+0x4BB414D7).s
#define AIMBOT_ActSmooth			/*##Smooth*/				XorStr<0xB8,9,0x328F882F>("\x9B\x9A\xE9\xD6\xD3\xD2\xCA\xD7"+0x328F882F).s
#define AIMBOT_FOV					/*##AimbotFOV*/				XorStr<0x81,12,0x996ED46B>("\xA2\xA1\xC2\xED\xE8\xE4\xE8\xFC\xCF\xC5\xDD"+0x996ED46B).s
//Settings
#define AIMBOT_SmoothSpeed			/*SmoothSpeed*/				XorStr<0xF9,12,0xA3F04AB4>("\xAA\x97\x94\x93\x89\x96\xAC\x70\x64\x67\x67"+0xA3F04AB4).s
#define AIMBOT_AimKey				/*Aim Key*/					XorStr<0x28,8,0xE22B0F40>("\x69\x40\x47\x0B\x67\x48\x57"+0xE22B0F40).s
#define AIMBOT_AimBone				/*Aim Bone*/				XorStr<0x37,9,0x02ECEDDD>("\x76\x51\x54\x1A\x79\x53\x53\x5B"+0x02ECEDDD).s
#define AIMBOT_AimType				/*Aim Type*/				XorStr<0xF4,9,0x2E63998D>("\xB5\x9C\x9B\xD7\xAC\x80\x8A\x9E"+0x2E63998D).s
#define AIMBOT_AimFOV				/*AimFOV*/					XorStr<0xAD,7,0x21DF14ED>("\xEC\xC7\xC2\xF6\xFE\xE4"+0x21DF14ED).s
//Slider
#define AIMBOT_Crosshair			/*Crosshair*/				XorStr<0x96,10,0x8BA40FF2>("\xD5\xE5\xF7\xEA\xE9\xF3\xFD\xF4\xEC"+0x8BA40FF2).s
#define AIMBOT_Player				/*Player*/					XorStr<0x67,7,0xDF428FE7>("\x37\x04\x08\x13\x0E\x1E"+0xDF428FE7).s
//Others
#define AIMBOT_FOVCircle			/*Show FOV*/				XorStr<0xF0,9,0x14C071E4>("\xA3\x99\x9D\x84\xD4\xB3\xB9\xA1"+0x14C071E4).s
#pragma endregion
#pragma region EXCLUSIVE
//Menu
#define EXCLUSIVE_Menu				/*Exclusive*/				XorStr<0x7D,10,0x63011DCF>("\x38\x06\x1C\xEC\xF4\xF1\xEA\xF2\xE0"+0x63011DCF).s

#pragma region RemoteKill Menu

//Title RemoteKill
#define REMOTEKILL_TITLE_Main		/*REMOTE KILL*/				XorStr<0x6C,12,0xF11847F3>("\x3E\x28\x23\x20\x24\x34\x52\x38\x3D\x39\x3A"+0xF11847F3).s
#define REMOTEKILL_TITLE_Settings	/*SETTINGS*/				XorStr<0x29,9,0x4FF149DD>("\x7A\x6F\x7F\x78\x64\x60\x68\x63"+0x4FF149DD).s
//Activation
#define REMOTEKILL_Activation		/*Activation*/				XorStr<0xC7,11,0x9A27E32C>("\x86\xAB\xBD\xA3\xBD\xAD\xB9\xA7\xA0\xBE"+0x9A27E32C).s
#define REMOTEKILL_Visible			/*Visible Check*/			XorStr<0x07,14,0xF2C75317>("\x51\x61\x7A\x63\x69\x60\x68\x2E\x4C\x78\x74\x71\x78"+0xF2C75317).s
#define REMOTEKILL_Respawn			/*Respawn Check*/			XorStr<0xDD,14,0xB810BFF4>("\x8F\xBB\xAC\x90\x80\x95\x8D\xC4\xA6\x8E\x82\x8B\x82"+0xB810BFF4).s
#define REMOTEKILL_FOV				/*FOV Check*/				XorStr<0xE0,10,0x09920E83>("\xA6\xAE\xB4\xC3\xA7\x8D\x83\x84\x83"+0x09920E83).s
#define REMOTEKILL_ShowFOV			/*Show FOV*/				XorStr<0x7E,9,0x65443A1F>("\x2D\x17\xEF\xF6\xA2\xC5\xCB\xD3"+0x65443A1F).s
#define REMOTEKILL_ActivationFilter	/*Set Filter*/				XorStr<0xAC,11,0x63E127BF>("\xFF\xC8\xDA\x8F\xF6\xD8\xDE\xC7\xD1\xC7"+0x63E127BF).s
//Settings
#define REMOTEKILL_Bone				/*Bones*/					XorStr<0xB7,6,0x4AF69366>("\xF5\xD7\xD7\xDF\xC8"+0x4AF69366).s
#define REMOTEKILL_FOVs				/*FOV*/						XorStr<0xF2,4,0x1E1F3A1A>("\xB4\xBC\xA2"+0x1E1F3A1A).s
#define REMOTEKILL_Filter			/*Filter Type*/				XorStr<0x27,12,0x62F5CA56>("\x61\x41\x45\x5E\x4E\x5E\x0D\x7A\x56\x40\x54"+0x62F5CA56).s
//Texts
#define REMOTEKILL_TEXT_Activation	/*Status -> %s*/			XorStr<0xE3,13,0x9958C4A0>("\xB0\x90\x84\x92\x92\x9B\xC9\xC7\xD5\xCC\xC8\x9D"+0x9958C4A0).s
#define REMOTEKILL_TEXT_Visible		/*Visible -> %s*/			XorStr<0xEB,14,0x96FCD471>("\xBD\x85\x9E\x87\x8D\x9C\x94\xD2\xDE\xCA\xD5\xD3\x84"+0x96FCD471).s
#define REMOTEKILL_TEXT_Respawn		/*Respawn -> %s*/			XorStr<0x26,14,0xDF77E9BB>("\x74\x42\x5B\x59\x4B\x5C\x42\x0D\x03\x11\x10\x14\x41"+0xDF77E9BB).s
#pragma endregion

#pragma region Ghost Aim MENU
//Title GhostAim
#define GAIM_TITLE_Main				/*GHOST AIM*/				XorStr<0x70,10,0x1496F32D>("\x37\x39\x3D\x20\x20\x55\x37\x3E\x35"+0x1496F32D).s
#define GAIM_TITLE_Ghost			/*Ghost*/					XorStr<0xEB,6,0x19012293>("\xAC\x84\x82\x9D\x9B"+0x19012293).s
#define GAIM_TITLE_Focus			/*Focus*/					XorStr<0x35,6,0x1CBBD1A2>("\x73\x59\x54\x4D\x4A"+0x1CBBD1A2).s
//Ghost
#define GAIM_Activation				/*Activate Ghost*/			XorStr<0xB4,15,0xC4067DB3>("\xF5\xD6\xC2\xDE\xCE\xD8\xCE\xDE\x9C\xFA\xD6\xD0\xB3\xB5"+0xC4067DB3).s
#define GAIM_BONE_ID				/*Select Bone*/				XorStr<0x47,12,0x02727EC3>("\x14\x2D\x25\x2F\x28\x38\x6D\x0C\x20\x3E\x34"+0x02727EC3).s
#define GAIM_BONE_Size				/*Change Size*/				XorStr<0xC7,12,0xF05F7C92>("\x84\xA0\xA8\xA4\xAC\xA9\xED\x9D\xA6\xAA\xB4"+0xF05F7C92).s
//Focus
#define FAIM_Activation				/*Activate Focus*/			XorStr<0x39,15,0xED33E168>("\x78\x59\x4F\x55\x4B\x5F\x4B\x25\x61\x04\x2C\x27\x30\x35"+0xED33E168).s
#define FAIM_ACT_FOV				/*Activate FOV*/			XorStr<0xB2,13,0x8BFD4368>("\xF3\xD0\xC0\xDC\xC0\xD6\xCC\xDC\x9A\xFD\xF3\xEB"+0x8BFD4368).s
#define FAIM_FOV_Size				/*FOV Size*/				XorStr<0x90,9,0xADE25C56>("\xD6\xDE\xC4\xB3\xC7\xFC\xEC\xF2"+0xADE25C56).s
#pragma endregion
#pragma region ESP
//Menu
#define ESP_MENU_Main				/*ESP*/						XorStr<0x04,4,0xA8A63B15>("\x41\x56\x56"+0xA8A63B15).s
#define ESP_MENU_Others				/*ESP Others*/				XorStr<0x3C,11,0x32656030>("\x79\x6E\x6E\x1F\x0F\x35\x2A\x26\x36\x36"+0x32656030).s
//Title
#define ESP_TITLE_Enemy				/*Enemy + NPC*/				XorStr<0x7B,12,0x177914E2>("\x3E\x12\x18\x13\x06\xA0\xAA\xA2\xCD\xD4\xC6"+0x177914E2).s
#define ESP_TITLE_Allies			/*Allies*/					XorStr<0x26,7,0x462C737F>("\x67\x4B\x44\x40\x4F\x58"+0x462C737F).s
//ESP
#define ESP_ENEMY_Activation		/*Activate##Enemy*/			XorStr<0x72,16,0xCEE5E25A>("\x33\x10\x00\x1C\x00\x16\x0C\x1C\x59\x58\x39\x13\x1B\x12\xF9"+0xCEE5E25A).s
#define ESP_ENEMY_Box				/*Show Box##Enemy*/			XorStr<0x2F,16,0x533E69DA>("\x7C\x58\x5E\x45\x13\x76\x5A\x4E\x14\x1B\x7C\x54\x5E\x51\x44"+0x533E69DA).s
#define ESP_ENEMY_Name				/*Show Name##Enemy*/		XorStr<0x33,17,0x940AA3AC>("\x60\x5C\x5A\x41\x17\x76\x58\x57\x5E\x1F\x1E\x7B\x51\x25\x2C\x3B"+0x940AA3AC).s
#define ESP_ENEMY_Health			/*Show Health##Enemy*/		XorStr<0x3F,19,0x2E8E34E7>("\x6C\x28\x2E\x35\x63\x0C\x20\x27\x2B\x3C\x21\x69\x68\x09\x23\x2B\x22\x29"+0x2E8E34E7).s
#define ESP_ENEMY_Armor				/*Show Armor##Enemy*/		XorStr<0x58,18,0xF75B08BB>("\x0B\x31\x35\x2C\x7C\x1C\x2C\x32\x0F\x13\x41\x40\x21\x0B\x03\x0A\x11"+0xF75B08BB).s
#define ESP_ENEMY_Line				/*Show Line##Enemy*/		XorStr<0x26,17,0xB9F6351A>("\x75\x4F\x47\x5E\x0A\x67\x45\x43\x4B\x0C\x13\x74\x5C\x56\x59\x4C"+0xB9F6351A).s
#define ESP_ENEMY_Distance			/*Show Distance##Enemy*/	XorStr<0xD6,21,0x3A5A10E9>("\x85\xBF\xB7\xAE\xFA\x9F\xB5\xAE\xAA\xBE\x8E\x82\x87\xC0\xC7\xA0\x88\x82\x85\x90"+0x3A5A10E9).s
#define ESP_ENEMY_Bone				/*Show Bone##Enemy*/		XorStr<0x76,17,0x9B406F6F>("\x25\x1F\x17\x0E\x5A\x39\x13\x13\x1B\x5C\xA3\xC4\xEC\xE6\xE9\xFC"+0x9B406F6F).s
#define ESP_ENEMY_Spawn				/*Spawn Check##Enemy*/		XorStr<0xDE,19,0x0C427216>("\x8D\xAF\x81\x96\x8C\xC3\xA7\x8D\x83\x84\x83\xCA\xC9\xAE\x82\x88\x83\x96"+0x0C427216).s
#define ESP_ENEMY_Visible			/*Visible Check##Enemy*/	XorStr<0x48,21,0xC7F5176A>("\x1E\x20\x39\x22\x2E\x21\x2B\x6F\x13\x39\x37\x30\x3F\x76\x75\x12\x36\x3C\x37\x22"+0xC7F5176A).s


#define ESP_ALLY_Activation			/*Activate##Ally*/			XorStr<0x64,15,0x3935BA2D>("\x25\x06\x12\x0E\x1E\x08\x1E\x0E\x4F\x4E\x2F\x03\x1C\x08"+0x3935BA2D).s
#define ESP_ALLY_Box				/*Show Box##Ally*/			XorStr<0x19,15,0x78CA2940>("\x4A\x72\x74\x6B\x3D\x5C\x70\x58\x02\x01\x62\x48\x49\x5F"+0x78CA2940).s
#define ESP_ALLY_Name				/*Show Name##Ally*/			XorStr<0xFA,16,0xE6B3D61F>("\xA9\x93\x93\x8A\xDE\xB1\x61\x6C\x67\x20\x27\x44\x6A\x6B\x71"+0xE6B3D61F).s
#define ESP_ALLY_Health				/*Show Health##Ally*/		XorStr<0xAB,18,0x3B0E364E>("\xF8\xC4\xC2\xD9\x8F\xF8\xD4\xD3\xDF\xC0\xDD\x95\x94\xF9\xD5\xD6\xC2"+0x3B0E364E).s
#define ESP_ALLY_Armor				/*Show Armor##Ally*/		XorStr<0x65,17,0x1137868B>("\x36\x0E\x08\x1F\x49\x2B\x19\x01\x02\x1C\x4C\x53\x30\x1E\x1F\x0D"+0x1137868B).s
#define ESP_ALLY_Line				/*Show Line##Ally*/			XorStr<0x99,16,0xF36064B0>("\xCA\xF2\xF4\xEB\xBD\xD2\xF6\xCE\xC4\x81\x80\xE5\xC9\xCA\xDE"+0xF36064B0).s
#define ESP_ALLY_Distance			/*Show Distance##Ally*/		XorStr<0x82,20,0xD345A3E3>("\xD1\xEB\xEB\xF2\xA6\xC3\xE1\xFA\xFE\xEA\xE2\xEE\xEB\xAC\xB3\xD0\xFE\xFF\xED"+0xD345A3E3).s
#define ESP_ALLY_Bone				/*Show Bone##Ally*/			XorStr<0x92,16,0x98395FED>("\xC1\xFB\xFB\xE2\xB6\xD5\xF7\xF7\xFF\xB8\xBF\xDC\xF2\xF3\xD9"+0x98395FED).s
#define ESP_ALLY_Spawn				/*Spawn Check##Ally*/		XorStr<0x5C,18,0x7F1180DB>("\x0F\x2D\x3F\x28\x0E\x41\x21\x0B\x01\x06\x0D\x44\x4B\x28\x06\x07\x15"+0x7F1180DB).s
#define ESP_ALLY_Visible			/*Visible Check##Ally*/		XorStr<0x12,20,0x13C81A59>("\x44\x7A\x67\x7C\x74\x7B\x7D\x39\x59\x73\x79\x7E\x75\x3C\x03\x60\x4E\x4F\x5D"+0x13C81A59).s

//Other
#define ESP_OTHER_Weapon			/*Show Weapon*/				XorStr<0x91,12,0x5ED832BB>("\xC2\xFA\xFC\xE3\xB5\xC1\xF2\xF9\xE9\xF5\xF5"+0x5ED832BB).s
#define ESP_OTHER_Explosive			/*Show Explosive*/			XorStr<0x04,15,0xF687E15D>("\x57\x6D\x69\x70\x28\x4C\x72\x7B\x60\x62\x7D\x66\x66\x74"+0xF687E15D).s
#define ESP_OTHER_Radar				/*Show D3D Radar*/			XorStr<0xBC,15,0x98B385F7>("\xEF\xD5\xD1\xC8\xE0\x85\xF1\x87\xE4\x97\xA7\xA3\xA9\xBB"+0x98B385F7).s
//Color
#define ESP_ALLY_COLOR_Visible		/*Allies Visible*/			XorStr<0xFE,15,0x10637734>("\xBF\x93\x6C\x68\x67\x70\x24\x53\x6F\x74\x61\x6B\x66\x6E"+0x10637734).s
#define ESP_ALLY_COLOR_Invisible	/*Allies NonVisible*/		XorStr<0x5C,18,0xBDEA0E46>("\x1D\x31\x32\x36\x05\x12\x42\x2D\x0B\x0B\x30\x0E\x1B\x00\x08\x07\x09"+0xBDEA0E46).s
#define ESP_ALLY_COLOR_Respawn		/*Allies Respawn*/			XorStr<0xEA,15,0x13D465FE>("\xAB\x87\x80\x84\x8B\x9C\xD0\xA3\x97\x80\x84\x94\x81\x99"+0x13D465FE).s

#define ESP_Ennemy_COLOR_Visible	/*Enemy Visible*/			XorStr<0xE1,14,0xDF1C02F4>("\xA4\x8C\x86\x89\x9C\xC6\xB1\x81\x9A\x83\x89\x80\x88"+0xDF1C02F4).s
#define ESP_Ennemy_COLOR_Invisible	/*Enemy NonVisible*/		XorStr<0x6D,17,0x2F5EB958>("\x28\x00\x0A\x1D\x08\x52\x3D\x1B\x1B\x20\x1E\x0B\x10\x18\x17\x19"+0x2F5EB958).s
#define ESP_Ennemy_COLOR_Respawn	/*Enemy Respawn*/			XorStr<0x5F,14,0x314EA5D2>("\x1A\x0E\x04\x0F\x1A\x44\x37\x03\x14\x18\x08\x1D\x05"+0x314EA5D2).s

//Radar
#pragma endregion
#pragma region VISUAL MENU
//TITLES
#define VISUAL_MENU					/*Visual*/					XorStr<0xE0,7,0x593D682E>("\xB6\x88\x91\x96\x85\x89"+0x593D682E).s
//NEXON
#define NEXON_Chams					/*Nexon Chams*/				XorStr<0x1A,12,0x53A45B7A>("\x54\x7E\x64\x72\x70\x3F\x63\x49\x43\x4E\x57"+0x53A45B7A).s
#define NEXON_REMOVE_Fog			/*Remove Fog*/				XorStr<0x1F,11,0x52041506>("\x4D\x45\x4C\x4D\x55\x41\x05\x60\x48\x4F"+0x52041506).s
#define NEXON_REMOVE_Smoke			/*Remove Smoke*/			XorStr<0x80,13,0x0B6B7659>("\xD2\xE4\xEF\xEC\xF2\xE0\xA6\xD4\xE5\xE6\xE1\xEE"+0x0B6B7659).s
#define NEXON_Glow					/*Glow Player*/				XorStr<0x93,12,0x6345B3E7>("\xD4\xF8\xFA\xE1\xB7\xC8\xF5\xFB\xE2\xF9\xEF"+0x6345B3E7).s
#define NEXON_Texture				/*Remove Texture*/			XorStr<0xCF,15,0xD493C2B9>("\x9D\xB5\xBC\xBD\xA5\xB1\xF5\x82\xB2\xA0\xAD\xAF\xA9\xB9"+0xD493C2B9).s
#define NEXON_Bright				/*Bright World*/			XorStr<0x91,13,0x76CC8BC9>("\xD3\xE0\xFA\xF3\xFD\xE2\xB7\xCF\xF6\xE8\xF7\xF8"+0x76CC8BC9).s
#define NEXON_WorldTree				/*Show World Tree*/			XorStr<0xEC,16,0x3F73A353>("\xBF\x85\x81\x98\xD0\xA6\x9D\x81\x98\x91\xD6\xA3\x8A\x9C\x9F"+0x3F73A353).s
#define NEXON_WorldBox				/*Show World Box*/			XorStr<0x65,15,0x0119E534>("\x36\x0E\x08\x1F\x49\x3D\x04\x1E\x01\x0A\x4F\x32\x1E\x0A"+0x0119E534).s
#pragma endregion
#pragma region PLAYER MENU
//Title
#define PLAYER_TITLE_NOCLIP			/*NO CLIP*/					XorStr<0x0F,8,0x347FAE76>("\x41\x5F\x31\x51\x5F\x5D\x45"+0x347FAE76).s
#define PLAYER_TITLE_Movement		/*Movement*/				XorStr<0x37,9,0xB3C58852>("\x7A\x57\x4F\x5F\x56\x59\x53\x4A"+0xB3C58852).s
#define PLAYER_TITLE_TeleKill		/*Teleport Kill*/			XorStr<0xEB,14,0xA9C8194D>("\xBF\x89\x81\x8B\x9F\x9F\x83\x86\xD3\xBF\x9C\x9A\x9B"+0xA9C8194D).s

//Player
#define PLAYER_Invisible			/*Invisible*/				XorStr<0x47,10,0x7227A6B0>("\x0E\x26\x3F\x23\x38\x25\x2F\x22\x2A"+0x7227A6B0).s
#define PLAYER_Fly_Activation		/*Activate Fly*/			XorStr<0x6D,13,0x314F2C16>("\x2C\x0D\x1B\x19\x07\x13\x07\x11\x55\x30\x1B\x01"+0x314F2C16).s
#define PLAYER_AntiKnockback		/*Anti Knockback*/			XorStr<0x44,15,0xC0E459CA>("\x05\x2B\x32\x2E\x68\x02\x24\x24\x2F\x26\x2C\x2E\x33\x3A"+0xC0E459CA).s
#define PLAYER_NoClip				/*No Clip*/					XorStr<0x5C,8,0xA2949FFF>("\x12\x32\x7E\x1C\x0C\x08\x12"+0xA2949FFF).s
#define PLAYER_NoClipSpeed			/*##Clip Speed*/			XorStr<0x3A,13,0x8D3E1F9A>("\x19\x18\x7F\x51\x57\x4F\x60\x12\x32\x26\x21\x21"+0x8D3E1F9A).s
#define PLAYER_BHOP					/*Buny Hop*/				XorStr<0x6C,9,0x46204E11>("\x2E\x18\x00\x16\x50\x39\x1D\x03"+0x46204E11).s
//Teleport
#define PLAYER_TELEKILL				/*TeleKill*/				XorStr<0x22,9,0xA6FA4CF8>("\x76\x46\x48\x40\x6D\x4E\x44\x45"+0xA6FA4CF8).s
#define PLAYER_TELEKILL_X			/*Position X*/				XorStr<0x1F,11,0xA0776AA3>("\x4F\x4F\x52\x4B\x57\x4D\x4A\x48\x07\x70"+0xA0776AA3).s
#define PLAYER_TELEKILL_Y			/*Position Y*/				XorStr<0xCA,11,0x044DFF01>("\x9A\xA4\xBF\xA4\xBA\xA6\xBF\xBF\xF2\x8A"+0x044DFF01).s
#define PLAYER_TELEKILL_Z			/*Position Z*/				XorStr<0x87,11,0xE1A37FE1>("\xD7\xE7\xFA\xE3\xFF\xE5\xE2\xE0\xAF\xCA"+0xE1A37FE1).s
//Spoofer
#define SPOOF_Activation			/*Activate Spoofer*/		XorStr<0x8E,17,0x90732326>("\xCF\xEC\xE4\xF8\xE4\xF2\xE0\xF0\xB6\xC4\xE8\xF6\xF5\xFD\xF9\xEF"+0x90732326).s
#define SPOOF_Character				/*Spoof Character*/			XorStr<0x7A,16,0x61754E6E>("\x29\x0B\x13\x12\x18\x5F\xC3\xE9\xE3\xF1\xE5\xE6\xF2\xE2\xFA"+0x61754E6E).s
#define SPOOF_Helmet				/*Spoof Helmet*/			XorStr<0x76,13,0xA9A9B657>("\x25\x07\x17\x16\x1C\x5B\x34\x18\x12\x12\xE5\xF5"+0xA9A9B657).s
#define SPOOF_Goggle				/*Spoof Goggle*/			XorStr<0x84,13,0xF354609A>("\xD7\xF5\xE9\xE8\xEE\xA9\xCD\xE4\xEB\xEA\xE2\xEA"+0xF354609A).s
#define SPOOF_Backpack				/*Spoof Backpack*/			XorStr<0xDA,15,0x6C607B36>("\x89\xAB\xB3\xB2\xB8\xFF\xA2\x80\x81\x88\x94\x84\x85\x8C"+0x6C607B36).s

#define SPOOF_Characters			/*Character ID*/			XorStr<0xD3,13,0x733A6347>("\x90\xBC\xB4\xA4\xB6\xBB\xAD\xBF\xA9\xFC\x94\x9A"+0x733A6347).s
#define SPOOF_Helmets				/*Helmet ID*/				XorStr<0xF8,10,0xDD528E57>("\xB0\x9C\x96\x96\x99\x89\xDE\xB6\x44"+0xDD528E57).s
#define SPOOF_Goggles				/*Goggle ID*/				XorStr<0x56,10,0xB203A61D>("\x11\x38\x3F\x3E\x36\x3E\x7C\x14\x1A"+0xB203A61D).s
#define SPOOF_Backpacks				/*Backpack ID*/				XorStr<0xF2,12,0x10D6E0EA>("\xB0\x92\x97\x9E\x86\x96\x9B\x92\xDA\xB2\xB8"+0x10D6E0EA).s
#define SPOOF_HP					/*680 HP*/					XorStr<0x72,7,0x5D6AA1D3>("\x44\x4B\x44\x55\x3E\x27"+0x5D6AA1D3).s
#pragma endregion
#pragma region WEAPON MENU
//Menu
//Title
#define WEAPON_TITLE_Basics			/*Basics Weapon Effect*/	XorStr<0x28,21,0x3EF13F23>("\x6A\x48\x59\x42\x4F\x5E\x0E\x78\x55\x50\x42\x5C\x5A\x15\x73\x51\x5E\x5C\x59\x4F"+0x3EF13F23).s
//Activation
#define WEAPON_Distance				/*[E] Distance*/			XorStr<0xB0,13,0x45EA7E45>("\xEB\xF4\xEF\x93\xF0\xDC\xC5\xC3\xD9\xD7\xD9\xDE"+0x45EA7E45).s
#define WEAPON_Recoil				/*Recoil*/					XorStr<0x4A,7,0x01C88FB2>("\x18\x2E\x2F\x22\x27\x23"+0x01C88FB2).s
#define WEAPON_Spread				/*Spread*/					XorStr<0x5F,7,0xC9D6A0EA>("\x0C\x10\x13\x07\x02\x00"+0xC9D6A0EA).s
#define WEAPON_Reload				/*Reload*/					XorStr<0x69,7,0xE816EA06>("\x3B\x0F\x07\x03\x0C\x0A"+0xE816EA06).s
#define WEAPON_FastSwitch			/*Switch*/					XorStr<0xBE,7,0xBEA07005>("\xED\xC8\xA9\xB5\xA1\xAB"+0xBEA07005).s
#define WEAPON_FastZoom				/*Zoom*/					XorStr<0x2A,5,0x1CDD9BD4>("\x70\x44\x43\x40"+0x1CDD9BD4).s
#define WEAPON_RemoveWeight			/*Weight*/					XorStr<0x73,7,0x29D8F61C>("\x24\x11\x1C\x11\x1F\x0C"+0x29D8F61C).s
#define WEAPON_MultiBullet			/*Bullet*/					XorStr<0xF1,7,0x2EB9126C>("\xB3\x87\x9F\x98\x90\x82"+0x2EB9126C).s
#define WEAPON_LegitFire			/*Legit*/					XorStr<0x01,6,0x20653C67>("\x4D\x67\x64\x6D\x71"+0x20653C67).s
#define WEAPON_RageFire			    /*Rage Fire*/				XorStr<0x17,10,0xE4DD8CA3>("\x45\x79\x7E\x7F\x3B\x5A\x74\x6C\x7A"+0xE4DD8CA3).s
#define WEAPON_BulletTracer			/*Bullet Tracer*/			XorStr<0x62,14,0x1B766571>("\x20\x16\x08\x09\x03\x13\x48\x3D\x18\x0A\x0F\x08\x1C"+0x1B766571).s
#define WEAPON_CrosshairColor		/*Color*/					XorStr<0x5D,6,0x20D5E88D>("\x1E\x31\x33\x0F\x13"+0x20D5E88D).s
#define WEAPON_CrosshairColors		/*##CrosshairColor*/		XorStr<0x6E,17,0x06600F18>("\x4D\x4C\x33\x03\x1D\x00\x07\x1D\x17\x1E\x0A\x3A\x15\x17\x13\x0F"+0x06600F18).s
#define WEAPON_CrosshairType		/*Type*/					XorStr<0xA4,5,0x9D8678BB>("\xF0\xDC\xD6\xC2"+0x9D8678BB).s
#define WEAPON_CrosshairTypes		/*##CrosshairType*/			XorStr<0x6E,16,0x28D7BBA5>("\x4D\x4C\x33\x03\x1D\x00\x07\x1D\x17\x1E\x0A\x2D\x03\x0B\x19"+0x28D7BBA5).s
//Slider
#define WEAPON_LegitFireValue		/*##LegitFire*/				XorStr<0x4F,12,0xBB5F4D2C>("\x6C\x73\x1D\x37\x34\x3D\x21\x10\x3E\x2A\x3C"+0xBB5F4D2C).s
#define WEAPON_RemoveWeightValue	/*##Weight Value*/			XorStr<0x31,15,0xA96ABC80>("\x12\x11\x64\x51\x5C\x51\x5F\x4C\x19\x6C\x5A\x50\x48\x5B"+0xA96ABC80).s
#define WEAPON_MultiBulletValue		/*##Multi Value*/			XorStr<0xFE,14,0x98C790B8>("\xDD\xDC\x4D\x74\x6E\x77\x6D\x25\x50\x66\x64\x7C\x6F"+0x98C790B8).s
//Teleport
#define WEAPON_Teleport				/*Weapon Teleport*/			XorStr<0x58,16,0x094532EE>("\x0F\x3C\x3B\x2B\x33\x33\x7E\x0B\x05\x0D\x07\x13\x0B\x17\x12"+0x094532EE).s
#define WEAPON_Teleport_Menu		/*Position##TeleWeapon*/	XorStr<0x96,21,0x5130F302>("\xC6\xF8\xEB\xF0\xEE\xF2\xF3\xF3\xBD\xBC\xF4\xC4\xCE\xC6\xF3\xC0\xC7\xD7\xC7\xC7"+0x5130F302).s
#define WEAPON_Settings				/*TeleWeapon_Settings*/		XorStr<0x51,20,0xF95DB9D6>("\x05\x37\x3F\x31\x02\x33\x36\x28\x36\x34\x04\x0F\x38\x2A\x2B\x09\x0F\x05\x10"+0xF95DB9D6).s
#define WEAPON_Teleport_X			/*Position X*/				XorStr<0x19,11,0x3A2F89F1>("\x49\x75\x68\x75\x69\x77\x70\x4E\x01\x7A"+0x3A2F89F1).s
#define WEAPON_Teleport_Y			/*Position Y*/				XorStr<0xEA,11,0xBB8BCFDC>("\xBA\x84\x9F\x84\x9A\x86\x9F\x9F\xD2\xAA"+0xBB8BCFDC).s
#define WEAPON_Teleport_Z			/*Position Z*/				XorStr<0x9E,11,0xD8A9CD5C>("\xCE\xF0\xD3\xC8\xD6\xCA\xCB\xCB\x86\xFD"+0xD8A9CD5C).s
#pragma endregion
#pragma region SPECIAL MENU
//Menu
#define SPECIAL_MENU				/*Special*/					XorStr<0x08,8,0xCC16A420>("\x5B\x79\x6F\x68\x65\x6C\x62"+0xCC16A420).s
//Title
#define SPECIAL_TITLE_Spam			/*Spammer*/					XorStr<0x5F,8,0xC3BD7A58>("\x0C\x10\x00\x0F\x0E\x01\x17"+0xC3BD7A58).s
#define SPECIAL_TITLE_Others		/*Others*/					XorStr<0xCE,7,0x5D936BF2>("\x81\xBB\xB8\xB4\xA0\xA0"+0x5D936BF2).s
#define SPECIAL_TITLE_CreateRoom	/*Create Room*/				XorStr<0x3A,12,0xF3F20308>("\x79\x49\x59\x5C\x4A\x5A\x60\x13\x2D\x2C\x29"+0xF3F20308).s


#define SPECIAL_KickHack			/*Kick Hack*/				XorStr<0x27,10,0xD0E1E72E>("\x6C\x41\x4A\x41\x0B\x64\x4C\x4D\x44"+0xD0E1E72E).s
#define SPECIAL_NameFilter			/*Name Filter*/				XorStr<0x9A,12,0x522963D1>("\xD4\xFA\xF1\xF8\xBE\xD9\xC9\xCD\xD6\xC6\xD6"+0x522963D1).s
#define SPECIAL_RadioCooldown		/*No Radio Cooldown*/		XorStr<0xB1, 18, 0x28F04C22>("\xFF\xDD\x93\xE6\xD4\xD2\xDE\xD7\x99\xF9\xD4\xD3\xD1\xDA\xD0\xB7\xAF" + 0x28F04C22).s
#define SPECIAL_RadioAll			/*Radio To All*/			XorStr<0xDF,13,0xEE736861>("\x8D\x81\x85\x8B\x8C\xC4\xB1\x89\xC7\xA9\x85\x86"+0xEE736861).s

//CreateRoom
#define SPECIAL_CREATE_PermOne		/*##MainPerms*/				XorStr<0xD2,12,0x32AA5B88>("\xF1\xF0\x99\xB4\xBF\xB9\x88\xBC\xA8\xB6\xAF"+0x32AA5B88).s
#define SPECIAL_CREATE_PermOneCombo	/*##Permission1*/			XorStr<0xF9,14,0x9E73DB04>("\xDA\xD9\xAB\x99\x8F\x93\x96\x73\x72\x6B\x6C\x6A\x34"+0x9E73DB04).s
#define SPECIAL_CREATE_PermOneText	/*Change Main Permission*/	XorStr<0xE8,23,0x4435ABEE>("\xAB\x81\x8B\x85\x8B\x88\xCE\xA2\x91\x98\x9C\xD3\xA4\x90\x84\x9A\x91\x8A\x89\x92\x93\x93"+0x4435ABEE).s

#define SPECIAL_CREATE_PermTwo		/*##SecondPerms*/			XorStr<0x2F,14,0xC4D23ECA>("\x0C\x13\x62\x57\x50\x5B\x5B\x52\x67\x5D\x4B\x57\x48"+0xC4D23ECA).s
#define SPECIAL_CREATE_PermTwoCombo	/*##Permission2*/			XorStr<0x05,14,0x2CC0E22A>("\x26\x25\x57\x6D\x7B\x67\x62\x7F\x7E\x67\x60\x7E\x23"+0x2CC0E22A).s
#define SPECIAL_CREATE_PermTwoText	/*Change 2nd Permission*/	XorStr<0xBD,22,0x845BAD34>("\xFE\xD6\xDE\xAE\xA6\xA7\xE3\xF6\xAB\xA2\xE7\x98\xAC\xB8\xA6\xA5\xBE\xBD\xA6\xBF\xBF"+0x845BAD34).s

#pragma endregion
//////////////////////////////////////////////////////////////////
//																//
//						MENU SETTIGS							//
//																//
//////////////////////////////////////////////////////////////////
#define Other_CloseVC				/*Close VoiceChat*/			XorStr<0x51,16,0xE155023E>("\x12\x3E\x3C\x27\x30\x76\x01\x37\x30\x39\x3E\x1F\x35\x3F\x2B"+0xE155023E).s
#define Other_CloseGame				/*Close Game*/				XorStr<0x7A,11,0xF78ACC2A>("\x39\x17\x13\x0E\x1B\x5F\xC7\xE0\xEF\xE6"+0xF78ACC2A).s
#define Other_SaveF					/*Save Features*/			XorStr<0xBB,14,0x273D72EE>("\xE8\xDD\xCB\xDB\x9F\x86\xA4\xA3\xB7\xB1\xB7\xA3\xB4"+0x273D72EE).s
#define Other_LoadF					/*Load Features*/			XorStr<0xF2,14,0x0BE0E091>("\xBE\x9C\x95\x91\xD6\xB1\x9D\x98\x8E\x8E\x8E\x98\x8D"+0x0BE0E091).s
#define FontMenu					/*Arial*/					XorStr<0x06,6,0x51BD9A1A>("\x47\x75\x61\x68\x66"+0x51BD9A1A).s
//////////////////////////////////////////////////////////////////
//																//
//						OTHER XOR								//
//																//
//////////////////////////////////////////////////////////////////
#define sESP_Distance				/*[ %0.0f m ]*/				XorStr<0x64,12,0x89EC1694>("\x3F\x45\x43\x57\x46\x59\x0C\x4B\x01\x4D\x33"+0x89EC1694).s
#define sESP_Name					/*[ %s ]*/					XorStr<0xF3, 7, 0x11EF782F>("\xA8\xD4\xD0\x85\xD7\xA5" + 0x11EF782F).s