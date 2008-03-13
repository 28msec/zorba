/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: Assert.h,v 1.2 2006/10/13 06:53:29 Paul Pedersen Exp $
 *
 *  Copyright 2005-2006 FLWOR Foundation.
 *
 */

// ZORBA_ASSERT (and the deprecated Assert) survive in release mode
// and raise errors via the Zorba error API

#ifndef ZORBA_ASSERT_H
#define ZORBA_ASSERT_H

#include <string>
#include "errors/error_factory.h"

#ifdef HAVE_EXECINFO_H
#include <execinfo.h>
#endif

namespace zorba {

class StackTracePrinter {
  public:
    StackTracePrinter()
    {
#ifdef HAVE_EXECINFO_H
#define TRACE_SIZE 25
      void *trace[TRACE_SIZE];
      int sz = backtrace(trace, TRACE_SIZE);
      char **syms = backtrace_symbols(trace, sz);
      for(int i = 0; i < sz; ++i) {
        std::cerr << syms[i] << std::endl;
      }
      free(syms);
#endif
    }
};

#ifdef __GNUC__
#define __ZORBA_ASSERT_aux4( ) __PRETTY_FUNCTION__
#else
#define __ZORBA_ASSERT_aux4( ) "?"
#endif
#define __ZORBA_ASSERT_aux3( line ) #line
#define __ZORBA_ASSERT_aux2( line ) __ZORBA_ASSERT_aux3( line )
#define __ZORBA_ASSERT_aux1( cond, line )       \
  do {\
    if (! (cond)) {\
      StackTracePrinter p; \
      ZorbaAssert (__FILE__ ":" __ZORBA_ASSERT_aux2 (line), __ZORBA_ASSERT_aux4(), #cond); \
    } \
  } while(0)
  
#define ZORBA_ASSERT( cond ) __ZORBA_ASSERT_aux1 (cond, __LINE__)


// Deprecated
//#define Assert( cond ) ZORBA_ASSERT (cond)

}	/* namespace zorba */
#endif	/* ZORBA_ASSERT_H */

