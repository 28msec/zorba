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

#include <cstdlib>

#include "util/ascii_util.h"
#include "util/cxx_util.h"
#include "util/string_util.h"
#include "zorbaserialization/zorba_class_serializer.h"

#include "integer.h"
#include "decimal.h"
#include "floatimpl.h"
#include "numconversions.h"

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(Integer)
END_SERIALIZABLE_CLASS_VERSIONS(Integer)

///////////////////////////////////////////////////////////////////////////////

#ifdef ZORBA_NUMERIC_OPTIMIZATION
HashCharPtrObjPtrLimited<Integer> Integer::parsed_integers;
#endif

///////////////////////////////////////////////////////////////////////////////

void Integer::parse( char const *s, bool allow_negative ) {
#ifdef ZORBA_NUMERIC_OPTIMIZATION
  Integer *hashed_integer;
  if( parsed_integers.get( s, hashed_integer ) ) {
    value_ = hashed_integer->value_;
    return;
  }
#endif /* ZORBA_NUMERIC_OPTIMIZATION */

  if ( !*s )
    throw std::invalid_argument( "empty string" );

#ifndef ZORBA_NO_BIGNUMBERS
  while ( ascii::is_space( *s ) )
    ++s;
  char const *const first_non_ws = s;
  if ( *s == '+' || (allow_negative && *s == '-') )
    ++s;
  while ( ascii::is_digit( *s ) )
    ++s;
  char const *first_trailing_ws = nullptr;
  while ( ascii::is_space( *s ) ) {
    if ( !first_trailing_ws )
      first_trailing_ws = s;
    ++s;
  }
  if ( *s )
    throw std::invalid_argument(
      BUILD_STRING( '"', *s, "\": invalid character" )
    );

  char const *s_ok;
  if ( first_trailing_ws ) {
    ptrdiff_t const size = first_trailing_ws - first_non_ws;
    char *const copy = std::strncpy( new char[ size ], first_non_ws, size );
    copy[ size - 1 ] = '\0';
    s_ok = copy;
  } else
    s_ok = first_non_ws;

  value_ = s_ok;
#else
  char *end;
  value_ = std::strtol( s, &end, 10 );
  if ( *end )
    throw std::invalid_argument(
      BUILD_STRING( '"', *end, "\": invalid character" )
    );
#endif /* ZORBA_NO_BIGNUMBERS */

#ifdef ZORBA_NUMERIC_OPTIMIZATION
  hashed_integer = new Integer( aInteger );
  const char *const dup_str = _strdup( s_ok );
  parsed_integers.insert( dup_str, hashed_integer );
#endif /* ZORBA_NUMERIC_OPTIMIZATION */
  if ( first_trailing_ws )
    delete[] s_ok;
}

void Integer::serialize( serialization::Archiver &ar ) {
  ar & value_;
}

////////// constructors ///////////////////////////////////////////////////////

#ifndef ZORBA_NO_BIGNUMBERS
Integer::Integer( long long n ) {
  zstring const temp( NumConversions::longToStr( n ) );
  value_ = temp.c_str();
}

Integer::Integer( unsigned long long n ) {
  zstring const temp( NumConversions::longToStr( n ) );
  value_ = temp.c_str();
}
#endif /* ZORBA_NO_BIGNUMBERS */

Integer::Integer( Decimal const &d ) {
  value_ = ftoi( d.value_ );
}

Integer::Integer( Double const &d ) {
  if ( !d.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( d.theFloating );
}

Integer::Integer( Float const &f ) {
  if ( !f.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( f.theFloating );
}

////////// assignment operators ///////////////////////////////////////////////

#ifndef ZORBA_NO_BIGNUMBERS
Integer& Integer::operator=( long long n ) {
  zstring const temp( NumConversions::longToStr( n ) );
  value_ = temp.c_str();
  return *this;
}

Integer& Integer::operator=( unsigned long n ) {
  zstring const temp( NumConversions::ulongToStr( n ) );
  value_ = temp.c_str();
  return *this;
}

Integer& Integer::operator=( unsigned long long n ) {
  zstring const temp( NumConversions::longToStr( n ) );
  value_ = temp.c_str();
  return *this;
}
#endif /* ZORBA_NO_BIGNUMBERS */

Integer& Integer::operator=( Decimal const &d ) {
  value_ = ftoi( d.value_ );
  return *this;
}

Integer& Integer::operator=( Double const &d ) {
  if ( !d.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( d.theFloating );
  return *this;
}

Integer& Integer::operator=( Float const &f ) {
  if ( !f.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( f.theFloating );
  return *this;
}

////////// arithmetic operators ///////////////////////////////////////////////

Decimal operator+( Integer const &i, Decimal const &d ) {
  return Decimal( i.value_ + d.value_ );
}

Decimal operator-( Integer const &i, Decimal const &d ) {
  return Decimal( i.value_ - d.value_ );
}

Decimal operator*( Integer const &i, Decimal const &d ) {
  return Decimal( i.value_ * d.value_ );
}

Decimal operator/( Integer const &i, Decimal const &d ) {
  return Decimal( (Integer::double_type)i.value_ / d.value_ );
}

Decimal operator%( Integer const &i, Decimal const &d ) {
  return Decimal( i.value_ % (Integer::value_type)d.value_ );
}

////////// relational operators ///////////////////////////////////////////////

bool operator==( Integer const &i, Decimal const &d ) {
  return i.value_ == d.value_;
}

bool operator!=( Integer const &i, Decimal const &d ) {
  return i.value_ != d.value_;
}

bool operator<( Integer const &i, Decimal const &d ) {
  return i.value_ < d.value_;
}

bool operator<=( Integer const &i, Decimal const &d ) {
  return i.value_ <= d.value_;
}

bool operator>( Integer const &i, Decimal const &d ) {
  return i.value_ > d.value_;
}

bool operator>=( Integer const &i, Decimal const &d ) {
  return i.value_ >= d.value_;
}

////////// math functions /////////////////////////////////////////////////////

#ifndef ZORBA_NO_BIGNUMBERS

Double Integer::pow( Integer const &power ) const {
  double_type const result( value_.pow( power.value_, 15 ) );
  char buf[300];
  result.toFixPtString( buf, 15 );
  xs_double double_result;
  xs_double::parseString( buf, double_result );
  return double_result;
}

Integer Integer::round( Integer const &precision ) const {
  return Integer( Decimal::round( value_, precision.value_ ) );
}

Integer Integer::roundHalfToEven( Integer const &precision ) const {
  return Integer( Decimal::roundHalfToEven( value_, precision.value_ ) );
}

#else

Double Integer::pow( Integer power ) const {
  return Double( std::pow( value_, power.value_ ) );
}

Integer Integer::round( Integer precision ) const {
  return Integer( Decimal::round( value_, precision.value_ ) );
}

Integer Integer::roundHalfToEven( Integer precision ) const {
  return Integer( Decimal::roundHalfToEven( value_, precision.value_ ) );
}

#endif /* ZORBA_NO_BIGNUMBERS */

////////// miscellaneous //////////////////////////////////////////////////////

#ifndef ZORBA_NO_BIGNUMBERS
uint32_t Integer::hash() const {
  return Decimal::hash( value_ );
}
#endif /* ZORBA_NO_BIGNUMBERS */

zstring Integer::toString() const {
#ifndef ZORBA_NO_BIGNUMBERS
  char *buf = new char[ value_.exponent() + 3 ];
  value_.toIntegerString( buf );
  zstring const s( buf );
  delete[] buf;
  return s;
#else
  char buf[ 128 ];
  sprintf( buf, "%d", value_ );
  return buf;
#endif /* ZORBA_NO_BIGNUMBERS */
}

#ifndef ZORBA_NO_BIGNUMBERS
Integer const& Integer::one() {
  static Integer const i(1);
  return i;
}

Integer const& Integer::zero() {
  static Integer const i(0);
  return i;
}
#endif /* ZORBA_NO_BIGNUMBERS */

std::ostream& operator<<( std::ostream &os, Integer const &i ) {
  return os << i.toString();
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
