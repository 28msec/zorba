#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/expression/expr.h"
#include "context/static_context.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/rewriter/framework/rule_driver.h"
#include "types/typeops.h"
#include "types/casting.h"

#include <memory>

using namespace std;

namespace zorba {

#define MODIFY( expr ) do { modified = true; expr; } while (0)

  class SubstVars : public RewriteRule {
  protected:
    var_expr *var;
    expr *subst;
    std::string m_ruleName;

  public:
    SubstVars (var_expr *var_, expr *subst_) : var (var_), subst (subst_), m_ruleName("SubstVars") {}
    const std::string& getRuleName() const { return m_ruleName; }
    expr_t rewritePre(expr *node, RewriterContext& rCtx);
    expr_t rewritePost(expr *node, RewriterContext& rCtx);
  };

  RULE_REWRITE_PRE(SubstVars) {
    return (node == var) ? subst : NULL;
  }
  RULE_REWRITE_POST(SubstVars) {
    return NULL;
  }

  // Substitutes @p var with @p subst in @p root
  expr_t subst_vars (RewriterContext rCtx0, expr_t root, var_expr *var, expr *subst) {
    RewriterContext rCtx (rCtx0.getCompilerCB (), root);
    auto_ptr<Rewriter> rw (new SingletonRuleMajorDriverBase (RuleMajorDriver::rule_ptr_t (new SubstVars (var, subst))));
    rw->rewrite (rCtx);
#if 0  // debug substitutions
    cout << "After subst " << var << ":" << endl; rCtx.getRoot()->put (cout) << endl;
#endif
    return rCtx.getRoot ();
  }

  // Returns a set containing all variables (including positional) defined by a FLWOR
  void flwor_vars (flwor_expr *flwor, VarSetAnnVal &vars) {
    for (flwor_expr::clause_list_t::iterator i = flwor->clause_begin();
         i != flwor->clause_end(); i++) {
      flwor_expr::forletref_t ref = *i;
      vars.add (ref->get_var ());
      if (ref->get_pos_var () != NULL)
        vars.add (ref->get_pos_var ());
    }
  }

// is this variable used in the next FOR clause that executes more than once?
bool used_upto_first_repeated_clause (var_expr *v, flwor_expr *flwor, static_context *sctx) {
  for (flwor_expr::clause_list_t::iterator i = flwor->clause_begin (); i != flwor->clause_end (); i++) {
    flwor_expr::forletref_t ref = *i;
    if (count_variable_uses(ref->get_expr (), v, 1) == 1)
      return true;
    if (ref->get_type () == forlet_clause::for_clause
        && TypeOps::type_max_cnt (*ref->get_expr ()->return_type (sctx)) >= 2)
      return false;
  }
  return false;
}

#define WHERE flwor->get_where ()

RULE_REWRITE_PRE(EliminateUnusedLetVars)
{
  flwor_expr *flwor = dynamic_cast<flwor_expr *>(node);
  if (flwor == NULL) return NULL;

  VarSetAnnVal myvars;
  flwor_vars (flwor, myvars);

  // 'for $x in ... return $x'
  if (WHERE == NULL && flwor->forlet_count () == 1 && myvars.varset.size () == 1
      && flwor->orderspec_count () == 0
      && &*(flwor->get_retval ()) == &*((*flwor) [0]->get_var ()))
    return (*flwor) [0]->get_expr ();

  // 'for $x in ... return ... WHERE cond' when cond doesn't depend on FLWOR vars
  if (WHERE != NULL) {
    const var_ptr_set &free_vars = get_varset_annotation (WHERE, AnnotationKey::FREE_VARS);
    var_ptr_set diff;
    set_intersection (myvars.varset.begin (), myvars.varset.end (), free_vars.begin (), free_vars.end (), inserter (diff, diff.begin ()));
    if (diff.empty ()) {
      expr_t old_where = WHERE;
      flwor->set_where (NULL);
      return fix_if_annotations (new if_expr (LOC (node), old_where, flwor, new fo_expr (LOC (node), LOOKUP_OPN ("concatenate"))));
    }
  }

  bool modified = false;
  static_context *sctx = rCtx.getStaticContext();

  // FLWOR vars used once or zero times. substitutions
  for (flwor_expr::clause_list_t::iterator i = flwor->clause_begin();
        i != flwor->clause_end(); ) {
    flwor_expr::forletref_t ref = *i;
    expr *cexpr = ref->get_expr ();
    forlet_clause::varref_t vref = ref->get_var();
    bool is_let = vref->get_kind() == var_expr::let_var;
    int quant_cnt = 2;  // cardinality of for clause: 0, 1 or more
    forlet_clause::varref_t pvref = ref->get_pos_var ();
    if (pvref != NULL && count_variable_uses(flwor, &*pvref, 1) == 0)
      MODIFY (ref->set_pos_var (pvref = NULL));
    if (! is_let) {
      xqtref_t ctype = cexpr->return_type (sctx);
      quant_cnt = TypeOps::type_max_cnt (*ctype);
    }
    if (is_let || quant_cnt < 2) {
      if (quant_cnt == 0) return new fo_expr (LOC (node), LOOKUP_OPN ("concatenate"));
      // otherwise is_let || quant_cnt == 1
      if (pvref != NULL)
        MODIFY (subst_vars (rCtx, node, pvref.getp (), new const_expr (LOC (node), xqp_integer::parseInt (1))));
      int uses = count_variable_uses(flwor, &*vref, 2);
      if (uses > 1) {
        if (cexpr->get_expr_kind () == const_expr_kind) {
          subst_vars (rCtx, node, vref, cexpr);
          MODIFY (i = flwor->remove_forlet_clause (i));
        } else ++i;
      } else {
        if (uses == 1) {
          if (flwor->forlet_count () == 1 // TODO: if cardinality FLWOR result = 1...
              || cexpr->get_annotation (AnnotationKey::UNFOLDABLE_OP) != TSVAnnotationValue::TRUE_VAL
              || used_upto_first_repeated_clause (&*vref, flwor, sctx))
            {
              subst_vars (rCtx, node, vref, cexpr);
              MODIFY (i = flwor->remove_forlet_clause (i));
            }
          else ++i;
        } else {
          MODIFY (i = flwor->remove_forlet_clause(i));
        }
      }
    } else {
      ++i;
    }
  }

  // FLWOR with no remaining clauses
  if (flwor->forlet_count() == 0) {
    expr_t result = flwor->get_retval();
    if (WHERE != NULL)
      result = fix_if_annotations (new if_expr(LOC (WHERE), WHERE, result, new fo_expr(LOC (WHERE), LOOKUP_OPN("concatenate"))));
    return result;
  }
  return modified ? node : NULL;
}

RULE_REWRITE_POST(EliminateUnusedLetVars) {
  return NULL;
}


// Checks whether @p cond comes has the form '$pos_var = ($idx)'
// where $idx would be a proper sequence position.
static bool refactor_index_pred (RewriterContext& rCtx, expr_t cond, forlet_clause::varref_t &pvar, rchandle<const_expr> &pos_expr) {
  fo_expr *fo = cond.dyn_cast<fo_expr> ().getp ();
  if (fo == NULL) return false;
  const function *f = fo->get_func ();
  if (f != LOOKUP_OP2 ("equal") && f != LOOKUP_OP2 ("value-equal"))
    return false;

  int i;
  for (i = 0; i < 2; i++) {
    if (NULL != (pvar = (*fo) [i].dyn_cast<var_expr> ()) && pvar->get_kind() == var_expr::pos_var
        && NULL != (pos_expr = (*fo) [1 - i].dyn_cast<const_expr> ().getp ())) {
      store::Item_t val = pos_expr->get_val ();
      if (TypeOps::is_subtype (*rCtx.getStaticContext()->get_typemanager()->create_named_type (val->getType ()), *GENV_TYPESYSTEM.INTEGER_TYPE_ONE)
          && val->getIntegerValue () >= xqp_integer::parseInt (1)) 
      {
        pos_expr = new const_expr (LOC (pos_expr), GenericCast::instance ()->promote (val, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));
        return true;
      }
    }
  }
  return false;
}

RULE_REWRITE_PRE(RefactorPredFLWOR) {
  flwor_expr *flwor = dynamic_cast<flwor_expr *>(node);
  if (flwor == NULL) return NULL;

  static_context *sctx = rCtx.getStaticContext();
  if_expr *ite_result = flwor->get_retval().dyn_cast<if_expr> ();

  rchandle<const_expr> pos;
  forlet_clause::varref_t pvar;

  // 'for $x in ... return if (...) then ... else ()'
  if (ite_result != NULL && WHERE == NULL &&
      TypeOps::is_equal (*ite_result->get_else_expr ()->return_type (sctx), *GENV_TYPESYSTEM.EMPTY_TYPE))
  {
    expr_t cond = ite_result->get_cond_expr (),
      then = ite_result->get_then_expr ();
    flwor->set_retval (then);
    flwor->set_where (cond);
    return flwor;
  }
  
  // 'for $x at $p where $p = ... return ...'
  if (WHERE != NULL && refactor_index_pred (rCtx, WHERE, pvar, pos) && count_variable_uses (flwor, &*pvar, 2) <= 1) {
    rchandle<fo_expr> result = new fo_expr (LOC (WHERE), LOOKUP_FN ("fn", "subsequence", 3),
                                            pvar->get_forlet_clause ()->get_expr (), &*pos, new const_expr (LOC (pos), xqp_double::parseInt (1)));
    fix_annotations (&*result);
    forlet_clause *clause = pvar->get_forlet_clause ();
    clause->set_expr (&*result);
    clause->set_pos_var (NULL);
    flwor->set_where (NULL);
    return flwor;
  }

  return NULL;
}

RULE_REWRITE_POST(RefactorPredFLWOR) {
  return NULL;
}

#undef WHERE

}
/* vim:set ts=2 sw=2: */
