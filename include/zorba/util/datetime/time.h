/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#ifndef XQP_TIME_H
#define XQP_TIME_H

#include <boost/date_time/posix_time/posix_time.hpp>
#include "util/rchandle.h"
#include "util/datetime/timezone.h"

namespace xqp
{
class xqpString;
class Time;
typedef rchandle<Time> Time_t;
class DateTime;
typedef rchandle<DateTime> DateTime_t;
class Duration;

/**
 *  time has the form: hh ':' mm ':' ss ('.' s+)? (zzzzzz)?
 *
 *  time cannot be negative
 *
 */

class Time : public SimpleRCObject
{
public:
  Time(boost::posix_time::time_duration t) : the_time(t) { };
  virtual ~Time() { };

  /**
   *  Returns 0 on success
   */
  static int parse_string(const xqpString& s, Time_t& t_t);

  /**
   *  Returns 0 on success
   */
  static int createTime(int hours, int minutes, double seconds, const TimeZone& tz, Time_t& t_t);
  
  bool operator<(const Time& t) const;
  bool operator==(const Time& t) const;
  int compare(const Time& t) const;

  DateTime_t toDateTime() const;
  xqpString toString() const;
  const boost::posix_time::time_duration& get_time_duration() const;

  int getHours() const;
  int getMinutes() const;
  double getSeconds() const;
  TimeZone getTimezone() const;

protected:
  Time& operator=(const Time_t& t_t);

  boost::posix_time::time_duration the_time;
  TimeZone the_time_zone;
};

Time_t operator+(const Time& t, const Duration& dur);

} // namespace xqp

#endif
