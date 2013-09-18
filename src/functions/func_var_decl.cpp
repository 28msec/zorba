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

  bool mustCopyInputNodes(expr* fo, csize input) const
  {
    return false;
  }

  CODEGEN_DECL();
};


PlanIter_t ctx_var_get::codegen(
    CompilerCB* cb,
    static_context* sctx, 
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    expr& ann) const
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
  util:context-item()
  
  This library also contains the declaration of the ZORBA_UTIL_FN_NS 
  "http://zorba.io/util-functions" context-item() function,
  which is a placeholder for the "." or "$$" context item accessors, as a 
  universal and language-neutral (XQuery and JSONiq) function.   
********************************************************************************/  
class context_item : public function
{
public:
  context_item(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_CONTEXT_ITEM_0)
  {
  }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize input) const
  {
    return false;
  }

  PlanIter_t codegen(
      CompilerCB* cb,
      static_context* sctx, 
      const QueryLoc& loc,
      std::vector<PlanIter_t>& argv,
      expr& ann) const
  {
    assert(false); // It should never reach here
    return NULL;
  }
};


/*******************************************************************************

********************************************************************************/
void populateContext_VarDecl(static_context* sctx)
{
  const char* zorba_op_ns = static_context::ZORBA_OP_NS;
      
  DECL(sctx, ctx_var_get,
       (createQName(zorba_op_ns, "", "ctxvar-get"),
        GENV_TYPESYSTEM.ITEM_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
  
  DECL(sctx, context_item,
       (createQName(static_context::ZORBA_UTIL_FN_NS, "", "context-item"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}

}
/* vim:set et sw=2 ts=2: */
