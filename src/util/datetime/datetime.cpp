/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include "util/datetime/datetime.h"
#include "util/datetime/parse.h"
#include "util/datetime/time.h"
#include "util/datetime/date.h"

namespace xqp
{
    
DateTime::DateTime(const Date_t& d_t, const Time_t& t_t)
{
  the_date_time = boost::posix_time::ptime(d_t->get_date(), t_t->get_time_duration());
}

DateTime_t DateTime::parse_string(xqpString s)
{
  DateTime_t t_t;
  xqpString temp = s.translate("T", " "); // replace "T" with " ", which is what boost expects

  t_t = new DateTime(boost::posix_time::time_from_string(*temp.getStore()));

  return t_t;
}

DateTime& DateTime::operator=(const DateTime_t& dt_t)
{
  the_date_time = dt_t->the_date_time;
  return *this;
}

bool DateTime::operator<(const DateTime& t) const
{
  return (the_date_time < t.the_date_time);
}

bool DateTime::operator==(const DateTime& t) const
{
  return (the_date_time == t.the_date_time);
}

xqpString DateTime::toString() const
{
  xqpString result = boost::posix_time::to_iso_extended_string(the_date_time);
  // TODO:
  return result;
}

int DateTime::compare(const DateTime& t) const
{
  if (operator<(t))
    return -1;
  else if (operator==(t))
    return 0;
  else
    return 1;
}

} // namespace xqp
