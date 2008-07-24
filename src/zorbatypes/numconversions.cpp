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

namespace zorba {
  bool NumConversions::isNegZero(const xqpString& aStr) {
    xqpString lStr = aStr.trim(" \n\r\t", 4);
    size_t lLength = aStr.length();
    const char* lChars = aStr.c_str();
    if (lChars[0] == '-') {
      for(size_t i = 1; i < lLength; ++i) {
        if (lChars[i] != '0') {
          return false;
        }
      }
      return true;
    } else {
      return false;
    }
  }

  bool NumConversions::starCharToInteger(const char* aCharStar, xqp_integer& aInteger) {
    return Integer::parseString(aCharStar, aInteger);
  }

  bool NumConversions::strToInteger(const xqpString& aStr, xqp_integer& aInteger){
    return starCharToInteger(aStr.c_str(), aInteger);
  }
  xqpString NumConversions::integerToStr(xqp_integer aInteger){
    return aInteger.toString();
  }
  bool NumConversions::strToUInteger(const xqpString& aStr, xqp_uinteger& aUInteger){
    return Integer::parseStringUnsigned(aStr.c_str(), aUInteger);
  }
  xqpString NumConversions::uintegerToStr(xqp_uinteger aUInteger){
    return aUInteger.toString();
  }
  bool NumConversions::starCharToInt(const char* aCharStar, xqp_int& aInt){
    std::stringstream lStream;
    return lStream << aCharStar && lStream >> aInt && lStream.get() == EOF;
  }
  bool NumConversions::strToInt(const xqpString& aStr, xqp_int& aInt) {
    return starCharToInt(aStr.c_str(), aInt);
  }
  xqpString NumConversions::intToStr(xqp_int aInt){
    std::stringstream lStream;
    lStream << aInt;
    return lStream.str();
  }
  bool NumConversions::strToUInt(const xqpString& aStr, xqp_uint& aUInt){
    if ( isNegZero(aStr)) {
      aUInt = 0;
      return true;
    }
    std::stringstream lStream;
    return lStream << aStr.c_str() && lStream >> aUInt && lStream.get() == EOF;
  }
  xqpString NumConversions::uintToStr(xqp_uint aUInt){
    std::stringstream lStream;
    lStream << aUInt;
    return lStream.str();
  }
  bool NumConversions::strToLongLong(const xqpString& aStr, xqp_long& aLong){
    std::stringstream lStream;
    return lStream << aStr.c_str() && lStream >> aLong && lStream.get() == EOF;
  }
  xqpString NumConversions::longLongToStr(xqp_long aLong){
    std::stringstream lStream;
    lStream << aLong;
    return lStream.str();
  }
  bool NumConversions::strToLong(const xqpString& aStr, long& aLong){
    std::stringstream lStream;
    return lStream << aStr.c_str() && lStream >> aLong && lStream.get() == EOF;
  }
  xqpString NumConversions::longToStr(long aLong) {
    std::stringstream lStream;
    lStream << aLong;
    return lStream.str();
  }
  bool NumConversions::strToULongLong(const xqpString& aStr, xqp_ulong& aULong){
    if ( isNegZero(aStr)) {
      aULong = 0;
      return true;
    }
    std::stringstream lStream;
    return lStream << aStr.c_str() && lStream >> aULong && lStream.get() == EOF;
  }
  xqpString NumConversions::ulongLongToStr(xqp_ulong aULong){
    std::stringstream lStream;
    lStream << aULong;
    return lStream.str();
  }
  xqpString NumConversions::ulongToStr(unsigned long aULong) {
    std::stringstream lStream;
    lStream << aULong;
    return lStream.str();
  }
  bool NumConversions::strToShort(const xqpString& aStr, xqp_short& aShort){
    std::stringstream lStream;
    return lStream << aStr.c_str() && lStream >> aShort && lStream.get() == EOF;
  }
  xqpString NumConversions::shortToStr(xqp_short aShort){
    std::stringstream lStream;
    lStream << aShort;
    return lStream.str();
  }
  bool NumConversions::strToUShort(const xqpString& aStr, xqp_ushort& aUShort){
    if ( isNegZero(aStr )) {
      aUShort = 0;
      return true;
    }
    std::stringstream lStream;
    return lStream << aStr.c_str() && lStream >> aUShort && lStream.get() == EOF;
  }
  xqpString NumConversions::ushortToStr(xqp_ushort aUShort){
    std::stringstream lStream;
    lStream << aUShort;
    return lStream.str();
  }
  bool NumConversions::starCharToDecimal(const char* aCharStar, xqp_decimal& aDecimal){
    return Decimal::parseString(aCharStar, aDecimal);
  }
  bool NumConversions::strToDecimal(const xqpString& aStr, xqp_decimal& aDecimal) {
    return starCharToDecimal(aStr.c_str(), aDecimal);
  }
  xqpString NumConversions::decimalToStr(xqp_decimal aDecimal){
    return aDecimal.toString();
  }

  bool NumConversions::starCharToFloat(const char* aCharStar, xqp_float& aFloat) {
    return Float::parseString(aCharStar, aFloat);
  }

  bool NumConversions::strToFloat(const xqpString& aStr, xqp_float& aFloat){
    return NumConversions::starCharToFloat(aStr.c_str(), aFloat);
  }
  xqpString NumConversions::floatToStr(xqp_float aFloat){
    return aFloat.toString();
  }
  bool NumConversions::starCharToDouble(const char* aCharStar, xqp_double& aDouble){
    return Double::parseString(aCharStar, aDouble);
  }
  bool NumConversions::strToDouble(const xqpString& aStr, xqp_double& aDouble) {
    return starCharToDouble(aStr.c_str(), aDouble);
  }
  xqpString NumConversions::doubleToStr(xqp_double aDouble){
    return aDouble.toString();
  }
  bool NumConversions::strToByte(const xqpString& aStr, xqp_byte& aByte){
    short lShort;
    if (strToShort(aStr, lShort)) {
      if (lShort >= -128 && lShort <= 127) {
        aByte = lShort;
        return true;
      } 
      else
        return false;
    }
    else
      return false;
  }
  xqpString NumConversions::byteToStr(xqp_byte aByte){
    return shortToStr(aByte);
  }
  bool NumConversions::strToUByte(const xqpString& aStr, xqp_ubyte& aUByte){
    unsigned short lUShort;
    if (strToUShort(aStr, lUShort)) {
      if (lUShort <= 255) {
        aUByte = lUShort;
        return true;
      }
      else
        return false;
    }
    else
      return false;
  }
  xqpString NumConversions::ubyteToStr(xqp_ubyte aUByte){
    return ushortToStr(aUByte);
  }

  xqpString NumConversions::sizetToStr(size_t aSizeT) {
    std::stringstream lStream;
    lStream << aSizeT;
    return lStream.str();
  }

  bool NumConversions::doubleToInt(const xqp_double& aDouble, xqp_int& aInt) {
#ifndef ZORBA_NO_BIGNUMBERS
    xqpString lStr = aDouble.toIntegerString();
    return NumConversions::strToInt(lStr, aInt);
#else
    aInt = (xqp_int)aDouble.theFloatImpl;
    return true;
#endif
  }

  bool NumConversions::doubleToLongLong(const xqp_double& aDouble, xqp_long& aLong) {
#ifndef ZORBA_NO_BIGNUMBERS
    xqpString lStr = aDouble.toIntegerString();
    return NumConversions::strToLongLong(lStr, aLong);
#else
    aLong = (xqp_long)aDouble.theFloatImpl;
    return true;
#endif
  }

  bool NumConversions::doubleToLong(const xqp_double& aDouble, long& aLong) {
#ifndef ZORBA_NO_BIGNUMBERS
    xqpString lStr = aDouble.toIntegerString();
    return NumConversions::strToLong(lStr, aLong);
#else
    aLong = (long)aDouble.theFloatImpl;
    return true;
#endif
  }

  bool NumConversions::integerToUInt(const xqp_integer& aInteger, xqp_uint& aUInt) {
#ifndef ZORBA_NO_BIGNUMBERS
    xqpString lStr = aInteger.toString();
    return NumConversions::strToUInt(lStr, aUInt);
#else
    aUInt = (xqp_uint)aInteger.theInteger;
    return true;
#endif
  }

  bool NumConversions::floatToInt(const xqp_float& aFloat, xqp_int& aInt) {
#ifndef ZORBA_NO_BIGNUMBERS
    xqpString lStr = aFloat.toIntegerString();
    return NumConversions::strToInt(lStr, aInt);
#else
    aInt = (xqp_int)aFloat.theFloatImpl;
    return true;
#endif
  }

  bool NumConversions::decimalToInt(const xqp_decimal& aDecimal, xqp_int& aInt) {
#ifndef ZORBA_NO_BIGNUMBERS
    xqpString lStr = aDecimal.toIntegerString();
    return NumConversions::strToInt(lStr, aInt);
#else
    aInt = (xqp_int)aDecimal.theDecimal;
    return true;
#endif
  }

} /* namespace zorba */
