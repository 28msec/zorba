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
#include "runtime/fetch/fetch.h"
#include "functions/func_fetch.h"


namespace zorba{



PlanIter_t fn_zorba_fetch_content::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FetchContentIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_fetch_content_binary::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FetchContentBinaryIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_fetch_content_type::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FetchContentTypeIterator(sctx, loc, argv);
}

void populate_context_fetch(static_context* sctx)
{


      {
    DECL_WITH_KIND(sctx, fn_zorba_fetch_content,
        (createQName("http://www.zorba-xquery.com/modules/fetch","","content"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_ZORBA_FETCH_CONTENT_3);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_fetch_content_binary,
        (createQName("http://www.zorba-xquery.com/modules/fetch","","content-binary"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.BASE64BINARY_TYPE_ONE),
        FunctionConsts::FN_ZORBA_FETCH_CONTENT_BINARY_2);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_fetch_content_type,
        (createQName("http://www.zorba-xquery.com/modules/fetch","","content-type"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_ZORBA_FETCH_CONTENT_TYPE_1);

  }

}


}



