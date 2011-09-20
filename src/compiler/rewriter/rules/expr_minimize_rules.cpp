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

#include "context/static_context.h"

#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/flwor_expr.h"

#include "functions/function.h"

#include "types/typeops.h"

namespace zorba 
{

static expr_t get_constant_if_typequant_one(expr* e, bool& modified);



/*******************************************************************************
  This rule looks for exprs of the form:

  FN(E) or 
  FN(flwor_FE), 
  where FN is one of fn:count, fn:empty, or fn:exists, and flwor_FE is a flwor
  expr whose return expr is FE.

  Then, it checks whether the return type of E/FE has quantifier ONE, and if so,
  it replaces E/FE with the constant 1.

  In fact the check on FE is recursive: if FE does not have a return type with
  quantifier ONE, but FE is a flwor expr with return expr FFE, then the rule is
  applied to FFE and so on.
********************************************************************************/

RULE_REWRITE_PRE(ReplaceExprWithConstantOneWhenPossible) 
{
  if (node->get_expr_kind() != fo_expr_kind)
    return NULL;

  fo_expr* fo = static_cast<fo_expr *>(&*node);
  const function* fn = fo->get_func();
  FunctionConsts::FunctionKind fkind = fn->getKind();

  if (fkind == FunctionConsts::FN_COUNT_1 ||
      fkind == FunctionConsts::FN_EMPTY_1 ||
      fkind == FunctionConsts::FN_EXISTS_1) 
  {
    bool modified = false;
    expr_t child = fo->get_arg(0);
    expr_t nc = get_constant_if_typequant_one(child, modified);
    if (nc != NULL) 
    {
      fo->set_arg(0, nc);
      return node;
    }
  }
  return NULL;
}


RULE_REWRITE_POST(ReplaceExprWithConstantOneWhenPossible) 
{
  return NULL;
}


static expr_t get_constant_if_typequant_one(expr* e, bool& modified)
{
  TypeManager* tm = e->get_type_manager();

  if (e->get_expr_kind() != const_expr_kind) 
  {
    if (!e->isNonDiscardable() &&
        TypeOps::type_cnt(tm, *(e->get_return_type())) == 1) 
    {
      modified = true;
      return new const_expr(e->get_sctx(), e->get_loc(), 1);
    }
    else if (e->get_expr_kind() == flwor_expr_kind)
    {
      flwor_expr* flwor = static_cast<flwor_expr *>(e);
      expr* ret = flwor->get_return_expr();
      expr_t newRet = get_constant_if_typequant_one(ret, modified);
      if (newRet != NULL) 
      {
        modified = true;
        flwor->set_return_expr(newRet);
      }
    }
  }

  return NULL;
}



}
/* vim:set et sw=2 ts=2: */
