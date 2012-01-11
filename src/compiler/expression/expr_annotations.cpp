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
#include "compiler/expression/expr_annotations.h"
#include "compiler/expression/expr.h"
#include "functions/function.h"

namespace zorba {


bool ExpressionPropertyComputer::returnsDuplicateNodes(expr *e)
{
  return true;
}


bool ExpressionPropertyComputer::returnsDescendantNodes(expr *e)
{
  switch(e->get_expr_kind()) {
    case relpath_expr_kind:
      {
        relpath_expr *re = static_cast<relpath_expr *>(e);
        uint32_t numSteps = re->size();
        for(uint32_t i = 0; i < numSteps; ++i) {
          expr *rec = &*(*re)[i];
          axis_step_expr *axis = dynamic_cast<axis_step_expr *>(rec);
          if (axis != NULL) {
            if (axis->getAxis() == axis_kind_descendant
              || axis->getAxis() == axis_kind_descendant_or_self) {
              return true;
            }
          } else {
            return returnsDescendantNodes(rec);
          }
        }
      }
      break;

    default:
      for(expr_iterator i = e->expr_begin(); !i.done(); ++i) {
        if (*i != NULL) {
          if (returnsDescendantNodes(*i)) {
            return true;
          }
        }
      }
      break;
  }
  return false;
}


bool ExpressionPropertyComputer::returnsAncestorNodes(expr *e)
{
  return true;
}

}
/* vim:set et sw=2 ts=2: */
