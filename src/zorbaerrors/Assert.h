/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
// ZORBA_ASSERT (and the deprecated Assert) survive in release mode
// and raise errors via the Zorba error API

#ifndef ZORBA_ASSERT_H
#define ZORBA_ASSERT_H

#include <string>
#include <iostream>
#include <zorba/config.h>

#ifdef HAVE_EXECINFO_H
#include <execinfo.h>
#include <stdlib.h>
#endif

#include "zorbaerrors/errors.h"
#include "zorbaerrors/error_manager.h"

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
      ZORBA_ERROR_PARAM(XQP0005_SYSTEM_ASSERT_FAILED, #cond, __FILE__ ":" __ZORBA_ASSERT_aux2 (line)); \
    }                                                                   \
  } while(0)
  
#define ZORBA_ASSERT( cond ) __ZORBA_ASSERT_aux1 (cond, __LINE__)


}	/* namespace zorba */
#endif	/* ZORBA_ASSERT_H */

