#include "compiler/rewriter/rules/ruleset.h"
#include "context/static_context.h"
#include "compiler/rewriter/tools/expr_tools.h"

namespace zorba {

RULE_REWRITE_PRE(MarkNodesWithNodeIdProperties)
{
  fo_expr *fo = dynamic_cast<fo_expr *>(node);
  if (fo != NULL) {
    const function *f = fo->get_func ();
    if (f == LOOKUP_FN("fn", "empty", 1)
        || f == LOOKUP_FN("fn", "exists", 1)
        || f == LOOKUP_FN("fn", "one-or-more", 1)
        || f == LOOKUP_FN ("fn", "max", 1)
        || f == LOOKUP_FN ("fn", "max", 2)
        || f == LOOKUP_FN ("fn", "min", 1)
        || f == LOOKUP_FN ("fn", "min", 2))
    {
      expr_t arg = (*fo)[0];
      arg->put_annotation(Annotation::IGNORES_DUPLICATE_NODES, TSVAnnotationValue::TRUE_VALUE);
      arg->put_annotation(Annotation::IGNORES_SORTED_NODES, TSVAnnotationValue::TRUE_VALUE);
    }
  }
  return NULL;
}

RULE_REWRITE_POST(MarkNodesWithNodeIdProperties)
{
  return NULL;
}

static bool can_remove_sort_distinct(const fo_expr *fo)
{
  TSVAnnotationValue *dnnr = static_cast<TSVAnnotationValue *>(fo->get_annotation(Annotation::IGNORES_DUPLICATE_NODES).get());
  TSVAnnotationValue *snnr = static_cast<TSVAnnotationValue *>(fo->get_annotation(Annotation::IGNORES_SORTED_NODES).get());
  return dnnr != NULL && dnnr->getValue() == TSVAnnotationValue::TSV_TRUE && snnr != NULL && dnnr->getValue() == TSVAnnotationValue::TSV_TRUE;
}

RULE_REWRITE_PRE(EliminateDocOrderSort)
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

RULE_REWRITE_POST(EliminateDocOrderSort)
{
  return NULL;
}

}
/* vim:set ts=2 sw=2: */
