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

#include <sstream>
#include <limits>
#include "zorbatypes/numconversions.h"

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


bool NumConversions::strToDouble(const char* aStr, xqp_double& aDouble)
{
  return Double::parseString(aStr, aDouble);
}
  

bool NumConversions::strToFloat(const char* aStr, xqp_float& aFloat) 
{
  return Float::parseString(aStr, aFloat);
}


bool NumConversions::strToDecimal(const char* aStr, xqp_decimal& aDecimal)
{
  return Decimal::parseString(aStr, aDecimal);
}


bool NumConversions::strToInteger(const char* aStr, xqp_integer& aInteger) 
{
  return Integer::parseString(aStr, aInteger);
}


bool NumConversions::strToUInteger(const char* aStr, xqp_uinteger& aUInteger)
{
  return Integer::parseStringUnsigned(aStr, aUInteger);
}


bool NumConversions::strToLong(const char* aStr, xqp_long& aLong)
{
  std::stringstream lStream;
  return lStream << aStr && lStream >> aLong && lStream.eof();
}


bool NumConversions::strToULong(const char* aStr, xqp_ulong& aULong)
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


bool NumConversions::strToInt(const char* aCharStar, xqp_int& aInt)
{
  std::stringstream lStream;
  return lStream << aCharStar && lStream >> aInt && lStream.eof();
}


bool NumConversions::strToUInt(const char* aStr, xqp_uint& aUInt)
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


bool NumConversions::strToShort(const char* aStr, xqp_short& aShort)
{
  std::stringstream lStream;
  return lStream << aStr && lStream >> aShort && lStream.eof();
}


bool NumConversions::strToUShort(const char* aStr, xqp_ushort& aUShort)
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


bool NumConversions::strToByte(const char* aStr, xqp_byte& aByte)
{
  short lShort;
  if (strToShort(aStr, lShort)) 
  {
    if (lShort >= -128 && lShort <= 127)
    {
      aByte = (xqp_byte)lShort;
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


bool NumConversions::strToUByte(const char* aStr, xqp_ubyte& aUByte)
{
  unsigned short lUShort;
  if (strToUShort(aStr, lUShort))
  {
    if (lUShort <= 255) 
    {
      aUByte = (xqp_ubyte)lUShort;
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


xqpStringStore_t NumConversions::doubleToStr(xqp_double aDouble)
{
  return aDouble.toString();
}


xqpStringStore_t NumConversions::floatToStr(xqp_float aFloat)
{
  return aFloat.toString();
}


xqpStringStore_t NumConversions::decimalToStr(xqp_decimal aDecimal)
{
  return aDecimal.toString();
}


xqpStringStore_t NumConversions::integerToStr(xqp_integer aInteger)
{
  return aInteger.toString();
}


xqpStringStore_t NumConversions::uintegerToStr(xqp_uinteger aUInteger)
{
  return aUInteger.toString();
}


xqpStringStore_t NumConversions::longToStr(xqp_long aLong)
{
  std::stringstream lStream;
  lStream << aLong;
  return new xqpStringStore(lStream.str());
}


xqpStringStore_t NumConversions::ulongToStr(xqp_ulong aULong)
{
  std::stringstream lStream;
  lStream << aULong;
  return new xqpStringStore(lStream.str());
}


xqpStringStore_t NumConversions::intToStr(xqp_int aInt)
{
  std::stringstream lStream;
  lStream << aInt;
  return new xqpStringStore(lStream.str());
}


xqpStringStore_t NumConversions::uintToStr(xqp_uint aUInt)
{
  std::stringstream lStream;
  lStream << aUInt;
  return new xqpStringStore(lStream.str());
}


xqpStringStore_t NumConversions::shortToStr(xqp_short aShort)
{
  std::stringstream lStream;
  lStream << aShort;
  return new xqpStringStore(lStream.str());
}


xqpStringStore_t NumConversions::ushortToStr(xqp_ushort aUShort)
{
  std::stringstream lStream;
  lStream << aUShort;
  return new xqpStringStore(lStream.str());
}

  
xqpStringStore_t NumConversions::byteToStr(xqp_byte aByte)
{
  return shortToStr(aByte);
}
  

xqpStringStore_t NumConversions::ubyteToStr(xqp_ubyte aUByte)
{
  return ushortToStr(aUByte);
}

  
xqpStringStore_t NumConversions::sizetToStr(size_t aSizeT) 
{
  std::stringstream lStream;
  lStream << aSizeT;
  return new xqpStringStore(lStream.str());
}


bool NumConversions::doubleToLong(const xqp_double& aDouble, xqp_long& aLong) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  xqpStringStore_t lStr = aDouble.toIntegerString();
  return NumConversions::strToLong(lStr->c_str(), aLong);
#else
  aLong = (xqp_long)aDouble.theFloating;
  return true;
#endif
}

 
bool NumConversions::doubleToInt(const xqp_double& aDouble, xqp_int& aInt) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  xqpStringStore_t lStr = aDouble.toIntegerString();
  return NumConversions::strToInt(lStr->c_str(), aInt);
#else
  aInt = (xqp_int)aDouble.theFloating;
  return true;
#endif
}


bool NumConversions::floatToInt(const xqp_float& aFloat, xqp_int& aInt) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  xqpStringStore_t lStr = aFloat.toIntegerString();
  return NumConversions::strToInt(lStr->c_str(), aInt);
#else
  aInt = (xqp_int)aFloat.theFloating;
  return true;
#endif
}


bool NumConversions::decimalToInteger(const xqp_decimal& aDecimal, xqp_integer& aInteger)
{
#ifndef ZORBA_NO_BIGNUMBERS
  if (aDecimal.isInteger())
  {
    xqpStringStore_t lStr = aDecimal.toString();
    return NumConversions::strToInteger(lStr->c_str(), aInteger);
  }
  else
  {
    return false;
  }
#else
  ZORBA_ASSERT(false);
#endif
}


bool NumConversions::decimalToULong(const xqp_decimal& aDecimal, xqp_ulong& aULong)
{
#ifndef ZORBA_NO_BIGNUMBERS
  if (aDecimal.isULong())
  {
    xqpStringStore_t lStr = aDecimal.toString();
    return NumConversions::strToULong(lStr->c_str(), aULong);
  }
  else
  {
    return false;
  }
#else
  ZORBA_ASSERT(false);
#endif
}


bool NumConversions::decimalToLong(const xqp_decimal& aDecimal, xqp_long& aLong)
{
#ifndef ZORBA_NO_BIGNUMBERS
  if (aDecimal.isLong())
  {
    xqpStringStore_t lStr = aDecimal.toString();
    return NumConversions::strToLong(lStr->c_str(), aLong);
  }
  else
  {
    return false;
  }
#else
  ZORBA_ASSERT(false);
#endif
}


bool NumConversions::decimalToUInt(const xqp_decimal& aDecimal, xqp_uint& aUInt)
{
#ifndef ZORBA_NO_BIGNUMBERS
  if (aDecimal.isUInt())
  {
    xqpStringStore_t lStr = aDecimal.toString();
    return NumConversions::strToUInt(lStr->c_str(), aUInt);
  }
  else
  {
    return false;
  }
#else
  ZORBA_ASSERT(false);
#endif
}


bool NumConversions::decimalToInt(const xqp_decimal& aDecimal, xqp_int& aInt) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  if (aDecimal.isInt())
  {
    xqpStringStore_t lStr = aDecimal.toString();
    return NumConversions::strToInt(lStr->c_str(), aInt);
  }
  else
  {
    return false;
  }
#else
  ZORBA_ASSERT(false);
#endif
}

  
bool NumConversions::integerToLong(const xqp_integer& aInteger, xqp_long& aLong) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  if (aInteger.isLong())
  {
    xqpStringStore_t lStr = aInteger.toString();
    return NumConversions::strToLong(lStr->c_str(), aLong);
  }
  else
  {
    return false;
  }
#else
  aLong = (xqp_uint)aInteger.theInteger;
  return true;
#endif
}


bool NumConversions::integerToUInt(const xqp_integer& aInteger, xqp_uint& aUInt) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  if (aInteger.isUInt())
  {
    xqpStringStore_t lStr = aInteger.toString();
    return NumConversions::strToUInt(lStr->c_str(), aUInt);
  }
  else
  {
    return false;
  }
#else
  aUInt = (xqp_uint)aInteger.theInteger;
  return true;
#endif
}


bool NumConversions::integerToInt(const xqp_integer& aInteger, xqp_int& aInt) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  if (aInteger.isInt())
  {
    xqpStringStore_t lStr = aInteger.toString();
    return NumConversions::strToInt(lStr->c_str(), aInt);
  }
  else
  {
    return false;
  }
#else
  aInt = (xqp_int)aInteger.theInteger;
  return true;
#endif
}


bool NumConversions::longToDouble(const xqp_long& aLong, xqp_double& aDouble)
{
  double d = static_cast<double>(aLong);

  if (aLong == static_cast<xqp_long>(d))
  {
    aDouble = d;
    return true;
  }
  else
  {
    return false;
  }
}


} /* namespace zorba */
