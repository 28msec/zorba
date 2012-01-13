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
#include "runtime/access/access.h"
#include "functions/func_access.h"


namespace zorba{



PlanIter_t fn_uri_collection::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnURICollectionIterator(sctx, loc, argv);
}

PlanIter_t fn_unparsed_text::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnUnparsedTextIterator(sctx, loc, argv);
}

PlanIter_t fn_unparsed_text_available::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnUnparsedTextAvailableIterator(sctx, loc, argv);
}

PlanIter_t fn_available_environment_variables::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnAvailableEnvironmentVariablesIterator(sctx, loc, argv);
}

PlanIter_t fn_environment_variable::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnEnvironmentVariableIterator(sctx, loc, argv);
}

void populate_context_access(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, fn_uri_collection,
        (createQName("http://www.w3.org/2005/xpath-functions","","uri-collection"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_STAR),
        FunctionConsts::FN_URI_COLLECTION_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_uri_collection,
        (createQName("http://www.w3.org/2005/xpath-functions","","uri-collection"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_STAR),
        FunctionConsts::FN_URI_COLLECTION_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_unparsed_text,
        (createQName("http://www.w3.org/2005/xpath-functions","","unparsed-text"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION),
        FunctionConsts::FN_UNPARSED_TEXT_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_unparsed_text,
        (createQName("http://www.w3.org/2005/xpath-functions","","unparsed-text"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION),
        FunctionConsts::FN_UNPARSED_TEXT_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_unparsed_text_available,
        (createQName("http://www.w3.org/2005/xpath-functions","","unparsed-text-available"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION),
        FunctionConsts::FN_UNPARSED_TEXT_AVAILABLE_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_unparsed_text_available,
        (createQName("http://www.w3.org/2005/xpath-functions","","unparsed-text-available"), 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION),
        FunctionConsts::FN_UNPARSED_TEXT_AVAILABLE_2);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_available_environment_variables,
        (createQName("http://www.w3.org/2005/xpath-functions","","available-environment-variables"), 
        GENV_TYPESYSTEM.STRING_TYPE_STAR),
        FunctionConsts::FN_AVAILABLE_ENVIRONMENT_VARIABLES_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_environment_variable,
        (createQName("http://www.w3.org/2005/xpath-functions","","environment-variable"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE, 
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION),
        FunctionConsts::FN_ENVIRONMENT_VARIABLE_1);

  }

}


}



