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
#include "runtime/errors_and_diagnostics/errors_and_diagnostics.h"

#include "compiler/api/compilercb.h"
#include "compiler/expression/expr_base.h"

#include "functions/func_errors_and_diagnostics.h"

#include "context/static_context.h"

namespace zorba
{

/*******************************************************************************

********************************************************************************/
fn_error::fn_error(const signature& sig) 
  :
  function(sig, FunctionConsts::FN_UNKNOWN)
{
  switch (sig.paramCount())
  {
  case 0:
    theKind = FunctionConsts::FN_ERROR_0;
    break;

  case 1:
    theKind = FunctionConsts::FN_ERROR_1;
    break;

  case 2:
    theKind = FunctionConsts::FN_ERROR_2;
    break;

  case 3:
    theKind = FunctionConsts::FN_ERROR_3;
    break;

  default:
    ZORBA_ASSERT(false);
  }
}

/*******************************************************************************

********************************************************************************/
BoolAnnotationValue fn_trace::ignoresSortedNodes(
    expr* fo,
    ulong input) const 
{
  return fo->getIgnoresSortedNodes();
}


BoolAnnotationValue fn_trace::ignoresDuplicateNodes(
    expr* fo, 
    ulong input) const 
{
  return fo->getIgnoresDuplicateNodes();
}


PlanIter_t fn_trace::codegen(
    CompilerCB* cb,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder &ann) const
{
  // tracing can be disabled  using declare option exq:trace "disable";
  zstring lOption;
  store::Item_t optionName;
  GENV_ITEMFACTORY->createQName(optionName,
                                "http://www.zorba-xquery.org/options",
                                "",
                                "trace");
  bool lOptionFound = sctx->lookup_option(optionName, lOption);

  if (!lOptionFound || (lOptionFound && lOption != "disable"))
  {
    return new TraceIterator( sctx, loc, argv );
  }
  else
  {
    return argv[0];
  }
}

} // namespace zorba
