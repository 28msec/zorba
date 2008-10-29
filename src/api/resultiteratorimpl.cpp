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

#include "zorbaerrors/error_manager.h"
#include "zorbautils/lock.h"

#include "system/globalenv.h"

#include "api/resultiteratorimpl.h"
#include "api/xqueryimpl.h"
#include "api/zorbaimpl.h"

#include "store/api/item.h"
#include "store/api/store.h"

#include "runtime/api/plan_wrapper.h"


namespace zorba {


#define RESULT_ITER_TRY try
 
#define RESULT_ITER_CATCH                                      \
catch (error::ZorbaError& e)                                   \
{                                                              \
  SYNC_CODE(                                                   \
  if (theHaveLock)                                             \
  {                                                            \
    GENV_STORE.getGlobalLock().unlock();                       \
    theHaveLock = false;                                       \
  })                                                           \
                                                               \
  ZorbaImpl::notifyError(theQuery->theErrorHandler, e);        \
}                                                              \
catch (std::exception& e)                                      \
{                                                              \
  SYNC_CODE(                                                   \
  if (theHaveLock)                                             \
  {                                                            \
    GENV_STORE.getGlobalLock().unlock();                       \
    theHaveLock = false;                                       \
  })                                                           \
                                                               \
  ZorbaImpl::notifyError(theQuery->theErrorHandler, e.what()); \
}                                                              \
catch (...)                                                    \
{                                                              \
  SYNC_CODE(                                                   \
  if (theHaveLock)                                             \
  {                                                            \
    GENV_STORE.getGlobalLock().unlock();                       \
    theHaveLock = false;                                       \
  })                                                           \
                                                               \
  ZorbaImpl::notifyError(theQuery->theErrorHandler);           \
} 



ResultIteratorImpl::ResultIteratorImpl(
    XQueryImpl* aQuery,
    const PlanWrapper_t& aPlanWrapper)
  :
  theQuery(aQuery),
  thePlan(aPlanWrapper),
  theIsOpened(false),
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

  theQuery->removeResultIterator(this);
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
    if (!theIsOpened)  
    {
      ZORBA_ERROR_DESC(API0010_XQUERY_EXECUTION_NOT_STARTED,
                       "ResultIterator has not been opened");
    }

    SYNC_CODE(
    if (!theHaveLock)
    {
      GENV_STORE.getGlobalLock().rlock();
      theHaveLock = true;
    })

    store::Item_t lItem;

    if (!thePlan->next(lItem))
      return false;
    
    if (lItem->isPul())
      ZORBA_ERROR(API0024_CANNOT_ITERATE_OVER_UPDATE_QUERY);

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
