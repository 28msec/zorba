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
#include "stdafx.h"

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

#include "diagnostics/xquery_warning.h"
#include "diagnostics/assert.h"

#include <memory>
#include <iterator>

namespace zorba
{

static void 
collect_flw_vars(const flwor_expr&, expr::FreeVars&);

static bool is_trivial_expr(const expr*);

static bool 
safe_to_fold_single_use(var_expr*, TypeConstants::quantifier_t, const flwor_expr&);

static bool 
var_in_try_or_loop(const var_expr*, const expr*, bool, bool, bool&);

static void 
rewrite_positional_pred(
    RewriterContext&,
    const flwor_expr*,
    var_expr*,
    expr*,
    CompareConsts::CompareType&);

static bool 
is_positional_pred(
    const flwor_expr*,
    csize,
    const expr*,
    var_expr*&,
    expr*&,
    CompareConsts::CompareType&);


#define MODIFY( expr ) do { modified = true; expr; } while (0)


/******************************************************************************

*******************************************************************************/
static void fix_if_annotations(if_expr* ifExpr)
{
  expr_tools::fix_annotations(ifExpr, ifExpr->get_cond_expr());
  expr_tools::fix_annotations(ifExpr, ifExpr->get_then_expr());
  expr_tools::fix_annotations(ifExpr, ifExpr->get_else_expr());
}


/*****************************************************************************

******************************************************************************/
class SubstVars : public PrePostRewriteRule
{
protected:
  const var_expr     * theVarExpr;
  expr               * theSubstExpr;
  std::vector<expr*>   thePath;

public:
  SubstVars(const var_expr* var, expr* subst)
    :
    PrePostRewriteRule(RewriteRule::SubstVars, "SubstVars"),
    theVarExpr(var),
    theSubstExpr(subst)
  {
  }

protected:
  expr* rewritePre(expr* node, RewriterContext& rCtx);
  expr* rewritePost(expr* node, RewriterContext& rCtx);
};


RULE_REWRITE_PRE(SubstVars)
{
  thePath.push_back(node);

  if (node == theVarExpr)
  {
    std::vector<expr*>::iterator ite = thePath.begin();
    std::vector<expr*>::iterator end = thePath.end();
    for (; ite != end; ++ite)
    {
      expr::FreeVars& vars = (*ite)->getFreeVars();
      vars.erase(theVarExpr);
      vars.insert(theSubstExpr->getFreeVars().begin(),
                  theSubstExpr->getFreeVars().end());
    }

    return theSubstExpr;
  }
  else
  {
    return NULL;
  }
}


RULE_REWRITE_POST(SubstVars)
{
  thePath.pop_back();
  return NULL;
}


/******************************************************************************
  Replace all references to var "var" inside the expr "root" with expr "subst"
********************************************************************************/
expr* subst_vars(
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


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  EliminateUnusedLetVars                                                    //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

*******************************************************************************/
RULE_REWRITE_PRE(EliminateUnusedLetVars)
{
  if (node->get_expr_kind() != flwor_expr_kind &&
      node->get_expr_kind() != gflwor_expr_kind)
    return NULL;

  const QueryLoc& loc = node->get_loc();
  static_context* sctx = node->get_sctx();

  flwor_expr* flworp = static_cast<flwor_expr *>(node);
  flwor_expr& flwor = *flworp;

  csize numClauses = flwor.num_clauses();

  // numClauses may be 0 in the case this flwor became a common sub-expression
  // due to var-inlining inside an if-then-else expr (see test
  // zorba/optim/flwor_vars_02.xq)
  if (numClauses == 0)
  {
    return flwor.get_return_expr();
  }

  // "for $x in E return $x"  --> "E"
  // "let $x := E return $x"  --> "E"
  // Single windowing clauses are left alone
  if (numClauses == 1 &&
      flwor.get_clause(0)->get_kind() != flwor_clause::window_clause)
  {
    assert(flwor.get_clause(0)->get_kind() == flwor_clause::for_clause ||
           flwor.get_clause(0)->get_kind() == flwor_clause::let_clause);

    const forletwin_clause* flwc =
    static_cast<const forletwin_clause *>(flwor.get_clause(0));

    if (flwor.get_return_expr()->get_var() == flwc->get_var())
    {
      return flwc->get_expr();
    }
  }

  // "for $x in ... where E ... return ...", and E doesn't depend on FLWOR vars
  // --> "if E then flwor else ()", where flwor is the original flwor expr
  // without the where clause.
  if (!flwor.has_sequential_clauses())
  {
    expr::FreeVars myVars;
    expr* whereExpr = NULL;

    for (csize i = 0; i < numClauses; ++i)
    {
      flwor_clause* clause = flwor.get_clause(i);

      if (clause->get_kind() == flwor_clause::where_clause)
      {
        whereExpr = clause->get_expr();
        const expr::FreeVars& whereVars = whereExpr->getFreeVars();

        if (myVars.empty())
          collect_flw_vars(flwor, myVars);

        expr::FreeVars diff;
        std::set_intersection(myVars.begin(),
                              myVars.end(),
                              whereVars.begin(),
                              whereVars.end(),
                              std::inserter(diff, diff.begin()));
        if (diff.empty())
        {
          flwor.remove_where_clause();

          if_expr* ifExpr = rCtx.theEM->
          create_if_expr(sctx,
                         loc,
                         whereExpr,
                         flworp,
                         rCtx.theEM->create_seq(sctx, loc));
          
          fix_if_annotations(ifExpr);
          
          return ifExpr;
        }
      }
    }
  }

  bool modified = false;

  // (a) Remove, if possible, FOR/LET vars that are not referenced anywhere
  // (b) Replace, if possible, FOR/LET vars that are referenced only once, with
  //     their domain expr.
  // (c) Change a LET var into a FOR var, if its domain expr consists of
  //     exactly one item.
  // (d) Remove any unused non-group variables from GROUP BY clauses.
  for (csize i = 0; i < numClauses; ++i)
  {
    bool substitute = false;

    flwor_clause* c = flwor.get_clause(i);

    if (c->get_kind() == flwor_clause::group_clause)
    {
      group_clause* gc = static_cast<group_clause *>(c);

      flwor_clause::rebind_list_t::iterator ite = gc->beginNonGroupVars();
      flwor_clause::rebind_list_t::iterator end = gc->endNonGroupVars();

      for(; ite != end; ++ite)
      {
        var_expr* var = ite->second;
        int uses = expr_tools::count_variable_uses(&flwor, var, 2);

        if (uses == 0 && !ite->first->isNonDiscardable())
        {
          gc->removeNonGroupingVar(ite);
          --ite;
          end = gc->endNonGroupVars();
        }
      }
    }
    else if (c->get_kind() == flwor_clause::for_clause)
    {
      for_clause* fc = static_cast<for_clause *>(c);

      expr* domainExpr = fc->get_expr();
      xqtref_t domainType = domainExpr->get_return_type();
      var_expr* var = fc->get_var();
      TypeConstants::quantifier_t domainQuant = domainType->get_quantifier();
      ulong domainCount = domainType->max_card();
      const var_expr* pvar = fc->get_pos_var();

      if (pvar != NULL &&
          expr_tools::count_variable_uses(&flwor, pvar, 1) == 0)
      {
        fc->set_pos_var(NULL);
        pvar = NULL;
      }

      // Cannot inline a FOR var whose domain is a sequential expr or
      // might contain more than 1 items.
      if (domainExpr->is_sequential() || domainCount > 1)
        continue;

      // FOR clause with 0 cardinality
      if (domainCount == 0)
      {
        if (! fc->is_allowing_empty())
        {
          return rCtx.theEM->create_seq(sctx, LOC(node));
        }
        else
        {
          if (pvar != NULL)
          {
            expr* constExpr = rCtx.theEM->
            create_const_expr(sctx, loc, xs_integer::zero());

            MODIFY(subst_vars(rCtx, node, pvar, constExpr));
            fc->set_pos_var(NULL);
          }

          expr* emptyExpr = rCtx.theEM->create_seq(sctx, LOC(node));
          MODIFY(subst_vars(rCtx, node, var, emptyExpr));
          substitute = true;
        }
      }

      // FOR clause with cardinality 0 or 1
      else
      {
        if (pvar != NULL)
        {
          if (domainQuant == TypeConstants::QUANT_ONE || 
              ! fc->is_allowing_empty())
          {
            expr* constExpr = rCtx.theEM->
            create_const_expr(sctx, loc, xs_integer::one());

            MODIFY(subst_vars(rCtx, node, pvar, constExpr));
            fc->set_pos_var(NULL);
          }
        }

        int uses = expr_tools::count_variable_uses(&flwor, var, 2);

        if (uses > 1 &&
            is_trivial_expr(domainExpr) &&
            (domainQuant == TypeConstants::QUANT_ONE ||
             fc->is_allowing_empty()))
        {
          subst_vars(rCtx, node, var, domainExpr);
          substitute = true;
        }
        else if (uses == 1 &&
                 (domainQuant == TypeConstants::QUANT_ONE || i == numClauses -1) &&
                 ((is_trivial_expr(domainExpr) &&
                   domainQuant == TypeConstants::QUANT_ONE) ||
                  safe_to_fold_single_use(var, domainQuant, flwor)))
        {
          subst_vars(rCtx, node, var, domainExpr);
          substitute = true;
        }
        else if (uses == 0 &&
                 !domainExpr->isNonDiscardable() &&
                 (domainQuant == TypeConstants::QUANT_ONE ||
                  fc->is_allowing_empty()))
        {
          substitute = true;
        }
      }

      if (substitute)
      {
        MODIFY(flwor.remove_clause(i));
        --numClauses;
        --i;

        flwor.compute_return_type(true, NULL);
      }
    }
    else if (c->get_kind() == flwor_clause::let_clause)
    {
      let_clause* lc = static_cast<let_clause *>(c);

      expr* domainExpr = lc->get_expr();
      xqtref_t domainType = domainExpr->get_return_type();
      TypeConstants::quantifier_t domainQuant = domainType->get_quantifier();
      var_expr* var = lc->get_var();

      if (domainExpr->is_sequential())
        continue;

      int uses = expr_tools::count_variable_uses(&flwor, var, 2);

      if (uses > 1 && is_trivial_expr(domainExpr))
      {
        subst_vars(rCtx, node, var, domainExpr);
        substitute = true;
      }
      else if (uses == 1 &&
               (is_trivial_expr(domainExpr) ||
                safe_to_fold_single_use(var, TypeConstants::QUANT_ONE, flwor)))
      {
        subst_vars(rCtx, node, var, domainExpr);
        substitute = true;
      }
      else if (uses == 0 && !domainExpr->isNonDiscardable())
      {
        substitute = true;
#if 0
        rCtx.getCompilerCB()->theXQueryDiagnostics->add_warning(
          NEW_XQUERY_WARNING(zwarn::ZWST0001_UNUSED_VARIABLE,
          WARN_PARAMS(var->get_name()->getStringValue()),
          WARN_LOC(var->get_loc())));
#endif
      }

      if (substitute)
      {
        MODIFY(flwor.remove_clause(i));
        --numClauses;
        --i;
      }
      else if (domainQuant == TypeConstants::QUANT_ONE)
      {
        MODIFY(flwor.remove_clause(i));
        const QueryLoc& loc = var->get_loc();
        var_expr* fvar = rCtx.theEM->
        create_var_expr(sctx, loc, var_expr::for_var, var->get_name());

        fvar->getFreeVars().insert(fvar);

        for_clause* fc = rCtx.theEM->
        create_for_clause(sctx, loc, fvar, domainExpr);

        flwor.add_clause(i, fc);

        subst_vars(rCtx, node, var, fvar);
      }
    }
  }

  expr* whereCond = NULL;

  while (flwor.num_clauses() > 0)
  {
    flwor_clause* clause = flwor.get_clause(0);

    if (clause->get_kind() == flwor_clause::for_clause ||
        clause->get_kind() == flwor_clause::let_clause ||
        clause->get_kind() == flwor_clause::window_clause)
    {
      break;
    }
    else if (clause->get_kind() == flwor_clause::group_clause)
    {
      group_clause* gc = static_cast<group_clause*>(clause);

      const flwor_clause::rebind_list_t& gVars = gc->get_grouping_vars();

      flwor_clause::rebind_list_t::const_iterator ite = gVars.begin();
      flwor_clause::rebind_list_t::const_iterator end = gVars.end();

      for (; ite != end; ++ite)
      {
        var_expr* gVar = ite->second;
        expr* inputExpr = ite->first;

        let_clause* letClause = rCtx.theEM->
        create_let_clause(sctx, gVar->get_loc(), gVar, inputExpr);

        flwor.add_clause(1, letClause);
      }

      const flwor_clause::rebind_list_t& ngVars = gc->get_nongrouping_vars();

      ite = ngVars.begin();
      end = ngVars.end();

      for (; ite != end; ++ite)
      {
        var_expr* ngVar = ite->second;
        expr* inputExpr = ite->first;

        let_clause* letClause = rCtx.theEM->
        create_let_clause(sctx, ngVar->get_loc(), ngVar, inputExpr);

        flwor.add_clause(1, letClause);
      }

      flwor.remove_clause(0);
      continue;
    }
    else if (clause->get_kind() == flwor_clause::where_clause)
    {
      expr* whereExpr = clause->get_expr();

      //TODO: Consider case where both whereExpr and whereCond ar AND ops
      if (whereCond == NULL)
      {
        whereCond = whereExpr;
      }
      else if (whereCond->get_function_kind() == FunctionConsts::OP_AND_N)
      {
        static_cast<fo_expr*>(whereCond)->add_arg(whereExpr);
      }
      else if (whereExpr->get_function_kind() == FunctionConsts::OP_AND_N)
      {
        static_cast<fo_expr*>(whereExpr)->add_arg(whereCond);
      }
      else
      {
        whereCond = rCtx.theEM->
        create_fo_expr(sctx,
                       whereCond->get_loc(),
                       GET_BUILTIN_FUNCTION(OP_AND_N),
                       whereExpr,
                       whereCond);
      }

      //as soon as whereCond is not NULL we don't need to mark as modified
      flwor.remove_clause(0);
      continue;
    }
    else if (clause->get_kind() == flwor_clause::count_clause)
    {
      // since one value is still returned, count variables are changed to 1
      subst_vars(rCtx,
                 flworp,
                 static_cast<count_clause*>(clause)->get_var(),
                 rCtx.theEM->create_const_expr(sctx, loc, xs_integer::one()));

      flwor.remove_clause(0);
      continue;
    }
    else if (clause->get_kind() == flwor_clause::order_clause)
    {
      flwor.remove_clause(0);
      continue;
    }
    else if (clause->get_kind() == flwor_clause::materialize_clause)
    {
      flwor.remove_clause(0);
      continue;
    }
    else
    {
      ZORBA_ASSERT(false);
    }
  }

  if (whereCond != NULL)
  {
    expr* result = (flwor.num_clauses() > 0 ? flworp : flwor.get_return_expr());

    if_expr* ifExpr = rCtx.theEM->
    create_if_expr(sctx,
                   whereCond->get_loc(),
                   whereCond,
                   result,
                   rCtx.theEM->create_seq(sctx, whereCond->get_loc()));

    fix_if_annotations(ifExpr);

    return ifExpr;
  }

  if (flwor.num_clauses() == 0)
    return flwor.get_return_expr();

  return modified ? node : NULL;
}


RULE_REWRITE_POST(EliminateUnusedLetVars)
{
  return NULL;
}


/*****************************************************************************
  Returns a set containing all the variables defined by the clauses of a flwor
  expr.
******************************************************************************/
static void collect_flw_vars(const flwor_expr& flwor, expr::FreeVars& vars)
{
  for (csize i = 0; i < flwor.num_clauses(); ++i)
  {
    const flwor_clause& c = *flwor.get_clause(i);

    switch (c.get_kind())
    {
    case flwor_clause::for_clause:
    {
      const for_clause* fc = static_cast<const for_clause *>(&c);

      vars.insert(fc->get_var());

      if (fc->get_pos_var() != NULL)
        vars.insert(fc->get_pos_var());

      break;
    }
    case flwor_clause::let_clause:
    {
      const let_clause* lc = static_cast<const let_clause *>(&c);
      vars.insert(lc->get_var());
      break;
    }
    case flwor_clause::window_clause:
    {
      const window_clause* wc = static_cast<const window_clause *>(&c);

      vars.insert(wc->get_var());

      if (wc->get_win_start() != NULL)
      {
        const flwor_wincond* cond = wc->get_win_start();
        const flwor_wincond::vars& condvars = cond->get_out_vars();

        if (condvars.posvar != NULL) vars.insert(condvars.posvar);
        if (condvars.curr != NULL) vars.insert(condvars.curr);
        if (condvars.prev != NULL) vars.insert(condvars.prev);
        if (condvars.next != NULL) vars.insert(condvars.next);
      }

      if (wc->get_win_stop() != NULL)
      {
        const flwor_wincond* cond = wc->get_win_stop();
        const flwor_wincond::vars& condvars = cond->get_out_vars();

        if (condvars.posvar != NULL) vars.insert(condvars.posvar);
        if (condvars.curr != NULL) vars.insert(condvars.curr);
        if (condvars.prev != NULL) vars.insert(condvars.prev);
        if (condvars.next != NULL) vars.insert(condvars.next);
      }

      break;
    }
    case flwor_clause::group_clause:
    {
      const group_clause* gc = static_cast<const group_clause *>(&c);

      flwor_clause::rebind_list_t::const_iterator ite = gc->beginGroupVars();
      flwor_clause::rebind_list_t::const_iterator end = gc->endGroupVars();

      for (; ite != end; ++ite)
      {
        vars.insert((*ite).second);
      }

      ite = gc->beginNonGroupVars();
      end = gc->endNonGroupVars();

      for (; ite != end; ++ite)
      {
        vars.insert((*ite).second);
      }

      break;
    }
    case flwor_clause::count_clause:
    {
      const count_clause* cc = static_cast<const count_clause *>(&c);
      vars.insert(cc->get_var());
      break;
    }
    default:
      break;
    }
  }
}


/******************************************************************************

******************************************************************************/
static bool is_trivial_expr(const expr* e)
{
  switch (e->get_expr_kind())
  {
  case const_expr_kind:
  {
    return true;
  }
  case var_expr_kind:
  {
    const var_expr* ve = static_cast<const var_expr*>(e);
    enum var_expr::var_kind k = ve->get_kind();

    // NOTE: An arg var is not materialized, and as a result, it cannot be
    // referenced more than once or be refeneced inside a loop or try block.
    // Therefore, an arg var that appears as the domain expr of a LET var
    // cannot trivially substitute the LET var.
    if (k == var_expr::arg_var ||
        k == var_expr::local_var ||
        (k == var_expr::prolog_var && ve->is_mutable()))
      return false;

    return true;
  }
  case wrapper_expr_kind:
  {
    return is_trivial_expr(static_cast<const wrapper_expr*>(e)->get_expr());
  }
  default:
    return false;
  }
}


/*****************************************************************************
  Check if it is OK to fold (inline) a FOR/LET var X that we know is referenced
  only once withing its flwor expr.

  For a LET var, varQuant is always QUANT_ONE.

  For a FOR var, varQuant is the quantifier of the type of the domain expr.
  It can be either QUANT_ONE or QUANT_QUESTION.
******************************************************************************/
static bool safe_to_fold_single_use(
    var_expr* var,
    TypeConstants::quantifier_t varQuant,
    const flwor_expr& flwor)
{
  TypeManager* tm = var->get_type_manager();

  bool declared = false;
  expr* referencingExpr = NULL;

  bool hasNodeConstr = var->get_domain_expr()->contains_node_construction();

  csize numClauses = flwor.num_clauses();

  for (csize i = 0; i < numClauses && referencingExpr == NULL; ++i)
  {
    const flwor_clause* clause = flwor.get_clause(i);
    flwor_clause::ClauseKind kind = clause->get_kind();

    switch (kind)
    {
    case flwor_clause::for_clause:
    case flwor_clause::let_clause:
    {
      const forletwin_clause* flc = static_cast<const forletwin_clause *>(clause);
      var_expr* varExpr = flc->get_var();
      expr* domExpr = flc->get_expr();

      if (! declared)
      {
        declared = (varExpr == var);
        continue;
      }

      assert(varQuant == TypeConstants::QUANT_ONE);

      if (domExpr->is_sequential())
        return false;

      // If X is referenced in the current FOR clause .....
      if (expr_tools::count_variable_uses(domExpr, var, 1) == 1)
      {
        referencingExpr = domExpr;
        break;
      }

      // If X is referenced after this FOR clause. In this case, we don't want
      // to inline X because its domain expr will be computed once per iteration
      // instead of just once.
      if (kind == flwor_clause::for_clause &&
          domExpr->get_return_type()->max_card() >= 2)
        return false;

      // test rbkt/zorba/extern/5890.xq illustrates why this check is needed
      //if (hasNodeConstr && fc.get_expr()->contains_node_construction())
      //  return false;

      break;
    }
    case flwor_clause::where_clause:
    {
      if (!declared)
        continue;

      assert(varQuant == TypeConstants::QUANT_ONE);

      if (expr_tools::count_variable_uses(clause->get_expr(), var, 1) == 1)
      {
        referencingExpr = clause->get_expr();
        break;
      }

      break;
    }
    case flwor_clause::order_clause:
    {
      if (!declared)
        continue;

      assert(varQuant == TypeConstants::QUANT_ONE);

      const orderby_clause* oc = static_cast<const orderby_clause*>(clause);

      std::vector<expr*>::const_iterator ite = oc->begin();
      std::vector<expr*>::const_iterator end = oc->end();

      for (; ite != end; ++ite)
      {
        if (expr_tools::count_variable_uses(*ite, var, 1) == 1)
        {
          referencingExpr = *ite;
          break;
        }
      }

      break;
    }
    case flwor_clause::group_clause:
    {
      if (!declared)
        continue;

      assert(varQuant == TypeConstants::QUANT_ONE);

      const group_clause* gc = static_cast<const group_clause*>(clause);

      flwor_clause::rebind_list_t::const_iterator ite = gc->beginGroupVars();
      flwor_clause::rebind_list_t::const_iterator end = gc->endGroupVars();

      for (; ite != end; ++ite)
      {
        expr* inputExpr = ite->first;
        if (expr_tools::count_variable_uses(inputExpr, var, 1) == 1)
        {
          referencingExpr = inputExpr;
          break;
        }
      }

      ite = gc->beginNonGroupVars();
      end = gc->endNonGroupVars();

      for (; ite != end; ++ite)
      {
        expr* inputExpr = ite->first;
        if (expr_tools::count_variable_uses(inputExpr, var, 1) == 1)
        {
          referencingExpr = inputExpr;
          break;
        }
      }

      break;
    }
    case flwor_clause::window_clause:
    {
      if (!declared)
        continue;

      assert(varQuant == TypeConstants::QUANT_ONE);

      const window_clause* wc = static_cast<const window_clause*>(clause);
      expr* domExpr = wc->get_expr();
      flwor_wincond* startCond = wc->get_win_start();
      flwor_wincond* stopCond = wc->get_win_stop();
      expr* startExpr = (startCond == NULL ? NULL : startCond->get_cond());
      expr* stopExpr = (stopCond == NULL ? NULL : stopCond->get_cond());

      if (domExpr->is_sequential())
        return false;

      if (expr_tools::count_variable_uses(domExpr, var, 1) == 1)
      {
        referencingExpr = domExpr;
        break;
      }

      if (domExpr->get_return_type()->max_card() > 1)
        return false;

      if (expr_tools::count_variable_uses(startExpr, var, 1) == 1)
      {
        referencingExpr = domExpr;
        break;
      }

      if (expr_tools::count_variable_uses(stopExpr, var, 1) == 1)
      {
        referencingExpr = domExpr;
        break;
      }

      break;
    }
    case flwor_clause::materialize_clause:
    {
      return false;
    }
    case flwor_clause::count_clause:
    {
      break;
    }
    default:
    {
      ZORBA_ASSERT(false);
    }
    }
  }

  if (referencingExpr == NULL)
  {
    expr* retExpr = flwor.get_return_expr();

    if (retExpr->is_sequential())
      return false;

    if (expr_tools::count_variable_uses(retExpr, var, 1) == 1)
    {
      if (varQuant != TypeConstants::QUANT_ONE)
      {
        // We are considering folding a FOR var whose domain expr may be the
        // empty sequence. We can fold only if doing so will cause the result
        // of the flwor expr to be the empty sequence in the case where the
        // domain expr will indeed be equal to the empty sequence.
        xqtref_t type = retExpr->get_return_type_with_empty_input(var);

        if (TypeOps::is_equal(tm, *type, *GENV_TYPESYSTEM.EMPTY_TYPE, retExpr->get_loc()))
        {
          referencingExpr = retExpr;
        }
        else
        {
          return false;
        }
      }
      else
      {
        referencingExpr = retExpr;
      }
    }
  }

  assert(referencingExpr != NULL);

  if (referencingExpr == NULL)
    return false;

  bool found = false;
  return !var_in_try_or_loop(var, referencingExpr, false, hasNodeConstr, found);
}


/*******************************************************************************
  Given a variable V and an expression E that references V exactly once, return
  true if the reference occurs inside a
  (a) for-loop within E, or
  (b) try expr within E, or
  (c) while expr within E

  The method traverses recursively the subtree of E looking for variable V and
  checking whether it crosses a loop or try expr. If it finds V and there is a
  loop or try expr in the path from E to V, it returns true; otherwise it returns
  false.

  Note: On the 1st (non-recursive) call, we know that E references V exactly
  once. But during a recursive call on a subexpr, the subexpr may or may not
  reference V.
********************************************************************************/
static bool var_in_try_or_loop(
    const var_expr* v,
    const expr* e,
    bool inTryOrLoop,
    bool hasNodeConstr,
    bool& found)
{
  if (found)
    return false;

  expr_kind_t kind = e->get_expr_kind();

  if (kind == trycatch_expr_kind)
  {
    const trycatch_expr* tce = static_cast<const trycatch_expr *>(e);

    if (var_in_try_or_loop(v, tce->get_try_expr(), true, hasNodeConstr, found))
    {
      assert(found);
      return true;
    }

    ZORBA_ASSERT(!found);

    csize numClauses = tce->clause_count();

    for (csize i = 0; i < numClauses; ++i)
    {
      if (var_in_try_or_loop(v,
                             tce->get_catch_expr(i),
                             inTryOrLoop, 
                             hasNodeConstr,
                             found))
      {
        assert(found);
        return true;
      }
    }

    return false;
  }
  else if (kind == while_expr_kind)
  {
    const while_expr* we = static_cast<const while_expr *>(e);

    if (var_in_try_or_loop(v, we->get_body(), true, hasNodeConstr, found))
    {
      assert(found);
      return true;
    }

    ZORBA_ASSERT(!found);

    return false;
  }
  else if (kind == flwor_expr_kind || kind == gflwor_expr_kind)
  {
    const flwor_expr& flwor = *static_cast<const flwor_expr *>(e);

    for (csize i = 0; i < flwor.num_clauses(); ++i)
    {
      const flwor_clause* c = flwor.get_clause(i);

      switch (c->get_kind())
      {
      case flwor_clause::for_clause:
      case flwor_clause::let_clause:
      {
        const forletwin_clause* flc = static_cast<const forletwin_clause*>(c);
        expr* domExpr = flc->get_expr();

        if (var_in_try_or_loop(v, domExpr, inTryOrLoop, hasNodeConstr, found))
        {
          assert(found);
          return true;
        }

        if (found)
          return false;

        if (c->get_kind() == flwor_clause::for_clause &&
            domExpr->get_return_type()->max_card() >= 2)
        {
          inTryOrLoop = true;
        }

        // test rbkt/zorba/extern/5890.xq illustrates why this check is needed
        //if (hasNodeConstr && domExpr->contains_node_construction())
        //{
        //  return true;
        //}

        break;
      }
      case flwor_clause::window_clause:
      {
        const window_clause* wc = static_cast<const window_clause*>(c);
        expr* domExpr = wc->get_expr();

        if (var_in_try_or_loop(v, domExpr, inTryOrLoop, hasNodeConstr, found))
        {
          assert(found);
          return true;
        }

        if (found)
          return false;

        inTryOrLoop = true;

        flwor_wincond* startCond = wc->get_win_start();
        flwor_wincond* stopCond = wc->get_win_stop();
        expr* startExpr = startCond == NULL ? NULL : startCond->get_cond();
        expr* stopExpr = stopCond == NULL ? NULL : stopCond->get_cond();

        if (startExpr &&
            var_in_try_or_loop(v, startExpr, inTryOrLoop, hasNodeConstr, found))
        {
          assert(found);
          return true;
        }

        if (found)
          return false;

        if (stopExpr &&
            var_in_try_or_loop(v, stopExpr, inTryOrLoop, hasNodeConstr, found))
        {
          assert(found);
          return true;
        }

        if (found)
          return false;

        break;
      }
      case flwor_clause::group_clause:
      {
        const group_clause* gc = static_cast<const group_clause*>(c);

        flwor_clause::rebind_list_t::const_iterator ite = gc->beginGroupVars();
        flwor_clause::rebind_list_t::const_iterator end = gc->endGroupVars();

        for (; ite != end; ++ite)
        {
          expr* gExpr = (*ite).first;

          if (var_in_try_or_loop(v, gExpr, inTryOrLoop, hasNodeConstr, found))
          {
            assert(found);
            return true;
          }

          if (found)
            return false;
        }

        ite = gc->beginNonGroupVars();
        end = gc->endNonGroupVars();

        for (; ite != end; ++ite)
        {
          expr* ngExpr = (*ite).first;

          if (var_in_try_or_loop(v, ngExpr, inTryOrLoop, hasNodeConstr, found))
          {
            assert(found);
            return true;
          }

          if (found)
            return false;
        }

        break; // TODO
      }
      case flwor_clause::where_clause:
      {
        const where_clause* wc = static_cast<const where_clause*>(c);

        if (var_in_try_or_loop(v, wc->get_expr(), inTryOrLoop, hasNodeConstr, found))
        {
          assert(found);
          return true;
        }

        if (found)
          return false;

        break;
      }
      case flwor_clause::order_clause:
      {
        const orderby_clause* oc = static_cast<const orderby_clause*>(c);

        std::vector<expr*>::const_iterator ite = oc->begin();
        std::vector<expr*>::const_iterator end = oc->end();

        for (; ite != end; ++ite)
        {
          if (var_in_try_or_loop(v, *ite, inTryOrLoop, hasNodeConstr, found))
          {
            assert(found);
            return true;
          }
          
          if (found)
            return false;
        }

        break;
      }
      case flwor_clause::count_clause:
      {
        break;
      }
      case flwor_clause::materialize_clause:
      {
        ZORBA_ASSERT(false);
      }
      default:
      {
        ZORBA_ASSERT(false);
      }
      }
    }

    return var_in_try_or_loop(v,
                              flwor.get_return_expr(),
                              inTryOrLoop,
                              hasNodeConstr,
                              found);
  }
  else if (e == v)
  {
    found = true;
    return inTryOrLoop;
  }
  else if (kind == if_expr_kind)
  {
    const if_expr* ifExpr = static_cast<const if_expr*>(e);
    const expr* condExpr = ifExpr->get_cond_expr();

    if (var_in_try_or_loop(v, condExpr, inTryOrLoop, hasNodeConstr, found))
      return true;

    if (found)
      return false;

    // The var may actually be referenced in both the then and the else branches.
    // So, if we find it in the then branch and is not in try-or-loop in there,
    // we must still check the else branch.

    bool thenFound = false;
    bool elseFound = false;
    const expr* thenExpr = ifExpr->get_then_expr();
    const expr* elseExpr = ifExpr->get_else_expr();

    if (var_in_try_or_loop(v, thenExpr, inTryOrLoop, hasNodeConstr, thenFound))
    {
      assert(thenFound);
      found = true;
      return true;
    }

    if (var_in_try_or_loop(v, elseExpr, inTryOrLoop, hasNodeConstr, elseFound))
    {
      assert(elseFound);
      found = true;
      return true;
    }

    found = (thenFound || elseFound);
    return false;
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
  while (!ei.done())
  {
    if (var_in_try_or_loop(v, ei.get_expr(), inTryOrLoop, hasNodeConstr, found))
    {
      return true;
    }

    if (found)
      return false;

    ei.next();
  }

  return false;
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  RefactorPredFLWOR                                                         //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/******************************************************************************
  This is a rule that is being applied by the FoldRules driver (see class
  FoldRules in default_optimizer.cpp).
******************************************************************************/
RULE_REWRITE_PRE(RefactorPredFLWOR)
{
  if (node->get_expr_kind() != flwor_expr_kind &&
      node->get_expr_kind() != gflwor_expr_kind)
  {
    return NULL;
  }

  bool modified = false;
  flwor_expr* flwor = static_cast<flwor_expr*>(node);

  static_context* sctx = flwor->get_sctx();

  // "for $x in ... return if (ce) then te else ()" -->
  // "for $x in ... where ce return te"
  if (flwor->get_return_expr()->get_expr_kind() == if_expr_kind)
  {
    if_expr* ifReturnExpr = static_cast<if_expr*>(flwor->get_return_expr());

    expr* condExpr = ifReturnExpr->get_cond_expr();
    expr* thenExpr = ifReturnExpr->get_then_expr();
    expr* elseExpr = ifReturnExpr->get_else_expr();

    if (!condExpr->is_sequential() &&
        !thenExpr->is_sequential() &&
        (elseExpr->is_simple() || elseExpr->is_vacuous()) &&
        !elseExpr->isNonDiscardable() &&
        elseExpr->get_return_type()->is_empty())
    {
      if (flwor->is_general())
      {
        flwor->add_where(condExpr);
      }
      else
      {
        expr* whereExpr = flwor->get_where();

        if (whereExpr == NULL)
        {
          flwor->set_where(condExpr);
        }
        else if (whereExpr->get_function_kind() == FunctionConsts::OP_AND_N)
        {
          fo_expr* foWhereExpr = static_cast<fo_expr*>(whereExpr);

          if (condExpr->get_function_kind() == FunctionConsts::OP_AND_N)
          {
            fo_expr* foCondExpr = static_cast<fo_expr*>(condExpr);
            foWhereExpr->add_args(foCondExpr->get_args());
          }
          else
          {
            foWhereExpr->add_arg(condExpr);
          }
        }
        else if (condExpr->get_function_kind() == FunctionConsts::OP_AND_N)
        {
          fo_expr* foCondExpr = static_cast<fo_expr*>(condExpr);
          foCondExpr->add_arg(whereExpr);
          flwor->set_where(condExpr);
        }
        else
        {
          expr* newWhereExpr = rCtx.theEM->
          create_fo_expr(sctx,
                         whereExpr->get_loc(),
                         GET_BUILTIN_FUNCTION(OP_AND_N),
                         whereExpr,
                         condExpr);

          flwor->set_where(newWhereExpr);
        }
      }

      flwor->set_return_expr(thenExpr);
      modified = true;
    }
  }

  // '... for $x at $p in E ... where $p = posExpr ... return ...' -->
  // '... for $x in fn:subsequence(E, posExpr, 1) ... return ...
  // TODO ??: we should be able to apply the rule, even if the pos var is
  // referenced more than once?
  // TODO: we should be able to apply the rule if all the sequential clauses
  // are before the clause that defines the pos var.
  // TODO: consider more than one positional preds in CNF
  if (! flwor->has_sequential_clauses())
  {
    csize numClauses = flwor->num_clauses();

    for (csize clausePos = 0; clausePos < numClauses; ++clausePos)
    {
      flwor_clause* clause = flwor->get_clause(clausePos);

      if (clause->get_kind() != flwor_clause::where_clause)
        continue;

      expr* whereExpr = clause->get_expr();

      expr* posExpr = NULL;
      var_expr* posVar = NULL;
      CompareConsts::CompareType compKind;

      FunctionConsts::FunctionKind predFunc = whereExpr->get_function_kind();

      if (predFunc == FunctionConsts::OP_AND_N)
      {
        fo_expr* andExpr = static_cast<fo_expr*>(whereExpr);
        csize numArgs = andExpr->num_args();

        for (csize i = 0; i < numArgs; ++i)
        {
          expr* arg = andExpr->get_arg(i);

          if (is_positional_pred(flwor, clausePos, arg, posVar, posExpr, compKind) &&
              expr_tools::count_variable_uses(flwor, posVar, 2) <= 1)
          {
            rewrite_positional_pred(rCtx, flwor, posVar, posExpr, compKind);

            andExpr->remove_arg(i);

            if (compKind == CompareConsts::GENERAL_EQUAL ||
                compKind == CompareConsts::VALUE_EQUAL)
              modified = true;

            break;
          }
        }

        if (andExpr->num_args() == 1)
        {
          clause->set_expr(andExpr->get_arg(0));
        }
      }
      else
      {
        if (is_positional_pred(flwor, clausePos, whereExpr, posVar, posExpr, compKind) &&
            expr_tools::count_variable_uses(flwor, posVar, 2) <= 1)
        {
          rewrite_positional_pred(rCtx, flwor, posVar, posExpr, compKind);

          flwor->remove_clause(clausePos);
          --clausePos;
          --numClauses;

          if (compKind == CompareConsts::GENERAL_EQUAL ||
              compKind == CompareConsts::VALUE_EQUAL)
            modified = true;
        }
      }
    }
  }

  return (modified ? flwor : NULL);
}


/******************************************************************************

*******************************************************************************/
RULE_REWRITE_POST(RefactorPredFLWOR)
{
  return NULL;
}


/******************************************************************************

*******************************************************************************/
static void rewrite_positional_pred(
    RewriterContext& rCtx,
    const flwor_expr* flworExpr,
    var_expr* posVar,
    expr* posExpr,
    CompareConsts::CompareType& compKind)
{
  static_context* sctx = flworExpr->get_sctx();

  for_clause* forClause = posVar->get_for_clause();
  expr* domainExpr = forClause->get_expr();

  fo_expr* result;

  switch (compKind)
  {
  case CompareConsts::GENERAL_EQUAL:
  case CompareConsts::VALUE_EQUAL:
  {
    result = rCtx.theEM->
    create_fo_expr(sctx,
                   domainExpr->get_loc(),
                   GET_BUILTIN_FUNCTION(OP_ZORBA_SEQUENCE_POINT_ACCESS_2),
                   domainExpr,
                   posExpr);
    break;
  }
  case CompareConsts::GENERAL_LESS_EQUAL:
  case CompareConsts::VALUE_LESS_EQUAL:
  {
    expr* oneExpr = rCtx.theEM->
    create_const_expr(sctx, domainExpr->get_loc(), xs_integer(1));

    std::vector<expr*> args(3);
    args[0] = domainExpr;
    args[1] = oneExpr;
    args[2] = posExpr;

    result = rCtx.theEM->
    create_fo_expr(sctx,
                   domainExpr->get_loc(),
                   GET_BUILTIN_FUNCTION(OP_ZORBA_SUBSEQUENCE_INT_3),
                   args);
    break;
  }
  case CompareConsts::GENERAL_LESS:
  case CompareConsts::VALUE_LESS:
  {
    expr* oneExpr1 = rCtx.theEM->
    create_const_expr(sctx, domainExpr->get_loc(), xs_integer(1));

    expr* oneExpr2 = rCtx.theEM->
    create_const_expr(sctx, domainExpr->get_loc(), xs_integer(1));

    posExpr = rCtx.theEM->
    create_fo_expr(sctx,
                   domainExpr->get_loc(),
                   GET_BUILTIN_FUNCTION(OP_NUMERIC_SUBTRACT_INTEGER_2),
                   posExpr,
                   oneExpr2);

    std::vector<expr*> args(3);
    args[0] = domainExpr;
    args[1] = oneExpr1;
    args[2] = posExpr;
    
    result = rCtx.theEM->
    create_fo_expr(sctx,
                   domainExpr->get_loc(),
                   GET_BUILTIN_FUNCTION(OP_ZORBA_SUBSEQUENCE_INT_3),
                   args);
    break;
  }
  case CompareConsts::GENERAL_GREATER_EQUAL:
  case CompareConsts::VALUE_GREATER_EQUAL:
  {
    result = rCtx.theEM->
    create_fo_expr(sctx,
                   domainExpr->get_loc(),
                   GET_BUILTIN_FUNCTION(OP_ZORBA_SUBSEQUENCE_INT_2),
                   domainExpr,
                   posExpr);
    break;
  }
  case CompareConsts::GENERAL_GREATER:
  case CompareConsts::VALUE_GREATER:
  {
    expr* oneExpr = rCtx.theEM->
    create_const_expr(sctx, domainExpr->get_loc(), xs_integer(1));

    posExpr = rCtx.theEM->
    create_fo_expr(sctx,
                   domainExpr->get_loc(),
                   GET_BUILTIN_FUNCTION(OP_NUMERIC_ADD_INTEGER_2),
                   posExpr,
                   oneExpr);

    result = rCtx.theEM->
    create_fo_expr(sctx,
                   domainExpr->get_loc(),
                   GET_BUILTIN_FUNCTION(OP_ZORBA_SUBSEQUENCE_INT_2),
                   domainExpr,
                   posExpr);
    break;
  }
  default:
  {
    ZORBA_ASSERT(false);
  }
  }
  
  expr_tools::fix_annotations(result);

  forClause->set_expr(result);
  forClause->set_pos_var(NULL);
}


/******************************************************************************
  Checks whether "condExpr" has the form '$posVar op posExpr', where

  (a)  op is eq or =, and
  (b1) posExpr is an integer literal with value >= 1, or
  (b2) the flwor expr has no sequential clauses and posExpr is an expression
       whose type is xs:integer? and which does not reference the for var
       associated with posVar nor any other vars that are defined after that
       for var and
  (c)  there is no count or groupby clause between the for and the where clause
       containing the condExpr and
  (d)  the for clause doesn't allow empty.

  TODO: (b2) can be relaxed somewhat: it is ok if all the sequential clauses
        are before the clause that defines the pos var.
******************************************************************************/
static bool is_positional_pred(
    const flwor_expr* flworExpr,
    const csize whereClausePos,
    const expr* predExpr,
    var_expr*& posVar,
    expr*& posExpr,
    CompareConsts::CompareType& compKind)
{
  static_context* sctx = predExpr->get_sctx();
  TypeManager* tm = sctx->get_typemanager();
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  const fo_expr* foPredExpr = NULL;
  const function* f;

  while (true)
  {
    if (predExpr->get_expr_kind() != fo_expr_kind)
      return false;

    foPredExpr = static_cast<const fo_expr*>(predExpr);
    f = foPredExpr->get_func();

    if (f->getKind() == FunctionConsts::FN_BOOLEAN_1)
    {
      predExpr = foPredExpr->get_arg(0);
      continue;
    }

    break;
  }

  if (!f->isComparisonFunction())
    return false;

  compKind = f->comparisonKind();

  for (csize i = 0; i < 2; ++i)
  {
    posVar = const_cast<var_expr*>(foPredExpr->get_arg(i)->get_var());
    posExpr = foPredExpr->get_arg(1 - i);

    if (posVar == NULL || posVar->get_kind() != var_expr::pos_var)
      continue;

    bool eq = false;

    switch (compKind)
    {
    case CompareConsts::GENERAL_EQUAL:
    case CompareConsts::VALUE_EQUAL:
    {
      eq = true;
      break;
    }
    case CompareConsts::VALUE_LESS:
    case CompareConsts::VALUE_LESS_EQUAL:
    case CompareConsts::GENERAL_LESS:
    case CompareConsts::GENERAL_LESS_EQUAL:
    {
      if (i == 1)
      {
        switch (compKind)
        {
        case CompareConsts::VALUE_LESS:
          compKind = CompareConsts::VALUE_GREATER;
          break;
        case CompareConsts::VALUE_LESS_EQUAL:
          compKind = CompareConsts::VALUE_GREATER_EQUAL;
          break;
        case CompareConsts::GENERAL_LESS:
          compKind = CompareConsts::GENERAL_GREATER;
          break;
        case CompareConsts::GENERAL_LESS_EQUAL:
          compKind = CompareConsts::GENERAL_GREATER_EQUAL;
          break;
        default:
          ZORBA_ASSERT(false);
        }
      }

      break;
    }
    case CompareConsts::VALUE_GREATER:
    case CompareConsts::VALUE_GREATER_EQUAL:
    case CompareConsts::GENERAL_GREATER:
    case CompareConsts::GENERAL_GREATER_EQUAL:
    {
      if (i == 1)
      {
        switch (compKind)
        {
        case CompareConsts::VALUE_GREATER:
          compKind = CompareConsts::VALUE_LESS;
          break;
        case CompareConsts::VALUE_GREATER_EQUAL:
          compKind = CompareConsts::VALUE_LESS_EQUAL;
          break;
        case CompareConsts::GENERAL_GREATER:
          compKind = CompareConsts::GENERAL_LESS;
          break;
        case CompareConsts::GENERAL_GREATER_EQUAL:
          compKind = CompareConsts::GENERAL_LESS_EQUAL;
          break;
        default:
          ZORBA_ASSERT(false);
        }
      }
      break;
    }
    default:
    {
      return false;
    }
    }

    for_clause* forClause = posVar->get_for_clause();

    if (forClause->is_allowing_empty())
      return false;

    // We check that there isn't any clause that breaks the optimization
    const flwor_clause* checkClause;
    csize checkClausePos = whereClausePos - 1;
    do
    {
      checkClause = flworExpr->get_clause(checkClausePos);

      if (checkClause->get_kind() == flwor_clause::group_clause ||
          (checkClause->get_kind() == flwor_clause::count_clause && eq))
        return false;

      --checkClausePos;
    }
    while (checkClause != forClause);

    if (posExpr->get_expr_kind() == const_expr_kind)
    {
      const_expr* posConstExpr = static_cast<const_expr*>(posExpr);
      const store::Item* val = posConstExpr->get_val();

      store::SchemaTypeCode valType = val->getTypeCode();

      if (TypeOps::is_subtype(valType, store::XS_INTEGER))
        return true;
     }
    else
    {
      xqtref_t posExprType = posExpr->get_return_type();
      
      if (TypeOps::is_subtype(tm,
                              *posExprType,
                              *rtm.INTEGER_TYPE_QUESTION,
                              posExpr->get_loc()))
      {
        VarIdMap varidMap;
        ulong numFlworVars = 0;
        expr_tools::index_flwor_vars(flworExpr, numFlworVars, varidMap, NULL);
        
        DynamicBitset varset(numFlworVars);
        ExprVarsMap exprVarMap;
        expr_tools::build_expr_to_vars_map(posExpr, varidMap, varset, exprVarMap);
        
        var_expr* forVar = forClause->get_var();
        ulong forVarId = varidMap[forVar];

        std::vector<ulong> posExprVarIds;
        exprVarMap[posExpr].getSet(posExprVarIds);

        csize numPosExprVars = posExprVarIds.size();
        for (csize i = 0; i < numPosExprVars; ++i)
        {
          if (posExprVarIds[i] >= forVarId)
            return false;
        }
        
        return true;
      }
    }
  }

  return false;
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  MergeFLWOR                                                                //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

*******************************************************************************/
RULE_REWRITE_PRE(MergeFLWOR)
{
  flwor_expr* flwor = dynamic_cast<flwor_expr *>(node);

  if (flwor == NULL)
    return NULL;

  bool modified = false;

  // Try to merge an inner flwor that appears in the return clause of the
  // outer flwor.
  if (flwor->get_return_expr()->get_expr_kind() == flwor_expr_kind &&
      !flwor->get_return_expr()->is_sequential())
  {
    // TODO: If the return clause is sequential, we can still do the merge,
    // but we must keep both the outer and the inner materialize clauses.

    flwor_expr* returnFlwor = static_cast<flwor_expr*>(flwor->get_return_expr());

    // If the outer flwor is not general, and it contains where, groupby, or
    // orderby clauses, we cannot merge because for/let clauses cannot appear
    // after where, groupby, or orderby clauses,
    if (!flwor->is_general())
    {
      csize numClauses = flwor->num_clauses();

      for (csize i = 0; i < numClauses; ++i)
      {
        const flwor_clause* c = flwor->get_clause(i);

        if (c->get_kind() == flwor_clause::where_clause ||
            c->get_kind() == flwor_clause::group_clause ||
            c->get_kind() == flwor_clause::order_clause)
        {
          goto next1;
        }
      }
    }

    csize numClauses = returnFlwor->num_clauses();

    for (csize i = 0; i < numClauses; ++i)
    {
      const flwor_clause* c = returnFlwor->get_clause(i);

      if (c->get_kind() == flwor_clause::group_clause ||
          c->get_kind() == flwor_clause::order_clause)
      {
        goto next1;
      }
    }

    for (csize i = 0; i < numClauses; ++i)
    {
      flwor->add_clause(returnFlwor->get_clause(i));
    }

    flwor->set_return_expr(returnFlwor->get_return_expr());

    modified = true;
  }

 next1:

  csize numClauses = flwor->num_clauses();

  // Try to merge an inner flwor that appears in a for/let clause of the outer
  // flwor.
  for (csize i = 0; i < numClauses; ++i)
  {
    bool merge = false;
    flwor_expr* nestedFlwor = NULL;
    ulong numNestedClauses;

    flwor_clause* c = flwor->get_clause(i);

    expr* domainExpr = c->get_expr();

    if (domainExpr != NULL &&
        domainExpr->get_expr_kind() == flwor_expr_kind &&
        !domainExpr->is_sequential())
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
            xqtref_t nestedDomainType =
              nestedClause->get_expr()->get_return_type();

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

  return (modified ? node : NULL);
}


/******************************************************************************

*******************************************************************************/
RULE_REWRITE_POST(MergeFLWOR)
{
  return NULL;
}


}
/* vim:set et sw=2 ts=2: */
