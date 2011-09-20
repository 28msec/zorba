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
#pragma once
#ifndef ZORBA_ITERATOR_ITEM_SEQUENCE_API_H
#define ZORBA_ITERATOR_ITEM_SEQUENCE_API_H

#include <zorba/config.h>
#include <zorba/item_sequence.h>

namespace zorba { 

  class XQueryImpl;

  /** \brief A sequence backed by an iterator and it's corresponding query.
   *
   * See ItemSequence
   */
  class ZORBA_DLL_PUBLIC InvokeItemSequence : public ItemSequence
  {
    public:
      /**
       * Construct a sequence using an Iterator and its XQuery
       */
      InvokeItemSequence(XQueryImpl* aQuery, Iterator_t aIter);

      /** \brief Destructor
       */
      virtual ~InvokeItemSequence();

      /** \brief get the Iterator over the items
       * @return an iterator over the items
      */
      virtual Iterator_t  getIterator();

    protected:
      Iterator_t theIterator;
      XQueryImpl* theXQuery; // have ownership and destroy in destructor

  }; /* class InvokeItemSequence */

} // namespace zorba
#endif


/* vim:set et sw=2 ts=2: */
