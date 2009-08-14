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

#include "system/globalenv.h"
#include "functions/arithmetic.h"
#include "functions/function_impl.h"
#include "runtime/core/arithmetic_impl.h"
#include "types/typeops.h"

using namespace std;

namespace zorba {


/*******************************************************************************
  binary_arith_func is an abstract function class representing the builtin
  operations of addition, subtraction, multiplication, division, integer
  devision, and modulo for all combinations of atomic data types for which
  these operations are defined.

  The actual operations are represented by subclasses of this class, one for
  each operation, e.g., op_add, op_substract, etc. The runtime iterators 
  associated with these functions can handle any acceptable combination of
  operand types. However, for better performance of numeric operations, the
  optimizer will try to specialize these functions to other functions that
  are specific to the type of the arguments. For example:

  op_add(xs:integer, xs:double) --> op_add_numeric_double(xs:double, xs:double) 
********************************************************************************/
class binary_arith_func : public function 
{
public:
  binary_arith_func (const signature& sig) : function (sig) {}

  virtual bool isArithmeticFunction() const { return true; }

  virtual const char* op_name() const = 0;

  xqtref_t return_type (const std::vector<xqtref_t>& arg_types) const;
  
  virtual bool specializable() const { return true; }

  const function* specialize(
        static_context* sctx,
        const std::vector<xqtref_t>& argTypes) const;
};


xqtref_t binary_arith_func::return_type(const std::vector<xqtref_t>& arg_types) const 
{
  if (TypeOps::is_numeric(*arg_types[0]) && TypeOps::is_numeric(*arg_types[1])) 
  {
    return TypeOps::arithmetic_type(*arg_types[0],
                                    *arg_types[1],
                                    arithmetic_kind() == ArithmeticConsts::DIVISION);
  }

  if (TypeOps::is_empty(*arg_types [0]))
    return arg_types[0];

  if (TypeOps::is_empty(*arg_types [1]))
    return arg_types[1];

  int cnt1 = TypeOps::type_min_cnt(*arg_types [0]);
  int cnt2 = TypeOps::type_min_cnt(*arg_types [0]);
  if (cnt2 < cnt1) cnt1 = cnt2;

  return (cnt1 == 0 ?
          GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION :
          GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE);
}


const function* binary_arith_func::specialize(
    static_context* sctx,
    const std::vector<xqtref_t>& argTypes) const 
{
  xqtref_t t0 = argTypes[0];
  xqtref_t t1 = argTypes[1];
    
  if (TypeOps::is_builtin_simple(*t0) && TypeOps::is_builtin_simple(*t1)) 
  {
    TypeConstants::atomic_type_code_t tc0 = TypeOps::get_atomic_type_code(*t0);
    TypeConstants::atomic_type_code_t tc1 = TypeOps::get_atomic_type_code(*t1);
      
    if (TypeOps::is_numeric(*t0) && TypeOps::is_numeric(*t1) && tc0 == tc1) 
    {
      const function* f1;
      const function* f2;
      f1 = sctx->lookup_builtin_fn(std::string(":numeric-") + op_name(), 2);
      f2 = f1->specialize(sctx, argTypes);

      return f2 == NULL ? f1 : f2;
    }
  }
  return NULL;
}


/*******************************************************************************
  generic add
********************************************************************************/
class op_add : public binary_arith_func
{
public:
  op_add(const signature& sig) : binary_arith_func (sig) {}

  const char* op_name() const { return "add"; }

  ArithmeticConsts::OperationKind arithmetic_kind() const 
  {
    return ArithmeticConsts::ADDITION;
  }

  DEFAULT_CODEGEN_BINARY(GenericArithIterator<AddOperation>)
};
  

/*******************************************************************************
  generic subtract
********************************************************************************/
class op_subtract : public binary_arith_func 
{
public:
  op_subtract(const signature& sig) : binary_arith_func (sig) {}

  const char* op_name() const { return "subtract"; }

  ArithmeticConsts::OperationKind arithmetic_kind() const 
  {
    return ArithmeticConsts::SUBTRACTION;
  }

  DEFAULT_CODEGEN_BINARY(GenericArithIterator<SubtractOperation>);
};
  

/*******************************************************************************
  generic multiply
********************************************************************************/
class op_multiply : public binary_arith_func
{
public:
  op_multiply(const signature& sig) : binary_arith_func (sig) {}

  const char* op_name() const { return "multiply"; }

  ArithmeticConsts::OperationKind arithmetic_kind() const 
  {
    return ArithmeticConsts::MULTIPLICATION;
  }

  DEFAULT_CODEGEN_BINARY(GenericArithIterator<MultiplyOperation>);
};


/*******************************************************************************
  generic divide
********************************************************************************/
class op_divide : public binary_arith_func
{
public:
  op_divide(const signature& sig) : binary_arith_func (sig) {}

  const char* op_name() const { return "divide"; }

  ArithmeticConsts::OperationKind arithmetic_kind() const 
  {
    return ArithmeticConsts::DIVISION;
  }

  DEFAULT_CODEGEN_BINARY(GenericArithIterator<DivideOperation>);
};


/*******************************************************************************
  6.2.5 op:numeric-integer-divide
********************************************************************************/
class op_integer_divide : public binary_arith_func
{
public:
  op_integer_divide(const signature& sig) : binary_arith_func(sig) {}

  const char* op_name() const { return "integer-divide"; }

  ArithmeticConsts::OperationKind arithmetic_kind() const 
  {
    return ArithmeticConsts::INTEGER_DIVISION;
  }

  DEFAULT_CODEGEN_BINARY(GenericArithIterator<IntegerDivideOperation>)
};


/*******************************************************************************
   6.2.6 op:numeric-mod
********************************************************************************/
class op_mod : public binary_arith_func
{
public:
	op_mod(const signature& sig) : binary_arith_func(sig) {}

  const char* op_name() const { return "mod"; }

  ArithmeticConsts::OperationKind arithmetic_kind() const 
  {
    return ArithmeticConsts::MODULO;
  }

  DEFAULT_CODEGEN_BINARY(GenericArithIterator<ModOperation>)
};


/*******************************************************************************
  Register generic arithmetic functions
********************************************************************************/
void populateContext_Arithmetics(static_context* sctx) 
{
DECL(sctx, op_add,
     (createQName (XQUERY_OP_NS,"fn", ":add"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, op_subtract,
     (createQName (XQUERY_OP_NS,"fn", ":subtract"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, op_multiply,
     (createQName (XQUERY_OP_NS,"fn", ":multiply"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, op_divide,
     (createQName (XQUERY_OP_NS,"fn", ":divide"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, op_integer_divide,
     (createQName (XQUERY_OP_NS,"fn", ":integer-divide"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

DECL(sctx, op_mod,
     (createQName (XQUERY_OP_NS,"fn", ":mod"),
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));
}


}
