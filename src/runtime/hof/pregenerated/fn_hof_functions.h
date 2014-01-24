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
#ifndef ZORBA_RUNTIME_HOF_FN_HOF_FUNCTIONS_H
#define ZORBA_RUNTIME_HOF_FN_HOF_FUNCTIONS_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "compiler/expression/expr_base.h"
#include "runtime/util/plan_wrapper_holder.h"
#include "types/typeimpl.h"
#include "functions/function.h"


namespace zorba {

/**
 * 
 *      Returns the function having a given name and arity, if there is one.
 *  
 * Author: Zorba Team
 */
class FunctionLookupIterator : public NaryBaseIterator<FunctionLookupIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FunctionLookupIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FunctionLookupIterator,
    NaryBaseIterator<FunctionLookupIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FunctionLookupIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FunctionLookupIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FunctionLookupIterator();

  zstring getNameAsString() const;

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

  void serialize( ::zorba::serialization::Archiver& ar);

  FunctionNameIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FunctionNameIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~FunctionNameIterator();

  zstring getNameAsString() const;

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

  zstring getNameAsString() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *      Applies the function item $f to successive pairs of items taken one from $seq1 and one from $seq2, returning the concatenation of the resulting sequences in order.
 *    
 * Author: Zorba Team
 */
class FnForEachPairIteratorState : public PlanIteratorState
{
public:
  PlanState* thePlanState; //
  PlanIter_t thePlan; //
  bool theIsOpen; //
  uint32_t theUDFStateOffset; //
  store::Item_t theFnItem; //

  FnForEachPairIteratorState();

  ~FnForEachPairIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnForEachPairIterator : public NaryBaseIterator<FnForEachPairIterator, FnForEachPairIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(FnForEachPairIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnForEachPairIterator,
    NaryBaseIterator<FnForEachPairIterator, FnForEachPairIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnForEachPairIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<FnForEachPairIterator, FnForEachPairIteratorState>(sctx, loc, children)
  {}

  virtual ~FnForEachPairIterator();

  zstring getNameAsString() const;

  uint32_t getStateSizeOfSubtree() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  void openImpl(PlanState&, uint32_t&);
};


/**
 * 
 *      Processes the supplied sequence from left to right or right to left, applying the supplied function repeatedly to each item in turn, together with an accumulated result value.
 *    
 * Author: Zorba Team
 */
class FnFoldLeftIteratorState : public PlanIteratorState
{
public:
  PlanState* thePlanState; //
  PlanIter_t thePlan; //
  bool theIsOpen; //
  uint32_t theUDFStateOffset; //
  store::Item_t theFnItem; //

  FnFoldLeftIteratorState();

  ~FnFoldLeftIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class FnFoldLeftIterator : public NaryBaseIterator<FnFoldLeftIterator, FnFoldLeftIteratorState>
{ 
protected:
  bool theIsFoldRight; //
public:
  SERIALIZABLE_CLASS(FnFoldLeftIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnFoldLeftIterator,
    NaryBaseIterator<FnFoldLeftIterator, FnFoldLeftIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar);

  FnFoldLeftIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool aIsFoldRight)
    : 
    NaryBaseIterator<FnFoldLeftIterator, FnFoldLeftIteratorState>(sctx, loc, children),
    theIsFoldRight(aIsFoldRight)
  {}

  virtual ~FnFoldLeftIterator();

  zstring getNameAsString() const;

  uint32_t getStateSizeOfSubtree() const;

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  void openImpl(PlanState&, uint32_t&);
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
