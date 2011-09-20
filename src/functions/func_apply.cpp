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

#include "functions/function_impl.h"

#include "system/globalenv.h"

#include "diagnostics/assert.h"

namespace zorba
{


/*******************************************************************************

********************************************************************************/
class xqsx_apply : public function 
{
public:
  xqsx_apply(const signature& sig)
    :
    function(sig, FunctionConsts::FN_APPLY_1)
  {
  }

  CODEGEN_DECL();
};


PlanIter_t xqsx_apply::codegen(
    CompilerCB* /*cb*/,
    static_context* aSctx,
    const QueryLoc& aLoc,
    std::vector<PlanIter_t>& aArgs,
    AnnotationHolder& aAnn) const
{
  ZORBA_ASSERT(false);
}


void populate_context_apply(static_context* sctx)
{
  const char* ns = static_context::ZORBA_SCRIPTING_FN_NS.c_str();

  DECL(sctx, xqsx_apply,
       (createQName(ns, "", "apply"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}


}
/* vim:set et sw=2 ts=2: */
