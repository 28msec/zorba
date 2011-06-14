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

#include "api/unmarshaller.h"

#include <zorba/item.h>
#include <zorba/zorba_string.h>
#include <zorba/iterator.h>
#include "api/staticcontextimpl.h"
#include "api/dynamiccontextimpl.h"
#include "api/storeiteratorimpl.h"
#include "api/collectionimpl.h"
#include "store/api/collection.h"

namespace zorba {

/**
 * This class wraps a non-StoreIteratorImpl Iterator in order to
 * convert its interface to the interface of the internal zorba
 * iterators.
 */
class NonStoreIteratorWrapper : public store::Iterator
{
private:
  zorba::Iterator* theIter;

public:
  NonStoreIteratorWrapper(zorba::Iterator* aIter) : theIter(aIter)
  {
  }

  virtual void open()
  {
    theIter->open();
  }

  virtual bool next(store::Item_t& result)
  {
    Item lItem;
    while ( theIter->next(lItem) ) 
    {
      result = Unmarshaller::getInternalItem(lItem);
      return true;
    }
    result = NULL;
    return false;
  }

  virtual void reset()
  {
    theIter->close();
    theIter->open();
  }
  
  virtual void close()
  {
    theIter->close();
  }
};


store::Item* Unmarshaller::getInternalItem(const Item& aItem)
{
  return aItem.m_item;
}


#define THE_STRING(STRING_OBJ)                                        \
  (const_cast<zstring*>(                                              \
    reinterpret_cast<zstring const*>( &(STRING_OBJ).string_storage_ ) \
  ))

zstring& Unmarshaller::getInternalString(const String& aString)
{
  return *THE_STRING( aString );
}

static_context* Unmarshaller::getInternalStaticContext(const StaticContext_t& aCtx)
{
  return static_cast<StaticContextImpl*>(aCtx.get())->theCtx;
}


dynamic_context* Unmarshaller::getInternalDynamicContext(DynamicContext* aCtx)
{
  return static_cast<DynamicContextImpl*>(aCtx)->theCtx; 
}


store::Iterator_t Unmarshaller::getInternalIterator(Iterator* aIter)
{
  StoreIteratorImpl* lStoreIter = dynamic_cast<StoreIteratorImpl*> (aIter);
  if (lStoreIter != NULL) {
    return lStoreIter->theIterator;
  }
  return store::Iterator_t(new NonStoreIteratorWrapper(aIter));
}


} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
