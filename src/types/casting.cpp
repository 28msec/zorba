/**
 *
 * @copyright
 * ========================================================================
 *  Copyright 2007 FLWOR Foundation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 * @author David Graf (david.graf@28msec.com)
 * @author Vinayak R. Borkar (vborky@yahoo.com)
 * @file types/casting.cpp
 *
 */

#include "util/numconversions.h"
#include "casting.h"
#include "system/globalenv.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "system/zorba.h"
#include "errors/error_factory.h"

namespace xqp
{

#define ATOMIC_TYPE(type) \
  GENV_TYPESYSTEM.create_atomic_type(TypeSystem::XS_##type, TypeSystem::QUANT_ONE)


/* begin class GenericCast */
GenericCast::GenericCast()
{
}


GenericCast* GenericCast::instance()
{
  static GenericCast aGenericCast;
  return &aGenericCast;
}

  
Item_t GenericCast::stringSimpleCast(
    const Item_t aSourceItem,
    const TypeSystem::xqtref_t& aSourceType,
    const TypeSystem::xqtref_t& aTargetType) const
{
  Item_t lItem = 0;
  TypeSystem& ts = GENV_TYPESYSTEM;
  ItemFactory* factory = Zorba::getItemFactory();

  xqpString lString = aSourceItem->getStringValue();
  switch(ts.get_atomic_type_code(*aTargetType)) {
  case TypeSystem::XS_ANY_ATOMIC:
  case TypeSystem::XS_STRING:
  case TypeSystem::XS_NORMALIZED_STRING:
  case TypeSystem::XS_UNTYPED_ATOMIC:
    break;
  default:
    lString = lString.trim(" \n\r\t",4);
    break;
  }
  
  switch(ts.get_atomic_type_code(*aTargetType))
  {
  case TypeSystem::XS_ANY_ATOMIC:
    lItem = factory->createUntypedAtomic(lString);
    break;
  case TypeSystem::XS_STRING:
    lItem = factory->createString(lString);
    break;
  case TypeSystem::XS_NORMALIZED_STRING:
    lItem = factory->createNormalizedString(lString);
    break;
  case TypeSystem::XS_TOKEN:
    lItem = factory->createToken(lString);
    break;
  case TypeSystem::XS_LANGUAGE:
    lItem = factory->createLanguage(lString);
    break;
  case TypeSystem::XS_NMTOKEN:
    lItem = factory->createNMTOKEN(lString);
    break;
  case TypeSystem::XS_NAME:
    lItem = factory->createName(lString);
    break;
  case TypeSystem::XS_ID:
    lItem = factory->createID(lString);
    break;
  case TypeSystem::XS_IDREF:
    lItem = factory->createIDREF(lString);
    break;
  case TypeSystem::XS_ENTITY:
    lItem = factory->createENTITY(lString);
    break;
  case TypeSystem::XS_UNTYPED_ATOMIC:
    lItem = factory->createUntypedAtomic(lString);
    break;
  case TypeSystem::XS_DATETIME:
  {
    xqp_dateTime dt;
    if (DateTime::parse_string(lString, dt))
      lItem = factory->createDateTime(dt);
  }
  break;
  case TypeSystem::XS_DATE:
  {
    xqp_date d;
    if (Date::parse_string(lString, d))
      lItem = factory->createDate(d);
  }
  break;
  case TypeSystem::XS_TIME:
  {
          xqp_time t;
          if (Time::parse_string(lString, t))
            lItem = factory->createTime(t);
        }
        break;
      case TypeSystem::XS_DURATION:
        {
          Duration_t d_t;
          if (Duration::parse_string(lString, d_t))
          {
            xqp_duration d = d_t;
            lItem = factory->createDuration(d);
          }
        }
        break;
      case TypeSystem::XS_DT_DURATION:
        {
          DayTimeDuration_t dtd_t;
          if (DayTimeDuration::parse_string(lString, dtd_t))
          {
            xqp_duration d = dtd_t;
            lItem = factory->createDuration(d);
          }
        }
        break;
      case TypeSystem::XS_YM_DURATION:
        {
          YearMonthDuration_t ymd_t;
          if (YearMonthDuration::parse_string(lString, ymd_t))
          {
            xqp_duration d = ymd_t;
            lItem = factory->createDuration(d);
          }
        }
        break;
      case TypeSystem::XS_GYEAR_MONTH:
        {
          xqp_gYearMonth ym;
          if (GYearMonth::parse_string(lString, ym))
            lItem = factory->createGYearMonth(ym);
        }
        break;
      case TypeSystem::XS_GYEAR:
        {
          xqp_gYear y;
          if (GYear::parse_string(lString, y))
            lItem = factory->createGYear(y);
        }
        break;
      case TypeSystem::XS_GMONTH_DAY:
        {
          xqp_gMonthDay md;
          if (GMonthDay::parse_string(lString, md))
            lItem = factory->createGMonthDay(md);
        }
        break;
      case TypeSystem::XS_GDAY:
        {
          xqp_gDay d;
          if (GDay::parse_string(lString, d))
            lItem = factory->createGDay(d);
        }
        break;
      case TypeSystem::XS_GMONTH:
        {
          xqp_gMonth m;
          if (GMonth::parse_string(lString, m))
            lItem = factory->createGMonth(m);
        }
        break;
      case TypeSystem::XS_FLOAT:
      {
        xqp_float n;
        if (NumConversions::strToFloat(lString, n))
          lItem = factory->createFloat(n);
      }
        break;
      case TypeSystem::XS_DOUBLE:
      {
        xqp_double n;
        if (NumConversions::strToDouble(lString, n))
          lItem = factory->createDouble(n);
      }
        break;
      case TypeSystem::XS_DECIMAL:
      {
        xqp_decimal n;
        if (NumConversions::strToDecimal(lString, n))
          lItem = factory->createDecimal(n);
      }
        break;
      case TypeSystem::XS_INTEGER:
      {
        xqp_integer n;
        if (NumConversions::strToInteger(lString, n))
          lItem = factory->createInteger(n);
      }
        break;
      case TypeSystem::XS_NON_POSITIVE_INTEGER:
      {
        xqp_integer n;
        if (NumConversions::strToInteger(lString, n)) 
          lItem = factory->createNonPositiveInteger(n);
      }
        break;
      case TypeSystem::XS_NEGATIVE_INTEGER:
      {
        xqp_integer n;
        if (NumConversions::strToInteger(lString, n) && n < 0)
          lItem = factory->createNegativeInteger(n);
      }
        break;
      case TypeSystem::XS_LONG:
      {
        xqp_long n;
        if (NumConversions::strToLong(lString, n))
          lItem = factory->createLong(n);
      }
        break;
      case TypeSystem::XS_INT:
      {
        xqp_int n;
        if (NumConversions::strToInt(lString, n))
          lItem = factory->createInt(n);
      }
        break;
      case TypeSystem::XS_SHORT:
      {
        xqp_short n;
        if (NumConversions::strToShort(lString, n))
          lItem = factory->createShort(n);
      }
        break;
      case TypeSystem::XS_BYTE:
      {
        xqp_byte n;
        if (NumConversions::strToByte(lString, n))
          lItem = factory->createByte(n);
      }
        break;
      case TypeSystem::XS_NON_NEGATIVE_INTEGER:
      {
        xqp_uinteger n;
        if (NumConversions::strToUInteger(lString, n))
          lItem = factory->createNonNegativeInteger(n);
      }
        break;
      case TypeSystem::XS_UNSIGNED_LONG:
      {
        xqp_ulong n;
        if (NumConversions::strToULong(lString, n))
          lItem = factory->createUnsignedLong(n);
      }
        break;
      case TypeSystem::XS_UNSIGNED_INT:
      {
        xqp_uint n;
        if (NumConversions::strToUInt(lString, n))          
          lItem = factory->createUnsignedInt(n);
      }
        break;
      case TypeSystem::XS_UNSIGNED_SHORT:
      {
        xqp_ushort n;
        if (NumConversions::strToUShort(lString, n))
          lItem = factory->createUnsignedShort(n);
      }
        break;
      case TypeSystem::XS_UNSIGNED_BYTE:
      {
        xqp_ubyte n;
        if (NumConversions::strToUByte(lString, n))
          lItem = factory->createUnsignedByte(n);
      }
        break;
  case TypeSystem::XS_POSITIVE_INTEGER:
  {
    xqp_integer n;
    if (NumConversions::strToInteger(lString, n) && n > 0)
      lItem = factory->createPositiveInteger(n);
  }
  break;
  case TypeSystem::XS_BOOLEAN:
  {
    lItem = castToBoolean(aSourceItem, aSourceType);
    break;
  }
  case TypeSystem::XS_BASE64BINARY:
    break;
  case TypeSystem::XS_HEXBINARY:
    break;
  case TypeSystem::XS_ANY_URI:
    lItem = factory->createAnyURI(lString);
    break;
    
  case TypeSystem::XS_NCNAME:
  {
    if (!ts.is_subtype(*aSourceType, *ts.STRING_TYPE_ONE) &&
        !ts.is_subtype(*aSourceType, *ts.UNTYPED_ATOMIC_TYPE_ONE))
    {
      ZORBA_ERROR_ALERT_OSS(ZorbaError::XPTY0004, false, false,
                            "Cannot cast " << lString
                            << " to an NCName because its type is "
                            << aSourceType->toString(), "");
    }

    if (castableToNCName(lString))
    {
      lItem = factory->createNCName(lString);
    }
    else
    {
      ZORBA_ERROR_ALERT_OSS(ZorbaError::XQDY0041, false, false,
                          "Cannot cast " << lString << " to an NCName", ""); 
    }
    break;
  }
  case TypeSystem::XS_QNAME:
  {
    // It seem that casting untyped atomic to qname is not allowed in
    // general, but it is allowed in the case of name expressions in
    // computed element/attribute constructors. ????
    if (!ts.is_subtype(*aSourceType, *ts.STRING_TYPE_ONE) &&
        !ts.is_subtype(*aSourceType, *ts.UNTYPED_ATOMIC_TYPE_ONE))
    {
      ZORBA_ERROR_ALERT_OSS(ZorbaError::XPTY0004, false, false,
                            "Cannot cast string \"" << lString
                            << "\" to an NCName because its type is "
                            << aSourceType->toString(), "");
    }
    
    // TODO namespace resolution
    xqpString lNamespace = "";
    xqpString lPrefix = "";
    int32_t lIndex = lString.indexOf(":");
    if (lIndex < 0) 
    {
      if (castableToNCName(lString))
      {
        lItem = factory->createQName(lNamespace, lPrefix, lString);
      }
      else
      {
        ZORBA_ERROR_ALERT_OSS(ZorbaError::XQDY0074, false, false,
                              "Cannot cast string \"" << lString
                              << "\" to an QName", ""); 
      }
    }
    else
    {
      lPrefix = lString.substr(0, lIndex);
      xqpString lLocal = lString.substr(lIndex + 1);

      if (castableToNCName(lPrefix) && castableToNCName(lLocal))
      {
        lItem = factory->createQName(lNamespace, lPrefix, lLocal);
      }
      else
      {
        ZORBA_ERROR_ALERT_OSS(ZorbaError::XQDY0074, false, false,
                              "Cannot cast string \"" << lString
                              << "\" to an QName", ""); 
      }
    }
    break;
  }

  case TypeSystem::XS_NOTATION:
    lItem = factory->createNOTATION(lString);
    break;
  default:
    // TODO parsing of user defined types
    break;
  }
  return lItem;
}


bool GenericCast::castableToNCName(const xqpString& str) const
{
  // TODO: replace this with the real stuff
  if (str.indexOf(":") >= 0 || str.indexOf(" ") >= 0)
  {
    return false;
  }

  return true;
}


Item_t GenericCast::castToBoolean(
    const Item_t aSourceItem,
    const TypeSystem::xqtref_t& aSourceType) const
{
  bool lRetValue = true;

#ifndef NDEBUG
  if (GENV_TYPESYSTEM.is_equal(*aSourceType, *ATOMIC_TYPE(BOOLEAN)))
  {
    assert(false); // is already handled by Generic::cast
  }
  else
#endif
    if (GENV_TYPESYSTEM.is_subtype(*aSourceType, *ATOMIC_TYPE(FLOAT)))
    {
      return aSourceItem->getEBV();
      //Item_t lFloatItem = Zorba::getItemFactory()->createFloat(0);
      //if (lFloatItem->equals(aSourceItem))
      //  lRetValue = false;
      // TODO check NaN
      
    } else if (GENV_TYPESYSTEM.is_subtype(*aSourceType, *ATOMIC_TYPE(DOUBLE)))
    {
      return aSourceItem->getEBV();
      //Item_t lDoubleItem = Zorba::getItemFactory()->createDouble(0);
      //if (lDoubleItem->equals(aSourceItem))
      //  lRetValue = false;

      // TODO check NaN
    } else if (GENV_TYPESYSTEM.is_subtype(*aSourceType, *ATOMIC_TYPE(DECIMAL)))
    {
      return aSourceItem->getEBV();
      //Item_t lDecimalItem = Zorba::getItemFactory()->createDecimal(0);
      //if (lDecimalItem->equals(aSourceItem))
      //  lRetValue = false;

      // TODO check NaN

    } else if (GENV_TYPESYSTEM.is_subtype(*aSourceType, *ATOMIC_TYPE(INTEGER)))
    {
      return aSourceItem->getEBV();
      //Item_t lIntegerItem = Zorba::getItemFactory()->createInteger(0);
      //if (lIntegerItem->equals(aSourceItem))
      //  lRetValue = false;

     // TODO check NAN
    } else if (GENV_TYPESYSTEM.is_equal(*aSourceType, *ATOMIC_TYPE(STRING))
               || GENV_TYPESYSTEM.is_equal(*aSourceType, *ATOMIC_TYPE(UNTYPED_ATOMIC)))
    {
      xqp_string lString = aSourceItem->getStringValue().trim();

      if (lString == "false" || lString == "0")
        lRetValue = false;
      else if (lString != "true" && lString != "1")
      {
        ZORBA_ERROR_ALERT(ZorbaError::FORG0001, false, "String cannot be cast to boolean");
      }
      
    }

    return Zorba::getItemFactory()->createBoolean(lRetValue);
  }
#undef ATOMIC_TYPE


Item_t GenericCast::cast(Item_t aItem, const TypeSystem::xqtref_t& aTargetType) const
{
  Item_t lResult;
  TypeSystem& ts = GENV_TYPESYSTEM;

  TypeSystem::xqtref_t lItemType = ts.create_type(aItem->getType(),
                                                  TypeSystem::QUANT_ONE);

  if (ts.is_subtype(*lItemType, *aTargetType)) 
  {
    return aItem;
  }
    
  lResult = stringSimpleCast(aItem, lItemType, aTargetType);
  if ( lResult == 0 ) 
  {
    ZORBA_ERROR_ALERT(ZorbaError::FORG0001, false, false,
                      "Passed item is not castable to passed target type.");
  }

  return lResult;
}


Item_t GenericCast::cast(
    const xqpString& aStr,
    const TypeSystem::xqtref_t& aTargetType) const
{
  Item_t lItem = Zorba::getItemFactory()->createString(aStr);
  Item_t lResult = cast(lItem, aTargetType);
  return lResult;
}


bool GenericCast::isCastable(
    Item_t aItem,
    const TypeSystem::xqtref_t& aTargetType) const
{
  Item_t lItem;
  TypeSystem& ts = GENV_TYPESYSTEM;

  TypeSystem::xqtref_t lItemType = ts.create_type(aItem->getType(),
                                                  TypeSystem::QUANT_ONE);

  if (ts.is_subtype(*lItemType, *aTargetType))
  {
    // Item is castable if target type is a supertype
    return true;  
  }
  
  // Most simple implementation: Check if string cast works
  lItem = stringSimpleCast(aItem, lItemType, aTargetType);

  return lItem != 0;
}


bool GenericCast::isCastable(
    const xqpString& aStr,
    const TypeSystem::xqtref_t& aTargetType) const
{
  Item_t lItem = Zorba::getItemFactory()->createString(aStr);
  return isCastable(lItem, aTargetType);
}

/* end class GenericCast */
} /* namespace xqp */
