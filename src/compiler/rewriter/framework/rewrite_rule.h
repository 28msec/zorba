#ifndef XQP_REWRITE_RULE_H
#define XQP_REWRITE_RULE_H

#include "common/shared_types.h"

namespace xqp {

class RewriterContext;

class RewriteRule {
  public:
    virtual ~RewriteRule() { }

    virtual expr_t rewritePre(expr *node, RewriterContext& rCtx) = 0;
    virtual expr_t rewritePost(expr *node, RewriterContext& rCtx) = 0;
};

}

#endif /* XQP_REWRITE_RULE_H */
/* vim:set ts=2 sw=2: */
