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
#include "compiler/expression/script_exprs.h"
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

static bool is_trivial_expr(const expr*);

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
  var_expr           * theVarExpr;
  expr               * theSubstExpr;
  std::vector<expr*>   thePath;

public:
  SubstVars(var_expr* var, expr* subst)
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
    var_expr* var,
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
  This is actually 4 rules bundled together:

  1. trivial-FLWOR-elimination :

  "for $x in E return $x"  --> "E"
  "let $x := E return $x"  --> "E"


  2. where-clause-to-if-then-else :

  "for $x in ... where E ... return ...", and E doesn't depend on FLWOR vars -->
  "if E then flwor else ()", where flwor is the original flwor expr without the
  where clause.


  3. LET-FOR-variable-folding-or-elimination :

  4. non-grouping-variable-elimination :

*******************************************************************************/
RULE_REWRITE_PRE(EliminateUnusedLetVars)
{
  if (node->get_expr_kind() != flwor_expr_kind &&
      node->get_expr_kind() != gflwor_expr_kind)
    return NULL;

  const QueryLoc& loc = node->get_loc();
  static_context* sctx = node->get_sctx();
  user_function* udf = node->get_udf();

  assert(udf == rCtx.theUDF);

  theFlwor = static_cast<flwor_expr *>(node);

  csize numClauses = theFlwor->num_clauses();

  // numClauses may be 0 in the case this flwor became a common sub-expression
  // due to var-inlining inside an if-then-else expr (see test
  // zorba/optim/flwor_vars_02.xq)
  if (numClauses == 0)
  {
    return theFlwor->get_return_expr();
  }

  // 1. trivial-FLWOR-elimination
  if (numClauses == 1 &&
      theFlwor->get_clause(0)->get_kind() != flwor_clause::window_clause)
  {
    assert(theFlwor->get_clause(0)->get_kind() == flwor_clause::for_clause ||
           theFlwor->get_clause(0)->get_kind() == flwor_clause::let_clause);

    const forletwin_clause* flwc =
    static_cast<const forletwin_clause *>(theFlwor->get_clause(0));

    if (theFlwor->get_return_expr()->get_var() == flwc->get_var())
    {
      return flwc->get_expr();
    }
  }

  // 2. where-clause-to-if-then-else
  if (!theFlwor->has_sequential_clauses())
  {
    expr* whereExpr = NULL;

    for (csize i = 0; i < numClauses; ++i)
    {
      flwor_clause* clause = theFlwor->get_clause(i);

      if (clause->get_kind() == flwor_clause::where_clause)
      {
        whereExpr = static_cast<where_clause*>(clause)->get_expr();
        const expr::FreeVars& whereVars = whereExpr->getFreeVars();

        csize k = 0;
        expr::FreeVars::const_iterator ite = whereVars.begin();
        expr::FreeVars::const_iterator end = whereVars.end();
        for (; ite != end; ++ite)
        {
          flwor_clause* vc = (*ite)->get_flwor_clause();
          if (vc != NULL && vc->get_flwor_expr() == theFlwor)
            break;

          ++k;
        }

        if (k == whereVars.size())
        {
          theFlwor->remove_clause(i);

          if_expr* ifExpr = rCtx.theEM->
          create_if_expr(sctx,
                         udf,
                         loc,
                         whereExpr,
                         theFlwor,
                         rCtx.theEM->create_seq(sctx, udf, loc));
          
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
    int isReferenced;

    flwor_clause* c = theFlwor->get_clause(i);

    switch (c->get_kind())
    {
    case flwor_clause::group_clause:
    {
      group_clause* gc = static_cast<group_clause *>(c);

      flwor_clause::rebind_list_t::iterator ite = gc->beginNonGroupVars();
      flwor_clause::rebind_list_t::iterator end = gc->endNonGroupVars();

      for(; ite != end; ++ite)
      {
        var_expr* var = ite->second;
        int uses = expr_tools::count_variable_uses(theFlwor, var, 1, NULL);

        if (uses == 0 && !ite->first->isNonDiscardable())
        {
          gc->removeNonGroupingVar(ite);
          --ite;
          end = gc->endNonGroupVars();
        }
      }

      break;
    }
    case flwor_clause::for_clause:
    {
      for_clause* fc = static_cast<for_clause *>(c);

      expr* domainExpr = fc->get_expr();
      xqtref_t domainType = domainExpr->get_return_type();
      var_expr* var = fc->get_var();
      TypeConstants::quantifier_t domainQuant = domainType->get_quantifier();
      ulong domainCount = domainType->max_card();
      var_expr* pvar = fc->get_pos_var();

      if (pvar != NULL &&
          expr_tools::count_variable_uses(theFlwor, pvar, 1, NULL) == 0)
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
          return rCtx.theEM->create_seq(sctx, udf, LOC(node));
        }
        else
        {
          if (pvar != NULL)
          {
            expr* constExpr = rCtx.theEM->
            create_const_expr(sctx, udf, loc, xs_integer::zero());

            MODIFY(subst_vars(rCtx, node, pvar, constExpr));
            fc->set_pos_var(NULL);
          }

          expr* emptyExpr = rCtx.theEM->create_seq(sctx, udf, LOC(node));
          MODIFY(subst_vars(rCtx, node, var, emptyExpr));

          MODIFY(theFlwor->remove_clause(i));
          --numClauses;
          --i;

          theFlwor->compute_return_type(false, NULL);
        }
      }
      // FOR clause with cardinality 0 or 1
      else
      {
        if (pvar != NULL &&
            (domainQuant == TypeConstants::QUANT_ONE || 
             ! fc->is_allowing_empty()))
        {
          expr* constExpr = rCtx.theEM->
          create_const_expr(sctx, udf, loc, xs_integer::one());

          MODIFY(subst_vars(rCtx, node, pvar, constExpr));
          fc->set_pos_var(NULL);
        }

        if (safe_to_fold_var(i, isReferenced))
        {
          if (isReferenced != 0)
            subst_vars(rCtx, node, var, domainExpr);

          MODIFY(theFlwor->remove_clause(i));
          --numClauses;
          --i;

#if 0
          std::cout << rCtx.theMessage << std::endl
                    << "After subst " << var << " :" << std::endl;
          rCtx.getRoot()->put(std::cout) << std::endl;
#endif
          theFlwor->compute_return_type(false, NULL);
        }
      }

      break;
    }
    case flwor_clause::let_clause:
    {
      let_clause* lc = static_cast<let_clause *>(c);
      var_expr* var = lc->get_var();
      expr* domainExpr = lc->get_expr();
      TypeConstants::quantifier_t domainQuant = 
      domainExpr->get_return_type()->get_quantifier();

      if (safe_to_fold_var(i, isReferenced))
      {
        if (isReferenced != 0)
          subst_vars(rCtx, node, var, domainExpr);

        MODIFY(theFlwor->remove_clause(i));
        --numClauses;
        --i;

#if 0
        std::cout << rCtx.theMessage << std::endl
                  << "After subst " << var << " :" << std::endl;
        rCtx.getRoot()->put(std::cout) << std::endl;
#endif
      }
      else if (domainQuant == TypeConstants::QUANT_ONE)
      {
        lc->set_kind(flwor_clause::for_clause);
        var->set_kind(var_expr::for_var);
        modified = true;
      }
    }
    default:
      break;
    }
  }

  expr* whereCond = NULL;

  while (theFlwor->num_clauses() > 0)
  {
    flwor_clause* clause = theFlwor->get_clause(0);

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

        theFlwor->add_clause(1, letClause);
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

        theFlwor->add_clause(1, letClause);
      }

      theFlwor->remove_clause(0);
      continue;
    }
    else if (clause->get_kind() == flwor_clause::where_clause)
    {
      expr* whereExpr = static_cast<where_clause*>(clause)->get_expr();

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
                       udf,
                       whereCond->get_loc(),
                       BUILTIN_FUNC(OP_AND_N),
                       whereExpr,
                       whereCond);
      }

      //as soon as whereCond is not NULL we don't need to mark as modified
      theFlwor->remove_clause(0);
      continue;
    }
    else if (clause->get_kind() == flwor_clause::count_clause)
    {
      // since one value is still returned, count variables are changed to 1
      subst_vars(rCtx,
                 theFlwor,
                 static_cast<count_clause*>(clause)->get_var(),
                 rCtx.theEM->create_const_expr(sctx, udf, loc, xs_integer::one()));

      theFlwor->remove_clause(0);
      continue;
    }
    else if (clause->get_kind() == flwor_clause::order_clause)
    {
      theFlwor->remove_clause(0);
      continue;
    }
    else if (clause->get_kind() == flwor_clause::materialize_clause)
    {
      theFlwor->remove_clause(0);
      continue;
    }
    else
    {
      ZORBA_ASSERT(false);
    }
  }

  if (whereCond != NULL)
  {
    expr* result = (theFlwor->num_clauses() > 0 ? theFlwor : theFlwor->get_return_expr());

    if_expr* ifExpr = rCtx.theEM->
    create_if_expr(sctx,
                   udf,
                   whereCond->get_loc(),
                   whereCond,
                   result,
                   rCtx.theEM->create_seq(sctx, udf, whereCond->get_loc()));

    fix_if_annotations(ifExpr);

    return ifExpr;
  }

  if (theFlwor->num_clauses() == 0)
    return theFlwor->get_return_expr();

  return modified ? node : NULL;
}


RULE_REWRITE_POST(EliminateUnusedLetVars)
{
  return NULL;
}


/*****************************************************************************
  Check if it is OK to fold (inline) a FOR/LET var X that we know is referenced
  only once withing its flwor expr.

  For a LET var, varQuant is always QUANT_ONE.

  For a FOR var, varQuant is the quantifier of the type of the domain expr.
  It can be either QUANT_ONE or QUANT_QUESTION.
******************************************************************************/
bool EliminateUnusedLetVars::safe_to_fold_var(csize varPos, int& numRefs)
{
  TypeManager* tm = theFlwor->get_type_manager();

  // if set to true, then it is unsafe to fold, but we may still be able to
  // completely eliminate the var if it not referenced anywhere.
  bool unsafe = false; 

  theRefPath.clear();
  numRefs = 0;

  forletwin_clause* varClause = 
  static_cast<forletwin_clause*>(theFlwor->get_clause(varPos));

  var_expr* var = varClause->get_var();
  expr* varDomExpr = varClause->get_expr();

  bool isSafeVar = 
  (varClause->get_kind() == flwor_clause::let_clause ||
   static_cast<for_clause*>(varClause)->is_allowing_empty() ||
   varDomExpr->get_return_type()->get_quantifier() == TypeConstants::QUANT_ONE);

  if (is_trivial_expr(varDomExpr))
  {
    numRefs = 1;
    return isSafeVar;
  }

  if (varDomExpr->is_sequential())
    return false;

  if (theFlwor->dereferencesNodes() && varDomExpr->constructsNodes())
    unsafe = true;

  csize numClauses = theFlwor->num_clauses();

  for (csize i = varPos+1; i < numClauses; ++i)
  {
    const flwor_clause* clause = theFlwor->get_clause(i);
    flwor_clause::ClauseKind kind = clause->get_kind();

    std::vector<const expr*>* path = (numRefs > 0 ? NULL : &theRefPath);
    int maxUses = 2 - numRefs;

    switch (kind)
    {
    case flwor_clause::for_clause:
    case flwor_clause::let_clause:
    {
      const forletwin_clause* flc = static_cast<const forletwin_clause *>(clause);
      expr* domExpr = flc->get_expr();

      int uses = expr_tools::count_variable_uses(domExpr, var, maxUses, path);

      if (uses > 0)
      {
        if (uses + numRefs > 1 || unsafe || !isSafeVar || domExpr->is_sequential())
          return false;

        numRefs = 1;
      }
      else if (numRefs == 0)
      {
        if (domExpr->is_sequential())
          unsafe = true;

        // If X is referenced after this FOR clause. In this case, we don't want
        // to inline X because its domain expr will be computed once per iteration
        // instead of just once.
        if (kind == flwor_clause::for_clause &&
            domExpr->get_return_type()->max_card() >= 2)
          unsafe = true;
      }

      break;
    }
    case flwor_clause::where_clause:
    {
      expr* whereExpr = static_cast<const where_clause*>(clause)->get_expr();

      int uses = expr_tools::count_variable_uses(whereExpr, var, maxUses, path);

      if (uses > 0)
      {
        if (uses + numRefs > 1 || unsafe || !isSafeVar)
          return false;

        numRefs = 1;
      }

      break;
    }
    case flwor_clause::order_clause:
    {
      const orderby_clause* oc = static_cast<const orderby_clause*>(clause);

      std::vector<expr*>::const_iterator ite = oc->begin();
      std::vector<expr*>::const_iterator end = oc->end();

      for (; ite != end; ++ite)
      {
        int uses = expr_tools::count_variable_uses(*ite, var, maxUses, path);

        if (uses > 0)
        {
          if (uses + numRefs > 1 || unsafe || !isSafeVar)
            return false;

          numRefs = 1;
        }
      }

      break;
    }
    case flwor_clause::group_clause:
    {
      const group_clause* gc = static_cast<const group_clause*>(clause);

      flwor_clause::rebind_list_t::const_iterator ite = gc->beginGroupVars();
      flwor_clause::rebind_list_t::const_iterator end = gc->endGroupVars();

      for (; ite != end; ++ite)
      {
        expr* inputExpr = ite->first;

        int uses = expr_tools::count_variable_uses(inputExpr, var, maxUses, path);

        if (uses > 0)
        {
          if (uses + numRefs > 1 || unsafe || !isSafeVar)
            return false;

          numRefs = 1;
        }
      }

      ite = gc->beginNonGroupVars();
      end = gc->endNonGroupVars();

      for (; ite != end; ++ite)
      {
        expr* inputExpr = ite->first;

        int uses = expr_tools::count_variable_uses(inputExpr, var, maxUses, path);

        if (uses > 0)
        {
          if (uses + numRefs > 1 || unsafe || !isSafeVar)
            return false;

          numRefs = 1;
        }
      }

      break;
    }
    case flwor_clause::window_clause:
    {
      const window_clause* wc = static_cast<const window_clause*>(clause);
      expr* domExpr = wc->get_expr();
      flwor_wincond* startCond = wc->get_win_start();
      flwor_wincond* stopCond = wc->get_win_stop();

      int uses = expr_tools::count_variable_uses(domExpr, var, maxUses, path);

      if (uses > 0)
      {
        if (uses + numRefs > 1 || unsafe || !isSafeVar || domExpr->is_sequential())
          return false;

        numRefs = 1;
      }
      else if (numRefs == 0)
      {
        if (domExpr->is_sequential())
          unsafe = true;

        if (domExpr->get_return_type()->max_card() >= 2)
          unsafe = true;
      }

      if (startCond != NULL)
      {
        int uses = expr_tools::count_variable_uses(startCond->get_cond(), var, 1, NULL);

        if (uses > 0)
          return false;
      }

      if (stopCond != NULL)
      {
        int uses = expr_tools::count_variable_uses(stopCond->get_cond(), var, 1, NULL);

        if (uses > 0)
          return false;
      }

      break;
    }
    case flwor_clause::materialize_clause:
    {
      unsafe = true;
      break;
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

  expr* retExpr = theFlwor->get_return_expr();

  std::vector<const expr*>* path = (numRefs > 0 ? NULL : &theRefPath);
  int maxUses = 2 - numRefs;

  int uses = expr_tools::count_variable_uses(retExpr, var, maxUses, path);

  if (uses > 0)
  {
    if (uses + numRefs > 1 || unsafe || retExpr->is_sequential())
      return false;

    numRefs = 1;

    if (varClause->get_kind() == flwor_clause::for_clause &&
        varDomExpr->get_return_type()->get_quantifier() != TypeConstants::QUANT_ONE)
    {
      // We are considering folding a FOR var whose domain expr may be the
      // empty sequence. We can fold only if doing so will cause the result
      // of the flwor expr to be the empty sequence in the case where the
      // domain expr will indeed be equal to the empty sequence.
      xqtref_t type = retExpr->get_return_type_with_empty_input(var);

      if (!TypeOps::is_equal(tm, *type, *GENV_TYPESYSTEM.EMPTY_TYPE, retExpr->get_loc()))
      {
        return false;
      }
    }
  }
  else if (numRefs == 0)
  {
    if (varDomExpr->isNonDiscardable() || !isSafeVar)
    {
      return false;
    }
    else
    {
#if 0
      rCtx.getCompilerCB()->theXQueryDiagnostics->add_warning(
          NEW_XQUERY_WARNING(zwarn::ZWST0001_UNUSED_VARIABLE,
          WARN_PARAMS(var->get_name()->getStringValue()),
          WARN_LOC(var->get_loc())));
#endif
      return true;
    }
  }

  return !var_in_try_or_loop(theRefPath);
}


/*******************************************************************************
  Given a variable V and an expression E that references V exactly once, return
  true if the reference occurs inside a
  (a) for-loop within E, or
  (b) try expr within E, or
  (c) while expr within E
********************************************************************************/
bool EliminateUnusedLetVars::var_in_try_or_loop(const std::vector<const expr*>& path)
{
  csize numSteps = path.size();

  for (csize n = 0; n < numSteps; ++n)
  {
    const expr* node = path[n];

    switch (node->get_expr_kind())
    {
    case trycatch_expr_kind:
    case while_expr_kind:
    {
      return true;
    }
    case flwor_expr_kind:
    case gflwor_expr_kind:
    {
      const expr* nextNode = path[n+1];

      const flwor_expr* flwor = static_cast<const flwor_expr*>(node);

      bool foundRefClause = false;
      csize numClauses = flwor->num_clauses();

      for (csize i = 0; i < numClauses && ! foundRefClause; ++i)
      {
        flwor_clause* c = flwor->get_clause(i);
        flwor_clause::ClauseKind ckind = c->get_kind();

        switch (ckind)
        {
        case flwor_clause::for_clause:
        case flwor_clause::let_clause:
        case flwor_clause::window_clause:
        {
          forletwin_clause* flwc = static_cast<forletwin_clause*>(c);
          expr* domExpr = flwc->get_expr();
            
          if (nextNode == domExpr)
          {
            foundRefClause = true;
            break;
          }

          if (ckind == flwor_clause::window_clause ||
              (ckind == flwor_clause::for_clause &&
               domExpr->get_return_type()->max_card() >= 2))
          {
            return true;
          }
          
          break;
        }
        case flwor_clause::group_clause:
        {
          group_clause* gc = static_cast<group_clause*>(c);
            
          flwor_clause::rebind_list_t::const_iterator ite = gc->beginGroupVars();
          flwor_clause::rebind_list_t::const_iterator end = gc->endGroupVars();
          
          for (; ite != end; ++ite)
          {
            expr* gExpr = (*ite).first;
            
            if (nextNode == gExpr)
            {
              foundRefClause = true;
              break;
            }
          }
          
          if (foundRefClause)
            break;

          ite = gc->beginNonGroupVars();
          end = gc->endNonGroupVars();
          
          for (; ite != end; ++ite)
          {
            expr* ngExpr = (*ite).first;
            
            if (nextNode == ngExpr)
            {
              foundRefClause = true;
              break;
            }
          }
          
          break;
        }
        case flwor_clause::where_clause:
        {
          where_clause* wc = static_cast<where_clause*>(c);
            
          if (nextNode == wc->get_expr())
            foundRefClause = true;
          
          break;
        }
        case flwor_clause::order_clause:
        {
          orderby_clause* oc = static_cast<orderby_clause*>(c);
          
          std::vector<expr*>::const_iterator ite = oc->begin();
          std::vector<expr*>::const_iterator end = oc->end();

          for (; ite != end; ++ite)
          {
            if (nextNode == *ite)
            {
              foundRefClause = true;
              break;
            }
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
      } // for each clause

      if (!foundRefClause)
      {
        ZORBA_ASSERT(nextNode == flwor->get_return_expr()); 
      }

      break;
    }
    default:
      break;
    }
  } // for each path step
    
  return false;
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

    assert(!e->isNonDiscardable());
    return true;
  }
  case wrapper_expr_kind:
  {
    return is_trivial_expr(static_cast<const wrapper_expr*>(e)->get_input());
  }
  default:
    return false;
  }
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
  user_function* udf = node->get_udf();

  assert(udf == rCtx.theUDF);

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
                         udf,
                         whereExpr->get_loc(),
                         BUILTIN_FUNC(OP_AND_N),
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

      expr* whereExpr = static_cast<where_clause*>(clause)->get_expr();

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
              expr_tools::count_variable_uses(flwor, posVar, 2, NULL) <= 1)
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
            expr_tools::count_variable_uses(flwor, posVar, 2, NULL) <= 1)
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
  user_function* udf = flworExpr->get_udf();

  assert(udf == rCtx.theUDF);

  for_clause* forClause = posVar->get_forlet_clause();
  expr* domainExpr = forClause->get_expr();

  fo_expr* result;

  switch (compKind)
  {
  case CompareConsts::GENERAL_EQUAL:
  case CompareConsts::VALUE_EQUAL:
  {
    result = rCtx.theEM->
    create_fo_expr(sctx,
                   udf,
                   domainExpr->get_loc(),
                   BUILTIN_FUNC(OP_ZORBA_SEQUENCE_POINT_ACCESS_2),
                   domainExpr,
                   posExpr);
    break;
  }
  case CompareConsts::GENERAL_LESS_EQUAL:
  case CompareConsts::VALUE_LESS_EQUAL:
  {
    expr* oneExpr = rCtx.theEM->
      create_const_expr(sctx, udf, domainExpr->get_loc(), xs_integer(1));

    std::vector<expr*> args(3);
    args[0] = domainExpr;
    args[1] = oneExpr;
    args[2] = posExpr;

    result = rCtx.theEM->
    create_fo_expr(sctx,
                   udf,
                   domainExpr->get_loc(),
                   BUILTIN_FUNC(OP_ZORBA_SUBSEQUENCE_INT_3),
                   args);
    break;
  }
  case CompareConsts::GENERAL_LESS:
  case CompareConsts::VALUE_LESS:
  {
    expr* oneExpr1 = rCtx.theEM->
    create_const_expr(sctx, udf, domainExpr->get_loc(), xs_integer(1));

    expr* oneExpr2 = rCtx.theEM->
    create_const_expr(sctx, udf, domainExpr->get_loc(), xs_integer(1));

    posExpr = rCtx.theEM->
    create_fo_expr(sctx,
                   udf,
                   domainExpr->get_loc(),
                   BUILTIN_FUNC(OP_NUMERIC_SUBTRACT_INTEGER_2),
                   posExpr,
                   oneExpr2);

    std::vector<expr*> args(3);
    args[0] = domainExpr;
    args[1] = oneExpr1;
    args[2] = posExpr;
    
    result = rCtx.theEM->
    create_fo_expr(sctx,
                   udf,
                   domainExpr->get_loc(),
                   BUILTIN_FUNC(OP_ZORBA_SUBSEQUENCE_INT_3),
                   args);
    break;
  }
  case CompareConsts::GENERAL_GREATER_EQUAL:
  case CompareConsts::VALUE_GREATER_EQUAL:
  {
    result = rCtx.theEM->
    create_fo_expr(sctx,
                   udf,
                   domainExpr->get_loc(),
                   BUILTIN_FUNC(OP_ZORBA_SUBSEQUENCE_INT_2),
                   domainExpr,
                   posExpr);
    break;
  }
  case CompareConsts::GENERAL_GREATER:
  case CompareConsts::VALUE_GREATER:
  {
    expr* oneExpr = rCtx.theEM->
    create_const_expr(sctx, udf, domainExpr->get_loc(), xs_integer(1));

    posExpr = rCtx.theEM->
    create_fo_expr(sctx,
                   udf,
                   domainExpr->get_loc(),
                   BUILTIN_FUNC(OP_NUMERIC_ADD_INTEGER_2),
                   posExpr,
                   oneExpr);

    result = rCtx.theEM->
    create_fo_expr(sctx,
                   udf,
                   domainExpr->get_loc(),
                   BUILTIN_FUNC(OP_ZORBA_SUBSEQUENCE_INT_2),
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

    for_clause* forClause = posVar->get_forlet_clause();

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
    csize numNestedClauses;

    flwor_clause* c = flwor->get_clause(i);

    if (c->get_kind() == flwor_clause::let_clause)
    {
      expr* domainExpr = static_cast<let_clause*>(c)->get_expr();

      if (domainExpr->get_expr_kind() == flwor_expr_kind &&
          !domainExpr->is_sequential())
      {
        nestedFlwor = static_cast<flwor_expr*>(domainExpr);
        numNestedClauses = nestedFlwor->num_clauses();
        merge = true;

        for (csize j = 0; j < numNestedClauses; ++j)
        {
          flwor_clause* nestedClause = nestedFlwor->get_clause(j);
          flwor_clause::ClauseKind nestedClauseKind = nestedClause->get_kind();

          if (nestedClauseKind == flwor_clause::for_clause)
          {
            xqtref_t nestedDomainType =
            static_cast<for_clause*>(nestedClause)->get_expr()->get_return_type();

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
    }
    else if (c->get_kind() == flwor_clause::for_clause &&
             static_cast<for_clause*>(c)->get_pos_var() == NULL)
    {
      expr* domainExpr = static_cast<for_clause*>(c)->get_expr();

      if (domainExpr->get_expr_kind() == flwor_expr_kind &&
          !domainExpr->is_sequential())
      {
        nestedFlwor = static_cast<flwor_expr*>(domainExpr);
        numNestedClauses = nestedFlwor->num_clauses();
        merge = true;

        for (csize j = 0; j < numNestedClauses; ++j)
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
