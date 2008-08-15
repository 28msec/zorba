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


#include "zorbatypes/zorbatypes_decl.h"
#include "zorbatypes/xqpstring.h"
#include "zorbatypes/duration.h"


namespace zorba
{

class TimeZone : protected Duration
{
public:
  virtual ~TimeZone() { };

  TimeZone() : timezone_not_set(true) { };
  
  TimeZone(short hours);

  /**
   *  Returns 0 on success.
   */
  static int
  parseTimeZone(const xqpString& s, TimeZone& tz);

  /**
   *  Returns 0 on success.
   */
  static int
  createTimeZone(int hours, int minutes, int seconds, TimeZone& tz);

  bool
  operator<(const TimeZone& t) const;
      
  bool
  operator==(const TimeZone& t) const;
      
  int
  compare(const TimeZone& t) const;

  xqpString
  toString() const;

  virtual bool
  isNegative() const;

  virtual long
  getHours() const;

  virtual long
  getMinutes() const;

  virtual double
  getSeconds() const;

  virtual long
  getIntSeconds() const;

  virtual long
  getFractionalSeconds() const;

  uint32_t 
  hash(int implicit_timezone_seconds) const;

  bool
  timeZoneNotSet() const;

protected:
  bool timezone_not_set;
  
};

} /* namespace zorba */
#endif
