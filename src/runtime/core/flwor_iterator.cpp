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

#include "zorbautils/fatal.h"
#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

#include "context/static_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/core/flwor_iterator.h"
#include "runtime/core/gflwor/comp_function.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/visitors/planiter_visitor.h"

#include "system/globalenv.h"

#include "store/api/temp_seq.h"
#include "store/api/store.h"
#include "store/api/pul.h"
#include "store/api/item_factory.h"
#include <zorba/internal/unique_ptr.h>


#ifndef WIN32
#include <sys/time.h>
#endif

#include <algorithm>


namespace zorba
{

namespace flwor
{

SERIALIZABLE_CLASS_VERSIONS(OrderByClause)

SERIALIZABLE_CLASS_VERSIONS(MaterializeClause)

SERIALIZABLE_CLASS_VERSIONS(GroupByClause)

SERIALIZABLE_CLASS_VERSIONS(ForLetClause)

SERIALIZABLE_CLASS_VERSIONS(FLWORIterator)


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
ForLetClause::ForLetClause(
    store::Item* aVarName,
    const std::vector<PlanIter_t>& varRefs,
    PlanIter_t& input)
  :
  theVarName(aVarName->getStringValue()),
  theType(FOR),
  theInput(input),
  theVarRefs(varRefs),
  theSingleItemLETVar(false),
  theDoLazyEval(true)
{
}


/***************************************************************************//**
  Creates a new ForClause for a FOR var and its associated positional var.

  @param var The var_expr for this FOR variable.
  @param varRefs The ForVarIterators representing the references to this var.
  @param aPosVars ForVarIterators representing the references to the associated
         positional var.
  @param aInput The iterator computing the value of this variable.
********************************************************************************/
ForLetClause::ForLetClause(
    store::Item* aVarName,
    const std::vector<PlanIter_t>& varRefs,
    const std::vector<PlanIter_t>& posVarRefs,
    PlanIter_t& input)
  :
  theVarName(aVarName->getStringValue()),
  theType(FOR),
  theInput(input),
  theVarRefs(varRefs),
  thePosVarRefs(posVarRefs),
  theSingleItemLETVar(false),
  theDoLazyEval(true)
{
}


/***************************************************************************//**
  Creates a new ForClause for a LET variable

  @param var The var_expr for this LET variable.
  @param aLetVars Vector of ForVar iterators representing the references to this
         variable.
  @param aInput The iterator computing the value of this variable.
********************************************************************************/
ForLetClause::ForLetClause(
    store::Item* aVarName,
    const std::vector<PlanIter_t>& varRefs,
    PlanIter_t& input,
    bool lazyEval,
    bool needsMaterialization)
  :
  theVarName(aVarName->getStringValue()),
  theType(LET),
  theInput(input),
  theVarRefs(varRefs),
  theSingleItemLETVar(false),
  theDoLazyEval(lazyEval)
{
}


/***************************************************************************//**

********************************************************************************/
void ForLetClause::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theVarName;
  bool isFor;
  
  if (ar.is_serializing_out())
  {
    isFor = (theType == FOR);
    ar & isFor;
  }
  else
  {
    ar & isFor;
    theType = (isFor ? FOR : LET);
  }

  ar & theVarRefs;
  ar & thePosVarRefs;
  ar & theInput;
  ar & theSingleItemLETVar;
  ar & theDoLazyEval;
}


/***************************************************************************//**

********************************************************************************/
void ForLetClause::accept(PlanIterVisitor& v) const
{
  // TODO correct for visitor
  switch ( theType )
  {
  case FOR:
    v.beginVisitFlworForVariable(getVarName(), theVarRefs, thePosVarRefs);
    theInput->accept(v);
    v.endVisitFlworForVariable();
    break;
  case LET:
    v.beginVisitFlworLetVariable(true, getVarName(), theVarRefs);
    theInput->accept(v);
    v.endVisitFlworLetVariable();
    break;
  default:
    ZORBA_ASSERT(false);
  }
}


/***************************************************************************//**

********************************************************************************/
zstring ForLetClause::getVarName() const
{
  return theVarName;
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  OrderByClause                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
OrderByClause::OrderByClause(
    const QueryLoc& loc,
    const std::vector<OrderSpec>& orderSpecs,
    bool stable)
  :
  theLocation(loc),
  theOrderSpecs(orderSpecs),
  theStable(stable)
{
}
  

/***************************************************************************//**

********************************************************************************/
void OrderByClause::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theLocation;
  ar & theOrderSpecs;
  ar & theStable;
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

  std::vector<OrderSpec>::const_iterator ite = theOrderSpecs.begin();
  std::vector<OrderSpec>::const_iterator end = theOrderSpecs.end();
  for (; ite != end; ++ite)
  {
    size += ite->theDomainIter->getStateSizeOfSubtree();
  }

  return size;
}


/***************************************************************************//**

********************************************************************************/
void OrderByClause::open(
    const static_context* sctx, 
    PlanState& planState, 
    uint32_t& offset)
{
  std::vector<OrderSpec>::iterator ite = theOrderSpecs.begin();
  std::vector<OrderSpec>::const_iterator end = theOrderSpecs.end();

  for (; ite != end; ++ite)
  {
    ite->open(planState, offset);

    if (ite->theCollation.size() != 0) 
    {
      ite->theCollator = sctx->get_collator(ite->theCollation, theLocation);
    }
    else
    {
      ite->theCollator = sctx->get_default_collator(theLocation);
    }
  }
}


/***************************************************************************//**

********************************************************************************/
void OrderByClause::reset(PlanState& planState)
{
  std::vector<OrderSpec>::iterator ite = theOrderSpecs.begin();
  std::vector<OrderSpec>::iterator end = theOrderSpecs.end();
  for (; ite != end; ++ite)
  {
    ite->theDomainIter->reset(planState);
  }
}


/***************************************************************************//**

********************************************************************************/
void OrderByClause::close(PlanState& planState)
{
  std::vector<OrderSpec>::iterator ite = theOrderSpecs.begin();
  std::vector<OrderSpec>::iterator end = theOrderSpecs.end();
  for (; ite != end; ++ite)
  {
    ite->theDomainIter->close(planState);
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  MaterializeClause                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
MaterializeClause::MaterializeClause(
    const QueryLoc& loc,
    std::vector<ForVarIter_t>& inputForVars,
    std::vector<LetVarIter_t>& inputLetVars,
    std::vector<std::vector<PlanIter_t> >& outputForVarsRefs,
    std::vector<std::vector<PlanIter_t> >& outputLetVarsRefs)
  :
  theLocation(loc),
  theInputForVars(inputForVars),
  theInputLetVars(inputLetVars),
  theOutputForVarsRefs(outputForVarsRefs),
  theOutputLetVarsRefs(outputLetVarsRefs),
  theStable(true)
{
}


/***************************************************************************//**

********************************************************************************/
void MaterializeClause::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theLocation;

  ar & theInputForVars;
  ar & theInputLetVars;
  ar & theOutputForVarsRefs;
  ar & theOutputLetVarsRefs;

  ar & theOrderSpecs;
  ar & theStable;
}


/***************************************************************************//**

********************************************************************************/
MaterializeClause::~MaterializeClause()
{
}


/***************************************************************************//**

********************************************************************************/
void MaterializeClause::addSort(
    const QueryLoc& loc,
    std::vector<OrderSpec>& orderSpecs,
    bool stable)
{
  theLocation = loc;
  theOrderSpecs.swap(orderSpecs);
  theStable = stable;
}


/***************************************************************************//**

********************************************************************************/
void MaterializeClause::accept(PlanIterVisitor& v) const
{ 
  v.beginVisitMaterializeClause();

  csize numVars = theInputForVars.size();

  for (csize i = 0; i < numVars; ++i)
  {
    v.beginVisitMaterializeVariable(true, theInputForVars[i], theOutputForVarsRefs[i]);
    v.endVisitMaterializeVariable();
  }

  numVars = theInputLetVars.size();

  for (csize i = 0; i < numVars; ++i)
  {
    v.beginVisitMaterializeVariable(false, theInputLetVars[i], theOutputLetVarsRefs[i]);
    v.endVisitMaterializeVariable();
  }

  std::vector<OrderSpec>::const_iterator ite = theOrderSpecs.begin();
  std::vector<OrderSpec>::const_iterator end = theOrderSpecs.end();
  for (; ite != end; ++ite)
  {
    ite->accept(v);
  }

  v.endVisitMaterializeClause();
}


/***************************************************************************//**

********************************************************************************/
uint32_t MaterializeClause::getStateSizeOfSubtree() const
{
  uint32_t size = 0;

  std::vector<ForVarIter_t>::const_iterator ite1 = theInputForVars.begin();
  std::vector<ForVarIter_t>::const_iterator end1 = theInputForVars.end();

  for (; ite1 != end1; ++ite1)
  {
    size += (*ite1)->getStateSizeOfSubtree();
  }

  std::vector<LetVarIter_t>::const_iterator ite2 = theInputLetVars.begin();
  std::vector<LetVarIter_t>::const_iterator end2 = theInputLetVars.end();

  for (; ite2 != end2; ++ite2)
  {
    size += (*ite2)->getStateSizeOfSubtree();
  }

  std::vector<OrderSpec>::const_iterator ite3 = theOrderSpecs.begin();
  std::vector<OrderSpec>::const_iterator end3 = theOrderSpecs.end();
  for (; ite3 != end3; ++ite3)
  {
    size += ite3->theDomainIter->getStateSizeOfSubtree();
  }

  return size;
}


/***************************************************************************//**

********************************************************************************/
void MaterializeClause::open(
    const static_context* sctx, 
    PlanState& planState, 
    uint32_t& offset)
{
  std::vector<ForVarIter_t>::iterator ite1 = theInputForVars.begin();
  std::vector<ForVarIter_t>::iterator end1 = theInputForVars.end();

  for (; ite1 != end1; ++ite1)
  {
    (*ite1)->open(planState, offset);
  }

  std::vector<LetVarIter_t>::iterator ite2 = theInputLetVars.begin();
  std::vector<LetVarIter_t>::iterator end2 = theInputLetVars.end();

  for (; ite2 != end2; ++ite2)
  {
    (*ite2)->open(planState, offset);
  }

  std::vector<OrderSpec>::iterator ite3 = theOrderSpecs.begin();
  std::vector<OrderSpec>::const_iterator end3 = theOrderSpecs.end();

  for (; ite3 != end3; ++ite3)
  {
    ite3->open(planState, offset);

    if (ite3->theCollation.size() != 0) 
    {
      ite3->theCollator = sctx->get_collator(ite3->theCollation, theLocation);
    }
    else
    {
      ite3->theCollator = sctx->get_default_collator(theLocation);
    }
  }
}


/***************************************************************************//**

********************************************************************************/
void MaterializeClause::close(PlanState& planState)
{
  std::vector<ForVarIter_t>::iterator ite1 = theInputForVars.begin();
  std::vector<ForVarIter_t>::iterator end1 = theInputForVars.end();

  for (; ite1 != end1; ++ite1)
  {
    (*ite1)->close(planState);
  }

  std::vector<LetVarIter_t>::iterator ite2 = theInputLetVars.begin();
  std::vector<LetVarIter_t>::iterator end2 = theInputLetVars.end();

  for (; ite2 != end2; ++ite2)
  {
    (*ite2)->close(planState);
  }

  std::vector<OrderSpec>::iterator ite3 = theOrderSpecs.begin();
  std::vector<OrderSpec>::iterator end3 = theOrderSpecs.end();
  for (; ite3 != end3; ++ite3)
  {
    ite3->theDomainIter->close(planState);
  }
}


/***************************************************************************//**

********************************************************************************/
void MaterializeClause::reset(PlanState& planState)
{
  std::vector<OrderSpec>::iterator ite = theOrderSpecs.begin();
  std::vector<OrderSpec>::iterator end = theOrderSpecs.end();
  for (; ite != end; ++ite)
  {
    ite->theDomainIter->reset(planState);
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GroupByClause                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
GroupByClause::GroupByClause(
    const QueryLoc& loc,
    std::vector<GroupingSpec> aGroupingSpecs,
    std::vector<NonGroupingSpec> aNonGroupingSpecs)
  :
  theLocation(loc),
  theGroupingSpecs(aGroupingSpecs),
  theNonGroupingSpecs(aNonGroupingSpecs)
{
}


void GroupByClause::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theLocation;
  ar & theGroupingSpecs;
  ar & theNonGroupingSpecs;
}


/***************************************************************************//**

********************************************************************************/
void GroupByClause::accept(PlanIterVisitor& v) const
{ 
  v.beginVisitGroupByClause();

  csize numSpecs = theGroupingSpecs.size();
  for (csize i = 0; i < numSpecs; ++i)
  {
    theGroupingSpecs[i].accept(v);
  }

  numSpecs = theNonGroupingSpecs.size();
  for (csize i = 0; i < numSpecs; ++i)
  {
    theNonGroupingSpecs[i].accept(v);
  }

  v.endVisitGroupByClause();
}


/***************************************************************************//**

********************************************************************************/
uint32_t GroupByClause::getStateSizeOfSubtree() const
{
  uint32_t size = 0;

  csize numSpecs = theGroupingSpecs.size();
  for (csize i = 0; i < numSpecs; ++i)
  {
    size += theGroupingSpecs[i].getStateSizeOfSubtree();
  }
  
  numSpecs = theNonGroupingSpecs.size();
  for (csize i = 0; i < numSpecs; ++i)
  {
    size += theNonGroupingSpecs[i].getStateSizeOfSubtree();
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
      groupIter->theCollator = sctx->get_collator(groupIter->theCollation, theLocation);
    }
    else
    {
      groupIter->theCollator = sctx->get_default_collator(theLocation);
    }
  }

  std::vector<NonGroupingSpec>::iterator nongroupIter = theNonGroupingSpecs.begin();
  std::vector<NonGroupingSpec>::iterator nongroupEnd = theNonGroupingSpecs.end();
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

  std::vector<NonGroupingSpec>::iterator nongroupIter = theNonGroupingSpecs.begin();
  std::vector<NonGroupingSpec>::iterator nongroupEnd = theNonGroupingSpecs.end();
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

  std::vector<NonGroupingSpec>::iterator nongroupIter = theNonGroupingSpecs.begin();
  std::vector<NonGroupingSpec>::iterator nongroupEnd = theNonGroupingSpecs.end();
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
  theGroupMap(0),
  theFirstResult(true)
{
}


/*******************************************************************************

********************************************************************************/
FlworState::~FlworState()
{
  clearSortTable();

  if (theGroupMap != NULL)
  {
    clearGroupMap();
    delete theGroupMap;
  }
}


/*******************************************************************************
  Init the state for a certain nb of variables but not the ordering
  @nb_variables  Number of FOR and LET clauses
********************************************************************************/
void FlworState::init(
    PlanState& planState,
    const std::vector<ForLetClause>& forletClauses)
{
  PlanIteratorState::init(planState);

  csize numVars = forletClauses.size();
  std::vector<long> v(numVars, 0);
  theVarBindingState.swap(v);
  assert(theVarBindingState.size() > 0);

  theTempSeqs.resize(numVars);
  theTempSeqIters.resize(numVars);

  std::vector<ForLetClause>::const_iterator iter = forletClauses.begin();
  std::vector<ForLetClause>::const_iterator end = forletClauses.end();
  std::vector<store::TempSeq_t>::iterator seqiter = theTempSeqs.begin();
  std::vector<store::Iterator_t>::iterator domiter = theTempSeqIters.begin();

  for (; iter != end; ++iter, ++seqiter, ++domiter)
  {
    const ForLetClause& flc = *iter;

    if (flc.theType == ForLetClause::LET && !flc.theSingleItemLETVar)
    {
      (*domiter) = new PlanIteratorWrapper(flc.theInput, planState);
      (*seqiter) = GENV_STORE.createTempSeq(flc.lazyEval());
    }
  }

  theNumTuples = 0;
  theCurTuplePos = 0;
  theFirstResult = true;
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
    const std::vector<ForLetClause>& forletClauses,
    std::vector<OrderSpec>* orderSpecs,
    const QueryLoc& groupbyLoc,
    std::vector<GroupingSpec>* groupingSpecs)
{
  init(planState, forletClauses);
 
  if (groupingSpecs != 0)
  {
    GroupTupleCmp cmp(groupbyLoc, planState.theLocalDynCtx, tm, groupingSpecs);
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

  csize size = theVarBindingState.size();

  ::memset(&theVarBindingState[0], 0, size * sizeof(long));

  theFirstResult = true;

  if (theOrderResultIter != NULL)
  {
    theResultTable.clear();
    theNumTuples = 0;
    theCurTuplePos = 0;

    theOrderResultIter = 0;
  }

  if (!theSortTable.empty())
    clearSortTable();

  theTuplesTable.clear();

  if (theGroupMap != NULL)
    clearGroupMap();
}


/*******************************************************************************

********************************************************************************/
void FlworState::clearSortTable()
{
  csize numTuples = theSortTable.size();

  for (csize i = 0; i < numTuples; ++i)
  {
    theSortTable[i].clear();
  }

  theSortTable.clear();
}

/*******************************************************************************

********************************************************************************/
void FlworState::clearGroupMap()
{
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
    MaterializeClause* materializeClause,
    PlanIter_t& aReturnClause)
  :
  PlanIterator(sctx, loc),
  theForLetClauses(aForLetClauses),
  theNumBindings(aForLetClauses.size()),
  theWhereClause(aWhereClause),
  theGroupByClause(aGroupByClauses),
  theOrderByClause(orderByClause),
  theMaterializeClause(materializeClause),
  theReturnClause(aReturnClause)
{
  if (theOrderByClause != 0 && theOrderByClause->theOrderSpecs.size() == 0)
  {
    delete theOrderByClause;
    theOrderByClause = NULL;
  }

  if (theOrderByClause && theMaterializeClause)
  {
    theMaterializeClause->addSort(theOrderByClause->theLocation,
                                  theOrderByClause->theOrderSpecs,
                                  theOrderByClause->theStable);
    delete theOrderByClause;
    theOrderByClause = NULL; 
  }
}


/***************************************************************************//**

********************************************************************************/
FLWORIterator::~FLWORIterator()
{
  if (theOrderByClause)
  {
    delete theOrderByClause;
  }

  if (theMaterializeClause)
  {
    delete theMaterializeClause;
  }

  if (theGroupByClause)
  { 
    delete theGroupByClause;
  }
}


/***************************************************************************//**

********************************************************************************/
void FLWORIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (PlanIterator*)this);
  ar & theForLetClauses;
  theNumBindings = theForLetClauses.size();
  ar & theWhereClause; //can be null
  ar & theGroupByClause;
  ar & theOrderByClause;  //can be null
  ar & theMaterializeClause;  //can be null
  ar & theReturnClause; 
}


/*******************************************************************************

********************************************************************************/
bool FLWORIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  ulong curVar = 0;
  store::Item_t curItem;

  FlworState* state;
  DEFAULT_STACK_INIT(FlworState, state, planState);

  assert(state->theVarBindingState.size() > 0);

  while (true)
  {
    // Here we do the variable bindings from the outer most to the inner most
    while (curVar != theNumBindings)
    {
      // Try to bind the current variable. If the binding of the variable is
      // successfull, we procede with the next binding level. Else, we go a
      // level back and try the previous level
      if (bindVariable(curVar, state, planState))
      {
        ++curVar;
      }
      else
      {
        // If there are no more bindings for the outer-most var (curVar == 0),
        // then if we had to Order or Group we need to return the results,
        // otherwise we just need to indicate that we finished by returning NULL.
        if (curVar == 0)
        {
          if (theMaterializeClause)
          {
            // GroupBy? OrderBy Materialize
            if (!theMaterializeClause->theOrderSpecs.empty())
            {
              if (theGroupByClause)
              {
                rebindGroupTuplesForMaterialize(state, planState);
              }

              {
                SortTupleCmp cmp(theMaterializeClause->theLocation,
                                 planState.theLocalDynCtx,
                                 theSctx->get_typemanager(),
                                 &theMaterializeClause->theOrderSpecs);

                if (theMaterializeClause->theStable)
                {
                  std::stable_sort(state->theSortTable.begin(),
                                   state->theSortTable.end(),
                                   cmp);
                }
                else
                {
                  std::sort(state->theSortTable.begin(),
                            state->theSortTable.end(),
                            cmp);
                }
              }

              state->theCurTuplePos = 0;
              state->theNumTuples = (ulong)state->theTuplesTable.size();

              while (state->theCurTuplePos < state->theNumTuples)
              {
                if (!state->theFirstResult)
                  theReturnClause->reset(planState);
                
                state->theFirstResult = false;

                rebindStreamTuple(state->theSortTable[state->theCurTuplePos].theDataPos,
                                  state,
                                  planState);

                while (consumeNext(result, theReturnClause, planState)) 
                {
                  STACK_PUSH(true, state);
                }
                
                ++(state->theCurTuplePos);
              }
            }

            // Materialize
            else
            {
              state->theCurTuplePos = 0;
              state->theNumTuples = (ulong)state->theTuplesTable.size();

              while (state->theCurTuplePos < state->theNumTuples)
              {
                if (!state->theFirstResult)
                  theReturnClause->reset(planState);
                
                state->theFirstResult = false;
                
                rebindStreamTuple(state->theCurTuplePos, state, planState);

                while (consumeNext(result, theReturnClause, planState)) 
                {
                  STACK_PUSH(true, state);
                }
                
                ++(state->theCurTuplePos);
              }
            }
          }

          // GroupBy? OrderBy (no Materialize)
          else if (theOrderByClause)
          {
            if (theGroupByClause)
            {
              rebindGroupTuplesForSort(state, planState);
            }

            {
              SortTupleCmp cmp(theOrderByClause->theLocation,
                               planState.theLocalDynCtx,
                               theSctx->get_typemanager(),
                               &theOrderByClause->theOrderSpecs);

              if (theOrderByClause->theStable)
              {
                std::stable_sort(state->theSortTable.begin(),
                                 state->theSortTable.end(),
                                 cmp);
              }
              else
              {
                std::sort(state->theSortTable.begin(),
                          state->theSortTable.end(),
                          cmp);
              }
            }

            state->theCurTuplePos = 0;
            state->theNumTuples = (ulong)state->theSortTable.size();

            while (state->theCurTuplePos < state->theNumTuples)
            {
              state->theOrderResultIter.transfer(state->theResultTable[state->theSortTable[state->theCurTuplePos].theDataPos]);

              state->theOrderResultIter->open();

              while (state->theOrderResultIter->next(result))
              {
                STACK_PUSH(true, state);
              }

             state->theOrderResultIter->close();

              ++(state->theCurTuplePos);
            }
          }

          // GroupBy Materialize? (no 0rderBy)
          else if (theGroupByClause)
          {
            state->theGroupMapIter = state->theGroupMap->begin();

            while (state->theGroupMapIter != state->theGroupMap->end())
            {
              if (!state->theFirstResult)
                theReturnClause->reset(planState);

              state->theFirstResult = false;

              rebindGroupTuple(state->theGroupMapIter, state, planState);

              while(consumeNext(result, theReturnClause, planState)) 
              {
                STACK_PUSH(true, state);
              }

              ++state->theGroupMapIter;
            }
          }

          goto stop;
        }
        else
        {
          // No more values for the current variable (and the current variable
          // is  not the 1st one). We go back to the previous variable to
          // compute its next value (if any). Then, we will come back to this
          // variable again, and compute all its possible values from the 
          // begining. So, we mark this var's state as "to be reset", so that
          // the domain expr of the var will be reset before we try to compute
          // its new set of values.
          state->theVarBindingState[curVar] = -1;
          --curVar;
        }
      }
    } // build next full tuple of var bindings

    // After binding all variables, we check first the where clause
    if (theWhereClause == NULL || evalToBool(theWhereClause, planState))
    {
      // If we do not need to do ordering or grouping, we compute and return
      // the items produced by the ReturnClause. Else, we have to materialize
      // the result.
      if (theGroupByClause)
      {
        materializeGroupTuple(state, planState);
      }
      else if (theMaterializeClause)
      {
        materializeStreamTuple(state, planState);
      }
      else if (theOrderByClause)
      {
        if (!state->theFirstResult)
          theReturnClause->reset(planState);

        state->theFirstResult = false;

        materializeSortTupleAndResult(state, planState);
      }
      else
      {
        if (!state->theFirstResult)
          theReturnClause->reset(planState);

        state->theFirstResult = false;

        while (consumeNext(result, theReturnClause, planState))
        {
          STACK_PUSH(true, state);
        }
      }
    }

    // curVar = theNumBindings - 1 indicates that we have to do the next binding level
    curVar = theNumBindings - 1;
  }

 stop:
  STACK_END(state);
}



/***************************************************************************//**
  Compute the next value, if any, for the given var, and bind that value to all
  the references of the variable. Return true if there was a next value, and
  false otherwise.
********************************************************************************/
bool FLWORIterator::bindVariable(
    ulong varNo,
    FlworState* iterState,
    PlanState& planState) const
{
  const ForLetClause& flc = theForLetClauses[varNo];

  long& bindingState = iterState->theVarBindingState[varNo];

  if (bindingState == -1)
  {
    theForLetClauses[varNo].theInput->reset(planState);
    bindingState = 0;
  }

  switch (flc.theType)
  {
  // In the case of a FOR var, we compute the next item of the input and bind
  // it to all the variable references.
  case ForLetClause::FOR :
  {
    store::Item_t item;
    if (!consumeNext(item, flc.theInput, planState))
    {
      return false;
    }

    // We increase the position counter
    ++bindingState;

    std::vector<PlanIter_t>::const_iterator ite = flc.theVarRefs.begin();
    std::vector<PlanIter_t>::const_iterator end = flc.theVarRefs.end();
    for (; ite != end; ++ite)
    {
      static_cast<ForVarIterator*>((*ite).getp())->bind(item.getp(), planState);
    }

    if (!flc.thePosVarRefs.empty())
    {
      store::Item_t posItem;
      GENV_ITEMFACTORY->createInteger(posItem, xs_integer(bindingState));

      std::vector<PlanIter_t>::const_iterator ite = flc.thePosVarRefs.begin();
      std::vector<PlanIter_t>::const_iterator end = flc.thePosVarRefs.end();
      for (; ite != end; ++ite)
      {
        static_cast<ForVarIterator*>((*ite).getp())->bind(posItem.getp(), planState);
      }
    }

    return true;
  }
  case ForLetClause::LET :
  {      
    // If the var is already bound, there is no next value for it, so return false.
    if (bindingState == 1)
    {
      return false;
    }

    if (!flc.theSingleItemLETVar)
    {
      store::TempSeq_t tmpSeq = iterState->theTempSeqs[varNo].getp();
      tmpSeq->init(iterState->theTempSeqIters[varNo]);

      std::vector<PlanIter_t>::const_iterator ite = flc.theVarRefs.begin();
      std::vector<PlanIter_t>::const_iterator end = flc.theVarRefs.end();
      for (; ite != end; ++ite)
      {
        static_cast<LetVarIterator*>((*ite).getp())->bind(tmpSeq, planState);
      }
    }
    else
    {
      store::Item_t item;
      if (!consumeNext(item, flc.theInput, planState))
      {
        item = NULL;
      }
      else
      {
        flc.theInput->reset(planState);
      }

      std::vector<PlanIter_t>::const_iterator ite = flc.theVarRefs.begin();
      std::vector<PlanIter_t>::const_iterator end = flc.theVarRefs.end();
      for (; ite != end; ++ite)
      {
        static_cast<LetVarIterator*>((*ite).getp())->bind(item, planState);
      }
    }

    bindingState = 1;
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
  Evaluates the predicateIter to the EBV. If the predicateIter = NULL true is
  returned.
********************************************************************************/
bool FLWORIterator::evalToBool(
    const PlanIter_t& predicateIter,
    PlanState& planState) const
{
  store::Item_t boolValue;
  if (!consumeNext(boolValue, predicateIter.getp(), planState))
  {
    predicateIter->reset(planState);
    return false;
  }

  bool value = boolValue->getBooleanValue();
  predicateIter->reset(planState);
  return value;
}


/***************************************************************************//**
  All FOR and LET vars are bound when this method is called. The method creates
  a tuple out of the values of the variables that are referenced after the
  materialize clause. It then stores this tuple in iterState->theTuplesTable
********************************************************************************/
void FLWORIterator::materializeStreamTuple(
    FlworState* iterState,
    PlanState& planState) const
{
  ZORBA_ASSERT(theMaterializeClause);

  FlworState::TuplesTable& tuplesTable = iterState->theTuplesTable;

  csize numTuples = tuplesTable.size();
  tuplesTable.resize(numTuples + 1);

  csize numForVars = theMaterializeClause->theInputForVars.size();
  csize numLetVars = theMaterializeClause->theInputLetVars.size();

  StreamTuple& streamTuple = tuplesTable[numTuples];
  streamTuple.theItems.resize(numForVars);
  streamTuple.theSequences.resize(numLetVars);

  for (csize i = 0;  i < numForVars; ++i)
  {
    store::Item_t forItem;
    consumeNext(forItem,
                theMaterializeClause->theInputForVars[i],
                planState);

    streamTuple.theItems[i].transfer(forItem);

    theMaterializeClause->theInputForVars[i]->reset(planState);
  }

  for (csize i = 0; i < numLetVars; ++i)
  {
    store::TempSeq_t letTempSeq;
    const PlanIter_t var_plan = theMaterializeClause->theInputLetVars[i];

    createTempSeq(letTempSeq, var_plan, planState, false);

    streamTuple.theSequences[i].transfer(letTempSeq);

    theMaterializeClause->theInputLetVars[i]->reset(planState);
  }

  // Create the sort tuple

  std::vector<OrderSpec>& orderSpecs = theMaterializeClause->theOrderSpecs;
  csize numSpecs = orderSpecs.size();

  if (numSpecs == 0)
    return;

  FlworState::SortTable& sortTable = iterState->theSortTable;
  sortTable.resize(numTuples + 1);

  std::vector<store::Item*>& sortTuple = sortTable[numTuples].theKeyValues;
  sortTuple.resize(numSpecs);

  for (csize i = 0; i < numSpecs; ++i)
  {
    store::Item_t sortKeyItem;
    if (consumeNext(sortKeyItem, orderSpecs[i].theDomainIter, planState))
    {
      sortTuple[i] = sortKeyItem.release();

      store::Item_t temp;
      if (consumeNext(temp, orderSpecs[i].theDomainIter, planState))
      {
        RAISE_ERROR(err::XPTY0004, theMaterializeClause->theLocation,
        ERROR_PARAMS(ZED(SingletonExpected_2o)));
      }
    }
    else
    {
      sortTuple[i] = NULL;
    }

    orderSpecs[i].theDomainIter->reset(planState);
  }

  sortTable[numTuples].theDataPos = numTuples;
}


/***************************************************************************//**
  All FOR and LET vars are bound when this method is called. The method computes
  the sort tuple ST and the return-clause sequence R for the current var 
  bindings. Then, it inserts I(R) into theReultTable, where I is an iterator over
  the temp seq storing R, and the pair (ST, P) into theSortTable, where P is the
  position of I(R) within theReultTable.
********************************************************************************/
void FLWORIterator::materializeSortTupleAndResult(
    FlworState* iterState,
    PlanState& planState) const
{
  ZORBA_ASSERT(theOrderByClause);

  FlworState::SortTable& sortTable = iterState->theSortTable;
  FlworState::ResultTable& resultTable = iterState->theResultTable;

  csize numTuples = sortTable.size();
  sortTable.resize(numTuples + 1);
  resultTable.resize(numTuples + 1);

  // Create the sort tuple

  std::vector<OrderSpec>& orderSpecs = theOrderByClause->theOrderSpecs;
  csize numSpecs = orderSpecs.size();

  std::vector<store::Item*>& sortKey = sortTable[numTuples].theKeyValues;
  sortKey.resize(numSpecs);

  for (csize i = 0; i < numSpecs; ++i)
  {
    store::Item_t sortKeyItem;
    if (consumeNext(sortKeyItem, orderSpecs[i].theDomainIter, planState))
    {
      sortKey[i] = sortKeyItem.release();

      store::Item_t temp;
      if (consumeNext(temp, orderSpecs[i].theDomainIter, planState))
      {
        RAISE_ERROR(err::XPTY0004, theOrderByClause->theLocation, 
        ERROR_PARAMS(ZED(SingletonExpected_2o)));
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
  store::TempSeq_t resultSeq = GENV_STORE.createTempSeq(iterWrapper, false);
  store::Iterator_t resultIter = resultSeq->getIterator();

  resultTable[numTuples].transfer(resultIter);
}


/***************************************************************************//**
  All FOR and LET vars are bound when this method is called. The method computes
  the group-by tuple T and then checks whether T is in the GroupMap already. If
  not, it inserts T in the GroupMap, together with one temp sequence for each of
  the non-grouping vars, storing the current value of the non-grouping var. If
  yes, it appends to each of the temp sequences associated with T the current
  value of each non-grouping var.
********************************************************************************/
void FLWORIterator::materializeGroupTuple(
    FlworState* iterState,
    PlanState& planState) const
{
  ZORBA_ASSERT(theGroupByClause);

  std::unique_ptr<GroupTuple> groupTuple(new GroupTuple());
  std::vector<store::Item_t>& groupTupleItems = groupTuple->theItems;

  std::vector<GroupingSpec> groupSpecs = theGroupByClause->theGroupingSpecs;
  std::vector<GroupingSpec>::iterator specIter = groupSpecs.begin();
  std::vector<GroupingSpec>::iterator specEnd = groupSpecs.end();

  while ( specIter != specEnd )
  {
    groupTupleItems.push_back(NULL);
    store::Item_t& tupleItem = groupTupleItems.back();
    
    consumeNext(tupleItem, specIter->theInput, planState);

    specIter->reset(planState);
    ++specIter;
  }

  GroupHashMap* groupMap = iterState->theGroupMap;

  std::vector<NonGroupingSpec> nongroupingSpecs = theGroupByClause->theNonGroupingSpecs;
  std::vector<store::TempSeq_t>* nongroupVarSequences = 0;
  csize numNonGroupingSpecs = nongroupingSpecs.size();

  if (groupMap->get(groupTuple.get(), nongroupVarSequences))
  {
    for (csize i = 0; i < numNonGroupingSpecs; ++i)
    {
      store::Iterator_t iterWrapper = 
      new PlanIteratorWrapper(nongroupingSpecs[i].theInput, planState);

      (*nongroupVarSequences)[i]->append(iterWrapper);

      nongroupingSpecs[i].reset(planState);
    }
  }
  else
  {
    nongroupVarSequences = new std::vector<store::TempSeq_t>();

    for (csize i = 0; i < numNonGroupingSpecs; ++i)
    {
      store::Iterator_t iterWrapper = 
      new PlanIteratorWrapper(nongroupingSpecs[i].theInput, planState);

      store::TempSeq_t result = GENV_STORE.createTempSeq(iterWrapper, false);

      nongroupVarSequences->push_back(result);

      nongroupingSpecs[i].reset(planState);
    }

    groupMap->insert(groupTuple.get(), nongroupVarSequences);
    groupTuple.release();
  }
}


/***************************************************************************//**
  Binds the values in current tuple of the group map to the var references
  that appear after the groupby clause. 
********************************************************************************/
void FLWORIterator::rebindStreamTuple( 
    ulong tuplePos,
    FlworState* iterState,
    PlanState& planState) const
{
  StreamTuple& streamTuple = 
  iterState->theTuplesTable[tuplePos];

  csize numForVarsRefs = theMaterializeClause->theOutputForVarsRefs.size();

  for (csize i = 0; i < numForVarsRefs; ++i)
  {
    bindVariables(streamTuple.theItems[i],
                  theMaterializeClause->theOutputForVarsRefs[i],
                  planState);
  }
  
  csize numLetVarsRefs = theMaterializeClause->theOutputLetVarsRefs.size();
  
  for (csize i = 0; i < numLetVarsRefs; ++i)
  {
    bindVariables(streamTuple.theSequences[i],
                  theMaterializeClause->theOutputLetVarsRefs[i],
                  planState);
  }
}


/*******************************************************************************

********************************************************************************/
void FLWORIterator::rebindGroupTuplesForSort(
    FlworState* iterState,
    PlanState& planState) const
{
  GroupHashMap* groupMap = iterState->theGroupMap;

  GroupHashMap::iterator groupMapIter = groupMap->begin();
  GroupHashMap::iterator groupMapEnd = groupMap->end();

  while (groupMapIter != groupMapEnd)
  {
    rebindGroupTuple(groupMapIter, iterState, planState);
  
    materializeSortTupleAndResult(iterState, planState);

    theReturnClause->reset(planState);

    ++groupMapIter;
  }
}


/*******************************************************************************

********************************************************************************/
void FLWORIterator::rebindGroupTuplesForMaterialize(
    FlworState* iterState,
    PlanState& planState) const
{
  GroupHashMap* groupMap = iterState->theGroupMap;

  GroupHashMap::iterator groupMapIter = groupMap->begin();
  GroupHashMap::iterator groupMapEnd = groupMap->end();

  while (groupMapIter != groupMapEnd)
  {
    rebindGroupTuple(groupMapIter, iterState, planState);
  
    materializeStreamTuple(iterState, planState);

    ++groupMapIter;
  }
}


/***************************************************************************//**
  Binds the values in current tuple of the group map to the var references
  that appear after the groupby clause. 
********************************************************************************/
void FLWORIterator::rebindGroupTuple( 
    GroupHashMap::iterator groupMapIter,
    FlworState* iterState,
    PlanState& planState) const
{
  // Bind grouping vars
  GroupTuple* groupTuple = (*groupMapIter).first;
  std::vector<store::Item_t>::iterator groupKeyIter = groupTuple->theItems.begin();

  std::vector<GroupingSpec>& groupSpecs = theGroupByClause->theGroupingSpecs;
  std::vector<GroupingSpec>::const_iterator specIter = groupSpecs.begin();
  std::vector<GroupingSpec>::const_iterator specEnd = groupSpecs.end();

  while (specIter != specEnd)
  {
    std::vector<ForVarIter_t>::const_iterator groupVarIter = specIter->theVarRefs.begin();
    std::vector<ForVarIter_t>::const_iterator groupVarEnd = specIter->theVarRefs.end();

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
  std::vector<NonGroupingSpec> lNonGroupingSpecs = theGroupByClause->theNonGroupingSpecs;
  std::vector<NonGroupingSpec>::const_iterator lNonGroupingSpecsIter = lNonGroupingSpecs.begin();

  while (lNonGroupingSpecsIter != lNonGroupingSpecs.end())
  {
    std::vector<LetVarIter_t>::const_iterator lOuterVarBindingIter =
    lNonGroupingSpecsIter->theVarRefs.begin();

    while (lOuterVarBindingIter != lNonGroupingSpecsIter->theVarRefs.end())
    {
      store::TempSeq_t lTmpSeq = *lOuterSeqIter;
      ( *lOuterVarBindingIter )->bind(lTmpSeq , planState);
      ++lOuterVarBindingIter;
    }
    ++lNonGroupingSpecsIter;
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

  std::vector<ForLetClause>::const_iterator iter = theForLetClauses.begin();
  std::vector<ForLetClause>::const_iterator end = theForLetClauses.end();
  for (; iter != end; ++iter)
  {
    iter->theInput->open(planState, offset);
  }

  theReturnClause->open(planState, offset);

  if (theWhereClause != NULL)
    theWhereClause->open(planState, offset);
  
  if (theGroupByClause)
    theGroupByClause->open(theSctx, planState, offset);
  
  if (theOrderByClause)
    theOrderByClause->open(theSctx, planState, offset);

  if (theMaterializeClause)
    theMaterializeClause->open(theSctx, planState, offset);

  if (theGroupByClause || theOrderByClause)
  {
    if (theGroupByClause)
    {
      iterState->init(planState,
                      theSctx->get_typemanager(),
                      theForLetClauses,
                      (theOrderByClause ? &theOrderByClause->theOrderSpecs : NULL),
                      theGroupByClause->theLocation,
                      &theGroupByClause->theGroupingSpecs); 
    }
    else if (theOrderByClause) 
    {
      iterState->init(planState,
                      theSctx->get_typemanager(),
                      theForLetClauses,
                      &theOrderByClause->theOrderSpecs,
                      QueryLoc::null,
                      0);
    }
  }
  else 
  {
    iterState->init(planState, theForLetClauses);
  }

  // some variables must have been bound
  assert(iterState->theVarBindingState.size() > 0);
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

  if (theMaterializeClause != NULL)
    theMaterializeClause->reset(planState);
  
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

  if (theMaterializeClause)
    theMaterializeClause->close(planState);

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
zstring FLWORIterator::getNameAsString() const {
  return "FLWORIterator";
}


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

  if (theWhereClause != NULL)
    size += theWhereClause->getStateSizeOfSubtree();

  if (theOrderByClause)
    size += theOrderByClause->getStateSizeOfSubtree();

  if (theMaterializeClause)
    size += theMaterializeClause->getStateSizeOfSubtree();

  if (theGroupByClause)
    size += theGroupByClause->getStateSizeOfSubtree();

  return size;
}


/*******************************************************************************

********************************************************************************/
void FLWORIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<ForLetClause>::const_iterator iter = theForLetClauses.begin();
  std::vector<ForLetClause>::const_iterator end = theForLetClauses.end();
  for (; iter != end; ++iter)
  {
    iter->accept(v);
  }

  if (theWhereClause != NULL)
    theWhereClause->accept(v);

  if (theGroupByClause)
    theGroupByClause->accept(v);
 
  if (theOrderByClause)
    theOrderByClause->accept(v);

  if (theMaterializeClause)
    theMaterializeClause->accept(v);

  theReturnClause->accept(v);

  v.endVisit(*this);
}

} // namespace flwor
} // namespace zorba
/* vim:set et sw=2 ts=2: */
