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
#include <zorba/item.h>

#include "api/resultiteratorimpl.h"
#include "api/zorbaimpl.h"

#include "store/api/item.h"
#include "runtime/api/plan_wrapper.h"
#include "errors/error_manager.h"

namespace zorba {

  ResultIteratorImpl::ResultIteratorImpl(const PlanWrapper_t& aPlanWrapper,
                                         error::ErrorManager* aErrorManager,
                                         ErrorHandler* aErrorHandler)
    : thePlan(aPlanWrapper),
      theIsOpened(false),
      theErrorManager(aErrorManager),
      theErrorHandler(aErrorHandler) {}

  ResultIteratorImpl::~ResultIteratorImpl() 
  {
    if (theIsOpened)
      thePlan->close();
  }
 
  void 
  ResultIteratorImpl::open()
  {
    ZORBA_TRY
      if ( ! theIsOpened ) {
        thePlan->open();
        theIsOpened = true;
      } 
    ZORBA_CATCH
  }

  bool
  ResultIteratorImpl::next(Item& aItem)
  {
    ZORBA_TRY
      store::Item_t lItem;
      if (!theIsOpened)  {
        ZORBA_ERROR_DESC(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED,
          "ResultIterator has not been opened");
       }

      lItem = thePlan->next();

      if (lItem == NULL)
        return false;
    
      if (lItem->isPul())
        ZORBA_ERROR(ZorbaError::API0024_CANNOT_ITERATE_OVER_UPDATE_QUERY);

      aItem = &*lItem;
      return true;
    ZORBA_CATCH
    return false;
  }

  void 
  ResultIteratorImpl::close()
  {
    ZORBA_TRY
      if (theIsOpened) {
        thePlan->reset();
      }
    ZORBA_CATCH
  }

} /* namespace zorba */
