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
#include "api/iteratorimpl.h"

#include <zorba/item.h>

#include "system/globalenv.h"

#include "zorbaerrors/error_manager.h"
#include "zorbautils/lock.h"
#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/store.h"

namespace zorba {

#define RESULT_ITERATOR_TRY try {
 
#define RESULT_ITERATOR_CATCH                                  \
} catch (error::ZorbaError& /*e*/)                             \
{                                                              \
  SYNC_CODE(                                                   \
  if (theHaveLock)                                             \
  {                                                            \
    GENV_STORE.getGlobalLock().unlock();                       \
    theHaveLock = false;                                       \
  })                                                           \
                                                               \
}                                                              \
catch (std::exception& /*e*/)                                  \
{                                                              \
  SYNC_CODE(                                                   \
  if (theHaveLock)                                             \
  {                                                            \
    GENV_STORE.getGlobalLock().unlock();                       \
    theHaveLock = false;                                       \
  })                                                           \
                                                               \
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
} 

  IteratorImpl::IteratorImpl(store::Iterator_t aIter, ErrorHandler* aErrorHandler)
    : theIterator(aIter),
      theErrorHandler(aErrorHandler),
      theIsOpened(false),
      theHaveLock(false)
  {
  }

  IteratorImpl::~IteratorImpl()
  {
    if (theIsOpened)
      theIterator->close();

    SYNC_CODE(
    if (theHaveLock)
      GENV_STORE.getGlobalLock().unlock();)
  }

  void 
  IteratorImpl::open()
  {
    RESULT_ITERATOR_TRY
      SYNC_CODE(
      if (!theHaveLock)
      {
        GENV_STORE.getGlobalLock().rlock();
        theHaveLock = true;
      })

      if ( ! theIsOpened )
      {
        theIterator->open();
        theIsOpened = true;
      }
    RESULT_ITERATOR_CATCH
  }

  bool
  IteratorImpl::next(Item& aItem)
  {
    RESULT_ITERATOR_TRY
      if (!theIsOpened)  
      {
        ZORBA_ERROR_DESC(API0010_XQUERY_EXECUTION_NOT_STARTED,
                         "Iterator has not been opened");
      }

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
    RESULT_ITERATOR_CATCH
    return false;
  }

  void 
  IteratorImpl::close()
  {
    RESULT_ITERATOR_TRY
      if (theIsOpened) {
        theIterator->reset();
      }

      SYNC_CODE(
      if (theHaveLock)
      {
        GENV_STORE.getGlobalLock().unlock();
        theHaveLock = false;
      })
    RESULT_ITERATOR_CATCH
  }

} /* namespace zorba */
