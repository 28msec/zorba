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

#include "functions/Numerics.h"
#include "functions/arithmetic.h"
#include "functions/function_impl.h"

#include "system/globalenv.h"

#include "runtime/numerics/NumericsImpl.h"
#include "runtime/booleans/BooleanImpl.h"

#include "types/typeops.h"

#include "context/namespace_context.h"

using namespace std;

namespace zorba {

  class single_numeric_func : public function {
  public:
    single_numeric_func (const signature &sig) : function (sig) {}
    virtual xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;
    virtual bool isArithmeticFunction() const { return true; }
  };

  class bin_num_arith_func : public function {
  public:
    bin_num_arith_func (const signature &sig) : function (sig) {}
    virtual xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const;
    virtual bool isArithmeticFunction() const { return true; }
  };

/*______________________________________________________________________
|  
| 6.2 Operators on Numeric Values
|_______________________________________________________________________*/

// base class factored out for benefit of divide specialization
template<class op, TypeConstants::atomic_type_code_t t>
class bin_num_specific_arith_func_base : public bin_num_arith_func
{
public:
  bin_num_specific_arith_func_base (const signature &sig) : bin_num_arith_func (sig) {}
  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const {
    return new SpecificNumArithIterator<op, t> (loc, argv[0], argv[1]);
  }
};

template<class op, TypeConstants::atomic_type_code_t t>
class bin_num_specific_arith_func : public bin_num_specific_arith_func_base<op, t>
{
public:
  bin_num_specific_arith_func (const signature &sig)
    : bin_num_specific_arith_func_base<op, t> (sig)
  {}
};

template<TypeConstants::atomic_type_code_t t>
class bin_num_specific_arith_func<DivideOperation, t> : public bin_num_specific_arith_func_base<DivideOperation, t>
{
public:
  bin_num_specific_arith_func (const signature &sig) : bin_num_specific_arith_func_base<DivideOperation, t> (sig) {}
  xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const {
    return binary_arith_func::atomic_return_type (arg_types);
  }
};

#define DECL_SPECIFIC_OP( op, opc, t, xqt )                        \
  typedef bin_num_specific_arith_func<opc, TypeConstants::XS_##xqt>  \
  op_numeric_##op##_##t;
#define DECL_ALL_SPECIFIC_OPS( op, opc )         \
  DECL_SPECIFIC_OP (op, opc, double, DOUBLE);    \
  DECL_SPECIFIC_OP (op, opc, decimal, DECIMAL);  \
  DECL_SPECIFIC_OP (op, opc, float, FLOAT);      \
  DECL_SPECIFIC_OP (op, opc, integer, INTEGER)

  DECL_ALL_SPECIFIC_OPS (add, AddOperation);
  DECL_ALL_SPECIFIC_OPS (subtract, SubtractOperation);
  DECL_ALL_SPECIFIC_OPS (multiply, MultiplyOperation);
  DECL_ALL_SPECIFIC_OPS (divide, DivideOperation);
#undef DECL_ALL_SPECIFIC_OPS
#undef DECL_SPECIFIC_OP

static const function *specialize_numeric (static_context *sctx, const std::vector<xqtref_t>& argTypes, const char *op) {
  xqtref_t t0 = argTypes[0];
  xqtref_t t1 = argTypes[1];
  ostringstream oss;

  oss << ":" "numeric-" << op << "-";
  if (TypeOps::is_simple(*t0) && TypeOps::is_simple (*t1)) {
    TypeConstants::atomic_type_code_t tc0 = TypeOps::get_atomic_type_code(*t0);
    TypeConstants::atomic_type_code_t tc1 = TypeOps::get_atomic_type_code(*t1);
    
    if (tc0 == tc1) {
      switch(tc0) {
      case TypeConstants::XS_DOUBLE:
        oss << "double";
        return sctx->lookup_builtin_fn (oss.str (), 2);
        
      case TypeConstants::XS_DECIMAL:
        oss << "decimal";
        return sctx->lookup_builtin_fn (oss.str (), 2);
        
      case TypeConstants::XS_FLOAT:
        oss << "float";
        return sctx->lookup_builtin_fn (oss.str (), 2);
        
      case TypeConstants::XS_INTEGER:
        oss << "integer";
        return sctx->lookup_builtin_fn (oss.str (), 2);
        
      default:
        return NULL;
      }
    }
  }
  return NULL;
}

class specializable_bin_num_arith_func : public bin_num_arith_func {
public:
  specializable_bin_num_arith_func (const signature &sig)
    : bin_num_arith_func (sig) {};
  virtual const char *op_name () const = 0;
  virtual bool specializable() const { return true; }
  const function *specialize(static_context *sctx, const std::vector<xqtref_t>& argTypes) const {
    return specialize_numeric (sctx, argTypes, op_name ());
  }
};

// 6.2.1 op:numeric-add
// --------------------
class op_numeric_add : public specializable_bin_num_arith_func
{
public:
  const char *op_name () const { return "add"; }
  op_numeric_add(const signature &sig) : specializable_bin_num_arith_func (sig) {};
  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// 6.2.2 op:numeric-subtract
// -------------------------
class op_numeric_subtract : public specializable_bin_num_arith_func
{
public:
  const char *op_name () const { return "subtract"; }
  op_numeric_subtract(const signature &sig) : specializable_bin_num_arith_func (sig) {};
  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};


// 6.2.3 op:numeric-multiply
// -------------------------
class op_numeric_multiply : public specializable_bin_num_arith_func
{
public:
  const char *op_name () const { return "multiply"; }
  op_numeric_multiply(const signature &sig) : specializable_bin_num_arith_func (sig) {};
  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// 6.2.4 op:numeric-divide
// -----------------------
class op_numeric_divide : public specializable_bin_num_arith_func
{
public:
  const char *op_name () const { return "divide"; }
  op_numeric_divide(const signature &sig) : specializable_bin_num_arith_func (sig) {};
  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  xqtref_t return_type (const std::vector<xqtref_t> &arg_types) const {
    return function::return_type (arg_types);
  }
};

// 6.2.5 op:numeric-integer-divide
// -------------------------------
class op_numeric_integer_divide : public bin_num_arith_func
{
public:
  op_numeric_integer_divide(const signature &sig) : bin_num_arith_func (sig) {};
  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// 6.2.6 op:numeric-mod
// --------------------
class op_numeric_mod : public bin_num_arith_func
{
public:
  op_numeric_mod(const signature &sig) : bin_num_arith_func (sig) {};
  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// 6.2.7 op:numeric-unary-plus
// ---------------------------
class op_numeric_unary_plus : public single_numeric_func
{
public:
  op_numeric_unary_plus(const signature&);
  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};


// 6.2.8 op:numeric-unary-minus
// ----------------------------
class op_numeric_unary_minus : public single_numeric_func
{
public:
  op_numeric_unary_minus(const signature&);
  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};


/*______________________________________________________________________
|  
| 6.4 Functions on Numeric Values
|_______________________________________________________________________*/

// 6.4.1 fn:abs
class fn_abs : public single_numeric_func 
{
public:
  fn_abs(const signature&);
  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// 6.4.2 fn:ceiling
class fn_ceiling : public single_numeric_func
{
  public:
    fn_ceiling(const signature&);
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// 6.4.3 fn:floor
class fn_floor : public single_numeric_func
{
  public:
    fn_floor(const signature&);
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// 6.4.4 fn:round
class fn_round : public single_numeric_func
{
  public:
    fn_round(const signature&);
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

// 6.4.5 fn:round-half-to-even
class fn_round_half_to_even : public single_numeric_func
{
  public:
    fn_round_half_to_even(const signature&);
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};


xqtref_t single_numeric_func::return_type (const std::vector<xqtref_t> &arg_types) const {
  return arg_types [0];
}

xqtref_t bin_num_arith_func::return_type (const std::vector<xqtref_t> &arg_types) const {
  if (TypeOps::is_empty (*arg_types [0]))
    return arg_types [0];
  if (TypeOps::is_empty (*arg_types [1]))
    return arg_types [1];
  return TypeOps::arithmetic_type (*arg_types [0], *arg_types [1]);
}

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

PlanIter_t op_numeric_add::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new NumArithIterator<AddOperation>(loc, argv[0], argv[1]);
}





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

PlanIter_t op_numeric_subtract::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new NumArithIterator<SubtractOperation>(loc, argv[0], argv[1]);
}





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

PlanIter_t op_numeric_multiply::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new NumArithIterator<MultiplyOperation>(loc, argv[0], argv[1]);
}


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

PlanIter_t op_numeric_divide::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new NumArithIterator<DivideOperation>(loc, argv[0], argv[1]);
}





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

PlanIter_t op_numeric_integer_divide::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new NumArithIterator<IntegerDivideOperation>(loc, argv[0], argv[1]);
}





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

PlanIter_t op_numeric_mod::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new NumArithIterator<ModOperation>(loc, argv[0], argv[1]);
}



/*______________________________________________________________________
 *  |  
 *  -| 6.2.7 op:numeric-unary-plus
 *  -| op:numeric-unary-plus($arg as numeric) as numeric
 *  -| 
 *  -| Summary: Backs up the unary "+" operator and returns its operand with 
 *  -| the sign unchanged: (+ $arg). Semantically, this operation performs no 
 *  -| operation.
 *  -|_______________________________________________________________________*/

op_numeric_unary_plus::op_numeric_unary_plus(
  const signature& sig)
:
  single_numeric_func(sig)
{
}

PlanIter_t op_numeric_unary_plus::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new OpNumericUnaryIterator(loc, argv[0], true);
}


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

op_numeric_unary_minus::op_numeric_unary_minus(
  const signature& sig)
:
  single_numeric_func(sig)
{
}

PlanIter_t op_numeric_unary_minus::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new OpNumericUnaryIterator(loc, argv[0], false);
}



  
/*______________________________________________________________________
|  
| 6.3 Comparison Operators on Numeric Values
|_______________________________________________________________________*/

// 6.3.1 op:numeric-equal
// 6.3.2 op:numeric-less-than
// 6.3.3 op:numeric-greater-than


/*______________________________________________________________________
|  
| 6.4 Functions on Numeric Values
|_______________________________________________________________________*/

// 6.4.1 fn:abs
fn_abs::fn_abs(const signature& sig)
:
  single_numeric_func(sig)
{     
}

PlanIter_t fn_abs::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnAbsIterator(loc, argv);
}



// 6.4.2 fn:ceiling
fn_ceiling::fn_ceiling(const signature& sig)
:
single_numeric_func(sig)
{}

PlanIter_t fn_ceiling::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnCeilingIterator(loc, argv);
}



// 6.4.3 fn:floor
fn_floor::fn_floor(const signature& sig)
:
single_numeric_func(sig)
{}

PlanIter_t fn_floor::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnFloorIterator(loc, argv);
}


// 6.4.4 fn:round
fn_round::fn_round(const signature& sig)
:
single_numeric_func(sig)
{}

PlanIter_t fn_round::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnRoundIterator(loc, argv);
}



// 6.4.5 fn:round-half-to-even
fn_round_half_to_even::fn_round_half_to_even(const signature& sig)
:
single_numeric_func(sig)
{}

PlanIter_t
fn_round_half_to_even::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new FnRoundHalfToEvenIterator(loc, argv);
}



PlanIter_t zor_numgen::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorNumGen(loc);
}

class fn_sqrt : public single_numeric_func
{
public:
  fn_sqrt(const signature& sig) : single_numeric_func (sig) {}
  PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const {
    return new FnSQRTIterator(loc, argv);
  }
};

/*______________________________________________________________________
|
| XQuery 1.1 functions
|_______________________________________________________________________*/

class fn_format_number_2 : public function
{
public:
  fn_format_number_2(const signature& sig) : function(sig) {};
  PlanIter_t codegen(const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
  {
    return new FnFormatNumberIterator(loc, argv);
  }
};

class fn_format_number_3 : public function
{
public:
  fn_format_number_3(const signature& sig) : function(sig) {};
  PlanIter_t codegen(const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
  {
    return new FnFormatNumberIterator(loc, argv);
  }
};

/*______________________________________________________________________
|  
| Functions declarations
|_______________________________________________________________________*/


#define DECL_DOUBLE_MATH_FUN( name, iter )                              \
  class fn_##name : public function_impl<Fn##iter##Iterator> {          \
  public:                                                               \
  fn_##name (const signature &sig) : function_impl<Fn##iter##Iterator> (sig) {} \
  }

DECL_DOUBLE_MATH_FUN (exp, Exp);
DECL_DOUBLE_MATH_FUN (log, Log);
DECL_DOUBLE_MATH_FUN (sin, Sin);
DECL_DOUBLE_MATH_FUN (cos, Cos);
DECL_DOUBLE_MATH_FUN (tan, Tan);
DECL_DOUBLE_MATH_FUN (asin, ArcSin);
DECL_DOUBLE_MATH_FUN (acos, ArcCos);
DECL_DOUBLE_MATH_FUN (atan, ArcTan);

#define REGISTER_DOUBLE_MATH_FUN( name )                        \
  DECL(sctx, fn_##name,                                         \
       (createQName(ZORBA_MATH_FN_NS, "fn-zorba-math", #name),  \
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE,                        \
        GENV_TYPESYSTEM.DOUBLE_TYPE_ONE))

void populateContext_Math (static_context *sctx) {
  DECL(sctx, fn_sqrt,
       (createQName(ZORBA_MATH_FN_NS,"fn-zorba-math", "sqrt"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));
  
  REGISTER_DOUBLE_MATH_FUN (exp);
  REGISTER_DOUBLE_MATH_FUN (log);
  REGISTER_DOUBLE_MATH_FUN (sin);
  REGISTER_DOUBLE_MATH_FUN (cos);
  REGISTER_DOUBLE_MATH_FUN (tan);
  REGISTER_DOUBLE_MATH_FUN (asin);
  REGISTER_DOUBLE_MATH_FUN (acos);
  REGISTER_DOUBLE_MATH_FUN (atan);
}

#define DECL_ARITH( sctx, op, type, xqt )                              \
  DECL(sctx, op_numeric_##op##_##type,                                   \
       (createQName (XQUERY_OP_NS,"fn", ":numeric-" #op "-" #type),    \
        GENV_TYPESYSTEM.xqt##_TYPE_QUESTION,                           \
        GENV_TYPESYSTEM.xqt##_TYPE_QUESTION,                           \
        GENV_TYPESYSTEM.xqt##_TYPE_QUESTION))

#define DECL_ALL_ARITH( sctx, op )                             \
  DECL(sctx, op_numeric_##op,                                  \
       (createQName (XQUERY_OP_NS, "fn", ":numeric-" #op),     \
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,              \
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,              \
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));            \
  DECL_ARITH( sctx, op, double, DOUBLE );                      \
  DECL_ARITH( sctx, op, float, FLOAT );                        \
  DECL_ARITH( sctx, op, decimal, DECIMAL );                    \
  DECL_ARITH( sctx, op, integer, INTEGER )

void populateContext_Numerics(static_context *sctx) {
// Numerics
DECL_ALL_ARITH (sctx, add);
DECL_ALL_ARITH (sctx, subtract);
DECL_ALL_ARITH (sctx, multiply);
DECL_ALL_ARITH (sctx, divide);

DECL(sctx, op_numeric_integer_divide,
     (createQName (XQUERY_OP_NS,"fn", ":numeric-integer-divide"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, op_numeric_mod,
     (createQName (XQUERY_OP_NS,"fn", ":numeric-mod"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, op_numeric_unary_minus,
     (createQName (XQUERY_OP_NS,"fn", ":unary-minus"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE));

DECL(sctx, op_numeric_unary_plus,
     (createQName (XQUERY_OP_NS,"fn", ":unary-plus"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE));

DECL(sctx, fn_abs,
     (createQName(XQUERY_FN_NS, "fn", "abs"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, fn_ceiling,
     (createQName(XQUERY_FN_NS, "fn", "ceiling"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, fn_floor,
     (createQName(XQUERY_FN_NS, "fn", "floor"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, fn_round,
     (createQName(XQUERY_FN_NS, "fn", "round"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, fn_round_half_to_even,
     (createQName(XQUERY_FN_NS, "fn", "round-half-to-even"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.INTEGER_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, fn_round_half_to_even,
     (createQName(XQUERY_FN_NS, "fn", "round-half-to-even"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

/*______________________________________________________________________
|  
| XQuery 1.1 functions
|_______________________________________________________________________*/

DECL(sctx, fn_format_number_2,
     (createQName(XQUERY_FN_NS, "fn", "format-number"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, fn_format_number_3,
     (createQName(XQUERY_FN_NS, "fn", "format-number"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));
      
// end Numerics

}
  
} /* namespace zorba */

