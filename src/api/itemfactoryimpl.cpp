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
#define  __STDC_LIMIT_MACROS
#include <zorba/item.h>
#include "zorbaerrors/errors.h"
#include "api/itemfactoryimpl.h"


#include "zorbatypes/duration.h"
#include "system/globalenv.h"
#include "store/api/item_factory.h"
#include "api/unmarshaller.h"

#include "store/api/item.h"


namespace zorba {
  
  ItemFactoryImpl*
  ItemFactoryImpl::getInstance()
  {
    static ItemFactoryImpl theInstance;
    return &theInstance;
  }

  ItemFactoryImpl::ItemFactoryImpl()
  {
    theItemFactory = GENV_ITEMFACTORY;
  }

  ItemFactoryImpl::~ItemFactoryImpl() {}


  Item
  ItemFactoryImpl::createString(const String& aString)
  {
    xqpStringStore_t lString = Unmarshaller::getInternalString(aString);

    store::Item_t lItem;
    theItemFactory->createString(lItem, lString);

    return &*lItem;
  }

  Item
  ItemFactoryImpl::createAnyURI(const String& aURI)
  {
    xqpStringStore_t lString = Unmarshaller::getInternalString(aURI);

    store::Item_t lItem;
    theItemFactory->createAnyURI(lItem, lString);

    return &*lItem;
  }

  Item
  ItemFactoryImpl::createDate( const String& aDateValue )
  {
    xqpStringStore* lString = Unmarshaller::getInternalString( aDateValue );

    store::Item_t lItem;
    theItemFactory->createDate(lItem,  lString );

    return &*lItem;
  }

  Item
  ItemFactoryImpl::createDate (
      short aYear,
      short aMonth,
      short aDay )
  {
    store::Item_t lItem;
    theItemFactory->createDate(lItem,  aYear, aMonth, aDay );

    return &*lItem;
  }

  Item
  ItemFactoryImpl::createQName(const String& aNamespace, const String& aPrefix,
                               const String& aLocalname)
  {
    xqpStringStore_t lNamespace = Unmarshaller::getInternalString( aNamespace );
    xqpStringStore_t lPrefix = Unmarshaller::getInternalString( aPrefix );
    xqpStringStore_t lLocalname = Unmarshaller::getInternalString( aLocalname );

    store::Item_t lItem;
    theItemFactory->createQName(lItem, lNamespace, lPrefix, lLocalname);
    return &*lItem;
  }

  Item
  ItemFactoryImpl::createQName(const String& aNamespace, const String& aLocalname)
  {
    xqpStringStore_t lNamespace = Unmarshaller::getInternalString( aNamespace );
    xqpStringStore_t lPrefix(new xqpStringStore(""));
    xqpStringStore_t lLocalname = Unmarshaller::getInternalString( aLocalname );
    store::Item_t lItem;
    theItemFactory->createQName(lItem, lNamespace, lPrefix, lLocalname);
    return &*lItem;
  }

  Item 
  ItemFactoryImpl::createNCName(const String& aValue)
  {
    xqpStringStore_t lString = Unmarshaller::getInternalString( aValue );
    store::Item_t lItem;
    theItemFactory->createNCName(lItem, lString);
    return &*lItem;
  }
    
  Item 
  ItemFactoryImpl::createBase64Binary(const char* aBinData, size_t aLength)
  {
    store::Item_t lItem;
    xqp_base64Binary n;
    if (xqp_base64Binary::parseString(aBinData, aLength, n))
      theItemFactory->createBase64Binary(lItem, n);
    
    return &*lItem;
  }
      
  Item 
  ItemFactoryImpl::createBoolean(bool aValue)
  {
    store::Item_t lItem;
    theItemFactory->createBoolean(lItem, aValue);
    return &*lItem;
  }
    
  Item 
  ItemFactoryImpl::createDecimalFromLong (unsigned long aValue)
  {
    store::Item_t lItem;

    // no error possible
    Decimal lDecimal = Decimal::parseULong(aValue);
    theItemFactory->createDecimal(lItem, lDecimal);
    return &*lItem;
  }
    
  Item 
  ItemFactoryImpl::createDecimalFromDouble (double aValue)
  {
    store::Item_t lItem;
    Decimal lDecimal;
    if (Decimal::parseNativeDouble(aValue, lDecimal)) {
      theItemFactory->createDecimal(lItem, lDecimal);
      return &*lItem;
    }

    return &*lItem;
  }

  Item 
  ItemFactoryImpl::createDecimal (const String& aValue)
  {
    store::Item_t lItem;
    xqpStringStore* lString = Unmarshaller::getInternalString( aValue );
    Decimal lDecimal;
    if (Decimal::parseString(lString->c_str(), lDecimal)) {
      theItemFactory->createDecimal(lItem, lDecimal);
      return &*lItem;
    }

    return &*lItem;
  }

  Item
  ItemFactoryImpl::createInteger(long long aInteger)
  {
    store::Item_t lItem;
    Integer lInteger = Integer::parseLongLong(aInteger);
    theItemFactory->createInteger(lItem, lInteger);
    return &*lItem;
  }

  Item
  ItemFactoryImpl::createInteger(const String& aInteger)
  {
    xqpStringStore* lString = Unmarshaller::getInternalString( aInteger );
    store::Item_t lItem;
    Integer lInteger;
    if (Integer::parseString(lString->c_str(), lInteger)) {
      theItemFactory->createInteger(lItem, lInteger);
      return &*lItem;
    }
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createLong ( long long aLong )
  {
    store::Item_t lItem;

    theItemFactory->createLong(lItem, aLong);
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createInt ( int aInt )
  {
    store::Item_t lItem;

    if ( (INT32_MIN <= aInt) && (aInt <= INT32_MAX) ) {
      theItemFactory->createInt(lItem, aInt);
    }

    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createShort ( short aShort )
  {
    store::Item_t lItem;

    theItemFactory->createShort(lItem, aShort);

    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createByte ( char aValue )
  {
    store::Item_t lItem;
  
    theItemFactory->createByte(lItem, aValue);

    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createDateTime(short aYear, short aMonth, short aDay,
                                  short aHour, short aMinute, double aSecond,
                                  short aTimezone_hours)
  {
    store::Item_t lItem;
    theItemFactory->createDateTime(lItem, aYear, aMonth, aDay, aHour, aMinute, aSecond, aTimezone_hours);

    return &*lItem;
  }

  Item
  ItemFactoryImpl::createDateTime( const String& aDateTimeValue )
  {
    xqpStringStore* lString = Unmarshaller::getInternalString( aDateTimeValue );

    store::Item_t lItem;
    theItemFactory->createDateTime(lItem,  lString );

    return &*lItem;
  }

  Item
  ItemFactoryImpl::createDouble ( double aValue )
  {
    store::Item_t lItem;
    Double lDouble = Double::parseFloatType(aValue);
    theItemFactory->createDouble(lItem, lDouble);
    return &*lItem;
  }

  Item
  ItemFactoryImpl::createDouble ( const String& aValue )
  {
    xqpStringStore* lString = Unmarshaller::getInternalString( aValue );
  
    store::Item_t lItem;
    Double lDouble;
    if (Double::parseString(lString->c_str(), lDouble)) {
      theItemFactory->createDouble(lItem, lDouble);
    } 
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createDuration( const String& aValue )
  {
    xqpStringStore* lString = Unmarshaller::getInternalString( aValue );
    const xqpString s(lString);
    store::Item_t   lItem;

    theItemFactory->createDuration(lItem, s);

    return &*lItem;
  }
      
  Item
  ItemFactoryImpl::createDuration ( short aYears, short aMonths, short aDays, 
                                    short aHours, short aMinutes, double aSeconds )
  {
    store::Item_t lItem;
    
    theItemFactory->createDuration(lItem, aYears, aMonths, aDays, aHours, aMinutes, aSeconds);
    
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createFloat ( const String& aValue )
  {
    xqpStringStore* lString = Unmarshaller::getInternalString( aValue );
    store::Item_t lItem;
    Float lFloat;
    if (Float::parseString(lString->c_str(), lFloat)) {
      theItemFactory->createFloat(lItem, lFloat);
    } 
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createFloat ( float aValue )
  {
    store::Item_t lItem;
    Float lFloat = Float::parseFloatType(aValue);
    theItemFactory->createFloat(lItem, lFloat);
    return &*lItem;
  }

  Item
  ItemFactoryImpl::createHexBinary ( const char* aHexData, size_t aSize )
  {
    store::Item_t lItem;
    xqp_hexBinary n;
    if (xqp_hexBinary::parseString(aHexData, aSize, n))
      theItemFactory->createHexBinary(lItem, n);
    
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createNegativeInteger ( long long aValue )
  {
    store::Item_t lItem;
    if (aValue < 0) {
      Integer lInteger;
      lInteger = Integer::parseLongLong(aValue);
      theItemFactory->createNegativeInteger(lItem, lInteger);
    }
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createNonNegativeInteger ( unsigned long long aValue )
  {
    store::Item_t lItem;
    Integer lInteger;
    lInteger = Integer::parseULongLong(aValue);
    theItemFactory->createNonNegativeInteger(lItem, lInteger);
    return &*lItem;
  }

  Item
  ItemFactoryImpl::createNonPositiveInteger ( long long aValue )
  {
    store::Item_t lItem;
    if (aValue < 0) {
      Integer lInteger;
      lInteger = Integer::parseLongLong(aValue);
      theItemFactory->createNonPositiveInteger(lItem, lInteger);
    }
    return &*lItem;
  }

  Item
  ItemFactoryImpl::createPositiveInteger ( unsigned long long aValue )
  {
    store::Item_t lItem;
    Integer lInteger;
    lInteger = Integer::parseLongLong(aValue);
    theItemFactory->createPositiveInteger(lItem, lInteger);
    return &*lItem;
  }

  Item
  ItemFactoryImpl::createGDay ( const String& aValue )
  {
    xqpStringStore* lString = Unmarshaller::getInternalString( aValue );
    store::Item_t lItem;

    theItemFactory->createGDay(lItem,  lString );
    
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGDay ( short aDay )
  {
    store::Item_t lItem;

    theItemFactory->createGDay(lItem,  aDay );
    
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGMonth ( short aMonth )
  {
    store::Item_t lItem;

    theItemFactory->createGMonth(lItem,  aMonth );
    
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGMonth ( const String& aValue )
  {
    xqpStringStore* lString = Unmarshaller::getInternalString( aValue );
    store::Item_t lItem;
    
    theItemFactory->createGMonth(lItem,  lString );
    
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGMonthDay ( const String& aValue )
  {
    xqpStringStore* lString = Unmarshaller::getInternalString( aValue );
    store::Item_t lItem;

    theItemFactory->createGMonthDay(lItem,  lString );
    
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGMonthDay ( short aMonth, short aDay )
  {
    store::Item_t lItem;

    theItemFactory->createGMonthDay(lItem,  aMonth, aDay );
    
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGYear ( const String& aValue )
  {
    xqpStringStore* lString = Unmarshaller::getInternalString( aValue );
    store::Item_t lItem;

    theItemFactory->createGYear(lItem,  lString );
    
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGYear ( short aYear )
  {
    store::Item_t lItem;

    theItemFactory->createGYear(lItem,  aYear );
    
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGYearMonth ( const String& aValue )
  {
    xqpStringStore* lString = Unmarshaller::getInternalString( aValue );
    store::Item_t lItem;
    
    theItemFactory->createGYearMonth(lItem,  lString );
    
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGYearMonth ( short aYear, short aMonth )
  {
    store::Item_t lItem;

    theItemFactory->createGYearMonth(lItem,  aYear, aMonth );
    
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createTime ( const String& aValue )
  {
    xqpStringStore* lString = Unmarshaller::getInternalString( aValue );
    store::Item_t lItem;

    theItemFactory->createTime(lItem,  lString );
    
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createTime ( short aHour, short aMinute, double aSecond )
  {
    store::Item_t lItem;

    theItemFactory->createTime(lItem,  aHour, aMinute, aSecond );
    
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createTime ( short aHour, short aMinute, double aSecond, short aTimezone_hours )
  {
    store::Item_t lItem;

    theItemFactory->createTime(lItem,  aHour, aMinute, aSecond, aTimezone_hours );
    
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createUnsignedByte(const unsigned char aValue)
  {
    store::Item_t lItem;
    theItemFactory->createUnsignedByte(lItem, aValue);
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createUnsignedInt(unsigned int aValue)
  {
    store::Item_t lItem;
    
    if ( aValue <= UINT32_MAX ) {
      theItemFactory->createUnsignedInt(lItem, aValue);
    }

    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createUnsignedLong(unsigned long long aValue)
  {
    store::Item_t lItem;
    theItemFactory->createUnsignedLong(lItem, aValue);
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createUnsignedShort(unsigned short aValue)
  {
    store::Item_t lItem;
    theItemFactory->createUnsignedShort(lItem, aValue);
    return &*lItem;
  }
} /* namespace zorba */
