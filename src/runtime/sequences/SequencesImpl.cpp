/**
 * Copyright FLWOR Foundation
 *
 * Author: David Graf (david.graf@28msec.com)
 */

#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include "runtime/sequences/SequencesImpl.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/numerics/NumericsImpl.h"
#include "system/globalenv.h"

#include "types/casting.h"

#include "store/api/store.h"

#include "errors/error_factory.h"

#include "util/web/web.h"

using namespace std;
namespace xqp {
  

/*______________________________________________________________________
|  
| 15.1 General Functions and Operators on Sequences
|_______________________________________________________________________*/


//15.1.2 op:concatenate 
//---------------------
void
FnConcatIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theCurIter = 0;
}

void
FnConcatIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurIter = 0;
}

Item_t
FnConcatIterator::nextImpl(PlanState& planState) {
  Item_t item;
  
  FnConcatIteratorState* state;
  DEFAULT_STACK_INIT(FnConcatIteratorState, state, planState);
  
  for (; state->theCurIter < theChildren.size(); ++state->theCurIter) {;
    item = this->consumeNext(theChildren[state->theCurIter], planState);
    while (item != NULL) {
      STACK_PUSH (item, state);
      item = this->consumeNext(theChildren[state->theCurIter], planState);
    }
  }
  
  STACK_END();
}

//15.1.3 fn:index-of
// FIXME this iterator has three arguments (i.e. the collaction as #3)
Item_t 
FnIndexOfIterator::nextImpl(PlanState& planState) {
  Item_t lSequenceItem;
  int8_t lCmpRes;

  FnIndexOfIteratorState* state;
  DEFAULT_STACK_INIT(FnIndexOfIteratorState, state, planState);
  
  state->theSearchItem = consumeNext(theChildren[1], planState);
  if ( state->theSearchItem == NULL ) 
  {
    ZORBA_ERROR_ALERT( ZorbaError::FORG0006, &loc, DONT_CONTINUE_EXECUTION,
         "An empty sequence is not allowed as search item of fn:index-of");    
  }

  while ( (lSequenceItem = consumeNext(theChildren[0], planState)) != NULL )
  {
    // inc the position in the sequence; do it at the beginning of the loop because index-of starts with one
    ++state->theCurrentPos; 
    
    // The items in the sequence theChild0 are compared with theSearchItem under the rules for the eq operator. 
    // Values of type xs:untypedAtomic are compared as if they were of type xs:string. 
    // Values that cannot be compared, i.e. the eq operator is not defined for their types, are considered to be distinct. 
    // If an item compares equal, then the position of that item in the sequence $seqParam is included in the result.
    lCmpRes = CompareIterator::valueCompare(lSequenceItem, state->theSearchItem);
    if ( lCmpRes == 0 ) // FIXME collation support
      STACK_PUSH(Zorba::getItemFactory()->createInteger(
        Integer::parseInt(state->theCurrentPos)), 
        state
      );
  }

  STACK_END();
}

void
FnIndexOfIteratorState::init(PlanState& planState) 
{
 PlanIteratorState::init(planState);
 theCurrentPos = 0;
 theSearchItem = NULL;
}

void
FnIndexOfIteratorState::reset(PlanState& planState) {
 PlanIteratorState::reset(planState);
 theCurrentPos = 0;
 theSearchItem = NULL;
}


//15.1.4 fn:empty
/*
 * If the value of $arg is the empty sequence, the function returns true; 
 * otherwise, the function returns false.
 */
Item_t 
FnEmptyIterator::nextImpl(PlanState& planState) {
  Item_t lSequenceItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if ( ( lSequenceItem = consumeNext(theChildren[0], planState) ) == NULL ) 
  {
    STACK_PUSH (Zorba::getItemFactory()->createBoolean ( true ), state);
  }
  else
  {
    STACK_PUSH (Zorba::getItemFactory()->createBoolean ( false ), state);   
  }

  STACK_END();
}

//15.1.5 fn:exists
/*
 * If the value of $arg is not the empty sequence, the function returns true; 
 * otherwise, the function returns false.
 */
Item_t 
FnExistsIterator::nextImpl(PlanState& planState) {
  Item_t lSequenceItem;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  
  if ( (lSequenceItem = consumeNext(theChildren[0], planState) ) != NULL) 
  {
    STACK_PUSH (Zorba::getItemFactory()->createBoolean ( true ), state);
  }
  else
  {
    STACK_PUSH (Zorba::getItemFactory()->createBoolean ( false ), state);   
  }

  STACK_END();
}


//15.1.6 fn:distinct-values
/**
 * Returns the sequence that results from removing from arg all but one of a set of
 * values that are eq to one other. 
 * The order in which the sequence of values is returned is ·implementation dependent·.
 * Here, we return the first item that is not a duplicate and throw away the remaining ones
 */
FnDistinctValuesIterator::FnDistinctValuesIterator(yy::location loc,
                                                   vector<PlanIter_t>& args)
 : NaryBaseIterator<FnDistinctValuesIterator, FnDistinctValuesIteratorState> ( loc, args )
{ }

FnDistinctValuesIterator::~FnDistinctValuesIterator(){}

Item_t 
FnDistinctValuesIterator::nextImpl(PlanState& planState) {
  Item_t lItem;
  FnDistinctValuesIteratorState::AlreadySeenConstIter_t lConstIter;
  
  FnDistinctValuesIteratorState* state;
  DEFAULT_STACK_INIT(FnDistinctValuesIteratorState, state, planState);

  if (theChildren.size() == 2)
  {
    // TODO collation support
  }
      
  while ( (lItem = consumeNext(theChildren[0], planState)) != NULL )
  {
    // check if the item is alrady in the map
    lConstIter = state->theAlreadySeenMap.find(lItem);

    // if the item was not in the map
    if ( lConstIter == state->theAlreadySeenMap.end() ) 
    {
      state->theAlreadySeenMap[lItem] = 1;
      STACK_PUSH(lItem, state);
    }
  }
    
  STACK_END();
}

void
FnDistinctValuesIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
}

void
FnDistinctValuesIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theAlreadySeenMap.clear();
}


//15.1.7 fn:insert-before
Item_t 
FnInsertBeforeIterator::nextImpl(PlanState& planState) {
 Item_t lInsertItem;
 Item_t lPositionItem;
 
 FnInsertBeforeIteratorState* state;
 DEFAULT_STACK_INIT(FnInsertBeforeIteratorState, state, planState);
 
 lPositionItem = consumeNext(theChildren[1], planState);
 if ( lPositionItem == NULL )
 {
   // raise error
 }

 state->thePosition = lPositionItem->getIntegerValue();
 if (state->thePosition < xqp_integer::parseInt(1))
   state->thePosition = xqp_integer::parseInt(1);
   
  
 while ( (state->theTargetItem = consumeNext(theChildren[0], planState)) != NULL ) 
 {
    if ( state->theCurrentPos == state->thePosition-xqp_integer::parseInt(1) ) // position found => insert sequence
    {
      while ( (lInsertItem = consumeNext(theChildren[2], planState)) != NULL)
      {
        STACK_PUSH (lInsertItem, state);
      }
    }
    ++state->theCurrentPos;
    STACK_PUSH (state->theTargetItem, state);
  }
  
  if (state->theCurrentPos < state->thePosition) // append to the end
  {
    while ( (lInsertItem = consumeNext(theChildren[2], planState)) != NULL)
    {
      STACK_PUSH (lInsertItem, state);
    }    
  }
 
  STACK_END();
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
// FIXME this iterator has three arguments (i.e. the collaction as #3)
Item_t 
FnRemoveIterator::nextImpl(PlanState& planState) {
  Item_t lSequenceItem;
  Item_t lPositionItem;

  FnRemoveIteratorState* state;
  DEFAULT_STACK_INIT(FnRemoveIteratorState, state, planState);
  
  lPositionItem = consumeNext(theChildren[1], planState);
  if ( lPositionItem == NULL ) 
  {
    ZORBA_ERROR_ALERT(
         ZorbaError::FORG0006,
         &loc, DONT_CONTINUE_EXECUTION,
         "An empty sequence is not allowed as second argument to of fn:remove.");
  }

  state->thePosition = lPositionItem->getIntegerValue();

  while ( (lSequenceItem = consumeNext(theChildren[0], planState)) != NULL )
  {
    // inc the position in the sequence; do it at the beginning of the loop because fn:remove starts with one
    ++state->theCurrentPos; 
  
    if (state->theCurrentPos == state->thePosition)
      continue;
  
    STACK_PUSH (lSequenceItem, state);
  }

  STACK_END();
}

void
FnRemoveIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
  theCurrentPos = xqp_integer::parseInt(0);
  thePosition   = xqp_integer::parseInt(0);
}

void
FnRemoveIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurrentPos = xqp_integer::parseInt(0);
  thePosition = xqp_integer::parseInt(0);
}


//15.1.9 fn:reverse
Item_t FnReverseIterator::nextImpl(PlanState& planState)
{
  Item_t iVal;

  FnReverseIteratorState *state;
  DEFAULT_STACK_INIT(FnReverseIteratorState, state, planState);

  while((iVal = consumeNext(theChildren[0], planState)) != NULL) {
    state->theStack.push(iVal);
  }

  while(!state->theStack.empty()) {
    iVal = state->theStack.top();
    state->theStack.pop();
    STACK_PUSH(iVal, state);
  }

  STACK_END();
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
Item_t 
FnSubsequenceIterator::nextImpl(PlanState& planState) {
  Item_t lSequence;
  Item_t lStartingLoc;
  Item_t lLength;

  FnSubsequenceIteratorState* state;
  DEFAULT_STACK_INIT(FnSubsequenceIteratorState, state, planState);
  
  lStartingLoc = consumeNext(theChildren[1], planState);
  if ( lStartingLoc == NULL ) 
  {
    ZORBA_ERROR_ALERT(
         ZorbaError::FORG0006, &loc, DONT_CONTINUE_EXECUTION,
         "An empty sequence is not allowed as starting location of fn:subsequence.");    
  }
  
  state->theStartingLoc = lStartingLoc->getDoubleValue();
  if (state->theStartingLoc < xqp_double::parseInt(0))
    state->theStartingLoc = xqp_double::parseInt(0);
    
  if (theChildren.size() == 3)
  {
    lLength = consumeNext(theChildren[2], planState);
    if ( lLength == NULL )
    {
      ZORBA_ERROR_ALERT( ZorbaError::FORG0006, &loc, DONT_CONTINUE_EXECUTION,
           "An empty sequence is not allowed as third argument of fn:subsequence.");
    }
    state->theLength = lLength->getDoubleValue();
  }
  else
  {
    state->theLength = xqp_double::parseInt(-1);
  }
  
  while ( ((lSequence = consumeNext(theChildren[0], planState)) != NULL) 
          && (( state->theLength == xqp_double::parseInt(-1) ) || ( state->theCurrentLength <= state->theLength  )))
  {
    if (state->theCurrentPos >= state->theStartingLoc)
    {
      ++state->theCurrentLength;
      STACK_PUSH(lSequence, state);
    }
    
    ++state->theCurrentPos; 
  }

  STACK_END();
}

void
FnSubsequenceIteratorState::init(PlanState& planState) 
{
 PlanIteratorState::init(planState);
 theStartingLoc = xqp_double::parseInt(0);
 theLength = xqp_double::parseInt(0);
 theCurrentPos = xqp_integer::parseInt(1); // position starts with 1, not 0
 theCurrentLength = xqp_integer::parseInt(1);
}

void
FnSubsequenceIteratorState::reset(PlanState& planState) 
{
 PlanIteratorState::reset(planState);
 theStartingLoc = xqp_double::parseInt(0);
 theLength = xqp_double::parseInt(0);
 theCurrentPos = xqp_integer::parseInt(1); // position starts with 1, not 0
 theCurrentLength = xqp_integer::parseInt(1);
}


//15.1.11 fn:unordered


/*______________________________________________________________________
|  
| 15.2 Functions That Test the Cardinality of Sequences
|_______________________________________________________________________*/

//15.2.1 fn:zero-or-one
Item_t 
FnZeroOrOneIterator::nextImpl(PlanState& planState) {
  Item_t lFirstSequenceItem;
  Item_t lNextSequenceItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  lFirstSequenceItem = consumeNext(theChildren[0], planState);
  if (lFirstSequenceItem != NULL)
  {
    lNextSequenceItem = consumeNext(theChildren[0], planState);
    if (lNextSequenceItem != NULL)
    {
      ZORBA_ERROR_ALERT(ZorbaError::FORG0003, 
        &loc, DONT_CONTINUE_EXECUTION, "fn:zero-or-one called with a sequence containing more than one item."); 

    }
    STACK_PUSH(lFirstSequenceItem, state);
  }
  STACK_END();
}



//15.2.2 fn:one-or-more
Item_t 
FnOneOrMoreIterator::nextImpl(PlanState& planState) {
  Item_t lSequenceItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  lSequenceItem = consumeNext(theChildren[0], planState);
  if (lSequenceItem == NULL)
  {
    ZORBA_ERROR_ALERT(ZorbaError::FORG0004,
        &loc, DONT_CONTINUE_EXECUTION, "fn:one-or-more called with a sequence containing no items.");
  }
  do
  {
    STACK_PUSH(lSequenceItem, state);
  } while ( (lSequenceItem = consumeNext(theChildren[0], planState)) != NULL );

  STACK_END();
}

//15.2.3 fn:exactly-one
Item_t 
FnExactlyOneIterator::nextImpl(PlanState& planState) {
  Item_t lFirstItem;
  Item_t lNextItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  lFirstItem = consumeNext(theChildren[0], planState);
  lNextItem = consumeNext(theChildren[0], planState);
  if ( lFirstItem == NULL || lNextItem != NULL )
  {
    ZORBA_ERROR_ALERT(ZorbaError::FORG0005,
        &loc, DONT_CONTINUE_EXECUTION, "fn:exactly-one called with a sequence containing zero or more than one item.");
  }

  STACK_PUSH(lFirstItem, state);

  STACK_END();
}


/*______________________________________________________________________
|
| 15.3 Equals, Union, Intersection and Except
|_______________________________________________________________________*/

//15.3.1 fn:deep-equal

//15.3.2 op:union

//15.3.3 op:intersect

//15.3.4 op:except


/*______________________________________________________________________
|
| 15.4 Aggregate Functions
|_______________________________________________________________________*/

//15.4.1 fn:count
Item_t 
FnCountIterator::nextImpl(PlanState& planState) {
  Item_t lSequenceItem;
  xqp_integer lCount = Integer::parseInt(0);

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while ( (lSequenceItem = consumeNext(theChildren[0], planState)) != NULL )
  {
    ++lCount;
  }

  STACK_PUSH(Zorba::getItemFactory()->createInteger(lCount), state);

  STACK_END();
}

//15.4.2 fn:avg
Item_t 
FnAvgIterator::nextImpl(PlanState& planState) {
  Item_t lSumItem;
  Item_t lRunningItem;
  xqp_integer lCount = Integer::parseInt(1);

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  lSumItem = consumeNext(theChildren[0], planState);
  if (lSumItem != NULL) // return empty-sequence if input is empty
  {
    while ( (lRunningItem = consumeNext(theChildren[0], planState)) != NULL )
    {
      // TODO add datetime
      if (lRunningItem->isNumeric() && lRunningItem->isNaN()) {
        lSumItem = lRunningItem;
        break;
      }
      lSumItem = ArithmeticIterator<AddOperations>::compute(loc, lSumItem, lRunningItem); 
      ++lCount;
    }

    STACK_PUSH(ArithmeticIterator<DivideOperations>::compute(loc, lSumItem, 
               Zorba::getItemFactory()->createInteger(lCount)), state);
  }

  STACK_END();
}

//15.4.3 fn:max & 15.4.4 fn:min
FnMinMaxIterator::FnMinMaxIterator
  (yy::location loc, std::vector<PlanIter_t>& aChildren, Type aType)
  : NaryBaseIterator<FnMinMaxIterator, PlanIteratorState>(loc, aChildren), 
    theType(aType),
    theCompareType(
       (aType == MIN 
       ? CompareIterator::VALUE_LESS 
       : CompareIterator::VALUE_GREATER)) 
{ }

Item_t 
FnMinMaxIterator::nextImpl(PlanState& planState) {
  Item_t lMaxItem;
  Item_t lRunningItem;
  xqtref_t lMaxType;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (theChildren.size() == 3)
    assert(false);

  lMaxItem = 0;
  lRunningItem = consumeNext(theChildren[0], planState);
  if ( lRunningItem != NULL )
  {
    do {
      // casting of untyped atomic
      xqtref_t lRunningType = GENV_TYPESYSTEM.create_type(lRunningItem->getType(),TypeConstants::QUANT_ONE);
      if (GENV_TYPESYSTEM.is_subtype(*lRunningType, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)) {
        lRunningItem = GenericCast::instance()->cast(lRunningItem, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
        lRunningType = GENV_TYPESYSTEM.DOUBLE_TYPE_ONE;
      }

      // FIXME collation support
      // implementation dependent: return the first occurence)
      if (lRunningItem->isNumeric() && lRunningItem->isNaN()) {
        /** It must be checked if the sequence contains any 
         * xs:double("NaN") [xs:double("NaN") is returned] or 
         * only xs:float("NaN")'s [xs:float("NaN") is returned]'.
         */
        lMaxItem = lRunningItem;
        if (GENV_TYPESYSTEM.is_subtype(*lRunningType, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE))
          break;

        lMaxType = GENV_TYPESYSTEM.create_type(lMaxItem->getType(), TypeConstants::QUANT_ONE);
      }
      if (lMaxItem != 0) {
        // Type Promotion
        Item_t lItemCur = GenericCast::instance()->promote(lRunningItem, lMaxType);
        if (lItemCur == 0) {
          lItemCur = GenericCast::instance()->promote(lMaxItem, lRunningType); 
          if (lItemCur != 0) {
            lMaxItem = lItemCur;
            lMaxType = GENV_TYPESYSTEM.create_type(lMaxItem->getType(), TypeConstants::QUANT_ONE);
          } else {
            ZORBA_ERROR_ALERT(ZorbaError::FORG0006, &loc, DONT_CONTINUE_EXECUTION, "Promote not possible");
          }
        } else {
          lRunningItem = lItemCur;
          lRunningType = GENV_TYPESYSTEM.create_type(lRunningItem->getType(), TypeConstants::QUANT_ONE);
        }
        if (CompareIterator::valueComparison(lRunningItem, lMaxItem, 
                                           theCompareType) ) {
          lMaxType = lRunningType;
          lMaxItem = lRunningItem;
        }
      } else {
        lMaxType = lRunningType;
        lMaxItem = lRunningItem;
      }
    } while ((lRunningItem = consumeNext(theChildren[0], planState)) != NULL);
    STACK_PUSH(lMaxItem, state);
  }

  STACK_END();
}


//15.4.5 fn:sum
Item_t 
FnSumIterator::nextImpl(PlanState& planState) {
  Item_t lSumItem;
  Item_t lRunningItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  lSumItem = consumeNext(theChildren[0], planState);
  if (lSumItem != NULL) // return 0 or given value if empty sequence
  {
    while ( (lRunningItem = consumeNext(theChildren[0], planState)) != NULL )
    {
      // TODO add datetime
      lSumItem = ArithmeticIterator<AddOperations>::compute(loc, lSumItem, lRunningItem); 
      // TODO break if one item is NaN
    }

    STACK_PUSH(lSumItem, state);
  }
  else
  {
    if (theChildren.size() == 2)
    {
      lSumItem = consumeNext(theChildren[1], planState);
      if (lSumItem != NULL)
      {
        STACK_PUSH(lSumItem, state);
      }
      // return the empty sequence otherwise
    }
    else
    {
      STACK_PUSH(Zorba::getItemFactory()->createInteger(Integer::parseInt((int32_t)0)), state);
    }
  }

  STACK_END();
}


/*______________________________________________________________________
|
| 15.5 Functions and Operators that Generate Sequences
|_______________________________________________________________________*/

//15.5.1 op:to
Item_t 
OpToIterator::nextImpl(PlanState& planState) {
  Item_t lItem;
  
  OpToIteratorState* state;
  DEFAULT_STACK_INIT(OpToIteratorState, state, planState);

  lItem = consumeNext(theChildren[0], planState);
  if (lItem == NULL)
  {
    ZorbaAlertFactory::error_alert (ZorbaError::XPTY0004, NULL,
        DONT_CONTINUE_EXECUTION, "The empty sequence is not allowed as first argument to op:to.");

  }
  state->theFirstVal = lItem->getIntegerValue();

  lItem = consumeNext(theChildren[1], planState);
  if (lItem == NULL)
  {
    ZorbaAlertFactory::error_alert (ZorbaError::XPTY0004, NULL,DONT_CONTINUE_EXECUTION,
        "The empty sequence is not allowed as second argument to op:to.");

  }
  state->theLastVal = lItem->getIntegerValue();

  // return empty sequence otherwise
  if ( state->theLastVal >= state->theFirstVal )
  {
    state->theCurInt = state->theFirstVal;
    while ( state->theCurInt <= state->theLastVal )
    {
      STACK_PUSH(Zorba::getItemFactory()->createInteger(state->theCurInt), state);
      ++state->theCurInt;
    }

  }

  STACK_END();
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

//15.5.3 fn:idref



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

FnDocIterator::FnDocIterator(yy::location loc, PlanIter_t& arg)
  :
  UnaryBaseIterator<FnDocIterator, PlanIteratorState> ( loc, arg )
{
}


FnDocIterator::~FnDocIterator()
{
}


Item_t FnDocIterator::nextImpl(PlanState& planState)
{
  Store& store = Store::getInstance();

  Item_t doc;
  Item_t uriItem;
  xqpStringStore* uriString;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  uriItem = consumeNext(theChild, planState);
  if (uriItem == NULL)
    return NULL;

  uriString = uriItem->getStringValue().getStore();

  doc = store.getDocument(uriString);
    
  if (doc == NULL)
  {
    xqp_string uriCopy = uriString;

    if (uriCopy.lowercase().indexOf("http://") == 0)
    {
      // retrieve web file
      xqp_string xmlString;
      int result = http_get(uriCopy.c_str(), xmlString);
      if (result != 0)
      {
        ZORBA_ERROR_ALERT_OSS(ZorbaError::FODC0002, &loc, DONT_CONTINUE_EXECUTION, uriString->c_str(),
                              "HTTP get failure.");
      }

      istringstream iss(xmlString.c_str());

      doc = store.loadDocument(uriString, iss);
      if (doc == NULL)
      {
        ZORBA_ERROR_ALERT_OSS(ZorbaError::FODC0002, &loc, DONT_CONTINUE_EXECUTION, uriString->c_str(),
                              "Failed to parse document.");
      }
    }
    else 
    {
      // load file
      ifstream ifs;
      ifs.open(uriString->c_str(), ios::in);
      if (ifs.is_open() == false)
      {
        ZORBA_ERROR_ALERT_OSS(ZorbaError::FODC0002, &loc, DONT_CONTINUE_EXECUTION, uriString->c_str(),
                              "File does not exist.");
      }
      
      doc = store.loadDocument(uriString, ifs);
      if (doc == NULL)
      {
        ZORBA_ERROR_ALERT_OSS(ZorbaError::FODC0002, &loc, DONT_CONTINUE_EXECUTION, uriString->c_str(),
                              "Failed to parse document.");
      }
    }
  }

  STACK_PUSH(doc, state);
  STACK_END();
}


} /* namespace xqp */
/* vim:set ts=2 sw=2: */
