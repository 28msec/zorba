/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include <exception> // TODO for what?

#include <zorba/date.h>
#include <zorba/datetime.h>
#include <zorba/timezone.h>
#include <zorba/xqpstring.h>

#include "util/datetime/parse.h"
#include "util/numconversions.h"

using namespace std;

namespace xqp
{

int Date::parse_string(const xqpString& s, Date_t& d_t)
{
  unsigned int position = 0;
  bool is_negative = false;
  std::string ss = *s.getStore();
  TimeZone_t tz_t;

  // date is in form of '-'? yyyy '-' mm '-' dd zzzzzz?
  

  skip_whitespace(ss, position);
  if (position == ss.size())
    return 1;

  if (ss[position] == '-')
  {
    is_negative = 1;
    position++;
  }

  d_t = new Date();

  // Parse year
  if (position == ss.size() || parse_int(ss, position, d_t->year, 4))
    return 1;
  if (is_negative)
    d_t->year = -d_t->year;
  if (position == ss.size() || ss[position++] != '-')
    return 1;

  // Parse month
  if (position == ss.size() || parse_int(ss, position, d_t->month, 2, 2))
    return 1;
  if (position == ss.size() || ss[position++] != '-')
    return 1;

  // Parse day
  if (position == ss.size() || parse_int(ss, position, d_t->day, 2, 2))
    return 1;

  if (position != ss.size())
  {
    // we might have a timezone
    if (!TimeZone::parse_string(ss.substr(position), tz_t))
      return 1;
    d_t->the_time_zone = *tz_t;
  }

  // Validate the date
  // year can be anything
  if (d_t->month < 1 || d_t->month > 12)
    return 1;

  if (d_t->day < 1 || d_t->day > get_last_day(d_t->year, d_t->month))
    return 1;

  return 0;
}

int Date::createDate(int a_year, int a_month, int a_day, Date_t& d_t)
{
  if (a_month < 1 || a_month > 12)
    return 1;
  if (a_day < 1 || a_day > get_last_day(a_year, a_month))
    return 1;

  d_t = new Date();
  d_t->year = a_year;
  d_t->month = a_month;
  d_t->day = a_day;
  return 0;
}

int Date::createDate(int a_year, int a_month, int a_day, const TimeZone& tz, Date_t& d_t)
{
  if (1 == createDate(a_year, a_month, a_day, d_t))
    return 1;
  
  d_t->the_time_zone = tz;
  return 0;
}

Date& Date::operator=(const Date_t& d_t)
{
  year = d_t->year;
  month = d_t->month;
  day = d_t->day;
  return *this;
}

bool Date::operator<(const Date& d) const
{
  // TODO: check timezone
  if (year < d.year
     ||
     (year == d.year && month < d.month)
     ||
     (year == d.year && month == d.month && day < d.day))
    return true;
  else
    return false;
}

bool Date::operator==(const Date& d) const
{
  // TODO: check timezone
  return (year == d.year && month == d.month && day == d.day);
}

int Date::compare(const Date& d) const
{
  // TODO: handle timezone
  if (operator<(d))
    return -1;
  else if (operator==(d))
    return 0;
  else
    return 1;
}

DateTime_t Date::toDateTime() const
{
  DateTime_t dt_t;
  DateTime::createDateTime(year<0, year, month, day, 0, 0, 0, 0, the_time_zone, dt_t);
  return dt_t;
}

xqpString Date::toString() const
{
  xqpString result = NumConversions::longToStr(year) + "-";

  if (month < 10)
    result += "0";
  result += NumConversions::longToStr(month) + "-";

  if (day < 10)
    result += "0";
  result += NumConversions::longToStr(day);
      
  result += the_time_zone.toString();
  return result;
}

int Date::getYear() const
{
  return year;
}

int Date::getMonth() const
{
  return month;
}

int Date::getDay() const
{
  return day;
}

TimeZone Date::getTimezone() const
{
  return the_time_zone;
}

Date_t operator+(const Date& d, const Duration& dur)
{
  Date_t d_t;
  DateTime_t dt_t = *d.toDateTime() + dur;
  Date::createDate(dt_t->getYear(), dt_t->getMonth(), dt_t->getDay(), dt_t->getTimezone(), d_t);
  return d_t;
}

} // namespace xqp
