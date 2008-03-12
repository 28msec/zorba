#ifndef ZORBA_RULESET_H
#define ZORBA_RULESET_H

#include "compiler/expression/expr.h"
#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/rewriter/framework/rewrite_rule.h"

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

// Node id rules
RULE(MarkNodesWithNodeIdProperties);
RULE(EliminateDocOrderSort);
RULE(EliminateTypeEnforcingOperations);
RULE(EliminateUnusedLetVars);
RULE(EliminateExtraneousPathSteps);

#undef RULE

#define RULE_REWRITE_PRE(name) expr_t name::rewritePre(expr *node, RewriterContext& rCtx)
#define RULE_REWRITE_POST(name) expr_t name::rewritePost(expr *node, RewriterContext& rCtx)

}

#endif /* ZORBA_REWRITE_RULE_H */
/* vim:set ts=2 sw=2: */
