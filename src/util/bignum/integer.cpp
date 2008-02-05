/*
 * Copyright 2008 FLWOR Foundation.
 *
 * Authros: David Graf (davidgraf@28msec.com)
 */

#include "util/bignum/integer.h"
#include "util/numconversions.h"
#include "util/bignum/decimal.h"
#include "util/bignum/floatimpl.h"

namespace xqp {

Integer::Integer(const Decimal& aDecimal) {
  theInteger = floatingToInteger(aDecimal.theDecimal);
}

Integer::Integer(long long aLong) {
  xqpString lStrRep = NumConversions::longToStr(aLong);
  theInteger = lStrRep.c_str();
}

Integer::Integer(unsigned long long aULong) {
  xqpString lStrRep = NumConversions::ulongToStr(aULong);
  theInteger = lStrRep.c_str();
}

Integer::Integer(uint32_t aUInt) {
  xqpString lStrRep = NumConversions::uintToStr(aUInt);
  theInteger = lStrRep.c_str();
}

bool Integer::parse(const char* aCharStar, Integer& aInteger) {
  // correctness check
  const char* lCur = aCharStar;
  bool lGotSign = false;
  bool lStop = false;
  bool lGotDigit = false;
  while (*lCur != '\0' && !lStop) {
    char lTmp = *lCur++;
    switch(lTmp) {
      case '+': 
        if (lGotSign || lGotDigit) {
          lStop = true;
        } else {
          lGotSign = true;
        }
        break;
      case '-':
        if(lGotSign || lGotDigit) {
          lStop = true;
        } else {
          lGotSign = true;
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
    aInteger.theInteger = lNumber;
    return true;
  }
}

bool Integer::parseUnsigned(const char* aStarChar, Integer& aUInteger) {
  // correctness check
  const char* lCur = aStarChar;
  bool lStop = false;
  while (*lCur != '\0' && !lStop) {
    char lTmp = *lCur++;
    switch(lTmp) {
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
        break;
      default:
        lStop = true;
        break;
    }
  }
  if (lStop) {
    return false;
  } else {
    MAPM lNumber = aStarChar;
    aUInteger.theInteger = lNumber;
    return true;
  }
}
  
Integer Integer::parseLong(long aLong) { 
  MAPM lNumber = aLong;
  return Integer(lNumber);
}
Integer Integer::parseULong(unsigned long aULong) {
  xqpString lStrRep = NumConversions::ulongToStr(aULong);
  MAPM lNumber = lStrRep.c_str();
  return Integer(lNumber);
}
Integer Integer::parseSizeT(size_t aSizeT) {
  xqpString lStrRep = NumConversions::sizetToStr(aSizeT);
  MAPM lNumber = lStrRep.c_str();
  return Integer(lNumber);
}


bool Integer::parse(const Double& aDouble, Integer& aInteger) {
  switch(aDouble.theType) {
  case FloatConsts::NORMAL:
  case FloatConsts::NORMAL_NEG:
  {
    MAPM lNum = aDouble.theFloatImpl;
    aInteger.theInteger = floatingToInteger(lNum);
    return true;
  }
    break;
  default:
    return false;
    break;
  }
}

bool Integer::parse(const Float& aFloat, Integer& aInteger) {
  switch(aFloat.theType) {
  case FloatConsts::NORMAL:
  case FloatConsts::NORMAL_NEG:
  {
    MAPM lNum = aFloat.theFloatImpl;
    aInteger.theInteger = floatingToInteger(lNum);
    return true;
  }
    break;
  default:
    return false;
    break;
  }
}

Integer& Integer::operator=(const Integer& aInteger) {
  theInteger = aInteger.theInteger;
  return *this;
}

Integer& Integer::operator=(long long aLong) {
  xqpString lStrRep = NumConversions::longToStr(aLong);
  theInteger = lStrRep.c_str();
  return *this;
}

Integer& Integer::operator=(int32_t aInt) {
  theInteger = aInt;
  return *this;
}

MAPM Integer::longlongToMAPM(long long aLong) {
  xqpString lStrRep = NumConversions::longToStr(aLong);
  return MAPM(lStrRep.c_str());
}

Integer Integer::operator+(const Integer& aInteger) const {
  Integer lResult(theInteger + aInteger.theInteger);
  return lResult;
}

Integer Integer::operator+(long long aLong) const {
  Integer lResult(theInteger + Integer::longlongToMAPM(aLong));
  return lResult;
}

Integer Integer::operator+(int32_t aInt) const {
  Integer lResult(theInteger + aInt);
  return lResult;
}

Decimal Integer::operator+(const Decimal& aDecimal) const {
  Decimal lResult(theInteger + aDecimal.theDecimal);
  return lResult;
}

Decimal Integer::operator+(double aDouble) const {
  Decimal lResult(theInteger + aDouble);
  return lResult;
}

Integer& Integer::operator+=(const Integer& aInteger) {
  theInteger += aInteger.theInteger;
  return *this;
}

Integer& Integer::operator+=(long long aLong) {
  theInteger += Integer::longlongToMAPM(aLong);
  return *this;
}

Integer& Integer::operator+=(int32_t aInt) {
  theInteger += aInt;
  return *this;
}

Integer Integer::operator-(const Integer& aInteger) const {
  Integer lResult(theInteger - aInteger.theInteger);
  return lResult;
}

Integer Integer::operator-(long long aLong) const {
  Integer lResult(theInteger - Integer::longlongToMAPM(aLong));
  return lResult;
}

Integer Integer::operator-(int32_t aInt) const {
  Integer lResult(theInteger - aInt);
  return lResult;
}

Decimal Integer::operator-(const Decimal& aDecimal) const {
  Decimal lResult(theInteger - aDecimal.theDecimal);
  return lResult;
}

Decimal Integer::operator-(double aDouble) const {
  Decimal lResult(theInteger - aDouble);
  return lResult;
}

Integer& Integer::operator-=(const Integer& aInteger) {
  theInteger -= aInteger.theInteger;
  return *this;
}

Integer& Integer::operator-=(long long aLong) {
  theInteger -= Integer::longlongToMAPM(aLong);
  return *this;
}

Integer& Integer::operator-=(int32_t aInt) {
  theInteger -= aInt;
  return *this;
}

Integer Integer::operator*(const Integer& aInteger) const {
  Integer lResult(theInteger * aInteger.theInteger);
  return lResult;
}

Integer Integer::operator*(long long aLong) const {
  Integer lResult(theInteger * Integer::longlongToMAPM(aLong));
  return lResult;
}

Integer Integer::operator*(int32_t aInt) const {
  Integer lResult(theInteger * aInt);
  return lResult;
}

Decimal Integer::operator*(const Decimal& aDecimal) const {
  Decimal lResult(theInteger * aDecimal.theDecimal);
  return lResult;
}

Decimal Integer::operator*(double aDouble) const {
  Decimal lResult(theInteger * aDouble);
  return lResult;
}

Integer& Integer::operator*=(const Integer& aInteger) {
  theInteger *= aInteger.theInteger;
  return *this;
}

Integer& Integer::operator*=(long long aLong) {
  theInteger *= Integer::longlongToMAPM(aLong);
  return *this;
}

Integer& Integer::operator*=(int32_t aInt) {
  theInteger *= aInt;
  return *this;
}

Integer Integer::operator/(const Integer& aInteger) const {
  MAPM lRes = theInteger / aInteger.theInteger;
  lRes = floatingToInteger(lRes);
  return Integer(lRes);
}

Integer Integer::operator/(long long aLong) const {
  MAPM lRes = theInteger / Integer::longlongToMAPM(aLong);
  lRes = floatingToInteger(lRes);
  return Integer(lRes);
}

Integer Integer::operator/(int32_t aInt) const {
  MAPM lRes = theInteger / aInt;
  lRes = floatingToInteger(lRes);
  return Integer(lRes);
}

Decimal Integer::operator/(const Decimal& aDecimal) const {
  MAPM lRes = theInteger / aDecimal.theDecimal;
  return Decimal(lRes);
}

Decimal Integer::operator/(double aDouble) const {
  MAPM lRes = theInteger / aDouble;
  return Decimal(lRes);
}

Integer& Integer::operator/=(const Integer& aInteger) {
  theInteger /= aInteger.theInteger;
  theInteger = floatingToInteger(theInteger);
  return *this;
}

Integer& Integer::operator/=(long long aLong) {
  theInteger /= Integer::longlongToMAPM(aLong);
  theInteger = floatingToInteger(theInteger);
  return *this;
}

Integer& Integer::operator/=(int32_t aInt) {
  theInteger /= aInt;
  theInteger = floatingToInteger(theInteger);
  return *this;
}

Integer Integer::operator%(const Integer& aInteger) const {
  MAPM lRes = theInteger % aInteger.theInteger;
  return Integer(lRes);
}

Integer Integer::operator%(long long aLong) const {
  MAPM lRes = theInteger % Integer::longlongToMAPM(aLong);
  return Integer(lRes);
}

Integer Integer::operator%(int32_t aInt) const {
  MAPM lRes = theInteger % aInt;
  return Integer(lRes);
}

Decimal Integer::operator%(const Decimal& aDecimal) const {
  MAPM lRes = theInteger % aDecimal.theDecimal;
  return Decimal(lRes);
}

Decimal Integer::operator%(double aDouble) const {
  MAPM lRes = theInteger % aDouble;
  return Decimal(lRes);
}

Integer& Integer::operator%=(const Integer& aInteger) {
  theInteger %= aInteger.theInteger;
  return *this;
}

Integer& Integer::operator%=(long long aLong) {
  theInteger %= Integer::longlongToMAPM(aLong);
  return *this;
}

Integer& Integer::operator%=(int32_t aInt) {
  theInteger %= aInt;
  return *this;
}

Integer Integer::operator-() const {
  return Integer(-theInteger);
}

Integer& Integer::operator++() {
  theInteger++;
  return *this;
}

Integer Integer::operator++(int) {
  Integer lRes(theInteger);
  theInteger++;
  return lRes;
}

Integer Integer::round(Integer aPrecision) const {
  return Integer(Decimal::round(theInteger, aPrecision.theInteger));
}

Integer Integer::roundHalfToEven(Integer aPrecision) const {
  return Integer(Decimal::roundHalfToEven(theInteger, aPrecision.theInteger));
}

bool Integer::operator==(const Decimal& aDecimal) const {
  return theInteger == aDecimal.theDecimal;
}

bool Integer::operator==(long long aLong) const {
  return theInteger == Integer::longlongToMAPM(aLong);
}

bool Integer::operator!=(const Decimal& aDecimal) const {
  return theInteger != aDecimal.theDecimal;
}

bool Integer::operator!=(long long aLong) const {
  return theInteger != Integer::longlongToMAPM(aLong);
}

bool Integer::operator<(const Decimal& aDecimal) const {
  return theInteger < aDecimal.theDecimal;
}

bool Integer::operator<(long long aLong) const {
  return theInteger < Integer::longlongToMAPM(aLong);
}

bool Integer::operator<=(const Decimal& aDecimal) const {
  return theInteger <= aDecimal.theDecimal;
}

bool Integer::operator<=(long long aLong) const {
  return theInteger <= Integer::longlongToMAPM(aLong);
}

bool Integer::operator<=(const Double& aDouble) const {
  switch(aDouble.theType) {
  case FloatConsts::INF_POS:
    return true;
    break;
  case FloatConsts::INF_NEG:
    return false;
    break;
  case FloatConsts::NOT_A_NUM:
    return false;
    break;
  default:
    return theInteger <= aDouble.theFloatImpl;
    break;
  }
}

bool Integer::operator>(const Decimal& aDecimal) const {
  return theInteger > aDecimal.theDecimal;
}

bool Integer::operator>(long long aLong) const {
  return theInteger > Integer::longlongToMAPM(aLong);
}

bool Integer::operator>=(const Decimal& aDecimal) const {
  return theInteger >= aDecimal.theDecimal;
}

bool Integer::operator>=(long long aLong) const {
  return theInteger >= Integer::longlongToMAPM(aLong);
}

bool Integer::operator>=(const Double& aDouble) const {
  switch(aDouble.theType) {
  case FloatConsts::INF_POS:
    return false;
    break;
  case FloatConsts::INF_NEG:
    return true;
    break;
  case FloatConsts::NOT_A_NUM:
    return false;
    break;
  default:
    return theInteger >= aDouble.theFloatImpl;
    break;
  }
}

xqpString Integer::toString() const {
  char lBuffer[1024];
  theInteger.toIntegerString(lBuffer);
  xqpString lResult = lBuffer;
  return lResult;
}

std::ostream& operator<<(std::ostream& os, const Integer& aInteger) {
  os << aInteger.toString();
  return os;
}

} // namespace xqp
