/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#ifndef XQP_PRASE_H
#define XQP_PRASE_H

#include <string>

namespace xqp
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
int parse_int(std::string& s, unsigned int& position, T& result, int min_digits = -1, int max_digits = -1)
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

} // namespace xqp

#endif
