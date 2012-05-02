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


#include "stdafx.h"
#include "runtime/function_item/function_item_iter.h"
#include "functions/func_function_item_iter.h"


namespace zorba{



PlanIter_t fn_function_name_3_0::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FunctionNameIterator(sctx, loc, argv);
}

PlanIter_t fn_function_arity_3_0::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FunctionArityIterator(sctx, loc, argv);
}

PlanIter_t fn_partial_apply_3_0::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new PartialApplyIterator(sctx, loc, argv);
}

void populate_context_function_item_iter(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, fn_function_name_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","function-name"), 
        GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE, 
        GENV_TYPESYSTEM.QNAME_TYPE_QUESTION),
        FunctionConsts::FN_FUNCTION_NAME_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_function_arity_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","function-arity"), 
        GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE),
        FunctionConsts::FN_FUNCTION_ARITY_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_partial_apply_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","partial-apply"), 
        GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE),
        FunctionConsts::FN_PARTIAL_APPLY_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_partial_apply_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","partial-apply"), 
        GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE, 
        GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE),
        FunctionConsts::FN_PARTIAL_APPLY_3);

  }

}


}



