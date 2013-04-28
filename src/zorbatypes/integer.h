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

// standard
#include <cmath>
#include <limits>

// Zorba
#include <zorba/config.h>
#include "common/common.h"
#include "util/stl_util.h"

// local
#include "m_apm.h"
#include "schema_types_base.h"
#include "zorbatypes_decl.h"
#include "zstring.h"

namespace zorba {

template<class CheckType>
class IntegerImpl;

namespace serialization {
  class Archiver;

  template<class C>
  void operator&( Archiver&, IntegerImpl<C>& );
}

///////////////////////////////////////////////////////////////////////////////

struct integer_check {
  template<typename ValueType>
  static ValueType check_value( ValueType n ) {
    return n;
  }
};

struct negative_check {
  template<typename ValueType>
  static ValueType check_value( ValueType n ) {
    if ( !ztd::lt0( n ) )
      throw std::range_error( BUILD_STRING( n, ": not < 0" ) );
    return n;
  }
};

struct nonPositive_check {
  template<typename ValueType>
  static ValueType check_value( ValueType n ) {
    if ( !ztd::le0( n ) )
      throw std::range_error( BUILD_STRING( n, ": not <= 0" ) );
    return n;
  }
};

struct nonNegative_check {
  template<typename ValueType>
  static ValueType check_value( ValueType n ) {
    if ( !ztd::ge0( n ) )
      throw std::range_error( BUILD_STRING( n, ": not >= 0" ) );
    return n;
  }
};

struct positive_check {
  template<typename ValueType>
  static ValueType check_value( ValueType n ) {
    if ( !ztd::gt0( n ) )
      throw std::range_error( BUILD_STRING( n, ": not > 0" ) );
    return n;
  }
};

template<class CheckType>
class IntegerImpl {
public:
#ifdef ZORBA_WITH_BIG_INTEGER
  typedef MAPM value_type;
#else
  typedef long long value_type;
#endif /* ZORBA_WITH_BIG_INTEGER */
  typedef CheckType check_type;

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
   * Constructs from another %IntegerImpl even if its \c CheckType is
   * different.  (This subsumes the conventional copy constructor.)
   *
   * @tparam CheckType2 The tag type of \a i.
   * @param i The %IntegerImpl to copy from.
   */
  template<class CheckType2>
  IntegerImpl( IntegerImpl<CheckType2> const &i );

  ////////// assignment operators /////////////////////////////////////////////

  /**
   * Assign from an %IntegerImpl even if its \c CheckType is different.
   * (This subsumes the conventional assignment operator.)
   *
   * @tparam CheckType2 The tag type of \a i.
   * @param i The %IntegerImpl to assign from.
   * @return Returns \c *this.
   */
  template<class CheckType2>
  IntegerImpl& operator=( IntegerImpl<CheckType2> const &i );

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

#define ZORBA_INTEGER_OP(OP)                                    \
  template<class C> friend                                      \
  IntegerImpl<C> operator OP( IntegerImpl<C> const&,            \
                              IntegerImpl<C> const& );          \
                                                                \
  template<class C> friend                                      \
  Decimal operator OP( IntegerImpl<C> const&, Decimal const& ); \
                                                                \
  template<class C> friend                                      \
  Decimal operator OP( Decimal const&, IntegerImpl<C> const& )

  ZORBA_INTEGER_OP(+);
  ZORBA_INTEGER_OP(-);
  ZORBA_INTEGER_OP(*);
  ZORBA_INTEGER_OP(/);
  ZORBA_INTEGER_OP(%);
#undef ZORBA_INTEGER_OP

#define ZORBA_INTEGER_OP(OP,T)                            \
  template<class C> friend                                \
  IntegerImpl<C> operator OP( IntegerImpl<C> const&, T ); \
                                                          \
  template<class C> friend                                \
  IntegerImpl<C> operator OP( T, IntegerImpl<C> const& )

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

#define ZORBA_REL_OP(OP)                                            \
  template<class C,class D> friend                                  \
  bool operator OP( IntegerImpl<C> const&, IntegerImpl<D> const& ); \
                                                                    \
  template<class C> friend                                          \
  bool operator OP( IntegerImpl<C> const&, Decimal const& );        \
                                                                    \
  template<class C> friend                                          \
  bool operator OP( Decimal const&, IntegerImpl<C> const& )

  ZORBA_REL_OP(==);
  ZORBA_REL_OP(!=);
  ZORBA_REL_OP(< );
  ZORBA_REL_OP(<=);
  ZORBA_REL_OP(> );
  ZORBA_REL_OP(>=);
#undef ZORBA_REL_OP

#define ZORBA_REL_OP(OP,T)                                                \
  template<class C> friend bool operator OP( IntegerImpl<C> const&, T );  \
  template<class C> friend bool operator OP( T, IntegerImpl<C> const& )

  ZORBA_REL_OP(==,char);
  ZORBA_REL_OP(!=,char);
  ZORBA_REL_OP(< ,char);
  ZORBA_REL_OP(<=,char);
  ZORBA_REL_OP(> ,char);
  ZORBA_REL_OP(>=,char);
  ZORBA_REL_OP(==,signed char);
  ZORBA_REL_OP(!=,signed char);
  ZORBA_REL_OP(< ,signed char);
  ZORBA_REL_OP(<=,signed char);
  ZORBA_REL_OP(> ,signed char);
  ZORBA_REL_OP(>=,signed char);
  ZORBA_REL_OP(==,short);
  ZORBA_REL_OP(!=,short);
  ZORBA_REL_OP(< ,short);
  ZORBA_REL_OP(<=,short);
  ZORBA_REL_OP(> ,short);
  ZORBA_REL_OP(>=,short);
  ZORBA_REL_OP(==,int);
  ZORBA_REL_OP(!=,int);
  ZORBA_REL_OP(< ,int);
  ZORBA_REL_OP(<=,int);
  ZORBA_REL_OP(> ,int);
  ZORBA_REL_OP(>=,int);
  ZORBA_REL_OP(==,long);
  ZORBA_REL_OP(!=,long);
  ZORBA_REL_OP(< ,long);
  ZORBA_REL_OP(<=,long);
  ZORBA_REL_OP(> ,long);
  ZORBA_REL_OP(>=,long);
  ZORBA_REL_OP(==,long long);
  ZORBA_REL_OP(!=,long long);
  ZORBA_REL_OP(< ,long long);
  ZORBA_REL_OP(<=,long long);
  ZORBA_REL_OP(> ,long long);
  ZORBA_REL_OP(>=,long long);
  ZORBA_REL_OP(==,unsigned char);
  ZORBA_REL_OP(!=,unsigned char);
  ZORBA_REL_OP(< ,unsigned char);
  ZORBA_REL_OP(<=,unsigned char);
  ZORBA_REL_OP(> ,unsigned char);
  ZORBA_REL_OP(>=,unsigned char);
  ZORBA_REL_OP(==,unsigned short);
  ZORBA_REL_OP(!=,unsigned short);
  ZORBA_REL_OP(< ,unsigned short);
  ZORBA_REL_OP(<=,unsigned short);
  ZORBA_REL_OP(> ,unsigned short);
  ZORBA_REL_OP(>=,unsigned short);
  ZORBA_REL_OP(==,unsigned int);
  ZORBA_REL_OP(!=,unsigned int);
  ZORBA_REL_OP(< ,unsigned int);
  ZORBA_REL_OP(<=,unsigned int);
  ZORBA_REL_OP(> ,unsigned int);
  ZORBA_REL_OP(>=,unsigned int);
  ZORBA_REL_OP(==,unsigned long);
  ZORBA_REL_OP(!=,unsigned long);
  ZORBA_REL_OP(< ,unsigned long);
  ZORBA_REL_OP(<=,unsigned long);
  ZORBA_REL_OP(> ,unsigned long);
  ZORBA_REL_OP(>=,unsigned long);
  ZORBA_REL_OP(==,unsigned long long);
  ZORBA_REL_OP(!=,unsigned long long);
  ZORBA_REL_OP(< ,unsigned long long);
  ZORBA_REL_OP(<=,unsigned long long);
  ZORBA_REL_OP(> ,unsigned long long);
  ZORBA_REL_OP(>=,unsigned long long);
  ZORBA_REL_OP(==,float);
  ZORBA_REL_OP(!=,float);
  ZORBA_REL_OP(< ,float);
  ZORBA_REL_OP(<=,float);
  ZORBA_REL_OP(> ,float);
  ZORBA_REL_OP(>=,float);
  ZORBA_REL_OP(==,double);
  ZORBA_REL_OP(!=,double);
  ZORBA_REL_OP(< ,double);
  ZORBA_REL_OP(<=,double);
  ZORBA_REL_OP(> ,double);
  ZORBA_REL_OP(>=,double);
#undef ZORBA_REL_OP

  ////////// math functions ///////////////////////////////////////////////////

  Double pow( IntegerImpl const &power ) const;
  IntegerImpl round( IntegerImpl const &precision ) const;
  IntegerImpl roundHalfToEven( IntegerImpl const &precision ) const;

  ////////// miscellaneous ////////////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
  size_t alloc_size() const;
#endif /* ZORBA_WITH_BIG_INTEGER */
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
  typedef value_type int_cast_type;
#endif /* ZORBA_WITH_BIG_INTEGER */

  value_type value_;

  static value_type ftoi( double d ) {
    return value_type( d >= 0 ? floor( d ) : ceil( d ) );
  }

#ifdef ZORBA_WITH_BIG_INTEGER
  IntegerImpl( value_type const &v ) : value_( v ) { }

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
  template<typename F> friend class FloatImpl;

#ifndef ZORBA_WITH_BIG_INTEGER
  template<class C> friend class IntegerImpl;
#endif /* ZORBA_WITH_BIG_INTEGER */

  friend xs_int to_xs_int( Integer const& );
  friend xs_long to_xs_long( Integer const& );
  friend xs_unsignedByte to_xs_unsignedByte( Integer const& );
  friend xs_unsignedShort to_xs_unsignedShort( Integer const& );
  friend xs_unsignedInt to_xs_unsignedInt( Integer const& );
  friend xs_unsignedLong to_xs_unsignedLong( Integer const& );

  template<class C> friend
  void serialization::operator&( serialization::Archiver&, IntegerImpl<C>& );
};

typedef IntegerImpl<integer_check>      Integer;
typedef IntegerImpl<negative_check>     NegativeInteger;
typedef IntegerImpl<nonNegative_check>  NonNegativeInteger;
typedef IntegerImpl<nonPositive_check>  NonPositiveInteger;
typedef IntegerImpl<positive_check>     PositiveInteger;

template<class IntegerType>
struct integer_const {
  static IntegerType const& zero();
  static IntegerType const& one();
};

template<>
struct integer_const<NegativeInteger> {
};

template<>
struct integer_const<NonPositiveInteger> {
  static NonPositiveInteger const& zero();
};

template<>
struct integer_const<PositiveInteger> {
  static PositiveInteger const& one();
};

////////// constructors ///////////////////////////////////////////////////////

template<class C>
inline IntegerImpl<C>::IntegerImpl( char c ) :
  value_( static_cast<long>( C::check_value( c ) ) )
{
}

template<class C>
inline IntegerImpl<C>::IntegerImpl( signed char c ) :
  value_( static_cast<long>( C::check_value( c ) ) )
{
}

template<class C>
inline IntegerImpl<C>::IntegerImpl( short n ) :
  value_( static_cast<long>( C::check_value( n ) ) )
{
}

template<class C>
inline IntegerImpl<C>::IntegerImpl( int n ) :
  value_( static_cast<long>( C::check_value( n ) ) )
{
}

template<class C>
inline IntegerImpl<C>::IntegerImpl( long n ) :
  value_( C::check_value( n ) )
{
}

#ifndef ZORBA_WITH_BIG_INTEGER
template<class C>
inline IntegerImpl<C>::IntegerImpl( long long n ) :
  value_( C::check_value( n ) )
{
}
#endif /* ZORBA_WITH_BIG_INTEGER */

template<class C>
inline IntegerImpl<C>::IntegerImpl( unsigned char c ) :
  value_( static_cast<long>( (unsigned long)C::check_value( c ) ) )
{
}

template<class C>
inline IntegerImpl<C>::IntegerImpl( unsigned short n ) :
  value_( static_cast<long>( (unsigned long)C::check_value( n ) ) )
{
}

#ifdef ZORBA_WITH_BIG_INTEGER
#if ZORBA_SIZEOF_INT != ZORBA_SIZEOF_LONG
template<class C>
inline IntegerImpl<C>::IntegerImpl( unsigned int n ) :
  value_( static_cast<long>( (unsigned long)C::check_value( n ) ) )
{
}
#endif /* ZORBA_SIZEOF_INT == ZORBA_SIZEOF_LONG */
#else /* ZORBA_WITH_BIG_INTEGER */
template<class C>
inline IntegerImpl<C>::IntegerImpl( unsigned int n ) :
  value_( static_cast<value_type>( C::check_value( n ) ) )
{
}

template<class C>
inline IntegerImpl<C>::IntegerImpl( unsigned long n ) :
  value_( static_cast<value_type>( C::check_value( n ) ) )
{
}

template<class C>
inline IntegerImpl<C>::IntegerImpl( unsigned long long n ) :
  value_( static_cast<value_type>( C::check_value( n ) ) )
{
}
#endif /* ZORBA_WITH_BIG_INTEGER */

template<class C>
inline IntegerImpl<C>::IntegerImpl( float n ) :
#ifdef ZORBA_WITH_BIG_INTEGER
  value_( static_cast<double>( C::check_value( n ) ) )
#else
  value_( static_cast<value_type>( C::check_value( n ) ) )
#endif /* ZORBA_WITH_BIG_INTEGER */
{
}

template<class C>
inline IntegerImpl<C>::IntegerImpl( double n ) :
#ifdef ZORBA_WITH_BIG_INTEGER
  value_( C::check_value( n ) )
#else
  value_( static_cast<value_type>( C::check_value( n ) ) )
#endif /* ZORBA_WITH_BIG_INTEGER */
{
}

template<class C>
inline IntegerImpl<C>::IntegerImpl( char const *s ) {
  parse( s );
}

template<class C>
template<class D>
inline IntegerImpl<C>::IntegerImpl( IntegerImpl<D> const &i ) :
  value_( C::check_value( i.value_ ) )
{
}

////////// assignment operators ///////////////////////////////////////////////

#define ZORBA_ASSIGN_OP(T)                                \
  template<class C> inline                     \
  IntegerImpl<C>& IntegerImpl<C>::operator=( T n ) {  \
    value_ = static_cast<int_cast_type>( n );             \
    return *this;                                         \
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

template<class C>
inline IntegerImpl<C>& IntegerImpl<C>::operator=( char const *s ) {
  parse( s );
  return *this;
}

template<class C>
template<class D>
inline IntegerImpl<C>& IntegerImpl<C>::operator=( IntegerImpl<D> const &i ) {
  value_ = i.value_; // TODO
  return *this;
}

////////// arithmetic operators ///////////////////////////////////////////////

#define ZORBA_INTEGER_OP(OP)                                  \
  template<class C> inline                         \
  IntegerImpl<C> operator OP( IntegerImpl<C> const &i,    \
                                IntegerImpl<C> const &j ) { \
    return IntegerImpl<C>( i.value_ OP j.value_ );          \
  }

ZORBA_INTEGER_OP(+)
ZORBA_INTEGER_OP(-)
ZORBA_INTEGER_OP(*)
ZORBA_INTEGER_OP(%)
#undef ZORBA_INTEGER_OP

template<class C> inline
IntegerImpl<C> operator/( IntegerImpl<C> const &i,
                           IntegerImpl<C> const &j ) {
  return IntegerImpl<C>( IntegerImpl<C>::ftoi( i.value_ / j.value_ ) );
}

#define ZORBA_INTEGER_OP(OP,T)                                    \
  template<class C> inline                                         \
  IntegerImpl<C> operator OP( IntegerImpl<C> const &i, T n ) {  \
    return IntegerImpl<C>( i.value_ OP IntegerImpl<C>::make_value_type( n ) ); \
  }                                                               \
                                                                  \
  template<class C> inline                                         \
  IntegerImpl<C> operator OP( T n, IntegerImpl<C> const &i ) {  \
    return IntegerImpl<C>( IntegerImpl<C>::make_value_type( n ) OP i.value_ ); \
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
  template<class C> inline                                       \
  IntegerImpl<C> operator/( IntegerImpl<C> const &i, T n ) {  \
    return IntegerImpl<C>( IntegerImpl<C>::ftoi( i.value_ / IntegerImpl<C>::make_value_type( n ) ) ); \
  }                                                             \
                                                                \
  template<class C> inline                                       \
  IntegerImpl<C> operator/( T n, IntegerImpl<C> const &i ) {  \
    return IntegerImpl<C>( IntegerImpl<C>::ftoi( IntegerImpl<C>::make_value_type( n ) / i.value_ ) ); \
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
  template<class C> inline                                                 \
  IntegerImpl<C>& IntegerImpl<C>::operator OP( IntegerImpl<C> const &i ) { \
    value_ OP i.value_;                                                   \
    return *this;                                                         \
  }

ZORBA_INTEGER_OP(+=)
ZORBA_INTEGER_OP(-=)
ZORBA_INTEGER_OP(*=)
ZORBA_INTEGER_OP(%=)
#undef ZORBA_INTEGER_OP

template<class C> inline
IntegerImpl<C>& IntegerImpl<C>::operator/=( IntegerImpl<C> const &i ) {
  value_ = ftoi( value_ / i.value_ );
  return *this;
}

#define ZORBA_INTEGER_OP(OP,T)                              \
  template<class C> inline                       \
  IntegerImpl<C>& IntegerImpl<C>::operator OP( T n ) {  \
    value_ OP make_value_type( n );                         \
    return *this;                                           \
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
  template<class C> inline                               \
  IntegerImpl<C>& IntegerImpl<C>::operator/=( T n ) { \
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

template<class C>
inline IntegerImpl<C> IntegerImpl<C>::operator-() const {
  return IntegerImpl<C>( -value_ );
}

template<class C>
inline IntegerImpl<C>& IntegerImpl<C>::operator++() {
  ++value_;
  return *this;
}

template<class C>
inline IntegerImpl<C> IntegerImpl<C>::operator++(int) {
  IntegerImpl<C> const result( *this );
  ++value_;
  return result;
}

template<class C>
inline IntegerImpl<C>& IntegerImpl<C>::operator--() {
  --value_;
  return *this;
}

template<class C>
inline IntegerImpl<C> IntegerImpl<C>::operator--(int) {
  IntegerImpl<C> const result( *this );
  --value_;
  return result;
}

////////// relational operators ///////////////////////////////////////////////

#define ZORBA_REL_OP(OP)                                                  \
  template<class C,class D> inline                                        \
  bool operator OP( IntegerImpl<C> const &i, IntegerImpl<D> const &j ) {  \
    return i.value_ OP j.value_;                                          \
  }

ZORBA_REL_OP(==)
ZORBA_REL_OP(!=)
ZORBA_REL_OP(< )
ZORBA_REL_OP(<=)
ZORBA_REL_OP(> )
ZORBA_REL_OP(>=)
#undef ZORBA_REL_OP

#define ZORBA_REL_OP(OP,T)                                    \
  template<class C> inline                                    \
  bool operator OP( IntegerImpl<C> const &i, T n ) {          \
    return i.value_ OP IntegerImpl<C>::make_value_type( n );  \
  }                                                           \
                                                              \
  template<class C> inline                                    \
  bool operator OP( T n, IntegerImpl<C> const &i ) {          \
    return IntegerImpl<C>::make_value_type( n ) OP i.value_;  \
  }

ZORBA_REL_OP(==,char)
ZORBA_REL_OP(!=,char)
ZORBA_REL_OP(< ,char)
ZORBA_REL_OP(<=,char)
ZORBA_REL_OP(> ,char)
ZORBA_REL_OP(>=,char)
ZORBA_REL_OP(==,signed char)
ZORBA_REL_OP(!=,signed char)
ZORBA_REL_OP(< ,signed char)
ZORBA_REL_OP(<=,signed char)
ZORBA_REL_OP(> ,signed char)
ZORBA_REL_OP(>=,signed char)
ZORBA_REL_OP(==,short)
ZORBA_REL_OP(!=,short)
ZORBA_REL_OP(< ,short)
ZORBA_REL_OP(<=,short)
ZORBA_REL_OP(> ,short)
ZORBA_REL_OP(>=,short)
ZORBA_REL_OP(==,int)
ZORBA_REL_OP(!=,int)
ZORBA_REL_OP(< ,int)
ZORBA_REL_OP(<=,int)
ZORBA_REL_OP(> ,int)
ZORBA_REL_OP(>=,int)
ZORBA_REL_OP(==,long)
ZORBA_REL_OP(!=,long)
ZORBA_REL_OP(< ,long)
ZORBA_REL_OP(<=,long)
ZORBA_REL_OP(> ,long)
ZORBA_REL_OP(>=,long)
ZORBA_REL_OP(==,unsigned char)
ZORBA_REL_OP(!=,unsigned char)
ZORBA_REL_OP(< ,unsigned char)
ZORBA_REL_OP(<=,unsigned char)
ZORBA_REL_OP(> ,unsigned char)
ZORBA_REL_OP(>=,unsigned char)
ZORBA_REL_OP(==,unsigned short)
ZORBA_REL_OP(!=,unsigned short)
ZORBA_REL_OP(< ,unsigned short)
ZORBA_REL_OP(<=,unsigned short)
ZORBA_REL_OP(> ,unsigned short)
ZORBA_REL_OP(>=,unsigned short)
ZORBA_REL_OP(==,unsigned int)
ZORBA_REL_OP(!=,unsigned int)
ZORBA_REL_OP(< ,unsigned int)
ZORBA_REL_OP(<=,unsigned int)
ZORBA_REL_OP(> ,unsigned int)
ZORBA_REL_OP(>=,unsigned int)
ZORBA_REL_OP(==,float)
ZORBA_REL_OP(!=,float)
ZORBA_REL_OP(< ,float)
ZORBA_REL_OP(<=,float)
ZORBA_REL_OP(> ,float)
ZORBA_REL_OP(>=,float)
ZORBA_REL_OP(==,double)
ZORBA_REL_OP(!=,double)
ZORBA_REL_OP(< ,double)
ZORBA_REL_OP(<=,double)
ZORBA_REL_OP(> ,double)
ZORBA_REL_OP(>=,double)
#ifndef ZORBA_WITH_BIG_INTEGER
ZORBA_REL_OP(==,long long)
ZORBA_REL_OP(!=,long long)
ZORBA_REL_OP(< ,long long)
ZORBA_REL_OP(<=,long long)
ZORBA_REL_OP(> ,long long)
ZORBA_REL_OP(>=,long long)
ZORBA_REL_OP(==,unsigned long)
ZORBA_REL_OP(!=,unsigned long)
ZORBA_REL_OP(< ,unsigned long)
ZORBA_REL_OP(<=,unsigned long)
ZORBA_REL_OP(> ,unsigned long)
ZORBA_REL_OP(>=,unsigned long)
ZORBA_REL_OP(==,unsigned long long)
ZORBA_REL_OP(!=,unsigned long long)
ZORBA_REL_OP(< ,unsigned long long)
ZORBA_REL_OP(<=,unsigned long long)
ZORBA_REL_OP(> ,unsigned long long)
ZORBA_REL_OP(>=,unsigned long long)
#endif /* ZORBA_WITH_BIG_INTEGER */
#undef ZORBA_REL_OP

////////// miscellaneous //////////////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER

template<class C>
inline int IntegerImpl<C>::compare( IntegerImpl<C> const &i ) const {
  return value_.compare( i.value_ );
}

template<class C>
inline bool IntegerImpl<C>::is_xs_int() const {
  return value_ >= MAPM::getMinInt32() && value_ <= MAPM::getMaxInt32();
}

template<class C>
inline bool IntegerImpl<C>::is_xs_long() const {
  return value_ >= MAPM::getMinInt64() && value_ <= MAPM::getMaxInt64();
}

template<class C>
inline int IntegerImpl<C>::sign() const {
  return value_.sign();
}

#else /* ZORBA_WITH_BIG_INTEGER */

template<class C>
inline int IntegerImpl<C>::compare( IntegerImpl<C> const &i ) const {
  return value_ < i.value_ ? -1 : value_ > i.value_ ? 1 : 0;
}

template<class C>
inline uint32_t IntegerImpl<C>::hash() const {
  return static_cast<uint32_t>( value_ );
}

template<class C>
inline bool IntegerImpl<C>::is_cxx_long() const {
  return ZORBA_IN_RANGE( value_, long );
}

template<class C>
inline bool IntegerImpl<C>::is_xs_byte() const {
  return ZORBA_IN_RANGE( value_, xs_byte );
}

template<class C>
inline bool IntegerImpl<C>::is_xs_int() const {
  return ZORBA_IN_RANGE( value_, xs_int );
}

template<class C>
inline bool IntegerImpl<C>::is_xs_long() const {
  return ZORBA_IN_RANGE( value_, xs_long );
}

template<class C>
inline bool IntegerImpl<C>::is_xs_short() const {
  return ZORBA_IN_RANGE( value_, xs_short );
}

template<class C>
inline bool IntegerImpl<C>::is_xs_unsignedByte() const {
  return ZORBA_IN_RANGE( value_, xs_unsignedByte );
}

template<class C>
inline bool IntegerImpl<C>::is_xs_unsignedInt() const {
  return ZORBA_IN_RANGE( value_, xs_unsignedInt );
}

template<class C>
inline bool IntegerImpl<C>::is_xs_unsignedLong() const {
  return ZORBA_IN_RANGE( value_, xs_unsignedLong );
}

template<class C>
inline bool IntegerImpl<C>::is_xs_unsignedShort() const {
  return ZORBA_IN_RANGE( value_, xs_unsignedShort );
}

template<class C>
inline int IntegerImpl<C>::sign() const {
  return ztd::lt0( value_ ) ? -1 : value_ > 0 ? 1 : 0;
}

#endif /* ZORBA_WITH_BIG_INTEGER */

template<class C> inline
typename IntegerImpl<C>::value_type& IntegerImpl<C>::value() {
  return value_;
}

template<class C> inline
typename IntegerImpl<C>::value_type const& IntegerImpl<C>::value() const {
  return value_;
}

template<class C>
inline std::ostream& operator<<( std::ostream &os, IntegerImpl<C> const &i ) {
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
