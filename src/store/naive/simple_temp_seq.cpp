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

#include "diagnostics/zorba_exception.h"
#include "zorba/diagnostic_list.h"
#include "diagnostics/diagnostic.h"
#include "store/api/item.h"
#include "store/naive/simple_temp_seq.h"
#include "store/api/copymode.h"

namespace zorba { namespace simplestore {

/*******************************************************************************

********************************************************************************/
SimpleTempSeq::SimpleTempSeq(store::Iterator_t& iter, bool copy)
{
  init(iter, copy);
}


/*******************************************************************************

********************************************************************************/
SimpleTempSeq::~SimpleTempSeq()
{
}


/*******************************************************************************

********************************************************************************/
bool SimpleTempSeq::empty()
{
  return theItems.size() == 0;
}


/*******************************************************************************

********************************************************************************/
store::Item_t SimpleTempSeq::operator[](xs_integer aIndex) 
{
  ulong lIndex;
  try {
    lIndex = to_xs_unsignedLong(aIndex);
  } catch (std::range_error& e)
  {
    throw ZORBA_EXCEPTION(
        zerr::ZSTR0060_RANGE_EXCEPTION,
        ERROR_PARAMS(
          BUILD_STRING("access out of bounds " << e.what() << ")")
        )
      );
  }
  return theItems[lIndex];
}


/*******************************************************************************

********************************************************************************/
xs_integer SimpleTempSeq::getSize() 
{
  return theItems.size();
}


/*******************************************************************************

********************************************************************************/
void SimpleTempSeq::getItem(xs_integer position, store::Item_t& res)
{
  ulong lPos;
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
  if (containsItem(lPos))
	{
    res = theItems[lPos - 1];
  }
  else
	{
    res = NULL;
  }
}
	

/*******************************************************************************

********************************************************************************/
bool SimpleTempSeq::containsItem(xs_integer position)
{
  ulong lPos;
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
  return theItems.size() >= lPos;
}


/*******************************************************************************

********************************************************************************/
void SimpleTempSeq::init(store::Iterator_t& iter, bool copy)
{
  store::CopyMode lCopyMode;
  store::Item_t curItem;

  theItems.clear();

  while (iter->next(curItem)) 
  {
    if (copy && curItem->isNode()) 
      curItem = curItem->copy(NULL, lCopyMode);

    theItems.push_back(NULL);
    theItems.back().transfer(curItem);
  }
}


/*******************************************************************************

********************************************************************************/
void SimpleTempSeq::append(store::Iterator_t iter, bool copy)
{
  store::Item_t curItem;
  store::CopyMode lCopyMode;

  while (iter->next(curItem))
  {
    if (copy && curItem->isNode())
      curItem = curItem->copy(NULL, lCopyMode);

    theItems.push_back(NULL);
    theItems.back().transfer(curItem);
  }
}


/*******************************************************************************
  Reads the whole Sequence from beginning to end; it is allowed to have several 
  concurrent iterators on the same TempSeq.

  @return Iterator which iterates over the complete TempSeq
********************************************************************************/
store::Iterator_t SimpleTempSeq::getIterator()
{
  return new SimpleTempSeqIter(this);
}


/*******************************************************************************
  Returns an iterator which reads just a part of the underlying TempSeq

  @param startPos The first item which the iterator returns
  @param endPos The last item which the iterator returns 
  @return Iterator
********************************************************************************/
store::Iterator_t SimpleTempSeq::getIterator(
    xs_integer startPos,
    xs_integer endPos,
    bool streaming)
{
  return new SimpleTempSeqIter(this, startPos, endPos);
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t SimpleTempSeq::getIterator(
    xs_integer startPos,
    store::Iterator_t function,
    const std::vector<store::Iterator_t>& vars,
    bool streaming)
{
  return store::Iterator_t ( NULL );
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t SimpleTempSeq::getIterator(
    const std::vector<xs_integer>& positions,
    bool streaming)
{
  return store::Iterator_t ( NULL );
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t SimpleTempSeq::getIterator(
    store::Iterator_t positions,
    bool streaming)
{
  return store::Iterator_t(NULL);
}


/*******************************************************************************

********************************************************************************/
void SimpleTempSeq::purge()
{

}


/*******************************************************************************

********************************************************************************/
void SimpleTempSeq::purgeUpTo(xs_integer upTo)
{

}


/*******************************************************************************

********************************************************************************/	
SimpleTempSeqIter::SimpleTempSeqIter(
    SimpleTempSeq_t aTempSeq)
	:
    theTempSeq(aTempSeq),
    theBorderType(none),
    theCurPos(-1)
{
}


SimpleTempSeqIter::SimpleTempSeqIter(
    SimpleTempSeq_t aTempSeq,
    xs_integer startPos,
    xs_integer endPos)
	:
		theTempSeq(aTempSeq),
    theBorderType(startEnd),
    theCurPos(to_xs_long(startPos) - 2),
    theStartPos(to_xs_long(startPos)),
    theEndPos(to_xs_long(endPos))
{
}


SimpleTempSeqIter::~SimpleTempSeqIter()
{
}


void SimpleTempSeqIter::init(const store::TempSeq_t& aTempSeq)
{
  theTempSeq = aTempSeq;
  theBorderType = none;
  theCurPos = -1;
}


void SimpleTempSeqIter::open()
{
  switch (theBorderType)
	{
  case startEnd:
    theCurPos = theStartPos - 2;
    break;
  case none:
    theCurPos = -1;
    break;
  }
}


bool SimpleTempSeqIter::next(store::Item_t& result)
{
  theCurPos++;
  switch (theBorderType)
	{
  case none:
    if ( theCurPos < to_xs_long(theTempSeq->getSize()) ) 
    {
      result = (*theTempSeq)[theCurPos];
      return true;
    }
    break;
  case startEnd:
    if ( theCurPos < theEndPos ) 
    {
      result = (*theTempSeq)[theCurPos];
      return true;
    }
    break;
  }
  result = NULL;
  return false;
}


store::Item* SimpleTempSeqIter::next()
{
  theCurPos++;
  switch (theBorderType)
	{
  case none:
    if ( theCurPos < to_xs_long(theTempSeq->getSize()) ) 
      return (*theTempSeq)[theCurPos];
    break;
  case startEnd:
    if ( theCurPos < theEndPos ) 
      return (*theTempSeq)[theCurPos];
    break;
  }

  return NULL;
}
  

void SimpleTempSeqIter::reset()
{
  switch (theBorderType)
	{
  case startEnd:
    theCurPos = theStartPos - 2;
    break;
  case none:
    theCurPos = -1;
    break;
  }
}


void SimpleTempSeqIter::close()
{
}

} // namespace store
} // namespace zorba
/* vim:set et sw=2 ts=2: */
