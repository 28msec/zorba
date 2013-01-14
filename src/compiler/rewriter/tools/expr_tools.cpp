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

#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/path_expr.h"
#include "compiler/expression/ft_expr.h"
#include "compiler/expression/ftnode.h"
#include "compiler/expression/expr_iter.h"

#include "functions/func_errors_and_diagnostics.h"

#include "types/typeops.h"

#include <iterator>

namespace zorba
{

namespace expr_tools
{

static void add_wincond_vars(const flwor_wincond*, ulong&, VarIdMap&, IdVarMap*);

static void add_var(var_expr*, ulong&, VarIdMap&, IdVarMap*);

static void remove_wincond_vars(const flwor_wincond*, const VarIdMap&, DynamicBitset&);

static void set_bit(var_expr*, const VarIdMap&, DynamicBitset&, bool);


/*******************************************************************************

********************************************************************************/
bool count_var_uses_rec(
    expr* e,
    var_expr* var,
    int limit,
    std::vector<expr**>* path,
    int& count)
{
  if (limit > 0 && count >= limit)
  {
    return false;
  }

  if (e == var)
  {
    ++count;
    return true;
  }

  if (e->get_expr_kind() == if_expr_kind)
  {
    ExprIterator iter(e);
    const if_expr* ifExpr = static_cast<const if_expr*>(e);

    if (path && count == 0)
      path->push_back(*iter);

    bool done = !count_var_uses_rec(ifExpr->get_cond_expr(), var, limit, path, count);
    if (done)
    {
      assert(count > 0);
      return false;
    }

    if (path && count == 0)
      path->pop_back();

    iter.next();

    if (path && count == 0)
      path->push_back(*iter);

    int thenCount = count;
    std::vector<expr**>* thenPath = (count == 0 ? path : NULL);
    
    done = !count_var_uses_rec(ifExpr->get_then_expr(), var, limit, thenPath, thenCount);
    if (done)
    {
      count = thenCount;
      assert(count > 0);
      return false;
    }

    if (path && count == 0)
      path->pop_back();

    iter.next();

    if (path && count == 0)
      path->push_back(*iter);

    int elseCount = count;
    std::vector<expr**>* elsePath = (count == 0 ? path : NULL);

    done = !count_var_uses_rec(ifExpr->get_else_expr(), var, limit, elsePath, elseCount);
    if (done)
    {
      count = elseCount;
      assert(count > 0);
      return false;
    }

    if (path && count == 0)
      path->pop_back();

    count = (thenCount > elseCount ? thenCount : elseCount);
  }
  else
  {
    ExprIterator iter(e);
    while (!iter.done())
    {
      if (path && count == 0)
      {
        path->push_back(*iter);
      }

      bool done = ! count_var_uses_rec(**iter, var, limit, path, count);

      if (done)
      {
        assert(count > 0);
        return false;
      }

      if (path && count == 0)
      {
        path->pop_back();
      }

      iter.next();
    }
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
int count_variable_uses(
    expr* root,
    var_expr* var,
    int limit,
    std::vector<expr**>* path)
{
  int count = 0;

  count_var_uses_rec(root, var, limit, path, count);

  return count;
}


/*******************************************************************************
  copy annotations when wrapping an expression in a new one
********************************************************************************/
expr* fix_annotations(expr* new_expr, const expr* old_expr)
{
  if (old_expr == NULL)
  {
    switch (new_expr->get_expr_kind())
    {
    case fo_expr_kind:
      old_expr = static_cast<const fo_expr*>(new_expr)->get_arg(0);
      break;
    default:
      assert(false);
      return NULL;
    }
  }

  const expr::FreeVars& old_set = old_expr->getFreeVars();
  const expr::FreeVars& new_set = new_expr->getFreeVars();

  expr::FreeVars s;
  std::set_union(old_set.begin(),
                 old_set.end(),
                 new_set.begin(),
                 new_set.end(),
                 inserter(s, s.begin()));

  new_expr->setFreeVars(s);

  return new_expr;
}



/*******************************************************************************
  Replace all references to "oldVar" inside "e" with references to "newVar".
********************************************************************************/
void replace_var(expr* e, const var_expr* oldVar, var_expr* newVar)
{
  if (e->get_expr_kind() == wrapper_expr_kind)
  {
    wrapper_expr* wrapper = reinterpret_cast<wrapper_expr*>(e);

    if (wrapper->get_input() == oldVar)
    {
      wrapper->set_expr(newVar);
      return;
    }
  }

  ExprIterator iter(e);
  while (!iter.done())
  {
    replace_var((**iter), oldVar, newVar);
    iter.next();
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//                                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Let FLWOR(e) be the set of flwor exprs within the expr tree rooted at expr e.
  Let FV(e) be the set of variables defined in any of the flwor exprs in FLWOR(e).
  This method assigns a prefix id to each variable in FV(e) and stores the mapping
  between var_expr and prefix id in "varmap". It also returns the number of vars
  in FV(e).

  Given 2 vars v1 and v2 in FV(e), their prefix ids allows to check if v1 is
  defined before v2: v1 is defined before v2 iff id(v1) < id(v2).
********************************************************************************/
void index_flwor_vars(
    const expr* e,
    ulong& numVars,
    VarIdMap& varidmap,
    IdVarMap* idvarmap)
{
  if (e->get_expr_kind() == flwor_expr_kind ||
      e->get_expr_kind() == gflwor_expr_kind)
  {
    const flwor_expr* flwor = static_cast<const flwor_expr *>(e);

    for (flwor_expr::clause_list_t::const_iterator i = flwor->clause_begin();
         i != flwor->clause_end();
         ++i)
    {
      const flwor_clause* c = *i;

      if (c->get_kind() == flwor_clause::for_clause)
      {
        const for_clause* fc = static_cast<const for_clause *>(c);

        add_var(fc->get_var(), numVars, varidmap, idvarmap);
        add_var(fc->get_pos_var(), numVars, varidmap, idvarmap);
        add_var(fc->get_score_var(), numVars, varidmap, idvarmap);

        index_flwor_vars(fc->get_expr(), numVars, varidmap, idvarmap);
      }
      else if (c->get_kind() == flwor_clause::let_clause)
      {
        const let_clause* lc = static_cast<const let_clause *>(c);

        add_var(lc->get_var(), numVars, varidmap, idvarmap);
        add_var(lc->get_score_var(), numVars, varidmap, idvarmap);

        index_flwor_vars(lc->get_expr(), numVars, varidmap, idvarmap);
      }
      else if (c->get_kind() == flwor_clause::window_clause)
      {
        const window_clause* wc = static_cast<const window_clause *>(c);

        add_var(wc->get_var(), numVars, varidmap, idvarmap);

        index_flwor_vars(wc->get_expr(), numVars, varidmap, idvarmap);

        flwor_wincond* startCond = wc->get_win_start();
        flwor_wincond* stopCond = wc->get_win_stop();

        if (startCond != NULL)
          add_wincond_vars(startCond, numVars, varidmap, idvarmap);

        if (stopCond != NULL)
          add_wincond_vars(stopCond, numVars, varidmap, idvarmap);
      }
      else if (c->get_kind() == flwor_clause::group_clause)
      {
        const group_clause* gc = static_cast<const group_clause *>(c);

        const flwor_clause::rebind_list_t& gvars = gc->get_grouping_vars();
        csize numGroupVars = gvars.size();

        for (csize i = 0; i < numGroupVars; ++i)
        {
          add_var(gvars[i].second, numVars, varidmap, idvarmap);
        }

        const flwor_clause::rebind_list_t& ngvars = gc->get_nongrouping_vars();
        csize numNonGroupVars = ngvars.size();

        for (csize i = 0; i < numNonGroupVars; ++i)
        {
          add_var(ngvars[i].second, numVars, varidmap, idvarmap);
        }
      }
      else if (c->get_kind() == flwor_clause::count_clause)
      {
        const count_clause* cc = static_cast<const count_clause *>(c);

        add_var(cc->get_var(), numVars, varidmap, idvarmap);
      }
      else if (c->get_kind() == flwor_clause::where_clause)
      {
        const where_clause* wc = static_cast<const where_clause *>(c);

        index_flwor_vars(wc->get_expr(), numVars, varidmap, idvarmap);
      }
      else if (c->get_kind() == flwor_clause::order_clause)
      {
        const orderby_clause* obc = static_cast<const orderby_clause *>(c);
        csize numExprs = obc->num_columns();
        for (csize i = 0; i < numExprs; ++i)
        {
          index_flwor_vars(obc->get_column_expr(i), numVars, varidmap, idvarmap);
        }
      }
    }

    index_flwor_vars(flwor->get_return_expr(), numVars, varidmap, idvarmap);
  }
  else if (e->get_expr_kind() == trycatch_expr_kind)
  {
    const trycatch_expr* trycatch = static_cast<const trycatch_expr*>(e);

    index_flwor_vars(trycatch->get_try_expr(), numVars, varidmap, idvarmap);

    csize numClauses = trycatch->clause_count();

    for (csize i = 0; i < numClauses; ++i)
    {
      const catch_clause* clause = (*trycatch)[i];

      catch_clause::var_map_t& trycatchVars =
        const_cast<catch_clause*>(clause)->get_vars();

      catch_clause::var_map_t::const_iterator ite = trycatchVars.begin();
      catch_clause::var_map_t::const_iterator end = trycatchVars.end();
      for (; ite != end; ++ite)
      {
        var_expr* trycatchVar = (*ite).second;
        add_var(trycatchVar, numVars, varidmap, idvarmap);
      }

      index_flwor_vars(trycatch->get_catch_expr(i), numVars, varidmap, idvarmap);
    }
  }
  else
  {
    ExprConstIterator iter(e);
    while(!iter.done())
    {
      const expr* ce = iter.get_expr();
      if (ce)
      {
        index_flwor_vars(ce, numVars, varidmap, idvarmap);
      }
      iter.next();
    }
  }
}


/*******************************************************************************

********************************************************************************/
static void add_wincond_vars(
    const flwor_wincond* cond,
    ulong& numVars,
    VarIdMap& varidmap,
    IdVarMap* idvarmap)
{
  const flwor_wincond::vars& inVars = cond->get_in_vars();
  const flwor_wincond::vars& outVars = cond->get_out_vars();

  add_var(inVars.posvar, numVars, varidmap, idvarmap);
  add_var(inVars.curr, numVars, varidmap, idvarmap);
  add_var(inVars.prev, numVars, varidmap, idvarmap);
  add_var(inVars.next, numVars, varidmap, idvarmap);

  index_flwor_vars(cond->get_expr(), numVars, varidmap, idvarmap);

  add_var(outVars.posvar, numVars, varidmap, idvarmap);
  add_var(outVars.curr, numVars, varidmap, idvarmap);
  add_var(outVars.prev, numVars, varidmap, idvarmap);
  add_var(outVars.next, numVars, varidmap, idvarmap);
}


/*******************************************************************************

********************************************************************************/
static void add_var(
    var_expr* v,
    ulong& numVars,
    VarIdMap& varidmap,
    IdVarMap* idvarmap)
{
  if (v != NULL)
  {
    varidmap[v] = numVars++;
    if (idvarmap)
      idvarmap->push_back(v);
  }
}


/*******************************************************************************
  For each expr E in the expr tree rooted at "e", this method computes the set
  of variables that belong to FV(e) and are referenced by E. Let V(E) be this
  set. V(E) is implemented as a bitset ("freeset") whose size is equal to the
  size of FV(e) and whose i-th bit is on iff the var with prefix id i belongs
  to V(E). The mapping between E and V(E) is stored in "freevarMap".
********************************************************************************/
void build_expr_to_vars_map(
    expr* e,
    const VarIdMap& varmap,
    DynamicBitset& freeset,
    ExprVarsMap& freevarMap)
{
  if (e->get_expr_kind() == var_expr_kind)
  {
    set_bit(static_cast<var_expr *>(e), varmap, freeset, true);
    freevarMap[e] = freeset;
    return;
  }

  csize numVars = freeset.size();

  DynamicBitset eFreeset(numVars);
  ExprIterator iter(e);
  while(!iter.done())
  {
    expr* ce = **iter;
    if (ce)
    {
      eFreeset.reset();
      build_expr_to_vars_map(ce, varmap, eFreeset, freevarMap);
      freeset.set_union(eFreeset);
    }
    iter.next();
  }

  // A flwor does not depend on the vars that are defined inside the flwor itself,
  // so remove these vars from the freeset of the flwor, if they have been added
  // there.
  if (e->get_expr_kind() == flwor_expr_kind ||
      e->get_expr_kind() == gflwor_expr_kind)
  {
    flwor_expr* flwor = static_cast<flwor_expr *>(e);

    for(flwor_expr::clause_list_t::const_iterator i = flwor->clause_begin();
        i != flwor->clause_end();
        ++i)
    {
      const flwor_clause* c = *i;

      if (c->get_kind() == flwor_clause::for_clause)
      {
        const for_clause* fc = static_cast<const for_clause *>(c);

        set_bit(fc->get_var(), varmap, freeset, false);
        set_bit(fc->get_pos_var(), varmap, freeset, false);
        set_bit(fc->get_score_var(), varmap, freeset, false);
      }
      else if (c->get_kind() == flwor_clause::let_clause)
      {
        const let_clause* lc = static_cast<const let_clause *>(c);

        set_bit(lc->get_var(), varmap, freeset, false);
        set_bit(lc->get_score_var(), varmap, freeset, false);
      }
      else if (c->get_kind() == flwor_clause::window_clause)
      {
        const window_clause* wc = static_cast<const window_clause *>(c);

        set_bit(wc->get_var(), varmap, freeset, false);

        flwor_wincond* startCond = wc->get_win_start();
        flwor_wincond* stopCond = wc->get_win_stop();

        if (startCond != NULL)
          remove_wincond_vars(startCond, varmap, freeset);

        if (stopCond != NULL)
          remove_wincond_vars(stopCond, varmap, freeset);
      }
      else if (c->get_kind() == flwor_clause::group_clause)
      {
        const group_clause* gc = static_cast<const group_clause *>(c);

        const flwor_clause::rebind_list_t& gvars = gc->get_grouping_vars();
        csize numGroupVars = gvars.size();

        for (csize i = 0; i < numGroupVars; ++i)
        {
          set_bit(gvars[i].second, varmap, freeset, false);
        }

        const flwor_clause::rebind_list_t& ngvars = gc->get_nongrouping_vars();
        csize numNonGroupVars = ngvars.size();

        for (csize i = 0; i < numNonGroupVars; ++i)
        {
          set_bit(ngvars[i].second, varmap, freeset, false);
        }
      }
      else if (c->get_kind() == flwor_clause::count_clause)
      {
        const count_clause* cc = static_cast<const count_clause *>(c);

        set_bit(cc->get_var(), varmap, freeset, false);
      }
    }
  }
  else if (e->get_expr_kind() == trycatch_expr_kind)
  {
    trycatch_expr* trycatch = static_cast<trycatch_expr*>(e);

    csize numClauses = trycatch->clause_count();

    for (csize i = 0; i < numClauses; ++i)
    {
      const catch_clause* clause = (*trycatch)[i];

      catch_clause::var_map_t& trycatchVars =
        const_cast<catch_clause*>(clause)->get_vars();

      catch_clause::var_map_t::const_iterator ite = trycatchVars.begin();
      catch_clause::var_map_t::const_iterator end = trycatchVars.end();
      for (; ite != end; ++ite)
      {
        var_expr* trycatchVar = (*ite).second;
        set_bit(trycatchVar, varmap, freeset, false);
      }
    }
  }

  freevarMap[e] = freeset;
}


/*******************************************************************************

********************************************************************************/
static void remove_wincond_vars(
    const flwor_wincond* cond,
    const VarIdMap& varmap,
    DynamicBitset& freeset)
{
  const flwor_wincond::vars& inVars = cond->get_in_vars();
  const flwor_wincond::vars& outVars = cond->get_out_vars();

  set_bit(inVars.posvar, varmap, freeset, false);
  set_bit(inVars.curr, varmap, freeset, false);
  set_bit(inVars.prev, varmap, freeset, false);
  set_bit(inVars.next, varmap, freeset, false);

  set_bit(outVars.posvar, varmap, freeset, false);
  set_bit(outVars.curr, varmap, freeset, false);
  set_bit(outVars.prev, varmap, freeset, false);
  set_bit(outVars.next, varmap, freeset, false);
}


/*******************************************************************************

********************************************************************************/
static void set_bit(
    var_expr* v,
    const VarIdMap& varmap,
    DynamicBitset& freeset,
    bool value)
{
  if (v == NULL)
    return;

  VarIdMap::const_iterator i = varmap.find(v);
  if (i != varmap.end())
    freeset.set(i->second, value);
}


}
}

/* vim:set et sw=2 ts=2: */
