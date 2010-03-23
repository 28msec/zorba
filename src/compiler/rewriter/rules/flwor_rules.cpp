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

#include "functions/function.h"
#include "functions/library.h"

#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/framework/rule_driver.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/rewriter/tools/expr_tools.h"

#include "context/static_context.h"

#include "types/typeops.h"
#include "types/casting.h"

#include <memory>


namespace zorba
{

static void collect_flw_vars(const flwor_expr& flwor, VarSetAnnVal& vars);

static bool is_trivial_expr(const expr* e);

static bool safe_to_fold_single_use(var_expr*, const flwor_expr&, static_context*);

static bool var_in_try_block_or_in_loop(static_context*, const var_expr*, const expr*, bool, bool, ulong&);

static bool is_subseq_pred(RewriterContext&, const flwor_expr*, const expr*, var_expr_t&, expr_t&);


#define MODIFY( expr ) do { modified = true; expr; } while (0)


/*******************************************************************************

********************************************************************************/
class SubstVars : public RewriteRule
{
protected:
  const var_expr   * theVarExpr;
  expr             * theSubstExpr;
  std::string        theRuleName;

public:
  SubstVars(const var_expr* var, expr* subst)
    :
    theVarExpr(var),
    theSubstExpr(subst),
    theRuleName("SubstVars")
  {
  }

  const std::string& getRuleName() const { return theRuleName; }

  expr_t rewritePre(expr* node, RewriterContext& rCtx);
  expr_t rewritePost(expr* node, RewriterContext& rCtx);
};


RULE_REWRITE_PRE(SubstVars)
{
  return (node == theVarExpr) ? theSubstExpr : NULL;
}


RULE_REWRITE_POST(SubstVars)
{
  return NULL;
}


/*******************************************************************************
  Replace all references to var "var" inside the expr "root" with expr "subst"
********************************************************************************/
expr_t subst_vars(RewriterContext rCtx0, expr_t root, const var_expr* var, expr* subst)
{
  RewriterContext rCtx (rCtx0.getCompilerCB(), root);

  std::auto_ptr<Rewriter> rw(new SingletonRuleMajorDriverBase(rule_ptr_t(new SubstVars(var, subst))));

  rw->rewrite(rCtx);

#if 0  // debug substitutions
  std::cout << "After subst " << var << ":" << std::endl; rCtx.getRoot()->put (std::cout) << std::endl;
#endif
  return rCtx.getRoot();
}



/*******************************************************************************

********************************************************************************/
RULE_REWRITE_PRE(EliminateUnusedLetVars)
{
  flwor_expr* flworp = dynamic_cast<flwor_expr *>(node);

  if (flworp == NULL || flworp->is_general())
    return NULL;

  flwor_expr& flwor = *flworp;

  VarSetAnnVal myVars;
  collect_flw_vars(flwor, myVars);

  const forletwin_clause& flwc = *reinterpret_cast<const forletwin_clause *>(flwor[0]);

  unsigned numClauses = flwor.num_clauses();
  unsigned numForLetClauses = 0;

  // "for $x in E return $x"  --> "E"
  // "let $x := E return $x"  --> "E"
  if (numClauses == 1 &&
      myVars.varset.size() == 1 &&
      flwor.get_return_expr()->get_expr_kind() == wrapper_expr_kind)
  {
    const wrapper_expr* w = static_cast<const wrapper_expr*>(flwor.get_return_expr());
    if (w->get_expr() == flwc.get_var())
      return flwc.get_expr();
  }

  // "for $x in ... where E ... return ...", and E doesn't depend on FLWOR vars -->
  // "if E then flwor else ()", where flwor is the original flwor expr without the
  // where clause.
  expr* whereExpr;
  if ((whereExpr = flwor.get_where()) != NULL &&
      flwor.get_annotation(Annotations::NONDISCARDABLE_EXPR) != TSVAnnotationValue::TRUE_VAL)
  {
    const var_ptr_set& whereVars = get_varset_annotation(whereExpr,
                                                         Annotations::FREE_VARS);
    var_ptr_set diff;
    set_intersection(myVars.varset.begin(), myVars.varset.end(),
                     whereVars.begin(), whereVars.end(),
                     inserter(diff, diff.begin()));
    if (diff.empty())
    {
      expr_t oldWhere = whereExpr;
      flwor.remove_where_clause();

      return fix_if_annotations(new if_expr(node->get_sctx_id(),
                                            LOC(node),
                                            NULL,
                                            oldWhere,
                                            &flwor,
                                            fo_expr::create_seq(node->get_sctx_id(), LOC(node))));
    }
  }

  bool modified = false;
  static_context* sctx = rCtx.getStaticContext(node);

  // (a) Remove, if possible, FOR/LET vars that are not referenced anywhere
  // (b) Replace, if possible, FOR/LET vars that are referenced only once, with
  //     their domain expr.
  for (ulong i = 0; i < numClauses; )
  {
    flwor_clause& c = *flwor.get_clause(i, false);

    if (c.get_kind() == flwor_clause::for_clause ||
        c.get_kind() == flwor_clause::let_clause)
    {
      numForLetClauses++;
      forletwin_clause* flwc = static_cast<forletwin_clause *>(&c);
      for_clause* fc = static_cast<for_clause *>(&c);

      bool is_let = c.get_kind() == flwor_clause::let_clause;

      expr* domainExpr = flwc->get_expr();
      var_expr* var = flwc->get_var();
      const var_expr* pvar = (is_let ? NULL : fc->get_pos_var());
      TypeConstants::quantifier_t for_quant;
      ulong for_quant_cnt = 2;  // cardinality of FOR clause: 0, 1 or more

      if (pvar != NULL && count_variable_uses(&flwor, pvar, &rCtx, 1) == 0)
      {
        MODIFY(fc->set_pos_var(NULL));
        pvar = NULL;
      }

      if (domainExpr->is_sequential())
      {
        ++i;
        continue;
      }

      if (! is_let)
      {
        xqtref_t domainType = domainExpr->return_type(sctx);
        for_quant_cnt = TypeOps::type_max_cnt(*domainType);
        for_quant = domainType->get_quantifier();
      }

      // Cannot substitute a FOR var whose domain might contain more than 1 items.
      if (is_let || for_quant == TypeConstants::QUANT_ONE)
      {
        if (for_quant_cnt == 0)
        {
          // FOR clause with 0 cardinality
          return fo_expr::create_seq(node->get_sctx_id(), LOC(node));
        }

        if (pvar != NULL)
        {
          MODIFY(subst_vars(rCtx,
                            node,
                            pvar,
                            new const_expr(node->get_sctx_id(),
                                           LOC(node),
                                           xqp_integer::parseInt(1))));
        }

        int uses = count_variable_uses(&flwor, var, &rCtx, 2);
        if (uses > 1)
        {
          if (is_trivial_expr(domainExpr))
          {
            subst_vars(rCtx, node, var, domainExpr);
            MODIFY(flwor.remove_clause(i));
            --numClauses;
            --numForLetClauses;
          }
          else
          {
            ++i;
          }
        }
        else // uses == 1 or 0
        {
          if (uses == 1)
          {
            if (is_trivial_expr(domainExpr) || safe_to_fold_single_use(var, flwor, sctx))
            {
              subst_vars(rCtx, node, var, domainExpr);
              MODIFY(flwor.remove_clause(i));
              --numClauses;
              --numForLetClauses;
            }
            else
            {
              ++i;
            }
          }
          else // uses == 0
          {
            if (domainExpr->get_annotation(Annotations::NONDISCARDABLE_EXPR) !=
                TSVAnnotationValue::TRUE_VAL)
            {
              MODIFY(flwor.remove_clause(i));
              --numClauses;
              --numForLetClauses;
            }
            else
            {
              ++i;
            }
          }
        }
      }
      else
      {
        ++i;
      }
    }
    else
    {
      ++i;
    }
  }

  // FLWOR with no remaining clauses
  if (numForLetClauses == 0)
  {
    expr_t result = flwor.get_return_expr(false);
    expr* whereExpr;

    if ((whereExpr = flwor.get_where()) != NULL)
    {
      result = fix_if_annotations(new if_expr(whereExpr->get_sctx_id(),
                                              LOC(whereExpr),
                                              NULL,
                                              whereExpr,
                                              result,
                                              fo_expr::create_seq(whereExpr->get_sctx_id(), LOC(whereExpr))));
    }

    return result;
  }

  return modified ? node : NULL;
}


RULE_REWRITE_POST(EliminateUnusedLetVars)
{
  return NULL;
}


/*******************************************************************************
  Returns a set containing all variables (including positional) defined by the
  FOR, LET, or WINDOW clauses of a flwor expr.
********************************************************************************/
static void collect_flw_vars(const flwor_expr& flwor, VarSetAnnVal& vars)
{
  for (uint32_t i = 0; i < flwor.num_clauses(); ++i)
  {
    const flwor_clause& c = *flwor[i];

    if (c.get_kind() == flwor_clause::for_clause)
    {
      const for_clause* fc = static_cast<const for_clause *>(&c);

      vars.add(fc->get_var());

      if (fc->get_pos_var() != NULL)
        vars.add(fc->get_pos_var());
    }

    else if (c.get_kind() == flwor_clause::let_clause)
    {
      const let_clause* lc = static_cast<const let_clause *>(&c);

      vars.add(lc->get_var());
    }

    else if (c.get_kind() == flwor_clause::window_clause)
    {
      const window_clause* wc = static_cast<const window_clause *>(&c);

      vars.add(wc->get_var());

      if (wc->get_win_start() != NULL)
      {
        const flwor_wincond* cond = wc->get_win_start();
        const flwor_wincond::vars& condvars = cond->get_out_vars();

        if (condvars.posvar != NULL) vars.add(condvars.posvar);
        if (condvars.curr != NULL) vars.add(condvars.curr);
        if (condvars.prev != NULL) vars.add(condvars.prev);
        if (condvars.next != NULL) vars.add(condvars.next);
      }

      if (wc->get_win_stop() != NULL)
      {
        const flwor_wincond* cond = wc->get_win_stop();
        const flwor_wincond::vars& condvars = cond->get_out_vars();

        if (condvars.posvar != NULL) vars.add(condvars.posvar);
        if (condvars.curr != NULL) vars.add(condvars.curr);
        if (condvars.prev != NULL) vars.add(condvars.prev);
        if (condvars.next != NULL) vars.add(condvars.next);
      }
    }
  }
}


/*******************************************************************************
  Cannot throw exception that can be caught by a try block
********************************************************************************/
static bool is_trivial_expr(const expr* e)
{
  switch (e->get_expr_kind())
  {
  case const_expr_kind: // ????
  {
    return true;
  }
  case var_expr_kind:
  {
    enum var_expr::var_kind vk = static_cast<const var_expr*>(e)->get_kind();
    return vk != var_expr::arg_var;
  }
  case wrapper_expr_kind:
  {
    return is_trivial_expr(static_cast<const wrapper_expr*>(e)->get_expr());
  }
  default:
    return false;
  }
}


/*******************************************************************************

********************************************************************************/
static bool safe_to_fold_single_use(
    var_expr* v,
    const flwor_expr& flwor,
    static_context* sctx)
{
  bool declared = false;
  expr_t referencingExpr = NULL;

  expr* domainExpr = v->get_domain_expr();

  bool hasNodeConstr = domainExpr->contains_node_construction();

  for (ulong i = 0; i < flwor.num_clauses(); ++i)
  {
    const flwor_clause& c = *flwor[i];

    if (c.get_kind() == flwor_clause::for_clause ||
        c.get_kind() == flwor_clause::let_clause)
    {
      const forletwin_clause& flc = *static_cast<const forletwin_clause *>(&c);
      var_expr* var = flc.get_var();

      if (! declared)
      {
        declared = (v == var);
        continue;
      }

      if (count_variable_uses(flc.get_expr(), v, NULL, 1) == 1)
      {
        referencingExpr = flc.get_expr();
        break;
      }

      // If the var is referenced inside a for loop with more than 1 iterations,
      // then we don't replace the var with its domain expr because the domain
      // expr will be computed once per iteration instead of just once.
      if (c.get_kind() == flwor_clause::for_clause &&
          TypeOps::type_max_cnt(*flc.get_expr()->return_type(sctx)) >= 2)
      {
        return false;
      }

      // test rbkt/zorba/extern/5890.xq illustrates why this check is needed
      if (hasNodeConstr && c.get_expr()->contains_node_construction())
      {
        return false;
      }
    }
  }

  if (flwor.get_where() != NULL &&
      referencingExpr == NULL &&
      count_variable_uses(flwor.get_where(), v, NULL, 1) == 1)
  {
    referencingExpr = flwor.get_where();
  }

  if (referencingExpr == NULL &&
      count_variable_uses(flwor.get_return_expr(), v, NULL, 1) == 1)
  {
    referencingExpr = flwor.get_return_expr();
  }

  if (referencingExpr == NULL)
  {
    return false;
  }

  ulong numRefs = 1;
  return !var_in_try_block_or_in_loop(sctx,
                                      v,
                                      referencingExpr,
                                      false,
                                      hasNodeConstr, 
                                      numRefs);
}


/*******************************************************************************

********************************************************************************/
static bool var_in_try_block_or_in_loop(
    static_context* sctx,
    const var_expr* v,
    const expr* e,
    bool in_try_block_or_in_loop,
    bool hasNodeConstr,
    ulong& numRemainingRefs)
{
  if (numRemainingRefs == 0)
    return false;

  expr_kind_t kind = e->get_expr_kind();

  if (kind == trycatch_expr_kind)
  {
    const trycatch_expr* tce = dynamic_cast<const trycatch_expr *>(e);

    if (var_in_try_block_or_in_loop(sctx,
                                    v,
                                    tce->get_try_expr(),
                                    true,
                                    hasNodeConstr,
                                    numRemainingRefs))
    {
      return true;
    }

    std::vector<catch_clause_t>::const_iterator i = tce->begin();
    std::vector<catch_clause_t>::const_iterator end = tce->end();
    while(i != end)
    {
      if (var_in_try_block_or_in_loop(sctx,
                                      v,
                                      (*i)->get_catch_expr(),
                                      in_try_block_or_in_loop,
                                      hasNodeConstr,
                                      numRemainingRefs))
      {
        return true;
      }
      ++i;
    }
    return false;
  }
  else if (kind == flwor_expr_kind)
  {
    const flwor_expr& flwor = *static_cast<const flwor_expr *>(e);

		expr_t referencingExpr = NULL;

    for (ulong i = 0; i < flwor.num_clauses(); ++i)
    {
      const flwor_clause& c = *flwor[i];

      if (c.get_kind() == flwor_clause::for_clause ||
          c.get_kind() == flwor_clause::let_clause)
      {
        const forletwin_clause& flc = *static_cast<const forletwin_clause *>(&c);;

        if (count_variable_uses(flc.get_expr(), v, NULL, 1) == 1)
        {
          referencingExpr = flc.get_expr();
          break;
        }

        if (c.get_kind() == flwor_clause::for_clause &&
            TypeOps::type_max_cnt(*flc.get_expr()->return_type(sctx)) >= 2)
        {
          return true;
        }

        // test rbkt/zorba/extern/5890.xq illustrates why this check is needed
        if (hasNodeConstr && c.get_expr()->contains_node_construction())
        {
          return true;
        }
      }
    }

		if (referencingExpr == NULL)
    {
			referencingExpr = flwor.get_return_expr();
		}

		return var_in_try_block_or_in_loop(sctx,
                                       v,
                                       &*referencingExpr,
                                       in_try_block_or_in_loop,
                                       hasNodeConstr,
                                       numRemainingRefs);
  }
  else if (e == v)
  {
    --numRemainingRefs;
    return in_try_block_or_in_loop;
  }

#if 0
  else if (kind == elem_expr_kind ||
      kind == attr_expr_kind ||
      kind == pi_expr_kind ||
      kind == text_expr_kind ||
      kind == doc_expr_kind)
  {
    // test rbkt/zorba/extern/5890.xq illustrates why this check is needed
    if (hasNodeConstr)
      return true;
  }
#endif

  // Or else navigate down all children
  const_expr_iterator ei = e->expr_begin_const();
  while(!ei.done())
  {
    if (var_in_try_block_or_in_loop(sctx,
                                    v,
                                    &*(*ei),
                                    in_try_block_or_in_loop,
                                    hasNodeConstr,
                                    numRemainingRefs))
    {
      return true;
    }
    ++ei;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
RULE_REWRITE_PRE(RefactorPredFLWOR)
{
  flwor_expr* flwor = dynamic_cast<flwor_expr *>(node);

  if (flwor == NULL || flwor->is_general())
    return NULL;

  static_context* sctx = rCtx.getStaticContext(node);

  if_expr* ifReturnExpr = dynamic_cast<if_expr*>(flwor->get_return_expr(true));
  expr* whereExpr = flwor->get_where();

  // "for $x in ... return if (ce) then te else ()" -->
  // "for $x in ... where ce return te"
  if (ifReturnExpr != NULL &&
      whereExpr == NULL &&
      ifReturnExpr->is_simple() &&
      TypeOps::is_empty(*ifReturnExpr->get_else_expr()->return_type(sctx)))
  {
    expr_t cond = ifReturnExpr->get_cond_expr(false);
    expr_t then = ifReturnExpr->get_then_expr(false);
    flwor->set_return_expr(then);
    flwor->set_where(cond);
    return flwor;
  }

  expr_t posExpr;
  var_expr_t posVar;

  // '... for $x at $p in E ... where $p = posExpr ... return ...' -->
  // '... for $x in fn:subsequence(E, posExpr, 1) ... return ...
  if (whereExpr != NULL &&
      is_subseq_pred(rCtx, flwor, whereExpr, posVar, posExpr) &&
      count_variable_uses(flwor, posVar, &rCtx, 2) <= 1)
  {
    function* subseq = GET_BUILTIN_FUNCTION(FN_ZORBA_INT_SUBSEQUENCE_3);
    expr* domainExpr = posVar->get_for_clause()->get_expr();

    std::vector<expr_t> args(3);
    args[0] = domainExpr;
    args[1] = posExpr;
    args[2] = new const_expr(posExpr->get_sctx_id(),
                             LOC(posExpr),
                             xqp_integer::parseInt(1));

    rchandle<fo_expr> result = new fo_expr(whereExpr->get_sctx_id(),
                                           LOC(whereExpr),
                                           subseq,
                                           args);
    fix_annotations(&*result);
    for_clause* clause = posVar->get_for_clause();
    clause->set_expr(&*result);
    clause->set_pos_var(NULL);
    flwor->remove_where_clause();

    return flwor;
  }

  return NULL;
}


RULE_REWRITE_POST(RefactorPredFLWOR)
{
  return NULL;
}


/*******************************************************************************
  Checks whether "condExpr" has the form '$posVar = posExpr', where posExpr is 
  an expression whose type is xs:positiveInteger, or an integer literal with
  value >= 1.
********************************************************************************/
static bool is_subseq_pred(
    RewriterContext& rCtx,
    const flwor_expr* flworExpr,
    const expr* condExpr,
    var_expr_t& posVar,
    expr_t& posExpr)
{
  static_context* sctx = rCtx.getStaticContext(condExpr);
  TypeManager* tm = sctx->get_typemanager();
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  const fo_expr* fo = dynamic_cast<const fo_expr*>(condExpr);

  if (fo == NULL)
    return false;

  const function* f = fo->get_func();

  if (f->getKind() != FunctionConsts::OP_EQUAL_2 &&
      f->getKind() != FunctionConsts::OP_VALUE_EQUAL_2)
    return false;

  for (ulong i = 0; i < 2; i++)
  {
    posVar = fo->get_arg(i)->get_var();
    posExpr = fo->get_arg(1 - i);
    const const_expr* posConstExpr = dynamic_cast<const const_expr*>(posExpr.getp());

    if (posVar != NULL &&
        posVar->get_kind() == var_expr::pos_var &&
        flworExpr->defines_variable(posVar) >= 0)
    {
      if (posConstExpr != NULL)
      {
        const store::Item* val = posConstExpr->get_val();
        xqtref_t valType = tm->create_named_type(val->getType());

        if (TypeOps::is_subtype(*valType, *rtm.INTEGER_TYPE_ONE) &&
            val->getIntegerValue() >= xqp_integer::parseInt(1))
        {
          return true;
        }
      }
      else
      {
        xqtref_t posExprType = posExpr->return_type(sctx);

        if (TypeOps::is_subtype(*posExprType, *rtm.INTEGER_TYPE_ONE))
        {
          VarIdMap varidMap;
          ulong numFlworVars = 0;
          index_flwor_vars(flworExpr, numFlworVars, varidMap, NULL);

          DynamicBitset varset(numFlworVars);
          ExprVarsMap exprVarMap;
          build_expr_to_vars_map(posExpr, varidMap, varset, exprVarMap);

          var_expr* forVar = posVar->get_for_clause()->get_var();
          ulong forVarId = varidMap[forVar];

          std::vector<ulong> posExprVarIds;
          exprVarMap[posExpr].getSet(posExprVarIds);

          ulong numPosExprVars = posExprVarIds.size();
          for (ulong i = 0; i < numPosExprVars; ++i)
          {
            if (posExprVarIds[i] >= forVarId)
              return false;
          }
          
          return true;
        }
      }
    }
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
RULE_REWRITE_PRE(MergeFLWOR)
{
  flwor_expr* flwor = dynamic_cast<flwor_expr *>(node);

  if (flwor == NULL)
    return NULL;

  bool modified = false;

  if (flwor->get_return_expr()->get_expr_kind() == flwor_expr_kind)
  {
    flwor_expr_t returnFlwor = static_cast<flwor_expr*>(flwor->get_return_expr(true));

    if (!flwor->is_general())
    {
      ulong numClauses = flwor->num_clauses();

      for (ulong i = 0; i < numClauses; ++i)
      {
        const flwor_clause* c = (*flwor)[i];

        if (c->get_kind() == flwor_clause::where_clause ||
            c->get_kind() == flwor_clause::group_clause ||
            c->get_kind() == flwor_clause::order_clause)
        {
          goto next1;
        }
      }
    }

    ulong numClauses = returnFlwor->num_clauses();
    
    for (ulong i = 0; i < numClauses; ++i)
    {
      const flwor_clause* c = (*returnFlwor)[i];
      
      if (c->get_kind() == flwor_clause::group_clause ||
          c->get_kind() == flwor_clause::order_clause)
      {
        goto next1;
      }
    }

    for (ulong i = 0; i < numClauses; ++i)
    {
      flwor->add_clause(returnFlwor->get_clause(i, false));
    }

    flwor->set_return_expr(returnFlwor->get_return_expr(true));

    modified = true;
  }

 next1:

#if 1
  ulong numClauses = flwor->num_clauses();

  for (ulong i = 0; i < numClauses; ++i)
  {
    bool merge = false;
    flwor_expr_t nestedFlwor;
    ulong numNestedClauses;

    flwor_clause* c = flwor->get_clause(i, false);

    expr* domainExpr = c->get_expr();

    if (domainExpr != NULL && domainExpr->get_expr_kind() == flwor_expr_kind)
    {
      nestedFlwor = static_cast<flwor_expr*>(c->get_expr());
      numNestedClauses = nestedFlwor->num_clauses();

      if (c->get_kind() == flwor_clause::let_clause)
      {
        merge = true;

        for (ulong j = 0; j < numNestedClauses; ++j)
        {
          if ((*nestedFlwor)[j]->get_kind() != flwor_clause::let_clause)
          {
            merge = false;
            break;
          }
        }
      }
      else if (c->get_kind() == flwor_clause::for_clause &&
               c->get_pos_var() == NULL)
      {
        merge = true;

        for (ulong j = 0; j < numNestedClauses; ++j)
        {
          flwor_clause* nestedClause = nestedFlwor->get_clause(j, false);
          flwor_clause::ClauseKind nestedClauseKind = nestedClause->get_kind();

          if (nestedClauseKind != flwor_clause::let_clause &&
              nestedClauseKind != flwor_clause::for_clause)
          {
#if 1
            // temp hack until we have an optimized general flwor
            if (nestedClauseKind == flwor_clause::where_clause &&
                i == numClauses-1 &&
                flwor->get_where() == NULL &&
                nestedFlwor->get_return_expr()->get_var() != NULL)
            {
              continue;
            }
#endif
            merge = false;
            break;
          }
        }
      }
    }

    if (merge)
    {
      for (ulong j = 0; j < numNestedClauses; ++j)
      {
        flwor_clause* nestedClause = nestedFlwor->get_clause(j, false);
#if 1
        if (nestedClause->get_kind() == flwor_clause::where_clause)
          flwor->add_clause(i+j+1, nestedClause);
        else
#endif
          flwor->add_clause(i+j, nestedClause);
      }

      c->set_expr(nestedFlwor->get_return_expr(false));

      numClauses += numNestedClauses;
      i += numNestedClauses;

      modified = true;
    }
  }
#endif

  return (modified ? node : NULL);
}


RULE_REWRITE_POST(MergeFLWOR)
{
  return NULL;
}


}
/* vim:set ts=2 sw=2: */
