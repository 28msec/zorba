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

#include "diagnostics/xquery_diagnostics.h"

#include "system/globalenv.h"

#include "context/static_context.h"

#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/rewriter/framework/rewriter.h"

#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/expr_iter.h"
#include "compiler/expression/expr.h"

#include "compiler/codegen/plan_visitor.h"
#include "compiler/api/compilercb.h"
#include "compiler/api/compiler_api.h"

#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "types/casting.h"

#include "functions/udf.h"
#include "functions/func_errors_and_diagnostics.h"
#include "functions/library.h"

#include "runtime/util/plan_wrapper_holder.h"
#include "runtime/base/plan_iterator.h"

#include "store/api/store.h"
#include "store/api/item_factory.h"

#include <iterator>

namespace zorba {

static bool execute(CompilerCB*, expr* node, store::Item_t& result);

static expr* partial_eval_fo(RewriterContext&, fo_expr*);

static expr* partial_eval_logic(fo_expr*, bool, RewriterContext&);

static expr* partial_eval_eq(RewriterContext&, fo_expr&);

static expr* partial_eval_return_clause(flwor_expr*, bool&, RewriterContext&);

static bool maybe_needs_implicit_timezone(const fo_expr* fo);


/*******************************************************************************
  Compute the NON_DISCARDABLE and UNFOLDABLE properties of expressions

  The meaning/purpose of the NON_DISCARDABLE property is as follows:
  Some expressions can be computed (at leat partially) during compilation time
  based on the static type of their argument. For example, count(E) can be
  replaced by const 1 if the static type of E has quantifier 1. Also,
  castable(E, target_type) can be replaced by const true if the static type of
  E is a subtype of target_type. However, E may have "side-effects", which
  prevent such a replacement. For example, it may be a treat expr, whose
  semantics is to return an error during runtime if the arg of the treat expr
  does not have the corect type. We flag such exprs as non-discardable so that
  no (partial) evaluation of parent exprs is done.

  The NON_DISCARDABLE property is used during the application of the PartialEval
  rule below.
********************************************************************************/
expr* MarkExprs::apply(RewriterContext& rCtx, expr* node, bool& modified)
{
  BoolAnnotationValue saveNonDiscardable = node->getNonDiscardable();
  BoolAnnotationValue saveUnfoldable = node->getUnfoldable();
  BoolAnnotationValue saveContainsRecursiveCall = node->getContainsRecursiveCall();
  BoolAnnotationValue saveConstructsNodes = node->getConstructsNodes();
  BoolAnnotationValue saveDereferencesNodes = node->getDereferencesNodes();

  // By default, an expr is discardable, foldable,  does not contain recursive
  // calls, and returns constructed nodes.
  BoolAnnotationValue curNonDiscardable = ANNOTATION_FALSE;
  BoolAnnotationValue curUnfoldable = ANNOTATION_FALSE;
  BoolAnnotationValue curContainsRecursiveCall = ANNOTATION_FALSE;
  BoolAnnotationValue curConstructsNodes = ANNOTATION_FALSE;
  BoolAnnotationValue curDereferencesNodes = ANNOTATION_FALSE;

  // Process udfs: If the current expr is a udf invocation, optimize the udf
  // body, if not optimized already, and determine whether the invocation is
  // a recursive call or not.
  if (node->get_expr_kind() == fo_expr_kind)
  {
    fo_expr* fo = static_cast<fo_expr *>(node);
    function* f = fo->get_func();

    if (f->isUdf() && !theIsLocal)
    {
      user_function* udf = static_cast<user_function*>(f);

      if (!udf->isOptimized())
      {
        // we can be here in case of mutually recursive udfs or during plan
        // serialization and udf was not callable by the main program
        udf->optimize();
      }

      if (rCtx.theUDF != NULL &&
          rCtx.theUDF->isMutuallyRecursiveWith(udf))
      {
        curContainsRecursiveCall = ANNOTATION_TRUE;
      }
    }
  }

  // Process the subexprs of the current expr. If any of the children is
  // nondiscardable, unfoldable, or contains recursive calls, then the current
  // expr is also nondiscardable, unfoldable, or contains recursive calls.
  ExprConstIterator iter(node);
  while(!iter.done())
  {
    expr* childExpr = iter.get_expr();

    apply(rCtx, childExpr, modified);

    if (childExpr->isNonDiscardable())
      curNonDiscardable = ANNOTATION_TRUE;

    if (childExpr->isUnfoldable())
      curUnfoldable = ANNOTATION_TRUE;

    if (childExpr->containsRecursiveCall())
      curContainsRecursiveCall = ANNOTATION_TRUE;

    if (childExpr->constructsNodes())
      curConstructsNodes = ANNOTATION_TRUE;

    if (childExpr->dereferencesNodes())
      curDereferencesNodes = ANNOTATION_TRUE;

    iter.next();
  }

  switch (node->get_expr_kind())
  {
  case fo_expr_kind:
  {
    fo_expr* fo = static_cast<fo_expr *>(node);
    function* f = fo->get_func();
        
    if (!f->isUdf())
    {
      if (FunctionConsts::FN_ERROR_0 <= f->getKind() &&
          f->getKind() <= FunctionConsts::FN_TRACE_2)
      {
        curNonDiscardable = ANNOTATION_TRUE_FIXED;
        curUnfoldable = ANNOTATION_TRUE_FIXED;
      }
      else if (f->getKind() == FunctionConsts::FN_ZORBA_REF_NODE_BY_REFERENCE_1)
      {
        curDereferencesNodes = ANNOTATION_TRUE;
      }
      
      // Do not fold functions that always require access to the dynamic context,
      // or may need to access the implicit timezone (which is also in the dynamic
      // constext).
      if (saveUnfoldable != ANNOTATION_TRUE_FIXED &&
          (f->accessesDynCtx() ||
           maybe_needs_implicit_timezone(fo) ||
           !f->isDeterministic()))
      {
        curUnfoldable = ANNOTATION_TRUE_FIXED;
      }
    }
    else if (theIsLocal)
    {
      curUnfoldable = saveUnfoldable;
      curDereferencesNodes = saveDereferencesNodes;
      curConstructsNodes = saveConstructsNodes;
    }
    else
    {
      if (saveUnfoldable != ANNOTATION_TRUE_FIXED &&
          (f->accessesDynCtx() || !f->isDeterministic()))
      {
        curUnfoldable = ANNOTATION_TRUE_FIXED;
      }
      
      if (static_cast<user_function*>(f)->dereferencesNodes())
        curDereferencesNodes = ANNOTATION_TRUE;
      
      if (static_cast<user_function*>(f)->constructsNodes())
        curConstructsNodes = ANNOTATION_TRUE;
    }
    
    break;
  }
  
  case var_expr_kind:
  {
    var_expr::var_kind varKind = static_cast<var_expr *>(node)->get_kind();
    
    if (varKind == var_expr::prolog_var || varKind == var_expr::local_var)
      curUnfoldable = ANNOTATION_TRUE_FIXED;
    
    break;
  }
  
  default:
  {
    break;
  }
  }

  if (node->is_sequential())
  {
    curNonDiscardable = ANNOTATION_TRUE_FIXED;
    curUnfoldable = ANNOTATION_TRUE_FIXED;
  }

  if (saveNonDiscardable != curNonDiscardable &&
      saveNonDiscardable != ANNOTATION_TRUE_FIXED)
  {
    node->setNonDiscardable(curNonDiscardable);
    modified = true;
  }

  if (saveUnfoldable != curUnfoldable &&
      saveUnfoldable != ANNOTATION_TRUE_FIXED)
  {
    node->setUnfoldable(curUnfoldable);
    modified = true;
  }

  if (saveContainsRecursiveCall != curContainsRecursiveCall &&
      saveContainsRecursiveCall != ANNOTATION_TRUE_FIXED)
  {
    node->setContainsRecursiveCall(curContainsRecursiveCall);
    modified = true;
  }

  if (saveConstructsNodes != curConstructsNodes &&
      saveConstructsNodes != ANNOTATION_TRUE_FIXED)
  {
    node->setConstructsNodes(curConstructsNodes);
    modified = true;
  }

  if (saveDereferencesNodes != curDereferencesNodes &&
      saveDereferencesNodes != ANNOTATION_TRUE_FIXED)
  {
    node->setDereferencesNodes(curDereferencesNodes);
    modified = true;
  }

  return NULL;
}


static bool maybe_needs_implicit_timezone(const fo_expr* fo)
{
  TypeManager* tm = fo->get_type_manager();

  const function* f = fo->get_func();
  FunctionConsts::FunctionKind fkind = f->getKind();
  xqtref_t type0 = (fo->num_args() > 0 ? fo->get_arg(0)->get_return_type() : NULL);
  xqtref_t type1 = (fo->num_args() > 1 ? fo->get_arg(1)->get_return_type() : NULL);

  return ( ((f->isComparisonFunction() ||
             f->arithmeticKind() == ArithmeticConsts::SUBTRACTION) &&
            (TypeOps::maybe_date_time(tm, *type0) ||
             TypeOps::maybe_date_time(tm, *type1)))
           ||
           ((fkind == FunctionConsts::FN_DISTINCT_VALUES_1 ||
             fkind == FunctionConsts::FN_DISTINCT_VALUES_2 ||
             fkind == FunctionConsts::FN_MIN_1 ||
             fkind == FunctionConsts::FN_MIN_2 ||
             fkind == FunctionConsts::FN_MAX_1 ||
             fkind == FunctionConsts::FN_MAX_2)
            && TypeOps::maybe_date_time(tm, *type0)) );
}


/*******************************************************************************
  For each expr E, collect all the variables that are referenced directly by E
  and its subexpressions.
********************************************************************************/
expr* MarkFreeVars::apply(RewriterContext& rCtx, expr* node, bool& modified)
{
  expr::FreeVars& freevars = node->getFreeVars();

  freevars.clear();

  switch (node->get_expr_kind())
  {
  case var_expr_kind:
  {
    var_expr* v = static_cast<var_expr *>(node);
    freevars.insert(v);

    break;
  }
  // Get the free vars of each child expr and add them to the free vars of the
  // parent. But in case of a flwor expr, do not add any variables defined by
  // the flwor expr itself

  case flwor_expr_kind:
  case gflwor_expr_kind:
  {
    flwor_expr* flwor = static_cast<flwor_expr *> (node);

    ExprIterator iter(node);
    while (!iter.done())
    {
      expr* e = **iter;
        
      apply(rCtx, e, modified);

      const expr::FreeVars& kfv = e->getFreeVars();

      expr::FreeVars::const_iterator ite = kfv.begin();
      expr::FreeVars::const_iterator end = kfv.end();
      for (; ite != end; ++ite)
      {
        flwor_clause* c = (*ite)->get_flwor_clause();
        if (c != NULL && c->get_flwor_expr() == flwor)
          continue;
        
        freevars.insert(*ite);
      }
      
      iter.next();
    }

    break;
  }
  default:
  {
    ExprIterator iter(node);

    while (!iter.done())
    {
      expr* e = **iter;

      apply(rCtx, e, modified);
        
      const expr::FreeVars& kfv = e->getFreeVars();
      std::copy(kfv.begin(),
                kfv.end(),
                inserter(freevars, freevars.begin()));
      
      iter.next();
    }
  }
  }

  return NULL;
}


/*******************************************************************************
  Execute const exprs that return at most one item as a result. Replace such
  exprs by either a const_expr whose value is the returned item, or an empty
  fn:concatenate expr, if no item is returned by the evaluation of the const
  expr.
********************************************************************************/
expr* FoldConst::apply(RewriterContext& rCtx, expr* node, bool& modified)
{
  expr_kind_t k = node->get_expr_kind();
  xqtref_t rtype = node->get_return_type(); // DO NOT MOVE THIS !!!!

  switch (k)
  {
  case const_expr_kind:
  case match_expr_kind:
  case axis_step_expr_kind:
  {
    break;
  }
  case fo_expr_kind:
  {
    fo_expr* fo = static_cast<fo_expr*>(node);

    if (fo->get_func()->getKind() == FunctionConsts::OP_CONCATENATE_N &&
        fo->num_args() == 0)
      break;
  }
   
  default:
  {
    if (node->getFreeVars().empty() &&
        ! node->isUnfoldable() &&
        rtype->max_card() <= 1)
    {
      store::Item_t result;
      bool folded = execute(rCtx.getCompilerCB(), node, result);

      if (folded)
      {
        expr* foldedExpr;

        if (result)
        {
          foldedExpr = rCtx.theEM->
          create_const_expr(node->get_sctx(), node->get_udf(), LOC(node), result);
        }
        else
        {
          foldedExpr  = rCtx.theEM->
          create_seq(node->get_sctx(), node->get_udf(), LOC(node));
        }

        modified = true;
        return foldedExpr;
      }
    }

    break;
  }
  }

  ExprIterator iter(node);

  while (!iter.done())
  {
    expr* new_e = apply(rCtx, **iter, modified);
    if (new_e != NULL)
    {
      **iter = new_e;
    }
    
    iter.next();
  }

  return NULL;
}


/*******************************************************************************

********************************************************************************/
static bool execute(
    CompilerCB* compilercb,
    expr* node,
    store::Item_t& result)
{
  ulong nextVarId = 1;
  PlanIter_t plan = codegen("const-folded expr", node, compilercb, nextVarId);

  QueryLoc loc = LOC (node);
  store::Item_t item;

  CompilerCB expr_ccb(*compilercb);
  expr_ccb.theRootSctx = node->get_sctx();

  try
  {
    //std::cout << "Const folding expr : " << std::endl;
    //node->put(std::cout);
    //std::cout << std::endl;

    PlanWrapperHolder pw(new PlanWrapper(plan,
                                         &expr_ccb,
                                         0,      // dynamic ctx
                                         NULL,   // xquery
                                         0,      // stack depth
                                         expr_ccb.theHaveTimeout,
                                         expr_ccb.theTimeout));
    if (pw->next(item))
    {
      if (item->isError())
      {
        node->setUnfoldable(ANNOTATION_TRUE_FIXED);
        node->setNonDiscardable(ANNOTATION_TRUE_FIXED);
        return false;
      }

      result.transfer(item);

      ZORBA_ASSERT(!pw->next(item));
    }
    else
    {
      result = NULL;
    }

    return true;
  }
  catch (ZorbaException const&)
  {
    node->setUnfoldable(ANNOTATION_TRUE_FIXED);
    node->setNonDiscardable(ANNOTATION_TRUE_FIXED);
    return false;

    // TODO:
    // we had to disable folding of errors because the FnErrorIterator
    // was erroneously used. It always raises a ZorbaUserError (which is not correct).
#if 0
    Error lErrorCode = e.theErrorCode;
    QueryLoc loc;
    loc.setLineBegin(e.theQueryLine);
    loc.setColumnBegin(e.theQueryColumn);
    store::Item_t qname;
    ITEM_FACTORY->createQName(qname,
                              "http://www.w3.org/2005/xqt-errors",
                              "err",
                              error::ZorbaError::toString(lErrorCode).c_str());
    expr* err_expr = rCtx.theEM->
    create_fo_expr(node->get_sctx_id(),
                   loc,
                   BUILTIN_FUNC(FN_ERROR_2),
                   rCtx.theEM->create_const_expr(node->get_sctx(), loc, qname),
                   rCtx.theEM->create_const_expr(node->get_sctx(), loc, e.theDescription));
    err_expr->setUnfoldable(ANNOTATION_TRUE_FIXED);
    err_expr->setNonDiscardable(ANNOTATION_TRUE_FIXED);
    return err_expr;
#endif
  }
}


/*******************************************************************************

  The PartialEval rule performs the following kinds of rewrites:

  Replace "castable(E, targetType)" or "instance-of(E, targetType)" with true, if
  the return type of E is a subtype of targetType and E is not NONDISCARDABLE_EXPR.

  Replace "instance-of(E, targetType)" with false if the intersection of return
  type of E and the targetType is empty and E is not NONDISCARDABLE_EXPR.

  Replace "if (cond) then E1 else E2" with E1 or E2 if cond is a const expr whose
  EBV is true or false respectively.

  Rewrite "and" or "or" exprs which have one or more operands that are constants.
  Do this only if none of the operands is NONDISCARDABLE.
  For example:
  E and false --> false
  E and true  --> E

  Rewrite exprs of the form "count(E) = const" or "count(E) eq const".
  For example:
  count(E) = -1 --> false, if E is not NONDISCARDABLE
  count(E) = 0  --> fn:empty(E)
  count(E) = 1  --> fn:exectly-one-noraise(E)
  count(E) = 10 --> fn:exectly-one-noraise(fn:subsequence(E, 10, 2))

  If E is not NONDISCARDABLE_EXPR:
  - Replace count(E) with 1 or 0 if the return type of E has QUANT_ONE or is the
    emtpy sequence.
  - Replace empty(E) with true if the return type of E is the emtpy sequence, or
    false if the return type of E has QUANT_ONE or QUANT_PLUS.
  - Replace exists(E) with false if the return type of E is the emtpy sequence, or
    truee if the return type of E has QUANT_ONE or QUANT_PLUS.

  Replace EBV(E) with true if the return type of E is subtype on node()+ and E
  is not NONDISCARDABLE.

********************************************************************************/

RULE_REWRITE_PRE(PartialEval)
{
  TypeManager* tm = node->get_type_manager();

  static_context* sctx = node->get_sctx();

  // if node is a castable or instance-of expr
  const castable_base_expr* cbe = NULL;
  if ((cbe = dynamic_cast<const castable_base_expr *>(node)) != NULL)
  {
    user_function* udf = node->get_udf();
    assert(udf == rCtx.theUDF);

    expr* arg = cbe->get_input();

    if (arg->isNonDiscardable())
      return NULL;

    xqtref_t argType = arg->get_return_type();
    xqtref_t targetType = cbe->get_target_type();

    try
    {
      if (TypeOps::is_subtype(tm, *argType, *targetType, node->get_loc()))
      {
        return rCtx.theEM->create_const_expr(sctx, udf, LOC(node), true);
      }
      else if (node->get_expr_kind() == instanceof_expr_kind)
      {
        instanceof_expr* ioExpr = static_cast<instanceof_expr*>(node);

        if (ioExpr->getCheckPrimeOnly())
        {
          argType = TypeOps::prime_type(tm, *argType);
          targetType = TypeOps::prime_type(tm, *targetType);
        }

        return (TypeOps::intersect_type(*argType, *targetType, tm) ==
                GENV_TYPESYSTEM.NONE_TYPE ?
                rCtx.theEM->create_const_expr(sctx, udf, LOC(node), false) :
                NULL);
      }
      else
      {
        return NULL;
      }
    }
    catch (XQueryException& e)
    {
      if (e.diagnostic() == err::XPTY0004)
        return NULL;

      throw;
    }
  }

  switch (node->get_expr_kind())
  {
  case if_expr_kind:
  {
    if_expr* ite = dynamic_cast<if_expr *> (node);
    const const_expr* cond = dynamic_cast<const const_expr*>(ite->get_cond_expr());
    if (cond != NULL)
    {
      return (cond->get_val()->getBooleanValue() ?
              ite->get_then_expr() :
              ite->get_else_expr());
    }
    break;
  }

  case fo_expr_kind:
  {
    return partial_eval_fo(rCtx, dynamic_cast<fo_expr *>(node));
  }

  default:
    break;
  }

  return NULL;
}

RULE_REWRITE_POST(PartialEval)
{
  return NULL;
}


static expr* partial_eval_fo(RewriterContext& rCtx, fo_expr* fo)
{
  TypeManager* tm = fo->get_type_manager();

  static_context* sctx = fo->get_sctx();
  user_function* udf = fo->get_udf();
  assert(udf == rCtx.theUDF);

  const function* f = fo->get_func();
  FunctionConsts::FunctionKind fkind = f->getKind();

  if (fkind == FunctionConsts::OP_OR_N && !fo->isNonDiscardable())
  {
    return partial_eval_logic(fo, true, rCtx);
  }
  else if (fkind == FunctionConsts::OP_AND_N && !fo->isNonDiscardable())
  {
    return partial_eval_logic(fo, false, rCtx);
  }
  else if (f->comparisonKind() == CompareConsts::VALUE_EQUAL ||
           f->comparisonKind() == CompareConsts::GENERAL_EQUAL)
  {
    return partial_eval_eq(rCtx, *fo);
  }
  else if (fkind == FunctionConsts::FN_COUNT_1 ||
           fkind == FunctionConsts::FN_EMPTY_1 ||
           fkind == FunctionConsts::FN_EXISTS_1)
  {
    expr* arg = fo->get_arg(0);

    if (!arg->isNonDiscardable())
    {
      xqtref_t argType = arg->get_return_type();
      TypeConstants::quantifier_t argQuant = argType->get_quantifier();
      int type_cnt = argType->card();

      if (fkind == FunctionConsts::FN_COUNT_1 && type_cnt != -1)
      {
        return rCtx.theEM->
        create_const_expr(sctx, udf, fo->get_loc(), xs_integer(type_cnt));
      }
      else if (fkind == FunctionConsts::FN_EMPTY_1)
      {
        if (type_cnt == 0)
        {
          return rCtx.theEM->create_const_expr(sctx, udf, fo->get_loc(), true);
        }
        else if (argQuant == TypeConstants::QUANT_ONE ||
                 argQuant == TypeConstants::QUANT_PLUS)
        {
          return rCtx.theEM->create_const_expr(sctx, udf, fo->get_loc(), false);
        }
      }
      else if (fkind == FunctionConsts::FN_EXISTS_1)
      {
        if (type_cnt == 0)
        {
          return rCtx.theEM->create_const_expr(sctx, udf, fo->get_loc(), false);
        }
        else if (argQuant == TypeConstants::QUANT_ONE ||
                 argQuant == TypeConstants::QUANT_PLUS)
        {
          return rCtx.theEM->create_const_expr(sctx, udf, fo->get_loc(), true);
        }
      }
    }

    if (arg->get_expr_kind() == flwor_expr_kind)
    {
      bool modified = false;
      expr* newArg = partial_eval_return_clause(static_cast<flwor_expr*>(arg),
                                                 modified,
                                                 rCtx);

      if (newArg != arg)
        fo->set_arg(0, newArg);

      if (modified)
        return fo;
    }

    return NULL;
  }
  else if (fkind == FunctionConsts::FN_BOOLEAN_1)
  {
    expr* arg = fo->get_arg(0);
    if (!arg->isNonDiscardable())
    {
      xqtref_t argType = arg->get_return_type();
      if (TypeOps::is_subtype(tm,
                              *argType,
                              *GENV_TYPESYSTEM.ANY_NODE_TYPE_PLUS,
                              arg->get_loc()))
      {
        return rCtx.theEM->create_const_expr(sctx, udf, fo->get_loc(), true);
      }
    }
  }

  return NULL;
}


/*******************************************************************************
  fo is a logical "and" or "or" expr. If "and" then the shortcircuit_val is
  false, otherwise, shortcircuit_val is true.
********************************************************************************/
static expr* partial_eval_logic(
    fo_expr* fo,
    bool shortcircuit_val,
    RewriterContext& rCtx)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;
  TypeManager* tm = fo->get_type_manager();
  static_context* sctx = fo->get_sctx();
  user_function* udf = fo->get_udf();

  assert(udf == rCtx.theUDF);

  long nonConst1 = -1;
  long nonConst2 = -1;

  csize numArgs = fo->num_args();

  for (csize i = 0; i < numArgs; ++i)
  {
    const expr* arg = fo->get_arg(i);
    const const_expr* constArg = NULL;

    if ((constArg = dynamic_cast<const const_expr*>(arg)) != NULL)
    {
      if (constArg->get_val()->getEBV() == shortcircuit_val)
      {
        return rCtx.theEM->
        create_const_expr(sctx, udf, LOC(fo), (xs_boolean)shortcircuit_val);
      }
    }
    else
    {
      if (nonConst1 < 0)
      {
        nonConst1 = i;
      }
      else
      {
        nonConst2 = i;
        break;  // no rewrite anyway
      }
    }
  }

  if (nonConst1 < 0)
  {
    // All args are constant exprs
    return rCtx.theEM->create_const_expr(sctx, udf, LOC(fo), (xs_boolean) !shortcircuit_val);
  }

  if (nonConst2 < 0)
  {
    // Only one of the args is a constant expr. The non-const arg is pointed
    // to by nonConst1.

    expr* arg = fo->get_arg(nonConst1);

    if (! TypeOps::is_subtype(tm,
                              *arg->get_return_type(),
                              *rtm.BOOLEAN_TYPE_ONE,
                              arg->get_loc()))
    {
      arg = rCtx.theEM->create_fo_expr(sctx,
                                       udf,
                                       LOC(fo),
                                       BUILTIN_FUNC(FN_BOOLEAN_1),
                                       arg);

      arg = expr_tools::fix_annotations(arg);
    }

    return arg;
  }

  return NULL;
}


/*******************************************************************************
  count(expr) = int_const

  1. if int_const < 0  --> false
  2. if int_const == 0 --> fn:empty(expr)
  3. if int_const == 1 --> fn:exactly-one-noraise(expr)
  4. if int_const > 1  --> fn:exactly-one-noraise(fn:subsequence(expr, int_const, 2))
********************************************************************************/
static expr* partial_eval_eq(RewriterContext& rCtx, fo_expr& fo)
{
  int i;
  fo_expr* count_expr = NULL;
  const_expr* val_expr = NULL;

  static_context* sctx = fo.get_sctx();
  user_function* udf = fo.get_udf();

  assert(udf == rCtx.theUDF);

  for (i = 0; i < 2; i++)
  {
    if (NULL != (val_expr = dynamic_cast<const_expr*>(fo.get_arg(i))) &&
        NULL != (count_expr = dynamic_cast<fo_expr*>(fo.get_arg(1-i))) &&
        count_expr->get_func()->getKind() == FunctionConsts::FN_COUNT_1)
      break;
  }

  if (i == 2)
    return NULL;

  RootTypeManager& rtm = GENV_TYPESYSTEM;

  TypeManager* tm = fo.get_sctx()->get_typemanager();

  store::Item* val = val_expr->get_val();

  if (TypeOps::is_subtype(tm,
                          *tm->create_named_type(val->getType(),
                                                 TypeConstants::QUANT_ONE,
                                                 fo.get_loc(),
                                                 err::XPTY0004),
                          *rtm.INTEGER_TYPE_ONE,
                          fo.get_loc()))
  {
    xs_integer ival = val->getIntegerValue();

    if (ival < 0)
    {
      if (!count_expr->isNonDiscardable())
        return rCtx.theEM->create_const_expr(sctx, udf, LOC(val_expr), false);
    }
    else if (ival == 0)
    {
      return expr_tools::fix_annotations(rCtx.theEM->
             create_fo_expr(sctx,
                            udf,
                            fo.get_loc(),
                            BUILTIN_FUNC(FN_EMPTY_1),
                            count_expr->get_arg(0)));
    }
    else if (ival == 1)
    {
      return expr_tools::fix_annotations(rCtx.theEM->
             create_fo_expr(sctx,
                            udf,
                            fo.get_loc(),
                            BUILTIN_FUNC(OP_EXACTLY_ONE_NORAISE_1),
                            count_expr->get_arg(0)));
    }
    else
    {
      std::vector<expr*> args(3);
      args[0] = count_expr->get_arg(0);
      args[1] = val_expr;
      args[2] = rCtx.theEM->create_const_expr(sctx, udf, LOC(val_expr), xs_integer(2));

      expr* subseq_expr = expr_tools::fix_annotations(rCtx.theEM->
      create_fo_expr(sctx,
                     udf,
                     LOC(count_expr),
                     BUILTIN_FUNC(OP_ZORBA_SUBSEQUENCE_INT_3),
                     args));

      return expr_tools::fix_annotations(rCtx.theEM->
      create_fo_expr(sctx,
                     udf,
                     fo.get_loc(),
                     BUILTIN_FUNC(OP_EXACTLY_ONE_NORAISE_1),
                     subseq_expr));
    }
  }

  return NULL;
}


/*******************************************************************************

********************************************************************************/
static expr* partial_eval_return_clause(
    flwor_expr* flworExpr,
    bool& modified,
    RewriterContext& rCtx)
{
  expr* returnExpr = flworExpr->get_return_expr();

  const QueryLoc& loc = returnExpr->get_loc();
  static_context* sctx = returnExpr->get_sctx();
  user_function* udf = returnExpr->get_udf();

  assert(udf == rCtx.theUDF);

  if (returnExpr->get_expr_kind() == const_expr_kind ||
      (!returnExpr->isNonDiscardable() &&
       returnExpr->get_return_type()->card() == 1))
  {
    if (flworExpr->num_clauses() == 1)
    {
      modified = true;

      flwor_clause* c = flworExpr->get_clause(0);

      if (c->get_kind() == flwor_clause::for_clause)
      {
        return static_cast<for_clause*>(c)->get_expr();
      }
      else
      {
        assert(c->get_kind() == flwor_clause::let_clause);

        return rCtx.theEM->create_const_expr(sctx, udf, loc, 1);
      }
    }
    else if (returnExpr->get_expr_kind() != const_expr_kind)
    {
      modified = true;

      expr* newRet = rCtx.theEM->create_const_expr(sctx, udf, loc, 1);

      flworExpr->set_return_expr(newRet);

      return flworExpr;
    }
  }

  if (returnExpr->get_expr_kind() == flwor_expr_kind)
  {
    expr* newRet =
    partial_eval_return_clause(static_cast<flwor_expr*>(returnExpr),  modified, rCtx);

    if (newRet != returnExpr)
    {
      flworExpr->set_return_expr(newRet);
      assert(modified);
    }
  }

  return flworExpr;
}


/*******************************************************************************

********************************************************************************/

RULE_REWRITE_PRE(InlineFunctions)
{
  return NULL;
}

RULE_REWRITE_POST(InlineFunctions)
{
  if (node->get_expr_kind() == fo_expr_kind)
  {
    const fo_expr* fo = static_cast<const fo_expr *> (node);

    if (fo->get_func()->isUdf())
    {
      assert(fo->get_udf() == rCtx.theUDF);

      const user_function* udf = static_cast<const user_function*>(fo->get_func());
      expr* body = udf->getBody();

      if (//!udf->isSequential() &&
          body != NULL &&
          !udf->isExiting() &&
          udf->isLeaf())
      {
        const std::vector<var_expr*>& udfArgs = udf->getArgVars();

        expr::substitution_t subst;

        for (csize i = 0; i < udfArgs.size(); ++i)
        {
          var_expr* p = udfArgs[i];
          subst[p] = fo->get_arg(i);

          if (fo->get_arg(i)->is_sequential())
            return NULL;
        }

        body = body->clone(fo->get_udf(), subst);

        body->clear_annotations();

        function_trace_expr* dummy = rCtx.theEM->
        create_function_trace_expr(fo->get_udf(), body);
        
        dummy->setFunctionName(udf->getName());
        dummy->setFunctionArity((unsigned int)udf->getArgVars().size());
        dummy->setFunctionCallLocation(node->get_loc());
        dummy->setFunctionLocation(udf->getLoc());
        
        return dummy;
      }
    }
  }

  return NULL;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
