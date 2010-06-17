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

#include <zorba/config.h>
#include "zorbatypes/representations.h"

namespace zorba {

/**
 * Class contains all num conversions and string to num and num to string conversions
 * that are used in Zorba.
 *
 * All functions which might not work return a bool which indicates the success of the
 * conversions. Functions which aways work return the value directly.
 */
class ZORBA_DLL_PUBLIC NumConversions 
{
public:

  /*****************************************************************************
    String to Numeric Conversions
  ******************************************************************************/

  static bool strToDouble(const char* aStr, xqp_double& aDouble);

  static bool strToFloat(const char* aStr, xqp_float& aFloat);

  static bool strToDecimal(const char* aStr, xqp_decimal& aDecimal);

  static bool strToInteger(const char* aCharStar, xqp_integer& aInteger);

  static bool strToUInteger(const char* aStr, xqp_uinteger& aUInteger);

  static bool strToLong(const char* aStr, xqp_long& aLong);

  static bool strToULong(const char* aStr, xqp_ulong& aULong);

  static bool strToInt(const char* aStarChar, xqp_int& aInt);

  static bool strToUInt(const char* aStr, xqp_uint& aUInt);

  static bool strToShort(const char* aStr, xqp_short& aShort);

  static bool strToUShort(const char* aStr, xqp_ushort& aUShort);

  static bool strToByte(const char* aStr, xqp_byte& aByte);

  static bool strToUByte(const char* aStr, xqp_ubyte& aUByte);


  /*****************************************************************************
    Numeric to String Conversions
  ******************************************************************************/

  static xqpStringStore_t doubleToStr(xqp_double aDouble);

  static xqpStringStore_t floatToStr(xqp_float aFloat);

  static xqpStringStore_t decimalToStr(xqp_decimal aDecimal);

  static xqpStringStore_t integerToStr(xqp_integer aInteger);

  static xqpStringStore_t uintegerToStr(xqp_uinteger aUInteger);

  static xqpStringStore_t longLongToStr(xqp_long aLong);

  static xqpStringStore_t ulongLongToStr(xqp_ulong aULong);

  static xqpStringStore_t intToStr(xqp_int aInt);

  static xqpStringStore_t uintToStr(xqp_uint aUInt);

  static xqpStringStore_t shortToStr(xqp_short aShort);

  static xqpStringStore_t ushortToStr(xqp_ushort aUShort);

  static xqpStringStore_t byteToStr(xqp_byte aByte);

  static xqpStringStore_t ubyteToStr(xqp_ubyte aUByte);

  static xqpStringStore_t sizetToStr(size_t);


  /*****************************************************************************
    Numeric to Numeric Conversions
  ******************************************************************************/

  static bool decimalToInteger(const xqp_decimal&, xqp_integer&);

  static bool decimalToULong(const xqp_decimal&, xqp_ulong&);

  static bool decimalToLong(const xqp_decimal&, xqp_long&);

  static bool decimalToUInt(const xqp_decimal&, xqp_uint&);

  static bool decimalToInt(const xqp_decimal&, xqp_int&);

  static bool integerToLong(const xqp_integer&, xqp_long&);

  static bool integerToUInt(const xqp_integer&, xqp_uint&);

  static bool integerToInt(const xqp_integer&, xqp_int&);

  static bool doubleToInt(const xqp_double&, xqp_int&);

  static bool doubleToLongLong(const xqp_double&, xqp_long&);

  static bool floatToInt(const xqp_float&, xqp_int&);

private:
  static bool isNegative(const char*& chp, bool& isNegZero);
};


} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
