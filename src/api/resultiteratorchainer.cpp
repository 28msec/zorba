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
#include "api/resultiteratorchainer.h"

#include <zorba/result_iterator.h>
#include <zorba/item.h>
#include "store/api/item.h"
#include "api/unmarshaller.h"

namespace zorba { namespace store {

ResultIteratorChainer::ResultIteratorChainer(ResultIterator* aResIter) 
  :
  theResult(aResIter)
{
}


ResultIteratorChainer::~ResultIteratorChainer() 
{
}


void
ResultIteratorChainer::open() 
{
  theResult->open();
}


Item_t
ResultIteratorChainer::next() 
{
  Item_t lStoreItem;

  ::zorba::Item lItem;
  while ( theResult->next(lItem) ) {
    return Unmarshaller::getInternalItem(lItem); 
  }

  return NULL;
}


void
ResultIteratorChainer::reset() 
{
  theResult->close();
}


void
ResultIteratorChainer::close() 
{
  theResult->close();
}

} // namespace store
} // namespace zorba

