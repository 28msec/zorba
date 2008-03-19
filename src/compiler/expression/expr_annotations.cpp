#include "compiler/expression/expr_annotations.h"
#include "functions/function.h"

namespace zorba {

void SourceFinder::findSources(expr *e)
{
  switch(e->get_expr_kind()) {
    case flwor_expr_kind:
      findSources(static_cast<flwor_expr *>(e)->get_retval());
      break;

    case fo_expr_kind:
      {
        fo_expr *fo = static_cast<fo_expr *>(e);
        const function *fn = fo->get_func();
        if (fn->isSource()) {
          m_sources.insert(fo);
        } else {
          findSourcesInChildren(fo);
        }
      }
      break;

    case var_expr_kind:
      {
        var_expr *var = static_cast<var_expr *>(e);
        switch(var->get_kind()) {
          case var_expr::for_var:
          case var_expr::let_var:
            findSources(&*var->get_forlet_clause()->get_expr());
            break;

          case var_expr::context_var:
          case var_expr::param_var:
            m_sources.insert(var);
            break;

          default:
            break;
        }
      }
      break;

    default:
      findSourcesInChildren(e);
      break;
  }
}

void SourceFinder::findSourcesInChildren(expr *e)
{
  for(expr_iterator i = e->expr_begin(); !i.done(); ++i) {
    if (*i != NULL) {
      findSources(*i);
    }
  }
}

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
/* vim:set ts=2 sw=2: */
