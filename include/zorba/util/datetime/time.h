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

namespace xqp
{
class Time;
typedef rchandle<Time> Time_t;

class Time : public rcobject
{
public:
  Time(boost::posix_time::time_duration t) : the_time(t) { };
  virtual ~Time() { };

  static Time_t parse_string(xqpString s);
  
  bool operator<(const Time& t) const;
  bool operator==(const Time& t) const;
  int compare(const Time& t) const;

  xqpString toString() const;
  const boost::posix_time::time_duration& get_time_duration() const;

protected:
  Time& operator=(const Time_t& t_t);
  boost::posix_time::time_duration the_time;

};

} // namespace xqp

#endif
