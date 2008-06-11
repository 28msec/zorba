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
#include "store/api/item.h"

#include "system/globalenv.h"
#include "runtime/numerics/NumericsImpl.h"
#include "util/tracer.h"
#include "types/casting.h"
#include "zorbaerrors/error_manager.h"
#include "runtime/visitors/planitervisitor.h"
#include "zorbaerrors/Assert.h"
#include "runtime/core/arithmetic_impl.h"
#include "types/typeconstants.h"
#include "types/typeops.h"
#include "store/api/item_factory.h"
#include "runtime/api/runtimecb.h"
#include "context/static_context.h"

namespace zorba
{
  /* begin class AddOperations */
  template<>
  bool AddOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DOUBLE> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc*,  const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createDouble (result,  i0->getDoubleValue() + i1->getDoubleValue() );
  }
  template<>
  bool AddOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc*,  const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createFloat (result,  i0->getFloatValue() + i1->getFloatValue() );
  }
  template<>
  bool AddOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc*,  const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createDecimal (result,  i0->getDecimalValue() + i1->getDecimalValue() );
  }
  template<>
  bool AddOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createInteger (result,  i0->getIntegerValue() + i1->getIntegerValue() );
  }
  /* end class AddOperations */

  /* start class SubtractOperations */
  template<>
  bool SubtractOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DOUBLE> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createDouble (result,  i0->getDoubleValue() - i1->getDoubleValue() );
  }

  template<>
  bool SubtractOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createFloat (result,  i0->getFloatValue() - i1->getFloatValue() );
  }

  template<>
  bool SubtractOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createDecimal (result,  i0->getDecimalValue() - i1->getDecimalValue() );
  }

  template<>
  bool SubtractOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createInteger (result,  i0->getIntegerValue() - i1->getIntegerValue() );
  }
  /* end class SubtractOperations */

  /* start class MultiplyOperations */
  template<>
  bool MultiplyOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DOUBLE> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createDouble (result,  i0->getDoubleValue() * i1->getDoubleValue() );
  }

  template<>
  bool MultiplyOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createFloat (result,  i0->getFloatValue() * i1->getFloatValue() );
  }

  template<>
  bool MultiplyOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createDecimal (result,  i0->getDecimalValue() * i1->getDecimalValue() );
  }

  template<>
  bool MultiplyOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createInteger (result,  i0->getIntegerValue() * i1->getIntegerValue() );
  }
  /* end class MultiplyOperations */

  /* start class DivideOperations */
  template<>
  bool DivideOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DOUBLE> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createDouble (result,  i0->getDoubleValue() / i1->getDoubleValue() );
  }

  template<>
  bool DivideOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createFloat (result,  i0->getFloatValue() / i1->getFloatValue() );
  }

  template<>
  bool DivideOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL> 
  ( store::Item_t& result, RuntimeCB* /*aRuntimeCB*/, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
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
  bool DivideOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
  {
    xqp_decimal ll0 = Decimal::parseInteger(i0->getIntegerValue());
    xqp_decimal ll1 = Decimal::parseInteger(i1->getIntegerValue());
    if ( ll1 == Integer::parseInt(0) )
    {
      ZORBA_ERROR_LOC_DESC( FOAR0001, *loc, "Division by zero (decimals)");
    }
    return GENV_ITEMFACTORY->createDecimal (result,  ll0 / ll1 );
  }
  /* end class DivideOperations */

  /* start class IntegerDivideOperations */
  template<>
  bool IntegerDivideOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DOUBLE> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
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
  bool IntegerDivideOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
  {
    if (i0->isNaN() || i1->isNaN() ) {
      ZORBA_ERROR_LOC_DESC( FOAR0002, *loc, "Integer Division with floats must not be done with NaNs");
    }
    if (i0->isPosOrNegInf()) {
      ZORBA_ERROR_LOC_DESC( FOAR0002, *loc, "Integer division must not be done with a +-INF dividend");
    }
    if (i0->isPosOrNegInf()) {
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
    return GENV_ITEMFACTORY->createInteger (result,  lInteger );
  }

  template<>
  bool IntegerDivideOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
  {
    xqp_decimal ld0 = i0->getDecimalValue();
    xqp_decimal ld1 = i1->getDecimalValue();
    if ( ld1 == Decimal::parseInt(0) )
    {
      ZORBA_ERROR_LOC_DESC( FOAR0001, *loc, "Division by zero (decimals)");
    }
    return GENV_ITEMFACTORY->createInteger (result, 
               Integer::parseDecimal ( ld0 / ld1 )
           );
  }

  template<>
  bool IntegerDivideOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
  {
    xqp_integer ll0 = i0->getIntegerValue();
    xqp_integer ll1 = i1->getIntegerValue();
    if ( ll1 == Integer::parseInt(0) )
    {
      ZORBA_ERROR_LOC_DESC( FOAR0001, *loc, "Division by zero (decimals)");
    }
    return GENV_ITEMFACTORY->createInteger (result, 
               ll0 / ll1
           );
  }
  /* end class IntegerDivideOperations */

  /* start class ModOperations */
  template<>
  bool ModOperation::compute<TypeConstants::XS_DOUBLE,TypeConstants::XS_DOUBLE> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createDouble (result,  i0->getDoubleValue() % i1->getDoubleValue() );
  }

  template<>
  bool ModOperation::compute<TypeConstants::XS_FLOAT,TypeConstants::XS_FLOAT> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc*, const store::Item* i0, const store::Item* i1 )
  {
    return GENV_ITEMFACTORY->createFloat (result,  i0->getFloatValue() % i1->getFloatValue() );
  }

  template<>
  bool ModOperation::compute<TypeConstants::XS_DECIMAL,TypeConstants::XS_DECIMAL> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
  {
    xqp_decimal ld0 = i0->getDecimalValue();
    xqp_decimal ld1 = i1->getDecimalValue();
    if ( ld1 == Decimal::parseInt(0) )
    {
      ZORBA_ERROR_LOC_DESC( FOAR0001,
         *loc, "Modulo by zero (decimals)");
    }
    return GENV_ITEMFACTORY->createDecimal (result,  ld0 % ld1  );
  }

  template<>
  bool ModOperation::compute<TypeConstants::XS_INTEGER,TypeConstants::XS_INTEGER> 
  ( store::Item_t& result, RuntimeCB* /* aRuntimeCB */, const QueryLoc* loc, const store::Item* i0, const store::Item* i1 )
  {
    xqp_integer ll0 = i0->getIntegerValue();
    xqp_integer ll1 = i1->getIntegerValue();
    if ( ll1 == Integer::parseInt(0) )
    {
      ZORBA_ERROR_LOC_DESC( FOAR0001, *loc, "Modulo by zero (decimals)");
    }
    return GENV_ITEMFACTORY->createInteger (result,  ll0 % ll1 );
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
  bool NumArithIterator<Operation>::nextImpl ( store::Item_t& result, PlanState& planState ) const
  {
    bool res;
    store::Item_t n0;
    store::Item_t n1;

    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    if (consumeNext( n0, this->theChild0.getp(), planState ))
    {
      if (consumeNext( n1, this->theChild1.getp(), planState ))
      {
        res = compute(result, planState.theRuntimeCB, this->loc, n0.getp(), n1.getp());
      
        if ( consumeNext(n0, this->theChild0.getp(), planState )
             || consumeNext(n1, this->theChild1.getp(), planState ) )
          ZORBA_ERROR_DESC( XPTY0004, "Arithmetic operation has a sequences greater than one as an operator.");
        STACK_PUSH ( res, state );
      }
    }
    STACK_END (state);
  }

  template < class Operation >
  bool NumArithIterator<Operation>::compute(store::Item_t& result, RuntimeCB* aRuntimeCB,
    const QueryLoc& aLoc, 
    store::Item *n0, store::Item *n1)
  {
    store::Item_t an0 = n0->getAtomizationValue();
    store::Item_t an1 = n1->getAtomizationValue();

    xqtref_t type0 = aRuntimeCB->theStaticContext->get_typemanager()->create_value_type (an0);
    xqtref_t type1 = aRuntimeCB->theStaticContext->get_typemanager()->create_value_type (an1);

    return computeAtomic(result, aRuntimeCB, aLoc, an0.getp(), type0, an1.getp(), type1);
  }
  
  template < class Operation >
  bool NumArithIterator<Operation>::computeAtomic
    (store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc& aLoc, store::Item *item0, xqtref_t type0, store::Item *item1, xqtref_t type1)
  {
    bool res;
    xqtref_t resultType = TypeOps::arithmetic_type ( *type0, *type1 );
    store::Item_t n0;
    store::Item_t n1;

    GenericCast::instance()->cast ( n0, item0, &*resultType );
    GenericCast::instance()->cast ( n1, item1, &*resultType );

    switch ( TypeOps::get_atomic_type_code ( *resultType ) )
    {
      case TypeConstants::XS_DOUBLE:
        res = Operation::template computeSingleType<TypeConstants::XS_DOUBLE> ( result, aRuntimeCB, &aLoc, n0, n1 );
        break;
      case TypeConstants::XS_FLOAT:
        res = Operation::template computeSingleType<TypeConstants::XS_FLOAT> ( result, aRuntimeCB, &aLoc,n0, n1 );
        break;
      case TypeConstants::XS_DECIMAL:
        res = Operation::template computeSingleType<TypeConstants::XS_DECIMAL> ( result, aRuntimeCB, &aLoc,n0, n1 );
        break;
      case TypeConstants::XS_INTEGER:
        res = Operation::template computeSingleType<TypeConstants::XS_INTEGER> ( result, aRuntimeCB, &aLoc,n0, n1 );
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

  bool OpNumericUnaryIterator::nextImpl ( store::Item_t& result, PlanState& planState ) const
  {
    store::Item_t item;
    xqtref_t type;

    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    if (consumeNext(item, theChild.getp(), planState ))
    {
      item = item->getAtomizationValue();
      type = planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type ( item);
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        GenericCast::instance()->cast ( item, item, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type ( item);
      }

      // TODO Optimizations (e.g. if item has already the correct type and value, it does not have to be created newly)
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
        GENV_ITEMFACTORY->createDouble (
          result,
          (thePlus ? item->getDoubleValue() : -item->getDoubleValue())
        );
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        GENV_ITEMFACTORY->createFloat (
          result,
          (thePlus ? item->getFloatValue() : -item->getFloatValue())
        );
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ) )
        GENV_ITEMFACTORY->createInteger (
          result,
          (thePlus ? item->getIntegerValue() : -item->getIntegerValue())
        );
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ) )
        GENV_ITEMFACTORY->createDecimal (
          result,
          (thePlus ? item->getDecimalValue() : -item->getDecimalValue())
        );
      else
      {
          ZORBA_ERROR_LOC_DESC( XPTY0004,
              loc, "Wrong operator type for an unary arithmetic operation.");
      }

      if ( consumeNext(item, theChild.getp(), planState ) )
          ZORBA_ERROR_LOC_DESC( XPTY0004,
              loc, "Arithmetic operation has a sequences greater than one as an operator.");
      STACK_PUSH (true, state );
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

  bool FnAbsIterator::nextImpl ( store::Item_t& result, PlanState& planState ) const
  {
    store::Item_t item;
    xqtref_t type;

    
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    if (consumeNext(result, theChildren[0].getp(), planState ))
    {
      result = result->getAtomizationValue();
      type = planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type (result);
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        GenericCast::instance()->cast ( result, result, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type (result);
      }

      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
        if ( result->getDoubleValue().isPos() ) {
          if ( !TypeOps::is_equal ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
            GENV_ITEMFACTORY->createDouble (result, result->getDoubleValue() );
        }
        else
          GENV_ITEMFACTORY->createDouble (result, -result->getDoubleValue() );
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        if ( result->getFloatValue().isPos() ) {
          if ( !TypeOps::is_equal ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
            GENV_ITEMFACTORY->createFloat (result, result->getFloatValue() );
        }
        else
          GENV_ITEMFACTORY->createFloat (result, -result->getFloatValue() );
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ) )
        if ( result->getIntegerValue() >= xqp_decimal::zero() ) {
          if ( !TypeOps::is_equal ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ) )
            GENV_ITEMFACTORY->createInteger (result, result->getIntegerValue() );
        }
        else
          GENV_ITEMFACTORY->createInteger (result, -result->getIntegerValue() );
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ) )
        if ( result->getDecimalValue() >= xqp_decimal::zero() ) {
          if ( !TypeOps::is_equal ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ) )
            GENV_ITEMFACTORY->createDecimal (result, result->getDecimalValue() );
        }
        else
          GENV_ITEMFACTORY->createDecimal (result, -result->getDecimalValue() );
      else
      {
        ZORBA_ERROR_LOC_DESC( XPTY0004,
            loc, "Wrong operator type for an abs operation.");
      }

      if ( consumeNext(item, theChildren[0].getp(), planState ))
      {
        ZORBA_ERROR_LOC_DESC( XPTY0004,
            loc, "Abs operation has a sequences greater than one as an operator.");
      }
      STACK_PUSH ( true, state );
    }
    STACK_END (state);
  }


// 6.4.2 fn:ceiling

  bool FnCeilingIterator::nextImpl(store::Item_t& result, PlanState& planState) const
  {
    store::Item_t item;
    xqtref_t type;
    
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    if (consumeNext(result, theChildren[0].getp(), planState ))
    {
      //get the value and the type of the item
      result = result->getAtomizationValue();
      type = planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type ( result);

      //Parameters of type xs:untypedAtomic are always promoted to xs:double
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        GenericCast::instance()->cast ( result, result, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type ( result);
      }

      //item type is subtype of DOUBLE
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
        GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().ceil());
        
      //item type is subtype of FLOAT
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().ceil());

      //item type is subtype of INTEGER 
      else if(TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ))
      { /* do nothing */ }

      //item type is subtype of DECIMAL
      else if (TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ))
        GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().ceil());

      else
      {
        ZORBA_ERROR_LOC_DESC( XPTY0004,
            loc, "Wrong operator type for a ceiling operation.");
      }

      if ( consumeNext(item, theChildren[0].getp(), planState ))
      {
        ZORBA_ERROR_LOC_DESC( XPTY0004,
            loc, "Ceiling operation has a sequences greater than one as an operator.");
      }
      STACK_PUSH ( true, state );
    }
    STACK_END (state);
  }
  
// 6.4.3 fn:floor

  bool FnFloorIterator::nextImpl(store::Item_t& result, PlanState& planState) const
  {
    store::Item_t item;
    xqtref_t type;
    
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    if (consumeNext(result, theChildren[0].getp(), planState ))
    {
      //get the value and the type of the item
      result = result->getAtomizationValue();
      type = planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type (result);

      //Parameters of type xs:untypedAtomic are always promoted to xs:double
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        GenericCast::instance()->cast ( result, result, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type ( result);
      }

      //item type is subtype of DOUBLE
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
        GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().floor());
        
      //item type is subtype of FLOAT
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().floor());

      //item type is subtype of INTEGER 
      else if(TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ))
        { /* do nothing */ }

      //item type is subtype of DECIMAL
      else if (TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ))
        GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().floor());

      else
      {
        ZORBA_ERROR_LOC_DESC( XPTY0004,
            loc, "Wrong operator type for a floor operation.");
      }

      if ( consumeNext(item, theChildren[0].getp(), planState ) )
      {
        ZORBA_ERROR_LOC_DESC( XPTY0004,
            loc, "Floor operation has a sequences greater than one as an operator.");
      }
      STACK_PUSH (true, state );
    }
    STACK_END (state);
  }
  
// 6.4.4 fn:round

  bool FnRoundIterator::nextImpl(store::Item_t& result, PlanState& planState) const
  {
    store::Item_t item;
    store::Item_t res;
    xqtref_t type;
    
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    if (consumeNext(result, theChildren[0].getp(), planState ))
    {
      //get the value and the type of the item
      result = result->getAtomizationValue();
      type = planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type (result);

      //Parameters of type xs:untypedAtomic are always promoted to xs:double
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        GenericCast::instance()->cast ( result, result, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type (result);
      }

      //item type is subtype of DOUBLE
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
        GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().round());
        
      //item type is subtype of FLOAT
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().round());

      //item type is subtype of INTEGER 
      else if(TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ))
        { /* do nothing */ }

      //item type is subtype of DECIMAL
      else if (TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ))
        GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().round());

      else
      {
        ZORBA_ERROR_LOC_DESC( XPTY0004,
            loc, "Wrong operator type for a round operation.");
      }

      if ( consumeNext(item, theChildren[0].getp(), planState ))
      {
        ZORBA_ERROR_LOC_DESC( XPTY0004,
            loc, "Round operation has a sequence longer than one as an operator.");
      }
      STACK_PUSH (true, state );
    }
    STACK_END (state);
  }
  
// 6.4.5 fn:round-half-to-even
  bool FnRoundHalfToEvenIterator::nextImpl(store::Item_t& result, PlanState& planState) const
  {
    store::Item_t item;
    store::Item_t itemPrec;
    store::Item_t res;
    xqtref_t type;
    Integer precision = Integer::parseInt((int32_t)0);
    
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    
    if (consumeNext(result, theChildren [0].getp(), planState ))
    {
      if (theChildren.size () == 2) {
        consumeNext(itemPrec, theChildren [1].getp(), planState );
        itemPrec = itemPrec->getAtomizationValue();
        precision = itemPrec->getIntegerValue();
      }
      
      //get the value and the type of the item
      result = result->getAtomizationValue();
      type = planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type (result);

      //Parameters of type xs:untypedAtomic are always promoted to xs:double
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        GenericCast::instance()->cast (result, result, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type (result);
      }

      //item type is subtype of DOUBLE
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
        GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().roundHalfToEven(precision));
        
      //item type is subtype of FLOAT
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().roundHalfToEven(precision));

      //item type is subtype of INTEGER 
      else if(TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ))
      { /* do nothing */ }
      //item type is subtype of DECIMAL
      else if (TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ))
        GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().roundHalfToEven(precision));

      else
      {
        ZORBA_ERROR_LOC_DESC( XPTY0004,
            loc, "Wrong operator type for a round-half-to-even operation.");
      }

      if ( consumeNext(item, theChildren [0].getp(), planState ))
      {
        ZORBA_ERROR_LOC_DESC( XPTY0004,
           loc, "Round-half-to-even operation has a sequences greater than one as an operator.");
      }
      STACK_PUSH ( true, state );
    }
    STACK_END (state);
  }


  bool FnSQRTIterator::nextImpl (store::Item_t& result, PlanState& planState) const {
    store::Item_t item;
    xqtref_t type;
    
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    if (consumeNext(result, theChildren[0].getp(), planState ))
    {
      result = result->getAtomizationValue();

      //get the value and the type of the item
      result = result->getAtomizationValue();
      type = planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type (result);

      //Parameters of type xs:untypedAtomic are always promoted to xs:double
      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        GenericCast::instance()->cast ( result, result, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type (result);
      }

      if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
        GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().sqrt());        
      else if ( TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        GENV_ITEMFACTORY->createFloat(result, result->getFloatValue().sqrt());
      else if(TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ))
        GENV_ITEMFACTORY->createInteger(result, result->getIntegerValue().sqrt());
      else if (TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ))
        GENV_ITEMFACTORY->createDecimal(result, result->getDecimalValue().sqrt());
      else
        ZORBA_ERROR_LOC_DESC( XPTY0004,
            loc, "Wrong operator type for a sqrt operation.");

      if ( consumeNext(item, theChildren[0].getp(), planState ))
      {
        ZORBA_ERROR_LOC_DESC( XPTY0004,
            loc, "sqrt operation has a sequence longer than one as an operator.");
      }

      STACK_PUSH (true, state);
    }
    STACK_END (state);
  }


  bool FnExpIterator::nextImpl (store::Item_t& result, PlanState& planState) const
  {
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    if (consumeNext(result, theChildren[0].getp(), planState )) {
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().exp());
      STACK_PUSH (true, state);
    }
    STACK_END (state);
  }

  bool FnLogIterator::nextImpl (store::Item_t& result, PlanState& planState) const
  {
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    if (consumeNext(result, theChildren[0].getp(), planState )) {
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().log());
      STACK_PUSH (true, state);
    }
    STACK_END (state);
  }

  bool FnSinIterator::nextImpl (store::Item_t& result, PlanState& planState) const
  {
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    if (consumeNext(result, theChildren[0].getp(), planState )) {
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().sin());
      STACK_PUSH (true, state);
    }
    STACK_END (state);
  }

  bool FnCosIterator::nextImpl (store::Item_t& result, PlanState& planState) const
  {
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
    if (consumeNext(result, theChildren[0].getp(), planState )) {
      GENV_ITEMFACTORY->createDouble(result, result->getDoubleValue().cos());
      STACK_PUSH (true, state);
    }
    STACK_END (state);
  }

  ZorNumGen::ZorNumGen ( const QueryLoc& loc ) 
    : NoaryBaseIterator<ZorNumGen, ZorNumGenState>(loc) {}

  ZorNumGen::~ZorNumGen() {}

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

