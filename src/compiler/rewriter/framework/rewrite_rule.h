#ifndef ZORBA_REWRITE_RULE_H
#define ZORBA_REWRITE_RULE_H

#include <string>
#include "common/shared_types.h"

namespace zorba {

class CompilerCB;
class RewriterContext;

class RewriteRule {
  public:
    virtual ~RewriteRule() { }

    virtual const std::string& getRuleName() const = 0;

    virtual expr_t rewritePre(expr *node, RewriterContext& rCtx) = 0;
    virtual expr_t rewritePost(expr *node, RewriterContext& rCtx) = 0;
};

}

#endif /* ZORBA_REWRITE_RULE_H */
/* vim:set ts=2 sw=2: */
