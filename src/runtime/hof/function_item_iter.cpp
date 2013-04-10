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
// auto_ptr<dynamic_context> manages to dealocate the
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

/*******************************************************************************

********************************************************************************/
FunctionItemIterator::FunctionItemIterator(
      static_context* sctx,
      const QueryLoc& loc,
      FunctionItemInfo* fnInfo)
  :
  NaryBaseIterator<FunctionItemIterator, PlanIteratorState>(sctx, loc, fnInfo->theScopedVarsIterators),
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
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // This portion is taken from the eval iterator
  {
    // Create the dynamic context for the eval query
    std::auto_ptr<dynamic_context> evalDctx;
    evalDctx.reset(new dynamic_context(planState.theGlobalDynCtx));

    // Import the outer environment.
    importOuterEnv(planState,
                   theFunctionItemInfo->theCCB,
                   theFunctionItemInfo->theClosureSctx,
                   evalDctx.get());

    if (theFunctionItemInfo->theIsCoercion)
    {
      FunctionItemIterator* child = dynamic_cast<FunctionItemIterator*>(theChildren[0].getp());
      if (child != NULL)
        theFunctionItemInfo->theQName = child->theFunctionItemInfo->theQName;
    }

    result = new FunctionItem(theFunctionItemInfo, evalDctx.release());
  }

  STACK_PUSH ( result != NULL, state );
  STACK_END (state);
}


/********************************************************************************

  These functions are copied from the EvalIterator -- maybe they could be shared.

********************************************************************************/

/****************************************************************************//**
  This method imports a static and dynamic environment from the quter query into
  the eval query. In particular:

  (a) imports into the importSctx all the outer vars of the eval query
  (b) imports into the importSctx all the ns bindings of the outer query at the
      place where the eval call appears at
  (c) Copies all the var values from the outer-query global dctx into the eval-
      query dctx.
  (d) For each of the non-global outer vars, places its value into the eval dctx.
      The var value is represented as a PlanIteratorWrapper over the subplan that
      evaluates the domain expr of the eval var.
  (e) Computes the max var id of all the var values set in steps (c) and (d).
      This max varid will be passed to the compiler of the eval query so that
      the varids that will be generated for the eval query will not conflict with
      the varids of the outer vars and the outer-query global vars.
********************************************************************************/
void FunctionItemIterator::importOuterEnv(
    PlanState& planState,
    CompilerCB* evalCCB,
    static_context* importSctx,
    dynamic_context* evalDctx) const
{
  ulong maxOuterVarId = 1;

  // Copy all the var values from the outer-query global dctx into the eval-query
  // dctx. This is need to handle the following scenario: (a) $x is an outer-query
  // global var that is not among the outer vars of the eval query (because $x was
  // hidden at the point where the eval call is made inside the outer query), and
  // (b) foo() is a function decalred in the outer query that accessed $x and is
  // invoked by the eval query. The copying must be done using the same positions
  // (i.e., var ids) in the eval dctx as in the outer-query dctx.

  dynamic_context* outerDctx = evalDctx->getParent();

  const std::vector<dynamic_context::VarValue>& outerGlobalValues =
  outerDctx->get_variables();

  csize numOuterGlobalVars = outerGlobalValues.size();

  for (csize i = 0; i < numOuterGlobalVars; ++i)
  {
    const dynamic_context::VarValue& outerVar = outerGlobalValues[i];

    if (!outerVar.isSet())
      continue;

    ulong outerVarId = static_cast<ulong>(i);

    if (outerVarId > maxOuterVarId)
      maxOuterVarId = outerVarId;

    store::Item_t itemValue;
    store::TempSeq_t seqValue;

    if (outerVar.hasItemValue())
    {
      store::Item_t value = outerVar.theValue.item;
      evalDctx->add_variable(outerVarId, value);
    }
    else
    {
      store::Iterator_t iteValue = outerVar.theValue.temp_seq->getIterator();
      evalDctx->add_variable(outerVarId, iteValue);
    }
  }

  ++maxOuterVarId;

  // Import the outer vars. Specifically, for each outer var:
  // (a) create a declaration inside the importSctx.
  // (b) Set its var id
  // (c) If it is not a global one, set its value within the eval dctx.
  csize curChild = -1;

  csize numOuterVars = theFunctionItemInfo->theScopedVarsNames.size();


  for (csize i = 0; i < numOuterVars; ++i)
  {
    if (!theFunctionItemInfo->theIsGlobalVar[i])
    {
      ++curChild;

      store::Iterator_t iter = new PlanIteratorWrapper(theChildren[curChild], planState);

      evalDctx->add_variable(theFunctionItemInfo->theVarId[i], iter);
    }
  }
}


NARY_ACCEPT(FunctionItemIterator)


}

