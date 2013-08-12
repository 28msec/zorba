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
#include "runtime/reference/reference.h"
#include "functions/func_reference.h"


namespace zorba{



PlanIter_t fn_reference_reference::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new ReferenceIterator(sctx, loc, argv);
}

PlanIter_t fn_reference_has_reference::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new HasReferenceIterator(sctx, loc, argv);
}

PlanIter_t fn_reference_assign_reference::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new AssignReferenceIterator(sctx, loc, argv);
}

PlanIter_t fn_reference_dereference::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new DereferenceIterator(sctx, loc, argv);
}

void populate_context_reference(static_context* sctx)
{


      {
    DECL_WITH_KIND(sctx, fn_reference_reference,
        (createQName("http://zorba.io/modules/reference","","reference"), 
        GENV_TYPESYSTEM.STRUCTURED_ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_REFERENCE_REFERENCE_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_reference_has_reference,
        (createQName("http://zorba.io/modules/reference","","has-reference"), 
        GENV_TYPESYSTEM.STRUCTURED_ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_REFERENCE_HAS_REFERENCE_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_reference_assign_reference,
        (createQName("http://zorba.io/modules/reference","","assign-reference"), 
        GENV_TYPESYSTEM.STRUCTURED_ITEM_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE),
        FunctionConsts::FN_REFERENCE_ASSIGN_REFERENCE_2);

  }




      {
    DECL_WITH_KIND(sctx, fn_reference_dereference,
        (createQName("http://zorba.io/modules/reference","","dereference"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRUCTURED_ITEM_TYPE_QUESTION),
        FunctionConsts::FN_REFERENCE_DEREFERENCE_1);

  }

}


}



