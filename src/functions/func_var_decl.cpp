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

#include "system/globalenv.h"

#include "functions/func_var_decl.h"
#include "functions/function_impl.h"

#include "compiler/api/compilercb.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/var_expr.h"

#include "runtime/core/var_iterators.h"


namespace zorba
{


/*******************************************************************************
  ctxvar-assign(varExpr, initExpr)

  This internal function is used to initialize prolog variables (including the
  context item, if it is declared in the prolog) that do have an initializing
  expr, or to assign a value to a prolog or block-local var. During runtime,
  the function computes the initExpr and stores the resulting value inside the
  appropriate dynamic ctx (global or local), at the location that is identified
  by the variable id.
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

  short getScriptingKind() const { return VAR_SETTING_EXPR; }

  CODEGEN_DECL();
};


PlanIter_t ctx_var_assign::codegen(
    CompilerCB* cb,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder& ann) const
{
  const fo_expr& foExpr = static_cast<const fo_expr&>(ann);

  assert(foExpr.get_arg(0)->get_expr_kind() == var_expr_kind);

  const var_expr* varExpr = static_cast<const var_expr*>(foExpr.get_arg(0));

  xqtref_t exprType = foExpr.get_arg(1)->get_return_type();

  CtxVarAssignIterator* iter = 
  new CtxVarAssignIterator(sctx,
                           loc,
                           varExpr->get_unique_id(),
                           varExpr->get_name(),
                           (varExpr->get_kind() == var_expr::local_var),
                           argv[1]);
  
  if (exprType->get_quantifier() == TypeConstants::QUANT_ONE)
    iter->setSingleItem();

  return iter;
}


/*******************************************************************************
  ctxvar-get(varExpr)

  An "artificial" function that is needed by the optimizer only. During runtime,
  it acts as a var reference for a prolog or local var, ie, its associated
  runtime iterator is CtxVarIterator. During translation, the expr 
  treat(ctxvar-get(varExpr), type) is created if a prolog/local var declaration
  has an associated type declaration. The purpose of the ctxvar-get is to "hide"
  the type of the variable from the treat expr (the type of ctxvar-get(varExpr)
  is item()*), so that the optimizer will not remove the treat expr. 
********************************************************************************/
class ctx_var_get : public function
{
public:
  ctx_var_get(const signature& sig)
    :
    function(sig, FunctionConsts::OP_VAR_GET_1)
  {
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


PlanIter_t ctx_var_get::codegen(
    CompilerCB* cb,
    static_context* sctx, 
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder& ann) const
{
  const fo_expr& foExpr = static_cast<const fo_expr&>(ann);

  assert(foExpr.get_arg(0)->get_expr_kind() == var_expr_kind);

  const var_expr* varExpr = static_cast<const var_expr*>(foExpr.get_arg(0));

  return new CtxVarIterator(sctx,
                            loc,
                            varExpr->get_unique_id(), 
                            varExpr->get_name(),
                            (varExpr->get_kind() == var_expr::local_var)); 
}


/*******************************************************************************

********************************************************************************/
void populateContext_VarDecl(static_context* sctx)
{
  const char* zorba_op_ns = static_context::ZORBA_OP_NS.c_str();

  DECL(sctx, ctx_var_assign,
       (createQName(zorba_op_ns, "", "ctxvar-assign"),
        GENV_TYPESYSTEM.ITEM_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.EMPTY_TYPE));

  DECL(sctx, ctx_var_get,
       (createQName(zorba_op_ns, "", "ctxvar-get"),
        GENV_TYPESYSTEM.ITEM_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}


}
/* vim:set et sw=2 ts=2: */
