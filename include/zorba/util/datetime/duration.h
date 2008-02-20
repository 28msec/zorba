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
#include "zorba/util/bignum/floatimpl.h"


namespace xqp
{
class TimeZone;
class DurationBase;
class YearMonthDuration;
class DayTimeDuration;
class Duration;
class Decimal;
typedef FloatImpl<double> Double;
typedef rchandle<DurationBase> DurationBase_t;
typedef rchandle<DayTimeDuration> DayTimeDuration_t;
typedef rchandle<YearMonthDuration> YearMonthDuration_t;
typedef rchandle<Duration> Duration_t;


class DurationBase : public SimpleRCObject
{
public:
  bool operator==(const DurationBase& dt) const;
  int compare(const DurationBase& dt) const;
  virtual xqpString toString(bool output_when_zero = true) const = 0;
  virtual Duration_t toDuration() const = 0;

  virtual DurationBase_t operator+(const DurationBase& db) const = 0;
  virtual DurationBase_t operator-(const DurationBase& db) const = 0;
  virtual DurationBase_t operator*(const Double value) const = 0;
  virtual DurationBase_t operator/(const Double value) const = 0;
  virtual Decimal operator/(const DurationBase& db) const = 0;

  virtual int32_t getYears() const = 0;
  virtual int32_t getMonths() const = 0;
  virtual int32_t getDays() const = 0;
  virtual int32_t getHours() const = 0;
  virtual int32_t getMinutes() const = 0;
  virtual double getSeconds() const = 0;
};


class YearMonthDuration : public DurationBase
{
friend class Duration;

public:
  YearMonthDuration() : months(0) { };
  YearMonthDuration(long the_months);
  virtual ~YearMonthDuration() { };

  static bool parse_string(const xqpString& s, YearMonthDuration_t& ymd_t);

  bool operator==(const YearMonthDuration& ymd) const;
  bool operator<(const YearMonthDuration& ymd) const;
  virtual xqpString toString(bool output_when_zero = true) const;
  virtual Duration_t toDuration() const;

  virtual DurationBase_t operator+(const DurationBase& db) const;
  virtual DurationBase_t operator-(const DurationBase& db) const;
  virtual DurationBase_t operator*(const Double value) const;
  virtual DurationBase_t operator/(const Double value) const;
  virtual Decimal operator/(const DurationBase& db) const;
  
  virtual int32_t getYears() const;
  virtual int32_t getMonths() const;
  virtual int32_t getDays() const;
  virtual int32_t getHours() const;
  virtual int32_t getMinutes() const;
  virtual double getSeconds() const;
  
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
  static bool from_Timezone(const TimeZone& t, DurationBase_t& dt);

  bool operator==(const DayTimeDuration& dtd) const;
  bool operator<(const DayTimeDuration& dtd) const;
  virtual xqpString toString(bool output_when_zero = true) const;
  virtual Duration_t toDuration() const;

  virtual DurationBase_t operator+(const DurationBase& dt) const;
  virtual DurationBase_t operator-(const DurationBase& dt) const;
  virtual DurationBase_t operator*(const Double value) const;
  virtual DurationBase_t operator/(const Double value) const;
  virtual Decimal operator/(const DurationBase& db) const;
  
  virtual int32_t getYears() const;
  virtual int32_t getMonths() const;
  virtual int32_t getDays() const;
  virtual int32_t getHours() const;
  virtual int32_t getMinutes() const;
  virtual double getSeconds() const;

  virtual DayTimeDuration normalize() const;

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
  Duration(const YearMonthDuration& ymd) : yearMonthDuration(ymd) { };
  Duration(const DayTimeDuration& dtd) : dayTimeDuration(dtd) { };
  virtual ~Duration() { };

  static bool parse_string(const xqpString& s, Duration_t& d_t);

  bool operator==(const Duration& d) const;
  int compare(const Duration& d) const;
  bool operator<(const Duration& d) const;
  virtual xqpString toString(bool output_when_zero = true) const;
  virtual Duration_t toDuration() const;

  virtual DurationBase_t operator+(const DurationBase& d) const;
  virtual DurationBase_t operator-(const DurationBase& d) const;
  virtual DurationBase_t operator*(const Double value) const;
  virtual DurationBase_t operator/(const Double value) const;
  virtual Decimal operator/(const DurationBase& db) const;

  virtual int32_t getYears() const;
  virtual int32_t getMonths() const;
  virtual int32_t getDays() const;
  virtual int32_t getHours() const;
  virtual int32_t getMinutes() const;
  virtual double getSeconds() const;

protected:
  YearMonthDuration yearMonthDuration;
  DayTimeDuration dayTimeDuration;
};

} // namespace xqp

#endif
