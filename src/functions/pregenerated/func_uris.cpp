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
#include "runtime/uris/uris.h"
#include "functions/func_uris.h"


namespace zorba{



PlanIter_t fn_zorba_uri_decode::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new DecodeURIIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_uri_parse::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new ParseURIIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_uri_serialize::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new SerializeURIIterator(sctx, loc, argv);
}

void populate_context_uris(static_context* sctx)
{


      {
    DECL_WITH_KIND(sctx, fn_zorba_uri_decode,
        (createQName("http://zorba.io/modules/uri","","decode"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_ZORBA_URI_DECODE_3);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_uri_parse,
        (createQName("http://zorba.io/modules/uri","","parse"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.JSON_OBJECT_TYPE_ONE),
        FunctionConsts::FN_ZORBA_URI_PARSE_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_uri_serialize,
        (createQName("http://zorba.io/modules/uri","","serialize"), 
        GENV_TYPESYSTEM.JSON_OBJECT_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_ZORBA_URI_SERIALIZE_1);

  }

}


}



