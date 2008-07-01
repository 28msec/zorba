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
#include "zorbatypes/datetime/parse.h"
#include <string>

namespace zorba
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
void skip_whitespace(std::string& s, unsigned int& position)
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

bool is_digit(char ch)
{
  return (ch >= '0' && ch <= '9');
}

// checks if a number of count chars, starting with position, are digits
bool are_digits(std::string& s, unsigned int& position, int count)
{
  for(unsigned int i=position; i<position+count; i++)
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

int days_since_year_start(int year, int month, int day)
{
  static const int days[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
  
  if (is_leap_year(year) && month >= 3)
    day++;
  
  return days[month-1] + day-1;
}


} // namespace zorba
