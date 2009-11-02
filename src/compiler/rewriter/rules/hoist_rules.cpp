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
#include "compiler/expression/flwor_expr.h"

#include "util/dynamic_bitset.h"

using namespace std;

namespace zorba 
{

static bool hoist_expressions(
    RewriterContext&,
    expr*,
    const std::map<const var_expr*, int>&,
    const ExprVarsMap&,
    struct flwor_holder*);

static expr_t try_hoisting(
    RewriterContext&,
    expr*,
    const std::map<const var_expr*, int>&,
    const ExprVarsMap&,
    struct flwor_holder*);

static bool non_hoistable (const expr*);

static bool is_already_hoisted(const expr*);

static bool contains_var(
    var_expr*,
    const std::map<const var_expr*, int>&,
    const DynamicBitset&);

static bool contains_node_construction(const expr*);

static bool is_enclosed_expr(const expr*);

static bool contains_updates(const expr*);


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

  int numVars = 0;
  std::map<const var_expr *, int> varmap;

  index_flwor_vars(node, numVars, varmap, NULL);

  ExprVarsMap freevarMap;
  DynamicBitset freeset(numVars);
  find_flwor_vars(node, varmap, freeset, freevarMap);

  struct flwor_holder root;
  if (hoist_expressions(rCtx, node, varmap, freevarMap, &root)) 
  {
    if (root.flwor != NULL) 
    {
      root.flwor->set_return_expr(node);
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

********************************************************************************/
static bool hoist_expressions(
    RewriterContext& rCtx,
    expr* e,
    const std::map<const var_expr *, int>& varmap,
    const ExprVarsMap& freevarMap,
    struct flwor_holder* fholder)
{
  bool status = false;
  if (e->get_expr_kind() == flwor_expr_kind) 
  {
    flwor_expr* flwor = static_cast<flwor_expr *>(e);

    struct flwor_holder curr_holder;
    curr_holder.prev = fholder;
    curr_holder.flwor = &*flwor;

    ulong numForLetClauses = flwor->num_forlet_clauses();
    ulong i = 0;
    while(i < numForLetClauses) 
    {
      forletwin_clause* flc = static_cast<forletwin_clause*>(flwor->get_clause(i, true));

      expr* domainExpr = flc->get_expr();

      expr_t var = try_hoisting(rCtx, domainExpr, varmap, freevarMap, &curr_holder);
      if (var != NULL) 
      {
        flc->set_expr(var.getp());
        numForLetClauses = flwor->num_forlet_clauses();
        status = true;
      }
      else 
      {
        status = hoist_expressions(rCtx, domainExpr, varmap, freevarMap, &curr_holder) ||
                 status;

        if (status)
          numForLetClauses = flwor->num_forlet_clauses();
      }

      i = ++(curr_holder.clause_count);

      assert(numForLetClauses == flwor->num_forlet_clauses());
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

    expr_t re = flwor->get_return_expr(false);
    expr_t rvar = try_hoisting(rCtx, re, varmap, freevarMap, &curr_holder);
    if (rvar != NULL) 
    {
      flwor->set_return_expr(rvar.getp());
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
    expr* e,
    const std::map<const var_expr*, int>& varmap,
    const ExprVarsMap& freevarMap,
    struct flwor_holder* holder)
{
  if (non_hoistable (e) || 
      contains_node_construction(e) ||
      is_enclosed_expr(e)) 
  {
    return NULL;
  }

  std::map<const expr*, DynamicBitset>::const_iterator fvme = freevarMap.find(e);
  ZORBA_ASSERT(fvme != freevarMap.end());
  const DynamicBitset& varset = fvme->second;
  bool inloop = false;
  struct flwor_holder* h = holder;
  int i = 0;
  bool found = false;

  while(h->prev != NULL && !found) 
  {
    group_clause* gc = h->flwor->get_group_clause();

    // If any free variable is a group-by variable, give up.
    if (gc != NULL)
    {
      for(flwor_expr::clause_list_t::const_iterator iter = h->flwor->clause_begin();
          iter != h->flwor->clause_end();
          ++iter)
      {
        if ((*iter) != gc)
          continue;

        const flwor_clause::rebind_list_t& gvars = gc->get_grouping_vars();
        unsigned numGroupVars = gvars.size();

        for (unsigned i = 0; i < numGroupVars; ++i)
        {
          if (contains_var(gvars[i].second.getp(), varmap, varset))
            return NULL;
        }
      }

      for(flwor_expr::clause_list_t::const_iterator iter = h->flwor->clause_begin();
          iter != h->flwor->clause_end();
          ++iter) 
      {
        if ((*iter) != gc)
          continue;

        const flwor_clause::rebind_list_t& ngvars = gc->get_nongrouping_vars();
        unsigned numNonGroupVars = ngvars.size();

        for (unsigned i = 0; i < numNonGroupVars; ++i)
        {
          if (contains_var(ngvars[i].second.getp(), varmap, varset))
            return NULL;
        }
      }
    }

    // Check whether expr e references any variables from the current flwor. If 
    // not, then move to the previous (outer) flwor. If yes, then let V be the
    // inner-most var referenced by e. If there are any FOR vars after V, e can
    // be hoisted out of any such FOR vars. Otherwise, e cannot be hoisted.  
    for(i = h->clause_count - 1; i >= 0; --i) 
    {
      const forletwin_clause* flc = reinterpret_cast<const forletwin_clause*>
                                    ((*h->flwor)[i]);

      if (contains_var(flc->get_var(), varmap, varset) ||
          contains_var(flc->get_pos_var(), varmap, varset) ||
          contains_var(flc->get_score_var(), varmap, varset)) 
      {
        found = true;
        break;
      }
      inloop = inloop || (flc->get_kind() == flwor_clause::for_clause);
    }

    if (!found)
      h = h->prev;
  }

  if (!inloop)
    return NULL;

  // Hoisting is possible ... Go ahead and hoist e: (a) we create an internal LET
  // var: $$temp := opext:hoist(e) (b) we place the $$temp declaration right after
  // variable V, and (c) we replace e with opext:unhoist($$temp).

  rchandle<var_expr> letvar(rCtx.createTempVar(e->get_sctx_id(), e->get_loc(), var_expr::let_var));
  expr_t hoisted = new fo_expr(e->get_sctx_id(), e->get_loc(), LOOKUP_OP1("hoist"), e);
  let_clause_t flref(new let_clause(e->get_sctx_id(), e->get_loc(), letvar, hoisted));
  letvar->set_flwor_clause(flref.getp());

  if (h->prev == NULL) 
  {
    if (h->flwor == NULL) 
    {
      h->flwor = new flwor_expr(e->get_sctx_id(), e->get_loc(), false);
    }
    h->flwor->add_clause(flref);
  }
  else 
  {
    h->flwor->add_clause(i + 1, flref);
    ++h->clause_count;
  }

  expr_t unhoisted = new fo_expr(e->get_sctx_id(), e->get_loc(), LOOKUP_OP1("unhoist"), letvar.getp());
  return unhoisted.getp();
}


/*******************************************************************************
  Check if the given var is contained in the given varset.
********************************************************************************/
static bool contains_var(
    var_expr* v,
    const std::map<const var_expr *, int>& varmap,
    const DynamicBitset& varset)
{
  if (v == NULL) 
  {
    return false;
  }

  std::map<const var_expr *, int>::const_iterator i = varmap.find(v);
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

  return (k == var_expr_kind ||
          k == const_expr_kind ||
          k == axis_step_expr_kind ||
          k == match_expr_kind ||
          (k == wrapper_expr_kind && 
           non_hoistable(static_cast<const wrapper_expr*>(e)->get_expr()))  ||
          is_already_hoisted(e));
}


/*******************************************************************************

********************************************************************************/
static bool is_already_hoisted(const expr* e)
{
  if (e->get_expr_kind() == fo_expr_kind) 
  {
    return static_cast<const fo_expr *>(e)->get_func() == LOOKUP_OP1("unhoist");
  }
  return false;
}


/*******************************************************************************
  Check if the expr tree rooted at e contains any node-constructor expr. If so,
  e cannot be hoisted.
********************************************************************************/
static bool contains_node_construction(const expr *e)
{
  if (e->get_expr_kind() == elem_expr_kind
      || e->get_expr_kind() == attr_expr_kind
      || e->get_expr_kind() == text_expr_kind
      || e->get_expr_kind() == doc_expr_kind
      || e->get_expr_kind() == pi_expr_kind)
  {
    return true;
  }

  const_expr_iterator i = e->expr_begin_const();
  while(!i.done()) 
  {
    const expr* ce = &*(*i);
    if (ce) 
    {
      if (contains_node_construction(ce)) 
      {
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
static bool is_enclosed_expr(const expr* e)
{
  if (e->get_expr_kind() != fo_expr_kind)
    return false;

  const function* fn = static_cast<const fo_expr *>(e)->get_func();
  return (fn->CHECK_IS_BUILTIN_NAMED(":enclosed-expr", 1));
}


/*******************************************************************************

********************************************************************************/
static bool contains_updates(const expr* e)
{
  if (e->is_updating())
    return true;

  const_expr_iterator i = e->expr_begin_const();
  while(!i.done()) 
  {
    const expr* ce = &*(*i);
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
