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
#include "runtime/errors_and_diagnostics/other_diagnostics.h"
#include "functions/func_other_diagnostics.h"


namespace zorba{



PlanIter_t op_zorba_read_line::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new ReadLineIterator(sctx, loc, argv);
}

PlanIter_t fn_zorba_util_print::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new PrintIterator(sctx, loc, argv);
}

void populate_context_other_diagnostics(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, op_zorba_read_line,
        (createQName("http://www.zorba-xquery.com/internal/zorba-ops","","read-line"), 
        GENV_TYPESYSTEM.STRING_TYPE_ONE),
        FunctionConsts::OP_ZORBA_READ_LINE_0);

  }


  {
    

    DECL_WITH_KIND(sctx, fn_zorba_util_print,
        (createQName("http://www.zorba-xquery.com/zorba/util-functions","","print"), 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.EMPTY_TYPE),
        FunctionConsts::FN_ZORBA_UTIL_PRINT_1);

  }

}


}



