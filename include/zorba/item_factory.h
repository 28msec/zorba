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
      createString(String aString) = 0;

      virtual Item
      createAnyURI(String aURI) = 0;


  }; /* class ItemFactory */

} /* namespace zorba */

#endif
