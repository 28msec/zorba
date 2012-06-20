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

#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include <zorbautils/fatal.h>
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

#include <zorbatypes/URI.h>
#include <zorbamisc/ns_consts.h>

// For timing
#include <zorba/util/time.h>

#include <zorba/transcode_stream.h>

#include <util/fs_util.h>
#include <util/uri_util.h>

#include <compiler/api/compilercb.h>

#include <runtime/sequences/sequences.h>
#include <runtime/core/arithmetic_impl.h>
#include <runtime/util/iterator_impl.h>
#include <runtime/util/handle_hashset_item_value.h>
#include <runtime/visitors/planiter_visitor.h>

#include <system/globalenv.h>

#include <types/casting.h>
#include <types/typeops.h>
#include <types/typeimpl.h>

#include <store/api/store.h>
#include <store/api/iterator.h>
#include <store/api/item_factory.h>
#include "store/api/temp_seq.h"
#include <store/api/pul.h>
#include <store/util/hashset_node_handle.h>

#include <context/static_context.h>

namespace zorbatm = zorba::time;

using namespace std;

namespace zorba {

static XQPCollator* getCollator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanState& planState,
    const PlanIterator* iter)
{
  store::Item_t lCollationItem;
  store::Item_t temp;

  if (!PlanIterator::consumeNext(lCollationItem, iter, planState))
    throw XQUERY_EXCEPTION(
      err::XPTY0004,
      ERROR_PARAMS( ZED( NoEmptySeqAsCollationParam ) ),
      ERROR_LOC( loc )
    );

  if (PlanIterator::consumeNext(temp, iter, planState))
    throw XQUERY_EXCEPTION(
      err::XPTY0004,
      ERROR_PARAMS( ZED( NoSeqAsCollationParam ) ),
      ERROR_LOC( loc )
    );

  xqtref_t lCollationItemType = sctx->get_typemanager()->create_value_type(lCollationItem);

  return sctx->get_collator(lCollationItem->getStringValue().str(), loc);
}

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  15.1 General Functions and Operators on Sequences                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************
  15.1.2 op:concatenate
********************************************************************************/
void FnConcatIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  NaryBaseIterator<FnConcatIterator, FnConcatIteratorState>
  ::openImpl(planState, offset);

  FnConcatIteratorState* state =
  StateTraitsImpl<FnConcatIteratorState>::getState(planState, this->theStateOffset);

  state->theEndIter = theChildren.end();
  state->theCurIter = theChildren.begin();
}

void FnConcatIterator::resetImpl(PlanState& planState) const
{
  NaryBaseIterator<FnConcatIterator, FnConcatIteratorState>::resetImpl(planState);

  FnConcatIteratorState* state =
  StateTraitsImpl<FnConcatIteratorState>::getState(planState, this->theStateOffset);

  state->theCurIter = theChildren.begin();
}

bool FnConcatIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  FnConcatIteratorState* state;
  DEFAULT_STACK_INIT(FnConcatIteratorState, state, planState);

  for (; state->theCurIter != state->theEndIter; ++state->theCurIter)
  {
    while(consumeNext(result, (*state->theCurIter).getp(), planState))
    {
      STACK_PUSH(true, state);
    }
  }

  STACK_END(state);
}


/*******************************************************************************
  15.1.3 fn:index-of
********************************************************************************/
bool
FnIndexOfIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lSequenceItem;
  store::Item_t lCollationItem;
  xqtref_t      lCollationItemType;
  store::Item_t searchItem;
  TypeManager* typemgr = theSctx->get_typemanager();
  long timezone = 0;
  bool found;

  FnIndexOfIteratorState* state;
  DEFAULT_STACK_INIT(FnIndexOfIteratorState, state, planState);

  if (!consumeNext(state->theSearchItem, theChildren[1].getp(), planState))
  {
		RAISE_ERROR(err::FORG0006, loc, ERROR_PARAMS(ZED(EmptySeqNoSearchItem)));
  }

  if ( theChildren.size() == 3 )
    state->theCollator = getCollator(theSctx, loc,
                                     planState, theChildren[2].getp());

  while ( consumeNext(lSequenceItem, theChildren[0].getp(), planState))
  {
    // inc the position in the sequence; do it at the beginning of the loop
    // because index-of starts with one
    ++state->theCurrentPos;

    searchItem = state->theSearchItem;

    try
    {
      found = CompareIterator::valueEqual(loc,
                                          lSequenceItem,
                                          searchItem,
                                          typemgr,
                                          timezone,
                                          state->theCollator);
    }
    catch (ZorbaException const& e)
    {
      if (e.diagnostic() == err::XPTY0004)
        found = false;
      else
        throw;
    }

    if (found)
    {
      STACK_PUSH(GENV_ITEMFACTORY->createInteger(result,
                                                 Integer(state->theCurrentPos)),
                 state);
    }
  }

  STACK_END(state);
}

/*******************************************************************************
  15.1.4 fn:empty
********************************************************************************/
bool
FnEmptyIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  store::Item_t lSequenceItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if ( !consumeNext(lSequenceItem, theChildren[0].getp(), planState))
  {
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, true), state);
  }
  else
  {
    theChildren[0]->reset(planState);
    STACK_PUSH (GENV_ITEMFACTORY->createBoolean(result, false), state);
  }

  STACK_END (state);
}

/*******************************************************************************
  15.1.5 fn:exists
********************************************************************************/
bool
FnExistsIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  store::Item_t lSequenceItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if ( consumeNext(lSequenceItem, theChildren[0].getp(), planState) )
  {
    theChildren[0]->reset(planState);
    STACK_PUSH (GENV_ITEMFACTORY->createBoolean ( result, true ), state);
  }
  else
  {
    STACK_PUSH (GENV_ITEMFACTORY->createBoolean ( result, false ), state);
  }

  STACK_END (state);
}


/*******************************************************************************
  15.1.6 fn:distinct-values
********************************************************************************/
void FnDistinctValuesIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theHasNaN = false;
  if (theAlreadySeenMap.get () != NULL)
    theAlreadySeenMap->clear();
}


bool FnDistinctValuesIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t lItem;
  xqtref_t lItemType;
  XQPCollator* lCollator;
  ValueCompareParam* valueCompare;

  FnDistinctValuesIteratorState* state;
  DEFAULT_STACK_INIT(FnDistinctValuesIteratorState, state, planState);

  if (theChildren.size() == 2)
  {
    lCollator = getCollator(theSctx, loc, planState, theChildren[1].getp());

    valueCompare = new ValueCompareParam(loc, planState.theLocalDynCtx, theSctx);
    valueCompare->theCollator = lCollator;
  }
  else
  {
    valueCompare = new ValueCompareParam(loc, planState.theLocalDynCtx, theSctx);
  }

  // theValueCompare managed by state->theAlreadySeenMap
  state->theAlreadySeenMap.reset(new ItemValueCollHandleHashSet(valueCompare));

  while (consumeNext(result, theChildren[0].getp(), planState))
  {
    if (result->isNaN())
    {
      if (! state->theHasNaN)
      {
        state->theHasNaN = true;
        STACK_PUSH(true, state);
      }
    }
    else if ( ! state->theAlreadySeenMap->exists(result) )
    {
      state->theAlreadySeenMap->insert(result);
      STACK_PUSH(true, state);
    }
  }

  STACK_END(state);
}


/*******************************************************************************
  15.1.7 fn:insert-before
********************************************************************************/
bool
FnInsertBeforeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
 store::Item_t lInsertItem;
 store::Item_t lPositionItem;

 FnInsertBeforeIteratorState* state;
 DEFAULT_STACK_INIT(FnInsertBeforeIteratorState, state, planState);

 if (!consumeNext(lPositionItem, theChildren[1].getp(), planState))
 {
   // raise error
 }

 state->thePosition = lPositionItem->getIntegerValue();
 if (state->thePosition < 1)
   state->thePosition = 1;

 while (consumeNext(result, theChildren[0].getp(), planState))
 {
    if ( state->theCurrentPos == state->thePosition-1 ) // position found => insert sequence
    {
      state->theTargetItem = result;
      while ( consumeNext(result, theChildren[2].getp(), planState))
      {
        STACK_PUSH (true, state);
      }
      result = state->theTargetItem;
    }
    ++state->theCurrentPos;
    STACK_PUSH (true, state);
  }

  if (state->theCurrentPos < state->thePosition) // append to the end
  {
    while (consumeNext(result, theChildren[2].getp(), planState))
    {
      STACK_PUSH (true, state);
    }
  }

  STACK_END (state);
}

/*******************************************************************************
  15.1.8 fn:remove
********************************************************************************/
bool
FnRemoveIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lSequenceItem;
  store::Item_t lPositionItem;
  store::Item_t lCollationItem;
  xqtref_t      lCollationItemType;

  FnRemoveIteratorState* state;
  DEFAULT_STACK_INIT(FnRemoveIteratorState, state, planState);

  if (!consumeNext(lPositionItem, theChildren[1].getp(), planState))
  {
		throw XQUERY_EXCEPTION(
			err::FORG0006,
			ERROR_PARAMS( ZED( EmptySeqNoFnRemoveArg ) ),
			ERROR_LOC( loc )
		);
  }
  state->thePosition = lPositionItem->getIntegerValue();

  if ( theChildren.size() == 3 )
    state->theCollator = getCollator(theSctx, loc, planState, theChildren[2].getp());

  while (consumeNext(result, theChildren[0].getp(), planState))
  {
    // inc the position in the sequence; do it at the beginning of the loop because fn:remove starts with one
    ++state->theCurrentPos;

    if (state->theCurrentPos == state->thePosition)
      continue;

    STACK_PUSH (true, state);
  }

  STACK_END (state);
}

/*******************************************************************************
  15.1.9 fn:reverse
********************************************************************************/
void FnReverseIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
}

void FnReverseIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  while (!theStack.empty())
    theStack.pop();
}

bool FnReverseIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t iVal;

  FnReverseIteratorState *state;
  DEFAULT_STACK_INIT(FnReverseIteratorState, state, planState);

  while(consumeNext(iVal, theChildren[0].getp(), planState))
  {
    state->theStack.push(iVal);
  }

  while(!state->theStack.empty())
  {
    result = state->theStack.top();
    state->theStack.pop();
    STACK_PUSH(true, state);
  }

  STACK_END (state);
}

/*******************************************************************************
  15.1.10 fn:subsequence
********************************************************************************/
void FnSubsequenceIterator::resetImpl(PlanState& planState) const
{
  FnSubsequenceIteratorState* state =
  StateTraitsImpl<FnSubsequenceIteratorState>::getState(planState, theStateOffset);

  if (state->theIsChildReset)
  {
    state->reset(planState);

    theChildren[1]->reset(planState);
    if (theChildren.size() > 2)
      theChildren[2]->reset(planState);
  }
  else
  {
    NaryBaseIterator<FnSubsequenceIterator, FnSubsequenceIteratorState>::
    resetImpl(planState);
  }
}

bool FnSubsequenceIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t startPosItem;
  xs_long startPos;
  store::Item_t lengthItem;

  FnSubsequenceIteratorState* state;
  DEFAULT_STACK_INIT(FnSubsequenceIteratorState, state, planState);

  state->theIsChildReset = false;

  CONSUME(startPosItem, 1);
  startPos =
  static_cast<xs_long>(startPosItem->getDoubleValue().round().getNumber()) - 1;

  if (theChildren.size() == 3)
  {
    CONSUME(lengthItem, 2);
    state->theRemaining =
    static_cast<xs_long>(lengthItem->getDoubleValue().round().getNumber());
  }

  if (startPos < 0)
  {
    if (theChildren.size() >= 3)
      state->theRemaining += startPos;

    startPos = 0;
  }

  // If a length is specified and it is <= 0, return the empty sequence
  if (theChildren.size() == 3 && state->theRemaining <= 0)
    goto done;

  // Consume and skip all input items that are before the startPos
  for (; startPos > 0; --startPos)
  {
    if (!CONSUME(result, 0))
      goto done;
  }

  if (theChildren.size() < 3)
  {
    while (CONSUME(result, 0))
    {
      STACK_PUSH(true, state);
    }
  }
  else
  {
    while (state->theRemaining > 0 && CONSUME(result, 0))
    {
      state->theRemaining--;
      
      STACK_PUSH(true, state);
    }
  }

done:
  theChildren[0]->reset(planState);
  state->theIsChildReset = true;

  STACK_END(state);
}

/*******************************************************************************
  15.1.10 fn:subsequence
********************************************************************************/
void SubsequenceIntIterator::resetImpl(PlanState& planState) const
{
  SubsequenceIntIteratorState* state =
  StateTraitsImpl<SubsequenceIntIteratorState>::getState(planState, theStateOffset);

  if (state->theIsChildReset)
  {
    state->reset(planState);

    theChildren[1]->reset(planState);
    if (theChildren.size() > 2)
      theChildren[2]->reset(planState);
  }
  else
  {
    NaryBaseIterator<SubsequenceIntIterator, SubsequenceIntIteratorState>::
    resetImpl(planState);
  }
}

bool SubsequenceIntIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t startPosItem;
  xs_long startPos;
  store::Item_t lengthItem;

  SubsequenceIntIteratorState* state;
  DEFAULT_STACK_INIT(SubsequenceIntIteratorState, state, planState);

  state->theIsChildReset = false;

  CONSUME(startPosItem, 1);
  startPos = startPosItem->getLongValue() - 1;

  if (theChildren.size() == 3)
  {
    CONSUME(lengthItem, 2);
    state->theRemaining = lengthItem->getLongValue();
  }

  if (startPos < 0)
  {
    if (theChildren.size() >= 3)
      state->theRemaining += startPos;

    startPos = 0;
  }

  // If a length is specified and it is <= 0, return the empty sequence
  if (theChildren.size() == 3 && state->theRemaining <= 0)
    goto done;

  // Consume and skip all input items that are before the startPos
  for (; startPos > 0; --startPos)
  {
    if (!CONSUME(result, 0))
      goto done;
  }

  if (theChildren.size() < 3)
  {
    while (CONSUME(result, 0))
    {
      STACK_PUSH(true, state);
    }
  }
  else
  {
    while (state->theRemaining > 0 && CONSUME(result, 0))
    {
      state->theRemaining--;

      STACK_PUSH(true, state);
    }
  }

done:
  theChildren[0]->reset(planState);
  state->theIsChildReset = true;

  STACK_END(state);
}


/*******************************************************************************
  zorbaop:sequence-point-access
********************************************************************************/
void SequencePointAccessIterator::resetImpl(PlanState& planState) const
{
  SequencePointAccessIteratorState* state =
  StateTraitsImpl<SequencePointAccessIteratorState>::getState(planState, theStateOffset);

  if (state->theIsChildReset)
  {
    state->reset(planState);

    theChildren[1]->reset(planState);
  }
  else
  {
    NaryBaseIterator<SequencePointAccessIterator, SequencePointAccessIteratorState>::
    resetImpl(planState);
  }
}

bool SequencePointAccessIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t startPosItem;
  xs_long startPos;

  SequencePointAccessIteratorState* state;
  DEFAULT_STACK_INIT(SequencePointAccessIteratorState, state, planState);

  state->theIsChildReset = false;

  if (!consumeNext(startPosItem, theChildren[1].getp(), planState))
    goto done;

  startPos = startPosItem->getLongValue();

  if (startPos <= 0)
    goto done;

  --startPos;

  // Consume and skip all input items that are before the startPos
  for (; startPos > 0; --startPos)
  {
    if (!CONSUME(result, 0))
      goto done;
  }

  if (CONSUME(result, 0))
  {
    STACK_PUSH(true, state);
  }

done:
  theChildren[0]->reset(planState);
  state->theIsChildReset = true;

  STACK_END(state);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  15.2 Functions That Test the Cardinality of Sequences                      //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************
  15.2.1 fn:zero-or-one
********************************************************************************/
bool
FnZeroOrOneIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lNextItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    while (consumeNext(lNextItem, theChildren[0].getp(), planState))
    {
      if (theDoDistinct)
      {
        if (!lNextItem->equals(result))
        {
					throw XQUERY_EXCEPTION( err::FORG0003, ERROR_LOC( loc ) );
        }
      }
      else
      {
				throw XQUERY_EXCEPTION( err::FORG0003, ERROR_LOC( loc ) );
      }
    }

    STACK_PUSH(true, state);
  }

  STACK_END(state);
}

/*******************************************************************************
  15.2.2 fn:one-or-more
********************************************************************************/
bool
FnOneOrMoreIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(result, theChildren[0].getp(), planState))
  {
		throw XQUERY_EXCEPTION( err::FORG0004, ERROR_LOC( loc ) );
  }
  do
  {
    STACK_PUSH(true, state);
  } while (consumeNext(result, theChildren[0].getp(), planState));

  STACK_END (state);
}

/*******************************************************************************
  15.2.3 fn:exactly-one
********************************************************************************/
bool
FnExactlyOneIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lNextItem;
  bool firstPresent = false;
  bool nextPresent = false;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if ((firstPresent = consumeNext(result, theChildren[0].getp(), planState)))
  {
    while(consumeNext(lNextItem, theChildren[0].getp(), planState))
    {
      if (!theDoDistinct || !lNextItem->equals(result))
      {
        nextPresent = true;
        theChildren[0]->reset(planState);
        break;
      }
    }
  }

  if (firstPresent && !nextPresent)
  {
    if (!theRaiseError)
    {
      GENV_ITEMFACTORY->createBoolean(result, true);
    }
  }
  else
  {
    if (theRaiseError)
			throw XQUERY_EXCEPTION( err::FORG0005, ERROR_LOC( loc ) );
    else
      GENV_ITEMFACTORY->createBoolean(result, false);
  }

  STACK_PUSH(true, state);

  STACK_END (state);
}

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  15.3 Deepe Equal, Union, Intersection, and Except                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************
  15.3.1 fn:deep-equal
********************************************************************************/
// Forward declaration
static bool DeepEqual(
    const QueryLoc& loc,
    static_context* sctx,
    dynamic_context* dctx,
    store::Item_t& item1,
    store::Item_t& item2,
    XQPCollator* collator);


static bool DeepEqual(
    const QueryLoc& loc,
    static_context* sctx,
    dynamic_context* dctx,
    store::Iterator_t it1,
    store::Iterator_t it2,
    XQPCollator* collator,
    bool skip_pi_nodes,
    bool skip_comment_nodes)
{
  store::Item_t child1, child2;
  bool c1Valid, c2Valid;

  it1->open();
  it2->open();

  while (1)
  {
    while ((c1Valid = it1->next(child1))
            &&
            ((skip_pi_nodes && child1->getNodeKind() == store::StoreConsts::piNode)
              ||
            (skip_comment_nodes && child1->getNodeKind() == store::StoreConsts::commentNode)))
      ;

    while ((c2Valid = it2->next(child2))
            &&
            ((skip_pi_nodes && child2->getNodeKind() == store::StoreConsts::piNode)
              ||
            (skip_comment_nodes && child2->getNodeKind() == store::StoreConsts::commentNode)))
      ;

    if (!c1Valid && !c2Valid)
      return true;
    else if (!c1Valid || !c2Valid)
      return false;
    else if (!DeepEqual(loc, sctx, dctx, child1, child2, collator))
      return false;
  }

  return true;
}

static bool DeepEqualAttributes(
  const QueryLoc& loc,
  static_context* sctx,
  dynamic_context* dctx,
  store::Iterator_t it1,
  store::Iterator_t it2,
  XQPCollator* collator)
{
  store::Item_t child1, child2;
  int c1count = 0, c2count = 0;

  it1->open();
  it2->open();

  while (it1->next(child1))
  {
    c1count++;
    it2->reset();
    bool found = false;
    while (it2->next(child2))
      if (DeepEqual(loc, sctx, dctx, child1, child2, collator))
      {
        found = true;
        break;
      }

    if (!found)
      return false;
  }

  it2->reset();
  while (it2->next(child2))
    c2count++;

  if (c1count != c2count)
    return false;

  return true;
}

static bool DeepEqual(
    const QueryLoc& loc,
    static_context* sctx,
    dynamic_context* dctx,
    store::Item_t& item1,
    store::Item_t& item2,
    XQPCollator* collator)
{
  const RootTypeManager& rtm = GENV_TYPESYSTEM;
  TypeManager* tm = sctx->get_typemanager();

  if (item1.isNull() && item2.isNull())
    return true;

  if (item1 == NULL || item2 == NULL)
    return false;

  if (item1->isNode() != item2->isNode())
    return false;

  if (item1->isAtomic())
  {
    assert(item2->isAtomic());
    long timezone = dctx->get_implicit_timezone();

    if (collator == NULL)
      collator = sctx->get_default_collator(QueryLoc::null);

    // check NaN
    xqtref_t type1 = tm->create_value_type(item1.getp());
    xqtref_t type2 = tm->create_value_type(item2.getp());

    if (((TypeOps::is_subtype(tm, *type1, *rtm.FLOAT_TYPE_ONE)
          &&
          item1->getFloatValue().isNaN())
          ||
         (TypeOps::is_subtype(tm, *type1, *rtm.DOUBLE_TYPE_ONE)
          &&
          item1->getDoubleValue().isNaN()))
          &&
        ((TypeOps::is_subtype(tm, *type2, *rtm.FLOAT_TYPE_ONE)
          &&
          item2->getFloatValue().isNaN())
          ||
         (TypeOps::is_subtype(tm, *type2, *rtm.DOUBLE_TYPE_ONE)
          &&
          item2->getDoubleValue().isNaN())))
      return true;

    try
    {
      return CompareIterator::valueEqual(loc, item1, item2, tm, timezone, collator);
    }
    catch (ZorbaException const& e)
    {
      if (e.diagnostic() == err::XPTY0004)
        return false;
      throw;
    }
  }
  else
  {
    assert(item1->isNode());
    assert(item2->isNode());

    if (item1->getNodeKind() != item2->getNodeKind())
      return false;

    switch (item1->getNodeKind())
    {
      case store::StoreConsts::anyNode:
        ZORBA_ASSERT(false);  // case not treated
        break;

      case store::StoreConsts::documentNode:
        return DeepEqual(loc,
                         sctx,
                         dctx,
                         item1->getChildren(),
                         item2->getChildren(),
                         collator,
                         true,
                         false);
        break;

      case store::StoreConsts::elementNode:
        if (! item1->getNodeName()->equals(item2->getNodeName()))
          return false;

        return (DeepEqualAttributes(loc,
                                    sctx,
                                    dctx,
                                    item1->getAttributes(),
                                    item2->getAttributes(),
                                    collator)
                &&
                DeepEqual(loc,
                          sctx,
                          dctx,
                          item1->getChildren(),
                          item2->getChildren(),
                          collator,
                          true,
                          true));
        break;

      case store::StoreConsts::attributeNode:
      {
        if (! item1->getNodeName()->equals(item2->getNodeName()))
          return false;

        store::Item_t tvalue1, tvalue2;
        store::Iterator_t tvalue1Iter, tvalue2Iter;
        item1->getTypedValue(tvalue1, tvalue1Iter);
        item2->getTypedValue(tvalue2, tvalue2Iter);

        if (tvalue1Iter == NULL && tvalue2Iter == NULL)
          return DeepEqual(loc, sctx, dctx, tvalue1, tvalue2, collator);
        else if (tvalue1Iter != NULL && tvalue2Iter != NULL)
          return DeepEqual(loc, sctx, dctx, tvalue1Iter, tvalue2Iter, collator, false, false);
        else
          return false;

        break;
      }
      case store::StoreConsts::textNode:     /* deliberate fall-through */
      case store::StoreConsts::commentNode:
      {
        return (0 == utf8::compare(item1->getStringValue(),
                                   item2->getStringValue(),
                                   collator));
        break;
      }

      case store::StoreConsts::piNode:
      {
        int lCmpRes = utf8::compare(item1->getNodeName()->getStringValue(),
                                    item2->getNodeName()->getStringValue(),
                                    collator);
        if (0 != lCmpRes)
          return false;

        lCmpRes = utf8::compare(item1->getStringValue(),
                                item2->getStringValue(),
                                collator);

        return (0 == lCmpRes);
        break;
      }
    }

    ZORBA_ASSERT(false);  // should never reach here
    return false;
  }
}

bool FnDeepEqualIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  PlanIteratorState* state;
  store::Item_t arg1, arg2;
  XQPCollator* collator = NULL;
  bool equal = true;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if ( theChildren.size() == 3 )
  {
    collator = getCollator(theSctx, loc, planState, theChildren[2].getp());
  }

  while (1)
  {
    bool a1 = consumeNext(arg1, theChildren[0].getp(), planState);
    bool a2 = consumeNext(arg2, theChildren[1].getp(), planState);

    if (!a1 && !a2)
      break;
    else if (!a1 || !a2)
    {
      equal = false;
      break;
    }

    if (arg1->isFunction() || arg2->isFunction())
    {
			throw XQUERY_EXCEPTION(
          err::FOTY0015,
          ERROR_PARAMS ( (arg1->isFunction()
                            ? arg1
                            : arg2
                         )->getFunctionName()->getStringValue() ),
          ERROR_LOC( loc )
        );
    }

    equal = equal && DeepEqual(loc,
                               theSctx,
                               planState.theLocalDynCtx,
                               arg1,
                               arg2,
                               collator);
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, equal), state);

  STACK_END (state);
}

/*******************************************************************************

  15.3.3 op:intersect : implemented by the HashSemiJoinIterator below

  15.3.4 op:except : implemented by the HashSemiJoinIterator below

  Hashing semi/anti join iterator.

  First producer goes in the result if a match in the second producer is
  found/not found. The order of the first producer is retained. No duplicate
  elimination is performed.
********************************************************************************/
HashSemiJoinIteratorState::HashSemiJoinIteratorState()
{
  theRightInput = new store::NodeHashSet();
}


HashSemiJoinIteratorState::~HashSemiJoinIteratorState()
{
  delete theRightInput;
  theRightInput = 0;
}


void HashSemiJoinIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
}


void HashSemiJoinIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theRightInput->clear();
}


bool HashSemiJoinIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItem;
  bool not_found;

  HashSemiJoinIteratorState* state;
  DEFAULT_STACK_INIT(HashSemiJoinIteratorState, state, planState);

  // eat the complete right-hand side and hash it
  while ( consumeNext(lItem, theChildren[1].getp(), planState))
  {
    state->theRightInput->insert(lItem);
  }

  while (consumeNext(result, theChildren[0].getp(), planState))
  {
    not_found = ! state->theRightInput->exists(result);
    if (not_found == theAntijoin)
      STACK_PUSH(true, state);
  }

  STACK_END (state);
}

/*******************************************************************************
  Sortmerge based semijoin iterator.
********************************************************************************/
bool SortSemiJoinIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item[2];
  short order;
  int i;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);


  for (;;)
  {
    // load items
    for (i = 0; i < 2; i++)
    {
      if (item [i] == NULL)
      {
        if (!CONSUME (item[i], i))
        {
          item[i] = NULL;
          goto done;
        }
      }
    }

    // advance, output
    order = GENV_STORE.compareNodes(item[0].getp(), item[1].getp());
    if ( order == 0 )
    {
      result = item[0];
      STACK_PUSH (true, state);
    }
    else
    {
      item [(order < 0) ? 0 : 1] = NULL;
    }
  }

done:
  STACK_END (state);
}

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
// 15.4 Aggregate Functions                                                    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************
  15.4.1 fn:count
********************************************************************************/
bool FnCountIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lSequenceItem;
  ulong lCount = 0;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (consumeNext(lSequenceItem, theChildren[0].getp(), planState))
  {
    ++lCount;
  }

  STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, Integer(lCount)), state);

  STACK_END(state);
}

/*******************************************************************************
  15.4.2 fn:avg
********************************************************************************/
bool FnAvgIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lSumItem;
  store::Item_t lRunningItem;
  xqtref_t      lRunningType;
  store::Item_t countItem;
  int lCount = 0;
  bool lHitNumeric = false, lHitYearMonth = false, lHitDayTime = false;

  const TypeManager* tm = theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t lUntypedAtomic     = rtm.UNTYPED_ATOMIC_TYPE_ONE;
  xqtref_t lYearMonthDuration = rtm.YM_DURATION_TYPE_ONE;
  xqtref_t lDayTimeDuration   = rtm.DT_DURATION_TYPE_ONE;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (consumeNext(lRunningItem, theChildren[0].getp(), planState))
  {
    lRunningType = tm->create_value_type(lRunningItem);

    if (TypeOps::is_numeric(tm, *lRunningType) ||
        TypeOps::is_equal(tm, *lRunningType, *lUntypedAtomic))
    {
      lHitNumeric = true;

      if ( lHitYearMonth )
        RAISE_ERROR(err::FORG0006, loc,
				ERROR_PARAMS(ZED(BadArgTypeForFn_2o34o),
                     *lRunningType,
                     "fn:avg",
                     ZED(ExpectedType_5),
                     *lYearMonthDuration));

      if ( lHitDayTime )
        RAISE_ERROR(err::FORG0006, loc,
        ERROR_PARAMS(ZED( BadArgTypeForFn_2o34o ),
                     *lRunningType,
                     "fn:avg",
                     ZED( ExpectedType_5 ),
                     *lDayTimeDuration));
    }
    else if (TypeOps::is_equal(tm, *lRunningType, *lYearMonthDuration))
    {
      lHitYearMonth = true;

      if (lHitNumeric)
        RAISE_ERROR(err::FORG0006, loc,
        ERROR_PARAMS(ZED(BadArgTypeForFn_2o34o),
                     *lRunningType,
                     "fn:avg",
                     ZED(ExpectedNumericType)));

      if (lHitDayTime)
        RAISE_ERROR(err::FORG0006, loc,
        ERROR_PARAMS(ZED( BadArgTypeForFn_2o34o ),
                     *lRunningType,
                     "fn:avg",
                     ZED( ExpectedType_5 ),
                     *lDayTimeDuration));
    }
    else if (TypeOps::is_equal(tm, *lRunningType, *lDayTimeDuration))
    {
      lHitDayTime = true;

      if ( lHitNumeric )
        RAISE_ERROR(err::FORG0006, loc,
        ERROR_PARAMS(ZED(BadArgTypeForFn_2o34o),
                     *lRunningType,
                     "fn:avg",
                     ZED(ExpectedNumericType)));

      if ( lHitYearMonth )
        RAISE_ERROR(err::FORG0006, loc,
        ERROR_PARAMS(ZED(BadArgTypeForFn_2o34o),
                     *lRunningType,
                     "fn:avg",
                     ZED(ExpectedType_5),
                     *lYearMonthDuration));
    }
    else
    {
			RAISE_ERROR(err::FORG0006, loc,
			ERROR_PARAMS(ZED(BadArgTypeForFn_2o34o),
                   *lRunningType,
                   "fn:avg",
                   ZED(ExpectedNumericOrDurationType)));
    }

    if ( lCount++ == 0 )
    {
      lSumItem = lRunningItem;
    }
    else
    {
      // DO NOT short-circuit for INF and NaN!
      // Must check all items in case FORG0006 is needed
      GenericArithIterator<AddOperation>::compute(lSumItem,
                                                  planState.theLocalDynCtx,
                                                  tm,
                                                  loc,
                                                  lSumItem,
                                                  lRunningItem);
    }
  }

  if (lCount > 0)
  {
    GENV_ITEMFACTORY->createInteger(countItem, Integer(lCount));
    GenericArithIterator<DivideOperation>::compute(result,
                                                   planState.theLocalDynCtx,
                                                   tm,
                                                   loc,
                                                   lSumItem,
                                                   countItem);

    STACK_PUSH(true, state);
  }
  // else return empty sequence

  STACK_END (state);
}

/*******************************************************************************
  15.4.5 fn:sum - Generic
********************************************************************************/
bool FnSumIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lRunningItem;
  xqtref_t      lResultType;
  xqtref_t      lRunningType;

  const TypeManager* tm = theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    // casting of untyped atomic
    lResultType = tm->create_value_type(result);

    if (TypeOps::is_subtype(tm, *lResultType, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm, NULL, loc);
      lResultType = rtm.DOUBLE_TYPE_ONE;
    }

    if (!TypeOps::is_numeric(tm, *lResultType) &&
        (!TypeOps::is_subtype(tm, *lResultType, *rtm.DURATION_TYPE_ONE) ||
         TypeOps::is_equal(tm, *lResultType, *rtm.DURATION_TYPE_ONE)))
    {
      RAISE_ERROR(err::FORG0006, loc,
			ERROR_PARAMS(ZED(BadArgTypeForFn_2o34o), *lResultType, "fn:sum"));
    }

    while (consumeNext(lRunningItem, theChildren[0].getp(), planState))
    {
      // casting of untyped atomic
      lRunningType = tm->create_value_type(lRunningItem);

      if (TypeOps::is_subtype(tm, *lRunningType, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
      {
        GenericCast::castToAtomic(lRunningItem,
                                  lRunningItem,
                                  &*rtm.DOUBLE_TYPE_ONE,
                                  tm,
                                  NULL,
                                  loc);

        lRunningType = rtm.DOUBLE_TYPE_ONE;
      }

      // handling of NaN
      if (lRunningItem->isNaN())
      {
         result = lRunningItem;
        break;
      }

      if((TypeOps::is_numeric(tm, *lResultType) &&
          TypeOps::is_numeric(tm, *lRunningType)) ||
         (TypeOps::is_subtype(tm, *lResultType, *rtm.YM_DURATION_TYPE_ONE) &&
          TypeOps::is_subtype(tm, *lRunningType, *rtm.YM_DURATION_TYPE_ONE)) ||
         (TypeOps::is_subtype(tm, *lResultType, *rtm.DT_DURATION_TYPE_ONE) &&
          TypeOps::is_subtype(tm, *lRunningType, *rtm.DT_DURATION_TYPE_ONE)))
      {
        GenericArithIterator<AddOperation>::compute(result,
                                                    planState.theLocalDynCtx,
                                                    tm,
                                                    loc,
                                                    result,
                                                    lRunningItem);
      }
      else
      {
				throw XQUERY_EXCEPTION(
					err::FORG0006,
					ERROR_PARAMS(
						ZED( SumImpossibleWithTypes_23 ), *lResultType, *lRunningType
					),
					ERROR_LOC( loc )
				);
      }
    }

    STACK_PUSH(true, state);
  }
  else
  {
    if (theChildren.size() == 2)
    {
      if (consumeNext(result, theChildren[1].getp(), planState))
      {
        STACK_PUSH(true, state);
      }
      // return the empty sequence otherwise
    }
    else
    {
      STACK_PUSH(
				GENV_ITEMFACTORY->createInteger( result, Integer::zero() ), state
			);
    }
  }

  STACK_END (state);
}

/*******************************************************************************
  15.4.5 fn:sum - Double
********************************************************************************/
bool FnSumDoubleIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  xs_double sum;
  store::Item_t item;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    sum = item->getDoubleValue();

    while (consumeNext(item, theChildren[0].getp(), planState))
    {
      if (item->isNaN())
      {
        result = item;
        break;
      }

      sum += item->getDoubleValue();
    }

    GENV_ITEMFACTORY->createDouble(result, sum);

    STACK_PUSH(true, state);
  }
  else if (theChildren.size() == 2)
  {
    if (consumeNext(result, theChildren[1].getp(), planState))
    {
      STACK_PUSH(true, state);
    }
  }
  else
  {
    GENV_ITEMFACTORY->createInteger(result, Integer::zero());
    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


/*******************************************************************************
  15.4.5 fn:sum - Float
********************************************************************************/
bool FnSumFloatIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  xs_float sum;
  store::Item_t item;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    sum = item->getFloatValue();

    while (consumeNext(item, theChildren[0].getp(), planState))
    {
      if (item->isNaN())
      {
        result = item;
        break;
      }

      sum += item->getFloatValue();
    }

    GENV_ITEMFACTORY->createFloat(result, sum);

    STACK_PUSH(true, state);
  }
  else if (theChildren.size() == 2)
  {
    if (consumeNext(result, theChildren[1].getp(), planState))
    {
      STACK_PUSH(true, state);
    }
  }
  else
  {
    GENV_ITEMFACTORY->createInteger(result, Integer::zero());
    STACK_PUSH(true, state);
  }

  STACK_END (state);
}

/*******************************************************************************
  15.4.5 fn:sum - Decimal
********************************************************************************/
bool FnSumDecimalIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  xs_decimal sum;
  store::Item_t item;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    sum = item->getDecimalValue();

    while (consumeNext(item, theChildren[0].getp(), planState))
    {
      if (item->isNaN())
      {
        result = item;
        break;
      }

      sum += item->getDecimalValue();
    }

    GENV_ITEMFACTORY->createDecimal(result, sum);

    STACK_PUSH(true, state);
  }
  else if (theChildren.size() == 2)
  {
    if (consumeNext(result, theChildren[1].getp(), planState))
    {
      STACK_PUSH(true, state);
    }
  }
  else
  {
    GENV_ITEMFACTORY->createInteger(result, Integer::zero());
    STACK_PUSH(true, state);
  }

  STACK_END (state);
}

/*******************************************************************************
  15.4.5 fn:sum - Integer
********************************************************************************/
bool FnSumIntegerIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  xs_integer    sum;
  store::Item_t item;
  xqtref_t      lResultType;
  xqtref_t      lTmpType;

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    lResultType = tm->create_value_type(item);
    sum = item->getIntegerValue();

    while (consumeNext(item, theChildren[0].getp(), planState))
    {
      lTmpType = tm->create_value_type(item);
      if(TypeOps::is_subtype(tm, *lResultType, *lTmpType))
        lResultType = lTmpType;

      if (item->isNaN())
      {
        result = item;
        break;
      }

      sum += item->getIntegerValue();
    }

    GENV_ITEMFACTORY->createInteger(result, sum);
    GenericCast::castToAtomic(result, result, &*lResultType, tm, NULL, loc);

    STACK_PUSH(true, state);
  }
  else if (theChildren.size() == 2)
  {
    if (consumeNext(result, theChildren[1].getp(), planState))
    {
      STACK_PUSH(true, state);
    }
  }
  else
  {
    GENV_ITEMFACTORY->createInteger(result, Integer::zero());
    STACK_PUSH(true, state);
  }

  STACK_END (state);
}

/*******************************************************************************
  15.5.1 op:to
********************************************************************************/
bool
OpToIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  store::Item_t lItem;
  OpToIteratorState* state;
  DEFAULT_STACK_INIT(OpToIteratorState, state, planState);

  if (consumeNext(lItem, theChildren[0].getp(), planState))
  {
    state->theFirstVal = lItem->getIntegerValue();

    if (consumeNext(lItem, theChildren[1].getp(), planState))
    {
      state->theLastVal = lItem->getIntegerValue();

      // return empty sequence otherwise
      if ( state->theLastVal >= state->theFirstVal )
      {
        state->theCurInt = state->theFirstVal;
        while ( state->theCurInt <= state->theLastVal )
        {
          STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, state->theCurInt), state);
          ++state->theCurInt;
        }

      }
    }
  }

  STACK_END (state);
}

/*******************************************************************************
  15.5.4 fn:doc
********************************************************************************/
static void fillTime (
    const zorbatm::walltime& t0,
    const zorbatm::cputime& t0user,
    PlanState& planState)
{
  zorbatm::walltime t1;
  zorbatm::cputime t1user;

  zorbatm::get_current_cputime(t1user);
  zorbatm::get_current_walltime(t1);

  planState.theGlobalDynCtx->theDocLoadingUserTime +=
    zorbatm::get_cputime_elapsed(t0user, t1user);

  planState.theGlobalDynCtx->theDocLoadingTime +=
    zorbatm::get_walltime_elapsed(t0, t1);
}

/**
 * Utility method for fn:doc() and fn:doc-available(). Given an input string,
 * use a few heuristics to create a valid URI, assuming that the input might
 * be an absolute or relative filesystem path, etc.
 */
static zstring normalizeInput(zstring const& aUri, static_context* aSctx,
                              QueryLoc const& loc)
{
  zstring const aBaseUri = aSctx->get_base_uri();
  zstring lResolvedURI;

  try
  {
    // To support the very common (if technically incorrect) use
    // case of users passing local filesystem paths to fn:doc(),
    // we use the following heuristic: IF the base URI has a file:
    // scheme AND the incoming URI has no scheme, we will assume
    // the incoming URI is actually a filesystem path.  QQQ For
    // the moment, we assume any "unknown" schemes are probably
    // Windows drive letters.
    if ((uri::get_scheme(aUri) == uri::none ||
         uri::get_scheme(aUri) == uri::unknown) &&
        uri::get_scheme(aBaseUri) == uri::file)
    {
      // Ok, we assume it's a filesystem path. First normalize it.
      zstring lNormalizedPath =
        fs::get_normalized_path(aUri, zstring(""));
      // QQQ For now, get_normalized_path() doesn't do what we
      // want when base URI represents a file. So, when the
      // normalized path is relative, we pretend it's a relative
      // URI and resolve it as such.
      if (fs::is_absolute(lNormalizedPath))
      {
        URI::encode_file_URI(lNormalizedPath, lResolvedURI);
      }
      else
      {
#ifdef WIN32
        ascii::replace_all(lNormalizedPath, '\\', '/');
#endif
        lResolvedURI = aSctx->resolve_relative_uri(lNormalizedPath, true);
      }
    }
    else
    {
      // We do NOT assume it's a filesystem path; just resolve it.
      lResolvedURI = aSctx->resolve_relative_uri(aUri, true);
    }
  }
  catch (ZorbaException& e)
  {
    if (e.diagnostic() == err::XQST0046)
      // the value of a URILiteral is of nonzero length and is not in the
      // lexical space of xs:anyURI.
      e.set_diagnostic(err::FODC0005);
    else
      e.set_diagnostic(err::FODC0002);

    set_source(e, loc);
    throw;
  }

  return lResolvedURI;
}

static void loadDocument(
  zstring const& aUri,
  static_context* aSctx,
  PlanState& aPlanState,
  QueryLoc const& loc,
  store::Item_t& oResult)
{
  // Normalize input to handle filesystem paths, etc.
  zstring const lNormUri(normalizeInput(aUri, aSctx, loc));

  // See if this (normalized) URI is already loaded in the store.
  try {
    oResult = GENV_STORE.getDocument(lNormUri);
  }
  catch (XQueryException& e) {
    set_source(e, loc);
    throw;
  }
  if (oResult != NULL) {
    return;
  }

  // Prepare a LoadProperties for loading the stream into the store
  store::LoadProperties lLoadProperties;
  lLoadProperties.setStoreDocument(true);
  lLoadProperties.setDTDValidate( aSctx->is_feature_set( feature::dtd ) );

  // Resolve URI to a stream
  zstring lErrorMessage;
  std::auto_ptr<internal::Resource> lResource = aSctx->resolve_uri
      (lNormUri, internal::EntityData::DOCUMENT, lErrorMessage);
  internal::StreamResource* lStreamResource =
      dynamic_cast<internal::StreamResource*>(lResource.get());
  if (lStreamResource == NULL) {
    throw XQUERY_EXCEPTION
        (err::FODC0002, ERROR_PARAMS(aUri, lErrorMessage), ERROR_LOC(loc));
  }
  std::istream* lStream = lStreamResource->getStream();
  if (lStream == NULL) {
    throw XQUERY_EXCEPTION(err::FODC0002, ERROR_PARAMS( aUri ), ERROR_LOC(loc));
  }

  // Load stream into store. NOTE: this will be replaced by calls to XQuery
  // functions doc:add() et al soon.
  zorbatm::walltime t0;
  zorbatm::cputime t0user;
  zorbatm::get_current_cputime (t0user);
  zorbatm::get_current_walltime(t0);
  try {
    store::Store& lStore = GENV.getStore();
    zstring lBaseUri = aSctx->get_base_uri();
    oResult = lStore.loadDocument(lBaseUri, lNormUri, *lStream, lLoadProperties);
    fillTime(t0, t0user, aPlanState);
  }
  catch (ZorbaException& e) {
    e.set_diagnostic(err::FODC0002);
    set_source(e, loc);
    throw;
  }
  if (oResult == NULL) {
    throw XQUERY_EXCEPTION(err::FODC0002, ERROR_PARAMS( aUri ), ERROR_LOC(loc));
  }
}

bool FnDocIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t uriItem;
  PlanIteratorState* state;
  zstring uriString;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(uriItem, theChildren[0].getp(), planState))
  {
    uriItem->getStringValue2(uriString);
    loadDocument(uriString, theSctx, planState, loc, result);
    STACK_PUSH(true, state);
  } // return empty sequence if input is the empty sequence

  STACK_END(state);
}

/*******************************************************************************
  15.5.5 fn:doc-available
********************************************************************************/
bool FnDocAvailableIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t    doc;
  store::Item_t    uriItem;
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(uriItem, theChildren[0].getp(), planState))
  {
    try
    {
      zstring uriString;
      uriItem->getStringValue2(uriString);
      loadDocument(uriString, theSctx, planState, loc, doc);
    }
    catch (ZorbaException& e)
    {
      if (e.diagnostic() == err::FODC0005)
      {
        set_source( e, loc );
        throw;
      }
      // other errors fall through and make the function return false
    }
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, doc != NULL), state);
  }
  else
    // return false if input is the empty sequence
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, false), state);

  STACK_END (state);
}


/*******************************************************************************
  14.8.8 fn:environment-variable
********************************************************************************/
bool FnEnvironmentVariableIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  zstring varname;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(item, theChildren[0].getp(),planState);  
  
  item->getStringValue2(varname);
  result = planState.theLocalDynCtx->get_environment_variable(varname);
  STACK_PUSH(result!=NULL, state);
    
  STACK_END(state);
}

/*******************************************************************************
  14.8.9 fn:available-environment-variables
********************************************************************************/
bool FnAvailableEnvironmentVariablesIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Iterator_t lIte;
  FnAvailableEnvironmentVariablesIteratorState* state;
  DEFAULT_STACK_INIT(FnAvailableEnvironmentVariablesIteratorState, state, planState);
    
  state->theIterator = planState.theLocalDynCtx->available_environment_variables();

  state->theIterator->open();
  while (state->theIterator->next(result))
  {
    STACK_PUSH(true, state);
  }
  state->theIterator->close();
  STACK_END(state);
}

void FnAvailableEnvironmentVariablesIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theIterator = 0;
}

void FnAvailableEnvironmentVariablesIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theIterator = 0;
}
 
/*******************************************************************************
  14.8.5 fn:unparsed-text
********************************************************************************/
/**
  * Utility method for fn:unparsed-text() and fn:unparsed-text-available(). 
  */
static void readDocument(
  zstring const& aUri,
  zstring const& aEncoding,
  static_context* aSctx,
  PlanState& aPlanState,
  QueryLoc const& loc,
  store::Item_t& oResult)
{
  //Normalize input to handle filesystem paths, etc.
  zstring const lNormUri(normalizeInput(aUri, aSctx, loc));

  //Resolve URI to stream
  zstring lErrorMessage;
  std::auto_ptr<internal::Resource> lResource = aSctx->resolve_uri
    (lNormUri, internal::EntityData::SOME_CONTENT, lErrorMessage);

  internal::StreamResource* lStreamResource =
    dynamic_cast<internal::StreamResource*>(lResource.get());
    
  if (lStreamResource == NULL)
  {
    throw XQUERY_EXCEPTION(err::FOUT1170, ERROR_PARAMS(aUri), ERROR_LOC(loc));
  }
  StreamReleaser lStreamReleaser = lStreamResource->getStreamReleaser();
  std::unique_ptr<std::istream, StreamReleaser> lStream(lStreamResource->getStream(), lStreamReleaser);

  lStreamResource->setStreamReleaser(nullptr);  

  //check if encoding is needed
  if (transcode::is_necessary(aEncoding.c_str()))
  {
    if (!transcode::is_supported(aEncoding.c_str()))
    {
      throw XQUERY_EXCEPTION(err::FOUT1190, ERROR_PARAMS(aUri), ERROR_LOC(loc));
    }
    transcode::attach(*lStream.get(), aEncoding.c_str());
  }
  //creates stream item
  GENV_ITEMFACTORY->createStreamableString(
    oResult,
    *lStream.release(),
    lStream.get_deleter()
    );

  if (oResult.isNull())
  {
    throw XQUERY_EXCEPTION(err::FOUT1170, ERROR_PARAMS(aUri), ERROR_LOC(loc));
  }
}

bool FnUnparsedTextIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t uriItem;
  store::Item_t encodingItem;
  zstring uriString;
  zstring encodingString("UTF-8");

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(uriItem, theChildren[0].getp(), planState))
  {
    STACK_PUSH(false, state);
  }

  if (theChildren.size() == 2)
  {
    consumeNext(encodingItem, theChildren[1].getp(), planState);
    encodingItem->getStringValue2(encodingString);
  }

  uriItem->getStringValue2(uriString);
  readDocument(uriString, encodingString, theSctx, planState, loc, result);
  STACK_PUSH(true, state);

  STACK_END(state);
}


/*******************************************************************************
  14.8.7 fn:unparsed-text-available
********************************************************************************/
   
bool FnUnparsedTextAvailableIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t unparsedText;
  store::Item_t uriItem;
  store::Item_t encodingItem;
  zstring uriString;
  zstring encodingString("UTF-8");

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
    
  if (!consumeNext(uriItem, theChildren[0].getp(), planState))
  {
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, false), state);
  }

  if (theChildren.size() == 2)
  {
    consumeNext(encodingItem, theChildren[1].getp(), planState);
    encodingItem->getStringValue2(encodingString);
  }

  uriItem->getStringValue2(uriString);

  try
  {
    readDocument(uriString, encodingString, theSctx, planState, loc, unparsedText);
  }
  catch (XQueryException const& e)
  {
    unparsedText = NULL;
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, !(unparsedText.isNull()) ), state);
    
  STACK_END(state);
}

/*******************************************************************************
  14.8.6 fn:unparsed-text-lines
********************************************************************************/
FnUnparsedTextLinesIteratorState::~FnUnparsedTextLinesIteratorState()
{
  delete theStream;
  theStream = 0;
  theStreamResource = 0;
}

bool FnUnparsedTextLinesIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t uriItem;
  store::Item_t encodingItem;
  store::Item_t streamItem;
  zstring streamLine;
  zstring uriString;
  zstring encodingString("UTF-8");
  zstring lNormUri;
  zstring lErrorMessage;
  std::auto_ptr<internal::Resource> lResource;
  StreamReleaser lStreamReleaser;

  FnUnparsedTextLinesIteratorState* state;
  DEFAULT_STACK_INIT(FnUnparsedTextLinesIteratorState, state, planState);

  if (!consumeNext(uriItem, theChildren[0].getp(), planState))
  {
    STACK_PUSH(false, state);
  }
  
  if (theChildren.size() == 2)
  {
    consumeNext(encodingItem, theChildren[1].getp(), planState);
    encodingItem->getStringValue2(encodingString);
  }
  
  //Normalize input to handle filesystem paths, etc.
  uriItem->getStringValue2(uriString);
  lNormUri = normalizeInput(uriString, theSctx, loc);

  //Resolve URI to stream
  lResource = theSctx->resolve_uri
    (lNormUri, internal::EntityData::SOME_CONTENT, lErrorMessage);

  state->theStreamResource =
    dynamic_cast<internal::StreamResource*>(lResource.get());

  if (state->theStreamResource == NULL)
    throw XQUERY_EXCEPTION(err::FOUT1170, ERROR_PARAMS(uriString), ERROR_LOC(loc));
  
  lStreamReleaser = state->theStreamResource->getStreamReleaser();
  state->theStream = new std::unique_ptr<std::istream, StreamReleaser> (state->theStreamResource->getStream(), lStreamReleaser);
  state->theStreamResource->setStreamReleaser(nullptr);

  //check if encoding is needed
  if (transcode::is_necessary(encodingString.c_str()))
  {
    if (!transcode::is_supported(encodingString.c_str()))
    {
      throw XQUERY_EXCEPTION(err::FOUT1190, ERROR_PARAMS(uriString), ERROR_LOC(loc));
    }
    transcode::attach(*state->theStream->get(), encodingString.c_str());
  }

  while (state->theStream->get()->good())
  {
    getline(*state->theStream->get(), streamLine);
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, streamLine), state);
  }

  STACK_END(state);
}

void FnUnparsedTextLinesIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theStreamResource = 0;
  theStream = 0;
}

void FnUnparsedTextLinesIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  delete theStream;
  theStream = 0;
  theStreamResource = 0;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
