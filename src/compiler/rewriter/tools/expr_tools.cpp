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

static void add_var(var_expr*, int&, VarIdMap&, IdVarMap*);

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
  if (e->get_expr_kind() == flwor_expr_kind) 
  {
    flwor_expr* flwor = static_cast<flwor_expr *>(e);
    for(flwor_expr::forlet_list_t::iterator i = flwor->forlet_begin();
        i != flwor->forlet_end();
        ++i) 
    {
      forlet_clause* flc = &*(*i);
      add_var(&*flc->get_var(), numVars, varidmap, idvarmap);
      add_var(&*flc->get_pos_var(), numVars, varidmap, idvarmap);
      add_var(&*flc->get_score_var(), numVars, varidmap, idvarmap);
    }

    for(flwor_expr::group_list_t::const_iterator i = flwor->group_vars_begin();
        i != flwor->group_vars_end();
        ++i) 
    {
      group_clause* gc = &*(*i);
      add_var(&*gc->getInnerVar(), numVars, varidmap, idvarmap);
    }

    for(flwor_expr::group_list_t::const_iterator i = flwor->non_group_vars_begin();
        i != flwor->non_group_vars_end(); ++i)
    {
      group_clause* gc = &*(*i);
      add_var(&*gc->getInnerVar(), numVars, varidmap, idvarmap);
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
static void add_var(
    var_expr* v,
    int& numVars,
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
  set. V(E) is implemented as a bitset whose size is equal to the size of FV(e)
  and whose i-th bit is on iff the var with prefix id i belongs to V(E). The
  mapping between E and V(E) is stored in "freevarMap".  
********************************************************************************/
void find_flwor_vars(
    expr* e,
    const VarIdMap& varmap,
    ExprVarsMap& freevarMap,
    DynamicBitset& freeset)
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
      find_flwor_vars(ce, varmap, freevarMap, eFreeset);
      freeset.set_union(eFreeset);
    }
    ++i;
  }

  // A flwor does not depend on the vars that are defined inside the flwor itself,
  // so remove these vars from the freeset of the flwor, if they have been added
  // there.
  if (e->get_expr_kind() == flwor_expr_kind) 
  {
    flwor_expr* flwor = static_cast<flwor_expr *>(e);
    for(flwor_expr::forlet_list_t::iterator i = flwor->forlet_begin();
        i != flwor->forlet_end(); ++i)
    {
      forlet_clause* flc = &*(*i);
      set_bit(&*flc->get_var(), varmap, freeset, false);
      set_bit(&*flc->get_pos_var(), varmap, freeset, false);
      set_bit(&*flc->get_score_var(), varmap, freeset, false);
    }

    for(flwor_expr::group_list_t::const_iterator i = flwor->group_vars_begin();
        i != flwor->group_vars_end();
        ++i) 
    {
      group_clause* gc = &*(*i);
      set_bit(&*gc->getInnerVar(), varmap, freeset, false);
    }

    for(flwor_expr::group_list_t::const_iterator i = flwor->non_group_vars_begin();
        i != flwor->non_group_vars_end();
        ++i) 
    {
      group_clause *gc = &*(*i);
      set_bit(&*gc->getInnerVar(), varmap, freeset, false);
    }
  }

  freevarMap[e] = freeset;
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

