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
#ifndef ZORBA_FLOATIMPL_H
#define ZORBA_FLOATIMPL_H

#include "common/common.h"
#ifndef ZORBA_NO_BIGNUMBERS
#include "zorbatypes/m_apm.h"
#else
#include <math.h>
#endif
#include "zorbatypes/zorbatypes_decl.h"
#include "zorbatypes/xqpstring.h"

namespace zorba {

#ifdef ZORBA_NO_BIGNUMBERS
typedef double    MAPM;
#endif

class FloatCommons 
{
 public:
  enum NumType {
    NORMAL = 0,
    NORMAL_NEG,
    INF_POS,
    INF_NEG,
    NOT_A_NUM
  };

  static const xqpString& get_INF_POS_STR();
  static const xqpString& get_INF_NEG_STR();
  static const xqpString& get_NOT_A_NUM_STR();

  static Double
  parseFloat(const Float&);
   
  static Float 
  parseDouble(const Double&);
};


/**
 * Class to implement isPosInf, isZero und isNegInf for every different Template
 * Parameter of FloatImpl
 */
template <typename FloatType> class FloatImplTraits;


#ifndef ZORBA_NO_BIGNUMBERS
  /**
   * Specialization for double
   */
  template <>
  class FloatImplTraits<double> {
    public:
      static bool 
      isPosInf(MAPM aMAPM);
      
      static bool
      isZero(MAPM aMAPM); 
      
      static bool
      isNegInf(MAPM aMAPM); 
      
      static MAPM
      cutMantissa(MAPM aMAPM);

      static uint32_t 
      hash(FloatCommons::NumType, MAPM aMAPM);
  };

  /**
   * Specialization for float
   */
  template <>
  class FloatImplTraits<float> {
    public:
      static bool
      isPosInf(MAPM aMAPM);
      
      static bool
      isZero(MAPM aMAPM); 
      
      static bool
      isNegInf(MAPM aMAPM); 
      
      static MAPM
      cutMantissa(MAPM aMAPM);

      static uint32_t 
      hash(FloatCommons::NumType, MAPM aMAPM);
  };
#else
  template <typename FloatType>
  class FloatImplTraits {
    public:
      static bool
      isPosInf(FloatType aMAPM);
      
      static bool
      isZero(FloatType aMAPM); 
      
      static bool
      isNegInf(FloatType aMAPM); 
      
      static FloatType
      cutMantissa(FloatType aMAPM);

      static uint32_t 
      hash(FloatCommons::NumType, FloatType aMAPM);
  };
#endif

  template <typename FloatType>
  class FloatImpl {
    friend class Integer;
    friend class Decimal;
    friend class FloatCommons;
    template <typename Type>
      friend class FloatImplTraits;
    friend class NumConversions;

    private:
      FloatCommons::NumType theType;
#ifndef ZORBA_NO_BIGNUMBERS
      MAPM theFloatImpl;
#else
      FloatType  theFloatImpl;
#endif

      FloatImpl(FloatCommons::NumType aType, MAPM aFloatImpl) : theType(aType), theFloatImpl(aFloatImpl) { }

      public:
      FloatImpl() : theType(FloatCommons::NORMAL), theFloatImpl(0) { }
      FloatImpl(const FloatImpl& aFloatImpl) : theType(aFloatImpl.theType), theFloatImpl(aFloatImpl.theFloatImpl) {}

    protected:
      /**
       * Checks if the MAPM value is to big, too small, or too precise 
       * => possible type change to 0, INF or -INF, or reduced precision
       */
      static void checkInfZeroPrecision(FloatImpl& aFloatImpl);

    public:
      /**
       * @return float or double that represents 0
       */
      static FloatImpl<FloatType>&
      zero();

      /**
       * @return float or double that represents -0
       */
      static FloatImpl<FloatType>&
      zero_neg();

      /**
       * @return float or double that represents +1
       */
      static FloatImpl<FloatType>&
      one();

      /**
       * @return float or double that represents -1
       */
      static FloatImpl<FloatType>&
      one_neg();

      /**
       * @return float or double that represents NaN
       */
      static FloatImpl<FloatType>&
      nan();

      /**
       * @return float or double that represents +INF
       */
      static FloatImpl<FloatType>&
      inf_pos();

      /**
       * @return float or double that represents -INF
       */
      static FloatImpl<FloatType>&
      inf_neg();

      /**
       * @return type of the float value (NaN, INF, -INF, NaN, NORMAL, or NORMAL_NEG
       */
      FloatCommons::NumType 
      getType() const { return theType; }

      /**
       * @return mapm number
       */
      MAPM 
      getNumber() const { return theFloatImpl; }

      /**
       * Checks if the passed number in string format is NaN, inf, 
       * -inf, negative or non-negative number.
       * @param aNumber Number in string format
       * @return number type
       */
      static FloatCommons::NumType
      checkInfNaNNeg(const char* aNumber);

      /**
       * Checks if the passed FloatType is Nan, inf, -inf, negative
       * or non-negative.
       * @param aNumber Number
       * @return number type
       */
      static FloatCommons::NumType
      checkInfNaNNeg(FloatType aNumber);

      /**
       * Parses string to float value
       */
      static bool
      parseString(const char* aCharStar, FloatImpl& aFloatImpl);

      /**
       * Parses float type (double of float) to float value
       */
      static FloatImpl<FloatType>
      parseFloatType(FloatType aFloatImpl);

      /**
       * Parses int to float value
       */
      static FloatImpl<FloatType>
      parseInt(int32_t);

      /**
       * Parses long to float value
       */
      static FloatImpl<FloatType>
      parseLong(long);

      static FloatImpl<FloatType>
      parseDecimal(const Decimal&);

      static FloatImpl<FloatType>
      parseInteger(const Integer&);

      FloatImpl<FloatType>& operator=(const FloatImpl& aFloatImpl) 
      {
        theType = aFloatImpl.theType;
        theFloatImpl = aFloatImpl.theFloatImpl;
        return *this;
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

      FloatImpl<FloatType> 
      operator-() const;

      FloatImpl<FloatType> 
      floor() const; 

      FloatImpl<FloatType>
      ceil() const; 

      FloatImpl<FloatType>
      round() const;

      FloatImpl<FloatType> 
      round(Integer aPrecision) const;

      FloatImpl<FloatType> 
      roundHalfToEven(Integer aPrecision) const;

      FloatImpl<FloatType> sqrt() const;
      FloatImpl<FloatType> exp() const;
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

      bool 
      isNaN() const { return theType == FloatCommons::NOT_A_NUM; }

      bool 
      isFinite() const { return theType == FloatCommons::NORMAL || theType == FloatCommons::NORMAL_NEG; }

      bool 
      isPosInf() const { return theType == FloatCommons::INF_POS; }

      bool
      isNegInf() const { return theType == FloatCommons::INF_NEG; }

      bool 
      isNeg() const { return theType == FloatCommons::NORMAL_NEG || theType == FloatCommons::INF_NEG;  }

      bool
      isPos() const { return theType == FloatCommons::NORMAL || theType == FloatCommons::INF_POS; }

      bool 
      isZero() const { return ((theType == FloatCommons::NORMAL || theType == FloatCommons::NORMAL_NEG) && theFloatImpl == 0); }

      bool 
      operator==(const FloatImpl& aFloatImpl) const;

      bool 
      operator!=(const FloatImpl& aFloatImpl) const;

      bool 
      operator<(const FloatImpl& aFloatImpl) const;

      bool 
      operator<=(const FloatImpl& aFloatImpl) const;

      bool 
      operator>(const FloatImpl& aFloatImpl) const;

      bool 
      operator>=(const FloatImpl& aFloatImpl) const;

      xqpString 
      toIntegerString() const;
      
      xqpString 
      toString() const;

      uint32_t
      hash() const;

  }; // class FloatImpl

  std::ostream&
  operator<<(std::ostream& os, const Double& aFloatImpl); 
  
  std::ostream&
  operator<<(std::ostream& os, const Float& aFloatImpl);
  
  Double
  operator+(const Double&, const Float&);
  
  Double
  operator+(const Float&, const Double&);
  
  Double
  operator-(const Double&, const Float&);
  
  Double
  operator-(const Float&, const Double&);
  
  Double
  operator*(const Double&, const Float&);
  
  Double
  operator*(const Float&, const Double&);
  
  Double
  operator/(const Double&, const Float&);
  
  Double
  operator/(const Float&, const Double&);
  
  Double
  operator%(const Double&, const Float&);
  
  Double
  operator%(const Float&, const Double&);
  
} /* namespace zorba */

#endif // ZORBA_DOUBLE_H

/*
 * Local variables:
 * mode: c++
 * End:
 */
