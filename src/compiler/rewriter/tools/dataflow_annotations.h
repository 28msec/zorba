#ifndef ZORBA_DATAFLOW_ANNOTATIONS_H
#define ZORBA_DATAFLOW_ANNOTATIONS_H

#include "compiler/expression/expr.h"

namespace zorba {

class DataflowAnnotationsComputer {
  public:
    DataflowAnnotationsComputer(static_context *ctx)
      : m_ctx(ctx) { }
    ~DataflowAnnotationsComputer() { }

    void compute(expr *e);

  private:
    static_context *m_ctx;

    void compute_sequential_expr(sequential_expr *e);
    void compute_constructor_expr(constructor_expr *e);
    void compute_var_expr(var_expr *e);
    void compute_flwor_expr(flwor_expr *e);
    void compute_trycatch_expr(trycatch_expr *e);
    void compute_promote_expr(promote_expr *e);
    void compute_typeswitch_expr(typeswitch_expr *e);
    void compute_if_expr(if_expr *e);
    void compute_function_def_expr(function_def_expr *e);
    void compute_fo_expr(fo_expr *e);
    void compute_ft_contains_expr(ft_contains_expr *e);
    void compute_instanceof_expr(instanceof_expr *e);
    void compute_treat_expr(treat_expr *e);
    void compute_castable_expr(castable_expr *e);
    void compute_cast_expr(cast_expr *e);
    void compute_name_cast_expr(name_cast_expr *e);
    void compute_validate_expr(validate_expr *e);
    void compute_extension_expr(extension_expr *e);
    void compute_relpath_expr(relpath_expr *e);
    void compute_axis_step_expr(axis_step_expr *e);
    void compute_match_expr(match_expr *e);
    void compute_const_expr(const_expr *e);
    void compute_order_expr(order_expr *e);
    void compute_elem_expr(elem_expr *e);
    void compute_doc_expr(doc_expr *e);
    void compute_attr_expr(attr_expr *e);
    void compute_text_expr(text_expr *e);
    void compute_pi_expr(pi_expr *e);
    void default_walk(expr *e);
    bool generic_compute(expr *e);
};

}

#endif /* ZORBA_DATAFLOW_ANNOTATIONS_H */
/* vim:set ts=2 sw=2: */
