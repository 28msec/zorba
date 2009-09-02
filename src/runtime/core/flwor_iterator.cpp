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

#include "context/static_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/core/flwor_iterator.h"
#include "runtime/core/gflwor/comp_function.h"
#include "runtime/api/runtimecb.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/visitors/planitervisitor.h"

#include "system/globalenv.h"

#include "store/api/temp_seq.h"
#include "store/api/store.h"
#include "store/api/pul.h"
#include "store/api/item_factory.h"


#ifndef WIN32
#include <sys/time.h>
#endif

#include <algorithm>


namespace zorba
{

namespace flwor
{
SERIALIZABLE_CLASS_VERSIONS(OrderByClause)
END_SERIALIZABLE_CLASS_VERSIONS(OrderByClause)

SERIALIZABLE_CLASS_VERSIONS(GroupByClause)
END_SERIALIZABLE_CLASS_VERSIONS(GroupByClause)

SERIALIZABLE_CLASS_VERSIONS(ForLetClause)
END_SERIALIZABLE_CLASS_VERSIONS(ForLetClause)

SERIALIZABLE_CLASS_VERSIONS(FLWORIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FLWORIterator)

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ForLetClause                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**
  Creates a new ForClause for a FOR var.

  @param var The var_expr for this FOR variable.
  @param VarRefs The ForVarIterators representing the references to this var.
  @param aInput The iterator computing the domain expr of this variable.
********************************************************************************/
ForLetClause::ForLetClause (
    const store::Item_t& aVarName,
    const std::vector<PlanIter_t>& varRefs,
    PlanIter_t& aInput)
  :
  theVarName(aVarName->getStringValue()),
  theType(FOR),
  theInput(aInput),
  theMaterialize(false)
{
  castIterVector<ForVarIterator>(theForVarRefs, varRefs);
}


/***************************************************************************//**
  Creates a new ForClause for a FOR var and its associated positional var.

  @param var The var_expr for this FOR variable.
  @param varRefs The ForVarIterators representing the references to this var.
  @param aPosVars ForVarIterators representing the references to the associated
         positional var.
  @param aInput The iterator computing the value of this variable.
********************************************************************************/
ForLetClause::ForLetClause (
    const store::Item_t& aVarName,
    const std::vector<PlanIter_t>& varRefs,
    const std::vector<PlanIter_t>& aPosVars,
    PlanIter_t& aInput)
  :
  theVarName(aVarName->getStringValue()),
  theType(FOR),
  theInput(aInput),
  theMaterialize(false)
{
  castIterVector<ForVarIterator>(theForVarRefs, varRefs);
  castIterVector<ForVarIterator>(thePosVarRefs, aPosVars);
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
    const store::Item_t& aVarName,
    const std::vector<PlanIter_t>& aLetVars,
    PlanIter_t& aInput,
    bool aNeedsMaterialization )
  :
#ifndef NDEBUG
  theVarName(aVarName->getStringValue()),
#endif
  theType(LET),
  theInput(aInput),
  theMaterialize(aNeedsMaterialization)
{
  castIterVector<LetVarIterator>(theLetVarRefs, aLetVars);
}


/***************************************************************************//**

********************************************************************************/
void ForLetClause::accept(PlanIterVisitor& v) const
{
  // TODO correct for visitor
  switch ( theType )
  {
  case FOR:
    v.beginVisitFlworForVariable(getVarName(), theForVarRefs, thePosVarRefs);
    theInput->accept(v);
    v.endVisitFlworForVariable();
    break;
  case LET:
    v.beginVisitFlworLetVariable(theMaterialize, getVarName(), theLetVarRefs);
    theInput->accept(v);
    v.endVisitFlworLetVariable();
    break;
  default:
    ZORBA_ASSERT ( false );
  }
}


/***************************************************************************//**

********************************************************************************/
xqpStringStore_t ForLetClause::getVarName() const
{
#ifndef NDEBUG
  return theVarName;
#else
  return new xqpStringStore();
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
    const std::vector<OrderSpec>& orderSpecs,
    bool stable)
  :
  theOrderSpecs(orderSpecs),
  theStable(stable)
{
}
  

/***************************************************************************//**

********************************************************************************/
void OrderByClause::accept(PlanIterVisitor& v) const
{
  std::vector<OrderSpec>::const_iterator iter;
  std::vector<OrderSpec>::const_iterator end = theOrderSpecs.end();
  for (iter = theOrderSpecs.begin(); iter != end; ++iter)
  {
    iter->accept(v);
  }
}


/***************************************************************************//**

********************************************************************************/
uint32_t OrderByClause::getStateSizeOfSubtree() const
{
  uint32_t size = 0;

  std::vector<OrderSpec>::const_iterator iter;
  std::vector<OrderSpec>::const_iterator end = theOrderSpecs.end();
  for (iter = theOrderSpecs.begin(); iter != end; ++iter)
  {
    size += iter->theDomainIter->getStateSizeOfSubtree();
  }

  return size;
}


/***************************************************************************//**

********************************************************************************/
void OrderByClause::open(static_context* sctx, PlanState& planState, uint32_t& offset)
{
  std::vector<OrderSpec>::iterator iter;
  std::vector<OrderSpec>::const_iterator end = theOrderSpecs.end();
  for (iter = theOrderSpecs.begin(); iter != end; ++iter)
  {
    iter->open(planState, offset);

    if (iter->theCollation.size() != 0) 
    {
      iter->theCollator = sctx->get_collation_cache()->
                          getCollator(iter->theCollation);
    }
    else
    {
      iter->theCollator = sctx->get_collation_cache()->
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
    iter->theDomainIter->reset(planState);
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
    iter->theDomainIter->close(planState);
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
    std::vector<GroupingOuterVar> aOuterVars)
  :
  theGroupingSpecs ( aGroupingSpecs ), 
  theOuterVars ( aOuterVars )
{
}


/***************************************************************************//**

********************************************************************************/
void GroupByClause::accept(PlanIterVisitor& v) const
{ 
  v.beginVisitGroupByClause();

  std::vector<GroupingSpec>::const_iterator groupIter = theGroupingSpecs.begin();
  std::vector<GroupingSpec>::const_iterator groupEnd = theGroupingSpecs.end();
  for (; groupIter != groupEnd; groupIter++ )
  {
    groupIter->accept(v);
  }

  std::vector<GroupingOuterVar>::const_iterator iterOuterVars;
  for ( iterOuterVars = theOuterVars.begin() ;
        iterOuterVars != theOuterVars.end();
        iterOuterVars++ )
  {
    iterOuterVars->accept(v);
  }

  v.endVisitGroupByClause();
}


/***************************************************************************//**

********************************************************************************/
uint32_t GroupByClause::getStateSizeOfSubtree() const
{
  uint32_t size = 0;
  std::vector<GroupingSpec>::const_iterator groupIter = theGroupingSpecs.begin();
  std::vector<GroupingSpec>::const_iterator groupEnd = theGroupingSpecs.end();
  for (; groupIter != groupEnd; ++groupIter)
  {
    size += groupIter->getStateSizeOfSubtree();
  }
  
  std::vector<GroupingOuterVar>::const_iterator iterOuterVars;
  for ( iterOuterVars = theOuterVars.begin();
        iterOuterVars != theOuterVars.end();
        iterOuterVars++ )
  {
    size += iterOuterVars->getStateSizeOfSubtree();
  }

  return size;
}


/***************************************************************************//**

********************************************************************************/
void GroupByClause::open(static_context* sctx, PlanState& planState, uint32_t& offset)
{ 
  std::vector<GroupingSpec>::iterator groupIter = theGroupingSpecs.begin();
  std::vector<GroupingSpec>::iterator groupEnd = theGroupingSpecs.end();
  for (; groupIter != groupEnd; ++groupIter)
  {
    groupIter->open(planState, offset);

    if (groupIter->theCollation.size() != 0) 
    {
      groupIter->theCollator = sctx->get_collation_cache()->
                               getCollator(groupIter->theCollation);
    }
    else
    {
      groupIter->theCollator = sctx->get_collation_cache()->
                               getDefaultCollator();
    }
  }

  std::vector<GroupingOuterVar>::iterator nongroupIter = theOuterVars.begin();
  std::vector<GroupingOuterVar>::iterator nongroupEnd = theOuterVars.end();
  for (; nongroupIter != nongroupEnd; ++nongroupIter)
  {
    nongroupIter->open(planState, offset);
  }
}


/***************************************************************************//**

********************************************************************************/
void GroupByClause::reset(PlanState& planState)
{
  std::vector<GroupingSpec>::const_iterator groupIter = theGroupingSpecs.begin();
  std::vector<GroupingSpec>::iterator groupEnd = theGroupingSpecs.end();
  for (; groupIter != groupEnd; ++groupIter)
  {
    groupIter->reset(planState);
  }

  std::vector<GroupingOuterVar>::iterator nongroupIter = theOuterVars.begin();
  std::vector<GroupingOuterVar>::iterator nongroupEnd = theOuterVars.end();
  for (; nongroupIter != nongroupEnd; ++nongroupIter)
  {
    nongroupIter->reset(planState);
  }
}


/***************************************************************************//**

********************************************************************************/
void GroupByClause::close(PlanState& planState)
{
  std::vector<GroupingSpec>::iterator groupIter =  theGroupingSpecs.begin();
  std::vector<GroupingSpec>::iterator groupEnd = theGroupingSpecs.end();
  for (; groupIter != groupEnd; ++groupIter)
  {
    groupIter->close(planState);
  }

  std::vector<GroupingOuterVar>::iterator nongroupIter = theOuterVars.begin();
  std::vector<GroupingOuterVar>::iterator nongroupEnd = theOuterVars.end();
  for (; nongroupIter != nongroupEnd; ++nongroupIter)
  {
    nongroupIter->close(planState);
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  FlworState                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

FlworState::FlworState() 
  :
  theNumTuples(0),
  theCurTuplePos(0),
  theGroupMap(0)
{
}


/*******************************************************************************

********************************************************************************/
FlworState::~FlworState()
{
  clearSortTable();

  clearGroupMap();

  delete theGroupMap;
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

  theNumTuples = 0;
  theCurTuplePos = 0;
}


/*******************************************************************************
  Init the state for a certain nb of variables, ordering and grouping

  @nb_variables  Number of FOR and LET clauses
  @orderSpecs    The OrderSpec which defines how to compare during ordering
  @groupingCollators The GoupingCollators which defines how to compare during grouping
********************************************************************************/
void FlworState::init(
    PlanState& planState,
    TypeManager* tm,
    size_t numVars,
    std::vector<OrderSpec>* orderSpecs,
    std::vector<GroupingSpec>* groupingSpecs)
{
  init(planState, numVars);
 
  if(groupingSpecs != 0)
  {
    GroupTupleCmp cmp(planState.theRuntimeCB, tm, groupingSpecs);
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

  clearSortTable();
  theDataTable.clear();
  theNumTuples = 0;
  theCurTuplePos = 0;

  theOrderResultIter = 0;

  clearGroupMap();
}


/*******************************************************************************

********************************************************************************/
void FlworState::clearSortTable()
{
  ulong numTuples = theSortTable.size();

  for (ulong i = 0; i < numTuples; ++i)
  {
    theSortTable[i].clear();
  }

  theSortTable.clear();
}

/*******************************************************************************

********************************************************************************/
void FlworState::clearGroupMap()
{
  if (theGroupMap == NULL)
    return;

  GroupHashMap::iterator iter = theGroupMap->begin();
  GroupHashMap::iterator end = theGroupMap->end();
  for (; iter != end; ++iter)
  {
    delete (*iter).first;
    delete (*iter).second;
  }
  
  theGroupMap->clear();
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
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<ForLetClause>& aForLetClauses,
    PlanIter_t& aWhereClause,
    GroupByClause* aGroupByClauses,
    OrderByClause* orderByClause,
    PlanIter_t& aReturnClause,
    bool aIsUpdating)
  :
  Batcher<FLWORIterator>(sctx, loc),
  theForLetClauses(aForLetClauses),
  theWhereClause(aWhereClause),
  theGroupByClause(aGroupByClauses),
  theOrderByClause(orderByClause),
  theReturnClause(aReturnClause),
  theIsUpdating(aIsUpdating),
  theNumBindings(aForLetClauses.size())
{
  if (theOrderByClause == 0 || theOrderByClause->theOrderSpecs.size() == 0)
  {
    theOrderByClause = 0;
    doOrderBy = false;
  }
  else
  {
    doOrderBy = true;
  }
  
  if (theGroupByClause == 0)
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
  if (doOrderBy)
  {
    delete theOrderByClause;
  }

  if (doGroupBy)
  { 
    delete theGroupByClause;
  }
}



/*******************************************************************************

********************************************************************************/
bool FLWORIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  //Needed variables
  int curVar = 0;
  store::Item_t curItem;
  std::auto_ptr<store::PUL> pul;

  FlworState* iterState;
  DEFAULT_STACK_INIT(FlworState, iterState, planState);

  assert(iterState->theVarBindingState.size() > 0);

  if (theIsUpdating)
    pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  while (true)
  {
    // Here we do the variable bindings from the outer most to the inner most
    while (curVar != theNumBindings)
    {
      // Try to bind the current variable. If the binding of the variable is
      // successfull, we procede with the next binding level. Else, we go a
      // level back and try the previous level
      if (bindVariable(curVar, iterState, planState))
      {
        ++curVar;
      }
      else
      {
        resetVariable(curVar, iterState, planState);
        --curVar;

        // If there are no more bindings for the outer-most var (curVar == -1),
        // then if we had to Order of Group we need to return the results,
        // otherwise we just need to indicate that we finished by returning NULL.
        if ( curVar == -1 )
        {
          if (theIsUpdating)
          {
            result = pul.release();
            STACK_PUSH(true, iterState);
          }
          else if(doOrderBy)
          {
            if(doGroupBy)
            {
              materializeGroupResultForSort(iterState, planState);
            }

            {
#if 0
              double startTime;
              double endTime;

              struct timeval stime;
              gettimeofday(&stime, NULL);
  
              startTime = (double)stime.tv_sec+(1.e-6)*stime.tv_usec;
#endif
              SortTupleCmp cmp(planState.theRuntimeCB,
                               theSctx->get_typemanager(),
                               &theOrderByClause->theOrderSpecs);

              if (theOrderByClause->theStable)
              {
                std::stable_sort(iterState->theSortTable.begin(),
                                 iterState->theSortTable.end(),
                                 cmp);
              }
              else
              {
                std::sort(iterState->theSortTable.begin(),
                          iterState->theSortTable.end(),
                          cmp);
              }
#if 0
              struct timeval etime;
              gettimeofday(&etime, NULL);

              endTime = (double)etime.tv_sec+(1.e-6)*etime.tv_usec;

              std::cout << "Sort Duration: " << (endTime - startTime) << std::endl;
#endif
            }

            iterState->theCurTuplePos = 0;
            iterState->theNumTuples = iterState->theSortTable.size();

            while (iterState->theCurTuplePos < iterState->theNumTuples)
            {
              iterState->theOrderResultIter.transfer(iterState->theDataTable[iterState->theSortTable[iterState->theCurTuplePos].theDataPos]);

              iterState->theOrderResultIter->open();

              while (iterState->theOrderResultIter->next(result))
              {
                STACK_PUSH(true, iterState);
              }

             iterState->theOrderResultIter->close();

              ++(iterState->theCurTuplePos);
            }
          }
          else if(doGroupBy)
          {
            iterState->theGroupMapIter = iterState->theGroupMap->begin();

            while (iterState->theGroupMapIter != iterState->theGroupMap->end())
            {
              bindGroupBy(iterState->theGroupMapIter, iterState, planState);

              while(consumeNext(result, theReturnClause, planState)) 
              {
                STACK_PUSH(true, iterState);
              }

              theReturnClause->reset(planState);
              ++iterState->theGroupMapIter;
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
        matVarsAndGroupBy(iterState, planState);
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
        while (consumeNext(result, theReturnClause, planState))
        {
          STACK_PUSH(true, iterState);
        }
        theReturnClause->reset(planState);
      }
      else
      {
        materializeResultForSort(iterState, planState);
      }
    }

    // curVar = theNumBindings - 1 indicates that we have to do the next binding level
    curVar = theNumBindings - 1;
  }

 stop:
  STACK_END(iterState);
}



/***************************************************************************//**
  Compute the next value, if any, for the given var, and bind that value to all
  the references of the variable. Return true if there was a next value, and
  false otherwise.
********************************************************************************/
bool FLWORIterator::bindVariable(
    int varNo,
    FlworState* iterState,
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
    ++ ( iterState->theVarBindingState[varNo] );

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
                                      Integer::parseInt(iterState->theVarBindingState[varNo]));

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
    if ( iterState->theVarBindingState[varNo] == 1 )
    {
      return false;
    }

    store::Iterator_t iterWrapper = new PlanIteratorWrapper(lForLetClause.theInput,
                                                            planState);
    std::vector<LetVarIter_t>::const_iterator vrefIter;
    std::vector<LetVarIter_t>::const_iterator end = lForLetClause.theLetVarRefs.end();

    // Depending on the query, we might need to materialize the LET-Binding
    if (lForLetClause.theMaterialize)
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

    ++ ( iterState->theVarBindingState[varNo] );
    return true;
  }
  default:
  {
    ZORBA_ASSERT(false);
  }
  }

  return false;
}


/***************************************************************************//**
  Reset the iterator the computes the domain/value of the given variable.
********************************************************************************/
void FLWORIterator::resetVariable(
    int varNo,
    FlworState* iterState,
    PlanState& planState) const
{
  theForLetClauses[varNo].theInput->reset( planState );
  iterState->theVarBindingState[varNo] = 0;
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
  bindings. Then, it inserts the pair (T, I(R)) into theSortArray (where I is
  an iterator over the temp seq storing R).
********************************************************************************/
void FLWORIterator::materializeResultForSort(
    FlworState* iterState,
    PlanState& planState) const
{
  ZORBA_ASSERT(doOrderBy);

  FlworState::SortTable& sortTable = iterState->theSortTable;
  FlworState::DataTable& dataTable = iterState->theDataTable;

  ulong numTuples = sortTable.size();
  sortTable.resize(numTuples + 1);
  dataTable.resize(numTuples + 1);

  // Create the sort tuple

  std::vector<OrderSpec>& orderSpecs = theOrderByClause->theOrderSpecs;
  ulong numSpecs = orderSpecs.size();

  std::vector<store::Item*>& sortKey = sortTable[numTuples].theKeyValues;
  sortKey.resize(numSpecs);

  for (ulong i = 0; i < numSpecs; ++i)
  {
    store::Item_t sortKeyItem;
    if (consumeNext(sortKeyItem, orderSpecs[i].theDomainIter, planState))
    {
      sortKey[i] = sortKeyItem.release();

      store::Item_t temp;
      if (consumeNext(temp, orderSpecs[i].theDomainIter, planState))
      {
        ZORBA_ERROR_DESC(XPTY0004, "Expected a singleton");
      }
    }
    else
    {
      sortKey[i] = NULL;
    }

    orderSpecs[i].theDomainIter->reset(planState);
  }

  sortTable[numTuples].theDataPos = numTuples;

  store::Iterator_t iterWrapper = new PlanIteratorWrapper(theReturnClause, planState);
  store::TempSeq_t resultSeq = GENV_STORE.createTempSeq(iterWrapper, false, false);
  store::Iterator_t resultIter = resultSeq->getIterator();

  dataTable[numTuples].transfer(resultIter);

  theReturnClause->reset(planState); 
}


/*******************************************************************************

********************************************************************************/
void FLWORIterator::materializeGroupResultForSort(
    FlworState* iterState,
    PlanState& planState) const
{
  GroupHashMap* groupMap = iterState->theGroupMap;

  GroupHashMap::iterator groupMapIter = groupMap->begin();
  GroupHashMap::iterator groupMapEnd = groupMap->end();

  while (groupMapIter != groupMapEnd)
  {
    bindGroupBy(groupMapIter, iterState, planState);
  
    materializeResultForSort(iterState, planState);

    ++groupMapIter;
  }
}


/***************************************************************************//**
  All FOR and LET vars are bound when this method is called. The method computes
  the order-by tuple T and then checks whether T is in the GroupMap already. If
  not, it inserts T in the GroupMap, together with one temp sequence for each of
  the non-grouping vars, storing the current value of the non-grouping var. If
  yes, it appends to each of the temp sequences associated with T the current
  value of each non-grouping var.
********************************************************************************/
void FLWORIterator::matVarsAndGroupBy (
    FlworState* iterState,
    PlanState& planState ) const
{
  ZORBA_ASSERT ( doGroupBy );

  GroupTuple* groupTuple = new GroupTuple();
  std::vector<store::Item_t>& lGroupTupleItems = groupTuple->theItems;
  std::vector<store::Item_t>& lGroupTupleValues = groupTuple->theTypedValues;

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

  GroupHashMap* groupMap = iterState->theGroupMap;

  std::vector<GroupingOuterVar> outerVars = theGroupByClause->theOuterVars;
  std::vector<store::TempSeq_t>* outerVarSequences = 0;
  long numOuterVars = outerVars.size();

  if (groupMap->get(groupTuple, outerVarSequences))
  {
    for (long i = 0; i < numOuterVars; ++i)
    {
      store::Iterator_t iterWrapper = new PlanIteratorWrapper(outerVars[i].theInput,
                                                              planState);
      (*outerVarSequences)[i]->append(iterWrapper, true);

      outerVars[i].reset(planState);
    }

    delete groupTuple;
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

    groupMap->insert(groupTuple, outerVarSequences);
  }
}


/***************************************************************************//**
  Binds the values in current tuple of the group map to the var references
  that appear after the groupby clause. 
********************************************************************************/
void FLWORIterator::bindGroupBy( 
    GroupHashMap::iterator groupMapIter,
    FlworState* iterState,
    PlanState& planState) const
{
  // Bind grouping vars
  GroupTuple* groupKey = (*groupMapIter).first;
  std::vector<store::Item_t>::iterator groupKeyIter = groupKey->theItems.begin();

  std::vector<GroupingSpec> groupSpecs = theGroupByClause->theGroupingSpecs;
  std::vector<GroupingSpec>::const_iterator specIter = groupSpecs.begin();
  std::vector<GroupingSpec>::const_iterator specEnd = groupSpecs.end();

  while (specIter != specEnd)
  {
    std::vector<ForVarIter_t>::const_iterator groupVarIter = specIter->theInnerVars.begin();
    std::vector<ForVarIter_t>::const_iterator groupVarEnd = specIter->theInnerVars.end();

    while (groupVarIter != groupVarEnd)
    {
      (*groupVarIter)->bind(*groupKeyIter, planState);
      ++groupVarIter;
    }

    ++specIter;
    ++groupKeyIter;
  }

  // Bind non-grouping vars
  std::vector<store::TempSeq_t>* lVector = (*groupMapIter).second;
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
  StateTraitsImpl<FlworState>::createState(planState, theStateOffset, offset);

  FlworState* iterState = StateTraitsImpl<FlworState>::getState(planState,
                                                                theStateOffset);
  if (doGroupBy || doOrderBy)
  {
    if (doGroupBy)
    {
      iterState->init(planState,
                      theSctx->get_typemanager(),
                      theNumBindings,
                      (doOrderBy ? &theOrderByClause->theOrderSpecs : NULL),
                      &theGroupByClause->theGroupingSpecs); 
    }
    else if (doOrderBy) 
    {
      iterState->init(planState,
                      theSctx->get_typemanager(),
                      theNumBindings,
                      &theOrderByClause->theOrderSpecs,
                      0);
    }
  }
  else 
  {
    iterState->init(planState, theNumBindings);
  }

  // some variables must have been bound
  assert(iterState->theVarBindingState.size() > 0);

  std::vector<ForLetClause>::const_iterator iter = theForLetClauses.begin();
  std::vector<ForLetClause>::const_iterator end = theForLetClauses.end();
  for (; iter != end; ++iter)
  {
    iter->theInput->open(planState, offset);
  }

  theReturnClause->open(planState, offset);

  if (theWhereClause != NULL)
    theWhereClause->open(planState, offset);
  
  if (doGroupBy)
    theGroupByClause->open(theSctx, planState, offset);
  
  if (doOrderBy)
    theOrderByClause->open(theSctx, planState, offset);
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

  StateTraitsImpl<FlworState>::reset(planState, theStateOffset);
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
  for (; iter != end; ++iter)
  {
    iter->theInput->close(planState);
  }
  
  StateTraitsImpl<FlworState>::destroyState(planState, theStateOffset);
}


/*******************************************************************************

********************************************************************************/
uint32_t FLWORIterator::getStateSize() const  
{
  return sizeof(FlworState); 
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
void FLWORIterator::accept(PlanIterVisitor& v) const
{
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



}
}
