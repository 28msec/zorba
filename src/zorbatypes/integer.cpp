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

#ifdef ZORBA_WITH_BIG_INTEGER
# define TEMPLATE_DECL    /* nothing */
# define INTEGER_IMPL     IntegerImpl
#else
# define TEMPLATE_DECL    template<typename IntType>
# define INTEGER_IMPL     IntegerImpl<IntType>
# define INTEGER_IMPL_LL  IntegerImpl<long long>
# define INTEGER_IMPL_ULL IntegerImpl<unsigned long long>
#endif /* ZORBA_WITH_BIG_INTEGER */

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
void IntegerImpl::parse( char const *s ) {
  Decimal::parse( s, &value_, Decimal::parse_integer );
#else
template<typename IntType>
void IntegerImpl<IntType>::parse( char const *s ) {
  value_ = ztd::aton<value_type>( s );
#endif /* ZORBA_WITH_BIG_INTEGER */
}

////////// constructors ///////////////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
IntegerImpl::IntegerImpl( long long n ) {
  ztd::itoa_buf_type buf;
  value_ = ztd::itoa( n, buf );
}

IntegerImpl::IntegerImpl( unsigned long n ) {
  ztd::itoa_buf_type buf;
  value_ = ztd::itoa( n, buf );
}

IntegerImpl::IntegerImpl( unsigned long long n ) {
  ztd::itoa_buf_type buf;
  value_ = ztd::itoa( n, buf );
}
#endif /* ZORBA_WITH_BIG_INTEGER */

TEMPLATE_DECL
INTEGER_IMPL::IntegerImpl( Decimal const &d ) {
  value_ = ftoi( d.value_ );
}

TEMPLATE_DECL
INTEGER_IMPL::IntegerImpl( Double const &d ) {
  if ( !d.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( d.getNumber() );
}

TEMPLATE_DECL
INTEGER_IMPL::IntegerImpl( Float const &f ) {
  if ( !f.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( f.getNumber() );
}

////////// assignment operators ///////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
IntegerImpl& IntegerImpl::operator=( long long n ) {
  ztd::itoa_buf_type buf;
  value_ = ztd::itoa( n, buf );
  return *this;
}

IntegerImpl& IntegerImpl::operator=( unsigned long n ) {
  ztd::itoa_buf_type buf;
  value_ = ztd::itoa( n, buf );
  return *this;
}

IntegerImpl& IntegerImpl::operator=( unsigned long long n ) {
  ztd::itoa_buf_type buf;
  value_ = ztd::itoa( n, buf );
  return *this;
}
#endif /* ZORBA_WITH_BIG_INTEGER */

TEMPLATE_DECL
INTEGER_IMPL& INTEGER_IMPL::operator=( Decimal const &d ) {
  value_ = ftoi( d.value_ );
  return *this;
}

TEMPLATE_DECL
INTEGER_IMPL& INTEGER_IMPL::operator=( Double const &d ) {
  if ( !d.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = ftoi( d.getNumber() );
  return *this;
}

TEMPLATE_DECL
INTEGER_IMPL& INTEGER_IMPL::operator=( Float const &f ) {
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
  template Decimal operator OP( INTEGER_IMPL_ULL const&, Decimal const& )
#endif /* ZORBA_WITH_BIG_INTEGER */

#define ZORBA_INTEGER_OP(OP)                                        \
  TEMPLATE_DECL                                                     \
  Decimal operator OP( INTEGER_IMPL const &i, Decimal const &d ) {  \
    return i.itod() OP d.value_;                                    \
  }                                                                 \
  ZORBA_INSTANTIATE(OP)

ZORBA_INTEGER_OP(+)
ZORBA_INTEGER_OP(-)
ZORBA_INTEGER_OP(*)
ZORBA_INTEGER_OP(/)
ZORBA_INTEGER_OP(%)
#undef ZORBA_INTEGER_OP
#undef ZORBA_INSTANTIATE

////////// relational operators ///////////////////////////////////////////////

TEMPLATE_DECL
bool operator==( INTEGER_IMPL const &i, Decimal const &d ) {
  return d.is_integer() && i.itod() == d.value_;
}

#define ZORBA_INTEGER_OP(OP)                                    \
  TEMPLATE_DECL                                                 \
  bool operator OP( INTEGER_IMPL const &i, Decimal const &d ) { \
    return i.itod() OP d.value_;                                \
  }

ZORBA_INTEGER_OP(!=)
ZORBA_INTEGER_OP(< )
ZORBA_INTEGER_OP(<=)
ZORBA_INTEGER_OP(> )
ZORBA_INTEGER_OP(>=)
#undef ZORBA_INTEGER_OP

#ifndef ZORBA_WITH_BIG_INTEGER
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

TEMPLATE_DECL
Double INTEGER_IMPL::pow( INTEGER_IMPL const &power ) const {
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

TEMPLATE_DECL
INTEGER_IMPL INTEGER_IMPL::round( IntegerImpl const &precision ) const {
  return IntegerImpl( Decimal::round( itod(), precision.itod() ) );
}

TEMPLATE_DECL
INTEGER_IMPL
INTEGER_IMPL::roundHalfToEven( IntegerImpl const &precision ) const {
  return INTEGER_IMPL( Decimal::roundHalfToEven( itod(), precision.itod() ) );
}

////////// miscellaneous //////////////////////////////////////////////////////

#ifndef ZORBA_WITH_BIG_INTEGER
TEMPLATE_DECL
typename INTEGER_IMPL::value_type INTEGER_IMPL::ftoi( MAPM const &d ) {
  MAPM const temp( d.sign() >= 0 ? d.floor() : d.ceil() );
  char *const buf = new char[ temp.exponent() + 3 ];
  temp.toIntegerString( buf );
  value_type const result( ztd::aton<value_type>( buf ) );
  delete[] buf;
  return result;
}

TEMPLATE_DECL
MAPM INTEGER_IMPL::itod() const {
  if ( is_long() )
    return static_cast<long>( value_ );
  ztd::itoa_buf_type buf;
  return ztd::itoa( value_, buf );
}
#endif /* ZORBA_WITH_BIG_INTEGER */

#ifdef ZORBA_WITH_BIG_INTEGER
uint32_t IntegerImpl::hash() const {
  return Decimal::hash( value_ );
}
#endif /* ZORBA_WITH_BIG_INTEGER */

TEMPLATE_DECL
INTEGER_IMPL const& INTEGER_IMPL::one() {
  static INTEGER_IMPL const i(1);
  return i;
}

TEMPLATE_DECL
zstring INTEGER_IMPL::toString() const {
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

TEMPLATE_DECL
INTEGER_IMPL const& INTEGER_IMPL::zero() {
  static INTEGER_IMPL const i(0);
  return i;
}

///////////////////////////////////////////////////////////////////////////////

#ifndef ZORBA_WITH_BIG_INTEGER
template class IntegerImpl<long long>;
template class IntegerImpl<unsigned long long>;
#endif /* ZORBA_WITH_BIG_INTEGER */

} // namespace zorba
/* vim:set et sw=2 ts=2: */
