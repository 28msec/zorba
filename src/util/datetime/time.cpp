/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include "util/datetime/time.h"
#include "util/datetime/parse.h"

namespace xqp
{
    
Time_t Time::parse_string(xqpString s)
{
  Time_t t_t;
  int time_zone_start;

  // Time is of form:  hh ':' mm ':' ss ('.' s+)? (zzzzzz)?
  // Time cannot be negative

  time_zone_start = s.indexOf("-");
  if (time_zone_start == -1)
    time_zone_start = s.indexOf("+");
  if (time_zone_start == -1)
    time_zone_start = s.indexOf("Z");

  // TODO: boost's time_duration allows a "-" at the start of the string, but we shouldn't, as its time, not duration
  if (time_zone_start == -1)
    t_t = new Time(boost::posix_time::duration_from_string(s));
  else
  {
    t_t = new Time(boost::posix_time::duration_from_string(s.substr(0, time_zone_start)));
    t_t->the_time_zone = TimeZone::parse_string(s.substr(time_zone_start, s.size()-time_zone_start));
  }

  if (t_t->the_time.hours() == 24 && t_t->the_time.minutes() == 0
      &&
      t_t->the_time.seconds() == 0 && t_t->the_time.fractional_seconds() == 0)
    t_t->the_time = boost::posix_time::time_duration(0, 0, 0, 0);
  
  return t_t;
}

const boost::posix_time::time_duration& Time::get_time_duration() const
{
  return the_time;
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
