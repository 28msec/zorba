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
#pragma once
#ifndef ZORBA_DATETIME_UTILS_H
#define ZORBA_DATETIME_UTILS_H

#include <cmath>
#include <string>
#include <sys/types.h>

#include <zorba/config.h>

#include "zorbatypes/numconversions.h"

#include "util/string_util.h"

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
    long min_digits = -1,
    long max_digits = -1,
    size_t delta = 0);


/*******************************************************************************
  Parses the fractional part of double number, not including the decimal dot.

  @param s
  @param position
  @param result
  @return Returns 0 on success and a positive value on an error
********************************************************************************/
int parse_frac(
    const char* str,
    size_t len,
    size_t& position,
    double& result);

std::string zero_pad(int value, unsigned int min_digits = 0);


/**
 * Returns the number of leap years between 1 AD and the given year.
 * @param year
 * @return
 */
int leap_years_count(int year);


template <typename T> inline
T quotient(T a, T b)
{
  return a >= 0 ? a / b : (a + 1) / b - 1;
}


template <typename T> inline
T modulo(T a, T b)
{
  a %= b;
  if (a<0)
    a += b;
  return a;
}


/**
 * Rounds to the nearest integer
 */
inline int round(double value)
{
  return int( value >= 0 ? value + 0.5 : value - 0.5 );
}


inline double frac(double value)
{
  return value - std::floor(value);
}


// Returns the last day of the given year and month. E.g. for 1980 and 2 it
// will return 29. Returns 0 on an error
int get_last_day(int year, int month);

} // namespace zorba

#endif /* ZORBA_DATETIME_UTILS_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
