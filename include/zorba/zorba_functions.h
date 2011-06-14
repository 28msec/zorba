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

#ifndef ZORBA_FUNCTIONS_API_H
#define ZORBA_FUNCTIONS_API_H

#include <zorba/config.h>

namespace zorba {

class String;

namespace zfn {

///////////////////////////////////////////////////////////////////////////////

/**
 * Removes all leading and trailing whitespace characters.
 *
 * @param s The string to remove whitespace characters from.
 */
ZORBA_DLL_PUBLIC
void trim( String &s );

/**
 * Removes all leading and trailing specified characters.
 *
 * @param s The string to remove specified characters from.
 * @param chars The characters to remove.
 */
ZORBA_DLL_PUBLIC
void trim( String &s, const char *chars );

#if 0
ZORBA_DLL_PUBLIC
String    tokenize( String const &pattern, String const &flags,
                    size_type* startPos, bool* hasMatched ) const;
#endif

///////////////////////////////////////////////////////////////////////////////

} // namespace zfn
} // namespace zorba

#endif /* ZORBA_FUNCTIONS_API_H */
/* vim:set et sw=2 ts=2: */
