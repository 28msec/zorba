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

private:
  static bool isNegative(const char*& chp, bool& isNegZero);
};


} // namespace zorba
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
