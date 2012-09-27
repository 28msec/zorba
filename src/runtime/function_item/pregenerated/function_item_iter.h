/*
 * Copyright 2006-2012 The FLWOR Foundation.
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

  void serialize( ::zorba::serialization::Archiver& ar);

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

  void serialize( ::zorba::serialization::Archiver& ar);

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


/**
 * 
 *      Returns the new function item obtained by binding one of the arguments of a supplied function item to a value.
 *      That is, it curries the supplied function.
 *    
 * Author: Zorba Team
 */
class PartialApplyIterator : public NaryBaseIterator<PartialApplyIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(PartialApplyIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(PartialApplyIterator,
    NaryBaseIterator<PartialApplyIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  PartialApplyIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<PartialApplyIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~PartialApplyIterator();

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
