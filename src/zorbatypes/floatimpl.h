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
#include "zorbaserialization/class_serializer.h"

#include "schema_types.h"
#include "zorbatypes_decl.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

// exported for testing only
template<typename FloatType>
class FloatImpl : public serialization::SerializeBaseClass 
{
public:
  typedef FloatType value_type;

  ////////// constructors /////////////////////////////////////////////////////

  FloatImpl( char );
  FloatImpl( signed char c );
  FloatImpl( short n );
  FloatImpl( int n = 0 );
  FloatImpl( long n );
  FloatImpl( long long n );
  FloatImpl( unsigned char c );
  FloatImpl( unsigned short n );
  FloatImpl( unsigned int n );
  FloatImpl( unsigned long n );
  FloatImpl( unsigned long long n );
  FloatImpl( float n );
  FloatImpl( double n );
  FloatImpl( Decimal const &d );
  FloatImpl( Integer const &i );

  FloatImpl( char const *s );

  template<typename FloatType2>
  FloatImpl( FloatImpl<FloatType2> const &f );

  ////////// assignment operators /////////////////////////////////////////////

  FloatImpl& operator=( char c );
  FloatImpl& operator=( signed char c );
  FloatImpl& operator=( int n );
  FloatImpl& operator=( short n );
  FloatImpl& operator=( long n );
  FloatImpl& operator=( long long n );
  FloatImpl& operator=( unsigned char c );
  FloatImpl& operator=( unsigned int n );
  FloatImpl& operator=( unsigned short n );
  FloatImpl& operator=( unsigned long n );
  FloatImpl& operator=( unsigned long long n );
  FloatImpl& operator=( float n );
  FloatImpl& operator=( double n );

  template<typename FloatType2>
  FloatImpl& operator=( FloatImpl<FloatType2> const &f );

  ////////// arithmetic operators /////////////////////////////////////////////

  template<typename FloatType2>
  FloatImpl& operator+=( FloatImpl<FloatType2> const &f );

  template<typename FloatType2>
  FloatImpl& operator-=( FloatImpl<FloatType2> const &f );

  template<typename FloatType2>
  FloatImpl& operator*=( FloatImpl<FloatType2> const &f );

  template<typename FloatType2>
  FloatImpl& operator/=( FloatImpl<FloatType2> const &f );

  template<typename FloatType2>
  FloatImpl& operator%=( FloatImpl<FloatType2> const &f );

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

  SERIALIZABLE_TEMPLATE_CLASS(FloatImpl)
  SERIALIZABLE_CLASS_CONSTRUCTOR(FloatImpl)
  void serialize( serialization::Archiver& );

private:
  typedef unsigned short precision_type;

  value_type     value_;
  precision_type precision_;

  FloatImpl( value_type v, precision_type p );

  static precision_type max_precision();

  void parse( char const* );
  bool parse_etc( char const* );

  friend class Integer;
  friend class Decimal;

  friend class FloatImpl<float>;
  friend class FloatImpl<double>;
};

typedef ZORBA_DLL_PUBLIC FloatImpl<float> Float;
typedef ZORBA_DLL_PUBLIC FloatImpl<double> Double;

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

template<typename FloatType> inline
FloatImpl<FloatType>::FloatImpl( char c ) :
  value_( static_cast<value_type>( c ) ), precision_( max_precision() )
{
}

template<typename FloatType> inline
FloatImpl<FloatType>::FloatImpl( signed char c ) :
  value_( static_cast<value_type>( c ) ), precision_( max_precision() )
{
}

template<typename FloatType> inline
FloatImpl<FloatType>::FloatImpl( short n ) :
  value_( static_cast<value_type>( n ) ), precision_( max_precision() )
{
}

template<typename FloatType> inline
FloatImpl<FloatType>::FloatImpl( int n ) :
  value_( static_cast<value_type>( n ) ), precision_( max_precision() )
{
}

template<typename FloatType> inline
FloatImpl<FloatType>::FloatImpl( long n ) :
  value_( static_cast<value_type>( n ) ), precision_( max_precision() )
{
}

template<typename FloatType> inline
FloatImpl<FloatType>::FloatImpl( long long n ) :
  value_( static_cast<value_type>( n ) ), precision_( max_precision() )
{
}

template<typename FloatType> inline
FloatImpl<FloatType>::FloatImpl( unsigned char c ) :
  value_( static_cast<value_type>( c ) ), precision_( max_precision() )
{
}

template<typename FloatType> inline
FloatImpl<FloatType>::FloatImpl( unsigned short n ) :
  value_( static_cast<value_type>( n ) ), precision_( max_precision() )
{
}

template<typename FloatType> inline
FloatImpl<FloatType>::FloatImpl( unsigned int n ) :
  value_( static_cast<value_type>( n ) ), precision_( max_precision() )
{
}

template<typename FloatType> inline
FloatImpl<FloatType>::FloatImpl( unsigned long n ) :
  value_( static_cast<value_type>( n ) ), precision_( max_precision() )
{
}

template<typename FloatType> inline
FloatImpl<FloatType>::FloatImpl( unsigned long long n ) :
  value_( static_cast<value_type>( n ) ), precision_( max_precision() )
{
}

template<typename FloatType> inline
FloatImpl<FloatType>::FloatImpl( float n ) :
  value_( static_cast<value_type>( n ) ), precision_( max_precision() )
{
}

template<typename FloatType> inline
FloatImpl<FloatType>::FloatImpl( double n ) :
  value_( static_cast<value_type>( n ) ), precision_( max_precision() )
{
}

template<typename FloatType> inline
FloatImpl<FloatType>::FloatImpl( char const *s ) {
  parse( s );
}

template<typename FloatType>
template<typename FloatType2>
inline FloatImpl<FloatType>::FloatImpl( FloatImpl<FloatType2> const &f ) :
  serialization::SerializeBaseClass(),
  value_( f.value_ ),
  precision_( max_precision() )
{
}

template<typename FloatType>
inline FloatImpl<FloatType>::FloatImpl( value_type v, precision_type p ) :
  value_( v ),
  precision_( p )
{
}

////////// assignment operators ///////////////////////////////////////////////

template<typename FloatType> inline FloatImpl<FloatType>&
FloatImpl<FloatType>::operator=( char c ) {
  value_ = static_cast<value_type>( c );
  precision_ = max_precision(); // TODO: should this be here?
  return *this;
}

template<typename FloatType> inline FloatImpl<FloatType>&
FloatImpl<FloatType>::operator=( signed char c ) {
  value_ = static_cast<value_type>( c );
  precision_ = max_precision();
  return *this;
}

template<typename FloatType> inline FloatImpl<FloatType>&
FloatImpl<FloatType>::operator=( int n ) {
  value_ = static_cast<value_type>( n );
  precision_ = max_precision();
  return *this;
}

template<typename FloatType> inline FloatImpl<FloatType>&
FloatImpl<FloatType>::operator=( short n ) {
  value_ = static_cast<value_type>( n );
  precision_ = max_precision();
  return *this;
}

template<typename FloatType> inline FloatImpl<FloatType>&
FloatImpl<FloatType>::operator=( long n ) {
  value_ = static_cast<value_type>( n );
  precision_ = max_precision();
  return *this;
}

template<typename FloatType> inline FloatImpl<FloatType>&
FloatImpl<FloatType>::operator=( long long n ) {
  value_ = static_cast<value_type>( n );
  precision_ = max_precision();
  return *this;
}

template<typename FloatType> inline FloatImpl<FloatType>&
FloatImpl<FloatType>::operator=( unsigned char c ) {
  value_ = static_cast<value_type>( c );
  precision_ = max_precision();
  return *this;
}

template<typename FloatType> inline FloatImpl<FloatType>&
FloatImpl<FloatType>::operator=( unsigned int n ) {
  value_ = static_cast<value_type>( n );
  precision_ = max_precision();
  return *this;
}

template<typename FloatType> inline FloatImpl<FloatType>&
FloatImpl<FloatType>::operator=( unsigned short n ) {
  value_ = static_cast<value_type>( n );
  precision_ = max_precision();
  return *this;
}

template<typename FloatType> inline FloatImpl<FloatType>&
FloatImpl<FloatType>::operator=( unsigned long n ) {
  value_ = static_cast<value_type>( n );
  precision_ = max_precision();
  return *this;
}

template<typename FloatType> inline FloatImpl<FloatType>&
FloatImpl<FloatType>::operator=( unsigned long long n ) {
  value_ = static_cast<value_type>( n );
  precision_ = max_precision();
  return *this;
}

template<typename FloatType> inline FloatImpl<FloatType>&
FloatImpl<FloatType>::operator=( float n ) {
  value_ = static_cast<value_type>( n );
  precision_ = max_precision();
  return *this;
}

template<typename FloatType> inline FloatImpl<FloatType>&
FloatImpl<FloatType>::operator=( double n ) {
  value_ = static_cast<value_type>( n );
  precision_ = max_precision();
  return *this;
}

template<typename FloatType>
template<typename FloatType2>
inline FloatImpl<FloatType>&
FloatImpl<FloatType>::operator=( FloatImpl<FloatType2> const &f ) {
  value_ = f.value_;
  precision_ = max_precision();
  return *this;
}

////////// arithmetic operators ///////////////////////////////////////////////

template<typename T> inline
FloatImpl<T> operator+( FloatImpl<T> const &f, FloatImpl<T> const &g ) {
  return FloatImpl<T>( f.getNumber() + g.getNumber() );
}

template<typename T> inline
FloatImpl<T> operator-( FloatImpl<T> const &f, FloatImpl<T> const &g ) {
  return FloatImpl<T>( f.getNumber() - g.getNumber() );
}

template<typename T> inline
FloatImpl<T> operator*( FloatImpl<T> const &f, FloatImpl<T> const &g ) {
  return FloatImpl<T>( f.getNumber() * g.getNumber() );
}

template<typename T> inline
FloatImpl<T> operator/( FloatImpl<T> const &f, FloatImpl<T> const &g ) {
  return FloatImpl<T>( f.getNumber() / g.getNumber() );
}

template<typename T> inline
FloatImpl<T> operator%( FloatImpl<T> const &f, FloatImpl<T> const &g ) {
  return FloatImpl<T>( std::fmod( f.getNumber(), g.getNumber() ) );
}

template<typename T>
template<typename U>
inline FloatImpl<T>& FloatImpl<T>::operator+=( FloatImpl<U> const &f ) {
  value_ += f.value_;
  return *this;
}

template<typename T>
template<typename U>
inline FloatImpl<T>& FloatImpl<T>::operator-=( FloatImpl<U> const &f ) {
  value_ -= f.value_;
  return *this;
}

template<typename T>
template<typename U>
inline FloatImpl<T>& FloatImpl<T>::operator*=( FloatImpl<U> const &f ) {
  value_ *= f.value_;
  return *this;
}

template<typename T>
template<typename U>
inline FloatImpl<T>& FloatImpl<T>::operator/=( FloatImpl<U> const &f ) {
  value_ /= f.value_;
  return *this;
}

template<typename T>
template<typename U>
inline FloatImpl<T>& FloatImpl<T>::operator%=( FloatImpl<U> const &f ) {
  value_ %= f.value_;
  return *this;
}

template<typename FloatType>
inline FloatImpl<FloatType> FloatImpl<FloatType>::operator-() const {
  return FloatImpl<FloatType>( -value_, precision_ );
}

inline Double operator+( Double const &d, Float const &f ) {
  return d.getNumber() + f.getNumber();
}

inline Double operator+( Float const &f, Double const &d ) {
  return f.getNumber() + d.getNumber();
}

inline Double operator-( Double const &d, Float const &f ) {
  return d.getNumber() - f.getNumber();
}

inline Double operator-( Float const &f, Double const &d ) {
  return f.getNumber() - d.getNumber();
}

inline Double operator*( Double const &d, Float const &f ) {
  return d.getNumber() * f.getNumber();
}

inline Double operator*( Float const &f, Double const &d ) {
  return f.getNumber() * d.getNumber();
}

inline Double operator/( Double const &d, Float const &f ) {
  return d.getNumber() / f.getNumber();
}

inline Double operator/( Float const &f, Double const &d ) {
  return f.getNumber() / d.getNumber();
}

inline Double operator%( Double const &d, Float const &f ) {
  return std::fmod( d.getNumber(), static_cast<double>( f.getNumber() ) );
}

inline Double operator%( Float const &f, Double const &d ) {
  return std::fmod( static_cast<double>( f.getNumber() ), d.getNumber() );
}

////////// relational operators ///////////////////////////////////////////////

template<typename T,typename U>
inline bool operator==( FloatImpl<T> const &f, FloatImpl<U> const &g ) {
  return f.getNumber() == g.getNumber();
}

template<typename T,typename U>
inline bool operator!=( FloatImpl<T> const &f, FloatImpl<U> const &g ) {
  return f.getNumber() != g.getNumber();
}

template<typename T,typename U>
inline bool operator<( FloatImpl<T> const &f, FloatImpl<U> const &g ) {
  return f.getNumber() < g.getNumber();
}

template<typename T,typename U>
inline bool operator<=( FloatImpl<T> const &f, FloatImpl<U> const &g ) {
  return !f.isNaN() && !g.isNaN() && f.getNumber() <= g.getNumber();
}

template<typename T,typename U>
inline bool operator>( FloatImpl<T> const &f, FloatImpl<U> const &g ) {
  return f.getNumber() > g.getNumber();
}

template<typename T,typename U>
inline bool operator>=( FloatImpl<T> const &f, FloatImpl<U> const &g ) {
  return !f.isNaN() && !g.isNaN() && f.getNumber() >= g.getNumber();
}

template<typename T>
inline bool operator==( FloatImpl<T> const &f, double d ) {
  return f.getNumber() == d;
}

template<typename T>
inline bool operator==( double d, FloatImpl<T> const &f ) {
  return d = f.getNumber();
}

template<typename T>
inline bool operator!=( FloatImpl<T> const &f, double d ) {
  return f.getNumber() != d;
}

template<typename T>
inline bool operator!=( double d, FloatImpl<T> const &f ) {
  return f.getNumber() != d;
}

template<typename T>
inline bool operator<( FloatImpl<T> const &f, double d ) {
  return f.getNumber() < d;
}

template<typename T>
inline bool operator<( double d, FloatImpl<T> const &f ) {
  return d < f.getNumber();
}

template<typename T>
inline bool operator<=( FloatImpl<T> const &f, double d ) {
  return !f.isNaN() && d == d && f.getNumber() <= d;
}

template<typename T>
inline bool operator<=( double d, FloatImpl<T> const &f ) {
  return d == d && !f.isNaN() && d <= f.getNumber();
}

template<typename T>
inline bool operator>( FloatImpl<T> const &f, double d ) {
  return f.getNumber() > d;
}

template<typename T>
inline bool operator>( double d, FloatImpl<T> const &f ) {
  return d > f.getNumber();
}

template<typename T>
inline bool operator>=( FloatImpl<T> const &f, double d ) {
  return !f.isNaN() && d == d && f.getNumber() >= d;
}

template<typename T>
inline bool operator>=( double d, FloatImpl<T> const &f ) {
  return d == d && !f.isNaN() && d >= f.getNumber();
}

////////// math functions /////////////////////////////////////////////////////

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::acosh() const {
  // formula from www.mathworks.com
  return std::log( value_ + std::sqrt( value_ * value_ - 1 ) );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::asinh() const {
  // formula from www.mathworks.com
  return std::log( value_ + std::sqrt( value_ * value_ + 1 ) );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::atan() const {
  return std::atan( value_ );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::atanh() const {
  // formula from www.mathworks.com
  return 0.5 * std::log( (1 + value_) / (1 - value_) );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::atan2( double x ) const {
  return std::atan2( value_, static_cast<value_type>( x ) );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::atan2( FloatImpl<FloatType> const &x ) const {
  return atan2( x.value_ );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::ceil() const {
  return std::ceil( value_ );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::cos() const {
  return std::cos( value_ );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::cosh() const {
  return std::cosh( value_ );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::exp() const {
  return std::exp( value_ );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::exp10() const {
  return std::pow( 10, value_ );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::floor() const {
  return std::floor( value_ );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::fmod( double d ) const {
  return std::fmod( value_, static_cast<value_type>( d ) );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::fmod( FloatImpl<FloatType> const &f ) const {
  return fmod( f.value_ );
}

template<typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::log() const {
  return value_ < 0 ? nan() : FloatImpl<FloatType>( std::log( value_ ) );
}

template<typename FloatType>
FloatImpl<FloatType> FloatImpl<FloatType>::log10() const {
  return value_ < 0 ? nan() : FloatImpl<FloatType>( std::log10( value_ ) );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::pow( int p ) const {
  return std::pow( value_, p );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::pow( FloatImpl<FloatType> const &p ) const {
  return p.isNaN() ? value_ : std::pow( value_, p.value_ );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::sin() const {
  return std::sin( value_ );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::sinh() const {
  return std::sinh( value_ );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::sqrt() const {
  return value_ < 0 ? nan() : FloatImpl( std::sqrt( value_ ) );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::tan() const {
  return std::tan( value_ );
}

template<typename FloatType> inline FloatImpl<FloatType>
FloatImpl<FloatType>::tanh() const {
  return std::tanh( value_ );
}

////////// miscellaneous //////////////////////////////////////////////////////

template<typename T>
template<typename U>
inline int FloatImpl<T>::compare( FloatImpl<U> const &f ) const {
  return value_ < f.value_ ? -1 : value_ > f.value_ ? 1 : 0;
}

template<typename FloatType>
inline uint32_t FloatImpl<FloatType>::hash() const {
  return static_cast<uint32_t>( value_ );
}

template<typename FloatType>
inline bool FloatImpl<FloatType>::isNeg() const {
  return value_ < 0;
}

template<typename FloatType>
inline bool FloatImpl<FloatType>::isPos() const {
  return value_ > 0;
}

template<typename FloatType>
inline bool FloatImpl<FloatType>::isPosZero() const {
  return value_ == 0 && !isNegZero();
}

template<typename FloatType>
inline bool FloatImpl<FloatType>::isNaN() const {
  return value_ != value_;
}

template<typename FloatType>
inline bool FloatImpl<FloatType>::isNegInf() const {
 return value_ == -std::numeric_limits<FloatType>::infinity();
}

template<typename FloatType>
inline bool FloatImpl<FloatType>::isPosInf() const {
  return value_ == std::numeric_limits<FloatType>::infinity();
}

template<typename FloatType>
inline bool FloatImpl<FloatType>::isFinite() const {
  return !isNaN() && !isPosInf() && !isNegInf();
}

template<typename FloatType>
inline bool FloatImpl<FloatType>::isInteger() const {
  return isFinite() && ::floor( value_ ) == value_;
}

template <typename FloatType>
inline bool FloatImpl<FloatType>::isZero() const {
  return value_ == 0;
}

template<typename FloatType> inline
std::ostream& operator<<( std::ostream &os, FloatImpl<FloatType> const &f ) {
  return os << f.toString();
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif // ZORBA_FLOATIMPL_H
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
