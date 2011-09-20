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
#pragma once
#ifndef ZORBA_TIMEZONE_H
#define ZORBA_TIMEZONE_H

#include <zorba/config.h>
#include "zorbatypes/zorbatypes_decl.h"
#include "zorbatypes/duration.h"
#include "util/ascii_util.h"


namespace zorba
{

class ZORBA_DLL_PUBLIC TimeZone : protected Duration
{
protected:
  bool timezone_not_set;

public:
  /**
   *  Returns 0 on success.
   */
  static int parseTimeZone(const char* str, ascii::size_type strlen, TimeZone& tz);

  /**
   *  Returns 0 on success.
   */
  static int createTimeZone(int hours, int minutes, int seconds, TimeZone& tz);

public:
  ~TimeZone() { };

  TimeZone() : timezone_not_set(true) { };
  
  TimeZone(short hours);

  SERIALIZABLE_CLASS(TimeZone)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(TimeZone, Duration)
  void serialize(::zorba::serialization::Archiver& ar);

  bool operator<(const TimeZone& t) const;
      
  bool operator==(const TimeZone& t) const;
      
  int compare(const TimeZone& t) const;

  zstring toString() const;

  bool isNegative() const;

  long getHours() const;

  long getMinutes() const;

  xs_decimal getSeconds() const;

  long getIntSeconds() const;

  long getFractionalSeconds() const;

  uint32_t hash(int implicit_timezone_seconds) const;

  bool timeZoneNotSet() const;
};

} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
