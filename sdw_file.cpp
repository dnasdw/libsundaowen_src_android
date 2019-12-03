#include "sdw_file.h"
#include "sdw_string.h"

void fu16printf(FILE* a_pFile, const wchar_t* a_szFormat, ...)
{
	va_list vaList;
	va_start(vaList, a_szFormat);
	wstring sFormatted = FormatV(a_szFormat, vaList);
	va_end(vaList);
	U16String sString = WToU16(sFormatted);
	fwrite(sString.c_str(), 2, sString.size(), a_pFile);
}

FILE* Fopen(const char* a_pFileName, const char* a_pMode, bool a_bVerbose /* = true */)
{
	FILE* fp = fopen(a_pFileName, a_pMode);
	if (fp == nullptr && a_bVerbose)
	{
#if !defined(SDW_ANDROID_HIDE_LOG_STRING)
		printf("ERROR: open file %s failed\n\n", a_pFileName);
#endif
	}
	return fp;
}

#if SDW_PLATFORM == SDW_PLATFORM_WINDOWS
FILE* FopenW(const wchar_t* a_pFileName, const wchar_t* a_pMode, bool a_bVerbose /* = true */)
{
	FILE* fp = _wfopen(a_pFileName, a_pMode);
	if (fp == nullptr && a_bVerbose)
	{
#if !defined(SDW_ANDROID_HIDE_LOG_STRING)
		wprintf(L"ERROR: open file %ls failed\n\n", a_pFileName);
#endif
	}
	return fp;
}
#endif
