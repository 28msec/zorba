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

#include "types/root_typemanager.h"
#include "types/typeops.h"

#include "compiler/expression/expr_iter.h"
#include "compiler/expression/expr.h"

#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/rules/type_rules.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/rewriter/framework/rule_driver.h"

#include "context/static_context.h"

#include "functions/function.h"
#include "functions/library.h"
#include "functions/udf.h"

#include "system/properties.h"

#include "diagnostics/assert.h"

#include "store/api/store.h"
#include "store/api/item_factory.h"

namespace zorba
{

static expr* wrap_in_num_promotion(
    function* fn,
    expr* arg,
    const xqtref_t& oldt,
    const xqtref_t& t,
    RewriterContext& rCtx);

static xqtref_t specialize_numeric(
    fo_expr* fo,
    static_context* sctx,
    RewriterContext& rCtx);

static function* flip_value_cmp(FunctionConsts::FunctionKind kind);


#if 0
RULE_REWRITE_POST(InferUDFTypes)
{
  if (node->get_expr_kind() != fo_expr_kind)
    return NULL;

  fo_expr* fo = static_cast<fo_expr*>(node);
  user_function* udf = static_cast<user_function*>(fo->get_func());

  if (udf == NULL)
    return NULL;

  if (udf->getBody() == NULL)
    return NULL;

  rCtx.theUDFCallChain.pop_back(udf);

  static_context* sctx = rCtx.getStaticContext(node);

  expr* bodyExpr = udf->getBody();
  xqtref_t bodyType = bodyExpr->get_return_type();
  xqtref_t declaredType = udf->getSignature().return_type();

  if (!TypeOps::is_equal(*bodyType, *declaredType) &&
      TypeOps::is_subtype(tm, *bodyType, *declaredType, bodyExpr->get_loc()))
  {
    udf->getSignature().return_type() = bodyType;
    return node;
  }

  return NULL;
}
#endif

/*******************************************************************************

********************************************************************************/
RULE_REWRITE_PRE(EliminateTypeEnforcingOperations)
{
  static_context* sctx = node->get_sctx();
  TypeManager* tm = sctx->get_typemanager();
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  switch (node->get_expr_kind())
  {
  case fo_expr_kind:
  {
    fo_expr* fo = static_cast<fo_expr *>(node);

    if (fo->get_func()->getKind() == FunctionConsts::FN_BOOLEAN_1)
    {
      expr* arg = fo->get_arg(0);
      xqtref_t arg_type = arg->get_return_type();
      if (TypeOps::is_subtype(tm, *arg_type, *rtm.BOOLEAN_TYPE_ONE, arg->get_loc()))
        return arg;
      else
        return NULL;
    }

    if (fo->get_func()->getKind() == FunctionConsts::FN_DATA_1)
    {
      expr* arg = fo->get_arg(0);
      xqtref_t arg_type = arg->get_return_type();
      if (TypeOps::is_subtype(tm, *arg_type, *rtm.ANY_ATOMIC_TYPE_STAR, arg->get_loc()))
        return arg;
      else
        return NULL;
    }

#ifdef ZORBA_WITH_JSON
    if (fo->get_func()->getKind() == FunctionConsts::OP_ZORBA_JSON_BOX_1)
    {
      expr* arg = fo->get_arg(0);
      xqtref_t arg_type = arg->get_return_type();

      if (arg_type->get_quantifier() == SequenceType::QUANT_ONE)
        return arg;

      if (arg_type->max_card() == 0)
      {
        store::Item_t null;
        GENV_STORE.getItemFactory()->createJSONNull(null);

        return rCtx.theEM->create_const_expr(sctx, fo->get_udf(), fo->get_loc(), null);
      }

      return NULL;
    }
#endif

    break;
  }
  case cast_expr_kind:
  {
    cast_expr* e = static_cast<cast_expr*>(node);

    expr* arg = e->get_input();
    xqtref_t arg_type = arg->get_return_type();
    xqtref_t target_type = e->get_target_type();

    if (TypeOps::is_equal(tm, *arg_type, *target_type, arg->get_loc()))
      return arg;

    if (target_type->isAtomicAny())
    {
      xqtref_t arg_ptype = TypeOps::prime_type(tm, *arg_type);
      xqtref_t target_ptype = TypeOps::prime_type(tm, *target_type);

      // If the prime types of the arg type and the target type are equal, then
      // for a cast expr, we just need to make sure that the cardinality of the
      // arg is the correct one. This we can do by turning cast to a treat expr
      // that just checks the cardinality.
      if (TypeOps::is_equal(tm, *arg_ptype, *target_ptype, arg->get_loc()))
      {
        return rCtx.theEM->create_treat_expr(sctx,
                                             node->get_udf(),
                                             node->get_loc(),
                                             arg,
                                             target_type,
                                             TREAT_TYPE_MATCH,
                                             false); // do not check the prime types
      }
    }

    break;
  }
  case promote_expr_kind:
  case treat_expr_kind:
  {
    cast_base_expr* pe = static_cast<cast_base_expr*>(node);

    expr* arg = pe->get_input();
    xqtref_t arg_type = arg->get_return_type();
    xqtref_t target_type = pe->get_target_type();

    if (arg->get_expr_kind() == fo_expr_kind)
    {
      fo_expr* fo = static_cast<fo_expr *>(arg);
      const function* fn = fo->get_func();

      if (fn->isExternal())
        return NULL;
    }

    // If arg type is subtype of target type, we can eliminate treat and promote
    // (because they are noops in this case).
    if (TypeOps::is_subtype(tm, *arg_type, *target_type, arg->get_loc()))
      return arg;

    if (node->get_expr_kind() == treat_expr_kind)
    {
      treat_expr* te = static_cast<treat_expr *> (pe);

      if (te->get_check_prime())
      {
        xqtref_t arg_ptype = TypeOps::prime_type(tm, *arg_type);
        xqtref_t target_ptype = TypeOps::prime_type(tm, *target_type);

        if (TypeOps::is_subtype(tm, *arg_ptype, *target_ptype, arg->get_loc()))
        {
          te->set_check_prime(false);
          return node;
        }
      }
    }

    return NULL;
  }
  default:
    break;
  }

  return NULL;
}


RULE_REWRITE_POST(EliminateTypeEnforcingOperations)
{
  return NULL;
}


/*******************************************************************************

********************************************************************************/
RULE_REWRITE_PRE(SpecializeOperations)
{
  return NULL;
}


RULE_REWRITE_POST(SpecializeOperations)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;
  TypeManager* tm = node->get_type_manager();
  static_context* sctx = node->get_sctx();
  user_function* udf = node->get_udf();

  if (node->get_expr_kind() == fo_expr_kind)
  {
    fo_expr* fo = static_cast<fo_expr *>(node);
    const function* fn = fo->get_func();
    FunctionConsts::FunctionKind fnKind = fn->getKind();

    if (! fn->specializable())
      return NULL;

    if (fnKind == FunctionConsts::FN_SUM_1 ||
        fnKind == FunctionConsts::FN_SUM_2)
    {
      expr* argExpr = fo->get_arg(0);
      const QueryLoc& argLoc = argExpr->get_loc();
      xqtref_t argType = argExpr->get_return_type();
   
      std::vector<xqtref_t> argTypes;
      argTypes.push_back(argType);

      function* replacement = fn->specialize(sctx, argTypes);
      if (replacement != NULL)
      {
        fo->set_func(replacement);

        if (TypeOps::is_subtype(tm, *argType, *rtm.UNTYPED_ATOMIC_TYPE_STAR, argLoc))
        {
          expr* promoteExpr = rCtx.theEM->
          create_promote_expr(sctx,
                              udf,
                              argExpr->get_loc(),
                              argExpr,
                              rtm.DOUBLE_TYPE_STAR,
                              PROMOTE_FUNC_PARAM,
                              replacement->getName());

          fo->set_arg(0, promoteExpr);
        }

        return node;
      }
    }
    else if (fnKind == FunctionConsts::OP_UNARY_MINUS_1 ||
             fnKind == FunctionConsts::OP_UNARY_PLUS_1)
    {
      expr* argExpr = fo->get_arg(0);
      xqtref_t argType = argExpr->get_return_type();
      std::vector<xqtref_t> argTypes;
      argTypes.push_back(argType);

      function* replacement = fn->specialize(sctx, argTypes);
      if (replacement != NULL)
      {
        fo->set_func(replacement);
        return node;
      }
    }
    else if (fnKind == FunctionConsts::FN_SUBSEQUENCE_2 ||
             fnKind == FunctionConsts::FN_SUBSEQUENCE_3 ||
             fnKind == FunctionConsts::FN_SUBSTRING_2 ||
             fnKind == FunctionConsts::FN_SUBSTRING_3)
    {
      expr* posExpr = fo->get_arg(1);
      if (posExpr->get_expr_kind() == promote_expr_kind)
      {
        promote_expr* promoteExpr = static_cast<promote_expr*>(posExpr);
        posExpr = promoteExpr->get_input();
      }

      const QueryLoc& posLoc = posExpr->get_loc();
      xqtref_t posType = posExpr->get_return_type();

      if (fo->num_args() == 3)
      {
        expr* lenExpr = fo->get_arg(2);
        if (lenExpr->get_expr_kind() == promote_expr_kind)
        {
          promote_expr* promoteExpr = static_cast<promote_expr*>(lenExpr);
          lenExpr = promoteExpr->get_input();
        }

        xqtref_t lenType = lenExpr->get_return_type();
        const QueryLoc& lenLoc = lenExpr->get_loc();

        if (TypeOps::is_subtype(tm, *posType, *rtm.INTEGER_TYPE_ONE, posLoc) &&
            TypeOps::is_subtype(tm, *lenType, *rtm.INTEGER_TYPE_ONE, lenLoc))
        {
          if (fnKind == FunctionConsts::FN_SUBSTRING_3)
            fo->set_func(BUILTIN_FUNC(OP_SUBSTRING_INT_3));
          else
            fo->set_func(BUILTIN_FUNC(OP_ZORBA_SUBSEQUENCE_INT_3));

          fo->set_arg(1, posExpr);
          fo->set_arg(1, lenExpr);
        }
      }
      else if (TypeOps::is_subtype(tm, *posType, *rtm.INTEGER_TYPE_ONE, posLoc))
      {
        if (fnKind == FunctionConsts::FN_SUBSTRING_2)
          fo->set_func(BUILTIN_FUNC(OP_SUBSTRING_INT_2));
        else
          fo->set_func(BUILTIN_FUNC(OP_ZORBA_SUBSEQUENCE_INT_2));

        fo->set_arg(1, posExpr);
      }
    }
    else if (fo->num_args() == 2)
    {
      expr* arg0 = fo->get_arg(0);
      expr* arg1 = fo->get_arg(1);

      xqtref_t t0 = arg0->get_return_type();
      xqtref_t t1 = arg1->get_return_type();

      if (t0->max_card() > 1 || t1->max_card() > 1)
        return NULL;

      if (fn->isArithmeticFunction())
      {
        if (! TypeOps::is_numeric_or_untyped(tm, *t0) ||
            ! TypeOps::is_numeric_or_untyped(tm, *t1))
          return NULL;

        if (specialize_numeric(fo, sctx, rCtx) != NULL)
          return node;
      }
      else if (fn->isGeneralComparisonFunction())
      {
        std::vector<xqtref_t> argTypes;
        argTypes.push_back(t0);
        argTypes.push_back(t1);
        function* replacement = fn->specialize(sctx, argTypes);
        if (replacement != NULL)
        {
          fo->set_func(replacement);
          return node;
        }
      }
      else if (fn->isValueComparisonFunction())
      {
        xqtref_t stringType = rtm.STRING_TYPE_QUESTION;
        xqtref_t untypedType = rtm.UNTYPED_ATOMIC_TYPE_QUESTION;

        const QueryLoc& loc0 = arg0->get_loc();
        const QueryLoc& loc1 = arg1->get_loc();

        bool atomicORstring0 = (TypeOps::is_subtype(tm, *t0, *untypedType, loc0) ||
                                TypeOps::is_subtype(tm, *t0, *stringType, loc0));

        bool atomicORstring1 = (TypeOps::is_subtype(tm, *t1, *untypedType, loc1) ||
                                TypeOps::is_subtype(tm, *t1, *stringType, loc1));

        if (atomicORstring0 && atomicORstring1)
        {
          std::vector<xqtref_t> argTypes;
          argTypes.push_back(stringType);
          argTypes.push_back(stringType);
          
          function* replacement = fn->specialize(sctx, argTypes);
          if (replacement != NULL)
          {
            fo->set_func(replacement);
            return node;
          }
        }
        else if (TypeOps::is_numeric(tm, *t0) && TypeOps::is_numeric(tm, *t1))
        {
          xqtref_t aType = specialize_numeric(fo, sctx, rCtx);
          if (aType != NULL)
          {
            if (TypeOps::is_equal(tm,
                                  *TypeOps::prime_type(tm, *aType),
                                  *rtm.DECIMAL_TYPE_ONE,
                                  fo->get_loc()) &&
                TypeOps::is_subtype(tm, *t0, *rtm.INTEGER_TYPE_ONE, fo->get_loc()))
            {
              expr* tmp = fo->get_arg(0);
              fo->set_arg(0, fo->get_arg(1));
              fo->set_arg(1, tmp);
              fo->set_func(flip_value_cmp(fo->get_func()->getKind()));
            }
            
            return node;
          }
        }
      }
    }
  }

  return NULL;
}


static xqtref_t specialize_numeric(
    fo_expr* fo,
    static_context* sctx,
    RewriterContext& rCtx)
{
  TypeManager* tm = fo->get_type_manager();

  const function* fn = fo->get_func();
  expr* arg0 = fo->get_arg(0);
  expr* arg1 = fo->get_arg(1);
  xqtref_t t0 = arg0->get_return_type();
  xqtref_t t1 = arg1->get_return_type();

  xqtref_t aType =
  TypeOps::arithmetic_type(tm,
                           *t0,
                           *t1,
                           fn->arithmeticKind() == ArithmeticConsts::DIVISION);

  if (!TypeOps::is_numeric(tm, *aType))
  {
    return NULL;
  }

  std::vector<xqtref_t> argTypes;
  argTypes.push_back(aType);
  argTypes.push_back(aType);

  function* replacement = fn->specialize(sctx, argTypes);
  if (replacement != NULL)
  {
    fo->set_func(replacement);

    expr* newArg0 = wrap_in_num_promotion(replacement, arg0, t0, aType, rCtx);
    expr* newArg1 = wrap_in_num_promotion(replacement, arg1, t1, aType, rCtx);

    if (newArg0 != NULL)
      fo->set_arg(0, newArg0);

    if (newArg1 != NULL)
      fo->set_arg(1, newArg1);

    return aType;
  }

  return NULL;
}


static expr* wrap_in_num_promotion(
    function* fn,
    expr* arg,
    const xqtref_t& oldt,
    const xqtref_t& t,
    RewriterContext& rCtx)
{
  TypeManager* tm = arg->get_type_manager();

  if (TypeOps::is_subtype(tm, *oldt, *t, arg->get_loc()))
    return NULL;

  if (arg->get_expr_kind() == promote_expr_kind && t->max_card() <= 1)
  {
    promote_expr* pe = static_cast<promote_expr*>(arg);
    xqtref_t peType = pe->get_target_type();
    if (TypeOps::is_equal(tm,
                          *peType,
                          *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
                          arg->get_loc()))
      arg = pe->get_input();
  }

  return rCtx.theEM->create_promote_expr(arg->get_sctx(),
                                         arg->get_udf(),
                                         arg->get_loc(),
                                         arg,
                                         t,
                                         PROMOTE_FUNC_PARAM,
                                         fn->getName());
}


static function* flip_value_cmp(FunctionConsts::FunctionKind kind)
{
  FunctionConsts::FunctionKind newKind;

  switch (kind)
  {
  case FunctionConsts::OP_VALUE_EQUAL_DOUBLE_2:
  case FunctionConsts::OP_VALUE_EQUAL_FLOAT_2:
  case FunctionConsts::OP_VALUE_EQUAL_DECIMAL_2:
  case FunctionConsts::OP_VALUE_EQUAL_INTEGER_2:
    newKind = kind;
    break;

  case FunctionConsts::OP_VALUE_NOT_EQUAL_DOUBLE_2:
  case FunctionConsts::OP_VALUE_NOT_EQUAL_FLOAT_2:
  case FunctionConsts::OP_VALUE_NOT_EQUAL_DECIMAL_2:
  case FunctionConsts::OP_VALUE_NOT_EQUAL_INTEGER_2:
    newKind = kind;
    break;

  case FunctionConsts::OP_VALUE_LESS_EQUAL_DOUBLE_2:
    newKind = FunctionConsts::OP_VALUE_GREATER_EQUAL_DOUBLE_2;
    break;
  case FunctionConsts::OP_VALUE_LESS_EQUAL_FLOAT_2:
    newKind = FunctionConsts::OP_VALUE_GREATER_EQUAL_FLOAT_2;
    break;
  case FunctionConsts::OP_VALUE_LESS_EQUAL_DECIMAL_2:
    newKind = FunctionConsts::OP_VALUE_GREATER_EQUAL_DECIMAL_2;
    break;
  case FunctionConsts::OP_VALUE_LESS_EQUAL_INTEGER_2:
    newKind = FunctionConsts::OP_VALUE_GREATER_EQUAL_INTEGER_2;
    break;

  case FunctionConsts::OP_VALUE_LESS_DOUBLE_2:
    newKind = FunctionConsts::OP_VALUE_GREATER_DOUBLE_2;
    break;
  case FunctionConsts::OP_VALUE_LESS_FLOAT_2:
    newKind = FunctionConsts::OP_VALUE_GREATER_FLOAT_2;
    break;
  case FunctionConsts::OP_VALUE_LESS_DECIMAL_2:
    newKind = FunctionConsts::OP_VALUE_GREATER_DECIMAL_2;
    break;
  case FunctionConsts::OP_VALUE_LESS_INTEGER_2:
    newKind = FunctionConsts::OP_VALUE_GREATER_INTEGER_2;
    break;

  case FunctionConsts::OP_VALUE_GREATER_EQUAL_DOUBLE_2:
    newKind = FunctionConsts::OP_VALUE_LESS_EQUAL_DOUBLE_2;
    break;
  case FunctionConsts::OP_VALUE_GREATER_EQUAL_FLOAT_2:
    newKind = FunctionConsts::OP_VALUE_LESS_EQUAL_FLOAT_2;
    break;
  case FunctionConsts::OP_VALUE_GREATER_EQUAL_DECIMAL_2:
    newKind = FunctionConsts::OP_VALUE_LESS_EQUAL_DECIMAL_2;
    break;
  case FunctionConsts::OP_VALUE_GREATER_EQUAL_INTEGER_2:
    newKind = FunctionConsts::OP_VALUE_LESS_EQUAL_INTEGER_2;
    break;

  case FunctionConsts::OP_VALUE_GREATER_DOUBLE_2:
    newKind = FunctionConsts::OP_VALUE_LESS_DOUBLE_2;
    break;
  case FunctionConsts::OP_VALUE_GREATER_FLOAT_2:
    newKind = FunctionConsts::OP_VALUE_LESS_FLOAT_2;
    break;
  case FunctionConsts::OP_VALUE_GREATER_DECIMAL_2:
    newKind = FunctionConsts::OP_VALUE_LESS_DECIMAL_2;
    break;
  case FunctionConsts::OP_VALUE_GREATER_INTEGER_2:
    newKind = FunctionConsts::OP_VALUE_LESS_INTEGER_2;
    break;

  default:
    ZORBA_ASSERT(false);
  }

  return BuiltinFunctionLibrary::getFunction(newKind);
}


}
/* vim:set et sw=2 ts=2: */
/* vim:set et sw=2 ts=2: */
