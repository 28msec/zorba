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
#ifndef ZORBA_DURATION_H
#define ZORBA_DURATION_H

// TODO can we remove boost includes from headers?
//      otherwise a user would need development header for writing
//      his apps
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>

#include "zorbatypes/zorbatypes_decl.h"
#include "zorbatypes/xqpstring.h"

namespace zorba
{
  class DurationBase;
  typedef rchandle<DurationBase> DurationBase_t;

  class DurationBase : public SimpleRCObject
  {
    public:
      bool 
      operator==(const DurationBase& dt) const;
      
      int
      compare(const DurationBase& dt) const;
      
      virtual xqpString
      toString(bool output_when_zero = true) const = 0;
      
      virtual Duration_t
      toDuration() const = 0;
      
      virtual Duration_t
      toNegDuration() const = 0;
      
      virtual DurationBase_t
      toYearMonthDuration() const = 0;
      
      virtual DurationBase_t
      toDayTimeDuration() const = 0;

      virtual DurationBase_t
      operator+(const DurationBase& db) const = 0;
      
      virtual DurationBase_t
      operator-(const DurationBase& db) const = 0;
      
      virtual DurationBase_t
      operator*(const Double value) const = 0;
      
      virtual DurationBase_t
      operator/(const Double value) const = 0;
      
      virtual Decimal
      operator/(const DurationBase& db) const = 0;

      virtual int
      getYears() const = 0;
      
      virtual int
      getMonths() const = 0;
      
      virtual int
      getDays() const = 0;
      
      virtual int
      getHours() const = 0;
      
      virtual int
      getMinutes() const = 0;
      
      virtual double
      getSeconds() const = 0;
      
      virtual uint32_t
      hash() const = 0;
  }; /* class DurationBase */


  class YearMonthDuration : public DurationBase
  {
    friend class Duration;

    public:
      YearMonthDuration() : months(0) { };
      YearMonthDuration(long the_months);
      virtual ~YearMonthDuration() { };

      static bool 
      parse_string(const xqpString& s, YearMonthDuration_t& ymd_t);

      bool 
      operator==(const YearMonthDuration& ymd) const;
      
      bool
      operator<(const YearMonthDuration& ymd) const;
      
      virtual xqpString
      toString(bool output_when_zero = true) const;
      
      virtual Duration_t
      toDuration() const;
      
      virtual Duration_t
      toNegDuration() const;
      
      virtual DurationBase_t
      toYearMonthDuration() const;
      
      virtual DurationBase_t
      toDayTimeDuration() const;

      virtual DurationBase_t
      operator+(const DurationBase& db) const;
      
      virtual DurationBase_t 
      operator-(const DurationBase& db) const;
      
      virtual DurationBase_t 
      operator*(const Double value) const;
      
      virtual DurationBase_t
      operator/(const Double value) const;
      
      virtual Decimal
      operator/(const DurationBase& db) const;

      virtual int
      getYears() const;
      
      virtual int
      getMonths() const;
      
      virtual int
      getDays() const;

      virtual int
      getHours() const;

      virtual int
      getMinutes() const;

      virtual double
      getSeconds() const;

      bool
      isNegative() const { return (months < 0); }
      
      bool
      isZero() const { return (months == 0); }
      
      virtual uint32_t
      hash() const;

    protected:
      YearMonthDuration& 
      operator=(const YearMonthDuration_t& ym_t);

      long months;
  };

  class DayTimeDuration : public DurationBase
  {
    friend class Duration;

    public:
      DayTimeDuration() : is_negative(false), days(0), timeDuration(0, 0, 0, 0) { };

      /**
       *  The function will use the absolute values of all long parameters.
       */
      DayTimeDuration(bool negative, long the_days, long hours, long minutes, long seconds, long frac_seconds);
      
      /**
       *  The function will use the absolute values of all long parameters. The sign of the duration will
       *  be set by the sign of the longest time period not equal to 0. E.g. if the_days is not equal to 0,
       *  their sign will be the sign of the duration, then hours will be checked, then minutes, etc.
       */
      DayTimeDuration(long the_days, long hours, long minutes, double seconds);
      
      /**
       *  The function will use the absolute values of all long parameters. The sign of the duration will 
       *  be set by the sign of the longest time period not equal to 0. E.g. if the_days is not equal to 0, 
       *  their sign will be the sign of the duration, then hours will be checked, then minutes, etc.
       */
      DayTimeDuration(long the_days, long hours, long minutes, long seconds, long frac_seconds);
      virtual ~DayTimeDuration() { };

      static bool 
      parse_string(const xqpString& s, DayTimeDuration_t& dtd_t, bool dont_check_letter_p = false);
      
      static bool
      from_Timezone(const TimeZone& t, DurationBase_t& dt);

      bool 
      operator==(const DayTimeDuration& dtd) const;

      bool
      operator<(const DayTimeDuration& dtd) const;
      
      virtual xqpString
      toString(bool output_when_zero = true) const;

      virtual Duration_t
      toDuration() const;

      virtual Duration_t
      toNegDuration() const;
      
      virtual DurationBase_t
      toYearMonthDuration() const;
      
      virtual DurationBase_t
      toDayTimeDuration() const;

      virtual DurationBase_t
      operator+(const DurationBase& dt) const;

      virtual DurationBase_t
      operator-(const DurationBase& dt) const;

      virtual DurationBase_t
      operator*(const Double value) const;

      virtual DurationBase_t
      operator/(const Double value) const;

      virtual Decimal
      operator/(const DurationBase& db) const;

      virtual int
      getYears() const;

      virtual int
      getMonths() const;

      virtual int
      getDays() const;

      virtual int
      getHours() const;

      virtual int
      getMinutes() const;

      virtual double
      getSeconds() const;
      
      double
      getTotalSeconds() const;

      bool
      isNegative() const { return is_negative; }
      
      bool
      isZero() const;
      
      virtual uint32_t
      hash() const;
      
      virtual uint32_t
      hash(uint32_t hval) const;

    protected:
      DayTimeDuration& 
      operator=(const DayTimeDuration_t& dt_t);
      
      // Addition or subtraction
      DurationBase_t
      add_or_subtract(const DurationBase& dt, bool subtract = false) const;

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
      static bool
      parse_string(const xqpString& s, Duration_t& d_t);

      /**
       * Returns 0 on success
       */
      static int
      from_Timezone(const TimeZone& t, Duration_t& dt);

      bool
      operator==(const Duration& d) const;
      
      int
      compare(const Duration& d) const;
      
      bool
      operator<(const Duration& d) const;
      
      virtual xqpString
      toString(bool output_when_zero = true) const;

      virtual Duration_t
      toDuration() const;

      virtual Duration_t
      toNegDuration() const;
      
      virtual DurationBase_t
      toYearMonthDuration() const;
      
      virtual DurationBase_t
      toDayTimeDuration() const;

      virtual DurationBase_t
      operator+(const DurationBase& d) const;

      virtual DurationBase_t
      operator-(const DurationBase& d) const;

      virtual DurationBase_t
      operator*(const Double value) const;

      virtual DurationBase_t
      operator/(const Double value) const;

      virtual Decimal
      operator/(const DurationBase& db) const;

      virtual int
      getYears() const;

      virtual int
      getMonths() const;

      virtual int
      getDays() const;

      virtual int
      getHours() const;

      virtual int
      getMinutes() const;

      virtual double
      getSeconds() const;

      bool 
      isNegative() const;
      
      bool 
      isZero() const;
      
      virtual uint32_t
      hash() const;

    protected:
      YearMonthDuration yearMonthDuration;
      DayTimeDuration dayTimeDuration;
  };

} /* namespace zorba */
#endif
