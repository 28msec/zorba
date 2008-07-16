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
#include "runtime/core/gflwor/tuplesource_iterator.h"

#include "zorbautils/fatal.h"
#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_manager.h"

#include "compiler/expression/expr.h"

#include "runtime/core/var_iterators.h"
#include "runtime/api/runtimecb.h"
#include "store/api/temp_seq.h"
#include "runtime/visitors/planitervisitor.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "system/globalenv.h"


namespace zorba {
  namespace gflwor {
    TupleSourceIterator::TupleSourceIterator ( const QueryLoc& aLoc ) :
        NoaryBaseIterator<TupleSourceIterator, PlanIteratorState> ( aLoc ) {}

    TupleSourceIterator::~TupleSourceIterator() {}

    bool TupleSourceIterator::nextImpl ( store::Item_t& aResult, PlanState& aPlanState ) const {
      PlanIteratorState* lState;
      store::Item_t lTuple;
      DEFAULT_STACK_INIT ( PlanIteratorState, lState, aPlanState );
      STACK_PUSH ( true, lState );
      STACK_PUSH ( false, lState );
      STACK_END ( lState );
    }

  } //Namespace flwor
}//Namespace zorba
