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

// This include needs to be kept in order to make sure the
// unique_ptr<dynamic_context> manages to dealocate the
// dynamic_context object.
#include "context/dynamic_context.h"


#include "runtime/hof/function_item.h"
#include "runtime/hof/function_item_iter.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item.h"
#include "store/api/temp_seq.h"

namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(FunctionItemIterator)
DEF_GET_NAME_AS_STRING(FunctionItemIterator)

/*******************************************************************************

********************************************************************************/
FunctionItemIterator::FunctionItemIterator(
      static_context* sctx,
      const QueryLoc& loc,
      FunctionItemInfo* fnInfo)
  :
  NaryBaseIterator<FunctionItemIterator,
                   PlanIteratorState>(sctx,
                                      loc,
                                      fnInfo->theInScopeVarIterators),
  theFunctionItemInfo(fnInfo)
{
}


FunctionItemIterator::~FunctionItemIterator()
{
}


void FunctionItemIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FunctionItemIterator, PlanIteratorState>*)this);
  ar & theFunctionItemInfo;
}


bool FunctionItemIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  csize numOuterVars;
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  numOuterVars = theFunctionItemInfo->theInScopeVarNames.size();

  if (numOuterVars > 0)
  {
    std::unique_ptr<dynamic_context> evalDctx;
    evalDctx.reset(new dynamic_context(planState.theGlobalDynCtx));

    for (csize i = 0; i < numOuterVars; ++i)
    {
      // hof ???? pre-allocate the wrappers.
      store::Iterator_t iter = new PlanIteratorWrapper(theChildren[i], planState);

      evalDctx->add_variable(theFunctionItemInfo->theInScopeVarIds[i], iter);
    }

    if (theFunctionItemInfo->theIsCoercion)
    {
      FunctionItemIterator* child = 
      dynamic_cast<FunctionItemIterator*>(theChildren[0].getp());

      if (child != NULL)
        theFunctionItemInfo->theQName = child->theFunctionItemInfo->theQName;
    }

    result = new FunctionItem(theFunctionItemInfo, evalDctx.get());
    evalDctx.release();
  }
  else
  {
    result = new FunctionItem(theFunctionItemInfo, NULL);
  }

  STACK_PUSH(result != NULL, state);
  STACK_END(state);
}


NARY_ACCEPT(FunctionItemIterator)


}

