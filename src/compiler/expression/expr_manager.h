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
#include "expr_consts.h"
#include "expr_utils.h"
#include "mem_manager.h"

#include "compiler/parser/parse_constants.h"

#include "zorbatypes/schema_types.h"

#include "store/api/update_consts.h"


namespace zorba
{

class CompilerCB;
class expr;
class var_expr;
class catch_clause;
class pragma;
class flwor_clause;
class forlet_clause;
class flwor_wincond;
class copy_clause;
class window_clause;
class groupby_clause;
class where_clause;
class count_clause;
class orderby_clause;
class materialize_clause;
struct flwor_wincond_vars;
class ftnode;



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
      user_function* udf,
      const QueryLoc& loc,
      expr* cond_expr,
      expr* then_expr,
      expr* else_expr);

  order_expr* create_order_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      DocOrderMode,
      expr*);

  validate_expr* create_validate_expr(
      static_context*,
      user_function* udf,
      const QueryLoc&,
      ParseConstants::validation_mode_t,
      const store::Item_t& aTypeName,
      expr* validated,
      rchandle<TypeManager>);

  cast_expr* create_cast_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr*,
      const xqtref_t&,
      bool allowsEmptyInput);

  treat_expr* create_treat_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* input,
      const xqtref_t& type,
      TreatErrorKind err,
      bool check_prime = true,
      store::Item* qnname = NULL);


  promote_expr* create_promote_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* input,
      const xqtref_t& type,
      PromoteErrorKind err,
      store::Item* qname);

  castable_expr* create_castable_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr*,
      const xqtref_t&,
      bool allowsEmptyInput);

  instanceof_expr* create_instanceof_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr*,
      xqtref_t,
      bool checkPrimeOnly = false);

  name_cast_expr* create_name_cast_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr*,
      const namespace_context*,
      bool isAttr);

  doc_expr* create_doc_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr* content,
      bool copyNodes);

  elem_expr* create_elem_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr* qnameExpr,
      expr* attrs,
      expr* content,
      const namespace_context* nsCtx,
      bool copyNodes);

  elem_expr* create_elem_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr* qnameExpr,
      expr* content,
      const namespace_context* nsCtx,
      bool copyNodes);

  attr_expr* create_attr_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* aQNameExpr,
      expr* aValueExpr);

  namespace_expr* create_namespace_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* prefixExpr,
      expr* uriExpr);

  text_expr* create_text_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      TextConstructorType,
      expr*);

  pi_expr* create_pi_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr*,
      expr*);

  const_expr* create_const_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      zstring& sval);

  const_expr* create_const_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      const std::string& sval);

  const_expr* create_const_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      const char* sval);

  const_expr* create_const_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      xs_integer);

  const_expr* create_const_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      xs_decimal);

  const_expr* create_const_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      xs_double);

  const_expr* create_const_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      xs_boolean);

  const_expr* create_const_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      const store::Item_t&);

  const_expr* create_const_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      const char* ns,
      const char* pre,
      const char* local);

  extension_expr* create_extension_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&);

  extension_expr* create_extension_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr*);

  catch_clause* create_catch_clause();

  trycatch_expr* create_trycatch_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr* tryExpr);

  wrapper_expr* create_wrapper_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* wrapped);

  function_trace_expr* create_function_trace_expr(
      user_function* udf,
      expr* aExpr);

  eval_expr* create_eval_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* e,
      expr_script_kind_t scriptingKind,
      namespace_context* nsCtx);

#ifdef ZORBA_WITH_DEBUGGER
  debugger_expr* create_debugger_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* aChild,
      namespace_context* nsCtx,
      bool aIsVarDeclaration);
#endif

////////////////////////////////////////////////////////////////////////////////

  var_expr* create_var_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      ulong varKind,
      store::Item* name);

  var_expr* create_var_expr(user_function* udf, const var_expr& source);

////////////////////////////////////////////////////////////////////////////////

  json_array_expr* create_json_array_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* content);

  json_object_expr* create_json_object_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* content,
      bool accumulate);

  json_direct_object_expr* create_json_direct_object_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      std::vector<expr*>& names,
      std::vector<expr*>& values);

////////////////////////////////////////////////////////////////////////////////

  insert_expr* create_insert_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      store::UpdateConsts::InsertType,
      expr* aSourceExpr,
      expr* aTargetExpr);

  delete_expr* create_delete_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr*);

  replace_expr* create_replace_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      store::UpdateConsts::ReplaceType aType,
      expr*,
      expr*);

  rename_expr* create_rename_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&,
      expr*,
      expr*);

  copy_clause* create_copy_clause(var_expr* aVar, expr* aExpr);

  transform_expr* create_transform_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc);

  block_expr* create_block_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      bool allowLastUpdating,
      std::vector<expr*>& seq,
      std::vector<var_expr*>* assignedVars);

  apply_expr* create_apply_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* inExpr,
      bool discardXDM);

  var_decl_expr* create_var_decl_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      var_expr* varExpr,
      expr* initExpr);

  var_set_expr* create_var_set_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      var_expr* varExpr,
      expr* setExpr);

  exit_expr* create_exit_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* inExpr);

  exit_catcher_expr* create_exit_catcher_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* inExpr,
      std::vector<expr*>& exitExprs);

  flowctl_expr* create_flowctl_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      FlowCtlAction action);

  while_expr* create_while_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* body);

////////////////////////////////////////////////////////////////////////////////

  relpath_expr* create_relpath_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc);

  axis_step_expr* create_axis_step_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&);

  match_expr* create_match_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc&);

////////////////////////////////////////////////////////////////////////////////

  dynamic_function_invocation_expr* create_dynamic_function_invocation_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* anExpr,
      const std::vector<expr*>& args);

  argument_placeholder_expr* create_argument_placeholder_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc);

  function_item_expr* create_function_item_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      function* f,
      csize arity,
      bool isInline,
      bool isCoercion);

  function_item_expr* create_function_item_expr(
      static_context* sctx,
      user_function* udf,      
      const QueryLoc& loc,
      bool isInline,
      bool isCoercion);

#ifndef ZORBA_NO_FULL_TEXT
  ftcontains_expr* create_ftcontains_expr(
      static_context*,
      user_function* udf,
      QueryLoc const&,
      expr* range,
      ftnode* ftselection,
      expr* ftignore);
#endif

////////////////////////////////////////////////////////////////////////////////

  //this calls the static create_seq within fo_expr
  fo_expr* create_seq(
      static_context* sctx,
      user_function* udf,
      const QueryLoc &);

  fo_expr* create_fo_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      const function* f,
      expr* arg);

  fo_expr* create_fo_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      const function* f,
      expr* arg1,
      expr* arg2);

  fo_expr* create_fo_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      const function* f,
      const std::vector<expr*>& args);

  fo_expr* create_fo_expr(
    static_context* sctx,
    user_function* udf,
    const QueryLoc& loc,
    const function* f);

////////////////////////////////////////////////////////////////////////////////

  forlet_clause* create_for_clause(
      static_context* sctx,
      const QueryLoc& loc,
      var_expr* varExpr,
      expr* domainExpr,
      var_expr* posVarExpr = NULL,
      var_expr* scoreVarExpr = NULL,
      bool isOuter = false);

  forlet_clause* create_let_clause(
      static_context* sctx,
      const QueryLoc& loc,
      var_expr* varExpr,
      expr* domainExpr,
      bool lazy = false);

  window_clause* create_window_clause(
      static_context* sctx,
      const QueryLoc& loc,
      WindowKind winKind,
      var_expr* varExpr,
      expr* domainExpr,
      flwor_wincond* winStart,
      flwor_wincond* winStop,
      bool lazy = false);

  flwor_wincond* create_flwor_wincond(
      static_context* sctx,
      bool isOnly,
      const flwor_wincond_vars& in_vars,
      const flwor_wincond_vars& out_vars,
      expr* cond);

  groupby_clause* create_groupby_clause(
      static_context* sctx,
      const QueryLoc& loc,
      const var_rebind_list_t& gvars,
      const var_rebind_list_t& ngvars,
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
      user_function* udf,
      const QueryLoc& loc);

  pragma* create_pragma(
      const store::Item_t&,
      const zstring&);
};

////////////////////////////////////////////////////////////////////////////////

json_array_expr* create_json_array_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* content);

json_object_expr* create_json_object_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      expr* content,
      bool accumulate);

json_direct_object_expr* create_json_direct_object_expr(
      static_context* sctx,
      user_function* udf,
      const QueryLoc& loc,
      std::vector<expr*>& names,
      std::vector<expr*>& values);

} // namespace zorba

#endif // ZORBA_COMPILER_EXPRMANAGER_H
