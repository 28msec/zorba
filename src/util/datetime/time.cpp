/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include <exception>
#include "util/datetime/time.h"
#include "util/datetime/datetime.h"
#include "util/datetime/parse.h"
#include "util/utf8/xqpString.h"

#define RETURN_1_ON_EXCEPTION(sequence)         \
  try                                           \
  {                                             \
    sequence;                                   \
  }                                             \
  catch (std::exception)                        \
  {                                             \
    return 1;                                   \
  }

namespace xqp
{

const uint16_t NO_SECONDS_IN_MINUTE = 60;


int Time::parse_string(const xqpString& s, Time_t& t_t)
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

  if (time_zone_start == -1)
  {
    RETURN_1_ON_EXCEPTION( t_t = new Time(boost::posix_time::duration_from_string(s)); );
  }
  else
  {
    RETURN_1_ON_EXCEPTION( t_t = new Time(boost::posix_time::duration_from_string(s.substr(0, time_zone_start))); );
    if (!TimeZone::parse_string(s.substr(time_zone_start), tz_t))
      return 1;
    t_t->the_time_zone = *tz_t;
  }

  // TODO: perform this check in datetime too?
  if (t_t->the_time.hours() == 24 && t_t->the_time.minutes() == 0
      &&
      t_t->the_time.seconds() == 0 && t_t->the_time.fractional_seconds() == 0)
  {
    RETURN_1_ON_EXCEPTION( t_t->the_time = boost::posix_time::time_duration(0, 0, 0, 0); )
  }
  
  return 0;
}

int Time::createTime(int hours, int minutes, double seconds, const TimeZone& tz, Time_t& t_t)
{
  if (seconds < 0 || seconds >= 60)
    return 1;
  if (minutes < 0 || minutes >= 60)
    return 1;
  if (hours < 0 || hours > 24)
    return 1;

  if (hours == 24 && minutes == 0 && seconds == 0)
    hours = 0;

  t_t = new Time(boost::posix_time::time_duration(hours,minutes,floor<double>(seconds),
    round(frac(seconds) * boost::posix_time::time_duration::ticks_per_second())));

  t_t->the_time_zone = tz;

  return 0;
}

DateTime_t Time::toDateTime() const
{
  DateTime_t dt_t;
  DateTime::createDateTime(false, 1972, 12, 31,
    the_time.hours(), the_time.minutes(), the_time.seconds(), the_time.fractional_seconds(), the_time_zone, dt_t);
  return dt_t;
}

const boost::posix_time::time_duration& Time::get_time_duration() const
{
  return the_time;
}

int Time::getHours() const
{
  return the_time.hours();
}

int Time::getMinutes() const
{
  return the_time.minutes();
}

double Time::getSeconds() const
{
  double frac_sec = double(the_time.fractional_seconds()) / boost::posix_time::time_duration::ticks_per_second();
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
  result += the_time_zone.toString();
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

Time_t operator+(const Time& t, const Duration& dur)
{
  Time_t t_t;
  // TODO: days in duration must be made to be 0
  DateTime_t dt_t = *t.toDateTime() + dur;
  Time::createTime(dt_t->getHours(), dt_t->getMinutes(), dt_t->getSeconds(), dt_t->getTimezone(), t_t);
  return t_t;
}

} // namespace xqp
