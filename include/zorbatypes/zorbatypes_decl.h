#ifndef ZORBA_ZORBATYPES_DECL_H
#define ZORBA_ZORBATYPES_DECL_H

#include <zorba/rchandle.h>

namespace zorba {
  /* numerics */
  template <class Object> class FloatImpl;
  class Integer;
  typedef FloatImpl<double> Double;
  typedef FloatImpl<float>  Float;

  /* datetime */
  class DateTime;
  class Date;
  class DayTimeDuration;
  class Decimal;
  class Duration;
  class Time;
  class TimeZone;
  class YearMonthDuration;
  class GYearMonth;
  class GYear;
  class GMonthDay;
  class GDay;
  class GMonth;

  typedef rchandle<DateTime> DateTime_t;
  typedef rchandle<Date> Date_t;
  typedef rchandle<Time> Time_t;
  typedef rchandle<TimeZone> TimeZone_t;
  typedef rchandle<DayTimeDuration> DayTimeDuration_t;
  typedef rchandle<YearMonthDuration> YearMonthDuration_t;
  typedef rchandle<Duration> Duration_t;
  typedef rchandle<GYearMonth> GYearMonth_t;
  typedef rchandle<GYear> GYear_t;
  typedef rchandle<GMonthDay> GMonthDay_t;
  typedef rchandle<GDay> GDay_t;
  typedef rchandle<GMonth> GMonth_t;
  
  /* string */
  class xqpStringStore;
  typedef rchandle<xqpStringStore> xqpStringStore_t;
};
#endif
