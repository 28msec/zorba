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

#include "functions/func_misc.h"
#include "functions/misc_impl.h"

#include "context/static_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/misc/misc.h"

namespace zorba 
{

PlanIter_t fn_trace::codegen(
    CompilerCB* cb,
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder &ann) const
{
  // tracing can be disabled  using declare option exq:trace "disable";
  xqp_string lOption;
  bool lOptionFound = sctx->lookup_option("http://www.zorba-xquery.org/options",
                                          "trace",
                                          lOption);

  if (!lOptionFound || (lOptionFound && lOption != "disable"))
  {
    return new TraceIterator ( sctx, loc, argv );
  }
  else
  {
    return argv[0];
  }
}

fn_error::fn_error(const signature& sig) : function (sig) {}

} // namespace zorba