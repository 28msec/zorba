/* *- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: NumericsImpl.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: David Graf
 *
 */

#include <iostream>
#include <cmath>

#include "system/globalenv.h"
#include "runtime/numerics/NumericsImpl.h"
#include "util/tracer.h"
#include "util/math_helper.h"
#include "types/casting.h"
#include "errors/error_factory.h"
#include "system/zorba.h"
#include "runtime/visitors/planitervisitor.h"

using namespace std;
namespace xqp
{
  /* begin class AddOperations */
  Item_t AddOperations::opDouble ( const yy::location* loc,  Item_t i0, Item_t i1 )
  {
    return Zorba::getItemFactory()->createDouble ( i0->getDoubleValue() + i1->getDoubleValue() );
  }
  Item_t AddOperations::opFloat ( const yy::location* loc,  Item_t i0, Item_t i1 )
  {
    return Zorba::getItemFactory()->createFloat ( i0->getFloatValue() + i1->getFloatValue() );
  }
  Item_t AddOperations::opDecimal ( const yy::location* loc,  Item_t i0, Item_t i1 )
  {
    return Zorba::getItemFactory()->createDecimal ( i0->getDecimalValue() + i1->getDecimalValue() );
  }
  Item_t AddOperations::opInteger ( const yy::location* loc,  Item_t i0, Item_t i1 )
  {
    return Zorba::getItemFactory()->createInteger ( i0->getIntegerValue() + i1->getIntegerValue() );
  }
  /* end class AddOperations */

  /* start class SubtractOperations */
  Item_t SubtractOperations::opDouble ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    return Zorba::getItemFactory()->createDouble ( i0->getDoubleValue() - i1->getDoubleValue() );
  }

  Item_t SubtractOperations::opFloat ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    return Zorba::getItemFactory()->createFloat ( i0->getFloatValue() - i1->getFloatValue() );
  }

  Item_t SubtractOperations::opDecimal ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    return Zorba::getItemFactory()->createDecimal ( i0->getDecimalValue() - i1->getDecimalValue() );
  }

  Item_t SubtractOperations::opInteger ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    return Zorba::getItemFactory()->createInteger ( i0->getIntegerValue() - i1->getIntegerValue() );
  }
  /* end class SubtractOperations */

  /* start class MultiplyOperations */
  Item_t MultiplyOperations::opDouble ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    return Zorba::getItemFactory()->createDouble ( i0->getDoubleValue() * i1->getDoubleValue() );
  }

  Item_t MultiplyOperations::opFloat ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    return Zorba::getItemFactory()->createFloat ( i0->getFloatValue() * i1->getFloatValue() );
  }

  Item_t MultiplyOperations::opDecimal ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    return Zorba::getItemFactory()->createDecimal ( i0->getDecimalValue() * i1->getDecimalValue() );
  }

  Item_t MultiplyOperations::opInteger ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    return Zorba::getItemFactory()->createInteger ( i0->getIntegerValue() * i1->getIntegerValue() );
  }
  /* end class MultiplyOperations */

  /* start class DivideOperations */
  Item_t DivideOperations::opDouble ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    return Zorba::getItemFactory()->createDouble ( i0->getDoubleValue() / i1->getDoubleValue() );
  }

  Item_t DivideOperations::opFloat ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    return Zorba::getItemFactory()->createFloat ( i0->getFloatValue() / i1->getFloatValue() );
  }

  Item_t DivideOperations::opDecimal ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    xqp_decimal ld0 = i0->getDecimalValue();
    xqp_decimal ld1 = i1->getDecimalValue();
    if ( ld1 == 0 )
    {
      ZORBA_ERROR_ALERT(AlertCodes::FOAR0001,
         loc, false, "Division by zero (decimals)");
    }
    return Zorba::getItemFactory()->createDecimal ( ld0 / ld1 );
  }

  Item_t DivideOperations::opInteger ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    xqp_decimal ll0 = static_cast<xqp_decimal>(i0->getIntegerValue());
    xqp_decimal ll1 = static_cast<xqp_decimal>(i1->getIntegerValue());
    if ( ll1 == 0 )
    {
      ZORBA_ERROR_ALERT(AlertCodes::FOAR0001,
         loc, false, "Division by zero (decimals)");
    }
    return Zorba::getItemFactory()->createDecimal ( ll0 / ll1 );
  }
  /* end class DivideOperations */

  /* start class IntegerDivideOperations */
  Item_t IntegerDivideOperations::opDouble ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    if (i0->isNaN() || i1->isNaN()) {
      ZORBA_ERROR_ALERT(AlertCodes::FOAR0002,
        loc, false, "Integer Devision with doubles must not be done with NaNs");
    }
    xqp_double d0 = i0->getDoubleValue();
    xqp_double d1 = i1->getDoubleValue();
    if ( d1 == 0 )
    {
      ZORBA_ERROR_ALERT(AlertCodes::FOAR0001,
         loc, false, "Division by zero (decimals)");
    }
    return Zorba::getItemFactory()->createInteger (
               static_cast<xqp_integer> ( d0 / d1 )
           );
  }

  Item_t IntegerDivideOperations::opFloat ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    if (i0->isNaN() || i1->isNaN()) {
      ZORBA_ERROR_ALERT(AlertCodes::FOAR0002,
        loc, false, "Integer Devision with floats must not be done with NaNs");
    }
    xqp_float f0 = i0->getFloatValue();
    xqp_float f1 = i1->getFloatValue();
    if ( f1 == 0 )
    {
      ZORBA_ERROR_ALERT(AlertCodes::FOAR0001,
         loc, false, "Division by zero (decimals)");
    }
    return Zorba::getItemFactory()->createInteger (
               static_cast<xqp_integer> ( f0 / f1 )
           );
  }

  Item_t IntegerDivideOperations::opDecimal ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    xqp_decimal ld0 = i0->getDecimalValue();
    xqp_decimal ld1 = i1->getDecimalValue();
    if ( ld1 == 0 )
    {
      ZORBA_ERROR_ALERT(AlertCodes::FOAR0001,
         loc, false, "Division by zero (decimals)");
    }
    return Zorba::getItemFactory()->createInteger (
               static_cast<xqp_integer> ( ld0 / ld1 )
           );
  }

  Item_t IntegerDivideOperations::opInteger ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    xqp_integer ll0 = i0->getIntegerValue();
    xqp_integer ll1 = i1->getIntegerValue();
    if ( ll1 == 0 )
    {
      ZORBA_ERROR_ALERT(AlertCodes::FOAR0001,
         loc, false, "Division by zero (decimals)");
    }
    return Zorba::getItemFactory()->createInteger (
               ll0 / ll1
           );
  }
  /* end class IntegerDivideOperations */

  /* start class ModOperations */
  Item_t ModOperations::opDouble ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    return Zorba::getItemFactory()->createDouble ( fmod ( i0->getDoubleValue(), i1->getDoubleValue() ) );
  }

  Item_t ModOperations::opFloat ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    return Zorba::getItemFactory()->createFloat ( fmod ( i0->getFloatValue(), i1->getFloatValue() ) );
  }

  Item_t ModOperations::opDecimal ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    xqp_decimal ld0 = i0->getDecimalValue();
    xqp_decimal ld1 = i1->getDecimalValue();
    if ( ld1 == 0 )
    {
      ZORBA_ERROR_ALERT(AlertCodes::FOAR0001,
         loc, false, "Modulo by zero (decimals)");
    }
    return Zorba::getItemFactory()->createDecimal ( fmod ( ld0, ld1 ) );
  }

  Item_t ModOperations::opInteger ( const yy::location* loc, Item_t i0, Item_t i1 )
  {
    xqp_integer ll0 = i0->getIntegerValue();
    xqp_integer ll1 = i1->getIntegerValue();
    if ( ll1 == 0 )
    {
      ZORBA_ERROR_ALERT(AlertCodes::FOAR0001,
         loc, false, "Modulo by zero (decimals)");
    }
    return Zorba::getItemFactory()->createInteger ( ll0 % ll1 );
  }
  /* end class ModOperations */

  /* begin class ArithmeticIterator */
  template< class Operations>
  ArithmeticIterator<Operations>::ArithmeticIterator
  ( const yy::location& loc, PlanIter_t& iter0, PlanIter_t& iter1 )
      :
      BinaryBaseIterator<ArithmeticIterator<Operations> > ( loc, iter0, iter1 )
  { }

  template< class Operations>
  ArithmeticIterator<Operations>::~ArithmeticIterator()
  { }

  template< class Operations>
  Item_t ArithmeticIterator<Operations>::nextImpl ( PlanState& planState )
  {
    Item_t n0;
    Item_t n1;
    Item_t res;
    TypeSystem::xqtref_t type0;
    TypeSystem::xqtref_t type1;
    TypeSystem::xqtref_t resultType;

    PlanIterator::PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIterator::PlanIteratorState, state, planState );
    n0 = this->consumeNext ( this->theChild0, planState );
    if ( n0 != NULL )
    {
      n1 = this->consumeNext ( this->theChild1, planState );
      if ( n1 != NULL )
      {
        res = ArithmeticIterator<Operations>::compute(this->loc, n0, n1);
      
        if ( consumeNext ( this->theChild0, planState ) != NULL 
             || consumeNext ( this->theChild1, planState ) != NULL )
          ZORBA_ERROR_ALERT(AlertCodes::XPTY0004,
              NULL, false, "Arithmetic operation has a sequences greater than one as an operator.");
        STACK_PUSH ( res, state );
      }
    }
    STACK_END();
  }

  template< class Operations>
  Item_t ArithmeticIterator<Operations>::compute(const yy::location& aLoc, Item_t n0, Item_t n1)
  {
    n0 = n0->getAtomizationValue();
    n1 = n1->getAtomizationValue();

    TypeSystem::xqtref_t type0 = GENV_TYPESYSTEM.create_type ( n0->getType(), TypeSystem::QUANT_ONE );
    TypeSystem::xqtref_t type1 = GENV_TYPESYSTEM.create_type ( n1->getType(), TypeSystem::QUANT_ONE );

    TypeSystem::xqtref_t resultType = GENV_TYPESYSTEM.arithmetic_type ( *type0, *type1 );
    n0 = GenericCast::instance()->cast ( n0, resultType );
    n1 = GenericCast::instance()->cast ( n1, resultType );
    Item_t res;

    switch ( GENV_TYPESYSTEM.get_atomic_type_code ( *resultType ) )
    {
      case TypeSystem::XS_DOUBLE:
        res = Operations::opDouble ( &aLoc, n0, n1 );
        break;
      case TypeSystem::XS_FLOAT:
        res = Operations::opFloat ( &aLoc,n0, n1 );
        break;
      case TypeSystem::XS_DECIMAL:
        res = Operations::opDecimal ( &aLoc,n0, n1 );
        break;
      case TypeSystem::XS_INTEGER:
        res = Operations::opInteger ( &aLoc,n0, n1 );
        break;
      default:
        assert(false);
    }

    return res;
  }
  
  /**
   * Information: It is not possible to move this function to
   * runtime/visitors/accept.cpp!
   */
  template< class Operations>
  void ArithmeticIterator<Operations>::accept(PlanIterVisitor& v) const { 
    v.beginVisit(*this); 
    this->theChild0->accept(v); 
    this->theChild1->accept(v); 
    v.endVisit(*this); 
  }

  /* instantiate ArithmeticIterator for all types */
  template class ArithmeticIterator<AddOperations>;
  template class ArithmeticIterator<SubtractOperations>;
  template class ArithmeticIterator<MultiplyOperations>;
  template class ArithmeticIterator<DivideOperations>;
  template class ArithmeticIterator<IntegerDivideOperations>;
  template class ArithmeticIterator<ModOperations>;
  /* end class ArithmeticIterator */

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
  OpNumericUnaryIterator::OpNumericUnaryIterator ( const yy::location& loc, PlanIter_t& theChild, bool aPlus )
      :
      UnaryBaseIterator<OpNumericUnaryIterator> ( loc, theChild ), thePlus ( aPlus )
  { }

  OpNumericUnaryIterator::~OpNumericUnaryIterator()
  { }

  Item_t OpNumericUnaryIterator::nextImpl ( PlanState& planState )
  {
    Item_t item;
    Item_t res;
    int32_t mul;
    TypeSystem::xqtref_t type;

    PlanIterator::PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIterator::PlanIteratorState, state, planState );
    item = this->consumeNext ( theChild, planState );
    if ( item != NULL )
    {
      item = item->getAtomizationValue();
      type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeSystem::QUANT_ONE );
      if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        item = GenericCast::instance()->cast ( item, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeSystem::QUANT_ONE );
      }

      if ( thePlus )
        mul = 1;
      else
        mul = -1;

      // TODO Optimizations (e.g. if item has already the correct type and value, it does not have to be created newly)
      if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
        res = Zorba::getItemFactory()->createDouble ( mul * item->getDoubleValue() );
      else if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        res = Zorba::getItemFactory()->createFloat ( mul * item->getFloatValue() );
      else if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ) )
        res = Zorba::getItemFactory()->createInteger ( mul * item->getIntegerValue() );
      else if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ) )
        res = Zorba::getItemFactory()->createDecimal ( mul * item->getDecimalValue() );
      else
      {
          ZORBA_ERROR_ALERT(AlertCodes::XPTY0004,
              &loc, false, "Wrong operator type for an unary arithmetic operation.");
      }

      if ( this->consumeNext ( theChild, planState ) != NULL )
          ZORBA_ERROR_ALERT(AlertCodes::XPTY0004,
              &loc, false, "Arithmetic operation has a sequences greater than one as an operator.");
      STACK_PUSH ( res, state );
    }
    STACK_END();
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
  FnAbsIterator::FnAbsIterator ( const yy::location& loc, PlanIter_t& aChild )
      :
      UnaryBaseIterator<FnAbsIterator> ( loc, aChild )
  { }

  FnAbsIterator::~FnAbsIterator()
  { }

  Item_t FnAbsIterator::nextImpl ( PlanState& planState )
  {
    Item_t item;
    Item_t res;
    TypeSystem::xqtref_t type;

    
    PlanIterator::PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIterator::PlanIteratorState, state, planState );
    item = this->consumeNext ( theChild, planState );
    if ( item != NULL )
    {
      item = item->getAtomizationValue();
      type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeSystem::QUANT_ONE );
      if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        item = GenericCast::instance()->cast ( item, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeSystem::QUANT_ONE );
      }

      if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
        if ( item->getDoubleValue() >= 0 )
          if ( GENV_TYPESYSTEM.is_equal ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
            res = item;
          else
            res = Zorba::getItemFactory()->createDouble ( item->getDoubleValue() );
        else
          res = Zorba::getItemFactory()->createDouble ( -item->getDoubleValue() );
      else if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        if ( item->getFloatValue() >= 0 )
          if ( GENV_TYPESYSTEM.is_equal ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
            res = item;
          else
            res = Zorba::getItemFactory()->createFloat ( item->getFloatValue() );
        else
          res = Zorba::getItemFactory()->createFloat ( -item->getFloatValue() );
      else if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ) )
        if ( item->getDecimalValue() >= 0 )
          if ( GENV_TYPESYSTEM.is_equal ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ) )
            res = item;
          else
            res = Zorba::getItemFactory()->createDecimal ( item->getDecimalValue() );
        else
          res = Zorba::getItemFactory()->createDecimal ( -item->getDecimalValue() );
      else if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ) )
        if ( item->getIntegerValue() >= 0 )
          if ( GENV_TYPESYSTEM.is_equal ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ) )
            res = item;
          else
            res = Zorba::getItemFactory()->createInteger ( item->getIntegerValue() );
        else
          res = Zorba::getItemFactory()->createInteger ( -item->getIntegerValue() );
      else
      {
        ZORBA_ERROR_ALERT(AlertCodes::XPTY0004,
            &loc, false, "Wrong operator type for an abs operation.");
      }

      if ( this->consumeNext ( theChild, planState ) != NULL )
      {
        ZORBA_ERROR_ALERT(AlertCodes::XPTY0004,
            &loc, false, "Abs operation has a sequences greater than one as an operator.");
      }
      STACK_PUSH ( res, state );
    }
    STACK_END();
  }


// 6.4.2 fn:ceiling
  FnCeilingIterator::FnCeilingIterator(const yy::location& loc, PlanIter_t& theChild)
  :
  UnaryBaseIterator<FnCeilingIterator>(loc, theChild)
  {}

  FnCeilingIterator::~FnCeilingIterator()
  {}

  Item_t FnCeilingIterator::nextImpl(PlanState& planState)
  {
    Item_t item;
    Item_t res;
    TypeSystem::xqtref_t type;
    
    PlanIterator::PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIterator::PlanIteratorState, state, planState );
    item = this->consumeNext ( theChild, planState );

    if ( item != NULL )
    {
      //get the value and the type of the item
      item = item->getAtomizationValue();
      type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeSystem::QUANT_ONE );

      //Parameters of type xs:untypedAtomic are always promoted to xs:double
      if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        item = GenericCast::instance()->cast ( item, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeSystem::QUANT_ONE );
      }

      //item type is subtype of DOUBLE
      if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
          res = Zorba::getItemFactory()->createDouble(ceil(item->getDoubleValue()));
        
      //item type is subtype of FLOAT
      else if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        res = Zorba::getItemFactory()->createFloat(ceil(item->getFloatValue()));

      //item type is subtype of DECIMAL
      else if (GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ))
        res = Zorba::getItemFactory()->createDecimal(ceil(item->getDecimalValue()));

      //item type is subtype of INTEGER 
      else if(GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ))
        res = item;

      else
      {
        ZORBA_ERROR_ALERT(AlertCodes::XPTY0004,
            &loc, false, "Wrong operator type for a ceiling operation.");
      }

      if ( this->consumeNext ( theChild, planState ) != NULL )
      {
        ZORBA_ERROR_ALERT(AlertCodes::XPTY0004,
            &loc, false, "Ceiling operation has a sequences greater than one as an operator.");
      }
      STACK_PUSH ( res, state );
    }
    STACK_END();
  }
  
// 6.4.3 fn:floor
  FnFloorIterator::FnFloorIterator(const yy::location& loc, PlanIter_t& theChild)
  :
  UnaryBaseIterator<FnFloorIterator>(loc, theChild)
  {}

  FnFloorIterator::~ FnFloorIterator()
  {}

  Item_t FnFloorIterator::nextImpl(PlanState& planState)
  {
    Item_t item;
    Item_t res;
    TypeSystem::xqtref_t type;
    
    PlanIterator::PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIterator::PlanIteratorState, state, planState );
    item = this->consumeNext ( theChild, planState );

    if ( item != NULL )
    {
      //get the value and the type of the item
      item = item->getAtomizationValue();
      type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeSystem::QUANT_ONE );

      //Parameters of type xs:untypedAtomic are always promoted to xs:double
      if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        item = GenericCast::instance()->cast ( item, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeSystem::QUANT_ONE );
      }

      //item type is subtype of DOUBLE
      if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
        res = Zorba::getItemFactory()->createDouble(floor(item->getDoubleValue()));
        
      //item type is subtype of FLOAT
      else if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        res = Zorba::getItemFactory()->createFloat(floor(item->getFloatValue()));

      //item type is subtype of DECIMAL
      else if (GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ))
        res = Zorba::getItemFactory()->createDecimal(floor(item->getDecimalValue()));

      //item type is subtype of INTEGER 
      else if(GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ))
        res = item;

      else
      {
        ZORBA_ERROR_ALERT(AlertCodes::XPTY0004,
            &loc, false, "Wrong operator type for a floor operation.");
      }

      if ( this->consumeNext ( theChild, planState ) != NULL )
      {
        ZORBA_ERROR_ALERT(AlertCodes::XPTY0004,
            &loc, false, "Floor operation has a sequences greater than one as an operator.");
      }
      STACK_PUSH ( res, state );
    }
    STACK_END();
  }
  
// 6.4.4 fn:round
  FnRoundIterator::FnRoundIterator(const yy::location& loc, PlanIter_t& theChild)
  :
  UnaryBaseIterator<FnRoundIterator>(loc, theChild)
  {}

  FnRoundIterator::~FnRoundIterator()
  {}

  Item_t FnRoundIterator::nextImpl(PlanState& planState)
  {
    Item_t item;
    Item_t res;
    TypeSystem::xqtref_t type;
    
    PlanIterator::PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIterator::PlanIteratorState, state, planState );
    item = this->consumeNext ( theChild, planState );

    if ( item != NULL )
    {
      //get the value and the type of the item
      item = item->getAtomizationValue();
      type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeSystem::QUANT_ONE );

      //Parameters of type xs:untypedAtomic are always promoted to xs:double
      if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        item = GenericCast::instance()->cast ( item, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeSystem::QUANT_ONE );
      }

      //item type is subtype of DOUBLE
      if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
        res = Zorba::getItemFactory()->createDouble(xqp::round(item->getDoubleValue()));
        
      //item type is subtype of FLOAT
      else if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        res = Zorba::getItemFactory()->createFloat(xqp::round(item->getFloatValue()));

      //item type is subtype of DECIMAL
      else if (GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ))
        res = Zorba::getItemFactory()->createDecimal(xqp::round(item->getDecimalValue()));

      //item type is subtype of INTEGER 
      else if(GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ))
        res = item;

      else
      {
        ZORBA_ERROR_ALERT(AlertCodes::XPTY0004,
            &loc, false, "Wrong operator type for a round operation.");
      }

      if ( this->consumeNext ( theChild, planState ) != NULL )
      {
        ZORBA_ERROR_ALERT(AlertCodes::XPTY0004,
            &loc, false, "Round operation has a sequences greater than one as an operator.");
      }
      STACK_PUSH ( res, state );
    }
    STACK_END();
  }
  
// 6.4.5 fn:round-half-to-even
  FnRoundHalfToEvenIterator::
  FnRoundHalfToEvenIterator(const yy::location& loc,
                                            PlanIter_t& iter0,
                                            PlanIter_t& iter1)
  :
  BinaryBaseIterator<FnRoundHalfToEvenIterator>( loc, iter0, iter1 )
  {}

  FnRoundHalfToEvenIterator::~ FnRoundHalfToEvenIterator()
  {}

  Item_t FnRoundHalfToEvenIterator::nextImpl(PlanState& planState)
  {
    Item_t item;
    Item_t itemPrec;
    Item_t res;
    TypeSystem::xqtref_t type;
    int32_t precision = 0;
    
    PlanIterator::PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIterator::PlanIteratorState, state, planState );
    
    item = this->consumeNext ( theChild0, planState );
    if ( item != NULL )
    {
      itemPrec = this->consumeNext ( theChild1, planState );
      if ( itemPrec != NULL )
      {
        itemPrec = itemPrec->getAtomizationValue();
        precision = itemPrec->getIntegerValue();
      }
      
      //get the value and the type of the item
      item = item->getAtomizationValue();
      type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeSystem::QUANT_ONE );

      //Parameters of type xs:untypedAtomic are always promoted to xs:double
      if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE ) )
      {
        item = GenericCast::instance()->cast ( item, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE );
        type = GENV_TYPESYSTEM.create_type ( item->getType(), TypeSystem::QUANT_ONE );
      }

      //item type is subtype of DOUBLE
      if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE ) )
        res = Zorba::getItemFactory()->createDouble(xqp::roundHalfToEven(item->getDoubleValue(), precision));
        
      //item type is subtype of FLOAT
      else if ( GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE ) )
        res = Zorba::getItemFactory()->createFloat(xqp::roundHalfToEven(item->getFloatValue(), precision));

      //item type is subtype of DECIMAL
      else if (GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE ))
        res = Zorba::getItemFactory()->createDecimal(xqp::roundHalfToEven(item->getDecimalValue(), precision));

      //item type is subtype of INTEGER 
      else if(GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE ))
        res = item;

      else
      {
        ZORBA_ERROR_ALERT(AlertCodes::XPTY0004,
            &loc, false, "Wrong operator type for a round-half-to-even operation.");
      }

      if ( this->consumeNext ( theChild0, planState ) != NULL )
      {
        ZORBA_ERROR_ALERT(AlertCodes::XPTY0004,
           &loc, false, "Round-half-to-even operation has a sequences greater than one as an operator.");
      }
      STACK_PUSH ( res, state );
    }
    STACK_END();
  }
  
  ZorNumGen::ZorNumGen ( const yy::location& loc ) : Batcher<ZorNumGen> ( loc ) {}
  ZorNumGen::~ZorNumGen() {}

  Item_t
  ZorNumGen::nextImpl ( PlanState& planState )
  {
    ZorNumGenState* state;
    GET_STATE ( ZorNumGenState, state, planState );

    DEFAULT_STACK_INIT ( ZorNumGenState, state, planState );
    while ( state->getCurNumber() < 100 )
    {
      STACK_PUSH (
          Zorba::getItemFactory()->createInteger ( state->getCurNumber() ),
          state );
      state->setCurNumber ( state->getCurNumber() + 1 );
    }
    STACK_END();
  }

  void
  ZorNumGen::resetImpl ( PlanState& planState )
  {
    ZorNumGenState* state;
    GET_STATE ( ZorNumGenState, state, planState );
    state->reset();
  }

  void
  ZorNumGen::releaseResourcesImpl ( PlanState& planState )
  {
  }

  uint32_t
  ZorNumGen::getStateSize() const
  {
    return sizeof ( ZorNumGenState );
  }

  uint32_t
  ZorNumGen::getStateSizeOfSubtree() const
  {
    return getStateSize();
  }

  void
  ZorNumGen::setOffset ( PlanState& planState, uint32_t& offset )
  {
    this->stateOffset = offset;
    offset += getStateSize();
  }

  void
  ZorNumGen::ZorNumGenState::init()
  {
    this->curNumber = 0;
  }

  void
  ZorNumGen::ZorNumGenState::reset()
  {
    this->curNumber = 0;
  }

  int32_t
  ZorNumGen::ZorNumGenState::getCurNumber()
  {
    return this->curNumber;
  }

  void
  ZorNumGen::ZorNumGenState::setCurNumber ( int32_t value )
  {
    this->curNumber = value;
  }

} /* namespace xqp */

