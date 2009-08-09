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
#include <limits>
#include "common/common.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/integer.h"
#include "zorbatypes/numconversions.h"

#ifndef ZORBA_NO_BIGNUMBERS
#define IS_ZERO(mapm_obj)                 (mapm_obj.sign() == 0)
#define IS_POSITIVE(mapm_obj)             (mapm_obj.sign() > 0)
#define IS_POSITIVE_OR_ZERO(mapm_obj)     (mapm_obj.sign() >= 0)
#define IS_NEGATIVE(mapm_obj)             (mapm_obj.sign() < 0)
#else
#define IS_ZERO(mapm_obj)                 (mapm_obj == 0)
#define IS_POSITIVE(mapm_obj)             (mapm_obj > 0)
#define IS_POSITIVE_OR_ZERO(mapm_obj)     (mapm_obj >= 0)
#define IS_NEGATIVE(mapm_obj)             (mapm_obj < 0)
#endif

namespace zorba {
SERIALIZABLE_CLASS_VERSIONS(Decimal)
END_SERIALIZABLE_CLASS_VERSIONS(Decimal)


Decimal& Decimal::zero() {
  static Decimal lValue(MAPM(0));
  return lValue;
}

#ifdef ZORBA_NUMERIC_OPTIMIZATION
HashCharPtrObjPtrLimited<Decimal>   Decimal::parsed_decimals;
#endif

bool Decimal::parseString(const char* aCharStar, Decimal& aDecimal) 
{
#ifdef ZORBA_NUMERIC_OPTIMIZATION
  Decimal *hashed_decimal;
  if(parsed_decimals.get(aCharStar, hashed_decimal))
  {
    //found in hash
    aDecimal.theDecimal = hashed_decimal->theDecimal;
    return true;
  }
#endif
  // correctness check
  const char* lCur = aCharStar;
  bool lGotPoint = false;
  bool lGotSign = false;
  bool lStop = false;
  bool lGotDigit = false;
  bool lGotSpace = false;

  char ch = *lCur;

  // Skip leading space
  while (ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n')
  {
    ++lCur;
    aCharStar++;
    ch = *lCur;
  }

  while (*lCur != '\0' && !lStop) 
  {
    ch = *lCur;

    switch(ch) 
    {
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
      
    case ' ':
    case '\t':
    case '\n':
    case '\r':
    {
      const char* firstSpace = lCur;
        
      // Skip trailing space
      while(ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n') 
      {
        ++lCur;
        ch = *lCur;
      }
      
      if (*lCur != 0)
      {
        lStop = true;
      }
      else
      {
        int len = firstSpace - aCharStar + 1;
        char* copy = new char[firstSpace - aCharStar + 1];
        strncpy(copy, aCharStar, len);
        copy[len-1] = 0;
        aCharStar = copy;
        lCur--;
      }
      
      break;
    }

    default:
      lStop = true;
      break;
    }

    lCur++;
  }

  if (lStop || !lGotDigit) 
  {
    return false;
  }
  else
  {
#ifndef ZORBA_NO_BIGNUMBERS
    aDecimal.theDecimal = aCharStar;
#else
    aDecimal.theDecimal = atof(aCharStar);
    if(aDecimal.theDecimal == -0)
      aDecimal.theDecimal = 0;
#endif

    if (lGotSpace)
      delete [] aCharStar;

#ifdef ZORBA_NUMERIC_OPTIMIZATION
    hashed_decimal = new Decimal(aDecimal);
    const char  *dup_str = _strdup(aCharStar);
    parsed_decimals.insert(dup_str, hashed_decimal);
#endif
    return true;
  }
}

bool Decimal::parseNativeDouble(double aDouble, Decimal& aDecimal) {
  if (
       aDouble == aDouble
    && aDouble != std::numeric_limits<double>::infinity()
    && aDouble != -std::numeric_limits<double>::infinity()
  ) {
    aDecimal.theDecimal = aDouble;
    return true;
  }
  else {
    return false;
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
  if (aFloat.isFinite()) {
    aDecimal.theDecimal = aFloat.theFloating;
    return true;
  } 
  else {
    return false;
  }
}

bool Decimal::parseDouble(const Double& aDouble, Decimal& aDecimal)
{
  if (aDouble.isFinite()) {
    aDecimal.theDecimal = aDouble.theFloating;
    return true;
  }
  else {
    return false;
  }
}

#ifndef ZORBA_NO_BIGNUMBERS

MAPM    mapm_0_5 = 0.5;

MAPM Decimal::round(const MAPM &aValue, const MAPM &aPrecision) {
  MAPM aExp = MAPM(10).pow(aPrecision);
  MAPM aCur = aValue * aExp;
  aCur += mapm_0_5;
  aCur = aCur.floor();
  aCur /= aExp;
  return aCur;
}

MAPM Decimal::roundHalfToEven(const MAPM &aValue, const MAPM &aPrecision) {
  MAPM aExp = MAPM(10).pow(aPrecision);
  MAPM aCur = aValue * aExp;
  bool aHalfVal;
  aHalfVal = ((aCur - mapm_0_5) == aCur.floor());
  aCur += mapm_0_5;
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
  if(aPrecision >= 0)
  {
    double  intpart;
    double  exp = modf(aValue, &intpart);
    double  prec = pow((double)10, aPrecision);
    exp *= prec;
    exp = ::floor(exp+0.5);
    return intpart + exp/prec;
  }
  else
  {
    double  prec = pow((double)10, -aPrecision);
    aValue  /= prec;
    return ::floor(aValue+0.5)*prec;
  }
}

MAPM Decimal::roundHalfToEven(MAPM aValue, int aPrecision) 
{
  if(aPrecision >= 0)
  {
    double  intpart;
    double  exp = modf(aValue, &intpart);
    double  prec = pow((double)10, aPrecision);
    exp *= prec;
    bool  bHalfVal = false;

    if((exp-0.5) == ::floor(exp))
    {
      if(aPrecision == 0)
        return ((long long)intpart)%2 ? intpart+1 : intpart;
      bHalfVal = true;
    }
    exp = ::floor(exp+0.5);
    if(bHalfVal && (((long long)exp)%2))
      exp--;
    return intpart + exp/prec;
  }
  else
  {
    double  prec = pow((double)10, -aPrecision);
    aValue /= prec;
    if((aValue-0.5) == ::floor(aValue))
    {
      return (((long long)aValue)%2) ? ::ceil(aValue)*prec : ::floor(aValue)*prec;
    }
    aValue = ::floor(aValue+0.5);
    if(bHalfVal && (((long long)aValue)%2))
      aValue--;
    return aValue;
  }
}
#endif

Decimal& Decimal::operator=(const Decimal& aDecimal) {
  theDecimal = aDecimal.theDecimal;
  return *this;
}

Decimal Decimal::operator+(const Integer& aInteger) const {
  return Decimal(theDecimal + aInteger.theInteger);
}

Decimal Decimal::operator+(const Decimal& aDecimal) const {
  return Decimal(theDecimal + aDecimal.theDecimal);
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
  return Decimal(theDecimal - aInteger.theInteger);
}

Decimal Decimal::operator-(const Decimal& aDecimal) const {
  return Decimal(theDecimal - aDecimal.theDecimal);
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
  return Decimal(theDecimal * aInteger.theInteger);
}

Decimal Decimal::operator*(const Decimal& aDecimal) const {
  return Decimal(theDecimal * aDecimal.theDecimal);
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
#ifndef ZORBA_NO_BIGNUMBERS
  MAPM lRes = theDecimal % aInteger.theInteger;
#else
  MAPM lRes = fmod(theDecimal, aInteger.theInteger);
#endif
  return Decimal(lRes);
}

Decimal Decimal::operator%(const Decimal& aDecimal) const {
#ifndef ZORBA_NO_BIGNUMBERS
  MAPM lRes = theDecimal % aDecimal.theDecimal;
#else
  MAPM lRes = fmod(theDecimal, aDecimal.theDecimal);
#endif
  return Decimal(lRes);
}

Decimal& Decimal::operator%=(const Integer& aInteger) {
#ifndef ZORBA_NO_BIGNUMBERS
  theDecimal = theDecimal % aInteger.theInteger;
#else
  theDecimal = fmod(theDecimal, aInteger.theInteger);
#endif
  return *this;
}

Decimal& Decimal::operator%=(const Decimal& aDecimal) {
#ifndef ZORBA_NO_BIGNUMBERS
  theDecimal = theDecimal % aDecimal.theDecimal;
#else
  MAPM lRes = fmod(theDecimal, aDecimal.theDecimal);
#endif
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

xqpString Decimal::decimalToString(MAPM theValue, int precision) {
#ifndef ZORBA_NO_BIGNUMBERS
  char lBuffer[1024];
 theValue.toFixPtString(lBuffer, precision);
#else
  char lBuffer[174];
  if(theValue == 0)
    sprintf(lBuffer, "0");
  //else if(fabs(theValue) < 1.0e-10)
  //  sprintf(lBuffer, "%.20lf", theValue);
  else
    sprintf(lBuffer, "%.16lf", theValue);
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

MAPM mapm_65535(65535);
uint32_t Decimal::hash() const
{
#ifndef ZORBA_NO_BIGNUMBERS
  Decimal lDecimal(theDecimal %  mapm_65535);
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

