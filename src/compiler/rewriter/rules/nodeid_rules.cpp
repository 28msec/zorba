#include "compiler/rewriter/rules/ruleset.h"
#include "context/static_context.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/expression/expr.h"
#include "types/typeops.h"
#include "functions/Sequences.h"

using namespace std;

namespace zorba {

static op_node_sort_distinct::nodes_or_atomics_t nodes_or_atomics (xqtref_t type) {
  xqtref_t pt = TypeOps::prime_type (*type);
  if (TypeOps::is_subtype (*pt, *GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE))
    return op_node_sort_distinct::NODES;
  else if (TypeOps::is_subtype (*pt, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE))
    return op_node_sort_distinct::ATOMICS;
  else
    return op_node_sort_distinct::MIXED;

}

static void propagate_down_nodeid_props(expr *src, expr *target) {
  Annotation::key_t k;
  k = AnnotationKey::IGNORES_SORTED_NODES; TSVAnnotationValue::update_annotation (target, k, src->get_annotation (k));
  k = AnnotationKey::IGNORES_DUP_NODES; TSVAnnotationValue::update_annotation (target, k, src->get_annotation (k));
}

template<typename T> void exprs_to_holders (T exprs_begin, T exprs_end, vector <AnnotationHolder *> &anns)
{
  for (T i = exprs_begin; i < exprs_end; i++)
    anns.push_back (static_cast<AnnotationHolder *> (&* (*i)));
}

static bool propagate_up_nodeid_props(expr *target, expr *src) {
  bool result = false;

  Annotation::value_ref_t snnr = src->get_annotation(AnnotationKey::PRODUCES_SORTED_NODES);
  Annotation::value_ref_t dnnr = src->get_annotation(AnnotationKey::PRODUCES_DISTINCT_NODES);

  if (snnr != NULL && target->get_annotation(AnnotationKey::PRODUCES_SORTED_NODES) == NULL) {
    target->put_annotation(AnnotationKey::PRODUCES_SORTED_NODES, snnr);
    result = true;
  }
  if (dnnr != NULL && target->get_annotation(AnnotationKey::PRODUCES_DISTINCT_NODES) == NULL) {
    target->put_annotation(AnnotationKey::PRODUCES_DISTINCT_NODES, dnnr);
    result = true;
  }

  return result;
}

static bool propagate_up_nodeid_props_to_flwor_variables(flwor_expr *flwor)
{
  bool result = false;
  uint32_t n = flwor->forlet_count();
  for(uint32_t i = 0; i < n; ++i) {
    flwor_expr::forletref_t& fl = (*flwor)[i];
    expr_t e = fl->get_expr();
    forlet_clause::varref_t v = fl->get_var();
    Annotation::value_ref_t snnr = fl->get_type() == forlet_clause::for_clause
      ? TSVAnnotationValue::TRUE_VALUE
      : e->get_annotation(AnnotationKey::PRODUCES_SORTED_NODES);
    Annotation::value_ref_t dnnr = fl->get_type() == forlet_clause::for_clause
      ? TSVAnnotationValue::TRUE_VALUE
      : e->get_annotation(AnnotationKey::PRODUCES_DISTINCT_NODES);

    if (snnr != NULL && v->get_annotation(AnnotationKey::PRODUCES_SORTED_NODES) == NULL) {
      v->put_annotation(AnnotationKey::PRODUCES_SORTED_NODES, snnr);
      result = true;
    }
    if (dnnr != NULL && v->get_annotation(AnnotationKey::PRODUCES_DISTINCT_NODES) == NULL) {
      v->put_annotation(AnnotationKey::PRODUCES_DISTINCT_NODES, dnnr);
      result = true;
    }
  }
  return result;
}

// If the result of a FLWOR ignores node order, than the sources of all
// FOR variables do too. This does not hold for dup nodes:
// (let $a := <u><v>1</v></u> let $x := ($a, $a) for $y in $x return <a>{$y}</a>)//u
static void mark_for_vars_ignoring_sort (flwor_expr *flwor) {
  Annotation::key_t k = AnnotationKey::IGNORES_SORTED_NODES;
  if (flwor->get_annotation (k) != TSVAnnotationValue::TRUE_VALUE)
    return;
  for (flwor_expr::clause_list_t::iterator i = flwor->clause_begin();
        i != flwor->clause_end(); i++) {
    flwor_expr::forletref_t ref = *i;
    forlet_clause::varref_t vref = ref->get_var();
    forlet_clause::varref_t pvref = ref->get_pos_var ();
    if (vref->get_kind() == var_expr::for_var && pvref == NULL)
      TSVAnnotationValue::update_annotation (ref->get_expr (), k, TSVAnnotationValue::TRUE_VALUE);
  }
}

// Assume all LET var values could ignore sort order and duplicate nodes,
// and allow expressions further down the tree to challenge this assumption.
static void init_let_vars_consumer_props (flwor_expr *flwor) {
  for (flwor_expr::clause_list_t::iterator i = flwor->clause_begin();
        i != flwor->clause_end(); i++)
  {
    flwor_expr::forletref_t ref = *i;
    forlet_clause::varref_t vref = ref->get_var();
    for (int j = 0; j < 2; j++) {
      Annotation::key_t k = j == 0 ? AnnotationKey::IGNORES_SORTED_NODES : AnnotationKey::IGNORES_DUP_NODES;
      if (vref->get_kind() == var_expr::let_var
          && vref->get_annotation (k) != TSVAnnotationValue::TRUE_VALUE
          && ref->get_expr ()->get_annotation (k) != TSVAnnotationValue::TRUE_VALUE)
      {
        vref->put_annotation (k, TSVAnnotationValue::TRUE_VALUE);
        ref->get_expr ()->put_annotation (k, TSVAnnotationValue::UNKNOWN_VALUE);
      }
    }
  }
}

// If no expression involving a LET var cares about sort order / dup nodes,
// mark the var value accordingly
static bool analyze_let_vars_consumer_props (flwor_expr *flwor) {
  bool modified = false;
  for (flwor_expr::clause_list_t::iterator i = flwor->clause_begin();
       i != flwor->clause_end(); i++)
  {
    flwor_expr::forletref_t ref = *i;
    forlet_clause::varref_t vref = ref->get_var();
    for (int j = 0; j < 2; j++) {
      Annotation::key_t k =
        j == 0 ? AnnotationKey::IGNORES_SORTED_NODES : AnnotationKey::IGNORES_DUP_NODES;
      
      if (vref->get_kind() == var_expr::let_var
          && vref->get_annotation (k) == TSVAnnotationValue::TRUE_VALUE
          && ref->get_expr ()->get_annotation (k) == TSVAnnotationValue::UNKNOWN_VALUE)
      {
        modified = true;
        ref->get_expr ()->put_annotation (k, TSVAnnotationValue::TRUE_VALUE);
      }
    }
  }
    
  return modified;
}

static bool mark_casts (expr_t input, xqtref_t target) {
  if (TypeOps::type_max_cnt (*target) <= 1) {
    TSVAnnotationValue::update_annotation (input, AnnotationKey::IGNORES_SORTED_NODES, TSVAnnotationValue::TRUE_VALUE);
    TSVAnnotationValue::update_annotation (input, AnnotationKey::IGNORES_DUP_NODES, TSVAnnotationValue::TRUE_VALUE);
    return true;
  }

  return false;
}

RULE_REWRITE_PRE(MarkConsumerNodeProps)
{
  switch (node->get_expr_kind ()) {
  case fo_expr_kind: {
    fo_expr *fo = static_cast<fo_expr *>(node);
    const function *f = fo->get_func ();
    if (f == LOOKUP_FN("fn", "empty", 1)
        || f == LOOKUP_FN("fn", "exists", 1)
        || f == LOOKUP_FN ("fn", "max", 1)
        || f == LOOKUP_FN ("fn", "max", 2)
        || f == LOOKUP_FN ("fn", "min", 1)
        || f == LOOKUP_FN ("fn", "min", 2))
    {
      expr_t arg = (*fo)[0];
      TSVAnnotationValue::update_annotation (arg, AnnotationKey::IGNORES_SORTED_NODES, TSVAnnotationValue::TRUE_VALUE);
      TSVAnnotationValue::update_annotation (arg, AnnotationKey::IGNORES_DUP_NODES, TSVAnnotationValue::TRUE_VALUE);
    } else if (f == LOOKUP_FN ("fn", "unordered", 1)
               || f == LOOKUP_FN ("fn", "count", 1)
               || f == LOOKUP_FN ("fn", "sum", 1)
               || f == LOOKUP_FN ("fn", "sum", 2)
               || f == LOOKUP_FN ("fn", "avg", 1)
               || f == LOOKUP_FN ("fn", "exactly-one", 1)
               || f == LOOKUP_OP1 ("exactly-one-noraise"))
    {
      expr_t arg = (*fo)[0];
      TSVAnnotationValue::update_annotation (arg, AnnotationKey::IGNORES_SORTED_NODES, TSVAnnotationValue::TRUE_VALUE);
      TSVAnnotationValue::update_annotation (arg, AnnotationKey::IGNORES_DUP_NODES, TSVAnnotationValue::FALSE_VALUE);
    } else if (f == LOOKUP_OP2 ("union")
               || f == LOOKUP_OP2 ("intersect")
               || f == LOOKUP_OP2 ("except"))
    {
      // Union, intersect and except CAN use sorted inputs, but do not require
      // them. For intersect and except, it's ALWAYS more efficient to sort
      // the output than to sort the inputs. For union, it's unclear.
      // In any case, if a sort is eliminated, it won't be missed, as other
      // stages can put it back in.
      for (int i = 0; i < 2; i++) {
        expr_t arg = (*fo) [i];
        TSVAnnotationValue::update_annotation (arg, AnnotationKey::IGNORES_SORTED_NODES, TSVAnnotationValue::TRUE_VALUE);
        TSVAnnotationValue::update_annotation (arg, AnnotationKey::IGNORES_DUP_NODES, TSVAnnotationValue::TRUE_VALUE);
      }
    } else {
      vector <AnnotationHolder *> anns;
      exprs_to_holders (fo->begin (), fo->end (), anns);
      f->compute_annotation (node, anns, AnnotationKey::IGNORES_DUP_NODES);
      f->compute_annotation (node, anns, AnnotationKey::IGNORES_SORTED_NODES);
    }
    break;
  }

  case if_expr_kind: {
    if_expr *ite = static_cast<if_expr *> (node);
    propagate_down_nodeid_props (node, ite->get_then_expr ());
    propagate_down_nodeid_props (node, ite->get_else_expr ());
    break;
  }

  case flwor_expr_kind: {
    flwor_expr *flwor = static_cast<flwor_expr *> (node);
    propagate_down_nodeid_props (node, flwor->get_retval ());
    mark_for_vars_ignoring_sort (flwor);
    init_let_vars_consumer_props (flwor);
    break;
  }

  case relpath_expr_kind: {
    expr_t arg = (*static_cast<relpath_expr *> (node)) [0];
    TSVAnnotationValue::update_annotation (arg, AnnotationKey::IGNORES_SORTED_NODES, TSVAnnotationValue::TRUE_VALUE);
    TSVAnnotationValue::update_annotation (arg, AnnotationKey::IGNORES_DUP_NODES, TSVAnnotationValue::TRUE_VALUE);
    break;
  }

  default:
    {
      cast_base_expr *ce = dynamic_cast<cast_base_expr *> (node);
      if (ce != NULL) {
        expr_t input = ce->get_input ();
        if (! mark_casts (input, ce->get_target_type ()))
          propagate_down_nodeid_props (node, input);
        break;
      }
    }
    
    {
      castable_base_expr *ce = dynamic_cast<castable_base_expr *> (node);
      if (ce != NULL) {
        mark_casts (ce->get_expr (), ce->get_type ());
        break;
      }
    }

    {
      for(expr_iterator i = node->expr_begin(); !i.done(); ++i) {
        TSVAnnotationValue::update_annotation (*i, AnnotationKey::IGNORES_SORTED_NODES, TSVAnnotationValue::FALSE_VALUE);
        TSVAnnotationValue::update_annotation (*i, AnnotationKey::IGNORES_DUP_NODES, TSVAnnotationValue::FALSE_VALUE);
      }
    }
    break;
  }

  return NULL;
}
RULE_REWRITE_POST(MarkConsumerNodeProps) {
  switch (node->get_expr_kind ()) {
  case flwor_expr_kind:
    return analyze_let_vars_consumer_props (static_cast<flwor_expr *> (node)) ? node : NULL;

  default: break;
  }

  return NULL;
}

RULE_REWRITE_PRE(MarkProducerNodeProps) { return NULL; }
RULE_REWRITE_POST(MarkProducerNodeProps)
{
  switch(node->get_expr_kind()) {
  case flwor_expr_kind: {
    flwor_expr *flwor = static_cast<flwor_expr *>(node);
    if (propagate_up_nodeid_props_to_flwor_variables(flwor))
      return node;  // TODO: minimize rewriting
    propagate_up_nodeid_props(flwor, &*flwor->get_retval());
    break;
  }

#if 0  // under construction
  case trycatch_expr_kind: {
    trycatch_expr *tc = static_cast<trycatch_expr *>(node);
    for(expr_iterator i = tc->expr_begin(); !i.done(); ++i) {
    }
    break;
  }
#endif

  case fo_expr_kind: {
    fo_expr *fo = static_cast<fo_expr *>(node);
    const function *f = fo->get_func ();
    const op_node_sort_distinct *nsdf = dynamic_cast<const op_node_sort_distinct *> (f);
    if (nsdf != NULL) {
      const bool *action = nsdf->action ();
    }
  }
    
  default:
    break;
  }
  return NULL;
}

RULE_REWRITE_PRE(EliminateProducerNodeOps)
{
  static_context *sctx = rCtx.getStaticContext ();
  fo_expr *fo = dynamic_cast<fo_expr *>(node);
  if (fo != NULL) {
    const function *f = fo->get_func ();
    if (f == LOOKUP_FN ("fn", "unordered", 1))
      return (*fo)[0];
    const op_node_sort_distinct *nsdf = dynamic_cast<const op_node_sort_distinct *> (f);
    if (nsdf != NULL) {
      const function *fmin = nsdf->min_action (sctx, node, NULL, nodes_or_atomics ((*fo) [0]->return_type (sctx)));
      if (fmin != NULL)
        fo->set_func (fmin);
      else
        return (*fo)[0];
    }
  }
  return NULL;
}

RULE_REWRITE_POST(EliminateProducerNodeOps) { return NULL; }

}
/* vim:set ts=2 sw=2: */
