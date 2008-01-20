/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#ifndef XQP_GREGORIAN_H
#define XQP_GREGORIAN_H

#include <boost/date_time/gregorian/gregorian.hpp>
#include "util/utf8/xqpString.h"
#include "util/rchandle.h"
#include "util/datetime/timezone.h"

namespace xqp
{
class GYearMonth;
typedef rchandle<GYearMonth> GYearMonth_t;

class GYear;
typedef rchandle<GYear> GYear_t;

class GMonthDay;
typedef rchandle<GMonthDay> GMonthDay_t;

class GDay;
typedef rchandle<GDay> GDay_t;

class GMonth;
typedef rchandle<GMonth> GMonth_t;


/**
 * GYearMonth
 * 
 */
class GYearMonth : public rcobject
{
public:
  GYearMonth(boost::gregorian::date d) : the_gyear_month(d) { };
  virtual ~GYearMonth() { };

  static bool parse_string(const xqpString& s, GYearMonth_t& gym_t);

  GYearMonth& operator=(const GYearMonth_t& gym_t);
  bool operator<(const GYearMonth& gym) const;
  bool operator==(const GYearMonth& gym) const;
  int compare(const GYearMonth& gym) const;

  xqpString toString() const;
  
protected:
  boost::gregorian::date the_gyear_month;
  TimeZone the_time_zone;
};

/**
 * GYear
 *
 */
class GYear : public rcobject
{
public:
  GYear(boost::gregorian::date d) : the_gyear(d) { };
  virtual ~GYear() { };

  static bool parse_string(const xqpString& s, GYear_t& gy_t);


  bool operator<(const GYear& gy) const;
  bool operator==(const GYear& gy) const;
  int compare(const GYear& gy) const;

  xqpString toString() const;

protected:
  GYear& operator=(const GYear_t& gy_t);

  boost::gregorian::date the_gyear;
  TimeZone the_time_zone;
};

/**
 * GMonthDay
 *
 */
class GMonthDay : public rcobject
{
public:
  GMonthDay(boost::gregorian::date d) : the_gmonth_day(d) { };
  virtual ~GMonthDay() { };

  static bool parse_string(const xqpString& s, GMonthDay_t& gmd_t);

  bool operator<(const GMonthDay& gmd) const;
  bool operator==(const GMonthDay& gmd) const;
  int compare(const GMonthDay& gmd) const;

  xqpString toString() const;

protected:
  GMonthDay& operator=(const GMonthDay_t& gmd_t);
  
  boost::gregorian::date the_gmonth_day;
  TimeZone the_time_zone;
};

/**
 * GDay
 *
 */
class GDay: public rcobject
{
public:
  GDay(boost::gregorian::date d) : the_gday(d) { };
  virtual ~GDay() { };

  static bool parse_string(const xqpString& s, GDay_t& gd_t);

  bool operator<(const GDay& gd) const;
  bool operator==(const GDay& gd) const;
  int compare(const GDay& gd) const;

  xqpString toString() const;

protected:
  GDay& operator=(const GDay_t& gd_t);
  
  boost::gregorian::date the_gday;
  TimeZone the_time_zone;
};

/**
 * GMonth
 *
 */
class GMonth: public rcobject
{
public:
  GMonth(boost::gregorian::date d) : the_gmonth(d) { };
  virtual ~GMonth() { };

  static bool parse_string(const xqpString& s, GMonth_t& gm_t);

  bool operator<(const GMonth& gm) const;
  bool operator==(const GMonth& gm) const;
  int compare(const GMonth& gm) const;

  xqpString toString() const;

protected:
  GMonth& operator=(const GMonth_t& gm_t);
  
  boost::gregorian::date the_gmonth;
  TimeZone the_time_zone;
};


} // namespace xqp

#endif
