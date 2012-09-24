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
#ifndef ZORBA_ITEM_FACTORY_IMPL_H
#define ZORBA_ITEM_FACTORY_IMPL_H

#include <istream>

#include <zorba/item_factory.h>

#include <zorba/api_shared_types.h>
#include "common/shared_types.h"
#include "util/singleton.h"

namespace zorba {
  
  class ItemFactoryImpl : public ItemFactory
  {
    private:
      friend struct Loki::CreateUsingNew<ItemFactoryImpl>;
      ItemFactoryImpl();

      virtual ~ItemFactoryImpl();

    public:
      virtual Item
      createString(const String& aString);

      virtual Item
      createStreamableString( std::istream&,
                              StreamReleaser,
                              bool seekable = false );

      virtual Item
      createAnyURI(const String& aURI);

      virtual Item
      createQName(const String& aNamespace, const String& aPrefix,
                  const String& aLocalname);

      virtual Item
      createQName(const String& aNamespace, const String& aLocalname);

      virtual Item
      createQName(const String& aQNameString);

      virtual Item 
      createNCName(const String& aValue);
    
      virtual Item 
      createBase64Binary(const char* aBinData, size_t aLength);

      virtual Item
      createBase64Binary(std::istream& aStream);
      
      virtual Item 
      createBase64Binary(const unsigned char* aBinData, size_t aLength);

      virtual Item
      createStreamableBase64Binary(
          std::istream &stream,
          StreamReleaser streamReleaser,
          bool seekable = false,
          bool encoded = false);

      virtual Item 
      createBoolean(bool aValue);
    
      virtual Item 
      createDecimalFromLong (unsigned long aValue);
    
      virtual Item 
      createDecimalFromDouble (double aValue);

      virtual Item 
      createDecimal (const String& aValue);

      virtual Item
      createInteger(long long aInteger);

      virtual Item
      createInteger(const String& aInteger);
    
      virtual Item
      createLong ( long long aLong );
    
      virtual Item
      createInt ( int aInt );
    
      virtual Item
      createShort ( short aShort );
    
      virtual Item
      createByte ( char value );
    
      virtual Item
      createDate ( const String& aDate );

      virtual Item
      createDate ( short aYear, short aMonth, short aDay );

      virtual Item
      createDateTime(short aYear, short aMonth, short aDay, 
                     short aHour, short aMinute, double aSecond,
                     short aTimezone_hours);

      virtual Item
      createDateTime(short aYear, short aMonth, short aDay,
                     short aHour, short aMinute, double aSecond);

      virtual Item
      createDateTime( const String& aDateTimeValue );

      virtual Item
      createDouble ( double aValue );

      virtual Item
      createDouble ( const String& aValue );
    
      virtual Item
      createDuration( const String& aValue );
      
      virtual Item
      createDuration ( short aYears, short aMonths, short aDays, 
                       short aHours, short aMinutes, double aSeconds );

      virtual Item
      createDayTimeDuration( const String& aValue );

      virtual Item
      createYearMonthDuration( const String& aValue );

      virtual Item
      createDocumentNode( const String& aBaseUri, const String& aDocUri );

      virtual Item
      createFloat ( const String& aValue );
    
      virtual Item
      createFloat ( float aValue );
    
      virtual Item
      createGDay ( const String& value );
    
      virtual Item
      createGDay ( short aDay );
    
      virtual Item
      createGMonth ( short aMonth );
    
      virtual Item
      createGMonth ( const String& aValue );
    
      virtual Item
      createGMonthDay ( const String& aValue );
    
      virtual Item
      createGMonthDay ( short aMonth, short aDay );
    
      virtual Item
      createGYear ( const String& value );
    
      virtual Item
      createGYear ( short aYear );
    
      virtual Item
      createGYearMonth ( const String& value );
    
      virtual Item
      createGYearMonth ( short aYear, short aMonth );
    
      virtual Item
      createHexBinary ( const char* aHexData, size_t aSize );

      virtual Item
      createNegativeInteger ( long long aValue );

      virtual Item
      createNonNegativeInteger ( unsigned long long aValue );

      virtual Item
      createNonPositiveInteger ( long long aValue );
    
      virtual Item
      createPositiveInteger ( unsigned long long aValue );

      virtual Item
      createTime ( const String& aValue );
    
      virtual Item
      createTime ( short aHour, short aMinute, double aSecond );
    
      virtual Item
      createTime ( short aHour, short aMinute, double aSecond, short aTimezone_hours );
    
      virtual Item
      createUnsignedByte(const unsigned char aValue);
    
      virtual Item
      createUnsignedInt(unsigned int aValue);
    
      virtual Item
      createUnsignedLong(unsigned long long aValue);
    
      virtual Item
      createUnsignedShort(unsigned short aValue);

      virtual Item
      createElementNode(Item& aParent,
                        Item aNodeName,
                        Item aTypeName,
                        bool aHasTypedValue,
                        bool aHasEmptyValue,
                        NsBindings aNsBindings);

      virtual void
      assignElementTypedValue(Item& aElement,
                              Item aTypedValue);

      virtual void
      assignElementTypedValue(Item& aElement,
                              std::vector<Item>& aTypedValue);

      virtual Item
      createAttributeNode(Item aParent,
        Item aNodeName,
        Item aTypeName,
        Item aTypedValue);

      virtual Item
      createAttributeNode(Item aParent,
        Item aNodeName,
        Item aTypeName,
        std::vector<Item> aTypedValue);

      virtual Item
      createCommentNode (
        Item   aParent,
        String &aContent);

      virtual Item 
      createPiNode (
        Item   aParent,
        String &aTarget,
        String &aContent,
        String &aBaseUri);

      virtual Item 
      createTextNode(
        Item   parent,
        String content);

#ifdef ZORBA_WITH_JSON
      virtual Item
      createJSONNull();

      virtual Item
      createJSONNumber(String aString);

      virtual Item
      createJSONObject(std::vector<std::pair<Item, Item> >& aPairs);

      virtual Item
      createJSONArray(std::vector<Item>& aItems);

#endif /* ZORBA_WITH_JSON */

      virtual Item
      createUserTypedAtomicItem(Item& aBaseItem, Item& aTypeName);

    protected:
      store::ItemFactory* theItemFactory;

  }; /* class ItemFactoryImpl */

  typedef Loki::SingletonHolder<ItemFactoryImpl,
                                Loki::CreateUsingNew,
                                Loki::DeletableSingleton> ItemFactorySingleton;

} // namespace zorba

#endif
/* vim:set et sw=2 ts=2: */
