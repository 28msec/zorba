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
#ifndef ZORBA_RULESET_H
#define ZORBA_RULESET_H

#include "compiler/expression/expr_base.h"
#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/rewriter/framework/rewrite_rule.h"
#include "compiler/semantic_annotations/annotation_keys.h"
#include "compiler/semantic_annotations/tsv_annotation.h"

namespace zorba {

#define RULE(name) \
  class name : public RewriteRule { \
    public: \
      name() : m_ruleName(#name) { } \
      ~name() { } \
      const std::string& getRuleName() const { return m_ruleName; } \
      expr_t rewritePre(expr *node, RewriterContext& rCtx); \
      expr_t rewritePost(expr *node, RewriterContext& rCtx); \
    private: \
      std::string m_ruleName; \
  }


RULE(EchoNodes);

RULE(InferVarTypes);

RULE(MarkConsumerNodeProps);
RULE(MarkProducerNodeProps);
RULE(EliminateNodeOps);
RULE(ReplaceExprWithConstantOneWhenPossible);

RULE(EliminateTypeEnforcingOperations);
RULE(EliminateUnusedLetVars);
RULE(RefactorPredFLWOR);
RULE(EliminateExtraneousPathSteps);
RULE(MarkFreeVars);
RULE(MarkExpensiveOps);
RULE(MarkUnfoldableExprs);
RULE(MarkImpureExprs);

class FoldConst : public RewriteRule {
protected:
  bool fold_expensive_ops;
  std::string m_ruleName;
public:     
  FoldConst (bool fold_expensive_ops_) : fold_expensive_ops (fold_expensive_ops_), m_ruleName("FoldConst") {}
  const std::string& getRuleName() const { return m_ruleName; }
  expr_t rewritePre(expr *node, RewriterContext& rCtx);
  expr_t rewritePost(expr *node, RewriterContext& rCtx);
};

RULE(PartialEval);

#undef RULE

#define RULE_REWRITE_PRE(name) expr_t name::rewritePre(expr *node, RewriterContext& rCtx)
#define RULE_REWRITE_POST(name) expr_t name::rewritePost(expr *node, RewriterContext& rCtx)

}

#endif /* ZORBA_REWRITE_RULE_H */
/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
