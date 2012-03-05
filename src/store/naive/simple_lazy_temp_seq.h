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
  xs_long                    thePurgedUpTo;
  
  std::vector<store::Item_t> theItems;

 public:
  SimpleLazyTempSeq() { }

  SimpleLazyTempSeq(const store::Iterator_t& iter);

  virtual ~SimpleLazyTempSeq();

  void init(const store::Iterator_t& iter);

  void append(const store::Iterator_t& iter);

  void purge();

  void purgeUpTo(xs_integer upTo);

  bool empty();

  void getItem(xs_integer position, store::Item_t& result);

  bool containsItem(xs_integer position);

  xs_integer getSize() const;

  store::Iterator_t getIterator() const;

  store::Iterator_t getIterator(
      xs_integer startPos,
      xs_integer endPos,
      bool streaming = false) const;

 private:
  void matNextItem();
};
 
 
/*******************************************************************************

********************************************************************************/
class SimpleLazyTempSeqIter : public store::Iterator 
{
 private:
  SimpleLazyTempSeq_t  theTempSeq;

  xs_long              theCurPos;
  xs_long              theStartPos;
  xs_long              theEndPos;

 public:
  SimpleLazyTempSeqIter(
      const SimpleLazyTempSeq* aTempSeq,
      xs_integer aStartPos,
      xs_integer aEndPos);

  virtual ~SimpleLazyTempSeqIter();

  void open();
  bool next(store::Item_t& result);
  void reset();
  void close();
};


} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_SIMPLE_LAZY_TEMP_SEQ_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
