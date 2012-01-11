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
#ifndef ZORBA_INTEGER_H
#define ZORBA_INTEGER_H

#include <cmath>
#include <limits>

#include <zorba/config.h>
#include "common/common.h"

#include "zorbaserialization/archiver.h"
#include "zorbaserialization/zorba_class_serializer.h"

#include "m_apm.h"
#include "schema_types_base.h"
#include "zorbatypes_decl.h"
#include "zstring.h"

namespace zorba {

class Integer;
namespace serialization {
  void operator&(serialization::Archiver&, zorba::Integer&);
}

///////////////////////////////////////////////////////////////////////////////

// exported for testing only
class ZORBA_DLL_PUBLIC Integer {
public:

  ////////// constructors /////////////////////////////////////////////////////

  Integer( char c );
  Integer( signed char c );
  Integer( short n );
  Integer( int n = 0 );
  Integer( long n );
  Integer( long long n );
  Integer( unsigned char c );
  Integer( unsigned short n );
  Integer( unsigned int n );
  Integer( unsigned long n );
  Integer( unsigned long long n );
  Integer( float n );
  Integer( double n );
  Integer( Decimal const &d );
  Integer( Integer const &i );

  /**
   * Constructs an %Integer from a C string.
   *
   * @param s The null-terminated C string to parse.  Leading and trailing
   * whitespace is ignored.
   * @throw std::invalid_argument if \a s does not contain a valid integer.
   * @throw std::range_error if \a s contains an integer that either underflows
   * or overflows the smallest or largest representable integer (only when not
   * compiled with ZORBA_WITH_BIG_INTEGER).
   */
  Integer( char const *s );

  /**
   * Constructs an %Integer from a Double.
   *
   * @param d The Double.
   * @throw std::invalid_argument if \a d is not finite.
   */
  Integer( Double const &d );

  /**
   * Constructs an %Integer from a Float.
   *
   * @param f The Float.
   * @throw std::invalid_argument if \a f is not finite.
   */
  Integer( Float const &f );

  ////////// assignment operators /////////////////////////////////////////////

  Integer& operator=( char c );
  Integer& operator=( signed char c );
  Integer& operator=( short n );
  Integer& operator=( int n );
  Integer& operator=( long n );
  Integer& operator=( long long n );
  Integer& operator=( unsigned char c );
  Integer& operator=( unsigned short n );
  Integer& operator=( unsigned int n );
  Integer& operator=( unsigned long n );
  Integer& operator=( unsigned long long n );
  Integer& operator=( float n );
  Integer& operator=( double n );
  Integer& operator=( char const *s );
  Integer& operator=( Decimal const &d );
  Integer& operator=( Double const &d );
  Integer& operator=( Float const &f );
  Integer& operator=( Integer const &i );

  ////////// arithmetic operators /////////////////////////////////////////////

  friend Integer operator+( Integer const &i, Integer const &j );
  friend Integer operator-( Integer const &i, Integer const &j );
  friend Integer operator*( Integer const &i, Integer const &j );
  friend Integer operator/( Integer const &i, Integer const &j );
  friend Integer operator%( Integer const &i, Integer const &j );

  friend Decimal operator+( Integer const &i, Decimal const &d );
  friend Decimal operator-( Integer const &i, Decimal const &d );
  friend Decimal operator*( Integer const &i, Decimal const &d );
  friend Decimal operator/( Integer const &i, Decimal const &d );
  friend Decimal operator%( Integer const &i, Decimal const &d );

  friend Decimal operator+( Decimal const &d, Integer const &i );
  friend Decimal operator-( Decimal const &d, Integer const &i );
  friend Decimal operator*( Decimal const &d, Integer const &i );
  friend Decimal operator/( Decimal const &d, Integer const &i );
  friend Decimal operator%( Decimal const &d, Integer const &i );

  Integer& operator+=( Integer const &i );
  Integer& operator-=( Integer const &i );
  Integer& operator*=( Integer const &i );
  Integer& operator/=( Integer const &i );
  Integer& operator%=( Integer const &i );

  Integer operator-() const;

  Integer& operator++();
  Integer  operator++(int);
  Integer& operator--();
  Integer  operator--(int);

  ////////// relational operators /////////////////////////////////////////////

  friend bool operator==( Integer const &i, Integer const &j );
  friend bool operator!=( Integer const &i, Integer const &j );
  friend bool operator< ( Integer const &i, Integer const &j );
  friend bool operator<=( Integer const &i, Integer const &j );
  friend bool operator> ( Integer const &i, Integer const &j );
  friend bool operator>=( Integer const &i, Integer const &j );

  friend bool operator==( Integer const &i, Decimal const &d );
  friend bool operator!=( Integer const &i, Decimal const &d );
  friend bool operator< ( Integer const &i, Decimal const &d );
  friend bool operator<=( Integer const &i, Decimal const &d );
  friend bool operator> ( Integer const &i, Decimal const &d );
  friend bool operator>=( Integer const &i, Decimal const &d );

  friend bool operator==( Decimal const &d, Integer const &i );
  friend bool operator!=( Decimal const &d, Integer const &i );
  friend bool operator< ( Decimal const &d, Integer const &i );
  friend bool operator<=( Decimal const &d, Integer const &i );
  friend bool operator> ( Decimal const &d, Integer const &i );
  friend bool operator>=( Decimal const &d, Integer const &i );

  ////////// math functions ///////////////////////////////////////////////////

  Double pow( Integer const &power ) const;
  Integer round( Integer const &precision ) const;
  Integer roundHalfToEven( Integer const &precision ) const;

  ////////// miscellaneous ////////////////////////////////////////////////////

  int compare( Integer const &i ) const;
  uint32_t hash() const;
  int sign() const;
  zstring toString() const;
  static Integer const& one();
  static Integer const& zero();

  /////////////////////////////////////////////////////////////////////////////

private:
#ifdef ZORBA_WITH_BIG_INTEGER
  typedef MAPM value_type;
#else
  typedef long long value_type;
#endif /* ZORBA_WITH_BIG_INTEGER */

  value_type value_;

#ifdef ZORBA_WITH_BIG_INTEGER
  Integer( value_type const &v ) : value_( v ) { }
#endif /* ZORBA_WITH_BIG_INTEGER */

  static value_type ftoi( double d ) {
    return value_type( d >= 0 ? floor( d ) : ceil( d ) );
  }

#ifdef ZORBA_WITH_BIG_INTEGER
  static value_type ftoi( MAPM const &d ) {
    return d.sign() >= 0 ? d.floor() : d.ceil();
  }

  MAPM const& itod() const {
    return value_;                      // intentional no-op
  }
#else
  bool is_long() const;

  static value_type ftoi( value_type v ) {
    return v;                           // intentional no-op
  }

  static value_type ftoi( MAPM const &d );

  MAPM itod() const;
#endif /* ZORBA_WITH_BIG_INTEGER */

  void parse( char const *s );

  friend class Decimal;
  template<typename T> friend class FloatImpl;

  friend xs_int to_xs_int( Integer const& );
  friend xs_long to_xs_long( Integer const& );
  friend xs_unsignedInt to_xs_unsignedInt( Integer const& );
  friend xs_unsignedLong to_xs_unsignedLong( Integer const& );

  friend void serialization::operator&(serialization::Archiver&, Integer&);
};

////////// constructors ///////////////////////////////////////////////////////

inline Integer::Integer( char c ) : value_( static_cast<long>( c ) ) {
}

inline Integer::Integer( signed char c ) : value_( static_cast<long>( c ) ) {
}

inline Integer::Integer( short n ) : value_( static_cast<long>( n ) ) {
}

inline Integer::Integer( int n ) : value_( static_cast<long>( n ) ) {
}

inline Integer::Integer( long n ) : value_( n ) {
}

#ifndef ZORBA_WITH_BIG_INTEGER
inline Integer::Integer( long long n ) : value_( n ) {
}
#endif /* ZORBA_WITH_BIG_INTEGER */

inline Integer::Integer( unsigned char c ) : value_( static_cast<long>( c ) ) {
}

inline Integer::Integer( unsigned short n ) : value_( static_cast<long>( n ) ) {
}

inline Integer::Integer( unsigned int n ) : value_( static_cast<long>( n ) ) {
}

#ifndef ZORBA_WITH_BIG_INTEGER
inline Integer::Integer( unsigned long n ) :
  value_( static_cast<value_type>( n ) )
{
}

inline Integer::Integer( unsigned long long n ) :
  value_( static_cast<value_type>( n ) )
{
}
#endif /* ZORBA_WITH_BIG_INTEGER */

inline Integer::Integer( float n ) :
#ifdef ZORBA_WITH_BIG_INTEGER
  value_( static_cast<double>( n ) )
#else
  value_( static_cast<value_type>( n ) )
#endif /* ZORBA_WITH_BIG_INTEGER */
{
}

inline Integer::Integer( double n ) :
#ifdef ZORBA_WITH_BIG_INTEGER
  value_( n )
#else
  value_( static_cast<value_type>( n ) )
#endif /* ZORBA_WITH_BIG_INTEGER */
{
}

inline Integer::Integer( char const *s ) {
  parse( s );
}

inline Integer::Integer( Integer const &i ) :
  value_( i.value_ )
{
}

////////// assignment operators ///////////////////////////////////////////////

inline Integer& Integer::operator=( char c ) {
  value_ = static_cast<long>( c );
  return *this;
}

inline Integer& Integer::operator=( signed char c ) {
  value_ = static_cast<long>( c );
  return *this;
}

inline Integer& Integer::operator=( short n ) {
  value_ = static_cast<long>( n );
  return *this;
}

inline Integer& Integer::operator=( int n ) {
  value_ = static_cast<long>( n );
  return *this;
}

inline Integer& Integer::operator=( long n ) {
  value_ = n;
  return *this;
}

#ifndef ZORBA_WITH_BIG_INTEGER
inline Integer& Integer::operator=( long long n ) {
  value_ = n;
  return *this;
}
#endif /* ZORBA_WITH_BIG_INTEGER */

inline Integer& Integer::operator=( unsigned char c ) {
  value_ = static_cast<long>( c );
  return *this;
}

inline Integer& Integer::operator=( unsigned short n ) {
  value_ = static_cast<long>( n );
  return *this;
}

inline Integer& Integer::operator=( unsigned int n ) {
  value_ = static_cast<long>( n );
  return *this;
}

#ifndef ZORBA_WITH_BIG_INTEGER
inline Integer& Integer::operator=( unsigned long n ) {
  value_ = static_cast<long>( n );
  return *this;
}

inline Integer& Integer::operator=( unsigned long long n ) {
  value_ = n;
  return *this;
}
#endif /* ZORBA_WITH_BIG_INTEGER */

inline Integer& Integer::operator=( float n ) {
  value_ = static_cast<long>( n );
  return *this;
}

inline Integer& Integer::operator=( double n ) {
  value_ = static_cast<long>( n );
  return *this;
}

inline Integer& Integer::operator=( char const *s ) {
  parse( s );
  return *this;
}

inline Integer& Integer::operator=( Integer const &i ) {
  value_ = i.value_;
  return *this;
}

////////// arithmetic operators ///////////////////////////////////////////////

inline Integer operator+( Integer const &i, Integer const &j ) {
  return i.value_ + j.value_;
}

inline Integer operator-( Integer const &i, Integer const &j ) {
  return i.value_ - j.value_;
}

inline Integer operator*( Integer const &i, Integer const &j ) {
  return i.value_ * j.value_;
}

inline Integer operator/( Integer const &i, Integer const &j ) {
  return Integer::ftoi( i.value_ / j.value_ );
}

inline Integer operator%( Integer const &i, Integer const &j ) {
  return i.value_ % j.value_;
}

inline Integer& Integer::operator+=( Integer const &i ) {
  value_ += i.value_;
  return *this;
}

inline Integer& Integer::operator-=( Integer const &i ) {
  value_ -= i.value_;
  return *this;
}

inline Integer& Integer::operator*=( Integer const &i ) {
  value_ *= i.value_;
  return *this;
}

inline Integer& Integer::operator/=( Integer const &i ) {
  value_ = ftoi( value_ / i.value_ );
  return *this;
}

inline Integer& Integer::operator%=( Integer const &i ) {
  value_ %= i.value_;
  return *this;
}

inline Integer Integer::operator-() const {
  return -value_;
}

inline Integer& Integer::operator++() {
  ++value_;
  return *this;
}

inline Integer Integer::operator++(int) {
  Integer const result( *this );
  ++value_;
  return result;
}

inline Integer& Integer::operator--() {
  --value_;
  return *this;
}

inline Integer Integer::operator--(int) {
  Integer const result( *this );
  --value_;
  return result;
}

////////// relational operators ///////////////////////////////////////////////

inline bool operator==( Integer const &i, Integer const &j ) {
  return i.value_ == j.value_;
}

inline bool operator!=( Integer const &i, Integer const &j ) {
  return i.value_ != j.value_;
}

inline bool operator<( Integer const &i, Integer const &j ) {
  return i.value_ < j.value_;
}

inline bool operator<=( Integer const &i, Integer const &j ) {
  return i.value_ <= j.value_;
}

inline bool operator>( Integer const &i, Integer const &j ) {
  return i.value_ > j.value_;
}

inline bool operator>=( Integer const &i, Integer const &j ) {
  return i.value_ >= j.value_;
}

////////// miscellaneous //////////////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER

inline int Integer::compare( Integer const &i ) const {
  return value_.compare( i.value_ );
}

inline int Integer::sign() const {
  return value_.sign();
}

#else

inline int Integer::compare( Integer const &i ) const {
  //
  // Note that we can't return the difference directly since it will be
  // truncated if it's ether > max(int) or < min(int) yielding a wrong result.
  //
  value_type const temp = value_ - i.value_;
  return temp < 0 ? -1 : temp > 0 ? 1 : 0;
}

inline uint32_t Integer::hash() const {
  return static_cast<uint32_t>( value_ );
}

inline bool Integer::is_long() const {
  return  value_ >= std::numeric_limits<long>::min() &&
          value_ <= std::numeric_limits<long>::max();
}

inline int Integer::sign() const {
  return value_ < 0 ? -1 : value_ > 0 ? 1 : 0;
}

#endif /* ZORBA_WITH_BIG_INTEGER */

inline std::ostream& operator<<( std::ostream &os, Integer const &i ) {
  return os << i.toString();
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif // ZORBA_INTEGER_H
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
