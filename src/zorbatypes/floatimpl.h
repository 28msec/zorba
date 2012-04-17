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
#ifndef ZORBA_FLOATIMPL_H
#define ZORBA_FLOATIMPL_H

#include <cmath>
#include <limits>

#include <zorba/config.h>

#include "common/common.h"
#include "util/stl_util.h"

#include "schema_types.h"
#include "zorbatypes_decl.h"

#ifdef ZORBA_WITH_BIG_INTEGER
# define TEMPLATE_DECL(I) /* nothing */
# define INTEGER_IMPL(I)  IntegerImpl
#else
# define TEMPLATE_DECL(I) template<typename I>
# define INTEGER_IMPL(I)  IntegerImpl<I>
#endif /* ZORBA_WITH_BIG_INTEGER */

namespace zorba {

template<typename FloatType>
class FloatImpl;

namespace serialization {
  template<typename FloatType>
  void operator&( Archiver&, FloatImpl<FloatType>& );
}

///////////////////////////////////////////////////////////////////////////////

template<typename FloatType>
class FloatImpl {
public:
  typedef FloatType value_type;

  ////////// constructors /////////////////////////////////////////////////////

  explicit FloatImpl( char );
  explicit FloatImpl( signed char c );
  explicit FloatImpl( short n );
  explicit FloatImpl( int n = 0 );
  explicit FloatImpl( long n );
  explicit FloatImpl( long long n );
  explicit FloatImpl( unsigned char c );
  explicit FloatImpl( unsigned short n );
  explicit FloatImpl( unsigned int n );
  explicit FloatImpl( unsigned long n );
  explicit FloatImpl( unsigned long long n );
  explicit FloatImpl( float n );
  explicit FloatImpl( double n );
  explicit FloatImpl( Decimal const &d );

  TEMPLATE_DECL(IntType)
  explicit FloatImpl( INTEGER_IMPL(IntType) const &i );

  /**
   * Constructs a %FloatImpl from a C string.
   *
   * @param s The null-terminated C string to parse.  Leading and trailing
   * whitespace is ignored.
   * @throw std::invalid_argument if \a s does not contain a valid floating
   * point number.
   * @throw std::range_error if \a s contains a number that either underflows
   * or overflows the smallest or largest representable floating point number.
   */
  explicit FloatImpl( char const *s );

  /**
   * Constructs from another %FloatImpl even if its \c FloatType is different.
   * (This subsumes the conventional copy constructor.)
   *
   * @tparam FloatType2 the floating-point type of \a f.
   * @param f The %FloatImpl to copy from.
   */
  template<typename FloatType2>
  FloatImpl( FloatImpl<FloatType2> const &f );

  ////////// assignment operators /////////////////////////////////////////////

  /**
   * Assign from a %FloatImpl even if its \c FloatType is different.
   * (This subsumes the conventional assignment operator.)
   *
   * @tparam FloatType2 the floating-point type of \a f.
   * @param f The %FloatImpl to assign from.
   * @return Returns \c *this.
   */
  template<typename FloatType2>
  FloatImpl& operator=( FloatImpl<FloatType2> const &f );

  /**
   * For every built-in arithmetic type A, assign to this %FloatImpl.
   *
   * @tparam A The built-in arithmetic type.
   * @param n The arithmetic value to assign.
   * @return Returns \c *this.
   */
  template<typename A>
  typename std::enable_if<ZORBA_TR1_NS::is_arithmetic<A>::value,
                          FloatImpl&>::type
  operator=( A n );

  FloatImpl& operator=( char const *s );
  FloatImpl& operator=( Decimal const &d );

  TEMPLATE_DECL(I)
  FloatImpl& operator=( INTEGER_IMPL(I) const &i );

  ////////// arithmetic operators /////////////////////////////////////////////

#define ZORBA_FLOAT_OP(OP)                                        \
  template<typename A>                                            \
  typename std::enable_if<ZORBA_TR1_NS::is_arithmetic<A>::value,  \
                          FloatImpl&>::type                       \
  operator OP( A n )

  ZORBA_FLOAT_OP(+=);
  ZORBA_FLOAT_OP(-=);
  ZORBA_FLOAT_OP(*=);
  ZORBA_FLOAT_OP(/=);
  ZORBA_FLOAT_OP(%=);
#undef ZORBA_FLOAT_OP

#define ZORBA_FLOAT_OP(OP)                                \
  template<typename FloatType2>                           \
  FloatImpl& operator OP( FloatImpl<FloatType2> const &f )

  ZORBA_FLOAT_OP(+=);
  ZORBA_FLOAT_OP(-=);
  ZORBA_FLOAT_OP(*=);
  ZORBA_FLOAT_OP(/=);
  ZORBA_FLOAT_OP(%=);
#undef ZORBA_FLOAT_OP

  FloatImpl operator-() const;

  ////////// math functions ///////////////////////////////////////////////////

  FloatImpl acos() const;
  FloatImpl acosh() const;
  FloatImpl asin() const;
  FloatImpl asinh() const;
  FloatImpl atan() const;
  FloatImpl atan2( double x ) const;
  FloatImpl atan2( FloatImpl const &x ) const;
  FloatImpl atanh() const;
  FloatImpl ceil() const;
  FloatImpl cos() const;
  FloatImpl cosh() const;
  FloatImpl exp() const;
  FloatImpl exp10() const;
  FloatImpl floor() const;
  FloatImpl fmod( double d ) const;
  FloatImpl fmod( FloatImpl const &f ) const;
  FloatImpl log() const;
  FloatImpl log10() const;
  FloatImpl pow( int p ) const;
  FloatImpl pow( FloatImpl const &p ) const;
  FloatImpl round( Integer const &precision ) const;
  FloatImpl round() const;
  FloatImpl roundHalfToEven( Integer const &precision ) const;
  FloatImpl sin() const;
  FloatImpl sinh() const;
  FloatImpl sqrt() const;
  FloatImpl tan() const;
  FloatImpl tanh() const;

  void frexp( FloatImpl &out_mantissa, Integer &out_exponent ) const;

  void modf( FloatImpl &out_fraction, FloatImpl &out_integer ) const;

  ////////// miscellaneous ////////////////////////////////////////////////////

  template<typename FloatType2>
  int compare( FloatImpl<FloatType2> const &f ) const;

  uint32_t hash() const;

  bool isNaN() const;
  bool isFinite() const;
  bool isPosInf() const;
  bool isNegInf() const;
  bool isNeg() const;
  bool isPos() const;
  bool isZero() const;
  bool isPosZero() const;
  bool isNegZero() const;
  bool isInteger() const;

  static FloatImpl const& zero();
  static FloatImpl const& neg_zero();
  static FloatImpl const& one();
  static FloatImpl const& neg_one();
  static FloatImpl const& nan();
  static FloatImpl const& pos_inf();
  static FloatImpl const& neg_inf();

  value_type getNumber() const {
    return value_;
  }

  zstring toIntegerString() const;

  zstring toString( bool no_scientific_mode = false ) const;

  /////////////////////////////////////////////////////////////////////////////

  template<typename FloatType2>
  friend void serialization::operator&( serialization::Archiver&,
                                        FloatImpl<FloatType2>& );

private:
  typedef unsigned short precision_type;

  value_type     value_;
  precision_type precision_;

  FloatImpl( value_type v, precision_type p );

  static precision_type max_precision();

  void parse( char const* );
  bool parse_etc( char const* );

  TEMPLATE_DECL(I) friend class IntegerImpl;
  friend class Decimal;

  friend class FloatImpl<float>;
  friend class FloatImpl<double>;
};

typedef FloatImpl<float> Float;
typedef FloatImpl<double> Double;

///////////////////////////////////////////////////////////////////////////////

template<>
inline FloatImpl<float>::precision_type FloatImpl<float>::max_precision() {
  return 7;
}

template<>
inline FloatImpl<double>::precision_type FloatImpl<double>::max_precision() {
  return 16;
}

////////// constructors ///////////////////////////////////////////////////////

template<typename F>
inline FloatImpl<F>::FloatImpl( char c ) :
  value_( static_cast<F>( c ) ), precision_( max_precision() )
{
}

template<typename F>
inline FloatImpl<F>::FloatImpl( signed char c ) :
  value_( static_cast<F>( c ) ), precision_( max_precision() )
{
}

template<typename F>
inline FloatImpl<F>::FloatImpl( short n ) :
  value_( static_cast<F>( n ) ), precision_( max_precision() )
{
}

template<typename F>
inline FloatImpl<F>::FloatImpl( int n ) :
  value_( static_cast<F>( n ) ), precision_( max_precision() )
{
}

template<typename F>
inline FloatImpl<F>::FloatImpl( long n ) :
  value_( static_cast<F>( n ) ), precision_( max_precision() )
{
}

template<typename F>
inline FloatImpl<F>::FloatImpl( long long n ) :
  value_( static_cast<F>( n ) ), precision_( max_precision() )
{
}

template<typename F>
inline FloatImpl<F>::FloatImpl( unsigned char c ) :
  value_( static_cast<F>( c ) ), precision_( max_precision() )
{
}

template<typename F>
inline FloatImpl<F>::FloatImpl( unsigned short n ) :
  value_( static_cast<F>( n ) ), precision_( max_precision() )
{
}

template<typename F>
inline FloatImpl<F>::FloatImpl( unsigned int n ) :
  value_( static_cast<F>( n ) ), precision_( max_precision() )
{
}

template<typename F>
inline FloatImpl<F>::FloatImpl( unsigned long n ) :
  value_( static_cast<F>( n ) ), precision_( max_precision() )
{
}

template<typename F>
inline FloatImpl<F>::FloatImpl( unsigned long long n ) :
  value_( static_cast<F>( n ) ), precision_( max_precision() )
{
}

template<typename F>
inline FloatImpl<F>::FloatImpl( float n ) :
  value_( static_cast<F>( n ) ), precision_( max_precision() )
{
}

template<typename F>
inline FloatImpl<F>::FloatImpl( double n ) :
  value_( static_cast<F>( n ) ), precision_( max_precision() )
{
}

template<typename F>
inline FloatImpl<F>::FloatImpl( char const *s ) {
  parse( s );
}

template<typename F> template<typename G>
inline FloatImpl<F>::FloatImpl( FloatImpl<G> const &f ) :
  value_( static_cast<F>( f.value_ ) ), precision_( max_precision() )
{
}

template<typename F>
inline FloatImpl<F>::FloatImpl( value_type v, precision_type p ) :
  value_( v ), precision_( p )
{
}

////////// assignment operators ///////////////////////////////////////////////

template<typename F> template<typename G>
inline FloatImpl<F>& FloatImpl<F>::operator=( FloatImpl<G> const &f ) {
  value_ = static_cast<F>( f.value_ );
  precision_ = max_precision();
  return *this;
}

template<typename F> template<typename A> inline
typename std::enable_if<ZORBA_TR1_NS::is_arithmetic<A>::value,
                        FloatImpl<F>&>::type
FloatImpl<F>::operator=( A n ) {
  value_ = static_cast<F>( n );
  precision_ = max_precision();
  return *this;
}

template<typename F>
inline FloatImpl<F>& FloatImpl<F>::operator=( char const *s ) {
  parse( s );
  return *this;
}

////////// arithmetic operators ///////////////////////////////////////////////

#define ZORBA_FLOAT_OP(OP)                                        \
  template<typename F,typename A> inline                          \
  typename std::enable_if<ZORBA_TR1_NS::is_arithmetic<A>::value,  \
                          FloatImpl<F> >::type                    \
  operator OP( FloatImpl<F> const &f, A n ) {                     \
    return FloatImpl<F>( f.getNumber() OP static_cast<F>( n ) );  \
  }                                                               \
                                                                  \
  template<typename F,typename A> inline                          \
  typename std::enable_if<ZORBA_TR1_NS::is_arithmetic<A>::value,  \
                          FloatImpl<F> >::type                    \
  operator OP( A n, FloatImpl<F> const &f ) {                     \
    return FloatImpl<F>( static_cast<F>( n ) OP f.getNumber() );  \
  }

ZORBA_FLOAT_OP(+)
ZORBA_FLOAT_OP(-)
ZORBA_FLOAT_OP(*)
ZORBA_FLOAT_OP(/)
#undef ZORBA_FLOAT_OP

template<typename F,typename A> inline
typename std::enable_if<ZORBA_TR1_NS::is_arithmetic<A>::value,
                        FloatImpl<F> >::type
operator%( FloatImpl<F> const &f, A n ) {
  return FloatImpl<F>( std::fmod( f.getNumber(), static_cast<F>( n ) ) );
}

template<typename F,typename A> inline
typename std::enable_if<ZORBA_TR1_NS::is_arithmetic<A>::value,
                        FloatImpl<F> >::type
operator%( A n, FloatImpl<F> const &f ) {
  return FloatImpl<F>( std::fmod( static_cast<F>( n ), f.getNumber() ) );
}

#define ZORBA_FLOAT_OP(OP)                                                    \
  template<typename F> inline                                                 \
  FloatImpl<F> operator OP( FloatImpl<F> const &f, FloatImpl<F> const &g ) {  \
    return FloatImpl<F>( f.getNumber() OP g.getNumber() );                    \
  }

ZORBA_FLOAT_OP(+)
ZORBA_FLOAT_OP(-)
ZORBA_FLOAT_OP(*)
ZORBA_FLOAT_OP(/)
#undef ZORBA_FLOAT_OP

template<typename F>
inline FloatImpl<F> operator%( FloatImpl<F> const &f, FloatImpl<F> const &g ) {
  return FloatImpl<F>( std::fmod( f.getNumber(), g.getNumber() ) );
}

#define ZORBA_FLOAT_OP(OP)                                        \
  template<typename F> template<typename A> inline                \
  typename std::enable_if<ZORBA_TR1_NS::is_arithmetic<A>::value,  \
                          FloatImpl<F>&>::type                    \
  FloatImpl<F>::operator OP( A n ) {                              \
    value_ OP static_cast<F>( n );                                \
    return *this;                                                 \
  }

ZORBA_FLOAT_OP(+=)
ZORBA_FLOAT_OP(-=)
ZORBA_FLOAT_OP(*=)
ZORBA_FLOAT_OP(/=)
ZORBA_FLOAT_OP(%=)
#undef ZORBA_FLOAT_OP

#define ZORBA_FLOAT_OP(OP)                                                  \
  template<typename F> template<typename G>                                 \
  inline FloatImpl<F>& FloatImpl<F>::operator OP( FloatImpl<G> const &f ) { \
    value_ OP static_cast<F>( f.value_ );                                   \
    return *this;                                                           \
  }

ZORBA_FLOAT_OP(+=)
ZORBA_FLOAT_OP(-=)
ZORBA_FLOAT_OP(*=)
ZORBA_FLOAT_OP(/=)
#undef ZORBA_FLOAT_OP

template<typename F> template<typename G>
inline FloatImpl<F>& FloatImpl<F>::operator%=( FloatImpl<G> const &f ) {
  value_ = std::fmod( value_, static_cast<F>( f.value_ ) );
  return *this;
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::operator-() const {
  return FloatImpl<F>( -value_, precision_ );
}

#define ZORBA_FLOAT_OP(OP) \
  inline Double operator OP( Double const &d, Float const &f ) {  \
    return Double( d.getNumber() OP f.getNumber() );              \
  }                                                               \
  inline Double operator OP( Float const &f, Double const &d ) {  \
    return Double( f.getNumber() OP d.getNumber() );              \
  }

ZORBA_FLOAT_OP(+)
ZORBA_FLOAT_OP(-)
ZORBA_FLOAT_OP(*)
ZORBA_FLOAT_OP(/)
#undef ZORBA_FLOAT_OP

inline Double operator%( Double const &d, Float const &f ) {
  return Double(
    std::fmod( d.getNumber(), static_cast<double>( f.getNumber() ) )
  );
}

inline Double operator%( Float const &f, Double const &d ) {
  return Double(
    std::fmod( static_cast<double>( f.getNumber() ), d.getNumber() )
  );
}

////////// relational operators ///////////////////////////////////////////////

template<typename F,typename G>
inline bool operator==( FloatImpl<F> const &f, FloatImpl<G> const &g ) {
  return f.getNumber() == g.getNumber();
}

template<typename F,typename G>
inline bool operator!=( FloatImpl<F> const &f, FloatImpl<G> const &g ) {
  return f.getNumber() != g.getNumber();
}

template<typename F,typename G>
inline bool operator<( FloatImpl<F> const &f, FloatImpl<G> const &g ) {
  return f.getNumber() < g.getNumber();
}

template<typename F,typename G>
inline bool operator<=( FloatImpl<F> const &f, FloatImpl<G> const &g ) {
  return !f.isNaN() && !g.isNaN() && f.getNumber() <= g.getNumber();
}

template<typename F,typename G>
inline bool operator>( FloatImpl<F> const &f, FloatImpl<G> const &g ) {
  return f.getNumber() > g.getNumber();
}

template<typename F,typename G>
inline bool operator>=( FloatImpl<F> const &f, FloatImpl<G> const &g ) {
  return !f.isNaN() && !g.isNaN() && f.getNumber() >= g.getNumber();
}

template<typename F>
inline bool operator==( FloatImpl<F> const &f, double d ) {
  return f.getNumber() == d;
}

template<typename F>
inline bool operator==( double d, FloatImpl<F> const &f ) {
  return d = f.getNumber();
}

template<typename F>
inline bool operator!=( FloatImpl<F> const &f, double d ) {
  return f.getNumber() != d;
}

template<typename F>
inline bool operator!=( double d, FloatImpl<F> const &f ) {
  return f.getNumber() != d;
}

template<typename F>
inline bool operator<( FloatImpl<F> const &f, double d ) {
  return f.getNumber() < d;
}

template<typename F>
inline bool operator<( double d, FloatImpl<F> const &f ) {
  return d < f.getNumber();
}

template<typename F>
inline bool operator<=( FloatImpl<F> const &f, double d ) {
  return !f.isNaN() && d == d && f.getNumber() <= d;
}

template<typename F>
inline bool operator<=( double d, FloatImpl<F> const &f ) {
  return d == d && !f.isNaN() && d <= f.getNumber();
}

template<typename F>
inline bool operator>( FloatImpl<F> const &f, double d ) {
  return f.getNumber() > d;
}

template<typename F>
inline bool operator>( double d, FloatImpl<F> const &f ) {
  return d > f.getNumber();
}

template<typename F>
inline bool operator>=( FloatImpl<F> const &f, double d ) {
  return !f.isNaN() && d == d && f.getNumber() >= d;
}

template<typename F>
inline bool operator>=( double d, FloatImpl<F> const &f ) {
  return d == d && !f.isNaN() && d >= f.getNumber();
}

////////// math functions /////////////////////////////////////////////////////

template<typename F>
inline FloatImpl<F> FloatImpl<F>::acosh() const {
  // formula from www.mathworks.com
  return FloatImpl<F>(
    std::log( value_ + std::sqrt( value_ * value_ - 1 ) )
  );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::asinh() const {
  // formula from www.mathworks.com
  return FloatImpl<F>(
    std::log( value_ + std::sqrt( value_ * value_ + 1 ) )
  );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::atan() const {
  return FloatImpl<F>( std::atan( value_ ) );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::atanh() const {
  // formula from www.mathworks.com
  return FloatImpl<F>( 0.5 * std::log( (1 + value_) / (1 - value_) ) );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::atan2( double x ) const {
  return FloatImpl<F>( std::atan2( value_, static_cast<F>( x ) ) );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::atan2( FloatImpl<F> const &x ) const {
  return FloatImpl<F>( atan2( x.value_ ) );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::ceil() const {
  return FloatImpl<F>( std::ceil( value_ ) );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::cos() const {
  return FloatImpl<F>( std::cos( value_ ) );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::cosh() const {
  return FloatImpl<F>( std::cosh( value_ ) );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::exp() const {
  return FloatImpl<F>( std::exp( value_ ) );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::exp10() const {
  return FloatImpl<F>( std::pow( 10, value_ ) );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::floor() const {
  return FloatImpl<F>( std::floor( value_ ) );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::fmod( double d ) const {
  return FloatImpl<F>( std::fmod( value_, static_cast<F>( d ) ) );
}

template<typename F>
inline FloatImpl<F>
FloatImpl<F>::fmod( FloatImpl<F> const &f ) const {
  return FloatImpl<F>( fmod( f.value_ ) );
}

template<typename F>
FloatImpl<F> FloatImpl<F>::log() const {
  return value_ < 0 ? nan() : FloatImpl<F>( std::log( value_ ) );
}

template<typename F>
FloatImpl<F> FloatImpl<F>::log10() const {
  return value_ < 0 ? nan() : FloatImpl<F>( std::log10( value_ ) );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::pow( int p ) const {
  return FloatImpl<F>( std::pow( value_, p ) );
}

template<typename F>
inline FloatImpl<F>
FloatImpl<F>::pow( FloatImpl<F> const &p ) const {
  return FloatImpl<F>(
    p.isNaN() ? value_ : std::pow( value_, p.value_ )
  );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::sin() const {
  return FloatImpl<F>( std::sin( value_ ) );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::sinh() const {
  return FloatImpl<F>( std::sinh( value_ ) );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::sqrt() const {
  return value_ < 0 ? nan() : FloatImpl( std::sqrt( value_ ) );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::tan() const {
  return FloatImpl<F>( std::tan( value_ ) );
}

template<typename F>
inline FloatImpl<F> FloatImpl<F>::tanh() const {
  return FloatImpl<F>( std::tanh( value_ ) );
}

////////// miscellaneous //////////////////////////////////////////////////////

template<typename F> template<typename G>
inline int FloatImpl<F>::compare( FloatImpl<G> const &f ) const {
  return value_ < f.value_ ? -1 : value_ > f.value_ ? 1 : 0;
}

template<typename F>
inline uint32_t FloatImpl<F>::hash() const {
  return static_cast<uint32_t>( value_ );
}

template<typename F>
inline bool FloatImpl<F>::isNeg() const {
  return value_ < 0;
}

template<typename F>
inline bool FloatImpl<F>::isPos() const {
  return value_ > 0;
}

template<typename F>
inline bool FloatImpl<F>::isPosZero() const {
  return value_ == 0 && !isNegZero();
}

template<typename F>
inline bool FloatImpl<F>::isNaN() const {
  return value_ != value_;
}

template<typename F>
inline bool FloatImpl<F>::isNegInf() const {
 return value_ == -std::numeric_limits<F>::infinity();
}

template<typename F>
inline bool FloatImpl<F>::isPosInf() const {
  return value_ == std::numeric_limits<F>::infinity();
}

template<typename F>
inline bool FloatImpl<F>::isFinite() const {
  return !isNaN() && !isPosInf() && !isNegInf();
}

template<typename F>
inline bool FloatImpl<F>::isInteger() const {
  return isFinite() && ::floor( value_ ) == value_;
}

template <typename F>
inline bool FloatImpl<F>::isZero() const {
  return value_ == 0;
}

template<typename F>
inline std::ostream& operator<<( std::ostream &os, FloatImpl<F> const &f ) {
  return os << f.toString();
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#undef TEMPLATE_DECL
#undef INTEGER_IMPL

#endif // ZORBA_FLOATIMPL_H
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
