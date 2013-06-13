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

#include "common/shared_types.h"
#include "types/typeops.h"

#include "functions/function.h"
#include "functions/function_impl.h"
#include "functions/func_fn_hof_functions.h"

#include "runtime/hof/fn_hof_functions.h"

#include "system/globalenv.h"


namespace zorba
{

/*******************************************************************************

********************************************************************************/
class fn_for_each_3_0 : public function
{
public:
  fn_for_each_3_0(const signature& sig, FunctionConsts::FunctionKind kind)
    :
    function(sig, kind)
  {
    theXQueryVersion = StaticContextConsts::xquery_version_3_0;
  }

  bool accessesDynCtx() const { return true; }

  PlanIter_t codegen(CompilerCB* cb,
                     static_context* sctx,
                     const QueryLoc& loc,
                     std::vector<PlanIter_t>& argv,
                     expr& ann) const
  {
    return NULL;
  }
};


/*******************************************************************************

********************************************************************************/
class fn_filter : public function
{
public:
  fn_filter(const signature& sig, FunctionConsts::FunctionKind kind)
    :
    function(sig, kind)
  {
    theXQueryVersion = StaticContextConsts::xquery_version_3_0;
  }

  bool accessesDynCtx() const { return true; }

  PlanIter_t codegen(CompilerCB* ccb,
                     static_context* sctx,
                     const QueryLoc& loc,
                     std::vector<PlanIter_t>& argv,
                     expr& ann) const
  {
    return NULL;
  }
};


/*******************************************************************************

********************************************************************************/
PlanIter_t fn_fold_left_3_0::codegen(
  CompilerCB* ccb,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnFoldLeftIterator(sctx, loc, argv, false);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t fn_fold_right_3_0::codegen(
  CompilerCB* ccb,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnFoldLeftIterator(sctx, loc, argv, true);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t fn_function_lookup_3_0::codegen(
  CompilerCB* ccb,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  ZORBA_ASSERT(false);
}


/*******************************************************************************

********************************************************************************/
PlanIter_t op_zorba_function_lookup_3_0::codegen(
  CompilerCB* ccb,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FunctionLookupIterator(sctx, loc, argv);
}


/*******************************************************************************

********************************************************************************/
void populate_context_hof_impl(static_context* sctx)
{
  {
    std::vector<xqtref_t> args;
    args.push_back(GENV_TYPESYSTEM.ITEM_TYPE_ONE);

    xqtref_t hofParamType = GENV_TYPESYSTEM.create_function_type(
                   args,
                   GENV_TYPESYSTEM.ITEM_TYPE_STAR,
                   SequenceType::QUANT_ONE);

    DECL_WITH_KIND(sctx,
                   fn_for_each_3_0,
                   (createQName(static_context::W3C_FN_NS, "", "for-each"),
                   GENV_TYPESYSTEM.ITEM_TYPE_STAR,
                   hofParamType,
                   GENV_TYPESYSTEM.ITEM_TYPE_STAR),
                   FunctionConsts::FN_FOR_EACH_2);
  }

  {
    std::vector<xqtref_t> args;
    args.push_back(GENV_TYPESYSTEM.ITEM_TYPE_ONE);

    xqtref_t hofParamType = GENV_TYPESYSTEM.create_function_type(
                   args,
                   GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE,
                   SequenceType::QUANT_ONE);

    DECL_WITH_KIND(sctx,
                   fn_filter,
                   (createQName(static_context::W3C_FN_NS, "", "filter"),
                   GENV_TYPESYSTEM.ITEM_TYPE_STAR,
                   hofParamType,
                   GENV_TYPESYSTEM.ITEM_TYPE_STAR),
                   FunctionConsts::FN_FILTER_2);
  }

  {
    std::vector<xqtref_t> args;
    args.push_back(GENV_TYPESYSTEM.ITEM_TYPE_ONE);
    args.push_back(GENV_TYPESYSTEM.ITEM_TYPE_ONE);

    xqtref_t hofParamType = GENV_TYPESYSTEM.create_function_type(
                   args,
                   GENV_TYPESYSTEM.ITEM_TYPE_STAR,
                   SequenceType::QUANT_ONE);

    DECL_WITH_KIND(sctx,
                   fn_for_each_pair_3_0,
                   (createQName(static_context::W3C_FN_NS, "", "for-each-pair"),
                   GENV_TYPESYSTEM.ITEM_TYPE_STAR,
                   GENV_TYPESYSTEM.ITEM_TYPE_STAR,
                   hofParamType,
                   GENV_TYPESYSTEM.ITEM_TYPE_STAR),
                   FunctionConsts::FN_FOR_EACH_PAIR_3);
  }

  {
    std::vector<xqtref_t> args;
    xqtref_t hofParamType;
    
    args.push_back(GENV_TYPESYSTEM.ITEM_TYPE_STAR);
    args.push_back(GENV_TYPESYSTEM.ITEM_TYPE_ONE);
    hofParamType = GENV_TYPESYSTEM.create_function_type(
                   args,
                   GENV_TYPESYSTEM.ITEM_TYPE_STAR,
                   SequenceType::QUANT_ONE);

    DECL_WITH_KIND(sctx,
                   fn_fold_left_3_0,
                   (createQName(static_context::W3C_FN_NS, "", "fold-left"),
                   GENV_TYPESYSTEM.ITEM_TYPE_STAR,
                   GENV_TYPESYSTEM.ITEM_TYPE_STAR,
                   hofParamType,
                   GENV_TYPESYSTEM.ITEM_TYPE_STAR),
                   FunctionConsts::FN_FOLD_LEFT_3);
    
    args.clear();
    args.push_back(GENV_TYPESYSTEM.ITEM_TYPE_ONE);
    args.push_back(GENV_TYPESYSTEM.ITEM_TYPE_STAR);
    hofParamType = GENV_TYPESYSTEM.create_function_type(
                   args,
                   GENV_TYPESYSTEM.ITEM_TYPE_STAR,
                   SequenceType::QUANT_ONE);

    DECL_WITH_KIND(sctx,
                   fn_fold_right_3_0,
                   (createQName(static_context::W3C_FN_NS, "", "fold-right"),
                   GENV_TYPESYSTEM.ITEM_TYPE_STAR,
                   GENV_TYPESYSTEM.ITEM_TYPE_STAR,
                   hofParamType,
                   GENV_TYPESYSTEM.ITEM_TYPE_STAR),
                   FunctionConsts::FN_FOLD_RIGHT_3);
  }

}

}

/* vim:set et sw=2 ts=2: */
