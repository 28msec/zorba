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

#include <zorba/diagnostic_list.h>
#include "diagnostics/assert.h"
#include "diagnostics/dict.h"
#include "diagnostics/util_macros.h"
#include "diagnostics/xquery_exception.h"
#include "simple_lazy_temp_seq.h"
#include "store/api/item.h"
#include "zorbatypes/integer.h"


namespace zorba
{
namespace simplestore
{


/*******************************************************************************

********************************************************************************/
SimpleLazyTempSeq::SimpleLazyTempSeq(const store::Iterator_t& iter)
{
  init(iter);
}


/*******************************************************************************

********************************************************************************/
SimpleLazyTempSeq::~SimpleLazyTempSeq()
{
  clear();
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeq::clear()
{
  std::vector<store::Item*>::iterator ite = theItems.begin();
  std::vector<store::Item*>::iterator end = theItems.end();
  for (; ite != end; ++ite)
  {
    (*ite)->removeReference();
  }

  theItems.clear();
}


/*******************************************************************************
  Get the next item (if any) from the input iterator and put it at the end of 
  the queue.  
********************************************************************************/
void SimpleLazyTempSeq::matNextItem() 
{
  store::Item_t item;

  if (! theIterator->next(item)) 
  {
    theMatFinished = true;
  }
  else
  {
    theItems.push_back(item.get());
    item.release();
  }
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
xs_integer SimpleLazyTempSeq::getSize() const
{
  ZORBA_ASSERT(false);
  return xs_integer(thePurgedUpTo + theItems.size());
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeq::init(const store::Iterator_t& iter)
{
  theIterator = iter;

  theMatFinished = false;
  thePurgedUpTo = 0;

  clear();
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
  theIterator = NULL;

  theMatFinished = false;
  thePurgedUpTo = 0;

  clear();
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeq::purgeUpTo(xs_integer position)
{
  xs_long pos;
  try 
  {
    pos = to_xs_long(position);
  }
  catch (std::range_error const&)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(position,ZED(ZSTR0060_ForSequence)));
  }

  ZORBA_ASSERT(pos >= thePurgedUpTo);
  ZORBA_ASSERT(static_cast<std::vector<store::Item*>::size_type>(pos - thePurgedUpTo) <= theItems.size());

  std::vector<store::Item*>::iterator ite = theItems.begin();
  std::vector<store::Item*>::iterator end = theItems.begin() + static_cast<std::vector<store::Item*>::size_type>(pos - thePurgedUpTo);
  for (; ite != end; ++ite)
  {
    (*ite)->removeReference();
  }

  theItems.erase(theItems.begin(), end);

  thePurgedUpTo = pos;
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeq::getItem(xs_integer position, store::Item_t& result)
{
  xs_long pos;
  try 
  {
    pos = to_xs_long(position);
  }
  catch (std::range_error const&)
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(position,ZED(ZSTR0060_ForSequence)));
  }

  ZORBA_ASSERT(pos > thePurgedUpTo);

  std::vector<store::Item*>::size_type numItemsToBuffer = static_cast<std::vector<store::Item*>::size_type>(pos - thePurgedUpTo);

  while (!theMatFinished && theItems.size() <  numItemsToBuffer) 
  {
    matNextItem();
  }

  if (theItems.size() >= numItemsToBuffer)
  {
    std::vector<store::Item*>::size_type sPos = static_cast<std::vector<store::Item*>::size_type>(pos - thePurgedUpTo - 1);
    result = theItems[sPos];
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
  xs_long pos;
  try 
  {
    pos = to_xs_long(position);
  }
  catch (std::range_error const&)
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(position,ZED(ZSTR0060_ForSequence)));
  }

  ZORBA_ASSERT(pos > thePurgedUpTo);

  std::vector<store::Item*>::size_type numItemsToBuffer = static_cast<std::vector<store::Item*>::size_type>(pos - thePurgedUpTo);

  while (!theMatFinished && theItems.size() <  numItemsToBuffer) 
  {
    matNextItem();
  }

  return theItems.size() >= numItemsToBuffer;
}


/*******************************************************************************
  Reads the whole Sequence from beginning to end; it is allowed to have several
  concurrent iterators on the same TempSeq.

  @return Iterator which iterates over the complete TempSeq
********************************************************************************/
store::Iterator_t SimpleLazyTempSeq::getIterator() const
{
  return new SimpleLazyTempSeqIter(this,
                                   xs_integer(1),
                                   xs_integer(std::numeric_limits<long>::max()));
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  SimpleLazyTempSeqIter                                                      //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
SimpleLazyTempSeqIter::SimpleLazyTempSeqIter()
  :
  theCurPos(0),
  theStartPos(0),
  theEndPos(0)
{
}


/*******************************************************************************
********************************************************************************/
#ifndef NDEBUG
std::string SimpleLazyTempSeq::toString() const
{
  std::stringstream result;
  
  result << "{";
  for (unsigned int i=0; i < theItems.size(); i++)
  {
    if (i != 0)
      result << " , ";
    result << theItems[i]->show();
  }
  result << "}";
  
  return result.str();
}
#endif


/*******************************************************************************

********************************************************************************/
SimpleLazyTempSeqIter::SimpleLazyTempSeqIter(
    const SimpleLazyTempSeq* tempSeq,
    xs_integer startPos,
    xs_integer endPos)
  :
  theTempSeq(const_cast<SimpleLazyTempSeq*>(tempSeq))
{
  try
  {
    theStartPos = to_xs_long(startPos);
  }
  catch ( std::range_error const& )
  {
    throw ZORBA_EXCEPTION(
      zerr::ZSTR0060_RANGE_EXCEPTION,
      ERROR_PARAMS( startPos, ZED( ZSTR0060_ForSequence ) )
    );
  }
  try
  {
    theEndPos = to_xs_long(endPos);
  }
  catch ( std::range_error const& )
  {
    throw ZORBA_EXCEPTION(
      zerr::ZSTR0060_RANGE_EXCEPTION,
      ERROR_PARAMS( endPos, ZED( ZSTR0060_ForSequence ) )
    );
  }

  theCurPos = theStartPos - 1;
}


/*******************************************************************************

********************************************************************************/
SimpleLazyTempSeqIter::~SimpleLazyTempSeqIter()
{
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeqIter::init(const store::TempSeq_t& seq)
{
  ZORBA_ASSERT(false);
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeqIter::init(
    const store::TempSeq_t& seq,
    xs_integer startPos,
    xs_integer endPos)
{
  assert(seq->isLazy());

  theTempSeq = static_cast<SimpleLazyTempSeq*>(seq.getp());

  try
  {
    theStartPos = to_xs_long(startPos);
  }
  catch ( std::range_error const& )
  {
    throw ZORBA_EXCEPTION(
      zerr::ZSTR0060_RANGE_EXCEPTION,
      ERROR_PARAMS( startPos, ZED( ZSTR0060_ForSequence ) )
    );
  }
  try
  {
    theEndPos = to_xs_long(endPos);
  }
  catch ( std::range_error const& )
  {
    throw ZORBA_EXCEPTION(
      zerr::ZSTR0060_RANGE_EXCEPTION,
      ERROR_PARAMS( endPos, ZED( ZSTR0060_ForSequence ) )
    );
  }

  theCurPos = theStartPos - 1;
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeqIter::open()
{
  theCurPos = theStartPos - 1;
}


/*******************************************************************************

********************************************************************************/
bool SimpleLazyTempSeqIter::next(store::Item_t& result)
{
  if (theCurPos < theEndPos && theTempSeq->containsItem(xs_integer(theCurPos+1)))
  {
    theTempSeq->getItem(xs_integer(++theCurPos), result);
    return true;
  }
  else
  {
    result = NULL;
    return false;
  }
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeqIter::reset()
{
  theCurPos = theStartPos - 1;
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeqIter::close()
{
}


} // namespace simplestore
} // namespace zorba
/* vim:set et sw=2 ts=2: */
