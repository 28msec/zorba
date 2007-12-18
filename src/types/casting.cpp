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
 * ========================================================================
 *
 * @author David Graf (david.graf@28msec.com)
 * @author Vinayak R. Borkar (vborky@yahoo.com)
 * @file types/casting.cpp
 *
 */

#include <boost/lexical_cast.hpp>

#include "casting.h"
#include "system/globalenv.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "util/zorba.h"

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
  
  Item_t GenericCast::stringSimpleCast(/*const*/ xqpString& aString, TypeSystem::xqtref_t& aTargetType) {
    Item_t lItem = 0;
    
    try {
      switch(GENV_TYPESYSTEM.get_atomic_type_code(*aTargetType)) {
        case TypeSystem::XS_ANY_ATOMIC:
          lItem = zorba::getItemFactory()->createUntypedAtomic(aString);
          break;
        case TypeSystem::XS_STRING:
          lItem = zorba::getItemFactory()->createString(aString);
          break;
        case TypeSystem::XS_NORMALIZED_STRING:
          lItem = zorba::getItemFactory()->createNormalizedString(aString);
          break;
        case TypeSystem::XS_TOKEN:
          lItem = zorba::getItemFactory()->createToken(aString);
          break;
        case TypeSystem::XS_LANGUAGE:
          lItem = zorba::getItemFactory()->createLanguage(aString);
          break;
        case TypeSystem::XS_NMTOKEN:
          lItem = zorba::getItemFactory()->createNMTOKEN(aString);
          break;
        case TypeSystem::XS_NAME:
          lItem = zorba::getItemFactory()->createName(aString);
          break;
        case TypeSystem::XS_NCNAME:
          lItem = zorba::getItemFactory()->createNCName(aString);
          break;
        case TypeSystem::XS_ID:
          lItem = zorba::getItemFactory()->createID(aString);
          break;
        case TypeSystem::XS_IDREF:
          lItem = zorba::getItemFactory()->createIDREF(aString);
          break;
        case TypeSystem::XS_ENTITY:
          lItem = zorba::getItemFactory()->createENTITY(aString);
          break;
        case TypeSystem::XS_UNTYPED_ATOMIC:
          lItem = zorba::getItemFactory()->createUntypedAtomic(aString);
          break;
        case TypeSystem::XS_DATETIME:
          // TODO
          break;
        case TypeSystem::XS_DATE:
          // TODO
          break;
        case TypeSystem::XS_TIME:
          // TODO
          break;
        case TypeSystem::XS_DURATION:
          // TODO
          break;
        case TypeSystem::XS_DT_DURATION:
          // TODO
          break;
        case TypeSystem::XS_YM_DURATION:
          // TODO
          break;
        case TypeSystem::XS_FLOAT:
        {
          xqp_float n = boost::lexical_cast<xqp_float>(aString.c_str());
          lItem = zorba::getItemFactory()->createFloat(n);
        }
          break;
        case TypeSystem::XS_DOUBLE:
        {
          xqp_double n = boost::lexical_cast<xqp_double>(aString.c_str());
          lItem = zorba::getItemFactory()->createDouble(n);
        }
          break;
        case TypeSystem::XS_DECIMAL:
        {
          xqp_decimal n = boost::lexical_cast<xqp_decimal>(aString.c_str());
          lItem = zorba::getItemFactory()->createDecimal(n);
        }
          break;
        case TypeSystem::XS_INTEGER:
        {
          xqp_integer n = boost::lexical_cast<xqp_integer>(aString.c_str());
          lItem = zorba::getItemFactory()->createInteger(n);
        }
          break;
        case TypeSystem::XS_NON_POSITIVE_INTEGER:
        {
          xqp_integer n = boost::lexical_cast<xqp_integer>(aString.c_str());
          lItem = zorba::getItemFactory()->createNonPositiveInteger(n);
        }
          break;
        case TypeSystem::XS_NEGATIVE_INTEGER:
        {
          xqp_integer n = boost::lexical_cast<xqp_integer>(aString.c_str());
          lItem = zorba::getItemFactory()->createNegativeInteger(n);
        }
          break;
        case TypeSystem::XS_LONG:
        {
          xqp_long n = boost::lexical_cast<xqp_long>(aString.c_str());
          lItem = zorba::getItemFactory()->createLong(n);
        }
          break;
        case TypeSystem::XS_INT:
        {
          xqp_int n = boost::lexical_cast<xqp_int>(aString.c_str());
          lItem = zorba::getItemFactory()->createInt(n);
        }
          break;
        case TypeSystem::XS_SHORT:
        {
          xqp_short n = boost::lexical_cast<xqp_short>(aString.c_str());
          lItem = zorba::getItemFactory()->createShort(n);
        }
          break;
        case TypeSystem::XS_BYTE:
        {
          xqp_byte n = boost::lexical_cast<xqp_byte>(aString.c_str());
          lItem = zorba::getItemFactory()->createByte(n);
        }
          break;
        case TypeSystem::XS_NON_NEGATIVE_INTEGER:
        {
          xqp_uinteger n = boost::lexical_cast<xqp_uinteger>(aString.c_str());
          lItem = zorba::getItemFactory()->createNonNegativeInteger(n);
        }
          break;
        case TypeSystem::XS_UNSIGNED_LONG:
        {
          xqp_ulong n = boost::lexical_cast<xqp_ulong>(aString.c_str());
          lItem = zorba::getItemFactory()->createUnsignedLong(n);
        }
          break;
        case TypeSystem::XS_UNSIGNED_INT:
        {
          xqp_uint n = boost::lexical_cast<xqp_uint>(aString.c_str());
          lItem = zorba::getItemFactory()->createUnsignedInt(n);
        }
          break;
        case TypeSystem::XS_UNSIGNED_SHORT:
        {
          xqp_ushort n = boost::lexical_cast<xqp_ushort>(aString.c_str());
          lItem = zorba::getItemFactory()->createUnsignedShort(n);
        }
          break;
        case TypeSystem::XS_UNSIGNED_BYTE:
        {
          xqp_ubyte n = boost::lexical_cast<xqp_ubyte>(aString.c_str());
          lItem = zorba::getItemFactory()->createUnsignedByte(n);
        }
          break;
        case TypeSystem::XS_POSITIVE_INTEGER:
        {
          xqp_integer n = boost::lexical_cast<xqp_integer>(aString.c_str());
          lItem = zorba::getItemFactory()->createPositiveInteger(n);
        }
          break;
        case TypeSystem::XS_GYEAR_MONTH:
          // TODO
          break;
        case TypeSystem::XS_GYEAR:
          // TODO
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
          bool b;
          if (aString == "true")
            lItem = zorba::getItemFactory()->createBoolean(true);
          else if (aString == "false")
            lItem = zorba::getItemFactory()->createBoolean(false);
        }
          break;
        case TypeSystem::XS_BASE64BINARY:
          break;
        case TypeSystem::XS_HEXBINARY:
          break;
        case TypeSystem::XS_ANY_URI:
          lItem = zorba::getItemFactory()->createAnyURI(aString);
          break;
        case TypeSystem::XS_QNAME:
        {
          // TODO namespace resolution
          xqpString lNamespace = "";
          xqpString lPrefix = "";
          int32_t lIndex = aString.indexOf(":");
          if (lIndex < 0) {
            lItem = &*zorba::getItemFactory()->createQName(lNamespace, lPrefix, aString);
          } else {
            lPrefix = aString.substr(0, lIndex);
            xqpString lLocal = aString.substr(lIndex + 1);
            lItem = &*zorba::getItemFactory()->createQName(lNamespace, lPrefix, lLocal);
          }
        }
          break;
        case TypeSystem::XS_NOTATION:
          lItem = zorba::getItemFactory()->createNOTATION(aString);
          break;
        default:
          // TODO parsing of user defined types
          break;
      }
    } catch (boost::bad_lexical_cast& e) {
      ZorbaErrorAlerts::error_alert (
        error_messages::XPST0080_STATIC_BAD_CAST_EXPR,
        error_messages::STATIC_ERROR,
        false,
        "System error during atomic string casting (boost bad_lexical_cast exception)!"
      );
}
    
    if (lItem == 0) {
      ZorbaErrorAlerts::error_alert (
        error_messages::XQP0015_SYSTEM_NOT_YET_IMPLEMENTED,
        error_messages::STATIC_ERROR,
        false,
        "String casting for asked type is not possible!"
      );
    }
    return lItem;
  }

  Item_t GenericCast::cast ( Item_t aItem, /*const*/ TypeSystem::xqtref_t& aTargetType )
  {
    Item_t lResult;
    
    TypeSystem::xqtref_t lItemType = GENV_TYPESYSTEM.create_type( aItem->getType(), TypeSystem::QUANT_ONE );
    if ( GENV_TYPESYSTEM.is_subtype ( *lItemType, *aTargetType ) ) {
      return aItem;
    }
    
    xqpString lStr = aItem->getStringProperty();
    lResult = stringSimpleCast(lStr, aTargetType);
    return lResult;
    
// 
//     if ( !GENV_TYPESYSTEM.is_atomic ( *aTargetType ) )
//     {
//       ZorbaErrorAlerts::error_alert (
//           error_messages::FORG0001_Invalid_value_for_cast_constructor,
//           error_messages::STATIC_ERROR,
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
//                 error_messages::FORG0001_Invalid_value_for_cast_constructor,
//                 error_messages::STATIC_ERROR,
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
//               error_messages::FORG0001_Invalid_value_for_cast_constructor,
//               error_messages::STATIC_ERROR,
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
//             error_messages::FORG0001_Invalid_value_for_cast_constructor,
//             error_messages::STATIC_ERROR,
//             false,
//             "Item cannot be casted to the declared type!"
//         );
//         break;
//     }
//     return result;
  }
  /* end class GenericCast */
} /* namespace xqp */
