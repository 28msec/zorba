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

#include "store/api/store.h"
#include "store/api/iterator.h"
#include "store/api/item_factory.h"

#include "system/globalenv.h"

#include "runtime/core/internal_operators.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/visitors/planiter_visitor.h"

#include "diagnostics/xquery_diagnostics.h"

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(HoistIterator)
END_SERIALIZABLE_CLASS_VERSIONS(HoistIterator)

SERIALIZABLE_CLASS_VERSIONS(UnhoistIterator)
END_SERIALIZABLE_CLASS_VERSIONS(UnhoistIterator)

void HoistIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theDone = false;
}

void HoistIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theDone = false;
}

bool
HoistIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool error = false;
  HoistIteratorState *state;
  DEFAULT_STACK_INIT(HoistIteratorState, state, planState);

  while(!state->theDone) 
  {
    try 
    {
      state->theDone = !consumeNext(result, theChildren[0].getp(), planState);
    }
    catch(ZorbaException const& e) 
    {
      error = true;
      state->theDone = true;
      std::unique_ptr<ZorbaException> ze( clone( e ) );

      GENV_ITEMFACTORY->createError(result, ze.release());
    }
    STACK_PUSH(error || !state->theDone, state);
  }
  STACK_END(state);
}


NARY_ACCEPT(HoistIterator);


bool
UnhoistIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while(consumeNext(result, theChildren[0].getp(), planState)) 
  {
    if (result->isError()) 
    {
      result->getError()->polymorphic_throw();
    }
    STACK_PUSH(true, state);
  }
  STACK_END(state);
}


NARY_ACCEPT(UnhoistIterator);


}
/* vim:set et sw=2 ts=2: */
