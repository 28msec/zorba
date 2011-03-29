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
 
#include "functions/function.h"
#include "functions/function_impl.h"

#include "runtime/eval/eval.h"


namespace zorba{


class fn_zorba_eval_simple : public function
{
public:
  fn_zorba_eval_simple(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_EVAL_SIMPLE_1)
  {
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


class fn_zorba_eval_updating : public function
{
public:
  fn_zorba_eval_updating(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_EVAL_UPDATING_1)
  {
  }

  bool accessesDynCtx() const { return true; }

  expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  CODEGEN_DECL();
};


class fn_zorba_eval_sequential : public function
{
public:
  fn_zorba_eval_sequential(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_EVAL_SEQUENTIAL_1)
  {
  }

  bool accessesDynCtx() const { return true; }

  expr_script_kind_t getUpdateType() const { return SEQUENTIAL_EXPR; }

  CODEGEN_DECL();
};


PlanIter_t fn_zorba_eval_simple::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  ZORBA_ASSERT(false);
  return NULL;
}


PlanIter_t fn_zorba_eval_updating::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  ZORBA_ASSERT(false);
  return NULL;
}


PlanIter_t fn_zorba_eval_sequential::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  ZORBA_ASSERT(false);
  return NULL;
}


void populate_context_eval(static_context* sctx)
{
  DECL(sctx, fn_zorba_eval_simple,
       (createQName(static_context::ZORBA_REFLECTION_FN_NS.c_str(), "", "eval-simple"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, fn_zorba_eval_updating,
       (createQName(static_context::ZORBA_REFLECTION_FN_NS.c_str(), "", "eval-updating"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.EMPTY_TYPE));

  DECL(sctx, fn_zorba_eval_sequential,
       (createQName(static_context::ZORBA_REFLECTION_FN_NS.c_str(), "", "eval-sequential"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}


}


