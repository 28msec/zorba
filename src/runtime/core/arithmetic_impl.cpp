#include <sstream>

#include "runtime/core/arithmetic_impl.h"
#include "errors/error_manager.h"
#include "system/globalenv.h"
#include "types/root_typemanager.h"
#include "types/casting.h"
#include "util/Assert.h"
#include "runtime/numerics/NumericsImpl.h"
#include "runtime/dateTime/DurationsDatesTimes.h"
#include "errors/error_manager.h"
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
  ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004, *aLoc, lStream.str());
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
      res = compute(planState.theRuntimeCB, this->loc, n0, n1);
    
      if ( consumeNext(this->theChild0.getp(), planState ) != NULL
           || consumeNext(this->theChild1.getp(), planState ) != NULL )
        ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004, this->loc, 
                    "An input to the Arithmetic operation has a sequences that is greater than one.");
      STACK_PUSH ( res, state );
    }
  }
  STACK_END (state);
}

template < class Operation >
store::Item_t GenericArithIterator<Operation>::compute(RuntimeCB* aRuntimeCB, const QueryLoc& aLoc, 
                                                store::Item_t n0, store::Item_t n1)
{
  n0 = n0->getAtomizationValue();
  n1 = n1->getAtomizationValue();

  xqtref_t type0 = aRuntimeCB->theStaticContext->get_typemanager()->
                   create_value_type (n0);

  xqtref_t type1 = aRuntimeCB->theStaticContext->get_typemanager()->
                   create_value_type (n1);
  
  if (TypeOps::is_subtype ( *type0, *GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE )
      &&
      TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.TIME_TYPE_ONE))
  {
    return Operation::template compute<TypeConstants::XS_DURATION,TypeConstants::XS_TIME> (aRuntimeCB, &aLoc, n0, n1);
  }
  else if (TypeOps::is_subtype ( *type0, *GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE )
     || 
     TypeOps::is_subtype ( *type0, *GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE ))
  {
    if (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE))
    {
      return Operation::template compute<TypeConstants::XS_DURATION,TypeConstants::XS_DATETIME> (aRuntimeCB, &aLoc, n0, n1);
    }
    else if (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DATE_TYPE_ONE))
    {
      return Operation::template compute<TypeConstants::XS_DURATION,TypeConstants::XS_DATE> (aRuntimeCB, &aLoc, n0, n1);
    }
    else if(TypeOps::is_numeric(*type1))
    {
      n1 = GenericCast::instance()->cast ( n1, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
      return Operation::template compute<TypeConstants::XS_DURATION,TypeConstants::XS_DOUBLE> ( aRuntimeCB, &aLoc, n0, n1 );
    }
    else if(TypeOps::is_equal(*type0, *type1))
      return Operation::template computeSingleType<TypeConstants::XS_DURATION> ( aRuntimeCB, &aLoc, n0, n1 );
  }
  else if(TypeOps::is_subtype ( *type0, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE ))
  {
    if(TypeOps::is_subtype ( *type1, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE ))
      return Operation::template compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DATETIME> (  aRuntimeCB, &aLoc, n0, n1 );
    else if (TypeOps::is_subtype ( *type1, *GENV_TYPESYSTEM.DURATION_TYPE_ONE ))
      return Operation::template compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DURATION> (  aRuntimeCB, &aLoc, n0, n1 );
  }
  else if(TypeOps::is_subtype ( *type0, *GENV_TYPESYSTEM.DATE_TYPE_ONE ))
  {
    if (TypeOps::is_subtype ( *type1, *GENV_TYPESYSTEM.DATE_TYPE_ONE ))
      return Operation::template compute<TypeConstants::XS_DATE,TypeConstants::XS_DATE> (  aRuntimeCB, &aLoc, n0, n1 );
    else if (TypeOps::is_subtype ( *type1, *GENV_TYPESYSTEM.DURATION_TYPE_ONE ))
      return Operation::template compute<TypeConstants::XS_DATE,TypeConstants::XS_DURATION> (  aRuntimeCB, &aLoc, n0, n1 );
  }
  else if(TypeOps::is_subtype ( *type0, *GENV_TYPESYSTEM.TIME_TYPE_ONE ))
  {
    if(TypeOps::is_subtype ( *type1, *GENV_TYPESYSTEM.TIME_TYPE_ONE ))
      return Operation::template compute<TypeConstants::XS_TIME,TypeConstants::XS_TIME> (  aRuntimeCB, &aLoc, n0, n1 );
    else if (TypeOps::is_subtype ( *type1, *GENV_TYPESYSTEM.DT_DURATION_TYPE_ONE))
      return Operation::template compute<TypeConstants::XS_TIME,TypeConstants::XS_DURATION> (  aRuntimeCB, &aLoc, n0, n1 );
  }
  else if ((TypeOps::is_numeric(*type0)
           || TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
           && ( TypeOps::is_numeric(*type1)
           || TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)))
  {
    return NumArithIterator<Operation>::computeAtomic( aRuntimeCB, aLoc, n0, type0, n1, type1);
  }
  
  ZORBA_ERROR_LOC_DESC(ZorbaError::XPTY0004, aLoc,
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
store::Item_t AddOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DURATION>
( RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_duration d = *i0->getDurationValue() + *i1->getDurationValue();
  return GENV_ITEMFACTORY->createDuration (d);
}

template<>
store::Item_t AddOperation::compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DURATION>
( RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_dateTime d = i0->getDateTimeValue()->addDuration(*i1->getDurationValue()->toDuration());
  return GENV_ITEMFACTORY->createDateTime (d);
}

template<>
store::Item_t AddOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DATETIME>
( RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_dateTime d = i1->getDateTimeValue()->addDuration(*i0->getDurationValue()->toDuration());
  return GENV_ITEMFACTORY->createDateTime (d);
}

template<>
store::Item_t AddOperation::compute<TypeConstants::XS_DATE,TypeConstants::XS_DURATION>
( RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_date d = i0->getDateValue()->addDuration(*i1->getDurationValue()->toDuration());
  return GENV_ITEMFACTORY->createDate (d);
}

template<>
store::Item_t AddOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DATE>
( RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_date d = i1->getDateValue()->addDuration(*i0->getDurationValue()->toDuration());
  return GENV_ITEMFACTORY->createDate (d);
}

template<>
store::Item_t AddOperation::compute<TypeConstants::XS_TIME,TypeConstants::XS_DURATION>
( RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_time t = i0->getTimeValue()->addDuration(*i1->getDurationValue()->toDuration());
  return GENV_ITEMFACTORY->createTime (t);
}

template<>
store::Item_t AddOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_TIME>
( RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_time t = i1->getTimeValue()->addDuration(*i0->getDurationValue()->toDuration());
  return GENV_ITEMFACTORY->createTime (t);
}

 /* end class AddOperations */

/* start class SubtractOperations */
template<>
store::Item_t SubtractOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DURATION>
( RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
{
  xqp_duration d = *i0->getDurationValue() - *i1->getDurationValue();
  return GENV_ITEMFACTORY->createDuration (d);
}

template<>
store::Item_t SubtractOperation::compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DURATION>
( RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_dateTime d = i0->getDateTimeValue()->subtractDuration(*i1->getDurationValue()->toDuration());
  return GENV_ITEMFACTORY->createDateTime (d);
}

template<>
store::Item_t SubtractOperation::compute<TypeConstants::XS_DATE,TypeConstants::XS_DURATION>
( RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_date d = i0->getDateValue()->subtractDuration(*i1->getDurationValue()->toDuration());
  return GENV_ITEMFACTORY->createDate (d);
}

template<>
store::Item_t SubtractOperation::compute<TypeConstants::XS_TIME,TypeConstants::XS_DURATION>
( RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_time t = i0->getTimeValue()->subtractDuration(*i1->getDurationValue()->toDuration());
  return GENV_ITEMFACTORY->createTime (t);
}

template<>
store::Item_t SubtractOperation::compute<TypeConstants::XS_DATETIME,TypeConstants::XS_DATETIME>
( RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_duration d;
  try {
    d = i0->getDateTimeValue()->subtractDateTime(*i1->getDateTimeValue(),
      aRuntimeCB->theDynamicContext->get_implicit_timezone());
  }
  catch (InvalidTimezoneException) {
    ZORBA_ERROR(ZorbaError::FODT0003);
  }
  return GENV_ITEMFACTORY->createDuration (d);
}

template<>
store::Item_t SubtractOperation::compute<TypeConstants::XS_DATE,TypeConstants::XS_DATE>
( RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_duration d;
  try {
    d = i0->getTimeValue()->subtractDateTime(*i1->getTimeValue(),
                         aRuntimeCB->theDynamicContext->get_implicit_timezone());
  }
  catch (InvalidTimezoneException) {
    ZORBA_ERROR(ZorbaError::FODT0003);
  }
  return GENV_ITEMFACTORY->createDuration (d);
}

template<>
store::Item_t SubtractOperation::compute<TypeConstants::XS_TIME,TypeConstants::XS_TIME>
( RuntimeCB* aRuntimeCB, const QueryLoc* loc,  const store::Item* i0, const store::Item* i1 )
{
  xqp_duration d;
  try {
    d = i0->getTimeValue()->subtractDateTime(*i1->getTimeValue(),
                         aRuntimeCB->theDynamicContext->get_implicit_timezone());
  }
  catch (InvalidTimezoneException) {
    ZORBA_ERROR(ZorbaError::FODT0003);
  }
  return GENV_ITEMFACTORY->createDuration (d);
}
/* end class SubtractOperations */

/* start class MultiplyOperations */
template<>
store::Item_t MultiplyOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DOUBLE>
( RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
{
  xqp_duration d;

  if( i1->getDoubleValue().isZero() )
  {
    xqtref_t type0 = aRuntimeCB->theStaticContext->get_typemanager()->
                     create_value_type (const_cast<store::Item *> (i0));

    if( TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE))
      d = new YearMonthDuration();
    else
      d = new DayTimeDuration();

    return GENV_ITEMFACTORY->createDuration(d);
  }
  else if ( i1->getDoubleValue().isPosInf() || i1->getDoubleValue().isNegInf() )
    ZORBA_ERROR_DESC( ZorbaError::FODT0002,  "Overflow/underflow in duration operation.");
  else if (  i1->getDoubleValue().isNaN() )
    ZORBA_ERROR_DESC( ZorbaError::FOCA0005,  "NaN supplied as float/double value");
  else
    d = *i0->getDurationValue() * (i1->getDoubleValue());
  
  return GENV_ITEMFACTORY->createDuration (d);
}
/* end class MultiplyOperations */

/* start class DivideOperations */
template<>
store::Item_t DivideOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DOUBLE>
( RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
{
  xqp_duration d;

  if( i1->getDoubleValue().isPosInf() || i1->getDoubleValue().isNegInf() )
  {
    xqtref_t type0 = aRuntimeCB->theStaticContext->get_typemanager()->
                     create_value_type (const_cast<store::Item *> (i0));

    if( TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.YM_DURATION_TYPE_ONE))
      d = new YearMonthDuration();
    else
      d = new DayTimeDuration();
    
    return GENV_ITEMFACTORY->createDuration(d);
  }
  else if ( i1->getDoubleValue().isZero() )
    ZORBA_ERROR_DESC( ZorbaError::FODT0002,  "Overflow/underflow in duration operation.");
  else if ( i1->getDoubleValue().isNaN() )
    ZORBA_ERROR_DESC( ZorbaError::FOCA0005,  "NaN supplied as float/double value");
  else
    d= *i0->getDurationValue() / i1->getDoubleValue();

  return GENV_ITEMFACTORY->createDuration (d);
}

template<>
store::Item_t DivideOperation::compute<TypeConstants::XS_DURATION,TypeConstants::XS_DURATION>
( RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
{
  xqp_decimal d = *i0->getDurationValue() / *i1->getDurationValue();
  return GENV_ITEMFACTORY->createDecimal(d);
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
