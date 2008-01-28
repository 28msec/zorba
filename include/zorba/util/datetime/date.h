/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#ifndef XQP_DATE_H
#define XQP_DATE_H

#include <boost/date_time/gregorian/gregorian.hpp>
#include "util/utf8/xqpString.h"
#include "util/rchandle.h"
#include "util/datetime/timezone.h"

namespace xqp
{
class Date;
typedef rchandle<Date> Date_t;

class Date : public rcobject
{
public:
  Date(boost::gregorian::date d) : the_date(d) { };
  virtual ~Date() { };

  static bool parse_string(const xqpString& s, Date_t& d_t);
  
  bool operator<(const Date& d) const;
  bool operator==(const Date& d) const;
  int compare(const Date& d) const;

  xqpString toString() const;
  const boost::gregorian::date& get_date() const;

  int32_t getYear() const;
  int32_t getMonth() const;

protected:
  Date& operator=(const Date_t& d_t);
  
  boost::gregorian::date the_date;
  TimeZone the_time_zone;
};

} // namespace xqp

#endif
