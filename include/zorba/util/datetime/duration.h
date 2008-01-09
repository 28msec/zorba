/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#ifndef XQP_DURATION_H
#define XQP_DURATION_H

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include "util/utf8/xqpString.h"
#include "util/rchandle.h"

namespace xqp
{
class YearMonthDuration;
class DayTimeDuration;
class Duration;
typedef rchandle<DayTimeDuration> DayTimeDuration_t;
typedef rchandle<YearMonthDuration> YearMonthDuration_t;
typedef rchandle<Duration> Duration_t;

class YearMonthDuration : public rcobject
{
public:
  YearMonthDuration() : months(0) { };
  YearMonthDuration(long the_months);
  virtual ~YearMonthDuration() { };

  static YearMonthDuration_t parse_string(xqpString s);

  YearMonthDuration& operator=(const YearMonthDuration_t& ym_t);
  bool operator<(const YearMonthDuration& ym) const;
  bool operator==(const YearMonthDuration& ym) const;
  int compare(const YearMonthDuration& ym) const;
  xqpString toString() const;

protected:  
  long months;
};

class DayTimeDuration : public rcobject
{
public:
  DayTimeDuration() : is_negative(false), days(0), timeDuration(0, 0, 0, 0) { };
  DayTimeDuration(bool negative, long the_days, long hours, long minutes, long seconds, long frac_seconds);
  virtual ~DayTimeDuration() { };

  static DayTimeDuration_t parse_string(xqpString s, bool dont_check_letter_p = false);
  
  DayTimeDuration& operator=(const DayTimeDuration_t& dt_t);
  bool operator<(const DayTimeDuration& dt) const;
  bool operator==(const DayTimeDuration& dt) const;
  int compare(const DayTimeDuration& dt) const;
  xqpString toString() const;

protected:  
  bool is_negative;
  long days;
  boost::posix_time::time_duration timeDuration;
};

class Duration : public rcobject
{
public:
  Duration();
  virtual ~Duration() { };

  static Duration_t parse_string(xqpString s);

  bool operator<(const Duration& d) const;
  bool operator==(const Duration& d) const;
  int compare(const Duration& d) const;
  xqpString toString() const;

protected:
  YearMonthDuration yearMonthDuration;
  DayTimeDuration dayTimeDuration;
};

} // namespace xqp

#endif
