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
#include "runtime/core/gflwor/groupby_iterator.h"
#include "runtime/core/gflwor/common.h"

#include "zorbautils/fatal.h"
#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_manager.h"

#include "runtime/api/runtimecb.h"

#include "system/globalenv.h"
#include "context/collation_cache.h"

using namespace zorba;

namespace zorba {
  namespace gflwor {


    /////////////////////////////////////////////////////////////////////////////////
    //                                                                             //
    //  GroupingOuterVar                                                           //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////

    GroupingOuterVar::GroupingOuterVar (
      PlanIter_t aInput,
      std::vector<LetVarIter_t> aOuterVars )
        : theInput ( aInput ), theOuterVars ( aOuterVars ) {}

    void GroupingOuterVar::accept ( PlanIterVisitor& v ) const {
      theInput->accept ( v );
    }

    void GroupingOuterVar::open ( PlanState& planState, uint32_t& offset ) const {
      theInput->open ( planState, offset );
    }

    void GroupingOuterVar::close ( PlanState& planState ) const {
      theInput->close ( planState );
    }

    void GroupingOuterVar::reset ( PlanState& planState ) const {
      theInput->reset ( planState );
    }

    uint32_t GroupingOuterVar::getStateSizeOfSubtree() const {
      return theInput->getStateSizeOfSubtree();
    }

    /////////////////////////////////////////////////////////////////////////////////
    //                                                                             //
    //  GroupingOuterVar                                                           //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////

    GroupingSpec::GroupingSpec (
      PlanIter_t aInput, std::vector<ForVarIter_t> aInnerVars, xqpString aCollation )
        : theInput ( aInput ), theInnerVars ( aInnerVars ), theCollation ( aCollation ) {}

    void GroupingSpec::accept ( PlanIterVisitor& v ) const {
      theInput->accept ( v );
    }

    void GroupingSpec::open ( PlanState& planState, uint32_t& offset ) const {
      theInput->open ( planState, offset );
    }

    void GroupingSpec::close ( PlanState& planState ) const {
      theInput->close ( planState );
    }

    void GroupingSpec::reset ( PlanState& planState ) const {
      theInput->reset ( planState );
    }

    uint32_t GroupingSpec::getStateSizeOfSubtree() const {
      return theInput->getStateSizeOfSubtree();
    }

    /////////////////////////////////////////////////////////////////////////////////
    //                                                                             //
    //  GroupByState                                                               //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////


    GroupByState::GroupByState() : theGroupMap ( 0 ), theValueCompareParam(0) {
    }


    GroupByState::~GroupByState() {
      group_map_t::iterator lGroupIter;
      for ( lGroupIter = theGroupMap->begin();
            lGroupIter != theGroupMap->end();
            ++lGroupIter ) {
        delete ( *lGroupIter ).first;
        delete ( *lGroupIter ).second;
      }
      delete theGroupMap;
      theGroupMap = 0;
    }


    void GroupByState::init ( PlanState& aState, std::vector<XQPCollator*> * aGroupingCollators ) {
      PlanIteratorState::init ( aState );
      theValueCompareParam = new GroupCompareParam ( aState.theRuntimeCB, *aGroupingCollators );
      theGroupMap = new group_map_t ( theValueCompareParam );
    }

    void GroupByState::reset ( PlanState& aPlanState ) {
      PlanIteratorState::reset ( aPlanState );
      group_map_t::iterator lGroupIter;
      for ( lGroupIter = theGroupMap->begin();
            lGroupIter != theGroupMap->end();
            ++lGroupIter ) {
        delete ( *lGroupIter ).first;
        delete ( *lGroupIter ).second;
      }
      theGroupMap->clear();
    }

    /////////////////////////////////////////////////////////////////////////////////
    //                                                                             //
    //  GroupByIterator                                                            //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////

    GroupByIterator::GroupByIterator ( const QueryLoc& aLoc,
                                       PlanIter_t aTupleIterator,
                                       std::vector<GroupingSpec> aGroupingSpecs,
                                       std::vector<GroupingOuterVar> aOuterVars ) :
        Batcher<GroupByIterator> ( aLoc ),
        theTupleIter(aTupleIterator),
        theGroupingSpecs ( aGroupingSpecs ),
        theOuterVars ( aOuterVars ) {
    }

    GroupByIterator::~GroupByIterator() {}

    bool GroupByIterator::nextImpl ( store::Item_t& aResult, PlanState& aPlanState ) const {
      GroupByState* lState;
      DEFAULT_STACK_INIT ( GroupByState, lState, aPlanState );
      while ( consumeNext ( aResult, theTupleIter, aPlanState ) ) {
        matVarsAndGroupBy ( lState, aPlanState );
      }
      if ( !lState->theGroupMap->empty() ) {
        lState->theCurGroupPos = lState->theGroupMap->begin();
        while(lState->theCurGroupPos != lState->theGroupMap->end()){
          bindGroupBy(lState->theCurGroupPos, lState, aPlanState);
          ++lState->theCurGroupPos;
          STACK_PUSH ( true, lState );
        }
      }
      STACK_PUSH ( false, lState );
      STACK_END ( lState );
    }

    void GroupByIterator::matVarsAndGroupBy (
      GroupByState* aGroupByState,
      PlanState& aPlanState ) const {

      GroupKey* lGroupKey = new GroupKey();
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
      lGroupKey->theKey = lKey;
      lGroupKey->theTypedKey = lTypedKey;

      group_map_t* lGroupMap = aGroupByState->theGroupMap;
      std::vector<store::TempSeq_t>* lOuterSeq = 0;
      std::vector<GroupingOuterVar>::const_iterator lOuterVarIter = theOuterVars.begin();
      if ( lGroupMap->get ( lGroupKey, lOuterSeq ) ) {
        assert ( lOuterSeq > 0 );
        std::vector<store::TempSeq_t>::iterator lOuterSeqIter = lOuterSeq->begin();
        while ( lOuterVarIter != theOuterVars.end() ) {
          store::Iterator_t iterWrapper = new PlanIteratorWrapper ( lOuterVarIter->theInput, aPlanState );
          ( *lOuterSeqIter )->append ( iterWrapper, true );
          lOuterVarIter->theInput->reset ( aPlanState );
          ++lOuterSeqIter;
          ++lOuterVarIter;
        }
        delete lGroupKey;
      } else {
        lOuterSeq = new std::vector<store::TempSeq_t>();
        while ( lOuterVarIter != theOuterVars.end() ) {
          store::Iterator_t iterWrapper = new PlanIteratorWrapper ( lOuterVarIter->theInput, aPlanState );
          store::TempSeq_t result = GENV_STORE.createTempSeq ( iterWrapper, true, false );
          lOuterSeq->push_back ( result );
          lOuterVarIter->theInput->reset ( aPlanState );
          ++lOuterVarIter;
        }
        lGroupMap->insert ( lGroupKey, lOuterSeq );
      }
    }

    void GroupByIterator::bindGroupBy ( group_map_t::iterator aGroupMapIter,
                                        GroupByState* aGroupByState,
                                        PlanState& aPlanState ) const {
      //Bind grouping vars
      GroupKey* lGroupKey = ( *aGroupMapIter ).first;
      std::vector<store::Item_t>::iterator lGroupKeyIter = lGroupKey->theKey.begin();
      std::vector<GroupingSpec>::const_iterator lSpecIter = theGroupingSpecs.begin();
      while ( lSpecIter != theGroupingSpecs.end() ) {
        std::vector<ForVarIter_t>::const_iterator lGroupVarIter = lSpecIter->theInnerVars.begin();
        while ( lGroupVarIter != lSpecIter->theInnerVars.end() ) {
          ( *lGroupVarIter )->bind ( *lGroupKeyIter, aPlanState );
          ++lGroupVarIter;
        }
        ++lSpecIter;
        ++lGroupKeyIter;
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


    void GroupByIterator::openImpl ( PlanState& aPlanState, uint32_t& aOffset ) {
      StateTraitsImpl <GroupByState>::createState ( aPlanState, this->stateOffset, aOffset );
      GroupByState* lGroupByState = StateTraitsImpl<GroupByState>::getState(aPlanState, this->stateOffset);
      
      std::vector<XQPCollator*> lCollators;
      std::vector<GroupingSpec>::const_iterator lGroupSpecIter;
      for (lGroupSpecIter = theGroupingSpecs.begin();
           lGroupSpecIter != theGroupingSpecs.end();
           ++lGroupSpecIter )
      {
        xqpString lTmp = lGroupSpecIter->theCollation;
        if (lTmp.size() != 0) {
          XQPCollator* lCollator = aPlanState.theRuntimeCB->theCollationCache->
              getCollator(lTmp.theStrStore);
          lCollators.push_back(lCollator);
        }else{
          lCollators.push_back(NULL);
        }
      }
      lGroupByState->init(aPlanState, &lCollators); 
      
      theTupleIter->open ( aPlanState, aOffset );
      
      std::vector<GroupingSpec>::iterator iter;
      for ( iter = theGroupingSpecs.begin() ; iter != theGroupingSpecs.end(); iter++ ) {
        iter->open ( aPlanState, aOffset );
      }
      std::vector<GroupingOuterVar>::iterator iterOuterVars;
      for ( iterOuterVars = theOuterVars.begin() ; iterOuterVars != theOuterVars.end(); iterOuterVars++ ) {
        iterOuterVars->open ( aPlanState, aOffset );
      }
    }

    void GroupByIterator::accept ( PlanIterVisitor& v ) const {
      v.beginVisitFlworGroupBy();
      
      theTupleIter->accept ( v );
      
      std::vector<GroupingSpec>::const_iterator iter;
      for ( iter = theGroupingSpecs.begin() ; iter != theGroupingSpecs.end(); iter++ ) {
        v.beginVisitFlworGroupBySpec();
        iter->accept ( v );
        v.endVisitFlworGroupBySpec();
      }
      std::vector<GroupingOuterVar>::const_iterator iterOuterVars;
      for ( iterOuterVars = theOuterVars.begin() ; iterOuterVars != theOuterVars.end(); iterOuterVars++ ) {
        v.beginVisitFlworGroupByOuterVar();
        iterOuterVars->accept ( v );
        v.endVisitFlworGroupByOuterVar();
      }
      v.endVisitFlworGroupBy();
    }


    void GroupByIterator::closeImpl ( PlanState& aPlanState ) {
      std::vector<GroupingSpec>::iterator lGroupSpecIter;
      for ( lGroupSpecIter = theGroupingSpecs.begin();
            lGroupSpecIter != theGroupingSpecs.end();
            ++lGroupSpecIter ) {
        lGroupSpecIter->close ( aPlanState );
      }
      std::vector<GroupingOuterVar>::iterator lOuterVarIter;
      for ( lOuterVarIter = theOuterVars.begin();
            lOuterVarIter != theOuterVars.end();
            ++lOuterVarIter ) {
        lOuterVarIter->close ( aPlanState );
      }
      
      theTupleIter->close ( aPlanState );
      
      StateTraitsImpl<GroupByState>::destroyState ( aPlanState, this->stateOffset );
    }

    uint32_t GroupByIterator::getStateSize() const  {
      return StateTraitsImpl<GroupByState>::getStateSize();
    }

    void GroupByIterator::resetImpl ( PlanState& aPlanState ) const {
      std::vector<GroupingSpec>::const_iterator lGroupSpecIter;
      for ( lGroupSpecIter = theGroupingSpecs.begin();
            lGroupSpecIter != theGroupingSpecs.end();
            ++lGroupSpecIter ) {
        lGroupSpecIter->reset ( aPlanState );
      }
      std::vector<GroupingOuterVar>::const_iterator lOuterVarIter;
      for ( lOuterVarIter = theOuterVars.begin();
            lOuterVarIter != theOuterVars.end();
            ++lOuterVarIter ) {
        lOuterVarIter->reset ( aPlanState );
      }
      
      theTupleIter->reset ( aPlanState );
      
      StateTraitsImpl<GroupByState>::reset ( aPlanState, this->stateOffset );
    }

    uint32_t GroupByIterator::getStateSizeOfSubtree() const {
      int32_t size = this->getStateSize();
      size  += theTupleIter->getStateSizeOfSubtree();
      std::vector<GroupingSpec>::const_iterator iter;
      for ( iter = theGroupingSpecs.begin() ; iter != theGroupingSpecs.end(); iter++ ) {
        size += iter->getStateSizeOfSubtree();
      }
      std::vector<GroupingOuterVar>::const_iterator iterOuterVars;
      for ( iterOuterVars = theOuterVars.begin() ; iterOuterVars != theOuterVars.end(); iterOuterVars++ ) {
        size += iterOuterVars->getStateSizeOfSubtree();
      }
      return size;
    }


  } //Namespace flwor
}//Namespace zorba
