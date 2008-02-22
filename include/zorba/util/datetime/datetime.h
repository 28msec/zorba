/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#ifndef XQP_UTIL_DATETIME_H
#define XQP_UTIL_DATETIME_H

#include <boost/date_time/posix_time/posix_time.hpp>
#include "util/rchandle.h"
#include "util/datetime/timezone.h"

namespace xqp
{
class xqpString;
class Duration;

class Date;
typedef rchandle<Date> Date_t;
  
class Time;
typedef rchandle<Time> Time_t;

class DateTime;
typedef rchandle<DateTime> DateTime_t;


class DateTime : public SimpleRCObject
{
public:
  DateTime(bool negative, boost::posix_time::ptime t) : is_negative(negative), the_date_time(t) { };
  DateTime(const Date_t& d_t, const Time_t& t_t);
  
  virtual ~DateTime() { };

  /**
   *  Returns 0 on success
   */
  static int parse_string(const xqpString& s, DateTime_t& dt_t);
  
  bool operator<(const DateTime& dt) const;
  bool operator==(const DateTime& dt) const;
  int compare(const DateTime& dt) const;

  xqpString toString() const;

  int getYear() const;
  int getMonth() const;
  int getDay() const;
  int getHours() const;
  int getMinutes() const;
  double getSeconds() const;
  TimeZone getTimezone() const;

protected:
  DateTime& operator=(const DateTime_t& dt_t);

  bool is_negative;
  boost::posix_time::ptime the_date_time;
  TimeZone the_time_zone;  
};

DateTime_t operator+(const DateTime& dt, const Duration& d);
DateTime_t operator-(const DateTime& dt, const Duration& d);

} // namespace xqp

#endif
