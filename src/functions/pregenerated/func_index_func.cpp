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
#include "runtime/indexing/index_func.h"
#include "functions/func_index_func.h"


namespace zorba{



PlanIter_t zorba_store_indexes_static_dml_keys::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new IndexKeysIterator(sctx, loc, argv);
}

void populate_context_index_func(static_context* sctx)
{


      {
    DECL_WITH_KIND(sctx, zorba_store_indexes_static_dml_keys,
        (createQName("http://www.zorba-xquery.com/modules/store/static/indexes/dml","","keys"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR),
        FunctionConsts::ZORBA_STORE_INDEXES_STATIC_DML_KEYS_1);

  }

}


}



