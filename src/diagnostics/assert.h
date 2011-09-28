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
#pragma once
#ifndef ZORBA_ASSERT_H
#define ZORBA_ASSERT_H

namespace zorba {

/**
 * Helper function for the ZORBA_ASSERT() macro.  This is called only if an
 * assertion fails.
 *
 * @param condition The string representation of the condition that failed.
 * @param file The C++ source-code file name where the assertion failed.
 * @param line The C++ source-code line number where the assertion failed.
 * @throws ZXQP0002_ASSERT_FAILED
 */
void assertion_failed( char const *condition, char const *file, int line );

/**
 * Zorba version of the standard assert(3) macro.
 */
#define ZORBA_ASSERT(COND)                                  \
  do {                                                      \
    if ( !(COND) ) {                                        \
      zorba::assertion_failed( #COND, __FILE__, __LINE__ ); \
      throw 0; /* never gets here but suppresses warning */ \
    }                                                       \
  } while (0)

} // namespace zorba
#endif /* ZORBA_ASSERT_H */
/* vim:set et sw=2 ts=2: */
