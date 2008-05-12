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

#include "system/globalenv.h"

#include "api/resultiteratorimpl.h"
#include "api/zorbaimpl.h"

#include "store/api/item.h"
#include "store/api/store.h"
#include "store/util/latch.h"

#include "runtime/api/plan_wrapper.h"
#include "errors/error_manager.h"

namespace zorba {


#define RESULT_ITER_TRY try
 
#define RESULT_ITER_CATCH                             \
catch (error::ZorbaError& e)                          \
{                                                     \
  SYNC_CODE(                                          \
  if (theHaveLock)                                    \
  {                                                   \
    GENV_STORE.getGlobalLock().unlock();              \
    theHaveLock = false;                              \
  })                                                  \
                                                      \
  ZorbaImpl::notifyError(theErrorHandler, e);         \
}                                                     \
catch (std::exception& e)                             \
{                                                     \
  SYNC_CODE(                                          \
  if (theHaveLock)                                    \
  {                                                   \
    GENV_STORE.getGlobalLock().unlock();)             \
    theHaveLock = false;                              \
  }                                                   \
                                                      \
  ZorbaImpl::notifyError(theErrorHandler, e.what());  \
}                                                     \
catch (...)                                           \
{                                                     \
  SYNC_CODE(                                          \
  if (theHaveLock)                                    \
  {                                                   \
    GENV_STORE.getGlobalLock().unlock();              \
    theHaveLock = false;                              \
  })                                                  \
                                                      \
  ZorbaImpl::notifyError(theErrorHandler);            \
} 



ResultIteratorImpl::ResultIteratorImpl(
    const PlanWrapper_t& aPlanWrapper,
    error::ErrorManager* aErrorManager,
    ErrorHandler* aErrorHandler)
  :
  thePlan(aPlanWrapper),
  theIsOpened(false),
  theErrorManager(aErrorManager),
  theErrorHandler(aErrorHandler),
  theHaveLock(false)
{
}


ResultIteratorImpl::~ResultIteratorImpl() 
{
  if (theIsOpened)
    thePlan->close();

  SYNC_CODE(
  if (theHaveLock)
    GENV_STORE.getGlobalLock().unlock();)
}
 

void 
ResultIteratorImpl::open()
{
  RESULT_ITER_TRY
  {
    SYNC_CODE(
    if (!theHaveLock)
    {
      GENV_STORE.getGlobalLock().rlock();
      theHaveLock = true;
    })

    if ( ! theIsOpened )
    {
      thePlan->open();
      theIsOpened = true;
    }
  } 
  RESULT_ITER_CATCH
}


bool
ResultIteratorImpl::next(Item& aItem)
{
  RESULT_ITER_TRY
  {
    store::Item_t lItem;

    if (!theIsOpened)  
    {
      ZORBA_ERROR_DESC(ZorbaError::API0010_XQUERY_EXECUTION_NOT_STARTED,
                       "ResultIterator has not been opened");
    }

    SYNC_CODE(
    if (!theHaveLock)
    {
      GENV_STORE.getGlobalLock().rlock();
      theHaveLock = true;
    })

    lItem = thePlan->next();

    if (lItem == NULL)
      return false;
    
    if (lItem->isPul())
      ZORBA_ERROR(ZorbaError::API0024_CANNOT_ITERATE_OVER_UPDATE_QUERY);

    aItem = &*lItem;
    return true;
  }
  RESULT_ITER_CATCH
  return false;
}


void 
ResultIteratorImpl::close()
{
  RESULT_ITER_TRY
  {
    if (theIsOpened) {
      thePlan->reset();
    }

    SYNC_CODE(
    if (theHaveLock)
    {
      GENV_STORE.getGlobalLock().unlock();
      theHaveLock = false;
    })
  }
  RESULT_ITER_CATCH
}


} /* namespace zorba */
