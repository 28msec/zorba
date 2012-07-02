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

#include "compiler/expression/flwor_expr.h"
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


namespace zorba
{

static expr_t wrap_in_num_promotion(expr* arg, xqtref_t oldt, xqtref_t t, RewriterContext& rCtx);

static xqtref_t specialize_numeric(fo_expr* fo, static_context* sctx, RewriterContext& rCtx);

static function* flip_value_cmp(FunctionConsts::FunctionKind kind);


#if 0
RULE_REWRITE_POST(InferUDFTypes)
{
  if (node->get_expr_kind() != fo_expr_kind)
    return NULL;

  fo_expr* fo = static_cast<fo_expr*>(node);
  user_function* udf = dynamic_cast<user_function*>(fo->get_func());

  if (udf == NULL)
    return NULL;

  if (udf->getBody() == NULL)
    return NULL;

  rCtx.theUDFCallChain.pop_back(udf);

  static_context* sctx = rCtx.getStaticContext(node);

  expr_t bodyExpr = udf->getBody();
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

  if (node->get_expr_kind() == fo_expr_kind)
  {
    fo_expr* fo = static_cast<fo_expr *>(node);

    if (fo->get_func()->getKind() == FunctionConsts::FN_BOOLEAN_1)
    {
      expr_t arg = fo->get_arg(0);
      xqtref_t arg_type = arg->get_return_type();
      if (TypeOps::is_subtype(tm, *arg_type, *rtm.BOOLEAN_TYPE_ONE, arg->get_loc()))
        return arg;
      else
        return NULL;
    }

    if (fo->get_func()->getKind() == FunctionConsts::FN_DATA_1)
    {
      expr_t arg = fo->get_arg(0);
      xqtref_t arg_type = arg->get_return_type();
      if (TypeOps::is_subtype(tm, *arg_type, *rtm.ANY_ATOMIC_TYPE_STAR, arg->get_loc()))
        return arg;
      else
        return NULL;
    }
  }

  cast_base_expr* pe;

  // Note: the if cond is true for promote_expr, treat_expr, and cast_expr
  if ((pe = dynamic_cast<cast_base_expr *>(node)) != NULL)
  {
    expr_t arg = pe->get_input();
    xqtref_t arg_type = arg->get_return_type();
    xqtref_t target_type = pe->get_target_type();

    if (arg->get_expr_kind() == fo_expr_kind)
    {
      fo_expr* fo = static_cast<fo_expr *>(arg.getp());
      const function* fn = fo->get_func();

      if (fn->isExternal())
        return NULL;
    }

    // If arg type is subtype of target type, we can eliminate treat and promote
    // (because they are noops in this case), but not cast (which will actually
    // create a new item with the target type).
    if (TypeOps::is_equal(tm, *arg_type, *target_type, arg->get_loc()) ||
        (node->get_expr_kind() != cast_expr_kind &&
         TypeOps::is_subtype(tm, *arg_type, *target_type, arg->get_loc())))
      return arg;

    xqtref_t arg_ptype = TypeOps::prime_type(tm, *arg_type);
    xqtref_t target_ptype = TypeOps::prime_type(tm, *target_type);

    // If the prime types of the arg type and the target type are equal, then
    // for a cast expr, we just need to make sure that the cardinality of the
    // arg is the correct one. This we can do by turning cast to a treat expr
    // that just chacks the cardinality.
    if (node->get_expr_kind() == cast_expr_kind &&
        TypeOps::is_equal(tm, *arg_ptype, *target_ptype, arg->get_loc()))
    {
      return rCtx.theEM->create_treat_expr(sctx,
                            node->get_loc(),
                            arg,
                            target_type,
                            err::XPTY0004,
                            false); // do not check the prime types
    }

    if (node->get_expr_kind() == treat_expr_kind)
    {
      treat_expr* te = static_cast<treat_expr *> (pe);

      if (te->get_check_prime() &&
          TypeOps::is_subtype(tm, *arg_ptype, *target_ptype, arg->get_loc()))
      {
        te->set_check_prime(false);
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


/*******************************************************************************

********************************************************************************/
RULE_REWRITE_PRE(SpecializeOperations)
{
  return NULL;
}


RULE_REWRITE_POST(SpecializeOperations)
{
  const Properties& props = *Properties::instance();

  RootTypeManager& rtm = GENV_TYPESYSTEM;
  TypeManager* tm = node->get_type_manager();

  static_context* sctx = node->get_sctx();

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
      expr_t argExpr = fo->get_arg(0);
      xqtref_t argType = argExpr->get_return_type();
      std::vector<xqtref_t> argTypes;
      argTypes.push_back(argType);

      function* replacement = fn->specialize(sctx, argTypes);
      if (replacement != NULL)
      {
        fo->set_func(replacement);

        if (TypeOps::is_subtype(tm,
                                *argType,
                                *rtm.UNTYPED_ATOMIC_TYPE_STAR,
                                argExpr->get_loc()))
        {
          expr_t promoteExpr = rCtx.theEM->create_promote_expr(argExpr->get_sctx(),
                                                argExpr->get_loc(),
                                                argExpr,
                                                rtm.DOUBLE_TYPE_STAR);

          fo->set_arg(0, promoteExpr);
        }

        return node;
      }
    }
    else if (fnKind == FunctionConsts::OP_UNARY_MINUS_1 ||
             fnKind == FunctionConsts::OP_UNARY_PLUS_1)
    {
      expr_t argExpr = fo->get_arg(0);
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
      expr_t posExpr = fo->get_arg(1);
      if (posExpr->get_expr_kind() == promote_expr_kind)
      {
        promote_expr* promoteExpr = static_cast<promote_expr*>(posExpr.getp());
        posExpr = promoteExpr->get_input();
      }

      const QueryLoc& posLoc = posExpr->get_loc();
      xqtref_t posType = posExpr->get_return_type();

      if (fo->num_args() == 3)
      {
        expr_t lenExpr = fo->get_arg(2);
        if (lenExpr->get_expr_kind() == promote_expr_kind)
        {
          promote_expr* promoteExpr = static_cast<promote_expr*>(lenExpr.getp());
          lenExpr = promoteExpr->get_input();
        }

        xqtref_t lenType = lenExpr->get_return_type();
        const QueryLoc& lenLoc = lenExpr->get_loc();

        if (TypeOps::is_subtype(tm, *posType, *rtm.INTEGER_TYPE_ONE, posLoc) &&
            TypeOps::is_subtype(tm, *lenType, *rtm.INTEGER_TYPE_ONE, lenLoc))
        {
          if (fnKind == FunctionConsts::FN_SUBSTRING_3)
            fo->set_func(GET_BUILTIN_FUNCTION(OP_SUBSTRING_INT_3));
          else
            fo->set_func(GET_BUILTIN_FUNCTION(OP_ZORBA_SUBSEQUENCE_INT_3));

          fo->set_arg(1, posExpr);
          fo->set_arg(1, lenExpr);
        }
      }
      else if (TypeOps::is_subtype(tm, *posType, *rtm.INTEGER_TYPE_ONE, posLoc))
      {
        if (fnKind == FunctionConsts::FN_SUBSTRING_2)
          fo->set_func(GET_BUILTIN_FUNCTION(OP_SUBSTRING_INT_2));
        else
          fo->set_func(GET_BUILTIN_FUNCTION(OP_ZORBA_SUBSEQUENCE_INT_2));

        fo->set_arg(1, posExpr);
      }
    }
    else if (fo->num_args() == 2)
    {
      expr* arg0 = fo->get_arg(0);
      expr* arg1 = fo->get_arg(1);

      xqtref_t t0 = arg0->get_return_type();
      xqtref_t t1 = arg1->get_return_type();

      if (TypeOps::type_max_cnt(tm, *t0) > 1 || TypeOps::type_max_cnt(tm, *t1) > 1)
        return NULL;

      if (props.specializeNum() && fn->isArithmeticFunction())
      {
        if (! TypeOps::is_numeric_or_untyped(tm, *t0) ||
            ! TypeOps::is_numeric_or_untyped(tm, *t1))
          return NULL;

        if (specialize_numeric(fo, sctx, rCtx) != NULL)
          return node;
      }
      else if (props.specializeCmp() && fn->isComparisonFunction())
      {
        if (fn->isGeneralComparisonFunction())
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
          xqtref_t string_type = rtm.STRING_TYPE_QUESTION;
          bool string_cmp = true;
          expr_t nargs[2];

          for (int i = 0; i < 2; ++i)
          {
            expr* arg = (i == 0 ? arg0 : arg1);
            xqtref_t type = (i == 0 ? t0 : t1);
            const QueryLoc& loc = arg->get_loc();

            if (TypeOps::is_subtype(tm, *type, *rtm.UNTYPED_ATOMIC_TYPE_QUESTION, loc))
            {
              nargs[i] = rCtx.theEM->create_cast_expr(arg->get_sctx(),
                                       arg->get_loc(),
                                       arg,
                                       string_type);
            }
            else if (! TypeOps::is_subtype(tm, *type, *string_type, loc))
            {
              string_cmp = false;
              break;
            }
          }

          if (string_cmp)
          {
            for (int i = 0; i < 2; i++)
            {
              if (nargs[i] != NULL)
                fo->set_arg(i, nargs[i]);
            }

            std::vector<xqtref_t> argTypes;
            argTypes.push_back(string_type);
            argTypes.push_back(string_type);
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
                expr_t tmp = fo->get_arg(0);
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
  }
  else if (node->get_expr_kind() == flwor_expr_kind ||
           node->get_expr_kind() == gflwor_expr_kind)
  {
    flwor_expr* flworExpr = reinterpret_cast<flwor_expr*>(node);

    bool modified = false;

    ulong numClauses = flworExpr->num_clauses();
    for (ulong i = 0; i < numClauses; ++i)
    {
      if (flworExpr->get_clause(i)->get_kind() == flwor_clause::order_clause)
      {
        orderby_clause* obc = reinterpret_cast<orderby_clause*>
                              (flworExpr->get_clause(i));

        ulong numColumns = obc->num_columns();
        for (ulong j = 0; j < numColumns; ++j)
        {
          expr* colExpr = obc->get_column_expr(j);
          xqtref_t colType = colExpr->get_return_type();
          const QueryLoc& colLoc = colExpr->get_loc();

          if (!TypeOps::is_equal(tm, *colType, *rtm.EMPTY_TYPE, colLoc) &&
              TypeOps::is_subtype(tm, *colType, *rtm.UNTYPED_ATOMIC_TYPE_STAR, colLoc))
          {
            expr_t castExpr = rCtx.theEM->create_cast_expr(colExpr->get_sctx(),
                                            colExpr->get_loc(),
                                            colExpr,
                                            rtm.STRING_TYPE_QUESTION);

            obc->set_column_expr(j, castExpr);
            modified = true;
          }
        }
      }
    }

    if (modified)
      return node;
  }

  return NULL;
}


static xqtref_t specialize_numeric(fo_expr* fo, static_context* sctx, RewriterContext& rCtx)
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

    expr_t newArg0 = wrap_in_num_promotion(arg0, t0, aType, rCtx);
    expr_t newArg1 = wrap_in_num_promotion(arg1, t1, aType, rCtx);

    if (newArg0 != NULL)
      fo->set_arg(0, newArg0);

    if (newArg1 != NULL)
      fo->set_arg(1, newArg1);

    return aType;
  }

  return NULL;
}


static expr_t wrap_in_num_promotion(expr* arg, xqtref_t oldt, xqtref_t t, RewriterContext& rCtx)
{
  TypeManager* tm = arg->get_type_manager();

  if (TypeOps::is_subtype(tm, *oldt, *t, arg->get_loc()))
    return NULL;

  if (arg->get_expr_kind() == promote_expr_kind && TypeOps::type_max_cnt(tm, *t) <= 1)
  {
    promote_expr* pe = static_cast<promote_expr*>(arg);
    xqtref_t peType = pe->get_target_type();
    if (TypeOps::is_equal(tm,
                          *peType,
                          *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
                          arg->get_loc()))
      arg = pe->get_input();
  }

  return rCtx.theEM->create_promote_expr(arg->get_sctx(), arg->get_loc(), arg, t);
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
