#ifndef LIBSUNDAOWEN_SDW_FILE_H_
#define LIBSUNDAOWEN_SDW_FILE_H_

#include "sdw_platform.h"
#include "sdw_type.h"

#if SDW_PLATFORM == SDW_PLATFORM_WINDOWS
#define Chsize _chsize_s
#define Fileno _fileno
#define UFopen FopenW
#else
#define Chsize ftruncate
#define Fileno fileno
#define UFopen Fopen
#endif

void fu16printf(FILE* a_pFile, const wchar_t* a_szFormat, ...);

FILE* Fopen(const char* a_pFileName, const char* a_pMode, bool a_bVerbose = true);

#if SDW_PLATFORM == SDW_PLATFORM_WINDOWS
FILE* FopenW(const wchar_t* a_pFileName, const wchar_t* a_pMode, bool a_bVerbose = true);
#endif

#endif	// LIBSUNDAOWEN_SDW_FILE_H_
