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
#include "diagnostics/util_macros.h"
#include "diagnostics/xquery_diagnostics.h"
#include "zorbautils/checked_vector.h"

#include "system/globalenv.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/visitors/planiter_visitor.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/core/gflwor/orderby_iterator.h"
#include "runtime/core/gflwor/common.h"
#include "runtime/core/gflwor/comp_function.h"

#include <vector>
#include <algorithm>

using namespace zorba;

namespace zorba 
{

namespace flwor 
{

SERIALIZABLE_CLASS_VERSIONS(OrderByIterator)

SERIALIZABLE_CLASS_VERSIONS(OrderSpec)


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  OrderSpec                                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


OrderSpec::OrderSpec (
    PlanIter_t domainIter,
    bool emptyLeast,
    bool descending,
    bool nativeCompare,
    const std::string& collation)
  :
  theDomainIter(domainIter),
  theEmptyLeast(emptyLeast),
  theDescending(descending),
  theNativeCompare(nativeCompare),
  theCollation(collation),
  theCollator(0)
{
}


void OrderSpec::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theDomainIter;
  ar & theEmptyLeast;
  ar & theDescending;
  ar & theNativeCompare;
  ar & theCollation;
  ar & theCollator;
}


void OrderSpec::accept(PlanIterVisitor& v) const
{
  theDomainIter->accept(v);
}


uint32_t OrderSpec::getStateSizeOfSubtree() const 
{
  return theDomainIter->getStateSizeOfSubtree();
}


void OrderSpec::open(PlanState& aPlanState, uint32_t& offset) const 
{
  theDomainIter->open(aPlanState, offset);
}


void OrderSpec::reset(PlanState& aPlanState) const 
{
  theDomainIter->reset(aPlanState);
}


void OrderSpec::close(PlanState& aPlanState) const 
{
  theDomainIter->close(aPlanState);
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  OrderByState                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


OrderByState::OrderByState() 
  :
  theNumTuples(0),
  theCurTuplePos(0)
{
}


OrderByState::~OrderByState() 
{
  clearSortTable();
}


void OrderByState::init(PlanState& planState, std::vector<OrderSpec>* orderSpecs) 
{
  PlanIteratorState::init(planState);

  theNumTuples = 0;
  theCurTuplePos = 0;
}


void OrderByState::reset(PlanState& planState) 
{
  PlanIteratorState::reset(planState);

  clearSortTable();
  theDataTable.clear();
  theNumTuples = 0;
  theCurTuplePos = 0;
}


void OrderByState::clearSortTable()
{
  ulong numTuples = (ulong)theSortTable.size();

  for (ulong i = 0; i < numTuples; ++i)
  {
    theSortTable[i].clear();
  }

  theSortTable.clear();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  OrderByIterator                                                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


OrderByIterator::OrderByIterator (
    static_context* sctx,
    const QueryLoc& aLoc,
    bool stable,
    std::vector<OrderSpec>& orderSpecs,
    PlanIter_t tupleIterator,
    std::vector<ForVarIter_t>& inputForVars,
    std::vector<LetVarIter_t>& inputLetVars,
    std::vector<std::vector<PlanIter_t> >& outputForVarsRefs,
    std::vector<std::vector<PlanIter_t> >& outputLetVarsRefs) 
  :
  PlanIterator(sctx, aLoc),
  theStable(stable),
  theOrderSpecs(orderSpecs),
  theTupleIter(tupleIterator),
  theInputForVars(inputForVars),
  theInputLetVars(inputLetVars),
  theOutputForVarsRefs(outputForVarsRefs),
  theOutputLetVarsRefs(outputLetVarsRefs) 
{  
}
  
  
OrderByIterator::~OrderByIterator() 
{
}


void OrderByIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (PlanIterator*)this);
  ar & theStable;
  ar & theOrderSpecs;
  ar & theTupleIter;

  ar & theInputForVars;
  ar & theInputLetVars;
  ar & theOutputForVarsRefs;
  ar & theOutputLetVarsRefs;
}


zstring OrderByIterator::getNameAsString() const {
  return "OrderByIterator";
}


uint32_t OrderByIterator::getStateSize() const 
{
  return sizeof(OrderByState);
}
  
  
uint32_t OrderByIterator::getStateSizeOfSubtree() const 
{
  int32_t lSize = this->getStateSize();
  lSize += theTupleIter->getStateSizeOfSubtree();
  lSize += getStateSizeOfSubtreeVector<OrderSpec> ( theOrderSpecs );
  lSize += getStateSizeOfSubtreeVectorPtr<ForVarIter_t> ( theInputForVars );
  lSize += getStateSizeOfSubtreeVectorPtr<LetVarIter_t> ( theInputLetVars );
  return lSize;
}
  
  
void OrderByIterator::accept(PlanIterVisitor& v) const 
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  ulong numVars = (ulong)theInputForVars.size();
  for (ulong i = 0; i < numVars; ++i)
  {
    v.beginVisitOrderByForVariable(theInputForVars[i], theOutputForVarsRefs[i]);
    v.endVisitOrderByForVariable();
  }

  numVars = (ulong)theInputLetVars.size();
  for (ulong i = 0; i < numVars; ++i)
  {
    v.beginVisitOrderByLetVariable(theInputLetVars[i], theOutputLetVarsRefs[i]);
    v.endVisitOrderByLetVariable();
  }

  callAcceptVector(theOrderSpecs, v);

  theTupleIter->accept(v);

  v.endVisit(*this);
}


void OrderByIterator::openImpl(PlanState& planState, uint32_t& aOffset) 
{
  StateTraitsImpl<OrderByState>::createState(planState, theStateOffset, aOffset);

  OrderByState* iterState = StateTraitsImpl<OrderByState>::getState(planState,
                                                                    theStateOffset);

  // Do a manual pass to set the Collator
  ulong numSpecs = (ulong)theOrderSpecs.size();
  for (ulong i = 0; i < numSpecs; ++i)
  {
    theOrderSpecs[i].open(planState, aOffset);

    if (! theOrderSpecs[i].theCollation.empty())
    {
      theOrderSpecs[i].theCollator = 
      theSctx->get_collator(theOrderSpecs[i].theCollation, loc);
    }
  }
  
  iterState->init(planState, &theOrderSpecs);
  
  theTupleIter->open(planState, aOffset);

  openVectorPtr<ForVarIter_t>(theInputForVars, planState, aOffset);
  openVectorPtr<LetVarIter_t>(theInputLetVars, planState, aOffset);
}

  
void OrderByIterator::resetImpl(PlanState& planState) const 
{
  OrderByState* iterState = StateTraitsImpl<OrderByState>::getState(planState,
                                                                    theStateOffset);
  iterState->reset(planState);
  
  theTupleIter->reset(planState);
  resetVector<OrderSpec>(theOrderSpecs, planState);
  resetVectorPtr<ForVarIter_t >(theInputForVars, planState);
  resetVectorPtr<LetVarIter_t >(theInputLetVars, planState);
}


void OrderByIterator::closeImpl(PlanState& planState) 
{
  theTupleIter->close(planState);
  closeVector<OrderSpec>(theOrderSpecs, planState);
  closeVectorPtr<ForVarIter_t>(theInputForVars, planState);
  closeVectorPtr<LetVarIter_t>(theInputLetVars, planState);

  StateTraitsImpl<OrderByState>::destroyState(planState, theStateOffset);
}
  
  

bool OrderByIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  OrderByState* iterState;
  DEFAULT_STACK_INIT(OrderByState, iterState, planState);

  while (consumeNext(result, theTupleIter, planState)) 
  {
    materializeResultForSort(iterState, planState);
  }

  {
    SortTupleCmp cmp(loc,
                     planState.theLocalDynCtx,
                     theSctx->get_typemanager(),
                     &theOrderSpecs);

    if (theStable)
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
  }

  iterState->theCurTuplePos = 0;
  iterState->theNumTuples = (ulong)iterState->theSortTable.size();

  while(iterState->theCurTuplePos < iterState->theNumTuples)
  {
    bindOrderBy(iterState, planState);

    STACK_PUSH(true, iterState);

    ++(iterState->theCurTuplePos);
  }

  STACK_PUSH(false, iterState);
  STACK_END(iterState);
}


/***************************************************************************//**
  All FOR and LET vars are bound when this method is called. The method computes
  the order-by tuple T and the return-clause sequence R for the current var
  bindings. Then, it inserts the pair (T, I(R)) into theOrderMap (where I is
  an iterator over the temp seq storing R).
********************************************************************************/
void OrderByIterator::materializeResultForSort( 
    OrderByState* iterState,
    PlanState& planState) const 
{
  OrderByState::SortTable& sortTable = iterState->theSortTable;
  OrderByState::DataTable& dataTable = iterState->theDataTable;

  csize numTuples = sortTable.size();
  sortTable.resize(numTuples + 1);
  dataTable.resize(numTuples + 1);

  // Create the sort tuple

  csize numSpecs = theOrderSpecs.size();

  std::vector<store::Item*>& sortKey = sortTable[numTuples].theKeyValues;
  sortKey.resize(numSpecs);

  for (csize i = 0; i < numSpecs; ++i)
  {
    store::Item_t sortKeyItem;
    if (consumeNext(sortKeyItem, theOrderSpecs[i].theDomainIter, planState)) 
    {
      sortKey[i] = sortKeyItem.release();

      store::Item_t temp;
      if (consumeNext(temp, theOrderSpecs[i].theDomainIter, planState)) 
      {
        RAISE_ERROR(err::XPTY0004, loc,
        ERROR_PARAMS(ZED(SingletonExpected_2o)));
      }
    }
    else
    {
      sortKey[i] = NULL;
    }

    theOrderSpecs[i].theDomainIter->reset(planState);
  }
  
  sortTable[numTuples].theDataPos = numTuples;

  // create the data tuple

  csize numForVars = theInputForVars.size();
  csize numLetVars = theInputLetVars.size();

  StreamTuple& streamTuple = dataTable[numTuples];
  streamTuple.theItems.resize(numForVars);
  streamTuple.theSequences.resize(numLetVars);

  for (csize i = 0;  i < numForVars; ++i)
  {
    store::Item_t forItem;
    consumeNext(forItem, theInputForVars[i], planState);

    streamTuple.theItems[i].transfer(forItem);

    theInputForVars[i]->reset(planState);
  }

  for (csize i = 0; i < numLetVars; ++i)
  {
    store::TempSeq_t letTempSeq;
    createTempSeq(letTempSeq, theInputLetVars[i], planState, false);

    streamTuple.theSequences[i].transfer(letTempSeq);

    theInputLetVars[i]->reset(planState);
  }
}
  

void OrderByIterator::bindOrderBy( 
    OrderByState* iterState,
    PlanState& planState) const 
{
  StreamTuple& streamTuple = 
  iterState->theDataTable[iterState->theSortTable[iterState->theCurTuplePos].theDataPos];

  csize numForVarsRefs = theOutputForVarsRefs.size();
  for (csize i = 0; i < numForVarsRefs; ++i)
  {
    bindVariables(streamTuple.theItems[i], theOutputForVarsRefs[i], planState);
  }

  csize numLetVarsRefs = theOutputLetVarsRefs.size();
  for(csize i = 0; i < numLetVarsRefs; ++i)
  {
    bindVariables(streamTuple.theSequences[i], theOutputLetVarsRefs[i], planState);
  }
}
  
  
} //Namespace flwor
} //Namespace zorba
/* vim:set et sw=2 ts=2: */
