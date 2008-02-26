#ifndef XQP_RULE_DRIVER_H
#define XQP_RULE_DRIVER_H

#include <vector>
#include "common/shared_types.h"
#include "compiler/rewriter/framework/rewriter.h"

namespace xqp {

class RewriterContext;
class RewriteRule;

class RuleMajorDriver : public Rewriter {
  public:
    typedef std::vector<RewriteRule *> rules_t;

    RuleMajorDriver(const rules_t& rules);
    ~RuleMajorDriver();

    void rewrite(RewriterContext& rCtx);

  private:
    rules_t m_rules;

    void rewriteRuleMajor(RewriterContext& rCtx);
    expr_t rewriteRec(RewriterContext& rCtx, RewriteRule *rule, expr *parent, bool& modified);
};

}

#endif /* XQP_RULE_DRIVER_H */
/* vim:set ts=2 sw=2: */
