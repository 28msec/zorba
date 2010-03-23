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

#include "zorbaerrors/Assert.h"

#include "store/api/item.h"
#include "store/naive/simple_lazy_temp_seq.h"


namespace zorba
{
namespace simplestore
{

const ulong SimpleLazyTempSeq::MAX_POSITION = std::vector<store::Item_t>().max_size();  //FIXME Is there no better way?


/*******************************************************************************

********************************************************************************/
SimpleLazyTempSeq::SimpleLazyTempSeq(store::Iterator_t& aIter, bool aCopy)
{
  init(aIter, aCopy);
}


/*******************************************************************************

********************************************************************************/
SimpleLazyTempSeq::~SimpleLazyTempSeq()
{
}


/*******************************************************************************

********************************************************************************/
bool SimpleLazyTempSeq::empty()
{
  if ( theItems.size() > 0 )
  {
    return false;
  }
  else
  {
    if ( theMatFinished )
    {
      return true;
    }
    else
    {
      matNextItem();
      return theItems.empty();
    }
  }
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeq::init(store::Iterator_t& aIter, bool aCopy)
{
  theIterator = aIter;
  theCopy = aCopy;
  theMatFinished = false;
  thePurgedUpTo = 0;
  theItems.clear();

  theIterator->open();
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeq::append(store::Iterator_t iter, bool copy)
{
  while (!theMatFinished)
  {
    matNextItem();
  }
  theMatFinished = false;
  theIterator = iter;
  theCopy = copy;
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeq::purge()
{
  //Not supported
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeq::purgeUpTo(ulong upTo)
{
  ZORBA_ASSERT(upTo >= thePurgedUpTo);
  ZORBA_ASSERT(upTo - thePurgedUpTo <= theItems.size());

  theItems.erase(theItems.begin(), (theItems.begin() + (upTo - thePurgedUpTo)));
  thePurgedUpTo = upTo;
}


/*******************************************************************************
  Reads the whole Sequence from beginning to end; it is allowed to have several
  concurrent iterators on the same TempSeq.

  @return Iterator which iterates over the complete TempSeq
********************************************************************************/
store::Iterator_t SimpleLazyTempSeq::getIterator()
{
  return new SimpleLazyTempSeqIter(this, 1,  SimpleLazyTempSeq::MAX_POSITION);
}


/*******************************************************************************
  Returns an iterator which reads just a part of the underlying TempSeq

  @param startPos The first item which the iterator returns
  @param endPos The last item which the iterator returns
  @return Iterator
********************************************************************************/
store::Iterator_t SimpleLazyTempSeq::getIterator(
    ulong startPos,
    ulong endPos,
    bool streaming)
{
  return new SimpleLazyTempSeqIter(this, startPos, endPos);
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t SimpleLazyTempSeq::getIterator(
    ulong startPos,
    store::Iterator_t function,
    const std::vector<store::Iterator_t>& vars,
    bool streaming)
{
  assert(false); //Not implemented
  return store::Iterator_t(NULL);
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t SimpleLazyTempSeq::getIterator(
    const std::vector<ulong>& positions,
    bool streaming)
{
  assert (false); //Not implemented
  return store::Iterator_t(NULL);
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t SimpleLazyTempSeq::getIterator(
    store::Iterator_t positions,
    bool streaming)
{
  assert(false); //Not implemented
  return store::Iterator_t ( NULL );
}


/*******************************************************************************

********************************************************************************/
SimpleLazyTempSeqIter::SimpleLazyTempSeqIter(
    SimpleLazyTempSeq_t aTempSeq,
    ulong aStartPos,
    ulong aEndPos)
  :
  theTempSeq(aTempSeq),
  theCurPos(aStartPos - 1),
  theStartPos(aStartPos),
  theEndPos(aEndPos)
{
}


SimpleLazyTempSeqIter::~SimpleLazyTempSeqIter()
{
}


void SimpleLazyTempSeqIter::open()
{
  theCurPos = theStartPos - 1;
}


bool SimpleLazyTempSeqIter::next(store::Item_t& result)
{
  if (theCurPos < theEndPos && theTempSeq->containsItem(theCurPos+1))
  {
    theTempSeq->getItem(++theCurPos, result);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


void SimpleLazyTempSeqIter::reset()
{
  theCurPos = theStartPos - 1;
}


void SimpleLazyTempSeqIter::close()
{
}

  } // namespace store
} // namespace zorba
