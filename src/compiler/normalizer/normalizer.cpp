#include "compiler/normalizer/normalizer.h"
#include "functions/function.h"
#include "functions/signature.h"
#include "types/typesystem.h"
#include "system/globalenv.h"

using namespace xqp;

#define LOOKUP_FN( pfx, local, arity ) static_cast<function *> (sctx->lookup_fn (pfx, local, arity))

static inline expr::expr_t wrap_in_bev(static_context *sctx, expr::expr_t e)
{
  expr::expr_t fh(new fo_expr(e->get_loc()));
  fo_expr *fp = static_cast<fo_expr *>(fh.get_ptr());
  fp->add(e);
  fp->set_func(LOOKUP_FN("fn", "boolean", 1));
  return fh;
}

static inline expr::expr_t wrap_in_atomization(static_context *sctx, expr::expr_t e)
{
  expr::expr_t fh(new fo_expr(e->get_loc()));
  fo_expr *fp = static_cast<fo_expr *>(fh.get_ptr());
  fp->add(e);
  fp->set_func(LOOKUP_FN("fn", "data", 1));
  return fh;
}

static inline expr::expr_t wrap_in_typematch(expr::expr_t e, TypeSystem::xqtref_t type)
{
  // TODO : Need to add typematch_expr
  return e;
}

static inline expr::expr_t wrap_in_type_conversion(expr::expr_t e, TypeSystem::xqtref_t type)
{
  // TODO : Need to add convert_simple_operand
  return e;
}

bool normalizer::begin_visit(expr& node)
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
    node.set_where(wrap_in_bev(m_sctx, where_h));
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
  node.set_cond_expr(wrap_in_bev(m_sctx, node.get_cond_expr()));
  return true;
}

bool normalizer::begin_visit(fo_expr& node)
{
  const function *func = node.get_func();
  std::cout << "In fo_expr: " << func->get_fname()->getStringProperty() << endl;
  const signature& sign = func->get_signature();

  int n = sign.arg_count();
  for(int i = 0; i < n; ++i) {
    expr::expr_t arg = node[i];
    const TypeSystem::xqtref_t& arg_type = sign[i];
    std::cout << "Arg: " << i << " type: " << arg_type.get_ptr() << endl;
    TypeSystem::xqtref_t arg_prime_type = GENV_TYPESYSTEM.prime_type(*arg_type);
    std::cout << "Arg: " << i << " prime type: " << arg_prime_type.get_ptr() << endl;
    if (GENV_TYPESYSTEM.is_subtype(*arg_prime_type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE)) {
      arg = wrap_in_atomization(m_sctx, arg);
      arg = wrap_in_type_conversion(arg, arg_type);
    }

    if (GENV_TYPESYSTEM.quantifier(*arg_type) != TypeSystem::QUANT_STAR) {
      arg = wrap_in_typematch(arg, arg_type);
    }

    node[i] = arg;
  }

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

bool normalizer::begin_visit(const_expr& node)
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

bool normalizer::begin_visit(pi_expr& node)
{
  return true;
}

void normalizer::end_visit(expr& node)
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

void normalizer::end_visit(const_expr& node)
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

void normalizer::end_visit(pi_expr& node)
{
}


/* vim:set ts=2 sw=2: */
