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
#include "json_exprs.h"

namespace zorba
{

#if 0
//A simple expression that can just be deallocated without calling the
//destructor.
class NullExpr : public expr
{
public:
  NullExpr() : expr(NULL, NULL, QueryLoc(), unknown_expr_kind) {}

  void accept(expr_visitor& v) {}

  void compute_scripting_kind() {}

  std::ostream& put(std::ostream& stream) const { return stream; }
};


class NullFlworClause : public flwor_clause
{
public:
  //it being a let clause is arbitrary, it doesn't matter what type it is.
  NullFlworClause() :flwor_clause(NULL, NULL, QueryLoc(), flwor_clause::let_clause) {}

  std::ostream& put(std::ostream& stream) const { return stream; }

  flwor_clause* clone(expr::substitution_t &) const { return NULL; }
};


class NullWincond : public flwor_wincond
{
public:
  NullWincond() : flwor_wincond(NULL, NULL, false, vars(), vars(), NULL) {}

  std::ostream& put(std::ostream& stream) const { return stream; }
};


class NullCatchClause : public catch_clause
{
public:
  NullCatchClause() : catch_clause(NULL) {}

  std::ostream& put(std::ostream& stream) const{return stream;}
};


class NullCopyClause : public copy_clause
{
public:
  NullCopyClause() : copy_clause(NULL, NULL, NULL) {}
};
#endif


ExprManager::ExprManager(CompilerCB* ccb)
  :
  theCCB(ccb)
{
  theExprs.reserve(1024);
  theFlworClauses.reserve(1024);
}


//calls on the destructors and also keeps tracks of certain numbers
ExprManager::~ExprManager()
{
  for(std::vector<expr*>::iterator iter = theExprs.begin();
      iter != theExprs.end();
      ++iter)
  {
    //We assume that the exprs being deleted they may be "held"
    //by a reference or pointer somewhere and will try deleting them again.
    //To prevent deleting an already deleted expr, we replace them with
    //a NullExpr

    expr* exp = *iter;

    exp->~expr();

    //constructs a new NULLExpr where the old expr existed
    //new (exp) NullExpr();
  }

  for(std::vector<flwor_clause*>::iterator iter = theFlworClauses.begin();
      iter != theFlworClauses.end();
      ++iter)
  {
    flwor_clause* clause = *iter;
    clause->~flwor_clause();
    // new (clause) NullFlworClause();
  }

  for(std::vector<flwor_wincond*>::iterator iter = theWinconds.begin();
      iter != theWinconds.end();
      ++iter)
  {
    flwor_wincond* wincond = *iter;
    wincond->~flwor_wincond();
    // new (wincond) NullWincond();
  }

  for(std::vector<catch_clause*>::iterator iter = theCatchClauses.begin();
      iter != theCatchClauses.end();
      ++iter)
  {
    catch_clause* clause = *iter;
    clause->~catch_clause();
    // new (clause) NullCatchClause();
  }

  for(std::vector<copy_clause*>::iterator iter = theCopyClauses.begin();
      iter != theCopyClauses.end();
      ++iter)
  {
    copy_clause* clause = *iter;
    clause->~copy_clause();
    // new (clause) NullCopyClause();
  }

  for(std::vector<pragma*>::iterator iter = thePragmas.begin();
      iter != thePragmas.end();
      ++iter)
  {
    pragma* pragma = *iter;
    pragma->~pragma();
    // new (clause) NullCopyClause();
  }
}


void ExprManager::reg(expr* exp)
{
  theExprs.push_back(exp);
}


void ExprManager::reg(flwor_clause* clause)
{
  theFlworClauses.push_back(clause);
}


void ExprManager::reg(flwor_wincond* wincond)
{
  theWinconds.push_back(wincond);
}


void ExprManager::reg(catch_clause* clause)
{
  theCatchClauses.push_back(clause);
}


void ExprManager::reg(copy_clause* clause)
{
  theCopyClauses.push_back(clause);
}


void ExprManager::reg(pragma* pragma)
{
  thePragmas.push_back(pragma);
}


////////////////////////////////////////////////////////////////////////////////

#define CREATE_AND_RETURN_EXPR(EXPRTYPE, ...)                          \
  EXPRTYPE* EXPPTR = new (theMemoryMgr) EXPRTYPE(theCCB, __VA_ARGS__); \
  reg(EXPPTR);                                                         \
  return EXPPTR

#define CREATE_AND_RETURN(TYPE, ...)                   \
  TYPE* EXPPTR = new (theMemoryMgr) TYPE(__VA_ARGS__); \
  reg(EXPPTR);                                         \
  return EXPPTR


////////////////////////////////////////////////////////////////////////////////


if_expr* ExprManager::create_if_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* cond_expr,
    expr* then_expr,
    expr* else_expr)
{
  CREATE_AND_RETURN_EXPR(if_expr, sctx, loc, cond_expr, then_expr, else_expr);
}


order_expr* ExprManager::create_order_expr(
    static_context* sctx,
    const QueryLoc& loc,
    order_expr::order_type_t order,
    expr* exp)
{
  CREATE_AND_RETURN_EXPR(order_expr, sctx, loc, order, exp);
}


validate_expr* ExprManager::create_validate_expr(
    static_context* sctx,
    const QueryLoc& loc,
    ParseConstants::validation_mode_t mode,
    const store::Item_t& aTypeName,
    expr* validated,
    rchandle<TypeManager> tm)
{
  CREATE_AND_RETURN_EXPR(validate_expr, sctx, loc, mode, aTypeName, validated, tm);
}


cast_expr* ExprManager::create_cast_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* casted,
    xqtref_t type)
{
  CREATE_AND_RETURN_EXPR(cast_expr, sctx, loc, casted, type);
}


treat_expr* ExprManager::create_treat_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* treated,
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
    expr* promoted,
    const xqtref_t& type,
    PromoteIterator::ErrorKind err,
    store::Item* qname)
{
  CREATE_AND_RETURN_EXPR(promote_expr, sctx, loc, promoted, type, err, qname);
}


castable_expr* ExprManager::create_castable_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* castable,
    xqtref_t type)
{
  CREATE_AND_RETURN_EXPR(castable_expr, sctx, loc, castable, type);
}


instanceof_expr* ExprManager::create_instanceof_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* instanced,
    xqtref_t type,
    bool checkPrimeOnly)
{
  CREATE_AND_RETURN_EXPR(instanceof_expr,
          sctx, loc, instanced, type, checkPrimeOnly);
}


name_cast_expr* ExprManager::create_name_cast_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* casted,
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
    expr* aQNameExpr,
    expr* aValueExpr)
{
  CREATE_AND_RETURN_EXPR(attr_expr, sctx, loc, aQNameExpr, aValueExpr);
}


text_expr* ExprManager::create_text_expr(
    static_context* sctx,
    const QueryLoc& loc,
    text_expr::text_constructor_type textType,
    expr* text)
{
  CREATE_AND_RETURN_EXPR(text_expr, sctx, loc, textType, text);
}


pi_expr* ExprManager::create_pi_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* targetExpr,
    expr* contentExpr)
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
    expr* extended)
{
  CREATE_AND_RETURN_EXPR(extension_expr, sctx, loc, extended);
}


catch_clause* ExprManager::create_catch_clause()
{
  CREATE_AND_RETURN(catch_clause, theCCB);
}


trycatch_expr* ExprManager::create_trycatch_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* tryExpr)
{
  CREATE_AND_RETURN_EXPR(trycatch_expr, sctx, loc, tryExpr);
}


wrapper_expr* ExprManager::create_wrapper_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* wrapped)
{
  CREATE_AND_RETURN_EXPR(wrapper_expr, sctx, loc, wrapped);
}


function_trace_expr* ExprManager::create_function_trace_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* aChild)
{
  CREATE_AND_RETURN_EXPR(function_trace_expr, sctx, loc, aChild);
}


function_trace_expr* ExprManager::create_function_trace_expr(expr* aExpr)
{
  //this function gets the ExprManager from the expression it recieves.
  function_trace_expr* e = new (theMemoryMgr) function_trace_expr(aExpr);
  reg(e);
  return e;
}


eval_expr* ExprManager::create_eval_expr(
    CompilerCB* ccb,
    static_context* sctx,
    const QueryLoc& loc,
    expr* e,
    expr_script_kind_t scriptingKind,
    namespace_context* nsCtx)
{
  CREATE_AND_RETURN_EXPR(eval_expr, ccb, sctx, loc, e, scriptingKind, nsCtx);
}

#ifdef ZORBA_WITH_DEBUGGER

debugger_expr* ExprManager::create_debugger_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* aChild,
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
  var_expr* e = new (theMemoryMgr) var_expr(source);
  reg(e);
  return e;
}


////////////////////////////////////////////////////////////////////////////////


#ifdef ZORBA_WITH_JSON

json_array_expr* ExprManager::create_json_array_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* content)
{
  CREATE_AND_RETURN_EXPR(json_array_expr, sctx, loc, content);
}


json_object_expr* ExprManager::create_json_object_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* content,
    bool accumulate)
{
  CREATE_AND_RETURN_EXPR(json_object_expr, sctx, loc, content, accumulate);
}


json_direct_object_expr* ExprManager::create_json_direct_object_expr(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<expr*>& names,
    std::vector<expr*>& values)
{
  CREATE_AND_RETURN_EXPR(json_direct_object_expr, sctx, loc, names, values);
}


#endif // ZORBA_WITH_JSON

////////////////////////////////////////////////////////////////////////////////


insert_expr* ExprManager::create_insert_expr(
    static_context* sctx,
    const QueryLoc& loc,
    store::UpdateConsts::InsertType insertType,
    expr* aSourceExpr,
    expr* aTargetExpr)
{
  CREATE_AND_RETURN_EXPR(insert_expr,
  sctx, loc, insertType, aSourceExpr, aTargetExpr);
}


delete_expr* ExprManager::create_delete_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* aTargetExpr)
{
  CREATE_AND_RETURN_EXPR(delete_expr, sctx, loc, aTargetExpr);
}


replace_expr* ExprManager::create_replace_expr(
    static_context* sctx,
    const QueryLoc& loc,
    store::UpdateConsts::ReplaceType aType,
    expr* aSourceExpr,
    expr* aTargetExpr)
{
  CREATE_AND_RETURN_EXPR(replace_expr, sctx, loc, aType, aSourceExpr, aTargetExpr);
}


rename_expr* ExprManager::create_rename_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* aSourceExpr,
    expr* aTargetExpr)
{
  CREATE_AND_RETURN_EXPR(rename_expr, sctx, loc, aSourceExpr, aTargetExpr);
}


copy_clause* ExprManager::create_copy_clause(var_expr* aVar, expr* aExpr)
{
  CREATE_AND_RETURN(copy_clause, theCCB,  aVar, aExpr);
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
    std::vector<expr*>& seq,
    std::vector<var_expr*>* assignedVars)
{
  CREATE_AND_RETURN_EXPR(block_expr,
  sctx, loc, allowLastUpdating, seq, assignedVars);
}


apply_expr* ExprManager::create_apply_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* inExpr,
    bool discardXDM)
{
  CREATE_AND_RETURN_EXPR(apply_expr, sctx, loc, inExpr, discardXDM);
}


var_decl_expr* ExprManager::create_var_decl_expr(
    static_context* sctx,
    const QueryLoc& loc,
    var_expr* varExpr,
    expr* initExpr)
{
  CREATE_AND_RETURN_EXPR(var_decl_expr, sctx, loc, varExpr, initExpr);
}


var_set_expr* ExprManager::create_var_set_expr(
    static_context* sctx,
    const QueryLoc& loc,
    var_expr* varExpr,
    expr* setExpr)
{
  CREATE_AND_RETURN_EXPR(var_set_expr, sctx, loc, varExpr, setExpr);
}


exit_expr* ExprManager::create_exit_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* inExpr)
{
  CREATE_AND_RETURN_EXPR(exit_expr, sctx, loc, inExpr);
}


exit_catcher_expr* ExprManager::create_exit_catcher_expr(
    static_context* sctx,
    const QueryLoc& loc,
    expr* inExpr,
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
      static_context* sctx, const QueryLoc& loc, expr* body)
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
    expr* anExpr,
    const std::vector<expr*>& args)
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
    expr* range,
    ftnode *ftselection,
    expr* ftignore)
{
  CREATE_AND_RETURN_EXPR(ftcontains_expr, sctx, loc, range, ftselection, ftignore);
}


////////////////////////////////////////////////////////////////////////////////

//this calls the static create_seq within fo_expr
fo_expr* ExprManager::create_seq(static_context* sctx, const QueryLoc& loc)
{
  //TODO make fo_expr use this factory to generate everything
  return fo_expr::create_seq(theCCB, sctx, loc);
}


fo_expr* ExprManager::create_fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    expr* arg)
{
  CREATE_AND_RETURN_EXPR(fo_expr, sctx, loc, f, arg);
}


fo_expr* ExprManager::create_fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    expr* arg1,
    expr* arg2)
{
  CREATE_AND_RETURN_EXPR(fo_expr, sctx, loc, f, arg1, arg2);
}


fo_expr* ExprManager::create_fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f,
    const std::vector<expr*>& args)
{
  CREATE_AND_RETURN_EXPR(fo_expr, sctx, loc, f, args);
}

fo_expr* ExprManager::create_fo_expr(
    static_context* sctx,
    const QueryLoc& loc,
    const function* f)
{

  CREATE_AND_RETURN_EXPR(fo_expr, sctx, loc, f);
}
////////////////////////////////////////////////////////////////////////////////

for_clause* ExprManager::create_for_clause(
    static_context* sctx,
    const QueryLoc& loc,
    var_expr* varExpr,
    expr* domainExpr,
    var_expr* posVarExpr,
    var_expr* scoreVarExpr,
    bool isOuter)
{
  CREATE_AND_RETURN(for_clause,
          sctx, theCCB, loc, varExpr, domainExpr, posVarExpr, scoreVarExpr, isOuter);
}

let_clause* ExprManager::create_let_clause(
    static_context* sctx,
    const QueryLoc& loc,
    var_expr* varExpr,
    expr* domainExpr,
    bool lazy)
{
  CREATE_AND_RETURN(let_clause, sctx, theCCB, loc, varExpr, domainExpr, lazy);
}

window_clause* ExprManager::create_window_clause(
    static_context* sctx,
    const QueryLoc& loc,
    window_clause::window_t winKind,
    var_expr* varExpr,
    expr* domainExpr,
    flwor_wincond* winStart,
    flwor_wincond* winStop,
    bool lazy)
{
  CREATE_AND_RETURN(window_clause,
          sctx, theCCB, loc, winKind, varExpr, domainExpr, winStart, winStop, lazy);
}

flwor_wincond* ExprManager::create_flwor_wincond(
  static_context* sctx,
  bool isOnly,
  const flwor_wincond::vars& in_vars,
  const flwor_wincond::vars& out_vars,
  expr* cond)
{
  CREATE_AND_RETURN(flwor_wincond, theCCB, sctx, isOnly, in_vars, out_vars, cond);
}

group_clause* ExprManager::create_group_clause(
    static_context* sctx,
    const QueryLoc& loc,
    const flwor_clause::rebind_list_t& gvars,
    flwor_clause::rebind_list_t ngvars,
    const std::vector<std::string>& collations)
{
  CREATE_AND_RETURN(group_clause, sctx, theCCB,  loc, gvars, ngvars, collations);
}

orderby_clause* ExprManager::create_orderby_clause(
  static_context* sctx,
  const QueryLoc& loc,
  bool stable,
  const std::vector<OrderModifier>& modifiers,
  const std::vector<expr*>& orderingExprs)
{
  CREATE_AND_RETURN(orderby_clause, sctx, theCCB, loc, stable, modifiers, orderingExprs);
}

materialize_clause* ExprManager::create_materialize_clause(
      static_context* sctx, const QueryLoc& loc)
{
  CREATE_AND_RETURN(materialize_clause, sctx, theCCB, loc);
}

count_clause* ExprManager::create_count_clause(
      static_context* sctx, const QueryLoc& loc, var_expr* var)
{
  CREATE_AND_RETURN(count_clause, sctx, theCCB, loc, var);
}

where_clause* ExprManager::create_where_clause(
      static_context* sctx, const QueryLoc& loc, expr* where)
{
  CREATE_AND_RETURN(where_clause, sctx, theCCB, loc, where);
}

flwor_expr* ExprManager::create_flwor_expr(
      static_context* sctx, const QueryLoc& loc, bool general)
{
  CREATE_AND_RETURN_EXPR(flwor_expr, sctx, loc, general);
}

pragma* ExprManager::create_pragma(
    const store::Item_t& name,
    const zstring& lit)
{
  CREATE_AND_RETURN(pragma, name, lit);
}

////////////////////////////////////////////////////////////////////////////////


} // namespace zorba

