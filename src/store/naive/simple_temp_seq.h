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

namespace zorba { namespace simplestore {

/**
 * Very simple implementation of Temp Sequence. It saves the resulting items
 * of an iterator eager in a vector.
 */
typedef rchandle<class SimpleTempSeq> SimpleTempSeq_t;


/*******************************************************************************

********************************************************************************/
class SimpleTempSeq : public store::TempSeq
{
  friend class SimpleTempSeqIter;

private:
  std::vector<store::Item_t> theItems;

public:
  SimpleTempSeq() { }

  SimpleTempSeq(const std::vector<store::Item_t>& items) : theItems(items) {}

  SimpleTempSeq(store::Iterator_t& iter, bool copy = false);

  virtual ~SimpleTempSeq();

  bool empty();
  
  xs_integer getSize();

  void init(store::Iterator_t& iter, bool copy = false);

  void append(store::Iterator_t iter, bool copy);

  void getItem(xs_integer position, store::Item_t& res);

  bool containsItem(xs_integer position);

  store::Iterator_t getIterator();

  store::Iterator_t getIterator(
        xs_integer startPos,
        xs_integer endPos,
        bool streaming = false);

  store::Iterator_t getIterator(
        xs_integer startPos,
        store::Iterator_t function,
        const std::vector<store::Iterator_t>& var,
        bool streaming = false );

  store::Iterator_t getIterator(
        const std::vector<xs_integer>& positions,
        bool streaming = false);

  store::Iterator_t getIterator(
        store::Iterator_t positions,
        bool streaming = false);
  
  void purge();
  void purgeUpTo(xs_integer upTo );
};


/*******************************************************************************

********************************************************************************/
class SimpleTempSeqIter : public store::TempSeqIterator
{
 private:
  enum BorderType
  {
    none,
    startEnd
  };

  SimpleTempSeq_t     theTempSeq;
  BorderType          theBorderType;

  uint64_t            theCurPos;
  uint64_t            theStartPos;
  uint64_t            theEndPos;

 public:
  SimpleTempSeqIter() {}

  SimpleTempSeqIter(SimpleTempSeq_t aTempSeq);

  SimpleTempSeqIter(
      SimpleTempSeq_t aTempSeq,
      xs_integer startPos,
      xs_integer endPos);

  virtual ~SimpleTempSeqIter();

  void init(const store::TempSeq_t& seq);

  store::Item* next();

  void open();
  bool next(store::Item_t& result);
  void reset();
  void close();
 };


} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_SIIMPLE_TEMP_SEQ_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
