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


#include "runtime/nodes/nodes.h"
#include "functions/func_nodes.h"


namespace zorba{



PlanIter_t fn_zorba_ref_node_reference::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new NodeReferenceIterator ( sctx, loc, argv);
}




PlanIter_t fn_zorba_ref_node_by_reference::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new NodeByReferenceIterator ( sctx, loc, argv);
}




PlanIter_t fn_local_name::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnLocalNameIterator ( sctx, loc, argv);
}




PlanIter_t fn_namespace_uri::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnNamespaceUriIterator ( sctx, loc, argv);
}




PlanIter_t fn_lang::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FnLangIterator ( sctx, loc, argv);
}



void populate_context_nodes(static_context* sctx) {

  DECL(sctx, fn_zorba_ref_node_reference,
      (createQName("http://www.zorba-xquery.com/zorba/node-ref-functions","fn-zorba-ref","node-reference"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_URI_TYPE_ONE));

  DECL(sctx, fn_zorba_ref_node_by_reference,
      (createQName("http://www.zorba-xquery.com/zorba/node-ref-functions","fn-zorba-ref","node-by-reference"),
      GENV_TYPESYSTEM.ANY_URI_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE));

  DECL(sctx, fn_local_name,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","local-name"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

  DECL(sctx, fn_namespace_uri,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","namespace-uri"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

  DECL(sctx, fn_lang,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","lang"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));
}


}