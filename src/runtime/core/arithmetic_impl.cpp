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

#include "runtime/core/arithmetic_impl.h"
#include "zorbaerrors/error_manager.h"
#include "system/globalenv.h"
#include "compiler/parser/query_loc.h"
#include "types/root_typemanager.h"
#include "types/casting.h"
#include "zorbaerrors/Assert.h"
#include "runtime/numerics/NumericsImpl.h"
#include "runtime/dateTime/DurationsDatesTimes.h"
#include "zorbaerrors/error_manager.h"
#include "store/api/item_factory.h"
#include "context/dynamic_context.h"
#include "runtime/api/runtimecb.h"
#include "types/typeops.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"
#include "context/static_context.h"

namespace zorba {

void ArithOperationsCommons::createError(
  RuntimeCB* aRuntimeCB,
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
  aRuntimeCB->theStaticContext->get_typemanager()->create_atomic_type(aType0, TypeConstants::QUANT_ONE)->serialize(lStream);
  lStream << " and ";
  aRuntimeCB->theStaticContext->get_typemanager()->create_atomic_type(aType1, TypeConstants::QUANT_ONE)->serialize(lStream);
  lStream << ".";
  ZORBA_ERROR_LOC_DESC( XPTY0004, *aLoc, lStream.str());
}

/* begin class GenericArithIterator */
template< class Operations>
GenericArithIterator<Operations>::GenericArithIterator
( const QueryLoc& loc, PlanIter_t& iter0, PlanIter_t& iter1 )
    :
    BinaryBaseIterator<GenericArithIterator<Operations>, PlanIteratorState > ( loc, iter0, iter1 )
{ }

template < class Operation >
bool GenericArithIterator<Operation>::nextImpl ( store::Item_t& result, PlanState& planState ) const
{
  store::Item_t n0;
  store::Item_t n1;
  bool status;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
  if (consumeNext( n0, this->theChild0.getp(), planState ))
  {
    if (consumeNext( n1, this->theChild1.getp(), planState ))
    {
      status = compute(result, planState.theRuntimeCB, this->loc, n0, n1);
    
      if ( consumeNext(n0, this->theChild0.getp(), planState )
           || consumeNext(n1, this->theChild1.getp(), planState ))
        ZORBA_ERROR_LOC_DESC( XPTY0004, this->loc, 
                    "An input to the Arithmetic operation has a sequences that is greater than one.");
      STACK_PUSH ( status, state );
    }
  }
  STACK_END (state);
}

template < class Operation >
bool GenericArithIterator<Operation>::compute(store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc& aLoc, 
                                                store::Item_t& n0, store::Item_t& n1)
{
  store::Item_t an0 = n0->getAtomizationValue();
  store::Item_t an1 = n1->getAtomizationValue();

  xqtref_t type0 = aRuntimeCB->theStaticContext->get_typemanager()->
                   create_value_type (an0);

  xqtref_t type1 = aRuntimeCB->theStaticContext->get_typemanager()->
                   create_value_type (an1);
  
  if (TypeOps::is_numeric(*type0)
      &&
      (TypeOps::is_subtype ( *type1, *GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE )
      ||
      TypeOps::is_subtype ( *type1, *GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE )))
  {
    GenericCast::instance()->castToAtomic(an0, an0, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
    if (TypeOps::is_subtype ( *type1, *GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE ))
      return Operation::template compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_YM_DURATION>(result, aRuntimeCB, &aLoc, an0, an1);
    else
      return Operation::template compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DT_DURATION>(result, aRuntimeCB, &aLoc, an0, an1);
  }
  else if (TypeOps::is_subtype ( *type0, *GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE )
      &&
      TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.TIME_TYPE_ONE))
  {
    return Operation::template compute<TypeConstants::XS_DURATION,TypeConstants::XS_TIME> (result, aRuntimeCB, &aLoc, an0, an1);
  }
  else if (TypeOps::is_subtype ( *type0, *GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE ))
  {
    if(TypeOps::is_numeric(*type1))
    {
      GenericCast::instance()->castToAtomic ( an1, an1, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
      return Operation::template compute<TypeConstants::XS_YM_DURATION,TypeConstants::XS_DOUBLE> ( result, aRuntimeCB, &aLoc, an0, an1 );
    }
    else if (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE))
      return Operation::template compute<TypeConstants::XS_DURATION,TypeConstants::XS_DATETIME> (result, aRuntimeCB, &aLoc, an0, an1);
    else if (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DATE_TYPE_ONE))
      return Operation::template compute<TypeConstants::XS_DURATION,TypeConstants::XS_DATE> (result, aRuntimeCB, &aLoc, an0, an1);
    else if (TypeOps::is_equal(*type0, *type1))
      return Operation::template computeSingleType<TypeConstants::XS_YM_DURATION> ( result, aRuntimeCB, &aLoc, an0, an1 );
  }
  else if (TypeOps::is_subtype ( *type0, *GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE ))
  {
    if(TypeOps::is_numeric(*type1))
    {
      GenericCast::instance()->castToAtomic ( an1, an1, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
      return Operation::template compute<TypeConstants::XS_DT_DURATION,TypeConstants::XS_DOUBLE> ( result, aRuntimeCB, &aLoc, an0, an1 );
    }
    else if (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE))
      return Operation::template compute<TypeConstants::XS_DURATION,TypeConstants::XS_DATETIME> (result, aRuntimeCB, &aLoc, an0, an1);
    else if (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DATE_TYPE_ONE))
      return Operation::template compute<TypeConstants::XS_DURATION,TypeConstants::XS_DATE> (result, aRuntimeCB, &aLoc, an0, an1);
    else if (TypeOps::is_equal(*type0, *type1))
      return Operation::template computeSingleType<TypeConstants::XS_DT_DURATION> ( result, aRuntimeCB, &aLoc, an0, an1 );
  }
  else if(TypeOps::is_subtype ( *type0, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE ))
  {
    if(TypeOps::is_subtype ( *type1, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE ))
      return Operation::template compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DATETIME> (  result, aRuntimeCB, &aLoc, an0, an1 );
    else if (TypeOps::is_subtype ( *type1, *GENV_TYPESYSTEM.DURATION_TYPE_ONE ))
      return Operation::template compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DURATION> (  result, aRuntimeCB, &aLoc, an0, an1 );
  }
  else if(TypeOps::is_subtype ( *type0, *GENV_TYPESYSTEM.DATE_TYPE_ONE ))
  {
    if (TypeOps::is_subtype ( *type1, *GENV_TYPESYSTEM.DATE_TYPE_ONE ))
      return Operation::template compute<TypeConstants::XS_DATE,TypeConstants::XS_DATE> (  result, aRuntimeCB, &aLoc, an0, an1 );
    else if (TypeOps::is_subtype ( *type1, *GENV_TYPESYSTEM.DURATION_TYPE_ONE ))
      return Operation::template compute<TypeConstants::XS_DATE,TypeConstants::XS_DURATION> (  result, aRuntimeCB, &aLoc, an0, an1 );
  }
  else if(TypeOps::is_subtype ( *type0, *GENV_TYPESYSTEM.TIME_TYPE_ONE ))
  {
    if(TypeOps::is_subtype ( *type1, *GENV_TYPESYSTEM.TIME_TYPE_ONE ))
      return Operation::template compute<TypeConstants::XS_TIME,TypeConstants::XS_TIME> (  result, aRuntimeCB, &aLoc, an0, an1 );
    else if (TypeOps::is_subtype ( *type1, *GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE))
      return Operation::template compute<TypeConstants::XS_TIME,TypeConstants::XS_DURATION> (  result, aRuntimeCB, &aLoc, an0, an1 );
  }
  else if ((TypeOps::is_numeric(*type0)
           || TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
           && ( TypeOps::is_numeric(*type1)
           || TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)))
  {
    return NumArithIterator<Operation>::computeAtomic( result, aRuntimeCB, aLoc, an0, type0, an1, type1);
  }
  
  ZORBA_ERROR_LOC_DESC(XPTY0004, aLoc,
                       "Arithmetic operation not defined between the given types("
                       + type0->toString() + " and " + type1->toString() + ").");
  
  return 0;
}

/**
 * Information: It is not possible to move this function to
 * runtime/visitors/accept.cpp!
 */
template < class Operation >
void GenericArithIterator<Operation>::accept(PlanIterVisitor& v) const { 
  v.beginVisit(*this); 
  this->theChild0->accept(v); 
  this->theChild1->accept(v); 
  v.endVisit(*this); 
}

// FIXME Why can the following template specializations not be moved to src/runtime/dateTime/DurationsDatesTimes.cpp?
//moved from DurationsDatesTimes
 
/* begin class AddOperations */
template<>
bool AddOperation::compute<TypeConstants::XS_YM_DURATION,TypeConstants::XS_YM_DURATION>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_yearMonthDuration* d = (xqp_yearMonthDuration*)(i0->getYearMonthDurationValue() + i1->getYearMonthDurationValue()).getp();
  return GENV_ITEMFACTORY->createYearMonthDuration(result, d);
}

template<>
bool AddOperation::compute<TypeConstants::XS_DT_DURATION,TypeConstants::XS_DT_DURATION>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_dayTimeDuration* d = (xqp_dayTimeDuration*)(i0->getDayTimeDurationValue() + i1->getDayTimeDurationValue()).getp();
  return GENV_ITEMFACTORY->createDayTimeDuration(result, d);
}

template<>
bool AddOperation::compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DURATION>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_dateTime* d = i0->getDateTimeValue().addDuration(*i1->getDurationValue().toDuration());
  return GENV_ITEMFACTORY->createDateTime(result, d);
}

template<>
bool AddOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DATETIME>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_dateTime* d = i1->getDateTimeValue().addDuration(*i0->getDurationValue().toDuration());
  return GENV_ITEMFACTORY->createDateTime (result, d);
}

template<>
bool AddOperation::compute<TypeConstants::XS_DATE,TypeConstants::XS_DURATION>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_date* d = i0->getDateValue().addDuration(*i1->getDurationValue().toDuration());
  return GENV_ITEMFACTORY->createDate (result, d);
}

template<>
bool AddOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DATE>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_date* d = i1->getDateValue().addDuration(*i0->getDurationValue().toDuration());
  return GENV_ITEMFACTORY->createDate (result, d);
}

template<>
bool AddOperation::compute<TypeConstants::XS_TIME,TypeConstants::XS_DURATION>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_time* t = i0->getTimeValue().addDuration(*i1->getDurationValue().toDuration());
  return GENV_ITEMFACTORY->createTime (result, t);
}

template<>
bool AddOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_TIME>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_time* t = i1->getTimeValue().addDuration(*i0->getDurationValue().toDuration());
  return GENV_ITEMFACTORY->createTime (result, t);
}

 /* end class AddOperations */

/* start class SubtractOperations */
template<>
bool SubtractOperation::compute<TypeConstants::XS_YM_DURATION,TypeConstants::XS_YM_DURATION>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_yearMonthDuration* d = (xqp_yearMonthDuration*)(i0->getYearMonthDurationValue() - i1->getYearMonthDurationValue()).getp();
  return GENV_ITEMFACTORY->createYearMonthDuration(result, d);
}

template<>
bool SubtractOperation::compute<TypeConstants::XS_DT_DURATION,TypeConstants::XS_DT_DURATION>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_dayTimeDuration* d = (xqp_dayTimeDuration*)(i0->getDayTimeDurationValue() - i1->getDayTimeDurationValue()).getp();
  return GENV_ITEMFACTORY->createDayTimeDuration(result, d);
}

template<>
bool SubtractOperation::compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DURATION>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_dateTime* d = i0->getDateTimeValue().subtractDuration(*i1->getDurationValue().toDuration());
  return GENV_ITEMFACTORY->createDateTime (result, d);
}


template<>
bool SubtractOperation::compute<TypeConstants::XS_DATE,TypeConstants::XS_DURATION>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_date* d = i0->getDateValue().subtractDuration(*i1->getDurationValue().toDuration());
  return GENV_ITEMFACTORY->createDate (result, d);
}


template<>
bool SubtractOperation::compute<TypeConstants::XS_TIME,TypeConstants::XS_DURATION>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_time* t = i0->getTimeValue().subtractDuration(*i1->getDurationValue().toDuration());
  return GENV_ITEMFACTORY->createTime (result, t);
}


template<>
bool SubtractOperation::compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DATETIME>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_dayTimeDuration* d;
  try {
    d = (xqp_dayTimeDuration*)i0->getDateTimeValue().subtractDateTime(&i1->getDateTimeValue(),
                                                 aRuntimeCB->theDynamicContext->get_implicit_timezone()).getp();
  }
  catch (InvalidTimezoneException) {
    ZORBA_ERROR(FODT0003);
  }
  return GENV_ITEMFACTORY->createDayTimeDuration(result, d);
}


template<>
bool SubtractOperation::compute<TypeConstants::XS_DATE,TypeConstants::XS_DATE>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_dayTimeDuration* d;
  try 
  {
    d = (xqp_dayTimeDuration*)i0->getTimeValue().subtractDateTime(&i1->getTimeValue(),
                                             aRuntimeCB->theDynamicContext->get_implicit_timezone()).getp();
  }
  catch (InvalidTimezoneException) 
  {
    ZORBA_ERROR(FODT0003);
  }
  return GENV_ITEMFACTORY->createDayTimeDuration(result, d);
}


template<>
bool SubtractOperation::compute<TypeConstants::XS_TIME,TypeConstants::XS_TIME>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_dayTimeDuration* d;
  try {
    d = (xqp_dayTimeDuration*)i0->getTimeValue().subtractDateTime(&i1->getTimeValue(),
                         aRuntimeCB->theDynamicContext->get_implicit_timezone()).getp();
  }
  catch (InvalidTimezoneException) {
    ZORBA_ERROR(FODT0003);
  }
  return GENV_ITEMFACTORY->createDayTimeDuration(result, d);
}
/* end class SubtractOperations */


/* start class MultiplyOperations */
template<>
bool MultiplyOperation::compute<TypeConstants::XS_YM_DURATION,TypeConstants::XS_DOUBLE>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
{
  xqp_yearMonthDuration* d;
  
  if ( i1->getDoubleValue().isPosInf() || i1->getDoubleValue().isNegInf() )
    ZORBA_ERROR_DESC( FODT0002,  "Overflow/underflow in duration operation.");
  else if (  i1->getDoubleValue().isNaN() )
    ZORBA_ERROR_DESC( FOCA0005,  "NaN supplied as float/double value");
  else
    d = (xqp_yearMonthDuration*)(i0->getYearMonthDurationValue() * (i1->getDoubleValue())).getp();
  
  return GENV_ITEMFACTORY->createYearMonthDuration(result, d);
}

template<>
bool MultiplyOperation::compute<TypeConstants::XS_DT_DURATION,TypeConstants::XS_DOUBLE>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
{
  xqp_dayTimeDuration* d;
  
  if ( i1->getDoubleValue().isPosInf() || i1->getDoubleValue().isNegInf() )
    ZORBA_ERROR_DESC( FODT0002,  "Overflow/underflow in duration operation.");
  else if (  i1->getDoubleValue().isNaN() )
    ZORBA_ERROR_DESC( FOCA0005,  "NaN supplied as float/double value");
  else
    d = (xqp_dayTimeDuration*)(i0->getDayTimeDurationValue() * (i1->getDoubleValue())).getp();
  
  return GENV_ITEMFACTORY->createDayTimeDuration(result, d);
}

template<>
bool MultiplyOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_YM_DURATION>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
{
  return MultiplyOperation::compute<TypeConstants::XS_YM_DURATION,TypeConstants::XS_DOUBLE>(result, aRuntimeCB, loc, i1, i0);
}

template<>
bool MultiplyOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DT_DURATION>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
{
  return MultiplyOperation::compute<TypeConstants::XS_DT_DURATION,TypeConstants::XS_DOUBLE>(result, aRuntimeCB, loc, i1, i0);
}
/* end class MultiplyOperations */

/* start class DivideOperations */
template<>
bool DivideOperation::compute<TypeConstants::XS_YM_DURATION,TypeConstants::XS_DOUBLE>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
{
  xqp_yearMonthDuration* d;

  if( i1->getDoubleValue().isPosInf() || i1->getDoubleValue().isNegInf() )
  {
    d = new YearMonthDuration();
  }
  else if ( i1->getDoubleValue().isZero() )
    ZORBA_ERROR_DESC( FODT0002,  "Overflow/underflow in duration operation.");
  else if ( i1->getDoubleValue().isNaN() )
    ZORBA_ERROR_DESC( FOCA0005,  "NaN supplied as float/double value");
  else
    d = (xqp_yearMonthDuration*)(i0->getYearMonthDurationValue() / i1->getDoubleValue()).getp();

  return GENV_ITEMFACTORY->createYearMonthDuration(result, d);
}

template<>
bool DivideOperation::compute<TypeConstants::XS_DT_DURATION,TypeConstants::XS_DOUBLE>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
{
  xqp_dayTimeDuration* d;

  if( i1->getDoubleValue().isPosInf() || i1->getDoubleValue().isNegInf() )
  {
    d = new DayTimeDuration();
  }
  else if ( i1->getDoubleValue().isZero() )
    ZORBA_ERROR_DESC( FODT0002,  "Overflow/underflow in duration operation.");
  else if ( i1->getDoubleValue().isNaN() )
    ZORBA_ERROR_DESC( FOCA0005,  "NaN supplied as float/double value");
  else
    d = (xqp_dayTimeDuration*)(i0->getDayTimeDurationValue() / i1->getDoubleValue()).getp();

  return GENV_ITEMFACTORY->createDayTimeDuration(result, d);
}

template<>
bool DivideOperation::compute<TypeConstants::XS_YM_DURATION,TypeConstants::XS_YM_DURATION>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
{
  xqp_decimal d = i0->getYearMonthDurationValue() / i1->getYearMonthDurationValue();
  return GENV_ITEMFACTORY->createDecimal(result, d);
}

template<>
bool DivideOperation::compute<TypeConstants::XS_DT_DURATION,TypeConstants::XS_DT_DURATION>
( store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
{
  xqp_decimal d = i0->getDayTimeDurationValue() / i1->getDayTimeDurationValue();
  return GENV_ITEMFACTORY->createDecimal(result, d);
}

/* end class DivideOperations */

/* instantiate GenericArithIterator for all types */
template class GenericArithIterator<AddOperation>;
template class GenericArithIterator<SubtractOperation>;
template class GenericArithIterator<MultiplyOperation>;
template class GenericArithIterator<DivideOperation>;
template class GenericArithIterator<IntegerDivideOperation>;
template class GenericArithIterator<ModOperation>;
/* end class GenericArithIterator */


}
