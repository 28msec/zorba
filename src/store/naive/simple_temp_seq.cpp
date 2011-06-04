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
store::Item_t SimpleTempSeq::operator[](ulong aIndex) 
{
  return theItems[aIndex];
}


/*******************************************************************************

********************************************************************************/
ulong SimpleTempSeq::getSize() 
{
  return (ulong)theItems.size();
}


/*******************************************************************************

********************************************************************************/
void SimpleTempSeq::getItem(ulong position, store::Item_t& res)
{
  if (containsItem(position))
	{
    res = theItems[position - 1];
  }
  else
	{
    res = NULL;
  }
}
	

/*******************************************************************************

********************************************************************************/
bool SimpleTempSeq::containsItem(ulong position)
{
  return theItems.size() >= position;
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
    ulong startPos,
    ulong endPos,
    bool streaming)
{
  return new SimpleTempSeqIter(this, startPos, endPos);
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t SimpleTempSeq::getIterator(
    ulong startPos,
    store::Iterator_t function,
    const std::vector<store::Iterator_t>& vars,
    bool streaming)
{
  return store::Iterator_t ( NULL );
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t SimpleTempSeq::getIterator(
    const std::vector<ulong>& positions,
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
void SimpleTempSeq::purgeUpTo(ulong upTo)
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
    ulong startPos,
    ulong endPos)
	:
		theTempSeq(aTempSeq),
    theBorderType(startEnd),
    theCurPos(startPos - 2),
    theStartPos(startPos),
    theEndPos(endPos)
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
    if ( theCurPos < theTempSeq->getSize() ) 
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
    if ( theCurPos < theTempSeq->getSize() ) 
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
