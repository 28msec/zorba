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
 * 
 *     A dynamic function invocation invokes a function item, calling the function it
 *     represents. A dynamic function invocation consists of an expression that returns
 *     the function item and a parenthesized list of zero or more arguments.
 *    
 * Author: Zorba Team
 */
class DynamicFunctionInvocationIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t thePlan; //the plan to execute
  bool theIsOpen; //flag indicating whether thePlan has been opened

  DynamicFunctionInvocationIteratorState();

  ~DynamicFunctionInvocationIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class DynamicFunctionInvocationIterator : public NaryBaseIterator<DynamicFunctionInvocationIterator, DynamicFunctionInvocationIteratorState>
{ 
protected:
  std::vector<PlanIter_t> theFunctionArgs; //
public:
  SERIALIZABLE_CLASS(DynamicFunctionInvocationIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(DynamicFunctionInvocationIterator,
    NaryBaseIterator<DynamicFunctionInvocationIterator, DynamicFunctionInvocationIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<DynamicFunctionInvocationIterator, DynamicFunctionInvocationIteratorState>*)this);

    ar & theFunctionArgs;
  }

  DynamicFunctionInvocationIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    checked_vector<PlanIter_t> args)
    : 
    NaryBaseIterator<DynamicFunctionInvocationIterator, DynamicFunctionInvocationIteratorState>(sctx, loc, children),
    theFunctionArgs(args)
  {}

  virtual ~DynamicFunctionInvocationIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      Returns the name of the function identified by a function item.
 *    
 * Author: Zorba Team
 */
class FunctionNameIterator : public NaryBaseIterator<FunctionNameIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FunctionNameIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FunctionNameIterator,
    NaryBaseIterator<FunctionNameIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FunctionNameIterator, PlanIteratorState>*)this);
  }

  FunctionNameIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FunctionNameIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FunctionNameIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      Returns the arity of the function identified by a function item.
 *    
 * Author: Zorba Team
 */
class FunctionArityIterator : public NaryBaseIterator<FunctionArityIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FunctionArityIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FunctionArityIterator,
    NaryBaseIterator<FunctionArityIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FunctionArityIterator, PlanIteratorState>*)this);
  }

  FunctionArityIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FunctionArityIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FunctionArityIterator();

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
