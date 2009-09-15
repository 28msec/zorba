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
#ifndef ZORBA_RUNTIME_FN_CONTEXT_IMPL_H
#define ZORBA_RUNTIME_FN_CONTEXT_IMPL_H

#include "common/shared_types.h"

#include "runtime/base/narybase.h"
#include "runtime/util/plan_wrapper_holder.h"

namespace zorba
{

/*******************************************************************************

********************************************************************************/
class EvalIteratorState : public PlanIteratorState 
{
public:
  PlanWrapperHolder eval_plan;
  std::auto_ptr<CompilerCB> ccb;
  std::auto_ptr<dynamic_context> dctx;

  EvalIteratorState();
  ~EvalIteratorState();
};


class EvalIterator : public NaryBaseIterator<EvalIterator, EvalIteratorState> 
{
protected:
  checked_vector<store::Item_t> varnames;
  checked_vector<std::string> var_keys;  
  checked_vector<xqtref_t> vartypes;

public:
  SERIALIZABLE_CLASS(EvalIterator);

  EvalIterator(::zorba::serialization::Archiver &ar);

  void serialize(::zorba::serialization::Archiver &ar);

public:
  EvalIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& aChildren)
    :
    NaryBaseIterator<EvalIterator, EvalIteratorState> (sctx, loc, aChildren)
  {
  }

  EvalIterator(
        static_context* sctx,
        const QueryLoc& loc,
        checked_vector<store::Item_t> varnames_,
        checked_vector<std::string> var_keys_,
        checked_vector<xqtref_t> vartypes_,
        std::vector<PlanIter_t>& aChildren)
    :
    NaryBaseIterator<EvalIterator, EvalIteratorState> (sctx, loc, aChildren),
    varnames (varnames_),
    var_keys (var_keys_),
    vartypes (vartypes_)
  {
  }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  static PlanIter_t compile(
        CompilerCB *ccb,
        xqp_string query, 
        checked_vector<store::Item_t> varnames,
        checked_vector<xqtref_t> vartypes); 
};

}

#endif 
/*
 * Local variables:
 * mode: c++
 * End:
 */
