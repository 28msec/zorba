#ifndef XQP_NORMALIZER_H
#define XQP_NORMALIZER_H

#include "compiler/expression/expr.h"
#include "compiler/expression/expr_visitor.h"

namespace xqp {

class normalizer : public expr_visitor {
  public:
    normalizer(static_context *ctx) : m_sctx(ctx) { }
    ~normalizer() { }

    bool begin_visit(expr&);
    bool begin_visit(var_expr&);
    bool begin_visit(order_modifier&);
    bool begin_visit(flwor_expr&);
    bool begin_visit(quantified_expr&);
    bool begin_visit(case_clause&);
    bool begin_visit(typeswitch_expr&);
    bool begin_visit(if_expr&);
    bool begin_visit(fo_expr&);
    bool begin_visit(ft_select_expr&);
    bool begin_visit(ft_contains_expr&);
    bool begin_visit(instanceof_expr&);
    bool begin_visit(treat_expr&);
    bool begin_visit(castable_expr&);
    bool begin_visit(cast_expr&);
    bool begin_visit(validate_expr&);
    bool begin_visit(extension_expr&);
    bool begin_visit(relpath_expr&);
    bool begin_visit(axis_step_expr&);
    bool begin_visit(match_expr&);
    bool begin_visit(const_expr&);
    bool begin_visit(order_expr&);
    bool begin_visit(elem_expr&);
    bool begin_visit(doc_expr&);
    bool begin_visit(compElem_expr&);
    bool begin_visit(attr_expr&);
    bool begin_visit(text_expr&);
    bool begin_visit(comment_expr&);
    bool begin_visit(pi_expr&);

    void end_visit(expr&);
    void end_visit(var_expr&);
    void end_visit(order_modifier&);
    void end_visit(flwor_expr&);
    void end_visit(quantified_expr&);
    void end_visit(case_clause&);
    void end_visit(typeswitch_expr&);
    void end_visit(if_expr&);
    void end_visit(fo_expr&);
    void end_visit(ft_select_expr&);
    void end_visit(ft_contains_expr&);
    void end_visit(instanceof_expr&);
    void end_visit(treat_expr&);
    void end_visit(castable_expr&);
    void end_visit(cast_expr&);
    void end_visit(validate_expr&);
    void end_visit(extension_expr&);
    void end_visit(relpath_expr&);
    void end_visit(axis_step_expr&);
    void end_visit(match_expr&);
    void end_visit(const_expr&);
    void end_visit(order_expr&);
    void end_visit(elem_expr&);
    void end_visit(doc_expr&);
    void end_visit(compElem_expr&);
    void end_visit(attr_expr&);
    void end_visit(text_expr&);
    void end_visit(comment_expr&);
    void end_visit(pi_expr&);

  private:
    static_context *m_sctx;
};

} /* namespace xqp */
#endif /* XQP_NORMALIZER_H */
/* vim:set ts=2 sw=2: */
