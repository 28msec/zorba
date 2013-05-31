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

// standard
#include <iostream>

// Zorba
#include <zorba/internal/ztd.h>
#include "zorbatypes/zstring.h"

namespace zorba {

class TimeZone;

namespace serialization {
  class Archiver;
  void operator&( Archiver&, TimeZone& );
}

///////////////////////////////////////////////////////////////////////////////

class TimeZone {
  typedef internal::ztd::explicit_bool explicit_bool;
public:
  typedef int value_type;

  /**
   * Parses a %TimeZone.
   *
   * @param s The string to parse.  Leading and trailing whitespce is ignored.
   * @param s_len The number of characters to parse.
   * @param tz The %TimeZone result.
   * @return Returns 0 on success, 1 for an invalid format, 2 for out-of-range
   * values.
   */
  static int parse( char const *s, size_t s_len, TimeZone *tz );

  /**
   * Constructs a %TimeZone.
   */
  TimeZone();
  
  /**
   * Constructs a %TimeZone.
   *
   * @param gmtoff The number of seconds east of the prime meridian.
   * @throws range_error if |<em>gmtoff</em>| &gt; 50400 (14 hours).
   */
  TimeZone( value_type gmtoff );

  /**
   * Constructs a %TimeZone.
   *
   * @throws range_error if |<em>hours</em>| &gt; 14, |<em>minutes</em>| &gt;
   * 59, or |<em>hours</em>| == 14 and |<em>minutes</em>| &gt; 0.
   */
  TimeZone( int hours, int minutes );

  /**
   * Gets the number of hours offset from GMT.
   *
   * @return Returns said hours where positive hours are hours east of the
   * prime meridian or an undefined value if the timezone is not set.
   */
  int getHours() const;

  /**
   * Gets the number of minutes offset from GMT.
   *
   * @return Returns said minutes where positive minutes are minutes east of
   * the prime meridian or an undefined value if the timezone is not set.
   */
  int getMinutes() const;

  /**
   * Gets the timezone offset from GMT.
   *
   * @return Returns the number of seconds east of the prime meridian or an
   * undefined value if the timezone is not set.
   */
  value_type gmtoff() const;

  /**
   * Conversion to \c bool.
   *
   * @return Returns \c true only if the time-zone is set.
   */
  operator explicit_bool::type() const;

  size_t hash() const;

  zstring toString() const;

private:
  value_type gmtoff_;
  bool timezone_not_set_;

  friend void serialization::operator&( serialization::Archiver&, TimeZone& );
};

///////////////////////////////////////////////////////////////////////////////

inline TimeZone::TimeZone() : timezone_not_set_( true ) {
}

inline int TimeZone::getHours() const {
  return gmtoff_ / (60 * 60);
}

inline int TimeZone::getMinutes() const {
  return gmtoff_ / 60 % 60;
}

inline TimeZone::value_type TimeZone::gmtoff() const {
  return gmtoff_;
}

inline TimeZone::operator explicit_bool::type() const {
  return explicit_bool::value_of( !timezone_not_set_ );
}

inline bool operator==( TimeZone const &tz1, TimeZone const &tz2 ) {
  return ( tz1 && tz2 && tz1.gmtoff() == tz2.gmtoff() )
      || ( !tz1 && !tz2 );
}

inline bool operator!=( TimeZone const &tz1, TimeZone const &tz2 ) {
  return !(tz1 == tz2);
}

inline bool operator<( TimeZone const &tz1, TimeZone const &tz2 ) {
  return tz1 && tz2 && tz1.gmtoff() < tz2.gmtoff();
}

inline bool operator<=( TimeZone const &tz1, TimeZone const &tz2 ) {
  return tz1 && tz2 && tz1.gmtoff() <= tz2.gmtoff();
}

inline bool operator>( TimeZone const &tz1, TimeZone const &tz2 ) {
  return tz1 && tz2 && tz1.gmtoff() > tz2.gmtoff();
}

inline bool operator>=( TimeZone const &tz1, TimeZone const &tz2 ) {
  return tz1 && tz2 && tz1.gmtoff() >= tz2.gmtoff();
}

inline bool operator==( TimeZone const &tz1, TimeZone::value_type tz2 ) {
  return tz1 && tz1.gmtoff() == tz2;
}

inline bool operator!=( TimeZone const &tz1, TimeZone::value_type tz2 ) {
  return !(tz1 == tz2);
}

inline bool operator<( TimeZone const &tz1, TimeZone::value_type tz2 ) {
  return tz1 && tz1.gmtoff() < tz2;
}

inline bool operator<=( TimeZone const &tz1, TimeZone::value_type tz2 ) {
  return tz1 && tz1.gmtoff() <= tz2;
}

inline bool operator>( TimeZone const &tz1, TimeZone::value_type tz2 ) {
  return tz1 && tz1.gmtoff() > tz2;
}

inline bool operator>=( TimeZone const &tz1, TimeZone::value_type tz2 ) {
  return tz1 && tz1.gmtoff() >= tz2;
}

inline bool operator==( TimeZone::value_type tz1, TimeZone const &tz2 ) {
  return tz2 && tz1 == tz2.gmtoff();
}

inline bool operator!=( TimeZone::value_type tz1, TimeZone const &tz2 ) {
  return !(tz1 == tz2);
}

inline bool operator<( TimeZone::value_type tz1, TimeZone const &tz2 ) {
  return tz2 && tz1 < tz2.gmtoff();
}

inline bool operator<=( TimeZone::value_type tz1, TimeZone const &tz2 ) {
  return tz2 && tz1 <= tz2.gmtoff();
}

inline bool operator>( TimeZone::value_type tz1, TimeZone const &tz2 ) {
  return tz2 && tz1 > tz2.gmtoff();
}

inline bool operator>=( TimeZone::value_type tz1, TimeZone const &tz2 ) {
  return tz2 && tz1 >= tz2.gmtoff();
}

inline std::ostream& operator<<( std::ostream &o, TimeZone const &tz ) {
  return o << tz.toString();
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_TIMEZONE_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
