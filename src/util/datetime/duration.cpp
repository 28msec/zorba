/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include "util/datetime/duration.h"
#include "util/datetime/parse.h"
#include "util/numconversions.h"

#include <iostream>
using namespace std;

namespace xqp
{
    

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
    result = result + NumConversions::integerToStr(abs_months / 12) + "Y";

  if (abs_months%12 != 0)
    result = result + NumConversions::integerToStr(abs_months % 12) + "M";
    
  // TODO:
  return result;
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
    months = result * 12;

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

  if (is_negative)
    result += "-";

  result += "P";

  /*
  if (days == 0)



  
  long abs_months = months;

  if (months < 0)
  {
    result += "-";
    abs_months = -months;
  }

  result += "P";

  if (abs_months > 12 )
    result = result + NumConversions::integerToStr(abs_months / 12) + "Y";

  if (abs_months%12 != 0)
    result = result + NumConversions::integerToStr(abs_months % 12) + "M";
    
  // TODO:
  return result;
  */

  // TODO:
  return NULL;
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
    if( !parse_s_string(ss, position, seconds, frac_seconds))
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
    if (!parse_ms_string(ss, position, minutes, seconds, frac_seconds))
      return false;
  }
  else if (ss[position] == 'M')
  {
    position++;
    minutes = result;
    if (!parse_s_string(ss, position, seconds, frac_seconds))
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

  dt_t = new DayTimeDuration(negative, days, minutes, hours, seconds, frac_seconds);
  return true;
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
  // TODO:
  return NULL;
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

  // Check month or year
  if (pos != -1)
  {
    d_t = new Duration();
    if (YearMonthDuration::parse_string(s.substr(0, pos+1), ymd_t))
      d_t->yearMonthDuration = *ymd_t;
    else
      return false;

    if ((unsigned int)pos+1 < s.size())
    {
      if (DayTimeDuration::parse_string(s.substr(pos+1, s.size() - pos - 1), dtd_t, false))
        d_t->dayTimeDuration = *dtd_t;
      else
        return false;
    }
  }
  // No month or year -- parse DayTime
  else 
  {
    d_t = new Duration();
    if (DayTimeDuration::parse_string(s, dtd_t))
      d_t->dayTimeDuration = *dtd_t;
    else
      return false;
  }
  
  return true;
}

}
