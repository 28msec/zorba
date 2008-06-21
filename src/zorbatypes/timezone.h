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
#ifndef ZORBA_TIMEZONE_H
#define ZORBA_TIMEZONE_H


#include <boost/date_time/posix_time/posix_time.hpp>
#include "zorbatypes/zorbatypes_decl.h"
#include "zorbatypes/xqpstring.h"


namespace zorba
{

class TimeZone : public SimpleRCObject
{
 public:
  virtual ~TimeZone() { };

  TimeZone() : the_time_zone(boost::posix_time::not_a_date_time) { };

  TimeZone(boost::posix_time::time_duration t) : the_time_zone(t) { };

  TimeZone(short hours);

  void init() { the_time_zone = boost::posix_time::not_a_date_time; }

  static bool
  parse_string(const xqpString& s, TimeZone_t& tz_t);

  /**
   *  Returns 0 on success.
   */
  static int
  createTimeZone(int hours, int minutes, int seconds, TimeZone_t& tz_t);

  bool
  operator<(const TimeZone& t) const;
      
  bool
  operator==(const TimeZone& t) const;
      
  int
  compare(const TimeZone& t) const;

  xqpString
  toString() const;

  virtual bool
  is_negative() const;

  virtual bool
  is_not_a_date_time() const;

  virtual long
  getHours() const;

  virtual long
  getMinutes() const;

  virtual long
  getSeconds() const;

  virtual long
  getFractionalSeconds() const;
      
  uint32_t 
  hash(int implicit_timezone_seconds) const;

protected:
  TimeZone& operator=(const TimeZone_t& t_t);

  boost::posix_time::time_duration the_time_zone;
};

} /* namespace zorba */
#endif
