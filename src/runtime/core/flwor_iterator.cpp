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

#include "context/collation_cache.h"
#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "compiler/expression/expr.h"
#include "runtime/core/flwor_iterator.h"
#include "runtime/core/var_iterators.h"
#include "runtime/api/runtimecb.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/visitors/planitervisitor.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "system/globalenv.h"

#include "store/api/temp_seq.h"
#include "store/api/store.h"
#include "store/api/pul.h"
#include "store/api/item_factory.h"


#include <time.h>


namespace zorba
{


namespace flwor
{


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ForLetClause                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**
  Creates a new ForClause for a FOR variable

  @param var The var_expr for this FOR variable.
  @param aForVars Vector of ForVar iterators representing the references to this
         variable.
  @param aInput The iterator computing the value of this variable.
********************************************************************************/
ForLetClause::ForLetClause(
    const var_expr* var,
    std::vector<ForVarIter_t> aForVars,
    PlanIter_t& aInput)
  :
#ifndef NDEBUG
  theVarName(var->get_varname()->getStringValue()->c_str()),
#endif
  theType ( FOR ),
  theForVarRefs ( aForVars ),
  theInput ( aInput )
{ 
}


/***************************************************************************//**
  Creates a new ForClause for a FOR var and its associated positional var.

  @param var The var_expr for this FOR variable.
  @param aForVars Vector of ForVar iterators representing the references to this
         variable.
  @param aPosVars Vector of ForVar iterators representing the references to the
         associated positional variable.
  @param aInput The iterator computing the value of this variable.
********************************************************************************/
ForLetClause::ForLetClause (
    const var_expr* var,
    std::vector<ForVarIter_t> aForVars,
    std::vector<ForVarIter_t> aPosVars,
    PlanIter_t& aInput )
  :
#ifndef NDEBUG
  theVarName(var->get_varname()->getStringValue()->c_str()),
#endif
  theType ( FOR ),
  theForVarRefs ( aForVars ),
  thePosVarRefs ( aPosVars ),
  theInput ( aInput )
{
}


/***************************************************************************//**
  Creates a new ForClause for a LET variable

  @param var The var_expr for this LET variable.
  @param aLetVars Vector of ForVar iterators representing the references to this
         variable.
  @param aInput The iterator computing the value of this variable.
  @param needsMaterialization Indicates if it is necassary to materialize the
         LET variable. 
********************************************************************************/
ForLetClause::ForLetClause (
    const var_expr* var,
    std::vector<LetVarIter_t> aLetVars,
    PlanIter_t& aInput,
    bool aNeedsMaterialization )
  :
#ifndef NDEBUG
  theVarName(var->get_varname()->getStringValue()->c_str()),
#endif
  theType(LET),
  theLetVarRefs(aLetVars),
  theInput(aInput),
  theMaterialize(aNeedsMaterialization)
{
}


/***************************************************************************//**

********************************************************************************/
void ForLetClause::accept ( PlanIterVisitor& v ) const
{
  // TODO correct for visitor
  switch ( theType )
  {
  case FOR:
    v.beginVisitFlworForVariable(*theInput, getVarName(), theForVarRefs);
    v.endVisitFlworForVariable(*theInput);
    break;
  case LET:
    v.beginVisitFlworLetVariable(*theInput, theMaterialize, getVarName());
    v.endVisitFlworLetVariable(*theInput);
    break;
  default:
    ZORBA_ASSERT ( false );
  }
}


/***************************************************************************//**

********************************************************************************/
xqpStringStore ForLetClause::getVarName() const
{
#ifndef NDEBUG
  return theVarName;
#else
  return std::string("");
#endif
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  OrderByClause                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
OrderByClause::OrderByClause (
    std::vector<OrderSpec> aOrderSpecs,
    bool aStable )
  :
  theOrderSpecs ( aOrderSpecs ),
  theStable ( aStable )
{
}
  

/***************************************************************************//**

********************************************************************************/
void OrderByClause::accept ( PlanIterVisitor& v ) const
{
  // TODO
  std::vector<OrderSpec>::const_iterator iter;
  for ( iter = theOrderSpecs.begin() ; iter != theOrderSpecs.end(); iter++ )
  {
    iter->accept ( v );
  }
}


/***************************************************************************//**

********************************************************************************/
uint32_t OrderByClause::getStateSizeOfSubtree() const
{
  uint32_t size = 0;

  std::vector<OrderSpec>::const_iterator iter;
  std::vector<OrderSpec>::const_iterator end = theOrderSpecs.end();
  for (iter = theOrderSpecs.begin(); iter != end; iter++ )
  {
    size += iter->theInput->getStateSizeOfSubtree();
  }

  return size;
}


/***************************************************************************//**

********************************************************************************/
void OrderByClause::open( PlanState& planState, uint32_t& offset)
{
  std::vector<OrderSpec>::const_iterator iter;
  for (iter = theOrderSpecs.begin(); iter != theOrderSpecs.end(); iter++)
  {
    iter->open(planState, offset);

    if (iter->theCollation.size() != 0) 
    {
      iter->theCollator = planState.theRuntimeCB->theCollationCache->
                          getCollator(iter->theCollation);
    }
    else
    {
      iter->theCollator = planState.theRuntimeCB->theCollationCache->
                          getDefaultCollator();
    }
  }
}


/***************************************************************************//**

********************************************************************************/
void OrderByClause::reset(PlanState& planState)
{
  std::vector<OrderSpec>::iterator iter = theOrderSpecs.begin();
  std::vector<OrderSpec>::iterator end = theOrderSpecs.end();
  for (; iter != end; iter++)
  {
    iter->theInput->reset(planState);
  }
}


/***************************************************************************//**

********************************************************************************/
void OrderByClause::close(PlanState& planState)
{
  std::vector<OrderSpec>::iterator iter = theOrderSpecs.begin();
  std::vector<OrderSpec>::iterator end = theOrderSpecs.end();
  for (; iter != end; iter++)
  {
    iter->theInput->close(planState);
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GroupByClause                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
GroupByClause::GroupByClause (
    std::vector<GroupingSpec> aGroupingSpecs,
    std::vector<GroupingOuterVar> aOuterVars,
    PlanIter_t aWhere)
  :
  theGroupingSpecs ( aGroupingSpecs ), 
  theOuterVars ( aOuterVars ),
  theWhere(aWhere)
{
}


/***************************************************************************//**

********************************************************************************/
void GroupByClause::accept(PlanIterVisitor& v) const
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
  for ( iterOuterVars = theOuterVars.begin() ;
        iterOuterVars != theOuterVars.end();
        iterOuterVars++ )
  {
    v.beginVisitFlworGroupByOuterVar();
    iterOuterVars->accept(v);
    v.endVisitFlworGroupByOuterVar();
  }
  v.endVisitFlworGroupBy();
}


/***************************************************************************//**

********************************************************************************/
uint32_t GroupByClause::getStateSizeOfSubtree() const
{
  uint32_t size = 0;
  std::vector<GroupingSpec>::const_iterator iter;
  std::vector<GroupingSpec>::const_iterator end = theGroupingSpecs.end();
  for (iter = theGroupingSpecs.begin(); iter != end; ++iter)
  {
    size += iter->getStateSizeOfSubtree();
  }
  
  std::vector<GroupingOuterVar>::const_iterator iterOuterVars;
  for ( iterOuterVars = theOuterVars.begin();
        iterOuterVars != theOuterVars.end();
        iterOuterVars++ )
  {
    size += iterOuterVars->getStateSizeOfSubtree();
  }

  if (theWhere != 0)
    size += theWhere->getStateSizeOfSubtree();

  return size;
}


/***************************************************************************//**

********************************************************************************/
void GroupByClause::open(PlanState& planState, uint32_t& offset)
{ 
  std::vector<GroupingSpec>::iterator iter = theGroupingSpecs.begin();
  std::vector<GroupingSpec>::iterator end = theGroupingSpecs.end();
  for (; iter != end; ++iter)
  {
    iter->open(planState, offset);

    if (iter->theCollation.size() != 0) 
    {
      iter->theCollator = planState.theRuntimeCB->theCollationCache->
                          getCollator(iter->theCollation);
    }
    else
    {
      iter->theCollator = planState.theRuntimeCB->theCollationCache->
                          getDefaultCollator();
    }
  }

  std::vector<GroupingOuterVar>::iterator iterOuterVars = theOuterVars.begin();
  std::vector<GroupingOuterVar>::iterator outerEnd = theOuterVars.end();
  for (; iterOuterVars != outerEnd; ++iterOuterVars)
  {
    iterOuterVars->open(planState, offset);
  }

  if (theWhere != 0)
    theWhere->open(planState, offset);
}


/***************************************************************************//**

********************************************************************************/
void GroupByClause::reset(PlanState& planState)
{
  std::vector<GroupingSpec>::const_iterator iter = theGroupingSpecs.begin();
  std::vector<GroupingSpec>::iterator end = theGroupingSpecs.end();
  for (; iter != end; ++iter)
  {
    iter->reset(planState);
  }

  std::vector<GroupingOuterVar>::iterator lOuterVarIter = theOuterVars.begin();
  std::vector<GroupingOuterVar>::iterator outerEnd = theOuterVars.end();
  for (; lOuterVarIter != outerEnd; ++lOuterVarIter)
  {
    lOuterVarIter->reset(planState);
  }

  if (theWhere != 0)
    theWhere->reset(planState);
}


/***************************************************************************//**

********************************************************************************/
void GroupByClause::close(PlanState& planState)
{
  std::vector<GroupingSpec>::iterator iter =  theGroupingSpecs.begin();
  std::vector<GroupingSpec>::iterator end = theGroupingSpecs.end();
  for (; iter != end; ++iter)
  {
    iter->close(planState);
  }

  std::vector<GroupingOuterVar>::iterator lOuterVarIter = theOuterVars.begin();
  std::vector<GroupingOuterVar>::iterator outerEnd = theOuterVars.end();
  for (; lOuterVarIter != outerEnd; ++lOuterVarIter)
  {
    lOuterVarIter->close(planState);
  }

  if (theWhere != 0)
    theWhere->close(planState);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  FLWORIterator                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**
  Constructor

  @param loc location
  @param forLetClauses For and Lets: Attention the order matters!
  @param whereClause The where-clause iterator. Can be null
  @param orderByClause The order by expressions. Can be null
  @param returnClause The return expression.
  @param isUpdating Whether this flwor is an updating expr or not.

********************************************************************************/
FLWORIterator::FLWORIterator(
    const QueryLoc& loc,
    std::vector<ForLetClause>& aForLetClauses,
    PlanIter_t& aWhereClause,
    GroupByClause* aGroupByClauses,
    OrderByClause* aOrderByClause,
    PlanIter_t& aReturnClause,
    bool aIsUpdating)
  :
  Batcher<FLWORIterator>(loc),
  theForLetClauses(aForLetClauses),
  theWhereClause(aWhereClause),
  theGroupByClause(aGroupByClauses),
  theOrderByClause(aOrderByClause),
  theReturnClause(aReturnClause),
  theIsUpdating(aIsUpdating),
  theNumBindings(aForLetClauses.size())
{
  if ( theOrderByClause == 0 || theOrderByClause->theOrderSpecs.size() == 0 )
  {
    theOrderByClause = 0;
    doOrderBy = false;
  }
  else
  {
    doOrderBy = true;
  }
  
  if ( theGroupByClause == 0 )
  {
    doGroupBy = false;
  }
  else
  {
    doGroupBy = true;
  }
}


/***************************************************************************//**

********************************************************************************/
FLWORIterator::~FLWORIterator()
{
  if ( doOrderBy )
  {
    delete theOrderByClause;
  }

  if( doGroupBy)
  { 
    delete theGroupByClause;
  }
}



/*******************************************************************************

********************************************************************************/
bool FLWORIterator::nextImpl ( store::Item_t& result, PlanState& planState ) const
{
  //Needed variables
  int curVar = 0;
  store::Item_t curItem;
  std::auto_ptr<store::PUL> pul;

  FlworState* flworState;
  DEFAULT_STACK_INIT(FlworState, flworState, planState);

  assert(flworState->theVarBindingState.size() > 0);

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
        resetVariable ( curVar, flworState, planState );
        --curVar;

        // If there are no more bindings for the outer-most var (curVar == -1),
        // then if we had to Order of Group we need to return the results,
        // otherwise we just need to indicate that we finished by returning NULL.
        if ( curVar == -1 )
        {
          if (theIsUpdating)
          {
            result = pul.release();
            STACK_PUSH(true, flworState);
          }
          else if(doOrderBy)
          {
            if(doGroupBy)
            {
              groupAndOrder(flworState, planState);
            }

            flworState->theOrderMapIter = flworState->theOrderMap->begin();

            while ( flworState->theOrderMapIter != flworState->theOrderMap->end() )
            {
              flworState->theOrderResultIter = flworState->theOrderMapIter->second;

              while ( flworState->theOrderResultIter->next(result) )
              {
                STACK_PUSH ( true, flworState );
              }
              ++ ( flworState->theOrderMapIter );
            }
          }
          else if(doGroupBy)
          {
            flworState->theGroupMapIter = flworState->theGroupMap->begin();
            while ( flworState->theGroupMapIter != flworState->theGroupMap->end() )
            {
              bindGroupBy( flworState->theGroupMapIter, flworState, planState );
              if(evalToBool(theGroupByClause->theWhere, planState)){
                while(consumeNext(result, theReturnClause, planState)) {
                  STACK_PUSH ( true, flworState );
                }
              }
              theReturnClause->reset(planState);
              ++flworState->theGroupMapIter;
            }
          }

          goto stop;
        }
      }
    } // build next full tuple of var bindings

    // After binding all variables, we check first the where clause
    if ( evalToBool( theWhereClause,  planState  ) )
    {
      // If we do not need to do ordering, grouping, or pul gneration, we 
      // compute and return the items produced by the ReturnClause. Else, we
      // have to  materialize the result.
      if(doGroupBy)
      {
        matVarsAndGroupBy ( flworState, planState );
      }
      else if (theIsUpdating)
      {
        while(consumeNext(curItem, theReturnClause, planState)) 
        {
          ZORBA_FATAL(curItem->isPul(), "");

          pul->mergeUpdates(curItem);
        }
        theReturnClause->reset(planState);
      }
      else if ( !doOrderBy )
      {
        while ( consumeNext(result, theReturnClause, planState) )
        {
          STACK_PUSH ( true, flworState );
        }
        theReturnClause->reset(planState);
      }
      else
      {
        matResultAndOrder ( flworState, planState );
      }
    }

    // curVar = theNumBindings - 1 indicates that we have to do the next binding level
    curVar = theNumBindings - 1;
  }

 stop:
  STACK_END (flworState);
}



/***************************************************************************//**
  Compute the next value, if any, for the given var, and bind that value to all
  the references of the variable. Return true if there was a next value, and
  false otherwise.
********************************************************************************/
bool FLWORIterator::bindVariable (
    int varNo,
    FlworState* flworState,
    PlanState& planState ) const
{
  const ForLetClause& lForLetClause = theForLetClauses[varNo];

  switch (lForLetClause.theType)
  {
  // In the case of a FOR var, we compute the next item of the input and bind
  // it to all the variable references.
  case ForLetClause::FOR :
  {
    store::Item_t lItem;
    if (!consumeNext ( lItem, lForLetClause.theInput.getp(), planState ))
    {
      return false;
    }

    // We increase the position counter
    ++ ( flworState->theVarBindingState[varNo] );

    std::vector<ForVarIter_t>::const_iterator vrefIter;
    std::vector<ForVarIter_t>::const_iterator end;

    end = lForLetClause.theForVarRefs.end();
    for (vrefIter = lForLetClause.theForVarRefs.begin();
         vrefIter != end;
         ++vrefIter)
    {
      (*vrefIter)->bind(lItem.getp(), planState);
    }

    if ( !lForLetClause.thePosVarRefs.empty() )
    {
      store::Item_t posItem;
      GENV_ITEMFACTORY->createInteger(posItem,
                                      Integer::parseInt(flworState->theVarBindingState[varNo]));

      end = lForLetClause.thePosVarRefs.end();
      for (vrefIter = lForLetClause.thePosVarRefs.begin();
           vrefIter != end;
           ++vrefIter)
      {
        (*vrefIter)->bind(posItem.getp(), planState);
      }
    }

    return true;
  }
  case ForLetClause::LET :
  {      
    // If the var is already bound, there is no next value for it, so return false.
    if ( flworState->theVarBindingState[varNo] == 1 )
    {
      return false;
    }

    store::Iterator_t iterWrapper = new PlanIteratorWrapper(lForLetClause.theInput,
                                                            planState);
    std::vector<LetVarIter_t>::const_iterator vrefIter;
    std::vector<LetVarIter_t>::const_iterator end = lForLetClause.theLetVarRefs.end();

    // Depending on the query, we might need to materialize the LET-Binding
    if ( lForLetClause.theMaterialize )
    {
      store::TempSeq_t tmpSeq = GENV_STORE.createTempSeq(iterWrapper, false, true);

      for (vrefIter = lForLetClause.theLetVarRefs.begin();
           vrefIter != end;
           ++vrefIter)
      {
        store::Iterator_t iter = tmpSeq->getIterator();
        iter->open();
        (*vrefIter)->bind(iter, planState);
      }
    }
    else
    {
      for (vrefIter = lForLetClause.theLetVarRefs.begin();
           vrefIter != end;
           vrefIter++)
      {
        (*vrefIter)->bind(iterWrapper, planState);
      }
    }

    ++ ( flworState->theVarBindingState[varNo] );
    return true;
  }
  default:
    //That should never happen
    ZORBA_ASSERT ( false );
  }

  return false;
}


/***************************************************************************//**
  Reset the iterator the computes the domain/value of the given variable.
********************************************************************************/
void FLWORIterator::resetVariable(
    int varNo,
    FlworState* flworState,
    PlanState& planState) const
{
  theForLetClauses[varNo].theInput->reset( planState );
  flworState->theVarBindingState[varNo] = 0;
}


/***************************************************************************//**
  Evaluates the predicateIter to the EBV. If the predicateIter = NULL true is
  returned.
********************************************************************************/
bool FLWORIterator::evalToBool(
    const PlanIter_t& predicateIter,
    PlanState& planState) const
{
  if ( predicateIter == NULL )
    return true;

  store::Item_t boolValue;
  if (!consumeNext ( boolValue, predicateIter.getp(), planState ))
    return false;

  bool value = boolValue->getBooleanValue();
  predicateIter->reset ( planState );
  return value;
}


/***************************************************************************//**
  All FOR and LET vars are bound when this method is called. The method computes
  the order-by tuple T and the return-clause sequence R for the current var
  bindings. Then, it inserts the pair (T, I(R)) into theOrderMap (where I is
  an iterator over the temp seq storing R).
********************************************************************************/
void FLWORIterator::matResultAndOrder(
    FlworState* flworState,
    PlanState& planState) const
{
  ZORBA_ASSERT ( doOrderBy );

  std::vector<OrderSpec>& lOrderSpecs = theOrderByClause->theOrderSpecs;

  std::vector<OrderSpec>::const_iterator lSpecIter = lOrderSpecs.begin();
  std::vector<store::Item_t> orderKey;

  while ( lSpecIter != lOrderSpecs.end() )
  {
    orderKey.push_back(NULL);
    store::Item_t& orderKeyItem = orderKey.back();
    if (consumeNext ( orderKeyItem, lSpecIter->theInput, planState ))
    {
      store::Item_t temp;
      if (consumeNext ( temp, lSpecIter->theInput, planState ))
      {
        ZORBA_ERROR_DESC( XPTY0004, "Expected a singleton" );
      }
    }
    lSpecIter->theInput->reset(planState);
    ++lSpecIter;
  }

  store::Iterator_t iterWrapper = new PlanIteratorWrapper(theReturnClause, planState);
  store::TempSeq_t result = GENV_STORE.createTempSeq(iterWrapper, false, false);
  store::Iterator_t iter = result->getIterator();
  iter->open(); //where is this iterator closed?

  flworState->theOrderMap->insert(std::pair<std::vector<store::Item_t>,
                                  store::Iterator_t>(orderKey, iter));

  theReturnClause->reset(planState); 
}


/***************************************************************************//**
  All FOR and LET vars are bound when this method is called. The method computes
  the order-by tuple T and then checks whether T is in the GroupMap already. If
  not, it inserts T in the GroupMap, together with one temp sequence for each of
  the non-grouping vars, storing the current value of the non-grouping var. If
  yes, it appends to the each of the temp sequences associated with T the current
  value of each non-grouping var.
********************************************************************************/
void FLWORIterator::matVarsAndGroupBy (
    FlworState* flworState,
    PlanState& planState ) const
{
  ZORBA_ASSERT ( doGroupBy );

  GroupTuple* lGroupTuple = new GroupTuple();
  std::vector<store::Item_t>& lGroupTupleItems = lGroupTuple->theItems;
  std::vector<store::Item_t>& lGroupTupleValues = lGroupTuple->theTypedValues;

  std::vector<GroupingSpec> lgroupSpecs = theGroupByClause->theGroupingSpecs;
  std::vector<GroupingSpec>::iterator lSpecIter = lgroupSpecs.begin();
  std::vector<GroupingSpec>::iterator end = lgroupSpecs.end();

  while ( lSpecIter != end )
  {
    lGroupTupleItems.push_back(NULL);
    store::Item_t& tupleItem = lGroupTupleItems.back();
    
    lGroupTupleValues.push_back(NULL);
    store::Item_t& tupleValue = lGroupTupleValues.back();

    bool status = consumeNext(tupleItem, lSpecIter->theInput, planState);

    if(status)
    {
      store::Iterator_t lTypedValueIter;

      tupleItem->getTypedValue(tupleValue, lTypedValueIter);

      if (lTypedValueIter != NULL)
      {
        lTypedValueIter->open();
        if(lTypedValueIter->next(tupleValue))
        {
          store::Item_t temp;
          if (lTypedValueIter->next(temp))
          {
            ZORBA_ERROR_DESC(XPTY0004,
                             "Expected a singleton (atomization has more than one value)" );
          }
        }
      }

      // check that there are no more values for the current grouping column
      store::Item_t temp;
      if (consumeNext(temp, lSpecIter->theInput, planState))
      {
        ZORBA_ERROR_DESC ( XPTY0004, "Expected a singleton" );
      }
    }

    lSpecIter->reset(planState);
    ++lSpecIter;
  }

  GroupHashMap* groupMap = flworState->theGroupMap;

  std::vector<GroupingOuterVar> outerVars = theGroupByClause->theOuterVars;
  std::vector<store::TempSeq_t>* outerVarSequences = 0;
  long numOuterVars = outerVars.size();

  if (groupMap->get(lGroupTuple, outerVarSequences))
  {
    for (long i = 0; i < numOuterVars; ++i)
    {
      store::Iterator_t iterWrapper = new PlanIteratorWrapper(outerVars[i].theInput,
                                                              planState);
      (*outerVarSequences)[i]->append(iterWrapper, true);

      outerVars[i].reset(planState);
    }

    delete lGroupTuple;
  }
  else
  {
    outerVarSequences = new std::vector<store::TempSeq_t>();

    for (long i = 0; i < numOuterVars; ++i)
    {
      store::Iterator_t iterWrapper = new PlanIteratorWrapper(outerVars[i].theInput,
                                                              planState);
      store::TempSeq_t result = GENV_STORE.createTempSeq(iterWrapper, true, false);

      outerVarSequences->push_back(result);

      outerVars[i].reset(planState);
    }

    groupMap->insert(lGroupTuple, outerVarSequences);
  }
}


/*******************************************************************************

********************************************************************************/
void FLWORIterator::groupAndOrder(
    FlworState* flworState,
    PlanState& planState ) const
{
  GroupHashMap* lGroupMap = flworState->theGroupMap;
  GroupHashMap::iterator lGroupMapIter = lGroupMap->begin();
  while ( lGroupMapIter != lGroupMap->end() )
  {
    bindGroupBy ( lGroupMapIter, flworState, planState );    
    if(evalToBool(theGroupByClause->theWhere, planState)){
      matResultAndOrder(flworState, planState);
    }

    ++lGroupMapIter;
  }
}


/***************************************************************************//**

********************************************************************************/
void FLWORIterator::bindGroupBy ( 
    GroupHashMap::iterator lGroupMapIter,
    FlworState* flworState,
    PlanState& planState ) const
{
  //Bind grouping vars
  GroupTuple* lGroupKey = ( *lGroupMapIter ).first;
  std::vector<store::Item_t>::iterator lGroupKeyIter = lGroupKey->theItems.begin();
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


/*******************************************************************************

********************************************************************************/
void FLWORIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<FlworState>::createState(planState, this->stateOffset, offset);

  FlworState* flworState = StateTraitsImpl<FlworState>::getState(planState,
                                                                 this->stateOffset);
  if(doGroupBy)
  {
    flworState->init(planState,
                     theNumBindings,
                     (doOrderBy ? &theOrderByClause->theOrderSpecs : NULL),
                     &theGroupByClause->theGroupingSpecs); 
  }
  else if ( doOrderBy ) 
  {
    flworState->init(planState,
                     theNumBindings,
                     &theOrderByClause->theOrderSpecs,
                     0);
  }
  else 
  {
    flworState->init(planState, theNumBindings);
  }

#ifndef NDEBUG
  // some variables must have been bound
  assert(flworState->theVarBindingState.size() > 0);
#endif

  std::vector<ForLetClause>::const_iterator iter = theForLetClauses.begin();
  std::vector<ForLetClause>::const_iterator end = theForLetClauses.end();
  for (; iter != end; iter++)
  {
    iter->theInput->open(planState, offset);
  }

  theReturnClause->open(planState, offset);

  if ( theWhereClause != NULL )
    theWhereClause->open(planState, offset);
  
  if ( doGroupBy)
    theGroupByClause->open(planState, offset);
  
  if ( doOrderBy )
    theOrderByClause->open(planState, offset);
}


/*******************************************************************************

********************************************************************************/
void FLWORIterator::resetImpl(PlanState& planState) const
{
  theReturnClause->reset(planState);

  if (theWhereClause != NULL)
    theWhereClause->reset(planState);

  if (theOrderByClause != NULL)
    theOrderByClause->reset(planState);
  
  if (theGroupByClause != NULL)
    theGroupByClause->reset(planState);

  std::vector<ForLetClause>::const_iterator iter = theForLetClauses.begin();
  std::vector<ForLetClause>::const_iterator end = theForLetClauses.end();
  for (; iter != end; ++iter)
  {
    iter->theInput->reset(planState);
  }

  StateTraitsImpl<FlworState>::reset(planState, this->stateOffset);
}


/*******************************************************************************

********************************************************************************/
void FLWORIterator::closeImpl(PlanState& planState)
{
  theReturnClause->close(planState);

  if (theWhereClause != 0)
    theWhereClause->close(planState);

  if (theOrderByClause != 0)
    theOrderByClause->close(planState);

  if(theGroupByClause != 0)
    theGroupByClause->close(planState);

  std::vector<ForLetClause>::const_iterator iter = theForLetClauses.begin();
  std::vector<ForLetClause>::const_iterator end = theForLetClauses.end();
  for (; iter != end; iter++)
  {
    iter->theInput->close(planState);
  }
  
  StateTraitsImpl<FlworState>::destroyState(planState, this->stateOffset);
}


/*******************************************************************************

********************************************************************************/
uint32_t FLWORIterator::getStateSize() const  
{
  return sizeof ( FlworState); 
}


/*******************************************************************************

********************************************************************************/
uint32_t FLWORIterator::getStateSizeOfSubtree() const
{
  int32_t size = this->getStateSize();

  std::vector<ForLetClause>::const_iterator iter = theForLetClauses.begin();
  std::vector<ForLetClause>::const_iterator end = theForLetClauses.end();
  for (; iter != end; ++iter)
  {
    size += iter->theInput->getStateSizeOfSubtree();
  }

  size += theReturnClause->getStateSizeOfSubtree();

  if ( theWhereClause != NULL )
    size += theWhereClause->getStateSizeOfSubtree();

  if ( doOrderBy )
    size += theOrderByClause->getStateSizeOfSubtree();

  if(doGroupBy)
    size += theGroupByClause->getStateSizeOfSubtree();

  return size;
}


/*******************************************************************************

********************************************************************************/
void FLWORIterator::accept ( PlanIterVisitor& v ) const
{
  // TODO
  v.beginVisit ( *this );

  std::vector<ForLetClause>::const_iterator iter = theForLetClauses.begin();
  std::vector<ForLetClause>::const_iterator end = theForLetClauses.end();
  for (; iter != end; ++iter)
  {
    iter->accept(v);
  }

  if ( theWhereClause != NULL )
  {
    v.beginVisitFlworWhereClause(*theWhereClause);
    v.endVisitFlworWhereClause(*theWhereClause);
  }

  if ( theGroupByClause )
    theGroupByClause->accept ( v );
 
  if ( doOrderBy )
    theOrderByClause->accept ( v );

  v.beginVisitFlworReturn(*theReturnClause);
  v.endVisitFlworReturn(*theReturnClause);

  v.endVisit(*this);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  FlworState                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

FlworState::FlworState() : theOrderMap(0), theGroupMap(0)
{
}


/*******************************************************************************

********************************************************************************/
FlworState::~FlworState()
{
  if ( theOrderMap )
  {
    delete theOrderMap;
    theOrderMap = 0;
  }

  if ( theGroupMap )
  {
    GroupHashMap::iterator iter = theGroupMap->begin();
    GroupHashMap::iterator end = theGroupMap->end();
    for (; iter != end; ++iter)
    {
      delete (*iter).first;
      delete (*iter).second;
    }

    delete theGroupMap;
    theGroupMap = 0;
  }
}


/*******************************************************************************
  Init the state for a certain nb of variables but not the ordering
  @nb_variables  Number of FOR and LET clauses
********************************************************************************/
void FlworState::init(PlanState& planState, size_t numVars)
{
  PlanIteratorState::init(planState);

  std::vector<uint32_t> v(numVars, 0);
  theVarBindingState.swap (v);
  assert(theVarBindingState.size() > 0);
}


/*******************************************************************************
  Init the state for a certain nb of variables, ordering and grouping

  @nb_variables  Number of FOR and LET clauses
  @orderSpecs    The OrderSpec which defines how to compare during ordering
  @groupingCollators The GoupingCollators which defines how to compare during grouping
********************************************************************************/
void FlworState::init(
    PlanState& planState,
    size_t numVars,
    std::vector<OrderSpec>* orderSpecs,
    std::vector<GroupingSpec>* groupingSpecs)
{
  init (planState, numVars);

  if(orderSpecs != 0)
  {
    OrderTupleCmp cmp(planState.theRuntimeCB, orderSpecs);
    theOrderMap = new FLWORIterator::order_map_t(cmp);
  }
  
  if(groupingSpecs != 0)
  {
    GroupTupleCmp cmp(planState.theRuntimeCB, groupingSpecs);
    theGroupMap = new GroupHashMap(cmp, 1024, false);
  }
}


/*******************************************************************************
  Resets the state
********************************************************************************/
void FlworState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);

  assert(theVarBindingState.size() > 0);

  size_t size = theVarBindingState.size();

  ::memset(&theVarBindingState[0], 0, size * sizeof(uint32_t));

  theOrderResultIter = 0;

  if ( theOrderMap != 0 )
  {
    theOrderMap->clear();
  }

  if(theGroupMap != 0)
  {
    GroupHashMap::iterator iter = theGroupMap->begin();
    GroupHashMap::iterator end = theGroupMap->end();
    for (; iter != end; ++iter )
    {
      delete (*iter).first;
      delete (*iter).second;
    }

    theGroupMap->clear();
  }
}


}
}
