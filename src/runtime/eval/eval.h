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
 
#ifndef ZORBA_RUNTIME_EVAL_EVAL_H
#define ZORBA_RUNTIME_EVAL_EVAL_H

#include "common/shared_types.h"

#include "compiler/expression/expr_consts.h"

#include "runtime/base/narybase.h"

namespace zorba {


class EvalIteratorState : public PlanIteratorState
{
public:
  PlanIter_t                     thePlan;
  PlanWrapper_t                  thePlanWrapper;
  std::auto_ptr<CompilerCB>      ccb;
  std::auto_ptr<dynamic_context> dctx;

public:
  EvalIteratorState();

  ~EvalIteratorState();
};


/****************************************************************************//**
  The 1st child iterator computes the query string, and the next N child
  iterators compute the value of each of the non-global outer variables
  (see below).

  theVarNames:
  ------------
  The names of all the outer-query vars that are in scope at the place where the
  eval expr appears. These will be "imported" to the prolog of the eval query as
  global external var declarations. From the viewpoint of the eval query, we call
  these vars the "outer vars" of the eval query. If the prolog of the eval query
  declares or imports any variable with the same name as the name of an outer 
  var, then the explicit eval var will hide the implicit outer var. 

  theVarTypes:
  ------------
  The data types of the outer vars.

  theIsGlobalVar:
  ----------------
  For each of the outer vars, this bool vector says whether the var corresponds
  to a global outer-query var. If yes, then its value should appear in the global
  dcx of the outer query, and will be copied from there into the global dctx of
  the inner query (using the same var id as the corresponding outer query var).

  theScriptingKind:
  -----------------

  Tells whether the eval query is going to be sequential, updating, or simple.
 
  theLocalBindings:
  -----------------

  theDoNodeCopy:
  --------------

  theForDebugger:
  ---------------

********************************************************************************/
class EvalIterator : public NaryBaseIterator<EvalIterator, EvalIteratorState>
{ 
protected:
  std::vector<store::Item_t>  theOuterVarNames;

  std::vector<xqtref_t>       theOuterVarTypes;

  std::vector<int>            theIsGlobalVar;

  expr_script_kind_t          theScriptingKind;

  store::NsBindings           theLocalBindings;

  bool                        theDoNodeCopy;

  bool                        theForDebugger;

public:
  SERIALIZABLE_CLASS(EvalIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(EvalIterator,
  NaryBaseIterator<EvalIterator, EvalIteratorState>);
  void serialize(::zorba::serialization::Archiver& ar);

  EvalIterator(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<PlanIter_t>& children,
      const std::vector<store::Item_t>& varNames,
      const std::vector<xqtref_t>& varTypes,
      const std::vector<int>& isGlobalVar,
      expr_script_kind_t scriptingKind,
      const store::NsBindings& localBindings,
      bool doNodeCopy,
      bool forDebugger);

  ~EvalIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const
  {
    return nextORcount(false, result, planState);
  }

  bool count(store::Item_t& result, PlanState& planState) const
  {
    return nextORcount(true, result, planState);
  }

private:
  void importOuterEnv(
      PlanState& planState,
      CompilerCB* evalCCB,
      static_context* importSctx,
      dynamic_context* evalDctx,
      ulong& maxOuterVarId) const;

  void setExternalVariables(
      CompilerCB* ccb,
      static_context* importSctx,
      static_context* evalSctx,
      dynamic_context* evalDctx) const;

  PlanIter_t compile(
      CompilerCB* ccb,
      const zstring& query,
      ulong maxOuterVarId,
      bool doCount) const;

  bool nextORcount(
      bool doCount,
      store::Item_t& result,
      PlanState& planState) const;
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
/* vim:set et sw=2 ts=2: */
