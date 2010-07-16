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
 #include "runtime/eval/eval.h"

#include <sstream>

#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/util/iterator_impl.h"

#include "compiler/parsetree/parsenodes.h"
#include "compiler/api/compilercb.h"
#include "compiler/api/compiler_api.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"


namespace zorba {

static PlanIter_t compile(
    CompilerCB* ccb,
    xqp_string query,
    checked_vector<store::Item_t> varnames,
    checked_vector<xqtref_t> vartypes)
{
  XQueryCompiler compiler(ccb);
  std::istringstream os(query);
  xqpStringStore_t dummyname = new xqpStringStore("");
  parsenode_t ast = compiler.parse(os, dummyname);
  QueryLoc loc;

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

  for (int i = (int) varnames.size() - 1; i >= 0; i--)
  {
    vfo->push_front(new VarDecl(loc,
                                new QName(loc, varnames[i]->getStringValue()->str()),
                                NULL,
                                NULL,
                                true));
  }
  // TODO: give eval'ed code the types of the variables (for optimization)

  return compiler.compile(ast);
}

void EvalIterator::serialize(::zorba::serialization::Archiver& ar)
{
  ar.set_serialize_everything();
  serialize_baseclass(ar,
  (NaryBaseIterator<EvalIterator, EvalIteratorState>*)this);

  ar & varnames;
  ar & var_keys;
  ar & vartypes;
}


bool EvalIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  short sctxid;
  EvalIteratorState* state;

  DEFAULT_STACK_INIT(EvalIteratorState, state, planState);

  CONSUME(item, 0);

  {
    // set up eval state's ccb
    state->ccb.reset(new CompilerCB(*planState.theCompilerCB));
    state->ccb->theRootSctx = getStaticContext()->create_child_context();
    sctxid = state->ccb->theSctxMap->size() + 1;
    (*planState.theCompilerCB->theSctxMap)[sctxid] = state->ccb->theRootSctx;
    state->dctx.reset(new dynamic_context(planState.dctx()));

    state->eval_plan.reset(new PlanWrapper(compile(state->ccb.get(),
                                                   &*item->getStringValue(),
                                                   varnames,
                                                   vartypes),
                                           state->ccb.get(),
                                           state->dctx.get(),
                                           planState.theQuery, // HACK/TODO: use the right query (static or dynamic context)
                                           planState.theStackDepth + 1));

    state->eval_plan->checkDepth(loc);

    for (unsigned i = 0; i < theChildren.size() - 1; i++)
    {
      store::Iterator_t lIter = new PlanIteratorWrapper(theChildren[i + 1], planState);
      // TODO: is saving an open iterator efficient?
      // Then again if we close theChildren [1] here,
      // we won't be able to re-open it later via the PlanIteratorWrapper
      state->dctx->add_variable(dynamic_context::var_key(state->ccb->theRootSctx->lookup_var(varnames[i], loc, XPST0008)), lIter);
    }
  }

  while (state->eval_plan->next(result))
  {
    STACK_PUSH(true, state);
  }

  state->eval_plan.reset(NULL);

  STACK_END(state);
}
}
