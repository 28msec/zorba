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
