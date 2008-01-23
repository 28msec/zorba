/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include "util/datetime/parse.h"
#include <string>

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

// Returns 1 if there is an error
int parse_int(std::string& s, unsigned int& position, long& result)
{
  if (s[position] < '0' || s[position] > '9')
    return 1;

  result = 0;
  while (s[position] >= '0' && s[position] <= '9' && position < s.size())
  {
    result = 10*result + s[position] - '0';
    position++;
  }

  return 0;
}

bool is_digit(char ch)
{
  return (ch >= '0' && ch <= '9');
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

  if (month<1 || month>12)
    return 0;

  if (is_leap_year(year) && month == 2)
    return 29;
  else
    return days[month-1];
}

} // namespace xqp
