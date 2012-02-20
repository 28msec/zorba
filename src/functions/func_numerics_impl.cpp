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
#include "stdafx.h"

#include "runtime/numerics/NumericsImpl.h"
#include "runtime/core/arithmetic_impl.h"

#include "compiler/expression/fo_expr.h"

#include "functions/func_numerics.h"
#include "functions/func_numerics_impl.h"

#include "system/globalenv.h"

#include "types/typeops.h"

namespace zorba
{

#define SPECIALIZE_NUMERIC_ARITH_FUNCTION(kind, type)             \
  switch (kind)                                                   \
  {                                                               \
  case FunctionConsts::OP_NUMERIC_ADD_2:                          \
    return GET_BUILTIN_FUNCTION(OP_NUMERIC_ADD_##type##_2);       \
                                                                  \
  case FunctionConsts::OP_NUMERIC_SUBTRACT_2:                     \
    return GET_BUILTIN_FUNCTION(OP_NUMERIC_SUBTRACT_##type##_2);  \
                                                                  \
 case FunctionConsts::OP_NUMERIC_MULTIPLY_2:                      \
   return GET_BUILTIN_FUNCTION(OP_NUMERIC_MULTIPLY_##type##_2);   \
                                                                  \
 case FunctionConsts::OP_NUMERIC_DIVIDE_2:                        \
   return GET_BUILTIN_FUNCTION(OP_NUMERIC_DIVIDE_##type##_2);     \
                                                                  \
 default:                                                         \
   ZORBA_ASSERT(false);                                           \
}


#define CODEGEN_SPECIFIC_NUMERIC(op, t)                                    \
PlanIter_t codegen(                                                        \
    CompilerCB*,                                                           \
    static_context* sctx,                                                  \
    const QueryLoc& loc,                                                   \
    std::vector<PlanIter_t>& argv,                                         \
    expr&) const                                               \
{                                                                          \
  return new SpecificNumArithIterator<op, t>(sctx, loc, argv[0], argv[1]); \
}


/*******************************************************************************
  Common base class for all FO functions and operators that work with 2 numeric
  operands.
********************************************************************************/
class bin_num_arith_func : public function
{
public:
  bin_num_arith_func(const signature& sig, FunctionConsts::FunctionKind kind)
    :
    function(sig, kind)
  {
  }

  bool isArithmeticFunction() const { return true; }

  xqtref_t getReturnType(const fo_expr* caller) const
  {
    TypeManager* tm = caller->get_type_manager();

    return TypeOps::arithmetic_type(tm,
                                    *(caller->get_arg(0)->get_return_type()),
                                    *(caller->get_arg(1)->get_return_type()),
                                    arithmeticKind() == ArithmeticConsts::DIVISION);
  }
};


/*******************************************************************************

********************************************************************************/
class specializable_bin_num_arith_func : public bin_num_arith_func
{
public:
  specializable_bin_num_arith_func(
        const signature& sig,
        FunctionConsts::FunctionKind kind)
    :
    bin_num_arith_func(sig, kind)
  {
  }

  bool specializable() const { return true; }

  function* specialize(static_context*, const std::vector<xqtref_t>&) const;
};


function* specializable_bin_num_arith_func::specialize(
    static_context* sctx,
    const std::vector<xqtref_t>& argTypes) const
{
  xqtref_t t0 = argTypes[0];
  xqtref_t t1 = argTypes[1];

  if (t0->type_kind() == XQType::ATOMIC_TYPE_KIND &&
      t1->type_kind() == XQType::ATOMIC_TYPE_KIND)
  {
    store::SchemaTypeCode tc0 = TypeOps::get_atomic_type_code(*t0);
    store::SchemaTypeCode tc1 = TypeOps::get_atomic_type_code(*t1);

    if (tc0 == tc1)
    {
      switch(tc0)
      {
      case store::XS_DOUBLE:
        SPECIALIZE_NUMERIC_ARITH_FUNCTION(theKind, DOUBLE);
        break;
      case store::XS_DECIMAL:
        SPECIALIZE_NUMERIC_ARITH_FUNCTION(theKind, DECIMAL);
        break;
      case store::XS_FLOAT:
        SPECIALIZE_NUMERIC_ARITH_FUNCTION(theKind, FLOAT);
        break;
      case store::XS_INTEGER:
        SPECIALIZE_NUMERIC_ARITH_FUNCTION(theKind, INTEGER);
        break;
      default:
        return NULL;
      }
    }
  }
  return NULL;
}


/*******************************************************************************
  6.2.1 op:numeric-add

  op:numeric-add($arg1 as numeric, $arg2 as numeric) as numeric

  Summary: Backs up the "+" operator and returns the arithmetic sum of
  its operands: ($arg1 + $arg2).

  Note:
  For xs:float or xs:double values, if one of the operands is a zero or
  a finite number and the other is INF or -INF, INF or -INF is returned.
  If both operands are INF, INF is returned. If both operands are -INF,
  -INF is returned. If one of the operands is INF and the other is -INF,
  NaN is returned.
********************************************************************************/
class op_numeric_add : public specializable_bin_num_arith_func
{
public:
  op_numeric_add(const signature& sig)
    :
    specializable_bin_num_arith_func(sig, FunctionConsts::OP_NUMERIC_ADD_2)
  {
  };

  ArithmeticConsts::OperationKind arithmeticKind() const
  {
    return ArithmeticConsts::ADDITION;
  }

  DEFAULT_BINARY_CODEGEN(NumArithIterator<AddOperation>);
};


template<store::SchemaTypeCode t, FunctionConsts::FunctionKind k>
class op_numeric_add_specific : public bin_num_arith_func
{
public:
  op_numeric_add_specific(const signature& sig) : bin_num_arith_func(sig, k)
  {
  }

  ArithmeticConsts::OperationKind arithmeticKind() const
  {
    return ArithmeticConsts::ADDITION;
  }

  CODEGEN_SPECIFIC_NUMERIC(AddOperation, t);
};


typedef
op_numeric_add_specific<store::XS_DOUBLE,
                        FunctionConsts::OP_NUMERIC_ADD_DOUBLE_2>
op_numeric_add_double;


typedef
op_numeric_add_specific<store::XS_FLOAT,
                        FunctionConsts::OP_NUMERIC_ADD_FLOAT_2>
op_numeric_add_float;


typedef
op_numeric_add_specific<store::XS_DECIMAL,
                        FunctionConsts::OP_NUMERIC_ADD_DECIMAL_2>
op_numeric_add_decimal;


typedef
op_numeric_add_specific<store::XS_INTEGER,
                        FunctionConsts::OP_NUMERIC_ADD_INTEGER_2>
op_numeric_add_integer;


/*******************************************************************************
  6.2.2 op:numeric-subtract

  op:numeric-subtract($arg1 as numeric, $arg2 as numeric) as numeric

  Summary: Backs up the "-" operator and returns the arithmetic difference of
  its operands: ($arg1 - $arg2).

  Note:
  For xs:float or xs:double values, if one of the operands is a zero or a
  finite number and the other is INF or -INF, an infinity of the appropriate
  sign is returned. If both operands are INF or -INF, NaN is returned. If one
  of the operands is INF and the other is -INF, an infinity of the appropriate
  sign is returned.
********************************************************************************/
class op_numeric_subtract : public specializable_bin_num_arith_func
{
public:
  op_numeric_subtract(const signature& sig)
    :
    specializable_bin_num_arith_func(sig, FunctionConsts::OP_NUMERIC_SUBTRACT_2)
  {
  };

  ArithmeticConsts::OperationKind arithmeticKind() const
  {
    return ArithmeticConsts::SUBTRACTION;
  }

  DEFAULT_BINARY_CODEGEN(NumArithIterator<SubtractOperation>);
};


template<store::SchemaTypeCode t, FunctionConsts::FunctionKind k>
class op_numeric_subtract_specific : public bin_num_arith_func
{
public:
  op_numeric_subtract_specific(const signature& sig) : bin_num_arith_func(sig, k)
  {
  }

  ArithmeticConsts::OperationKind arithmeticKind() const
  {
    return ArithmeticConsts::SUBTRACTION;
  }

  CODEGEN_SPECIFIC_NUMERIC(SubtractOperation, t);
};


typedef
op_numeric_subtract_specific<store::XS_DOUBLE,
                             FunctionConsts::OP_NUMERIC_SUBTRACT_DOUBLE_2>
op_numeric_subtract_double;


typedef
op_numeric_subtract_specific<store::XS_FLOAT,
                             FunctionConsts::OP_NUMERIC_SUBTRACT_FLOAT_2>
op_numeric_subtract_float;


typedef
op_numeric_subtract_specific<store::XS_DECIMAL,
                             FunctionConsts::OP_NUMERIC_SUBTRACT_DECIMAL_2>
op_numeric_subtract_decimal;


typedef
op_numeric_subtract_specific<store::XS_INTEGER,
                             FunctionConsts::OP_NUMERIC_SUBTRACT_INTEGER_2>
op_numeric_subtract_integer;


/*******************************************************************************
   6.2.3 op:numeric-multiply

  op:numeric-multiply($arg1 as numeric, $arg2 as numeric) as numeric

  Summary: Backs up the "*" operator and returns the arithmetic product of its
  operands: ($arg1 * $arg2).

  Note:
  For xs:float or xs:double values, if one of the operands is a zero and the
  other is an infinity, NaN is returned. If one of the operands is a non-zero
  number and the other is an infinity, an infinity with the appropriate sign
  is returned.
********************************************************************************/
class op_numeric_multiply : public specializable_bin_num_arith_func
{
public:
  op_numeric_multiply(const signature& sig)
    :
    specializable_bin_num_arith_func(sig, FunctionConsts::OP_NUMERIC_MULTIPLY_2)
  {
  };

  ArithmeticConsts::OperationKind arithmeticKind() const
  {
    return ArithmeticConsts::MULTIPLICATION;
  }

  DEFAULT_BINARY_CODEGEN(NumArithIterator<MultiplyOperation>);
};


template<store::SchemaTypeCode t, FunctionConsts::FunctionKind k>
class op_numeric_multiply_specific : public bin_num_arith_func
{
public:
  op_numeric_multiply_specific(const signature& sig) : bin_num_arith_func(sig, k)
  {
  };

  ArithmeticConsts::OperationKind arithmeticKind() const
  {
    return ArithmeticConsts::MULTIPLICATION;
  }

  CODEGEN_SPECIFIC_NUMERIC(MultiplyOperation, t);
};


typedef
op_numeric_multiply_specific<store::XS_DOUBLE,
                             FunctionConsts::OP_NUMERIC_MULTIPLY_DOUBLE_2>
op_numeric_multiply_double;


typedef
op_numeric_multiply_specific<store::XS_FLOAT,
                             FunctionConsts::OP_NUMERIC_MULTIPLY_FLOAT_2>
op_numeric_multiply_float;


typedef
op_numeric_multiply_specific<store::XS_DECIMAL,
                             FunctionConsts::OP_NUMERIC_MULTIPLY_DECIMAL_2>
op_numeric_multiply_decimal;


typedef
op_numeric_multiply_specific<store::XS_INTEGER,
                             FunctionConsts::OP_NUMERIC_MULTIPLY_INTEGER_2>
op_numeric_multiply_integer;


/*******************************************************************************
  6.2.4 op:numeric-divide

  op:numeric-divide($arg1 as numeric, $arg2 as numeric) as numeric

  Summary: Backs up the "div" operator and returns the arithmetic quotient of
  its operands: ($arg1 div $arg2).

  As a special case, if the types of both $arg1 and $arg2 are xs:integer, then
  the return type is xs:decimal.

  Notes:
  For xs:decimal and xs:integer operands, if the divisor is (positive or
  negative) zero, an error is raised [err:FOAR0001]. For xs:float and
  xs:double operands, floating point division is performed as specified
  in [IEEE 754-1985].

  For xs:float or xs:double values, a positive number divided by positive zero
  returns INF. A negative number divided by positive zero returns -INF. Division
  by negative zero returns -INF and INF, respectively. Positive or negative zero
  divided by positive or negative zero returns NaN. Also, INF or -INF divided by
  INF or -INF returns NaN.
********************************************************************************/
class op_numeric_divide : public specializable_bin_num_arith_func
{
public:
  op_numeric_divide(const signature& sig)
    :
    specializable_bin_num_arith_func(sig, FunctionConsts::OP_NUMERIC_DIVIDE_2)
  {
  }

  ArithmeticConsts::OperationKind arithmeticKind() const
  {
    return ArithmeticConsts::DIVISION;
  }

  DEFAULT_BINARY_CODEGEN(NumArithIterator<DivideOperation>);
};


template<store::SchemaTypeCode t, FunctionConsts::FunctionKind k>
class op_numeric_divide_specific : public bin_num_arith_func
{
public:
  op_numeric_divide_specific(const signature& sig) : bin_num_arith_func(sig, k)
  {
  }

  ArithmeticConsts::OperationKind arithmeticKind() const
  {
    return ArithmeticConsts::DIVISION;
  }

  CODEGEN_SPECIFIC_NUMERIC(DivideOperation, t);
};


typedef
op_numeric_divide_specific<store::XS_DOUBLE,
                           FunctionConsts::OP_NUMERIC_DIVIDE_DOUBLE_2>
op_numeric_divide_double;


typedef
op_numeric_divide_specific<store::XS_FLOAT,
                           FunctionConsts::OP_NUMERIC_DIVIDE_FLOAT_2>
op_numeric_divide_float;


typedef
op_numeric_divide_specific<store::XS_DECIMAL,
                           FunctionConsts::OP_NUMERIC_DIVIDE_DECIMAL_2>
op_numeric_divide_decimal;


typedef
op_numeric_divide_specific<store::XS_INTEGER,
                           FunctionConsts::OP_NUMERIC_DIVIDE_INTEGER_2>
op_numeric_divide_integer;



/*******************************************************************************
  6.2.5 op:numeric-integer-divide

  op:numeric-integer-divide($arg1 as numeric, $arg2 as numeric) as xs:integer

  Summary: This function backs up the "idiv" operator and performs an integer
  division: that is, it divides the first argument by the second, and returns
  the integer obtained by truncating the fractional part of the result. The
  division is performed so that the sign of the fractional part is the same as
  the sign of the dividend.

  If the dividend, $arg1, is not evenly divided by the divisor, $arg2, then
  the quotient is the xs:integer value obtained, ignoring (truncating) any
  remainder that results from the division (that is, no rounding is performed).
  Thus, the semantics " $a idiv $b " are equivalent to " ($a div $b) cast as
  xs:integer" except for error situations.

  If the divisor is (positive or negative) zero, then an error is raised
  [err:FOAR0001]. If either operand is NaN or if $arg1 is INF or -INF then
  an error is raised [err:FOAR0002].

  Note:
  The semantics of this function are different from integer division as
  defined in programming languages such as Java and C++.
********************************************************************************/
class op_numeric_integer_divide : public bin_num_arith_func
{
public:
  op_numeric_integer_divide(const signature& sig)
    :
    bin_num_arith_func(sig, FunctionConsts::OP_NUMERIC_INTEGER_DIVIDE_2)
  {
  };

  ArithmeticConsts::OperationKind arithmeticKind() const
  {
    return ArithmeticConsts::INTEGER_DIVISION;
  }

  DEFAULT_BINARY_CODEGEN(NumArithIterator<IntegerDivideOperation>);
};


/*******************************************************************************

  6.2.6 op:numeric-mod

  op:numeric-mod($arg1 as numeric, $arg2 as numeric) as numeric

  Summary: Backs up the "mod" operator. Informally, this function
  returns the remainder resulting from dividing $arg1, the dividend, by
  $arg2, the divisor. The operation a mod b for operands that are
  xs:integer or xs:decimal, or types derived from them, produces a
  result such that (a idiv b)*b+(a mod b) is equal to a and the
  magnitude of the result is always less than the magnitude of b. This
  identity holds even in the special case that the dividend is the
  negative integer of largest possible magnitude for its type and the
  divisor is -1 (the remainder is 0). It follows from this rule that the
  sign of the result is the sign of the dividend.

  For xs:integer and xs:decimal operands, if $arg2 is zero, then an
  error is raised [err:FOAR0001].

  For xs:float and xs:double operands the following rules apply:
   * If either operand is NaN, the result is NaN.
   * If the dividend is positive or negative infinity, or the divisor
     is positive or negative zero (0), or both, the result is NaN.
   * If the dividend is finite and the divisor is an infinity, the
     result equals the dividend.
   * If the dividend is positive or negative zero and the divisor is
     finite, the result is the same as the dividend.
   * In the remaining cases, where neither positive or negative
     infinity, nor positive or negative zero, nor NaN is involved, the
     result obeys (a idiv b)*b+(a mod b) = a. Division is truncating
     division, analogous to integer division, not [IEEE 754-1985] rounding
     division i.e. additional digits are truncated, not rounded to the
     required precision.
********************************************************************************/
class op_numeric_mod : public bin_num_arith_func
{
public:
  op_numeric_mod(const signature& sig)
    :
    bin_num_arith_func(sig, FunctionConsts::OP_NUMERIC_MOD_2)
  {
  };

  ArithmeticConsts::OperationKind arithmeticKind() const
  {
    return ArithmeticConsts::MODULO;
  }

  DEFAULT_BINARY_CODEGEN(NumArithIterator<ModOperation>);
};



/*******************************************************************************

********************************************************************************/
class single_numeric_func : public function
{
public:
  single_numeric_func(const signature& sig, FunctionConsts::FunctionKind kind)
    :
    function(sig, kind)
  {
  }

  virtual xqtref_t getReturnType(const fo_expr* caller) const
  {
    return caller->get_arg(0)->get_return_type();
  }

  virtual bool specializable() const { return true; }

  function* specialize(static_context*, const std::vector<xqtref_t>&) const;

  virtual bool isArithmeticFunction() const { return true; }
};


function* single_numeric_func::specialize(
    static_context* sctx,
    const std::vector<xqtref_t>& argTypes) const
{
  const RootTypeManager& rtm = GENV_TYPESYSTEM;
  TypeManager* tm = sctx->get_typemanager();

  xqtref_t argType = argTypes[0];

  if (getKind() == FunctionConsts::OP_UNARY_PLUS_1)
  {
    if (TypeOps::is_subtype(tm, *argType, *rtm.DOUBLE_TYPE_ONE))
    {
      return GET_BUILTIN_FUNCTION(OP_DOUBLE_UNARY_PLUS_1);
    }
  }
  else if (getKind() == FunctionConsts::OP_UNARY_MINUS_1)
  {
    if (TypeOps::is_subtype(tm, *argType, *rtm.DOUBLE_TYPE_ONE))
    {
      return GET_BUILTIN_FUNCTION(OP_DOUBLE_UNARY_MINUS_1);
    }
  }

  return NULL;
}


/*******************************************************************************
  6.2.7 op:numeric-unary-plus

  op:numeric-unary-plus($arg as numeric) as numeric

  Summary: Backs up the unary "+" operator and returns its operand with the
  sign unchanged: (+ $arg). Semantically, this operation performs no operation.
********************************************************************************/
class op_numeric_unary_plus : public single_numeric_func
{
public:
  op_numeric_unary_plus(const signature& sig)
    :
    single_numeric_func(sig, FunctionConsts::OP_UNARY_PLUS_1)
  {
  }

  CODEGEN_DECL();
};


PlanIter_t op_numeric_unary_plus::codegen(
    CompilerCB* /*cb*/,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    expr& ann) const
{
  return new OpNumericUnaryIterator(sctx, loc, argv[0], true);
}


class op_double_unary_plus : public single_numeric_func
{
public:
  op_double_unary_plus(const signature& sig)
    :
    single_numeric_func(sig, FunctionConsts::OP_DOUBLE_UNARY_PLUS_1)
  {
  }

  bool specializable() const { return false; }

  CODEGEN_DECL();
};


PlanIter_t op_double_unary_plus::codegen(
    CompilerCB* /*cb*/,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    expr& ann) const
{
  return new OpDoubleUnaryIterator(sctx, loc, argv[0], true);
}


/*******************************************************************************
  6.2.8 op:numeric-unary-minus

  op:numeric-unary-minus($arg as numeric) as numeric

  Summary: Backs up the unary "-" operator and returns its operand with the
  sign reverse: (- $arg).

  For xs:integer and xs:decimal arguments, 0 and 0.0 return 0 and 0.0,
  respectively. For xs:float and xs:double arguments, NaN returns NaN,
  0.0E0 returns -0.0E0 and vice versa. INF returns -INF. -INF returns INF.
********************************************************************************/
class op_numeric_unary_minus : public single_numeric_func
{
public:
  op_numeric_unary_minus(const signature& sig)
    :
    single_numeric_func(sig, FunctionConsts::OP_UNARY_MINUS_1)
  {
  }

  CODEGEN_DECL();
};


PlanIter_t op_numeric_unary_minus::codegen(
    CompilerCB* /*cb*/,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    expr& ann) const
{
  return new OpNumericUnaryIterator(sctx, loc, argv[0], false);
}


class op_double_unary_minus : public single_numeric_func
{
public:
  op_double_unary_minus(const signature& sig)
    :
    single_numeric_func(sig, FunctionConsts::OP_DOUBLE_UNARY_MINUS_1)
  {
  }

  bool specializable() const { return false; }

  CODEGEN_DECL();
};


PlanIter_t op_double_unary_minus::codegen(
    CompilerCB* /*cb*/,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    expr& ann) const
{
  return new OpDoubleUnaryIterator(sctx, loc, argv[0], false);
}


/*******************************************************************************

********************************************************************************/
xqtref_t fn_floor::getReturnType(const fo_expr* caller) const
{
  TypeManager* tm = caller->get_type_manager();
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  const QueryLoc& loc = caller->get_loc();
  const XQType& argType = *(caller->get_arg(0)->get_return_type());
  TypeConstants::quantifier_t quant = argType.get_quantifier();

  if (TypeOps::is_subtype(tm, argType, *rtm.DOUBLE_TYPE_QUESTION, loc))
  {
    return (quant == TypeConstants::QUANT_ONE ?
            rtm.DOUBLE_TYPE_ONE :
            rtm.DOUBLE_TYPE_QUESTION);
  }
  else if (TypeOps::is_subtype(tm, argType, *rtm.FLOAT_TYPE_QUESTION, loc))
  {
    return (quant == TypeConstants::QUANT_ONE ?
            rtm.FLOAT_TYPE_ONE :
            rtm.FLOAT_TYPE_QUESTION);
  }
  else if (TypeOps::is_subtype(tm, argType, *rtm.INTEGER_TYPE_QUESTION, loc))
  {
    return (quant == TypeConstants::QUANT_ONE ?
            rtm.INTEGER_TYPE_ONE :
            rtm.INTEGER_TYPE_QUESTION);
  }
  else if (TypeOps::is_subtype(tm, argType, *rtm.DECIMAL_TYPE_QUESTION, loc))
  {
    return (quant == TypeConstants::QUANT_ONE ?
            rtm.DECIMAL_TYPE_ONE :
            rtm.DECIMAL_TYPE_QUESTION);
  }

  return theSignature.returnType();
}


/*******************************************************************************
  Register the rest of the numeric functions
********************************************************************************/
#define DECL_ARITH( sctx, op, type, xqt )                              \
DECL(sctx, op_numeric_##op##_##type,                                   \
     (createQName(zorba_op_ns, "", "numeric-" #op "-" #type),          \
      GENV_TYPESYSTEM.xqt##_TYPE_QUESTION,                             \
      GENV_TYPESYSTEM.xqt##_TYPE_QUESTION,                             \
      GENV_TYPESYSTEM.xqt##_TYPE_QUESTION))


#define DECL_ALL_ARITH( sctx, op )                             \
DECL(sctx, op_numeric_##op,                                    \
     (createQName(xquery_op_ns, "", "numeric-" #op),           \
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,                \
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,                \
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));              \
                                                               \
DECL_ARITH(sctx, op, double, DOUBLE);                          \
DECL_ARITH(sctx, op, float, FLOAT);                            \
DECL_ARITH(sctx, op, decimal, DECIMAL);                        \
DECL_ARITH(sctx, op, integer, INTEGER)


void populateContext_Numerics(static_context* sctx)
{
  const char* xquery_op_ns = static_context::XQUERY_OP_NS;
  const char* zorba_op_ns = static_context::ZORBA_OP_NS;

  DECL_ALL_ARITH (sctx, add);
  DECL_ALL_ARITH (sctx, subtract);
  DECL_ALL_ARITH (sctx, multiply);
  DECL_ALL_ARITH (sctx, divide);

  DECL(sctx, op_numeric_integer_divide,
       (createQName(xquery_op_ns, "", "numeric-integer-divide"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

  DECL(sctx, op_numeric_mod,
       (createQName(zorba_op_ns, "", "numeric-mod"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

  /*
      XPath 2.0 Specification
      http://www.w3.org/TR/xpath20/#id-arithmetic says that:
      If the atomized operand is an empty sequence, the result
      of the arithmetic expression is an empty sequence, and the
      implementation need not evaluate the other operand or
      apply the operator.

      Thus the arithmetic operators allow for empty sequences
      as parameters and return results, contrary to the signature
      of these functions as described in XQuery and XPath Functions
      Specification.
  */
  DECL(sctx, op_numeric_unary_minus,
       (createQName(xquery_op_ns, "", "unary-minus"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

  DECL(sctx, op_double_unary_minus,
       (createQName(zorba_op_ns, "", "double-minus"),
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION,
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION));

  DECL(sctx, op_numeric_unary_plus,
       (createQName(xquery_op_ns, "", "unary-plus"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

  DECL(sctx, op_double_unary_plus,
       (createQName(zorba_op_ns, "", "double-plus"),
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION,
        GENV_TYPESYSTEM.DOUBLE_TYPE_QUESTION));
}


}
/* vim:set et sw=2 ts=2: */
