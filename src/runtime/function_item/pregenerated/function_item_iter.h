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
 *      Applies the function item $f to successive pairs of items taken one from $seq1 and one from $seq2, returning the concatenation of the resulting sequences in order.
 *    
 * Author: Zorba Team
 */
class FnMapPairsState : public PlanIteratorState
{
public:
  PlanState* thePlanState; //
  PlanIter_t thePlan; //
  bool theIsOpen; //
  uint32_t theUDFStateOffset; //

  FnMapPairsState();

  ~FnMapPairsState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnMapPairs : public NaryBaseIterator<FnMapPairs, FnMapPairsState>
{ 
public:
  SERIALIZABLE_CLASS(FnMapPairs);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnMapPairs,
    NaryBaseIterator<FnMapPairs, FnMapPairsState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnMapPairs(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnMapPairs, FnMapPairsState>(sctx, loc, children)
  {}

  virtual ~FnMapPairs();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      Processes the supplied sequence from left to right or right to left, applying the supplied function repeatedly to each item in turn, together with an accumulated result value.
 *    
 * Author: Zorba Team
 */
class FnFoldLeft : public NaryBaseIterator<FnFoldLeft, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnFoldLeft);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnFoldLeft,
    NaryBaseIterator<FnFoldLeft, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnFoldLeft(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnFoldLeft, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FnFoldLeft();

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
