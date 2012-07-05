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

#include "diagnostics/util_macros.h"


namespace zorba {


SERIALIZABLE_CLASS_VERSIONS(EvalIterator)


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
    const store::NsBindings& localBindings,
    bool doNodeCopy,
    bool forDebugger)
  :
  NaryBaseIterator<EvalIterator, EvalIteratorState>(sctx, loc, children),
  theVarNames(aVarNames),
  theVarTypes(aVarTypes),
  theScriptingKind(scriptingKind),
  theLocalBindings(localBindings),
  theDoNodeCopy(doNodeCopy),
  theForDebugger(forDebugger)
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
  ar & theDoNodeCopy;
  ar & theForDebugger;
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
    csize numEvalVars = theVarNames.size();

    // Create the ccb for the eval query
    CompilerCB* evalCCB = new CompilerCB(*planState.theCompilerCB);
    evalCCB->theIsEval = true;
    evalCCB->theConfig.for_serialization_only = !theDoNodeCopy;
    state->ccb.reset(evalCCB);

    // Create an "outer" sctx and register into it (a) global vars corresponding
    // to the eval vars and (b) the expression-level ns bindings at the place
    // where the eval call appears at.
    static_context* outerSctx = theSctx->create_child_context();

    for (csize i = 0; i < numEvalVars; ++i)
    {
      var_expr_t ve = 
      state->ccb->getExprManager().create_var_expr(outerSctx,
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

    evalCCB->theRootSctx = evalSctx;
    (evalCCB->theSctxMap)[1] = evalSctx;

    // Create the dynamic context for the eval query
    dynamic_context* evalDctx = new dynamic_context(planState.theGlobalDynCtx);
    state->dctx.reset(evalDctx);

    // Copy the values of outer vars into the evalDctx
    ulong maxOuterVarId;
    copyOuterVariables(planState, outerSctx, evalDctx, maxOuterVarId);

    // If we are here after a reset, we must set state->thePlanWrapper to NULL
    // before reseting the state->thePlan. Otherwise, the current state->thePlan
    // will be destroyed first, and then we will attempt to close it when
    // state->thePlanWrapper is reset later.
    state->thePlanWrapper = NULL;

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
                                            planState.theStackDepth + 1,
                                            state->ccb->theHaveTimeout,
                                            state->ccb->theTimeout);

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

  const std::vector<dynamic_context::VarValue>& outerVars = outerDctx->get_variables();
  csize numOuterVars = outerVars.size();

  for (csize i = 0; i < numOuterVars; ++i)
  {
    const dynamic_context::VarValue& outerVar = outerVars[i];

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

  // For each of the eval vars, place its value into the evalDctx. The var
  // value is represented as a PlanIteratorWrapper over the subplan that
  // evaluates the domain expr of the eval var.
  for (csize i = 0; i < theChildren.size() - 1; ++i)
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
    sctxIte->second->getVariables(innerVars, true, false, true);
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

  audit::StringAuditor filenameAudit(sar, audit::XQUERY_COMPILATION_FILENAME, lName);

  parsenode_t ast;

  {
    time::Timer lTimer;
    audit::DurationAuditor durationAudit(sar,
                                         audit::XQUERY_COMPILATION_PARSE_DURATION,
                                         lTimer);

    ast = compiler.parse(os, lName);
  }

  rchandle<MainModule> mm = ast.dyn_cast<MainModule>();
  if (mm == NULL)
    throw XQUERY_EXCEPTION(err::XPST0003, ERROR_LOC(loc));

  expr_t rootExpr;
  PlanIter_t rootIter = compiler.compile(ast,
                                         false, // do not apply PUL
                                         rootExpr,
                                         maxOuterVarId,
                                         sar);
  if (theScriptingKind == SIMPLE_EXPR)
  {
    if (ccb->isSequential())
    {
      RAISE_ERROR(zerr::XSST0004, loc, ERROR_PARAMS("eval"));
    }
    else if (ccb->isUpdating())
    {
      RAISE_ERROR(err::XUST0001, loc, ERROR_PARAMS(ZED(XUST0001_UDF_2), "eval"));
    }
  }
  else if (theScriptingKind == UPDATING_EXPR)
  {
    if (ccb->isSequential())
    {
      RAISE_ERROR(zerr::XSST0003, loc, ERROR_PARAMS("eval_u"));
    }
  }
  else // sequential
  {
    if (ccb->isUpdating() && !theForDebugger)
    {
      RAISE_ERROR(zerr::XSST0002, loc, ERROR_PARAMS("eval_s"));
    }
  }

  return rootIter;
}


NARY_ACCEPT(EvalIterator);


}
/* vim:set et sw=2 ts=2: */
