#include "compiler/rewriter/rules/ruleset.h"
#include "context/static_context.h"
#include "compiler/rewriter/tools/expr_tools.h"

namespace zorba {

RULE_REWRITE_PRE(MarkNodesWithNodeIdPropertiesRule)
{
  fo_expr *fo = dynamic_cast<fo_expr *>(node);
  if (fo != NULL) {
    function *empty = LOOKUP_FN("fn", "empty", 1);
    if (fo->get_func() == empty) {
      expr_t arg = (*fo)[0];
      arg->put_annotation("distinct-nodes-not-required", "true");
      arg->put_annotation("sorted-nodes-not-required", "true");
    }
  }
  return NULL;
}

RULE_REWRITE_POST(MarkNodesWithNodeIdPropertiesRule)
{
  return NULL;
}

static bool can_remove_sort_distinct(const fo_expr *fo)
{
  const std::string *dnnr = fo->get_annotation("distinct-nodes-not-required");
  const std::string *snnr = fo->get_annotation("sorted-nodes-not-required");
  return dnnr != NULL && (*dnnr) == "true" && snnr != NULL && (*snnr) == "true";
}

RULE_REWRITE_PRE(EliminateDocOrderSortRule)
{
  fo_expr *fo = dynamic_cast<fo_expr *>(node);
  if (fo != NULL) {
    function *dosFoExpr = LOOKUP_OP1("sort-distinct-nodes-asc-or-atomics");
    if (fo->get_func() == dosFoExpr && can_remove_sort_distinct(fo)) {
      expr_t arg = (*fo)[0];
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
