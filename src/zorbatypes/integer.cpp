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

#include "stdafx.h"

#include <cerrno>
#include <cstdlib>

#include "util/cxx_util.h"
#include "util/string_util.h"

#include "integer.h"
#include "decimal.h"
#include "floatimpl.h"
#include "numconversions.h"

using namespace std;

#ifdef WIN32
namespace std {
  inline long long strtoll( char const *s, char **end, int base ) {
    return ::_strtoi64( s, end, base );
  }

  inline long long strtoull( char const *s, char **end, int base ) {
    return ::_strtoui64( s, end, base );
  }
}
#endif /* WIN32 */

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

void Integer::parse( char const *s ) {
#ifdef ZORBA_WITH_BIG_INTEGER
  Decimal::parse( s, &value_, Decimal::parse_integer );
#else
  value_ = ztd::aton<value_type>( s );
#endif /* ZORBA_WITH_BIG_INTEGER */
}

////////// constructors ///////////////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
Integer::Integer( long long n ) {
  ztd::itoa_buf_type buf;
  value_ = ztd::itoa( n, buf );
}

Integer::Integer( unsigned long n ) {
  ztd::itoa_buf_type buf;
  value_ = ztd::itoa( n, buf );
}

Integer::Integer( unsigned long long n ) {
  ztd::itoa_buf_type buf;
  value_ = ztd::itoa( n, buf );
}
#endif /* ZORBA_WITH_BIG_INTEGER */

Integer::Integer( Decimal const &d ) {
  value_ = ftoi( d.value_ );
}

Integer::Integer( Double const &d ) {
  if ( !d.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( d.getNumber() );
}

Integer::Integer( Float const &f ) {
  if ( !f.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( f.getNumber() );
}

////////// assignment operators ///////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
Integer& Integer::operator=( long long n ) {
  ztd::itoa_buf_type buf;
  value_ = ztd::itoa( n, buf );
  return *this;
}

Integer& Integer::operator=( unsigned long n ) {
  ztd::itoa_buf_type buf;
  value_ = ztd::itoa( n, buf );
  return *this;
}

Integer& Integer::operator=( unsigned long long n ) {
  ztd::itoa_buf_type buf;
  value_ = ztd::itoa( n, buf );
  return *this;
}
#endif /* ZORBA_WITH_BIG_INTEGER */

Integer& Integer::operator=( Decimal const &d ) {
  value_ = ftoi( d.value_ );
  return *this;
}

Integer& Integer::operator=( Double const &d ) {
  if ( !d.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( d.getNumber() );
  return *this;
}

Integer& Integer::operator=( Float const &f ) {
  if ( !f.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( f.getNumber() );
  return *this;
}

////////// arithmetic operators ///////////////////////////////////////////////

Decimal operator+( Integer const &i, Decimal const &d ) {
  return i.itod() + d.value_;
}

Decimal operator-( Integer const &i, Decimal const &d ) {
  return i.itod() - d.value_;
}

Decimal operator*( Integer const &i, Decimal const &d ) {
  return i.itod() * d.value_;
}

Decimal operator/( Integer const &i, Decimal const &d ) {
  return i.itod() / d.value_;
}

Decimal operator%( Integer const &i, Decimal const &d ) {
  return i.itod() % d.value_;
}

////////// relational operators ///////////////////////////////////////////////

bool operator==( Integer const &i, Decimal const &d ) {
  return d.is_integer() && i.itod() == d.value_;
}

bool operator!=( Integer const &i, Decimal const &d ) {
  return i.itod() != d.value_;
}

bool operator<( Integer const &i, Decimal const &d ) {
  return i.itod() < d.value_;
}

bool operator<=( Integer const &i, Decimal const &d ) {
  return i.itod() <= d.value_;
}

bool operator>( Integer const &i, Decimal const &d ) {
  return i.itod() > d.value_;
}

bool operator>=( Integer const &i, Decimal const &d ) {
  return i.itod() >= d.value_;
}

////////// math functions /////////////////////////////////////////////////////

Double Integer::pow( Integer const &power ) const {
#ifdef ZORBA_WITH_BIG_INTEGER
  value_type const result( value_.pow( power.value_, 15 ) );
  char buf[300];
  result.toFixPtString( buf, 15 );
  return Double( buf );
#else
  return Double(
    // The casts are needed for disambiguation with MSVC++.
    ::pow( static_cast<double>( value_ ), static_cast<double>( power.value_ ) )
  );
#endif /* ZORBA_WITH_BIG_INTEGER */
}

Integer Integer::round( Integer const &precision ) const {
  return Integer( Decimal::round( itod(), precision.itod() ) );
}

Integer Integer::roundHalfToEven( Integer const &precision ) const {
  return Integer( Decimal::roundHalfToEven( itod(), precision.itod() ) );
}

////////// miscellaneous //////////////////////////////////////////////////////

#ifndef ZORBA_WITH_BIG_INTEGER
Integer::value_type Integer::ftoi( MAPM const &d ) {
  MAPM const temp( d.sign() >= 0 ? d.floor() : d.ceil() );
  char *const buf = new char[ temp.exponent() + 3 ];
  temp.toIntegerString( buf );
  value_type const result( std::strtoll( buf, nullptr, 10 ) );
  delete[] buf;
  return result;
}

MAPM Integer::itod() const {
  if ( is_long() )
    return static_cast<long>( value_ );
  ztd::itoa_buf_type buf;
  return ztd::itoa( value_, buf );
}
#endif /* ZORBA_WITH_BIG_INTEGER */

#ifdef ZORBA_WITH_BIG_INTEGER
uint32_t Integer::hash() const {
  return Decimal::hash( value_ );
}
#endif /* ZORBA_WITH_BIG_INTEGER */

Integer const& Integer::one() {
  static Integer const i(1);
  return i;
}

zstring Integer::toString() const {
#ifdef ZORBA_WITH_BIG_INTEGER
  char *const buf = new char[ value_.exponent() + 3 ];
  value_.toIntegerString( buf );
  zstring const result( buf );
  delete[] buf;
  return result;
#else
  ztd::itoa_buf_type buf;
  return ztd::itoa( value_, buf );
#endif /* ZORBA_WITH_BIG_INTEGER */
}

Integer const& Integer::zero() {
  static Integer const i(0);
  return i;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
