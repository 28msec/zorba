/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#ifndef XQP_DATE_H
#define XQP_DATE_H

#include <boost/date_time/gregorian/gregorian.hpp>
#include "util/rchandle.h"
#include "util/datetime/timezone.h"

namespace xqp
{
class xqpString;
class Duration;
class DateTime;
typedef rchandle<DateTime> DateTime_t;
    
class Date;
typedef rchandle<Date> Date_t;


/**
 *  date has the form: '-'? yyyy '-' mm '-' dd zzzzzz?
 *
 */

class Date : public SimpleRCObject
{
public:
  virtual ~Date() { };

  /**
   *  Returns 0 on success
   */
  static int parse_string(const xqpString& s, Date_t& d_t);

  /**
   *  Returns 0 on success
   */
  static int createDate(int a_year, int a_month, int a_day, Date_t& d_t);

  /**
   *  Returns 0 on success
   */
  static int createDate(int a_year, int a_month, int a_day, const TimeZone& tz, Date_t& d_t);
  
  bool operator<(const Date& d) const;
  bool operator==(const Date& d) const;
  int compare(const Date& d) const;

  DateTime_t toDateTime() const;
  xqpString toString() const;
  
  int getYear() const;
  int getMonth() const;
  int getDay() const;
  TimeZone getTimezone() const;

protected:
  Date() : year(1), month(1), day(1) { };
  Date& operator=(const Date_t& d_t);

  int year; // the year carries the sign of the date
  int month;
  int day;
  TimeZone the_time_zone;
};

Date_t operator+(const Date& d, const Duration& dur);

} // namespace xqp

#endif
