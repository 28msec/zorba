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
#include "runtime/core/constructors.h"

#include "functions/function_impl.h"

#include "system/globalenv.h"


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

  xqtref_t getReturnType(const std::vector<xqtref_t>& arg_types) const;

  bool propagatesDistinctNodes(ulong producer) const
  {
    return producer == 0;
  }

  bool propagatesSortedNodes(ulong producer) const
  {
    return producer == 0;
  }

  DEFAULT_UNARY_CODEGEN(EnclosedIterator);
};


xqtref_t op_enclosed_expr::getReturnType(const std::vector<xqtref_t>& arg_types) const
{
  xqtref_t argType = arg_types[0];

  if (argType->type_kind() == XQType::NODE_TYPE_KIND)
    return argType;
  else
    return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}


void populateContext_Constructors(static_context* sctx)
{
DECL(sctx, op_enclosed_expr,
     (createQName(ZORBA_OP_NS, "op", "enclosed-expr"),
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR));
}


}
