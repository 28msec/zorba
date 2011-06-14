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

#include "common/common.h"

#include <sstream>
#include <limits>
#include "zorbatypes/numconversions.h"
#include "diagnostics/assert.h"

namespace zorba 
{


bool NumConversions::isNegative(const char*& chp, bool& isNegZero) 
{
  isNegZero = false;

  char ch = *chp;

  while (ch != '\0' && 
         (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r'))
  {
    ++chp;
    ch = *chp;
  }

  if (ch == '-')
  {
    while (ch != '\0' && ch == '0')
    {
      ++chp;
      ch = *chp;
    }

    if (ch == '\0')
    {
      isNegZero = true;
      return false;
    }

    return true;
  }

  return false;
}


bool NumConversions::strToDouble(const char* aStr, xs_double& aDouble)
{
  return Double::parseString(aStr, aDouble);
}
  

bool NumConversions::strToFloat(const char* aStr, xs_float& aFloat) 
{
  return Float::parseString(aStr, aFloat);
}


bool NumConversions::strToDecimal(const char* aStr, xs_decimal& aDecimal)
{
  try {
    aDecimal = aStr;
    return true;
  }
  catch ( std::invalid_argument const& ) {
    return false;
  }
}


bool NumConversions::strToInteger(const char* aStr, xs_integer& aInteger) 
{
  try {
    aInteger = aStr;
    return true;
  }
  catch ( std::invalid_argument const& ) {
    return false;
  }
}


bool NumConversions::strToUInteger(const char* aStr, xs_uinteger& aUInteger)
{
  try {
    xs_integer const temp( aStr );
    if ( temp.sign() >= 0 ) {
      aUInteger = temp;
      return true;
    }
  }
  catch ( std::invalid_argument const& ) {
    // ignore
  }
  return false;
}


bool NumConversions::strToLong(const char* aStr, xs_long& aLong)
{
  std::stringstream lStream;
  return lStream << aStr && lStream >> aLong && lStream.eof();
}


bool NumConversions::strToULong(const char* aStr, xs_unsignedLong& aULong)
{
  const char* chp = aStr;
  bool negZero;

  if (isNegative(chp, negZero))
  {
    return false;
  }

  if (negZero)
  {
    aULong = 0;
    return true;
  }

  std::stringstream lStream;
  return lStream << chp && lStream >> aULong && lStream.eof();
}


bool NumConversions::strToInt(const char* aCharStar, xs_int& aInt)
{
  std::stringstream lStream;
  return lStream << aCharStar && lStream >> aInt && lStream.eof();
}


bool NumConversions::strToUInt(const char* aStr, xs_unsignedInt& aUInt)
{
  const char* chp = aStr;
  bool negZero;

  if (isNegative(chp, negZero))
  {
    return false;
  }

  if (negZero)
  {
    aUInt = 0;
    return true;
  }

  std::stringstream lStream;
  return lStream << aStr && lStream >> aUInt && lStream.eof();
}


bool NumConversions::strToShort(const char* aStr, xs_short& aShort)
{
  std::stringstream lStream;
  return lStream << aStr && lStream >> aShort && lStream.eof();
}


bool NumConversions::strToUShort(const char* aStr, xs_unsignedShort& aUShort)
{
  const char* chp = aStr;
  bool negZero;

  if (isNegative(chp, negZero))
  {
    return false;
  }

  if (negZero)
  {
    aUShort = 0;
    return true;
  }

  std::stringstream lStream;
  return lStream << aStr && lStream >> aUShort && lStream.eof();
}


bool NumConversions::strToByte(const char* aStr, xs_byte& aByte)
{
  short lShort;
  if (strToShort(aStr, lShort)) 
  {
    if (lShort >= -128 && lShort <= 127)
    {
      aByte = (xs_byte)lShort;
      return true;
    } 
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}


bool NumConversions::strToUByte(const char* aStr, xs_unsignedByte& aUByte)
{
  unsigned short lUShort;
  if (strToUShort(aStr, lUShort))
  {
    if (lUShort <= 255) 
    {
      aUByte = (xs_unsignedByte)lUShort;
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}


zstring NumConversions::doubleToStr(xs_double aDouble)
{
  return aDouble.toString();
}


zstring NumConversions::floatToStr(xs_float aFloat)
{
  return aFloat.toString();
}


zstring NumConversions::decimalToStr(xs_decimal aDecimal)
{
  return aDecimal.toString();
}


zstring NumConversions::integerToStr(xs_integer aInteger)
{
  return aInteger.toString();
}


zstring NumConversions::uintegerToStr(xs_uinteger aUInteger)
{
  return aUInteger.toString();
}


zstring NumConversions::longToStr(xs_long aLong)
{
  std::stringstream lStream;
  lStream << aLong;
  return lStream.str();
}


zstring NumConversions::ulongToStr(xs_unsignedLong aULong)
{
  std::stringstream lStream;
  lStream << aULong;
  return lStream.str();
}


zstring NumConversions::intToStr(xs_int aInt)
{
  std::stringstream lStream;
  lStream << aInt;
  return lStream.str();
}


zstring NumConversions::uintToStr(xs_unsignedInt aUInt)
{
  std::stringstream lStream;
  lStream << aUInt;
  return lStream.str();
}


zstring NumConversions::shortToStr(xs_short aShort)
{
  std::stringstream lStream;
  lStream << aShort;
  return lStream.str();
}


zstring NumConversions::ushortToStr(xs_unsignedShort aUShort)
{
  std::stringstream lStream;
  lStream << aUShort;
  return lStream.str();
}

  
zstring NumConversions::byteToStr(xs_byte aByte)
{
  return shortToStr(aByte);
}
  

zstring NumConversions::ubyteToStr(xs_unsignedByte aUByte)
{
  return ushortToStr(aUByte);
}

  
zstring NumConversions::sizetToStr(size_t aSizeT) 
{
  std::stringstream lStream;
  lStream << aSizeT;
  return lStream.str();
}


bool NumConversions::doubleToLong(const xs_double& aDouble, xs_long& aLong) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  zstring lStr = aDouble.toIntegerString();
  return NumConversions::strToLong(lStr.c_str(), aLong);
#else
  aLong = (xs_long)aDouble.theFloating;
  return true;
#endif
}

 
bool NumConversions::doubleToInt(const xs_double& aDouble, xs_int& aInt) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  zstring lStr = aDouble.toIntegerString();
  return NumConversions::strToInt(lStr.c_str(), aInt);
#else
  aInt = (xs_int)aDouble.theFloating;
  return true;
#endif
}


bool NumConversions::floatToInt(const xs_float& aFloat, xs_int& aInt) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  zstring lStr = aFloat.toIntegerString();
  return NumConversions::strToInt(lStr.c_str(), aInt);
#else
  aInt = (xs_int)aFloat.theFloating;
  return true;
#endif
}


bool NumConversions::decimalToInteger(const xs_decimal& aDecimal, xs_integer& aInteger)
{
#ifndef ZORBA_NO_BIGNUMBERS
  if (aDecimal.is_integer())
  {
    zstring lStr = aDecimal.toString();
    return NumConversions::strToInteger(lStr.c_str(), aInteger);
  }
  else
  {
    return false;
  }
#else
  ZORBA_ASSERT(false);
#endif
}


bool NumConversions::decimalToULong(const xs_decimal& aDecimal, xs_unsignedLong& aULong)
{
#ifndef ZORBA_NO_BIGNUMBERS
  if (aDecimal.is_xs_ulong())
  {
    zstring lStr = aDecimal.toString();
    return NumConversions::strToULong(lStr.c_str(), aULong);
  }
  else
  {
    return false;
  }
#else
  ZORBA_ASSERT(false);
#endif
}


bool NumConversions::decimalToLong(const xs_decimal& aDecimal, xs_long& aLong)
{
#ifndef ZORBA_NO_BIGNUMBERS
  if (aDecimal.is_xs_long())
  {
    zstring lStr = aDecimal.toString();
    return NumConversions::strToLong(lStr.c_str(), aLong);
  }
  else
  {
    return false;
  }
#else
  ZORBA_ASSERT(false);
#endif
}


bool NumConversions::decimalToUInt(const xs_decimal& aDecimal, xs_unsignedInt& aUInt)
{
#ifndef ZORBA_NO_BIGNUMBERS
  if (aDecimal.is_xs_uint())
  {
    zstring lStr = aDecimal.toString();
    return NumConversions::strToUInt(lStr.c_str(), aUInt);
  }
  else
  {
    return false;
  }
#else
  ZORBA_ASSERT(false);
#endif
}


bool NumConversions::decimalToInt(const xs_decimal& aDecimal, xs_int& aInt) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  if (aDecimal.is_xs_int())
  {
    zstring lStr = aDecimal.toString();
    return NumConversions::strToInt(lStr.c_str(), aInt);
  }
  else
  {
    return false;
  }
#else
  ZORBA_ASSERT(false);
#endif
}

  
bool NumConversions::integerToLong(const xs_integer& aInteger, xs_long& aLong) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  if (aInteger.is_xs_long())
  {
    zstring lStr = aInteger.toString();
    return NumConversions::strToLong(lStr.c_str(), aLong);
  }
  else
  {
    return false;
  }
#else
  aLong = (xs_unsignedInt)aInteger.value_;
  return true;
#endif
}


bool NumConversions::integerToUInt(const xs_integer& aInteger, xs_unsignedInt& aUInt) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  if (aInteger.is_xs_uint())
  {
    zstring lStr = aInteger.toString();
    return NumConversions::strToUInt(lStr.c_str(), aUInt);
  }
  else
  {
    return false;
  }
#else
  aUInt = (xs_unsignedInt)aInteger.value_;
  return true;
#endif
}


bool NumConversions::integerToInt(const xs_integer& aInteger, xs_int& aInt) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  if (aInteger.is_xs_int())
  {
    zstring lStr = aInteger.toString();
    return NumConversions::strToInt(lStr.c_str(), aInt);
  }
  else
  {
    return false;
  }
#else
  aInt = (xs_int)aInteger.value_;
  return true;
#endif
}


bool NumConversions::longToDouble(const xs_long& aLong, xs_double& aDouble)
{
  double d = static_cast<double>(aLong);

  if (aLong == static_cast<xs_long>(d))
  {
    aDouble = d;
    return true;
  }
  else
  {
    return false;
  }
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
