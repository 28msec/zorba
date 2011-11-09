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
#include "functions/function.h"
#include "functions/function_impl.h"

#include "functions/func_strings.h"
#include "functions/func_strings_impl.h"

#include "runtime/strings/strings_impl.h"

#include "compiler/expression/expr_consts.h"


namespace zorba
{

/*******************************************************************************

********************************************************************************/
BoolAnnotationValue fn_concat::ignoresSortedNodes(
    expr* fo,
    ulong input) const
{
  return ANNOTATION_TRUE;
}


BoolAnnotationValue fn_concat::ignoresDuplicateNodes(
    expr* fo,
    ulong input) const
{
  return ANNOTATION_TRUE;
}

function* fn_substring::specialize( static_context* sctx,
    const std::vector<xqtref_t>& argTypes) const
{
  return NULL;
}


function* fn_substring_intopt::specialize(static_context *sctx,
    const std::vector<xqtref_t>& argTypes) const
{
  return NULL;
}

PlanIter_t fn_substring_intopt::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new SubstringIntOptIterator(sctx, loc, argv);
}

}

/* vim:set et sw=2 ts=2: */
