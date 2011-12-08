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

  EvalIteratorState();

  ~EvalIteratorState();
};


/****************************************************************************//**
  The 1st child iterator computes the query string, and the next N child
  iterators compute the domain expression of each of the "using" variables.

  theVarNames : The names of the "using" vars. These will be added to the prolog
                of the eval query as external var declarations. An error will be
                raised if the prolog of the eval query declares or imports any 
                variable with the same name as the name of a "using" variable.
  theVarTypes : The data types of the "using" vars.
********************************************************************************/
class EvalIterator : public NaryBaseIterator<EvalIterator, EvalIteratorState>
{ 
protected:
  std::vector<store::Item_t>  theVarNames;
  std::vector<xqtref_t>       theVarTypes;
  expr_script_kind_t          theScriptingKind;
  store::NsBindings           theLocalBindings;
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
      const std::vector<store::Item_t>& aVarNames,
      const std::vector<xqtref_t>& aVarTypes,
      expr_script_kind_t scriptingKind,
      const store::NsBindings& localBindings,
      bool forDebugger);

  ~EvalIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

private:
  void copyOuterVariables(
      PlanState& planState,
      static_context* outerSctx,
      dynamic_context* evalDctx,
      ulong& maxOuterVarId) const;

void setExternalVariables(
      CompilerCB* ccb,
      static_context* outerSctx,
      static_context* evalSctx,
      dynamic_context* evalDctx) const;

  PlanIter_t compile(
      CompilerCB* ccb,
      const zstring& query,
      ulong maxOuterVarId) const;
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
/* vim:set et sw=2 ts=2: */
