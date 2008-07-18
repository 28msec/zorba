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
#include "runtime/core/gflwor/for_iterator.h"
#include "runtime/core/gflwor/common.h"

#include "runtime/core/var_iterators.h"
#include "runtime/visitors/planitervisitor.h"
#include "store/api/store.h"
#include "system/globalenv.h"
#include "store/api/item_factory.h"

using namespace zorba;

namespace zorba {
  namespace gflwor {

    /////////////////////////////////////////////////////////////////////////////////
    //                                                                             //
    //  For  State                                                                 //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////

    void
    ForState::init ( PlanState& planState ) {
      PlanIteratorState::init ( planState );
      thePosition=0;
    }

    void
    ForState::reset ( PlanState& planState ) {
      PlanIteratorState::reset ( planState );
      thePosition=0;
    }

    /////////////////////////////////////////////////////////////////////////////////
    //                                                                             //
    //  ForIterator                                                                //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////

    // theChild0 --> TupleIterator
    // theChild1 --> InputIterator
    ForIterator::ForIterator ( const QueryLoc& loc,
                               const store::Item_t& aVarName,
                               PlanIter_t aTupleIterator,
                               PlanIter_t aInput,
                               std::vector<ForVarIter_t> aForVars,
                               std::vector<ForVarIter_t> aPosVars ) :
        BinaryBaseIterator<ForIterator, ForState> ( loc, aTupleIterator, aInput ),
        theVarName ( aVarName ), theForVars ( aForVars ),
        thePosVars ( aPosVars ) {
          theHasPosVars = !thePosVars.empty();
    }

    ForIterator::ForIterator ( const QueryLoc& loc,
                               const store::Item_t& aVarName,
                               PlanIter_t aTupleIterator,
                               PlanIter_t aInput,
                               std::vector<ForVarIter_t> aForVars ) :
        BinaryBaseIterator<ForIterator, ForState> ( loc, aTupleIterator, aInput ),
        theVarName ( aVarName ),
        theHasPosVars(false),
        theForVars ( aForVars ){
    }

    ForIterator::~ForIterator() {}

    bool ForIterator::nextImpl ( store::Item_t& aResult, PlanState& aPlanState ) const {
      ForState* lState;
      store::Item_t lItem;
      
      DEFAULT_STACK_INIT ( ForState, lState, aPlanState );
      while ( consumeNext ( aResult, theChild0, aPlanState ) ) {
        while ( consumeNext ( lItem, theChild1, aPlanState ) ) {
          bindVariables ( lItem, theForVars, aPlanState );
          if ( theHasPosVars ) {
            store::Item_t lPosItem;
            GENV_ITEMFACTORY->createInteger(lPosItem, Integer::parseInt(lState->incReturnPosition()));
            bindVariables ( lPosItem, thePosVars, aPlanState );
          }
          STACK_PUSH ( true, lState );
        }
        theChild1->reset(aPlanState);
        
      }
      STACK_PUSH ( false, lState );
      STACK_END ( lState );
    }

  } //Namespace flwor
}//Namespace zorba
