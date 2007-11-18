#include "compiler/normalizer/normalizer.h"

using namespace xqp;

#define LOOKUP_FN( pfx, local ) static_cast<function *> (sctx_p->lookup_fn (pfx, local))

bool normalizer::begin_visit(expr& node)
{
  return true;
}

bool normalizer::begin_visit(empty_expr& node)
{
  return true;
}

bool normalizer::begin_visit(enclosed_expr& node)
{
  return true;
}

bool normalizer::begin_visit(expr_list& node)
{
  return true;
}

bool normalizer::begin_visit(var_expr& node)
{
  return true;
}

bool normalizer::begin_visit(order_modifier& node)
{
  return true;
}

bool normalizer::begin_visit(flwor_expr& node)
{
  expr::expr_t where_h = node.get_where();
  if (where_h.get_ptr()) {
    expr::expr_t fh(new fo_expr(where_h->get_loc()));
    fo_expr *fp = static_cast<fo_expr *>(fh.get_ptr());

    fp->add(where_h);
    // TODO - set function
    node.set_where(fh);
  }
  return true;
}

bool normalizer::begin_visit(quantified_expr& node)
{
  return true;
}

bool normalizer::begin_visit(case_clause& node)
{
  return true;
}

bool normalizer::begin_visit(typeswitch_expr& node)
{
  return true;
}

bool normalizer::begin_visit(if_expr& node)
{
  return true;
}

bool normalizer::begin_visit(fo_expr& node)
{
  return true;
}

bool normalizer::begin_visit(ft_select_expr& node)
{
  return true;
}

bool normalizer::begin_visit(ft_contains_expr& node)
{
  return true;
}

bool normalizer::begin_visit(instanceof_expr& node)
{
  return true;
}

bool normalizer::begin_visit(treat_expr& node)
{
  return true;
}

bool normalizer::begin_visit(castable_expr& node)
{
  return true;
}

bool normalizer::begin_visit(cast_expr& node)
{
  return true;
}

bool normalizer::begin_visit(unary_expr& node)
{
  return true;
}

bool normalizer::begin_visit(validate_expr& node)
{
  return true;
}

bool normalizer::begin_visit(extension_expr& node)
{
  return true;
}

bool normalizer::begin_visit(relpath_expr& node)
{
  return true;
}

bool normalizer::begin_visit(axis_step_expr& node)
{
  return true;
}

bool normalizer::begin_visit(match_expr& node)
{
  return true;
}

bool normalizer::begin_visit(literal_expr& node)
{
  return true;
}

bool normalizer::begin_visit(order_expr& node)
{
  return true;
}

bool normalizer::begin_visit(elem_expr& node)
{
  return true;
}

bool normalizer::begin_visit(doc_expr& node)
{
  return true;
}

bool normalizer::begin_visit(compElem_expr& node)
{
  return true;
}

bool normalizer::begin_visit(attr_expr& node)
{
  return true;
}

bool normalizer::begin_visit(text_expr& node)
{
  return true;
}

bool normalizer::begin_visit(comment_expr& node)
{
  return true;
}

bool normalizer::begin_visit(pi_expr& node)
{
  return true;
}

void normalizer::end_visit(expr& node)
{
}

void normalizer::end_visit(empty_expr& node)
{
}

void normalizer::end_visit(enclosed_expr& node)
{
}

void normalizer::end_visit(expr_list& node)
{
}

void normalizer::end_visit(var_expr& node)
{
}

void normalizer::end_visit(order_modifier& node)
{
}

void normalizer::end_visit(flwor_expr& node)
{
}

void normalizer::end_visit(quantified_expr& node)
{
}

void normalizer::end_visit(case_clause& node)
{
}

void normalizer::end_visit(typeswitch_expr& node)
{
}

void normalizer::end_visit(if_expr& node)
{
}

void normalizer::end_visit(fo_expr& node)
{
}

void normalizer::end_visit(ft_select_expr& node)
{
}

void normalizer::end_visit(ft_contains_expr& node)
{
}

void normalizer::end_visit(instanceof_expr& node)
{
}

void normalizer::end_visit(treat_expr& node)
{
}

void normalizer::end_visit(castable_expr& node)
{
}

void normalizer::end_visit(cast_expr& node)
{
}

void normalizer::end_visit(unary_expr& node)
{
}

void normalizer::end_visit(validate_expr& node)
{
}

void normalizer::end_visit(extension_expr& node)
{
}

void normalizer::end_visit(relpath_expr& node)
{
}

void normalizer::end_visit(axis_step_expr& node)
{
}

void normalizer::end_visit(match_expr& node)
{
}

void normalizer::end_visit(literal_expr& node)
{
}

void normalizer::end_visit(order_expr& node)
{
}

void normalizer::end_visit(elem_expr& node)
{
}

void normalizer::end_visit(doc_expr& node)
{
}

void normalizer::end_visit(compElem_expr& node)
{
}

void normalizer::end_visit(attr_expr& node)
{
}

void normalizer::end_visit(text_expr& node)
{
}

void normalizer::end_visit(comment_expr& node)
{
}

void normalizer::end_visit(pi_expr& node)
{
}


/* vim:set ts=2 sw=2: */
