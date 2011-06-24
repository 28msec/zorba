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

#include <cerrno>
#include <cstdlib>

#include "ascii_util.h"
#include "string_util.h"

#ifdef WIN32
namespace std {
  inline long long strtoll( char const *s, char **end, int base ) {
    return ::_strtoi64( s, end, base );
  }

  inline long long strtoull( char const *s, char **end, int base ) {
    return ::_strtoui64( s, end, base );
  }
}
#endif /* WIN32 */

using namespace std;

namespace zorba {
namespace ztd {

///////////////////////////////////////////////////////////////////////////////

long long atoll( char const *s ) {
  char *end;
  long long const result = std::strtoll( s, &end, 10 );
  if ( errno == ERANGE )
    throw std::range_error(
      BUILD_STRING( '"', s, "\": number too big/small" )
    );
  if ( end == s )
    throw std::invalid_argument( BUILD_STRING( '"', s, "\": no digits" ) );
  for ( ; *end; ++end )                 // remaining characters, if any, ...
    if ( !ascii::is_space( *end ) )     // ... may only be whitespace
      throw std::invalid_argument(
        BUILD_STRING( '"', *end, "\": invalid character" )
      );
  return result;
}

unsigned long long atoull( char const *s ) {
  char *end;
  unsigned long long const result = std::strtoull( s, &end, 10 );
  if ( errno == ERANGE )
    throw std::range_error(
      BUILD_STRING( '"', s, "\": number too big" )
    );
  if ( end == s )
    throw std::invalid_argument( BUILD_STRING( '"', s, "\": no digits" ) );
  for ( ; *end; ++end )                 // remaining characters, if any, ...
    if ( !ascii::is_space( *end ) )     // ... may only be whitespace
      throw std::invalid_argument(
        BUILD_STRING( '"', *end, "\": invalid character" )
      );
  return result;
}

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
