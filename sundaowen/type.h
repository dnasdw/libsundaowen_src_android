#ifndef LIBSUNDAOWEN_SUNDAOWEN_TYPE_H_
#define LIBSUNDAOWEN_SUNDAOWEN_TYPE_H_

#include "platform.h"

#if SDW_COMPILER == SDW_COMPILER_MSC
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <direct.h>
#include <io.h>
#else
#if defined(__APPLE__)
#include <mach-o/dyld.h>
#endif
#include <dirent.h>
#include <iconv.h>
#include <unistd.h>
#endif
#include <sys/stat.h>

#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#if SDW_COMPILER != SDW_COMPILER_MSC || (SDW_COMPILER == SDW_COMPILER_MSC && SDW_COMPILER_VERSION >= 1800)
#include <cinttypes>
#else
#ifndef _PFX_8
#define _PFX_8 "hh"
#endif
#ifndef _PFX_16
#define _PFX_16 "h"
#endif
#ifndef _PFX_32
#define _PFX_32 "l"
#endif
#ifndef _PFX_64
#define _PFX_64 "ll"
#endif
#ifndef PRId8
#define PRId8 _PFX_8 "d"
#endif
#ifndef PRId16
#define PRId16 _PFX_16 "d"
#endif
#ifndef PRId32
#define PRId32 _PFX_32 "d"
#endif
#ifndef PRId64
#define PRId64 _PFX_64 "d"
#endif
#ifndef PRIu8
#define PRIu8 _PFX_8 "u"
#endif
#ifndef PRIu16
#define PRIu16 _PFX_16 "u"
#endif
#ifndef PRIu32
#define PRIu32 _PFX_32 "u"
#endif
#ifndef PRIu64
#define PRIu64 _PFX_64 "u"
#endif
#ifndef PRIx8
#define PRIx8 _PFX_8 "x"
#endif
#ifndef PRIx16
#define PRIx16 _PFX_16 "x"
#endif
#ifndef PRIx32
#define PRIx32 _PFX_32 "x"
#endif
#ifndef PRIx64
#define PRIx64 _PFX_64 "x"
#endif
#ifndef PRIX8
#define PRIX8 _PFX_8 "X"
#endif
#ifndef PRIX16
#define PRIX16 _PFX_16 "X"
#endif
#ifndef PRIX32
#define PRIX32 _PFX_32 "X"
#endif
#ifndef PRIX64
#define PRIX64 _PFX_64 "X"
#endif
#endif
#include <climits>
#include <clocale>
#include <cmath>
#include <cstdarg>
#include <cstddef>
#if SDW_COMPILER != SDW_COMPILER_MSC || (SDW_COMPILER == SDW_COMPILER_MSC && SDW_COMPILER_VERSION >= 1600)
#include <cstdint>
#else
typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;
#endif
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#if SDW_COMPILER == SDW_COMPILER_MSC && SDW_COMPILER_VERSION >= 1600
#include <codecvt>
#endif
#include <deque>
#include <functional>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
#if SDW_COMPILER == SDW_COMPILER_MSC && SDW_COMPILER_VERSION < 1600
using namespace std::tr1;
#endif

typedef int8_t n8;
typedef int16_t n16;
typedef int32_t n32;
typedef int64_t n64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

#if SDW_COMPILER == SDW_COMPILER_MSC
#if SDW_COMPILER_VERSION < 1600
#define nullptr NULL
#endif
#if SDW_COMPILER_VERSION < 1600
typedef wchar_t Char16_t;
typedef wstring U16String;
#elif SDW_COMPILER_VERSION >= 1900
typedef u16 Char16_t;
typedef basic_string<Char16_t> U16String;
#else
typedef char16_t Char16_t;
typedef u16string U16String;
#endif
typedef wstring String;
typedef wregex Regex;
#define STR(x) L##x
#else
typedef char16_t Char16_t;
typedef u16string U16String;
typedef string String;
typedef regex Regex;
#define STR(x) x
#endif

#endif	// LIBSUNDAOWEN_SUNDAOWEN_TYPE_H_