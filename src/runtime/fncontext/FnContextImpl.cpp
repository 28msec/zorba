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
#include "compiler/api/compiler_api.h"
#include "compiler/parsetree/parsenodes.h"

#include "runtime/fncontext/FnContextImpl.h"
#include "runtime/core/item_iterator.h"
#include "runtime/api/runtimecb.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/util/iterator_impl.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "types/typeimpl.h"

#include "store/api/store.h"
#include "store/api/iterator.h"
#include "store/api/temp_seq.h"

#include "system/globalenv.h"

using namespace std;

namespace zorba
{

store::Item_t CtxVariableIterator::nextImpl(PlanState& planState) const
{
  store::Item_t item, varName;
  xqpStringStore dot (".");
  
  CtxVariableIteratorState* state;
  DEFAULT_STACK_INIT(CtxVariableIteratorState, state, planState);

  varName = CONSUME (0);

	if(varName->getStringValue ()->equals (&dot)) {  // looking for context item?
    item = planState.theRuntimeCB->theDynamicContext->context_item();
		if(item == NULL)
			ZORBA_ERROR_LOC_PARAM( ZorbaError::XPDY0002, loc, "context item", "");
		STACK_PUSH( item, state);
	} else {
    state->theIter = planState.theRuntimeCB->theDynamicContext->
                     get_variable(varName);

    if (state->theIter == NULL)
			ZORBA_ERROR_LOC_PARAM( ZorbaError::XPDY0002, loc, varName->getStringValue (), "");

    state->theIter->open();

    while ( (item = state->theIter->next()) != NULL )
			STACK_PUSH (item, state);

    state->theIter->close();
	}

  STACK_END (state);
}

  static PlanIter_t compile (XQueryCompiler &compiler, xqp_string query, checked_vector<store::Item_t> varnames, checked_vector<xqtref_t> vartypes) {
    istringstream os (query);
    parsenode_t ast = compiler.parse (os);
    QueryLoc loc;

    rchandle<MainModule> mm = ast.dyn_cast<MainModule> ();
    assert (mm != NULL);
    rchandle<Prolog> prolog = mm->get_prolog ();
    if (prolog == NULL) {
      prolog = new Prolog (loc, NULL, NULL);
      mm->set_prolog (prolog);
    }
    rchandle<VFO_DeclList> vfo = prolog->get_vfo_list ();
    if (vfo == NULL) {
      vfo = new VFO_DeclList (loc);
      prolog->set_vfo_list (vfo);
    }

    for (int i = (int) varnames.size () - 1; i >= 0; i--)
      vfo->push_front (new VarDecl (loc, xqp_string (varnames [i]->getStringValue ().getp()),
                                    NULL, NULL));
    // TODO: give eval'ed code the types of the variables (for optimization)

    return compiler.compile (ast);
  }

store::Item_t EvalIterator::nextImpl(PlanState& planState) const {
  store::Item_t item;
  CompilerCB *ccb = new CompilerCB (*planState.theCompilerCB);
  XQueryCompiler compiler (ccb);
  auto_ptr<dynamic_context> dctx (new dynamic_context (planState.dctx ()));

  EvalIteratorState* state;
  DEFAULT_STACK_INIT(EvalIteratorState, state, planState);

  state->ccb.reset (ccb);
  ccb->m_sctx = ccb->m_sctx->create_child_context ();
  item = CONSUME (0);
  state->eval_plan.reset (new PlanWrapper (compile (compiler, &*item->getStringValue (), varnames, vartypes), ccb, dctx.get ()));

  for (unsigned i = 0; i < theChildren.size () - 1; i++) {
    store::Iterator_t lIter = new PlanIteratorWrapper (theChildren [i + 1], planState);
    // TODO: is saving an open iterator efficient?
    // Then again if we close theChildren [1] here,
    // we won't be able to re-open it later via the PlanIteratorWrapper
    dctx->add_variable (ccb->m_sctx->qname_internal_key (varnames [i]),
                        lIter);
  }

  while (NULL != (item = state->eval_plan->next ())) {
    STACK_PUSH (item, state);
  }

  STACK_END (state);
}

store::Item_t CtxVarAssignIterator::nextImpl(PlanState& planState) const
{
  store::Item_t varName;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  varName = CONSUME (0);

  planState.theRuntimeCB->theDynamicContext->add_variable (static_context::qname_internal_key (varName),
                                                           new PlanIteratorWrapper (theChildren [1], planState));

  STACK_END (state);
}

}
