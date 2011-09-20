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
#ifndef ZORBA_SIMPLESTORE_DOCUMENT_NAME_ITERATOR_H
#define ZORBA_SIMPLESTORE_DOCUMENT_NAME_ITERATOR_H

#include "store/api/iterator.h"
#include "system/globalenv.h"

namespace zorba {

  namespace simplestore {

    /*******************************************************************************
    ********************************************************************************/
    template < typename T >
    class DocumentNameIterator : public store::Iterator
    {
    private:
      T&                   theItems;
      typename T::iterator theIterator;
      bool                 theOpened;
    
    public:
      DocumentNameIterator(const T& aItems)
        : theItems(*const_cast<T*>(&aItems)),
          theOpened(false)
      {
      }
    
      virtual ~DocumentNameIterator()
      {
        close();
      }
    
      virtual void open()
      {
        theIterator = theItems.begin();
        theOpened = true;
      }
    
      virtual bool next(store::Item_t& aResult)
      {
        if (theIterator == theItems.end())
        {
          aResult = NULL;
          return false;
        }
        else
        {
          zstring lUri = (*theIterator).first;
          GENV_ITEMFACTORY->createString(aResult, lUri);
          ++theIterator;
          return true;
        }
      }
    
      virtual void reset()
      {
        theIterator = theItems.begin();
      }
    
      virtual void close()
      {
        if (!theOpened) {
          return;
        }

        theOpened = false;
      }
    };

  } // namespace store
} // namespace zorba


#endif

/* vim:set et sw=2 ts=2: */
