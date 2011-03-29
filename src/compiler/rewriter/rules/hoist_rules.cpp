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

#include "functions/library.h"
#include "functions/udf.h"

#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/expr_iter.h"

#include "types/typeops.h"

#include "util/dynamic_bitset.h"

#include "zorbaerrors/assert.h"


namespace zorba
{

static bool hoist_expressions(
    RewriterContext&,
    expr*,
    const VarIdMap&,
    const ExprVarsMap&,
    struct flwor_holder*);

static expr_t try_hoisting(
    RewriterContext&,
    expr*,
    const VarIdMap&,
    const ExprVarsMap&,
    struct flwor_holder*);

static bool non_hoistable (const expr*);

static bool is_already_hoisted(const expr*);

static bool contains_var(
    var_expr*,
    const VarIdMap&,
    const DynamicBitset&);

static bool is_enclosed_expr(const expr*);

static bool containsUpdates(const expr*);


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
expr_t HoistRule::apply(
    RewriterContext& rCtx,
    expr* node,
    bool& modified)
{
  assert(node == rCtx.getRoot());

  //  if (containsUpdates(node))
  //   return node;

  ulong numVars = 0;
  VarIdMap varmap;

  index_flwor_vars(node, numVars, varmap, NULL);

  ExprVarsMap freevarMap;
  DynamicBitset freeset(numVars);
  build_expr_to_vars_map(node, varmap, freeset, freevarMap);

  struct flwor_holder root;
  modified = hoist_expressions(rCtx, node, varmap, freevarMap, &root);

  if (modified && root.flwor != NULL)
  {
    root.flwor->set_return_expr(node);
    return root.flwor.getp();
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
    while (i < numForLetClauses)
    {
      forletwin_clause* flc = static_cast<forletwin_clause*>(flwor->get_clause(i));

      expr* domainExpr = flc->get_expr();

      expr_t unhoistExpr = try_hoisting(rCtx,
                                        domainExpr,
                                        varmap,
                                        freevarMap,
                                        &curr_holder);
      if (unhoistExpr != NULL)
      {
        flc->set_expr(unhoistExpr.getp());
        status = true;

        numForLetClauses = flwor->num_forlet_clauses();
      }
      else
      {
        bool hoisted = hoist_expressions(rCtx,
                                         domainExpr,
                                         varmap,
                                         freevarMap,
                                         &curr_holder);
        if (hoisted)
        {
          status = true;

          numForLetClauses = flwor->num_forlet_clauses();
        }
      }

      i = ++(curr_holder.clause_count);

      assert(numForLetClauses == flwor->num_forlet_clauses());
    }

    expr_t we = flwor->get_where();
    if (we != NULL)
    {
      expr_t unhoistExpr = try_hoisting(rCtx, we, varmap, freevarMap, &curr_holder);
      if (unhoistExpr != NULL)
      {
        flwor->set_where(unhoistExpr.getp());
        status = true;
      }
      else
      {
        status = hoist_expressions(rCtx, we, varmap, freevarMap, &curr_holder) || status;
      }
    }

    expr_t re = flwor->get_return_expr();
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
  else if (e->get_expr_kind() == sequential_expr_kind)
  {
    // Note : local vars must also be indexed if they are allowed to be set
    // inside the for/let clauses of a flwor expr.

    ExprIterator iter(e);

    while(!iter.done())
    {
      // TODO: if no updating child exprs have been encountered so far, subexprs
      // of the current child expr may be hoisted outside the sequential expr as
      // long as they don't reference any local vars.
      expr_t ce = *iter;

      struct flwor_holder root;
      bool nestedModified = hoist_expressions(rCtx, ce, varmap, freevarMap, &root);

      if (nestedModified && root.flwor != NULL)
      {
        root.flwor->set_return_expr(ce);
        (*iter) = root.flwor;
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
        expr_t unhoistExpr = try_hoisting(rCtx, ce, varmap, freevarMap, fholder);
        if (unhoistExpr != NULL)
        {
          *iter = unhoistExpr.getp();
          status = true;
        }
        else
        {
          status = hoist_expressions(rCtx, ce, varmap, freevarMap, fholder) || status;
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
    struct flwor_holder* holder)
{
  if (non_hoistable(e) ||
      e->contains_node_construction() ||
      e->containsRecursiveCall() ||
      is_enclosed_expr(e))
  {
    return NULL;
  }

  TypeManager* tm = e->get_type_manager();

  std::map<const expr*, DynamicBitset>::const_iterator fvme = freevarMap.find(e);
  ZORBA_ASSERT(fvme != freevarMap.end());
  const DynamicBitset& varset = fvme->second;

  struct flwor_holder* h = holder;

  bool inloop = false;
  bool foundReferencedFLWORVar = false;
  int i = 0;

  // h->prev == NULL means that expr e is not inside any flwor expr, and as a
  // result, there is nothing to hoist. 
  while (h->prev != NULL && !foundReferencedFLWORVar)
  {
    group_clause* gc = h->flwor->get_group_clause();

    // If any free variable is a group-by variable, give up.
    if (gc != NULL)
    {
      const flwor_clause::rebind_list_t& gvars = gc->get_grouping_vars();
      ulong numGroupVars = (ulong)gvars.size();

      for (ulong i = 0; i < numGroupVars; ++i)
      {
        if (contains_var(gvars[i].second.getp(), varmap, varset))
          return NULL;
      }

      const flwor_clause::rebind_list_t& ngvars = gc->get_nongrouping_vars();
      ulong numNonGroupVars = (ulong)ngvars.size();

      for (ulong i = 0; i < numNonGroupVars; ++i)
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
    for (i = h->clause_count - 1; i >= 0; --i)
    {
      const forletwin_clause* flc = reinterpret_cast<const forletwin_clause*>
                                    ((*h->flwor)[i]);

      if (contains_var(flc->get_var(), varmap, varset) ||
          contains_var(flc->get_pos_var(), varmap, varset) ||
          contains_var(flc->get_score_var(), varmap, varset))
      {
        foundReferencedFLWORVar = true;
        break;
      }

      inloop = (inloop ||
                (flc->get_kind() == flwor_clause::for_clause &&
                 TypeOps::type_max_cnt(tm, *flc->get_expr()->get_return_type()) >= 2));
    }

    if (!foundReferencedFLWORVar)
      h = h->prev;
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

  let_clause_t flref(new let_clause(e->get_sctx(),
                                    e->get_loc(),
                                    letvar,
                                    hoisted));

  letvar->set_flwor_clause(flref.getp());

  if (h->prev == NULL)
  {
    if (h->flwor == NULL)
    {
      h->flwor = new flwor_expr(e->get_sctx(), e->get_loc(), false);
    }
    h->flwor->add_clause(flref);
  }
  else
  {
    h->flwor->add_clause(i + 1, flref);
    ++h->clause_count;
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
      e->is_nondeterministic() ||
      e->get_scripting_kind() == SEQUENTIAL_EXPR)
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
    return static_cast<const fo_expr *>(e)->get_func()->getKind() ==
           FunctionConsts::OP_UNHOIST_1;
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
/* vim:set ts=2 sw=2: */
