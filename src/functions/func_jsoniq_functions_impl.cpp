/*
 * Copyright 2011 The FLWOR Foundation.
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

#include "functions/func_jsoniq_functions.h"
#include "runtime/json/jsoniq_functions.h"
#include "runtime/core/item_iterator.h"
#include "compiler/parser/query_loc.h"

#include "compiler/expression/expr_consts.h"
#include "compiler/expression/fo_expr.h"

#include "types/typeops.h"

namespace zorba
{

#ifdef ZORBA_WITH_JSON

PlanIter_t fn_jsoniq_flatten::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONFlattenIterator(sctx, loc, argv[0], false);
}


PlanIter_t op_zorba_flatten_internal::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  return new JSONFlattenIterator(sctx, loc, argv[0], true);
}


PlanIter_t fn_jsoniq_parse_json::codegen(
  CompilerCB*,
  static_context* sctx,
  const QueryLoc& loc,
  std::vector<PlanIter_t>& argv,
  expr& ann) const
{
  SingletonIterator* lArg = dynamic_cast<SingletonIterator*>(argv[0].getp());
  if (lArg && lArg->getValue()->isAtomic())
  {
    const QueryLoc& lArgLoc = lArg->getLocation();
    return new JSONParseIterator(sctx, loc, argv, lArgLoc);
  }
  else
  {
    QueryLoc lArgLoc = QueryLoc::null;
    return new JSONParseIterator(sctx, loc, argv, lArgLoc);
  }
}


xqtref_t op_zorba_json_unbox::getReturnType(const fo_expr* caller) const
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;
  TypeManager* tm = caller->get_type_manager();
  xqtref_t lArgType = caller->get_arg(0)->get_return_type();

  if (!TypeOps::is_subtype(tm, *lArgType, *rtm.JSON_ITEM_TYPE_STAR))
  {
    return lArgType;
  }

  if (TypeOps::is_subtype(tm, *lArgType, *rtm.JSON_OBJECT_TYPE_STAR) ||
      TypeOps::is_subtype(tm, *lArgType, *rtm.JSON_ARRAY_TYPE_STAR))
  {
    return lArgType;
  }
  return rtm.ITEM_TYPE_STAR;
}

#endif // ZORBA_WITH_JSON

} /* namespace zorba */

/* vim:set et sw=2 ts=2: */
