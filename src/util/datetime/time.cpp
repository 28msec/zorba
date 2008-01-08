/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include "util/datetime/time.h"
#include "util/datetime/parse.h"

#include <iostream>
using namespace std;


namespace xqp
{
    
Time_t Time::parse_string(xqpString s)
{
  Time_t t_t;

  // TODO: boost's time_duration allows a "-" at the start of the string, but we shouldn't as its time, not duration
  t_t = new Time(boost::posix_time::duration_from_string(s));
  
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
