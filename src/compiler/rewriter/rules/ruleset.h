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

PREPOST_RULE(MergeFLWOR);

PREPOST_RULE(EliminateExtraneousPathSteps);

PREPOST_RULE(InlineFunctions);

PREPOST_RULE(PartialEval);


/*******************************************************************************

********************************************************************************/
class EliminateUnusedLetVars : public PrePostRewriteRule
{
protected:
  flwor_expr                * theFlwor;
  std::vector<const expr*>    theRefPath;

public:
  EliminateUnusedLetVars()
    :
    PrePostRewriteRule(RewriteRule::EliminateUnusedLetVars, "EliminateUnusedLetVars"),
    theFlwor(NULL)
  {
    theRefPath.reserve(32);
  }

protected:
  expr* rewritePre(expr* node, RewriterContext& rCtx);

  expr* rewritePost(expr* node, RewriterContext& rCtx);

  bool safe_to_fold_var(csize varClausePos, int& numRefs);

  bool var_in_try_or_loop(const std::vector<const expr*>& path);
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

#if 1
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
#endif

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


/*******************************************************************************

********************************************************************************/
class HoistRule : public RewriteRule
{
public:
  HoistRule() : RewriteRule(RewriteRule::IndexJoin, "Hoist") {}

  expr* apply(RewriterContext& rCtx, expr* node, bool& modified);
};



/*******************************************************************************

********************************************************************************/
class IndexJoinRule : public RewriteRule
{
public:
  IndexJoinRule() : RewriteRule(RewriteRule::IndexJoin, "IndexJoin") {}

  expr* apply(RewriterContext& rCtx, expr* node, bool& modified);
};


}

#endif /* ZORBA_REWRITE_RULE_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
