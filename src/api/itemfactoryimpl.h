#ifndef ZORBA_ITEM_FACTORY_IMPL_H
#define ZORBA_ITEM_FACTORY_IMPL_H

#include <zorba/item_factory.h>

#include <zorba/api_shared_types.h>
#include "common/shared_types.h"

namespace zorba {
  
  class ItemFactoryImpl : public ItemFactory
  {
    public:
      static ItemFactoryImpl*
      getInstance();

      ItemFactoryImpl();

      virtual ~ItemFactoryImpl();

      virtual Item
      createString(const String& aString);

      virtual Item
      createAnyURI(const String& aURI);

      virtual Item
      createQName(const String& aNamespace, const String& aPrefix,
                  const String& aLocalname);

      virtual Item
      createQName(const String& aNamespace, const String& aLocalname);

      virtual Item 
      createNCName(const String& aValue);
    
      virtual Item 
      createBase64Binary(const char* aBinData, size_t aLength);
      
      virtual Item 
      createBoolean(bool aValue);
    
      virtual Item 
      createDecimal (unsigned long aValue);
    
      virtual Item 
      createDecimal (double aValue);

      virtual Item 
      createDecimal (const String& aValue);

      virtual Item
      createInteger(int aInteger);

      virtual Item
      createInteger(long aInteger);

      virtual Item
      createInteger(const String& aInteger);
    
      virtual Item
      createLong ( long long aLong );
    
      virtual Item
      createInt ( int32_t aInt );
    
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
                     short aHour, short aMinute, short aSecond, 
                     short aTimezone);

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
                       short aHours, short aMinutes, short aSeconds );
    
      virtual Item createENTITIES ( const String& aValue );
      
      virtual Item
      createENTITY ( const String& value );
    
      virtual Item
      createFloat ( const String& aValue );
    
      virtual Item
      createGDay ( const String& value );
    
      virtual Item
      createGDay ( short aDay );
    
      virtual Item
      createGMonth ( short& aMonth );
    
      virtual Item
      createGMonth ( const String& aValue );
    
      virtual Item
      createGMonthDay ( const String& aValue );
    
      virtual Item
      createGMonthDay ( short month, short day );
    
      virtual Item
      createGYear ( const String& value );
    
      virtual Item
      createGYear ( short year );
    
      virtual Item
      createGYearMonth ( const String& value );
    
      virtual Item
      createGYearMonth ( short year, short month );
    
      virtual Item
      createHexBinary ( const char* aHexData, size_t aSize );
    
      virtual Item
      createID ( const String& aValue );
    
      virtual Item
      createIDREF ( const String& aValue );
    
      virtual Item
      createIDREFS ( const String& aValue );
    
      virtual Item
      createLanguage ( const String& aValue );
    
      virtual Item
      createNMTOKEN ( const String& aValue );
    
      virtual Item
      createNMTOKENS ( const String& aValue );
    
      virtual Item
      createNOTATION ( const String& aValue );
    
      virtual Item
      createName ( const String& aValue );
    
      virtual Item
      createNegativeInteger ( const String& aValue );
    
      virtual Item
      createNegativeInteger ( long aValue );

      virtual Item
      createNonNegativeInteger ( const String& aValue );
    
      virtual Item
      createNonNegativeInteger ( unsigned long aValue );

      virtual Item
      createNonPositiveInteger ( const String& aValue );
    
      virtual Item
      createNonPositiveInteger ( long aValue );

      virtual Item
      createNormalizedString ( const String& aValue );
    
      virtual Item
      createPositiveInteger ( const String& aValue );
    
      virtual Item
      createPositiveInteger ( unsigned long aValue );

      virtual Item
      createTime ( const String& aValue );
    
      virtual Item
      createTime ( short aHour, short aMinute, short aSecond );
    
      virtual Item
      createTime ( short aHour, short aMinute, short aSecond, short aTimezone );
    
      virtual Item
      createToken ( const String& aValue );
    
      virtual Item
      createUnsignedByte(const char aValue);
    
      virtual Item
      createUnsignedInt(unsigned int aValue);
    
      virtual Item
      createUnsignedLong(unsigned long aValue);
    
      virtual Item
      createUnsignedShort(unsigned short aValue);

    protected:
      store::ItemFactory* theItemFactory;

  }; /* class ItemFactoryImpl */

} /* namespace zorba */

#endif
