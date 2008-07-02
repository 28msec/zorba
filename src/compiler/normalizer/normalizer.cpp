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
#include "compiler/normalizer/normalizer.h"
#include "context/static_context.h"
#include "compiler/expression/expr.h"
#include "functions/signature.h"
#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "system/globalenv.h"
#include <iostream>

namespace zorba {

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
  return new treat_expr (e->get_loc (), e, type, XPTY0004);
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
    ZORBA_ERROR_LOC(XUST0001, lExpr->get_loc());
}

class normalizer : public expr_visitor {
  static_context *m_sctx;

public:
  normalizer(CompilerCB* aCompilerCB) : m_sctx(aCompilerCB->m_sctx) { }
  ~normalizer() { }

#define DEF_VISIT_METHODS( e )                  \
  bool begin_visit (e& node) { return true; }   \
  void end_visit (e& node) {}

DEF_VISIT_METHODS (expr)

DEF_VISIT_METHODS (sequential_expr)

DEF_VISIT_METHODS (var_expr)

DEF_VISIT_METHODS (order_modifier)

DEF_VISIT_METHODS (eval_expr)

DEF_VISIT_METHODS (typeswitch_expr)

void end_visit (flwor_expr&) {}
bool begin_visit (flwor_expr& node)
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
        ZORBA_ERROR_LOC_PARAM (XPTY0004, loc, "empty-sequence()", "");
      xqtref_t promote_type = is_for ? m_sctx->get_typemanager()->create_type (*vartype, TypeConstants::QUANT_STAR) : vartype;
      expr_t e = clause->get_expr ();
      clause->set_expr (new treat_expr (e->get_loc (), e, promote_type, XPTY0004));
    }
  }
  return true;
}

void end_visit (case_clause&) {}
bool begin_visit (case_clause& node)
{
  checkNonUpdating(&*node.get_var_h());
  return true;
}

void end_visit (promote_expr&) {}
bool begin_visit (promote_expr& node)
{
  checkNonUpdating(&*node.get_input());
  return true;
}

void end_visit (trycatch_expr&) {}
bool begin_visit (trycatch_expr& node)
{
  checkNonUpdating(&*node.get_try_expr());
  return true;
}

void end_visit (if_expr&) {}
bool begin_visit (if_expr& node)
{
  node.set_cond_expr(wrap_in_bev(m_sctx, node.get_cond_expr()));
  return true;
}

void end_visit (fo_expr&) {}
bool begin_visit (fo_expr& node)
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

void end_visit (instanceof_expr&) {}
bool begin_visit (instanceof_expr& node)
{
  checkNonUpdating(&*node.get_input());
  return true;
}

DEF_VISIT_METHODS (treat_expr)

void end_visit (castable_expr&) {}
bool begin_visit (castable_expr& node)
{
  checkNonUpdating(&*node.get_input());
  return true;
}

void end_visit (cast_expr&) {}
bool begin_visit (cast_expr& node)
{
  checkNonUpdating(&*node.get_input());
  return true;
}

void end_visit (name_cast_expr&) {}
bool begin_visit (name_cast_expr& node)
{
  checkNonUpdating(&*node.get_input());
  return true;
}

void end_visit (validate_expr&) {}
bool begin_visit (validate_expr& node)
{
  checkNonUpdating(&*node.get_expr());
  return true;
}

void end_visit (extension_expr&) {}
bool begin_visit (extension_expr& node)
{
  checkNonUpdating(&*node.get_expr());
  return true;
}

void end_visit (relpath_expr&) {}
bool begin_visit (relpath_expr& node)
{
  if (node.size() > 0) {
    expr_t ie = node[0];
    expr_t pe = new treat_expr(ie->get_loc(), ie, GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR, XPTY0019);
    node[0] = pe;
  }
  return true;
}

DEF_VISIT_METHODS (axis_step_expr)
DEF_VISIT_METHODS (match_expr)
DEF_VISIT_METHODS (const_expr)
DEF_VISIT_METHODS (order_expr)

void end_visit (elem_expr&) {}
bool begin_visit (elem_expr& node)
{
  //node.setQNameExpr(wrap_in_atomization(m_sctx, node.getQNameExpr()));
  checkNonUpdating(&*node.getQNameExpr());
  checkNonUpdating(&*node.getAttrs());
  checkNonUpdating(&*node.getContent());
  return true;
}

void end_visit (doc_expr&) {}
bool begin_visit (doc_expr& node)
{
  checkNonUpdating(node.getContent());
  return true;
}

// FIXME => static inline function (see also translator)
#define LOOKUP_OP1( local ) static_cast<function *> (m_sctx->lookup_builtin_fn (":" local, 1))

void end_visit (attr_expr&) {}
bool begin_visit (attr_expr& node)
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

void end_visit (text_expr&) {}
bool begin_visit (text_expr& node)
{
  checkNonUpdating(&*node.get_text());
  return true;
}

void end_visit (pi_expr&) {}
bool begin_visit (pi_expr& node)
{
  checkNonUpdating(&*node.get_target_expr());
  return true;
}

DEF_VISIT_METHODS (insert_expr)
DEF_VISIT_METHODS (delete_expr)
DEF_VISIT_METHODS (rename_expr)
DEF_VISIT_METHODS (replace_expr)
DEF_VISIT_METHODS (transform_expr)
DEF_VISIT_METHODS (exit_expr)
DEF_VISIT_METHODS (function_def_expr)

DEF_VISIT_METHODS (ft_select_expr)
DEF_VISIT_METHODS (ft_contains_expr)

};

void normalize_expr_tree (const char *norm_descr, CompilerCB* aCompilerCB, expr_t root) {
  normalizer n (aCompilerCB);
  root->accept(n);
  if (aCompilerCB->m_config.normalize_cb)
    aCompilerCB->m_config.normalize_cb (&*root, norm_descr);
}

}

/* vim:set ts=2 sw=2: */
