/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include <exception>
#include "util/datetime/time.h"
#include "util/datetime/parse.h"

#define RETURN_FALSE_ON_EXCEPTION(sequence)     \
  try                                           \
  {                                             \
    sequence;                                   \
  }                                             \
  catch (std::exception& ex)                    \
  {                                             \
    return false;                               \
  }

namespace xqp
{
  const uint16_t NO_SECONDS_IN_MINUTE = 60;

bool Time::parse_string(const xqpString& s, Time_t& t_t)
{
  int time_zone_start;
  TimeZone_t tz_t;

  // Time is of form:  hh ':' mm ':' ss ('.' s+)? (zzzzzz)?
  // Time cannot be negative

  time_zone_start = s.indexOf("-");
  if (time_zone_start == -1)
    time_zone_start = s.indexOf("+");
  if (time_zone_start == -1)
    time_zone_start = s.indexOf("Z");

  // TODO: boost's time_duration allows a "-" at the start of the string, but we shouldn't, as its time, not duration
  if (time_zone_start == -1)
  {
    RETURN_FALSE_ON_EXCEPTION( t_t = new Time(boost::posix_time::duration_from_string(s)); );
  }
  else
  {
    RETURN_FALSE_ON_EXCEPTION( t_t = new Time(boost::posix_time::duration_from_string(s.substr(0, time_zone_start))); );
    if (TimeZone::parse_string(s.substr(time_zone_start, s.size()-time_zone_start), tz_t))
      t_t->the_time_zone = *tz_t;
    else
      return false;
  }

  if (t_t->the_time.hours() == 24 && t_t->the_time.minutes() == 0
      &&
      t_t->the_time.seconds() == 0 && t_t->the_time.fractional_seconds() == 0)
  {
    RETURN_FALSE_ON_EXCEPTION( t_t->the_time = boost::posix_time::time_duration(0, 0, 0, 0); )
  }
  
  return true;
}

const boost::posix_time::time_duration& Time::get_time_duration() const
{
  return the_time;
}

int32_t Time::getHours() const
{
  return the_time.hours();
}

int32_t Time::getMinutes() const
{
  return the_time.minutes();
}

double Time::getSeconds() const
{
  double frac_sec = the_time.fractional_seconds();
  while(frac_sec > 1)
  {
    frac_sec = frac_sec /10;
  }
  
  return (the_time.seconds() % NO_SECONDS_IN_MINUTE) + frac_sec;
}

TimeZone Time::getTimezone() const
{
  return the_time_zone;
}

Time& Time::operator=(const Time_t& t_t)
{
  the_time = t_t->the_time;
  return *this;
}

bool Time::operator<(const Time& t) const
{
  return (the_time < t.the_time);
}

bool Time::operator==(const Time& t) const
{
  return (the_time == t.the_time);
}

xqpString Time::toString() const
{
  xqpString result = boost::posix_time::to_simple_string(the_time);
  // TODO:
  return result;
}

int Time::compare(const Time& t) const
{
  if (operator<(t))
    return -1;
  else if (operator==(t))
    return 0;
  else
    return 1;
}

} // namespace xqp
