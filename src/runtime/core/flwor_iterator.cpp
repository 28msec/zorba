/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: Tim Kraska
 *
 */

#include "errors/fatal.h"
#include "compiler/expression/expr.h"
#include "runtime/core/flwor_iterator.h"
#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "runtime/core/var_iterators.h"
#include "runtime/api/runtimecb.h"
#include "errors/error_manager.h"
#include "store/api/temp_seq.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/visitors/planitervisitor.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "util/Assert.h"
#include "system/globalenv.h"
#include "store/api/store.h"
#include "store/api/pul.h"
#include "store/api/item_factory.h"
#include "context/static_context.h"
#include "context/collation_cache.h"

namespace zorba
{

  // Utility function -- is this item null or a NaN?
static bool empty_item (RuntimeCB* aRuntimeCB, store::Item_t s)
{
  return (s == 0) || (s->isNumeric () && s->isNaN());
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ForLetClause                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


FLWORIterator::ForLetClause::ForLetClause(
    const var_expr* var,
    std::vector<var_iter_t> aForVars,
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
    std::vector<var_iter_t> aForVars,
    std::vector<var_iter_t> aPosVars,
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
    std::vector<ref_iter_t> aLetVars,
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
    v.beginVisitFlworForVariable(*theInput, getVarName());
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

FLWORIterator::GroupClause::GroupClause(
  PlanIter_t aInput, std::vector<ref_iter_t> aInnerVars)
: theInput(aInput), theInnerVars(aInnerVars)
{}

FLWORIterator::GroupClause::GroupClause(
  PlanIter_t aInput, std::vector<ref_iter_t> aInnerVars, xqpString& aCollation)
: theInput(aInput), theInnerVars(aInnerVars), theCollation(aCollation)
{}

void FLWORIterator::GroupClause::accept ( PlanIterVisitor& v ) const
{
  v.beginVisitFlworGroupBy(*theInput);
  v.endVisitFlworGroupBy(*theInput);
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
      ZORBA_ERROR_DESC( ZorbaError::XPTY0004, "Non-comparable types found while sorting" );
      
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
    std::vector<FLWORIterator::GroupClause>& aGroupByClauses,
    std::vector<FLWORIterator::GroupClause>& aNonGroupByClauses,
    FLWORIterator::OrderByClause* aOrderByClause,
    PlanIter_t& aReturnClause,
    bool aIsUpdating,
    bool aWhereClauseReturnsBooleanPlus)
  :
  Batcher<FLWORIterator>(loc),
  forLetClauses(aForLetClauses),
  whereClause(aWhereClause),
  theGroupByClauses(aGroupByClauses),
  theNonGroupByClauses(aNonGroupByClauses),
  orderByClause(aOrderByClause),
  returnClause(aReturnClause),
  whereClauseReturnsBooleanPlus(aWhereClauseReturnsBooleanPlus),
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
}


FLWORIterator::~FLWORIterator()
{
  if ( doOrderBy )
  {
    delete orderByClause;
  }
}



store::Item_t FLWORIterator::nextImpl ( PlanState& planState ) const
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
            STACK_PUSH(pul.release(), flworState);
          }
          else if ( doOrderBy )
          {
            flworState->curOrderPos = flworState->orderMap->begin();

            while ( flworState->curOrderPos != flworState->orderMap->end() )
            {
              flworState->curOrderResultSeq = flworState->curOrderPos->second;

              while ( ( curItem = flworState->curOrderResultSeq->next() ) != 0 )
              {
                STACK_PUSH ( curItem, flworState );
              }
              ++ ( flworState->curOrderPos );
            }
          }

          goto stop;
        }
      }
    } // build next full tuple

    // After binding all variables, we check first the where clause
    // curVar = theNumBindings - 1 indicates that we have to do the next binding level
    if ( evalWhereClause ( planState ) )
    {
      // In the case we not need to do ordering, we now returning the items
      // produced by the ReturnClause
      if (theIsUpdating)
      {
        curItem = consumeNext(returnClause, planState);
        while (curItem != 0)
        {
          ZORBA_FATAL(curItem->isPul(), "");

          pul->mergeUpdates(curItem);

          curItem = consumeNext(returnClause, planState);
        }
        returnClause->reset(planState);
      }
      else if ( !doOrderBy )
      {
        while ( (curItem = consumeNext(returnClause, planState)) != 0  )
        {
          STACK_PUSH ( curItem, flworState );
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
    store::Item_t lItem = consumeNext ( lSpecIter->theOrderByIter.getp(), planState );
    orderKey.push_back ( lItem );
    //Test for singleton
    if ( lItem != 0 )
    {
      lItem = consumeNext ( lSpecIter->theOrderByIter.getp(), planState );
      if ( lItem != 0 )
      {
        ZORBA_ERROR_DESC( ZorbaError::XPTY0004, "Expected a singleton" );
      }
    }
    lSpecIter->theOrderByIter->reset(planState);
    ++lSpecIter;
  }

  store::Iterator_t iterWrapper = new PlanIteratorWrapper(returnClause, planState);
  store::TempSeq_t result = GENV_STORE.createTempSeq(iterWrapper, false, false);
  store::Iterator_t iter = result->getIterator();
  iter->open();
  flworState->orderMap->insert(std::pair<std::vector<store::Item_t>, store::Iterator_t>(orderKey, iter));
  returnClause->reset(planState);

}


bool FLWORIterator::evalWhereClause ( PlanState& planState ) const
{
  if ( whereClause == NULL )
    return true;

  if ( whereClauseReturnsBooleanPlus )
  {
    store::Item_t boolValue = consumeNext ( whereClause.getp(), planState );
    if ( boolValue == NULL )
      return false;

    bool value = boolValue->getBooleanValue();
    whereClause->reset(planState);
    return value;
  }

  store::Item_t item = FnBooleanIterator::effectiveBooleanValue(loc,
                                                         planState,
                                                         whereClause);
  whereClause->reset(planState);
  return item->getBooleanValue();
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
    store::Item_t lItem = consumeNext ( lForLetClause.theInput.getp(), planState );
    if ( lItem == NULL )
    {
      return false;
    }

    //We increase the position counter
    ++ ( flworState->varBindingState[varNb] );

    std::vector<var_iter_t>::const_iterator forIter;
    for (forIter = lForLetClause.theForVars.begin();
         forIter != lForLetClause.theForVars.end();
         forIter++)
    {
      var_iter_t variable = (*forIter);
      variable->bind(lItem, planState);
    }

    if ( !lForLetClause.thePosVars.empty() )
    {
      store::Item_t posItem = GENV_ITEMFACTORY->
                       createInteger(Integer::parseInt(flworState->varBindingState[varNb]));

      std::vector<var_iter_t>::const_iterator posIter;
      for (posIter = lForLetClause.thePosVars.begin();
           posIter != lForLetClause.thePosVars.end();
           posIter++)
      {
        var_iter_t variable = (*posIter);
        variable->bind(posItem, planState);
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
      std::vector<ref_iter_t>::const_iterator letIter;
      for (letIter = lForLetClause.theLetVars.begin();
           letIter != lForLetClause.theLetVars.end();
           letIter++ )
      {
        store::Iterator_t iter = tmpSeq->getIterator();
        iter->open();
        (*letIter)->bind(iter, planState);
      }
    }
    else
    {
      std::vector<ref_iter_t>::const_iterator letIter;
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
  if ( doOrderBy )
  {
    flworState->init(planState,
                     theNumBindings,
                     &orderByClause->orderSpecs);
  }
  else
  {
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

  if (whereClause != NULL)
    whereClause->close(planState);

  if (orderByClause != NULL)
  {
    std::vector<FLWORIterator::OrderSpec>::iterator iter;
    for (iter = orderByClause->orderSpecs.begin();
         iter != orderByClause->orderSpecs.end();
         iter++)
    {
      iter->theOrderByIter->close(planState);
    }
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

  return size;
}


void FLWORIterator::accept ( PlanIterVisitor& v ) const
{
  // TODO
  v.beginVisit ( *this );
  std::vector<FLWORIterator::ForLetClause>::const_iterator iter;
  for ( iter = forLetClauses.begin() ; iter != forLetClauses.end(); iter++ )
  {
    iter->accept ( v );
  }

  if ( whereClause != NULL )
  {
    v.beginVisitFlworWhereClause(*whereClause);
    v.endVisitFlworWhereClause(*whereClause);
  }
  {
    std::vector<FLWORIterator::GroupClause>::const_iterator lIter = theGroupByClauses.begin();
    std::vector<FLWORIterator::GroupClause>::const_iterator lEnd  = theGroupByClauses.end();
    for (;lIter!=lEnd;++lIter)
    {
      lIter->accept(v);
    }
  }
  {
    std::vector<FLWORIterator::GroupClause>::const_iterator lIter = theNonGroupByClauses.begin();
    std::vector<FLWORIterator::GroupClause>::const_iterator lEnd  = theNonGroupByClauses.end();
    for (;lIter!=lEnd;++lIter)
    {
      lIter->accept(v);
    }
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
  orderMap(0)
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
    std::vector<FLWORIterator::OrderSpec>* orderSpecs)
{
  init (planState, numVars);
  orderMap = new FLWORIterator::order_map_t(orderSpecs);
}


void FlworState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  assert(varBindingState.size() > 0);
  size_t size = varBindingState.size();
  varBindingState.clear();
  varBindingState.insert(varBindingState.begin(), size, 0);
  curOrderResultSeq = 0;
  if ( orderMap != 0 )
  {
    orderMap->clear();
  }
}


}
