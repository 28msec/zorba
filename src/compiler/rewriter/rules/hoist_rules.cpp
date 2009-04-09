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
#include <map>
#include "context/static_context.h"
#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/expression/expr.h"

#include "util/dynamic_bitset.h"

using namespace std;

namespace zorba 
{

static void index_flvars(expr*, int&, std::map<var_expr *, int>&);

static void compute_freevars(expr*, const std::map<var_expr*, int>&, std::map<expr*, DynamicBitset>&, DynamicBitset&, int);

static bool hoist_expressions(RewriterContext&, expr*, const std::map<var_expr*, int>&, const std::map<expr*, DynamicBitset>&, struct flwor_holder*);

static expr_t try_hoisting(RewriterContext&, expr*, const std::map<var_expr*, int>&, const std::map<expr*, DynamicBitset>&, struct flwor_holder*);

static bool non_hoistable (expr*);

static bool is_already_hoisted(expr*);

static void add_var(var_expr*, int&, std::map<var_expr *, int>&);

static void set_bit(var_expr*, const std::map<var_expr*, int>&, DynamicBitset&, bool);

static bool contains_var(var_expr*, const std::map<var_expr*, int>&, const DynamicBitset&);

static bool contains_node_construction(expr*);

static bool is_enclosed_expr(expr*);

static bool contains_updates(expr*);


/*******************************************************************************
  Used to implement a stack of flwor exprs.
********************************************************************************/
struct flwor_holder 
{
  struct flwor_holder  * prev;
  rchandle<flwor_expr>   flwor;
  int                    clause_count;

  flwor_holder() : prev(NULL), clause_count(0) { }
};


/*******************************************************************************
  This rule looks for exprs that are inside a for loop but do not depend on the
  loop variable, and then moves such exprs outside the loop.
********************************************************************************/
RULE_REWRITE_PRE(HoistExprsOutOfLoops)
{
  if (node != rCtx.getRoot())
    return NULL;

  if (contains_updates(node))
    return NULL;

  int counter = 0;
  std::map<var_expr *, int> varmap;

  index_flvars(node, counter, varmap);

  std::map<expr *, DynamicBitset> freevarMap;
  DynamicBitset freeset(counter);
  compute_freevars(node, varmap, freevarMap, freeset, counter);

  struct flwor_holder root;
  if (hoist_expressions(rCtx, node, varmap, freevarMap, &root)) 
  {
    if (root.flwor != NULL) 
    {
      root.flwor->set_retval(node);
      return root.flwor.getp();
    }
    return node;
  }

  return NULL;
}


RULE_REWRITE_POST(HoistExprsOutOfLoops)
{
  return NULL;
}


/*******************************************************************************
  Let FLWOR(e) be the set of flwor exprs within the expr tree rooted at expr e.
  Let FV(e) be the set of variables defined in any of the flwor exprs in FLWOR(e).
  This method assigns a prefix id to each variable in FV(e) and stores the mapping
  between var_expr and prefix id in "varmap".

  Given 2 vars v1 and v2 in FV(e), their prefix ids allows to check if v1 is
  defined before v2: v1 is defined before v2 iff id(v1) < id(v2). 
********************************************************************************/
static void index_flvars(expr* e, int& counter, std::map<var_expr *, int>& varmap)
{
  if (e->get_expr_kind() == flwor_expr_kind) 
  {
    flwor_expr *flwor = static_cast<flwor_expr *>(e);
    for(flwor_expr::forlet_list_t::iterator i = flwor->forlet_begin();
        i != flwor->forlet_end();
        ++i) 
    {
      forlet_clause *flc = &*(*i);
      add_var(&*flc->get_var(), counter, varmap);
      add_var(&*flc->get_pos_var(), counter, varmap);
      add_var(&*flc->get_score_var(), counter, varmap);
    }

    for(flwor_expr::group_list_t::const_iterator i = flwor->group_vars_begin();
        i != flwor->group_vars_end();
        ++i) 
    {
      group_clause *gc = &*(*i);
      add_var(&*gc->getInnerVar(), counter, varmap);
    }

    for(flwor_expr::group_list_t::const_iterator i = flwor->non_group_vars_begin();
        i != flwor->non_group_vars_end(); ++i)
    {
      group_clause *gc = &*(*i);
      add_var(&*gc->getInnerVar(), counter, varmap);
    }
  }

  expr_iterator i = e->expr_begin();
  while(!i.done()) 
  {
    expr *ce = &*(*i);
    if (ce) 
    {
      index_flvars(ce, counter, varmap);
    }
    ++i;
  }
}


/*******************************************************************************

********************************************************************************/
static void add_var(var_expr *v, int& counter, std::map<var_expr *, int>& varmap)
{
  if (v != NULL)
    varmap[v] = counter++;
}


/*******************************************************************************
  For each expr E in the expr tree rooted at "e", this method computes the set
  of variables that belong to FV(e) and are referenced by E. Let V(E) be this
  set. V(E) is implemented as a bitset whose size is equal to the size of FV(e)
  and whose i-th bit is on iff the var with prefix id i belongs to V(E). The
  mapping between E and V(E) is stored in "freevarMap".  
********************************************************************************/
static void compute_freevars(
    expr* e,
    const std::map<var_expr *, int>& varmap,
    std::map<expr *, DynamicBitset>& freevarMap,
    DynamicBitset& freeset,
    int counter)
{
  if (e->get_expr_kind() == var_expr_kind) 
  {
    set_bit(static_cast<var_expr *>(e), varmap, freeset, true);
    return;
  }

  DynamicBitset eFreeset(counter);
  expr_iterator i = e->expr_begin();
  while(!i.done()) 
  {
    expr* ce = &*(*i);
    if (ce) 
    {
      eFreeset.reset();
      compute_freevars(ce, varmap, freevarMap, eFreeset, counter);
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
    var_expr *v,
    const std::map<var_expr *, int>& varmap,
    DynamicBitset& freeset,
    bool value)
{
  if (v == NULL)
    return;

  std::map<var_expr *, int>::const_iterator i = varmap.find(v);
  if (i != varmap.end())
    freeset.set(i->second, value);
}


/*******************************************************************************

********************************************************************************/
static bool hoist_expressions(
    RewriterContext& rCtx,
    expr* e,
    const std::map<var_expr *, int>& varmap,
    const std::map<expr *, DynamicBitset>& freevarMap,
    struct flwor_holder* fholder)
{
  bool status = false;
  if (e->get_expr_kind() == flwor_expr_kind) 
  {
    flwor_expr *flwor = static_cast<flwor_expr *>(e);

    struct flwor_holder curr_holder;
    curr_holder.prev = fholder;
    curr_holder.flwor = &*flwor;

    int i = 0;
    while((unsigned)i < flwor->forlet_count()) 
    {
      forlet_clause *flc = &*((*flwor)[i]);
      expr *flcexpr = flc->get_expr();
      expr_t var = try_hoisting(rCtx, flcexpr, varmap, freevarMap, &curr_holder);
      if (var != NULL) 
      {
        flc->set_expr(var.getp());
        status = true;
      }
      else 
      {
        status = hoist_expressions(rCtx, flcexpr, varmap, freevarMap, &curr_holder) ||
                 status;
      }
      i = ++(curr_holder.clause_count);
    }

    expr_t we = flwor->get_where();
    if (we != NULL) 
    {
      expr_t wvar = try_hoisting(rCtx, we, varmap, freevarMap, &curr_holder);
      if (wvar != NULL) 
      {
        flwor->set_where(wvar.getp());
        status = true;
      }
      else
      {
        status = hoist_expressions(rCtx, we, varmap, freevarMap, &curr_holder) || status;
      }
    }

    expr_t re = flwor->get_retval();
    expr_t rvar = try_hoisting(rCtx, re, varmap, freevarMap, &curr_holder);
    if (rvar != NULL) 
    {
      flwor->set_retval(rvar.getp());
      status = true;
    }
    else 
    {
      status = hoist_expressions(rCtx, re, varmap, freevarMap, &curr_holder) || status;
    }
  }
  else if (e->get_expr_kind() == sequential_expr_kind
           || e->is_updating()
           || e->get_expr_kind() == gflwor_expr_kind) 
  {
    // do nothing
  }
  else
  {
    expr_iterator i = e->expr_begin();
    while(!i.done()) 
    {
      expr *ce = &*(*i);
      if (ce) 
      {
        expr_t var = try_hoisting(rCtx, ce, varmap, freevarMap, fholder);
        if (var != NULL)
        {
          *i = var.getp();
          status = true;
        }
        else
        {
          status = hoist_expressions(rCtx, ce, varmap, freevarMap, fholder) || status;
        }
      }
      ++i;
    }
  }

  return status;
}


/*******************************************************************************

********************************************************************************/
static expr_t try_hoisting(
    RewriterContext& rCtx,
    expr *e,
    const std::map<var_expr *, int>& varmap,
    const std::map<expr *, DynamicBitset>& freevarMap,
    struct flwor_holder *holder)
{
  if (non_hoistable (e) || 
      contains_node_construction(e) ||
      is_enclosed_expr(e)) 
  {
    return NULL;
  }

  std::map<expr *, DynamicBitset>::const_iterator fvme = freevarMap.find(e);
  ZORBA_ASSERT(fvme != freevarMap.end());
  const DynamicBitset& varset = fvme->second;
  bool inloop = false;
  struct flwor_holder *h = holder;
  int i = 0;
  bool found = false;

  while(h->prev != NULL && !found) 
  {
    // If any free variable is a group-by variable, give up.
    for(flwor_expr::group_list_t::const_iterator j = h->flwor->group_vars_begin();
        j != h->flwor->group_vars_end();
        ++j) 
    {
      group_clause *gc = &*(*j);
      if (contains_var(&*gc->getInnerVar(), varmap, varset))
        return NULL;
    }

    for(flwor_expr::group_list_t::const_iterator j = h->flwor->non_group_vars_begin();
        j != h->flwor->non_group_vars_end();
        ++j) 
    {
      group_clause *gc = &*(*j);
      if (contains_var(&*gc->getInnerVar(), varmap, varset))
        return NULL;
    }

    // Check whether expr e references any variables from the current flwor. If 
    // not, then move to the previous (outer) flwor. If yes, then let V be the
    // inner-most var referenced by e. If there are any FOR vars after V, e can
    // be hoisted out of any such FOR vars. Otherwise, e cannot be hoisted.  
    for(i = h->clause_count - 1; i >= 0; --i) 
    {
      forlet_clause *flc = (*h->flwor)[i];
      if (contains_var(flc->get_var(), varmap, varset) ||
          contains_var(flc->get_pos_var(), varmap, varset) ||
          contains_var(flc->get_score_var(), varmap, varset)) 
      {
        found = true;
        break;
      }
      inloop = inloop || (flc->get_type() == forlet_clause::for_clause);
    }

    if (!found)
      h = h->prev;
  }

  if (!inloop)
    return NULL;

  // Hoisting is possible ... Go ahead and hoist e: (a) we create an internal LET
  // var: $$temp := opext:hoist(e) (b) we place the $$temp declaration right after
  // variable V, and (c) we replace e with opext:unhoist($$temp).

  rchandle<var_expr> letvar(rCtx.createTempVar(e->get_loc(), var_expr::let_var));
  expr_t hoisted = new fo_expr(e->get_loc(), LOOKUP_OP1("hoist"), e);
  flwor_expr::forletref_t flref(new forlet_clause(forlet_clause::let_clause,
                                                  letvar,
                                                  NULL,
                                                  NULL,
                                                  hoisted));
  letvar->set_forlet_clause(flref.getp());

  if (h->prev == NULL) 
  {
    if (h->flwor == NULL) 
    {
      h->flwor = new flwor_expr(e->get_loc());
    }
    h->flwor->add(flref);
  }
  else 
  {
    h->flwor->add(i + 1, flref);
    ++h->clause_count;
  }

  expr_t unhoisted = new fo_expr(e->get_loc(), LOOKUP_OP1("unhoist"), letvar.getp());
  return unhoisted.getp();
}


/*******************************************************************************
  Check if the given var is contained in the given varset.
********************************************************************************/
static bool contains_var(
    var_expr *v,
    const std::map<var_expr *, int>& varmap,
    const DynamicBitset& varset)
{
  if (v == NULL) {
    return false;
  }
  std::map<var_expr *, int>::const_iterator i = varmap.find(v);
  if (i == varmap.end()) {
    return false;
  }
  int bit = i->second;
  return varset.get(bit);
}


/*******************************************************************************

********************************************************************************/
static bool non_hoistable (expr *e) 
{
  expr_kind_t k = e->get_expr_kind();
  return k == var_expr_kind
    || k == const_expr_kind
    || k == axis_step_expr_kind
    || k == match_expr_kind
    || (k == wrapper_expr_kind && non_hoistable (static_cast<const wrapper_expr *> (e)->get_expr ()))
    || is_already_hoisted(e);
}


/*******************************************************************************

********************************************************************************/
static bool is_already_hoisted(expr *e)
{
  if (e->get_expr_kind() == fo_expr_kind) 
  {
    return static_cast<fo_expr *>(e)->get_func() == LOOKUP_OP1("unhoist");
  }
  return false;
}


/*******************************************************************************
  Check if the expr tree rooted at e contains any node-constructor expr. If so,
  e cannot be hoisted.
********************************************************************************/
static bool contains_node_construction(expr *e)
{
  if (e->get_expr_kind() == elem_expr_kind
    || e->get_expr_kind() == attr_expr_kind
    || e->get_expr_kind() == text_expr_kind
    || e->get_expr_kind() == doc_expr_kind
    || e->get_expr_kind() == pi_expr_kind
    || e->get_expr_kind() == constructor_expr_kind) 
  {
    return true;
  }

  expr_iterator i = e->expr_begin();
  while(!i.done()) 
  {
    expr *ce = &*(*i);
    if (ce) 
    {
      if (contains_node_construction(ce)) {
        return true;
      }
    }
    ++i;
  }
  return false;
}


/*******************************************************************************
  Enclosed exprs cannot be hoisted because they may construct text nodes.
********************************************************************************/
static bool is_enclosed_expr(expr *e)
{
  if (e->get_expr_kind() != fo_expr_kind)
    return false;

  const function *fn = static_cast<fo_expr *>(e)->get_func();
  return (fn == LOOKUP_FN("fn", ":enclosed-expr", 1));
}


/*******************************************************************************

********************************************************************************/
static bool contains_updates(expr *e)
{
  if (e->is_updating())
    return true;

  expr_iterator i = e->expr_begin();
  while(!i.done()) 
  {
    expr *ce = &*(*i);
    if (ce) 
    {
      if (contains_updates(ce))
        return true;
    }
    ++i;
  }

  return false;
}

}
/* vim:set ts=2 sw=2: */
