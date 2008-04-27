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
#include "util/rchandle.h"

#include "store/api/item.h"
#include "store/naive/simple_temp_seq.h"
#include "store/api/copymode.h"

namespace zorba { namespace store {

/*******************************************************************************

********************************************************************************/
SimpleTempSeq::SimpleTempSeq(Iterator_t iter, bool copy, bool lazy)
{
  Item_t curItem = iter->next();
  CopyMode lCopyMode;
  while ( curItem != NULL )
	{
    if (copy && curItem->isNode()) {
      curItem = curItem->copyXmlTree(lCopyMode);
    }
    theItems.push_back(curItem);
    curItem = iter->next();
  }
}


/*******************************************************************************

********************************************************************************/
SimpleTempSeq::~SimpleTempSeq()
{
}


/*******************************************************************************
  Reads the whole Sequence from beginning to end; it is allowed to have several 
  concurrent iterators on the same TempSeq.

  @return Iterator which iterates over the complete TempSeq
********************************************************************************/
Iterator_t SimpleTempSeq::getIterator()
{
  return new SimpleTempSeqIter(this);
}


/*******************************************************************************
  Returns an iterator which reads just a part of the underlying TempSeq

  @param startPos The first item which the iterator returns
  @param endPos The last item which the iterator returns 
  @return Iterator
********************************************************************************/
Iterator_t SimpleTempSeq::getIterator(
    int32_t startPos,
    int32_t endPos,
    bool streaming)
{
  return Iterator_t ( NULL );
}


/*******************************************************************************

********************************************************************************/
Iterator_t SimpleTempSeq::getIterator(
    int32_t startPos,
    Iterator_t function,
    const std::vector<var_iterator>& vars,
    bool streaming)
{
  return Iterator_t ( NULL );
}


/*******************************************************************************

********************************************************************************/
Iterator_t SimpleTempSeq::getIterator(
    const std::vector<int32_t>& positions,
    bool streaming)
{
  return Iterator_t ( NULL );
}


/*******************************************************************************

********************************************************************************/
Iterator_t SimpleTempSeq::getIterator(Iterator_t positions, bool streaming)
{
  return Iterator_t(NULL);
}


/*******************************************************************************

********************************************************************************/
void SimpleTempSeq::append(Iterator_t iter, bool copy)
{
  Item_t curItem = iter->next();
  CopyMode lCopyMode;
  while ( curItem != NULL )
  {
    if (copy && curItem->isNode()) {
      curItem = curItem->copyXmlTree(lCopyMode);
    }
    theItems.push_back(curItem);
    curItem = iter->next();
  }
}


/*******************************************************************************

********************************************************************************/
Item_t SimpleTempSeq::getItem(int32_t position)
{
  if ( this->containsItem(position))
	{
    return theItems[position - 1];
  }
  else
	{
    return NULL;
  }
}
	

/*******************************************************************************

********************************************************************************/
bool SimpleTempSeq::containsItem(int32_t position)
{
  return int32_t ( theItems.size() ) >= position;
}
  

/*******************************************************************************

********************************************************************************/
void SimpleTempSeq::purge()
{

}


/*******************************************************************************

********************************************************************************/
void SimpleTempSeq::purgeUpTo(int32_t upTo)
{

}


/*******************************************************************************

********************************************************************************/
void SimpleTempSeq::purgeItem(const std::vector<int32_t>& positions)
{

}


/*******************************************************************************

********************************************************************************/
void SimpleTempSeq::purgeItem(int32_t position)
{

}


bool SimpleTempSeq::empty()
{
  return theItems.size() == 0;
}

Item_t SimpleTempSeq::operator[](int32_t aIndex) {
  return theItems[aIndex];
}

int32_t SimpleTempSeq::getSize() {
  return theItems.size();
}


/*******************************************************************************

********************************************************************************/	
SimpleTempSeq::SimpleTempSeqIter::SimpleTempSeqIter(
    SimpleTempSeq_t aTempSeq)
	:
    theTempSeq(aTempSeq),
    theBorderType(none),
    theCurPos(-1)
{
}


SimpleTempSeq::SimpleTempSeqIter::SimpleTempSeqIter(
    SimpleTempSeq_t aTempSeq,
    int startPos,
    int endPos)
	:
		theTempSeq(aTempSeq),
    theBorderType(startEnd),
    theCurPos(startPos - 2),
    theStartPos(startPos),
    theEndPos(endPos)
{
}


SimpleTempSeq::SimpleTempSeqIter::SimpleTempSeqIter(
    SimpleTempSeq_t aTempSeq,
    const std::vector<int32_t>& positions)
	:
		theTempSeq(aTempSeq),
    theBorderType(specificPositions),
    theCurPos(-1),
    thePositions(positions)
{
}


SimpleTempSeq::SimpleTempSeqIter::~SimpleTempSeqIter()
{
}

void SimpleTempSeq::SimpleTempSeqIter::open()
{
  switch (theBorderType)
	{
  case startEnd:
    theCurPos = theStartPos - 2;
    break;
  case none:
  case specificPositions:
    theCurPos = -1;
    break;
  }
}

Item_t SimpleTempSeq::SimpleTempSeqIter::next()
{
  theCurPos++;
  switch (theBorderType)
	{
  case none:
    if ( theCurPos < theTempSeq->getSize() ) {
      return (*theTempSeq)[theCurPos];
    }
    break;
  case startEnd:
    if ( theCurPos < theEndPos )
      return  (*theTempSeq)[theCurPos];
    break;
  case specificPositions:
    if ( theCurPos < int32_t ( thePositions.size() ) )
      return  (*theTempSeq)[thePositions[theCurPos]];
    break;
  }
  return NULL;
}
  

void SimpleTempSeq::SimpleTempSeqIter::reset()
{
  switch (theBorderType)
	{
  case startEnd:
    theCurPos = theStartPos - 2;
    break;
  case none:
  case specificPositions:
    theCurPos = -1;
    break;
  }
}


void SimpleTempSeq::SimpleTempSeqIter::close()
{
}

} // namespace store
} // namespace zorba
