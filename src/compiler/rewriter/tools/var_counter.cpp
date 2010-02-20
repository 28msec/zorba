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
#include "compiler/expression/expr.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/expression/abstract_expr_visitor.h"


namespace zorba {

bool count_variable_uses_rec(
    const expr* e,
    const var_expr* var,
    RewriterContext* rCtx,
    int limit,
    int& count)
{
  if (limit > 0 && count >= limit)
  {
    return false;
  }

  if (e == var)
  {
    ++count;
    return true;
  }

  for (const_expr_iterator iter = e->expr_begin_const(); !iter.done(); ++iter)
  {
    if (!count_variable_uses_rec((*iter), var, rCtx, limit, count))
      return false;
  }

  return true;
}


int count_variable_uses(
    const expr* root,
    const var_expr* var,
    RewriterContext* rCtx,
    int limit = 0)
{
  int count = 0;

  count_variable_uses_rec(root, var, rCtx, limit, count);

  return count;
}


}

/* vim:set ts=2 sw=2: */
