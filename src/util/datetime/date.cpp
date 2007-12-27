/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include "util/datetime/date.h"
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

Date_t Date::parse_string(xqpString s)
{
  Date_t d_t;

  d_t = new Date(boost::gregorian::from_simple_string(s));
  
  return d_t;
}

Date& Date::operator=(const Date_t& d_t)
{
  the_date = d_t->the_date;
  return *this;
}

bool Date::operator<(const Date& d)
{
  return (the_date < d.the_date);

}

bool Date::operator==(const Date& d)
{
  return (the_date == d.the_date);
}

} // namespace xqp
