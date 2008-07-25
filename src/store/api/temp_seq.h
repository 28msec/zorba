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
#ifndef ZORBA_STORE_TEMP_SEQ_H
#define ZORBA_STORE_TEMP_SEQ_H

#include <vector>

#include "common/common.h"

#include "common/shared_types.h"


namespace zorba { namespace store {


/**
 * XQuery Data Model Instance: Logically, implements a "vector&lt;Item_t&gt;"
 * Used internally to materialize temporary query results
 */

class TempSeq : public SimpleRCObject
{  
public:
  virtual ~TempSeq(){}

  /**
   * Reads the whole Sequence from beginning to end; it is allowed to have several 
   * concurrent iterators on the same TempSeq.
   * 
   * @return Iterator which iterates over the complete TempSeq
   * 
   */
  virtual Iterator_t getIterator() = 0;
  
    /**
   * Appends the items from the iterator to the temp sequence
   * 
   * @return Iterator which iterates over the complete TempSeq
   * 
     */
  virtual void append(Iterator_t iter, bool copy) = 0;
		
  /**
   * Returns an iterator which reads just a part of the underlying TempSeq
   * Starts counting with 1.
   *
   * @param startPos The first item which the iterator returns. Starts counting with 1.
   * @param endPos The last item which the iterator returns 
   * @return Iterator
   */
  virtual Iterator_t getIterator(
        int32_t startPos,
        int32_t endPos,
        bool streaming = false) = 0;
		
  /** Info: Tim's territory. Do not touch for the moment!
   *
   * Returns an iterator which reads just a part of the underlying XMD instance
   * Note: Not every store needs to implement this method.
   * If an store is not implementing it, the iterator should throw an exception;
   * 
   * Starts counting with 1.
   *
   * @param startPos The first item which the iterator returns
   * @param endPos HigherOrderedFunction is called for every item in the sequence. If its returns true, the sequence ends
   * @param var variables which have to be bound for every item
   * @return Iterator
   */
  virtual Iterator_t getIterator(
        int32_t startPos,
        Iterator_t function,
        const std::vector<Iterator_t>& var,
        bool streaming = false) = 0;
				
		
  /** Info: Tim's territory. Do not touch for the moment!
   *
   * Returns an iterator which just returns the positions given by the iterator.
   * 
   * Starts counting with 1.
   *
   * @param positions Positions to return
   * @return Iterator
   */
  virtual Iterator_t getIterator(
        const std::vector<int32_t>& positions,
        bool streaming = false) = 0;
		
  /** Info: Tim's territory. Do not touch for the moment!
   *
   * Returns an iterator which just returns the positions given by the iterator. 
   * 
   * @param positions An iterator which only returns int32_t numbers or null. 
   *									Each int32_t value corresponds to a position in the XDMInstance. 
   */
  virtual Iterator_t getIterator(Iterator_t positions, bool streaming = false) = 0;
		
  /**
   * Gets an item at a certain position.
   * 
   * Starts counting with 1.
   *
   * @param position (first position in XQuery is 1 and not 0!)
   * @return item
   */
  virtual Item_t getItem(int32_t position) = 0;
		
		
  /**
   * Returns true if the item at the passed position is available.
   * 
   * Starts counting with 1.
   *
   * @param position 
   * @return 
   */
  virtual bool containsItem(int32_t position) = 0;
		
  /**
   * purge() allows the store to do proper garbage collection. If e.g. a let 
   * has created iterators for all his bindings he has to produce, it can
   * call purge(). After purge() it is not allowed to ask the XDMInstance
   * to create further iterators or items. Of course it is allowed to use
   * the already created iteratos
   */
  virtual void purge() = 0;
		
  /** 
   * Similar to purge(), but in contrast it is still allowed to ask for items
   * or iterators which start with an item higher than the position number upTo
   * 
   * Starts counting with 1.
   * 
   * @param upTo boundary for garbage collector
   */
  virtual void purgeUpTo(int32_t upTo) = 0;
		
  /** Info: Tim's territory. Do not touch for the moment!
   *
   * This optimizations gives the store a hint that the caller will never
   * ask for an iterator again, which might contain those items.
   * 
   * Starts counting with 1.
   *
   * @param positions
   */
  virtual void purgeItem(const std::vector<int32_t>& positions) = 0;
		
  /** Info: Tim's territory. Do not touch for the moment!
   *
   * This optimizations gives the store a hint that the caller will never
   * ask for an iterator again, which might contain this item. 
   * 
   * Starts counting with 1.
   */
  virtual void purgeItem(int32_t position) = 0;
		
		
  /**
   * @return Does this TempSeq save an empty sequence? 
   */
  virtual bool empty() = 0;
};

} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_TEMP_SEQ_H */
