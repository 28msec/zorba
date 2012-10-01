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
#include "diagnostics/assert.h"
#include "runtime/base/plan_iterator.h"


namespace zorba{


class fn_zorba_invoke : public function
{
public:
  fn_zorba_invoke(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INVOKE_N)
  {
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


class fn_zorba_invoke_n : public function
{
public:
  fn_zorba_invoke_n(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INVOKE_N_N)
  {
  }

  bool accessesDynCtx() const { return true; }

  bool isDeterministic() const { return false; }

  CODEGEN_DECL();
};


class fn_zorba_invoke_u : public function
{
public:
  fn_zorba_invoke_u(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INVOKE_U_N)
  {
  }

  bool accessesDynCtx() const { return true; }

  unsigned short getScriptingKind() const { return UPDATING_EXPR; }

  CODEGEN_DECL();
};


class fn_zorba_invoke_s : public function
{
public:
  fn_zorba_invoke_s(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INVOKE_S_N)
  {
  }

  bool accessesDynCtx() const { return true; }

  unsigned short getScriptingKind() const { return SEQUENTIAL_FUNC_EXPR; }

  CODEGEN_DECL();
};


PlanIter_t fn_zorba_invoke::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  ZORBA_ASSERT(false);
  return NULL;
}


PlanIter_t fn_zorba_invoke_n::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  ZORBA_ASSERT(false);
  return NULL;
}


PlanIter_t fn_zorba_invoke_u::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  ZORBA_ASSERT(false);
  return NULL;
}


PlanIter_t fn_zorba_invoke_s::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  ZORBA_ASSERT(false);
  return NULL;
}


void populate_context_reflection(static_context* sctx)
{
  DECL(sctx, fn_zorba_invoke,
       (createQName(static_context::ZORBA_REFLECTION_FN_NS, "", "invoke"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        true,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, fn_zorba_invoke_n,
       (createQName(static_context::ZORBA_REFLECTION_FN_NS, "", "invoke-n"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        true,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, fn_zorba_invoke_u,
       (createQName(static_context::ZORBA_REFLECTION_FN_NS, "", "invoke-u"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        true,
        GENV_TYPESYSTEM.EMPTY_TYPE));

  DECL(sctx, fn_zorba_invoke_s,
       (createQName(static_context::ZORBA_REFLECTION_FN_NS, "", "invoke-s"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        true,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}

}


/* vim:set et sw=2 ts=2: */
