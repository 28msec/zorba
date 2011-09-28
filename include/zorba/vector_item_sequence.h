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
#include <zorba/iterator.h>

namespace zorba { 

  /** \brief This class is an implementation of the ItemSequence.
   *         Objects of this class return, on each next call, an
   *         Item of the vector that is passed to this object.
   *
   * See ItemSequence
   */
  class ZORBA_DLL_PUBLIC VectorItemSequence : public ItemSequence
  {
    class InternalIterator : public Iterator
    {
    private:
      VectorItemSequence   *theItemSequence;
      std::vector<Item>::iterator theIterator;
      std::vector<Item>::iterator theEnd;
      bool is_open;
    public:
      InternalIterator(VectorItemSequence *item_sequence);

      /** \brief Start iterating.
       *
       * This function needs to be called before calling next().
       * Initializes the iterator over the items vector.
       *
       */
      virtual void open();
      /** \brief Get the next Item of the vector of items from ItemSequence.
       *
       * @param aItem the next Item of the sequence if true is returned by the function.
       * @return true if the vector is not exhausted, false otherwise.
       * @throw ZorbaException if iterator is not open or an error occured.
       */
      virtual bool next(Item& aItem);
      /** \brief Close the iterator.
       *
       * You can call close and open to reset the iterator.
       *
       */
      virtual void close();
      /**
       * brief Check whether the iterator is open or not
       */
      virtual bool isOpen() const;
    };
    public:
      /** \brief Constructor
       * 
       * @param aSequence the vector containing the sequence of Items
       */
      VectorItemSequence(const std::vector<Item>& aSequence);

      /** \brief Destructor
       */
      virtual ~VectorItemSequence() { }

      /** \brief get the Iterator over the items vector
       * @return an iterator over the items
      */
      virtual Iterator_t  getIterator();

    protected:
      std::vector<Item> theSequence;

  }; /* class VectorItemSequence */

} // namespace zorba
#endif

/* vim:set et sw=2 ts=2: */
