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

#include "functions/function.h"
#include "functions/library.h"

#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/framework/rule_driver.h"
#include "compiler/rewriter/tools/expr_tools.h"

#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/expr_iter.h"
#include "compiler/expression/expr.h"

#include "context/static_context.h"

#include "types/typeops.h"
#include "types/casting.h"

#include "zorbaerrors/xquery_warning.h"

#include <memory>
#include <iterator>

namespace zorba
{

static void collect_flw_vars(const flwor_expr& flwor, VarSetAnnVal& vars);

static bool is_trivial_expr(const expr* e);

static bool safe_to_fold_single_use(var_expr*, TypeConstants::quantifier_t, const flwor_expr&);

static bool var_in_try_block_or_in_loop(const var_expr*, const expr*, bool, bool, ulong&);

static bool is_subseq_pred(RewriterContext&, const flwor_expr*, const expr*, var_expr_t&, expr_t&);


#define MODIFY( expr ) do { modified = true; expr; } while (0)


/*******************************************************************************

********************************************************************************/
static void fix_if_annotations(if_expr* ifExpr)
{
  fix_annotations(ifExpr, ifExpr->get_cond_expr());
  fix_annotations(ifExpr, ifExpr->get_then_expr());
  fix_annotations(ifExpr, ifExpr->get_else_expr());
}


/*******************************************************************************

********************************************************************************/
class SubstVars : public PrePostRewriteRule
{
protected:
  const var_expr   * theVarExpr;
  expr             * theSubstExpr;

public:
  SubstVars(const var_expr* var, expr* subst)
    :
    PrePostRewriteRule(RewriteRule::SubstVars, "SubstVars"),
    theVarExpr(var),
    theSubstExpr(subst)
  {
  }

protected:
  expr_t rewritePre(expr* node, RewriterContext& rCtx);
  expr_t rewritePost(expr* node, RewriterContext& rCtx);
};


RULE_REWRITE_PRE(SubstVars)
{
  return (node == theVarExpr) ? theSubstExpr : NULL;
}


RULE_REWRITE_POST(SubstVars)
{
  return NULL;
}


/*******************************************************************************
  Replace all references to var "var" inside the expr "root" with expr "subst"
********************************************************************************/
expr_t subst_vars(
    const RewriterContext& rCtx0,
    expr* root,
    const var_expr* var,
    expr* subst)
{
  RewriterContext rCtx(rCtx0.getCompilerCB(),
                       root,
                       rCtx0.theUDF,
                       rCtx0.theMessage,
                       rCtx0.theIsInOrderedMode);

  SubstVars rule(var, subst);

  bool modified;

  rule.apply(rCtx, root, modified);

#if 0  // debug substitutions
  std::cout << rCtx.theMessage << std::endl
            << "After subst " << var << " :" << std::endl;
  rCtx.getRoot()->put(std::cout) << std::endl;
#endif

  return rCtx.getRoot();
}



/*******************************************************************************

********************************************************************************/
RULE_REWRITE_PRE(EliminateUnusedLetVars)
{
  const QueryLoc& loc = LOC(node);
  static_context* sctx = node->get_sctx();
  TypeManager* tm = sctx->get_typemanager();

  if (node->get_expr_kind() != flwor_expr_kind)
    return NULL;

  flwor_expr* flworp = static_cast<flwor_expr *>(node);
  flwor_expr& flwor = *flworp;

  VarSetAnnVal myVars;
  collect_flw_vars(flwor, myVars);

  const forletwin_clause& flwc = *reinterpret_cast<const forletwin_clause *>(flwor[0]);

  unsigned numClauses = flwor.num_clauses();
  unsigned numForLetClauses = 0;

  // "for $x in E return $x"  --> "E"
  // "let $x := E return $x"  --> "E"
  if (numClauses == 1 &&
      myVars.theVarset.size() == 1 &&
      flwor.get_return_expr()->get_expr_kind() == wrapper_expr_kind)
  {
    const wrapper_expr* w = static_cast<const wrapper_expr*>(flwor.get_return_expr());
    if (w->get_expr() == flwc.get_var())
      return flwc.get_expr();
  }

  // "for $x in ... where E ... return ...", and E doesn't depend on FLWOR vars -->
  // "if E then flwor else ()", where flwor is the original flwor expr without the
  // where clause.
  expr* whereExpr;
  if ((whereExpr = flwor.get_where()) != NULL)
  {
    const var_ptr_set& whereVars = get_varset_annotation(whereExpr,
                                                         Annotations::FREE_VARS);
    var_ptr_set diff;
    set_intersection(myVars.theVarset.begin(), myVars.theVarset.end(),
                     whereVars.begin(), whereVars.end(),
                     std::inserter(diff, diff.begin()));
    if (diff.empty())
    {
      expr_t oldWhere = whereExpr;
      flwor.remove_where_clause();

      rchandle<if_expr> ifExpr = new if_expr(sctx,
                                             loc,
                                             oldWhere,
                                             &flwor,
                                             fo_expr::create_seq(sctx, loc));

      fix_if_annotations(ifExpr);

      return ifExpr;
    }
  }

  bool modified = false;
  group_clause* gc = NULL;

  // (a) Remove, if possible, FOR/LET vars that are not referenced anywhere
  // (b) Replace, if possible, FOR/LET vars that are referenced only once, with
  //     their domain expr.
  // (c) Change a LET var into a FOR var, if its domain expr consists of
  //     exactly one item.
  for (ulong i = 0; i < numClauses; ++i)
  {
    bool substitute = false;

    flwor_clause& c = *flwor.get_clause(i);

    if (c.get_kind() == flwor_clause::group_clause)
    {
      gc = static_cast<group_clause *>(&c);
    }
    else if (c.get_kind() == flwor_clause::for_clause)
    {
      numForLetClauses++;
      for_clause* fc = static_cast<for_clause *>(&c);

      expr* domainExpr = fc->get_expr();
      xqtref_t domainType = domainExpr->get_return_type();
      var_expr* var = fc->get_var();
      TypeConstants::quantifier_t domainQuant = domainType->get_quantifier();
      ulong domainCount = TypeOps::type_max_cnt(tm, *domainType);
      const var_expr* pvar = fc->get_pos_var();

      if (pvar != NULL && count_variable_uses(&flwor, pvar, &rCtx, 1) == 0)
      {
        MODIFY(fc->set_pos_var(NULL));
        pvar = NULL;
      }

      // Cannot substitute a FOR var whose domain is a sequential expr or
      // might contain more than 1 items.
      if (domainExpr->is_sequential() || domainCount >= 2)
        continue;

      // FOR clause with 0 cardinality
      if (domainCount == 0)
        return fo_expr::create_seq(sctx, LOC(node));

      if (pvar != NULL)
      {
        MODIFY(subst_vars(rCtx, node, pvar, new const_expr(sctx,
                                                           loc,
                                                           xs_integer::parseInt(1))));
      }

      int uses = count_variable_uses(&flwor, var, &rCtx, 2);

      if (uses > 1 &&
          is_trivial_expr(domainExpr) &&
          domainQuant == TypeConstants::QUANT_ONE)
      {
        subst_vars(rCtx, node, var, domainExpr);
        substitute = true;
      }
      else if (uses == 1 &&
               ((is_trivial_expr(domainExpr) &&
                 domainQuant == TypeConstants::QUANT_ONE) ||
                safe_to_fold_single_use(var, domainQuant, flwor)))
      {
        subst_vars(rCtx, node, var, domainExpr);
        substitute = true;
      }
      else if (uses == 0 &&
               !domainExpr->isNonDiscardable() &&
               domainQuant == TypeConstants::QUANT_ONE)
      {
        substitute = true;
      }

      if (substitute)
      {
        MODIFY(flwor.remove_clause(i));
        --numClauses;
        --numForLetClauses;
        --i;

        flwor.compute_return_type(true, NULL);
      }
    }
    else if (c.get_kind() == flwor_clause::let_clause)
    {
      let_clause* lc = static_cast<let_clause *>(&c);
      numForLetClauses++;

      expr* domainExpr = lc->get_expr();
      xqtref_t domainType = domainExpr->get_return_type();
      TypeConstants::quantifier_t domainQuant = domainType->get_quantifier();
      var_expr* var = lc->get_var();

      int uses = count_variable_uses(&flwor, var, &rCtx, 2);

      if (uses > 1 && !domainExpr->is_sequential() && is_trivial_expr(domainExpr))
      {
        subst_vars(rCtx, node, var, domainExpr);
        substitute = true;
      }
      else if (uses == 1)
      {
        if (!domainExpr->is_sequential() &&
            (is_trivial_expr(domainExpr) ||
             safe_to_fold_single_use(var, TypeConstants::QUANT_ONE, flwor)))
        {
          subst_vars(rCtx, node, var, domainExpr);
          substitute = true;
        }
      }
      else if (uses == 0 &&
               !domainExpr->is_sequential() &&
               !domainExpr->isNonDiscardable())
      {
        substitute = true;

				rCtx.getCompilerCB()->theXQueryDiagnostics->add_warning(
					NEW_XQUERY_WARNING(
						zwarn::ZWST0001_UNUSED_VARIABLE,
						WARN_PARAMS(var->get_name()->getStringValue()),
						WARN_LOC(var->get_loc())));
      }

      if (substitute)
      {
        MODIFY(flwor.remove_clause(i));
        --numClauses;
        --numForLetClauses;
        --i;
      }
      else if (domainQuant == TypeConstants::QUANT_ONE)
      {
        let_clause_t save = lc;
        MODIFY(flwor.remove_clause(i));
        const QueryLoc& loc = var->get_loc();
        var_expr_t fvar = new var_expr(sctx, loc, var_expr::for_var, var->get_name()); 
        for_clause_t fc = new for_clause(sctx, loc, fvar, domainExpr);
        flwor.add_clause(i, fc);

        subst_vars(rCtx, node, var, fvar.getp());
      }
    }
  }

  // FLWOR with no remaining clauses
  if (numForLetClauses == 0)
  {
    if (gc != NULL)
    {
      const flwor_clause::rebind_list_t& gVars = gc->get_grouping_vars();
      flwor_clause::rebind_list_t::const_iterator gVarsIte = gVars.begin();
      flwor_clause::rebind_list_t::const_iterator gVarsEnd = gVars.end();
      for (; gVarsIte != gVarsEnd; ++gVarsIte)
      {
        subst_vars(rCtx, flworp, gVarsIte->second.getp(), gVarsIte->first.getp());
      }

      const flwor_clause::rebind_list_t& ngVars = gc->get_nongrouping_vars();
      flwor_clause::rebind_list_t::const_iterator ngVarsIte = ngVars.begin();
      flwor_clause::rebind_list_t::const_iterator ngVarsEnd = ngVars.end();
      for (; ngVarsIte != ngVarsEnd; ++ngVarsIte)
      {
        subst_vars(rCtx, flworp, ngVarsIte->second.getp(), ngVarsIte->first.getp());
      }
    }

    expr_t result = flwor.get_return_expr();
    expr* whereExpr;

    if ((whereExpr = flwor.get_where()) != NULL)
    {
      rchandle<if_expr> ifExpr = 
      new if_expr(whereExpr->get_sctx(),
                  LOC(whereExpr),
                  whereExpr,
                  result,
                  fo_expr::create_seq(whereExpr->get_sctx(),
                                      LOC(whereExpr)));
      fix_if_annotations(ifExpr);
      
      return ifExpr;
    }

    return result;
  }

  return modified ? node : NULL;
}


RULE_REWRITE_POST(EliminateUnusedLetVars)
{
  return NULL;
}


/*******************************************************************************
  Returns a set containing all variables (including positional) defined by the
  FOR, LET, or WINDOW clauses of a flwor expr.
********************************************************************************/
static void collect_flw_vars(const flwor_expr& flwor, VarSetAnnVal& vars)
{
  for (uint32_t i = 0; i < flwor.num_clauses(); ++i)
  {
    const flwor_clause& c = *flwor[i];

    if (c.get_kind() == flwor_clause::for_clause)
    {
      const for_clause* fc = static_cast<const for_clause *>(&c);

      vars.add(fc->get_var());

      if (fc->get_pos_var() != NULL)
        vars.add(fc->get_pos_var());
    }

    else if (c.get_kind() == flwor_clause::let_clause)
    {
      const let_clause* lc = static_cast<const let_clause *>(&c);

      vars.add(lc->get_var());
    }

    else if (c.get_kind() == flwor_clause::window_clause)
    {
      const window_clause* wc = static_cast<const window_clause *>(&c);

      vars.add(wc->get_var());

      if (wc->get_win_start() != NULL)
      {
        const flwor_wincond* cond = wc->get_win_start();
        const flwor_wincond::vars& condvars = cond->get_out_vars();

        if (condvars.posvar != NULL) vars.add(condvars.posvar);
        if (condvars.curr != NULL) vars.add(condvars.curr);
        if (condvars.prev != NULL) vars.add(condvars.prev);
        if (condvars.next != NULL) vars.add(condvars.next);
      }

      if (wc->get_win_stop() != NULL)
      {
        const flwor_wincond* cond = wc->get_win_stop();
        const flwor_wincond::vars& condvars = cond->get_out_vars();

        if (condvars.posvar != NULL) vars.add(condvars.posvar);
        if (condvars.curr != NULL) vars.add(condvars.curr);
        if (condvars.prev != NULL) vars.add(condvars.prev);
        if (condvars.next != NULL) vars.add(condvars.next);
      }
    }
  }
}


/*******************************************************************************
  Cannot throw exception that can be caught by a try block
********************************************************************************/
static bool is_trivial_expr(const expr* e)
{
  switch (e->get_expr_kind())
  {
  case const_expr_kind: // ????
  {
    return true;
  }
  case var_expr_kind:
  {
    enum var_expr::var_kind vk = static_cast<const var_expr*>(e)->get_kind();
    return vk != var_expr::arg_var;
  }
  case wrapper_expr_kind:
  {
    return is_trivial_expr(static_cast<const wrapper_expr*>(e)->get_expr());
  }
  default:
    return false;
  }
}


/*******************************************************************************

********************************************************************************/
static bool safe_to_fold_single_use(
    var_expr* v,
    TypeConstants::quantifier_t for_quant,
    const flwor_expr& flwor)
{
  bool declared = false;
  expr_t referencingExpr = NULL;

  TypeManager* tm = v->get_type_manager();

  expr* domainExpr = v->get_domain_expr();

  bool hasNodeConstr = domainExpr->contains_node_construction();

  for (ulong i = 0; i < flwor.num_clauses(); ++i)
  {
    const flwor_clause& c = *flwor[i];
    flwor_clause::ClauseKind kind = c.get_kind();

    if (kind == flwor_clause::for_clause)
    {
      const for_clause& fc = *static_cast<const for_clause *>(&c);
      var_expr* var = fc.get_var();

      if (! declared)
      {
        declared = (v == var);
        continue;
      }

      if (count_variable_uses(fc.get_expr(), v, NULL, 1) == 1)
      {
        if (for_quant != TypeConstants::QUANT_ONE)
        {
          xqtref_t type = fc.get_expr()->get_return_type_with_empty_input(v);

          if (TypeOps::is_equal(tm, *type, *GENV_TYPESYSTEM.EMPTY_TYPE))
          {
            referencingExpr = fc.get_expr();
            break;
          }
          else
          {
            return false;
          }
        }
        else
        {
          referencingExpr = fc.get_expr();
          break;
        }
      }

      // If the var is referenced inside a for loop with more than 1 iterations,
      // then we don't replace the var with its domain expr because the domain
      // expr will be computed once per iteration instead of just once.
      if (TypeOps::type_max_cnt(tm, *fc.get_expr()->get_return_type()) >= 2)
        return false;

      // test rbkt/zorba/extern/5890.xq illustrates why this check is needed
      if (hasNodeConstr && fc.get_expr()->contains_node_construction())
        return false;
    }
    else if (kind == flwor_clause::let_clause)
    {
      const forletwin_clause& flc = *static_cast<const forletwin_clause *>(&c);
      var_expr* var = flc.get_var();

      if (! declared)
      {
        declared = (v == var);
        continue;
      }

      if (for_quant == TypeConstants::QUANT_ONE &&
          count_variable_uses(flc.get_expr(), v, NULL, 1) == 1)
      {
        referencingExpr = flc.get_expr();
        break;
      }

      // test rbkt/zorba/extern/5890.xq illustrates why this check is needed
      if (hasNodeConstr && c.get_expr()->contains_node_construction())
        return false;
    }
    else if (kind == flwor_clause::where_clause)
    {
      if (for_quant == TypeConstants::QUANT_ONE && 
          count_variable_uses(c.get_expr(), v, NULL, 1) == 1)
      {
        referencingExpr = c.get_expr();
        break;
      }
    }
    else if (kind == flwor_clause::order_clause)
    {
      if (for_quant == TypeConstants::QUANT_ONE)
      {
        // TODO
      }
    }
  }

  if (referencingExpr == NULL &&
      !flwor.get_return_expr()->is_sequential() &&
      count_variable_uses(flwor.get_return_expr(), v, NULL, 1) == 1)
  {
    if (for_quant != TypeConstants::QUANT_ONE)
    {
      xqtref_t type = 
      flwor.get_return_expr()->get_return_type_with_empty_input(v);

      if (TypeOps::is_equal(tm, *type, *GENV_TYPESYSTEM.EMPTY_TYPE))
        referencingExpr = flwor.get_return_expr();
    }
    else
    {
      referencingExpr = flwor.get_return_expr();
    }
  }

  if (referencingExpr == NULL)
    return false;

  ulong numRefs = 1;
  return !var_in_try_block_or_in_loop(v,
                                      referencingExpr,
                                      false,
                                      hasNodeConstr, 
                                      numRefs);
}


/*******************************************************************************
  Given a variable V and an expression E that references V a given number of
  times (numRemainingRefs), return true if there is at least one reference v
  of V in E such that:
  (a) v occurs inside a for-loop within E, or
  (b) 
********************************************************************************/
static bool var_in_try_block_or_in_loop(
    const var_expr* v,
    const expr* e,
    bool in_try_block_or_in_loop,
    bool hasNodeConstr,
    ulong& numRemainingRefs)
{
  if (numRemainingRefs == 0)
    return false;

  TypeManager* tm = v->get_type_manager();

  expr_kind_t kind = e->get_expr_kind();

  if (kind == trycatch_expr_kind)
  {
    const trycatch_expr* tce = dynamic_cast<const trycatch_expr *>(e);

    if (var_in_try_block_or_in_loop(v,
                                    tce->get_try_expr(),
                                    true,
                                    hasNodeConstr,
                                    numRemainingRefs))
    {
      return true;
    }

    ulong numClauses = tce->clause_count();

    for (ulong i = 0; i < numClauses; ++i)
    {
      if (var_in_try_block_or_in_loop(v,
                                      tce->get_catch_expr(i),
                                      in_try_block_or_in_loop,
                                      hasNodeConstr,
                                      numRemainingRefs))
      {
        return true;
      }
    }
    return false;
  }
  else if (kind == flwor_expr_kind)
  {
    const flwor_expr& flwor = *static_cast<const flwor_expr *>(e);

		expr_t referencingExpr = NULL;

    for (ulong i = 0; i < flwor.num_clauses(); ++i)
    {
      const flwor_clause& c = *flwor[i];

      if (c.get_kind() == flwor_clause::for_clause ||
          c.get_kind() == flwor_clause::let_clause)
      {
        const forletwin_clause& flc = *static_cast<const forletwin_clause *>(&c);;

        if (count_variable_uses(flc.get_expr(), v, NULL, 1) == 1)
        {
          referencingExpr = flc.get_expr();
          break;
        }

        if (c.get_kind() == flwor_clause::for_clause &&
            TypeOps::type_max_cnt(tm, *flc.get_expr()->get_return_type()) >= 2)
        {
          return true;
        }

        // test rbkt/zorba/extern/5890.xq illustrates why this check is needed
        if (hasNodeConstr && c.get_expr()->contains_node_construction())
        {
          return true;
        }
      }
    }

		if (referencingExpr == NULL)
    {
			referencingExpr = flwor.get_return_expr();
		}

		return var_in_try_block_or_in_loop(v,
                                       &*referencingExpr,
                                       in_try_block_or_in_loop,
                                       hasNodeConstr,
                                       numRemainingRefs);
  }
  else if (e == v)
  {
    --numRemainingRefs;
    return in_try_block_or_in_loop;
  }

#if 0
  else if (kind == elem_expr_kind ||
      kind == attr_expr_kind ||
      kind == pi_expr_kind ||
      kind == text_expr_kind ||
      kind == doc_expr_kind)
  {
    // test rbkt/zorba/extern/5890.xq illustrates why this check is needed
    if (hasNodeConstr)
      return true;
  }
#endif

  // Or else navigate down all children
  ExprConstIterator ei(e);
  while(!ei.done())
  {
    if (var_in_try_block_or_in_loop(v,
                                    ei.get_expr(),
                                    in_try_block_or_in_loop,
                                    hasNodeConstr,
                                    numRemainingRefs))
    {
      return true;
    }
    ei.next();
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
RULE_REWRITE_PRE(RefactorPredFLWOR)
{
  TypeManager* tm = node->get_type_manager();

  flwor_expr* flwor = dynamic_cast<flwor_expr *>(node);

  if (flwor == NULL || flwor->is_general())
    return NULL;

  if_expr* ifReturnExpr = dynamic_cast<if_expr*>(flwor->get_return_expr());
  expr* whereExpr = flwor->get_where();

  // "for $x in ... return if (ce) then te else ()" -->
  // "for $x in ... where ce return te"
  if (ifReturnExpr != NULL &&
      whereExpr == NULL &&
      ifReturnExpr->is_simple() &&
      TypeOps::is_empty(tm, *ifReturnExpr->get_else_expr()->get_return_type()))
  {
    expr_t cond = ifReturnExpr->get_cond_expr();
    expr_t then = ifReturnExpr->get_then_expr();
    flwor->set_return_expr(then);
    flwor->set_where(cond);
    return flwor;
  }

  expr_t posExpr;
  var_expr_t posVar;

  // '... for $x at $p in E ... where $p = posExpr ... return ...' -->
  // '... for $x in fn:subsequence(E, posExpr, 1) ... return ...
  if (whereExpr != NULL &&
      is_subseq_pred(rCtx, flwor, whereExpr, posVar, posExpr) &&
      count_variable_uses(flwor, posVar, &rCtx, 2) <= 1)
  {
    function* seq_point = GET_BUILTIN_FUNCTION(OP_ZORBA_SEQUENCE_POINT_ACCESS_2);
    expr* domainExpr = posVar->get_for_clause()->get_expr();

    std::vector<expr_t> args(2);
    args[0] = domainExpr;
    args[1] = posExpr;

    rchandle<fo_expr> result = new fo_expr(whereExpr->get_sctx(),
                                           LOC(whereExpr),
                                           seq_point,
                                           args);
    fix_annotations(&*result);
    for_clause* clause = posVar->get_for_clause();
    clause->set_expr(&*result);
    clause->set_pos_var(NULL);
    flwor->remove_where_clause();

    return flwor;
  }

  return NULL;
}


RULE_REWRITE_POST(RefactorPredFLWOR)
{
  return NULL;
}


/*******************************************************************************
  Checks whether "condExpr" has the form '$posVar = posExpr', where posExpr is 
  an integer literal with value >= 1, or an expression whose type is xs:Integer
  and which does not reference the for var associated with posVar nor any other
  vars that are defined after that for var.
********************************************************************************/
static bool is_subseq_pred(
    RewriterContext& rCtx,
    const flwor_expr* flworExpr,
    const expr* condExpr,
    var_expr_t& posVar,
    expr_t& posExpr)
{
  static_context* sctx = condExpr->get_sctx();
  TypeManager* tm = sctx->get_typemanager();
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  const fo_expr* fo = dynamic_cast<const fo_expr*>(condExpr);

  if (fo == NULL)
    return false;

  const function* f = fo->get_func();

  if (f->getKind() != FunctionConsts::OP_EQUAL_2 &&
      f->getKind() != FunctionConsts::OP_VALUE_EQUAL_2)
    return false;

  for (ulong i = 0; i < 2; i++)
  {
    posVar = fo->get_arg(i)->get_var();
    posExpr = fo->get_arg(1 - i);
    const const_expr* posConstExpr = dynamic_cast<const const_expr*>(posExpr.getp());

    if (posVar != NULL &&
        posVar->get_kind() == var_expr::pos_var &&
        flworExpr->defines_variable(posVar) >= 0)
    {
      if (posConstExpr != NULL)
      {
        const store::Item* val = posConstExpr->get_val();
        xqtref_t valType = tm->create_named_type(val->getType(),
                                                 TypeConstants::QUANT_ONE,
                                                 posConstExpr->get_loc(),
                                                 err::XPTY0004);

        if (TypeOps::is_subtype(tm, *valType, *rtm.INTEGER_TYPE_ONE) &&
            val->getIntegerValue() >= xs_integer::parseInt(1))
        {
          return true;
        }
      }
      else
      {
        xqtref_t posExprType = posExpr->get_return_type();

        if (TypeOps::is_subtype(tm, *posExprType, *rtm.INTEGER_TYPE_ONE))
        {
          VarIdMap varidMap;
          ulong numFlworVars = 0;
          index_flwor_vars(flworExpr, numFlworVars, varidMap, NULL);

          DynamicBitset varset(numFlworVars);
          ExprVarsMap exprVarMap;
          build_expr_to_vars_map(posExpr, varidMap, varset, exprVarMap);

          var_expr* forVar = posVar->get_for_clause()->get_var();
          ulong forVarId = varidMap[forVar];

          std::vector<ulong> posExprVarIds;
          exprVarMap[posExpr].getSet(posExprVarIds);

          ulong numPosExprVars = (ulong)posExprVarIds.size();
          for (ulong i = 0; i < numPosExprVars; ++i)
          {
            if (posExprVarIds[i] >= forVarId)
              return false;
          }
          
          return true;
        }
      }
    }
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
RULE_REWRITE_PRE(MergeFLWOR)
{
  flwor_expr* flwor = dynamic_cast<flwor_expr *>(node);

  if (flwor == NULL)
    return NULL;

  bool modified = false;

  if (flwor->get_return_expr()->get_expr_kind() == flwor_expr_kind)
  {
    flwor_expr_t returnFlwor = static_cast<flwor_expr*>(flwor->get_return_expr());

    if (!flwor->is_general())
    {
      ulong numClauses = flwor->num_clauses();

      for (ulong i = 0; i < numClauses; ++i)
      {
        const flwor_clause* c = (*flwor)[i];

        if (c->get_kind() == flwor_clause::where_clause ||
            c->get_kind() == flwor_clause::group_clause ||
            c->get_kind() == flwor_clause::order_clause)
        {
          goto next1;
        }
      }
    }

    ulong numClauses = returnFlwor->num_clauses();
    
    for (ulong i = 0; i < numClauses; ++i)
    {
      const flwor_clause* c = (*returnFlwor)[i];
      
      if (c->get_kind() == flwor_clause::group_clause ||
          c->get_kind() == flwor_clause::order_clause)
      {
        goto next1;
      }
    }

    for (ulong i = 0; i < numClauses; ++i)
    {
      flwor->add_clause(returnFlwor->get_clause(i));
    }

    flwor->set_return_expr(returnFlwor->get_return_expr());

    modified = true;
  }

 next1:

#if 1
  ulong numClauses = flwor->num_clauses();

  for (ulong i = 0; i < numClauses; ++i)
  {
    bool merge = false;
    flwor_expr_t nestedFlwor;
    ulong numNestedClauses;

    flwor_clause* c = flwor->get_clause(i);

    expr* domainExpr = c->get_expr();

    if (domainExpr != NULL && domainExpr->get_expr_kind() == flwor_expr_kind)
    {
      nestedFlwor = static_cast<flwor_expr*>(c->get_expr());
      numNestedClauses = nestedFlwor->num_clauses();

      if (c->get_kind() == flwor_clause::let_clause)
      {
        merge = true;

        for (ulong j = 0; j < numNestedClauses; ++j)
        {
          flwor_clause* nestedClause = nestedFlwor->get_clause(j);
          flwor_clause::ClauseKind nestedClauseKind = nestedClause->get_kind();

          if (nestedClauseKind == flwor_clause::for_clause)
          {
            xqtref_t nestedDomainType = nestedClause->get_expr()->get_return_type();

            if (nestedDomainType->get_quantifier() != TypeConstants::QUANT_ONE)
            {
              merge = false;
              break;
            }
          }
          else if (nestedClauseKind != flwor_clause::let_clause)
          {
            merge = false;
            break;
          }
        }
      }
      else if (c->get_kind() == flwor_clause::for_clause &&
               c->get_pos_var() == NULL)
      {
        merge = true;

        for (ulong j = 0; j < numNestedClauses; ++j)
        {
          flwor_clause* nestedClause = nestedFlwor->get_clause(j);
          flwor_clause::ClauseKind nestedClauseKind = nestedClause->get_kind();

          if (nestedClauseKind != flwor_clause::let_clause &&
              nestedClauseKind != flwor_clause::for_clause)
          {
#if 1
            // temp hack until we have an optimized general flwor
            if (nestedClauseKind == flwor_clause::where_clause &&
                i == numClauses-1 &&
                flwor->get_where() == NULL &&
                nestedFlwor->get_return_expr()->get_var() != NULL)
            {
              continue;
            }
#endif
            merge = false;
            break;
          }
        }
      }
    }

    if (merge)
    {
      for (ulong j = 0; j < numNestedClauses; ++j)
      {
        flwor_clause* nestedClause = nestedFlwor->get_clause(j);
#if 1
        if (nestedClause->get_kind() == flwor_clause::where_clause)
          flwor->add_clause(i+j+1, nestedClause);
        else
#endif
          flwor->add_clause(i+j, nestedClause);
      }

      c->set_expr(nestedFlwor->get_return_expr());

      numClauses += numNestedClauses;
      i += numNestedClauses;

      modified = true;
    }
  }
#endif

  return (modified ? node : NULL);
}


RULE_REWRITE_POST(MergeFLWOR)
{
  return NULL;
}


}
/* vim:set ts=2 sw=2: */
