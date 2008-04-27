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
#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "context/static_context.h"
#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "system/globalenv.h"

using namespace std;

namespace zorba {

RULE_REWRITE_PRE(InferVarTypes) {
  return NULL;
}

RULE_REWRITE_POST(InferVarTypes) {
  static_context *sctx = rCtx.getStaticContext();
  if (node->get_expr_kind () == flwor_expr_kind) {
    flwor_expr *flwor = dynamic_cast<flwor_expr *> (node);
    for (uint32_t i = 0; i < flwor->forlet_count (); i++) {
      flwor_expr::forletref_t clause = (*flwor) [i];
      varref_t posvar = clause->get_pos_var ();
      if (posvar != NULL)
        posvar->set_type (GENV_TYPESYSTEM.POSITIVE_INTEGER_TYPE_ONE);
      expr_t e = clause->get_expr ();
      xqtref_t vartype = clause->get_var ()->get_type (),
        ctype = e->return_type (sctx);
      if (clause->get_type () == forlet_clause::for_clause)
        ctype = TypeOps::prime_type (*ctype);
      if (vartype == NULL || TypeOps::is_subtype (*ctype, *vartype))
        clause->get_var ()->set_type (ctype);
    }
  }
  return NULL;
}

RULE_REWRITE_PRE(EliminateTypeEnforcingOperations)
{
  fo_expr *fo;

  if ((fo = dynamic_cast<fo_expr *>(node)) != NULL) {
    function *fnboolean = LOOKUP_FN("fn", "boolean", 1);
    if (fo->get_func() == fnboolean) {
      expr_t arg = (*fo)[0];
      xqtref_t arg_type = arg->return_type(rCtx.getStaticContext());
      if (TypeOps::is_subtype(*arg_type, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE))
        return arg;
      else return NULL;
    }
    function *fndata = LOOKUP_FN("fn", "data", 1);
    if (fo->get_func() == fndata) {
      expr_t arg = (*fo)[0];
      xqtref_t arg_type = arg->return_type(rCtx.getStaticContext());
      if (TypeOps::is_subtype(*arg_type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR))
        return arg;
      else return NULL;
    }
  }
  cast_base_expr *pe;
  if ((pe = dynamic_cast<cast_base_expr *>(node)) != NULL) {
    expr_t arg = pe->get_input();
    xqtref_t arg_type = arg->return_type(rCtx.getStaticContext()),
      target_type = pe->get_target_type();
    if (TypeOps::is_subtype(*arg_type, *target_type))
      return arg;
    if (node->get_expr_kind () == treat_expr_kind) {
      treat_expr *te = dynamic_cast<treat_expr *> (pe);
      if (te->get_check_prime ()
          && TypeOps::is_subtype (*TypeOps::prime_type (*arg_type),
                                  *TypeOps::prime_type (*target_type)))
        te->set_check_prime (false);
    }
    return NULL;
  }

  return NULL;
}

RULE_REWRITE_POST(EliminateTypeEnforcingOperations)
{
  return NULL;
}

}
/* vim:set ts=2 sw=2: */
