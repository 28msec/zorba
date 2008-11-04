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
#include "zorbautils/fatal.h"
#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_manager.h"

#include "compiler/expression/expr.h"
#include "runtime/core/flwor_iterator.h"
#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "runtime/core/var_iterators.h"
#include "runtime/api/runtimecb.h"
#include "store/api/temp_seq.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/visitors/planitervisitor.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "system/globalenv.h"
#include "store/api/store.h"
#include "store/api/pul.h"
#include "store/api/item_factory.h"
#include "context/collation_cache.h"


namespace zorba
{

  // Utility function -- is this item null or a NaN?
static bool empty_item (RuntimeCB* aRuntimeCB, store::Item_t s)
{
  return (s == 0) || (s->isNaN());
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ForLetClause                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


FLWORIterator::ForLetClause::ForLetClause(
    const var_expr* var,
    std::vector<ForVarIter_t> aForVars,
    PlanIter_t& aInput)
  :
#ifndef NDEBUG
  theVarName(var->get_varname()->getStringValue()->c_str()),
#endif
  theType ( FOR ),
  theForVars ( aForVars ),
  theInput ( aInput )
{ }


FLWORIterator::ForLetClause::ForLetClause (
    const var_expr* var,
    std::vector<ForVarIter_t> aForVars,
    std::vector<ForVarIter_t> aPosVars,
    PlanIter_t& aInput )
  :
#ifndef NDEBUG
  theVarName(var->get_varname()->getStringValue()->c_str()),
#endif
  theType ( FOR ),
  theForVars ( aForVars ),
  thePosVars ( aPosVars ),
  theInput ( aInput )
{
}


FLWORIterator::ForLetClause::ForLetClause (
    const var_expr* var,
    std::vector<LetVarIter_t> aLetVars,
    PlanIter_t& aInput,
    bool aNeedsMaterialization )
  :
#ifndef NDEBUG
  theVarName(var->get_varname()->getStringValue()->c_str()),
#endif
  theType(LET),
  theLetVars(aLetVars),
  theInput(aInput),
  theNeedsMaterialization(aNeedsMaterialization)
{
}


void FLWORIterator::ForLetClause::accept ( PlanIterVisitor& v ) const
{
  // TODO correct for visitor
  switch ( theType )
  {
  case FOR:
    v.beginVisitFlworForVariable(*theInput, getVarName(), theForVars);
    v.endVisitFlworForVariable(*theInput);
    break;
  case LET:
    v.beginVisitFlworLetVariable(*theInput, theNeedsMaterialization, getVarName());
    v.endVisitFlworLetVariable(*theInput);
    break;
  default:
    ZORBA_ASSERT ( false );
  }
}


xqpStringStore FLWORIterator::ForLetClause::getVarName() const
{
#ifndef NDEBUG
  return theVarName;
#else
  return std::string("");
#endif
}

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GroupByClause                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////



FLWORIterator::GroupingOuterVar::GroupingOuterVar(
  PlanIter_t aInput, 
  std::vector<LetVarIter_t> aOuterVars)
  : theInput(aInput), theOuterVars(aOuterVars)
{}

void FLWORIterator::GroupingOuterVar::accept ( PlanIterVisitor& v ) const
{
  theInput->accept(v);
}

void FLWORIterator::GroupingOuterVar::open ( PlanState& planState, uint32_t& offset )
{
  theInput->open(planState, offset);
}

void FLWORIterator::GroupingOuterVar::close ( PlanState& planState )
{
  theInput->close(planState);
}

FLWORIterator::GroupingSpec::GroupingSpec(
  PlanIter_t aInput, std::vector<ForVarIter_t> aInnerVars, xqpString aCollation )
  : theInput(aInput), theInnerVars(aInnerVars), theCollation(aCollation)
{}

void FLWORIterator::GroupingSpec::accept ( PlanIterVisitor& v ) const
{
  theInput->accept(v);
}

void FLWORIterator::GroupingSpec::open ( PlanState& planState, uint32_t& offset )
{
  theInput->open(planState, offset);
}

void FLWORIterator::GroupingSpec::close ( PlanState& planState )
{
  theInput->close(planState);
}

FLWORIterator::GroupByClause::GroupByClause (
  std::vector<GroupingSpec> aGroupingSpecs,
  std::vector<GroupingOuterVar> aOuterVars,
  PlanIter_t aWhere)
: theGroupingSpecs ( aGroupingSpecs ), 
  theOuterVars ( aOuterVars ),
  theWhere(aWhere)
{}

void FLWORIterator::GroupByClause::accept ( PlanIterVisitor& v ) const
{ 
  v.beginVisitFlworGroupBy();
  std::vector<GroupingSpec>::const_iterator iter;
  for ( iter = theGroupingSpecs.begin() ; iter != theGroupingSpecs.end(); iter++ )
  {
    v.beginVisitFlworGroupBySpec();
    iter->accept(v);
    v.endVisitFlworGroupBySpec();
  }
  std::vector<GroupingOuterVar>::const_iterator iterOuterVars;
  for ( iterOuterVars = theOuterVars.begin() ; iterOuterVars != theOuterVars.end(); iterOuterVars++ )
  {
    v.beginVisitFlworGroupByOuterVar();
    iterOuterVars->accept(v);
    v.endVisitFlworGroupByOuterVar();
  }
  v.endVisitFlworGroupBy();
}

void FLWORIterator::GroupByClause::open ( PlanState& planState, uint32_t& offset )
{ 
  std::vector<GroupingSpec>::iterator iter;
  for ( iter = theGroupingSpecs.begin() ; iter != theGroupingSpecs.end(); iter++ )
  {
    iter->open ( planState, offset  );
  }
  std::vector<GroupingOuterVar>::iterator iterOuterVars;
  for ( iterOuterVars = theOuterVars.begin() ; iterOuterVars != theOuterVars.end(); iterOuterVars++ )
  {
    iterOuterVars->open ( planState, offset  );
  }

  if (theWhere != 0)
    theWhere->open ( planState, offset );
}

void FLWORIterator::GroupByClause::close ( PlanState& planState )
{
  std::vector<GroupingSpec>::iterator lGroupSpecIter;
  for ( lGroupSpecIter = theGroupingSpecs.begin();
          lGroupSpecIter != theGroupingSpecs.end();
          ++lGroupSpecIter )
  {
    lGroupSpecIter->close ( planState );
  }
  std::vector<GroupingOuterVar>::iterator lOuterVarIter;
  for ( lOuterVarIter = theOuterVars.begin();
          lOuterVarIter != theOuterVars.end();
          ++lOuterVarIter )
  {
    lOuterVarIter->close ( planState );
  }
  if ( theWhere != 0 )
  {
    theWhere->close ( planState );
  }
}

uint32_t FLWORIterator::GroupingOuterVar::getStateSizeOfSubtree() const
{
  return theInput->getStateSizeOfSubtree();
}

uint32_t FLWORIterator::GroupingSpec::getStateSizeOfSubtree() const
{
  return theInput->getStateSizeOfSubtree();
}

uint32_t FLWORIterator::GroupByClause::getStateSizeOfSubtree() const
{
  uint32_t size=0;
  std::vector<GroupingSpec>::const_iterator iter;
  for ( iter = theGroupingSpecs.begin() ; iter != theGroupingSpecs.end(); iter++ )
  {
    size += iter->getStateSizeOfSubtree();
  }
  
  
  std::vector<GroupingOuterVar>::const_iterator iterOuterVars;
  for ( iterOuterVars = theOuterVars.begin() ; iterOuterVars != theOuterVars.end(); iterOuterVars++ )
  {
    size += iterOuterVars->getStateSizeOfSubtree();
  }

  if (theWhere != 0)
    size += theWhere->getStateSizeOfSubtree();

  return size;
}

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  OrderSpec                                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

FLWORIterator::OrderSpec::OrderSpec (
    PlanIter_t aOrderByIter,
    bool aEmpty_least,
    bool aDescending )
  :
  theOrderByIter ( aOrderByIter ),
  theEmptyLeast ( aEmpty_least ),
  theDescending ( aDescending ),
  theCollator(0)
{
}

FLWORIterator::OrderSpec::OrderSpec (
    PlanIter_t aOrderByIter,
    bool aEmpty_least,
    bool aDescending,
    const xqpString& aCollation)
  :
  theOrderByIter ( aOrderByIter ),
  theEmptyLeast ( aEmpty_least ),
  theDescending ( aDescending ),
  theCollation(aCollation),
  theCollator(0)
{
}

void FLWORIterator::OrderSpec::accept ( PlanIterVisitor& v ) const
{
  v.beginVisitFlworOrderBy(*theOrderByIter);
  v.endVisitFlworOrderBy(*theOrderByIter);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  OrderByClause                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


FLWORIterator::OrderByClause::OrderByClause (
    std::vector<FLWORIterator::OrderSpec> aOrderSpecs,
    bool aStable )
  :
  orderSpecs ( aOrderSpecs ),
  stable ( aStable )
{
}
  

void FLWORIterator::OrderByClause::accept ( PlanIterVisitor& v ) const
{
  // TODO
  std::vector<OrderSpec>::const_iterator iter;
  for ( iter = orderSpecs.begin() ; iter != orderSpecs.end(); iter++ )
  {
    iter->accept ( v );
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  OrderKeyCmp                                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


int8_t FLWORIterator::OrderKeyCmp::compare(
    RuntimeCB* aRuntimeCB,
    const store::Item_t& s1,
    const store::Item_t& s2,
    bool desc,
    bool emptyLeast,
    XQPCollator* collator) const
{
  if ( empty_item (aRuntimeCB, s1) )
  {
    if ( empty_item (aRuntimeCB, s2) )
      return descAsc ( 0, desc );
    else
      return descAsc (emptyLeast ? -1 : 1, desc);
  }
  else if ( empty_item (aRuntimeCB, s2) )
  {
    return descAsc (emptyLeast ? 1 : -1, desc);
  }
  else
  {
    // danm: both valueCompare (x, NaN) and valueCompare (NaN, x) return 2.
    // That's why empty_item is needed.
    int8_t result = CompareIterator::valueCompare ( aRuntimeCB, s1 , s2, collator );
    if (result > 1 || result < -1) {
      ZORBA_ERROR_DESC( XPTY0004, "Non-comparable types found while sorting" );
      
    }
    return descAsc (result , desc );
  }
}


int8_t FLWORIterator::OrderKeyCmp::descAsc ( int8_t result, bool desc ) const
{
  ZORBA_ASSERT (result <= 1 && result >= -1);
  return desc ? -result : result;
}


bool FLWORIterator::OrderKeyCmp::operator() (
    const std::vector<store::Item_t>& s1,
    const std::vector<store::Item_t>& s2 ) const
{
  ZORBA_ASSERT ( s1.size() == s2.size() );
  ZORBA_ASSERT ( s1.size() == mOrderSpecs->size() );

  std::vector<store::Item_t>::const_iterator s1iter = s1.begin();
  std::vector<store::Item_t>::const_iterator s2iter = s2.begin();
  std::vector<OrderSpec>::const_iterator orderSpecIter = mOrderSpecs->begin();

  while ( s1iter != s1.end() )
  {
    int8_t cmp = compare(orderSpecIter->theRuntimeCB,
                         *s1iter,
                         *s2iter,
                         orderSpecIter->theDescending,
                         orderSpecIter->theEmptyLeast,
                         orderSpecIter->theCollator);
    if ( cmp == 1 )
    {
      return false;
    }
    else if ( cmp == -1 )
    {
      return true;
    }
    ++s1iter;
    ++s2iter;
    ++orderSpecIter;
  }
  return false;
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  FLWORIterator                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

FLWORIterator::FLWORIterator(
    const QueryLoc& loc,
    std::vector<FLWORIterator::ForLetClause> &aForLetClauses,
    PlanIter_t& aWhereClause,
    FLWORIterator::GroupByClause* aGroupByClauses,
    FLWORIterator::OrderByClause* aOrderByClause,
    PlanIter_t& aReturnClause,
    bool aIsUpdating)
  :
  Batcher<FLWORIterator>(loc),
  forLetClauses(aForLetClauses),
  whereClause(aWhereClause),
  theGroupByClause(aGroupByClauses),
  orderByClause(aOrderByClause),
  returnClause(aReturnClause),
  theIsUpdating(aIsUpdating),
  theNumBindings(aForLetClauses.size())
{
  if ( orderByClause == 0 || orderByClause->orderSpecs.size() == 0 )
  {
    orderByClause = 0;
    doOrderBy = false;
  }
  else
  {
    doOrderBy = true;
  }
  
  if ( theGroupByClause == 0 ){
    doGroupBy = false;
  }else{
    doGroupBy = true;
  }
}


FLWORIterator::~FLWORIterator()
{
  if ( doOrderBy )
  {
    delete orderByClause;
  }
  if( doGroupBy){ 
    delete theGroupByClause;
  }
}



bool FLWORIterator::nextImpl ( store::Item_t& result, PlanState& planState ) const
{
  //Needed variables
  int curVar = 0;
  store::Item_t curItem;
  std::auto_ptr<store::PUL> pul;

  FlworState* flworState;
  DEFAULT_STACK_INIT(FlworState, flworState, planState);

  assert(flworState->varBindingState.size() > 0);

  if (theIsUpdating)
    pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  while ( true )
  {
    // Here we do the variable bindings from the outer most to the inner most
    while ( curVar != theNumBindings )
    {
      // Try to bind the current variable. If the binding of the variable is
      // successfull, we procede with the next binding level. Else, we go a
      // level back and try the previous level
      if ( bindVariable ( curVar, flworState, planState ) )
      {
        ++curVar;
      }
      else
      {
        flworState->varBindingState[curVar] = 0;
        resetInput ( curVar, flworState, planState );
        --curVar;

        // If we finished the last binding (curVar == -1) and we had to Order
        // we need to return the results, otherwise we just need to indicate
        // that we finished by returning NULL
        if ( curVar == -1 )
        {
          if (theIsUpdating)
          {
            result = pul.release();
            STACK_PUSH(true, flworState);
          }
          else if(doOrderBy)
          {
            if(doGroupBy){
              groupAndOrder(flworState, planState);
            }
            flworState->curOrderPos = flworState->orderMap->begin();

            while ( flworState->curOrderPos != flworState->orderMap->end() )
            {
              flworState->curOrderResultSeq = flworState->curOrderPos->second;

              while ( flworState->curOrderResultSeq->next(result) )
              {
                STACK_PUSH ( true, flworState );
              }
              ++ ( flworState->curOrderPos );
            }
          }
          else if(doGroupBy)
          {
            flworState->curGroupPos = flworState->groupMap->begin();
            while ( flworState->curGroupPos != flworState->groupMap->end() )
            {
              bindGroupBy( flworState->curGroupPos, flworState, planState );
              if(evalToBool(theGroupByClause->theWhere, planState)){
                while(consumeNext(result, returnClause, planState)) {
                  STACK_PUSH ( true, flworState );
                }
              }
              returnClause->reset(planState);
              ++flworState->curGroupPos;
            }
          }

          goto stop;
        }
      }
    } // build next full tuple

    // After binding all variables, we check first the where clause
    // curVar = theNumBindings - 1 indicates that we have to do the next binding level
   
    if ( evalToBool( whereClause,  planState  ) )
    {
      // In the case we not need to do ordering, we now returning the items
      // produced by the ReturnClause
      if(doGroupBy)
      {
        matVarsAndGroupBy ( flworState, planState );
      }
      else if (theIsUpdating)
      {
        while(consumeNext(curItem, returnClause, planState)) {
          ZORBA_FATAL(curItem->isPul(), "");

          pul->mergeUpdates(curItem);
        }
        returnClause->reset(planState);
      }
      else if ( !doOrderBy )
      {
        while ( consumeNext(result, returnClause, planState) )
        {
          STACK_PUSH ( true, flworState );
        }
        returnClause->reset(planState);
        //In the case we have to order we are materializing the result
      }
      else
      {
        matResultAndOrder ( flworState, planState );
      }
    }

    curVar = theNumBindings - 1;
  }

 stop:
  STACK_END (flworState);
}


void FLWORIterator::groupAndOrder ( FlworState* flworState,
                                    PlanState& planState ) const
{
  FLWORIterator::group_map_t* lGroupMap = flworState->groupMap;
  FLWORIterator::group_map_t::iterator lGroupMapIter = lGroupMap->begin();
  while ( lGroupMapIter != lGroupMap->end() )
  {
    bindGroupBy ( lGroupMapIter, flworState, planState );    
    if(evalToBool(theGroupByClause->theWhere, planState)){
      matResultAndOrder(flworState, planState);
    }

    ++lGroupMapIter;
  }
}

void FLWORIterator::bindGroupBy ( FLWORIterator::group_map_t::iterator lGroupMapIter,
                                  FlworState* flworState,
                                  PlanState& planState ) const
{
  //Bind grouping vars
  GroupKey* lGroupKey = ( *lGroupMapIter ).first;
  std::vector<store::Item_t>::iterator lGroupKeyIter = lGroupKey->theKey.begin();
  std::vector<GroupingSpec> lgroupSpecs = theGroupByClause->theGroupingSpecs;
  std::vector<GroupingSpec>::const_iterator lSpecIter = lgroupSpecs.begin();
  while ( lSpecIter != lgroupSpecs.end() )
  {
    std::vector<ForVarIter_t>::const_iterator lGroupVarIter = lSpecIter->theInnerVars.begin();
    while ( lGroupVarIter != lSpecIter->theInnerVars.end() )
    {
      ( *lGroupVarIter )->bind ( *lGroupKeyIter, planState );
      ++lGroupVarIter;
    }
    ++lSpecIter;
    ++lGroupKeyIter;
  }

  //Bind non-grouping vars
  std::vector<store::TempSeq_t>* lVector = ( *lGroupMapIter ).second;
  std::vector<store::TempSeq_t>::const_iterator lOuterSeqIter = lVector->begin();
  std::vector<GroupingOuterVar> lOuterVars = theGroupByClause->theOuterVars;
  std::vector<GroupingOuterVar>::const_iterator lOuterVarsIter = lOuterVars.begin();
  while ( lOuterVarsIter != lOuterVars.end() )
  {
    std::vector<LetVarIter_t>::const_iterator lOuterVarBindingIter = lOuterVarsIter->theOuterVars.begin();
    while ( lOuterVarBindingIter != lOuterVarsIter->theOuterVars.end() )
    {
      store::TempSeq_t lTmpSeq = *lOuterSeqIter;
      store::Iterator_t lBindIterator = lTmpSeq->getIterator();
      lBindIterator->open();
      ( *lOuterVarBindingIter )->bind ( lBindIterator , planState );
      ++lOuterVarBindingIter;
    }
    ++lOuterVarsIter;
    ++lOuterSeqIter;
  }
}


void FLWORIterator::matVarsAndGroupBy (
    FlworState* flworState,
    PlanState& planState ) const
{
  ZORBA_ASSERT ( doGroupBy );

  GroupKey* lGroupKey = new GroupKey();
  std::vector<store::Item_t> lKey;
  std::vector<store::Item_t> lTypedKey;
  std::vector<GroupingSpec> lgroupSpecs = theGroupByClause->theGroupingSpecs;
  std::vector<GroupingSpec>::iterator lSpecIter = lgroupSpecs.begin();
  while ( lSpecIter != lgroupSpecs.end() )
  {
    lKey.push_back(NULL);
    store::Item_t& location = lKey.back();
    bool status = consumeNext ( location, lSpecIter->theInput.getp(), planState );
    
    //Getting the typed value
    if(!status)
    {
      lTypedKey.push_back(NULL);
    }
    else
    {
      store::Item_t temp;

      store::Iterator_t lTypedValueIter;
      store::Item_t lTypedValue;
      location->getTypedValue(lTypedValue, lTypedValueIter);
      if (lTypedValueIter == NULL)
      {
        lTypedKey.push_back(NULL);
        lTypedKey.back().transfer(lTypedValue);
      }
      else
      {
        lTypedValueIter->open();
        lTypedKey.push_back(NULL);
        store::Item_t& typedItem = lTypedKey.back();
        if(lTypedValueIter->next(typedItem))
        {
          if (lTypedValueIter->next(temp))
          {
            ZORBA_ERROR_DESC ( XPTY0004, "Expected a singleton (atomization has more than one value)" );
          }
        }
      }
    }
    
    //check for more values
    if (status)
    {
      store::Item_t temp;
      if (consumeNext ( temp, lSpecIter->theInput.getp(), planState ))
      {
        ZORBA_ERROR_DESC ( XPTY0004, "Expected a singleton" );
      }
    }
    lSpecIter->theInput->reset ( planState );
    ++lSpecIter;
  }
  lGroupKey->theKey = lKey;
  lGroupKey->theTypedKey = lTypedKey;
  
  FLWORIterator::group_map_t* lGroupMap = flworState->groupMap;
  std::vector<store::TempSeq_t>* lOuterSeq = 0;
  std::vector<GroupingOuterVar> lOuterVars = theGroupByClause->theOuterVars;
  std::vector<GroupingOuterVar>::iterator lOuterVarIter = lOuterVars.begin();
  if ( lGroupMap->get ( lGroupKey, lOuterSeq ) ){
    assert(lOuterSeq > 0);
    std::vector<store::TempSeq_t>::iterator lOuterSeqIter = lOuterSeq->begin();
    while ( lOuterVarIter != lOuterVars.end() ){
      store::Iterator_t iterWrapper = new PlanIteratorWrapper ( lOuterVarIter->theInput, planState );
      ( *lOuterSeqIter )->append ( iterWrapper, true );
      lOuterVarIter->theInput->reset ( planState );
      ++lOuterSeqIter;
      ++lOuterVarIter;
    }
    delete lGroupKey;
  }else{
    lOuterSeq = new std::vector<store::TempSeq_t>();
    while ( lOuterVarIter != lOuterVars.end() ){
      store::Iterator_t iterWrapper = new PlanIteratorWrapper ( lOuterVarIter->theInput, planState );
      store::TempSeq_t result = GENV_STORE.createTempSeq ( iterWrapper, true, false );
      lOuterSeq->push_back ( result );
      lOuterVarIter->theInput->reset ( planState );
      ++lOuterVarIter;
    }
    lGroupMap->insert ( lGroupKey, lOuterSeq );
  }
}

void FLWORIterator::matResultAndOrder(
    FlworState* flworState,
    PlanState& planState) const
{
  ZORBA_ASSERT ( doOrderBy );

  std::vector<OrderSpec>& lOrderSpecs = orderByClause->orderSpecs;
  //FIXME hould be a const iterator after the change of Plan_Iter
  std::vector<OrderSpec>::iterator lSpecIter = lOrderSpecs.begin();
  std::vector<store::Item_t> orderKey;

  while ( lSpecIter != lOrderSpecs.end() )
  {
    orderKey.push_back(NULL);
    store::Item_t& location = orderKey.back();
    if (consumeNext ( location, lSpecIter->theOrderByIter.getp(), planState ))
    {
      store::Item_t temp;
      if (consumeNext ( temp, lSpecIter->theOrderByIter.getp(), planState ))
      {
        ZORBA_ERROR_DESC( XPTY0004, "Expected a singleton" );
      }
    }
    lSpecIter->theOrderByIter->reset(planState);
    ++lSpecIter;
  }

  store::Iterator_t iterWrapper = new PlanIteratorWrapper(returnClause, planState);
  store::TempSeq_t result = GENV_STORE.createTempSeq(iterWrapper, false, false);
  store::Iterator_t iter = result->getIterator();
  iter->open(); //where is this iterator closed?
  flworState->orderMap->insert(std::pair<std::vector<store::Item_t>, store::Iterator_t>(orderKey, iter));
  returnClause->reset(planState); 

}


bool FLWORIterator::evalToBool ( const PlanIter_t& checkIter, PlanState& planState ) const
{
  if ( checkIter == NULL )
    return true;

  //if ( whereClauseReturnsBooleanPlus )
  //{
  store::Item_t boolValue;
  if (!consumeNext ( boolValue, checkIter.getp(), planState ))
    return false;

  bool value = boolValue->getBooleanValue();
  checkIter->reset ( planState );
  return value;
  /*}

  store::Item_t item = FnBooleanIterator::effectiveBooleanValue(loc,
                                                         planState,
                                                         whereClause);
  whereClause->reset(planState);
  return item->getBooleanValue();*/
}


void FLWORIterator::resetInput(
    const int& varNb,
    FlworState* flworState,
    PlanState& planState) const
{
  FLWORIterator::ForLetClause lForLetClause = forLetClauses[varNb];
  lForLetClause.theInput->reset( planState );
  flworState->varBindingState[varNb] = 0;
}


bool FLWORIterator::bindVariable (
    int varNb,
    FlworState* flworState,
    PlanState& planState ) const
{
  const FLWORIterator::ForLetClause& lForLetClause = forLetClauses[varNb];

  switch (lForLetClause.theType)
  {
  //In the case of a FOR we try to get the next item of the input and bind
  // it to all the variable references
  case ForLetClause::FOR :
  {
    store::Item_t lItem;
    if (!consumeNext ( lItem, lForLetClause.theInput.getp(), planState ))
    {
      return false;
    }

    //We increase the position counter
    ++ ( flworState->varBindingState[varNb] );

    std::vector<ForVarIter_t>::const_iterator forIter;
    std::vector<ForVarIter_t>::const_iterator forEnd = lForLetClause.theForVars.end();
    for (forIter = lForLetClause.theForVars.begin();
         forIter != forEnd;
         forIter++)
    {
      const ForVarIter_t& variable = (*forIter);
      variable->bind(lItem.getp(), planState);
    }

    if ( !lForLetClause.thePosVars.empty() )
    {
      store::Item_t posItem;
      GENV_ITEMFACTORY->createInteger(posItem,
                                      Integer::parseInt(flworState->varBindingState[varNb]));

      std::vector<ForVarIter_t>::const_iterator posIter;
      std::vector<ForVarIter_t>::const_iterator posEnd = lForLetClause.thePosVars.end();
      for (posIter = lForLetClause.thePosVars.begin();
           posIter != posEnd;
           posIter++)
      {
        const ForVarIter_t& variable = (*posIter);
        variable->bind(posItem.getp(), planState);
      }
    }
    //TODO Pos Bindings
    return true;
  }
  case ForLetClause::LET :
  {      
    //return false if the Var-Variable was already bound
    if ( flworState->varBindingState[varNb] == 1 )
    {
      return false;
    }

    store::Iterator_t iterWrapper = new PlanIteratorWrapper(lForLetClause.theInput, planState);
    //Depending on the query, we might need to materialize the LET-Binding
    if ( lForLetClause.theNeedsMaterialization )
    {
      store::TempSeq_t tmpSeq = GENV_STORE.createTempSeq(iterWrapper, false, true);
      std::vector<LetVarIter_t>::const_iterator letIter;
      for (letIter = lForLetClause.theLetVars.begin();
           letIter != lForLetClause.theLetVars.end();
           ++letIter )
      {
        store::Iterator_t iter = tmpSeq->getIterator();
        iter->open();
        (*letIter)->bind(iter, planState);
      }
    }
    else
    {
      std::vector<LetVarIter_t>::const_iterator letIter;
      for (letIter = lForLetClause.theLetVars.begin();
           letIter != lForLetClause.theLetVars.end();
           letIter++)
      {
        (*letIter)->bind(iterWrapper, planState);
      }
    }
    ++ ( flworState->varBindingState[varNb] );
    return true;
  }
  default:
    //That should never happen
    ZORBA_ASSERT ( false );
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
void FLWORIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<FlworState>::createState(planState, this->stateOffset, offset);
  FlworState* flworState = StateTraitsImpl<FlworState>::getState(planState, this->stateOffset);

  //we allocate resources
  if(doGroupBy){
    std::vector<XQPCollator*> lCollators;
    std::vector<GroupingSpec>::const_iterator lGroupSpecIter;
    for (lGroupSpecIter = theGroupByClause->theGroupingSpecs.begin();
         lGroupSpecIter != theGroupByClause->theGroupingSpecs.end();
         ++lGroupSpecIter )
    {
      xqpString lTmp = lGroupSpecIter->theCollation;
      if (lTmp.size() != 0) {
        XQPCollator* lCollator = planState.theRuntimeCB->theCollationCache->
            getCollator(lTmp.theStrStore);
        lCollators.push_back(lCollator);
      }else{
        lCollators.push_back(NULL);
      }
    }
    flworState->init(planState,
                       theNumBindings,
                       &orderByClause->orderSpecs,
                       &lCollators); 
  }else if ( doOrderBy ) {
    flworState->init(planState,
                     theNumBindings,
                     &orderByClause->orderSpecs,
                     0);
  } else {
    flworState->init(planState, theNumBindings);
  }

#ifndef NDEBUG
  // some variables must have been bound
  assert(flworState->varBindingState.size() > 0);
#endif

  std::vector<FLWORIterator::ForLetClause>::const_iterator iter;
  for (iter = forLetClauses.begin(); iter != forLetClauses.end(); iter++)
  {
    iter->theInput->open ( planState, offset );
  }

  returnClause->open ( planState, offset );

  if ( whereClause != NULL )
    whereClause->open ( planState, offset );
  
  if ( doGroupBy){
    theGroupByClause->open(planState, offset);
  }
  
  if ( doOrderBy )
  {
    std::vector<OrderSpec>::const_iterator iter;
    for (iter = orderByClause->orderSpecs.begin();
         iter != orderByClause->orderSpecs.end();
         iter++ )
    {
      iter->theOrderByIter->open ( planState, offset );
      iter->theRuntimeCB = planState.theRuntimeCB; // TODO check if this is the right place and the right runtimecb
      if (iter->theCollation.size() != 0) 
      {
        xqpString lTmp = iter->theCollation;
        iter->theCollator = planState.theRuntimeCB->theCollationCache->
                            getCollator(lTmp.theStrStore);
      }
    }
  }
 
}


void FLWORIterator::resetImpl ( PlanState& planState ) const
{
  returnClause->reset(planState);

  if (whereClause != NULL)
    whereClause->reset(planState);

  if (orderByClause != NULL)
  {
    std::vector<FLWORIterator::OrderSpec>::iterator iter;
    for (iter = orderByClause->orderSpecs.begin();
         iter != orderByClause->orderSpecs.end();
         iter++)
    {
      iter->theOrderByIter->reset(planState);
    }
  }
  
  if(theGroupByClause != NULL){
    std::vector<GroupingSpec>::const_iterator lGroupSpecIter;
    for (lGroupSpecIter = theGroupByClause->theGroupingSpecs.begin();
         lGroupSpecIter != theGroupByClause->theGroupingSpecs.end();
         ++lGroupSpecIter )
    {
      lGroupSpecIter->theInput->reset(planState);
    }
    std::vector<GroupingOuterVar>::const_iterator lOuterVarIter;
    for (lOuterVarIter = theGroupByClause->theOuterVars.begin();
         lOuterVarIter != theGroupByClause->theOuterVars.end();
         ++lOuterVarIter )
    {
      lOuterVarIter->theInput->reset(planState);
    }
  }

  std::vector<FLWORIterator::ForLetClause>::const_iterator iter;
  for (iter = forLetClauses.begin(); iter != forLetClauses.end(); iter++)
  {
    iter->theInput->reset(planState);
  }

  StateTraitsImpl<FlworState>::reset(planState, this->stateOffset);
}


void FLWORIterator::closeImpl ( PlanState& planState )
{
  returnClause->close(planState);

  if (whereClause != 0)
    whereClause->close(planState);

  if (orderByClause != 0)
  {
    std::vector<FLWORIterator::OrderSpec>::iterator iter;
    for (iter = orderByClause->orderSpecs.begin();
         iter != orderByClause->orderSpecs.end();
         iter++)
    {
      iter->theOrderByIter->close(planState);
    }
  }
  if(theGroupByClause != 0){
    theGroupByClause->close(planState);
  }

  std::vector<FLWORIterator::ForLetClause>::iterator iter;
  for (iter = forLetClauses.begin(); iter != forLetClauses.end(); iter++)
  {
    iter->theInput->close(planState);
  }
  
  StateTraitsImpl<FlworState>::destroyState(planState, this->stateOffset);
}


uint32_t FLWORIterator::getStateSize() const  { return sizeof ( FlworState); }

uint32_t FLWORIterator::getStateSizeOfSubtree() const
{
  int32_t size = this->getStateSize();
  std::vector<FLWORIterator::ForLetClause>::const_iterator iter;
  for ( iter = forLetClauses.begin() ; iter != forLetClauses.end(); iter++ )
  {
    size += iter->theInput->getStateSizeOfSubtree();
  }

  size += returnClause->getStateSizeOfSubtree();

  if ( whereClause != NULL )
    size += whereClause->getStateSizeOfSubtree();

  if ( doOrderBy )
  {
    std::vector<OrderSpec>::const_iterator iter;
    for (iter = orderByClause->orderSpecs.begin();
         iter != orderByClause->orderSpecs.end();
         iter++ )
    {
      size += iter->theOrderByIter->getStateSizeOfSubtree();
    }
  }

  if(doGroupBy){
    size += theGroupByClause->getStateSizeOfSubtree();
  }
  return size;
}


void FLWORIterator::accept ( PlanIterVisitor& v ) const
{
  // TODO
  v.beginVisit ( *this );
  std::vector<FLWORIterator::ForLetClause>::const_iterator iter;
  for ( iter = forLetClauses.begin() ; iter != forLetClauses.end(); iter++ )
  {
    iter->accept(v);
  }

  if ( whereClause != NULL )
  {
    v.beginVisitFlworWhereClause(*whereClause);
    v.endVisitFlworWhereClause(*whereClause);
  }
  if ( theGroupByClause )
  {
    theGroupByClause->accept ( v );
  }
 
  if ( doOrderBy )
  {
    orderByClause->accept ( v );
  }
  v.beginVisitFlworReturn(*returnClause);
  v.endVisitFlworReturn(*returnClause);

  v.endVisit(*this);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  FlworState                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

FlworState::FlworState()
  :
    orderMap(0), groupMap(0), valueCompareParam(0)
{
}


FlworState::~FlworState()
{
  if ( orderMap )
  {
    orderMap->clear(); // TODO is this needed
    delete orderMap;
    orderMap = 0;
  }
  if ( groupMap )
  {
    
    FLWORIterator::group_map_t::iterator lGroupIter;
    for (lGroupIter = groupMap->begin();
         lGroupIter != groupMap->end();
         ++lGroupIter )
    {
      delete (*lGroupIter).first;
      delete (*lGroupIter).second;
    }
    //groupMap->clear();
    delete groupMap;
    groupMap = 0;
    //delete valueCompareParam;
    //valueCompareParam = 0;
  }
}


void FlworState::init(PlanState& planState, size_t numVars)
{
  PlanIteratorState::init(planState);
  std::vector<uint32_t> v(numVars, 0);
  varBindingState.swap (v);
  assert(varBindingState.size() > 0);
}


void FlworState::init(
    PlanState& planState,
    size_t numVars,
    std::vector<FLWORIterator::OrderSpec>* orderSpecs,
    std::vector<XQPCollator*> * groupingCollators)
{
  init (planState, numVars);
  if(orderSpecs!=0){
    orderMap = new FLWORIterator::order_map_t(orderSpecs);
  }
  
  if(groupingCollators!=0){
    valueCompareParam = new GroupCompareParam(planState.theRuntimeCB, *groupingCollators);
    groupMap = new FLWORIterator::group_map_t(valueCompareParam);
  }
}


void FlworState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  assert(varBindingState.size() > 0);
  size_t size = varBindingState.size();
  ::memset(&varBindingState[0], 0, size * sizeof(uint32_t));
  curOrderResultSeq = 0;
  if ( orderMap != 0 )
  {
    orderMap->clear();
  }
  if(groupMap != 0){
    FLWORIterator::group_map_t::iterator lGroupIter;
    for (lGroupIter = groupMap->begin();
         lGroupIter != groupMap->end();
         ++lGroupIter )
    {
      delete (*lGroupIter).first;
      delete (*lGroupIter).second;
      //delete (*lGroupIter).second;
    }
    groupMap->clear();
  }
}


}
