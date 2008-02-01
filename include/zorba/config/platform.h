#ifndef XQP_PLATFORM_H
#define XQP_PLATFORM_H

#if defined (__WIN32__)
# include "zorba/config/win32.h"
#endif

#if defined (__APPLE__)
# include "zorba/config/apple.h"
#endif

#if defined (__FreeBSD__)
# include "zorba/config/freebsd.h"
#endif

#if defined (__UNIX__)
# include "zorba/config/unix.h"
#endif

#if defined (__CYWIN__)
# include "zorba/config/cygwin.h"
#endif

#endif
