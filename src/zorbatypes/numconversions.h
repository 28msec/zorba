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
#ifndef ZORBA_NUM_CONVERSIONS_H
#define ZORBA_NUM_CONVERSIONS_H

#include "zorbatypes/representations.h"

namespace zorba {

/**
 * Class contains all num conversions and string to num and num to string conversions
 * that are used in Zorba.
 *
 * All functions which might not work return a bool which indicates the success of the
 * conversions. Functions which aways work return the value directly.
 */
class NumConversions {
private:
  static bool isNegZero(const xqpString& aStr);

public:
  /**********************************************************************************
   * String to Numeric and Numeric to String Conversions
   *********************************************************************************/
  static bool starCharToInteger(const char* aCharStar, xqp_integer& aInteger);
  static bool strToInteger(const xqpString& aStr, xqp_integer& aInteger);
  static xqpString integerToStr(xqp_integer aInteger);
  static bool strToUInteger(const xqpString& aStr, xqp_uinteger& aUInteger);
  static xqpString uintegerToStr(xqp_uinteger aUInteger);
  static bool starCharToInt(const char* aStarChar, xqp_int& aInt);
  static bool strToInt(const xqpString& aStr, xqp_int& aInt);
  static xqpString intToStr(xqp_int aInt);
  static bool strToUInt(const xqpString& aStr, xqp_uint& aUInt);
  static xqpString uintToStr(xqp_uint aUInt);
  static bool strToLongLong(const xqpString& aStr, xqp_long& aLong);
  static xqpString longLongToStr(xqp_long aLong);
  static bool strToLong(const xqpString& aStr, long&);
  static xqpString longToStr(long aLong);
  static bool strToULongLong(const xqpString& aStr, xqp_ulong& aULong);
  static xqpString ulongLongToStr(xqp_ulong aULong);
  static xqpString ulongToStr(unsigned long);
  static bool strToShort(const xqpString& aStr, xqp_short& aShort);
  static xqpString shortToStr(xqp_short aShort);
  static bool strToUShort(const xqpString& aStr, xqp_ushort& aUShort);
  static xqpString ushortToStr(xqp_ushort aUShort);
  static bool starCharToDecimal(const char* aStarChar, xqp_decimal& aDecimal);
  static bool strToDecimal(const xqpString& aStr, xqp_decimal& aDecimal);
  static xqpString decimalToStr(xqp_decimal aDecimal);
  static bool starCharToFloat(const char* aStarChar, xqp_float& aFloat);
  static bool strToFloat(const xqpString& aStr, xqp_float& aFloat);
  static xqpString floatToStr(xqp_float aFloat);
  static bool starCharToDouble(const char* aStarChar, xqp_double& aDouble);
  static bool strToDouble(const xqpString& aStr, xqp_double& aDouble);
  static xqpString doubleToStr(xqp_double aDouble);
  static bool strToByte(const xqpString& aStr, xqp_byte& aByte);
  static xqpString byteToStr(xqp_byte aByte);
  static bool strToUByte(const xqpString& aStr, xqp_ubyte& aUByte);
  static xqpString ubyteToStr(xqp_ubyte aUByte);
  static xqpString sizetToStr(size_t);

  /********************************************************************************
   * Numeric to Numeric Conversions
   * *****************************************************************************/
  static bool doubleToInt(const xqp_double&, xqp_int&);
  static bool doubleToLongLong(const xqp_double&, xqp_long&);
  static bool doubleToLong(const xqp_double&, long&);
  static bool integerToUInt(const xqp_integer&, xqp_uint&);
  static bool floatToInt(const xqp_float&, xqp_int&);
  static bool decimalToInt(const xqp_decimal&, xqp_int&);
}; /* class NumConversions */

} /* namespace zorba */

#endif
