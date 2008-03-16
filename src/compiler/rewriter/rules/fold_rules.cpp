#include "compiler/rewriter/rules/ruleset.h"
#include "context/static_context.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/expression/expr.h"
#include "compiler/codegen/plan_visitor.h"
#include "types/root_typemanager.h"
#include "types/typemanager.h"
#include "system/globalenv.h"
#include "runtime/base/plan_wrapper.h"
#include "functions/function.h"

#include <set>

using namespace std;

namespace zorba {

  typedef rchandle<var_expr> varref_t;

  class FreeVarAnnVal : public AnnotationValue {
  public:
    set<var_expr *> varset;
    void add (var_expr *v) { varset.insert (varset.begin (), v); }
  };
  
  inline set<var_expr *> &get_freevars (const expr *e) {
    assert (e != NULL);
    Annotation::value_ref_t ann = e->get_annotation (AnnotationKey::FREE_VARS);
    ZORBA_ASSERT (ann != NULL);
    return dynamic_cast<FreeVarAnnVal *> (ann.get ())->varset;
  }

  static void execute (expr_t node, vector<store::Item_t> &result) {
    PlanIter_t plan = codegen ("const-folded expr", node);
    rchandle<PlanWrapper> pw  = new PlanWrapper (plan);
    store::Item_t item;
    for (pw->open (); (item = pw->next ()) != NULL; )
      result.push_back (item);
  }

  RULE_REWRITE_PRE(MarkFreeVars) {
    return NULL;
  }

  RULE_REWRITE_POST(MarkFreeVars) {
    FreeVarAnnVal *freevars = new FreeVarAnnVal;
    Annotation::value_ref_t new_ann = Annotation::value_ref_t (freevars);
    if (node->get_expr_kind () == var_expr_kind) {
      varref_t v = dynamic_cast<var_expr *> (node);
      freevars->add (v);
    } else {
      for(expr_iterator i = node->expr_begin(); ! i.done(); ++i) {
        expr *e = *i;
        set<var_expr *> &kfv = get_freevars (e);
        copy (kfv.begin (), kfv.end (), inserter (freevars->varset, freevars->varset.begin ()));
      }
      if (node->get_expr_kind () == flwor_expr_kind) {
        flwor_expr *flwor = dynamic_cast<flwor_expr *> (node);
        for (flwor_expr::clause_list_t::iterator i = flwor->clause_begin (); i != flwor->clause_end (); i++) {
          flwor_expr::forletref_t clause = *i;
          freevars->varset.erase (clause->get_var ());
        }
      }
    }
    node->put_annotation (AnnotationKey::FREE_VARS, new_ann);
    return NULL;
  }

  RULE_REWRITE_PRE(MarkExpensiveOps) {
    return NULL;
  }

  RULE_REWRITE_POST(MarkExpensiveOps) {
    Annotation::key_t k = AnnotationKey::EXPENSIVE_OP;
    switch (node->get_expr_kind ()) {
    case flwor_expr_kind:
    case relpath_expr_kind:
      node->put_annotation (k, TSVAnnotationValue::TRUE_VALUE);
      break;
    default:
      for(expr_iterator i = node->expr_begin(); ! i.done(); ++i) {
        if ((*i)->get_annotation (k) == TSVAnnotationValue::TRUE_VALUE) {
          node->put_annotation (k, TSVAnnotationValue::TRUE_VALUE);
          break;
        }
      }
    }
    return NULL;
  }

  inline bool already_folded (expr_t e, RewriterContext& rCtx) {
    if (e->get_expr_kind () == const_expr_kind)
      return true;
    if (e->get_expr_kind () != fo_expr_kind)
      return false;
    const fo_expr *fo = e.dyn_cast<fo_expr> ().getp ();
    return fo->get_func () == LOOKUP_OPN ("concatenate") && fo->size () == 0;
  }

  RULE_REWRITE_PRE(FoldConst) {
    // For now only expression with an atomic return type are folded.
    // TODO: never fold constructors!

    TypeManager *ts = rCtx.getStaticContext()->get_typemanager();
    xqtref_t rtype = node->return_type (rCtx.getStaticContext ());
    TypeConstants::quantifier_t rquant = ts->quantifier (*rtype);

    if (! already_folded (node, rCtx) && get_freevars (node).empty ()
        && (rquant == TypeConstants::QUANT_ONE || rquant == TypeConstants::QUANT_QUESTION
            || ts->is_equal (*rtype, *GENV_TYPESYSTEM.EMPTY_TYPE))
        && (fold_expensive_ops || 
            node->get_annotation (AnnotationKey::EXPENSIVE_OP) != TSVAnnotationValue::TRUE_VALUE)
        && (node->get_expr_kind () != fo_expr_kind
            || ! dynamic_cast<fo_expr *> (node)->get_func ()->requires_dyn_ctx ()))
        
    {
      vector<store::Item_t> result;
      execute (node, result);
      ZORBA_ASSERT (result.size () <= 1);
      expr_t folded =
        result.size () == 1
        ? ((expr *) (new const_expr (node->get_loc (), result [0])))
        : ((expr *) (new fo_expr (node->get_loc (), LOOKUP_OPN ("concatenate"))));
      folded->put_annotation (AnnotationKey::FREE_VARS, Annotation::value_ref_t (new FreeVarAnnVal));
      return folded;
    }
    return NULL;
  }

  RULE_REWRITE_POST(FoldConst) {
    return NULL;
  }

}
