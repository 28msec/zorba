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
friend class Duration;

public:
  YearMonthDuration() : months(0) { };
  YearMonthDuration(long the_months);
  virtual ~YearMonthDuration() { };

  static bool parse_string(const xqpString& s, YearMonthDuration_t& ymd_t);

  bool operator<(const YearMonthDuration& ym) const;
  bool operator==(const YearMonthDuration& ym) const;
  int compare(const YearMonthDuration& ym) const;
  xqpString toString() const;

protected:
  YearMonthDuration& operator=(const YearMonthDuration_t& ym_t);
  
  long months;
};

class DayTimeDuration : public rcobject
{
friend class Duration;

public:
  DayTimeDuration() : is_negative(false), days(0), timeDuration(0, 0, 0, 0) { };
  DayTimeDuration(bool negative, long the_days, long hours, long minutes, long seconds, long frac_seconds);
  virtual ~DayTimeDuration() { };

  static bool parse_string(const xqpString& s, DayTimeDuration_t& dtd_t, bool dont_check_letter_p = false);
  
  bool operator<(const DayTimeDuration& dt) const;
  bool operator==(const DayTimeDuration& dt) const;
  int compare(const DayTimeDuration& dt) const;
  xqpString toString() const;

protected:
  DayTimeDuration& operator=(const DayTimeDuration_t& dt_t);
  
  bool is_negative;
  long days;
  boost::posix_time::time_duration timeDuration;
};

class Duration : public rcobject
{
public:
  Duration();
  virtual ~Duration() { };

  static bool parse_string(const xqpString& s, Duration_t& d_t);

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
