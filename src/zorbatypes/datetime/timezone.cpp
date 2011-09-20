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

#include <string>
#include <exception>

#include <zorbatypes/timezone.h>
#include "zorbatypes/datetime/parse.h"
#include "zorbautils/hashfun.h"
#include "util/ascii_util.h"
#include "zorbaserialization/template_serializer.h"


namespace zorba
{
SERIALIZABLE_CLASS_VERSIONS(TimeZone)
END_SERIALIZABLE_CLASS_VERSIONS(TimeZone)


TimeZone::TimeZone(short hours) : Duration(DAYTIMEDURATION_FACET)
{
  timezone_not_set = false;

  if (hours < 0)
    is_negative = true;

  data[HOUR_DATA] = abs<long>(hours);
}


void TimeZone::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (Duration*)this);
  ar & timezone_not_set;
}


int TimeZone::parseTimeZone(const char* str, ascii::size_type strlen, TimeZone& tz)
{
  ascii::size_type pos = 0;
  
  ascii::skip_whitespace(str, strlen, &pos);

  // A time zone is of form: (('+' | '-') hh ':' mm) | 'Z'

  if (str[pos] == 'Z')
  {
    ++pos;
    ascii::skip_whitespace(str, strlen, &pos);

    if (pos != strlen)
      return 1;

    // '+00:00', '-00:00', and 'Z' all represent the same zero-length duration
    // timezone, UTC; 'Z' is its canonical representation.
    tz = TimeZone(0);
  }
  else
  {
    tz = TimeZone(0);
    
    if (str[pos] == '-')
      tz.is_negative = true;
    else if (str[pos] == '+')
      /* do nothing */ ;
    else
      return 1;

    ++pos;

    if ( parse_long(str, strlen, pos, tz.data[HOUR_DATA], 2, 2) )
      return 1;

    if (str[pos++] != ':')
      return 1;
    
    if ( parse_long(str, strlen, pos, tz.data[MINUTE_DATA], 2, 2) )
      return 1;

    // minutes must be between 00..59
    if (tz.data[MINUTE_DATA] >= 60)
      return 1;

    // hours must be between -14 .. 14
    if (tz.data[HOUR_DATA]*60 + tz.data[MINUTE_DATA] > 14*60)
      return 1;

    ascii::skip_whitespace(str, strlen, &pos);

    if (pos != strlen)
      return 1;
  }
  
  return 0;
}


int TimeZone::createTimeZone(int hours, int minutes, int seconds, TimeZone& tz)
{
  tz = TimeZone(hours);
  tz.data[MINUTE_DATA] = abs<long>(minutes);
  tz.data[SECONDS_DATA] = abs<long>(seconds);
  tz.normalize(); 
  return 0;
}


bool TimeZone::operator<(const TimeZone& t) const
{
  return (compare(t) == -1);
}


bool TimeZone::operator==(const TimeZone& t) const
{
  return (compare(t) == 0);
}


zstring TimeZone::toString() const
{
  zstring result;
  
  if (timeZoneNotSet())
    return result;

  if (data[HOUR_DATA] == 0 && data[MINUTE_DATA] == 0)
    return "Z";

  if (isNegative())
    result.append("-", 1);
  else
    result.append("+", 1);

  result.append(to_string(data[HOUR_DATA], 2));
  result.append(":", 1);
  result.append(to_string(data[MINUTE_DATA], 2));
    
  return result;
}


int TimeZone::compare(const TimeZone& t) const
{
  return Duration::compare(t);
}


bool TimeZone::timeZoneNotSet() const
{
  return timezone_not_set;
}


bool TimeZone::isNegative() const
{
  return Duration::isNegative();
}


long TimeZone::getHours() const
{
  return Duration::getHours();
}


long TimeZone::getMinutes() const
{
  return Duration::getMinutes();
}


xs_decimal TimeZone::getSeconds() const
{
  return Duration::getSeconds();
}


long TimeZone::getIntSeconds() const
{
  return Duration::getIntSeconds();
}


long TimeZone::getFractionalSeconds() const
{
  return Duration::getFractionalSeconds();
}


uint32_t TimeZone::hash(int implicit_timezone_seconds) const
{
  return hashfun::h32<uint32_t>(timeZoneNotSet() ? (uint32_t)-1 : Duration::hash(), 0);
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
