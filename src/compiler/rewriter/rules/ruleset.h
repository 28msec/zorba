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
#include "compiler/semantic_annotations/annotation_keys.h"


namespace zorba 
{

PREPOST_RULE(EchoNodes);

PREPOST_RULE(PlanPrinter);

PREPOST_RULE(MarkProducerNodeProps);

PREPOST_RULE(EliminateNodeOps);

PREPOST_RULE(SpecializeOperations);

PREPOST_RULE(EliminateTypeEnforcingOperations);

PREPOST_RULE(EliminateUnusedLetVars);

PREPOST_RULE(RefactorPredFLWOR);

PREPOST_RULE(MergeFLWOR);

PREPOST_RULE(EliminateExtraneousPathSteps);

PREPOST_RULE(MarkFreeVars);

PREPOST_RULE(InlineFunctions);

PREPOST_RULE(PartialEval);


/*******************************************************************************

********************************************************************************/
class FoldConst : public PrePostRewriteRule 
{
protected:
  bool  theFoldExpensiveOps;

public:     
  FoldConst(bool fold_expensive_ops) 
    :
    PrePostRewriteRule(RewriteRule::FoldConst, "FoldConst"),
    theFoldExpensiveOps(fold_expensive_ops)
  {
  }

protected:
  expr_t rewritePre(expr* node, RewriterContext& rCtx);

  expr_t rewritePost(expr* node, RewriterContext& rCtx);
};


/*******************************************************************************

********************************************************************************/
class MarkExprs : public RewriteRule 
{
public:
  MarkExprs() : RewriteRule(RewriteRule::MarkExprs, "MarkExprs") {}

  expr_t apply(RewriterContext& rCtx, expr* node, bool& modified);
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

  expr_t apply(RewriterContext& rCtx, expr* node, bool& modified);
};


/*******************************************************************************

********************************************************************************/
class HoistRule : public RewriteRule 
{
public:
  HoistRule() : RewriteRule(RewriteRule::IndexJoin, "Hoist") {}

  expr_t apply(RewriterContext& rCtx, expr* node, bool& modified);
};



/*******************************************************************************

********************************************************************************/
class IndexJoinRule : public RewriteRule 
{
public:
  IndexJoinRule() : RewriteRule(RewriteRule::IndexJoin, "IndexJoin") {}

  expr_t apply(RewriterContext& rCtx, expr* node, bool& modified);
};


#undef RULE


}

#endif /* ZORBA_REWRITE_RULE_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
