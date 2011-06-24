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


bool NumConversions::doubleToLong(const xs_double& aDouble, xs_long& aLong) 
{
  zstring const lStr( aDouble.toIntegerString() );
  try {
    aLong = ztd::aton<xs_long>(lStr.c_str());
    return true;
  }
  catch ( std::exception const& ) {
    return false;
  }
}

 
bool NumConversions::doubleToInt(const xs_double& aDouble, xs_int& aInt) 
{
  zstring const lStr( aDouble.toIntegerString() );
  try {
    aInt = ztd::aton<xs_int>(lStr.c_str());
    return true;
  }
  catch ( std::exception const& ) {
    return false;
  }
}


bool NumConversions::floatToInt(const xs_float& aFloat, xs_int& aInt) 
{
  zstring const lStr( aFloat.toIntegerString() );
  try {
    aInt = ztd::aton<xs_int>(lStr.c_str());
    return true;
  }
  catch ( std::exception const& ) {
    return false;
  }
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
  if (aDecimal.is_xs_ulong()) {
    zstring lStr = aDecimal.toString();
    try {
      aULong = ztd::aton<xs_unsignedLong>(lStr.c_str());
      return true;
    }
    catch ( std::exception const& ) {
      // ignore
    }
  }
  return false;
}


bool NumConversions::decimalToLong(const xs_decimal& aDecimal, xs_long& aLong)
{
  if (aDecimal.is_xs_long()) {
    zstring lStr( aDecimal.toString() );
    try {
      aLong = ztd::aton<xs_long>( lStr.c_str() );
    }
    catch ( std::exception const& ) {
      // ignore
    }
  }
  return false;
}


bool NumConversions::decimalToUInt(const xs_decimal& aDecimal, xs_unsignedInt& aUInt)
{
  if (aDecimal.is_xs_uint()) {
    zstring lStr = aDecimal.toString();
    try {
      aUInt = ztd::aton<xs_unsignedInt>(lStr.c_str());
      return true;
    }
    catch ( std::exception const& ) {
      // ignore
    }
  }
  return false;
}


bool NumConversions::decimalToInt(const xs_decimal& aDecimal, xs_int& aInt) 
{
  if (aDecimal.is_xs_int()) {
    zstring const lStr( aDecimal.toString() );
    try {
      aInt = ztd::aton<xs_int>(lStr.c_str());
      return true;
    }
    catch ( std::exception const& ) {
      // ignore
    }
  }
  return false;
}

  
bool NumConversions::integerToLong(const xs_integer& aInteger, xs_long& aLong) 
{
#ifdef ZORBA_WITH_BIG_INTEGER
  if (aInteger.is_xs_long()) {
    zstring const lStr( aInteger.toString() );
    try {
      aLong = ztd::aton<xs_long>(lStr.c_str());
      return true;
    }
    catch ( std::exception const& ) {
      // ignore
    }
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
  if (aInteger.is_xs_uint()) {
    zstring lStr = aInteger.toString();
    try {
      aUInt = ztd::aton<xs_unsignedInt>(lStr.c_str());
      return true;
    }
    catch ( std::exception const& ) {
      // ignore
    }
  }
  return false;
#else
  aUInt = static_cast<xs_unsignedInt>(aInteger.value_);
  return true;
#endif
}


bool NumConversions::integerToInt(const xs_integer& aInteger, xs_int& aInt) {
#ifdef ZORBA_WITH_BIG_INTEGER
  if (aInteger.is_xs_int()) {
    zstring lStr( aInteger.toString() );
    try {
      aInt = ztd::aton<xs_int>(lStr.c_str());
      return true;
    }
    catch ( std::exception const& ) {
      // ignore
    }
  }
  return false;
#else
  aInt = static_cast<xs_int>(aInteger.value_);
  return true;
#endif
}



} // namespace zorba
/* vim:set et sw=2 ts=2: */
