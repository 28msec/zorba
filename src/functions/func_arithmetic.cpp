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

#include <vector>

#include "system/globalenv.h"

#include "functions/func_arithmetic.h"
#include "functions/function_impl.h"

#include "runtime/core/arithmetic_impl.h"

#include "types/typeops.h"

namespace zorba {


/*******************************************************************************
  binary_arith_func is an abstract function class representing the builtin
  operations of addition, subtraction, multiplication, division, integer
  devision, and modulo for all combinations of atomic data types for which
  these operations are defined.

  The actual operations are represented by subclasses of this class, one for
  each operation, e.g., op_add, op_substract, etc. The runtime iterators 
  associated with these functions can handle any acceptable combination of
  operand types. However, for better performance operations, the optimizer
  will try to specialize these functions to other functions that are specific
  to the type of the arguments. For example:

  op_add(xs:integer, xs:double) --> op_add_numeric_double(xs:double, xs:double) 
********************************************************************************/
class binary_arith_func : public function 
{
public:
  binary_arith_func(const signature& sig, FunctionConsts::FunctionKind kind)
    :
    function(sig, kind)
  {
  }

  virtual bool isArithmeticFunction() const { return true; }

  xqtref_t getReturnType(
        const TypeManager* tm,
        const std::vector<xqtref_t>& arg_types) const;
  
  virtual bool specializable() const { return true; }

  function* specialize(
        static_context* sctx,
        const std::vector<xqtref_t>& argTypes) const;
};


xqtref_t binary_arith_func::getReturnType(
    const TypeManager* tm,
    const std::vector<xqtref_t>& arg_types) const 
{
  bool numeric0 = TypeOps::is_numeric(tm, *arg_types[0]);
  bool numeric1 = TypeOps::is_numeric(tm, *arg_types[1]);
  ArithmeticConsts::OperationKind arithKind = arithmeticKind();

  if (numeric0 && numeric1) 
  {
    return TypeOps::arithmetic_type(tm,
                                    *arg_types[0],
                                    *arg_types[1],
                                    arithKind == ArithmeticConsts::DIVISION);
  }
  else if ((numeric0 || numeric1) && 
           (arithKind == ArithmeticConsts::ADDITION ||
            arithKind == ArithmeticConsts::SUBTRACTION))
  {
    return TypeOps::arithmetic_type(tm, *arg_types[0], *arg_types[1], false);
  }
           

  if (TypeOps::is_empty(tm, *arg_types [0]))
    return arg_types[0];

  if (TypeOps::is_empty(tm, *arg_types [1]))
    return arg_types[1];

  int cnt1 = TypeOps::type_min_cnt(tm, *arg_types [0]);
  int cnt2 = TypeOps::type_min_cnt(tm, *arg_types [0]);
  if (cnt2 < cnt1) cnt1 = cnt2;

  return (cnt1 == 0 ?
          GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION :
          GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE);
}


function* binary_arith_func::specialize(
    static_context* sctx,
    const std::vector<xqtref_t>& argTypes) const 
{
  const TypeManager* tm = sctx->get_typemanager();

  xqtref_t t0 = argTypes[0];
  xqtref_t t1 = argTypes[1];
    
  if (TypeOps::is_numeric(tm, *t0) && TypeOps::is_numeric(tm, *t1)) 
  {
    function* f1 = NULL;
    function* f2 = NULL;

    switch (theKind)
    {
    case FunctionConsts::OP_ADD_2:
      f1 = GET_BUILTIN_FUNCTION(OP_NUMERIC_ADD_2);
      break;
    case FunctionConsts::OP_SUBTRACT_2:
      f1 = GET_BUILTIN_FUNCTION(OP_NUMERIC_SUBTRACT_2);
      break;
    case FunctionConsts::OP_MULTIPLY_2:
      f1 = GET_BUILTIN_FUNCTION(OP_NUMERIC_MULTIPLY_2);
      break;
    case FunctionConsts::OP_DIVIDE_2:
      f1 = GET_BUILTIN_FUNCTION(OP_NUMERIC_DIVIDE_2);
      break;
    case FunctionConsts::OP_INTEGER_DIVIDE_2:
      f1 = GET_BUILTIN_FUNCTION(OP_NUMERIC_INTEGER_DIVIDE_2);
      break;
    case FunctionConsts::OP_MOD_2:
      f1 = GET_BUILTIN_FUNCTION(OP_NUMERIC_MOD_2);
      break;
    default:
      ZORBA_ASSERT(false);
    }

    f2 = f1->specialize(sctx, argTypes);

    return f2 == NULL ? f1 : f2;
  }

  return NULL;
}


/*******************************************************************************
  generic add
********************************************************************************/
class op_add : public binary_arith_func
{
public:
  op_add(const signature& sig) 
    :
    binary_arith_func(sig, FunctionConsts::OP_ADD_2)
  {
  }

  ArithmeticConsts::OperationKind arithmeticKind() const 
  {
    return ArithmeticConsts::ADDITION;
  }

  DEFAULT_BINARY_CODEGEN(GenericArithIterator<AddOperation>)
};
  

/*******************************************************************************
  generic subtract
********************************************************************************/
class op_subtract : public binary_arith_func 
{
public:
  op_subtract(const signature& sig)
    :
    binary_arith_func(sig, FunctionConsts::OP_SUBTRACT_2)
  {
  }

  ArithmeticConsts::OperationKind arithmeticKind() const 
  {
    return ArithmeticConsts::SUBTRACTION;
  }

  DEFAULT_BINARY_CODEGEN(GenericArithIterator<SubtractOperation>);
};
  

/*******************************************************************************
  generic multiply
********************************************************************************/
class op_multiply : public binary_arith_func
{
public:
  op_multiply(const signature& sig) 
    :
    binary_arith_func(sig, FunctionConsts::OP_MULTIPLY_2)
  {
  }

  ArithmeticConsts::OperationKind arithmetiKind() const 
  {
    return ArithmeticConsts::MULTIPLICATION;
  }

  DEFAULT_BINARY_CODEGEN(GenericArithIterator<MultiplyOperation>);
};


/*******************************************************************************
  generic divide
********************************************************************************/
class op_divide : public binary_arith_func
{
public:
  op_divide(const signature& sig)
    :
    binary_arith_func(sig, FunctionConsts::OP_DIVIDE_2)
  {
  }

  ArithmeticConsts::OperationKind arithmeticKind() const 
  {
    return ArithmeticConsts::DIVISION;
  }

  DEFAULT_BINARY_CODEGEN(GenericArithIterator<DivideOperation>);
};


/*******************************************************************************
  6.2.5 op:numeric-integer-divide
********************************************************************************/
class op_integer_divide : public binary_arith_func
{
public:
  op_integer_divide(const signature& sig) 
    :
    binary_arith_func(sig, FunctionConsts::OP_INTEGER_DIVIDE_2)
  {
  }

  ArithmeticConsts::OperationKind arithmeticKind() const 
  {
    return ArithmeticConsts::INTEGER_DIVISION;
  }

  DEFAULT_BINARY_CODEGEN(GenericArithIterator<IntegerDivideOperation>)
};


/*******************************************************************************
   6.2.6 op:numeric-mod
********************************************************************************/
class op_mod : public binary_arith_func
{
public:
	op_mod(const signature& sig) 
    :
    binary_arith_func(sig, FunctionConsts::OP_MOD_2)
  {
  }

  ArithmeticConsts::OperationKind arithmeticKind() const 
  {
    return ArithmeticConsts::MODULO;
  }

  DEFAULT_BINARY_CODEGEN(GenericArithIterator<ModOperation>)
};


/*******************************************************************************
  Register generic arithmetic functions
********************************************************************************/
void populateContext_Arithmetics(static_context* sctx) 
{
  const char* xquery_op_ns = static_context::XQUERY_OP_NS.c_str();

  DECL(sctx, op_add,
       (createQName (xquery_op_ns, "", "add"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

  DECL(sctx, op_subtract,
       (createQName (xquery_op_ns, "", "subtract"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

  DECL(sctx, op_multiply,
       (createQName (xquery_op_ns, "", "multiply"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

  DECL(sctx, op_divide,
       (createQName (xquery_op_ns, "", "divide"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

  DECL(sctx, op_integer_divide,
       (createQName (xquery_op_ns, "", "integer-divide"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));

  DECL(sctx, op_mod,
       (createQName (xquery_op_ns, "", "mod"),
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION));
}


}
/* vim:set et sw=2 ts=2: */
