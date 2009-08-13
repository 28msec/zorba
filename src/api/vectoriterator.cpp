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
#include "api/vectoriterator.h"

#include <zorba/item.h>

#include "system/globalenv.h"

#include "zorbaerrors/error_manager.h"
#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/store.h"

namespace zorba {

#define RESULT_ITERATOR_TRY try {
 
#define RESULT_ITERATOR_CATCH                                  \
} catch (error::ZorbaError& /*e*/)                             \
{                                                              \
}                                                              \
catch (std::exception& /*e*/)                                  \
{                                                              \
}                                                              \
catch (...)                                                    \
{                                                              \
} 

  VectorIterator::VectorIterator(const std::vector<store::Item_t>& aVector,
                                 ErrorHandler* aErrorHandler)
    : theVector(aVector),
      theErrorHandler(aErrorHandler),
      theIsOpened(false)
  {
  }

  VectorIterator::~VectorIterator()
  {
  }

  void 
  VectorIterator::open()
  {
    RESULT_ITERATOR_TRY
      if ( theIsOpened )
      {
        ZORBA_ERROR_DESC(API0010_XQUERY_EXECUTION_NOT_STARTED,
                         "Iterator has already been opened");
      }
      theIter = theVector.begin();
      theIsOpened = true;
    RESULT_ITERATOR_CATCH
  }

  bool
  VectorIterator::next(Item& aItem)
  {
    RESULT_ITERATOR_TRY
      if (!theIsOpened)  
      {
        ZORBA_ERROR_DESC(API0010_XQUERY_EXECUTION_NOT_STARTED,
                         "Iterator has not been opened");
      }

      if (theIter == theVector.end()) 
        return false;
      
      aItem = &**theIter;
      ++theIter;
      return true;
    RESULT_ITERATOR_CATCH
    return false;
  }

  void 
  VectorIterator::close()
  {
  }

} /* namespace zorba */
