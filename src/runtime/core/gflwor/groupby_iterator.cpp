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

#include "runtime/api/runtimecb.h"
#include "runtime/visitors/planitervisitor.h"
#include "runtime/core/gflwor/groupby_iterator.h"
#include "runtime/core/gflwor/common.h"

#include "system/globalenv.h"
#include "context/collation_cache.h"

using namespace zorba;

namespace zorba 
{

namespace flwor 
{

SERIALIZABLE_CLASS_VERSIONS(GroupByIterator)
END_SERIALIZABLE_CLASS_VERSIONS(GroupByIterator)

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GroupByState                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


GroupByState::GroupByState() 
  :
  theGroupMap ( 0 )
{
}


GroupByState::~GroupByState() 
{
  GroupHashMap::iterator iter = theGroupMap->begin();
  GroupHashMap::iterator end = theGroupMap->end();
  for (; iter != end; ++iter )
  {
    delete ( *iter ).first;
    delete ( *iter ).second;
  }

  delete theGroupMap;
  theGroupMap = 0;
}
  

void GroupByState::init (
    PlanState& aState,
    const TypeManager* tm,
    std::vector<GroupingSpec>* groupingSpecs) 
{
  PlanIteratorState::init(aState);

  GroupTupleCmp cmp(aState.theRuntimeCB, tm, groupingSpecs);
  theGroupMap = new GroupHashMap(cmp, 1024, false);
}


void GroupByState::reset ( PlanState& aPlanState ) 
{
  PlanIteratorState::reset ( aPlanState );

  GroupHashMap::iterator iter = theGroupMap->begin();
  GroupHashMap::iterator end = theGroupMap->end();
  for (; iter != end; ++iter )
  {
    delete ( *iter ).first;
    delete ( *iter ).second;
  }

  theGroupMap->clear();
}
  

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GroupByIterator                                                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
GroupByIterator::GroupByIterator (
    short sctx,
    const QueryLoc& aLoc,
    PlanIter_t aTupleIterator,
    std::vector<GroupingSpec> aGroupingSpecs,
    std::vector<GroupingOuterVar> aOuterVars ) 
  :
  Batcher<GroupByIterator> ( sctx, aLoc ),
  theTupleIter(aTupleIterator),
  theGroupingSpecs ( aGroupingSpecs ),
  theOuterVars ( aOuterVars ) 
{
}
  

/***************************************************************************//**

********************************************************************************/
GroupByIterator::~GroupByIterator() 
{
}


/***************************************************************************//**

********************************************************************************/
bool GroupByIterator::nextImpl ( store::Item_t& aResult, PlanState& aPlanState ) const 
{
  GroupByState* lState;
  DEFAULT_STACK_INIT ( GroupByState, lState, aPlanState );

  while ( consumeNext ( aResult, theTupleIter, aPlanState ) ) 
  {
    try {
    matVarsAndGroupBy ( lState, aPlanState );
    }
    catch (error::ZorbaError& lError)
    {
      ZORBA_ERROR_LOC_DESC(lError.theErrorCode, loc, lError.theDescription);
    }
  }

  if ( !lState->theGroupMap->empty() ) 
  {
    lState->theGroupMapIter = lState->theGroupMap->begin();
    while(lState->theGroupMapIter != lState->theGroupMap->end())
    {
      bindGroupBy(lState->theGroupMapIter, lState, aPlanState);
      ++lState->theGroupMapIter;
      STACK_PUSH ( true, lState );
    }
  }
  STACK_PUSH ( false, lState );
  STACK_END ( lState );
}
  

/***************************************************************************//**

********************************************************************************/
void GroupByIterator::matVarsAndGroupBy (
    GroupByState* aGroupByState,
    PlanState& aPlanState ) const 
{
  GroupTuple* lGroupTuple = new GroupTuple();
  std::vector<store::Item_t> lKey;
  std::vector<store::Item_t> lTypedKey;
  std::vector<GroupingSpec>::const_iterator lSpecIter = theGroupingSpecs.begin();
  while ( lSpecIter != theGroupingSpecs.end() ) {
    lKey.push_back ( NULL );
    store::Item_t& location = lKey.back();
    bool status = consumeNext ( location, lSpecIter->theInput.getp(), aPlanState );
    //Getting the typed value
    if ( !status ) {
      lTypedKey.push_back ( NULL );
    } else {
      store::Item_t temp;
      store::Iterator_t lTypedValueIter;
      store::Item_t lTypedValue;
      location->getTypedValue ( lTypedValue, lTypedValueIter );
      if ( lTypedValueIter == NULL ) {
        lTypedKey.push_back ( NULL );
        lTypedKey.back().transfer ( lTypedValue );
      } else {
        lTypedValueIter->open();
        lTypedKey.push_back ( NULL );
        store::Item_t& typedItem = lTypedKey.back();
        if ( lTypedValueIter->next ( typedItem ) ) {
          if ( lTypedValueIter->next ( temp ) ) {
            ZORBA_ERROR_DESC ( XPTY0004, "Expected a singleton (atomization has more than one value)" );
          }
        }
      }
    }

    //check for more values
    if ( status ) {
      store::Item_t temp;
      if ( consumeNext ( temp, lSpecIter->theInput.getp(), aPlanState ) ) {
        ZORBA_ERROR_DESC ( XPTY0004, "Expected a singleton" );
      }
    }
    lSpecIter->theInput->reset ( aPlanState );
    ++lSpecIter;
  }
  lGroupTuple->theItems = lKey;
  lGroupTuple->theTypedValues = lTypedKey;
  
  GroupHashMap* lGroupMap = aGroupByState->theGroupMap;
  std::vector<store::TempSeq_t>* lOuterSeq = 0;
  std::vector<GroupingOuterVar>::const_iterator lOuterVarIter = theOuterVars.begin();
  if ( lGroupMap->get ( lGroupTuple, lOuterSeq ) ) {
    assert ( lOuterSeq > 0 );
    std::vector<store::TempSeq_t>::iterator lOuterSeqIter = lOuterSeq->begin();
    while ( lOuterVarIter != theOuterVars.end() ) {
      store::Iterator_t iterWrapper = new PlanIteratorWrapper ( lOuterVarIter->theInput, aPlanState );
      ( *lOuterSeqIter )->append ( iterWrapper, false );//FIXME are those settings right? I think copy is correct 
      lOuterVarIter->theInput->reset ( aPlanState );
      ++lOuterSeqIter;
      ++lOuterVarIter;
    }
    delete lGroupTuple;
  } else {
    lOuterSeq = new std::vector<store::TempSeq_t>();
    while ( lOuterVarIter != theOuterVars.end() ) {
      store::Iterator_t iterWrapper = new PlanIteratorWrapper ( lOuterVarIter->theInput, aPlanState );
      store::TempSeq_t result = GENV_STORE.createTempSeq ( iterWrapper, false, false ); //FIXME are those settings right? 
      lOuterSeq->push_back ( result );
      lOuterVarIter->theInput->reset ( aPlanState );
      ++lOuterVarIter;
    }
    lGroupMap->insert ( lGroupTuple, lOuterSeq );
  }
}


/***************************************************************************//**

********************************************************************************/
void GroupByIterator::bindGroupBy (
    GroupHashMap::iterator aGroupMapIter,
    GroupByState* aGroupByState,
    PlanState& aPlanState ) const 
{
      //Bind grouping vars
      GroupTuple* lGroupTuple = ( *aGroupMapIter ).first;
      std::vector<store::Item_t>::iterator lGroupTupleIter = lGroupTuple->theItems.begin();
      std::vector<GroupingSpec>::const_iterator lSpecIter = theGroupingSpecs.begin();
      while ( lSpecIter != theGroupingSpecs.end() ) {
        std::vector<ForVarIter_t>::const_iterator lGroupVarIter = lSpecIter->theInnerVars.begin();
        while ( lGroupVarIter != lSpecIter->theInnerVars.end() ) {
          ( *lGroupVarIter )->bind ( *lGroupTupleIter, aPlanState );
          ++lGroupVarIter;
        }
        ++lSpecIter;
        ++lGroupTupleIter;
      }

      //Bind non-grouping vars
      std::vector<store::TempSeq_t>* lVector = ( *aGroupMapIter ).second;
      std::vector<store::TempSeq_t>::const_iterator lOuterSeqIter = lVector->begin();
      std::vector<GroupingOuterVar>::const_iterator lOuterVarsIter = theOuterVars.begin();
      while ( lOuterVarsIter != theOuterVars.end() ) {
        std::vector<LetVarIter_t>::const_iterator lOuterVarBindingIter = lOuterVarsIter->theOuterVars.begin();
        while ( lOuterVarBindingIter != lOuterVarsIter->theOuterVars.end() ) {
          store::TempSeq_t lTmpSeq = *lOuterSeqIter;
          store::Iterator_t lBindIterator = lTmpSeq->getIterator();
          lBindIterator->open();
          ( *lOuterVarBindingIter )->bind ( lBindIterator , aPlanState );
          ++lOuterVarBindingIter;
        }
        ++lOuterVarsIter;
        ++lOuterSeqIter;
      }
}


/***************************************************************************//**

********************************************************************************/
void GroupByIterator::openImpl ( PlanState& planState, uint32_t& aOffset ) 
{
  StateTraitsImpl <GroupByState>::createState(planState, this->stateOffset, aOffset);

  GroupByState* state = StateTraitsImpl<GroupByState>::getState(planState,
                                                                this->stateOffset);
      
  static_context* sctx = getStaticContext(planState);

  state->init(planState, sctx->get_typemanager(), &theGroupingSpecs); 
      
  theTupleIter->open(planState, aOffset);

  std::vector<GroupingSpec>::iterator iter = theGroupingSpecs.begin();
  std::vector<GroupingSpec>::iterator end = theGroupingSpecs.end();
  for (; iter != end; ++iter)
  {
    iter->open(planState, aOffset);

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

  std::vector<GroupingOuterVar>::iterator iterOuterVars = theOuterVars.begin();
  std::vector<GroupingOuterVar>::iterator outerEnd = theOuterVars.end();
  for (; iterOuterVars != outerEnd; ++iterOuterVars)
  {
    iterOuterVars->open ( planState, aOffset );
  }
}


/***************************************************************************//**

********************************************************************************/
void GroupByIterator::resetImpl ( PlanState& planState ) const 
{
  std::vector<GroupingSpec>::const_iterator iter = theGroupingSpecs.begin();
  std::vector<GroupingSpec>::const_iterator end = theGroupingSpecs.end();
  for (; iter != end; ++iter)
  {
    iter->reset(planState);
  }

  std::vector<GroupingOuterVar>::const_iterator lOuterVarIter = theOuterVars.begin();
  std::vector<GroupingOuterVar>::const_iterator outerEnd = theOuterVars.end();
  for (; lOuterVarIter != outerEnd; ++lOuterVarIter)
  {
    lOuterVarIter->reset(planState);
  }

  theTupleIter->reset ( planState );
  
  StateTraitsImpl<GroupByState>::reset ( planState, this->stateOffset );
}


/***************************************************************************//**

********************************************************************************/
void GroupByIterator::closeImpl ( PlanState& planState ) 
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

  theTupleIter->close ( planState );
  
  StateTraitsImpl<GroupByState>::destroyState ( planState, this->stateOffset );
}


/***************************************************************************//**

********************************************************************************/
void GroupByIterator::accept(PlanIterVisitor& v) const 
{
  v.beginVisit(*this);
      
  theTupleIter->accept(v);
      
  std::vector<GroupingSpec>::const_iterator iter;
  for (iter = theGroupingSpecs.begin(); iter != theGroupingSpecs.end(); ++iter) 
  {
    iter->accept(v);
  }

  std::vector<GroupingOuterVar>::const_iterator iterOuterVars;
  for (iterOuterVars = theOuterVars.begin(); iterOuterVars != theOuterVars.end(); ++iterOuterVars) 
  {
    iterOuterVars->accept(v);
  }

  v.endVisit(*this);
}
  

/***************************************************************************//**

********************************************************************************/
uint32_t GroupByIterator::getStateSize() const  
{
  return StateTraitsImpl<GroupByState>::getStateSize();
}


/***************************************************************************//**

********************************************************************************/
uint32_t GroupByIterator::getStateSizeOfSubtree() const 
{
  int32_t size = this->getStateSize();
  size  += theTupleIter->getStateSizeOfSubtree();

  std::vector<GroupingSpec>::const_iterator iter;
  for (iter = theGroupingSpecs.begin(); iter != theGroupingSpecs.end(); iter++) 
  {
    size += iter->getStateSizeOfSubtree();
  }

  std::vector<GroupingOuterVar>::const_iterator iterOuterVars;
  for (iterOuterVars = theOuterVars.begin();
       iterOuterVars != theOuterVars.end();
       iterOuterVars++) 
  {
    size += iterOuterVars->getStateSizeOfSubtree();
  }
  return size;
}


} //Namespace flwor
}//Namespace zorba
