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
#ifndef XQP_PRASE_H
#define XQP_PRASE_H

#include <string>
#include "zorbatypes/numconversions.h"

namespace zorba
{

void skip_whitespace(std::string& s, unsigned int& position);


/**
 * Parses an integer number. Will parse digits starting with the given position stopping
 * at first non-digit character and updating the position. If min_digits and/or max_digits values
 * are greater than 0, the number of parsed characters must obey these conditions, or the function
 * will return an error.
 *
 * @param s The source string to parse
 * @param position The position to start parsing from
 * @param result Contains the result of the parsing
 * @param min_digits Minimum number of digits
 * @param max_digits Maximum number od digits
 * @return Returns 1 on an error, 0 on success
 */
template <typename T>
int parse_int(
    std::string& s,
    unsigned int& position,
    T& result,
    int min_digits = -1,
    int max_digits = -1)
{
  int digits = 0;
  if (s[position] < '0' || s[position] > '9')
    return 1;

  result = 0;
  while (s[position] >= '0' && s[position] <= '9' && position < s.size())
  {
    result = 10*result + s[position] - '0';
    position++;
    digits++;
  }

  if (min_digits >= 0 && digits < min_digits)
    return 1;

  if (max_digits >= 0 && digits > max_digits)
    return 1;

  return 0;
}


/**
 * Parses the fractional part of double number, not including the decimal dot.
 * @param s 
 * @param position 
 * @param result 
 * @return 
 */
inline double parse_frac(std::string& s, unsigned int& position, double& result)
{
  if (s[position] < '0' || s[position] > '9')
    return 1;

  double temp = 0.1;
  result = 0;
  while (s[position] >= '0' && s[position] <= '9' && position < s.size())
  {
    result += temp * (s[position] - '0');
    temp /= 10;
    position++;
  }
  
  return 0;
}


inline std::string to_string(int value, int min_digits = 0)
{
  std::string zeros = "";
  std::string temp = NumConversions::longToStr(value);
  
  for (int i=temp.size(); i<min_digits; i++)
    zeros += '0';
       
  return zeros + temp;
}

/**
 * Returns the number of leap years between 1 AD and the given year.
 * @param year 
 * @return 
 */
int leap_years_count(int year);

/**
 * Returns the number of days passed from the start of the year. 1st of January will return 0. 
 * @param month 
 * @param day 
 * @return 
 */
int days_since_year_start(int year, int month, int day);
  
template <typename T>
T quotient(T a, T b)
{
  if (a >= 0)
    return a / b;
  else
    return (a+1) / b - 1;
}

template <typename T>
T modulo(T a, T b)
{
  a = a % b;
  if (a<0)
    a += b;

  return a;
}

template <typename T>
int floor(T a)
{
  if (a>=0)
    return (int)a;
  else if (a - ((int)a) == 0)
    return (int)a;
  else
    return (int)(a-1);
}

template <typename T>
T abs(T value)
{
  if (value < 0)
    return -value;
  else
    return value;
}

/**
 * Rounds to the nearest integer
 */
inline int round(double value)
{
  if (value >= 0)
    return int(value+0.5);
  else
    return int(value-0.5);
}

inline double frac(double value)
{
  return value - floor<double>(value);
}

bool is_digit(char ch);

bool are_digits(std::string& s, unsigned int& position, int count);
    
// Returns the last day of the given year and month. E.g. for 1980 and 2 it
// will return 29. Returns 0 on an error
int get_last_day(int year, int month);

} // namespace zorba

#endif
