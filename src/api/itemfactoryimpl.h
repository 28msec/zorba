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
      createFloat ( const String& aValue );
    
      virtual Item
      createFloat ( float aValue );
    
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

    protected:
      store::ItemFactory* theItemFactory;

  }; /* class ItemFactoryImpl */

} /* namespace zorba */

#endif
