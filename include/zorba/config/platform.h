#ifndef ZORBA_PLATFORM_H
#define ZORBA_PLATFORM_H

#include <zorba/config/config.h>


#if defined (WIN32) && ! defined (CYGWIN)
# include "zorba/config/win32.h"
#endif


#if defined (APPLE)
# include "zorba/config/apple.h"
#endif

#if defined (__FreeBSD__)
# include "zorba/config/freebsd.h"
#endif

#if defined (UNIX)
# include "zorba/config/unix.h"
#endif

#if defined (CYGWIN)
# include "zorba/config/cygwin.h"
#endif

#endif
