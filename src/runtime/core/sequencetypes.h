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
#ifndef ZORBA_SEQUENCETYPES_H
#define ZORBA_SEQUENCETYPES_H

#include "zorbaerrors/errors.h"
#include "common/shared_types.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/narybase.h"
#include "runtime/util/iterator_impl.h"
#include "types/typeconstants.h"

namespace zorba 
{

/*******************************************************************************
   All type-related iterators have the same kind of state.
********************************************************************************/
class CommonTypeIteratorState : public PlanIteratorState
{
public: 
  TypeManager* tm;
};


/*******************************************************************************
  Implement 3.12.1: Instance Of

  The boolean operator instance of returns true if the value of its first 
  operand matches the SequenceType in its second operand, according to the rules
  for SequenceType matching; otherwise it returns false.
********************************************************************************/
class InstanceOfIterator : public UnaryBaseIterator<InstanceOfIterator,
                                                    CommonTypeIteratorState>
{
private:
  xqtref_t theSequenceType;

public:
  SERIALIZABLE_CLASS(InstanceOfIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(InstanceOfIterator,
                                   UnaryBaseIterator<InstanceOfIterator,
                                                     CommonTypeIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<InstanceOfIterator, CommonTypeIteratorState>*)this);
    ar & theSequenceType;
  }

public:
  InstanceOfIterator(
        short sctx,
        const QueryLoc& loc, 
        PlanIter_t& aTreatExpr, 
        xqtref_t aSequenceType);
 
  ~InstanceOfIterator();
  
  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************
  Implement 3.12.3: Cast

  http://www.w3.org/TR/xquery/#id-cast
********************************************************************************/
class CastIterator : public UnaryBaseIterator<CastIterator, CommonTypeIteratorState> 
{
  friend class PrinterVisitor;

private:
  xqtref_t                    theCastType;
  TypeConstants::quantifier_t theQuantifier;

public:
  SERIALIZABLE_CLASS(CastIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CastIterator,
                                   UnaryBaseIterator<CastIterator,
                                                     CommonTypeIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<CastIterator, CommonTypeIteratorState>*)this);
    ar & theCastType;
    SERIALIZE_ENUM(TypeConstants::quantifier_t, theQuantifier);
  }

public:
  CastIterator(short sctx,
               const QueryLoc& loc,
               PlanIter_t& aChild,
               const xqtref_t& aCastType);

  ~CastIterator();
  
  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************
  Implement 3.12.4: Castable

  http://www.w3.org/TR/xquery/#id-castable
********************************************************************************/
class CastableIterator : public UnaryBaseIterator<CastableIterator,
                                                  CommonTypeIteratorState> 
{
  friend class PrinterVisitor;

private:
  xqtref_t                    theCastType;
  TypeConstants::quantifier_t theQuantifier;

public:
  SERIALIZABLE_CLASS(CastableIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(CastableIterator,
                                   UnaryBaseIterator<CastableIterator, CommonTypeIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<CastableIterator, CommonTypeIteratorState>*)this);
    ar & theCastType;
    SERIALIZE_ENUM(TypeConstants::quantifier_t, theQuantifier);
  }

public:
  CastableIterator(
        short sctx,
        const QueryLoc& aLoc,
        PlanIter_t& aChild,
        const xqtref_t& aCastType);

  virtual ~CastableIterator();

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************
  Iterator which tries to promote an item to the passed target type. If it
  is not possible, a type error is thrown. If the type of the item is a 
  subtype of the target type, then no promotion is done (it's a noop).
********************************************************************************/
class PromoteIterator : public UnaryBaseIterator<PromoteIterator,
                                                 CommonTypeIteratorState> 
{
  friend class PrinterVisitor;

private:
  xqtref_t                    thePromoteType;
  TypeConstants::quantifier_t theQuantifier;

public:
  SERIALIZABLE_CLASS(PromoteIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(PromoteIterator,
                                   UnaryBaseIterator<PromoteIterator,
                                                     CommonTypeIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<PromoteIterator, CommonTypeIteratorState>*)this);
    ar & thePromoteType;
    SERIALIZE_ENUM(TypeConstants::quantifier_t, theQuantifier);
  }

public:
  PromoteIterator(short sctx, const QueryLoc&, PlanIter_t&, const xqtref_t& aPromoteType);

  virtual ~PromoteIterator();

  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  void accept(PlanIterVisitor&) const;
};


/*******************************************************************************
  Iterator which checks if a sequence is an instance of the target type. If not,
  an error is thrown.
********************************************************************************/
class TreatIterator : public UnaryBaseIterator<TreatIterator,
                                               CommonTypeIteratorState> 
{
  friend class PrinterVisitor;

private:
  xqtref_t theTreatType;
  TypeConstants::quantifier_t theQuantifier;
  bool check_prime;
  XQUERY_ERROR theErrorCode;

public:
  SERIALIZABLE_CLASS(TreatIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(TreatIterator,
                                   UnaryBaseIterator<TreatIterator,
                                                     CommonTypeIteratorState>)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<TreatIterator, CommonTypeIteratorState>*)this);
    ar & theTreatType;
    SERIALIZE_ENUM(TypeConstants::quantifier_t, theQuantifier);
    ar & check_prime;
    SERIALIZE_ENUM(XQUERY_ERROR, theErrorCode);
  }

public:
  TreatIterator(
        short sctx,
        const QueryLoc&,
        PlanIter_t& aChild,
        const xqtref_t& aTreatType,
        bool check_prime,
        XQUERY_ERROR);
  
  void openImpl(PlanState& planState, uint32_t& offset);

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;

  void accept(PlanIterVisitor&) const;
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
#endif  /* ZORBA_SEQUENCETYPES_H */
  
/*
 * Local variables:
 * mode: c++
 * End:
 */
