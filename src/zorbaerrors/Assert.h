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

namespace zorba {

void assertion_failed( char const *condition, char const *file, int line );

#define ZORBA_ASSERT(COND)                                  \
  do {                                                      \
    if ( !(COND) ) {                                        \
      assertion_failed( #COND, __FILE__, __LINE__ );        \
      throw 0; /* never gets here but suppresses warning */ \
    }                                                       \
  } while (0)

} // namespace zorba
#endif /* ZORBA_ASSERT_H */
/* vim:set et sw=2 ts=2: */
