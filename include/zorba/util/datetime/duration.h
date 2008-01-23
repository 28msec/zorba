/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza, Sorin Nasoi
 */

#ifndef XQP_DURATION_H
#define XQP_DURATION_H

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include "util/utf8/xqpString.h"
#include "util/rchandle.h"

namespace xqp
{
class DurationBase;
class YearMonthDuration;
class DayTimeDuration;
class Duration;
typedef rchandle<DurationBase> DurationBase_t;
typedef rchandle<DayTimeDuration> DayTimeDuration_t;
typedef rchandle<YearMonthDuration> YearMonthDuration_t;
typedef rchandle<Duration> Duration_t;


class DurationBase : public rcobject
{
public:
  virtual bool operator<(const DurationBase& dt) const = 0;
  virtual bool operator==(const DurationBase& dt) const = 0;;
  virtual int compare(const DurationBase& dt) const = 0;;
  virtual xqpString toString() const = 0;;
  virtual int32_t getYears() const = 0;
};


class YearMonthDuration : public DurationBase
{
friend class Duration;

public:
  YearMonthDuration() : months(0) { };
  YearMonthDuration(long the_months);
  virtual ~YearMonthDuration() { };

  static bool parse_string(const xqpString& s, YearMonthDuration_t& ymd_t);

  virtual bool operator<(const DurationBase& dt) const;
  virtual bool operator==(const DurationBase& dt) const;
  virtual int compare(const DurationBase& dt) const;
  virtual xqpString toString() const;

  virtual int32_t getYears() const;

protected:
  YearMonthDuration& operator=(const YearMonthDuration_t& ym_t);

  long months;
};

class DayTimeDuration : public DurationBase
{
friend class Duration;

public:
  DayTimeDuration() : is_negative(false), days(0), timeDuration(0, 0, 0, 0) { };
  DayTimeDuration(bool negative, long the_days, long hours, long minutes, long seconds, long frac_seconds);
  virtual ~DayTimeDuration() { };

  static bool parse_string(const xqpString& s, DayTimeDuration_t& dtd_t, bool dont_check_letter_p = false);
  
  virtual bool operator<(const DurationBase& dt) const;
  virtual bool operator==(const DurationBase& dt) const;
  virtual int compare(const DurationBase& dt) const;
  virtual xqpString toString() const;

  virtual int32_t getYears() const;

protected:
  DayTimeDuration& operator=(const DayTimeDuration_t& dt_t);
  
  bool is_negative;
  long days;
  boost::posix_time::time_duration timeDuration;
};

class Duration : public DurationBase
{
public:
  Duration();
  virtual ~Duration() { };

  static bool parse_string(const xqpString& s, Duration_t& d_t);

  virtual bool operator<(const DurationBase& d) const;
  virtual bool operator==(const DurationBase& d) const;
  virtual int compare(const DurationBase& d) const;
  virtual xqpString toString() const;

  virtual int32_t getYears() const;

protected:
  YearMonthDuration yearMonthDuration;
  DayTimeDuration dayTimeDuration;
};

} // namespace xqp

#endif
