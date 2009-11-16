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


#include "runtime/base64/base64.h"
#include "functions/func_base64.h"


namespace zorba{



PlanIter_t fn_zorba_util_base64Decode::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new Base64DecodeIterator ( sctx, loc, argv);
}

PlanIter_t fn_zorba_util_base64Encode::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new Base64EncodeIterator ( sctx, loc, argv);
}

void populate_context_base64(static_context* sctx) {
  DECL(sctx, fn_zorba_util_base64Decode,
      (createQName("http://www.zorba-xquery.com/zorba/util-functions","fn-zorba-util","base64Decode"),
      GENV_TYPESYSTEM.BASE64BINARY_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));


  DECL(sctx, fn_zorba_util_base64Encode,
      (createQName("http://www.zorba-xquery.com/zorba/util-functions","fn-zorba-util","base64Encode"),
      GENV_TYPESYSTEM.ITEM_TYPE_ONE,
      GENV_TYPESYSTEM.BASE64BINARY_TYPE_ONE));

}


}