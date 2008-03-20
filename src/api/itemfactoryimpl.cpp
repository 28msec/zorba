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
  ItemFactoryImpl::createString(String aString)
  {
    xqpStringStore* lString = Unmarshaller::getInternalString(aString);

    store::Item_t lItem;
    lItem = theItemFactory->createString(lString);

    return &*lItem;
  }

  Item
  ItemFactoryImpl::createAnyURI(String aURI)
  {
    xqpStringStore* lString = Unmarshaller::getInternalString(aURI);

    store::Item_t lItem;
    lItem = theItemFactory->createAnyURI(lString);

    return &*lItem;
  }

} /* namespace zorba */
