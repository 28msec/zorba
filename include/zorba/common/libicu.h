#ifndef ZORBA_LIBICU_H

#if defined CYGWIN
#  define U_HAVE_INTTYPES 0
#  define U_HAVE_INT8_T 1
#  define U_HAVE_INT32_T 1
#  define U_HAVE_UINT32_T 1
#endif

#include <unicode/utypes.h>
#include <unicode/coll.h>
#include <unicode/ustring.h>
#include <unicode/stsearch.h>
#include <unicode/ucnv.h>
#include <unicode/normlzr.h>
#endif
