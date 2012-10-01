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

#include "functions/function.h"
#include "functions/function_impl.h"

#include "runtime/eval/eval.h"


namespace zorba{


class fn_zorba_eval : public function
{
public:
  fn_zorba_eval(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_EVAL_1)
  {
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


class fn_zorba_eval_n : public function
{
public:
  fn_zorba_eval_n(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_EVAL_N_1)
  {
  }

  bool accessesDynCtx() const { return true; }

  bool isDeterministic() const { return false; }

  CODEGEN_DECL();
};


class fn_zorba_eval_u : public function
{
public:
  fn_zorba_eval_u(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_EVAL_U_1)
  {
  }

  bool accessesDynCtx() const { return true; }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  bool isDeterministic() const { return false; }

  CODEGEN_DECL();
};


class fn_zorba_eval_s : public function
{
public:
  fn_zorba_eval_s(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_EVAL_S_1)
  {
  }

  bool accessesDynCtx() const { return true; }

  unsigned short getScriptingKind() const { return SEQUENTIAL_FUNC_EXPR; }

  CODEGEN_DECL();
};

PlanIter_t fn_zorba_eval::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  ZORBA_ASSERT(false);
  return NULL;
}

PlanIter_t fn_zorba_eval_n::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  ZORBA_ASSERT(false);
  return NULL;
}


PlanIter_t fn_zorba_eval_u::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  ZORBA_ASSERT(false);
  return NULL;
}


PlanIter_t fn_zorba_eval_s::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  ZORBA_ASSERT(false);
  return NULL;
}


void populate_context_eval(static_context* sctx)
{
  DECL(sctx, fn_zorba_eval,
       (createQName(static_context::ZORBA_REFLECTION_FN_NS, "", "eval"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, fn_zorba_eval_n,
       (createQName(static_context::ZORBA_REFLECTION_FN_NS, "", "eval-n"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, fn_zorba_eval_u,
       (createQName(static_context::ZORBA_REFLECTION_FN_NS, "", "eval-u"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.EMPTY_TYPE));

  DECL(sctx, fn_zorba_eval_s,
       (createQName(static_context::ZORBA_REFLECTION_FN_NS, "", "eval-s"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}


}

/* vim:set et sw=2 ts=2: */
