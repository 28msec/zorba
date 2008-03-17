/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include <exception>
#include <cassert>
#include <zorbatypes/datetime.h>
#include <zorbatypes/zorba_time.h>
#include <zorbatypes/date.h>
#include <zorbatypes/duration.h>
#include <zorbatypes/timezone.h>
#include <zorbatypes/zorbatypes_decl.h>
#include <errors/error_factory.h>

#include "system/zorba.h"
#include "system/zorba_engine.h"
#include "zorbatypes/datetime/parse.h"
#include "context/dynamic_context.h"

using namespace std;

namespace zorba
{
  
static const char separators[] = {'-', '-', 'T', ':', ':'};
static const char min_length[] = { 4, 2, 2, 2, 2, 2};
  
const int DateTime::FRAC_SECONDS_UPPER_LIMIT = 1000000;

DateTime::DateTime()
  : 
  facet(DATETIME_FACET)
{ 
  for (int i=0; i<7; i++)
    data[i] = 0;
}

DateTime::DateTime(boost::posix_time::ptime t)
{
  data[YEAR_DATA] = t.date().year();
  data[MONTH_DATA] = t.date().month();
  data[DAY_DATA] = t.date().day();
  data[HOUR_DATA] = t.time_of_day().hours();
  data[MINUTE_DATA] = t.time_of_day().minutes();
  data[SECONDS_DATA] = t.time_of_day().seconds();
  data[FRACSECONDS_DATA] = t.time_of_day().fractional_seconds();
}

DateTime::DateTime(const Date_t& d_t, const Time_t& t_t)
{
  facet = DATETIME_FACET;
  data[YEAR_DATA] = d_t->getYear();
  data[MONTH_DATA] = d_t->getMonth();
  data[DAY_DATA] = d_t->getDay();
  data[HOUR_DATA] = t_t->getHours();
  data[MINUTE_DATA] = t_t->getMinutes();
  data[SECONDS_DATA] = floor<double>(t_t->getSeconds());
  data[FRACSECONDS_DATA] = round(frac(t_t->getSeconds()) * FRAC_SECONDS_UPPER_LIMIT);
  
  if (!d_t->getTimezone().is_not_a_date_time() 
       && 
       !t_t->getTimezone().is_not_a_date_time()
       &&
       !(d_t->getTimezone() == t_t->getTimezone()))
    ZORBA_ERROR_ALERT(ZorbaError::FORG0008);
  
  if (!d_t->getTimezone().is_not_a_date_time())
    the_time_zone = d_t->getTimezone();
  else if (!t_t->getTimezone().is_not_a_date_time())
    the_time_zone = t_t->getTimezone();
}

// Returns 0 on success
int DateTime::parse_date(std::string& ss, unsigned int& position, int& year, int& month, int& day)
{
  bool is_negative = false;
  unsigned int temp_position;
  
  if (position == ss.size())
    return 1;

  if (ss[position] == '-')
  {
    is_negative = true;
    position++;
  }

  // Parse year
  temp_position = position;
  if (position == ss.size() || parse_int(ss, position, year, 4))
    return 1;
  if (position - temp_position > 4 
      &&
      ss[temp_position] == '0')
    return 1;
  if (is_negative)
    year = -year;
  if (position == ss.size() || ss[position++] != '-')
    return 1;

  // Parse month
  if (position == ss.size() || parse_int(ss, position, month, 2, 2))
    return 1;
  if (position == ss.size() || ss[position++] != '-')
    return 1;

  // Parse day
  if (position == ss.size() || parse_int(ss, position, day, 2, 2))
    return 1;
  
  // Validate the date
  // year may not be 0
  if (year == 0)
    return 1;
  
  if (month < 1 || month > 12)
    return 1;

  if (day < 1 || day > get_last_day(year, month))
    return 1;
  
  return 0;
}

// Returns 0 on success
int DateTime::parse_time(std::string& ss, unsigned int& position, int& hour, int& minute, int& seconds, int& frac_seconds)
{
  if (position == ss.size())
    return 1;
  
  // Parse hour
  if (position == ss.size() || parse_int(ss, position, hour, 2, 2))
    return 1;
  if (position == ss.size() || ss[position++] != ':')
    return 1;

  // Parse minute
  if (position == ss.size() || parse_int(ss, position, minute, 2, 2))
    return 1;
  if (position == ss.size() || ss[position++] != ':')
    return 1;

  // Parse seconds
  if (position == ss.size() || parse_int(ss, position, seconds, 2, 2))
    return 1;
  
  if (position < ss.size() && ss[position] == '.')
  {
    position++;
    if (parse_int(ss, position, frac_seconds))
      return 1;
    
    if (frac_seconds != 0)
    {
      // make sure we keep the correct number of digits
      while (frac_seconds*10 < FRAC_SECONDS_UPPER_LIMIT)
        frac_seconds *= 10;
    
      while (frac_seconds >= FRAC_SECONDS_UPPER_LIMIT)
        frac_seconds = round(frac_seconds/10.0); 
    }
  }
  else
    frac_seconds = 0;
  
  // Validate the time
  if (hour > 24)
    return 1;
  
  if (minute > 59)
    return 1;
  if (hour == 24 && minute != 0)
    return 1;
  
  if (seconds > 59)
    return 1;
  if (hour == 24 && (seconds != 0 || frac_seconds != 0))
    return 1;
  
  return 0;
}

int DateTime::parseDateTime(const xqpString& s, DateTime_t& dt_t)
{
  TimeZone_t tz_t;
  unsigned int position = 0;
  std::string ss = *s.getStore();
  dt_t = new DateTime();
  
  // DateTime is of form: '-'? yyyy '-' mm '-' dd 'T' hh ':' mm ':' ss ('.' s+)? (zzzzzz)?
  
  skip_whitespace(ss, position);
  dt_t->facet = DATETIME_FACET;
  
  if (parse_date(ss, position, dt_t->data[YEAR_DATA], dt_t->data[MONTH_DATA], dt_t->data[DAY_DATA]))
    return 1;
  if (position == ss.size() || ss[position++] != 'T')
    return 1;
  
  if (parse_time(ss, position, dt_t->data[HOUR_DATA], dt_t->data[MINUTE_DATA], dt_t->data[SECONDS_DATA], dt_t->data[FRACSECONDS_DATA]))
    return 1;
  
  if (position < ss.size())
  {
    if (!TimeZone::parse_string(ss.substr(position), tz_t))
      return 1;
    dt_t->the_time_zone = *tz_t;
  }
  
  if (dt_t->data[HOUR_DATA] == 24)
  {
    dt_t->data[HOUR_DATA] = 0;
    dt_t = *dt_t + Duration(DayTimeDuration(false, 1, 0, 0, 0, 0));
  }
  
  return 0;
}

int DateTime::parseDate(const xqpString& s, DateTime_t& dt_t)
{
  TimeZone_t tz_t;
  unsigned int position = 0;
  std::string ss = *s.getStore();
  dt_t = new DateTime();
  
  skip_whitespace(ss, position);
  dt_t->facet = DATE_FACET;
  
  if (parse_date(ss, position, dt_t->data[YEAR_DATA], dt_t->data[MONTH_DATA], dt_t->data[DAY_DATA]))
    return 1;

  if (position < ss.size())
  {
    if (!TimeZone::parse_string(ss.substr(position), tz_t))
      return 1;
    dt_t->the_time_zone = *tz_t;
  }
  
  return 0;
}

int DateTime::parseTime(const xqpString& s, DateTime_t& dt_t)
{
  TimeZone_t tz_t;
  unsigned int position = 0;
  std::string ss = *s.getStore();
  dt_t = new DateTime();
  
  skip_whitespace(ss, position);
  dt_t->facet = TIME_FACET;
  
  if (parse_time(ss, position, dt_t->data[HOUR_DATA], dt_t->data[MINUTE_DATA], dt_t->data[SECONDS_DATA], dt_t->data[FRACSECONDS_DATA]))
    return 1;
  
  if (position < ss.size())
  {
    if (!TimeZone::parse_string(ss.substr(position), tz_t))
      return 1;
    dt_t->the_time_zone = *tz_t;
  }
  
  return 0;
}

int DateTime::createDateTime(int years, int months, int days,
                            int hours, int minutes, int seconds, int fractional_seconds, TimeZone_t& tz_t, DateTime_t& dt_t)
{
  dt_t = new DateTime();
  dt_t->facet = DATETIME_FACET;
  dt_t->data[YEAR_DATA] = years;
  dt_t->data[MONTH_DATA] = abs<int>(months);
  dt_t->data[DAY_DATA] = abs<int>(days);
  dt_t->data[HOUR_DATA] = abs<int>(hours);
  dt_t->data[MINUTE_DATA] = abs<int>(minutes);
  dt_t->data[SECONDS_DATA] = abs<int>(seconds);
  dt_t->data[FRACSECONDS_DATA] = abs<int>(fractional_seconds);
      
  if (!tz_t.isNull())
    dt_t->the_time_zone = *tz_t;
  
  return 0;
}

int DateTime::createDateTime(int years, int months, int days,
                            int hours, int minutes, int seconds, int fractional_seconds, const TimeZone& tz, DateTime_t& dt_t)
{
  dt_t = new DateTime();
  dt_t->facet = DATETIME_FACET;
  dt_t->data[YEAR_DATA] = years;
  dt_t->data[MONTH_DATA] = abs<int>(months);
  dt_t->data[DAY_DATA] = abs<int>(days);
  dt_t->data[HOUR_DATA] = abs<int>(hours);
  dt_t->data[MINUTE_DATA] = abs<int>(minutes);
  dt_t->data[SECONDS_DATA] = abs<int>(seconds);
  dt_t->data[FRACSECONDS_DATA] = abs<int>(fractional_seconds);
      
  dt_t->the_time_zone = tz;

  return 0;
}

DurationBase_t DateTime::toDayTimeDuration() const
{
  if (data[YEAR_DATA] >= 0)
    return new DayTimeDuration(false, 
      365 * (abs<int>(data[YEAR_DATA]) - 1) + leap_years_count(data[YEAR_DATA])
      + days_since_year_start(data[YEAR_DATA], data[MONTH_DATA], data[DAY_DATA]),
      data[HOUR_DATA], data[MINUTE_DATA], data[SECONDS_DATA], data[FRACSECONDS_DATA]);
  else
  {
    DayTimeDuration days(true, 365 * abs<int>(data[YEAR_DATA]) - leap_years_count(data[YEAR_DATA]) + 1
        - days_since_year_start(data[YEAR_DATA], data[MONTH_DATA], data[DAY_DATA]),
        0, 0, 0, 0);
    
    DayTimeDuration remainder(false, 0, data[HOUR_DATA], data[MINUTE_DATA], data[SECONDS_DATA], data[FRACSECONDS_DATA]);
    
    return days + remainder;
  }
}

DateTime& DateTime::operator=(const DateTime_t& dt_t)
{
  facet = dt_t->facet;
  for (int i=0; i<7; i++)
    data[i] = dt_t->data[i];
  the_time_zone = dt_t->the_time_zone;
  return *this;
}

bool DateTime::operator<(const DateTime& dt) const
{
  DateTime_t d1_t = normalizeTimeZone();
  DateTime_t d2_t = dt.normalizeTimeZone();
  
  // TODO: timezone
  // assume both datetimes have the same facet // TODO: check
  
  if (d1_t->data[YEAR_DATA] < d2_t->data[YEAR_DATA])
    return true;
  
  if (d1_t->data[YEAR_DATA] < 0 && d2_t->data[YEAR_DATA] < 0)
  {
    // both are negative
    for (int i=1; i<7; i++)
      if (d1_t->data[i] > d2_t->data[i])
        return true;
  }
  else
  {
    for (int i=1; i<7; i++)
      if (d1_t->data[i] < d2_t->data[i])
        return true;
  }
    
  return false;
}

bool DateTime::operator==(const DateTime& dt) const
{
  DateTime_t d1_t = normalizeTimeZone();
  DateTime_t d2_t = dt.normalizeTimeZone();
  
  // TODO: timezone
  for (int i=0; i<7; i++)
    if (d1_t->data[i] != d2_t->data[i])
      return false;
  
  return true;
}

int DateTime::compare(const DateTime& dt) const
{
  // TODO: handle timezone
  DateTime_t d1_t = normalizeTimeZone();
  DateTime_t d2_t = dt.normalizeTimeZone();
  
  if (d1_t->data[YEAR_DATA] < d2_t->data[YEAR_DATA])
    return -1;
  else if (d1_t->data[YEAR_DATA] > d2_t->data[YEAR_DATA])
    return 1;
  
  if (d1_t->data[YEAR_DATA] < 0 && d2_t->data[YEAR_DATA] < 0)
  {
    for (int i=1; i<7; i++)
      if (d1_t->data[i] > d2_t->data[i])
        return -1;
      else if (d1_t->data[i] < d2_t->data[i])
        return 1;
  }
  else
  {
    for (int i=1; i<7; i++)
      if (d1_t->data[i] < d2_t->data[i])
        return -1;
      else if (d1_t->data[i] > d2_t->data[i])
        return 1;
  }
  
  return 0;
  
  /*
  if (operator<(dt))
    return -1;
  else if (operator==(dt))
    return 0;
  else
    return 1;
  */
}

DurationBase_t DateTime::operator-(const DateTime& dt) const
{
  return *normalizeTimeZone()->toDayTimeDuration() - *dt.normalizeTimeZone()->toDayTimeDuration();
}

DateTime_t DateTime::normalize(const long tz_seconds)
{
  if( the_time_zone.is_not_a_date_time() )
  {
    boost::posix_time::time_duration tz( 0, 0, abs<int>(tz_seconds), 0 );
    boost::posix_time::time_duration td;
    //boost::posix_time::time_duration td(the_date_time.time_of_day().hours(), the_date_time.time_of_day().minutes(),
    //                                    the_date_time.time_of_day().seconds(), the_date_time.time_of_day().fractional_seconds());

    tz = tz_seconds < 0 ? td + tz: td - tz;
    
    DateTime_t new_dt_t;

    DateTime::createDateTime(getYear(), getMonth(), getDay(), tz.hours(), tz.minutes(),
                             tz.seconds(), tz.fractional_seconds(), tz, new_dt_t);
 
    return new_dt_t;
  }
  else
    return this;
}

xqpString DateTime::toString() const
{
  xqpString result;
  
  // TODO: output based on the facet

  if (data[YEAR_DATA] < 0)
    result += "-";
  
  for (int i=0; i<6; i++)
  {
    result += to_string(abs<int>(data[i]), min_length[i]);  // abs<> only needed for year
    if (i<5)
      result += separators[i];
  }
  
  if (data[FRACSECONDS_DATA] != 0)
  {
    int temp = data[FRACSECONDS_DATA];
    while (temp%10 == 0)
      temp = temp / 10;
    
    result += '.';
    result += to_string(temp);
  }
  
  result += the_time_zone.toString();
  
  return result;
}

Date_t DateTime::getDate() const
{
  Date_t new_dt_t;
  if (Date::createDate(data[YEAR_DATA], data[MONTH_DATA], data[DAY_DATA], the_time_zone, new_dt_t))
    assert(0);
  return new_dt_t;
}

Time_t DateTime::getTime() const
{
  Time_t new_t_t;
  if (Time::createTime(data[HOUR_DATA], data[MINUTE_DATA], getSeconds(), the_time_zone, new_t_t))
    assert(0);
  return new_t_t;
}

int DateTime::getYear() const
{
  return data[YEAR_DATA];
}

int DateTime::getMonth() const
{
  assert(data[MONTH_DATA] >= 0);
  return data[MONTH_DATA];
}

int DateTime::getDay() const
{
  assert(data[DAY_DATA] >= 0);
  return data[DAY_DATA];
}

int DateTime::getHours() const
{
  assert(data[HOUR_DATA] >= 0);
  return data[HOUR_DATA];
}

int DateTime::getMinutes() const
{
  assert(data[MINUTE_DATA] >= 0);
  return data[MINUTE_DATA];
}

double DateTime::getSeconds() const
{
  return data[SECONDS_DATA] + (1.0 * data[FRACSECONDS_DATA] / FRAC_SECONDS_UPPER_LIMIT);
}

TimeZone DateTime::getTimezone() const
{
  return the_time_zone;
}

DateTime_t DateTime::normalizeTimeZone(int tz_seconds) const
{
  Duration_t d_t;

  if( the_time_zone.is_not_a_date_time() )
  {
    // TODO: validate timezone value (-14 .. +14 H)
    d_t = new Duration(DayTimeDuration((tz_seconds<0), 0, 0, 0, tz_seconds, 0));
  }
  else
  {
    if (Duration::from_Timezone(the_time_zone, d_t))
      assert(0);
  }

  return *this - *d_t;
}

DateTime_t DateTime::normalizeTimeZone() const
{
  Duration_t d_t;

  if( the_time_zone.is_not_a_date_time() )
  {
    // TODO: validate timezone value (-14 .. +14 H)
    int timezone_secs = ZORBA_FOR_CURRENT_THREAD()->get_base_dynamic_context()->get_implicit_timezone();
    d_t = new Duration(DayTimeDuration((timezone_secs<0), 0, 0, 0, timezone_secs, 0));
  }
  else
  {
    if (Duration::from_Timezone(the_time_zone, d_t))
      assert(0);
  }
  
  return *this - *d_t;
}

DateTime_t DateTime::adjustToTimeZone(int tz_seconds) const
{
  DayTimeDuration_t dtduration_t;
  DayTimeDuration_t context_tz_t;
  DateTime_t dt_t;
  TimeZone_t tz_t;

  // If $timezone is not specified, then $timezone is the value of the implicit timezone in the dynamic context.
  context_tz_t = new DayTimeDuration((tz_seconds<0), 0, 0, 0, tz_seconds, 0);

  // TODO: validate timezone value (-14 .. +14 H)
  dt_t = new DateTime(*this);
  
  // If $arg does not have a timezone component and $timezone is not the empty sequence,
  // then the result is $arg with $timezone as the timezone component.
  if (the_time_zone.is_not_a_date_time())
  {
    if (TimeZone::createTimeZone(context_tz_t->getHours(), context_tz_t->getMinutes(), context_tz_t->getSeconds(), tz_t))
      assert(0);
    dt_t->the_time_zone = *tz_t;
  }
  else
  {
      // If $arg has a timezone component and $timezone is not the empty sequence, then
      // the result is an xs:dateTime value with a timezone component of $timezone that is equal to $arg.
    dtduration_t = new DayTimeDuration(the_time_zone.is_negative(), 0, the_time_zone.getHours(),
                                       the_time_zone.getMinutes(), the_time_zone.getSeconds(), 0);

    dtduration_t = *context_tz_t - *dtduration_t;
    dt_t = *dt_t + *dtduration_t->toDuration();
    if (TimeZone::createTimeZone(context_tz_t->getHours(), context_tz_t->getMinutes(), context_tz_t->getSeconds(), tz_t))
      assert(0);
    dt_t->the_time_zone = *tz_t;
  }

  return dt_t;
}

DateTime_t DateTime::adjustToTimeZone(const DurationBase_t& db_t) const
{
  DateTime_t dt_t;
  DayTimeDuration_t dtduration_t;
  DayTimeDuration_t context_tz_t;
  TimeZone_t tz_t;

  // A dynamic error is raised [err:FODT0003] if $timezone is less than -PT14H or greater than PT14H or
  // if does not contain an integral number of minutes.
  // TODO: validate timezone value (-14 .. +14 H)
  
  dt_t = new DateTime(*this);
  
  if (db_t.isNull())
  {
    if (!the_time_zone.is_not_a_date_time())
      dt_t->the_time_zone = TimeZone();
  }
  else
  {
    // If $arg does not have a timezone component and $timezone is not the empty sequence,
    // then the result is $arg with $timezone as the timezone component.
    if (the_time_zone.is_not_a_date_time())
    {
      if (TimeZone::createTimeZone(db_t->getHours(), db_t->getMinutes(), db_t->getSeconds(), tz_t))
        assert(0);
      dt_t->the_time_zone = *tz_t;
    }
    else
    {
      // If $arg has a timezone component and $timezone is not the empty sequence, then
      // the result is an xs:dateTime value with a timezone component of $timezone that is equal to $arg.
      dtduration_t = new DayTimeDuration(the_time_zone.is_negative(), 0, the_time_zone.getHours(),
                                         the_time_zone.getMinutes(), the_time_zone.getSeconds(), 0);

      context_tz_t = dynamic_cast<DayTimeDuration*>(db_t.getp());
      if (context_tz_t.isNull())
        assert(0);

      dtduration_t = *context_tz_t - *dtduration_t;
      dt_t = *dt_t + *dtduration_t->toDuration();
      if (TimeZone::createTimeZone(context_tz_t->getHours(), context_tz_t->getMinutes(), context_tz_t->getSeconds(), tz_t))
        assert(0);
      dt_t->the_time_zone = *tz_t;
    }
  }

  return dt_t;
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
  frac_seconds = round(temp_frac_seconds * DateTime::FRAC_SECONDS_UPPER_LIMIT);
  
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

  // TODO: make sure year is not 0

  if (DateTime::createDateTime(years, months, days, hours, minutes, int_seconds, frac_seconds,
                            dt.getTimezone(), new_dt_t))
    assert(0);

  return new_dt_t;
}

DateTime_t operator-(const DateTime& dt, const Duration& d)
{
  return dt + *d.toNegDuration();
}

} // namespace xqp
