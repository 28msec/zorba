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


#include "runtime/reflection/reflection.h"
#include "functions/func_reflection.h"


namespace zorba{



PlanIter_t fn_zorba_reflection_invoke::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  AnnotationHolder& ann) const
{
  return new InvokeIterator(sctx, loc, argv);
}

void populate_context_reflection(static_context* sctx)
{
  DECL_WITH_KIND(sctx, fn_zorba_reflection_invoke,
      (createQName("http://www.zorba-xquery.com/modules/reflection","","invoke"),
      GENV_TYPESYSTEM.QNAME_TYPE_ONE,
      true,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR),
      FunctionConsts::FN_ZORBA_REFLECTION_INVOKE_N);

}


}



