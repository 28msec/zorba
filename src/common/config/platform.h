#ifndef ZORBA_PLATFORM_H
#define ZORBA_PLATFORM_H

#include "common/config/config.h"

#if (defined (WIN32) || defined (WINCE)) && ! defined (CYGWIN)
# include "common/config/win32.h"
#endif

#if defined (APPLE)
# include "common/config/apple.h"
#endif

#if defined (__FreeBSD__)
# include "common/config/freebsd.h"
#endif

#if defined (UNIX)
# include "common/config/unix.h"
#endif

#if defined (CYGWIN)
# include "common/config/cygwin.h"
#endif

#endif
