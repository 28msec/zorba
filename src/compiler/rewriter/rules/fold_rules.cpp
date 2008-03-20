#include "compiler/rewriter/rules/ruleset.h"
#include "context/static_context.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/expression/expr.h"
#include "compiler/codegen/plan_visitor.h"
#include "types/root_typemanager.h"
#include "types/typemanager.h"
#include "system/globalenv.h"
#include "runtime/api/plan_wrapper.h"
#include "functions/function.h"
#include "errors/error_messages.h"

#include "errors/errors.h"

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
    PlanWrapperHolder (PlanIter_t plan, CompilerCB* compilercb) : pw (new PlanWrapper (plan, compilercb, 0))
    { pw->open (); }
    ~PlanWrapperHolder() { pw->close (); }
    PlanWrapper *operator-> () { return pw.get(); }
  };

  static expr_t execute (CompilerCB* compilercb, expr_t node, vector<store::Item_t> &result) {
    PlanIter_t plan = codegen ("const-folded expr", node);
    QueryLoc loc = node->get_loc ();
    store::Item_t item;
    try {
      for (PlanWrapperHolder pw  (plan, compilercb); (item = pw->next ()) != NULL; )
        result.push_back (item);
      return NULL;
    } catch (error::ZorbaError& e) {
      ZorbaError::ErrorCode lErrorCode = (ZorbaError::ErrorCode) e.theErrorCode;
      expr_t err_expr = new fo_expr (loc, LOOKUP_FN ("fn", "error", 1), 
                                     new const_expr (loc, ITEM_FACTORY->createQName ("http://www.w3.org/2005/xqt-errors", "err",  error::ZorbaError::toString(lErrorCode).c_str ())));
      err_expr->put_annotation (AnnotationKey::UNFOLDABLE_OP, TSVAnnotationValue::TRUE_VALUE);
      return err_expr;
    }
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
      expr_t folded = execute (rCtx.getCompilerCB(), node, result);
      if (folded == NULL) {
        ZORBA_ASSERT (result.size () <= 1);
        folded =
          result.size () == 1
          ? ((expr *) (new const_expr (node->get_loc (), result [0])))
          : ((expr *) (new fo_expr (node->get_loc (), LOOKUP_OPN ("concatenate"))));
      }
      return folded;
    }
    return NULL;
  }

  RULE_REWRITE_POST(FoldConst) {
    return NULL;
  }

  RULE_REWRITE_PRE(PartialEval) {
    TypeManager *ts = rCtx.getStaticContext()->get_typemanager();

    castable_base_expr *cbe;
    if ((cbe = dynamic_cast<castable_base_expr *>(node)) != NULL) {
      expr_t arg = cbe->get_expr();
      xqtref_t arg_type = arg->return_type(rCtx.getStaticContext());
      if (ts->is_subtype(*arg_type, *cbe->get_type()))
        return new const_expr (node->get_loc (), true);
      else if (node->get_expr_kind () == instanceof_expr_kind)
        return ts->intersect_type (*arg_type, *cbe->get_type ()) == GENV_TYPESYSTEM.NONE_TYPE 
          ? new const_expr (node->get_loc (), false) : NULL;
      else
        return NULL;
    }

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
        expr_t nontrivial1, nontrivial2;
        for (vector<expr_t>::iterator i = fo->begin (); i != fo->end (); i++) {
          const_expr *cond = i->dyn_cast<const_expr> ().getp ();
          if (cond != NULL) {
            if (cond->get_val ()->getEBV ()->getBooleanValue ())
              return new const_expr (node->get_loc (), (xqp_boolean) true);
          } else {
            if (nontrivial1 == NULL)
              nontrivial1 = *i;
            else
              nontrivial2 = *i;
          }
        }
        if (nontrivial1 == NULL)
          return new const_expr (node->get_loc (), (xqp_boolean) false);
        else if (nontrivial2 == NULL)
          return new fo_expr (node->get_loc (), LOOKUP_FN("fn", "boolean", 1), nontrivial1);
        else
          return NULL;
      } else if (f == LOOKUP_OPN ("and")) {
        // TODO: eliminate "true() and ..." as for "or" above
        for (vector<expr_t>::iterator i = fo->begin (); i != fo->end (); i++) {
          const_expr *cond = i->dyn_cast<const_expr> ().getp ();
          if (cond != NULL && ! cond->get_val ()->getEBV ()->getBooleanValue ())
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
