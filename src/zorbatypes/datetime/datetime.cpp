/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include <exception>
#include <zorbatypes/datetime.h>
#include <zorbatypes/duration.h>
#include <zorbatypes/timezone.h>
#include <zorbatypes/zorbatypes_decl.h>

#include "zorbatypes/datetime/parse.h"

using namespace std;

static const int FACET_MEMBERS[][7] = {
  { 1, 1, 1, 1, 1, 1, 1},    // DATETIME_FACET = 0,
  { 1, 1, 1, 0, 0, 0, 0},    // DATE_FACET = 1,
  { 0, 0, 0, 1, 1, 1, 1},    // TIME_FACET = 2,
  { 1, 1, 0, 0, 0, 0, 0}    // GYEARMONTH_FACET = 3
};

namespace zorba
{
  
static const char separators[] = {'-', '-', 'T', ':', ':'};
static const char min_length[] = { 4, 2, 2, 2, 2, 2};
  
const int DateTime::FRAC_SECONDS_UPPER_LIMIT = 1000000;

DateTime::DateTime()
  : 
  facet(DATETIME_FACET)
{ 
  for (int i=YEAR_DATA; i<=DAY_DATA; i++)
    data[i] = 1;
  
  for (int i=HOUR_DATA; i<=FRACSECONDS_DATA; i++)
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

int DateTime::createDateTime(const DateTime_t& date_t, const DateTime_t& time_t, DateTime_t& result_t)
{
  if (!date_t->getTimezone().is_not_a_date_time()
       &&
       !time_t->getTimezone().is_not_a_date_time()
       &&
       !(date_t->getTimezone() == time_t->getTimezone()))
    return 2;

  int res = createDateTime(date_t->getYear(), date_t->getMonth(), date_t->getDay(), time_t->getHours(), time_t->getMinutes(),
                           floor<double>(time_t->getSeconds()), round(frac(time_t->getSeconds()) * FRAC_SECONDS_UPPER_LIMIT), result_t);

  if (res == 0)
  {
    if (!date_t->getTimezone().is_not_a_date_time())
      result_t->the_time_zone = date_t->getTimezone();
    else if (!time_t->getTimezone().is_not_a_date_time())
      result_t->the_time_zone = time_t->getTimezone();
  }

  return res;
}

int DateTime::createDateTime(int years, int months, int days,
                             int hours, int minutes, int seconds, int fractional_seconds, DateTime_t& dt_t)
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
    dt_t = dt_t->addDuration(Duration(DayTimeDuration(false, 1, 0, 0, 0, 0)));
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
  
  if (dt_t->data[HOUR_DATA] == 24)
    dt_t->data[HOUR_DATA] = 0;
  
  return 0;
}

int DateTime::parseGYearMonth(const xqpString& s, DateTime_t& dt_t)
{
  TimeZone_t tz_t;
  unsigned int position = 0;
  std::string ss = *s.getStore();
  dt_t = new DateTime();
  
  // GYearMonth of form: '-'? yyyy '-' mm zzzzzz?
  
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
  
  if (dt_t->data[HOUR_DATA] == 24)
    dt_t->data[HOUR_DATA] = 0;
  
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
    DayTimeDuration days(true, 365 * abs<int>(data[YEAR_DATA]) - leap_years_count(data[YEAR_DATA])
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

int DateTime::compare(const DateTime& dt) const
{
  // TODO: handle timezone
  DateTime_t d1_t, d2_t;
  
  d1_t = normalizeTimeZone(0);
  d2_t = dt.normalizeTimeZone(0);
  
  /*
  d1_t->facet = DATETIME_FACET;
  d2_t->facet = DATETIME_FACET;
  
  cout << "d1: " << d1_t->toString() << endl;
  cout << "d2: " << d2_t->toString() << endl;
  
  d1_t = normalizeTimeZone(0);
  d2_t = dt.normalizeTimeZone(0);
  
  cout << "d1: " << d1_t->toString() << endl;
  cout << "d2: " << d2_t->toString() << endl;
  */
  
  // compare signed year first
  // if (FACET_MEMBERS[d1_t->facet][YEAR_DATA] && FACET_MEMBERS[d2_t->facet][YEAR_DATA])
  {
    if (d1_t->data[YEAR_DATA] < d2_t->data[YEAR_DATA])
      return -1;
    else if (d1_t->data[YEAR_DATA] > d2_t->data[YEAR_DATA])
      return 1;
  }
  
  // compare the rest of the data
  if (//FACET_MEMBERS[d1_t->facet][YEAR_DATA] && FACET_MEMBERS[d2_t->facet][YEAR_DATA]
      //&&
      d1_t->data[YEAR_DATA] < 0 && d2_t->data[YEAR_DATA] < 0)
  {
    for (int i=1; i<7; i++)
      // if (FACET_MEMBERS[d1_t->facet][i] && FACET_MEMBERS[d2_t->facet][i])
      {
        if (d1_t->data[i] > d2_t->data[i])
          return -1;
        else if (d1_t->data[i] < d2_t->data[i])
          return 1;
      }
  }
  else
  {
    for (int i=1; i<7; i++)
      // if (FACET_MEMBERS[d1_t->facet][i] && FACET_MEMBERS[d2_t->facet][i])
      {
        if (d1_t->data[i] < d2_t->data[i])
          return -1;
        else if (d1_t->data[i] > d2_t->data[i])
          return 1;
      }
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

DurationBase_t DateTime::subtractDateTime(const DateTime& dt, int implicit_timezone_seconds) const
{
  /*
  DateTime_t d1,d2;
  d1 = normalizeTimeZone();
  d2 = dt.normalizeTimeZone();
  
  d1->facet = DATETIME_FACET;
  d2->facet = DATETIME_FACET;
  
  
  cout << "d1: " << d1->toString() << endl;
  cout << "d2: " << d2->toString() << endl;
  
  cout << "d1: " << d1->toDayTimeDuration()->toString() << endl;
  cout << "d2: " << d2->toDayTimeDuration()->toString() << endl;
  */
  
  return *normalizeTimeZone(implicit_timezone_seconds)->toDayTimeDuration()
      - *dt.normalizeTimeZone(implicit_timezone_seconds)->toDayTimeDuration();
}

xqpString DateTime::toString() const
{
  xqpString result;
  
  // TODO: output based on the facet

  // output sign
  if (facet == DATETIME_FACET || facet == DATE_FACET)
  {
    if (data[YEAR_DATA] < 0)
      result += "-";
  }
  
  // output Date
  if (facet == DATETIME_FACET || facet == DATE_FACET)
  {
    
    for (int i=0; i<3; i++)
    {
      result += to_string(abs<int>(data[i]), min_length[i]);  // abs<> only needed for year
      if (i < 2)
        result += separators[i];
    }
  }
  
  // output Time
  if (facet == DATETIME_FACET || facet == TIME_FACET)
  {
    if (facet == DATETIME_FACET)
      result += 'T';
    
    for (int i=3; i<6; i++)
    {
      result += to_string(abs<int>(data[i]), min_length[i]);  // abs<> only needed for year
      if (i < 5)
        result += separators[i];
    }
  }
  
  if (facet == DATETIME_FACET || facet == TIME_FACET)
  {
    if (data[FRACSECONDS_DATA] != 0)
    {
      int temp = data[FRACSECONDS_DATA];
      while (temp%10 == 0)
        temp = temp / 10;
    
      result += '.';
      result += to_string(temp);
    }
  }
  
  result += the_time_zone.toString();
  
  return result;
}

DateTime_t DateTime::getDate() const
{
  DateTime_t dt_t = new DateTime(*this);
  dt_t->setFacet(DATE_FACET);
  return dt_t;
}

DateTime_t DateTime::getTime() const
{
  DateTime_t dt_t = new DateTime(*this);
  dt_t->setFacet(TIME_FACET);
  return dt_t;
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

void DateTime::adjustToFacet()
{
  switch (facet)
  {
  case DATETIME_FACET:
    // do nothing;
    break;
  case DATE_FACET:
    for (int i=HOUR_DATA; i<=FRACSECONDS_DATA; i++)
      data[i] = 0;
    break;
  case TIME_FACET:
    for (int i=YEAR_DATA; i<=DAY_DATA; i++)
      data[i] = 1;
    break;
    
  case GYEARMONTH_FACET:
    data[DAY_DATA] = 1;
    for (int i=HOUR_DATA; i<=FRACSECONDS_DATA; i++)
      data[i] = 0;
    break;
  }
}

void DateTime::setFacet(FACET_TYPE a_facet)
{
  facet = a_facet;
  adjustToFacet();
}

DateTime_t DateTime::normalizeTimeZone(int tz_seconds) const
{
  Duration_t d_t;
  DateTime_t dt_t;

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
  
  dt_t = subtractDuration(*d_t, false); // do not adjust to facet
  dt_t->the_time_zone = TimeZone(0);
  
  return dt_t;
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
    dt_t = dt_t->addDuration(*dtduration_t->toDuration());
    if (TimeZone::createTimeZone(context_tz_t->getHours(), context_tz_t->getMinutes(), context_tz_t->getSeconds(), tz_t))
      assert(0);
    dt_t->the_time_zone = *tz_t;
  }

  return dt_t;
}

DateTime_t DateTime::adjustToTimeZone(const DurationBase_t& db_t) const
{
  DayTimeDuration_t dtduration_t;
  DayTimeDuration_t context_tz_t;
  DateTime_t dt_t;
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
      dt_t = dt_t->addDuration(*dtduration_t->toDuration());
      if (TimeZone::createTimeZone(context_tz_t->getHours(), context_tz_t->getMinutes(), context_tz_t->getSeconds(), tz_t))
        assert(0);
      dt_t->the_time_zone = *tz_t;
    }
  }

  return dt_t;
}

DateTime_t DateTime::addDuration(const Duration& d, bool adjust_facet) const
{
  DateTime_t new_dt_t;
  int years, months, days, hours, minutes, int_seconds, frac_seconds, temp_days, carry;
  double temp_frac_seconds;

  // For the algorithm, see XML Schema 2 spec, Appendix E
  // http://www.w3.org/TR/xmlschema-2/#adding-durations-to-dateTimes
  
  months = modulo<int>(data[MONTH_DATA] + d.getMonths() - 1, 12) + 1;
  years = data[YEAR_DATA] + d.getYears() + quotient<int>(data[MONTH_DATA] + d.getMonths() - 1, 12);

  int_seconds = modulo<int>(floor(getSeconds() + d.getSeconds()), 60);
  temp_frac_seconds = (getSeconds() + d.getSeconds() - floor(getSeconds() + d.getSeconds()));
  frac_seconds = round(temp_frac_seconds * DateTime::FRAC_SECONDS_UPPER_LIMIT);
  
  minutes = data[MINUTE_DATA] + d.getMinutes() + quotient<int>(floor(getSeconds() + d.getSeconds()), 60);
  hours = data[HOUR_DATA] + d.getHours() + quotient<int>(minutes, 60);
  minutes = modulo<int>(minutes, 60);
  carry = quotient<int>(hours, 24);
  hours = modulo<int>(hours, 24);

  if (data[DAY_DATA] > get_last_day(years, months))
    temp_days = get_last_day(years, months);
  else if (data[DAY_DATA] < 1)
    temp_days = 1;
  else
    temp_days = data[DAY_DATA];

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

  // make sure year is not 0
  if (years == 0)
  {
    if (data[YEAR_DATA] > 0)
    {
      assert(d.isNegative());
      years = -1;
    }
    else if (data[YEAR_DATA] < 0)
    {
      assert(!d.isNegative());
      years = 1;
    }
    else
      assert(0);
  }

  if (DateTime::createDateTime(years, months, days, hours, minutes, int_seconds, frac_seconds, getTimezone(), new_dt_t))
    assert(0);
  
  new_dt_t->facet = facet;
  if (adjust_facet)
    new_dt_t->adjustToFacet();
  
  return new_dt_t;
}

DateTime_t DateTime::subtractDuration(const Duration& d, bool adjust_facet) const
{
  return addDuration(*(d.toNegDuration()), adjust_facet);
}

} // namespace xqp
