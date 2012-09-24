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

class CompilerCB;

class ExprManager
{
private:
  std::vector<expr*>          theExprs;
  std::vector<flwor_clause*>  theFlworClauses;
  std::vector<flwor_wincond*> theWinconds;
  std::vector<catch_clause*>  theCatchClauses;
  std::vector<copy_clause*>   theCopyClauses;
  std::vector<pragma*>        thePragmas;
  MemoryManager               theMemoryMgr;
  CompilerCB           *const theCCB;

public:
  ExprManager(CompilerCB* ccb);

  ~ExprManager();

  void reg(expr*);

  void reg(flwor_clause*);

  void reg(flwor_wincond*);

  void reg(catch_clause*);

  void reg(copy_clause*);

  void reg(pragma*);

private:
  //An ExprManager is the only object to handle a collection of Exprs and
  //the memory in which they recide. Copying it in a senseful way would.
  //require copying all the memory, which is costly and useless.
  ExprManager(const ExprManager&);
  ExprManager& operator= (const ExprManager&);

public:
  MemoryManager& getMemory() { return theMemoryMgr; }

  csize numExprs() const { return theExprs.size(); }

public:
  if_expr* create_if_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr* cond_expr,
      expr* then_expr,
      expr* else_expr);

  order_expr* create_order_expr(
      static_context* sctx,
      const QueryLoc& loc,
      order_expr::order_type_t,
      expr*);

  validate_expr* create_validate_expr(
      static_context*,
      const QueryLoc&,
      ParseConstants::validation_mode_t,
      const store::Item_t& aTypeName,
      expr* validated,
      rchandle<TypeManager>);

  cast_expr* create_cast_expr(
      static_context* sctx,
      const QueryLoc&,
      expr*,
      xqtref_t);

  treat_expr* create_treat_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr* input,
      const xqtref_t& type,
      TreatIterator::ErrorKind err,
      bool check_prime = true,
      store::Item* qnname = NULL);


  promote_expr* create_promote_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr* input,
      const xqtref_t& type,
      PromoteIterator::ErrorKind err,
      store::Item* qname);

  castable_expr* create_castable_expr(
      static_context* sctx,
      const QueryLoc&,
      expr*,
      xqtref_t);

  instanceof_expr* create_instanceof_expr(
      static_context* sctx,
      const QueryLoc&,
      expr*,
      xqtref_t,
      bool checkPrimeOnly = false);

  name_cast_expr* create_name_cast_expr(
      static_context* sctx,
      const QueryLoc&,
      expr*,
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
      expr* aQNameExpr,
      expr* aValueExpr);

  text_expr* create_text_expr(
      static_context* sctx,
      const QueryLoc&,
      text_expr::text_constructor_type,
      expr*);

  pi_expr* create_pi_expr(
      static_context* sctx,
      const QueryLoc&,
      expr*,
      expr*);

  const_expr* create_const_expr(
      static_context* sctx,
      const QueryLoc&,
      zstring& sval);

  const_expr* create_const_expr(
      static_context* sctx,
      const QueryLoc&,
      const std::string& sval);

  const_expr* create_const_expr(
      static_context* sctx,
      const QueryLoc&,
      const char* sval);

  const_expr* create_const_expr(
      static_context* sctx,
      const QueryLoc&,
      xs_integer);

  const_expr* create_const_expr(
      static_context* sctx,
      const QueryLoc&,
      xs_decimal);

  const_expr* create_const_expr(
      static_context* sctx,
      const QueryLoc&,
      xs_double);

  const_expr* create_const_expr(
      static_context* sctx,
      const QueryLoc&,
      xs_boolean);

  const_expr* create_const_expr(
      static_context* sctx,
      const QueryLoc&,
      store::Item_t);

  const_expr* create_const_expr(
      static_context* sctx,
      const QueryLoc&,
      const char* ns,
      const char* pre,
      const char* local);

  extension_expr* create_extension_expr(
      static_context* sctx,
      const QueryLoc&);

  extension_expr* create_extension_expr(
      static_context* sctx,
      const QueryLoc&,
      expr*);

  catch_clause* create_catch_clause();

  trycatch_expr* create_trycatch_expr(
      static_context* sctx,
      const QueryLoc&,
      expr* tryExpr);

  wrapper_expr* create_wrapper_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr* wrapped);

  function_trace_expr* create_function_trace_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr* aChild);

  function_trace_expr* create_function_trace_expr(expr* aExpr);

  eval_expr* create_eval_expr(
      CompilerCB* ccb,
      static_context* sctx,
      const QueryLoc& loc,
      expr* e,
      expr_script_kind_t scriptingKind,
      namespace_context* nsCtx);

#ifdef ZORBA_WITH_DEBUGGER
  debugger_expr* create_debugger_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr* aChild,
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

#ifdef ZORBA_WITH_JSON

  json_array_expr* create_json_array_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr* content);

  json_object_expr* create_json_object_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr* content,
      bool accumulate);

  json_direct_object_expr* create_json_direct_object_expr(
      static_context* sctx,
      const QueryLoc&,
      std::vector<expr*>& names,
      std::vector<expr*>& values);

#endif

////////////////////////////////////////////////////////////////////////////////

  insert_expr* create_insert_expr(
      static_context* sctx,
      const QueryLoc&,
      store::UpdateConsts::InsertType,
      expr* aSourceExpr,
      expr* aTargetExpr);

  delete_expr* create_delete_expr(
      static_context* sctx,
      const QueryLoc&,
      expr*);

  replace_expr* create_replace_expr(
      static_context* sctx,
      const QueryLoc&,
      store::UpdateConsts::ReplaceType aType,
      expr*,
      expr*);

  rename_expr* create_rename_expr(
      static_context* sctx,
      const QueryLoc&,
      expr*,
      expr*);

  copy_clause* create_copy_clause(var_expr* aVar, expr* aExpr);

  transform_expr* create_transform_expr(
      static_context* sctx,
      const QueryLoc& loc);

  block_expr* create_block_expr(
      static_context* sctx,
      const QueryLoc& loc,
      bool allowLastUpdating,
      std::vector<expr*>& seq,
      std::vector<var_expr*>* assignedVars);

  apply_expr* create_apply_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr* inExpr,
      bool discardXDM);

  var_decl_expr* create_var_decl_expr(
      static_context* sctx,
      const QueryLoc& loc,
      var_expr* varExpr,
      expr* initExpr);

  var_set_expr* create_var_set_expr(
      static_context* sctx,
      const QueryLoc& loc,
      var_expr* varExpr,
      expr* setExpr);

  exit_expr* create_exit_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr* inExpr);

  exit_catcher_expr* create_exit_catcher_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr* inExpr,
      std::vector<expr*>& exitExprs);

  flowctl_expr* create_flowctl_expr(
      static_context* sctx,
      const QueryLoc& loc,
      flowctl_expr::action action);

  while_expr* create_while_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr* body);

////////////////////////////////////////////////////////////////////////////////

  relpath_expr* create_relpath_expr(static_context* sctx, const QueryLoc& loc);

  axis_step_expr* create_axis_step_expr(static_context* sctx, const QueryLoc&);

  match_expr* create_match_expr(static_context* sctx, const QueryLoc&);

////////////////////////////////////////////////////////////////////////////////

  dynamic_function_invocation_expr* create_dynamic_function_invocation_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr* anExpr,
      const std::vector<expr*>& args);

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
      expr* range,
      ftnode *ftselection,
      expr* ftignore);

////////////////////////////////////////////////////////////////////////////////

  //this calls the static create_seq within fo_expr
  fo_expr* create_seq(static_context* sctx, const QueryLoc &);

  fo_expr* create_fo_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const function* f,
      expr* arg);

  fo_expr* create_fo_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const function* f,
      expr* arg1,
      expr* arg2);

  fo_expr* create_fo_expr(
      static_context* sctx,
      const QueryLoc& loc,
      const function* f,
      const std::vector<expr*>& args);

  fo_expr* create_fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f);

////////////////////////////////////////////////////////////////////////////////

  for_clause* create_for_clause(
      static_context* sctx,
      const QueryLoc& loc,
      var_expr* varExpr,
      expr* domainExpr,
      var_expr* posVarExpr = NULL,
      var_expr* scoreVarExpr = NULL,
      bool isOuter = false);

  let_clause* create_let_clause(
      static_context* sctx,
      const QueryLoc& loc,
      var_expr* varExpr,
      expr* domainExpr,
      bool lazy = false);

  window_clause* create_window_clause(
      static_context* sctx,
      const QueryLoc& loc,
      window_clause::window_t winKind,
      var_expr* varExpr,
      expr* domainExpr,
      flwor_wincond* winStart,
      flwor_wincond* winStop,
      bool lazy = false);

  flwor_wincond* create_flwor_wincond(
      static_context* sctx,
      bool isOnly,
      const flwor_wincond::vars& in_vars,
      const flwor_wincond::vars& out_vars,
      expr* cond);

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
      const std::vector<expr*>& orderingExprs);

  materialize_clause* create_materialize_clause(
      static_context* sctx,
      const QueryLoc& loc);

  count_clause* create_count_clause(
      static_context* sctx,
      const QueryLoc& loc,
      var_expr* var);

  where_clause* create_where_clause(
      static_context* sctx,
      const QueryLoc& loc,
      expr* where);

  flwor_expr* create_flwor_expr(
      static_context* sctx,
      const QueryLoc& loc,
      bool general);
 
  pragma* create_pragma(
      const store::Item_t&,
      const zstring&);
};

////////////////////////////////////////////////////////////////////////////////

#ifdef ZORBA_WITH_JSON

json_array_expr* create_json_array_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr* content);

json_object_expr* create_json_object_expr(
      static_context* sctx,
      const QueryLoc& loc,
      expr* content,
      bool accumulate);

json_direct_object_expr* create_json_direct_object_expr(
      static_context* sctx,
      const QueryLoc& loc,
      std::vector<expr*>& names,
      std::vector<expr*>& values);

#endif

} // namespace zorba

#endif // ZORBA_COMPILER_EXPRMANAGER_H
