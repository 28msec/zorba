/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza, Sorin Nasoi
 */

#include <string>
#include <iostream>
#include <cassert>

#include <zorbatypes/duration.h>
#include "zorbatypes/datetime/parse.h"
#include "zorbatypes/numconversions.h"

using namespace std;

namespace zorba
{
const int NO_MONTHS_IN_YEAR = 12;
const int NO_HOURS_IN_DAY = 24;
const int NO_MINUTES_IN_HOUR = 60;
const int NO_SECONDS_IN_MINUTE = 60;
const int NO_SEC_IN_DAY = NO_HOURS_IN_DAY * NO_MINUTES_IN_HOUR * NO_SECONDS_IN_MINUTE;
const int NO_SEC_IN_HOUR = NO_MINUTES_IN_HOUR * NO_SECONDS_IN_MINUTE;
 
/****************************************************************************
 *
 * DurationBase
 *
 ****************************************************************************/

int DurationBase::compare(const DurationBase& dt) const
{
  return toDuration()->compare(*dt.toDuration());
}

bool DurationBase::operator==(const DurationBase& dt) const
{
  return *toDuration() == *dt.toDuration();
}

/****************************************************************************
 *
 * YearMonthDuration
 *
 ****************************************************************************/

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

bool YearMonthDuration::operator<(const YearMonthDuration& ymd) const
{
  if (months < ymd.months)
    return true;
  else
    return false;
}

bool YearMonthDuration::operator==(const YearMonthDuration& ymd) const
{
  if (months == ymd.months)
    return true;
  else
    return false;
}

xqpString YearMonthDuration::toString(bool output_when_zero) const
{
  xqpString result = "";
  long abs_months = months;

  if (months == 0)
  {
    if (output_when_zero)
      return "P0M";
    else
      return "";
  }

  if (months < 0)
  {
    result += "-";
    abs_months = -months;
  }

  result += "P";

  if (abs_months >= 12 )
    result = result + NumConversions::longToStr(abs_months / 12) + "Y";

  if ((abs_months%12) != 0)
    result = result + NumConversions::longToStr(abs_months % 12) + "M";
    
  return result;
}

Duration_t YearMonthDuration::toDuration() const
{
  Duration_t d_t = new Duration(*this);
  return d_t;
}

Duration_t YearMonthDuration::toNegDuration() const
{
  Duration_t d_t = new Duration(*this, true);
  return d_t;
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
  xqp_double lDouble = xqp_double::parseInt(months) * value;
  xqp_long lLong;
  bool b = NumConversions::doubleToLongLong(lDouble.round(), lLong);
  assert(b);
  YearMonthDuration* ym = new YearMonthDuration( lLong );
  return ym;
}

DurationBase_t YearMonthDuration::operator/(const Double value) const
{
  xqp_double lDouble = xqp_double::parseInt(months) / value;
  xqp_long lLong;
  bool b = NumConversions::doubleToLongLong(lDouble.round(), lLong);
  assert(b);
  YearMonthDuration* ym = new YearMonthDuration(lLong);
  return ym;
}

Decimal YearMonthDuration::operator/(const DurationBase& db) const
{
  const YearMonthDuration& ymd = dynamic_cast<const YearMonthDuration&>(db);
  Decimal res = Decimal::parseLong( months )/ Decimal::parseLong( ymd.months );
  return res;
}

int YearMonthDuration::getYears() const
{
  long lLong = months/(long)NO_MONTHS_IN_YEAR;
  return (int)lLong;
}

int YearMonthDuration::getMonths() const
{
  long lLong = months % (long)NO_MONTHS_IN_YEAR;
  return (int)lLong;
}

int YearMonthDuration::getDays() const
{
  return 0;
}

int YearMonthDuration::getHours() const
{
  return 0;
}

int YearMonthDuration::getMinutes() const
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

/****************************************************************************
 *
 * DayTimeDuration
 *
 ****************************************************************************/
DayTimeDuration::DayTimeDuration() : is_negative(false), days(0), timeDuration(0, 0, 0, 0)
{
};

DayTimeDuration::DayTimeDuration(bool negative, long the_days, long hours, long minutes, long seconds, long frac_seconds)
{
  if (abs<long>(hours) >= 24)
  {
    the_days += quotient<long>(hours, 24);
    hours = modulo<long>(hours, 24);
  }
  
  is_negative = negative;
  days = abs<long>(the_days);
  timeDuration = boost::posix_time::time_duration(abs<long>(hours), abs<long>(minutes), abs<long>(seconds), abs<long>(frac_seconds));
  
  if (isZero())
    is_negative = false;
}

DayTimeDuration& DayTimeDuration::operator=(const DayTimeDuration_t& dt_t)
{
  is_negative = dt_t->is_negative;
  days = dt_t->days;
  timeDuration = dt_t->timeDuration;
  return *this;
}

bool DayTimeDuration::operator<(const DayTimeDuration& dtd) const
{
  if (is_negative != dtd.is_negative)
    return (is_negative == true);
  else if (days != dtd.days)
    return (days < dtd.days);
  else
    return timeDuration < dtd.timeDuration;
}

bool DayTimeDuration::operator==(const DayTimeDuration& dtd) const
{
  if (is_negative == dtd.is_negative
      &&
      days == dtd.days
      &&
      timeDuration == dtd.timeDuration)
    return true;
  else
    return false;
}

bool DayTimeDuration::isZero() const
{
  return (days == 0 && timeDuration.hours() == 0 && timeDuration.minutes() == 0
    &&
    timeDuration.seconds() == 0 && timeDuration.fractional_seconds() == 0);
}

#define OUTPUT_T_SEPARATOR(result, have_t_separator)  do { \
  if (!have_t_separator) { \
    result += "T"; \
    have_t_separator = true; \
  } \
} while(0);

xqpString DayTimeDuration::toString(bool output_when_zero) const
{
  xqpString result = "";
  bool have_t_separator = false;

  if (isZero())
  {
    if (output_when_zero)
      return "PT0S";
    else
      return "";
  }
    
  if ( is_negative )
    result += "-";

  result += "P";

  if ( days != 0 )
    result += NumConversions::longToStr ( days ) + "D";

  if ( timeDuration.hours() != 0)
  {
    OUTPUT_T_SEPARATOR(result, have_t_separator);
    result += NumConversions::intToStr ( timeDuration.hours() ) + "H";
  }

  if ( timeDuration.minutes() != 0 )
  {
    OUTPUT_T_SEPARATOR(result, have_t_separator);
    result += NumConversions::intToStr ( timeDuration.minutes() ) + "M";
  }

  if (timeDuration.seconds() != 0 || timeDuration.fractional_seconds() != 0)
  {
    OUTPUT_T_SEPARATOR(result, have_t_separator);
    result += NumConversions::intToStr ( timeDuration.seconds() );

    if ( timeDuration.fractional_seconds() != 0 )
    {
      // delete the trailing zeros
      int temp = timeDuration.fractional_seconds();
      while (temp != 0 && ((temp%10) == 0))
        temp /= 10;
      result += "." + NumConversions::longToStr(temp);
    }

    result += "S";
  }

  return result;
}

Duration_t DayTimeDuration::toDuration() const
{
  Duration_t d_t = new Duration(*this);
  return d_t;
}

Duration_t DayTimeDuration::toNegDuration() const
{
  Duration_t d_t = new Duration(*this, true);
  return d_t;
}

DurationBase_t DayTimeDuration::operator+(const DurationBase& db) const
{
  const DayTimeDuration& dtd = dynamic_cast<const DayTimeDuration&>(db);
  long resDays;
  bool resIsNeg;
  
  resDays = (is_negative?-1:1)*days + (dtd.is_negative?-1:1)*dtd.days;
  boost::posix_time::time_duration resTimeDuration = timeDuration*(is_negative?-1:1) + dtd.timeDuration*(dtd.is_negative?-1:1);
  
  //TODO: move sign resolution to constructor
  if (resDays != 0)
    resIsNeg = resDays < 0;
  else if (resTimeDuration.hours() != 0)
    resIsNeg = resTimeDuration.hours() < 0;
  else if (resTimeDuration.minutes() != 0)
    resIsNeg = resTimeDuration.minutes() < 0;
  else if (resTimeDuration.seconds() != 0)
    resIsNeg = resTimeDuration.seconds() < 0;
  else if (resTimeDuration.fractional_seconds() != 0)
    resIsNeg = resTimeDuration.fractional_seconds() < 0;

  DayTimeDuration_t dt_t = new DayTimeDuration(
      resIsNeg,
      resDays,
      resTimeDuration.hours(),
      resTimeDuration.minutes(),
      resTimeDuration.seconds(),
      resTimeDuration.fractional_seconds());

  return &*dt_t;
}

DurationBase_t DayTimeDuration::operator-(const DurationBase& db) const
{
  const DayTimeDuration& dtd = dynamic_cast<const DayTimeDuration&>(db);
  long resDays;
  bool resIsNeg;

  resDays = (is_negative?-1:1)*days - (dtd.is_negative?-1:1)*dtd.days;
  boost::posix_time::time_duration resTimeDuration = timeDuration*(is_negative?-1:1) - dtd.timeDuration*(dtd.is_negative?-1:1);

  //TODO: move sign resolution to constructor
  if (resDays != 0)
    resIsNeg = resDays < 0;
  else if (resTimeDuration.hours() != 0)
    resIsNeg = resTimeDuration.hours() < 0;
  else if (resTimeDuration.minutes() != 0)
    resIsNeg = resTimeDuration.minutes() < 0;
  else if (resTimeDuration.seconds() != 0)
    resIsNeg = resTimeDuration.seconds() < 0;
  else if (resTimeDuration.fractional_seconds() != 0)
    resIsNeg = resTimeDuration.fractional_seconds() < 0;

  DayTimeDuration_t dt_t = new DayTimeDuration(
      resIsNeg,
      resDays,
      resTimeDuration.hours(),
      resTimeDuration.minutes(),
      resTimeDuration.seconds(),
      resTimeDuration.fractional_seconds());

  return &*dt_t;
}

DurationBase_t DayTimeDuration::operator*(const Double value) const
{
  bool b;
  long resFrac;
  xqp_double frac = xqp_double::parseLong(timeDuration.fractional_seconds());
  xqp_double lFrac = frac * value;
  b = NumConversions::doubleToLong(lFrac.round(), resFrac);
  assert(b);
  
  long resSeconds = days * NO_HOURS_IN_DAY * NO_MINUTES_IN_HOUR * NO_SECONDS_IN_MINUTE + timeDuration.total_seconds();
  xqp_double lDouble = xqp_double::parseLong(resSeconds) * value;
  b = NumConversions::doubleToLong(lDouble.round(), resSeconds);
  assert(b);
  
  //TODO Should normalization be part of the constructor?
  DayTimeDuration* dt = new DayTimeDuration(
      is_negative,
      resSeconds / NO_SEC_IN_DAY, //days
      (resSeconds % NO_SEC_IN_DAY) / NO_SEC_IN_HOUR, //hours
      ((resSeconds % NO_SEC_IN_DAY) % NO_SEC_IN_HOUR) / NO_SECONDS_IN_MINUTE, //minutes
      ((resSeconds % NO_SEC_IN_DAY) % NO_SEC_IN_HOUR) % NO_SECONDS_IN_MINUTE, //seconds
      resFrac);

  return dt;
}

DurationBase_t DayTimeDuration::operator/(const Double value) const
{
  bool b;
  long resFrac;
  xqp_double frac = xqp_double::parseLong(timeDuration.fractional_seconds());
  xqp_double lFrac = frac / value;
  b = NumConversions::doubleToLong(lFrac.round(), resFrac);
  assert(b);
  
  long resSeconds;
  xqp_double seconds = xqp_double::parseLong(days * NO_SEC_IN_DAY + timeDuration.total_seconds());
  xqp_double lDouble = seconds / value;
  b = NumConversions::doubleToLong(lDouble.round(), resSeconds);
  assert(b);

  //TODO Should normalization be part of the constructor?
  DayTimeDuration* dt = new DayTimeDuration(
      (resSeconds < 0)? !is_negative: is_negative ,
      resSeconds / NO_SEC_IN_DAY, //days
      (resSeconds % NO_SEC_IN_DAY) / NO_SEC_IN_HOUR, //hours
      ((resSeconds % NO_SEC_IN_DAY) % NO_SEC_IN_HOUR) / NO_SECONDS_IN_MINUTE, //minutes
      ((resSeconds % NO_SEC_IN_DAY) % NO_SEC_IN_HOUR) % NO_SECONDS_IN_MINUTE, //seconds
      resFrac);

  return dt;
}

Decimal DayTimeDuration::operator/(const DurationBase& db) const
{
  long lLong = days * NO_SEC_IN_DAY + timeDuration.total_seconds()+ timeDuration.fractional_seconds();
  Decimal op1 = Decimal::parseLong(lLong);
  if( is_negative )
    op1 = -op1;

  const DayTimeDuration& dtd = dynamic_cast<const DayTimeDuration&>(db);
  long lLong2 = dtd.days * NO_SEC_IN_DAY + dtd.timeDuration.total_seconds() + dtd.timeDuration.fractional_seconds();
  Decimal op2 = Decimal::parseLong(lLong2);
  if( is_negative )
    op2 = -op2;

  return op1/op2;
}

int DayTimeDuration::getYears() const
{
  return 0;
}

int DayTimeDuration::getMonths() const
{
  return 0;
}

int DayTimeDuration::getDays() const
{
  return (is_negative? -1 : 1) * days;
}

int DayTimeDuration::getHours() const
{
  return (is_negative? -1 : 1) * timeDuration.hours();
}

int DayTimeDuration::getMinutes() const
{
  return (is_negative? -1 : 1) * timeDuration.minutes();
}

double DayTimeDuration::getSeconds() const
{
  double frac_sec = double(timeDuration.fractional_seconds()) / boost::posix_time::time_duration::ticks_per_second();
  return (is_negative? -1 : 1) * (timeDuration.seconds()+frac_sec);
}

// parse a 'nS' string, with fractional seconds, returns true on success and false on failure
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
  
  // process the fractional seconds
  double frac = frac_seconds;
  while (frac >= 1)
    frac /= 10;

  dt_t = new DayTimeDuration(negative, days, hours, minutes, seconds, 
                             round(frac * boost::posix_time::time_duration::ticks_per_second()));
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

/****************************************************************************
 *
 * Duration
 *
 ****************************************************************************/

Duration::Duration(const YearMonthDuration& ymd, bool negate) : yearMonthDuration(ymd)
{
  if (negate)
    yearMonthDuration.months = -yearMonthDuration.months;
}

Duration::Duration(const DayTimeDuration& dtd, bool negate) : dayTimeDuration(dtd)
{
  if (negate && !dayTimeDuration.isZero())
    dayTimeDuration.is_negative = !dayTimeDuration.is_negative;
}

int Duration::from_Timezone(const TimeZone& t, Duration_t& dt)
{
  if(t.is_not_a_date_time())
    return 1;
  
  dt = new Duration( DayTimeDuration(t.is_negative(), 0, t.getHours(), t.getMinutes(), t.getSeconds(), t.getFractionalSeconds()) );
  return 0;
}

bool Duration::operator<(const Duration& d) const
{
  if (yearMonthDuration == d.yearMonthDuration)
    return dayTimeDuration < d.dayTimeDuration;
  else if (dayTimeDuration == d.dayTimeDuration)
    return yearMonthDuration < d.yearMonthDuration;
  else
  {
    // it should not be possible to compare duration in the other cases.
    assert(0);
    return false;
  }
}

bool Duration::operator==(const Duration& d) const
{
  if (yearMonthDuration == d.yearMonthDuration
      &&
      dayTimeDuration == d.dayTimeDuration)
    return true;
  else
    return false;
}

int Duration::compare(const Duration& d) const
{
  if (operator<(d))
    return -1;
  if (operator==(d))
    return 0;
  else
    return 1;
}

bool Duration::isNegative() const
{
  if (!yearMonthDuration.isZero())
    return yearMonthDuration.isNegative();
  else
    return dayTimeDuration.isNegative();
}

xqpString Duration::toString(bool output_when_zero) const
{
  xqpString result = yearMonthDuration.toString(false)
      +
      dayTimeDuration.toString(yearMonthDuration.isZero()).substr(yearMonthDuration.isZero()? 0 : 1);

  return result;
}

Duration_t Duration::toDuration() const
{
  Duration_t d_t = new Duration(*this);
  return d_t;
}

Duration_t Duration::toNegDuration() const
{
  Duration_t d_t = new Duration(*this);
  if (!d_t->yearMonthDuration.isZero())
    d_t->yearMonthDuration.months = - d_t->yearMonthDuration.months;
  else if (!d_t->dayTimeDuration.isZero())
    d_t->dayTimeDuration.is_negative = !d_t->dayTimeDuration.is_negative;
  return d_t;
}

DurationBase_t Duration::operator+(const DurationBase& db) const
{
  assert(0); // Addition not defined for general Duration
  return NULL;
}

DurationBase_t Duration::operator-(const DurationBase& db) const
{
  assert(0); // Substraction not defined for general Duration
  return NULL;
}

DurationBase_t Duration::operator*(const Double value) const
{
  return NULL;
}

DurationBase_t Duration::operator/(const Double value) const
{
  return NULL;
}

Decimal Duration::operator/(const DurationBase& db) const
{
  return Decimal::parseInt(0);
}

int Duration::getYears() const
{
  // yearMonthDuration.getYears() already has the correct sign
  return yearMonthDuration.getYears();
}

int Duration::getMonths() const
{
  // yearMonthDuration.getMonths() already has the correct sign
  return yearMonthDuration.getMonths();
}

int Duration::getDays() const
{
  return (isNegative() && !yearMonthDuration.isZero()? -1 : 1) * dayTimeDuration.getDays();
}

int Duration::getHours() const
{
  return (isNegative() && !yearMonthDuration.isZero()? -1 : 1) * dayTimeDuration.getHours();
}

int Duration::getMinutes() const
{
  return (isNegative() && !yearMonthDuration.isZero()? -1 : 1) * dayTimeDuration.getMinutes();
}

double Duration::getSeconds() const
{
  return (isNegative() && !yearMonthDuration.isZero()? -1 : 1) * dayTimeDuration.getSeconds();
}

// Parse a '(-)PnYnMnDTnHnMnS'
bool Duration::parse_string(const xqpString& s, Duration_t& d_t)
{
  int pos, t_pos;
  YearMonthDuration_t ymd_t;
  DayTimeDuration_t dtd_t;

  t_pos = s.indexOf("T");
  pos = s.indexOf("M");
  if (pos == -1)
    pos = s.indexOf("Y");
  else if (t_pos != -1 && t_pos < pos)
    pos = -1;

  // Check month or year
  if (pos != -1)
  {
    if (!YearMonthDuration::parse_string(s.substr(0, pos+1), ymd_t))
      return false;
    d_t = new Duration(*ymd_t);
    
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
    d_t = new Duration(*dtd_t);
  }
  
  return true;
}

}
