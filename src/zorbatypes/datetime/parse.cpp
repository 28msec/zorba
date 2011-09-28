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

#include "zorbatypes/datetime/parse.h"
#include <string>

namespace zorba
{


/*******************************************************************************
  Parses an integer number. Will parse digits starting with the given position
  stopping at first non-digit character and updating the position. If min_digits
  and/or max_digits values are greater than 0, the number of parsed characters
  must obey these conditions, or the function will return an error.

  @param str The source string to parse
  @param str_len the length of the input string
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
    ascii::size_type str_len,
    ascii::size_type& position,
    long& result,
    long min_digits,
    long max_digits,
    long delta)
{
  long digits = 0;

  if (position + delta >= str_len)
    return 1;

  if (str[position+delta] < '0' || str[position+delta] > '9')
    return 1;

  result = 0;

  while (position + delta < str_len &&
         str[position+delta] >= '0' && str[position+delta] <= '9')
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



bool is_digit(char ch)
{
  return (ch >= '0' && ch <= '9');
}


// checks if a number of count chars, starting with position, are digits
bool are_digits(std::string& s, unsigned int& position, int count)
{
  for(unsigned int i = position; i < position+count; i++)
    if (s[i] < '0' || s[i] > '9')
      return false;

  return true;
}


static bool is_leap_year(int year)
{
  if (((year%4 == 0) && (year%100 != 0))
        ||
        (year%400 == 0))
    return true;
  else
    return false;
}


int get_last_day(int year, int month)
{
  static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  year = year + quotient<int>(month-1, 12);
  month = modulo<int>(month-1, 12) + 1;

  if (is_leap_year(year) && month == 2)
    return 29;
  else
    return days[month-1];
}

int leap_years_count(int year)
{
  year--;
  return year/4 - year/100 + year/400;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
