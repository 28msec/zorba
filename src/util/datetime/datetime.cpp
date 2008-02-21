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
#include "util/datetime/duration.h"

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

static long abs(long value)
{
  if (value < 0)
    return -value;
  else
    return value;
}

DateTime::DateTime(const Date_t& d_t, const Time_t& t_t)
{
  if (d_t->getYear() < 0)
    is_negative = true;
  
  the_date_time = boost::posix_time::ptime(
      boost::gregorian::date(abs(d_t->getYear()), abs(d_t->getMonth()), abs(d_t->getDay())),
      t_t->get_time_duration());
}

int DateTime::parse_string(const xqpString& s, DateTime_t& dt_t)
{
  unsigned int time_zone_start;
  unsigned int position = 0;
  int frac_start;
  long temp_frac;
  std::string ss;
  TimeZone_t tz_t;
  bool is_negative;

  // DateTime is of form: '-'? yyyy '-' mm '-' dd 'T' hh ':' mm ':' ss ('.' s+)? (zzzzzz)?

  ss = *s.translate("T", " ").getStore(); // replace "T" with " ", which is what boost expects

  skip_whitespace(ss, position);
  if (position == ss.size())
    return 1;

  if (ss[position] == '-')
  {
    is_negative = 1;
    position++;
  }
  
  frac_start = s.indexOf(".");
  if (frac_start != -1)
  {
    time_zone_start = frac_start + 1;
    parse_int(ss, (unsigned int&)time_zone_start, temp_frac);
  }
  else
    time_zone_start = position+19;

  RETURN_1_ON_EXCEPTION(
    dt_t = new DateTime(is_negative, boost::posix_time::time_from_string(ss.substr(position,time_zone_start-position))); );

  if (ss.size() > time_zone_start)
  {
    if (!TimeZone::parse_string(ss.substr(time_zone_start), tz_t))
      return 1;
    dt_t->the_time_zone = *tz_t;
  }

  return 0;
}

DateTime& DateTime::operator=(const DateTime_t& dt_t)
{
  is_negative = dt_t->is_negative;
  the_date_time = dt_t->the_date_time;
  return *this;
}

bool DateTime::operator<(const DateTime& dt) const
{
  if (is_negative != dt.is_negative)
    return (is_negative == true);
  else
    return (the_date_time < dt.the_date_time);
}

bool DateTime::operator==(const DateTime& dt) const
{
  return (the_date_time == dt.the_date_time);
}

xqpString DateTime::toString() const
{
  xqpString result = boost::posix_time::to_iso_extended_string(the_date_time);
  result += the_time_zone.toString();
  // TODO:
  return result;
}

int DateTime::compare(const DateTime& dt) const
{
  // TODO: handle timezone
  if (operator<(dt))
    return -1;
  else if (operator==(dt))
    return 0;
  else
    return 1;
}

int DateTime::getYear() const
{
  return (is_negative? -1 : 1) * the_date_time.date().year();
}

int DateTime::getMonth() const
{
  return the_date_time.date().month();
}

int DateTime::getDay() const
{
  return the_date_time.date().day();
}

int DateTime::getHours() const
{
  return the_date_time.time_of_day().hours();
}

int DateTime::getMinutes() const
{
  return the_date_time.time_of_day().minutes();
}

double DateTime::getSeconds() const
{
  double frac_sec = the_date_time.time_of_day().fractional_seconds();
  while(frac_sec > 1)
  {
    frac_sec = frac_sec /10;
  }
  
  return the_date_time.time_of_day().seconds() + frac_sec;
}

TimeZone DateTime::getTimezone() const
{
  return the_time_zone;
}

DateTime_t operator+(const DateTime& dt, const Duration& d)
{
  DateTime_t dt_t;
  int years, months, days, hours, minutes, int_seconds, frac_seconds, temp_days, carry;

  // For the algorithm, see XML Schema 2 spec, Appendix E
  // http://www.w3.org/TR/xmlschema-2/#adding-durations-to-dateTimes
  
  months = modulo<int>(dt.getMonth() + d.getMonths() - 1, 12) + 1;
  years = dt.getYear() + d.getYears() + quotient<int>(dt.getMonth() + d.getMonths() - 1, 12);

  int_seconds = modulo<int>(floor(dt.getSeconds() + d.getSeconds()), 60);                            // TODO: frac_seconds
  minutes = dt.getMinutes() + d.getMinutes() + quotient<int>(floor(dt.getSeconds() + d.getSeconds()), 60);
  hours = dt.getHours() + d.getHours() + quotient<int>(minutes, 60);
  minutes = modulo<int>(minutes, 60);
  carry = quotient<int>(hours, 24);
  hours = modulo<int>(hours, 24);

  if (dt.getDay() > get_last_day(years, months))
    temp_days = get_last_day(years, months);
  else if (dt.getDay() < 1)
    temp_days = 1;
  else
    temp_days = dt.getDay();

  days = d.getDays() + temp_days + carry;
  while (1)
  {
    if (days <1)
    {
      days = days + get_last_day(years,months-1);
      carry = -1;
    }
    else if (days > get_last_day(years, months))
    {
      days = days - get_last_day(years, months);
      carry = 1;
    }
    else
      break;

    years = years + quotient<int>(months + carry-1, 12);
    months = modulo<int>(months + carry -1, 12) + 1;
  }

  return NULL;
}

} // namespace xqp
