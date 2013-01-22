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

  static float strtof( char const *s, char **end ) {
    double const result = std::strtod( s, end );
    if ( !errno ) {
      if ( result < std::numeric_limits<float>::min() ||
           result > std::numeric_limits<float>::max() )
        errno = ERANGE;
    }
    return static_cast<float>( result );
  }

  inline long long strtoll( char const *s, char **end, int base ) {
    return ::_strtoi64( s, end, base );
  }

  inline unsigned long long strtoull( char const *s, char **end, int base ) {
    return ::_strtoui64( s, end, base );
  }

} // namespace std
#endif /* WIN32 */

using namespace std;

namespace zorba {
namespace ztd {

///////////////////////////////////////////////////////////////////////////////

static void no_digits( char const *buf ) {
  throw std::invalid_argument( BUILD_STRING( '"', buf, "\": no digits" ) );
}

static void too_big_or_small( char const *buf, char const *end ) {
  zstring const s( buf, end );
  throw std::range_error( BUILD_STRING( '"', s, "\": number too big/small" ) );
}

inline void check_errno( char const *buf, char const *end ) {
  if ( errno == ERANGE )
    too_big_or_small( buf, end );
}

static void check_trailing_chars_impl( char const *end ) {
  for ( ; *end; ++end )                 // remaining characters, if any, ...
    if ( !ascii::is_space( *end ) )     // ... may only be whitespace
      throw std::invalid_argument(
        BUILD_STRING( '\'', *end, "': invalid character" )
      );
}

inline void check_parse_number( char const *buf, char const *end,
                                bool check_trailing_chars ) {
  if ( end == buf )
    no_digits( buf );
  if ( check_trailing_chars )
    check_trailing_chars_impl( end );
}

class aton_context {
public:
  aton_context( char const **&end ) {
    if ( end ) {
      check_trailing_chars_ = false;
    } else {
      end = &end_;
      check_trailing_chars_ = true;
    }
    errno = 0;
  }
  bool check_trailing_chars() const {
    return check_trailing_chars_;
  }
private:
  bool check_trailing_chars_;
  char const *end_;
};

///////////////////////////////////////////////////////////////////////////////

double atod( char const *buf, char const **end ) {
  aton_context const ctx( end );
  double const result = std::strtod( buf, (char**)end );
  check_parse_number( buf, *end, ctx.check_trailing_chars() );
  return result;
}

float atof( char const *buf, char const **end ) {
  aton_context const ctx( end );
  float const result = std::strtof( buf, (char**)end );
  check_parse_number( buf, *end, ctx.check_trailing_chars() );
  return result;
}

long long atoll( char const *buf, char const **end ) {
  aton_context const ctx( end );
  long long const result = std::strtoll( buf, (char**)end, 10 );
  check_errno( buf, *end );
  check_parse_number( buf, *end, ctx.check_trailing_chars() );
  return result;
}

unsigned long long atoull( char const *buf, char const **end ) {
  aton_context const ctx( end );
  //
  // We have to check for '-' ourselves since strtoull(3) allows it (oddly).
  //
  buf = ascii::trim_start_whitespace( buf );
  bool const minus = *buf == '-';

  unsigned long long const result = std::strtoull( buf, (char**)end, 10 );
  check_errno( buf, *end );
  check_parse_number( buf, *end, ctx.check_trailing_chars() );

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
