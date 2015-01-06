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

#include "deep_equality.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

#include "zorbatypes/decimal.h"
#include "zorbatypes/URI.h"
#include "zorbamisc/ns_consts.h"
#include "zorbautils/fatal.h"

// For timing
#include <zorba/util/time.h>

#include <zorba/util/transcode_stream.h>

#include <util/fs_util.h>
#include <util/uri_util.h>

#include <compiler/api/compilercb.h>

#include <runtime/sequences/sequences.h>
#include <runtime/core/arithmetic_impl.h>
#include <runtime/util/iterator_impl.h>
#include <runtime/visitors/planiter_visitor.h>
#include <runtime/util/doc_uri_heuristics.h>

#include <system/globalenv.h>

#include <types/casting.h>
#include <types/typeops.h>
#include <types/typeimpl.h>

#include <store/api/store.h>
#include <store/api/iterator.h>
#include <store/api/item_factory.h>
#include "store/api/temp_seq.h"
#include <store/api/pul.h>

#include <context/static_context.h>

#include "zorbautils/hashset_structured_itemh.h"
#include "zorbautils/hashset_atomic_itemh.h"

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
  {
    RAISE_ERROR(err::XPTY0004, loc,
    ERROR_PARAMS(ZED(NoEmptySeqAsCollationParam)));
  }

  if (PlanIterator::consumeNext(temp, iter, planState))
  {
    RAISE_ERROR(err::XPTY0004, loc,
    ERROR_PARAMS(ZED(NoSeqAsCollationParam)));
  }

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
  store::Item_t seqItem;
  store::Item_t searchItem;
  TypeManager* tm = theSctx->get_typemanager();
  long timezone = 0;
  bool found;

  FnIndexOfIteratorState* state;
  DEFAULT_STACK_INIT(FnIndexOfIteratorState, state, planState);

  if (!consumeNext(state->theSearchItem, theChildren[1].getp(), planState))
  {
    RAISE_ERROR(err::FORG0006, loc, ERROR_PARAMS(ZED(EmptySeqNoSearchItem)));
  }

  if (theChildren.size() == 3)
  {
    state->theCollator = 
    getCollator(theSctx, loc, planState, theChildren[2].getp());
  }

  while (consumeNext(seqItem, theChildren[0].getp(), planState))
  {
    // inc the position in the sequence; do it at the beginning of the loop
    // because index-of starts with one
    ++state->theCurrentPos;

    try
    {
      if (theFastComp == 1)
      {
        found = seqItem->equals(state->theSearchItem, timezone, state->theCollator);
      }
      else if (theFastComp == 2)
      {
        found = state->theSearchItem->equals(seqItem, timezone, state->theCollator);
      }
      else
      {
        searchItem = state->theSearchItem;

        found = CompareIterator::valueEqual(loc,
                                            seqItem,
                                            searchItem,
                                            tm,
                                            timezone,
                                            state->theCollator,
                                            true);
      }
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
  if (theAlreadySeenMap.get() != NULL)
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
  state->theAlreadySeenMap.reset(new AtomicItemHandleHashSet(valueCompare));

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
  store::Item_t item;
  xs_long startPos;
  xs_double startPosDouble; 
  xs_double lengthDouble;

  FnSubsequenceIteratorState* state;
  DEFAULT_STACK_INIT(FnSubsequenceIteratorState, state, planState);

  state->theIsChildReset = false;
  
  CONSUME(item, 1);
  startPosDouble = item->getDoubleValue();

  //If starting position is set to +INF return empty sequence
  if (startPosDouble.isPosInf() || startPosDouble.isNaN())
    goto done;

  //Removed startpos - 1, since if a -INF is present it overflows it to a positive number
  startPos =
    static_cast<xs_long>(startPosDouble.round().getNumber());

  if (theChildren.size() == 3)
  {
    CONSUME(item, 2);
    lengthDouble = item->getDoubleValue();
    if ( lengthDouble.isPosInf() ) {
      if ( startPosDouble.isNegInf() ) {
        //
        // XQuery F&0 3.0 14.1.9: ... if $startingLoc is -INF and $length is
        // +INF, then fn:round($startingLoc) + fn:round($length) is NaN; since
        // position() lt NaN is always false, the result is an empty sequence.
        //
        goto done;
      }

      state->theRemaining = 1;
    }
    else
    {
      state->theRemaining =
        static_cast<xs_long>(lengthDouble.round().getNumber());
      if ( state->theRemaining < 0 && lengthDouble > 0 ) {
        // overflow happened
        state->theRemaining = numeric_limits<xs_long>::max();
      }
    }
  }

  if (startPos < 1)
  {
    if ( theChildren.size() == 3 &&
         state->theRemaining != numeric_limits<xs_long>::max() ) {
      state->theRemaining += startPos - 1;
    }
    startPos = 0;
  }

  // If a length is specified and it is <= 0, return the empty sequence
  if (theChildren.size() == 3 && state->theRemaining <= 0)
    goto done;

  // Consume and skip all input items that are before the startPos
  if (!theChildren[0]->skip(startPos-1, planState))
    goto done;

  if (theChildren.size() < 3 || lengthDouble.isPosInf())
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
  if (!theChildren[0]->skip(startPos, planState))
    goto done;

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
  if (!theChildren[0]->skip(startPos, planState))
    goto done;

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
//  15.3 Deep Equal, Union, Intersection, and Except                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************
  15.3.1 fn:deep-equal
********************************************************************************/
bool FnDeepEqualIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  PlanIteratorState* state;
  store::Item_t arg1, arg2;
  XQPCollator* collator = NULL;
  bool equal = true;
  int timezone;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if ( theChildren.size() == 3 )
  {
    collator = getCollator(theSctx, loc, planState, theChildren[2].getp());
  }

  if (collator == NULL)
    collator = theSctx->get_default_collator(QueryLoc::null);

  timezone = planState.theGlobalDynCtx->get_implicit_timezone();

  while (1)
  {
    bool a1 = consumeNext(arg1, theChildren[0].getp(), planState);
    bool a2 = consumeNext(arg2, theChildren[1].getp(), planState);

    if (!a1 && !a2)
    {
      break;
    }
    else if (!a1 || !a2)
    {
      equal = false;
      break;
    }

    if (arg1->isFunction() || arg2->isFunction())
    {
      RAISE_ERROR(err::FOTY0015, loc,
      ERROR_PARAMS((arg1->isFunction() ? arg1 : arg2)->getFunctionName()->getStringValue()));
    }

    equal = equal && equality::deepEqual(loc, theSctx, arg1, arg2, collator, timezone, true);
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, equal), state);

  STACK_END(state);
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
  theRightInput = new StructuredItemHandleHashSet(1024, false);
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
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  theChildren[0]->count(result, planState);

  STACK_PUSH(!!result, state);

  STACK_END(state);
}


/*******************************************************************************
  15.4.2 fn:avg
********************************************************************************/
bool FnAvgIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lSumItem;
  store::Item_t lRunningItem;
  store::SchemaTypeCode lRunningType;
  store::Item_t countItem;
  int lCount = 0;
  bool lHitNumeric = false, lHitYearMonth = false, lHitDayTime = false;

  const TypeManager* tm = theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (consumeNext(lRunningItem, theChildren[0].getp(), planState))
  {
    lRunningType = lRunningItem->getTypeCode();

    if (TypeOps::is_numeric(lRunningType) ||
        lRunningType == store::XS_UNTYPED_ATOMIC)
    {
      lHitNumeric = true;

      if (lHitYearMonth)
      {
        xqtref_t type = tm->create_value_type(lRunningItem);
        RAISE_ERROR(err::FORG0006, loc,
                     ERROR_PARAMS(ZED(BadArgTypeForFn_2o34o),
                     *type,
                     "fn:avg",
                     ZED(ExpectedType_5),
                     *rtm.YM_DURATION_TYPE_ONE));
      }

      if (lHitDayTime)
      {
        xqtref_t type = tm->create_value_type(lRunningItem);
        RAISE_ERROR(err::FORG0006, loc,
        ERROR_PARAMS(ZED( BadArgTypeForFn_2o34o ),
                     *type,
                     "fn:avg",
                     ZED( ExpectedType_5 ),
                     *rtm.DT_DURATION_TYPE_ONE));
      }
    }
    else if (lRunningType == store::XS_YM_DURATION)
    {
      lHitYearMonth = true;

      if (lHitNumeric)
      {
        xqtref_t type = tm->create_value_type(lRunningItem);
        RAISE_ERROR(err::FORG0006, loc,
        ERROR_PARAMS(ZED(BadArgTypeForFn_2o34o),
                     *type,
                     "fn:avg",
                     ZED(ExpectedNumericType)));
      }

      if (lHitDayTime)
      {
        xqtref_t type = tm->create_value_type(lRunningItem);
        RAISE_ERROR(err::FORG0006, loc,
        ERROR_PARAMS(ZED( BadArgTypeForFn_2o34o ),
                     *type,
                     "fn:avg",
                     ZED( ExpectedType_5 ),
                     *rtm.DT_DURATION_TYPE_ONE));
      }
    }
    else if (lRunningType == store::XS_DT_DURATION)
    {
      lHitDayTime = true;

      if (lHitNumeric)
      {
        xqtref_t type = tm->create_value_type(lRunningItem);
        RAISE_ERROR(err::FORG0006, loc,
        ERROR_PARAMS(ZED(BadArgTypeForFn_2o34o),
                     *type,
                     "fn:avg",
                     ZED(ExpectedNumericType)));
      }

      if (lHitYearMonth)
      {
        xqtref_t type = tm->create_value_type(lRunningItem);
        RAISE_ERROR(err::FORG0006, loc,
        ERROR_PARAMS(ZED(BadArgTypeForFn_2o34o),
                     *type,
                     "fn:avg",
                     ZED(ExpectedType_5),
                     *rtm.YM_DURATION_TYPE_ONE));
      }
    }
    else
    {
      xqtref_t type = tm->create_value_type(lRunningItem);
      RAISE_ERROR(err::FORG0006, loc,
                   ERROR_PARAMS(ZED(BadArgTypeForFn_2o34o),
                   *type,
                   "fn:avg",
                   ZED(ExpectedNumericOrDurationType)));
    }

    if (lCount++ == 0)
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
  store::SchemaTypeCode lResultType;
  store::SchemaTypeCode lRunningType;

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    // casting of untyped atomic
    lResultType = result->getTypeCode();

    if (lResultType == store::XS_UNTYPED_ATOMIC)
    {
      GenericCast::castToBuiltinAtomic(result, result, store::XS_DOUBLE, NULL, loc);
      lResultType = store::XS_DOUBLE;
    }

    if (!TypeOps::is_numeric(lResultType) &&
        (!TypeOps::is_subtype(lResultType, store::XS_DURATION) ||
         lResultType == store::XS_DURATION))
    {
      xqtref_t type = tm->create_value_type(result);
      RAISE_ERROR(err::FORG0006, loc,
        ERROR_PARAMS(ZED(BadArgTypeForFn_2o34o), *type, "fn:sum"));
    }

    while (consumeNext(lRunningItem, theChildren[0].getp(), planState))
    {
      // casting of untyped atomic
      lRunningType = lRunningItem->getTypeCode();

      if (lRunningType == store::XS_UNTYPED_ATOMIC)
      {
        GenericCast::castToBuiltinAtomic(lRunningItem,
                                         lRunningItem,
                                         store::XS_DOUBLE,
                                         NULL,
                                         loc);

        lRunningType = store::XS_DOUBLE;
      }

      // handling of NaN
      if (lRunningItem->isNaN())
      {
         result = lRunningItem;
        break;
      }

      if ((TypeOps::is_numeric(lResultType) &&
           TypeOps::is_numeric(lRunningType)) ||
          (TypeOps::is_subtype(lResultType, store::XS_YM_DURATION) &&
           TypeOps::is_subtype(lRunningType, store::XS_YM_DURATION)) ||
          (TypeOps::is_subtype(lResultType, store::XS_DT_DURATION) &&
           TypeOps::is_subtype(lRunningType, store::XS_DT_DURATION)))
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
        xqtref_t type1 = tm->create_value_type(result);
        xqtref_t type2 = tm->create_value_type(lRunningItem);
        RAISE_ERROR(err::FORG0006, loc,
          ERROR_PARAMS(ZED( SumImpossibleWithTypes_23 ), *type1, *type2));
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
      STACK_PUSH(GENV_ITEMFACTORY->
                 createInteger(result, numeric_consts<xs_integer>::zero()),
                 state);
    }
  }

  STACK_END(state);
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
    GENV_ITEMFACTORY->createInteger(result, numeric_consts<xs_integer>::zero());
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
    GENV_ITEMFACTORY->createInteger(result, numeric_consts<xs_integer>::zero());
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
    GENV_ITEMFACTORY->createInteger(result, numeric_consts<xs_integer>::zero());
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
  store::SchemaTypeCode lResultType;
  store::SchemaTypeCode lTmpType;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    lResultType = item->getTypeCode();

    sum = item->getIntegerValue();

    while (consumeNext(item, theChildren[0].getp(), planState))
    {
      lTmpType = item->getTypeCode();

      if (TypeOps::is_subtype(lResultType, lTmpType))
        lResultType = lTmpType;

      if (item->isNaN())
      {
        result = item;
        break;
      }

      sum += item->getIntegerValue();
    }

    GENV_ITEMFACTORY->createInteger(result, sum);

    GenericCast::castToBuiltinAtomic(result, result, lResultType, NULL, loc);

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
    GENV_ITEMFACTORY->createInteger(result, numeric_consts<xs_integer>::zero());
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


static void loadDocument(
    zstring const& aUri,
    static_context* aSctx,
    PlanState& aPlanState,
    QueryLoc const& loc,
    store::Item_t& oResult)
{
  // Normalize input to handle filesystem paths, etc.
  zstring lNormUri;
  normalizeInputUri(aUri, aSctx, loc, &lNormUri);

  // See if this (normalized) URI is already loaded in the store.
  try 
  {
    oResult = GENV_STORE.getDocument(lNormUri);
  }
  catch (XQueryException& e)
  {
    set_source(e, loc);
    throw;
  }

  if (oResult != NULL)
    return;

  // Prepare a LoadProperties for loading the stream into the store
  store::LoadProperties lLoadProperties;
  lLoadProperties.setStoreDocument(true);
  lLoadProperties.setDTDValidate( aSctx->is_feature_set( feature::dtd ) );
  lLoadProperties.setBaseUri(lNormUri);

  // Resolve URI to a stream
  zstring lErrorMessage;

  std::unique_ptr<internal::Resource> lResource =
  aSctx->resolve_uri(lNormUri, internal::EntityData::DOCUMENT, lErrorMessage);

  internal::StreamResource* lStreamResource =
  dynamic_cast<internal::StreamResource*>(lResource.get());

  if (lStreamResource == NULL)
  {
    throw XQUERY_EXCEPTION
        (err::FODC0002, ERROR_PARAMS(aUri, lErrorMessage), ERROR_LOC(loc));
  }

  std::istream* lStream = lStreamResource->getStream();
  if (lStream == NULL)
  {
    throw XQUERY_EXCEPTION(err::FODC0002, ERROR_PARAMS( aUri ), ERROR_LOC(loc));
  }

  // Load stream into store. NOTE: this will be replaced by calls to XQuery
  // functions doc:add() et al soon.
  zorbatm::walltime t0;
  zorbatm::cputime t0user;
  zorbatm::get_current_cputime (t0user);
  zorbatm::get_current_walltime(t0);

  try
  {
    store::Store& lStore = GENV.getStore();
    oResult = lStore.loadDocument(lNormUri, lNormUri, *lStream, lLoadProperties);
    fillTime(t0, t0user, aPlanState);
  }
  catch (ZorbaException& e)
  {
    e.set_diagnostic(err::FODC0002);
    set_source(e, loc);
    throw;
  }

  if (oResult == NULL)
  {
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
  zstring lNormUri;
  normalizeInputUri(aUri, aSctx, loc, &lNormUri);

  //Check for a fragment identifier
  //Create a zorba::URI for validating if it contains a fragment  
  std::unique_ptr<zorba::URI> lUri(new zorba::URI(lNormUri));
  if (lUri->get_encoded_fragment() != "")
  {
    throw XQUERY_EXCEPTION(err::FOUT1170, ERROR_PARAMS(aUri), ERROR_LOC(loc));    
  }

  //Resolve URI to stream
  zstring lErrorMessage;
  std::unique_ptr<internal::Resource> lResource = aSctx->resolve_uri
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
    *lStream.get(),
    lStream.get_deleter()
  );
  lStream.release();

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
  catch (XQueryException const&)
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
  std::unique_ptr<internal::Resource> lResource;
  StreamReleaser lStreamReleaser;
  std::unique_ptr<zorba::URI> lUri;

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
  normalizeInputUri(uriString, theSctx, loc, &lNormUri);

  //Check for a fragment identifier
  //Create a zorba::URI for validating if it contains a fragment  
  lUri.reset(new zorba::URI(lNormUri));
  if (lUri->get_encoded_fragment() != "")
  {
    throw XQUERY_EXCEPTION(err::FOUT1170, ERROR_PARAMS(uriString), ERROR_LOC(loc));    
  }

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
