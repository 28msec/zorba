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

#include "compiler/api/compilercb.h"
#include "compiler/rewriter/rules/index_join_rule.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/script_exprs.h"
#include "compiler/expression/expr.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/xqddf/value_index.h"
#include "compiler/expression/expr_iter.h"

#include "functions/function.h"
#include "functions/library.h"

#include "types/typeops.h"

#include "system/properties.h"

#include "diagnostics/assert.h"


namespace zorba
{

struct PredicateInfo
{
  flwor_expr  * theFlworExpr;
  csize         theWherePos;
  expr        * thePredicate;

  expr        * theOuterOp;
  var_expr    * theOuterVar;
  csize         theOuterVarId;

  expr        * theInnerOp;
  var_expr    * theInnerVar;
  csize         theInnerVarId;

  bool          theIsGeneral;

  csize         theStackPos;
  csize         theChildPos;
};


/*******************************************************************************

********************************************************************************/
IndexJoinRule::IndexJoinRule(RewriterContext* rctx)
  :
  RewriteRule(RewriteRule::IndexJoin, "IndexJoin"),
  theRCtx(rctx),
  theRootExpr(rctx->getRoot())
{
  theVarIdMap = new expr_tools::VarIdMap;
  theIdVarMap = new expr_tools::IdVarMap;
  theExprVarsMap = new expr_tools::ExprVarsMap;

  theIdVarMap->reserve(32);
  theIdVarMap->push_back(0); // because varids are starting from 1

  csize numVars = 0;
  expr_tools::index_flwor_vars(theRootExpr, numVars, *theVarIdMap, theIdVarMap);

  DynamicBitset freeset(numVars+1);
  expr_tools::build_expr_to_vars_map(theRootExpr,
                                     *theVarIdMap,
                                     freeset,
                                     *theExprVarsMap);
}


/*******************************************************************************

********************************************************************************/
IndexJoinRule::~IndexJoinRule()
{
  assert(theVarDefExprs.empty());
  assert(theChildPositions.empty());

  delete theVarIdMap;
  delete theIdVarMap;
  delete theExprVarsMap;
}


/*******************************************************************************
  This rule analyzes the where clauses of flwor exprs to deterimne whether any
  predicate in a clause is a join predicate and whether the associated join
  can be converted into a hashjoin using an index that is built on-the-fly.
********************************************************************************/
expr* IndexJoinRule::apply(RewriterContext& rCtx, expr* node, bool& modified)
{
  assert(node != theRootExpr || theVarDefExprs.empty());
  assert(node != theRootExpr || theChildPositions.empty());

  flwor_expr* flworExpr = NULL;

  expr_kind_t nodeKind = node->get_expr_kind();

  if (nodeKind == flwor_expr_kind || nodeKind == gflwor_expr_kind)
  {
    flworExpr = static_cast<flwor_expr *>(node);

    // Push the flwor expr into the stack
    theVarDefExprs.push_back(flworExpr);
    theChildPositions.push_back(0);

    csize numClauses = flworExpr->num_clauses();
    for (csize i = 0; i < numClauses; ++i)
    {
      flwor_clause* c = flworExpr->get_clause(i);

      if (c->get_kind() != flwor_clause::where_clause)
        continue;

      const where_clause* wc = static_cast<const where_clause *>(c);
      expr* whereExpr = wc->get_expr();

      PredicateInfo predInfo;
      predInfo.theFlworExpr = flworExpr;
      predInfo.theWherePos = i;
      predInfo.thePredicate = whereExpr;

      if (isIndexJoinPredicate(predInfo))
      {
        rewriteJoin(predInfo);
        modified = true;

        predInfo.theFlworExpr->remove_clause(c, i);

        expr* e = theVarDefExprs.back();

        ZORBA_ASSERT(e == node || e->get_expr_kind() == block_expr_kind);
          
        theVarDefExprs.pop_back();
        theChildPositions.pop_back();
        return e;
      }
      else if (whereExpr->get_function_kind() == FunctionConsts::OP_AND_N)
      {
        // TODO: consider multi-key indices
        ExprIterator iter(whereExpr);
        while (!iter.done())
        {
          PredicateInfo predInfo;
          predInfo.theFlworExpr = flworExpr;
          predInfo.theWherePos = i;
          predInfo.thePredicate = (**iter);
          
          if (isIndexJoinPredicate(predInfo))
          {
            rewriteJoin(predInfo);
            
            modified = true;

            // TODO: just remove the pred instead of replacing it with true.
            expr* trueExpr = rCtx.theEM->
            create_const_expr(flworExpr->get_sctx(),
                              flworExpr->get_udf(),
                              flworExpr->get_loc(),
                              true);
            (**iter) = trueExpr;
              
            expr* e = theVarDefExprs.back();
              
            ZORBA_ASSERT(e == node || e->get_expr_kind() == block_expr_kind);
              
            theVarDefExprs.pop_back();
            theChildPositions.pop_back();
            return e;
          }

          iter.next();
        }
      }
    }
  }

  // No index-join rewrite done, so drill down.

  if (nodeKind == flwor_expr_kind || nodeKind == gflwor_expr_kind)
  {
    csize numClauses = flworExpr->num_clauses();
    csize clausePos = 0;
    csize numClauseChildren;

    ExprIterator iter(node);
    while (!iter.done() && !modified)
    {
      theChildPositions.back() = clausePos;

      if (clausePos == numClauses)
      {
        numClauseChildren = 1;
      }
      else
      {
        flwor_clause* c = flworExpr->get_clause(clausePos);

        switch (c->get_kind())
        {
        case flwor_clause::for_clause:
        case flwor_clause::let_clause:
        case flwor_clause::where_clause:
        {
          numClauseChildren = 1;
          break;
        }
        case flwor_clause::window_clause:
        {
          window_clause* wc = static_cast<window_clause *>(c);
          numClauseChildren = 1;
          if (wc->get_win_start()) ++numClauseChildren;
          if (wc->get_win_stop()) ++numClauseChildren;
          break;
        }
        case flwor_clause::groupby_clause:
        {
          groupby_clause* gc = static_cast<groupby_clause *>(c);
          numClauseChildren = gc->numGroupingVars() + gc->numNonGroupingVars();
          break;
        }
        case flwor_clause::orderby_clause:
        {
          orderby_clause* oc = static_cast<orderby_clause *>(c);
          numClauseChildren = oc->num_columns();
          break;
        }
        case flwor_clause::count_clause:
        case flwor_clause::materialize_clause:
        {
          numClauseChildren = 0;
          break;
        }
        default:
          ZORBA_ASSERT(false);
        }
      }

      for (csize j = 0; j < numClauseChildren; ++j)
      {
        expr* currChild = **iter;
        expr* newChild = apply(rCtx, currChild, modified);
        
        if (currChild != newChild)
        {
          assert(modified);
          **iter = newChild;
        }
        
        if (modified)
          break;

        iter.next();
      }

      ++clausePos;
    }

    // drill out
    expr* e = theVarDefExprs.back();

    ZORBA_ASSERT(e == node || e->get_expr_kind() == block_expr_kind);

    theVarDefExprs.pop_back();
    theChildPositions.pop_back();
    return e;
  }
  else if (nodeKind == trycatch_expr_kind)
  {
    // drill in
    theVarDefExprs.push_back(node);
    theChildPositions.push_back(0);

    ExprIterator iter(node);
    while (!iter.done())
    {
      expr* currChild = **iter;
      expr* newChild = apply(rCtx, currChild, modified);

      if (currChild != newChild)
      {
        assert(modified);
        **iter = newChild;
      }
      
      if (modified)
        break;

      iter.next();
    }

    // drill out
    theVarDefExprs.pop_back();
    theChildPositions.pop_back();

    return node;
  }
  else if (nodeKind == block_expr_kind)
  {
    // drill in
    theVarDefExprs.push_back(node);
    theChildPositions.push_back(0);

    block_expr* block = static_cast<block_expr*>(node);
    csize numArgs = block->size();
    for (csize i = 0; i < numArgs; ++i)
    {
      theChildPositions.back() = i;

      expr* currChild = (*block)[i];
      expr* newChild = apply(rCtx, currChild, modified);
      ZORBA_ASSERT(currChild == newChild);

      if (modified)
        break;
    }

    // drill out
    ZORBA_ASSERT(theVarDefExprs.back() == node);
    theVarDefExprs.pop_back();
    theChildPositions.pop_back();

    return node;
  }
  else
  {
    ExprIterator iter(node);
    while (!iter.done())
    {
      expr* currChild = **iter;
      expr* newChild = apply(rCtx, currChild, modified);

      if (currChild != newChild)
      {
        assert(modified);
        **iter = newChild;
      }
      
      if (modified)
        break;

      iter.next();
    }

    return node;
  }
}


/*******************************************************************************
  Check whether the given predicate is a join predicate that can be converted
  to a hashjoin.
********************************************************************************/
bool IndexJoinRule::isIndexJoinPredicate(PredicateInfo& predInfo)
{
  const fo_expr* foExpr = NULL;
  const function* fn;
  const expr* predExpr = predInfo.thePredicate;

  // skip fn:boolean() wrapper
  while (true)
  {
    if (predExpr->get_expr_kind() != fo_expr_kind)
      return false;

    foExpr = static_cast<const fo_expr*>(predExpr);
    fn = foExpr->get_func();

    if (fn->getKind() == FunctionConsts::FN_BOOLEAN_1)
    {
      predExpr = foExpr->get_arg(0);
      continue;
    }

    break;
  }

  CompareConsts::CompareType opKind = fn->comparisonKind();

  if (opKind != CompareConsts::VALUE_EQUAL && opKind != CompareConsts::GENERAL_EQUAL)
    return false;

  predInfo.theIsGeneral = (opKind == CompareConsts::GENERAL_EQUAL);

  expr* op1 = foExpr->get_arg(0);
  expr* op2 = foExpr->get_arg(1);

  // Analyze each operand of the eq to see if it depends on a single LOOP
  // variable. If that is not true, we reject this predicate.
  csize var1id;
  var_expr* var1 = findLoopVar(op1, var1id);
  if (var1 == NULL)
    return false;

  csize var2id;
  var_expr* var2 = findLoopVar(op2, var2id);
  if (var2 == NULL)
    return false;

  if (var1 == var2)
    return false;

  // Determine the outer and inner side of the join
  if (var1id < var2id)
  {
    predInfo.theOuterOp = op1;
    predInfo.theOuterVar = var1;
    predInfo.theOuterVarId = var1id;
    predInfo.theInnerOp = op2;
    predInfo.theInnerVar = var2;
    predInfo.theInnerVarId = var2id;
  }
  else
  {
    predInfo.theOuterOp = op2;
    predInfo.theOuterVar = var2;
    predInfo.theOuterVarId = var2id;
    predInfo.theInnerOp = op1;
    predInfo.theInnerVar = var1;
    predInfo.theInnerVarId = var1id;
  }

  static_context* sctx = predExpr->get_sctx();
  TypeManager* tm = sctx->get_typemanager();
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  // Make sure we don't have a pred between two groupby vars 
  if (predInfo.theInnerVar->get_kind() != var_expr::for_var)
    return false;

  forlet_clause* innerVarClause = predInfo.theInnerVar->get_forlet_clause();

  // The inner var must not be an outer FOR var
  if (innerVarClause->is_allowing_empty())
    return false;

  // The predicate must be in the same flwor that defines the inner var (this
  // way we can be sure that the pred acts as a filter over the inner var).
  if (!predInfo.theFlworExpr->defines_var(predInfo.theInnerVar))
    return false;

  // There should be no COUNT clause and no sequential clauses between the
  // WHERE clause and the inner var clause.
  for (csize i = predInfo.theWherePos; i > 0; --i)
  {
    flwor_clause* c = predInfo.theFlworExpr->get_clause(i-1);

    switch (c->get_kind())
    {
    case flwor_clause::for_clause:
    case flwor_clause::let_clause:
    case flwor_clause::window_clause:
    {
      forletwin_clause* flwc = static_cast<forletwin_clause*>(c);
      if (flwc->get_expr()->is_sequential())
        return false;

      break;
    }
    case flwor_clause::count_clause:
    {
      return false;
    }
    case flwor_clause::orderby_clause:
    case flwor_clause::where_clause:
    {
      break;
    }
    case flwor_clause::groupby_clause:
    case flwor_clause::materialize_clause:
    default:
    {
      ZORBA_ASSERT(false);
    }
    }
    
    if (c == innerVarClause)
      break;
  }

  // Let OV be the outer LOOP var and BV be the inner-most non-LET variable that
  // the index expression depends on. The index must be created somewhere between
  // BV anmd OV. The checkVarDeps method finds BV and checks that BV is defined
  // before OV.
  expr* innerDomainExpr = innerVarClause->get_expr();
  csize boundaryVarId = 0;
  if (checkVarDeps(innerDomainExpr, predInfo.theOuterVarId, boundaryVarId))
    return false;

  // Check whether it is possible to place the index creation somewhere between
  // BV and OV, and if so, determine the exact location.
  if (!findIndexPos(predInfo, boundaryVarId))
    return false;

  // Type checks
  xqtref_t outerType = predInfo.theOuterOp->get_return_type();
  xqtref_t innerType = predInfo.theInnerOp->get_return_type();
  xqtref_t primeOuterType = TypeOps::prime_type(tm, *outerType);
  xqtref_t primeInnerType = TypeOps::prime_type(tm, *innerType);
  TypeConstants::quantifier_t outerQuant = outerType->get_quantifier();
  TypeConstants::quantifier_t innerQuant = innerType->get_quantifier();
  const QueryLoc& innerLoc = predInfo.theInnerOp->get_loc();
  const QueryLoc& outerLoc = predInfo.theOuterOp->get_loc();

  if (!predInfo.theIsGeneral)
  {
    // Normally, other rewrite rules should have added the necessary casting
    // to the eq operands so that their static types have quantifiers ONE
    // or QUESTION. But just in case those rules have been disabled, we
    // check again here and reject the hashjoin rewrite if these conditions
    // are violated.

    if (innerQuant != TypeConstants::QUANT_ONE &&
        innerQuant != TypeConstants::QUANT_QUESTION)
      return false;

    if (outerQuant != TypeConstants::QUANT_ONE &&
        outerQuant != TypeConstants::QUANT_QUESTION)
      return false;

    // The type of the inner operand in the join predicate must not be
    // xs:anyAtomic.
    if (TypeOps::is_equal(tm, *primeInnerType, *rtm.ANY_ATOMIC_TYPE_ONE, innerLoc))
      return false;

    // The prime type of the outer operand in the join predicate must be a
    // subtype of the prime type of the inner operand.
    if (!TypeOps::is_subtype(tm, *primeOuterType, *primeInnerType, outerLoc))
      return false;
  }
  else
  {
    // TODO: allow domain exprs that return atomic items?
    if (! TypeOps::is_subtype(tm,
                              *innerDomainExpr->get_return_type(),
                              *rtm.ANY_NODE_TYPE_STAR,
                              innerDomainExpr->get_loc()))
      return false;

    if (innerDomainExpr->getProducesDistinctNodes() != ANNOTATION_TRUE &&
        innerDomainExpr->getProducesDistinctNodes() != ANNOTATION_TRUE_FIXED)
      return false;
  }

  return true;
}


/*******************************************************************************
  Check if "curExpr" references a single var and that var is a LOOP var, i.e.,
  a GROUPBY var or a FOR var whose domain expr has a max cardinality > 1. If so,
  return that LOOP var and its prefix id; otherwise return NULL. If "curExpr"
  references a single LET var, the check is applied recurdively to the domain
  expr of the LET var.

  TODO: it is possible to relax the conditions to allow curExpr to reference
  a single LOOP var plus local/global vars. But then we must make sure we
  don't cross these additional var when we look for the place where to put the
  index creation.  
********************************************************************************/
var_expr* IndexJoinRule::findLoopVar(expr* curExpr, csize& varid)
{
  var_expr* var = NULL;

  while (true)
  {
    std::vector<csize> varidSet;

    const DynamicBitset& bitset = (*theExprVarsMap)[curExpr];

    bitset.getSet(varidSet);

    if (varidSet.size() != 1)
      return NULL;

    varid = varidSet[0];
    var = (*theIdVarMap)[varid];
    var_expr::var_kind vkind = var->get_kind();

    if (vkind == var_expr::for_var)
    {
      curExpr = var->get_domain_expr();

      xqtref_t domainType = curExpr->get_return_type();
      TypeConstants::quantifier_t quant = domainType->get_quantifier();

      if (quant == TypeConstants::QUANT_STAR || quant == TypeConstants::QUANT_PLUS)
      {
        return var;
      }
      else if (quant == TypeConstants::QUANT_ONE)
      {
        // this FOR var is equivalent to a LET var, so we drill into its
        // domain expr
        continue;
      }
      else
      {
        return false;
      }
    }
    else if (vkind == var_expr::groupby_var)
    {
      return var;
    }
    else if (vkind == var_expr::let_var)
    {
      curExpr = var->get_domain_expr();
    }
    else
    {
      return NULL;
    }
  }

  return var;
}


/*******************************************************************************
  Return true iff "idxExpr" references the outer loop var OV or any other var
  that is defined after OV. Also find and return the id of the "boundary" var
  BV that is the inner-most variable that the indExp depends on.

  NOTE: for the purposes of this method, LET vars are "transparent", i.e., the
  method is applied recursively on the domain expr of each LET var that is
  referenced by idxExpr. 
********************************************************************************/
bool IndexJoinRule::checkVarDeps(
    expr* idxExpr,
    csize outerVarId,
    csize& boundVarId)
{
  const DynamicBitset& bitset = (*theExprVarsMap)[idxExpr];

  csize numVars = bitset.size();
  for (csize varid = 0; varid < numVars; ++varid)
  {
    if (!bitset.get(varid))
      continue;

    if (varid >= outerVarId)
    {
      if (varid == outerVarId)
        return true;

      const var_expr* var = (*theIdVarMap)[varid];

      if (var->get_kind() == var_expr::let_var)
      {
        expr* domExpr = var->get_forlet_clause()->get_expr();
        if (checkVarDeps(domExpr, outerVarId, boundVarId))
          return true;
      }
      else
      {
        return true;
      }
    }
    else if (varid > boundVarId)
    {
      boundVarId = varid;
    }
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
bool IndexJoinRule::findIndexPos(PredicateInfo& predInfo, csize boundVarId)
{
  csize numStackedExprs = theVarDefExprs.size();

  //
  // Find the position of the outer loop var
  //
  var_expr* outerVar = predInfo.theOuterVar;
  flwor_expr* outerFlwor = outerVar->get_flwor_clause()->get_flwor_expr();
  csize outerStackPos = numStackedExprs;
  csize outerVarPos; 

  bool found = outerFlwor->get_var_pos(outerVar, outerVarPos);
  ZORBA_ASSERT(found);

  for (csize i = 0; i < numStackedExprs; ++i)
  {
    if (theVarDefExprs[i] == outerFlwor)
    {
      outerStackPos = i;
      break;
    }
  }

  assert(outerStackPos < numStackedExprs);

  //
  // Find the position of the inner loop var
  //
  var_expr* innerVar = predInfo.theInnerVar;
  flwor_expr* innerFlwor = innerVar->get_flwor_clause()->get_flwor_expr();
  csize innerStackPos = numStackedExprs - 1;
  csize innerVarPos; 

  found = innerFlwor->get_var_pos(innerVar, innerVarPos);
  ZORBA_ASSERT(found);

  //
  // Make sure that there are no sequential clauses/exprs and no trycatch exprs
  // in the path between the inner and the outer loop vars.
  //
  theChildPositions[numStackedExprs-1] = innerVarPos;

  for (csize i = outerStackPos; i <= innerStackPos; ++i)
  {
    expr* currExpr = theVarDefExprs[i];
    expr_kind_t currKind = currExpr->get_expr_kind();

    if (currKind == flwor_expr_kind || currKind == gflwor_expr_kind)
    {
      flwor_expr* flwor = static_cast<flwor_expr*>(currExpr);
      csize numClauses = flwor->num_clauses();
      csize startClause;
      csize stopClause;
      bool checkReturn = false;

      if (outerStackPos == innerStackPos)
      {
        startClause = outerVarPos;
        stopClause = innerVarPos;
      }
      else if (i == outerStackPos)
      {
        startClause = outerVarPos;
        stopClause = numClauses - 1;
        checkReturn = true;
      }
      else
      {
        startClause = 0;
        stopClause = theChildPositions[i];
        if (stopClause == numClauses)
        {
          --stopClause;
          checkReturn = true;
        }
      }

      for (csize j = startClause; j <= stopClause; ++j)
      {
        flwor_clause* c = flwor->get_clause(j);

        switch (c->get_kind())
        {
        case flwor_clause::for_clause:
        case flwor_clause::let_clause:
        case flwor_clause::window_clause:
        {
          forletwin_clause* flwc = static_cast<forletwin_clause*>(c);

          if (flwc->get_expr()->is_sequential())
            return false;

          break;
        }
        default:
          break;
        }
      }

      if (checkReturn && flwor->get_return_expr()->is_sequential())
        return false;
    }
    else if (currKind == trycatch_expr_kind)
    {
      return false;
    }
    else if (currKind == block_expr_kind)
    {
      block_expr* block = static_cast<block_expr*>(currExpr);

      for (csize j = 0; j <= theChildPositions[i]; ++j)
      {
        if ((*block)[j]->is_sequential())
          return false;
      } 
    }
  }

  //
  // Find the position of the boundary var
  //
  var_expr* boundVar = NULL; 
  expr* boundExpr;
  csize boundStackPos;
  csize boundVarPos; 

  if (boundVarId == 0)
  {
    boundStackPos = 0;
    boundVarPos = 0;
  }
  else
  {
    boundVar = (*theIdVarMap)[boundVarId];
    ZORBA_ASSERT(boundVar);

    if (boundVar->get_kind() == var_expr::catch_var)
    {
      // Not worth bothering about index exprs accessing catch vars
      return false; 
    }
    else if (boundVar->get_kind() == var_expr::prolog_var ||
             boundVar->get_kind() == var_expr::local_var)
    {
      block_expr* blockExpr = boundVar->get_block_expr();
      ZORBA_ASSERT(blockExpr);
      boundExpr = blockExpr;

      found = blockExpr->get_var_pos(boundVar, boundVarPos);
      ZORBA_ASSERT(found);
    }
    else
    {
      flwor_clause* boundClause = boundVar->get_flwor_clause();
      ZORBA_ASSERT(boundClause);
      flwor_expr* boundFlwor = boundClause->get_flwor_expr();
      boundExpr = boundFlwor;
      
      found = boundFlwor->get_var_pos(boundVar, boundVarPos);
      ZORBA_ASSERT(found);
    }
    
    for (csize i = 0; i < numStackedExprs; ++i)
    {
      if (theVarDefExprs[i] == boundExpr)
      {
        boundStackPos = i;
        break;
      }
    }
  }

  ZORBA_ASSERT(boundStackPos < numStackedExprs);

  //
  // Try to place the index creation as early as possible, but without crossing
  // any sequential expr or trycatch expr or the definition of the boundary var.
  //
  theChildPositions[outerStackPos] = outerVarPos;

  for (csize i = outerStackPos; i >= boundStackPos; --i)
  {
    expr* currExpr = theVarDefExprs[i];
    expr_kind_t currKind = currExpr->get_expr_kind();

    if (currKind == flwor_expr_kind || currKind == gflwor_expr_kind)
    {
      flwor_expr* flwor = static_cast<flwor_expr*>(currExpr);
      csize numClauses = flwor->num_clauses();
      csize stopClause = 0;
      csize startClause = theChildPositions[i];
      bool checkReturn = false;

      if (startClause == numClauses)
      {
        checkReturn = true;
        --startClause;
      }

      if (checkReturn && flwor->get_return_expr()->is_sequential())
      {
        predInfo.theStackPos = i+1;
        predInfo.theChildPos = 0;
        return true;
      }

      for (csize j = startClause+1; j > stopClause; --j)
      {
        if (i == boundStackPos && j-1 == boundVarPos)
        {
          predInfo.theStackPos = i;
          predInfo.theChildPos = (boundVarId == 0 ? j-1 : j);
          return true;
        }

        flwor_clause* c = flwor->get_clause(j-1);

        switch (c->get_kind())
        {
        case flwor_clause::for_clause:
        case flwor_clause::let_clause:
        case flwor_clause::window_clause:
        {
          forletwin_clause* flwc = static_cast<forletwin_clause*>(c);

          if (flwc->get_expr()->is_sequential())
          {
            predInfo.theStackPos = i;
            predInfo.theChildPos = j;
            return true;
          }
          break;
        }
        default:
          break;
        }
      }
    }
    else if (currKind == trycatch_expr_kind)
    {
      predInfo.theStackPos = i+1;
      predInfo.theChildPos = 0;
      return true;
    }
    else if (currKind == block_expr_kind)
    {
      block_expr* block = static_cast<block_expr*>(currExpr);
      csize stopArg = 0;
      csize startArg = theChildPositions[i];

      for (csize j = startArg+1; j > stopArg; --j)
      {
        csize arg = j-1;

        if ((*block)[arg]->is_sequential() ||
            (i == boundStackPos && arg == boundVarPos))
        {
          predInfo.theStackPos = i;
          predInfo.theChildPos = j;
          return true;
        }
      }
    }

    if (i == 0)
      break;
  }

  predInfo.theStackPos = 0;
  predInfo.theChildPos = 0;
  return true;
}


/*******************************************************************************

********************************************************************************/
void IndexJoinRule::rewriteJoin(PredicateInfo& predInfo)
{
  CompilerCB* ccb = theRootExpr->get_ccb();
  ExprManager* em = ccb->getExprManager();
  static_context* sctx = predInfo.thePredicate->get_sctx();
  user_function* udf = predInfo.thePredicate->get_udf();
  const QueryLoc& loc = predInfo.theInnerVar->get_loc();

  for_clause* innerClause = predInfo.theInnerVar->get_forlet_clause();

  //
  // The index domain expr is the expr that defines the inner var, expanded so
  // that it does not reference any LET variables defined after the outer var
  // 
  expr* indexDomainExpr = innerClause->get_expr();
  expandVars(indexDomainExpr, predInfo.theOuterVarId, predInfo.theInnerVarId);

  //
  // Create the index declaration
  //
  std::ostringstream os;
  os << "tempIndex" << ccb->theTempIndexCounter++;

  store::Item_t qname;
  GENV_ITEMFACTORY->createQName(qname, "", "", os.str().c_str());

  IndexDecl_t idx = new IndexDecl(sctx, ccb, loc, qname);

  if (predInfo.theIsGeneral)
    idx->setGeneral(true);

  idx->setTemp(true);

  idx->setDomainExpr(indexDomainExpr);

  idx->setDomainVariable(theRCtx->createTempVar(sctx, loc, var_expr::for_var));

  idx->setDomainPositionVariable(theRCtx->createTempVar(sctx, loc, var_expr::pos_var));

  std::vector<expr*> columnExprs(1);
  std::vector<xqtref_t> columnTypes(1);
  std::vector<OrderModifier> modifiers(1);

  columnExprs[0] = predInfo.theInnerOp;

  columnTypes[0] = (predInfo.theIsGeneral ?
                    NULL :
                    predInfo.theInnerOp->get_return_type());

  modifiers[0].theAscending = true;
  modifiers[0].theEmptyLeast = true;
  modifiers[0].theCollation = sctx->get_default_collation(QueryLoc::null);

  expr_tools::replace_var(columnExprs[0], predInfo.theInnerVar, idx->getDomainVariable());

  idx->setKeyExpressions(columnExprs);

  idx->setKeyTypes(columnTypes);

  idx->setOrderModifiers(modifiers);

  //
  // Create the "create-index()" expr
  //
  expr* qnameExpr = em->create_const_expr(sctx, udf, loc, qname);

  expr* buildExpr = idx->getBuildExpr(loc);

  function* f = BUILTIN_FUNC(OP_CREATE_INTERNAL_INDEX_2);
  fo_expr* createExpr = em->create_fo_expr(sctx, udf, loc, f, qnameExpr, buildExpr);

  DynamicBitset indexVars;
  expr_tools::build_expr_to_vars_map(createExpr,
                                     *theVarIdMap,
                                     indexVars, 
                                     *theExprVarsMap);

  //
  // Place the create-index expr to its target position
  //
  expr* targetExpr = theVarDefExprs[predInfo.theStackPos];
  csize targetPos = predInfo.theChildPos;
  expr_kind_t targetKind = targetExpr->get_expr_kind();

  if (targetKind == block_expr_kind)
  {
    block_expr* block = static_cast<block_expr*>(targetExpr);

    block->add(targetPos, createExpr);
  }
  else if (targetKind == flwor_expr_kind || targetKind == gflwor_expr_kind)
  {
    flwor_expr* flwor = static_cast<flwor_expr*>(targetExpr);
    csize numClauses = flwor->num_clauses();

    if (targetPos == numClauses)
    {
      std::vector<expr*> args(2);
      args[0] = createExpr;
      args[1] = flwor->get_return_expr();

      block_expr* block = em->create_block_expr(sctx, udf, loc, false, args, NULL);

      DynamicBitset blockVars = indexVars;
      blockVars.set_union((*theExprVarsMap)[flwor->get_return_expr()]);
      (*theExprVarsMap)[block] = blockVars;

      flwor->set_return_expr(block);
    }
    else
    {
      var_expr* dummyVar = theRCtx->createTempVar(sctx, loc, var_expr::let_var);

      let_clause* createClause = 
      em->create_let_clause(sctx, loc, dummyVar, createExpr, false);

      flwor->add_clause(targetPos, createClause);
    }
  }
  else
  {
    ZORBA_ASSERT(false);
  }

  //
  // Replace the expr defining the inner var with an index probe.
  //
  fo_expr* probeExpr = NULL;

  if (predInfo.theIsGeneral)
  {
    probeExpr = em->
    create_fo_expr(sctx,
                   udf,
                   loc,
                   BUILTIN_FUNC(FN_ZORBA_XQDDF_PROBE_INDEX_POINT_GENERAL_N),
                   qnameExpr,
                   const_cast<expr*>(predInfo.theOuterOp));
    
    probeExpr = em->
    create_fo_expr(sctx,
                   udf,
                   loc,
                   BUILTIN_FUNC(OP_SORT_DISTINCT_NODES_ASC_1),
                   probeExpr);
  }
  else
  {
    probeExpr = em->
    create_fo_expr(sctx,
                   udf,
                   loc,
                   BUILTIN_FUNC(FN_ZORBA_XQDDF_PROBE_INDEX_POINT_VALUE_N),
                   qnameExpr,
                   const_cast<expr*>(predInfo.theOuterOp));
  }

  DynamicBitset probeVars = (*theExprVarsMap)[predInfo.theOuterOp];
  (*theExprVarsMap)[probeExpr] = probeVars;

  innerClause->set_expr(probeExpr);

  sctx->bind_index(idx, loc);

  if (Properties::instance()->printIntermediateOpt())
  {
    std::cout << std::endl << idx->toString() << std::endl;
  }

#if 0
  if (predInfo.theIsGeneral)
    std::cout << "!!!!! Applied General Hash Join !!!!!" << std::endl << std::endl;
  else
    std::cout << "!!!!! Applied Value Hash Join !!!!!" << std::endl << std::endl;
#endif
}


/*******************************************************************************

********************************************************************************/
void IndexJoinRule::expandVars(expr* e, csize outerVarId, csize innerVarId)
{
  if (e->get_expr_kind() == wrapper_expr_kind)
  {
    wrapper_expr* wrapper = static_cast<wrapper_expr*>(e);

    if (wrapper->get_input()->get_expr_kind() == var_expr_kind)
    {
      var_expr* var = static_cast<var_expr*>(wrapper->get_input());
      csize varid = 0;

      ZORBA_ASSERT(theVarIdMap->find(var) != theVarIdMap->end());
      
      varid = (*theVarIdMap)[var];

      // If it is a variable that is defined after the outer var
      if (outerVarId <= varid && varid < innerVarId)
      {
        if (var->get_kind() == var_expr::let_var)
        {
          wrapper->set_expr(var->get_forlet_clause()->get_expr());

          return expandVars(wrapper, outerVarId, innerVarId);
        }
        else if (var->get_kind() == var_expr::for_var)
        {
#if 1
          ZORBA_ASSERT(false);
#else
          // TODO: to expand a FOR var, we must make sure that the expr is a
          // map w.r.t. that var.
          wrapper->set_expr(var->get_forlet_clause()->get_expr());
          return expandVars(wrapper, outerVarId, maxVarId);
#endif
        }
        else
        {
          ZORBA_ASSERT(false);
        }
      }
    }
  }
  else if (e->get_expr_kind() == var_expr_kind)
  {
    ZORBA_ASSERT(false);
  }
  else
  {
    ExprIterator iter(e);
    while (!iter.done())
    {
      expandVars(**iter, outerVarId, innerVarId);
      iter.next();
    }
  }
}


}
/* vim:set et sw=2 ts=2: */
