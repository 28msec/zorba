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

#include "m_apm.h"
#include "schema_types_base.h"
#include "zorbatypes_decl.h"
#include "zstring.h"

#ifdef ZORBA_WITH_BIG_INTEGER
# define TEMPLATE_DECL(I)   /* nothing */
# define INTEGER_IMPL(I)    IntegerImpl
# define TEMPLATE_TYPENAME  /* nothing */
#else
# define TEMPLATE_DECL(I)   template<typename I> /* spacer */
# define INTEGER_IMPL(I)    IntegerImpl<I> /* spacer */
# define TEMPLATE_TYPENAME  typename
#endif /* ZORBA_WITH_BIG_INTEGER */
#define INTEGER_IMPL_LL   INTEGER_IMPL(long long)
#define INTEGER_IMPL_ULL  INTEGER_IMPL(unsigned long long)

namespace zorba {

TEMPLATE_DECL(I)
class IntegerImpl;

namespace serialization 
{
  class Archiver;
  TEMPLATE_DECL(I) void operator&( Archiver&, INTEGER_IMPL(I)& );
}

///////////////////////////////////////////////////////////////////////////////

TEMPLATE_DECL(IntType)
class IntegerImpl 
{
public:
#ifdef ZORBA_WITH_BIG_INTEGER
  typedef MAPM value_type;
#else
  typedef IntType value_type;
#endif /* ZORBA_WITH_BIG_INTEGER */

  ////////// constructors /////////////////////////////////////////////////////

  explicit IntegerImpl( char c );
  explicit IntegerImpl( signed char c );
  explicit IntegerImpl( short n );
  explicit IntegerImpl( int n = 0 );
  explicit IntegerImpl( long n );
  explicit IntegerImpl( long long n );
  explicit IntegerImpl( unsigned char c );
  explicit IntegerImpl( unsigned short n );
  explicit IntegerImpl( unsigned int n );
  explicit IntegerImpl( unsigned long n );
  explicit IntegerImpl( unsigned long long n );
  explicit IntegerImpl( float n );
  explicit IntegerImpl( double n );
  explicit IntegerImpl( Decimal const &d );

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
  explicit IntegerImpl( char const *s );

  /**
   * Constructs an %IntegerImpl from a Double.
   *
   * @param d The Double.
   * @throw std::invalid_argument if \a d is not finite.
   */
  explicit IntegerImpl( Double const &d );

  /**
   * Constructs an %IntegerImpl from a Float.
   *
   * @param f The Float.
   * @throw std::invalid_argument if \a f is not finite.
   */
  explicit IntegerImpl( Float const &f );

  /**
   * Constructs from another %IntegerImpl even if its \c IntType is different.
   * (This subsumes the conventional copy constructor.)
   *
   * @tparam IntType2 the integer type of \a i.
   * @param i The %IntegerImpl to copy from.
   */
  TEMPLATE_DECL(IntType2)
  IntegerImpl( INTEGER_IMPL(IntType2) const &i );

  ////////// assignment operators /////////////////////////////////////////////

  /**
   * Assign from an %IntegerImpl even if its \c IntType is different.
   * (This subsumes the conventional assignment operator.)
   *
   * @tparam IntType2 the integer type of \a i.
   * @param i The %IntegerImpl to assign from.
   * @return Returns \c *this.
   */
  TEMPLATE_DECL(IntType2)
  IntegerImpl& operator=( INTEGER_IMPL(IntType2) const &i );

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

  ////////// arithmetic operators /////////////////////////////////////////////

#define ZORBA_INTEGER_OP(OP)                                      \
  TEMPLATE_DECL(I) friend                                         \
  INTEGER_IMPL(I) operator OP( INTEGER_IMPL(I) const&,            \
                               INTEGER_IMPL(I) const& );          \
                                                                  \
  TEMPLATE_DECL(I) friend                                         \
  Decimal operator OP( INTEGER_IMPL(I) const&, Decimal const& );  \
                                                                  \
  TEMPLATE_DECL(I) friend                                         \
  Decimal operator OP( Decimal const&, INTEGER_IMPL(I) const& )

  ZORBA_INTEGER_OP(+);
  ZORBA_INTEGER_OP(-);
  ZORBA_INTEGER_OP(*);
  ZORBA_INTEGER_OP(/);
  ZORBA_INTEGER_OP(%);
#undef ZORBA_INTEGER_OP

#define ZORBA_INTEGER_OP(OP,T)                              \
  TEMPLATE_DECL(I) friend                                   \
  INTEGER_IMPL(I) operator OP( INTEGER_IMPL(I) const&, T ); \
                                                            \
  TEMPLATE_DECL(I) friend                                   \
  INTEGER_IMPL(I) operator OP( T, INTEGER_IMPL(I) const& )

  ZORBA_INTEGER_OP(+,char);
  ZORBA_INTEGER_OP(-,char);
  ZORBA_INTEGER_OP(*,char);
  ZORBA_INTEGER_OP(/,char);
  ZORBA_INTEGER_OP(%,char);
  ZORBA_INTEGER_OP(+,signed char);
  ZORBA_INTEGER_OP(-,signed char);
  ZORBA_INTEGER_OP(*,signed char);
  ZORBA_INTEGER_OP(/,signed char);
  ZORBA_INTEGER_OP(%,signed char);
  ZORBA_INTEGER_OP(+,short);
  ZORBA_INTEGER_OP(-,short);
  ZORBA_INTEGER_OP(*,short);
  ZORBA_INTEGER_OP(/,short);
  ZORBA_INTEGER_OP(%,short);
  ZORBA_INTEGER_OP(+,int);
  ZORBA_INTEGER_OP(-,int);
  ZORBA_INTEGER_OP(*,int);
  ZORBA_INTEGER_OP(/,int);
  ZORBA_INTEGER_OP(%,int);
  ZORBA_INTEGER_OP(+,long);
  ZORBA_INTEGER_OP(-,long);
  ZORBA_INTEGER_OP(*,long);
  ZORBA_INTEGER_OP(/,long);
  ZORBA_INTEGER_OP(%,long);
  ZORBA_INTEGER_OP(+,long long);
  ZORBA_INTEGER_OP(-,long long);
  ZORBA_INTEGER_OP(*,long long);
  ZORBA_INTEGER_OP(/,long long);
  ZORBA_INTEGER_OP(%,long long);
  ZORBA_INTEGER_OP(+,unsigned char);
  ZORBA_INTEGER_OP(-,unsigned char);
  ZORBA_INTEGER_OP(*,unsigned char);
  ZORBA_INTEGER_OP(/,unsigned char);
  ZORBA_INTEGER_OP(%,unsigned char);
  ZORBA_INTEGER_OP(+,unsigned short);
  ZORBA_INTEGER_OP(-,unsigned short);
  ZORBA_INTEGER_OP(*,unsigned short);
  ZORBA_INTEGER_OP(/,unsigned short);
  ZORBA_INTEGER_OP(%,unsigned short);
  ZORBA_INTEGER_OP(+,unsigned int);
  ZORBA_INTEGER_OP(-,unsigned int);
  ZORBA_INTEGER_OP(*,unsigned int);
  ZORBA_INTEGER_OP(/,unsigned int);
  ZORBA_INTEGER_OP(%,unsigned int);
  ZORBA_INTEGER_OP(+,unsigned long);
  ZORBA_INTEGER_OP(-,unsigned long);
  ZORBA_INTEGER_OP(*,unsigned long);
  ZORBA_INTEGER_OP(/,unsigned long);
  ZORBA_INTEGER_OP(%,unsigned long);
  ZORBA_INTEGER_OP(+,unsigned long long);
  ZORBA_INTEGER_OP(-,unsigned long long);
  ZORBA_INTEGER_OP(*,unsigned long long);
  ZORBA_INTEGER_OP(/,unsigned long long);
  ZORBA_INTEGER_OP(%,unsigned long long);
  ZORBA_INTEGER_OP(+,float);
  ZORBA_INTEGER_OP(-,float);
  ZORBA_INTEGER_OP(*,float);
  ZORBA_INTEGER_OP(/,float);
  ZORBA_INTEGER_OP(%,float);
  ZORBA_INTEGER_OP(+,double);
  ZORBA_INTEGER_OP(-,double);
  ZORBA_INTEGER_OP(*,double);
  ZORBA_INTEGER_OP(/,double);
  ZORBA_INTEGER_OP(%,double);
#undef ZORBA_INTEGER_OP

#define ZORBA_INTEGER_OP(OP,TYPE) \
  IntegerImpl& operator OP( TYPE )

  ZORBA_INTEGER_OP(+=,IntegerImpl const&);
  ZORBA_INTEGER_OP(-=,IntegerImpl const&);
  ZORBA_INTEGER_OP(*=,IntegerImpl const&);
  ZORBA_INTEGER_OP(/=,IntegerImpl const&);
  ZORBA_INTEGER_OP(%=,IntegerImpl const&);
#undef ZORBA_INTEGER_OP

#define ZORBA_INTEGER_OP(OP,T) \
  IntegerImpl& operator OP( T )

  ZORBA_INTEGER_OP(+=,char);
  ZORBA_INTEGER_OP(-=,char);
  ZORBA_INTEGER_OP(*=,char);
  ZORBA_INTEGER_OP(/=,char);
  ZORBA_INTEGER_OP(%=,char);
  ZORBA_INTEGER_OP(+=,signed char);
  ZORBA_INTEGER_OP(-=,signed char);
  ZORBA_INTEGER_OP(*=,signed char);
  ZORBA_INTEGER_OP(/=,signed char);
  ZORBA_INTEGER_OP(%=,signed char);
  ZORBA_INTEGER_OP(+=,short);
  ZORBA_INTEGER_OP(-=,short);
  ZORBA_INTEGER_OP(*=,short);
  ZORBA_INTEGER_OP(/=,short);
  ZORBA_INTEGER_OP(%=,short);
  ZORBA_INTEGER_OP(+=,int);
  ZORBA_INTEGER_OP(-=,int);
  ZORBA_INTEGER_OP(*=,int);
  ZORBA_INTEGER_OP(/=,int);
  ZORBA_INTEGER_OP(%=,int);
  ZORBA_INTEGER_OP(+=,long);
  ZORBA_INTEGER_OP(-=,long);
  ZORBA_INTEGER_OP(*=,long);
  ZORBA_INTEGER_OP(/=,long);
  ZORBA_INTEGER_OP(%=,long);
  ZORBA_INTEGER_OP(+=,long long);
  ZORBA_INTEGER_OP(-=,long long);
  ZORBA_INTEGER_OP(*=,long long);
  ZORBA_INTEGER_OP(/=,long long);
  ZORBA_INTEGER_OP(%=,long long);
  ZORBA_INTEGER_OP(+=,unsigned char);
  ZORBA_INTEGER_OP(-=,unsigned char);
  ZORBA_INTEGER_OP(*=,unsigned char);
  ZORBA_INTEGER_OP(/=,unsigned char);
  ZORBA_INTEGER_OP(%=,unsigned char);
  ZORBA_INTEGER_OP(+=,unsigned short);
  ZORBA_INTEGER_OP(-=,unsigned short);
  ZORBA_INTEGER_OP(*=,unsigned short);
  ZORBA_INTEGER_OP(/=,unsigned short);
  ZORBA_INTEGER_OP(%=,unsigned short);
  ZORBA_INTEGER_OP(+=,unsigned int);
  ZORBA_INTEGER_OP(-=,unsigned int);
  ZORBA_INTEGER_OP(*=,unsigned int);
  ZORBA_INTEGER_OP(/=,unsigned int);
  ZORBA_INTEGER_OP(%=,unsigned int);
  ZORBA_INTEGER_OP(+=,unsigned long);
  ZORBA_INTEGER_OP(-=,unsigned long);
  ZORBA_INTEGER_OP(*=,unsigned long);
  ZORBA_INTEGER_OP(/=,unsigned long);
  ZORBA_INTEGER_OP(%=,unsigned long);
  ZORBA_INTEGER_OP(+=,unsigned long long);
  ZORBA_INTEGER_OP(-=,unsigned long long);
  ZORBA_INTEGER_OP(*=,unsigned long long);
  ZORBA_INTEGER_OP(/=,unsigned long long);
  ZORBA_INTEGER_OP(%=,unsigned long long);
  ZORBA_INTEGER_OP(+=,float);
  ZORBA_INTEGER_OP(-=,float);
  ZORBA_INTEGER_OP(*=,float);
  ZORBA_INTEGER_OP(/=,float);
  ZORBA_INTEGER_OP(%=,float);
  ZORBA_INTEGER_OP(+=,double);
  ZORBA_INTEGER_OP(-=,double);
  ZORBA_INTEGER_OP(*=,double);
  ZORBA_INTEGER_OP(/=,double);
  ZORBA_INTEGER_OP(%=,double);
#undef ZORBA_INTEGER_OP

  IntegerImpl operator-() const;

  IntegerImpl& operator++();
  IntegerImpl  operator++(int);
  IntegerImpl& operator--();
  IntegerImpl  operator--(int);

  ////////// relational operators /////////////////////////////////////////////

#define ZORBA_INTEGER_OP(OP)                                          \
  TEMPLATE_DECL(I) friend                                             \
  bool operator OP( INTEGER_IMPL(I) const&, INTEGER_IMPL(I) const& ); \
                                                                      \
  TEMPLATE_DECL(I) friend                                             \
  bool operator OP( INTEGER_IMPL(I) const&, Decimal const& );         \
                                                                      \
  TEMPLATE_DECL(I) friend                                             \
  bool operator OP( Decimal const&, INTEGER_IMPL(I) const& )

  ZORBA_INTEGER_OP(==);
  ZORBA_INTEGER_OP(!=);
  ZORBA_INTEGER_OP(< );
  ZORBA_INTEGER_OP(<=);
  ZORBA_INTEGER_OP(> );
  ZORBA_INTEGER_OP(>=);
#undef ZORBA_INTEGER_OP

#define ZORBA_INTEGER_OP(OP,T)                                            \
  TEMPLATE_DECL(I) friend bool operator OP( INTEGER_IMPL(I) const&, T );  \
  TEMPLATE_DECL(I) friend bool operator OP( T, INTEGER_IMPL(I) const& )

  ZORBA_INTEGER_OP(==,char);
  ZORBA_INTEGER_OP(!=,char);
  ZORBA_INTEGER_OP(< ,char);
  ZORBA_INTEGER_OP(<=,char);
  ZORBA_INTEGER_OP(> ,char);
  ZORBA_INTEGER_OP(>=,char);
  ZORBA_INTEGER_OP(==,signed char);
  ZORBA_INTEGER_OP(!=,signed char);
  ZORBA_INTEGER_OP(< ,signed char);
  ZORBA_INTEGER_OP(<=,signed char);
  ZORBA_INTEGER_OP(> ,signed char);
  ZORBA_INTEGER_OP(>=,signed char);
  ZORBA_INTEGER_OP(==,short);
  ZORBA_INTEGER_OP(!=,short);
  ZORBA_INTEGER_OP(< ,short);
  ZORBA_INTEGER_OP(<=,short);
  ZORBA_INTEGER_OP(> ,short);
  ZORBA_INTEGER_OP(>=,short);
  ZORBA_INTEGER_OP(==,int);
  ZORBA_INTEGER_OP(!=,int);
  ZORBA_INTEGER_OP(< ,int);
  ZORBA_INTEGER_OP(<=,int);
  ZORBA_INTEGER_OP(> ,int);
  ZORBA_INTEGER_OP(>=,int);
  ZORBA_INTEGER_OP(==,long);
  ZORBA_INTEGER_OP(!=,long);
  ZORBA_INTEGER_OP(< ,long);
  ZORBA_INTEGER_OP(<=,long);
  ZORBA_INTEGER_OP(> ,long);
  ZORBA_INTEGER_OP(>=,long);
  ZORBA_INTEGER_OP(==,long long);
  ZORBA_INTEGER_OP(!=,long long);
  ZORBA_INTEGER_OP(< ,long long);
  ZORBA_INTEGER_OP(<=,long long);
  ZORBA_INTEGER_OP(> ,long long);
  ZORBA_INTEGER_OP(>=,long long);
  ZORBA_INTEGER_OP(==,unsigned char);
  ZORBA_INTEGER_OP(!=,unsigned char);
  ZORBA_INTEGER_OP(< ,unsigned char);
  ZORBA_INTEGER_OP(<=,unsigned char);
  ZORBA_INTEGER_OP(> ,unsigned char);
  ZORBA_INTEGER_OP(>=,unsigned char);
  ZORBA_INTEGER_OP(==,unsigned short);
  ZORBA_INTEGER_OP(!=,unsigned short);
  ZORBA_INTEGER_OP(< ,unsigned short);
  ZORBA_INTEGER_OP(<=,unsigned short);
  ZORBA_INTEGER_OP(> ,unsigned short);
  ZORBA_INTEGER_OP(>=,unsigned short);
  ZORBA_INTEGER_OP(==,unsigned int);
  ZORBA_INTEGER_OP(!=,unsigned int);
  ZORBA_INTEGER_OP(< ,unsigned int);
  ZORBA_INTEGER_OP(<=,unsigned int);
  ZORBA_INTEGER_OP(> ,unsigned int);
  ZORBA_INTEGER_OP(>=,unsigned int);
  ZORBA_INTEGER_OP(==,unsigned long);
  ZORBA_INTEGER_OP(!=,unsigned long);
  ZORBA_INTEGER_OP(< ,unsigned long);
  ZORBA_INTEGER_OP(<=,unsigned long);
  ZORBA_INTEGER_OP(> ,unsigned long);
  ZORBA_INTEGER_OP(>=,unsigned long);
  ZORBA_INTEGER_OP(==,unsigned long long);
  ZORBA_INTEGER_OP(!=,unsigned long long);
  ZORBA_INTEGER_OP(< ,unsigned long long);
  ZORBA_INTEGER_OP(<=,unsigned long long);
  ZORBA_INTEGER_OP(> ,unsigned long long);
  ZORBA_INTEGER_OP(>=,unsigned long long);
  ZORBA_INTEGER_OP(==,float);
  ZORBA_INTEGER_OP(!=,float);
  ZORBA_INTEGER_OP(< ,float);
  ZORBA_INTEGER_OP(<=,float);
  ZORBA_INTEGER_OP(> ,float);
  ZORBA_INTEGER_OP(>=,float);
  ZORBA_INTEGER_OP(==,double);
  ZORBA_INTEGER_OP(!=,double);
  ZORBA_INTEGER_OP(< ,double);
  ZORBA_INTEGER_OP(<=,double);
  ZORBA_INTEGER_OP(> ,double);
  ZORBA_INTEGER_OP(>=,double);
#undef ZORBA_INTEGER_OP

  ////////// math functions ///////////////////////////////////////////////////

  Double pow( IntegerImpl const &power ) const;
  IntegerImpl round( IntegerImpl const &precision ) const;
  IntegerImpl roundHalfToEven( IntegerImpl const &precision ) const;

  ////////// miscellaneous ////////////////////////////////////////////////////

  int compare( IntegerImpl const& ) const;
  uint32_t hash() const;
  bool is_cxx_long() const;
  bool is_xs_byte() const;
  bool is_xs_int() const;
  bool is_xs_long() const;
  bool is_xs_short() const;
  bool is_xs_unsignedByte() const;
  bool is_xs_unsignedInt() const;
  bool is_xs_unsignedLong() const;
  bool is_xs_unsignedShort() const;
  int sign() const;
  zstring toString() const;
  value_type& value();
  value_type const& value() const;
  static IntegerImpl const& one();
  static IntegerImpl const& zero();

  /////////////////////////////////////////////////////////////////////////////

private:
#ifdef ZORBA_WITH_BIG_INTEGER
  typedef long int_cast_type;
#else
  typedef IntType int_cast_type;
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

  template<typename T>
  static value_type make_value_type( T n ) {
    return value_type( static_cast<int_cast_type>( n ) );
  }

#else /* ZORBA_WITH_BIG_INTEGER */

  static value_type ftoi( value_type v ) {
    return v;                           // intentional no-op
  }

  static value_type ftoi( MAPM const &d );

  MAPM itod() const;

  template<typename T>
  static value_type make_value_type( T n ) {
    return static_cast<value_type>( n );
  }
#endif /* ZORBA_WITH_BIG_INTEGER */

  void parse( char const *s );

  friend class Decimal;
  template<typename T> friend class FloatImpl;

#ifndef ZORBA_WITH_BIG_INTEGER
  template<typename T> friend class IntegerImpl;
#endif /* ZORBA_WITH_BIG_INTEGER */

  friend xs_int to_xs_int( INTEGER_IMPL_LL const& );
  friend xs_long to_xs_long( INTEGER_IMPL_LL const& );
  friend xs_unsignedInt to_xs_unsignedInt( INTEGER_IMPL_LL const& );
  friend xs_unsignedLong to_xs_unsignedLong( INTEGER_IMPL_LL const& );

  TEMPLATE_DECL(I) friend
  void serialization::operator&( serialization::Archiver&, INTEGER_IMPL(I)& );
};

typedef INTEGER_IMPL_LL Integer;
typedef INTEGER_IMPL_ULL UInteger;

////////// constructors ///////////////////////////////////////////////////////

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)::IntegerImpl( char c ) :
  value_( static_cast<long>( c ) )
{
}

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)::IntegerImpl( signed char c ) :
  value_( static_cast<long>( c ) )
{
}

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)::IntegerImpl( short n ) :
  value_( static_cast<long>( n ) )
{
}

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)::IntegerImpl( int n ) :
  value_( static_cast<long>( n ) )
{
}

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)::IntegerImpl( long n ) :
  value_( n )
{
}

#ifndef ZORBA_WITH_BIG_INTEGER
TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)::IntegerImpl( long long n ) :
  value_( n )
{
}
#endif /* ZORBA_WITH_BIG_INTEGER */

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)::IntegerImpl( unsigned char c ) :
  value_( static_cast<long>( c ) )
{
}

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)::IntegerImpl( unsigned short n ) :
  value_( static_cast<long>( n ) )
{
}

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)::IntegerImpl( unsigned int n ) :
  value_( static_cast<long>( n ) )
{
}

#ifndef ZORBA_WITH_BIG_INTEGER
TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)::IntegerImpl( unsigned long n ) :
  value_( static_cast<value_type>( n ) )
{
}

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)::IntegerImpl( unsigned long long n ) :
  value_( static_cast<value_type>( n ) )
{
}
#endif /* ZORBA_WITH_BIG_INTEGER */

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)::IntegerImpl( float n ) :
#ifdef ZORBA_WITH_BIG_INTEGER
  value_( static_cast<double>( n ) )
#else
  value_( static_cast<value_type>( n ) )
#endif /* ZORBA_WITH_BIG_INTEGER */
{
}

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)::IntegerImpl( double n ) :
#ifdef ZORBA_WITH_BIG_INTEGER
  value_( n )
#else
  value_( static_cast<value_type>( n ) )
#endif /* ZORBA_WITH_BIG_INTEGER */
{
}

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)::IntegerImpl( char const *s ) {
  parse( s );
}

TEMPLATE_DECL(I)
TEMPLATE_DECL(J)
inline INTEGER_IMPL(I)::IntegerImpl( INTEGER_IMPL(J) const &i ) :
  value_( i.value_ )
{
}

////////// assignment operators ///////////////////////////////////////////////

#define ZORBA_ASSIGN_OP(T)                              \
  TEMPLATE_DECL(I) inline                               \
  INTEGER_IMPL(I)& INTEGER_IMPL(I)::operator=( T n ) {  \
    value_ = static_cast<int_cast_type>( n );           \
    return *this;                                       \
  }

ZORBA_ASSIGN_OP(char)
ZORBA_ASSIGN_OP(signed char)
ZORBA_ASSIGN_OP(short)
ZORBA_ASSIGN_OP(int)
ZORBA_ASSIGN_OP(long)
ZORBA_ASSIGN_OP(unsigned char)
ZORBA_ASSIGN_OP(unsigned short)
ZORBA_ASSIGN_OP(unsigned int)
ZORBA_ASSIGN_OP(float)
ZORBA_ASSIGN_OP(double)
#ifndef ZORBA_WITH_BIG_INTEGER
ZORBA_ASSIGN_OP(long long)
ZORBA_ASSIGN_OP(unsigned long)
ZORBA_ASSIGN_OP(unsigned long long)
#endif /* ZORBA_WITH_BIG_INTEGER */
#undef ZORBA_ASSIGN_OP

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)& INTEGER_IMPL(I)::operator=( char const *s ) {
  parse( s );
  return *this;
}

TEMPLATE_DECL(I) TEMPLATE_DECL(J)
inline INTEGER_IMPL(I)& INTEGER_IMPL(I)::operator=( INTEGER_IMPL(J) const &i ) {
  value_ = i.value_;
  return *this;
}

////////// arithmetic operators ///////////////////////////////////////////////

#define ZORBA_INTEGER_OP(OP)                                \
  TEMPLATE_DECL(I) inline                                   \
  INTEGER_IMPL(I) operator OP( INTEGER_IMPL(I) const &i,    \
                               INTEGER_IMPL(I) const &j ) { \
    return INTEGER_IMPL(I)( i.value_ OP j.value_ );         \
  }

ZORBA_INTEGER_OP(+)
ZORBA_INTEGER_OP(-)
ZORBA_INTEGER_OP(*)
ZORBA_INTEGER_OP(%)
#undef ZORBA_INTEGER_OP

TEMPLATE_DECL(I) inline
INTEGER_IMPL(I) operator/( INTEGER_IMPL(I) const &i,
                           INTEGER_IMPL(I) const &j ) {
  return INTEGER_IMPL(I)( INTEGER_IMPL(I)::ftoi( i.value_ / j.value_ ) );
}

#define ZORBA_INTEGER_OP(OP,T)                                    \
  TEMPLATE_DECL(I) inline                                         \
  INTEGER_IMPL(I) operator OP( INTEGER_IMPL(I) const &i, T n ) {  \
    return INTEGER_IMPL(I)( i.value_ OP INTEGER_IMPL(I)::make_value_type( n ) ); \
  }                                                               \
                                                                  \
  TEMPLATE_DECL(I) inline                                         \
  INTEGER_IMPL(I) operator OP( T n, INTEGER_IMPL(I) const &i ) {  \
    return INTEGER_IMPL(I)( INTEGER_IMPL(I)::make_value_type( n ) OP i.value_ ); \
  }

ZORBA_INTEGER_OP(+,char)
ZORBA_INTEGER_OP(-,char)
ZORBA_INTEGER_OP(*,char)
ZORBA_INTEGER_OP(%,char)
ZORBA_INTEGER_OP(+,signed char)
ZORBA_INTEGER_OP(-,signed char)
ZORBA_INTEGER_OP(*,signed char)
ZORBA_INTEGER_OP(%,signed char)
ZORBA_INTEGER_OP(+,short)
ZORBA_INTEGER_OP(-,short)
ZORBA_INTEGER_OP(*,short)
ZORBA_INTEGER_OP(%,short)
ZORBA_INTEGER_OP(+,int)
ZORBA_INTEGER_OP(-,int)
ZORBA_INTEGER_OP(*,int)
ZORBA_INTEGER_OP(%,int)
ZORBA_INTEGER_OP(+,long)
ZORBA_INTEGER_OP(-,long)
ZORBA_INTEGER_OP(*,long)
ZORBA_INTEGER_OP(%,long)
ZORBA_INTEGER_OP(+,unsigned char)
ZORBA_INTEGER_OP(-,unsigned char)
ZORBA_INTEGER_OP(*,unsigned char)
ZORBA_INTEGER_OP(%,unsigned char)
ZORBA_INTEGER_OP(+,unsigned short)
ZORBA_INTEGER_OP(-,unsigned short)
ZORBA_INTEGER_OP(*,unsigned short)
ZORBA_INTEGER_OP(%,unsigned short)
ZORBA_INTEGER_OP(+,unsigned int)
ZORBA_INTEGER_OP(-,unsigned int)
ZORBA_INTEGER_OP(*,unsigned int)
ZORBA_INTEGER_OP(%,unsigned int)
ZORBA_INTEGER_OP(+,float)
ZORBA_INTEGER_OP(-,float)
ZORBA_INTEGER_OP(*,float)
ZORBA_INTEGER_OP(%,float)
ZORBA_INTEGER_OP(+,double)
ZORBA_INTEGER_OP(-,double)
ZORBA_INTEGER_OP(*,double)
ZORBA_INTEGER_OP(%,double)
#ifndef ZORBA_WITH_BIG_INTEGER
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
#endif /* ZORBA_WITH_BIG_INTEGER */
#undef ZORBA_INTEGER_OP

#define ZORBA_INTEGER_OP(T)                                     \
  TEMPLATE_DECL(I) inline                                       \
  INTEGER_IMPL(I) operator/( INTEGER_IMPL(I) const &i, T n ) {  \
    return INTEGER_IMPL(I)( INTEGER_IMPL(I)::ftoi( i.value_ / INTEGER_IMPL(I)::make_value_type( n ) ) ); \
  }                                                             \
                                                                \
  TEMPLATE_DECL(I) inline                                       \
  INTEGER_IMPL(I) operator/( T n, INTEGER_IMPL(I) const &i ) {  \
    return INTEGER_IMPL(I)( INTEGER_IMPL(I)::ftoi( INTEGER_IMPL(I)::make_value_type( n ) / i.value_ ) ); \
  }

ZORBA_INTEGER_OP(signed char)
ZORBA_INTEGER_OP(char)
ZORBA_INTEGER_OP(short)
ZORBA_INTEGER_OP(int)
ZORBA_INTEGER_OP(long)
ZORBA_INTEGER_OP(unsigned char)
ZORBA_INTEGER_OP(unsigned short)
ZORBA_INTEGER_OP(unsigned int)
ZORBA_INTEGER_OP(float)
ZORBA_INTEGER_OP(double)
#ifndef ZORBA_WITH_BIG_INTEGER
ZORBA_INTEGER_OP(long long)
ZORBA_INTEGER_OP(unsigned long)
ZORBA_INTEGER_OP(unsigned long long)
#endif /* ZORBA_WITH_BIG_INTEGER */
#undef ZORBA_INTEGER_OP

#define ZORBA_INTEGER_OP(OP)                                              \
  TEMPLATE_DECL(I) inline                                                 \
  INTEGER_IMPL(I)& INTEGER_IMPL(I)::operator OP( IntegerImpl const &i ) { \
    value_ OP i.value_;                                                   \
    return *this;                                                         \
  }

ZORBA_INTEGER_OP(+=)
ZORBA_INTEGER_OP(-=)
ZORBA_INTEGER_OP(*=)
ZORBA_INTEGER_OP(%=)
#undef ZORBA_INTEGER_OP

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)& INTEGER_IMPL(I)::operator/=( IntegerImpl const &i ) {
  value_ = ftoi( value_ / i.value_ );
  return *this;
}

#define ZORBA_INTEGER_OP(OP,T)                            \
  TEMPLATE_DECL(I) inline                                 \
  INTEGER_IMPL(I)& INTEGER_IMPL(I)::operator OP( T n ) {  \
    value_ OP make_value_type( n );                       \
    return *this;                                         \
  }

ZORBA_INTEGER_OP(+=,char)
ZORBA_INTEGER_OP(-=,char)
ZORBA_INTEGER_OP(*=,char)
ZORBA_INTEGER_OP(%=,char)
ZORBA_INTEGER_OP(+=,signed char)
ZORBA_INTEGER_OP(-=,signed char)
ZORBA_INTEGER_OP(*=,signed char)
ZORBA_INTEGER_OP(%=,signed char)
ZORBA_INTEGER_OP(+=,short)
ZORBA_INTEGER_OP(-=,short)
ZORBA_INTEGER_OP(*=,short)
ZORBA_INTEGER_OP(%=,short)
ZORBA_INTEGER_OP(+=,int)
ZORBA_INTEGER_OP(-=,int)
ZORBA_INTEGER_OP(*=,int)
ZORBA_INTEGER_OP(%=,int)
ZORBA_INTEGER_OP(+=,long)
ZORBA_INTEGER_OP(-=,long)
ZORBA_INTEGER_OP(*=,long)
ZORBA_INTEGER_OP(%=,long)
ZORBA_INTEGER_OP(+=,unsigned char)
ZORBA_INTEGER_OP(-=,unsigned char)
ZORBA_INTEGER_OP(*=,unsigned char)
ZORBA_INTEGER_OP(%=,unsigned char)
ZORBA_INTEGER_OP(+=,unsigned short)
ZORBA_INTEGER_OP(-=,unsigned short)
ZORBA_INTEGER_OP(*=,unsigned short)
ZORBA_INTEGER_OP(%=,unsigned short)
ZORBA_INTEGER_OP(+=,unsigned int)
ZORBA_INTEGER_OP(-=,unsigned int)
ZORBA_INTEGER_OP(*=,unsigned int)
ZORBA_INTEGER_OP(%=,unsigned int)
ZORBA_INTEGER_OP(+=,float)
ZORBA_INTEGER_OP(-=,float)
ZORBA_INTEGER_OP(*=,float)
ZORBA_INTEGER_OP(%=,float)
ZORBA_INTEGER_OP(+=,double)
ZORBA_INTEGER_OP(-=,double)
ZORBA_INTEGER_OP(*=,double)
ZORBA_INTEGER_OP(%=,double)
#ifndef ZORBA_WITH_BIG_INTEGER
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
#endif /* ZORBA_WITH_BIG_INTEGER */
#undef ZORBA_INTEGER_OP

#define ZORBA_INTEGER_OP(T)                             \
  TEMPLATE_DECL(I) inline                               \
  INTEGER_IMPL(I)& INTEGER_IMPL(I)::operator/=( T n ) { \
    value_ = ftoi( value_ / make_value_type( n ) );     \
    return *this;                                       \
  }

ZORBA_INTEGER_OP(char)
ZORBA_INTEGER_OP(signed char)
ZORBA_INTEGER_OP(short)
ZORBA_INTEGER_OP(int)
ZORBA_INTEGER_OP(long)
ZORBA_INTEGER_OP(unsigned char)
ZORBA_INTEGER_OP(unsigned short)
ZORBA_INTEGER_OP(unsigned int)
ZORBA_INTEGER_OP(float)
ZORBA_INTEGER_OP(double)
#ifndef ZORBA_WITH_BIG_INTEGER
ZORBA_INTEGER_OP(long long)
ZORBA_INTEGER_OP(unsigned long)
ZORBA_INTEGER_OP(unsigned long long)
#endif /* ZORBA_WITH_BIG_INTEGER */
#undef ZORBA_INTEGER_OP

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I) INTEGER_IMPL(I)::operator-() const {
  return INTEGER_IMPL(I)( -value_ );
}

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)& INTEGER_IMPL(I)::operator++() {
  ++value_;
  return *this;
}

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I) INTEGER_IMPL(I)::operator++(int) {
  INTEGER_IMPL(I) const result( *this );
  ++value_;
  return result;
}

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I)& INTEGER_IMPL(I)::operator--() {
  --value_;
  return *this;
}

TEMPLATE_DECL(I)
inline INTEGER_IMPL(I) INTEGER_IMPL(I)::operator--(int) {
  INTEGER_IMPL(I) const result( *this );
  --value_;
  return result;
}

////////// relational operators ///////////////////////////////////////////////

#define ZORBA_INTEGER_OP(OP)                                                \
  TEMPLATE_DECL(I) inline                                                   \
  bool operator OP( INTEGER_IMPL(I) const &i, INTEGER_IMPL(I) const &j ) {  \
    return i.value_ OP j.value_;                                            \
  }

ZORBA_INTEGER_OP(==)
ZORBA_INTEGER_OP(!=)
ZORBA_INTEGER_OP(< )
ZORBA_INTEGER_OP(<=)
ZORBA_INTEGER_OP(> )
ZORBA_INTEGER_OP(>=)
#undef ZORBA_INTEGER_OP

#define ZORBA_INTEGER_OP(OP,T)                                \
  TEMPLATE_DECL(I) inline                                     \
  bool operator OP( INTEGER_IMPL(I) const &i, T n ) {         \
    return i.value_ OP INTEGER_IMPL(I)::make_value_type( n ); \
  }                                                           \
                                                              \
  TEMPLATE_DECL(I) inline                                     \
  bool operator OP( T n, INTEGER_IMPL(I) const &i ) {         \
    return INTEGER_IMPL(I)::make_value_type( n ) OP i.value_; \
  }

ZORBA_INTEGER_OP(==,char)
ZORBA_INTEGER_OP(!=,char)
ZORBA_INTEGER_OP(< ,char)
ZORBA_INTEGER_OP(<=,char)
ZORBA_INTEGER_OP(> ,char)
ZORBA_INTEGER_OP(>=,char)
ZORBA_INTEGER_OP(==,signed char)
ZORBA_INTEGER_OP(!=,signed char)
ZORBA_INTEGER_OP(< ,signed char)
ZORBA_INTEGER_OP(<=,signed char)
ZORBA_INTEGER_OP(> ,signed char)
ZORBA_INTEGER_OP(>=,signed char)
ZORBA_INTEGER_OP(==,short)
ZORBA_INTEGER_OP(!=,short)
ZORBA_INTEGER_OP(< ,short)
ZORBA_INTEGER_OP(<=,short)
ZORBA_INTEGER_OP(> ,short)
ZORBA_INTEGER_OP(>=,short)
ZORBA_INTEGER_OP(==,int)
ZORBA_INTEGER_OP(!=,int)
ZORBA_INTEGER_OP(< ,int)
ZORBA_INTEGER_OP(<=,int)
ZORBA_INTEGER_OP(> ,int)
ZORBA_INTEGER_OP(>=,int)
ZORBA_INTEGER_OP(==,long)
ZORBA_INTEGER_OP(!=,long)
ZORBA_INTEGER_OP(< ,long)
ZORBA_INTEGER_OP(<=,long)
ZORBA_INTEGER_OP(> ,long)
ZORBA_INTEGER_OP(>=,long)
ZORBA_INTEGER_OP(==,unsigned char)
ZORBA_INTEGER_OP(!=,unsigned char)
ZORBA_INTEGER_OP(< ,unsigned char)
ZORBA_INTEGER_OP(<=,unsigned char)
ZORBA_INTEGER_OP(> ,unsigned char)
ZORBA_INTEGER_OP(>=,unsigned char)
ZORBA_INTEGER_OP(==,unsigned short)
ZORBA_INTEGER_OP(!=,unsigned short)
ZORBA_INTEGER_OP(< ,unsigned short)
ZORBA_INTEGER_OP(<=,unsigned short)
ZORBA_INTEGER_OP(> ,unsigned short)
ZORBA_INTEGER_OP(>=,unsigned short)
ZORBA_INTEGER_OP(==,unsigned int)
ZORBA_INTEGER_OP(!=,unsigned int)
ZORBA_INTEGER_OP(< ,unsigned int)
ZORBA_INTEGER_OP(<=,unsigned int)
ZORBA_INTEGER_OP(> ,unsigned int)
ZORBA_INTEGER_OP(>=,unsigned int)
ZORBA_INTEGER_OP(==,float)
ZORBA_INTEGER_OP(!=,float)
ZORBA_INTEGER_OP(< ,float)
ZORBA_INTEGER_OP(<=,float)
ZORBA_INTEGER_OP(> ,float)
ZORBA_INTEGER_OP(>=,float)
ZORBA_INTEGER_OP(==,double)
ZORBA_INTEGER_OP(!=,double)
ZORBA_INTEGER_OP(< ,double)
ZORBA_INTEGER_OP(<=,double)
ZORBA_INTEGER_OP(> ,double)
ZORBA_INTEGER_OP(>=,double)
#ifndef ZORBA_WITH_BIG_INTEGER
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
#endif /* ZORBA_WITH_BIG_INTEGER */
#undef ZORBA_INTEGER_OP

////////// miscellaneous //////////////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER

inline int IntegerImpl::compare( IntegerImpl const &i ) const {
  return value_.compare( i.value_ );
}

inline bool IntegerImpl::is_xs_int() const {
  return value_ >= MAPM::getMinInt32() && value_ <= MAPM::getMaxInt32();
}

inline bool IntegerImpl::is_xs_long() const {
  return value_ >= MAPM::getMinInt64() && value_ <= MAPM::getMaxInt64();
}

inline int IntegerImpl::sign() const {
  return value_.sign();
}

#else /* ZORBA_WITH_BIG_INTEGER */

template<typename I>
inline int IntegerImpl<I>::compare( IntegerImpl const &i ) const {
  return value_ < i.value_ ? -1 : value_ > i.value_ ? 1 : 0;
}

template<typename I>
inline uint32_t IntegerImpl<I>::hash() const {
  return static_cast<uint32_t>( value_ );
}

template<typename I>
inline bool IntegerImpl<I>::is_cxx_long() const {
  return ZORBA_IN_RANGE( value_, long );
}

template<typename I>
inline bool IntegerImpl<I>::is_xs_byte() const {
  return ZORBA_IN_RANGE( value_, xs_byte );
}

template<typename I>
inline bool IntegerImpl<I>::is_xs_int() const {
  return ZORBA_IN_RANGE( value_, xs_int );
}

template<typename I>
inline bool IntegerImpl<I>::is_xs_long() const {
  return ZORBA_IN_RANGE( value_, xs_long );
}

template<typename I>
inline bool IntegerImpl<I>::is_xs_short() const {
  return ZORBA_IN_RANGE( value_, xs_short );
}

template<typename I>
inline bool IntegerImpl<I>::is_xs_unsignedByte() const {
  return ZORBA_IN_RANGE( value_, xs_unsignedByte );
}

template<typename I>
inline bool IntegerImpl<I>::is_xs_unsignedInt() const {
  return ZORBA_IN_RANGE( value_, xs_unsignedInt );
}

template<typename I>
inline bool IntegerImpl<I>::is_xs_unsignedLong() const {
  return ZORBA_IN_RANGE( value_, xs_unsignedLong );
}

template<typename I>
inline bool IntegerImpl<I>::is_xs_unsignedShort() const {
  return ZORBA_IN_RANGE( value_, xs_unsignedShort );
}

template<typename I>
inline int IntegerImpl<I>::sign() const {
  return ztd::lt0( value_ ) ? -1 : value_ > 0 ? 1 : 0;
}

#endif /* ZORBA_WITH_BIG_INTEGER */

TEMPLATE_DECL(I) inline
TEMPLATE_TYPENAME INTEGER_IMPL(I)::value_type& INTEGER_IMPL(I)::value() {
  return value_;
}

TEMPLATE_DECL(I) inline
TEMPLATE_TYPENAME INTEGER_IMPL(I)::value_type const&
INTEGER_IMPL(I)::value() const {
  return value_;
}

TEMPLATE_DECL(I)
inline std::ostream& operator<<( std::ostream &os, INTEGER_IMPL(I) const &i ) {
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
