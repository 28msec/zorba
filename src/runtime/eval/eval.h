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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************
#ifndef ZORBA_RUNTIME_EVAL_EVAL_H
#define ZORBA_RUNTIME_EVAL_EVAL_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "runtime/util/plan_wrapper_holder.h"
#include "types/typeimpl.h"


namespace zorba {

/**
 * eval iterator
 * 
 * Author: Zorba Team * 
 */
class EvalIteratorState : public PlanIteratorState
{
public:
  PlanWrapperHolder eval_plan; //the plan to execute
  std::auto_ptr<CompilerCB> ccb; //the CompilerCB used to compile the eval plan
  std::auto_ptr<dynamic_context> dctx; //the dynamic context used to during execution of the eval plan

  EvalIteratorState();

  ~EvalIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class EvalIterator : public NaryBaseIterator <EvalIterator, EvalIteratorState>
{ 
protected:
  checked_vector<store::Item_t> varnames; //
  checked_vector<std::string> var_keys; //
  checked_vector<xqtref_t> vartypes; //
public:
  SERIALIZABLE_CLASS(EvalIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(EvalIterator,
    NaryBaseIterator <EvalIterator, EvalIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator <EvalIterator, EvalIteratorState>*)this);

    ar & varnames;
    ar & var_keys;
    ar & vartypes;
  }

  EvalIterator(
    static_context* sctx,
    const QueryLoc& loc
    , std::vector<PlanIter_t>& aChildren,
    checked_vector<store::Item_t> aVarNames,
    checked_vector<std::string> aVarKeys,
    checked_vector<xqtref_t> aVarTypes)
    : NaryBaseIterator <EvalIterator, EvalIteratorState>
    (sctx, loc, aChildren),
    varnames(aVarNames),
    var_keys(aVarKeys),
    vartypes(aVarTypes) {}

  virtual ~EvalIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
