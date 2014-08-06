/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************



#include "stdafx.h"
#include "runtime/dctx/dctx.h"
#include "functions/func_dctx.h"


namespace zorba{



PlanIter_t fn_zorba_dctx_snapshot_id::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new DctxSnapshotIdIterator(sctx, loc, argv);
}

void populate_context_dctx(static_context* sctx)
{


      {
    DECL_WITH_KIND(sctx, fn_zorba_dctx_snapshot_id,
        (createQName("http://zorba.io/modules/dctx","","snapshot-id"), 
        GENV_TYPESYSTEM.UNSIGNED_LONG_TYPE_ONE),
        FunctionConsts::FN_ZORBA_DCTX_SNAPSHOT_ID_0);

  }

}


}



