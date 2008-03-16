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
      name() { } \
      ~name() { } \
      expr_t rewritePre(expr *node, RewriterContext& rCtx); \
      expr_t rewritePost(expr *node, RewriterContext& rCtx); \
  }


RULE(EchoNodes);

RULE(MarkNodesWithNodeIdProperties);
RULE(EliminateDocOrderSort);

RULE(EliminateTypeEnforcingOperations);
RULE(EliminateUnusedLetVars);
RULE(EliminateExtraneousPathSteps);
RULE(MarkFreeVars);
RULE(MarkExpensiveOps);
RULE(MarkUnfoldableOps);

class FoldConst : public RewriteRule {
protected:
  bool fold_expensive_ops;
public:     
  FoldConst (bool fold_expensive_ops_) : fold_expensive_ops (fold_expensive_ops_) {}
  expr_t rewritePre(expr *node, RewriterContext& rCtx);
  expr_t rewritePost(expr *node, RewriterContext& rCtx);
};

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
