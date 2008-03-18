#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/expression/expr.h"
#include "context/static_context.h"
#include "compiler/rewriter/tools/expr_tools.h"

namespace zorba {

RULE_REWRITE_PRE(EliminateUnusedLetVars)
{
  static_context *sctx = rCtx.getStaticContext();
  TypeManager *ts = sctx->get_typemanager();
  flwor_expr *flwor = dynamic_cast<flwor_expr *>(node);
  if (flwor != NULL) {
    flwor_expr::clause_list_t::iterator i = flwor->clause_begin();
    while(i != flwor->clause_end()) {
      flwor_expr::forletref_t ref = *i;
      forlet_clause::varref_t vref = ref->get_var();
      bool is_let = vref->get_kind() == var_expr::let_var;
      int quant_cnt = 2;
      if (! is_let) {
        xqtref_t ctype = ref->get_expr ()->return_type (sctx);
        if (ts->is_equal (*ctype, *ts->create_empty_type ()))
          quant_cnt = 0;
        else if (ts->quantifier (*ctype) == TypeConstants::QUANT_ONE)
          quant_cnt = 1;
      }
      if (is_let || quant_cnt < 2) {
        if (quant_cnt == 0) return new fo_expr (node->get_loc (), LOOKUP_OPN ("concatenate"));
        int uses = count_variable_uses(flwor, &*vref);
        if (uses >= 1)  // TODO: substitute for uses == 1
          ++i;
        else
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
