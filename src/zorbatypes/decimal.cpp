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

#include <limits>
#include "common/common.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/integer.h"
#include "zorbatypes/numconversions.h"
#include "zorbaserialization/zorba_class_serializer.h"

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

SERIALIZABLE_CLASS_VERSIONS(Decimal)
END_SERIALIZABLE_CLASS_VERSIONS(Decimal)


#ifdef ZORBA_NUMERIC_OPTIMIZATION
HashCharPtrObjPtrLimited<Decimal>   Decimal::parsed_decimals;
#endif


Decimal& Decimal::zero() 
{
  static Decimal lValue(MAPM(0));
  return lValue;
}


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
        int len = (int)(firstSpace - aCharStar + 1);
        char* copy = new char[firstSpace - aCharStar + 1];
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
    aDecimal.theDecimal = aCharStar;

#ifdef ZORBA_NUMERIC_OPTIMIZATION
    hashed_decimal = new Decimal(aDecimal);
    const char  *dup_str = _strdup(aCharStar);
    parsed_decimals.insert(dup_str, hashed_decimal);
#endif
    if(new_aCharStar)
      delete[] aCharStar;
    return true;
  }
}


bool Decimal::parseNativeDouble(double aDouble, Decimal& aDecimal) 
{
  if (aDouble == aDouble &&
      aDouble != std::numeric_limits<double>::infinity() &&
      aDouble != -std::numeric_limits<double>::infinity())
  {
    aDecimal.theDecimal = aDouble;
    return true;
  }
  else
  {
    return false;
  }
}


bool Decimal::parseFloat(const Float& aFloat, Decimal& aDecimal)
{
  if (aFloat.isFinite()) 
  {
    aDecimal.theDecimal = aFloat.theFloating;
    return true;
  } 
  else
  {
    return false;
  }
}


bool Decimal::parseDouble(const Double& aDouble, Decimal& aDecimal)
{
  if (aDouble.isFinite()) 
  {
    aDecimal.theDecimal = aDouble.theFloating;
    return true;
  }
  else
  {
    return false;
  }
}


Decimal Decimal::parseInteger(const Integer& aInteger) 
{
  Decimal lDecimal(aInteger.theInteger);
  return lDecimal;
}


Decimal Decimal::parseLongLong(int64_t aLong) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  zstring lStrRep = NumConversions::longToStr(aLong);
  Decimal lDecimal;
  lDecimal.theDecimal = lStrRep.c_str();
  return lDecimal;
#else
  Decimal lDecimal;
  lDecimal.theDecimal = (MAPM)aLong;
  return lDecimal;
#endif
}


Decimal Decimal::parseULongLong(uint64_t aULong) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  zstring lStrRep = NumConversions::ulongToStr(aULong);
  Decimal lDecimal;
  lDecimal.theDecimal = lStrRep.c_str();
  return lDecimal;
#else
  Decimal lDecimal;
  lDecimal.theDecimal = (MAPM)aULong;
  return lDecimal;
#endif
}


Decimal Decimal::parseInt(int32_t aInt) 
{
  Decimal lDecimal;
  lDecimal.theDecimal = aInt;
  return lDecimal;
}


Decimal Decimal::parseUInt(uint32_t aUInt) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  zstring lStrRep = NumConversions::uintToStr(aUInt);
  Decimal lDecimal;
  lDecimal.theDecimal = lStrRep.c_str();
  return lDecimal;
#else
  Decimal lDecimal;
  lDecimal.theDecimal = aUInt;
  return lDecimal;
#endif
}


#ifndef ZORBA_NO_BIGNUMBERS
MAPM Decimal::round(const MAPM& aValue, const MAPM& aPrecision) 
{
  MAPM aExp = MAPM(10).pow(aPrecision);
  MAPM aCur = aValue * aExp;
  aCur += MAPM::get0_5();
  aCur = aCur.floor();
  aCur /= aExp;
  return aCur;
}


MAPM Decimal::roundHalfToEven(const MAPM &aValue, const MAPM &aPrecision) 
{
  MAPM aExp = MAPM(10).pow(aPrecision);
  MAPM aCur = aValue * aExp;
  bool aHalfVal;
  aHalfVal = ((aCur - MAPM::get0_5()) == aCur.floor());
  aCur += MAPM::get0_5();
  aCur = aCur.floor();
  if (aHalfVal && aCur.is_odd()) 
  {
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
    return aValue;
  }
}
#endif


zstring Decimal::decimalToString(MAPM theValue, int precision) 
{
  bool do_reduce = false;
#ifndef ZORBA_NO_BIGNUMBERS
  char lBuffer[1024];
  theValue.toFixPtString(lBuffer, precision);

  if (precision < ZORBA_FLOAT_POINT_PRECISION)
    do_reduce = true;
#else
  char lBuffer[174];
  if(theValue == 0)
    sprintf(lBuffer, "0");
  //else if(fabs(theValue) < 1.0e-10)
  //  sprintf(lBuffer, "%.20lf", theValue);
  else
    sprintf(lBuffer, "%.16lf", theValue);
  do_reduce = true;
#endif

  // Note in the canonical representation the decimal point is required
  // and there must be at least one digit to the right and one digit to 
  // the left of the decimal point (which may be 0)
  if(strchr(lBuffer,'.') != 0) 
  {
    // remove trailing 0's
    char* lastChar = lBuffer + strlen(lBuffer) - 1;

    while(*lastChar == '0') 
    {
      *lastChar--=0;
    }
    // remove decimal point, if there are no digits after it
    if(*lastChar == '.')
      *lastChar = 0;
  }
  //+debug
/*
  char str1[100];
  strcpy(str1, "9.99999");
  Decimal::reduceFloatingPointString(str1);
  strcpy(str1, "9.999999999");
  Decimal::reduceFloatingPointString(str1);
  strcpy(str1, "9.999999999E12");
  Decimal::reduceFloatingPointString(str1);
  strcpy(str1, "-9.999999999E12");
  Decimal::reduceFloatingPointString(str1);
  strcpy(str1, "9.99919999");
  Decimal::reduceFloatingPointString(str1);
  strcpy(str1, "9.0000000001");
  Decimal::reduceFloatingPointString(str1);
  strcpy(str1, "0.000009999998");
  Decimal::reduceFloatingPointString(str1);
*/

  if(do_reduce)
    Decimal::reduceFloatingPointString(lBuffer);

  return lBuffer;
}

/*
    Remove trailing .99999 or .000001.
    Find four or five consecutive 9 or 0 after decimal point and eliminate them.
*/
void Decimal::reduceFloatingPointString(char *str)
{
  char *strDot = strrchr(str, '.');
  if(!strDot)
    return;//not a floating point number
  char *lE = strrchr(str, 'E');
  int len = (int)strlen(str);
  bool has_E = false;
  if(!lE)
    lE = strrchr(str, 'e');
  if(!lE)
    lE = str + len;
  else
    has_E = true;
  char *digit_ptr = lE-1;
  int pos = (int)(digit_ptr - strDot);
  while(pos > 8) //(*digit_ptr != '.')
  {
    if(*digit_ptr == '9')
    {
      if((digit_ptr[-1] == '9') && (digit_ptr[-2] == '9') && (digit_ptr[-3] == '9'))
      {
        if(isdigit(digit_ptr[1]) && (digit_ptr[1] >= '5'))
          digit_ptr -= 4;
        else if(digit_ptr[-4] == '9')
          digit_ptr -= 5;
        else
          goto nextDigit;
        //now add 1 to remaining digits
        char *last_digit = digit_ptr;
        while(digit_ptr >= str)
        {
          if(digit_ptr[0] == '.')
          {//skip
          }
          else if(digit_ptr[0] == '9')
          {
            digit_ptr[0] = '0';
            if(last_digit == digit_ptr)
              last_digit--;
          }
          else
          {
            if(isdigit(digit_ptr[0]))
              digit_ptr[0]++;
            break;
          }
          digit_ptr--;
        }
        if(last_digit[0] != '.')
          last_digit++;
        else if(has_E)
        {
          last_digit[1] = '0';
          last_digit += 2;
        }
        if((digit_ptr < str) || !isdigit(digit_ptr[0]))
        {
          memmove(str+1, str, (last_digit-str));
          last_digit++;
          if(isdigit(str[0]))
            str[0] = '1';
          else
            str[1] = '1';
          if(has_E)
          {
            //increment the Exponent
            strDot++;
            strDot[0] = strDot[-1];
            strDot[-1] = '.';
            int expon = atoi(lE+1);
            expon++;
            sprintf(lE+1, "%d", expon);
            last_digit--;
          }
        }
        memmove(last_digit, lE, strlen(lE));
        last_digit[strlen(lE)] = 0;
        break;
      }
    }
    else if(*digit_ptr == '0')
    {
      if((digit_ptr[-1] == '0') && (digit_ptr[-2] == '0') && (digit_ptr[-3] == '0'))
      {
        if(isdigit(digit_ptr[1]) && (digit_ptr[1] < '5'))
          digit_ptr -= 4;
        else if(digit_ptr[-4] == '0')
          digit_ptr -= 5;
        else
          goto nextDigit;
        while(*digit_ptr == '0')
          digit_ptr--;
        if(*digit_ptr != '.')
          digit_ptr++;
        else if(has_E)
        {
          digit_ptr[1] = '0';
          digit_ptr += 2;
        }
        memmove(digit_ptr, lE, strlen(lE));
        digit_ptr[strlen(lE)] = 0;
        break;
      }
    }
nextDigit:
    digit_ptr--;
    pos--;
  }
}


void Decimal::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theDecimal;
}


Decimal& Decimal::operator=(const Decimal& aDecimal) 
{
  theDecimal = aDecimal.theDecimal;
  return *this;
}


Decimal Decimal::operator+(const Integer& aInteger) const 
{
  return Decimal(theDecimal + aInteger.theInteger);
}


Decimal Decimal::operator+(const Decimal& aDecimal) const 
{
  return Decimal(theDecimal + aDecimal.theDecimal);
}


Decimal& Decimal::operator+=(const Integer& aInteger) 
{
  theDecimal += aInteger.theInteger;
  return *this;
}


Decimal& Decimal::operator+=(const Decimal& aDecimal) 
{
  theDecimal += aDecimal.theDecimal;
  return *this;
}


Decimal Decimal::operator-(const Integer& aInteger) const 
{
  return Decimal(theDecimal - aInteger.theInteger);
}


Decimal Decimal::operator-(const Decimal& aDecimal) const 
{
  return Decimal(theDecimal - aDecimal.theDecimal);
}


Decimal& Decimal::operator-=(const Integer& aInteger) 
{
  theDecimal -= aInteger.theInteger;
  return *this;
}


Decimal& Decimal::operator-=(const Decimal& aDecimal) 
{
  theDecimal -= aDecimal.theDecimal;
  return *this;
}


Decimal Decimal::operator*(const Integer& aInteger) const 
{
  return Decimal(theDecimal * aInteger.theInteger);
}


Decimal Decimal::operator*(const Decimal& aDecimal) const 
{
  return Decimal(theDecimal * aDecimal.theDecimal);
}


Decimal& Decimal::operator*=(const Integer& aInteger) 
{
  theDecimal *= aInteger.theInteger;
  return *this;
}


Decimal& Decimal::operator*=(const Decimal& aDecimal) 
{
  theDecimal *= aDecimal.theDecimal;
  return *this;
}


Decimal Decimal::operator/(const Integer& aInteger) const 
{
  MAPM lRes = theDecimal / aInteger.theInteger;
  return Decimal(lRes);
}


Decimal Decimal::operator/(const Decimal& aDecimal) const 
{
  MAPM lRes = theDecimal / aDecimal.theDecimal;
  return Decimal(lRes);
}


Decimal& Decimal::operator/=(const Integer& aInteger) 
{
  theDecimal /= aInteger.theInteger;
  return *this;
}


Decimal& Decimal::operator/=(const Decimal& aDecimal) 
{
  theDecimal /= aDecimal.theDecimal;
  return *this;
}


Decimal Decimal::operator%(const Integer& aInteger) const 
{
#ifndef ZORBA_NO_BIGNUMBERS
  MAPM lRes = theDecimal % aInteger.theInteger;
#else
  MAPM lRes = fmod(theDecimal, aInteger.theInteger);
#endif
  return Decimal(lRes);
}


Decimal Decimal::operator%(const Decimal& aDecimal) const 
{
#ifndef ZORBA_NO_BIGNUMBERS
  MAPM lRes = theDecimal % aDecimal.theDecimal;
#else
  MAPM lRes = fmod(theDecimal, aDecimal.theDecimal);
#endif
  return Decimal(lRes);
}


Decimal& Decimal::operator%=(const Integer& aInteger) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  theDecimal = theDecimal % aInteger.theInteger;
#else
  theDecimal = fmod(theDecimal, aInteger.theInteger);
#endif
  return *this;
}


Decimal& Decimal::operator%=(const Decimal& aDecimal) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  theDecimal = theDecimal % aDecimal.theDecimal;
#else
  MAPM lRes = fmod(theDecimal, aDecimal.theDecimal);
#endif
  return *this;
}


Decimal Decimal::operator-() const 
{
  return Decimal(-theDecimal);
}


Decimal Decimal::round() const 
{
  return round(Integer::zero());
}


Decimal Decimal::round(Integer aPrecision) const 
{
  return Decimal(Decimal::round(theDecimal, aPrecision.theInteger));
}


Decimal Decimal::roundHalfToEven(Integer aPrecision) const 
{
  return Decimal(Decimal::roundHalfToEven(theDecimal, aPrecision.theInteger));
}


Decimal Decimal::sqrt() const 
{
#ifndef ZORBA_NO_BIGNUMBERS
  return Decimal (theDecimal.sqrt ());
#else
  return ::sqrt(theDecimal);
#endif
}


bool Decimal::operator==(const Integer& aInteger) const 
{ 
  return theDecimal == aInteger.theInteger;
}


bool Decimal::operator!=(const Integer& aInteger) const 
{ 
  return theDecimal != aInteger.theInteger;
}


bool Decimal::operator<(const Integer& aInteger) const 
{ 
  return theDecimal < aInteger.theInteger;
}


bool Decimal::operator<=(const Integer& aInteger) const 
{ 
  return theDecimal <= aInteger.theInteger;
}


bool Decimal::operator>(const Integer& aInteger) const 
{ 
  return theDecimal > aInteger.theInteger;
}


bool Decimal::operator>=(const Integer& aInteger) const 
{ 
  return theDecimal >= aInteger.theInteger;
}


uint32_t Decimal::hash() const
{
#ifndef ZORBA_NO_BIGNUMBERS
  char buffer[1024];
  char* bufferp = (theDecimal.exponent() + 3 > 1024 ?
                   new char[theDecimal.exponent() + 3] :
                   buffer);

  if (theDecimal.is_integer())
  {
    if (theDecimal.sign() < 0)
    {
      if (theDecimal >= MAPM::getMinInt64())
      {
        // hash it as int64
        theDecimal.toIntegerString(bufferp);
        std::stringstream strstream(bufferp);
        int64_t longv;
        strstream >> longv;
        assert(strstream.eof());
        if (bufferp != buffer)
          delete bufferp;
        return static_cast<uint32_t>(longv & 0xffffffff);
      }
    }
    else if (theDecimal <= MAPM::getMaxUInt64())
    {
      // hash it as uint64
      theDecimal.toIntegerString(bufferp);
      std::stringstream strstream(bufferp);
      uint64_t longv;
      strstream >> longv;
      assert(strstream.eof());
      if (bufferp != buffer)
        delete bufferp;
      return static_cast<uint32_t>(longv & 0xffffffff);
    }
  }

  // In all other cases, hash it as double
  theDecimal.toFixPtString(bufferp, ZORBA_FLOAT_POINT_PRECISION);
  std::stringstream strstream(bufferp);
  double doublev;
  strstream >> doublev;
  assert(strstream.eof());
  if (bufferp != buffer)
    delete bufferp;
  return static_cast<uint32_t>(doublev);

#else
  return (((uint32_t)theDecimal)%65535);
#endif
}


zstring Decimal::toString() const 
{
  return decimalToString(theDecimal);
}


zstring Decimal::toIntegerString() const 
{
#ifndef ZORBA_NO_BIGNUMBERS
  char lBuffer[1024];
  theDecimal.toIntegerString(lBuffer);
#else
  char lBuffer[124];
  sprintf(lBuffer, "%d", (int)theDecimal);
#endif
  return lBuffer;
}


int Decimal::getValueAsInt() const
{
  zstring strtemp = toIntegerString();
  return atoi(strtemp.c_str());
}



std::ostream& operator<<(std::ostream& os, const Decimal& aDecimal) 
{
  os << aDecimal.toString();
  return os;
}



} // namespace zorba

