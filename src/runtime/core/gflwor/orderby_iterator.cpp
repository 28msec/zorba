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
#include "runtime/core/gflwor/orderby_iterator.h"
#include "runtime/core/gflwor/common.h"

#include "zorbautils/fatal.h"
#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_manager.h"

#include "runtime/api/runtimecb.h"

#include "system/globalenv.h"
#include "context/collation_cache.h"
#include "runtime/visitors/planitervisitor.h"
#include "runtime/booleans/BooleanImpl.h"
#include "zorbautils/checked_vector.h"
#include <vector>

using namespace zorba;

namespace zorba {
  namespace gflwor {


    /////////////////////////////////////////////////////////////////////////////////
    //                                                                             //
    //  OrderSpec                                                                  //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////

    OrderSpec::OrderSpec (
      PlanIter_t aOrderByIter,
      bool aEmpty_least,
      bool aDescending )
        :
        theOrderByIter ( aOrderByIter ),
        theEmptyLeast ( aEmpty_least ),
        theDescending ( aDescending ),
        theCollator ( 0 ),
        theRuntimeCB ( 0 ) {
    }

    OrderSpec::OrderSpec (
      PlanIter_t aOrderByIter,
      bool aEmpty_least,
      bool aDescending,
      const xqpString& aCollation )
        :
        theOrderByIter ( aOrderByIter ),
        theEmptyLeast ( aEmpty_least ),
        theDescending ( aDescending ),
        theCollation ( aCollation ),
        theCollator ( 0 ),
        theRuntimeCB ( 0 ) {
    }

    void OrderSpec::reset ( PlanState& aPlanState ) const {
      theOrderByIter->reset ( aPlanState );
    }

    void OrderSpec::accept ( PlanIterVisitor& v ) const {
      v.beginVisitFlworOrderBy ( *theOrderByIter );
      v.endVisitFlworOrderBy ( *theOrderByIter );
    }

    void OrderSpec::open ( PlanState& aPlanState, uint32_t& offset ) const {
      theOrderByIter->open ( aPlanState, offset );
    }

    void OrderSpec::close ( PlanState& aPlanState ) const {
      theOrderByIter->close ( aPlanState );
    }

    uint32_t OrderSpec::getStateSizeOfSubtree() const {
      return theOrderByIter->getStateSizeOfSubtree();
    }

    /////////////////////////////////////////////////////////////////////////////////
    //                                                                             //
    //  OrderByState                                                               //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////


    OrderByState::OrderByState() : theOrderMap ( 0 ) {
    }


    OrderByState::~OrderByState() {
      //delete theOrderMap;
      //theOrderMap = 0;
    }


    void OrderByState::init ( PlanState& aState, std::vector<OrderSpec>* orderSpecs ) {
      PlanIteratorState::init ( aState );
      theOrderMap = order_map_t ( orderSpecs );
    }

    void OrderByState::reset ( PlanState& aPlanState ) {
      PlanIteratorState::reset ( aPlanState );
      theOrderMap.clear();
    }


    /////////////////////////////////////////////////////////////////////////////////
    //                                                                             //
    //  OrderByIterator                                                            //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////

    OrderByIterator::OrderByIterator ( const QueryLoc& aLoc,
                                       PlanIter_t& aTupleIterator,
                                       std::vector<OrderSpec>& aOrderSpecs,
                                       std::vector<ForVarIter_t>& aForVariableInput,
                                       std::vector<LetVarIter_t>& aLetVariableInput,
                                       std::vector< std::vector<ForVarIter_t> >& aForVariableOutput,
                                       std::vector< std::vector<LetVarIter_t> >& aLetVariableOutput ) :
        Batcher<OrderByIterator> ( aLoc ),
        theTupleIter ( aTupleIterator ),
        theOrderSpecs ( aOrderSpecs ),
        theForVariableInput ( aForVariableInput ),
        theLetVariableInput ( aLetVariableInput ),
        theForVariableOutput ( aForVariableOutput ),
        theLetVariableOutput ( aLetVariableOutput ) {

    }

    OrderByIterator::~OrderByIterator() {

    }

    void OrderByIterator::openImpl ( PlanState& aPlanState, uint32_t& aOffset ) {
      StateTraitsImpl<OrderByState>::createState ( aPlanState, this->stateOffset, aOffset );
      OrderByState* lOrderByState = StateTraitsImpl<OrderByState>::getState ( aPlanState, this->stateOffset );

      //Do a manually pass to set the Collator
      std::vector<OrderSpec>::iterator iter;
      for ( iter = theOrderSpecs.begin();
            iter != theOrderSpecs.end();
            iter++ ) {
        iter->open ( aPlanState, aOffset );
        iter->theRuntimeCB = aPlanState.theRuntimeCB; // HACK should be done in a seperate class
        if ( iter->theCollation.size() != 0 ) {
          xqpString lTmp = iter->theCollation;
          iter->theCollator = aPlanState.theRuntimeCB->theCollationCache->
                              getCollator ( lTmp.theStrStore );
        }
      }

      lOrderByState->init ( aPlanState, &theOrderSpecs );
      theTupleIter->open ( aPlanState, aOffset );
      openVectorPtr<ForVarIter_t> ( theForVariableInput, aPlanState, aOffset );
      openVectorPtr<LetVarIter_t> ( theLetVariableInput, aPlanState, aOffset );
    }

    void OrderByIterator::resetImpl ( PlanState& aPlanState ) const {
      OrderByState* lOrderByState = StateTraitsImpl<OrderByState>::getState ( aPlanState, this->stateOffset );
      lOrderByState->reset ( aPlanState );

      theTupleIter->reset ( aPlanState );
      resetVector<OrderSpec> ( theOrderSpecs, aPlanState );
      resetVectorPtr<ForVarIter_t > ( theForVariableInput, aPlanState );
      resetVectorPtr<LetVarIter_t > ( theLetVariableInput, aPlanState );
    }

    void OrderByIterator::closeImpl ( PlanState& aPlanState ) {
      theTupleIter->close ( aPlanState );
      closeVector<OrderSpec> ( theOrderSpecs, aPlanState );
      closeVectorPtr<ForVarIter_t> ( theForVariableInput, aPlanState );
      closeVectorPtr<LetVarIter_t> ( theLetVariableInput, aPlanState );
      StateTraitsImpl<OrderByState>::destroyState ( aPlanState, this->stateOffset );
    }


    uint32_t OrderByIterator::getStateSize() const {
      return sizeof ( OrderByState );
    }

    uint32_t OrderByIterator::getStateSizeOfSubtree() const {
      int32_t lSize = this->getStateSize();
      lSize += getStateSizeOfSubtreeVector<OrderSpec> ( theOrderSpecs );
      lSize += getStateSizeOfSubtreeVectorPtr<ForVarIter_t> ( theForVariableInput );
      lSize += getStateSizeOfSubtreeVectorPtr<LetVarIter_t> ( theLetVariableInput );
      return lSize;
    }

    void OrderByIterator::accept ( PlanIterVisitor& ) const {

    }

    bool OrderByIterator::nextImpl ( store::Item_t& aResult, PlanState& aPlanState ) const {
      OrderByState* lState;
      store::Item_t lItem;
      DEFAULT_STACK_INIT ( OrderByState, lState, aPlanState );
      while ( consumeNext ( aResult, theTupleIter, aPlanState ) ) {
        matVarsAndOrderBy(lState, aPlanState);
      }
      lState->theCurOrderPos = lState->theOrderMap.begin();
      while(lState->theCurOrderPos != lState->theOrderMap.end()){
        bindOrderBy(lState->theCurOrderPos,aPlanState);
        STACK_PUSH ( true, lState );
        ++(lState->theCurOrderPos);
      }
      STACK_PUSH ( false, lState );
      STACK_END ( lState );
    }
    

    void OrderByIterator::matVarsAndOrderBy ( OrderByState* aOrderByState,
        PlanState& aPlanState ) const {
      //Create the key

      std::vector<store::Item_t> orderKey;
      for ( std::vector<OrderSpec>::const_iterator lSpecIter = theOrderSpecs.begin();
            lSpecIter != theOrderSpecs.end();
            ++lSpecIter ) {
        orderKey.push_back ( NULL );
        store::Item_t& lKeyLocation = orderKey.back();
        if ( consumeNext ( lKeyLocation, lSpecIter->theOrderByIter.getp(), aPlanState ) ) {
          store::Item_t temp;
          if ( consumeNext ( temp, lSpecIter->theOrderByIter.getp(), aPlanState ) ) {
            ZORBA_ERROR_DESC ( XPTY0004, "Expected a singleton" );
          }
        }
        lSpecIter->theOrderByIter->reset ( aPlanState );
      }

      //Materialize the tuple
      std::vector<store::Item_t > lItems;
      for ( std::vector<ForVarIter_t>::const_iterator lForInputIter = theForVariableInput.begin();
            lForInputIter != theForVariableInput.end();
            ++lForInputIter ) {
        lItems.push_back ( NULL );
        store::Item_t& lItemLocation = lItems.back();
        consumeNext ( lItemLocation, lForInputIter->getp(), aPlanState );
        ( *lForInputIter )->reset ( aPlanState );
      }

      std::vector<store::TempSeq_t > lSequences;
      for ( std::vector<LetVarIter_t>::const_iterator lLetInputIter = theLetVariableInput.begin();
            lLetInputIter != theLetVariableInput.end();
            ++lLetInputIter ) {
        lSequences.push_back ( NULL );
        store::TempSeq_t& lTempSeqLocation = lSequences.back();
        createTempSeq ( lTempSeqLocation, *lLetInputIter, aPlanState, false );
        ( *lLetInputIter )->reset ( aPlanState );
      }
      OrderValue lOrderValue ( lItems, lSequences );

      aOrderByState->theOrderMap.insert ( std::pair<std::vector<store::Item_t>, OrderValue> ( orderKey, lOrderValue ) );
    }
    

    void OrderByIterator::bindOrderBy ( order_map_t::const_iterator& aOrderMapIter,
                                        PlanState& aPlanState ) const {
      const OrderValue& lOrderValue = aOrderMapIter->second;
      for(size_t i=0; i < theForVariableOutput.size(); ++i){
        bindVariables(lOrderValue.theItems[i], theForVariableOutput[i], aPlanState);
      }
      for(size_t i=0; i < theLetVariableOutput.size(); ++i){
        bindVariables(lOrderValue.theSequences[i], theLetVariableOutput[i], aPlanState);
      }
    }

    /////////////////////////////////////////////////////////////////////////////////
    //                                                                             //
    //  OrderKeyCmp                                                                //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////


    int8_t OrderKeyCmp::compare (
      RuntimeCB* aRuntimeCB,
      const store::Item_t& s1,
      const store::Item_t& s2,
      bool desc,
      bool emptyLeast,
      XQPCollator* collator ) const {
      if ( empty_item ( aRuntimeCB, s1 ) ) {
        if ( empty_item ( aRuntimeCB, s2 ) )
          return descAsc ( 0, desc );
        else
          return descAsc ( emptyLeast ? -1 : 1, desc );
      } else if ( empty_item ( aRuntimeCB, s2 ) ) {
        return descAsc ( emptyLeast ? 1 : -1, desc );
      } else {
        // danm: both valueCompare (x, NaN) and valueCompare (NaN, x) return 2.
        // That's why empty_item is needed.
        int8_t result = CompareIterator::valueCompare ( aRuntimeCB, s1 , s2, collator );
        if ( result > 1 || result < -1 ) {
          ZORBA_ERROR_DESC ( XPTY0004, "Non-comparable types found while sorting" );

        }
        return descAsc ( result , desc );
      }
    }


    int8_t OrderKeyCmp::descAsc ( int8_t result, bool desc ) const {
      ZORBA_ASSERT ( result <= 1 && result >= -1 );
      return desc ? -result : result;
    }


    bool OrderKeyCmp::operator() (
      const std::vector<store::Item_t>& s1,
      const std::vector<store::Item_t>& s2 ) const {
      ZORBA_ASSERT ( s1.size() == s2.size() );
      ZORBA_ASSERT ( s1.size() == mOrderSpecs->size() );

      std::vector<store::Item_t>::const_iterator s1iter = s1.begin();
      std::vector<store::Item_t>::const_iterator s2iter = s2.begin();
      std::vector<OrderSpec>::const_iterator orderSpecIter = mOrderSpecs->begin();


      while ( s1iter != s1.end() ) {
        int8_t cmp = compare ( orderSpecIter->theRuntimeCB,
                               *s1iter,
                               *s2iter,
                               orderSpecIter->theDescending,
                               orderSpecIter->theEmptyLeast,
                               orderSpecIter->theCollator );
        if ( cmp == 1 ) {
          return false;
        } else if ( cmp == -1 ) {
          return true;
        }
        ++s1iter;
        ++s2iter;
        ++orderSpecIter;
      }
      return false;
    }

  } //Namespace flwor
}//Namespace zorba
