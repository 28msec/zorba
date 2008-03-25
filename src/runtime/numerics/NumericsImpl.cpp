/* *- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: NumericsImpl.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: David Graf
 *
 */

#include "store/api/item.h"

#include "system/globalenv.h"
#include "runtime/numerics/NumericsImpl.h"
#include "util/tracer.h"
#include "types/casting.h"
#include "errors/error_manager.h"
#include "runtime/visitors/planitervisitor.h"
#include "util/Assert.h"
#include "runtime/core/arithmetic_impl.h"
#include "types/typeconstants.h"
#include "types/typeops.h"
#include "store/api/item_factory.h"

namespace zorba
{
  /* begin class AddOperations */
  template<>
  store::Item_t AddOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DOUBLE> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc*,  const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createDouble ( i0->getDoubleValue() + i1->getDoubleValue() );
  }
  template<>
  store::Item_t AddOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc*,  const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createFloat ( i0->getFloatValue() + i1->getFloatValue() );
  }
  template<>
  store::Item_t AddOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc*,  const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createDecimal ( i0->getDecimalValue() + i1->getDecimalValue() );
  }
  template<>
  store::Item_t AddOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createInteger ( i0->getIntegerValue() + i1->getIntegerValue() );
  }
  /* end class AddOperations */

  /* start class SubtractOperations */
  template<>
  store::Item_t SubtractOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DOUBLE> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createDouble ( i0->getDoubleValue() - i1->getDoubleValue() );
  }

  template<>
  store::Item_t SubtractOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createFloat ( i0->getFloatValue() - i1->getFloatValue() );
  }

  template<>
  store::Item_t SubtractOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createDecimal ( i0->getDecimalValue() - i1->getDecimalValue() );
  }

  template<>
  store::Item_t SubtractOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createInteger ( i0->getIntegerValue() - i1->getIntegerValue() );
  }
  /* end class SubtractOperations */

  /* start class MultiplyOperations */
  template<>
  store::Item_t MultiplyOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DOUBLE> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createDouble ( i0->getDoubleValue() * i1->getDoubleValue() );
  }

  template<>
  store::Item_t MultiplyOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createFloat ( i0->getFloatValue() * i1->getFloatValue() );
  }

  template<>
  store::Item_t MultiplyOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createDecimal ( i0->getDecimalValue() * i1->getDecimalValue() );
  }

  template<>
  store::Item_t MultiplyOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createInteger ( i0->getIntegerValue() * i1->getIntegerValue() );
  }
  /* end class MultiplyOperations */

  /* start class DivideOperations */
  template<>
  store::Item_t DivideOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DOUBLE> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createDouble ( i0->getDoubleValue() / i1->getDoubleValue() );
  }

  template<>
  store::Item_t DivideOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createFloat ( i0->getFloatValue() / i1->getFloatValue() );
  }

  template<>
  store::Item_t DivideOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL> 
  ( RuntimeCB* /*aRuntimeCB*/, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
  {
    xqp_decimal ld0 = i0->getDecimalValue();
    xqp_decimal ld1 = i1->getDecimalValue();
    if ( ld1 == Integer::parseInt(0) )
    {
      ZORBA_ERROR_LOC_DESC( ZorbaError::FOAR0001, *loc, "Division by zero (decimals)");
    }
    return GENV_ITEMFACTORY->createDecimal ( ld0 / ld1 );
  }

  template<>
  store::Item_t DivideOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
  {
    xqp_decimal ll0 = Decimal::parseInteger(i0->getIntegerValue());
    xqp_decimal ll1 = Decimal::parseInteger(i1->getIntegerValue());
    if ( ll1 == Integer::parseInt(0) )
    {
      ZORBA_ERROR_LOC_DESC( ZorbaError::FOAR0001, *loc, "Division by zero (decimals)");
    }
    return GENV_ITEMFACTORY->createDecimal ( ll0 / ll1 );
  }
  /* end class DivideOperations */

  /* start class IntegerDivideOperations */
  template<>
  store::Item_t IntegerDivideOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DOUBLE> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
  {
    if (i0->isNaN() || i1->isNaN()) {
      ZORBA_ERROR_LOC_DESC( ZorbaError::FOAR0002, *loc, "Division with doubles must not be done with NaNs");
    }
    if (i0->isPosOrNegInf()) {
      ZORBA_ERROR_LOC_DESC( ZorbaError::FOAR0002, *loc, "Division must not be done with a +-INF dividend");
    }
    if (i0->isPosOrNegInf()) {
      // idiv with +-INF divisor has 0 as result
      return GENV_ITEMFACTORY->createInteger(Integer::parseInt((int32_t)0));
    }

    xqp_double d0 = i0->getDoubleValue();
    xqp_double d1 = i1->getDoubleValue();
    if ( d1 == Double::parseInt(0) )
    {
      ZORBA_ERROR_LOC_DESC( ZorbaError::FOAR0001, *loc, "Division by zero (decimals)");
    }

    xqp_integer lInteger;
    bool lBool = Integer::parseDouble( d0 / d1, lInteger);
    ZORBA_ASSERT(lBool);
    return GENV_ITEMFACTORY->createInteger ( lInteger );
  }

  template<>
  store::Item_t IntegerDivideOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
  {
    if (i0->isNaN() || i1->isNaN() ) {
      ZORBA_ERROR_LOC_DESC( ZorbaError::FOAR0002, *loc, "Integer Division with floats must not be done with NaNs");
    }
    if (i0->isPosOrNegInf()) {
      ZORBA_ERROR_LOC_DESC( ZorbaError::FOAR0002, *loc, "Integer division must not be done with a +-INF dividend");
    }
    if (i0->isPosOrNegInf()) {
      // idiv with +-INF divisor has 0 as result
      return GENV_ITEMFACTORY->createInteger(Integer::parseInt((int32_t)0));
    }

    xqp_float f0 = i0->getFloatValue();
    xqp_float f1 = i1->getFloatValue();
    if ( f1 == xqp_float::parseInt(0) )
    {
      ZORBA_ERROR_LOC_DESC( ZorbaError::FOAR0001, *loc, "Division by zero (decimals)");
    }
    xqp_integer lInteger;
    bool lBool = Integer::parseFloat( f0 / f1, lInteger);
    ZORBA_ASSERT(lBool);
    return GENV_ITEMFACTORY->createInteger ( lInteger );
  }

  template<>
  store::Item_t IntegerDivideOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
  {
    xqp_decimal ld0 = i0->getDecimalValue();
    xqp_decimal ld1 = i1->getDecimalValue();
    if ( ld1 == Decimal::parseInt(0) )
    {
      ZORBA_ERROR_LOC_DESC( ZorbaError::FOAR0001, *loc, "Division by zero (decimals)");
    }
    return GENV_ITEMFACTORY->createInteger (
               Integer::parseDecimal ( ld0 / ld1 )
           );
  }

  template<>
  store::Item_t IntegerDivideOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
  {
    xqp_integer ll0 = i0->getIntegerValue();
    xqp_integer ll1 = i1->getIntegerValue();
    if ( ll1 == Integer::parseInt(0) )
    {
      ZORBA_ERROR_LOC_DESC( ZorbaError::FOAR0001, *loc, "Division by zero (decimals)");
    }
    return GENV_ITEMFACTORY->createInteger (
               ll0 / ll1
           );
  }
  /* end class IntegerDivideOperations */

  /* start class ModOperations */
  template<>
  store::Item_t ModOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DOUBLE> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createDouble ( i0->getDoubleValue() % i1->getDoubleValue() );
  }

  template<>
  store::Item_t ModOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createFloat ( i0->getFloatValue() % i1->getFloatValue() );
  }

  template<>
  store::Item_t ModOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
  {
    xqp_decimal ld0 = i0->getDecimalValue();
    xqp_decimal ld1 = i1->getDecimalValue();
    if ( ld1 == Decimal::parseInt(0) )
    {
      ZORBA_ERROR_LOC_DESC( ZorbaError::FOAR0001,
         *loc, "Modulo by zero (decimals)");
    }
    return GENV_ITEMFACTORY->createDecimal ( ld0 % ld1  );
  }

  template<>
  store::Item_t ModOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER> 
  ( RuntimeCB* /* aRuntimeCB */, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
  {
    xqp_integer ll0 = i0->getIntegerValue();
    xqp_integer ll1 = i1->getIntegerValue();
    if ( ll1 == Integer::parseInt(0) )
    {
      ZORBA_ERROR_LOC_DESC( ZorbaError::FOAR0001, *loc, "Modulo by zero (decimals)");
    }
    return GENV_ITEMFACTORY->createInteger ( ll0 % ll1 );
  }
  /* end class ModOperations */

  /* begin class NumArithIterator */
  template< class Operations>
  NumArithIterator<Operations>::NumArithIterator
  ( const QueryLoc& loc, PlanIter_t& iter0, PlanIter_t& iter1 )
      :
      BinaryBaseIterator<NumArithIterator<Operations>, PlanIteratorState > ( loc, iter0, iter1 )
  { }

  template < class Operation >
  store::Item_t NumArithIterator<Operation>::nextImpl ( PlanState& planState ) const
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
          ZORBA_ERROR_DESC( ZorbaError::XPTY0004, "Arithmetic operation has a sequences greater than one as an operator.");
        STACK_PUSH ( res, state );
      }
    }
    STACK_END (state);
  }

  template < class Operation >
  store::Item_t NumArithIterator<Operation>::compute(RuntimeCB* aRuntimeCB, const QueryLoc& aLoc, 
                                                     store::Item_t n0, store::Item_t n1)
  {
    n0 = n0->getAtomizationValue();
    n1 = n1->getAtomizationValue();

    xqtref_t type0 = GENV_TYPESYSTEM.create_type ( n0->getType(), TypeConstants::QUANT_ONE );
    xqtref_t type1 = GENV_TYPESYSTEM.create_type ( n1->getType(), TypeConstants::QUANT_ONE );

    return computeAtomic(aRuntimeCB, aLoc, n0, type0, n1, type1);
  }
  
  template < class Operation >
  store::Item_t NumArithIterator<Operation>::computeAtomic
    (RuntimeCB* aRuntimeCB, const QueryLoc& aLoc, store::Item_t item0, xqtref_t type0, store::Item_t item1, xqtref_t type1)
  {
    store::Item_t res;
    
    xqtref_t resultType = TypeOps::arithmetic_type ( *type0, *type1 );
    store::Item_t n0 = GenericCast::instance()->cast ( item0, resultType );
    store::Item_t n1 = GenericCast::instance()->cast ( item1, resultType );

    switch ( TypeOps::get_atomic_type_code ( *resultType ) )
    {
      case TypeConstants::XS_DOUBLE:
        res = Operation::template computeSingleType<TypeConstants::XS_DOUBLE> ( aRuntimeCB, &aLoc, n0, n1 );
        break;
      case TypeConstants::XS_FLOAT:
        res = Operation::template computeSingleType<TypeConstants::XS_FLOAT> ( aRuntimeCB, &aLoc,n0, n1 );
        break;
      case TypeConstants::XS_DECIMAL:
        res = Operation::template computeSingleType<TypeConstants::XS_DECIMAL> ( aRuntimeCB, &aLoc,n0, n1 );
        break;
      case TypeConstants::XS_INTEGER:
        res = Operation::template computeSingleType<TypeConstants::XS_INTEGER> ( aRuntimeCB, &aLoc,n0, n1 );
        break;
      default:
        ZORBA_ASSERT(false);
    }
    return res;
  }
  
  /**
   * Information: It is not possible to move this function to
   * runtime/visitors/accept.cpp!
   */
  template < class Operation >
  void NumArithIterator<Operation>::accept(PlanIterVisitor& v) const { 
    v.beginVisit(*this); 
    this->theChild0->accept(v); 
    this->theChild1->accept(v); 
    v.endVisit(*this); 
  }

  /* instantiate NumArithIterator for all types */
  template class NumArithIterator<AddOperation>;
  template class NumArithIterator<SubtractOperation>;
  template class NumArithIterator<MultiplyOperation>;
  template class NumArithIterator<DivideOperation>;
  template class NumArithIterator<IntegerDivideOperation>;
  template class NumArithIterator<ModOperation>;
  /* end class NumArithIterator */

  /*______________________________________________________________________
  |
  | 6.2.1 op:numeric-add
  | op:numeric-add($arg1 as numeric, $arg2 as numeric) as numeric
  |
  | Summary: Backs up the "+" operator and returns the arithmetic sum of
  | its operands: ($arg1 + $arg2).
  |
  | Note:
  | For xs:float or xs:double values, if one of the operands is a zero or
  | a finite number and the other is INF or -INF, INF or -INF is returned.
  | If both operands are INF, INF is returned. If both operands are -INF,
  | -INF is returned. If one of the operands is INF and the other is -INF,
  | NaN is returned.
  |_______________________________________________________________________*/


  /*______________________________________________________________________
  |
  | 6.2.2 op:numeric-subtract
  | op:numeric-subtract($arg1 as numeric, $arg2 as numeric) as numeric
  |
  | Summary: Backs up the "-" operator and returns the arithmetic
  | difference of its operands: ($arg1 - $arg2).
  |
  | Note:
  | For xs:float or xs:double values, if one of the operands is a zero or
  | a finite number and the other is INF or -INF, an infinity of the
  | appropriate sign is returned. If both operands are INF or -INF, NaN is
  | returned. If one of the operands is INF and the other is -INF, an
  | infinity of the appropriate sign is returned.
  |_______________________________________________________________________*/


  /*______________________________________________________________________
  |
  | 6.2.3 op:numeric-multiply
  | op:numeric-multiply($arg1 as numeric, $arg2 as numeric) as numeric
  |
  | Summary: Backs up the "*" operator and returns the arithmetic product
  | of its operands: ($arg1 * $arg2).
  |
  | Note:
  | For xs:float or xs:double values, if one of the operands is a zero and
  | the other is an infinity, NaN is returned. If one of the operands is a
  | non-zero number and the other is an infinity, an infinity with the
  | appropriate sign is returned.
  |_______________________________________________________________________*/


  /*______________________________________________________________________
  |
  | 6.2.4 op:numeric-divide
  | op:numeric-divide($arg1 as numeric, $arg2 as numeric) as numeric
  |
  | Summary: Backs up the "div" operator and returns the arithmetic
  | quotient of its operands: ($arg1 div $arg2).
  |
  | As a special case, if the types of both $arg1 and $arg2 are
  | xs:integer, then the return type is xs:decimal.
  |
  | Notes:
  | For xs:decimal and xs:integer operands, if the divisor is (positive or
  | negative) zero, an error is raised [err:FOAR0001]. For xs:float and
  | xs:double operands, floating point division is performed as specified
  | in [IEEE 754-1985].
  |
  | For xs:float or xs:double values, a positive number divided by
  | positive zero returns INF. A negative number divided by positive zero
  | returns -INF. Division by negative zero returns -INF and INF,
  | respectively. Positive or negative zero divided by positive or
  | negative zero returns NaN. Also, INF or -INF divided by INF or -INF
  | returns NaN.
  |_______________________________________________________________________*/


  /*______________________________________________________________________
  |
  | 6.2.5 op:numeric-integer-divide
  | op:numeric-integer-divide($arg1 as numeric, $arg2 as numeric) as xs:integer
  |
  | Summary: This function backs up the "idiv" operator and performs an
  | integer division: that is, it divides the first argument by the
  | second, and returns the integer obtained by truncating the fractional
  | part of the result. The division is performed so that the sign of the
  | fractional part is the same as the sign of the dividend.
  |
  | If the dividend, $arg1, is not evenly divided by the divisor, $arg2,
  | then the quotient is the xs:integer value obtained, ignoring
  | (truncating) any remainder that results from the division (that is, no
  | rounding is performed). Thus, the semantics " $a idiv $b " are
  | equivalent to " ($a div $b) cast as xs:integer " except for error
  | situations.
  |
  | If the divisor is (positive or negative) zero, then an error is raised
  | [err:FOAR0001]. If either operand is NaN or if $arg1 is INF or -INF
  | then an error is raised [err:FOAR0002].
  |
  | Note:
  | The semantics of this function are different from integer division as
  | defined in programming languages such as Java and C++.
  |_______________________________________________________________________*/


  /*______________________________________________________________________
  |
  | 6.2.6 op:numeric-mod
  | op:numeric-mod($arg1 as numeric, $arg2 as numeric) as numeric
  |
  | Summary: Backs up the "mod" operator. Informally, this function
  | returns the remainder resulting from dividing $arg1, the dividend, by
  | $arg2, the divisor. The operation a mod b for operands that are
  | xs:integer or xs:decimal, or types derived from them, produces a
  | result such that (a idiv b)*b+(a mod b) is equal to a and the
  | magnitude of the result is always less than the magnitude of b. This
  | identity holds even in the special case that the dividend is the
  | negative integer of largest possible magnitude for its type and the
  | divisor is -1 (the remainder is 0). It follows from this rule that the
  | sign of the result is the sign of the dividend.
  |
  | For xs:integer and xs:decimal operands, if $arg2 is zero, then an
  | error is raised [err:FOAR0001].
  |
  | For xs:float and xs:double operands the following rules apply:
  |   * If either operand is NaN, the result is NaN.
  |   * If the dividend is positive or negative infinity, or the divisor
  |     is positive or negative zero (0), or both, the result is NaN.
  |   * If the dividend is finite and the divisor is an infinity, the
  |     result equals the dividend.
  |   * If the dividend is positive or negative zero and the divisor is
  |     finite, the result is the same as the dividend.
  |   * In the remaining cases, where neither positive or negative
  |     infinity, nor positive or negative zero, nor NaN is involved, the
  |     result obeys (a idiv b)*b+(a mod b) = a. Division is truncating
  |     division, analogous to integer division, not [IEEE 754-1985] rounding
  |     division i.e. additional digits are truncated, not rounded to the
  |     required precision.
  |_______________________________________________________________________*/

  /*______________________________________________________________________
  |
  | 6.2.7 op:numeric-unary-plus
  | op:numeric-unary-plus($arg as numeric) as numeric
  |
  | Summary: Backs up the unary "+" operator and returns its operand with
  | the sign unchanged: (+ $arg). Semantically, this operation performs no
  | operation.
  |_______________________________________________________________________*/



  /*______________________________________________________________________
  |
  | 6.2.8 op:numeric-unary-minus
  | op:numeric-unary-minus($arg as numeric) as numeric
  |
  | Summary: Backs up the unary "-" operator and returns its operand with
  | the sign reversed: (- $arg). If $arg is positive, its negative is
  | returned; if it is negative, its positive is returned.
  |
  | For xs:integer and xs:decimal arguments, 0 and 0.0 return 0 and 0.0,
  | respectively. For xs:float and xs:double arguments, NaN returns NaN,
  | 0.0E0 returns -0.0E0 and vice versa. INF returns -INF. -INF returns
  | INF.
  |_______________________________________________________________________*/
  OpNumericUnaryIterator::OpNumericUnaryIterator ( const QueryLoc& loc, PlanIter_t& theChild, bool aPlus )
      :
      UnaryBaseIterator<OpNumericUnaryIterator, PlanIteratorState> ( loc, theChild ), thePlus ( aPlus )
  { }

  OpNumericUnaryIterator::~OpNumericUnaryIterator()
  { }

  store::Item_t OpNumericUnaryIterator::nextImpl ( PlanState& planState ) const
  {
    store::Item_t item;
    store::Item_t res;
    xqtref_t type;

    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    item = consumeNext(theChild.getp(), planState );
    if ( item != NULL )
    {
      item = item->getAtomizationValue();
      type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeConstants::QUANT_ONE );
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        item = GenericCast::instance()->cast ( item, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeConstants::QUANT_ONE );
      }

      // TODO Optimizations (e.g. if item has already the correct type and value, it does not have to be created newly)
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
        res = GENV_ITEMFACTORY->createDouble ( 
          (thePlus ? item->getDoubleValue() : -item->getDoubleValue())
        );
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        res = GENV_ITEMFACTORY->createFloat ( 
          (thePlus ? item->getFloatValue() : -item->getFloatValue())
        );
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ) )
        res = GENV_ITEMFACTORY->createInteger ( 
          (thePlus ? item->getIntegerValue() : -item->getIntegerValue())
        );
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ) )
        res = GENV_ITEMFACTORY->createDecimal ( 
          (thePlus ? item->getDecimalValue() : -item->getDecimalValue())
        );
      else
      {
          ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004,
              loc, "Wrong operator type for an unary arithmetic operation.");
      }

      if ( consumeNext(theChild.getp(), planState ) != NULL )
          ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004,
              loc, "Arithmetic operation has a sequences greater than one as an operator.");
      STACK_PUSH ( res, state );
    }
    STACK_END (state);
  }



  /*______________________________________________________________________
  |
  | 6.3 Comparison Operators on Numeric Values
  |_______________________________________________________________________*/

// 6.3.1 op:numeric-equal



  /*______________________________________________________________________
  |
  | 6.4 Functions on Numeric Values
  |_______________________________________________________________________*/

// 6.4.1 fn:abs

  store::Item_t FnAbsIterator::nextImpl ( PlanState& planState ) const
  {
    store::Item_t item;
    store::Item_t res;
    xqtref_t type;

    
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    item = consumeNext(theChildren[0].getp(), planState );
    if ( item != NULL )
    {
      item = item->getAtomizationValue();
      type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeConstants::QUANT_ONE );
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        item = GenericCast::instance()->cast ( item, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeConstants::QUANT_ONE );
      }

      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
        if ( item->getDoubleValue().isPos() )
          if ( TypeOps::is_equal ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
            res = item;
          else
            res = GENV_ITEMFACTORY->createDouble ( item->getDoubleValue() );
        else
          res = GENV_ITEMFACTORY->createDouble ( -item->getDoubleValue() );
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        if ( item->getFloatValue().isPos() )
          if ( TypeOps::is_equal ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
            res = item;
          else
            res = GENV_ITEMFACTORY->createFloat ( item->getFloatValue() );
        else
          res = GENV_ITEMFACTORY->createFloat ( -item->getFloatValue() );
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ) )
        if ( item->getDecimalValue() >= xqp_decimal::zero() )
          if ( TypeOps::is_equal ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ) )
            res = item;
          else
            res = GENV_ITEMFACTORY->createDecimal ( item->getDecimalValue() );
        else
          res = GENV_ITEMFACTORY->createDecimal ( -item->getDecimalValue() );
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ) )
        if ( item->getIntegerValue() >= xqp_decimal::zero() )
          if ( TypeOps::is_equal ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ) )
            res = item;
          else
            res = GENV_ITEMFACTORY->createInteger ( item->getIntegerValue() );
        else
          res = GENV_ITEMFACTORY->createInteger ( -item->getIntegerValue() );
      else
      {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004,
            loc, "Wrong operator type for an abs operation.");
      }

      if ( consumeNext(theChildren[0].getp(), planState ) != NULL )
      {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004,
            loc, "Abs operation has a sequences greater than one as an operator.");
      }
      STACK_PUSH ( res, state );
    }
    STACK_END (state);
  }


// 6.4.2 fn:ceiling

  store::Item_t FnCeilingIterator::nextImpl(PlanState& planState) const
  {
    store::Item_t item;
    store::Item_t res;
    xqtref_t type;
    
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    item = consumeNext(theChildren[0].getp(), planState );

    if ( item != NULL )
    {
      //get the value and the type of the item
      item = item->getAtomizationValue();
      type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeConstants::QUANT_ONE );

      //Parameters of type xs:untypedAtomic are always promoted to xs:double
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        item = GenericCast::instance()->cast ( item, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeConstants::QUANT_ONE );
      }

      //item type is subtype of DOUBLE
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
          res = GENV_ITEMFACTORY->createDouble(item->getDoubleValue().ceil());
        
      //item type is subtype of FLOAT
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        res = GENV_ITEMFACTORY->createFloat(item->getFloatValue().ceil());

      //item type is subtype of DECIMAL
      else if (TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ))
        res = GENV_ITEMFACTORY->createDecimal(item->getDecimalValue().ceil());

      //item type is subtype of INTEGER 
      else if(TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ))
        res = item;

      else
      {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004,
            loc, "Wrong operator type for a ceiling operation.");
      }

      if ( consumeNext(theChildren[0].getp(), planState ) != NULL )
      {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004,
            loc, "Ceiling operation has a sequences greater than one as an operator.");
      }
      STACK_PUSH ( res, state );
    }
    STACK_END (state);
  }
  
// 6.4.3 fn:floor

  store::Item_t FnFloorIterator::nextImpl(PlanState& planState) const
  {
    store::Item_t item;
    store::Item_t res;
    xqtref_t type;
    
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    item = consumeNext(theChildren[0].getp(), planState );

    if ( item != NULL )
    {
      //get the value and the type of the item
      item = item->getAtomizationValue();
      type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeConstants::QUANT_ONE );

      //Parameters of type xs:untypedAtomic are always promoted to xs:double
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        item = GenericCast::instance()->cast ( item, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeConstants::QUANT_ONE );
      }

      //item type is subtype of DOUBLE
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
        res = GENV_ITEMFACTORY->createDouble(item->getDoubleValue().floor());
        
      //item type is subtype of FLOAT
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        res = GENV_ITEMFACTORY->createFloat(item->getFloatValue().floor());

      //item type is subtype of DECIMAL
      else if (TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ))
        res = GENV_ITEMFACTORY->createDecimal(item->getDecimalValue().floor());

      //item type is subtype of INTEGER 
      else if(TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ))
        res = item;

      else
      {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004,
            loc, "Wrong operator type for a floor operation.");
      }

      if ( consumeNext(theChildren[0].getp(), planState ) != NULL )
      {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004,
            loc, "Floor operation has a sequences greater than one as an operator.");
      }
      STACK_PUSH ( res, state );
    }
    STACK_END (state);
  }
  
// 6.4.4 fn:round

  store::Item_t FnRoundIterator::nextImpl(PlanState& planState) const
  {
    store::Item_t item;
    store::Item_t res;
    xqtref_t type;
    
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    item = consumeNext(theChildren[0].getp(), planState );

    if ( item != NULL )
    {
      //get the value and the type of the item
      item = item->getAtomizationValue();
      type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeConstants::QUANT_ONE );

      //Parameters of type xs:untypedAtomic are always promoted to xs:double
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        item = GenericCast::instance()->cast ( item, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeConstants::QUANT_ONE );
      }

      //item type is subtype of DOUBLE
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
        res = GENV_ITEMFACTORY->createDouble(item->getDoubleValue().round());
        
      //item type is subtype of FLOAT
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        res = GENV_ITEMFACTORY->createFloat(item->getFloatValue().round());

      //item type is subtype of DECIMAL
      else if (TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ))
        res = GENV_ITEMFACTORY->createDecimal(item->getDecimalValue().round());

      //item type is subtype of INTEGER 
      else if(TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ))
        res = item;

      else
      {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004,
            loc, "Wrong operator type for a round operation.");
      }

      if ( consumeNext(theChildren[0].getp(), planState ) != NULL )
      {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004,
            loc, "Round operation has a sequences greater than one as an operator.");
      }
      STACK_PUSH ( res, state );
    }
    STACK_END (state);
  }
  
// 6.4.5 fn:round-half-to-even
  FnRoundHalfToEvenIterator::
  FnRoundHalfToEvenIterator(const QueryLoc& loc,
                                            PlanIter_t& iter0,
                                            PlanIter_t& iter1)
  :
  BinaryBaseIterator<FnRoundHalfToEvenIterator, PlanIteratorState>( loc, iter0, iter1 )
  {
  }

  FnRoundHalfToEvenIterator::~ FnRoundHalfToEvenIterator()
  {}

  store::Item_t FnRoundHalfToEvenIterator::nextImpl(PlanState& planState) const
  {
    store::Item_t item;
    store::Item_t itemPrec;
    store::Item_t res;
    xqtref_t type;
    Integer precision = Integer::parseInt((int32_t)0);
    
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    
    item = consumeNext(theChild0.getp(), planState );
    if ( item != NULL )
    {
      itemPrec = consumeNext(theChild1.getp(), planState );
      if ( itemPrec != NULL )
      {
        itemPrec = itemPrec->getAtomizationValue();
        precision = itemPrec->getIntegerValue();
      }
      
      //get the value and the type of the item
      item = item->getAtomizationValue();
      type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeConstants::QUANT_ONE );

      //Parameters of type xs:untypedAtomic are always promoted to xs:double
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        item = GenericCast::instance()->cast ( item, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeConstants::QUANT_ONE );
      }

      //item type is subtype of DOUBLE
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
        res = GENV_ITEMFACTORY->createDouble(item->getDoubleValue().roundHalfToEven(precision));
        
      //item type is subtype of FLOAT
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        res = GENV_ITEMFACTORY->createFloat(item->getFloatValue().roundHalfToEven(precision));

      //item type is subtype of DECIMAL
      else if (TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ))
        res = GENV_ITEMFACTORY->createDecimal(item->getDecimalValue().roundHalfToEven(precision));

      //item type is subtype of INTEGER 
      else if(TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ))
        res = item;

      else
      {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004,
            loc, "Wrong operator type for a round-half-to-even operation.");
      }

      if ( consumeNext(theChild0.getp(), planState ) != NULL )
      {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004,
           loc, "Round-half-to-even operation has a sequences greater than one as an operator.");
      }
      STACK_PUSH ( res, state );
    }
    STACK_END (state);
  }
  
  ZorNumGen::ZorNumGen ( const QueryLoc& loc ) 
    : NoaryBaseIterator<ZorNumGen, ZorNumGenState>(loc) {}

  ZorNumGen::~ZorNumGen() {}

  store::Item_t
  ZorNumGen::nextImpl ( PlanState& planState ) const
  {
    ZorNumGenState* state;
    DEFAULT_STACK_INIT ( ZorNumGenState, state, planState );

    while ( state->getCurNumber() < 100 )
    {
      STACK_PUSH (
          GENV_ITEMFACTORY->createInteger ( Integer::parseInt(state->getCurNumber()) ),
          state );
      state->setCurNumber ( state->getCurNumber() + 1 );
    }
    STACK_END (state);
  }


  void
  ZorNumGenState::init(PlanState& planState)
  {
    PlanIteratorState::init(planState);
    this->curNumber = 0;
  }

  void
  ZorNumGenState::reset(PlanState& planState)
  {
    PlanIteratorState::reset(planState);
    this->curNumber = 0;
  }

  int32_t
  ZorNumGenState::getCurNumber()
  {
    return this->curNumber;
  }

  void
  ZorNumGenState::setCurNumber ( int32_t value )
  {
    this->curNumber = value;
  }

} /* namespace zorba */

