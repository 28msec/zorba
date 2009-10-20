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

#include "runtime/accessors/accessors.h"

namespace zorba{


PlanIter_t fn_node_name::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new NodeNameIterator(sctx,loc,argv);
}




PlanIter_t fn_nilled::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new NilledIterator(sctx,loc,argv);
}




PlanIter_t fn_base_uri::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new BaseUriIterator(sctx,loc,argv);
}




PlanIter_t fn_document_uri::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new DocumentUriIterator(sctx,loc,argv);
}




PlanIter_t fn_root::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new RootIterator(sctx,loc,argv);
}



void populate_context_accessors(static_context* sctx) {

  DECL(sctx, fn_node_name,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","node-name"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION));

  DECL(sctx, fn_nilled,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","nilled"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION));

  DECL(sctx, fn_base_uri,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","base-uri"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

  DECL(sctx, fn_document_uri,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","document-uri"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

  DECL(sctx, fn_root,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","root"),
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION));
}

}