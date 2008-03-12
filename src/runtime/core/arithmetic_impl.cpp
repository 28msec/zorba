#include <sstream>
#include <zorba/item.h>

#include "runtime/core/arithmetic_impl.h"
#include "errors/error_factory.h"
#include "system/globalenv.h"
#include "types/root_typemanager.h"
#include "types/casting.h"
#include "util/Assert.h"
#include "runtime/numerics/NumericsImpl.h"
#include "runtime/dateTime/DurationsDatesTimes.h"
#include "errors/error_factory.h"
#include "system/zorba.h"
#include "store/api/item_factory.h"
#include "system/zorba_engine.h"
#include "context/dynamic_context.h"

namespace zorba {

void ArithOperationsCommons::createError(
  const char* aOp, 
  const QueryLoc* aLoc, 
  TypeConstants::atomic_type_code_t aType0,
  TypeConstants::atomic_type_code_t aType1
)
{
  AtomicXQType lAType0(aType0, TypeConstants::QUANT_ONE);
  AtomicXQType lAType1(aType1, TypeConstants::QUANT_ONE);
  std::stringstream lStream;
  lStream << "The operation '";
  lStream << aOp;
  lStream << "' is not possible with parameters of the type ";
  lAType0.serialize(lStream);
  lStream << " and ";
  lAType1.serialize(lStream);
  lStream << "!";
  ZORBA_ERROR_ALERT(
    ZorbaError::XPTY0004,
    aLoc,
    DONT_CONTINUE_EXECUTION,
    lStream.str()
  );
}

/* begin class GenericArithIterator */
template< class Operations>
GenericArithIterator<Operations>::GenericArithIterator
( const QueryLoc& loc, PlanIter_t& iter0, PlanIter_t& iter1 )
    :
    BinaryBaseIterator<GenericArithIterator<Operations>, PlanIteratorState > ( loc, iter0, iter1 )
{ }

template < class Operation >
store::Item_t GenericArithIterator<Operation>::nextImpl ( PlanState& planState ) const
{
  store::Item_t n0;
  store::Item_t n1;
  store::Item_t res;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
  n0 = consumeNext( this->theChild0.getp(), planState );
  if ( n0 != NULL )
  {
    n1 = consumeNext( this->theChild1.getp(), planState );
    if ( n1 != NULL )
    {
      res = compute(this->loc, n0, n1);
    
      if ( consumeNext(this->theChild0.getp(), planState ) != NULL
           || consumeNext(this->theChild1.getp(), planState ) != NULL )
        ZORBA_ERROR_ALERT(ZorbaError::XPTY0004,
            NULL, DONT_CONTINUE_EXECUTION, "Arithmetic operation has a sequences greater than one as an operator.");
      STACK_PUSH ( res, state );
    }
  }
  STACK_END();
}

template < class Operation >
store::Item_t GenericArithIterator<Operation>::compute(const QueryLoc& aLoc, store::Item_t n0, store::Item_t n1)
{
  n0 = n0->getAtomizationValue();
  n1 = n1->getAtomizationValue();

  xqtref_t type0 = GENV_TYPESYSTEM.create_type ( n0->getType(), TypeConstants::QUANT_ONE );
  xqtref_t type1 = GENV_TYPESYSTEM.create_type ( n1->getType(), TypeConstants::QUANT_ONE );

  if(GENV_TYPESYSTEM.is_subtype ( *type0, *GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE )
     || GENV_TYPESYSTEM.is_subtype ( *type0, *GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE ))
  {
    if(GENV_TYPESYSTEM.is_numeric(*type1))
    {
      n1 = GenericCast::instance()->cast ( n1, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
      return Operation::template compute<TypeConstants::XS_DURATION,TypeConstants::XS_DOUBLE> ( &aLoc, n0, n1 );
    }
    else if(GENV_TYPESYSTEM.is_equal(*type0, *type1))
      return Operation::template computeSingleType<TypeConstants::XS_DURATION> ( &aLoc, n0, n1 );
    else
      ZORBA_ERROR_ALERT(ZorbaError::XPTY0004,
                        NULL, DONT_CONTINUE_EXECUTION, "Arithmetic operation not defined between the given types(" + type0->toString() + " and " + type1->toString() + ").");
  }
  else if(GENV_TYPESYSTEM.is_subtype ( *type0, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE ))
  {
    if(GENV_TYPESYSTEM.is_subtype ( *type1, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE ))
      return Operation::template compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DATETIME> ( &aLoc, n0, n1 );
    else
      return Operation::template compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DURATION> ( &aLoc, n0, n1 );
  }
  else if(GENV_TYPESYSTEM.is_subtype ( *type0, *GENV_TYPESYSTEM.DATE_TYPE_ONE ))
  {
    if(GENV_TYPESYSTEM.is_subtype ( *type1, *GENV_TYPESYSTEM.DATE_TYPE_ONE ))
      return Operation::template compute<TypeConstants::XS_DATE,TypeConstants::XS_DATE> ( &aLoc, n0, n1 );
    else
      return Operation::template compute<TypeConstants::XS_DATE,TypeConstants::XS_DURATION> ( &aLoc, n0, n1 );
  }
  else if(GENV_TYPESYSTEM.is_subtype ( *type0, *GENV_TYPESYSTEM.TIME_TYPE_ONE ))
  {
    if(GENV_TYPESYSTEM.is_subtype ( *type1, *GENV_TYPESYSTEM.TIME_TYPE_ONE ))
      return Operation::template compute<TypeConstants::XS_TIME,TypeConstants::XS_TIME> ( &aLoc, n0, n1 );
    else
      return Operation::template compute<TypeConstants::XS_TIME,TypeConstants::XS_DURATION> ( &aLoc, n0, n1 );
  }
  else if (
           (GENV_TYPESYSTEM.is_numeric(*type0)
           || GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
           && ( GENV_TYPESYSTEM.is_numeric(*type1)
           || GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
          )
  {
    return NumArithIterator<Operation>::computeAtomic(aLoc, n0, type0, n1, type1);
  }
  else
  {
    ZORBA_ERROR_ALERT(ZorbaError::XPTY0004,
                      NULL, DONT_CONTINUE_EXECUTION, "Arithmetic operation not defined between the given types(" + type0->toString() + " and " + type1->toString() + ").");
  }
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
store::Item_t AddOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DURATION>
( const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_duration d = *i0->getDurationValue() + *i1->getDurationValue();
  return Zorba::getItemFactory()->createDuration (d);
}

template<>
store::Item_t AddOperation::compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DURATION>
( const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_dateTime d = *i0->getDateTimeValue() + *i1->getDurationValue()->toDuration();
  return Zorba::getItemFactory()->createDateTime (d);
}

template<>
store::Item_t AddOperation::compute<TypeConstants::XS_DATE,TypeConstants::XS_DURATION>
( const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_date d = *i0->getDateValue() + *i1->getDurationValue()->toDuration();
  return Zorba::getItemFactory()->createDate (d);
}

template<>
store::Item_t AddOperation::compute<TypeConstants::XS_TIME,TypeConstants::XS_DURATION>
( const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_time t = *i0->getTimeValue() + *i1->getDurationValue()->toDuration();
  return Zorba::getItemFactory()->createTime (t);
}
 /* end class AddOperations */

/* start class SubtractOperations */
template<>
store::Item_t SubtractOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DURATION>
( const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
{
  xqp_duration d = *i0->getDurationValue() - *i1->getDurationValue();
  return Zorba::getItemFactory()->createDuration (d);
}

template<>
store::Item_t SubtractOperation::compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DURATION>
( const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_dateTime d = *i0->getDateTimeValue() + *i1->getDurationValue()->toNegDuration();
  return Zorba::getItemFactory()->createDateTime (d);
}

template<>
store::Item_t SubtractOperation::compute<TypeConstants::XS_DATE,TypeConstants::XS_DURATION>
( const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_date d = *i0->getDateValue() + *i1->getDurationValue()->toNegDuration();
  return Zorba::getItemFactory()->createDate (d);
}

template<>
store::Item_t SubtractOperation::compute<TypeConstants::XS_TIME,TypeConstants::XS_DURATION>
( const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_time t = *i0->getTimeValue() + *i1->getDurationValue()->toNegDuration();
  return Zorba::getItemFactory()->createTime (t);
}

template<>
store::Item_t SubtractOperation::compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DATETIME>
( const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  int timezone_secs = ZORBA_FOR_CURRENT_THREAD()->get_base_dynamic_context()->get_implicit_timezone();
  xqp_duration d = *i0->getDateTimeValue()->normalizeTimeZone(timezone_secs) - 
                   *i1->getDateTimeValue()->normalizeTimeZone(timezone_secs);
  return Zorba::getItemFactory()->createDuration (d);
}

template<>
store::Item_t SubtractOperation::compute<TypeConstants::XS_DATE,TypeConstants::XS_DATE>
( const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  long timezone_sec = /*18000;*/ ZORBA_FOR_CURRENT_THREAD()->get_base_dynamic_context()->get_implicit_timezone();
  xqp_duration d = *i0->getDateValue()->normalize(timezone_sec) - *i1->getDateValue()->normalize(timezone_sec);
  return Zorba::getItemFactory()->createDuration (d);
}

template<>
store::Item_t SubtractOperation::compute<TypeConstants::XS_TIME,TypeConstants::XS_TIME>
( const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  long timezone_sec = /*-18000;*/ ZORBA_FOR_CURRENT_THREAD()->get_base_dynamic_context()->get_implicit_timezone();
  xqp_duration d = *i0->getTimeValue()->normalize(timezone_sec) - * i1->getTimeValue()->normalize(timezone_sec);
  return Zorba::getItemFactory()->createDuration (d);
}
/* end class SubtractOperations */

/* start class MultiplyOperations */
template<>
store::Item_t MultiplyOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DOUBLE>
( const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
{
  xqp_duration d;

  if( i1->getDoubleValue().isZero() )
  {
    xqtref_t type0 = GENV_TYPESYSTEM.create_type(i0->getType(), TypeConstants::QUANT_ONE);
    if( GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE))
      d = new YearMonthDuration();
    else
      d = new DayTimeDuration();

    return Zorba::getItemFactory()->createDuration(d);
  }
  else if ( i1->getDoubleValue().isPosInf() || i1->getDoubleValue().isNegInf() )
    ZORBA_ERROR_ALERT( ZorbaError::FODT0002, NULL, DONT_CONTINUE_EXECUTION, "Overflow/underflow in duration operation.");
  else if (  i1->getDoubleValue().isNaN() )
    ZORBA_ERROR_ALERT( ZorbaError::FOCA0005, NULL, DONT_CONTINUE_EXECUTION, "NaN supplied as float/double value");
  else
    d = *i0->getDurationValue() * (i1->getDoubleValue());
  
  return Zorba::getItemFactory()->createDuration (d);
}
/* end class MultiplyOperations */

/* start class DivideOperations */
template<>
store::Item_t DivideOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DOUBLE>
( const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
{
  xqp_duration d;

  if( i1->getDoubleValue().isPosInf() || i1->getDoubleValue().isNegInf() )
  {
    xqtref_t type0 = GENV_TYPESYSTEM.create_type(i0->getType(), TypeConstants::QUANT_ONE);
    if( GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE))
      d = new YearMonthDuration();
    else
      d = new DayTimeDuration();
    
    return Zorba::getItemFactory()->createDuration(d);
  }
  else if ( i1->getDoubleValue().isZero() )
    ZORBA_ERROR_ALERT( ZorbaError::FODT0002, NULL, DONT_CONTINUE_EXECUTION, "Overflow/underflow in duration operation.");
  else if ( i1->getDoubleValue().isNaN() )
    ZORBA_ERROR_ALERT( ZorbaError::FOCA0005, NULL, DONT_CONTINUE_EXECUTION, "NaN supplied as float/double value");
  else
    d= *i0->getDurationValue() / i1->getDoubleValue();

  return Zorba::getItemFactory()->createDuration (d);
}

template<>
store::Item_t DivideOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DURATION>
( const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
{
  xqp_decimal d = *i0->getDurationValue() / *i1->getDurationValue();
  return Zorba::getItemFactory()->createDecimal(d);
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
