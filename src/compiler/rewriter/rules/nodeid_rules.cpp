#include "compiler/rewriter/rules/ruleset.h"
#include "context/static_context.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/expression/expr.h"
#include "functions/function.h"

using namespace std;

namespace zorba {

template<typename T> void exprs_to_holders (T exprs_begin, T exprs_end, vector <AnnotationHolder *> &anns)
{
  for (T i = exprs_begin; i < exprs_end; i++)
    anns.push_back (static_cast<AnnotationHolder *> (&* (*i)));
}

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
      arg->put_annotation(Annotation::IGNORES_DUP_NODES, TSVAnnotationValue::TRUE_VALUE);
      arg->put_annotation(Annotation::IGNORES_SORTED_NODES, TSVAnnotationValue::TRUE_VALUE);
    } else {
      vector <AnnotationHolder *> anns;
      exprs_to_holders (fo->begin (), fo->end (), anns);
      f->compute_annotation (node, anns, Annotation::IGNORES_DUP_NODES);
      f->compute_annotation (node, anns, Annotation::IGNORES_SORTED_NODES);
    }
  }
  return NULL;
}

static bool propogate_nodeid_props_to_flwor_variables(flwor_expr *flwor)
{
  bool result = false;
  uint32_t n = flwor->forlet_count();
  for(uint32_t i = 0; i < n; ++i) {
    flwor_expr::forletref_t& fl = (*flwor)[i];
    expr_t e = fl->get_expr();
    forlet_clause::varref_t v = fl->get_var();
    Annotation::value_ref_t snnr = fl->get_type() == forlet_clause::for_clause
      ? TSVAnnotationValue::TRUE_VALUE
      : e->get_annotation(Annotation::PRODUCES_SORTED_NODES);
    Annotation::value_ref_t dnnr = fl->get_type() == forlet_clause::for_clause
      ? TSVAnnotationValue::TRUE_VALUE
      : e->get_annotation(Annotation::PRODUCES_DISTINCT_NODES);

    if (snnr != NULL && v->get_annotation(Annotation::PRODUCES_SORTED_NODES) == NULL) {
      v->put_annotation(Annotation::PRODUCES_SORTED_NODES, snnr);
      result = true;
    }
    if (dnnr != NULL && v->get_annotation(Annotation::PRODUCES_DISTINCT_NODES) == NULL) {
      v->put_annotation(Annotation::PRODUCES_DISTINCT_NODES, dnnr);
      result = true;
    }
  }
  return result;
}

static bool propogate_up_nodeid_props(expr *target, expr *src)
{
  bool result = false;

  Annotation::value_ref_t snnr = src->get_annotation(Annotation::PRODUCES_SORTED_NODES);
  Annotation::value_ref_t dnnr = src->get_annotation(Annotation::PRODUCES_DISTINCT_NODES);

  if (snnr != NULL && target->get_annotation(Annotation::PRODUCES_SORTED_NODES) == NULL) {
    target->put_annotation(Annotation::PRODUCES_SORTED_NODES, snnr);
    result = true;
  }
  if (dnnr != NULL && target->get_annotation(Annotation::PRODUCES_DISTINCT_NODES) == NULL) {
    target->put_annotation(Annotation::PRODUCES_DISTINCT_NODES, dnnr);
    result = true;
  }

  return result;
}

RULE_REWRITE_POST(MarkNodesWithNodeIdProperties)
{
  switch(node->get_expr_kind()) {
    case flwor_expr_kind:
      {
        flwor_expr *flwor = static_cast<flwor_expr *>(node);
        if (propogate_nodeid_props_to_flwor_variables(flwor)) {
          return node;
        }
        if (propogate_up_nodeid_props(flwor, &*flwor->get_retval())) {
          return node;
        }
      }
      break;

    case trycatch_expr_kind:
      {
        trycatch_expr *tc = static_cast<trycatch_expr *>(node);
        for(expr_iterator i = tc->expr_begin(); !i.done(); ++i) {
          if (*i != NULL) {
          }
        }
      }
      break;

    default:
      break;
  }
  return NULL;
}

static bool can_remove_sort_distinct(const fo_expr *fo) {
  return fo->get_annotation(Annotation::IGNORES_SORTED_NODES) == TSVAnnotationValue::TRUE_VALUE
    && fo->get_annotation(Annotation::IGNORES_SORTED_NODES) == TSVAnnotationValue::TRUE_VALUE;
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
