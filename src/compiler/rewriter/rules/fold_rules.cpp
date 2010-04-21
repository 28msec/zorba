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

#include "zorbaerrors/errors.h"
#include "zorbaerrors/error_messages.h"

#include "system/globalenv.h"

#include "context/static_context.h"

#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/codegen/plan_visitor.h"
#include "compiler/api/compilercb.h"

#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "types/casting.h"

#include "functions/udf.h"
#include "functions/func_fnerror.h"
#include "functions/library.h"

#include "runtime/util/plan_wrapper_holder.h"
#include "runtime/base/plan_iterator.h"

#include "store/api/store.h"
#include "store/api/item_factory.h"

using namespace std;

namespace zorba {

static void remove_wincond_vars(const flwor_wincond*, VarSetAnnVal*);

static bool standalone_expr(expr_t);

static bool already_folded(expr_t, RewriterContext&);

static expr_t partial_eval_fo (RewriterContext&, fo_expr*);

static expr_t partial_eval_logic(fo_expr*, bool, RewriterContext&);

static expr_t partial_eval_eq(RewriterContext&, fo_expr&);

static bool maybe_needs_implicit_timezone(const fo_expr* fo, static_context* sctx);


/*******************************************************************************

********************************************************************************/
static expr_t execute (
    CompilerCB* compilercb,
    expr_t node,
    vector<store::Item_t>& result)
{
  PlanIter_t plan = codegen ("const-folded expr", node, compilercb);
  QueryLoc loc = LOC (node);
  store::Item_t item;
  try
  {
    PlanWrapperHolder pw(new PlanWrapper(plan,
                                         compilercb,
                                         0,      // dynamic ctx
                                         NULL,   // xquery
                                         0,      // stack depth
                                         compilercb->theTimeout));
    for (;;)
    {
      if (!pw->next(item))
      {
        break;
      }
      result.push_back(item);
    }

    return NULL;
  }
  catch (error::ZorbaError& /*e*/)
  {
    node->setUnfoldable(expr::ANNOTATION_TRUE_FIXED);
    node->setNonDiscardable(expr::ANNOTATION_TRUE_FIXED);
    return node;
    // TODO:
    // we had to disable folding of errors because the FnErrorIterator
    // was erroneously used. It always raises a ZorbaUserError (which is not correct).
#if 0
    XQUERY_ERROR lErrorCode = e.theErrorCode;
    QueryLoc loc;
    loc.setLineBegin(e.theQueryLine);
    loc.setColumnBegin(e.theQueryColumn);
    store::Item_t qname;
    ITEM_FACTORY->createQName(qname,
                              "http://www.w3.org/2005/xqt-errors",
                              "err",
                              error::ZorbaError::toString(lErrorCode).c_str());
    expr_t err_expr = new fo_expr(node->get_sctx_id(),
                                  loc,
                                  GET_BUILTIN_FUNCTION(FN_ERROR_2),
                                  new const_expr(node->get_sctx_id(), loc, qname),
                                  new const_expr(node->get_sctx_id(), loc, e.theDescription));
    err_expr->setUnfoldable(expr::ANNOTATION_TRUE_FIXED);
    err_expr->setNonDiscardable(expr::ANNOTATION_TRUE_FIXED);
    return err_expr;
#endif
  }
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

  Mark the exprs that should not be folded
********************************************************************************/
expr_t MarkExprs::apply(RewriterContext& rCtx, expr* node, bool& modified)
{
  expr::BoolAnnotationValue saveNonDiscardable = node->getNonDiscardable();
  expr::BoolAnnotationValue saveUnfoldable = node->getUnfoldable();

  // By default, an expr is discardable and foldable
  expr::BoolAnnotationValue curNonDiscardable = expr::ANNOTATION_FALSE;
  expr::BoolAnnotationValue curUnfoldable = expr::ANNOTATION_FALSE;

  for (const_expr_iterator i = node->expr_begin_const(); !i.done(); ++i)
  {
    expr* childExpr = *i;

    apply(rCtx, childExpr, modified);

    // If any of the children is nondiscardable, "this" is nondiscardable too.
    if (childExpr->isNonDiscardable())
    {
      curNonDiscardable = expr::ANNOTATION_TRUE;
    }

    // If any of the children is unfoldable, then "this" is unfoldable too.
    if (childExpr->isUnfoldable())
    {
      curUnfoldable = expr::ANNOTATION_TRUE;
    }
  }

  // Certain exprs are nondiscardable and/or unfoldable independently from
  // their children
  switch (node->get_expr_kind())
  {
  // TODO: update exprs probably non-discardable as well
  case fo_expr_kind:
  {
    fo_expr* fo = static_cast<fo_expr *>(node);
    const function* f = fo->get_func();

    // The various fn:error functions are non-discardable. Variable assignment
    // is also non-discardable.
    if (f->getKind() == FunctionConsts::OP_VAR_ASSIGN_1 ||
        dynamic_cast<const fn_error*>(f) != NULL)
    {
      curNonDiscardable = expr::ANNOTATION_TRUE_FIXED;
    }

    // Do not fold functions that always require access to the dynamic context,
    // or may need to access the implicit timezone (which is also in the dynamic
    // constext).
    if (f->accessesDynCtx () ||
        dynamic_cast<const fn_error*>(f) != NULL ||
        maybe_needs_implicit_timezone(fo, node->get_sctx()) ||
        !f->isDeterministic())
    {
      curUnfoldable = expr::ANNOTATION_TRUE_FIXED;
    }

    break;
  }

  case var_expr_kind:
  {
    var_expr::var_kind varKind = static_cast<var_expr *>(node)->get_kind();

    if (varKind == var_expr::prolog_var || varKind == var_expr::local_var)
      curUnfoldable = expr::ANNOTATION_TRUE_FIXED;

    break;
  }

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
  {
    curUnfoldable = expr::ANNOTATION_TRUE_FIXED;
    break;
  }

  case cast_expr_kind:
  case treat_expr_kind:
  case promote_expr_kind:
  {
    curNonDiscardable = expr::ANNOTATION_TRUE_FIXED;
    break;
  }

  default:
  {
    break;
  }
  }

  if (saveNonDiscardable != curNonDiscardable &&
      saveNonDiscardable != expr::ANNOTATION_TRUE_FIXED)
  {
    node->setNonDiscardable(curNonDiscardable);
    modified = true;
  }

  if (saveUnfoldable != curUnfoldable &&
      saveUnfoldable != expr::ANNOTATION_TRUE_FIXED)
  {
    node->setUnfoldable(curUnfoldable);
    modified = true;
  }

  return NULL;
}


static bool maybe_needs_implicit_timezone(const fo_expr* fo, static_context* sctx)
{
  const function* f = fo->get_func();
  FunctionConsts::FunctionKind fkind = f->getKind();
  xqtref_t type0 = (fo->num_args() > 0 ? fo->get_arg(0)->return_type(sctx) : NULL);
  xqtref_t type1 = (fo->num_args() > 1 ? fo->get_arg(1)->return_type(sctx) : NULL);

  return ( ((f->isComparisonFunction() ||
             f->arithmeticKind() == ArithmeticConsts::SUBTRACTION) &&
            (TypeOps::maybe_date_time(*type0) || TypeOps::maybe_date_time(*type1)))
           ||
           ((fkind == FunctionConsts::FN_DISTINCT_VALUES_1 ||
             fkind == FunctionConsts::FN_DISTINCT_VALUES_2 ||
             fkind == FunctionConsts::FN_MIN_1 ||
             fkind == FunctionConsts::FN_MIN_2 ||
             fkind == FunctionConsts::FN_MAX_1 ||
             fkind == FunctionConsts::FN_MAX_2)
            && TypeOps::maybe_date_time(*TypeOps::prime_type(*type0))) );
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
  AnnotationValue_t new_ann = AnnotationValue_t (freevars);

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
      const var_ptr_set &kfv = get_varset_annotation (e, Annotations::FREE_VARS);
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

  node->put_annotation (Annotations::FREE_VARS, new_ann);
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
  Execute const exprs that return at most one item as a result. Replace such
  exprs by either a const_expr whose value is the returned item, or an empty
  fn:concatenate expr, if no item is returned by the evaluation of the const
  expr.
********************************************************************************/

RULE_REWRITE_PRE(FoldConst)
{
  xqtref_t rtype = node->return_type(node->get_sctx());

  // TODO: this computation could be moved to isUnfoldable() in fo_expr
  bool isDeterministicFunc = true;
  fo_expr* fo = dynamic_cast<fo_expr *>(node);
  if (fo != NULL && fo->get_func() != NULL)
    isDeterministicFunc = fo->get_func()->isDeterministic();

  if (standalone_expr(node) &&
      ! already_folded(node, rCtx) &&
      get_varset_annotation (node, Annotations::FREE_VARS).empty() &&
      ! node->isUnfoldable() &&
      isDeterministicFunc &&
      TypeOps::type_max_cnt(*rtype) <= 1)
    // &&
    //  (fold_expensive_ops ||
    //   node->get_annotation (Annotations::EXPENSIVE_OP) != TSVAnnotationValue::TRUE_VAL))
  {
    vector<store::Item_t> result;
    expr_t folded = execute (rCtx.getCompilerCB(), node, result);
    if (folded == NULL)
    {
      ZORBA_ASSERT (result.size () <= 1);
      folded = (result.size () == 1 ?
                ((expr *) (new const_expr (node->get_sctx(), LOC (node), result [0]))) :
                ((expr *) (fo_expr::create_seq (node->get_sctx(), LOC (node)))));
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
  const fo_expr *fo = e.dyn_cast<fo_expr>().getp ();

  return (fo->get_func()->getKind() == FunctionConsts::OP_CONCATENATE_N &&
          fo->num_args() == 0);
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
  const castable_base_expr* cbe;
  if ((cbe = dynamic_cast<const castable_base_expr *>(node)) != NULL)
  {
    const expr* arg = cbe->get_input();

    if (arg->isNonDiscardable())
      return NULL;

    xqtref_t arg_type = arg->return_type(node->get_sctx());

    if (TypeOps::is_subtype(*arg_type, *cbe->get_target_type()))
    {
      return new const_expr(node->get_sctx(), LOC(node), true);
    }
    else if (node->get_expr_kind() == instanceof_expr_kind)
    {
      return (TypeOps::intersect_type(*arg_type, *cbe->get_target_type()) ==
              GENV_TYPESYSTEM.NONE_TYPE ?
              new const_expr(node->get_sctx(), LOC(node), false) :
              NULL);
    }
    else
    {
      return NULL;
    }
  }

  switch (node->get_expr_kind())
  {
  case if_expr_kind:
  {
    if_expr* ite = dynamic_cast<if_expr *> (node);
    const const_expr* cond = dynamic_cast<const const_expr*>(ite->get_cond_expr());
    if (cond != NULL)
    {
      return (cond->get_val()->getBooleanValue() ?
              ite->get_then_expr(true) :
              ite->get_else_expr(true));
    }
    break;
  }

  case fo_expr_kind:
  {
    return partial_eval_fo(rCtx, dynamic_cast<fo_expr *> (node));
  }

  default:
    break;
  }

  return NULL;
}

RULE_REWRITE_POST(PartialEval)
{
  return NULL;
}


static expr_t partial_eval_fo(RewriterContext& rCtx, fo_expr* fo)
{
  const function* f = fo->get_func();
  FunctionConsts::FunctionKind fkind = f->getKind();

  if (fkind == FunctionConsts::OP_OR_2)
  {
    return partial_eval_logic(fo, true, rCtx);
  }
  else if (fkind == FunctionConsts::OP_AND_2)
  {
    return partial_eval_logic(fo, false, rCtx);
  }
  else if (f->comparisonKind() == CompareConsts::VALUE_EQUAL ||
           f->comparisonKind() == CompareConsts::GENERAL_EQUAL)
  {
    return partial_eval_eq(rCtx, *fo);
  }
  else if (fkind == FunctionConsts::FN_COUNT_1)
  {
    expr_t arg = fo->get_arg(0, false);
    if (!arg->isNonDiscardable())
    {
      int type_cnt = TypeOps::type_cnt(*arg->return_type(fo->get_sctx()));
      if (type_cnt != -1)
        return new const_expr(fo->get_sctx(), fo->get_loc(), Integer::parseInt(type_cnt));
    }
    return NULL;
  }
  else if (fkind == FunctionConsts::FN_BOOLEAN_1)
  {
    expr_t arg = fo->get_arg(0, false);
    xqtref_t argType = arg->return_type(fo->get_sctx());
    if (TypeOps::is_subtype(*argType, *GENV_TYPESYSTEM.ANY_NODE_TYPE_PLUS))
    {
      return new const_expr(fo->get_sctx(), fo->get_loc(), true);
    }
  }

  return NULL;
}


/*******************************************************************************
  fo is a logical "and" or "or" expr. If "and" then the shortcircuit_val is
  false, otherwise, shortcircuit_val is true.
********************************************************************************/
static expr_t partial_eval_logic(
    fo_expr* fo,
    bool shortcircuit_val,
    RewriterContext& rCtx)
{
  long nonConst1 = -1;
  long nonConst2 = -1;

  ulong numArgs = fo->num_args();

  for (ulong i = 0; i < numArgs; ++i)
  {
    const expr* arg = fo->get_arg(i);
    const const_expr* constArg;

    if ((constArg = dynamic_cast<const const_expr*>(arg)) != NULL)
    {
      if (constArg->get_val()->getEBV()->getBooleanValue() == shortcircuit_val)
        return new const_expr(fo->get_sctx(), LOC(fo), (xqp_boolean)shortcircuit_val);
    }
    else
    {
      if (nonConst1 < 0)
      {
        nonConst1 = i;
      }
      else
      {
        nonConst2 = i;
        break;  // no rewrite anyway
      }
    }
  }

  if (nonConst1 < 0)
  {
    // Both args are constant exprs
    return new const_expr(fo->get_sctx(), LOC(fo), (xqp_boolean) ! shortcircuit_val);
  }

  if (nonConst2 < 0)
  {
    // Only one of the args is a constant expr. The non-const arg is pointed
    // to by nonConst1.

    expr_t arg = fo->get_arg(nonConst1, true);

    if (! TypeOps::is_subtype(*arg->return_type(fo->get_sctx()),
                              *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE))
    {
      arg = fix_annotations(new fo_expr(fo->get_sctx(),
                                        LOC(fo),
                                        GET_BUILTIN_FUNCTION(FN_BOOLEAN_1),
                                        arg));
    }

    return arg;
  }

  return NULL;
}


/*******************************************************************************
  count(expr) = int_const
********************************************************************************/
static expr_t partial_eval_eq(RewriterContext& rCtx, fo_expr& fo)
{
  int i;
  fo_expr* count_expr = NULL;
  const_expr* val_expr = NULL;

  for (i = 0; i < 2; i++)
  {
    if (NULL != (val_expr = dynamic_cast<const_expr*>(fo.get_arg(i, false))) &&
        NULL != (count_expr = dynamic_cast<fo_expr*>(fo.get_arg(1-i, false))) &&
        count_expr->get_func()->getKind() == FunctionConsts::FN_COUNT_1)
      break;
  }

  if (i == 2)
    return NULL;

  TypeManager* tm = fo.get_sctx()->get_typemanager();

  store::Item* val = val_expr->get_val();

  if (TypeOps::is_subtype(*tm->create_named_type(val->getType()),
                          *GENV_TYPESYSTEM.INTEGER_TYPE_ONE))
  {
    xqp_integer ival = val->getIntegerValue();
    xqp_integer zero = xqp_integer::parseInt(0);

    if (ival < zero)
    {
      return new const_expr(val_expr->get_sctx(), LOC(val_expr), false);
    }
    else if (ival == zero)
    {
      return fix_annotations(new fo_expr(fo.get_sctx(), fo.get_loc(),
                                         GET_BUILTIN_FUNCTION(FN_EMPTY_1),
                                         count_expr->get_arg(0, false)));
    }
    else if (ival == xqp_integer::parseInt(1))
    {
      return fix_annotations(new fo_expr(fo.get_sctx(),
                                         fo.get_loc(),
                                         GET_BUILTIN_FUNCTION(OP_EXACTLY_ONE_NORAISE_1),
                                         count_expr->get_arg(0, false)));
    }
    else
    {
      store::Item_t pVal;
      store::Item_t iVal = val;
      GenericCast::promote(pVal, iVal, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, *tm);
      expr_t dpos = new const_expr(val_expr->get_sctx(), LOC(val_expr), pVal);

      std::vector<expr_t> args(3);
      args[0] = count_expr->get_arg(0);
      args[1] = dpos;
      args[2] = new const_expr(val_expr->get_sctx(),
                               LOC(val_expr),
                               xqp_integer::parseInt(2));

      expr_t subseq_expr = fix_annotations(
                           new fo_expr(count_expr->get_sctx(),
                                       LOC (count_expr),
                                       GET_BUILTIN_FUNCTION(FN_ZORBA_INT_SUBSEQUENCE_3),
                                       args));

      return fix_annotations(new fo_expr(fo.get_sctx(),
                                         fo.get_loc(),
                                         GET_BUILTIN_FUNCTION(OP_EXACTLY_ONE_NORAISE_1),
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
  if (node->get_expr_kind () == fo_expr_kind)
  {
    const fo_expr* fo = static_cast<const fo_expr *> (node);

    const user_function* udf = dynamic_cast<const user_function *>(fo->get_func());
    expr_t body;

    if (NULL != udf && ! udf->isSequential() && udf->isLeaf() &&
        (NULL != (body = udf->getBody())))
    {
      const std::vector<var_expr_t>& udfArgs = udf->getArgVars();

      expr::substitution_t subst;

      for (ulong i = 0; i < udfArgs.size(); ++i)
      {
        var_expr_t p = udfArgs[i];
        subst[p] = fo->get_arg(i);
      }

      try
      {
        expr_t body = udf->getBody();
        body = body->clone(subst);
        body->clear_annotations();
        return body;
        // TODO: this is caught here, because clone is not implemented for all expressions
      }
      catch (...)
      {
      }
    }
  }

  return NULL;
}

}
