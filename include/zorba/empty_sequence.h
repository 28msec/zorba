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
#ifndef ZORBA_EMPTY_SEQUENCE_API_H
#define ZORBA_EMPTY_SEQUENCE_API_H

#include <zorba/config.h>
#include <zorba/item_sequence.h>
#include <zorba/item.h>
#include <zorba/iterator.h>

namespace zorba { 

  /** \brief This class is an implementation of the ItemSequence.
   *         Objects of this class return, on the first next call,
   *         an empty sequence.
   *
   * See ItemSequence
   */
  class ZORBA_DLL_PUBLIC EmptySequence : public ItemSequence
  {
    class InternalIterator : public Iterator
    {
    private:
      ItemSequence    *theItemSequence;
      bool is_open;
    public:
      InternalIterator(ItemSequence *item_sequence);

      /** \brief Start iterating.
       *
       * This function needs to be called before calling next().
       *
       */
      virtual void open();
      /** \brief Get the next Item of the sequence.
       *
       * This function returns false with no item.
       * @param aItem not used
       * @return false always
       * @throw ZorbaException if iterator is not open.
       *
       */
      virtual bool next(Item& aItem);
      /** \brief Stop iterating.
       *
       *  Not mandatory.
       */
      virtual void close();
      /**
       * brief Check whether the iterator is open or not
       */
      virtual bool isOpen() const;
    };
    public:
      /** \brief Constructor
       */
      EmptySequence() { }

      /** \brief Destructor
       */
      virtual ~EmptySequence() { }

      /** \brief get the void Iterator
       * @return a void iterator
      */
      virtual Iterator_t  getIterator();

  }; /* class EmptySequence */

} // namespace zorba

#endif /* ZORBA_EMPTY_SEQUENCE_API_H */
/* vim:set et sw=2 ts=2: */
