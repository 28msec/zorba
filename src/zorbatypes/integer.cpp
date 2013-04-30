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

ostream& operator<<( ostream &o, MAPM const &m ) {
  unique_ptr<char[]> const buf( new char[ m.exponent() + 3 ] );
  m.toIntegerString( buf.get() );
  return o << buf.get();
}

#ifdef ZORBA_WITH_BIG_INTEGER
void integer_check::throw_range_error( MAPM const &n, char const *op ) {
  ostringstream oss;
  oss << n;
  throw range_error( BUILD_STRING( oss.str(), ": not ", op, " 0" ) );
}
#endif /* ZORBA_WITH_BIG_INTEGER */

///////////////////////////////////////////////////////////////////////////////

template<class C>
void IntegerImpl<C>::parse( char const *s ) {
#ifdef ZORBA_WITH_BIG_INTEGER
  Decimal::parse( s, &value_, Decimal::parse_integer );
#else
  value_ = ztd::aton<value_type>( s );
#endif /* ZORBA_WITH_BIG_INTEGER */
  C::check_value( value_ );
}

////////// constructors ///////////////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
template<class C>
IntegerImpl<C>::IntegerImpl( long long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  C::check_value( value_ );
}

#if ZORBA_SIZEOF_INT == ZORBA_SIZEOF_LONG
template<class C>
IntegerImpl<C>::IntegerImpl( unsigned int n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  C::check_value( value_ );
}
#endif /* ZORBA_SIZEOF_INT == ZORBA_SIZEOF_LONG */

template<class C>
IntegerImpl<C>::IntegerImpl( unsigned long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  C::check_value( value_ );
}

template<class C>
IntegerImpl<C>::IntegerImpl( unsigned long long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  C::check_value( value_ );
}
#endif /* ZORBA_WITH_BIG_INTEGER */

template<class C>
IntegerImpl<C>::IntegerImpl( Decimal const &d ) {
  value_ = C::check_value( ftoi( d.value_ ) );
}

template<class C>
IntegerImpl<C>::IntegerImpl( Double const &d ) {
  if ( !d.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = C::check_value( ftoi( d.getNumber() ) );
}

template<class C>
IntegerImpl<C>::IntegerImpl( Float const &f ) {
  if ( !f.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = C::check_value( ftoi( f.getNumber() ) );
}

////////// assignment operators ///////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
template<class C>
IntegerImpl<C>& IntegerImpl<C>::operator=( long long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  C::check_value( value_ );
  return *this;
}

template<class C>
IntegerImpl<C>& IntegerImpl<C>::operator=( unsigned long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  C::check_value( value_ );
  return *this;
}

template<class C>
IntegerImpl<C>& IntegerImpl<C>::operator=( unsigned long long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  C::check_value( value_ );
  return *this;
}
#endif /* ZORBA_WITH_BIG_INTEGER */

template<class C>
IntegerImpl<C>& IntegerImpl<C>::operator=( Decimal const &d ) {
  value_ = C::check_value( ftoi( d.value_ ) );
  return *this;
}

template<class C>
IntegerImpl<C>& IntegerImpl<C>::operator=( Double const &d ) {
  if ( !d.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = C::check_value( ftoi( d.getNumber() ) );
  return *this;
}

template<class C>
IntegerImpl<C>& IntegerImpl<C>::operator=( Float const &f ) {
  if ( !f.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = C::check_value( ftoi( f.getNumber() ) );
  return *this;
}

////////// arithmetic operators ///////////////////////////////////////////////

#define ZORBA_INSTANTIATE(OP,I) \
  template Decimal operator OP( I const&, Decimal const& );

#define ZORBA_INTEGER_OP(OP)                                          \
  template<class C>                                                   \
  Decimal operator OP( IntegerImpl<C> const &i, Decimal const &d ) {  \
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

#define ZORBA_INSTANTIATE(OP,I,T)         \
  template I operator OP( I const&, T );  \
  template I operator OP( T, I const& )

#define ZORBA_INTEGER_OP(OP,T)                                  \
  template<class C>                                             \
  IntegerImpl<C> operator OP( IntegerImpl<C> const &i, T n ) {  \
    ascii::itoa_buf_type buf;                                   \
    return i.value_ OP MAPM( ascii::itoa( n, buf ) );           \
  }                                                             \
  template<class C>                                             \
  IntegerImpl<C> operator OP( T n, IntegerImpl<C> const &i ) {  \
    ascii::itoa_buf_type buf;                                   \
    return MAPM( ascii::itoa( n, buf ) ) OP i.value_;           \
  }                                                             \
  ZORBA_INSTANTIATE( OP, Integer, T );                          \
  ZORBA_INSTANTIATE( OP, NegativeInteger, T );                  \
  ZORBA_INSTANTIATE( OP, NonNegativeInteger, T );               \
  ZORBA_INSTANTIATE( OP, NonPositiveInteger, T );               \
  ZORBA_INSTANTIATE( OP, PositiveInteger, T );

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
#undef ZORBA_INSTANTIATE
#undef ZORBA_INTEGER_OP

#define ZORBA_INSTANTIATE( I, T )       \
  template I operator/( I const&, T );  \
  template I operator/( T, I const& )

#define ZORBA_INTEGER_OP(T)                                   \
  template<class C>                                           \
  IntegerImpl<C> operator/( IntegerImpl<C> const &i, T n ) {  \
    ascii::itoa_buf_type buf;                                 \
    MAPM const temp( ascii::itoa( n, buf ) );                 \
    return IntegerImpl<C>::ftoi( i.value_ / temp );           \
  }                                                           \
  template<class C>                                           \
  IntegerImpl<C> operator/( T n, IntegerImpl<C> const &i ) {  \
    ascii::itoa_buf_type buf;                                 \
    MAPM const temp( ascii::itoa( n, buf ) );                 \
    return IntegerImpl<C>::ftoi( temp / i.value_ );           \
  }                                                           \
  ZORBA_INSTANTIATE( Integer, T );                            \
  ZORBA_INSTANTIATE( NegativeInteger, T );                    \
  ZORBA_INSTANTIATE( NonNegativeInteger, T );                 \
  ZORBA_INSTANTIATE( NonPositiveInteger, T );                 \
  ZORBA_INSTANTIATE( PositiveInteger, T );                    \

ZORBA_INTEGER_OP(long long)
ZORBA_INTEGER_OP(unsigned long)
ZORBA_INTEGER_OP(unsigned long long)
#undef ZORBA_INSTANTIATE
#undef ZORBA_INTEGER_OP

#define ZORBA_INTEGER_OP(OP,T)                          \
  template<class C>                                     \
  IntegerImpl<C>& IntegerImpl<C>::operator OP( T n ) {  \
    ascii::itoa_buf_type buf;                           \
    value_type const temp( ascii::itoa( n, buf ) );     \
    C::check_value( value_ OP temp );                   \
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

#define ZORBA_INTEGER_OP(T) \
  template<class C>                                   \
  IntegerImpl<C>& IntegerImpl<C>::operator/=( T n ) { \
    ascii::itoa_buf_type buf;                         \
    value_type const temp( ascii::itoa( n, buf ) );   \
    C::check_value( value_ = ftoi( value_ / temp ) ); \
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

template<class C>
bool operator==( IntegerImpl<C> const &i, Decimal const &d ) {
  return d.is_xs_integer() && i.itod() == d.value_;
}

ZORBA_INSTANTIATE( ==, Integer );
ZORBA_INSTANTIATE( ==, NegativeInteger );
ZORBA_INSTANTIATE( ==, NonNegativeInteger );
ZORBA_INSTANTIATE( ==, NonPositiveInteger );
ZORBA_INSTANTIATE( ==, PositiveInteger );

#define ZORBA_INTEGER_OP(OP)                                      \
  template<class C>                                               \
  bool operator OP( IntegerImpl<C> const &i, Decimal const &d ) { \
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

#define ZORBA_INSTANTIATE(OP,I,T)           \
  template bool operator OP( I const&, T ); \
  template bool operator OP( T, I const& )

#define ZORBA_INTEGER_OP(OP,T) \
  template<class C>                                   \
  bool operator OP( IntegerImpl<C> const &i, T n ) {  \
    ascii::itoa_buf_type buf;                         \
    return i.value_ OP MAPM( ascii::itoa( n, buf ) ); \
  }                                                   \
                                                      \
  template<class C>                                   \
  bool operator OP( T n, IntegerImpl<C> const &i ) {  \
    ascii::itoa_buf_type buf;                         \
    return MAPM( ascii::itoa( n, buf ) ) OP i.value_; \
  }                                                   \
                                                      \
  ZORBA_INSTANTIATE( OP, Integer, T );                \
  ZORBA_INSTANTIATE( OP, NegativeInteger, T );        \
  ZORBA_INSTANTIATE( OP, NonNegativeInteger, T );     \
  ZORBA_INSTANTIATE( OP, NonPositiveInteger, T );     \
  ZORBA_INSTANTIATE( OP, PositiveInteger, T );

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

static MAPM xs_byte_min( "-128" );
static MAPM xs_byte_max( "127" );
static MAPM xs_short_min( "-32768" );
static MAPM xs_short_max( "32767" );
static MAPM xs_unsignedByte_max( "256" );
static MAPM xs_unsignedInt_max( "4294967295" );
static MAPM xs_unsignedLong_max( "18446744073709551615" );
static MAPM xs_unsignedShort_max( "65536" );

template<class C>
size_t IntegerImpl<C>::alloc_size() const {
  return value_.significant_digits();
}

template<class C>
uint32_t IntegerImpl<C>::hash() const {
  return Decimal::hash( value_ );
}

template<class C>
bool IntegerImpl<C>::is_xs_byte() const {
  return value_ >= xs_byte_min && value_ <= xs_byte_max;
}

template<class C>
bool IntegerImpl<C>::is_xs_short() const {
  return value_ >= xs_short_min && value_ <= xs_short_max;
}

template<class C>
bool IntegerImpl<C>::is_xs_unsignedByte() const {
  return value_.sign() >= 0 && value_ <= xs_unsignedByte_max;
}

template<class C>
bool IntegerImpl<C>::is_xs_unsignedInt() const {
  return value_.sign() >= 0 && value_ <= xs_unsignedInt_max;
}

template<class C>
bool IntegerImpl<C>::is_xs_unsignedLong() const {
  return value_.sign() >= 0 && value_ <= xs_unsignedLong_max;
}

template<class C>
bool IntegerImpl<C>::is_xs_unsignedShort() const {
  return value_.sign() >= 0 && value_ <= xs_unsignedShort_max;
}
#endif /* ZORBA_WITH_BIG_INTEGER */

template<class C>
zstring IntegerImpl<C>::toString() const {
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
template class IntegerImpl<integer_check>;
template class IntegerImpl<negative_check>;
template class IntegerImpl<nonNegative_check>;
template class IntegerImpl<nonPositive_check>;
template class IntegerImpl<positive_check>;

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
