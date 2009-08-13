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
#include <sstream>


#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/Assert.h"

#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"

#include "system/globalenv.h"

#include "compiler/parser/query_loc.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "types/casting.h"

#include "runtime/core/arithmetic_impl.h"
#include "runtime/numerics/NumericsImpl.h"
#include "runtime/dateTime/DurationsDatesTimes.h"
#include "runtime/api/runtimecb.h"

#include "store/api/item_factory.h"

namespace zorba {

SERIALIZABLE_TEMPLATE_VERSIONS(GenericArithIterator)
END_SERIALIZABLE_TEMPLATE_VERSIONS(GenericArithIterator)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(GenericArithIterator, GenericArithIterator<AddOperation>, 1)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(GenericArithIterator, GenericArithIterator<SubtractOperation>, 2)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(GenericArithIterator, GenericArithIterator<MultiplyOperation>, 3)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(GenericArithIterator, GenericArithIterator<DivideOperation>, 4)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(GenericArithIterator, GenericArithIterator<IntegerDivideOperation>, 5)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS(GenericArithIterator, GenericArithIterator<ModOperation>, 6)

void ArithOperationsCommons::createError(
  RuntimeCB* rcb,
  const TypeManager* tm,
  const char* aOp, 
  const QueryLoc* aLoc, 
  TypeConstants::atomic_type_code_t aType0,
  TypeConstants::atomic_type_code_t aType1
)
{
  std::stringstream lStream;
  lStream << "The operation '";
  lStream << aOp;
  lStream << "' is not possible with parameters of the type ";
  tm->create_builtin_atomic_type(aType0, TypeConstants::QUANT_ONE)->serialize_ostream(lStream);
  lStream << " and ";
  tm->create_builtin_atomic_type(aType1, TypeConstants::QUANT_ONE)->serialize_ostream(lStream);
  lStream << ".";
  ZORBA_ERROR_LOC_DESC( XPTY0004, *aLoc, lStream.str());
}



/*******************************************************************************
  GenericArithIterator
********************************************************************************/

template< class Operations>
GenericArithIterator<Operations>::GenericArithIterator(
    short sctx, 
    const QueryLoc& loc,
    PlanIter_t& iter0,
    PlanIter_t& iter1)
    :
    BinaryBaseIterator<GenericArithIterator<Operations>, GenericArithIteratorState >(sctx, loc, iter0, iter1)
{ 
}


template < class Operation >
void GenericArithIterator<Operation>::openImpl(PlanState& planState, uint32_t& offset)
{
  BinaryBaseIterator<GenericArithIterator<Operation>, GenericArithIteratorState >::
  openImpl(planState, offset);

  GenericArithIteratorState* state = StateTraitsImpl<GenericArithIteratorState>::
  getState(planState, this->stateOffset);

  state->tm = this->getStaticContext(planState)->get_typemanager();
}


template < class Operation >
bool GenericArithIterator<Operation>::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t n0;
  store::Item_t n1;
  bool status;

  GenericArithIteratorState* state;
  DEFAULT_STACK_INIT(GenericArithIteratorState, state, planState);

  if (consumeNext(n0, this->theChild0.getp(), planState))
  {
    if (consumeNext(n1, this->theChild1.getp(), planState))
    {
      status = compute(result, planState.theRuntimeCB, state->tm, this->loc, n0, n1);
    
      if (consumeNext(n0, this->theChild0.getp(), planState) ||
          consumeNext(n1, this->theChild1.getp(), planState))
      {
        ZORBA_ERROR_LOC_DESC(XPTY0004, this->loc, 
        "An operand of an arithmetic operation is a sequences with more than one item.");
      }

      STACK_PUSH ( status, state );
    }
  }

  STACK_END (state);
}


template < class Operation >
bool GenericArithIterator<Operation>::compute(
    store::Item_t& result,
    RuntimeCB* rcb,
    const TypeManager* tm,
    const QueryLoc& aLoc, 
    store::Item_t& n0,
    store::Item_t& n1)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  assert(n0->isAtomic());
  assert(n1->isAtomic());

  xqtref_t type0 = tm->create_value_type(n0);
  xqtref_t type1 = tm->create_value_type(n1);
  
  if (TypeOps::is_numeric(*type0) &&
      (TypeOps::is_subtype(*type1, *rtm.YM_DURATION_TYPE_ONE) ||
       TypeOps::is_subtype(*type1, *rtm.DT_DURATION_TYPE_ONE)))
  {
    GenericCast::castToAtomic(n0, n0, &*rtm.DOUBLE_TYPE_ONE, *tm);

    if (TypeOps::is_subtype(*type1, *rtm.YM_DURATION_TYPE_ONE))
    {
      return Operation::template
             compute<TypeConstants::XS_DOUBLE, TypeConstants::XS_YM_DURATION>
             (result, rcb, tm, &aLoc, n0, n1);
    }
    else
    {
      return Operation::template
             compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DT_DURATION>
             (result, rcb, tm, &aLoc, n0, n1);
    }
  }
  else if (TypeOps::is_subtype(*type0, *rtm.DT_DURATION_TYPE_ONE) &&
           TypeOps::is_subtype(*type1, *rtm.TIME_TYPE_ONE))
  {
    return Operation::template
           compute<TypeConstants::XS_DURATION,TypeConstants::XS_TIME>
           (result, rcb, tm, &aLoc, n0, n1);
  }
  else if (TypeOps::is_subtype(*type0, *rtm.YM_DURATION_TYPE_ONE))
  {
    if(TypeOps::is_numeric(*type1))
    {
      GenericCast::castToAtomic(n1, n1, &*rtm.DOUBLE_TYPE_ONE, *tm);
      return Operation::template
             compute<TypeConstants::XS_YM_DURATION,TypeConstants::XS_DOUBLE>
             (result, rcb, tm, &aLoc, n0, n1);
    }
    else if (TypeOps::is_subtype(*type1, *rtm.DATETIME_TYPE_ONE))
    {
      return Operation::template
             compute<TypeConstants::XS_DURATION,TypeConstants::XS_DATETIME>
             (result, rcb, tm, &aLoc, n0, n1);
    }
    else if (TypeOps::is_subtype(*type1, *rtm.DATE_TYPE_ONE))
    {
      return Operation::template
             compute<TypeConstants::XS_DURATION,TypeConstants::XS_DATE>
             (result, rcb, tm, &aLoc, n0, n1);
    }
    else if (TypeOps::is_equal(*type0, *type1))
    {
      return Operation::template
      computeSingleType<TypeConstants::XS_YM_DURATION>
      (result, rcb, tm, &aLoc, n0, n1);
    }
  }
  else if (TypeOps::is_subtype(*type0, *rtm.DT_DURATION_TYPE_ONE))
  {
    if(TypeOps::is_numeric(*type1))
    {
      GenericCast::castToAtomic(n1, n1, &*rtm.DOUBLE_TYPE_ONE, *tm);

      return Operation::template
             compute<TypeConstants::XS_DT_DURATION,TypeConstants::XS_DOUBLE>
             (result, rcb, tm, &aLoc, n0, n1);
    }
    else if (TypeOps::is_subtype(*type1, *rtm.DATETIME_TYPE_ONE))
    {
      return Operation::template 
             compute<TypeConstants::XS_DURATION,TypeConstants::XS_DATETIME>
             (result, rcb, tm, &aLoc, n0, n1);
    }
    else if (TypeOps::is_subtype(*type1, *rtm.DATE_TYPE_ONE))
    {
      return Operation::template
             compute<TypeConstants::XS_DURATION,TypeConstants::XS_DATE>
             (result, rcb, tm, &aLoc, n0, n1);
    }
    else if (TypeOps::is_equal(*type0, *type1))
    {
      return Operation::template
             computeSingleType<TypeConstants::XS_DT_DURATION>
             (result, rcb, tm, &aLoc, n0, n1);
    }
  }
  else if(TypeOps::is_subtype(*type0, *rtm.DATETIME_TYPE_ONE))
  {
    if(TypeOps::is_subtype(*type1, *rtm.DATETIME_TYPE_ONE))
    {
      return Operation::template
             compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DATETIME>
             (result, rcb, tm, &aLoc, n0, n1);
    }
    else if (TypeOps::is_subtype ( *type1, *rtm.DURATION_TYPE_ONE ))
    {
      return Operation::template
             compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DURATION>
            (result, rcb, tm, &aLoc, n0, n1);
    }
  }
  else if(TypeOps::is_subtype(*type0, *rtm.DATE_TYPE_ONE))
  {
    if (TypeOps::is_subtype(*type1, *rtm.DATE_TYPE_ONE))
    {
      return Operation::template
             compute<TypeConstants::XS_DATE,TypeConstants::XS_DATE>
             (result, rcb, tm, &aLoc, n0, n1);
    }
    else if (TypeOps::is_subtype ( *type1, *rtm.DURATION_TYPE_ONE ))
    {
      return Operation::template
             compute<TypeConstants::XS_DATE,TypeConstants::XS_DURATION>
             (result, rcb, tm, &aLoc, n0, n1);
    }
  }
  else if(TypeOps::is_subtype(*type0, *rtm.TIME_TYPE_ONE))
  {
    if(TypeOps::is_subtype(*type1, *rtm.TIME_TYPE_ONE))
    {
      return Operation::template
             compute<TypeConstants::XS_TIME,TypeConstants::XS_TIME>
             (result, rcb, tm, &aLoc, n0, n1);
    }
    else if (TypeOps::is_subtype(*type1, *rtm.DT_DURATION_TYPE_ONE))
    {
      return Operation::template 
             compute<TypeConstants::XS_TIME,TypeConstants::XS_DURATION>
             (result, rcb, tm, &aLoc, n0, n1);
    }
  }
  else if ((TypeOps::is_numeric(*type0) ||
            TypeOps::is_subtype(*type0, *rtm.UNTYPED_ATOMIC_TYPE_ONE)) &&
           ( TypeOps::is_numeric(*type1) ||
             TypeOps::is_subtype(*type1, *rtm.UNTYPED_ATOMIC_TYPE_ONE)))
  {
    return NumArithIterator<Operation>::
           computeAtomic(result, rcb, tm, aLoc, n0, type0, n1, type1);
  }
  
  ZORBA_ERROR_LOC_DESC(XPTY0004, aLoc,
                       "Arithmetic operation not defined between the given types ("
                       + type0->toString() + " and " + type1->toString() + ").");
  
  return 0;
}


/**
 * Information: It is not possible to move this function to
 * runtime/visitors/accept.cpp!
 */
template < class Operation >
void GenericArithIterator<Operation>::accept(PlanIterVisitor& v) const 
{ 
  v.beginVisit(*this); 
  this->theChild0->accept(v); 
  this->theChild1->accept(v); 
  v.endVisit(*this); 
}


/*******************************************************************************
  AddOperation
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
    const store::Item* i1 )
{
  return GENV_ITEMFACTORY->
         createInteger(result, i0->getIntegerValue() + i1->getIntegerValue());
}


template<>
bool AddOperation::compute<TypeConstants::XS_YM_DURATION,TypeConstants::XS_YM_DURATION>
 ( store::Item_t& result,
   RuntimeCB* rcb,
   const TypeManager* tm,
   const QueryLoc* loc,
   const store::Item* i0,
   const store::Item* i1 )
{
  std::auto_ptr<Duration> d(i0->getYearMonthDurationValue() + i1->getYearMonthDurationValue());
  return GENV_ITEMFACTORY->createYearMonthDuration(result, d.get());
}


template<>
bool AddOperation::compute<TypeConstants::XS_DT_DURATION,TypeConstants::XS_DT_DURATION>
( store::Item_t& result,
  RuntimeCB* rcb,
  const TypeManager* tm,
  const QueryLoc* loc,
  const store::Item* i0,
  const store::Item* i1 )
{
  std::auto_ptr<Duration> d(i0->getDayTimeDurationValue() + i1->getDayTimeDurationValue());
  return GENV_ITEMFACTORY->createDayTimeDuration(result, d.get());
}


template<>
bool AddOperation::compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DURATION>
( store::Item_t& result,
  RuntimeCB* rcb,
  const TypeManager* tm,
  const QueryLoc* loc,
  const store::Item* i0,
  const store::Item* i1 )
{
  std::auto_ptr<xqp_dateTime> d(i0->getDateTimeValue().addDuration(i1->getDurationValue()));
  return GENV_ITEMFACTORY->createDateTime(result, d.get());
}


template<>
bool AddOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DATETIME>
( store::Item_t& result,
  RuntimeCB* rcb,
  const TypeManager* tm,
  const QueryLoc* loc,
  const store::Item* i0,
  const store::Item* i1 )
{
  std::auto_ptr<xqp_dateTime> d(i1->getDateTimeValue().addDuration(i0->getDurationValue()));
  return GENV_ITEMFACTORY->createDateTime(result, d.get());
}


template<>
bool AddOperation::compute<TypeConstants::XS_DATE,TypeConstants::XS_DURATION>
( store::Item_t& result,
  RuntimeCB* rcb,
  const TypeManager* tm,
  const QueryLoc* loc,
  const store::Item* i0,
  const store::Item* i1 )
{
  std::auto_ptr<xqp_date> d = std::auto_ptr<xqp_date>(i0->getDateValue().addDuration(i1->getDurationValue()));
  return GENV_ITEMFACTORY->createDate(result, d.get());
}


template<>
bool AddOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DATE>
( store::Item_t& result,
  RuntimeCB* rcb,
  const TypeManager* tm,
  const QueryLoc* loc,
  const store::Item* i0,
  const store::Item* i1 )
{
  std::auto_ptr<xqp_date> d = std::auto_ptr<xqp_date>(i1->getDateValue().addDuration(i0->getDurationValue()));
  return GENV_ITEMFACTORY->createDate (result, d.get());
}


template<>
bool AddOperation::compute<TypeConstants::XS_TIME,TypeConstants::XS_DURATION>
( store::Item_t& result,
  RuntimeCB* rcb,
  const TypeManager* tm,
  const QueryLoc* loc,
  const store::Item* i0,
  const store::Item* i1 )
{
  std::auto_ptr<xqp_time> t = std::auto_ptr<xqp_time>(i0->getTimeValue().addDuration(i1->getDurationValue()));
  return GENV_ITEMFACTORY->createTime (result, t.get());
}


template<>
bool AddOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_TIME>
( store::Item_t& result,
  RuntimeCB* rcb,
  const TypeManager* tm,
  const QueryLoc* loc,
  const store::Item* i0,
  const store::Item* i1 )
{
  std::auto_ptr<xqp_time> t(i1->getTimeValue().addDuration(i0->getDurationValue()));
  return GENV_ITEMFACTORY->createTime (result, t.get());
}


/*******************************************************************************
  SubtractOperation
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


template<>
bool SubtractOperation::compute<TypeConstants::XS_YM_DURATION,TypeConstants::XS_YM_DURATION>(
    store::Item_t& result,
    RuntimeCB* rcb,
    const TypeManager* tm,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1 )
{
  std::auto_ptr<Duration> d(i0->getYearMonthDurationValue() -
                            i1->getYearMonthDurationValue());

  return GENV_ITEMFACTORY->createYearMonthDuration(result, d.get());
}


template<>
bool SubtractOperation::compute<TypeConstants::XS_DT_DURATION,TypeConstants::XS_DT_DURATION>(
    store::Item_t& result,
    RuntimeCB* rcb,
    const TypeManager* tm,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  std::auto_ptr<Duration> d(i0->getDayTimeDurationValue() -
                            i1->getDayTimeDurationValue());

  return GENV_ITEMFACTORY->createDayTimeDuration(result, d.get());
}


template<>
bool SubtractOperation::compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DURATION>(
    store::Item_t& result,
    RuntimeCB* rcb,
    const TypeManager* tm,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  std::auto_ptr<xqp_dateTime> d(i0->getDateTimeValue().subtractDuration(i1->getDurationValue()));
  return GENV_ITEMFACTORY->createDateTime(result, d.get());
}


template<>
bool SubtractOperation::compute<TypeConstants::XS_DATE,TypeConstants::XS_DURATION>(
    store::Item_t& result,
    RuntimeCB* rcb,
    const TypeManager* tm,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  std::auto_ptr<xqp_date> d(i0->getDateValue().subtractDuration(i1->getDurationValue()));
  return GENV_ITEMFACTORY->createDate(result, d.get());
}


template<>
bool SubtractOperation::compute<TypeConstants::XS_TIME,TypeConstants::XS_DURATION>(
    store::Item_t& result,
    RuntimeCB* rcb,
    const TypeManager* tm,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  std::auto_ptr<xqp_time> t(i0->getTimeValue().subtractDuration(i1->getDurationValue()));
  return GENV_ITEMFACTORY->createTime(result, t.get());
}


template<>
bool SubtractOperation::compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DATETIME>(
    store::Item_t& result,
    RuntimeCB* rcb,
    const TypeManager* tm,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  std::auto_ptr<Duration> d;
  try 
  {
    d.reset(i0->getDateTimeValue().subtractDateTime(&i1->getDateTimeValue(),
                                                    rcb->theDynamicContext->get_implicit_timezone()));
  }
  catch (InvalidTimezoneException) 
  {
    ZORBA_ERROR(FODT0003);
  }
  return GENV_ITEMFACTORY->createDayTimeDuration(result, d.get());
}


template<>
bool SubtractOperation::compute<TypeConstants::XS_DATE,TypeConstants::XS_DATE>(
    store::Item_t& result,
    RuntimeCB* rcb,
    const TypeManager* tm,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  std::auto_ptr<Duration> d;
  try 
  {
    d.reset(i0->getTimeValue().subtractDateTime(&i1->getTimeValue(),
                                                rcb->theDynamicContext->get_implicit_timezone()));
  }
  catch (InvalidTimezoneException) 
  {
    ZORBA_ERROR(FODT0003);
  }
  return GENV_ITEMFACTORY->createDayTimeDuration(result, d.get());
}


template<>
bool SubtractOperation::compute<TypeConstants::XS_TIME,TypeConstants::XS_TIME>(
    store::Item_t& result,
    RuntimeCB* rcb,
    const TypeManager* tm,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  std::auto_ptr<Duration> d;
  try 
  {
    d.reset(i0->getTimeValue().subtractDateTime(&i1->getTimeValue(),
                                                rcb->theDynamicContext->get_implicit_timezone()));
  }
  catch (InvalidTimezoneException) 
  {
    ZORBA_ERROR(FODT0003);
  }
  return GENV_ITEMFACTORY->createDayTimeDuration(result, d.get());
}


/*******************************************************************************
  MultiplyOperation
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


template<>
bool MultiplyOperation::compute<TypeConstants::XS_YM_DURATION,TypeConstants::XS_DOUBLE>(
    store::Item_t& result,
    RuntimeCB* rcb,
    const TypeManager* tm,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  std::auto_ptr<Duration> d;
  
  if ( i1->getDoubleValue().isPosInf() || i1->getDoubleValue().isNegInf() )
    ZORBA_ERROR_DESC( FODT0002,  "Overflow/underflow in duration operation.");
  else if (i1->getDoubleValue().isNaN())
    ZORBA_ERROR_DESC( FOCA0005,  "NaN supplied as float/double value");
  else
    d.reset(i0->getYearMonthDurationValue() * (i1->getDoubleValue()));
  
  return GENV_ITEMFACTORY->createYearMonthDuration(result, d.get());
}


template<>
bool MultiplyOperation::compute<TypeConstants::XS_DT_DURATION,TypeConstants::XS_DOUBLE>(
    store::Item_t& result,
    RuntimeCB* rcb,
    const TypeManager* tm,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  std::auto_ptr<Duration> d;
  
  if ( i1->getDoubleValue().isPosInf() || i1->getDoubleValue().isNegInf() )
    ZORBA_ERROR_DESC( FODT0002,  "Overflow/underflow in duration operation.");
  else if (i1->getDoubleValue().isNaN())
    ZORBA_ERROR_DESC( FOCA0005,  "NaN supplied as float/double value");
  else
    d.reset(i0->getDayTimeDurationValue() * (i1->getDoubleValue()));
  
  return GENV_ITEMFACTORY->createDayTimeDuration(result, d.get());
}


template<>
bool MultiplyOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_YM_DURATION>
( store::Item_t& result,
  RuntimeCB* rcb,
  const TypeManager* tm,
  const QueryLoc* loc,
  const store::Item* i0,
  const store::Item* i1 )
{
  return MultiplyOperation::compute<TypeConstants::XS_YM_DURATION,TypeConstants::XS_DOUBLE>(result, rcb, tm, loc, i1, i0);
}


template<>
bool MultiplyOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DT_DURATION>
( store::Item_t& result,
  RuntimeCB* rcb,
  const TypeManager* tm,
  const QueryLoc* loc,
  const store::Item* i0,
  const store::Item* i1 )
{
  return MultiplyOperation::compute<TypeConstants::XS_DT_DURATION,TypeConstants::XS_DOUBLE>(result, rcb, tm, loc, i1, i0);
}


/*******************************************************************************
  DivideOperation
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


template<>
bool DivideOperation::compute<TypeConstants::XS_YM_DURATION,TypeConstants::XS_DOUBLE>(
    store::Item_t& result,
    RuntimeCB* rcb,
    const TypeManager* tm,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1)
{
  std::auto_ptr<Duration> d;

  if( i1->getDoubleValue().isPosInf() || i1->getDoubleValue().isNegInf() )
  {
    d = std::auto_ptr<Duration>(new Duration(Duration::YEARMONTHDURATION_FACET));
  }
  else if ( i1->getDoubleValue().isZero() )
    ZORBA_ERROR_DESC( FODT0002,  "Overflow/underflow in duration operation.");
  else if ( i1->getDoubleValue().isNaN() )
    ZORBA_ERROR_DESC( FOCA0005,  "NaN supplied as float/double value");
  else
    d = std::auto_ptr<Duration>(i0->getYearMonthDurationValue() / i1->getDoubleValue());

  return GENV_ITEMFACTORY->createYearMonthDuration(result, d.get());
}


template<>
bool DivideOperation::compute<TypeConstants::XS_DT_DURATION,TypeConstants::XS_DOUBLE>
( store::Item_t& result,
  RuntimeCB* rcb,
  const TypeManager* tm,
  const QueryLoc* loc,
  const store::Item* i0,
  const store::Item* i1 )
{
  std::auto_ptr<Duration> d;

  if( i1->getDoubleValue().isPosInf() || i1->getDoubleValue().isNegInf() )
  {
    d.reset(new Duration());
  }
  else if ( i1->getDoubleValue().isZero() )
    ZORBA_ERROR_DESC( FODT0002,  "Overflow/underflow in duration operation.");
  else if ( i1->getDoubleValue().isNaN() )
    ZORBA_ERROR_DESC( FOCA0005,  "NaN supplied as float/double value");
  else
    d.reset(i0->getDayTimeDurationValue() / i1->getDoubleValue());

  return GENV_ITEMFACTORY->createDayTimeDuration(result, d.get());
}


template<>
bool DivideOperation::compute<TypeConstants::XS_YM_DURATION,TypeConstants::XS_YM_DURATION>
( store::Item_t& result,
  RuntimeCB* rcb,
  const TypeManager* tm,
  const QueryLoc* loc,
  const store::Item* i0,
  const store::Item* i1 )
{
  xqp_decimal d = i0->getYearMonthDurationValue() / i1->getYearMonthDurationValue();
  return GENV_ITEMFACTORY->createDecimal(result, d);
}


template<>
bool DivideOperation::compute<TypeConstants::XS_DT_DURATION,TypeConstants::XS_DT_DURATION>(
    store::Item_t& result,
    RuntimeCB* rcb,
    const TypeManager* tm,
    const QueryLoc* loc,
    const store::Item* i0,
    const store::Item* i1 )
{
  xqp_decimal d = i0->getDayTimeDurationValue() / i1->getDayTimeDurationValue();

  return GENV_ITEMFACTORY->createDecimal(result, d);
}


/*******************************************************************************
  IntegerDivideOperation
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
    ZORBA_ERROR_LOC_DESC( FOAR0002, *loc, "Division with doubles must not be done with NaNs");
  }
  if (i0->isPosOrNegInf()) {
    ZORBA_ERROR_LOC_DESC( FOAR0002, *loc, "Division must not be done with a +-INF dividend");
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
  ModOperation
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
  instantiate GenericArithIterator for all types
********************************************************************************/

template class GenericArithIterator<AddOperation>;
template class GenericArithIterator<SubtractOperation>;
template class GenericArithIterator<MultiplyOperation>;
template class GenericArithIterator<DivideOperation>;
template class GenericArithIterator<IntegerDivideOperation>;
template class GenericArithIterator<ModOperation>;


}
