#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/expression/expr.h"
#include "context/static_context.h"
#include "compiler/rewriter/tools/expr_tools.h"

namespace zorba {

RULE_REWRITE_PRE(EliminateUnusedLetVars)
{
  flwor_expr *flwor = dynamic_cast<flwor_expr *>(node);
  if (flwor != NULL) {
    flwor_expr::clause_list_t::iterator i = flwor->clause_begin();
    while(i != flwor->clause_end()) {
      flwor_expr::forletref_t ref = *i;
      forlet_clause::varref_t vref = ref->get_var();
      if (vref->get_kind() == var_expr::let_var && count_variable_uses(flwor, &*vref) == 0) {
        i = flwor->remove_forlet_clause(i);
      } else {
        ++i;
      }
    }
    if (flwor->forlet_count() == 0) {
      expr_t where = flwor->get_where();
      expr_t result = flwor->get_retval();
      if (where != NULL) {
        rchandle<if_expr> ite(new if_expr(where->get_loc()));
        ite->set_cond_expr(where);
        ite->set_then_expr(result);
        ite->set_else_expr(new fo_expr(where->get_loc(), LOOKUP_FN("fn", "concatenate", 0)));
        result = &*ite;
      }
      return result;
    }
  }
  return NULL;
}

RULE_REWRITE_POST(EliminateUnusedLetVars)
{
  return NULL;
}

}
/* vim:set ts=2 sw=2: */
