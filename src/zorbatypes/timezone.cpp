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

// standard
#include <cstdlib>
#include <exception>

// Zorba
#include "datetime/parse.h"
#include "timezone.h"
#include "util/ascii_util.h"
#include "util/hash/hash.h"
#include "util/string_util.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * XML Schema Part 2: 3.2.7.3: Timezones are durations with ... the hour
 * magnitude limited to at most 14 ...
 */
static int const MaxHour = 14;

static TimeZone::value_type const MaxValue = MaxHour * 60 * 60;
static TimeZone::value_type const MinValue = -MaxValue;

static TimeZone::value_type check_value( TimeZone::value_type gmtoff ) {
  if ( gmtoff < MinValue )
    throw range_error(
      BUILD_STRING( gmtoff, ": value < minimum value of ", MinValue )
    );
  if ( gmtoff > MaxValue )
    throw range_error(
      BUILD_STRING( gmtoff, ": value > maximum value of ", MaxValue )
    );
  return gmtoff;
}

static TimeZone::value_type check_value( int hours, int minutes ) {
  bool const negative = hours < 0 || minutes < 0;

  if ( (hours = ::abs( hours )) > MaxHour )
    throw range_error(
      BUILD_STRING( hours, ": |hours| > maximum of ", MaxHour )
    );
  if ( (minutes = ::abs( minutes )) > 59 )
    throw range_error(
      BUILD_STRING( minutes, ": |minutes| > maximum of 59" )
    );
  if ( hours == MaxHour && minutes )
    throw range_error(
      BUILD_STRING( minutes, ": |minutes| > 0 when |hours| is ", MaxHour )
    );

  return (hours * 60 * 60 + minutes * 60) * (negative ? -1 : 1);
}

///////////////////////////////////////////////////////////////////////////////

TimeZone::TimeZone( value_type gmtoff ) :
  gmtoff_( check_value( gmtoff ) ),
  timezone_not_set_( false )
{
}

TimeZone::TimeZone( int hours, int minutes ) :
  gmtoff_( check_value( hours, minutes ) ),
  timezone_not_set_( false )
{
}

size_t TimeZone::hash() const {
  std::hash<value_type> hasher;
  return !*this ? hasher( ~0 ) : hasher( gmtoff_ );
}

int TimeZone::parse( char const *s, size_t s_len, TimeZone *tz ) {
  s = ascii::trim_space( s, &s_len );
  char const *const end = s + s_len;
  if ( s == end )                       // string was entirely whitespace
    return 1;

  //
  // Ibid: The lexical representation of a timezone is a string of the form:
  // (('+' | '-') hh ':' mm) | 'Z'.
  //
  if ( *s == 'Z' ) {
    if ( ++s != end )
      return 1;
    *tz = TimeZone( 0 );
  } else {
    if ( end - s != 6 )                 // need exactly 6 characters
      return 1;
    bool negative = false;
    switch ( *s ) {
      case '-':
        negative = true;
        // no break;
      case '+':
        try {
          if ( !ascii::is_digit( *++s ) )
            return 1;
          int hours = (int)ztd::aton<unsigned>( s, end, &s );
          if ( end - s != 3 || *s != ':' || !ascii::is_digit( *++s ) )
            return 1;
          int minutes = (int)ztd::aton<unsigned>( s, end, &s );
          if ( s != end )
            return 1;
          if ( negative ) {
            if ( hours )
              hours = -hours;
            else
              minutes = -minutes;
          }
          *tz = TimeZone( hours, minutes );
        }
        catch ( std::exception const& ) {
          //
          // IMHO, using error codes is terrible, especially when C++ supports
          // exceptions; but the original code returned error codes so we're
          // forced to return them as well (otherwise more chunks of code would
          // have to be rewritten to catch exceptions).  Perhaps a future
          // clean-up will fix this.
          //
          // That aside, the original code didn't even use error code well in
          // that this function returned '1' for all errors rather than
          // something more sensible like returning different error codes for
          // "syntax error" vs "range error."
          //
          return 1;
        }
        break;
      default:
        return 1;
    }
  }
  return 0;
}

zstring TimeZone::toString() const {
  zstring result;
  if ( *this ) {
    if ( !gmtoff_ )
      result = 'Z';
    else {
      result += *this < 0 ? '-' : '+';
      result += zero_pad( std::abs( getHours() ), 2 );
      result += ':';
      result += zero_pad( std::abs( getMinutes() ), 2 );
    }
  }
  return result;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
