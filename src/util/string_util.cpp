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
#include "cxx_util.h"
#include "string_util.h"
#include "zorbatypes/zstring.h"

#ifdef WIN32
namespace std {

  // Windows doesn't have these functions -- add them ourselves.

  static float strtof( char const *s, char **last ) {
    double const result = std::strtod( s, last );
    if ( !errno ) {
      if ( result < std::numeric_limits<float>::min() ||
           result > std::numeric_limits<float>::max() )
        errno = ERANGE;
    }
    return static_cast<float>( result );
  }

  inline long long strtoll( char const *s, char **last, int base ) {
    return ::_strtoi64( s, last, base );
  }

  inline unsigned long long strtoull( char const *s, char **last, int base ) {
    return ::_strtoui64( s, last, base );
  }

} // namespace std
#endif /* WIN32 */

using namespace std;

namespace zorba {
namespace ztd {

///////////////////////////////////////////////////////////////////////////////

static void too_big_or_small( char const *buf, char const *last ) {
  zstring const s( buf, last );
  throw std::range_error( BUILD_STRING( '"', s, "\": number too big/small" ) );
}

inline void check_errno( char const *buf, char const *last ) {
  if ( errno == ERANGE )
    too_big_or_small( buf, last );
}

static void check_trailing_chars_impl( char const *last ) {
  for ( ; *last; ++last )               // remaining characters, if any, ...
    if ( !ascii::is_space( *last ) )    // ... may only be whitespace
      throw std::invalid_argument(
        BUILD_STRING( '\'', *last, "': invalid character" )
      );
}

inline void check_parse_number( char const *buf, char const *last,
                                bool check_trailing_chars ) {
  if ( last == buf )
    throw std::invalid_argument( BUILD_STRING( '"', buf, "\": no digits" ) );
  if ( check_trailing_chars )
    check_trailing_chars_impl( last );
}

class aton_context {
public:
  aton_context( char const **&last ) {
    if ( last ) {
      check_trailing_chars_ = false;
    } else {
      last = &last_;
      check_trailing_chars_ = true;
    }
    errno = 0;
  }
  bool check_trailing_chars() const {
    return check_trailing_chars_;
  }
private:
  bool check_trailing_chars_;
  char const *last_;
};

///////////////////////////////////////////////////////////////////////////////

double atod( char const *buf, char const **last ) {
  aton_context const ctx( last );
  double const result = std::strtod( buf, (char**)last );
  check_parse_number( buf, *last, ctx.check_trailing_chars() );
  return result;
}

float atof( char const *buf, char const **last ) {
  aton_context const ctx( last );
  float const result = std::strtof( buf, (char**)last );
  check_parse_number( buf, *last, ctx.check_trailing_chars() );
  return result;
}

long long atoll( char const *buf, char const **last ) {
  aton_context const ctx( last );
  long long const result = std::strtoll( buf, (char**)last, 10 );
  check_errno( buf, *last );
  check_parse_number( buf, *last, ctx.check_trailing_chars() );
  return result;
}

unsigned long long atoull( char const *buf, char const **last ) {
  aton_context const ctx( last );
  //
  // We have to check for '-' ourselves since strtoull(3) allows it (oddly).
  //
  buf = ascii::trim_start_whitespace( buf );
  bool const minus = *buf == '-';

  unsigned long long const result = std::strtoull( buf, (char**)last, 10 );
  check_errno( buf, *last );
  check_parse_number( buf, *last, ctx.check_trailing_chars() );

  if ( minus && result ) {
    //
    // Throw an exception only if there was a '-' and the result is non-zero.
    // Hence, this allows "-0" and treats it as "0".
    //
    throw std::invalid_argument(
      "'-': invalid character for unsigned integer"
    );
  }
  return result;
}

unsigned long long atoull( char const *buf, char const *end,
                           char const **last ) {
  aton_context const ctx( last );
  unsigned long long n = 0;
  char const *s = buf;

  for ( ; s < end && ascii::is_space( *s ); ++s )
    ;
  for ( ; s < end && ascii::is_digit( *s ); ++s ) {
    unsigned long long const n_prev = n;
    n = n * 10 + *s - '0';
    if ( n < n_prev ) {
      errno = ERANGE;
      too_big_or_small( buf, end );
    }
  }
  *last = s;
  check_parse_number( buf, *last, ctx.check_trailing_chars() );
  return n;
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
