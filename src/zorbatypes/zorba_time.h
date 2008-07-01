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
#ifndef ZORBA_TIME_H
#define ZORBA_TIME_H

#include <boost/date_time/posix_time/posix_time.hpp>

#include "zorbatypes/zorbatypes_decl.h"
#include "zorbatypes/timezone.h"

namespace zorba
{

 /**
  *  time has the form: hh ':' mm ':' ss ('.' s+)? (zzzzzz)?
  *
  *  time cannot be negative
  *
  */
  class Time : public SimpleRCObject
  {
    public:
      Time(boost::posix_time::time_duration t) : the_time(t) { };
      virtual ~Time() { };

      /**
       *  Returns 0 on success
       */
      static int 
      parse_string(const xqpString& s, Time_t& t_t);

      /**
       *  Returns 0 on success
       */
      static int 
      createTime(int hours, int minutes, double seconds, const TimeZone& tz, Time_t& t_t);

      bool 
      operator<(const Time& t) const;
      
      bool
      operator==(const Time& t) const;
      
      int
      compare(const Time& t) const;

      DateTime_t
      toDateTime() const;
      
      xqpString
      toString() const;
      
      const boost::posix_time::time_duration& 
      get_time_duration() const;

      int
      getHours() const;
      
      int
      getMinutes() const;
      
      double
      getSeconds() const;
      
      TimeZone
      getTimezone() const;

      DateTime_t
      normalize(const long tz_seconds);

    protected:
      Time& 
      operator=(const Time_t& t_t);

      boost::posix_time::time_duration the_time;
      TimeZone the_time_zone;
  };

  Time_t operator+(const Time& t, const Duration& dur);

} /* namespace zorba */
#endif
