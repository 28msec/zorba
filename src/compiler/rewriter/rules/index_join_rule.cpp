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
#include "compiler/rewriter/rules/ruleset.h"
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

struct PredicateInfo;

static bool isIndexJoinPredicate(RewriterContext&, PredicateInfo&);

static void rewriteJoin(RewriterContext&, PredicateInfo&, bool&);

static var_expr* findForVar(static_context*, RewriterContext&, const expr*, ulong&);

static bool checkVarDependency(RewriterContext&, expr*, ulong);

static bool expandVars(RewriterContext&, expr*, ulong, long&);

static bool findFlworForVar(RewriterContext&, const var_expr*, flwor_expr*&, ulong&, ulong&);


struct PredicateInfo
{
  flwor_expr  * theFlworExpr;
  expr        * thePredicate;
  expr        * theOuterOp;
  var_expr    * theOuterVar;
  ulong         theOuterVarId;
  expr        * theInnerOp;
  var_expr    * theInnerVar;
  bool          theIsGeneral;
};


/*******************************************************************************
  This rule analyzes the where clause of flwor exprs to deterimne whether any
  predicate in the clause is a join predicate and whether the associated join
  can be converted into a hashjoin using an index that is built on-th-fly.
********************************************************************************/
expr* IndexJoinRule::apply(RewriterContext& rCtx, expr* node, bool& modified)
{
  flwor_expr* flworExpr = NULL;

  if (node->get_expr_kind() == gflwor_expr_kind)
    return node;

  if (node->get_expr_kind() == trycatch_expr_kind)
  {
    rCtx.theFlworStack.push_back(node);
  }
  else if (node->get_expr_kind() == flwor_expr_kind)
  {
    flworExpr = static_cast<flwor_expr *>(node);

    // Push the flwor expr into the stack
    rCtx.theFlworStack.push_back(flworExpr);
    rCtx.theInReturnClause.push_back(false);

    expr* whereExpr = flworExpr->get_where();

    if (whereExpr == NULL)
      goto drilldown;

    PredicateInfo predInfo;
    predInfo.theFlworExpr = flworExpr;
    predInfo.thePredicate = whereExpr;

    if (isIndexJoinPredicate(rCtx, predInfo))
    {
      rewriteJoin(rCtx, predInfo, modified);

      if (modified)
      {
        predInfo.theFlworExpr->remove_where_clause();

        expr* e = rCtx.theFlworStack.back();

        ZORBA_ASSERT(e == node || e->get_expr_kind() == block_expr_kind);

        rCtx.theFlworStack.pop_back();
        rCtx.theInReturnClause.pop_back();
        return e;
      }
    }
    else if (whereExpr->get_function_kind() == FunctionConsts::OP_AND_N)
    {
      // TODO: consider multi-key indices
      ExprIterator iter(whereExpr);
      while (!iter.done())
      {
        PredicateInfo predInfo;
        predInfo.theFlworExpr = flworExpr;
        predInfo.thePredicate = (**iter);

        if (isIndexJoinPredicate(rCtx, predInfo))
        {
          rewriteJoin(rCtx, predInfo, modified);

          if (modified)
          {
            expr* trueExpr = rCtx.theEM->create_const_expr(flworExpr->get_sctx(),
                                             flworExpr->get_loc(),
                                             true);
            (**iter) = trueExpr;

            expr* e = rCtx.theFlworStack.back();

            ZORBA_ASSERT(e == node || e->get_expr_kind() == block_expr_kind);

            rCtx.theFlworStack.pop_back();
            rCtx.theInReturnClause.pop_back();
            return e;
          }
        }

        iter.next();
      }
    }
  }

 drilldown:

  ExprIterator iter(node);
  while (!iter.done())
  {
    expr* currChild = **iter;

    if (flworExpr != NULL && currChild == flworExpr->get_return_expr())
      rCtx.theInReturnClause.back() = true;

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

  if (node->get_expr_kind() == trycatch_expr_kind)
  {
    rCtx.theFlworStack.pop_back();
    return node;
  }
  else if (node->get_expr_kind() == flwor_expr_kind)
  {
    expr* e = rCtx.theFlworStack.back();

    ZORBA_ASSERT(e == node || e->get_expr_kind() == block_expr_kind);

    rCtx.theFlworStack.pop_back();
    rCtx.theInReturnClause.pop_back();
    return e;
  }
  else
  {
    return node;
  }
}


/*******************************************************************************
  Check whether the given predicate is a join predicate that can be converted
  to a hashjoin.
********************************************************************************/
static bool isIndexJoinPredicate(RewriterContext& rCtx, PredicateInfo& predInfo)
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

  static_context* sctx = predExpr->get_sctx();

  predInfo.theIsGeneral = (opKind == CompareConsts::GENERAL_EQUAL);

  expr* op1 = foExpr->get_arg(0);
  expr* op2 = foExpr->get_arg(1);

  // Analyze each operand of the eq to see if it depends on a single for
  // variable. If that is not true, we reject this predicate.
  ulong var1id;
  var_expr* var1 = findForVar(sctx, rCtx, op1, var1id);
  if (var1 == NULL)
    return false;

  ulong var2id;
  var_expr* var2 = findForVar(sctx, rCtx, op2, var2id);
  if (var2 == NULL)
    return false;

  if (var1 == var2)
    return false;

  // Determine the outer and inner side of the join
  ulong outerVarId;

  if (var1id < var2id)
  {
    predInfo.theOuterOp = op1;
    predInfo.theOuterVar = var1;
    predInfo.theOuterVarId = var1id;
    predInfo.theInnerOp = op2;
    predInfo.theInnerVar = var2;
    outerVarId = var1id;
  }
  else
  {
    predInfo.theOuterOp = op2;
    predInfo.theOuterVar = var2;
    predInfo.theOuterVarId = var2id;
    predInfo.theInnerOp = op1;
    predInfo.theInnerVar = var1;
    outerVarId = var2id;
  }

  TypeManager* tm = sctx->get_typemanager();
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  // The domain of the outer var must contain more than 1 item.
  xqtref_t outerDomainType = predInfo.theOuterVar->get_domain_expr()->get_return_type();

  if (outerDomainType->max_card() < 2)
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
    if (TypeOps::is_equal(tm, *primeOuterType, *rtm.UNTYPED_ATOMIC_TYPE_ONE, outerLoc) ||
        TypeOps::is_equal(tm, *primeInnerType, *rtm.UNTYPED_ATOMIC_TYPE_ONE, innerLoc))
      return false;

    if (TypeOps::is_equal(tm, *primeOuterType, *rtm.ANY_ATOMIC_TYPE_ONE, outerLoc) ||
        TypeOps::is_equal(tm, *primeInnerType, *rtm.ANY_ATOMIC_TYPE_ONE, innerLoc))
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
  Check if "curExpr" references a single var and that var is a FOR var. If so,
  return that FOR var and its prefix id; otherwise return NULL.
********************************************************************************/
static var_expr* findForVar(
    static_context* sctx,
    RewriterContext& rCtx,
    const expr* curExpr,
    ulong& varid)
{
  var_expr* var = NULL;

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
      curExpr = var->get_domain_expr();

      if (curExpr->is_sequential())
        return NULL;

      xqtref_t domainType = var->get_domain_expr()->get_return_type();

      if (domainType->get_quantifier() != TypeConstants::QUANT_ONE)
      {
        // found a real FOR var, so we return it.
        return var;
      }
    }
    else if (var->get_kind() == var_expr::let_var)
    {
      curExpr = var->get_domain_expr();

      if (curExpr->is_sequential())
        return NULL;
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

  ulong numVars = (ulong)varidSet.size();
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
static void rewriteJoin(
    RewriterContext& rCtx,
    PredicateInfo& predInfo,
    bool& modified)
{
  // std::cout << "!!!!! Found Join Index Predicate !!!!!" << std::endl << std::endl;

  const QueryLoc& loc = predInfo.thePredicate->get_loc();
  static_context* sctx = predInfo.thePredicate->get_sctx();

  for_clause* fc = predInfo.theInnerVar->get_for_clause();

  long maxInnerVarId = -1;

  // The index domain expr is the expr that defines the inner var, expanded, if
  // possible, so that it does not reference any variables defined after the outer
  // var (because the index must be built ouside the loop of the outer FOR var).
  // Note: must clone fc->get_expr() because expandVars modifies its input, but
  // fc->get_expr should not be modified, because we may discover later that the
  // rewrite is not possible after all,
  expr::substitution_t subst;
  expr* domainExpr = fc->get_expr()->clone(subst);

  if (!expandVars(rCtx, domainExpr, predInfo.theOuterVarId, maxInnerVarId))
    return;

  //
  // Create the index name and the "create-index()" expr
  //
  std::ostringstream os;
  os << "tempIndex" << rCtx.theCCB->theTempIndexCounter++;

  store::Item_t qname;
  GENV_ITEMFACTORY->createQName(qname, "", "", os.str().c_str());

  expr* qnameExpr(rCtx.theEM->create_const_expr(sctx, loc, qname));
  expr* buildExpr = NULL;

  fo_expr* createExpr = rCtx.theEM->create_fo_expr(sctx,
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
    // F does not define the outer var as well, then we create the index in the
    // return expr of F. Otherwise, we first break up F by creating a sub-flwor
    // expr (subF) and moving all clauses of F that appear after V's defining
    // clause into subF, making the return expr of f be the return expr of subF,
    // and setting subF as the return expr of F. Then, we create the index in
    // the return expr of F.

    const var_expr* mostInnerVar = (*rCtx.theIdVarMap)[maxInnerVarId];
    flwor_clause* mostInnerVarClause = mostInnerVar->get_flwor_clause();

    flwor_expr* innerFlwor = NULL;
    ulong innerPosInStack = 0;
    ulong mostInnerVarPos = 0;

    if (!findFlworForVar(rCtx,
                         mostInnerVar,
                         innerFlwor,
                         mostInnerVarPos,
                         innerPosInStack))
      return;

    csize numClauses = innerFlwor->num_clauses();

    if (innerFlwor->defines_variable(predInfo.theOuterVar) >= 0 ||
        mostInnerVarPos < numClauses-1)
    {
      ZORBA_ASSERT(mostInnerVarPos < numClauses-1);

      const QueryLoc& nestedLoc = mostInnerVarClause->get_loc();

      flwor_expr* nestedFlwor = rCtx.theEM->create_flwor_expr(sctx, nestedLoc, false);

      for (csize i = mostInnerVarPos+1; i < numClauses; ++i)
      {
        nestedFlwor->add_clause(innerFlwor->get_clause(i));
      }

      for (csize i = numClauses - 1; i > mostInnerVarPos; --i)
      {
        innerFlwor->remove_clause(i);
      }

      nestedFlwor->set_return_expr(innerFlwor->get_return_expr());

      std::vector<expr*> args(2);
      args[0] = createExpr;
      args[1] = nestedFlwor;

      block_expr* seqExpr = rCtx.theEM->create_block_expr(sctx, loc, false, args, NULL);

      innerFlwor->set_return_expr(seqExpr);

      if (predInfo.theFlworExpr == innerFlwor)
      {
        // The where clause has moved to the nested flwor.
        predInfo.theFlworExpr = nestedFlwor;
      }
    }
    else
    {
      expr* returnExpr = innerFlwor->get_return_expr();

      if (returnExpr->get_expr_kind() == block_expr_kind)
      {
        block_expr* seqExpr = static_cast<block_expr*>(returnExpr);

        csize numArgs = seqExpr->size();
        csize arg;
        for (arg = 0; arg < numArgs; ++arg)
        {
          if ((*seqExpr)[arg]->get_function_kind() !=
              FunctionConsts::OP_CREATE_INTERNAL_INDEX_2)
          {
            break;
          }
        }

        seqExpr->add_at(arg, createExpr);
      }
      else
      {
        std::vector<expr*> args(2);
        args[0] = createExpr;
        args[1] = returnExpr;

        block_expr* seqExpr = rCtx.theEM->create_block_expr(sctx, loc, false, args, NULL);

        innerFlwor->set_return_expr(seqExpr);
      }
    }
  }
  else
  {
    // The inner domain expr does not reference any flwor vars. In this case,
    // find the flwor expr defining the outer var and create the index just
    // before this flwor.
    flwor_expr* outerFlworExpr = NULL;
    ulong outerPosInStack = 0;
    ulong dummy = 0;

    if (!findFlworForVar(rCtx,
                         predInfo.theOuterVar,
                         outerFlworExpr,
                         dummy,
                         outerPosInStack))
      return;

    //  Build outer sequential expr
    std::vector<expr*> args(2);
    args[0] = createExpr;
    args[1] = outerFlworExpr;

    block_expr* seqExpr = rCtx.theEM->create_block_expr(sctx, loc, false, args, NULL);

    rCtx.theFlworStack[outerPosInStack] = seqExpr;
  }

  modified = true;

  //
  // Replace the expr defining the inner var with an index probe.
  //
  fo_expr* probeExpr = NULL;

  if (predInfo.theIsGeneral)
  {
    probeExpr =
    rCtx.theEM->create_fo_expr(sctx,
                loc,
                GET_BUILTIN_FUNCTION(FN_ZORBA_XQDDF_PROBE_INDEX_POINT_GENERAL_N),
                qnameExpr,
                const_cast<expr*>(predInfo.theOuterOp));

    probeExpr =
    rCtx.theEM->create_fo_expr(sctx,
                loc,
                GET_BUILTIN_FUNCTION(OP_SORT_DISTINCT_NODES_ASC_1),
                probeExpr);
  }
  else
  {
    probeExpr =
    rCtx.theEM->create_fo_expr(sctx,
                loc,
                GET_BUILTIN_FUNCTION(FN_ZORBA_XQDDF_PROBE_INDEX_POINT_VALUE_N),
                qnameExpr,
                const_cast<expr*>(predInfo.theOuterOp));
  }

  fc->set_expr(probeExpr);

  //
  // Create the IndexDecl obj
  //
  IndexDecl_t idx = new IndexDecl(sctx, rCtx.theCCB, loc, qname);

  if (predInfo.theIsGeneral)
    idx->setGeneral(true);

  idx->setTemp(true);

  idx->setDomainExpr(domainExpr);

  idx->setDomainVariable(rCtx.createTempVar(sctx, loc, var_expr::for_var));

  idx->setDomainPositionVariable(rCtx.createTempVar(sctx, loc, var_expr::pos_var));

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

  sctx->bind_index(idx, loc);

  buildExpr = idx->getBuildExpr(rCtx.getCompilerCB(), loc);

  createExpr->set_arg(1, buildExpr);

  if (Properties::instance()->printIntermediateOpt())
  {
    std::cout << std::endl << idx->toString() << std::endl;
  }

  //idx->setDomainExpr(NULL);
  //idx->setDomainVariable(NULL);

#if 0
  if (predInfo.theIsGeneral)
    std::cout << "!!!!! Applied General Hash Join !!!!!" << std::endl << std::endl;
  else
    std::cout << "!!!!! Applied Value Hash Join !!!!!" << std::endl << std::endl;
#endif
}



/*******************************************************************************

********************************************************************************/
static bool expandVars(
    RewriterContext& rCtx,
    expr* subExpr,
    ulong outerVarId,
    long& maxVarId)
{
  if (subExpr->get_expr_kind() == wrapper_expr_kind)
  {
    wrapper_expr* wrapper = reinterpret_cast<wrapper_expr*>(subExpr);

    if (wrapper->get_expr()->get_expr_kind() == var_expr_kind)
    {
      var_expr* var = reinterpret_cast<var_expr*>(wrapper->get_expr());
      long varid = -1;

      if (rCtx.theVarIdMap->find(var) != rCtx.theVarIdMap->end())
      {
        varid = (*rCtx.theVarIdMap)[var];
      }
      else if (var->get_kind() == var_expr::local_var)
      {
        // TODO: allow index domain exprs to reference local vars
        return false;
      }

      // If it is a variable that is defined after the outer var
      if (varid > (long)outerVarId)
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
        if (varid > maxVarId)
          maxVarId = varid;

        return true;
      }
    }
  }
  else if (subExpr->get_expr_kind() == var_expr_kind)
  {
    ZORBA_ASSERT(false);
  }

  ExprIterator iter(subExpr);
  while (!iter.done())
  {
    if (!expandVars(rCtx, **iter, outerVarId, maxVarId))
      return false;

    iter.next();
  }

  return true;
}


/*******************************************************************************
  Find the flwor expr defining the given var.
********************************************************************************/
static bool findFlworForVar(
    RewriterContext& rCtx,
    const var_expr* var,
    flwor_expr*& flworExpr,
    ulong& varPos,
    ulong& posInStack)
{
  flworExpr = NULL;

  long numFlwors = (long)rCtx.theFlworStack.size();

  for (long i = numFlwors - 1; i >= 0; --i)
  {
    if (rCtx.theFlworStack[i]->get_expr_kind() == trycatch_expr_kind)
      return false;

    flworExpr = dynamic_cast<flwor_expr*>(rCtx.theFlworStack[i]);

    assert(flworExpr != NULL);

    if (i < numFlwors - 1 &&
        rCtx.theInReturnClause[i] == true &&
        flworExpr->is_sequential())
      return false;

    // This condition is rather conservative and can be relaxed. TODO
    if (flworExpr->has_sequential_clauses())
      return false;

    long pos;
    if ((pos = flworExpr->defines_variable(var)) >= 0)
    {
      varPos = pos;
      posInStack = i;
      break;
    }

    flworExpr = NULL;
  }

  assert(flworExpr != NULL);
  return true;
}


}
/* vim:set et sw=2 ts=2: */
