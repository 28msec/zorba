/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
#include "runtime/seq/seq.h"
#include "functions/func_seq.h"


namespace zorba{



PlanIter_t fn_zorba_seq_value_intersect::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new SeqValueIntersectIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_seq_value_union::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new SeqValueUnionIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_seq_value_except::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new SeqValueExceptIterator(sctx, loc, argv);
}

void populate_context_seq(static_context* sctx)
{


      {
    DECL_WITH_KIND(sctx, fn_zorba_seq_value_intersect,
        (createQName("http://zorba.io/modules/sequence","","value-intersect"), 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR),
        FunctionConsts::FN_ZORBA_SEQ_VALUE_INTERSECT_2);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_seq_value_union,
        (createQName("http://zorba.io/modules/sequence","","value-union"), 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR),
        FunctionConsts::FN_ZORBA_SEQ_VALUE_UNION_2);

  }




      {
    DECL_WITH_KIND(sctx, fn_zorba_seq_value_except,
        (createQName("http://zorba.io/modules/sequence","","value-except"), 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR, 
        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR),
        FunctionConsts::FN_ZORBA_SEQ_VALUE_EXCEPT_2);

  }

}


}



