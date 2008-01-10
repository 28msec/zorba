/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#ifndef XQP_UTIL_DATETIME_H
#define XQP_UTIL_DATETIME_H

#include <boost/date_time/posix_time/posix_time.hpp>
#include "util/utf8/xqpString.h"
#include "util/rchandle.h"
#include "util/datetime/timezone.h"

namespace xqp
{

class Date;
typedef rchandle<Date> Date_t;
  
class Time;
typedef rchandle<Time> Time_t;

class DateTime;
typedef rchandle<DateTime> DateTime_t;

class DateTime : public rcobject
{
public:
  DateTime(boost::posix_time::ptime t) : the_date_time(t) { };
  DateTime(const Date_t& d_t, const Time_t& t_t);
  
  virtual ~DateTime() { };

  static DateTime_t parse_string(xqpString s);
  
  bool operator<(const DateTime& t) const;
  bool operator==(const DateTime& t) const;
  int compare(const DateTime& t) const;

  xqpString toString() const;

protected:
  DateTime& operator=(const DateTime_t& t_t);
  
  boost::posix_time::ptime the_date_time;
  TimeZone the_time_zone;  
};

} // namespace xqp

#endif
