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
#include "stdafx.h"
#include <limits>

#include "diagnostics/xquery_exception.h"
#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"

#include "store/api/item.h"
#include "store/naive/simple_lazy_temp_seq.h"


namespace zorba
{
namespace simplestore
{


/*******************************************************************************

********************************************************************************/
SimpleLazyTempSeq::SimpleLazyTempSeq(const store::Iterator_t& aIter)
{
  init(aIter);
}


/*******************************************************************************

********************************************************************************/
SimpleLazyTempSeq::~SimpleLazyTempSeq()
{
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeq::init(const store::Iterator_t& aIter)
{
  theIterator = aIter;
  theMatFinished = false;
  thePurgedUpTo = 0;
  theItems.clear();
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeq::append(const store::Iterator_t& iter)
{
  while (!theMatFinished)
  {
    matNextItem();
  }

  theMatFinished = false;
  theIterator = iter;
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeq::purge()
{
  //Not supported
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeq::purgeUpTo(xs_integer upTo)
{
  xs_long lUpTo;
  try 
  {
    lUpTo = to_xs_long(upTo);
  }
  catch (std::range_error& e)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(BUILD_STRING("sequence too big (" << e.what() << ")")));
  }

  ZORBA_ASSERT(lUpTo >= thePurgedUpTo);
  ZORBA_ASSERT(lUpTo - thePurgedUpTo <= theItems.size());

  theItems.erase(theItems.begin(), (theItems.begin() + (lUpTo - thePurgedUpTo)));
  thePurgedUpTo = lUpTo;
}


/*******************************************************************************

********************************************************************************/
bool SimpleLazyTempSeq::empty()
{
  if (!theItems.empty())
  {
    return false;
  }
  else
  {
    if (theMatFinished)
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
void SimpleLazyTempSeq::getItem(xs_integer position, store::Item_t& result)
{
  xs_long lPos;
  try 
  {
    lPos = to_xs_long(position);
  }
  catch (std::range_error& e)
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(BUILD_STRING("access out of bounds " << e.what() << ")")));
  }

  if (this->containsItem(position)) 
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
  xs_long lPos;
  try 
  {
    lPos = to_xs_long(position);
  }
  catch (std::range_error& e)
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(BUILD_STRING("access out of bounds " << e.what() << ")")));
  }

  assert(lPos > thePurgedUpTo);

  xs_long numItemsToBuffer = lPos - thePurgedUpTo;

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
void SimpleLazyTempSeq::matNextItem() 
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


/*******************************************************************************
  Reads the whole Sequence from beginning to end; it is allowed to have several
  concurrent iterators on the same TempSeq.

  @return Iterator which iterates over the complete TempSeq
********************************************************************************/
store::Iterator_t SimpleLazyTempSeq::getIterator() const
{
  return new SimpleLazyTempSeqIter(this, 1, std::numeric_limits<long>::max());
}


/*******************************************************************************
  Returns an iterator which reads just a part of the underlying TempSeq

  @param startPos The first item which the iterator returns
  @param endPos The last item which the iterator returns
  @return Iterator
********************************************************************************/
store::Iterator_t SimpleLazyTempSeq::getIterator(
    xs_integer startPos,
    xs_integer endPos,
    bool streaming) const
{
  return new SimpleLazyTempSeqIter(this, startPos, endPos);
}


/*******************************************************************************
********************************************************************************/
zstring SimpleLazyTempSeq::show() const
{
  zstring result = "{";
  
  for (unsigned int i=0; i < theItems.size(); i++)
  {
    if (i != 0)
      result += " , ";
    result += theItems[i]->show();
  }
  
  return result + "}";
}


/*******************************************************************************

********************************************************************************/
SimpleLazyTempSeqIter::SimpleLazyTempSeqIter(
    const SimpleLazyTempSeq* aTempSeq,
    xs_integer aStartPos,
    xs_integer aEndPos)
  :
  theTempSeq(const_cast<SimpleLazyTempSeq*>(aTempSeq))
{
  try 
  {
    theCurPos = to_xs_long(aStartPos) - 1;
    theStartPos = to_xs_long(aStartPos);
    theEndPos = to_xs_long(aEndPos);
  }
  catch (std::range_error& e)
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(BUILD_STRING("sequence too big (" << e.what() << ")")));
  }
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


} // namespace simplestore
} // namespace zorba
/* vim:set et sw=2 ts=2: */
