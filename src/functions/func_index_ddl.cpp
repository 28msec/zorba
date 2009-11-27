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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************


#include "runtime/indexing/index_ddl.h"
#include "functions/func_index_ddl.h"


namespace zorba{



PlanIter_t fn_zorba_ddl_create_index::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new CreateIndexIterator ( sctx, loc, argv[0]);
}

PlanIter_t fn_zorba_ddl_delete_index::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new DeleteIndexIterator ( sctx, loc, argv[0]);
}

void populate_context_index_ddl(static_context* sctx) {
  DECL(sctx, fn_zorba_ddl_create_index,
      (createQName("http://www.zorba-xquery.com/modules/ddl","fn-zorba-ddl","create-index"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));


  DECL(sctx, fn_zorba_ddl_delete_index,
      (createQName("http://www.zorba-xquery.com/modules/ddl","fn-zorba-ddl","delete-index"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

}


}