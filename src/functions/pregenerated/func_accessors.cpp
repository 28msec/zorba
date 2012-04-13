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
#include "runtime/accessors/accessors.h"
#include "functions/func_accessors.h"


namespace zorba{



PlanIter_t fn_node_name_3_0::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new NodeNameIterator(sctx, loc, argv);
}
PlanIter_t fn_node_name::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new NodeNameIterator(sctx, loc, argv);
}

PlanIter_t fn_nilled::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new NilledIterator(sctx, loc, argv);
}


PlanIter_t fn_data::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new FnDataIterator(sctx, loc, argv);
}

PlanIter_t fn_base_uri::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new BaseUriIterator(sctx, loc, argv);
}

PlanIter_t fn_document_uri_3_0::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new DocumentUriIterator(sctx, loc, argv);
}
PlanIter_t fn_document_uri::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new DocumentUriIterator(sctx, loc, argv);
}

PlanIter_t fn_root::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new RootIterator(sctx, loc, argv);
}

void populate_context_accessors(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, fn_node_name_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","node-name"), 
        GENV_TYPESYSTEM.QNAME_TYPE_QUESTION),
        FunctionConsts::FN_NODE_NAME_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_node_name,
        (createQName("http://www.w3.org/2005/xpath-functions","","node-name"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.QNAME_TYPE_QUESTION),
        FunctionConsts::FN_NODE_NAME_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_nilled,
        (createQName("http://www.w3.org/2005/xpath-functions","","nilled"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION),
        FunctionConsts::FN_NILLED_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_string,
        (createQName("http://www.w3.org/2005/xpath-functions","","string"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_STRING_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_string,
        (createQName("http://www.w3.org/2005/xpath-functions","","string"), 
        GENV_TYPESYSTEM.ITEM_TYPE_QUESTION, 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::FN_STRING_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_data,
        (createQName("http://www.w3.org/2005/xpath-functions","","data"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR),
        FunctionConsts::FN_DATA_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_base_uri,
        (createQName("http://www.w3.org/2005/xpath-functions","","base-uri"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION),
        FunctionConsts::FN_BASE_URI_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_base_uri,
        (createQName("http://www.w3.org/2005/xpath-functions","","base-uri"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION),
        FunctionConsts::FN_BASE_URI_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_document_uri_3_0,
        (createQName("http://www.w3.org/2005/xpath-functions","","document-uri"), 
        GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION),
        FunctionConsts::FN_DOCUMENT_URI_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_document_uri,
        (createQName("http://www.w3.org/2005/xpath-functions","","document-uri"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION),
        FunctionConsts::FN_DOCUMENT_URI_1);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_root,
        (createQName("http://www.w3.org/2005/xpath-functions","","root"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION),
        FunctionConsts::FN_ROOT_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_root,
        (createQName("http://www.w3.org/2005/xpath-functions","","root"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION),
        FunctionConsts::FN_ROOT_1);

  }

}


}



