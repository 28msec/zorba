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

#include "expr_manager.h"

#include "mem_manager.h"

#include "expr.h"
#include "ftnode.h"
#include "var_expr.h"
#include "flwor_expr.h"
#include "fo_expr.h"
#include "ft_expr.h"
#include "function_item_expr.h"
#include "path_expr.h"
#include "script_exprs.h"
#include "update_exprs.h"

namespace zorba
{

ExprManager::ExprManager()
  :
  memory()
{
}


//calls on the destructors and also keeps tracks of certain numbers
ExprManager::~ExprManager()
{
  unsigned long total_expr = theExprs.size();
  unsigned long zero_ref_expr = 0;

  unsigned long total_bytes = 0;
  unsigned long zero_ref_bytes = 0;

  for(std::list<expr*>::iterator iter = theExprs.begin();
      iter != theExprs.end();
      iter++)
  {
    expr* exp = *iter;

    unsigned long bytes = sizeof *exp;

    total_bytes += bytes;

    if(exp->getRefCount() == 0)
    {
      ++zero_ref_expr;
      zero_ref_bytes += bytes;
    }

    exp->~expr();
  }
}


expr* ExprManager::reg(expr* exp)
{
  theExprs.push_back(exp);
  return exp;
}


////////////////////////////////////////////////////////////////////////////////

#define CREATE_AND_RETURN_EXPR(EXPRTYPE, ...) \
  EXPRTYPE* EXPPTR = new (memory) EXPRTYPE(__VA_ARGS__); \
  reg(EXPPTR); \
  return EXPPTR

#define CREATE_AND_RETURN(TYPE, ...) \
  TYPE *EXPPTR = new (memory) TYPE(__VA_ARGS__); \
  return EXPPTR


////////////////////////////////////////////////////////////////////////////////


if_expr* ExprManager::create_if_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t cond_expr,
    expr_t then_expr,
    expr_t else_expr)
{
  CREATE_AND_RETURN_EXPR(if_expr, sctx, loc, cond_expr, then_expr, else_expr);
}


order_expr* ExprManager::create_order_expr(
    static_context* sctx,
    const QueryLoc& loc,
    order_expr::order_type_t order,
    expr_t exp)
{
  CREATE_AND_RETURN_EXPR(order_expr, sctx, loc, order, exp);
}


validate_expr* ExprManager::create_validate_expr(
    static_context* sctx,
    const QueryLoc& loc,
    ParseConstants::validation_mode_t mode,
    const store::Item_t& aTypeName,
    expr_t validated,
    rchandle<TypeManager> tm)
{
  CREATE_AND_RETURN_EXPR(validate_expr, sctx, loc, mode, aTypeName, validated, tm);
}


cast_expr* ExprManager::create_cast_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t casted,
    xqtref_t type)
{
  CREATE_AND_RETURN_EXPR(cast_expr, sctx, loc, casted, type);
}


treat_expr* ExprManager::create_treat_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& treated,
    const xqtref_t& type,
    TreatIterator::ErrorKind err,
    bool check_prime,
    store::Item* qname)
{
  CREATE_AND_RETURN_EXPR(treat_expr,
  sctx, loc, treated, type, err, check_prime, qname);
}


promote_expr* ExprManager::create_promote_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& promoted,
    const xqtref_t& type,
    PromoteIterator::ErrorKind err,
    store::Item* qname)
{
  CREATE_AND_RETURN_EXPR(promote_expr, sctx, loc, promoted, type, err, qname);
}


castable_expr* ExprManager::create_castable_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t castable,
    xqtref_t type)
{
  CREATE_AND_RETURN_EXPR(castable_expr, sctx, loc, castable, type);
}


instanceof_expr* ExprManager::create_instanceof_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t instanced,
    xqtref_t type,
    bool checkPrimeOnly)
{
  CREATE_AND_RETURN_EXPR(instanceof_expr,
          sctx, loc, instanced, type, checkPrimeOnly);
}


name_cast_expr* ExprManager::create_name_cast_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t casted,
    const namespace_context* ns,
    bool isAttr)
{
  CREATE_AND_RETURN_EXPR(name_cast_expr, sctx, loc, casted, ns, isAttr);
}


doc_expr* ExprManager::create_doc_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* content,
    bool copyNodes)
{
  CREATE_AND_RETURN_EXPR(doc_expr, sctx, loc, content, copyNodes);
}


elem_expr* ExprManager::create_elem_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* qnameExpr,
    expr* attrs,
    expr* content,
    const namespace_context* nsCtx,
    bool copyNodes)
{
  CREATE_AND_RETURN_EXPR(elem_expr,
          sctx, loc, qnameExpr, attrs, content, nsCtx, copyNodes);
}


elem_expr* ExprManager::create_elem_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* qnameExpr,
    expr* content,
    const namespace_context* nsCtx,
    bool copyNodes)
{
  CREATE_AND_RETURN_EXPR(elem_expr,
          sctx, loc, qnameExpr, content, nsCtx, copyNodes);
}


attr_expr* ExprManager::create_attr_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t aQNameExpr,
    expr_t aValueExpr)
{
  CREATE_AND_RETURN_EXPR(attr_expr, sctx, loc, aQNameExpr, aValueExpr);
}


text_expr* ExprManager::create_text_expr(
    static_context* sctx,
    const QueryLoc& loc,
    text_expr::text_constructor_type textType,
    expr_t text)
{
  CREATE_AND_RETURN_EXPR(text_expr, sctx, loc, textType, text);
}


pi_expr* ExprManager::create_pi_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t targetExpr,
    expr_t contentExpr)
{
  CREATE_AND_RETURN_EXPR(pi_expr, sctx, loc, targetExpr, contentExpr);
}


const_expr* ExprManager::create_const_expr(
    static_context* sctx,
    const QueryLoc& loc,
    zstring& sval)
{
  CREATE_AND_RETURN_EXPR(const_expr, sctx, loc, sval);
}


const_expr* ExprManager::create_const_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const std::string& sval)
{
  CREATE_AND_RETURN_EXPR(const_expr, sctx, loc, sval);
}


const_expr* ExprManager::create_const_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const char* sval)
{
  CREATE_AND_RETURN_EXPR(const_expr, sctx, loc, sval);
}


const_expr* ExprManager::create_const_expr(
    static_context* sctx,
    const QueryLoc& loc,
    xs_integer val)
{
  CREATE_AND_RETURN_EXPR(const_expr, sctx, loc, val);
}


const_expr* ExprManager::create_const_expr(
    static_context* sctx,
    const QueryLoc& loc,
    xs_decimal val)
{
  CREATE_AND_RETURN_EXPR(const_expr, sctx, loc, val);
}


const_expr* ExprManager::create_const_expr(
    static_context* sctx,
    const QueryLoc& loc,
    xs_double val)
{
  CREATE_AND_RETURN_EXPR(const_expr, sctx, loc, val);
}


const_expr* ExprManager::create_const_expr(
    static_context* sctx,
    const QueryLoc& loc,
    xs_boolean val)
{
  CREATE_AND_RETURN_EXPR(const_expr, sctx, loc, val);
}


const_expr* ExprManager::create_const_expr(
    static_context* sctx,
    const QueryLoc& loc,
    store::Item_t val)
{
  CREATE_AND_RETURN_EXPR(const_expr, sctx, loc, val);
}


const_expr* ExprManager::create_const_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const char* ns,
    const char* pre,
    const char* local)
{
  CREATE_AND_RETURN_EXPR(const_expr, sctx, loc, ns, pre, local);
}


extension_expr* ExprManager::create_extension_expr(
    static_context* sctx,
    const QueryLoc& loc)
{
  CREATE_AND_RETURN_EXPR(extension_expr, sctx, loc);
}


extension_expr* ExprManager::create_extension_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t extended)
{
  CREATE_AND_RETURN_EXPR(extension_expr, sctx, loc, extended);
}


catch_clause* ExprManager::create_catch_clause()
{
  CREATE_AND_RETURN(catch_clause);
}


trycatch_expr* ExprManager::create_trycatch_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t tryExpr)
{
  CREATE_AND_RETURN_EXPR(trycatch_expr, sctx, loc, tryExpr);
}


wrapper_expr* ExprManager::create_wrapper_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t wrapped)
{
  CREATE_AND_RETURN_EXPR(wrapper_expr, sctx, loc, wrapped);
}


function_trace_expr* ExprManager::create_function_trace_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr_t aChild)
{
  CREATE_AND_RETURN_EXPR(function_trace_expr, sctx, loc, aChild);
}


function_trace_expr* ExprManager::create_function_trace_expr(expr_t aExpr)
{
  CREATE_AND_RETURN_EXPR(function_trace_expr, aExpr);
}


eval_expr* ExprManager::create_eval_expr(
    CompilerCB* ccb,
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& e,
    expr_script_kind_t scriptingKind,
    namespace_context* nsCtx)
{
  CREATE_AND_RETURN_EXPR(eval_expr, ccb, sctx, loc, e, scriptingKind, nsCtx);
}

#ifdef ZORBA_WITH_DEBUGGER

debugger_expr* ExprManager::create_debugger_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& aChild,
    namespace_context* nsCtx,
    bool aIsVarDeclaration)
{
  CREATE_AND_RETURN_EXPR(debugger_expr,
  sctx, loc, aChild, nsCtx, aIsVarDeclaration);
}

#endif

////////////////////////////////////////////////////////////////////////////////

var_expr* ExprManager::create_var_expr(
    static_context* sctx,
    const QueryLoc& loc,
    var_expr::var_kind k,
    store::Item* name)
{
  CREATE_AND_RETURN_EXPR(var_expr, sctx, loc, k, name);
}


var_expr* ExprManager::create_var_expr(const var_expr& source)
{
  CREATE_AND_RETURN_EXPR(var_expr, source);
}


////////////////////////////////////////////////////////////////////////////////


insert_expr* ExprManager::create_insert_expr(
    static_context* sctx,
    const QueryLoc& loc,
    store::UpdateConsts::InsertType insertType,
    const expr_t& aSourceExpr,
    const expr_t& aTargetExpr)
{
  CREATE_AND_RETURN_EXPR(insert_expr,
  sctx, loc, insertType, aSourceExpr, aTargetExpr);
}


delete_expr* ExprManager::create_delete_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& aTargetExpr)
{
  CREATE_AND_RETURN_EXPR(delete_expr, sctx, loc, aTargetExpr);
}


replace_expr* ExprManager::create_replace_expr(
    static_context* sctx,
    const QueryLoc& loc,
    store::UpdateConsts::ReplaceType aType,
    const expr_t& aSourceExpr,
    const expr_t& aTargetExpr)
{
  CREATE_AND_RETURN_EXPR(replace_expr, sctx, loc, aType, aSourceExpr, aTargetExpr);
}


rename_expr* ExprManager::create_rename_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& aSourceExpr,
    const expr_t& aTargetExpr)
{
  CREATE_AND_RETURN_EXPR(rename_expr, sctx, loc, aSourceExpr, aTargetExpr);
}


copy_clause* ExprManager::create_copy_clause(var_expr_t aVar, expr_t aExpr)
{
  CREATE_AND_RETURN(copy_clause, aVar, aExpr);
}


transform_expr* ExprManager::create_transform_expr(
    static_context* sctx,
    const QueryLoc& loc)
{
  CREATE_AND_RETURN_EXPR(transform_expr, sctx, loc);
}


block_expr* ExprManager::create_block_expr(
    static_context* sctx,
    const QueryLoc& loc,
    bool allowLastUpdating,
    std::vector<expr_t>& seq,
    std::vector<var_expr*>* assignedVars)
{
  CREATE_AND_RETURN_EXPR(block_expr,
  sctx, loc, allowLastUpdating, seq, assignedVars);
}


apply_expr* ExprManager::create_apply_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& inExpr,
    bool discardXDM)
{
  CREATE_AND_RETURN_EXPR(apply_expr, sctx, loc, inExpr, discardXDM);
}


var_decl_expr* ExprManager::create_var_decl_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const var_expr_t& varExpr,
    const expr_t& initExpr)
{
  CREATE_AND_RETURN_EXPR(var_decl_expr, sctx, loc, varExpr, initExpr);
}


var_set_expr* ExprManager::create_var_set_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const var_expr_t& varExpr,
    const expr_t& setExpr)
{
  CREATE_AND_RETURN_EXPR(var_set_expr, sctx, loc, varExpr, setExpr);
}


exit_expr* ExprManager::create_exit_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& inExpr)
{
  CREATE_AND_RETURN_EXPR(exit_expr, sctx, loc, inExpr);
}


exit_catcher_expr* ExprManager::create_exit_catcher_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& inExpr,
    std::vector<expr*>& exitExprs)
{
  CREATE_AND_RETURN_EXPR(exit_catcher_expr, sctx, loc, inExpr, exitExprs);
}


flowctl_expr* ExprManager::create_flowctl_expr(
    static_context* sctx,
    const QueryLoc& loc,
    flowctl_expr::action action)
{
  CREATE_AND_RETURN_EXPR(flowctl_expr, sctx, loc, action);
}


while_expr* ExprManager::create_while_expr(
      static_context* sctx, const QueryLoc& loc, expr_t body)
{
  CREATE_AND_RETURN_EXPR(while_expr, sctx, loc, body);
}


////////////////////////////////////////////////////////////////////////////////

relpath_expr* ExprManager::create_relpath_expr(
     static_context* sctx,
     const QueryLoc& loc)
{
  CREATE_AND_RETURN_EXPR(relpath_expr, sctx, loc);
}


axis_step_expr* ExprManager::create_axis_step_expr(
    static_context* sctx,
    const QueryLoc& loc)
{
  CREATE_AND_RETURN_EXPR(axis_step_expr, sctx, loc);
}


match_expr* ExprManager::create_match_expr(
    static_context* sctx,
    const QueryLoc& loc)
{
  CREATE_AND_RETURN_EXPR(match_expr, sctx, loc);
}


////////////////////////////////////////////////////////////////////////////////

dynamic_function_invocation_expr*
ExprManager::create_dynamic_function_invocation_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const expr_t& anExpr,
    const std::vector<expr_t>& args)
{
  CREATE_AND_RETURN_EXPR(dynamic_function_invocation_expr, sctx, loc, anExpr, args);
}


function_item_expr* ExprManager::create_function_item_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const store::Item* aQName,
    function* f,
    uint32_t aArity)
{
  CREATE_AND_RETURN_EXPR(function_item_expr, sctx, loc, aQName, f, aArity);
}


function_item_expr* ExprManager::create_function_item_expr(
    static_context* sctx,
    const QueryLoc& loc)
{
  CREATE_AND_RETURN_EXPR(function_item_expr, sctx, loc);
}


ftcontains_expr* ExprManager::create_ftcontains_expr(
    static_context* sctx,
    QueryLoc const& loc,
    expr_t range,
    ftnode *ftselection,
    expr_t ftignore)
{
  CREATE_AND_RETURN_EXPR(ftcontains_expr, sctx, loc, range, ftselection, ftignore);
}


////////////////////////////////////////////////////////////////////////////////

//this calls the static create_seq within fo_expr
fo_expr* ExprManager::create_seq(static_context* sctx, const QueryLoc& loc)
{
  //TODO make fo_expr use this factory to generate everything
  return fo_expr::create_seq(sctx, loc);
}


fo_expr* ExprManager::create_fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    const expr* arg)
{
  CREATE_AND_RETURN_EXPR(fo_expr, sctx, loc, f, arg);
}


fo_expr* ExprManager::create_fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    const expr* arg1,
    const expr* arg2)
{
  CREATE_AND_RETURN_EXPR(fo_expr, sctx, loc, f, arg1, arg2);
}


fo_expr* ExprManager::create_fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    const std::vector<expr_t>& args)
{
  CREATE_AND_RETURN_EXPR(fo_expr, sctx, loc, f, args);
}

////////////////////////////////////////////////////////////////////////////////

for_clause* ExprManager::create_for_clause(
    static_context* sctx,
    const QueryLoc& loc,
    var_expr_t varExpr,
    expr_t domainExpr,
    var_expr_t posVarExpr,
    var_expr_t scoreVarExpr,
    bool isOuter)
{
  CREATE_AND_RETURN(for_clause,
          sctx, loc, varExpr, domainExpr, posVarExpr, scoreVarExpr, isOuter);
}

let_clause* ExprManager::create_let_clause(
    static_context* sctx,
    const QueryLoc& loc,
    var_expr_t varExpr,
    expr_t domainExpr,
    bool lazy)
{
  CREATE_AND_RETURN(let_clause, sctx, loc, varExpr, domainExpr, lazy);
}

window_clause* ExprManager::create_window_clause(
    static_context* sctx,
    const QueryLoc& loc,
    window_clause::window_t winKind,
    var_expr_t varExpr,
    expr_t domainExpr,
    flwor_wincond_t winStart,
    flwor_wincond_t winStop,
    bool lazy)
{
  CREATE_AND_RETURN(window_clause,
          sctx, loc, winKind, varExpr, domainExpr, winStart, winStop, lazy);
}

flwor_wincond* ExprManager::create_flwor_wincond(
  static_context* sctx,
  bool isOnly,
  const flwor_wincond::vars& in_vars,
  const flwor_wincond::vars& out_vars,
  expr_t cond)
{
  CREATE_AND_RETURN(flwor_wincond, sctx, isOnly, in_vars, out_vars, cond);
}

group_clause* ExprManager::create_group_clause(
    static_context* sctx,
    const QueryLoc& loc,
    const flwor_clause::rebind_list_t& gvars,
    flwor_clause::rebind_list_t ngvars,
    const std::vector<std::string>& collations)
{
  CREATE_AND_RETURN(group_clause, sctx, loc, gvars, ngvars, collations);
}

orderby_clause* ExprManager::create_orderby_clause(
  static_context* sctx,
  const QueryLoc& loc,
  bool stable,
  const std::vector<OrderModifier>& modifiers,
  const std::vector<expr_t>& orderingExprs)
{
  CREATE_AND_RETURN(orderby_clause, sctx, loc, stable, modifiers, orderingExprs);
}

materialize_clause* ExprManager::create_materialize_clause(
      static_context* sctx, const QueryLoc& loc)
{
  CREATE_AND_RETURN(materialize_clause, sctx, loc);
}

count_clause* ExprManager::create_count_clause(
      static_context* sctx, const QueryLoc& loc, var_expr_t var)
{
  CREATE_AND_RETURN(count_clause, sctx, loc, var);
}

where_clause* ExprManager::create_where_clause(
      static_context* sctx, const QueryLoc& loc, expr_t where)
{
  CREATE_AND_RETURN(where_clause, sctx, loc, where);
}

flwor_expr* ExprManager::create_flwor_expr(
      static_context* sctx, const QueryLoc& loc, bool general)
{
  CREATE_AND_RETURN_EXPR(flwor_expr, sctx, loc, general);
}

} // namespace zorba
