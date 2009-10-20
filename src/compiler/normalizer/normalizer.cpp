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
#include <typeinfo>
#include <iostream>

#include "types/root_typemanager.h"
#include "types/typeops.h"
#include "system/globalenv.h"

#include "context/static_context.h"

#include "compiler/normalizer/normalizer.h"
#include "compiler/expression/expr.h"
#include "compiler/api/compilercb.h"
#include "compiler/expression/expr_visitor.h"

#include "functions/signature.h"
#include "functions/function.h"

namespace zorba 
{

#define LOOKUP_FN( pfx, local, arity ) (sctx->lookup_fn (pfx, local, arity))
#define LOOKUP_OP1( local ) (m_cb->m_sctx->lookup_builtin_fn (":" local, 1))


static inline expr::expr_t wrap_in_atomization(
    short context,
    static_context *sctx,
    expr::expr_t e)
{
  fo_expr_t fo = new fo_expr(context, e->get_loc(), LOOKUP_FN("fn", "data", 1), e);
  return fo.getp();
}


static inline expr::expr_t wrap_in_type_conversion(
    short context,
    expr::expr_t e,
    xqtref_t type)
{
  expr::expr_t ph = new promote_expr(context, e->get_loc(), e, type);
  // TODO : Need to add convert_simple_operand
  return ph;
}


static inline expr::expr_t wrap_in_typematch(
    short context, 
    expr::expr_t e,
    xqtref_t type)
{
  // treat_expr should be avoided for updating expressions too,
  // but in that case "type" will be item()* anyway
  return TypeOps::is_subtype(*GENV_TYPESYSTEM.ITEM_TYPE_STAR, *type)
    ? e
    : new treat_expr(context, e->get_loc(), e, type, XPTY0004);
}


static inline void checkNonUpdating(const expr* lExpr)
{
  if (lExpr != 0 && lExpr->is_updating())
    ZORBA_ERROR_LOC(XUST0001, lExpr->get_loc());
}


/*******************************************************************************

********************************************************************************/
class normalizer : public expr_visitor 
{
  CompilerCB   * m_cb;

public:
  normalizer(CompilerCB* aCompilerCB) : m_cb(aCompilerCB) {}

  ~normalizer() { }

#define DEF_VISIT_METHODS( e )                  \
  bool begin_visit(e& node) { return true; }    \
  void end_visit(e& node) {}

DEF_VISIT_METHODS (expr)

DEF_VISIT_METHODS (debugger_expr)

DEF_VISIT_METHODS (wrapper_expr)

DEF_VISIT_METHODS (sequential_expr)

DEF_VISIT_METHODS (var_expr)

DEF_VISIT_METHODS (order_modifier)

DEF_VISIT_METHODS (eval_expr)



bool begin_visit(flwor_expr& node) 
{
  return true;
}


void end_visit(flwor_expr& node)
{
  for (unsigned i = 0; i < node.num_clauses(); i++) 
  {
    flwor_clause& c = *(node[i]);

    if (c.get_kind() == flwor_clause::where_clause) 
    {
    }
    else if (c.get_kind() == flwor_clause::order_clause)
    {
    }
    else if (c.get_kind() == flwor_clause::for_clause)
    {
      for_clause* fc = static_cast<for_clause *> (&c);

      xqtref_t vartype = fc->get_var()->get_type();
      if (vartype != NULL) 
      {
        if (TypeOps::is_empty(*vartype))
          ZORBA_ERROR_LOC_PARAM(XPTY0004, fc->get_loc(), "empty-sequence()", "");

        xqtref_t promote_type = m_cb->theRootSctx->get_typemanager()->
                                create_type(*vartype, TypeConstants::QUANT_STAR);

        expr_t e = fc->get_expr();
        fc->set_expr(wrap_in_typematch(m_cb->m_cur_sctx, e, promote_type));
      }
    }
    else if (c.get_kind() == flwor_clause::let_clause)
    {
      let_clause* lc = static_cast<let_clause *> (&c);

      xqtref_t vartype = lc->get_var()->get_type();
      if (vartype != NULL) 
      {
        expr_t e = lc->get_expr();
        lc->set_expr(wrap_in_typematch(m_cb->m_cur_sctx, e, vartype));
      }
    }
    else if (c.get_kind() == flwor_clause::window_clause)
    {
      window_clause* wc = static_cast<window_clause *> (&c);

      xqtref_t vartype = wc->get_var()->get_type();
      if (vartype != NULL) 
      {
        expr_t e = wc->get_expr();
        wc->set_expr(wrap_in_typematch(m_cb->m_cur_sctx, e, vartype));
      }
    }
  }
}


void end_visit (promote_expr&) 
{
}

bool begin_visit (promote_expr& node)
{
  checkNonUpdating(&*node.get_input());
  return true;
}


void end_visit (trycatch_expr&) 
{
}

bool begin_visit (trycatch_expr& node)
{
  checkNonUpdating(&*node.get_try_expr());
  return true;
}


void end_visit (if_expr&)
{
}

bool begin_visit(if_expr& node)
{
  return true;
}


void end_visit (fo_expr&) 
{
}

bool begin_visit (fo_expr& node)
{
  return true;
}


void end_visit (instanceof_expr&) 
{
}

bool begin_visit (instanceof_expr& node)
{
  checkNonUpdating(&*node.get_input());
  return true;
}


DEF_VISIT_METHODS (treat_expr)


void end_visit (castable_expr&) 
{
}

bool begin_visit (castable_expr& node)
{
  checkNonUpdating(&*node.get_input());
  return true;
}


void end_visit (cast_expr&) 
{
}

bool begin_visit (cast_expr& node)
{
  checkNonUpdating(&*node.get_input());
  return true;
}


void end_visit (name_cast_expr&) 
{
}

bool begin_visit (name_cast_expr& node)
{
  checkNonUpdating(&*node.get_input());
  return true;
}


void end_visit (validate_expr&) 
{
}

bool begin_visit (validate_expr& node)
{
  checkNonUpdating(&*node.get_expr());
  return true;
}


void end_visit (extension_expr&) 
{
}

bool begin_visit (extension_expr& node)
{
  checkNonUpdating(&*node.get_expr());
  return true;
}


DEF_VISIT_METHODS (relpath_expr)
DEF_VISIT_METHODS (axis_step_expr)
DEF_VISIT_METHODS (match_expr)
DEF_VISIT_METHODS (const_expr)
DEF_VISIT_METHODS (order_expr)


void end_visit (elem_expr&) 
{
}

bool begin_visit (elem_expr& node)
{
  //node.setQNameExpr(wrap_in_atomization(m_sctx, node.getQNameExpr()));
  checkNonUpdating(&*node.getQNameExpr());
  checkNonUpdating(&*node.getAttrs());
  checkNonUpdating(&*node.getContent());
  return true;
}


void end_visit (doc_expr&) 
{
}

bool begin_visit (doc_expr& node)
{
  checkNonUpdating(node.getContent());
  return true;
}


void end_visit (attr_expr&) 
{
}

bool begin_visit (attr_expr& node)
{
  assert (node.getQNameExpr() != NULL);

  checkNonUpdating(&*node.getQNameExpr());
  checkNonUpdating(&*node.getValueExpr());

  return true;
}


void end_visit (text_expr&) 
{
}

bool begin_visit (text_expr& node)
{
  checkNonUpdating(&*node.get_text());
  return true;
}


void end_visit (pi_expr&) 
{
}

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
DEF_VISIT_METHODS (while_expr)
DEF_VISIT_METHODS (flowctl_expr)

DEF_VISIT_METHODS (function_def_expr)

DEF_VISIT_METHODS (ft_select_expr)
DEF_VISIT_METHODS (ft_contains_expr)

};


void normalize_expr_tree(
    const char* norm_descr,
    CompilerCB* aCompilerCB,
    expr_t& root,
    const XQType* rType) 
{
  normalizer n (aCompilerCB);

  root->accept(n);

  if (rType != NULL)
  {
    if (TypeOps::is_builtin_simple(*rType)) 
    {
      root = wrap_in_atomization(aCompilerCB->m_cur_sctx, aCompilerCB->theRootSctx, root);
      root = wrap_in_type_conversion(aCompilerCB->m_cur_sctx, root, rType);
    }
    else 
    {
      root = wrap_in_typematch (aCompilerCB->m_cur_sctx, root, rType);
    }
  }

  if (aCompilerCB->theConfig.normalize_cb)
    aCompilerCB->theConfig.normalize_cb (&*root, norm_descr);
}

}

/* vim:set ts=2 sw=2: */
