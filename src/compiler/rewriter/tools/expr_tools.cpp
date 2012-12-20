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
#include "compiler/expression/script_exprs.h"
#include "compiler/expression/ft_expr.h"
#include "compiler/expression/ftnode.h"
#include "compiler/expression/expr_iter.h"
#include "compiler/api/compilercb.h"

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
static void normalize_comp(
    CompareConsts::CompareType& comp,
    expr*& arg0,
    expr*& arg1)
{
  switch (comp)
  {
  case CompareConsts::VALUE_GREATER:
  case CompareConsts::GENERAL_GREATER:
  case CompareConsts::VALUE_GREATER_EQUAL:
  case CompareConsts::GENERAL_GREATER_EQUAL:
  {
    comp = static_cast<CompareConsts::CompareType>(static_cast<int>(comp) - 4);
     
    expr* tmp = arg0;
    arg0 = arg1;
    arg1 = tmp;
     
    break;
  }
  default:
    break;
  }
}


/*******************************************************************************

********************************************************************************/
bool match_exact(expr* query, expr* view, expr::substitution_t& subst)
{
  if (query == view)
    return true;

  if (query->get_expr_kind() != view->get_expr_kind())
  {
    if (query->get_expr_kind() == var_expr_kind)
    {
      var_expr* qe = static_cast<var_expr*>(query);

      if (qe->get_kind() != var_expr::let_var)
        return false;

      return match_exact(qe->get_domain_expr(), view, subst);
    }
    else if (view->get_expr_kind() == var_expr_kind)
    {
      var_expr* ve = static_cast<var_expr*>(view);

      switch (ve->get_kind())
      {
      case var_expr::for_var:
      {
        expr::substitution_t::iterator ite = subst.find(view);

        if (ite != subst.end())
        {
          return match_exact(query, ite->second, subst);
        }
        else
        {
          assert(false);
          subst[view] = query;
          return true;
        }
      }
      case var_expr::let_var:
      {
        return match_exact(query, ve->get_domain_expr(), subst);
      }
      case var_expr::pos_var:
      {
        return false;
      }
      case var_expr::win_var:
      case var_expr::wincond_out_var:
      case var_expr::wincond_out_pos_var:
      case var_expr::wincond_in_var:
      case var_expr::wincond_in_pos_var:
      case var_expr::groupby_var:
      case var_expr::non_groupby_var:
      case var_expr::count_var:
      {
        ZORBA_ASSERT(false); // TODO
      }
      case var_expr::score_var:
      case var_expr::prolog_var:
      case var_expr::local_var:
      case var_expr::copy_var:
      case var_expr::catch_var:
      case var_expr::arg_var:
      case var_expr::eval_var:
      {
        ZORBA_ASSERT(false);
      }
      default:
      {
        ZORBA_ASSERT(false);
      }
      }
    }
    else if (view->get_function_kind() == FunctionConsts::OP_UNHOIST_1)
    {
      fo_expr* vfo = static_cast<fo_expr*>(view);
      return match_exact(query, vfo->get_arg(0), subst);
    }
    else if (query->get_function_kind() == FunctionConsts::OP_UNHOIST_1)
    {
      fo_expr* qfo = static_cast<fo_expr*>(query);
      return match_exact(qfo->get_arg(0), view, subst);
    }
    else if (view->get_function_kind() == FunctionConsts::OP_HOIST_1)
    {
      fo_expr* vfo = static_cast<fo_expr*>(view);
      return match_exact(query, vfo->get_arg(0), subst);
    }
    else if (query->get_function_kind() == FunctionConsts::OP_HOIST_1)
    {
      fo_expr* qfo = static_cast<fo_expr*>(query);
      return match_exact(qfo->get_arg(0), view, subst);
    }
    else if (view->get_expr_kind() == wrapper_expr_kind)
    {
      wrapper_expr* vwe = static_cast<wrapper_expr*>(view);
      return match_exact(query, vwe->get_input(), subst);
    }
    else if (query->get_expr_kind() == wrapper_expr_kind)
    {
      wrapper_expr* qwe = static_cast<wrapper_expr*>(query);
      return match_exact(qwe->get_input(), view, subst);
    }
    else
    {
      return false;
    }
  }

  switch (query->get_expr_kind())
  {
  case var_expr_kind:
  {
    var_expr* qe = static_cast<var_expr*>(query);
    var_expr* ve = static_cast<var_expr*>(view);

    var_expr::var_kind qkind = qe->get_kind();
    var_expr::var_kind vkind = ve->get_kind();

    if (qkind != vkind)
    {
      if (qkind == var_expr::let_var)
      {
        return match_exact(qe->get_domain_expr(), view, subst);
      }

      return false;
    }

    switch (qkind)
    {
    case var_expr::for_var:
    case var_expr::pos_var:
    {
      expr::substitution_t::iterator ite = subst.find(view);

      if (ite != subst.end())
      {
        return (qe == ite->second);
      }
      else
      {
        assert(false);
        subst[view] = query;
        return true;
      }
    }
    case var_expr::let_var:
    {
      return match_exact(qe->get_domain_expr(), ve->get_domain_expr(), subst);
    }
    case var_expr::win_var:
    case var_expr::wincond_out_var:
    case var_expr::wincond_out_pos_var:
    case var_expr::wincond_in_var:
    case var_expr::wincond_in_pos_var:
    case var_expr::groupby_var:
    case var_expr::non_groupby_var:
    case var_expr::count_var:
    {
      ZORBA_ASSERT(false); // TODO
    }
    case var_expr::score_var:
    case var_expr::prolog_var:
    case var_expr::local_var:
    case var_expr::copy_var:
    case var_expr::catch_var:
    case var_expr::arg_var:
    case var_expr::eval_var:
    {
      ZORBA_ASSERT(false);
    }
    default:
    {
      ZORBA_ASSERT(false);
    }
    }

    break;
  }

  case fo_expr_kind:
  {
    fo_expr* qe = static_cast<fo_expr*>(query);
    fo_expr* ve = static_cast<fo_expr*>(view);

    if (qe->get_func() != ve->get_func())
    {
      function* vfunc = ve->get_func();
      function* qfunc = qe->get_func();

      if (qfunc->isComparisonFunction() && vfunc->isComparisonFunction())
      {
        CompareConsts::CompareType qcomp = qe->get_func()->comparisonKind();
        CompareConsts::CompareType vcomp = ve->get_func()->comparisonKind();

        expr* qarg0 = qe->get_arg(0);
        expr* qarg1 = qe->get_arg(1);
        expr* varg0 = ve->get_arg(0);
        expr* varg1 = ve->get_arg(1);

        normalize_comp(qcomp, qarg0, qarg1);
        normalize_comp(vcomp, varg0, varg1);

        if (qcomp == vcomp &&
            match_exact(qarg0, varg0, subst) &&
            match_exact(qarg1, varg1, subst))
          return true;
      }
      else if (vfunc->getKind() == FunctionConsts::OP_UNHOIST_1)
      {
        return match_exact(query, ve->get_arg(0), subst);
      }
      else if (qfunc->getKind() == FunctionConsts::OP_UNHOIST_1)
      {
        return match_exact(qe->get_arg(0), view, subst);
      }
      else if (vfunc->getKind() == FunctionConsts::OP_HOIST_1)
      {
        return match_exact(query, ve->get_arg(0), subst);
      }
      else if (qfunc->getKind() == FunctionConsts::OP_HOIST_1)
      {
        return match_exact(qe->get_arg(0), view, subst);
      }

      return false;
    }

    function* func = qe->get_func();

    csize numArgs = qe->num_args();

    if (numArgs != ve->num_args())
      return false;

    csize i = 0;
    for (; i < numArgs; i++)
    {
      if (!match_exact(qe->get_arg(i), ve->get_arg(i), subst))
        break;
    }

    if (i < numArgs)
    {
      if (func->getKind() == FunctionConsts::STATIC_COLLECTIONS_DML_COLLECTION_1)
      {
        const store::Item* collName1 = ve->get_arg(0)->getQName();
        const store::Item* collName2 = qe->get_arg(0)->getQName();

        if (collName1 != NULL && collName2 != NULL && collName1->equals(collName2))
          return true;
#if 0
        if (collName != NULL && qe->get_arg(0)->get_var() != NULL)
        {
          const var_expr* var = qe->get_arg(0)->get_var();

          if (var->get_kind() == var_expr::prolog_var &&
              var->num_set_exprs() == 1 &&
              var->get_set_expr(0)->get_expr_kind() == var_decl_expr_kind)
          {
            const var_decl_expr* decl = 
            static_cast<const var_decl_expr*>(var->get_set_expr(0));

            const store::Item* collName2 = decl->get_init_expr()->getQName();

            if (collName2 != NULL && collName->equals(collName2))
              return true;
          }
        }
#endif
      }
      else if (func->isComparisonFunction())
      {
        CompareConsts::CompareType compKind = func->comparisonKind();

        if (CompareConsts::VALUE_EQUAL <= compKind && 
            compKind <= CompareConsts::NODE_NOT_EQUAL)
        {
          if (match_exact(qe->get_arg(0), ve->get_arg(1), subst) &&
              match_exact(qe->get_arg(1), ve->get_arg(0), subst))
            return true;
        }
      }

      return false;
    }

    return true;
  }

  case relpath_expr_kind:
  {
    relpath_expr* qe = static_cast<relpath_expr*>(query);
    relpath_expr* ve = static_cast<relpath_expr*>(view);

    csize vnumSteps = ve->size();
    csize qnumSteps = qe->size();
    csize numSteps = (vnumSteps < qnumSteps ? vnumSteps : qnumSteps);

    for (csize i = numSteps-1; i > 0; --i)
    {
      axis_step_expr* qstep = static_cast<axis_step_expr*>((*qe)[i]);
      axis_step_expr* vstep = static_cast<axis_step_expr*>((*ve)[i]);

      if (qstep->getAxis() != vstep->getAxis())
        return false;

      match_expr* qtest = qstep->getTest();
      match_expr* vtest = vstep->getTest();

      if (!qtest->matches(vtest))
        return false;
    }

    // <vsource>/b/c  vs  <qsource>/a/b/c
    if (vnumSteps < qnumSteps)
    {
      expr* vsource = (*ve)[0];

      if (vsource->get_expr_kind() != var_expr_kind)
        return false;

      relpath_expr* qpath = query->get_ccb()->getExprManager()->
      create_relpath_expr(qe->get_sctx(), qe->get_udf(), qe->get_loc());

      for (csize i = 0; i < qnumSteps - vnumSteps; ++i)
        qpath->add_back((*qe)[i]);

      return match_exact(qpath, vsource, subst);
    }
    // <vsource>/a/b/c  vs  <qsource>/b/c
    else if (qnumSteps < vnumSteps)
    {
      expr* qsource = (*qe)[0];

      if (qsource->get_expr_kind() != var_expr_kind)
        return false;

      relpath_expr* vpath = query->get_ccb()->getExprManager()->
      create_relpath_expr(ve->get_sctx(), ve->get_udf(), ve->get_loc());

      for (csize i = 0; i < vnumSteps - qnumSteps; ++i)
        vpath->add_back((*ve)[i]);

      return match_exact(qsource, vpath, subst);
    }
    else
    {
      return match_exact((*qe)[0], (*ve)[0], subst);
    }
  }

  case cast_expr_kind:
  case castable_expr_kind:
  case instanceof_expr_kind:
  {
    cast_or_castable_base_expr* qe = static_cast<cast_or_castable_base_expr*>(query);
    cast_or_castable_base_expr* ve = static_cast<cast_or_castable_base_expr*>(view);

    TypeManager* tm = qe->get_type_manager();

    if (!TypeOps::is_equal(tm, *qe->get_target_type(), *ve->get_target_type()))
      return false;

    return match_exact(qe->get_input(), ve->get_input(), subst);
  }

  case promote_expr_kind:
  {
    promote_expr* qe = static_cast<promote_expr*>(query);
    promote_expr* ve = static_cast<promote_expr*>(view);

    TypeManager* tm = qe->get_type_manager();

    if (!TypeOps::is_subtype(tm, *qe->get_return_type(), *ve->get_target_type()))
      return false;

    return match_exact(qe->get_input(), ve->get_input(), subst);
  }

  case treat_expr_kind:
  {
    treat_expr* qe = static_cast<treat_expr*>(query);
    treat_expr* ve = static_cast<treat_expr*>(view);

    TypeManager* tm = qe->get_type_manager();

    if (qe->get_check_prime() != ve->get_check_prime())
      return false;

    if (!qe->get_check_prime())
    {
      if (qe->get_target_type()->get_quantifier() !=
          ve->get_target_type()->get_quantifier())
        return false;
    }
    else if (!TypeOps::is_equal(tm, *qe->get_target_type(), *ve->get_target_type()))
    {
      return false;
    }

    return match_exact(qe->get_input(), ve->get_input(), subst);
  }

  case wrapper_expr_kind:
  {
    wrapper_expr* qe = static_cast<wrapper_expr*>(query);
    wrapper_expr* ve = static_cast<wrapper_expr*>(view);

    return match_exact(qe->get_input(), ve->get_input(), subst);
  }

  case const_expr_kind:
  {
    const_expr* qe = static_cast<const_expr*>(query);
    const_expr* ve = static_cast<const_expr*>(view);

    try
    {
      // TODO: collation, timezone ???? Implement the full eq spec ????
      return qe->get_val()->equals(ve->get_val());
    }
    catch (ZorbaException&)
    {
      return false;
    }
    break;
  }

  case delete_expr_kind:
  case insert_expr_kind:
  case rename_expr_kind:
  case replace_expr_kind:
  case transform_expr_kind:
  default:
  {
    ZORBA_ASSERT(false);
  }
  }

  return false;
}


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
  Let FV(e) be the set of variables defined in any of the flwor exprs in 
  FLWOR(e). This method assigns a prefix id to each variable in FV(e) and
  stores the mapping between var_expr and prefix id in "varidmap" and the
  reverse mapping in "idvapmap". It also returns the number of vars in FV(e).

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
      else if (c->get_kind() == flwor_clause::groupby_clause)
      {
        const groupby_clause* gc = static_cast<const groupby_clause *>(c);

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
      else if (c->get_kind() == flwor_clause::groupby_clause)
      {
        const groupby_clause* gc = static_cast<const groupby_clause *>(c);

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


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//                                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


#if 0
/*******************************************************************************

********************************************************************************/
static void set_must_copy(expr* target, BoolAnnotationValue v)
{
  assert(v != ANNOTATION_UNKNOWN);

  if (target == NULL)
    return;

  switch (target->getMustCopyNodes())
  {
  case ANNOTATION_UNKNOWN:
  {
    target->setMustCopyNodes(v);
    return;
  }
  case ANNOTATION_TRUE_FIXED:
  {
    return;
  }
  case ANNOTATION_TRUE:
  {
    if (v == ANNOTATION_TRUE_FIXED)
      target->setMustCopyNodes(v);

    return;
  }
  case ANNOTATION_FALSE:
  {
    target->setMustCopyNodes(v);
    return;
  }
  }
}


/*******************************************************************************
  If the no-node-copy annotation of the target expr is not set to false
  already, set it to the value of the no-node-copy annotations of the
  source expr.
********************************************************************************/
static void pushdown_must_copy(expr* src, expr* target)
{
  set_must_copy(target, src->getMustCopyNodes());
}


/*******************************************************************************

********************************************************************************/
static void pushdown_window_vars(const flwor_wincond* cond, expr* target)
{
  const flwor_wincond::vars& inVars = cond->get_in_vars();

  if (inVars.curr)
    pushdown_must_copy(inVars.curr, target);

  if (inVars.prev)
    pushdown_must_copy(inVars.prev, target);

  if (inVars.next)
    pushdown_must_copy(inVars.next, target);

  const flwor_wincond::vars& outVars = cond->get_out_vars();

  if (outVars.curr)
    pushdown_must_copy(outVars.curr, target);

  if (outVars.prev)
    pushdown_must_copy(outVars.prev, target);

  if (outVars.next)
    pushdown_must_copy(outVars.next, target);
}


/*******************************************************************************

********************************************************************************/
void computeMustCopyProperty(expr* inExpr)
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
    pushdown_must_copy(inExpr, e->getContent());
    break;
  }

  case elem_expr_kind:
  {
    elem_expr* e = static_cast<elem_expr*>(inExpr);
    pushdown_must_copy(inExpr, e->getContent());
    pushdown_must_copy(inExpr, e->getAttrs());
    set_must_copy(e->getQNameExpr(), ANNOTATION_FALSE);
    break;
  }

  case attr_expr_kind:
  {
    attr_expr* e = static_cast<attr_expr*>(inExpr);
    pushdown_must_copy(inExpr, e->getValueExpr());
    set_must_copy(e->getQNameExpr(), ANNOTATION_FALSE);
    break;
  }

  case text_expr_kind:
  {
    text_expr* e = static_cast<text_expr*>(inExpr);
    set_must_copy(e->get_text(), ANNOTATION_FALSE);
    break;
  }

  case pi_expr_kind:
  {
    pi_expr* e = static_cast<pi_expr*>(inExpr);
    set_must_copy(e->get_target_expr(), ANNOTATION_FALSE);
    set_must_copy(e->get_content_expr(), ANNOTATION_FALSE);
    break;
  }

  case relpath_expr_kind:
  {
    const relpath_expr* e = static_cast<const relpath_expr*>(inExpr);

    std::vector<expr*>::const_iterator ite = e->begin();
    std::vector<expr*>::const_iterator end = e->end();

    for (++ite; ite != end; ++ite)
    {
      axis_step_expr* axisExpr = static_cast<axis_step_expr*>((*ite));
      axis_kind_t axisKind = axisExpr->getAxis();

      if (axisKind != axis_kind_child &&
          axisKind != axis_kind_descendant &&
          axisKind != axis_kind_self &&
          axisKind != axis_kind_attribute)
      {
        set_must_copy((*e)[0], ANNOTATION_TRUE_FIXED);
        break;
      }
    }

    break;
  }

  case flwor_expr_kind:
  case gflwor_expr_kind:
  {
    flwor_expr* e = static_cast<flwor_expr*>(inExpr);

    pushdown_must_copy(inExpr, e->get_return_expr());

    csize i = e->num_clauses();
    for (; i > 0; --i)
    {
      flwor_clause* clause = e->get_clause(i-1);

      switch(clause->get_kind())
      {
      case flwor_clause::for_clause:
      {
        for_clause* fc = static_cast<for_clause*>(clause);
        pushdown_must_copy(fc->get_var(), fc->get_expr());
        computeMustCopyProperty(fc->get_expr());
        break;
      }
      case flwor_clause::let_clause:
      {
        let_clause* lc = static_cast<let_clause*>(clause);
        pushdown_must_copy(lc->get_var(), lc->get_expr());
        computeMustCopyProperty(lc->get_expr());
        break;
      }
      case flwor_clause::window_clause:
      {
        window_clause* wc = static_cast<window_clause*>(clause);

        pushdown_must_copy(wc->get_var(), wc->get_expr());

        const flwor_wincond* startCond = wc->get_win_start();
        const flwor_wincond* endCond = wc->get_win_start();

        if (startCond)
        {
          set_must_copy(startCond->get_cond(), ANNOTATION_FALSE);

          computeMustCopyProperty(startCond->get_cond());

          pushdown_window_vars(startCond, wc->get_expr());
        }

        if (endCond)
        {
          set_must_copy(endCond->get_cond(), ANNOTATION_FALSE);

          computeMustCopyProperty(endCond->get_cond());

          pushdown_window_vars(endCond, wc->get_expr());
        }

        computeMustCopyProperty(wc->get_expr());
        break;
      }
      case flwor_clause::where_clause:
      {
        where_clause* cc = static_cast<where_clause*>(clause);
        set_must_copy(cc->get_expr(), ANNOTATION_FALSE);
        computeMustCopyProperty(cc->get_expr());
        break;
      }
      case flwor_clause::groupby_clause:
      {
        groupby_clause* gc = static_cast<groupby_clause*>(clause);

        flwor_clause::rebind_list_t::iterator ite = gc->beginGroupVars();
        flwor_clause::rebind_list_t::iterator end = gc->endGroupVars();

        for (; ite != end; ++ite)
        {
          pushdown_must_copy((*ite).second, (*ite).first);
        }

        ite = gc->beginNonGroupVars();
        end = gc->endNonGroupVars();

        for (; ite != end; ++ite)
        {
          pushdown_must_copy((*ite).second, (*ite).first);
        }

        break;
      }
      case flwor_clause::order_clause:
      {
        orderby_clause* ob = static_cast<orderby_clause*>(clause);

        std::vector<expr*>::iterator ite = ob->begin();
        std::vector<expr*>::iterator end = ob->end();

        for (; ite != end; ++ite)
        {
          set_must_copy((*ite), ANNOTATION_FALSE);
          computeMustCopyProperty(*ite);
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
    pushdown_must_copy(inExpr, e->get_cond_expr());
    pushdown_must_copy(inExpr, e->get_then_expr());
    pushdown_must_copy(inExpr, e->get_else_expr());
    break;
  }

  case trycatch_expr_kind:
  {
    trycatch_expr* e = static_cast<trycatch_expr*>(inExpr);
    pushdown_must_copy(inExpr, e->get_try_expr());

    csize numCatches = e->clause_count();
    for (csize i = 0; i < numCatches; ++i)
    {
      pushdown_must_copy(inExpr, e->get_catch_expr(i));
    }
    break;
  }

  case fo_expr_kind:
  {
    fo_expr* e = static_cast<fo_expr*>(inExpr);
    function* func = e->get_func();

    csize numArgs = e->num_args();

    for (csize i = 0; i < numArgs; ++i)
    {
      set_must_copy(e->get_arg(i), func->mustCopyInputNodes(e, i));
    }

    break;
  }

  case dynamic_function_invocation_expr_kind:
  case function_item_expr_kind:
  {
    ZORBA_ASSERT(false); // TODO
  }

  case castable_expr_kind:
  case instanceof_expr_kind:
  case cast_expr_kind:
  {
    cast_or_castable_base_expr* e = static_cast<cast_or_castable_base_expr*>(inExpr);
    set_must_copy(e, ANNOTATION_FALSE);
    pushdown_must_copy(inExpr, e->get_input());
    break;
  }

  case treat_expr_kind:
  case promote_expr_kind:
  {
    cast_base_expr* e = static_cast<cast_base_expr*>(inExpr);

    if (TypeOps::is_subtype(e->get_type_manager(),
                            *e->get_target_type(),
                            *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_STAR))
    {
      set_must_copy(e, ANNOTATION_FALSE);
    }

    pushdown_must_copy(inExpr, e->get_input());
    break;
  }

  case name_cast_expr_kind:
  {
    name_cast_expr* e = static_cast<name_cast_expr*>(inExpr);
    set_must_copy(e, ANNOTATION_FALSE);
    pushdown_must_copy(inExpr, e->get_input());
    break;
  }

  case validate_expr_kind:
  {
    validate_expr* e = static_cast<validate_expr*>(inExpr);
    set_must_copy(e, ANNOTATION_TRUE_FIXED);
    pushdown_must_copy(inExpr, e->get_expr());
    break;
  }

  case extension_expr_kind:
  {
    extension_expr* e = static_cast<extension_expr*>(inExpr);
    pushdown_must_copy(inExpr, e->get_expr());
    break;
  }

  case order_expr_kind:
  {
    order_expr* e = static_cast<order_expr*>(inExpr);
    pushdown_must_copy(inExpr, e->get_expr());
    break;
  }

  case delete_expr_kind:
  case insert_expr_kind:
  case rename_expr_kind:
  case replace_expr_kind:
  {
    update_expr_base* e = static_cast<update_expr_base*>(inExpr);

    set_must_copy(e->getTargetExpr(), ANNOTATION_TRUE_FIXED);

    if (e->get_expr_kind() == rename_expr_kind)
    {
      set_must_copy(e->getSourceExpr(), ANNOTATION_FALSE);
    }
    else if (e->get_expr_kind() == replace_expr_kind)
    {
      replace_expr* re = static_cast<replace_expr*>(inExpr);

      if (re->getType() == store::UpdateConsts::VALUE_OF_NODE)
      {
        set_must_copy(e->getSourceExpr(), ANNOTATION_FALSE);
      }
      else
      {
        set_must_copy(e->getSourceExpr(), ANNOTATION_TRUE_FIXED);
      }
    }
    else
    {
      set_must_copy(e->getSourceExpr(), ANNOTATION_TRUE_FIXED);
    }

    break;
  }

#if 0
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

#endif

  case wrapper_expr_kind:
  {
    wrapper_expr* e = static_cast<wrapper_expr*>(inExpr);
    pushdown_must_copy(inExpr, e->get_expr());
    break;
  }

  case function_trace_expr_kind:
  {
    function_trace_expr* e = static_cast<function_trace_expr*>(inExpr);
    pushdown_must_copy(inExpr, e->get_expr());
    break;
  }

#ifndef ZORBA_NO_FULL_TEXT
	case ft_expr_kind:
  {
    ft_expr* e = static_cast<ft_expr*>(inExpr);
    set_must_copy(e, ANNOTATION_FALSE);
    set_must_copy(e->get_range(), ANNOTATION_TRUE_FIXED);
    set_must_copy(e->get_ignore(), ANNOTATION_TRUE_FIXED);
    break;
  }
#endif /* ZORBA_NO_FULL_TEXT */

  case axis_step_expr_kind:
  case match_expr_kind:
  default:
    ZORBA_ASSERT(false);
  }

  ExprIterator iter(inExpr);
  while (!iter.done())
  {
    computeMustCopyProperty(*iter);
    iter.next();
  }
}
#endif


}
}

/* vim:set et sw=2 ts=2: */
