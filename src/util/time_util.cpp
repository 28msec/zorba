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

#include <algorithm>
#include <cassert>
#include <cstring>
#ifdef WIN32
# include <windows.h>
# include <time.h>                      /* for gmtime_s() */
# if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
#   define DELTA_EPOCH_IN_USEC 11644473600000000Ui64
# else
#   define DELTA_EPOCH_IN_USEC 11644473600000000ULL
# endif
#else
# include <ctime>
# include <sys/time.h>
#endif /* WIN32 */

// local
#include "less.h"
#include "time_util.h"

#define DEF_END(CHAR_ARRAY)                             \
  static char const *const *const end =                 \
    CHAR_ARRAY + sizeof( CHAR_ARRAY ) / sizeof( char* )

#define FIND(WHAT) \
  static_cast<type>( find_index( string_of, end, WHAT ) )

using namespace std;

/**
 * A less-verbose way to use std::lower_bound.
 */
inline int find_index( char const *const *begin, char const *const *end,
                       char const *s ) {
  char const *const *const entry =
    ::lower_bound( begin, end, s, less<char const*>() );
  return entry != end && ::strcmp( s, *entry ) == 0 ? entry - begin : 0;
}

namespace zorba {
namespace time {

///////////////////////////////////////////////////////////////////////////////

namespace iso8601 {
  /**
   * Weekday values as used by the ISO 8601 specification.
   */
  enum weekday {
    mon = 1,
    tue = 2,
    wed = 3,
    thu = 4,
    fri = 5,
    sat = 6,
    sun = 7
  };
}

namespace calendar {

char const *const string_of[] = {
  "#UNKNOWN",
  "AD",   // Anno Domini (Christian Era)
  "AH",   // Anno Hegirae (Muhammedan Era)
  "AM",   // Anno Mundi (Jewish)
  "AME",  // Mauludi Era (solar years since Mohammed's birth)
  "AP",   // Anno Persici
  "AS",   // Aji Saka Era (Java)
  "BE",   // Buddhist Era
  "CB",   // Cooch Behar Era
  "CE",   // Common Era
  "CL",   // Chinese Lunar Era
  "CS",   // Chula Sakarat Era
  "EE",   // Ethiopian Era
  "FE",   // Fasli Era
  "ISO",  // ISO 8601 calendar
  "JE",   // Japanese
  "KE",   // Khalsa Era (Sikh calendar)
  "KY",   // Kali Yuga
  "ME",   // Malabar Era
  "MS",   // Monarchic Solar Era
  "OS",   // Old Style (Julian)
  "RS",   // Rattanakosin (Bangkok) Era
  "SE",   // Saka Era
  "SH",   // Mohammedan Solar Era (Iran)
  "SS",   // Saka Samvat
  "TE",   // Tripurabda Era
  "VE",   // Vikrama Era
  "VS"    // Vikrama Samvat Era
};

int calc_week_in_month( unsigned mday, unsigned mon, unsigned year, type cal ) {
  int mon1_wday = time::calc_wday( 1, mon, year );

  switch ( cal ) {
    case AD:
      return (mon1_wday + mday - 1) / 7 + 1;
    case ISO: {
      //
      // From https://www.w3.org/Bugs/Public/show_bug.cgi?id=21370#c6
      //
      //    When the 'w' component is used, the convention to be adopted is
      //    that each Monday-to-Sunday week is considered to fall within a
      //    particular month if its Thursday occurs in that month; the weeks
      //    that fall in a particular month under this definition are numbered
      //    starting from 1. Thus, for example, 29 January 2013 falls in week 5
      //    because the Thursday of the relevant week (31 January 2013) is the
      //    fifth Thursday in January, and 1 February 2013 is also in week 5
      //    for the same reason.
      //
      mon1_wday = convert_wday_to( mon1_wday, cal );
      int week = (mday + mon1_wday - 2) / 7 + 1;
      if ( mon1_wday > iso8601::thu && !--week )
        return 5;                       // week is part of previous month

      int const wday =
        convert_wday_to( time::calc_wday( mday, mon, year ), cal );
      int const yday = time::calc_yday( mday, mon, year );
      if ( time::days_in_year( year ) - yday + 1 < iso8601::thu - wday )
        return 1;                       // date falls in week 1 of next year

      return week;
    }
    default:
      return -1;
  }
}

int calc_week_in_year( unsigned mday, unsigned mon, unsigned year, type cal ) {
  int yday = time::calc_yday( mday, mon, year );
  int jan1_wday = time::calc_wday( 1, time::jan, year );

  switch ( cal ) {
    case AD:
      return (jan1_wday + yday) / 7 + 1;
    case ISO: {
      // Based on http://www.personal.ecu.edu/mccartyr/ISOwdALG.txt
      ++yday; // code assumes [1-366]
      jan1_wday = convert_wday_to( jan1_wday, cal );

      if ( jan1_wday > iso8601::thu && jan1_wday + yday <= 8 ) {
        // date falls in week 52 or 53 of previous year
        return  52
              + (jan1_wday == iso8601::fri ||
                (jan1_wday == iso8601::sat && time::is_leap_year( year - 1 )));
      }
      int const wday =
        convert_wday_to( time::calc_wday( mday, mon, year ), cal );
      if ( time::days_in_year( year ) - yday < iso8601::thu - wday ) {
        // date falls in week 1 of next year
        return 1;
      }
      return  (yday + (7 - wday) + (jan1_wday - 1)) / 7
            - (jan1_wday > iso8601::thu);
    }
    default:
      return -1;
  }
}

int convert_mon_to( unsigned mon, type to ) {
  switch ( to ) {
    case AD:
    case ISO:
      return (int)mon;
    default:
      return -1;
  }
}

int convert_wday_from( unsigned wday, type from ) {
  switch ( from ) {
    case AD:
      return static_cast<int>( wday );
    case ISO:
      return wday == (unsigned)iso8601::sun ? (int)time::sun : (int)wday;
    default:
      return -1;
  }
}

int convert_wday_to( unsigned wday, type to ) {
  switch ( to ) {
    case AD:
      return static_cast<int>( wday );
    case ISO:
      return wday == (unsigned)time::sun ? (int)iso8601::sun : (int)wday;
    default:
      return -1;
  }
}

type find( char const *calendar ) {
  DEF_END( string_of );
  return FIND( calendar );
}

} // namespace calendar

///////////////////////////////////////////////////////////////////////////////

static unsigned const yday_mon[][13] = {
  // 0   1   2   3    4    5    6    7    8    9   10   11   12
  {  0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 },  // non-leap
  {  0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 }   // leap
};

///////////////////////////////////////////////////////////////////////////////

bool calc_mday_mon( unsigned yday, unsigned *mday, unsigned *mon,
                    unsigned year ) {
  assert( (int)yday < days_in_year( year ) );

  unsigned const *const ym = yday_mon[ is_leap_year( year ) ];
  for ( unsigned m = 1; m <= 12; ++m ) 
    if ( ym[ m ] > yday ) {
      --m;
      if ( mday )
        *mday = yday - ym[ m ] + 1;
      if ( mon )
        *mon = m;
      return true;
    }
  return false;
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
 * @param mday The month day [1-31].
 * @param mon The month [0-11].
 * @param year The year.
 * @return Returns the weekday [0-6] where 0 = Sunday.
 */
int calc_wday( unsigned mday, unsigned mon, unsigned year ) {
  assert( mday >= 1 );
  assert( (int)mday <= days_in_month( mon, year ) );
  assert( mon < 12 );

  ++mon; // Tondering's algorithm assumes month value in range 1-12.
  int const a = (14 - mon) / 12;
  int const y = year - a;
  int const m = mon + 12 * a - 2;
  return (mday + y + y/4 - y/100 + y/400 + (31 * m) / 12) % 7;
}

int calc_yday( unsigned mday, unsigned mon, unsigned year ) {
  assert( mday >= 1 );
  assert( (int)mday <= days_in_month( mon, year ) );
  return (int)yday_mon[ is_leap_year( year ) ][ mon ] + mday - 1;
}

int days_in_month( unsigned mon, unsigned year ) {
  static int const days[] = {
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
  assert( mon < 12 );
  return days[ mon ] + (mon == feb && is_leap_year( year ));
}

void get_epoch( sec_type *sec, usec_type *usec ) {
#ifdef WIN32
  FILETIME ft;
  ::GetSystemTimeAsFileTime( &ft );
  unsigned __int64 temp = ((__int64)ft.dwHighDateTime << 32) | ft.dwLowDateTime;
  temp /= 10;                           // nanosec -> usec
  temp -= DELTA_EPOCH_IN_USEC;          // 1601 -> 1970
  *sec = (sec_type)(temp / 1000000L);  // usec -> sec
  if ( usec )
    *usec = (usec_type)(temp % 1000000L);
#else
  timeval tv;
  ::gettimeofday( &tv, nullptr );
  *sec = tv.tv_sec;
  if ( usec )
    *usec = tv.tv_usec;
#endif /* WIN32 */
}

void get_gmtime( ztm *tm, sec_type when ) {
  if ( !when )
    get_epoch( &when );
#ifdef WIN32
  time_t time = static_cast<time_t>(when);
  ::gmtime_s( tm, &time );  
#else
  ::gmtime_r( &when, tm );
#endif /* WIN32 */
  tm->ZTM_GMTOFF = 0;
}

void get_localtime( ztm *tm, sec_type when ) {
  if ( !when )
    get_epoch( &when );
#ifdef WIN32
  time_t time = static_cast<time_t>(when);
  ::localtime_s( tm, &time );
  tm->ZTM_GMTOFF = - _timezone;         // seconds west -> east
#else
  ::localtime_r( &when, tm );
#if !defined(ZORBA_HAVE_STRUCT_TM_TM_GMTOFF) && \
    !defined(ZORBA_HAVE_STRUCT_TM___TM_GMTOFF)
  tm->ZTM_GMTOFF = ::timegm( tm ) - when;
#endif
#endif /* WIN32 */
}

long get_gmt_offset() {
#ifdef WIN32
  TIME_ZONE_INFORMATION tz;
  ::GetTimeZoneInformation( &tz );
  return tz.Bias * -60;                 // minutes west -> seconds east
#else
  sec_type const now = ::time( nullptr );
  ztm tm;
  ::localtime_r( &now, &tm );
  return ::timegm( &tm ) - now;
#endif /* WIN32 */
}

char get_military_tz( int hour ) {
  hour %= 24;
  if ( hour > 12 )
    hour -= 24;
  else if ( hour < -12 )
    hour += 24;
  if ( hour >= 0 && hour <= 12 )
    return "ZABCDEFGHIKLM" [ hour ];    // no 'J' here (it means "no timezone")
  return " NOPQRSTUVWXY" [ -hour ];
}

///////////////////////////////////////////////////////////////////////////////

} // namespace time
} // namespace zorba
/* vim:set et sw=2 ts=2: */
