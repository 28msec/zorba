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

#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/expression/flwor_expr.h"

namespace zorba
{

static void add_wincond_vars(const flwor_wincond*, int&, VarIdMap&, IdVarMap*);

static void add_var(var_expr*, int&, VarIdMap&, IdVarMap*);

static void remove_wincond_vars(const flwor_wincond*, const VarIdMap&, DynamicBitset&);

static void set_bit(var_expr*, const std::map<var_expr*, int>&, DynamicBitset&, bool);


/*******************************************************************************
  Replace all references to "oldVar" inside "e" with references to "newVar".
********************************************************************************/
void replace_var(expr* e, var_expr* oldVar, var_expr* newVar)
{
  if (e->get_expr_kind() == wrapper_expr_kind)
  {
    wrapper_expr* wrapper = reinterpret_cast<wrapper_expr*>(e);

    if (wrapper->get_expr().getp() == oldVar)
    {
      wrapper->set_expr(newVar);
      return;
    }
  }

  expr_iterator iter = e->expr_begin();
  while (!iter.done())
  {
    replace_var((*iter), oldVar, newVar);
    ++iter;
  }
}


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
    expr* e,
    int& numVars,
    VarIdMap& varidmap,
    IdVarMap* idvarmap)
{
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

        add_var(fc->get_var(), numVars, varidmap, idvarmap);
        add_var(fc->get_pos_var(), numVars, varidmap, idvarmap);
        add_var(fc->get_score_var(), numVars, varidmap, idvarmap);
      }
      else if (c->get_kind() == flwor_clause::let_clause)
      {
        const let_clause* lc = static_cast<const let_clause *>(c);

        add_var(lc->get_var(), numVars, varidmap, idvarmap);
        add_var(lc->get_score_var(), numVars, varidmap, idvarmap);
      }
      else if (c->get_kind() == flwor_clause::window_clause)
      {
        const window_clause* wc = static_cast<const window_clause *>(c);

        add_var(wc->get_var(), numVars, varidmap, idvarmap);

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
        unsigned numGroupVars = gvars.size();

        for (unsigned i = 0; i < numGroupVars; ++i)
        {
          add_var(gvars[i].second.getp(), numVars, varidmap, idvarmap);
        }

        const flwor_clause::rebind_list_t& ngvars = gc->get_nongrouping_vars();
        unsigned numNonGroupVars = ngvars.size();

        for (unsigned i = 0; i < numNonGroupVars; ++i)
        {
          add_var(ngvars[i].second.getp(), numVars, varidmap, idvarmap);
        }
      }
      else if (c->get_kind() == flwor_clause::count_clause)
      {
        const count_clause* cc = static_cast<const count_clause *>(c);

        add_var(cc->get_var(), numVars, varidmap, idvarmap);
      }
    }
  }

  expr_iterator i = e->expr_begin();
  while(!i.done()) 
  {
    expr* ce = &*(*i);
    if (ce) 
    {
      index_flwor_vars(ce, numVars, varidmap, idvarmap);
    }
    ++i;
  }
}


/*******************************************************************************

********************************************************************************/
static void add_wincond_vars(
    const flwor_wincond* cond,
    int& numVars,
    VarIdMap& varidmap,
    IdVarMap* idvarmap)
{
  const flwor_wincond::vars& inVars = cond->get_in_vars();
  const flwor_wincond::vars& outVars = cond->get_out_vars();
          
  add_var(inVars.posvar.getp(), numVars, varidmap, idvarmap);
  add_var(inVars.curr.getp(), numVars, varidmap, idvarmap);
  add_var(inVars.prev.getp(), numVars, varidmap, idvarmap);
  add_var(inVars.next.getp(), numVars, varidmap, idvarmap);
          
  add_var(outVars.posvar.getp(), numVars, varidmap, idvarmap);
  add_var(outVars.curr.getp(), numVars, varidmap, idvarmap);
  add_var(outVars.prev.getp(), numVars, varidmap, idvarmap);
  add_var(outVars.next.getp(), numVars, varidmap, idvarmap);
}


/*******************************************************************************

********************************************************************************/
static void add_var(var_expr* v, int& numVars, VarIdMap& varidmap, IdVarMap* idvarmap)
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
void find_flwor_vars(
    expr* e,
    const VarIdMap& varmap,
    DynamicBitset& freeset,
    ExprVarsMap& freevarMap)
{
  if (e->get_expr_kind() == var_expr_kind) 
  {
    set_bit(static_cast<var_expr *>(e), varmap, freeset, true);
    return;
  }

  int numVars = freeset.size();

  DynamicBitset eFreeset(numVars);
  expr_iterator i = e->expr_begin();
  while(!i.done()) 
  {
    expr* ce = &*(*i);
    if (ce) 
    {
      eFreeset.reset();
      find_flwor_vars(ce, varmap, eFreeset, freevarMap);
      freeset.set_union(eFreeset);
    }
    ++i;
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
        unsigned numGroupVars = gvars.size();

        for (unsigned i = 0; i < numGroupVars; ++i)
        {
          set_bit(gvars[i].second.getp(), varmap, freeset, false);
        }

        const flwor_clause::rebind_list_t& ngvars = gc->get_nongrouping_vars();
        unsigned numNonGroupVars = ngvars.size();
        
        for (unsigned i = 0; i < numNonGroupVars; ++i)
        {
          set_bit(ngvars[i].second.getp(), varmap, freeset, false);
        }
      }
      else if (c->get_kind() == flwor_clause::count_clause)
      {
        const count_clause* cc = static_cast<const count_clause *>(c);

        set_bit(cc->get_var(), varmap, freeset, false);
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

  set_bit(inVars.posvar.getp(), varmap, freeset, false);
  set_bit(inVars.curr.getp(), varmap, freeset, false);
  set_bit(inVars.prev.getp(), varmap, freeset, false);
  set_bit(inVars.next.getp(), varmap, freeset, false);

  set_bit(outVars.posvar.getp(), varmap, freeset, false);
  set_bit(outVars.curr.getp(), varmap, freeset, false);
  set_bit(outVars.prev.getp(), varmap, freeset, false);
  set_bit(outVars.next.getp(), varmap, freeset, false);
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

  std::map<var_expr *, int>::const_iterator i = varmap.find(v);
  if (i != varmap.end())
    freeset.set(i->second, value);
}


}

