/*-
 * Copyright (c) 1997, 1998, 2005, 2008 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code was contributed to The NetBSD Foundation by Klaus Klein.
 * Heavily optimised by David Laight
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

// standard
#include <cstring>
#include <stdexcept>
#ifdef WIN32
# include <windows.h>
#else
# include <tzfile.h>                    /* for TM_YEAR_BASE */
#endif /* WIN32 */

// Zorba
#include "ascii_util.h"
#include "cxx_util.h"
#include "string_util.h"
#include "zorbautils/locale.h"

// local
#include "strptime.h"

#ifndef TM_YEAR_BASE
# define TM_YEAR_BASE 1900
#endif

//
// We do not implement alternate representations. However, we always check
// whether a given modifier is allowed for a certain conversion.
//
int const ALT_E = 0x01;
int const ALT_O = 0x02;
#define CHECK_ALT(x)  do { if ( alt_format & ~(x) ) bad_alt( c ); } while (0)

using namespace std;

namespace zorba {
namespace ztd {

///////////////////////////////////////////////////////////////////////////////

struct rfc2822_obs_zone {
  char const *name;
  int gmtoff;
  bool isdst;
};

//
// See RFC 2822: "Internet Message Format," section 4.3, "Obsolete Date and
// Time."
//
static rfc2822_obs_zone const rfc2822_obs_zones[] = {
  { "GMT",  0                 },
  { "UTC",  0                 }, // non-RFC: be liberal in what you accept....
  { "UT" ,  0                 }, // must go after "UTC"
  { "EDT", -4 * 60 * 60, true },
  { "EST", -5 * 60 * 60       },
  { "CDT", -5 * 60 * 60, true },
  { "CST", -6 * 60 * 60       },
  { "MDT", -6 * 60 * 60, true },
  { "MST", -7 * 60 * 60       },
  { "PDT", -7 * 60 * 60, true },
  { "PST", -8 * 60 * 60       },
  0
};

///////////////////////////////////////////////////////////////////////////////

typedef char const* (*locale_fn_type)(unsigned);

static void bad_alt( char c ) {
  throw invalid_argument(
    BUILD_STRING( '\'', c, "': invalid alternate representation" )
  );
}

//
// This is an adapter function to adapt locale::get_time_ampm(bool) to a
// function that takes an unsigned parameter so that locale_find() can be used
// for it.
//
static char const* get_time_ampm( unsigned pm ) {
  return locale::get_time_ampm( pm );
}

static char const* locale_find( char conv_char, char const *bp,
                                locale_fn_type locale_fn,
                                unsigned limit, int *result ) {
  for ( int i = 0; i < limit; ++i ) {
    char const *const s = (*locale_fn)( i );
    size_t const len = ::strlen( s );
    if ( ::strncmp( bp, s, len ) == 0 ) {
      *result = i;
      return bp + len;
    }
  }
  throw invalid_argument( BUILD_STRING( "invalid value for %", conv_char ) );
}

static char const* parse_num( char conv_char, char const *bp,
                              unsigned low, unsigned high, int *result ) {
  char c = *bp;
  if ( !ascii::is_digit( c ) )
    throw invalid_argument(
      BUILD_STRING( '\'', c, "': invalid value for %", conv_char )
    );

  unsigned limit = high; // "high" also determines the number of digits
  unsigned n = 0;

  do {
    n *= 10;
    n += c - '0';
    limit /= 10;
    c = *++bp;
  } while ( (n * 10 <= high) && limit && ascii::is_digit( c ) );

  if ( n < low || n > high )
    throw invalid_argument(
      BUILD_STRING(
        n, ": value for %", conv_char, " not in range ", low, '-', high
      )
    );
  *result = n;
  return bp;
}

///////////////////////////////////////////////////////////////////////////////

char const* strptime( char const *buf, char const *fmt, ztm *tm ) {
  char const *bp = buf;
  char c;
  char const *recurse_fmt;
  bool split_year = false;

  while ( bp && (c = *fmt++) ) {
    if ( ascii::is_space( c ) ) {
      bp = ascii::trim_start_whitespace( bp );
      continue;
    }

    int alt_format = 0;
    int n = 0;

    if ( c != '%' ) {                   // literal
literal:
      CHECK_ALT(0);
      if ( *bp != c )
        throw invalid_argument(
          BUILD_STRING( "'", *bp, "': literal character mismatches '", c, '\'' )
        );
      ++bp;
      continue;
    }

again:
    switch ( c = *fmt++ ) {
      case '%':
        goto literal;

      case 'a': // abbreviated weekday name
        CHECK_ALT(0);
        bp = locale_find( c, bp, &locale::get_weekday_abbr, 7, &tm->tm_wday );
        break;

      case 'A': // full weekday name
        CHECK_ALT(0);
        bp = locale_find( c, bp, &locale::get_weekday_name, 7, &tm->tm_wday );
        break;

      case 'b': // abbreviated month name
      case 'h': // same as %b
        CHECK_ALT(0);
        bp = locale_find( c, bp, &locale::get_month_abbr, 12, &tm->tm_mon );
        break;

      case 'B': // full month name
        CHECK_ALT(0);
        bp = locale_find( c, bp, &locale::get_month_name, 12, &tm->tm_mon );
        break;

      case 'c': // date and time
        CHECK_ALT(ALT_E);
        recurse_fmt = locale::get_date_time_format();
        goto recurse;

      case 'C': // century number
        CHECK_ALT(ALT_E);
        n = 20;
        bp = parse_num( c, bp, 0, 99, &n );
        n = n * 100 - TM_YEAR_BASE;
        if ( split_year )
          n += tm->tm_year % 100;
        else
          split_year = true;
        tm->tm_year = n;
        break;

      case 'D':
        CHECK_ALT(0);
        recurse_fmt = "%m/%d/%y";
        goto recurse;

      case 'd': // day of month: 01-31
      case 'e': // day of month: 1-31
        CHECK_ALT(ALT_O);
        bp = parse_num( c, bp, 1, 31, &tm->tm_mday );
        break;

      case 'E': // "%E?" alternative conversion modifier
        alt_format = ALT_E;
        goto again;

      case 'F':
        CHECK_ALT(0);
        recurse_fmt = "%Y-%m-%d";
        goto recurse;

      case 'j': // day of year: 001-366
        CHECK_ALT(0);
        n = 1;
        bp = parse_num( c, bp, 1, 366, &n );
        tm->tm_yday = n - 1;
        break;

      case 'k': // hour: 0-23
        CHECK_ALT(0);
        // no break;
      case 'H': // hour: 00-23
        CHECK_ALT(ALT_O);
        bp = parse_num( c, bp, 0, 23, &tm->tm_hour );
        break;

      case 'l': // hour: 1-12
        CHECK_ALT(0);
        // no break;
      case 'I': // hour: 01-12
        CHECK_ALT(ALT_O);
        bp = parse_num( c, bp, 1, 12, &tm->tm_hour );
        if ( tm->tm_hour == 12 )
          tm->tm_hour = 0;
        break;

      case 'm': // month: 01-12
        CHECK_ALT(ALT_O);
        n = 1;
        bp = parse_num( c, bp, 1, 12, &n );
        tm->tm_mon = n - 1;
        break;

      case 'M': // minute: 00-59
        CHECK_ALT(ALT_O);
        bp = parse_num( c, bp, 0, 59, &tm->tm_min );
        break;

      case 'n': // newline
      case 't': // tab
        CHECK_ALT(0);
        bp = ascii::trim_start_whitespace( bp );
        break;

      case 'O': // "%O?" alternative conversion modifier
        alt_format = ALT_O;
        goto again;

      case 'p': // AM/PM
        CHECK_ALT(0);
        bp = locale_find( c, bp, &get_time_ampm, 2, &n );
        if ( tm->tm_hour > 11 )
          throw invalid_argument(
            "%p specified in format string more than once"
          );
        if ( n )
          tm->tm_hour += 12;
        break;

      case 'r':
        CHECK_ALT(0);
        recurse_fmt = "%I:%M:%S %p";
        goto recurse;

      case 'R':
        CHECK_ALT(0);
        recurse_fmt = "%H:%M";
        goto recurse;

      case 'S': // seconds: 00-60 (60 for leap second)
        CHECK_ALT(ALT_O);
        bp = parse_num( c, bp, 0, 60, &tm->tm_sec );
        break;

#if 0
      case 's': // number of seconds since epoch
        break;
#endif

      case 'T':
        CHECK_ALT(0);
        recurse_fmt = "%H:%M:%S";
        goto recurse;

      case 'u': // day of week, beginning on Monday: 1-7
        CHECK_ALT(ALT_O);
        bp = parse_num( c, bp, 1, 7, &n );
        tm->tm_wday = n == 7 ? 0 : n;
        break;

      case 'V': // week of year, beginning on Monday: 01-53
        CHECK_ALT(ALT_O);
        //
        // This is bogus since we can not assume any valid information present
        // in the tm structure at this point to calculate a real value, so just
        // check the range for now.
        //
        bp = parse_num( c, bp, 1, 53, &n );
        break;

      case 'U': // week of year, beginning on Sunday: 00-53
      case 'W': // week of year, beginning on Monday: 00-53
        CHECK_ALT(ALT_O);
        //
        // This is bogus since we can not assume any valid information present
        // in the tm structure at this point to calculate a real value, so just
        // check the range for now.
        //
        bp = parse_num( c, bp, 0, 53, &n );
        break;

      case 'v':
        CHECK_ALT(0);
        recurse_fmt = "%e-%b-%Y";
        goto recurse;

      case 'w': // day of week, beginning on Sunday: 0-6
        CHECK_ALT(ALT_O);
        bp = parse_num( c, bp, 0, 6, &tm->tm_wday );
        break;

      case 'x': // date
        CHECK_ALT(ALT_E);
        recurse_fmt = locale::get_date_format();
        goto recurse;

      case 'X': // time
        CHECK_ALT(ALT_E);
        recurse_fmt = locale::get_time_format();
        goto recurse;

      case 'y': // year within 100 years of the epoch
        CHECK_ALT(ALT_E | ALT_O);
        bp = parse_num( c, bp, 0, 99, &n );
        if ( split_year )               // preserve century
          n += (tm->tm_year / 100) * 100;
        else {
          split_year = true;
          if ( n <= 68 )
            n = n + 2000 - TM_YEAR_BASE;
          else
            n = n + 1900 - TM_YEAR_BASE;
        }
        tm->tm_year = n;
        break;

      case 'Y': // year: 0-9999
        CHECK_ALT(ALT_E);
        n = TM_YEAR_BASE;
        bp = parse_num( c, bp, 0, 9999, &n );
        tm->tm_year = n - TM_YEAR_BASE;
        break;

      case 'z': { // RFC 2822 timezone offset or name: [+|-]HHMM | ZZZ
        CHECK_ALT(0);
        int sign = 0;
        if ( *bp == '+' )
          sign = 1;
        else if ( *bp == '-' )
          sign = -1;
        if ( sign )
          ++bp;

        if ( ascii::is_digit( *bp ) ) { // start of HHMM
          int hour = (*bp - '0') * 10;
          if ( !ascii::is_digit( *++bp ) )
            goto bad_tz;
          hour += *bp - '0';
          if ( !ascii::is_digit( *++bp ) )
            goto bad_tz;
          int minute = (*bp - '0') * 10;
          if ( !ascii::is_digit( *++bp ) )
            goto bad_tz;
          minute += *bp - '0';
          int gmtoff = hour * 60 * 60 + minute * 60;
          if ( sign )
            gmtoff *= sign;
          set_gmtoff( *tm, gmtoff );
          break;
        } else if ( sign )              // sign followed by non-digit
bad_tz:   throw invalid_argument( "invalid 4-digit timezone offset" );
        // no break;
      } // case 'z'

      case 'Z': { // RFC 2822 timezone name only: ZZZ
        CHECK_ALT(0);
        for ( rfc2822_obs_zone const *z = rfc2822_obs_zones; z->name; ++z ) {
          size_t const len = ::strlen( z->name );
          if ( ::strncmp( bp, z->name, len ) == 0 ) {
            set_gmtoff( *tm, z->gmtoff );
            tm->tm_isdst = z->isdst;
            bp += len;
            goto next_outer_loop;
          }
        }
        char bad_tz[4];
        ::memset( bad_tz, 0, sizeof( bad_tz ) );
        ::strncpy( bad_tz, bp, 3 );     // assume 3
        throw invalid_argument(
          BUILD_STRING( '"', bad_tz, "\": unrecognized timezone" )
        );
      } // case 'Z'

      default: // unknown/unsupported conversion
        throw invalid_argument( BUILD_STRING( '%', c, ": invalid %") );
    } // switch

next_outer_loop:
    continue;

recurse:
    bp = ztd::strptime( bp, recurse_fmt, tm );
  } // while

  return bp;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace zorba
/* vim:set et sw=2 ts=2: */
