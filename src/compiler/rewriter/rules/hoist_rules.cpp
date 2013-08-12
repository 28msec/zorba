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

#include "compiler/rewriter/rules/hoist_rules.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/expr_iter.h"

#include "types/typeimpl.h"

#include "util/dynamic_bitset.h"

#include "diagnostics/assert.h"


namespace zorba
{


static bool non_hoistable(const expr*);

static bool is_already_hoisted(const expr*);

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
  expr               * theExpr;
  long                 clauseCount;

  PathHolder() : prev(NULL), theExpr(NULL), clauseCount(0)
  {
  }
};


/*******************************************************************************

********************************************************************************/
expr* skip_children(expr* e)
{
  FunctionConsts::FunctionKind fkind = e->get_function_kind();

  if (fkind == FunctionConsts::OP_ENCLOSED_1 ||
      fkind == FunctionConsts::OP_HOIST_1)
  {
    return e;
  } 
  else
  {
    expr* ce = e->get_single_child();
    while (ce != NULL)
    {
      e = ce;
      ce = e->get_single_child();
    }

    return e;
  }
}


/*******************************************************************************
  This rule looks for exprs that are inside a for loop but do not depend on the
  loop variable, and then moves such exprs outside the loop.
********************************************************************************/
expr* HoistRule::apply(
    RewriterContext& rCtx,
    expr* node,
    bool& modified)
{
  assert(node == rCtx.getRoot());

  csize numVars = 0;
  theVarIdMap.clear();
  theExprVarsMap.clear();

  expr_tools::index_flwor_vars(node, numVars, theVarIdMap, NULL);

  /*
  expr_tools::VarIdMap::const_iterator ite = varmap.begin();
  expr_tools::VarIdMap::const_iterator end = varmap.end();
  for (; ite != end; ++ite)
  {
    std::cerr << "[ " << ite->first << " --> " << ite->second << "]" << std::endl;
  }
  */

  DynamicBitset freeset(numVars+1);
  expr_tools::build_expr_to_vars_map(node, theVarIdMap, freeset, theExprVarsMap);

  PathHolder root;
  modified = hoistChildren(rCtx, node, &root);

  if (modified && root.theExpr != NULL)
  {
    assert(root.theExpr->get_expr_kind() == flwor_expr_kind);

    static_cast<flwor_expr*>(root.theExpr)->set_return_expr(node);
    return root.theExpr;
  }

  return node;
}


/*******************************************************************************
  Try to hoist the children of the given expr "e".
********************************************************************************/
bool HoistRule::hoistChildren(RewriterContext& rCtx, expr* e, PathHolder* path)
{
  bool status = false;

  if (e->get_expr_kind() == flwor_expr_kind)
  {
    flwor_expr* flwor = static_cast<flwor_expr *>(e);

    PathHolder step;
    step.prev = path;
    step.theExpr = e;

    csize numClauses = flwor->num_clauses();
    csize i = 0;

    while (i < numClauses)
    {
      flwor_clause* c = flwor->get_clause(i);

      switch (c->get_kind())
      {
      case flwor_clause::for_clause:
      case flwor_clause::let_clause:
      case flwor_clause::window_clause:
      {
        forletwin_clause* flwc = static_cast<forletwin_clause*>(c);
        expr* domainExpr = flwc->get_expr();

        expr* unhoistExpr = hoistExpr(rCtx, domainExpr, &step);

        if (unhoistExpr != NULL)
        {
          flwc->set_expr(unhoistExpr);
          status = true;
          numClauses = flwor->num_clauses();
          // TODO: the expr that was just hoisted here, may contain sub-exprs that
          // can be hoisted even earlier.
        }
        else if (domainExpr->is_sequential())
        {
          PathHolder root;

          bool hoisted = hoistChildren(rCtx, domainExpr, &root);

          if (hoisted)
          {
            if (root.theExpr != NULL)
            {
              assert(root.theExpr->get_expr_kind() == flwor_expr_kind);
              
              static_cast<flwor_expr*>(root.theExpr)->set_return_expr(domainExpr);
              flwc->set_expr(root.theExpr);
            }
            
            status = true;
            assert(numClauses == flwor->num_clauses());
          }
        }
        else
        {
          domainExpr = skip_children(domainExpr);

          if (hoistChildren(rCtx, domainExpr, &step))
          {
            status = true;
            numClauses = flwor->num_clauses();
          }
        }

        if (c->get_kind() == flwor_clause::window_clause)
        {
          window_clause* wc = static_cast<window_clause*>(c);
          flwor_wincond* startCond = wc->get_win_start();
          flwor_wincond* stopCond = wc->get_win_stop();

          if (startCond)
          {
            expr* condExpr = startCond->get_expr();

            ZORBA_ASSERT(!condExpr->is_sequential());

            ++step.clauseCount;

            expr* unhoistExpr = hoistExpr(rCtx, condExpr, &step);

            if (unhoistExpr != NULL)
            {
              startCond->set_expr(unhoistExpr);
              status = true;
              numClauses = flwor->num_clauses();
            }
            else
            {
              condExpr = skip_children(condExpr);

              if (hoistChildren(rCtx, condExpr, &step))
              {
                status = true;
                numClauses = flwor->num_clauses();
              }
            }

            --step.clauseCount;
          }

          if (stopCond)
          {
            expr* condExpr = stopCond->get_expr();

            ZORBA_ASSERT(!condExpr->is_sequential());

            ++step.clauseCount;

            expr* unhoistExpr = hoistExpr(rCtx, condExpr, &step);

            if (unhoistExpr != NULL)
            {
              stopCond->set_expr(unhoistExpr);
              status = true;
              numClauses = flwor->num_clauses();
            }
            else
            {
              condExpr = skip_children(condExpr);

              if (hoistChildren(rCtx, condExpr, &step))
              {
                status = true;
                numClauses = flwor->num_clauses();
              }
            }

            --step.clauseCount;
          }
        }

        break;
      }
      case flwor_clause::where_clause:
      {
        where_clause* wc = static_cast<where_clause*>(c);
        expr* we = wc->get_expr();

        ZORBA_ASSERT(!we->is_sequential());

        expr* unhoistExpr = hoistExpr(rCtx, we, &step);

        if (unhoistExpr != NULL)
        {
          wc->set_expr(unhoistExpr);
          status = true;
          numClauses = flwor->num_clauses();
        }
        else
        {
          we = skip_children(we);

          if (hoistChildren(rCtx, we, &step))
          {
            status = true;
            numClauses = flwor->num_clauses();
          }
        }

        break;
      }
      case flwor_clause::orderby_clause:
      {
        orderby_clause* oc = static_cast<orderby_clause*>(c);

        std::vector<expr*>::const_iterator ite = oc->begin();
        std::vector<expr*>::const_iterator end = oc->end();
        for (; ite != end; ++ite)
        {
          expr* oe = *ite;
          
          ZORBA_ASSERT(!oe->is_sequential());

          expr* unhoistExpr = hoistExpr(rCtx, oe, &step);

          if (unhoistExpr != NULL)
          {
            oc->set_column_expr(ite - oc->begin(), unhoistExpr);
            status = true;
            numClauses = flwor->num_clauses();
          }
          else
          {
            oe = skip_children(oe);

            if (hoistChildren(rCtx, oe, &step))
            {
              status = true;
              numClauses = flwor->num_clauses();
            }
          }
        }

        break;
      }
      case flwor_clause::groupby_clause:
      {
        groupby_clause* gc = static_cast<groupby_clause*>(c);

        var_rebind_list_t::iterator ite = gc->beginGroupVars();
        var_rebind_list_t::iterator end = gc->endGroupVars();
        for (; ite != end; ++ite)
        {
          expr* ge = (*ite).first;
          
          ZORBA_ASSERT(!ge->is_sequential());

          expr* unhoistExpr = hoistExpr(rCtx, ge, &step);

          if (unhoistExpr != NULL)
          {
            (*ite).first = unhoistExpr;
            status = true;
            numClauses = flwor->num_clauses();
          }
          else if (hoistChildren(rCtx, ge, &step))
          {
            status = true;
            numClauses = flwor->num_clauses();
          }
        }

        ite = gc->beginNonGroupVars();
        end = gc->endNonGroupVars();
        for (; ite != end; ++ite)
        {
          expr* ge = (*ite).first;
          
          ZORBA_ASSERT(!ge->is_sequential());

          expr* unhoistExpr = hoistExpr(rCtx, ge, &step);

          if (unhoistExpr != NULL)
          {
            (*ite).first = unhoistExpr;
            status = true;
            numClauses = flwor->num_clauses();
          }
          else if (hoistChildren(rCtx, ge, &step))
          {
            status = true;
            numClauses = flwor->num_clauses();
          }
        }

        break;
      }
      case flwor_clause::count_clause:
      {
        break;
      }
      case flwor_clause::materialize_clause:
      {
        break;
      }
      default:
        ZORBA_ASSERT(false);
      }

      i = ++(step.clauseCount);

      assert(numClauses == flwor->num_clauses());
    }

    expr* re = flwor->get_return_expr();
    expr* unhoistExpr = hoistExpr(rCtx, re, &step);

    if (unhoistExpr != NULL)
    {
      flwor->set_return_expr(unhoistExpr);
      status = true;
    }
    else if (re->is_sequential())
    {
      PathHolder root;
      bool nestedModified = hoistChildren(rCtx, re, &root);

      if (nestedModified && root.theExpr != NULL)
      {
        assert(root.theExpr->get_expr_kind() == flwor_expr_kind);

        static_cast<flwor_expr*>(root.theExpr)->set_return_expr(re);
        flwor->set_return_expr(root.theExpr);
      }

      status = nestedModified || status;
    }
    else
    {
      re = skip_children(re);

      status = hoistChildren(rCtx, re, &step) || status;
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
      expr* ce = **iter;

      PathHolder root;
      bool nestedModified = hoistChildren(rCtx, ce, &root);

      if (nestedModified && root.theExpr != NULL)
      {
        assert(root.theExpr->get_expr_kind() == flwor_expr_kind);

        static_cast<flwor_expr*>(root.theExpr)->set_return_expr(ce);
        (**iter) = root.theExpr;
      }

      status = nestedModified || status;

      iter.next();
    }
  }

  else if (e->is_updating() || e->get_expr_kind() == transform_expr_kind)
  {
    // do nothing
  }

  else if (e->get_expr_kind() == trycatch_expr_kind)
  {
    PathHolder step;
    step.prev = path;
    step.theExpr = e;
    path = &step;

    ExprIterator iter(e);

    while (!iter.done())
    {
      expr* ce = **iter;
      if (ce)
      {
        expr* unhoistExpr = hoistExpr(rCtx, ce, path);
        if (unhoistExpr != NULL)
        {
          **iter = unhoistExpr;
          status = true;
        }
        else
        {
          ce = skip_children(ce);

          status = hoistChildren(rCtx, ce, path) || status;
        }
      }

      iter.next();
    }
  }

  else
  {
    ExprIterator iter(e);

    while (!iter.done())
    {
      expr* ce = **iter;
      if (ce)
      {
        expr* unhoistExpr = hoistExpr(rCtx, ce, path);
        if (unhoistExpr != NULL)
        {
          **iter = unhoistExpr;
          status = true;
        }
        else
        {
          ce = skip_children(ce);

          status = hoistChildren(rCtx, ce, path) || status;
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
expr* HoistRule::hoistExpr(
    RewriterContext& rCtx,
    expr* e,
    struct PathHolder* path)
{
  if (non_hoistable(e) || e->constructsNodes())
  {
    return NULL;
  }

  const QueryLoc& loc = e->get_loc();
  static_context* sctx = e->get_sctx();
  user_function* udf = e->get_udf();

  assert(udf == rCtx.theUDF);

  expr_tools::ExprVarsMap::const_iterator fvme = theExprVarsMap.find(e);
  ZORBA_ASSERT(fvme != theExprVarsMap.end());
  const DynamicBitset& varset = fvme->second;

  PathHolder* step = path;
  PathHolder* nextstep = NULL;

  bool inloop = false;
  int clauseNo = 0;

  // step->prev == NULL means that expr e is not inside any flwor expr, and as a
  // result, there is nothing to hoist.
  while (step->prev != NULL)
  {
    if (step->theExpr->get_expr_kind() == trycatch_expr_kind)
    {
      // Should not hoist an expr out of a try-catch if it contains any try-catch vars
      trycatch_expr* trycatch = static_cast<trycatch_expr*>(step->theExpr);
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

          if (contains_var(trycatchVar, varset))
            return NULL;
        }
      }
    }
    else
    {
      assert(step->theExpr->get_expr_kind() == flwor_expr_kind);

      flwor_expr* flwor = static_cast<flwor_expr*>(step->theExpr);

      bool foundReferencedFLWORVar = false;
      bool foundSequentialClause = false;

      // Check whether expr e references any variables from the current flwor. If
      // not, then e can be hoisted out of the current flwor and we repeat the
      // while-loop to see if e can be hoisted w.r.t. the previous (outer) flwor.
      // If yes, then let V be the inner-most var referenced by e. If there are any
      // FOR vars after V, e can be hoisted out of any such FOR vars. Otherwise, e
      // cannot be hoisted.
      for (clauseNo = step->clauseCount - 1; clauseNo >= 0; --clauseNo)
      {
        flwor_clause* c = flwor->get_clause(clauseNo);

        switch (c->get_kind())
        {
        case flwor_clause::for_clause:
        case flwor_clause::let_clause:
        case flwor_clause::window_clause:
        {
          forletwin_clause* flwc = static_cast<forletwin_clause*>(c);

          if (flwc->get_expr()->is_sequential())
          {
            foundSequentialClause = true;
            break;
          }

          if (contains_var(flwc->get_var(), varset) ||
              contains_var(flwc->get_pos_var(), varset))
            // contains_var(flc->get_score_var(), varset)
          {
            foundReferencedFLWORVar = true;
            break;
          }

          if (c->get_kind() == flwor_clause::window_clause)
          {
            window_clause* wc = static_cast<window_clause*>(c);
            flwor_wincond* startCond = wc->get_win_start();
            flwor_wincond* stopCond = wc->get_win_stop();
            
            if (startCond)
            {
              const flwor_wincond_vars& vars = startCond->get_out_vars();

              if (contains_var(vars.posvar, varset) ||
                  contains_var(vars.curr, varset) ||
                  contains_var(vars.prev, varset) ||
                  contains_var(vars.next, varset))
              {
                foundReferencedFLWORVar = true;
                break;
              }

              const flwor_wincond_vars& invars = startCond->get_in_vars();

              if (contains_var(invars.posvar, varset) ||
                  contains_var(invars.curr, varset) ||
                  contains_var(invars.prev, varset) ||
                  contains_var(invars.next, varset))
              {
                foundReferencedFLWORVar = true;

                if (inloop)
                {
                  ZORBA_ASSERT(nextstep);
                  step = nextstep;
                  clauseNo = -1;
                }

                break;
              }
            }

            if (stopCond)
            {
              const flwor_wincond_vars& vars = stopCond->get_out_vars();

              if (contains_var(vars.posvar, varset) ||
                  contains_var(vars.curr, varset) ||
                  contains_var(vars.prev, varset) ||
                  contains_var(vars.next, varset))
              {
                foundReferencedFLWORVar = true;
                break;
              }

              const flwor_wincond_vars& invars = stopCond->get_in_vars();

              if (contains_var(invars.posvar, varset) ||
                  contains_var(invars.curr, varset) ||
                  contains_var(invars.prev, varset) ||
                  contains_var(invars.next, varset))
              {
                foundReferencedFLWORVar = true;

                if (inloop)
                {
                  ZORBA_ASSERT(nextstep);
                  step = nextstep;
                  clauseNo = -1;
                }

                break;
              }
            }
          }

          if (!inloop)
            inloop = ((c->get_kind() == flwor_clause::for_clause ||
                       c->get_kind() == flwor_clause::window_clause) &&
                      flwc->get_expr()->get_return_type()->max_card() >= 2);

          break;
        }
        case flwor_clause::groupby_clause:
        {
          groupby_clause* gc = static_cast<groupby_clause*>(c);

          var_rebind_list_t::iterator ite = gc->beginGroupVars();
          var_rebind_list_t::iterator end = gc->endGroupVars();
          for (; ite != end; ++ite)
          {
            if (contains_var((*ite).second, varset))
            {
              foundReferencedFLWORVar = true;
              break;
            }
          }

          if (foundReferencedFLWORVar)
            break;

          ite = gc->beginNonGroupVars();
          end = gc->endNonGroupVars();
          for (; ite != end; ++ite)
          {
            if (contains_var((*ite).second, varset))
            {
              foundReferencedFLWORVar = true;
              break;
            }
          }

          break;
        }
        case flwor_clause::count_clause:
        {
          count_clause* cc = static_cast<count_clause*>(c);

          if (contains_var(cc->get_var(), varset))
          {
            foundReferencedFLWORVar = true;
          }

          break;
        }
        case flwor_clause::orderby_clause:
        case flwor_clause::where_clause:
        {
          break;
        }
        case flwor_clause::materialize_clause:
        {
          return NULL;
        }
        default:
          ZORBA_ASSERT(false);
        }

        if (foundSequentialClause || foundReferencedFLWORVar)
          break;
      } // for each flwor clause

      if (foundSequentialClause || foundReferencedFLWORVar)
        break;

      if (step->prev->prev == NULL)
        break;
    } // flwor expr

    nextstep = step;
    step = step->prev;
  }

  if (!inloop)
    return NULL;

  // Hoisting is possible ... Go ahead and hoist e: (a) we create an internal LET
  // var: $$temp := op:hoist(e) (b) we place the $$temp declaration right after
  // variable V, and (c) we replace e with op:unhoist($$temp).

  var_expr* letvar = rCtx.createTempVar(sctx, loc, var_expr::let_var);

  expr* hoisted = rCtx.theEM->
  create_fo_expr(sctx, udf, loc, BUILTIN_FUNC(OP_HOIST_1), e);

  hoisted->setAnnotationFlags(e->getAnnotationFlags());
  //letvar->setFlags(e->getFlags());

  let_clause* flref = rCtx.theEM->create_let_clause(sctx, loc, letvar, hoisted);

  letvar->set_flwor_clause(flref);

  ZORBA_ASSERT(step->theExpr == NULL ||
               step->theExpr->get_expr_kind() == flwor_expr_kind);

  if (step->prev == NULL)
  {
    if (step->theExpr == NULL)
    {
      step->theExpr = rCtx.theEM->create_flwor_expr(sctx, udf, loc);
    }

    static_cast<flwor_expr*>(step->theExpr)->add_clause(flref);
  }
  else
  {
    static_cast<flwor_expr*>(step->theExpr)->add_clause(clauseNo + 1, flref);
    ++step->clauseCount;
  }

  expr* unhoisted = rCtx.theEM->
  create_fo_expr(sctx, udf, loc,
                 BUILTIN_FUNC(OP_UNHOIST_1),
                 rCtx.theEM->create_wrapper_expr(sctx, udf, loc, letvar));

  unhoisted->setAnnotationFlags(e->getAnnotationFlags());

  return unhoisted;
}


/*******************************************************************************
  Check if the given var is contained in the given varset.
********************************************************************************/
bool HoistRule::contains_var(var_expr* v, const DynamicBitset& varset)
{
  if (v == NULL)
    return false;

  expr_tools::VarIdMap::const_iterator i = theVarIdMap.find(v);

  if (i == theVarIdMap.end())
    return false;

  return varset.get(i->second);
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
      k == argument_placeholder_expr_kind ||
      (k == wrapper_expr_kind &&
       non_hoistable(static_cast<const wrapper_expr*>(e)->get_input())) ||
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
    FunctionConsts::FunctionKind fkind = f->getKind();

    if (fkind == FunctionConsts::OP_CONCATENATE_N && fo->num_args() == 0)
      return true;

    if (fkind == FunctionConsts::STATIC_COLLECTIONS_DML_COLLECTION_1 ||
        fkind == FunctionConsts::STATIC_COLLECTIONS_DML_COLLECTION_2 ||
        fkind == FunctionConsts::STATIC_COLLECTIONS_DML_COLLECTION_3 ||
        fkind == FunctionConsts::DYNAMIC_COLLECTIONS_DML_COLLECTION_1 ||
        fkind == FunctionConsts::DYNAMIC_COLLECTIONS_DML_COLLECTION_2 ||
        fkind == FunctionConsts::DYNAMIC_COLLECTIONS_DML_COLLECTION_3)
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
