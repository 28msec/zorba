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
#include <memory>

#include "zorbautils/hashfun.h"
#include <zorbatypes/duration.h>
#include "zorbatypes/datetime/parse.h"
#include "zorbatypes/numconversions.h"
#include "zorbatypes/datetime.h"


namespace zorba
{

const int Duration::FRAC_SECONDS_UPPER_LIMIT = 1000000;

static const long max_value[] = { 0, 12, 30, 24, 60, 60, Duration::FRAC_SECONDS_UPPER_LIMIT};


Duration::Duration()
{
  facet = DURATION_FACET;
  is_negative = false;
  for (int i=0; i <= FRACSECONDS_DATA; i++)
    data[i] = 0;
}

Duration::Duration(FACET_TYPE facet_type) : facet(facet_type)
{
  is_negative = false;
  for (int i=0; i <= FRACSECONDS_DATA; i++)
    data[i] = 0;
}

Duration::Duration(FACET_TYPE facet_type, long years, long months, long days,
         long hours, long minutes, double seconds)
{
  seconds = abs<double>(seconds);

  is_negative = false;
  if (years != 0 && years < 0)
    is_negative = true;
  else if (months != 0 && months < 0)
    is_negative = true;
  else if (days != 0 && days < 0)
    is_negative = true;
  else if (hours != 0 && hours < 0)
    is_negative = true;
  else if (minutes != 0 && minutes < 0)
    is_negative = true;
  else if (seconds != 0 && seconds < 0)
    is_negative = true;

  facet = facet_type;
  data[YEAR_DATA] = abs<long>(years);
  data[MONTH_DATA] = abs<long>(months);
  data[DAY_DATA] = abs<long>(days);
  data[HOUR_DATA] = abs<long>(hours);
  data[MINUTE_DATA] = abs<long>(minutes);
  data[SECONDS_DATA] = floor<double>(seconds);
  data[FRACSECONDS_DATA] = round(frac(seconds) * FRAC_SECONDS_UPPER_LIMIT);

  normalize();
}


Duration::Duration(FACET_TYPE facet_type, bool negative, long years, long months, long days,
         long hours, long minutes, double seconds)
{
  seconds = abs<double>(seconds);

  facet = facet_type;
  is_negative = negative;
  data[YEAR_DATA] = abs<long>(years);
  data[MONTH_DATA] = abs<long>(months);
  data[DAY_DATA] = abs<long>(days);
  data[HOUR_DATA] = abs<long>(hours);
  data[MINUTE_DATA] = abs<long>(minutes);
  data[SECONDS_DATA] = floor<double>(seconds);
  data[FRACSECONDS_DATA] = round(frac(seconds) * FRAC_SECONDS_UPPER_LIMIT);

  normalize();
}

Duration::Duration(FACET_TYPE facet_type, bool negative, long years, long months, long days,
           long hours, long minutes, int seconds, int frac_seconds)
{
  facet = facet_type;
  is_negative = negative;
  data[YEAR_DATA] = abs<long>(years);
  data[MONTH_DATA] = abs<long>(months);
  data[DAY_DATA] = abs<long>(days);
  data[HOUR_DATA] = abs<long>(hours);
  data[MINUTE_DATA] = abs<long>(minutes);
  data[SECONDS_DATA] = abs<long>(seconds);
  data[FRACSECONDS_DATA] = abs<long>(frac_seconds);

  normalize();
}

bool Duration::isNegative() const
{
  return is_negative;
}

long Duration::getYears() const
{
  return (is_negative? -1 : 1) * data[YEAR_DATA];
}

long Duration::getMonths() const
{
  return (is_negative? -1 : 1) * data[MONTH_DATA];
}

long Duration::getDays() const
{
  return (is_negative? -1 : 1) * data[DAY_DATA];
}

long Duration::getHours() const
{
  return (is_negative? -1 : 1) * data[HOUR_DATA];
}

long Duration::getMinutes() const
{
  return (is_negative? -1 : 1) * data[MINUTE_DATA];
}

double Duration::getSeconds() const
{
  return (is_negative? -1 : 1) * (data[SECONDS_DATA] + double(data[FRACSECONDS_DATA]) / FRAC_SECONDS_UPPER_LIMIT);
}

long Duration::getFractionalSeconds() const
{
  return (is_negative? -1 : 1) * data[FRACSECONDS_DATA];
}

long Duration::getIntSeconds() const
{
  return (is_negative? -1 : 1) * data[SECONDS_DATA];
}

Double Duration::getTotalSeconds() const
{
  return (is_negative? Double::parseLong(-1) : Double::parseLong(1))
      * ((((((((Double::parseLong(data[YEAR_DATA]) * Double::parseLong(12)
      + Double::parseLong(data[MONTH_DATA])) * Double::parseLong(30))
      + Double::parseLong(data[DAY_DATA])) * Double::parseLong(24))
      + Double::parseLong(data[HOUR_DATA])) * Double::parseLong(60))
      + Double::parseLong(data[MINUTE_DATA])) * Double::parseLong(60))
      + Double::parseLong(data[SECONDS_DATA])
      + Double::parseFloatType(double(data[FRACSECONDS_DATA]) / FRAC_SECONDS_UPPER_LIMIT);
}

int Duration::fromTimezone(const TimeZone& t, Duration& d)
{
  if(!t.timeZoneNotSet())
  {
    d = Duration(DAYTIMEDURATION_FACET, t.isNegative(), 0, 0, 0, t.getHours(), t.getMinutes(), t.getIntSeconds(), t.getFractionalSeconds() );
    return 0;
  }
  else
    return 1;
}
 
bool Duration::operator==(const Duration& d) const 
{
  if (is_negative != d.is_negative)
    return false;
                 
  for (int i=YEAR_DATA; i<=FRACSECONDS_DATA; i++)
    if (data[i] != d.data[i])
      return false;

  return true;
}

bool Duration::isZero() const
{ 
  for (int i=0; i<FRACSECONDS_DATA; i++)
    if (data[i] != 0)
      return false;

  return true;
}

int Duration::compare(const Duration& d, bool ignore_sign) const
{
  for (int i=YEAR_DATA; i<=FRACSECONDS_DATA; i++)
    if ( (is_negative && !ignore_sign ? -1 : 1)*data[i] > (d.is_negative && !ignore_sign? -1 : 1)*d.data[i])
      return 1;
    else if ((is_negative && !ignore_sign? -1 : 1)*data[i] < (d.is_negative && !ignore_sign? -1 : 1)*d.data[i])
      return -1;
  
  return 0;
}

Duration* Duration::operator+(const Duration& d) const
{
  int start_data;
  int end_data;
  Duration* result;

  if (compare(d, true) == -1)
    return d.operator+(*this);
  
  if (facet == YEARMONTHDURATION_FACET && d.facet == YEARMONTHDURATION_FACET)
  {
    start_data = MONTH_DATA;
    end_data = YEAR_DATA;
  }
  else if (facet == DAYTIMEDURATION_FACET && d.facet == DAYTIMEDURATION_FACET)
  {
    start_data = FRACSECONDS_DATA;
    end_data = DAY_DATA;
  }
  else
  {
    assert(0);
    return NULL;
  }
  
  result = new Duration(facet);
  long carry = 0;
  bool right_operand_sign = (is_negative != d.is_negative);
  for (int i=start_data; i>=end_data; i--)
  {
    if (i == FRACSECONDS_DATA)
    {
      double sum = double(data[i] + (right_operand_sign? -1 : 1) * d.data[i]) / FRAC_SECONDS_UPPER_LIMIT;
      result->data[FRACSECONDS_DATA] = round(frac(sum)*FRAC_SECONDS_UPPER_LIMIT);
      carry = floor<double>(sum);
    }
    else
    {
      long sum = data[i] + (right_operand_sign? -1 : 1) * d.data[i] + carry;

      if (i == end_data)
      {
        result->data[i] = sum;
      }
      else
      {
        carry = quotient<long>(sum, max_value[i]);
        result->data[i] = modulo<long>(sum, max_value[i]);
      }
    }
  }

  result->is_negative = is_negative;
  
  return result;
}

Duration* Duration::operator-(const Duration& d) const
{
  std::auto_ptr<Duration> temp = std::auto_ptr<Duration>(d.toNegDuration());
  return operator+(*temp);
}
      
Duration* Duration::operator*(const Double value) const
{
  Double result;
  long seconds;
  long frac_seconds;

  if (facet == DURATION_FACET)
  {
    assert(0);
    return NULL;
  }
  
  Double tps = Double::parseFloatType(FRAC_SECONDS_UPPER_LIMIT);

  result = getTotalSeconds() * value;
  result = (result * tps).round() / tps;
  NumConversions::doubleToLong(result.floor(), seconds);
  
  result = (result - result.floor()) * tps;
  NumConversions::doubleToLong(result.round(), frac_seconds);

  Duration* d = new Duration(facet, seconds<0, 0, 0, 0, 0, 0, seconds, frac_seconds);
  return d;
}
      
Duration* Duration::operator/(const Double value) const
{
  Double result;
  long seconds;
  long frac_seconds;

  if (facet == DURATION_FACET)
  {
    assert(0);
    return NULL;
  }
  
  Double tps = Double::parseFloatType(FRAC_SECONDS_UPPER_LIMIT);
  
  result = getTotalSeconds() / value;
  result = (result * tps).round() / tps;
  NumConversions::doubleToLong(result.floor(), seconds);

  result = (result - result.floor()) * tps;
  NumConversions::doubleToLong(result.round(), frac_seconds);

  Duration* d = new Duration(facet, seconds<0, 0, 0, 0, 0, 0, seconds, frac_seconds);
  return d;
}
      
Decimal Duration::operator/(const Duration& d) const
{
  Decimal op1, op2;

  Decimal::parseDouble(getTotalSeconds(), op1);
  Decimal::parseDouble(d.getTotalSeconds(), op2);
  
  return op1 / op2;
}

Duration* Duration::toNegDuration() const
{
  Duration* d = new Duration(*this);

  if (!isZero())
    d->is_negative = !d->is_negative;

  return d;
}
      
Duration* Duration::toDuration() const
{
  Duration* d = new Duration(*this);
  d->facet = DURATION_FACET;
  return d;
}

Duration* Duration::toYearMonthDuration() const
{
  Duration* d = new Duration(*this);

  d->facet = YEARMONTHDURATION_FACET;
  for (int i=DAY_DATA; i<=FRACSECONDS_DATA; i++)
    d->data[i] = 0;
  
  return d;
}

Duration* Duration::toDayTimeDuration() const
{
  Duration* d = new Duration(*this);

  d->data[MONTH_DATA] = 0;
  d->data[YEAR_DATA] = 0;
  d->facet = DAYTIMEDURATION_FACET;
    
  return d;
}

void Duration::normalize()
{
  long carry = 0;
    
  for (int i = SECONDS_DATA; i>YEAR_DATA; i--)
  {
    data[i] += carry;
    carry = quotient<long>(data[i], max_value[i]);
    data[i] = modulo<long>(data[i], max_value[i]);
  }
  
  data[YEAR_DATA] += carry;

  adjustToFacet();
}

void Duration::adjustToFacet()
{
  // assumes the data is normalized. Otherwise call normalize(), which will adjust to facet, too
  if (facet == YEARMONTHDURATION_FACET)
    for (int i=FRACSECONDS_DATA; i>=DAY_DATA; i--)
    {
      if (data[i] >= max_value[i]/2 && !is_negative)
        data[i-1] += 1;
      
      data[i] = 0;
    }

  if (facet == DAYTIMEDURATION_FACET)
  {
    data[DAY_DATA] += data[MONTH_DATA] * 30 + data[YEAR_DATA] * 12 * 30;
    data[MONTH_DATA] = 0;
    data[YEAR_DATA] = 0;
  }

  if (isZero())
    is_negative = false;
}

void Duration::setFacet(FACET_TYPE a_facet)
{
  facet = a_facet;
  normalize();
}
  
int Duration::parseYearMonthDuration(const xqpString& s, Duration& d)
{
  std::string ss = s.getStore()->str();
  bool negative = false;
  unsigned int position = 0;
  long result, months = 0;
  
  skip_whitespace(ss, position);

  if (position == ss.size())
    return 1;
    
  if (ss[position] == '-')
  {
    negative = true;
    position++;
  }

  if (position == ss.size() || ss[position++] != 'P')
    return 1;
    
  if (position == ss.size() || parse_int(ss, position, result))
    return 1;
    
  if (position == ss.size())
    return 1;

  if (ss[position] == 'Y')
  {
    position++;
    months = result * 12;

    if (position < ss.size())
    {
      if (parse_int(ss, position, result) == 0)
      {
        if (ss[position++] != 'M')
          return 1;

        months += result;
      }
      else
        return 1;
    }
  }
  else if (ss[position++] == 'M')
  {
    months = result;
  }
  else
    return 1;

  if (ss.size() != position)
    return 1;

  d = Duration(YEARMONTHDURATION_FACET, negative, 0, months, 0, 0, 0, 0);
  return 0;
}
    
    
// parse a 'nS' string, with fractional seconds, returns true on success and false on failure
static bool parse_s_string(std::string ss, unsigned int& position, long& seconds, long& frac_seconds)
{
  long result;
  double temp_frac_seconds;
  
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

    if (position == ss.size() || parse_frac(ss, position, temp_frac_seconds))
      return false;

    if (position == ss.size() || ss[position] != 'S')
      return false;

    position++;
    frac_seconds = round(temp_frac_seconds * Duration::FRAC_SECONDS_UPPER_LIMIT);
  }

  return true;
}

// parse a 'nMnS' string, with fractional seconds
static bool parse_ms_string(std::string ss, unsigned int& position, long& minutes, long& seconds, long& frac_seconds)
{
  long result;
  double temp_frac_seconds;
  
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

    if (position == ss.size() || parse_frac(ss, position, temp_frac_seconds))
      return false;

    if (position == ss.size() || ss[position] != 'S')
      return false;

    position++;
    frac_seconds = round(temp_frac_seconds * Duration::FRAC_SECONDS_UPPER_LIMIT);
  }

  return true;
}

// parse a 'nHnMnS' string, with fractional seconds
static bool parse_hms_string(std::string ss, unsigned int& position, long& hours, long& minutes, long& seconds, long& frac_seconds)
{
  long result;
  double temp_frac_seconds;
  
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

    if (position == ss.size() || parse_frac(ss, position, temp_frac_seconds))
      return false;

    if (position == ss.size() || ss[position] != 'S')
      return false;

    position++;
    frac_seconds = round(temp_frac_seconds * Duration::FRAC_SECONDS_UPPER_LIMIT);
  }

  return true;
}

// Parse a 'PnDTnHnMnS' dateTime duration
int Duration::parseDayTimeDuration(const xqpString& s, Duration& d, bool dont_check_letter_p)
{
  std::string ss = s.getStore()->str();
  bool negative = false;
  unsigned int position = 0;
  long result, days = 0, hours = 0, minutes = 0, seconds = 0, frac_seconds = 0;

  skip_whitespace(ss, position);
  
  if (position == ss.size())
    return 1;
  
  if (ss[position] == '-')
  {
    negative = 1;
    position++;
  }

  if (!dont_check_letter_p && (position == ss.size() || ss[position++] != 'P'))
    return 1;

  if (position == ss.size())
    return 1;

  // It must be either 'T' or 'nD'
  if (ss[position] != 'T')
  {
    if (parse_int(ss, position, result))
      return 1;

    days = result;

    if (position == ss.size() || ss[position++] != 'D')
      return 1;
  }

  // Either 'T', or whitespace, or end
  
  if (position<ss.size() && ss[position] == 'T')
  {
    position++;
    if (!parse_hms_string(ss, position, hours, minutes, seconds, frac_seconds))
      return 1;
  }

  skip_whitespace(ss, position);

  if (ss.size() != position)
    return 1;

  long carry = seconds / 60;
  seconds = seconds % 60;

  minutes += carry;
  carry  = minutes / 60;
  minutes = minutes % 60;

  hours += carry;
  carry = hours / 24;
  hours = hours % 24;

  days += carry;

  d = Duration(DAYTIMEDURATION_FACET, negative, 0, 0, days, hours, minutes, seconds, frac_seconds);
  return 0;
}

int Duration::parseDuration(const xqpString& s, Duration& d)
{
  int pos, t_pos;
  Duration ymd;
  Duration dtd;

  t_pos = s.indexOf("T");
  pos = s.indexOf("M");
  if (pos == -1)
    pos = s.indexOf("Y");
  else if (t_pos != -1 && t_pos < pos)
    pos = -1;

  // Check month or year
  if (pos != -1)
  {
    if (0 != Duration::parseYearMonthDuration(s.substr(0, pos+1), ymd))
      return 1;
    d = Duration(ymd);
    
    if ((unsigned int)pos+1 < s.size())
    {
      if (0 != Duration::parseDayTimeDuration(s.substr(pos+1), dtd, true))
        return 1;
      for (int i=DAY_DATA; i<=FRACSECONDS_DATA; i++)
        d.data[i] = dtd.data[i];
    }
  }
  else
  {
    // No month or year -- parse DayTime
    if (0 != Duration::parseDayTimeDuration(s, dtd))
      return 1;
    d = dtd;
  }

  d.facet = DURATION_FACET;
  return 0;
}

xqpString Duration::toString() const
{
  xqpString result;
  
  if (isZero())
  {
    if (facet == YEARMONTHDURATION_FACET)
      return "P0M";
    else
      return "PT0S";
  }

  if (is_negative)
    result += "-";

  result += "P";

  if (facet != DAYTIMEDURATION_FACET)
  {
    if (data[YEAR_DATA] != 0)
      result = result + NumConversions::longToStr(data[YEAR_DATA]) + "Y";

    if (data[MONTH_DATA] != 0)
      result = result + NumConversions::longToStr(data[MONTH_DATA]) + "M";
  }

  if (facet != YEARMONTHDURATION_FACET)
  {
    if (data[DAY_DATA] != 0)
      result = result + NumConversions::longToStr(data[DAY_DATA]) + "D";

    for (int i=HOUR_DATA; i<=FRACSECONDS_DATA; i++)
      if (data[i] != 0)
      {
        result += "T";
        break;
      }

    if (data[HOUR_DATA] != 0)
      result = result + NumConversions::longToStr(data[HOUR_DATA]) + "H";
    
    if (data[MINUTE_DATA] != 0)
      result = result + NumConversions::longToStr(data[MINUTE_DATA]) + "M";

    if (data[SECONDS_DATA] != 0 || data[FRACSECONDS_DATA] != 0)
    {
      result += NumConversions::intToStr(data[SECONDS_DATA]);

      if ( data[FRACSECONDS_DATA] != 0 )
      {
        int frac_seconds = data[FRACSECONDS_DATA];
        result += ".";
      
        // print leading 0s, if any
        int temp = FRAC_SECONDS_UPPER_LIMIT / 10;
        while (temp > frac_seconds && temp > 0)
        {
          result += '0';
          temp /= 10;
        }
      
        // strip trailing 0s, if any
        while (frac_seconds%10 == 0 && frac_seconds > 0)
          frac_seconds = frac_seconds / 10;
      
        result += to_string(frac_seconds);
      }

      result += "S";
    }
  }
  
  return result;
}

uint32_t Duration::hash() const
{
  uint32_t hval = 0;

  hval = hashfun::h32<int>((int)is_negative, hval);
  for (int i=YEAR_DATA; i<=FRACSECONDS_DATA; i++)
    hval = hashfun::h32<long>(data[i], hval);
  
  return hval;
}

  
} // namespace zorba
