#ifndef ZORBA_RULESET_H
#define ZORBA_RULESET_H

#include "compiler/expression/expr.h"
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
RULE(EliminateProducerNodeOps);
RULE(MarkProducerNodeProps);
// RULE(EliminateConsumerNodeOps);

RULE(EliminateTypeEnforcingOperations);
RULE(EliminateUnusedLetVars);
RULE(RefactorPredFLWOR);
RULE(EliminateExtraneousPathSteps);
RULE(MarkFreeVars);
RULE(MarkExpensiveOps);
RULE(MarkUnfoldableOps);

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
