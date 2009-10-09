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
#ifndef ZORBA_VECTOR_ITEM_SEQUENCE_API_H
#define ZORBA_VECTOR_ITEM_SEQUENCE_API_H

#include <vector>

#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/item_sequence.h>

namespace zorba { 

  /** \brief This class is an implementation of the ItemSequence.
   *         Objects of this class return, on each next call, an
   *         Item of the vector that is passed to this object.
   *
   * See ItemSequence
   */
  class ZORBA_DLL_PUBLIC VectorItemSequence : public ItemSequence
  {
    public:
      /** \brief Constructor
       * 
       * @param aSequence the vector containing the sequence of Items
       */
      VectorItemSequence(const std::vector<Item>& aSequence);

      /** \brief Destructor
       */
      virtual ~VectorItemSequence() { }

      /** \brief Get the next Item of the vector that was passed
       *         in the constructor.
       *
       * @param aItem the next Item of the sequence if true is returned by the function.
       * @return true if the sequence is not exhausted, false otherwise.
       * @throw ZorbaException if an error occured.
       */
      virtual bool
      next(Item& aItem);

    protected:
      std::vector<Item> theSequence;
      std::vector<Item>::iterator theIterator;
      std::vector<Item>::iterator theEnd;

  }; /* class VectorItemSequence */

} // namespace zorba
#endif

