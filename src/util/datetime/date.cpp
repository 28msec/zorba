/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include "util/datetime/date.h"
#include "util/datetime/timezone.h"
#include "util/datetime/parse.h"
#include "errors/error_factory.h"

#include <iostream>
using namespace std;

namespace xqp
{
    
Date_t Date::parse_string(xqpString s)
{
  Date_t d_t;
  unsigned int position = 0;
  bool is_negative = false;
  std::string ss = *s.getStore();

  // date of form: '-'? yyyy '-' mm '-' dd zzzzzz?

  skip_whitespace(ss, position);
  if (position == ss.size())
    ZORBA_ERROR_ALERT(ZorbaError::FORG0001, NULL);

  if (ss[position] == '-')
  {
    is_negative = 1;
    position++;
  }

  if (ss.size()-position > 10) // we might have a timezone
  {
    d_t = new Date(boost::gregorian::from_simple_string(ss.substr(position, 10)));
    d_t->the_time_zone = *TimeZone::parse_string(ss.substr(position+10, ss.size() - position - 10));
  }
  else
    d_t = new Date(boost::gregorian::from_simple_string(ss));

  // TODO: date can be negative

  return d_t;
}

Date& Date::operator=(const Date_t& d_t)
{
  the_date = d_t->the_date;
  return *this;
}

bool Date::operator<(const Date& d) const
{
  return (the_date < d.the_date);
}

bool Date::operator==(const Date& d) const
{
  return (the_date == d.the_date);
}

xqpString Date::toString() const
{
  xqpString result = boost::gregorian::to_iso_extended_string(the_date);
  result += the_time_zone.toString();
  // TODO:
  return result;
}

const boost::gregorian::date& Date::get_date() const
{
  return the_date;
}

int Date::compare(const Date& d) const
{
  // TODO: handle timezone
  if (operator<(d))
    return -1;
  else if (operator==(d))
    return 0;
  else
    return 1;
}

} // namespace xqp
