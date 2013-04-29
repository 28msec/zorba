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
#include "integer.h"
#include "numconversions.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

Decimal::value_type const Decimal::round_precision_limit( 64 );

void Decimal::parse( char const *s, value_type *result, int parse_options ) {
  if ( !*s )
    throw std::invalid_argument( "empty string" );

  s = ascii::trim_start_whitespace( s );
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
    throw std::invalid_argument(
      BUILD_STRING( '"', *s, "\": invalid character" )
    );

  if ( first_trailing_ws ) {
    ptrdiff_t const size = first_trailing_ws - first_non_ws;
    char *const copy = std::strncpy( new char[ size + 1 ], first_non_ws, size );
    copy[ size ] = '\0';
    *result = copy;
    delete[] copy;
  } else
    *result = first_non_ws;

}

/**
 * Remove trailing .99999 or .000001.
 * Find four or five consecutive 9 or 0 after decimal point and eliminate them.
 */
void Decimal::reduce( char *s ) {
  char *dot = strrchr( s, '.' );
  if ( !dot )                           // not a floating point number
    return;

  bool has_e = false;
  char *e = strrchr( s, 'E' );
  if ( !e )
    e = strrchr( s, 'e' );
  if ( !e )
    e = s + strlen( s );
  else
    has_e = true;

  char *digits = e - 1;
  for ( int pos = (int)(digits - dot); pos > 8; --pos, --digits ) {
    if ( *digits == '9' ) {
      if ( digits[-1] == '9' && digits[-2] == '9' && digits[-3] == '9' ) {
        if ( ascii::is_digit( digits[1] ) && digits[1] >= '5' )
          digits -= 4;
        else if ( digits[-4] == '9' )
          digits -= 5;
        else
          continue;

        // now add 1 to remaining digits
        char *last_digit = digits;
        while ( digits >= s ) {
          if ( digits[0] == '.' ) {
            // skip
          } else if ( digits[0] == '9' ) {
            digits[0] = '0';
            if ( last_digit == digits )
              --last_digit;
          } else {
            if ( ascii::is_digit( digits[0] ) )
              digits[0]++;
            break;
          }
          --digits;
        }
        if ( last_digit[0] != '.' )
          ++last_digit;
        else if ( has_e ) {
          last_digit[1] = '0';
          last_digit += 2;
        }
        if ( digits < s || !ascii::is_digit( digits[0] ) ) {
          memmove( s + 1, s, last_digit - s );
          ++last_digit;
          if ( ascii::is_digit( s[0] ) )
            s[0] = '1';
          else
            s[1] = '1';
          if ( has_e ) {                // increment the exponent
            ++dot;
            dot[0] = dot[-1];
            dot[-1] = '.';
            sprintf( e + 1, "%d", atoi( e + 1 ) + 1 );
            --last_digit;
          }
        }
        int const e_len = strlen( e );
        memmove( last_digit, e, e_len );
        last_digit[ e_len ] = 0;
        break;
      }
    } else if ( *digits == '0' ) {
      if ( digits[-1] == '0' && digits[-2] == '0' && digits[-3] == '0' ) {
        if ( ascii::is_digit( digits[1] ) && digits[1] < '5' )
          digits -= 4;
        else if ( digits[-4] == '0' )
          digits -= 5;
        else
          continue;
        while ( *digits == '0' )
          --digits;
        if ( *digits != '.' )
          ++digits;
        else if ( has_e ) {
          digits[1] = '0';
          digits += 2;
        }
        int const e_len = strlen( e );
        memmove( digits, e, e_len );
        digits[ e_len ] = '\0';
        break;
      }
    }
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
    throw std::invalid_argument( "float value = infinity" );
  value_ = f;
}

Decimal::Decimal( double d ) {
  if ( d != d ||
       d ==  std::numeric_limits<double>::infinity() ||
       d == -std::numeric_limits<double>::infinity() )
    throw std::invalid_argument( "double value = infinity" );
  value_ = d;
}

Decimal::Decimal( Double const &d ) {
  if ( !d.isFinite() )
    throw std::invalid_argument( "double value = infinity" );
  value_ = d.getNumber();
}

Decimal::Decimal( Float const &f ) {
  if ( !f.isFinite() )
    throw std::invalid_argument( "float value = infinity" );
  value_ = f.getNumber();
}

template<class C>
Decimal::Decimal( IntegerImpl<C> const &i ) : value_( i.itod() ) {
}

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

template<class C>
Decimal& Decimal::operator=( IntegerImpl<C> const &i ) {
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
    throw std::invalid_argument( "not finite" );
  value_ = d.getNumber();
  return *this;
}

Decimal& Decimal::operator=( Float const &f ) {
  if ( !f.isFinite() )
    throw std::invalid_argument( "not finite" );
  value_ = f.getNumber();
  return *this;
}

////////// arithmetic operators ///////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
# define ZORBA_INSTANTIATE(OP) /* nothing */
#else
# define ZORBA_INSTANTIATE(OP)                                                \
  template Decimal operator OP( Decimal const&, Integer const& );             \
  template Decimal operator OP( Decimal const&, NegativeInteger const& );     \
  template Decimal operator OP( Decimal const&, NonNegativeInteger const& );  \
  template Decimal operator OP( Decimal const&, NonPositiveInteger const& );  \
  template Decimal operator OP( Decimal const&, PositiveInteger const& )
#endif /* ZORBA_WITH_BIG_INTEGER */

#define ZORBA_DECIMAL_OP(OP)                                          \
  template<class C>                                                   \
  Decimal operator OP( Decimal const &d, IntegerImpl<C> const &i ) {  \
    return d.value_ OP i.itod();                                      \
  }                                                                   \
  ZORBA_INSTANTIATE(OP)

ZORBA_DECIMAL_OP(+);
ZORBA_DECIMAL_OP(-);
ZORBA_DECIMAL_OP(*);
ZORBA_DECIMAL_OP(/);
ZORBA_DECIMAL_OP(%);
#undef ZORBA_DECIMAL_OP
#undef ZORBA_INSTANTIATE

////////// relational operators ///////////////////////////////////////////////

#ifdef ZORBA_WITH_BIG_INTEGER
# define ZORBA_INSTANTIATE(OP) /* nothing */
#else
# define ZORBA_INSTANTIATE(OP)                                            \
  template bool operator OP( Decimal const&, Integer const& );            \
  template bool operator OP( Decimal const&, NegativeInteger const& );    \
  template bool operator OP( Decimal const&, NonNegativeInteger const& ); \
  template bool operator OP( Decimal const&, NonPositiveInteger const& ); \
  template bool operator OP( Decimal const&, PositiveInteger const& )
#endif /* ZORBA_WITH_BIG_INTEGER */

#define ZORBA_DECIMAL_OP(OP)                                      \
  template<class C>                                               \
  bool operator OP( Decimal const &d, IntegerImpl<C> const &i ) { \
    return d.value_ OP i.itod();                                  \
  }                                                               \
  ZORBA_INSTANTIATE(OP)

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

template<class C>
Decimal Decimal::round( IntegerImpl<C> const &precision ) const {
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

template<class C>
Decimal Decimal::roundHalfToEven( IntegerImpl<C> const &precision ) const {
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
      std::stringstream ss( bufp );
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
    std::stringstream ss( bufp );
    uint64_t n;
    ss >> n;
    assert( ss.eof() );
    if ( bufp != buf )
      delete[] bufp;
    return static_cast<uint32_t>( n & 0xFFFFFFFF );
  }

  // In all other cases, hash it as double
  value.toFixPtString( bufp, ZORBA_FLOAT_POINT_PRECISION );
  std::stringstream ss( bufp );
  double n;
  ss >> n;
  assert( ss.eof() );
  if ( bufp != buf )
    delete[] bufp;
  return static_cast<uint32_t>( n );
}

zstring Decimal::toString( value_type const &value, int precision ) {
  return toString(value, false, precision);
}

zstring Decimal::toString( value_type const &value, bool minusZero, int precision ) {
  char buf[ 1024 ];

  if ( minusZero )
  {
    buf[0] = '-';
  }

  value.toFixPtString( buf + minusZero, precision );

  //
  // Note that in the canonical representation, the decimal point is required
  // and there must be at least one digit to the right and one digit to the
  // left of the decimal point (which may be 0).
  //
  if ( strchr( buf, '.' ) != 0 ) {
    // remove trailing 0's
    char *last = buf + strlen( buf ) - 1;
    while ( *last == '0' && last > buf )
      *last-- = '\0';

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
