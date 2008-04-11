#include "compiler/expression/expr.h"
#include "compiler/rewriter/framework/rule_driver.h"
#include "compiler/rewriter/framework/rewrite_rule.h"
#include "compiler/rewriter/framework/rewriter_context.h"

#include "util/properties.h"

namespace zorba {

RuleMajorDriver::RuleMajorDriver() { }

RuleMajorDriver::~RuleMajorDriver() { }

void RuleMajorDriver::rewrite(RewriterContext& rCtx)
{
  rewriteRuleMajor(rCtx);
}

void RuleMajorDriver::rewriteRuleMajor(RewriterContext& rCtx)
{
  bool modified = false;
  rules_t::const_iterator end = m_rules.end();
  do {
    modified = false;

    for(rules_t::iterator i = m_rules.begin(); i != end; ++i) {
      expr_t newRoot = rewriteRec(rCtx, &**i, &*rCtx.getRoot(), modified);

      if (newRoot != NULL) {
        rCtx.setRoot(newRoot);
      }

      if (modified && Properties::instance()->printIntermediateOptimizations ()) {
        std::cout << "After " << (*i)->getRuleName () << ":" << std::endl;
        rCtx.getRoot ()->put (std::cout) << std::endl;
      }
    }
  } while(modified);
}

expr_t RuleMajorDriver::rewriteRec(RewriterContext& rCtx, RewriteRule *rule, expr *parent, bool& modified)
{
  expr_t result = NULL;
  expr_t newParent = rule->rewritePre(&*parent, rCtx);
  if (newParent != NULL) {
    parent = newParent;
    result = newParent;
    modified = true;
  }
  for(expr_iterator i = parent->expr_begin(); !i.done(); ++i) {
    expr_t new_e = rewriteRec(rCtx, rule, &**i, modified);
    if (new_e != NULL) {
      *i = &*new_e;
    }
  }
  newParent = rule->rewritePost(&*parent, rCtx);
  if (newParent != NULL) {
    result = newParent;
    modified = true;
  }
  return result;
}

}
/* vim:set ts=2 sw=2: */
