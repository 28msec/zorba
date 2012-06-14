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

#include <map>

#include "context/static_context.h"

#include "functions/library.h"
#include "functions/udf.h"

#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/expr_iter.h"

#include "types/typeimpl.h"

#include "util/dynamic_bitset.h"

#include "diagnostics/assert.h"


namespace zorba
{

static bool hoist_expressions(
    RewriterContext&,
    expr*,
    const VarIdMap&,
    const ExprVarsMap&,
    struct PathHolder*);

static expr_t try_hoisting(
    RewriterContext&,
    expr*,
    const VarIdMap&,
    const ExprVarsMap&,
    struct PathHolder*);

static bool non_hoistable (const expr*);

static bool is_already_hoisted(const expr*);

static bool contains_var(
    var_expr*,
    const VarIdMap&,
    const DynamicBitset&);

static bool is_enclosed_expr(const expr*);

static bool containsUpdates(const expr*);


/*******************************************************************************
  Used to implement a stack of "intersting" exprs that appear in the path from
  the root expr to the current expr. Currently, "intersting" exprs are flwor
  and try-catch exprs.
********************************************************************************/
struct PathHolder
{
  struct PathHolder  * prev;
  expr_t               expr;
  long                 clauseCount;

  PathHolder() 
    :
    prev(NULL),
    clauseCount(0)
  {
  }
};


/*******************************************************************************
  This rule looks for exprs that are inside a for loop but do not depend on the
  loop variable, and then moves such exprs outside the loop.
********************************************************************************/
expr_t HoistRule::apply(
    RewriterContext& rCtx,
    expr* node,
    bool& modified)
{
  assert(node == rCtx.getRoot());

  ulong numVars = 0;
  VarIdMap varmap;

  expr_tools::index_flwor_vars(node, numVars, varmap, NULL);

  ExprVarsMap freevarMap;
  DynamicBitset freeset(numVars);
  expr_tools::build_expr_to_vars_map(node, varmap, freeset, freevarMap);

  PathHolder root;
  modified = hoist_expressions(rCtx, node, varmap, freevarMap, &root);

  if (modified && root.expr != NULL)
  {
    assert(root.expr->get_expr_kind() == flwor_expr_kind);

    static_cast<flwor_expr*>(root.expr.getp())->set_return_expr(node);
    return root.expr;
  }

  return node;
}


/*******************************************************************************
  Try to hoist the children of the given expr "e".
********************************************************************************/
static bool hoist_expressions(
    RewriterContext& rCtx,
    expr* e,
    const VarIdMap& varmap,
    const ExprVarsMap& freevarMap,
    struct PathHolder* path)
{
  bool status = false;

  if (e->get_expr_kind() == flwor_expr_kind)
  {
    flwor_expr* flwor = static_cast<flwor_expr *>(e);

    PathHolder step;
    step.prev = path;
    step.expr = e;

    csize numForLetClauses = flwor->num_forlet_clauses();
    csize i = 0;

    while (i < numForLetClauses)
    {
      forletwin_clause* flc = static_cast<forletwin_clause*>(flwor->get_clause(i));
      expr* domainExpr = flc->get_expr();

      expr_t unhoistExpr = 
      try_hoisting(rCtx, domainExpr, varmap, freevarMap, &step);

      if (unhoistExpr != NULL)
      {
        flc->set_expr(unhoistExpr.getp());
        status = true;
        numForLetClauses = flwor->num_forlet_clauses();
        // TODO: the expr that was just hoisted here, may contain sub-exprs that
        // can be hoisted even earlier. 
      }
      else if (domainExpr->is_sequential())
      {
        PathHolder root;

        bool hoisted = 
        hoist_expressions(rCtx, domainExpr, varmap, freevarMap, &root);

        if (hoisted)
        {
          if (root.expr != NULL)
          {
            assert(root.expr->get_expr_kind() == flwor_expr_kind);

            static_cast<flwor_expr*>(root.expr.getp())->set_return_expr(domainExpr);
            flc->set_expr(root.expr.getp());
          }

          status = true;
          assert(numForLetClauses == flwor->num_forlet_clauses());
        }
      }
      else
      {
        bool hoisted = 
        hoist_expressions(rCtx, domainExpr, varmap, freevarMap, &step);

        if (hoisted)
        {
          status = true;
          numForLetClauses = flwor->num_forlet_clauses();
        }
      }

      i = ++(step.clauseCount);

      assert(numForLetClauses == flwor->num_forlet_clauses());
    }

    expr_t we = flwor->get_where();
    if (we != NULL)
    {
      ZORBA_ASSERT(!we->is_sequential());

      expr_t unhoistExpr = try_hoisting(rCtx, we, varmap, freevarMap, &step);

      if (unhoistExpr != NULL)
      {
        flwor->set_where(unhoistExpr.getp());
        status = true;
      }
      else
      {
        status = hoist_expressions(rCtx, we, varmap, freevarMap, &step) || status;
      }
    }

    // TODO: hoist orderby exprs

    expr_t re = flwor->get_return_expr();
    expr_t unhoistExpr = try_hoisting(rCtx, re, varmap, freevarMap, &step);

    if (unhoistExpr != NULL)
    {
      flwor->set_return_expr(unhoistExpr.getp());
      status = true;
    }
    else if (re->is_sequential())
    {
      PathHolder root;
      bool nestedModified = hoist_expressions(rCtx, re, varmap, freevarMap, &root);

      if (nestedModified && root.expr != NULL)
      {
        assert(root.expr->get_expr_kind() == flwor_expr_kind);

        static_cast<flwor_expr*>(root.expr.getp())->set_return_expr(re);
        flwor->set_return_expr(root.expr.getp());
      }

      status = nestedModified || status;
    }
    else
    {
      status = hoist_expressions(rCtx, re, varmap, freevarMap, &step) || status;
    }
  }

  else if (e->get_expr_kind() == trycatch_expr_kind)
  {
    PathHolder step;
    step.prev = path;
    step.expr = e;

    ExprIterator iter(e);

    while(!iter.done())
    {
      expr* ce = &*(*iter);
      if (ce)
      {
        expr_t unhoistExpr = try_hoisting(rCtx, ce, varmap, freevarMap, &step);
        if (unhoistExpr != NULL)
        {
          *iter = unhoistExpr.getp();
          status = true;
        }
        else
        {
          status = hoist_expressions(rCtx, ce, varmap, freevarMap, &step) || status;
        }
      }

      iter.next();
    }
  }

  else if (e->get_expr_kind() == block_expr_kind || e->is_sequential())
  {
    ExprIterator iter(e);

    while (!iter.done())
    {
      // TODO: if no updating child exprs have been encountered so far, subexprs
      // of the current child expr may be hoisted outside the sequential expr as
      // long as they don't reference any local vars.
      expr_t ce = *iter;

      PathHolder root;
      bool nestedModified = hoist_expressions(rCtx, ce, varmap, freevarMap, &root);

      if (nestedModified && root.expr != NULL)
      {
        assert(root.expr->get_expr_kind() == flwor_expr_kind);

        static_cast<flwor_expr*>(root.expr.getp())->set_return_expr(ce);
        (*iter) = root.expr;
      }

      status = nestedModified || status;

      iter.next();
    }
  }

  else if (e->is_updating() ||
           e->get_expr_kind() == gflwor_expr_kind ||
           e->get_expr_kind() == transform_expr_kind)
  {
    // do nothing
  }

  else
  {
    ExprIterator iter(e);

    while(!iter.done())
    {
      expr* ce = &*(*iter);
      if (ce)
      {
        expr_t unhoistExpr = try_hoisting(rCtx, ce, varmap, freevarMap, path);
        if (unhoistExpr != NULL)
        {
          *iter = unhoistExpr.getp();
          status = true;
        }
        else
        {
          status = hoist_expressions(rCtx, ce, varmap, freevarMap, path) || status;
        }
      }

      iter.next();
    }
  }

  return status;
}


/*******************************************************************************
  Try to hoist the given expr e out of some for loop that is located in some
  flwor expr inside the stack of flwor exprs that is accessible via the "holder"
  param.
********************************************************************************/
static expr_t try_hoisting(
    RewriterContext& rCtx,
    expr* e,
    const VarIdMap& varmap,
    const ExprVarsMap& freevarMap,
    struct PathHolder* path)
{
  if (non_hoistable(e) || e->contains_node_construction())
  {
    return NULL;
  }

  std::map<const expr*, DynamicBitset>::const_iterator fvme = freevarMap.find(e);
  ZORBA_ASSERT(fvme != freevarMap.end());
  const DynamicBitset& varset = fvme->second;

  PathHolder* step = path;

  bool inloop = false;
  bool foundReferencedFLWORVar = false;
  bool foundSequentialClause = false;
  int i = 0;

  // step->prev == NULL means that expr e is not inside any flwor expr, and as a
  // result, there is nothing to hoist. 
  while (step->prev != NULL)
  {
    if (step->expr->get_expr_kind() == trycatch_expr_kind)
    {
      // Should not hoist an expr out of a try-catch if it contains any try-catch vars
      trycatch_expr* trycatch = static_cast<trycatch_expr*>(step->expr.getp());
      csize numClauses = trycatch->clause_count();

      for (csize i = 0; i < numClauses; ++i)
      {
        const catch_clause_t& clause = (*trycatch)[i];

        catch_clause::var_map_t& trycatchVars = clause->get_vars();

        catch_clause::var_map_t::const_iterator ite = trycatchVars.begin();
        catch_clause::var_map_t::const_iterator end = trycatchVars.end();
        for (; ite != end; ++ite)
        {
          const var_expr_t& trycatchVar = (*ite).second;

          if (contains_var(trycatchVar.getp(), varmap, varset))
            return NULL;
        } 
      }
    }
    else
    {
      assert(step->expr->get_expr_kind() == flwor_expr_kind);

      flwor_expr* flwor = static_cast<flwor_expr*>(step->expr.getp());
      group_clause* gc = flwor->get_group_clause();

      // If any free variable is a group-by variable, give up.
      if (gc != NULL)
      {
        const flwor_clause::rebind_list_t& gvars = gc->get_grouping_vars();
        csize numGroupVars = gvars.size();

        for (csize i = 0; i < numGroupVars; ++i)
        {
          if (contains_var(gvars[i].second.getp(), varmap, varset))
            return NULL;
        }

        const flwor_clause::rebind_list_t& ngvars = gc->get_nongrouping_vars();
        csize numNonGroupVars = ngvars.size();
        
        for (csize i = 0; i < numNonGroupVars; ++i)
        {
          if (contains_var(ngvars[i].second.getp(), varmap, varset))
            return NULL;
        }
      }

      // Check whether expr e references any variables from the current flwor. If
      // not, then e can be hoisted out of the current flwor and we repeat the 
      // while-loop to see if e can be hoisted w.r.t. the previous (outer) flwor.
      // If yes, then let V be the inner-most var referenced by e. If there are any
      // FOR vars after V, e can be hoisted out of any such FOR vars. Otherwise, e
      // cannot be hoisted.
      for (i = step->clauseCount - 1; i >= 0; --i)
      {
        const forletwin_clause* flc = 
        static_cast<const forletwin_clause*>(flwor->get_clause(i));

        if (flc->get_expr()->is_sequential())
        {
          foundSequentialClause = true;
          break;
        }

        if (contains_var(flc->get_var(), varmap, varset) ||
            contains_var(flc->get_pos_var(), varmap, varset) ||
            contains_var(flc->get_score_var(), varmap, varset))
        {
          foundReferencedFLWORVar = true;
          break;
        }
        
        inloop = (inloop ||
                  (flc->get_kind() == flwor_clause::for_clause &&
                   flc->get_expr()->get_return_type()->max_card() >= 2));
      }

      if (foundSequentialClause || foundReferencedFLWORVar)
        break;
    }

    if (step->prev->prev == NULL)
      break;

    step = step->prev;
  }

  if (!inloop)
    return NULL;

  // Hoisting is possible ... Go ahead and hoist e: (a) we create an internal LET
  // var: $$temp := op:hoist(e) (b) we place the $$temp declaration right after
  // variable V, and (c) we replace e with op:unhoist($$temp).

  var_expr_t letvar(rCtx.createTempVar(e->get_sctx(), e->get_loc(), var_expr::let_var));

  expr_t hoisted = new fo_expr(e->get_sctx(),
                               e->get_loc(),
                               GET_BUILTIN_FUNCTION(OP_HOIST_1),
                               e);

  hoisted->setFlags(e->getFlags());
  letvar->setFlags(e->getFlags());

  let_clause_t flref(new let_clause(e->get_sctx(), e->get_loc(), letvar, hoisted));

  letvar->set_flwor_clause(flref.getp());

  if (step->prev == NULL)
  {
    if (step->expr == NULL)
    {
      step->expr = new flwor_expr(e->get_sctx(), e->get_loc(), false);
    }
    static_cast<flwor_expr*>(step->expr.getp())->add_clause(flref);
  }
  else if (step->expr->get_expr_kind() == flwor_expr_kind)
  {
    static_cast<flwor_expr*>(step->expr.getp())->add_clause(i + 1, flref);
    ++step->clauseCount;
  }
  else
  {
    assert(step->expr->get_expr_kind() == trycatch_expr_kind);
    trycatch_expr* trycatchExpr = static_cast<trycatch_expr*>(step->expr.getp());

    flwor_expr_t flwor = new flwor_expr(e->get_sctx(), e->get_loc(), false);
    flwor->add_clause(flref);
    flwor->set_return_expr(trycatchExpr->get_try_expr());

    trycatchExpr->set_try_expr(flwor);
  }

  expr_t unhoisted = new fo_expr(e->get_sctx(),
                                 e->get_loc(),
                                 GET_BUILTIN_FUNCTION(OP_UNHOIST_1),
                                 new wrapper_expr(e->get_sctx(),
                                                  e->get_loc(),
                                                  letvar.getp()));
  unhoisted->setFlags(e->getFlags());

  return unhoisted.getp();
}


/*******************************************************************************
  Check if the given var is contained in the given varset.
********************************************************************************/
static bool contains_var(
    var_expr* v,
    const VarIdMap& varmap,
    const DynamicBitset& varset)
{
  if (v == NULL)
  {
    return false;
  }

  VarIdMap::const_iterator i = varmap.find(v);
  if (i == varmap.end())
  {
    return false;
  }
  int bit = i->second;
  return varset.get(bit);
}


/*******************************************************************************

********************************************************************************/
static bool non_hoistable(const expr* e)
{
  expr_kind_t k = e->get_expr_kind();

  if (k == var_expr_kind ||
      k == const_expr_kind ||
      k == axis_step_expr_kind ||
      k == match_expr_kind ||
      (k == wrapper_expr_kind && 
       non_hoistable(static_cast<const wrapper_expr*>(e)->get_expr())) ||
      is_already_hoisted(e) ||
      is_enclosed_expr(e) ||
      e->containsRecursiveCall() ||
      e->is_nondeterministic() ||
      e->is_sequential() ||
      e->is_updating())
  {
    return true;
  }

  if (k == fo_expr_kind)
  {
    const fo_expr* fo = static_cast<const fo_expr*>(e);
    const function* f = fo->get_func();

    if (f->getKind() == FunctionConsts::OP_CONCATENATE_N && fo->num_args() == 0)
      return true;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
static bool is_already_hoisted(const expr* e)
{
  if (e->get_expr_kind() == fo_expr_kind)
  {
    function* f = static_cast<const fo_expr *>(e)->get_func();

    return (f->getKind() == FunctionConsts::OP_UNHOIST_1 ||
            f->getKind() == FunctionConsts::OP_HOIST_1);
  }
  return false;
}


/*******************************************************************************
  Enclosed exprs cannot be hoisted because they may construct text nodes.
********************************************************************************/
static bool is_enclosed_expr(const expr* e)
{
  if (e->get_expr_kind() != fo_expr_kind)
    return false;

  const function* fn = static_cast<const fo_expr *>(e)->get_func();
  return (fn->getKind() == FunctionConsts::OP_ENCLOSED_1);
}


/*******************************************************************************

********************************************************************************/
static bool containsUpdates(const expr* e)
{
  if (e->is_updating())
    return true;

  ExprConstIterator iter(e);
  while(!iter.done())
  {
    const expr* ce = iter.get_expr();
    if (ce)
    {
      if (containsUpdates(ce))
        return true;
    }
    iter.next();
  }

  return false;
}


}
/* vim:set et sw=2 ts=2: */
