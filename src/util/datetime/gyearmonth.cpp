/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include "util/datetime/gyearmonth.h"
#include "util/datetime/timezone.h"
#include "util/datetime/parse.h"
#include "errors/error_factory.h"

#include <iostream>
using namespace std;

namespace xqp
{
    
gYearMonth_t gYearMonth::parse_string(xqpString s)
{
  gYearMonth_t d_t;
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
    d_t = new gYearMonth(boost::gregorian::from_simple_string(ss.substr(position, 10)));
    d_t->the_time_zone = *TimeZone::parse_string(ss.substr(position+10, ss.size() - position - 10));
  }
  else
    d_t = new gYearMonth(boost::gregorian::from_simple_string(ss));

  // TODO: date can be negative

  return d_t;
}

gYearMonth& gYearMonth::operator=(const gYearMonth_t& gym_t)
{
  the_gyear_month = gym_t->the_gyear_month;
  return *this;
}

bool gYearMonth::operator<(const gYearMonth& gym) const
{
  return (the_gyear_month < gym.the_gyear_month);
}

bool gYearMonth::operator==(const gYearMonth& gym) const
{
  return (the_gyear_month == gym.the_gyear_month);
}

xqpString gYearMonth::toString() const
{
  xqpString result = boost::gregorian::to_iso_extended_string(the_gyear_month);
  result += the_time_zone.toString();
  // TODO:
  return result;
}

/*
const boost::gregorian::date& gYearMonth::get_gYearMonth() const
{
  return the_gyear_month;
}
*/

int gYearMonth::compare(const gYearMonth& gym) const
{
  // TODO: handle timezone
  if (operator<(gym))
    return -1;
  else if (operator==(gym))
    return 0;
  else
    return 1;
}

} // namespace xqp
