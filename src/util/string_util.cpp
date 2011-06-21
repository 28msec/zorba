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

using namespace std;

namespace zorba {
namespace ztd {

///////////////////////////////////////////////////////////////////////////////

char* itoa( long long n, char *buf ) {
  //
  // This implementation is much faster than using sprintf(3).
  //
  char *s = buf;
  long long n_prev;
  do { 
    n_prev = n;
    n /= 10; 
    *s++ = "9876543210123456789" [ 9 + n_prev - n * 10 ];
  } while ( n );

  if ( n_prev < 0 ) *s++ = '-';
  *s = '\0';

  for ( char *t = buf; t < s; ++t ) {
    char const c = *--s; *s = *t; *t = c;
  }
  return buf;
}

char* itoa( unsigned long long n, char *buf ) {
  char *s = buf;
  unsigned long long n_prev;
  do { 
    n_prev = n;
    n /= 10; 
    *s++ = "0123456789" [ n_prev - n * 10 ];
  } while ( n );

  *s = '\0';

  for ( char *t = buf; t < s; ++t ) {
    char const c = *--s; *s = *t; *t = c;
  }
  return buf;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace zorba
/* vim:set et sw=2 ts=2: */
