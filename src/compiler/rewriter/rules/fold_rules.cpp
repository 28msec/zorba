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
#include "functions/Boolean.h"
#include "functions/arithmetic.h"

#include "zorbaerrors/error_messages.h"
#include "zorbaerrors/errors.h"

#include "store/api/store.h"
#include "store/api/item_factory.h"

using namespace std;

namespace zorba {

static void remove_wincond_vars(const flwor_wincond*, VarSetAnnVal*);

static bool maybe_needs_implicit_timezone (const fo_expr*, static_context*);

static bool standalone_expr (expr_t);

static bool already_folded (expr_t, RewriterContext&);

static expr_t partial_eval_fo (RewriterContext&, fo_expr*);

static expr_t partial_eval_logic(fo_expr*, bool, RewriterContext&);

static expr_t partial_eval_eq (RewriterContext&, fo_expr&);


/*******************************************************************************

********************************************************************************/
static expr_t execute (
    CompilerCB* compilercb,
    expr_t node,
    vector<store::Item_t> &result) 
{
  PlanIter_t plan = codegen ("const-folded expr", node, compilercb);
  QueryLoc loc = LOC (node);
  store::Item_t item;
  try 
  {
    for (PlanWrapperHolder pw (new PlanWrapper (plan, compilercb, NULL)); ; ) {
      if (!pw->next(item)) {
        break;
      }
      result.push_back (item);
    }
    return NULL;
  }
  catch (error::ZorbaError& e) 
  {
    XQUERY_ERROR lErrorCode = e.theErrorCode;
    QueryLoc loc;
    loc.setLineBegin(e.theQueryLine);
    loc.setColumnBegin(e.theQueryColumn);
    store::Item_t qname;
    ITEM_FACTORY->createQName (qname, "http://www.w3.org/2005/xqt-errors", "err",  error::ZorbaError::toString(lErrorCode).c_str ());
    expr_t err_expr = new fo_expr (loc, LOOKUP_FN ("fn", "error", 2),
                                   new const_expr (loc, qname),
                                   new const_expr (loc, e.theDescription));
    err_expr->put_annotation (AnnotationKey::UNFOLDABLE_OP, TSVAnnotationValue::TRUE_VAL);
    err_expr->put_annotation (AnnotationKey::NONDISCARDABLE_EXPR, TSVAnnotationValue::TRUE_VAL);
    return err_expr;
  }
}


/*******************************************************************************
  If any of the subexprs of the given expr E has the given annotation k, then
  set the k annotation on E as well. 
********************************************************************************/
void propagate_any_child_up (expr *node, Annotation::key_t k) 
{
  for(expr_iterator i = node->expr_begin(); ! i.done(); ++i) {
    if ((*i)->get_annotation (k).getp() == TSVAnnotationValue::TRUE_VAL.getp()) {
      node->put_annotation (k, TSVAnnotationValue::TRUE_VAL);
      break;
    }
  }
}


/*******************************************************************************
  For each expr E, collect all the variables that are referenced directly by E
  and its subexpressions.
********************************************************************************/

RULE_REWRITE_PRE(MarkFreeVars) 
{
  return NULL;
}

RULE_REWRITE_POST(MarkFreeVars) 
{
  VarSetAnnVal *freevars = new VarSetAnnVal;
  Annotation::value_ref_t new_ann = Annotation::value_ref_t (freevars);
  
  if (node->get_expr_kind () == var_expr_kind) 
  {
    varref_t v = dynamic_cast<var_expr *> (node);
    freevars->add (v);
  }
  else 
  {
    for(expr_iterator i = node->expr_begin(); ! i.done(); ++i) 
    {
      expr *e = *i;
      const var_ptr_set &kfv = get_varset_annotation (e, AnnotationKey::FREE_VARS);
      copy (kfv.begin(), kfv.end(), inserter(freevars->varset, freevars->varset.begin()));
    }

    if (node->get_expr_kind () == flwor_expr_kind ||
        node->get_expr_kind () == gflwor_expr_kind) 
    {
      flwor_expr* flwor = dynamic_cast<flwor_expr *> (node);
      for (flwor_expr::clause_list_t::const_iterator i = flwor->clause_begin();
           i != flwor->clause_end();
           ++i)
      {
        const flwor_clause* c = *i;

        if (c->get_kind() == flwor_clause::for_clause)
        {
          const for_clause* fc = static_cast<const for_clause *>(c);

          freevars->varset.erase(fc->get_var());
          if (fc->get_pos_var() != NULL)
            freevars->varset.erase(fc->get_pos_var());
        }
        else if (c->get_kind() == flwor_clause::let_clause)
        {
          const let_clause* lc = static_cast<const let_clause *>(c);

          freevars->varset.erase(lc->get_var());
        }
        else if (c->get_kind() == flwor_clause::window_clause)
        {
          const window_clause* wc = static_cast<const window_clause *>(c);

          freevars->varset.erase(wc->get_var());

          flwor_wincond* startCond = wc->get_win_start();
          flwor_wincond* stopCond = wc->get_win_stop();

          if (startCond != NULL)
            remove_wincond_vars(startCond, freevars);

          if (stopCond != NULL)
            remove_wincond_vars(stopCond, freevars);
        }
        else if (c->get_kind() == flwor_clause::group_clause)
        {
          const group_clause* gc = static_cast<const group_clause *>(c);

          const flwor_clause::rebind_list_t& gvars = gc->get_grouping_vars();
          unsigned numGroupVars = gvars.size();

          for (unsigned i = 0; i < numGroupVars; ++i)
          {
            freevars->varset.erase(gvars[i].second.getp());
          }

          const flwor_clause::rebind_list_t& ngvars = gc->get_nongrouping_vars();
          unsigned numNonGroupVars = ngvars.size();
        
          for (unsigned i = 0; i < numNonGroupVars; ++i)
          {
            freevars->varset.erase(ngvars[i].second.getp());
          }
        }
        else if (c->get_kind() == flwor_clause::count_clause)
        {
          const count_clause* cc = static_cast<const count_clause *>(c);

          freevars->varset.erase(cc->get_var());
        }
      }
    }
  }

  node->put_annotation (AnnotationKey::FREE_VARS, new_ann);
  return NULL;
}


static void remove_wincond_vars(
    const flwor_wincond* cond,
    VarSetAnnVal* freevars)
{
  const flwor_wincond::vars& inVars = cond->get_in_vars();
  const flwor_wincond::vars& outVars = cond->get_out_vars();

  freevars->varset.erase(inVars.posvar.getp());
  freevars->varset.erase(inVars.curr.getp());
  freevars->varset.erase(inVars.prev.getp());
  freevars->varset.erase(inVars.next.getp());

  freevars->varset.erase(outVars.posvar.getp());
  freevars->varset.erase(outVars.curr.getp());
  freevars->varset.erase(outVars.prev.getp());
  freevars->varset.erase(outVars.next.getp());
}


/*******************************************************************************
  Mark expensive exprs (flwor expr, path expr, and any exprs referencing other
  expensive exprs).
********************************************************************************/

RULE_REWRITE_PRE(MarkExpensiveOps) 
{
  return NULL;
}
  

RULE_REWRITE_POST(MarkExpensiveOps) 
{
  Annotation::key_t k = AnnotationKey::EXPENSIVE_OP;
  switch (node->get_expr_kind ()) {
  case flwor_expr_kind:
  case gflwor_expr_kind:
  case relpath_expr_kind:
    node->put_annotation (k, TSVAnnotationValue::TRUE_VAL);
    break;
  default:
    propagate_any_child_up (node, k);
  }
  return NULL;
}


/*******************************************************************************
  Mark the exprs that should not be folded
********************************************************************************/

RULE_REWRITE_PRE(MarkUnfoldableExprs) 
{
  return NULL;
}


RULE_REWRITE_POST(MarkUnfoldableExprs) 
{
  Annotation::key_t k = AnnotationKey::UNFOLDABLE_OP;
  switch (node->get_expr_kind ()) 
  {
  case fo_expr_kind: {
    fo_expr *fo = static_cast<fo_expr *> (node);
    const function *f = fo->get_func ();

    // Do not fold functions that always require access to the dynamic context,
    // or may need to access the implicit timezone (which is also in the dynamic
    // constext). 
    if (f->requires_dyn_ctx () || dynamic_cast<const fn_error *> (f) != NULL
        || maybe_needs_implicit_timezone (fo, rCtx.getStaticContext ())
        || !f->isPureFunction())
      node->put_annotation (k, TSVAnnotationValue::TRUE_VAL);
    break;
  }
      
  case var_expr_kind:
    if (static_cast<var_expr *> (node)->get_kind () == var_expr::context_var)
      node->put_annotation (k, TSVAnnotationValue::TRUE_VAL);
    break;

  // Exit and flow-control exprs do more than just computing a result which is
  // consumed by their parent expr. So, they cannot be folded.
  case exit_expr_kind:
  case flowctl_expr_kind:

  // Node constructors are unfoldable because if a node constructor is inside
  // a loop, then it will create a different xml tree every time it is invoked,
  // even if the constructor itself is "constant" (i.e. does not reference any
  // varialbes)
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
    propagate_any_child_up (node, k);

  return NULL;
}


static bool maybe_needs_implicit_timezone (const fo_expr *fo, static_context *sctx) 
{
  const function *f = fo->get_func ();
  xqtref_t type0 = (fo->size() > 0 ? (*fo)[0]->return_type (sctx) : NULL);
  xqtref_t type1 = (fo->size() > 1 ? (*fo)[1]->return_type (sctx) : NULL);

  return ( ((f->isComparisonFunction() || dynamic_cast<const op_subtract *> (f) != NULL)
            &&
            (TypeOps::maybe_date_time (*type0) || TypeOps::maybe_date_time (*type1)))
           || ((f == LOOKUP_FN ("fn", "distinct-values", 1) ||
                f == LOOKUP_FN ("fn", "distinct-values", 2) ||
                f == LOOKUP_FN ("fn", "min", 1) ||
                f == LOOKUP_FN ("fn", "min", 2) ||
                f == LOOKUP_FN ("fn", "max", 1) ||
                f == LOOKUP_FN ("fn", "max", 2))
               && TypeOps::maybe_date_time(*TypeOps::prime_type(*type0))) );
}


/*******************************************************************************
  Execute const exprs that return at most one item as a result. Replace such
  exprs by either a const_expr whose value is the returned item, or an empty
  fn:concatenate expr, if no item is returned by the evaluation of the const
  expr.
********************************************************************************/

RULE_REWRITE_PRE(FoldConst) 
{
  xqtref_t rtype = node->return_type (rCtx.getStaticContext ());
  
  if (standalone_expr (node) &&
      ! already_folded (node, rCtx) &&
      get_varset_annotation (node, AnnotationKey::FREE_VARS).empty () &&
      node->get_annotation (AnnotationKey::UNFOLDABLE_OP) != TSVAnnotationValue::TRUE_VAL &&
      TypeOps::type_max_cnt (*rtype) <= 1 &&
      (fold_expensive_ops ||
       node->get_annotation (AnnotationKey::EXPENSIVE_OP) != TSVAnnotationValue::TRUE_VAL))
  {
    vector<store::Item_t> result;
    expr_t folded = execute (rCtx.getCompilerCB(), node, result);
    if (folded == NULL) {
      ZORBA_ASSERT (result.size () <= 1);
      folded = (result.size () == 1 ?
                ((expr *) (new const_expr (LOC (node), result [0]))) :
                ((expr *) (fo_expr::create_seq (LOC (node)))));
    }
    return folded;
  }
  return NULL;
}

RULE_REWRITE_POST(FoldConst) 
{
  return NULL;
}


static bool standalone_expr (expr_t e) 
{
  expr_kind_t k = e->get_expr_kind ();
  return k != match_expr_kind && k != axis_step_expr_kind;
}


static bool already_folded (expr_t e, RewriterContext& rCtx) 
{
  if (e->get_expr_kind () == const_expr_kind)
    return true;
  if (e->get_expr_kind () != fo_expr_kind)
    return false;
  const fo_expr *fo = e.dyn_cast<fo_expr> ().getp ();
  return fo->is_concatenation () && fo->size () == 0;
}


/*******************************************************************************
  Some expressions can be computed (at leat partially) during compilation time
  based on the static type of their argument. For example, count(E) can be 
  replaced by const 1 if the static type of E has quantifier 1. Also,
  castable(E, target_type) can be replaced by const true if the static type of 
  E is a subtype of target_type. However, E may have "side-effects", which
  prevent such a replacement. For example, it may be a treat expr, whose 
  semantics is to return an error during runtime if the arg of the treat expr
  does not have the corect type. We call such exprs "impure", and flag them as
  non-discardable so that no (partial) evaluation of parent exprs is done.
********************************************************************************/

RULE_REWRITE_PRE(MarkImpureExprs) 
{
  return NULL;
}

RULE_REWRITE_POST(MarkImpureExprs) 
{
  // TODO: constructors cannot be cloned; but currently we never clone anyway.
  // TODO: propagate non-discardable prop for FLWOR vars (see nodeid_rules.cpp)

  Annotation::key_t k = AnnotationKey::NONDISCARDABLE_EXPR;
  switch (node->get_expr_kind ()) 
  {
  // TODO: update exprs probably non-discardable as well
  case fo_expr_kind: 
  {
    fo_expr *fo = static_cast<fo_expr *> (node);
    const function *f = fo->get_func ();

    if (f == LOOKUP_OP2 ("ctxvar-assign") ||
        dynamic_cast<const fn_error *> (f) != NULL)
      node->put_annotation (k, TSVAnnotationValue::TRUE_VAL);

    break;
  }
  default:
  {
    if (dynamic_cast<cast_base_expr *> (node) != NULL)
      node->put_annotation (k, TSVAnnotationValue::TRUE_VAL);
  }
  }
  
  if (node->get_annotation(k) != TSVAnnotationValue::TRUE_VAL.getp())
    propagate_any_child_up (node, k);

  return NULL;
}


/*******************************************************************************

  The PartialEval rule performs the following kinds of rewrites:

  Replace "castable(E, targetType)" with true if the return type of E is a
  subtype of targetType and E is not NONDISCARDABLE_EXPR.

  Replace "instance-of(E, targetType)" with false if the intersection of return
  type of E and the targetType is empty and E is not NONDISCARDABLE_EXPR.

  Replace "if (cond) then E1 else E2" with E1 or E2 if cond is a const expr whose
  EBV is true or false respectively.
 
  Rewrite "and" or "or" exprs which have one or more operands that are constants.
  For example:
  E and false --> false
  E and true  --> E
 
  Rewrite exprs of the form "count(E) = const" or "count(E) eq const".
  For example:
  count(E) = -1 --> false
  count(E) = 0  --> fn:empty(E)
  count(E) = 1  --> fn:exectly-one-noraise(E)
  count(E) = 10 --> fn:exectly-one-noraise(fn:subsequence(E, 10, 2))

  Replace count(E) with 1 if the return type of E has QUANT_ONE and E is not
  NONDISCARDABLE_EXPR.

********************************************************************************/

RULE_REWRITE_PRE(PartialEval) 
{
  castable_base_expr *cbe;
  if ((cbe = dynamic_cast<castable_base_expr *>(node)) != NULL) 
  {
    expr_t arg = cbe->get_input();
    if (arg->get_annotation (AnnotationKey::NONDISCARDABLE_EXPR).getp() == TSVAnnotationValue::TRUE_VAL.getp())
      return NULL;

    xqtref_t arg_type = arg->return_type(rCtx.getStaticContext());

    if (TypeOps::is_subtype(*arg_type, *cbe->get_target_type()))
      return new const_expr (LOC (node), true);

    else if (node->get_expr_kind() == instanceof_expr_kind)
      return TypeOps::intersect_type(*arg_type, *cbe->get_target_type()) == GENV_TYPESYSTEM.NONE_TYPE 
        ? new const_expr (LOC (node), false) : NULL;
    else
      return NULL;
  }

  switch (node->get_expr_kind ()) 
  {
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

RULE_REWRITE_POST(PartialEval) 
{
  return NULL;
}


static expr_t partial_eval_fo (RewriterContext& rCtx, fo_expr *fo) 
{
  const function *f = fo->get_func ();
  if (f == LOOKUP_OPN ("or"))
    return partial_eval_logic (fo, true, rCtx);

  else if (f == LOOKUP_OPN ("and"))
    return partial_eval_logic (fo, false, rCtx);

  else if (f->comparison_kind() == CompareConsts::VALUE_EQUAL ||
           f->comparison_kind() == CompareConsts::GENERAL_EQUAL)
    return partial_eval_eq (rCtx, *fo);

  else if (f == LOOKUP_FN ("fn", "count", 1)) {
    expr_t arg = (*fo) [0];
    if (arg->get_annotation (AnnotationKey::NONDISCARDABLE_EXPR) != TSVAnnotationValue::TRUE_VAL) {
      int type_cnt = TypeOps::type_cnt (*arg->return_type (rCtx.getStaticContext()));
      if (type_cnt != -1)
        return new const_expr (fo->get_loc (), Integer::parseInt (type_cnt));
    }
    return NULL;
  }
  return NULL;
}


static expr_t partial_eval_logic (
    fo_expr *fo,
    bool shortcircuit_val,
    RewriterContext& rCtx) 
{
  // fo is a logical "and" or "or" expr

  expr_t nontrivial1, nontrivial2;
  for (vector<expr_t>::iterator i = fo->begin (); i != fo->end (); i++) {
    const_expr *cond = i->dyn_cast<const_expr> ().getp ();
    if (cond != NULL) {
      if (cond->get_val ()->getEBV ()->getBooleanValue () == shortcircuit_val)
        return new const_expr (LOC (fo), (xqp_boolean) shortcircuit_val);
    } else {
      if (nontrivial1 == NULL)
        nontrivial1 = *i;
      else {
        nontrivial2 = *i;
        break;  // no rewrite anyway
      }
    }
  }

  if (nontrivial1 == NULL)
    return new const_expr (LOC (fo), (xqp_boolean) ! shortcircuit_val);

  if (nontrivial2 == NULL) {
    if (! TypeOps::is_subtype(*nontrivial1->return_type(rCtx.getStaticContext()),
                              *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE))
      nontrivial1 = fix_annotations (new fo_expr (LOC (fo),
                                                  LOOKUP_FN("fn", "boolean", 1),
                                                  nontrivial1));
    return nontrivial1;
  }
  return NULL;
}


static expr_t partial_eval_eq (RewriterContext& rCtx, fo_expr &fo) 
{
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

  if (i == 2)
    return NULL;
  
  store::Item_t val = val_expr->get_val ();
  if (TypeOps::is_subtype (*rCtx.getStaticContext()->get_typemanager()->create_named_type (val->getType ()), *GENV_TYPESYSTEM.INTEGER_TYPE_ONE)) 
  {
    xqp_integer ival = val->getIntegerValue ();
    xqp_integer zero = xqp_integer::parseInt (0);
    if (ival < zero)
      return new const_expr (LOC (val_expr), false);
    else if (ival == zero)
      return fix_annotations (new fo_expr (fo.get_loc (),
                                           LOOKUP_FN ("fn", "empty", 1),
                                           (*count_expr) [0]));
    else if (ival == xqp_integer::parseInt (1))
      return fix_annotations (new fo_expr (fo.get_loc (),
                                           LOOKUP_OP1 ("exactly-one-noraise"),
                                           (*count_expr) [0]));
    else {
      store::Item_t pVal;
      GenericCast::instance ()->promote (pVal, val, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      expr_t dpos = new const_expr (LOC (val_expr), pVal);
      expr_t subseq_expr = fix_annotations(
                           new fo_expr (LOC (count_expr),
                                        LOOKUP_FN ("fn", "subsequence", 3),
                                        (*count_expr) [0],
                                        dpos,
                                        new const_expr (LOC (val_expr),
                                                        xqp_double::parseInt (2))));
      return fix_annotations (new fo_expr (fo.get_loc (),
                                           LOOKUP_OP1 ("exactly-one-noraise"),
                                           subseq_expr));
    }
  }
  
  return NULL;
}



/*******************************************************************************

********************************************************************************/

RULE_REWRITE_PRE(InlineFunctions)
{
  return NULL;
}

RULE_REWRITE_POST(InlineFunctions)
{
  if (node->get_expr_kind () == fo_expr_kind) {
    fo_expr *fo = static_cast<fo_expr *> (node);
    const user_function *udf = dynamic_cast<const user_function *> (fo->get_func ());
    expr_t body;
    if (NULL != udf && ! udf->isSequential () && udf->isLeaf ()
        && (NULL != (body = udf->get_body ())))
    {
      expr_t body = udf->get_body ();
      const std::vector<var_expr_t>& params = udf->get_params();
      expr::substitution_t subst;
      for (unsigned i = 0; i < params.size (); ++i) {
        var_expr_t p = params [i];
        subst [p] = (*fo) [i];
      }
      try {
        body = body->clone (subst);
        return body;
      } catch (...) {}
    }
  }
  return NULL;
}

}
