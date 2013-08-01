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

/**
 * \brief This class is an implementation of ItemSequence. Objects of this
 * class store the items of the sequence in a vector.
 *
 * See ItemSequence
 */
class ZORBA_DLL_PUBLIC VectorItemSequence : public ItemSequence
{
  /**
   * \brief Implements an iterator over the sequence.
   *
   * See Iterator.
   */
  class InternalIterator : public Iterator
  {
  private:
    VectorItemSequence          * theItemSequence;
    std::vector<Item>::iterator   theIterator;
    std::vector<Item>::iterator   theEnd;
    bool                          theIsOpen;

  public:
    InternalIterator(VectorItemSequence* seq);
    
    virtual void open();

    virtual bool next(Item& aItem);

    virtual void close();

    virtual bool isOpen() const;
  };

 protected:
  std::vector<Item> theSequence;

 public:
  /**
   * @param aSequence the vector containing the items of the sequence
   */
  VectorItemSequence(const std::vector<Item>& aSequence);
  
  virtual ~VectorItemSequence() { }
  
  virtual Iterator_t getIterator();
  
}; /* class VectorItemSequence */
  
} // namespace zorba
#endif

/* vim:set et sw=2 ts=2: */
