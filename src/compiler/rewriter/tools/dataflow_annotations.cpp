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
#include "compiler/rewriter/tools/dataflow_annotations.h"
#include "compiler/semantic_annotations/annotation_keys.h"
#include "compiler/semantic_annotations/tsv_annotation.h"
#include "types/typeops.h"
#include "context/static_context.h"

namespace zorba {

#define SORTED_NODES(e) e->put_annotation(AnnotationKey::PRODUCES_SORTED_NODES, TSVAnnotationValue::TRUE_VAL)
#define DISTINCT_NODES(e) e->put_annotation(AnnotationKey::PRODUCES_DISTINCT_NODES, TSVAnnotationValue::TRUE_VAL)
#define PROPOGATE_SORTED_NODES(src, tgt) tgt->put_annotation(AnnotationKey::PRODUCES_SORTED_NODES, src->get_annotation(AnnotationKey::PRODUCES_SORTED_NODES))
#define PROPOGATE_DISTINCT_NODES(src, tgt) tgt->put_annotation(AnnotationKey::PRODUCES_DISTINCT_NODES, src->get_annotation(AnnotationKey::PRODUCES_DISTINCT_NODES))
#define LOOKUP_FN( pfx, local, arity ) static_cast<function *> (m_ctx->lookup_fn (pfx, local, arity))

void DataflowAnnotationsComputer::compute(expr *e)
{
  switch(e->get_expr_kind()) {
    case sequential_expr_kind:
      compute_sequential_expr(static_cast<sequential_expr *>(e));
      break;

    case constructor_expr_kind:
      compute_constructor_expr(static_cast<constructor_expr *>(e));
      break;

    case var_expr_kind:
      compute_var_expr(static_cast<var_expr *>(e));
      break;

    case flwor_expr_kind:
      compute_flwor_expr(static_cast<flwor_expr *>(e));
      break;

    case trycatch_expr_kind:
      compute_trycatch_expr(static_cast<trycatch_expr *>(e));
      break;

    case promote_expr_kind:
      compute_promote_expr(static_cast<promote_expr *>(e));
      break;

    case typeswitch_expr_kind:
      compute_typeswitch_expr(static_cast<typeswitch_expr *>(e));
      break;

    case if_expr_kind:
      compute_if_expr(static_cast<if_expr *>(e));
      break;

    case function_def_expr_kind:
      compute_function_def_expr(static_cast<function_def_expr *>(e));
      break;

    case fo_expr_kind:
      compute_fo_expr(static_cast<fo_expr *>(e));
      break;

    case ft_contains_expr_kind:
      compute_ft_contains_expr(static_cast<ft_contains_expr *>(e));
      break;

    case instanceof_expr_kind:
      compute_instanceof_expr(static_cast<instanceof_expr *>(e));
      break;

    case treat_expr_kind:
      compute_treat_expr(static_cast<treat_expr *>(e));
      break;

    case castable_expr_kind:
      compute_castable_expr(static_cast<castable_expr *>(e));
      break;

    case cast_expr_kind:
      compute_cast_expr(static_cast<cast_expr *>(e));
      break;

    case name_cast_expr_kind:
      compute_name_cast_expr(static_cast<name_cast_expr *>(e));
      break;

    case validate_expr_kind:
      compute_validate_expr(static_cast<validate_expr *>(e));
      break;

    case extension_expr_kind:
      compute_extension_expr(static_cast<extension_expr *>(e));
      break;

    case relpath_expr_kind:
      compute_relpath_expr(static_cast<relpath_expr *>(e));
      break;

    case axis_step_expr_kind:
      compute_axis_step_expr(static_cast<axis_step_expr *>(e));
      break;

    case match_expr_kind:
      compute_match_expr(static_cast<match_expr *>(e));
      break;

    case const_expr_kind:
      compute_const_expr(static_cast<const_expr *>(e));
      break;

    case order_expr_kind:
      compute_order_expr(static_cast<order_expr *>(e));
      break;

    case elem_expr_kind:
      compute_elem_expr(static_cast<elem_expr *>(e));
      break;

    case doc_expr_kind:
      compute_doc_expr(static_cast<doc_expr *>(e));
      break;

    case attr_expr_kind:
      compute_attr_expr(static_cast<attr_expr *>(e));
      break;

    case text_expr_kind:
      compute_text_expr(static_cast<text_expr *>(e));
      break;

    case pi_expr_kind:
      compute_pi_expr(static_cast<pi_expr *>(e));
      break;

    default:
      break;
  }
}

void DataflowAnnotationsComputer::compute_sequential_expr(sequential_expr *e)
{
  default_walk(e);
  generic_compute(e);
}

void DataflowAnnotationsComputer::compute_constructor_expr(constructor_expr *e)
{
  default_walk(e);
  SORTED_NODES(e);
  DISTINCT_NODES(e);
}

void DataflowAnnotationsComputer::compute_var_expr(var_expr *e)
{
  if (!generic_compute(e)) {
    if (e->get_kind() == var_expr::let_var) {
      PROPOGATE_SORTED_NODES(e->get_flwor_clause()->get_expr().getp(), e);
      PROPOGATE_DISTINCT_NODES(e->get_flwor_clause()->get_expr().getp(), e);
    }
  }
}

void DataflowAnnotationsComputer::compute_flwor_expr(flwor_expr *e)
{
  flwor_expr::clause_list_t::iterator ci = e->clause_begin();
  flwor_expr::clause_list_t::iterator cend = e->clause_end();
  while(ci != cend) {
    flwor_expr::forletref_t& flc = *ci;
    compute(flc->get_expr().getp());
    ++ci;
  }
  expr *where = e->get_where().getp();
  if (where != NULL) {
    compute(where);
  }
  
  flwor_expr::orderspec_list_t::iterator oi = e->orderspec_begin();
  flwor_expr::orderspec_list_t::iterator oend = e->orderspec_end();
  while(oi != oend) {
    flwor_expr::orderspec_t& ospec = *oi;
    compute(ospec.first);
    ++oi;
  }

  compute(e->get_retval().getp());
  if (!generic_compute(e)) {
  }
}

void DataflowAnnotationsComputer::compute_trycatch_expr(trycatch_expr *e)
{
  default_walk(e);
  generic_compute(e);
}

void DataflowAnnotationsComputer::compute_promote_expr(promote_expr *e)
{
  default_walk(e);
  PROPOGATE_SORTED_NODES(e->get_input().getp(), e);
  PROPOGATE_DISTINCT_NODES(e->get_input().getp(), e);
}

void DataflowAnnotationsComputer::compute_typeswitch_expr(typeswitch_expr *e)
{
  default_walk(e);
  generic_compute(e);
}

void DataflowAnnotationsComputer::compute_if_expr(if_expr *e)
{
  default_walk(e);
  generic_compute(e);
}

void DataflowAnnotationsComputer::compute_function_def_expr(function_def_expr *e)
{
  default_walk(e);
  if (!generic_compute(e)) {
  }
}

void DataflowAnnotationsComputer::compute_fo_expr(fo_expr *e)
{
  default_walk(e);
  if (!generic_compute(e)) {
    const function *f = e->get_func();
    if (f == LOOKUP_FN("fn", "doc", 1)) {
      SORTED_NODES(e);
      DISTINCT_NODES(e);
    }
  }
}

void DataflowAnnotationsComputer::compute_ft_contains_expr(ft_contains_expr *e)
{
  default_walk(e);
  if (!generic_compute(e)) {
  }
}

void DataflowAnnotationsComputer::compute_instanceof_expr(instanceof_expr *e)
{
  default_walk(e);
  PROPOGATE_SORTED_NODES(e->get_input().getp(), e);
  PROPOGATE_DISTINCT_NODES(e->get_input().getp(), e);
}

void DataflowAnnotationsComputer::compute_treat_expr(treat_expr *e)
{
  default_walk(e);
  if (!generic_compute(e)) {
    PROPOGATE_SORTED_NODES(e->get_input().getp(), e);
    PROPOGATE_DISTINCT_NODES(e->get_input().getp(), e);
  }
}

void DataflowAnnotationsComputer::compute_castable_expr(castable_expr *e)
{
  default_walk(e);
  PROPOGATE_SORTED_NODES(e->get_input().getp(), e);
  PROPOGATE_DISTINCT_NODES(e->get_input().getp(), e);
}

void DataflowAnnotationsComputer::compute_cast_expr(cast_expr *e)
{
  default_walk(e);
  if (!generic_compute(e)) {
    PROPOGATE_SORTED_NODES(e->get_input().getp(), e);
    PROPOGATE_DISTINCT_NODES(e->get_input().getp(), e);
  }
}

void DataflowAnnotationsComputer::compute_name_cast_expr(name_cast_expr *e)
{
  default_walk(e);
  if (!generic_compute(e)) {
    PROPOGATE_SORTED_NODES(e->get_input().getp(), e);
    PROPOGATE_DISTINCT_NODES(e->get_input().getp(), e);
  }
}

void DataflowAnnotationsComputer::compute_validate_expr(validate_expr *e)
{
  default_walk(e);
  if (!generic_compute(e)) {
    PROPOGATE_SORTED_NODES(e->get_expr().getp(), e);
    PROPOGATE_DISTINCT_NODES(e->get_expr().getp(), e);
  }
}

void DataflowAnnotationsComputer::compute_extension_expr(extension_expr *e)
{
  default_walk(e);
  if (!generic_compute(e)) {
    PROPOGATE_SORTED_NODES(e->get_expr().getp(), e);
    PROPOGATE_DISTINCT_NODES(e->get_expr().getp(), e);
  }
}

void DataflowAnnotationsComputer::compute_relpath_expr(relpath_expr *e)
{
  default_walk(e);
  if (!generic_compute(e)) {
    int sz = e->size();
    bool non_single_fwd_axis = false;
    bool reverse_axis = false;
    for(int i = 1; i < sz; ++i) {
      axis_step_expr *ase = dynamic_cast<axis_step_expr *>((*e)[i].getp());
      if (ase == NULL) {
        return;
      }
      reverse_axis = reverse_axis || ase->is_reverse_axis();
      non_single_fwd_axis = non_single_fwd_axis || ((ase->getAxis() != axis_kind_child) && (ase->getAxis() != axis_kind_attribute));
    }
    if (!non_single_fwd_axis) {
      Annotation::value_ref_t sortedAnnot = (*e)[0]->get_annotation(AnnotationKey::PRODUCES_SORTED_NODES);
      if (sortedAnnot != NULL) {
        e->put_annotation(AnnotationKey::PRODUCES_SORTED_NODES, sortedAnnot);
      }
      Annotation::value_ref_t distinctAnnot = (*e)[0]->get_annotation(AnnotationKey::PRODUCES_DISTINCT_NODES);
      if (distinctAnnot != NULL) {
        e->put_annotation(AnnotationKey::PRODUCES_DISTINCT_NODES, distinctAnnot);
      }
    } else {
      xqtref_t crt = (*e)[0]->return_type(m_ctx);
      if (TypeOps::type_max_cnt(*crt) <= 1) {
        bool sorted = false;
        bool distinct = false;
        if (sz == 2) {
          distinct = true;
          sorted = !reverse_axis;
        } else {
          if (!non_single_fwd_axis) {
            sorted = true;
            distinct = true;
          }
        }
        e->put_annotation(AnnotationKey::PRODUCES_SORTED_NODES, TSVAnnotationValue::from_bool(sorted));
        e->put_annotation(AnnotationKey::PRODUCES_DISTINCT_NODES, TSVAnnotationValue::from_bool(distinct));
      }
    }
  }
}

void DataflowAnnotationsComputer::compute_axis_step_expr(axis_step_expr *e)
{
  default_walk(e);
  if (!generic_compute(e)) {
  }
}

void DataflowAnnotationsComputer::compute_match_expr(match_expr *e)
{
  default_walk(e);
  generic_compute(e);
}

void DataflowAnnotationsComputer::compute_const_expr(const_expr *e)
{
  default_walk(e);
  generic_compute(e);
}

void DataflowAnnotationsComputer::compute_order_expr(order_expr *e)
{
  default_walk(e);
  generic_compute(e);
}

void DataflowAnnotationsComputer::compute_elem_expr(elem_expr *e)
{
  default_walk(e);
  SORTED_NODES(e);
  DISTINCT_NODES(e);
}

void DataflowAnnotationsComputer::compute_doc_expr(doc_expr *e)
{
  default_walk(e);
  SORTED_NODES(e);
  DISTINCT_NODES(e);
}

void DataflowAnnotationsComputer::compute_attr_expr(attr_expr *e)
{
  default_walk(e);
  SORTED_NODES(e);
  DISTINCT_NODES(e);
}

void DataflowAnnotationsComputer::compute_text_expr(text_expr *e)
{
  default_walk(e);
  SORTED_NODES(e);
  DISTINCT_NODES(e);
}

void DataflowAnnotationsComputer::compute_pi_expr(pi_expr *e)
{
  default_walk(e);
  SORTED_NODES(e);
  DISTINCT_NODES(e);
}

void DataflowAnnotationsComputer::default_walk(expr *e)
{
  expr_iterator i = e->expr_begin();
  while(!i.done()) {
    expr *child = (*i).getp();
    if (child != NULL) {
      compute(child);
    }
    ++i;
  }
}

/**
 * Checks if the expression has a return type with a quantifier of
 * ONE or QUESTION. If so, the expression cannot have dup nodes
 * or nodes out of sorted order.
 */
bool DataflowAnnotationsComputer::generic_compute(expr *e)
{
  xqtref_t rt = e->return_type(m_ctx);
  TypeConstants::quantifier_t quant = TypeOps::quantifier(*rt);
  if (quant == TypeConstants::QUANT_ONE || quant == TypeConstants::QUANT_QUESTION) {
    SORTED_NODES(e);
    DISTINCT_NODES(e);
    return true;
  }
  return false;
}

}
/* vim:set ts=2 sw=2: */
