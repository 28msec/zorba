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
#include "stdafx.h"

#include <zorba/item.h>

#include "diagnostics/xquery_diagnostics.h"
#include "zorbautils/lock.h"

#include "system/globalenv.h"

#include "api/resultiteratorimpl.h"
#include "api/unmarshaller.h"
#include "api/xqueryimpl.h"
#include "api/zorbaimpl.h"

#include "context/static_context.h"

#include "runtime/api/plan_wrapper.h"
#include "runtime/base/plan_iterator.h"

#include "store/api/item.h"
#include "store/api/store.h"
#include "common/shared_types.h"

namespace zorba {

#define RESULT_ITER_CATCH                                           \
catch (ZorbaException const &e)                                     \
{                                                                   \
  SYNC_CODE(                                                        \
  if (theHaveLock)                                                  \
  {                                                                 \
    GENV_STORE.getGlobalLock().unlock();                            \
    theHaveLock = false;                                            \
  })                                                                \
                                                                    \
  ZorbaImpl::notifyError(theQuery->theDiagnosticHandler, e);        \
}                                                                   \
catch (std::exception const& e)                                     \
{                                                                   \
  SYNC_CODE(                                                        \
  if (theHaveLock)                                                  \
  {                                                                 \
    GENV_STORE.getGlobalLock().unlock();                            \
    theHaveLock = false;                                            \
  })                                                                \
                                                                    \
  ZorbaImpl::notifyError(theQuery->theDiagnosticHandler, e.what()); \
}                                                                   \
catch (...)                                                         \
{                                                                   \
  SYNC_CODE(                                                        \
  if (theHaveLock)                                                  \
  {                                                                 \
    GENV_STORE.getGlobalLock().unlock();                            \
    theHaveLock = false;                                            \
  })                                                                \
                                                                    \
  ZorbaImpl::notifyError(theQuery->theDiagnosticHandler);           \
} 



/*******************************************************************************

********************************************************************************/
ResultIteratorImpl::ResultIteratorImpl(
    XQueryImpl* aQuery,
    const PlanWrapper_t& aPlanWrapper)
  :
  theQuery(aQuery),
  thePlan(aPlanWrapper),
  theIsOpen(false),
  theHaveLock(false)
{
}


/*******************************************************************************

********************************************************************************/
ResultIteratorImpl::~ResultIteratorImpl() 
{
  try
  {
    if (theIsOpen && thePlan)
    {
      thePlan->close();
    }

    SYNC_CODE(
    if (theHaveLock)
    {
      GENV_STORE.getGlobalLock().unlock();
      theHaveLock = false;
    })

    if (theQuery)
    {
      theQuery->removeResultIterator(this);
      theQuery = NULL;
    }
  }
  RESULT_ITER_CATCH
}


/*******************************************************************************

********************************************************************************/
void ResultIteratorImpl::open()
{
  try
  {
    if (!thePlan || !theQuery)
      throw ZORBA_EXCEPTION(zerr::ZAPI0042_ITERATOR_CLOSED);

    if (theIsOpen)  
      throw ZORBA_EXCEPTION(zerr::ZAPI0041_ITERATOR_ALREADY_OPEN);

    SYNC_CODE(
    if (!theHaveLock)
    {
      GENV_STORE.getGlobalLock().rlock();
      theHaveLock = true;
    })

    thePlan->open();

    theIsOpen = true;

    theQuery->theExecuting = true;
  } 
  RESULT_ITER_CATCH
}


/*******************************************************************************

********************************************************************************/
bool ResultIteratorImpl::next(Item& aItem)
{
  try
  {
    if (!thePlan)
      throw ZORBA_EXCEPTION(zerr::ZAPI0042_ITERATOR_CLOSED);

    if (!theIsOpen)  
      throw ZORBA_EXCEPTION(zerr::ZAPI0040_ITERATOR_NOT_OPEN);

    SYNC_CODE(
    if (!theHaveLock)
    {
      GENV_STORE.getGlobalLock().rlock();
      theHaveLock = true;
    })

    store::Item_t lItem;

    if (!thePlan->next(lItem))
      return false;
    
    aItem = &*lItem;
    return true;
  }
  RESULT_ITER_CATCH
  return false;
}


/*******************************************************************************

********************************************************************************/
void ResultIteratorImpl::close()
{
  try
  {
    if (!thePlan || !theQuery)
      throw ZORBA_EXCEPTION(zerr::ZAPI0042_ITERATOR_CLOSED);

    if (!theIsOpen)  
      throw ZORBA_EXCEPTION(zerr::ZAPI0040_ITERATOR_NOT_OPEN);

    thePlan->close();

    theIsOpen = false;

    theQuery->theExecuting = false;

    SYNC_CODE(
    if (theHaveLock)
    {
      GENV_STORE.getGlobalLock().unlock();
      theHaveLock = false;
    })
  }
  RESULT_ITER_CATCH
}


/*******************************************************************************
  Called only from the XQueryImpl::close() method
********************************************************************************/
void ResultIteratorImpl::closeInternal()
{
  if (theIsOpen)
  {
    thePlan->close();
    thePlan = NULL;

    theIsOpen = false;
  }

  SYNC_CODE(
  if (theHaveLock)
  {
    GENV_STORE.getGlobalLock().unlock();
    theHaveLock = false;
  })

  assert(theQuery);
  theQuery = NULL;
}


} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
