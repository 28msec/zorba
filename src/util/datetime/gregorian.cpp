/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include <exception>
#include "util/datetime/gregorian.h"
#include "util/datetime/timezone.h"
#include "util/datetime/parse.h"

#define RETURN_FALSE_ON_EXCEPTION(sequence)     \
  try                                           \
  {                                             \
    sequence;                                   \
  }                                             \
  catch (std::exception& ex)                    \
  {                                             \
    return false;                               \
  }


#include <iostream>
using namespace std;

namespace xqp
{

/**
 * GYearMonth
 *
 */
bool GYearMonth::parse_string(const xqpString& s, GYearMonth_t& gym_t)
{
  unsigned int position = 0;
  bool is_negative = false;
  std::string ss = *s.getStore();
  TimeZone_t tz_t;

  // GYearMonth of form: '-'? yyyy '-' mm zzzzzz?

  skip_whitespace(ss, position);
  if (position == ss.size())
    return false;
    
  if (ss[position] == '-')
  {
    is_negative = 1;
    position++;
  }

  if (ss.size()-position > 7) // we might have a timezone
  {
    RETURN_FALSE_ON_EXCEPTION( gym_t = new GYearMonth(boost::gregorian::from_simple_string(ss.substr(position, 7) + "-01")); );
    if (TimeZone::parse_string(ss.substr(position+7, ss.size() - position - 7), tz_t))
      gym_t->the_time_zone = *tz_t;
    else
      return false;
  }
  else
  {
    RETURN_FALSE_ON_EXCEPTION( gym_t = new GYearMonth(boost::gregorian::from_simple_string(ss.substr(position) + "-01")); );
  }

  // TODO: they day should not be "01" but the last day of the given month
  // TODO: can be negative

  return true;
}

GYearMonth& GYearMonth::operator=(const GYearMonth_t& gym_t)
{
  the_gyear_month = gym_t->the_gyear_month;
  return *this;
}

bool GYearMonth::operator<(const GYearMonth& gym) const
{
  return (the_gyear_month < gym.the_gyear_month);
}

bool GYearMonth::operator==(const GYearMonth& gym) const
{
  return (the_gyear_month == gym.the_gyear_month);
}

xqpString GYearMonth::toString() const
{
  xqpString result = boost::gregorian::to_iso_extended_string(the_gyear_month).substr(0, 7);
  result += the_time_zone.toString();
  // TODO:
  return result;
}

int GYearMonth::compare(const GYearMonth& gym) const
{
  // TODO: handle timezone
  if (operator<(gym))
    return -1;
  else if (operator==(gym))
    return 0;
  else
    return 1;
}


/**
 * GYear
 *
 */
bool GYear::parse_string(const xqpString& s, GYear_t& gy_t)
{
  unsigned int position = 0;
  bool is_negative = false;
  std::string ss = *s.getStore();
  TimeZone_t tz_t;

  // GYear of form: '-'? yyyy zzzzzz?

  skip_whitespace(ss, position);
  if (position == ss.size())
    return false;

  if (ss[position] == '-')
  {
    is_negative = 1;
    position++;
  }

  if (ss.size()-position > 4) // we might have a timezone
  {
    RETURN_FALSE_ON_EXCEPTION( gy_t = new GYear(boost::gregorian::from_simple_string(ss.substr(position, 4) + "-01-01")); );

    if (TimeZone::parse_string(ss.substr(position+4), tz_t))
      gy_t->the_time_zone = *tz_t;
    else
      return false;
  }
  else
  {
    RETURN_FALSE_ON_EXCEPTION( gy_t = new GYear(boost::gregorian::from_simple_string(ss.substr(position) + "-01-01")); );
  }

  // TODO: check what month/day should be filled in
  // TODO: can be negative

  return true;
}

GYear& GYear::operator=(const GYear_t& gy_t)
{
  the_gyear = gy_t->the_gyear;
  return *this;
}

bool GYear::operator<(const GYear& gy) const
{
  return (the_gyear < gy.the_gyear);
}

bool GYear::operator==(const GYear& gy) const
{
  return (the_gyear == gy.the_gyear);
}

xqpString GYear::toString() const
{
  xqpString result = boost::gregorian::to_iso_extended_string(the_gyear).substr(0, 4);
  result += the_time_zone.toString();
  // TODO:
  return result;
}

int GYear::compare(const GYear& gy) const
{
  // TODO: handle timezone
  if (operator<(gy))
    return -1;
  else if (operator==(gy))
    return 0;
  else
    return 1;
}


/**
 * GMonthDay
 *
 */
bool GMonthDay::parse_string(const xqpString& s, GMonthDay_t& gmd_t)
{
  unsigned int position = 0;
  std::string ss = *s.getStore();
  TimeZone_t tz_t;

  // GMonthDay of form: --MM-DD zzzzzz?
  // preceding - is not allowed.

  skip_whitespace(ss, position);

  if (position == ss.size() || ss[position++] != '-')
    return false;
  if (position == ss.size())
    return false;

  if (ss.size()-position > 6) // we might have a timezone
  {
    RETURN_FALSE_ON_EXCEPTION( gmd_t = new GMonthDay(boost::gregorian::from_simple_string("1972" + ss.substr(position, 6))); );
    if (TimeZone::parse_string(ss.substr(position+6, ss.size() - position - 6), tz_t))
      gmd_t->the_time_zone = *tz_t;
    else
      return false;
  }
  else
  {
    RETURN_FALSE_ON_EXCEPTION(
      gmd_t = new GMonthDay(boost::gregorian::from_simple_string("1972" + ss.substr(position))); );
  }

  // TODO: they day and month should not be "01-01" but the last day of the given month

  return true;
}

GMonthDay& GMonthDay::operator=(const GMonthDay_t& gmd_t)
{
  the_gmonth_day = gmd_t->the_gmonth_day;
  return *this;
}

bool GMonthDay::operator<(const GMonthDay& gmd) const
{
  return (the_gmonth_day < gmd.the_gmonth_day);
}

bool GMonthDay::operator==(const GMonthDay& gmd) const
{
  return (the_gmonth_day == gmd.the_gmonth_day);
}

xqpString GMonthDay::toString() const
{
  xqpString result = "-" + boost::gregorian::to_iso_extended_string(the_gmonth_day).substr(4, 6);
  result += the_time_zone.toString();
  // TODO:
  return result;
}

int GMonthDay::compare(const GMonthDay& gmd) const
{
  // TODO: handle timezone
  if (operator<(gmd))
    return -1;
  else if (operator==(gmd))
    return 0;
  else
    return 1;
}


/**
 * GDay
 *
 */
bool GDay::parse_string(const xqpString& s, GDay_t& gd_t)
{
  unsigned int position = 0;
  std::string ss = *s.getStore();
  TimeZone_t tz_t;

  // GDay of form: ---DD zzzzzz?
  // preceding - is not allowed.

  skip_whitespace(ss, position);

  if (position == ss.size() || ss[position++] != '-')
    return false;
  if (position == ss.size() || ss[position++] != '-')
    return false;
  if (position == ss.size())
    return false;

  if (ss.size()-position > 3) // we might have a timezone
  {
    RETURN_FALSE_ON_EXCEPTION( gd_t = new GDay(boost::gregorian::from_simple_string("1972-12" + ss.substr(position, 3))); );
    if (TimeZone::parse_string(ss.substr(position+3, ss.size() - position - 3), tz_t))
      gd_t->the_time_zone = *tz_t;
    else
      return false;
  }
  else
  {
    RETURN_FALSE_ON_EXCEPTION( gd_t = new GDay(boost::gregorian::from_simple_string("1972-12" + ss.substr(position))); );
  }

  // TODO: they day and month should not be "01-01" but the last day of the given month
  
  return true;
}

GDay& GDay::operator=(const GDay_t& gd_t)
{
  the_gday = gd_t->the_gday;
  return *this;
}

bool GDay::operator<(const GDay& gd) const
{
  return (the_gday < gd.the_gday);
}

bool GDay::operator==(const GDay& gd) const
{
  return (the_gday == gd.the_gday);
}

xqpString GDay::toString() const
{
  xqpString result = "--" + boost::gregorian::to_iso_extended_string(the_gday).substr(7, 3);
  result += the_time_zone.toString();
  // TODO:
  return result;
}

int GDay::compare(const GDay& gd) const
{
  // TODO: handle timezone
  if (operator<(gd))
    return -1;
  else if (operator==(gd))
    return 0;
  else
    return 1;
}


/**
 * GMonth
 *
 */
bool GMonth::parse_string(const xqpString& s, GMonth_t& gm_t )
{
  unsigned int position = 0;
  std::string ss = *s.getStore();
  TimeZone_t tz_t;

  // GMonth of form: --MM zzzzzz?
  // preceding - is not allowed.

  skip_whitespace(ss, position);

  if (position == ss.size() || ss[position++] != '-')
    return false;
  if (position == ss.size())
    return false;

  if (ss.size()-position > 3) // we might have a timezone
  {
    RETURN_FALSE_ON_EXCEPTION( gm_t = new GMonth(boost::gregorian::from_simple_string("1972" + ss.substr(position, 3) + "-01")); );
    if (TimeZone::parse_string(ss.substr(position+3, ss.size() - position - 3), tz_t))
      gm_t->the_time_zone = *tz_t;
    else
      return false;
  }
  else
  {
    RETURN_FALSE_ON_EXCEPTION( gm_t = new GMonth(boost::gregorian::from_simple_string("1972" + ss.substr(position) + "-01")); );
  }

  // TODO: they day and month should not be "01-01" but the last day of the given month
  
  return true;
}

GMonth& GMonth::operator=(const GMonth_t& gm_t)
{
  the_gmonth = gm_t->the_gmonth;
  return *this;
}

bool GMonth::operator<(const GMonth& gm) const
{
  return (the_gmonth < gm.the_gmonth);
}

bool GMonth::operator==(const GMonth& gm) const
{
  return (the_gmonth == gm.the_gmonth);
}

xqpString GMonth::toString() const
{
  xqpString result = "-" + boost::gregorian::to_iso_extended_string(the_gmonth).substr(4, 3);
  result += the_time_zone.toString();
  // TODO:
  return result;
}

int GMonth::compare(const GMonth& gm) const
{
  // TODO: handle timezone
  if (operator<(gm))
    return -1;
  else if (operator==(gm))
    return 0;
  else
    return 1;
}


} // namespace xqp
