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
#include "runtime/xqdoc/xqdoc.h"
#include "functions/func_xqdoc.h"


namespace zorba{



PlanIter_t fn_zorba_xqdoc_xqdoc::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new XQDocIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_xqdoc_xqdoc_options_impl::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new XQDocIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_xqdoc_xqdoc_content::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new XQDocContentIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_xqdoc_xqdoc_content_options_impl::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new XQDocContentIterator(sctx, loc, argv);
}

void populate_context_xqdoc(static_context* sctx)
{


      {
    DECL_WITH_KIND(sctx, fn_zorba_xqdoc_xqdoc,
        (createQName("http://www.zorba-xquery.com/modules/xqdoc","","xqdoc"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ELEMENT_TYPE_ONE),
        FunctionConsts::FN_ZORBA_XQDOC_XQDOC_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_xqdoc_xqdoc_options_impl,
        (createQName("http://www.zorba-xquery.com/modules/xqdoc","","xqdoc-options-impl"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ELEMENT_TYPE_ONE, 
        GENV_TYPESYSTEM.ELEMENT_TYPE_ONE),
        FunctionConsts::FN_ZORBA_XQDOC_XQDOC_OPTIONS_IMPL_2);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_xqdoc_xqdoc_content,
        (createQName("http://www.zorba-xquery.com/modules/xqdoc","","xqdoc-content"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ELEMENT_TYPE_ONE),
        FunctionConsts::FN_ZORBA_XQDOC_XQDOC_CONTENT_1);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_xqdoc_xqdoc_content_options_impl,
        (createQName("http://www.zorba-xquery.com/modules/xqdoc","","xqdoc-content-options-impl"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.ELEMENT_TYPE_ONE, 
        GENV_TYPESYSTEM.ELEMENT_TYPE_ONE),
        FunctionConsts::FN_ZORBA_XQDOC_XQDOC_CONTENT_OPTIONS_IMPL_2);

  }

}


}



