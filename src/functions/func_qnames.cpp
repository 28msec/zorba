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


#include "runtime/qnames/qnames.h"
#include "functions/func_qnames.h"


namespace zorba{



PlanIter_t fn_resolve_QName::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ResolveQNameIterator ( sctx, loc, argv[0], argv[1]);
}

PlanIter_t fn_QName::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new QNameIterator ( sctx, loc, argv[0], argv[1]);
}

PlanIter_t op_QName_equal::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new QNameEqualIterator ( sctx, loc, argv[0], argv[1]);
}

PlanIter_t fn_prefix_from_QName::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new PrefixFromQNameIterator ( sctx, loc, argv[0]);
}

PlanIter_t fn_local_name_from_QName::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new LocalNameFromQNameIterator ( sctx, loc, argv[0]);
}

PlanIter_t fn_namespace_uri_from_QName::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new NamespaceUriFromQNameIterator ( sctx, loc, argv[0]);
}

PlanIter_t fn_namespace_uri_for_prefix::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new NamespaceUriForPrefixIterator ( sctx, loc, argv);
}

PlanIter_t fn_in_scope_prefixes::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new InScopePrefixesIterator ( sctx, loc, argv[0]);
}

void populate_context_qnames(static_context* sctx) {
  DECL(sctx, fn_resolve_QName,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","resolve-QName"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ELEMENT_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION));


  DECL(sctx, fn_QName,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","QName"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_ONE));


  DECL(sctx, op_QName_equal,
      (createQName("http://www.w3.org/2005/xpath-functions","fn",":QName-equal"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));


  DECL(sctx, fn_prefix_from_QName,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","prefix-from-QName"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.NCNAME_TYPE_QUESTION));


  DECL(sctx, fn_local_name_from_QName,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","local-name-from-QName"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.NCNAME_TYPE_QUESTION));


  DECL(sctx, fn_namespace_uri_from_QName,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","namespace-uri-from-QName"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));


  DECL(sctx, fn_namespace_uri_for_prefix,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","namespace-uri-for-prefix"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.ELEMENT_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));


  DECL(sctx, fn_in_scope_prefixes,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","in-scope-prefixes"),
      GENV_TYPESYSTEM.ELEMENT_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_STAR));

}


}