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

#include <math.h>

#include <zorba/config.h>

#include "common/common.h"
#include "zorbaserialization/class_serializer.h"

#include "schema_types.h"
#include "zorbatypes_decl.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

class FloatCommons
{
 public:
  static const zstring& get_INF_POS_STR();
  static const zstring& get_INF_NEG_STR();
  static const zstring& get_NOT_A_NUM_STR();

  static Double parseFloat(const Float&);

  static Float parseDouble(const Double&);
};


// exported for testing only
template<typename FloatType>
class ZORBA_DLL_PUBLIC FloatImpl : public serialization::SerializeBaseClass {
public:
  typedef FloatType value_type;

  /**
   * @return float or double that represents 0
   */
  static FloatImpl<FloatType> const& zero();

  /**
   * @return float or double that represents -0
   */
  static FloatImpl<FloatType> const& neg_zero();

  /**
   * @return float or double that represents +1
   */
  static FloatImpl<FloatType> const& one();

  /**
   * @return float or double that represents -1
   */
  static FloatImpl<FloatType> const& neg_one();

  /**
   * @return float or double that represents NaN
   */
  static FloatImpl<FloatType> const& nan();

  /**
   * @return float or double that represents +INF
   */
  static FloatImpl<FloatType> const& inf_pos();

  /**
   * @return float or double that represents -INF
   */
  static FloatImpl<FloatType> const& inf_neg();

  static int max_precision();

  /**
   * Parses string to float value
   */
  static bool parseString(const char* aCharStar, FloatImpl& aFloatImpl);

  /**
   * Parses float type (double of float) to float value
   */
  static FloatImpl<FloatType> parseFloatType(FloatType aFloatImpl);

  static FloatImpl<FloatType> parseDecimal(const Decimal&);

  static FloatImpl<FloatType> parseInteger(const Integer&);

  /**
   * Parses long to float value
   */
  static FloatImpl<FloatType> parseULong(uint64_t);

  /**
   * Parses long to float value
   */
  static FloatImpl<FloatType> parseLong(int64_t);

  /**
   * Parses int to float value
   */
  static FloatImpl<FloatType> parseInt(int32_t);

  /**
   * Parses int to float value
   */
  static FloatImpl<FloatType> parseUInt(uint32_t);

protected:
  /**
   * Checks if the passed number in string format is NaN, INF,
   * -INF, negative or non-negative number.
   * @param aNumber Number in string format
   * @param parsed number
   * @return false if aNumber is not parsable to INF or nan
   */
  static bool parseInfNaNString(const char* aNumber, FloatImpl& aFloatImpl);

public:
  SERIALIZABLE_TEMPLATE_CLASS(FloatImpl)
  SERIALIZABLE_CLASS_CONSTRUCTOR(FloatImpl)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  FloatImpl( int n = 0 ) :
    theFloating( static_cast<value_type>( n ) ), precision( max_precision() )
  {
  }

  FloatImpl( float n ) :
    theFloating( static_cast<value_type>( n ) ), precision( max_precision() )
  {
  }

  FloatImpl( double n ) :
    theFloating( static_cast<value_type>( n ) ), precision( max_precision() )
  {
  }

  FloatImpl(const FloatImpl& aFloatImpl)
    :
    ::zorba::serialization::SerializeBaseClass(),
    theFloating(aFloatImpl.theFloating),
    precision(aFloatImpl.precision)
  {
  }

  FloatImpl<FloatType>& operator=(const FloatImpl& aFloatImpl)
  {
    theFloating = aFloatImpl.theFloating;
    precision = aFloatImpl.precision;
    return *this;
  }

  value_type getNumber() const { return theFloating; }

  bool isNaN() const;

  bool isFinite() const;

  bool isPosInf() const;

  bool isNegInf() const;

  bool isNeg() const;

  bool isPos() const;

  bool isZero() const;

  bool isPosZero() const;

  bool isNegZero() const;

  bool isInteger() const { return isFinite() && ::floor(theFloating) == theFloating; }

  uint32_t hash() const;

  bool operator==(const FloatImpl& aFloatImpl) const;

  bool operator!=(const FloatImpl& aFloatImpl) const;

  bool operator<(const FloatImpl& aFloatImpl) const;

  bool operator<=(const FloatImpl& aFloatImpl) const;

  bool operator>(const FloatImpl& aFloatImpl) const;

  bool operator>=(const FloatImpl& aFloatImpl) const;

  long compare(const FloatImpl& aFloatImpl) const
  {
    return (*this < aFloatImpl ? -1 : (*this == aFloatImpl ? 0 : 1));
  }

  FloatImpl<FloatType> operator+(const FloatImpl& aFloatImpl) const;

  FloatImpl<FloatType>& operator+=(const FloatImpl& aFloatImpl)
  {
    *this = *this + aFloatImpl;
    return *this;
  }

  FloatImpl<FloatType> operator-(const FloatImpl& aFloatImpl) const;

  FloatImpl<FloatType>& operator-=(const FloatImpl& aFloatImpl)
  {
    *this = *this - aFloatImpl;
    return *this;
  }

  FloatImpl<FloatType> operator*(const FloatImpl& aFloatImpl) const;

  FloatImpl<FloatType>& operator*=(const FloatImpl& aFloatImpl)
  {
    *this = *this * aFloatImpl;
    return *this;
  }

  FloatImpl<FloatType> operator/(const FloatImpl& aFloatImpl) const;

  FloatImpl<FloatType>& operator/=(const FloatImpl& aFloatImpl)
  {
    *this = *this / aFloatImpl;
    return *this;
  }

  FloatImpl<FloatType> operator%(const FloatImpl& aFloatImpl) const;

  FloatImpl<FloatType>& operator%=(const FloatImpl& aFloatImpl)
  {
    *this = *this % aFloatImpl;
    return *this;
  }

  FloatImpl<FloatType> operator-() const;

  FloatImpl<FloatType> floor() const;

  FloatImpl<FloatType> ceil() const;

  FloatImpl<FloatType> round() const;

  FloatImpl<FloatType> round(Integer aPrecision) const;

  FloatImpl<FloatType> roundHalfToEven(Integer aPrecision) const;

  FloatImpl<FloatType> sqrt() const;

  FloatImpl<FloatType> exp() const;

  FloatImpl<FloatType> exp10() const;

  FloatImpl<FloatType> log() const;

  FloatImpl<FloatType> log10() const;

  FloatImpl<FloatType> sin() const;

  FloatImpl<FloatType> cos() const;

  FloatImpl<FloatType> tan() const;

  FloatImpl<FloatType> asin() const;

  FloatImpl<FloatType> acos() const;

  FloatImpl<FloatType> atan() const;

  FloatImpl<FloatType> sinh() const;

  FloatImpl<FloatType> cosh() const;

  FloatImpl<FloatType> tanh() const;

  FloatImpl<FloatType> asinh() const;

  FloatImpl<FloatType> acosh() const;

  FloatImpl<FloatType> atanh() const;

  FloatImpl<FloatType> atan2(FloatImpl<FloatType> x) const;

  FloatImpl<FloatType> pow(FloatImpl<FloatType> p) const;

  FloatImpl<FloatType> pow(int p) const;

  FloatImpl<FloatType> fmod(FloatImpl<FloatType> p) const;

  void frexp(FloatImpl<FloatType>& out_mantissa, Integer& out_exponent) const;

  void modf(FloatImpl<FloatType>& out_fraction, FloatImpl<FloatType>& out_integer) const;

  zstring toIntegerString() const;

  zstring toString(bool no_scientific_mode = false) const;

private:
  value_type     theFloating;
  unsigned short precision;

  friend class Integer;
  friend class Decimal;
  friend class FloatCommons;
  template<typename T> friend class FloatImplTraits;
};

///////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const Double& aFloatImpl);
std::ostream& operator<<(std::ostream& os, const Float& aFloatImpl);

Double operator+(const Double&, const Float&);
Double operator+(const Float&, const Double&);
Double operator-(const Double&, const Float&);
Double operator-(const Float&, const Double&);
Double operator*(const Double&, const Float&);
Double operator*(const Float&, const Double&);
Double operator/(const Double&, const Float&);
Double operator/(const Float&, const Double&);
Double operator%(const Double&, const Float&);
Double operator%(const Float&, const Double&);

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif // ZORBA_FLOATIMPL_H
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
