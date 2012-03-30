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
#include "schema_types_base.h"
#include "zorbatypes_decl.h"
#include "zstring.h"

#ifdef ZORBA_WITH_BIG_INTEGER
# define TEMPLATE_DECL(T) /* nothing */
# define INTEGER_IMPL(T)  IntegerImpl
#else
# define TEMPLATE_DECL(T) template<typename T>
# define INTEGER_IMPL(T)  IntegerImpl<T>
#endif /* ZORBA_WITH_BIG_INTEGER */

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

class ZORBA_DLL_PUBLIC  Decimal  : public serialization::SerializeBaseClass {
public:

  ////////// constructors /////////////////////////////////////////////////////

  explicit Decimal( char c );
  explicit Decimal( signed char c );
  explicit Decimal( short n );
  explicit Decimal( int n = 0 );
  explicit Decimal( long n );
  explicit Decimal( long long n );
  explicit Decimal( unsigned char c );
  explicit Decimal( unsigned short n );
  explicit Decimal( unsigned int n );
  explicit Decimal( unsigned long n );
  explicit Decimal( unsigned long long n );
  explicit Decimal( float n );
  explicit Decimal( double n );
  Decimal( Decimal const &d );

  TEMPLATE_DECL(T)
  Decimal( INTEGER_IMPL(T) const &i );

  /**
   * Constructs a %Decimal from a C string.
   *
   * @param s The null-terminated C string to parse.  Leading and trailing
   * whitespace is ignored.
   * @throw std::invalid_argument if \a s does not contain a valid decimal.
   */
  explicit Decimal( char const *s );

  /**
   * Constructs a %Decimal from a Double.
   *
   * @param n The Double.
   * @throw std::invalid_argument if \a n is not finite.
   */
  explicit Decimal( Double const &n );

  /**
   * Constructs a %Decimal from a Float.
   *
   * @param n The Float.
   * @throw std::invalid_argument if \a n is not finite.
   */
  explicit Decimal( Float const &n );

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

  TEMPLATE_DECL(T)
  Decimal& operator=( INTEGER_IMPL(T) const &i );

  ////////// arithmetic operators /////////////////////////////////////////////

  friend Decimal operator+( Decimal const&, Decimal const& );
  friend Decimal operator-( Decimal const&, Decimal const& );
  friend Decimal operator*( Decimal const&, Decimal const& );
  friend Decimal operator/( Decimal const&, Decimal const& );
  friend Decimal operator%( Decimal const&, Decimal const& );

#define ZORBA_DECIMAL_OP(OP)                                            \
  TEMPLATE_DECL(T)                                                      \
  friend Decimal operator OP( Decimal const&, INTEGER_IMPL(T) const& ); \
  TEMPLATE_DECL(T)                                                      \
  friend Decimal operator OP( INTEGER_IMPL(T) const&, Decimal const& )

  ZORBA_DECIMAL_OP(+);
  ZORBA_DECIMAL_OP(-);
  ZORBA_DECIMAL_OP(*);
  ZORBA_DECIMAL_OP(/);
  ZORBA_DECIMAL_OP(%);
#undef ZORBA_DECIMAL_OP

  Decimal& operator+=( Decimal const& );
  Decimal& operator-=( Decimal const& );
  Decimal& operator*=( Decimal const& );
  Decimal& operator/=( Decimal const& );
  Decimal& operator%=( Decimal const& );

#define ZORBA_DECIMAL_OP(OP) \
  TEMPLATE_DECL(T) Decimal& operator OP( INTEGER_IMPL(T) const& )

  ZORBA_DECIMAL_OP(+=);
  ZORBA_DECIMAL_OP(-=);
  ZORBA_DECIMAL_OP(*=);
  ZORBA_DECIMAL_OP(/=);
  ZORBA_DECIMAL_OP(%=);
#undef ZORBA_DECIMAL_OP

  Decimal operator-() const;

  ////////// relational operators /////////////////////////////////////////////

#define ZORBA_DECIMAL_OP(OP)                                          \
  friend bool operator OP( Decimal const&, Decimal const& );          \
  TEMPLATE_DECL(T)                                                    \
  friend bool operator OP( Decimal const&, INTEGER_IMPL(T) const& );  \
  TEMPLATE_DECL(T)                                                    \
  friend bool operator OP( INTEGER_IMPL(T) const&, Decimal const& )

  ZORBA_DECIMAL_OP(==);
  ZORBA_DECIMAL_OP(!=);
  ZORBA_DECIMAL_OP(< );
  ZORBA_DECIMAL_OP(<=);
  ZORBA_DECIMAL_OP(> );
  ZORBA_DECIMAL_OP(>=);
#undef ZORBA_DECIMAL_OP

  ////////// math functions ///////////////////////////////////////////////////

  int compare( Decimal const& ) const;

  Decimal ceil() const;
  Decimal floor() const;
  Decimal round() const;

  TEMPLATE_DECL(T)
  Decimal round( INTEGER_IMPL(T) const &precision ) const;

  TEMPLATE_DECL(T)
  Decimal roundHalfToEven( INTEGER_IMPL(T) const &precision ) const;

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

  bool is_xs_long() const;

  enum parse_options {
    parse_integer,
    parse_decimal
  };

  static void parse( char const *s, value_type *result,
                     int parse_options = parse_decimal );

  static void reduce( char *s );

  static value_type round2( value_type const &v, value_type const &precision );

  static value_type roundHalfToEven2( value_type const &v,
                                      value_type const &precision );

  static zstring toString( value_type const&,
                           int precision = ZORBA_FLOAT_POINT_PRECISION );

  TEMPLATE_DECL(T) friend class IntegerImpl;
  template<typename T> friend class FloatImpl;

  friend xs_long to_xs_long( Decimal const& );
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
  parse( s, &value_ );
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
  parse( s, &value_ );
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

inline bool Decimal::is_xs_long() const {
  return value_.is_integer() &&
         value_ > MAPM::getMinInt64() && value_ < MAPM::getMaxInt64();
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

#undef TEMPLATE_DECL
#undef INTEGER_IMPL

#endif /* ZORBA_DECIMAL_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
