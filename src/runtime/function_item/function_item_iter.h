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
#ifndef ZORBA_RUNTIME_FUNCTION_ITEM_FUNCTION_ITEM_ITER_H
#define ZORBA_RUNTIME_FUNCTION_ITEM_FUNCTION_ITEM_ITER_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "compiler/expression/expr_base.h"
#include "runtime/util/plan_wrapper_holder.h"
#include "types/typeimpl.h"
#include "functions/function.h"


namespace zorba {

/**
 * TODO: notes from the spec
 * Author: Zorba Team
 */
class DynamicFunctionInvocationIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t thePlan; //the plan to execute
  std::auto_ptr<CompilerCB> ccb; //the CompilerCB used to compile the plan
  std::auto_ptr<dynamic_context> dctx; //the dynamic context used to during execution of the plan

  DynamicFunctionInvocationIteratorState();

  ~DynamicFunctionInvocationIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class DynamicFunctionInvocationIterator : public NaryBaseIterator<DynamicFunctionInvocationIterator, DynamicFunctionInvocationIteratorState>
{ 
protected:
  checked_vector<PlanIter_t> theArgs; //
public:
  SERIALIZABLE_CLASS(DynamicFunctionInvocationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DynamicFunctionInvocationIterator,
    NaryBaseIterator<DynamicFunctionInvocationIterator, DynamicFunctionInvocationIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<DynamicFunctionInvocationIterator, DynamicFunctionInvocationIteratorState>*)this);

    ar & theArgs;
  }

  DynamicFunctionInvocationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    checked_vector<PlanIter_t> args)
    : 
    NaryBaseIterator<DynamicFunctionInvocationIterator, DynamicFunctionInvocationIteratorState>(sctx, loc, children),
    theArgs(args)
  {}

  virtual ~DynamicFunctionInvocationIterator();

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
