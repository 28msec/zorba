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

#include "runtime/core/gflwor/tuplesource_iterator.h"

#include "zorbautils/fatal.h"
#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

#include "compiler/expression/expr.h"

#include "runtime/core/var_iterators.h"
#include "store/api/temp_seq.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "system/globalenv.h"


namespace zorba 
{
namespace flwor 
{

SERIALIZABLE_CLASS_VERSIONS(TupleSourceIterator)
END_SERIALIZABLE_CLASS_VERSIONS(TupleSourceIterator)


bool TupleSourceIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState) const
{
  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);

  STACK_PUSH(true, lState);
  STACK_PUSH(false, lState);
  STACK_END(lState);
}


NOARY_ACCEPT(TupleSourceIterator);


} //Namespace flwor
}//Namespace zorba
/* vim:set et sw=2 ts=2: */
