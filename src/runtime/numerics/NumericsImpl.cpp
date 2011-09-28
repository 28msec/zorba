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
#include "stdafx.h"

#include "common/shared_types.h"

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"
#include "zorbatypes/zorbatypes_decl.h"

#include "system/globalenv.h"

#include "util/tracer.h"

#include "types/casting.h"
#include "types/typeops.h"

#include "context/static_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/numerics/NumericsImpl.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/core/arithmetic_impl.h"

#include "store/api/item_factory.h"
#include "store/api/item.h"


namespace zorba
{
SERIALIZABLE_TEMPLATE_VERSIONS(NumArithIterator)
END_SERIALIZABLE_TEMPLATE_VERSIONS(NumArithIterator)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(NumArithIterator, NumArithIterator<AddOperation>, 1)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(NumArithIterator, NumArithIterator<SubtractOperation>, 2)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(NumArithIterator, NumArithIterator<MultiplyOperation>, 3)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(NumArithIterator, NumArithIterator<DivideOperation>, 4)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(NumArithIterator, NumArithIterator<IntegerDivideOperation>, 5)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(NumArithIterator, NumArithIterator<ModOperation>, 6)

SERIALIZABLE_TEMPLATE_VERSIONS(SpecificNumArithIterator)
END_SERIALIZABLE_TEMPLATE_VERSIONS(SpecificNumArithIterator)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<AddOperation, TypeConstants::XS_DOUBLE>, 1);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<AddOperation, TypeConstants::XS_FLOAT>, 2);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<AddOperation, TypeConstants::XS_DECIMAL>, 3);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<AddOperation, TypeConstants::XS_INTEGER>, 4);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_DOUBLE>, 5);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_FLOAT>, 6);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_DECIMAL>, 7);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_INTEGER>, 8);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_DOUBLE>, 9);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_FLOAT>, 10);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_DECIMAL>, 11);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_INTEGER>, 12);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<DivideOperation, TypeConstants::XS_DOUBLE>, 13);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<DivideOperation, TypeConstants::XS_FLOAT>, 14);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<DivideOperation, TypeConstants::XS_DECIMAL>, 15);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<DivideOperation, TypeConstants::XS_INTEGER>, 16);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<ModOperation, TypeConstants::XS_DOUBLE>, 17);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<ModOperation, TypeConstants::XS_FLOAT>, 18);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<ModOperation, TypeConstants::XS_DECIMAL>, 19);
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(SpecificNumArithIterator, SpecificNumArithIterator<ModOperation, TypeConstants::XS_INTEGER>, 20);


SERIALIZABLE_CLASS_VERSIONS(OpNumericUnaryIterator)
END_SERIALIZABLE_CLASS_VERSIONS(OpNumericUnaryIterator)

SERIALIZABLE_CLASS_VERSIONS(OpDoubleUnaryIterator)
END_SERIALIZABLE_CLASS_VERSIONS(OpDoubleUnaryIterator)

/*******************************************************************************
  AddOperation (see runtime/core/arithmetic_impl.h/cpp)
********************************************************************************/
template<>
bool AddOperation::compute<TypeConstants::XS_DOUBLE, TypeConstants::XS_DOUBLE>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc*,
    const store::Item* i0,
    const store::Item* i1 )
{
  return GENV_ITEMFACTORY->
         createDouble(result, i0->getDoubleValue() + i1->getDoubleValue());
}


template<>
bool AddOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc*,
    const store::Item* i0,
    const store::Item* i1 )
{
  return GENV_ITEMFACTORY->
         createFloat(result, i0->getFloatValue() + i1->getFloatValue());
}


template<>
bool AddOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc*,
    const store::Item* i0,
    const store::Item* i1 )
{
  return GENV_ITEMFACTORY->
         createDecimal(result,  i0->getDecimalValue() + i1->getDecimalValue());
}


template<>
bool AddOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc*,
    const store::Item* i0,
    const store::Item* i1)
{
  return GENV_ITEMFACTORY->
         createInteger(result, i0->getIntegerValue() + i1->getIntegerValue());
}


/*******************************************************************************
  SubtractOperation (see runtime/core/arithmetic_impl.h/cpp)
********************************************************************************/
template<>
bool SubtractOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DOUBLE>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc*,
    const store::Item* i0,
    const store::Item* i1)
{
  return GENV_ITEMFACTORY->
         createDouble(result, i0->getDoubleValue() - i1->getDoubleValue());
}


template<>
bool SubtractOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc*,
    const store::Item* i0,
    const store::Item* i1 )
{
  return GENV_ITEMFACTORY->
         createFloat(result, i0->getFloatValue() - i1->getFloatValue());
}


template<>
bool SubtractOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc*,
    const store::Item* i0,
    const store::Item* i1 )
{
  return GENV_ITEMFACTORY->
         createDecimal(result, i0->getDecimalValue() - i1->getDecimalValue());
}


template<>
bool SubtractOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc*,
    const store::Item* i0,
    const store::Item* i1 )
{
  return GENV_ITEMFACTORY->
         createInteger(result, i0->getIntegerValue() - i1->getIntegerValue());
}


/*******************************************************************************
  MultiplyOperation (see runtime/core/arithmetic_impl.h/cpp)
********************************************************************************/
template<>
bool MultiplyOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DOUBLE>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc*,
    const store::Item* i0,
    const store::Item* i1 )
{
  return GENV_ITEMFACTORY->
         createDouble(result, i0->getDoubleValue() * i1->getDoubleValue());
}


template<>
bool MultiplyOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc*,
    const store::Item* i0,
    const store::Item* i1)
{
  return GENV_ITEMFACTORY->
         createFloat(result,  i0->getFloatValue() * i1->getFloatValue());
}


template<>
bool MultiplyOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc*,
    const store::Item* i0,
    const store::Item* i1)
{
  return GENV_ITEMFACTORY->
         createDecimal(result,  i0->getDecimalValue() * i1->getDecimalValue());
}


template<>
bool MultiplyOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc*,
    const store::Item* i0,
    const store::Item* i1)
{
  return GENV_ITEMFACTORY->
         createInteger(result,  i0->getIntegerValue() * i1->getIntegerValue());
}


/*******************************************************************************
  DivideOperation (see runtime/core/arithmetic_impl.h/cpp)
********************************************************************************/
template<>
bool DivideOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DOUBLE>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc*,
    const store::Item* i0,
    const store::Item* i1)
{
  return GENV_ITEMFACTORY->
         createDouble(result, i0->getDoubleValue() / i1->getDoubleValue());
}


template<>
bool DivideOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc*,
    const store::Item* i0,
    const store::Item* i1)
{
  return GENV_ITEMFACTORY->
         createFloat(result, i0->getFloatValue() / i1->getFloatValue());
}


template<>
bool DivideOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL>(
    store::Item_t& result,
    dynamic_context* /*dctx*/,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  xs_decimal ld0 = i0->getDecimalValue();
  xs_decimal ld1 = i1->getDecimalValue();
  if ( ld1 == Integer::zero() )
  {
    throw XQUERY_EXCEPTION( err::FOAR0001, ERROR_LOC( loc ) );
  }
  return GENV_ITEMFACTORY->createDecimal (result,  ld0 / ld1 );
}


template<>
bool DivideOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1 )
{
  xs_decimal const ll0(i0->getIntegerValue());
  xs_decimal const ll1(i1->getIntegerValue());
  if ( ll1 == Integer::zero() )
  {
    throw XQUERY_EXCEPTION( err::FOAR0001, ERROR_LOC( loc ) );
  }
  return GENV_ITEMFACTORY->createDecimal (result,  ll0 / ll1 );
}


/*******************************************************************************
  IntegerDivideOperation (see runtime/core/arithmetic_impl.h/cpp)
********************************************************************************/
template<>
bool IntegerDivideOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DOUBLE>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1 )
{
  xs_double d0 = i0->getDoubleValue();
  xs_double d1 = i1->getDoubleValue();

  if ( d1 == xs_double::zero() )
  {
    throw XQUERY_EXCEPTION( err::FOAR0001, ERROR_LOC( loc ) );
  }

  if (i0->isNaN() || i1->isNaN()) 
  {
    throw XQUERY_EXCEPTION(
      err::FOAR0002, ERROR_PARAMS( ZED( DivisionNoNaN ) ), ERROR_LOC( loc )
    );
  }
  if (i0->isPosOrNegInf()) 
  {
    throw XQUERY_EXCEPTION(
      err::FOAR0002, ERROR_PARAMS( ZED( DivisionNoINF ) ), ERROR_LOC( loc )
    );
  }

  if (i0->isPosOrNegInf()) {
    // idiv with +-INF divisor has 0 as result
    return GENV_ITEMFACTORY->createInteger(result, Integer::zero());
  }

  xs_integer const lInteger( d0 / d1 );
  return GENV_ITEMFACTORY->createInteger (result,  lInteger );
}


template<>
bool IntegerDivideOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  xs_float f0 = i0->getFloatValue();
  xs_float f1 = i1->getFloatValue();
  if ( f1 == xs_float::zero() )
  {
    throw XQUERY_EXCEPTION( err::FOAR0001, ERROR_LOC( loc ) );
  }

  if (i0->isNaN() || i1->isNaN()) 
  {
    throw XQUERY_EXCEPTION(
      err::FOAR0002, ERROR_PARAMS( ZED( DivisionNoNaN ) ), ERROR_LOC( loc )
    );
  }
  if (i0->isPosOrNegInf()) 
  {
    throw XQUERY_EXCEPTION(
      err::FOAR0002, ERROR_PARAMS( ZED( DivisionNoINF ) ), ERROR_LOC( loc )
    );
  }
  if (i0->isPosOrNegInf()) 
  {
    // idiv with +-INF divisor has 0 as result
    return GENV_ITEMFACTORY->createInteger(result, Integer::zero());
  }

  xs_integer const lInteger( f0 / f1 );
  return GENV_ITEMFACTORY->createInteger(result, lInteger);
}


template<>
bool IntegerDivideOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1 )
{
  xs_decimal ld0 = i0->getDecimalValue();
  xs_decimal ld1 = i1->getDecimalValue();

  if ( ld1.sign() == 0 )
  {
    throw XQUERY_EXCEPTION( err::FOAR0001, ERROR_LOC( loc ) );
  }
  return GENV_ITEMFACTORY->createInteger(result, Integer(ld0 / ld1));
}


template<>
bool IntegerDivideOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1 )
{
  xs_integer ll0 = i0->getIntegerValue();
  xs_integer ll1 = i1->getIntegerValue();

  if ( ll1 == Integer::zero() )
  {
    throw XQUERY_EXCEPTION( err::FOAR0001, ERROR_LOC( loc ) );
  }
  return GENV_ITEMFACTORY->createInteger (result, ll0 / ll1);
}


/*******************************************************************************
  ModOperation (see runtime/core/arithmetic_impl.h/cpp)
********************************************************************************/
template<>
bool ModOperation::compute<TypeConstants::XS_DOUBLE, TypeConstants::XS_DOUBLE>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc*,
    const store::Item* i0,
    const store::Item* i1)
{
  return GENV_ITEMFACTORY->
         createDouble(result, i0->getDoubleValue() % i1->getDoubleValue());
}


template<>
bool ModOperation::compute<TypeConstants::XS_FLOAT, TypeConstants::XS_FLOAT>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc*,
    const store::Item* i0,
    const store::Item* i1)
{
  return GENV_ITEMFACTORY->
         createFloat(result, i0->getFloatValue() % i1->getFloatValue());
}


template<>
bool ModOperation::compute<TypeConstants::XS_DECIMAL, TypeConstants::XS_DECIMAL>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  xs_decimal ld0 = i0->getDecimalValue();
  xs_decimal ld1 = i1->getDecimalValue();

  if ( ld1.sign() == 0 )
  {
    throw XQUERY_EXCEPTION( err::FOAR0001, ERROR_LOC( loc ) );
  }
  return GENV_ITEMFACTORY->createDecimal(result,  ld0 % ld1);
}


template<>
bool ModOperation::compute<TypeConstants::XS_INTEGER, TypeConstants::XS_INTEGER>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  xs_integer ll0 = i0->getIntegerValue();
  xs_integer ll1 = i1->getIntegerValue();

  if ( ll1 == Integer::zero() )
  {
    throw XQUERY_EXCEPTION( err::FOAR0001, ERROR_LOC( loc ) );
  }
  return GENV_ITEMFACTORY->createInteger(result, ll0 % ll1);
}


/*******************************************************************************
  NumArithIterator<Operation>
********************************************************************************/

template< class Operations>
NumArithIterator<Operations>::NumArithIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& iter0,
    PlanIter_t& iter1)
  :
  BinaryBaseIterator<NumArithIterator<Operations>, PlanIteratorState >(sctx, loc, iter0, iter1)
{ 
}


template < class Operation >
bool NumArithIterator<Operation>::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  bool res;
  store::Item_t n0;
  store::Item_t n1;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (this->consumeNext(n0, this->theChild0.getp(), planState))
  {
    if (this->consumeNext(n1, this->theChild1.getp(), planState))
    {
      res = compute(result,
                    planState.theLocalDynCtx,
                    this->theSctx->get_typemanager(),
                    this->loc,
                    n0,
                    n1);
      
      if (this->consumeNext(n0, this->theChild0.getp(), planState) ||
          this->consumeNext(n1, this->theChild1.getp(), planState))
        throw XQUERY_EXCEPTION(
          err::XPTY0004, ERROR_PARAMS( ZED( NoSeqAsArithOp ) )
        );
      STACK_PUSH(res, state);
    }
  }

  STACK_END(state);
}


template <class Operation>
void NumArithIterator<Operation>::accept(PlanIterVisitor& v) const 
{
  v.beginVisit(*this);

  this->theChild0->accept(v);
  this->theChild1->accept(v);

  v.endVisit(*this);
}



template < class Operation >
bool NumArithIterator<Operation>::compute(
    store::Item_t& result,
    dynamic_context* dctx,
    const TypeManager* tm,
    const QueryLoc& aLoc, 
    store::Item_t& n0,
    store::Item_t& n1)
{
  assert(n0->isAtomic());
  assert(n1->isAtomic());

  xqtref_t type0 = tm->create_value_type(n0);
  xqtref_t type1 = tm->create_value_type(n1);

  return computeAtomic(result, dctx, tm, aLoc, n0, type0, n1, type1);
}

  
template < class Operation >
bool NumArithIterator<Operation>::computeAtomic(
    store::Item_t& result,
    dynamic_context* dctx,
    const TypeManager* tm,
    const QueryLoc& aLoc,
    store::Item_t& item0,
    xqtref_t type0,
    store::Item_t& item1,
    xqtref_t type1)
{
  bool res;
  store::Item_t n0;
  store::Item_t n1;

  bool isDivision = Operation::getOperationKind() == ArithmeticConsts::DIVISION;

  xqtref_t resultType = TypeOps::arithmetic_type(tm, *type0, *type1, isDivision);

  switch (TypeOps::get_atomic_type_code(*resultType))
  {
  case TypeConstants::XS_DOUBLE:
  {
    GenericCast::castToAtomic(n0, item0, &*resultType, tm, NULL, aLoc);
    GenericCast::castToAtomic(n1, item1, &*resultType, tm, NULL, aLoc);
    
    res = Operation::template
          computeSingleType<TypeConstants::XS_DOUBLE>
          (result, dctx, tm, &aLoc, n0, n1 );
    break;
  }
  case TypeConstants::XS_FLOAT:
  {
    GenericCast::castToAtomic(n0, item0, &*resultType, tm, NULL, aLoc);
    GenericCast::castToAtomic(n1, item1, &*resultType, tm, NULL, aLoc);

    res = Operation::template 
          computeSingleType<TypeConstants::XS_FLOAT>
          (result, dctx, tm, &aLoc, n0, n1);
    break;
  }
  case TypeConstants::XS_DECIMAL:
  {
    GenericCast::castToAtomic(n0, item0, &*resultType, tm, NULL, aLoc);
    GenericCast::castToAtomic(n1, item1, &*resultType, tm, NULL, aLoc);

    res = Operation::template
          computeSingleType<TypeConstants::XS_DECIMAL>
          (result, dctx, tm, &aLoc,n0, n1);
    break;
  }
  case TypeConstants::XS_INTEGER:
  {
    GenericCast::castToAtomic(n0, item0, &*resultType, tm, NULL, aLoc);
    GenericCast::castToAtomic(n1, item1, &*resultType, tm, NULL, aLoc);

    res = Operation::template 
          computeSingleType<TypeConstants::XS_INTEGER>
          (result, dctx, tm, &aLoc, n0, n1 );
    break;
  }
  default:
  {
    throw XQUERY_EXCEPTION(
        err::XPTY0004,
        ERROR_PARAMS( ZED( ArithOpNotDefinedBetween_23 ), *type0, *type1 ),
        ERROR_LOC( aLoc )
      );
  }
  }

  return res;
}

  
// instantiate NumArithIterator for all kinds of arithmetic operators
template class NumArithIterator<AddOperation>;
template class NumArithIterator<SubtractOperation>;
template class NumArithIterator<MultiplyOperation>;
template class NumArithIterator<DivideOperation>;
template class NumArithIterator<IntegerDivideOperation>;
template class NumArithIterator<ModOperation>;


/*******************************************************************************

********************************************************************************/

template< class Operations, TypeConstants::atomic_type_code_t Type >
SpecificNumArithIterator<Operations, Type>::SpecificNumArithIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& iter0,
    PlanIter_t& iter1)
  :
  BinaryBaseIterator<SpecificNumArithIterator<Operations, Type>, PlanIteratorState >(sctx, loc, iter0, iter1)
{ 
}


template < class Operation, TypeConstants::atomic_type_code_t Type >
void SpecificNumArithIterator<Operation, Type>::accept(PlanIterVisitor& v) const 
{
  v.beginVisit(*this);

  this->theChild0->accept(v);
  this->theChild1->accept(v);

  v.endVisit(*this);
}


template < class Operation, TypeConstants::atomic_type_code_t Type >
bool SpecificNumArithIterator<Operation, Type>::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  bool res;
  store::Item_t n0;
  store::Item_t n1;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (this->consumeNext( n0, this->theChild0.getp(), planState ))
  {
    if (this->consumeNext( n1, this->theChild1.getp(), planState ))
    {
      res = compute(result,
                    planState.theLocalDynCtx,
                    this->theSctx->get_typemanager(),
                    this->loc,
                    n0.getp(),
                    n1.getp());
      
      if (this->consumeNext(n0, this->theChild0.getp(), planState) ||
          this->consumeNext(n1, this->theChild1.getp(), planState))
        throw XQUERY_EXCEPTION(
          err::XPTY0004, ERROR_PARAMS( ZED( NoSeqAsArithOp ) )
        );
      STACK_PUSH ( res, state );
    }
  }
  STACK_END (state);
}


template < class Operation, TypeConstants::atomic_type_code_t Type >
bool SpecificNumArithIterator<Operation, Type>::compute(
    store::Item_t& result,
    dynamic_context* dctx,
    const TypeManager* tm,
    const QueryLoc& aLoc, 
    store::Item *n0,
    store::Item *n1)
{
  assert(n0->isAtomic());
  assert(n1->isAtomic());

  return Operation::template computeSingleType<Type>(result, dctx, tm, &aLoc, n0, n1 );
}

  
template class SpecificNumArithIterator<AddOperation, TypeConstants::XS_DOUBLE>;
template class SpecificNumArithIterator<AddOperation, TypeConstants::XS_FLOAT>;
template class SpecificNumArithIterator<AddOperation, TypeConstants::XS_DECIMAL>;
template class SpecificNumArithIterator<AddOperation, TypeConstants::XS_INTEGER>;
template class SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_DOUBLE>;
template class SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_FLOAT>;
template class SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_DECIMAL>;
template class SpecificNumArithIterator<SubtractOperation, TypeConstants::XS_INTEGER>;
template class SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_DOUBLE>;
template class SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_FLOAT>;
template class SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_DECIMAL>;
template class SpecificNumArithIterator<MultiplyOperation, TypeConstants::XS_INTEGER>;
template class SpecificNumArithIterator<DivideOperation, TypeConstants::XS_DOUBLE>;
template class SpecificNumArithIterator<DivideOperation, TypeConstants::XS_FLOAT>;
template class SpecificNumArithIterator<DivideOperation, TypeConstants::XS_DECIMAL>;
template class SpecificNumArithIterator<DivideOperation, TypeConstants::XS_INTEGER>;
template class SpecificNumArithIterator<ModOperation, TypeConstants::XS_DOUBLE>;
template class SpecificNumArithIterator<ModOperation, TypeConstants::XS_FLOAT>;
template class SpecificNumArithIterator<ModOperation, TypeConstants::XS_DECIMAL>;
template class SpecificNumArithIterator<ModOperation, TypeConstants::XS_INTEGER>;


/*******************************************************************************

********************************************************************************/
OpNumericUnaryIterator::OpNumericUnaryIterator (
     static_context* sctx,
     const QueryLoc& loc,
     PlanIter_t& theChild,
     bool aPlus )
  :
  UnaryBaseIterator<OpNumericUnaryIterator, PlanIteratorState>(sctx, loc, theChild),
  thePlus(aPlus)
{
}


OpNumericUnaryIterator::~OpNumericUnaryIterator()
{
}


bool OpNumericUnaryIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  xqtref_t type;

  const RootTypeManager& rtm = GENV_TYPESYSTEM;
  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChild.getp(), planState ))
  {
    assert(item->isAtomic());

    type = tm->create_value_type(item);

    if (TypeOps::is_subtype(tm, *type, *rtm.UNTYPED_ATOMIC_TYPE_ONE ) )
    {
      GenericCast::castToAtomic(item, item, &*rtm.DOUBLE_TYPE_ONE, tm, NULL, loc);
      type = rtm.DOUBLE_TYPE_ONE;
    }
    
    // TODO Optimizations (e.g. if item has already the correct type and value,
    // it does not have to be created newly)
    if (TypeOps::is_subtype(tm, *type, *rtm.DOUBLE_TYPE_ONE))
    {
      GENV_ITEMFACTORY->
      createDouble(result,
                   (thePlus ? item->getDoubleValue() : -item->getDoubleValue()));
    }
    else if ( TypeOps::is_subtype(tm, *type, *rtm.FLOAT_TYPE_ONE ) )
    {
      GENV_ITEMFACTORY->
      createFloat(result,
                  (thePlus ? item->getFloatValue() : -item->getFloatValue()));
    }
    else if ( TypeOps::is_subtype(tm, *type, *rtm.INTEGER_TYPE_ONE ) )
    {
      GENV_ITEMFACTORY->
      createInteger(result,
                    (thePlus ? item->getIntegerValue() : -item->getIntegerValue()));
    }
    else if ( TypeOps::is_subtype(tm, *type, *rtm.DECIMAL_TYPE_ONE ) )
    {
      GENV_ITEMFACTORY->
      createDecimal(result,
                   (thePlus ? item->getDecimalValue() : -item->getDecimalValue()));
    }
    else
    {
      throw XQUERY_EXCEPTION(
        err::XPTY0004,
        ERROR_PARAMS( ZED( BadTypeFor_23 ), type, ZED( UnaryArithOp ) ),
        ERROR_LOC( loc )
      );
    }
    
    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


UNARY_ACCEPT(OpNumericUnaryIterator);


/*******************************************************************************

********************************************************************************/
OpDoubleUnaryIterator::OpDoubleUnaryIterator(
     static_context* sctx,
     const QueryLoc& loc,
     PlanIter_t& theChild,
     bool aPlus)
  :
  UnaryBaseIterator<OpDoubleUnaryIterator, PlanIteratorState>(sctx, loc, theChild),
  thePlus(aPlus)
{
}


OpDoubleUnaryIterator::~OpDoubleUnaryIterator()
{
}


bool OpDoubleUnaryIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChild.getp(), planState ))
  {
    assert(item->isAtomic());

    GENV_ITEMFACTORY->createDouble(result, (thePlus ?
                                            item->getDoubleValue() :
                                            -item->getDoubleValue()));

    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


UNARY_ACCEPT(OpDoubleUnaryIterator);


} // namespace zorba
/* vim:set et sw=2 ts=2: */
