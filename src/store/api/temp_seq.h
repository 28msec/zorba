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

#include <zorba/config.h>
#include "zorbatypes/schema_types.h"
#include "store/api/shared_types.h"


namespace zorba { namespace store {


/**
 * XQuery Data Model Instance: Logically, implements a "vector&lt;Item_t&gt;"
 * Used internally to materialize temporary query results
 */

class  TempSeq : public SimpleRCObject
{  
public:
  virtual ~TempSeq(){}

  /**
   * Initializes a temp sequence with the given input iterator
   */
  virtual void init(const store::Iterator_t& iter) = 0;

  /**
   * Appends the items from the iterator to the temp sequence
   */
  virtual void append(const Iterator_t& iter) = 0;
	
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
  virtual void purgeUpTo(xs_integer upTo) = 0;

  /**
   * @return Does this TempSeq save an empty sequence? 
   */
  virtual bool empty() = 0;

  /**
   * Gets an item at a certain position.
   * 
   * Starts counting with 1.
   *
   * @param position (first position in XQuery is 1 and not 0!)
   * @return item
   */
  virtual void getItem(xs_integer position, Item_t& result) = 0;
		
  /**
   * Returns true if the item at the passed position is available.
   * 
   * Starts counting with 1.
   *
   * @param position 
   * @return 
   */
  virtual bool containsItem(xs_integer position) = 0;

  /**
   *
   */
  virtual xs_integer getSize() const = 0;

  /**
   * Reads the whole Sequence from beginning to end; it is allowed to have several 
   * concurrent iterators on the same TempSeq.
   * 
   * @return Iterator which iterates over the complete TempSeq
   * 
   */
  virtual Iterator_t getIterator() const = 0;
	
  /**
   * Returns an iterator which reads just a part of the underlying TempSeq
   * Starts counting with 1.
   *
   * @param startPos The first item which the iterator returns. Starts counting with 1.
   * @param endPos The last item which the iterator returns 
   * @return Iterator
   */
  virtual Iterator_t getIterator(
      xs_integer startPos,
      xs_integer endPos,
      bool streaming = false) const = 0;
  
  /** Method to print the contents of the sequence
   */
  virtual zstring show() const = 0;
};

} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_TEMP_SEQ_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
