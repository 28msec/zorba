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


namespace zorba {


SERIALIZABLE_CLASS_VERSIONS(EvalIterator)
END_SERIALIZABLE_CLASS_VERSIONS(EvalIterator)


/****************************************************************************//**

********************************************************************************/
static PlanIter_t compile(
    CompilerCB* ccb,
    dynamic_context* evalDctx,
    zstring query,
    std::vector<store::Item_t> varnames,
    std::vector<xqtref_t> vartypes)
{
  QueryLoc loc;
  XQueryCompiler compiler(ccb);
  std::stringstream os;

  os.write(query.data(), (std::streamsize)query.size());

  zstring dummyname;
  parsenode_t ast = compiler.parse(os, dummyname);

  rchandle<MainModule> mm = ast.dyn_cast<MainModule>();
  if (mm == NULL)
    ZORBA_ERROR_LOC(XPST0003, loc);

  rchandle<Prolog> prolog = mm->get_prolog();
  if (prolog == NULL)
  {
    prolog = new Prolog(loc, NULL, NULL);
    mm->set_prolog(prolog);
  }

  rchandle<VFO_DeclList> vfo = prolog->get_vfo_list();
  if (vfo == NULL)
  {
    vfo = new VFO_DeclList(loc);
    prolog->set_vfo_list(vfo);
  }

  for (long i = (long)varnames.size() - 1; i >= 0; --i)
  {
    vfo->push_front(new VarDecl(loc,
                                new QName(loc, varnames[i]->getStringValue().str()),
                                NULL,
                                NULL,
                                NULL,
                                true));
  }

  // TODO: give eval'ed code the types of the variables (for optimization)

  static_context* outerSctx = ccb->theRootSctx->get_parent();
  dynamic_context* outerDctx = evalDctx->getParent();

  ulong maxOuterVarId = 0;
  std::vector<var_expr_t> outerVars;
  outerSctx->getVariables(outerVars);
  
  FOR_EACH(std::vector<var_expr_t>, ite, outerVars)
  {
    var_expr* outerVar = (*ite).getp();

    ulong outerVarId = outerVar->get_unique_id();

    if (outerVarId > maxOuterVarId)
      maxOuterVarId = outerVarId;

    store::Item_t itemValue;
    store::TempSeq_t seqValue;

    if (!outerDctx->exists_variable(outerVarId))
      continue;

    outerDctx->get_variable(outerVarId,
                            outerVar->get_name(),
                            QueryLoc::null,
                            itemValue,
                            seqValue);

    if (itemValue != NULL)
    {
      evalDctx->add_variable(outerVarId, itemValue);
    }
    else
    {
      store::Iterator_t iteValue = seqValue->getIterator();
      evalDctx->add_variable(outerVarId, iteValue);
    }
  }

  ++maxOuterVarId;

  return compiler.compile(ast, maxOuterVarId);
}


/****************************************************************************//**

********************************************************************************/
static void setEvalVariable(
    const static_context* evalSctx,
    dynamic_context* evalDctx,
    const store::Item_t& varName,
    store::Iterator_t& value)
{
  const var_expr* evalVar = evalSctx->lookup_var(varName,
                                                 QueryLoc::null,
                                                 MAX_ZORBA_ERROR_CODE);
    
  if (!evalVar)
  {
    ZORBA_ASSERT(false);
  }

  ulong varId = evalVar->get_unique_id();

  evalDctx->add_variable(varId, value);
}


EvalIteratorState::EvalIteratorState() 
{
}


EvalIteratorState::~EvalIteratorState() 
{
}


EvalIterator::EvalIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    const std::vector<store::Item_t>& aVarNames,
    const std::vector<xqtref_t>& aVarTypes)
  : 
  NaryBaseIterator<EvalIterator, EvalIteratorState>(sctx, loc, children),
  theVarNames(aVarNames),
  theVarTypes(aVarTypes)
{
}


EvalIterator::~EvalIterator() 
{
}


void EvalIterator::serialize(::zorba::serialization::Archiver& ar)
{
  ar.set_serialize_everything();
  serialize_baseclass(ar,
  (NaryBaseIterator<EvalIterator, EvalIteratorState>*)this);

  ar & theVarNames;
  ar & theVarTypes;
}


bool EvalIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  EvalIteratorState* state;

  DEFAULT_STACK_INIT(EvalIteratorState, state, planState);

  CONSUME(item, 0);

  {
    // set up eval state's ccb
    CompilerCB* evalCcb = new CompilerCB(*planState.theCompilerCB);
    state->ccb.reset(evalCcb);
    static_context* evalSctx = getStaticContext()->create_child_context();
    evalCcb->theRootSctx = evalSctx;
    (evalCcb->theSctxMap)[1] = evalSctx;

    dynamic_context* evalDctx = new dynamic_context(planState.theGlobalDynCtx);
    state->dctx.reset(evalDctx);

    state->thePlan = compile(evalCcb,
                             evalDctx,
                             item->getStringValue(),
                             theVarNames,
                             theVarTypes);

    state->thePlanWrapper = new PlanWrapper(state->thePlan,
                                            evalCcb,
                                            evalDctx,
                                            planState.theQuery, // HACK/TODO: use the right query (static or dynamic context)
                                            planState.theStackDepth + 1);

    state->thePlanWrapper->checkDepth(loc);

    state->thePlanWrapper->open();

    for (unsigned i = 0; i < theChildren.size() - 1; ++i)
    {
      store::Iterator_t lIter = new PlanIteratorWrapper(theChildren[i + 1], planState);
      // TODO: is saving an open iterator efficient?
      // Then again if we close theChildren [1] here,
      // we won't be able to re-open it later via the PlanIteratorWrapper

      setEvalVariable(evalCcb->theRootSctx, evalDctx, theVarNames[i], lIter);
    }
  }

  while (state->thePlanWrapper->next(result))
  {
    STACK_PUSH(true, state);
  }

  state->thePlanWrapper = NULL;

  STACK_END(state);
}


NARY_ACCEPT(EvalIterator);


}
