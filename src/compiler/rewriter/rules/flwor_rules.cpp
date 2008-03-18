#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/expression/expr.h"
#include "context/static_context.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/rewriter/framework/rule_driver.h"

#include <memory>

using namespace std;

namespace zorba {

  class SubstVars : public RewriteRule {
  protected:
    var_expr *var;
    expr *subst;

  public:
    SubstVars (var_expr *var_, expr *subst_) : var (var_), subst (subst_) {}
    expr_t rewritePre(expr *node, RewriterContext& rCtx);
    expr_t rewritePost(expr *node, RewriterContext& rCtx);
  };

  RULE_REWRITE_PRE(SubstVars) {
    return (node == var) ? subst : NULL;
  }
  RULE_REWRITE_POST(SubstVars) {
    return NULL;
  }

  expr_t subst_vars (RewriterContext& rCtx, var_expr *var, expr *subst) {
    auto_ptr<Rewriter> rw (new SingletonRuleMajorDriverBase (RuleMajorDriver::rule_ptr_t (new SubstVars (var, subst))));
    rw->rewrite (rCtx);
    return rCtx.getRoot ();
  }

RULE_REWRITE_PRE(EliminateUnusedLetVars)
{
  static_context *sctx = rCtx.getStaticContext();
  TypeManager *ts = sctx->get_typemanager();
  flwor_expr *flwor = dynamic_cast<flwor_expr *>(node);
  if (flwor != NULL) {
    flwor_expr::clause_list_t::iterator i = flwor->clause_begin();
    while(i != flwor->clause_end()) {
      flwor_expr::forletref_t ref = *i;
      expr *cexpr = ref->get_expr ();
      forlet_clause::varref_t vref = ref->get_var();
      bool is_let = vref->get_kind() == var_expr::let_var;
      int quant_cnt = 2;  // cardinality of for clause: 0, 1 or more
      if (! is_let) {
        xqtref_t ctype = cexpr->return_type (sctx);
        if (ts->is_equal (*ctype, *ts->create_empty_type ()))
          quant_cnt = 0;
        else if (ts->quantifier (*ctype) == TypeConstants::QUANT_ONE)
          quant_cnt = 1;
      }
      if (is_let || quant_cnt < 2) {
        if (quant_cnt == 0) return new fo_expr (node->get_loc (), LOOKUP_OPN ("concatenate"));
        // otherwise is_let || quant_cnt == 1
        forlet_clause::varref_t pvref = ref->get_pos_var ();
        if (pvref != NULL)
          subst_vars (rCtx, pvref.getp (), new const_expr (node->get_loc (), xqp_integer::parseInt (1)));
        int uses = count_variable_uses(flwor, &*vref);
        if (uses > 1)
          ++i;
        else {
          if (uses == 1) {
            if (flwor->forlet_count () == 1 // TODO: if cardinality FLWOR result = 1...
                || cexpr->get_annotation (AnnotationKey::UNFOLDABLE_OP) != TSVAnnotationValue::TRUE_VALUE) 
            {
              
              i = flwor->remove_forlet_clause (i);
              subst_vars (rCtx, vref, cexpr);
            }
            else ++i;
          } else {
            i = flwor->remove_forlet_clause(i);
          }
        }
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
