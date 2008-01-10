/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#ifndef XQP_GYEARMONTH_H
#define XQP_GYEARMONTH_H

#include <boost/date_time/gregorian/gregorian.hpp>
#include "util/utf8/xqpString.h"
#include "util/rchandle.h"
#include "util/datetime/timezone.h"

namespace xqp
{
class gYearMonth;
typedef rchandle<gYearMonth> gYearMonth_t;

class gYearMonth : public rcobject
{
public:
  gYearMonth(boost::gregorian::date d) : the_gyear_month(d) { };
  virtual ~gYearMonth() { };

  static gYearMonth_t parse_string(xqpString s);

  gYearMonth& operator=(const gYearMonth_t& gym_t);
  bool operator<(const gYearMonth& gym) const;
  bool operator==(const gYearMonth& gym) const;
  int compare(const gYearMonth& gym) const;

  xqpString toString() const;
  
protected:
  boost::gregorian::date the_gyear_month;
  TimeZone the_time_zone;
};

} // namespace xqp

#endif
