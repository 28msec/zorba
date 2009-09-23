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

#include "context/static_context.h"

#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/expression/expr.h"

#include "types/typeops.h"

using namespace std;

namespace zorba 
{

#define LOOKUP_FN( pfx, local, arity ) \
(GENV.getRootStaticContext ().lookup_fn (pfx, local, arity))


static expr_t get_constant_if_typequant_one(static_context *sctx, expr_t e);

static void replace_with_constant_if_typequant_one(static_context *sctx, expr_t expr)
{
  switch(expr->get_expr_kind()) 
  {
    case flwor_expr_kind: 
    {
      flwor_expr* flwor = static_cast<flwor_expr *>(&*expr);
      expr_t ret = flwor->get_return_expr();
      expr_t nret = get_constant_if_typequant_one(sctx, ret);
      if (nret != NULL) {
        flwor->set_return_expr(nret);
      }
      break;
    }
    default:
      break;
  }
}

static expr_t get_constant_if_typequant_one(static_context *sctx, expr_t e)
{
  if (e->get_expr_kind() != const_expr_kind) 
  {
    if (TypeOps::type_cnt(*(e->return_type(sctx))) == 1) 
    {
      return new const_expr(e->get_cur_sctx(), e->get_loc(), 1);
    }
    else
    {
      replace_with_constant_if_typequant_one(sctx, e);
    }
  }
  return NULL;
}


RULE_REWRITE_PRE(ReplaceExprWithConstantOneWhenPossible) 
{
  static_context *sctx = rCtx.getStaticContext(node);

  if (node->get_expr_kind() != fo_expr_kind)
    return NULL;

  fo_expr *fo = static_cast<fo_expr *>(&*node);
  const function *fn = fo->get_func();

  if (fn == LOOKUP_FN("fn", "count", 1)
      || fn == LOOKUP_FN("fn", "empty", 1)
      || fn == LOOKUP_FN("fn", "exists", 1)) {
    expr_t child = (*fo)[0];
    expr_t nc = get_constant_if_typequant_one(sctx, child);
    if (nc != NULL) 
    {
      (*fo)[0] = nc;
      return node;
    }
  }
  return NULL;
}

RULE_REWRITE_POST(ReplaceExprWithConstantOneWhenPossible) 
{
  return NULL;
}

}
/* vim:set ts=2 sw=2: */
