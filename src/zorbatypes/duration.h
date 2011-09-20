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
#pragma once
#ifndef ZORBA_TYPES_DURATION_H
#define ZORBA_TYPES_DURATION_H

#include <zorba/config.h>
#include "zorbatypes/zorbatypes_decl.h"
#include "zorbatypes/schema_types.h"

#include "zorbaserialization/class_serializer.h"
#include "util/ascii_util.h"

namespace zorba
{

/*******************************************************************************
  The lexical format of duration is : PnYn MnDTnH nMnS

  See http://www.w3.org/TR/xmlschema-2/#duration for details.

  Note: class Timezone (in timezone.h) is a subclass of Duration
********************************************************************************/
class ZORBA_DLL_PUBLIC Duration : public ::zorba::serialization::SerializeBaseClass
{
public:

  typedef enum
  {
    DURATION_FACET = 0,
    YEARMONTHDURATION_FACET = 1,
    DAYTIMEDURATION_FACET = 2
  } FACET_TYPE;

  static const int FRAC_SECONDS_UPPER_LIMIT; // = 1000000, maximum 6 digits

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

protected:
  FACET_TYPE facet;

  bool       is_negative;
  long       data[7];

public:
  /**
   * Returns 0 on success, 1 on nonspecified error and 2 on integer overflow
   *
   */
  static int parseDuration(
        const char* str,
        ascii::size_type strlen,
        Duration& d);

  /**
   * Returns 0 on success, 1 on nonspecified error and 2 on integer overflow
   */
  static int parseYearMonthDuration(
        const char* str,
        ascii::size_type strlen,
        Duration& d);

  /**
   * Returns 0 on success, 1 on nonspecified error and 2 on integer overflow
   */
  static int parseDayTimeDuration(
        const char* str,
        ascii::size_type strlen,
        Duration& d,
        bool dont_check_letter_p = false);

  /**
   * Returns 0 on success
   */
  static int fromTimezone(const TimeZone& t, Duration& d);

public:
  SERIALIZABLE_CLASS(Duration)
  SERIALIZABLE_CLASS_CONSTRUCTOR(Duration)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  Duration();

  Duration(FACET_TYPE facet_type);

  /**
   * The function will use the absolute values of all long parameters. The
   * sign of the duration will be set by the sign of the longest time unit
   * different from 0. E.g. if years are not equal to 0, their sign will be
   * the sign of the duration, then months will be checked, then days, etc.
   */
  Duration(
        FACET_TYPE facet_type,
        long years,
        long months,
        long days,
        long hours,
        long minutes,
        double seconds);

  /**
   *  The function will use the absolute values of all long parameters.
   */
  Duration(
        FACET_TYPE facet_type,
        bool negative,
        long years,
        long months,
        long days,
        long hours,
        long minutes,
        double seconds);

  /**
   *  The function will use the absolute values of all long parameters.
   */
  Duration(
        FACET_TYPE facet_type,
        bool negative,
        long years,
        long months,
        long days,
        long hours,
        long minutes,
        int seconds,
        int frac_seconds);

  virtual ~Duration() {}

  bool operator==(const Duration& d) const;

  int compare(const Duration& d, bool ignore_sign = false) const;

  zstring toString() const;

  Duration* toDuration() const;

  Duration* toNegDuration() const;

  Duration* toYearMonthDuration() const;

  Duration* toDayTimeDuration() const;

  Duration* operator+(const Duration& d) const;

  Duration* operator-(const Duration& d) const;

  Duration* operator*(const xs_double& value) const;

  Duration* operator/(const xs_double& value) const;

  Decimal operator/(const Duration& d) const;

  virtual bool isNegative() const;

  bool isZero() const;

  long getYears() const;

  long getMonths() const;

  long getDays() const;

  virtual long getHours() const;

  virtual long getMinutes() const;

  virtual xs_decimal getSeconds() const;

  virtual long getFractionalSeconds() const;

  virtual long getIntSeconds() const;

  xs_double getTotalSeconds() const;

  long getTotalMilliseconds() const;

  uint32_t hash() const;

  FACET_TYPE getFacet() const { return facet; };

protected:
  void normalize();

  void adjustToFacet();

  void setFacet(FACET_TYPE a_facet);
};


} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */

/* vim:set et sw=2 ts=2: */
