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
#ifndef ZORBA_DATETIME_H
#define ZORBA_DATETIME_H

#include <zorba/config.h>
#include "zorbatypes/timezone.h"
#include "zorbatypes/duration.h"


namespace zorba
{

class   InvalidTimezoneException : public std::exception
{
};
  

 // exported for testing only
class ZORBA_DLL_PUBLIC DateTime 
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


public:
  /**
   *  Returns 0 on success
   *  Returns 2 if both the Date and the Time have a timezone, and they differ (FORG0008)
   */
  static int
  createDateTime(
        const DateTime* date,
        const DateTime* time,
        DateTime& result);
  
  /**
   *  The function will use the absolute values of all int parameters except
   *  years. No TimeZone.
   *  Returns 0 on success
   */
  static int
  createDateTime(
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
  static int
  createDateTime(
        int years,
        int months,
        int days,
        int hours,
        int minutes,
        double seconds,
        const TimeZone* tz,
        DateTime& dt);
      
  /**
   *  The function will use the absolute values of all int parameters except years. TimeZone may be NULL
   *  Returns 0 on success
   */
  static int
  createDateTime(
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
  static int
  createDate(
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
  static int
  createTime(
        int hours,
        int minutes,
        double seconds,
        const TimeZone* tz,
        DateTime& dt);
      
  /**
   *  The function will use the absolute value of the months parameter.
   *  Returns 0 on success
   */
  static int
  createGYearMonth(int years, int months, DateTime& dt);
  
  /**
   *  Returns 0 on success
   */
  static int
  createGYear(int years, DateTime& dt);

  /**
   *  The function will use the absolute values of all int parameters.
   *  Returns 0 on success
   */
  static int
  createGMonth(int months, DateTime& dt);

  /**
   *  The function will use the absolute values of all int parameters.
   *  Returns 0 on success
   */
  static int
  createGMonthDay(int months, int days, DateTime& dt);
  
  /**
   *  The function will use the absolute values of all int parameters.
   *  Returns 0 on success
   */
  static int
  createGDay(int days, DateTime& dt);

  static int
  getLocalTime(DateTime& dt);

  /**
   *  Returns 0 on success
   */
  static int 
  parseDateTime(const xqpString& s, DateTime& dt);
      
  /**
   *  Returns 0 on success
   */
  static int
  parseDate(const xqpString& s, DateTime& dt);
      
  /**
   *  Returns 0 on success
   */
  static int
  parseTime(const xqpString& s, DateTime& dt);
      
  /**
   *  Returns 0 on success
   */
  static int 
  parseGYearMonth(const xqpString& s, DateTime& dt);

  /**
   *  Returns 0 on success
   */
  static int 
  parseGYear(const xqpString& s, DateTime& dt);

  /**
   *  Returns 0 on success
   */
  static int 
  parseGMonth(const xqpString& s, DateTime& dt);

  /**
   *  Returns 0 on success
   */
  static int 
  parseGMonthDay(const xqpString& s, DateTime& dt);

  /**
   *  Returns 0 on success
   */
  static int 
  parseGDay(const xqpString& s, DateTime& dt);

public:
  DateTime();

  virtual ~DateTime() { };

  void init();

  DateTime& operator=(const DateTime* dt);

      
  /**
   *  Creates a new DateTime object from the given one, adjusting it to the newly 
   *  given facet. Useful for casting. Will always return 0.
   */
  int 
  createWithNewFacet(FACET_TYPE new_facet, DateTime& dt) const;

  xqpString 
  toString() const;
      
  DateTime*
  getDate() const;

  DateTime*
  getTime() const;
      
  int 
  getYear() const;
      
  int 
  getMonth() const;

  int 
  getDay() const;
      
  int 
  getHours() const;
      
  int 
  getMinutes() const;
      
  double 
  getSeconds() const;
  
  int
  getIntSeconds() const;
  
  int 
  getFractionalSeconds() const;  
      
  TimeZone
  getTimezone() const;

  /**
   *  Returns -1 if the DateTime is less than the given DateTime
   *  Returns 0 if the DateTimes are equal
   *  Returns 1 if the DateTime is greater than the given DateTime
   *
   *  Throws InvalidTimezoneException if the given timezone is not valid.
   *
   */
  int 
  compare(const DateTime* dt, long timezone_seconds) const;
      
  uint32_t 
  hash(int implicit_timezone_seconds) const;

  DateTime* 
  addDuration(const Duration& d, bool adjust_facet = true) const;

  DateTime* 
  subtractDuration(const Duration& d, bool adjust_facet = true) const;

  /**
   *  Throws InvalidTimezoneException if the given timezone is not valid.
   */
  Duration*
  subtractDateTime(const DateTime* dt, int implicit_timezone_seconds) const;
      
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
   *
   */ 
  int getDayOfWeek() const;
  int getDayOfYear() const;
  int getWeekInYear() const;
  int getWeekInMonth() const;
  bool isLeapYear() const;

  static int getDayOfWeek(int year, int month, int day);
  static int getDayOfYear(int year, int month, int day);
  static int getWeekInYear(int year, int month, int day);
  static int getWeekInMonth(int year, int month, int day);
  static bool isLeapYear(int year);  
  
      
protected:
  static int
  parse_date(std::string& ss,
             unsigned int& position,
             int& year,
             int& month,
             int& day);

  static int
  parse_time(std::string& ss,
             unsigned int& position,
             int& hour,
             int& minute,
             int& seconds,
             int& frac_seconds);

  Duration* toDayTimeDuration() const;

  void adjustToFacet();

  void setFacet(FACET_TYPE a_facet);

  
protected:
  FACET_TYPE facet;

  int data[7];
      
  TimeZone the_time_zone;
};

} /* namespace xqp */

#endif
