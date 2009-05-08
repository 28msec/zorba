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
#include "types/typeops.h"

#include "functions/function.h"

#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/expression/expr.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "indexing/value_index.h"

namespace zorba 
{

struct PredicateInfo;

static bool isIndexJoinPredicate(RewriterContext&, PredicateInfo&);

static void rewriteJoin(RewriterContext&, PredicateInfo&);

static var_expr* findForVar(RewriterContext&, expr*, int&);

static bool checkVarDependency(RewriterContext&, expr*, int);

static void expandVars(RewriterContext&, expr*, int);

static bool isAndExpr(expr* e);


struct PredicateInfo
{
  flwor_expr * theFlworExpr;
  expr       * thePredicate;
  expr       * theOuterOp;
  var_expr   * theOuterVar;
  int          theOuterVarId;
  expr       * theInnerOp;
  var_expr   * theInnerVar;
};


/*******************************************************************************

********************************************************************************/
expr_t IndexJoin::rewritePre(expr* node, RewriterContext& rCtx)
{
  if (node->get_expr_kind() != flwor_expr_kind) 
    return NULL;

  flwor_expr* flworExpr = static_cast<flwor_expr *>(node);

  rCtx.m_flwor_exprs.push_back(flworExpr);

  expr* whereExpr = flworExpr->get_where();

  if (whereExpr == NULL)
    return NULL;

  PredicateInfo predInfo;
  predInfo.theFlworExpr = flworExpr;
  predInfo.thePredicate = whereExpr;

  if (isIndexJoinPredicate(rCtx, predInfo))
  {
    rewriteJoin(rCtx, predInfo);
    flworExpr->remove_where_clause();
  }
  else if (isAndExpr(whereExpr))
  {
    expr_iterator i = whereExpr->expr_begin();
    for(; !i.done(); ++i) 
    {
      PredicateInfo predInfo;
      predInfo.thePredicate = (*i);

      if (isIndexJoinPredicate(rCtx, predInfo))
      {
        rewriteJoin(rCtx, predInfo);
      }
    }
  }

  return NULL;
}


expr_t IndexJoin::rewritePost(expr* node, RewriterContext& rCtx)
{
  if (node->get_expr_kind() == flwor_expr_kind)
  { 
    expr_t expr = rCtx.m_flwor_exprs[rCtx.m_flwor_exprs.size() - 1];
    rCtx.m_flwor_exprs.resize(rCtx.m_flwor_exprs.size() - 1);

    if (expr->get_expr_kind() == flwor_expr_kind)
      return NULL;
    else
      return expr;
  }

  return NULL;
}


/*******************************************************************************
  Check whether the given predicate is a join predicate that can be conversted 
  to a hashjoin.
********************************************************************************/
static bool isIndexJoinPredicate(RewriterContext& rCtx, PredicateInfo& predInfo)
{
  const fo_expr* foExpr;
  const function* fn;
  const expr* predExpr = predInfo.thePredicate;

  // skip fn:boolean() wrapper
  while (true)
  {
    if (predExpr->get_expr_kind() != fo_expr_kind)
      return false;

    foExpr = static_cast<const fo_expr*>(predExpr);
    fn = foExpr->get_func();

    if (fn == LOOKUP_FN("fn", "boolean", 1))
    {
      predExpr = (*foExpr)[0];
      continue;
    }

    break;
  }

  if (!fn->isValueComparisonFunction())
    return false;

  const expr_t& op1 = (*foExpr)[0];
  const expr_t& op2 = (*foExpr)[1];

  if (rCtx.m_varid_map == NULL)
  {
    rCtx.m_varid_map = new VarIdMap;
    rCtx.m_idvar_map = new IdVarMap;
    rCtx.m_exprvars_map = new ExprVarsMap;

    int numVars = 0;
    index_flwor_vars(rCtx.m_root, numVars, *rCtx.m_varid_map, rCtx.m_idvar_map);

    DynamicBitset freeset(numVars);
    find_flwor_vars(rCtx.m_root, *rCtx.m_varid_map, *rCtx.m_exprvars_map, freeset);
  }

  // Analyze each operand of the eq to see if it depends on a single for
  // variable. If that is not true, we reject this predicate.
  int var1id;
  var_expr* var1 = findForVar(rCtx, op1.getp(), var1id);
  if (var1 == NULL)
    return false;

  int var2id;
  var_expr* var2 = findForVar(rCtx, op2.getp(), var2id);
  if (var2 == NULL)
    return false;

  if (var1 == var2)
    return false;

  // Determine the outer and inner side of the join
  int outerVarId;
  int innerVarId;

  if (var1id < var2id)
  {
    predInfo.theOuterOp = op1.getp();
    predInfo.theOuterVar = var1;
    predInfo.theOuterVarId = var1id;
    predInfo.theInnerOp = op2.getp();
    predInfo.theInnerVar = var2;
    outerVarId = var1id;
    innerVarId = var2id;
  }
  else
  {
    predInfo.theOuterOp = op2.getp();
    predInfo.theOuterVar = var2;
    predInfo.theOuterVarId = var2id;
    predInfo.theInnerOp = op1.getp();
    predInfo.theInnerVar = var1; 
    outerVarId = var2id;
    innerVarId = var1id;
  }

  // The expr that defines the inner var must not depend on the outer var.
  expr* innerDomainExpr = predInfo.theInnerVar->get_for_clause()->get_expr();
  if (checkVarDependency(rCtx, innerDomainExpr, outerVarId))
    return false;

  // The predicate must be in the same flwor that defines the inner var (this
  // way we can be sure that the pred acts as a filter over the inner var).
  if (predInfo.theFlworExpr->defines_variable(predInfo.theInnerVar, NULL) < 0)
    return false;
    
  // Type checks
  xqtref_t outerType = predInfo.theOuterOp->return_type(rCtx.m_sctx);
  xqtref_t innerType = predInfo.theInnerOp->return_type(rCtx.m_sctx);
  xqtref_t primeOuterType = TypeOps::prime_type(*outerType);
  xqtref_t primeInnerType = TypeOps::prime_type(*innerType);
  TypeConstants::quantifier_t outerQuant = TypeOps::quantifier(*outerType);
  TypeConstants::quantifier_t innerQuant = TypeOps::quantifier(*innerType);

  // Normally, other rewrite rules should have added the necessary casting
  // to the eq operands so that their static types have quantifiers ONE
  // or QUESTION and the associated prime types are not xs:untypedAtomic.
  // But just in case those rules have been disabled, we check again here
  // and reject the hashjoin rewrite if these condition are violated.
  if (innerQuant != TypeConstants::QUANT_ONE &&
      innerQuant != TypeConstants::QUANT_QUESTION)
    return false;

  if (outerQuant != TypeConstants::QUANT_ONE &&
      outerQuant != TypeConstants::QUANT_QUESTION)
    return false;

  if (TypeOps::is_equal(*primeOuterType, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    return false;

  if (TypeOps::is_equal(*primeInnerType, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    return false;

  // The type of the outer/inner operands in the join predicate must not be
  // xs:anyAtomic.
  if (TypeOps::is_equal(*primeOuterType, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE) ||
      TypeOps::is_equal(*primeInnerType, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE))
    return false;

  // The type of the outer operand in the join predicate must be a subtype
  // of the inner operand.
  if (!TypeOps::is_subtype(*outerType, *innerType))
    return false;

  return true;
}


/*******************************************************************************

********************************************************************************/
static void rewriteJoin(RewriterContext& rCtx, PredicateInfo& predInfo)
{
  std::cout << "!!!!! Found Join Index Predicate !!!!!" << std::endl << std::endl;

  const QueryLoc& loc = predInfo.thePredicate->get_loc();

  for_clause* fc = predInfo.theInnerVar->get_for_clause();

  // The index domain expr is the expr that defines the inner var, expanded so that
  // it does not reference any variables defined after the outer var.
  expr* domainExpr = fc->get_expr();
  expandVars(rCtx, domainExpr, predInfo.theOuterVarId);

  //
  // Create the ValueIndex obj
  //
  std::ostringstream os;
  os << rCtx.m_tempIndexCounter++;

  xqpString uri("tempIndex" + os.str());

  ValueIndex_t idx = new ValueIndex(rCtx.m_sctx, uri.getStore());

  idx->setDomainExpression(domainExpr);

  idx->setDomainVariable(rCtx.createTempVar(loc, var_expr::for_var));

  idx->setDomainPositionVariable(rCtx.createTempVar(loc, var_expr::pos_var));

  idx->setTemp(true);

  std::vector<expr_t> columnExprs(1);
  std::vector<xqtref_t> columnTypes(1);
  std::vector<std::string> collations(1);

  columnExprs[0] = predInfo.theInnerOp;
  columnTypes[0] = predInfo.theInnerOp->return_type(rCtx.m_sctx);
  collations[0] = rCtx.m_sctx->default_collation_uri().c_str();

  replace_var(columnExprs[0], predInfo.theInnerVar, idx->getDomainVariable());

  idx->setIndexFieldExpressions(columnExprs);

  idx->setIndexFieldTypes(columnTypes);

  idx->setIndexFieldCollations(collations);

  rCtx.m_sctx->bind_index(uri, idx.getp());

  //
  // Find the flwor expr defining the outer var
  //
  flwor_expr* outerFlworExpr = NULL;
  expr_t outerSeqExpr;
  long outerExprPos = -1;

  for (long i = rCtx.m_flwor_exprs.size() - 1; i >= 0; --i)
  {
    if (rCtx.m_flwor_exprs[i]->get_expr_kind() == flwor_expr_kind)
    {
      outerFlworExpr = reinterpret_cast<flwor_expr*>(rCtx.m_flwor_exprs[i].getp());
    }
    else
    {
      assert(rCtx.m_flwor_exprs[i]->get_expr_kind() == fo_expr_kind);

      outerSeqExpr = rCtx.m_flwor_exprs[i];
      expr_iterator exprIter = outerSeqExpr->expr_begin();
      while (!exprIter.done())
      {
        if ((*exprIter)->get_expr_kind() == flwor_expr_kind)
        {
          outerFlworExpr = reinterpret_cast<flwor_expr*>((*exprIter).getp());
          break;
        }
      }
    }

    assert(outerFlworExpr != NULL);

    if (outerFlworExpr->defines_variable(predInfo.theOuterVar, NULL) >= 0)
    {
      outerExprPos = i;
      break;
    }

    outerFlworExpr = NULL;
    outerSeqExpr = NULL;
  }

  assert(outerFlworExpr != NULL);

  //
  // create the "create index", "build index", and "drop index" exprs
  //
  store::Item_t uri_item;
  GENV_ITEMFACTORY->createAnyURI(uri_item, uri.c_str());
  expr_t uriExpr(new const_expr(loc, uri_item));

  rchandle<fo_expr> createExpr;
  rchandle<fo_expr> buildExpr;

  createExpr = new fo_expr(loc, LOOKUP_RESOLVED_FN(ZORBA_OPEXTENSIONS_NS,
                                                   "create-index",
                                                   1));
  createExpr->add(uriExpr);

  buildExpr = new fo_expr(loc, LOOKUP_RESOLVED_FN(ZORBA_OPEXTENSIONS_NS,
                                                  "build-index",
                                                  1));
  buildExpr->add(uriExpr);

  //
  //  Build or adjust outer sequential expr 
  //
  if (outerSeqExpr == NULL)
  {
    sequential_expr* seqExpr = new sequential_expr(loc);
    
    seqExpr->push_back(createExpr.getp());
    seqExpr->push_back(buildExpr.getp());
    seqExpr->push_back(outerFlworExpr);

    outerSeqExpr = seqExpr;
    assert(outerExprPos >= 0);
    rCtx.m_flwor_exprs[outerExprPos] = outerSeqExpr;
  }
  else
  {
    sequential_expr* seqExpr = reinterpret_cast<sequential_expr*>(outerSeqExpr.getp());

    seqExpr->push_front(createExpr.getp());
    seqExpr->push_front(buildExpr.getp());
  }

  //
  // Replace the expr defining the inner var with an index probe.
  //
  rchandle<fo_expr> probeExpr;
  probeExpr = new fo_expr(loc, LOOKUP_RESOLVED_FN(ZORBA_OPEXTENSIONS_NS,
                                                  "probe-index-point",
                                                  VARIADIC_SIG_SIZE));
  probeExpr->add(uriExpr);
  probeExpr->add(predInfo.theOuterOp);

  fc->set_expr(probeExpr.getp());
}


/*******************************************************************************

********************************************************************************/
static var_expr* findForVar(RewriterContext& rCtx, expr* curExpr, int& varid)
{
  var_expr* var = NULL;

  while (true)
  {
    std::vector<int> varidSet;

    const DynamicBitset& bitset = (*rCtx.m_exprvars_map)[curExpr];

    bitset.getSet(varidSet);

    if (varidSet.size() != 1)
      return NULL;

    varid = varidSet[0];
    var = (*rCtx.m_idvar_map)[varid];

    if (var->get_kind() == var_expr::for_var)
    {
      break;
    }
    else if (var->get_kind() == var_expr::let_var)
    {
      curExpr = var->get_forletwin_clause()->get_expr();
    }
    else 
    {
      return NULL;
    }
  }

  return var;
}

/*******************************************************************************

********************************************************************************/
static bool checkVarDependency(
    RewriterContext& rCtx,
    expr* curExpr,
    int searchVarId)
{
  const DynamicBitset& bitset = (*rCtx.m_exprvars_map)[curExpr];

  if (bitset.get(searchVarId))
    return true;

  std::vector<int> varidSet;
  bitset.getSet(varidSet);

  ulong numVars = varidSet.size();
  for (ulong i = 0; i < numVars; ++i)
  {
    var_expr* var = (*rCtx.m_idvar_map)[varidSet[i]];
    curExpr = var->get_forletwin_clause()->get_expr();

    if (checkVarDependency(rCtx, curExpr, searchVarId))
      return true;
  }

  return false;
}



/*******************************************************************************

********************************************************************************/
static void expandVars(
    RewriterContext& rCtx,
    expr* subExpr,
    int outerVarId)
{
  if (subExpr->get_expr_kind() == wrapper_expr_kind)
  {
    wrapper_expr* wrapper = reinterpret_cast<wrapper_expr*>(subExpr);

    if (wrapper->get_expr()->get_expr_kind() == var_expr_kind)
    {
      var_expr* var = reinterpret_cast<var_expr*>(wrapper->get_expr().getp());
      int varid = (*rCtx.m_varid_map)[var];

      if (varid > outerVarId)
      {
        wrapper->set_expr(var->get_forletwin_clause()->get_expr());
        expandVars(rCtx, wrapper->get_expr(), outerVarId);
        return;
      }
    }
  }
  
  expr_iterator iter = subExpr->expr_begin();
  while (!iter.done())
  {
    expandVars(rCtx, *iter, outerVarId);
    ++iter;
  }

}


/*******************************************************************************

********************************************************************************/
static bool isAndExpr(expr* e)
{
  if (e->get_expr_kind() != fo_expr_kind)
    return false;

  const function* fn = static_cast<fo_expr *>(e)->get_func();
  return (fn == LOOKUP_OP2("and"));
}


}

/* vim:set ts=2 sw=2: */
