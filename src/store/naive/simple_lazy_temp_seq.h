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
#ifndef ZORBA_STORE_SIMPLE_LAZY_TEMP_SEQ_H
#define ZORBA_STORE_SIMPLE_LAZY_TEMP_SEQ_H

#include <vector>

#include "diagnostics/zorba_exception.h"
#include "zorba/diagnostic_list.h"
#include "diagnostics/diagnostic.h"
#include "store/api/iterator.h"
#include "store/api/temp_seq.h"
#include "store/api/copymode.h"

namespace zorba 
{

namespace simplestore 
{

typedef rchandle<class SimpleLazyTempSeq> SimpleLazyTempSeq_t;


/*******************************************************************************
  theIterator    : The input iterator that produces the items to be buffered by
                   "this" temp sequence.
  theCopy        : Whether or not to copy the items returned by theIterator 
                   before buffering them in "this" temp sequence.
  theMatFinished : Set to true when theIterator returns its last item.
  thePurgedUpTo  : The number of items that have been purged from the buffer so
                   far.

  theItems       : Vector storing the buffered items.
********************************************************************************/
class SimpleLazyTempSeq : public store::TempSeq 
{
 private:
  store::Iterator_t          theIterator;
  bool                       theCopy;
  bool                       theMatFinished;
  uint64_t                      thePurgedUpTo;
  
  std::vector<store::Item_t> theItems;

 public:
  SimpleLazyTempSeq() { }

  SimpleLazyTempSeq(store::Iterator_t& iter, bool copy = false);

  virtual ~SimpleLazyTempSeq();

  bool empty();

  void init(store::Iterator_t& iter, bool copy = false);

  void append(store::Iterator_t iter, bool copy);

  inline void getItem(xs_integer position, store::Item_t& result);

  inline bool containsItem(xs_integer position);

  store::Iterator_t getIterator();

  store::Iterator_t getIterator(
        xs_integer startPos,
        xs_integer endPos,
        bool streaming = false);

  store::Iterator_t getIterator(
        xs_integer startPos,
        store::Iterator_t function,
        const std::vector<store::Iterator_t>& var,
        bool streaming = false);

  store::Iterator_t getIterator(
        const std::vector<xs_integer>& positions,
        bool streaming = false);

  store::Iterator_t getIterator(
        store::Iterator_t positions,
        bool streaming = false);
        
  void purge();

  void purgeUpTo(xs_integer upTo);

 private:
  inline void matNextItem();
};
 
 
class SimpleLazyTempSeqIter : public store::Iterator 
{
 private:
  SimpleLazyTempSeq_t  theTempSeq;

  uint64_t             theCurPos;
  uint64_t             theStartPos;
  uint64_t             theEndPos;

 public:
  SimpleLazyTempSeqIter(
        SimpleLazyTempSeq_t aTempSeq,
        xs_integer aStartPos,
        xs_integer aEndPos);

  virtual ~SimpleLazyTempSeqIter();

  void open();
  bool next(store::Item_t& result);
  void reset();
  void close();
};



/*******************************************************************************

********************************************************************************/
inline void SimpleLazyTempSeq::getItem(xs_integer position, store::Item_t& result)
{
  uint64_t lPos;
  try {
    lPos = to_xs_unsignedLong(position);
  } catch (std::range_error& e)
  {
    throw ZORBA_EXCEPTION(
        zerr::ZSTR0060_RANGE_EXCEPTION,
        ERROR_PARAMS(
          BUILD_STRING("access out of bounds " << e.what() << ")")
        )
      );
  }
  if ( this->containsItem ( lPos ) ) 
  {
    result = theItems[lPos - thePurgedUpTo - 1];
  }
  else 
  {
    result = NULL;
  }
}


/*******************************************************************************
  This method checks if the i-th item in the result sequences of the input
  iterator is in the queue or not. In general, the item may be missing from
  the queue because:
  (a) it has either been purged, or
  (b) it has not been computed yet, or
  (c) the result sequence contains less than i items.
 
  Case (a) should never arise: it is the user of the lazy temp sequence that
  decided when and how many items to purge, so he shouldn't come back to ask
  for an item that has been purged.

  In case (c), the method will compute and buffer any input items that have not
  been computed already and then return false.

  In case (b), the method will compute and buffer all the items starting after
  the last computed item and up to the i-th item; then it will return true.

  If the i-th item is already in the queue, the method will simply return true. 
********************************************************************************/
inline bool SimpleLazyTempSeq::containsItem(xs_integer position) 
{
  uint64_t lPos;
  try {
    lPos = to_xs_unsignedLong(position);
  } catch (std::range_error& e)
  {
    throw ZORBA_EXCEPTION(
        zerr::ZSTR0060_RANGE_EXCEPTION,
        ERROR_PARAMS(
          BUILD_STRING("access out of bounds " << e.what() << ")")
        )
      );
  }
  assert(lPos > thePurgedUpTo);

  uint64_t numItemsToBuffer = lPos - thePurgedUpTo;

  while (!theMatFinished && theItems.size() <  numItemsToBuffer) 
  {
    matNextItem();
  }

  return theItems.size() >= numItemsToBuffer;
}


/*******************************************************************************
  Get the next item (if any) from the input iterator and put it at the end of 
  the queue.  
********************************************************************************/
inline void SimpleLazyTempSeq::matNextItem() 
{
  theItems.push_back(NULL);

  store::Item_t& lLocation = theItems.back();

  if (theIterator->next(lLocation)) 
  {
    if (theCopy && lLocation->isNode()) 
    {
      store::CopyMode lCopyMode;
      lLocation = lLocation->copy(NULL, lCopyMode);
    }
  }
  else 
  {
    // We do not want to have an empty item materialized.
    theItems.pop_back();
    theMatFinished = true;
    theIterator->close();
  }
}


} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_SIMPLE_LAZY_TEMP_SEQ_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
