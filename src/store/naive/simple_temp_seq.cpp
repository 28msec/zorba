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

#include "diagnostics/xquery_exception.h"
#include "zorba/diagnostic_list.h"
#include "diagnostics/diagnostic.h"
#include "diagnostics/util_macros.h"

#include "store/api/item.h"
#include "simple_temp_seq.h"
#include "store/api/copymode.h"

namespace zorba { namespace simplestore {


/*******************************************************************************

********************************************************************************/
SimpleTempSeq::SimpleTempSeq(store::Item_t& item) 
{
  theItems.push_back(NULL);
  theItems[0] = item.release();
}


/*******************************************************************************

********************************************************************************/
SimpleTempSeq::SimpleTempSeq(std::vector<store::Item_t>& items)
{
  theItems.resize(items.size());

  std::vector<store::Item_t>::iterator ite = items.begin();
  std::vector<store::Item_t>::iterator end = items.end();
  std::vector<store::Item*>::iterator ite2 = theItems.begin();
  for (; ite != end; ++ite, ++ite2)
  {
    (*ite2) = (*ite).release();
  }
}


/*******************************************************************************

********************************************************************************/
SimpleTempSeq::SimpleTempSeq(const store::Iterator_t& iter)
{
  init(iter);
}


/*******************************************************************************

********************************************************************************/
SimpleTempSeq::~SimpleTempSeq()
{
  clear();
}


/*******************************************************************************

********************************************************************************/
void SimpleTempSeq::clear()
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

********************************************************************************/
void SimpleTempSeq::init(const store::Iterator_t& iter)
{
  store::Item_t curItem;

  clear();

  while (iter->next(curItem)) 
  {
    // TODO ???? Check that the size is less than max(csize, xs_integer)
    theItems.push_back(NULL);
    theItems.back() = curItem.release();
  }
}


/*******************************************************************************

********************************************************************************/
void SimpleTempSeq::append(const store::Iterator_t& iter)
{
  store::Item_t curItem;

  while (iter->next(curItem))
  {
    // TODO ???? Check that the size is less than max(csize, xs_integer)
    theItems.push_back(NULL);
    theItems.back() = curItem.release();
  }
}


/*******************************************************************************

********************************************************************************/
void SimpleTempSeq::purge()
{
  clear();
}


/*******************************************************************************

********************************************************************************/
void SimpleTempSeq::purgeUpTo(xs_integer pos)
{
}


/*******************************************************************************

********************************************************************************/
bool SimpleTempSeq::empty()
{
  return theItems.empty();
}


/*******************************************************************************

********************************************************************************/
xs_integer SimpleTempSeq::getSize() const
{
  return xs_integer( theItems.size() );
}


/*******************************************************************************

********************************************************************************/
void SimpleTempSeq::getItem(xs_integer position, store::Item_t& res)
{
  xs_long pos;
  try 
  {
    pos = to_xs_long(position);
  }
  catch (std::range_error& e)
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(BUILD_STRING("access out of bounds " << e.what() << ")")));
  }

  if (0 < pos && pos <= theItems.size())
	{
    res = theItems[pos - 1];
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
  xs_long pos;
  try 
  {
    pos = to_xs_long(position);
  }
  catch (std::range_error& e)
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(BUILD_STRING("access out of bounds " << e.what() << ")")));
  }

  return 0 < pos && pos <= theItems.size();
}


/*******************************************************************************
  Reads the whole Sequence from beginning to end; it is allowed to have several 
  concurrent iterators on the same TempSeq.

  @return Iterator which iterates over the complete TempSeq
********************************************************************************/
store::Iterator_t SimpleTempSeq::getIterator() const
{
  return new SimpleTempSeqIter(this);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  SimpleTempSeqIter                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/	
SimpleTempSeqIter::SimpleTempSeqIter(const SimpleTempSeq* tempSeq)
	:
  theTempSeq(const_cast<SimpleTempSeq*>(tempSeq))
{
  theBegin = theTempSeq->theItems.begin();
  theEnd = theTempSeq->theItems.end();
}


/*******************************************************************************

********************************************************************************/	
void SimpleTempSeqIter::init(const store::TempSeq_t& tempSeq)
{
  theTempSeq = tempSeq;

  theBegin = theTempSeq->theItems.begin();
  theEnd = theTempSeq->theItems.end();
}


/*******************************************************************************
  Return the items in the subrange [startPos, endPos]
********************************************************************************/	
void SimpleTempSeqIter::init(
    const store::TempSeq_t& tempSeq,
    xs_integer startPos,
    xs_integer endPos)
{
  theTempSeq = tempSeq;

  xs_long start;
  xs_long end;

  try 
  {
    start = to_xs_long(startPos);
    end = to_xs_long(endPos);
  }
  catch (std::range_error& e)
  {
    RAISE_ERROR_NO_LOC(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(BUILD_STRING("access out of bounds " << e.what() << ")")));
  }

  if (start > 0 && end > 0)
  {
    theBegin = theTempSeq->theItems.begin() + (start - 1);
    theEnd = theTempSeq->theItems.begin() + end;
  }
  else
  {
    theBegin = theTempSeq->theItems.end();
    theEnd = theTempSeq->theItems.end();
  }
}


/*******************************************************************************

********************************************************************************/	
void SimpleTempSeqIter::open()
{
  theIte = theBegin;
}


/*******************************************************************************

********************************************************************************/	
bool SimpleTempSeqIter::next(store::Item_t& result)
{
  if (theIte != theEnd)
  {
    result = *theIte;
    ++theIte;
    return true;
  }

  result = NULL;
  return false;
}


/*******************************************************************************

********************************************************************************/	
void SimpleTempSeqIter::reset()
{
  theIte = theBegin;
}


/*******************************************************************************

********************************************************************************/	
void SimpleTempSeqIter::close()
{
}


} // namespace store
} // namespace zorba
/* vim:set et sw=2 ts=2: */
