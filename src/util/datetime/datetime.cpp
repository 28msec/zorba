/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include <exception>
#include "util/datetime/datetime.h"
#include "util/datetime/parse.h"
#include "util/datetime/time.h"
#include "util/datetime/date.h"

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
    
DateTime::DateTime(const Date_t& d_t, const Time_t& t_t)
{
  the_date_time = boost::posix_time::ptime(d_t->get_date(), t_t->get_time_duration());
}

bool DateTime::parse_string(const xqpString& s, DateTime_t& dt_t)
{
  int frac_start;
  unsigned int position;
  long unused;
  std::string temp;
  TimeZone_t tz_t;

  // DateTime is of form: '-'? yyyy '-' mm '-' dd 'T' hh ':' mm ':' ss ('.' s+)? (zzzzzz)?

  // TODO: handle negative DateTimes

  temp = *s.translate("T", " ").getStore(); // replace "T" with " ", which is what boost expects
  frac_start = s.indexOf(".");
  
  if (frac_start != -1)
  {
    position = frac_start + 1;
    parse_int(temp, position, unused);
  }
  else
    position = 19;

  RETURN_FALSE_ON_EXCEPTION( dt_t = new DateTime(boost::posix_time::time_from_string(temp.substr(0, position))); );
  if (temp.size() > position)
  {
    if (TimeZone::parse_string(temp.substr(position, temp.size()-position), tz_t))
      dt_t->the_time_zone = *tz_t;
    else
      return false;
  }

  return true;
}

DateTime& DateTime::operator=(const DateTime_t& dt_t)
{
  the_date_time = dt_t->the_date_time;
  return *this;
}

bool DateTime::operator<(const DateTime& t) const
{
  return (the_date_time < t.the_date_time);
}

bool DateTime::operator==(const DateTime& t) const
{
  return (the_date_time == t.the_date_time);
}

xqpString DateTime::toString() const
{
  xqpString result = boost::posix_time::to_iso_extended_string(the_date_time);
  result += the_time_zone.toString();
  // TODO:
  return result;
}

int DateTime::compare(const DateTime& t) const
{
  // TODO: handle timezone
  if (operator<(t))
    return -1;
  else if (operator==(t))
    return 0;
  else
    return 1;
}

int32_t DateTime::getYear() const
{
  return the_date_time.date().year();
}

int32_t DateTime::getMonth() const
{
  return the_date_time.date().month();
}

int32_t DateTime::getDay() const
{
  return the_date_time.date().day();
}

int32_t DateTime::getHours() const
{
  return the_date_time.time_of_day().hours();
}

int32_t DateTime::getMinutes() const
{
  return the_date_time.time_of_day().minutes();
}
} // namespace xqp
