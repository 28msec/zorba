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

#include "functions/function.h"

#include "system/globalenv.h"

#include "util/properties.h"

using namespace std;

namespace zorba {

RULE_REWRITE_PRE(InferVarTypes) 
{
  return NULL;
}


RULE_REWRITE_POST(InferVarTypes) 
{
  static_context *sctx = rCtx.getStaticContext();

  if (node->get_expr_kind () == flwor_expr_kind) 
  {
    flwor_expr *flwor = dynamic_cast<flwor_expr *> (node);

    for (uint32_t i = 0; i < flwor->forlet_count (); i++) 
    {
      flwor_expr::forletref_t clause = (*flwor) [i];
      expr_t e = clause->get_expr ();
      xqtref_t explicitType = clause->get_var ()->get_type ();
      xqtref_t domainType = e->return_type (sctx);

      if (clause->get_type () == forlet_clause::for_clause)
        domainType = TypeOps::prime_type (*domainType);

      if (explicitType == NULL || TypeOps::is_subtype (*domainType, *explicitType))
        clause->get_var ()->set_type (domainType);
    }
  }
  return NULL;
}


RULE_REWRITE_PRE(EliminateTypeEnforcingOperations)
{
  fo_expr *fo;

  if ((fo = dynamic_cast<fo_expr *>(node)) != NULL) 
  {
    function *fnboolean = LOOKUP_FN("fn", "boolean", 1);
    if (fo->get_func() == fnboolean) 
    {
      expr_t arg = (*fo)[0];
      xqtref_t arg_type = arg->return_type(rCtx.getStaticContext());
      if (TypeOps::is_subtype(*arg_type, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE))
        return arg;
      else
        return NULL;
    }

    function *fndata = LOOKUP_FN("fn", "data", 1);
    if (fo->get_func() == fndata) 
    {
      expr_t arg = (*fo)[0];
      xqtref_t arg_type = arg->return_type(rCtx.getStaticContext());
      if (TypeOps::is_subtype(*arg_type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR))
        return arg;
      else
        return NULL;
    }
  }

  cast_base_expr *pe;
  // Note: the if cond is true for promote_expr, treat_expr, and cast_expr
  if ((pe = dynamic_cast<cast_base_expr *>(node)) != NULL) {
    expr_t arg = pe->get_input();
    xqtref_t arg_type = arg->return_type(rCtx.getStaticContext());
    xqtref_t target_type = pe->get_target_type();

    // If arg type is subtype of target type, we can eliminate treat and promote
    // (because they are noops in this case), but not cast (which will actually
    // create a new item with the target type).
    if (TypeOps::is_equal(*arg_type, *target_type)
        || (node->get_expr_kind () != cast_expr_kind
            && TypeOps::is_subtype(*arg_type, *target_type)))
      return arg;
    
    xqtref_t arg_ptype = TypeOps::prime_type (*arg_type),
      target_ptype = TypeOps::prime_type (*target_type);
    if (node->get_expr_kind () == cast_expr_kind
        && TypeOps::is_equal (*arg_ptype, *target_ptype))
      return new treat_expr (node->get_loc (), pe->get_input (), target_type, XPTY0004, false);

    if (node->get_expr_kind () == treat_expr_kind) {
      treat_expr *te = dynamic_cast<treat_expr *> (pe);
      if (te->get_check_prime ()
          && TypeOps::is_subtype (*arg_ptype, *target_ptype))
      {
        te->set_check_prime (false);
        return node;
      }
    }
    return NULL;
  }

  return NULL;
}

RULE_REWRITE_POST(EliminateTypeEnforcingOperations)
{
  return NULL;
}

RULE_REWRITE_PRE(SpecializeOperations)
{
  return NULL;
}

RULE_REWRITE_POST(SpecializeOperations)
{
  const Properties &props = *Properties::instance ();
  if (node->get_expr_kind() == fo_expr_kind) {
    fo_expr *fo = static_cast<fo_expr *>(node);
    const function *fn = fo->get_func();
    if (! fn->specializable ()) return NULL;
    if (fo->size() == 2) {
      xqtref_t t0 = (*fo)[0]->return_type(rCtx.getStaticContext());
      xqtref_t t1 = (*fo)[1]->return_type(rCtx.getStaticContext());
      std::vector<xqtref_t> argTypes;

      if (props.specializeNum () && fn->isArithmeticFunction()) {
        if (! TypeOps::is_numeric (*t0) || ! TypeOps::is_numeric (*t0))
          return NULL;
        xqtref_t aType = TypeOps::arithmetic_type_static(*t0, *t1);
        
        if (aType == NULL || !TypeOps::is_numeric(*aType)) {
          return NULL;
        }
        
        argTypes.push_back(aType);
        argTypes.push_back(aType);
        
        const function *replacement = fn->specialize(rCtx.getStaticContext(), argTypes);
        if (replacement != NULL) {
          fo->set_func(replacement);
          bool a0Promote = !TypeOps::is_subtype(*t0, *aType);
          bool a1Promote = !TypeOps::is_subtype(*t1, *aType);
          
          if (a0Promote) {
            (*fo)[0] = new promote_expr(fo->get_loc(), (*fo)[0], aType);
          }
          if (a1Promote) {
            (*fo)[1] = new promote_expr(fo->get_loc(), (*fo)[1], aType);
          }
          return node;
        }
      } else if (props.specializeCmp () && fn->isComparisonFunction ()) {
        argTypes.push_back(t0);
        argTypes.push_back(t1);
        const function *replacement = fn->specialize(rCtx.getStaticContext(), argTypes);
        if (replacement != NULL) {
          fo->set_func(replacement);
          return node;
        }
      }
    }
  }
  return NULL;
}

}
/* vim:set ts=2 sw=2: */
