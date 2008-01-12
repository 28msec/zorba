/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include "util/datetime/timezone.h"
#include "util/datetime/parse.h"
#include "errors/error_factory.h"

namespace xqp
{
    
TimeZone_t TimeZone::parse_string(xqpString s)
{
  std::string ss = *s.getStore();
  TimeZone_t tz_t;
  unsigned int position = 0;
  bool is_negative = false;

  // A time zone is of form: (('+' | '-') hh ':' mm) | 'Z'

  skip_whitespace(ss, position);
  if (position == ss.size())
    ZORBA_ERROR_ALERT(ZorbaError::FORG0001, NULL);

  if (ss[position] == 'Z')
  {
    // '+00:00', '-00:00', and 'Z' all represent the same zero-length duration timezone, UTC; 'Z' is its canonical representation.
    tz_t = new TimeZone(boost::posix_time::duration_from_string("00:00:00"));

    position++;
    
    if (ss.size() != position)
      ZORBA_ERROR_ALERT(ZorbaError::FORG0001, NULL);
  }
  else
  {
    if (ss[position] == '-')
      is_negative = true;
    else if (ss[position] == '+')
      /* do nothing */ ;
    else
      ZORBA_ERROR_ALERT(ZorbaError::FORG0001, NULL);

    position++;

    // Parse hh:mm . Add ":00" and pass it off to boost
    std::string temp = ss.substr(position,ss.size()-position) + ":00";
    if (is_negative)
      temp = "-" + temp;
  
    tz_t = new TimeZone(boost::posix_time::duration_from_string(temp));
  }
  
  return tz_t;
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
    
    if (the_time_zone.hours() >= 0)
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

} // namespace xqp
