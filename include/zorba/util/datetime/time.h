/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#ifndef XQP_TIME_H
#define XQP_TIME_H

#include <boost/date_time/posix_time/posix_time.hpp>
#include "util/utf8/xqpString.h"
#include "util/rchandle.h"
#include "util/datetime/timezone.h"

namespace xqp
{
class Time;
typedef rchandle<Time> Time_t;

class Time : public rcobject
{
public:
  Time(boost::posix_time::time_duration t) : the_time(t) { };
  virtual ~Time() { };

  static bool parse_string(const xqpString& s, Time_t& t_t);
  
  bool operator<(const Time& t) const;
  bool operator==(const Time& t) const;
  int compare(const Time& t) const;

  xqpString toString() const;
  const boost::posix_time::time_duration& get_time_duration() const;

  int32_t getHours() const;

protected:
  Time& operator=(const Time_t& t_t);

  boost::posix_time::time_duration the_time;
  TimeZone the_time_zone;
};

} // namespace xqp

#endif
