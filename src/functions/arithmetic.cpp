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

  const function *binary_arith_func::specialize(static_context *sctx, const std::vector<xqtref_t>& argTypes) const {
    xqtref_t t0 = argTypes[0];
    xqtref_t t1 = argTypes[1];
    
    if (TypeOps::is_simple(*t0) && TypeOps::is_simple(*t1)) {
      TypeConstants::atomic_type_code_t tc0 = TypeOps::get_atomic_type_code(*t0);
      TypeConstants::atomic_type_code_t tc1 = TypeOps::get_atomic_type_code(*t1);
      
      if (TypeOps::is_numeric (*t0) && TypeOps::is_numeric (*t1) && tc0 == tc1)
        return sctx->lookup_builtin_fn (std::string (":numeric-") + op_name (), 2)->specialize (sctx, argTypes);
    }
    return NULL;
  }

  // 6.2.1 op:add
  // --------------------
  class op_add : public binary_arith_func
  {
  public:
    op_add(const signature& sig) : binary_arith_func (sig) {}
    const char *op_name () const { return "add"; }
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  // 6.2.3 op:numeric-multiply
  // -------------------------
  class op_multiply : public binary_arith_func
  {
  public:
    op_multiply(const signature& sig) : binary_arith_func (sig) {}
    const char *op_name () const { return "multiply"; }
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };


  // 6.2.4 op:numeric-divide
  // -----------------------
  class op_divide : public binary_arith_func
  {
  public:
    op_divide(const signature& sig) : binary_arith_func (sig) {}
    const char *op_name () const { return "divide"; }
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  // 6.2.5 op:numeric-integer-divide
  // -------------------------------
  class op_integer_divide : public function
  {
  public:
	op_integer_divide(const signature& sig) : function (sig) {}
    virtual bool isArithmeticFunction() const { return true; }
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };

  // 6.2.6 op:numeric-mod
  // --------------------
  class op_mod : public function
  {
  public:
	op_mod(const signature& sig) : function (sig) {}
    virtual bool isArithmeticFunction() const { return true; }
    PlanIter_t codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
  };


PlanIter_t op_add::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<AddOperation>(loc, argv[0], argv[1]);
}



PlanIter_t op_subtract::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<SubtractOperation>(loc, argv[0], argv[1]);
}

PlanIter_t op_multiply::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<MultiplyOperation>(loc, argv[0], argv[1]);
}



PlanIter_t op_divide::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<DivideOperation>(loc, argv[0], argv[1]);
}



PlanIter_t op_integer_divide::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<IntegerDivideOperation>(loc, argv[0], argv[1]);
}



PlanIter_t op_mod::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
	return new GenericArithIterator<ModOperation>(loc, argv[0], argv[1]);
}


void populateContext_Arithmetics(static_context *sctx) {
// Generic Arithmetics
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
