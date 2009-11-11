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

SERIALIZABLE_CLASS_VERSIONS(ZorNumGen)
END_SERIALIZABLE_CLASS_VERSIONS(ZorNumGen)

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

UNARY_ACCEPT (FnExpIterator);

UNARY_ACCEPT (FnLogIterator);

UNARY_ACCEPT (FnSinIterator);

UNARY_ACCEPT (FnCosIterator);

UNARY_ACCEPT (FnTanIterator);

UNARY_ACCEPT (FnArcSinIterator);

UNARY_ACCEPT (FnArcCosIterator);

UNARY_ACCEPT (FnArcTanIterator);

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


} /* namespace zorba */
