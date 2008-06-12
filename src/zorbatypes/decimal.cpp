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
#include "common/common.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/integer.h"
#include "zorbatypes/numconversions.h"

namespace zorba {

Decimal& Decimal::zero() {
  static Decimal lValue(MAPM(0));
  return lValue;
}

bool Decimal::parseString(const char* aCharStar, Decimal& aDecimal) {
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
#ifndef ZORBA_NO_BIGNUMBERS
    MAPM lNumber = aCharStar;
    aDecimal.theDecimal = lNumber;
    return true;
#else
    aDecimal.theDecimal = atof(aCharStar);
    return true;
#endif
  }
}

bool Decimal::parseNativeDouble(double aDouble, Decimal& aDecimal) {
  switch(Double::checkInfNaNNeg(aDouble)) {
  case FloatCommons::NORMAL:
  case FloatCommons::NORMAL_NEG:
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

Decimal Decimal::parseULong(unsigned long aULong) {
#ifndef ZORBA_NO_BIGNUMBERS
  MAPM lNumber = NumConversions::ulongToStr(aULong).c_str();
#else
  MAPM lNumber = aULong;
#endif
  return Decimal(lNumber);
}

Decimal Decimal::parseInteger(const Integer& aInteger) {
  Decimal lDecimal;
  lDecimal.theDecimal = aInteger.theInteger;
  return lDecimal;
}

Decimal Decimal::parseInt(int32_t aInt) {
  Decimal lDecimal;
  lDecimal.theDecimal = aInt;
  return lDecimal;
}

Decimal Decimal::parseUInt(uint32_t aUInt) {
#ifndef ZORBA_NO_BIGNUMBERS
  xqpString lStrRep = NumConversions::uintToStr(aUInt);
  Decimal lDecimal;
  lDecimal.theDecimal = lStrRep.c_str();
  return lDecimal;
#else
  Decimal lDecimal;
  lDecimal.theDecimal = aUInt;
  return lDecimal;
#endif
}

Decimal Decimal::parseLongLong(long long aLong) {
#ifndef ZORBA_NO_BIGNUMBERS
  xqpString lStrRep = NumConversions::longLongToStr(aLong);
  Decimal lDecimal;
  lDecimal.theDecimal = lStrRep.c_str();
  return lDecimal;
#else
  Decimal lDecimal;
  lDecimal.theDecimal = (MAPM)aLong;
  return lDecimal;
#endif
}

Decimal Decimal::parseULongLong(unsigned long long aULong) {
#ifndef ZORBA_NO_BIGNUMBERS
  xqpString lStrRep = NumConversions::ulongLongToStr(aULong);
  Decimal lDecimal;
  lDecimal.theDecimal = lStrRep.c_str();
  return lDecimal;
#else
  Decimal lDecimal;
  lDecimal.theDecimal = (MAPM)aULong;
  return lDecimal;
#endif
}

bool Decimal::parseFloat(const Float& aFloat, Decimal& aDecimal)
{
  if (!aFloat.isFinite() || aFloat.isNaN()) {
    return false;
  } else {
    aDecimal.theDecimal = aFloat.theFloatImpl;
    return true;
  }
}

bool Decimal::parseDouble(const Double& aDouble, Decimal& aDecimal)
{
  if (!aDouble.isFinite() || aDouble.isNaN()) {
    return false;
  } else {
    aDecimal.theDecimal = aDouble.theFloatImpl;
    return true;
  }
}

#ifndef ZORBA_NO_BIGNUMBERS
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
#else
MAPM Decimal::round(MAPM aValue, int aPrecision) 
{
  double  intpart;
  double  exp = modf(aValue, &intpart);
  double  prec = pow((double)10, aPrecision);
  exp *= prec;
  exp = ::floor(exp+0.5);
  return intpart + exp/prec;
}

MAPM Decimal::roundHalfToEven(MAPM aValue, int aPrecision) 
{
  double  intpart;
  double  exp = modf(aValue, &intpart);
  double  prec = pow((double)10, aPrecision);
  exp *= prec;
  bool  bHalfVal = false;
  if((exp-0.5) == ::floor(exp))
    bHalfVal = true;
  exp = ::floor(exp+0.5);
  if(bHalfVal && (((long long)exp)%2))
    exp--;
  return intpart + exp/prec;
}
#endif

Decimal& Decimal::operator=(const Decimal& aDecimal) {
  theDecimal = aDecimal.theDecimal;
  return *this;
}

Decimal Decimal::operator+(const Integer& aInteger) const {
  Decimal lResult(theDecimal + aInteger.theInteger);
  return lResult;
}

Decimal Decimal::operator+(const Decimal& aDecimal) const {
  Decimal lResult(theDecimal + aDecimal.theDecimal);
  return lResult;
}

Decimal& Decimal::operator+=(const Integer& aInteger) {
  theDecimal += aInteger.theInteger;
  return *this;
}

Decimal& Decimal::operator+=(const Decimal& aDecimal) {
  theDecimal += aDecimal.theDecimal;
  return *this;
}

Decimal Decimal::operator-(const Integer& aInteger) const {
  Decimal lResult(theDecimal - aInteger.theInteger);
  return lResult;
}

Decimal Decimal::operator-(const Decimal& aDecimal) const {
  Decimal lResult(theDecimal - aDecimal.theDecimal);
  return lResult;
}

Decimal& Decimal::operator-=(const Integer& aInteger) {
  theDecimal -= aInteger.theInteger;
  return *this;
}

Decimal& Decimal::operator-=(const Decimal& aDecimal) {
  theDecimal -= aDecimal.theDecimal;
  return *this;
}

Decimal Decimal::operator*(const Integer& aInteger) const {
  Decimal lResult(theDecimal * aInteger.theInteger);
  return lResult;
}

Decimal Decimal::operator*(const Decimal& aDecimal) const {
  Decimal lResult(theDecimal * aDecimal.theDecimal);
  return lResult;
}

Decimal& Decimal::operator*=(const Integer& aInteger) {
  theDecimal *= aInteger.theInteger;
  return *this;
}

Decimal& Decimal::operator*=(const Decimal& aDecimal) {
  theDecimal *= aDecimal.theDecimal;
  return *this;
}

Decimal Decimal::operator/(const Integer& aInteger) const {
  MAPM lRes = theDecimal / aInteger.theInteger;
  return Decimal(lRes);
}

Decimal Decimal::operator/(const Decimal& aDecimal) const {
  MAPM lRes = theDecimal / aDecimal.theDecimal;
  return Decimal(lRes);
}

Decimal& Decimal::operator/=(const Integer& aInteger) {
  theDecimal /= aInteger.theInteger;
  return *this;
}


Decimal& Decimal::operator/=(const Decimal& aDecimal) {
  theDecimal /= aDecimal.theDecimal;
  return *this;
}

Decimal Decimal::operator%(const Integer& aInteger) const {
  MAPM lRes = (IMAPM)theDecimal % aInteger.theInteger;
  return Decimal(lRes);
}

Decimal Decimal::operator%(const Decimal& aDecimal) const {
  MAPM lRes = (IMAPM)theDecimal % (IMAPM)aDecimal.theDecimal;
  return Decimal(lRes);
}

Decimal& Decimal::operator%=(const Integer& aInteger) {
  theDecimal = (IMAPM)theDecimal % aInteger.theInteger;
  return *this;
}

Decimal& Decimal::operator%=(const Decimal& aDecimal) {
  theDecimal = (IMAPM)theDecimal % (IMAPM)aDecimal.theDecimal;
  return *this;
}

Decimal Decimal::operator-() const {
  return Decimal(-theDecimal);
}

Decimal Decimal::round() const {
  return round(Integer::zero());
}

Decimal Decimal::round(Integer aPrecision) const {
  return Decimal(Decimal::round(theDecimal, aPrecision.theInteger));
}

Decimal Decimal::roundHalfToEven(Integer aPrecision) const {
  return Decimal(Decimal::roundHalfToEven(theDecimal, aPrecision.theInteger));
}

Decimal Decimal::sqrt() const {
#ifndef ZORBA_NO_BIGNUMBERS
  return Decimal (theDecimal.sqrt ());
#else
  return ::sqrt(theDecimal);
#endif
}

bool Decimal::operator==(const Integer& aInteger) const { 
  return theDecimal == aInteger.theInteger;
}

bool Decimal::operator!=(const Integer& aInteger) const { 
  return theDecimal != aInteger.theInteger;
}

bool Decimal::operator<(const Integer& aInteger) const { 
  return theDecimal < aInteger.theInteger;
}

bool Decimal::operator<=(const Integer& aInteger) const { 
  return theDecimal <= aInteger.theInteger;
}

bool Decimal::operator>(const Integer& aInteger) const { 
  return theDecimal > aInteger.theInteger;
}

bool Decimal::operator>=(const Integer& aInteger) const { 
  return theDecimal >= aInteger.theInteger;
}

xqpString Decimal::decimalToString(MAPM theValue) {
#ifndef ZORBA_NO_BIGNUMBERS
  char lBuffer[1024];
  theValue.toFixPtString(lBuffer, ZORBA_FLOAT_POINT_PRECISION);
#else
  char lBuffer[124];
//  char  lflags[20];
//  sprintf(lflags, "%%.%dlf", ZORBA_FLOAT_POINT_PRECISION);
  sprintf(lBuffer, "%.7lf", theValue);
#endif

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

xqpString Decimal::toIntegerString() const {
#ifndef ZORBA_NO_BIGNUMBERS
  char lBuffer[1024];
  theDecimal.toIntegerString(lBuffer);
#else
  char lBuffer[124];
  sprintf(lBuffer, "%d", (int)theDecimal);
#endif
  xqpString lResult = lBuffer;
  return lResult;
}

uint32_t Decimal::hash() const
{
#ifndef ZORBA_NO_BIGNUMBERS
  Decimal lDecimal(theDecimal %  65535);
  if (lDecimal < Decimal::zero())
    lDecimal = -lDecimal;
  Integer lInteger = Integer::parseDecimal(lDecimal);
  uint32_t lHash;
  NumConversions::integerToUInt(lInteger, lHash);
  return lHash;
#else
  return (((uint32_t)theDecimal)%65535);
#endif
}

std::ostream& operator<<(std::ostream& os, const Decimal& aDecimal) {
  os << aDecimal.toString();
  return os;
}

} // namespace zorba

