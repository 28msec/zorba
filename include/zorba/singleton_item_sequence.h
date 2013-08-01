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

/**
 * \brief This class is an implementation of ItemSequence. Objects of this
 * class represent a sequence with exactly one item.
 *
 * See ItemSequence
 */
class ZORBA_DLL_PUBLIC SingletonItemSequence : public ItemSequence
{
  /**
   * \brief Implements an iterator over the sequence.
   *
   * See Iterator.
   */
  class InternalIterator : public Iterator
  {
  private:
    SingletonItemSequence  * theItemSequence;
    bool                     theIsOpen;
    bool                     theIsDone;

  public:
    InternalIterator(SingletonItemSequence* seq);
    
    virtual void open();
 
    virtual bool next(Item& aItem);

    virtual void close();

    virtual bool isOpen() const;
  };

 protected:
  Item theItem;

 public:
  /**
   * @param aItem the single item of the sequence
   */
  SingletonItemSequence(const Item& aItem);

  virtual ~SingletonItemSequence() { }

  virtual Iterator_t getIterator();

}; /* class SingletonItemSequence */

} // namespace zorba

#endif /* ZORBA_SINGLETON_ITEM_SEQUENCE_API_H */
/* vim:set et sw=2 ts=2: */
