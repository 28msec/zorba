/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_ZORBATYPES_DECL_H
#define ZORBA_ZORBATYPES_DECL_H

#include "zorbatypes/rchandle.h"

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
  class XQPCollator;
  class xqpStringStore;
  typedef rchandle<xqpStringStore> xqpStringStore_t;
};
#endif
