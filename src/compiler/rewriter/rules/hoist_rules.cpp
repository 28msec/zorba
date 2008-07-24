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

namespace zorba {

static void add_var(var_expr *v, int& counter, std::map<var_expr *, int>& varmap)
{
  if (v != NULL) {
    varmap[v] = counter++;
  }
}

static void index_flvars(expr *e, int& counter, std::map<var_expr *, int>& varmap)
{
  if (e->get_expr_kind() == flwor_expr_kind) {
    flwor_expr *flwor = static_cast<flwor_expr *>(e);
    for(flwor_expr::clause_list_t::iterator i = flwor->clause_begin(); i != flwor->clause_end(); ++i) {
      forlet_clause *flc = &*(*i);
      add_var(&*flc->get_var(), counter, varmap);
      add_var(&*flc->get_pos_var(), counter, varmap);
      add_var(&*flc->get_score_var(), counter, varmap);
    }
    for(flwor_expr::group_list_t::const_iterator i = flwor->group_begin(); i != flwor->group_end(); ++i) {
      group_clause *gc = &*(*i);
      add_var(&*gc->getInnerVar(), counter, varmap);
    }
    for(flwor_expr::group_list_t::const_iterator i = flwor->non_group_begin(); i != flwor->non_group_end(); ++i) {
      group_clause *gc = &*(*i);
      add_var(&*gc->getInnerVar(), counter, varmap);
    }
  }
  expr_iterator i = e->expr_begin();
  while(!i.done()) {
    expr *ce = &*(*i);
    if (ce) {
      index_flvars(ce, counter, varmap);
    }
    ++i;
  }
}

static void set_bit(var_expr *v, const std::map<var_expr *, int>& varmap, DynamicBitset& freeset, bool value)
{
  if (v == NULL) {
    return;
  }
  std::map<var_expr *, int>::const_iterator i = varmap.find(v);
  if (i != varmap.end()) {
    freeset.set(i->second, value);
  }
}

static void compute_freevars(expr *e, const std::map<var_expr *, int>& varmap, std::map<expr *, DynamicBitset>& freevarMap, DynamicBitset& freeset, int counter)
{
  if (e->get_expr_kind() == var_expr_kind) {
    set_bit(static_cast<var_expr *>(e), varmap, freeset, true);
    return;
  }
  DynamicBitset eFreeset(counter);
  expr_iterator i = e->expr_begin();
  while(!i.done()) {
    expr *ce = &*(*i);
    if (ce) {
      eFreeset.reset();
      compute_freevars(ce, varmap, freevarMap, eFreeset, counter);
      freeset.set_union(eFreeset);
    }
    ++i;
  }
  if (e->get_expr_kind() == flwor_expr_kind) {
    flwor_expr *flwor = static_cast<flwor_expr *>(e);
    for(flwor_expr::clause_list_t::iterator i = flwor->clause_begin(); i != flwor->clause_end(); ++i) {
      forlet_clause *flc = &*(*i);
      set_bit(&*flc->get_var(), varmap, freeset, false);
      set_bit(&*flc->get_pos_var(), varmap, freeset, false);
      set_bit(&*flc->get_score_var(), varmap, freeset, false);
    }
    for(flwor_expr::group_list_t::const_iterator i = flwor->group_begin(); i != flwor->group_end(); ++i) {
      group_clause *gc = &*(*i);
      set_bit(&*gc->getInnerVar(), varmap, freeset, false);
    }
    for(flwor_expr::group_list_t::const_iterator i = flwor->non_group_begin(); i != flwor->non_group_end(); ++i) {
      group_clause *gc = &*(*i);
      set_bit(&*gc->getInnerVar(), varmap, freeset, false);
    }
  }
  freevarMap[e] = freeset;

}

struct flwor_holder {
  struct flwor_holder *prev;
  rchandle<flwor_expr> flwor;
  int clause_count;

  flwor_holder()
    : prev(NULL),
    clause_count(0) { }
};

static bool contains_var(var_expr *v, const std::map<var_expr *, int>& varmap, const DynamicBitset& varset)
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

static bool contains_node_construction(expr *e)
{
  if (e->get_expr_kind() == elem_expr_kind
    || e->get_expr_kind() == attr_expr_kind
    || e->get_expr_kind() == text_expr_kind
    || e->get_expr_kind() == doc_expr_kind
    || e->get_expr_kind() == pi_expr_kind
    || e->get_expr_kind() == constructor_expr_kind) {
    return true;
  }
  expr_iterator i = e->expr_begin();
  while(!i.done()) {
    expr *ce = &*(*i);
    if (ce) {
      if (contains_node_construction(ce)) {
        return true;
      }
    }
    ++i;
  }
  return false;
}

static rchandle<var_expr> try_hoisting(RewriterContext& rCtx, expr *e, const std::map<var_expr *, int>& varmap, const std::map<expr *, DynamicBitset>& freevarMap, struct flwor_holder *holder)
{
  if (e->get_expr_kind() == var_expr_kind
    || e->get_expr_kind() == const_expr_kind
    || e->get_expr_kind() == axis_step_expr_kind
    || e->get_expr_kind() == match_expr_kind) {
    return NULL;
  }
  if (contains_node_construction(e)) {
    return NULL;
  }
  std::map<expr *, DynamicBitset>::const_iterator fvme = freevarMap.find(e);
  ZORBA_ASSERT(fvme != freevarMap.end());
  const DynamicBitset& varset = fvme->second;
  bool inloop = false;
  struct flwor_holder *h = holder;
  int i;
  bool found = false;
  while(h->prev != NULL && !found) {
    // If any free variable is a group-by variable, give up.
    for(flwor_expr::group_list_t::const_iterator j = h->flwor->group_begin(); j != h->flwor->group_end(); ++j) {
      group_clause *gc = &*(*j);
      if (contains_var(&*gc->getInnerVar(), varmap, varset)) {
        return NULL;
      }
    }
    for(flwor_expr::group_list_t::const_iterator j = h->flwor->non_group_begin(); j != h->flwor->non_group_end(); ++j) {
      group_clause *gc = &*(*j);
      if (contains_var(&*gc->getInnerVar(), varmap, varset)) {
        return NULL;
      }
    }
     
    for(i = h->clause_count - 1; i >= 0; --i) {
      forlet_clause *flc = (*h->flwor)[i];
      if (contains_var(flc->get_var(), varmap, varset)
        || contains_var(flc->get_pos_var(), varmap, varset)
        || contains_var(flc->get_score_var(), varmap, varset)) {
        found = true;
        break;
      }
      inloop = inloop || (flc->get_type() == forlet_clause::for_clause);
    }
    if (!found) {
      h = h->prev;
    }
  }
  if (!inloop) {
    return NULL;
  }
  rchandle<var_expr> letvar(rCtx.createTempVar(e->get_loc(), var_expr::let_var));
  flwor_expr::forletref_t flref(new forlet_clause(forlet_clause::let_clause, letvar, NULL, NULL, e));
  letvar->set_forlet_clause(flref.getp());
  if (h->prev == NULL) {
    if (h->flwor == NULL) {
      h->flwor = new flwor_expr(e->get_loc());
    }
    h->flwor->add(flref);
  } else {
    h->flwor->add(i + 1, flref);
    ++h->clause_count;
  }
  return letvar;
}

static bool hoist_expressions(RewriterContext& rCtx, expr *e, const std::map<var_expr *, int>& varmap, const std::map<expr *, DynamicBitset>& freevarMap, struct flwor_holder *fholder)
{
  bool status = false;
  if (e->get_expr_kind() == flwor_expr_kind) {
    flwor_expr *flwor = static_cast<flwor_expr *>(e);

    struct flwor_holder curr_holder;
    curr_holder.prev = fholder;
    curr_holder.flwor = &*flwor;

    int i = 0;
    while((unsigned)i < flwor->forlet_count()) {
      forlet_clause *flc = &*((*flwor)[i]);
      expr *flcexpr = flc->get_expr();
      rchandle<var_expr> var = try_hoisting(rCtx, flcexpr, varmap, freevarMap, &curr_holder);
      if (var != NULL) {
        flc->set_expr(var.getp());
        status = true;
      } else {
        status = hoist_expressions(rCtx, flcexpr, varmap, freevarMap, &curr_holder) || status;
      }
      i = ++(curr_holder.clause_count);
    }
    expr_t we = flwor->get_where();
    if (we != NULL) {
      rchandle<var_expr> wvar = try_hoisting(rCtx, we, varmap, freevarMap, &curr_holder);
      if (wvar != NULL) {
        flwor->set_where(wvar.getp());
        status = true;
      } else {
        status = hoist_expressions(rCtx, we, varmap, freevarMap, &curr_holder) || status;
      }
    }

    expr_t re = flwor->get_retval();
    rchandle<var_expr> rvar = try_hoisting(rCtx, re, varmap, freevarMap, &curr_holder);
    if (rvar != NULL) {
      flwor->set_retval(rvar.getp());
      status = true;
    } else {
      status = hoist_expressions(rCtx, re, varmap, freevarMap, &curr_holder) || status;
    }
  } else {
    expr_iterator i = e->expr_begin();
    while(!i.done()) {
      expr *ce = &*(*i);
      if (ce) {
        rchandle<var_expr> var = try_hoisting(rCtx, ce, varmap, freevarMap, fholder);
        if (var != NULL) {
          *i = var.getp();
          status = true;
        } else {
          status = hoist_expressions(rCtx, ce, varmap, freevarMap, fholder) || status;
        }
      }
      ++i;
    }
  }

  return status;
}

RULE_REWRITE_PRE(HoistExprsOutOfLoops)
{
  if (node != rCtx.getRoot()) {
    return NULL;
  }
  int counter = 0;
  std::map<var_expr *, int> varmap;

  index_flvars(node, counter, varmap);

  std::map<expr *, DynamicBitset> freevarMap;
  DynamicBitset freeset(counter);
  compute_freevars(node, varmap, freevarMap, freeset, counter);

  struct flwor_holder root;
  if (hoist_expressions(rCtx, node, varmap, freevarMap, &root)) {
    if (root.flwor != NULL) {
      root.flwor->set_retval(node);
      return root.flwor;
    }
    return node;
  }

  return NULL;
}

RULE_REWRITE_POST(HoistExprsOutOfLoops)
{
  return NULL;
}

}
/* vim:set ts=2 sw=2: */
