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


#include "runtime/function_item/function_item_iter.h"
#include "functions/func_function_item_iter.h"


namespace zorba{



PlanIter_t fn_function_name::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FunctionNameIterator(sctx, loc, argv);
}

PlanIter_t fn_function_arity::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new FunctionArityIterator(sctx, loc, argv);
}

void populate_context_function_item_iter(static_context* sctx)
{
  DECL(sctx, fn_function_name,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","function-name"),
      GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_QUESTION));


  DECL(sctx, fn_function_arity,
      (createQName("http://www.w3.org/2005/xpath-functions","fn","function-arity"),
      GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_ONE,
      GENV_TYPESYSTEM.INTEGER_TYPE_ONE));

}


}



