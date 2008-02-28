#ifndef ZORBA_COMMON_H
#define ZORBA_COMMON_H

#include <iostream>
#include <cassert>

#include <zorba/config/platform.h>

#ifdef WIN32
#include <windows.h>

#elif defined ZORBA_USE_PTHREAD_LIBRARY
#include <pthread.h>

#elif defined ZORBA_USE_BOOST_THREAD_LIBRARY
#include <boost/thread/tss.hpp>

#elif defined ZORBA_FOR_ONE_THREAD_ONLY

#else
#error Unsupported thread system. For Unix set ZORBA_THREAD="pthread" or "boost" or "singlethread" in cmake -D ZORBA_THREAD=...
#endif

#endif
