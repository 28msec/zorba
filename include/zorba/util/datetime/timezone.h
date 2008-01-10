/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#ifndef XQP_TIMEZONE_H
#define XQP_TIMEZONE_H

#include <boost/date_time/posix_time/posix_time.hpp>
#include "util/utf8/xqpString.h"
#include "util/rchandle.h"

namespace xqp
{
class TimeZone;
typedef rchandle<TimeZone> TimeZone_t;

class TimeZone : public rcobject
{
public:
  TimeZone() : the_time_zone(boost::posix_time::not_a_date_time) { };
  TimeZone(boost::posix_time::time_duration t) : the_time_zone(t) { };
  virtual ~TimeZone() { };

  static TimeZone_t parse_string(xqpString s);

  TimeZone& operator=(const TimeZone_t& t_t);
  bool operator<(const TimeZone& t) const;
  bool operator==(const TimeZone& t) const;
  int compare(const TimeZone& t) const;

  xqpString toString() const;
  
protected:
  boost::posix_time::time_duration the_time_zone;
};

} // namespace xqp

#endif
