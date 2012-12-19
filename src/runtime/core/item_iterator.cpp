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

#include "diagnostics/assert.h"

#include "compiler/api/compilercb.h"
#include "compiler/expression/var_expr.h"
#include "compiler/expression/function_item_expr.h"
#include "compiler/expression/expr_manager.h"
#include "functions/udf.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/core/item_iterator.h"
#include "runtime/core/var_iterators.h"
#include "runtime/function_item/function_item.h"
#include "runtime/booleans/BooleanImpl.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item.h"
#include "store/api/temp_seq.h"


namespace zorba
{
SERIALIZABLE_CLASS_VERSIONS(EmptyIterator)

SERIALIZABLE_CLASS_VERSIONS(SingletonIterator)

SERIALIZABLE_CLASS_VERSIONS(DynamicFunctionIterator)

SERIALIZABLE_CLASS_VERSIONS(IfThenElseIterator)


/*******************************************************************************

********************************************************************************/
bool EmptyIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  return false;
}


NOARY_ACCEPT(EmptyIterator);


/*******************************************************************************

********************************************************************************/
void SingletonIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (NoaryBaseIterator<SingletonIterator,
                                             PlanIteratorState>*)this);
  ar & theValue;
}


/*******************************************************************************

********************************************************************************/
void SingletonIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<PlanIteratorState>::
  createState(planState, theStateOffset, offset);
}


bool SingletonIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  result = theValue;
  STACK_PUSH ( result != NULL, state );
  STACK_END (state);
}


void SingletonIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);
  v.endVisit(*this);
}


uint32_t SingletonIterator::getStateSizeOfSubtree() const
{
  int32_t size = this->getStateSize();
  return size;
}


/*******************************************************************************

********************************************************************************/
void DynamicFunctionIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (NoaryBaseIterator<DynamicFunctionIterator,
                      PlanIteratorState>*)this);
  ar & theDynamicFunctionInfo;
  // TODO: add the rest
}


/*******************************************************************************

********************************************************************************/
DynamicFunctionIterator::DynamicFunctionIterator(
      static_context* sctx,
      const QueryLoc& loc,
      DynamicFunctionInfo* fnInfo)
  :
  NaryBaseIterator<DynamicFunctionIterator, PlanIteratorState>(sctx, loc, fnInfo->theScopedVarsIterators),
  theDynamicFunctionInfo(fnInfo)
{
}

bool DynamicFunctionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // This portion is taken from the eval iterator
  {
    // Create the "import" sctx. The importOuterEnv() method (called below) will
    // register into the importSctx (a) the outer vars of the eval query and (b)
    // the expression-level ns bindings of the outer query at the place where
    // the eval call appears at.
    static_context* importSctx = theSctx->create_child_context();

    // Create the root sctx for the eval query
    static_context* evalSctx = importSctx->create_child_context();

    // Create the ccb for the eval query

    std::auto_ptr<CompilerCB> evalCCB;
    evalCCB.reset(new CompilerCB(*planState.theCompilerCB));
    evalCCB->theRootSctx = evalSctx;
    (evalCCB->theSctxMap)[1] = evalSctx;
    
    // Create the dynamic context for the eval query
    std::auto_ptr<dynamic_context> evalDctx;
    evalDctx.reset(new dynamic_context(planState.theGlobalDynCtx));
    
    // Import the outer environment.
    ulong maxOuterVarId;
    importOuterEnv(planState, evalCCB.get(), importSctx, evalDctx.get(), maxOuterVarId);

    // Set the values for the (explicit) external vars of the eval query
    setExternalVariables(evalCCB.get(), importSctx, evalDctx.get());

    /*
    std::cerr << "--> " << toString() << ": creating function item with params: " << std::endl;
    for (csize i=0; i<theChildren.size(); i++)
    {
      std::cerr << "    "
          << (theDynamicFunctionInfo->theScopedVarsNames[i].getp() ?
              theDynamicFunctionInfo->theScopedVarsNames[i]->show() : "")
          // << ": " << (varsValues[i].getp() ? varsValues[i]->toString() : "NULL")
          << std::endl;
    }
    */
    
    // std::cerr << "--> the body before: " << static_cast<user_function*>(theDynamicFunctionInfo->theFunction.getp())->getBody()->toString() << std::endl;

    result = new FunctionItem(theDynamicFunctionInfo, evalCCB.release(), evalDctx.release());
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
void DynamicFunctionIterator::importOuterEnv(
    PlanState& planState,
    CompilerCB* evalCCB,
    static_context* importSctx,
    dynamic_context* evalDctx,
    ulong& maxOuterVarId) const
{
  maxOuterVarId = 1;

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

  csize numOuterVars = theDynamicFunctionInfo->theScopedVarsNames.size();

  for (csize i = 0; i < numOuterVars; ++i)
  {
    var_expr* ve = evalCCB->theEM->create_var_expr(importSctx,
                                                   NULL,
                                                   loc,
                                                   var_expr::hof_var,
                                                   theDynamicFunctionInfo->theScopedVarsNames[i].getp());

    // ve->set_type(theOuterVarTypes[i]); TODO: get types

    if (!theDynamicFunctionInfo->theIsGlobalVar[i])
    {
      ++curChild;

      store::Iterator_t iter = new PlanIteratorWrapper(theChildren[curChild], planState);

      evalDctx->add_variable(maxOuterVarId, iter);

      ve->set_unique_id(maxOuterVarId);

      if (theDynamicFunctionInfo->theSubstVarsValues[i] != NULL
          &&
          theDynamicFunctionInfo->theSubstVarsValues[i]->get_unique_id() == 0)
      {
        theDynamicFunctionInfo->theSubstVarsValues[i]->set_var_info(NULL);
        theDynamicFunctionInfo->theSubstVarsValues[i]->set_unique_id(maxOuterVarId);
      }

      ++maxOuterVarId;
    }
    else
    {
      static_context* outerSctx = importSctx->get_parent();

      VarInfo* outerGlobalVar = outerSctx->lookup_var(theDynamicFunctionInfo->theScopedVarsNames[i]);

      ulong outerGlobalVarId;

      if (outerGlobalVar)
      {
        outerGlobalVarId = outerGlobalVar->getId();
      }
      else if (outerGlobalVar == NULL)
      {
        // std::cerr << "--> searching for var: " << theDynamicFunctionInfo->theScopedVarsNames[i]->toString() << std::endl;
        for (csize j=0; j<theDynamicFunctionInfo->theSubstVarsValues.size(); j++)
        {
          // std::cerr << "    substVar: " << (theDynamicFunctionInfo->theSubstVarsValues[j] ? theDynamicFunctionInfo->theSubstVarsValues[j]->toString() : "NULL");
          if (theDynamicFunctionInfo->theSubstVarsValues[j]->get_name()->equals(theDynamicFunctionInfo->theScopedVarsNames[i].getp()))
            outerGlobalVarId = theDynamicFunctionInfo->theSubstVarsValues[j]->get_unique_id();
        }
      }

      // ZORBA_ASSERT(outerGlobalVar);

      // std::cerr << "--> importOuterEnv(): outerSctx: " << outerSctx->toString() << std::endl;

      if (theDynamicFunctionInfo->theSubstVarsValues[i] != NULL
          &&
          theDynamicFunctionInfo->theSubstVarsValues[i]->get_unique_id() == 0)
      {
        // theDynamicFunctionInfo->theSubstVarsValues[i]->set_var_info(NULL);
        theDynamicFunctionInfo->theSubstVarsValues[i]->set_unique_id(outerGlobalVarId);
      }

      ve->set_unique_id(outerGlobalVarId);
    }

    // std::cerr << "--> importOuterEnv(): updated id for subst_var: "
    //  << (theDynamicFunctionInfo->theSubstVarsValues[i].getp()
    //  ? theDynamicFunctionInfo->theSubstVarsValues[i]->toString() : "NULL\n");

    importSctx->bind_var(ve, loc, err::XQST0049);
  }

  // Import the outer-query ns bindings

  store::NsBindings::const_iterator ite = theDynamicFunctionInfo->theLocalBindings.begin();
  store::NsBindings::const_iterator end = theDynamicFunctionInfo->theLocalBindings.end();

  for (; ite != end; ++ite)
  {
    importSctx->bind_ns(ite->first, ite->second, loc);
  }
}


/****************************************************************************//**

********************************************************************************/
void DynamicFunctionIterator::setExternalVariables(
    CompilerCB* ccb,
    static_context* importSctx,
    dynamic_context* evalDctx) const
{
  std::vector<VarInfo*> innerVars;

  CompilerCB::SctxMap::const_iterator sctxIte = ccb->theSctxMap.begin();
  CompilerCB::SctxMap::const_iterator sctxEnd = ccb->theSctxMap.end();

  for (; sctxIte != sctxEnd; ++sctxIte)
  {
    sctxIte->second->getVariables(innerVars, true, false, true);
  }

  FOR_EACH(std::vector<VarInfo*>, ite, innerVars)
  {
    VarInfo* innerVar = (*ite);

    if (!innerVar->isExternal())
      continue;

    ulong innerVarId = innerVar->getId();

    VarInfo* outerVar = importSctx->lookup_var(innerVar->getName());

    if (!outerVar)
      continue;

    store::Item_t itemValue;
    store::TempSeq_t seqValue;

    evalDctx->get_variable(outerVar->getId(),
                           outerVar->getName(),
                           loc,
                           itemValue,
                           seqValue);

    if (itemValue != NULL)
    {
      evalDctx->add_variable(innerVarId, itemValue);
    }
    else
    {
      store::Iterator_t iteValue = seqValue->getIterator();
      evalDctx->add_variable(innerVarId, iteValue);
    }
  }
}


void DynamicFunctionIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}


/*******************************************************************************

********************************************************************************/
IfThenElseIterator::IfThenElseIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& aCondIter,
    PlanIter_t& aThenIter,
    PlanIter_t& aElseIter,
    bool aIsBooleanIter)
  :
  Batcher<IfThenElseIterator>(sctx, loc),
  theCondIter(aCondIter),
  theThenIter(aThenIter),
  theElseIter(aElseIter),
  theIsBooleanIter(aIsBooleanIter)
{
}


void IfThenElseIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (Batcher<IfThenElseIterator>*)this);
  ar & theCondIter;
  ar & theThenIter;
  ar & theElseIter;
  ar & theIsBooleanIter;
}


void IfThenElseIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);
  theCondIter->accept(v);
  theThenIter->accept(v);
  theElseIter->accept(v);
  v.endVisit(*this);
}


bool IfThenElseIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  IfThenElseIteratorState* state;
  DEFAULT_STACK_INIT(IfThenElseIteratorState, state, planState);

  if (theIsBooleanIter)
  {
    store::Item_t condResult;
    consumeNext ( condResult, theCondIter.getp(), planState );
    state->theThenUsed = condResult->getBooleanValue();
  }
  else
  {
    state->theThenUsed = FnBooleanIterator::effectiveBooleanValue(this->loc,
                                                                  planState,
                                                                  theCondIter);
  }

  while (true)
  {
    STACK_PUSH(consumeNext(result,
                           (state->theThenUsed ? theThenIter.getp() : theElseIter.getp()),
                           planState),
               state);
  }

  STACK_END(state);
}


void IfThenElseIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<IfThenElseIteratorState>::
  createState(planState, theStateOffset, offset);

  theCondIter->open(planState, offset);
  theThenIter->open(planState, offset);
  theElseIter->open(planState, offset);
}


void IfThenElseIterator::resetImpl(PlanState& planState) const
{
  StateTraitsImpl<IfThenElseIteratorState>::reset(planState, theStateOffset);

  theCondIter->reset(planState);
  theThenIter->reset(planState);
  theElseIter->reset(planState);
}


void IfThenElseIterator::closeImpl(PlanState& planState) const
{
  theCondIter->close(planState);
  theThenIter->close(planState);
  theElseIter->close(planState);

  StateTraitsImpl<IfThenElseIteratorState>::destroyState(planState, theStateOffset);
}


uint32_t IfThenElseIterator::getStateSizeOfSubtree() const
{
  return getStateSize()
      + theCondIter->getStateSizeOfSubtree()
      + theThenIter->getStateSizeOfSubtree()
      + theElseIter->getStateSizeOfSubtree();
}


} /* namespace zorba */

/* vim:set et sw=2 ts=2: */
