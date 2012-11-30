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
FnMapPairsState::~FnMapPairsState()
{
  if (theIsOpen)
  {
    thePlan->close(*thePlanState);
  }
}


void FnMapPairsState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  thePlanState = &planState;
  thePlan = NULL;
  theIsOpen = false;
}


void FnMapPairsState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if (theIsOpen)
  {
    thePlan->reset(planState);
  }
}


bool FnMapPairs::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t lFItem, child1, child2;
  FunctionItem* lFunctionItem = NULL;
  

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lFItem, theChildren[0], planState);

  // function signature guarantees that
  ZORBA_ASSERT(lFItem->isFunction());

  lFunctionItem = static_cast<FunctionItem*>(lFItem.getp());
  
  while (true)
  {
    if (!consumeNext(child1, theChildren[1], planState) ||
        !consumeNext(child2, theChildren[2], planState))
      break;
        
    if (child1.getp() && child2.getp())
    {
      
    }
    else
    {
      result = NULL;
      STACK_PUSH(true, state);
    }
  }

  STACK_END(state);
}


/*******************************************************************************

 ******************************************************************************/
bool
FnFoldLeft::nextImpl(
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

} // namespace zorba
/* vim:set et sw=2 ts=2: */
