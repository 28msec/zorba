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
#include <string>

// Zorba
#include <zorba/config.h>
#include "common/common.h"
#include "util/stl_util.h"
#include "util/string_util.h"

// local
#include "m_apm.h"
#include "numeric_types.h"
#include "schema_types_base.h"
#include "zorbatypes_decl.h"
#include "zstring.h"

namespace zorba {

template<class TraitsType>
class IntegerImpl;

namespace serialization {
  class Archiver;

  template<class T>
  void operator&( Archiver&, IntegerImpl<T>& );
}

///////////////////////////////////////////////////////////////////////////////

struct integer_traits {
  static int const default_value = 0;

  template<typename ValueType>
  static ValueType check_value( ValueType n, bool ) {
    return n;
  }

  static MAPM const& check_value( MAPM const &n, bool ) {
    return n;
  }

protected:
  static void throw_error( std::string const&, bool );

  template<typename ValueType>
  static void throw_error( ValueType n, char const *op,
                           bool throw_range_error ) {
    std::string const what( BUILD_STRING( n, ": not ", op, " 0" ) );
    throw_error( what, throw_range_error );
  }

  static void throw_error( MAPM const &n, char const *op,
                           bool throw_range_error );
};

struct nonPositive_traits : integer_traits {
  template<typename ValueType>
  static ValueType check_value( ValueType n, bool throw_range_error ) {
    if ( !ztd::le0( n ) )
      throw_error( n, "<=", throw_range_error );
    return n;
  }
  static MAPM const& check_value( MAPM const &n, bool throw_range_error ) {
    if ( !(n.sign() <= 0) )
      throw_error( n, "<=", throw_range_error );
    return n;
  }
};

struct negative_traits : nonPositive_traits {
  static int const default_value = -1;

  template<typename ValueType>
  static ValueType check_value( ValueType n, bool throw_range_error ) {
    if ( !ztd::lt0( n ) )
      throw_error( n, "<", throw_range_error );
    return n;
  }
  static MAPM const& check_value( MAPM const &n, bool throw_range_error ) {
    if ( !(n.sign() < 0) )
      throw_error( n, "<", throw_range_error );
    return n;
  }
};

struct nonNegative_traits : integer_traits {
  template<typename ValueType>
  static ValueType check_value( ValueType n, bool throw_range_error ) {
    if ( !ztd::ge0( n ) )
      throw_error( n, ">=", throw_range_error );
    return n;
  }
  static MAPM const& check_value( MAPM const &n, bool throw_range_error ) {
    if ( !(n.sign() >= 0) )
      throw_error( n, ">=", throw_range_error );
    return n;
  }
};

struct positive_traits : nonNegative_traits {
  static int const default_value = 1;

  template<typename ValueType>
  static ValueType check_value( ValueType n, bool throw_range_error ) {
    if ( !ztd::gt0( n ) )
      throw_error( n, ">", throw_range_error );
    return n;
  }
  static MAPM const& check_value( MAPM const &n, bool throw_range_error ) {
    if ( !(n.sign() > 0) )
      throw_error( n, ">", throw_range_error );
    return n;
  }
};

///////////////////////////////////////////////////////////////////////////////

template<class TraitsType>
class IntegerImpl {
public:
#ifdef ZORBA_WITH_BIG_INTEGER
  typedef MAPM value_type;
#else
  typedef long long value_type;
#endif /* ZORBA_WITH_BIG_INTEGER */
  typedef TraitsType traits_type;

  ////////// constructors /////////////////////////////////////////////////////

  explicit IntegerImpl( char c );
  explicit IntegerImpl( signed char c );
  explicit IntegerImpl( short n );
  explicit IntegerImpl( int n = traits_type::default_value );
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
   * Constructs from another %IntegerImpl even if its \c TraitsType is
   * different.  (This subsumes the conventional copy constructor.)
   *
   * @tparam TraitsType2 The traits type of \a i.
   * @param i The %IntegerImpl to copy from.
   * @throw std::invalid_argument if \a i contains a value that is invalid for
   * this type of integer.
   */
  template<class TraitsType2>
  IntegerImpl( IntegerImpl<TraitsType2> const &i );

  ////////// assignment operators /////////////////////////////////////////////

  /**
   * Assign from an %IntegerImpl even if its \c TraitsType is different.
   * (This subsumes the conventional assignment operator.)
   *
   * @tparam TraitsType2 The traits type of \a i.
   * @param i The %IntegerImpl to assign from.
   * @return Returns \c *this.
   * @throw std::invalid_argument if \a i contains a value that is invalid for
   * this type of integer.
   */
  template<class TraitsType2>
  IntegerImpl& operator=( IntegerImpl<TraitsType2> const &i );

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

#define ZORBA_INTEGER_OP(OP)                                            \
  template<class T,class U> friend                                      \
  Integer operator OP( IntegerImpl<T> const&, IntegerImpl<U> const& );  \
                                                                        \
  template<class T> friend                                              \
  Decimal operator OP( IntegerImpl<T> const&, Decimal const& );         \
                                                                        \
  template<class T> friend                                              \
  Decimal operator OP( Decimal const&, IntegerImpl<T> const& )

  ZORBA_INTEGER_OP(+);
  ZORBA_INTEGER_OP(-);
  ZORBA_INTEGER_OP(*);
  ZORBA_INTEGER_OP(/);
  ZORBA_INTEGER_OP(%);
#undef ZORBA_INTEGER_OP

#define ZORBA_INTEGER_OP(OP,N)                      \
  template<class T> friend                          \
  Integer operator OP( IntegerImpl<T> const&, N );  \
                                                    \
  template<class T> friend                          \
  Integer operator OP( N, IntegerImpl<T> const& )

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

#define ZORBA_INTEGER_OP(OP,T) \
  IntegerImpl& operator OP( T )

  ZORBA_INTEGER_OP(+=,IntegerImpl const&);
  ZORBA_INTEGER_OP(-=,IntegerImpl const&);
  ZORBA_INTEGER_OP(*=,IntegerImpl const&);
  ZORBA_INTEGER_OP(/=,IntegerImpl const&);
  ZORBA_INTEGER_OP(%=,IntegerImpl const&);
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

  Integer operator-() const;

  IntegerImpl& operator++();
  IntegerImpl  operator++(int);
  IntegerImpl& operator--();
  IntegerImpl  operator--(int);

  ////////// relational operators /////////////////////////////////////////////

#define ZORBA_REL_OP(OP)                                            \
  template<class T,class U> friend                                  \
  bool operator OP( IntegerImpl<T> const&, IntegerImpl<U> const& ); \
                                                                    \
  template<class T> friend                                          \
  bool operator OP( IntegerImpl<T> const&, Decimal const& );        \
                                                                    \
  template<class T> friend                                          \
  bool operator OP( Decimal const&, IntegerImpl<T> const& )

  ZORBA_REL_OP(==);
  ZORBA_REL_OP(!=);
  ZORBA_REL_OP(< );
  ZORBA_REL_OP(<=);
  ZORBA_REL_OP(> );
  ZORBA_REL_OP(>=);
#undef ZORBA_REL_OP

#define ZORBA_REL_OP(OP,N)                                                \
  template<class T> friend bool operator OP( IntegerImpl<T> const&, N );  \
  template<class T> friend bool operator OP( N, IntegerImpl<T> const& )

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

  /////////////////////////////////////////////////////////////////////////////

private:
#ifdef ZORBA_WITH_BIG_INTEGER
  typedef long int_cast_type;
#else
  typedef value_type int_cast_type;
#endif /* ZORBA_WITH_BIG_INTEGER */

  value_type value_;

#ifdef ZORBA_WITH_BIG_INTEGER
  IntegerImpl( value_type const &v ) : value_( v ) { }

  static value_type ftoi( double d ) {
    return value_type( d >= 0 ? floor( d ) : ceil( d ) );
  }

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

  static value_type ftoi( double d );

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

  void parse( char const *s, bool throw_range_error );

  friend class Decimal;
  template<typename F> friend class FloatImpl;
  template<class T> friend class IntegerImpl;

  friend xs_int to_xs_int( Integer const& );
  friend xs_long to_xs_long( Integer const& );
  friend xs_unsignedByte to_xs_unsignedByte( Integer const& );
  friend xs_unsignedShort to_xs_unsignedShort( Integer const& );
  friend xs_unsignedInt to_xs_unsignedInt( Integer const& );
  friend xs_unsignedLong to_xs_unsignedLong( Integer const& );

  template<class T> friend
  void serialization::operator&( serialization::Archiver&, IntegerImpl<T>& );
};

typedef IntegerImpl<integer_traits>     Integer;
typedef IntegerImpl<negative_traits>    NegativeInteger;
typedef IntegerImpl<nonNegative_traits> NonNegativeInteger;
typedef IntegerImpl<nonPositive_traits> NonPositiveInteger;
typedef IntegerImpl<positive_traits>    PositiveInteger;

////////// constructors ///////////////////////////////////////////////////////

template<class T>
inline IntegerImpl<T>::IntegerImpl( char c ) :
  value_( static_cast<long>( T::check_value( c, false ) ) )
{
}

template<class T>
inline IntegerImpl<T>::IntegerImpl( signed char c ) :
  value_( static_cast<long>( T::check_value( c, false ) ) )
{
}

template<class T>
inline IntegerImpl<T>::IntegerImpl( short n ) :
  value_( static_cast<long>( T::check_value( n, false ) ) )
{
}

template<class T>
inline IntegerImpl<T>::IntegerImpl( int n ) :
  value_( static_cast<long>( T::check_value( n, false ) ) )
{
}

template<class T>
inline IntegerImpl<T>::IntegerImpl( long n ) :
  value_( T::check_value( n, false ) )
{
}

#ifndef ZORBA_WITH_BIG_INTEGER
template<class T>
inline IntegerImpl<T>::IntegerImpl( long long n ) :
  value_( T::check_value( n, false ) )
{
}
#endif /* ZORBA_WITH_BIG_INTEGER */

template<class T>
inline IntegerImpl<T>::IntegerImpl( unsigned char c ) :
  value_( static_cast<long>( (unsigned long)T::check_value( c, false ) ) )
{
}

template<class T>
inline IntegerImpl<T>::IntegerImpl( unsigned short n ) :
  value_( static_cast<long>( (unsigned long)T::check_value( n, false ) ) )
{
}

#ifdef ZORBA_WITH_BIG_INTEGER
#if ZORBA_SIZEOF_INT != ZORBA_SIZEOF_LONG
template<class T>
inline IntegerImpl<T>::IntegerImpl( unsigned int n ) :
  value_( static_cast<long>( (unsigned long)T::check_value( n, false ) ) )
{
}
#endif /* ZORBA_SIZEOF_INT == ZORBA_SIZEOF_LONG */
#else /* ZORBA_WITH_BIG_INTEGER */

template<class T>
inline IntegerImpl<T>::IntegerImpl( unsigned int n ) :
  value_( static_cast<value_type>( T::check_value( n, false ) ) )
{
}

template<class T>
inline IntegerImpl<T>::IntegerImpl( unsigned long n ) :
  value_( static_cast<value_type>( T::check_value( n, false ) ) )
{
}

template<class T>
inline IntegerImpl<T>::IntegerImpl( unsigned long long n ) :
  value_( static_cast<value_type>( T::check_value( n, false ) ) )
{
}
#endif /* ZORBA_WITH_BIG_INTEGER */

template<class T>
inline IntegerImpl<T>::IntegerImpl( float n ) :
#ifdef ZORBA_WITH_BIG_INTEGER
  value_( static_cast<double>( T::check_value( n, false ) ) )
#else
  value_( static_cast<value_type>( T::check_value( n, false ) ) )
#endif /* ZORBA_WITH_BIG_INTEGER */
{
}

template<class T>
inline IntegerImpl<T>::IntegerImpl( double n ) :
#ifdef ZORBA_WITH_BIG_INTEGER
  value_( T::check_value( n, false ) )
#else
  value_( static_cast<value_type>( T::check_value( n, false ) ) )
#endif /* ZORBA_WITH_BIG_INTEGER */
{
}

template<class T>
inline IntegerImpl<T>::IntegerImpl( char const *s ) {
  parse( s, false );
}

template<class T>
template<class U>
inline IntegerImpl<T>::IntegerImpl( IntegerImpl<U> const &i ) :
  value_( T::check_value( i.value_, false ) )
{
}

////////// assignment operators ///////////////////////////////////////////////

#define ZORBA_ASSIGN_OP(N)                                              \
  template<class T> inline                                              \
  IntegerImpl<T>& IntegerImpl<T>::operator=( N n ) {                    \
    value_ = static_cast<int_cast_type>( T::check_value( n, false ) );  \
    return *this;                                                       \
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

template<class T>
inline IntegerImpl<T>& IntegerImpl<T>::operator=( char const *s ) {
  parse( s, false );
  return *this;
}

template<class T>
template<class U>
inline IntegerImpl<T>& IntegerImpl<T>::operator=( IntegerImpl<U> const &i ) {
  T::check_value( value_ = i.value_, false );
  return *this;
}

////////// arithmetic operators ///////////////////////////////////////////////

#define ZORBA_INTEGER_OP(OP)                                                \
  template<class T,class U> inline                                          \
  Integer operator OP( IntegerImpl<T> const &i, IntegerImpl<U> const &j ) { \
    return Integer( i.value_ OP j.value_ );                                 \
  }

ZORBA_INTEGER_OP(+)
ZORBA_INTEGER_OP(-)
ZORBA_INTEGER_OP(*)
ZORBA_INTEGER_OP(%)
#undef ZORBA_INTEGER_OP

template<class T,class U>
inline Integer operator/( IntegerImpl<T> const &i, IntegerImpl<U> const &j ) {
  return Integer( Integer::ftoi( i.value_ / j.value_ ) );
}

#define ZORBA_INTEGER_OP(OP,N)                                    \
  template<class T> inline                                        \
  Integer operator OP( IntegerImpl<T> const &i, N n ) {           \
    return Integer( i.value_ OP Integer::make_value_type( n ) );  \
  }                                                               \
                                                                  \
  template<class T> inline                                        \
  Integer operator OP( N n, IntegerImpl<T> const &i ) {           \
    return Integer( Integer::make_value_type( n ) OP i.value_ );  \
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

#define ZORBA_INTEGER_OP(N)                           \
  template<class T> inline                            \
  Integer operator/( IntegerImpl<T> const &i, N n ) { \
    return Integer( Integer::ftoi( i.value_ / Integer::make_value_type( n ) ) ); \
  }                                                   \
                                                      \
  template<class T> inline                            \
  Integer operator/( N n, IntegerImpl<T> const &i ) { \
    return Integer( Integer::ftoi( Integer::make_value_type( n ) / i.value_ ) ); \
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

#define ZORBA_INTEGER_OP(OP)                                                \
  template<class T> inline                                                  \
  IntegerImpl<T>& IntegerImpl<T>::operator OP( IntegerImpl<T> const &i ) {  \
    T::check_value( value_ OP i.value_, true );                             \
    return *this;                                                           \
  }

ZORBA_INTEGER_OP(+=)
ZORBA_INTEGER_OP(-=)
ZORBA_INTEGER_OP(*=)
ZORBA_INTEGER_OP(%=)
#undef ZORBA_INTEGER_OP

template<class T>
inline IntegerImpl<T>& IntegerImpl<T>::operator/=( IntegerImpl<T> const &i ) {
  value_ = T::check_value( ftoi( value_ / i.value_ ), true );
  return *this;
}

#define ZORBA_INTEGER_OP(OP,N)                              \
  template<class T> inline                                  \
  IntegerImpl<T>& IntegerImpl<T>::operator OP( N n ) {      \
    T::check_value( value_ OP make_value_type( n ), true ); \
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

#define ZORBA_INTEGER_OP(N)                                                 \
  template<class T> inline                                                  \
  IntegerImpl<T>& IntegerImpl<T>::operator/=( N n ) {                       \
    value_ = T::check_value( ftoi( value_ / make_value_type( n ) ), true ); \
    return *this;                                                           \
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

template<class T>
inline Integer IntegerImpl<T>::operator-() const {
  return Integer( -value_ );
}

template<class T>
inline IntegerImpl<T>& IntegerImpl<T>::operator++() {
  T::check_value( ++value_, true );
  return *this;
}

template<class T>
inline IntegerImpl<T> IntegerImpl<T>::operator++(int) {
  IntegerImpl<T> const result( *this );
  T::check_value( ++value_, true );
  return result;
}

template<class T>
inline IntegerImpl<T>& IntegerImpl<T>::operator--() {
  T::check_value( --value_, true );
  return *this;
}

template<class T>
inline IntegerImpl<T> IntegerImpl<T>::operator--(int) {
  IntegerImpl<T> const result( *this );
  T::check_value( --value_, true );
  return result;
}

////////// relational operators ///////////////////////////////////////////////

#define ZORBA_REL_OP(OP)                                                  \
  template<class T,class U> inline                                        \
  bool operator OP( IntegerImpl<T> const &i, IntegerImpl<U> const &j ) {  \
    return i.value_ OP j.value_;                                          \
  }

ZORBA_REL_OP(==)
ZORBA_REL_OP(!=)
ZORBA_REL_OP(< )
ZORBA_REL_OP(<=)
ZORBA_REL_OP(> )
ZORBA_REL_OP(>=)
#undef ZORBA_REL_OP

#define ZORBA_REL_OP(OP,N)                                    \
  template<class T> inline                                    \
  bool operator OP( IntegerImpl<T> const &i, N n ) {          \
    return i.value_ OP IntegerImpl<T>::make_value_type( n );  \
  }                                                           \
                                                              \
  template<class T> inline                                    \
  bool operator OP( N n, IntegerImpl<T> const &i ) {          \
    return IntegerImpl<T>::make_value_type( n ) OP i.value_;  \
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

template<class T>
inline int IntegerImpl<T>::compare( IntegerImpl<T> const &i ) const {
  return value_.compare( i.value_ );
}

template<class T>
inline bool IntegerImpl<T>::is_xs_int() const {
  return value_ >= MAPM::getMinInt32() && value_ <= MAPM::getMaxInt32();
}

template<class T>
inline bool IntegerImpl<T>::is_xs_long() const {
  return value_ >= MAPM::getMinInt64() && value_ <= MAPM::getMaxInt64();
}

template<class T>
inline int IntegerImpl<T>::sign() const {
  return value_.sign();
}

#else /* ZORBA_WITH_BIG_INTEGER */

template<class T>
inline int IntegerImpl<T>::compare( IntegerImpl<T> const &i ) const {
  return value_ < i.value_ ? -1 : value_ > i.value_ ? 1 : 0;
}

template<class T>
inline uint32_t IntegerImpl<T>::hash() const {
  return static_cast<uint32_t>( value_ );
}

template<class T>
inline bool IntegerImpl<T>::is_cxx_long() const {
  return ZORBA_IN_RANGE( value_, long );
}

template<class T>
inline bool IntegerImpl<T>::is_xs_byte() const {
  return ZORBA_IN_RANGE( value_, xs_byte );
}

template<class T>
inline bool IntegerImpl<T>::is_xs_int() const {
  return ZORBA_IN_RANGE( value_, xs_int );
}

template<class T>
inline bool IntegerImpl<T>::is_xs_long() const {
  return ZORBA_IN_RANGE( value_, xs_long );
}

template<class T>
inline bool IntegerImpl<T>::is_xs_short() const {
  return ZORBA_IN_RANGE( value_, xs_short );
}

template<class T>
inline bool IntegerImpl<T>::is_xs_unsignedByte() const {
  return ZORBA_IN_RANGE( value_, xs_unsignedByte );
}

template<class T>
inline bool IntegerImpl<T>::is_xs_unsignedInt() const {
  return ZORBA_IN_RANGE( value_, xs_unsignedInt );
}

template<class T>
inline bool IntegerImpl<T>::is_xs_unsignedLong() const {
  return ZORBA_IN_RANGE( value_, xs_unsignedLong );
}

template<class T>
inline bool IntegerImpl<T>::is_xs_unsignedShort() const {
  return ZORBA_IN_RANGE( value_, xs_unsignedShort );
}

template<class T>
inline int IntegerImpl<T>::sign() const {
  return ztd::lt0( value_ ) ? -1 : value_ > 0 ? 1 : 0;
}

#endif /* ZORBA_WITH_BIG_INTEGER */

template<class T>
inline typename IntegerImpl<T>::value_type& IntegerImpl<T>::value() {
  return value_;
}

template<class T>
inline typename IntegerImpl<T>::value_type const&
IntegerImpl<T>::value() const {
  return value_;
}

template<class T>
inline std::ostream& operator<<( std::ostream &os, IntegerImpl<T> const &i ) {
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
