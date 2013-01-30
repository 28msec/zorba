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

#include "context/static_context.h"

#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/expression/path_expr.h"


namespace zorba
{

RULE_REWRITE_PRE(EliminateExtraneousPathSteps)
{
  if (node->get_expr_kind() == relpath_expr_kind)
  {
    relpath_expr* re = static_cast<relpath_expr *>(node);
    csize numSteps = re->size();

    for (csize i = 1; i < numSteps - 1; ++i)
    {
      assert((*re)[i]->get_expr_kind() == axis_step_expr_kind);

      axis_step_expr* axisStep = static_cast<axis_step_expr*>((*re)[i]);

      if (axisStep->getAxis() == axis_kind_descendant_or_self &&
          axisStep->getTest()->getTestKind() == match_anykind_test)
      {
        axis_step_expr* nextStep = static_cast<axis_step_expr*>((*re)[i+1]);
        if (nextStep->getAxis() == axis_kind_child)
        {
          nextStep->setAxis(axis_kind_descendant);
          (*re).erase(i);
          numSteps--;
          i--;
        }
      }
    }

    if (numSteps == 1)
    {
      return (*re)[0];
    }
  }

  return NULL;
}


RULE_REWRITE_POST(EliminateExtraneousPathSteps)
{
  return NULL;
}

}
/* vim:set et sw=2 ts=2: */
