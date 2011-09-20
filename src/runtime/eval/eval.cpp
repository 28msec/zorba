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

#include <sstream>

#include "store/api/temp_seq.h"

#include "runtime/eval/eval.h"

#include "runtime/visitors/planiter_visitor.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/util/iterator_impl.h"

#include "compiler/parsetree/parsenodes.h"
#include "compiler/api/compilercb.h"
#include "compiler/api/compiler_api.h"
#include "compiler/expression/var_expr.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "types/typeimpl.h"

#include "api/auditimpl.h"


namespace zorba {


SERIALIZABLE_CLASS_VERSIONS(EvalIterator)
END_SERIALIZABLE_CLASS_VERSIONS(EvalIterator)


/****************************************************************************//**

********************************************************************************/
EvalIteratorState::EvalIteratorState() 
{
}


/****************************************************************************//**

********************************************************************************/
EvalIteratorState::~EvalIteratorState() 
{
}


/****************************************************************************//**

********************************************************************************/
EvalIterator::EvalIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    const std::vector<store::Item_t>& aVarNames,
    const std::vector<xqtref_t>& aVarTypes,
    expr_script_kind_t scriptingKind,
    const store::NsBindings& localBindings)
  : 
  NaryBaseIterator<EvalIterator, EvalIteratorState>(sctx, loc, children),
  theVarNames(aVarNames),
  theVarTypes(aVarTypes),
  theScriptingKind(scriptingKind),
  theLocalBindings(localBindings)
{
}


/****************************************************************************//**

********************************************************************************/
EvalIterator::~EvalIterator() 
{
}


/****************************************************************************//**

********************************************************************************/
void EvalIterator::serialize(::zorba::serialization::Archiver& ar)
{
  ar.set_serialize_everything();
  serialize_baseclass(ar,
  (NaryBaseIterator<EvalIterator, EvalIteratorState>*)this);

  ar & theVarNames;
  ar & theVarTypes;
  SERIALIZE_ENUM(enum expr_script_kind_t, theScriptingKind);
  ar & theLocalBindings;
}


/****************************************************************************//**

********************************************************************************/
bool EvalIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  EvalIteratorState* state;

  DEFAULT_STACK_INIT(EvalIteratorState, state, planState);

  CONSUME(item, 0);

  {
    ulong numEvalVars = theVarNames.size();

    // Create an "outer" sctx and register into it (a) global vars corresponding
    // to the eval vars and (b) the expression-level ns bindings at the place 
    // where the eval call appears at.
    static_context* outerSctx = theSctx->create_child_context();

    for (ulong i = 0; i < numEvalVars; ++i)
    {
      var_expr_t ve = new var_expr(outerSctx,
                                   loc,
                                   var_expr::prolog_var,
                                   theVarNames[i].getp());

      ve->set_type(theVarTypes[i]);

      outerSctx->bind_var(ve, loc, err::XQST0049);
    }

    store::NsBindings::const_iterator ite = theLocalBindings.begin();
    store::NsBindings::const_iterator end = theLocalBindings.end();

    for (; ite != end; ++ite)
    {
      outerSctx->bind_ns(ite->first, ite->second, loc);
    }

    // Create the root sctx for the eval query
    static_context* evalSctx = outerSctx->create_child_context();

    // Create the ccb for the eval query
    CompilerCB* evalCCB = new CompilerCB(*planState.theCompilerCB);
    evalCCB->theIsEval = true;
    evalCCB->theRootSctx = evalSctx;
    (evalCCB->theSctxMap)[1] = evalSctx;

    state->ccb.reset(evalCCB);

    // Create the dynamic context for the eval query
    dynamic_context* evalDctx = new dynamic_context(planState.theGlobalDynCtx);
    state->dctx.reset(evalDctx);

    // Copy the values of outer vars into the evalDctx
    ulong maxOuterVarId;
    copyOuterVariables(planState, outerSctx, evalDctx, maxOuterVarId);

    // Compile
    state->thePlan = compile(evalCCB,
                             item->getStringValue(),
                             maxOuterVarId);

    // Set external vars
    setExternalVariables(evalCCB, outerSctx, evalSctx, evalDctx);

    // Execute
    state->thePlanWrapper = new PlanWrapper(state->thePlan,
                                            evalCCB,
                                            evalDctx,
                                            planState.theQuery,
                                            planState.theStackDepth + 1);

    state->thePlanWrapper->checkDepth(loc);

    state->thePlanWrapper->open();
  }

  while (state->thePlanWrapper->next(result))
  {
    STACK_PUSH(true, state);
  }

  state->thePlanWrapper = NULL;

  STACK_END(state);
}


/****************************************************************************//**
  Copy the values of all the "outer" vars (i.e., global and eval vars) to the 
  evalDctx. Also, compute the max varid of all these vars and pass this max varid
  to the compiler of the eval query so that the varids that will be generated for
  the eval query will not conflict with the varids of the global and eval vars.
********************************************************************************/
void EvalIterator::copyOuterVariables(
    PlanState& planState,
    static_context* outerSctx,
    dynamic_context* evalDctx,
    ulong& maxOuterVarId) const
{
  maxOuterVarId = 1;

  dynamic_context* outerDctx = evalDctx->getParent();

  std::vector<var_expr_t> globalVars;
  outerSctx->get_parent()->getVariables(globalVars, true, true);
  
  FOR_EACH(std::vector<var_expr_t>, ite, globalVars)
  {
    var_expr* globalVar = (*ite).getp();

    ulong globalVarId = globalVar->get_unique_id();

    if (globalVarId > maxOuterVarId)
      maxOuterVarId = globalVarId;

    store::Item_t itemValue;
    store::TempSeq_t seqValue;

    if (!outerDctx->exists_variable(globalVarId))
      continue;

    outerDctx->get_variable(globalVarId,
                            globalVar->get_name(),
                            loc,
                            itemValue,
                            seqValue);

    if (itemValue != NULL)
    {
      evalDctx->add_variable(globalVarId, itemValue);
    }
    else
    {
      store::Iterator_t iteValue = seqValue->getIterator();
      evalDctx->add_variable(globalVarId, iteValue);
    }
  }

  ++maxOuterVarId;

  // For each of the eval vars, place its value into the evalDctx. The var
  // value is represented as a PlanIteratorWrapper over the subplan that
  // evaluates the domain expr of the eval var.
  for (ulong i = 0; i < theChildren.size() - 1; ++i)
  {
    var_expr* evalVar = outerSctx->lookup_var(theVarNames[i],
                                              loc,
                                              zerr::ZXQP0000_NO_ERROR);
    ZORBA_ASSERT(evalVar);

    evalVar->set_unique_id(maxOuterVarId);

    store::Iterator_t iter = new PlanIteratorWrapper(theChildren[i + 1], planState);

    evalDctx->add_variable(maxOuterVarId, iter);

    ++maxOuterVarId;
  }
}


/****************************************************************************//**

********************************************************************************/
void EvalIterator::setExternalVariables(
    CompilerCB* ccb,
    static_context* outerSctx,
    static_context* evalSctx,
    dynamic_context* evalDctx) const
{
  std::vector<var_expr_t> innerVars;

  CompilerCB::SctxMap::const_iterator sctxIte = ccb->theSctxMap.begin();
  CompilerCB::SctxMap::const_iterator sctxEnd = ccb->theSctxMap.end();

  for (; sctxIte != sctxEnd; ++sctxIte)
  {
    sctxIte->second->getVariables(innerVars);
  }

  FOR_EACH(std::vector<var_expr_t>, ite, innerVars)
  {
    var_expr* innerVar = (*ite).getp();

    if (!innerVar->is_external())
      continue;

    ulong innerVarId = innerVar->get_unique_id();

    var_expr* globalVar = outerSctx->lookup_var(innerVar->get_name(),
                                                loc, 
                                                zerr::ZXQP0000_NO_ERROR);

    if (globalVar == NULL)
      continue;

    store::Item_t itemValue;
    store::TempSeq_t seqValue;

    evalDctx->get_variable(globalVar->get_unique_id(),
                           globalVar->get_name(),
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


/****************************************************************************//**

********************************************************************************/
PlanIter_t EvalIterator::compile(
    CompilerCB* ccb,
    const zstring& query,
    ulong maxOuterVarId) const
{
  std::stringstream os;

  XQueryCompiler compiler(ccb);

  os.write(query.data(), (std::streamsize)query.size());

  std::stringstream evalname;
  evalname << "eval@" << loc.getFilename()
           << "-" << loc.getLineBegin()
           << "-" << loc.getColumnBegin();

  audit::Event* ae = ccb->theRootSctx->get_audit_event();
  zorba::audit::ScopedRecord sar(ae);

  std::string lName = evalname.str();
  zorba::audit::StringAuditor filenameAudit(
      sar, zorba::audit::XQUERY_COMPILATION_FILENAME, lName);

  parsenode_t ast;
  {
    zorba::time::Timer lTimer;
    zorba::audit::DurationAuditor durationAudit(
        sar, zorba::audit::XQUERY_COMPILATION_PARSE_DURATION, lTimer);
    ast = compiler.parse(os, lName);
  }

  rchandle<MainModule> mm = ast.dyn_cast<MainModule>();
  if (mm == NULL)
    throw XQUERY_EXCEPTION(err::XPST0003, ERROR_LOC(loc));

  expr_t rootExpr;
  PlanIter_t rootIter = compiler.compile(ast, false, rootExpr, maxOuterVarId, sar);

  return rootIter;
}


NARY_ACCEPT(EvalIterator);


}
/* vim:set et sw=2 ts=2: */
