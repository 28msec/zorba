#include "context/static_context.h"
#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/expression/expr.h"
#include "compiler/codegen/plan_visitor.h"
#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "types/casting.h"
#include "system/globalenv.h"

#include "runtime/util/plan_wrapper_holder.h"

#include "functions/function.h"
#include "functions/Misc.h"

#include "errors/error_messages.h"
#include "errors/errors.h"

using namespace std;

namespace zorba {

  static expr_t execute (CompilerCB* compilercb, expr_t node, vector<store::Item_t> &result) {
    PlanIter_t plan = codegen ("const-folded expr", node);
    QueryLoc loc = LOC (node);
    store::Item_t item;
    try {
      for (PlanWrapperHolder pw  (new PlanWrapper (plan, compilercb, NULL)); (item = pw->next ()) != NULL; )
        result.push_back (item);
      return NULL;
    } catch (error::ZorbaError& e) {
      ZorbaError::ErrorCode lErrorCode = (ZorbaError::ErrorCode) e.theErrorCode;
      QueryLoc loc = e.theQueryLocation;
      expr_t err_expr = new fo_expr (loc, LOOKUP_FN ("fn", "error", 2),
                                     new const_expr (loc, ITEM_FACTORY->createQName ("http://www.w3.org/2005/xqt-errors", "err",  error::ZorbaError::toString(lErrorCode).c_str ())),
                                     new const_expr (loc, e.theDescription));
      err_expr->put_annotation (AnnotationKey::UNFOLDABLE_OP, TSVAnnotationValue::TRUE_VAL);
      return err_expr;
    }
  }

  RULE_REWRITE_PRE(MarkFreeVars) {
    return NULL;
  }

  RULE_REWRITE_POST(MarkFreeVars) {
    VarSetAnnVal *freevars = new VarSetAnnVal;
    Annotation::value_ref_t new_ann = Annotation::value_ref_t (freevars);
    if (node->get_expr_kind () == var_expr_kind) {
      varref_t v = dynamic_cast<var_expr *> (node);
      freevars->add (v);
    } else {
      for(expr_iterator i = node->expr_begin(); ! i.done(); ++i) {
        expr *e = *i;
        const var_ptr_set &kfv = get_varset_annotation (e, AnnotationKey::FREE_VARS);
        copy (kfv.begin (), kfv.end (), inserter (freevars->varset, freevars->varset.begin ()));
      }
      if (node->get_expr_kind () == flwor_expr_kind) {
        flwor_expr *flwor = dynamic_cast<flwor_expr *> (node);
        for (flwor_expr::clause_list_t::iterator i = flwor->clause_begin (); i != flwor->clause_end (); i++) {
          flwor_expr::forletref_t clause = *i;
          freevars->varset.erase (clause->get_var ());
          if (clause->get_pos_var () != NULL)
            freevars->varset.erase (clause->get_pos_var ());
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
      node->put_annotation (k, TSVAnnotationValue::TRUE_VAL);
      break;
    default:
      for(expr_iterator i = node->expr_begin(); ! i.done(); ++i) {
        if ((*i)->get_annotation (k) == TSVAnnotationValue::TRUE_VAL) {
          node->put_annotation (k, TSVAnnotationValue::TRUE_VAL);
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
    case fo_expr_kind: {
      const function *f = dynamic_cast<fo_expr *> (node)->get_func ();
      if (f->requires_dyn_ctx () || dynamic_cast<const fn_error *> (f) != NULL)
        node->put_annotation (k, TSVAnnotationValue::TRUE_VAL);
      break;
    }
    case elem_expr_kind:
    case attr_expr_kind:
    case text_expr_kind:
    case pi_expr_kind:
    case doc_expr_kind:
      node->put_annotation (k, TSVAnnotationValue::TRUE_VAL);
      break;
    default: break;
    }

    if (node->get_annotation (k) != TSVAnnotationValue::TRUE_VAL)
      for(expr_iterator i = node->expr_begin(); ! i.done(); ++i) {
        if ((*i)->get_annotation (k) == TSVAnnotationValue::TRUE_VAL) {
          node->put_annotation (k, TSVAnnotationValue::TRUE_VAL);
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

  inline bool standalone_expr (expr_t e) {
    expr_kind_t k = e->get_expr_kind ();
    return k != match_expr_kind && k != axis_step_expr_kind;
  }

  RULE_REWRITE_PRE(FoldConst) {
    xqtref_t rtype = node->return_type (rCtx.getStaticContext ());

    if (standalone_expr (node) &&
        ! already_folded (node, rCtx) && get_varset_annotation (node, AnnotationKey::FREE_VARS).empty ()
        && node->get_annotation (AnnotationKey::UNFOLDABLE_OP) != TSVAnnotationValue::TRUE_VAL
        && TypeOps::type_max_cnt (*rtype) <= 1
        && (fold_expensive_ops ||
            node->get_annotation (AnnotationKey::EXPENSIVE_OP) != TSVAnnotationValue::TRUE_VAL))
    {
      vector<store::Item_t> result;
      expr_t folded = execute (rCtx.getCompilerCB(), node, result);
      if (folded == NULL) {
        ZORBA_ASSERT (result.size () <= 1);
        folded =
          result.size () == 1
          ? ((expr *) (new const_expr (LOC (node), result [0])))
          : ((expr *) (new fo_expr (LOC (node), LOOKUP_OPN ("concatenate"))));
      }
      return folded;
    }
    return NULL;
  }
  
  RULE_REWRITE_POST(FoldConst) {
    return NULL;
  }

  static expr_t partial_eval_logic (fo_expr *fo, bool shortcircuit_val) {
    expr_t nontrivial1, nontrivial2;
    for (vector<expr_t>::iterator i = fo->begin (); i != fo->end (); i++) {
      const_expr *cond = i->dyn_cast<const_expr> ().getp ();
      if (cond != NULL) {
        if (cond->get_val ()->getEBV ()->getBooleanValue () == shortcircuit_val)
          return new const_expr (LOC (fo), (xqp_boolean) shortcircuit_val);
      } else {
        if (nontrivial1 == NULL)
          nontrivial1 = *i;
        else
          nontrivial2 = *i;
      }
    }
    if (nontrivial1 == NULL)
      return new const_expr (LOC (fo), (xqp_boolean) ! shortcircuit_val);
    else if (nontrivial2 == NULL)
      return fix_annotations (new fo_expr (LOC (fo), LOOKUP_FN("fn", "boolean", 1), nontrivial1));
    else
      return NULL;
  }

  static expr_t partial_eval_eq (RewriterContext& rCtx, fo_expr &fo) {
    int i;
    fo_expr *count_expr = NULL;
    const_expr *val_expr = NULL;
    const function *fn_count = LOOKUP_FN ("fn", "count", 1);

    for (i = 0; i < 2; i++) {
      if (NULL != (val_expr = fo [i].dyn_cast<const_expr> ().getp ())
          && NULL != (count_expr = fo [1-i].dyn_cast<fo_expr> ().getp())
          && count_expr->get_func () == fn_count)
        break;
    }
    if (i == 2) return NULL;

    store::Item_t val = val_expr->get_val ();
    if (TypeOps::is_subtype (*rCtx.getStaticContext()->get_typemanager()->create_named_type (val->getType ()), *GENV_TYPESYSTEM.INTEGER_TYPE_ONE)) {
      xqp_integer ival = val->getIntegerValue (), zero = xqp_integer::parseInt (0);
      if (ival < zero)
        return new const_expr (LOC (val_expr), false);
      else if (ival == zero)
        return fix_annotations (new fo_expr (fo.get_loc (), LOOKUP_FN ("fn", "empty", 1), (*count_expr) [0]));
      else if (ival == xqp_integer::parseInt (1))
        return fix_annotations (new fo_expr (fo.get_loc (), LOOKUP_OP1 ("exactly-one-noraise"), (*count_expr) [0]));
      else {
        expr_t dpos = new const_expr (LOC (val_expr), GenericCast::instance ()->promote (val, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));
        expr_t subseq_expr = fix_annotations (new fo_expr (LOC (count_expr), LOOKUP_FN ("fn", "subsequence", 3), (*count_expr) [0], dpos, new const_expr (LOC (val_expr), xqp_double::parseInt (2))));
        return fix_annotations (new fo_expr (fo.get_loc (), LOOKUP_OP1 ("exactly-one-noraise"), subseq_expr));
      }
    }

    return NULL;
  }

  static expr_t partial_eval_fo (RewriterContext& rCtx, fo_expr *fo) {
    const function *f = fo->get_func ();
    if (f == LOOKUP_OPN ("or"))
      return partial_eval_logic (fo, true);
    else if (f == LOOKUP_OPN ("and"))
      return partial_eval_logic (fo, false);
    else if (f == LOOKUP_OP2 ("value-equal") || f == LOOKUP_OP2 ("equal"))
      return partial_eval_eq (rCtx, *fo);
    else if (f == LOOKUP_FN ("fn", "count", 1)) {
      int type_cnt = TypeOps::type_cnt (*(*fo) [0]->return_type (rCtx.getStaticContext()));
      if (type_cnt != -1)
        return new const_expr (fo->get_loc (), Integer::parseInt (type_cnt));
      else
        return NULL;
    }
    return NULL;
  }

  RULE_REWRITE_PRE(PartialEval) {
    castable_base_expr *cbe;
    if ((cbe = dynamic_cast<castable_base_expr *>(node)) != NULL) {
      expr_t arg = cbe->get_input();
      xqtref_t arg_type = arg->return_type(rCtx.getStaticContext());
      if (TypeOps::is_subtype(*arg_type, *cbe->get_target_type()))
        return new const_expr (LOC (node), true);
      else if (node->get_expr_kind () == instanceof_expr_kind)
        return TypeOps::intersect_type (*arg_type, *cbe->get_target_type ()) == GENV_TYPESYSTEM.NONE_TYPE 
          ? new const_expr (LOC (node), false) : NULL;
      else
        return NULL;
    }

    switch (node->get_expr_kind ()) {

    case if_expr_kind: {
      if_expr *ite = dynamic_cast<if_expr *> (node);
      const_expr *cond = ite->get_cond_expr ().dyn_cast<const_expr> ().getp ();
      if (cond != NULL) {
        return cond->get_val ()->getBooleanValue () ? ite->get_then_expr () : ite->get_else_expr ();
      }
      break;
    }

    case fo_expr_kind:
      return partial_eval_fo (rCtx, dynamic_cast<fo_expr *> (node));

    default: break;
    }

    return NULL;
  }

  RULE_REWRITE_POST(PartialEval) {
    return NULL;
  }

}
