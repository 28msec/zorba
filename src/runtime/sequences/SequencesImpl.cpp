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
#include "store/naive/simple_loader.h"
#include "store/api/collection.h"
#include "store/naive/store_defs.h"
#include "errors/Error.h"
#include "runtime/visitors/planitervisitor.h"
#include "util/web/web.h"

#include "system/globalenv.h"
#include "types/casting.h"

using namespace std;
namespace xqp {
  

/*______________________________________________________________________
|  
| 15.1 General Functions and Operators on Sequences
|_______________________________________________________________________*/


//15.1.2 op:concatenate 
//---------------------

FnConcatIterator::FnConcatIterator(
  yy::location loc,
  vector<PlanIter_t>& aChildren)
:
  NaryBaseIterator<FnConcatIterator>(loc, aChildren)
{}

FnConcatIterator::~FnConcatIterator(){}

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

void 
FnConcatIterator::resetImpl(PlanState& planState) {
  FnConcatIteratorState* state;
  GET_STATE(FnConcatIteratorState, state, planState);
  state->reset();
  
  std::vector<PlanIter_t>::iterator iter = theChildren.begin();
  for(; iter != theChildren.end(); ++iter) {
    this->resetChild(*iter, planState);
  }
}

void
FnConcatIterator::FnConcatIteratorState::init() {
  PlanIterator::PlanIteratorState::init();
  theCurIter = 0;
}

void
FnConcatIterator::FnConcatIteratorState::reset() {
  PlanIterator::PlanIteratorState::reset();
  theCurIter = 0;
}

//15.1.3 fn:index-of
// FIXME this iterator has three arguments (i.e. the collaction as #3)
FnIndexOfIterator::FnIndexOfIterator(yy::location loc,
                                    PlanIter_t& arg1,
                                    PlanIter_t& arg2,
                                    std::string collation)
 : BinaryBaseIterator<FnIndexOfIterator> ( loc, arg1, arg2 )
{ }

FnIndexOfIterator::~FnIndexOfIterator(){}

Item_t 
FnIndexOfIterator::nextImpl(PlanState& planState) {
  Item_t lSequenceItem;
  int8_t lCmpRes;

  FnIndexOfIteratorState* state;
  DEFAULT_STACK_INIT(FnIndexOfIteratorState, state, planState);
  
  state->theSearchItem = consumeNext(theChild1, planState);
  if ( state->theSearchItem == NULL ) 
  {
    ZORBA_ERROR_ALERT(
         error_messages::FORG0006_INVALID_ARGUMENT_TYPE,
         error_messages::RUNTIME_ERROR,
         NULL, false,
         "An empty sequence is not allowed as search item of fn:index-of");    
  }

  while ( (lSequenceItem = consumeNext(theChild0, planState)) != NULL )
  {
    // inc the position in the sequence; do it at the beginning of the loop because index-of starts with one
    ++state->theCurrentPos; 
    
    // The items in the sequence theChild0 are compared with theSearchItem under the rules for the eq operator. 
    // Values of type xs:untypedAtomic are compared as if they were of type xs:string. 
    // Values that cannot be compared, i.e. the eq operator is not defined for their types, are considered to be distinct. 
    // If an item compares equal, then the position of that item in the sequence $seqParam is included in the result.
    lCmpRes = CompareIterator::valueCompare(lSequenceItem, state->theSearchItem);
    if ( lCmpRes == 0 ) // FIXME collation support
      STACK_PUSH(zorba::getItemFactory()->createInteger(state->theCurrentPos), state);
  }

  STACK_END();
}


uint32_t
FnIndexOfIterator::getStateSizeOfSubtree() const 
{
 return theChild0->getStateSizeOfSubtree() 
        + theChild1->getStateSizeOfSubtree() + getStateSize();
}

void 
FnIndexOfIterator::releaseResourcesImpl(PlanState& planState)
{
  BinaryBaseIterator<FnIndexOfIterator>::releaseResourcesImpl(planState);
  
  FnIndexOfIteratorState* state;
  GET_STATE(FnIndexOfIteratorState, state, planState);
  
  // do we need a releaseResouces function in the state or is it always the same as reset?
  state->reset(); 
}

void 
FnIndexOfIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  BinaryBaseIterator<FnIndexOfIterator>::setOffset(planState, offset);

  FnIndexOfIteratorState* state = 
    new (planState.block + stateOffset) FnIndexOfIteratorState;
}

void 
FnIndexOfIterator::resetImpl(PlanState& planState)
{
  BinaryBaseIterator<FnIndexOfIterator>::resetImpl(planState);

  FnIndexOfIteratorState* state;
  GET_STATE(FnIndexOfIteratorState, state, planState);
  state->reset();
}


void
FnIndexOfIterator::FnIndexOfIteratorState::init() 
{
 PlanIterator::PlanIteratorState::init();
 theCurrentPos = 0;
 theSearchItem = NULL;
}

void
FnIndexOfIterator::FnIndexOfIteratorState::reset() {
 PlanIterator::PlanIteratorState::reset();
 theCurrentPos = 0;
 theSearchItem = NULL;
}


//15.1.4 fn:empty
/*
 * If the value of $arg is the empty sequence, the function returns true; 
 * otherwise, the function returns false.
 */
FnEmptyIterator::FnEmptyIterator(yy::location loc,
                               PlanIter_t& arg)
  : UnaryBaseIterator<FnEmptyIterator> ( loc, arg )
{ }

FnEmptyIterator::~FnEmptyIterator(){}

Item_t 
FnEmptyIterator::nextImpl(PlanState& planState) {
  Item_t item;

  PlanIterator::PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIterator::PlanIteratorState, state, planState);

  item = consumeNext(theChild, planState);
  if (item == NULL) 
  {
    STACK_PUSH (zorba::getItemFactory()->createBoolean ( true ), state);
  }
  else
  {
    STACK_PUSH (zorba::getItemFactory()->createBoolean ( false ), state);   
  }

  STACK_END();
}

//15.1.5 fn:exists
/*
 * If the value of $arg is not the empty sequence, the function returns true; 
 * otherwise, the function returns false.
 */
FnExistsIterator::FnExistsIterator(yy::location loc,
                                   PlanIter_t& arg)
  : UnaryBaseIterator<FnExistsIterator> ( loc, arg )
{ }

FnExistsIterator::~FnExistsIterator(){}

Item_t 
FnExistsIterator::nextImpl(PlanState& planState) {
  Item_t item;
  
  PlanIterator::PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIterator::PlanIteratorState, state, planState);
  
  item = consumeNext(theChild, planState);
  if (item != NULL) 
  {
    STACK_PUSH (zorba::getItemFactory()->createBoolean ( true ), state);
  }
  else
  {
    STACK_PUSH (zorba::getItemFactory()->createBoolean ( false ), state);   
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
                                                   PlanIter_t& arg,
                                                   std::string collation)
 : UnaryBaseIterator<FnDistinctValuesIterator> ( loc, arg )
{ }

FnDistinctValuesIterator::~FnDistinctValuesIterator(){}

Item_t 
FnDistinctValuesIterator::nextImpl(PlanState& planState) {
  Item_t lItem;
  FnDistinctValuesIteratorState::AlreadySeenConstIter_t lConstIter;
  
  FnDistinctValuesIteratorState* state;
  DEFAULT_STACK_INIT(FnDistinctValuesIteratorState, state, planState);
      
  while ( (lItem = consumeNext(theChild, planState)) != NULL )
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

uint32_t
FnDistinctValuesIterator::getStateSizeOfSubtree() const 
{
  return theChild->getStateSizeOfSubtree() + getStateSize();
}

void 
FnDistinctValuesIterator::releaseResourcesImpl(PlanState& planState)
{
  UnaryBaseIterator<FnDistinctValuesIterator>::releaseResourcesImpl(planState);
  
  FnDistinctValuesIteratorState* state;
  GET_STATE(FnDistinctValuesIteratorState, state, planState);
  
  // do we need a releaseResouces function in the state or is it always the same as reset?
  state->reset(); 
}

void 
FnDistinctValuesIterator::resetImpl(PlanState& planState)
{
  UnaryBaseIterator<FnDistinctValuesIterator>::resetImpl(planState);

  FnDistinctValuesIteratorState* state;
  GET_STATE(FnDistinctValuesIteratorState, state, planState);
  state->reset();
}

void 
FnDistinctValuesIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  UnaryBaseIterator<FnDistinctValuesIterator>::setOffset(planState, offset);

  FnDistinctValuesIteratorState* state = 
    new (planState.block + stateOffset) FnDistinctValuesIteratorState;
}

bool 
FnDistinctValuesIterator::ItemCmp::operator() ( 
  const Item_t& i1, const Item_t& i2) const
{
  return CompareIterator::compare(i1, i2)<0?true:false;
}

void
FnDistinctValuesIterator::FnDistinctValuesIteratorState::init() 
{
 PlanIterator::PlanIteratorState::init();
}

void
FnDistinctValuesIterator::FnDistinctValuesIteratorState::reset() {
 PlanIterator::PlanIteratorState::reset();
 theAlreadySeenMap.clear();
}


//15.1.7 fn:insert-before
FnInsertBeforeIterator::FnInsertBeforeIterator(yy::location loc,
                                              vector<PlanIter_t>& aChildren)
  : NaryBaseIterator<FnInsertBeforeIterator>(loc, aChildren)
{}

FnInsertBeforeIterator::~FnInsertBeforeIterator(){}

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
 if (state->thePosition < 1)
   state->thePosition = 1;
   
  
 while ( (state->theTargetItem = consumeNext(theChildren[0], planState)) != NULL ) 
 {
    if ( state->theCurrentPos == state->thePosition-1 ) // position found => insert sequence
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
FnInsertBeforeIterator::resetImpl(PlanState& planState) {
 NaryBaseIterator<FnInsertBeforeIterator>::resetImpl(planState);

 FnInsertBeforeIteratorState* state;
 GET_STATE(FnInsertBeforeIteratorState, state, planState);
 state->reset();
}

void 
FnInsertBeforeIterator::releaseResourcesImpl(PlanState& planState)
{
  NaryBaseIterator<FnInsertBeforeIterator>::releaseResourcesImpl(planState);
  
  FnInsertBeforeIteratorState* state;
  GET_STATE(FnInsertBeforeIteratorState, state, planState);
  
  // do we need a releaseResouces function in the state or is it always the same as reset?
  state->reset(); 
}


void
FnInsertBeforeIterator::FnInsertBeforeIteratorState::init() {
 PlanIterator::PlanIteratorState::init();
 theCurrentPos = 0;
 thePosition = 0;
 theTargetItem = NULL;
}

void
FnInsertBeforeIterator::FnInsertBeforeIteratorState::reset() {
 PlanIterator::PlanIteratorState::reset();
 theCurrentPos = 0;
 thePosition = 0; 
 theTargetItem = NULL;
}


//15.1.8 fn:remove
// FIXME this iterator has three arguments (i.e. the collaction as #3)
FnRemoveIterator::FnRemoveIterator(yy::location loc,
                                    PlanIter_t& arg1,
                                    PlanIter_t& arg2)
 : BinaryBaseIterator<FnRemoveIterator> ( loc, arg1, arg2 )
{ }

FnRemoveIterator::~FnRemoveIterator(){}

Item_t 
FnRemoveIterator::nextImpl(PlanState& planState) {
  Item_t lSequenceItem;
  Item_t lPositionItem;

  FnRemoveIteratorState* state;
  DEFAULT_STACK_INIT(FnRemoveIteratorState, state, planState);
  
  lPositionItem = consumeNext(theChild1, planState);
  if ( lPositionItem == NULL ) 
  {
    ZORBA_ERROR_ALERT(
         error_messages::FORG0006_INVALID_ARGUMENT_TYPE,
         error_messages::RUNTIME_ERROR,
         NULL, false,
         "An empty sequence is not allowed as second argument to of fn:remove");    
  }

  state->thePosition = lPositionItem->getIntegerValue();

  while ( (lSequenceItem = consumeNext(theChild0, planState)) != NULL )
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
FnRemoveIterator::releaseResourcesImpl(PlanState& planState)
{
  BinaryBaseIterator<FnRemoveIterator>::releaseResourcesImpl(planState);
  
  FnRemoveIteratorState* state;
  GET_STATE(FnRemoveIteratorState, state, planState);

  state->reset(); 
}

void 
FnRemoveIterator::resetImpl(PlanState& planState)
{
  BinaryBaseIterator<FnRemoveIterator>::resetImpl(planState);

  FnRemoveIteratorState* state;
  GET_STATE(FnRemoveIteratorState, state, planState);
  state->reset();
}


void
FnRemoveIterator::FnRemoveIteratorState::init() 
{
 PlanIterator::PlanIteratorState::init();
 theCurrentPos = 0;
 thePosition   = 0;
}

void
FnRemoveIterator::FnRemoveIteratorState::reset() {
 PlanIterator::PlanIteratorState::reset();
 theCurrentPos = 0;
 thePosition   = 0;
}


//15.1.9 fn:reverse

//15.1.10 fn:subsequence
FnSubsequenceIterator::FnSubsequenceIterator(yy::location loc,
                                            vector<PlanIter_t>& args)
 : NaryBaseIterator<FnSubsequenceIterator> ( loc, args )
{ }

FnSubsequenceIterator::~FnSubsequenceIterator(){}

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
         error_messages::FORG0006_INVALID_ARGUMENT_TYPE,
         error_messages::RUNTIME_ERROR,
         NULL, false,
         "An empty sequence is not allowed as starting location of fn:subsequence");    
  }
  
  state->theStartingLoc = lStartingLoc->getDoubleValue();
  if (state->theStartingLoc < 0)
    state->theStartingLoc = 0;
    
  if (theChildren.size() == 3)
  {
    lLength = consumeNext(theChildren[2], planState);
    if ( lLength == NULL )
    {
      ZORBA_ERROR_ALERT(
           error_messages::FORG0006_INVALID_ARGUMENT_TYPE,
           error_messages::RUNTIME_ERROR,
           NULL, false,
           "An empty sequence is not allowed as third argument of fn:subsequence");          
    }
    state->theLength = lLength->getDoubleValue();
  }
  else
  {
    state->theLength = -1;
  }
  
  while ( ((lSequence = consumeNext(theChildren[0], planState)) != NULL) 
          && (( state->theLength == -1 ) || ( state->theCurrentLength <= state->theLength  )))
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
FnSubsequenceIterator::releaseResourcesImpl(PlanState& planState)
{
  NaryBaseIterator<FnSubsequenceIterator>::releaseResourcesImpl(planState);
  
  FnSubsequenceIteratorState* state;
  GET_STATE(FnSubsequenceIteratorState, state, planState);
  
  state->reset(); 
}

void 
FnSubsequenceIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  NaryBaseIterator<FnSubsequenceIterator>::setOffset(planState, offset);

  FnSubsequenceIteratorState* state = 
    new (planState.block + stateOffset) FnSubsequenceIteratorState;
}

void 
FnSubsequenceIterator::resetImpl(PlanState& planState)
{
  NaryBaseIterator<FnSubsequenceIterator>::resetImpl(planState);

  FnSubsequenceIteratorState* state;
  GET_STATE(FnSubsequenceIteratorState, state, planState);
  state->reset();
}


void
FnSubsequenceIterator::FnSubsequenceIteratorState::init() 
{
 PlanIterator::PlanIteratorState::init();
 theStartingLoc = 0;
 theLength = 0;
 theCurrentPos = 1; // position starts with 1, not 0
 theCurrentLength = 1;
}

void
FnSubsequenceIterator::FnSubsequenceIteratorState::reset() 
{
 PlanIterator::PlanIteratorState::reset();
 theStartingLoc = 0;
 theLength = 0;
 theCurrentPos = 1; // position starts with 1, not 0
 theCurrentLength = 1;
}


//15.1.11 fn:unordered


/*______________________________________________________________________
|  
| 15.2 Functions That Test the Cardinality of Sequences
|_______________________________________________________________________*/

//15.2.1 fn:zero-or-one
FnZeroOrOneIterator::FnZeroOrOneIterator(yy::location loc,
                                         PlanIter_t& aChild)
 : UnaryBaseIterator<FnZeroOrOneIterator> ( loc, aChild )
{ }

FnZeroOrOneIterator::~FnZeroOrOneIterator(){}

Item_t 
FnZeroOrOneIterator::nextImpl(PlanState& planState) {
  Item_t lFirstSequenceItem;
  Item_t lNextSequenceItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  lFirstSequenceItem = consumeNext(theChild, planState);
  if (lFirstSequenceItem != NULL)
  {
    lNextSequenceItem = consumeNext(theChild, planState);
    if (lNextSequenceItem != NULL)
    {
      ZORBA_ERROR_ALERT(error_messages::FODC0003_Function_stability_not_defined,                                                                          error_messages::RUNTIME_ERROR, 
                        NULL, false, "fn:zero-or-one called with a sequence containing more than one item"); 
    }
    STACK_PUSH(lFirstSequenceItem, state);
  }
  STACK_END();
}



//15.2.2 fn:one-or-more
FnOneOrMoreIterator::FnOneOrMoreIterator(yy::location loc,
                                         PlanIter_t& aChild)
 : UnaryBaseIterator<FnOneOrMoreIterator> ( loc, aChild )
{ }

FnOneOrMoreIterator::~FnOneOrMoreIterator(){}

Item_t 
FnOneOrMoreIterator::nextImpl(PlanState& planState) {
  Item_t lSequenceItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  lSequenceItem = consumeNext(theChild, planState);
  if (lSequenceItem == NULL)
  {
    ZORBA_ERROR_ALERT(error_messages::FODC0004_Invalid_argument_to_fn_collection,
                      error_messages::RUNTIME_ERROR, 
                      NULL, false, "fn:one-or-more called with a sequence containing no items.");
  }
  do
  {
    STACK_PUSH(lSequenceItem, state);
  } while ( (lSequenceItem = consumeNext(theChild, planState)) != NULL );

  STACK_END();
}

//15.2.3 fn:exactly-one
FnExactlyOneIterator::FnExactlyOneIterator(yy::location loc,
                                           PlanIter_t& aChild)
 : UnaryBaseIterator<FnExactlyOneIterator> ( loc, aChild )
{ }

FnExactlyOneIterator::~FnExactlyOneIterator(){}

Item_t 
FnExactlyOneIterator::nextImpl(PlanState& planState) {
  Item_t lFirstItem;
  Item_t lNextItem;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  lFirstItem = consumeNext(theChild, planState);
  lNextItem = consumeNext(theChild, planState);
  if ( lFirstItem == NULL || lNextItem != NULL )
  {
    ZORBA_ERROR_ALERT(error_messages::FODC0005_Invalid_argument_to_fn_doc_or_fn_doc_available,
                      error_messages::RUNTIME_ERROR, 
                      NULL, false, "fn:exactly-one called with a sequence containing zero or more than one item.");
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

//15.4.2 fn:avg

//15.4.3 fn:max

//15.4.4 fn:min

//15.4.5 fn:sum


/*______________________________________________________________________
|
| 15.5 Functions and Operators that Generate Sequences
|_______________________________________________________________________*/

//15.5.1 op:to

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

FnDocIterator::FnDocIterator (
    yy::location loc, PlanIter_t& arg)
    :
    UnaryBaseIterator<FnDocIterator> ( loc, arg )
{
}

FnDocIterator::~FnDocIterator() {}

Item_t
FnDocIterator::nextImpl ( PlanState& planState )
{
  Item_t item, xml;

  FnDocIteratorState* state;
  DEFAULT_STACK_INIT ( FnDocIteratorState, state, planState );

  item = consumeNext(theChild, planState);

  if (!state->got_doc || item->getStringValue() != state->uri)
  {
    state->uri = item->getStringValue();
    SimpleStore& store = GET_STORE();
    state->collection = store.getCollection(item);
    
    if (state->collection != NULL)
    {
      state->childrenIter = state->collection->getIterator(true);
      state->got_doc = 2;
    }
    else if(state->uri.lowercase().indexOf("http://") == 0)
    {
      // retrieve web file
      xqp_string result;
      int result_code = http_get(state->uri.c_str(), result);

      if (result_code != 0)
      {
         // File does not exist
        ZORBA_ERROR_ALERT(error_messages::FODC0002_Error_retrieving_resource,
                          error_messages::RUNTIME_ERROR,
                          NULL,
                          false,
                          "Could not retrieve resource");
      }

      istringstream iss(result.getStore().c_str());
      XmlLoader& loader = store.getXmlLoader();
      state->doc = loader.loadXml(iss);
      state->childrenIter = state->doc->getChildren();
      state->got_doc = 1;
    }
    else 
    {
      // load file
      ifstream ifs;
      ifs.open(((string)state->uri).c_str(), ios::in);
      if (ifs.is_open() == false)
      {
        // File does not exist
        ZORBA_ERROR_ALERT(error_messages::FODC0002_Error_retrieving_resource,
                          error_messages::RUNTIME_ERROR,
                          NULL,
                          false,
                          "The file does not exist");
      }

      XmlLoader& loader = store.getXmlLoader();
      state->doc = loader.loadXml(ifs);
      state->childrenIter = state->doc->getChildren();
      state->got_doc = 1;
    }
  }

  do
  {
    item = state->childrenIter->next();
    if (item != NULL)
      STACK_PUSH(item, state);
  }
  while (item != NULL);
  
  STACK_END();
}

uint32_t
FnDocIterator::getStateSize() const {
  return sizeof(FnDocIteratorState);
}

FnDocIterator::FnDocIteratorState::FnDocIteratorState()
  :
  got_doc(0)
{
}

void
FnDocIterator::FnDocIteratorState::init()
{
  PlanIterator::PlanIteratorState::init();
  if (got_doc == 1)
    childrenIter = doc->getChildren();
  else if (got_doc == 2)
    childrenIter = collection->getIterator(true);
}

void
FnDocIterator::FnDocIteratorState::reset()
{
  PlanIterator::PlanIteratorState::reset();
  got_doc = 0;
}

//15.5.5 fn:doc-available

//15.5.6 fn:collection


} /* namespace xqp */

