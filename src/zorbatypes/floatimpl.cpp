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

#include <limits>
#include <string>
#include <stdlib.h>

#include "common/common.h"
#include "util/ascii_util.h"

#include "decimal.h"
#include "floatimpl.h"
#include "integer.h"

#include "zorbaserialization/serialize_zorba_types.h"
#include "zorbaserialization/serialize_template_types.h"

///////////////////////////////////////////////////////////////////////////////

namespace zorba {

zstring const& nan_str() {
  static zstring const value( "NaN" );
  return value;
}

zstring const& pos_inf_str() {
  static zstring const value( "INF" );
  return value;
}

zstring const& neg_inf_str() {
  static zstring const value( "-INF" );
  return value;
}

////////////////////////////////////////////////////////////////////////////////

static void count_significant_digits( char digit, int *significant_digits,
                                      int *trailing_zeros ) {
  if ( digit == '0' )
    ++*trailing_zeros;
  else {
    if ( (*significant_digits)++ )
      *significant_digits += *trailing_zeros;
    *trailing_zeros = 0;
  }
}

template<typename FloatType>
void FloatImpl<FloatType>::parse( char const *s ) {
  if ( !*s )
    throw std::invalid_argument( "empty string" );

  int significant_digits = 0;

  s = ascii::trim_start_whitespace( s );

  if ( !parse_etc( s ) ) {
    char const *const first_non_ws = s;
    int trailing_zeros = 0;
    //
    // We need got_digit to know that we're potentially parsing a floating
    // point value comprised of at least one digit -- which means the value
    // can't be one of the special values of INF, -INF, or NaN.
    //
    // We need to know this to prevent aton() from parsing the special values
    // since it (via strtod() that it uses) allows them regardless of case
    // whereas XQuery insists on a specific case.
    //
    bool got_digit = false;

    if ( *s == '+' || *s == '-' )
      ++s;
    if ( ascii::is_digit( *s ) ) {
      got_digit = true;
      do {
        count_significant_digits( *s, &significant_digits, &trailing_zeros );
      } while ( ascii::is_digit( *++s ) );
    }
    if ( *s == '.' && ascii::is_digit( *++s ) ) {
      got_digit = true;
      do {
        count_significant_digits( *s, &significant_digits, &trailing_zeros );
      } while ( ascii::is_digit( *++s ) );
    }
    if ( *s == 'e' || *s == 'E' ) {
      ++s;
      if ( *s == '+' || *s == '-' )
        ++s;
      if ( ascii::is_digit( *s ) ) {
        got_digit = true;
        while ( ascii::is_digit( *++s ) ) ;
      }
    }
    if ( !got_digit )
      throw std::invalid_argument(
        BUILD_STRING( '"', first_non_ws, "\": invalid floating-point literal" )
      );
    value_ = ztd::aton<value_type>( first_non_ws );
  }

  precision_ = significant_digits < max_precision() ?
    significant_digits : max_precision();
}

template<typename FloatType>
bool FloatImpl<FloatType>::parse_etc( char const *s ) {
  if ( strncmp( s, "INF", 3 ) == 0 ) {
    value_ = FloatImpl<FloatType>::pos_inf().value_;
    s += 3;
  } else if ( strncmp( s, "-INF", 4 ) == 0 ) {
    value_ = FloatImpl<FloatType>::neg_inf().value_;
    s += 4;
  } else if ( strncmp( s, "NaN", 3 ) == 0 ) {
    value_ = FloatImpl<FloatType>::nan().value_;
    s += 3;
  } else if ( strncmp( s, "+INF", 4 ) == 0 ) {
    value_ = FloatImpl<FloatType>::pos_inf().value_;
    s += 4;
  } else
    return false;

  return !*ascii::trim_start_whitespace( s );
}

////////// constructors ///////////////////////////////////////////////////////

template<typename FloatType>
FloatImpl<FloatType>::FloatImpl( Decimal const &d ) {
  zstring const temp( d.toString() );
  parse( temp.c_str() );
}

template<typename FloatType>
template<class C>
FloatImpl<FloatType>::FloatImpl( IntegerImpl<C> const &i ) {
  zstring const temp( i.toString() );
  parse( temp.c_str() );
}

template FloatImpl<float>::FloatImpl( Integer const& );
template FloatImpl<float>::FloatImpl( NegativeInteger const& );
template FloatImpl<float>::FloatImpl( NonNegativeInteger const& );
template FloatImpl<float>::FloatImpl( NonPositiveInteger const& );
template FloatImpl<float>::FloatImpl( PositiveInteger const& );

template FloatImpl<double>::FloatImpl( Integer const& );
template FloatImpl<double>::FloatImpl( NegativeInteger const& );
template FloatImpl<double>::FloatImpl( NonNegativeInteger const& );
template FloatImpl<double>::FloatImpl( NonPositiveInteger const& );
template FloatImpl<double>::FloatImpl( PositiveInteger const& );

////////// assignment operators ///////////////////////////////////////////////

template<typename FloatType>
FloatImpl<FloatType>& FloatImpl<FloatType>::operator=( Decimal const &d ) {
  zstring const temp( d.toString() );
  parse( temp.c_str() );
  return *this;
}

template<typename FloatType>
template<class C>
FloatImpl<FloatType>&
FloatImpl<FloatType>::operator=( IntegerImpl<C> const &i ) {
  zstring const temp( i.toString() );
  parse( temp.c_str() );
  return *this;
}

#define INSTANTIATE(F,I) \
  template FloatImpl<F>& FloatImpl<F>::operator=( I const& )

INSTANTIATE(float,Integer);
INSTANTIATE(float,NegativeInteger);
INSTANTIATE(float,NonNegativeInteger);
INSTANTIATE(float,NonPositiveInteger);
INSTANTIATE(float,PositiveInteger);

INSTANTIATE(double,Integer);
INSTANTIATE(double,NegativeInteger);
INSTANTIATE(double,NonNegativeInteger);
INSTANTIATE(double,NonPositiveInteger);
INSTANTIATE(double,PositiveInteger);
#undef INSTANTIATE

////////// math functions /////////////////////////////////////////////////////

template<typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::acos() const {
  if ( *this < numeric_consts<FloatImpl>::neg_one() ||
       *this > numeric_consts<FloatImpl>::one() )
    return nan();
  return FloatImpl<FloatType>(
    isNegZero() ? -std::acos( value_ ): std::acos( value_ )
  );
}

template<typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::asin() const {
  if ( *this < numeric_consts<FloatImpl>::neg_one() ||
       *this > numeric_consts<FloatImpl>::one() )
    return nan();
  return FloatImpl<FloatType>( std::asin( value_ ) );
}

template<typename FloatType>
void FloatImpl<FloatType>::frexp( FloatImpl<FloatType> &out_mantissa,
                                  Integer &out_exponent ) const {
  int expint;
  out_mantissa = FloatImpl( ::frexp( value_, &expint ) );
  out_exponent = Integer( expint );
}

template<>
void FloatImpl<double>::modf( FloatImpl<double> &out_fraction,
                              FloatImpl<double> &out_integer ) const {
  double int_part;
  out_fraction = std::modf( value_, &int_part );
  out_integer = int_part;
}

template<>
void FloatImpl<float>::modf( FloatImpl<float> &out_fraction,
                             FloatImpl<float> &out_integer ) const {
  float int_part;
  out_fraction = ::modff( value_, &int_part );
  out_integer = int_part;
}

template<typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::round() const {
  return round( numeric_consts<xs_integer>::zero() );
}

template<typename FloatType>
FloatImpl<FloatType>
FloatImpl<FloatType>::round( Integer const &precision ) const {
  FloatImpl result;
  if ( isFinite() && !isZero() ) {
    MAPM m(
      Decimal::round2(
        Decimal::value_type( value_ ),
        Decimal::value_type( precision.itod() )
      )
    );
    if ( value_ < 0 && m.sign() == 0 )
      result = neg_zero();
    else {
      char buf[200];
      m.toString( buf, ZORBA_FLOAT_POINT_PRECISION );
      result.parse( buf );
    }
  } else
    result.value_ = value_;

  return result;
}

template<typename FloatType> FloatImpl<FloatType>
FloatImpl<FloatType>::roundHalfToEven( Integer const &precision) const {
  FloatImpl result;
  if ( isFinite() && !isZero() ) {
    MAPM m(
      Decimal::roundHalfToEven2(
        Decimal::value_type( value_ ),
        Decimal::value_type( precision.itod() )
      )
    );
    if ( value_ < 0 && m.sign() == 0 )
      result = neg_zero();
    else {
      char buf[200];
      m.toString( buf, ZORBA_FLOAT_POINT_PRECISION );
      result.parse( buf );
    }
  } else
    result.value_ = value_;
  return result;
}

////////// miscellaneous //////////////////////////////////////////////////////

template<>
bool FloatImpl<double>::isNegZero() const {
  if ( !value_ ) {
    char const *const bytes = reinterpret_cast<char const*>( &value_ );
    // test for little endian and big endian
    return bytes[0] || bytes[7];        // TODO: depends on sizeof(double)
  }
  return false;
}

template<>
bool FloatImpl<float>::isNegZero() const {
  if ( !value_ ) {
    char const *const bytes = reinterpret_cast<char const*>( &value_ );
    // test for little endian and big endian
    return bytes[0] || bytes[3];        // TODO: depends on sizeof(float)
  }
  return false;
}

template<typename FloatType>
FloatImpl<FloatType> const& FloatImpl<FloatType>::nan() {
  static FloatImpl<FloatType> const value( std::sqrt( -1.0 ) );
  return value;
}

template<typename FloatType>
FloatImpl<FloatType> const& FloatImpl<FloatType>::neg_inf() {
  static FloatImpl<FloatType> const value(
    -std::numeric_limits<FloatType>::infinity()
  );
  return value;
}

template<typename FloatType>
FloatImpl<FloatType> const& FloatImpl<FloatType>::neg_zero() {
  static FloatImpl<FloatType> const value( -0.0 );
  return value;
}

template<typename FloatType>
FloatImpl<FloatType> const& FloatImpl<FloatType>::pos_inf() {
  static FloatImpl<FloatType> const value(
    std::numeric_limits<FloatType>::infinity()
  );
  return value;
}

template<typename FloatType>
zstring FloatImpl<FloatType>::toIntegerString() const {
  if ( isNaN() )
    return nan_str();
  if  (isPosInf() )
    return pos_inf_str();
  if ( isNegInf() )
    return neg_inf_str();
  if ( isPosZero() )
    return "0";
  if ( isNegZero() )
    return "-0";

  // TODO: make xs_int
  char buf[174];
  sprintf( buf, "%d", (int)value_ );
  return buf;
}

template<typename FloatType>
zstring FloatImpl<FloatType>::toString( bool no_scientific_format ) const {
  if ( isNaN() )
    return nan_str();
  if ( isPosInf() )
    return pos_inf_str();
  if ( isNegInf() )
    return neg_inf_str();
  if ( isPosZero() )
    return "0";
  if ( isNegZero() )
    return "-0";

  FloatType const absVal = fabs( value_ );
  FloatType const lower = 0.000001f, upper = 1000000.0f;

  if (no_scientific_format || (absVal < upper && absVal >= lower) || absVal == 0)
  {
#if 1
    // This is the "spec" implementation, i.e., it is an exact application of
    // the spec in  http://www.w3.org/TR/xpath-functions/#casting
    MAPM decimal_mapm( value_ );
    decimal_mapm = decimal_mapm.round( precision_ );
    return Decimal::toString(decimal_mapm, isNegZero(), max_precision());
#else
    std::stringstream stream;
    stream.precision(7);
    stream.setf(std::ios::fixed);
    stream << value_;

    zstring result(stream.str());

    // remove non-significant trailing 0's
    long i = result.size() - 1;
    while (str[i] == '0')
      --i;

    if (i >= 0) {
      long j = i;
      while (str[j] != '.')
        --j;

      if (j >= 0)
        if (j == i)
          result.resize(i);
        else
          result.resize(i+1);
    }

    return result;
#endif
  } else {
    char format[15];
    sprintf( format, "%%#1.%dE", static_cast<int>( precision_ ) );

    char buf[174];
    sprintf( buf, format, static_cast<double>( value_ ) );

    char *e = strchr( buf, 'E' );
    char *zeros = e ? e - 1 : buf + strlen( buf ) - 1;

    while ( *zeros == '0' )
      --zeros;

    if ( e ) {
      if ( *zeros == '.' )
        ++zeros;

      zeros[1] = 'E';
      ++e;

      if ( *e == '+' )
        ++e;
      else if ( *e == '-' ) {
        ++zeros;
        zeros[1] = '-';
        ++e;
      }

      while ( *e == '0' )
        ++e;

      memmove( (void*)(zeros + 2), e, strlen( e ) + 1 );
    } else {
      if ( *zeros == '.' )
        --zeros;
      zeros[1] = '\0';
    }

    Decimal::reduce( buf );
    return buf;
  }
}

///////////////////////////////////////////////////////////////////////////////

template class FloatImpl<double>;
template class FloatImpl<float>;

#ifdef WIN32
// exported for testing only
template class ZORBA_DLL_PUBLIC FloatImpl<double>;
template class ZORBA_DLL_PUBLIC FloatImpl<float>;
#endif /* WIN32 */

} // namespace zorba
/* vim:set et sw=2 ts=2: */
