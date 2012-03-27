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

#include "util/stl_util.h"
#include "zorbaserialization/archiver.h"
#include "zorbaserialization/zorba_class_serializer.h"

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
#define INTEGER_IMPL_LL  INTEGER_IMPL(long long)
#define INTEGER_IMPL_ULL INTEGER_IMPL(unsigned long long)

namespace zorba {

TEMPLATE_DECL(T)
class IntegerImpl;

namespace serialization {
  TEMPLATE_DECL(T) void operator&( Archiver&, INTEGER_IMPL(T)& );
}

///////////////////////////////////////////////////////////////////////////////

TEMPLATE_DECL(IntType)
class IntegerImpl {
public:

  ////////// constructors /////////////////////////////////////////////////////

  IntegerImpl( char c );
  IntegerImpl( signed char c );
  IntegerImpl( short n );
  IntegerImpl( int n = 0 );
  IntegerImpl( long n );
  IntegerImpl( long long n );
  IntegerImpl( unsigned char c );
  IntegerImpl( unsigned short n );
  IntegerImpl( unsigned int n );
  IntegerImpl( unsigned long n );
  IntegerImpl( unsigned long long n );
  IntegerImpl( float n );
  IntegerImpl( double n );
  IntegerImpl( Decimal const &d );

  TEMPLATE_DECL(U)
  IntegerImpl( INTEGER_IMPL(U) const &i );

  /**
   * Constructs an %IntegerImpl from a C string.
   *
   * @param s The null-terminated C string to parse.  Leading and trailing
   * whitespace is ignored.
   * @throw std::invalid_argument if \a s does not contain a valid integer.
   * @throw std::range_error if \a s contains an integer that either underflows
   * or overflows the smallest or largest representable integer (only when not
   * compiled with ZORBA_WITH_BIG_INTEGER).
   */
  IntegerImpl( char const *s );

  /**
   * Constructs an %IntegerImpl from a Double.
   *
   * @param d The Double.
   * @throw std::invalid_argument if \a d is not finite.
   */
  IntegerImpl( Double const &d );

  /**
   * Constructs an %IntegerImpl from a Float.
   *
   * @param f The Float.
   * @throw std::invalid_argument if \a f is not finite.
   */
  IntegerImpl( Float const &f );

  ////////// assignment operators /////////////////////////////////////////////

  IntegerImpl& operator=( char c );
  IntegerImpl& operator=( signed char c );
  IntegerImpl& operator=( short n );
  IntegerImpl& operator=( int n );
  IntegerImpl& operator=( long n );
  IntegerImpl& operator=( long long n );
  IntegerImpl& operator=( unsigned char c );
  IntegerImpl& operator=( unsigned short n );
  IntegerImpl& operator=( unsigned int n );
  IntegerImpl& operator=( unsigned long n );
  IntegerImpl& operator=( unsigned long long n );
  IntegerImpl& operator=( float n );
  IntegerImpl& operator=( double n );
  IntegerImpl& operator=( char const *s );
  IntegerImpl& operator=( Decimal const &d );
  IntegerImpl& operator=( Double const &d );
  IntegerImpl& operator=( Float const &f );

  TEMPLATE_DECL(U)
  IntegerImpl& operator=( INTEGER_IMPL(U) const &i );

  ////////// arithmetic operators /////////////////////////////////////////////

#define ZORBA_INTEGER_OP(OP)                                      \
  TEMPLATE_DECL(T) friend                                         \
  INTEGER_IMPL(T) operator OP( INTEGER_IMPL(T) const&,            \
                               INTEGER_IMPL(T) const& );          \
  TEMPLATE_DECL(T) friend                                         \
  Decimal operator OP( INTEGER_IMPL(T) const&, Decimal const& );  \
  TEMPLATE_DECL(T) friend                                         \
  Decimal operator OP( Decimal const&, INTEGER_IMPL(T) const& )

  ZORBA_INTEGER_OP(+);
  ZORBA_INTEGER_OP(-);
  ZORBA_INTEGER_OP(*);
  ZORBA_INTEGER_OP(/);
  ZORBA_INTEGER_OP(%);
#undef ZORBA_INTEGER_OP

#ifndef ZORBA_WITH_BIG_INTEGER
#define ZORBA_INTEGER_OP(OP,TYPE)                               \
  TEMPLATE_DECL(T) friend                                       \
  INTEGER_IMPL(T) operator OP( INTEGER_IMPL(T) const&, TYPE );  \
  TEMPLATE_DECL(T) friend                                       \
  INTEGER_IMPL(T) operator OP( TYPE, INTEGER_IMPL(T) const& )

  ZORBA_INTEGER_OP(+,char);
  ZORBA_INTEGER_OP(+,signed char);
  ZORBA_INTEGER_OP(+,short);
  ZORBA_INTEGER_OP(+,int);
  ZORBA_INTEGER_OP(+,long);
  ZORBA_INTEGER_OP(+,long long);
  ZORBA_INTEGER_OP(+,unsigned char);
  ZORBA_INTEGER_OP(+,unsigned short);
  ZORBA_INTEGER_OP(+,unsigned int);
  ZORBA_INTEGER_OP(+,unsigned long);
  ZORBA_INTEGER_OP(+,unsigned long long);
  ZORBA_INTEGER_OP(+,float);
  ZORBA_INTEGER_OP(+,double);

  ZORBA_INTEGER_OP(-,char);
  ZORBA_INTEGER_OP(-,signed char);
  ZORBA_INTEGER_OP(-,short);
  ZORBA_INTEGER_OP(-,int);
  ZORBA_INTEGER_OP(-,long);
  ZORBA_INTEGER_OP(-,long long);
  ZORBA_INTEGER_OP(-,unsigned char);
  ZORBA_INTEGER_OP(-,unsigned short);
  ZORBA_INTEGER_OP(-,unsigned int);
  ZORBA_INTEGER_OP(-,unsigned long);
  ZORBA_INTEGER_OP(-,unsigned long long);
  ZORBA_INTEGER_OP(-,float);
  ZORBA_INTEGER_OP(-,double);

  ZORBA_INTEGER_OP(*,char);
  ZORBA_INTEGER_OP(*,signed char);
  ZORBA_INTEGER_OP(*,short);
  ZORBA_INTEGER_OP(*,int);
  ZORBA_INTEGER_OP(*,long);
  ZORBA_INTEGER_OP(*,long long);
  ZORBA_INTEGER_OP(*,unsigned char);
  ZORBA_INTEGER_OP(*,unsigned short);
  ZORBA_INTEGER_OP(*,unsigned int);
  ZORBA_INTEGER_OP(*,unsigned long);
  ZORBA_INTEGER_OP(*,unsigned long long);
  ZORBA_INTEGER_OP(*,float);
  ZORBA_INTEGER_OP(*,double);

  ZORBA_INTEGER_OP(/,char);
  ZORBA_INTEGER_OP(/,signed char);
  ZORBA_INTEGER_OP(/,short);
  ZORBA_INTEGER_OP(/,int);
  ZORBA_INTEGER_OP(/,long);
  ZORBA_INTEGER_OP(/,long long);
  ZORBA_INTEGER_OP(/,unsigned char);
  ZORBA_INTEGER_OP(/,unsigned short);
  ZORBA_INTEGER_OP(/,unsigned int);
  ZORBA_INTEGER_OP(/,unsigned long);
  ZORBA_INTEGER_OP(/,unsigned long long);
  ZORBA_INTEGER_OP(/,float);
  ZORBA_INTEGER_OP(/,double);

  ZORBA_INTEGER_OP(%,char);
  ZORBA_INTEGER_OP(%,signed char);
  ZORBA_INTEGER_OP(%,short);
  ZORBA_INTEGER_OP(%,int);
  ZORBA_INTEGER_OP(%,long);
  ZORBA_INTEGER_OP(%,long long);
  ZORBA_INTEGER_OP(%,unsigned char);
  ZORBA_INTEGER_OP(%,unsigned short);
  ZORBA_INTEGER_OP(%,unsigned int);
  ZORBA_INTEGER_OP(%,unsigned long);
  ZORBA_INTEGER_OP(%,unsigned long long);
  ZORBA_INTEGER_OP(%,float);
  ZORBA_INTEGER_OP(%,double);
#undef ZORBA_INTEGER_OP
#endif /* ZORBA_WITH_BIG_INTEGER */

#define ZORBA_INTEGER_OP(OP,TYPE) \
  IntegerImpl& operator OP( TYPE )

  ZORBA_INTEGER_OP(+=,IntegerImpl const&);
  ZORBA_INTEGER_OP(-=,IntegerImpl const&);
  ZORBA_INTEGER_OP(*=,IntegerImpl const&);
  ZORBA_INTEGER_OP(/=,IntegerImpl const&);
  ZORBA_INTEGER_OP(%=,IntegerImpl const&);
#ifndef ZORBA_WITH_BIG_INTEGER
  ZORBA_INTEGER_OP(+=,char);
  ZORBA_INTEGER_OP(+=,signed char);
  ZORBA_INTEGER_OP(+=,short);
  ZORBA_INTEGER_OP(+=,int);
  ZORBA_INTEGER_OP(+=,long);
  ZORBA_INTEGER_OP(+=,long long);
  ZORBA_INTEGER_OP(+=,unsigned char);
  ZORBA_INTEGER_OP(+=,unsigned short);
  ZORBA_INTEGER_OP(+=,unsigned int);
  ZORBA_INTEGER_OP(+=,unsigned long);
  ZORBA_INTEGER_OP(+=,unsigned long long);
  ZORBA_INTEGER_OP(+=,float);
  ZORBA_INTEGER_OP(+=,double);

  ZORBA_INTEGER_OP(-=,char);
  ZORBA_INTEGER_OP(-=,signed char);
  ZORBA_INTEGER_OP(-=,short);
  ZORBA_INTEGER_OP(-=,int);
  ZORBA_INTEGER_OP(-=,long);
  ZORBA_INTEGER_OP(-=,long long);
  ZORBA_INTEGER_OP(-=,unsigned char);
  ZORBA_INTEGER_OP(-=,unsigned short);
  ZORBA_INTEGER_OP(-=,unsigned int);
  ZORBA_INTEGER_OP(-=,unsigned long);
  ZORBA_INTEGER_OP(-=,unsigned long long);
  ZORBA_INTEGER_OP(-=,float);
  ZORBA_INTEGER_OP(-=,double);

  ZORBA_INTEGER_OP(*=,char);
  ZORBA_INTEGER_OP(*=,signed char);
  ZORBA_INTEGER_OP(*=,short);
  ZORBA_INTEGER_OP(*=,int);
  ZORBA_INTEGER_OP(*=,long);
  ZORBA_INTEGER_OP(*=,long long);
  ZORBA_INTEGER_OP(*=,unsigned char);
  ZORBA_INTEGER_OP(*=,unsigned short);
  ZORBA_INTEGER_OP(*=,unsigned int);
  ZORBA_INTEGER_OP(*=,unsigned long);
  ZORBA_INTEGER_OP(*=,unsigned long long);
  ZORBA_INTEGER_OP(*=,float);
  ZORBA_INTEGER_OP(*=,double);

  ZORBA_INTEGER_OP(/=,char);
  ZORBA_INTEGER_OP(/=,signed char);
  ZORBA_INTEGER_OP(/=,short);
  ZORBA_INTEGER_OP(/=,int);
  ZORBA_INTEGER_OP(/=,long);
  ZORBA_INTEGER_OP(/=,long long);
  ZORBA_INTEGER_OP(/=,unsigned char);
  ZORBA_INTEGER_OP(/=,unsigned short);
  ZORBA_INTEGER_OP(/=,unsigned int);
  ZORBA_INTEGER_OP(/=,unsigned long);
  ZORBA_INTEGER_OP(/=,unsigned long long);
  ZORBA_INTEGER_OP(/=,float);
  ZORBA_INTEGER_OP(/=,double);

  ZORBA_INTEGER_OP(%=,char);
  ZORBA_INTEGER_OP(%=,signed char);
  ZORBA_INTEGER_OP(%=,short);
  ZORBA_INTEGER_OP(%=,int);
  ZORBA_INTEGER_OP(%=,long);
  ZORBA_INTEGER_OP(%=,long long);
  ZORBA_INTEGER_OP(%=,unsigned char);
  ZORBA_INTEGER_OP(%=,unsigned short);
  ZORBA_INTEGER_OP(%=,unsigned int);
  ZORBA_INTEGER_OP(%=,unsigned long);
  ZORBA_INTEGER_OP(%=,unsigned long long);
  ZORBA_INTEGER_OP(%=,float);
  ZORBA_INTEGER_OP(%=,double);
#endif /* ZORBA_WITH_BIG_INTEGER */

#undef ZORBA_INTEGER_OP

  IntegerImpl operator-() const;

  IntegerImpl& operator++();
  IntegerImpl  operator++(int);
  IntegerImpl& operator--();
  IntegerImpl  operator--(int);

  ////////// relational operators /////////////////////////////////////////////

#define ZORBA_INTEGER_OP(OP)                                          \
  TEMPLATE_DECL(T) friend                                             \
  bool operator OP( INTEGER_IMPL(T) const&, INTEGER_IMPL(T) const& ); \
  TEMPLATE_DECL(T) friend                                             \
  bool operator OP( INTEGER_IMPL(T) const&, Decimal const& );         \
  TEMPLATE_DECL(T) friend                                             \
  bool operator OP( Decimal const&, INTEGER_IMPL(T) const& )

  ZORBA_INTEGER_OP(==);
  ZORBA_INTEGER_OP(!=);
  ZORBA_INTEGER_OP(< );
  ZORBA_INTEGER_OP(<=);
  ZORBA_INTEGER_OP(> );
  ZORBA_INTEGER_OP(>=);
#undef ZORBA_INTEGER_OP

#ifndef ZORBA_WITH_BIG_INTEGER
#define ZORBA_INTEGER_OP(OP,TYPE)                   \
  TEMPLATE_DECL(T) friend                           \
  bool operator OP( INTEGER_IMPL(T) const&, TYPE ); \
  TEMPLATE_DECL(T) friend                           \
  bool operator OP( TYPE, INTEGER_IMPL(T) const& )

  ZORBA_INTEGER_OP(==,char);
  ZORBA_INTEGER_OP(==,signed char);
  ZORBA_INTEGER_OP(==,short);
  ZORBA_INTEGER_OP(==,int);
  ZORBA_INTEGER_OP(==,long);
  ZORBA_INTEGER_OP(==,long long);
  ZORBA_INTEGER_OP(==,unsigned char);
  ZORBA_INTEGER_OP(==,unsigned short);
  ZORBA_INTEGER_OP(==,unsigned int);
  ZORBA_INTEGER_OP(==,unsigned long);
  ZORBA_INTEGER_OP(==,unsigned long long);
  ZORBA_INTEGER_OP(==,float);
  ZORBA_INTEGER_OP(==,double);

  ZORBA_INTEGER_OP(!=,char);
  ZORBA_INTEGER_OP(!=,signed char);
  ZORBA_INTEGER_OP(!=,short);
  ZORBA_INTEGER_OP(!=,int);
  ZORBA_INTEGER_OP(!=,long);
  ZORBA_INTEGER_OP(!=,long long);
  ZORBA_INTEGER_OP(!=,unsigned char);
  ZORBA_INTEGER_OP(!=,unsigned short);
  ZORBA_INTEGER_OP(!=,unsigned int);
  ZORBA_INTEGER_OP(!=,unsigned long);
  ZORBA_INTEGER_OP(!=,unsigned long long);
  ZORBA_INTEGER_OP(!=,float);
  ZORBA_INTEGER_OP(!=,double);

  ZORBA_INTEGER_OP(< ,char);
  ZORBA_INTEGER_OP(< ,signed char);
  ZORBA_INTEGER_OP(< ,short);
  ZORBA_INTEGER_OP(< ,int);
  ZORBA_INTEGER_OP(< ,long);
  ZORBA_INTEGER_OP(< ,long long);
  ZORBA_INTEGER_OP(< ,unsigned char);
  ZORBA_INTEGER_OP(< ,unsigned short);
  ZORBA_INTEGER_OP(< ,unsigned int);
  ZORBA_INTEGER_OP(< ,unsigned long);
  ZORBA_INTEGER_OP(< ,unsigned long long);
  ZORBA_INTEGER_OP(< ,float);
  ZORBA_INTEGER_OP(< ,double);

  ZORBA_INTEGER_OP(<=,char);
  ZORBA_INTEGER_OP(<=,signed char);
  ZORBA_INTEGER_OP(<=,short);
  ZORBA_INTEGER_OP(<=,int);
  ZORBA_INTEGER_OP(<=,long);
  ZORBA_INTEGER_OP(<=,long long);
  ZORBA_INTEGER_OP(<=,unsigned char);
  ZORBA_INTEGER_OP(<=,unsigned short);
  ZORBA_INTEGER_OP(<=,unsigned int);
  ZORBA_INTEGER_OP(<=,unsigned long);
  ZORBA_INTEGER_OP(<=,unsigned long long);
  ZORBA_INTEGER_OP(<=,float);
  ZORBA_INTEGER_OP(<=,double);

  ZORBA_INTEGER_OP(> ,char);
  ZORBA_INTEGER_OP(> ,signed char);
  ZORBA_INTEGER_OP(> ,short);
  ZORBA_INTEGER_OP(> ,int);
  ZORBA_INTEGER_OP(> ,long);
  ZORBA_INTEGER_OP(> ,long long);
  ZORBA_INTEGER_OP(> ,unsigned char);
  ZORBA_INTEGER_OP(> ,unsigned short);
  ZORBA_INTEGER_OP(> ,unsigned int);
  ZORBA_INTEGER_OP(> ,unsigned long);
  ZORBA_INTEGER_OP(> ,unsigned long long);
  ZORBA_INTEGER_OP(> ,float);
  ZORBA_INTEGER_OP(> ,double);

  ZORBA_INTEGER_OP(>=,char);
  ZORBA_INTEGER_OP(>=,signed char);
  ZORBA_INTEGER_OP(>=,short);
  ZORBA_INTEGER_OP(>=,int);
  ZORBA_INTEGER_OP(>=,long);
  ZORBA_INTEGER_OP(>=,long long);
  ZORBA_INTEGER_OP(>=,unsigned char);
  ZORBA_INTEGER_OP(>=,unsigned short);
  ZORBA_INTEGER_OP(>=,unsigned int);
  ZORBA_INTEGER_OP(>=,unsigned long);
  ZORBA_INTEGER_OP(>=,unsigned long long);
  ZORBA_INTEGER_OP(>=,float);
  ZORBA_INTEGER_OP(>=,double);
#undef ZORBA_INTEGER_OP
#endif /* ZORBA_WITH_BIG_INTEGER */

  ////////// math functions ///////////////////////////////////////////////////

  Double pow( IntegerImpl const &power ) const;
  IntegerImpl round( IntegerImpl const &precision ) const;
  IntegerImpl roundHalfToEven( IntegerImpl const &precision ) const;

  ////////// miscellaneous ////////////////////////////////////////////////////

  int compare( IntegerImpl const& ) const;
  uint32_t hash() const;
  int sign() const;
  zstring toString() const;
  static IntegerImpl const& one();
  static IntegerImpl const& zero();

  /////////////////////////////////////////////////////////////////////////////

private:
#ifdef ZORBA_WITH_BIG_INTEGER
  typedef MAPM value_type;
#else
  typedef IntType value_type;
#endif /* ZORBA_WITH_BIG_INTEGER */

  value_type value_;

#ifdef ZORBA_WITH_BIG_INTEGER
  IntegerImpl( value_type const &v ) : value_( v ) { }
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

#ifndef ZORBA_WITH_BIG_INTEGER
  template<typename U> friend class IntegerImpl;
#endif /* ZORBA_WITH_BIG_INTEGER */

  friend xs_int to_xs_int( INTEGER_IMPL_LL const& );
  friend xs_long to_xs_long( INTEGER_IMPL_LL const& );
  friend xs_unsignedInt to_xs_unsignedInt( INTEGER_IMPL_LL const& );
  friend xs_unsignedLong to_xs_unsignedLong( INTEGER_IMPL_LL const& );

  TEMPLATE_DECL(T) friend
  void serialization::operator&( serialization::Archiver&, INTEGER_IMPL(T)& );
};

typedef INTEGER_IMPL_LL Integer;
typedef INTEGER_IMPL_ULL UInteger;

////////// constructors ///////////////////////////////////////////////////////

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)::IntegerImpl( char c ) :
  value_( static_cast<long>( c ) )
{
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)::IntegerImpl( signed char c ) :
  value_( static_cast<long>( c ) )
{
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)::IntegerImpl( short n ) :
  value_( static_cast<long>( n ) )
{
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)::IntegerImpl( int n ) :
  value_( static_cast<long>( n ) )
{
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)::IntegerImpl( long n ) :
  value_( n )
{
}

#ifndef ZORBA_WITH_BIG_INTEGER
TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)::IntegerImpl( long long n ) :
  value_( n )
{
}
#endif /* ZORBA_WITH_BIG_INTEGER */

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)::IntegerImpl( unsigned char c ) :
  value_( static_cast<long>( c ) )
{
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)::IntegerImpl( unsigned short n ) :
  value_( static_cast<long>( n ) )
{
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)::IntegerImpl( unsigned int n ) :
  value_( static_cast<long>( n ) )
{
}

#ifndef ZORBA_WITH_BIG_INTEGER
TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)::IntegerImpl( unsigned long n ) :
  value_( static_cast<value_type>( n ) )
{
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)::IntegerImpl( unsigned long long n ) :
  value_( static_cast<value_type>( n ) )
{
}
#endif /* ZORBA_WITH_BIG_INTEGER */

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)::IntegerImpl( float n ) :
#ifdef ZORBA_WITH_BIG_INTEGER
  value_( static_cast<double>( n ) )
#else
  value_( static_cast<value_type>( n ) )
#endif /* ZORBA_WITH_BIG_INTEGER */
{
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)::IntegerImpl( double n ) :
#ifdef ZORBA_WITH_BIG_INTEGER
  value_( n )
#else
  value_( static_cast<value_type>( n ) )
#endif /* ZORBA_WITH_BIG_INTEGER */
{
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)::IntegerImpl( char const *s ) {
  parse( s );
}

TEMPLATE_DECL(T)
TEMPLATE_DECL(U)
inline INTEGER_IMPL(T)::IntegerImpl( INTEGER_IMPL(U) const &i ) :
  value_( i.value_ )
{
}

////////// assignment operators ///////////////////////////////////////////////

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( char c ) {
  value_ = static_cast<long>( c );
  return *this;
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( signed char c ) {
  value_ = static_cast<long>( c );
  return *this;
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( short n ) {
  value_ = static_cast<long>( n );
  return *this;
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( int n ) {
  value_ = static_cast<long>( n );
  return *this;
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( long n ) {
  value_ = n;
  return *this;
}

#ifndef ZORBA_WITH_BIG_INTEGER
TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( long long n ) {
  value_ = n;
  return *this;
}
#endif /* ZORBA_WITH_BIG_INTEGER */

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( unsigned char c ) {
  value_ = static_cast<long>( c );
  return *this;
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( unsigned short n ) {
  value_ = static_cast<long>( n );
  return *this;
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( unsigned int n ) {
  value_ = static_cast<long>( n );
  return *this;
}

#ifndef ZORBA_WITH_BIG_INTEGER
TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( unsigned long n ) {
  value_ = static_cast<long>( n );
  return *this;
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( unsigned long long n ) {
  value_ = n;
  return *this;
}
#endif /* ZORBA_WITH_BIG_INTEGER */

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( float n ) {
  value_ = static_cast<long>( n );
  return *this;
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( double n ) {
  value_ = static_cast<long>( n );
  return *this;
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( char const *s ) {
  parse( s );
  return *this;
}

TEMPLATE_DECL(T)
TEMPLATE_DECL(U)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator=( INTEGER_IMPL(U) const &i ) {
  value_ = i.value_;
  return *this;
}

////////// arithmetic operators ///////////////////////////////////////////////

#define ZORBA_INTEGER_OP(OP)                                \
  TEMPLATE_DECL(T) inline                                   \
  INTEGER_IMPL(T) operator OP( INTEGER_IMPL(T) const &i,    \
                               INTEGER_IMPL(T) const &j ) { \
    return i.value_ OP j.value_;                            \
  }

ZORBA_INTEGER_OP(+)
ZORBA_INTEGER_OP(-)
ZORBA_INTEGER_OP(*)
ZORBA_INTEGER_OP(%)
#undef ZORBA_INTEGER_OP

TEMPLATE_DECL(T) inline
INTEGER_IMPL(T) operator/( INTEGER_IMPL(T) const &i, INTEGER_IMPL(T) const &j ) {
  return INTEGER_IMPL(T)::ftoi( i.value_ / j.value_ );
}

#ifndef ZORBA_WITH_BIG_INTEGER
#define ZORBA_INTEGER_OP(OP,TYPE)                                   \
  TEMPLATE_DECL(T) inline                                           \
  INTEGER_IMPL(T) operator OP( INTEGER_IMPL(T) const& i, TYPE n ) { \
    return i.value_ OP static_cast<long>( n );                      \
  }                                                                 \
  TEMPLATE_DECL(T) inline                                           \
  INTEGER_IMPL(T) operator OP( TYPE n, INTEGER_IMPL(T) const &i ) { \
    return static_cast<long>( n ) OP i.value_;                      \
  }

ZORBA_INTEGER_OP(+,char)
ZORBA_INTEGER_OP(+,signed char)
ZORBA_INTEGER_OP(+,short)
ZORBA_INTEGER_OP(+,int)
ZORBA_INTEGER_OP(+,long)
ZORBA_INTEGER_OP(+,long long)
ZORBA_INTEGER_OP(+,unsigned char)
ZORBA_INTEGER_OP(+,unsigned short)
ZORBA_INTEGER_OP(+,unsigned int)
ZORBA_INTEGER_OP(+,unsigned long)
ZORBA_INTEGER_OP(+,unsigned long long)
ZORBA_INTEGER_OP(+,float)
ZORBA_INTEGER_OP(+,double)

ZORBA_INTEGER_OP(-,char)
ZORBA_INTEGER_OP(-,signed char)
ZORBA_INTEGER_OP(-,short)
ZORBA_INTEGER_OP(-,int)
ZORBA_INTEGER_OP(-,long)
ZORBA_INTEGER_OP(-,long long)
ZORBA_INTEGER_OP(-,unsigned char)
ZORBA_INTEGER_OP(-,unsigned short)
ZORBA_INTEGER_OP(-,unsigned int)
ZORBA_INTEGER_OP(-,unsigned long)
ZORBA_INTEGER_OP(-,unsigned long long)
ZORBA_INTEGER_OP(-,float)
ZORBA_INTEGER_OP(-,double)

ZORBA_INTEGER_OP(*,char)
ZORBA_INTEGER_OP(*,signed char)
ZORBA_INTEGER_OP(*,short)
ZORBA_INTEGER_OP(*,int)
ZORBA_INTEGER_OP(*,long)
ZORBA_INTEGER_OP(*,long long)
ZORBA_INTEGER_OP(*,unsigned char)
ZORBA_INTEGER_OP(*,unsigned short)
ZORBA_INTEGER_OP(*,unsigned int)
ZORBA_INTEGER_OP(*,unsigned long)
ZORBA_INTEGER_OP(*,unsigned long long)
ZORBA_INTEGER_OP(*,float)
ZORBA_INTEGER_OP(*,double)

ZORBA_INTEGER_OP(%,char)
ZORBA_INTEGER_OP(%,signed char)
ZORBA_INTEGER_OP(%,short)
ZORBA_INTEGER_OP(%,int)
ZORBA_INTEGER_OP(%,long)
ZORBA_INTEGER_OP(%,long long)
ZORBA_INTEGER_OP(%,unsigned char)
ZORBA_INTEGER_OP(%,unsigned short)
ZORBA_INTEGER_OP(%,unsigned int)
ZORBA_INTEGER_OP(%,unsigned long)
ZORBA_INTEGER_OP(%,unsigned long long)
ZORBA_INTEGER_OP(%,float)
ZORBA_INTEGER_OP(%,double)
#undef ZORBA_INTEGER_OP

#define ZORBA_INTEGER_DIV(TYPE)                                   \
  TEMPLATE_DECL(T) inline                                         \
  INTEGER_IMPL(T) operator/( INTEGER_IMPL(T) const& i, TYPE n ) { \
    return INTEGER_IMPL(T)::ftoi( i.value_ / n );                 \
  }                                                               \
  TEMPLATE_DECL(T) inline                                         \
  INTEGER_IMPL(T) operator/( TYPE n, INTEGER_IMPL(T) const &i ) { \
    return INTEGER_IMPL(T)::ftoi( n / i.value_ );                 \
  }
ZORBA_INTEGER_DIV(char)
ZORBA_INTEGER_DIV(signed char)
ZORBA_INTEGER_DIV(short)
ZORBA_INTEGER_DIV(int)
ZORBA_INTEGER_DIV(long)
ZORBA_INTEGER_DIV(long long)
ZORBA_INTEGER_DIV(unsigned char)
ZORBA_INTEGER_DIV(unsigned short)
ZORBA_INTEGER_DIV(unsigned int)
ZORBA_INTEGER_DIV(unsigned long)
ZORBA_INTEGER_DIV(unsigned long long)
ZORBA_INTEGER_DIV(float)
ZORBA_INTEGER_DIV(double)
#undef ZORBA_INTEGER_DIV
#endif /* ZORBA_WITH_BIG_INTEGER */

#define ZORBA_INTEGER_OP(OP)                                              \
  TEMPLATE_DECL(T) inline                                                 \
  INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator OP( IntegerImpl const &i ) { \
    value_ OP i.value_;                                                   \
    return *this;                                                         \
  }

ZORBA_INTEGER_OP(+=)
ZORBA_INTEGER_OP(-=)
ZORBA_INTEGER_OP(*=)
ZORBA_INTEGER_OP(%=)
#undef ZORBA_INTEGER_OP

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator/=( IntegerImpl const &i ) {
  value_ = ftoi( value_ / i.value_ );
  return *this;
}

#ifndef ZORBA_WITH_BIG_INTEGER
#define ZORBA_INTEGER_OP(OP,TYPE)                           \
  TEMPLATE_DECL(T) inline                                   \
  INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator OP( TYPE n ) { \
    value_ OP static_cast<long>( n );                       \
    return *this;                                           \
  }

ZORBA_INTEGER_OP(+=,char)
ZORBA_INTEGER_OP(+=,signed char)
ZORBA_INTEGER_OP(+=,short)
ZORBA_INTEGER_OP(+=,int)
ZORBA_INTEGER_OP(+=,long)
ZORBA_INTEGER_OP(+=,long long)
ZORBA_INTEGER_OP(+=,unsigned char)
ZORBA_INTEGER_OP(+=,unsigned short)
ZORBA_INTEGER_OP(+=,unsigned int)
ZORBA_INTEGER_OP(+=,unsigned long)
ZORBA_INTEGER_OP(+=,unsigned long long)
ZORBA_INTEGER_OP(+=,float)
ZORBA_INTEGER_OP(+=,double)

ZORBA_INTEGER_OP(-=,char)
ZORBA_INTEGER_OP(-=,signed char)
ZORBA_INTEGER_OP(-=,short)
ZORBA_INTEGER_OP(-=,int)
ZORBA_INTEGER_OP(-=,long)
ZORBA_INTEGER_OP(-=,long long)
ZORBA_INTEGER_OP(-=,unsigned char)
ZORBA_INTEGER_OP(-=,unsigned short)
ZORBA_INTEGER_OP(-=,unsigned int)
ZORBA_INTEGER_OP(-=,unsigned long)
ZORBA_INTEGER_OP(-=,unsigned long long)
ZORBA_INTEGER_OP(-=,float)
ZORBA_INTEGER_OP(-=,double)

ZORBA_INTEGER_OP(*=,char)
ZORBA_INTEGER_OP(*=,signed char)
ZORBA_INTEGER_OP(*=,short)
ZORBA_INTEGER_OP(*=,int)
ZORBA_INTEGER_OP(*=,long)
ZORBA_INTEGER_OP(*=,long long)
ZORBA_INTEGER_OP(*=,unsigned char)
ZORBA_INTEGER_OP(*=,unsigned short)
ZORBA_INTEGER_OP(*=,unsigned int)
ZORBA_INTEGER_OP(*=,unsigned long)
ZORBA_INTEGER_OP(*=,unsigned long long)
ZORBA_INTEGER_OP(*=,float)
ZORBA_INTEGER_OP(*=,double)

ZORBA_INTEGER_OP(%=,char)
ZORBA_INTEGER_OP(%=,signed char)
ZORBA_INTEGER_OP(%=,short)
ZORBA_INTEGER_OP(%=,int)
ZORBA_INTEGER_OP(%=,long)
ZORBA_INTEGER_OP(%=,long long)
ZORBA_INTEGER_OP(%=,unsigned char)
ZORBA_INTEGER_OP(%=,unsigned short)
ZORBA_INTEGER_OP(%=,unsigned int)
ZORBA_INTEGER_OP(%=,unsigned long)
ZORBA_INTEGER_OP(%=,unsigned long long)
ZORBA_INTEGER_OP(%=,float)
ZORBA_INTEGER_OP(%=,double)
#undef ZORBA_INTEGER_OP

#define ZORBA_INTEGER_DIV(TYPE)                             \
  TEMPLATE_DECL(T) inline                                   \
  INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator/=( TYPE n ) {  \
    value_ = ftoi( value_ / n );                            \
    return *this;                                           \
  }

ZORBA_INTEGER_DIV(char)
ZORBA_INTEGER_DIV(signed char)
ZORBA_INTEGER_DIV(short)
ZORBA_INTEGER_DIV(int)
ZORBA_INTEGER_DIV(long)
ZORBA_INTEGER_DIV(long long)
ZORBA_INTEGER_DIV(unsigned char)
ZORBA_INTEGER_DIV(unsigned short)
ZORBA_INTEGER_DIV(unsigned int)
ZORBA_INTEGER_DIV(unsigned long)
ZORBA_INTEGER_DIV(unsigned long long)
ZORBA_INTEGER_DIV(float)
ZORBA_INTEGER_DIV(double)
#undef ZORBA_INTEGER_DIV
#endif /* ZORBA_WITH_BIG_INTEGER */

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T) INTEGER_IMPL(T)::operator-() const {
  return -value_;
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator++() {
  ++value_;
  return *this;
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T) INTEGER_IMPL(T)::operator++(int) {
  INTEGER_IMPL(T) const result( *this );
  ++value_;
  return result;
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T)& INTEGER_IMPL(T)::operator--() {
  --value_;
  return *this;
}

TEMPLATE_DECL(T)
inline INTEGER_IMPL(T) INTEGER_IMPL(T)::operator--(int) {
  INTEGER_IMPL(T) const result( *this );
  --value_;
  return result;
}

////////// relational operators ///////////////////////////////////////////////

#define ZORBA_INTEGER_OP(OP)                                                \
  TEMPLATE_DECL(T) inline                                                   \
  bool operator OP( INTEGER_IMPL(T) const &i, INTEGER_IMPL(T) const &j ) {  \
    return i.value_ OP j.value_;                                            \
  }

ZORBA_INTEGER_OP(==)
ZORBA_INTEGER_OP(!=)
ZORBA_INTEGER_OP(< )
ZORBA_INTEGER_OP(<=)
ZORBA_INTEGER_OP(> )
ZORBA_INTEGER_OP(>=)
#undef ZORBA_INTEGER_OP

#ifndef ZORBA_WITH_BIG_INTEGER
#define ZORBA_INTEGER_OP(OP,TYPE)                         \
  TEMPLATE_DECL(T) inline                                 \
  bool operator OP( INTEGER_IMPL(T) const &i, TYPE n ) {  \
    return i.value_ OP static_cast<long>( n );            \
  }                                                       \
  TEMPLATE_DECL(T) inline                                 \
  bool operator OP( TYPE n, INTEGER_IMPL(T) const &i ) {  \
    return static_cast<long>( n ) OP i.value_;            \
  }                                                       \

  ZORBA_INTEGER_OP(==,char);
  ZORBA_INTEGER_OP(==,signed char);
  ZORBA_INTEGER_OP(==,short);
  ZORBA_INTEGER_OP(==,int);
  ZORBA_INTEGER_OP(==,long);
  ZORBA_INTEGER_OP(==,long long);
  ZORBA_INTEGER_OP(==,unsigned char);
  ZORBA_INTEGER_OP(==,unsigned short);
  ZORBA_INTEGER_OP(==,unsigned int);
  ZORBA_INTEGER_OP(==,unsigned long);
  ZORBA_INTEGER_OP(==,unsigned long long);
  ZORBA_INTEGER_OP(==,float);
  ZORBA_INTEGER_OP(==,double);

  ZORBA_INTEGER_OP(!=,char);
  ZORBA_INTEGER_OP(!=,signed char);
  ZORBA_INTEGER_OP(!=,short);
  ZORBA_INTEGER_OP(!=,int);
  ZORBA_INTEGER_OP(!=,long);
  ZORBA_INTEGER_OP(!=,long long);
  ZORBA_INTEGER_OP(!=,unsigned char);
  ZORBA_INTEGER_OP(!=,unsigned short);
  ZORBA_INTEGER_OP(!=,unsigned int);
  ZORBA_INTEGER_OP(!=,unsigned long);
  ZORBA_INTEGER_OP(!=,unsigned long long);
  ZORBA_INTEGER_OP(!=,float);
  ZORBA_INTEGER_OP(!=,double);

  ZORBA_INTEGER_OP(< ,char);
  ZORBA_INTEGER_OP(< ,signed char);
  ZORBA_INTEGER_OP(< ,short);
  ZORBA_INTEGER_OP(< ,int);
  ZORBA_INTEGER_OP(< ,long);
  ZORBA_INTEGER_OP(< ,long long);
  ZORBA_INTEGER_OP(< ,unsigned char);
  ZORBA_INTEGER_OP(< ,unsigned short);
  ZORBA_INTEGER_OP(< ,unsigned int);
  ZORBA_INTEGER_OP(< ,unsigned long);
  ZORBA_INTEGER_OP(< ,unsigned long long);
  ZORBA_INTEGER_OP(< ,float);
  ZORBA_INTEGER_OP(< ,double);

  ZORBA_INTEGER_OP(<=,char);
  ZORBA_INTEGER_OP(<=,signed char);
  ZORBA_INTEGER_OP(<=,short);
  ZORBA_INTEGER_OP(<=,int);
  ZORBA_INTEGER_OP(<=,long);
  ZORBA_INTEGER_OP(<=,long long);
  ZORBA_INTEGER_OP(<=,unsigned char);
  ZORBA_INTEGER_OP(<=,unsigned short);
  ZORBA_INTEGER_OP(<=,unsigned int);
  ZORBA_INTEGER_OP(<=,unsigned long);
  ZORBA_INTEGER_OP(<=,unsigned long long);
  ZORBA_INTEGER_OP(<=,float);
  ZORBA_INTEGER_OP(<=,double);

  ZORBA_INTEGER_OP(> ,char);
  ZORBA_INTEGER_OP(> ,signed char);
  ZORBA_INTEGER_OP(> ,short);
  ZORBA_INTEGER_OP(> ,int);
  ZORBA_INTEGER_OP(> ,long);
  ZORBA_INTEGER_OP(> ,long long);
  ZORBA_INTEGER_OP(> ,unsigned char);
  ZORBA_INTEGER_OP(> ,unsigned short);
  ZORBA_INTEGER_OP(> ,unsigned int);
  ZORBA_INTEGER_OP(> ,unsigned long);
  ZORBA_INTEGER_OP(> ,unsigned long long);
  ZORBA_INTEGER_OP(> ,float);
  ZORBA_INTEGER_OP(> ,double);

  ZORBA_INTEGER_OP(>=,char);
  ZORBA_INTEGER_OP(>=,signed char);
  ZORBA_INTEGER_OP(>=,short);
  ZORBA_INTEGER_OP(>=,int);
  ZORBA_INTEGER_OP(>=,long);
  ZORBA_INTEGER_OP(>=,long long);
  ZORBA_INTEGER_OP(>=,unsigned char);
  ZORBA_INTEGER_OP(>=,unsigned short);
  ZORBA_INTEGER_OP(>=,unsigned int);
  ZORBA_INTEGER_OP(>=,unsigned long);
  ZORBA_INTEGER_OP(>=,unsigned long long);
  ZORBA_INTEGER_OP(>=,float);
  ZORBA_INTEGER_OP(>=,double);
#undef ZORBA_INTEGER_OP
#endif /* ZORBA_WITH_BIG_INTEGER */

////////// miscellaneous //////////////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER

inline int IntegerImpl::compare( IntegerImpl const &i ) const {
  return value_.compare( i.value_ );
}

inline int IntegerImpl::sign() const {
  return value_.sign();
}

#else

template<typename IntType>
inline int IntegerImpl<IntType>::compare( IntegerImpl const &i ) const {
  return value_ < i.value_ ? -1 : value_ > i.value_ ? 1 : 0;
}

template<typename IntType>
inline uint32_t IntegerImpl<IntType>::hash() const {
  return static_cast<uint32_t>( value_ );
}

template<typename IntType>
inline bool IntegerImpl<IntType>::is_long() const {
  return  value_ >= std::numeric_limits<long>::min() &&
          value_ <= std::numeric_limits<long>::max();
}

template<typename IntType>
inline int IntegerImpl<IntType>::sign() const {
  return ztd::lt0( value_ ) ? -1 : value_ > 0 ? 1 : 0;
}

#endif /* ZORBA_WITH_BIG_INTEGER */

TEMPLATE_DECL(T)
inline std::ostream& operator<<( std::ostream &os, INTEGER_IMPL(T) const &i ) {
  return os << i.toString();
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#undef TEMPLATE_DECL
#undef INTEGER_IMPL
#undef INTEGER_IMPL_LL
#undef INTEGER_IMPL_ULL

#endif // ZORBA_INTEGER_H
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
