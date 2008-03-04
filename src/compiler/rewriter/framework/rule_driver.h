#ifndef XQP_RULE_DRIVER_H
#define XQP_RULE_DRIVER_H

#include <vector>
#include <boost/shared_ptr.hpp>
#include "common/shared_types.h"
#include "compiler/rewriter/framework/rewriter.h"

namespace zorba {

class RewriterContext;
class RewriteRule;

class RuleMajorDriver : public Rewriter {
  public:
    RuleMajorDriver();;
    virtual ~RuleMajorDriver();

    void rewrite(RewriterContext& rCtx);

  protected:
    typedef boost::shared_ptr<RewriteRule> rule_ptr_t;
    typedef std::vector<rule_ptr_t> rules_t;
    rules_t m_rules;

    void rewriteRuleMajor(RewriterContext& rCtx);
    expr_t rewriteRec(RewriterContext& rCtx, RewriteRule *rule, expr *parent, bool& modified);
};

}

#endif /* XQP_RULE_DRIVER_H */
/* vim:set ts=2 sw=2: */
