#include <zorba/item.h>
#include "api/itemfactoryimpl.h"

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
  ItemFactoryImpl::createInteger(int aInteger) 
  {
    store::Item_t lItem;
    lItem = theItemFactory->createInt(aInteger);

    return &*lItem;
  }

  Item
  ItemFactoryImpl::createString(const String& aString)
  {
    xqpStringStore* lString = Unmarshaller::getInternalString(aString);

    store::Item_t lItem;
    lItem = theItemFactory->createString(lString);

    return &*lItem;
  }

  Item
  ItemFactoryImpl::createAnyURI(const String& aURI)
  {
    xqpStringStore* lString = Unmarshaller::getInternalString(aURI);

    store::Item_t lItem;
    lItem = theItemFactory->createAnyURI(lString);

    return &*lItem;
  }

  Item
  ItemFactoryImpl::createDate( const String& aDateValue )
  {
    xqpStringStore* lString = Unmarshaller::getInternalString( aDateValue );

    store::Item_t lItem;
    lItem = theItemFactory->createDate( lString );

    return &*lItem;
  }

  Item
  ItemFactoryImpl::createQName(const String& aNamespace, const String& aPrefix,
                               const String& aLocalname)
  {
    store::Item_t lItem;
    return &*lItem;
  }

  Item
  ItemFactoryImpl::createQName(const String& aNamespace, const String& aLocalname)
  {
    store::Item_t lItem;
    return &*lItem;
  }

  Item 
  ItemFactoryImpl::createNCName(const String& aValue)
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item 
  ItemFactoryImpl::createBase64Binary(const char* aBinData, size_t aLength)
  {
    store::Item_t lItem;
    return &*lItem;
  }
      
  Item 
  ItemFactoryImpl::createBoolean(bool aValue)
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item 
  ItemFactoryImpl::createDecimal (unsigned long aValue)
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item 
  ItemFactoryImpl::createDecimal (double aValue)
  {
    store::Item_t lItem;
    return &*lItem;
  }

  Item 
  ItemFactoryImpl::createDecimal (const String& aValue)
  {
    store::Item_t lItem;
    return &*lItem;
  }

  Item
  ItemFactoryImpl::createInteger(long aInteger)
  {
    store::Item_t lItem;
    return &*lItem;
  }

  Item
  ItemFactoryImpl::createInteger(const String& aInteger)
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createLong ( long long aLong )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createInt ( int aInt )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createShort ( short aShort )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createByte ( char value )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createDate ( short aYear, short aMonth, short aDay )
  {
    store::Item_t lItem;
    return &*lItem;
  }

  Item
  ItemFactoryImpl::createDateTime(short year, short month, short day, 
                                  short hour, short minute, short second, 
                                  short timezone)
  {
    store::Item_t lItem;
    lItem = theItemFactory->createDateTime(year, month, day, hour, minute, second, timezone);

    return &*lItem;
  }

  Item
  ItemFactoryImpl::createDateTime( const String& aDateTimeValue )
  {
    xqpStringStore* lString = Unmarshaller::getInternalString( aDateTimeValue );

    store::Item_t lItem;
    lItem = theItemFactory->createDateTime( lString );

    return &*lItem;
  }

  Item
  ItemFactoryImpl::createDouble ( double aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }

  Item
  ItemFactoryImpl::createDouble ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createDuration( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
      
  Item
  ItemFactoryImpl::createDuration ( short aYears, short aMonths, short aDays, 
                       short aHours, short aMinutes, short aSeconds )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item 
  ItemFactoryImpl::createENTITIES ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
      
  Item
  ItemFactoryImpl::createENTITY ( const String& value )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createFloat ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGDay ( const String& value )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGDay ( short aDay )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGMonth ( short& aMonth )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGMonth ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGMonthDay ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGMonthDay ( short month, short day )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGYear ( const String& value )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGYear ( short year )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGYearMonth ( const String& value )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createGYearMonth ( short year, short month )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createHexBinary ( const char* aHexData, size_t aSize )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createID ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createIDREF ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createIDREFS ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createLanguage ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createNMTOKEN ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createNMTOKENS ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createNOTATION ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createName ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createNegativeInteger ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createNegativeInteger ( long aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }

  Item
  ItemFactoryImpl::createNonNegativeInteger ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createNonNegativeInteger ( unsigned long aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }

  Item
  ItemFactoryImpl::createNonPositiveInteger ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createNonPositiveInteger ( long aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }

  Item
  ItemFactoryImpl::createNormalizedString ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createPositiveInteger ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createPositiveInteger ( unsigned long aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }

  Item
  ItemFactoryImpl::createTime ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createTime ( short aHour, short aMinute, short aSecond )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createTime ( short aHour, short aMinute, short aSecond, short aTimezone )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createToken ( const String& aValue )
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createUnsignedByte(const char aValue)
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createUnsignedInt(unsigned int aValue)
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createUnsignedLong(unsigned long aValue)
  {
    store::Item_t lItem;
    return &*lItem;
  }
    
  Item
  ItemFactoryImpl::createUnsignedShort(unsigned short aValue)
  {
    store::Item_t lItem;
    return &*lItem;
  }
} /* namespace zorba */
