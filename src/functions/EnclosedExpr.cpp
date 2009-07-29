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
#include "system/globalenv.h"
#include "functions/EnclosedExpr.h"
#include "runtime/core/item_iterator.h"
#include "runtime/core/constructors.h"

namespace zorba
{


xqtref_t op_enclosed_expr::return_type(const std::vector<xqtref_t>& arg_types) const
{
  xqtref_t argType = arg_types[0];

  if (argType->type_kind() == XQType::NODE_TYPE_KIND)
    return argType;
  else
    return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}


PlanIter_t op_enclosed_expr::codegen(
    CompilerCB* /*cb*/,
    short sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& argv,
    AnnotationHolder& ann) const
{
  return new EnclosedIterator ( sctx, loc, argv[0] );
}
  
  
}
