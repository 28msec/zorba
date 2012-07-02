/*
 * Copyright 2006-2012 The FLWOR Foundation.
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

#pragma once
#ifndef ZORBA_COMPILER_EXPRMANAGER_H
#define ZORBA_COMPILER_EXPRMANAGER_H

#include "expr_classes.h"
#include "expr.h"
#include "script_exprs.h"
#include "flwor_expr.h"
#include "ftnode.h"

#include "mem_manager.h"

namespace zorba
{

class ExprManager
{
public:
  ExprManager();
  ~ExprManager();

  expr* reg(expr*);

private:
  std::list<expr*> theExprs;
  MemoryManager memory;

private:
  //An ExprManager is the only objecto to handle a collection of Exprs and
  //the memory in which they recide. It makes no sense to copy it.
  ExprManager(const ExprManager&);
  ExprManager& operator= (const ExprManager&);

public:
  MemoryManager& getMemory() {return memory;}

public:
  if_expr* create_if_expr(static_context* sctx, const QueryLoc& loc,
                          expr_t cond_expr, expr_t then_expr,
                          expr_t else_expr);

  order_expr* create_order_expr(static_context* sctx, const QueryLoc& loc,
                                order_expr::order_type_t, expr_t);

  validate_expr* create_validate_expr(static_context*, const QueryLoc&,
                                      ParseConstants::validation_mode_t,
                                      const store::Item_t& aTypeName,
                                      expr_t validated,
                                      rchandle<TypeManager>);


  cast_expr* create_cast_expr(static_context* sctx, const QueryLoc&,
                                expr_t, xqtref_t);


  treat_expr* create_treat_expr(
        static_context* sctx,
        const QueryLoc&,
        expr_t,
        xqtref_t,
        Error const&,
        bool check_prime = true,
        store::Item_t fnQname = NULL);


  promote_expr* create_promote_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr_t input,
      xqtref_t type,
      store::Item_t fnQname = NULL);

  castable_expr* create_castable_expr(
          static_context* sctx,
          const QueryLoc&,
          expr_t,
          xqtref_t);

  instanceof_expr* create_instanceof_expr(
      static_context* sctx,
      const QueryLoc&,
      expr_t,
      xqtref_t,
      bool checkPrimeOnly = false);

  name_cast_expr* create_name_cast_expr(
        static_context* sctx,
        const QueryLoc&,
        expr_t,
        const namespace_context*,
        bool isAttr);

  doc_expr* create_doc_expr(
          static_context* sctx,
          const QueryLoc&,
          expr* content,
          bool copyNodes);

  elem_expr* create_elem_expr(
        static_context* sctx,
        const QueryLoc&,
        expr* qnameExpr,
        expr* attrs,
        expr* content,
        const namespace_context* nsCtx,
        bool copyNodes);

  elem_expr* create_elem_expr(
        static_context* sctx,
        const QueryLoc&,
        expr* qnameExpr,
        expr* content,
        const namespace_context* nsCtx,
        bool copyNodes);

  attr_expr* create_attr_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t aQNameExpr,
    expr_t aValueExpr);

  text_expr* create_text_expr(
      static_context* sctx,
      const QueryLoc&,
      text_expr::text_constructor_type,
      expr_t);

  pi_expr* create_pi_expr(
          static_context* sctx,
          const QueryLoc&,
          expr_t,
          expr_t);

  const_expr* create_const_expr(
          static_context* sctx, const QueryLoc&, zstring& sval);

  const_expr* create_const_expr(
          static_context* sctx, const QueryLoc&, const std::string& sval);

  const_expr* create_const_expr(
          static_context* sctx, const QueryLoc&, const char* sval);

  const_expr* create_const_expr(
          static_context* sctx, const QueryLoc&, xs_integer);

  const_expr* create_const_expr(
          static_context* sctx, const QueryLoc&, xs_decimal);

  const_expr* create_const_expr(
          static_context* sctx, const QueryLoc&, xs_double);

  const_expr* create_const_expr(
          static_context* sctx, const QueryLoc&, xs_boolean);

  const_expr* create_const_expr(
          static_context* sctx, const QueryLoc&, store::Item_t);

  const_expr* create_const_expr(
          static_context* sctx,
          const QueryLoc&,
          const char* ns,
          const char* pre,
          const char* local);

  extension_expr* create_extension_expr(static_context* sctx, const QueryLoc&);

  extension_expr* create_extension_expr(
          static_context* sctx,
          const QueryLoc&,
          expr_t);

  catch_clause* create_catch_clause();

  trycatch_expr* create_trycatch_expr(
          static_context* sctx, const QueryLoc&, expr_t tryExpr);

  wrapper_expr* create_wrapper_expr(
          static_context* sctx, const QueryLoc& loc, expr_t wrapped);

  function_trace_expr* create_function_trace_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr_t aChild);

  function_trace_expr* create_function_trace_expr(expr_t aExpr);

  eval_expr* create_eval_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const expr_t& e,
      expr_script_kind_t scriptingKind,
      namespace_context* nsCtx);

#ifdef ZORBA_WITH_DEBUGGER
  debugger_expr* create_debugger_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const expr_t& aChild,
      namespace_context* nsCtx,
      bool aIsVarDeclaration);
#endif

////////////////////////////////////////////////////////////////////////////////

  var_expr* create_var_expr(
      static_context* sctx,
      const QueryLoc& loc,
      var_expr::var_kind k,
      store::Item* name);

  var_expr* create_var_expr(const var_expr& source);

////////////////////////////////////////////////////////////////////////////////

  insert_expr* create_insert_expr(
    static_context* sctx,
    const QueryLoc&,
    store::UpdateConsts::InsertType,
    const expr_t& aSourceExpr,
    const expr_t& aTargetExpr);

  delete_expr* create_delete_expr(
          static_context* sctx, const QueryLoc&, const expr_t&);

  replace_expr* create_replace_expr(
    static_context* sctx,
    const QueryLoc&,
    store::UpdateConsts::ReplaceType aType,
    const expr_t&,
    const expr_t&);

  rename_expr* create_rename_expr(
      static_context* sctx,
      const QueryLoc&,
      const expr_t&,
      const expr_t&);

  copy_clause* create_copy_clause(var_expr_t aVar, expr_t aExpr);

  transform_expr* create_transform_expr(
          static_context* sctx, const QueryLoc& loc);

  block_expr* create_block_expr(
      static_context* sctx,
      const QueryLoc& loc,
      bool allowLastUpdating,
      std::vector<expr_t>& seq,
      std::vector<var_expr*>* assignedVars);

  apply_expr* create_apply_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const expr_t& inExpr,
      bool discardXDM);

  var_decl_expr* create_var_decl_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const var_expr_t& varExpr,
      const expr_t& initExpr);

  var_set_expr* create_var_set_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const var_expr_t& varExpr,
      const expr_t& setExpr);

  exit_expr* create_exit_expr(
          static_context* sctx, const QueryLoc& loc, const expr_t& inExpr);

  exit_catcher_expr* create_exit_catcher_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const expr_t& inExpr,
      std::vector<expr*>& exitExprs);

  flowctl_expr* create_flowctl_expr(
          static_context* sctx, const QueryLoc& loc,
          flowctl_expr::action action);

  while_expr* create_while_expr(
          static_context* sctx, const QueryLoc& loc, expr_t body);

////////////////////////////////////////////////////////////////////////////////

  relpath_expr* create_relpath_expr(static_context* sctx, const QueryLoc& loc);

  axis_step_expr* create_axis_step_expr(static_context* sctx, const QueryLoc&);

  match_expr* create_match_expr(static_context* sctx, const QueryLoc&);

////////////////////////////////////////////////////////////////////////////////

  dynamic_function_invocation_expr* create_dynamic_function_invocation_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const expr_t& anExpr,
      const std::vector<expr_t>& args);

  function_item_expr* create_function_item_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const store::Item* aQName,
      function* f,
      uint32_t aArity);

  function_item_expr* create_function_item_expr(
      static_context* sctx,
      const QueryLoc& loc);

  ftcontains_expr* create_ftcontains_expr(
    static_context*,
    QueryLoc const&,
    expr_t range,
    ftnode *ftselection,
    expr_t ftignore);

////////////////////////////////////////////////////////////////////////////////

  //this calls the static create_seq within fo_expr
  fo_expr* create_seq(static_context* sctx, const QueryLoc &);

  fo_expr* create_fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    const expr* arg);

  fo_expr* create_fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    const expr* arg1,
    const expr* arg2);

  fo_expr* create_fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    const std::vector<expr_t>& args);

  fo_expr* create_fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f);

////////////////////////////////////////////////////////////////////////////////

  for_clause* create_for_clause(
        static_context* sctx,
        ExprManager* exprMan,
        const QueryLoc& loc,
        var_expr_t varExpr,
        expr_t domainExpr,
        var_expr_t posVarExpr = NULL,
        var_expr_t scoreVarExpr = NULL,
        bool isOuter = false);

  let_clause* create_let_clause(
        static_context* sctx,
        ExprManager* exprMan,
        const QueryLoc& loc,
        var_expr_t varExpr,
        expr_t domainExpr,
        bool lazy = false);

  window_clause* create_window_clause(
        static_context* sctx,
        ExprManager* exprMan,
        const QueryLoc& loc,
        window_clause::window_t winKind,
        var_expr_t varExpr,
        expr_t domainExpr,
        flwor_wincond_t winStart,
        flwor_wincond_t winStop,
        bool lazy = false);

  flwor_wincond* create_flwor_wincond(
      static_context* sctx,
      bool isOnly,
      const flwor_wincond::vars& in_vars,
      const flwor_wincond::vars& out_vars,
      expr_t cond);

  group_clause* create_group_clause(
        static_context* sctx,
        const QueryLoc& loc,
        const flwor_clause::rebind_list_t& gvars,
        flwor_clause::rebind_list_t ngvars,
        const std::vector<std::string>& collations);

  orderby_clause * create_orderby_clause (
      static_context* sctx,
      const QueryLoc& loc,
      bool stable,
      const std::vector<OrderModifier>& modifiers,
      const std::vector<expr_t>& orderingExprs);

  materialize_clause* create_materialize_clause(
          static_context* sctx, const QueryLoc& loc);

  count_clause* create_count_clause(
          static_context* sctx, const QueryLoc& loc, var_expr_t var);

  where_clause* create_where_clause(
          static_context* sctx, const QueryLoc& loc, expr_t where);

  flwor_expr* create_flwor_expr(
          static_context* sctx, const QueryLoc& loc, bool general);

};

} // namespace zorba

#endif // ZORBA_COMPILER_EXPRMANAGER_H
