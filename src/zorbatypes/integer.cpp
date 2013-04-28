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
#include <zorba/internal/unique_ptr.h>
#include "util/cxx_util.h"
#include "util/string_util.h"

// local
#include "decimal.h"
#include "floatimpl.h"
#include "integer.h"
#include "numconversions.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

template<class C>
void IntegerImpl<C>::parse( char const *s ) {
#ifdef ZORBA_WITH_BIG_INTEGER
  Decimal::parse( s, &value_, Decimal::parse_integer );
  // TODO: check value?
#else
  value_type const temp( ztd::aton<value_type>( s ) );
#if 0
  if ( is_too_big( temp ) )
    throw std::range_error(
      BUILD_STRING( '"', temp, "\": unsigned integer too big" )
    );
#endif
  value_ = temp;
#endif /* ZORBA_WITH_BIG_INTEGER */
}

////////// constructors ///////////////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
template<class C>
IntegerImpl<C>::IntegerImpl( long long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
}

#if ZORBA_SIZEOF_INT == ZORBA_SIZEOF_LONG
template<class C>
IntegerImpl<C>::IntegerImpl( unsigned int n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
}
#endif /* ZORBA_SIZEOF_INT == ZORBA_SIZEOF_LONG */

IntegerImpl::IntegerImpl( unsigned long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
}

IntegerImpl::IntegerImpl( unsigned long long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
}
#endif /* ZORBA_WITH_BIG_INTEGER */

template<class C>
IntegerImpl<C>::IntegerImpl( Decimal const &d ) {
  value_ = ftoi( d.value_ );
}

template<class C>
IntegerImpl<C>::IntegerImpl( Double const &d ) {
  if ( !d.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( d.getNumber() );
}

template<class C>
IntegerImpl<C>::IntegerImpl( Float const &f ) {
  if ( !f.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( f.getNumber() );
}

////////// assignment operators ///////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
IntegerImpl& IntegerImpl::operator=( long long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  return *this;
}

IntegerImpl& IntegerImpl::operator=( unsigned long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  return *this;
}

IntegerImpl& IntegerImpl::operator=( unsigned long long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  return *this;
}
#endif /* ZORBA_WITH_BIG_INTEGER */

template<class C>
IntegerImpl<C>& IntegerImpl<C>::operator=( Decimal const &d ) {
  value_ = ftoi( d.value_ );
  return *this;
}

template<class C>
IntegerImpl<C>& IntegerImpl<C>::operator=( Double const &d ) {
  if ( !d.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( d.getNumber() );
  return *this;
}

template<class C>
IntegerImpl<C>& IntegerImpl<C>::operator=( Float const &f ) {
  if ( !f.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( f.getNumber() );
  return *this;
}

////////// arithmetic operators ///////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
# define ZORBA_INSTANTIATE(OP) /* nothing */
#else
# define ZORBA_INSTANTIATE(OP)                                                \
  template Decimal operator OP( Integer const&, Decimal const& );             \
  template Decimal operator OP( NegativeInteger const&, Decimal const& );     \
  template Decimal operator OP( NonNegativeInteger const&, Decimal const& );  \
  template Decimal operator OP( NonPositiveInteger const&, Decimal const& );  \
  template Decimal operator OP( PositiveInteger const&, Decimal const& );
#endif /* ZORBA_WITH_BIG_INTEGER */

#define ZORBA_INTEGER_OP(OP)                                          \
  template<class C>                                                    \
  Decimal operator OP( IntegerImpl<C> const &i, Decimal const &d ) { \
    return i.itod() OP d.value_;                                      \
  }                                                                   \
  ZORBA_INSTANTIATE(OP)

ZORBA_INTEGER_OP(+)
ZORBA_INTEGER_OP(-)
ZORBA_INTEGER_OP(*)
ZORBA_INTEGER_OP(/)
ZORBA_INTEGER_OP(%)
#undef ZORBA_INTEGER_OP
#undef ZORBA_INSTANTIATE

#ifdef ZORBA_WITH_BIG_INTEGER

#define ZORBA_INTEGER_OP(OP,T)                                            \
  IntegerImpl operator OP( IntegerImpl const &i, T n ) {                  \
    ascii::itoa_buf_type buf;                                             \
    return i.value_ OP IntegerImpl::value_type( ascii::itoa( n, buf ) );  \
  }                                                                       \
  IntegerImpl operator OP( T n, IntegerImpl const &i ) {                  \
    ascii::itoa_buf_type buf;                                             \
    return IntegerImpl::value_type( ascii::itoa( n, buf ) ) OP i.value_;  \
  }

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

#define ZORBA_INTEGER_OP(T)                                       \
  IntegerImpl operator/( IntegerImpl const &i, T n ) {            \
    ascii::itoa_buf_type buf;                                     \
    IntegerImpl::value_type const temp( ascii::itoa( n, buf ) );  \
    return IntegerImpl::ftoi( i.value_ / temp );                  \
  }                                                               \
  IntegerImpl operator/( T n, IntegerImpl const &i ) {            \
    ascii::itoa_buf_type buf;                                     \
    IntegerImpl::value_type const temp( ascii::itoa( n, buf ) );  \
    return IntegerImpl::ftoi( temp / i.value_ );                  \
  }

ZORBA_INTEGER_OP(long long)
ZORBA_INTEGER_OP(unsigned long)
ZORBA_INTEGER_OP(unsigned long long)
#undef ZORBA_INTEGER_OP

#define ZORBA_INTEGER_OP(OP,T)                      \
  IntegerImpl& IntegerImpl::operator OP( T n ) {    \
    ascii::itoa_buf_type buf;                       \
    value_type const temp( ascii::itoa( n, buf ) ); \
    value_ OP temp;                                 \
    return *this;                                   \
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

#define ZORBA_INTEGER_OP(T) \
  IntegerImpl& IntegerImpl::operator/=( T n ) {     \
    ascii::itoa_buf_type buf;                       \
    value_type const temp( ascii::itoa( n, buf ) ); \
    value_ = ftoi( value_ / temp );                 \
    return *this;                                   \
  }

ZORBA_INTEGER_OP(long long)
ZORBA_INTEGER_OP(unsigned long)
ZORBA_INTEGER_OP(unsigned long long)
#undef ZORBA_INTEGER_OP
#endif /* ZORBA_WITH_BIG_INTEGER */

////////// relational operators ///////////////////////////////////////////////

template<class C>
bool operator==( IntegerImpl<C> const &i, Decimal const &d ) {
  return d.is_xs_integer() && i.itod() == d.value_;
}

#define ZORBA_INTEGER_OP(OP)                                        \
  template<class C>                                                  \
  bool operator OP( IntegerImpl<C> const &i, Decimal const &d ) {  \
    return i.itod() OP d.value_;                                    \
  }

ZORBA_INTEGER_OP(!=)
ZORBA_INTEGER_OP(< )
ZORBA_INTEGER_OP(<=)
ZORBA_INTEGER_OP(> )
ZORBA_INTEGER_OP(>=)
#undef ZORBA_INTEGER_OP

#ifdef ZORBA_WITH_BIG_INTEGER

#define ZORBA_INTEGER_OP(OP,T) \
  bool operator OP( IntegerImpl const &i, T n ) {                         \
    ascii::itoa_buf_type buf;                                             \
    return i.value_ OP IntegerImpl::value_type( ascii::itoa( n, buf ) );  \
  }                                                                       \
                                                                          \
  bool operator OP( T n, IntegerImpl const &i ) {                         \
    ascii::itoa_buf_type buf;                                             \
    return IntegerImpl::value_type( ascii::itoa( n, buf ) ) OP i.value_;  \
  }

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

#else /* ZORBA_WITH_BIG_INTEGER */

#define ZORBA_INSTANTIATE(OP)                                             \
  template bool operator OP( Integer const&, Decimal const& );            \
  template bool operator OP( NegativeInteger const&, Decimal const& );    \
  template bool operator OP( NonNegativeInteger const&, Decimal const& ); \
  template bool operator OP( NonPositiveInteger const&, Decimal const& ); \
  template bool operator OP( PositiveInteger const&, Decimal const& )

ZORBA_INSTANTIATE(==);
ZORBA_INSTANTIATE(!=);
ZORBA_INSTANTIATE(< );
ZORBA_INSTANTIATE(<=);
ZORBA_INSTANTIATE(> );
ZORBA_INSTANTIATE(>=);
#undef ZORBA_INSTANTIATE

#endif /* ZORBA_WITH_BIG_INTEGER */

////////// math functions /////////////////////////////////////////////////////

template<class C>
Double IntegerImpl<C>::pow( IntegerImpl<C> const &power ) const {
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

template<class C>
IntegerImpl<C> IntegerImpl<C>::round( IntegerImpl<C> const &precision ) const {
  return IntegerImpl( Decimal::round2( itod(), precision.itod() ) );
}

template<class C>
IntegerImpl<C>
IntegerImpl<C>::roundHalfToEven( IntegerImpl const &precision ) const {
  return IntegerImpl( Decimal::roundHalfToEven2( itod(), precision.itod() ) );
}

////////// miscellaneous //////////////////////////////////////////////////////

#ifndef ZORBA_WITH_BIG_INTEGER
template<class C>
typename IntegerImpl<C>::value_type IntegerImpl<C>::ftoi( MAPM const &d ) {
  MAPM const temp( d.sign() >= 0 ? d.floor() : d.ceil() );
  unique_ptr<char[]> const buf( new char[ temp.exponent() + 3 ] );
  temp.toIntegerString( buf.get() );
  return ztd::aton<value_type>( buf.get() );
}

template<class C>
MAPM IntegerImpl<C>::itod() const {
  if ( is_cxx_long() )
    return static_cast<long>( value_ );
  ascii::itoa_buf_type buf;
  return ascii::itoa( value_, buf );
}
#endif /* ZORBA_WITH_BIG_INTEGER */

#ifdef ZORBA_WITH_BIG_INTEGER
size_t IntegerImpl::alloc_size() const {
  return value_.significant_digits();
}

uint32_t IntegerImpl::hash() const {
  return Decimal::hash( value_ );
}

bool IntegerImpl::is_xs_byte() const {
  static MAPM xs_byte_min( "-128" );
  static MAPM xs_byte_max( "127" );
  return value_ >= xs_byte_min && value_ <= xs_byte_max;
}

bool IntegerImpl::is_xs_short() const {
  static MAPM xs_short_min( "-32768" );
  static MAPM xs_short_max( "32767" );
  return value_ >= xs_short_min && value_ <= xs_short_max;
}

bool IntegerImpl::is_xs_unsignedByte() const {
  static MAPM xs_unsignedByte_max( "256" );
  return value_.sign() >= 0 && value_ <= xs_unsignedByte_max;
}

bool IntegerImpl::is_xs_unsignedInt() const {
  static MAPM xs_unsignedInt_max( "4294967295" );
  return value_.sign() >= 0 && value_ <= xs_unsignedInt_max;
}

bool IntegerImpl::is_xs_unsignedLong() const {
  static MAPM xs_unsignedLong_max( "18446744073709551615" );
  return value_.sign() >= 0 && value_ <= xs_unsignedLong_max;
}

bool IntegerImpl::is_xs_unsignedShort() const {
  static MAPM xs_unsignedShort_max( "65536" );
  return value_.sign() >= 0 && value_ <= xs_unsignedShort_max;
}
#endif /* ZORBA_WITH_BIG_INTEGER */

template<class C>
zstring IntegerImpl<C>::toString() const {
#ifdef ZORBA_WITH_BIG_INTEGER
  unique_ptr<char[]> const buf( new char[ value_.exponent() + 3 ] );
  value_.toIntegerString( buf.get() );
  return buf.get();
#else
  ascii::itoa_buf_type buf;
  return ascii::itoa( value_, buf );
#endif /* ZORBA_WITH_BIG_INTEGER */
}

///////////////////////////////////////////////////////////////////////////////

// instantiate integer types
template class IntegerImpl<integer_check>;
template class IntegerImpl<negative_check>;
template class IntegerImpl<nonNegative_check>;
template class IntegerImpl<nonPositive_check>;
template class IntegerImpl<positive_check>;

///////////////////////////////////////////////////////////////////////////////

template<class I>
I const& integer_const<I>::zero() {
  static I const i(0);
  return i;
}

template<class I>
I const& integer_const<I>::one() {
  static I const i(1);
  return i;
}

template class integer_const<Integer>;
template class integer_const<NonNegativeInteger>;

NonPositiveInteger const& integer_const<NonPositiveInteger>::zero() {
  static NonPositiveInteger const i(0);
  return i;
}

PositiveInteger const& integer_const<PositiveInteger>::one() {
  static PositiveInteger const i(1);
  return i;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
