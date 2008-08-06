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

#include "runtime/sequences/SequencesImpl.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/numerics/NumericsImpl.h"
#include "runtime/api/runtimecb.h"
#include "runtime/core/arithmetic_impl.h"
#include "runtime/util/iterator_impl.h"

#include "system/globalenv.h"

#include "types/casting.h"
#include "types/typeops.h"
#include "store/api/store.h"
#include "store/api/iterator.h"
#include "store/api/item_factory.h"
#include "store/api/pul.h"

#include "context/static_context.h"
#include "context/collation_cache.h"
#include "context/internal_uri_resolvers.h"

#include "store/util/hashset_node_handle.h"

#include "runtime/booleans/compare_types.h"
#include "runtime/util/handle_hashset_item_value.h"

using namespace std;
namespace zorba {
  

/*______________________________________________________________________
|  
| 15.1 General Functions and Operators on Sequences
|_______________________________________________________________________*/

static XQPCollator*
getCollator(
    RuntimeCB* aRuntimeCB,
    const QueryLoc& loc,
    PlanState& planState,
    const PlanIterator* iter)
{
  store::Item_t lCollationItem;
  store::Item_t temp;

  if (!PlanIterator::consumeNext(lCollationItem, iter, planState))
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc, "An empty-sequence is not allowed as collation parameter");

  if (PlanIterator::consumeNext(temp, iter, planState))
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc, "A sequence of more then one item is not allowed as collation parameter");
    
  xqtref_t lCollationItemType = planState.theCompilerCB->m_sctx->get_typemanager()->
                                create_value_type (lCollationItem);

  // TODO resolve uri (base-uri)

  return planState.theRuntimeCB->theCollationCache->getCollator(lCollationItem->getStringValue());
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
FnIndexOfIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  store::Item_t lSequenceItem;
  store::Item_t lCollationItem;
  xqtref_t      lCollationItemType;

  FnIndexOfIteratorState* state;
  DEFAULT_STACK_INIT(FnIndexOfIteratorState, state, planState);
  
  if (!consumeNext(state->theSearchItem, theChildren[1].getp(), planState))
  {
    ZORBA_ERROR_LOC_DESC( FORG0006, loc, 
         "An empty sequence is not allowed as search item of fn:index-of");    
  }

  if ( theChildren.size() == 3 )
    state->theCollator = getCollator(planState.theRuntimeCB, loc, planState, theChildren[2].getp());

  while ( consumeNext(lSequenceItem, theChildren[0].getp(), planState))
  {
    // inc the position in the sequence; do it at the beginning of the loop because index-of starts with one
    ++state->theCurrentPos;
    
    if (CompareIterator::valueEqual(planState.theRuntimeCB,
                                    lSequenceItem, state->theSearchItem, state->theCollator) == 0)
      STACK_PUSH(GENV_ITEMFACTORY->createInteger(
        result,
        Integer::parseInt(state->theCurrentPos)), 
        state
      );
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
FnDistinctValuesIterator::FnDistinctValuesIterator(const QueryLoc& loc,
                                                   vector<PlanIter_t>& args)
 : NaryBaseIterator<FnDistinctValuesIterator, FnDistinctValuesIteratorState> ( loc, args )
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
  
  FnDistinctValuesIteratorState* state;
  DEFAULT_STACK_INIT(FnDistinctValuesIteratorState, state, planState);

  if (theChildren.size() == 2)
  {
    lCollator = getCollator(planState.theRuntimeCB, loc, planState, theChildren[1].getp());

    ValueCollCompareParam* vcp = new ValueCollCompareParam(planState.theRuntimeCB);
    vcp->theCollator = lCollator;
    state->theAlreadySeenMap = 
      new ItemValueCollHandleHashSet(vcp);
  } else {
    ValueCollCompareParam* vcp = new ValueCollCompareParam(planState.theRuntimeCB);
    state->theAlreadySeenMap = new ItemValueCollHandleHashSet(vcp);
  }

  while (consumeNext(result, theChildren[0].getp(), planState)) {
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
  if (theAlreadySeenMap) 
  {
    delete theAlreadySeenMap;
    theAlreadySeenMap = 0;
  }
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
  if (theAlreadySeenMap)
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
    state->theCollator = getCollator(planState.theRuntimeCB, loc, planState, theChildren[2].getp());

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
bool 
FnSubsequenceIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  store::Item_t temp;
  xqp_integer lSkip;
  xqp_integer zero = xqp_integer::parseInt (0), minus_one = xqp_integer::parseInt (-1);

  FnSubsequenceIteratorState* state;
  DEFAULT_STACK_INIT(FnSubsequenceIteratorState, state, planState);
  
  CONSUME(temp, 1);
  xqp_integer::parseDouble (temp->getDoubleValue ().round (), lSkip);
  lSkip += minus_one;
  
  if (theChildren.size() == 3) {
    CONSUME(temp, 2);
    xqp_integer::parseDouble (temp->getDoubleValue ().round (),
                              state->theRemaining);
  }

  if (lSkip < zero) {
    if (theChildren.size () >= 3)
      state->theRemaining += lSkip;
    lSkip = zero;
  }

  if (theChildren.size () == 3 && state->theRemaining <= zero)
    goto done;

  for (; lSkip > zero; --lSkip)
    if (!CONSUME (result, 0))
      goto done;
  
  while (((theChildren.size () < 3) || (state->theRemaining > xqp_integer::parseInt (0)))
         && CONSUME (result, 0))
  {
    if (theChildren.size () >= 3)
      state->theRemaining--;
      STACK_PUSH (true, state);
  }

done:
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

  if (firstPresent = consumeNext(result, theChildren[0].getp(), planState))
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

bool DeepEqual(store::Item_t& item1, store::Item_t& item2, XQPCollator* collator, RuntimeCB* theRuntimeCB);
    

bool DeepEqual(
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
    else if (!DeepEqual(child1, child2, collator, theRuntimeCB))
      return false;
  }
    
  return true;
}


bool DeepEqual(
    store::Item_t& item1,
    store::Item_t& item2,
    XQPCollator* collator,
    RuntimeCB* theRuntimeCB)
{
  if (item1.isNull() && item2.isNull())
    return true;

  if (item1 == NULL || item2 == NULL)
    return false;

  if (item1->isNode() != item2->isNode())
    return false;
  
  if (item1->isAtomic())
  {
    assert(item2->isAtomic());
    
    // check NaN
    xqtref_t type1 = theRuntimeCB->theStaticContext->get_typemanager()->create_value_type(item1.getp());
    xqtref_t type2 = theRuntimeCB->theStaticContext->get_typemanager()->create_value_type(item2.getp());
    
    if (((TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)
          &&
          item1->getFloatValue().isNaN())
          ||
          (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE)
          &&
          item1->getDoubleValue().isNaN()))
          &&
          ((TypeOps::is_subtype(*type2, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)
          &&
          item2->getFloatValue().isNaN())
          ||
          (TypeOps::is_subtype(*type2, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE)
          &&
          item2->getDoubleValue().isNaN())))
      return true;
    
    int result = CompareIterator::valueCompare(theRuntimeCB, item1, item2, collator);
    return (result == 0);
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
        return DeepEqual(item1->getAttributes(), item2->getAttributes(), collator, theRuntimeCB)
            &&
            DeepEqual(item1->getChildren(), item2->getChildren(), collator, theRuntimeCB);
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
          return DeepEqual(tvalue1, tvalue2, collator, theRuntimeCB);
        else if (tvalue1Iter != NULL && tvalue2Iter != NULL)
          return DeepEqual(tvalue1Iter, tvalue2Iter, collator, theRuntimeCB);
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
    collator = getCollator(planState.theRuntimeCB, loc, planState, theChildren[2].getp());
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

    equal = equal && DeepEqual(arg1, arg2, collator, planState.theRuntimeCB);
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

HashSemiJoinIterator::HashSemiJoinIterator(const QueryLoc& loc,
                                   std::vector<PlanIter_t>& args,
                                   bool antijoin)
 : NaryBaseIterator<HashSemiJoinIterator, HashSemiJoinIteratorState> ( loc, args ),
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
SortSemiJoinIterator::SortSemiJoinIterator(const QueryLoc& loc,
                                   std::vector<PlanIter_t>& args)
 : NaryBaseIterator<SortSemiJoinIterator, PlanIteratorState> ( loc, args )
{
}

SortSemiJoinIterator::~SortSemiJoinIterator() {}

bool 
SortSemiJoinIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  store::Item_t item [2];
  bool order;
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
    if (!order) {
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
bool 
FnAvgIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  store::Item_t lSumItem;
  store::Item_t lRunningItem;
  xqtref_t      lRunningType;
  store::Item_t countItem;
  int lCount = 0;
  bool lHitNumeric = false, lHitYearMonth = false, lHitDayTime = false;
  xqtref_t lUntypedAtomic     = GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE; 
  xqtref_t lYearMonthDuration = GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE; 
  xqtref_t lDayTimeDuration   = GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (consumeNext(lRunningItem, theChildren[0].getp(), planState)) {
    
    lRunningType = GENV_TYPESYSTEM.create_value_type (lRunningItem);

    if (TypeOps::is_numeric (*lRunningType) || TypeOps::is_equal (*lRunningType, *lUntypedAtomic)) {
      lHitNumeric = true;
      if ( lHitYearMonth )
        ZORBA_ERROR_LOC_DESC(FORG0006, loc, "Invalid argument type " + lRunningType->toString() 
                                                        + " for function fn:avg. Expected type " 
                                                        + lYearMonthDuration->toString() +".");
      if ( lHitDayTime ) 
        ZORBA_ERROR_LOC_DESC(FORG0006, loc, "Invalid argument type " + lRunningType->toString() 
                                                        + " for function fn:avg. Expected type " 
                                                        + lDayTimeDuration->toString() +".");

    } else if (TypeOps::is_equal (*lRunningType, *lYearMonthDuration)) {
      lHitYearMonth = true;
      if ( lHitNumeric )
        ZORBA_ERROR_LOC_DESC(FORG0006, loc, "Invalid argument type " + lRunningType->toString() 
                                                        + " for function fn:avg. Expected a numeric type.");
      if ( lHitDayTime ) 
        ZORBA_ERROR_LOC_DESC(FORG0006, loc, "Invalid argument type " + lRunningType->toString() 
                                                        + " for function fn:avg. Expected type " 
                                                        + lDayTimeDuration->toString() +".");

    } else if (TypeOps::is_equal (*lRunningType, *lDayTimeDuration)) {
      lHitDayTime = true;
      if ( lHitNumeric )
        ZORBA_ERROR_LOC_DESC(FORG0006, loc, "Invalid argument type " + lRunningType->toString() 
                                                        + " for function fn:avg. Expected a numeric type.");
      if ( lHitYearMonth )
        ZORBA_ERROR_LOC_DESC(FORG0006, loc, "Invalid argument type " + lRunningType->toString() 
                                                        + " for function fn:avg. Expected type " 
                                                        + lYearMonthDuration->toString() +".");
    } else {
      ZORBA_ERROR_LOC_DESC(FORG0006, loc, "The fn:avg function only accepts numeric or duration types.");
    }
    if ( lCount++ == 0 ) {
      lSumItem = lRunningItem;
    } else {
      // DO NOT short-circuit for INF and NaN!
      // Must check all items in case FORG0006 is needed
      GenericArithIterator<AddOperation>::compute(lSumItem, planState.theRuntimeCB, loc, lSumItem, lRunningItem);
    }
  }

  if (lCount > 0) {
    GENV_ITEMFACTORY->createInteger(countItem, Integer::parseInt (lCount));
    GenericArithIterator<DivideOperation>::compute(result, planState.theRuntimeCB, loc, lSumItem, countItem);
    STACK_PUSH(true, state);
  }
  // else return empty sequence

  STACK_END (state);
}

//15.4.3 fn:max & 15.4.4 fn:min
FnMinMaxIterator::FnMinMaxIterator
  (const QueryLoc& loc, std::vector<PlanIter_t>& aChildren, Type aType)
  : NaryBaseIterator<FnMinMaxIterator, PlanIteratorState>(loc, aChildren), 
    theType(aType),
    theCompareType(
       (aType == MIN 
       ? CompareConsts::VALUE_LESS 
       : CompareConsts::VALUE_GREATER)) 
{ }

bool 
FnMinMaxIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  store::Item_t lRunningItem = NULL;
  xqtref_t lMaxType;
  XQPCollator*  lCollator = 0;

  result = NULL;
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (theChildren.size() == 3)
    lCollator = getCollator(planState.theRuntimeCB, loc, planState, theChildren[2].getp());

  if (consumeNext(lRunningItem, theChildren[0].getp(), planState))
  {
    do {
      // casting of untyped atomic
      xqtref_t lRunningType = planState.theCompilerCB->m_sctx->get_typemanager()->
                              create_value_type (lRunningItem);

      if (TypeOps::is_subtype(*lRunningType, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)) {
        GenericCast::instance()->cast(lRunningItem, lRunningItem, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
        lRunningType = GENV_TYPESYSTEM.DOUBLE_TYPE_ONE;
      }

      // implementation dependent: return the first occurence)
      if (lRunningItem->isNaN()) {
        /** It must be checked if the sequence contains any 
         * xs:double("NaN") [xs:double("NaN") is returned] or 
         * only xs:float("NaN")'s [xs:float("NaN") is returned]'.
         */
        result = lRunningItem;
        if (TypeOps::is_subtype(*lRunningType, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE))
          break;

        lMaxType = planState.theCompilerCB->m_sctx->get_typemanager()->
                   create_value_type (result);
      }
      if (result != 0) {
        // Type Promotion
        store::Item_t lItemCur;
        if (!GenericCast::instance()->promote(lItemCur, lRunningItem, &*lMaxType)) {
          if (GenericCast::instance()->promote(lItemCur, result, &*lRunningType)) {
            result = lItemCur;
            lMaxType = planState.theCompilerCB->m_sctx->get_typemanager()->
                       create_value_type (result);
          } else {
            ZORBA_ERROR_LOC_DESC( FORG0006, loc,  "Promote not possible");
          }
        } else {
          lRunningItem = lItemCur;
          lRunningType = planState.theCompilerCB->m_sctx->get_typemanager()->
                         create_value_type (lRunningItem);
        }

        if (CompareIterator::valueComparison(planState.theRuntimeCB, lRunningItem, result, theCompareType, lCollator) ) {
          lMaxType = lRunningType;
          result = lRunningItem;
        }
      } else {
        lMaxType = lRunningType;
        result = lRunningItem;
      }
    } while (consumeNext(lRunningItem, theChildren[0].getp(), planState));
    STACK_PUSH(result != NULL, state);
  }

  STACK_END (state);
}


//15.4.5 fn:sum
bool 
FnSumIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  store::Item_t lRunningItem;
  xqtref_t      lResultType, lRunningType;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(result, theChildren[0].getp(), planState)) {

    // casting of untyped atomic
    lResultType = planState.theCompilerCB->m_sctx->get_typemanager()->
        create_value_type (result);

    if (TypeOps::is_subtype(*lResultType, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)) {
      GenericCast::instance()->cast(result, result, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      lResultType = GENV_TYPESYSTEM.DOUBLE_TYPE_ONE;
    }

    if (!TypeOps::is_numeric(*lResultType) && !TypeOps::is_subtype(*lResultType, *GENV_TYPESYSTEM.DURATION_TYPE_ONE))
      ZORBA_ERROR_LOC( FORG0006, loc );
    
    while (consumeNext(lRunningItem, theChildren[0].getp(), planState)) {
      // casting of untyped atomic
      lRunningType = planState.theCompilerCB->m_sctx->get_typemanager()->
          create_value_type (lRunningItem);

      if (TypeOps::is_subtype(*lRunningType, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)) {
        GenericCast::instance()->cast(lRunningItem, lRunningItem, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
        lRunningType = GENV_TYPESYSTEM.DOUBLE_TYPE_ONE;
      }

      // handling of NaN
      if (lRunningItem->isNaN()) {
         result = lRunningItem;
        break;
      }

      if((TypeOps::is_numeric(*lResultType) &&
          TypeOps::is_numeric(*lRunningType)) ||
         (TypeOps::is_subtype(*lResultType, *GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE) &&
          TypeOps::is_subtype(*lRunningType, *GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE)) ||
         (TypeOps::is_subtype(*lResultType, *GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE) &&
          TypeOps::is_subtype(*lRunningType, *GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE)))
        GenericArithIterator<AddOperation>::compute(result, planState.theRuntimeCB, loc, result, lRunningItem);
      else
        ZORBA_ERROR_LOC_DESC( FORG0006, loc, "Sum is not possible with parameters of the type " + TypeOps::toString (*lResultType) + " and " + TypeOps::toString (*lRunningType) );
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

//15.5.2 fn:id
void
FnIdIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theIterator = NULL;
  theTypedValueIter = NULL;
  inNode = NULL;
  inArg = NULL;
}


void
FnIdIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theIterator = NULL;
  theTypedValueIter = NULL;
  inNode = NULL;
  inArg = NULL;
}


bool 
FnIdIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  store::Item_t     item;
  store::Iterator_t theAttributes;
  bool              push;
  xqp_string        strArg;
  bool              tmp;
  store::Item*      rootNode;
  store::Item_t typedValue;

  FnIdIteratorState *state;
  DEFAULT_STACK_INIT(FnIdIteratorState, state, planState);

  if(consumeNext(state->inNode, theChildren[1], planState))
  {
    rootNode = state->inNode.getp();
    while (rootNode->getParent() != NULL)
      rootNode = rootNode->getParent();

    if (rootNode->getNodeKind() != store::StoreConsts::documentNode)
      ZORBA_ERROR_LOC_DESC(FODC0001, loc,
                           "No target document for fn:id function");

    state->inNode = rootNode;
    state->theIterator = state->inNode->getChildren();

    while (consumeNext(state->inArg, theChildren[0], planState))
    {
      state->theIterator->open();

      while(state->theIterator->next(result))
      {
        if(result->getNodeKind() == store::StoreConsts::elementNode)
        {
          if(result->isId())
          {
            result->getTypedValue(typedValue, state->theTypedValueIter);
            assert(state->theTypedValueIter == NULL);
    
            strArg = state->inArg->getStringValue().getp();

            try {
              tmp = strArg.matches(typedValue->getStringValue().getp()," ");
            }
            catch(zorbatypesException& ex){
              ZORBA_ERROR_LOC(error::DecodeZorbatypesError(ex.ErrorCode()), loc);
            }
                
            if(tmp)
              STACK_PUSH(true, state );
          }
          else
          {
            push = false;
            theAttributes = result->getAttributes();
            theAttributes->open();
            
            while (!push)
            {
              if (!theAttributes->next(result))
                break;
    
              if(result->isId())
              {
                result->getTypedValue(typedValue, state->theTypedValueIter);
                assert(state->theTypedValueIter == NULL);
    
                strArg = state->inArg->getStringValue().getp();
    
                if(strArg.matches(typedValue->getStringValue().getp()," "))
                  push = true;
              }
            }

            if(push)
              STACK_PUSH(true, state );
          }
        }
      }
    }
  }

  STACK_END (state);
}
  

//15.5.3 fn:idref
void
FnIdRefIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  inNode = NULL;
  inArg = NULL;
  theIterator = NULL;
  theTypedValueIter = NULL;
}

void
FnIdRefIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  inNode = NULL;
  inArg = NULL;
  theIterator = NULL;
  theTypedValueIter = NULL;
}

/**
 * 
 * @param planState 
 * @return 
 */
bool
FnIdRefIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  store::Item_t     item;
  store::Item_t     typedValue;
  store::Iterator_t theAttributes;
  store::Item_t     res;
  bool              push;
  xqp_string        strArg;
  bool              tmp;
  store::Item*      rootNode;

  FnIdIteratorState *state;
  DEFAULT_STACK_INIT(FnIdIteratorState, state, planState);

  if(consumeNext(state->inNode, theChildren[1], planState))
  {
    rootNode = state->inNode.getp();
    while (rootNode->getParent() != NULL)
      rootNode = rootNode->getParent();

    if (rootNode->getNodeKind() != store::StoreConsts::documentNode)
      ZORBA_ERROR_LOC_DESC(FODC0001, loc,
                           "No target document for fn:idref function");

    state->inNode = rootNode;
    state->theIterator = state->inNode->getChildren();

    while (consumeNext(state->inArg, theChildren[0], planState))
    {
      state->theIterator->open();

      while(state->theIterator->next(result))
      {
        if(result->getNodeKind() == store::StoreConsts::elementNode ||
           result->getNodeKind() == store::StoreConsts::attributeNode)
        {
          if(result->isIdRefs())
          {
            result->getTypedValue(typedValue, state->theTypedValueIter);

            if (state->theTypedValueIter == NULL && typedValue != NULL)
            {
              strArg = state->inArg->getStringValue().getp();

              try {
                tmp = strArg.matches(item->getStringValue().getp()," ");
              }
              catch(zorbatypesException& ex){
                ZORBA_ERROR_LOC(error::DecodeZorbatypesError(ex.ErrorCode()), loc);
              }
                
              if(tmp)
                STACK_PUSH(true, state );
            }
            else if (state->theTypedValueIter != NULL)
            {
              state->theTypedValueIter->open();
    
              while (true)
              {
                if (!state->theTypedValueIter->next(item))
                  break;

                strArg = state->inArg->getStringValue().getp();

                try {
                  tmp = strArg.matches(item->getStringValue().getp()," ");
                }
                catch(zorbatypesException& ex){
                  ZORBA_ERROR_LOC(error::DecodeZorbatypesError(ex.ErrorCode()), loc);
                }
                
                if(tmp)
                  STACK_PUSH(true, state );
              }
            }
          }
          else
          {
            push = false;
            theAttributes = result->getAttributes();
            theAttributes->open();
            
            while (!push)
            {
              if (!theAttributes->next(item))
                break;
    
              if(item->isId())
              {
                item->getTypedValue(typedValue, state->theTypedValueIter);

                if (state->theTypedValueIter == NULL && typedValue != NULL)
                {
                  strArg = state->inArg->getStringValue().getp();
    
                  if(strArg.matches(typedValue->getStringValue().getp()," "))
                    push = true;
                }
                else if (state->theTypedValueIter != NULL)
                {
                  state->theTypedValueIter->open();
    
                  while (!push)
                  {
                    if (!state->theTypedValueIter->next(item))
                      break;

                    strArg = state->inArg->getStringValue().getp();
    
                    if(strArg.matches(item->getStringValue().getp()," "))
                    {
                      push = true;
                      break;
                    }
                  }
                }
              }
            }
            if(push)
              STACK_PUSH(true, state );
          }
        }
      }
    }
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

FnDocIterator::FnDocIterator(const QueryLoc& loc, PlanIter_t& arg)
  :
  UnaryBaseIterator<FnDocIterator, PlanIteratorState> ( loc, arg )
{
}


FnDocIterator::~FnDocIterator()
{
}

bool FnDocIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     uriItem;
  xqpString         uriString;
  xqpStringStore_t  resolvedURIString;
  store::Item_t     resolvedURIItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(uriItem, theChild.getp(), planState)) {

    uriString = uriItem->getStringValueP();

    try {
      // maybe the document is stored with the uri that is given by the user
      result = GENV_STORE.getDocument(uriString.getStore());
    } catch (error::ZorbaError& e) {
      ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
    }
    if (result != NULL) {
      STACK_PUSH(true, state);
    } else {
      try {
        resolvedURIString = planState.sctx()->resolve_relative_uri(uriString).getStore(); 
        GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
      } catch (error::ZorbaError& e) {
        ZORBA_ERROR_LOC_DESC(FODC0005, loc, e.theDescription);
      }
      try {
        result = planState.sctx()->get_document_uri_resolver()->resolve(resolvedURIItem, 
                                                                        planState.sctx());
      } catch (error::ZorbaError& e) {
        ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
      }

      STACK_PUSH(true, state);
    }

  } // return empty sequence if input is the empty sequence
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

  if (consumeNext(uriItem, theChildren[0].getp(), planState)) {

    try {
      doc = planState.sctx()->get_document_uri_resolver()->resolve(uriItem, planState.sctx());
    } catch (error::ZorbaError& e) {
      if (e.theErrorCode == FODC0005) {
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
