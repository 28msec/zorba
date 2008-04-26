/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include <exception>

#include <zorbatypes/timezone.h>
#include "zorbatypes/datetime/parse.h"
#include <util/hashfun.h>

#define RETURN_FALSE_ON_EXCEPTION(sequence)     \
  try                                           \
  {                                             \
    sequence;                                   \
  }                                             \
  catch (std::exception)                        \
  {                                             \
    return false;                               \
  }

#include <iostream>
using namespace std;

namespace zorba
{
TimeZone::TimeZone(short hours)
{
  boost::posix_time::time_duration t( hours, 0 , 0 , 0 );
  the_time_zone = t;
}

bool TimeZone::parse_string(const xqpString& s, TimeZone_t& tz_t)
{
  std::string ss = s.getStore()->str();
  unsigned int position = 0;
  bool is_negative = false;
  
  // A time zone is of form: (('+' | '-') hh ':' mm) | 'Z'

  if (ss.size() != 1 && ss.size() != 6)
    return false;

  if (ss[position] == 'Z')
  {
    // '+00:00', '-00:00', and 'Z' all represent the same zero-length duration timezone, UTC; 'Z' is its canonical representation.

    RETURN_FALSE_ON_EXCEPTION( tz_t = new TimeZone(boost::posix_time::duration_from_string("00:00:00")) );
    
    position++;
    
    if (ss.size() != position)
      return false;
  }
  else
  {
    if (ss[position] == '-')
      is_negative = true;
    else if (ss[position] == '+')
      /* do nothing */ ;
    else
      return false;

    position++;

    // Validate the timezone
    if (!is_digit(ss[position]) || !is_digit(ss[position+1]) || ss[position+2] != ':' ||
         !is_digit(ss[position+3]) || !is_digit(ss[position+4]))
      return false;
    
    // minutes must be between 00..59
    if (ss.substr (position + 3, 2) >= "60")
      return false;

    // Parse hh:mm . Add ":00" and pass it off to boost
    std::string temp = ss.substr(position) + ":00";
    if (is_negative)
      temp = "-" + temp;

    boost::posix_time::time_duration t;
    RETURN_FALSE_ON_EXCEPTION( t = boost::posix_time::duration_from_string (temp); );
    
    if (t.minutes() < -59 || t.minutes() > 59)
      return false;
    
    // hours must be between -14 .. 14
    if (t.hours()*60 + t.minutes() > 14*60 || t.hours()*60 + t.minutes() < -14*60)
      return false;
    
    tz_t = new TimeZone(t);
  }
  
  return true;
}

int TimeZone::createTimeZone(int hours, int minutes, int seconds, TimeZone_t& tz_t)
{
  tz_t = new TimeZone(boost::posix_time::time_duration(hours, minutes, seconds, 0));
  return 0;
}

TimeZone& TimeZone::operator=(const TimeZone_t& tz_t)
{
  the_time_zone = tz_t->the_time_zone;
  return *this;
}

bool TimeZone::operator<(const TimeZone& t) const
{
  return (the_time_zone < t.the_time_zone);
}

bool TimeZone::operator==(const TimeZone& t) const
{
  return (the_time_zone == t.the_time_zone);
}

xqpString TimeZone::toString() const
{
  xqpString result;
  
  if (the_time_zone.is_not_a_date_time())
    return xqpString("");
  else
  {
    result = boost::posix_time::to_simple_string(the_time_zone);

    if (the_time_zone.hours() == 0 && the_time_zone.minutes() == 0)
      return xqpString("Z");
    else if (the_time_zone.hours() >= 0 && the_time_zone.minutes() >= 0 && the_time_zone.seconds() >= 0)
      result = "+" + result.substr(0, 5);
    else
      result = result.substr(0, 6);
  }
  
  return result;
}

int TimeZone::compare(const TimeZone& t) const
{
  if (operator<(t))
    return -1;
  else if (operator==(t))
    return 0;
  else
    return 1;
}

bool TimeZone::is_negative() const
{
  return the_time_zone.is_negative();
}

bool TimeZone::is_not_a_date_time() const
{
  return the_time_zone.is_not_a_date_time();
}

long TimeZone::getHours() const
{
  return (the_time_zone.is_negative()? -1 : 1) * the_time_zone.hours();
}

long TimeZone::getMinutes() const
{
  return (the_time_zone.is_negative()? -1 : 1) * the_time_zone.minutes();
}

long TimeZone::getSeconds() const
{
  return (the_time_zone.is_negative()? -1 : 1) * the_time_zone.seconds();
}

long TimeZone::getFractionalSeconds() const
{
  return (the_time_zone.is_negative()? -1 : 1) * the_time_zone.fractional_seconds();
}

uint32_t TimeZone::hash(int implicit_timezone_seconds) const
{
  return hashfun::h32<boost::int64_t>(is_not_a_date_time() ? -1 : the_time_zone.ticks(), 0);
}


} // namespace zorba
