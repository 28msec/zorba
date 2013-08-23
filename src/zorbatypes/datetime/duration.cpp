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
#include "stdafx.h"

#include <cmath>
#include <memory>
#include <string>

#include "zorbatypes/datetime.h"
#include "zorbatypes/datetime/parse.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/duration.h"
#include "zorbatypes/float.h"
#include "zorbatypes/integer.h"
#include "zorbatypes/numconversions.h"
#include "zorbautils/hashfun.h"

#include "diagnostics/xquery_diagnostics.h"

#include "util/ascii_util.h"


namespace zorba
{


const int Duration::FRAC_SECONDS_UPPER_LIMIT = 1000000;

static const long max_value[] =
{
  0, 12, 30, 24, 60, 60, Duration::FRAC_SECONDS_UPPER_LIMIT
};

static const long seconds_per_year = 60 * 60 * 24 * 30 * 12;

/******************************************************************************
  Parse a 'nS' string, with fractional seconds, returns 0 on success and a
  positive value on failure
*******************************************************************************/
static int parse_s_string(
    const char* str,
    ascii::size_type len,
    ascii::size_type& pos,
    long& seconds,
    long& frac_seconds)
{
  ascii::size_type savepos = pos;
  ascii::skip_space(str, len, &pos);
  int err;

  if (pos != savepos) {
    return (pos != len ? 1 : 0);
  }

  long result;

  if ((err = parse_long(str, len, pos, result)) != 0) {
    return err;
  }

  if (pos == len) {
    return 1;
  }

  if (str[pos] == 'S') {
    pos++;
    seconds = result;
  } else if (str[pos] == '.') {
    pos++;
    seconds = result;

    double temp_frac_seconds = 0;
    if ((err = parse_frac(str, len, pos, temp_frac_seconds)) != 0) {
      return err;
    }

    if (pos == len || str[pos] != 'S') {
      return 1;
    }

    pos++;
    frac_seconds = round(temp_frac_seconds * Duration::FRAC_SECONDS_UPPER_LIMIT);
  }

  return 0;
}


/******************************************************************************
  parse a 'nMnS' string, with fractional seconds
*******************************************************************************/
static int parse_ms_string(
    const char* str,
    ascii::size_type len,
    ascii::size_type& pos,
    long& minutes,
    long& seconds,
    long& frac_seconds)
{
  ascii::size_type savepos = pos;
  ascii::skip_space(str, len, &pos);
  int err;

  if (pos != savepos)
    return (pos != len ? 1 : 0);

  long result;

  if ((err = parse_long(str, len, pos, result)) != 0)
    return err;

  if (pos == len)
    return 1;

  if (str[pos] == 'M')
  {
    pos++;
    minutes = result;

    if (pos < len && (err = parse_s_string(str, len, pos, seconds, frac_seconds)) != 0)
      return err;
  }
  else if (str[pos] == 'S')
  {
    pos++;
    seconds = result;
  }
  else if (str[pos] == '.')
  {
    pos++;
    seconds = result;

    double temp_frac_seconds = 0;
    if ((err = parse_frac(str, len, pos, temp_frac_seconds)) != 0)
      return err;

    if (pos == len || str[pos] != 'S')
      return 1;

    pos++;
    frac_seconds = round(temp_frac_seconds * Duration::FRAC_SECONDS_UPPER_LIMIT);
  }

  return 0;
}


/******************************************************************************
  parse a 'nHnMnS' string, with fractional seconds
*******************************************************************************/
static int parse_hms_string(
    const char* str,
    ascii::size_type len,
    ascii::size_type& pos,
    long& hours,
    long& minutes,
    long& seconds,
    long& frac_seconds)
{
  long result;
  int err;

  if ((err = parse_long(str, len, pos, result)) != 0)
    return err;

  if (pos == len)
    return 1;

  if (str[pos] == 'H')
  {
    pos++;

    hours = result;

    if (pos < len && (err = parse_ms_string(str, len, pos, minutes, seconds, frac_seconds)) != 0)
      return err;
  }
  else if (str[pos] == 'M')
  {
    pos++;

    minutes = result;

    if (pos < len && (err = parse_s_string(str, len, pos, seconds, frac_seconds)) != 0)
      return err;
  }
  else if (str[pos] == 'S')
  {
    pos++;
    seconds = result;
  }
  else if (str[pos] == '.')
  {
    pos++;
    seconds = result;

    double temp_frac_seconds;
    if ((err = parse_frac(str, len, pos, temp_frac_seconds)) != 0)
      return err;

    if (pos == len || str[pos] != 'S')
      return 1;

    pos++;
    frac_seconds = round(temp_frac_seconds * Duration::FRAC_SECONDS_UPPER_LIMIT);
  }

  return 0;
}


int Duration::parseDuration(const char* str, ascii::size_type len, Duration& d)
{
  zstring::size_type ym_pos;
  zstring::size_type t_pos;
  int err;

  zstring_b wrap;
  wrap.wrap_memory(const_cast<char*>(str), len);

  t_pos = wrap.find('T');
  ym_pos = wrap.find('M');

  if (ym_pos == zstring::npos || t_pos < ym_pos)
    ym_pos = wrap.find('Y');
  else if (t_pos != zstring::npos && t_pos < ym_pos)
    ym_pos = zstring::npos;

  // Check month or year
  if (ym_pos != zstring::npos)
  {
    if ((err = parseYearMonthDuration(str, (ulong)ym_pos+1, d)) != 0)
      return err;

    ascii::size_type pos = ym_pos+1;
    ascii::skip_space(str, len, &pos);

    if (pos > ym_pos + 1 && pos != len)
      return 1;

    if (pos < len)
    {
      Duration dtd;

      if ((err = parseDayTimeDuration(str + pos, len - ym_pos -1, dtd, true)) != 0)
        return err;

      for (int i = DAY_DATA; i <= FRACSECONDS_DATA; ++i)
        d.data[i] = dtd.data[i];
    }
  }
  else
  {
    // No month or year -- parse DayTime
    if ((err = parseDayTimeDuration(str, len, d)) != 0)
      return err;
  }

  d.facet = DURATION_FACET;
  return 0;
}


int Duration::parseYearMonthDuration(const char* str, ascii::size_type len, Duration& d)
{
  bool negative = false;
  ascii::size_type pos = 0;
  long result;
  long months = 0;
  int err;

  ascii::skip_space(str, len, &pos);

  if (pos == len)
    return 1;

  if (str[pos] == '-')
  {
    negative = true;
    pos++;
  }

  if (pos == len || str[pos++] != 'P')
    return 1;

  if ((err = parse_long(str, len, pos, result)) != 0)
    return err;

  if (pos == len)
    return 1;

  if (str[pos] == 'Y')
  {
    pos++;
    months = result * 12;

    if (pos < len)
    {
      if ((err = parse_long(str, len, pos, result)) != 0)
        return err;

      if (str[pos++] != 'M')
        return 1;

      months += result;
    }
  }
  else if (str[pos++] == 'M')
  {
    months = result;
  }
  else
  {
    return 1;
  }

  ascii::skip_space(str, len, &pos);

  if (len != pos)
    return 1;

  d = Duration(YEARMONTHDURATION_FACET, negative, 0, months, 0, 0, 0, 0);

  return 0;
}


/*******************************************************************************
  Parse a 'PnDTnHnMnS' dateTime duration
********************************************************************************/
int Duration::parseDayTimeDuration(
    const char* str,
    ascii::size_type len,
    Duration& d,
    bool dont_check_letter_p)
{
  bool negative = false;
  ascii::size_type pos = 0;
  long days = 0, hours = 0, minutes = 0, seconds = 0, frac_seconds = 0;
  int err;

  ascii::skip_space(str, len, &pos);

  if (pos == len)
    return 1;

  if (str[pos] == '-')
  {
    negative = 1;
    pos++;
  }

  if (!dont_check_letter_p && (pos == len || str[pos++] != 'P'))
    return 1;

  if (pos == len)
    return 1;

  // It must be either 'T' or 'nD'
  if (str[pos] != 'T')
  {
    long result = 0;
    if ((err = parse_long(str, len, pos, result)) != 0)
      return err;

    days = result;

    if (pos == len || str[pos++] != 'D')
      return 1;
  }

  // Either 'T', or whitespace, or end

  if (pos < len && str[pos] == 'T')
  {
    pos++;

    if ((err = parse_hms_string(str, len, pos, hours, minutes, seconds, frac_seconds)) != 0)
      return err;
  }

  ascii::skip_space(str, len, &pos);

  if (len != pos)
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

  d = Duration(DAYTIMEDURATION_FACET,
               negative, 0, 0, days,
               hours, minutes, seconds, frac_seconds);
  return 0;
}


int Duration::fromTimezone(const TimeZone& t, Duration& d)
{
  if( t )
  {
    d = Duration(DAYTIMEDURATION_FACET,
                 t < 0,
                 0, 0, 0,
                 t.getHours(),
                 t.getMinutes(),
                 0, 0 );
    return 0;
  }
  else
  {
    return 1;
  }
}



Duration::Duration()
{
  facet = DURATION_FACET;
  is_negative = false;

  for (int i = 0; i <= FRACSECONDS_DATA; ++i)
    data[i] = 0;
}


Duration::Duration(FACET_TYPE facet_type) : facet(facet_type)
{
  is_negative = false;

  for (int i = 0; i <= FRACSECONDS_DATA; ++i)
    data[i] = 0;
}


Duration::Duration(
    FACET_TYPE facet_type,
    long years,
    long months,
    long days,
    long hours,
    long minutes,
    double seconds)
{
  seconds = std::fabs(seconds);

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
  data[YEAR_DATA] = std::abs(years);
  data[MONTH_DATA] = std::abs(months);
  data[DAY_DATA] = std::abs(days);
  data[HOUR_DATA] = std::abs(hours);
  data[MINUTE_DATA] = std::abs(minutes);
  data[SECONDS_DATA] = static_cast<long>(std::floor(seconds));
  data[FRACSECONDS_DATA] = round(frac(seconds) * FRAC_SECONDS_UPPER_LIMIT);

  normalize();
}


Duration::Duration(
    FACET_TYPE facet_type,
    bool negative,
    long years,
    long months,
    long days,
    long hours,
    long minutes,
    double seconds)
{
  seconds = std::fabs(seconds);

  facet = facet_type;
  is_negative = negative;
  data[YEAR_DATA] = std::abs(years);
  data[MONTH_DATA] = std::abs(months);
  data[DAY_DATA] = std::abs(days);
  data[HOUR_DATA] = std::abs(hours);
  data[MINUTE_DATA] = std::abs(minutes);
  data[SECONDS_DATA] = static_cast<long>(std::floor(seconds));
  data[FRACSECONDS_DATA] = round(frac(seconds) * FRAC_SECONDS_UPPER_LIMIT);

  normalize();
}


Duration::Duration(
    FACET_TYPE facet_type,
    bool negative, long years, long months, long days,
    long hours, long minutes, int seconds, int frac_seconds)
{
  facet = facet_type;
  is_negative = negative;
  data[YEAR_DATA] = std::abs(years);
  data[MONTH_DATA] = std::abs(months);
  data[DAY_DATA] = std::abs(days);
  data[HOUR_DATA] = std::abs(hours);
  data[MINUTE_DATA] = std::abs(minutes);
  data[SECONDS_DATA] = std::abs(seconds);
  data[FRACSECONDS_DATA] = std::abs(frac_seconds);

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


xs_decimal Duration::getSeconds() const
{
  return  xs_decimal(is_negative? -1 : 1)
        * (xs_decimal(data[SECONDS_DATA])
          + xs_decimal(data[FRACSECONDS_DATA])
          / xs_decimal(FRAC_SECONDS_UPPER_LIMIT)
          );
}


long Duration::getFractionalSeconds() const
{
  return (is_negative? -1 : 1) * data[FRACSECONDS_DATA];
}


long Duration::getIntSeconds() const
{
  return (is_negative? -1 : 1) * data[SECONDS_DATA];
}


xs_double Duration::getTotalSeconds() const
{
  return (is_negative ?
      numeric_consts<xs_double>::neg_one() : numeric_consts<xs_double>::one())
      * ((((((((xs_double(data[YEAR_DATA]) * 12
      + xs_double(data[MONTH_DATA])) * 30)
      + xs_double(data[DAY_DATA])) * 24)
      + xs_double(data[HOUR_DATA])) * 60)
      + xs_double(data[MINUTE_DATA])) * 60)
      + xs_double(data[SECONDS_DATA])
      + xs_double(double(data[FRACSECONDS_DATA]) / FRAC_SECONDS_UPPER_LIMIT);
}


long Duration::getTotalMilliseconds() const
{
  return (is_negative? -1 : 1)
      * (((((((((data[YEAR_DATA] * 12
        + data[MONTH_DATA]) * 30)
        + data[DAY_DATA]) * 24)
        + data[HOUR_DATA]) * 60)
        + data[MINUTE_DATA]) * 60)
        + data[SECONDS_DATA])
      * 1000
      + round(data[FRACSECONDS_DATA]/(FRAC_SECONDS_UPPER_LIMIT / 1000.0));
}


bool Duration::operator==(const Duration& d) const
{
  if (is_negative != d.is_negative)
    return false;

  for (int i=0; i<=FRACSECONDS_DATA; i++)
    if (data[i] != d.data[i])
      return false;

  return true;
}


bool Duration::isZero() const
{
  for (int i=0; i<=FRACSECONDS_DATA; i++)
    if (data[i] != 0)
      return false;

  return true;
}


int Duration::compare(const Duration& d, bool ignore_sign) const
{
  for (int i=0; i<=FRACSECONDS_DATA; i++)
  {
    if ( (is_negative && !ignore_sign ? -1 : 1) * data[i] >
         (d.is_negative && !ignore_sign ? -1 : 1) * d.data[i])
      return 1;

    else if ((is_negative && !ignore_sign ? -1 : 1) * data[i] <
             (d.is_negative && !ignore_sign? -1 : 1) * d.data[i])
      return -1;
  }
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
  for (int i = start_data; i >= end_data; i--)
  {
    if (i == FRACSECONDS_DATA)
    {
      double sum = double(data[i] + (right_operand_sign? -1 : 1) * d.data[i]) / FRAC_SECONDS_UPPER_LIMIT;
      result->data[FRACSECONDS_DATA] = round(frac(sum)*FRAC_SECONDS_UPPER_LIMIT);
      carry = static_cast<long>(std::floor(sum));
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


#define TRY_XS_INT_CONVERT(target, value, xs_type)                         \
  {                                                                        \
    xs_type const res(value);                                              \
    try {                                                                  \
      target = to_xs_int(res);                                             \
    } catch (std::range_error const&) {                                    \
      throw XQUERY_EXCEPTION(err::FODT0002, ERROR_PARAMS(res.toString())); \
    }                                                                      \
  }

Duration* Duration::operator*(const xs_double& value) const
{
  xs_double result;
  xs_integer totalSeconds;
  int32_t years;
  int32_t seconds;
  int32_t frac_seconds;
  bool negative = false;

  if (facet == DURATION_FACET)
  {
    assert(0);
    return NULL;
  }

  try {
    result = getTotalSeconds() * value;
  } catch (std::range_error const&) {
    throw XQUERY_EXCEPTION(err::FODT0002);
  }

  if (result < 0)
  {
    negative = true;
    result = -result;
  }
  result = result.round(Integer(FRAC_SECONDS_UPPER_LIMIT));
  totalSeconds = result.floor();
  result = (result - result.floor()) * FRAC_SECONDS_UPPER_LIMIT;

  TRY_XS_INT_CONVERT(years, totalSeconds / seconds_per_year, xs_integer);
  TRY_XS_INT_CONVERT(seconds, totalSeconds % seconds_per_year, xs_integer);
  TRY_XS_INT_CONVERT(frac_seconds, result.round(), xs_double);

  Duration* d = new Duration(facet, negative, years, 0, 0, 0, 0, seconds, frac_seconds);
  return d;
}


Duration* Duration::operator/(const xs_double& value) const
{
  xs_double result;
  xs_integer totalSeconds;
  int32_t years;
  int32_t seconds;
  int32_t frac_seconds;
  bool negative = false;

  if (facet == DURATION_FACET)
  {
    assert(0);
    return NULL;
  }

  try {
    result = getTotalSeconds() / value;
  } catch (std::range_error const&) {
    throw XQUERY_EXCEPTION(err::FODT0002);
  }

  if (result < 0)
  {
    negative = true;
    result = -result;
  }
  result = result.round(Integer(FRAC_SECONDS_UPPER_LIMIT));
  totalSeconds = result.floor();
  result = (result - result.floor()) * FRAC_SECONDS_UPPER_LIMIT;

  TRY_XS_INT_CONVERT(years, totalSeconds / seconds_per_year, xs_integer);
  TRY_XS_INT_CONVERT(seconds, totalSeconds % seconds_per_year, xs_integer);
  TRY_XS_INT_CONVERT(frac_seconds, result.round(), xs_double);

  Duration* d = new Duration(facet, negative, years, 0, 0, 0, 0, seconds, frac_seconds);
  return d;
}

#undef TRY_XS_INT_CONVERT


Decimal Duration::operator/(const Duration& d) const
{ 
  if (d.isZero())
    XQUERY_EXCEPTION(err::FOAR0001);    
  return Decimal( getTotalSeconds() ) / Decimal( d.getTotalSeconds() );
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
      if ((data[i] >= max_value[i]/2 && !is_negative)
          ||
          (data[i] > max_value[i]/2 && is_negative))
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


zstring Duration::toString() const
{
  zstring result;

  if (isZero())
  {
    if (facet == YEARMONTHDURATION_FACET)
      return "P0M";
    else
      return "PT0S";
  }

  if (is_negative)
  {
    result.append("-", 1);
    result.append("P", 1);
  }
  else
  {
    result.append("P", 1);
  }

  if (facet != DAYTIMEDURATION_FACET)
  {
    ascii::itoa_buf_type buf;

    if (data[YEAR_DATA] != 0)
    {
      result += ascii::itoa(data[YEAR_DATA], buf);
      result.append("Y", 1);
    }

    if (data[MONTH_DATA] != 0)
    {
      result += ascii::itoa(data[MONTH_DATA], buf);
      result.append("M", 1);
    }
  }

  if (facet != YEARMONTHDURATION_FACET)
  {
    ascii::itoa_buf_type buf;

    if (data[DAY_DATA] != 0)
    {
      result += ascii::itoa(data[DAY_DATA], buf);
      result.append("D", 1);
    }

    for (int i=HOUR_DATA; i<=FRACSECONDS_DATA; i++)
    {
      if (data[i] != 0)
      {
        result.append("T", 1);
        break;
      }
    }

    if (data[HOUR_DATA] != 0)
    {
      result += ascii::itoa(data[HOUR_DATA], buf);
      result.append("H", 1);
    }

    if (data[MINUTE_DATA] != 0)
    {
      result += ascii::itoa(data[MINUTE_DATA], buf);
      result.append("M", 1);
    }

    if (data[SECONDS_DATA] != 0 || data[FRACSECONDS_DATA] != 0)
    {
      result += ascii::itoa(data[SECONDS_DATA], buf);

      if ( data[FRACSECONDS_DATA] != 0 )
      {
        int frac_seconds = data[FRACSECONDS_DATA];
        result.append(".", 1);

        // print leading 0s, if any
        int temp = FRAC_SECONDS_UPPER_LIMIT / 10;
        while (temp > frac_seconds && temp > 0)
        {
          result.append("0", 1);
          temp /= 10;
        }

        // strip trailing 0s, if any
        while (frac_seconds%10 == 0 && frac_seconds > 0)
          frac_seconds = frac_seconds / 10;

        result.append(ztd::to_string(frac_seconds));
      }

      result.append("S", 1);
    }
  }

  return result;
}


uint32_t Duration::hash() const
{
  uint32_t hval = 0;

  hval = hashfun::h32<int>((int)is_negative, hval);

  for (int i = 0; i <= FRACSECONDS_DATA; ++i)
    hval = hashfun::h32<long>(data[i], hval);

  return hval;
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
