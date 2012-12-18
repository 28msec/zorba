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

// standard
#include <cstring>
#include <stdexcept>
#include <string>
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

using namespace std;

namespace zorba {
namespace ztd {

///////////////////////////////////////////////////////////////////////////////

time_exception::time_exception( string const &msg ) :
  invalid_argument( msg )
{
}

time_exception::~time_exception() throw() {
  // out-of-line since it's virtual
}

invalid_specification::invalid_specification( char spec ) :
  time_exception(
    BUILD_STRING( '\'', ascii::printable_char( spec ), "': invalid %" )
  ),
  spec_( spec )
{
}

invalid_specification::~invalid_specification() throw() {
  // out-of-line since it's virtual
}

invalid_value_specs::invalid_value_specs( char spec ) :
  specs_( 1, spec )
{
}

invalid_value_specs::invalid_value_specs( char const *specs ) :
  specs_( specs )
{
}

invalid_value_value::invalid_value_value( char c ) :
  value_( 1, c )
{
}

invalid_value_value::invalid_value_value( char const *buf, size_t len ) :
  value_( buf, len )
{
  ascii::trim_end_whitespace( value_ );
}

template<typename ValueType>
invalid_value_value::invalid_value_value( ValueType const &value ) :
  value_( BUILD_STRING( value ) )
{
}

std::string invalid_value::build_msg( string const &value,
                                      string const &specs ) {
  return BUILD_STRING( '"', value, "\": invalid value for %", specs );
}

invalid_value::invalid_value( char const *buf, size_t len, char spec ) :
  invalid_value_value( buf, len ),
  invalid_value_specs( spec ),
  time_exception( build_msg( value_, specs_ ) )
{
}

invalid_value::invalid_value( char const *buf, size_t len, char const *specs ) :
  invalid_value_value( buf, len ),
  invalid_value_specs( specs ),
  time_exception( build_msg( value_, specs_ ) )
{
}

template<typename ValueType>
invalid_value::invalid_value( ValueType const &value, char spec ) :
  invalid_value_value( value ),
  invalid_value_specs( spec ),
  time_exception( build_msg( value_, specs_ ) )
{
}

template<typename ValueType>
invalid_value::invalid_value( ValueType const &value, char const *specs ) :
  invalid_value_value( value ),
  invalid_value_specs( specs ),
  time_exception( build_msg( value_, specs_ ) )
{
}

invalid_value::~invalid_value() throw() {
  // out-of-line since it's virtual
}

literal_mismatch::literal_mismatch( char expected, char got ) :
  time_exception(
    BUILD_STRING(
      '\'', ascii::printable_char( got ), "': literal character mismatched '",
      expected, '\''
    )
  ),
  expected_( expected ),
  got_( got )
{
}

literal_mismatch::~literal_mismatch() throw() {
  // out-of-line since it's virtual
}

///////////////////////////////////////////////////////////////////////////////

struct rfc2822_obs_zone {
  char const *name;
  long gmtoff;
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

template<typename IntType> inline
bool bits_set( IntType flags, IntType bits ) {
  return (flags & bits) == bits;
}

inline bool is_leap_year( unsigned year ) {
  return !(year % 4) && ((year % 100) || !(year % 400));
}

/**
 * Tondering's algorithm for calculating the weekday given a date; see:
 * http://www.tondering.dk/claus/calendar.html
 *
 * COPYRIGHT:
 *   These functions are Copyright (c) 2008 by Claus Tondering
 *   (claus@tondering.dk).
 *  
 * LICENSE:
 *   The code is distributed under the Boost Software License, which
 *   says:
 *  
 *     Boost Software License - Version 1.0 - August 17th, 2003
 *  
 *     Permission is hereby granted, free of charge, to any person or
 *     organization obtaining a copy of the software and accompanying
 *     documentation covered by this license (the "Software") to use,
 *     reproduce, display, distribute, execute, and transmit the
 *     Software, and to prepare derivative works of the Software, and
 *     to permit third-parties to whom the Software is furnished to do
 *     so, all subject to the following:
 *  
 *     The copyright notices in the Software and this entire
 *     statement, including the above license grant, this restriction
 *     and the following disclaimer, must be included in all copies of
 *     the Software, in whole or in part, and all derivative works of
 *     the Software, unless such copies or derivative works are solely
 *     in the form of machine-executable object code generated by a
 *     source language processor.
 *  
 *     THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *     EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *     OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, TITLE AND
 *     NON-INFRINGEMENT. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR
 *     ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE FOR ANY DAMAGES OR
 *     OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 *     ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE
 *     USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @param mday Month day: 1-31.
 * @param mon Month: 0-11.
 * @param year Year.
 * @return Returns the weekday where 0 = Sunday.
 */
static unsigned calc_wday( unsigned mday, unsigned mon, unsigned year ) {
  ++mon; // Tondering's algorithm assumes month value in range 1-12.
  unsigned const a = (14 - mon) / 12;
  unsigned const y = year - a;
  unsigned const m = mon + 12 * a - 2;
  return (mday + y + y/4 - y/100 + y/400 + (31 * m) / 12) % 7;
}

static unsigned calc_yday( unsigned mday, unsigned mon, unsigned year ) {
  static unsigned const first_of_the_month[][12] = {
    { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 }, // non-leap year
    { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335 }  // leap year
  };
  return first_of_the_month[ is_leap_year( year ) ][ mon ] + mday;
}

static unsigned days_in_month( unsigned mon, unsigned year ) {
  static unsigned const days[] = {
    31, //  0: Jan
    28, //  1: Feb
    31, //  2: Mar
    30, //  3: Apr
    31, //  4: May
    30, //  5: Jun
    31, //  6: Jul
    31, //  7: Aug
    30, //  8: Sep
    31, //  9: Oct
    30, // 10: Nov
    31  // 11: Dec
  };
  return days[ mon ] + (mon == 1 /* Feb */ && is_leap_year( year ));
}

inline bool is_mday_valid( unsigned mday, unsigned mon, unsigned year ) {
  return mday >= 1 && mday <= days_in_month( mon, year );
}

static bool is_wday_valid( unsigned wday, unsigned mday, unsigned mon,
                           unsigned year ) {
  return wday == calc_wday( mday, mon, year );
}

inline bool is_yday_valid( unsigned yday, unsigned mday, unsigned mon,
                           unsigned year ) {
  return yday == calc_yday( mday, mon, year );
}

///////////////////////////////////////////////////////////////////////////////

typedef char const* (*locale_fn_type)(unsigned);

static void bad_alt( char c ) {
  throw invalid_argument( // TODO
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

static void locale_find( char conv, char const **bpp, locale_fn_type locale_fn,
                         int limit, int *result, bool *found = nullptr ) {
  char const *&bp = *bpp;
  size_t len_sum = 0;

  for ( int i = 0; i < limit; ++i ) {
    char const *const s = (*locale_fn)( i );
    size_t const len = ::strlen( s );
    len_sum += len;
    if ( ::strncmp( bp, s, len ) == 0 ) {
      *result = i;
      if ( found )
        *found = true;
      bp += len;
      return;
    }
  }
  if ( !found ) {
    //
    // Since we don't know the extent of the value in the buffer, extract a
    // representative chunk whose length is the average length of all the legal
    // values.
    //
    throw invalid_value( bp, len_sum / limit, conv );
  }
  *found = false;
}

static void parse_num( char conv, char const **bpp, unsigned low,
                       unsigned high, int *result ) {
  char const *&bp = *bpp;
  char c = *bp;
  if ( !ascii::is_digit( c ) )
    throw invalid_value( c, conv );

  unsigned limit = high; // "high" also determines the number of digits
  unsigned n = 0;

  do {
    n = n * 10 + c - '0';
    limit /= 10;
    c = *++bp;
  } while ( limit && ascii::is_digit( c ) );

  if ( n < low || n > high )
    throw invalid_value( n, conv );
  *result = n;
}

///////////////////////////////////////////////////////////////////////////////

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

//
// We do not implement alternate representations. However, we always check
// whether a given modifier is allowed for a certain conversion.
//
int const ALT_E = 0x01;
int const ALT_O = 0x02;
#define CHECK_ALT(x)  do { if ( alt_format & ~(x) ) bad_alt( c ); } while (0)

static char const* strptime_impl( char const *buf, char const *fmt, ztm *tm,
                                  unsigned *set_fields ) {
  char const *bp = buf;
  char c;
  bool found;
  char const *recurse_fmt;
  bool split_year = false;

  while ( bp && (c = *fmt++) ) {
    if ( ascii::is_space( c ) ) {
      bp = ascii::trim_start_whitespace( bp );
      continue;
    }

    int alt_format = 0;
    int n;

    if ( c != '%' ) {                   // literal
literal:
      CHECK_ALT(0);
      if ( *bp != c )
        throw literal_mismatch( c, *bp );
      ++bp;
      continue;
    }

again:
    switch ( c = *fmt++ ) {
      case '%':
        goto literal;

      case 'a': // abbreviated weekday name
      case 'A': // full weekday name
        CHECK_ALT(0);
        locale_find(
          c, &bp, &locale::get_weekday_name, 7, &tm->tm_wday, &found
        );
        if ( !found )
          locale_find( c, &bp, &locale::get_weekday_abbr, 7, &tm->tm_wday );
        *set_fields |= set_wday;
        break;

      case 'b': // abbreviated month name
      case 'B': // full month name
      case 'h': // same as %b
        CHECK_ALT(0);
        locale_find( c, &bp, &locale::get_month_name, 12, &tm->tm_mon, &found );
        if ( !found )
          locale_find( c, &bp, &locale::get_month_abbr, 12, &tm->tm_mon );
        *set_fields |= set_mon;
        break;

      case 'c': // date and time
        CHECK_ALT(ALT_E);
        recurse_fmt = locale::get_date_time_format();
        goto recurse;

      case 'C': // century number
        CHECK_ALT(ALT_E);
        parse_num( c, &bp, 0, 99, &n );
        n = n * 100 - TM_YEAR_BASE;
        if ( split_year )
          n += tm->tm_year % 100;
        else
          split_year = true;
        tm->tm_year = n;
        *set_fields |= set_year;
        break;

      case 'D':
        CHECK_ALT(0);
        recurse_fmt = "%m/%d/%y";
        goto recurse;

      case 'd': // day of month: 01-31
      case 'e': // day of month: 1-31
        CHECK_ALT(ALT_O);
        parse_num( c, &bp, 1, 31, &tm->tm_mday );
        *set_fields |= set_mday;
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
        parse_num( c, &bp, 1, 366, &n );
        tm->tm_yday = n - 1;
        *set_fields |= set_yday;
        break;

      case 'k': // hour: 0-23
        CHECK_ALT(0);
        goto case_H;

      case 'H': // hour: 00-23
        CHECK_ALT(ALT_O);
case_H: parse_num( c, &bp, 0, 23, &tm->tm_hour );
        *set_fields |= set_hour;
        break;

      case 'l': // hour: 1-12
        CHECK_ALT(0);
        goto case_I;

      case 'I': // hour: 01-12
        CHECK_ALT(ALT_O);
case_I: parse_num( c, &bp, 1, 12, &tm->tm_hour );
        if ( tm->tm_hour == 12 )
          tm->tm_hour = 0;
        *set_fields |= set_hour;
        break;

      case 'm': // month: 01-12
        CHECK_ALT(ALT_O);
        parse_num( c, &bp, 1, 12, &n );
        tm->tm_mon = n - 1;
        *set_fields |= set_mon;
        break;

      case 'M': // minute: 00-59
        CHECK_ALT(ALT_O);
        parse_num( c, &bp, 0, 59, &tm->tm_min );
        *set_fields |= set_min;
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
        locale_find( c, &bp, &get_time_ampm, 2, &n );
        if ( tm->tm_hour > 11 )
          throw invalid_value( tm->tm_hour, "Il" );
        if ( n /* i.e., PM */ )
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
        parse_num( c, &bp, 0, 60, &tm->tm_sec );
        *set_fields |= set_sec;
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
        parse_num( c, &bp, 1, 7, &n );
        tm->tm_wday = n - 1;
        *set_fields |= set_wday;
        break;

      case 'V': // week of year, beginning on Monday: 01-53
        CHECK_ALT(ALT_O);
        //
        // This is bogus since we can not assume any valid information present
        // in the tm structure at this point to calculate a real value, so just
        // check the range for now.
        //
        parse_num( c, &bp, 1, 53, &n );
        break;

      case 'U': // week of year, beginning on Sunday: 00-53
      case 'W': // week of year, beginning on Monday: 00-53
        CHECK_ALT(ALT_O);
        //
        // This is bogus since we can not assume any valid information present
        // in the tm structure at this point to calculate a real value, so just
        // check the range for now.
        //
        parse_num( c, &bp, 0, 53, &n );
        break;

      case 'v':
        CHECK_ALT(0);
        recurse_fmt = "%e-%b-%Y";
        goto recurse;

      case 'w': // day of week, beginning on Sunday: 0-6
        CHECK_ALT(ALT_O);
        parse_num( c, &bp, 0, 6, &tm->tm_wday );
        *set_fields |= set_wday;
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
        parse_num( c, &bp, 0, 99, &n );
        if ( split_year )               // preserve century
          n += (tm->tm_year / 100) * 100;
        else {
          n += (n <= 68 ? 2000 : 1900) - TM_YEAR_BASE;
          split_year = true;
        }
        tm->tm_year = n;
        *set_fields |= set_year;
        break;

      case 'Y': // year: 0-9999
        CHECK_ALT(ALT_E);
        parse_num( c, &bp, 0, 9999, &n );
        tm->tm_year = n - TM_YEAR_BASE;
        *set_fields |= set_year;
        break;

      case 'z': { // RFC 2822 timezone offset or name: [+|-]HHMM | ZZZ
        CHECK_ALT(0);
        char const *const bp0 = bp;
        int sign;
        switch ( *bp ) {
          case '+': sign =  1; ++bp; break;
          case '-': sign = -1; ++bp; break;
          default : sign =  0;
        }
        if ( ascii::is_digit( *bp ) ) { // start of HHMM
          int hour = (*bp - '0') * 10;
          if ( !ascii::is_digit( *++bp ) )
            goto bad_tz;
          hour += *bp - '0';
          //
          // We don't need to check the hour because values [-99,99] are legal.
          //
          if ( !ascii::is_digit( *++bp ) )
            goto bad_tz;
          int minute = (*bp - '0') * 10;
          if ( !ascii::is_digit( *++bp ) )
            goto bad_tz;
          minute += *bp++ - '0';
          if ( minute > 59 )
            goto bad_tz;
          long gmtoff = hour * 60 * 60 + minute * 60;
          if ( sign )
            gmtoff *= sign;
          set_gmtoff_field( *tm, gmtoff );
          tm->tm_isdst = 0;
          *set_fields |= set_gmtoff;
          break;
        } else if ( sign )              // sign followed by non-digit
bad_tz:   throw invalid_value( bp0, 4 + !!sign, c );
        // no break;
      } // case 'z'

      case 'Z': { // RFC 2822 timezone name only: ZZZ
        CHECK_ALT(0);
        for ( rfc2822_obs_zone const *z = rfc2822_obs_zones; z->name; ++z ) {
          size_t const len = ::strlen( z->name );
          if ( ::strncmp( bp, z->name, len ) == 0 ) {
            set_gmtoff_field( *tm, z->gmtoff );
            tm->tm_isdst = z->isdst;
            *set_fields |= set_gmtoff;
            bp += len;
            goto next_outer_loop;
          }
        }
        throw invalid_value( bp, 3 /* assume */, c );
      } // case 'Z'

      default: // unknown/unsupported conversion
        throw invalid_specification( c );
    } // switch

next_outer_loop:
    continue;

recurse:
    bp = ztd::strptime_impl( bp, recurse_fmt, tm, set_fields );
  } // while

  if ( bits_set( *set_fields, set_mday | set_mon | set_year ) ) {
    int const year = TM_YEAR_BASE + tm->tm_year;
    if ( !is_mday_valid( tm->tm_mday, tm->tm_mon, year ) )
      throw invalid_value( tm->tm_mday, "de" );
    if ( (*set_fields & set_wday) &&
         !is_wday_valid( tm->tm_wday, tm->tm_mday, tm->tm_mon, year ) )
      throw invalid_value( tm->tm_wday, "uw" );
    if ( (*set_fields & set_yday) &&
         !is_yday_valid( tm->tm_yday, tm->tm_mday, tm->tm_mon, year ) )
      throw invalid_value( tm->tm_yday, 'j' );
  }

  return bp;
}

char const* strptime( char const *buf, char const *fmt, ztm *tm,
                      unsigned *set_fields ) {
  unsigned local_fields;
  if ( !set_fields )
    set_fields = &local_fields;
  *set_fields = 0;
  return strptime_impl( buf, fmt, tm, set_fields );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace zorba
/* vim:set et sw=2 ts=2: */
