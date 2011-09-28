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
#ifndef ZORBA_SINGLETON_ITEM_SEQUENCE_API_H
#define ZORBA_SINGLETON_ITEM_SEQUENCE_API_H

#include <zorba/config.h>
#include <zorba/item_sequence.h>
#include <zorba/iterator.h>
#include <zorba/item.h>

namespace zorba { 

  /** \brief A sequence that contains only one item.
   *
   * This class is an implementation of the ItemSequence. Objects of this class
   * are backed by an iterator that returns on the first next call, the Item
   * that is passed to this class' constructor.
   *
   * See ItemSequence
   */
  class ZORBA_DLL_PUBLIC SingletonItemSequence : public ItemSequence
  {
    class InternalIterator : public Iterator
    {
    private:
      SingletonItemSequence   *theItemSequence;
      bool is_open;
      bool theDone;
    public:
      InternalIterator(SingletonItemSequence *item_sequence);

      /** \brief Start iterating.
       *
       * This function needs to be called before calling next().
       *
       */
      virtual void open();
      /** \brief Get the one Item.
       *
       * @param aItem the Item if true is returned by the function.
       * @return true if the sequence is not exhausted, false otherwise.
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
       * @param aItem the single item in this sequence
       */
      SingletonItemSequence(const Item& aItem);

      /** \brief Destructor
       */
      virtual ~SingletonItemSequence() { }

      /** \brief get the Iterator over the single item
       * @return an iterator over the one item
      */
      virtual Iterator_t    getIterator();

    protected:

      Item theItem;

  }; /* class SingletonItemSequence */

} // namespace zorba

#endif /* ZORBA_SINGLETON_ITEM_SEQUENCE_API_H */
/* vim:set et sw=2 ts=2: */
