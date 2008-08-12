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

#include "zorbatypes/zorbatypes_decl.h"
#include "zorbatypes/xqpstring.h"

namespace zorba
{


class Duration
{
public:
  typedef enum
  {
    DURATION_FACET = 0,
    YEARMONTHDURATION_FACET = 1,
    DAYTIMEDURATION_FACET = 2
  } FACET_TYPE;

  static const int FRAC_SECONDS_UPPER_LIMIT; // = 1000000, maximum 6 digits
  
public:
  Duration();
  
  Duration(FACET_TYPE facet_type);

 /**
   *  The function will use the absolute values of all long parameters. The sign of the duration will
   *  be set by the sign of the longest time unit different from 0. E.g. if years are not equal to 0,
   *  their sign will be the sign of the duration, then months will be checked, then days, etc.
  */
  Duration(FACET_TYPE facet_type, long years, long months, long days,
           long hours, long minutes, double seconds);

  /**
   *  The function will use the absolute values of all long parameters.
   */
  Duration(FACET_TYPE facet_type, bool negative, long years, long months, long days,
           long hours, long minutes, double seconds);

  /**
   *  The function will use the absolute values of all long parameters.
   */
  Duration(FACET_TYPE facet_type, bool negative, long years, long months, long days,
           long hours, long minutes, int seconds, int frac_seconds);

  /**
   * Returns 0 on success
   */
  static int
  parseYearMonthDuration(const xqpString& s, Duration& d);
  
  /**
   * Returns 0 on success
   */
  static int
  parseDayTimeDuration(const xqpString& s, Duration& d, bool dont_check_letter_p = false);

  /**
   * Returns 0 on success
   */
  static int
  parseDuration(const xqpString& s, Duration& d);

  /**
   * Returns 0 on success
   */
  static int
  fromTimezone(const TimeZone& t, Duration& d);
  
  bool 
  operator==(const Duration& d) const;
      
  int
  compare(const Duration& d, bool ignore_sign = false) const;
      
  xqpString
  toString() const;
      
  Duration*
  toDuration() const;
      
  Duration*
  toNegDuration() const;
      
  Duration*
  toYearMonthDuration() const;
      
  Duration*
  toDayTimeDuration() const;

  Duration*
  operator+(const Duration& d) const;
      
  Duration*
  operator-(const Duration& d) const;
      
  Duration*
  operator*(const Double value) const;
      
  Duration*
  operator/(const Double value) const;
      
  Decimal
  operator/(const Duration& d) const;

  bool
  isNegative() const;

  bool
  isZero() const;

  long
  getYears() const;
      
  long
  getMonths() const;
      
  long
  getDays() const;
      
  long
  getHours() const;
      
  long
  getMinutes() const;
      
  double
  getSeconds() const;

  long
  getFractionalSeconds() const;

  long
  getIntSeconds() const;

  Double
  getTotalSeconds() const;
      
  uint32_t
  hash() const;

  FACET_TYPE getFacet() const { return facet; };

protected:
  void normalize();
  void adjustToFacet();
  void setFacet(FACET_TYPE a_facet);
  
protected:
  typedef enum
  {
    YEAR_DATA = 0,
    MONTH_DATA = 1,
    DAY_DATA = 2,
    HOUR_DATA = 3,
    MINUTE_DATA = 4,
    SECONDS_DATA = 5,
    FRACSECONDS_DATA = 6
  } DATA_TYPE;
  
  FACET_TYPE facet;

  bool is_negative;
  long data[7];
};


} /* namespace zorba */

#endif
