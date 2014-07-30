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
#include "diagnostics/util_macros.h"
#include "diagnostics/xquery_diagnostics.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/integer.h"
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

SERIALIZABLE_TEMPLATE_INSTANCE(NumArithIterator,
                               NumArithIterator<AddOperation>,
                               1)
template<>
DEF_GET_NAME_AS_STRING(NumArithIterator<AddOperation>)

SERIALIZABLE_TEMPLATE_INSTANCE(NumArithIterator,
                               NumArithIterator<SubtractOperation>,
                               2)
template<>
DEF_GET_NAME_AS_STRING(NumArithIterator<SubtractOperation>)

SERIALIZABLE_TEMPLATE_INSTANCE(NumArithIterator,
                               NumArithIterator<MultiplyOperation>,
                               3)
template<>
DEF_GET_NAME_AS_STRING(NumArithIterator<MultiplyOperation>)

SERIALIZABLE_TEMPLATE_INSTANCE(NumArithIterator,
                               NumArithIterator<DivideOperation>,
                               4)
template<>
DEF_GET_NAME_AS_STRING(NumArithIterator<DivideOperation>)

SERIALIZABLE_TEMPLATE_INSTANCE(NumArithIterator,
                               NumArithIterator<IntegerDivideOperation>,
                               5)
template<>
DEF_GET_NAME_AS_STRING(NumArithIterator<IntegerDivideOperation>)

SERIALIZABLE_TEMPLATE_INSTANCE(NumArithIterator,
                               NumArithIterator<ModOperation>,
                               6)
template<>
DEF_GET_NAME_AS_STRING(NumArithIterator<ModOperation>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<AddOperation, store::XS_DOUBLE>,
1);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<AddOperation,store::XS_DOUBLE>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<AddOperation, store::XS_FLOAT>,
2);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<AddOperation,store::XS_FLOAT>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<AddOperation, store::XS_DECIMAL>,
3);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<AddOperation,store::XS_DECIMAL>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<AddOperation, store::XS_INTEGER>,
4);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<AddOperation,store::XS_INTEGER>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<SubtractOperation, store::XS_DOUBLE>,
5);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<SubtractOperation,store::XS_DOUBLE>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<SubtractOperation, store::XS_FLOAT>,
6);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<SubtractOperation,store::XS_FLOAT>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<SubtractOperation, store::XS_DECIMAL>,
7);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<SubtractOperation,store::XS_DECIMAL>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<SubtractOperation, store::XS_INTEGER>,
8);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<SubtractOperation,store::XS_INTEGER>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<MultiplyOperation, store::XS_DOUBLE>,
9);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<MultiplyOperation,store::XS_DOUBLE>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<MultiplyOperation, store::XS_FLOAT>,
10);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<MultiplyOperation,store::XS_FLOAT>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<MultiplyOperation, store::XS_DECIMAL>,
11);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<MultiplyOperation,store::XS_DECIMAL>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<MultiplyOperation, store::XS_INTEGER>,
12);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<MultiplyOperation,store::XS_INTEGER>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<DivideOperation, store::XS_DOUBLE>,
13);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<DivideOperation,store::XS_DOUBLE>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<DivideOperation, store::XS_FLOAT>,
14);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<DivideOperation,store::XS_FLOAT>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<DivideOperation, store::XS_DECIMAL>,
15);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<DivideOperation,store::XS_DECIMAL>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<DivideOperation, store::XS_INTEGER>,
16);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<DivideOperation,store::XS_INTEGER>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<ModOperation, store::XS_DOUBLE>,
17);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<ModOperation,store::XS_DOUBLE>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<ModOperation, store::XS_FLOAT>,
18);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<ModOperation,store::XS_FLOAT>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<ModOperation, store::XS_DECIMAL>,
19);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<ModOperation,store::XS_DECIMAL>)

SERIALIZABLE_TEMPLATE_INSTANCE_2(
SpecificNumArithIterator,
SpecificNumArithIterator<ModOperation, store::XS_INTEGER>,
20);
template<>
DEF_GET_NAME_AS_STRING(SpecificNumArithIterator<ModOperation,store::XS_INTEGER>)


SERIALIZABLE_CLASS_VERSIONS(OpNumericUnaryIterator)
DEF_GET_NAME_AS_STRING(OpNumericUnaryIterator)

SERIALIZABLE_CLASS_VERSIONS(OpDoubleUnaryIterator)
DEF_GET_NAME_AS_STRING(OpDoubleUnaryIterator)


/*******************************************************************************
  AddOperation (see runtime/core/arithmetic_impl.h/cpp)
********************************************************************************/
template<>
bool AddOperation::compute<store::XS_DOUBLE, store::XS_DOUBLE>(
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
bool AddOperation::compute<store::XS_FLOAT,store::XS_FLOAT>(
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
bool AddOperation::compute<store::XS_DECIMAL,store::XS_DECIMAL>(
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
bool AddOperation::compute<store::XS_INTEGER,store::XS_INTEGER>(
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
bool SubtractOperation::compute<store::XS_DOUBLE,store::XS_DOUBLE>(
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
bool SubtractOperation::compute<store::XS_FLOAT,store::XS_FLOAT>(
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
bool SubtractOperation::compute<store::XS_DECIMAL,store::XS_DECIMAL>(
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
bool SubtractOperation::compute<store::XS_INTEGER,store::XS_INTEGER>(
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
bool MultiplyOperation::compute<store::XS_DOUBLE,store::XS_DOUBLE>(
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
bool MultiplyOperation::compute<store::XS_FLOAT,store::XS_FLOAT>(
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
bool MultiplyOperation::compute<store::XS_DECIMAL,store::XS_DECIMAL>(
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
bool MultiplyOperation::compute<store::XS_INTEGER,store::XS_INTEGER>(
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
bool DivideOperation::compute<store::XS_DOUBLE,store::XS_DOUBLE>(
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
bool DivideOperation::compute<store::XS_FLOAT,store::XS_FLOAT>(
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
bool DivideOperation::compute<store::XS_DECIMAL,store::XS_DECIMAL>(
    store::Item_t& result,
    dynamic_context* /*dctx*/,
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
  return GENV_ITEMFACTORY->createDecimal (result,  ld0 / ld1 );
}


template<>
bool DivideOperation::compute<store::XS_INTEGER,store::XS_INTEGER>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1 )
{
  xs_decimal const ll0(i0->getIntegerValue());
  xs_decimal const ll1(i1->getIntegerValue());
  if ( ll1.sign() == 0 )
  {
    throw XQUERY_EXCEPTION( err::FOAR0001, ERROR_LOC( loc ) );
  }
  return GENV_ITEMFACTORY->createDecimal (result,  ll0 / ll1 );
}


/*******************************************************************************
  IntegerDivideOperation (see runtime/core/arithmetic_impl.h/cpp)
********************************************************************************/
template<>
bool IntegerDivideOperation::compute<store::XS_DOUBLE,store::XS_DOUBLE>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1 )
{
  xs_double d0 = i0->getDoubleValue();
  xs_double d1 = i1->getDoubleValue();

  if ( d1 == numeric_consts<xs_double>::zero() )
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
    return GENV_ITEMFACTORY->createInteger(result, numeric_consts<xs_integer>::zero());
  }

  xs_integer const lInteger( d0 / d1 );
  return GENV_ITEMFACTORY->createInteger (result,  lInteger );
}


template<>
bool IntegerDivideOperation::compute<store::XS_FLOAT,store::XS_FLOAT>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  xs_float f0 = i0->getFloatValue();
  xs_float f1 = i1->getFloatValue();
  if ( f1 == numeric_consts<xs_float>::zero() )
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
    return GENV_ITEMFACTORY->createInteger(result, numeric_consts<xs_integer>::zero());
  }

  xs_integer const lInteger( f0 / f1 );
  return GENV_ITEMFACTORY->createInteger(result, lInteger);
}


template<>
bool IntegerDivideOperation::compute<store::XS_DECIMAL,store::XS_DECIMAL>(
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
bool IntegerDivideOperation::compute<store::XS_INTEGER,store::XS_INTEGER>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1 )
{
  xs_integer ll0 = i0->getIntegerValue();
  xs_integer ll1 = i1->getIntegerValue();

  if ( ll1.sign() == 0 )
  {
    throw XQUERY_EXCEPTION( err::FOAR0001, ERROR_LOC( loc ) );
  }

  return GENV_ITEMFACTORY->createInteger (result, ll0 / ll1);
}


/*******************************************************************************
  ModOperation (see runtime/core/arithmetic_impl.h/cpp)
********************************************************************************/
template<>
bool ModOperation::compute<store::XS_DOUBLE, store::XS_DOUBLE>(
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
bool ModOperation::compute<store::XS_FLOAT, store::XS_FLOAT>(
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
bool ModOperation::compute<store::XS_DECIMAL, store::XS_DECIMAL>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  xs_decimal ld0 = i0->getDecimalValue();
  xs_decimal ld1 = i1->getDecimalValue();

  if (ld1.sign() == 0)
  {
    throw XQUERY_EXCEPTION(err::FOAR0001, ERROR_LOC(loc));
  }
  return GENV_ITEMFACTORY->createDecimal(result,  ld0 % ld1);
}


template<>
bool ModOperation::compute<store::XS_INTEGER, store::XS_INTEGER>(
    store::Item_t& result,
    dynamic_context* /* dctx */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  xs_integer ll0 = i0->getIntegerValue();
  xs_integer ll1 = i1->getIntegerValue();

  if ( ll1.sign() == 0 )
  {
    throw XQUERY_EXCEPTION(err::FOAR0001, ERROR_LOC(loc));
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

      STACK_PUSH(res, state);
    }
  }

  STACK_END(state);
}


template <class Operation>
void NumArithIterator<Operation>::accept(PlanIterVisitor& v) const 
{
  if (!v.hasToVisit(this))
    return;

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

  store::SchemaTypeCode type0 = n0->getTypeCode();
  store::SchemaTypeCode type1 = n1->getTypeCode();

  return computeAtomic(result, dctx, tm, aLoc, n0, type0, n1, type1);
}

  
template < class Operation >
bool NumArithIterator<Operation>::computeAtomic(
    store::Item_t& result,
    dynamic_context* dctx,
    const TypeManager* tm,
    const QueryLoc& aLoc,
    store::Item_t& item0,
    store::SchemaTypeCode type0,
    store::Item_t& item1,
    store::SchemaTypeCode type1)
{
  bool res;
  store::Item_t n0;
  store::Item_t n1;

  bool isDivision = Operation::getOperationKind() == ArithmeticConsts::DIVISION;

  store::SchemaTypeCode resultType = TypeOps::arithmetic_type(type0, type1, isDivision);

  switch (resultType)
  {
  case store::XS_DOUBLE:
  {
    GenericCast::castToBuiltinAtomic(n0, item0, resultType, NULL, aLoc);
    GenericCast::castToBuiltinAtomic(n1, item1, resultType, NULL, aLoc);
    
    res = Operation::template
          computeSingleType<store::XS_DOUBLE>
          (result, dctx, tm, &aLoc, n0, n1 );
    break;
  }
  case store::XS_FLOAT:
  {
    GenericCast::castToBuiltinAtomic(n0, item0, resultType, NULL, aLoc);
    GenericCast::castToBuiltinAtomic(n1, item1, resultType, NULL, aLoc);

    res = Operation::template 
          computeSingleType<store::XS_FLOAT>
          (result, dctx, tm, &aLoc, n0, n1);
    break;
  }
  case store::XS_DECIMAL:
  {
    GenericCast::castToBuiltinAtomic(n0, item0, resultType, NULL, aLoc);
    GenericCast::castToBuiltinAtomic(n1, item1, resultType, NULL, aLoc);

    res = Operation::template
          computeSingleType<store::XS_DECIMAL>
          (result, dctx, tm, &aLoc,n0, n1);
    break;
  }
  case store::XS_INTEGER:
  {
    GenericCast::castToBuiltinAtomic(n0, item0, resultType, NULL, aLoc);
    GenericCast::castToBuiltinAtomic(n1, item1, resultType, NULL, aLoc);

    res = Operation::template 
          computeSingleType<store::XS_INTEGER>
          (result, dctx, tm, &aLoc, n0, n1 );
    break;
  }
  default:
  {
    xqtref_t type0 = tm->create_value_type(item0);
    xqtref_t type1 = tm->create_value_type(item1);

    RAISE_ERROR(err::XPTY0004, aLoc,
    ERROR_PARAMS(ZED(ArithOpNotDefinedBetween_23),
                 type0->toSchemaString(),
                 type1->toSchemaString()));
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

template< class Operations, store::SchemaTypeCode Type >
SpecificNumArithIterator<Operations, Type>::SpecificNumArithIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& iter0,
    PlanIter_t& iter1)
  :
  BinaryBaseIterator<SpecificNumArithIterator<Operations, Type>, PlanIteratorState >(sctx, loc, iter0, iter1)
{ 
}


template < class Operation, store::SchemaTypeCode Type >
void SpecificNumArithIterator<Operation, Type>::accept(PlanIterVisitor& v) const 
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  this->theChild0->accept(v);
  this->theChild1->accept(v);

  v.endVisit(*this);
}


template < class Operation, store::SchemaTypeCode Type >
bool SpecificNumArithIterator<Operation, Type>::nextImpl(
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
      assert(n0->isAtomic());
      assert(n1->isAtomic());

      res = Operation::template 
      computeSingleType<Type>(result, NULL, NULL, &this->loc, n0.getp(), n1.getp());

      STACK_PUSH(res, state);
    }
  }
  STACK_END(state);
}


template < class Operation, store::SchemaTypeCode Type >
bool SpecificNumArithIterator<Operation, Type>::compute(
    store::Item_t& result,
    dynamic_context* dctx,
    const TypeManager* tm,
    const QueryLoc& aLoc, 
    store::Item* n0,
    store::Item* n1)
{
  assert(n0->isAtomic());
  assert(n1->isAtomic());

  return Operation::template computeSingleType<Type>(result, dctx, tm, &aLoc, n0, n1);
}

  
template class SpecificNumArithIterator<AddOperation, store::XS_DOUBLE>;
template class SpecificNumArithIterator<AddOperation, store::XS_FLOAT>;
template class SpecificNumArithIterator<AddOperation, store::XS_DECIMAL>;
template class SpecificNumArithIterator<AddOperation, store::XS_INTEGER>;
template class SpecificNumArithIterator<SubtractOperation, store::XS_DOUBLE>;
template class SpecificNumArithIterator<SubtractOperation, store::XS_FLOAT>;
template class SpecificNumArithIterator<SubtractOperation, store::XS_DECIMAL>;
template class SpecificNumArithIterator<SubtractOperation, store::XS_INTEGER>;
template class SpecificNumArithIterator<MultiplyOperation, store::XS_DOUBLE>;
template class SpecificNumArithIterator<MultiplyOperation, store::XS_FLOAT>;
template class SpecificNumArithIterator<MultiplyOperation, store::XS_DECIMAL>;
template class SpecificNumArithIterator<MultiplyOperation, store::XS_INTEGER>;
template class SpecificNumArithIterator<DivideOperation, store::XS_DOUBLE>;
template class SpecificNumArithIterator<DivideOperation, store::XS_FLOAT>;
template class SpecificNumArithIterator<DivideOperation, store::XS_DECIMAL>;
template class SpecificNumArithIterator<DivideOperation, store::XS_INTEGER>;
template class SpecificNumArithIterator<ModOperation, store::XS_DOUBLE>;
template class SpecificNumArithIterator<ModOperation, store::XS_FLOAT>;
template class SpecificNumArithIterator<ModOperation, store::XS_DECIMAL>;
template class SpecificNumArithIterator<ModOperation, store::XS_INTEGER>;


/*******************************************************************************

********************************************************************************/
OpNumericUnaryIterator::OpNumericUnaryIterator(
     static_context* sctx,
     const QueryLoc& loc,
     PlanIter_t& theChild,
     bool aPlus)
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
  store::SchemaTypeCode type;

  const TypeManager* tm = theSctx->get_typemanager();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChild.getp(), planState ))
  {
    assert(item->isAtomic());

    type = item->getTypeCode();

    if (type == store::XS_UNTYPED_ATOMIC)
    {
      GenericCast::castToBuiltinAtomic(item, item, store::XS_DOUBLE, NULL, loc);
      type = store::XS_DOUBLE;
    }
    
    // TODO Optimizations (e.g. if item has already the correct type and value,
    // it does not have to be created newly)
    if (TypeOps::is_subtype(type, store::XS_DOUBLE))
    {
      GENV_ITEMFACTORY->
      createDouble(result,
                   (thePlus ? item->getDoubleValue() : -item->getDoubleValue()));
    }
    else if (TypeOps::is_subtype(type, store::XS_FLOAT))
    {
      GENV_ITEMFACTORY->
      createFloat(result,
                  (thePlus ? item->getFloatValue() : -item->getFloatValue()));
    }
    else if (TypeOps::is_subtype(type, store::XS_INTEGER))
    {
      GENV_ITEMFACTORY->
      createInteger(result,
                    (thePlus ? item->getIntegerValue() : -item->getIntegerValue()));
    }
    else if (TypeOps::is_subtype(type, store::XS_DECIMAL))
    {
      GENV_ITEMFACTORY->
      createDecimal(result,
                   (thePlus ? item->getDecimalValue() : -item->getDecimalValue()));
    }
    else
    {
      xqtref_t type = tm->create_value_type(item);
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadTypeFor_23), type->toSchemaString(), ZED(UnaryArithOp)));
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

  if (consumeNext(item, theChild.getp(), planState))
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
