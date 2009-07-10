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

#include "types/node_test.h"
#include "types/casting.h"
#include "types/typeops.h"
#include "types/typemanagerimpl.h"
#include "types/schema/schema.h"

#include "compiler/translator/translator.h"
#include "compiler/api/compilercb.h"

#include "context/static_context.h"
#include "context/static_context_consts.h"
#include "context/namespace_context.h"
#include "context/internal_uri_resolvers.h"
#include "context/standard_uri_resolvers.h"
#include "compiler/expression/expr.h"
#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/parsetree/parsenode_visitor.h"
#include "compiler/normalizer/normalizer.h"
#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/rewriter/framework/rewriter.h"
#include "compiler/api/compiler_api.h"
#include "compiler/parser/util.h"

#include "indexing/value_index.h"
#include "compiler/indexing/index_tools.h"

#include "system/globalenv.h"

#include "functions/signature.h"
#include "functions/external_function_adapters.h"

#include "store/api/item.h"
#include "store/api/update_consts.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"

#ifdef ZORBA_DEBUGGER
#include "debugger/debugger_server.h"
#endif

using namespace std;

namespace zorba {

#define LOOKUP_FN( pfx, local, arity ) (sctx_p->lookup_fn (pfx, local, arity))
#define LOOKUP_OP1( local ) (sctx_p->lookup_builtin_fn (":" local, 1))
#define LOOKUP_OP2( local ) (sctx_p->lookup_builtin_fn (":" local, 2))
#define LOOKUP_OP3( local ) (sctx_p->lookup_builtin_fn (":" local, 3))
#define LOOKUP_OPN( local ) (sctx_p->lookup_builtin_fn (":" local, VARIADIC_SIG_SIZE))
#define LOOKUP_RESOLVED_FN( ns, local, arity ) (sctx_p->lookup_resolved_fn(ns, local, arity))

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

  template<class T> T &peek_stack (stack<T> &stk) {
    ZORBA_ASSERT (! stk.empty ());
    return stk.top ();
  }

  template <typename T> T pop_stack (stack<T> &stk) {
    T x = peek_stack (stk);
    stk.pop ();
    return x;
  }

  template <typename T> T pop_stack (list<T> &stk) {
    ZORBA_ASSERT (! stk.empty ());
    T x =  stk.back ();
    stk.pop_back ();
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
  stack<ValueIndex_t>                  indexstack;

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
  expr_t ctx_item_default;
  xqtref_t ctx_item_type;
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

  bool hadBSpaceDecl, hadBUriDecl, hadConstrDecl, hadCopyNSDecl, hadDefNSDecl, hadEmptyOrdDecl, hadOrdModeDecl, hadRevalDecl;
  int xquery_version;  // 100 for 1.0, 110 for 1.1 etc

  varref_t theDotVar, theDotPosVar, theLastVar;

  // TODO: should be static
  // functions accepting . as default arg
  set<string> xquery_fns_def_dot;
  const function *op_concatenate, *op_enclosed_expr, *op_or, *fn_data,
    * ctx_decl, *ctx_set, *ctx_get, *ctx_exists;

  set<string> zorba_predef_mod_ns;
  
  // format of strings: type_char + qname_internal_key
  // where type_char is F or V
  stack<string> global_decl_stack;
  list<string> global_var_decls;
  list<function *> global_fn_decls, fn_decl_stack;
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
    hadRevalDecl (false),
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
    ctx_decl = ctx_set = ctx_get = ctx_exists = NULL;
    zorba_predef_mod_ns.insert (ZORBA_FN_NS);
    zorba_predef_mod_ns.insert (ZORBA_MATH_FN_NS);
    zorba_predef_mod_ns.insert (ZORBA_REST_FN_NS);
    zorba_predef_mod_ns.insert (ZORBA_NODEREF_FN_NS);
    zorba_predef_mod_ns.insert (ZORBA_COLLECTION_FN_NS);
    zorba_predef_mod_ns.insert (ZORBA_ALEXIS_FN_NS);
#ifdef ZORBA_WITH_EMAIL
    zorba_predef_mod_ns.insert (ZORBA_EMAIL_FN_NS);
#endif
    zorba_predef_mod_ns.insert (ZORBA_JSON_FN_NS);
    zorba_predef_mod_ns.insert (ZORBA_JSON_ML_FN_NS);
    zorba_predef_mod_ns.insert (ZORBA_OPEXTENSIONS_NS);
    zorba_predef_mod_ns.insert (ZORBA_FOP_FN_NS);

    sctx_p->get_global_bindings (theGlobalVars);
    for (list<global_binding>::iterator i = theGlobalVars.begin ();
         i != theGlobalVars.end (); i++)
    {
      varref_t ve = (*i).first;
      global_var_decls.push_back (static_context::qname_internal_key (ve->get_varname ()));
    }

    ctx_item_type = GENV_TYPESYSTEM.ITEM_TYPE_ONE;
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


expr_t peek_nodestk_or_null () {
  return (nodestack.empty ()) ? expr_t (NULL) : peek_stack (nodestack);
}


xqtref_t pop_tstack()
{
  return pop_stack (tstack); 
}


/*******************************************************************************
  Create a type representing an ElementTest, where:

	ElementTest ::= "element" "(" (ElementNameOrWildcard ("," TypeName "?"?)?)? ")"
********************************************************************************/
xqtref_t create_element_test(
    const QueryLoc& loc,
    QName* elemName,
    TypeName* typeName,
    bool nillable)
{
  store::Item_t ename;
  store::Item_t tname;
  rchandle<NodeTest> nodeTest;
  xqtref_t contentType;

  if (elemName != NULL) 
  {
    ename = sctx_p->lookup_elem_qname(elemName->get_qname(), loc);
  }
  
  if (typeName != NULL) 
  {
    tname = sctx_p->lookup_elem_qname(typeName->get_name()->get_qname(), loc);
    
    contentType = CTXTS->create_named_type(tname, TypeConstants::QUANT_ONE);
  }
  
  return CTXTS->create_node_type(store::StoreConsts::elementNode,
                                 ename,
                                 contentType,
                                 TypeConstants::QUANT_ONE,
                                 nillable);
}


varref_t create_var(
    const QueryLoc& loc,
    store::Item_t qname,
    var_expr::var_kind kind,
    xqtref_t type = NULL) 
{
  varref_t e = new var_expr(loc, kind, qname, global_decl_stack.empty ());

  if (kind == var_expr::pos_var ||
      kind == var_expr::count_var ||
      kind == var_expr::wincond_out_pos_var ||
      kind == var_expr::wincond_in_pos_var)
  {
    type = GENV_TYPESYSTEM.POSITIVE_INTEGER_TYPE_ONE;
  }

  e->set_type (type);
  return e;
}

  
varref_t create_var(
    const QueryLoc& loc,
    string varname,
    var_expr::var_kind kind, 
    xqtref_t type = NULL) 
{
  store::Item_t qname = sctx_p->lookup_var_qname (varname, loc);
  return create_var (loc, qname, kind, type);
}
  

void bind_var (varref_t e, static_context *sctx) 
{
  assert (sctx != NULL);
  store::Item_t qname = e->get_varname ();
  if (! sctx->bind_var (qname, e.getp ()))
  {
    if(e->get_kind () == var_expr::let_var)
    {
      ZORBA_ERROR_LOC_PARAM (XQST0039, e->get_loc (), qname->getStringValue (), "");
    }
    else
    {
      ZORBA_ERROR_LOC_PARAM (XQST0049, e->get_loc (), qname->getStringValue (), "");
    }
  }
}


varref_t bind_var (
    const QueryLoc& loc,
    string varname,
    var_expr::var_kind kind,
    xqtref_t type = NULL) 
{
  varref_t e = create_var (loc, varname, kind, type);
  bind_var (e, sctx_p);
  return e;
}


varref_t bind_var (
    const QueryLoc& loc,
    store::Item_t varname,
    var_expr::var_kind kind,
    xqtref_t type = NULL) 
{
  varref_t e = create_var (loc, varname, kind, type);
  bind_var (e, sctx_p);
  return e;
}


varref_t bind_var_and_push (
    const QueryLoc& loc,
    store::Item_t varname,
    var_expr::var_kind kind,
    xqtref_t type = NULL) 
{
  varref_t e = bind_var (loc, varname, kind, type);
  nodestack.push (&*e);
  return e;
}


varref_t bind_var_and_push (
    const QueryLoc& loc,
    string varname,
    var_expr::var_kind kind,
    xqtref_t type = NULL) 
{
  return bind_var_and_push (loc, sctx_p->lookup_var_qname (varname, loc), kind, type);
}


void bind_udf (store::Item_t qname, function *f, int nargs, static_context *sctx, const QueryLoc& loc) {
  if (! sctx->bind_fn (qname, f, nargs))
    ZORBA_ERROR_LOC_PARAM (XQST0034, loc, qname->getStringValue (), loc.getFilenameBegin());
}


void bind_udf (store::Item_t qname, function *f, int nargs, const QueryLoc& loc) {
  bind_udf (qname, f, nargs, sctx_p, loc);
  bind_udf (qname, f, nargs, minfo->globals.get (), loc);
  // bind the udf also in the sctx that is used
  // for importing modules
  if (export_sctx != NULL) {
    // set the static context in which the function is compiled
    user_function* user_f = dynamic_cast<user_function*>(f);
    assert(user_f);
    user_f->set_context(sctx_p);
    bind_udf (qname, f, nargs, export_sctx, loc);
  }
}


fo_expr *create_seq (const QueryLoc& loc) {
  return fo_expr::create_seq (loc);
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


/*******************************************************************************
  Lookup variable by qname (expanded or not). Search starts from the "current"
  ctx and moves upwards the ancestor path until the first instance (if any) of
  the variable is found.

  The first method raises error if var not found, the other 2 methods return NULL.
********************************************************************************/
varref_t lookup_ctx_var (xqp_string name, const QueryLoc &loc) 
{
  expr *ve = sctx_p->lookup_var (name);
  if (ve != NULL)
    return (var_expr *) ve;
  ZORBA_ERROR_LOC_PARAM (XPDY0002, loc, name, "");
}


var_expr *lookup_var (string varname) 
{
    return static_cast<var_expr *> (sctx_p->lookup_var (varname));
}


var_expr *lookup_var (store::Item_t varname) 
{
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
      switch(lType2) {
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
      break;
    case SIMPLE_EXPR:
      switch(lType2) {
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
      break;
    case UPDATE_EXPR:
      switch(lType2) {
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
      break;
    default:
      ZORBA_ASSERT(false);
    }
    return SIMPLE_EXPR;
  }
  
  StaticContextConsts::xquery_version_t parse_xquery_version(const VersionDecl* vh) 
  {
    if (vh == NULL)
      return StaticContextConsts::xquery_version_1_0; // TODO: the spec says the default should be 1.1 for a 1.1 processor

    string ver = vh->get_version ();
    if (ver == "1.0")
    {
      xquery_version = StaticContextConsts::xquery_version_1_0;
      return StaticContextConsts::xquery_version_1_0;
    }
    else if (ver == "1.1")
    {
      xquery_version = StaticContextConsts::xquery_version_1_1;
      return StaticContextConsts::xquery_version_1_1;
    }
    else
      return StaticContextConsts::xquery_version_unknown;
  }
  
expr_t wrap_in_atomization (expr_t e) {
  return new fo_expr (e->get_loc (), CACHED (fn_data, LOOKUP_FN ("fn", "data", 1)), e);
}
  
void declare_var (const global_binding &b, std::vector<expr_t> &stmts) {
  CACHED (ctx_decl, LOOKUP_OP1 ("ctxvar-declare"));
  CACHED (ctx_set, LOOKUP_OP2 ("ctxvar-assign"));

  varref_t var = b.first;
  xqtref_t var_type = var->get_type ();
  expr_t expr = b.second;
  xqpStringStore dot (".");
  expr_t qname_expr =
    new const_expr (var->get_loc(), var->get_varname ()->getStringValue ()->equals (&dot) ? "." : dynamic_context::var_key (&*var));

  expr_t decl_expr = new fo_expr (var->get_loc(), ctx_decl, qname_expr->clone ());
  if (expr != NULL) {
    if (expr->is_updating())
      ZORBA_ERROR_LOC(XUST0001, expr->get_loc());

    expr = new fo_expr (var->get_loc(),
                        ctx_set, qname_expr->clone (), expr);
    expr = new sequential_expr (var->get_loc (), decl_expr, expr);
    if (b.is_extern ()) {
      CACHED (ctx_exists, LOOKUP_OP1 ("ctxvar-exists"));
      expr_t exists_expr =
        expr_t (new fo_expr (var->get_loc (), ctx_exists, qname_expr->clone ()));
      expr = new if_expr (var->get_loc (), exists_expr,
                          expr_t (create_seq (var->get_loc ())), expr);
    }
    stmts.push_back (expr);
  } else {  // no init expr
    if (! b.is_extern ())
      stmts.push_back (decl_expr);
  }
  if (var_type != NULL && (b.is_extern () || b.second != NULL)) {
    // check type for vars that are external or have an init expr
    CACHED (ctx_get, LOOKUP_OP1 ("ctxvariable"));
    expr_t get = new fo_expr (var->get_loc (), ctx_get, qname_expr->clone ());
    stmts.push_back (new treat_expr (var->get_loc (), get, var->get_type (), XPTY0004));
  }
}


void add_single_global_assign (const global_binding &b) 
{
  declare_var (b, minfo->init_exprs);
}


expr_t wrap_in_globalvar_assign(expr_t e) 
{
  for (list<global_binding>::iterator i = theGlobalVars.begin ();
      i != theGlobalVars.end ();
      i++)
  {
    add_single_global_assign (*i);
  }

  if (! minfo->init_exprs.empty ()) {
    e = new sequential_expr (e->get_loc(), minfo->init_exprs, e);
  }

  return e;
}


/*******************************************************************************
  Create a LET clause for the given LET variable "lv", with the given expr "e" as
  its defining expression.
********************************************************************************/
let_clause_t wrap_in_letclause(expr_t e, varref_t lv) 
{
  assert (lv->get_kind () == var_expr::let_var);
  return new let_clause(e->get_loc(), lv, e.getp());
}


let_clause_t wrap_in_letclause(expr_t e, const QueryLoc& loc, string name) 
{
  return wrap_in_letclause(e, bind_var(loc, name, var_expr::let_var));
}


let_clause_t wrap_in_letclause(expr_t e) 
{
  return wrap_in_letclause(e, tempvar(e->get_loc(), var_expr::let_var));
}


/*******************************************************************************
  Create a FOR clause for the given FOR variable "fv" and its associated POS var
  "pv" (pv may be NULL). Use the given expr "e" as the defining expr for "fv". 
********************************************************************************/
for_clause_t wrap_in_forclause(expr_t e, varref_t fv, varref_t pv) 
{
  assert (fv->get_kind () == var_expr::for_var);
  if (pv != NULL)
    assert (pv->get_kind() == var_expr::pos_var);

  return new for_clause(e->get_loc(), fv, e, pv);
}


for_clause_t wrap_in_forclause(
    expr_t expr,
    const QueryLoc& loc,
    string fv_name,
    string pv_name)
{
  return wrap_in_forclause(expr,
                           bind_var(loc, fv_name, var_expr::for_var),
                           bind_var(loc, pv_name, var_expr::pos_var));
}


for_clause_t wrap_in_forclause(expr_t expr, bool add_posvar) 
{
  varref_t fv = tempvar(expr->get_loc(), var_expr::for_var);

  varref_t pv = (add_posvar ? tempvar(expr->get_loc(), var_expr::pos_var) : 
                                varref_t (NULL));
  return wrap_in_forclause(expr, fv, pv);
}


/*******************************************************************************
  Create a flwor expr that uses the given expr as its input. In particular, if
  withContextSize is true, the following flwor is built:

    let $$temp := inputExpr
    let $$last-idx := count($$temp)
    for $$dot at $$pos in $$temp
    .....

  if withContextSize is false, the following flwor is built:

    for $$dot at $$pos in inputExpr
    .....
********************************************************************************/
rchandle<flwor_expr> wrap_expr_in_flwor(expr* inputExpr, bool withContextSize)
{
  const QueryLoc& loc = inputExpr->get_loc();

  push_scope();

  rchandle<flwor_expr> flworExpr = new flwor_expr(loc, false);

  if (withContextSize) 
  {
    // create a LET var equal to the seq returned by the input epxr
    let_clause_t lcInputSeq = wrap_in_letclause(inputExpr);

    // compute the size of the input seq
    rchandle<fo_expr> countExpr = new fo_expr(loc, LOOKUP_FN("fn", "count", 1));
    countExpr->add(lcInputSeq->get_var());

    let_clause_t lcLast = wrap_in_letclause(countExpr.getp(),
                                            loc,
                                            LAST_IDX_VARNAME);

    // Iterate over the input seq
    for_clause_t fcDot = wrap_in_forclause(lcInputSeq->get_var(),
                                           loc,
                                           DOT_VARNAME,
                                           DOT_POS_VARNAME);
    flworExpr->add_clause(lcInputSeq);
    flworExpr->add_clause(lcLast);
    flworExpr->add_clause(fcDot);
  }
  else
  {
    // Iterate over the input seq
    for_clause_t fcDot = wrap_in_forclause(inputExpr,
                                           loc,
                                           DOT_VARNAME,
                                           DOT_POS_VARNAME);
    flworExpr->add_clause(fcDot);
  }

  return flworExpr;
}


/*******************************************************************************

********************************************************************************/
expr_t wrap_in_dos_and_dupelim(expr_t expr, bool atomics, bool reverse = false) 
{
  std::ostringstream funcName;

  funcName << ":sort-distinct-nodes";

  if (reverse)
    funcName << "-desc";
  else
    funcName << "-asc";

  if (atomics)
    funcName << "-or-atomics";

  rchandle<fo_expr> dos;
  dos = new fo_expr(expr->get_loc(), sctx_p->lookup_builtin_fn(funcName.str(), 1));
  dos->add(expr);
  return &*dos;
}


/*******************************************************************************
  Collect the var_eprs for all variables that (a) are defined by some clause
  in a given range of clauses, and (b) are in-scope when this method is called. 
********************************************************************************/
void collect_flwor_vars (
    const FLWORExpr& e,
    set<const var_expr *>& vars,
    const FLWORClause* start,
    const FLWORClause* end,
    bool inclusive) 
{
  const FLWORClauseList& clauses = *e.get_clause_list();

  // Find the ordinal number of the "end" clause, or the "end-1" clause, if
  // inclusive is false.
  int i;
  for (i = clauses.size () - 1; i >= 0; --i) 
  {
    if (&*clauses [i] == end) 
    {
      if (! inclusive) --i;
      break;
    }
  }
  assert (i >= 0);

  // Look for variables in reverse order (starting from the last clause).
  for (;; i--) 
  {
    const FLWORClause& c = *clauses[i];

    if (typeid (c) == typeid (ForClause)) 
    {
      const VarInDeclList &lV = *(static_cast<const ForClause *>(&c)->get_vardecl_list());
      for (int j =  lV.size() - 1; j >= 0; --j) 
      {
        vars.insert (lookup_var (lV[j]->get_varname()));
      }
    }
    else if (typeid (c) == typeid (LetClause)) 
    {
      const VarGetsDeclList &lV = *(static_cast<const LetClause *>(&c)->get_vardecl_list());
      for (int j =  lV.size() - 1; j >= 0; --j) 
      {
        vars.insert(lookup_var(lV[j]->get_varname()));
      }
    }
    else if (typeid(c) == typeid(WindowClause)) 
    {
      const WindowClause &wc = *static_cast<const WindowClause *>(&c);
      vars.insert (lookup_var (wc.get_var ()->get_varname()));
      for (int j = 1; j >= 0; j--) 
      {
        const FLWORWinCond *cond = &*wc[j];
        if (cond != NULL) 
        {
          const WindowVars *wv = &*cond->get_winvars ();
          if (wv != NULL) 
          {
            if (! wv->get_next ().empty ())
              vars.insert (lookup_var (wv->get_next ()));
            if (! wv->get_prev ().empty ())
              vars.insert (lookup_var (wv->get_prev ()));
            if (! wv->get_curr ().empty ())
              vars.insert (lookup_var (wv->get_curr ()));
            if (wv->get_posvar () != NULL)
              vars.insert(lookup_var(wv->get_posvar ()->get_varname()));
          }
        }
      }
    }
    else if (typeid (c) == typeid (CountClause)) 
    {
      vars.insert(lookup_var(static_cast<const CountClause *>(&c)->get_varname()));
    }
    else if (typeid (c) == typeid (OrderByClause))
    {
      // Nothing to do; orderby does not define any vars.
    }
    else if (typeid (c) == typeid (GroupByClause))
    {
      // Group-by redefines ALL previous variables, but the GroupByClause lists
      // only the grouping vars. So, to find the var_exprs for the vars defined
      // by the GroupByClause, we exploit the fact that the redefined var_exprs
      // "shadow" their corresponding var_exprs, that is, each redefined var_expr
      // oX appears in the static context after its corresponding var_expr iX and
      // both iX and oX  use the same var name. So, we can collect all the oX 
      // var_exprs by going through all the clauses that appear before this GB
      // and looking up, by name, all the vars defined by those clauses.
      collect_flwor_vars (e, vars, &*clauses [0], &c, false);
      break;
    }

    if (&c == start)
      break;
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
  sctx_p->set_global_bindings (theGlobalVars);
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
  push_scope ();
  return no_state;
}

void end_visit (const BlockBody& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  vector<expr_t> stmts;  // constructed in reverse... maybe not the best choice

  rchandle<VFO_DeclList> decls = v.get_decls ();
  for (int i = 0; i < v.size(); i++)
    stmts.push_back (pop_nodestack ());
  if (decls != NULL) {
    for (int i = decls->size () - 1; i >= 0; --i) {
      expr_t val = pop_nodestack ();
      varref_t ve = pop_nodestack ().cast<var_expr> ();
      global_binding b (ve, val, false);
      vector<expr_t> stmts1;
      declare_var (b, stmts1);
      reverse (stmts1.begin (), stmts1.end ());
      stmts.insert (stmts.end (), stmts1.begin (), stmts1.end ());
    }
  }
  reverse (stmts.begin (), stmts.end ());
  nodestack.push (new sequential_expr (loc, stmts));
  pop_scope ();
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
                                     sctx_p->lookup_qname("", qname->get_qname(), qname->get_location()));
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
                              sctx_p->lookup_qname("", constQName->get_qname(), constQName->get_location()));
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


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  FLWOR and Genralized FLWOR Expressions                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

  FLWORExpr ::= InitialClause FLWORClauseList? ReturnClause

  InitialClause ::= ForClause | LetClause | WindowClause

********************************************************************************/
void *begin_visit (const FLWORExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const FLWORExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  if (xquery_version <= StaticContextConsts::xquery_version_1_0 && v.is_non_10())
    ZORBA_ERROR_LOC (XPST0003, loc);

  const FLWORClauseList& clauses = *v.get_clause_list();

  vector <rchandle<flwor_clause> > eclauses;

  rchandle<flwor_expr> flwor = new flwor_expr(loc, v.is_general());

  //
  // Process return clause
  //
  expr_t retExpr = pop_nodestack();
  
#ifdef ZORBA_DEBUGGER
  if ( compilerCB->m_debugger != 0) 
  {
    const QueryLoc& return_location = v.get_return_location(); 
    rchandle<debugger_expr> lDebuggerExpr = new debugger_expr(return_location,
                                                              retExpr,
                                                              theScopedVariables,
                                                              theGlobalVars);
   retExpr = lDebuggerExpr;
  }
#endif

  flwor->set_return_expr(retExpr);

  for (int i = clauses.size() - 1; i >= 0; i--) 
  {
    const FLWORClause& c = *clauses[i];

    vector<rchandle<var_expr> > varExprs;
    vector<rchandle<var_expr> > posVarExprs; // mirrors varExprs vector
    vector<rchandle<expr> > domainExprs;     // mirrors varExprs vector

    //
    // Process FOR clause
    //
    if (typeid(c) == typeid(ForClause)) 
    {
      const ForClause& flc = *static_cast<const ForClause *> (&c);
      if (xquery_version <= StaticContextConsts::xquery_version_1_0 && flc.is_outer())
        ZORBA_ERROR_LOC(XPST0003, loc);

      int numVars = flc.get_decl_count();
      VarInDeclList* decl_list = &*flc.get_vardecl_list();

      for (int j = numVars - 1; j >= 0; --j) 
      {
        var_expr_t ve;
        ve = pop_nodestack_var();
        ve->set_kind(var_expr::for_var);
        varExprs.push_back(ve);

        if ((*decl_list)[j]->get_posvar() == NULL)
        {
          posVarExprs.push_back(NULL);
        }
        else 
        {
          var_expr_t pve = pop_nodestack_var();
          pve->set_kind(var_expr::pos_var);
          posVarExprs.push_back(pve);
        }

        expr_t domainExpr = pop_nodestack();
        if (domainExpr->is_updating())
          ZORBA_ERROR_LOC(XUST0001, loc);
        domainExprs.push_back(domainExpr);

        pop_scope();
      }

      for (int j = 0; j < numVars; j++) 
      {
        expr_t domainExpr = domainExprs[j];
#ifdef ZORBA_DEBUGGER
        if(compilerCB->m_debugger != 0)
        {
          push_scope();
          for(int k = numVars; k > j; k--)
          {
            theScopedVariables.push_back(varExprs[k-1]);
          }

          domainExpr = new debugger_expr(domainExprs[j]->get_loc(),
                                         domainExpr,
                                         theScopedVariables,
                                         theGlobalVars,
                                         true);
          pop_scope();
        }
#endif
        for_clause* eflc = new for_clause(c.get_location(),
                                          varExprs[j],
                                          domainExpr,
                                          posVarExprs[j]);
        eflc->set_outer(flc.is_outer());

        eclauses.push_back(eflc);

#ifdef ZORBA_DEBUGGER
        if(compilerCB->m_debugger != 0)
        {
          theScopedVariables.push_back(varExprs[j]);
          if(posVarExprs[j] != 0)
          {
            theScopedVariables.push_back(posVarExprs[j]);
          }
          eflc->set_bound_variables(theScopedVariables);
          eflc->set_global_variables(theGlobalVars);
        }
#endif
      }
    }

    //
    // Process LET clause
    //
    else if (typeid (c) == typeid (LetClause)) 
    {
      const LetClause& flc = *static_cast<const LetClause *> (&c);
      int numVars = flc.get_decl_count();

      for (int j = 0; j < numVars; j++) 
      {
        var_expr_t ve = pop_nodestack_var();
        ve->set_kind(var_expr::let_var);
        varExprs.push_back(ve);

        expr_t domainExpr = pop_nodestack();
        if (domainExpr->is_updating())
          ZORBA_ERROR_LOC(XUST0001, loc);
        domainExprs.push_back(domainExpr);

        pop_scope();
      }

      for (int j = 0; j < numVars; j++)
      {
        expr_t domainExpr = domainExprs[j];
#ifdef ZORBA_DEBUGGER
        if(compilerCB->m_debugger != 0)
        {
          push_scope();
          for(int k = numVars; k-1 > j; k--)
          {
            theScopedVariables.push_back(varExprs[k-1]);
          }
          domainExpr = new debugger_expr(domainExprs[j]->get_loc(),
                                         domainExpr,
                                         theScopedVariables,
                                         theGlobalVars);
          pop_scope();
        }
#endif
        let_clause* eflc = new let_clause(c.get_location(),
                                          varExprs[j],
                                          domainExpr);
        eclauses.push_back(eflc);
      }
    }

    //
    // Process WINDOW clause
    //
    else if (typeid (c) == typeid (WindowClause)) 
    {
      pop_scope(2);  // var decl + output window condition vars

      const WindowClause& wc = *static_cast<const WindowClause *>(&c);

      window_clause::window_t winKind =
         (wc.get_wintype() == WindowClause::tumbling_window ?
          window_clause::tumbling_window :
          window_clause::sliding_window);
      
      flwor_wincond_t econds[2];
      flwor_wincond::vars outputCondVarExprs[2];
      flwor_wincond::vars inputCondVarExprs[2];

      for (int i = 1; i >= 0; i--) 
      {
        rchandle<FLWORWinCond> cond = wc[i];
        if (cond != NULL) 
        {
          rchandle<WindowVars> vars = cond->get_winvars();
          pop_wincond_vars(vars, outputCondVarExprs[i]);
        }
      }

      varref_t windowVarExpr = pop_nodestack_var();

      expr_t windowDomainExpr = pop_nodestack();

      for (int i = 1; i >= 0; i--) 
      {
        rchandle<FLWORWinCond> cond = wc[i];
        if (cond != NULL) 
        {
          expr_t condExpr = pop_nodestack();

          rchandle<WindowVars> vars = cond->get_winvars();
          pop_wincond_vars(vars, inputCondVarExprs[i]);

          econds[i] = new flwor_wincond(cond->is_only(),
                                        inputCondVarExprs[i],
                                        outputCondVarExprs[i],
                                        condExpr);
        }
      }

      window_clause* flwc = new window_clause(c.get_location(),
                                              winKind,
                                              windowVarExpr,
                                              windowDomainExpr,
                                              econds[0],
                                              econds[1]);
      eclauses.push_back(flwc);
    }

    //
    // Process WHERE clause
    //
    else if (typeid (c) == typeid (WhereClause)) 
    {
      expr_t whereExpr = pop_nodestack();
      if (whereExpr->is_updating())
        ZORBA_ERROR_LOC(XUST0001, loc);

      eclauses.push_back(new where_clause(c.get_location(), whereExpr));
    }

    //
    // Process GROUPBY clause
    //
    else if (typeid (c) == typeid (GroupByClause))
    {
      const GroupByClause* groupByClause = static_cast<const GroupByClause *>(&c);
      const GroupSpecList& groupSpecs = *groupByClause->get_spec_list();
      size_t numGroupSpecs = groupSpecs.size();

      vector<string> collations;
      group_clause::rebind_list_t grouping_rebind;
      group_clause::rebind_list_t nongrouping_rebind;
      varref_t input_var;
      varref_t output_var;

      for (int i = numGroupSpecs - 1; i >= 0; i--) 
      {
        const GroupSpec& groupSpec = *groupSpecs[i];

        output_var = pop_nodestack_var();
        input_var = pop_nodestack_var();

        if (groupSpec.group_coll_spec() != NULL)
          collations.push_back(groupSpec.group_coll_spec()->get_uri());
        else
          collations.push_back ("");

        wrapper_expr_t input_wrapper;
        input_wrapper = new wrapper_expr(c.get_location(),
                                         static_cast<expr*>(input_var.getp()));

        grouping_rebind.push_back(pair<wrapper_expr_t, varref_t>(input_wrapper,
                                                                 output_var));

        pop_scope();
      }
      
      reverse(collations.begin(), collations.end());
      reverse(grouping_rebind.begin(), grouping_rebind.end());

      while (NULL != (output_var = pop_nodestack_var())) 
      {
        input_var = pop_nodestack_var();

        wrapper_expr_t input_wrapper;
        input_wrapper = new wrapper_expr(c.get_location(),
                                         static_cast<expr*>(input_var.getp()));

        nongrouping_rebind.push_back(pair<wrapper_expr_t, varref_t>(input_wrapper,
                                                                    output_var));

        pop_scope();
      }
      
      eclauses.push_back(new group_clause(c.get_location(),
                                          grouping_rebind,
                                          nongrouping_rebind,
                                          collations));
    }

    //
    // Process ORDERBY clause
    //
    else if (typeid (c) == typeid (OrderByClause)) 
    {
      const OrderByClause& orderByClause = static_cast<const OrderByClause&>(c);
      const OrderSpecList& orderSpecs = *orderByClause.get_spec_list();
      unsigned numOrderSpecs = orderSpecs.size();

      std::vector<order_modifier> modifiers(numOrderSpecs);
      std::vector<expr_t> orderExprs(numOrderSpecs);

      for (int i = numOrderSpecs - 1; i >= 0; --i) 
      {
        OrderSpec* spec = orderSpecs[i];
        OrderModifier* mod = spec->get_modifier();

        ParseConstants::dir_spec_t dirSpec = ParseConstants::dir_ascending;
        if (mod && mod->get_dir_spec() != NULL)
          dirSpec = mod->get_dir_spec()->get_dir_spec();

        StaticContextConsts::order_empty_mode_t emptySpec = sctx_p->order_empty_mode();
        if (mod && mod->get_empty_spec() != NULL)
          emptySpec = mod->get_empty_spec()->get_empty_order_spec();

        string collation = sctx_p->default_collation_uri();
        if (mod && mod->get_collation_spec() != NULL)
          collation = mod->get_collation_spec()->get_uri();
        if (! sctx_p->has_collation_uri(collation))
          ZORBA_ERROR_LOC(XQST0076, loc);

        expr_t orderExpr = pop_nodestack();
        if (orderExpr->is_updating())
          ZORBA_ERROR_LOC(XUST0001, loc);

        modifiers[i] = order_modifier(dirSpec, emptySpec, collation);
        orderExprs[i] = orderExpr;
      }

      rchandle<orderby_clause> obgc = new orderby_clause(c.get_location(),
                                                         orderByClause.get_stable_bit(),
                                                         modifiers,
                                                         orderExprs);
      eclauses.push_back(obgc.cast<flwor_clause>());
    }

    //
    // Process COUNT clause
    //
    else if (typeid (c) == typeid (CountClause)) 
    {
      eclauses.push_back(new count_clause(c.get_location(), pop_nodestack_var()));
    }
  }

  for (int i = eclauses.size() - 1; i >= 0; --i)
    flwor->add_clause(eclauses[i]);

  nodestack.push(&*flwor);
}


void pop_wincond_vars(rchandle<WindowVars> node, flwor_wincond::vars& vars) 
{
  if (node != NULL) 
  {
    if (! node->get_next().empty())
      vars.next = pop_nodestack_var();

    if (! node->get_prev().empty())
      vars.prev = pop_nodestack_var();

    if (! node->get_curr().empty())
      vars.curr = pop_nodestack_var();

    if (node->get_posvar() != NULL)
      vars.posvar = pop_nodestack_var();
  }
}


/*******************************************************************************
  - For the Generazed FLWOR:

  FLWORClauseList ::= FLWORClause | FLWORClause  FLWORClauseList

  - For the traditional FLWOR:

  FLWORClauseList ::= (ForClause | LetClause)+ 
                      WhereCluase?
                      GroupByClause?
                      OrderByClause?
********************************************************************************/
void *begin_visit (const FLWORClauseList& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const FLWORClauseList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  ForClause ::= "outer"? "for" "$"  VarInDeclList
********************************************************************************/
void *begin_visit (const ForClause& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const ForClause& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  VarInDeclList ::= VarInDecl | VarInDeclList  ","  "$"  VarInDecl
********************************************************************************/
void *begin_visit (const VarInDeclList& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const VarInDeclList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  VarInDecl ::= VarName TypeDeclaration? PositionalVar? FTScoreVar? "in" ExprSingle
********************************************************************************/
void *begin_visit (const VarInDecl& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const VarInDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  push_scope();

  xqp_string varname = v.get_varname();
  store::Item_t var_qname = sctx_p->lookup_var_qname(varname, loc);

  const PositionalVar* pv = v.get_posvar();
  if (pv != NULL) 
  {
    xqp_string pvarname = pv->get_varname();
    store::Item_t pvar_qname = sctx_p->lookup_var_qname(pvarname, loc);
    if (pvar_qname->equals(var_qname.getp()))
      ZORBA_ERROR_LOC (XQST0089, loc);

    bind_var_and_push(pv->get_location (), pvar_qname, var_expr::pos_var);

#ifdef ZORBA_DEBUGGER
    theScopedVariables.push_back(nodestack.top().dyn_cast<var_expr>());
#endif
  }

  xqtref_t type = v.get_typedecl () == NULL ? NULL : pop_tstack ();

  bind_var_and_push(loc, var_qname, var_expr::for_var, type);

#ifdef ZORBA_DEBUGGER
  theScopedVariables.push_back(nodestack.top().dyn_cast<var_expr>());
#endif
}


/*******************************************************************************
  PositionalVar ::= "at" "$"  VarName
********************************************************************************/
void *begin_visit (const PositionalVar& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const PositionalVar& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  LetClause ::= "let" "$" VarGetsDeclList | "let" "score $" VarGetsDeclList
********************************************************************************/
void *begin_visit (const LetClause& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const LetClause& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  VarGetsDeclList ::= VarGetsDecl | VarGetsDeclList ","  "$"  VarGetsDecl
********************************************************************************/
void *begin_visit (const VarGetsDeclList& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const VarGetsDeclList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  VarGetsDecl	::= VarName TypeDeclaration? ":=" ExprSingle |
                  VarName TypeDeclaration? FTScoreVar ":=" ExprSingle

  Note: This ast node also represents EVAL external vars
********************************************************************************/
void *begin_visit (const VarGetsDecl& v) 
{
  TRACE_VISIT();
  return no_state;
}

void end_visit (const VarGetsDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  push_scope();

  xqtref_t type = v.get_typedecl() == NULL ? NULL : pop_tstack ();

  if (v.get_kind() == VarGetsDecl::let_var)
    bind_var_and_push(loc, v.get_varname(), var_expr::let_var, type);
  else
    nodestack.push(&*create_var (loc, v.get_varname(), var_expr::let_var, type));

#ifdef ZORBA_DEBUGGER
  theScopedVariables.push_back(nodestack.top().dyn_cast<var_expr>());
#endif
}


/*******************************************************************************
  WindowClause ::= "for" (TumblingWindowClause | SlidingWindowClause)

  TumblingWindowClause ::= "tumbling" "window" WindowVarDecl
                           WindowStartCondition WindowEndCondition?

  SlidingWindowClause ::= "sliding" "window" WindowVarDecl
                          WindowStartCondition WindowEndCondition

  Note: The accept() method of WindowClause translates the window conditions
        first and then it translates the condition variable.
********************************************************************************/
void *begin_visit(const WindowClause& v) 
{
  TRACE_VISIT();

  if (xquery_version <= StaticContextConsts::xquery_version_1_0)
    ZORBA_ERROR_LOC (XPST0003, loc);

  // Create scope for the input window-condition vars. These vars are visible
  // inside the WindowStartCondition and WindowEndCondition only, so the scope
  // created here will be destroyed as soon as we start processing the 
  // WindowVarDecl (see below).
  push_scope();

  return no_state;
}

void end_visit(const WindowClause& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  // Create scope for the output window-condition vars. 
  push_scope();

  // Create var_exprs for output window-condition vars and push them to the
  // nodestack.
  rchandle<FLWORWinCond> cond;
  for (int i = 0; i < 2; i++)
  {
    if (NULL != (cond = v[i])) 
    {
      rchandle<WindowVars> vars = cond->get_winvars();
      if (vars != NULL)
        bind_winvars(*vars, false);
    }
  }
}


/*******************************************************************************
  WindowVarDecl ::= "$" VarName TypeDeclaration? "in"  ExprSingle
********************************************************************************/
void *begin_visit(const WindowVarDecl& v)
{
  TRACE_VISIT();

  // Done with input window condition vars.
  pop_scope();

  return no_state;
}

void end_visit (const WindowVarDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  xqtref_t type = v.get_typedecl () == NULL ? NULL : pop_tstack ();

  push_scope();

  bind_var_and_push(loc, v.get_varname(), var_expr::win_var, type);
}


/*******************************************************************************
  WindowStartCondition ::= "start" WindowVars "when" ExprSingle

  WindowEndCondition ::= "only"? "end" WindowVars "when" ExprSingle
********************************************************************************/
void *begin_visit(const FLWORWinCond& v) 
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const FLWORWinCond& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  WindowVars ::= ("$" CurrentItem)? PositionalVar?
                 ("previous" "$" PreviousItem)?
                 ("next" "$" NextItem)?
********************************************************************************/
void *begin_visit(const WindowVars& v) 
{
  TRACE_VISIT();
  return no_state;
}


void end_visit(const WindowVars& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  // Create var_exprs for input window-condition vars and push them to the
  // nodestack.
  bind_winvars(v, true);
}


void bind_winvars(const WindowVars& v, bool input) 
{
  const QueryLoc& loc = v.get_location();

  enum var_expr::var_kind varKind = (input ?
                                     var_expr::wincond_in_var :
                                     var_expr::wincond_out_var);

  enum var_expr::var_kind pvarKind = (input ?
                                      var_expr::wincond_in_pos_var :
                                      var_expr::wincond_out_pos_var);

  rchandle<PositionalVar> pv = v.get_posvar();
  if (pv != NULL)
  {
    bind_var_and_push(pv->get_location(), pv->get_varname(), pvarKind);
  }

  if (! v.get_curr().empty())
    bind_var_and_push(loc, v.get_curr(), varKind);

  if (! v.get_prev().empty())
    bind_var_and_push(loc, v.get_prev(), varKind);

  if (! v.get_next().empty())
    bind_var_and_push(loc, v.get_next(), varKind);
}



/*******************************************************************************
  GroupByClause ::= "group" "by" GroupingSpecList

  On return from the end_visit() method, the nodestack contains a pair of 
  var_exprs for each var X defined by any clauses appearing before this
  GroupByClause. The first var_expr in the pair corresponds to the input-stream
  var X, and the second var_expr corresponds to the associated output-stream
  var. The pairs for the grouping vars appear first (i.e., at the top of the
  odestack), followed by the pairs for the non-grouping vars.
********************************************************************************/
void *begin_visit(const GroupByClause& v) 
{
  TRACE_VISIT ();

  nodestack.push(NULL);

  const FLWORExpr& flwor = *v.get_flwor ();
  const FLWORClauseList& clauses = *flwor.get_clause_list ();

  set<const var_expr *> all_vars;
  set<const var_expr *> group_vars;
  set<const var_expr *> non_group_vars;

  // Collect the var_exprs for all the vars that have been defined by all
  // clauses before this GroupByClause.
  collect_flwor_vars (flwor, all_vars, &*clauses [0], &v, false);

  // Collect the var_exprs for all the grouping vars specified in this GroupByClause.
  GroupSpecList* lList = v.get_spec_list();
  for (size_t i = 0; i < lList->size(); ++i) 
  {
    GroupSpec* lSpec = (*lList)[i];
    string varname = lSpec->get_var_name();
    const var_expr *ve = lookup_var(varname);
    if (ve == NULL)
      ZORBA_ERROR_LOC_PARAM( XPST0008, loc, varname, "");
    group_vars.insert(ve);
  }

  // The non-grouping vars are the vars in the difference of the 2 sets above.
  set_difference (all_vars.begin(), all_vars.end(),
                  group_vars.begin(), group_vars.end(),
                  inserter(non_group_vars, non_group_vars.begin()));

  // For each var_expr X that does not appear in the group-by clause, create
  // a new var_exp ngX and push ngX and X in the node stack.
  for (set<const var_expr *>::iterator i = non_group_vars.begin();
       i != non_group_vars.end();
       ++i)
  {
    nodestack.push(const_cast<var_expr *>(*i));

    push_scope();

    bind_var_and_push(loc, (*i)->get_varname(), var_expr::non_groupby_var);
  }

  return no_state;
}


void end_visit (const GroupByClause& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  GroupSpecList ::= 	GroupingSpec ("," GroupingSpec)*
********************************************************************************/
void *begin_visit(const GroupSpecList& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const GroupSpecList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  GroupSpec ::= "$" VarName ("collation" URILiteral)?
********************************************************************************/
void *begin_visit(const GroupSpec& v) 
{
  TRACE_VISIT ();

  var_expr* e = lookup_var (v.get_var_name());
  if (e == NULL)
    ZORBA_ERROR_LOC_PARAM(XPST0008, loc, v.get_var_name(), "");

  push_scope();

  // Create a new var_expr gX, corresponding to the input-stream var X that 
  // is referenced by this group spec. gX represents X in the output stream.
  // Push the var_exprs for both X and gX into the nodestack.
  nodestack.push(rchandle<expr>(e));
  bind_var_and_push(loc, v.get_var_name(), var_expr::groupby_var);

  return no_state;
}

void end_visit(const GroupSpec& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************

********************************************************************************/
void *begin_visit(const GroupCollationSpec& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const GroupCollationSpec& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  OrderByClause ::= (("order" "by") | ("stable" "order" "by")) OrderSpecList
********************************************************************************/
void *begin_visit(const OrderByClause& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const OrderByClause& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  OrderSpecList ::=	OrderSpec ("," OrderSpec)*
********************************************************************************/
void *begin_visit(const OrderSpecList& v) 
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const OrderSpecList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  OrderSpec ::= ExprSingle OrderModifier
********************************************************************************/
void *begin_visit(const OrderSpec& v) 
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const OrderSpec& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  OrderModifier ::= OrderDirSpec? OrderEmptySpec? OrderCollationSpec?

  OrderCollationSpec ::= "collation" URILiteral

  OrderDirSpec ::= "ascending" | "descending"

  OrderEmptySpec ::= "empty" ("greatest" | "least")
********************************************************************************/
void *begin_visit (const OrderModifier& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const OrderModifier& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}

void *begin_visit (const OrderCollationSpec& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const OrderCollationSpec& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}

void *begin_visit (const OrderDirSpec& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const OrderDirSpec& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}

void *begin_visit (const OrderEmptySpec& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const OrderEmptySpec& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  WhereClause ::= "where"  ExprSingle
********************************************************************************/
void *begin_visit (const WhereClause& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const WhereClause& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  CountClause ::= "count" "$" VarName
********************************************************************************/
void *begin_visit (const CountClause& v) 
{
  TRACE_VISIT ();

  if (xquery_version <= StaticContextConsts::xquery_version_1_0)
    ZORBA_ERROR_LOC (XPST0003, loc);

  return no_state;
}

void end_visit (const CountClause& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
  bind_var_and_push (loc, v.get_varname (), var_expr::count_var, NULL);
}


/***************************************************************************//**

********************************************************************************/
void *begin_visit (const CtxItemDecl& v) 
{
  TRACE_VISIT ();

  if (xquery_version <= StaticContextConsts::xquery_version_1_0)
    ZORBA_ERROR_LOC (XPST0003, loc);

  return no_state;
}

void end_visit (const CtxItemDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
  if (v.get_type () != NULL) {
    ctx_item_type = pop_tstack ();
  }
  if (v.get_expr () != NULL)
    ctx_item_default = pop_nodestack ();
  if (v.get_type () != NULL || v.get_expr () != NULL) {
    store::Item_t dotname;
    varref_t var = create_var (loc, ".", var_expr::context_var, ctx_item_type);
    global_binding b (var, ctx_item_default, true);
    add_single_global_assign (b);
  }
}


/***************************************************************************//**
  IndexDecl ::= "DECLARE" ["UNIQUE"] ["HASH" | "BTREE"] "INDEX" UriLiteral
                "ON" ExprSingle
                "BY" "(" IndexFieldList ")"
********************************************************************************/
void *begin_visit (const IndexDecl& v) 
{
  TRACE_VISIT ();
  xqpStringStore_t uri(new xqpStringStore(v.get_uri()));
  ValueIndex_t vi = new ValueIndex(sctx_p, uri);
  indexstack.push(vi);
  return no_state;
}

void end_visit (const IndexDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
  ValueIndex_t vi = indexstack.top();
  indexstack.pop();
  vi->setUnique(v.uniq);
  vi->setMethod("btree" == v.method ? ValueIndex::BTREE : ValueIndex::HASH);
  IndexTools::inferIndexCreators(vi.getp());
  xqp_string uri(vi->getIndexUri());
  sctx_p->bind_index(uri, vi.getp());
}


/***************************************************************************//**
  IndexFieldList ::= IndexField (COMMA IndexField)*
********************************************************************************/
void *begin_visit (const IndexFieldList& v) {
  TRACE_VISIT ();

  expr_t dExpr = pop_nodestack();
  const std::string& uri = indexstack.top()->getIndexUri()->str();
  if (compilerCB->m_config.translate_cb != NULL)
    compilerCB->m_config.translate_cb (&*dExpr, uri);

  normalize_expr_tree(uri.c_str(), compilerCB, dExpr, &*GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR);

  if (compilerCB->m_config.opt_level == CompilerCB::config_t::O1) {
    RewriterContext rCtx(compilerCB, dExpr);
    GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rCtx);
    dExpr = rCtx.getRoot();
    if (compilerCB->m_config.optimize_cb != NULL)
      compilerCB->m_config.optimize_cb (&*dExpr, uri.c_str());
  }

  indexstack.top()->setDomainExpression(dExpr);

  push_scope();

  indexstack.top()->setDomainVariable(bind_var(v.get_location(),
                                               DOT_VARNAME,
                                               var_expr::for_var));

  indexstack.top()->setDomainPositionVariable(bind_var(v.get_location(),
                                                       DOT_POS_VARNAME,
                                                       var_expr::pos_var));
  return no_state;
}

void end_visit (const IndexFieldList& v, void* /*visit_state*/) {
  std::vector<expr_t> iCols;
  std::vector<xqtref_t> iColTypes;
  std::vector<std::string> iColColls;
  for(int i = v.fields.size() - 1; i >= 0; --i) {
    iCols.push_back(pop_nodestack());
    xqtref_t type = (v.fields[i]->get_type() != NULL ?
                     pop_tstack() :
                     GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION);
    iColTypes.push_back(type);
    iColColls.push_back(v.fields[i]->coll);
  }
  std::reverse(iCols.begin(), iCols.end());
  std::reverse(iColTypes.begin(), iColTypes.end());
  std::reverse(iColColls.begin(), iColColls.end());

  indexstack.top()->setIndexFieldExpressions(iCols);
  indexstack.top()->setIndexFieldTypes(iColTypes);
  indexstack.top()->setIndexFieldCollations(iColColls);

  pop_scope();

  TRACE_VISIT_OUT ();
}


/***************************************************************************//**
  IndexField ::= ExprSingle [TypeDeclaration] ["COLLATION" UriLiteral]
********************************************************************************/
void *begin_visit (const IndexField& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const IndexField& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


/***************************************************************************//**
  IndexStatement ::= ["CREATE" | "BUILD" | "DROP"] "INDEX" UriLiteral
********************************************************************************/
void *begin_visit (const IndexStatement& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const IndexStatement& v, void* /*visit_state*/) {
  rchandle<fo_expr> fo;
  switch(v.type) {
    case IndexStatement::build_stmt:
      fo = new fo_expr(v.get_location(), LOOKUP_RESOLVED_FN(ZORBA_OPEXTENSIONS_NS, "build-index", 1));
      break;

    case IndexStatement::create_stmt:
      fo = new fo_expr(v.get_location(), LOOKUP_RESOLVED_FN(ZORBA_OPEXTENSIONS_NS, "create-index", 1));
      break;

    case IndexStatement::drop_stmt:
      fo = new fo_expr(v.get_location(), LOOKUP_RESOLVED_FN(ZORBA_OPEXTENSIONS_NS, "drop-index", 1));
      break;
  }
  store::Item_t uri_item;
  GENV_ITEMFACTORY->createAnyURI(uri_item, v.get_uri().c_str());
  expr_t uri(new const_expr(v.get_location(), uri_item));
  fo->add(uri);
  nodestack.push((const rchandle<fo_expr>&)fo);

  TRACE_VISIT_OUT ();
}

/*******************************************************************************

  VarDecl represents a variable declaration in the prolog.

********************************************************************************/

void *begin_visit (const VarDecl& v) {
  TRACE_VISIT ();
  string key = static_context::qname_internal_key (sctx_p->lookup_var_qname (v.get_varname (), loc));
  if (v.is_global ()) {
    global_var_decls.push_front (key);
    // TODO: local vars too
    global_decl_stack.push ("V" + key);
  }
  return no_state;
}

void end_visit (const VarDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  if (v.is_global ())
    pop_stack (global_decl_stack);
  xqp_string varname = v.get_varname();

  // The declared type of a global or external is never tightened based on
  // type inference because globals are mutable.
  xqtref_t type;
  if (v.get_typedecl () != NULL)
    type = pop_tstack ();

  varref_t ve = bind_var (loc, varname, var_expr::context_var, type);
  if (v.is_global ()) {
    if (! mod_ns.empty () && xqp_string (ve->get_varname ()->getNamespace ()) != mod_ns)
      ZORBA_ERROR_LOC (XQST0048, loc);
    if (! v.is_extern ()) {
      bind_var (ve, minfo->globals.get ());

      // bind the variable also in the sctx that is used
      // for importing modules
      if (export_sctx != NULL) {
        bind_var (ve, export_sctx);
      }
    }
#ifdef ZORBA_DEBUGGER
    theScopedVariables.push_back( ve );
#endif
  }
  expr_t val = v.get_initexpr () == NULL ? expr_t(NULL) : pop_nodestack();
  if (v.is_global ()) {
    theGlobalVars.push_back(global_binding(ve, val, v.is_extern ()));
  } else {
    nodestack.push (ve.cast<expr> ());
    nodestack.push (val);
  }
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
      const SequenceType *td = p->get_typedecl ().getp ();
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
                                                  n->get_name()->get_location ());
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
      f = new user_function(n->get_location(), sig, NULL, n->get_type (), n->deterministic);
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
  for (list<function *>::iterator k = global_fn_decls.begin ();
       k != global_fn_decls.end (); k++)
  {
    string kkey = "F" + static_context::qname_internal_key ((*k)->get_fname ());
    strset_t kedges;    
    if (! global_deps.get (kkey, kedges))
      continue;

    for (set<string>::iterator j = kedges->begin (); j != kedges->end (); j++) {
      string jkey = *j;
      for (list<function *>::iterator i = global_fn_decls.begin ();
           i != global_fn_decls.end (); i++)
      {
        string ikey = "F" + static_context::qname_internal_key ((*i)->get_fname ());
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
  function *f = sctx_p->lookup_fn_int (key, v.get_param_count ());
  global_fn_decls.push_front (f);
  fn_decl_stack.push_front (f);
  return no_state;
}


void end_visit (const FunctionDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
  pop_stack (global_decl_stack);
  pop_stack (fn_decl_stack);
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
  if (nargs > 0) 
  {
    rchandle<flwor_expr> flwor = pop_nodestack().dyn_cast<flwor_expr> ();
    ZORBA_ASSERT(flwor != NULL);

    for(int i = 0; i < nargs; ++i) 
    {
      const let_clause* lc = dynamic_cast<const let_clause*>((*flwor)[i]);

      var_expr* arg_var = dynamic_cast<var_expr*>(lc->get_expr());
      ZORBA_ASSERT(arg_var != NULL);

      args.push_back(arg_var);
    }

    if (body != NULL) 
    {
      flwor->set_return_expr(body);
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
    assert(body != NULL);
    if (body->is_sequential () && lFuncType != ParseConstants::fn_sequential) {
      ZORBA_ERROR_LOC_DESC (XPST0003, loc, "Only a sequential function can have a body that is sequential expression");
    }
    // bugfix for #2816235 (test seq_func1)
    // Under section 2.2.2 "Category Rules", it states:
    // If the body of a sequential function is a Block it must be either a sequential or simple expression."
    // TODO: the error code has not yet been decided by the w3c
    if ( lFuncType == ParseConstants::fn_sequential && body->is_updating() ) {
      ZORBA_ERROR_LOC_DESC (XPTY0004, loc, "A sequential function cannot have a body that returns a pending update list");
    }
    if (lFuncType == ParseConstants::fn_read) {
      if (body->is_updating())
        ZORBA_ERROR_LOC(XUST0001, loc);
    }
    else if (lFuncType == ParseConstants::fn_update) {
      if (! body->is_updating_or_vacuous ())
        ZORBA_ERROR_LOC(XUST0002, loc);
    } 

    user_function *udf = dynamic_cast<user_function *>(
                         LOOKUP_FN(v.get_name ()->get_prefix (),
                                   v.get_name ()->get_localname (),
                                   nargs));
    ZORBA_ASSERT (udf != NULL);
    
    if (compilerCB->m_config.translate_cb != NULL)
      compilerCB->m_config.translate_cb (&*body, v.get_name ()->get_qname ());

    normalize_expr_tree(v.get_name ()->get_qname().c_str(), compilerCB, body, *&(udf->get_signature().return_type()));

    if (compilerCB->m_config.opt_level == CompilerCB::config_t::O1) 
    {
      RewriterContext rCtx(compilerCB, body);
      GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rCtx);
      body = rCtx.getRoot();

      RewriterContext rCtx1(compilerCB, body);
      GENV_COMPILERSUBSYS.getPhase1Rewriter()->rewrite(rCtx1);
      body = rCtx1.getRoot();

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
    nodestack.push(new flwor_expr(loc, false));
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

  store::Item_t qname = sctx_p->lookup_qname ("", v.get_name(), v.get_location());

  varref_t param_var = create_var (loc, qname, var_expr::param_var);
  varref_t subst_var = bind_var (loc, qname, var_expr::let_var);

#ifdef ZORBA_DEBUGGER
  if(compilerCB->m_debugger != 0)
  {
    theScopedVariables.push_back(subst_var);
  }
#endif

  flwor->add_clause(wrap_in_letclause(&*param_var, subst_var));

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
    else if (fname == "id")
    {
      if (sz == 1)
        arguments.insert(arguments.begin(), DOT_VAR);

      expr_t idsExpr = arguments[1];

      rchandle<flwor_expr> flworExpr = wrap_expr_in_flwor(idsExpr, false);

      for_clause* fc = reinterpret_cast<for_clause*>((*flworExpr.getp())[0]);
      expr* flworVarExpr = fc->get_var();

      rchandle<fo_expr> normExpr;
      rchandle<fo_expr> tokenExpr;
      rchandle<const_expr> constExpr = new const_expr(loc, xqpString(" " ));

      normExpr = new fo_expr(loc, LOOKUP_FN("fn", "normalize-space", 1));
      normExpr->add(flworVarExpr);
      tokenExpr = new fo_expr(loc, LOOKUP_FN("fn", "tokenize", 2));
      tokenExpr->add(normExpr.getp());
      tokenExpr->add(constExpr.getp());

      flworExpr->set_return_expr(tokenExpr.getp());

      pop_scope();

      arguments[1] = flworExpr;
    }
    else if (sz == 1 && (fname == "lang" || fname == "idref")) 
    {
      arguments.insert(arguments.begin(), DOT_VAR);
    } 
    else if (sz == 1 && fname == "resolve-uri") {
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
    } else if (fname == "doc") {
      if (sz > 0) {
        expr_t  doc_uri = arguments[0];
        //validate uri
        if(doc_uri->get_expr_kind() == const_expr_kind)
        {
          const_expr  *const_uri = reinterpret_cast<const_expr*>(doc_uri.getp());
          store::Item_t uri_value = const_uri->get_val();
          xqpStringStore_t   uri_string = uri_value->getStringValue();
          try{
            xqpString   xqp_uri_string(uri_string);
            //xqpString   xqp_base_uri("http://website/");
            //URI   baseURI(xqp_base_uri, false);
            if(uri_string->indexOf(":/") >= 0)
            {
              URI   docURI(xqp_uri_string, true);//with validate`
            }
          }
          catch(error::ZorbaError &e)
          {
            ZORBA_ERROR_LOC_PARAM(FODC0005, loc, e.toString(), "");
          }
        }
      }
    }
  } else if (fn_ns->byteEqual(ZORBA_FN_NS)) {
    if (fname == "inline-xml" && sz == 1) {
      nodestack.push (new eval_expr(loc, create_cast_expr (loc, arguments [0], GENV_TYPESYSTEM.STRING_TYPE_ONE, true)));
      return;
    }
  }

  sz = arguments.size ();  // recompute size

  // try constructor functions
  xqtref_t type = CTXTS->create_named_type(sctx_p->lookup_elem_qname(prefix, fname, loc),
                                           TypeConstants::QUANT_QUESTION);

  if (type != NULL) 
  {
    if (sz != 1
        || TypeOps::is_equal (*type, *GENV_TYPESYSTEM.NOTATION_TYPE_QUESTION)
        || TypeOps::is_equal (*type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION))
      ZORBA_ERROR_LOC_PARAM( XPST0017,  loc, prefix + ":" + fname, sz);

    nodestack.push (create_cast_expr (loc, arguments [0], type, true));
  }
  else 
  {  // a real function
      function *f = LOOKUP_FN (prefix, fname, sz);
      if (f == NULL)
        ZORBA_ERROR_LOC_PARAM (XPST0017, loc, (prefix.empty () ? prefix : (prefix + ":")) + fname, to_string (sz));

      if (NULL != dynamic_cast<user_function *> (f)) {
        if (! fn_decl_stack.empty ()) {
          user_function *udf = dynamic_cast<user_function *> (fn_decl_stack.back ());
          ZORBA_ASSERT (udf != NULL);
          udf->setLeaf (false);
          // cout << "UDF " << udf->get_fname ()->getStringValue () << " non-leaf due to " << f->get_fname ()->getStringValue () << endl;
        }
      }

      rchandle<fo_expr> fo_h = new fo_expr (loc, f);

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
  sctx_p->set_xquery_version(parse_xquery_version(v.get_version_decl().getp()));
  nodestack.push (wrap_in_globalvar_assign (create_seq (loc)));
}


void *begin_visit (const MainModule & v) {
  TRACE_VISIT ();

  theDotVar = bind_var (loc, DOT_VARNAME, var_expr::context_var, ctx_item_type);
  
  sctx_p->set_xquery_version(parse_xquery_version(v.get_version_decl().getp()));
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
  if (! ( pfx.empty () || ( pfx == mod_pfx && target_ns == mod_ns ) ) ) {
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

  // use the target namespace if no at clauses are there
  // otherwise use the resolved URIs of the at clauses
  vector<xqpStringStore_t> lURIs;
  if (ats == NULL || ats->size () == 0) {
    lURIs.push_back(xqp_string(target_ns).getStore());
  } else {
    for (int i = 0; i < ats->size(); ++i) {
      lURIs.push_back(sctx_p->resolve_relative_uri((*ats)[i], xqp_string()).getStore());
    }
  }

  // the module URI resolve that is used for retrieving the istream to the module
  // this can either be Zorba's standard implementation or one that has been
  // provided by the user
  InternalModuleURIResolver* lModuleResolver = sctx_p->get_module_uri_resolver();

  // do the actual work
  // take each of the URIs collected above and import the module's functions
  // and variables into the current static context.
  for (vector<xqpStringStore_t>::iterator lIter = lURIs.begin();
       lIter != lURIs.end(); ++lIter) {
    xqpStringStore_t resolveduri = *lIter; 
    store::Item_t    aturiitem = NULL;
    if (!GENV_ITEMFACTORY->createAnyURI(aturiitem, resolveduri))
      ZORBA_ERROR_LOC_DESC_OSS(XQST0046, loc, "URI is not valid " << resolveduri);

    // track cyclic imports
    set<string> mod_stk1 = mod_stack;
    if (! mod_stk1.insert (xqpString(resolveduri.getp())).second)
      ZORBA_ERROR_LOC (XQST0073, loc);
    
    string imported_ns; // the target namespace of the imported module
    static_context *imported_sctx = NULL;

    // use the cache
    if (minfo->mod_ns_map.get (xqpString(resolveduri.getp()), imported_ns)) {
      bool found = minfo->mod_sctx_map.get (xqpString(resolveduri.getp()), imported_sctx);
      ZORBA_ASSERT (found);
    } else {
      // we get the ownership of the input stream
      // TODO: we have to find a way to tell user defined resolvers when their input stream
      // can be freed. The current solution might leed to problems on Windows.
      xqpStringStore lFileUri;
      auto_ptr<istream> modfile (lModuleResolver->resolve(aturiitem, sctx_p, &lFileUri));
#ifdef ZORBA_DEBUGGER
      if(compilerCB->m_debugger != 0) {
        compilerCB->m_debugger->theModuleFileMappings.insert(std::pair<std::string, std::string>(aturiitem->getStringValue()->c_str(), lFileUri.c_str()));
      }
#endif

      if (modfile.get () == NULL || ! *modfile) {
        ZORBA_ERROR_LOC_PARAM (XQST0059, loc, resolveduri, target_ns);
      }

      // Create a CompilerCB for the imported module as a copy of the importing
      // module's CompilerCB. Copying is needed for configuration settings,
      // error manager, and debugger
      CompilerCB mod_ccb (*compilerCB);

      static_context_t independent_sctx = static_cast<static_context *> (minfo->topCompilerCB->m_sctx->get_parent ());

      // Create the root sctx for the imported module as a child of the
      // user-specified sctx (if any) or the zorba default (root) sctx (if no
      // user-specified sctx).
      mod_ccb.m_sctx = independent_sctx->create_child_context ();
      minfo->topCompilerCB->m_sctx_list.push_back (mod_ccb.m_sctx); // make sure it's not deleted
      mod_ccb.m_sctx->set_entity_retrieval_url (xqpString(resolveduri.getp()));

      // Create an sctx where the imported module is going to register all the
      // variable and function declarations that appear in its prolog. After the
      // translation of the imported module is done, this sctx will be merged
      // with the sctx of the importing module.
      imported_sctx = independent_sctx->create_child_context();
      minfo->topCompilerCB->m_sctx_list.push_back (imported_sctx);
      // remeber the context; will be used in the translation process 
      // of the module as export_sctx
      minfo->mod_sctx_map.put (xqpString(resolveduri.getp()), imported_sctx);

      // Parse the imported module
      XQueryCompiler xqc (&mod_ccb);
      xqpString lFileName(aturiitem->getStringValue());
      rchandle<parsenode> ast = xqc.parse (*modfile, lFileName);
#ifdef ZORBA_DEBUGGER
      if(compilerCB->m_debugger != 0)
      {
        compilerCB->m_debugger->addModule(ast);
      }
#endif
      // Get the target namespace that appears in the module declaration
      // of the imported module and check that this ns is the same as the
      // target ns in the module import statement.
      // Also make sure that the imported module is a library module
      LibraryModule *mod_ast = dynamic_cast<LibraryModule *> (&*ast);
      if (mod_ast == NULL)
        ZORBA_ERROR_LOC_PARAM (XQST0059, loc, resolveduri, target_ns);

      // translate the imported module
      translate_aux (*ast, &mod_ccb, minfo, mod_stk1);

      // Register the mapping between the current location uri and the
      // target namespace.
      imported_ns = mod_ast->get_decl ()->get_target_namespace ();
      minfo->mod_ns_map.put (xqpString(resolveduri.getp()), imported_ns);
    }

    // module with given target_ns not found
    if (imported_ns != target_ns)
      ZORBA_ERROR_LOC_PARAM (XQST0059, loc, resolveduri, target_ns);

    // We catch duplicate functions / vars in minfo->globals.
    // We can safely ignore the return value. We might even be able
    // to assert() here (not sure though).
    sctx_p->import_module (imported_sctx);
  } // for (vector<xqpStringStore_t>::iterator lIter = lURIs.begin();
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

  // ignore if an error occurs
  sctx_p->bind_option(option_ns, qn->get_localname(), v.get_val());

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


void *begin_visit (const DecimalFormatNode& v) {
  // cout << "Got DecimalFormat declaration: " << std::endl;
  TRACE_VISIT ();

  store::Item_t qname;
  if (!v.is_default)
  {
    string::size_type pos = v.format_name.find(":");
    string prefix = v.format_name.substr(0, pos == string::npos ? 0 : pos);
    string name = v.format_name.substr(pos == string::npos ? 0 : pos+1);
    xqp_string ns;
    ns_ctx->findBinding(prefix, ns);
    GENV_ITEMFACTORY->createQName(qname, ns.c_str(), prefix.c_str(), name.c_str());
  }
  
  DecimalFormat_t df = new DecimalFormat(v.is_default, qname, v.param_list);
  sctx_p->add_decimal_format(df);
    
  return no_state;
}

void end_visit (const DecimalFormatNode& v, void* /*visit_state*/) {
  // std::cout << "end_visit() Got DecimalFormat declaration: " << std::endl;
  TRACE_VISIT_OUT ();
}


void *begin_visit (const SchemaImport& v) 
{
  TRACE_VISIT ();

#ifndef ZORBA_NO_XMLSCHEMA

  SchemaPrefix* sp = &*v.get_prefix();
  string target_ns = v.get_uri();

  if (! schema_import_ns_set.insert(target_ns).second)
    ZORBA_ERROR_LOC (XQST0058, loc);

  if (sp != NULL) 
  {
    if (target_ns.size() == 0)
      ZORBA_ERROR_LOC_PARAM(XQST0057, loc,
                            "(no target namespace uri specified)",
                            target_ns);

    string pfx = sp->get_prefix();
    if (pfx == "xml" || pfx == "xmlns")
      ZORBA_ERROR_LOC (XQST0070, loc);

    if (sp->get_default_bit()) 
      sctx_p->set_default_elem_type_ns (target_ns);

    if (! pfx.empty())
      sctx_p->bind_ns (pfx, target_ns, XQST0033);
  }

  store::Item_t lTargetNamespace = NULL;
  ITEM_FACTORY->createAnyURI(lTargetNamespace, target_ns.c_str());
  ZORBA_ASSERT(lTargetNamespace != NULL);

  rchandle<URILiteralList> atlist = v.get_at_list();
  std::vector<store::Item_t> lAtURIList;

  if (atlist != NULL) 
  {
    for (int i = 0; i < atlist->size(); ++i) 
    {
      string at = sctx_p->resolve_relative_uri((*atlist)[i], xqpString());
      store::Item_t lAtURIItem;
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
  
  try 
  {
    store::Item_t lSchemaUri = lSchemaResolver->resolve(lTargetNamespace,
                                                        lAtURIList,
                                                        sctx_p);
    CTXTS->initializeSchema();
    Schema* schema_p = CTXTS->getSchema();

    std::string lTmp(lSchemaUri->getStringValue()->c_str());
    schema_p->registerXSD(lTargetNamespace->getStringValue()->c_str(), lTmp, loc);
  }
  catch (error::ZorbaError& e) 
  {
    ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
  }

  return no_state;

#else
  ZORBA_ERROR_LOC(XQST0009, loc);
  return no_state;
#endif
}

void end_visit (const SchemaImport& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}

void *begin_visit (const SchemaPrefix& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const SchemaPrefix& v, void* /*visit_state*/) 
{
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
  if (! xqp_string (v.get_encoding ()).matches ("^[A-Za-z]([A-Za-z0-9._]|[-])*$", ""))
    ZORBA_ERROR_LOC (XQST0087, loc);

  StaticContextConsts::xquery_version_t ver = parse_xquery_version(&v);
  if (ver == StaticContextConsts::xquery_version_unknown)
    ZORBA_ERROR_LOC(XQST0031, loc);

  sctx_p->set_xquery_version(ver);
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
      && ! TypeOps::is_equal (*type, *GENV_TYPESYSTEM.QNAME_TYPE_QUESTION)) 
  {
    if (isCast)
      return new cast_expr (loc, node, type);
    else
      return new castable_expr (loc, node, type);
  }
  else 
  {  // a QName cast
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
      lUpdateType = update_type_check_for_if(e_h->get_update_type(),
                                             lUpdateType, 
                                             loc);
      elist_h->add(e_h);
    }
    nodestack.push(elist_h.release());
  }
}

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

  if (c_h->is_updating()) {
    ZORBA_ERROR_LOC(XUST0001, loc);
  }

  update_type_check_for_if(t_h->get_update_type(), 
                           e_h->get_update_type(),
                           loc);

#ifdef ZORBA_DEBUGGER
  if (compilerCB->m_debugger != 0) {
    c_h = new debugger_expr(c_h->get_loc(), c_h, theScopedVariables, theGlobalVars);
    t_h = new debugger_expr(t_h->get_loc(), t_h, theScopedVariables, theGlobalVars);
    e_h = new debugger_expr(e_h->get_loc(), e_h, theScopedVariables, theGlobalVars);
  }
#endif
  if_expr *lIfExpr = new if_expr(loc,c_h,t_h,e_h);
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
  nodestack.push(new fo_expr (loc, LOOKUP_OP1 ("sort-distinct-nodes-asc"), fo_h));
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
                            sctx_p->lookup_qname("", qname, v.getQName()->get_location()) :
                            sctx_p->lookup_elem_qname(qname, v.getQName()->get_location()));
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
                              sctx_p->lookup_qname("", qname, wildcard->get_location()) :
                              sctx_p->lookup_elem_qname(qname, wildcard->get_location()));
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
      cc->add_nametest_h(new NodeNameTest(qn_h));
    } else {
      rchandle<Wildcard> wildcard = v.getWildcard();
      ZORBA_ASSERT(wildcard != NULL);

      switch (wildcard->getKind())
      {
        case ParseConstants::wild_all:
          cc->add_nametest_h(new NodeNameTest(xqpString("*").theStrStore, xqpString("*").theStrStore));
          break;
        case ParseConstants::wild_elem:
          cc->add_nametest_h(new NodeNameTest(xqpString("*").theStrStore, wildcard->getPrefix().theStrStore));
          break;
        case ParseConstants::wild_prefix:
          cc->add_nametest_h(new NodeNameTest(wildcard->getLocalName().theStrStore, xqpString("*").theStrStore));
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


/*******************************************************************************

  DocumentTest ::= "document-node" "(" (ElementTest | SchemaElementTest)? ")"

********************************************************************************/
void *begin_visit (const DocumentTest& v) 
{
  TRACE_VISIT();
  return no_state;
}


void end_visit (const DocumentTest& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  ElementTest* elemTest = v.get_elem_test().getp();
  SchemaElementTest* schemaTest = v.get_schema_elem_test().getp();
  axis_step_expr* axisExpr = peek_nodestk_or_null().dyn_cast<axis_step_expr>();
  rchandle<match_expr> match;

  if (elemTest == NULL && schemaTest == NULL) 
  {
    if (axisExpr != NULL) 
    {
      match = new match_expr(loc);
      match->setTestKind(match_doc_test);

      axisExpr->setTest(match);
    }
    else
    {
      tstack.push(GENV_TYPESYSTEM.DOCUMENT_TYPE_ONE);
    }
  }
  else if (axisExpr != NULL) 
  {
    match = axisExpr->getTest();
    match->setDocTestKind(match->getTestKind());
    match->setTestKind(match_doc_test);
  }
  else
  {
    xqtref_t elementOrSchemaTest = pop_tstack();
        
    xqtref_t docTest = CTXTS->create_node_type(store::StoreConsts::documentNode,
                                               NULL,
                                               elementOrSchemaTest,
                                               TypeConstants::QUANT_ONE,
                                               false);
    tstack.push(docTest);
  }
}


/*******************************************************************************

	ElementTest ::= "element" "("
                     (ElementNameOrWildcard ("," TypeName "?"?)?)?
                  ")"

  ElementNameOrWildcard ::= ElementName | "*"

********************************************************************************/
void *begin_visit (const ElementTest& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const ElementTest& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  bool nillable =  v.isNilledAllowed();
  rchandle<QName> elemName = v.getElementName();
  rchandle<TypeName> typeName = v.getTypeName();
  store::Item_t elemNameItem;
  store::Item_t typeNameItem;

  if (elemName != NULL)
    elemNameItem = sctx_p->lookup_elem_qname(elemName->get_qname(), loc);

  if (typeName != NULL)
    typeNameItem = sctx_p->lookup_elem_qname(typeName->get_name()->get_qname(), loc);

  // if the top of the stack is an axis step expr, add a node test expr to it.
  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();

  if (axisExpr != NULL) 
  {
    rchandle<match_expr> me = new match_expr(loc);
    me->setTestKind(match_elem_test);
    me->setQName(elemNameItem);
    me->setTypeName(typeNameItem);
    me->setNilledAllowed(nillable);

    axisExpr->setTest(me);
  }

  // Else, create a sequence-type match
  else 
  {
    xqtref_t contentType;
  
    if (typeName != NULL) 
    {
      contentType = CTXTS->create_named_type(typeNameItem, TypeConstants::QUANT_ONE);
    }
  
    xqtref_t seqmatch = CTXTS->create_node_type(store::StoreConsts::elementNode,
                                                elemNameItem,
                                                contentType,
                                                TypeConstants::QUANT_ONE,
                                                nillable);
    tstack.push(seqmatch);
  }
}


/*******************************************************************************

  SchemaElementTest ::= "schema-element" "(" ElementDeclaration ")"

  ElementDeclaration ::= ElementName

********************************************************************************/
void *begin_visit (const SchemaElementTest& v) 
{
  TRACE_VISIT ();

#ifndef ZORBA_NO_XMLSCHEMA
  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  rchandle<QName> elemName = v.get_elem();
  ZORBA_ASSERT(elemName != NULL);

  store::Item_t elemQNameItem = sctx_p->lookup_elem_qname(elemName->get_qname(), loc);

  if (axisExpr != NULL) 
  {
    store::Item_t typeQNameItem;
    CTXTS->get_schema_element_typename(elemQNameItem, typeQNameItem);

    rchandle<match_expr> match = new match_expr(loc);
    match->setTestKind(match_xs_elem_test);
    match->setQName(elemQNameItem);
    match->setTypeName(typeQNameItem);

    axisExpr->setTest(match);
  }
  else
  {
    xqtref_t seqmatch = CTXTS->create_schema_element_type(elemQNameItem,
                                                          TypeConstants::QUANT_ONE);
    tstack.push(seqmatch);
  }
#else//ZORBA_NO_XMLSCHEMA
    ZORBA_ERROR_LOC(XQP0004_SYSTEM_NOT_SUPPORTED, v.get_location());
#endif
  return no_state;
}


void end_visit (const SchemaElementTest& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


void *begin_visit (const AttributeTest& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const AttributeTest& v, void* /*visit_state*/) 
{
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
      match->setQName(sctx_p->lookup_qname("", attrName->get_qname(), attrName->get_location()));

    if (typeName != NULL)
      match->setTypeName(sctx_p->lookup_elem_qname(typeName->get_name()->get_qname(), typeName->get_location()));

    axisExpr->setTest(match);
  }
  else 
  {
    store::Item_t attrNameItem;
    xqtref_t contentType;

    if (attrName != NULL) 
    {
      attrNameItem = sctx_p->lookup_qname("", attrName->get_qname(), attrName->get_location());
    }

    if (typeName != NULL) 
    {
      store::Item_t tname = sctx_p->lookup_elem_qname(typeName->get_name()->get_qname(), typeName->get_location());

      contentType = CTXTS->create_named_type(tname, TypeConstants::QUANT_ONE);
    }

    xqtref_t seqmatch = CTXTS->create_node_type(store::StoreConsts::attributeNode,
                                                attrNameItem.getp(),
                                                contentType,
                                                TypeConstants::QUANT_ONE,
                                                false);

    tstack.push(seqmatch);
  }
}


void *begin_visit (const SchemaAttributeTest& v) 
{
  TRACE_VISIT ();

#ifndef ZORBA_NO_XMLSCHEMA
  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  rchandle<QName> attrName = v.get_attr();
  ZORBA_ASSERT(attrName != NULL);

  store::Item_t attrQNameItem = sctx_p->lookup_qname("", attrName->get_qname(), attrName->get_location());

  if (axisExpr != NULL) 
  {
    store::Item_t typeQNameItem;
    CTXTS->get_schema_attribute_typename(attrQNameItem, typeQNameItem);

    rchandle<match_expr> match = new match_expr(loc);
    match->setTestKind(match_xs_attr_test);
    match->setQName(attrQNameItem);
    match->setTypeName(typeQNameItem);

    axisExpr->setTest(match);
  }
  else 
  {
    xqtref_t seqmatch = CTXTS->create_schema_attribute_type(attrQNameItem,
                                                            TypeConstants::QUANT_ONE);

    tstack.push(seqmatch);
  }

#else//ZORBA_NO_XMLSCHEMA
  ZORBA_ERROR_LOC(XQP0004_SYSTEM_NOT_SUPPORTED, v.get_location());
#endif
  return no_state;
}


void end_visit (const SchemaAttributeTest& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


void *begin_visit (const TextTest& v) 
{
  TRACE_VISIT ();
  // no action needed here
  return no_state;
}


void end_visit (const TextTest& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  if (axisExpr != NULL) 
  {
    rchandle<match_expr> match = new match_expr(loc);
    match->setTestKind(match_text_test);
    axisExpr->setTest(match);
  }
  else 
  {
    tstack.push(GENV_TYPESYSTEM.TEXT_TYPE_ONE);
  }
}


void *begin_visit (const CommentTest& v) 
{
  TRACE_VISIT ();
  // no action needed here
  return no_state;
}


void end_visit (const CommentTest& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  if (axisExpr != NULL) 
  {
    rchandle<match_expr> match = new match_expr(loc);
    match->setTestKind(match_comment_test);
    axisExpr->setTest(match);
  }
  else 
  {
    tstack.push(GENV_TYPESYSTEM.COMMENT_TYPE_ONE);
  }
}


void *begin_visit (const PITest& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const PITest& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  string target = v.get_target();

  store::Item_t qname = NULL;
  if (target != "")
    GENV_ITEMFACTORY->createQName(qname, NULL, NULL, target.c_str ());

  if (axisExpr != NULL) 
  {
    rchandle<match_expr> match = new match_expr(loc);
    match->setTestKind(match_pi_test);
    if (target != "")
      match->setQName(qname);
    axisExpr->setTest(match);
  } 
  else 
  {
    if (target == "")
    {
      tstack.push(GENV_TYPESYSTEM.PI_TYPE_ONE);
    }
    else 
    {
      xqtref_t t = GENV_TYPESYSTEM.create_node_type(store::StoreConsts::piNode,
                                                    qname,
                                                    NULL,
                                                    TypeConstants::QUANT_ONE,
                                                    false);
      tstack.push (t);
    }
  }
}


xqpString tempname () {
  return "$$temp" + to_string(tempvar_counter++);
}

varref_t tempvar(const QueryLoc& loc, var_expr::var_kind kind)
{
  xqpString lname (tempname ());
  return create_var(loc, lname, kind);
}


rchandle<flwor_expr> wrap_in_let_flwor (expr_t expr, varref_t lv, expr_t ret) 
{
  rchandle<flwor_expr> fe = new flwor_expr(lv->get_loc(), false);
  fe->add_clause(wrap_in_letclause (expr, lv));
  fe->set_return_expr(ret);
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

  In general, rpe-i says how step-i is connected with step-(i+1), i.e. with / or //.

  The root PathExpr node says whether the path expr starts with a / or // or an
  input step expr. In particular, the type of PathExpr can be one of the following:

  1. path_leading_lone_slash (/)
  2. path_leading_slash      (/...)
  3. path_leading_slashslash (//...)
  4. path_relative           (source_expr/...)

  In case 1, the PathExpr does not have any child node.

  Cases 2 and 3 are treated as if the syntax tree was like this:

       PathExpr
           |
         rpe0
        /    \
      step0  rpe1
            /    \
          step1  rpe2
                /    \
              step2  rpe3
                    /    \
                 step3  step4

  where, the type of PathExpr is path_relative, rpe0 designates a "/", and
  step0 is either
  fn:root(./self::node()) in case 2, or 
  fn:root(./self::node())/descendant-or-self::node() in case 3.

********************************************************************************/
void *begin_visit (const PathExpr& v) 
{
  TRACE_VISIT();

  const PathExpr& pe = v;

  ParseConstants::pathtype_t pe_type = pe.get_type();

  expr_t result;
  rchandle<relpath_expr> path_expr = NULL;

  // Put a NULL in the stack to mark the beginning of a PathExp tree.
  nodestack.push(NULL);

  // In cases 2, 3, and 4 create a new relpath_expr, which will be put to the nodestack.
  if (pe_type != ParseConstants::path_leading_lone_slash) 
  {
    path_expr = new relpath_expr(loc);

    result = path_expr.getp();
  }

  // If path expr starts with / or // (cases 1, 2, or 3), create an expr
  // R = fn:root(./self::node()). 
  //
  // In case 1, just push R to the nodestack.
  //
  // In case 2, put relpath_expr(R) to the nodestact 
  //
  // In case 3, put relpath_expr(R, descendant-or-self::node()) to the nodestack
  //
  // In case 4, put relpath_expr() to the nodestack

  if (pe_type != ParseConstants::path_relative)  
  {
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

    if (path_expr != NULL) 
    {
      path_expr->add_back(&*fo);
      result = path_expr.getp();
    }

    if (pe_type == ParseConstants::path_leading_slashslash) 
    {
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


void end_visit (const PathExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  expr_t arg2 = pop_nodestack();
  expr_t arg1 = pop_nodestack();

  ZORBA_ASSERT(arg1 == NULL);

  nodestack.push(wrap_in_dos_and_dupelim(arg2, true));
}


void* begin_visit(const RelativePathExpr& v)
{
  TRACE_VISIT ();

  const RelativePathExpr& rpe = v;
  rchandle<exprnode> step = rpe.get_step_expr();
  ZORBA_ASSERT(step != NULL);
  AxisStep* axisStep = step.dyn_cast<AxisStep>();

  // Let rpe be the i-th rpe in the Path Tree. Then i > 0, and pathExpr represents
  // the translation of step-0/step-1/.../step-(i-1)/. 
  expr_t e = pop_nodestack();
  relpath_expr* pathExpr = e.dyn_cast<relpath_expr>();
  ZORBA_ASSERT(pathExpr != NULL);

  // If case 4 and i = 1, then there is no step0 and pathExpr is empty.
  if (pathExpr->size() == 0) 
  {
    if (axisStep != NULL) 
    {
      pathExpr->add_back(DOT_VAR);

      if (axisStep->get_predicate_list() == NULL) 
      {
        // The path expr is of the form "axis::test/....". We push 
        // [ pathExpr(.) ] to the nodestack. 
        nodestack.push(pathExpr);
      }
      else 
      {
        // The path expr is of the form "axis::test[pred]/....". We push
        // [ for $$dot at $$pos in pathExpr(.) ]  to the nodestack.
        rchandle<flwor_expr> flworExpr = wrap_expr_in_flwor(pathExpr, false);
        nodestack.push(flworExpr.getp());
      }
    }
    else 
    {
      // The path expr is of the form "source_expr/....". We push 
      // pathExpr() to the nodestack. 
      nodestack.push(pathExpr);
    }
  }

  // Else if step-i is an axis step with no repdicates, just put pathExpr(...)
  // back in the stack.
  else if (axisStep != NULL && axisStep->get_predicate_list() == NULL) 
  {
    nodestack.push(pathExpr);
  }

  // Else, step-i is an axis step with predicates or a filter expr, and 
  // is not the very 1st step in the path expr. In this case, pathExpr becomes
  // the input to a new flwor expr that will compute, once for each node in
  // pathExpr, the next step in the path. In particular, the following expr
  // is pushed to the stack:
  //
  // [ for $$dot at $$pos in sort-distinct(pathExpr) ]
  else 
  {
    expr_t inputExpr = wrap_in_dos_and_dupelim(pathExpr, false);
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
  // the path expr is of the form "source_expr/...." and i = 1.
  if (pathExpr != NULL) 
  {
    axis_step_expr* axisExpr = stepExpr.dyn_cast<axis_step_expr>();
    ZORBA_ASSERT(axisExpr != NULL || pathExpr->size() == 0);

    pathExpr->add_back(stepExpr);
  }

  // Else, step-i was not an axis step, or it contained predicates. In this
  // case, translation of step-i resulted in a flwor expr that includes step-i
  // and all the ancestors of rpe-i. We create a new path_expr and make the
  // flwor expr its 1st step (i.e. flwor/.... or flwor/descendant-or-sef/...)
  else 
  {
    ZORBA_ASSERT(flworExpr != NULL);

    flworExpr->set_return_expr(stepExpr);
    pop_scope();

    pathExpr = new relpath_expr(loc);
    pathExpr->add_back(flworExpr);
  }

  // Convert // to /descendant-or-self::node()/
  if (rpe.get_step_type() == ParseConstants::st_slashslash)
  {
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
  // filter step or an axis step with predicates. In this case, pathExpr
  // becomes the input to a new flwor expr that will compute, once for each
  // node in pathExpr, the next step in the path. The flwor is pushed to the
  // nodestack.
  else 
  {
    expr_t inputSeqExpr = wrap_in_dos_and_dupelim(pathExpr, false);
    rchandle<flwor_expr> flworExpr = wrap_expr_in_flwor(inputSeqExpr, false);
    nodestack.push(flworExpr.getp());
  }
}


void end_visit (const RelativePathExpr& v, void* /*visit_state*/) 
{
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
  if (pathExpr != NULL) 
  {
    axis_step_expr* axisExpr = stepExpr.dyn_cast<axis_step_expr>();
    ZORBA_ASSERT(axisExpr != NULL);

    pathExpr->add_back(stepExpr);
    nodestack.push(pathExpr);
  }
  else
  {
    ZORBA_ASSERT(flworExpr != NULL);
    ZORBA_ASSERT(stepExpr != NULL);

    flworExpr->set_return_expr(stepExpr);
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
  // This method is called from FilterExpr::accept() after the primary expr is
  // translated, but before the associated predicate list is translated.

  if (!v.isPathStep())
    return;

  PredicateList* pl = v.get_pred_list().getp();

  ZORBA_ASSERT(pl != NULL && pl->size() > 0);

  expr_t primaryExpr = pop_nodestack();
  expr_t e = pop_nodestack();
  flwor_expr* flworExpr = e.dyn_cast<flwor_expr>();

  if (flworExpr != NULL) 
  {
    // for each item in the input seq compute the input seq for the pred
    // (= outer_dot/primaryExpr)
#if 0
    const QueryLoc& loc = v.get_location();

    const for_clause* fcOuterDot =
      reinterpret_cast<const for_clause*>((*flworExpr)[0]);
    if (primaryExpr->get_expr_kind() == axis_step_expr_kind) 
    {
      rchandle<relpath_expr> pathStepExpr = new relpath_expr(loc);
      pathStepExpr->add_back(fcOuterDot->get_var());
      pathStepExpr->add_back(primaryExpr.getp());
      primaryExpr = pathStepExpr.getp();
    }
#endif

    let_clause_t lcPredSeq = wrap_in_letclause(primaryExpr.getp());

    flworExpr->add_clause(lcPredSeq);

    nodestack.push(flworExpr);
    nodestack.push(lcPredSeq->get_var());
  }
  else
  {
     relpath_expr* pathExpr = e.dyn_cast<relpath_expr>();
     ZORBA_ASSERT(pathExpr != NULL && pathExpr->size() == 0);

     nodestack.push(pathExpr);
     nodestack.push(primaryExpr);
  }
}


void end_visit (const FilterExpr& v, void* /*visit_state*/) 
{
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

  // Nothing to do if there are no predicates
  if (pl == NULL || pl->size() == 0)
    return;

  const QueryLoc& loc = v.get_location();

  expr_t e = pop_nodestack();
  rchandle<axis_step_expr> axisExpr = e.dyn_cast<axis_step_expr>();
  ZORBA_ASSERT(axisExpr != NULL);

  e = pop_nodestack();
  flwor_expr* flworExpr = e.dyn_cast<flwor_expr>();
  ZORBA_ASSERT(flworExpr != NULL);

  axis_kind_t axisKind = axisExpr->getAxis();

  // For each item in the input seq compute the input seq for the preds (i.e.
  // outer_dot/axisExpr). In particular, the following exprs are pushed to the
  // nodestack:
  //
  // [ for $$dot at $$pos in sort-distinct(pathExpr-(i-1))
  //   let $$predInput := $$dot/axis::test ]
  //
  // [ $$predInput ]
  const for_clause* fcOuterDot = reinterpret_cast<const for_clause*>((*flworExpr)[0]);
  rchandle<relpath_expr> predPathExpr = new relpath_expr(loc);
  predPathExpr->add_back(fcOuterDot->get_var());
  predPathExpr->add_back(axisExpr.getp());
    
  expr_t predInputExpr = predPathExpr;
  
  if (axisKind == axis_kind_ancestor ||
      axisKind == axis_kind_ancestor_or_self ||
      axisKind == axis_kind_preceding_sibling ||
      axisKind == axis_kind_preceding)
  {
    predInputExpr = wrap_in_dos_and_dupelim(predInputExpr, false, true);
  }

  rchandle<let_clause> lcPredInput = wrap_in_letclause(predInputExpr.getp());

  flworExpr->add_clause(lcPredInput);

  nodestack.push(flworExpr);
  nodestack.push(lcPredInput->get_var());
}


void end_visit (const AxisStep& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();
}


void *begin_visit (const PredicateList& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const PredicateList& v, void* /*visit_state*/) 
{
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

  let_clause_t lcPred = wrap_in_letclause(predExpr);
  var_expr* predvar = lcPred->get_var();

  flworExpr->add_clause(lcPred);

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

  flworExpr->set_return_expr(ifExpr);

  nodestack.push(flworExpr);

  pop_scope();
}


void *begin_visit (const ForwardStep& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const ForwardStep& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


void *begin_visit (const AbbrevForwardStep& v) 
{
  TRACE_VISIT ();

  rchandle<axis_step_expr> ase = expect_axis_step_top ();

  if (v.get_attr_bit()) {
    ase->setAxis(axis_kind_attribute);
  } else {
    ase->setAxis(axis_kind_child);
  }

  return no_state;
}


void end_visit (const AbbrevForwardStep& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


void *begin_visit (const ForwardAxis& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const ForwardAxis& v, void* /*visit_state*/) 
{
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


void *begin_visit (const ReverseStep& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const ReverseStep& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


void *begin_visit (const ReverseAxis& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const ReverseAxis& v, void* /*visit_state*/) 
{
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


void end_visit (const QuantifiedExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  rchandle<flwor_expr> flwor(new flwor_expr(loc, false));

  flwor->set_return_expr(new const_expr(loc, true));

  rchandle<expr> sat = pop_nodestack();
  if (v.get_qmode() == ParseConstants::quant_every) 
  {
    rchandle<fo_expr> uw = new fo_expr(v.get_expr()->get_location(),
                                       LOOKUP_FN("fn", "not", 1));
    uw->add(sat);
    sat = uw.getp();
  }

  vector<varref_t> vars_vals (2 * v.get_decl_list()->size());
  generate (vars_vals.rbegin (), vars_vals.rend (), stack_to_generator (nodestack));

  for (int i = 0; i < v.get_decl_list()->size(); ++i) 
  {
    pop_scope ();
    varref_t ve = vars_vals [2 * i + 1].cast<var_expr> ();
    flwor->add_clause(wrap_in_forclause (&*vars_vals [2 * i], ve, NULL));
  }

  flwor->add_where(sat);

  rchandle<fo_expr> quant = new fo_expr(loc,
                                        v.get_qmode() == ParseConstants::quant_every ?
                                        LOOKUP_FN("fn", "empty", 1) :
                                        LOOKUP_FN("fn", "exists", 1));
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
      defret = &*wrap_in_let_flwor (&*sv, defvar, defret);
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
      nodestack.push (lFlwor);
    }
    expr_t lThen = pop_nodestack();
    update_type_check_for_if(lThen->get_update_type(), 
                             defret->get_update_type(),
                             loc);
    defret = new if_expr (e_p->get_location (),
                          new instanceof_expr (loc, &*sv, type),
                          lThen, defret);
  }

  {
    v.get_switch_expr ()->accept (*this);
    expr_t se = pop_nodestack ();
    if (se->is_updating()) {
      ZORBA_ERROR_LOC(XUST0001, loc);
    }
    expr_t lFlwor = wrap_in_let_flwor (se, sv, defret);
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
  nodestack.push(new fo_expr (loc, LOOKUP_OP1 ("sort-distinct-nodes-asc"), fo_h));
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

void *begin_visit (const ValidateExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ValidateExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
  store::Item_t qname;
  if (v.get_type_name() != NULL)
  {
    xqp_string ns;
    ns_ctx->findBinding(v.get_type_name()->get_prefix(), ns);
    GENV_ITEMFACTORY->createQName(qname, ns.c_str(), v.get_type_name()->get_prefix().c_str(), v.get_type_name()->get_localname().c_str());
  }

  nodestack.push (new validate_expr (loc,
                                     v.get_valmode(),
                                     qname,
                                     pop_nodestack(),
                                     sctx_p->get_typemanager()));
}

void *begin_visit (const VarRef& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const VarRef& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  var_expr *ve = lookup_var (v.get_varname ());
  if (ve == NULL)
    ZORBA_ERROR_LOC_PARAM (XPST0008, loc, v.get_varname (), "");
  if (ve->global && ! global_decl_stack.empty ()) {
    string key = "V" + static_context::qname_internal_key (ve->get_varname ());
    add_multimap_value (global_deps, global_decl_stack.top (), key);
  }
  nodestack.push (new wrapper_expr (v.get_location (), rchandle<expr> (ve)));
}


/* update-related */
void *begin_visit (const DeleteExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const DeleteExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  expr_t lTarget = pop_nodestack();
  if (lTarget->is_updating()) {
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
  if (lTarget->is_updating() || lSource->is_updating()) {
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

  if (nameExpr->is_updating() || targetExpr->is_updating()) {
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
  if (lReplacement->is_updating() || lTarget->is_updating()) {
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
  CHK_SINGLE_DECL (hadBUriDecl, XUST0003);
  sctx_p->set_validation_mode (v.get_mode ());
  return no_state;
}

void end_visit (const RevalidationDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const TransformExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const TransformExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  expr_t lReturn = pop_nodestack();
  if (lReturn->is_updating()) 
  {
    ZORBA_ERROR_LOC(XUST0001, loc);
  }

  expr_t lModify = pop_nodestack();
  if (! lModify->is_updating_or_vacuous ()) 
  {
    ZORBA_ERROR_LOC(XUST0002, loc);
  }

  std::auto_ptr<transform_expr> lTransform(new transform_expr(loc, lModify, lReturn));

  const size_t lSize = v.get_var_list()->size();
  for (size_t i = 0; i < lSize; ++i)
  {
    expr_t lExpr = pop_nodestack();
    if (lExpr->is_updating()) 
    {
      ZORBA_ERROR_LOC(XUST0001, loc);
    }

    varref_t lVarExpr = pop_nodestack_var ();
    lVarExpr->set_kind(var_expr::copy_var);

    copy_clause* copyClause = new copy_clause( lVarExpr, lExpr);
    lTransform->add_front(copyClause);

    pop_scope();
  }

  nodestack.push(lTransform.release());
}

void *begin_visit (const CopyVarList& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CopyVarList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}

void *begin_visit (const VarBinding& v) 
{
  TRACE_VISIT ();
  push_scope ();
  bind_var_and_push (loc, v.get_varname (), var_expr::copy_var);
  return no_state;
}

void end_visit (const VarBinding& v, void*) 
{
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
  if (xquery_version <= StaticContextConsts::xquery_version_1_0)
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

#if 0
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
#endif

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

void *begin_visit (const AssignExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const AssignExpr& v, void* visit_state) {
  TRACE_VISIT_OUT ();
  // TODO: add treat_expr to check var type
  const function *ctx_set = LOOKUP_OP2 ("ctxvar-assign");
  varref_t ve = lookup_ctx_var (v.get_varname (), loc);
  if (ve->get_kind () != var_expr::context_var)
    ZORBA_ERROR_LOC (XPST0003, loc);
  expr_t qname_expr = new const_expr (ve->get_loc(), dynamic_context::var_key (&*ve));
  nodestack.push (new fo_expr (loc, ctx_set, qname_expr, pop_nodestack ()));
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

