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


bool NumConversions::isNegZero(const xqpStringStore_t& aStr) 
{
  xqpStringStore_t lStr = aStr->trim(" \n\r\t", 4);
  size_t lLength = lStr->bytes();
  const char* lChars = lStr->c_str();
  if (lChars[0] == '-') 
  {
    for (size_t i = 1; i < lLength; ++i) 
    {
      if (lChars[i] != '0') 
      {
        return false;
      }
    }
    return true;
  }
  else
  {
    return false;
  }
}


bool NumConversions::starCharToInteger(const char* aCharStar, xqp_integer& aInteger) 
{
  return Integer::parseString(aCharStar, aInteger);
}


bool NumConversions::strToInteger(const xqpStringStore_t& aStr, xqp_integer& aInteger)
{
  return starCharToInteger(aStr->c_str(), aInteger);
}


xqpStringStore_t NumConversions::integerToStr(xqp_integer aInteger)
{
  return aInteger.toString();
}


bool NumConversions::strToUInteger(const xqpStringStore_t& aStr, xqp_uinteger& aUInteger)
{
  return Integer::parseStringUnsigned(aStr->c_str(), aUInteger);
}


xqpStringStore_t NumConversions::uintegerToStr(xqp_uinteger aUInteger)
{
  return aUInteger.toString();
}


bool NumConversions::starCharToInt(const char* aCharStar, xqp_int& aInt)
{
  std::stringstream lStream;
  return lStream << aCharStar && lStream >> aInt && lStream.eof();
}


bool NumConversions::strToInt(const xqpStringStore_t& aStr, xqp_int& aInt) 
{
  return starCharToInt(aStr->c_str(), aInt);
}


xqpStringStore_t NumConversions::intToStr(xqp_int aInt)
{
  std::stringstream lStream;
  lStream << aInt;
  return new xqpStringStore(lStream.str());
}


bool NumConversions::strToUInt(const xqpStringStore_t& aStr, xqp_uint& aUInt)
{
  if ( isNegZero(aStr)) 
  {
    aUInt = 0;
    return true;
  }
  std::stringstream lStream;
  return lStream << aStr->c_str() && lStream >> aUInt && lStream.eof();
}


xqpStringStore_t NumConversions::uintToStr(xqp_uint aUInt)
{
  std::stringstream lStream;
  lStream << aUInt;
  return new xqpStringStore(lStream.str());
}


bool NumConversions::strToLongLong(const xqpStringStore_t& aStr, xqp_long& aLong)
{
  std::stringstream lStream;
  return lStream << aStr->c_str() && lStream >> aLong && lStream.eof();
}


xqpStringStore_t NumConversions::longLongToStr(xqp_long aLong)
{
  std::stringstream lStream;
  lStream << aLong;
  return new xqpStringStore(lStream.str());
}


bool NumConversions::strToLong(const xqpStringStore_t& aStr, long& aLong)
{
  std::stringstream lStream;
  return lStream << aStr->c_str() && lStream >> aLong && lStream.eof();
}
  

xqpStringStore_t NumConversions::longToStr(long aLong) 
{
  std::stringstream lStream;
  lStream << aLong;
  return new xqpStringStore(lStream.str());
}


bool NumConversions::strToULongLong(const xqpStringStore_t& aStr, xqp_ulong& aULong)
{
  if ( isNegZero(aStr))
  {
    aULong = 0;
    return true;
  }
  std::stringstream lStream;
  return lStream << aStr->c_str() && lStream >> aULong && lStream.eof();
}


xqpStringStore_t NumConversions::ulongLongToStr(xqp_ulong aULong)
{
  std::stringstream lStream;
  lStream << aULong;
  return new xqpStringStore(lStream.str());
}


xqpStringStore_t NumConversions::ulongToStr(unsigned long aULong) 
{
  std::stringstream lStream;
  lStream << aULong;
  return new xqpStringStore(lStream.str());
}


bool NumConversions::strToShort(const xqpStringStore_t& aStr, xqp_short& aShort)
{
  std::stringstream lStream;
  return lStream << aStr->c_str() && lStream >> aShort && lStream.eof();
}


xqpStringStore_t NumConversions::shortToStr(xqp_short aShort)
{
  std::stringstream lStream;
  lStream << aShort;
  return new xqpStringStore(lStream.str());
}


bool NumConversions::strToUShort(const xqpStringStore_t& aStr, xqp_ushort& aUShort)
{
  if ( isNegZero(aStr )) 
  {
    aUShort = 0;
    return true;
  }
  std::stringstream lStream;
  return lStream << aStr->c_str() && lStream >> aUShort && lStream.eof();
}


xqpStringStore_t NumConversions::ushortToStr(xqp_ushort aUShort)
{
  std::stringstream lStream;
  lStream << aUShort;
  return new xqpStringStore(lStream.str());
}


bool NumConversions::starCharToDecimal(const char* aCharStar, xqp_decimal& aDecimal)
{
  return Decimal::parseString(aCharStar, aDecimal);
}


bool NumConversions::strToDecimal(const xqpStringStore_t& aStr, xqp_decimal& aDecimal) 
{
  return starCharToDecimal(aStr->c_str(), aDecimal);
}
  

xqpStringStore_t NumConversions::decimalToStr(xqp_decimal aDecimal)
{
  return aDecimal.toString();
}

  
bool NumConversions::starCharToFloat(const char* aCharStar, xqp_float& aFloat) 
{
  return Float::parseString(aCharStar, aFloat);
}


bool NumConversions::strToFloat(const xqpStringStore_t& aStr, xqp_float& aFloat)
{
  return NumConversions::starCharToFloat(aStr->c_str(), aFloat);
}


xqpStringStore_t NumConversions::floatToStr(xqp_float aFloat)
{
  return aFloat.toString();
}


bool NumConversions::starCharToDouble(const char* aCharStar, xqp_double& aDouble)
{
  return Double::parseString(aCharStar, aDouble);
}
  

bool NumConversions::strToDouble(const xqpStringStore_t& aStr, xqp_double& aDouble) 
{
  return starCharToDouble(aStr->c_str(), aDouble);
}
  

xqpStringStore_t NumConversions::doubleToStr(xqp_double aDouble)
{
  return aDouble.toString();
}

  
bool NumConversions::strToByte(const xqpStringStore_t& aStr, xqp_byte& aByte)
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
      return false;
  }
  else
    return false;
}
  

xqpStringStore_t NumConversions::byteToStr(xqp_byte aByte)
{
  return shortToStr(aByte);
}
  

bool NumConversions::strToUByte(const xqpStringStore_t& aStr, xqp_ubyte& aUByte)
{
  unsigned short lUShort;
  if (strToUShort(aStr, lUShort)) 
  {
    if (lUShort <= 255) {
      aUByte = (xqp_ubyte)lUShort;
      return true;
    }
    else
      return false;
  }
  else
    return false;
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

 
bool NumConversions::doubleToInt(const xqp_double& aDouble, xqp_int& aInt) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  xqpStringStore_t lStr = aDouble.toIntegerString();
  return NumConversions::strToInt(lStr, aInt);
#else
  aInt = (xqp_int)aDouble.theFloating;
  return true;
#endif
}

  
bool NumConversions::doubleToLongLong(const xqp_double& aDouble, xqp_long& aLong) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  xqpStringStore_t lStr = aDouble.toIntegerString();
  return NumConversions::strToLongLong(lStr, aLong);
#else
  aLong = (xqp_long)aDouble.theFloating;
  return true;
#endif
}

  
bool NumConversions::doubleToLong(const xqp_double& aDouble, long& aLong) 
{
#ifndef ZORBA_NO_BIGNUMBERS
    xqpStringStore_t lStr = aDouble.toIntegerString();
    return NumConversions::strToLong(lStr, aLong);
#else
    aLong = (long)aDouble.theFloating;
    return true;
#endif
}


bool NumConversions::integerToLong(const xqp_integer& aInteger, xqp_long& aLong) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  xqpStringStore_t lStr = aInteger.toString();
  return NumConversions::strToLongLong(lStr, aLong);
#else
  aLong = (xqp_uint)aInteger.theInteger;
  return true;
#endif
}


bool NumConversions::integerToUInt(const xqp_integer& aInteger, xqp_uint& aUInt) 
{
#ifndef ZORBA_NO_BIGNUMBERS
  xqpStringStore_t lStr = aInteger.toString();
  return NumConversions::strToUInt(lStr, aUInt);
#else
  aUInt = (xqp_uint)aInteger.theInteger;
  return true;
#endif
}

  
bool NumConversions::floatToInt(const xqp_float& aFloat, xqp_int& aInt) 
{
#ifndef ZORBA_NO_BIGNUMBERS
    xqpStringStore_t lStr = aFloat.toIntegerString();
    return NumConversions::strToInt(lStr, aInt);
#else
    aInt = (xqp_int)aFloat.theFloating;
    return true;
#endif
}

  
bool NumConversions::decimalToInt(const xqp_decimal& aDecimal, xqp_int& aInt) 
{
#ifndef ZORBA_NO_BIGNUMBERS
    xqpStringStore_t lStr = aDecimal.toIntegerString();
    return NumConversions::strToInt(lStr, aInt);
#else
    aInt = (xqp_int)aDecimal.theDecimal;
    return true;
#endif
}

} /* namespace zorba */
