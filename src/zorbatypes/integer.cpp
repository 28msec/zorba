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
#include "integer_macros.h"
#include "numconversions.h"

using namespace std;

#ifndef ZORBA_WITH_BIG_INTEGER
z_uint_type const MaxUIntegerValue = ~0ull >> 1;

inline bool is_too_big( z_int_type ) {
  return false;
}

inline bool is_too_big( z_uint_type n ) {
  return n > MaxUIntegerValue;
}
#endif /* ZORBA_WITH_BIG_INTEGER */

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

TEMPLATE_DECL(I)
void INTEGER_IMPL(I)::parse( char const *s ) {
#ifdef ZORBA_WITH_BIG_INTEGER
  Decimal::parse( s, &value_, Decimal::parse_integer );
#else
  value_type const temp( ztd::aton<value_type>( s ) );
  if ( is_too_big( temp ) )
    throw std::range_error(
      BUILD_STRING( '"', temp, "\": unsigned integer too big" )
    );
  value_ = temp;
#endif /* ZORBA_WITH_BIG_INTEGER */
}

////////// constructors ///////////////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
IntegerImpl::IntegerImpl( long long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
}

#if ZORBA_SIZEOF_INT == ZORBA_SIZEOF_LONG
TEMPLATE_DECL(T)
INTEGER_IMPL(T)::IntegerImpl( unsigned int n ) {
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

TEMPLATE_DECL(T)
INTEGER_IMPL(T)::IntegerImpl( Decimal const &d ) {
  value_ = ftoi( d.value_ );
}

TEMPLATE_DECL(T)
INTEGER_IMPL(T)::IntegerImpl( Double const &d ) {
  if ( !d.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( d.getNumber() );
}

TEMPLATE_DECL(T)
INTEGER_IMPL(T)::IntegerImpl( Float const &f ) {
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

TEMPLATE_DECL(T)
INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( Decimal const &d ) {
  value_ = ftoi( d.value_ );
  return *this;
}

TEMPLATE_DECL(T)
INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( Double const &d ) {
  if ( !d.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( d.getNumber() );
  return *this;
}

TEMPLATE_DECL(T)
INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( Float const &f ) {
  if ( !f.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( f.getNumber() );
  return *this;
}

////////// arithmetic operators ///////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
# define ZORBA_INSTANTIATE(OP) /* nothing */
#else
# define ZORBA_INSTANTIATE(OP)                                            \
  template Decimal operator OP( INTEGER_IMPL_LL const&, Decimal const& ); \
  template Decimal operator OP( INTEGER_IMPL_ULL const&, Decimal const& );
#endif /* ZORBA_WITH_BIG_INTEGER */

#define ZORBA_INTEGER_OP(OP)                                          \
  TEMPLATE_DECL(T)                                                    \
  Decimal operator OP( INTEGER_IMPL(T) const &i, Decimal const &d ) { \
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

TEMPLATE_DECL(T)
bool operator==( INTEGER_IMPL(T) const &i, Decimal const &d ) {
  return d.is_xs_integer() && i.itod() == d.value_;
}

#define ZORBA_INTEGER_OP(OP)                                        \
  TEMPLATE_DECL(T)                                                  \
  bool operator OP( INTEGER_IMPL(T) const &i, Decimal const &d ) {  \
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

#define ZORBA_INSTANTIATE(OP)                                           \
  template bool operator OP( INTEGER_IMPL_LL const&, Decimal const& );  \
  template bool operator OP( INTEGER_IMPL_ULL const&, Decimal const& )

ZORBA_INSTANTIATE(==);
ZORBA_INSTANTIATE(!=);
ZORBA_INSTANTIATE(< );
ZORBA_INSTANTIATE(<=);
ZORBA_INSTANTIATE(> );
ZORBA_INSTANTIATE(>=);
#undef ZORBA_INSTANTIATE

#endif /* ZORBA_WITH_BIG_INTEGER */

////////// math functions /////////////////////////////////////////////////////

TEMPLATE_DECL(T)
Double INTEGER_IMPL(T)::pow( INTEGER_IMPL(T) const &power ) const {
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

TEMPLATE_DECL(T)
INTEGER_IMPL(T) INTEGER_IMPL(T)::round( IntegerImpl const &precision ) const {
  return IntegerImpl( Decimal::round2( itod(), precision.itod() ) );
}

TEMPLATE_DECL(T)
INTEGER_IMPL(T)
INTEGER_IMPL(T)::roundHalfToEven( IntegerImpl const &precision ) const {
  return IntegerImpl( Decimal::roundHalfToEven2( itod(), precision.itod() ) );
}

////////// miscellaneous //////////////////////////////////////////////////////

#ifndef ZORBA_WITH_BIG_INTEGER
TEMPLATE_DECL(T)
typename INTEGER_IMPL(T)::value_type INTEGER_IMPL(T)::ftoi( MAPM const &d ) {
  MAPM const temp( d.sign() >= 0 ? d.floor() : d.ceil() );
  unique_ptr<char[]> const buf( new char[ temp.exponent() + 3 ] );
  temp.toIntegerString( buf.get() );
  return ztd::aton<value_type>( buf.get() );
}

TEMPLATE_DECL(T)
MAPM INTEGER_IMPL(T)::itod() const {
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

TEMPLATE_DECL(T)
INTEGER_IMPL(T) const& INTEGER_IMPL(T)::one() {
  static INTEGER_IMPL(T) const i(1);
  return i;
}

TEMPLATE_DECL(T)
zstring INTEGER_IMPL(T)::toString() const {
#ifdef ZORBA_WITH_BIG_INTEGER
  unique_ptr<char[]> const buf( new char[ value_.exponent() + 3 ] );
  value_.toIntegerString( buf.get() );
  return buf.get();
#else
  ascii::itoa_buf_type buf;
  return ascii::itoa( value_, buf );
#endif /* ZORBA_WITH_BIG_INTEGER */
}

TEMPLATE_DECL(T)
INTEGER_IMPL(T) const& INTEGER_IMPL(T)::zero() {
  static INTEGER_IMPL(T) const i(0);
  return i;
}

///////////////////////////////////////////////////////////////////////////////

#ifndef ZORBA_WITH_BIG_INTEGER
template class IntegerImpl<z_int_type>;
template class IntegerImpl<z_uint_type>;
#endif /* ZORBA_WITH_BIG_INTEGER */

} // namespace zorba
/* vim:set et sw=2 ts=2: */
