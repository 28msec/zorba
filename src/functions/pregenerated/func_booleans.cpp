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
#include "runtime/booleans/booleans.h"
#include "functions/func_booleans.h"


namespace zorba{



PlanIter_t op_is_same_node::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new IsSameNodeIterator(sctx, loc, argv);
}

PlanIter_t op_node_before::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new NodeBeforeIterator(sctx, loc, argv);
}

PlanIter_t op_node_after::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new NodeAfterIterator(sctx, loc, argv);
}

void populate_context_booleans(static_context* sctx)
{
  {
    

    DECL_WITH_KIND(sctx, op_is_same_node,
        (createQName("http://www.zorba-xquery.com/internal/xquery-ops","","is-same-node"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION),
        FunctionConsts::OP_IS_SAME_NODE_2);

  }


  {
    

    DECL_WITH_KIND(sctx, op_node_before,
        (createQName("http://www.zorba-xquery.com/internal/xquery-ops","","node-before"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION),
        FunctionConsts::OP_NODE_BEFORE_2);

  }


  {
    

    DECL_WITH_KIND(sctx, op_node_after,
        (createQName("http://www.zorba-xquery.com/internal/xquery-ops","","node-after"), 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.ANY_NODE_TYPE_QUESTION, 
        GENV_TYPESYSTEM.BOOLEAN_TYPE_QUESTION),
        FunctionConsts::OP_NODE_AFTER_2);

  }

}


}



