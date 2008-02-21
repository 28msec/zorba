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
class Date;
typedef rchandle<Date> Date_t;


/**
 *  date has the form: '-'? yyyy '-' mm '-' dd zzzzzz?
 *
 */

class Date : public SimpleRCObject
{
public:
  // Date(boost::gregorian::date d) : the_date(d) { };
  virtual ~Date() { };

  /**
   *  Returns 0 on success
   */
  static int parse_string(const xqpString& s, Date_t& d_t);
  static int createDate(int year, int month, int date, Date_t& d_t);
  
  bool operator<(const Date& d) const;
  bool operator==(const Date& d) const;
  int compare(const Date& d) const;

  xqpString toString() const;
  // const boost::gregorian::date& get_date() const;

  int32_t getYear() const;
  int32_t getMonth() const;
  int32_t getDay() const;
  TimeZone getTimezone() const;

protected:
  Date() : year(1), month(1), day(1) { };
  Date& operator=(const Date_t& d_t);

  int year; // the year carries the sign of the date
  int month;
  int day;
  TimeZone the_time_zone;
};

} // namespace xqp

#endif
