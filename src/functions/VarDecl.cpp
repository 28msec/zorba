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

#include "system/globalenv.h"

#include "functions/VarDecl.h"
#include "functions/function_impl.h"

#include "compiler/api/compilercb.h"
#include "compiler/expression/fo_expr.h"

#include "runtime/core/var_iterators.h"


namespace zorba
{

/*******************************************************************************
  ctxvar-declare(varName)

  This internal function is used to declare block-local and prolog variables
  (including the context item, if it is declared in the prolog), except for
  external vars without an initalizing expr. During runtime, the function
  registers the varName into the dynamic context.
********************************************************************************/
class ctx_var_declare : public function
{
public:
  ctx_var_declare(const signature& sig) 
    :
    function(sig, FunctionConsts::OP_VAR_DECLARE_1)
  {
  }

  bool accessesDynCtx() const { return true; }

  DEFAULT_NARY_CODEGEN(CtxVarDeclIterator);
};


/*******************************************************************************
  ctxvar-assign(varName, initExpr)

  This internal function is used to initialize prolog variables that do have an
  initializing expr, or to assign a value to a prolog or block-local var. For
  the context item var, the function creates, during runtime, a binding in the
  dynamic ctx between the varName (".") and the actual context item. Otherwise,
  the function creates a binding in the dynamic ctx between the varName and an
  iterator plan that computes the initExpr. 
********************************************************************************/
class ctx_var_assign : public function
{
public:
  ctx_var_assign(const signature& sig) 
    :
    function(sig, FunctionConsts::OP_VAR_ASSIGN_1)
  {
  }

  bool accessesDynCtx() const { return true; }

  expr_script_kind_t getUpdateType() const { return SEQUENTIAL_EXPR; }

  CODEGEN_DECL();
};


PlanIter_t ctx_var_assign::codegen(
    CompilerCB* cb,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder& ann) const
{
  CtxVarAssignIterator* iter = new CtxVarAssignIterator(sctx, loc, argv);

  const fo_expr& expr = reinterpret_cast<const fo_expr&>(ann);

  xqtref_t exprType = expr.get_arg(1)->get_return_type();

  if (exprType->get_quantifier() == TypeConstants::QUANT_ONE)
    iter->setSingleItem();

  return iter;
}


/*******************************************************************************
  ctxvar-exists(varName)

  This internal function is used to check if a prolog of block-local variable
  has been declared. During runtime, it checks if an entry exists for variable
  in the dynamic ctx.
********************************************************************************/
class ctx_var_exists : public function
{
public:
  ctx_var_exists(const signature& sig) 
    :
    function(sig, FunctionConsts::OP_VAR_EXISTS_1)
  {
  }

  bool accessesDynCtx() const { return true; }

  DEFAULT_NARY_CODEGEN(CtxVarExistsIterator);
};


/*******************************************************************************
  ctxvariable(varName)

  This internal function is used to represent references to prolog or block-local
  variables. During runtime, it retrieves from the dymanic context the temp seq
  (or single item) that is associated with varName and returns, one-at-a-time,
  the items stored in that temp seq..
********************************************************************************/ 
class ctx_variable : public function
{
public:
  ctx_variable(const signature& sig) 
    :
    function(sig, FunctionConsts::OP_VAR_REF_1)
  {
  }

  bool accessesDynCtx() const { return true; }

  PlanIter_t codegen(
        CompilerCB* cb,
        static_context* sctx, 
        const QueryLoc& loc,
        std::vector<PlanIter_t>& argv,
        AnnotationHolder& ann) const
  {
    return new CtxVarIterator(sctx, loc, argv[0]); 
  }
};


void populateContext_VarDecl(static_context* sctx)
{
DECL(sctx, ctx_variable,
     (createQName(ZORBA_OP_NS,"op-zorba", "ctxvar-ref"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
DECL(sctx, ctx_var_declare,
     (createQName(ZORBA_OP_NS,"op-zorba", "ctxvar-declare"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.EMPTY_TYPE));
DECL(sctx, ctx_var_assign,
     (createQName(ZORBA_OP_NS,"op-zorba", "ctxvar-assign"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE));
DECL(sctx, ctx_var_exists,
     (createQName(ZORBA_OP_NS,"op-zorba", "ctxvar-exists"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
}


}
