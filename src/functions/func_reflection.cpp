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


class fn_zorba_invoke_simple : public function
{
public:
  fn_zorba_invoke_simple(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INVOKE_SIMPLE_N)
  {
  }

  bool accessesDynCtx() const { return true; }

  CODEGEN_DECL();
};


class fn_zorba_invoke_updating : public function
{
public:
  fn_zorba_invoke_updating(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INVOKE_UPDATING_N)
  {
  }

  bool accessesDynCtx() const { return true; }

  short getScriptingKind() const { return UPDATING_EXPR; }

  CODEGEN_DECL();
};


class fn_zorba_invoke_sequential : public function
{
public:
  fn_zorba_invoke_sequential(const signature& sig)
    :
    function(sig, FunctionConsts::FN_ZORBA_INVOKE_SEQUENTIAL_N)
  {
  }

  bool accessesDynCtx() const { return true; }

  short getScriptingKind() const 
  {
    return (SEQUENTIAL_FUNC_EXPR | SEQUENTIAL_EXPR); 
  }

  CODEGEN_DECL();
};


PlanIter_t fn_zorba_invoke_simple::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  ZORBA_ASSERT(false);
  return NULL;
}


PlanIter_t fn_zorba_invoke_updating::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  ZORBA_ASSERT(false);
  return NULL;
}


PlanIter_t fn_zorba_invoke_sequential::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  ZORBA_ASSERT(false);
  return NULL;
}


void populate_context_reflection(static_context* sctx)
{
  DECL(sctx, fn_zorba_invoke_simple,
       (createQName(static_context::ZORBA_REFLECTION_FN_NS.c_str(), "", "invoke-simple"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        true,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, fn_zorba_invoke_updating,
       (createQName(static_context::ZORBA_REFLECTION_FN_NS.c_str(), "", "invoke-updating"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        true,
        GENV_TYPESYSTEM.EMPTY_TYPE));

  DECL(sctx, fn_zorba_invoke_sequential,
       (createQName(static_context::ZORBA_REFLECTION_FN_NS.c_str(), "", "invoke-sequential"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        true,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}

}


