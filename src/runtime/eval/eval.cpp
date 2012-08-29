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
    const std::vector<store::Item_t>& varNames,
    const std::vector<xqtref_t>& varTypes,
    const std::vector<int>& isGlobalVar,
    expr_script_kind_t scriptingKind,
    const store::NsBindings& localBindings,
    bool doNodeCopy,
    bool forDebugger)
  : 
  NaryBaseIterator<EvalIterator, EvalIteratorState>(sctx, loc, children),
  theOuterVarNames(varNames),
  theOuterVarTypes(varTypes),
  theIsGlobalVar(isGlobalVar),
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

  ar & theOuterVarNames;
  ar & theOuterVarTypes;
  ar & theIsGlobalVar;
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
    // Create the "import" sctx. The importOuterEnv() method (called below) will
    // register into the importSctx (a) the outer vars of the eval query and (b)
    // the expression-level ns bindings of the outer query at the place where
    // the eval call appears at.
    static_context* importSctx = theSctx->create_child_context();

    // Create the root sctx for the eval query
    static_context* evalSctx = importSctx->create_child_context();

    // Create the ccb for the eval query
    CompilerCB* evalCCB = new CompilerCB(*planState.theCompilerCB);
    evalCCB->theIsEval = true;
    evalCCB->theRootSctx = evalSctx;
    evalCCB->theConfig.for_serialization_only = !theDoNodeCopy;
    (evalCCB->theSctxMap)[1] = evalSctx;

    state->ccb.reset(evalCCB);

    // Create the dynamic context for the eval query
    dynamic_context* evalDctx = new dynamic_context(planState.theGlobalDynCtx);
    state->dctx.reset(evalDctx);

    // Import the outer environment.
    std::vector<var_expr_t> outerVars;
    ulong maxOuterVarId;
    importOuterEnv(planState, importSctx, evalDctx, outerVars, maxOuterVarId);

    // If we are here after a reet, we must set state->thePlanWrapper to NULL
    // before reseting the state->thePlan. Otherwise, the current state->thePlan
    // will be destroyed first, and then we will attempt to close it when 
    // state->thePlanWrapper is reset later. 
    state->thePlanWrapper = NULL;

    // Compile
    state->thePlan = compile(evalCCB, item->getStringValue(), maxOuterVarId);

    // Set the values for the (explicit) external vars of the eval query
    setExternalVariables(evalCCB, importSctx, evalSctx, evalDctx);

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
void EvalIterator::importOuterEnv(
    PlanState& planState,
    static_context* importSctx,
    dynamic_context* evalDctx,
    std::vector<var_expr_t>& outerVars,
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

  csize curChild = 0;

  csize numOuterVars = theOuterVarNames.size();

  outerVars.resize(numOuterVars);

  for (csize i = 0; i < numOuterVars; ++i)
  {
    var_expr_t ve = new var_expr(importSctx,
                                 loc,
                                 var_expr::prolog_var,
                                 theOuterVarNames[i].getp());

    ve->set_type(theOuterVarTypes[i]);

    outerVars[i] = ve;

    if (!theIsGlobalVar[i])
    {
      ++curChild;

      store::Iterator_t iter = new PlanIteratorWrapper(theChildren[curChild], planState);

      evalDctx->add_variable(maxOuterVarId, iter);

      ve->set_unique_id(maxOuterVarId);

      ++maxOuterVarId;
    }
    else
    {
      static_context* outerSctx = importSctx->get_parent();

      VarInfo* outerGlobalVar = outerSctx->lookup_var(theOuterVarNames[i]);
      ZORBA_ASSERT(outerGlobalVar);

      ulong outerGlobalVarId = outerGlobalVar->getId();

      ve->set_unique_id(outerGlobalVarId);
    }

    importSctx->bind_var(ve, loc, err::XQST0049);
  }

  // Import the outer-query ns bindings

  store::NsBindings::const_iterator ite = theLocalBindings.begin();
  store::NsBindings::const_iterator end = theLocalBindings.end();

  for (; ite != end; ++ite)
  {
    importSctx->bind_ns(ite->first, ite->second, loc);
  }
}


/****************************************************************************//**

********************************************************************************/
void EvalIterator::setExternalVariables(
    CompilerCB* ccb,
    static_context* importSctx,
    static_context* evalSctx,
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
  {
    RAISE_ERROR(err::XPST0003, loc,
    ERROR_PARAMS(ZED(XPST0003_ModuleDeclNotInMain)));
  }

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
