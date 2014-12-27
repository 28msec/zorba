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

// standard
#include <cerrno>
#include <cstdlib>

// Zorba
#include <zorba/internal/cxx_util.h>
#include <zorba/internal/unique_ptr.h>
#include "util/string_util.h"

// local
#include "decimal.h"
#include "float.h"
#include "integer.h"
#include "numconversions.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

void integer_traits::throw_error( MAPM const &n, char const *op ) {
  unique_ptr<char[]> const buf( new char[ n.exponent() + 3 ] );
  n.toIntegerString( buf.get() );
  string const what( BUILD_STRING( buf.get(), ": not ", op, " 0" ) );
  throw range_error( what );
}

///////////////////////////////////////////////////////////////////////////////

#ifndef ZORBA_WITH_BIG_INTEGER
template<class T>
typename IntegerImpl<T>::value_type IntegerImpl<T>::ftoi( double d ) {
  d = d >= 0 ? floor( d ) : ceil( d );
  value_type const i = static_cast<value_type>(d);
  if ( i != d )
    throw range_error(
      BUILD_STRING( '"', d, "\": value too large/small for integer" )
    );
  return i;
}
#endif /* ZORBA_WITH_BIG_INTEGER */

template<class T>
void IntegerImpl<T>::parse( char const *s ) {
  try {
#ifdef ZORBA_WITH_BIG_INTEGER
    Decimal::parse( s, &value_, Decimal::parse_integer );
#else
    value_ = ztd::aton<value_type>( s );
#endif /* ZORBA_WITH_BIG_INTEGER */
  }
  catch ( invalid_argument const &e ) {
    throw range_error( e.what() );
  }
  T::check_value( value_ );
}

////////// constructors ///////////////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
template<class T>
IntegerImpl<T>::IntegerImpl( long long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  T::check_value( value_ );
}

#if ZORBA_SIZEOF_INT == ZORBA_SIZEOF_LONG
template<class T>
IntegerImpl<T>::IntegerImpl( unsigned int n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  T::check_value( value_ );
}
#endif /* ZORBA_SIZEOF_INT == ZORBA_SIZEOF_LONG */

template<class T>
IntegerImpl<T>::IntegerImpl( unsigned long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  T::check_value( value_ );
}

template<class T>
IntegerImpl<T>::IntegerImpl( unsigned long long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  T::check_value( value_ );
}
#endif /* ZORBA_WITH_BIG_INTEGER */

template<class T>
IntegerImpl<T>::IntegerImpl( Decimal const &d ) {
  value_ = T::check_value( ftoi( d.value_ ) );
}

template<class T>
IntegerImpl<T>::IntegerImpl( Double const &d ) {
  if ( !d.isFinite() )
    throw invalid_argument( "not finite" );
  value_ = T::check_value( ftoi( d.getNumber() ) );
}

template<class T>
IntegerImpl<T>::IntegerImpl( Float const &f ) {
  if ( !f.isFinite() )
    throw invalid_argument( "not finite" );
  value_ = T::check_value( ftoi( f.getNumber() ) );
}

////////// assignment operators ///////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
template<class T>
IntegerImpl<T>& IntegerImpl<T>::operator=( long long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  T::check_value( value_ );
  return *this;
}

template<class T>
IntegerImpl<T>& IntegerImpl<T>::operator=( unsigned long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  T::check_value( value_ );
  return *this;
}

template<class T>
IntegerImpl<T>& IntegerImpl<T>::operator=( unsigned long long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  T::check_value( value_ );
  return *this;
}
#endif /* ZORBA_WITH_BIG_INTEGER */

template<class T>
IntegerImpl<T>& IntegerImpl<T>::operator=( Decimal const &d ) {
  value_ = T::check_value( ftoi( d.value_ ) );
  return *this;
}

template<class T>
IntegerImpl<T>& IntegerImpl<T>::operator=( Double const &d ) {
  if ( !d.isFinite() )
    throw invalid_argument( "not finite" );
  value_ = T::check_value( ftoi( d.getNumber() ) );
  return *this;
}

template<class T>
IntegerImpl<T>& IntegerImpl<T>::operator=( Float const &f ) {
  if ( !f.isFinite() )
    throw invalid_argument( "not finite" );
  value_ = T::check_value( ftoi( f.getNumber() ) );
  return *this;
}

////////// arithmetic operators ///////////////////////////////////////////////

#define ZORBA_INSTANTIATE(OP,I) \
  template Decimal operator OP( I const&, Decimal const& );

#define ZORBA_INTEGER_OP(OP)                                          \
  template<class T>                                                   \
  Decimal operator OP( IntegerImpl<T> const &i, Decimal const &d ) {  \
    return i.itod() OP d.value_;                                      \
  }                                                                   \
  ZORBA_INSTANTIATE( OP, Integer );                                   \
  ZORBA_INSTANTIATE( OP, NegativeInteger );                           \
  ZORBA_INSTANTIATE( OP, NonNegativeInteger );                        \
  ZORBA_INSTANTIATE( OP, NonPositiveInteger );                        \
  ZORBA_INSTANTIATE( OP, PositiveInteger );

ZORBA_INTEGER_OP(+)
ZORBA_INTEGER_OP(-)
ZORBA_INTEGER_OP(*)
ZORBA_INTEGER_OP(/)
ZORBA_INTEGER_OP(%)
#undef ZORBA_INTEGER_OP
#undef ZORBA_INSTANTIATE

#ifdef ZORBA_WITH_BIG_INTEGER

#define ZORBA_INSTANTIATE(OP,I,N)               \
  template Integer operator OP( I const&, N );  \
  template Integer operator OP( N, I const& )

#define ZORBA_INTEGER_OP(OP,N)                          \
  template<class T>                                     \
  Integer operator OP( IntegerImpl<T> const &i, N n ) { \
    ascii::itoa_buf_type buf;                           \
    return i.value_ OP MAPM( ascii::itoa( n, buf ) );   \
  }                                                     \
  template<class T>                                     \
  Integer operator OP( N n, IntegerImpl<T> const &i ) { \
    ascii::itoa_buf_type buf;                           \
    return MAPM( ascii::itoa( n, buf ) ) OP i.value_;   \
  }                                                     \
  ZORBA_INSTANTIATE( OP, Integer, N );                  \
  ZORBA_INSTANTIATE( OP, NegativeInteger, N );          \
  ZORBA_INSTANTIATE( OP, NonNegativeInteger, N );       \
  ZORBA_INSTANTIATE( OP, NonPositiveInteger, N );       \
  ZORBA_INSTANTIATE( OP, PositiveInteger, N );

ZORBA_INTEGER_OP(+,long long)
ZORBA_INTEGER_OP(-,long long)
ZORBA_INTEGER_OP(*,long long)
ZORBA_INTEGER_OP(%,long long)
ZORBA_INTEGER_OP(+,unsigned long)
ZORBA_INTEGER_OP(-,unsigned long)
ZORBA_INTEGER_OP(*,unsigned long)
ZORBA_INTEGER_OP(%,unsigned long)
ZORBA_INTEGER_OP(+,unsigned long long)
ZORBA_INTEGER_OP(-,unsigned long long)
ZORBA_INTEGER_OP(*,unsigned long long)
ZORBA_INTEGER_OP(%,unsigned long long)
#undef ZORBA_INTEGER_OP
#undef ZORBA_INSTANTIATE

#define ZORBA_INSTANTIATE(I,N)                \
  template Integer operator/( I const&, N );  \
  template Integer operator/( N, I const& )

#define ZORBA_INTEGER_OP(N)                           \
  template<class T>                                   \
  Integer operator/( IntegerImpl<T> const &i, N n ) { \
    ascii::itoa_buf_type buf;                         \
    MAPM const temp( ascii::itoa( n, buf ) );         \
    return Integer::ftoi( i.value_ / temp );          \
  }                                                   \
  template<class T>                                   \
  Integer operator/( N n, IntegerImpl<T> const &i ) { \
    ascii::itoa_buf_type buf;                         \
    MAPM const temp( ascii::itoa( n, buf ) );         \
    return Integer::ftoi( temp / i.value_ );          \
  }                                                   \
  ZORBA_INSTANTIATE( Integer, N );                    \
  ZORBA_INSTANTIATE( NegativeInteger, N );            \
  ZORBA_INSTANTIATE( NonNegativeInteger, N );         \
  ZORBA_INSTANTIATE( NonPositiveInteger, N );         \
  ZORBA_INSTANTIATE( PositiveInteger, N );

ZORBA_INTEGER_OP(long long)
ZORBA_INTEGER_OP(unsigned long)
ZORBA_INTEGER_OP(unsigned long long)
#undef ZORBA_INTEGER_OP
#undef ZORBA_INSTANTIATE

#define ZORBA_INTEGER_OP(OP,N)                          \
  template<class T>                                     \
  IntegerImpl<T>& IntegerImpl<T>::operator OP( N n ) {  \
    ascii::itoa_buf_type buf;                           \
    value_type const temp( ascii::itoa( n, buf ) );     \
    T::check_value( value_ OP temp );                   \
    return *this;                                       \
  }

ZORBA_INTEGER_OP(+=,long long)
ZORBA_INTEGER_OP(-=,long long)
ZORBA_INTEGER_OP(*=,long long)
ZORBA_INTEGER_OP(%=,long long)
ZORBA_INTEGER_OP(+=,unsigned long)
ZORBA_INTEGER_OP(-=,unsigned long)
ZORBA_INTEGER_OP(*=,unsigned long)
ZORBA_INTEGER_OP(%=,unsigned long)
ZORBA_INTEGER_OP(+=,unsigned long long)
ZORBA_INTEGER_OP(-=,unsigned long long)
ZORBA_INTEGER_OP(*=,unsigned long long)
ZORBA_INTEGER_OP(%=,unsigned long long)
#undef ZORBA_INTEGER_OP

#define ZORBA_INTEGER_OP(N) \
  template<class T>                                   \
  IntegerImpl<T>& IntegerImpl<T>::operator/=( N n ) { \
    ascii::itoa_buf_type buf;                         \
    value_type const temp( ascii::itoa( n, buf ) );   \
    T::check_value( value_ = ftoi( value_ / temp ) ); \
    return *this;                                     \
  }

ZORBA_INTEGER_OP(long long)
ZORBA_INTEGER_OP(unsigned long)
ZORBA_INTEGER_OP(unsigned long long)
#undef ZORBA_INTEGER_OP
#endif /* ZORBA_WITH_BIG_INTEGER */

////////// relational operators ///////////////////////////////////////////////

#define ZORBA_INSTANTIATE(OP,I) \
  template bool operator OP( I const&, Decimal const& )

template<class T>
bool operator==( IntegerImpl<T> const &i, Decimal const &d ) {
  return d.is_xs_integer() && i.itod() == d.value_;
}

ZORBA_INSTANTIATE( ==, Integer );
ZORBA_INSTANTIATE( ==, NegativeInteger );
ZORBA_INSTANTIATE( ==, NonNegativeInteger );
ZORBA_INSTANTIATE( ==, NonPositiveInteger );
ZORBA_INSTANTIATE( ==, PositiveInteger );

#define ZORBA_INTEGER_OP(OP)                                      \
  template<class T>                                               \
  bool operator OP( IntegerImpl<T> const &i, Decimal const &d ) { \
    return i.itod() OP d.value_;                                  \
  }                                                               \
  ZORBA_INSTANTIATE( OP, Integer );                               \
  ZORBA_INSTANTIATE( OP, NegativeInteger );                       \
  ZORBA_INSTANTIATE( OP, NonNegativeInteger );                    \
  ZORBA_INSTANTIATE( OP, NonPositiveInteger );                    \
  ZORBA_INSTANTIATE( OP, PositiveInteger );

ZORBA_INTEGER_OP(!=)
ZORBA_INTEGER_OP(< )
ZORBA_INTEGER_OP(<=)
ZORBA_INTEGER_OP(> )
ZORBA_INTEGER_OP(>=)
#undef ZORBA_INSTANTIATE
#undef ZORBA_INTEGER_OP

#ifdef ZORBA_WITH_BIG_INTEGER

#define ZORBA_INSTANTIATE(OP,I,N)           \
  template bool operator OP( I const&, N ); \
  template bool operator OP( N, I const& )

#define ZORBA_INTEGER_OP(OP,N) \
  template<class T>                                   \
  bool operator OP( IntegerImpl<T> const &i, N n ) {  \
    ascii::itoa_buf_type buf;                         \
    return i.value_ OP MAPM( ascii::itoa( n, buf ) ); \
  }                                                   \
                                                      \
  template<class T>                                   \
  bool operator OP( N n, IntegerImpl<T> const &i ) {  \
    ascii::itoa_buf_type buf;                         \
    return MAPM( ascii::itoa( n, buf ) ) OP i.value_; \
  }                                                   \
                                                      \
  ZORBA_INSTANTIATE( OP, Integer, N );                \
  ZORBA_INSTANTIATE( OP, NegativeInteger, N );        \
  ZORBA_INSTANTIATE( OP, NonNegativeInteger, N );     \
  ZORBA_INSTANTIATE( OP, NonPositiveInteger, N );     \
  ZORBA_INSTANTIATE( OP, PositiveInteger, N );

ZORBA_INTEGER_OP(==,long long)
ZORBA_INTEGER_OP(!=,long long)
ZORBA_INTEGER_OP(< ,long long)
ZORBA_INTEGER_OP(<=,long long)
ZORBA_INTEGER_OP(> ,long long)
ZORBA_INTEGER_OP(>=,long long)
ZORBA_INTEGER_OP(==,unsigned long)
ZORBA_INTEGER_OP(!=,unsigned long)
ZORBA_INTEGER_OP(< ,unsigned long)
ZORBA_INTEGER_OP(<=,unsigned long)
ZORBA_INTEGER_OP(> ,unsigned long)
ZORBA_INTEGER_OP(>=,unsigned long)
ZORBA_INTEGER_OP(==,unsigned long long)
ZORBA_INTEGER_OP(!=,unsigned long long)
ZORBA_INTEGER_OP(< ,unsigned long long)
ZORBA_INTEGER_OP(<=,unsigned long long)
ZORBA_INTEGER_OP(> ,unsigned long long)
ZORBA_INTEGER_OP(>=,unsigned long long)
#undef ZORBA_INSTANTIATE

#endif /* ZORBA_WITH_BIG_INTEGER */

////////// math functions /////////////////////////////////////////////////////

template<class T>
Double IntegerImpl<T>::pow( IntegerImpl<T> const &power ) const {
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

template<class T>
IntegerImpl<T> IntegerImpl<T>::round( IntegerImpl<T> const &precision ) const {
  return IntegerImpl( Decimal::round2( itod(), precision.itod() ) );
}

template<class T>
IntegerImpl<T>
IntegerImpl<T>::roundHalfToEven( IntegerImpl const &precision ) const {
  return IntegerImpl( Decimal::roundHalfToEven2( itod(), precision.itod() ) );
}

////////// miscellaneous //////////////////////////////////////////////////////

#ifndef ZORBA_WITH_BIG_INTEGER
template<class T>
typename IntegerImpl<T>::value_type IntegerImpl<T>::ftoi( MAPM const &d ) {
  MAPM const temp( d.sign() >= 0 ? d.floor() : d.ceil() );
  unique_ptr<char[]> const buf( new char[ temp.exponent() + 3 ] );
  temp.toIntegerString( buf.get() );
  return ztd::aton<value_type>( buf.get() );
}

template<class T>
MAPM IntegerImpl<T>::itod() const {
  if ( is_cxx_long() )
    return static_cast<long>( value_ );
  ascii::itoa_buf_type buf;
  return ascii::itoa( value_, buf );
}
#endif /* ZORBA_WITH_BIG_INTEGER */

#ifdef ZORBA_WITH_BIG_INTEGER

static MAPM xs_byte_min( "-128" );
static MAPM xs_byte_max( "127" );
static MAPM xs_short_min( "-32768" );
static MAPM xs_short_max( "32767" );
static MAPM xs_unsignedByte_max( "256" );
static MAPM xs_unsignedInt_max( "4294967295" );
static MAPM xs_unsignedLong_max( "18446744073709551615" );
static MAPM xs_unsignedShort_max( "65536" );

template<class T>
size_t IntegerImpl<T>::alloc_size() const {
  return value_.significant_digits();
}

template<class T>
uint32_t IntegerImpl<T>::hash() const {
  return Decimal::hash( value_ );
}

template<class T>
bool IntegerImpl<T>::is_xs_byte() const {
  return value_ >= xs_byte_min && value_ <= xs_byte_max;
}

template<class T>
bool IntegerImpl<T>::is_xs_short() const {
  return value_ >= xs_short_min && value_ <= xs_short_max;
}

template<class T>
bool IntegerImpl<T>::is_xs_unsignedByte() const {
  return value_.sign() >= 0 && value_ <= xs_unsignedByte_max;
}

template<class T>
bool IntegerImpl<T>::is_xs_unsignedInt() const {
  return value_.sign() >= 0 && value_ <= xs_unsignedInt_max;
}

template<class T>
bool IntegerImpl<T>::is_xs_unsignedLong() const {
  return value_.sign() >= 0 && value_ <= xs_unsignedLong_max;
}

template<class T>
bool IntegerImpl<T>::is_xs_unsignedShort() const {
  return value_.sign() >= 0 && value_ <= xs_unsignedShort_max;
}
#endif /* ZORBA_WITH_BIG_INTEGER */

template<class T>
zstring IntegerImpl<T>::toString() const {
#ifdef ZORBA_WITH_BIG_INTEGER
  ostringstream oss;
  oss << value_;
  return oss.str();
#else
  ascii::itoa_buf_type buf;
  return ascii::itoa( value_, buf );
#endif /* ZORBA_WITH_BIG_INTEGER */
}

///////////////////////////////////////////////////////////////////////////////

// instantiate integer types
template class IntegerImpl<integer_traits>;
template class IntegerImpl<negative_traits>;
template class IntegerImpl<nonNegative_traits>;
template class IntegerImpl<nonPositive_traits>;
template class IntegerImpl<positive_traits>;

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
