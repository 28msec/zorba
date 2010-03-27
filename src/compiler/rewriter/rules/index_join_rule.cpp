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

#include "compiler/api/compilercb.h"
#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/xqddf/value_index.h"

#include "functions/function.h"
#include "functions/library.h"

#include "types/typeops.h"

#include "util/properties.h"

#include "zorbaerrors/Assert.h"


namespace zorba
{

struct PredicateInfo;

static bool isIndexJoinPredicate(RewriterContext&, PredicateInfo&);

static bool rewriteJoin(RewriterContext&, PredicateInfo&);

  static const var_expr* findForVar(static_context*, RewriterContext&, const expr*, ulong&);

static bool checkVarDependency(RewriterContext&, expr*, ulong);

static bool expandVars(RewriterContext&, expr*, ulong, int&);

static void findFlworForVar(RewriterContext&, const var_expr*, flwor_expr*&,
                            sequential_expr*&, ulong&, ulong&, ulong&);


struct PredicateInfo
{
  flwor_expr     * theFlworExpr;
  expr           * thePredicate;
  const expr     * theOuterOp;
  const var_expr * theOuterVar;
  ulong            theOuterVarId;
  const expr     * theInnerOp;
  const var_expr * theInnerVar;
};


/*******************************************************************************
  This rule analyzes the where clause of flwor exprs to deterimne whether any
  predicate in the clause is a join predicate and whether the associated join
  can be converted into a hashjoin using an index that is built on-th-fly. 
********************************************************************************/
expr_t IndexJoin::rewritePre(expr* node, RewriterContext& rCtx)
{
  if (node->get_expr_kind() != flwor_expr_kind)
    return NULL;

  flwor_expr* flworExpr = static_cast<flwor_expr *>(node);

  // Push the flwor expr into the stack
  rCtx.theFlworStack.push_back(flworExpr);
  rCtx.theIsModifiedStack.push_back(false);

  expr* whereExpr = flworExpr->get_where();

  if (whereExpr == NULL)
    return NULL;

  PredicateInfo predInfo;
  predInfo.theFlworExpr = flworExpr;
  predInfo.thePredicate = whereExpr;

  if (isIndexJoinPredicate(rCtx, predInfo))
  {
    if (rewriteJoin(rCtx, predInfo))
    {
      predInfo.theFlworExpr->remove_where_clause();
    }
  }
  else if (whereExpr->get_function_kind() == FunctionConsts::OP_AND_2)
  {
    // TODO: Flatten the and-tree and test all conjuncts
    // TODO: consider multi-key indices
    expr_iterator i = whereExpr->expr_begin();
    for(; !i.done(); ++i)
    {
      PredicateInfo predInfo;
      predInfo.theFlworExpr = flworExpr;
      predInfo.thePredicate = (*i);

      if (isIndexJoinPredicate(rCtx, predInfo))
      {
        if (rewriteJoin(rCtx, predInfo))
        {
          expr_t trueExpr = new const_expr(flworExpr->get_sctx_id(),
                                           flworExpr->get_loc(),
                                           true);
          (*i) = trueExpr;

          if (Properties::instance()->printIntermediateOpt())
          {
            std::cout << std::endl << "After HashJoin rewrite " << std::endl
                      << rCtx.getRoot()->toString() << std::endl;
          }
        }
      }
    }
  }

  return NULL;
}


expr_t IndexJoin::rewritePost(expr* node, RewriterContext& rCtx)
{
  if (node->get_expr_kind() == flwor_expr_kind)
  {
    expr_t expr = rCtx.theFlworStack.back();
    rCtx.theFlworStack.pop_back();

    bool modified = rCtx.theIsModifiedStack.back();
    rCtx.theIsModifiedStack.pop_back();

    return (modified ? expr : NULL);
  }

  return NULL;
}


/*******************************************************************************
  Check whether the given predicate is a join predicate that can be converted 
  to a hashjoin.
********************************************************************************/
static bool isIndexJoinPredicate(RewriterContext& rCtx, PredicateInfo& predInfo)
{
  const fo_expr* foExpr;
  const function* fn;
  const expr* predExpr = predInfo.thePredicate;

  static_context* sctx = rCtx.getStaticContext(predExpr);

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

  if (fn->comparisonKind() != CompareConsts::VALUE_EQUAL)
    return false;

  const expr* op1 = foExpr->get_arg(0);
  const expr* op2 = foExpr->get_arg(1);

  if (rCtx.theVarIdMap == NULL)
  {
    rCtx.theVarIdMap = new VarIdMap;
    rCtx.theIdVarMap = new IdVarMap;
    rCtx.theExprVarsMap = new ExprVarsMap;

    ulong numVars = 0;
    index_flwor_vars(rCtx.getRoot(), numVars, *rCtx.theVarIdMap, rCtx.theIdVarMap);

    DynamicBitset freeset(numVars);
    build_expr_to_vars_map(rCtx.getRoot(),
                           *rCtx.theVarIdMap,
                           freeset,
                           *rCtx.theExprVarsMap);
  }

  // Analyze each operand of the eq to see if it depends on a single for
  // variable. If that is not true, we reject this predicate.
  ulong var1id;
  const var_expr* var1 = findForVar(sctx, rCtx, op1, var1id);
  if (var1 == NULL)
    return false;

  ulong var2id;
  const var_expr* var2 = findForVar(sctx, rCtx, op2, var2id);
  if (var2 == NULL)
    return false;

  if (var1 == var2)
    return false;

  // Determine the outer and inner side of the join
  ulong outerVarId;
  ulong innerVarId;

  if (var1id < var2id)
  {
    predInfo.theOuterOp = op1;
    predInfo.theOuterVar = var1;
    predInfo.theOuterVarId = var1id;
    predInfo.theInnerOp = op2;
    predInfo.theInnerVar = var2;
    outerVarId = var1id;
    innerVarId = var2id;
  }
  else
  {
    predInfo.theOuterOp = op2;
    predInfo.theOuterVar = var2;
    predInfo.theOuterVarId = var2id;
    predInfo.theInnerOp = op1;
    predInfo.theInnerVar = var1;
    outerVarId = var2id;
    innerVarId = var1id;
  }

  // The domain of the outer var must contain more than 1 item.
  xqtref_t outerDomainType = predInfo.theOuterVar->get_domain_expr()->return_type(sctx);

  if (TypeOps::type_max_cnt(*outerDomainType) < 2)
    return false;

  // The expr that defines the inner var must not depend on the outer var.
  expr* innerDomainExpr = predInfo.theInnerVar->get_for_clause()->get_expr();
  if (checkVarDependency(rCtx, innerDomainExpr, outerVarId))
    return false;

  // The predicate must be in the same flwor that defines the inner var (this
  // way we can be sure that the pred acts as a filter over the inner var).
  if (predInfo.theFlworExpr->defines_variable(predInfo.theInnerVar) < 0)
    return false;

  // Type checks
  xqtref_t outerType = predInfo.theOuterOp->return_type(sctx);
  xqtref_t innerType = predInfo.theInnerOp->return_type(sctx);
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

  // The type of the outer/inner operands in the join predicate must not be
  // xs:untypedAtomic or xs:anyAtomic.
  if (TypeOps::is_equal(*primeOuterType, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE) ||
      TypeOps::is_equal(*primeInnerType, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    return false;

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
  Check if "curExpr" references a single var and that var is a FOR var. If so,
  return that FOR var and its prefix id; otherwise return NULL.
********************************************************************************/
static const var_expr* findForVar(
    static_context* sctx,
    RewriterContext& rCtx,
    const expr* curExpr,
    ulong& varid)
{
  const var_expr* var = NULL;

  while (true)
  {
    std::vector<ulong> varidSet;

    const DynamicBitset& bitset = (*rCtx.theExprVarsMap)[curExpr];

    bitset.getSet(varidSet);

    if (varidSet.size() != 1)
      return NULL;

    varid = varidSet[0];
    var = (*rCtx.theIdVarMap)[varid];

    if (var->get_kind() == var_expr::for_var)
    {
      xqtref_t domainType = var->get_domain_expr()->return_type(sctx);

      if (domainType->get_quantifier() == TypeConstants::QUANT_ONE)
      {
        // treat this var as a let var
        curExpr = var->get_domain_expr();
      }
      else
      {
        break;
      }
    }
    else if (var->get_kind() == var_expr::let_var)
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
  Check if "curExpr" depends on the var V with the given prefix id. The method
  returns true if "curExpr" references V or references another var whose domain
  expr depends on V.
********************************************************************************/
static bool checkVarDependency(
    RewriterContext& rCtx,
    expr* curExpr,
    ulong searchVarId)
{
  const DynamicBitset& bitset = (*rCtx.theExprVarsMap)[curExpr];

  if (bitset.get(searchVarId))
    return true;

  std::vector<ulong> varidSet;
  bitset.getSet(varidSet);

  ulong numVars = varidSet.size();
  for (ulong i = 0; i < numVars; ++i)
  {
    const var_expr* var = (*rCtx.theIdVarMap)[varidSet[i]];
    curExpr = var->get_forletwin_clause()->get_expr();

    if (checkVarDependency(rCtx, curExpr, searchVarId))
      return true;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
static bool rewriteJoin(RewriterContext& rCtx, PredicateInfo& predInfo)
{
  // std::cout << "!!!!! Found Join Index Predicate !!!!!" << std::endl << std::endl;

  const QueryLoc& loc = predInfo.thePredicate->get_loc();
  short sctxid = predInfo.thePredicate->get_sctx_id();
  static_context* sctx = rCtx.getStaticContext(predInfo.thePredicate);

  for_clause* fc = predInfo.theInnerVar->get_for_clause();

  int maxInnerVarId = -1;

  // The index domain expr is the expr that defines the inner var, expanded, if
  // possible, so that it does not reference any variables defined after the outer
  // var (because the index must be built ouside the loop of the outer FOR var).
  // Note: must clone fc->get_expr() because expandVars modifies its input, but
  // fc->get_expr should not be modified, because we may discover later that the
  // rewrite is not possible after all,
  expr::substitution_t subst;
  expr_t domainExpr = fc->get_expr()->clone(subst);
  if (!expandVars(rCtx, domainExpr, predInfo.theOuterVarId, maxInnerVarId))
    return false;

  //
  // Create the index name and the "create-index()" expr
  //
  std::ostringstream os;
  os << "tempIndex" << rCtx.m_tempIndexCounter++;

  store::Item_t qname;
  GENV_ITEMFACTORY->createQName(qname, "", "", os.str().c_str());

  expr_t qnameExpr(new const_expr(sctxid, loc, qname));
  expr_t buildExpr;

  fo_expr_t createExpr = new fo_expr(sctxid,
                                     loc,
                                     GET_BUILTIN_FUNCTION(OP_CREATE_INTERNAL_INDEX_2),
                                     qnameExpr,
                                     buildExpr);

  //
  // Find where to place the create-index expr
  //
  if (maxInnerVarId >= 0)
  {
    // The domain expr depends on some flwor var that is defined before the outer
    // var. In this case, we find the flwor expr defining the inner-most var V
    // referenced by the domain expr of the index. Let F be this flwor expr. If
    // F does not define the other var as well, then we create the index in the
    // return expr of F. Otherwise, we first break up F by creating a sub-flwor
    // expr (subF) and moving all clauses of F that appear after V's defining
    // clause into subF, making the return expr of f be the return expr of subF,
    // and setting subF as the return expr of F. Then, we create the index in 
    // the return expr of F.

    const var_expr* mostInnerVar = (*rCtx.theIdVarMap)[maxInnerVarId];
    flwor_clause* mostInnerVarClause = mostInnerVar->get_flwor_clause();

    flwor_expr* innerFlwor = NULL;
    ulong innerPosInStack;
    ulong innerPosInSeq;
    ulong mostInnerVarPos;
    sequential_expr* innerSeqExpr;

    findFlworForVar(rCtx,
                    mostInnerVar,
                    innerFlwor,
                    innerSeqExpr,
                    mostInnerVarPos,
                    innerPosInStack,
                    innerPosInSeq);

    if (innerFlwor->defines_variable(predInfo.theOuterVar) >= 0)
    {
      ulong numClauses = innerFlwor->num_clauses();

      ZORBA_ASSERT(mostInnerVarPos < numClauses-1);

      const QueryLoc& nestedLoc = mostInnerVarClause->get_loc();

      flwor_expr_t nestedFlwor = new flwor_expr(sctxid, nestedLoc, false);

      for (ulong i = mostInnerVarPos+1; i < numClauses; ++i)
      {
        nestedFlwor->add_clause(innerFlwor->get_clause(i, false));
      }

      for (ulong i = numClauses - 1; i > mostInnerVarPos; --i)
      {
        innerFlwor->remove_clause(i);
      }

      nestedFlwor->set_return_expr(innerFlwor->get_return_expr(true));

      innerSeqExpr = new sequential_expr(sctxid, loc);

      innerSeqExpr->push_back(createExpr.getp());
      innerSeqExpr->push_back(nestedFlwor.getp());

      innerFlwor->set_return_expr(innerSeqExpr);

      if (predInfo.theFlworExpr == innerFlwor)
        predInfo.theFlworExpr = nestedFlwor;
    }
    else
    {
      expr* returnExpr = innerFlwor->get_return_expr(false);

      if (returnExpr->get_expr_kind() == sequential_expr_kind)
      {
        innerSeqExpr = static_cast<sequential_expr*>(returnExpr);

        ulong numArgs = innerSeqExpr->size();
        ulong arg;
        for (arg = 0; arg < numArgs; ++arg)
        {
          if ((*innerSeqExpr)[arg]->get_function_kind() !=
              FunctionConsts::OP_CREATE_INTERNAL_INDEX_2)
          {
            break;
          }
        }

        innerSeqExpr->add_at(arg, createExpr.getp());
      }
      else
      {
        innerSeqExpr = new sequential_expr(sctxid, loc);
        
        innerSeqExpr->push_back(createExpr.getp());
        innerSeqExpr->push_back(returnExpr);

        innerFlwor->set_return_expr(innerSeqExpr);
      }
    }

    rCtx.theIsModifiedStack[innerPosInStack] = true;
  }
  else
  {
    // Find the flwor expr defining the outer var and create the index just
    // before this flwor.
    flwor_expr* outerFlworExpr = NULL;
    sequential_expr* outerSeqExpr;
    ulong outerPosInStack;
    ulong outerPosInSeq;
    ulong dummy;

    findFlworForVar(rCtx,
                    predInfo.theOuterVar,
                    outerFlworExpr,
                    outerSeqExpr,
                    dummy,
                    outerPosInStack,
                    outerPosInSeq);

    //  Build or adjust outer sequential expr
    if (outerSeqExpr == NULL)
    {
      outerSeqExpr = new sequential_expr(sctxid, loc);

      outerSeqExpr->push_back(createExpr.getp());
      outerSeqExpr->push_back(outerFlworExpr);

      rCtx.theFlworStack[outerPosInStack] = outerSeqExpr;
    }
    else
    {
      outerSeqExpr->add_at(outerPosInSeq, createExpr.getp());
    }

    rCtx.theIsModifiedStack[outerPosInStack] = true;
  }

  //
  // Replace the expr defining the inner var with an index probe.
  //
  fo_expr_t probeExpr = new fo_expr(sctxid,
                                    loc,
                                    GET_BUILTIN_FUNCTION(FN_ZORBA_DDL_PROBE_INDEX_POINT_N),
                                    qnameExpr,
                                    const_cast<expr*>(predInfo.theOuterOp));

  fc->set_expr(probeExpr.getp());

  //
  // Create the ValueIndex obj
  //
  ValueIndex_t idx = new ValueIndex(sctx, loc, qname);

  idx->setDomainExpr(domainExpr);

  idx->setDomainVariable(rCtx.createTempVar(sctxid, loc, var_expr::for_var));

  idx->setDomainPositionVariable(rCtx.createTempVar(sctxid, loc, var_expr::pos_var));

  idx->setTemp(true);

  std::vector<expr_t> columnExprs(1);
  std::vector<xqtref_t> columnTypes(1);
  std::vector<OrderModifier> modifiers(1);

  columnExprs[0] = predInfo.theInnerOp;
  columnTypes[0] = predInfo.theInnerOp->return_type(sctx);
  modifiers[0].theAscending = true;
  modifiers[0].theEmptyLeast = true;
  modifiers[0].theCollation = sctx->get_default_collation(QueryLoc::null);

  replace_var(columnExprs[0], predInfo.theInnerVar, idx->getDomainVariable());

  idx->setKeyExpressions(columnExprs);

  idx->setKeyTypes(columnTypes);

  idx->setOrderModifiers(modifiers);

  sctx->bind_index(qname, idx, loc);

  buildExpr = idx->getBuildExpr(rCtx.getCompilerCB(), loc);

  createExpr->set_arg(1, buildExpr);

  if (Properties::instance()->printIntermediateOpt())
  {
    std::cout << std::endl << idx->toString() << std::endl;
  }

  idx->setDomainExpr(NULL);
  idx->setDomainVariable(NULL);

  //std::cout << "!!!!! Applied Hash Join !!!!!" << std::endl << std::endl;

  return true;
}



/*******************************************************************************

********************************************************************************/
static bool expandVars(
    RewriterContext& rCtx,
    expr* subExpr,
    ulong outerVarId,
    int& maxVarId)
{
  if (subExpr->get_expr_kind() == wrapper_expr_kind)
  {
    wrapper_expr* wrapper = reinterpret_cast<wrapper_expr*>(subExpr);

    if (wrapper->get_expr()->get_expr_kind() == var_expr_kind)
    {
      const var_expr* var = reinterpret_cast<const var_expr*>(wrapper->get_expr());
      ulong varid = (*rCtx.theVarIdMap)[var];

      if (varid > outerVarId)
      {
        if (var->get_kind() == var_expr::let_var)
        {
          wrapper->set_expr(var->get_forletwin_clause()->get_expr());

          return expandVars(rCtx, wrapper, outerVarId, maxVarId);
        }
        else if (var->get_kind() == var_expr::for_var)
        {
#if 1
          return false;
#else
          // TODO: to expand a FOR var, we must make sure that the expr is a
          // map w.r.t. that var.
          wrapper->set_expr(var->get_forletwin_clause()->get_expr());

          return expandVars(rCtx, wrapper, outerVarId, maxVarId);
#endif
        }
        else
        {
          return false;
        }
      }
      else
      {
        if ((long)varid > maxVarId)
          maxVarId = varid;

        return true;
      }
    }
  }
  else if (subExpr->get_expr_kind() == var_expr_kind)
  {
    ZORBA_ASSERT(false);
  }

  expr_iterator iter = subExpr->expr_begin();
  while (!iter.done())
  {
    if (!expandVars(rCtx, *iter, outerVarId, maxVarId))
      return false;

    ++iter;
  }

  return true;
}


/*******************************************************************************
  Find the flwor expr defining the given var.
********************************************************************************/
static void findFlworForVar(
    RewriterContext& rCtx,
    const var_expr* var,
    flwor_expr*& flworExpr,
    sequential_expr*& seqExpr,
    ulong& varPos,
    ulong& posInStack,
    ulong& posInSeq)
{
  posInSeq = 0;
  flworExpr = NULL;
  seqExpr = NULL;

  for (long i = rCtx.theFlworStack.size() - 1; i >= 0; --i)
  {
    if (rCtx.theFlworStack[i]->get_expr_kind() == flwor_expr_kind)
    {
      flworExpr = static_cast<flwor_expr*>(rCtx.theFlworStack[i].getp());
    }
    else
    {
      assert(rCtx.theFlworStack[i]->get_expr_kind() == sequential_expr_kind);

      seqExpr = static_cast<sequential_expr*>(rCtx.theFlworStack[i].getp());

      expr_iterator exprIter = seqExpr->expr_begin();
      while (!exprIter.done())
      {
        if ((*exprIter)->get_expr_kind() == flwor_expr_kind)
        {
          flworExpr = static_cast<flwor_expr*>((*exprIter).getp());
          break;
        }
        ++exprIter;
        ++posInSeq;
      }
    }

    assert(flworExpr != NULL);

    long pos;
    if ((pos = flworExpr->defines_variable(var)) >= 0)
    {
      varPos = pos;
      posInStack = i;
      break;
    }

    flworExpr = NULL;
    seqExpr = NULL;
  }

  assert(flworExpr != NULL);
}


}

/* vim:set ts=2 sw=2: */
