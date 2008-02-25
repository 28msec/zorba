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
  virtual Duration_t toNegDuration() const = 0;

  virtual DurationBase_t operator+(const DurationBase& db) const = 0;
  virtual DurationBase_t operator-(const DurationBase& db) const = 0;
  virtual DurationBase_t operator*(const Double value) const = 0;
  virtual DurationBase_t operator/(const Double value) const = 0;
  virtual Decimal operator/(const DurationBase& db) const = 0;

  virtual int getYears() const = 0;
  virtual int getMonths() const = 0;
  virtual int getDays() const = 0;
  virtual int getHours() const = 0;
  virtual int getMinutes() const = 0;
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
  virtual Duration_t toNegDuration() const;

  virtual DurationBase_t operator+(const DurationBase& db) const;
  virtual DurationBase_t operator-(const DurationBase& db) const;
  virtual DurationBase_t operator*(const Double value) const;
  virtual DurationBase_t operator/(const Double value) const;
  virtual Decimal operator/(const DurationBase& db) const;
  
  virtual int getYears() const;
  virtual int getMonths() const;
  virtual int getDays() const;
  virtual int getHours() const;
  virtual int getMinutes() const;
  virtual double getSeconds() const;

  bool isNegative() const { return (months < 0); }
  bool isZero() const { return (months == 0); }
  
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
  virtual Duration_t toNegDuration() const;

  virtual DurationBase_t operator+(const DurationBase& dt) const;
  virtual DurationBase_t operator-(const DurationBase& dt) const;
  virtual DurationBase_t operator*(const Double value) const;
  virtual DurationBase_t operator/(const Double value) const;
  virtual Decimal operator/(const DurationBase& db) const;
  
  virtual int getYears() const;
  virtual int getMonths() const;
  virtual int getDays() const;
  virtual int getHours() const;
  virtual int getMinutes() const;
  virtual double getSeconds() const;

  bool isNegative() const { return is_negative; }
  bool isZero() const;


protected:
  void normalize();
  DayTimeDuration& operator=(const DayTimeDuration_t& dt_t);

  bool is_negative;
  long days;
  boost::posix_time::time_duration timeDuration;
};

class Duration : public DurationBase
{
public:
  virtual ~Duration() { };

  /**
   * Constructs a Duration from an YearMonthDuration
   * @param ymd source YearMonthDuration
   * @param negate if true, the created Duration's sign will be inverted
   */
  Duration(const YearMonthDuration& ymd, bool negate = false);

  /**
   * Constructs a Duration from a DateTimeDuration
   * @param dtd source DateTimeDuration
   * @param negate if true, the created Duration's sign will be inverted
   */
  Duration(const DayTimeDuration& dtd, bool negate = false);
  
  /**
   * Returns true on success
   */
  static bool parse_string(const xqpString& s, Duration_t& d_t);

  bool operator==(const Duration& d) const;
  int compare(const Duration& d) const;
  bool operator<(const Duration& d) const;
  virtual xqpString toString(bool output_when_zero = true) const;
  virtual Duration_t toDuration() const;
  virtual Duration_t toNegDuration() const;

  virtual DurationBase_t operator+(const DurationBase& d) const;
  virtual DurationBase_t operator-(const DurationBase& d) const;
  virtual DurationBase_t operator*(const Double value) const;
  virtual DurationBase_t operator/(const Double value) const;
  virtual Decimal operator/(const DurationBase& db) const;

  virtual int getYears() const;
  virtual int getMonths() const;
  virtual int getDays() const;
  virtual int getHours() const;
  virtual int getMinutes() const;
  virtual double getSeconds() const;

  bool isNegative() const;
  bool isZero() const;

protected:
  YearMonthDuration yearMonthDuration;
  DayTimeDuration dayTimeDuration;
};

} // namespace xqp

#endif
