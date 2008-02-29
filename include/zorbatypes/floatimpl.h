#ifndef ZORBA_FLOATIMPL_H
#define ZORBA_FLOATIMPL_H

#include <zorbatypes/m_apm.h>
#include <zorbatypes/zorbatypes_decl.h>
#include <zorbatypes/xqpstring.h>

namespace xqp {

  class FloatCommons {
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
  };

  template <typename FloatType>
  class FloatImpl {
    friend class Integer;
    friend class FloatCommons;

    private:
      FloatCommons::NumType theType;
      MAPM theFloatImpl;

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
  
} /* namespace xqp */

#endif // XQP_DOUBLE_H

