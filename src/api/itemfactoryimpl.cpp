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
  ItemFactoryImpl::createDate( const String& aDateValue )
  {
    xqpStringStore* lString = Unmarshaller::getInternalString( aDateValue );

    store::Item_t lItem;
    lItem = theItemFactory->createDate( lString );

    return &*lItem;
  }
} /* namespace zorba */
