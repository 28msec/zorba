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
#include "api/storeiteratorimpl.h"

#include <zorba/item.h>

#include "system/globalenv.h"

#include "api/zorbaimpl.h"

#include "zorbaerrors/error_manager.h"

#include "zorbautils/lock.h"

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/store.h"

namespace zorba {

#define STORE_ITERATOR_CATCH                                   \
catch (ZorbaException const& e)                                \
{                                                              \
  SYNC_CODE(                                                   \
  if (theHaveLock)                                             \
  {                                                            \
    GENV_STORE.getGlobalLock().unlock();                       \
    theHaveLock = false;                                       \
  })                                                           \
                                                               \
  ZorbaImpl::notifyError(theErrorHandler, e);                  \
}                                                              \
catch (std::exception const& e)                                \
{                                                              \
  SYNC_CODE(                                                   \
  if (theHaveLock)                                             \
  {                                                            \
    GENV_STORE.getGlobalLock().unlock();                       \
    theHaveLock = false;                                       \
  })                                                           \
                                                               \
  ZorbaImpl::notifyError(theErrorHandler, e.what());           \
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
  ZorbaImpl::notifyError(theErrorHandler);                     \
} 


/*******************************************************************************

********************************************************************************/
StoreIteratorImpl::StoreIteratorImpl(
    store::Iterator_t aIter,
    ErrorHandler* aErrorHandler)
  :
  theIterator(aIter),
  theErrorHandler(aErrorHandler),
  theOwnErrorHandler(false),
  theIsOpen(false),
  theHaveLock(false)
{
  if (theErrorHandler == NULL)
  {
    theErrorHandler = new DefaultErrorHandler();
    theOwnErrorHandler = true;
  }
}


/*******************************************************************************

********************************************************************************/
StoreIteratorImpl::~StoreIteratorImpl()
{
  try
  {
    if (theIsOpen)
    {
      theIterator->close();
    }

    SYNC_CODE(
    if (theHaveLock)
      GENV_STORE.getGlobalLock().unlock();)

    if (theOwnErrorHandler)
      delete theErrorHandler;
  }
  STORE_ITERATOR_CATCH
}


/*******************************************************************************

********************************************************************************/
void StoreIteratorImpl::open()
{
  try
  {
    if (theIsOpen)  
      throw ZORBA_EXCEPTION(zerr::ZAPI0041_ITERATOR_ALREADY_OPEN);

    SYNC_CODE(
    if (!theHaveLock)
    {
      GENV_STORE.getGlobalLock().rlock();
      theHaveLock = true;
    })
    
    theIterator->open();
    
    theIsOpen = true;
  }
  STORE_ITERATOR_CATCH
}


/*******************************************************************************

********************************************************************************/
bool StoreIteratorImpl::next(Item& aItem)
{
  try
  {
    if (!theIsOpen)  
      throw ZORBA_EXCEPTION(zerr::ZAPI0040_ITERATOR_NOT_OPEN);

    SYNC_CODE(
    if (!theHaveLock)
    {
      GENV_STORE.getGlobalLock().rlock();
      theHaveLock = true;
    })

    store::Item_t lItem;

    if (!theIterator->next(lItem))
      return false;
      
    aItem = &*lItem;
    return true;
  }
  STORE_ITERATOR_CATCH
  return false;
}


/*******************************************************************************

********************************************************************************/
void StoreIteratorImpl::close()
{
  try
  {
    if (!theIsOpen)  
      throw ZORBA_EXCEPTION(zerr::ZAPI0040_ITERATOR_NOT_OPEN);

    theIterator->close();

    theIsOpen = false;

    SYNC_CODE(
    if (theHaveLock)
    {
      GENV_STORE.getGlobalLock().unlock();
      theHaveLock = false;
    })
  }
  STORE_ITERATOR_CATCH
}


} /* namespace zorba */
