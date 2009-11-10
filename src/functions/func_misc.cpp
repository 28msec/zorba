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


#include "runtime/misc/misc.h"
#include "functions/func_misc.h"


namespace zorba{







PlanIter_t op_zorba_read_line::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ReadLineIterator(sctx,loc,argv);
}




PlanIter_t op_zorba_print::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new PrintIterator(sctx,loc,argv);
}




PlanIter_t fn_resolve_uri::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ResolveUriIterator(sctx,loc,argv);
}




PlanIter_t fn_error::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new ErrorIterator(sctx,loc,argv);
}



void populate_context_misc(static_context* sctx) {

  DECL(sctx, fn_trace,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","trace"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, op_zorba_read_line,
      (createQName("http://www.zorba-xquery.com/zorba/internal-functions","op-zorba","read-line"),
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

  DECL(sctx, op_zorba_print,
      (createQName("http://www.zorba-xquery.com/zorba/internal-functions","op-zorba","print"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.EMPTY_TYPE));

  DECL(sctx, fn_resolve_uri,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","resolve-uri"),
      GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ANY_URI_TYPE_QUESTION));

  DECL(sctx, fn_error,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","error"),
      GENV_TYPESYSTEM.NONE_TYPE));

  DECL(sctx, fn_error,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","error"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

  DECL(sctx, fn_error,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","error"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.NONE_TYPE));

  DECL(sctx, fn_error,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","error"),
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION,
      GENV_TYPESYSTEM.STRING_TYPE_ONE,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.NONE_TYPE));
}


}