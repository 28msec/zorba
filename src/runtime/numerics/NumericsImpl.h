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
#ifndef ZORBA_RUNTIME_NUMERICS
#define ZORBA_RUNTIME_NUMERICS

#include "common/shared_types.h"

#include "runtime/base/unarybase.h" // TODO remove after iterator refactoring
#include "runtime/base/binarybase.h" // TODO remove after iterator refactoring
#include "runtime/base/narybase.h"

//#include "store/api/xs_type_codes.h"
#include <zorba/store_consts.h>

namespace zorba
{

class dynamic_context;


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
        dynamic_context* dctx,
        const TypeManager* tm,
        const QueryLoc& loc,
        store::Item_t& item0,
        store::Item_t& item1);
      
  static bool
  computeAtomic(
        store::Item_t& result,
        dynamic_context* dctx,
        const TypeManager* tm,
        const QueryLoc&,
        store::Item_t& item0,
        xqtref_t type0,
        store::Item_t& item1,
        xqtref_t type1);

public:
  NumArithIterator(static_context* sctx, const QueryLoc&, PlanIter_t&, PlanIter_t&);

  virtual ~NumArithIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState&) const;
      
public:
  SERIALIZABLE_TEMPLATE_CLASS(NumArithIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  NumArithIterator,
  BinaryBaseIterator<NumArithIterator<Operation>, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<NumArithIterator<Operation>,PlanIteratorState>*)this);
  }
};


/*******************************************************************************
  Template iterator for numeric arithmetic operations (+, -, *, div, idiv, and
  mod) between operands of a specific data type. The class that implements the
  specific operation is passed as the template class param, and the data type
  of the operands is passed as a template const param.
********************************************************************************/
template < class Operation, store::SchemaTypeCode Type >
class SpecificNumArithIterator : 
public BinaryBaseIterator<SpecificNumArithIterator<Operation, Type>, PlanIteratorState>
{
public:
  static bool
  compute(
        store::Item_t& result,
        dynamic_context* dctx,
        const TypeManager* tm,
        const QueryLoc& loc,
        store::Item *item0,
        store::Item *item1);

public:
  SpecificNumArithIterator(
        static_context* sctx,
        const QueryLoc&,
        PlanIter_t&,
        PlanIter_t&);

  virtual ~SpecificNumArithIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState&) const;
      
public:
  SERIALIZABLE_TEMPLATE_CLASS(SpecificNumArithIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR3T(
  SpecificNumArithIterator,
  BinaryBaseIterator<SpecificNumArithIterator<Operation, Type>, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (BinaryBaseIterator<SpecificNumArithIterator<Operation, Type>, PlanIteratorState>*)this);
  }
};


/*******************************************************************************
  6.2.7 op:numeric-unary-plus
  6.2.8 op:numeric-unary-minus
********************************************************************************/
class OpNumericUnaryIterator : public UnaryBaseIterator<OpNumericUnaryIterator,
                                                        PlanIteratorState>
{
private:
  bool thePlus;

public:
  SERIALIZABLE_CLASS(OpNumericUnaryIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  OpNumericUnaryIterator,
  UnaryBaseIterator<OpNumericUnaryIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, 
    (UnaryBaseIterator<OpNumericUnaryIterator, PlanIteratorState>*)this);

    ar & thePlus;
  }

public:
  OpNumericUnaryIterator(
        static_context* sctx,
        const QueryLoc&,
        PlanIter_t& aChild,
        bool aPlus);

  virtual ~OpNumericUnaryIterator();
  
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


class OpDoubleUnaryIterator : public UnaryBaseIterator<OpDoubleUnaryIterator,
                                                       PlanIteratorState>
{
private:
  bool thePlus;

public:
  SERIALIZABLE_CLASS(OpDoubleUnaryIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  OpDoubleUnaryIterator,
  UnaryBaseIterator<OpDoubleUnaryIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, 
    (UnaryBaseIterator<OpDoubleUnaryIterator, PlanIteratorState>*)this);

    ar & thePlus;
  }

public:
  OpDoubleUnaryIterator(
        static_context* sctx,
        const QueryLoc&,
        PlanIter_t& aChild,
        bool aPlus);

  virtual ~OpDoubleUnaryIterator();
  
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


}
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
