#include "compiler/rewriter/rules/ruleset.h"
#include "context/static_context.h"

#define LOOKUP_OP1( local ) static_cast<function *> (rCtx.getStaticContext()->lookup_builtin_fn (":" local, 1))

namespace zorba {

RULE_REWRITE_PRE(MarkNodesWithNodeIdPropertiesRule)
{
  return NULL;
}

RULE_REWRITE_POST(MarkNodesWithNodeIdPropertiesRule)
{
  return NULL;
}

RULE_REWRITE_PRE(EliminateDocOrderSortRule)
{
  fo_expr *fo = dynamic_cast<fo_expr *>(node);
  if (fo != NULL) {
    function *dosFoExpr = LOOKUP_OP1("sort-distinct-nodes-asc-or-atomics");
    if (fo->get_func() == dosFoExpr) {
      expr_t arg = (*fo)[0];
      // TODO - test for dups
      return arg;
    }
  }
  return NULL;
}

RULE_REWRITE_POST(EliminateDocOrderSortRule)
{
  return NULL;
}

}
/* vim:set ts=2 sw=2: */
