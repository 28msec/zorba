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
#include "stdafx.h"

#include "zorbatypes/integer.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/floatimpl.h"
#include "zorbatypes/numconversions.h"
#include "zorbaserialization/zorba_class_serializer.h"

#include <stdlib.h>

#undef  IS_ZERO
#undef  IS_POSITIVE
#undef  IS_POSITIVE_OR_ZERO
#undef  IS_NEGATIVE
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

namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(Integer)
END_SERIALIZABLE_CLASS_VERSIONS(Integer)


Integer& Integer::zero() 
{
  static Integer lValue(IMAPM(0));
  return lValue;
}


#ifdef ZORBA_NUMERIC_OPTIMIZATION
HashCharPtrObjPtrLimited<Integer>   Integer::parsed_integers;
#endif


bool Integer::parseString(const char* aCharStar, Integer& aInteger) 
{
#ifdef ZORBA_NUMERIC_OPTIMIZATION
  Integer *hashed_integer;
  if(parsed_integers.get(aCharStar, hashed_integer))
  {
    //found in hash
    aInteger.theInteger = hashed_integer->theInteger;
    return true;
  }
#endif
  // correctness check
  const char* lCur = aCharStar;
  bool lGotSign = false;
  bool lStop = false;
  bool lGotDigit = false;
  bool new_aCharStar = false;

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
        ptrdiff_t len = firstSpace - aCharStar + 1;
        char* copy = new char[len];
        strncpy(copy, aCharStar, len);
        copy[len-1] = 0;
        aCharStar = copy;
        new_aCharStar = true;
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
    if(new_aCharStar)
      delete[] aCharStar;
    return false;
  } 
  else 
  {
#ifndef ZORBA_NO_BIGNUMBERS
    aInteger.theInteger = aCharStar;
#else
    aInteger.theInteger = atoi(aCharStar);
#endif

#ifdef ZORBA_NUMERIC_OPTIMIZATION
    hashed_integer = new Integer(aInteger);
    const char  *dup_str = _strdup(aCharStar);
    parsed_integers.insert(dup_str, hashed_integer);
#endif
    if(new_aCharStar)
      delete[] aCharStar;
    return true;
  }
}


bool Integer::parseStringUnsigned(const char* aStarChar, Integer& aUInteger) 
{
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
#ifndef ZORBA_NO_BIGNUMBERS
    aUInteger.theInteger = aStarChar;
    return true;
#else
    aUInteger.theInteger = (IMAPM)atoi(aStarChar);
    return true;
#endif
  }
}

  
bool Integer::parseDouble(const Double& aDouble, Integer& aInteger) 
{
  if (aDouble.isFinite()) 
  {
    aInteger.theInteger = floatingToInteger(aDouble.theFloating);
    return true;
  }
  else 
  {
    return false;
  }
}


bool Integer::parseFloat(const Float& aFloat, Integer& aInteger) 
{
  if (aFloat.isFinite()) 
  {
    aInteger.theInteger = floatingToInteger(aFloat.theFloating);
    return true;
  }
  else
  {
    return false;
  }
}


Integer Integer::parseDecimal(const Decimal& aDecimal) 
{
  Integer lInteger(floatingToInteger(aDecimal.theDecimal));
  return lInteger;
}


Integer Integer::parseLong(int64_t aLong) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  zstring lStrRep = NumConversions::longToStr(aLong);
  MAPM lMAPM = lStrRep.c_str();
  return Integer(lMAPM);
#else
  return Integer((IMAPM)aLong);
#endif
}


Integer Integer::parseULong(uint64_t aULong) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  zstring lStrRep = NumConversions::ulongToStr(aULong);
  MAPM lMAPM = lStrRep.c_str();
  return Integer(lMAPM);
#else
  return Integer((IMAPM)aULong);
#endif
}


Integer Integer::parseInt(int32_t aInt) 
{
  MAPM lMAPM = aInt;
  Integer lInteger(lMAPM);
  return lInteger;
}


Integer Integer::parseUInt(uint32_t aUInt) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  zstring lStrRep = NumConversions::uintToStr(aUInt);
  MAPM lMAPM = lStrRep.c_str();
  return Integer(lMAPM);
#else
  return Integer((IMAPM)aUInt);
#endif
}


Integer Integer::parseSizeT(size_t aSizeT) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  zstring lStrRep = NumConversions::sizetToStr(aSizeT);
  MAPM lNumber = lStrRep.c_str();
  return Integer(lNumber);
#else
  return Integer((IMAPM)aSizeT);
#endif
}


void Integer::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theInteger;
}


Integer& Integer::operator=(const Integer& aInteger) 
{
  theInteger = aInteger.theInteger;
  return *this;
}


IMAPM Integer::floatingToInteger(MAPM theFloating) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  // TODO inf and nan handling
  if (IS_POSITIVE_OR_ZERO(theFloating))
    return theFloating.floor();
  else
    return theFloating.ceil();
#else
  return (IMAPM)theFloating;
#endif
}


Integer Integer::operator+(const Integer& aInteger) const 
{
  return Integer(theInteger + aInteger.theInteger);
}


Decimal Integer::operator+(const Decimal& aDecimal) const 
{
  return Decimal(theInteger + aDecimal.theDecimal);
}


Integer& Integer::operator+=(const Integer& aInteger) 
{
  theInteger += aInteger.theInteger;
  return *this;
}


Integer Integer::operator-(const Integer& aInteger) const 
{
  return Integer(theInteger - aInteger.theInteger);
}


Decimal Integer::operator-(const Decimal& aDecimal) const 
{
  return Decimal(theInteger - aDecimal.theDecimal);
}


Integer& Integer::operator-=(const Integer& aInteger) 
{
  theInteger -= aInteger.theInteger;
  return *this;
}


Integer Integer::operator*(const Integer& aInteger) const 
{
  return Integer(theInteger * aInteger.theInteger);
}


Decimal Integer::operator*(const Decimal& aDecimal) const 
{
  return Decimal(theInteger * aDecimal.theDecimal);
}


Integer& Integer::operator*=(const Integer& aInteger) 
{
  theInteger *= aInteger.theInteger;
  return *this;
}


Integer Integer::operator/(const Integer& aInteger) const 
{
  MAPM lRes = (MAPM)theInteger / aInteger.theInteger;
  lRes = floatingToInteger(lRes);
  return Integer(lRes);
}


Decimal Integer::operator/(const Decimal& aDecimal) const 
{
  MAPM lRes = (MAPM)theInteger / aDecimal.theDecimal;
  return Decimal(lRes);
}


Integer& Integer::operator/=(const Integer& aInteger) 
{
  theInteger /= (MAPM)aInteger.theInteger;
  theInteger = floatingToInteger(theInteger);
  return *this;
}


Integer Integer::operator%(const Integer& aInteger) const 
{
  MAPM lRes = theInteger % aInteger.theInteger;
  return Integer(lRes);
}


Decimal Integer::operator%(const Decimal& aDecimal) const 
{
  MAPM lRes = theInteger % (IMAPM)aDecimal.theDecimal;
  return Decimal(lRes);
}


Integer& Integer::operator%=(const Integer& aInteger) 
{
  theInteger %= aInteger.theInteger;
  return *this;
}


Integer Integer::operator-() const {
  return Integer(-theInteger);
}


Integer& Integer::operator++() {
  ++theInteger;
  return *this;
}


Integer& Integer::operator--() {
  --theInteger;
  return *this;
}


Integer Integer::operator++(int) {
  Integer lRes(theInteger);
  ++theInteger;
  return lRes;
}


Integer Integer::operator--(int) {
  Integer lRes(theInteger);
  --theInteger;
  return lRes;
}


Integer Integer::round(Integer aPrecision) const 
{
  return Integer(Decimal::round(theInteger, aPrecision.theInteger));
}


Integer Integer::roundHalfToEven(Integer aPrecision) const 
{
  return Integer(Decimal::roundHalfToEven(theInteger, aPrecision.theInteger));
}


Integer Integer::sqrt () const 
{
#ifndef ZORBA_NO_BIGNUMBERS
  return Integer (theInteger.sqrt ());
#else
  return Integer(::sqrt((double)theInteger));
#endif
}


Double  Integer::pow(Integer p) const
{
#ifndef ZORBA_NO_BIGNUMBERS
  MAPM result;
  result = theInteger.pow(p.theInteger, 15);
  char outbuf[300];
  result.toFixPtString(outbuf, 15);
  xs_double    double_result;
  xs_double::parseString(outbuf, double_result);
  return double_result;
#else
  return xs_double(::pow((double)theInteger, p.theInteger));
#endif
}

bool Integer::operator==(const Decimal& aDecimal) const 
{
  return theInteger == aDecimal.theDecimal;
}


bool Integer::operator!=(const Decimal& aDecimal) const 
{
  return theInteger != aDecimal.theDecimal;
}


bool Integer::operator<(const Decimal& aDecimal) const 
{
  return theInteger < aDecimal.theDecimal;
}


bool Integer::operator<=(const Decimal& aDecimal) const 
{
  return theInteger <= aDecimal.theDecimal;
}


bool Integer::operator<=(const Double& aDouble) const 
{
    return theInteger <= aDouble.theFloating;
}


bool Integer::operator>(const Decimal& aDecimal) const 
{
  return theInteger > aDecimal.theDecimal;
}


bool Integer::operator>=(const Decimal& aDecimal) const 
{
  return theInteger >= aDecimal.theDecimal;
}


bool Integer::operator>=(const Double& aDouble) const 
{
  return theInteger >= aDouble.theFloating;
}


zstring Integer::toString() const 
{
#ifndef ZORBA_NO_BIGNUMBERS
  char* lBuffer = new char[theInteger.exponent()+3];
  theInteger.toIntegerString(lBuffer);
  zstring lResult(lBuffer);
  delete[] lBuffer;
  return lResult;
#else
  char lBuffer[124];
  sprintf(lBuffer, "%d", theInteger);
  return lBuffer;
#endif
}


uint32_t Integer::hash() const
{
#ifndef ZORBA_NO_BIGNUMBERS
  char buffer[1024];
  char* bufferp = (theInteger.exponent() + 3 > 1024 ?
                   new char[theInteger.exponent() + 3] :
                   buffer);

  if (theInteger.sign() < 0)
  {
    if (theInteger >= MAPM::getMinInt64())
    {
      // hash it as int64
      theInteger.toIntegerString(bufferp);
      std::stringstream strstream(bufferp);
      int64_t longv;
      strstream >> longv;
      assert(strstream.eof());
      if (bufferp != buffer)
        delete bufferp;
      return static_cast<uint32_t>(longv & 0xffffffff);
    }
  }
  else if (theInteger <= MAPM::getMaxUInt64())
  {
    // hash it as uint64
    theInteger.toIntegerString(bufferp);
    std::stringstream strstream(bufferp);
    uint64_t longv;
    strstream >> longv;
    assert(strstream.eof());
    if (bufferp != buffer)
      delete bufferp;
    return static_cast<uint32_t>(longv & 0xffffffff);
  }

  // In all other cases, hash it as double
  theInteger.toFixPtString(bufferp, ZORBA_FLOAT_POINT_PRECISION);
  std::stringstream strstream(bufferp);
  double doublev;
  strstream >> doublev;
  assert(strstream.eof());
  if (bufferp != buffer)
    delete bufferp;
  return static_cast<uint32_t>(doublev);

#else
  return static_cast<uint32_t>(theInteger);
#endif
}


std::ostream& operator<<(std::ostream& os, const Integer& aInteger) 
{
  os << aInteger.toString();
  return os;
}


} // namespace zorba
