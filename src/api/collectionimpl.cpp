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

#include "zorbaerrors/error_manager.h"
#include "zorbautils/lock.h"

#include "api/unmarshaller.h"

#include "system/globalenv.h"

#include "runtime/util/flowctl_exception.h"

#include "store/api/collection.h"
#include "store/api/item.h"
#include "store/api/store.h"
#include "store/api/copymode.h"


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
CollectionImpl::getName() const
{
  ZORBA_TRY
    return theCollection->getName();
  ZORBA_CATCH
  return Item();
}


unsigned long
CollectionImpl::size() const
{
  return theCollection->size();
}


bool
CollectionImpl::addDocument(std::istream& lInStream)
{
  ZORBA_TRY

    theCollection->loadDocument(lInStream);
    return true;

  ZORBA_CATCH
  return false;
}


bool
CollectionImpl::addNode(Item& aNode)
{
  ZORBA_TRY

    store::Item* lItem = Unmarshaller::getInternalItem(aNode);

    // Get the store lock to protect the node. 
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    store::CopyMode lCopyMode;
    store::Item* lCopy = lItem->copy(NULL, lCopyMode);

    theCollection->addNode(lCopy);

    return true;

  ZORBA_CATCH
  return false;
}


bool
CollectionImpl::addNodes(const Iterator_t& aIterator)
{
  ZORBA_TRY

    Iterator* lIter = aIterator.get();
    if (!lIter)
      throw ZORBA_EXCEPTION(
        ZAPI0014_INVALID_ARGUMENT, ERROR_PARAMS( "null", ZED( BadIterator ) )
      );

    store::Iterator_t lRes = Unmarshaller::getInternalIterator(lIter);

    // Get the store lock to protect the nodes. Note: the result iterator
    // also holds the store lock in R mode.
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    store::CopyMode lCopyMode;
    store::Item_t node;
    while (lRes->next(node))
    {
      store::Item* lCopy = node->copy(NULL, lCopyMode);
      theCollection->addNode(lCopy, -1);
    }

    return true;

  ZORBA_CATCH
  return false;
}


bool
CollectionImpl::deleteNode(Item& aNode)
{
  ZORBA_TRY

    store::Item* lItem = Unmarshaller::getInternalItem(aNode);

    // Make sure nobody else is accessing the node to delete. 
    // Not sure if we really need this ????? 
    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::WRITE);)

    ulong pos;
    return theCollection->removeNode(lItem, pos);

  ZORBA_CATCH
  return false;
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
