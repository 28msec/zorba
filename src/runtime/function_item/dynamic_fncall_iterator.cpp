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

#include "diagnostics/util_macros.h"

#include "runtime/function_item/dynamic_fncall_iterator.h"
#include "runtime/function_item/function_item.h"
#include "runtime/core/fncall_iterator.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/visitors/planiter_visitor.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "store/api/item_factory.h"

#include "types/root_typemanager.h"

#include "system/globalenv.h"


namespace zorba 
{


SERIALIZABLE_CLASS_VERSIONS(DynamicFnCallIterator)



/*******************************************************************************

********************************************************************************/
DynamicFnCallIteratorState::DynamicFnCallIteratorState() 
{
}


/*******************************************************************************

********************************************************************************/
DynamicFnCallIteratorState::~DynamicFnCallIteratorState()
{
  if (theIsOpen) 
  {
    thePlan->close(*thePlanState);
  }
}


/*******************************************************************************

********************************************************************************/
void DynamicFnCallIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  thePlanState = &planState;
  thePlan = NULL;
  theIsOpen = false;
}


/*******************************************************************************

********************************************************************************/
void DynamicFnCallIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if (theIsOpen) 
  {
    thePlan->reset(planState);
  }
}


/*******************************************************************************

********************************************************************************/
DynamicFnCallIterator::~DynamicFnCallIterator() 
{
}


/*******************************************************************************

********************************************************************************/
uint32_t DynamicFnCallIterator::getStateSizeOfSubtree() const
{
  uint32_t size = NaryBaseIterator<DynamicFnCallIterator, DynamicFnCallIteratorState>::
                  getStateSizeOfSubtree();

  return size + sizeof(UDFunctionCallIteratorState);
}


/*******************************************************************************

********************************************************************************/
void DynamicFnCallIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<DynamicFnCallIteratorState>::createState(planState,
                                                           theStateOffset,
                                                           offset);

  StateTraitsImpl<DynamicFnCallIteratorState>::initState(planState, theStateOffset);

  DynamicFnCallIteratorState* state =
  StateTraitsImpl<DynamicFnCallIteratorState>::getState(planState, theStateOffset);

  state->theUDFStateOffset = offset;

  offset += sizeof(UDFunctionCallIteratorState);

  std::vector<PlanIter_t>::iterator lIter = theChildren.begin(); 
  std::vector<PlanIter_t>::iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter )
	{
    (*lIter)->open(planState, offset);
  }
}


/*******************************************************************************

********************************************************************************/
bool DynamicFnCallIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t item;
  store::Item_t funcItem;
  FunctionItem* fnItem;
  std::vector<PlanIter_t> argIters;
  std::vector<PlanIter_t>::iterator ite;
  std::vector<PlanIter_t>::const_iterator ite2;
  std::vector<PlanIter_t>::const_iterator end2;

  DynamicFnCallIteratorState* state;

  DEFAULT_STACK_INIT(DynamicFnCallIteratorState, state, planState);

  // first child must return exactly one item which is a function item
  // otherwise XPTY0004 is raised
  if (!consumeNext(funcItem, theChildren[0], planState))
  {
    RAISE_ERROR(err::XPTY0004, loc, 
    ERROR_PARAMS(ZED(XPTY0004_TypePromotion),
                 "empty-sequence()",
                 GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE->toSchemaString()));
  }

  if (consumeNext(item, theChildren[0], planState))
  {
    RAISE_ERROR(err::XPTY0004, loc, 
    ERROR_PARAMS(ZED(XPTY0004_NoMultiSeqTypePromotion),
                 GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE->toSchemaString()));
  }

  if (!funcItem->isFunction())
  {
    const TypeManager* tm = theSctx->get_typemanager();
    xqtref_t type = tm->create_value_type(funcItem);

    RAISE_ERROR(err::XPTY0004, loc, 
    ERROR_PARAMS(ZED(XPTY0004_TypePromotion),
                 type->toSchemaString(),
                 GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE->toSchemaString()));
  }

  fnItem = static_cast<FunctionItem*>(funcItem.getp());

  argIters.resize(theChildren.size() - 1 + fnItem->getVariables().size());

  ite = argIters.begin();

  ite2 = theChildren.begin();
  end2 = theChildren.end();
  ++ite2;

  for (; ite2 != end2; ++ite2, ++ite)
  {
    *ite = *ite2;
  }

  ite2 = fnItem->getVariables().begin();
  end2 = fnItem->getVariables().end();

  for(; ite2 != end2; ++ite2, ++ite) 
  {
    *ite = *ite2;
  }

  state->thePlan = fnItem->getImplementation(argIters);

  // must be opened after vars and params are set
  state->thePlan->open(planState, state->theUDFStateOffset);
  state->theIsOpen = true;
  
  while(consumeNext(result, state->thePlan, planState)) 
  {
    STACK_PUSH(true, state);
  }

  // need to close here early in case the plan is completely
  // consumed. Otherwise, the plan would still be opened
  // if destroyed from the state's destructor.
  state->thePlan->close(planState);
  state->theIsOpen = false;

  STACK_END(state);
};


/*******************************************************************************

********************************************************************************/
NARY_ACCEPT(DynamicFnCallIterator)


}//zorba namespace
/* vim:set et sw=2 ts=2: */
