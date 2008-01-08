/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include "util/datetime/date.h"
#include "util/datetime/parse.h"

namespace xqp
{
    
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
  // TODO:
  return NULL;
}

const boost::gregorian::date& Date::get_date() const
{
  return the_date;
}

int Date::compare(const Date& d) const
{
  if (operator<(d))
    return -1;
  else if (operator==(d))
    return 0;
  else
    return 1;
}

} // namespace xqp
