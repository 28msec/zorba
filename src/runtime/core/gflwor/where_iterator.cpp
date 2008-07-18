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
#include "runtime/core/gflwor/where_iterator.h"
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
    //  WhereIterator                                                                //
    //                                                                             //
    /////////////////////////////////////////////////////////////////////////////////

    // theChild0 --> TupleIterator
    // theChild1 --> InputIterator
    WhereIterator::WhereIterator ( const QueryLoc& loc,
                               PlanIter_t aTupleIterator,
                               PlanIter_t aWhereClause ) :
        BinaryBaseIterator<WhereIterator, PlanIteratorState> ( loc, aTupleIterator, aWhereClause ) {
    }

    WhereIterator::~WhereIterator() {}

    bool WhereIterator::nextImpl ( store::Item_t& aResult, PlanState& aPlanState ) const {
      PlanIteratorState* lState;
      store::Item_t lItem;

      DEFAULT_STACK_INIT ( PlanIteratorState, lState, aPlanState );
      while ( consumeNext ( aResult, theChild0, aPlanState ) ) {
        if(evalToBool(theChild1, aPlanState)){
          STACK_PUSH ( true, lState );
        }        
      }
      STACK_PUSH ( false, lState );
      STACK_END ( lState );
    }

  } //Namespace flwor
}//Namespace zorba
