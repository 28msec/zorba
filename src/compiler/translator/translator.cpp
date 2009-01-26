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

#include <sstream>
#include <iterator>

#include "zorbautils/fatal.h"
#include "zorbautils/strutil.h"
#include "zorbatypes/URI.h"
#include "zorbaerrors/error_manager.h"

#include "common/common.h"
#include "util/properties.h"
#include "util/stl_extra.h"
#include "util/tracer.h"

#include "compiler/translator/translator.h"
#include "compiler/api/compilercb.h"

#include "context/static_context.h"
#include "context/namespace_context.h"
#include "context/internal_uri_resolvers.h"
#include "context/standard_uri_resolvers.h"
#include "types/node_test.h"
#include "types/casting.h"
#include "types/typeops.h"
#include "compiler/expression/expr.h"
#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/parsetree/parsenode_visitor.h"
#include "compiler/normalizer/normalizer.h"
#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/rewriter/framework/rewriter.h"
#include "compiler/api/compiler_api.h"
#include "compiler/parser/util.h"

#include "system/globalenv.h"

#include "functions/signature.h"
#include "functions/external_function_adapters.h"

#include "types/delegating_typemanager.h"
#include "types/schema/schema.h"

#include "store/api/item.h"
#include "store/api/update_consts.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"

#ifdef ZORBA_DEBUGGER
#include "debugger/debugger_server.h"
#endif

using namespace std;

namespace zorba {

#define LOOKUP_FN( pfx, local, arity ) static_cast<function *> (sctx_p->lookup_fn (pfx, local, arity))
#define LOOKUP_OP1( local ) static_cast<function *> (sctx_p->lookup_builtin_fn (":" local, 1))
#define LOOKUP_OP2( local ) static_cast<function *> (sctx_p->lookup_builtin_fn (":" local, 2))
#define LOOKUP_OP3( local ) static_cast<function *> (sctx_p->lookup_builtin_fn (":" local, 3))
#define LOOKUP_OPN( local ) static_cast<function *> (sctx_p->lookup_builtin_fn (":" local, VARIADIC_SIG_SIZE))

#define CACHED( cache, val ) ((cache == NULL) ? (cache = val) : cache)

#define CHK_SINGLE_DECL( state, err ) do { if (state) ZORBA_ERROR(err); state = true; } while (0)
#define QLOCDECL const QueryLoc &loc = v.get_location(); (void) loc
#ifndef NDEBUG
# define TRACE_VISIT() QLOCDECL; if (Properties::instance()->traceTranslator()) cout << string(++print_depth, ' ') << TRACE << ", stk size " << nodestack.size () << ", tstk size: " << tstack.size () << ", scope depth " << scope_depth << endl
# define TRACE_VISIT_OUT() QLOCDECL; if (Properties::instance()->traceTranslator()) cout << string(print_depth--, ' ') << TRACE << ", stk size: " << nodestack.size () << ", tstk size: " << tstack.size () << ", scope depth " << scope_depth << endl
#else
# define TRACE_VISIT() QLOCDECL
# define TRACE_VISIT_OUT() QLOCDECL
#endif

#define DOT_VARNAME "$$dot"
#define DOT_POS_VARNAME "$$pos"
#define LAST_IDX_VARNAME "$$last-idx"

#define DOT_VAR lookup_ctx_var (DOT_VARNAME, loc).getp()

#define ITEM_FACTORY (GENV.getStore().getItemFactory())

#define CTXTS sctx_p->get_typemanager ()

  typedef pair<varref_t, expr_t> global_binding;

  template<class T> T &peek_stack (stack<T> &stk) {
    ZORBA_ASSERT (! stk.empty ());
    return stk.top ();
  }

  template <typename T> T pop_stack (stack<T> &stk) {
    T x = peek_stack (stk);
    stk.pop ();
    return x;
  }

  template <class T> class RCSet : public SimpleRCObject {
  public:
    set<T> theSet;
    typedef set<string>::iterator iterator;
    
    iterator begin () { return theSet.begin (); }
    iterator begin () const { return theSet.begin (); }
    iterator end () { return theSet.end (); }
    iterator end () const { return theSet.end (); }
    void insert (const T &val) { theSet.insert (val); }
    void insert (iterator p0, iterator p1) { theSet.insert (p0, p1); }
    iterator find (const T &val) { return theSet.find (val); }
    unsigned size () const { return theSet.size (); }
  };
  typedef rchandle<RCSet<string> > strset_t;
  void add_multimap_value (hashmap<strset_t > &map, const string &key, const string &val) {
    strset_t result;
    if (! map.get (key, result)) {
      result = new RCSet<string> ();
      map.put (key, result);
    }
    result->insert (val);
  }
  
  class ModulesInfo {
  public:
    auto_ptr<static_context> globals;
    hashmap<static_context *> mod_sctx_map;
    hashmap<string> mod_ns_map;
    checked_vector<expr_t> init_exprs;
    CompilerCB *topCompilerCB;

    ModulesInfo (static_context *sctx, CompilerCB *topCompilerCB_)
      : globals (static_cast<static_context *> (sctx->get_parent ())->create_child_context ()),
        topCompilerCB (topCompilerCB_)
    {}
  };

  expr_t translate_aux (const parsenode &root, CompilerCB* aCompilerCB, ModulesInfo *minfo, set<string> mod_stack);

class TranslatorImpl : public parsenode_visitor
{
public:
  friend expr_t translate_aux (const parsenode &root, CompilerCB* aCompilerCB, ModulesInfo *minfo, set<string> mod_stack);

protected:

  uint32_t                             print_depth;
  int                                  scope_depth;

  CompilerCB                         * compilerCB;
  static_context                     * sctx_p;
  ModulesInfo                        * minfo;
  vector<rchandle<static_context> >  & sctx_list;
  stack<expr_t>                        nodestack;
  stack<xqtref_t>                      tstack;  // types stack

  set<string> mod_import_ns_set;
  set<string> mod_stack;
  set<string> schema_import_ns_set;
  int tempvar_counter;


  /*******************************************************************************
   Global vars are the ones declared in the prolog (both external and non-external
   vars). theGlobalVars vector contains one entry per global var V. The entry maps
   the var_expr for V to the expr E that defines V (E is NULL for external vars)
  ********************************************************************************/
  list<global_binding> theGlobalVars;
#ifdef ZORBA_DEBUGGER
  checked_vector<unsigned int> theScopes;
  checked_vector<varref_t> theScopedVariables;
#endif

  rchandle<namespace_context> ns_ctx;
  /// Current module's namespace and prefix
  string mod_ns, mod_pfx;
  static_context *export_sctx;

  // FOR WHITESPACE CHECKING OF DirElemContent (stack is need because of nested elements)
  /**
   * Saves true if the previous DirElemContent is a boundary (DirElemConstructor or EnclosedExpr).
   */
  stack<bool> theIsWSBoundaryStack;
  /**
   * Saves the previous DirElemContent if it might be boundary whitespace (its previous item is a boundary
   * and it contains whitespace). It must be checked if the next item (the current item) is a boundary.
   */
  stack<const DirElemContent*> thePossibleWSContentStack;

  bool hadBSpaceDecl, hadBUriDecl, hadConstrDecl, hadCopyNSDecl, hadDefNSDecl, hadEmptyOrdDecl, hadOrdModeDecl;
  int xquery_version;  // 100 for 1.0, 110 for 1.1 etc

  varref_t theDotVar, theDotPosVar, theLastVar;

  // TODO: should be static
  // functions accepting . as default arg
  set<string> xquery_fns_def_dot;
  const function *op_concatenate, *op_enclosed_expr, *op_or, *fn_data;

  set<string> zorba_predef_mod_ns;
  
  // format of strings: type_char + qname_internal_key
  // where type_char is F or V
  stack<string> global_decl_stack;
  list<string> global_fn_decls, global_var_decls;
  hashmap<strset_t> global_deps;

  TranslatorImpl (CompilerCB* aCompilerCB, ModulesInfo *minfo_, set<string> mod_stack_)
    :
    print_depth (0),
    scope_depth (0),
    compilerCB(aCompilerCB),
    sctx_p (aCompilerCB->m_sctx),
    minfo (minfo_),
    sctx_list (aCompilerCB->m_sctx_list),
    mod_stack (mod_stack_),
    tempvar_counter (1),
    ns_ctx(new namespace_context(sctx_p)),
    export_sctx (NULL),
    hadBSpaceDecl (false),
    hadBUriDecl (false),
    hadConstrDecl (false),
    hadCopyNSDecl (false),
    hadEmptyOrdDecl (false),
    hadOrdModeDecl (false),
    xquery_version (10000)  // fictious version 100.0 -- allow everything
  {
    xquery_fns_def_dot.insert ("string-length");
    xquery_fns_def_dot.insert ("normalize-space");
    xquery_fns_def_dot.insert ("root");
    xquery_fns_def_dot.insert ("base-uri");
    xquery_fns_def_dot.insert ("namespace-uri");
    xquery_fns_def_dot.insert ("local-name");
    xquery_fns_def_dot.insert ("name");
    xquery_fns_def_dot.insert ("string");

    op_concatenate = op_enclosed_expr = op_or = fn_data = NULL;
    zorba_predef_mod_ns.insert (ZORBA_FN_NS);
    zorba_predef_mod_ns.insert (ZORBA_MATH_FN_NS);
    zorba_predef_mod_ns.insert (ZORBA_REST_FN_NS);
    zorba_predef_mod_ns.insert (ZORBA_NODEREF_FN_NS);
    zorba_predef_mod_ns.insert (ZORBA_COLLECTION_FN_NS);
    zorba_predef_mod_ns.insert (ZORBA_ALEXIS_FN_NS);
  }

  varref_t lookup_ctx_var (xqp_string name, const QueryLoc &loc) {
    expr *ve = sctx_p->lookup_var (name);
    if (ve != NULL)
      return (var_expr *) ve;
    ZORBA_ERROR_LOC_PARAM (XPDY0002, loc, name, "");
  }

  expr_t pop_nodestack (int n = 1) {
    ZORBA_ASSERT (n >= 0);
    rchandle<expr> e_h;
    for (; n > 0; --n) {
      ZORBA_FATAL(! nodestack.empty(), "");
      e_h = nodestack.top();
      nodestack.pop();
#ifndef NDEBUG
      if (Properties::instance()->traceTranslator()) {
        cout << "Popped from nodestack:\n";
        if (e_h != NULL)
          e_h->put (cout) << endl;
        else
          cout << "NULL" << endl;
      }
#endif
    }
    return e_h;
  }

  varref_t pop_nodestack_var () {
    expr_t e = pop_nodestack ();
    assert (e == NULL || e->get_expr_kind () == var_expr_kind);
    return static_cast<var_expr *> (e.getp ());
  }

  xqtref_t pop_tstack()
  { return pop_stack (tstack); }

  expr_t peek_nodestk_or_null () {
    return (nodestack.empty ()) ? expr_t (NULL) : peek_stack (nodestack);
  }

  varref_t create_var (const QueryLoc& loc, store::Item_t qname, var_expr::var_kind kind, xqtref_t type = NULL) {
    varref_t e = new var_expr (loc, kind, qname, global_decl_stack.size ());
    if (kind == var_expr::pos_var || kind == var_expr::count_var || kind == var_expr::wincond_pos_var || kind == var_expr::wincond_in_pos_var)
      type = GENV_TYPESYSTEM.POSITIVE_INTEGER_TYPE_ONE;
    e->set_type (type);
    return e;
  }

  varref_t create_var (const QueryLoc& loc, string varname, var_expr::var_kind kind, xqtref_t type = NULL) {
    store::Item_t qname = sctx_p->lookup_var_qname (varname, loc);
    return create_var (loc, qname, kind, type);
  }

  void bind_var (varref_t e, static_context *sctx) {
    assert (sctx != NULL);
    store::Item_t qname = e->get_varname ();
    if (! sctx->bind_var (qname, e.getp ()))
      ZORBA_ERROR_LOC_PARAM (XQST0049, e->get_loc (), qname->getStringValue (), "");
  }

  varref_t bind_var (const QueryLoc& loc, string varname, var_expr::var_kind kind, xqtref_t type = NULL) {
    varref_t e = create_var (loc, varname, kind, type);
    bind_var (e, sctx_p);
    return e;
  }
  varref_t bind_var (const QueryLoc& loc, store::Item_t varname, var_expr::var_kind kind, xqtref_t type = NULL) {
    varref_t e = create_var (loc, varname, kind, type);
    bind_var (e, sctx_p);
    return e;
  }

  varref_t bind_var_and_push (const QueryLoc& loc, store::Item_t varname, var_expr::var_kind kind, xqtref_t type = NULL) {
    varref_t e = bind_var (loc, varname, kind, type);
    nodestack.push (&*e);
    return e;
  }

  varref_t bind_var_and_push (const QueryLoc& loc, string varname, var_expr::var_kind kind, xqtref_t type = NULL) {
    return bind_var_and_push (loc, sctx_p->lookup_var_qname (varname, loc), kind, type);
  }

  void bind_udf (store::Item_t qname, function *f, int nargs, static_context *sctx, const QueryLoc& loc) {
    if (! sctx->bind_fn (qname, f, nargs))
      ZORBA_ERROR_LOC_PARAM (XQST0034, loc, qname->getStringValue (), loc.getFilenameBegin());
  }
  void bind_udf (store::Item_t qname, function *f, int nargs, const QueryLoc& loc) {
    bind_udf (qname, f, nargs, sctx_p, loc);
    bind_udf (qname, f, nargs, minfo->globals.get (), loc);
    if (export_sctx != NULL)
      bind_udf (qname, f, nargs, export_sctx, loc);
  }

  fo_expr *create_seq (const QueryLoc& loc) {
    return new fo_expr (loc, CACHED (op_concatenate, LOOKUP_OPN ("concatenate")));
  }

  void push_scope () {
#ifdef ZORBA_DEBUGGER
    theScopes.push_back( theScopedVariables.size() );
#endif
    sctx_list.push_back (sctx_p = sctx_p->create_child_context());
    ++scope_depth;
  }

  void pop_scope (int n = 1)
  {
#ifdef ZORBA_DEBUGGER
    theScopedVariables.erase( theScopedVariables.begin()+theScopes.back(), theScopedVariables.end() );
    theScopes.pop_back();
#endif
    while (n-- > 0) {
      static_context *parent = (static_context *) sctx_p->get_parent ();
      sctx_p = parent;
      --scope_depth;
      assert (scope_depth >= 0);
    }
  }

  rchandle<axis_step_expr> expect_axis_step_top () {
    rchandle<axis_step_expr> axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
    if (axisExpr == NULL) {
      cout << "Expecting axis step on top of stack; ";
      if (nodestack.top() != NULL)
        cout << "typeid(top()) = " << typeid(*nodestack.top()).name() << endl;
      else
        cout << "top is null\n";
      ZORBA_ASSERT (false);
    }
    return axisExpr;
  }

  var_expr *lookup_var (string varname) {
    return static_cast<var_expr *> (sctx_p->lookup_var (varname));
  }
  var_expr *lookup_var (store::Item_t varname) {
    return static_cast<var_expr *> (sctx_p->lookup_var (varname));
  }

  void push_elem_scope() {
    ns_ctx = new namespace_context(&*ns_ctx);
  }

  void pop_elem_scope() {
    ns_ctx = ns_ctx->get_parent();
  }

  expr_update_t update_type_check_for_if(
    expr_update_t lType1, 
    expr_update_t lType2, 
    const QueryLoc& aLoc)
  {
    switch(lType1)
    {
    case VACUOUS_EXPR:
      switch(lType2)
      {
      case VACUOUS_EXPR:
        return VACUOUS_EXPR;
        break;
      case SIMPLE_EXPR:
        return SIMPLE_EXPR;
        break;
      case UPDATE_EXPR:
        return UPDATE_EXPR;
        break;
      }
    case SIMPLE_EXPR:
      switch(lType2)
      {
      case VACUOUS_EXPR:
        return SIMPLE_EXPR;
        break;
      case SIMPLE_EXPR:
        return SIMPLE_EXPR;
        break;
      case UPDATE_EXPR:
        ZORBA_ERROR_LOC(XUST0001, aLoc);
        break;
      }
    case UPDATE_EXPR:
      switch(lType2)
      {
      case VACUOUS_EXPR:
        return UPDATE_EXPR;
        break;
      case SIMPLE_EXPR:
        ZORBA_ERROR_LOC(XUST0001, aLoc);
        break;
      case UPDATE_EXPR:
        return UPDATE_EXPR;
        break;
      }
    }
    ZORBA_ASSERT(false);
    return SIMPLE_EXPR;
  }
  
  void parse_xquery_version (rchandle<VersionDecl> vh) {
    if (vh != NULL) {
      string ver = vh->get_version ();
      if (ver == "1.0")
        xquery_version = 100;
      else if (ver == "1.1")
        xquery_version = 110;
      // ignore otherwise
    }
  }
  
expr_t wrap_in_atomization (expr_t e) {
  return new fo_expr (e->get_loc (), CACHED (fn_data, LOOKUP_FN ("fn", "data", 1)), e);
}

expr_t wrap_in_globalvar_assign(expr_t e) {
  const function *ctx_set = LOOKUP_OP2 ("ctxvar-assign");
  const function *ctx_get = LOOKUP_OP1 ("ctxvariable");

  for (list<global_binding>::iterator i = theGlobalVars.begin ();
      i != theGlobalVars.end ();
      i++)
  {
    global_binding b = *i;
    varref_t var = b.first;
    xqtref_t var_type = var->get_type ();
    expr_t expr = b.second;
    expr_t qname_expr = new const_expr (var->get_loc(), dynamic_context::var_key (&*var));

    if (expr != NULL) {
      if (expr->isUpdating())
        ZORBA_ERROR_LOC(XUST0001, e->get_loc());

      if (var_type != NULL)
        expr = new treat_expr (expr->get_loc (), expr, var->get_type (), XPTY0004);
      minfo->init_exprs.push_back (new fo_expr (var->get_loc(),
                                         ctx_set, qname_expr, expr));
    } else if (var_type != NULL) {
      expr_t get = new fo_expr (var->get_loc (), ctx_get, qname_expr);
      minfo->init_exprs.push_back (new treat_expr (var->get_loc (), get, var->get_type (), XPTY0004));
    }
  }

  if (! minfo->init_exprs.empty ()) {
    expr_update_t lUpdateType = e->getUpdateType();
    e = new sequential_expr (e->get_loc(), minfo->init_exprs, e);
    e->setUpdateType(lUpdateType);
  }

  return e;
}


/*******************************************************************************
  Create a LET clause for the given LET variable "lv", with the given expr "e" as
  its defining expression.
********************************************************************************/
rchandle<forlet_clause> wrap_in_letclause(expr_t e, varref_t lv) {
  assert (lv->get_kind () == var_expr::let_var);
  return new forlet_clause(forlet_clause::let_clause, lv, NULL, NULL, e.getp());
}


rchandle<forlet_clause> wrap_in_letclause(expr_t e, const QueryLoc& loc, string name) {
  return wrap_in_letclause (e, bind_var (loc, name, var_expr::let_var));
}


rchandle<forlet_clause> wrap_in_letclause(expr_t e) {
  return wrap_in_letclause (e, tempvar(e->get_loc(), var_expr::let_var));
}


/*******************************************************************************
  Create a FOR clause for the given FOR variable "fv" and its associated POS var
  "pv" (pv may be NULL). Use the given expr "e" as the defining expr for "fv". 
********************************************************************************/
rchandle<forlet_clause> wrap_in_forclause(expr_t e, varref_t fv, varref_t pv) {
  assert (fv->get_kind () == var_expr::for_var);
  if (pv != NULL)
    assert (pv->get_kind() == var_expr::pos_var);
  return new forlet_clause(forlet_clause::for_clause, fv, pv, NULL, e);
}


rchandle<forlet_clause> wrap_in_forclause(expr_t expr, bool add_posvar) {
  varref_t fv = tempvar(expr->get_loc(), var_expr::for_var);
  varref_t pv = (add_posvar ? tempvar(expr->get_loc(), var_expr::pos_var) : 
                                varref_t (NULL));
  return wrap_in_forclause (expr, fv, pv);
}


rchandle<forlet_clause> wrap_in_forclause(
    expr_t expr,
    const QueryLoc& loc,
    string fv_name,
    string pv_name)
{
  return wrap_in_forclause (expr,
                            bind_var (loc, fv_name, var_expr::for_var),
                            bind_var (loc, pv_name, var_expr::pos_var));
}


/*******************************************************************************
  Create a flwor expr that uses the given expr as its input.
********************************************************************************/
rchandle<flwor_expr> wrap_expr_in_flwor(expr* inputExpr, bool withContextSize)
{
  const QueryLoc& loc = inputExpr->get_loc();

  push_scope();

  rchandle<flwor_expr> flworExpr = new flwor_expr(loc);

  if (withContextSize) {
    // create a LET var equal to the seq returned by the input epxr
    rchandle<forlet_clause> lcInputSeq = wrap_in_letclause(inputExpr);

    // compute the size of the input seq
    rchandle<fo_expr> countExpr = new fo_expr(loc, LOOKUP_FN("fn", "count", 1));
    countExpr->add(lcInputSeq->get_var().getp());

    rchandle<forlet_clause> lcLast = wrap_in_letclause(countExpr.getp(),
                                                       loc,
                                                       LAST_IDX_VARNAME);

    // Iterate over the input seq
    rchandle<forlet_clause> fcDot = wrap_in_forclause(lcInputSeq->get_var().getp(),
                                                      loc,
                                                      DOT_VARNAME,
                                                      DOT_POS_VARNAME);
    flworExpr->add(lcInputSeq);
    flworExpr->add(lcLast);
    flworExpr->add(fcDot);
  } else {
    // Iterate over the input seq
    rchandle<forlet_clause> fcDot = wrap_in_forclause(inputExpr,
                                                      loc,
                                                      DOT_VARNAME,
                                                      DOT_POS_VARNAME);
    flworExpr->add(fcDot);
  }

  return flworExpr;
}


/*******************************************************************************

********************************************************************************/
expr_t wrap_in_dos_and_dupelim(expr_t expr) {
  rchandle<fo_expr> dos = new fo_expr(expr->get_loc(),
                                      LOOKUP_OP1("sort-distinct-nodes-asc-or-atomics"));
  dos->add(expr);
  return &*dos;
}


/*******************************************************************************

********************************************************************************/

void collect_flwor_vars (const FLWORExpr &e, set<const var_expr *> &vars, const FLWORClause *start, const FLWORClause *end, bool inclusive) {
  const FLWORClauseList &clauses = *e.get_clause_list ();
  int i;
  for (i = clauses.size () - 1; i >= 0; --i) {
    if (&*clauses [i] == end) {
      if (! inclusive) --i;
      break;
    }
  }
  assert (i >= 0);
  for (;; i--) {
    const FLWORClause &c = *clauses [i];
    if (typeid (c) == typeid (ForClause)) {
      const VarInDeclList &lV = *(static_cast<const ForClause *> (&c)->get_vardecl_list());
      for (int j =  lV.size() - 1; j >= 0; --j) {
        vars.insert (lookup_var (lV [j]->get_varname()));
      }
    } else if (typeid (c) == typeid (LetClause)) {
      const VarGetsDeclList &lV = *(static_cast<const LetClause *> (&c)->get_vardecl_list());
      for (int j =  lV.size() - 1; j >= 0; --j) {
        vars.insert (lookup_var (lV [j]->get_varname()));
      }
    } else if (typeid (c) == typeid (WindowClause)) {
      const WindowClause &wc = *static_cast<const WindowClause *> (&c);
      vars.insert (lookup_var (wc.get_var ()->get_varname()));
      for (int j = 1; j >= 0; j--) {
        const FLWORWinCond *cond = &*wc [j];
        if (cond != NULL) {
          const WindowVars *wv = &*cond->get_winvars ();
          if (wv != NULL) {
            if (! wv->get_next ().empty ())
              vars.insert (lookup_var (wv->get_next ()));
            if (! wv->get_prev ().empty ())
              vars.insert (lookup_var (wv->get_prev ()));
            if (! wv->get_curr ().empty ())
              vars.insert (lookup_var (wv->get_curr ()));
            if (wv->get_posvar () != NULL)
              vars.insert (lookup_var (wv->get_posvar ()->get_varname()));
          }
        }
      }
    } else if (typeid (c) == typeid (CountClause)) {
        vars.insert (lookup_var (static_cast<const CountClause *> (&c)->get_varname ()));
    } else if (typeid (c) == typeid (OrderByClause) || typeid (c) == typeid (GroupByClause)) {
      collect_flwor_vars (e, vars, &*clauses [0], &c, false);
      // order-by and group-by shadow all previous variables
      break;
    }
    if (&c == start) break;
  }
}

/*******************************************************************************

********************************************************************************/


void *begin_visit (const exprnode& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const exprnode& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


/*******************************************************************************

********************************************************************************/
void *begin_visit (const ArgList& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ArgList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


/*******************************************************************************

********************************************************************************/
void *begin_visit (const QueryBody& v) {
  TRACE_VISIT ();
  // fictious :query-body operator
  // TODO: should be local::query-body, but some C examples fail to
  // properly initialize the store
  global_decl_stack.push ("F" + static_context::qname_internal_key (sctx_p->lookup_fn_qname ("fn", ":query-body", loc)));
  return no_state;
}

void end_visit (const QueryBody& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  pop_stack (global_decl_stack);
  nodestack.push(wrap_in_globalvar_assign(pop_nodestack()));
}


/*******************************************************************************

********************************************************************************/
void *begin_visit (const BaseURIDecl& v) {
  TRACE_VISIT ();
  CHK_SINGLE_DECL (hadBUriDecl, XQST0032);
  try {
    sctx_p->set_baseuri(v.get_base_uri());
  } catch (error::ZorbaError&) {
    // assume it's a relative uri and we will resolve it later.
    // It's currently a problem if the uri is absolute but invalid
  }
  return NULL;
}

void end_visit (const BaseURIDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const BoundarySpaceDecl& v) {
  TRACE_VISIT ();
  CHK_SINGLE_DECL (hadBSpaceDecl, XQST0068);
  sctx_p->set_boundary_space_mode(v.get_boundary_space_mode());
  return NULL;
}

void end_visit (const BoundarySpaceDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const CaseClause& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CaseClause& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const CaseClauseList& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CaseClauseList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const ConstructionDecl& v) {
  TRACE_VISIT ();
  CHK_SINGLE_DECL (hadConstrDecl, XQST0067);
  sctx_p->set_construction_mode(v.get_mode());
  return NULL;
}

void end_visit (const ConstructionDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const CopyNamespacesDecl& v) {
  TRACE_VISIT ();
  CHK_SINGLE_DECL (hadCopyNSDecl, XQST0055);
  return no_state;
}

void end_visit (const CopyNamespacesDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
 sctx_p->set_inherit_mode  (v.get_inherit_mode ());
 sctx_p->set_preserve_mode (v.get_preserve_mode ());
}


void *begin_visit (DefaultCollationDecl const& v) {
  TRACE_VISIT ();
  string uri = v.get_collation();
  sctx_p->set_default_collation_uri(uri);
  return NULL;
}

void end_visit (const DefaultCollationDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (DefaultNamespaceDecl const& v) {
  TRACE_VISIT ();
  switch (v.get_mode()) {
  case ParseConstants::ns_element_default:
    sctx_p->set_default_elem_type_ns (v.get_default_namespace ());
    break;
  case ParseConstants::ns_function_default:
    sctx_p->set_default_function_namespace (v.get_default_namespace ());
    break;
  }
  return NULL;
}

void end_visit (const DefaultNamespaceDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const EmptyOrderDecl& v) {
  TRACE_VISIT ();
  CHK_SINGLE_DECL (hadEmptyOrdDecl, XQST0069);
  sctx_p->set_order_empty_mode(v.get_mode());
  return no_state;
}

void end_visit (const EmptyOrderDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


/*******************************************************************************

   Enclosed Expr
   Used in direct and computed node constructors.

********************************************************************************/
void *begin_visit (const EnclosedExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const EnclosedExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  expr_t lContent = pop_nodestack();
  fo_expr *fo_h = new fo_expr(loc, CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
  fo_h->add(lContent);
  nodestack.push(fo_h);
}

void *begin_visit (const BlockBody& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const BlockBody& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  vector<expr_t> statements;
  for (int i = 0; i < v.size(); i++)
    statements.push_back (pop_nodestack ());
  reverse (statements.begin (), statements.end ());
  nodestack.push (new sequential_expr (loc, statements, create_seq (loc)));
}


/*******************************************************************************

  Node Construction

********************************************************************************/

void *begin_visit (const DirCommentConstructor& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const DirCommentConstructor& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  xqpString str = v.get_comment();
  expr_t content = new const_expr (loc, str);
  nodestack.push (new text_expr(loc,
                                text_expr::comment_constructor,
                                content));
}

void *begin_visit (const DirPIConstructor& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const DirPIConstructor& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  xqp_string target_str = v.get_pi_target ();
  if (target_str.uppercase () == "XML")
    ZORBA_ERROR_LOC ( XPST0003, loc);
  expr_t
    target = new const_expr (loc, target_str),
    content = new const_expr (loc, v.get_pi_content ());
  nodestack.push (new pi_expr (loc, target,  content));
}


void *begin_visit (const DirElemConstructor& v) {
  TRACE_VISIT();
  push_scope();
  push_elem_scope();
  return no_state;
}

void end_visit (const DirElemConstructor& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  expr_t nameExpr;
  expr_t attrExpr;
  expr_t contentExpr;

  rchandle<QName> end_tag = v.get_end_name(), start_tag = v.get_elem_name ();
  if (end_tag != NULL && start_tag->get_qname() != end_tag->get_qname ())
    ZORBA_ERROR_LOC_DESC( XPST0003, loc, string ("Start tag ") + start_tag->get_qname () + " does not match end tag " + end_tag->get_qname());

  if (v.get_dir_content_list() != NULL)
    contentExpr = pop_nodestack();

  if (v.get_attr_list() != NULL)
    attrExpr = pop_nodestack();

  nameExpr = new const_expr(loc,
                            sctx_p->lookup_elem_qname(v.get_elem_name()->get_qname(), loc));

  nodestack.push(new elem_expr(loc,
                               nameExpr,
                               attrExpr,
                               contentExpr,
                               ns_ctx));
  pop_elem_scope();
  pop_scope();
}

/**
 * Inserts an entry in theIsWSBoundaryStack and thePossibleWSContentStack to save
 * information during boundary whitespace checking.
 */
void begin_check_boundary_whitespace() {
  if (sctx_p->boundary_space_mode() == StaticContextConsts::strip_space) {
    theIsWSBoundaryStack.push(true);
    thePossibleWSContentStack.push(0);
  }
}

/**
 * Whitespace checking. Checks if v might be a whitespace (check of the following boundary can
 * only be checked during the next invocation), and if the items saved in thePossibleWSContentStack
 * is really boundary whitespace.
 */
void check_boundary_whitespace(const DirElemContent& v) {
  v.setIsStripped(false);
  if (sctx_p->boundary_space_mode() == StaticContextConsts::strip_space) {
    bool lPrevIsBoundary = pop_stack (theIsWSBoundaryStack);
    const DirElemContent* lPrev = peek_stack (thePossibleWSContentStack);
    thePossibleWSContentStack.pop();

    if (v.get_direct_cons() != 0 || (v.get_common_content() != 0 && v.get_common_content()->get_expr() != 0)) {
      thePossibleWSContentStack.push(0);
      theIsWSBoundaryStack.push(true);
      if (lPrev != 0) {
        lPrev->setIsStripped(true);
      }
    } else if (v.get_common_content() != 0 || v.get_cdata() != 0) {
      thePossibleWSContentStack.push(0);
      theIsWSBoundaryStack.push(false);
    } else {
      bool lCouldBe = false;
      if (lPrevIsBoundary) {
        xqpString content = v.get_elem_content();
        // Filtering out of whitespaces
        if (content.trim(" \n\r\t", 4).empty()) {
          lCouldBe = true;
        }
      }
      if (lCouldBe) {
        thePossibleWSContentStack.push(&v);
      } else {
        thePossibleWSContentStack.push(0);
      }
      theIsWSBoundaryStack.push(false);
    }
  }
}

/**
 * Deletes the entries in theIsWSBoundaryStack and thePossibleWSContentStack. If thePossibleWSContentStack
 * contains an item, this item is boundary whitespace because end of content is a boundary.
 */
void end_check_boundary_whitespace() {
  if (sctx_p->boundary_space_mode() == StaticContextConsts::strip_space) {
    const DirElemContent* lPrev = pop_stack (thePossibleWSContentStack);
    if (lPrev != 0) {
      lPrev->setIsStripped(true);
    }
    theIsWSBoundaryStack.pop();
  }
}

void *begin_visit (const DirElemContentList& v) {
  TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit (const DirElemContentList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  rchandle<fo_expr> expr_list = create_seq (loc);
  while (true) {
    expr_t e_h = pop_nodestack();
    if (e_h == NULL)
      break;
    expr_list->add(e_h);
  }
  if (expr_list->size() == 1)
    nodestack.push(*expr_list->begin());
  else {
    nodestack.push(expr_list.getp ());
  }
}


void *begin_visit (const DirElemContent& v) {
  TRACE_VISIT ();

  return no_state;
}

void end_visit (const DirElemContent& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  if (v.get_direct_cons() != NULL) {
    // nothing to be done, the content expression is already on the stack
  }
  else if (v.get_cdata() != NULL) {
  }
  else if (v.get_common_content() != NULL) {
  } else {
    if (!v.isStripped()) {
      expr_t content = new const_expr (loc, v.get_elem_content());
      nodestack.push (new text_expr(loc,
                                    text_expr::text_constructor,
                                    content));
    }
  }
}


void *begin_visit (const CDataSection& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CDataSection& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  expr_t content = new const_expr (loc, v.get_cdata_content ());
  nodestack.push (new text_expr (loc, text_expr::text_constructor, content));
}


void *begin_visit (const DirAttributeList& v) {
  TRACE_VISIT ();

  nodestack.push(NULL);
  // visit prefix attributes first
  for (int visitType = 0; visitType < 2; visitType++)
    for (int i = 0; i < v.size (); i++) {
      const DirAttr *attr = v [i];
      const QName* qname = attr->get_name().getp();
      bool isPrefix = qname->get_qname() == "xmlns" || qname->get_prefix() == "xmlns";
      if ((isPrefix && visitType == 0)
          || (! isPrefix && visitType == 1))
        attr->accept (*this);
    }

  unsigned long numAttrs = 0;
  vector<rchandle<attr_expr> > attributes;
  while(true) {
    expr_t expr = pop_nodestack();
    if (expr == NULL)
      break;

    attr_expr* attrExpr = expr.dyn_cast<attr_expr> ().getp();

    for (unsigned long i = 0; i < numAttrs; i++) {
      if (attributes[i]->getQName()->equals(attrExpr->getQName()))
         ZORBA_ERROR_LOC( XQST0040, loc);
    }

    attributes.push_back(attrExpr);
    numAttrs++;
  }

  if (attributes.size() == 1)
    nodestack.push(attributes[0].getp());
  else {
    fo_expr* expr_list = create_seq(loc);

    for (vector<rchandle<attr_expr> >::reverse_iterator it = attributes.rbegin();
         it != attributes.rend();
         ++it)
    {
      expr_list->add((*it).cast<expr> ());
    }

    nodestack.push(expr_list);
  }

  return NULL;  // reject visitor -- everything done
}

void end_visit (const DirAttributeList& v, void* /*visit_state*/) {
  // begin_visit() rejects visitor
  ZORBA_ASSERT (false);
}


void *begin_visit (const DirAttr& v) {
  TRACE_VISIT ();
  // boundary is needed because the value of an attribute might be empty
  nodestack.push(NULL);
  return no_state;
}

void end_visit (const DirAttr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  expr_t valueExpr = pop_nodestack();

  if (valueExpr != NULL) {
    // delete boundary
    nodestack.pop();
  }

  QName* qname = v.get_name().getp();

  if (qname->get_qname() == "xmlns" || qname->get_prefix() == "xmlns") {
    xqpString prefix;

    if (qname->get_qname() != "xmlns") {
      prefix = qname->get_localname();
      if (prefix == "xmlns")
        ZORBA_ERROR_LOC (XQST0070, loc);
    }
    // else we have a defult-namespace declaration

    const_expr* constValueExpr = valueExpr.dyn_cast<const_expr> ().getp();
    if (constValueExpr != NULL) {
      xqpString uri(constValueExpr->get_val()->getStringValue());

      if ((prefix == "xml") != (uri == XML_NS))
        ZORBA_ERROR_LOC (XQST0070, loc);
      sctx_p->bind_ns(prefix, uri, XQST0071);
      ns_ctx->bind_ns(prefix, uri);
    } else if (valueExpr == NULL) {
      if (prefix == "xml")
        ZORBA_ERROR_LOC ( XQST0070, loc);

      // unbind the prefix
      sctx_p->bind_ns(prefix, "", XQST0071);
      ns_ctx->bind_ns(prefix, "");
    }
    else
      ZORBA_ERROR_LOC( XQST0022, loc);
  } else {
    expr_t nameExpr = new const_expr(loc,
                                     sctx_p->lookup_qname("", qname->get_qname(), loc));
    expr_t attrExpr = new attr_expr(loc, nameExpr, valueExpr);
    nodestack.push(attrExpr);
  }
}


void *begin_visit (const DirAttributeValue& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const DirAttributeValue& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void attr_content_list(const QueryLoc& loc, void* /*visit_state*/)
{
  rchandle<fo_expr> expr_list_t = create_seq(loc);
  expr_t e_h;
  while(true)
  {
    expr_t e_h = pop_nodestack();
    if (e_h == NULL)
      break;
    expr_list_t->add(e_h);
  }

  if (expr_list_t->size() == 1)
    nodestack.push(*expr_list_t->begin());
  else if (expr_list_t->size() > 1)
    nodestack.push(expr_list_t.getp());
}

void *begin_visit (const QuoteAttrContentList& v) {
  TRACE_VISIT ();

  nodestack.push(NULL);
  return no_state;
}

void end_visit (const QuoteAttrContentList& v, void* visit_state) {
  TRACE_VISIT_OUT ();
  attr_content_list(loc, visit_state);
}


void *begin_visit (const AposAttrContentList& v) {
  TRACE_VISIT ();

  nodestack.push(NULL);
  return no_state;
}

void end_visit (const AposAttrContentList& v, void* visit_state) {
  TRACE_VISIT_OUT ();
  attr_content_list (loc, visit_state);
}


void attr_val_content (const QueryLoc& loc, const CommonContent *cc, xqpString content)
{
  if (cc == NULL) {
    nodestack.push(new const_expr (loc, content));

    //    nodestack.push(new text_expr(loc,
    //                            text_expr::text_constructor,
    //                            new const_expr (loc, content)));
  }
  else
  {
    // nothing to be done because when common content != NULL,
    // the corresponding expr is already on the stack
  }
}

void *begin_visit (const QuoteAttrValueContent& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const QuoteAttrValueContent& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  attr_val_content (loc, v.get_common_content(), v.get_quot_atcontent());
}


void *begin_visit (const AposAttrValueContent& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const AposAttrValueContent& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  attr_val_content (loc, v.get_common_content(), v.get_apos_atcontent());
}


void *begin_visit (const CommonContent& v) {
  TRACE_VISIT ();

  return no_state;
}

void end_visit (const CommonContent& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  switch (v.get_type())
  {
  case ParseConstants::cont_entity:
  {
    ZORBA_ASSERT (false); 
    break;
  }
  case ParseConstants::cont_charref:
  {
    string content;
    string charrefs = v.get_ref();

    const char* curRef = charrefs.c_str();
    const char* end = curRef + charrefs.size();

    while (curRef < end)
    {
      int d = decode_entity(curRef, &content);
      if (d<0)
        ZORBA_ERROR_LOC(XPST0003, loc);
      else
        curRef += d;

      if (curRef >= end)
        break;

      if (*curRef == '&')
        curRef++;
    }

    expr_t lConstExpr = new const_expr(loc, content);
    nodestack.push(lConstExpr);
    break;
  }
  case ParseConstants::cont_escape_lbrace:
  {
    // we always create a text node here because if we are in an attribute, we atomice
    // the text node into its string value
    xqpString content("{");
    expr_t lConstExpr = new const_expr(loc, content);
    nodestack.push ( lConstExpr );
    break;
  }
  case ParseConstants::cont_escape_rbrace:
  {
    // we always create a text node here because if we are in an attribute, we atomice
    // the text node into its string value
    xqpString content("}");
    expr_t lConstExpr = new const_expr(loc, content);
    nodestack.push ( lConstExpr );
    break;
  }
  case ParseConstants::cont_expr:
  {
    break;
  }
  }
}


void *begin_visit (const CompDocConstructor& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CompDocConstructor& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  expr_t lContent = pop_nodestack();

  fo_expr *lEnclosed = new fo_expr(loc, CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
  lEnclosed->add(lContent);

  nodestack.push (new doc_expr (loc, lEnclosed ));
}


void *begin_visit (const CompElemConstructor& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CompElemConstructor& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  expr_t nameExpr, contentExpr;

  if (v.get_content_expr() != 0) {
    contentExpr = pop_nodestack();

    fo_expr *lEnclosed = new fo_expr(loc, CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
    lEnclosed->add(contentExpr);
    contentExpr = lEnclosed;
  }

  QName* constQName = v.get_qname_expr().dyn_cast<QName> ().getp();

  if (constQName != NULL) {
    nameExpr = new const_expr(loc,
                              sctx_p->lookup_elem_qname(constQName->get_qname(), loc));
  } else {
    nameExpr = pop_nodestack();

    rchandle<fo_expr> atomExpr = (fo_expr*)wrap_in_atomization (nameExpr).getp();
    nameExpr = new name_cast_expr(loc, atomExpr.getp(), ns_ctx);
  }

  nodestack.push (new elem_expr(loc, nameExpr, contentExpr, ns_ctx));
}


void *begin_visit (const CompAttrConstructor& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CompAttrConstructor& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  expr_t nameExpr;
  expr_t valueExpr;
  expr_t attrExpr;

  if (v.get_val_expr() != 0) {
    valueExpr = pop_nodestack();

    fo_expr* enclosedExpr = new fo_expr(loc, CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
    enclosedExpr->add(valueExpr);

    valueExpr = enclosedExpr;
  }

  QName* constQName = v.get_qname_expr().dyn_cast<QName> ().getp();

  if (constQName != NULL) {
    nameExpr = new const_expr(loc,
                              sctx_p->lookup_qname("", constQName->get_qname(), loc));
  } else {
    nameExpr = pop_nodestack();

    rchandle<fo_expr> atomExpr = (fo_expr*)wrap_in_atomization (nameExpr).getp();

    expr_t castExpr = new name_cast_expr(loc,
                                         atomExpr.getp(),
                                         ns_ctx);
    nameExpr = castExpr;
  }

  attrExpr = new attr_expr(loc, nameExpr, valueExpr);

  nodestack.push(attrExpr);
}


void *begin_visit (const CompCommentConstructor& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CompCommentConstructor& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  expr_t inputExpr = pop_nodestack();

  rchandle<fo_expr> enclosedExpr = new fo_expr(loc,
                                               CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
  enclosedExpr->add(inputExpr);

  expr_t textExpr = new text_expr(loc,
                                  text_expr::comment_constructor,
                                  enclosedExpr.getp());

  nodestack.push(textExpr);
}


void *begin_visit (const CompPIConstructor& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CompPIConstructor& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  expr_t target;
  expr_t content;

  if (v.get_content_expr() == NULL) {
    content = create_seq(loc);
  } else {
    content = pop_nodestack();

    rchandle<fo_expr> enclosedExpr = new fo_expr(loc, CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
    enclosedExpr->add(content);

    content = enclosedExpr;
  }

  if (v.get_target_expr() != NULL) {
    target = pop_nodestack();

    rchandle<fo_expr> atomExpr = (fo_expr*)wrap_in_atomization (target).getp();

    rchandle<cast_expr> castExpr =
      new cast_expr(loc, atomExpr.getp(),
                    GENV_TYPESYSTEM.NCNAME_TYPE_ONE);

    rchandle<fo_expr> enclosedExpr = new fo_expr(loc, CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
    enclosedExpr->add(castExpr.getp());

    target = enclosedExpr;
  }

  expr_t e = (v.get_target_expr () != NULL ?
              new pi_expr (loc, target, content) :
              new pi_expr (loc, new const_expr (loc, v.get_target()), content));

  nodestack.push (e);
}


void *begin_visit (const CompTextConstructor& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CompTextConstructor& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  expr_t inputExpr = pop_nodestack();

  rchandle<fo_expr> enclosedExpr = new fo_expr(loc,
                                               CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
  enclosedExpr->add(inputExpr);

  expr_t textExpr = new text_expr(loc,
                                  text_expr::text_constructor,
                                  enclosedExpr.getp());

  nodestack.push(textExpr);
}


/*******************************************************************************

  FLWOR Expression

********************************************************************************/
void *begin_visit (const FLWORExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void pop_wincond_vars (rchandle<WindowVars> node, flwor_wincond::vars &vars) {
  if (node != NULL) {
    if (! node->get_next ().empty ())
      vars.next = pop_nodestack_var ();
    if (! node->get_prev ().empty ())
      vars.prev = pop_nodestack_var ();
    if (! node->get_curr ().empty ())
      vars.curr = pop_nodestack_var ();
    if (node->get_posvar () != NULL)
      vars.posvar = pop_nodestack_var ();
  }
}

void translate_gflwor (const FLWORExpr& v) {
  const QueryLoc &loc = v.get_location ();
  const FLWORClauseList &clauses = *v.get_clause_list ();
  vector <rchandle<flwor_clause> > eclauses;

  expr_t lReturnExpr = pop_nodestack ();
#ifdef ZORBA_DEBUGGER
  if ( compilerCB->m_debugger != 0) {
    const QueryLoc& return_location = v.get_return_location(); 
    rchandle<debugger_expr> lDebuggerExpr = new debugger_expr(return_location, lReturnExpr,
								theScopedVariables, theGlobalVars);
   lReturnExpr = lDebuggerExpr;
  }
#endif

  rchandle<gflwor_expr> flwor = new gflwor_expr (loc, lReturnExpr);
  flwor->setUpdateType(lReturnExpr->getUpdateType());

  for (int i = clauses.size () - 1; i >= 0; i--) {
    vector<rchandle <var_expr> > vars, pos_vars;
    vector<rchandle <expr> > exprs;
    int nvars;

    const FLWORClause &c = *clauses [i];
    if (typeid (c) == typeid (WindowClause)) {
      pop_scope (2);  // var decl + outer window conditions
      const WindowClause &wc = *static_cast<const WindowClause *> (&c);
      flwor_wincond::vars out_vars [2];
      for (int i = 1; i >= 0; i--) {
        rchandle<FLWORWinCond> cond = wc [i];
        if (cond != NULL) {
          rchandle<WindowVars> vars = cond->get_winvars ();
          pop_wincond_vars (vars, out_vars [i]);
        }
      }
      varref_t wvar = pop_nodestack_var ();
      expr_t val = pop_nodestack ();
      auto_ptr<flwor_wincond> econds [2];
      for (int i = 1; i >= 0; i--) {
        rchandle<FLWORWinCond> cond = wc [i];
        if (cond != NULL) {
          expr_t val = pop_nodestack ();
          flwor_wincond::vars in_vars;

          rchandle<WindowVars> vars = cond->get_winvars ();
          pop_wincond_vars (vars, in_vars);
          econds [i].reset (new flwor_wincond (cond->is_only (), in_vars, out_vars [i], val));
        }
      }
      forletwin_gclause *flwc =
        new forletwin_gclause (forletwin_gclause::win_clause, wvar, val,
                               NULL, NULL,
                               wc.get_wintype () == WindowClause::tumbling_window ? forletwin_gclause::tumbling_window : forletwin_gclause::sliding_window,
                               econds [0], econds [1]);
      
      eclauses.push_back (flwc);
    } else if (typeid (c) == typeid (ForClause)) {
      const ForClause &flc = *static_cast<const ForClause *> (&c);
      nvars = flc.get_decl_count ();
      VarInDeclList *decl_list = &*flc.get_vardecl_list ();

      for (int j = nvars - 1; j >= 0; j--) {
        var_expr_t ve;
        ve = pop_nodestack_var ();
        ve->set_kind (var_expr::for_var);
        vars.push_back (ve);
        expr_t lValueExpr = pop_nodestack();
        if (lValueExpr->isUpdating())
          ZORBA_ERROR_LOC(XUST0001, loc);
        exprs.push_back(lValueExpr);
        if ((*decl_list) [j]->get_posvar () == NULL)
          pos_vars.push_back (NULL);
        else {
          var_expr_t pve = pop_nodestack_var ();
          pve->set_kind (var_expr::pos_var);
          pos_vars.push_back (pve);
        }
        pop_scope ();
      }

      for (int j = 0; j < nvars; j++) {
        expr_t lExpr = exprs[j];
        varref_t lVar = vars[j];
#ifdef ZORBA_DEBUGGER
        if(compilerCB->m_debugger != 0)
        {
          push_scope();
          for(int k=nvars; k>j; k--)
          {
            theScopedVariables.push_back(vars[k-1]);
          }
          lExpr = new debugger_expr(exprs[j]->get_loc(), lExpr, theScopedVariables, theGlobalVars, true);
          //lVar = new debugger_expr(lVar->get_loc(), lVar, theScopedVariables, theGlobalVars, true);
          pop_scope();
        }
#endif
        forletwin_gclause *eflc = 
          new forletwin_gclause (forletwin_gclause::for_clause, lVar, lExpr, pos_vars [j]);
#ifdef ZORBA_DEBUGGER
        if(compilerCB->m_debugger != 0)
        {
          theScopedVariables.push_back(vars[j]);
          if(pos_vars[j] != 0)
          {
            theScopedVariables.push_back(pos_vars[j]);
          }
          eflc->set_bound_variables(theScopedVariables);
          eflc->set_global_variables(theGlobalVars);
        }
#endif
        eflc->set_outer (flc.is_outer ());
        eclauses.push_back (eflc);
      }
    } else if (typeid (c) == typeid (LetClause)) {
      const LetClause &flc = *static_cast<const LetClause *> (&c);
      nvars = flc.get_decl_count ();
      for (int j = 0; j < nvars; j++) {
        var_expr_t ve = pop_nodestack_var ();
        expr_t lValueExpr = pop_nodestack();
        if (lValueExpr->isUpdating())
          ZORBA_ERROR_LOC(XUST0001, loc);
        exprs.push_back(lValueExpr);
        ve->set_kind (var_expr::let_var);
        vars.push_back (ve);
        pop_scope ();
      }

      for (int j = 0; j < nvars; j++)
      {
        expr_t lExpr = exprs[j];
#ifdef ZORBA_DEBUGGER
        if(compilerCB->m_debugger != 0)
        {
          push_scope();
          for(int k=nvars; k-1>j; k--)
          {
            theScopedVariables.push_back(vars[k-1]);
          }
          lExpr = new debugger_expr(exprs[j]->get_loc(), lExpr, theScopedVariables, theGlobalVars);
          pop_scope();
        }
#endif
        forletwin_gclause *flc = new forletwin_gclause (forletwin_gclause::let_clause, vars [j], lExpr);
        eclauses.push_back (flc);
      }
    } else if (typeid (c) == typeid (WhereClause)) {
      eclauses.push_back (new where_gclause (c.get_location (), pop_nodestack ()));
    } else if (typeid (c) == typeid (CountClause)) {
      eclauses.push_back (new count_gclause (c.get_location (), pop_nodestack_var ()));
    } else if (typeid (c) == typeid (GroupByClause)) {
      const GroupByClause *gbc = static_cast<const GroupByClause *> (&c);
      const GroupSpecList &gl = *gbc->get_spec_list();
      vector<string> collations;

      group_gclause::rebind_list_t inner_rebind, outer_rebind;
      for (int i = gl.size () - 1; i >= 0; i--) {
        const GroupSpec* lSpec = &*gl[i];
        if (lSpec->group_coll_spec() != NULL)
          collations.push_back (lSpec->group_coll_spec()->get_uri());
        else
          collations.push_back ("");
        
        varref_t outer_var = pop_nodestack_var ();
        varref_t inner_var = pop_nodestack_var ();
        inner_rebind.push_back (pair<varref_t, varref_t> (inner_var, outer_var));
        pop_scope();
      }
      
      reverse (collations.begin (), collations.end ());
      reverse (inner_rebind.begin (), inner_rebind.end ());

      varref_t outer_var;
      while (NULL != (outer_var = pop_nodestack_var ())) {
        varref_t inner_var = pop_nodestack_var ();
        outer_rebind.push_back (pair<varref_t, varref_t> (inner_var, outer_var));
        pop_scope();
      }
      
      eclauses.push_back (new group_gclause (c.get_location (), inner_rebind, outer_rebind, collations));
    } else if (typeid (c) == typeid (OrderByClause)) {
      const OrderByClause *obc = static_cast<const OrderByClause *> (&c);
      OrderSpecList *order_list = obc->get_spec_list ();

      // order by most-significant key last
      for (unsigned i = 0; i < order_list->size (); i++) {
        OrderSpec *spec = &*((*order_list) [i]);
        OrderModifier *mod = &*spec->get_modifier ();
        ParseConstants::dir_spec_t dir_spec = ParseConstants::dir_ascending;
        if (mod && mod->get_dir_spec () != NULL)
          dir_spec = mod->get_dir_spec ()->get_dir_spec ();
        StaticContextConsts::order_empty_mode_t empty_spec = sctx_p->order_empty_mode ();
        if (mod && mod->get_empty_spec () != NULL)
          empty_spec = mod->get_empty_spec ()->get_empty_order_spec ();
        string col = sctx_p->default_collation_uri ();
        if (mod && mod->get_collation_spec () != NULL)
          col = mod->get_collation_spec ()->get_uri ();
        if (! sctx_p->has_collation_uri (col))
          ZORBA_ERROR_LOC (XQST0076, loc);
      
        orderby_gclause::rebind_list_t rebind_list;
        for (;;) {
          varref_t inner = pop_nodestack_var ();
          if (inner == NULL) break;
          rebind_list.push_back (pair<varref_t, varref_t> (inner, pop_nodestack_var ()));
        }
        expr_t lOrderExpr = pop_nodestack ();
        if (lOrderExpr->isUpdating())
          ZORBA_ERROR_LOC(XUST0001, loc);
        pop_scope ();
          
        // since we're translating each order-spec into a separate
        // order-by clause, the ordering MUST be stable
        rchandle<orderby_gclause> obgc = new orderby_gclause (c.get_location (), dir_spec, empty_spec, col, true /* obc->get_stable_bit () */, lOrderExpr);
        obgc->set_rebind (rebind_list);
        eclauses.push_back (obgc.cast<flwor_clause> ());
      }
    }
  }

  for (int i = eclauses.size () - 1; i >= 0; i--)
    flwor->push_back (eclauses [i]);

  nodestack.push (&*flwor);
}

void end_visit (const FLWORExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  if (v.is_general ()) {
    translate_gflwor (v);
    return;
  }

  int i, j;

  expr_t lReturnExpr = pop_nodestack ();
  
  rchandle<flwor_expr> flwor = new flwor_expr (loc);
  flwor->setUpdateType(lReturnExpr->getUpdateType());
  flwor->set_retval (lReturnExpr);
  OrderByClause *orderby = &*v.get_orderby ();
  if (orderby) {
    flwor->set_order_stable (orderby->get_stable_bit ());
    OrderSpecList *order_list = &*orderby->get_spec_list ();
    int n = order_list->size ();
    vector<expr_t> orders (n);
    generate (orders.rbegin (), orders.rend (), stack_to_generator (nodestack));
    for (i = 0; i < n; i++) {
      OrderSpec *spec = &*((*order_list) [i]);
      OrderModifier *mod = &*spec->get_modifier ();
      ParseConstants::dir_spec_t dir_spec = ParseConstants::dir_ascending;
      if (mod && mod->get_dir_spec () != NULL)
        dir_spec = mod->get_dir_spec ()->get_dir_spec ();
      StaticContextConsts::order_empty_mode_t empty_spec = sctx_p->order_empty_mode ();
      if (mod && mod->get_empty_spec () != NULL)
        empty_spec = mod->get_empty_spec ()->get_empty_order_spec ();
      string col = sctx_p->default_collation_uri ();
      if (mod && mod->get_collation_spec () != NULL)
        col = mod->get_collation_spec ()->get_uri ();
      if (! sctx_p->has_collation_uri (col))
        ZORBA_ERROR_LOC (XQST0076, loc);
      rchandle<order_modifier> emod (new order_modifier (dir_spec, empty_spec, col));
      expr_t lOrderExpr = orders [i];
      if (lOrderExpr->isUpdating()) {
        ZORBA_ERROR_LOC(XUST0001, loc);
      }
      flwor->add (flwor_expr::orderspec_t (lOrderExpr, emod));
    }
  }

  GroupByClause *lGroupBy = &*v.get_groupby();
  if (lGroupBy) {
    if (lGroupBy->get_where() != 0) {
      expr_t lClauseExpr = pop_nodestack();
      if (lClauseExpr->isUpdating())
        ZORBA_ERROR_LOC(XUST0001, loc);
      flwor->set_group_where(lClauseExpr);
    }

    // TODO let after group by

    GroupSpecList *lGroupList = lGroupBy->get_spec_list();
    size_t lSize = lGroupList->size();
    vector<rchandle<group_clause> > gclauses;
    for (int i = (lSize-1); i >= 0; --i) {
      GroupSpec* lSpec = &*((*lGroupList)[i]);

      varref_t inner_var = pop_nodestack_var ();
      varref_t outer_var = pop_nodestack_var ();

      group_clause* lClause = NULL;
      if (lSpec->group_coll_spec() != NULL)
        lClause = new group_clause(outer_var, inner_var, lSpec->group_coll_spec()->get_uri());
      else
        lClause = new group_clause(outer_var, inner_var);
      gclauses.push_back (lClause);
      pop_scope();
    }
    for (int i = gclauses.size () - 1; i >= 0; --i)
      flwor->add (gclauses [i]);

    varref_t inner_var;
    while (NULL != (inner_var = pop_nodestack_var ())) {
      varref_t outer_var = pop_nodestack_var ();
      group_clause* lClause = new group_clause(outer_var, inner_var);
      flwor->add_non_group(lClause);
      pop_scope();
    }
  }

  if (v.get_where () != NULL) {
    expr_t lClauseExpr = pop_nodestack();
    if (lClauseExpr->isUpdating())
      ZORBA_ERROR_LOC(XUST0001, loc);
    flwor->set_where (lClauseExpr);
  }
  FLWORClauseList *clauses = v.get_clause_list ().getp ();
  vector <forlet_clause *> eclauses;

  for (i = clauses->size () - 1; i >= 0; i--) {
    ForOrLetClause *clause = dynamic_cast<ForOrLetClause *> ((*clauses) [i].getp ());
    if (clause == NULL) continue;

    vector<rchandle <var_expr> > vars, pos_vars;
    vector<rchandle <expr> > exprs;
    int size = clause->get_decl_count ();

    if (clause->for_or_let () == ForOrLetClause::for_clause) {
      ForClause *forclause = static_cast<ForClause *> (clause);
      VarInDeclList *decl_list = &*forclause->get_vardecl_list ();

      for (j = size - 1; j >= 0; j--) {
        varref_t ve;
        ve = pop_nodestack_var ();
        ve->set_kind (var_expr::for_var);
        // for var
        vars.push_back (ve);
        // value expression
        expr_t lValueExpr = pop_nodestack();
        if (lValueExpr->isUpdating())
          ZORBA_ERROR_LOC(XUST0001, loc);
        exprs.push_back(lValueExpr);
        // pos var
        if ((*decl_list) [j]->get_posvar () == NULL)
          pos_vars.push_back (NULL);
        else {
          varref_t pve = pop_nodestack_var ();
          pve->set_kind (var_expr::pos_var);
          pos_vars.push_back (pve);
        }
        pop_scope ();
      }

      for (j = 0; j < size; j++) {
        forlet_clause *flc = new forlet_clause (forlet_clause::for_clause, vars [j], pos_vars [j], NULL, exprs [j]);
        eclauses.push_back (flc);
      }
    } else {  // let clause
      for (j = 0; j < size; j++) {
        varref_t ve = pop_nodestack_var ();
        expr_t lValueExpr = pop_nodestack();
        if (lValueExpr->isUpdating())
          ZORBA_ERROR_LOC(XUST0001, loc);
        exprs.push_back(lValueExpr);
        ve->set_kind (var_expr::let_var);
        vars.push_back (ve);
        pop_scope ();
      }

      for (j = 0; j < size; j++) {
        forlet_clause *flc = new forlet_clause (forlet_clause::let_clause, vars [j], NULL, NULL, exprs [j]);
        eclauses.push_back (flc);
      }
    }
  }

  for (i = eclauses.size () - 1; i >= 0; i--)
    flwor->add (rchandle<forlet_clause> (eclauses [i]));

  nodestack.push (&*flwor);
}


void *begin_visit (const WindowClause& v) {
  TRACE_VISIT ();
  push_scope ();  // for window conditions
  return no_state;
}

void end_visit (const WindowClause& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  push_scope ();
  rchandle<FLWORWinCond> cond;
  for (int i = 0; i < 2; i++)
    if (NULL != (cond = v [i])) {
      rchandle<WindowVars> vars = cond->get_winvars ();
      if (vars != NULL)
        bind_winvars (*vars, false);
    }
}

void *begin_visit (const WindowVarDecl& v) {
  TRACE_VISIT ();
  pop_scope ();  // done with window conditions
  return no_state;
}

void end_visit (const WindowVarDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  xqtref_t type = v.get_typedecl () == NULL ? NULL : pop_tstack ();
  push_scope ();
  bind_var_and_push (loc, v.get_varname (), var_expr::win_var, type);
}

void *begin_visit (const FLWORWinCond& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const FLWORWinCond& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const WindowVars& v) {
  TRACE_VISIT ();
  return no_state;
}

void bind_winvars (const WindowVars& v, bool in) {
  const QueryLoc &loc = v.get_location ();
  enum var_expr::var_kind item_var_kind =
    in ? var_expr::wincond_in_var : var_expr::wincond_var;
  rchandle<PositionalVar> pv = v.get_posvar ();
  if (pv != NULL)
    bind_var_and_push (pv->get_location (), pv->get_varname (),
                       in ? var_expr::wincond_in_pos_var : var_expr::wincond_pos_var);
  if (! v.get_curr ().empty ())
    bind_var_and_push (loc, v.get_curr (), item_var_kind);
  if (! v.get_prev ().empty ())
    bind_var_and_push (loc, v.get_prev (), item_var_kind);
  if (! v.get_next ().empty ())
    bind_var_and_push (loc, v.get_next (), item_var_kind);
}

void end_visit (const WindowVars& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  bind_winvars (v, true);
}

void *begin_visit (const FLWORClauseList& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const FLWORClauseList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const LetClause& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const LetClause& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const VarGetsDecl& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const VarGetsDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  push_scope ();
  xqtref_t type = v.get_typedecl () == NULL ? NULL : pop_tstack ();
  if (v.get_kind () == VarGetsDecl::let_var)
    bind_var_and_push (loc, v.get_varname (), var_expr::let_var, type);
  else
    nodestack.push (&*create_var (loc, v.get_varname (), var_expr::let_var, type));
#ifdef ZORBA_DEBUGGER
  theScopedVariables.push_back(nodestack.top().dyn_cast<var_expr>());
#endif
}


void *begin_visit (const ForClause& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ForClause& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const VarInDecl& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const VarInDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  push_scope ();
  const PositionalVar *pv = v.get_posvar ();
  xqp_string varname = v.get_varname ();
  store::Item_t var_qname = sctx_p->lookup_var_qname (varname, loc);
  if (pv != NULL) {
    expr_t val_expr = pop_nodestack ();
    xqp_string pvarname = pv->get_varname ();
    store::Item_t pvar_qname = sctx_p->lookup_var_qname (pvarname, loc);
    if (pvar_qname->equals (var_qname.getp ()))
      ZORBA_ERROR_LOC (XQST0089, loc);
    bind_var_and_push (pv->get_location (), pvar_qname, var_expr::pos_var);
#ifdef ZORBA_DEBUGGER
    theScopedVariables.push_back(nodestack.top().dyn_cast<var_expr>());
#endif
    nodestack.push (val_expr);
  }
  bind_var_and_push (loc, var_qname, var_expr::for_var, v.get_typedecl () == NULL ? NULL : pop_tstack ());
#ifdef ZORBA_DEBUGGER
  theScopedVariables.push_back(nodestack.top().dyn_cast<var_expr>());
#endif
}

void *begin_visit (const PositionalVar& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const PositionalVar& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const WhereClause& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const WhereClause& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const CountClause& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CountClause& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  bind_var_and_push (loc, v.get_varname (), var_expr::count_var, NULL);
}


void *begin_visit (const GroupByClause& v) {
  TRACE_VISIT ();

  nodestack.push(NULL);

  const FLWORExpr &flwor = *v.get_flwor ();
  const FLWORClauseList &clauses = *flwor.get_clause_list ();
  set<const var_expr *> all_vars;
  collect_flwor_vars (flwor, all_vars, &*clauses [0], &v, false);

  set<const var_expr *> group_vars;
  GroupSpecList* lList = v.get_spec_list();
  for (size_t i = 0; i < lList->size(); ++i) {
    GroupSpec* lSpec = (*lList)[i];
    string varname = lSpec->get_var_name();
    const var_expr *ve = lookup_var (varname);
    if (ve == NULL)
      ZORBA_ERROR_LOC_PARAM( XPST0008, loc, varname, "");
    group_vars.insert (ve);
  }

  set<const var_expr *> non_group_vars;
  set_difference (all_vars.begin (), all_vars.end (),
                  group_vars.begin (), group_vars.end (),
                  inserter (non_group_vars, non_group_vars.begin ()));

  // For each FOR/LET var_expr X that does not appear in the group-by clause,
  // create a new var_exp ngX and push ngX and X in the node stack
  for (set<const var_expr *>::iterator i = non_group_vars.begin ();
       i != non_group_vars.end (); i++)
  {
    nodestack.push (const_cast<var_expr *> (*i));
    push_scope ();
    bind_var_and_push (loc, (*i)->get_varname (), var_expr::non_groupby_var);
  }

  return no_state;
}

void end_visit (const GroupByClause& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const GroupSpecList& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const GroupSpecList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const GroupSpec& v) {
  TRACE_VISIT ();
  var_expr *e = lookup_var (v.get_var_name());
  if (e == NULL)
    ZORBA_ERROR_LOC_PARAM(XPST0008, loc, v.get_var_name(), "");
  push_scope();
  // Create a new var_expr gX, corresponding to the var X that is referenced
  // by this group spec. Then push gX and X to the node stack.
  nodestack.push(rchandle<expr>(e));
  bind_var_and_push(loc, v.get_var_name(), var_expr::groupby_var);
  return no_state;
}

void end_visit (const GroupSpec& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const GroupCollationSpec& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const GroupCollationSpec& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const LetClauseList& v) {
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const LetClauseList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const OrderByClause& v) {
  TRACE_VISIT ();
  const FLWORExpr &flwor = *v.get_flwor ();
  if (! flwor.is_general ()) return no_state;
  const OrderSpecList &ol = *v.get_spec_list ();

  const FLWORClauseList &clauses = *flwor.get_clause_list ();
  for (int i = ol.size () - 1; i >= 0; i--) {
    set<const var_expr *> vars;
    collect_flwor_vars (flwor, vars, &*clauses [0], &v, false);
    ol [i]->accept (*this);
    push_scope ();
    nodestack.push (NULL);
    for (set<const var_expr *>::iterator si = vars.begin (); si != vars.end (); ++si) {
      var_expr *inner = const_cast<var_expr *> (*si);
      var_expr *outer = bind_var (inner->get_loc (), inner->get_varname (), inner->get_kind (), inner->get_type ());
      nodestack.push (outer);
      nodestack.push (inner);
    }
  }
  return NULL;  // reject visitor!
}

void end_visit (const OrderByClause& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const OrderSpecList& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const OrderSpecList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const OrderSpec& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const OrderSpec& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const OrderModifier& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const OrderModifier& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const OrderCollationSpec& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const OrderCollationSpec& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const OrderDirSpec& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const OrderDirSpec& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const OrderEmptySpec& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const OrderEmptySpec& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


/*******************************************************************************

  VarDecl represents a variable declaration in the prolog.

********************************************************************************/

void *begin_visit (const VarDecl& v) {
  TRACE_VISIT ();
  string key = static_context::qname_internal_key (sctx_p->lookup_var_qname (v.get_varname (), loc));
  global_decl_stack.push ("V" + key);
  global_var_decls.push_front (key);
  return no_state;
}

void end_visit (const VarDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  pop_stack (global_decl_stack);
  xqp_string varname = v.get_varname();

  // The declared type of a global or external is never tightened based on
  // type inference because globals are mutable.
  xqtref_t type;
  if (v.get_typedecl () != NULL)
    type = pop_tstack ();

  varref_t ve = bind_var (loc, varname, var_expr::context_var, type);
  if (! mod_ns.empty () && xqp_string (ve->get_varname ()->getNamespace ()) != mod_ns)
    ZORBA_ERROR_LOC (XQST0048, loc);
  if (! v.is_extern ()) {
    bind_var (ve, minfo->globals.get ());
    if (export_sctx != NULL)
      bind_var (ve, export_sctx);
  }
  expr_t val = v.is_extern() ? expr_t(NULL) : pop_nodestack();
  theGlobalVars.push_back(global_binding(ve, val));
#ifdef ZORBA_DEBUGGER
  theScopedVariables.push_back( ve );
#endif
}


/*******************************************************************************

  Function declarations and invocations.

  VFO_DeclList represents a list of prolog declarations that consists of all
  the variable, udf, and option declaration in the prolog. 
 
********************************************************************************/

void *begin_visit (const VFO_DeclList& v) {
  TRACE_VISIT ();

  // Function declaration translation must be done in two passes because of
  // mutually recursive functions. So, here's the 1st pass. The second pass
  // happens when accept() is called on each individual FunctionDecl node in
  // the list.

  for (vector<rchandle<parsenode> >::const_iterator it = v.begin();
       it != v.end();
       ++it)
  {
    const FunctionDecl *n = it->dyn_cast<FunctionDecl> ().getp ();

    // skip variable and option declarations.
    if (n == NULL)
      continue;

    rchandle<ParamList> params = n->get_paramlist ();
    if (params == NULL)
      params = new ParamList (n->get_location ());

    int nargs = params->size();
    vector<xqtref_t> arg_types;
    for (vector<rchandle<Param> >::const_iterator it = params->begin ();
         it != params->end ();
         ++it)
    {
      const Param *p = (*it).getp ();
      const TypeDeclaration *td = p->get_typedecl ().getp ();
      if (td == NULL) {
        arg_types.push_back (GENV_TYPESYSTEM.ITEM_TYPE_STAR);
      } else {
        td->accept (*this);
        arg_types.push_back (pop_tstack ());
      }
    }

    xqtref_t return_type = GENV_TYPESYSTEM.ITEM_TYPE_STAR;
    if (n->get_return_type () != NULL)  {
      n->get_return_type ()->accept (*this);
      return_type = pop_tstack ();
    }

    store::Item_t qname = sctx_p->lookup_fn_qname(n->get_name()->get_prefix(),
                                                  n->get_name()->get_localname(),
                                                  n->get_location ());
    {
      xqp_string ns = qname->getNamespace ();
      if(ns.empty())
        ZORBA_ERROR_LOC (XQST0060, loc);//function must be declared in a non-NULL namespace
      if (ns == XQUERY_FN_NS || ns == XML_NS || ns == XML_SCHEMA_NS || ns == XSI_NS)
        ZORBA_ERROR_LOC_PARAM (XQST0045,
                               n->get_location (),
                               qname->getLocalName()->str(), "");
      // In a module, all exports must be inside to target ns
      if (! mod_ns.empty () && ns != mod_ns)
        ZORBA_ERROR_LOC (XQST0048, loc);
    }

    signature sig(qname, arg_types, return_type);

    rchandle<function> f;
    switch(n->get_type()) 
    {
    case ParseConstants::fn_extern_update:
    case ParseConstants::fn_extern: {
      StatelessExternalFunction *ef =
        sctx_p->lookup_stateless_external_function(n->get_name()->get_prefix(),
                                                   n->get_name()->get_localname());
      if (ef == NULL) {
          ZORBA_ERROR_LOC_PARAM(XQP0028_FUNCTION_IMPL_NOT_FOUND, n->get_location(), qname->getNamespace()->str(), qname->getLocalName()->str());
      }
      ZORBA_ASSERT(ef != NULL);
      f = new stateless_external_function_adapter(sig, ef, n->get_type () == ParseConstants::fn_extern_update);
      break;
    }
    case ParseConstants::fn_sequential:
    case ParseConstants::fn_update:
    case ParseConstants::fn_read: {
      f = new user_function(n->get_location(), sig, NULL, n->get_type () == ParseConstants::fn_update);
      break;
    }
    default:
      ZORBA_ASSERT(false);
    }
    bind_udf(qname, f, nargs, n->get_location());
  }

  return no_state;
}


void reorder_globals () {
  // STEP 1: Floyd-Warshall transitive closure of edges starting from functions
  for (list<string>::iterator k = global_fn_decls.begin ();
       k != global_fn_decls.end (); k++)
  {
    string kkey = "F" + *k;
    strset_t kedges;    
    if (! global_deps.get (kkey, kedges))
      continue;

    for (set<string>::iterator j = kedges->begin (); j != kedges->end (); j++) {
      string jkey = *j;
      for (list<string>::iterator i = global_fn_decls.begin ();
           i != global_fn_decls.end (); i++)
      {
        string ikey = "F" + *i;
        strset_t iedges, new_iedges;
        if (global_deps.get (ikey, iedges)
            && iedges->find (kkey) != iedges->end ()
            && iedges->find (jkey) == iedges->end ()) {
          // cout << "Added " << ikey << " -> " << kkey << " -> " << jkey << endl;
          iedges->insert (jkey);
        }
      }
    }
  }

  // STEP 2: add var -> fn -> var dependencies found above
  for (list<string>::iterator i = global_var_decls.begin ();
       i != global_var_decls.end (); i++)
  {
    string ikey = "V" + *i;
    strset_t iedges;
    if (! global_deps.get (ikey, iedges))
      continue;
    set<string> new_iedges;
    for (set<string>::iterator k = iedges->begin (); k != iedges->end (); k++) {
      string kkey = *k;
      strset_t kedges;
      if (kkey [0] == 'F' && global_deps.get (kkey, kedges))
        new_iedges.insert (kedges->begin (), kedges->end ());
    }
    // after iteration on iedges is finished, enlarge it
    #if 0
    cout << "Adding to " << ikey << " ";
    copy (new_iedges.begin (), new_iedges.end (),
          ostream_iterator<string> (cout, " "));
    cout << endl;
    #endif
    iedges->insert (new_iedges.begin (), new_iedges.end ());
  }

  // STEP 3: topologically sort global vars.
  // Note that steps 1 & 2 are required: we cannot sort the entire set of
  // global vars + fns, because functions are allowed to be mutually recursive.
  // Implemented using non-recursive (stack-based) DFS traversal.
  // This algorithm unfortunately does not detect cycles.
  list<string> topsorted_vars;  // dependencies first
  set<string> visited;
  stack<string> todo;  // format: action_char + var_key
  for (list<string>::iterator i = global_var_decls.begin ();
       i != global_var_decls.end (); i++)
    todo.push ("I" + (*i));
  
  while (! todo.empty ()) {
    string ikey = todo.top ();
    // cout << "Action " << ikey << endl;
    char action = ikey [0];
    ikey.replace (0, 1, "");
    todo.pop ();

    switch (action) {
    case 'D':  // finish notification
      topsorted_vars.push_back (ikey);
      break;
    case 'I':  // visit request
      if (visited.find (ikey) == visited.end ()) {
        visited.insert (ikey);
        todo.push ("D" + ikey);
        strset_t iedges;
        if (global_deps.get ("V" + ikey, iedges)) {
          for (set<string>::iterator j = iedges->begin ();
               j != iedges->end (); j++)
          {
            if ((*j) [0] == 'V')
              todo.push ("I" + (*j).substr (1));
          }
        }
      }
      break;
    default: assert (false);
    }
  }

  // STEP 4: reorder theGlobalVars according to topological order
  #if 1
  map<string, global_binding> gvmap;
  for (list<global_binding>::iterator i = theGlobalVars.begin ();
       i != theGlobalVars.end (); i++)
  {
    store::Item_t qname = (*i).first->get_varname ();
    gvmap [static_context::qname_internal_key (qname)] = *i;
  }
  theGlobalVars.clear ();
  for (list<string>::iterator i = topsorted_vars.begin ();
       i != topsorted_vars.end (); i++) {
    map<string, global_binding>::iterator p = gvmap.find (*i);
    if (p != gvmap.end ())
      theGlobalVars.push_back ((*p).second);
  }
  #endif
}

void end_visit (const VFO_DeclList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  if (Properties::instance ()->reorderGlobals ())
    reorder_globals ();
  // else cout << "Warning: global var reordering disabled\n";
}


void *begin_visit (const FunctionDecl& v) {
  TRACE_VISIT ();
  push_scope ();
  store::Item_t qname = sctx_p->lookup_fn_qname(v.get_name()->get_prefix(),
                                                v.get_name()->get_localname(),
                                                v.get_location ());
  string key = sctx_p->qname_internal_key (qname);
  global_decl_stack.push ("F" + key);
  global_fn_decls.push_front (key);
  return no_state;
}


void end_visit (const FunctionDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  pop_stack (global_decl_stack);
  ParseConstants::function_type_t lFuncType = v.get_type();
  expr_t body;
  bool is_external = 
    lFuncType == ParseConstants::fn_extern
    || lFuncType == ParseConstants::fn_extern_update
    || lFuncType == ParseConstants::fn_extern_sequential;
  if (! is_external)
    body = pop_nodestack ();
  if (v.get_return_type () != NULL)
    pop_tstack ();

  // The following code must execute regardless of the function type
  // to clean up the node and type stacks.
  int nargs = v.get_param_count ();
  vector<varref_t> args;
  if (nargs > 0) {
    rchandle<flwor_expr> flwor = pop_nodestack().dyn_cast<flwor_expr> ();
    ZORBA_ASSERT(flwor != NULL);

    for(int i = 0; i < nargs; ++i) {
      rchandle<forlet_clause>& flc = (*flwor)[i];
      var_expr* arg_var = flc->get_expr().dyn_cast<var_expr> ().getp();
      ZORBA_ASSERT(arg_var != NULL);
      args.push_back(arg_var);
    }
    if (body != NULL) {
      flwor->set_retval(body);
      flwor->setUpdateType(body->getUpdateType());
    }
    body = &*flwor;
  }

  switch(lFuncType)
  {
  case ParseConstants::fn_update:
  {
    if (v.get_return_type() != 0)
      ZORBA_ERROR_LOC(XUST0028, loc);

    // Fall through the fn_read case.
  }
  case ParseConstants::fn_sequential:
  case ParseConstants::fn_read:
  {
    if (lFuncType == ParseConstants::fn_read) {
      if (body->isUpdating())
        ZORBA_ERROR_LOC(XUST0001, loc);
    }
    else if (lFuncType == ParseConstants::fn_update) {
      if (body->getUpdateType() == SIMPLE_EXPR)
        ZORBA_ERROR_LOC(XUST0002, loc);
    }

    assert(body != NULL);

    user_function *udf = dynamic_cast<user_function *>(
                         LOOKUP_FN(v.get_name ()->get_prefix (),
                                   v.get_name ()->get_localname (),
                                   nargs));
    ZORBA_ASSERT (udf != NULL);
    
    if (compilerCB->m_config.translate_cb != NULL)
      compilerCB->m_config.translate_cb (&*body, v.get_name ()->get_qname ());

    normalize_expr_tree(v.get_name ()->get_qname().c_str(), compilerCB, body, *&(udf->get_signature().return_type()));

    if (compilerCB->m_config.opt_level == CompilerCB::config_t::O1) {
      RewriterContext rCtx(compilerCB, body);
      GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rCtx);
      body = rCtx.getRoot();
      if (compilerCB->m_config.optimize_cb != NULL)
        compilerCB->m_config.optimize_cb (&*body, v.get_name ()->get_qname ());
    }

    udf->set_body(body);
    udf->set_params(args);
    break;
  }
  case ParseConstants::fn_extern_update:
  {
    if (v.get_return_type() != 0)
      ZORBA_ERROR_LOC(XUST0028, loc);
  }
  default:
    break;
  }
  pop_scope ();
}


void *begin_visit (const ParamList& v) {
  TRACE_VISIT ();
  if (v.size() > 0) {
    nodestack.push(new flwor_expr(loc));
  }
  return no_state;
}


void end_visit (const ParamList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const Param& v) {
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const Param& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  rchandle<flwor_expr> flwor = nodestack.top().cast<flwor_expr> ();
  ZORBA_ASSERT(flwor != NULL);

  store::Item_t qname = sctx_p->lookup_qname ("", v.get_name(), loc);

  varref_t param_var = create_var (loc, qname, var_expr::param_var);
  varref_t subst_var = bind_var (loc, qname, var_expr::let_var);

#ifdef ZORBA_DEBUGGER
  if(compilerCB->m_debugger != 0)
  {
    theScopedVariables.push_back(subst_var);
  }
#endif

  flwor->add(wrap_in_letclause(&*param_var, subst_var));

  if (v.get_typedecl () != NULL)  {
    param_var->set_type (pop_tstack ());
    subst_var->set_type(param_var->get_type());
  }
}


void *begin_visit (const FunctionCall& v) {
  TRACE_VISIT ();
  rchandle<QName> qn_h = v.get_fname();
  string prefix = qn_h->get_prefix();
  string fname = qn_h->get_localname();
  store::Item_t qname = sctx_p->lookup_fn_qname(prefix, fname, loc);
  string key = "F" + static_context::qname_internal_key (qname);
  if (! global_decl_stack.empty ())
    add_multimap_value (global_deps, global_decl_stack.top (), key);
  nodestack.push(NULL);
  return no_state;
}

void end_visit (const FunctionCall& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  vector<expr_t> arguments;
  while (true) 
  {
    expr_t e_h = pop_nodestack();
    if (e_h == NULL)
      break;
    arguments.push_back(e_h);
  }
  int sz = arguments.size ();

  rchandle<QName> qn_h = v.get_fname();
  string prefix = qn_h->get_prefix();
  string fname = qn_h->get_localname();

  const xqpStringStore *fn_ns = sctx_p->lookup_fn_qname(prefix, fname, loc)->getNamespace ();

  if (fn_ns->byteEqual(XQUERY_FN_NS)) {
    if (fname == "position" && sz == 0)  {
      nodestack.push (lookup_ctx_var(DOT_POS_VARNAME, loc).getp());
      return;
    } else if (fname == "last" && sz == 0) {
      nodestack.push(lookup_ctx_var(LAST_IDX_VARNAME, loc).getp());
      return;
    } else if (fname == "number") {
      switch (sz) 
      {
      case 0:
        arguments.push_back (DOT_VAR);
        break;
      case 1:
        break;
      default:
        ZORBA_ERROR_LOC_PARAM( XPST0017, loc, "fn:number", sz );
      }

      varref_t tv = tempvar (loc, var_expr::let_var);

      expr_t nan_expr = new const_expr (loc, xqp_double::nan ());

      expr_t ret = new if_expr (loc,
                                new castable_expr (loc,
                                                   &*tv,
                                                   GENV_TYPESYSTEM.DOUBLE_TYPE_ONE),
                                new cast_expr (loc,
                                               &*tv,
                                               GENV_TYPESYSTEM.DOUBLE_TYPE_ONE),
                                nan_expr);

      expr_t data_expr = wrap_in_atomization (arguments [0]);

      nodestack.push(&*wrap_in_let_flwor(new treat_expr(loc,
                                                        data_expr,
                                                        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
                                                        XPTY0004),
                                         tv,
                                         ret));
      return;
    }
    else if (sz == 0 && xquery_fns_def_dot.find (fname) != xquery_fns_def_dot.end ()) {
      arguments.push_back (DOT_VAR);
    } else if (fname == "static-base-uri") {
      if (sz != 0)
        ZORBA_ERROR_LOC_PARAM( XPST0017, loc, "fn:static-base-uri", sz );

      xqp_string baseuri = sctx_p->final_baseuri ();
      if (baseuri.empty ())
        nodestack.push (create_seq (loc));
      else
        nodestack.push (new cast_expr (loc,
                                       new const_expr (loc, baseuri),
                                       GENV_TYPESYSTEM.ANY_URI_TYPE_ONE));
      return;
    }
    else if (sz == 1 &&
             (fname == "lang" || fname == "id" || fname == "idref")) 
    {
      arguments.insert (arguments.begin (), DOT_VAR);
    } else if (sz == 1 && fname == "resolve-uri") {
#if 0  // even if the base-uri is not declared in the prolog, we have a default
      if (! hadBUriDecl)
        ZORBA_ERROR (FONS0005);
      else
#endif
        arguments.insert (arguments.begin (), new const_expr (loc, sctx_p->final_baseuri()));
    } else if (sz == 1 && fname == "parse") {
      arguments.insert (arguments.begin (), new const_expr (loc, sctx_p->final_baseuri()));
    } else if (fname == "concat") {
      if (sz < 2)
        ZORBA_ERROR_LOC_PARAM (XPST0017, loc, "concat", to_string (sz));
    }
  } else if (fn_ns->byteEqual(ZORBA_FN_NS)) {
    if (fname == "inline-xml" && sz == 1) {
      nodestack.push (new eval_expr(loc, create_cast_expr (loc, arguments [0], GENV_TYPESYSTEM.STRING_TYPE_ONE, true)));
      return;
    }
  }

  sz = arguments.size ();  // recompute size

  // try constructor functions
  xqtref_t type = CTXTS->create_named_type(sctx_p->lookup_elem_qname (prefix, fname, loc), TypeConstants::QUANT_QUESTION);

  if (type != NULL) {
    if (sz != 1
        || TypeOps::is_equal (*type, *GENV_TYPESYSTEM.NOTATION_TYPE_QUESTION)
        || TypeOps::is_equal (*type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION))
      ZORBA_ERROR_LOC_PARAM( XPST0017,  loc, prefix + ":" + fname, sz);
    nodestack.push (create_cast_expr (loc, arguments [0], type, true));
  } else {
      function *f = LOOKUP_FN (prefix, fname, sz);
      if (f == NULL)
        ZORBA_ERROR_LOC_PARAM (XPST0017, loc, (prefix.empty () ? prefix : (prefix + ":")) + fname, to_string (sz));
      rchandle<fo_expr> fo_h = new fo_expr (loc, f);
      fo_h->setUpdateType(fo_h->get_func()->getUpdateType());

      // TODO this should be a const iterator
      vector<expr_t>::reverse_iterator iter = arguments.rbegin();
      for(; iter != arguments.rend(); ++iter)
        fo_h->add(*iter);
#ifdef ZORBA_DEBUGGER
      if ( compilerCB->m_debugger != 0 ) {
        rchandle<debugger_expr> lDebuggerExpr = new debugger_expr(loc, &*fo_h, theScopedVariables, theGlobalVars);
        nodestack.push(&*lDebuggerExpr);
      } else {
        nodestack.push(&*fo_h);
      }
#else
      nodestack.push(&*fo_h);
#endif
  }
}


/*******************************************************************************


********************************************************************************/

void *begin_visit (const GeneralComp& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const GeneralComp& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const LibraryModule& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const LibraryModule& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  parse_xquery_version (v.get_version_decl ());
  nodestack.push (wrap_in_globalvar_assign (create_seq (loc)));
}


void *begin_visit (const MainModule & v) {
  TRACE_VISIT ();

  theDotVar = bind_var(QueryLoc::null, DOT_VARNAME, var_expr::context_var, GENV_TYPESYSTEM.ITEM_TYPE_ONE);
  
  parse_xquery_version (v.get_version_decl ());
  return no_state;
}

void end_visit (const MainModule & v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const Module& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const Module& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const ModuleDecl& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ModuleDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  mod_pfx = v.get_prefix ();
  mod_ns = v.get_target_namespace ();
  if (mod_ns.empty ())
    ZORBA_ERROR_LOC (XQST0088, loc);
  if (mod_pfx == "xml" || mod_pfx == "xmlns")
    ZORBA_ERROR_LOC (XQST0070, loc);
  sctx_p->bind_ns (mod_pfx, mod_ns);
  bool found = minfo->mod_sctx_map.get (sctx_p->entity_retrieval_url (), export_sctx);
  ZORBA_ASSERT (found);
}


void *begin_visit (const ModuleImport& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ModuleImport& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  string pfx = v.get_prefix (), target_ns = v.get_uri ();
#ifdef ZORBA_DEBUGGER
  if(compilerCB->m_debugger != 0)
  {
    compilerCB->m_debugger->theImports.insert(make_pair<string, string>(target_ns, pfx)); 
  }
#endif

  // The namespace prefix specified in a module import must not be xml or xmlns [err:XQST0070]
  if (pfx == "xml" || pfx == "xmlns")
    ZORBA_ERROR_LOC (XQST0070, loc);

  // The first URILiteral in a module import must be of nonzero length [err:XQST0088]
  if (target_ns.empty ())
    ZORBA_ERROR_LOC (XQST0088, loc);

  // It is a static error [err:XQST0047] if more than one module import in a Prolog specifies the same target namespace
  if (! mod_import_ns_set.insert (target_ns).second)
    ZORBA_ERROR_LOC (XQST0047, loc);

  // The namespace prefix specified in a module import must not be the same as any namespace prefix bound 
  // in the same module by another module import, 
  // a schema import, a namespace declaration, or a module declaration with a different target namespace [err:XQST0033].
  if (! (pfx.empty () || (pfx == mod_pfx && target_ns == mod_ns))) {
    try {
      sctx_p->bind_ns(pfx, target_ns, XQST0033);
    } catch (error::ZorbaError& e) {
      // rethrow with current location
      ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
    }
  }

  rchandle<URILiteralList> ats = v.get_uri_list ();
  // Handle pre-defined modules
  if (ats == NULL && zorba_predef_mod_ns.find (target_ns) != zorba_predef_mod_ns.end ())
    return;

  vector<xqpStringStore_t> lURIs;
  if (ats == NULL || ats->size () == 0) {
    lURIs.push_back(xqp_string(target_ns).getStore());
  } else {
    for (int i = 0; i < ats->size(); ++i) {
      lURIs.push_back(sctx_p->resolve_relative_uri((*ats)[i], xqp_string()).getStore());
    }
  }

  InternalModuleURIResolver* lModuleResolver = sctx_p->get_module_uri_resolver();

  for (vector<xqpStringStore_t>::iterator lIter = lURIs.begin();
       lIter != lURIs.end(); ++lIter) {
    xqpStringStore_t resolveduri = *lIter; 
    store::Item_t    aturiitem = NULL;
    if (!GENV_ITEMFACTORY->createAnyURI(aturiitem, resolveduri))
      ZORBA_ERROR_LOC_DESC_OSS(XQST0046, loc, "URI is not valid " << resolveduri);

    set<string> mod_stk1 = mod_stack;
    if (! mod_stk1.insert (xqpString(resolveduri.getp())).second)
      ZORBA_ERROR_LOC (XQST0073, loc);
    
    string imported_ns;
    static_context *imported_sctx = NULL;
    if (minfo->mod_ns_map.get (xqpString(resolveduri.getp()), imported_ns)) {
      bool found = minfo->mod_sctx_map.get (xqpString(resolveduri.getp()), imported_sctx);
      ZORBA_ASSERT (found);
    } else {
      // we get the ownership if the moduleResolver is a standard resolver
      auto_ptr<istream> modfile (lModuleResolver->resolve(aturiitem, sctx_p));

      try {
        if (modfile.get () == NULL || ! *modfile) {
          ZORBA_ERROR_LOC_PARAM (XQST0059, loc, resolveduri, target_ns);
        }

        CompilerCB mod_ccb (*compilerCB);
        static_context *independent_sctx = static_cast<static_context *> (minfo->topCompilerCB->m_sctx->get_parent ());
        minfo->topCompilerCB->m_sctx_list.push_back (mod_ccb.m_sctx = independent_sctx->create_child_context ());
        mod_ccb.m_sctx->set_entity_retrieval_url (xqpString(resolveduri.getp()));
        minfo->topCompilerCB->m_sctx_list.push_back (imported_sctx = independent_sctx->create_child_context ());
        minfo->mod_sctx_map.put (xqpString(resolveduri.getp()), imported_sctx);
        XQueryCompiler xqc (&mod_ccb);
        xqpString lFileName(aturiitem->getStringValue());
        rchandle<parsenode> ast = xqc.parse (*modfile, lFileName);
#ifdef ZORBA_DEBUGGER
        if(compilerCB->m_debugger != 0)
        {
          compilerCB->m_debugger->addModule(ast);
        }
#endif
        LibraryModule *mod_ast = dynamic_cast<LibraryModule *> (&*ast);
        if (mod_ast == NULL)
          ZORBA_ERROR_LOC_PARAM (XQST0059, loc, resolveduri, target_ns);
        imported_ns = mod_ast->get_decl ()->get_target_namespace ();
        translate_aux (*ast, &mod_ccb, minfo, mod_stk1);
        minfo->mod_ns_map.put (xqpString(resolveduri.getp()), imported_ns);
      } catch (...) {
        throw;
      }
    }

    if (imported_ns != target_ns)
      ZORBA_ERROR_LOC_PARAM (XQST0059, loc, resolveduri, target_ns);
    // We catch duplicate functions / vars in minfo->globals.
    // We can safely ignore the return value. We might even be able
    // to assert() here (not sure though).
    sctx_p->import_module (imported_sctx);
  }
}


void *begin_visit (const NamespaceDecl& v) {
  TRACE_VISIT ();
  xqp_string pre = v.get_prefix (), uri = v.get_uri ();
  if (pre == "xml" || pre == "xmlns" || uri == XML_NS)
    ZORBA_ERROR_LOC (XQST0070, loc);
  sctx_p->bind_ns (pre, uri);
  return NULL;
}

void end_visit (const NamespaceDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const NodeComp& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const NodeComp& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const OptionDecl& v) {
  TRACE_VISIT ();
  //check if namespace for option is valid
  rchandle<QName>   qn = v.get_qname();
  xqpString   option_ns = sctx_p->lookup_ns(qn->get_prefix(), loc);
  return no_state;
}

void end_visit (const OptionDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const OrderingModeDecl& v) {
  TRACE_VISIT ();
  CHK_SINGLE_DECL (hadOrdModeDecl, XQST0065);
  sctx_p->set_ordering_mode(v.get_mode());
  return NULL;
}


void end_visit (const OrderingModeDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const Pragma& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const Pragma& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
 // may raise XPST0081
 sctx_p->lookup_ns (v.get_name ()->get_prefix (), loc);
}

void *begin_visit (const PragmaList& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const PragmaList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const Prolog& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const Prolog& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const QVarInDecl& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const QVarInDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  push_scope ();
  xqtref_t type;
  if (v.get_typedecl () != NULL)
    type = pop_tstack ();
  bind_var_and_push (loc, v.get_name (), var_expr::for_var, type);
}


void *begin_visit (const QVarInDeclList& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const QVarInDeclList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const SIND_DeclList& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const SIND_DeclList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const SchemaImport& v) {
  TRACE_VISIT ();
#ifndef ZORBA_NO_XMLSCHEMA
    SchemaPrefix *sp = &*v.get_prefix();
    string target_ns = v.get_uri ();
    if (! schema_import_ns_set.insert (target_ns).second)
      ZORBA_ERROR_LOC (XQST0058, loc);
    if (sp != NULL) {
      string pfx = sp->get_prefix ();
      if (pfx == "xml" || pfx == "xmlns")
        ZORBA_ERROR_LOC (XQST0070, loc);
      if (sp->get_default_bit ()) {
        sctx_p->set_default_elem_type_ns (target_ns);
      }
      if (! pfx.empty ())
        sctx_p->bind_ns (pfx, target_ns, XQST0033);
    }

    rchandle<URILiteralList> atlist = v.get_at_list();
//  if (atlist == NULL || atlist->size () == 0)
//    ZORBA_ERROR_LOC_PARAM (XQST0057, loc, "(no location specified)", target_ns);

    std::vector<store::Item_t> lAtURIList;
    store::Item_t lTargetNamespace = NULL;
    ITEM_FACTORY->createAnyURI(lTargetNamespace, target_ns.c_str());
    ZORBA_ASSERT(lTargetNamespace != NULL);

    if (atlist != NULL) {
      for (int i = 0; i < atlist->size(); ++i) {
        string at = sctx_p->resolve_relative_uri((*atlist)[0], xqpString());
        store::Item_t lAtURIItem = NULL;
        ITEM_FACTORY->createAnyURI(lAtURIItem, at.c_str());
        ZORBA_ASSERT(lAtURIItem != NULL);
        lAtURIList.push_back(lAtURIItem);
#if 0
      string prefix = sp == NULL ? "" : sp->get_prefix();
      cout << "SchemaImport: " << prefix << " : " << target_ns
           << " @ " << at << endl;
      cout << " Context: " << CTXTS << "\n";
#endif
      }
    }

    InternalSchemaURIResolver* lSchemaResolver = sctx_p->get_schema_uri_resolver();

    try {
      store::Item_t lSchemaUri = lSchemaResolver->resolve(lTargetNamespace, lAtURIList, sctx_p);
      
      ((DelegatingTypeManager*)CTXTS)->initializeSchema();
      Schema* schema_p = ((DelegatingTypeManager*)CTXTS)->getSchema();
      
      schema_p->registerXSD (lSchemaUri->getStringValue()->c_str (), loc);
    } catch (error::ZorbaError& e) {
      ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
    }

    return no_state;
#else
    ZORBA_ERROR_LOC (XQST0009, loc);
    return no_state;
#endif
}

void end_visit (const SchemaImport& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const SchemaPrefix& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const SchemaPrefix& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const SignList& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const SignList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const SingleType& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const SingleType& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  if (v.get_hook_bit ())
    tstack.push (CTXTS->create_type (*pop_tstack (), TypeConstants::QUANT_QUESTION));
  // else leave type as it is on tstack
}


void *begin_visit (const TypeDeclaration& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const TypeDeclaration& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const TypeName& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const TypeName& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const URILiteralList& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const URILiteralList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const ValueComp& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ValueComp& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const VersionDecl& v) {
  TRACE_VISIT ();
  if (v.get_version () != "1.0")
    ZORBA_ERROR_LOC (XQST0031, loc);
  if (! xqp_string (v.get_encoding ()).matches ("^[A-Za-z]([A-Za-z0-9._]|[-])*$", ""))
    ZORBA_ERROR_LOC (XQST0087, loc);
  return no_state;
}

void end_visit (const VersionDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}



void *begin_visit (const AdditiveExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const AdditiveExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  rchandle<expr> e1_h = pop_nodestack();
  rchandle<expr> e2_h = pop_nodestack();
  function *func = NULL;
  switch (v.get_add_op()) {
  case ParseConstants::op_plus:
    func = LOOKUP_OP2 ("add");
    break;
  case ParseConstants::op_minus:
    func = LOOKUP_OP2 ("subtract");
    break;
  }
  fo_expr *fo_h = new fo_expr(loc, func);
  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push (fo_h);
}


void *begin_visit (const AndExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const AndExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  rchandle<expr> e1_h = pop_nodestack();
  rchandle<expr> e2_h = pop_nodestack();
  fo_expr *fo_h = new fo_expr(loc, LOOKUP_OPN ("and"));
  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push (fo_h);
}


/// Creates a cast_expr or castable_expr.
expr_t create_cast_expr (const QueryLoc& loc, expr_t node, xqtref_t type, bool isCast) {
  if (TypeOps::is_equal (*type, *GENV_TYPESYSTEM.NOTATION_TYPE_ONE)
      || TypeOps::is_equal (*type, *GENV_TYPESYSTEM.NOTATION_TYPE_QUESTION)
      || TypeOps::is_equal (*type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE)
      || TypeOps::is_equal (*type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION))
    ZORBA_ERROR_LOC (XPST0080, loc);
  if (! TypeOps::is_equal (*type, *GENV_TYPESYSTEM.QNAME_TYPE_ONE)
      && ! TypeOps::is_equal (*type, *GENV_TYPESYSTEM.QNAME_TYPE_QUESTION)) {
    if (isCast)
      return new cast_expr (loc, node, type);
    else
      return new castable_expr (loc, node, type);
  } else {  // a QName cast
    const const_expr *ce = node.dyn_cast<const_expr> ().getp();
    if (ce != NULL
        && TypeOps::is_equal (*CTXTS->create_value_type (ce->get_val ()),
                              *GENV_TYPESYSTEM.STRING_TYPE_ONE))
    {
      store::Item_t castLiteral;
      try 
      {
        xqpStringStore_t strval = ce->get_val()->getStringValue();
        GenericCast::instance()->castToQName(castLiteral, strval, ns_ctx);
      }
      catch (error::ZorbaError& e)
      {
        if (isCast) {
          throw e;
        } else {
          if (e.theErrorCode == FORG0001)
            ZORBA_ERROR_LOC(XPST0003, loc);
          else
            ZORBA_ERROR_LOC(XPST0081, loc);
        }
      }
      assert (castLiteral != NULL || ! isCast);
      if (isCast)
        return new const_expr (loc, castLiteral);
      else
        return new const_expr (loc, castLiteral != NULL);
    } else {
      if (isCast)
        return new treat_expr (loc, node, type, XPTY0004);
      else
        return new instanceof_expr (loc, node, type);
    }
  }
}


void *begin_visit (const CastExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CastExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  nodestack.push (create_cast_expr (loc, pop_nodestack (), pop_tstack (), true));
}

void *begin_visit (const CastableExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CastableExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  nodestack.push (create_cast_expr (loc, pop_nodestack (), pop_tstack (), false));
}


void *begin_visit (const ComparisonExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ComparisonExpr& v, void* /*visit_state*/) {
#define M( pc, op ) case ParseConstants::pc: f = LOOKUP_OP2 (op); break;

  TRACE_VISIT_OUT ();

  function *f = NULL;
  if (v.get_gencomp()!=NULL) {
    switch (v.get_gencomp()->get_type()) {
    M (op_eq, "equal");
    M (op_ne, "not-equal");
    M (op_lt, "less");
    M (op_le, "less-equal");
    M (op_gt, "greater");
    M (op_ge, "greater-equal");
    }
  } else if (v.get_valcomp () != NULL) {
    switch (v.get_valcomp()->get_type()) {
    M (op_val_eq, "value-equal");
    M (op_val_ne, "value-not-equal");
    M (op_val_lt, "value-less");
    M (op_val_le, "value-less-equal");
    M (op_val_gt, "value-greater");
    M (op_val_ge, "value-greater-equal");
    }
  } else if (v.get_nodecomp()!=NULL) {
    switch (v.get_nodecomp()->get_type()) {
    M (op_is, "is-same-node");
    M (op_precedes, "node-before");
    M (op_follows, "node-after");
    }
  }

  fo_expr *fo_p = new fo_expr(loc, f);

  rchandle<expr> e1_h = pop_nodestack();
  rchandle<expr> e2_h = pop_nodestack();;
  fo_p->add(e2_h);
  fo_p->add(e1_h);
  nodestack.push(fo_p);

#undef M
}



void *begin_visit (const ContextItemExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ContextItemExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  var_expr *e = static_cast<var_expr *> (DOT_VAR);
  e->set_loc(loc);
  nodestack.push(e);
}


void *begin_visit (const Expr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const Expr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  if (v.numberOfChildren () > 1) {
    expr_update_t lUpdateType = VACUOUS_EXPR;
    std::auto_ptr<fo_expr> elist_h(create_seq (loc));
    for (int i = 0; i < v.numberOfChildren (); i++) {
      expr_t e_h = pop_nodestack();
      lUpdateType = update_type_check_for_if(
                      e_h->getUpdateType(), 
                      lUpdateType, 
                      loc);
      elist_h->add(e_h);
    }
    elist_h->setUpdateType(lUpdateType);
    nodestack.push(elist_h.release());
  }
}

// void *begin_visit(const ExprSingle& v)
// {
// TRACE_VISIT ();
//  return no_state;
// }

void *begin_visit (const ExtensionExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ExtensionExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  if (v.get_expr () == NULL)
    ZORBA_ERROR_LOC( XQST0079, loc);
}


void *begin_visit (const IfExpr& v) {
  TRACE_VISIT ();
  // nothing to do here
  return no_state;
}

void end_visit (const IfExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  expr_t e_h = pop_nodestack ();
  expr_t t_h = pop_nodestack ();
  expr_t c_h = pop_nodestack ();

  if (c_h->isUpdating()) {
    ZORBA_ERROR_LOC(XUST0001, loc);
  }

  expr_update_t lUpdateType = update_type_check_for_if(
    t_h->getUpdateType(), 
    e_h->getUpdateType(),
    loc);

#ifdef ZORBA_DEBUGGER
  if (compilerCB->m_debugger != 0) {
    c_h = new debugger_expr(c_h->get_loc(), c_h, theScopedVariables, theGlobalVars);
    t_h = new debugger_expr(t_h->get_loc(), t_h, theScopedVariables, theGlobalVars);
    e_h = new debugger_expr(e_h->get_loc(), e_h, theScopedVariables, theGlobalVars);
  }
#endif
  if_expr *lIfExpr = new if_expr(loc,c_h,t_h,e_h);
  lIfExpr->setUpdateType(lUpdateType);
  nodestack.push(lIfExpr);
}


void *begin_visit (const InstanceofExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const InstanceofExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  nodestack.push(new instanceof_expr(loc, pop_nodestack(), pop_tstack()));
}


void *begin_visit (const IntersectExceptExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const IntersectExceptExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  rchandle<expr> e1_h = pop_nodestack ();
  rchandle<expr> e2_h = pop_nodestack ();
  function *f = NULL;
  switch (v.get_intex_op()) {
  case ParseConstants::op_intersect:
    f = LOOKUP_OP2 ("intersect");
    break;
  case ParseConstants::op_except:
    f = LOOKUP_OP2 ("except");
    break;
  }

  fo_expr *fo_h = new fo_expr(loc, f);

  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push(new fo_expr (loc, LOOKUP_OP1 ("sort-distinct-nodes-ascending"), fo_h));
}

void *begin_visit (const MultiplicativeExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const MultiplicativeExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  rchandle<expr> e1_h = pop_nodestack ();
  rchandle<expr> e2_h = pop_nodestack ();
  function *f = NULL;
  switch (v.get_mult_op()) {
  case ParseConstants::op_mul:
    f = LOOKUP_OP2 ("multiply");
    break;
  case ParseConstants::op_div:
    f = LOOKUP_OP2 ("divide");
    break;
  case ParseConstants::op_idiv:
    f = LOOKUP_OP2 ("integer-divide");
    break;
  case ParseConstants::op_mod:
    f = LOOKUP_OP2 ("mod");
    break;
  }
  fo_expr *fo_h = new fo_expr(loc, f);
  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push (fo_h);
}

void *begin_visit (const NumericLiteral& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const NumericLiteral& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  switch (v.get_type()) {
  case ParseConstants::num_integer: {
    nodestack.push(new const_expr(loc, v.get<xqp_integer>()));
    break;
  }
  case ParseConstants::num_decimal: {
    nodestack.push(new const_expr(loc, v.get<xqp_decimal>()));
    break;
  }
  case ParseConstants::num_double: {
    nodestack.push(new const_expr(loc, v.get<xqp_double>()));
    break;
  }
  }
}

void *begin_visit (const OrExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const OrExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  rchandle<expr> e1_h = pop_nodestack();
  rchandle<expr> e2_h = pop_nodestack();
  fo_expr *fo_p = new fo_expr(loc, CACHED (op_or, LOOKUP_OPN ("or")));
  fo_p->add(e2_h);
  fo_p->add(e1_h);
  nodestack.push (fo_p);
}

void *begin_visit (const OrderedExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const OrderedExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  nodestack.push (new order_expr (loc, order_expr::ordered,
                                  pop_nodestack ()));
}


void *begin_visit (const ParenthesizedExpr& v) {
  TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit (const ParenthesizedExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  expr_t expr = pop_nodestack();
  if (expr != NULL) {
    pop_nodestack();
    nodestack.push(expr);
  } else {
    fo_expr* lSeq = create_seq (loc);
    lSeq->setUpdateType(VACUOUS_EXPR);
    nodestack.push(lSeq);
  }
}


/*******************************************************************************

  Sequence Type Matching

  A SequenceType parsenode has 2 children: The right child is always an
  OccurrenceIndicator node. The left child may be either an AtomicType node,
  or one of the 9 kind-test nodes (elementTest, documentTest, ... etc), or
  an ItemType node. ItemType respesents the expression item().

********************************************************************************/

void *begin_visit (const SequenceType& v) {
  TRACE_VISIT ();
  if (v.get_itemtype () == NULL && v.get_occur () == NULL) {
    tstack.push (GENV_TYPESYSTEM.EMPTY_TYPE);
    return NULL;
  }
  return no_state;
}

void end_visit (const SequenceType& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const OccurrenceIndicator& v) {
  TRACE_VISIT ();
  TypeConstants::quantifier_t q = TypeConstants::QUANT_STAR;
  switch (v.get_type ()) {
  case ParseConstants::occurs_exactly_one:
    q = TypeConstants::QUANT_ONE; break;
  case ParseConstants::occurs_one_or_more:
    q = TypeConstants::QUANT_PLUS; break;
  case ParseConstants::occurs_optionally:
    q = TypeConstants::QUANT_QUESTION; break;
  case ParseConstants::occurs_zero_or_more:
    q = TypeConstants::QUANT_STAR; break;
  case ParseConstants::occurs_never:
    ZORBA_ASSERT (false);
  }

  if (q != TypeConstants::QUANT_ONE)
    tstack.push (CTXTS->create_type (*pop_tstack (), q));

  return no_state;
}

void end_visit (const OccurrenceIndicator& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const AtomicType& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const AtomicType& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  rchandle<QName> qname = v.get_qname ();
  xqtref_t t =
    CTXTS->create_named_atomic_type(sctx_p->lookup_elem_qname(qname->get_prefix (),
                                                              qname->get_localname (),
                                                              loc),
                                    TypeConstants::QUANT_ONE);
  // some types that should never be parsed, like xs:untyped, are;
  // we catch them with is_simple()
  if (t == NULL)
    ZORBA_ERROR_LOC_PARAM (XPST0051, loc, qname->get_qname (), "");
  else
    tstack.push (t);
}


void *begin_visit (const ItemType& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ItemType& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  tstack.push (GENV_TYPESYSTEM.ITEM_TYPE_ONE);
}


/*******************************************************************************

  NodeTest (NameTest | KindTest)

********************************************************************************/
void *begin_visit (const NameTest& v) {
  TRACE_VISIT ();
  return no_state;
}



void end_visit (const NameTest& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  expr *top = &*nodestack.top();

  axis_step_expr *axisExpr = NULL;
  trycatch_expr *tce = NULL;

  if ((axisExpr = dynamic_cast<axis_step_expr *>(top)) != NULL) {
    // Construct name-test match expr
    rchandle<match_expr> matchExpr = new match_expr(loc);;
    matchExpr->setTestKind(match_name_test);

    if (v.getQName() != NULL) {
      string qname = v.getQName()->get_qname();
      store::Item_t qn_h = (axisExpr->getAxis () == axis_kind_attribute ?
                            sctx_p->lookup_qname("", qname, loc) :
                            sctx_p->lookup_elem_qname(qname, loc));
      matchExpr->setQName(qn_h);
    } else {
      rchandle<Wildcard> wildcard = v.getWildcard();
      ZORBA_ASSERT(wildcard != NULL);

      switch (wildcard->getKind())
      {
      case ParseConstants::wild_all:
      {
        matchExpr->setWildKind(match_all_wild);
        break;
      }
      case ParseConstants::wild_elem:
      {
        matchExpr->setWildKind(match_name_wild);
        matchExpr->setWildName(wildcard->getPrefix());

        string qname = wildcard->getPrefix() + ":wildcard";

        store::Item_t qn_h = (axisExpr->getAxis () == axis_kind_attribute ?
                              sctx_p->lookup_qname("", qname, loc) :
                              sctx_p->lookup_elem_qname(qname, loc));
        matchExpr->setQName(qn_h);
        break;
      }
      case ParseConstants::wild_prefix:
      {
        matchExpr->setWildKind(match_prefix_wild);
        matchExpr->setWildName(wildcard->getLocalName());
        break;
      }
      }
    }

    // add the match expression
    axisExpr->setTest(matchExpr);
  } else if ((tce = dynamic_cast<trycatch_expr *>(top)) != NULL) {
    catch_clause *cc = &*(*tce)[0];
    if (v.getQName() != NULL) {
      string qname = v.getQName()->get_qname();
      store::Item_t qn_h = sctx_p->lookup_elem_qname (qname, loc);
      cc->set_nametest_h(new NodeNameTest(qn_h));
    } else {
      rchandle<Wildcard> wildcard = v.getWildcard();
      ZORBA_ASSERT(wildcard != NULL);

      switch (wildcard->getKind())
      {
        case ParseConstants::wild_all:
          cc->set_nametest_h(new NodeNameTest(xqpString("*").theStrStore, xqpString("*").theStrStore));
          break;
        case ParseConstants::wild_elem:
          cc->set_nametest_h(new NodeNameTest(xqpString("*").theStrStore, wildcard->getPrefix().theStrStore));
          break;
        case ParseConstants::wild_prefix:
          cc->set_nametest_h(new NodeNameTest(wildcard->getLocalName().theStrStore, xqpString("*").theStrStore));
          break;
      }
    }
  } else {
    ZORBA_ASSERT(false);
  }
}


void *begin_visit (const Wildcard& v) {
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const Wildcard& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const QName& v) {
  TRACE_VISIT();
  ZORBA_ASSERT(0);
  return no_state;
}


void end_visit (const QName& v, void* /*visit_state*/) {
  ZORBA_ASSERT(0);
  TRACE_VISIT_OUT ();
}


void *begin_visit (const AnyKindTest& v) {
  TRACE_VISIT ();
  // no action needed here
  return no_state;
}


void end_visit (const AnyKindTest& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  // if the top of the stack is an axis step expr, add a node test expr to it.
  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  if (axisExpr != NULL) {
    rchandle<match_expr> me = new match_expr(loc);
    me->setTestKind(match_anykind_test);
    axisExpr->setTest(me);
  } else {
    tstack.push(GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE);
  }
}


void *begin_visit (const DocumentTest& v) {
  TRACE_VISIT ();

  return no_state;
}


void end_visit (const DocumentTest& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  rchandle<ElementTest> elemTest = v.get_elem_test();

  if (elemTest == NULL) {
    axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
    if (axisExpr != NULL) {
      rchandle<match_expr> match = new match_expr(loc);
      match->setTestKind(match_doc_test);

      axisExpr->setTest(match);
    } else {
      tstack.push(GENV_TYPESYSTEM.DOCUMENT_TYPE_ONE);
    }
  } else {
    rchandle<QName> elemName = elemTest->getElementName();
    rchandle<TypeName> typeName = elemTest->getTypeName();
    bool nilled =  elemTest->isNilledAllowed();

    axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
    if (axisExpr != NULL) {
      rchandle<match_expr> match = new match_expr(loc);
      match->setTestKind(match_doc_test);

      if (elemName != NULL)
        match->setQName(sctx_p->lookup_elem_qname(elemName->get_qname(), loc));

      if (typeName != NULL)
        match->setTypeName(sctx_p->lookup_elem_qname(typeName->get_name()->get_qname(), loc));

      if (nilled)
        match->setNilledAllowed(true);

      axisExpr->setTest(match);
    } else {
      ZORBA_ERROR_LOC_DESC( XQP0004_SYSTEM_NOT_SUPPORTED, loc, "Document kind test");
    }
  }
}


void *begin_visit (const ElementTest& v) {
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const ElementTest& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  rchandle<QName> elemName = v.getElementName();
  rchandle<TypeName> typeName = v.getTypeName();
  bool nillable =  v.isNilledAllowed();

  // if the top of the stack is an axis step expr, add a node test expr to it.
  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  if (axisExpr != NULL) 
  {
    rchandle<match_expr> me = new match_expr(loc);
    me->setTestKind(match_elem_test);

    if (elemName != NULL)
      me->setQName(sctx_p->lookup_elem_qname(elemName->get_qname(), loc));

    if (typeName != NULL)
      me->setTypeName(sctx_p->lookup_elem_qname(typeName->get_name()->get_qname(), loc));

    if (nillable)
      me->setNilledAllowed(true);

    axisExpr->setTest(me);
  }

  // Else, create a sequence-type match
  else 
  {
    rchandle<NodeTest> nodeTest;
    if (elemName != NULL) 
    {
      store::Item_t qnameItem = sctx_p->lookup_elem_qname(elemName->get_qname(), loc);

      rchandle<NodeNameTest> nodeNameTest =
        new NodeNameTest(qnameItem->getNamespace(), qnameItem->getLocalName());

      nodeTest = new NodeTest(store::StoreConsts::elementNode, nodeNameTest);
    }
    else 
    {
      nodeTest = new NodeTest(store::StoreConsts::elementNode);
    }

    xqtref_t contentType;
    if (typeName != NULL) 
    {
      store::Item_t qnameItem =
        sctx_p->lookup_elem_qname(typeName->get_name()->get_qname(), loc);

      contentType = CTXTS->create_named_type(qnameItem, TypeConstants::QUANT_ONE);
    }

    xqtref_t seqmatch = CTXTS->
      create_node_type(nodeTest, contentType, TypeConstants::QUANT_ONE, nillable);

    tstack.push(seqmatch);
  }
}


void *begin_visit (const AttributeTest& v) {
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const AttributeTest& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT();

  rchandle<QName> attrName = v.get_attr_name();
  rchandle<TypeName> typeName = v.get_type_name();

  // if the top of the stack is an axis step expr, add a node test expr to it.
  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  if (axisExpr != NULL) 
  {
    rchandle<match_expr> match = new match_expr(loc);
    match->setTestKind(match_attr_test);

    if (attrName != NULL)
      match->setQName(sctx_p->lookup_qname("", attrName->get_qname(), loc));

    if (typeName != NULL)
      match->setTypeName(sctx_p->lookup_elem_qname(typeName->get_name()->get_qname(), loc));

    axisExpr->setTest(match);
  }
  else 
  {
    rchandle<NodeTest> nodeTest;
    if (attrName != NULL) {
      store::Item_t qnameItem = sctx_p->lookup_qname("", attrName->get_qname(), loc);

      rchandle<NodeNameTest> nodeNameTest =
        new NodeNameTest(qnameItem->getNamespace(),
                         qnameItem->getLocalName());

      nodeTest = new NodeTest(store::StoreConsts::attributeNode, nodeNameTest);
    } else {
      nodeTest = new NodeTest(store::StoreConsts::attributeNode);
    }

    xqtref_t contentType;
    if (typeName != NULL) {
      store::Item_t qnameItem = sctx_p->lookup_elem_qname(typeName->get_name()->get_qname(), loc);

      contentType = CTXTS->create_named_type(qnameItem, TypeConstants::QUANT_ONE);
    }

    xqtref_t seqmatch = CTXTS->
      create_node_type(nodeTest, contentType, TypeConstants::QUANT_ONE, false);

    tstack.push(seqmatch);
  }
}


void *begin_visit (const TextTest& v) {
  TRACE_VISIT ();
  // no action needed here
  return no_state;
}


void end_visit (const TextTest& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  if (axisExpr != NULL) {
    rchandle<match_expr> match = new match_expr(loc);
    match->setTestKind(match_text_test);
    axisExpr->setTest(match);
  } else {
    tstack.push(GENV_TYPESYSTEM.TEXT_TYPE_ONE);
  }
}


void *begin_visit (const CommentTest& v) {
  TRACE_VISIT ();
  // no action needed here
  return no_state;
}


void end_visit (const CommentTest& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  if (axisExpr != NULL) {
    rchandle<match_expr> match = new match_expr(loc);
    match->setTestKind(match_comment_test);
    axisExpr->setTest(match);
  } else {
    tstack.push(GENV_TYPESYSTEM.COMMENT_TYPE_ONE);
  }
}


void *begin_visit (const PITest& v) {
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const PITest& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  string target = v.get_target();
  store::Item_t qname = NULL;
  if (target != "")
    GENV_ITEMFACTORY->createQName(qname, NULL, NULL, target.c_str ());
  if (axisExpr != NULL) {
    rchandle<match_expr> match = new match_expr(loc);
    match->setTestKind(match_pi_test);
    if (target != "")
      match->setQName(qname);
    axisExpr->setTest(match);
  } else {
    if (target == "")
      tstack.push(GENV_TYPESYSTEM.PI_TYPE_ONE);
    else {
      rchandle<NodeTest> nodetest =
        new NodeTest (store::StoreConsts::piNode, new NodeNameTest (qname));
      xqtref_t t =
        GENV_TYPESYSTEM.create_node_type (nodetest, NULL, TypeConstants::QUANT_ONE,
                                          false);
      tstack.push (t);
    }
  }
}


void *begin_visit (const SchemaAttributeTest& v) {
  TRACE_VISIT ();
  rchandle<match_expr> match = new match_expr(loc);
  match->setTestKind(match_xs_attr_test);

  rchandle<QName> attr_h = v.get_attr();
  if (attr_h!=NULL) {
    match->setQName(sctx_p->lookup_elem_qname (attr_h->get_qname(), loc));
  }
  nodestack.push(&*match);
  return no_state;
}


void end_visit (const SchemaAttributeTest& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const SchemaElementTest& v) {
  TRACE_VISIT ();
  rchandle<match_expr> match = new match_expr(loc);
  match->setTestKind(match_xs_elem_test);

  rchandle<QName> elem_h = v.get_elem();
  if (elem_h!=NULL) {
    match->setQName (sctx_p->lookup_qname ("", elem_h->get_qname(), loc));
  }
  nodestack.push(&*match);
  return no_state;
}


void end_visit (const SchemaElementTest& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

xqpString tempname () {
  return "$$temp" + to_string(tempvar_counter++);
}

varref_t tempvar(const QueryLoc& loc, var_expr::var_kind kind)
{
  xqpString lname (tempname ());
  return create_var(loc, lname, kind);
}


rchandle<flwor_expr> wrap_in_let_flwor (expr_t expr, varref_t lv, expr_t ret) {
  rchandle<flwor_expr> fe = new flwor_expr (lv->get_loc ());
  fe->add (wrap_in_letclause (expr, lv));
  fe->set_retval (ret);
  return fe;
}


/*******************************************************************************

  Path Expressions

  The syntax tree for a generic PathExpr looks like this:

       PathExpr
           |
         rpe1
        /    \
      step1  rpe2
            /    \
          step2  rpe3
                /    \
              step3  step4

  The possible types of a PathExpr are:
  1. path_leading_lone_slash
  2. path_leading_slash
  3. path_leading_slashslash
  4. path_relative

  In case 1, the PathExpr does not have any child node.

  rpe-i says how step-i is connected with step-(i+1), i.e. with / or //.

********************************************************************************/
void *begin_visit (const PathExpr& v) {
  TRACE_VISIT();

  const PathExpr& pe = v;

  ParseConstants::pathtype_t pe_type = pe.get_type();

  expr_t result;
  rchandle<relpath_expr> path_expr = NULL;

  // Put a NULL in the stack to mark the beginning of a PathExp tree.
  nodestack.push(NULL);

  if (pe_type != ParseConstants::path_leading_lone_slash) {
    path_expr = new relpath_expr(loc);

    result = path_expr.getp();
  }

  // If path expr starts with / or // (cases 1, 2, or 3), create an expr
  // R = fn:root(./self::node()). 
  // In case 1, just push R to the nodestack.
  // In case 2, put "R/..." to the nodestact 
  // In case 3, put "R/descendant-or-self/...." to the nodestack
  if (pe_type != ParseConstants::path_relative)  {
    rchandle<relpath_expr> ctx_path_expr = new relpath_expr(loc);
    ctx_path_expr->add_back(DOT_VAR);

    rchandle<match_expr> me = new match_expr(loc);
    me->setTestKind(match_anykind_test);
    rchandle<axis_step_expr> ase = new axis_step_expr(loc);
    ase->setAxis(axis_kind_self);
    ase->setTest(me);

    ctx_path_expr->add_back(&*ase);

    rchandle<fo_expr> fo = new fo_expr(loc, LOOKUP_FN("fn", "root", 1));
    fo->add(&*ctx_path_expr);

    result = fo.getp();

    if (path_expr != NULL) {
      path_expr->add_back(&*fo);
      result = path_expr.getp();
    }

    if (pe_type == ParseConstants::path_leading_slashslash) {
      rchandle<axis_step_expr> ase = new axis_step_expr(loc);
      rchandle<match_expr> me = new match_expr(loc);
      me->setTestKind(match_anykind_test);
      ase->setAxis(axis_kind_descendant_or_self);
      ase->setTest(me);

      path_expr->add_back(&*ase);
    }
  }

  nodestack.push(result.getp());
  return no_state;
}


void end_visit (const PathExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  expr_t arg2 = pop_nodestack();
  expr_t arg1 = pop_nodestack();

  ZORBA_ASSERT(arg1 == NULL);

  nodestack.push(wrap_in_dos_and_dupelim(arg2));
}


void* begin_visit(const RelativePathExpr& v)
{
  TRACE_VISIT ();

  const RelativePathExpr& rpe = v;

  expr_t e = pop_nodestack();
  relpath_expr* pathExpr = e.dyn_cast<relpath_expr>();
  ZORBA_ASSERT(pathExpr != NULL);

  rchandle<exprnode> child1 = rpe.get_step_expr();
  ZORBA_ASSERT(child1 != NULL);
  AxisStep* axisStep = child1.dyn_cast<AxisStep>();

  // If the current rpe is the root of the Path Tree ..
  if (pathExpr->size() == 0) {
    if (axisStep != NULL) {
      pathExpr->add_back(DOT_VAR);

      if (axisStep->get_predicate_list() == NULL) {
        nodestack.push(pathExpr);
      } else {
        rchandle<flwor_expr> flworExpr = wrap_expr_in_flwor(pathExpr, false);
        nodestack.push(flworExpr.getp());
      }
    } else {
      nodestack.push(pathExpr);
    }
  }

  // Else if child1 is an axis step with no repdicates, just put the pathExpr
  // back in the stack.
  else if (axisStep != NULL && axisStep->get_predicate_list() == NULL) {
    nodestack.push(pathExpr);
  }

  // Else, child1 is an axis step with predicates or a filter expr, and child1
  // is not the very 1st step in the path expr. In this case, pathExpr becomes
  // the input to a new flwor expr that will compute, once for each node in
  // pathExpr, the next step in the path. The flwor is pushed to the nodestack.
  else {
    expr_t inputExpr = wrap_in_dos_and_dupelim(pathExpr);
    rchandle<flwor_expr> flworExpr = wrap_expr_in_flwor(inputExpr, false);
    nodestack.push(flworExpr.getp());
  }

  return no_state;
}


void intermediate_visit(const RelativePathExpr& rpe, void* /*visit_state*/)
{
  const QueryLoc& loc = rpe.get_location();

  // Let rpe be the i-th rpe in the Path Tree. This method is called after having
  // translated step-i, but before starting the translation of rpe-(i+1).

  // There were 2 exprs in the stack: stepExpr is the expr for step-i and curExpr
  // is the expr we have constructed so far for the ancestors of rpe-i. CurExpr
  // is either a path expr or a flwor expr.
  expr_t stepExpr = pop_nodestack();
  expr_t curExpr = pop_nodestack();

  relpath_expr* pathExpr = curExpr.dyn_cast<relpath_expr>();
  flwor_expr* flworExpr = curExpr.dyn_cast<flwor_expr>();

  // If curExpr is a path expr, step-i was an axis step with no predicates, or
  // rpe-i is the root of the Path Tree.
  if (pathExpr != NULL) {
    axis_step_expr* axisExpr = stepExpr.dyn_cast<axis_step_expr>();
    ZORBA_ASSERT(axisExpr != NULL || pathExpr->size() == 0);

    pathExpr->add_back(stepExpr);
  }

  // Else, step-i was not an axis step, or it contained predicates. In this
  // case, translation of step-i resulted in a flwor expr that includes step-i
  // and all the ancestors of rpe-i. We create a new path_expr and make the
  // flwor expr its 1st step (i.e. flwor/.... or flwor/descendant-or-sef/...)
  else {
    ZORBA_ASSERT(flworExpr != NULL);

    flworExpr->set_retval(stepExpr);
    pop_scope();

    pathExpr = new relpath_expr(loc);
    pathExpr->add_back(flworExpr);
  }

  if (rpe.get_step_type() == ParseConstants::st_slashslash) {
    rchandle<axis_step_expr> ase = new axis_step_expr(loc);
    rchandle<match_expr> me = new match_expr(loc);
    me->setTestKind(match_anykind_test);
    ase->setAxis(axis_kind_descendant_or_self);
    ase->setTest(me);
    pathExpr->add_back(ase.getp());
  }

  rchandle<exprnode> child2 = rpe.get_relpath_expr();
  ZORBA_ASSERT(child2 != NULL);
  AxisStep* axisStep = child2.dyn_cast<AxisStep>();

  // If the second child of rpe-i is another rpe or an axis step with no
  // predicates, then we push the current path_expr to the stack.
  if (child2.dyn_cast<RelativePathExpr>() != NULL ||
      (axisStep != NULL && axisStep->get_predicate_list() == NULL))
  {
    nodestack.push(pathExpr);
  }

  // Else we have reached the last step of the Path Tree, and this step is a
  // filter step or an axist step with predicates. In this case, pathExpr
  // becomes the input to a new flwor expr that will compute, once for each
  // node in pathExpr, the next step in the path. The flwor is pushed to the
  // nodestack.
  else {
    expr_t inputSeqExpr = wrap_in_dos_and_dupelim(pathExpr);
    rchandle<flwor_expr> flworExpr = wrap_expr_in_flwor(inputSeqExpr, false);
    nodestack.push(flworExpr.getp());
  }
}


void end_visit (const RelativePathExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  const RelativePathExpr& rpe = v;
  rchandle<exprnode> child2 = rpe.get_relpath_expr();

  // If rpe-i is not the bottom rpe in the Path Tree, there is nothing to be done.  
  if (child2.dyn_cast<RelativePathExpr>() != NULL)
    return;

  // There were 2 exprs in the stack: stepExpr is the expr for step-(i+1) and 
  // curExpr is the expr we have constructed so far for step-i and the ancestors
  // of rpe-i. CurExpr is either a path expr or a flwor expr.
  expr_t stepExpr = pop_nodestack();
  expr_t curExpr = pop_nodestack();

  relpath_expr* pathExpr = curExpr.dyn_cast<relpath_expr>();
  flwor_expr* flworExpr = curExpr.dyn_cast<flwor_expr>();

  // If curExpr is a path expr, step-(i+1) was an axis step with no predicates.
  if (pathExpr != NULL) {
    axis_step_expr* axisExpr = stepExpr.dyn_cast<axis_step_expr>();
    ZORBA_ASSERT(axisExpr != NULL);

    pathExpr->add_back(stepExpr);
    nodestack.push(pathExpr);
  } else {
    ZORBA_ASSERT(flworExpr != NULL);
    ZORBA_ASSERT(stepExpr != NULL);

    flworExpr->set_retval(stepExpr);
    pop_scope();

    nodestack.push(flworExpr);
  }
}


/*******************************************************************************

  StepExpr ::= AxisStep  |  FilterExpr

  AxisStep ::= (ForwardStep | ReverseStep)  PredicateList?

  FilterExpr ::= PrimaryExpr  PredicateList?

********************************************************************************/

void* begin_visit(const FilterExpr& v)
{
  TRACE_VISIT ();

  return no_state;
}


void post_primary_visit(const FilterExpr& v, void* /*visit_state*/)
{
  // This method is called from AxisExpr::accept() after the primary expr is
  // translated, but before the associated predicate list is translated.

  if (!v.isPathStep())
    return;

  PredicateList* pl = v.get_pred_list().getp();

  ZORBA_ASSERT(pl != NULL && pl->size() > 0);

  const QueryLoc& loc = v.get_location();

  expr_t primaryExpr = pop_nodestack();

  expr_t e = pop_nodestack();
  flwor_expr* flworExpr = e.dyn_cast<flwor_expr>();

  if (flworExpr != NULL) {
    // for each item in the input seq
    rchandle<forlet_clause> fcOuterDot = (*flworExpr)[0];

    // compute the input seq for the pred (= outer_dot/primaryExpr)
    if (primaryExpr->get_expr_kind() == axis_step_expr_kind) {
      rchandle<relpath_expr> pathStepExpr = new relpath_expr(loc);
      pathStepExpr->add_back(fcOuterDot->get_var().getp());
      pathStepExpr->add_back(primaryExpr.getp());
      primaryExpr = pathStepExpr.getp();
    }
    
    rchandle<forlet_clause> lcPredSeq = wrap_in_letclause(primaryExpr.getp());

    flworExpr->add(lcPredSeq);

    nodestack.push(flworExpr);
    nodestack.push(lcPredSeq->get_var().getp());
  } else {
     relpath_expr* pathExpr = e.dyn_cast<relpath_expr>();
     ZORBA_ASSERT(pathExpr != NULL && pathExpr->size() == 0);

     nodestack.push(pathExpr);
     nodestack.push(primaryExpr);
  }
}


void end_visit (const FilterExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT();
}


void* begin_visit(const AxisStep& v)
{
  TRACE_VISIT ();

  rchandle<axis_step_expr> ase = new axis_step_expr(loc);
  nodestack.push(ase.getp());
  return no_state;
}


void post_axis_visit(const AxisStep& v, void* /*visit_state*/)
{
  // This method is called from AxisStep::accept() after the step itself is
  // translated, but before the associated predicate list (if any) is translated.

  PredicateList* pl = v.get_predicate_list().getp();

  if (pl == NULL || pl->size() == 0)
    return;

  const QueryLoc& loc = v.get_location();

  expr_t e = pop_nodestack();
  rchandle<axis_step_expr> axisExpr = e.dyn_cast<axis_step_expr>();
  ZORBA_ASSERT(axisExpr != NULL);

  e = pop_nodestack();
  flwor_expr* flworExpr = e.dyn_cast<flwor_expr>();
  ZORBA_ASSERT(flworExpr != NULL);

  // for each item in the input seq
  rchandle<forlet_clause> fcOuterDot = (*flworExpr)[0];

  // compute the input seq for the pred (= outer_dot/axisExpr)
  rchandle<relpath_expr> pathStepExpr = new relpath_expr(loc);
  pathStepExpr->add_back(fcOuterDot->get_var().getp());
  pathStepExpr->add_back(axisExpr.getp());
    
  rchandle<forlet_clause> lcPredSeq = wrap_in_letclause(pathStepExpr.getp());

  flworExpr->add(lcPredSeq);

  nodestack.push(flworExpr);
  nodestack.push(lcPredSeq->get_var().getp());
}


void end_visit (const AxisStep& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT();
}


void *begin_visit (const PredicateList& v) {
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const PredicateList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void pre_predicate_visit(const PredicateList& v, void* /*visit_state*/)
{
  // This method is called from PredicateList::accept(), before calling accept()
  // on each predicate in the list

  // get the predicate input seq
  expr_t inputSeqExpr = pop_nodestack();

  rchandle<flwor_expr> flworExpr = wrap_expr_in_flwor(inputSeqExpr, true);

  nodestack.push(flworExpr.getp());
}


void post_predicate_visit(const PredicateList& v, void* /*visit_state*/)
{
  // This method is called from PredicateList::accept(), after calling accept()
  // on each predicate in the list

  expr_t predExpr = pop_nodestack();

  expr_t f = pop_nodestack();
  flwor_expr* flworExpr = f.dyn_cast<flwor_expr>();
  ZORBA_ASSERT(flworExpr != NULL);

  const QueryLoc& loc = predExpr->get_loc();

  rchandle<forlet_clause> lcPred = wrap_in_letclause(predExpr);
  var_expr* predvar = lcPred->get_var().getp();

  flworExpr->add(lcPred);

  expr_t dotvar = DOT_VAR;

  // Check if the pred expr returns a numeric result
  rchandle<fo_expr> cond = new fo_expr(loc, CACHED (op_or, LOOKUP_OPN ("or")));
  cond->add(new instanceof_expr(loc, predvar, GENV_TYPESYSTEM.DECIMAL_TYPE_ONE));
  cond->add(new instanceof_expr(loc, predvar, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));
  cond = new fo_expr(loc, CACHED (op_or, LOOKUP_OPN ("or")), &*cond);
  cond->add(new instanceof_expr(loc, predvar, GENV_TYPESYSTEM.FLOAT_TYPE_ONE));

  // If so: return $dot if the value of the pred expr is equal to the value
  // of $dot_pos var, otherwise return the empty seq.
  rchandle<fo_expr> eq = new fo_expr(loc, LOOKUP_OP2("value-equal"));
  eq->add(lookup_ctx_var(DOT_POS_VARNAME, loc).getp ());
  eq->add(predvar);

  expr_t thenExpr = new if_expr(loc, eq.getp(), dotvar, create_seq(loc));

  // Else, return $dot if the the value of the pred expr is true, otherwise
  // return the empty seq.
  expr_t elseExpr = new if_expr(loc, predvar, dotvar, create_seq(loc));

  expr_t ifExpr = new if_expr(loc, cond.getp(), thenExpr, elseExpr);

  flworExpr->set_retval(ifExpr);

  nodestack.push(flworExpr);

  pop_scope();
}


void *begin_visit (const ForwardStep& v) {
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const ForwardStep& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const AbbrevForwardStep& v) {
  TRACE_VISIT ();

  rchandle<axis_step_expr> ase = expect_axis_step_top ();

  if (v.get_attr_bit()) {
    ase->setAxis(axis_kind_attribute);
  } else {
    ase->setAxis(axis_kind_child);
  }

  return no_state;
}


void end_visit (const AbbrevForwardStep& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const ForwardAxis& v) {
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const ForwardAxis& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  rchandle<axis_step_expr> ase = expect_axis_step_top ();

  switch (v.get_axis())
  {
  case ParseConstants::axis_child:
  {
    ase->setAxis(axis_kind_child);
    break;
  }
  case ParseConstants::axis_descendant:
  {
    ase->setAxis(axis_kind_descendant);
    break;
  }
  case ParseConstants::axis_attribute:
  {
    ase->setAxis(axis_kind_attribute);
    break;
  }
  case ParseConstants::axis_self:
  {
    ase->setAxis(axis_kind_self);
    break;
  }
  case ParseConstants::axis_descendant_or_self:
  {
    ase->setAxis(axis_kind_descendant_or_self);
    break;
  }
  case ParseConstants::axis_following_sibling:
  {
    ase->setAxis(axis_kind_following_sibling);
    break;
  }
  case ParseConstants::axis_following:
  {
    ase->setAxis(axis_kind_following);
    break;
  }
  }
}


void *begin_visit (const ReverseStep& v) {
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const ReverseStep& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const ReverseAxis& v) {
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const ReverseAxis& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  rchandle<axis_step_expr> ase = expect_axis_step_top ();

  switch (v.get_axis())
  {
  case ParseConstants::axis_parent:
  {
    ase->setAxis(axis_kind_parent);
    break;
  }
  case ParseConstants::axis_ancestor:
  {
    ase->setAxis(axis_kind_ancestor);
    break;
  }
  case ParseConstants::axis_preceding_sibling:
  {
    ase->setAxis(axis_kind_preceding_sibling);
    break;
  }
  case ParseConstants::axis_preceding:
  {
    ase->setAxis(axis_kind_preceding);
    break;
  }
  case ParseConstants::axis_ancestor_or_self:
  {
    ase->setAxis(axis_kind_ancestor_or_self);
    break;
  }
  }
}


/*******************************************************************************

********************************************************************************/
void *begin_visit (const QuantifiedExpr& v) {
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const QuantifiedExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  rchandle<flwor_expr> flwor(new flwor_expr(loc));
  flwor->set_retval(new const_expr(loc, true));
  rchandle<expr> sat = pop_nodestack();
  if (v.get_qmode() == ParseConstants::quant_every) {
    rchandle<fo_expr> uw = new fo_expr(v.get_expr()->get_location(), LOOKUP_FN("fn", "not", 1));
    uw->add(sat);
    sat = uw.getp();
  }
  flwor->set_where(sat);
  vector<varref_t> vars_vals (2 * v.get_decl_list()->size());
  generate (vars_vals.rbegin (), vars_vals.rend (), stack_to_generator (nodestack));
  for (int i = 0; i < v.get_decl_list()->size(); ++i) {
    pop_scope ();
    varref_t ve = vars_vals [2 * i + 1].cast<var_expr> ();
    flwor->add(wrap_in_forclause (&*vars_vals [2 * i], ve, NULL));
  }
  rchandle<fo_expr> quant = new fo_expr(loc, v.get_qmode() == ParseConstants::quant_every ? LOOKUP_FN("fn", "empty", 1) : LOOKUP_FN("fn", "exists", 1));
  quant->add (&*flwor);
  nodestack.push (&*quant);
}


/*******************************************************************************

********************************************************************************/
void *begin_visit (const RangeExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const RangeExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  fo_expr *e = new fo_expr (loc, LOOKUP_OP2 ("to"));

  rchandle<expr> e1_h = pop_nodestack ();
  rchandle<expr> e2_h = pop_nodestack ();

  e->add(e2_h);
  e->add(e1_h);

  nodestack.push(e);
}


void *begin_visit (const StringLiteral& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const StringLiteral& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  nodestack.push(new const_expr(loc,v.get_strval()));
}

void *begin_visit (const TreatExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const TreatExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  nodestack.push (new treat_expr (loc, pop_nodestack (), pop_tstack (), XPDY0050));
}

void *begin_visit (const TypeswitchExpr& v) {
  TRACE_VISIT ();

  varref_t sv = tempvar (v.get_switch_expr ()->get_location (), var_expr::let_var);

  expr_t defret;
  {
    string defvar_name = v.get_default_varname ();
    varref_t defvar;
    if (! defvar_name.empty ()) {
      push_scope ();
      defvar = bind_var (v.get_default_clause ()->get_location (), defvar_name, var_expr::let_var);
    }
    v.get_default_clause ()->accept (*this);
    defret = pop_nodestack ();
    if (! defvar_name.empty ()) {
      pop_scope ();
      expr_update_t lUpdateType = (defret->isUpdating() ? UPDATE_EXPR : SIMPLE_EXPR);
      defret = &*wrap_in_let_flwor (&*sv, defvar, defret);
      defret->setUpdateType(lUpdateType);
    }
  }

  const CaseClauseList *clauses = v.get_clause_list ();
  for (vector<rchandle<CaseClause> >::const_reverse_iterator it = clauses->rbegin();
       it!=clauses->rend(); ++it)
  {
    const CaseClause *e_p = &**it;
    const QueryLoc &loc = e_p->get_location ();
    string name = e_p->get_varname ();
    varref_t var;
    if (! name.empty ()) {
      push_scope ();
      var = bind_var (loc, name, var_expr::let_var);
    }
    e_p->accept (*this);
    xqtref_t type = pop_tstack ();
    if (! name.empty ()) {
      pop_scope ();
      expr_t lExpr = pop_nodestack();
      expr_t lFlwor = wrap_in_let_flwor (new cast_expr (loc, &*sv, type), var, lExpr);
      lFlwor->setUpdateType(lExpr->getUpdateType());
      nodestack.push (lFlwor);
    }
    expr_t lThen = pop_nodestack();
    expr_update_t lUpdateType = update_type_check_for_if(
      lThen->getUpdateType(), 
      defret->getUpdateType(),
      loc);
    defret = new if_expr (e_p->get_location (),
                          new instanceof_expr (loc, &*sv, type),
                          lThen, defret);
    defret->setUpdateType(lUpdateType);
  }

  {
    v.get_switch_expr ()->accept (*this);
    expr_t se = pop_nodestack ();
    if (se->isUpdating()) {
      ZORBA_ERROR_LOC(XUST0001, loc);
    }
    expr_t lFlwor = wrap_in_let_flwor (se, sv, defret);
    lFlwor->setUpdateType(defret->getUpdateType());
    nodestack.push (lFlwor);
  }

  return NULL;
}

void end_visit (const TypeswitchExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  // shouldn't get here, begin_visit() rejects visitor
  ZORBA_ASSERT (false);
}


void *begin_visit (const UnaryExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const UnaryExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  rchandle<expr> e1_h = pop_nodestack ();
  fo_expr *fo_p = new fo_expr(loc,
                              v.get_signlist()->get_sign()
                              ? LOOKUP_OP1 ("unary-plus")
                              : LOOKUP_OP1 ("unary-minus"));
  fo_p->add(e1_h);
  nodestack.push(fo_p);
}

void *begin_visit (const UnionExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const UnionExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  rchandle<expr> e1_h = pop_nodestack ();
  rchandle<expr> e2_h = pop_nodestack ();
  fo_expr *fo_h = new fo_expr(loc, LOOKUP_OP2 ("union"));
  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push(new fo_expr (loc, LOOKUP_OP1 ("sort-distinct-nodes-ascending"), fo_h));
}

void *begin_visit (const UnorderedExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const UnorderedExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  nodestack.push (new order_expr (loc, order_expr::unordered,
                                  pop_nodestack ()));
}

void *begin_visit (const ValidateExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ValidateExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  nodestack.push (new validate_expr (loc, v.get_valmode (), pop_nodestack ()));
}

void *begin_visit (const VarRef& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const VarRef& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  var_expr *e = lookup_var (v.get_varname ());
  if (e == NULL)
    ZORBA_ERROR_LOC_PARAM( XPST0008, loc, v.get_varname (), "");
  if (e->get_depth () == 0 && ! global_decl_stack.empty ()) {
    string key = "V" + static_context::qname_internal_key (e->get_varname ());
    add_multimap_value (global_deps, global_decl_stack.top (), key);
  }
  nodestack.push (new wrapper_expr (v.get_location (), rchandle<expr> (e)));
}


/* update-related */
void *begin_visit (const DeleteExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const DeleteExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  expr_t lTarget = pop_nodestack();
  if (lTarget->isUpdating()) {
    ZORBA_ERROR_LOC(XUST0001, loc);
  }
  expr_t aDelete = new delete_expr(loc, lTarget);
  nodestack.push(aDelete);
}

void *begin_visit (const InsertExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const InsertExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  expr_t lTarget = pop_nodestack();
  expr_t lSource = pop_nodestack();
  if (lTarget->isUpdating() || lSource->isUpdating()) {
    ZORBA_ERROR_LOC(XUST0001, loc);
  }
  fo_expr* lEnclosed = new fo_expr(loc, CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
  lEnclosed->add(lSource);
  lSource = lEnclosed;

  expr_t lInsert = new insert_expr(loc, v.getType(), lSource, lTarget);
  nodestack.push(lInsert);
}


void *begin_visit (const RenameExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const RenameExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT();

  expr_t nameExpr = pop_nodestack();
  expr_t targetExpr = pop_nodestack();

  if (nameExpr->isUpdating() || targetExpr->isUpdating()) {
    ZORBA_ERROR_LOC(XUST0001, loc);
  }

  rchandle<fo_expr> atomExpr = (fo_expr*)wrap_in_atomization (nameExpr).getp();
  nameExpr = new name_cast_expr(loc, atomExpr.getp(), ns_ctx);

  expr_t renameExpr = new rename_expr(loc, targetExpr, nameExpr);

  nodestack.push(renameExpr);
}

void *begin_visit (const ReplaceExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ReplaceExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  expr_t lReplacement = pop_nodestack();
  expr_t lTarget = pop_nodestack();
  if (lReplacement->isUpdating() || lTarget->isUpdating()) {
    ZORBA_ERROR_LOC(XUST0001, loc);
  }

  if (v.getType() == store::UpdateConsts::NODE) {
    fo_expr* lEnclosed = new fo_expr(loc, CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
    lEnclosed->add(lReplacement);
    lReplacement = lEnclosed;
  }

  expr_t lReplace = new replace_expr(loc,
                                     v.getType(),
                                     lTarget,
                                     lReplacement);
  nodestack.push(lReplace);
}

void *begin_visit (const RevalidationDecl& v) {
  TRACE_VISIT ();
  ZORBA_NOT_IMPLEMENTED ("revalidation");
  return no_state;
}

void end_visit (const RevalidationDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const TransformExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const TransformExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  expr_t lReturn = pop_nodestack();
  if (lReturn->isUpdating()) {
    ZORBA_ERROR_LOC(XUST0001, loc);
  }
  expr_t lModify = pop_nodestack();
  if (lModify->getUpdateType() == SIMPLE_EXPR) {
    ZORBA_ERROR_LOC(XUST0002, loc);
  }
  std::auto_ptr<transform_expr> lTransform(new transform_expr(loc, lModify, lReturn));
  const size_t lSize = v.get_varname_list()->size();
  for (size_t i = 0; i < lSize; ++i)
  {
    expr_t lExpr = pop_nodestack();
    if (lExpr->isUpdating()) {
      ZORBA_ERROR_LOC(XUST0001, loc);
    }
    varref_t lVarExpr = pop_nodestack_var ();
    lVarExpr->set_kind(var_expr::copy_var);
    copy_clause* lCCE = new copy_clause( lVarExpr, lExpr);
    lTransform->add(lCCE);
    pop_scope();
  }
  nodestack.push(lTransform.release());
}

void *begin_visit (const VarNameList& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const VarNameList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const VarBinding& v) {
  TRACE_VISIT ();
  push_scope ();
  bind_var_and_push (loc, v.get_varname (), var_expr::copy_var);
  return no_state;
}

void end_visit (const VarBinding& v, void*) {
  TRACE_VISIT_OUT ();
}

/* try-catch-related */
void *begin_visit (const TryExpr& v) {
  TRACE_VISIT ();
  nodestack.push(new trycatch_expr(loc));
  return no_state;
}

void end_visit (const TryExpr& v, void* visit_state) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const EvalExpr& v) {
  TRACE_VISIT ();
  if (xquery_version <= 100)
    ZORBA_ERROR_LOC (XPST0003, loc);
  return no_state;
}

void end_visit (const EvalExpr& v, void* visit_state) {
  TRACE_VISIT_OUT ();

  rchandle<eval_expr> result =
    new eval_expr(loc, create_cast_expr (loc, pop_nodestack (), GENV_TYPESYSTEM.STRING_TYPE_ONE, true));

  rchandle<VarGetsDeclList> vgdl = v.get_vars ();
  
  for (size_t i = 0; i < vgdl->size (); i++) {
    varref_t ve = pop_nodestack ().dyn_cast<var_expr> ();
    ve->set_kind (var_expr::eval_var);
    expr_t val = pop_nodestack ();
    if (ve->get_type () != NULL)
      val = new treat_expr (val->get_loc (), val, ve->get_type (), XPTY0004);
    result->add_var (eval_expr::eval_var (&*ve, val));
    pop_scope ();
  }

  nodestack.push (&*result);
}

void *begin_visit (const CatchListExpr& v) {
  TRACE_VISIT ();
  expr_t te = pop_nodestack();
  trycatch_expr *tce = dynamic_cast<trycatch_expr *>(&*nodestack.top());
  tce->set_try_expr(te);
  return no_state;
}

void end_visit (const CatchListExpr& v, void* visit_state) {
  TRACE_VISIT_OUT ();
}

expr_t cc_component(const QueryLoc& loc, varref_t var, const char *local)
{
  expr_t exists = new fo_expr(loc, LOOKUP_FN("fn", "exists", 1), &*var);
  expr_t emptyseq = create_seq (loc);
  store::Item_t qname;
  GENV_ITEMFACTORY->createQName(qname, XQUERY_FN_NS, "fn", local);
  expr_t eName = new const_expr(loc, qname);
  expr_t eContents = new fo_expr(loc, CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")), &*var);
  push_elem_scope();
  expr_t eVal = new elem_expr(loc, eName, NULL, eContents, ns_ctx);
  pop_elem_scope();
  expr_t ite = new if_expr(loc, exists, eVal, emptyseq);

  return ite;
}

void *begin_visit (const CatchExpr& v) {
  TRACE_VISIT ();
  trycatch_expr *tce = dynamic_cast<trycatch_expr *>(&*nodestack.top());
  trycatch_expr::clauseref_t cc = new catch_clause();
  tce->add_clause_in_front(cc);
  push_scope();
  if (v.getVarErrorCode() != "") {
    varref_t ev = bind_var(loc, v.getVarErrorCode(), var_expr::catch_var, GENV_TYPESYSTEM.QNAME_TYPE_QUESTION);
    cc->set_errorcode_var_h(ev);
#ifdef ZORBA_DEBUGGER
        if(compilerCB->m_debugger != 0)
        {
          theScopedVariables.push_back(ev);
        }
#endif

  if (v.getVarErrorDescr() != "") {
      varref_t dv = bind_var(loc, v.getVarErrorDescr(), var_expr::catch_var, GENV_TYPESYSTEM.STRING_TYPE_QUESTION);
      cc->set_errordesc_var_h(dv);
#ifdef ZORBA_DEBUGGER
        if(compilerCB->m_debugger != 0)
        {
          theScopedVariables.push_back(dv);
        }
#endif
      if (v.getVarErrorVal() != "") {
        varref_t vv = bind_var(loc, v.getVarErrorVal(), var_expr::catch_var, GENV_TYPESYSTEM.ITEM_TYPE_QUESTION);
        cc->set_errorobj_var_h(vv);
#ifdef ZORBA_DEBUGGER
        if(compilerCB->m_debugger != 0)
        {
          theScopedVariables.push_back(vv);
        }
#endif
      }
    }
  }
  return no_state;
}

void end_visit (const CatchExpr& v, void* visit_state) {
  TRACE_VISIT_OUT ();
  expr_t ce = pop_nodestack();
  trycatch_expr *tce = dynamic_cast<trycatch_expr *>(&*nodestack.top());
  catch_clause *cc = &*(*tce)[0];
  cc->set_catch_expr_h(ce);
  pop_scope();
}

void *begin_visit (const ExitExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ExitExpr& v, void* visit_state) {
  TRACE_VISIT_OUT ();
  nodestack.push (new exit_expr (loc, pop_nodestack ()));
}

void *begin_visit (const WhileExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const WhileExpr& v, void* visit_state) {
  TRACE_VISIT_OUT ();
  rchandle<sequential_expr> body = pop_nodestack ().cast<sequential_expr> ();
  expr_t cond = pop_nodestack ();
  body->push_front (new if_expr (loc, cond, create_seq (loc), new flowctl_expr (loc, flowctl_expr::BREAK)));
  nodestack.push (new while_expr (loc, body.getp()));
}

void *begin_visit (const FlowCtlStatement& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const FlowCtlStatement& v, void* visit_state) {
  TRACE_VISIT_OUT ();
  enum flowctl_expr::action a;
  switch (v.get_action ()) {
  case FlowCtlStatement::BREAK:
    a = flowctl_expr::BREAK;
    break;
  case FlowCtlStatement::CONTINUE:
    a = flowctl_expr::CONTINUE;
    break;
  default:
    ZORBA_FATAL(false, "");
  }
  nodestack.push (new flowctl_expr (loc, a));
}

/* full-text-related */
void *begin_visit (const FTAnd& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  ZORBA_ASSERT (false);
  return no_state;
}

void end_visit (const FTAnd& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTAnyallOption& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTAnyallOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTBigUnit& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTBigUnit& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTCaseOption& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTCaseOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTContainsExpr& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTContainsExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTContent& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTContent& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTDiacriticsOption& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTDiacriticsOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTDistance& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTDistance& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTIgnoreOption& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTIgnoreOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTInclExclStringLiteral& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTInclExclStringLiteral& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTInclExclStringLiteralList& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTInclExclStringLiteralList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTLanguageOption& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTLanguageOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTMatchOption& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTMatchOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const FTMatchOptionProximityList& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTMatchOptionProximityList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTMildnot& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTMildnot& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTOptionDecl& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTOptionDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTOr& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTOr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTOrderedIndicator& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTOrderedIndicator& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTProximity& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTProximity& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTRange& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTRange& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTRefOrList& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTRefOrList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTScope& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTScope& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTScoreVar& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTScoreVar& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTSelection& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTSelection& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTStemOption& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTStemOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTStopwordOption& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTStopwordOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTStringLiteralList& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTStringLiteralList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTThesaurusID& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTThesaurusID& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTThesaurusList& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTThesaurusList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTThesaurusOption& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTThesaurusOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTTimes& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTTimes& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTUnaryNot& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTUnaryNot& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTUnit& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTUnit& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTWildcardOption& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTWildcardOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTWindow& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTWindow& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTWords& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTWords& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTWordsSelection& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTWordsSelection& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTWordsValue& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTWordsValue& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const FTMatchOptionProximity& v) {
  TRACE_VISIT ();
  ZORBA_NOT_SUPPORTED ("full text");
  return no_state;
}

void end_visit (const FTMatchOptionProximity& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


// Pass-thru -- nothing to be done

void *begin_visit (const VarInDeclList& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const VarInDeclList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const VarGetsDeclList& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const VarGetsDeclList& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

void *begin_visit (const ParseErrorNode& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ParseErrorNode& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}

// End pass-thru

public:

expr_t result () {
  if (nodestack.size () != 1) {
    cout << "Error: extra nodes on translator stack:\n";
    while (! nodestack.empty ()) {
      expr_t e_h = pop_nodestack ();
#ifndef NDEBUG
      if (! Properties::instance()->traceTranslator()) {
        if (e_h != NULL)
          e_h->put (cout) << endl;
        else
          cout << "NULL" << endl;
      }
#endif
    }
    ZORBA_ASSERT (false);
  }
  ZORBA_ASSERT (tstack.size () == 0);
  if (scope_depth != 0) {
    cout << "Error: scope depth " << scope_depth << endl;
    ZORBA_ASSERT (false);
  }
  return pop_nodestack ();
}

};

expr_t translate_aux (const parsenode &root, CompilerCB* aCompilerCB, ModulesInfo *minfo, set<string> mod_stack) {
  auto_ptr<TranslatorImpl> t (new TranslatorImpl (aCompilerCB, minfo, mod_stack));
  root.accept (*t);
  rchandle<expr> result = t->result ();
  if (aCompilerCB->m_config.translate_cb != NULL)
    aCompilerCB->m_config.translate_cb (&*result, "XQuery program");
  return result;
}

expr_t translate (const parsenode &root, CompilerCB* aCompilerCB) {
  set<string> mod_stack;
  if (typeid (root) != typeid (MainModule))
    ZORBA_ERROR_LOC_DESC (XPST0003, root.get_location (), "Module declaration must not be used in a main module");
  ModulesInfo minfo (aCompilerCB->m_sctx, aCompilerCB);
  return translate_aux (root, aCompilerCB, &minfo, mod_stack);
}

} /* namespace zorba */

