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

#include "zorbaerrors/fatal.h"

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

#include "zorbaerrors/error_manager.h"
#include "zorbatypes/zorbatypesError.h"
#include "zorbatypes/URI.h"
#include "zorbaerrors/error_messages.h"

#include "util/web/web.h"
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
  store::Item_t lCollationItem = PlanIterator::consumeNext(iter, planState);

  if (lCollationItem == NULL)
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc, "An empty-sequence is not allowed as collation parameter");

  if (PlanIterator::consumeNext(iter, planState) != NULL)
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


store::Item_t
FnConcatIterator::nextImpl(PlanState& planState) const 
{
  store::Item_t item;
  std::auto_ptr<store::PUL> pul;

  FnConcatIteratorState* state;
  DEFAULT_STACK_INIT(FnConcatIteratorState, state, planState);

  if (theIsUpdating)
    pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  for (; state->theCurIter < theChildren.size(); ++state->theCurIter) 
  {
    item = consumeNext(theChildren[state->theCurIter].getp(), planState);
    while (item != NULL) 
    {
      if (theIsUpdating)
      {
        ZORBA_FATAL(item->isPul(), "");

        pul->mergeUpdates(item);
      }
      else
      {
        STACK_PUSH (item, state);
      }

      item = consumeNext(theChildren[state->theCurIter].getp(), planState);
    }
  }
  
  if (theIsUpdating)
    STACK_PUSH(pul.release(), state);

  STACK_END (state);
}

//15.1.3 fn:index-of
store::Item_t 
FnIndexOfIterator::nextImpl(PlanState& planState) const {
  store::Item_t lSequenceItem;
  store::Item_t lCollationItem;
  xqtref_t      lCollationItemType;
  int8_t lCmpRes;

  FnIndexOfIteratorState* state;
  DEFAULT_STACK_INIT(FnIndexOfIteratorState, state, planState);
  
  state->theSearchItem = consumeNext(theChildren[1].getp(), planState);
  if ( state->theSearchItem == NULL ) 
  {
    ZORBA_ERROR_LOC_DESC( FORG0006, loc, 
         "An empty sequence is not allowed as search item of fn:index-of");    
  }

  if ( theChildren.size() == 3 )
    state->theCollator = getCollator(planState.theRuntimeCB, loc, planState, theChildren[2].getp());

  while ( (lSequenceItem = consumeNext(theChildren[0].getp(), planState)) != NULL )
  {
    // inc the position in the sequence; do it at the beginning of the loop because index-of starts with one
    ++state->theCurrentPos; 
    
    lCmpRes = CompareIterator::valueCompare(planState.theRuntimeCB, 
                                            lSequenceItem, state->theSearchItem, state->theCollator);
    if ( lCmpRes == 0 ) 
      STACK_PUSH(GENV_ITEMFACTORY->createInteger(
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
store::Item_t 
FnEmptyIterator::nextImpl(PlanState& planState) const {
  store::Item_t lSequenceItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if ( ( lSequenceItem = consumeNext(theChildren[0].getp(), planState) ) == NULL ) 
  {
    STACK_PUSH (GENV_ITEMFACTORY->createBoolean ( true ), state);
  }
  else
  {
    STACK_PUSH (GENV_ITEMFACTORY->createBoolean ( false ), state);   
  }

  STACK_END (state);
}

//15.1.5 fn:exists
/*
 * If the value of $arg is not the empty sequence, the function returns true; 
 * otherwise, the function returns false.
 */
store::Item_t 
FnExistsIterator::nextImpl(PlanState& planState) const {
  store::Item_t lSequenceItem;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  
  if ( (lSequenceItem = consumeNext(theChildren[0].getp(), planState) ) != NULL) 
  {
    STACK_PUSH (GENV_ITEMFACTORY->createBoolean ( true ), state);
  }
  else
  {
    STACK_PUSH (GENV_ITEMFACTORY->createBoolean ( false ), state);   
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

store::Item_t 
FnDistinctValuesIterator::nextImpl(PlanState& planState) const {
  store::Item_t lItem;
  xqtref_t lItemType;
  XQPCollator* lCollator;
  
  FnDistinctValuesIteratorState* state;
  DEFAULT_STACK_INIT(FnDistinctValuesIteratorState, state, planState);

  if (theChildren.size() == 2)
  {
    lCollator = getCollator(planState.theRuntimeCB, loc, planState, theChildren[1].getp());

    state->theValueCompareParam = new store::ValueCollCompareParam(planState.theRuntimeCB);
    state->theValueCompareParam->theCollator = lCollator;
    state->theAlreadySeenMap = 
      new store::ItemValueCollHandleHashSet(static_cast<store::ValueCollCompareParam*>(state->theValueCompareParam));
  } else {
    state->theValueCompareParam = new store::ValueCollCompareParam(planState.theRuntimeCB);
    state->theAlreadySeenMap = new store::ItemValueCollHandleHashSet(state->theValueCompareParam);
  }

  while ( (lItem = consumeNext(theChildren[0].getp(), planState)) != NULL ) {
    if (lItem->isNumeric () && lItem->isNaN ()) {
      if (! state->theHasNaN) {
        state->theHasNaN = true;
        STACK_PUSH(lItem, state);
      }
    } else if ( ! state->theAlreadySeenMap->find(lItem) ) {
      // check if the item is already in the map
      state->theAlreadySeenMap->insert(lItem);
      STACK_PUSH(lItem, state);
    }
  }
    
  STACK_END (state);
}

void
FnDistinctValuesIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
}

void
FnDistinctValuesIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theHasNaN = false;
  theAlreadySeenMap->clear();
}

FnDistinctValuesIteratorState::FnDistinctValuesIteratorState()
  : theHasNaN (false),
    theAlreadySeenMap(0),
    theValueCompareParam(0) {}

FnDistinctValuesIteratorState::~FnDistinctValuesIteratorState() 
{
  if (theAlreadySeenMap) {
    delete theAlreadySeenMap;
    theAlreadySeenMap = 0;
  }

}


//15.1.7 fn:insert-before
store::Item_t 
FnInsertBeforeIterator::nextImpl(PlanState& planState) const {
 store::Item_t lInsertItem;
 store::Item_t lPositionItem;
 
 FnInsertBeforeIteratorState* state;
 DEFAULT_STACK_INIT(FnInsertBeforeIteratorState, state, planState);
 
 lPositionItem = consumeNext(theChildren[1].getp(), planState);
 if ( lPositionItem == NULL )
 {
   // raise error
 }

 state->thePosition = lPositionItem->getIntegerValue();
 if (state->thePosition < xqp_integer::parseInt(1))
   state->thePosition = xqp_integer::parseInt(1);
   
  
 while ( (state->theTargetItem = consumeNext(theChildren[0].getp(), planState)) != NULL ) 
 {
    if ( state->theCurrentPos == state->thePosition-xqp_integer::parseInt(1) ) // position found => insert sequence
    {
      while ( (lInsertItem = consumeNext(theChildren[2].getp(), planState)) != NULL)
      {
        STACK_PUSH (lInsertItem, state);
      }
    }
    ++state->theCurrentPos;
    STACK_PUSH (state->theTargetItem, state);
  }
  
  if (state->theCurrentPos < state->thePosition) // append to the end
  {
    while ( (lInsertItem = consumeNext(theChildren[2].getp(), planState)) != NULL)
    {
      STACK_PUSH (lInsertItem, state);
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
store::Item_t 
FnRemoveIterator::nextImpl(PlanState& planState) const {
  store::Item_t lSequenceItem;
  store::Item_t lPositionItem;
  store::Item_t lCollationItem;
  xqtref_t      lCollationItemType;

  FnRemoveIteratorState* state;
  DEFAULT_STACK_INIT(FnRemoveIteratorState, state, planState);
  
  lPositionItem = consumeNext(theChildren[1].getp(), planState);
  if ( lPositionItem == NULL ) 
  {
    ZORBA_ERROR_LOC_DESC( FORG0006,
         loc, "An empty sequence is not allowed as second argument to of fn:remove.");
  }
  state->thePosition = lPositionItem->getIntegerValue();

  if ( theChildren.size() == 3 )
    state->theCollator = getCollator(planState.theRuntimeCB, loc, planState, theChildren[2].getp());

  while ( (lSequenceItem = consumeNext(theChildren[0].getp(), planState)) != NULL )
  {
    // inc the position in the sequence; do it at the beginning of the loop because fn:remove starts with one
    ++state->theCurrentPos; 
  
    if (state->theCurrentPos == state->thePosition)
      continue;
  
    STACK_PUSH (lSequenceItem, state);
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
store::Item_t FnReverseIterator::nextImpl(PlanState& planState) const
{
  store::Item_t iVal;

  FnReverseIteratorState *state;
  DEFAULT_STACK_INIT(FnReverseIteratorState, state, planState);

  while((iVal = consumeNext(theChildren[0].getp(), planState)) != NULL) {
    state->theStack.push(iVal);
  }

  while(!state->theStack.empty()) {
    iVal = state->theStack.top();
    state->theStack.pop();
    STACK_PUSH(iVal, state);
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
store::Item_t 
FnSubsequenceIterator::nextImpl(PlanState& planState) const {
  store::Item_t item;
  xqp_integer lSkip;
  xqp_integer zero = xqp_integer::parseInt (0), minus_one = xqp_integer::parseInt (-1);

  FnSubsequenceIteratorState* state;
  DEFAULT_STACK_INIT(FnSubsequenceIteratorState, state, planState);
  
  xqp_integer::parseDouble (CONSUME (1)->getDoubleValue ().round (), lSkip);
  lSkip += minus_one;
  
  if (theChildren.size() == 3)
    xqp_integer::parseDouble (CONSUME (2)->getDoubleValue ().round (),
                              state->theRemaining);

  if (lSkip < zero) {
    if (theChildren.size () >= 3)
      state->theRemaining += lSkip;
    lSkip = zero;
  }

  if (theChildren.size () == 3 && state->theRemaining <= zero)
    goto done;

  for (; lSkip > zero; --lSkip)
    if (NULL == (item = CONSUME (0)))
      goto done;
  
  while (((theChildren.size () < 3) || (state->theRemaining > xqp_integer::parseInt (0)))
         && (NULL != (item = CONSUME (0))))
  {
    if (theChildren.size () >= 3)
      state->theRemaining--;
      STACK_PUSH (item, state);
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
store::Item_t 
FnZeroOrOneIterator::nextImpl(PlanState& planState) const {
  store::Item_t lFirstSequenceItem;
  store::Item_t lNextSequenceItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  lFirstSequenceItem = consumeNext(theChildren[0].getp(), planState);
  if (lFirstSequenceItem != NULL)
  {
    lNextSequenceItem = consumeNext(theChildren[0].getp(), planState);
    if (lNextSequenceItem != NULL)
    {
      ZORBA_ERROR_LOC_DESC( FORG0003, 
        loc,  "fn:zero-or-one called with a sequence containing more than one item."); 

    }
    STACK_PUSH(lFirstSequenceItem, state);
  }
  STACK_END (state);
}



//15.2.2 fn:one-or-more
store::Item_t 
FnOneOrMoreIterator::nextImpl(PlanState& planState) const {
  store::Item_t lSequenceItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  lSequenceItem = consumeNext(theChildren[0].getp(), planState);
  if (lSequenceItem == NULL)
  {
    ZORBA_ERROR_LOC_DESC( FORG0004,
        loc,  "fn:one-or-more called with a sequence containing no items.");
  }
  do
  {
    STACK_PUSH(lSequenceItem, state);
  } while ( (lSequenceItem = consumeNext(theChildren[0].getp(), planState)) != NULL );

  STACK_END (state);
}

//15.2.3 fn:exactly-one
store::Item_t 
FnExactlyOneIterator::nextImpl(PlanState& planState) const {
  store::Item_t lFirstItem;
  store::Item_t lNextItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  lFirstItem = consumeNext(theChildren[0].getp(), planState);
  if (lFirstItem != NULL)
    lNextItem = consumeNext(theChildren[0].getp(), planState);

  if (lFirstItem != NULL && lNextItem == NULL)
    STACK_PUSH (raise_err ? lFirstItem : GENV_ITEMFACTORY->createBoolean (true),
                state);
  else {
    if (raise_err)
      ZORBA_ERROR_LOC_DESC( FORG0005,
                            loc, "fn:exactly-one called with a sequence containing zero or more than one item.");
    else
      STACK_PUSH (GENV_ITEMFACTORY->createBoolean ( false ), state);
  }

  STACK_END (state);
}


/*______________________________________________________________________
|
| 15.3 Equals, Union, Intersection and Except
|_______________________________________________________________________*/

//15.3.1 fn:deep-equal

bool DeepEqual(store::Item_t& item1, store::Item_t& item2, XQPCollator* collator, RuntimeCB* theRuntimeCB);
    
bool DeepEqual(store::Iterator_t it1, store::Iterator_t it2, XQPCollator* collator, RuntimeCB* theRuntimeCB)
{
  store::Item_t child1, child2;
  
  it1->open();
  it2->open();
  child1 = it1->next();
  child2 = it2->next();
  while (1)
  {
    if (child1 == NULL && child2 == NULL)
      return true;
    else if (child1 == NULL || child2 == NULL)
      return false;
    else if (!DeepEqual(child1, child2, collator, theRuntimeCB))
      return false;
      
    child1 = it1->next();
    child2 = it2->next();
  }
    
  return true;
}

bool DeepEqual(store::Item_t& item1, store::Item_t& item2, XQPCollator* collator, RuntimeCB* theRuntimeCB)
{
  if (item1.isNull() && item2.isNull())
    return true;
  
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
        if (0 != item1->getNodeName()->getStringValue()->compare(item2->getNodeName()->getStringValue(), collator))
          return false;
        return DeepEqual(item1->getTypedValue(), item2->getTypedValue(), collator, theRuntimeCB);
        break;
        
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

store::Item_t 
FnDeepEqualIterator::nextImpl(PlanState& planState) const
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
    arg1 = consumeNext(theChildren[0].getp(), planState);
    arg2 = consumeNext(theChildren[1].getp(), planState);

    if (arg1 == NULL && arg2 == NULL)
      break;
    else if (arg1 == NULL || arg2 == NULL)
    {
      equal = false;
      break;
    }

    equal = equal && DeepEqual(arg1, arg2, collator, planState.theRuntimeCB);
  }
  
  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(equal), state);

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

store::Item_t 
HashSemiJoinIterator::nextImpl(PlanState& planState) const {
  store::Item_t lItem;
  bool not_found;

  HashSemiJoinIteratorState* state;
  DEFAULT_STACK_INIT(HashSemiJoinIteratorState, state, planState);

  // eat the complete right-hand side and hash it
  while ( (lItem = consumeNext(theChildren[1].getp(), planState)) != NULL ) {
    state->theRightInput->insert(lItem);
  }
  

  while ( ( lItem = consumeNext(theChildren[0].getp(), planState)) != NULL ) {
    not_found = ! state->theRightInput->find(lItem);
    if (not_found == theAntijoin)
      STACK_PUSH(lItem, state);
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

store::Item_t 
SortSemiJoinIterator::nextImpl(PlanState& planState) const {
  store::Item_t item [2];
  bool order;
  int i;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);


  for (;;) {

    // load items
    for (i = 0; i < 2; i++) {
      if (item [i] == NULL) {
        if ((item [i] = CONSUME (i)) == NULL)
          goto done;
      }
    }

    // advance, output
    order = GENV_STORE.compareNodes (item [0].getp(), item [1].getp());
    if (!order) {
      STACK_PUSH (item [0], state);
      item [0] = item [1] = NULL;
    }
    else item [order? 0 : 1] = NULL;

  }

done:
  STACK_END (state);
}

/*______________________________________________________________________
|
| 15.4 Aggregate Functions
|_______________________________________________________________________*/

//15.4.1 fn:count
store::Item_t 
FnCountIterator::nextImpl(PlanState& planState) const {
  store::Item_t lSequenceItem;
  xqp_integer lCount = Integer::parseInt(0);

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while ( (lSequenceItem = consumeNext(theChildren[0].getp(), planState)) != NULL )
  {
    ++lCount;
  }

  STACK_PUSH(GENV_ITEMFACTORY->createInteger(lCount), state);

  STACK_END (state);
}

//15.4.2 fn:avg
store::Item_t 
FnAvgIterator::nextImpl(PlanState& planState) const {
  store::Item_t lSumItem;
  store::Item_t lRunningItem;
  xqtref_t      lRunningType;
  int lCount = 0;
  bool lHitNumeric = false, lHitYearMonth = false, lHitDayTime = false;
  xqtref_t lUntypedAtomic     = GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE; 
  xqtref_t lYearMonthDuration = GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE; 
  xqtref_t lDayTimeDuration   = GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while ((lRunningItem = consumeNext(theChildren[0].getp(), planState)) != NULL) {
    
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
      lSumItem = GenericArithIterator<AddOperation>::compute(planState.theRuntimeCB, loc, lSumItem, lRunningItem);
    }
  }

  if (lCount > 0)
    STACK_PUSH(GenericArithIterator<DivideOperation>::compute(planState.theRuntimeCB, loc, lSumItem,
                                                          GENV_ITEMFACTORY->createInteger(Integer::parseInt (lCount))), state);
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

store::Item_t 
FnMinMaxIterator::nextImpl(PlanState& planState) const {
  store::Item_t lMaxItem = NULL;
  store::Item_t lRunningItem = NULL;
  xqtref_t lMaxType;
  XQPCollator*  lCollator = 0;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (theChildren.size() == 3)
    lCollator = getCollator(planState.theRuntimeCB, loc, planState, theChildren[2].getp());

  lRunningItem = consumeNext(theChildren[0].getp(), planState);
  if ( lRunningItem != NULL )
  {
    do {
      // casting of untyped atomic
      xqtref_t lRunningType = planState.theCompilerCB->m_sctx->get_typemanager()->
                              create_value_type (lRunningItem);

      if (TypeOps::is_subtype(*lRunningType, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)) {
        lRunningItem = GenericCast::instance()->cast(lRunningItem, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
        lRunningType = GENV_TYPESYSTEM.DOUBLE_TYPE_ONE;
      }

      // implementation dependent: return the first occurence)
      if (lRunningItem->isNumeric() && lRunningItem->isNaN()) {
        /** It must be checked if the sequence contains any 
         * xs:double("NaN") [xs:double("NaN") is returned] or 
         * only xs:float("NaN")'s [xs:float("NaN") is returned]'.
         */
        lMaxItem = lRunningItem;
        if (TypeOps::is_subtype(*lRunningType, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE))
          break;

        lMaxType = planState.theCompilerCB->m_sctx->get_typemanager()->
                   create_value_type (lMaxItem);
      }
      if (lMaxItem != 0) {
        // Type Promotion
        store::Item_t lItemCur = GenericCast::instance()->promote(lRunningItem, &*lMaxType);
        if (lItemCur == 0) {
          lItemCur = GenericCast::instance()->promote(lMaxItem, &*lRunningType); 
          if (lItemCur != 0) {
            lMaxItem = lItemCur;
            lMaxType = planState.theCompilerCB->m_sctx->get_typemanager()->
                       create_value_type (lMaxItem);
          } else {
            ZORBA_ERROR_LOC_DESC( FORG0006, loc,  "Promote not possible");
          }
        } else {
          lRunningItem = lItemCur;
          lRunningType = planState.theCompilerCB->m_sctx->get_typemanager()->
                         create_value_type (lRunningItem);
        }

        if (CompareIterator::valueComparison(planState.theRuntimeCB, lRunningItem, lMaxItem, theCompareType, lCollator) ) {
          lMaxType = lRunningType;
          lMaxItem = lRunningItem;
        }
      } else {
        lMaxType = lRunningType;
        lMaxItem = lRunningItem;
      }
    } while ((lRunningItem = consumeNext(theChildren[0].getp(), planState)) != NULL);
    STACK_PUSH(lMaxItem, state);
  }

  STACK_END (state);
}


//15.4.5 fn:sum
store::Item_t 
FnSumIterator::nextImpl(PlanState& planState) const {
  store::Item_t lSumItem;
  store::Item_t lRunningItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  lSumItem = consumeNext(theChildren[0].getp(), planState);
  if (lSumItem != NULL) { // return 0 or given value if empty sequence
    while ( (lRunningItem = consumeNext(theChildren[0].getp(), planState)) != NULL ) {
      lSumItem = GenericArithIterator<AddOperation>::compute(planState.theRuntimeCB, loc, lSumItem, lRunningItem); 
    }

    STACK_PUSH(lSumItem, state);
  } else {
    if (theChildren.size() == 2)
    {
      lSumItem = consumeNext(theChildren[1].getp(), planState);
      if (lSumItem != NULL)
      {
        STACK_PUSH(lSumItem, state);
      }
      // return the empty sequence otherwise
    } else {
      STACK_PUSH(GENV_ITEMFACTORY->createInteger(Integer::parseInt((int32_t)0)), state);
    }
  }

  STACK_END (state);
}


/*______________________________________________________________________
|
| 15.5 Functions and Operators that Generate Sequences
|_______________________________________________________________________*/

//15.5.1 op:to
store::Item_t 
OpToIterator::nextImpl(PlanState& planState) const {
  store::Item_t lItem;
  
  OpToIteratorState* state;
  DEFAULT_STACK_INIT(OpToIteratorState, state, planState);

  lItem = consumeNext(theChildren[0].getp(), planState);
  if (lItem != NULL)
  {
    state->theFirstVal = lItem->getIntegerValue();

    lItem = consumeNext(theChildren[1].getp(), planState);
    if (lItem != NULL)
    {
      state->theLastVal = lItem->getIntegerValue();

      // return empty sequence otherwise
      if ( state->theLastVal >= state->theFirstVal )
      {
        state->theCurInt = state->theFirstVal;
        while ( state->theCurInt <= state->theLastVal )
        {
          STACK_PUSH(GENV_ITEMFACTORY->createInteger(state->theCurInt), state);
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
  theTypedValue = NULL;
  inNode = NULL;
  inArg = NULL;
}

void
FnIdIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theIterator = NULL;
  theTypedValue = NULL;
  inNode = NULL;
  inArg = NULL;
}

store::Item_t 
FnIdIterator::nextImpl(PlanState& planState) const 
{
  store::Item_t     itemEl;
  store::Item_t     item;
  store::Iterator_t theAttributes;
  store::Item_t     res;
  bool              push;
  xqp_string        strArg;
  bool              tmp;
  store::Item*      rootNode;

  FnIdIteratorState *state;
  DEFAULT_STACK_INIT(FnIdIteratorState, state, planState);

  if((state->inNode = consumeNext(theChildren[1], planState)) != NULL)
  {
    rootNode = state->inNode.getp();
    while (rootNode->getParent() != NULL)
      rootNode = rootNode->getParent();

    if (rootNode->getNodeKind() != store::StoreConsts::documentNode)
      ZORBA_ERROR_LOC_DESC(FODC0001, loc,
                           "No target document for fn:id function");

    state->inNode = rootNode;
    state->theIterator = state->inNode->getChildren();

    while ((state->inArg = consumeNext(theChildren[0], planState)) != NULL)
    {
      state->theIterator->open();

      while((itemEl = state->theIterator->next()) != NULL )
      {
        if(itemEl->getNodeKind() == store::StoreConsts::elementNode)
        {
          if(itemEl->isId())
          {
            state->theTypedValue = itemEl->getTypedValue();
            state->theTypedValue->open();
    
            while (true)
            {
              item = state->theTypedValue->next();
              if (item == NULL)
                break;

              strArg = state->inArg->getStringValue().getp();

              try {
                tmp = strArg.matches(item->getStringValue().getp()," ");
              }
              catch(zorbatypesException& ex){
                ZORBA_ERROR_LOC(error::DecodeZorbatypesError(ex.ErrorCode()), loc);
              }
                
              if(tmp)
                STACK_PUSH( itemEl, state );
            }
          }
          else
          {
            push = false;
            theAttributes = itemEl->getAttributes();
            theAttributes->open();
            
            while (!push)
            {
              item = theAttributes->next();
              if (item == NULL)
                break;
    
              if(item->isId())
              {
                state->theTypedValue = item->getTypedValue();
                state->theTypedValue->open();
    
                while (!push)
                {
                  item = state->theTypedValue->next();
                  if (item == NULL)
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
            if(push)
              STACK_PUSH( itemEl, state );
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
  theTypedValue = NULL;
}

void
FnIdRefIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  inNode = NULL;
  inArg = NULL;
  theIterator = NULL;
  theTypedValue = NULL;
}

/**
 * 
 * @param planState 
 * @return 
 */
store::Item_t
FnIdRefIterator::nextImpl(PlanState& planState) const {
  store::Item_t     itemNode;
  store::Item_t     item;
  store::Iterator_t theAttributes;
  store::Item_t     res;
  bool              push;
  xqp_string        strArg;
  bool              tmp;
  store::Item*      rootNode;

  FnIdIteratorState *state;
  DEFAULT_STACK_INIT(FnIdIteratorState, state, planState);

  if((state->inNode = consumeNext(theChildren[1], planState)) != NULL)
  {
    rootNode = state->inNode.getp();
    while (rootNode->getParent() != NULL)
      rootNode = rootNode->getParent();

    if (rootNode->getNodeKind() != store::StoreConsts::documentNode)
      ZORBA_ERROR_LOC_DESC(FODC0001, loc,
                           "No target document for fn:idref function");

    state->inNode = rootNode;
    state->theIterator = state->inNode->getChildren();

    while ((state->inArg = consumeNext(theChildren[0], planState)) != NULL)
    {
      state->theIterator->open();

      while((itemNode = state->theIterator->next()) != NULL )
      {
        if(itemNode->getNodeKind() == store::StoreConsts::elementNode ||
           itemNode->getNodeKind() == store::StoreConsts::attributeNode)
        {
          if(itemNode->isIdRefs())
          {
            state->theTypedValue = itemNode->getTypedValue();
            state->theTypedValue->open();
    
            while (true)
            {
              item = state->theTypedValue->next();
              if (item == NULL)
                break;

              strArg = state->inArg->getStringValue().getp();

              try {
                tmp = strArg.matches(item->getStringValue().getp()," ");
              }
              catch(zorbatypesException& ex){
                ZORBA_ERROR_LOC(error::DecodeZorbatypesError(ex.ErrorCode()), loc);
              }
                
              if(tmp)
                STACK_PUSH( itemNode, state );
            }
          }
          else
          {
            push = false;
            theAttributes = itemNode->getAttributes();
            theAttributes->open();
            
            while (!push)
            {
              item = theAttributes->next();
              if (item == NULL)
                break;
    
              if(item->isId())
              {
                state->theTypedValue = item->getTypedValue();
                state->theTypedValue->open();
    
                while (!push)
                {
                  item = state->theTypedValue->next();
                  if (item == NULL)
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
            if(push)
              STACK_PUSH( itemNode, state );
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


static store::Item_t get_doc(xqpStringStore_t& uriString, const char **err) 
{
  store::Store& store = GENV.getStore();

  store::Item_t doc = store.getDocument(uriString);
    
  if (doc == NULL)
  {
    xqpStringStore_t lowercaseUri = uriString->lowercase();
    if (lowercaseUri->indexOf("http://") == 0)
    {
#ifdef HAVE_CURL_H
      // retrieve web file
      xqp_string xmlString;
      int result = http_get(lowercaseUri->c_str(), xmlString);
      if (result != 0)
      {
        *err = "HTTP get failure."; 
        return NULL;
      }

      istringstream iss(xmlString.c_str());

      doc = store.loadDocument(uriString, iss);
      if (doc == NULL)
      {
        *err = "Failed to parse document.";
        return NULL;
      }
#else
      *err = "Can't perform HTTP request. Please build Zorba with libcurl."; 
      return NULL;
#endif
    }
    else 
    {
      // load file
      ifstream ifs;
      xqpStringStore_t decodedURI = URI::decode_file_URI(uriString);
      ifs.open(decodedURI->c_str(), ios::in);
      if (ifs.is_open() == false)
      {
        *err = "File does not exist."; return NULL;
      }
      
      doc = store.loadDocument(uriString, ifs);
      if (doc == NULL)
      {
        *err = "Failed to parse document."; return NULL;
      }
    }
  }

  return doc;
}

store::Item_t FnDocIterator::nextImpl(PlanState& planState) const
{
  store::Item_t    doc;
  store::Item_t    uriItem;
  xqpStringStore_t uriString;
  xqpStringStore_t uriString2;
  const char*      err = NULL;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  uriItem = consumeNext(theChild.getp(), planState);
  if (uriItem == NULL)
    return NULL;

  uriString = uriItem->getStringValue();

  if(!URI::is_valid(uriString))
    ZORBA_ERROR_PARAM(FODC0005, uriString->c_str(), "");

  uriString2 = uriString;

  doc = get_doc(uriString, &err);

  if (doc == NULL)
    ZORBA_ERROR_LOC_PARAM(FODC0002, loc,
                          uriString2->c_str(),
                          (err == NULL ? "" :  err));
  STACK_PUSH(doc, state);
  STACK_END (state);
}

/*______________________________________________________________________
| 15.5.5 fn:doc-available
|
|   fn:doc-available($uri as xs:string?) as xs:boolean
|_______________________________________________________________________*/
store::Item_t FnDocAvailableIterator::nextImpl(PlanState& planState) const
{
  store::Item_t    doc;
  store::Item_t    uriItem;
  xqpStringStore_t uriString;
  const char*      err = NULL;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  uriItem = consumeNext(theChildren[0].getp(), planState);
  if (uriItem == NULL)
    return NULL;

  uriString = uriItem->getStringValue();

  if(!URI::is_valid(uriString))
    ZORBA_ERROR_PARAM(FODC0005, xqp_string(uriString), "");

  doc = get_doc(uriString, &err);

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(doc != NULL), state);
  STACK_END (state);
}
} /* namespace zorba */
/* vim:set ts=2 sw=2: */
