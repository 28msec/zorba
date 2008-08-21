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

#include "store/api/item.h"
#include "store/minimal/min_lazy_temp_seq.h"
#include "common/shared_types.h"


namespace zorba {
  namespace storeminimal {

const uint32_t SimpleLazyTempSeq::MAX_POSITION = std::vector<store::Item_t>().max_size();  //FIXME Is there no better way?


/*******************************************************************************

********************************************************************************/
SimpleLazyTempSeq::SimpleLazyTempSeq ( store::Iterator_t aIter, bool aCopy )
  :
  theIterator(aIter),
  theCopy(aCopy),
  theMatFinished(false),
  thePurgedUpTo(0) 
{
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
store::Item_t SimpleLazyTempSeq::getItem ( int32_t position ) 
{
  if ( this->containsItem ( position ) ) 
  {
    return theItems[position - thePurgedUpTo - 1];
  }
  else
  {
    return NULL;
  }
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeq::append ( store::Iterator_t iter, bool copy ) 
{
  while ( !theMatFinished ) 
  {
    matNextItem();
  }
  theMatFinished = false;
  theIterator = iter;
  theCopy = copy;
}


/*******************************************************************************
  Reads the whole Sequence from beginning to end; it is allowed to have several
  concurrent iterators on the same TempSeq.

  @return Iterator which iterates over the complete TempSeq
********************************************************************************/
store::Iterator_t SimpleLazyTempSeq::getIterator() 
{
  return new SimpleLazyTempSeqIter ( this, 1,  SimpleLazyTempSeq::MAX_POSITION );
}


/*******************************************************************************
  Returns an iterator which reads just a part of the underlying TempSeq

  @param startPos The first item which the iterator returns
  @param endPos The last item which the iterator returns
  @return Iterator
********************************************************************************/
store::Iterator_t SimpleLazyTempSeq::getIterator (
    int32_t startPos,
    int32_t endPos,
    bool streaming ) 
{
  return new SimpleLazyTempSeqIter ( this, startPos, endPos );
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t SimpleLazyTempSeq::getIterator (
    int32_t startPos,
    store::Iterator_t function,
    const std::vector<store::Iterator_t>& vars,
    bool streaming ) 
{
  assert ( false ); //Not implemented
  return store::Iterator_t ( NULL );
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t SimpleLazyTempSeq::getIterator (
    const std::vector<int32_t>& positions,
    bool streaming ) 
{
  assert ( false ); //Not implemented
  return store::Iterator_t ( NULL );
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t SimpleLazyTempSeq::getIterator (
    store::Iterator_t positions,
    bool streaming ) 
{
  assert ( false ); //Not implemented
  return store::Iterator_t ( NULL );
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeq::purge() 
{
  //Not supported
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeq::purgeUpTo ( int32_t upTo ) 
{
  theItems.erase(theItems.begin(), (theItems.begin() + upTo));
  thePurgedUpTo = upTo;
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeq::purgeItem ( const std::vector<int32_t>& positions ) 
{
  //Not supported
}


/*******************************************************************************

********************************************************************************/
void SimpleLazyTempSeq::purgeItem ( int32_t position ) 
{
}


/*******************************************************************************

********************************************************************************/
SimpleLazyTempSeqIter::SimpleLazyTempSeqIter (
    SimpleLazyTempSeq_t aTempSeq,
    uint32_t aStartPos,
    uint32_t aEndPos )
  :
  theTempSeq ( aTempSeq ),
  theCurPos ( aStartPos - 1),
  theStartPos ( aStartPos),
  theEndPos ( aEndPos ) 
{
}


SimpleLazyTempSeqIter::~SimpleLazyTempSeqIter() 
{
}
  

void SimpleLazyTempSeqIter::open() 
{
  theCurPos = theStartPos - 1;
}


bool SimpleLazyTempSeqIter::next ( store::Item_t& result ) 
{
  if(theCurPos < theEndPos)
  {
    return theTempSeq->getItem(result, ++theCurPos);
  }
  else
  {
    result=NULL;
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

  } // namespace storeminimal
} // namespace zorba
