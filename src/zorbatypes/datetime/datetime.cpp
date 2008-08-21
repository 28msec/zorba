/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <string>
#include <exception>
#include <cassert>
#include <memory>

#ifndef WIN32
#include <sys/time.h>
#else
#include <sys/timeb.h>
#include <time.h>
#endif

#include "zorbautils/hashfun.h"
#include <zorbatypes/datetime.h>
#include <zorbatypes/duration.h>
#include <zorbatypes/timezone.h>
#include <zorbatypes/zorbatypes_decl.h>

#include "zorbatypes/datetime/parse.h"

using namespace std;

namespace zorba
{

static const int FACET_MEMBERS[][8] = {
  { 1, 1, 1, 1, 1, 1, 1, 0},    // DATETIME_FACET = 0,
  { 1, 1, 1, 0, 0, 0, 0, 0},    // DATE_FACET = 1,
  { 0, 0, 0, 1, 1, 1, 1, 0},    // TIME_FACET = 2,
  { 1, 1, 0, 0, 0, 0, 0, 0},    // GYEARMONTH_FACET = 3
  { 1, 0, 0, 0, 0, 0, 0, 0},    // GYEAR_FACET = 4
  { 0, 1, 0, 0, 0, 0, 0, 0},    // GMONTH_FACET = 5
  { 0, 1, 1, 0, 0, 0, 0, 0},    // GMONTHDAY_FACET = 6
  { 0, 0, 1, 0, 0, 0, 0, 0}     // GDAY_FACET = 7
};

static const char separators[] = { '-', '-', 'T', ':', ':', '.'};
static const char min_length[] = { 4, 2, 2, 2, 2, 2, 0};
  
  
const int DateTime::FRAC_SECONDS_UPPER_LIMIT = 1000000;


DateTime::DateTime()
  : 
  facet(DATETIME_FACET)
{ 
  init();
}


void DateTime::init()
{
  facet = DATETIME_FACET;

  for (int i = YEAR_DATA; i <= DAY_DATA; i++)
    data[i] = 1;
  
  for (int i = HOUR_DATA; i <= FRACSECONDS_DATA; i++)
    data[i] = 0;

  the_time_zone = TimeZone();
}


int DateTime::createDateTime(
    const DateTime* date,
    const DateTime* time,
    DateTime& result)
{
  if (!date->getTimezone().timeZoneNotSet() &&
      !time->getTimezone().timeZoneNotSet() &&
      !(date->getTimezone() == time->getTimezone()))
    return 2;

  int res = createDateTime(date->getYear(),
                           date->getMonth(),
                           date->getDay(),
                           time->getHours(),
                           time->getMinutes(),
                           floor<double>(time->getSeconds()),
                           round(frac(time->getSeconds()) * FRAC_SECONDS_UPPER_LIMIT),
                           result);

  if (res == 0)
  {
    if (!date->getTimezone().timeZoneNotSet())
      result.the_time_zone = date->getTimezone();
    else if (!time->getTimezone().timeZoneNotSet())
      result.the_time_zone = time->getTimezone();
  }

  return res;
}


int DateTime::createDateTime(
    int years,
    int months,
    int days,
    int hours,
    int minutes,
    int seconds,
    int fractional_seconds,
    DateTime& dt)
{
  dt.facet = DATETIME_FACET;
  dt.data[YEAR_DATA] = years;
  dt.data[MONTH_DATA] = abs<int>(months);
  dt.data[DAY_DATA] = abs<int>(days);
  dt.data[HOUR_DATA] = abs<int>(hours);
  dt.data[MINUTE_DATA] = abs<int>(minutes);
  dt.data[SECONDS_DATA] = abs<int>(seconds);
  dt.data[FRACSECONDS_DATA] = abs<int>(fractional_seconds);
  return 0;
}


int DateTime::createDateTime(
    int years,
    int months,
    int days, 
    int hours,
    int minutes,
    double seconds,
    const TimeZone* tz,
    DateTime& dt)
{
  dt.facet = DATETIME_FACET;
  dt.data[YEAR_DATA] = years;
  dt.data[MONTH_DATA] = abs<int>(months);
  dt.data[DAY_DATA] = abs<int>(days);
  dt.data[HOUR_DATA] = abs<int>(hours);
  dt.data[MINUTE_DATA] = abs<int>(minutes);
  dt.data[SECONDS_DATA] = floor<double>(abs<double>(seconds));
  dt.data[FRACSECONDS_DATA] = round(frac(abs<double>(seconds)) * FRAC_SECONDS_UPPER_LIMIT);
  
  if (tz != NULL)
    dt.the_time_zone = *tz;
  
  return 0;
}


int DateTime::createDateTime(
    int years,
    int months,
    int days,
    int hours,
    int minutes,
    int seconds,
    int fractional_seconds,
    const TimeZone* tz,
    DateTime& dt)
{
  dt.facet = DATETIME_FACET;
  dt.data[YEAR_DATA] = years;
  dt.data[MONTH_DATA] = abs<int>(months);
  dt.data[DAY_DATA] = abs<int>(days);
  dt.data[HOUR_DATA] = abs<int>(hours);
  dt.data[MINUTE_DATA] = abs<int>(minutes);
  dt.data[SECONDS_DATA] = abs<int>(seconds);
  dt.data[FRACSECONDS_DATA] = abs<int>(fractional_seconds);
      
  if (tz != NULL)
    dt.the_time_zone = *tz;

  return 0;
}


int DateTime::createDate(
    int years,
    int months,
    int days,
    const TimeZone* tz,
    DateTime& dt)
{
  dt.facet = DATE_FACET;
  dt.data[YEAR_DATA] = years;
  dt.data[MONTH_DATA] = abs<int>(months);
  dt.data[DAY_DATA] = abs<int>(days);
  dt.data[HOUR_DATA] = 0;
  dt.data[MINUTE_DATA] = 0;
  dt.data[SECONDS_DATA] = 0;
  dt.data[FRACSECONDS_DATA] = 0;

  if (tz != NULL)
    dt.the_time_zone = *tz;
  
  return 0;
}


int DateTime::createTime(
    int hours, 
    int minutes, 
    double seconds, 
    const TimeZone* tz,
    DateTime& dt)
{
  dt.facet = TIME_FACET;
  dt.data[YEAR_DATA] = 1;
  dt.data[MONTH_DATA] = 1;
  dt.data[DAY_DATA] = 1;
  dt.data[HOUR_DATA] = abs<int>(hours);
  dt.data[MINUTE_DATA] = abs<int>(minutes);
  dt.data[SECONDS_DATA] = floor<double>(abs<double>(seconds));
  dt.data[FRACSECONDS_DATA] = round(frac(abs<double>(seconds)) * FRAC_SECONDS_UPPER_LIMIT);
      
  if (tz != NULL)
    dt.the_time_zone = *tz;
  
  return 0;
}


int DateTime::createGYearMonth(int years, int months, DateTime& dt)
{
  dt.facet = GYEARMONTH_FACET;
  dt.data[YEAR_DATA] = years;
  dt.data[MONTH_DATA] = abs<int>(months);
  dt.data[DAY_DATA] = 1;
  dt.data[HOUR_DATA] = 0;
  dt.data[MINUTE_DATA] = 0;
  dt.data[SECONDS_DATA] = 0;
  dt.data[FRACSECONDS_DATA] = 0;

  return 0;
}


int DateTime::createGYear(int years, DateTime& dt)
{
  dt.facet = GYEAR_FACET;
  dt.data[YEAR_DATA] = years;
  dt.data[MONTH_DATA] = 1;
  dt.data[DAY_DATA] = 1;
  dt.data[HOUR_DATA] = 0;
  dt.data[MINUTE_DATA] = 0;
  dt.data[SECONDS_DATA] = 0;
  dt.data[FRACSECONDS_DATA] = 0;

  return 0;
}


int DateTime::createGMonth(int months, DateTime& dt)
{
  dt.facet = GMONTH_FACET;
  dt.data[YEAR_DATA] = 1;
  dt.data[MONTH_DATA] = abs<int>(months);
  dt.data[DAY_DATA] = 1;
  dt.data[HOUR_DATA] = 0;
  dt.data[MINUTE_DATA] = 0;
  dt.data[SECONDS_DATA] = 0;
  dt.data[FRACSECONDS_DATA] = 0;

  return 0;
}


int DateTime::createGMonthDay(int months, int days, DateTime& dt)
{
  dt.facet = GMONTHDAY_FACET;
  dt.data[YEAR_DATA] = 1;
  dt.data[MONTH_DATA] = abs<int>(months);
  dt.data[DAY_DATA] = abs<int>(days);
  dt.data[HOUR_DATA] = 0;
  dt.data[MINUTE_DATA] = 0;
  dt.data[SECONDS_DATA] = 0;
  dt.data[FRACSECONDS_DATA] = 0;

  return 0;
}


int DateTime::createGDay(int days, DateTime& dt)
{
  dt.facet = GDAY_FACET;
  dt.data[YEAR_DATA] = 1;
  dt.data[MONTH_DATA] = 1;
  dt.data[DAY_DATA] = abs<int>(days);
  dt.data[HOUR_DATA] = 0;
  dt.data[MINUTE_DATA] = 0;
  dt.data[SECONDS_DATA] = 0;
  dt.data[FRACSECONDS_DATA] = 0;

  return 0;
}

int DateTime::getLocalTime(DateTime& dt)
{
  // TODO: check code on windows
#ifndef WIN32
  timeval tv;
  gettimeofday(&tv, NULL);
  tm curr, *curr_ptr = 0;
  curr_ptr = localtime_r(&tv.tv_sec, &curr);
  return createDateTime(curr_ptr->tm_year + 1900, curr_ptr->tm_mon + 1, curr_ptr->tm_mday,
                        curr_ptr->tm_hour, curr_ptr->tm_min, curr_ptr->tm_sec,
                        round((tv.tv_usec / 1000000.0) * FRAC_SECONDS_UPPER_LIMIT), dt);
#else
  struct _timeb   tb;
  _ftime_s(&tb);
  struct  tm  curr, *curr_ptr=0;
  _localtime64_s(&curr, &tb.time);
  curr_ptr = &curr;
  return createDateTime(curr_ptr->tm_year + 1900, curr_ptr->tm_mon + 1, curr_ptr->tm_mday,
                        curr_ptr->tm_hour, curr_ptr->tm_min, curr_ptr->tm_sec,
                        round((tb.millitm / 1000.0) * FRAC_SECONDS_UPPER_LIMIT), dt);
#endif

}

int DateTime::parseDateTime(const xqpString& s, DateTime& dt)
{
  unsigned int position = 0;
  std::string ss = s.getStore()->str();

  // DateTime is of form: '-'? yyyy '-' mm '-' dd 'T' hh ':' mm ':' ss ('.' s+)? (zzzzzz)?

  skip_whitespace(ss, position);
  dt.facet = DATETIME_FACET;
  
  if (parse_date(ss, position, dt.data[YEAR_DATA], dt.data[MONTH_DATA], dt.data[DAY_DATA]))
    return 1;
  if (position == ss.size() || ss[position++] != 'T')
    return 1;
  
  if (parse_time(ss, position, dt.data[HOUR_DATA], dt.data[MINUTE_DATA], dt.data[SECONDS_DATA], dt.data[FRACSECONDS_DATA]))
    return 1;
    
  if (position < ss.size())
  {
    if (0 != TimeZone::parseTimeZone(ss.substr(position), dt.the_time_zone))
      return 1;
  }
  
  if (dt.data[HOUR_DATA] == 24)
  {
    dt.data[HOUR_DATA] = 0;
    std::auto_ptr<DateTime> temp = std::auto_ptr<DateTime>(
        dt.addDuration(Duration(Duration::DAYTIMEDURATION_FACET, false, 0, 0, 1, 0, 0, 0)));
    dt = *temp;
  }

  return 0;
}


int DateTime::parseDate(const xqpString& s, DateTime& dt)
{
  TimeZone tz;
  unsigned int position = 0;
  std::string ss = s.getStore()->str();

  skip_whitespace(ss, position);
  dt.facet = DATE_FACET;
  
  if (parse_date(ss, position, dt.data[YEAR_DATA], dt.data[MONTH_DATA], dt.data[DAY_DATA]))
    return 1;

  if (position < ss.size())
  {
    if (0 != TimeZone::parseTimeZone(ss.substr(position), dt.the_time_zone))
      return 1;
  }
  
  return 0;
}


int DateTime::parseTime(const xqpString& s, DateTime& dt)
{
  unsigned int position = 0;
  std::string ss = s.getStore()->str();

  skip_whitespace(ss, position);
  dt.facet = TIME_FACET;
  
  if (parse_time(ss, position, dt.data[HOUR_DATA], dt.data[MINUTE_DATA], dt.data[SECONDS_DATA], dt.data[FRACSECONDS_DATA]))
    return 1;
    
  if (position < ss.size())
  {
    if (0 != TimeZone::parseTimeZone(ss.substr(position), dt.the_time_zone))
      return 1;
  }
  
  if (dt.data[HOUR_DATA] == 24)
    dt.data[HOUR_DATA] = 0;

  return 0;
}


int DateTime::parseGYearMonth(const xqpString& s, DateTime& dt)
{
  unsigned int position = 0, temp_position = 0;
  std::string ss = s.getStore()->str();
  std::string temp;

  // GYearMonth of form: '-'? yyyy '-' mm zzzzzz?
  
  skip_whitespace(ss, position);
  dt.facet = GYEARMONTH_FACET;
  
  if (ss[position] == '-')
    temp = ss.substr(position++, 8);
  else
    temp = ss.substr(position, 7);
  
  temp += "-01";
  if (parse_date(temp, temp_position, dt.data[YEAR_DATA], dt.data[MONTH_DATA], dt.data[DAY_DATA]))
    return 1;
  
  position += 7;
  if (position < ss.size())
  {
    if (0 != TimeZone::parseTimeZone(ss.substr(position), dt.the_time_zone))
      return 1;
  }

  return 0;
}


int DateTime::parseGYear(const xqpString& s, DateTime& dt)
{
  unsigned int position = 0, temp_position = 0;
  std::string ss = s.getStore()->str();
  std::string temp;

  // GYear of form: '-'? yyyy zzzzzz?
  
  skip_whitespace(ss, position);
  dt.facet = GYEAR_FACET;
  
  if (ss[position] == '-')
    temp = ss.substr(position++, 5);
  else
    temp = ss.substr(position, 4);
  
  temp += "-01-01";
  if (parse_date(temp, temp_position, dt.data[YEAR_DATA], dt.data[MONTH_DATA], dt.data[DAY_DATA]))
    return 1;
  
  position += 4;
  if (position < ss.size())
  {
    if (0 != TimeZone::parseTimeZone(ss.substr(position), dt.the_time_zone))
      return 1;
  }

  return 0;
}


int DateTime::parseGMonth(const xqpString& s, DateTime& dt)
{
  unsigned int position = 0, temp_position = 0;
  std::string ss = s.getStore()->str();
  std::string temp;

  // GMonth of form: --MM zzzzzz?
  // preceding - is not allowed.
  
  skip_whitespace(ss, position);
  dt.facet = GMONTH_FACET;
  
  if (ss[position++] != '-')
    return 1;
  
  temp = "0001" + ss.substr(position, 3) + "-01";
  if (parse_date(temp,
                 temp_position,
                 dt.data[YEAR_DATA],
                 dt.data[MONTH_DATA],
                 dt.data[DAY_DATA]))
    return 1;
  
  position += 3;
  if (position < ss.size())
  {
    if (0 != TimeZone::parseTimeZone(ss.substr(position), dt.the_time_zone))
      return 1;
  }

  return 0;
}


int DateTime::parseGMonthDay(const xqpString& s, DateTime& dt)
{
  unsigned int position = 0, temp_position = 0;
  std::string ss = s.getStore()->str();
  std::string temp;

  // GMonthDay of form: --MM-DD zzzzzz?
  // preceding - is not allowed.

  skip_whitespace(ss, position);
  dt.facet = GMONTHDAY_FACET;
  
  if (ss[position++] != '-')
    return 1;
  
  temp = "0004" + ss.substr(position, 6); // Year 4 to make it a leap year, to allow the MonthDay of 29 February

  if (parse_date(temp,
                 temp_position,
                 dt.data[YEAR_DATA],
                 dt.data[MONTH_DATA],
                 dt.data[DAY_DATA]))
    return 1;

  dt.data[YEAR_DATA] = 1;
  
  position += 6;
  if (position < ss.size())
  {
    if (0 != TimeZone::parseTimeZone(ss.substr(position), dt.the_time_zone))
      return 1;
  }

  return 0;
}


int DateTime::parseGDay(const xqpString& s, DateTime& dt)
{
  unsigned int position = 0, temp_position = 0;
  std::string ss = s.getStore()->str();
  std::string temp;

  // GDay of form: ---DD zzzzzz?
  // preceding - is not allowed.
  
  skip_whitespace(ss, position);
  dt.facet = GDAY_FACET;
  
  if (ss[position++] != '-')
    return 1;
  if (ss[position++] != '-')
    return 1;
  
  temp = "0001-01" + ss.substr(position, 3);
  if (parse_date(temp,
                 temp_position,
                 dt.data[YEAR_DATA],
                 dt.data[MONTH_DATA],
                 dt.data[DAY_DATA]))
    return 1;
  
  position += 3;
  if (position < ss.size())
  {
    if (0 != TimeZone::parseTimeZone(ss.substr(position), dt.the_time_zone))
      return 1;
  }

  return 0;
}


// Returns 0 on success
int DateTime::parse_date(
    std::string& ss,
    unsigned int& position,
    int& year,
    int& month,
    int& day)
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
int DateTime::parse_time(
    std::string& ss,
    unsigned int& position,
    int& hour,
    int& minute,
    int& seconds,
    int& frac_seconds)
{
  double temp_frac_seconds;
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
    if (parse_frac(ss, position, temp_frac_seconds))
      return 1;
    frac_seconds = round(temp_frac_seconds * FRAC_SECONDS_UPPER_LIMIT);
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



DateTime& DateTime::operator=(const DateTime* dt)
{
  facet = dt->facet;
  for (int i=0; i<7; i++)
    data[i] = dt->data[i];
  the_time_zone = dt->the_time_zone;
  return *this;
}


int DateTime::createWithNewFacet(FACET_TYPE new_facet, DateTime& dt) const
{
  dt = *this;
  dt.setFacet(new_facet);
  return 0;
}


xqpString DateTime::toString() const
{
  xqpString result;
  
  // output sign
  if (FACET_MEMBERS[facet][0])
    if (data[YEAR_DATA] < 0)
      result.append_in_place("-");
  
  // output preceding '-' for Gregorian dates, when needed
  if (facet == GMONTH_FACET || facet == GMONTHDAY_FACET)
    result.append_in_place("--");
  if (facet == GDAY_FACET)
    result.append_in_place("---");
  
  for (int i=0; i<=5; i++)
  {
    if (FACET_MEMBERS[facet][i])
    {
      result.append_in_place(to_string(abs<int>(data[i]), min_length[i]));
      if (FACET_MEMBERS[facet][i+1] && i<=4)
        result.append_in_place(separators[i]);
    }
  }
  
  if (FACET_MEMBERS[facet][FRACSECONDS_DATA] && (data[FRACSECONDS_DATA] != 0))
  {
    int temp;
    result .append_in_place('.');
    
    // print leading 0s, if any
    temp = FRAC_SECONDS_UPPER_LIMIT / 10;
    while (temp > data[FRACSECONDS_DATA] && temp > 0)
    {
      result.append_in_place('0');
      temp /= 10;
    }
    
    // strip trailing 0s, if any
    temp = data[FRACSECONDS_DATA];
    while (temp%10 == 0 && temp > 0)
      temp = temp / 10;
    
    result.append_in_place(to_string(temp));
  }
  
  result.append_in_place(the_time_zone.toString().getStore());
  
  return result;
}


DateTime* DateTime::getDate() const
{
  DateTime* dt = new DateTime(*this);
  dt->setFacet(DATE_FACET);
  return dt;
}


DateTime* DateTime::getTime() const
{
  DateTime* dt = new DateTime(*this);
  dt->setFacet(TIME_FACET);
  return dt;
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


int DateTime::compare(const DateTime* dt, int timezone_seconds) const
{
  std::auto_ptr<DateTime> d1_t;
  std::auto_ptr<DateTime> d2_t;
  
  d1_t.reset(normalizeTimeZone(timezone_seconds));
  d2_t.reset(dt->normalizeTimeZone(timezone_seconds));
    
  if (d1_t->data[YEAR_DATA] < d2_t->data[YEAR_DATA])
    return -1;
  else if (d1_t->data[YEAR_DATA] > d2_t->data[YEAR_DATA])
    return 1;
  
  // compare the rest of the data
  if (d1_t->data[YEAR_DATA] < 0 && d2_t->data[YEAR_DATA] < 0)
  {
    for (int i=1; i<7; i++)
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
    {
      if (d1_t->data[i] < d2_t->data[i])
        return -1;
      else if (d1_t->data[i] > d2_t->data[i])
        return 1;
    }
  }
  
  return 0;
}


uint32_t DateTime::hash(int implicit_timezone_seconds) const
{
  uint32_t hval = 0;
  std::auto_ptr<DateTime> dt(normalizeTimeZone(implicit_timezone_seconds));
  
  hval = hashfun::h32<int>((int)dt->facet, hval);
  hval = hashfun::h32<int>(dt->data[YEAR_DATA], hval);
  hval = hashfun::h32<int>(dt->data[MONTH_DATA], hval);
  hval = hashfun::h32<int>(dt->data[DAY_DATA], hval);
  hval = hashfun::h32<int>(dt->data[HOUR_DATA], hval);
  hval = hashfun::h32<int>(dt->data[MINUTE_DATA], hval);
  hval = hashfun::h32<int>(dt->data[SECONDS_DATA], hval);
  hval = hashfun::h32<int>(dt->data[FRACSECONDS_DATA], hval);
  
  hval = dt->the_time_zone.hash(hval);
  
  return hval;
}


Duration* DateTime::toDayTimeDuration() const
{
  if (data[YEAR_DATA] >= 0)
    return new Duration(Duration::DAYTIMEDURATION_FACET, false, 0, 0,
                        365 * (abs<int>(data[YEAR_DATA]) - 1) +
                          leap_years_count(data[YEAR_DATA]) +
                          days_since_year_start(data[YEAR_DATA],
                            data[MONTH_DATA],
                            data[DAY_DATA]),
                        data[HOUR_DATA],
                        data[MINUTE_DATA],
                        data[SECONDS_DATA],
                        data[FRACSECONDS_DATA]);
  else
  {
    Duration days(Duration::DAYTIMEDURATION_FACET, true, 0, 0,
                         365 * abs<int>(data[YEAR_DATA]) -
                         leap_years_count(data[YEAR_DATA]) -
                         days_since_year_start(data[YEAR_DATA],
                                               data[MONTH_DATA],
                                               data[DAY_DATA]),
                         0, 0, 0, 0);
    
    Duration remainder(Duration::DAYTIMEDURATION_FACET, false, 0, 0, 0,
                              data[HOUR_DATA],
                              data[MINUTE_DATA],
                              data[SECONDS_DATA],
                              data[FRACSECONDS_DATA]);
    
    return days + remainder;
  }
}


DateTime* DateTime::addDuration(const Duration& d, bool adjust_facet) const
{
  DateTime* new_dt = NULL;
  int years, months, days, hours, minutes, int_seconds, frac_seconds, temp_days, carry;
  double temp_frac_seconds;

  // For the algorithm, see XML Schema 2 spec, Appendix E
  // http://www.w3.org/TR/xmlschema-2/#adding-durations-to-dateTimes
  
  months = modulo<int>(data[MONTH_DATA] + d.getMonths() - 1, 12) + 1;

  years = data[YEAR_DATA] + d.getYears() +
          quotient<int>(data[MONTH_DATA] + d.getMonths() - 1, 12);

  int_seconds = modulo<int>(floor(getSeconds() + d.getSeconds()), 60);

  temp_frac_seconds = (getSeconds() + d.getSeconds() -
                       floor(getSeconds() + d.getSeconds()));

  frac_seconds = round(temp_frac_seconds * DateTime::FRAC_SECONDS_UPPER_LIMIT);
  
  minutes = data[MINUTE_DATA] + d.getMinutes() +
            quotient<int>(floor(getSeconds() + d.getSeconds()), 60);

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
  
  if (data[YEAR_DATA] > 0 && d.isNegative() && years <= 0)
    years--;
  if (data[YEAR_DATA] < 0 && (!d.isNegative()) && years >= 0)
    years++;

  new_dt = new DateTime();

  if (DateTime::createDateTime(years, months, days, hours, minutes,
                               int_seconds, frac_seconds, &the_time_zone,
                               *new_dt))
    assert(0);
  
  new_dt->facet = facet;
  if (adjust_facet)
    new_dt->adjustToFacet();

  return new_dt;
}


DateTime* DateTime::subtractDuration(const Duration& d, bool adjust_facet) const
{
  return addDuration(*(d.toNegDuration()), adjust_facet);
}


Duration* DateTime::subtractDateTime(
    const DateTime* dt,
    int implicit_timezone_seconds) const
{
  std::auto_ptr<DateTime> dt1(normalizeTimeZone(implicit_timezone_seconds));
  std::auto_ptr<DateTime> dt2(dt->normalizeTimeZone(implicit_timezone_seconds));
  std::auto_ptr<Duration> dur1(dt1->toDayTimeDuration());
  std::auto_ptr<Duration> dur2(dt2->toDayTimeDuration());
  return *dur1 - *dur2;
}


DateTime* DateTime::normalizeTimeZone(int tz_seconds) const
{
  DateTime* dt;
  Duration d;
  
  if( the_time_zone.timeZoneNotSet() )
  {
    // validate timezone value (-14 .. +14 H)
    if (tz_seconds > 14*3600 || tz_seconds < -14*3600)
      throw InvalidTimezoneException();
    
    d = Duration(Duration::DAYTIMEDURATION_FACET, 0, 0, (tz_seconds < 0), 0, 0, 0, tz_seconds, 0);
  }
  else
  {
    if (0 != Duration::fromTimezone(the_time_zone, d))
      assert(0);
  }
  
  dt = subtractDuration(d, false); // do not adjust to facet
  dt->the_time_zone = TimeZone(0);
  
  return dt;
}


DateTime* DateTime::adjustToTimeZone(int tz_seconds) const
{
  std::auto_ptr<Duration> dtduration;
  std::auto_ptr<Duration> context_tz;
  std::auto_ptr<DateTime> dt;
  
  // validate timezone value (-14 .. +14 H)
  if (tz_seconds > 14*3600 || tz_seconds < -14*3600)
    throw InvalidTimezoneException();

  // If $timezone is not specified, then $timezone is the value of the implicit timezone in the dynamic context.
  context_tz = std::auto_ptr<Duration>(new Duration(Duration::DAYTIMEDURATION_FACET, (tz_seconds<0), 0, 0, 0, 0, 0, tz_seconds, 0));

  dt = std::auto_ptr<DateTime>(new DateTime(*this));
  
  // If $arg does not have a timezone component and $timezone is not the empty sequence,
  // then the result is $arg with $timezone as the timezone component.
  if (the_time_zone.timeZoneNotSet())
  {
    if (TimeZone::createTimeZone(context_tz->getHours(), context_tz->getMinutes(), int(context_tz->getSeconds()), dt->the_time_zone))
      assert(0);
  }
  else
  {
    // If $arg has a timezone component and $timezone is not the empty sequence, then
    // the result is an xs:dateTime value with a timezone component of $timezone that is equal to $arg.
    dtduration = std::auto_ptr<Duration>(new Duration(Duration::DAYTIMEDURATION_FACET,
                                the_time_zone.isNegative(),
                                0, 0, 0,
                                the_time_zone.getHours(),
                                the_time_zone.getMinutes(),
                                the_time_zone.getIntSeconds(), 0));

    dtduration = std::auto_ptr<Duration>(*context_tz - *dtduration);
    dt = std::auto_ptr<DateTime>(dt->addDuration(*dtduration));
    if (TimeZone::createTimeZone(context_tz->getHours(), context_tz->getMinutes(), int(context_tz->getSeconds()), dt->the_time_zone))
      assert(0);
  }

  return dt.release();
}


DateTime* DateTime::adjustToTimeZone(const Duration* d) const
{
  std::auto_ptr<Duration> dtduration;
  std::auto_ptr<const Duration> context_tz;
  std::auto_ptr<DateTime> dt;

  // A dynamic error is raised [err:FODT0003] if $timezone is less than -PT14H
  // or greater than PT14H or if does not contain an integral number of minutes.
  
  dt = std::auto_ptr<DateTime>(new DateTime(*this));
  
  if (d == NULL)
  {
    if (!the_time_zone.timeZoneNotSet())
      dt->the_time_zone = TimeZone();
  }
  else
  {
    // validate timezone value (-14 .. +14 H)
    if (d->getYears() != 0 || d->getMonths() != 0 ||
        d->getDays() != 0 ||
        d->getSeconds() != 0 ||
        d->getHours()*3600 + d->getMinutes()*60 > 14*3600 ||
        d->getHours()*3600 + d->getMinutes()*60 < -14*3600)
      throw InvalidTimezoneException();
        
    // If $arg does not have a timezone component and $timezone is not the
    // empty sequence, then the result is $arg with $timezone as the timezone
    // component.
    if (the_time_zone.timeZoneNotSet())
    {
      if (TimeZone::createTimeZone(d->getHours(), d->getMinutes(), int(d->getSeconds()), dt->the_time_zone))
        assert(0);
    }
    else
    {
      // If $arg has a timezone component and $timezone is not the empty sequence, then
      // the result is an xs:dateTime value with a timezone component of $timezone that is equal to $arg.
      dtduration = std::auto_ptr<Duration>(new Duration(Duration::DAYTIMEDURATION_FACET, the_time_zone.isNegative(),
                                  0, 0, 0,
                                         the_time_zone.getHours(),
                                         the_time_zone.getMinutes(),
                                         the_time_zone.getIntSeconds(),
                                         0));

      context_tz = std::auto_ptr<Duration>(new Duration(*d));
      if (context_tz.get() == NULL)
        assert(0);

      dtduration = std::auto_ptr<Duration>(*context_tz - *dtduration);
      dt.reset(dt->addDuration(*dtduration));

      if (TimeZone::createTimeZone(context_tz->getHours(),
                                   context_tz->getMinutes(),
                                   int(context_tz->getSeconds()),
                                   dt->the_time_zone))
        assert(0);
    }
  }

  return dt.release();
}


void DateTime::setFacet(FACET_TYPE a_facet)
{
  facet = a_facet;
  adjustToFacet();
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
  case GYEAR_FACET:
    data[MONTH_DATA] = 1;
    data[DAY_DATA] = 1;
    for (int i=HOUR_DATA; i<=FRACSECONDS_DATA; i++)
      data[i] = 0;
    break;
  case GMONTH_FACET:
    data[YEAR_DATA] = 1;
    data[DAY_DATA] = 1;
    for (int i=HOUR_DATA; i<=FRACSECONDS_DATA; i++)
      data[i] = 0;
    break;
  case GMONTHDAY_FACET:
    data[YEAR_DATA] = 1;
    for (int i=HOUR_DATA; i<=FRACSECONDS_DATA; i++)
      data[i] = 0;
    break;
  case GDAY_FACET:
    data[YEAR_DATA] = 1;
    data[MONTH_DATA] = 1;
    for (int i=HOUR_DATA; i<=FRACSECONDS_DATA; i++)
      data[i] = 0;
    break;
  }
}


} // namespace xqp
