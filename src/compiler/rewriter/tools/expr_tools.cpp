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
bool count_variable_uses_rec(
    const expr* e,
    const var_expr* var,
    RewriterContext* rCtx,
    int limit,
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
    const if_expr* ifExpr = static_cast<const if_expr*>(e);

    int thenCount = 0;
    int elseCount = 0;

    if (!count_variable_uses_rec(ifExpr->get_cond_expr(), var, rCtx, limit, count))
        return false;

    if (!count_variable_uses_rec(ifExpr->get_then_expr(), var, rCtx, limit, thenCount))
    {
      count = thenCount;
      return false;
    }

    if (!count_variable_uses_rec(ifExpr->get_else_expr(), var, rCtx, limit, elseCount))
    {
      count = elseCount;
      return false;
    }

    count += (thenCount > elseCount ? thenCount : elseCount);
  }
  else
  {
    ExprConstIterator iter(e);
    while (!iter.done())
    {
      if (!count_variable_uses_rec(iter.get_expr(), var, rCtx, limit, count))
        return false;
      
      iter.next();
    }
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
int count_variable_uses(
    const expr* root,
    const var_expr* var,
    RewriterContext* rCtx,
    int limit = 0)
{
  int count = 0;

  count_variable_uses_rec(root, var, rCtx, limit, count);

  return count;
}


/*******************************************************************************

********************************************************************************/
const var_ptr_set& get_varset_annotation(const expr* e) 
{
  static var_ptr_set no_free_vars;

  AnnotationValue_t ann = e->get_annotation(Annotations::FREE_VARS);
  return (ann == NULL ?
          no_free_vars :
          dynamic_cast<VarSetAnnVal *>(ann.getp())->theVarset);
}


/*******************************************************************************
  copy annotations when wrapping an expression in a new one
********************************************************************************/
expr_t fix_annotations(expr* new_expr, const expr* old_expr) 
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
  
  for (int k = 0; k < Annotations::MAX_ANNOTATION; ++k) 
  {
    if (k == Annotations::FREE_VARS)
    {
      const var_ptr_set& old_set = get_varset_annotation(old_expr);
      const var_ptr_set& new_set = get_varset_annotation(new_expr);

      var_ptr_set s;
      std::set_union(old_set.begin(),
                     old_set.end(),
                     new_set.begin(),
                     new_set.end(),
                     inserter(s, s.begin()));

      new_expr->put_annotation(static_cast<Annotations::Key>(k),
                               AnnotationValue_t(new VarSetAnnVal(s)));
    }
  }
  
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

    if (wrapper->get_expr() == oldVar)
    {
      wrapper->set_expr(newVar);
      return;
    }
  }

  ExprIterator iter(e);
  while (!iter.done())
  {
    replace_var((*iter), oldVar, newVar);
    iter.next();
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
        unsigned numGroupVars = (unsigned)gvars.size();

        for (unsigned i = 0; i < numGroupVars; ++i)
        {
          add_var(gvars[i].second.getp(), numVars, varidmap, idvarmap);
        }

        const flwor_clause::rebind_list_t& ngvars = gc->get_nongrouping_vars();
        unsigned numNonGroupVars = (unsigned)ngvars.size();

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
      else if (c->get_kind() == flwor_clause::where_clause)
      {
        const where_clause* wc = static_cast<const where_clause *>(c);

        index_flwor_vars(wc->get_expr(), numVars, varidmap, idvarmap);
      }
      else if (c->get_kind() == flwor_clause::order_clause)
      {
        const orderby_clause* obc = static_cast<const orderby_clause *>(c);
        ulong numExprs = obc->num_columns();
        for (ulong i = 0; i < numExprs; ++i)
        {
          index_flwor_vars(obc->get_column_expr(i), numVars, varidmap, idvarmap);
        }
      }
    }

    index_flwor_vars(flwor->get_return_expr(), numVars, varidmap, idvarmap);
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
          
  add_var(inVars.posvar.getp(), numVars, varidmap, idvarmap);
  add_var(inVars.curr.getp(), numVars, varidmap, idvarmap);
  add_var(inVars.prev.getp(), numVars, varidmap, idvarmap);
  add_var(inVars.next.getp(), numVars, varidmap, idvarmap);

  index_flwor_vars(cond->get_cond(), numVars, varidmap, idvarmap);

  add_var(outVars.posvar.getp(), numVars, varidmap, idvarmap);
  add_var(outVars.curr.getp(), numVars, varidmap, idvarmap);
  add_var(outVars.prev.getp(), numVars, varidmap, idvarmap);
  add_var(outVars.next.getp(), numVars, varidmap, idvarmap);
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

  ulong numVars = freeset.size();

  DynamicBitset eFreeset(numVars);
  ExprIterator iter(e);
  while(!iter.done()) 
  {
    expr* ce = &*(*iter);
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
        unsigned numGroupVars = (unsigned)gvars.size();

        for (unsigned i = 0; i < numGroupVars; ++i)
        {
          set_bit(gvars[i].second.getp(), varmap, freeset, false);
        }

        const flwor_clause::rebind_list_t& ngvars = gc->get_nongrouping_vars();
        unsigned numNonGroupVars = (unsigned)ngvars.size();
        
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

  VarIdMap::const_iterator i = varmap.find(v);
  if (i != varmap.end())
    freeset.set(i->second, value);
}


/*******************************************************************************
  If the no-node-copy annotation of the target expr is not set to false
  already, set it to the value of the no-node-copy annotations of the
  source expr.
********************************************************************************/
static void pushdown_no_node_copy(expr* src, expr* target) 
{
  if (target->getNoNodeCopy1() != ANNOTATION_FALSE)
    target->setNoNodeCopy1(src->getNoNodeCopy1());

  if (target->getNoNodeCopy2() != ANNOTATION_FALSE)
    target->setNoNodeCopy2(src->getNoNodeCopy2());
}


/*******************************************************************************
  If the no-node-copy annotation of the target expr is not set to false
  already, set it to the given value.
********************************************************************************/
static void set_no_node_copy(expr* target, BoolAnnotationValue v) 
{
  if (target->getNoNodeCopy1() != ANNOTATION_FALSE)
    target->setNoNodeCopy1(v);

  if (target->getNoNodeCopy2() != ANNOTATION_FALSE)
    target->setNoNodeCopy2(v);
}


/*******************************************************************************
  If the no-node-copy annotation of the target expr is not set to false
  already, set it to the value of the no-node-copy annotations of the
  source expr.
********************************************************************************/
static void pushdown_window_vars(const flwor_wincond* cond, expr* target) 
{
  const flwor_wincond::vars& inVars = cond->get_in_vars();

  if (inVars.curr)
    pushdown_no_node_copy(inVars.curr.getp(), target);

  if (inVars.prev)
    pushdown_no_node_copy(inVars.prev.getp(), target);

  if (inVars.next)
    pushdown_no_node_copy(inVars.next.getp(), target);

  const flwor_wincond::vars& outVars = cond->get_out_vars();

  if (outVars.curr)
    pushdown_no_node_copy(outVars.curr.getp(), target);

  if (outVars.prev)
    pushdown_no_node_copy(outVars.prev.getp(), target);
  
  if (outVars.next)
    pushdown_no_node_copy(outVars.next.getp(), target);
}


/*******************************************************************************

********************************************************************************/
void computeNoNodeCopyProperty(expr* inExpr)
{
  switch(inExpr->get_expr_kind()) 
  {
  case const_expr_kind:
  {
    return;
  }

  case var_expr_kind:
  {
    var_expr* e = static_cast<var_expr*>(inExpr);

    switch (e->get_kind())
    {
    case var_expr::for_var:
    case var_expr::let_var:
    case var_expr::pos_var:
    case var_expr::win_var:
    case var_expr::score_var:
    case var_expr::wincond_out_var:
    case var_expr::wincond_out_pos_var:
    case var_expr::wincond_in_var:
    case var_expr::wincond_in_pos_var:
    case var_expr::count_var:
    case var_expr::groupby_var:
    case var_expr::non_groupby_var:
    case var_expr::copy_var:
    {
      return;
    }

    case var_expr::arg_var:
    {
      return;
      //expr* argExpr = argExprs[e->get_param_pos()];
      //pushdown_no_node_copy(inExpr, argExpr);
    }

    case var_expr::prolog_var: 
    case var_expr::local_var:
    {
      // TODO: pass into this function a map with one entry per in-scope var.
      // The entry maps the var to the most recently encountered assignment 
      // expr for this var. 
      return;
    }

    case var_expr::catch_var:
    {
      // TODO: associate the catch var with the try clause and keep track inside the
      // try_catch expr of all the fn:error() calls that return an item()* seq.
      return;
    }

    case var_expr::eval_var: // TODO
    default:
    {
      ZORBA_ASSERT(false);
    }
    }

    break;
  }

  case doc_expr_kind:
  {
    doc_expr* e = static_cast<doc_expr*>(inExpr);
    pushdown_no_node_copy(inExpr, e->getContent());
    break;
  }

  case elem_expr_kind:
  {
    elem_expr* e = static_cast<elem_expr*>(inExpr);
    pushdown_no_node_copy(inExpr, e->getContent());
    pushdown_no_node_copy(inExpr, e->getAttrs());
    set_no_node_copy(e->getQNameExpr(), ANNOTATION_TRUE);
    break;
  }

  case attr_expr_kind:
  {
    attr_expr* e = static_cast<attr_expr*>(inExpr);
    pushdown_no_node_copy(inExpr, e->getValueExpr());
    break;
  }

  case text_expr_kind:
  {
    text_expr* e = static_cast<text_expr*>(inExpr);
    set_no_node_copy(e->get_text(), ANNOTATION_TRUE);
    break;
  }

  case pi_expr_kind:
  {
    pi_expr* e = static_cast<pi_expr*>(inExpr);
    set_no_node_copy(e->get_target_expr(), ANNOTATION_TRUE);
    set_no_node_copy(e->get_content_expr(), ANNOTATION_TRUE);
    break;
  }

  case relpath_expr_kind:
  {
    const relpath_expr* e = static_cast<const relpath_expr*>(inExpr);

    std::vector<expr_t>::const_iterator ite = e->begin();
    std::vector<expr_t>::const_iterator end = e->end();

    for (++ite; ite != end; ++ite)
    {
      axis_step_expr* axisExpr = static_cast<axis_step_expr*>((*ite).getp());
      axis_kind_t axisKind = axisExpr->getAxis();

      if (axisKind != axis_kind_child &&
          axisKind != axis_kind_descendant &&
          axisKind != axis_kind_self &&
          axisKind != axis_kind_attribute)
      {
        set_no_node_copy((*e)[0].getp(), ANNOTATION_FALSE);
        break;
      }
    }

    break;
  }

  case flwor_expr_kind:
  case gflwor_expr_kind:
  {
    flwor_expr* e = static_cast<flwor_expr*>(inExpr);

    pushdown_no_node_copy(inExpr, e->get_return_expr());

    csize i = e->num_clauses();
    for (; i > 0; --i)
    {
      flwor_clause* clause = e->get_clause(i-1);

      switch(clause->get_kind())
      {
      case flwor_clause::for_clause:
      {
        for_clause* fc = static_cast<for_clause*>(clause);
        pushdown_no_node_copy(fc->get_var(), fc->get_expr());
        computeNoNodeCopyProperty(fc->get_expr());
        break;
      }
      case flwor_clause::let_clause:
      {
        let_clause* lc = static_cast<let_clause*>(clause);
        pushdown_no_node_copy(lc->get_var(), lc->get_expr());
        computeNoNodeCopyProperty(lc->get_expr());
        break;
      }
      case flwor_clause::window_clause:
      {
        window_clause* wc = static_cast<window_clause*>(clause);

        pushdown_no_node_copy(wc->get_var(), wc->get_expr());

        const flwor_wincond* startCond = wc->get_win_start();
        const flwor_wincond* endCond = wc->get_win_start();

        if (startCond)
        {
          set_no_node_copy(startCond->get_cond(), ANNOTATION_TRUE);

          computeNoNodeCopyProperty(startCond->get_cond());

          pushdown_window_vars(startCond, wc->get_expr());
        }

        if (endCond)
        {
          set_no_node_copy(endCond->get_cond(), ANNOTATION_TRUE);

          computeNoNodeCopyProperty(endCond->get_cond());

          pushdown_window_vars(endCond, wc->get_expr());
        }

        computeNoNodeCopyProperty(wc->get_expr());
        break;
      }
      case flwor_clause::where_clause:
      {
        where_clause* cc = static_cast<where_clause*>(clause);
        set_no_node_copy(cc->get_expr(), ANNOTATION_TRUE);
        computeNoNodeCopyProperty(cc->get_expr());
        break;
      }
      case flwor_clause::group_clause:
      {
        group_clause* gc = static_cast<group_clause*>(clause);

        flwor_clause::rebind_list_t::iterator ite = gc->beginGroupVars();
        flwor_clause::rebind_list_t::iterator end = gc->endGroupVars();

        for (; ite != end; ++ite)
        {
          pushdown_no_node_copy((*ite).second.getp(), (*ite).first.getp());
        }

        ite = gc->beginNonGroupVars();
        end = gc->endNonGroupVars();

        for (; ite != end; ++ite)
        {
          pushdown_no_node_copy((*ite).second.getp(), (*ite).first.getp());
        }

        break;
      }
      case flwor_clause::order_clause:
      {
        orderby_clause* ob = static_cast<orderby_clause*>(clause);

        std::vector<expr_t>::iterator ite = ob->begin();
        std::vector<expr_t>::iterator end = ob->end();

        for (; ite != end; ++ite)
        {
          set_no_node_copy((*ite), ANNOTATION_TRUE);
          computeNoNodeCopyProperty(*ite);
        }
        break;
      }
      case flwor_clause::count_clause:
      {
        break;
      }
      default:
        ZORBA_ASSERT(false);
      }
    }

    return;
  }

  case if_expr_kind:
  {
    if_expr* e = static_cast<if_expr*>(inExpr);
    pushdown_no_node_copy(inExpr, e->get_cond_expr());
    pushdown_no_node_copy(inExpr, e->get_then_expr());
    pushdown_no_node_copy(inExpr, e->get_else_expr());
    break;
  }

  case trycatch_expr_kind:
  {
    trycatch_expr* e = static_cast<trycatch_expr*>(inExpr);
    pushdown_no_node_copy(inExpr, e->get_try_expr());
    pushdown_no_node_copy(inExpr, e->get_catch_expr());
    break;
  }

  case fo_expr_kind:
  {
    fo_expr* e = static_cast<fo_expr*>(inExpr);
    function* func = e->get_func();

    csize numArgs = e->num_args();

    for (csize i = 0; i < numArgs; ++i)
    {
      set_no_node_copy(e->get_arg(i), func->requiresNodeCopy(e, i));
    }

    break;
  }

#if 0
  case dynamic_function_invocation_expr_kind:
  case function_item_expr_kind:

  case castable_expr_kind:
  case instanceof_expr_kind:
  case cast_expr_kind:
  case treat_expr_kind:
  case promote_expr_kind:
  case name_cast_expr_kind:

  case validate_expr_kind:

  case extension_expr_kind:

  case order_expr_kind:

  case delete_expr_kind:
  case insert_expr_kind:
  case rename_expr_kind:
  case replace_expr_kind:
  case transform_expr_kind:

  case block_expr_kind:
  case var_decl_expr_kind:
  case apply_expr_kind:
  case exit_expr_kind:
  case exit_catcher_expr_kind:
  case flowctl_expr_kind:
  case while_expr_kind:

  case eval_expr_kind:
  case debugger_expr_kind:
  case wrapper_expr_kind:
  case function_trace_expr_kind:

#ifndef ZORBA_NO_FULL_TEXT
	case ft_expr_kind:
#endif /* ZORBA_NO_FULL_TEXT */

#endif

  case axis_step_expr_kind:
  case match_expr_kind:
  default:
    ZORBA_ASSERT(false);
  }

  ExprIterator iter(inExpr);
  while (!iter.done())
  {
    computeNoNodeCopyProperty(*iter);
    iter.next();
  }
}


}
}

/* vim:set et sw=2 ts=2: */
