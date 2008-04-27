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
#include "compiler/rewriter/rules/ruleset.h"
#include "context/static_context.h"
#include "compiler/rewriter/tools/expr_tools.h"

namespace zorba {

RULE_REWRITE_PRE(EliminateExtraneousPathSteps)
{
  relpath_expr *re = dynamic_cast<relpath_expr *>(node);
  if (re != NULL) {
    ulong numSteps = re->size();
    
    for (ulong i = 0; i < numSteps - 1; i++) {
      axis_step_expr* axisStep = dynamic_cast<axis_step_expr*>((*re)[i].getp());
      
      if (axisStep != NULL &&
          axisStep->getAxis() == axis_kind_descendant_or_self &&
          axisStep->getTest()->getTestKind() == match_anykind_test)
      {
        axis_step_expr* nextStep = dynamic_cast<axis_step_expr*>((*re)[i+1].getp());
        if (nextStep != NULL &&
            nextStep->getAxis() == axis_kind_child)
        {
          nextStep->setAxis(axis_kind_descendant);
          (*re).erase(i);
          numSteps--;
          i--;
        }
      }
    }

    if (numSteps == 1) {
      return (*re) [0];
    }
  }

  return NULL;
}

RULE_REWRITE_POST(EliminateExtraneousPathSteps)
{
  return NULL;
}

}
/* vim:set ts=2 sw=2: */
