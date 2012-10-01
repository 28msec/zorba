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

#include "compiler/rewriter/rules/rule_base.h"
#include "compiler/expression/expr_base.h"
#include "compiler/expression/expr_iter.h"


namespace zorba
{


/*******************************************************************************
  Apply the given rule to the "curExpr" and, recursively, to each sub expression
  of "curExpr". If any rewrite is done anywhere inside the expr sub tree rooted
  at "curExpr", then "modified" will be set to true ("modified" is never set to
  false by this method). If as part of a re-write, "curExpr" is rewriten into
  another expr E, then E is returned to the caller.
********************************************************************************/
expr* PrePostRewriteRule::apply(RewriterContext& rCtx, expr* curExpr, bool& modified)
{
  expr* result = NULL;

  expr* newExpr = rewritePre(&*curExpr, rCtx);
  if (newExpr != NULL)
  {
    curExpr = newExpr;
    result = newExpr;
    modified = true;
  }

  ExprIterator iter(curExpr);

  while (!iter.done())
  {
    expr* new_e = apply(rCtx, **iter, modified);
    if (new_e != NULL)
    {
      **iter = new_e;
    }

    iter.next();
  }

  newExpr = rewritePost(&*curExpr, rCtx);
  if (newExpr != NULL)
  {
    result = newExpr;
    modified = true;
  }

  return result;
}


}

/* vim:set et sw=2 ts=2: */
