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
#ifndef ZORBA_NUMERICS_IMPL_H
#define ZORBA_NUMERICS_IMPL_H

#include "common/shared_types.h"
#include "runtime/base/noarybase.h" // TODO remove after iterator refactoring
#include "runtime/base/unarybase.h" // TODO remove after iterator refactoring
#include "runtime/base/binarybase.h" // TODO remove after iterator refactoring
#include "runtime/base/narybase.h"

namespace zorba
{
  class RuntimeCB;

/*******************************************************************************
  Template iterator for arithmetic operations (+, -, *, div, idiv, and mod)
  among numeric and/or untypedAtomic types. The class that implements the
  specific operation is passed as the template parameter (these classes are
  defined in runtime/core/arithmetic_impl.h). 

  The iterator can handle operands with any valid combination of numeric and/or
  untypedAtomic data types. 
********************************************************************************/
template < class Operation >
class NumArithIterator : public BinaryBaseIterator<NumArithIterator<Operation>,
                                                   PlanIteratorState>
{
public:
  static bool
  compute(
        store::Item_t& result,
        RuntimeCB* aRuntimeCB,
        const TypeManager* tm,
        const QueryLoc& loc,
        store::Item_t& item0,
        store::Item_t& item1);
      
  static bool
  computeAtomic(
        store::Item_t& result,
        RuntimeCB* aRuntimeCB,
        const TypeManager* tm,
        const QueryLoc&,
        store::Item_t& item0,
        xqtref_t type0,
        store::Item_t& item1,
        xqtref_t type1);

public:
  NumArithIterator(short sctx, const QueryLoc&, PlanIter_t&, PlanIter_t&);

  virtual ~NumArithIterator(){}

  bool nextImpl(store::Item_t& result, PlanState&) const;
      
  virtual void accept(PlanIterVisitor&) const;

public:
  SERIALIZABLE_TEMPLATE_CLASS(NumArithIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(NumArithIterator, BinaryBaseIterator<NumArithIterator<Operation>,PlanIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (BinaryBaseIterator<NumArithIterator<Operation>,PlanIteratorState>*)this);
  }
};


/*******************************************************************************
  Template iterator for numeric arithmetic operations (+, -, *, div, idiv, and
  mod) between operands of a specific data type. The class that implements the
  specific operation is passed as the template class param, and the data type
  of the operands is passed as a template const param.
********************************************************************************/
template < class Operation, TypeConstants::atomic_type_code_t Type >
class SpecificNumArithIterator : 
public BinaryBaseIterator<SpecificNumArithIterator<Operation, Type>, PlanIteratorState>
{
public:
  static bool
  compute(
        store::Item_t& result,
        RuntimeCB* aRuntimeCB,
        const TypeManager* tm,
        const QueryLoc& loc,
        store::Item *item0,
        store::Item *item1);

public:
  SpecificNumArithIterator(short sctx, const QueryLoc&, PlanIter_t&, PlanIter_t&);

  virtual ~SpecificNumArithIterator() {}

  bool nextImpl(store::Item_t& result, PlanState&) const;
      
  virtual void accept(PlanIterVisitor&) const;

public:
  SERIALIZABLE_TEMPLATE_CLASS(SpecificNumArithIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR3T(SpecificNumArithIterator, BinaryBaseIterator<SpecificNumArithIterator<Operation, Type>, PlanIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (BinaryBaseIterator<SpecificNumArithIterator<Operation, Type>, PlanIteratorState>*)this);
  }
};



// 6.2.7 op:numeric-unary-plus
// ---------------------------

// 6.2.8 op:numeric-unary-minus
// ----------------------------
class OpNumericUnaryIterator : public UnaryBaseIterator<OpNumericUnaryIterator,
                                                        PlanIteratorState>
{
private:
  bool thePlus;

public:
  SERIALIZABLE_CLASS(OpNumericUnaryIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(OpNumericUnaryIterator, UnaryBaseIterator<OpNumericUnaryIterator, PlanIteratorState>)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (UnaryBaseIterator<OpNumericUnaryIterator, PlanIteratorState>*)this);
    ar & thePlus;
  }

public:
  OpNumericUnaryIterator(short sctx, const QueryLoc&, PlanIter_t& aChild, bool aPlus);

  virtual ~OpNumericUnaryIterator();
  
  bool nextImpl(store::Item_t& result, PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};



  /*______________________________________________________________________
  |
  | 6.3 Comparison Operators on Numeric Values
  |_______________________________________________________________________*/

// 6.3.1 op:numeric-equal
// -------------------------


// 6.3.2 op:numeric-less-than
// 6.3.3 op:numeric-greater-than


  /*______________________________________________________________________
  |
  | 6.4 Functions on Numeric Values
  |_______________________________________________________________________*/

// 6.4.1 fn:abs
  NARY_ITER(FnAbsIterator);

// 6.4.2 fn:ceiling
  NARY_ITER(FnCeilingIterator);

// 6.4.3 fn:floor
  NARY_ITER(FnFloorIterator);
  
// 6.4.4 fn:round   
  NARY_ITER(FnRoundIterator);
  
// 6.4.5 fn:round-half-to-even
  NARY_ITER(FnRoundHalfToEvenIterator);


class ZorNumGenState : public PlanIteratorState
{
private:
  int32_t curNumber;
public:
  void init(PlanState&);
  void reset(PlanState&);
  
  int32_t getCurNumber();
  void setCurNumber(int32_t);
};
  

/**
 * Helper Iterator to produce a defined amount of integer items
 */
class ZorNumGen : public NoaryBaseIterator<ZorNumGen, ZorNumGenState> 
{
public:
  ZorNumGen ( short sctx, const QueryLoc& loc);
  ~ZorNumGen();
  
  bool nextImpl(store::Item_t& result, PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
public:
  SERIALIZABLE_CLASS(ZorNumGen)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(ZorNumGen, NoaryBaseIterator<ZorNumGen, ZorNumGenState> )
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (NoaryBaseIterator<ZorNumGen, ZorNumGenState> *)this);
  }
};
  
  
NARY_ITER (FnSQRTIterator);

NARY_ITER (FnExpIterator);
NARY_ITER (FnLogIterator);
NARY_ITER (FnSinIterator);
NARY_ITER (FnCosIterator);
NARY_ITER (FnTanIterator);
NARY_ITER (FnArcSinIterator);
NARY_ITER (FnArcCosIterator);
NARY_ITER (FnArcTanIterator);


/*______________________________________________________________________
|
| XQuery 1.1 functions
|_______________________________________________________________________*/
class FnFormatNumberIterator: public NaryBaseIterator<FnFormatNumberIterator, PlanIteratorState >
{
public:
  FnFormatNumberIterator( short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& aChildren)
    :
    NaryBaseIterator<FnFormatNumberIterator, PlanIteratorState >(sctx, loc, aChildren)
  {}

public:
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
  public:
    SERIALIZABLE_CLASS(FnFormatNumberIterator)
    SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnFormatNumberIterator, NaryBaseIterator<FnFormatNumberIterator, PlanIteratorState > )
    void serialize(::zorba::serialization::Archiver &ar)
    {
      serialize_baseclass(ar, (NaryBaseIterator<FnFormatNumberIterator, PlanIteratorState > *)this);
    }
};


} /* namespace zorba */
#endif  /* ZORBA_NUMERICS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
