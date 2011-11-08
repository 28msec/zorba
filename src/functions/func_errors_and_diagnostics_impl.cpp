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

#include "runtime/errors_and_diagnostics/errors_and_diagnostics.h"

#include "compiler/api/compilercb.h"
#include "compiler/expression/expr_base.h"
#include "zorbamisc/ns_consts.h"

#include "functions/func_errors_and_diagnostics.h"

#include "context/static_context.h"

namespace zorba
{

/*******************************************************************************

********************************************************************************/
BoolAnnotationValue fn_trace::ignoresSortedNodes(
    expr* fo,
    csize input) const 
{
  return fo->getIgnoresSortedNodes();
}


BoolAnnotationValue fn_trace::ignoresDuplicateNodes(
    expr* fo, 
    csize input) const 
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
  // tracing can be disabled using declare option op:disable-feature "trace";
  if ( sctx->is_feature_set( feature::trace ) )
  {
    return new TraceIterator( sctx, loc, argv );
  }
  else
  {
    return argv[0];
  }
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
