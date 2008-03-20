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
      createInteger(int aInteger);

      virtual Item
      createString(String aString);

      virtual Item
      createAnyURI(String aURI);

    protected:
      store::ItemFactory* theItemFactory;

  }; /* class ItemFactoryImpl */

} /* namespace zorba */

#endif
