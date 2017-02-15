#include "sdw_string.h"

#if SDW_COMPILER == SDW_COMPILER_MSC
#if SDW_COMPILER_VERSION < 1600
string WToU8(const wstring& a_sString)
{
	n32 nLength = WideCharToMultiByte(CP_UTF8, 0, a_sString.c_str(), -1, nullptr, 0, nullptr, nullptr);
	char* pTemp = new char[nLength];
	WideCharToMultiByte(CP_UTF8, 0, a_sString.c_str(), -1, pTemp, nLength, nullptr, nullptr);
	string sString = pTemp;
	delete[] pTemp;
	return sString;
}

string U16ToU8(const U16String& a_sString)
{
	return WToU8(a_sString);
}

wstring U8ToW(const string& a_sString)
{
	n32 nLength = MultiByteToWideChar(CP_UTF8, 0, a_sString.c_str(), -1, nullptr, 0);
	wchar_t* pTemp = new wchar_t[nLength];
	MultiByteToWideChar(CP_UTF8, 0, a_sString.c_str(), -1, pTemp, nLength);
	wstring sString = pTemp;
	delete[] pTemp;
	return sString;
}

wstring U16ToW(const U16String& a_sString)
{
	return a_sString;
}

U16String U8ToU16(const string& a_sString)
{
	return U8ToW(a_sString);
}

U16String WToU16(const wstring& a_sString)
{
	return a_sString;
}
#else
string WToU8(const wstring& a_sString)
{
	static wstring_convert<codecvt_utf8<wchar_t>> c_cvt_u8;
	return c_cvt_u8.to_bytes(a_sString);
}

string U16ToU8(const U16String& a_sString)
{
	static wstring_convert<codecvt_utf8_utf16<Char16_t>, Char16_t> c_cvt_u8_u16;
	return c_cvt_u8_u16.to_bytes(a_sString);
}

wstring U8ToW(const string& a_sString)
{
	static wstring_convert<codecvt_utf8<wchar_t>> c_cvt_u8;
	return c_cvt_u8.from_bytes(a_sString);
}

wstring U16ToW(const U16String& a_sString)
{
	return U8ToW(U16ToU8(a_sString));
}

U16String U8ToU16(const string& a_sString)
{
	static wstring_convert<codecvt_utf8_utf16<Char16_t>, Char16_t> c_cvt_u8_u16;
	return c_cvt_u8_u16.from_bytes(a_sString);
}

U16String WToU16(const wstring& a_sString)
{
	return U8ToU16(WToU8(a_sString));
}
#endif
#else
string WToU8(const wstring& a_sString)
{
	return TToT<wstring, string>(a_sString, "WCHAR_T", "UTF-8");
}

string U16ToU8(const U16String& a_sString)
{
	return TToT<U16String, string>(a_sString, "UTF-16LE", "UTF-8");
}

wstring U8ToW(const string& a_sString)
{
	return TToT<string, wstring>(a_sString, "UTF-8", "WCHAR_T");
}

wstring U16ToW(const U16String& a_sString)
{
	return TToT<U16String, wstring>(a_sString, "UTF-16LE", "WCHAR_T");
}

U16String U8ToU16(const string& a_sString)
{
	return TToT<string, U16String>(a_sString, "UTF-8", "UTF-16LE");
}

U16String WToU16(const wstring& a_sString)
{
	return TToT<wstring, U16String>(a_sString, "WCHAR_T", "UTF-16LE");
}
#endif

static const n32 s_nFormatBufferSize = 4096;

string FormatV(const char* a_szFormat, va_list a_vaList)
{
	static char c_szBuffer[s_nFormatBufferSize] = {};
	vsnprintf(c_szBuffer, s_nFormatBufferSize, a_szFormat, a_vaList);
	return c_szBuffer;
}

wstring FormatV(const wchar_t* a_szFormat, va_list a_vaList)
{
	static wchar_t c_szBuffer[s_nFormatBufferSize] = {};
	vswprintf(c_szBuffer, s_nFormatBufferSize, a_szFormat, a_vaList);
	return c_szBuffer;
}

string Format(const char* a_szFormat, ...)
{
	va_list vaList;
	va_start(vaList, a_szFormat);
	string sFormatted = FormatV(a_szFormat, vaList);
	va_end(vaList);
	return sFormatted;
}

wstring Format(const wchar_t* a_szFormat, ...)
{
	va_list vaList;
	va_start(vaList, a_szFormat);
	wstring sFormatted = FormatV(a_szFormat, vaList);
	va_end(vaList);
	return sFormatted;
}
