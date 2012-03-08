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
#include "stdafx.h"

#include "runtime/core/constructors.h"
#include "runtime/json/jsoniq_functions.h"

#include "functions/function_impl.h"

#include "compiler/expression/fo_expr.h"

#include "system/globalenv.h"

#include "types/typeops.h"

namespace zorba
{


/*******************************************************************************
   Used to concatenate adjacent atomic values in the input sequence into a 
   text node. Concatenation inserts a single space between each pair of atomic
   values.
********************************************************************************/
class op_enclosed_expr : public function 
{
public:
  op_enclosed_expr(const signature& sig)
    :
    function(sig, FunctionConsts::OP_ENCLOSED_1)
  {
  }

  xqtref_t getReturnType(const fo_expr* caller) const;

  bool mustCopyInputNodes(expr* fo, csize input) const
  {
    return false;
  }

  bool propagatesDistinctNodes(csize producer) const
  {
    return producer == 0;
  }

  bool propagatesSortedNodes(csize producer) const
  {
    return producer == 0;
  }

  CODEGEN_DECL();
};


xqtref_t op_enclosed_expr::getReturnType(const fo_expr* caller) const
{
  xqtref_t argType = caller->get_arg(0)->get_return_type();

  if (argType->type_kind() == XQType::NODE_TYPE_KIND)
    return argType;
  else
    return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}


PlanIter_t op_enclosed_expr::codegen(
    CompilerCB* /* cb */,
    static_context* sctx,
    const QueryLoc& loc, 
    std::vector<PlanIter_t>& argv,
    expr& ann) const
{
#ifdef ZORBA_WITH_JSON
  fo_expr* enclosedExpr = static_cast<fo_expr*>(&ann);

  expr* inputExpr = enclosedExpr->get_arg(0);

  if (inputExpr->get_function_kind() == FunctionConsts::OP_ZORBA_FLATTEN_INTERNAL_1)
  {
    TypeManager* tm = inputExpr->get_type_manager();

    expr* contentExpr = static_cast<fo_expr*>(inputExpr)->get_arg(0);
    xqtref_t type = contentExpr->get_return_type();

    type = TypeOps::intersect_type(*type, *GENV_TYPESYSTEM.JSON_ITEM_TYPE_STAR, tm);

    if (type->is_none() || type->is_empty())
    {
      assert(dynamic_cast<JSONFlattenIterator*>(argv[0].getp()) != NULL);
      
      PlanIter_t inputIter = 
      static_cast<JSONFlattenIterator*>(argv[0].getp())->getChild();

      return new EnclosedIterator(sctx, loc, inputIter);
    }
  }
#endif

  return new EnclosedIterator(sctx, loc, argv[0]);
}



void populateContext_Constructors(static_context* sctx)
{
  const char* zorba_op_ns = static_context::ZORBA_OP_NS;

  DECL(sctx, op_enclosed_expr,
       (createQName(zorba_op_ns, "", "enclosed-expr"),
        GENV_TYPESYSTEM.ITEM_TYPE_STAR,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}


}
/* vim:set et sw=2 ts=2: */
