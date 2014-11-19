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
#pragma once
#ifndef ZORBA_RUNTIME_SEQUENCETYPES
#define ZORBA_RUNTIME_SEQUENCETYPES

#include <zorba/typeident.h>

#include "common/shared_types.h"

#include "runtime/base/unarybase.h"
#include "runtime/base/narybase.h"

#include "types/typeconstants.h"

#include "compiler/expression/expr_consts.h"

#include "context/namespace_context.h"


namespace zorba 
{

/*******************************************************************************
  Implement 3.12.1: Instance Of

  The boolean operator instance of returns true if the value of its first 
  operand matches the SequenceType in its second operand, according to the rules
  for SequenceType matching; otherwise it returns false.
********************************************************************************/
class InstanceOfIterator : public UnaryBaseIterator<InstanceOfIterator,
                                                    PlanIteratorState>
{
private:
  xqtref_t theSequenceType;

public:
  SERIALIZABLE_CLASS(InstanceOfIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  InstanceOfIterator,
  UnaryBaseIterator<InstanceOfIterator, PlanIteratorState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  InstanceOfIterator(
        static_context* sctx,
        const QueryLoc& loc, 
        PlanIter_t& aTreatExpr, 
        xqtref_t aSequenceType);
 
  ~InstanceOfIterator();

  void accept(PlanIterVisitor& v) const;

  zstring getNameAsString() const;
  
  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************
  Implement 3.12.3: Cast

  http://www.w3.org/TR/xquery/#id-cast
********************************************************************************/
class CastIteratorState : public PlanIteratorState
{
public:
  std::vector<store::Item_t> theResultItems;
  csize                      theResultPos;

  void init(PlanState&);
  void reset(PlanState&);
};


class CastIterator : public UnaryBaseIterator<CastIterator, CastIteratorState> 
{
  friend class PrinterVisitor;

private:
  xqtref_t          theCastType;
  bool              theAllowEmpty;

  namespace_context theNsCtx;

public:
  SERIALIZABLE_CLASS(CastIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  CastIterator,
  UnaryBaseIterator<CastIterator, CastIteratorState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  CastIterator(
      static_context* sctx,
      const QueryLoc& loc,
      PlanIter_t& child,
      const xqtref_t& castType,
      bool allowEmpty);
  
  ~CastIterator();

  void accept(PlanIterVisitor& v) const;
  
  zstring getNameAsString() const;
  
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/*******************************************************************************
  Implement 3.12.4: Castable

  http://www.w3.org/TR/xquery/#id-castable
********************************************************************************/
class CastableIterator : public UnaryBaseIterator<CastableIterator,
                                                  PlanIteratorState> 
{
  friend class PrinterVisitor;

private:
  xqtref_t  theCastType;
  bool      theAllowEmpty;

  namespace_context theNsCtx;

public:
  SERIALIZABLE_CLASS(CastableIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  CastableIterator,
  UnaryBaseIterator<CastableIterator, PlanIteratorState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  CastableIterator(
        static_context* sctx,
        const QueryLoc& loc,
        PlanIter_t& child,
        const xqtref_t& castType,
        bool allowEmpty);

  ~CastableIterator();

  void accept(PlanIterVisitor& v) const;

  zstring getNameAsString() const;
  
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/*******************************************************************************
  Iterator which tries to promote an item to the passed target type. If it
  is not possible, a type error is thrown. If the type of the item is a 
  subtype of the target type, then no promotion is done (it's a noop).
********************************************************************************/
class PromoteIterator : public UnaryBaseIterator<PromoteIterator,
                                                 PlanIteratorState> 
{
  friend class PrinterVisitor;

private:
  xqtref_t                   thePromoteType;
  SequenceType::Quantifier   theQuantifier;
  PromoteErrorKind           theErrorKind;
  store::Item_t							 theQName; 
  namespace_context          theNsCtx;

public:
  SERIALIZABLE_CLASS(PromoteIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  PromoteIterator,
  UnaryBaseIterator<PromoteIterator, PlanIteratorState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  PromoteIterator(
      static_context* sctx,
      const QueryLoc& loc,
      PlanIter_t& child,
      const xqtref_t& promoteType,
      PromoteErrorKind err,
      store::Item_t qname = NULL);

  ~PromoteIterator();

  void accept(PlanIterVisitor& v) const;

  zstring getNameAsString() const;
  
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

protected:
  void raiseError(const zstring& valueType) const;
};


/*******************************************************************************
  Iterator which checks if a sequence is an instance of the target type. If not,
  an error is thrown.

  theTreatType  :
  theQuantifier :
  theErrorCode  :
  theFnQName    : Stores the QName of the function, if the treat iterator is 
                  used to check the result type a function.
********************************************************************************/
class TreatIterator : public UnaryBaseIterator<TreatIterator,
                                               PlanIteratorState> 
{
  friend class PrinterVisitor;
  typedef UnaryBaseIterator<TreatIterator,PlanIteratorState> base_type;

private:
  xqtref_t                  theTreatType;
  SequenceType::Quantifier  theQuantifier;
  bool                      theCheckPrime;
  TreatErrorKind            theErrorKind;
  store::Item_t						theQName;

public:
  SERIALIZABLE_CLASS(TreatIterator);
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  TreatIterator,
  UnaryBaseIterator<TreatIterator, PlanIteratorState>);
  void serialize(::zorba::serialization::Archiver& ar);

public:
  TreatIterator(
      static_context* sctx,
      const QueryLoc& loc,
      PlanIter_t& child,
      const xqtref_t& treatType,
      bool check_prime,
      TreatErrorKind errorKind,
      store::Item_t qname);

  void accept(PlanIterVisitor& v) const;

  zstring getNameAsString() const;
  
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  bool countImpl(store::Item_t& result, PlanState& planState) const;
  bool skipImpl(int64_t count, PlanState &planState) const;

protected:
  void raiseError(const zstring& valueType) const;
};


/*******************************************************************************

********************************************************************************/
class EitherNodesOrAtomicsIteratorState : public PlanIteratorState 
{
public:
  bool atomics;
};

NARY_ITER_STATE(EitherNodesOrAtomicsIterator, EitherNodesOrAtomicsIteratorState);


} /* namespace zorba */
#endif
  
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
