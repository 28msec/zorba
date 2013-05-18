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

#include <cstring>
#include <limits>

#include "common/common.h"
#include "util/ascii_util.h"

#include "decimal.h"
#include "float.h"
#include "integer.h"
#include "numconversions.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

Decimal::value_type const Decimal::round_precision_limit( 64 );

void Decimal::parse( char const *s, value_type *result, int parse_options ) {
  if ( !*s )
    throw invalid_argument( "empty string" );

  s = ascii::trim_start_space( s );
  char const *const first_non_ws = s;

  if ( *s == '+' || *s == '-' )
    ++s;
  while ( ascii::is_digit( *s ) )
    ++s;
  if ( parse_options & parse_decimal ) {
    if ( *s == '.' ) {
      ++s;
      while ( ascii::is_digit( *s ) )
        ++s;
    }
  }
  char const *first_trailing_ws = nullptr;
  while ( ascii::is_space( *s ) ) {
    if ( !first_trailing_ws )
      first_trailing_ws = s;
    ++s;
  }
  if ( *s )
    throw range_error(
      BUILD_STRING( '"', *s, "\": invalid value for integer" )
    );

  if ( first_trailing_ws ) {
    ptrdiff_t const size = first_trailing_ws - first_non_ws;
    char *const copy = ::strncpy( new char[ size + 1 ], first_non_ws, size );
    copy[ size ] = '\0';
    *result = copy;
    delete[] copy;
  } else
    *result = first_non_ws;
}

/**
 * Rounds .xxx9999xxx or .xxx000000xxx.
 */
void Decimal::reduce( char *s ) {
  char *const dot = ::strrchr( s, '.' );
  if ( !dot )                           // not a floating-point number
    return;

  bool has_e = false;
  char *e = ::strpbrk( s, "eE" );
  if ( !e )
    e = s + ::strlen( s );              // eliminates a special-case
  else
    has_e = true;
  char *digit = e - 1;

  if ( ::strncmp( dot + 1, "9999", 3 ) == 0 ) {
    // The "leading nines" case, e.g., 12.9999[34][E56]
    if ( has_e ) {
      ::memmove( dot + 2, e, strlen( e ) + 1 );
      dot[1] = '0';
    } else
      ::memmove( dot, e, strlen( e ) + 1 );
    digit = dot - 1;
    char const *const first = *s == '-' ? s + 1 : s;
    while ( true ) {
      if ( *digit == '9' ) {
        *digit = '0';
        if ( digit == first ) {
          // slide to the right to insert a leading '1'
          ::memmove( digit + 1, digit, strlen( digit ) + 1 );
          *digit = '1';
          break;
        }
        --digit;
      } else {
        ++digit[0];                     // e.g., 12 => 13
        break;
      }
    }
    return;
  }

  if ( char *const nines = ::strstr( dot + 1, "9999" ) ) {
    // The "in-the-middle nines" case, e.g., 12.349999[56][E78]
    ++nines[-1];                        // e.g., .xxx19 => .xxx29
    ::memmove( nines, e, strlen( e ) + 1 );
    return;
  }

  if ( char *zeros = ::strstr( dot + 1, "000000" ) ) {
    // The "zeros" case, e.g., 12.0000003, 12.340000005.
    if ( zeros == dot + 1 && has_e )
      ++zeros;                          // leave one 0 after . and before E
    ::memmove( zeros, e, strlen( e ) + 1 );
    if ( !has_e ) {
      char *const last = s + ::strlen( s ) - 1;
      if ( *last == '.' )
        *last = '\0';
    }
    return;
  }
}

////////// constructors ///////////////////////////////////////////////////////

Decimal::Decimal( long long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
}

Decimal::Decimal( unsigned long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
}

Decimal::Decimal( unsigned long long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
}

Decimal::Decimal( float f ) {
  if ( f != f ||
       f ==  std::numeric_limits<float>::infinity() ||
       f == -std::numeric_limits<float>::infinity() )
    throw invalid_argument( "float value = infinity" );
  value_ = f;
}

Decimal::Decimal( double d ) {
  if ( d != d ||
       d ==  std::numeric_limits<double>::infinity() ||
       d == -std::numeric_limits<double>::infinity() )
    throw invalid_argument( "double value = infinity" );
  value_ = d;
}

Decimal::Decimal( Double const &d ) {
  if ( !d.isFinite() )
    throw invalid_argument( "double value = infinity" );
  value_ = d.getNumber();
}

Decimal::Decimal( Float const &f ) {
  if ( !f.isFinite() )
    throw invalid_argument( "float value = infinity" );
  value_ = f.getNumber();
}

template<class T>
Decimal::Decimal( IntegerImpl<T> const &i ) : value_( i.itod() ) {
}

// instantiate Decimal-from-Integer constructors
template Decimal::Decimal( Integer const& );
template Decimal::Decimal( NegativeInteger const& );
template Decimal::Decimal( NonNegativeInteger const& );
template Decimal::Decimal( NonPositiveInteger const& );
template Decimal::Decimal( PositiveInteger const& );

////////// assignment operators ///////////////////////////////////////////////

Decimal& Decimal::operator=( long long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  return *this;
}

Decimal& Decimal::operator=( unsigned long long n ) {
  ascii::itoa_buf_type buf;
  value_ = ascii::itoa( n, buf );
  return *this;
}

template<class T>
Decimal& Decimal::operator=( IntegerImpl<T> const &i ) {
  value_ = i.itod();
  return *this;
}

template Decimal& Decimal::operator=( Integer const& );
template Decimal& Decimal::operator=( NegativeInteger const& );
template Decimal& Decimal::operator=( NonNegativeInteger const& );
template Decimal& Decimal::operator=( NonPositiveInteger const& );
template Decimal& Decimal::operator=( PositiveInteger const& );

Decimal& Decimal::operator=( Double const &d ) {
  if ( !d.isFinite() )
    throw invalid_argument( "not finite" );
  value_ = d.getNumber();
  return *this;
}

Decimal& Decimal::operator=( Float const &f ) {
  if ( !f.isFinite() )
    throw invalid_argument( "not finite" );
  value_ = f.getNumber();
  return *this;
}

////////// arithmetic operators ///////////////////////////////////////////////

#define ZORBA_INSTANTIATE(OP,I) \
  template Decimal operator OP( Decimal const&, I const& )

#define ZORBA_DECIMAL_OP(OP)                                          \
  template<class T> inline                                            \
  Decimal operator OP( Decimal const &d, IntegerImpl<T> const &i ) {  \
    return d.value_ OP i.itod();                                      \
  }                                                                   \
  ZORBA_INSTANTIATE(OP,Integer);                                      \
  ZORBA_INSTANTIATE(OP,NegativeInteger);                              \
  ZORBA_INSTANTIATE(OP,NonNegativeInteger);                           \
  ZORBA_INSTANTIATE(OP,NonPositiveInteger);                           \
  ZORBA_INSTANTIATE(OP,PositiveInteger);

ZORBA_DECIMAL_OP(+);
ZORBA_DECIMAL_OP(-);
ZORBA_DECIMAL_OP(*);
ZORBA_DECIMAL_OP(/);
ZORBA_DECIMAL_OP(%);
#undef ZORBA_DECIMAL_OP
#undef ZORBA_INSTANTIATE

////////// relational operators ///////////////////////////////////////////////

#define ZORBA_INSTANTIATE(OP,I) \
  template bool operator OP( Decimal const&, I const& )

#define ZORBA_DECIMAL_OP(OP)                                      \
  template<class T> inline                                        \
  bool operator OP( Decimal const &d, IntegerImpl<T> const &i ) { \
    return d.value_ OP i.itod();                                  \
  }                                                               \
  ZORBA_INSTANTIATE( OP, Integer );                               \
  ZORBA_INSTANTIATE( OP, NegativeInteger );                       \
  ZORBA_INSTANTIATE( OP, NonNegativeInteger );                    \
  ZORBA_INSTANTIATE( OP, NonPositiveInteger );                    \
  ZORBA_INSTANTIATE( OP, PositiveInteger );

ZORBA_DECIMAL_OP(==);
ZORBA_DECIMAL_OP(!=);
ZORBA_DECIMAL_OP(< );
ZORBA_DECIMAL_OP(<=);
ZORBA_DECIMAL_OP(> );
ZORBA_DECIMAL_OP(>=);
#undef ZORBA_DECIMAL_OP
#undef ZORBA_INSTANTIATE

////////// math functions /////////////////////////////////////////////////////

Decimal Decimal::round() const {
  return round( numeric_consts<xs_integer>::zero() );
}

template<class T>
Decimal Decimal::round( IntegerImpl<T> const &precision ) const {
  return round2( value_, precision.itod() );
}

template Decimal Decimal::round( Integer const& ) const;
template Decimal Decimal::round( NegativeInteger const& ) const;
template Decimal Decimal::round( NonNegativeInteger const& ) const;
template Decimal Decimal::round( NonPositiveInteger const& ) const;
template Decimal Decimal::round( PositiveInteger const& ) const;

Decimal::value_type Decimal::round2( value_type const &v,
                                     value_type const &precision ) {
  if ( precision < -round_precision_limit )
    return round2( v, -round_precision_limit );
  if ( precision > round_precision_limit )
    return round2( v, round_precision_limit );

  value_type const exp( value_type(10).pow( precision ) );
  value_type result( v * exp );
  result += MAPM::get0_5();
  result = result.floor();
  result /= exp;
  return result;
}

template<class T>
Decimal Decimal::roundHalfToEven( IntegerImpl<T> const &precision ) const {
  return roundHalfToEven2( value_, precision.itod() );
}

template Decimal Decimal::roundHalfToEven( Integer const& ) const;
template Decimal Decimal::roundHalfToEven( NegativeInteger const& ) const;
template Decimal Decimal::roundHalfToEven( NonNegativeInteger const& ) const;
template Decimal Decimal::roundHalfToEven( NonPositiveInteger const& ) const;
template Decimal Decimal::roundHalfToEven( PositiveInteger const& ) const;

Decimal::value_type Decimal::roundHalfToEven2( value_type const &v,
                                               value_type const &precision ) {
  if ( precision < -round_precision_limit )
    return roundHalfToEven2( v, -round_precision_limit );
  if ( precision > round_precision_limit )
    return roundHalfToEven2( v, round_precision_limit );

  value_type const exp( value_type(10).pow( precision ) );
  value_type result( v * exp );
  bool const aHalfVal = (result - MAPM::get0_5()) == result.floor();
  result += MAPM::get0_5();
  result = result.floor();
  if ( aHalfVal && result.is_odd() )
    --result;
  result /= exp;
  return result;
}

////////// miscellaneous //////////////////////////////////////////////////////

size_t Decimal::alloc_size() const {
  return value_.significant_digits();
}

uint32_t Decimal::hash( value_type const &value ) {
  char buf[1024];
  char *bufp = value.exponent() + 3 > 1024 ?
    new char[ value.exponent() + 3 ] : buf;

  if ( value.sign() < 0 ) {
    if ( value >= MAPM::getMinInt64() ) {
      // hash it as int64
      value.toIntegerString( bufp );
      stringstream ss( bufp );
      int64_t n;
      ss >> n;
      assert( ss.eof() );
      if ( bufp != buf )
        delete[] bufp;
      return static_cast<uint32_t>( n & 0xFFFFFFFF );
    }
  } else if ( value <= MAPM::getMaxUInt64() ) {
    // hash it as uint64
    value.toIntegerString( bufp );
    stringstream ss( bufp );
    uint64_t n;
    ss >> n;
    assert( ss.eof() );
    if ( bufp != buf )
      delete[] bufp;
    return static_cast<uint32_t>( n & 0xFFFFFFFF );
  }

  // In all other cases, hash it as double
  value.toFixPtString( bufp, ZORBA_FLOAT_POINT_PRECISION );
  stringstream ss( bufp );
  double n;
  ss >> n;
  assert( ss.eof() );
  if ( bufp != buf )
    delete[] bufp;
  return static_cast<uint32_t>( n );
}

zstring Decimal::toString( value_type const &value, bool minusZero,
                           int precision ) {
  char buf[ 2048 ];

  if ( minusZero ) {
    if ( value.sign() == 0 )
      buf[0] = '-';
    else
      minusZero = false;
  }

  value.toFixPtString( buf + minusZero, precision );

  //
  // Note that in the canonical representation, the decimal point is required
  // and there must be at least one digit to the right and one digit to the
  // left of the decimal point (which may be 0).
  //
  if ( strchr( buf, '.' ) != 0 ) {
    // remove trailing 0's
    char *last = buf + strlen( buf );
    while ( *--last == '0' )
      *last = '\0';
    if ( *last == '.' )                 // remove '.' if no digits after it
      *last = '\0';
  }

  if ( precision < ZORBA_FLOAT_POINT_PRECISION )
    reduce( buf );
  return buf;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
