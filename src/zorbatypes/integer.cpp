/*
 * Copyright 2008 FLWOR Foundation.
 *
 * Authros: David Graf (davidgraf@28msec.com)
 */

#include <zorbatypes/integer.h>
#include <zorbatypes/decimal.h>
#include <zorbatypes/floatimpl.h>
#include <zorbatypes/numconversions.h>

namespace xqp {

Integer& Integer::zero() {
  static Integer lValue(MAPM(0));
  return lValue;
}

bool Integer::parseString(const char* aCharStar, Integer& aInteger) {
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

bool Integer::parseStringUnsigned(const char* aStarChar, Integer& aUInteger) {
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
  
bool Integer::parseDouble(const Double& aDouble, Integer& aInteger) {
  switch(aDouble.theType) {
  case FloatCommons::NORMAL:
  case FloatCommons::NORMAL_NEG:
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

bool Integer::parseFloat(const Float& aFloat, Integer& aInteger) {
  switch(aFloat.theType) {
  case FloatCommons::NORMAL:
  case FloatCommons::NORMAL_NEG:
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

Integer Integer::parseDecimal(const Decimal& aDecimal) {
  Integer lInteger(floatingToInteger(aDecimal.theDecimal));
  return lInteger;
}

Integer Integer::parseLongLong(long long aLong) {
  xqpString lStrRep = NumConversions::longLongToStr(aLong);
  MAPM lMAPM = lStrRep.c_str();
  Integer lInteger(lMAPM);
  return lInteger;
}

Integer Integer::parseULongLong(unsigned long long aULong) {
  xqpString lStrRep = NumConversions::ulongLongToStr(aULong);
  MAPM lMAPM = lStrRep.c_str();
  Integer lInteger(lMAPM);
  return lInteger;
}

Integer Integer::parseInt(int32_t aInt) {
  MAPM lMAPM = aInt;
  Integer lInteger(lMAPM);
  return lInteger;
}

Integer Integer::parseUInt(uint32_t aUInt) {
  xqpString lStrRep = NumConversions::uintToStr(aUInt);
  MAPM lMAPM = lStrRep.c_str();
  Integer lInteger(lMAPM);
  return lInteger;
}

Integer Integer::parseLong(long aLong) { 
  MAPM lNumber = aLong;
  return Integer(lNumber);
}

Integer Integer::parseULong(unsigned long aULong) {
  xqpString lStrRep = NumConversions::ulongLongToStr(aULong);
  MAPM lNumber = lStrRep.c_str();
  return Integer(lNumber);
}
Integer Integer::parseSizeT(size_t aSizeT) {
  xqpString lStrRep = NumConversions::sizetToStr(aSizeT);
  MAPM lNumber = lStrRep.c_str();
  return Integer(lNumber);
}


Integer& Integer::operator=(const Integer& aInteger) {
  theInteger = aInteger.theInteger;
  return *this;
}

MAPM Integer::longlongToMAPM(long long aLong) {
  xqpString lStrRep = NumConversions::longLongToStr(aLong);
  return MAPM(lStrRep.c_str());
}

Integer Integer::operator+(const Integer& aInteger) const {
  Integer lResult(theInteger + aInteger.theInteger);
  return lResult;
}

Decimal Integer::operator+(const Decimal& aDecimal) const {
  Decimal lResult(theInteger + aDecimal.theDecimal);
  return lResult;
}

Integer& Integer::operator+=(const Integer& aInteger) {
  theInteger += aInteger.theInteger;
  return *this;
}

Integer Integer::operator-(const Integer& aInteger) const {
  Integer lResult(theInteger - aInteger.theInteger);
  return lResult;
}

Decimal Integer::operator-(const Decimal& aDecimal) const {
  Decimal lResult(theInteger - aDecimal.theDecimal);
  return lResult;
}

Integer& Integer::operator-=(const Integer& aInteger) {
  theInteger -= aInteger.theInteger;
  return *this;
}

Integer Integer::operator*(const Integer& aInteger) const {
  Integer lResult(theInteger * aInteger.theInteger);
  return lResult;
}

Decimal Integer::operator*(const Decimal& aDecimal) const {
  Decimal lResult(theInteger * aDecimal.theDecimal);
  return lResult;
}

Integer& Integer::operator*=(const Integer& aInteger) {
  theInteger *= aInteger.theInteger;
  return *this;
}

Integer Integer::operator/(const Integer& aInteger) const {
  MAPM lRes = theInteger / aInteger.theInteger;
  lRes = floatingToInteger(lRes);
  return Integer(lRes);
}

Decimal Integer::operator/(const Decimal& aDecimal) const {
  MAPM lRes = theInteger / aDecimal.theDecimal;
  return Decimal(lRes);
}

Integer& Integer::operator/=(const Integer& aInteger) {
  theInteger /= aInteger.theInteger;
  theInteger = floatingToInteger(theInteger);
  return *this;
}

Integer Integer::operator%(const Integer& aInteger) const {
  MAPM lRes = theInteger % aInteger.theInteger;
  return Integer(lRes);
}

Decimal Integer::operator%(const Decimal& aDecimal) const {
  MAPM lRes = theInteger % aDecimal.theDecimal;
  return Decimal(lRes);
}

Integer& Integer::operator%=(const Integer& aInteger) {
  theInteger %= aInteger.theInteger;
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

bool Integer::operator!=(const Decimal& aDecimal) const {
  return theInteger != aDecimal.theDecimal;
}

bool Integer::operator<(const Decimal& aDecimal) const {
  return theInteger < aDecimal.theDecimal;
}

bool Integer::operator<=(const Decimal& aDecimal) const {
  return theInteger <= aDecimal.theDecimal;
}

bool Integer::operator<=(const Double& aDouble) const {
  switch(aDouble.theType) {
  case FloatCommons::INF_POS:
    return true;
    break;
  case FloatCommons::INF_NEG:
    return false;
    break;
  case FloatCommons::NOT_A_NUM:
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

bool Integer::operator>=(const Decimal& aDecimal) const {
  return theInteger >= aDecimal.theDecimal;
}

bool Integer::operator>=(const Double& aDouble) const {
  switch(aDouble.theType) {
  case FloatCommons::INF_POS:
    return false;
    break;
  case FloatCommons::INF_NEG:
    return true;
    break;
  case FloatCommons::NOT_A_NUM:
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
