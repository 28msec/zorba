#include "runtime/core/arithmetic_impl.h"
#include "errors/error_factory.h"
#include "system/globalenv.h"
#include "types/root_typemanager.h"
#include "types/casting.h"
#include "util/Assert.h"
#include "runtime/numerics/NumericsImpl.h"

namespace xqp {

/* begin class GenericArithIterator */
template< class Operations>
GenericArithIterator<Operations>::GenericArithIterator
( const yy::location& loc, PlanIter_t& iter0, PlanIter_t& iter1 )
    :
    BinaryBaseIterator<GenericArithIterator<Operations>, PlanIteratorState > ( loc, iter0, iter1 )
{ }

template < class Operation >
Item_t GenericArithIterator<Operation>::nextImpl ( PlanState& planState )
{
  Item_t n0;
  Item_t n1;
  Item_t res;

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
Item_t GenericArithIterator<Operation>::compute(const yy::location& aLoc, Item_t n0, Item_t n1)
{
  n0 = n0->getAtomizationValue();
  n1 = n1->getAtomizationValue();

  xqtref_t type0 = GENV_TYPESYSTEM.create_type ( n0->getType(), TypeConstants::QUANT_ONE );
  xqtref_t type1 = GENV_TYPESYSTEM.create_type ( n1->getType(), TypeConstants::QUANT_ONE );

  if ( GENV_TYPESYSTEM.is_numeric(*type0) 
    || GENV_TYPESYSTEM.is_numeric(*type1)
    || GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)
    || GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)) {
    return NumArithIterator<Operation>::computeAtomic(aLoc, n0, type0, n1, type1);
  } else {
    ZORBA_ASSERT(false);
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

/* instantiate GenericArithIterator for all types */
template class GenericArithIterator<AddOperation>;
template class GenericArithIterator<SubtractOperation>;
template class GenericArithIterator<MultiplyOperation>;
template class GenericArithIterator<DivideOperation>;
template class GenericArithIterator<IntegerDivideOperation>;
template class GenericArithIterator<ModOperation>;
/* end class GenericArithIterator */

}
