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
#include "runtime/errors_and_diagnostics/errors_and_diagnostics.h"
#include "functions/func_errors_and_diagnostics.h"


namespace zorba{



PlanIter_t fn_error::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ErrorIterator(sctx, loc, argv);
}


void populate_context_errors_and_diagnostics(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, fn_error,
        (createQName("http://www.w3.org/2005/xpath-functions","","error"), 
        GENV_TYPESYSTEM.NONE_TYPE),
        FunctionConsts::FN_ERROR_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_error,
        (createQName("http://www.w3.org/2005/xpath-functions","","error"), 
        GENV_TYPESYSTEM.QNAME_TYPE_ONE, 
        GENV_TYPESYSTEM.NONE_TYPE),
        FunctionConsts::FN_ERROR_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_error,
        (createQName("http://www.w3.org/2005/xpath-functions","","error"), 
        GENV_TYPESYSTEM.QNAME_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.NONE_TYPE),
        FunctionConsts::FN_ERROR_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_error,
        (createQName("http://www.w3.org/2005/xpath-functions","","error"), 
        GENV_TYPESYSTEM.QNAME_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.NONE_TYPE),
        FunctionConsts::FN_ERROR_3);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_trace,
        (createQName("http://www.w3.org/2005/xpath-functions","","trace"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::FN_TRACE_2);

  }

}


}



