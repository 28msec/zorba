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
#include <iostream>
#include "common/config/config.h"

#ifdef HAVE_EXECINFO_H
#include <execinfo.h>
#include <stdlib.h>
#endif

#include "errors/errors.h"
#include "errors/error_manager.h"

namespace zorba {

class StackTracePrinter {
public:
  StackTracePrinter(std::ostream *is)
  {
#ifdef HAVE_EXECINFO_H
#define TRACE_SIZE 25
    void *trace[TRACE_SIZE];
    int sz = backtrace(trace, TRACE_SIZE);
    char **syms = backtrace_symbols(trace, sz);
    for(int i = 0; i < sz; ++i)
      *is << syms[i] << std::endl;
    free(syms);
#undef TRACE_SIZE
#endif
  }
};

#define __ZORBA_ASSERT_aux3( line ) #line
#define __ZORBA_ASSERT_aux2( line ) __ZORBA_ASSERT_aux3( line )
#define __ZORBA_ASSERT_aux1( cond, line )                               \
  do {                                                                  \
    if (! (cond)) {                                                     \
      StackTracePrinter p (&std::cerr);                                 \
      ZORBA_ERROR_PARAM(::zorba::ZorbaError::XQP0005_SYSTEM_ASSERT_FAILED, #cond, __FILE__ ":" __ZORBA_ASSERT_aux2 (line)); \
    }                                                                   \
  } while(0)
  
#define ZORBA_ASSERT( cond ) __ZORBA_ASSERT_aux1 (cond, __LINE__)


}	/* namespace zorba */
#endif	/* ZORBA_ASSERT_H */

