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

#pragma once
#ifndef ZORBA_FATAL_H
#define ZORBA_FATAL_H

#include <string>

#include "util/string_util.h"

namespace zorba {

/**
 * Helper function for the ZORBA_FATAL() macro.  This is called only if the
 * condition fails.  This function calls abort(3).
 *
 * @param condition The string representation of the condition that failed.
 * @param file The C++ source-code file name where the condition failed.
 * @param line The C++ source-code line number where the condition failed.
 */
void fatal( char const *condition, char const *file, int line,
            char const *msg );

#define ZORBA_FATAL(COND,MSG)                                 \
  do {                                                        \
    if ( !(COND) ) {                                          \
      std::string const msg( BUILD_STRING( MSG ) );           \
      zorba::fatal( #COND, __FILE__, __LINE__, msg.c_str() ); \
      throw 0; /* never gets here but suppresses warning */   \
    }                                                         \
  } while (0)

} // namespace zorba
#endif /* ZORBA_FATAL_H */
/* vim:set et sw=2 ts=2: */
