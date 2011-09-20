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
#ifndef ZORBA_DATETIME_H
#define ZORBA_DATETIME_H

#include <iostream>

#include <zorba/config.h>
#include "zorbatypes/timezone.h"
#include "zorbatypes/duration.h"

#include "zorbaserialization/class_serializer.h"

#include "util/ascii_util.h"


namespace zorba
{

class InvalidTimezoneException : public std::exception
{
};
  

class DateTime : ::zorba::serialization::SerializeBaseClass
{
public:
      
  /** Available facets for the DateTime class */
  typedef enum 
  {
    DATETIME_FACET = 0,
    DATE_FACET = 1,
    TIME_FACET = 2,
    GYEARMONTH_FACET = 3,
    GYEAR_FACET = 4,
    GMONTH_FACET = 5,
    GMONTHDAY_FACET = 6,
    GDAY_FACET = 7
  } FACET_TYPE;

  // Only year may be negative, all other must be positive
  // The year gives the sign of DateTime, Date, etc
      
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


  static const int FACET_MEMBERS[8][8];

  // fractional seconds have 6 digits. 0.1 seconds are represented as 100000,
  // 0.01 seconds as 10000, etc.
  static const int FRAC_SECONDS_UPPER_LIMIT; // = 1000000, maximum 6 digits

protected:
  FACET_TYPE facet;

  long       data[7];
      
  TimeZone   the_time_zone;

public:
  /**
   *  Returns 0 on success
   *  Returns 2 if both the Date and the Time have a timezone, and they differ (FORG0008)
   */
  static int createDateTime(
        const DateTime* date,
        const DateTime* time,
        DateTime& result);
  
  /**
   *  The function will use the absolute values of all int parameters except
   *  years. No TimeZone.
   *  Returns 0 on success
   */
  static int createDateTime(
        int years,
        int months,
        int days,
        int hours,
        int minutes,
        int seconds,
        int fractional_seconds,
        DateTime& dt);
      
  /**
   *  The function will use the absolute values of all int parameters except
   *  years. TimeZone may be NULL
   *  Returns 0 on success
   */
  static int createDateTime(
        int years,
        int months,
        int days,
        int hours,
        int minutes,
        double seconds,
        const TimeZone* tz,
        DateTime& dt);
      
  /**
   *  The function will use the absolute values of all int parameters except
   *  years. TimeZone may be NULL
   *  Returns 0 on success
   */
  static int createDateTime(
        int years,
        int months,
        int days,
        int hours,
        int minutes,
        int seconds,
        int fractional_seconds,
        const TimeZone* tz,
        DateTime& dt);

  /**
   *  The function will use the absolute values of all int parameters except years.
   *  TimeZone may be NULL
   *  Returns 0 on success
   */
  static int createDate(
        int years,
        int months,
        int days,
        const TimeZone* tz,
        DateTime& dt);

  /**
   *  The function will use the absolute values of all int parameters. TimeZone
   *  is a reference
   *  Returns 0 on success
   */
  static int createTime(
        int hours,
        int minutes,
        double seconds,
        const TimeZone* tz,
        DateTime& dt);
      
  /**
   *  The function will use the absolute value of the months parameter.
   *  Returns 0 on success
   */
  static int createGYearMonth(int years, int months, DateTime& dt);
  
  /**
   *  Returns 0 on success
   */
  static int createGYear(int years, DateTime& dt);

  /**
   *  The function will use the absolute values of all int parameters.
   *  Returns 0 on success
   */
  static int createGMonth(int months, DateTime& dt);

  /**
   *  The function will use the absolute values of all int parameters.
   *  Returns 0 on success
   */
  static int createGMonthDay(int months, int days, DateTime& dt);
  
  /**
   *  The function will use the absolute values of all int parameters.
   *  Returns 0 on success
   */
  static int createGDay(int days, DateTime& dt);

  static int getLocalTime(DateTime& dt);

  /**
   *  Returns 0 on success
   */
  static int parseDateTime(const char* str, ascii::size_type strlen, DateTime& dt);
      
  /**
   *  Returns 0 on success
   */
  static int parseDate(const char* str, ascii::size_type strlen, DateTime& dt);
      
  /**
   *  Returns 0 on success
   */
  static int parseTime(const char* str, ascii::size_type strlen, DateTime& dt);
      
  /**
   *  Returns 0 on success
   */
  static int parseGYearMonth(const char* str, ascii::size_type strlen, DateTime& dt);

  /**
   *  Returns 0 on success
   */
  static int parseGYear(const char* str, ascii::size_type strlen, DateTime& dt);

  /**
   *  Returns 0 on success
   */
  static int parseGMonth(const char* str, ascii::size_type strlen, DateTime& dt);

  /**
   *  Returns 0 on success
   */
  static int parseGMonthDay(const char* str, ascii::size_type strlen, DateTime& dt);

  /**
   *  Returns 0 on success
   */
  static int parseGDay(const char* str, ascii::size_type strlen, DateTime& dt);

  static int getDayOfWeek(int year, int month, int day);

  static int getDayOfYear(int year, int month, int day);

  static int getWeekInYear(int year, int month, int day);

  static int getWeekInMonth(int year, int month, int day);

  static bool isLeapYear(int year);  

protected:
  static int parse_date(
        const char* str,
        ascii::size_type strlen,
        ascii::size_type& position,
        long& year,
        long& month,
        long& day);

  static int parse_time(
        const char* str,
        ascii::size_type strlen,
        ascii::size_type& position,
        long& hour,
        long& minute,
        long& seconds,
        long& frac_seconds);

public:
  SERIALIZABLE_CLASS(DateTime)
  SERIALIZABLE_CLASS_CONSTRUCTOR(DateTime)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  DateTime();

  virtual ~DateTime() { };

  void init();

  DateTime& operator=(const DateTime* dt);

  /**
   *  Creates a new DateTime object from the given one, adjusting it to the newly 
   *  given facet. Useful for casting. Will always return 0.
   */
  int createWithNewFacet(FACET_TYPE new_facet, DateTime& dt) const;

  zstring toString() const;
      
  DateTime* getDate() const;

  DateTime* getTime() const;
      
  int getYear() const;
      
  int getMonth() const;

  int getDay() const;
      
  int getHours() const;
      
  int getMinutes() const;
      
  xs_decimal getSeconds() const;
  
  int getIntSeconds() const;
  
  int getFractionalSeconds() const;  
      
  TimeZone getTimezone() const;

  /**
   *  Returns -1 if the DateTime is less than the given DateTime
   *  Returns 0 if the DateTimes are equal
   *  Returns 1 if the DateTime is greater than the given DateTime
   *
   *  Throws InvalidTimezoneException if the given timezone is not valid.
   */
  int compare(const DateTime* dt, long timezone_seconds) const;
      
  uint32_t hash(int implicit_timezone_seconds) const;

  DateTime* addDuration(const Duration& d, bool adjust_facet = true) const;

  DateTime* subtractDuration(const Duration& d, bool adjust_facet = true) const;

  /**
   *  Throws InvalidTimezoneException if the given timezone is not valid.
   */
  Duration* subtractDateTime(const DateTime* dt, int implicit_timezone_seconds) const;
      
  /**
   *  Throws InvalidTimezoneException if the given timezone is not valid.
   */
  DateTime* normalizeTimeZone(int tz_seconds) const;
      
  /**
   *  Throws InvalidTimezoneException if the given timezone is not valid.
   */
  DateTime* adjustToTimeZone(int tz_seconds) const;
      
  /**
   *  Throws InvalidTimezoneException if the given timezone is not valid.
   */
  DateTime* adjustToTimeZone(const Duration* db_t) const;
      
  FACET_TYPE getFacet() const { return facet; };   
  
  /**
   *  For a given Date or DateTime, it will return the respective day of the week, 
   *  with the index being 0 based, with 0 being Sunday, 1 Monday, etc. If the give 
   *  DateTime does not have a Date or DateTime facet, the function will return -1.
   */ 
  int getDayOfWeek() const;
  int getDayOfYear() const;
  int getWeekInYear() const;
  int getWeekInMonth() const;
  bool isLeapYear() const;
      
protected:
  Duration* toDayTimeDuration() const;

  void adjustToFacet();

  void setFacet(FACET_TYPE a_facet);
};

inline std::ostream& operator<<( std::ostream &o, DateTime const &dt ) {
  return o << dt.toString();
}

} // namespace zorba
#endif /* ZORBA_DATETIME_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
