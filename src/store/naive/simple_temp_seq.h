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
#ifndef ZORBA_STORE_SIMPLE_TEMP_SEQ_H
#define ZORBA_STORE_SIMPLE_TEMP_SEQ_H

#include <vector>

#include "store/api/iterator.h"
#include "store/api/temp_seq.h"

namespace zorba { namespace store {

/**
 * Very simple implementation of Temp Sequence. It saves the resulting items
 * of an iterator eager in a vector.
 */
typedef rchandle<class SimpleTempSeq> SimpleTempSeq_t;

class SimpleTempSeq : public TempSeq
{
private:
  std::vector<Item_t> theItems;

public:
  SimpleTempSeq() { }

  SimpleTempSeq(const std::vector<Item_t>& items) : theItems(items) {}

  SimpleTempSeq(Iterator_t iter, bool copy = false, bool lazy = true);

  virtual ~SimpleTempSeq();

  virtual bool empty();
  
  Item_t operator[](int32_t aIndex);
  int32_t getSize();

  virtual void append(Iterator_t iter, bool copy);

  virtual Item_t getItem(int32_t position);
  virtual bool containsItem(int32_t position);

  virtual Iterator_t getIterator();

  virtual Iterator_t getIterator(
        int32_t startPos,
        int32_t endPos,
        bool streaming = false);

  virtual Iterator_t getIterator(
        int32_t startPos,
        Iterator_t function,
        const std::vector<var_iterator>& var,
        bool streaming = false );

  virtual Iterator_t getIterator(
        const std::vector<int32_t>& positions,
        bool streaming = false);

  virtual Iterator_t getIterator(
        Iterator_t positions,
        bool streaming = false);
  
  virtual void purge();
  virtual void purgeUpTo(int32_t upTo );
  virtual void purgeItem(const std::vector<int32_t>& positions );
  virtual void purgeItem(int32_t position );

  class SimpleTempSeqIter : public Iterator
	{
  private:
    enum BorderType
    {
      none,
      startEnd,
      specificPositions
    };

    SimpleTempSeq_t            theTempSeq;
    BorderType                 theBorderType;

    int32_t                    theCurPos;
    int32_t                    theStartPos;
    int32_t                    theEndPos;
    std::vector<int32_t>       thePositions;
    
  public:
    SimpleTempSeqIter(SimpleTempSeq_t aTempSeq);
    SimpleTempSeqIter(SimpleTempSeq_t aTempSeq, int startPos, int endPos);
    SimpleTempSeqIter(SimpleTempSeq_t aTempSeq, const std::vector<int32_t>& positions);
    virtual ~SimpleTempSeqIter();

    void open();
    bool next(Item_t& result);
    void reset();
    void close();
  };

}; /* class SimpleTempSeq */

} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_SIIMPLE_TEMP_SEQ_H */
