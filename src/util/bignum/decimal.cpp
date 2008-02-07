/*
 * Copyright 2008 FLWOR Foundation.
 *
 * Authros: David Graf (davidgraf@28msec.com)
 */

#include "util/bignum/integer.h"
#include "util/numconversions.h"
#include "util/bignum/decimal.h"

namespace xqp {

Decimal::Decimal(const Integer& aInteger) {
  theDecimal = aInteger.theInteger;
}

Decimal::Decimal(uint32_t aUInt) {
  xqpString lStrRep = NumConversions::uintToStr(aUInt);
  theDecimal = lStrRep.c_str();
}

Decimal::Decimal(long long aLong) {
  xqpString lStrRep = NumConversions::longToStr(aLong);
  theDecimal = lStrRep.c_str();
}

Decimal::Decimal(unsigned long long aULong) {
  xqpString lStrRep = NumConversions::ulongToStr(aULong);
  theDecimal = lStrRep.c_str();
}

bool Decimal::parse(const char* aCharStar, Decimal& aDecimal) {
  // correctness check
  const char* lCur = aCharStar;
  bool lGotPoint = false;
  bool lGotSign = false;
  bool lStop = false;
  bool lGotDigit = false;
  while (*lCur != '\0' && !lStop) {
    char lTmp = *lCur++;
    switch(lTmp) {
      case '+': 
        if (lGotSign || lGotDigit || lGotPoint) {
          lStop = true;
        } else {
          lGotSign = true;
        }
        break;
      case '-':
        if(lGotSign || lGotDigit || lGotPoint) {
          lStop = true;
        } else {
          lGotSign = true;
        }
        break;
      case '.': 
        if (lGotPoint) {
          lStop = true;
        } else {
          lGotPoint = true;
        }
        break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9': 
        lGotDigit = true;
        break;
      default:
        lStop = true;
        break;
    }
  }
  if (lStop || !lGotDigit) {
    return false;
  } else {
    MAPM lNumber = aCharStar;
    aDecimal.theDecimal = lNumber;
    return true;
  }
}

bool Decimal::parse(double aDouble, Decimal& aDecimal) {
  switch(Double::checkInfNaNNeg(aDouble)) {
  case FloatConsts::NORMAL:
  case FloatConsts::NORMAL_NEG:
    aDecimal.theDecimal = aDouble;
    return true;
    break;
  default:
    return false;
    break;
  }
}

Decimal Decimal::parseLong(long aLong) {
  MAPM lNumber = aLong;
  return Decimal(lNumber);
}

MAPM Decimal::round(MAPM aValue, MAPM aPrecision) {
  MAPM aExp = MAPM(10).pow(aPrecision);
  MAPM aCur = aValue * aExp;
  aCur += 0.5;
  aCur = aCur.floor();
  aCur /= aExp;
  return aCur;
}

MAPM Decimal::roundHalfToEven(MAPM aValue, MAPM aPrecision) {
  MAPM aExp = MAPM(10).pow(aPrecision);
  MAPM aCur = aValue * aExp;
  bool aHalfVal = ((aCur - 0.5) == aCur.floor());
  aCur += 0.5;
  aCur = aCur.floor();
  if (aHalfVal && aCur.is_odd()) {
    aCur -= 1;
  }
  aCur /= aExp;
  return aCur;
}

Decimal& Decimal::operator=(const Decimal& aDecimal) {
  theDecimal = aDecimal.theDecimal;
  return *this;
}

Decimal& Decimal::operator=(const Integer& aInteger) {
  theDecimal = aInteger.theInteger;
  return *this;
}

Decimal& Decimal::operator=(long long aLong) {
  xqpString lStrRep = NumConversions::longToStr(aLong);
  theDecimal = lStrRep.c_str();
  return *this;
}

Decimal& Decimal::operator=(int32_t aInt) {
  theDecimal = aInt;
  return *this;
}

Decimal Decimal::operator+(const Integer& aInteger) const {
  Decimal lResult(theDecimal + aInteger.theInteger);
  return lResult;
}

Decimal Decimal::operator+(long long aLong) const {
  Decimal lResult(theDecimal + Integer::longlongToMAPM(aLong));
  return lResult;
}

Decimal Decimal::operator+(int32_t aInt) const {
  Decimal lResult(theDecimal + aInt);
  return lResult;
}

Decimal Decimal::operator+(const Decimal& aDecimal) const {
  Decimal lResult(theDecimal + aDecimal.theDecimal);
  return lResult;
}

Decimal Decimal::operator+(double aDouble) const {
  Decimal lResult(theDecimal + aDouble);
  return lResult;
}

Decimal& Decimal::operator+=(const Integer& aInteger) {
  theDecimal += aInteger.theInteger;
  return *this;
}

Decimal& Decimal::operator+=(long long aLong) {
  theDecimal += Integer::longlongToMAPM(aLong);
  return *this;
}

Decimal& Decimal::operator+=(int32_t aInt) {
  theDecimal += aInt;
  return *this;
}

Decimal& Decimal::operator+=(const Decimal& aDecimal) {
  theDecimal += aDecimal.theDecimal;
  return *this;
}

Decimal& Decimal::operator+=(double aDouble) {
  theDecimal += aDouble;
  return *this;
}

Decimal Decimal::operator-(const Integer& aInteger) const {
  Decimal lResult(theDecimal - aInteger.theInteger);
  return lResult;
}

Decimal Decimal::operator-(long long aLong) const {
  Decimal lResult(theDecimal - Integer::longlongToMAPM(aLong));
  return lResult;
}

Decimal Decimal::operator-(int32_t aInt) const {
  Decimal lResult(theDecimal - aInt);
  return lResult;
}

Decimal Decimal::operator-(const Decimal& aDecimal) const {
  Decimal lResult(theDecimal - aDecimal.theDecimal);
  return lResult;
}

Decimal Decimal::operator-(double aDouble) const {
  Decimal lResult(theDecimal - aDouble);
  return lResult;
}

Decimal& Decimal::operator-=(const Integer& aInteger) {
  theDecimal -= aInteger.theInteger;
  return *this;
}

Decimal& Decimal::operator-=(long long aLong) {
  theDecimal -= Integer::longlongToMAPM(aLong);
  return *this;
}

Decimal& Decimal::operator-=(int32_t aInt) {
  theDecimal -= aInt;
  return *this;
}

Decimal& Decimal::operator-=(const Decimal& aDecimal) {
  theDecimal -= aDecimal.theDecimal;
  return *this;
}

Decimal& Decimal::operator-=(double aDouble) {
  theDecimal -= aDouble;
  return *this;
}

Decimal Decimal::operator*(const Integer& aInteger) const {
  Decimal lResult(theDecimal * aInteger.theInteger);
  return lResult;
}

Decimal Decimal::operator*(long long aLong) const {
  Decimal lResult(theDecimal * Integer::longlongToMAPM(aLong));
  return lResult;
}

Decimal Decimal::operator*(int32_t aInt) const {
  Decimal lResult(theDecimal * aInt);
  return  lResult;
}

Decimal Decimal::operator*(const Decimal& aDecimal) const {
  Decimal lResult(theDecimal * aDecimal.theDecimal);
  return lResult;
}

Decimal Decimal::operator*(double aDouble) const {
  Decimal lResult(theDecimal * aDouble);
  return lResult;
}

Decimal& Decimal::operator*=(const Integer& aInteger) {
  theDecimal *= aInteger.theInteger;
  return *this;
}

Decimal& Decimal::operator*=(long long aLong) {
  theDecimal *= Integer::longlongToMAPM(aLong);
  return *this;
}

Decimal& Decimal::operator*=(int32_t aInt) {
  theDecimal *= aInt;
  return *this;
}

Decimal& Decimal::operator*=(const Decimal& aDecimal) {
  theDecimal *= aDecimal.theDecimal;
  return *this;
}

Decimal& Decimal::operator*=(double aDouble) {
  theDecimal *= aDouble;
  return *this;
}

Decimal Decimal::operator/(const Integer& aInteger) const {
  MAPM lRes = theDecimal / aInteger.theInteger;
  return Decimal(lRes);
}

Decimal Decimal::operator/(long long aLong) const {
  MAPM lRes = theDecimal / Integer::longlongToMAPM(aLong);
  return Decimal(lRes);
}

Decimal Decimal::operator/(int32_t aInt) const {
  MAPM lRes = theDecimal / aInt;
  return Decimal(lRes);
}

Decimal Decimal::operator/(const Decimal& aDecimal) const {
  MAPM lRes = theDecimal / aDecimal.theDecimal;
  return Decimal(lRes);
}

Decimal Decimal::operator/(double aDouble) const {
  MAPM lRes = theDecimal / aDouble;
  return Decimal(lRes);
}

Decimal& Decimal::operator/=(const Integer& aInteger) {
  theDecimal /= aInteger.theInteger;
  return *this;
}

Decimal& Decimal::operator/=(long long aLong) {
  theDecimal /= Integer::longlongToMAPM(aLong);
  return *this;
}

Decimal& Decimal::operator/=(int32_t aInt) {
  theDecimal /= aInt;
  return *this;
}

Decimal& Decimal::operator/=(const Decimal& aDecimal) {
  theDecimal /= aDecimal.theDecimal;
  return *this;
}

Decimal& Decimal::operator/=(double aDouble) {
  theDecimal /= aDouble;
  return *this;
}

Decimal Decimal::operator%(const Integer& aInteger) const {
  MAPM lRes = theDecimal % aInteger.theInteger;
  return Decimal(lRes);
}

Decimal Decimal::operator%(long long aLong) const {
  MAPM lRes = theDecimal % Integer::longlongToMAPM(aLong);
  return Decimal(lRes);
}

Decimal Decimal::operator%(int32_t aInt) const {
  MAPM lRes = theDecimal % aInt;
  return Decimal(lRes);
}

Decimal Decimal::operator%(const Decimal& aDecimal) const {
  MAPM lRes = theDecimal % aDecimal.theDecimal;
  return Decimal(lRes);
}

Decimal Decimal::operator%(double aDouble) const {
  MAPM lRes = theDecimal % aDouble;
  return Decimal(lRes);
}

Decimal& Decimal::operator%=(const Integer& aInteger) {
  theDecimal %= aInteger.theInteger;
  return *this;
}

Decimal& Decimal::operator%=(long long aLong) {
  theDecimal %= Integer::longlongToMAPM(aLong);
  return *this;
}

Decimal& Decimal::operator%=(int32_t aInt) {
  theDecimal %= aInt;
  return *this;
}

Decimal& Decimal::operator%=(const Decimal& aDecimal) {
  theDecimal %= aDecimal.theDecimal;
  return *this;
}

Decimal& Decimal::operator%=(double aDouble) {
  theDecimal %= aDouble;
  return *this;
}

Decimal Decimal::operator-() const {
  return Decimal(-theDecimal);
}

Decimal Decimal::round() const {
  return round((int32_t)0);
}

Decimal Decimal::round(Integer aPrecision) const {
  return Decimal(Decimal::round(theDecimal, aPrecision.theInteger));
}

Decimal Decimal::roundHalfToEven(Integer aPrecision) const {
  return Decimal(Decimal::roundHalfToEven(theDecimal, aPrecision.theInteger));
}

bool Decimal::operator==(const Integer& aInteger) const { 
  return theDecimal == aInteger.theInteger;
}

bool Decimal::operator==(long long aLong) const {
  return theDecimal == Integer::longlongToMAPM(aLong);
}

bool Decimal::operator!=(const Integer& aInteger) const { 
  return theDecimal != aInteger.theInteger;
}

bool Decimal::operator!=(long long aLong) const {
  return theDecimal != Integer::longlongToMAPM(aLong);
}

bool Decimal::operator<(const Integer& aInteger) const { 
  return theDecimal < aInteger.theInteger;
}

bool Decimal::operator<(long long aLong) const {
  return theDecimal < Integer::longlongToMAPM(aLong);
}

bool Decimal::operator<=(const Integer& aInteger) const { 
  return theDecimal <= aInteger.theInteger;
}

bool Decimal::operator<=(long long aLong) const {
  return theDecimal <= Integer::longlongToMAPM(aLong);
}

bool Decimal::operator>(const Integer& aInteger) const { 
  return theDecimal > aInteger.theInteger;
}

bool Decimal::operator>(long long aLong) const {
  return theDecimal > Integer::longlongToMAPM(aLong);
}

bool Decimal::operator>=(const Integer& aInteger) const { 
  return theDecimal >= aInteger.theInteger;
}

bool Decimal::operator>=(long long aLong) const {
  return theDecimal >= Integer::longlongToMAPM(aLong);
}

xqpString Decimal::decimalToString(MAPM theValue) {
  char lBuffer[1024];
  theValue.toFixPtString(lBuffer, 16);
  
  // Note in the canonical representation the decimal point is required
  // and there must be at least one digit to the right and one digit to 
  // the left of the decimal point (which may be 0)
  if(strchr(lBuffer,'.')!=0) {
    // remove trailing 0's
    char* lastChar=lBuffer+strlen(lBuffer)-1;
    while(*lastChar=='0') {
      *lastChar--=0;
    }
    // remove decimal point, if there are no digits after it
    if(*lastChar=='.')
      *lastChar=0;
  }
    
  xqpString lResult = lBuffer;
  return lResult;
}

xqpString Decimal::toString() const {
  return decimalToString(theDecimal);
}

std::ostream& operator<<(std::ostream& os, const Decimal& aDecimal) {
  os << aDecimal.toString();
  return os;
}

} // namespace xqp

