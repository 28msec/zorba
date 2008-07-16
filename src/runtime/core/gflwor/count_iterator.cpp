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
#include "runtime/core/gflwor/count_iterator.h"
#include "runtime/core/gflwor/common_binding.h"

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
    CountState::init ( PlanState& planState ) {
      PlanIteratorState::init ( planState );
      theCount=0;
    }

    void
    CountState::reset ( PlanState& planState ) {
      PlanIteratorState::reset ( planState );
      theCount=0;
    }

    /////////////////////////////////////////////////////////////////////////////////
    //                                                                             //
    //  ForIterator                                                                //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////

    // theChild0 --> TupleIterator
    // theChild1 --> InputIterator
    CountIterator::CountIterator ( const QueryLoc& loc,
                                   const store::Item_t& aVarName,
                                   PlanIter_t aTupleIterator,
                                   std::vector<ForVarIter_t> aCountVars ) :
        UnaryBaseIterator<CountIterator, CountState> ( loc, aTupleIterator ),
        theVarName ( aVarName ),
        theCountVars ( aCountVars ) {

    }


    CountIterator::~CountIterator() {}

    bool CountIterator::nextImpl ( store::Item_t& aResult, PlanState& aPlanState ) const {
      CountState* lState;
      store::Item_t lItem;

      DEFAULT_STACK_INIT ( CountState, lState, aPlanState );
      while ( consumeNext ( aResult, theChild, aPlanState ) ) {
        {
          store::Item_t lCountItem;
          GENV_ITEMFACTORY->createInteger ( lCountItem, Integer::parseInt ( lState->incCount() ) );
          bindVariables ( lCountItem, theCountVars, aPlanState );
        }
        STACK_PUSH ( true, lState );
      }
      STACK_PUSH ( false, lState );
      STACK_END ( lState );
    }

  } //Namespace flwor
}//Namespace zorba
