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

  set<var_expr *> no_free_vars;

  class FreeVarAnnVal : public AnnotationValue {
  public:
    set<var_expr *> varset;
    void add (var_expr *v) { varset.insert (varset.begin (), v); }
  };
  
  inline const set<var_expr *> &get_freevars (const expr *e) {
    assert (e != NULL);
    Annotation::value_ref_t ann = e->get_annotation (AnnotationKey::FREE_VARS);
    return (ann == NULL) ? no_free_vars : dynamic_cast<FreeVarAnnVal *> (ann.get ())->varset;
  }

  class PlanWrapperHolder {
    auto_ptr<PlanWrapper> pw;

  public:
    PlanWrapperHolder (PlanIter_t plan) : pw (new PlanWrapper (plan))
    { pw->open (); }
    ~PlanWrapperHolder() { pw->close (); }
    PlanWrapper *operator-> () { return pw.get(); }
  };

  static void execute (expr_t node, vector<store::Item_t> &result) {
    PlanIter_t plan = codegen ("const-folded expr", node);
    store::Item_t item;
    for (PlanWrapperHolder pw  (plan); (item = pw->next ()) != NULL; )
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
        const set<var_expr *> &kfv = get_freevars (e);
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

  RULE_REWRITE_PRE(MarkUnfoldableOps) {
    return NULL;
  }

  RULE_REWRITE_POST(MarkUnfoldableOps) {
    Annotation::key_t k = AnnotationKey::UNFOLDABLE_OP;
    switch (node->get_expr_kind ()) {
    case fo_expr_kind:
      if (dynamic_cast<fo_expr *> (node)->get_func ()->requires_dyn_ctx ())
        node->put_annotation (k, TSVAnnotationValue::TRUE_VALUE);
      break;
    case elem_expr_kind:
    case attr_expr_kind:
    case text_expr_kind:
    case pi_expr_kind:
    case doc_expr_kind:
      node->put_annotation (k, TSVAnnotationValue::TRUE_VALUE);
      break;
    default: break;
    }

    if (node->get_annotation (k) != TSVAnnotationValue::TRUE_VALUE)
      for(expr_iterator i = node->expr_begin(); ! i.done(); ++i) {
        if ((*i)->get_annotation (k) == TSVAnnotationValue::TRUE_VALUE) {
          node->put_annotation (k, TSVAnnotationValue::TRUE_VALUE);
          break;
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
    TypeManager *ts = rCtx.getStaticContext()->get_typemanager();
    xqtref_t rtype = node->return_type (rCtx.getStaticContext ());
    TypeConstants::quantifier_t rquant = ts->quantifier (*rtype);

    if (! already_folded (node, rCtx) && get_freevars (node).empty ()
        && node->get_annotation (AnnotationKey::UNFOLDABLE_OP) != TSVAnnotationValue::TRUE_VALUE
        && (rquant == TypeConstants::QUANT_ONE || rquant == TypeConstants::QUANT_QUESTION
            || ts->is_equal (*rtype, *GENV_TYPESYSTEM.EMPTY_TYPE))
        && (fold_expensive_ops || 
            node->get_annotation (AnnotationKey::EXPENSIVE_OP) != TSVAnnotationValue::TRUE_VALUE))
    {
      vector<store::Item_t> result;
      execute (node, result);
      ZORBA_ASSERT (result.size () <= 1);
      expr_t folded =
        result.size () == 1
        ? ((expr *) (new const_expr (node->get_loc (), result [0])))
        : ((expr *) (new fo_expr (node->get_loc (), LOOKUP_OPN ("concatenate"))));
      return folded;
    }
    return NULL;
  }

  RULE_REWRITE_POST(FoldConst) {
    return NULL;
  }

  RULE_REWRITE_PRE(PartialEval) {
    switch (node->get_expr_kind ()) {
    case if_expr_kind: {
      if_expr *ite = dynamic_cast<if_expr *> (node);
      const_expr *cond = ite->get_cond_expr ().dyn_cast<const_expr> ().getp ();
      if (cond != NULL)
        return cond->get_val ()->getBooleanValue () ? ite->get_then_expr () : ite->get_else_expr ();
    }
      break;
    case fo_expr_kind: {
      fo_expr *fo = dynamic_cast<fo_expr *> (node);
      const function *f = fo->get_func ();
      if (f == LOOKUP_OPN ("or")) {
        for (vector<expr_t>::iterator i = fo->begin (); i != fo->end (); i++) {
          const_expr *cond = i->dyn_cast<const_expr> ().getp ();
          if (cond != NULL && cond->get_val ()->getBooleanValue ())
            return new const_expr (node->get_loc (), (xqp_boolean) true);
        }
      } else if (f == LOOKUP_OPN ("and")) {
        for (vector<expr_t>::iterator i = fo->begin (); i != fo->end (); i++) {
          const_expr *cond = i->dyn_cast<const_expr> ().getp ();
          if (cond != NULL && ! cond->get_val ()->getBooleanValue ())
            return new const_expr (node->get_loc (), (xqp_boolean) false);
        }
      }
    }
      break;
    default: break;
    }

    return NULL;
  }

  RULE_REWRITE_POST(PartialEval) {
    return NULL;
  }

}
