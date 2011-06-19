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
#include "stdafx.h"

#include "string_util.h"

namespace zorba {
namespace ztd {

///////////////////////////////////////////////////////////////////////////////

char* lltoa( long long n, char *buf ) {
  //
  // See: Brian W. Kernighan, Dennis M. Ritchie. "The C Programming Language,
  // 2nd ed."  Addison-Wesley, Reading, MA, 1988. pp. 63-64.
  //
  bool const is_neg = n < 0;
  if ( is_neg ) n = -n;
  char *s = buf;
  do {                                  // generate digits in reverse
    *s++ = static_cast<char>( n % 10 + '0' );
  } while ( n /= 10 );
  if ( is_neg ) *s++ = '-';
  *s = '\0';

  for ( char *t = buf; t < s; ++t ) {   // now reverse the string
    char const temp = *--s; *s = *t; *t = temp;
  }
  return buf;
}

char* lltoa( unsigned long long n, char *buf ) {
  //
  // See: Brian W. Kernighan, Dennis M. Ritchie. "The C Programming Language,
  // 2nd ed."  Addison-Wesley, Reading, MA, 1988. pp. 63-64.
  //
  char *s = buf;
  do {                                  // generate digits in reverse
    *s++ = static_cast<char>( n % 10 + '0' );
  } while ( n /= 10 );
  *s = '\0';

  for ( char *t = buf; t < s; ++t ) {   // now reverse the string
    char const temp = *--s; *s = *t; *t = temp;
  }
  return buf;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace zorba
/* vim:set et sw=2 ts=2: */
