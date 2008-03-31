#ifndef ZORBA_ITEM_FACTORY_API_H
#define ZORBA_ITEM_FACTORY_API_H

#include <zorba/api_shared_types.h>

namespace zorba {
  
  class ItemFactory 
  {
    public:
      virtual ~ItemFactory() {}

      virtual Item
      createInteger(int aInteger) = 0;

      virtual Item
      createString(const String& aString) = 0;

      virtual Item
      createAnyURI(const String& aURI) = 0;

      virtual Item
      createDateTime(short year, short month, short day, 
                     short hour, short minute, short second, short timeZone) = 0;

      virtual Item
      createDateTime( const String& aDateTimeValue ) = 0;


  }; /* class ItemFactory */

} /* namespace zorba */

#endif
