/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include <exception>
#include <zorba/datetime.h>
#include <zorba/time.h>
#include <zorba/date.h>
#include <zorba/duration.h>

#include "util/datetime/parse.h"

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

DateTime::DateTime(const Date_t& d_t, const Time_t& t_t)
{
  is_negative = (d_t->getYear() < 0);
  
  the_date_time = boost::posix_time::ptime(
      boost::gregorian::date(abs<int>(d_t->getYear()), abs<int>(d_t->getMonth()), abs<int>(d_t->getDay())),
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
  bool is_negative = false;

  // DateTime is of form: '-'? yyyy '-' mm '-' dd 'T' hh ':' mm ':' ss ('.' s+)? (zzzzzz)?

  ss = *s.translate("T", " ").getStore(); // replace "T" with " ", which is what boost expects

  skip_whitespace(ss, position);
  if (position == ss.size())
    return 1;

  if (ss[position] == '-')
  {
    is_negative = true;
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

int DateTime::createDateTime(bool is_negative, int years, int months, int days,
                            int hours, int minutes, int seconds, int fractional_seconds, TimeZone_t& tz_t, DateTime_t& dt_t)
{
  dt_t = new DateTime(is_negative, boost::posix_time::ptime(
    boost::gregorian::date(abs<int>(years), abs<int>(months), abs<int>(days)),
    boost::posix_time::time_duration(abs<int>(hours), abs<int>(minutes), abs<int>(seconds), abs<int>(fractional_seconds))));

  if (!tz_t.isNull())
    dt_t->the_time_zone = *tz_t;

  return 0;
}

int DateTime::createDateTime(bool is_negative, int years, int months, int days,
                            int hours, int minutes, int seconds, int fractional_seconds, const TimeZone& tz, DateTime_t& dt_t)
{
  dt_t = new DateTime(is_negative, boost::posix_time::ptime(
    boost::gregorian::date(abs<int>(years), abs<int>(months), abs<int>(days)),
    boost::posix_time::time_duration(abs<int>(hours), abs<int>(minutes), abs<int>(seconds), abs<int>(fractional_seconds))));

  dt_t->the_time_zone = tz;

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

DayTimeDuration_t DateTime::operator-(const DateTime& dt) const
{
  boost::posix_time::time_duration td;
  td = the_date_time - dt.the_date_time;
  
  DayTimeDuration_t d_t = new DayTimeDuration(
      the_date_time <= dt.the_date_time ? true: false,
      quotient<int>(td.hours(), 24),
      modulo<int>(td.hours(), 24),
      td.minutes(),
      td.seconds(),
      td.fractional_seconds());
 
  return d_t;
}

DateTime_t  DateTime::normalize(const long tz_seconds)
{
  if( the_time_zone.is_not_a_date_time() )
  {
    boost::posix_time::time_duration tz( 0, 0, tz_seconds, 0 );
    boost::posix_time::time_duration td(the_date_time.time_of_day().hours(), the_date_time.time_of_day().minutes(),
                                        the_date_time.time_of_day().seconds(), the_date_time.time_of_day().fractional_seconds());

    tz = tz_seconds < 0 ? td - tz: td + tz;
    
    DateTime_t new_dt_t;

    DateTime::createDateTime(is_negative, getYear(), getMonth(), getDay(), tz.hours(), tz.minutes(),
                             tz.seconds(), tz.fractional_seconds(), tz, new_dt_t);
 
    return new_dt_t;
  }
  else
    return this;
}

xqpString DateTime::toString() const
{
  xqpString result;

  if (is_negative)
    result += "-";
  
  result += boost::posix_time::to_iso_extended_string(the_date_time);
  result += the_time_zone.toString();
  
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
  return (is_negative? -1 : 1) * abs<int>(the_date_time.date().year());
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
  double frac_sec = double(the_date_time.time_of_day().fractional_seconds()) / boost::posix_time::time_duration::ticks_per_second();
  return the_date_time.time_of_day().seconds() + frac_sec;
}

TimeZone DateTime::getTimezone() const
{
  return the_time_zone;
}

DateTime_t operator+(const DateTime& dt, const Duration& d)
{
  DateTime_t new_dt_t;
  int years, months, days, hours, minutes, int_seconds, frac_seconds, temp_days, carry;
  double temp_frac_seconds;

  // For the algorithm, see XML Schema 2 spec, Appendix E
  // http://www.w3.org/TR/xmlschema-2/#adding-durations-to-dateTimes
  
  months = modulo<int>(dt.getMonth() + d.getMonths() - 1, 12) + 1;
  years = dt.getYear() + d.getYears() + quotient<int>(dt.getMonth() + d.getMonths() - 1, 12);

  int_seconds = modulo<int>(floor(dt.getSeconds() + d.getSeconds()), 60);
  temp_frac_seconds = (dt.getSeconds() + d.getSeconds() - floor(dt.getSeconds() + d.getSeconds()));
  frac_seconds = round(temp_frac_seconds * boost::posix_time::time_duration::ticks_per_second());
  
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

  // TODO: find out if the dateTime is negative
  DateTime::createDateTime((years<0), years, months, days, hours, minutes, int_seconds, frac_seconds,
                            dt.getTimezone(), new_dt_t);

  return new_dt_t;
}

} // namespace xqp
