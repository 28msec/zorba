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
#include "runtime/jsound/jsound.h"
#include "functions/func_jsound.h"


namespace zorba{



PlanIter_t fn_zorba_jsound_jsd_annotate::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSoundAnnotateIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_jsound_jsd_validate::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSoundValidateIterator(sctx, loc, argv);
}

void populate_context_jsound(static_context* sctx)
{


      {
    DECL_WITH_KIND(sctx, fn_zorba_jsound_jsd_annotate,
        (createQName("http://jsound.io/modules/jsound","","jsd-annotate"), 
        GENV_TYPESYSTEM.JSON_OBJECT_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_ONE),
        FunctionConsts::FN_ZORBA_JSOUND_JSD_ANNOTATE_3);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_jsound_jsd_validate,
        (createQName("http://jsound.io/modules/jsound","","jsd-validate"), 
        GENV_TYPESYSTEM.JSON_OBJECT_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_ZORBA_JSOUND_JSD_VALIDATE_3);

  }

}


}



