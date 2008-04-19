#include "compiler/normalizer/normalizer.h"
#include "context/static_context.h"
#include "compiler/expression/expr.h"
#include "functions/signature.h"
#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "system/globalenv.h"
#include <iostream>

using namespace zorba;

#define LOOKUP_FN( pfx, local, arity ) static_cast<function *> (sctx->lookup_fn (pfx, local, arity))

static inline expr::expr_t wrap_in_bev(static_context *sctx, expr::expr_t e)
{
  expr::expr_t fh(new fo_expr(e->get_loc(), LOOKUP_FN("fn", "boolean", 1)));
  fo_expr *fp = static_cast<fo_expr *>(fh.getp());
  fp->add(e);
  return fh;
}

static inline expr::expr_t wrap_in_atomization(static_context *sctx, expr::expr_t e)
{
  expr::expr_t fh(new fo_expr(e->get_loc(), LOOKUP_FN("fn", "data", 1)));
  fo_expr *fp = static_cast<fo_expr *>(fh.getp());
  fp->add(e);
  return fh;
}

static inline expr::expr_t wrap_in_typematch(expr::expr_t e, xqtref_t type)
{
  return new treat_expr (e->get_loc (), e, type, ZorbaError::XPTY0004);
}

static inline expr::expr_t wrap_in_type_conversion(expr::expr_t e, xqtref_t type)
{
  expr::expr_t ph = new promote_expr(e->get_loc(), e, type);
  // TODO : Need to add convert_simple_operand
  return ph;
}

static inline void checkNonUpdating(const expr* lExpr)
{
  if (lExpr != 0 && lExpr->isUpdating())
    ZORBA_ERROR_LOC(ZorbaError::XUST0001, lExpr->get_loc());
}

bool normalizer::begin_visit(expr& /*node*/)
{
  return true;
}

bool normalizer::begin_visit(var_expr& /*node*/)
{
  return true;
}

bool normalizer::begin_visit(order_modifier& /*node*/)
{
  return true;
}

bool normalizer::begin_visit(flwor_expr& node)
{
  QueryLoc loc = node.get_loc ();
  expr::expr_t where_h = node.get_where();
  if (where_h.getp()) {
    node.set_where(wrap_in_bev(m_sctx, where_h));
  }
  uint32_t on = node.orderspec_count();
  for(uint32_t i = 0; i < on; ++i) {
    flwor_expr::orderspec_t& os = node.orderspec_at(i);
    os.first = wrap_in_atomization(m_sctx, os.first);
  }
  for (uint32_t i = 0; i < node.forlet_count (); i++) {
    flwor_expr::forletref_t clause = node [i];
    xqtref_t vartype = clause->get_var ()->get_type ();
    if (vartype != NULL) {
      bool is_for = clause->get_type () == forlet_clause::for_clause;
      if (is_for && TypeOps::is_empty (*vartype))
        ZORBA_ERROR_LOC (ZorbaError::XPTY0004, loc);
      xqtref_t promote_type = is_for ? m_sctx->get_typemanager()->create_type (*vartype, TypeConstants::QUANT_STAR) : vartype;
      expr_t e = clause->get_expr ();
      clause->set_expr (new treat_expr (e->get_loc (), e, promote_type, ZorbaError::XPTY0004));
    }
  }
  return true;
}

bool normalizer::begin_visit(case_clause& node)
{
  checkNonUpdating(&*node.var_h);
  return true;
}

bool normalizer::begin_visit(promote_expr& node)
{
  checkNonUpdating(&*node.get_input());
  return true;
}

bool normalizer::begin_visit(trycatch_expr& node)
{
  checkNonUpdating(&*node.get_try_expr());
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
  const signature& sign = node.get_signature();

  int n = node.size();
  for(int i = 0; i < n; ++i) {
    expr::expr_t arg = node[i];
    if (!node.isUpdating())
      checkNonUpdating(&*arg);
    const xqtref_t& arg_type = sign[i];
    xqtref_t arg_prime_type = TypeOps::prime_type(*arg_type);
    if (TypeOps::is_subtype(*arg_prime_type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE)) {
      arg = wrap_in_atomization(m_sctx, arg);
      arg = wrap_in_type_conversion(arg, arg_type);
    }
    else arg = wrap_in_typematch(arg, arg_type);

    node[i] = arg;
  }

  return true;
}

bool normalizer::begin_visit(ft_select_expr& /*node*/)
{
  return true;
}

bool normalizer::begin_visit(ft_contains_expr& /*node*/)
{
  return true;
}

bool normalizer::begin_visit(instanceof_expr& node)
{
  checkNonUpdating(&*node.get_input());
  return true;
}

bool normalizer::begin_visit(treat_expr& node)
{
  return true;
}

bool normalizer::begin_visit(castable_expr& node)
{
  checkNonUpdating(&*node.get_input());
  return true;
}

bool normalizer::begin_visit(cast_expr& node)
{
  checkNonUpdating(&*node.get_input());
  return true;
}

bool normalizer::begin_visit(name_cast_expr& node)
{
  checkNonUpdating(&*node.get_input());
  return true;
}

bool normalizer::begin_visit(validate_expr& node)
{
  checkNonUpdating(&*node.get_expr());
  return true;
}

bool normalizer::begin_visit(extension_expr& node)
{
  checkNonUpdating(&*node.get_expr());
  return true;
}

bool normalizer::begin_visit(relpath_expr& node)
{
  if (node.size() > 0) {
    expr_t ie = node[0];
    expr_t pe = new treat_expr(ie->get_loc(), ie, GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, ZorbaError::XPTY0019);
    node[0] = pe;
  }
  return true;
}

bool normalizer::begin_visit(axis_step_expr& node)
{
  return true;
}

bool normalizer::begin_visit(match_expr& /*node*/)
{
  return true;
}

bool normalizer::begin_visit(const_expr& /*node*/)
{
  return true;
}

bool normalizer::begin_visit(order_expr& /*node*/)
{
  return true;
}

bool normalizer::begin_visit(elem_expr& node)
{
  //node.setQNameExpr(wrap_in_atomization(m_sctx, node.getQNameExpr()));
  checkNonUpdating(&*node.getQNameExpr());
  checkNonUpdating(&*node.getAttrs());
  checkNonUpdating(&*node.getContent());
  return true;
}

bool normalizer::begin_visit(doc_expr& node)
{
  checkNonUpdating(node.getContent());
  return true;
}

// FIXME => static inline function (see also translator)
#define LOOKUP_OP1( local ) static_cast<function *> (m_sctx->lookup_builtin_fn (":" local, 1))

bool normalizer::begin_visit(attr_expr& node)
{
  assert (node.getQNameExpr() != NULL);

  checkNonUpdating(&*node.getQNameExpr());
  checkNonUpdating(&*node.getValueExpr());

  // node.setQNameExpr(wrap_in_atomization(m_sctx, node.getQNameExpr()));
  
  if (node.getValueExpr() != NULL) {
    rchandle<expr> lExpr = node.getValueExpr();
    fo_expr* lFoExpr = 0;
    if ((lFoExpr = dynamic_cast<fo_expr*>(&*lExpr)))
    {
      function* lTestFunc = LOOKUP_OP1("enclosed-expr");
      if (lFoExpr->get_func() == lTestFunc)
      {
        (*lFoExpr)[0] = wrap_in_atomization(m_sctx, (*lFoExpr)[0].getp());
        return true;
      }
    }
    node.setValueExpr(wrap_in_atomization(m_sctx, node.getValueExpr()));
  }

  return true;
}

#undef LOOKUP_OP1

bool normalizer::begin_visit(text_expr& node)
{
  checkNonUpdating(&*node.get_text());
  return true;
}

bool normalizer::begin_visit(pi_expr& node)
{
  checkNonUpdating(&*node.get_target_expr());
  return true;
}

bool normalizer::begin_visit(insert_expr&)
{
  return true;
}

bool normalizer::begin_visit(delete_expr&)
{
  return true;
}

bool normalizer::begin_visit(rename_expr&)
{
  return true;
}

bool normalizer::begin_visit(replace_expr&)
{
  return true;
}

bool normalizer::begin_visit(transform_expr&)
{
  return true;
}

void normalizer::end_visit(expr& /*node*/)
{
}

void normalizer::end_visit(var_expr& /*node*/)
{
}

void normalizer::end_visit(order_modifier& /*node*/)
{
}

void normalizer::end_visit(flwor_expr& /*node*/)
{
}

void normalizer::end_visit(case_clause& /*node*/)
{
}

void normalizer::end_visit(promote_expr& /*node*/)
{
}

void normalizer::end_visit(trycatch_expr& /*node*/)
{
}

void normalizer::end_visit(typeswitch_expr& /*node*/)
{
}

void normalizer::end_visit(if_expr& /*node*/)
{
}

void normalizer::end_visit(fo_expr& /*node*/)
{
}

void normalizer::end_visit(ft_select_expr& /*node*/)
{
}

void normalizer::end_visit(ft_contains_expr& /*node*/)
{
}

void normalizer::end_visit(instanceof_expr& /*node*/)
{
}

void normalizer::end_visit(treat_expr& /*node*/)
{
}

void normalizer::end_visit(castable_expr& /*node*/)
{
}

void normalizer::end_visit(cast_expr& /*node*/)
{
}

void normalizer::end_visit(name_cast_expr& /*node*/)
{
}

void normalizer::end_visit(validate_expr& /*node*/)
{
}

void normalizer::end_visit(extension_expr& /*node*/)
{
}

void normalizer::end_visit(relpath_expr& /*node*/)
{
}

void normalizer::end_visit(axis_step_expr& /*node*/)
{
}

void normalizer::end_visit(match_expr& /*node*/)
{
}

void normalizer::end_visit(const_expr& /*node*/)
{
}

void normalizer::end_visit(order_expr& /*node*/)
{
}

void normalizer::end_visit(elem_expr& /*node*/)
{
}

void normalizer::end_visit(doc_expr& /*node*/)
{
}

void normalizer::end_visit(attr_expr& /*node*/)
{
}

void normalizer::end_visit(text_expr& /*node*/)
{
}

void normalizer::end_visit(pi_expr& /*node*/)
{
}

bool normalizer::begin_visit (function_def_expr& /*v*/) {
  return true;
}

void normalizer::end_visit (function_def_expr &v) {
}

void normalizer::end_visit(insert_expr&)
{}

void normalizer::end_visit(delete_expr&)
{}

void normalizer::end_visit(replace_expr&)
{}

void normalizer::end_visit(rename_expr&)
{}

void normalizer::end_visit(transform_expr&)
{}

void zorba::normalize_expr_tree (const char *norm_descr, CompilerCB* aCompilerCB, expr_t root) {
  normalizer n (aCompilerCB);
  root->accept(n);
  if (aCompilerCB->m_config.print_normalized) {
    std::cout << "Expression tree for " << norm_descr << " after normalization:\n";
    root->put(std::cout) << std::endl;
  }
}

/* vim:set ts=2 sw=2: */
