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

#include "runtime/function_item/function_item_iter.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/util/iterator_impl.h"
#include "runtime/function_item/function_item.h"

#include "compiler/parsetree/parsenodes.h"
#include "compiler/api/compilercb.h"
#include "compiler/api/compiler_api.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "store/api/item_factory.h"


using namespace std;

namespace zorba {


/*******************************************************************************

 ******************************************************************************/
bool
FunctionNameIterator::nextImpl(
    store::Item_t& r,
    PlanState& planState) const
{
  store::Item_t lFItem;
  FunctionItem* lFunctionItem = 0;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lFItem, theChildren[0], planState);

  // function signature guarantees that
  ZORBA_ASSERT(lFItem->isFunction());

  lFunctionItem = static_cast<FunctionItem*>(lFItem.getp());

  if (lFunctionItem->getFunctionName()) 
  {
    // non-inline function
    r = lFunctionItem->getFunctionName();
    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


/*******************************************************************************

 ******************************************************************************/
bool
FunctionArityIterator::nextImpl(
    store::Item_t& r,
    PlanState& planState) const
{
  store::Item_t lFItem;
  FunctionItem* lFunctionItem = 0;
  xs_integer    lInt;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lFItem, theChildren[0], planState);

  // function signature guarantees that
  ZORBA_ASSERT(lFItem->isFunction());

  lFunctionItem = static_cast<FunctionItem*>(lFItem.getp());

  lInt = Integer(lFunctionItem->getArity());

  STACK_PUSH(GENV_ITEMFACTORY->createInteger(r, lInt), state);

  STACK_END(state);
}

/*******************************************************************************

 ******************************************************************************/
bool
PartialApplyIterator::nextImpl(
    store::Item_t& r,
    PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  throw XQUERY_EXCEPTION(
    zerr::ZXQP0004_NOT_IMPLEMENTED,
    ERROR_PARAMS( "fn:partial-apply()" ),
    ERROR_LOC( loc )
  );

  STACK_END(state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
