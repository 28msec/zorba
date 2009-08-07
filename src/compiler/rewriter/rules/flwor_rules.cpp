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
#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/framework/rule_driver.h"
#include "compiler/expression/expr.h"
#include "context/static_context.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "types/typeops.h"
#include "types/casting.h"

#include <memory>

using namespace std;

namespace zorba 
{

static void collect_flw_vars(const flwor_expr& flwor, VarSetAnnVal& vars);

static bool is_trivial_expr(expr* e);

static bool safe_to_fold_single_use(var_expr*, const flwor_expr&, static_context*);

static bool var_in_try_block_or_in_loop(static_context*, var_expr*, expr*, bool);

static bool refactor_index_pred(RewriterContext&, const expr*, var_expr*&, rchandle<const_expr>&);


#define MODIFY( expr ) do { modified = true; expr; } while (0)


/*******************************************************************************

********************************************************************************/
class SubstVars : public RewriteRule 
{
protected:
  var_expr   * var;
  expr       * subst;
  std::string m_ruleName;

public:
  SubstVars(var_expr *var_, expr *subst_) 
    :
    var (var_), subst (subst_), m_ruleName("SubstVars") 
  {
  }

  const std::string& getRuleName() const { return m_ruleName; }

  expr_t rewritePre(expr *node, RewriterContext& rCtx);
  expr_t rewritePost(expr *node, RewriterContext& rCtx);
};


RULE_REWRITE_PRE(SubstVars) 
{
  return (node == var) ? subst : NULL;
}
  

RULE_REWRITE_POST(SubstVars) 
{
  return NULL;
}


/*******************************************************************************
  Replace all references to var "var" inside the expr "root" with expr "subst"
********************************************************************************/
expr_t subst_vars (RewriterContext rCtx0, expr_t root, var_expr* var, expr* subst) 
{
  RewriterContext rCtx (rCtx0.getCompilerCB (), root);
  auto_ptr<Rewriter> rw(new SingletonRuleMajorDriverBase(rule_ptr_t(new SubstVars(var, subst))));
  rw->rewrite(rCtx);
#if 0  // debug substitutions
  cout << "After subst " << var << ":" << endl; rCtx.getRoot()->put (cout) << endl;
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
      flwor.get_return_expr() == flwc.get_var())
  {
    return flwc.get_expr();
  }

  // "for $x in ... where E ... return ...", and E doesn't depend on FLWOR vars -->
  // "if E then flwor else ()", where flwor is the original flwor expr without the
  // where clause.
  expr* whereExpr;
  if ((whereExpr = flwor.get_where()) != NULL && 
      flwor.get_annotation(AnnotationKey::NONDISCARDABLE_EXPR) != TSVAnnotationValue::TRUE_VAL) 
  {
    const var_ptr_set& whereVars = get_varset_annotation(whereExpr,
                                                         AnnotationKey::FREE_VARS);
    var_ptr_set diff;
    set_intersection(myVars.varset.begin(), myVars.varset.end(),
                     whereVars.begin(), whereVars.end(),
                     inserter(diff, diff.begin()));
    if (diff.empty()) 
    {
      expr_t oldWhere = whereExpr;
      flwor.remove_where_clause();

      return fix_if_annotations(new if_expr(node->get_cur_sctx(), LOC(node),
                                            oldWhere,
                                            &flwor,
                                            fo_expr::create_seq (node->get_cur_sctx(), LOC(node))));
    }
  }

  bool modified = false;
  static_context* sctx = rCtx.getStaticContext();

  // (a) Remove, if possible, FOR/LET vars that are not referenced anywhere
  // (b) Replace, if possible, FOR/LET vars that are referenced only once, with
  //     their domain expr.
  for (unsigned i = 0; i < numClauses; )
  {
    flwor_clause& c = *flwor[i];

    if (c.get_kind() == flwor_clause::for_clause ||
        c.get_kind() == flwor_clause::let_clause)
    {
      numForLetClauses++;
      forletwin_clause* flwc = static_cast<forletwin_clause *>(&c);
      for_clause* fc = static_cast<for_clause *>(&c);

      bool is_let = c.get_kind() == flwor_clause::let_clause;

      expr* domainExpr = flwc->get_expr();
      var_expr* var = flwc->get_var();
      var_expr* pvar = (is_let ? NULL : fc->get_pos_var());
      int quant_cnt = 2;  // cardinality of for clause: 0, 1 or more

      if (pvar != NULL && count_variable_uses(&flwor, pvar, 1) == 0)
        MODIFY(fc->set_pos_var(pvar = NULL));

      if (! is_let) 
      {
        xqtref_t domainType = domainExpr->return_type(sctx);
        quant_cnt = TypeOps::type_max_cnt(*domainType);
      }

      // Cannot substitute a FOR var whose domain might contain more than 1 items.
      if (is_let || quant_cnt < 2) 
      {
        if (quant_cnt == 0)
          return fo_expr::create_seq (node->get_cur_sctx(), LOC(node));

        if (pvar != NULL)
          MODIFY(subst_vars(rCtx,
                            node,
                            pvar,
                            new const_expr(node->get_cur_sctx(), LOC(node), xqp_integer::parseInt(1))));

        int uses = count_variable_uses(&flwor, var, 2);
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
            if (domainExpr->get_annotation(AnnotationKey::NONDISCARDABLE_EXPR) !=
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
    expr_t result = flwor.get_return_expr();
    expr* whereExpr;
    if ((whereExpr = flwor.get_where()) != NULL)
      result = fix_if_annotations(new if_expr(whereExpr->get_cur_sctx(), LOC(whereExpr),
                                              whereExpr,
                                              result,
                                              fo_expr::create_seq(whereExpr->get_cur_sctx(), LOC(whereExpr))));
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
static bool is_trivial_expr (expr* e) 
{
  switch (e->get_expr_kind ()) 
  {
  case const_expr_kind: // ????
  case var_expr_kind: 
  {
    enum var_expr::var_kind vk = static_cast<var_expr *>(e)->get_kind();
    return vk != var_expr::arg_var;
  }
  case wrapper_expr_kind:
  {
    return is_trivial_expr(static_cast<wrapper_expr *>(e)->get_expr());
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

  for (unsigned i = 0; i < flwor.num_clauses(); ++i) 
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

      if (count_variable_uses(flc.get_expr(), v, 1) == 1) 
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
    }
  }

         
  if (flwor.get_where() != NULL &&
      referencingExpr == NULL &&
      count_variable_uses(flwor.get_where(), v, 1) == 1)
  {
    referencingExpr = flwor.get_where();
  }

  if (referencingExpr == NULL &&
      count_variable_uses(flwor.get_return_expr(), v, 1) == 1)
  {
    referencingExpr = flwor.get_return_expr();
  }

  if (referencingExpr == NULL) 
  {
    return false;
  }

  return !var_in_try_block_or_in_loop(sctx, v, referencingExpr, false);
}


/*******************************************************************************

********************************************************************************/
static bool var_in_try_block_or_in_loop(
    static_context* sctx,
    var_expr* v,
    expr* e, 
    bool in_try_block_or_in_loop)
{
  if (e->get_expr_kind() == trycatch_expr_kind) 
  {
    trycatch_expr* tce = dynamic_cast<trycatch_expr *>(e);
    if (var_in_try_block_or_in_loop(sctx, v, &*tce->get_try_expr(), true)) 
    {
      return true;
    }
    std::vector<trycatch_expr::clauseref_t>::const_iterator i = tce->begin();
    std::vector<trycatch_expr::clauseref_t>::const_iterator end = tce->end();
    while(i != end) 
    {
      if (var_in_try_block_or_in_loop(sctx,
                                      v,
                                      &*(*i)->get_catch_expr_h(),
                                      in_try_block_or_in_loop)) 
      {
        return true;
      }
    }
    return false;
  }
  else if (e->get_expr_kind() == flwor_expr_kind) 
  {
    flwor_expr& flwor = *static_cast<flwor_expr *>(e);
    
		expr_t referencingExpr = NULL;

    for (uint32_t i = 0; i < flwor.num_clauses(); i++) 
    {
      const flwor_clause& c = *flwor[i];

      if (c.get_kind() == flwor_clause::for_clause ||
          c.get_kind() == flwor_clause::let_clause)
      {
        const forletwin_clause& flc = *static_cast<const forletwin_clause *>(&c);;

        if (count_variable_uses(flc.get_expr(), v, 1) == 1) 
        {
          referencingExpr = flc.get_expr();
          break;
        }

        if (c.get_kind() == flwor_clause::for_clause &&
            TypeOps::type_max_cnt(*flc.get_expr()->return_type(sctx)) >= 2)
        {
          return false;
        }
      }
    }

		if (referencingExpr == NULL) 
    {
			referencingExpr = flwor.get_return_expr();
		}

		return var_in_try_block_or_in_loop(sctx, v, &*referencingExpr, in_try_block_or_in_loop);
  } 
  else if (e == v) 
  {
    return in_try_block_or_in_loop;
  }

  // Or else navigate down all children
  expr_iterator ei = e->expr_begin();
  while(!ei.done()) 
  {
    if (var_in_try_block_or_in_loop(sctx, v, &*(*ei), in_try_block_or_in_loop)) 
    {
      return true;
    }
    ++ei;
  }
  return false;
}


RULE_REWRITE_PRE(RefactorPredFLWOR) 
{
  flwor_expr* flwor = dynamic_cast<flwor_expr *>(node);

  if (flwor == NULL || flwor->is_general()) 
    return NULL;

  static_context* sctx = rCtx.getStaticContext();

  if_expr* ite_result = dynamic_cast<if_expr*>(flwor->get_return_expr());

  rchandle<const_expr> pos;
  var_expr* pvar;

  expr* whereExpr = flwor->get_where();

  // "for $x in ... return if (ce) then te else ()" --> 
  // "for $x in ... where ce return te"
  if (ite_result != NULL &&
      whereExpr == NULL &&
      TypeOps::is_empty(*ite_result->get_else_expr()->return_type(sctx)))
  {
    expr_t cond = ite_result->get_cond_expr();
    expr_t then = ite_result->get_then_expr();
    flwor->set_return_expr(then);
    flwor->set_where(cond);
    return flwor;
  }
  
  // 'for $x at $p where $p = ... return ...'
  if (whereExpr != NULL &&
      refactor_index_pred(rCtx, whereExpr, pvar, pos) &&
      count_variable_uses(flwor, pvar, 2) <= 1) 
  {
    rchandle<fo_expr> result = new fo_expr (whereExpr->get_cur_sctx(), LOC(whereExpr),
                                            LOOKUP_FN("fn", "subsequence", 3),
                                            pvar->get_for_clause()->get_expr(),
                                            &*pos,
                                            new const_expr(pos->get_cur_sctx(), LOC(pos),
                                                            xqp_double::parseInt(1)));
    fix_annotations(&*result);
    for_clause* clause = pvar->get_for_clause();
    clause->set_expr(&*result);
    clause->set_pos_var(NULL);
    flwor->remove_where_clause();
    return flwor;
  }

  return NULL;
}


/*******************************************************************************

********************************************************************************/
RULE_REWRITE_POST(RefactorPredFLWOR) 
{
  return NULL;
}


/*******************************************************************************
  Checks whether "cond" has the form '$pos_var = ($idx)'
  where $idx would be a proper sequence position.
********************************************************************************/
static bool refactor_index_pred(
    RewriterContext& rCtx,
    const expr* cond,
    var_expr*& pvar,
    rchandle<const_expr>& pos_expr) 
{
  const fo_expr* fo = dynamic_cast<const fo_expr*>(cond);

  if (fo == NULL)
    return false;

  const function* f = fo->get_func();

  if (f != LOOKUP_OP2("equal") && f != LOOKUP_OP2 ("value-equal"))
    return false;

  static_context* sctx = rCtx.getStaticContext();
  TypeManager* tm = sctx->get_typemanager();

  int i;
  for (i = 0; i < 2; i++) 
  {
    if (NULL != (pvar = (*fo)[i].dyn_cast<var_expr>()) &&
        pvar->get_kind() == var_expr::pos_var &&
        NULL != (pos_expr = (*fo)[1 - i].dyn_cast<const_expr>().getp())) 
    {
      store::Item_t val = pos_expr->get_val();

      if (TypeOps::is_subtype(*tm->create_named_type(val->getType()),
                              *GENV_TYPESYSTEM.INTEGER_TYPE_ONE)
          && val->getIntegerValue() >= xqp_integer::parseInt(1)) 
      {
        store::Item_t pVal;
        GenericCast::promote(pVal, val, &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE, *tm);
        pos_expr = new const_expr(pos_expr->get_cur_sctx(), LOC(pos_expr), pVal);
        return true;
      }
    }
  }
  return false;
}


}
/* vim:set ts=2 sw=2: */
