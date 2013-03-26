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
  char const *s = ascii::trim_start_whitespace( buf, end - buf );

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

///////////////////////////////////////////////////////////////////////////////

namespace english_impl {

// Based on code from:
// http://www.cprogramming.com/challenges/integer-to-english-sol.html

static zstring const ones[][2] = {
  { "",          ""            },
  { "one",       "first"       },
  { "two",       "second"      },
  { "three",     "third"       },
  { "four",      "fourth"      },
  { "five",      "fifth"       },
  { "six",       "sixth"       },
  { "seven",     "seventh"     },
  { "eight",     "eighth"      },
  { "nine",      "ninth"       },
  { "ten",       "tenth"       },
  { "eleven",    "eleventh"    },
  { "twelve",    "twelfth"     },
  { "thirteen",  "thirteenth"  },
  { "fourteen",  "fourteenth"  },
  { "fifteen",   "fifteenth"   },
  { "sixteen",   "sixteenth"   },
  { "seventeen", "seventeenth" },
  { "eighteen",  "eighteenth"  },
  { "nineteen",  "nineteenth"  }
};

static zstring const tens[][2] = {
  { "",        ""           },
  { "",        ""           },
  { "twenty",  "twentieth"  },
  { "thirty",  "thirtieth"  },
  { "forty",   "fortieth"   },
  { "fifty",   "fiftieth"   },
  { "sixty",   "sixtieth"   },
  { "seventy", "seventieth" },
  { "eighty",  "eighteenth" },
  { "ninety",  "ninetieth"  }
};

// Enough entries to print English for 64-bit integers.
static zstring const big[][2] = {
  { "",            ""              },
  { "thousand",    "thousandth"    },
  { "million",     "millionth"     },
  { "billion",     "billionth"     },
  { "trillion",    "trillionth"    },
  { "quadrillion", "quadrillionth" },
  { "quintillion", "quintillionth" }
};

inline zstring if_space( zstring const &s ) {
  return s.empty() ? "" : ' ' + s;
}

static zstring hundreds( int64_t n, bool ordinal ) {
  if ( n < 20 )
    return ones[ n ][ ordinal ];
  zstring const tmp( if_space( ones[ n % 10 ][ ordinal ] ) );
  return tens[ n / 10 ][ ordinal && tmp.empty() ] + tmp;
}

} // namespace english_impl

zstring english( int64_t n, bool ordinal ) {
  using namespace english_impl;

  if ( !n )
    return ordinal ? "zeroth" : "zero";

  bool const negative = n < 0;
  if ( negative )
    n = -n;

  int big_count = 0;
  bool big_ordinal = ordinal;
  zstring r;

  while ( n ) {
    if ( int64_t const m = n % 1000 ) {
      zstring s;
      if ( m < 100 )
        s = hundreds( m, ordinal );
      else {
        zstring const tmp( if_space( hundreds( m % 100, ordinal ) ) );
        s = ones[ m / 100 ][0] + ' '
          + (ordinal && tmp.empty() ? "hundredth" : "hundred") + tmp;
      }
      zstring const tmp( if_space( r ) );
      r = s + if_space( big[ big_count ][ big_ordinal && tmp.empty() ] + tmp );
      big_ordinal = false;
    }
    n /= 1000;
    ++big_count;
    ordinal = false;
  }

  if ( negative )
    r = "negative " + r;
  return r;
}

char const* ordinal( long long n ) {
  n = std::abs( n );
  switch ( n % 100 ) {
    case 11:
    case 12:
    case 13:
      break;
    default:
      switch ( n % 10 ) {
        case 1: return "st";
        case 2: return "nd";
        case 3: return "rd";
      }
  }
  return "th";
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace zorba
/* vim:set et sw=2 ts=2: */
