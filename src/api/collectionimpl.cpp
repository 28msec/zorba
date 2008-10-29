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
#include "api/collectionimpl.h"
#include <zorba/item.h>
#include <zorba/error_handler.h>
#include <istream>
#include "api/zorbaimpl.h"

#include <zorba/exception.h>

#include "zorbaerrors/errors.h"
#include "zorbaerrors/error_manager.h"
#include "zorbautils/lock.h"

#include "api/unmarshaller.h"

#include "system/globalenv.h"

#include "runtime/api/plan_wrapper.h"

#include "store/api/collection.h"
#include "store/api/item.h"
#include "store/api/store.h"


namespace zorba {

CollectionImpl::CollectionImpl(
    const store::Collection_t& aCollection,
    ErrorHandler* aErrorHandler)
  :
  theCollection(aCollection),
  theErrorHandler(aErrorHandler)
{
}


CollectionImpl::~CollectionImpl()
{
}

 
Item
CollectionImpl::getUri() const
{
  ZORBA_TRY
    return theCollection->getUri();
  ZORBA_CATCH
  return Item();
}


unsigned long
CollectionImpl::size() const
{
  return theCollection->size();
}



bool
CollectionImpl::addNode(const Item& aNode, long aPosition)
{
  ZORBA_TRY

    store::Item* lItem = Unmarshaller::getInternalItem(aNode);

    SYNC_CODE(AutoLock(GENV_STORE.getGlobalLock(), Lock::WRITE);)

    //check if the item is already in the collection
    theCollection->addToCollection(lItem, aPosition);
    return true;

  ZORBA_CATCH
    return false;
}

bool
CollectionImpl::addNode(const Item& aNode, const Item& aTargetNode, bool aOrder)
{
  ZORBA_TRY

    store::Item* lItem = Unmarshaller::getInternalItem(aNode);
    store::Item* targetItem = Unmarshaller::getInternalItem(aTargetNode);

    SYNC_CODE(AutoLock(GENV_STORE.getGlobalLock(), Lock::WRITE);)

    theCollection->addNode(lItem, targetItem, aOrder);

    return true;

  ZORBA_CATCH
    return false;
}


bool
CollectionImpl::addNodes(const ResultIterator* aResultIterator)
{
  ZORBA_TRY

    PlanWrapper_t lPlan = Unmarshaller::getInternalPlan(aResultIterator);

    SYNC_CODE(AutoLock(GENV_STORE.getGlobalLock(), Lock::WRITE);)

    theCollection->addToCollection(&*lPlan);
    return true;

  ZORBA_CATCH
  return false;
}


bool
CollectionImpl::addDocument(std::istream& lInStream, long aPosition)
{
  ZORBA_TRY
    theCollection->addToCollection(lInStream, aPosition);
    return true;
  ZORBA_CATCH
  return false;
}


bool
CollectionImpl::deleteNode(const Item& aNode)
{
  ZORBA_TRY
    store::Item* lItem = Unmarshaller::getInternalItem(aNode);

    SYNC_CODE(AutoLock(GENV_STORE.getGlobalLock(), Lock::WRITE);)

    theCollection->removeFromCollection(lItem);
    return true;
  ZORBA_CATCH
  return false;
}


bool
CollectionImpl::deleteNode(long aPosition)
{
  ZORBA_TRY
    theCollection->removeFromCollection(aPosition);
    return true;
  ZORBA_CATCH
  return false;
}


Item
CollectionImpl::nodeAt(long aPosition)
{
  ZORBA_TRY
      return theCollection->nodeAt(aPosition).getp();
  ZORBA_CATCH
      return Item();
}

long
CollectionImpl::indexOf(const Item& aNode)
{
  ZORBA_TRY
      store::Item* lItem = Unmarshaller::getInternalItem(aNode);

  SYNC_CODE(AutoLock(GENV_STORE.getGlobalLock(), Lock::WRITE);)

      theCollection->indexOf(lItem);
  return true;
  ZORBA_CATCH
      return false;
}

} /* namespace zorba */
