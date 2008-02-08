/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza, Sorin Nasoi
 */

#include <string>
#include "util/datetime/duration.h"
#include "util/datetime/parse.h"
#include "util/numconversions.h"

#include <iostream>
using namespace std;

namespace xqp
{
  const uint32_t NO_MONTHS_IN_YEAR = 12;
  const uint32_t NO_HOURS_IN_DAY = 24;
  const uint32_t NO_MINUTES_IN_HOUR = 60;
  const uint32_t NO_SECONDS_IN_MINUTE = 60;
  const uint32_t NO_SEC_IN_DAY = NO_HOURS_IN_DAY * NO_MINUTES_IN_HOUR * NO_SECONDS_IN_MINUTE;
  const uint32_t NO_SEC_IN_HOUR = NO_MINUTES_IN_HOUR * NO_SECONDS_IN_MINUTE;
 

YearMonthDuration::YearMonthDuration(long the_months)
  :
  months(the_months)
{
}

YearMonthDuration& YearMonthDuration::operator=(const YearMonthDuration_t& ym_t)
{
  months = ym_t->months;
  return *this;
}

bool YearMonthDuration::operator<(const DurationBase& db) const
{
  const YearMonthDuration& ymd = dynamic_cast<const YearMonthDuration&>(db); // TODO: catch bad_cast and throw Zorba exception?
  if (months < ymd.months)
    return true;
  else
    return false;
}

bool YearMonthDuration::operator==(const DurationBase& db) const
{
  const YearMonthDuration& ymd = dynamic_cast<const YearMonthDuration&>(db);
  
  if (months == ymd.months)
    return true;
  else
    return false;
}

int YearMonthDuration::compare(const DurationBase& db) const
{
  const YearMonthDuration& ymd = dynamic_cast<const YearMonthDuration&>(db);

  if (operator<(ymd))
    return -1;
  else if (operator==(ymd))
    return 0;
  else
    return 1;
}

xqpString YearMonthDuration::toString() const
{
  xqpString result = "";
  long abs_months = months;

  if (months < 0)
  {
    result += "-";
    abs_months = -months;
  }

  result += "P";

  if (abs_months > 12 )
    result = result + NumConversions::longToStr(abs_months / 12) + "Y";

  if (abs_months%12 != 0)
    result = result + NumConversions::longToStr(abs_months % 12) + "M";
    
  // TODO:
  return result;
}

DurationBase_t YearMonthDuration::operator+(const DurationBase& db) const
{
  const YearMonthDuration& ymd = dynamic_cast<const YearMonthDuration&>(db);
  YearMonthDuration* ym = new YearMonthDuration(months + ymd.months);
  return ym;
}

DurationBase_t YearMonthDuration::operator-(const DurationBase& db) const
{
  const YearMonthDuration& ymd = dynamic_cast<const YearMonthDuration&>(db);
  YearMonthDuration* ym = new YearMonthDuration(months - ymd.months);
  return ym;
}

DurationBase_t YearMonthDuration::operator*(const Double value) const
{
  YearMonthDuration* ym = new YearMonthDuration( atol ((months * value).round().toString().c_str()) );
  return ym;
}

DurationBase_t YearMonthDuration::operator/(const Double value) const
{
  YearMonthDuration* ym = new YearMonthDuration(atol ((months / value).round().toString().c_str()));
  return ym;
}

Decimal YearMonthDuration::operator/(const DurationBase& db) const
{
  const YearMonthDuration& ymd = dynamic_cast<const YearMonthDuration&>(db);
  Decimal res = Decimal::parseLong( months )/ Decimal::parseLong( ymd.months );
  return res;
}

int32_t YearMonthDuration::getYears() const
{
  return months/NO_MONTHS_IN_YEAR;
}

int32_t YearMonthDuration::getMonths() const
{
  return (months % NO_MONTHS_IN_YEAR);
}

int32_t YearMonthDuration::getDays() const
{
  return 0;
}

int32_t YearMonthDuration::getHours() const
{
  return 0;
}

int32_t YearMonthDuration::getMinutes() const
{
  return 0;
}

double YearMonthDuration::getSeconds() const
{
  return 0;
}

bool YearMonthDuration::parse_string(const xqpString& s, YearMonthDuration_t& ym_t)
{
  std::string ss = *s.getStore();
  bool negative = false;
  unsigned int position = 0;
  long result, months = 0;
  
  skip_whitespace(ss, position);

  if (position == ss.size())
    return false;
    
  if (ss[position] == '-')
  {
    negative = 1;
    position++;
  }

  if (position == ss.size() || ss[position++] != 'P')
    return false;
    
  if (position == ss.size() || parse_int(ss, position, result))
    return false;
    
  if (position == ss.size())
    return false;

  if (ss[position] == 'Y')
  {
    position++;
    months = result * NO_MONTHS_IN_YEAR;

    if (position < ss.size())
    {
      if (parse_int(ss, position, result) == 0)
      {
        if (ss[position++] != 'M')
          return false;

        months += result;
      }
      else
        return false;
    }
  }
  else if (ss[position++] == 'M')
  {
    months = result;
  }
  else
    return false;

  if (ss.size() != position)
    return false;

  if (negative)
    months = -months;

  ym_t = new YearMonthDuration(months);
  return true;
}

DayTimeDuration::DayTimeDuration(bool negative, long the_days, long hours, long minutes, long seconds, long frac_seconds)
  :
  is_negative(negative), days(the_days), timeDuration(hours, minutes, seconds, frac_seconds)
{
  // TODO: normalization
}

DayTimeDuration& DayTimeDuration::operator=(const DayTimeDuration_t& dt_t)
{
  is_negative = dt_t->is_negative;
  days = dt_t->days;
  timeDuration = dt_t->timeDuration;
  return *this;
}

bool DayTimeDuration::operator<(const DurationBase& db) const
{
  const DayTimeDuration& dtd = dynamic_cast<const DayTimeDuration&>(db);
  
  if (is_negative != dtd.is_negative)
    return (is_negative == true);
  else if (days != dtd.days)
    return (days < dtd.days);
  else
    return timeDuration < dtd.timeDuration;
}

bool DayTimeDuration::operator==(const DurationBase& db) const
{
  const DayTimeDuration& dtd = dynamic_cast<const DayTimeDuration&>(db);
  
  if (is_negative == dtd.is_negative
      &&
      days == dtd.days
      &&
      timeDuration == dtd.timeDuration)
    return true;
  else
    return false;
}

int DayTimeDuration::compare(const DurationBase& db) const
{
  const DayTimeDuration& dtd = dynamic_cast<const DayTimeDuration&>(db);
  
  if (operator<(dtd))
    return -1;
  else if (operator==(dtd))
    return 0;
  else
    return 1;
}

xqpString DayTimeDuration::toString() const
{
  xqpString result = "";

  if ( is_negative )
    result += "-";

  result += "P";

    // TODO: check

  if ( days != 0 )
    result += NumConversions::longToStr ( days ) + "D";


  result += "T";

  if ( timeDuration.hours() != 0)
    result += NumConversions::integerToStr ( timeDuration.hours() ) + "H";

  if ( timeDuration.minutes() != 0 )
    result += NumConversions::integerToStr ( timeDuration.minutes() ) + "M";

  if ( timeDuration.seconds() != 0 || timeDuration.fractional_seconds() != 0  ||
       (timeDuration.hours() == 0 && timeDuration.minutes() == 0 && timeDuration.seconds() == 0 && timeDuration.fractional_seconds() == 0))
  {
    result += NumConversions::integerToStr ( timeDuration.seconds() );

    if ( timeDuration.fractional_seconds() != 0 )
      result += "." + NumConversions::longToStr ( timeDuration.fractional_seconds() );

    result += "S";
  }

  return result;
}

DurationBase_t DayTimeDuration::operator+(const DurationBase& db) const
{
  const DayTimeDuration& dtd = dynamic_cast<const DayTimeDuration&>(db);
  long resDays;

  if(is_negative)
    resDays = dtd.is_negative ? -days-dtd.days : -days+dtd.days;
  else
    resDays = dtd.is_negative ? days-dtd.days : days+dtd.days;

  bool resIsNeg = resDays<0 ? true : false;

  boost::posix_time::time_duration resTimeDuration = timeDuration + dtd.timeDuration;

  //TODO Should normalization be part of the constructor?
  DayTimeDuration* dt = new DayTimeDuration(
      resIsNeg,
      resDays + resTimeDuration.hours() / NO_HOURS_IN_DAY,
      resTimeDuration.hours() % NO_HOURS_IN_DAY,
      resTimeDuration.minutes(),
      resTimeDuration.seconds(),
      resTimeDuration.fractional_seconds());

  return dt;
}

DurationBase_t DayTimeDuration::operator-(const DurationBase& db) const
{
  const DayTimeDuration& dtd = dynamic_cast<const DayTimeDuration&>(db);
  long resDays;

  if(is_negative)
    resDays = dtd.is_negative ? -days+dtd.days : -days-dtd.days;
  else
    resDays = dtd.is_negative ? days+dtd.days : days-dtd.days;

  bool resIsNeg = resDays<0 ? true : false;

  boost::posix_time::time_duration resTimeDuration = timeDuration - dtd.timeDuration;

  //TODO Should normalization be part of the constructor?
  DayTimeDuration* dt = new DayTimeDuration(
      resIsNeg,
  resDays + resTimeDuration.hours() / NO_HOURS_IN_DAY,
  resTimeDuration.hours() % NO_HOURS_IN_DAY,
  resTimeDuration.minutes(),
  resTimeDuration.seconds(),
  resTimeDuration.fractional_seconds());

  return dt;
}

DurationBase_t DayTimeDuration::operator*(const Double value) const
{
  long resSeconds = days * NO_HOURS_IN_DAY * NO_MINUTES_IN_HOUR * NO_SECONDS_IN_MINUTE + timeDuration.total_seconds();
  resSeconds = atol (( resSeconds * value).round().toString().c_str());

  //TODO Should normalization be part of the constructor?
  DayTimeDuration* dt = new DayTimeDuration(
      is_negative,
      resSeconds / NO_SEC_IN_DAY, //days
      (resSeconds % NO_SEC_IN_DAY) / NO_SEC_IN_HOUR, //hours
      ((resSeconds % NO_SEC_IN_DAY) % NO_SEC_IN_HOUR) / NO_SECONDS_IN_MINUTE, //minutes
      ((resSeconds % NO_SEC_IN_DAY) % NO_SEC_IN_HOUR) % NO_SECONDS_IN_MINUTE, //seconds
      timeDuration.fractional_seconds());

  return dt;
}

DurationBase_t DayTimeDuration::operator/(const Double value) const
{
  long resSeconds = days * NO_SEC_IN_DAY + timeDuration.total_seconds();
  resSeconds = atol (( resSeconds / value).round().toString().c_str());

  //TODO Should normalization be part of the constructor?
  DayTimeDuration* dt = new DayTimeDuration(
      is_negative,
      resSeconds / NO_SEC_IN_DAY, //days
      (resSeconds % NO_SEC_IN_DAY) / NO_SEC_IN_HOUR, //hours
      ((resSeconds % NO_SEC_IN_DAY) % NO_SEC_IN_HOUR) / NO_SECONDS_IN_MINUTE, //minutes
      ((resSeconds % NO_SEC_IN_DAY) % NO_SEC_IN_HOUR) % NO_SECONDS_IN_MINUTE, //seconds
      0);

  return dt;
}

Decimal DayTimeDuration::operator/(const DurationBase& db) const
{
  Decimal op1 = Decimal::parseLong(days * NO_SEC_IN_DAY + timeDuration.total_seconds()) + Decimal::parseLong(timeDuration.fractional_seconds());
  if( is_negative )
    op1 = -op1;

  const DayTimeDuration& dtd = dynamic_cast<const DayTimeDuration&>(db);
  Decimal op2 = Decimal::parseLong(dtd.days * NO_SEC_IN_DAY + dtd.timeDuration.total_seconds()) + Decimal::parseLong(dtd.timeDuration.fractional_seconds());
  if( is_negative )
    op2 = -op2;

  return op1/op2;
}

int32_t DayTimeDuration::getYears() const
{
  return 0;
}

int32_t DayTimeDuration::getMonths() const
{
  return 0;
}

int32_t DayTimeDuration::getDays() const
{
    return is_negative?
        -normalize().days:
        normalize().days;
}

int32_t DayTimeDuration::getHours() const
{
  return is_negative?
      -timeDuration.hours() % NO_HOURS_IN_DAY:
      timeDuration.hours() % NO_HOURS_IN_DAY;
}

int32_t DayTimeDuration::getMinutes() const
{
  return is_negative?
      -timeDuration.minutes() % NO_MINUTES_IN_HOUR:
      timeDuration.minutes() % NO_MINUTES_IN_HOUR;
}

double DayTimeDuration::getSeconds() const
{
  double frac_sec = timeDuration.fractional_seconds();
  while(frac_sec > 1)
  {
    frac_sec = frac_sec /10;
  }
  
  return is_negative?
      -(timeDuration.seconds() % NO_SECONDS_IN_MINUTE) + frac_sec:
      (timeDuration.seconds() % NO_SECONDS_IN_MINUTE) + frac_sec;
}

DayTimeDuration DayTimeDuration::normalize() const
{
  int32_t tmp = timeDuration.hours() / NO_HOURS_IN_DAY;
  DayTimeDuration_t dt = new DayTimeDuration(is_negative,
                                             days + tmp,
                                             timeDuration.hours(),
                                             timeDuration.minutes(),
                                             timeDuration.seconds(),
                                             timeDuration.fractional_seconds());
  return *dt;
}

// parse a 'nS' string, with fractional seconds, returns 0 on success and 1 on failure
static bool parse_s_string(std::string ss, unsigned int& position, long& seconds, long& frac_seconds)
{
  long result;
  
  if (position == ss.size() || parse_int(ss, position, result))
    return false;

  if (position == ss.size())
    return false;

  if (ss[position] == 'S')
  {
    position++;
    seconds = result;
  }
  else if (ss[position] == '.')
  {
    position++;
    seconds = result;

    if (position == ss.size() || parse_int(ss, position, result))
      return false;

    if (position == ss.size() || ss[position] != 'S')
      return false;

    position++;
    frac_seconds = result;
  }

  return true;
}

// parse a 'nMnS' string, with fractional seconds
static bool parse_ms_string(std::string ss, unsigned int& position, long& minutes, long& seconds, long& frac_seconds)
{
  long result;
  
  if (position == ss.size() || parse_int(ss, position, result))
    return false;

  if (position == ss.size())
    return false;

  if (ss[position] == 'M')
  {
    position++;
    minutes = result;
    if (position < ss.size() && !parse_s_string(ss, position, seconds, frac_seconds))
      return false;
  }
  else if (ss[position] == 'S')
  {
    position++;
    seconds = result;
  }
  else if (ss[position] == '.')
  {
    position++;
    seconds = result;

    if (position == ss.size() || parse_int(ss, position, result))
      return false;

    if (position == ss.size() || ss[position] != 'S')
      return false;

    position++;
    frac_seconds = result;
  }

  return true;
}

// parse a 'nHnMnS' string, with fractional seconds
static bool parse_hms_string(std::string ss, unsigned int& position, long& hours, long& minutes, long& seconds, long& frac_seconds)
{
  long result;
  
  if (position == ss.size() || parse_int(ss, position, result))
    return false;

  if (position == ss.size())
    return false;

  if (ss[position] == 'H')
  {
    position++;
    hours = result;
    if (position < ss.size() && !parse_ms_string(ss, position, minutes, seconds, frac_seconds))
      return false;
  }
  else if (ss[position] == 'M')
  {
    position++;
    minutes = result;
    if (position < ss.size() && !parse_s_string(ss, position, seconds, frac_seconds))
      return false;
  }
  else if (ss[position] == 'S')
  {
    position++;
    seconds = result;
  }
  else if (ss[position] == '.')
  {
    position++;
    seconds = result;

    if (position == ss.size() || parse_int(ss, position, result))
      return false;

    if (position == ss.size() || ss[position] != 'S')
      return false;

    position++;
    frac_seconds = result;
  }

  return true;
}

// Parse a 'PnDTnHnMnS' dateTime duration
bool DayTimeDuration::parse_string(const xqpString& s, DayTimeDuration_t& dt_t, bool dont_check_letter_p)
{
  std::string ss = *s.getStore();
  bool negative = false;
  unsigned int position = 0;
  long result, days = 0, hours = 0, minutes = 0, seconds = 0, frac_seconds = 0;

  skip_whitespace(ss, position);

  if (position == ss.size())
    return false;
  
  if (ss[position] == '-')
  {
    negative = 1;
    position++;
  }

  if (!dont_check_letter_p && (position == ss.size() || ss[position++] != 'P'))
    return false;

  if (position == ss.size())
    return false;

  // It must be either 'T' or 'nD'
  if (ss[position] != 'T')
  {
    if (parse_int(ss, position, result))
      return false;

    days = result;

    if (position == ss.size() || ss[position++] != 'D')
      return false;
  }

  // Either 'T', or whitespace, or end
  
  if (position<ss.size() && ss[position] == 'T')
  {
    position++;
    if (!parse_hms_string(ss, position, hours, minutes, seconds, frac_seconds))
      return false;
  }

  skip_whitespace(ss, position);

  if (ss.size() != position)
    return false;

  dt_t = new DayTimeDuration(negative, days, hours, minutes, seconds, frac_seconds);
  return true;
}

bool DayTimeDuration::from_Timezone ( const TimeZone& t, DurationBase_t& dt )
{
  if(!t.is_not_a_date_time())
  {
    dt = new DayTimeDuration ( t.is_negative(), 0, t.getHours(), t.getMinutes(), t.getSeconds(), t.getFractionalSeconds() );
    return true;
  }
  else
    return false;
}

Duration::Duration()
{
  
}

bool Duration::operator<(const DurationBase& db) const
{
  const Duration& d = dynamic_cast<const Duration&>(db);
  
  if (yearMonthDuration == d.yearMonthDuration)
    return dayTimeDuration < d.dayTimeDuration;
  else if (dayTimeDuration == d.dayTimeDuration)
    return yearMonthDuration < d.yearMonthDuration;
  else
    // TODO: treat other cases ?
    return false;
}

bool Duration::operator==(const DurationBase& db) const
{
  const Duration& d = dynamic_cast<const Duration&>(db);
  
  if (yearMonthDuration == d.yearMonthDuration
      &&
      dayTimeDuration == d.dayTimeDuration)
    return true;
  else
    return false;
}

int Duration::compare(const DurationBase& db) const
{
  const Duration& d = dynamic_cast<const Duration&>(db);
  
  if (operator<(d))
    return -1;
  if (operator==(d))
    return 0;
  else
    return 1;
}

xqpString Duration::toString() const
{
  xqpString result;
  xqpString temp = dayTimeDuration.toString();

  // TODO: check "-" signs
  result = yearMonthDuration.toString() + temp.substr(1, temp.size() - 1);

  
  // TODO:
  return result;
}

DurationBase_t Duration::operator+(const DurationBase& db) const
{
  Duration* d = new Duration();
  return d;
}

DurationBase_t Duration::operator-(const DurationBase& db) const
{
  Duration* d = new Duration();
  return d;
}

DurationBase_t Duration::operator*(const Double value) const
{
  Duration* d = new Duration();
  return d;
}

DurationBase_t Duration::operator/(const Double value) const
{
  Duration* d = new Duration();
  return d;
}

Decimal Duration::operator/(const DurationBase& db) const
{
  return (int32_t)0;
}

int32_t Duration::getYears() const
{
  return 0;
}

int32_t Duration::getMonths() const
{
  return 0;
}

int32_t Duration::getDays() const
{
  return 0;
}

int32_t Duration::getHours() const
{
  return 0;
}

int32_t Duration::getMinutes() const
{
  return 0;
}

double Duration::getSeconds() const
{
  return 0;
}

// Parse a '(-)PnYnMnDTnHnMnS'
bool Duration::parse_string(const xqpString& s, Duration_t& d_t)
{
  int pos;
  YearMonthDuration_t ymd_t;
  DayTimeDuration_t dtd_t;

  pos = s.indexOf("M");
  if (pos == -1)
    pos = s.indexOf("Y");

  d_t = new Duration();

  // Check month or year
  if (pos != -1)
  {
    if (!YearMonthDuration::parse_string(s.substr(0, pos+1), ymd_t))
      return false;
    d_t->yearMonthDuration = *ymd_t;

    if ((unsigned int)pos+1 < s.size())
    {
      if (!DayTimeDuration::parse_string(s.substr(pos+1), dtd_t, true))
        return false;
      d_t->dayTimeDuration = *dtd_t;
    }
  }
  else 
  {
    // No month or year -- parse DayTime
    if (!DayTimeDuration::parse_string(s, dtd_t))
      return false;
    d_t->dayTimeDuration = *dtd_t;
  }
  
  return true;
}

}
