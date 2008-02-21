#ifndef XQP_ZORBA_COMMON_H
#define XQP_ZORBA_COMMON_H

#include <iostream>
#include <cassert>

#include "zorba/config/platform.h"

#ifdef WIN32
#elif defined ZORBA_USE_PTHREAD_LIBRARY
#elif defined ZORBA_USE_BOOST_THREAD_LIBRARY
#elif defined ZORBA_FOR_ONE_THREAD_ONLY
#else
#error Unsupported thread system. For Unix set ZORBA_THREAD="pthread" or "boost" or "singlethread" in cmake -D ZORBA_THREAD=...
#endif

#endif
