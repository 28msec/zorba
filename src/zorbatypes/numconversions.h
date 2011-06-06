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
#pragma once
#ifndef ZORBA_NUM_CONVERSIONS_H
#define ZORBA_NUM_CONVERSIONS_H

#include <zorba/config.h>
#include "zorbatypes/schema_types.h"

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

  static bool strToDouble(const char* aStr, xs_double& aDouble);

  static bool strToFloat(const char* aStr, xs_float& aFloat);

  static bool strToDecimal(const char* aStr, xs_decimal& aDecimal);

  static bool strToInteger(const char* aCharStar, xs_integer& aInteger);

  static bool strToUInteger(const char* aStr, xs_uinteger& aUInteger);

  static bool strToLong(const char* aStr, xs_long& aLong);

  static bool strToULong(const char* aStr, xs_unsignedLong& aULong);

  static bool strToInt(const char* aStarChar, xs_int& aInt);

  static bool strToUInt(const char* aStr, xs_unsignedInt& aUInt);

  static bool strToShort(const char* aStr, xs_short& aShort);

  static bool strToUShort(const char* aStr, xs_unsignedShort& aUShort);

  static bool strToByte(const char* aStr, xs_byte& aByte);

  static bool strToUByte(const char* aStr, xs_unsignedByte& aUByte);


  /*****************************************************************************
    Numeric to String Conversions
  ******************************************************************************/

  static zstring doubleToStr(xs_double aDouble);

  static zstring floatToStr(xs_float aFloat);

  static zstring decimalToStr(xs_decimal aDecimal);

  static zstring integerToStr(xs_integer aInteger);

  static zstring uintegerToStr(xs_uinteger aUInteger);

  static zstring longToStr(xs_long aLong);

  static zstring ulongToStr(xs_unsignedLong aULong);

  static zstring intToStr(xs_int aInt);

  static zstring uintToStr(xs_unsignedInt aUInt);

  static zstring shortToStr(xs_short aShort);

  static zstring ushortToStr(xs_unsignedShort aUShort);

  static zstring byteToStr(xs_byte aByte);

  static zstring ubyteToStr(xs_unsignedByte aUByte);

  static zstring sizetToStr(size_t);


  /*****************************************************************************
    Numeric to Numeric Conversions
  ******************************************************************************/

  static bool doubleToInt(const xs_double&, xs_int&);

  static bool doubleToLong(const xs_double&, xs_long&);

  static bool floatToInt(const xs_float&, xs_int&);

  static bool decimalToInteger(const xs_decimal&, xs_integer&);

  static bool decimalToULong(const xs_decimal&, xs_unsignedLong&);

  static bool decimalToLong(const xs_decimal&, xs_long&);

  static bool decimalToUInt(const xs_decimal&, xs_unsignedInt&);

  static bool decimalToInt(const xs_decimal&, xs_int&);

  static bool integerToLong(const xs_integer&, xs_long&);

  static bool integerToUInt(const xs_integer&, xs_unsignedInt&);

  static bool integerToInt(const xs_integer&, xs_int&);

  static bool longToDouble(const xs_long& aLong, xs_double& aDouble);

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
