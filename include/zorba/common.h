#ifndef XQP_COMMON_H
#define XQP_COMMON_H

#include "zorba/config.h"

#include <iostream>
#include <cassert>

#ifdef WIN32
#include "util/win32/stdint.h"
#define		XQP_DLLEXPORT		__declspec( dllexport )
#else
#define		XQP_DLLEXPORT
#endif

#endif
