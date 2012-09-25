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

  theIterator :
  -------------
  The input iterator that produces the items to be cached by "this" temp sequence.

  theMatFinished :
  ----------------
  Set to true when theIterator returns its last item.

  thePurgedUpTo :
  ---------------
  The number of items that have been purged from the buffer so far.

  theItems :
  ----------
  Vector storing the cached items.
********************************************************************************/
class SimpleLazyTempSeq : public store::TempSeq 
{
 private:
  store::Iterator_t          theIterator;

  bool                       theMatFinished;

  xs_long                    thePurgedUpTo;
  
  std::vector<store::Item*>  theItems; // ref-counting is done manually

 private:
  void clear();

  void matNextItem();

 public:
  SimpleLazyTempSeq() { }

  SimpleLazyTempSeq(const store::Iterator_t& iter);

  virtual ~SimpleLazyTempSeq();

  // Store API

  bool isLazy() const { return true; }

  bool empty();

  xs_integer getSize() const;

  void init(const store::Iterator_t& iter);

  void append(const store::Iterator_t& iter);

  void purge();

  void purgeUpTo(xs_integer pos);

  void getItem(xs_integer pos, store::Item_t& result);

  bool containsItem(xs_integer pos);

  store::Iterator_t getIterator() const;
  
#ifndef NDEBUG  
  virtual std::string toString() const;
#endif  
};
 
 
/*******************************************************************************

********************************************************************************/
class SimpleLazyTempSeqIter : public store::TempSeqIterator
{
 private:
  SimpleLazyTempSeq_t  theTempSeq;

  xs_long              theCurPos;
  xs_long              theStartPos;
  xs_long              theEndPos;

 public:
  SimpleLazyTempSeqIter();

  SimpleLazyTempSeqIter(
      const SimpleLazyTempSeq* tempSeq,
      xs_integer startPos,
      xs_integer endPos);

  virtual ~SimpleLazyTempSeqIter();

  // Store API

  void init(const store::TempSeq_t& seq);

  void init(const store::TempSeq_t& seq, xs_integer startPos, xs_integer endPos);

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
