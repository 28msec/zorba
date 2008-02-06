/*
 * Copyright 2008 FLWOR Foundation
 *
 * Authors: David Graf (davidgraf@28msec)
 */

#ifndef XQP_DOUBLE_H
#define XQP_DOUBLE_H

#include "mapm/m_apm.h"
#include "util/utf8/xqpString.h"
#include "util/bignum/integer.h"
#include "util/bignum/decimal.h"

namespace xqp {

class Integer;

template <typename Type> class FloatImpl;

typedef FloatImpl<double> Double;
typedef FloatImpl<float> Float;

std::ostream& operator<<(std::ostream& os, const Double& aFloatImpl); 
std::ostream& operator<<(std::ostream& os, const Float& aFloatImpl);

/**
 * Class to implement isPosInf, isZero und isNegInf for every different Template
 * Parameter of FloatImpl
 */
template <typename FloatType> class FloatImplTraits;

/**
 * Specialization for double
 */
template <>
class FloatImplTraits<double> {
public:
  static bool isPosInf(MAPM aMAPM);
  static bool isZero(MAPM aMAPM); 
  static bool isNegInf(MAPM aMAPM); 
};

class FloatConsts {
public:
  enum NumType {
    NORMAL = 0,
    NORMAL_NEG,
    INF_POS,
    INF_NEG,
    NOT_A_NUM
  };

  static const xqpString INF_POS_STR;
  static const xqpString INF_NEG_STR;
  static const xqpString NOT_A_NUM_STR;
};

/**
 * Specialization for float
 */
template <>
class FloatImplTraits<float> {
public:
  static bool isPosInf(MAPM aMAPM);
  static bool isZero(MAPM aMAPM); 
  static bool isNegInf(MAPM aMAPM); 
};

template <typename FloatType>
class FloatImpl {
  friend class Integer;

private:
  FloatConsts::NumType theType;
  MAPM theFloatImpl;

  FloatImpl(FloatConsts::NumType aType, MAPM aFloatImpl) : theType(aType), theFloatImpl(aFloatImpl) { }

public:
  FloatImpl() : theType(FloatConsts::NORMAL), theFloatImpl(0) { }
  FloatImpl(FloatType aFloatImpl) { setFloatImpl(aFloatImpl); }
  FloatImpl(const FloatImpl& aFloatImpl) : theType(aFloatImpl.theType), theFloatImpl(aFloatImpl.theFloatImpl) {}

protected:
  /**
   * Sets the value of the template parameter type.
   */
  void setFloatImpl(FloatType aFloatImpl);

  /**
   * @return true, if aFloatImpl has been changed
   */
  static bool checkInfNaN(FloatImpl& aFloatImpl);

public:
  /**
   * Checks if the passed number in string format is NaN, inf, 
   * -inf, negative or non-negative number.
   * @param aNumber Number in string format
   * @return number type
   */
  static FloatConsts::NumType checkInfNaNNeg(const char* aNumber);

  /**
   * Checks if the passed FloatType is Nan, inf, -inf, negative
   * or non-negative.
   * @param aNumber Number
   * @return number type
   */
  static FloatConsts::NumType checkInfNaNNeg(FloatType aNumber);

  static bool parse(const char* aCharStar, FloatImpl& aFloatImpl);

  FloatImpl& operator=(FloatType aFloatImpl){
    setFloatImpl(aFloatImpl);
    return *this;
  }
 
  FloatImpl& operator=(const FloatImpl& aFloatImpl) {
    theType = aFloatImpl.theType;
    theFloatImpl = aFloatImpl.theFloatImpl;
    return *this;
  }

  FloatImpl operator+(const FloatImpl& aFloatImpl) const;
 
  FloatImpl& operator+=(const FloatImpl& aFloatImpl){
    *this = *this + aFloatImpl;
    return *this;
  }

  FloatImpl operator-(const FloatImpl& aFloatImpl) const;

  FloatImpl& operator-=(const FloatImpl& aFloatImpl){
    *this = *this - aFloatImpl;
    return *this;
  }

  FloatImpl operator*(const FloatImpl& aFloatImpl) const;

  FloatImpl& operator*=(const FloatImpl& aFloatImpl){
    *this = *this * aFloatImpl;
    return *this;
  }

  FloatImpl operator/(const FloatImpl& aFloatImpl) const;

  FloatImpl& operator/=(const FloatImpl& aFloatImpl){
    *this = *this / aFloatImpl;
    return *this;
  }

  FloatImpl operator%(const FloatImpl& aFloatImpl) const;

  FloatImpl& operator%=(const FloatImpl& aFloatImpl){
    *this = *this % aFloatImpl;
    return *this;
  }

  FloatImpl operator-() const;

  FloatImpl floor() const; 

  FloatImpl ceil() const; 

  FloatImpl round() const{
    return round((int32_t)0);
  }

  FloatImpl round(Integer aPrecision) const;

  FloatImpl roundHalfToEven(Integer aPrecision) const;

  bool isNaN() const { return theType == FloatConsts::NOT_A_NUM; }

  bool isFinite() const { return theType == FloatConsts::NORMAL || theType == FloatConsts::NORMAL_NEG; }

  bool isPosInf() const { return theType == FloatConsts::INF_POS; }

  bool isNegInf() const { return theType == FloatConsts::INF_NEG; }

  bool isNeg() const { return theType == FloatConsts::NORMAL || theType == FloatConsts::INF_POS;  }

  bool isPos() const { return theType == FloatConsts::NORMAL_NEG || theType == FloatConsts::INF_NEG; }

  bool isZero() const { return ((theType == FloatConsts::NORMAL || theType == FloatConsts::NORMAL_NEG) && theFloatImpl == 0); }

  bool operator==(const FloatImpl& aFloatImpl) const;

  bool operator!=(const FloatImpl& aFloatImpl) const;

  bool operator<(const FloatImpl& aFloatImpl) const;

  bool operator<=(const FloatImpl& aFloatImpl) const;

  bool operator>(const FloatImpl& aFloatImpl) const;

  bool operator>=(const FloatImpl& aFloatImpl) const;

  xqpString toString() const;

}; // class FloatImpl

} // namespace xqp


#endif // XQP_DOUBLE_H

