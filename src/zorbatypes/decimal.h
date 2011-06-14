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
#ifndef ZORBA_DECIMAL_H
#define ZORBA_DECIMAL_H

#include <zorba/config.h>

#include "common/common.h"
#include "zorbaserialization/archiver.h"
#include "zorbaserialization/class_serializer.h"

#include "m_apm.h"
#include "zorbatypes_decl.h"
#include "zstring.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

class ZORBA_DLL_PUBLIC  Decimal  : public serialization::SerializeBaseClass {
public:

  ////////// constructors /////////////////////////////////////////////////////

  Decimal( char c );
  Decimal( signed char c );
  Decimal( short n );
  Decimal( int n = 0 );
  Decimal( long n );
  Decimal( long long n );
  Decimal( unsigned char c );
  Decimal( unsigned short n );
  Decimal( unsigned int n );
  Decimal( unsigned long n );
  Decimal( unsigned long long n );
  Decimal( float n );
  Decimal( double n );
  Decimal( Decimal const &d );
  Decimal( Integer const &i );

  /**
   * Constructs a %Decimal from a C string.
   *
   * @param s The null-terminated C string to parse.  Leading and trailing
   * whitespace is ignored.
   * @throw std::invalid_argument if \a s does not contain a valid decimal.
   */
  Decimal( char const *s );

  /**
   * Constructs a %Decimal from a Double.
   *
   * @param n The Double.
   * @throw std::invalid_argument if \a n is not finite.
   */
  Decimal( Double const &n );

  /**
   * Constructs a %Decimal from a Float.
   *
   * @param n The Float.
   * @throw std::invalid_argument if \a n is not finite.
   */
  Decimal( Float const &n );

  ////////// assignment operators /////////////////////////////////////////////

  Decimal& operator=( char c );
  Decimal& operator=( signed char c );
  Decimal& operator=( short n );
  Decimal& operator=( int n );
  Decimal& operator=( long n );
  Decimal& operator=( long long n );
  Decimal& operator=( unsigned char c );
  Decimal& operator=( unsigned short n );
  Decimal& operator=( unsigned int n );
  Decimal& operator=( unsigned long n );
  Decimal& operator=( unsigned long long n );
  Decimal& operator=( float n );
  Decimal& operator=( double n );
  Decimal& operator=( char const *s );
  Decimal& operator=( Decimal const &d );
  Decimal& operator=( Double const &d );
  Decimal& operator=( Float const &f );
  Decimal& operator=( Integer const &i );

  ////////// arithmetic operators /////////////////////////////////////////////

  friend Decimal operator+( Decimal const &d1, Decimal const &d2 );
  friend Decimal operator-( Decimal const &d1, Decimal const &d2 );
  friend Decimal operator*( Decimal const &d1, Decimal const &d2 );
  friend Decimal operator/( Decimal const &d1, Decimal const &d2 );
  friend Decimal operator%( Decimal const &d1, Decimal const &d2 );

  friend Decimal operator+( Decimal const &d, Integer const &i );
  friend Decimal operator-( Decimal const &d, Integer const &i );
  friend Decimal operator*( Decimal const &d, Integer const &i );
  friend Decimal operator/( Decimal const &d, Integer const &i );
  friend Decimal operator%( Decimal const &d, Integer const &i );

  friend Decimal operator+( Integer const &i, Decimal const &d );
  friend Decimal operator-( Integer const &i, Decimal const &d );
  friend Decimal operator*( Integer const &i, Decimal const &d );
  friend Decimal operator/( Integer const &i, Decimal const &d );
  friend Decimal operator%( Integer const &i, Decimal const &d );

  Decimal& operator+=( Decimal const& );
  Decimal& operator-=( Decimal const& );
  Decimal& operator*=( Decimal const& );
  Decimal& operator/=( Decimal const& );
  Decimal& operator%=( Decimal const& );

  Decimal& operator+=( Integer const& );
  Decimal& operator-=( Integer const& );
  Decimal& operator*=( Integer const& );
  Decimal& operator/=( Integer const& );
  Decimal& operator%=( Integer const& );

  Decimal operator-() const;

  ////////// relational operators /////////////////////////////////////////////

  friend bool operator==( Decimal const &d1, Decimal const &d2 );
  friend bool operator!=( Decimal const &d1, Decimal const &d2 );
  friend bool operator< ( Decimal const &d1, Decimal const &d2 );
  friend bool operator<=( Decimal const &d1, Decimal const &d2 );
  friend bool operator> ( Decimal const &d1, Decimal const &d2 );
  friend bool operator>=( Decimal const &d1, Decimal const &d2 );

  friend bool operator==( Decimal const &d, Integer const &i );
  friend bool operator!=( Decimal const &d, Integer const &i );
  friend bool operator< ( Decimal const &d, Integer const &i );
  friend bool operator<=( Decimal const &d, Integer const &i );
  friend bool operator> ( Decimal const &d, Integer const &i );
  friend bool operator>=( Decimal const &d, Integer const &i );

  friend bool operator==( Integer const &i, Decimal const &d );
  friend bool operator!=( Integer const &i, Decimal const &d );
  friend bool operator< ( Integer const &i, Decimal const &d );
  friend bool operator<=( Integer const &i, Decimal const &d );
  friend bool operator> ( Integer const &i, Decimal const &d );
  friend bool operator>=( Integer const &i, Decimal const &d );

  ////////// math functions ///////////////////////////////////////////////////

  int compare( Decimal const &d ) const;

  Decimal ceil() const;
  Decimal floor() const;
  Decimal round() const;
  Decimal round( Integer const &precision ) const;
  Decimal roundHalfToEven( Integer const &precision ) const;
  Decimal sqrt() const;

  ////////// miscellaneous ////////////////////////////////////////////////////

  bool is_integer() const;

  uint32_t hash() const;

  int sign() const;

  zstring toString( int precision = ZORBA_FLOAT_POINT_PRECISION ) const;

  static Decimal const& one();
  static Decimal const& zero();

  /////////////////////////////////////////////////////////////////////////////

  SERIALIZABLE_CLASS(Decimal)
  SERIALIZABLE_CLASS_CONSTRUCTOR(Decimal)
  void serialize( serialization::Archiver& );

private:
  typedef MAPM value_type;
  value_type value_;

  Decimal( value_type const &v ) : value_( v ) { }

  static uint32_t hash( value_type const& );

  bool is_xs_int() const;
  bool is_xs_long() const;
  bool is_xs_uint() const;
  bool is_xs_ulong() const;

  enum parse_options {
    parse_none,
    parse_negative = 0x01,
    parse_decimal  = 0x02 | parse_negative
  };

  void parse( char const *s, int parse_options = parse_decimal );

  static void parse( char const *s, value_type *result,
                     int parse_options = parse_decimal );

  static void reduce( char *s );

  static value_type round( value_type const &v, value_type const &precision );

  static value_type roundHalfToEven( value_type const &v,
                                     value_type const &precision );

  static zstring toString( value_type const&,
                           int precision = ZORBA_FLOAT_POINT_PRECISION );

  friend class Integer;
  template<typename T> friend class FloatImpl;
  friend class NumConversions;
};

////////// constructors ///////////////////////////////////////////////////////

inline Decimal::Decimal( char c ) : value_( static_cast<long>( c ) ) {
}

inline Decimal::Decimal( signed char c ) : value_( static_cast<long>( c ) ) {
}

inline Decimal::Decimal( short n ) : value_( static_cast<long>( n ) ) {
}

inline Decimal::Decimal( int n ) : value_( static_cast<long>( n ) ) {
}

inline Decimal::Decimal( long n ) : value_( n ) {
}

inline Decimal::Decimal( unsigned char c ) : value_( static_cast<long>( c ) ) {
}

inline Decimal::Decimal( unsigned short n ) : value_( static_cast<long>( n ) ) {
}

inline Decimal::Decimal( unsigned int n ) : value_( static_cast<long>( n ) ) {
}

inline Decimal::Decimal( char const *s ) {
  parse( s );
}

inline Decimal::Decimal( Decimal const &d ) :
  serialization::SerializeBaseClass(), value_( d.value_ )
{
}

////////// assignment operators ///////////////////////////////////////////////

inline Decimal& Decimal::operator=( char c ) {
  value_ = static_cast<long>( c );
  return *this;
}

inline Decimal& Decimal::operator=( signed char c ) {
  value_ = static_cast<long>( c );
  return *this;
}

inline Decimal& Decimal::operator=( short n ) {
  value_ = static_cast<long>( n );
  return *this;
}

inline Decimal& Decimal::operator=( int n ) {
  value_ = static_cast<long>( n );
  return *this;
}

inline Decimal& Decimal::operator=( long n ) {
  value_ = n;
  return *this;
}

inline Decimal& Decimal::operator=( unsigned char c ) {
  value_ = static_cast<long>( c );
  return *this;
}

inline Decimal& Decimal::operator=( unsigned short n ) {
  value_ = static_cast<long>( n );
  return *this;
}

inline Decimal& Decimal::operator=( unsigned int n ) {
  value_ = static_cast<long>( n );
  return *this;
}

inline Decimal& Decimal::operator=( float n ) {
  value_ = n;
  return *this;
}

inline Decimal& Decimal::operator=( double n ) {
  value_ = n;
  return *this;
}

inline Decimal& Decimal::operator=( char const *s ) {
  parse( s );
  return *this;
}

inline Decimal& Decimal::operator=( Decimal const &d ) {
  value_ = d.value_;
  return *this;
}

////////// arithmetic operators ///////////////////////////////////////////////

inline Decimal operator+( Decimal const &d1, Decimal const &d2 ) {
  return d1.value_ + d2.value_;
}

inline Decimal operator-( Decimal const &d1, Decimal const &d2 ) {
  return d1.value_ - d2.value_;
}

inline Decimal operator*( Decimal const &d1, Decimal const &d2 ) {
  return d1.value_ * d2.value_;
}

inline Decimal operator/( Decimal const &d1, Decimal const &d2 ) {
  return d1.value_ / d2.value_;
}

inline Decimal operator%( Decimal const &d1, Decimal const &d2 ) {
  return d1.value_ % d2.value_;
}

inline Decimal& Decimal::operator+=( Decimal const &d ) {
  value_ += d.value_;
  return *this;
}

inline Decimal& Decimal::operator-=( Decimal const &d ) {
  value_ -= d.value_;
  return *this;
}

inline Decimal& Decimal::operator*=( Decimal const &d ) {
  value_ *= d.value_;
  return *this;
}

inline Decimal& Decimal::operator/=( Decimal const &d ) {
  value_ /= d.value_;
  return *this;
}

inline Decimal& Decimal::operator%=( Decimal const &d ) {
  value_ %= d.value_;
  return *this;
}

inline Decimal Decimal::operator-() const {
  return -value_;
}

////////// relational operators ///////////////////////////////////////////////

inline bool operator==( Decimal const &d1, Decimal const &d2 ) {
  return d1.value_ == d2.value_;
}

inline bool operator!=( Decimal const &d1, Decimal const &d2 ) {
  return d1.value_ != d2.value_;
}

inline bool operator<( Decimal const &d1, Decimal const &d2 ) {
  return d1.value_ < d2.value_;
}

inline bool operator<=( Decimal const &d1, Decimal const &d2 ) {
  return d1.value_ <= d2.value_;
}

inline bool operator>( Decimal const &d1, Decimal const &d2 ) {
  return d1.value_ > d2.value_;
}

inline bool operator>=( Decimal const &d1, Decimal const &d2 ) {
  return d1.value_ >= d2.value_;
}

////////// math functions /////////////////////////////////////////////////////

inline Decimal Decimal::ceil() const {
  return value_.ceil();
}

inline Decimal Decimal::floor() const {
  return value_.floor();
}

inline Decimal Decimal::sqrt() const {
  return value_.sqrt();
}

////////// miscellaneous //////////////////////////////////////////////////////

inline int Decimal::compare( Decimal const &d ) const {
  return value_.compare( d.value_ );
}

inline uint32_t Decimal::hash() const {
  return hash( value_ );
}

inline bool Decimal::is_integer() const {
  return value_.is_integer() != 0;
}

inline bool Decimal::is_xs_int() const {
  return  value_.is_integer() &&
          value_ > MAPM::getMinInt32() && value_ < MAPM::getMaxInt32();
}

inline bool Decimal::is_xs_long() const {
  return value_.is_integer() &&
         value_ > MAPM::getMinInt64() && value_ < MAPM::getMaxInt64();
}

inline bool Decimal::is_xs_uint() const {
  return  value_.is_integer() &&
          value_.sign() >= 0 &&
          value_ < MAPM::getMaxUInt32();
}

inline bool Decimal::is_xs_ulong() const {
  return  value_.is_integer() &&
          value_.sign() >= 0 &&
          value_ < MAPM::getMaxUInt64();
}

inline int Decimal::sign() const {
  return value_.sign();
}

inline zstring Decimal::toString( int precision ) const {
  return toString( value_, precision );
}

inline std::ostream& operator<<( std::ostream &os, Decimal const &d ) {
  return os << d.toString();
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_DECIMAL_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
