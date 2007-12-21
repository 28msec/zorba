/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include "util/datetime/duration.h"
#include <string>
#include "errors/Error.h"

namespace xqp
{
    
/**
 * Whitespace characters used in the functions below
 */
static const char* whitespace = " \t\r\n";

/**
 * The function skips any whitespace in the given string,
 * advancing the position parameter.
 *
 */
static void skip_whitespace(std::string& s, unsigned int& position)
{
  int done = 0;

  while (!done && position < s.size())
  {
    done = 1;
    for (unsigned int i=0; i<strlen(whitespace); i++)
      if (s[position] == whitespace[i])
    {
      position++;
      done = 0;
      break;
    }
  }
}

// Returns 1 if there is an error
static int parse_int(std::string& s, unsigned int& position, long& result)
{
  long mult = 1;
  
  if (s[position] < '0' || s[position] > '9')
    return 1;

  result = 0;
  while (s[position] >= '0' && s[position] <= '9' && position < s.size())
  {
    mult++;
    result += mult*result + s[position] - '0';
    position++;
  }

  return 0;
}

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

bool YearMonthDuration::operator<(const YearMonthDuration& ym)
{
  if (months < ym.months)
    return true;
  else
    return false;
}

bool YearMonthDuration::operator==(const YearMonthDuration& ym)
{
  if (months == ym.months)
    return true;
  else
    return false;
}
    
YearMonthDuration_t YearMonthDuration::parse_string(xqpString s)
{
  std::string ss = s.getStore();
  bool negative = false;
  unsigned int position = 0;
  long result, months;
  YearMonthDuration_t ym_t;

  skip_whitespace(ss, position);

  if (position == ss.size())
    ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);
  
  if (ss[position] == '-')
  {
    negative = 1;
    position++;
  }

  if (position == ss.size() || ss[position++] != 'P')
    ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

  if (position == ss.size() || parse_int(ss, position, result))
    ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

  if (position == ss.size())
    ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

  if (ss[position] == 'Y')
  {
    position++;
    months = result * 12;
    
    if (position == ss.size())
      ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

    if (parse_int(ss, position, result) == 0)
    {
      if (ss[position++] != 'M')
        ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

      months += result;
    }
  }
  else if (ss[position++] == 'M')
  {
    months = result;
  }
  else
    ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

  skip_whitespace(ss, position);

  if (ss.size() != position)
    ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

  if (negative)
    months = -months;
  
  ym_t = new YearMonthDuration(months);
  return ym_t;
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

bool DayTimeDuration::operator<(const DayTimeDuration& dt_t)
{
  if (is_negative != dt_t.is_negative)
    return (is_negative == true);
  else if (days != dt_t.days)
    return (days < dt_t.days);
  else
    return timeDuration < dt_t.timeDuration;
}

bool DayTimeDuration::operator==(const DayTimeDuration& dt_t)
{
  if (is_negative == dt_t.is_negative
      &&
      days == dt_t.days
      &&
      timeDuration == dt_t.timeDuration)
    return true;
  else
    return false;
}

// parse a 'nS' string, with fractional seconds
static void parse_s_string(std::string ss, unsigned int& position, long& seconds, long& frac_seconds)
{
  long result;
  
  if (position == ss.size() || parse_int(ss, position, result))
    ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

  if (position == ss.size())
    ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);;

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
      ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

    if (position == ss.size() || ss[position] != 'S')
      ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

    position++;
    frac_seconds = result;
  }

}

// parse a 'nMnS' string, with fractional seconds
static void parse_ms_string(std::string ss, unsigned int& position, long& minutes, long& seconds, long& frac_seconds)
{
  long result;
  
  if (position == ss.size() || parse_int(ss, position, result))
    ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

  if (position == ss.size())
    ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);;

  if (ss[position] == 'M')
  {
    position++;
    minutes = result;
    parse_s_string(ss, position, seconds, frac_seconds);
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
      ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

    if (position == ss.size() || ss[position] != 'S')
      ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

    position++;
    frac_seconds = result;
  }

}

// parse a 'nHnMnS' string, with fractional seconds
static void parse_hms_string(std::string ss, unsigned int& position, long& hours, long& minutes, long& seconds, long& frac_seconds)
{
  long result;
  
  if (position == ss.size() || parse_int(ss, position, result))
    ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

  if (position == ss.size())
    ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);;

  if (ss[position] == 'H')
  {
    position++;
    hours = result;
    parse_ms_string(ss, position, minutes, seconds, frac_seconds);
  }
  else if (ss[position] == 'M')
  {
    position++;
    minutes = result;
    parse_s_string(ss, position, seconds, frac_seconds);
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
      ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

    if (position == ss.size() || ss[position] != 'S')
      ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

    position++;
    frac_seconds = result;
  }
}

// Parse a 'PnDTnHnMnS' dateTime duration
DayTimeDuration_t DayTimeDuration::parse_string(xqpString s, bool dont_check_letter_p)
{
  std::string ss = s.getStore();
  bool negative = false;
  unsigned int position = 0;
  long result, days = 0, hours = 0, minutes = 0, seconds = 0, frac_seconds = 0;
  DayTimeDuration_t dt_t;

  skip_whitespace(ss, position);

  if (position == ss.size())
    ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);
  
  if (ss[position] == '-')
  {
    negative = 1;
    position++;
  }

  if (!dont_check_letter_p && (position == ss.size() || ss[position++] != 'P'))
    ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

  if (position == ss.size())
    ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

  // It must be either 'T' or 'nD'
  if (ss[position] != 'T')
  {
    if (parse_int(ss, position, result))
      ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

    days = result;

    if (position == ss.size() || ss[position++] != 'D')
      ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);
  }

  // Either 'T', or whitespace, or end
  
  if (position<ss.size() && ss[position] == 'T')
  {
    position++;
    parse_hms_string(ss, position, hours, minutes, seconds, frac_seconds);
  }

  skip_whitespace(ss, position);

  if (ss.size() != position)
    ZORBA_ERROR_ALERT(error_messages::FORG0001, NULL);

  dt_t = new DayTimeDuration(negative, days, minutes, hours, seconds, frac_seconds);
  return dt_t;
}


Duration::Duration()
{
  
}

bool Duration::operator==(const Duration& dt)
{
  if (yearMonthDuration == dt.yearMonthDuration
      &&
      dayTimeDuration == dt.dayTimeDuration)
    return true;
  else
    return false;
}

// Parse a '(-)PnYnMnDTnHnMnS'
Duration_t Duration::parse_string(xqpString s)
{
  Duration_t d_t;
  int pos;

  pos = s.indexOf("M");
  if (pos == -1)
    pos = s.indexOf("Y");

  // Check month or year
  if (pos != -1)
  {
    d_t->yearMonthDuration = *YearMonthDuration::parse_string(s.substr(0, pos+1));

    if ((unsigned int)pos+1 < s.size())
      d_t->dayTimeDuration = *DayTimeDuration::parse_string(s.substr(pos+1, s.size() - pos - 1), false);
  }
  // No month or year -- parse DayTime
  else 
  {
    d_t->dayTimeDuration = *DayTimeDuration::parse_string(s);
  }
  
  return d_t;
}

}
