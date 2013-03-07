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

#include <sstream>
#include <string>
#include <iomanip>

#include "util/ascii_util.h"
#include "util/time_util.h"
#include "zorbatypes/datetime/parse.h"

namespace zorba
{


/*******************************************************************************
  Parses an integer number. Will parse digits starting with the given position
  stopping at first non-digit character and updating the position. If min_digits
  and/or max_digits values are greater than 0, the number of parsed characters
  must obey these conditions, or the function will return an error.

  @param str The source string to parse
  @param len the length of the input string
  @param position The position to start parsing from
  @param result Contains the result of the parsing
  @param min_digits Minimum number of digits
  @param max_digits Maximum number od digits
  @param delta Where to start parsing, the first digit being pointed by position+delta
  @return Returns 0 on success and a positive value on an error, as follows:
          1 - nonspecified error
          2 - integer overflow
********************************************************************************/
int parse_long(
    const char* str,
    size_t len,
    size_t& position,
    long& result,
    long min_digits,
    long max_digits,
    size_t delta)
{
  long digits = 0;

  if (position + delta >= len)
    return 1;

  if (str[position+delta] < '0' || str[position+delta] > '9')
    return 1;

  result = 0;

  while ( position + delta < len && ascii::is_digit( str[position+delta] ) )
  {
    result = 10 * result + str[position + delta] - '0';
    position++;
    digits++;

    if (result < 0) // we've had an overflow
      return 2;
  }

  if (min_digits >= 0 && digits < min_digits)
    return 1;

  if (max_digits >= 0 && digits > max_digits)
    return 1;

  return 0;
}



int get_last_day( int year, int month ) {
  --month;
  year += quotient<int>( month, 12 );
  month = modulo<int>( month, 12 );
  return time::days_in_month( month, year );
}

int leap_years_count(int year)
{
  year--;
  return year/4 - year/100 + year/400;
}


int parse_frac( char const *str, size_t len, size_t &pos, double &result )
{
  if (pos >= len)
    return 1;

  if ( !ascii::is_digit( str[pos] ) )
    return 1;

  double temp = 0.1;
  result = 0;
  while ( pos < len && ascii::is_digit( str[pos] ) ) {
    result += temp * (str[pos] - '0');
    temp /= 10;
    ++pos;
  }

  return 0;
}

std::string zero_pad(int value, unsigned int min_digits)
{
  std::ostringstream oss;
  oss << std::setfill('0') << std::setw( min_digits ) << value;
  return oss.str();
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
