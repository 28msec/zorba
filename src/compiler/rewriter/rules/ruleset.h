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
#pragma once
#ifndef ZORBA_COMPILER_REWRITER_RULESET_H
#define ZORBA_COMPILER_REWRITER_RULESET_H

#include <string>

#include "compiler/expression/expr_base.h"
#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/rewriter/rules/rule_base.h"


namespace zorba
{


class SourceFinder;


PREPOST_RULE(EchoNodes);

PREPOST_RULE(PlanPrinter);

PREPOST_RULE(EliminateNodeOps);

PREPOST_RULE(SpecializeOperations);

PREPOST_RULE(EliminateTypeEnforcingOperations);

PREPOST_RULE(RefactorPredFLWOR);

PREPOST_RULE(EliminateExtraneousPathSteps);

PREPOST_RULE(InlineFunctions);

PREPOST_RULE(PartialEval);


/*******************************************************************************

********************************************************************************/
class EliminateUnusedLetVars : public PrePostRewriteRule
{
protected:
  flwor_expr           * theFlwor;
  std::vector<expr**>    theRefs;

  /*
   * The maximum size (1+subexpressions) a FLWR expression is allowed to increase
   * as an effect of a variable folding.
   */
  static const int       FOLD_SIZE_INCREASE_LIMIT = 512;
  
  /*
   * The maximum size (1+subexpressions) a FLWR expression is allowed to be
   * before variable folding.
   */
  static const int       FOLD_FLWOR_SIZE_LIMIT = 2048;

public:
  EliminateUnusedLetVars()
    :
    PrePostRewriteRule(RewriteRule::EliminateUnusedLetVars, "EliminateUnusedLetVars"),
    theFlwor(NULL)
  {
    theRefs.reserve(32);
  }

protected:
  expr* rewritePre(expr* node, RewriterContext& rCtx);

  expr* rewritePost(expr* node, RewriterContext& rCtx);

  bool safe_to_fold_var(csize varPos, int& numRefs);

  bool safe_to_fold_var_rec(
      expr* node,
      csize varPos,
      var_expr* var,
      bool unsafe,
      bool isSafeVar,
      int& numRefs);

  bool should_fold_var(int numRefs, expr* domExpr);

  void subst_vars(
      const RewriterContext& rCtx,
      var_expr* var,
      expr* subst,
      int numRefs);
};


/*******************************************************************************

********************************************************************************/
class MergeFLWOR : public RewriteRule
{
public:
  MergeFLWOR()
    :
    RewriteRule(RewriteRule::MergeFLWOR, "MergeFLWOR")
  {
  }

  expr* apply(RewriterContext& rCtx, expr* node, bool& modified);
};


/*******************************************************************************

********************************************************************************/
class FoldConst : public RewriteRule
{
public:
  FoldConst()
    :
    RewriteRule(RewriteRule::FoldConst, "FoldConst")
  {
  }

  expr* apply(RewriterContext& rCtx, expr* node, bool& modified);
};


/*******************************************************************************

********************************************************************************/
class MarkExprs : public RewriteRule
{
protected:
  bool theIsLocal;

public:
  MarkExprs(bool local = false)
    :
    RewriteRule(RewriteRule::MarkExprs, "MarkExprs"),
    theIsLocal(local)
  {
  }

  void setLocal(bool v) { theIsLocal = v; }

  expr* apply(RewriterContext& rCtx, expr* node, bool& modified);
};


/*******************************************************************************

********************************************************************************/
class MarkFreeVars : public RewriteRule
{
public:
  MarkFreeVars()
    :
    RewriteRule(RewriteRule::MarkFreeVars, "MarkFreeVars")
  {
  }

  expr* apply(RewriterContext& rCtx, expr* node, bool& modified);
};


/*******************************************************************************

********************************************************************************/
class MarkConsumerNodeProps : public RewriteRule
{
public:
  MarkConsumerNodeProps()
    :
    RewriteRule(RewriteRule::MarkConsumerNodeProps, "MarkConsumerNodeProps")
  {
  }

  expr* apply(RewriterContext& rCtx, expr* node, bool& modified);
};


/*******************************************************************************

********************************************************************************/
class MarkProducerNodeProps : public RewriteRule
{
public:
  MarkProducerNodeProps()
    :
    RewriteRule(RewriteRule::MarkProducerNodeProps, "MarkProducerNodeProps")
  {
  }

  expr* apply(RewriterContext& rCtx, expr* node, bool& modified);
};


/*******************************************************************************

********************************************************************************/
class MarkNodeCopyProps : public RewriteRule
{
  typedef std::set<user_function*> UdfSet;

protected:
  SourceFinder   * theSourceFinder;

  UdfSet           theProcessedUDFs;

public:
  MarkNodeCopyProps()
    :
    RewriteRule(RewriteRule::MarkNodeCopyProps, "MarkNodeCopyProps")
  {
  }

  expr* apply(RewriterContext& rCtx, expr* node, bool& modified);

protected:
  void applyInternal(expr* node, bool deferred);

  void markSources(const std::vector<expr*>& sources);

  void findSourcesForNodeExtractors(expr* node);
};


}

#endif /* ZORBA_REWRITE_RULE_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
