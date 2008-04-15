#include "api/collectionimpl.h"
#include <zorba/item.h>
#include <zorba/error_handler.h>
#include <istream>
#include "api/zorbaimpl.h"

#include <zorba/exception.h>
#include "errors/errors.h"
#include "errors/error_manager.h"
#include "api/unmarshaller.h"

#include "runtime/api/plan_wrapper.h"

#include "store/api/collection.h"
#include "store/api/item.h"

namespace zorba {

  CollectionImpl::CollectionImpl(const store::Collection_t& aCollection, ErrorHandler* aErrorHandler)
    : theCollection(aCollection),
      theErrorHandler(aErrorHandler)
  {
  }

  CollectionImpl::~CollectionImpl() {}
 
  Item
  CollectionImpl::getUri() 
  {
    ZORBA_TRY
      return &*theCollection->getUri();
    ZORBA_CATCH
    return Item();
  }
 
  bool
  CollectionImpl::addItem(const Item& aItem) 
  {
    ZORBA_TRY
      store::Item* lItem = Unmarshaller::getInternalItem(aItem);
      theCollection->addToCollection(lItem);
      return true;
    ZORBA_CATCH
    return false;
  }
 
  bool
  CollectionImpl::deleteItem(const Item& aItem) 
  {
    ZORBA_TRY
      store::Item* lItem = Unmarshaller::getInternalItem(aItem);
      theCollection->removeFromCollection(lItem);
      return true;
    ZORBA_CATCH
    return false;
  }
 
  bool
  CollectionImpl::addItems(const ResultIterator_t& aResultIterator) 
  {
    ZORBA_TRY
      PlanWrapper_t lPlan = Unmarshaller::getInternalPlan(aResultIterator);
      theCollection->addToCollection(&*lPlan);
      return true;
    ZORBA_CATCH
    return false;
  }

  bool
  CollectionImpl::addDocument(std::istream& lInStream)
  {
    ZORBA_TRY
      theCollection->addToCollection(lInStream);
      return true;
    ZORBA_CATCH
    return false;
  }

} /* namespace zorba */
