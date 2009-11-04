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
#include <vector>

#include "common/shared_types.h"

#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_manager.h"
#include "zorbatypes/zorbatypes_decl.h"
#include "zorbatypes/xqpstring.h"

#include "system/globalenv.h"

#include "util/tracer.h"

#include "types/casting.h"
#include "types/typeconstants.h"
#include "types/typeops.h"

#include "context/static_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/numerics/NumericsImpl.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/core/arithmetic_impl.h"
#include "runtime/api/runtimecb.h"

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

SERIALIZABLE_CLASS_VERSIONS(FnAbsIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnAbsIterator)

SERIALIZABLE_CLASS_VERSIONS(FnCeilingIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnCeilingIterator)

SERIALIZABLE_CLASS_VERSIONS(FnFloorIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnFloorIterator)

SERIALIZABLE_CLASS_VERSIONS(FnRoundIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnRoundIterator)

SERIALIZABLE_CLASS_VERSIONS(FnRoundHalfToEvenIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnRoundHalfToEvenIterator)

SERIALIZABLE_CLASS_VERSIONS(ZorNumGen)
END_SERIALIZABLE_CLASS_VERSIONS(ZorNumGen)

SERIALIZABLE_CLASS_VERSIONS(FnSQRTIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnSQRTIterator)

SERIALIZABLE_CLASS_VERSIONS(FnExpIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnExpIterator)

SERIALIZABLE_CLASS_VERSIONS(FnLogIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnLogIterator)

SERIALIZABLE_CLASS_VERSIONS(FnSinIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnSinIterator)

SERIALIZABLE_CLASS_VERSIONS(FnCosIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnCosIterator)

SERIALIZABLE_CLASS_VERSIONS(FnTanIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnTanIterator)

SERIALIZABLE_CLASS_VERSIONS(FnArcSinIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnArcSinIterator)

SERIALIZABLE_CLASS_VERSIONS(FnArcCosIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnArcCosIterator)

SERIALIZABLE_CLASS_VERSIONS(FnArcTanIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnArcTanIterator)

SERIALIZABLE_CLASS_VERSIONS(FnFormatNumberIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnFormatNumberIterator)

SERIALIZABLE_CLASS_VERSIONS(FnAtan2Iterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnAtan2Iterator)
SERIALIZABLE_CLASS_VERSIONS(FnCoshIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnCoshIterator)
SERIALIZABLE_CLASS_VERSIONS(FnAcoshIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnAcoshIterator)
SERIALIZABLE_CLASS_VERSIONS(FnFmodIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnFmodIterator)
SERIALIZABLE_CLASS_VERSIONS(FnFrexpIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnFrexpIterator)
SERIALIZABLE_CLASS_VERSIONS(FnLdexpIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnLdexpIterator)
SERIALIZABLE_CLASS_VERSIONS(FnLog10Iterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnLog10Iterator)
SERIALIZABLE_CLASS_VERSIONS(FnModfIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnModfIterator)
SERIALIZABLE_CLASS_VERSIONS(FnPowIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnPowIterator)
SERIALIZABLE_CLASS_VERSIONS(FnSinhIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnSinhIterator)
SERIALIZABLE_CLASS_VERSIONS(FnAsinhIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnAsinhIterator)
SERIALIZABLE_CLASS_VERSIONS(FnTanhIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnTanhIterator)
SERIALIZABLE_CLASS_VERSIONS(FnAtanhIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnAtanhIterator)
SERIALIZABLE_CLASS_VERSIONS(FnPiIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnPiIterator)
SERIALIZABLE_CLASS_VERSIONS(FnIsInfIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnIsInfIterator)
SERIALIZABLE_CLASS_VERSIONS(FnIsNaNIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FnIsNaNIterator)

NARY_ACCEPT (FnAbsIterator);

NARY_ACCEPT (FnCeilingIterator);

NARY_ACCEPT (FnFloorIterator);
  
NARY_ACCEPT (FnRoundIterator);
  
NARY_ACCEPT (FnRoundHalfToEvenIterator);

UNARY_ACCEPT (FnSQRTIterator);

UNARY_ACCEPT (FnExpIterator);

UNARY_ACCEPT (FnLogIterator);

UNARY_ACCEPT (FnSinIterator);

UNARY_ACCEPT (FnCosIterator);

UNARY_ACCEPT (FnTanIterator);

UNARY_ACCEPT (FnArcSinIterator);

UNARY_ACCEPT (FnArcCosIterator);

UNARY_ACCEPT (FnArcTanIterator);

NARY_ACCEPT (FnFormatNumberIterator);

BINARY_ACCEPT (FnAtan2Iterator);
UNARY_ACCEPT (FnCoshIterator);
UNARY_ACCEPT (FnAcoshIterator);
BINARY_ACCEPT (FnFmodIterator);
UNARY_ACCEPT (FnFrexpIterator);
BINARY_ACCEPT (FnLdexpIterator);
UNARY_ACCEPT (FnLog10Iterator);
UNARY_ACCEPT (FnModfIterator);
BINARY_ACCEPT (FnPowIterator);
UNARY_ACCEPT (FnSinhIterator);
UNARY_ACCEPT (FnAsinhIterator);
UNARY_ACCEPT (FnTanhIterator);
UNARY_ACCEPT (FnAtanhIterator);
NOARY_ACCEPT (FnPiIterator);
UNARY_ACCEPT (FnIsInfIterator);
UNARY_ACCEPT (FnIsNaNIterator);

/*******************************************************************************
  AddOperation (see runtime/core/arithmetic_impl.h/cpp)
********************************************************************************/
template<>
bool AddOperation::compute<TypeConstants::XS_DOUBLE, TypeConstants::XS_DOUBLE>(
    store::Item_t& result,
    RuntimeCB* /* rcb */,
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
    RuntimeCB* /* rcb */,
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
    RuntimeCB* /* rcb */,
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
    RuntimeCB* /* rcb */,
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
    RuntimeCB* /* rcb */,
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
    RuntimeCB* /* rcb */,
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
    RuntimeCB* /* rcb */,
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
    RuntimeCB* /* rcb */,
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
    RuntimeCB* /* rcb */,
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
    RuntimeCB* /* rcb */,
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
    RuntimeCB* /* rcb */,
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
    RuntimeCB* /* rcb */,
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
    RuntimeCB* /* rcb */,
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
    RuntimeCB* /* rcb */,
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
    RuntimeCB* /*rcb*/,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  xqp_decimal ld0 = i0->getDecimalValue();
  xqp_decimal ld1 = i1->getDecimalValue();
  if ( ld1 == Integer::parseInt(0) )
  {
    ZORBA_ERROR_LOC_DESC( FOAR0001, *loc, "Division by zero (decimals)");
  }
  return GENV_ITEMFACTORY->createDecimal (result,  ld0 / ld1 );
}


template<>
bool DivideOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER>(
    store::Item_t& result,
    RuntimeCB* /* rcb */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1 )
{
  xqp_decimal ll0 = Decimal::parseInteger(i0->getIntegerValue());
  xqp_decimal ll1 = Decimal::parseInteger(i1->getIntegerValue());
  if ( ll1 == Integer::parseInt(0) )
  {
    ZORBA_ERROR_LOC_DESC( FOAR0001, *loc, "Division by zero (decimals)");
  }
  return GENV_ITEMFACTORY->createDecimal (result,  ll0 / ll1 );
}


/*******************************************************************************
  IntegerDivideOperation (see runtime/core/arithmetic_impl.h/cpp)
********************************************************************************/
template<>
bool IntegerDivideOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DOUBLE>(
    store::Item_t& result,
    RuntimeCB* /* rcb */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1 )
{
  if (i0->isNaN() || i1->isNaN()) {
    ZORBA_ERROR_LOC_DESC( FOAR0002, *loc,
                          "Division with doubles must not be done with NaNs");
  }
  if (i0->isPosOrNegInf()) {
    ZORBA_ERROR_LOC_DESC( FOAR0002, *loc,
                          "Division must not be done with a +-INF dividend");
  }

  if (i0->isPosOrNegInf()) {
    // idiv with +-INF divisor has 0 as result
    return GENV_ITEMFACTORY->createInteger(result, Integer::parseInt((int32_t)0));
  }
  
  xqp_double d0 = i0->getDoubleValue();
  xqp_double d1 = i1->getDoubleValue();

  if ( d1 == Double::parseInt(0) )
  {
    ZORBA_ERROR_LOC_DESC( FOAR0001, *loc, "Division by zero (decimals)");
  }

  xqp_integer lInteger;
  bool lBool = Integer::parseDouble( d0 / d1, lInteger);
  ZORBA_ASSERT(lBool);

  return GENV_ITEMFACTORY->createInteger (result,  lInteger );
}


template<>
bool IntegerDivideOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT>(
    store::Item_t& result,
    RuntimeCB* /* rcb */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  if (i0->isNaN() || i1->isNaN()) 
  {
    ZORBA_ERROR_LOC_DESC(FOAR0002, *loc,
                          "Integer Division with floats must not be done with NaNs");
  }
  if (i0->isPosOrNegInf()) 
  {
    ZORBA_ERROR_LOC_DESC(FOAR0002, *loc,
                         "Integer division must not be done with a +-INF dividend");
  }
  if (i0->isPosOrNegInf()) 
  {
    // idiv with +-INF divisor has 0 as result
    return GENV_ITEMFACTORY->createInteger(result, Integer::parseInt((int32_t)0));
  }

  xqp_float f0 = i0->getFloatValue();
  xqp_float f1 = i1->getFloatValue();
  if ( f1 == xqp_float::parseInt(0) )
  {
    ZORBA_ERROR_LOC_DESC( FOAR0001, *loc, "Division by zero (decimals)");
  }
  xqp_integer lInteger;
  bool lBool = Integer::parseFloat( f0 / f1, lInteger);
  ZORBA_ASSERT(lBool);

  return GENV_ITEMFACTORY->createInteger(result, lInteger);
}


template<>
bool IntegerDivideOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL>(
    store::Item_t& result,
    RuntimeCB* /* rcb */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1 )
{
  xqp_decimal ld0 = i0->getDecimalValue();
  xqp_decimal ld1 = i1->getDecimalValue();

  if ( ld1 == Decimal::parseInt(0) )
  {
    ZORBA_ERROR_LOC_DESC( FOAR0001, *loc, "Division by zero (decimals)");
  }
  return GENV_ITEMFACTORY->createInteger(result, Integer::parseDecimal(ld0 / ld1));
}


template<>
bool IntegerDivideOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER>(
    store::Item_t& result,
    RuntimeCB* /* rcb */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1 )
{
  xqp_integer ll0 = i0->getIntegerValue();
  xqp_integer ll1 = i1->getIntegerValue();

  if ( ll1 == Integer::parseInt(0) )
  {
    ZORBA_ERROR_LOC_DESC( FOAR0001, *loc, "Division by zero (decimals)");
  }
  return GENV_ITEMFACTORY->createInteger (result, ll0 / ll1);
}


/*******************************************************************************
  ModOperation (see runtime/core/arithmetic_impl.h/cpp)
********************************************************************************/
template<>
bool ModOperation::compute<TypeConstants::XS_DOUBLE, TypeConstants::XS_DOUBLE>(
    store::Item_t& result,
    RuntimeCB* /* rcb */,
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
    RuntimeCB* /* rcb */,
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
    RuntimeCB* /* rcb */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  xqp_decimal ld0 = i0->getDecimalValue();
  xqp_decimal ld1 = i1->getDecimalValue();

  if ( ld1 == Decimal::parseInt(0) )
  {
    ZORBA_ERROR_LOC_DESC(FOAR0001, *loc, "Modulo by zero (decimals)");
  }
  return GENV_ITEMFACTORY->createDecimal(result,  ld0 % ld1);
}


template<>
bool ModOperation::compute<TypeConstants::XS_INTEGER, TypeConstants::XS_INTEGER>(
    store::Item_t& result,
    RuntimeCB* /* rcb */,
    const TypeManager* /* tm */,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  xqp_integer ll0 = i0->getIntegerValue();
  xqp_integer ll1 = i1->getIntegerValue();

  if ( ll1 == Integer::parseInt(0) )
  {
    ZORBA_ERROR_LOC_DESC(FOAR0001, *loc, "Modulo by zero (decimals)");
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

  if (consumeNext(n0, this->theChild0.getp(), planState))
  {
    if (consumeNext(n1, this->theChild1.getp(), planState))
    {
      res = compute(result,
                    planState.theRuntimeCB,
                    this->theSctx->get_typemanager(),
                    this->loc,
                    n0,
                    n1);
      
      if (consumeNext(n0, this->theChild0.getp(), planState) ||
          consumeNext(n1, this->theChild1.getp(), planState))
        ZORBA_ERROR_DESC(XPTY0004,
                         "Arithmetic operation has a sequence longer than one as an operand.");
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
    RuntimeCB* rcb,
    const TypeManager* tm,
    const QueryLoc& aLoc, 
    store::Item_t& n0,
    store::Item_t& n1)
{
  assert(n0->isAtomic());
  assert(n1->isAtomic());

  xqtref_t type0 = tm->create_value_type(n0);
  xqtref_t type1 = tm->create_value_type(n1);

  return computeAtomic(result, rcb, tm, aLoc, n0, type0, n1, type1);
}

  
template < class Operation >
bool NumArithIterator<Operation>::computeAtomic(
    store::Item_t& result,
    RuntimeCB* rcb,
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

  xqtref_t resultType = TypeOps::arithmetic_type(*type0, *type1, isDivision);

  try
  {
    switch (TypeOps::get_atomic_type_code(*resultType))
    {
    case TypeConstants::XS_DOUBLE:
    {
      GenericCast::castToAtomic(n0, item0, &*resultType, *tm);
      GenericCast::castToAtomic(n1, item1, &*resultType, *tm);

      res = Operation::template
            computeSingleType<TypeConstants::XS_DOUBLE>
            (result, rcb, tm, &aLoc, n0, n1 );
      break;
    }
    case TypeConstants::XS_FLOAT:
    {
      GenericCast::castToAtomic(n0, item0, &*resultType, *tm);
      GenericCast::castToAtomic(n1, item1, &*resultType, *tm);

      res = Operation::template 
            computeSingleType<TypeConstants::XS_FLOAT>
            (result, rcb, tm, &aLoc, n0, n1);
      break;
    }
    case TypeConstants::XS_DECIMAL:
    {
      GenericCast::castToAtomic(n0, item0, &*resultType, *tm);
      GenericCast::castToAtomic(n1, item1, &*resultType, *tm);

      res = Operation::template
            computeSingleType<TypeConstants::XS_DECIMAL>
            (result, rcb, tm, &aLoc,n0, n1);
      break;
    }
    case TypeConstants::XS_INTEGER:
    {
      GenericCast::castToAtomic(n0, item0, &*resultType, *tm);
      GenericCast::castToAtomic(n1, item1, &*resultType, *tm);

       res = Operation::template 
            computeSingleType<TypeConstants::XS_INTEGER>
            (result, rcb, tm, &aLoc, n0, n1 );
      break;
    }
    default:
    {
      ZORBA_ERROR_LOC_DESC_OSS(XPTY0004, aLoc,
                               "Numeric operation not defined between the given types ("
                               << type0->toString() << " and "
                               << type1->toString() << ").");
    }
    }
  }
  catch(error::ZorbaError& e)
  {
    // rethrow casting errors but with location
    ZORBA_ERROR_LOC_DESC(e.theErrorCode , aLoc, e.theDescription);
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

  if (consumeNext( n0, this->theChild0.getp(), planState ))
  {
    if (consumeNext( n1, this->theChild1.getp(), planState ))
    {
      res = compute(result,
                    planState.theRuntimeCB,
                    this->theSctx->get_typemanager(),
                    this->loc,
                    n0.getp(),
                    n1.getp());
      
      if (consumeNext(n0, this->theChild0.getp(), planState) ||
          consumeNext(n1, this->theChild1.getp(), planState))
        ZORBA_ERROR_DESC(XPTY0004,
                         "Arithmetic operation has a sequence longer than one as an operand.");
      STACK_PUSH ( res, state );
    }
  }
  STACK_END (state);
}


template < class Operation, TypeConstants::atomic_type_code_t Type >
bool SpecificNumArithIterator<Operation, Type>::compute(
    store::Item_t& result,
    RuntimeCB* rcb,
    const TypeManager* tm,
    const QueryLoc& aLoc, 
    store::Item *n0,
    store::Item *n1)
{
  assert(n0->isAtomic());
  assert(n1->isAtomic());

  return Operation::template computeSingleType<Type>(result, rcb, tm, &aLoc, n0, n1 );
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

    if ( TypeOps::is_subtype(*type, *rtm.UNTYPED_ATOMIC_TYPE_ONE ) )
    {
      GenericCast::castToAtomic(item, item, &*rtm.DOUBLE_TYPE_ONE, *tm);
      type = rtm.DOUBLE_TYPE_ONE;
    }
    
    // TODO Optimizations (e.g. if item has already the correct type and value,
    // it does not have to be created newly)
    if (TypeOps::is_subtype(*type, *rtm.DOUBLE_TYPE_ONE))
    {
      GENV_ITEMFACTORY->
      createDouble(result,
                   (thePlus ? item->getDoubleValue() : -item->getDoubleValue()));
    }
    else if ( TypeOps::is_subtype ( *type, *rtm.FLOAT_TYPE_ONE ) )
    {
      GENV_ITEMFACTORY->
      createFloat(result,
                  (thePlus ? item->getFloatValue() : -item->getFloatValue()));
    }
    else if ( TypeOps::is_subtype ( *type, *rtm.INTEGER_TYPE_ONE ) )
    {
      GENV_ITEMFACTORY->
      createInteger(result,
                    (thePlus ? item->getIntegerValue() : -item->getIntegerValue()));
    }
    else if ( TypeOps::is_subtype ( *type, *rtm.DECIMAL_TYPE_ONE ) )
    {
      GENV_ITEMFACTORY->
      createDecimal(result,
                   (thePlus ? item->getDecimalValue() : -item->getDecimalValue()));
    }
    else
    {
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc,
                           "Wrong operand type for a unary arithmetic operation.");
    }
    
    if ( consumeNext(item, theChild.getp(), planState ) )
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc,
                           "Arithmetic operation has a sequence longer than one as an operand.");
    STACK_PUSH (true, state );
  }
  STACK_END (state);
}


UNARY_ACCEPT(OpNumericUnaryIterator);


/*******************************************************************************

********************************************************************************/
bool FnAbsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  xqtref_t type;

  const TypeManager& tm = *theSctx->get_typemanager();

  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChildren[0].getp(), planState ))
  {
    assert(result->isAtomic());

    type = tm.create_value_type(result);
    if ( TypeOps::is_subtype(*type, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm);
      type = tm.create_value_type(result);
    }

    if ( TypeOps::is_subtype ( *type, *rtm.DOUBLE_TYPE_ONE ) )
    {
      if ( result->getDoubleValue().isPos() || result->getDoubleValue().isPosZero()  ) 
      {
        if ( !TypeOps::is_equal ( *type, *rtm.DOUBLE_TYPE_ONE ) )
          GENV_ITEMFACTORY->createDouble (result, result->getDoubleValue() );
      }
      else
        GENV_ITEMFACTORY->createDouble (result, -result->getDoubleValue() );
    }
    else if ( TypeOps::is_subtype ( *type, *rtm.FLOAT_TYPE_ONE ) )
      if ( result->getFloatValue().isPos() || result->getFloatValue().isPosZero() ) {
        if ( !TypeOps::is_equal ( *type, *rtm.FLOAT_TYPE_ONE ) )
          GENV_ITEMFACTORY->createFloat (result, result->getFloatValue() );
      }
      else
        GENV_ITEMFACTORY->createFloat (result, -result->getFloatValue() );
    else if ( TypeOps::is_subtype ( *type, *rtm.INTEGER_TYPE_ONE ) )
      if ( result->getIntegerValue() >= xqp_decimal::zero() ) {
        if ( !TypeOps::is_equal ( *type, *rtm.INTEGER_TYPE_ONE ) )
          GENV_ITEMFACTORY->createInteger (result, result->getIntegerValue() );
      }
      else
        GENV_ITEMFACTORY->createInteger (result, -result->getIntegerValue() );
    else if ( TypeOps::is_subtype ( *type, *rtm.DECIMAL_TYPE_ONE ) )
      if ( result->getDecimalValue() >= xqp_decimal::zero() ) {
        if ( !TypeOps::is_equal ( *type, *rtm.DECIMAL_TYPE_ONE ) )
          GENV_ITEMFACTORY->createDecimal (result, result->getDecimalValue() );
      }
      else
        GENV_ITEMFACTORY->createDecimal (result, -result->getDecimalValue() );
    else
    {
      ZORBA_ERROR_LOC_DESC( XPTY0004,
                            loc, "Wrong operand type for fn:abs.");
    }
    
    if ( consumeNext(item, theChildren[0].getp(), planState ))
    {
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc,
                           "fn:abs has a sequence longer than one as an operand.");
    }
    STACK_PUSH ( true, state );
  }
  STACK_END (state);
}


/*******************************************************************************
  6.4.2 fn:ceiling
********************************************************************************/
bool FnCeilingIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  xqtref_t type;
    
  const TypeManager& tm = *theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChildren[0].getp(), planState ))
  {
    //get the value and the type of the item
    assert(result->isAtomic());

    type = tm.create_value_type(result);

    //Parameters of type xs:untypedAtomic are always promoted to xs:double
    if ( TypeOps::is_subtype(*type, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm);
      type = tm.create_value_type(result);
    }
    
    //item type is subtype of DOUBLE
    if ( TypeOps::is_subtype(*type, *rtm.DOUBLE_TYPE_ONE))
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().ceil());
    
    //item type is subtype of FLOAT
    else if ( TypeOps::is_subtype ( *type, *rtm.FLOAT_TYPE_ONE ) )
      GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().ceil());
    
    //item type is subtype of INTEGER 
    else if(TypeOps::is_subtype ( *type, *rtm.INTEGER_TYPE_ONE ))
    { /* do nothing */ }
    
    //item type is subtype of DECIMAL
    else if (TypeOps::is_subtype ( *type, *rtm.DECIMAL_TYPE_ONE ))
      GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().ceil());
    
    else
    {
      ZORBA_ERROR_LOC_DESC( XPTY0004,
                            loc, "Wrong operand type for fn:ceiling.");
    }
    
    if ( consumeNext(item, theChildren[0].getp(), planState ))
    {
      ZORBA_ERROR_LOC_DESC( XPTY0004,
                            loc, "fn:ceiling has a sequence longer than one as an operand.");
    }
    STACK_PUSH ( true, state );
  }
  STACK_END (state);
}


/*******************************************************************************
  6.4.3 fn:floor
********************************************************************************/
bool FnFloorIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  xqtref_t type;
    
  const TypeManager& tm = *theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChildren[0].getp(), planState ))
  {
    //get the value and the type of the item
    assert(result->isAtomic());
    
    type = tm.create_value_type(result);
    
    //Parameters of type xs:untypedAtomic are always promoted to xs:double
    if ( TypeOps::is_subtype(*type, *rtm.UNTYPED_ATOMIC_TYPE_ONE ) )
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm);
      type = tm.create_value_type(result);
    }
    
    //item type is subtype of DOUBLE
    if ( TypeOps::is_subtype ( *type, *rtm.DOUBLE_TYPE_ONE ) )
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().floor());
    
    //item type is subtype of FLOAT
    else if ( TypeOps::is_subtype ( *type, *rtm.FLOAT_TYPE_ONE ) )
      GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().floor());
    
    //item type is subtype of INTEGER 
    else if(TypeOps::is_subtype ( *type, *rtm.INTEGER_TYPE_ONE ))
    { /* do nothing */ }
    
    //item type is subtype of DECIMAL
    else if (TypeOps::is_subtype ( *type, *rtm.DECIMAL_TYPE_ONE ))
      GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().floor());
    
    else
    {
      ZORBA_ERROR_LOC_DESC( XPTY0004,
                            loc, "Wrong operand type for fn:floor.");
    }
    
    if ( consumeNext(item, theChildren[0].getp(), planState ) )
    {
      ZORBA_ERROR_LOC_DESC( XPTY0004,
                            loc, "fn:floor has a sequence longer than one as an operand.");
    }
    STACK_PUSH (true, state );
  }
  STACK_END (state);
}


/*******************************************************************************
  6.4.4 fn:round
********************************************************************************/
bool FnRoundIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  store::Item_t res;
  xqtref_t type;
    
  const TypeManager& tm = *theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChildren[0].getp(), planState ))
  {
    //get the value and the type of the item
    assert(result->isAtomic());
    
    type = tm.create_value_type(result);
    
    //Parameters of type xs:untypedAtomic are always promoted to xs:double
    if ( TypeOps::is_subtype(*type, *rtm.UNTYPED_ATOMIC_TYPE_ONE ) )
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm);
      type = tm.create_value_type(result);
    }
    
    //item type is subtype of DOUBLE
    if ( TypeOps::is_subtype ( *type, *rtm.DOUBLE_TYPE_ONE ) )
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().round());
    
    //item type is subtype of FLOAT
    else if ( TypeOps::is_subtype ( *type, *rtm.FLOAT_TYPE_ONE ) )
      GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().round());
    
    //item type is subtype of INTEGER 
    else if(TypeOps::is_subtype ( *type, *rtm.INTEGER_TYPE_ONE ))
    { /* do nothing */ }
    
    //item type is subtype of DECIMAL
    else if (TypeOps::is_subtype ( *type, *rtm.DECIMAL_TYPE_ONE ))
      GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().round());
    
    else
    {
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc, "Wrong operand type for fn:round.");
    }
    
    if ( consumeNext(item, theChildren[0].getp(), planState ))
    {
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc,
                           "fn:round has a sequence longer than one as an operator.");
    }
    STACK_PUSH (true, state );
  }
  STACK_END (state);
}


/*******************************************************************************
  6.4.5 fn:round-half-to-even
********************************************************************************/
bool FnRoundHalfToEvenIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  store::Item_t itemPrec;
  store::Item_t res;
  xqtref_t type;
  Integer precision = Integer::parseInt((int32_t)0);
  
  const TypeManager& tm = *theSctx->get_typemanager();
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
  
  if (consumeNext(result, theChildren [0].getp(), planState ))
  {
    if (theChildren.size () == 2) 
    {
      consumeNext(itemPrec, theChildren[1].getp(), planState);
      assert(itemPrec->isAtomic());
      
      precision = itemPrec->getIntegerValue();
    }
    
    //get the value and the type of the item
    assert(result->isAtomic());
    
    type = tm.create_value_type (result);
    
    //Parameters of type xs:untypedAtomic are always promoted to xs:double
    if ( TypeOps::is_subtype ( *type, *rtm.UNTYPED_ATOMIC_TYPE_ONE ) )
    {
      GenericCast::castToAtomic(result, result, &*rtm.DOUBLE_TYPE_ONE, tm);
      type = tm.create_value_type (result);
    }
    
    //item type is subtype of DOUBLE
    if ( TypeOps::is_subtype ( *type, *rtm.DOUBLE_TYPE_ONE ) )
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().roundHalfToEven(precision));
    
    //item type is subtype of FLOAT
    else if ( TypeOps::is_subtype ( *type, *rtm.FLOAT_TYPE_ONE ) )
      GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().roundHalfToEven(precision));
    
    //item type is subtype of INTEGER 
    else if(TypeOps::is_subtype ( *type, *rtm.INTEGER_TYPE_ONE ))
    { /* do nothing */ }
    //item type is subtype of DECIMAL
    else if (TypeOps::is_subtype ( *type, *rtm.DECIMAL_TYPE_ONE ))
      GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().roundHalfToEven(precision));
    
    else
    {
      ZORBA_ERROR_LOC_DESC( XPTY0004,
                            loc, "Wrong operand type for fn:round-half-to-even.");
    }
    
    if ( consumeNext(item, theChildren [0].getp(), planState ))
    {
      ZORBA_ERROR_LOC_DESC( XPTY0004,
                            loc, "fn:round-half-to-even has a sequence longer than one as an operand.");
    }
    STACK_PUSH ( true, state );
  }
  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool FnSQRTIterator::nextImpl (store::Item_t& result, PlanState& planState) const 
{
  store::Item_t item;
  xqtref_t type;
    
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChild.getp(), planState ))
  {
    GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().sqrt());

    if ( consumeNext(item, theChild.getp(), planState ))
    {
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc,
                           "fn:sqrt has a sequence longer than one as an operator.");
    }
    
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool FnExpIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, this->theChild.getp(), planState )) 
  {
    GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().exp());
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool FnLogIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, this->theChild.getp(), planState )) 
  {
    GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().log());
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool FnSinIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, this->theChild.getp(), planState )) 
  {
    GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().sin());
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool FnCosIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, this->theChild.getp(), planState )) 
  {
    GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().cos());
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool FnTanIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, this->theChild.getp(), planState )) 
  {
    GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().tan());
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool FnArcSinIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, this->theChild.getp(), planState )) 
  {
    GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().asin());
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool FnArcCosIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, this->theChild.getp(), planState )) 
  {
    GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().acos());
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool FnArcTanIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, this->theChild.getp(), planState )) 
  {
    GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().atan());
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/
bool FnAtan2Iterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  store::Item_t n0;
  store::Item_t n1;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(n0, this->theChild0.getp(), planState))
  {
    if (consumeNext(n1, this->theChild1.getp(), planState))
    {
      {
        xqp_double doub1 = n0->getDoubleValue();
        xqp_double doub2 = n1->getDoubleValue();

        GENV_ITEMFACTORY->createDouble(result, doub1.atan2(doub2));
      }

      if (consumeNext(n0, this->theChild0.getp(), planState) ||
          consumeNext(n1, this->theChild1.getp(), planState))
        ZORBA_ERROR_DESC(XPTY0004,
                         "Atan2 function has a sequence longer than one as an operand.");
      STACK_PUSH(true, state);
    }
  }

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool FnCoshIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChild.getp(), planState )) 
  {
    GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().cosh());
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/
bool FnAcoshIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChild.getp(), planState )) 
  {
    GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().acosh());
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/
bool FnFmodIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  store::Item_t n0;
  store::Item_t n1;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(n0, this->theChild0.getp(), planState))
  {
    if (consumeNext(n1, this->theChild1.getp(), planState))
    {
      {
        xqp_double doub1 = n0->getDoubleValue();
        xqp_double doub2 = n1->getDoubleValue();

        GENV_ITEMFACTORY->createDouble(result, doub1.fmod(doub2));
      }

      if (consumeNext(n0, this->theChild0.getp(), planState) ||
          consumeNext(n1, this->theChild1.getp(), planState))
        ZORBA_ERROR_DESC(XPTY0004,
                         "Fmod function has a sequence longer than one as an operand.");
      STACK_PUSH(true, state);
    }
  }

  STACK_END(state);
}

/*******************************************************************************

********************************************************************************/
bool FnFrexpIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  FnFrexpState* state;
  DEFAULT_STACK_INIT ( FnFrexpState, state, planState );

  if (consumeNext(result, theChild.getp(), planState )) 
  {
    {
      xqp_double    doub = result->getDoubleValue();
      xqp_double    doub_mantissa;
      doub.frexp(doub_mantissa, state->int_exponent);
      GENV_ITEMFACTORY->createDouble(result, doub_mantissa);
    }
    STACK_PUSH (true, state);
    GENV_ITEMFACTORY->createInteger(result, state->int_exponent);
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/
bool FnLdexpIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  store::Item_t n0;
  store::Item_t n1;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(n0, this->theChild0.getp(), planState))
  {
    if (consumeNext(n1, this->theChild1.getp(), planState))
    {
      {
        xqp_integer integ = n1->getIntegerValue();
        xqp_double  doub = n0->getDoubleValue();
        xqp_integer integ_2 = Integer::parseInt(2);
        xqp_double doub_pow = integ_2.pow(integ);

        GENV_ITEMFACTORY->createDouble(result, doub * doub_pow);
      }

      if (consumeNext(n0, this->theChild0.getp(), planState) ||
          consumeNext(n1, this->theChild1.getp(), planState))
        ZORBA_ERROR_DESC(XPTY0004,
                         "Ldexp function has a sequence longer than one as an operand.");
      STACK_PUSH(true, state);
    }
  }

  STACK_END(state);
}

/*******************************************************************************

********************************************************************************/
bool FnLog10Iterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChild.getp(), planState )) 
  {
    GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().log10());
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/
bool FnPiIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  GENV_ITEMFACTORY->createDouble(result, 3.1415926535897932384626433832795);
  STACK_PUSH (true, state);

  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/
bool FnModfIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  FnModfState* state;
  DEFAULT_STACK_INIT ( FnModfState, state, planState );

  if (consumeNext(result, theChild.getp(), planState )) 
  {
    {
      xqp_double    doub = result->getDoubleValue();
      xqp_double    doub_fraction;
      doub.modf(doub_fraction, state->doub_integer);
      GENV_ITEMFACTORY->createDouble(result, doub_fraction);
    }
    STACK_PUSH (true, state);
    GENV_ITEMFACTORY->createDouble(result, state->doub_integer);
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/
bool FnPowIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  store::Item_t n0;
  store::Item_t n1;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(n0, this->theChild0.getp(), planState))
  {
    if (consumeNext(n1, this->theChild1.getp(), planState))
    {
      {
        xqp_double doub1 = n0->getDoubleValue();
        xqp_double  doub2 = n1->getDoubleValue();

        GENV_ITEMFACTORY->createDouble(result, doub1.pow(doub2));
      }

      if (consumeNext(n0, this->theChild0.getp(), planState) ||
          consumeNext(n1, this->theChild1.getp(), planState))
        ZORBA_ERROR_DESC(XPTY0004,
                         "Pow function has a sequence longer than one as an operand.");
      STACK_PUSH(true, state);
    }
  }

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool FnSinhIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChild.getp(), planState )) 
  {
    GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().sinh());
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/
bool FnAsinhIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChild.getp(), planState )) 
  {
    GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().asinh());
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/
bool FnTanhIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChild.getp(), planState )) 
  {
    GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().tanh());
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/
bool FnAtanhIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChild.getp(), planState )) 
  {
    GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().atanh());
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/
bool FnIsInfIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChild.getp(), planState )) 
  {
    GENV_ITEMFACTORY->createBoolean(result, !result->getDoubleValue().isFinite());
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/
bool FnIsNaNIterator::nextImpl (store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (consumeNext(result, theChild.getp(), planState )) 
  {
    GENV_ITEMFACTORY->createBoolean(result, result->getDoubleValue().isNaN());
    STACK_PUSH (true, state);
  }
  STACK_END (state);
}




/*******************************************************************************

********************************************************************************/
void ZorNumGenState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  this->curNumber = 0;
}


void ZorNumGenState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  this->curNumber = 0;
}


int32_t ZorNumGenState::getCurNumber()
{
  return this->curNumber;
}


void ZorNumGenState::setCurNumber ( int32_t value )
{
  this->curNumber = value;
}


bool
ZorNumGen::nextImpl ( store::Item_t& result, PlanState& planState ) const
{
  ZorNumGenState* state;
  DEFAULT_STACK_INIT ( ZorNumGenState, state, planState );
  
  while ( state->getCurNumber() < 100 )
  {
    STACK_PUSH (
                GENV_ITEMFACTORY->createInteger (result, Integer::parseInt(state->getCurNumber()) ),
                state );
    state->setCurNumber ( state->getCurNumber() + 1 );
  }
  STACK_END (state);
}


NOARY_ACCEPT(ZorNumGen);


/*******************************************************************************

********************************************************************************/
static const char* decimal_separator_param = "decimal-separator";
static const char* grouping_separator_param = "grouping-separator";
static const char* infinity_param = "infinity";
static const char* minus_sign_param = "minus-sign";
static const char* nan_param = "NaN";
static const char* percent_param = "percent";
static const char* per_mille_param = "per-mille";
static const char* zero_digit_param = "zero-digit";
static const char* digit_param = "digit";
static const char* pattern_separator_param = "pattern-separator";


class FormatNumberInfo
{
public:
  QueryLoc loc;
  // Separators
  xqpStringStore_t decimal_separator;
  xqpStringStore_t grouping_separator;
  xqpStringStore_t percent;
  xqpStringStore_t per_mille;
  xqpStringStore_t zero_digit;
  xqpStringStore_t digit_sign;
  xqpStringStore_t pattern_separator;
  xqpStringStore_t infinity;
  xqpStringStore_t NaN;
  xqpStringStore_t minus;

  class PartInfo
  {
  public:
    xqpStringStore_t str;
    std::vector<int> grouping_pos;
    int N;
    int minimum_size;
    int maximum_size;
    PartInfo() : str(new xqpStringStore()), N(-1), minimum_size(0), maximum_size(0) {};
  };

  class SubPictureInfo
  {
  public:
    xqpStringStore_t str;
    xqpStringStore_t prefix;
    xqpStringStore_t suffix;
    PartInfo integer_part;
    PartInfo fractional_part;
    SubPictureInfo() : str(new xqpStringStore()), prefix(new xqpStringStore()), suffix(new xqpStringStore()) {};
  } pos_subpicture, neg_subpicture;
  
  FormatNumberInfo()
  {
    decimal_separator = new xqpStringStore(".");
    grouping_separator = new xqpStringStore(",");
    percent = new xqpStringStore("%");
    xqpString temp;
    temp = (uint32_t)0x2030;    
    per_mille = temp.theStrStore;
    zero_digit = new xqpStringStore("0");
    digit_sign = new xqpStringStore("#");
    pattern_separator = new xqpStringStore(";");
    infinity = new xqpStringStore("Infinity");
    NaN = new xqpStringStore("NaN");
    minus = new xqpStringStore("-");
  }

  void readFormat(const DecimalFormat_t& df_t)
  {
    if (df_t.isNull())
      return;

    const DecimalFormat::param_vector_type* params = df_t->getParamVector();

    for ( DecimalFormat::param_vector_type::const_iterator it = params->begin(); it != params->end(); it++)
    {
      if (it->first == decimal_separator_param)
        decimal_separator = new xqpStringStore(it->second);
      else if (it->first == grouping_separator_param)
        grouping_separator = new xqpStringStore(it->second);
      else if (it->first == infinity_param)
        infinity = new xqpStringStore(it->second);
      else if (it->first == minus_sign_param)
        minus = new xqpStringStore(it->second);
      else if (it->first == nan_param)
        NaN = new xqpStringStore(it->second);
      else if (it->first == percent_param)
        percent = new xqpStringStore(it->second);
      else if (it->first == per_mille_param)
        per_mille = new xqpStringStore(it->second);
      else if (it->first == zero_digit_param)
        zero_digit = new xqpStringStore(it->second);
      else if (it->first == digit_param)
        digit_sign = new xqpStringStore(it->second);
      else if (it->first == pattern_separator_param)
        pattern_separator = new xqpStringStore(it->second);
    }
  }
};


// returns an error if there are two or more instances of the given pattern in the string
template <typename T>
static void errorIfTwoOrMore(xqpStringStore& part, T sep, QueryLoc& loc)
{
  int pos = part.indexOf(sep);
  if (pos != -1)
    if (part.indexOf(sep, pos+1) != -1)
      ZORBA_ERROR_LOC(XTDE1310, loc);
}


static void parsePart(
    FormatNumberInfo& info,
    FormatNumberInfo::PartInfo& part,
    bool fractional = false)
{
  xqpStringStore& str = *part.str;
  if (str.size() == 0)
    return;

  errorIfTwoOrMore(str, info.percent->c_str(), info.loc);
  errorIfTwoOrMore(str, info.per_mille->c_str(), info.loc);

  if (str.indexOf(info.percent->c_str()) != -1 && str.indexOf(info.per_mille->c_str()) != -1)
    ZORBA_ERROR_LOC(XTDE1310, info.loc);

  if (str.indexOf(info.digit_sign->c_str()) == -1 && str.indexOf(info.zero_digit->c_str()) == -1)
    ZORBA_ERROR_LOC(XTDE1310, info.loc);

  // get grouping separators
  int digit_signs = 0;
  int zero_signs = 0;
  int start = fractional? 0 : str.numChars()-1;
  int end = fractional? str.numChars() : -1;
  int delta = fractional? 1 : -1;  
  int first_digit_sign = -1;
  int last_zero_sign = -1;
  while (start != end)
  {
    xqpStringStore::char_type ch = str.charAt(start);
    if (*info.digit_sign == ch)
    {
      if (first_digit_sign == -1)
        first_digit_sign = start;
      digit_signs++;
    }
    else if (*info.zero_digit == ch)
    {
      last_zero_sign = start;
      zero_signs++;
    }
    else if (*info.grouping_separator == ch)
      part.grouping_pos.push_back(digit_signs+zero_signs);
    start += delta;
  }

  if (first_digit_sign != -1 && last_zero_sign != -1
      &&
      ((!fractional && first_digit_sign > last_zero_sign)
        ||
        (fractional && first_digit_sign < last_zero_sign)))
    ZORBA_ERROR_LOC(XTDE1310, info.loc);

  if (part.grouping_pos.size() > 0 && part.grouping_pos[0] == 0)
    ZORBA_ERROR_LOC(XTDE1310, info.loc);

  if (part.grouping_pos.size() > 0)
  {
    part.N = part.grouping_pos[0];
    for (unsigned int i=1; i<part.grouping_pos.size(); i++)
      if ((part.grouping_pos[i] % part.N) != 0)
      {
        part.N = -1;
        break;
      }
  }
 
  part.minimum_size = zero_signs;
  if (!fractional && zero_signs == 0 && str.indexOf(info.decimal_separator->c_str()) == -1)
    part.minimum_size = 1;

  if (fractional)
    part.maximum_size = digit_signs + zero_signs;
}


static void parseSubpicture(
    FormatNumberInfo::SubPictureInfo& sub_picture,
    FormatNumberInfo& info)
{
  int chars;
  xqpStringStore& str = *sub_picture.str;
  if (str.size() == 0)
    return;

  errorIfTwoOrMore(str, info.decimal_separator->c_str(), info.loc);
  int pos = str.indexOf(info.decimal_separator->c_str());
  if (pos != -1)
  {
    sub_picture.integer_part.str = str.substr(0, pos);
    sub_picture.fractional_part.str = str.substr(pos+1, str.size()-pos);
  }
  else
    sub_picture.integer_part.str = &str;

  parsePart(info, sub_picture.integer_part);
  parsePart(info, sub_picture.fractional_part, true);

  // prefix
  xqpStringStore_t temp = sub_picture.integer_part.str;
  chars = temp->numChars();
  for (int i = 0; i < chars; i++)
  {
    xqpStringStore::char_type ch = temp->charAt(i);
    if (*info.decimal_separator == ch || *info.grouping_separator == ch || *info.zero_digit == ch 
      || *info.digit_sign == ch || *info.pattern_separator == ch || i == chars-1)
    {
      sub_picture.prefix = temp->substr(0, i);
      break;
    }
  }
  // suffix
  temp = sub_picture.fractional_part.str;
  chars = temp->numChars();
  for (int i=chars-1; i >= 0; i--)
  {
    xqpStringStore::char_type ch = temp->charAt(i);
    if (*info.decimal_separator == ch || *info.grouping_separator == ch || *info.zero_digit == ch 
      || *info.digit_sign == ch || *info.pattern_separator == ch || i == 0)
    {
      sub_picture.suffix = temp->substr(i+1, chars-i-1);
      break;
    }
  }
}

static void parsePicture(xqpStringStore& picture, FormatNumberInfo& info)
{
  errorIfTwoOrMore(picture, info.pattern_separator->c_str(), info.loc);

  int pos = picture.indexOf(info.pattern_separator->c_str());
  if (pos != -1)
  {
    info.pos_subpicture.str = picture.substr(0, pos);
    info.neg_subpicture.str = picture.substr(pos+1, picture.size() - pos);
  }
  else 
    info.pos_subpicture.str = &picture;

  parseSubpicture(info.pos_subpicture, info);
  if (info.neg_subpicture.str->size() == 0)
  {
    info.neg_subpicture = info.pos_subpicture;
    xqpStringStore_t temp(info.minus);
    temp->append_in_place(info.pos_subpicture.prefix);
    info.neg_subpicture.prefix = temp;
  }
  else
    parseSubpicture(info.neg_subpicture, info);
}

static bool isAllowedType(store::Item* type_qname)
{
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  if (type_qname->equals(rtm.XS_FLOAT_QNAME)     
    || type_qname->equals(rtm.XS_DOUBLE_QNAME)
    || type_qname->equals(rtm.XS_DECIMAL_QNAME)
    || type_qname->equals(rtm.XS_INTEGER_QNAME)
    || type_qname->equals(rtm.XS_NON_POSITIVE_INTEGER_QNAME)
    || type_qname->equals(rtm.XS_NEGATIVE_INTEGER_QNAME)
    || type_qname->equals(rtm.XS_LONG_QNAME)
    || type_qname->equals(rtm.XS_INT_QNAME)
    || type_qname->equals(rtm.XS_SHORT_QNAME)
    || type_qname->equals(rtm.XS_BYTE_QNAME)
    || type_qname->equals(rtm.XS_NON_NEGATIVE_INTEGER_QNAME)
    || type_qname->equals(rtm.XS_UNSIGNED_LONG_QNAME)
    || type_qname->equals(rtm.XS_UNSIGNED_INT_QNAME)
    || type_qname->equals(rtm.XS_UNSIGNED_SHORT_QNAME)
    || type_qname->equals(rtm.XS_UNSIGNED_BYTE_QNAME)
    || type_qname->equals(rtm.XS_POSITIVE_INTEGER_QNAME))
    return true;
  else
    return false;
}

// returns n zeros "0". n can be 0 and then the function will return ""
static xqpStringStore_t createZeros(int n)
{
  xqpStringStore_t result = new xqpStringStore("");
  for (int i=0; i<n; i++)
    result->append_in_place("0");
  return result;
}


static void formatGroupings(
    xqpStringStore_t& result,
    xqpStringStore_t& str,
    FormatNumberInfo::PartInfo& part,
    FormatNumberInfo& info)
{
  unsigned int grouping_index = 0;
  result = new xqpStringStore();
  int len = str->numChars();
  for (int i = len-1; i >= 0; i--)
  {
    xqpStringStore::char_type ch = str->charAt(i);

    if (((grouping_index < part.grouping_pos.size()
        &&
        len-i-1 == part.grouping_pos[grouping_index])
      || 
      (part.N != -1 
        &&
        len-1-i != 0
        &&
        ((len-1-i) % part.N) == 0))
      &&
      ch != '-')
    {
      result->append_in_place(info.grouping_separator);
      if (grouping_index < part.grouping_pos.size())
        grouping_index++;
      while (grouping_index < part.grouping_pos.size()
          &&
          part.grouping_pos[grouping_index] == part.grouping_pos[grouping_index-1])
      {
        result->append_in_place(info.grouping_separator);
        grouping_index++;
      }
    }

    if (ch == '0')
      result->append_in_place(info.zero_digit);
    else if (ch == '-')
      ; // skip the '-' sign
    else
      result->append_in_place(ch);
  }
}


static void formatNumber(
    xqpStringStore& resultString,
    store::Item_t& number,
    FormatNumberInfo& info,
    const TypeManager* tm)
{
  const RootTypeManager& rtm = GENV_TYPESYSTEM;

  if (number->isNaN())
  {
    resultString.append_in_place(info.NaN);
    return;
  }

  store::Item_t zero;
  store::Item_t doubleItem;
  bool positive = true;
  FormatNumberInfo::SubPictureInfo& sub_picture = info.pos_subpicture;

  GENV_ITEMFACTORY->createDouble(zero, xqp_double::zero());

  GenericCast::castToAtomic(doubleItem, number, &*rtm.DOUBLE_TYPE_ONE, *tm);

  if (doubleItem->compare(zero) == -1)
  {
    positive = false;
    sub_picture = info.neg_subpicture;
  }

  if (doubleItem->isPosOrNegInf())
  {
    resultString.append_in_place(sub_picture.prefix);
    resultString.append_in_place(info.infinity);
    resultString.append_in_place(sub_picture.suffix);
    return;
  }

  xqp_double adjusted = doubleItem->getDoubleValue();
  if (sub_picture.str->indexOf(info.percent->c_str()) != -1)
    adjusted = adjusted * Double::parseInt(100);
  else if (sub_picture.str->indexOf(info.per_mille->c_str()) != -1)
    adjusted = adjusted * Double::parseInt(1000);

  adjusted = adjusted.roundHalfToEven(Integer::parseInt(sub_picture.fractional_part.maximum_size));
  xqpStringStore_t converted = adjusted.toString(true).theStrStore;
  
  // process min sizes
  xqpStringStore_t integer_part, fractional_part;
  int pos = converted->indexOf(".");
  if (pos == -1)
  {
    integer_part = converted;
    fractional_part = new xqpStringStore("");
  }
  else
  {
    integer_part = converted->substr(0, pos);
    fractional_part = converted->substr(pos+1, converted->numChars() - pos + 1);
  }

  // Add zeros
  xqpStringStore_t temp = createZeros(sub_picture.integer_part.minimum_size - integer_part->numChars());
  temp->append_in_place(integer_part);
  integer_part = temp;  
  fractional_part->append_in_place(createZeros(sub_picture.fractional_part.minimum_size - fractional_part->numChars()));

  // groupings
  xqpStringStore_t integer_part_result, fractional_part_result;
  formatGroupings(integer_part_result, integer_part, sub_picture.integer_part, info);
  integer_part_result = integer_part_result->reverse();
  fractional_part = fractional_part->reverse();
  formatGroupings(fractional_part_result, fractional_part, sub_picture.fractional_part, info);

  resultString.append_in_place(sub_picture.prefix);
  resultString.append_in_place(integer_part_result);
  if (fractional_part->numChars() != 0)
  {
    resultString.append_in_place(info.decimal_separator);
    resultString.append_in_place(fractional_part_result);
  }
  resultString.append_in_place(sub_picture.suffix);
}


bool FnFormatNumberIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  xqpStringStore_t resultString, pictureString;
  store::Item_t numberItem, pictureItem, formatName;
  FormatNumberInfo info;
  DecimalFormat_t df_t;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

  if (planState.theCompilerCB->theRootSctx->xquery_version() == StaticContextConsts::xquery_version_1_0)
    ZORBA_ERROR_LOC_DESC(XPST0017, loc, "The format-number() function is only available in the XQuery 1.1 processing mode.");

  if (!consumeNext(result, theChildren[0].getp(), planState ))
  {
    // Got void, returning void
      STACK_PUSH(false, state);
  }
  else
  {
    info.loc = loc;
    if (!isAllowedType(result->getType()))
      ZORBA_ERROR_LOC(XPTY0004, info.loc);

    consumeNext(pictureItem, theChildren[1].getp(), planState);
    
    if (theChildren.size() >= 3 &&
        consumeNext(formatName, theChildren[2].getp(), planState))
      df_t = planState.theCompilerCB->theRootSctx->get_decimal_format(formatName);
    else
      df_t = planState.theCompilerCB->theRootSctx->get_decimal_format(NULL);

    info.readFormat(df_t);
    
    pictureString = pictureItem->getStringValue();
    resultString = new xqpStringStore();
    parsePicture(*pictureString, info);
    formatNumber(*resultString, result, info, theSctx->get_typemanager());

    STACK_PUSH (GENV_ITEMFACTORY->createString(result, resultString), state);
  }
  STACK_END (state);
}

} /* namespace zorba */
