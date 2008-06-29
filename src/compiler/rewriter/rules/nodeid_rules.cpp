/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "context/static_context.h"

#include "compiler/rewriter/rules/ruleset.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/rewriter/tools/dataflow_annotations.h"
#include "compiler/rewriter/framework/rule_driver.h"

#include "compiler/expression/expr.h"

#include "types/typeops.h"

#include "functions/nodeid_internal.h"

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

// If the result of a FLWOR ignores node order, than the sources of all
// FOR variables do too. This does not hold for dup nodes:
// (let $a := <u><v>1</v></u> let $x := ($a, $a) for $y in $x return <a>{$y}</a>)//u
static void mark_for_vars_ignoring_sort (flwor_expr *flwor) {
  Annotation::key_t k = AnnotationKey::IGNORES_SORTED_NODES;
  Annotation::value_ref_t v = flwor->get_annotation (k);
  for (flwor_expr::clause_list_t::iterator i = flwor->clause_begin();
        i != flwor->clause_end(); i++) {
    flwor_expr::forletref_t ref = *i;
    forlet_clause::varref_t vref = ref->get_var();
    forlet_clause::varref_t pvref = ref->get_pos_var ();
    if (vref->get_kind() == var_expr::for_var) {
      TSVAnnotationValue::update_annotation (ref->get_expr (), k, (pvref == NULL) ? v : TSVAnnotationValue::FALSE_VAL);
    }
  }
}

// Assume all LET var values could ignore sort order and duplicate nodes,
// and allow expressions further down the tree to challenge this assumption.
static void init_let_vars_consumer_props (flwor_expr *flwor) {
  for (flwor_expr::clause_list_t::iterator i = flwor->clause_begin();
        i != flwor->clause_end(); i++)
  {
    int todo = 0;
    flwor_expr::forletref_t ref = *i;
    forlet_clause::varref_t vref = ref->get_var();
    for (int j = 0; j < 2; j++) {
      Annotation::key_t k = j == 0 ? AnnotationKey::IGNORES_SORTED_NODES : AnnotationKey::IGNORES_DUP_NODES;
      if (vref->get_kind() == var_expr::let_var) {
        Annotation::value_ref_t v = vref->get_annotation (k);
        TSVAnnotationValue::update_annotation (ref->get_expr (), k, v);
        if (v != TSVAnnotationValue::TRUE_VAL)
        {
          vref->put_annotation (k, TSVAnnotationValue::TRUE_VAL);
          todo |= (1 << j);
        }
      }
    }

    if (todo != 0)
      vref->put_annotation (AnnotationKey::LET_VAR_NODEID_ANALYSIS, Annotation::value_ref_t (new IntAnnotationValue (todo)));
  }
}

// If no expression involving a LET var cares about sort order / dup nodes,
// mark the var value accordingly
static bool analyze_let_vars_consumer_props (flwor_expr *flwor) {
  bool modified = false;

  for (flwor_expr::clause_list_t::reverse_iterator i = flwor->clause_rbegin();
       i != flwor->clause_rend(); i++)
  {
    flwor_expr::forletref_t ref = *i;
    forlet_clause::varref_t vref = ref->get_var();
    for (int j = 0; j < 2; j++) {
      Annotation::key_t k =
        j == 0 ? AnnotationKey::IGNORES_SORTED_NODES : AnnotationKey::IGNORES_DUP_NODES;
      
      Annotation::value_ref_t analysis_ann = vref->get_annotation (AnnotationKey::LET_VAR_NODEID_ANALYSIS);
      if (vref->get_kind() == var_expr::let_var
          && analysis_ann != NULL
          && 0 != ((1 << j) & static_cast<IntAnnotationValue *> (analysis_ann.get ())->n))
      {
        Annotation::value_ref_t v = vref->get_annotation (k);
        TSVAnnotationValue::update_annotation (ref->get_expr (), k, v);
        if (v == TSVAnnotationValue::TRUE_VAL) {
          modified = true;
        }
      }

    }
    vref->remove_annotation (AnnotationKey::LET_VAR_NODEID_ANALYSIS);
  }
    
  return modified;
}

  static void mark_casts (cast_or_castable_base_expr *node, expr_t input, static_context *sctx) {
    xqtref_t target = node->get_target_type ();
    if (TypeOps::is_empty (*target)) {
      TSVAnnotationValue::update_annotation (input, AnnotationKey::IGNORES_SORTED_NODES, TSVAnnotationValue::TRUE_VAL);
      TSVAnnotationValue::update_annotation (input, AnnotationKey::IGNORES_DUP_NODES, TSVAnnotationValue::TRUE_VAL);
      return;
    }

    bool is_cast = dynamic_cast<cast_base_expr *> (input.getp ()) != NULL;

    TypeConstants::quantifier_t q = TypeOps::quantifier (*target);

    if (! is_cast || q == TypeConstants::QUANT_ONE || q == TypeConstants::QUANT_QUESTION) {
      TSVAnnotationValue::update_annotation (input, AnnotationKey::IGNORES_SORTED_NODES, TSVAnnotationValue::TRUE_VAL);
    } else if (is_cast) {
      TSVAnnotationValue::update_annotation (input, AnnotationKey::IGNORES_SORTED_NODES,
                                             TSVAnnotationValue::from_bool (node->get_annotation (AnnotationKey::IGNORES_DUP_NODES) == TSVAnnotationValue::TRUE_VAL));
    }

    bool ignores_dups =
      q == TypeConstants::QUANT_STAR
      || (q == TypeConstants::QUANT_PLUS
          && TypeOps::type_min_cnt (*input->return_type (sctx)) >= 1);
    if (is_cast)
      ignores_dups = ignores_dups && node->get_annotation (AnnotationKey::IGNORES_DUP_NODES) == TSVAnnotationValue::TRUE_VAL;
    TSVAnnotationValue::update_annotation (input, AnnotationKey::IGNORES_DUP_NODES,
                                           TSVAnnotationValue::from_bool (ignores_dups));
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
      TSVAnnotationValue::update_annotation (arg, AnnotationKey::IGNORES_SORTED_NODES, TSVAnnotationValue::TRUE_VAL);
      TSVAnnotationValue::update_annotation (arg, AnnotationKey::IGNORES_DUP_NODES, TSVAnnotationValue::TRUE_VAL);
    } else if (f == LOOKUP_FN ("fn", "unordered", 1)
               || f == LOOKUP_FN ("fn", "count", 1)
               || f == LOOKUP_FN ("fn", "sum", 1)
               || f == LOOKUP_FN ("fn", "sum", 2)
               || f == LOOKUP_FN ("fn", "avg", 1)
               || f == LOOKUP_FN ("fn", "exactly-one", 1)
               || f == LOOKUP_OP1 ("exactly-one-noraise"))
    {
      expr_t arg = (*fo)[0];
      TSVAnnotationValue::update_annotation (arg, AnnotationKey::IGNORES_SORTED_NODES, TSVAnnotationValue::TRUE_VAL);
      TSVAnnotationValue::update_annotation (arg, AnnotationKey::IGNORES_DUP_NODES, TSVAnnotationValue::FALSE_VAL);
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
        TSVAnnotationValue::update_annotation (arg, AnnotationKey::IGNORES_SORTED_NODES, TSVAnnotationValue::TRUE_VAL);
        TSVAnnotationValue::update_annotation (arg, AnnotationKey::IGNORES_DUP_NODES, TSVAnnotationValue::TRUE_VAL);
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
    init_let_vars_consumer_props (flwor);
    mark_for_vars_ignoring_sort (flwor);
    propagate_down_nodeid_props (node, flwor->get_retval ());
    break;
  }

  case relpath_expr_kind: {
    expr_t arg = (*static_cast<relpath_expr *> (node)) [0];
    TSVAnnotationValue::update_annotation (arg, AnnotationKey::IGNORES_SORTED_NODES, TSVAnnotationValue::TRUE_VAL);
    TSVAnnotationValue::update_annotation (arg, AnnotationKey::IGNORES_DUP_NODES, TSVAnnotationValue::TRUE_VAL);
    break;
  }

  default:
    {
      cast_or_castable_base_expr *ce = dynamic_cast<cast_base_expr *> (node);
      if (ce != NULL) {
        expr_t input = ce->get_input ();
        mark_casts (ce, input, rCtx.getStaticContext ());
        break;
      }
    }

    {
      for(expr_iterator i = node->expr_begin(); !i.done(); ++i) {
        TSVAnnotationValue::update_annotation (*i, AnnotationKey::IGNORES_SORTED_NODES, TSVAnnotationValue::FALSE_VAL);
        TSVAnnotationValue::update_annotation (*i, AnnotationKey::IGNORES_DUP_NODES, TSVAnnotationValue::FALSE_VAL);
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

RULE_REWRITE_PRE(MarkProducerNodeProps)
{
  if (rCtx.getRoot().getp() == node) {
    DataflowAnnotationsComputer computer(rCtx.getStaticContext());
    computer.compute(node);
  }
  return NULL;
}

RULE_REWRITE_POST(MarkProducerNodeProps)
{
  return NULL;
}

RULE_REWRITE_PRE(EliminateNodeOps)
{
  static_context *sctx = rCtx.getStaticContext ();
  fo_expr *fo = dynamic_cast<fo_expr *>(node);
  if (fo != NULL) {
    const function *f = fo->get_func ();
    if (f == LOOKUP_FN ("fn", "unordered", 1))
      return (*fo)[0];
    const op_node_sort_distinct *nsdf = dynamic_cast<const op_node_sort_distinct *> (f);
    if (nsdf != NULL) {
      const function *fmin = nsdf->min_action (sctx, node, (*fo)[0], nodes_or_atomics ((*fo) [0]->return_type (sctx)));
      if (fmin != NULL) {
        fo->set_func (fmin);
      }
      else {
        // re-compute IGNORES_*
        fo->set_func (LOOKUP_FN ("fn", "reverse", 1));  // HACK: need fn:identity here
        auto_ptr<Rewriter> rw (new SingletonRuleMajorDriverBase (RuleMajorDriver::rule_ptr_t (new MarkConsumerNodeProps ())));
        rw->rewrite (rCtx);
        return (*fo)[0];
      }
    }
  }
  return NULL;
}

RULE_REWRITE_POST(EliminateNodeOps) { return NULL; }

}
/* vim:set ts=2 sw=2: */
