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

  /* begin class GenericCast */
  GenericCast::GenericCast()
  {}

  GenericCast* GenericCast::instance()
  {
    static GenericCast aGenericCast;
    return &aGenericCast;
  }
  
  Item_t GenericCast::stringSimpleCast(const Item_t aSourceItem,
                                       const TypeSystem::xqtref_t& aSourceType,
                                       const TypeSystem::xqtref_t& aTargetType) const
  {
    Item_t lItem = 0;

    xqpString lString = aSourceItem->getStringProperty().trim(" \n\r\t",4);
  
    switch(GENV_TYPESYSTEM.get_atomic_type_code(*aTargetType)) {
      case TypeSystem::XS_ANY_ATOMIC:
        lItem = Zorba::getItemFactory()->createUntypedAtomic(lString);
        break;
      case TypeSystem::XS_STRING:
        lItem = Zorba::getItemFactory()->createString(lString);
        break;
      case TypeSystem::XS_NORMALIZED_STRING:
        lItem = Zorba::getItemFactory()->createNormalizedString(lString);
        break;
      case TypeSystem::XS_TOKEN:
        lItem = Zorba::getItemFactory()->createToken(lString);
        break;
      case TypeSystem::XS_LANGUAGE:
        lItem = Zorba::getItemFactory()->createLanguage(lString);
        break;
      case TypeSystem::XS_NMTOKEN:
        lItem = Zorba::getItemFactory()->createNMTOKEN(lString);
        break;
      case TypeSystem::XS_NAME:
        lItem = Zorba::getItemFactory()->createName(lString);
        break;
      case TypeSystem::XS_NCNAME:
        lItem = Zorba::getItemFactory()->createNCName(lString);
        break;
      case TypeSystem::XS_ID:
        lItem = Zorba::getItemFactory()->createID(lString);
        break;
      case TypeSystem::XS_IDREF:
        lItem = Zorba::getItemFactory()->createIDREF(lString);
        break;
      case TypeSystem::XS_ENTITY:
        lItem = Zorba::getItemFactory()->createENTITY(lString);
        break;
      case TypeSystem::XS_UNTYPED_ATOMIC:
        lItem = Zorba::getItemFactory()->createUntypedAtomic(lString);
        break;
      case TypeSystem::XS_DATETIME:
        lItem = Zorba::getItemFactory()->createDateTime(lString);
        break;
      case TypeSystem::XS_DATE:
        lItem = Zorba::getItemFactory()->createDate(lString);
        break;
      case TypeSystem::XS_TIME:
        lItem = Zorba::getItemFactory()->createTime(lString);
        break;
      case TypeSystem::XS_DURATION:
        lItem = Zorba::getItemFactory()->createDuration(lString);
        break;
      case TypeSystem::XS_DT_DURATION:
        lItem = Zorba::getItemFactory()->createDuration(lString);
        break;
      case TypeSystem::XS_YM_DURATION:
        lItem = Zorba::getItemFactory()->createDuration(lString);
        break;
      case TypeSystem::XS_FLOAT:
      {
        xqp_float n;
        if (NumConversions::strToFloat(lString, n))
          lItem = Zorba::getItemFactory()->createFloat(n);
      }
        break;
      case TypeSystem::XS_DOUBLE:
      {
        xqp_double n;
        if (NumConversions::strToDouble(lString, n))
          lItem = Zorba::getItemFactory()->createDouble(n);
      }
        break;
      case TypeSystem::XS_DECIMAL:
      {
        xqp_decimal n;
        if (NumConversions::strToDecimal(lString, n))
          lItem = Zorba::getItemFactory()->createDecimal(n);
      }
        break;
      case TypeSystem::XS_INTEGER:
      {
        xqp_integer n;
        if (NumConversions::strToInteger(lString, n))
          lItem = Zorba::getItemFactory()->createInteger(n);
      }
        break;
      case TypeSystem::XS_NON_POSITIVE_INTEGER:
      {
        xqp_integer n;
        if (NumConversions::strToInteger(lString, n)) 
          lItem = Zorba::getItemFactory()->createNonPositiveInteger(n);
      }
        break;
      case TypeSystem::XS_NEGATIVE_INTEGER:
      {
        xqp_integer n;
        if (NumConversions::strToInteger(lString, n) && n < 0)
          lItem = Zorba::getItemFactory()->createNegativeInteger(n);
      }
        break;
      case TypeSystem::XS_LONG:
      {
        xqp_long n;
        if (NumConversions::strToLong(lString, n))
          lItem = Zorba::getItemFactory()->createLong(n);
      }
        break;
      case TypeSystem::XS_INT:
      {
        xqp_int n;
        if (NumConversions::strToInt(lString, n))
          lItem = Zorba::getItemFactory()->createInt(n);
      }
        break;
      case TypeSystem::XS_SHORT:
      {
        xqp_short n;
        if (NumConversions::strToShort(lString, n))
          lItem = Zorba::getItemFactory()->createShort(n);
      }
        break;
      case TypeSystem::XS_BYTE:
      {
        xqp_byte n;
        if (NumConversions::strToByte(lString, n))
          lItem = Zorba::getItemFactory()->createByte(n);
      }
        break;
      case TypeSystem::XS_NON_NEGATIVE_INTEGER:
      {
        xqp_uinteger n;
        if (NumConversions::strToUInteger(lString, n))
          lItem = Zorba::getItemFactory()->createNonNegativeInteger(n);
      }
        break;
      case TypeSystem::XS_UNSIGNED_LONG:
      {
        xqp_ulong n;
        if (NumConversions::strToULong(lString, n))
          lItem = Zorba::getItemFactory()->createUnsignedLong(n);
      }
        break;
      case TypeSystem::XS_UNSIGNED_INT:
      {
        xqp_uint n;
        if (NumConversions::strToUInt(lString, n))          
          lItem = Zorba::getItemFactory()->createUnsignedInt(n);
      }
        break;
      case TypeSystem::XS_UNSIGNED_SHORT:
      {
        xqp_ushort n;
        if (NumConversions::strToUShort(lString, n))
          lItem = Zorba::getItemFactory()->createUnsignedShort(n);
      }
        break;
      case TypeSystem::XS_UNSIGNED_BYTE:
      {
        xqp_ubyte n;
        if (NumConversions::strToUByte(lString, n))
          lItem = Zorba::getItemFactory()->createUnsignedByte(n);
      }
        break;
      case TypeSystem::XS_POSITIVE_INTEGER:
      {
        xqp_integer n;
        if (NumConversions::strToInteger(lString, n) && n > 0)
          lItem = Zorba::getItemFactory()->createPositiveInteger(n);
      }
        break;
      case TypeSystem::XS_GYEAR_MONTH:
        // TODO
        break;
      case TypeSystem::XS_GYEAR:
        // TODO
        lItem = aSourceItem->getEBV();
        break;
      case TypeSystem::XS_GMONTH_DAY:
        // TODO
        break;
      case TypeSystem::XS_GDAY:
        // TODO
        break;
      case TypeSystem::XS_GMONTH:
        // TODO
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
        lItem = Zorba::getItemFactory()->createAnyURI(lString);
        break;
      case TypeSystem::XS_QNAME:
      {
        // TODO namespace resolution
        xqpString lNamespace = "";
        xqpString lPrefix = "";
        int32_t lIndex = lString.indexOf(":");
        if (lIndex < 0) {
          lItem = &*Zorba::getItemFactory()->createQName(lNamespace, lPrefix, lString);
        } else {
          lPrefix = lString.substr(0, lIndex);
          xqpString lLocal = lString.substr(lIndex + 1);
          lItem = &*Zorba::getItemFactory()->createQName(lNamespace, lPrefix, lLocal);
        }
      }
        break;
      case TypeSystem::XS_NOTATION:
        lItem = Zorba::getItemFactory()->createNOTATION(lString);
        break;
      default:
        // TODO parsing of user defined types
        break;
    }
    return lItem;
  }

#define ATOMIC_TYPE(type) \
  GENV_TYPESYSTEM.create_atomic_type(TypeSystem::XS_##type, TypeSystem::QUANT_ONE)

  Item_t
  GenericCast::castToBoolean(const Item_t aSourceItem,
                             const TypeSystem::xqtref_t& aSourceType) const
  {
    bool lRetValue = true;

#ifndef NDEBUG
    if (GENV_TYPESYSTEM.is_equal(*aSourceType, *ATOMIC_TYPE(BOOLEAN)))
    {
      assert(false); // is already handled by Generic::cast
    } else
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
      xqp_string lString = aSourceItem->getStringProperty().trim();

      if (lString == "false" || lString == "0")
        lRetValue = false;
      else if (lString != "true" && lString != "1")
      {
        ZORBA_ERROR_ALERT(AlertCodes::FORG0001, false, "String cannot be cast to boolean");
      }
      
    }

    return Zorba::getItemFactory()->createBoolean(lRetValue);
  }
#undef ATOMIC_TYPE

  Item_t GenericCast::cast ( Item_t aItem, const TypeSystem::xqtref_t& aTargetType ) const
  {
    Item_t lResult;
    
    TypeSystem::xqtref_t lItemType = 
            GENV_TYPESYSTEM.create_type( aItem->getType(), TypeSystem::QUANT_ONE );

    if ( GENV_TYPESYSTEM.is_subtype ( *lItemType, *aTargetType ) ) {
      return aItem;
    }
    
    lResult = stringSimpleCast(aItem, lItemType, aTargetType);
    if ( lResult == 0 ) {
      ZORBA_ERROR_ALERT(AlertCodes::FORG0001, false, 
        false, "Passed item is not castable to passed target type."
      );
    }
    return lResult;
    
// 
//     if ( !GENV_TYPESYSTEM.is_atomic ( *aTargetType ) )
//     {
//       ZorbaErrorAlerts::error_alert (
//           AlertCodes::FORG0001_Invalid_value_for_cast_constructor,
//           AlertCodes::STATIC_ERROR,
//           false,
//           "Item cannot be casted to the declared type!"
//       );
//     }
// 
//     switch ( GENV_TYPESYSTEM.get_atomic_type_code ( *aTargetType ) )
//     {
//       case TypeSystem::XS_DOUBLE:
//         double doubleVal;
//         if ( GENV_TYPESYSTEM.is_subtype ( *itemType, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
//         {
//           doubleVal = static_cast<double> ( item->getFloatValue() );
//         }
//         else if ( GENV_TYPESYSTEM.is_subtype ( *itemType, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ) )
//         {
//           doubleVal = static_cast<double> ( item->getDecimalValue() );
//         }
//         else
//         {
//           const char* pStart = item->getStringValue().c_str();
//           char* pEnd;
//           doubleVal = strtod ( pStart, &pEnd );
//           if ( *pEnd != '\0' )
//           {
//             ZorbaErrorAlerts::error_alert (
//                 AlertCodes::FORG0001_Invalid_value_for_cast_constructor,
//                 AlertCodes::STATIC_ERROR,
//                 NULL,
//                 false,
//                 "Cannot convert \"" + item->getStringValue() + "\" to a double!"
//             );
//           }
//         }
//         result = lItemFactory->createDouble ( doubleVal );
//         break;
//       case TypeSystem::XS_FLOAT:
//         if ( GENV_TYPESYSTEM.is_subtype ( *itemType, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ) )
//         {
//           result = lItemFactory->createFloat ( static_cast<float> ( item->getDecimalValue() ) );
//         }
//         else
//         {
//           ZorbaErrorAlerts::error_alert (
//               AlertCodes::FORG0001_Invalid_value_for_cast_constructor,
//               AlertCodes::STATIC_ERROR,
//               NULL,
//               false,
//               "Numeric casting of a non numeric type"
//           );
//         }
//         break;
//       case TypeSystem::XS_STRING:
//         result = lItemFactory->createString ( item->getStringProperty() );
//         break;
//       default:
//         ZorbaErrorAlerts::error_alert (
//             AlertCodes::FORG0001_Invalid_value_for_cast_constructor,
//             AlertCodes::STATIC_ERROR,
//             false,
//             "Item cannot be casted to the declared type!"
//         );
//         break;
//     }
//     return result;
  }

  bool GenericCast::isCastable(Item_t aItem, const TypeSystem::xqtref_t& aTargetType) const {
    TypeSystem::xqtref_t lItemType = 
        GENV_TYPESYSTEM.create_type( aItem->getType(), TypeSystem::QUANT_ONE );

    if ( GENV_TYPESYSTEM.is_subtype ( *lItemType, *aTargetType ) ) {
      // Item is castable if target type is a supertype
      return true;  
    }
    
    // Most simple implementation: Check if string cast works
    Item_t lItem = stringSimpleCast(aItem, lItemType, aTargetType);
    if (lItem == 0) {
      return false;
    } else {
      return true;
    }
  }
  /* end class GenericCast */
} /* namespace xqp */
