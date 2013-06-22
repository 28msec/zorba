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
#include <zorba/internal/ztd.h>

#include "common/common.h"
#include "util/stl_util.h"

#include "m_apm.h"
#include "schema_types_base.h"
#include "zorbatypes_decl.h"
#include "zstring.h"

namespace zorba {

class Decimal;

namespace serialization 
{
  class Archiver;
  void operator&(Archiver& ar, Decimal& obj);
}


///////////////////////////////////////////////////////////////////////////////

class Decimal {
  typedef internal::ztd::explicit_bool explicit_bool;
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

  template<class T>
  explicit Decimal( IntegerImpl<T> const &i );

  /**
   * Constructs a %Decimal from a C string.
   *
   * @param s The null-terminated C string to parse.  Leading and trailing
   * whitespace is ignored.
   * @throw std::invalid_argument if \a s does not contain a valid decimal.
   */
  explicit Decimal( char const *s );

  /**
   * Constructs a %Decimal from a string.
   *
   * @tparam StringType The string type.
   * @param s The string to parse.  Leading and trailing whitespace is ignored.
   * @throw std::invalid_argument if \a s does not contain a valid decimal.
   */
  template<class StringType>
  explicit Decimal( StringType const &s,
    typename std::enable_if<ZORBA_HAS_C_STR(StringType)>::type* = nullptr );

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

  /**
   * Conventional copy constructor.
   *
   * @param d The %Decimal to copy from.
   */
  Decimal( Decimal const &d );

  ////////// assignment operators /////////////////////////////////////////////

  /**
   * Conventional assignment operator.
   *
   * @param d The %Decimal to assign from.
   * @return Returns \c *this.
   */
  Decimal& operator=( Decimal const &d );

  Decimal& operator=( signed char c );
  Decimal& operator=( char c );
  Decimal& operator=( short n );
  Decimal& operator=( int n );
  Decimal& operator=( long n );
  Decimal& operator=( long long n );
  Decimal& operator=( unsigned char c );
  Decimal& operator=( unsigned short n );
  Decimal& operator=( unsigned int n );
  Decimal& operator=( unsigned long n );
  Decimal& operator=( unsigned long long n );

  Decimal& operator=( char const *s );

  template<class StringType>
  typename std::enable_if<ZORBA_HAS_C_STR(StringType),Decimal&>::type
  operator=( StringType const &s );

  Decimal& operator=( Double const &d );
  Decimal& operator=( Float const &f );

  template<class T>
  Decimal& operator=( IntegerImpl<T> const &i );

  ////////// arithmetic operators /////////////////////////////////////////////

  friend Decimal operator+( Decimal const&, Decimal const& );
  friend Decimal operator-( Decimal const&, Decimal const& );
  friend Decimal operator*( Decimal const&, Decimal const& );
  friend Decimal operator/( Decimal const&, Decimal const& );
  friend Decimal operator%( Decimal const&, Decimal const& );

#define ZORBA_DECIMAL_OP(OP)                                            \
  template<class T>                                                     \
  friend Decimal operator OP( Decimal const&, IntegerImpl<T> const& );  \
                                                                        \
  template<class T>                                                     \
  friend Decimal operator OP( IntegerImpl<T> const&, Decimal const& )

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
  template<class T> Decimal& operator OP( IntegerImpl<T> const& )

  ZORBA_DECIMAL_OP(+=);
  ZORBA_DECIMAL_OP(-=);
  ZORBA_DECIMAL_OP(*=);
  ZORBA_DECIMAL_OP(/=);
  ZORBA_DECIMAL_OP(%=);
#undef ZORBA_DECIMAL_OP

  Decimal operator-() const;

  ////////// relational operators /////////////////////////////////////////////

#define ZORBA_DECIMAL_OP(OP)                                        \
  friend bool operator OP( Decimal const&, Decimal const& );        \
  template<class T>                                                 \
  friend bool operator OP( Decimal const&, IntegerImpl<T> const& ); \
  template<class T>                                                 \
  friend bool operator OP( IntegerImpl<T> const&, Decimal const& )

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

  template<class T>
  Decimal round( IntegerImpl<T> const &precision ) const;

  template<class T>
  Decimal roundHalfToEven( IntegerImpl<T> const &precision ) const;

  Decimal sqrt() const;

  ////////// miscellaneous ////////////////////////////////////////////////////

  size_t alloc_size() const;

  bool is_xs_int() const;
  bool is_xs_integer() const;
  bool is_xs_long() const;

  uint32_t hash() const;

  int sign() const;
  operator explicit_bool::type() const;

  zstring toString( int precision = ZORBA_FLOAT_POINT_PRECISION ) const;

  /////////////////////////////////////////////////////////////////////////////

private:
  typedef MAPM value_type;
  typedef long int_cast_type;

  value_type value_;
  static value_type const round_precision_limit;

  Decimal( value_type const &v ) : value_( v ) { }

  static uint32_t hash( value_type const& );

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

  static zstring toString( value_type const &value,
                           int precision = ZORBA_FLOAT_POINT_PRECISION ) {
    return toString( value, false, precision );
  }

  static zstring toString( value_type const&, bool,
                           int precision = ZORBA_FLOAT_POINT_PRECISION );

  template<class T> friend class IntegerImpl;
  template<typename F> friend class FloatImpl;

  friend xs_long to_xs_long( Decimal const& );
  friend void serialization::operator&( serialization::Archiver&, Decimal& );
};

////////// constructors ///////////////////////////////////////////////////////

#define ZORBA_DECIMAL_CTOR(T) \
  inline Decimal::Decimal( T n ) : value_( static_cast<int_cast_type>( n ) ) { }

ZORBA_DECIMAL_CTOR(char)
ZORBA_DECIMAL_CTOR(signed char)
ZORBA_DECIMAL_CTOR(short)
ZORBA_DECIMAL_CTOR(int)
ZORBA_DECIMAL_CTOR(long)
ZORBA_DECIMAL_CTOR(unsigned char)
ZORBA_DECIMAL_CTOR(unsigned short)
ZORBA_DECIMAL_CTOR(unsigned int)
#undef ZORBA_DECIMAL_CTOR

inline Decimal::Decimal( char const *s ) {
  parse( s, &value_ );
}

template<class StringType>
inline Decimal::Decimal( StringType const &s,
  typename std::enable_if<ZORBA_HAS_C_STR(StringType)>::type* )
{
  parse( s.c_str(), &value_ );
}

inline Decimal::Decimal( Decimal const &d ) : value_( d.value_ )
{
}

////////// assignment operators ///////////////////////////////////////////////

inline Decimal& Decimal::operator=( Decimal const &d ) {
  value_ = d.value_;
  return *this;
}

#define ZORBA_DECIMAL_OP(T)                   \
  inline Decimal& Decimal::operator=( T n ) { \
    value_ = static_cast<int_cast_type>( n ); \
    return *this;                             \
  }

ZORBA_DECIMAL_OP(signed char)
ZORBA_DECIMAL_OP(char)
ZORBA_DECIMAL_OP(short)
ZORBA_DECIMAL_OP(int)
ZORBA_DECIMAL_OP(long)
ZORBA_DECIMAL_OP(unsigned char)
ZORBA_DECIMAL_OP(unsigned short)
ZORBA_DECIMAL_OP(unsigned int)
ZORBA_DECIMAL_OP(unsigned long)
#undef ZORBA_DECIMAL_OP

inline Decimal& Decimal::operator=( char const *s ) {
  parse( s, &value_ );
  return *this;
}

template<class StringType> inline
typename std::enable_if<ZORBA_HAS_C_STR(StringType),Decimal&>::type
Decimal::operator=( StringType const &s ) {
  return operator=( s.c_str() );
}

////////// arithmetic operators ///////////////////////////////////////////////

#define ZORBA_DECIMAL_OP(OP)                                            \
  inline Decimal operator OP( Decimal const &d1, Decimal const &d2 ) {  \
    return d1.value_ OP d2.value_;                                      \
  }

ZORBA_DECIMAL_OP(+)
ZORBA_DECIMAL_OP(-)
ZORBA_DECIMAL_OP(*)
ZORBA_DECIMAL_OP(/)
ZORBA_DECIMAL_OP(%)
#undef ZORBA_DECIMAL_OP

#define ZORBA_DECIMAL_OP(OP)                                  \
  inline Decimal& Decimal::operator OP( Decimal const &d ) {  \
    value_ OP d.value_;                                       \
    return *this;                                             \
  }

ZORBA_DECIMAL_OP(+=)
ZORBA_DECIMAL_OP(-=)
ZORBA_DECIMAL_OP(*=)
ZORBA_DECIMAL_OP(/=)
ZORBA_DECIMAL_OP(%=)
#undef ZORBA_DECIMAL_OP

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

inline bool Decimal::is_xs_int() const {
  return value_.is_integer() &&
         value_ >= MAPM::getMinInt32() && value_ <= MAPM::getMaxInt32();
}

inline bool Decimal::is_xs_integer() const {
  return value_.is_integer() != 0;
}

inline bool Decimal::is_xs_long() const {
  return value_.is_integer() &&
         value_ >= MAPM::getMinInt64() && value_ <= MAPM::getMaxInt64();
}

inline int Decimal::sign() const {
  return value_.sign();
}

inline Decimal::operator internal::ztd::explicit_bool::type() const {
  return explicit_bool::value_of( sign() );
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
