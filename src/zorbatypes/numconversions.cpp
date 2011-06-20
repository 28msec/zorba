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


bool NumConversions::strToUInteger(const char* aStr, xs_uinteger& aUInteger)
{
  try {
    xs_integer const temp( aStr );
    if ( temp.sign() >= 0 ) {
      aUInteger = temp;
      return true;
    }
  }
  catch ( std::exception const& ) {
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
  if (strToShort(aStr, lShort)) {
    if (lShort >= -128 && lShort <= 127) {
      aByte = (xs_byte)lShort;
      return true;
    } 
  }
  return false;
}


bool NumConversions::strToUByte(const char* aStr, xs_unsignedByte& aUByte)
{
  unsigned short lUShort;
  if (strToUShort(aStr, lUShort)) {
    if (lUShort <= 255) {
      aUByte = (xs_unsignedByte)lUShort;
      return true;
    }
  }
  return false;
}


bool NumConversions::doubleToLong(const xs_double& aDouble, xs_long& aLong) 
{
  zstring lStr = aDouble.toIntegerString();
  return strToLong(lStr.c_str(), aLong);
}

 
bool NumConversions::doubleToInt(const xs_double& aDouble, xs_int& aInt) 
{
  zstring lStr = aDouble.toIntegerString();
  return NumConversions::strToInt(lStr.c_str(), aInt);
}


bool NumConversions::floatToInt(const xs_float& aFloat, xs_int& aInt) 
{
  zstring lStr = aFloat.toIntegerString();
  return NumConversions::strToInt(lStr.c_str(), aInt);
}


bool NumConversions::decimalToInteger(const xs_decimal& aDecimal, xs_integer& aInteger)
{
  if (aDecimal.is_integer()) {
    zstring const lStr( aDecimal.toString() );
    try {
      aInteger = lStr.c_str();
      return true;
    }
    catch ( std::exception const& ) {
    }
  }
  return false;
}


bool NumConversions::decimalToULong(const xs_decimal& aDecimal, xs_unsignedLong& aULong)
{
  if (aDecimal.is_xs_ulong())
  {
    zstring lStr = aDecimal.toString();
    return strToULong(lStr.c_str(), aULong);
  }
  else
  {
    return false;
  }
}


bool NumConversions::decimalToLong(const xs_decimal& aDecimal, xs_long& aLong)
{
  if (aDecimal.is_xs_long())
  {
    zstring lStr = aDecimal.toString();
    return strToLong(lStr.c_str(), aLong);
  }
  else
  {
    return false;
  }
}


bool NumConversions::decimalToUInt(const xs_decimal& aDecimal, xs_unsignedInt& aUInt)
{
  if (aDecimal.is_xs_uint())
  {
    zstring lStr = aDecimal.toString();
    return NumConversions::strToUInt(lStr.c_str(), aUInt);
  }
  else
  {
    return false;
  }
}


bool NumConversions::decimalToInt(const xs_decimal& aDecimal, xs_int& aInt) 
{
  if (aDecimal.is_xs_int())
  {
    zstring lStr = aDecimal.toString();
    return NumConversions::strToInt(lStr.c_str(), aInt);
  }
  else
  {
    return false;
  }
}

  
bool NumConversions::integerToLong(const xs_integer& aInteger, xs_long& aLong) 
{
#ifdef ZORBA_WITH_BIG_INTEGER
  if (aInteger.is_xs_long()) {
    zstring lStr = aInteger.toString();
    return strToLong(lStr.c_str(), aLong);
  }
  return false;
#else
  aLong = static_cast<xs_long>(aInteger.value_);
  return true;
#endif
}


bool NumConversions::integerToUInt(const xs_integer& aInteger, xs_unsignedInt& aUInt) 
{
#ifdef ZORBA_WITH_BIG_INTEGER
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
  aUInt = static_cast<xs_unsignedInt>(aInteger.value_);
  return true;
#endif
}


bool NumConversions::integerToInt(const xs_integer& aInteger, xs_int& aInt) 
{
#ifdef ZORBA_WITH_BIG_INTEGER
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
  aInt = static_cast<xs_int>(aInteger.value_);
  return true;
#endif
}



} // namespace zorba
/* vim:set et sw=2 ts=2: */
