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
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "zorbautils/fatal.h"
#include "zorbaerrors/error_manager.h"
#include "zorbatypes/zorbatypesError.h"
#include "zorbaerrors/error_messages.h"
#include "zorbatypes/URI.h"

// For timing
#include <zorbatypes/zorbatypes_decl.h>
#include <zorbatypes/datetime.h>
#include <zorbatypes/duration.h>
#include <zorbatypes/floatimpl.h>
#include "util/time.h"

#include "runtime/sequences/SequencesImpl.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/numerics/NumericsImpl.h"
#include "runtime/api/runtimecb.h"
#include "runtime/core/arithmetic_impl.h"
#include "runtime/util/iterator_impl.h"
#include "runtime/util/handle_hashset_item_value.h"

#include "system/globalenv.h"

#include "types/casting.h"
#include "types/typeops.h"

#include "store/api/store.h"
#include "store/api/iterator.h"
#include "store/api/item_factory.h"
#include "store/api/pul.h"
#include "store/util/hashset_node_handle.h"

#include "context/static_context.h"
#include "context/collation_cache.h"
#include "context/internal_uri_resolvers.h"


namespace zorbatm = zorba::time;

using namespace std;

namespace zorba {
  
SERIALIZABLE_CLASS_VERSIONS(FnConcatIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnConcatIterator)

SERIALIZABLE_CLASS_VERSIONS(FnIndexOfIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnIndexOfIterator)

SERIALIZABLE_CLASS_VERSIONS(FnEmptyIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnEmptyIterator)

SERIALIZABLE_CLASS_VERSIONS(FnExistsIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnExistsIterator)

SERIALIZABLE_CLASS_VERSIONS(FnDistinctValuesIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnDistinctValuesIterator)

SERIALIZABLE_CLASS_VERSIONS(FnInsertBeforeIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnInsertBeforeIterator)

SERIALIZABLE_CLASS_VERSIONS(FnRemoveIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnRemoveIterator)

SERIALIZABLE_CLASS_VERSIONS(FnReverseIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnReverseIterator)

SERIALIZABLE_CLASS_VERSIONS(FnSubsequenceIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnSubsequenceIterator)

SERIALIZABLE_CLASS_VERSIONS(FnZeroOrOneIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnZeroOrOneIterator)

SERIALIZABLE_CLASS_VERSIONS(FnOneOrMoreIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnOneOrMoreIterator)

SERIALIZABLE_CLASS_VERSIONS(FnExactlyOneIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnExactlyOneIterator)

SERIALIZABLE_CLASS_VERSIONS(FnDeepEqualIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnDeepEqualIterator)

SERIALIZABLE_CLASS_VERSIONS(HashSemiJoinIterator)
END_SERIALIZABLE_CLASS_VERSIONS(HashSemiJoinIterator)

SERIALIZABLE_CLASS_VERSIONS(SortSemiJoinIterator)
END_SERIALIZABLE_CLASS_VERSIONS(SortSemiJoinIterator)

SERIALIZABLE_CLASS_VERSIONS(FnCountIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnCountIterator)

SERIALIZABLE_CLASS_VERSIONS(FnAvgIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnAvgIterator)

SERIALIZABLE_CLASS_VERSIONS(FnMinMaxIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnMinMaxIterator)

SERIALIZABLE_CLASS_VERSIONS(FnSumIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnSumIterator)

SERIALIZABLE_CLASS_VERSIONS(OpToIterator)
END_SERIALIZABLE_CLASS_VERSIONS(OpToIterator)

SERIALIZABLE_CLASS_VERSIONS(FnIdIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnIdIterator)

SERIALIZABLE_CLASS_VERSIONS(FnIdRefIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnIdRefIterator)

SERIALIZABLE_CLASS_VERSIONS(FnDocIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnDocIterator)

SERIALIZABLE_CLASS_VERSIONS(FnDocAvailableIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnDocAvailableIterator)

SERIALIZABLE_CLASS_VERSIONS(FnParseIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnParseIterator)


/*______________________________________________________________________
|  
| 15.1 General Functions and Operators on Sequences
|_______________________________________________________________________*/

static XQPCollator*
getCollator(
    RuntimeCB* aRuntimeCB,
    static_context* sctx,
    const QueryLoc& loc,
    PlanState& planState,
    const PlanIterator* iter)
{
  store::Item_t lCollationItem;
  store::Item_t temp;

  if (!PlanIterator::consumeNext(lCollationItem, iter, planState))
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc, "An empty sequence is not allowed as collation parameter");

  if (PlanIterator::consumeNext(temp, iter, planState))
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc, "A sequence of more then one item is not allowed as collation parameter");
    
  xqtref_t lCollationItemType = sctx->get_typemanager()->create_value_type (lCollationItem);

  return sctx->get_collation_cache()->getCollator(lCollationItem->getStringValue()->str());
}


//15.1.2 op:concatenate 
//---------------------
void
FnConcatIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
  theCurIter = 0;
}

void
FnConcatIteratorState::reset(PlanState& planState) 
{
  PlanIteratorState::reset(planState);
  theCurIter = 0;
}


bool
FnConcatIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  std::auto_ptr<store::PUL> pul;

  FnConcatIteratorState* state;
  DEFAULT_STACK_INIT(FnConcatIteratorState, state, planState);

  if (theIsUpdating)
    pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  for (; state->theCurIter < theChildren.size(); ++state->theCurIter) 
  {
    while(consumeNext(result, theChildren[state->theCurIter].getp(), planState))
    {
      if (theIsUpdating)
      {
        ZORBA_FATAL(result->isPul(), "");

        pul->mergeUpdates(result);
      }
      else
      {
        STACK_PUSH (true, state);
      }
    }
  }
  
  if (theIsUpdating) {
    result = pul.release();
    STACK_PUSH(result != NULL, state);
  }

  STACK_END (state);
}


//15.1.3 fn:index-of
bool 
FnIndexOfIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  store::Item_t lSequenceItem;
  store::Item_t lCollationItem;
  xqtref_t      lCollationItemType;
  store::Item_t searchItem;
  TypeManager* typemgr = theSctx->get_typemanager();
  long timezone = 0;

  FnIndexOfIteratorState* state;
  DEFAULT_STACK_INIT(FnIndexOfIteratorState, state, planState);
  
  if (!consumeNext(state->theSearchItem, theChildren[1].getp(), planState))
  {
    ZORBA_ERROR_LOC_DESC( FORG0006, loc, 
         "An empty sequence is not allowed as the search item of fn:index-of");    
  }

  if ( theChildren.size() == 3 )
    state->theCollator = getCollator(planState.theRuntimeCB, theSctx, loc,
                                     planState, theChildren[2].getp());

  while ( consumeNext(lSequenceItem, theChildren[0].getp(), planState))
  {
    // inc the position in the sequence; do it at the beginning of the loop because index-of starts with one
    ++state->theCurrentPos;
    
    searchItem = state->theSearchItem;
    if (CompareIterator::valueEqual(lSequenceItem,
                                    searchItem,
                                    typemgr,
                                    timezone,
                                    state->theCollator) > 0)
    {
      STACK_PUSH(GENV_ITEMFACTORY->createInteger(result,
                                                 Integer::parseInt(state->theCurrentPos)), 
                 state);
    }
  }

  STACK_END (state);
}


void
FnIndexOfIteratorState::init(PlanState& planState) 
{
 PlanIteratorState::init(planState);
 theCurrentPos = 0;
 theSearchItem = NULL;
 theCollator = 0;
}


void
FnIndexOfIteratorState::reset(PlanState& planState) {
 PlanIteratorState::reset(planState);
 theCurrentPos = 0;
 theSearchItem = NULL;
 theCollator = 0;
}


//15.1.4 fn:empty
/*
 * If the value of $arg is the empty sequence, the function returns true; 
 * otherwise, the function returns false.
 */
bool 
FnEmptyIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  store::Item_t lSequenceItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if ( !consumeNext(lSequenceItem, theChildren[0].getp(), planState))
  {
    STACK_PUSH (GENV_ITEMFACTORY->createBoolean ( result, true ), state);
  }
  else
  {
    STACK_PUSH (GENV_ITEMFACTORY->createBoolean ( result, false ), state);   
  }

  STACK_END (state);
}

//15.1.5 fn:exists
/*
 * If the value of $arg is not the empty sequence, the function returns true; 
 * otherwise, the function returns false.
 */
bool 
FnExistsIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  store::Item_t lSequenceItem;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  
  if ( consumeNext(lSequenceItem, theChildren[0].getp(), planState) ) 
  {
    STACK_PUSH (GENV_ITEMFACTORY->createBoolean ( result, true ), state);
  }
  else
  {
    STACK_PUSH (GENV_ITEMFACTORY->createBoolean ( result, false ), state);   
  }

  STACK_END (state);
}


//15.1.6 fn:distinct-values
/**
 * Returns the sequence that results from removing from arg all but one of a set of
 * values that are eq to one other. 
 * The order in which the sequence of values is returned is ·implementation dependent·.
 * Here, we return the first item that is not a duplicate and throw away the remaining ones
 */
FnDistinctValuesIterator::FnDistinctValuesIterator(short sctx, const QueryLoc& loc,
                                                   vector<PlanIter_t>& args)
 : NaryBaseIterator<FnDistinctValuesIterator, FnDistinctValuesIteratorState> ( sctx, loc, args )
{ }

FnDistinctValuesIterator::~FnDistinctValuesIterator()
{
}


bool 
FnDistinctValuesIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  store::Item_t lItem;
  xqtref_t lItemType;
  XQPCollator* lCollator;
  ValueCompareParam* theValueCompare;
  
  FnDistinctValuesIteratorState* state;
  DEFAULT_STACK_INIT(FnDistinctValuesIteratorState, state, planState);

  if (theChildren.size() == 2) 
  {
    lCollator = getCollator(planState.theRuntimeCB, theSctx, loc,
                            planState, theChildren[1].getp());

    theValueCompare = new ValueCompareParam(planState.theRuntimeCB, theSctx);
    theValueCompare->theCollator = lCollator;
  }
  else
  {
    theValueCompare = new ValueCompareParam(planState.theRuntimeCB, theSctx);
  }
  // theValueCompare managed by state->theAlreadySeenMap
  state->theAlreadySeenMap.reset (new ItemValueCollHandleHashSet (theValueCompare));

  while (consumeNext(result, theChildren[0].getp(), planState)) 
  {
    if (result->isNaN ()) {
      if (! state->theHasNaN) {
        state->theHasNaN = true;
        STACK_PUSH(true, state);
      }
    } else if ( ! state->theAlreadySeenMap->find(result) ) {
      // check if the item is already in the map
      state->theAlreadySeenMap->insert(result);
      STACK_PUSH(true, state);
    }
  }
    
  STACK_END (state);
}


FnDistinctValuesIteratorState::FnDistinctValuesIteratorState()
  :
  theHasNaN (false),
  theAlreadySeenMap(0)
{
}


FnDistinctValuesIteratorState::~FnDistinctValuesIteratorState() 
{
}


void
FnDistinctValuesIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
}


void
FnDistinctValuesIteratorState::reset(PlanState& planState) 
{
  PlanIteratorState::reset(planState);
  theHasNaN = false;
  if (theAlreadySeenMap.get () != NULL)
    theAlreadySeenMap->clear();
}


//15.1.7 fn:insert-before
bool 
FnInsertBeforeIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
 store::Item_t lInsertItem;
 store::Item_t lPositionItem;
 
 FnInsertBeforeIteratorState* state;
 DEFAULT_STACK_INIT(FnInsertBeforeIteratorState, state, planState);
 
 if (!consumeNext(lPositionItem, theChildren[1].getp(), planState))
 {
   // raise error
 }

 state->thePosition = lPositionItem->getIntegerValue();
 if (state->thePosition < xqp_integer::parseInt(1))
   state->thePosition = xqp_integer::parseInt(1);
   
  
 while (consumeNext(result, theChildren[0].getp(), planState))
 {
    if ( state->theCurrentPos == state->thePosition-xqp_integer::parseInt(1) ) // position found => insert sequence
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

void
FnInsertBeforeIteratorState::init(PlanState& planState) {
 PlanIteratorState::init(planState);
 theCurrentPos = xqp_integer::parseInt(0);
 thePosition = xqp_integer::parseInt(0);
 theTargetItem = NULL;
}

void
FnInsertBeforeIteratorState::reset(PlanState& planState) {
 PlanIteratorState::reset(planState);
 theCurrentPos = xqp_integer::parseInt(0);
 thePosition = xqp_integer::parseInt(0); 
 theTargetItem = NULL;
}


//15.1.8 fn:remove
bool 
FnRemoveIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  store::Item_t lSequenceItem;
  store::Item_t lPositionItem;
  store::Item_t lCollationItem;
  xqtref_t      lCollationItemType;

  FnRemoveIteratorState* state;
  DEFAULT_STACK_INIT(FnRemoveIteratorState, state, planState);
  
  if (!consumeNext(lPositionItem, theChildren[1].getp(), planState))
  {
    ZORBA_ERROR_LOC_DESC( FORG0006,
         loc, "An empty sequence is not allowed as second argument to of fn:remove.");
  }
  state->thePosition = lPositionItem->getIntegerValue();

  if ( theChildren.size() == 3 )
    state->theCollator = getCollator(planState.theRuntimeCB, theSctx, loc,
                                     planState, theChildren[2].getp());

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

void
FnRemoveIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
  theCurrentPos = xqp_integer::parseInt(0);
  thePosition   = xqp_integer::parseInt(0);
  theCollator = 0;
}

void
FnRemoveIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurrentPos = xqp_integer::parseInt(0);
  thePosition = xqp_integer::parseInt(0);
  theCollator = 0;
}


//15.1.9 fn:reverse
bool FnReverseIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t iVal;

  FnReverseIteratorState *state;
  DEFAULT_STACK_INIT(FnReverseIteratorState, state, planState);

  while(consumeNext(iVal, theChildren[0].getp(), planState)) {
    state->theStack.push(iVal);
  }

  while(!state->theStack.empty()) {
    result = state->theStack.top();
    state->theStack.pop();
    STACK_PUSH(true, state);
  }

  STACK_END (state);
}

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

//15.1.10 fn:subsequence
bool FnSubsequenceIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  store::Item_t startPosItem;
  xqp_integer startPos;
  store::Item_t lengthItem;
  xqp_integer zero = xqp_integer::parseInt (0);
  xqp_integer minus_one = xqp_integer::parseInt (-1);

  FnSubsequenceIteratorState* state;
  DEFAULT_STACK_INIT(FnSubsequenceIteratorState, state, planState);
  
  CONSUME(startPosItem, 1);
  xqp_integer::parseDouble(startPosItem->getDoubleValue().round(), startPos);
  startPos += minus_one;
  
  if (theChildren.size() == 3) 
  {
    CONSUME(lengthItem, 2);
    xqp_integer::parseDouble(lengthItem->getDoubleValue().round(),
                             state->theRemaining);
  }

  if (startPos < zero)
  {
    if (theChildren.size() >= 3)
      state->theRemaining += startPos;

    startPos = zero;
  }

  // If a length is specified and it is <= 0, return the empty sequence
  if (theChildren.size() == 3 && state->theRemaining <= zero)
    goto done;

  // Consume and skip all input items that are before the startPos
  for (; startPos > zero; --startPos)
  {
    if (!CONSUME(result, 0))
      goto done;
  }

  while ((theChildren.size() < 3 || state->theRemaining > xqp_integer::parseInt(0)) &&
         CONSUME(result, 0))
  {
    if (theChildren.size () >= 3)
      state->theRemaining--;

    STACK_PUSH (true, state);
  }

done:
  theChildren[0]->reset(planState);

  STACK_END (state);
}

void
FnSubsequenceIteratorState::init(PlanState& planState) 
{
 PlanIteratorState::init(planState);
}

void
FnSubsequenceIteratorState::reset(PlanState& planState) 
{
 PlanIteratorState::reset(planState);
}


//15.1.11 fn:unordered


/*______________________________________________________________________
|  
| 15.2 Functions That Test the Cardinality of Sequences
|_______________________________________________________________________*/

//15.2.1 fn:zero-or-one
bool 
FnZeroOrOneIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  store::Item_t lFirstSequenceItem;
  store::Item_t lNextSequenceItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState))
  {
    if (consumeNext(lNextSequenceItem, theChildren[0].getp(), planState))
    {
      ZORBA_ERROR_LOC_DESC( FORG0003, 
        loc,  "fn:zero-or-one called with a sequence containing more than one item.");
    }
    STACK_PUSH(true, state);
  }
  STACK_END (state);
}



//15.2.2 fn:one-or-more
bool 
FnOneOrMoreIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(result, theChildren[0].getp(), planState))
  {
    ZORBA_ERROR_LOC_DESC( FORG0004,
        loc,  "fn:one-or-more called with a sequence containing no items.");
  }
  do
  {
    STACK_PUSH(true, state);
  } while (consumeNext(result, theChildren[0].getp(), planState));

  STACK_END (state);
}

//15.2.3 fn:exactly-one
bool 
FnExactlyOneIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  store::Item_t lNextItem;
  bool firstPresent = false;
  bool nextPresent = false;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if ((firstPresent = consumeNext(result, theChildren[0].getp(), planState)))
    nextPresent = consumeNext(lNextItem, theChildren[0].getp(), planState);

  if (firstPresent && !nextPresent) 
  {
    if (!raise_err) {
      GENV_ITEMFACTORY->createBoolean (result, true);
    }
  }
  else 
  {
    if (raise_err)
      ZORBA_ERROR_LOC_DESC( FORG0005,
                            loc, "fn:exactly-one called with a sequence containing zero or more than one item.");
    else
      GENV_ITEMFACTORY->createBoolean (result, false );
  }
  STACK_PUSH(true, state);

  STACK_END (state);
}


/*______________________________________________________________________
|
| 15.3 Equals, Union, Intersection and Except
|_______________________________________________________________________*/

//15.3.1 fn:deep-equal
bool DeepEqual(
    static_context* sctx,
    store::Item_t& item1,
    store::Item_t& item2,
    XQPCollator* collator,
    RuntimeCB* theRuntimeCB);

bool DeepEqual(
    static_context* sctx,
    store::Iterator_t it1,
    store::Iterator_t it2,
    XQPCollator* collator,
    RuntimeCB* theRuntimeCB)
{
  store::Item_t child1, child2;
  bool c1Valid, c2Valid;
  
  it1->open();
  it2->open();

  while (1)
  {
    c1Valid = it1->next(child1);
    c2Valid = it2->next(child2);

    if (!c1Valid && !c2Valid)
      return true;
    else if (!c1Valid || !c2Valid)
      return false;
    else if (!DeepEqual(sctx, child1, child2, collator, theRuntimeCB))
      return false;
  }
    
  return true;
}


bool DeepEqual(
    static_context* sctx,
    store::Item_t& item1,
    store::Item_t& item2,
    XQPCollator* collator,
    RuntimeCB* theRuntimeCB)
{
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  if (item1.isNull() && item2.isNull())
    return true;

  if (item1 == NULL || item2 == NULL)
    return false;

  if (item1->isNode() != item2->isNode())
    return false;
  
  if (item1->isAtomic())
  {
    assert(item2->isAtomic());
    TypeManager* typemgr = sctx->get_typemanager();
    long timezone = theRuntimeCB->theDynamicContext->get_implicit_timezone();

    if (collator == NULL)
      collator = sctx->get_collation_cache()->getDefaultCollator();

    // check NaN
    xqtref_t type1 = typemgr->create_value_type(item1.getp());
    xqtref_t type2 = typemgr->create_value_type(item2.getp());
    
    if (((TypeOps::is_subtype(*type1, *rtm.FLOAT_TYPE_ONE)
          &&
          item1->getFloatValue().isNaN())
          ||
          (TypeOps::is_subtype(*type1, *rtm.DOUBLE_TYPE_ONE)
          &&
          item1->getDoubleValue().isNaN()))
          &&
          ((TypeOps::is_subtype(*type2, *rtm.FLOAT_TYPE_ONE)
          &&
          item2->getFloatValue().isNaN())
          ||
          (TypeOps::is_subtype(*type2, *rtm.DOUBLE_TYPE_ONE)
          &&
          item2->getDoubleValue().isNaN())))
      return true;
    
    return CompareIterator::valueEqual(item1, item2, typemgr, timezone, collator) > 0;
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
        ZORBA_ASSERT(false);  // case not treated
        break;
        
      case store::StoreConsts::elementNode:
        if (0 != item1->getNodeName()->getStringValue()->compare(item2->getNodeName()->getStringValue(), collator))
          return false;
        return DeepEqual(sctx, item1->getAttributes(), item2->getAttributes(), collator, theRuntimeCB)
            &&
            DeepEqual(sctx, item1->getChildren(), item2->getChildren(), collator, theRuntimeCB);
        break;
        
      case store::StoreConsts::attributeNode:
      {
        if (0 != item1->getNodeName()->getStringValue()->compare(item2->getNodeName()->getStringValue(), collator))
          return false;

        store::Item_t tvalue1, tvalue2;
        store::Iterator_t tvalue1Iter, tvalue2Iter;
        item1->getTypedValue(tvalue1, tvalue1Iter);
        item2->getTypedValue(tvalue2, tvalue2Iter);

        if (tvalue1Iter == NULL && tvalue2Iter == NULL)
          return DeepEqual(sctx, tvalue1, tvalue2, collator, theRuntimeCB);
        else if (tvalue1Iter != NULL && tvalue2Iter != NULL)
          return DeepEqual(sctx, tvalue1Iter, tvalue2Iter, collator, theRuntimeCB);
        else
          return false;

        break;
      }  
      case store::StoreConsts::textNode:     /* deliberate fall-through */
      case store::StoreConsts::commentNode:
        return (0 == item1->getStringValue()->compare(item2->getStringValue(), collator));
        break;
        
      case store::StoreConsts::piNode:
        if (0 != item1->getNodeName()->getStringValue()->compare(item2->getNodeName()->getStringValue(), collator))
          return false;
        return (0 == item1->getStringValue()->compare(item2->getStringValue(), collator));
        break;
    }
    
    ZORBA_ASSERT(false);  // should never reach here
    return false;
  }
}

bool 
FnDeepEqualIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  store::Item_t arg1, arg2;
  XQPCollator* collator = NULL;
  bool equal = true;
  
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if ( theChildren.size() == 3 )
  {
    collator = getCollator(planState.theRuntimeCB, theSctx, loc,
                           planState, theChildren[2].getp());
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

    equal = equal && DeepEqual(theSctx, arg1, arg2, collator, planState.theRuntimeCB);
  }
  
  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, equal), state);

  STACK_END (state);
}

//15.3.2 op:union
// see header file

//15.3.3 op:intersect
//15.3.4 op:except
HashSemiJoinIteratorState::HashSemiJoinIteratorState() {
  theRightInput = new store::NodeHashSet();
}

HashSemiJoinIteratorState::~HashSemiJoinIteratorState() {
  delete theRightInput;
  theRightInput = 0;
}

void
HashSemiJoinIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void
HashSemiJoinIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}

HashSemiJoinIterator::HashSemiJoinIterator(short sctx,
                                   const QueryLoc& loc,
                                   std::vector<PlanIter_t>& args,
                                   bool antijoin)
 : NaryBaseIterator<HashSemiJoinIterator, HashSemiJoinIteratorState> ( sctx, loc, args ),
   theAntijoin(antijoin)
{
}

HashSemiJoinIterator::~HashSemiJoinIterator() {}

bool 
HashSemiJoinIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  store::Item_t lItem;
  bool not_found;

  HashSemiJoinIteratorState* state;
  DEFAULT_STACK_INIT(HashSemiJoinIteratorState, state, planState);

  // eat the complete right-hand side and hash it
  while ( consumeNext(lItem, theChildren[1].getp(), planState)) {
    state->theRightInput->insert(lItem);
  }
  

  while (consumeNext(result, theChildren[0].getp(), planState)) {
    not_found = ! state->theRightInput->find(result);
    if (not_found == theAntijoin)
      STACK_PUSH(true, state);
  }

  STACK_END (state);
}

// sort-merge semi-join
SortSemiJoinIterator::SortSemiJoinIterator(short sctx,
                                   const QueryLoc& loc,
                                   std::vector<PlanIter_t>& args)
 : NaryBaseIterator<SortSemiJoinIterator, PlanIteratorState> ( sctx, loc, args )
{
}

SortSemiJoinIterator::~SortSemiJoinIterator() {}

bool 
SortSemiJoinIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  store::Item_t item [2];
  short order;
  int i;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);


  for (;;) {

    // load items
    for (i = 0; i < 2; i++) {
      if (item [i] == NULL) {
        if (!CONSUME (item[i], i)) {
          item[i] = NULL;
          goto done;
        }
      }
    }

    // advance, output
    order = GENV_STORE.compareNodes (item [0].getp(), item [1].getp());
    if ( order == 0 ) {
      result = item[0];
      STACK_PUSH (true, state);
    }
    else item [(order < 0) ? 0 : 1] = NULL;

  }

done:
  STACK_END (state);
}

/*______________________________________________________________________
|
| 15.4 Aggregate Functions
|_______________________________________________________________________*/

//15.4.1 fn:count
bool 
FnCountIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  store::Item_t lSequenceItem;
  xqp_integer lCount = Integer::parseInt(0);

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (consumeNext(lSequenceItem, theChildren[0].getp(), planState))
  {
    ++lCount;
  }

  STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, lCount), state);

  STACK_END (state);
}

//15.4.2 fn:avg
bool FnAvgIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  store::Item_t lSumItem;
  store::Item_t lRunningItem;
  xqtref_t      lRunningType;
  store::Item_t countItem;
  int lCount = 0;
  bool lHitNumeric = false, lHitYearMonth = false, lHitDayTime = false;

  const TypeManager& tm = *theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t lUntypedAtomic     = rtm.UNTYPED_ATOMIC_TYPE_ONE; 
  xqtref_t lYearMonthDuration = rtm.YM_DURATION_TYPE_ONE; 
  xqtref_t lDayTimeDuration   = rtm.DT_DURATION_TYPE_ONE;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (consumeNext(lRunningItem, theChildren[0].getp(), planState)) 
  {  
    lRunningType = tm.create_value_type(lRunningItem);

    if (TypeOps::is_numeric(*lRunningType) ||
        TypeOps::is_equal(*lRunningType, *lUntypedAtomic)) 
    {
      lHitNumeric = true;
      if ( lHitYearMonth )
        ZORBA_ERROR_LOC_DESC_OSS(FORG0006, loc,
                                 "Invalid argument type " << lRunningType->toString()
                                 << " for function fn:avg. Expected type "
                                 << lYearMonthDuration->toString() << ".");
      if ( lHitDayTime ) 
        ZORBA_ERROR_LOC_DESC_OSS(FORG0006, loc,
                                 "Invalid argument type " << lRunningType->toString() 
                                 << " for function fn:avg. Expected type " 
                                 << lDayTimeDuration->toString() << ".");

    }
    else if (TypeOps::is_equal (*lRunningType, *lYearMonthDuration)) 
    {
      lHitYearMonth = true;
      if ( lHitNumeric )
        ZORBA_ERROR_LOC_DESC_OSS(FORG0006, loc,
                                 "Invalid argument type " << lRunningType->toString() 
                                 << " for function fn:avg. Expected a numeric type.");
      if ( lHitDayTime ) 
        ZORBA_ERROR_LOC_DESC_OSS(FORG0006, loc,
                                 "Invalid argument type " << lRunningType->toString() 
                                 << " for function fn:avg. Expected type " 
                                 << lDayTimeDuration->toString() << ".");

    }
    else if (TypeOps::is_equal (*lRunningType, *lDayTimeDuration))
    {
      lHitDayTime = true;
      if ( lHitNumeric )
        ZORBA_ERROR_LOC_DESC_OSS(FORG0006, loc,
                                 "Invalid argument type " << lRunningType->toString() 
                                 << " for function fn:avg. Expected a numeric type.");
      if ( lHitYearMonth )
        ZORBA_ERROR_LOC_DESC_OSS(FORG0006, loc,
                                 "Invalid argument type " << lRunningType->toString() 
                                 << " for function fn:avg. Expected type " 
                                 << lYearMonthDuration->toString() << ".");
    }
    else
    {
      ZORBA_ERROR_LOC_DESC(FORG0006, loc,
                           "The fn:avg function only accepts numeric or duration types.");
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
                                                  planState.theRuntimeCB,
                                                  &tm,
                                                  loc,
                                                  lSumItem,
                                                  lRunningItem);
    }
  }

  if (lCount > 0) 
  {
    GENV_ITEMFACTORY->createInteger(countItem, Integer::parseInt (lCount));
    GenericArithIterator<DivideOperation>::compute(result,
                                                   planState.theRuntimeCB,
                                                   &tm,
                                                   loc,
                                                   lSumItem,
                                                   countItem);

    STACK_PUSH(true, state);
  }
  // else return empty sequence

  STACK_END (state);
}

//15.4.3 fn:max & 15.4.4 fn:min
FnMinMaxIterator::FnMinMaxIterator
  (short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& aChildren, Type aType)
  : NaryBaseIterator<FnMinMaxIterator, PlanIteratorState>(sctx, loc, aChildren), 
    theType(aType),
    theCompareType(
       (aType == MIN 
       ? CompareConsts::VALUE_LESS 
       : CompareConsts::VALUE_GREATER)) 
{ 
}


bool 
FnMinMaxIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  store::Item_t lRunningItem = NULL;
  xqtref_t lMaxType;

  const TypeManager& tm = *theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  long timezone = planState.theRuntimeCB->theDynamicContext->get_implicit_timezone();
  XQPCollator*  lCollator = 0;
  bool  elems_in_seq = 0;
  result = NULL;

  try
  {
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (theChildren.size() == 2)
    lCollator = getCollator(planState.theRuntimeCB, theSctx, loc,
                            planState, theChildren[1].getp());
  else
    lCollator = theSctx->get_collation_cache()->getDefaultCollator();

  if (consumeNext(lRunningItem, theChildren[0].getp(), planState))
  {
    do 
    {
      // casting of untyped atomic
      xqtref_t lRunningType = tm.create_value_type(lRunningItem);

      if (TypeOps::is_subtype(*lRunningType, *rtm.UNTYPED_ATOMIC_TYPE_ONE)) 
      {
        GenericCast::castToAtomic(lRunningItem, lRunningItem, &*rtm.DOUBLE_TYPE_ONE, tm);
        lRunningType = rtm.DOUBLE_TYPE_ONE;
      }

      // implementation dependent: return the first occurence)
      if (lRunningItem->isNaN()) 
      {
        /** It must be checked if the sequence contains any 
         * xs:double("NaN") [xs:double("NaN") is returned] or 
         * only xs:float("NaN")'s [xs:float("NaN") is returned]'.
         */
        result = lRunningItem;
        if (TypeOps::is_subtype(*lRunningType, *rtm.DOUBLE_TYPE_ONE))
          break;

        lMaxType = tm.create_value_type (result);
      }

      if (result != 0) 
      {
        // Type Promotion
        store::Item_t lItemCur;
        if (!GenericCast::promote(lItemCur, lRunningItem, &*lMaxType, tm)) 
        {
          if (GenericCast::promote(lItemCur, result, &*lRunningType, tm))
          {
            result.transfer(lItemCur);
            lMaxType = tm.create_value_type(result);
          } 
          else 
          {
            ZORBA_ERROR_LOC_DESC( FORG0006, loc,  "Promotion not possible");
          }
        }
        else 
        {
          lRunningItem.transfer(lItemCur);
          lRunningType = tm.create_value_type(lRunningItem);
        }

        store::Item_t current_copy(lRunningItem);
        store::Item_t max_copy(result);
        if (CompareIterator::valueComparison(loc,
                                             current_copy,
                                             max_copy,
                                             theCompareType,
                                             &tm,
                                             timezone,
                                             lCollator) ) 
        {
          lMaxType = lRunningType;
          result.transfer(lRunningItem);
        }
      }
      else 
      {
        lMaxType = lRunningType;
        result.transfer(lRunningItem);
      }

      elems_in_seq++;
    } while (consumeNext(lRunningItem, theChildren[0].getp(), planState));
    
    if(elems_in_seq == 1)
    {
      //check type compatibility
      store::Item_t dummy1(result);
      store::Item_t dummy2(result);
      CompareIterator::valueComparison(loc,
                                       dummy1,
                                       dummy2,
                                       theCompareType,
                                       &tm,
                                       timezone,
                                       lCollator);
    }

    STACK_PUSH(result != NULL, state);
  } // if non-empty seq

  STACK_END (state);
  
  }
  catch(error::ZorbaError &e)
  {
    if(e.localName() == "XPTY0004")
    {
      ZORBA_ERROR_LOC(FORG0006, loc);
    }
    throw;
  }
}


//15.4.5 fn:sum
bool FnSumIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  store::Item_t lRunningItem;
  xqtref_t      lResultType, lRunningType;

  const TypeManager& tm = *theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState)) 
  {
    // casting of untyped atomic
    lResultType = tm.create_value_type(result);

    if (TypeOps::is_subtype(*lResultType, *rtm.UNTYPED_ATOMIC_TYPE_ONE)) 
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm);
      lResultType = rtm.DOUBLE_TYPE_ONE;
    }

    if (!TypeOps::is_numeric(*lResultType) &&
        !TypeOps::is_subtype(*lResultType, *rtm.DURATION_TYPE_ONE))
      ZORBA_ERROR_LOC( FORG0006, loc );
    
    while (consumeNext(lRunningItem, theChildren[0].getp(), planState)) 
    {
      // casting of untyped atomic
      lRunningType = tm.create_value_type(lRunningItem);

      if (TypeOps::is_subtype(*lRunningType, *rtm.UNTYPED_ATOMIC_TYPE_ONE)) 
      {
        GenericCast::castToAtomic(lRunningItem, lRunningItem, &*rtm.DOUBLE_TYPE_ONE, tm);
        lRunningType = rtm.DOUBLE_TYPE_ONE;
      }

      // handling of NaN
      if (lRunningItem->isNaN()) {
         result = lRunningItem;
        break;
      }

      if((TypeOps::is_numeric(*lResultType) &&
          TypeOps::is_numeric(*lRunningType)) ||
         (TypeOps::is_subtype(*lResultType, *rtm.YM_DURATION_TYPE_ONE) &&
          TypeOps::is_subtype(*lRunningType, *rtm.YM_DURATION_TYPE_ONE)) ||
         (TypeOps::is_subtype(*lResultType, *rtm.DT_DURATION_TYPE_ONE) &&
          TypeOps::is_subtype(*lRunningType, *rtm.DT_DURATION_TYPE_ONE)))
        GenericArithIterator<AddOperation>::compute(result,
                                                    planState.theRuntimeCB,
                                                    &tm,
                                                    loc,
                                                    result,
                                                    lRunningItem);
      else
        ZORBA_ERROR_LOC_DESC( FORG0006, loc, "Sum is not possible with parameters of type " + TypeOps::toString (*lResultType) + " and " + TypeOps::toString (*lRunningType) );
    }

    STACK_PUSH(true, state);
  } else {
    if (theChildren.size() == 2)
    {
      if (consumeNext(result, theChildren[1].getp(), planState))
      {
        STACK_PUSH(true, state);
      }
      // return the empty sequence otherwise
    } else {
      STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, Integer::parseInt((int32_t)0)), state);
    }
  }

  STACK_END (state);
}


/*______________________________________________________________________
|
| 15.5 Functions and Operators that Generate Sequences
|_______________________________________________________________________*/

//15.5.1 op:to
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

void
OpToIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theCurInt = xqp_integer::parseInt(0);
  theFirstVal = xqp_integer::parseInt(0);
  theLastVal = xqp_integer::parseInt(0);
}

void
OpToIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurInt = xqp_integer::parseInt(0);
  theFirstVal = xqp_integer::parseInt(0);
  theLastVal = xqp_integer::parseInt(0);
}


/*******************************************************************************
  15.5.2 fn:id
********************************************************************************/
void FnIdIteratorState::init(PlanState& planState)
{
  DescendantAxisState::init(planState);
  theIsInitialized = false;
  theAttrsIte = GENV_ITERATOR_FACTORY->createAttributesIterator();
  assert(theIds.empty());
  assert(theDocNode == NULL);
}


void FnIdIteratorState::reset(PlanState& planState)
{
  DescendantAxisState::reset(planState);
  theIsInitialized = false;
  theIds.clear();
  theDocNode = NULL;
}


bool FnIdIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  store::Item_t  id;
  store::Item*   child;
  store::Item*   attr;
  store::Item_t  tmp;
  bool           isMatchingId;
  ulong i;

  FnIdIteratorState *state;
  DEFAULT_STACK_INIT(FnIdIteratorState, state, planState);

  if (!state->theIsInitialized)
  {
    while (consumeNext(id, theChildren[0], planState))
    {
      state->theIds.push_back(id->getStringValue());
    }

    if(!consumeNext(state->theDocNode, theChildren[1], planState))
    {
      ZORBA_ERROR_LOC_DESC(FODC0001, loc,
                           "No target document for fn:id function");
    }

    while (state->theDocNode->getParent() != NULL)
    {
      state->theDocNode = state->theDocNode->getParent();
    }

    if (state->theDocNode->getNodeKind() != store::StoreConsts::documentNode)
    {
      ZORBA_ERROR_LOC_DESC(FODC0001, loc,
                           "No target document for fn:id function");
    }

    state->push(state->theDocNode);

    state->theIsInitialized = true;
  }

  while (true)
  {
    while ((child = state->top()->next()) == NULL)
    {
      state->pop();
      if (state->empty())
        break;
    }

    if (child == NULL)
      break;

    if (child->getNodeKind() != store::StoreConsts::elementNode)
      continue;

    tmp = child;
    state->push(tmp);

    isMatchingId = false;

    if (child->isId())
    {
      for (i = 0; i < state->theIds.size(); ++i)
      {
        if (child->getStringValue()->equals(state->theIds[i]))
        {
          result = child;
          STACK_PUSH(true, state);
          isMatchingId = true;
          break;
        }
      }
    }
    else
    {
      tmp = child;
      state->theAttrsIte->init(tmp);
      state->theAttrsIte->open();

      attr = state->theAttrsIte->next();

      while (attr != NULL)
      {
        if (attr->isId())
        {
          for (i = 0; i < state->theIds.size(); ++i)
          {
            if (attr->getStringValue()->equals(state->theIds[i]))
            {
              result = child;
              STACK_PUSH(true, state);
              isMatchingId = true;
              break;
            }
          }
        }

        if (isMatchingId)
          break;

        attr = state->theAttrsIte->next();
      }

      state->theAttrsIte->close();
    }
  }

  STACK_END (state);
}
  

/*******************************************************************************
  15.5.3 fn:idref
********************************************************************************/
void FnIdRefIteratorState::init(PlanState& planState)
{
  DescendantAxisState::init(planState);
  theIsInitialized = false;
  theAttrsIte = GENV_ITERATOR_FACTORY->createAttributesIterator();
  assert(theIds.empty());
  assert(theDocNode == NULL);
}


void FnIdRefIteratorState::reset(PlanState& planState)
{
  DescendantAxisState::reset(planState);
  theIsInitialized = false;
  theIds.clear();
  theDocNode = NULL;
}


bool FnIdRefIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  store::Item_t     id;
  store::Item*      child = NULL;
  store::Item*      attr = NULL;
  store::Item_t     tmp;
  store::Item_t     typedValue;
  store::Iterator_t typedValueIte;

  bool           isMatchingId;
  ulong          i;

  std::vector<xqpStringStore_t> idrefs;

  FnIdRefIteratorState* state;
  DEFAULT_STACK_INIT(FnIdRefIteratorState, state, planState);

  if (!state->theIsInitialized)
  {
    while (consumeNext(id, theChildren[0], planState))
    {
      state->theIds.push_back(id->getStringValue());
    }

    if(!consumeNext(state->theDocNode, theChildren[1], planState))
    {
      ZORBA_ERROR_LOC_DESC(FODC0001, loc,
                           "No target document for fn:idref function");
    }

    while (state->theDocNode->getParent() != NULL)
    {
      state->theDocNode = state->theDocNode->getParent();
    }

    if (state->theDocNode->getNodeKind() != store::StoreConsts::documentNode)
    {
      ZORBA_ERROR_LOC_DESC(FODC0001, loc,
                           "No target document for fn:idref function");
    }

    state->push(state->theDocNode);

    state->theIsInitialized = true;
  }


  while (true)
  {
    while ((child = state->top()->next()) == NULL)
    {
      state->pop();
      if (state->empty())
        break;
    }

    if (child == NULL)
      break;

    if (child->getNodeKind() != store::StoreConsts::elementNode)
      continue;

    tmp = child;
    state->push(tmp);

    if (child->isIdRefs())
    {
      isMatchingId = false;

      child->getTypedValue(typedValue, typedValueIte);

      for (i = 0; i < state->theIds.size(); ++i)
      {
        if (typedValue != NULL)
        {
          if (typedValue->getStringValue()->equals(state->theIds[i]))
          {
            result = child;
            STACK_PUSH(true, state);
            isMatchingId = true;
            break;
          }
        }
        else if (typedValueIte != NULL)
        {
          typedValueIte->open();

          while(typedValueIte->next(typedValue))
          {
            if (typedValue->getStringValue()->equals(state->theIds[i]))
            {
              isMatchingId = true;
              result = child;
              break;
            }
          }

          typedValueIte->close();

          if (isMatchingId)
          {
            STACK_PUSH(true, state);
            break;
          }
        }
      }
    }

    tmp = state->topNode();
    state->theAttrsIte->init(tmp);
    state->theAttrsIte->open();

    attr = state->theAttrsIte->next();

    while (attr != NULL)
    {
      if (attr->isIdRefs())
      {
        isMatchingId = false;

        attr->getTypedValue(typedValue, typedValueIte);

        for (i = 0; i < state->theIds.size(); ++i)
        {
          if (typedValue != NULL)
          {
            if (typedValue->getStringValue()->equals(state->theIds[i]))
            {
              result = attr;
              STACK_PUSH(true, state);
              isMatchingId = true;
              break;
            }
          }
          else if (typedValueIte != NULL)
          {
            typedValueIte->open();

            while(typedValueIte->next(typedValue))
            {
              if (typedValue->getStringValue()->equals(state->theIds[i]))
              {
                isMatchingId = true;
                result = attr;
                break;
              }
            }
            
            typedValueIte->close();

            if (isMatchingId)
            {
              STACK_PUSH(true, state);
              break;
            }
          }
        }
      }

      attr = state->theAttrsIte->next();
    }

    state->theAttrsIte->close();
  }

  STACK_END (state);
}


/*______________________________________________________________________
| 15.5.4 fn:doc
|
|   fn:doc($uri as xs:string?) as document-node()?
| 
| Summary: Retrieves a document using an xs:anyURI, which may include a 
| fragment identifier, supplied as an xs:string. If $uri is not a valid 
| xs:anyURI, an error is raised [err:FODC0005]. If it is a relative URI 
| Reference, it is resolved relative to the value of the base URI 
| property from the static context. The resulting absolute URI Reference 
| is promoted to an xs:string. If the Available documents discussed in 
| Section 2.1.2 Dynamic ContextXP provides a mapping from this string to 
| a document node, the function returns that document node. If the 
| Available documents maps the string to an empty sequence, then the 
| function returns an empty sequence. If the Available documents 
| provides no mapping for the string, an error is raised [err:FODC0005]. 
| 
| If $uri is the empty sequence, the result is an empty sequence.
|_______________________________________________________________________*/

FnDocIterator::FnDocIterator( short sctx, const QueryLoc& loc, PlanIter_t& arg)
  :
  UnaryBaseIterator<FnDocIterator, PlanIteratorState> ( sctx, loc, arg )
{
}


FnDocIterator::~FnDocIterator()
{
}

static void fillTime (
    const zorba::DateTime& t0,
    const zorbatm::timeinfo& t0user,
    RuntimeCB *runtimeCB) 
{
  zorba::DateTime   t1;
  zorbatm::timeinfo t1user;

  zorba::DateTime::getLocalTime(t1);
  zorbatm::get_timeinfo (t1user);

  std::auto_ptr<zorba::Duration> diffTime;
  diffTime.reset(t1.subtractDateTime(&t0, 0));
  runtimeCB->docLoadingTime += diffTime->getTotalMilliseconds();

  runtimeCB->docLoadingUserTime +=
    zorbatm::get_time_elapsed (zorbatm::extract_user_time_detail (t0user),
                               zorbatm::extract_user_time_detail (t1user));
}


bool FnDocIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     uriItem;
  xqpString         uriString;
  xqpStringStore_t  resolvedURIString;
  store::Item_t     resolvedURIItem;
  RuntimeCB        *runtimeCB;
  zorba::DateTime   t0;
  zorbatm::timeinfo t0user;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  runtimeCB = planState.theRuntimeCB;
  if (consumeNext(uriItem, theChild.getp(), planState)) {

    uriString = uriItem->getStringValueP();

    try {
      // maybe the document is stored with the uri that is given by the user
      result = GENV_STORE.getDocument(uriString.getStore());
    } catch (error::ZorbaError& e) {
      ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
    }

    if (result != NULL) 
    {
      fillTime (t0, t0user, runtimeCB);
      STACK_PUSH(true, state);
    }
    else 
    {
      try 
      {
        resolvedURIString = theSctx->resolve_relative_uri(uriString, xqp_string(), false).getStore();
        GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
      }
      catch (error::ZorbaError& e) 
      {
        ZORBA_ERROR_LOC_DESC(FODC0005, loc, e.theDescription);
      }

      try 
      {
        zorba::DateTime::getLocalTime(t0);
        zorbatm::get_timeinfo (t0user);

        result = theSctx->get_document_uri_resolver()->resolve(resolvedURIItem, 
                                                               theSctx,
                                                               false,
                                                               false);
        fillTime(t0, t0user, runtimeCB);
      } 
      catch (error::ZorbaError& e) 
      {
        ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
      }

      STACK_PUSH(true, state);
    }

  } // return empty sequence if input is the empty sequence
  STACK_END (state);
}

bool FnParseIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Store& lStore = GENV.getStore();
  xqpString         docString;
  xqpStringStore_t  tmpString(new xqpStringStore(""));
  std::auto_ptr<std::istringstream> iss;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  consumeNext (result, theChildren [0].getp (), planState);
  docString = result->getStringValueP ();
  iss.reset (new std::istringstream (docString.c_str()));
  try {
    result = lStore.loadDocument(tmpString, *iss, false);
  } catch (error::ZorbaError& e) {
    ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
  }
  STACK_PUSH(true, state);
  STACK_END (state);

}

/*______________________________________________________________________
| 15.5.5 fn:doc-available
|
|   fn:doc-available($uri as xs:string?) as xs:boolean
|_______________________________________________________________________*/
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
      doc = theSctx->get_document_uri_resolver()->resolve(uriItem,
                                                          theSctx,
                                                          false,
                                                          false);
    }
    catch (error::ZorbaError& e) 
    {
      if (e.theErrorCode == FODC0005) 
      {
        ZORBA_ERROR_LOC_DESC(FODC0005, loc, e.theDescription);
      }
      // other errors fall through and make the function return false
    }
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, doc != NULL), state);
  }

  STACK_END (state);
}


} /* namespace zorba */
/* vim:set ts=2 sw=2: */
