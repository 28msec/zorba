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

#include "context/static_context.h"
#include "context/static_context_consts.h"
#include "context/namespace_context.h"
#include "context/internal_uri_resolvers.h"
#include "context/standard_uri_resolvers.h"

#include "compiler/translator/translator.h"
#include "compiler/api/compilercb.h"
#include "compiler/expression/expr.h"
#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/parsetree/parsenode_visitor.h"
#include "compiler/normalizer/normalizer.h"
#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/rewriter/framework/rewriter.h"
#include "compiler/api/compiler_api.h"
#include "compiler/parser/util.h"
#include "compiler/indexing/index_tools.h"

#include "indexing/value_index.h"

#include "system/globalenv.h"

#include "functions/signature.h"
#include "functions/external_function_adapters.h"

#include "store/api/item.h"
#include "store/api/update_consts.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"

#include "debugger/zorba_debugger_commons.h"

using namespace std;

namespace zorba {

class ModulesInfo;


static expr_t translate_aux(
    const parsenode& root,
    CompilerCB* aCompilerCB,
    ModulesInfo* minfo,
    set<string> mod_stack,
    bool isLibModule);


#define QLOCDECL const QueryLoc &loc = v.get_location(); (void) loc

#ifndef NDEBUG

# define TRACE_VISIT() QLOCDECL; if (Properties::instance()->traceTranslator()) cout << string(++print_depth, ' ') << TRACE << ", stk size " << nodestack.size () << ", tstk size: " << tstack.size () << ", scope depth " << scope_depth << endl

# define TRACE_VISIT_OUT() QLOCDECL; if (Properties::instance()->traceTranslator()) cout << string(print_depth--, ' ') << TRACE << ", stk size: " << nodestack.size () << ", tstk size: " << tstack.size () << ", scope depth " << scope_depth << endl

#else
# define TRACE_VISIT() QLOCDECL
# define TRACE_VISIT_OUT() QLOCDECL
#endif


/*******************************************************************************
  Lookup in the sctx the function object for a function with a given prefix
  local name and arity. Return NULL if such a function is not found 
********************************************************************************/
#define LOOKUP_FN( pfx, local, arity ) (sctx_p->lookup_fn (pfx, local, arity))

#define LOOKUP_OP1( local ) (sctx_p->lookup_builtin_fn (":" local, 1))

#define LOOKUP_OP2( local ) (sctx_p->lookup_builtin_fn (":" local, 2))

#define LOOKUP_OP3( local ) (sctx_p->lookup_builtin_fn (":" local, 3))

#define LOOKUP_OPN( local ) (sctx_p->lookup_builtin_fn (":" local, VARIADIC_SIG_SIZE))

#define LOOKUP_RESOLVED_FN( ns, local, arity ) (sctx_p->lookup_resolved_fn(ns, local, arity))


/*******************************************************************************
  Set/get chached pointers to function objs for certain commonly-used function
  and operators (to avoid looking them up in the sctx all the time).
********************************************************************************/
#define CACHED( cache, val ) ((cache == NULL) ? (cache = val) : cache)


/*******************************************************************************
  Check/set certain bool data members of TranslatorImpl: raise error if true
  already otherwise set to true.
********************************************************************************/
#define CHK_SINGLE_DECL( state, err ) \
do { if (state) ZORBA_ERROR(err); state = true; } while (0)


/*******************************************************************************

********************************************************************************/
#define ITEM_FACTORY (GENV.getStore().getItemFactory())

#define CTXTS sctx_p->get_typemanager ()


/*******************************************************************************
  Internal names for certain implicit vars
********************************************************************************/
#define DOT_VARNAME "$$dot"
#define DOT_POS_VARNAME "$$pos"
#define LAST_IDX_VARNAME "$$last-idx"

#define DOT_VAR lookup_ctx_var (DOT_VARNAME, loc).getp()


/*******************************************************************************

********************************************************************************/
template<class T> T& peek_stack (stack<T> &stk) 
{
  ZORBA_ASSERT (! stk.empty ());
  return stk.top ();
}


template <typename T> T pop_stack (stack<T> &stk) 
{
  T x = peek_stack (stk);
  stk.pop ();
  return x;
}


template <typename T> T pop_stack (list<T> &stk) 
{
  ZORBA_ASSERT (! stk.empty ());
  T x =  stk.back ();
  stk.pop_back ();
  return x;
}


/*******************************************************************************
  Wrapper for ref-counted std::set
********************************************************************************/
template <class T> class RCSet : public SimpleRCObject 
{
public:
  typedef set<string>::iterator iterator;

  set<T> theSet;
  
    
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


/*******************************************************************************
  Given a hashmap that maps strings to set-of-strings, add a new string to
  the value-set of a given key string.
********************************************************************************/
void add_multimap_value(
    hashmap<strset_t > &map,
    const string &key,
    const string &val) 
{
  strset_t result;
  if (! map.get (key, result)) 
  {
    result = new RCSet<string> ();
    map.put (key, result);
  }
  result->insert (val);
}
  

/*******************************************************************************

  There is only one ModulesInfo instance per compilation. It is created on the
  stack by the translate() method.

  topCompilerCB : The compilerCB for the root module of the compilation. It
                  provides access to the static context that is common to all 
                  modules (this is either a user-provided sctx, or the zorba
                  default sctx).

  mod_ns_map    : Maps resolved module location uris to target namespaces.
                  Used to skip compilation of a module that has been compiled
                  already (for example this is the case when 2 imported modules
                  both import a common module). It is also used to make sure
                  that a location uri does not appear in two module import
                  statements with different target namespaces.

  mod_sctx_map  : Maps resolved module location uris to sctx objs containing
                  the var and udf declarations that are exported by the
                  modules corresponding to the location uris.

  init_exprs    : Contains the initializing expr for each prolog var in each
                  module participating in the compilation (see method
                  wrap_in_globalvar_assigh())

********************************************************************************/
class ModulesInfo 
{
public:
  CompilerCB                * topCompilerCB;
  hashmap<static_context_t>   mod_sctx_map;
  hashmap<string>             mod_ns_map;
  checked_vector<expr_t>      init_exprs;
  auto_ptr<static_context>    globals;

  ModulesInfo(CompilerCB *topCompilerCB_)
    :
    topCompilerCB (topCompilerCB_),
    globals(static_cast<static_context *>
            (topCompilerCB->m_sctx->get_parent())->create_child_context())
  {
  }
};



/*******************************************************************************

  A new instance of TranslatorImpl is created for the translation of each
  module participating in a query. The instance is destroyed when the translation
  of the associated module is finished.

  xquery_version       : 100 for 1.0, 110 for 1.1 etc

  cb                   : The compiler control block associated with this translator
                         (each translator uses its own compiler cb; also for library
                          modules).

  minfo                : Pointer to the unique ModulesInfo instance (see class
                         ModulesInfo above).

  mod_stack            : A set containing the ns uri of all the modules that have
                         been imported so far by this module and its ancestor 
                         modules in a chain of module imports. It is used to check
                         that there are no cycles in a chain of module imports.

  theModuleNamespace   : If this translator is working on a library module,
                         theModuleNamespace is the namespace uri of that module.
  theModulePrefix      : If this translator is working on a library module, 
                         theModulePrefix is the prefix associated with the ns
                         uri of that module.

  zorba_predef_mod_ns  : Set of ns uris for all internal predefined modules. 
  mod_import_ns_set    : Set of ns uris for all the modules directly imported 
                         by this module. Used to check that the same module is
                         not imported twice by this module.
  schema_import_ns_set : Set of ns uris for all schemas directly imported by
                         this module. Used to check that the same schema is not
                         imported twice by this module.

  sctx_p               : The "current" static context node. It is initialized
                         with the root static context of the associated module.
  export_sctx          : In case this is a library module translator, export_sctx
                         is populated with the variable and function declarations
                         that are exported by the module, i.e., the var and udf
                         declarations that appear in the prolog of this module.
                         The export_sctx is created by the importing module,
                         populated by the imported module, and then merged by
                         the importing module into its own sctx. export_sctx is
                         "shared" between importing and imported modules via the
                         minfo->mod_sctx_map. export_sctx is needed because module
                         import is not transitive: If M1 imports M2 and M2 imports
                         M3, then the vars and functions are seen by M2, but not
                         by M3. This means, that the regular root sctx S2 of M2
                         will contain the decls from both M2 and M3. So, M1 should
                         not import S2 into its own sctx S1. Instead, we create
                         ES2 for M2 and register in there the decls of M2 only;
                         then, we import ES2 to S1.
  ns_ctx               : The "current" namespace bindings node. It is initialized
                         with a newly allocated ns_ctx node, which points to the
                         initial sctx node. The initial sctx node stores all ns
                         bindings that are declared in the prolog. ns_ctx nodes 
                         are created to store ns bindings declared in element
                         constructors. In general, the ns_ctx hierarchy (of which
                         the initial sctx node and its ancestors are considered
                         to be part of) defines the namepsace bindings that are
                         in scope for each expr. ns_ctx nodes are kept separate
                         from sctx nodes because sctx nodes may disappear after
                         translation is done, whereas certain exprs need to know
                         their ns_ctx in later compilation phases as well.

  print_depth          : For pretty tracing
  scope_depth          : Incremented/Decremented every time a scope is pushed/popped
                         Used for some sanity checking only.

  theDotVar            : var_expr for the context item var of the main module

  thePrologVars        : thePrologVars vector contains one entry for each var V
                         declared in the prolog of this module. The entry maps
                         the var_expr for V to the expr E that initializes V (E
                         is NULL for vars without init expr). At the end of each
                         module translation, the method wrap_in_globalvar_assign()
                         creates appropriate initialization exprs for each var in 
                         thePrologVars and registers them in minfo->init_exprs, so
                         that they will be incorporated in the whole query plan at
                         the end of the translation of the root module.

  thePrologDeps        : A hashmap implementing the dependency graph among the
                         variables and udfs declared in the prolog of a module.
                         It maps the normalized qname of a var or udf X to a set
                         containing the normalized qnames of all the vars and
                         udfs that X depends on. Examples:
                         - $x := $y + g($z)  :  $x --> ($y, g, $z)
                         - f { $y + g($z) }  :  f  --> ($y, g, $z)
                         Initially only direct dependencies are registered. The
                         graph is later expanded by the reorder_globals() method
                         to include transitive dependencies as well. Then, the
                         graph is used to sort thePrologVars so that vars are
                         initialized before they are referenced.
  prolog_vf_key        : During the translation of a variable or function decl
                         in the prolog, prolog_vf_key stores the normalized
                         qname of that variable or function (the actual format is
                         type_char + normalized_qname, where type_char is F or
                         V). It is used in building the thePrologDeps: if the
                         prolog_vf_key string is not the empty, then we know
                         that we are in the scope of a var or function decl, and
                         if that declaration refernces another var V or calls 
                         another function F, then we create a dependency between
                         the var or function specified by prolog_vf_key and V
                         or F.
  prolog_fn_decls      : List containing the normalized qname for each udf
                         declared in the prolog of this module. It is used by 
                         the reorder_globals() method.
  prolog_var_decls     : List containing the normalized qname for each variable
                         declared in the prolog of this module. It is used by 
                         the reorder_globals() method.

  tempvar_counter      : Counter used to generate names for internally generated
                         variables. The names are unique within this translator.

  nodestack            : If E is the expr that is currently being built, then
                         nodestack contains all the ancestors (or ancestor
                         place-holdres) of E in the expr tree.

  tstack               : Stack of the static types for some of the exprs in the
                         nodestack.

  hadBSpaceDecl        : Set to true if prolog has boundary space decl. Used to
                         check that such a decl does not appear more than once.
  hadBUriDecl          : Set to true if prolog has bas uri decl. Used to check
                         that such a decl does not appear more than once.
  hadConstrDecl        : Set to true if prolog has construction mode decl. Used
                         to check that such a decl does not appear more than once.
  hadCopyNSDecl        : Set to true if prolog has copy namespaces decl. Used to
                         check that such a decl does not appear more than once.
  hadEmptyOrdDecl      : Set to true if prolog has empty seq order decl. Used to
                         check that such a decl does not appear more than once.
  hadOrdModeDecl       : Set to true if prolog has doc order decl. Used to
                         check that such a decl does not appear more than once.

  xquery_fns_def_dot   : Set of the names of all build-in functions accepting
                         "." as their default arg. TODO: should be static

  theIsWSBoundaryStack : Saves true if the previous DirElemContent is a boundary
                         for whitespace (DirElemConstructor or EnclosedExpr).
  thePossibleWSContentStack: Saves the previous DirElemContent if it might be
                         bounded whitespace (if it contains whitespace and its
                         previous item is a whitespace boundary). It must be
                         checked if the next item is a whitespace boundary.

  op_concatenate       : Cached ptr to the function obj for the concat func 
  op_enclosed_expr     : Cached ptr to the function obj for the enclosed_expr op
  op_or                : Cached ptr to the function obj for the or op 
  fn_data              : Cached ptr to the function obj for the data func 

********************************************************************************/
class TranslatorImpl : public parsenode_visitor
{
public:
  friend expr_t translate_aux(const parsenode&, CompilerCB*, ModulesInfo*, set<string>, bool);

protected:

  int                                  xquery_version;

  CompilerCB                         * cb;

  ModulesInfo                        * minfo;

  set<string>                          mod_stack;
  string                               theModuleNamespace;
  string                               theModulePrefix;
  set<string>                          mod_import_ns_set;
  set<string>                          zorba_predef_mod_ns;

  set<string>                          schema_import_ns_set;

  static_context                     * sctx_p;

  static_context                     * export_sctx;

  rchandle<namespace_context>          ns_ctx;

  uint32_t                             print_depth;
  int                                  scope_depth;

  varref_t                             theDotVar;

  xqtref_t                             ctx_item_type;

  list<global_binding>                 thePrologVars;

  hashmap<strset_t>                    thePrologDeps;
  string                               prolog_vf_key;
  list<string>                         prolog_var_decls;
  list<function *>                     prolog_fn_decls;

  stack<short>                         sctxstack;
  checked_vector<unsigned int>         theScopes;

  int                                  tempvar_counter;

  stack<expr_t>                        nodestack;

  stack<xqtref_t>                      tstack; 

  list<function *>                     fn_decl_stack;

  stack<ValueIndex_t>                  indexstack;

  bool                                 hadBSpaceDecl;
  bool                                 hadBUriDecl;
  bool                                 hadConstrDecl;
  bool                                 hadCopyNSDecl;
  bool                                 hadDefNSDecl;
  bool                                 hadEmptyOrdDecl;
  bool                                 hadOrdModeDecl;
  bool                                 hadRevalDecl;

  stack<bool>                          theIsWSBoundaryStack;
  stack<const DirElemContent*>         thePossibleWSContentStack;

  set<string>                          xquery_fns_def_dot;

  const function                     * op_concatenate;
  const function                     * op_enclosed_expr;
  const function                     * op_or;
  const function                     * fn_data;
  const function                     * ctx_decl; 
  const function                     * ctx_set;
  const function                     * ctx_get;
  const function                     * ctx_exists;
  

TranslatorImpl(
    CompilerCB* aCompilerCB,
    ModulesInfo* minfo_,
    set<string> mod_stack_,
    bool isLibModule)
  :
  xquery_version (10000),  // fictious version 100.0 -- allow everything
  cb(aCompilerCB),
  minfo (minfo_),
  mod_stack (mod_stack_),
  sctx_p (aCompilerCB->m_sctx),
  export_sctx (NULL),
  ns_ctx(new namespace_context(sctx_p)),
  print_depth (0),
  scope_depth (0),
  tempvar_counter (1),
  hadBSpaceDecl (false),
  hadBUriDecl (false),
  hadConstrDecl (false),
  hadCopyNSDecl (false),
  hadDefNSDecl (false),
  hadEmptyOrdDecl (false),
  hadOrdModeDecl (false),
  hadRevalDecl (false)
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

  zorba_predef_mod_ns.insert (ZORBA_XQDOC_FN_NS);
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
  
  ctx_item_type = GENV_TYPESYSTEM.ITEM_TYPE_ONE;
}


/*******************************************************************************
  Pop the top n exprs from the nodestack and return the last expr that was popped.
********************************************************************************/
expr_t pop_nodestack (int n = 1) 
{
  ZORBA_ASSERT (n >= 0);

  rchandle<expr> e_h;

  for (; n > 0; --n) 
  {
    ZORBA_FATAL(! nodestack.empty(), "");
    e_h = nodestack.top();
    nodestack.pop();
#ifndef NDEBUG
    if (Properties::instance()->traceTranslator()) 
    {
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


/*******************************************************************************
  Assert that the top expr in the nodestack is a var_expr and pop it.
********************************************************************************/
varref_t pop_nodestack_var () 
{
  expr_t e = pop_nodestack ();
  assert (e == NULL || e->get_expr_kind () == var_expr_kind);
  return static_cast<var_expr *> (e.getp ());
}


/*******************************************************************************
  Return rchandle to the expr at the top of the nodestack, or NULL if the
  nodestack is empty.
********************************************************************************/
expr_t peek_nodestk_or_null () 
{
  return (nodestack.empty ()) ? expr_t (NULL) : peek_stack (nodestack);
}


/*******************************************************************************
  Check if the top expr in thenodestack is an axis_step, and if so return
  rchandle to it (but do not pop). Otherwise, raise error.
********************************************************************************/
rchandle<axis_step_expr> expect_axis_step_top () 
{
  rchandle<axis_step_expr> axisExpr = peek_nodestk_or_null().dyn_cast<axis_step_expr>();
  if (axisExpr == NULL) 
  {
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

********************************************************************************/
xqtref_t pop_tstack()
{
  return pop_stack(tstack); 
}


/*******************************************************************************
  Create new static context, make it the current one for the current module, and
  register it into the query-level sctx map.
********************************************************************************/
void push_scope() 
{
  // create a new static context for the new scope
  sctx_p = sctx_p->create_child_context(); 
 
  if (cb->theDebuggerCommons != NULL) 
  {
    // in debug mode, we remember all static contexts
    // this allows the debugger to introspect (during runtime)
    // all variables in scope
    sctxstack.push(cb->m_cur_sctx);
    cb->m_cur_sctx = cb->m_context_map->size() + 1;
    (*cb->m_context_map)[cb->m_cur_sctx] = sctx_p; 
  }
  else
  {
    // in non-debug mode, we need to make sure that the scoped
    // contexts are kept around for the compilation of this module.
    // The static context available at runtime will be the root context
    // in which the module is compiled. Keeping all contexts around during
    // runtime seems to be overhead.
    cb->m_sctx_list.push_back(sctx_p);
  }
  ++scope_depth;
}


/*******************************************************************************
  Make the parent of the current sctx be the current sctx for the current module.
********************************************************************************/
void pop_scope()
{
  if (cb->theDebuggerCommons != NULL) 
  {
    cb->m_cur_sctx = sctxstack.top();
    sctx_p = (*cb->m_context_map)[cb->m_cur_sctx];
    sctxstack.pop();
  }
  else
  {
    // pop one scope, howerver the static context is kept around in the m_sctx_list
    static_context *parent = (static_context *) sctx_p->get_parent ();
    sctx_p = parent;
  }
  --scope_depth;
}


/*******************************************************************************

********************************************************************************/
void push_elem_scope() 
{
  ns_ctx = new namespace_context(&*ns_ctx);
}


/*******************************************************************************

********************************************************************************/
void pop_elem_scope() 
{
  ns_ctx = ns_ctx->get_parent();
}


/*******************************************************************************
  Create a name to be used for an internally generated variable. The name is
  unique within this translator.
********************************************************************************/
xqpString tempname () 
{
  return "$$temp" + to_string(tempvar_counter++);
  }
  
    
/*******************************************************************************
  Create a var_expr for a variable with a given qname item, kind, and type
********************************************************************************/
varref_t create_var(
    const QueryLoc& loc,
    store::Item_t qname,
    var_expr::var_kind kind,
    xqtref_t type = NULL) 
{
  varref_t e = new var_expr(cb->m_cur_sctx, loc, kind, qname);

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

  
/*******************************************************************************
  Create a var_expr for a variable with a given qname, kind, and type.
  The given qname is resolved to a qname item. An error is raised if the
  resolution fails.
********************************************************************************/
varref_t create_var(
    const QueryLoc& loc,
    string varname,
    var_expr::var_kind kind, 
    xqtref_t type = NULL) 
{
  store::Item_t qname = sctx_p->lookup_var_qname (varname, loc);
  return create_var (loc, qname, kind, type);
}
  

/*******************************************************************************
  Create a var_expr for an internal variable with a given kind.
********************************************************************************/
  varref_t tempvar(const QueryLoc& loc, var_expr::var_kind kind)
{
  xqpString lname (tempname ());
  return create_var(loc, lname, kind);
}


/*******************************************************************************
  Create a binding in the given sctx between a var qname item and a var_expr.
  Raise error if a var with the same expanded qname item is already in the given
  sctx obj.
********************************************************************************/
void bind_var (varref_t e, static_context *sctx) 
{
  assert (sctx != NULL);

  store::Item_t qname = e->get_varname ();

  if (! sctx->bind_var(qname, e.getp()))
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


/*******************************************************************************
  Create a var_expr for a variable with a given qname item, kind, and type.
  Then, create a binding in the given sctx between the var qname item and the
  var_expr. Raise error if a var with the same expanded qname item is already
  in the given sctx obj.
********************************************************************************/
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


/*******************************************************************************
  Create a var_expr for a variable with a given qname item, kind, and type.
  Then, create a binding in the given sctx between the var qname item and the
  var_expr. Finally, push the var_expr to the nodestack. Raise error if a var
  with the same expanded qname is already in the given context.
********************************************************************************/
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



/*******************************************************************************
  Create a binding in the given sctx obj between the given (function qname item,
  arity) pair and the given function object. Raise error if such a binding
  exists already in the sctx.
********************************************************************************/
void bind_udf(
    store::Item_t qname,
    function *f,
    int nargs,
    static_context *sctx,
    const QueryLoc& loc) 
  {
  if (! sctx->bind_fn (qname, f, nargs))
    ZORBA_ERROR_LOC_PARAM(XQST0034, loc,
                          qname->getStringValue(),
                          loc.getFilenameBegin());
      }
  

/*******************************************************************************
  Create a binding between the given (function qname item, arity) pair and the
  given function object. The binding is created in (a) the current sctx of this 
  module, (b) the query-level sctx that gathers all declaration of functions and
  variables from all modules, and (c) the export_sctx (if any). Raise error if 
  such a binding exists already in any of these sctxs.
********************************************************************************/
void bind_udf (store::Item_t qname, function *f, int nargs, const QueryLoc& loc) 
  {
  bind_udf (qname, f, nargs, sctx_p, loc);
  bind_udf (qname, f, nargs, minfo->globals.get (), loc);

  if (export_sctx != NULL) 
    {
    bind_udf (qname, f, nargs, export_sctx, loc);
    }
    }
  

/*******************************************************************************
  Create an fn:concatenate() expr
********************************************************************************/
fo_expr *create_seq (const QueryLoc& loc) 
{
  return fo_expr::create_seq (cb->m_cur_sctx, loc);
}
  

/*******************************************************************************
  Wrap the given expr in an fn:data() function
********************************************************************************/
expr_t wrap_in_atomization (expr_t e) 
{
  return new fo_expr (cb->m_cur_sctx,
                      e->get_loc (),
                      CACHED (fn_data, LOOKUP_FN ("fn", "data", 1)),
                      e);
    }


/*******************************************************************************
  Wrap the given expr in one of the following functions:
  fn:sort-distinct-nodes-asc-or-atomics, or
  fn:sort-distinct-nodes-desc-or-atomics, or
  fn:sort-distinct-nodes-asc, or
  fn:sort-distinct-nodes-desc
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
  dos = new fo_expr(cb->m_cur_sctx,
                    expr->get_loc(),
                    sctx_p->lookup_builtin_fn(funcName.str(), 1));
  dos->add(expr);
  return &*dos;
}


/*******************************************************************************
  Create a LET clause for the given LET variable "lv", with the given expr "e" as
  its defining expression.
********************************************************************************/
let_clause_t wrap_in_letclause(expr_t e, varref_t lv) 
{
  assert (lv->get_kind () == var_expr::let_var);
  return new let_clause(cb->m_cur_sctx, e->get_loc(), lv, e.getp());
}


/*******************************************************************************
  Create a var_expr for a LET var with the given qname and add that var to the
  local sctx obj. Then, create a LET clause for this new var_expr, with the given
  expr "e" as its defining expression.
********************************************************************************/
let_clause_t wrap_in_letclause(expr_t e, const QueryLoc& loc, string name) 
{
  return wrap_in_letclause(e, bind_var(loc, name, var_expr::let_var));
}


/*******************************************************************************
  Create a var_expr for a new internal LET var and then create a LET clause for
  this new var_expr, with the given expr "e" as its defining expression. NOTE:
  the internal var is not registered in the sctx.
********************************************************************************/
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

  return new for_clause(cb->m_cur_sctx, e->get_loc(), fv, e, pv);
}


/*******************************************************************************
  Create var_exprs for a FOR var with the given qname and its associated POS
  var, whose qname is also given. Then add those vars to the local sctx obj.
  Then, create a FOR clause for these new var_exprs, with the given expr as the
  defining expression of the FOR var.
********************************************************************************/
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


/*******************************************************************************
  Create a var_expr for a new internal FOR var and then create a FOR clause for
  this new var_expr, with the given expr as its defining expression. NOTE:
  the internal var is not registered in the sctx.
********************************************************************************/
for_clause_t wrap_in_forclause(expr_t expr, bool add_posvar) 
{
  varref_t fv = tempvar(expr->get_loc(), var_expr::for_var);

  varref_t pv = (add_posvar ? tempvar(expr->get_loc(), var_expr::pos_var) : 
                                varref_t (NULL));
  return wrap_in_forclause(expr, fv, pv);
}


/*******************************************************************************
  Create a flwor expr with a single let clause and a return expr. In particular,
  is built:

  let $lv := domExpr
  return retExpr

********************************************************************************/
rchandle<flwor_expr> wrap_in_let_flwor(expr_t domExpr, varref_t lv, expr_t retExpr) 
{
  rchandle<flwor_expr> fe = new flwor_expr(cb->m_cur_sctx, lv->get_loc(), false);

  fe->add_clause(wrap_in_letclause (domExpr, lv));

  fe->set_return_expr(retExpr);

  return fe;
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

  rchandle<flwor_expr> flworExpr = new flwor_expr(cb->m_cur_sctx, loc, false);

  if (withContextSize) 
  {
    // create a LET var equal to the seq returned by the input epxr
    let_clause_t lcInputSeq = wrap_in_letclause(inputExpr);

    // compute the size of the input seq
    rchandle<fo_expr> countExpr = new fo_expr(cb->m_cur_sctx, loc, LOOKUP_FN("fn", "count", 1));
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
   In this expression branch, we create the debugger expressions.
   Furthermore, we create an entry for all expressions in the map
   of breakable expressions. This is done here, in order to be able,
   to set breakpoints of expressions which are not translated at the
   beginning (e.g. inside functions).
********************************************************************************/
void wrap_in_debugger_expr (expr_t& aExpr) {
  if (cb->theDebuggerCommons != NULL) {
    DebugLocation_t lLocation;
    std::auto_ptr<debugger_expr> lExpr(new debugger_expr(cb->m_cur_sctx,
                                                         aExpr->get_loc(), 
                                                         aExpr, thePrologVars));

    lLocation.theFileName = aExpr->get_loc().getFilename();
    lLocation.theLineNumber = aExpr->get_loc().getLineno();
    lLocation.theQueryLocation = aExpr->get_loc();
    cb->theDebuggerCommons->theLocationMap.insert(
      std::pair<DebugLocation_t, bool>(lLocation, false));

    // retrieve all variables that are in the current scope
    typedef std::vector<var_expr_t> VarExprVector;
    VarExprVector lAllInScopeVars;
    sctx_p->getVariables(lAllInScopeVars);

    // for each var, create a eval_var and add it to
    // the debugger expression
    for (VarExprVector::iterator lIter = lAllInScopeVars.begin();
         lIter != lAllInScopeVars.end(); ++lIter) {
      varref_t ve(new var_expr(*(*lIter).dyn_cast<var_expr>()));
      ve->set_kind(var_expr::eval_var);

     lExpr->add_var(eval_expr::eval_var(&*ve, NULL));

    }

    aExpr = lExpr.release();
  }
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
  Create declaration/initialization exprs for each prolog variable of this 
  module and put these exprs in minfo->init_exprs. Then create a sequential
  expr with its children being all the init exprs in minfo->init_exprs  plus
  the given expr "e" as its last child. 

  The method is called at the end of the translation of each module. The returned
  expr is the result of the module translation. For the root module, the "e" expr
  is the result of translating the QueryBody. For non-root modules, "e" is an
  empty fn:concatenate() expr. 
********************************************************************************/
expr_t wrap_in_globalvar_assign(expr_t e) 
{
  for (list<global_binding>::iterator i = thePrologVars.begin();
      i != thePrologVars.end();
      i++)
  {
     declare_var(*i, minfo->init_exprs);
  }

  expr_t preloadedInitExpr = static_cast<static_context*>(sctx_p->get_parent())->
                             get_query_expr();

  if (!minfo->init_exprs.empty() || preloadedInitExpr != NULL) 
  {
    sequential_expr* seqExpr =
    new sequential_expr(cb->m_cur_sctx, e->get_loc(), minfo->init_exprs, e);

    if (preloadedInitExpr)
      seqExpr->push_front(preloadedInitExpr);

    return seqExpr;
  }
  else
  {
  return e;
}
}


/*******************************************************************************
  Create declaration/initialization exprs for a prolog or block-local variable.

  The following 4 cases are considered:
  1. non-extrernal var with init expr, 
  2. external var with init expr,
  3. non-extrernal var without init expr,
  4. external var without init expr,

  The corresponding expr created here (and added to stmts) are:
  
  1. sequential(ctxvar-declare(varName), ctxvar-assign(varName, initExpr))

  2. if (ctxvar-exists(varName)) 
     then fn:concatenate()
     else sequential(ctxvar-declare(varName), ctxvar-assign(varName, initExpr))

  3. ctxvar-declare(varName)

  4. nothing

  If the var declaration includes a type declaration, then the following expr
  is also created and added to stmts:

  treat(ctxvariable(varName), type)
********************************************************************************/
void declare_var(const global_binding& b, std::vector<expr_t>& stmts) 
{
  CACHED (ctx_decl, LOOKUP_OP1 ("ctxvar-declare"));
  CACHED (ctx_set, LOOKUP_OP2 ("ctxvar-assign"));

  varref_t var = b.first;
  xqtref_t var_type = var->get_type ();
  expr_t expr = b.second;

  xqpStringStore dot (".");

  expr_t qname_expr = new const_expr(cb->m_cur_sctx,
                                     var->get_loc(),
                                     var->get_varname()->getStringValue()->equals(&dot) ?
                                     "." : dynamic_context::var_key(&*var));

  expr_t decl_expr = new fo_expr(cb->m_cur_sctx,
                                 var->get_loc(),
                                 ctx_decl,
                                 qname_expr->clone());
 
  if (expr != NULL) 
  {
    if (expr->is_updating())
      ZORBA_ERROR_LOC(XUST0001, expr->get_loc());

    expr = new fo_expr (cb->m_cur_sctx,
                        var->get_loc(),
                        ctx_set,
                        qname_expr->clone(),
                        expr);

    expr = new sequential_expr(cb->m_cur_sctx, var->get_loc(), decl_expr, expr);

    if (b.is_extern()) 
    {
      CACHED (ctx_exists, LOOKUP_OP1 ("ctxvar-exists"));
      expr_t exists_expr = new fo_expr(cb->m_cur_sctx,
                                       var->get_loc(),
                                       ctx_exists,
                                       qname_expr->clone());

      expr = new if_expr (cb->m_cur_sctx,
                          var->get_loc(),
                          exists_expr,
                          create_seq(var->get_loc()),
                          expr);
    }

    stmts.push_back(expr);
  }
  else 
  {
    if (! b.is_extern())
      stmts.push_back(decl_expr);
  }

  if (var_type != NULL && (b.is_extern() || b.second != NULL)) 
  {
    // check type for vars that are external or have an init expr
    CACHED (ctx_get, LOOKUP_OP1("ctxvariable"));

    expr_t get = new fo_expr(cb->m_cur_sctx,
                             var->get_loc(),
                             ctx_get,
                             qname_expr->clone());

    stmts.push_back(new treat_expr(cb->m_cur_sctx,
                                   var->get_loc(),
                                   get,
                                   var->get_type(),
                                   XPTY0004));
  }
}


/*******************************************************************************

********************************************************************************/
expr_update_t update_type_anding(
    expr_update_t lType1, 
    expr_update_t lType2, 
    const QueryLoc& aLoc)
{
  switch(lType1)
  {
  case VACUOUS_EXPR:
  {
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
    break;
  }
  case SIMPLE_EXPR:
  {
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
    break;
  }
  case UPDATE_EXPR:
  {
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
    break;
  }
  default:
    ZORBA_ASSERT(false);
  }
  return SIMPLE_EXPR;
}
  

/*******************************************************************************

********************************************************************************/
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



/*******************************************************************************

********************************************************************************/
void *begin_visit (const exprnode& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const exprnode& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Module, VersionDecl, MainModule, LibraryModule, ModuleDecl                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  [1] Module ::= 	VersionDecl? (LibraryModule | MainModule)
********************************************************************************/
void *begin_visit (const Module& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const Module& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/******************************************************************************
  [2] VersionDecl ::= XQUERY ENCODING STRING_LITERAL SEMI |
                      XQUERY VERSION STRING_LITERAL SEMI |
                      XQUERY VERSION STRING_LITERAL ENCODING STRING_LITERAL SEMI
********************************************************************************/
void *begin_visit (const VersionDecl& v) 
{
  TRACE_VISIT ();
  if (! xqp_string (v.get_encoding ()).matches ("^[A-Za-z]([A-Za-z0-9._]|[-])*$", ""))
    ZORBA_ERROR_LOC (XQST0087, loc);

  StaticContextConsts::xquery_version_t ver = parse_xquery_version(&v);
  if (ver == StaticContextConsts::xquery_version_unknown)
    ZORBA_ERROR_LOC(XQST0031, loc);

  sctx_p->set_xquery_version(ver);
  return no_state;
}

void end_visit (const VersionDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [3] MainModule ::= Prolog  QueryBody | QueryBody
********************************************************************************/
void *begin_visit (const MainModule & v) 
{
  TRACE_VISIT ();

  theDotVar = bind_var(loc, DOT_VARNAME, var_expr::prolog_var, ctx_item_type);
  
  sctx_p->set_xquery_version(parse_xquery_version(v.get_version_decl().getp()));

  return no_state;
}

void end_visit (const MainModule & v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [4] LibraryModule ::= ModuleDecl  Prolog
********************************************************************************/
void *begin_visit (const LibraryModule& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const LibraryModule& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  sctx_p->set_xquery_version(parse_xquery_version(v.get_version_decl().getp()));

  // Note: There is no real reason to put the expr returned by 
  // wrap_in_globalvar_assign() in the nodestack. The only reason is for the
  // translate_aux() function to be able to pick that expr from the stack in
  // order to print it.
  nodestack.push(wrap_in_globalvar_assign(create_seq(loc)));
}


/******************************************************************************
  [5] ModuleDecl ::= MODULE NAMESPACE  NCNAME  EQ  URI_LITERAL  SEMI
********************************************************************************/
void *begin_visit (const ModuleDecl& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ModuleDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  theModulePrefix = v.get_prefix ();
  theModuleNamespace = v.get_target_namespace ();

  if (theModuleNamespace.empty ())
    ZORBA_ERROR_LOC (XQST0088, loc);

  if (theModulePrefix == "xml" || theModulePrefix == "xmlns")
    ZORBA_ERROR_LOC (XQST0070, loc);

  sctx_p->bind_ns(theModulePrefix, theModuleNamespace);

  static_context_t lTmpCtx;
  bool found = minfo->mod_sctx_map.get(sctx_p->entity_retrieval_url(), lTmpCtx);
  ZORBA_ASSERT (found);

  export_sctx = lTmpCtx.getp();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Prolog                                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  [6] Prolog ::= SIND_DeclList  VFO_DeclList

  [6a] SIND_DeclList ::= SIND_Decl Separator | SIND_DeclList SIND_Decl Separator

  [6b] VFO_DeclList ::= VFO_Decl Separator | VFO_DeclList VFO_Decl Separator

  [6c] SIND_Decl ::= Setter | NamespaceDecl | DefaultNamespaceDecl | Import

  [6d] VFO_Decl ::= VarDecl | ContextItemDecl | FunctionDecl | IndexDecl | OptionDecl
********************************************************************************/
void *begin_visit (const Prolog& v) 
{
  TRACE_VISIT ();
  return no_state;
  }

void end_visit (const Prolog& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [6a] SIND_DeclList ::= SIND_Decl Separator | SIND_DeclList SIND_Decl Separator
********************************************************************************/
void *begin_visit (const SIND_DeclList& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const SIND_DeclList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [6c] SIND_Decl ::= Setter | NamespaceDecl | DefaultNamespaceDecl | Import
********************************************************************************/


/******************************************************************************

  [7] Setter ::= BoundarySpaceDecl |
                 OrderingModeDecl |
                 EmptyOrderDecl |
                 CopyNamespacesDecl |
                 DecimalFormatDecl |
                 DefaultCollationDecl |
                 BaseURIDecl |
                 ConstructionDecl |

********************************************************************************/


/*******************************************************************************
  [11] BoundarySpaceDecl ::= DECLARE_BOUNDARY_SPACE  ( PRESERVE | STRIP )
********************************************************************************/
void *begin_visit (const BoundarySpaceDecl& v) 
{
  TRACE_VISIT ();
  CHK_SINGLE_DECL (hadBSpaceDecl, XQST0068);
  sctx_p->set_boundary_space_mode(v.get_boundary_space_mode());
  return NULL;
}

void end_visit (const BoundarySpaceDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [14] OrderingModeDecl ::= DECLARE_ORDERING  ( ORDERED | UNORDERED )
********************************************************************************/
void *begin_visit (const OrderingModeDecl& v) 
{
  TRACE_VISIT ();
  CHK_SINGLE_DECL (hadOrdModeDecl, XQST0065);
  sctx_p->set_ordering_mode(v.get_mode());
  return NULL;
}


void end_visit (const OrderingModeDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [15] EmptyOrderDecl ::= DECLARE_DEFAULT_ORDER  EMPTY_GREATEST |
                          DECLARE_DEFAULT_ORDER  EMPTY_LEAST
********************************************************************************/
void *begin_visit (const EmptyOrderDecl& v) 
{
  TRACE_VISIT ();
  CHK_SINGLE_DECL (hadEmptyOrdDecl, XQST0069);
  sctx_p->set_order_empty_mode(v.get_mode());
  return no_state;
}

void end_visit (const EmptyOrderDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [16] CopyNamespacesDecl ::= DECLARE_COPY_NAMESPACES PreserveMode COMMA InheritMode

  [19] PreserveMode ::= "preserve" | "no-preserve"
  [20] InheritMode ::=  "inherit" | "no-inherit"
********************************************************************************/
void *begin_visit (const CopyNamespacesDecl& v) 
{
  TRACE_VISIT ();
  CHK_SINGLE_DECL (hadCopyNSDecl, XQST0055);
  return no_state;
}

void end_visit (const CopyNamespacesDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
 sctx_p->set_inherit_mode  (v.get_inherit_mode ());
 sctx_p->set_preserve_mode (v.get_preserve_mode ());
}


/******************************************************************************
  [17] DecimalFormatDecl ::= "declare"
                             (("decimal-format" QName) | ("default" "decimal-format"))
                             (DFPropertyName "=" StringLiteral)*

  [18] DFPropertyName ::= "decimal-separator" | "grouping-separator" |
                          "infinity" | "minus-sign" | "NaN" | "percent" |
                          "per-mille" | "zero-digit" | "digit" |
                          "pattern-separator"
********************************************************************************/
void *begin_visit (const DecimalFormatNode& v) 
{
  // cout << "Got DecimalFormat declaration: " << std::endl;
  TRACE_VISIT ();

  store::Item_t qname;
  if (!v.is_default)
  {
    string::size_type pos = v.format_name.find(":");

    xqpStringStore_t prefix =
    new xqpStringStore(v.format_name.substr(0, pos == string::npos ? 0 : pos));

    string name = v.format_name.substr(pos == string::npos ? 0 : pos+1);

    xqpStringStore_t ns;
    ns_ctx->findBinding(prefix, ns);

    GENV_ITEMFACTORY->createQName(qname, ns->c_str(), prefix->c_str(), name.c_str());
  }
  
  DecimalFormat_t df = new DecimalFormat(v.is_default, qname, v.param_list);
  sctx_p->add_decimal_format(df);
    
  return no_state;
}

void end_visit (const DecimalFormatNode& v, void* /*visit_state*/) 
{
  // std::cout << "end_visit() Got DecimalFormat declaration: " << std::endl;
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [21] DefaultCollationDecl ::=	DECLARE_DEFAULT_COLLATION  URI_LITERAL
********************************************************************************/
void *begin_visit (DefaultCollationDecl const& v) 
{
  TRACE_VISIT ();
  string uri = v.get_collation();
  sctx_p->set_default_collation_uri(uri);
  return NULL;
}

void end_visit (const DefaultCollationDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [22] BaseURIDecl ::= DECLARE_BASE_URI  URI_LITERAL
********************************************************************************/
void *begin_visit (const BaseURIDecl& v) 
{
  TRACE_VISIT ();
  CHK_SINGLE_DECL (hadBUriDecl, XQST0032);
  try 
  {
    sctx_p->set_baseuri(v.get_base_uri());
  }
  catch (error::ZorbaError&) 
  {
    // assume it's a relative uri and we will resolve it later.
    // It's currently a problem if the uri is absolute but invalid
  }
  return NULL;
}

void end_visit (const BaseURIDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [31] ConstructionDecl ::= DECLARE_CONSTRUCTION  PRESERVE
                            DECLARE_CONSTRUCTION  STRIP
********************************************************************************/
void *begin_visit (const ConstructionDecl& v) 
{
  TRACE_VISIT ();
  CHK_SINGLE_DECL (hadConstrDecl, XQST0067);
  sctx_p->set_construction_mode(v.get_mode());
  return NULL;
}

void end_visit (const ConstructionDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [10] NamespaceDecl ::= ::= DECLARE_NAMESPACE  NCNAME  EQ  URI_LITERAL
********************************************************************************/
void *begin_visit (const NamespaceDecl& v) 
{
  TRACE_VISIT ();

  xqp_string pre = v.get_prefix (), uri = v.get_uri ();
  if (pre == "xml" || pre == "xmlns" || uri == XML_NS)
    ZORBA_ERROR_LOC (XQST0070, loc);

  sctx_p->bind_ns (pre, uri);

  return NULL;
}

void end_visit (const NamespaceDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [12] DefaultNamespaceDecl ::= DECLARE DEFAULT ELEMENT NAMESPACE URILiteral |
                                DECLARE DEFAULT FUNCTION NAMESPACE URILiteral
********************************************************************************/
void *begin_visit (DefaultNamespaceDecl const& v) 
{
  TRACE_VISIT ();
  switch (v.get_mode()) 
  {
  case ParseConstants::ns_element_default:
    sctx_p->set_default_elem_type_ns (v.get_default_namespace ());
    break;
  case ParseConstants::ns_function_default:
    sctx_p->set_default_function_namespace (v.get_default_namespace ());
    break;
  }
  return NULL;
}

void end_visit (const DefaultNamespaceDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [8] Import ::= SchemaImport | ModuleImport
********************************************************************************/


/*******************************************************************************
  [23] SchemaImport ::= "import" "schema" SchemaPrefix? URILiteral
                        ("at"  URILiteralList)?
********************************************************************************/
void *begin_visit (const SchemaImport& v) 
{
  TRACE_VISIT ();

#ifndef ZORBA_NO_XMLSCHEMA

  SchemaPrefix* prefix = &*v.get_prefix();
  string target_ns = v.get_uri();

  if (! schema_import_ns_set.insert(target_ns).second)
    ZORBA_ERROR_LOC (XQST0058, loc);

  if (prefix != NULL) 
  {
    if (target_ns.size() == 0)
      ZORBA_ERROR_LOC_PARAM(XQST0057, loc,
                            "(no target namespace uri specified)",
                            target_ns);

    string pfx = prefix->get_prefix();

    if (pfx == "xml" || pfx == "xmlns")
      ZORBA_ERROR_LOC (XQST0070, loc);

    if (prefix->get_default_bit()) 
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
      // If current uri is relative, turn it to an absolute one, using the
      // base uri from the sctx.
      string at = sctx_p->resolve_relative_uri((*atlist)[i], xqpString());

      store::Item_t lAtURIItem;
      ITEM_FACTORY->createAnyURI(lAtURIItem, at.c_str());
      ZORBA_ASSERT(lAtURIItem != NULL);
      lAtURIList.push_back(lAtURIItem);
#if 0
      string pfx = prefix == NULL ? "" : prefix->get_prefix();
      cout << "SchemaImport: " << pfx << " : " << target_ns
           << " @ " << at << endl;
      cout << " Context: " << CTXTS << "\n";
#endif
    }
  }
  
  InternalSchemaURIResolver* lSchemaResolver = sctx_p->get_schema_uri_resolver();
  
  try 
  {
    // If lAtURIList is empty, return lTargetNamespace, else return the 1st
    // uri item from lAtURIList.
    store::Item_t lSchemaUri = lSchemaResolver->resolve(lTargetNamespace,
                                                        lAtURIList,
                                                        sctx_p);

    // Create a Schema obj and register it in the typemanger, if the typemanager
    // does not have a schema obj already
    CTXTS->initializeSchema();
    Schema* schema_p = CTXTS->getSchema();

    std::string lTmp(lSchemaUri->getStringValue()->c_str());

    // Make Xerxes load and parse the xsd file and create a Xerces
    // representaton of it.
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


/******************************************************************************
  [23a] URLLiteralList ::= URI_LITERAL | URILiteralList  COMMA  URI_LITERAL
********************************************************************************/
void *begin_visit (const URILiteralList& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const URILiteralList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/******************************************************************************
  [24] SchemaPrefix ::=	("namespace" NCName "=") | ("default" "element" "namespace")
********************************************************************************/
void *begin_visit (const SchemaPrefix& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const SchemaPrefix& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [25] ModuleImport ::= "import" "module" ("namespace" NCName "=")? URILiteral
                        ("at" URILiteralList)?
********************************************************************************/
void *begin_visit (const ModuleImport& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const ModuleImport& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  string pfx = v.get_prefix ();
  string target_ns = v.get_uri ();

  // The namespace prefix specified in a module import must not be xml or xmlns
  // [err:XQST0070]
  if (pfx == "xml" || pfx == "xmlns")
    ZORBA_ERROR_LOC (XQST0070, loc);

  // The first URILiteral in a module import must be of nonzero length [err:XQST0088]
  if (target_ns.empty ())
    ZORBA_ERROR_LOC (XQST0088, loc);

  // It is a static error [err:XQST0047] if more than one module import in a
  // Prolog specifies the same target namespace
  if (! mod_import_ns_set.insert (target_ns).second)
    ZORBA_ERROR_LOC (XQST0047, loc);

  // The namespace prefix specified in a module import must not be the same as
  // any namespace prefix bound  in the same module by another module import, 
  // a schema import, a namespace declaration, or a module declaration with a
  // different target namespace [err:XQST0033].
  if (! (pfx.empty() || (pfx == theModulePrefix && target_ns == theModuleNamespace) ) ) 
  {
    try 
    {
      sctx_p->bind_ns(pfx, target_ns, XQST0033);
    }
    catch (error::ZorbaError& e)
    {
      // rethrow with current location
      ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
    }
  }

  rchandle<URILiteralList> ats = v.get_uri_list ();

  // Handle pre-defined modules
  if (ats == NULL && zorba_predef_mod_ns.find (target_ns) != zorba_predef_mod_ns.end ())
    return;

  // Create a list of absolute uris identifying the locations of modules in
  // the target ns. If there are no "at" clauses, use the target namespace.
  vector<xqpStringStore_t> lURIs;
  if (ats == NULL || ats->size () == 0) 
  {
    lURIs.push_back(xqp_string(target_ns).getStore());
  }
  else
  {
    for (int i = 0; i < ats->size(); ++i) 
    {
      // If current uri is relative, turn it to an absolute one, using the
      // base uri from the sctx.
      lURIs.push_back(sctx_p->resolve_relative_uri((*ats)[i], xqp_string()).getStore());
    }
  }

  // Get the module URI resolver to be used for retrieving the istream of the
  // module. This can either be Zorba's standard implementation or one that has
  // been provided by the user
  InternalModuleURIResolver* lModuleResolver = sctx_p->get_module_uri_resolver();

  // Take each of the URIs collected above and import the module's functions
  // and variables into the current static context.
  for (vector<xqpStringStore_t>::iterator lIter = lURIs.begin();
       lIter != lURIs.end();
       ++lIter) 
  {
    // Get the location uri for the module to import and create a uri item
    // out of it.
    xqpStringStore_t resolveduri = *lIter; 
    store::Item_t    aturiitem = NULL;
    if (!GENV_ITEMFACTORY->createAnyURI(aturiitem, resolveduri))
      ZORBA_ERROR_LOC_DESC_OSS(XQST0046, loc, "URI is not valid " << resolveduri);

    // Make sure that there are no cycles in a chain of module imports.
    set<string> mod_stk1 = mod_stack;
    if (! mod_stk1.insert(resolveduri->str()).second)
      ZORBA_ERROR_LOC (XQST0073, loc);
    
    string imported_ns; // the target namespace of the imported module
    static_context_t imported_sctx = NULL;

    // Check whether we have already imported a module from the current location
    // uri. If so, check that the target ns of what we imported before is the
    // same as what we are trying to import now.
    if (minfo->mod_ns_map.get(resolveduri->str(), imported_ns)) 
    {
      bool found = minfo->mod_sctx_map.get(resolveduri->str(), imported_sctx);
      ZORBA_ASSERT (found);

      if (imported_ns != target_ns)
        ZORBA_ERROR_LOC_PARAM (XQST0059, loc, resolveduri, target_ns);
    } 

    // We are importing a module for the 1st time.
    else 
    {
      // Open the file containing the imported module. We get the ownership of
      // the input stream.
      // TODO: we have to find a way to tell user defined resolvers when their
      // input stream can be freed. The current solution might leed to problems
      // on Windows.
      xqpStringStore lFileUri;
      auto_ptr<istream> modfile(lModuleResolver->resolve(aturiitem, sctx_p, &lFileUri));

      if (modfile.get () == NULL || ! *modfile) 
      {
        ZORBA_ERROR_LOC_PARAM (XQST0059, loc, resolveduri, target_ns);
      }

      // Create a CompilerCB for the imported module as a copy of the importing
      // module's CompilerCB. Copying is needed for configuration settings,
      // error manager, and debugger
      CompilerCB mod_ccb (*cb);

      // Get the query-level sctx. This is the user-specified sctx (if any) or
      // the zorba default (root) sctx (if no user-specified sctx).
      static_context_t independent_sctx = 
      static_cast<static_context *>(minfo->topCompilerCB->m_sctx->get_parent());

      // Create the root sctx for the imported module as a child of the
      // query-level sctx. Register this sctx in the query-lever sctx map.
      mod_ccb.m_sctx = independent_sctx->create_child_context ();
      mod_ccb.m_cur_sctx = minfo->topCompilerCB->m_context_map->size() + 1;
      mod_ccb.m_sctx->set_entity_retrieval_url(resolveduri->str());

      (*minfo->topCompilerCB->m_context_map)[mod_ccb.m_cur_sctx] = mod_ccb.m_sctx;

      // Create an sctx where the imported module is going to register all the
      // variable and function declarations that appear in its prolog. After the
      // translation of the imported module is done, this sctx will be merged
      // with the sctx of the importing module.
      imported_sctx = independent_sctx->create_child_context();

      // Register the imported_sctx in minfo->mod_sctx_map so that it is
      // accessible by both the importing and the imported modules.
      minfo->mod_sctx_map.put(resolveduri->str(), imported_sctx);

      // Parse the imported module
      XQueryCompiler xqc (&mod_ccb);
      xqpString lFileName(aturiitem->getStringValue());
      rchandle<parsenode> ast = xqc.parse (*modfile, lFileName);

      // Get the target namespace that appears in the module declaration
      // of the imported module and check that this ns is the same as the
      // target ns in the module import statement.
      // Also make sure that the imported module is a library module
      LibraryModule *mod_ast = dynamic_cast<LibraryModule *> (&*ast);
      if (mod_ast == NULL)
        ZORBA_ERROR_LOC_PARAM (XQST0059, loc, resolveduri, target_ns);

      imported_ns = mod_ast->get_decl()->get_target_namespace();
      
      if (imported_ns.empty())
        ZORBA_ERROR_LOC(XQST0088, loc);

      if (imported_ns != target_ns)
        ZORBA_ERROR_LOC_PARAM(XQST0059, loc, resolveduri, target_ns);

      // translate the imported module
      translate_aux(*ast, &mod_ccb, minfo, mod_stk1, true);

      // Register the mapping between the current location uri and the
      // target namespace.
      minfo->mod_ns_map.put(resolveduri->str(), imported_ns);
    }

    // Merge the exported sctx of the imported module into the sctx of the
    // current module. Note: We catch duplicate functions / vars in 
    // minfo->globals. We can safely ignore the return value. We might even
    // be able to assert() here (not sure though).
    sctx_p->import_module(imported_sctx.getp());

  } // for (vector<xqpStringStore_t>::iterator lIter = lURIs.begin();
}


/*******************************************************************************
  [6b] VFO_DeclList ::= VFO_Decl Separator | VFO_DeclList VFO_Decl Separator

  [6d] VFO_Decl ::= VarDecl | ContextItemDecl | FunctionDecl | IndexDecl | OptionDecl
********************************************************************************/
void *begin_visit (const VFO_DeclList& v) 
{
  TRACE_VISIT ();

  // Function declaration translation must be done in two passes because of
  // mutually recursive functions and also because the defining expr of a declared
  // var may reference a function that is declared after the var. So, here's the
  // 1st pass; it translates the type declarations for the params and return value
  // and then creates the udf object and binds it in the sctx. The second pass
  // happens when accept() is called on each individual FunctionDecl node in
  // the list.

  for (vector<rchandle<parsenode> >::const_iterator it = v.begin();
       it != v.end();
       ++it)
  {
    const FunctionDecl* func_decl = it->dyn_cast<FunctionDecl> ().getp ();

    // skip variable and option declarations.
    if (func_decl == NULL)
      continue;

    const QueryLoc& loc = func_decl->get_location();

    rchandle<ParamList> params = func_decl->get_paramlist();
    if (params == NULL)
      params = new ParamList(loc);

    int nargs = params->size();

    // Translate the type declarations for the args and the return value of the
    // udf and put the resulting types in the arg_types vector.
    vector<xqtref_t> arg_types;

    for (vector<rchandle<Param> >::const_iterator it = params->begin ();
         it != params->end ();
         ++it)
    {
      const Param* param = (*it).getp ();
      const SequenceType* param_type = param->get_typedecl().getp ();
      if (param_type == NULL) 
      {
        arg_types.push_back (GENV_TYPESYSTEM.ITEM_TYPE_STAR);
}
      else 
      {
        param_type->accept(*this);
        arg_types.push_back(pop_tstack());
      }
    }

    xqtref_t return_type = GENV_TYPESYSTEM.ITEM_TYPE_STAR;
    if (func_decl->get_return_type() != NULL)  
{
      func_decl->get_return_type()->accept(*this);
      return_type = pop_tstack();
}

    // Expand the function qname (error is raised if qname resolution fails).
    store::Item_t qname = sctx_p->lookup_fn_qname(func_decl->get_name()->get_prefix(),
                                                  func_decl->get_name()->get_localname(),
                                                  func_decl->get_name()->get_location());
    {
      xqp_string ns = qname->getNamespace();

      //function must be declared in a non-NULL namespace
      if(ns.empty())
        ZORBA_ERROR_LOC (XQST0060, loc);

      if (ns == XQUERY_FN_NS || ns == XML_NS || ns == XML_SCHEMA_NS || ns == XSI_NS)
        ZORBA_ERROR_LOC_PARAM (XQST0045,
                               func_decl->get_location(),
                               qname->getLocalName()->str(), "");

      // In a module, all exports must be inside the target ns
      if (! theModuleNamespace.empty () && ns != theModuleNamespace)
        ZORBA_ERROR_LOC (XQST0048, loc);
}

    // Create the function object.
    signature sig(qname, arg_types, return_type);

    rchandle<function> f;

    switch(func_decl->get_type()) 
    {
    case ParseConstants::fn_extern_update:
    case ParseConstants::fn_extern:
    case ParseConstants::fn_extern_sequential:
    {
      StatelessExternalFunction* ef =
      sctx_p->lookup_stateless_external_function(func_decl->get_name()->get_prefix(),
                                                 func_decl->get_name()->get_localname());
      // The external function must be registered already in the static context
      // via the StaticContextImpl::registerStatelessExternalFunction() user api.
      if (ef == NULL) 
      {
        ZORBA_ERROR_LOC_PARAM(XQP0028_FUNCTION_IMPL_NOT_FOUND,
                              loc,
                              qname->getNamespace()->str(),
                              qname->getLocalName()->str());
}

      ZORBA_ASSERT(ef != NULL);

      bool updating = (func_decl->get_type() == ParseConstants::fn_extern_update);

      f = new stateless_external_function_adapter(sig, ef, updating);
      break;
}
    case ParseConstants::fn_sequential:
    case ParseConstants::fn_update:
    case ParseConstants::fn_read: 
    {
      f = new user_function(loc,
                            sig,
                            NULL, // no body for now
                            func_decl->get_type(),
                            func_decl->deterministic);
      break;
    }
    default:
      ZORBA_ASSERT(false);
    }

    // Create bindings between (function qname item, arity) and function obj
    // in the current sctx of this module and, if this is a lib module, in its
    // export sctx as well.
    bind_udf(qname, f, nargs, loc);
}

  return no_state;
}


void end_visit (const VFO_DeclList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  if (Properties::instance()->reorderGlobals())
    reorder_globals();
  // else cout << "Warning: global var reordering disabled\n";
}


/*******************************************************************************
  [13] OptionDecl ::= DECLARE_OPTION  QNAME  STRING_LITERAL
********************************************************************************/
void *begin_visit (const OptionDecl& v) 
{
  TRACE_VISIT ();
  //check if namespace for option is valid
  rchandle<QName>   qn = v.get_qname();
  xqpString   option_ns = sctx_p->lookup_ns(qn->get_prefix(), loc);

  // ignore if an error occurs
  sctx_p->bind_option(option_ns, qn->get_localname(), v.get_val());

  return no_state;
}

void end_visit (const OptionDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [26] VarDecl ::= "declare" "variable" "$" QName TypeDeclaration?
                   ((":=" VarValue) |
                    ("external" (":=" VarDefaultValue)?))


  [27] VarValue ::= ExprSingle

  [28] VarDefaultValue ::= ExprSingle

  Note: VarDecl is also used to represent block-local var declarations. The
  syntax for block-local var declarations is:

  BlockDecls ::= (BlockVarDecl ";")*

  BlockVarDecl ::= "declare" "$" VarName TypeDeclaration? (":=" ExprSingle)?
                    ("," "$" VarName TypeDeclaration? (":=" ExprSingle)?)*
********************************************************************************/
void *begin_visit (const VarDecl& v) 
{
  TRACE_VISIT ();

  store::Item_t varQNameItem = sctx_p->lookup_var_qname(v.get_varname(), loc);
  string key = static_context::qname_internal_key(varQNameItem);

  if (v.is_global()) 
  {
    prolog_var_decls.push_front(key);

    // TODO: local vars too
    prolog_vf_key = string("V") + key;
}

  return no_state;
}


void end_visit (const VarDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  if (v.is_global())
    prolog_vf_key.clear();

  xqp_string varname = v.get_varname();

  // The declared type of a global or external is never tightened based on
  // type inference because globals are mutable.
  xqtref_t type;
  if (v.get_typedecl() != NULL)
    type = pop_tstack();

  varref_t ve;

  if (v.is_global()) 
  {
    // Create a var_expr for this var and put a mapping between the var name and
    // the var_expr in the local sctx. Raise error if var name exists already in
    // local sctx obj.
    ve = bind_var(loc, varname, var_expr::prolog_var, type);

    // All vars declared in a module must be in the same namespace as the module
    if (! theModuleNamespace.empty() &&
        ve->get_varname()->getNamespace()->str() != theModuleNamespace)
      ZORBA_ERROR_LOC (XQST0048, loc);

    // Make sure that there is no other prolog var with the same name in any of
    // modules transalted so far.
    bind_var(ve, minfo->globals.get());

    // If this is a library module, register the var in the exported sctx as well.
    if (export_sctx != NULL)
      bind_var(ve, export_sctx);

    expr_t val = (v.get_initexpr () == NULL ? expr_t(NULL) : pop_nodestack());

    thePrologVars.push_back(global_binding(ve, val, v.is_extern()));
}
  else
  {
    ve = bind_var(loc, varname, var_expr::local_var, type);

    expr_t val = (v.get_initexpr () == NULL ? expr_t(NULL) : pop_nodestack());

    nodestack.push(ve.cast<expr>());
    nodestack.push(val);
  }
  }


/*******************************************************************************
  [29] ContextItemDecl ::= "declare" "context" "item" ("as" ItemType)?
                           ((":=" VarValue) |
                            ("external" (":=" VarDefaultValue)?))
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

  expr_t ctx_item_default;
  if (v.get_expr() != NULL)
    ctx_item_default = pop_nodestack ();

  if (v.get_type () != NULL)
    ctx_item_type = pop_tstack();

  if (v.get_type() != NULL || v.get_expr() != NULL) 
  {
    store::Item_t dotname;
    varref_t var = create_var (loc, ".", var_expr::prolog_var, ctx_item_type);
    global_binding b (var, ctx_item_default, true);

    declare_var(b, minfo->init_exprs);
}
}


/*******************************************************************************
  [32] FunctionDecl ::= "declare"
                        ("deterministic" | "nondeterministic")?
                        ("simple" | "updating | "sequential")?
                        "function" QName "(" ParamList? ")" ("as" SequenceType)?
                        (FunctionBody | "external")

  [33] FunctionBody ::= EnclosedExpr | Block

  Block ::= "{" BlockDecls BlockBody "}"

  BlockDecls ::= (BlockVarDecl ";")*

  BlockVarDecl ::= "declare" "$" VarName TypeDeclaration? (":=" ExprSingle)?
                    ("," "$" VarName TypeDeclaration? (":=" ExprSingle)?)*

  BlockBody ::= Expr

  Note: If a function is a sequential one, then its FunctionBody must be a Block,
        otherwise its FunctionBody must be an EnclosedExpr.

  Note: There are no parsenode classes for BlockVarDecl and BlockDecls; instead
        the parser generates VarDecl and VFO_DeclList parsenodes.

  Note: There is no parsenode class for Block; instead the parser generates either
        an Expr node if BlockDecls is empty, or a BlockBody node whose "decls"
        data member stores the var declarations.
********************************************************************************/
void *begin_visit (const FunctionDecl& v) 
    {
  TRACE_VISIT ();

  push_scope ();

  // Get qname item out of function qname (will raise error if prefix in qname
  // is not bound to a namespace).
  store::Item_t qname = sctx_p->lookup_fn_qname(v.get_name()->get_prefix(),
                                                v.get_name()->get_localname(),
                                                v.get_location ());

  string key = sctx_p->qname_internal_key (qname);
  prolog_vf_key = string("F") + key;

  function* f = sctx_p->lookup_fn_int(key, v.get_param_count());

  prolog_fn_decls.push_front(f);
  fn_decl_stack.push_front(f);

  return no_state;
}


void end_visit (const FunctionDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  prolog_vf_key.clear();
  pop_stack (fn_decl_stack);

  expr_t body;
  ParseConstants::function_type_t lFuncType = v.get_type();
  bool is_external = (lFuncType == ParseConstants::fn_extern ||
                      lFuncType == ParseConstants::fn_extern_update ||
                      lFuncType == ParseConstants::fn_extern_sequential);
  if (! is_external)
    body = pop_nodestack ();

  if (v.get_return_type () != NULL)
    pop_tstack ();

  // If function has any params, they have been wraped in a flwor expr. Set the
  // return clause of the flwor to the body expr of the function, and then make
  // this flwor be the actual body of the function.
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

    if (body->is_sequential() && lFuncType != ParseConstants::fn_sequential) 
    {
      ZORBA_ERROR_LOC_DESC (XPST0003, loc,
                            "Only a sequential function can have a body that is sequential expression");
  }

    // Under section 2.2.2 "Category Rules", it states: If the body of a
    // sequential function is a Block it must be either a sequential or
    // simple expression."
    // TODO: the error code has not yet been decided by the w3c
    if ( lFuncType == ParseConstants::fn_sequential && body->is_updating() ) 
    {
      ZORBA_ERROR_LOC_DESC (XPTY0004, loc,
                            "A sequential function cannot have a body that returns a pending update list");
}

    if (lFuncType == ParseConstants::fn_read) 
    {
      if (body->is_updating())
        ZORBA_ERROR_LOC(XUST0001, loc);
}
    else if (lFuncType == ParseConstants::fn_update) 
    {
      if (! body->is_updating_or_vacuous ())
        ZORBA_ERROR_LOC(XUST0002, loc);
    } 

    user_function *udf = dynamic_cast<user_function *>(
                         LOOKUP_FN(v.get_name ()->get_prefix (),
                                   v.get_name ()->get_localname (),
                                   nargs));
    ZORBA_ASSERT (udf != NULL);

    // Normalize and optimize the function body. This has to be done here because
    // we have the correct static context here (udfs declared in a library module
    // must be compiled in the contex tof that module).
    if (cb->m_config.translate_cb != NULL)
      cb->m_config.translate_cb(&*body, v.get_name()->get_qname());

    normalize_expr_tree(v.get_name()->get_qname().c_str(),
                        cb,
                        body,
                        *&(udf->get_signature().return_type()));

    if (cb->m_config.opt_level == CompilerCB::config_t::O1) 
{
      RewriterContext rCtx(cb, body);
      GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rCtx);
      body = rCtx.getRoot();

      RewriterContext rCtx1(cb, body);
      GENV_COMPILERSUBSYS.getPhase1Rewriter()->rewrite(rCtx1);
      body = rCtx1.getRoot();

      if (cb->m_config.optimize_cb != NULL)
        cb->m_config.optimize_cb(&*body, v.get_name ()->get_qname ());
    }

    udf->set_body(body);
    udf->set_args(args);
    break;
  }
  case ParseConstants::fn_extern:
  case ParseConstants::fn_extern_sequential:
  {
      break;
  }
  case ParseConstants::fn_extern_update:
  {
    if (v.get_return_type() != 0)
      ZORBA_ERROR_LOC(XUST0028, loc);

    break;
}
  default:
  {
    ZORBA_ASSERT(0);
  }
  }

  pop_scope();
}


/*******************************************************************************
  [34] ParamList ::= Param ("," Param)*
********************************************************************************/
void *begin_visit (const ParamList& v) 
{
  TRACE_VISIT ();

  if (v.size() > 0) 
  {
    nodestack.push(new flwor_expr(cb->m_cur_sctx, loc, false));
  }
  return no_state;
}


void end_visit (const ParamList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [35] Param ::= "$" QName TypeDeclaration?
********************************************************************************/
void *begin_visit (const Param& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const Param& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  rchandle<flwor_expr> flwor = nodestack.top().cast<flwor_expr> ();
  ZORBA_ASSERT(flwor != NULL);

  store::Item_t qname = sctx_p->lookup_qname ("", v.get_name(), v.get_location());

  varref_t arg_var = create_var (loc, qname, var_expr::arg_var);
  varref_t subst_var = bind_var (loc, qname, var_expr::let_var);

  flwor->add_clause(wrap_in_letclause(&*arg_var, subst_var));

  if (v.get_typedecl () != NULL)  
  {
    arg_var->set_type (pop_tstack ());
    subst_var->set_type(arg_var->get_type());
  }
}


/***************************************************************************//**
  IndexDecl ::= DECLARE [UNIQUE] [HASH | BTREE] INDEX URI_LITERAL
                ON ExprSingle
                BY IndexFieldList ")"

  Translation of an index declaration involves the creation and setting-up of
  a ValueIndex obj (see indexing/value_index.h) and the creation in the current
  sctx (which is the root sctx of the current module) of a binding between the
  index uri and this ValueIndex obj.
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
void *begin_visit (const IndexFieldList& v) 
{
  TRACE_VISIT ();

  expr_t dExpr = pop_nodestack();
  const std::string& uri = indexstack.top()->getIndexUri()->str();

  if (cb->m_config.translate_cb != NULL)
    cb->m_config.translate_cb (&*dExpr, uri);

  // Normalize and optimize the domain expr
  normalize_expr_tree(uri.c_str(), cb, dExpr, &*GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR);

  if (cb->m_config.opt_level == CompilerCB::config_t::O1) 
  {
    RewriterContext rCtx(cb, dExpr);
    GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rCtx);
    dExpr = rCtx.getRoot();
    if (cb->m_config.optimize_cb != NULL)
      cb->m_config.optimize_cb (&*dExpr, uri.c_str());
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

void end_visit (const IndexFieldList& v, void* /*visit_state*/) 
  {
  std::vector<expr_t> iCols;
  std::vector<xqtref_t> iColTypes;
  std::vector<std::string> iColCollations;

  for(int i = v.fields.size() - 1; i >= 0; --i) 
  {
    iCols.push_back(pop_nodestack());
    xqtref_t type = (v.fields[i]->get_type() != NULL ?
                     pop_tstack() :
                     GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION);
    iColTypes.push_back(type);
    iColCollations.push_back(v.fields[i]->coll);
  }

  std::reverse(iCols.begin(), iCols.end());
  std::reverse(iColTypes.begin(), iColTypes.end());
  std::reverse(iColCollations.begin(), iColCollations.end());

  indexstack.top()->setIndexFieldExpressions(iCols);
  indexstack.top()->setIndexFieldTypes(iColTypes);
  indexstack.top()->setIndexFieldCollations(iColCollations);

  pop_scope();

  TRACE_VISIT_OUT ();
  }


/***************************************************************************//**
  IndexField ::= ExprSingle [TypeDeclaration] ["COLLATION" UriLiteral]
********************************************************************************/
void *begin_visit (const IndexField& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const IndexField& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  EnclosedExpr, Block, QueryBody, Expr, ExprSingle                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  [36] EnclosedExpr ::= "{" Expr "}"

   Although EnclosedExpr appears in several grammar rules, an EnclosedExpr
   parsenode is created only in the case of direct and computed node constructors.
********************************************************************************/
void *begin_visit (const EnclosedExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const EnclosedExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  expr_t lContent = pop_nodestack();
  fo_expr *fo_h = new fo_expr(cb->m_cur_sctx,
                              loc,
                              CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
  fo_h->add(lContent);
  nodestack.push(fo_h);
}


/*******************************************************************************
  Block ::= "{" BlockDecls BlockBody "}"

  BlockDecls ::= (BlockVarDecl ";")*

  BlockVarDecl ::= "declare" "$" VarName TypeDeclaration? (":=" ExprSingle)?
                    ("," "$" VarName TypeDeclaration? (":=" ExprSingle)?)*

  BlockBody ::= Expr

  Note: There are no parsenode classes for BlockVarDecl and BlockDecls; instead
        the parser generates VarDecl and VFO_DeclList parsenodes.

  Note: There is no parsenode class for Block; instead the parser generates either
        an Expr node if BlockDecls is empty, or a BlockBody node whose "decls"
        data member stores the var declarations.
********************************************************************************/
void *begin_visit (const BlockBody& v) 
{
  TRACE_VISIT ();

  push_scope ();
  return no_state;
}

void end_visit (const BlockBody& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  // Vector to hold the init exprs for the local vars.
  // constructed in reverse... maybe not the best choice
  vector<expr_t> stmts;

  rchandle<VFO_DeclList> decls = v.get_decls ();

  for (int i = 0; i < v.size(); i++)
    stmts.push_back (pop_nodestack ());

  if (decls != NULL)
  {
    for (int i = decls->size() - 1; i >= 0; --i) 
    {
      expr_t val = pop_nodestack();
      varref_t ve = pop_nodestack().cast<var_expr> ();
      global_binding b (ve, val, false);

      vector<expr_t> stmts1;
      declare_var (b, stmts1);

      reverse(stmts1.begin(), stmts1.end());

      stmts.insert(stmts.end(), stmts1.begin(), stmts1.end());
  }
  }

  reverse (stmts.begin(), stmts.end());

  nodestack.push (new sequential_expr (cb->m_cur_sctx, loc, stmts));

  pop_scope ();
}


/*******************************************************************************
  [37] QueryBody ::= Expr
********************************************************************************/
void *begin_visit (const QueryBody& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const QueryBody& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  expr_t resultExpr = wrap_in_globalvar_assign(pop_nodestack());

  nodestack.push(resultExpr);

  if (minfo->topCompilerCB->isLoadPrologQuery())
    sctx_p->set_query_expr(resultExpr);
}


/*******************************************************************************
  [38] Expr ::= ExprSingle | Expr  COMMA  ExprSingle
********************************************************************************/
void *begin_visit (const Expr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const Expr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  if (v.numberOfChildren () > 1) 
  {
    std::auto_ptr<fo_expr> elist_h(create_seq (loc));

    expr_update_t lUpdateType = VACUOUS_EXPR;

    for (int i = 0; i < v.numberOfChildren (); i++) 
    {
      expr_t e_h = pop_nodestack();

      lUpdateType = update_type_anding(e_h->get_update_type(), 
                                       lUpdateType, 
                                       loc);

      elist_h->add(e_h);
  }

    nodestack.push(elist_h.release());
}
}


/*******************************************************************************
  [39] ExprSingle ::= 

  ** XQuery 1.1 exprs
                      FLWORExpr |
                      QuantifiedExpr |
                      TypeswitchExpr |
                      IfExpr |
                      OrExpr |
                      TryExpr |

  ** updates
                      InsertExpr |
                      DeleteExpr |
                      RenameExpr |
                      ReplaceExpr |
                      TransformExpr |

  ** scripting
                      ExitExpr |
                      WhileExpr |
                      FlowCtlStatement |
                      AssignExpr |
                      BlockExpr |

  ** eval
                      EvalExpr

  ** indexes
                      IndexStatement
********************************************************************************/


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  FLWOR                                                                      //
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

  rchandle<flwor_expr> flwor = new flwor_expr(cb->m_cur_sctx, loc, v.is_general());

  //
  // Process return clause
  //
  expr_t retExpr = pop_nodestack();
  
  wrap_in_debugger_expr(retExpr);

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
        wrap_in_debugger_expr(domainExpr);
        for_clause* eflc = new for_clause(cb->m_cur_sctx, c.get_location(),
                                          varExprs[j],
                                          domainExpr,
                                          posVarExprs[j]);
        eflc->set_outer(flc.is_outer());

        eclauses.push_back(eflc);

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
        wrap_in_debugger_expr(domainExpr);
        let_clause* eflc = new let_clause(cb->m_cur_sctx, c.get_location(),
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
      pop_scope();  // var decl + output window condition vars
      pop_scope();

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

      window_clause* flwc = new window_clause(cb->m_cur_sctx, c.get_location(),
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
      wrap_in_debugger_expr(whereExpr);
      if (whereExpr->is_updating())
        ZORBA_ERROR_LOC(XUST0001, loc);

      eclauses.push_back(new where_clause(cb->m_cur_sctx, c.get_location(), whereExpr));
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
        input_wrapper = new wrapper_expr(cb->m_cur_sctx, c.get_location(),
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
        input_wrapper = new wrapper_expr(cb->m_cur_sctx, c.get_location(),
                                         static_cast<expr*>(input_var.getp()));

        nongrouping_rebind.push_back(pair<wrapper_expr_t, varref_t>(input_wrapper,
                                                                    output_var));

        pop_scope();
      }
      
      eclauses.push_back(new group_clause(cb->m_cur_sctx, c.get_location(),
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

      rchandle<orderby_clause> obgc = new orderby_clause(cb->m_cur_sctx, c.get_location(),
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
      eclauses.push_back(new count_clause(cb->m_cur_sctx,
                                          c.get_location(), 
                                          pop_nodestack_var()));
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
  }

  xqtref_t type = v.get_typedecl () == NULL ? NULL : pop_tstack ();

  bind_var_and_push(loc, var_qname, var_expr::for_var, type);
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


/*******************************************************************************
  [65] QuantifiedExpr ::= ("some" | "every") QVarInDeclList "satisfies" ExprSingle

  A universally quantified expr is translated into a flwor expr:

  fn:empty(for $v1 in expr1, ... vn in exprn
           where not(testExpr)
           return true)

  An existentially quantified expr is translated into a flwor expr:

  fn:exists(for $v1 in expr1, ... vn in exprn
            where testExpr
            return true)

********************************************************************************/
void *begin_visit (const QuantifiedExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const QuantifiedExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  rchandle<flwor_expr> flwor(new flwor_expr(cb->m_cur_sctx, loc, false));

  flwor->set_return_expr(new const_expr(cb->m_cur_sctx, loc, true));

  rchandle<expr> sat = pop_nodestack();

  if (v.get_qmode() == ParseConstants::quant_every) 
  {
    rchandle<fo_expr> uw = new fo_expr(cb->m_cur_sctx,
                                       v.get_expr()->get_location(),
                                       LOOKUP_FN("fn", "not", 1));
    uw->add(sat);
    sat = uw.getp();
  }

  vector<expr_t> vars_vals(2 * v.get_decl_list()->size());

  generate(vars_vals.rbegin(), vars_vals.rend(), stack_to_generator(nodestack));

  for (int i = 0; i < v.get_decl_list()->size(); ++i) 
  {
    pop_scope();
    varref_t ve = vars_vals[2 * i + 1].cast<var_expr>();
    expr_t domainExpr = vars_vals[2 * i];
    flwor->add_clause(wrap_in_forclause (domainExpr, ve, NULL));
}

  flwor->add_where(sat);

  rchandle<fo_expr> quant = new fo_expr(cb->m_cur_sctx,
                                        loc,
                                        v.get_qmode() == ParseConstants::quant_every ?
                                        LOOKUP_FN("fn", "empty", 1) :
                                        LOOKUP_FN("fn", "exists", 1));
  quant->add (&*flwor);
  nodestack.push (&*quant);
}


/*******************************************************************************
  QVarInDeclList := QVarInDecl ("," QVarInDecl)*
********************************************************************************/
void *begin_visit (const QVarInDeclList& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const QVarInDeclList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  QVarInDecl := "$" VarName TypeDeclaration? "in" ExprSingle
********************************************************************************/
void *begin_visit (const QVarInDecl& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const QVarInDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  push_scope ();
  xqtref_t type;
  if (v.get_typedecl () != NULL)
    type = pop_tstack ();

  bind_var_and_push (loc, v.get_name (), var_expr::for_var, type);
  }


/*******************************************************************************
  [66] TypeswitchExpr ::= "typeswitch" "(" Expr ")"
                          CaseClauseList
                          "default" ("$" VarName)? "return" ExprSingle

  A typeswitch expr is translated into a flwor expr. For example, a typeswitch of
  the following form:

  typeswitch E
  case $v1 as type1 return E1
  ......
  case $vn as typen return En
  default return Ed

  is translated into:

  let $sv := E
  return if (instance_of($sv, type1)) then
           let $v1 := cast($sv, type1) return E1
         else if (instance_of($sv, type2)) then
           let $v2 := cast($sv, type2) return E2
         ....
         else if instance_of($sv, typen)) then
           let $vn := cast($sv, typen) return En
         else
           return Ed
********************************************************************************/
void *begin_visit (const TypeswitchExpr& v) 
{
  TRACE_VISIT ();

  varref_t sv = tempvar(v.get_switch_expr()->get_location(), var_expr::let_var);

  string defvar_name = v.get_default_varname();
  varref_t defvar;
  expr_t defret;

  if (! defvar_name.empty ()) 
  {
    push_scope();
    defvar = bind_var(v.get_default_clause()->get_location(),
                      defvar_name,
                      var_expr::let_var);
  }

  v.get_default_clause()->accept(*this);

  defret = pop_nodestack();

  if (! defvar_name.empty()) 
  {
    pop_scope();
    
    // defret = [let $defvar := $sv return defret]
    defret = &*wrap_in_let_flwor(&*sv, defvar, defret);
  }

  const CaseClauseList* clauses = v.get_clause_list();
  for (vector<rchandle<CaseClause> >::const_reverse_iterator it = clauses->rbegin();
       it != clauses->rend();
       ++it)
  {
    const CaseClause *e_p = &**it;
    const QueryLoc &loc = e_p->get_location ();

    string varname = e_p->get_varname ();
    varref_t caseVar;

    if (! varname.empty ()) 
    {
      push_scope ();
      caseVar = bind_var(loc, varname, var_expr::let_var);
    }

    e_p->accept (*this);

    xqtref_t type = pop_tstack ();

    if (! varname.empty ()) 
    {
      pop_scope();
      expr_t caseExpr = pop_nodestack();

      // case_clause = [let $caseVar := cast($sv, caseType) return caseExpr]
      expr_t lFlwor = wrap_in_let_flwor(new cast_expr(cb->m_cur_sctx, loc, &*sv, type),
                                        caseVar,
                                        caseExpr);
      nodestack.push (lFlwor);
    }

    expr_t lThen = pop_nodestack();
    update_type_anding(lThen->get_update_type(), 
                       defret->get_update_type(),
                       loc);

    defret = new if_expr (cb->m_cur_sctx,
                          e_p->get_location(),
                          new instanceof_expr(cb->m_cur_sctx, loc, &*sv, type),
                          lThen,
                          defret);
  }

  v.get_switch_expr()->accept(*this);

  expr_t se = pop_nodestack();

  if (se->is_updating()) {
    ZORBA_ERROR_LOC(XUST0001, loc);
  }

  expr_t lFlwor = wrap_in_let_flwor(se, sv, defret);

  nodestack.push (lFlwor);

  // Return NULL so that TypeswitchExpr::accept() will not call accept() on the
  // children of the TypeswitchExpr parsenode.
  return NULL;
}


void end_visit (const TypeswitchExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
  // shouldn't get here, begin_visit() rejects visitor
  ZORBA_ASSERT (false);
}


/*******************************************************************************
  CaseClauseList := CaseClause+
********************************************************************************/
void *begin_visit (const CaseClauseList& v) 
{
  TRACE_VISIT ();

  // shouldn't get here
  ZORBA_ASSERT (false);

  return no_state;
}


void end_visit (const CaseClauseList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [67] CaseClause ::= "case" ("$" VarName "as")? SequenceType "return" ExprSingle
********************************************************************************/
void *begin_visit (const CaseClause& v) 
{
  TRACE_VISIT ();

  return no_state;
}

void end_visit (const CaseClause& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [68] IfExpr ::= "if" "(" Expr ")" "then" ExprSingle "else" ExprSingle
********************************************************************************/
void *begin_visit (const IfExpr& v) 
{
  TRACE_VISIT ();
  // nothing to do here
  return no_state;
}

void end_visit (const IfExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
  expr_t e_h = pop_nodestack ();
  expr_t t_h = pop_nodestack ();
  expr_t c_h = pop_nodestack ();

  if (c_h->is_updating()) {
    ZORBA_ERROR_LOC(XUST0001, loc);
  }

  update_type_anding(t_h->get_update_type(), 
                     e_h->get_update_type(),
                     loc);

  wrap_in_debugger_expr(e_h);
  wrap_in_debugger_expr(t_h);
  wrap_in_debugger_expr(c_h);

  if_expr *lIfExpr = new if_expr(cb->m_cur_sctx, loc,c_h,t_h,e_h);
  nodestack.push(lIfExpr);
}


/*******************************************************************************
  [69] OrExpr ::= AndExpr ( "or" AndExpr )*
********************************************************************************/
void *begin_visit (const OrExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const OrExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
  rchandle<expr> e1_h = pop_nodestack();
  rchandle<expr> e2_h = pop_nodestack();
  fo_expr *fo_p = new fo_expr(cb->m_cur_sctx, loc, CACHED (op_or, LOOKUP_OPN ("or")));
  fo_p->add(e2_h);
  fo_p->add(e1_h);
  nodestack.push (fo_p);
}


/*******************************************************************************
  [70] AndExpr ::= ComparisonExpr ( "and" ComparisonExpr )*
********************************************************************************/
void *begin_visit (const AndExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const AndExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
  rchandle<expr> e1_h = pop_nodestack();
  rchandle<expr> e2_h = pop_nodestack();
  fo_expr *fo_h = new fo_expr(cb->m_cur_sctx, loc, LOOKUP_OPN ("and"));
  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push (fo_h);
}


/*******************************************************************************
  [71] ComparisonExpr ::= RangeExpr
                          ((ValueComp | GeneralComp | NodeComp) RangeExpr)?

  Note: For the full-text extension, the rule for ComparisonExpr is:

  ComparisonExpr ::= FTContainsExpr
                     ((ValueComp | GeneralComp | NodeComp) FTContainsExpr)?

********************************************************************************/
void *begin_visit (const ComparisonExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ComparisonExpr& v, void* /*visit_state*/) 
{
#define M( pc, op ) case ParseConstants::pc: f = LOOKUP_OP2 (op); break;

  TRACE_VISIT_OUT ();

  function *f = NULL;
  if (v.get_gencomp()!=NULL) 
  {
    switch (v.get_gencomp()->get_type()) {
    M (op_eq, "equal");
    M (op_ne, "not-equal");
    M (op_lt, "less");
    M (op_le, "less-equal");
    M (op_gt, "greater");
    M (op_ge, "greater-equal");
    }
  }
  else if (v.get_valcomp () != NULL) 
  {
    switch (v.get_valcomp()->get_type()) {
    M (op_val_eq, "value-equal");
    M (op_val_ne, "value-not-equal");
    M (op_val_lt, "value-less");
    M (op_val_le, "value-less-equal");
    M (op_val_gt, "value-greater");
    M (op_val_ge, "value-greater-equal");
    }
  }
  else if (v.get_nodecomp()!=NULL) 
  {
    switch (v.get_nodecomp()->get_type()) {
    M (op_is, "is-same-node");
    M (op_precedes, "node-before");
    M (op_follows, "node-after");
    }
  }

  fo_expr *fo_p = new fo_expr(cb->m_cur_sctx, loc, f);

  rchandle<expr> e1_h = pop_nodestack();
  rchandle<expr> e2_h = pop_nodestack();;
  fo_p->add(e2_h);
  fo_p->add(e1_h);
  nodestack.push(fo_p);

#undef M
}


/*******************************************************************************
  [83] GeneralComp ::= "=" | "!=" | "<" | "<=" | ">" | ">="
********************************************************************************/
void *begin_visit (const GeneralComp& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const GeneralComp& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [84] ValueComp ::= "eq" | "ne" | "lt" | "le" | "gt" | "ge"
********************************************************************************/
void *begin_visit (const ValueComp& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ValueComp& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [85] NodeComp ::= "is" | "<<" | ">>"
********************************************************************************/
void *begin_visit (const NodeComp& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const NodeComp& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [72] RangeExpr ::= AdditiveExpr ( "to" AdditiveExpr )?
********************************************************************************/
void *begin_visit (const RangeExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const RangeExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
  fo_expr *e = new fo_expr (cb->m_cur_sctx, loc, LOOKUP_OP2 ("to"));

  rchandle<expr> e1_h = pop_nodestack ();
  rchandle<expr> e2_h = pop_nodestack ();

  e->add(e2_h);
  e->add(e1_h);

  nodestack.push(e);
}


/*******************************************************************************
  [73] AdditiveExpr ::= MultiplicativeExpr ( ("+" | "-") MultiplicativeExpr )*
********************************************************************************/
void *begin_visit (const AdditiveExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const AdditiveExpr& v, void* /*visit_state*/) 
{
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
  fo_expr *fo_h = new fo_expr(cb->m_cur_sctx, loc, func);
  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push (fo_h);
}


/*******************************************************************************
  [74] MultiplicativeExpr ::= UnionExpr (("*" | "div" | "idiv" | "mod") UnionExpr)*
********************************************************************************/
void *begin_visit (const MultiplicativeExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const MultiplicativeExpr& v, void* /*visit_state*/) 
{
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
  fo_expr *fo_h = new fo_expr(cb->m_cur_sctx, loc, f);
  fo_h->add(e2_h);
  fo_h->add(e1_h);
  nodestack.push (fo_h);
}


/*******************************************************************************
  [75] UnionExpr ::= IntersectExceptExpr (("union" | "|") IntersectExceptExpr)*
********************************************************************************/
void *begin_visit (const UnionExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const UnionExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  rchandle<expr> e1_h = pop_nodestack ();
  rchandle<expr> e2_h = pop_nodestack ();
  fo_expr *fo_h = new fo_expr(cb->m_cur_sctx, loc, LOOKUP_OP2 ("union"));
  fo_h->add(e2_h);
  fo_h->add(e1_h);

  nodestack.push(new fo_expr(cb->m_cur_sctx,
                             loc,
                             LOOKUP_OP1 ("sort-distinct-nodes-asc"),
                             fo_h));
}


/*******************************************************************************
  [76] IntersectExceptExpr ::= InstanceofExpr
                               (("intersect" | "except") InstanceofExpr)*
********************************************************************************/
void *begin_visit (const IntersectExceptExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const IntersectExceptExpr& v, void* /*visit_state*/) 
{
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

  fo_expr *fo_h = new fo_expr(cb->m_cur_sctx, loc, f);

  fo_h->add(e2_h);
  fo_h->add(e1_h);

  nodestack.push(new fo_expr(cb->m_cur_sctx,
                             loc,
                             LOOKUP_OP1 ("sort-distinct-nodes-asc"),
                             fo_h));
}


/*******************************************************************************
  [77] InstanceofExpr ::= TreatExpr ( "instance" "of" SequenceType )?
********************************************************************************/
void *begin_visit (const InstanceofExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const InstanceofExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
  nodestack.push(new instanceof_expr(cb->m_cur_sctx,
                                     loc,
                                     pop_nodestack(),
                                     pop_tstack()));
}


/*******************************************************************************
  [78] TreatExpr ::= CastableExpr ( "treat" "as" SequenceType )?
********************************************************************************/
void *begin_visit (const TreatExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const TreatExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  nodestack.push(new treat_expr(cb->m_cur_sctx,
                                loc,
                                pop_nodestack(),
                                pop_tstack(),
                                XPDY0050));
}


/*******************************************************************************
  [79] CastableExpr ::= CastExpr ( "castable" "as" SingleType )?
********************************************************************************/
void *begin_visit (const CastableExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CastableExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  nodestack.push(create_cast_expr(loc, pop_nodestack(), pop_tstack(), false));
}


expr_t create_cast_expr (const QueryLoc& loc, expr_t node, xqtref_t type, bool isCast)
{
  if (TypeOps::is_equal(*type, *GENV_TYPESYSTEM.NOTATION_TYPE_ONE) ||
      TypeOps::is_equal(*type, *GENV_TYPESYSTEM.NOTATION_TYPE_QUESTION) ||
      TypeOps::is_equal(*type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE) ||
      TypeOps::is_equal(*type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION))
    ZORBA_ERROR_LOC(XPST0080, loc);

  if (TypeOps::is_subtype(*type, *GENV_TYPESYSTEM.QNAME_TYPE_QUESTION)) 
  {
    const const_expr* ce = node.dyn_cast<const_expr> ().getp();

    if (ce != NULL &&
        TypeOps::is_equal(*CTXTS->create_value_type(ce->get_val()),
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
        if (isCast) 
        {
          throw e;
        }
        else
        {
          if (e.theErrorCode == FORG0001)
            ZORBA_ERROR_LOC(XPST0003, loc);
          else
            ZORBA_ERROR_LOC(XPST0081, loc);
        }
      }

      assert (castLiteral != NULL || ! isCast);

      if (isCast)
        return new const_expr(cb->m_cur_sctx, loc, castLiteral);
      else
        return new const_expr(cb->m_cur_sctx, loc, castLiteral != NULL);
    }
    else
    {
      
      xqtref_t qnameType = (type->get_quantifier() == TypeConstants::QUANT_ONE ?
                            GENV_TYPESYSTEM.QNAME_TYPE_ONE :
                            GENV_TYPESYSTEM.QNAME_TYPE_QUESTION);

      // when casting to type T, where T is QName or subtype of, and the input
      // is not a const expr, then the input MUST be of type T or subtype of.
      if (isCast)
        return new treat_expr(cb->m_cur_sctx, loc, node, qnameType, XPTY0004);
      else
        return new instanceof_expr(cb->m_cur_sctx, loc, node, qnameType);
    }
  }
  else
  {
    if (isCast)
      return new cast_expr(cb->m_cur_sctx, loc, node, type);
    else
      return new castable_expr(cb->m_cur_sctx, loc, node, type);
  }
}


/*******************************************************************************
  [80] CastExpr ::= UnaryExpr ( "cast" "as" SingleType )?
********************************************************************************/
void *begin_visit (const CastExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CastExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  nodestack.push(create_cast_expr(loc, pop_nodestack(), pop_tstack(), true));
}


/*******************************************************************************
  [81] UnaryExpr ::= ("-" | "+")* ValueExpr
********************************************************************************/
void *begin_visit (const UnaryExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const UnaryExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  rchandle<expr> e1_h = pop_nodestack ();
  fo_expr *fo_p = new fo_expr(cb->m_cur_sctx, loc,
                              v.get_signlist()->get_sign()
                              ? LOOKUP_OP1 ("unary-plus")
                              : LOOKUP_OP1 ("unary-minus"));
  fo_p->add(e1_h);
  nodestack.push(fo_p);
}


void *begin_visit (const SignList& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const SignList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [82] ValueExpr ::= ValidateExpr | PathExpr | ExtensionExpr
********************************************************************************/


/*******************************************************************************
  [86] ValidateExpr ::= "validate" (ValidationMode | ("as" TypeName))? "{" Expr "}"
  [87] ValidationMode ::= "lax" | "strict"
********************************************************************************/
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
    xqpStringStore_t prefix = new xqpStringStore(v.get_type_name()->get_prefix());
    xqpStringStore_t ns;
    ns_ctx->findBinding(prefix, ns);

    GENV_ITEMFACTORY->createQName(qname,
                                  ns->c_str(),
                                  prefix->c_str(),
                                  v.get_type_name()->get_localname().c_str());
  }

  nodestack.push(new validate_expr(cb->m_cur_sctx,
                                   loc,
                                   v.get_valmode(),
                                   qname,
                                   pop_nodestack(),
                                   sctx_p->get_typemanager()));
}


/*******************************************************************************
  [88] ExtensionExpr ::= PragmaList "{" Expr? "}"
********************************************************************************/
void *begin_visit (const ExtensionExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ExtensionExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
  if (v.get_expr () == NULL)
    ZORBA_ERROR_LOC( XQST0079, loc);
}


/*******************************************************************************
  PragmaList ::= Pragma | PragmaList  Pragma
********************************************************************************/
void *begin_visit (const PragmaList& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const PragmaList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [89] Pragma ::= "(#" S? QName (S PragmaContents)? "#)"  // ws: explicitXQ
  [90] PragmaContents ::= (Char* - (Char* '#)' Char*))
********************************************************************************/
void *begin_visit (const Pragma& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const Pragma& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
 // may raise XPST0081
 sctx_p->lookup_ns (v.get_name ()->get_prefix (), loc);
}


/*******************************************************************************

  Path Expressions

  [91] PathExpr ::= ("/" RelativePathExpr?) |
                    ("//" RelativePathExpr) |
                     RelativePathExpr 	// gn: leading-lone-slashXQ

  [92] RelativePathExpr ::= StepExpr (("/" | "//") StepExpr)*

  [93] StepExpr ::= FilterExpr | AxisStep

  [94] AxisStep ::= (ReverseStep | ForwardStep) PredicateList

  [95] ForwardStep ::= (ForwardAxis NodeTest) | AbbrevForwardStep

  [96] ForwardAxis ::= ("child" "::") |
                       ("descendant" "::") |
                       ("attribute" "::") |
                       ("self" "::") |
                       ("descendant-or-self" "::") |
                       ("following-sibling" "::") |
                       ("following" "::")

  [97] AbbrevForwardStep ::= "@"? NodeTest

  [98] ReverseStep ::= (ReverseAxis NodeTest) | AbbrevReverseStep

  [99] ReverseAxis ::= ("parent" "::") |
                       ("ancestor" "::") |
                       ("preceding-sibling" "::") |
                       ("preceding" "::") |
                       ("ancestor-or-self" "::")

  [100] AbbrevReverseStep ::= ".."

  [101] NodeTest ::= KindTest | NameTest

  [102] NameTest ::= QName | Wildcard

  [103] Wildcard ::= "*" | (NCName ":" "*") | ("*" ":" NCName)

  [104] FilterExpr ::= PrimaryExpr PredicateList

  [105] PredicateList ::= Predicate*

  [106] Predicate ::= "[" Expr "]"


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

  In case 1, the PathExpr node does not have any child node.

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

  In general, a path expression is translated into a combination of relpath_exprs
  and flwor_exprs. relpath_exprs are created to represent the portions of a path
  expression whose steps consist of AxisSteps with no predicates. flwor_exprs 
  are are created to represent steps that are FilterExprs or AxisSteps with
  predicates.
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
    path_expr = new relpath_expr(cb->m_cur_sctx, loc);

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
    rchandle<relpath_expr> ctx_path_expr = new relpath_expr(cb->m_cur_sctx, loc);
    ctx_path_expr->add_back(DOT_VAR);

    rchandle<match_expr> me = new match_expr(cb->m_cur_sctx, loc);
    me->setTestKind(match_anykind_test);
    rchandle<axis_step_expr> ase = new axis_step_expr(cb->m_cur_sctx, loc);
    ase->setAxis(axis_kind_self);
    ase->setTest(me);

    ctx_path_expr->add_back(&*ase);

    rchandle<fo_expr> fo = new fo_expr(cb->m_cur_sctx, loc, LOOKUP_FN("fn", "root", 1));
    fo->add(&*ctx_path_expr);

    result = fo.getp();

    if (path_expr != NULL) 
    {
      path_expr->add_back(&*fo);
      result = path_expr.getp();
    }

    if (pe_type == ParseConstants::path_leading_slashslash) 
    {
      rchandle<axis_step_expr> ase = new axis_step_expr(cb->m_cur_sctx, loc);
      rchandle<match_expr> me = new match_expr(cb->m_cur_sctx, loc);
      me->setTestKind(match_anykind_test);
      ase->setAxis(axis_kind_descendant_or_self);
      ase->setTest(me);

      path_expr->add_back(&*ase);
    }
  }

  nodestack.push(result.getp());
  return no_state;
}


/*******************************************************************************

  [92] RelativePathExpr ::= StepExpr (("/" | "//") StepExpr)*

  Note: If a RelativePathExpr consists of a single StepExpr, a RelativePathExpr
  node is generated whose left child is a ContextItemExpr and its right child
  is the StepExpr.

********************************************************************************/
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

    pathExpr = new relpath_expr(cb->m_cur_sctx, loc);
    pathExpr->add_back(flworExpr);
  }

  // Convert // to /descendant-or-self::node()/
  if (rpe.get_step_type() == ParseConstants::st_slashslash)
  {
    rchandle<axis_step_expr> ase = new axis_step_expr(cb->m_cur_sctx, loc);
    rchandle<match_expr> me = new match_expr(cb->m_cur_sctx, loc);
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
  [93] StepExpr ::= FilterExpr | AxisStep
********************************************************************************/


/*******************************************************************************
  [94] AxisStep ::= (ReverseStep | ForwardStep) PredicateList
********************************************************************************/
void* begin_visit(const AxisStep& v)
{
  TRACE_VISIT ();

  rchandle<axis_step_expr> ase = new axis_step_expr(cb->m_cur_sctx, loc);
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
  rchandle<relpath_expr> predPathExpr = new relpath_expr(cb->m_cur_sctx, loc);
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


/*******************************************************************************
  [95] ForwardStep ::= (ForwardAxis NodeTest) | AbbrevForwardStep
********************************************************************************/
void *begin_visit (const ForwardStep& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const ForwardStep& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [97] AbbrevForwardStep ::= "@"? NodeTest
********************************************************************************/
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


/*******************************************************************************
  [98] ReverseStep ::= (ReverseAxis NodeTest) | AbbrevReverseStep
  [100] AbbrevReverseStep ::= ".."
********************************************************************************/
void *begin_visit (const ReverseStep& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const ReverseStep& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************

********************************************************************************/
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


/*******************************************************************************

********************************************************************************/
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
  [101] NodeTest ::= KindTest | NameTest
********************************************************************************/


/*******************************************************************************
  [102] NameTest ::= QName | Wildcard
********************************************************************************/
void *begin_visit (const NameTest& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const NameTest& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  expr* top = &*nodestack.top();

  axis_step_expr* axisExpr = NULL;
  trycatch_expr* tce = NULL;

  if ((axisExpr = dynamic_cast<axis_step_expr *>(top)) != NULL) 
  {
    // Construct name-test match expr
    rchandle<match_expr> matchExpr = new match_expr(cb->m_cur_sctx, loc);;
    matchExpr->setTestKind(match_name_test);

    if (v.getQName() != NULL) 
    {
      string qname = v.getQName()->get_qname();
      store::Item_t qn_h = (axisExpr->getAxis () == axis_kind_attribute ?
                            sctx_p->lookup_qname("", qname, v.getQName()->get_location()) :
                            sctx_p->lookup_elem_qname(qname, v.getQName()->get_location()));
      matchExpr->setQName(qn_h);
    }
    else 
    {
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
  }
  else if ((tce = dynamic_cast<trycatch_expr *>(top)) != NULL) 
  {
    catch_clause *cc = &*(*tce)[0];
    if (v.getQName() != NULL) 
    {
      string qname = v.getQName()->get_qname();
      store::Item_t qn_h = sctx_p->lookup_elem_qname (qname, loc);
      cc->add_nametest_h(new NodeNameTest(qn_h));
    }
    else
    {
      rchandle<Wildcard> wildcard = v.getWildcard();
      ZORBA_ASSERT(wildcard != NULL);

      switch (wildcard->getKind())
      {
        case ParseConstants::wild_all:
          cc->add_nametest_h(new NodeNameTest(NULL, NULL));
          break;
        case ParseConstants::wild_elem:
          cc->add_nametest_h(new NodeNameTest(NULL, wildcard->getPrefix().theStrStore));
          break;
        case ParseConstants::wild_prefix:
          cc->add_nametest_h(new NodeNameTest(wildcard->getLocalName().theStrStore, NULL));
          break;
      }
    }
  }
  else
  {
    ZORBA_ASSERT(false);
  }
}


/*******************************************************************************
  [103] Wildcard ::= "*" | (NCName ":" "*") | ("*" ":" NCName)
********************************************************************************/
void *begin_visit (const Wildcard& v) 
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit (const Wildcard& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  [104] FilterExpr ::= PrimaryExpr PredicateList
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


/*******************************************************************************
  [105] PredicateList ::= Predicate*
  [106] Predicate ::= "[" Expr "]"
********************************************************************************/
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
  rchandle<fo_expr> cond = new fo_expr(cb->m_cur_sctx, loc, CACHED(op_or, LOOKUP_OPN("or")));
  cond->add(new instanceof_expr(cb->m_cur_sctx, loc, predvar, GENV_TYPESYSTEM.DECIMAL_TYPE_ONE));
  cond->add(new instanceof_expr(cb->m_cur_sctx, loc, predvar, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE));
  cond = new fo_expr(cb->m_cur_sctx, loc, CACHED (op_or, LOOKUP_OPN ("or")), &*cond);
  cond->add(new instanceof_expr(cb->m_cur_sctx, loc, predvar, GENV_TYPESYSTEM.FLOAT_TYPE_ONE));

  // If so: return $dot if the value of the pred expr is equal to the value
  // of $dot_pos var, otherwise return the empty seq.
  rchandle<fo_expr> eq = new fo_expr(cb->m_cur_sctx, loc, LOOKUP_OP2("value-equal"));
  eq->add(lookup_ctx_var(DOT_POS_VARNAME, loc).getp ());
  eq->add(predvar);

  expr_t thenExpr = new if_expr(cb->m_cur_sctx, loc, eq.getp(), dotvar, create_seq(loc));

  // Else, return $dot if the the value of the pred expr is true, otherwise
  // return the empty seq.
  expr_t elseExpr = new if_expr(cb->m_cur_sctx, loc, predvar, dotvar, create_seq(loc));

  expr_t ifExpr = new if_expr(cb->m_cur_sctx, loc, cond.getp(), thenExpr, elseExpr);

  flworExpr->set_return_expr(ifExpr);

  nodestack.push(flworExpr);

  pop_scope();
}


/*******************************************************************************
  [107] PrimaryExpr ::= Literal |
                        VarRef |
                        ParenthesizedExpr |
                        ContextItemExpr |
                        FunctionCall |
                        OrderedExpr |
                        UnorderedExpr |
                        Constructor
********************************************************************************/


/*******************************************************************************
  [108] Literal ::= NumericLiteral | StringLiteral
********************************************************************************/


/*******************************************************************************
  [109] NumericLiteral ::= IntegerLiteral | DecimalLiteral | DoubleLiteral

  [178] IntegerLiteral ::= Digits

  [179] DecimalLiteral :: ("." Digits) | (Digits "." [0-9]*) 

  [180] DoubleLiteral ::= (("." Digits) | (Digits ("." [0-9]*)?)) [eE] [+-]? Digits
********************************************************************************/
void *begin_visit (const NumericLiteral& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const NumericLiteral& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
  switch (v.get_type()) {
  case ParseConstants::num_integer: {
    nodestack.push(new const_expr(cb->m_cur_sctx, loc, v.get<xqp_integer>()));
    break;
  }
  case ParseConstants::num_decimal: {
    nodestack.push(new const_expr(cb->m_cur_sctx, loc, v.get<xqp_decimal>()));
    break;
  }
  case ParseConstants::num_double: {
    nodestack.push(new const_expr(cb->m_cur_sctx, loc, v.get<xqp_double>()));
    break;
  }
  }
}


/*******************************************************************************
  [181] StringLiteral ::= ('"' (PredefinedEntityRef |
                                CharRef |
                                EscapeQuot |
                                [^"&])*
                           '"') |
                          ("'" (PredefinedEntityRef |
                                CharRef |
                                EscapeApos |
                                [^'&])*
                           "'")

  [182] PredefinedEntityRef ::= "&" ("lt" | "gt" | "amp" | "quot" | "apos") ";"

  [183] EscapeQuot ::= '""'

  [184] EscapeApos ::= "''"

  [190] CharRef ::= [http://www.w3.org/TR/REC-xml#NT-CharRef]
********************************************************************************/
void *begin_visit (const StringLiteral& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const StringLiteral& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
  nodestack.push(new const_expr(cb->m_cur_sctx, loc,v.get_strval()));
}


/*******************************************************************************
  [110] VarRef ::= "$" VarName
  [111] VarName ::= QName
********************************************************************************/
void *begin_visit (const VarRef& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const VarRef& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  var_expr *ve = lookup_var (v.get_varname ());

  if (ve == NULL)
    ZORBA_ERROR_LOC_PARAM (XPST0008, loc, v.get_varname (), "");

  if (ve->get_kind() == var_expr::prolog_var && ! prolog_vf_key.empty()) 
  {
    string key = "V" + static_context::qname_internal_key (ve->get_varname ());
    add_multimap_value(thePrologDeps, prolog_vf_key, key);
  }

  nodestack.push(new wrapper_expr(cb->m_cur_sctx, v.get_location(), rchandle<expr>(ve)));
}


/*******************************************************************************
  [112] ParenthesizedExpr ::= "(" Expr? ")"
********************************************************************************/
void *begin_visit (const ParenthesizedExpr& v) 
{
  TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit (const ParenthesizedExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  expr_t expr = pop_nodestack();

  if (expr != NULL) 
  {
    pop_nodestack();
    nodestack.push(expr);
  }
  else 
  {
    fo_expr* lSeq = create_seq (loc);
    nodestack.push(lSeq);
  }
}


/*******************************************************************************
  [113] ContextItemExpr ::= "."
********************************************************************************/
void *begin_visit (const ContextItemExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ContextItemExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  var_expr* e = static_cast<var_expr *>(DOT_VAR);
  e->set_loc(loc);
  nodestack.push(e);
}


/*******************************************************************************
  [114] OrderedExpr ::= "ordered" "{" Expr "}"
********************************************************************************/
void *begin_visit (const OrderedExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const OrderedExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  nodestack.push(new order_expr(cb->m_cur_sctx,
                                loc,
                                order_expr::ordered,
                                pop_nodestack()));
}


/*******************************************************************************
  [115] UnorderedExpr ::= "unordered" "{" Expr "}"
********************************************************************************/
void *begin_visit (const UnorderedExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const UnorderedExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  nodestack.push(new order_expr(cb->m_cur_sctx,
                                loc,
                                order_expr::unordered,
                                pop_nodestack()));
}


/*******************************************************************************
  [116] FunctionCall ::= QName "(" ArgList? ")"
********************************************************************************/
void *begin_visit (const FunctionCall& v) 
{
  TRACE_VISIT ();

  rchandle<QName> qn_h = v.get_fname();
  string prefix = qn_h->get_prefix();
  string fname = qn_h->get_localname();

  store::Item_t qname = sctx_p->lookup_fn_qname(prefix, fname, loc);
  string key = "F" + static_context::qname_internal_key(qname);

  if (! prolog_vf_key.empty())
    add_multimap_value(thePrologDeps, prolog_vf_key, key);

  nodestack.push(NULL);
  return no_state;
}

void end_visit (const FunctionCall& v, void* /*visit_state*/) 
{
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

  const xqpStringStore* fn_ns = sctx_p->lookup_fn_qname(prefix, fname, loc)->getNamespace();

  if (fn_ns->byteEqual(XQUERY_FN_NS)) 
  {
    if (fname == "position" && sz == 0)  
    {
      nodestack.push(lookup_ctx_var(DOT_POS_VARNAME, loc).getp());
      return;
    }
    else if (fname == "last" && sz == 0)
    {
      nodestack.push(lookup_ctx_var(LAST_IDX_VARNAME, loc).getp());
      return;
    }
    else if (fname == "number") 
    {
      switch (sz) 
      {
      case 0:
        arguments.push_back(DOT_VAR);
        break;
      case 1:
        break;
      default:
        ZORBA_ERROR_LOC_PARAM( XPST0017, loc, "fn:number", sz );
      }

      varref_t tv = tempvar(loc, var_expr::let_var);

      expr_t nan_expr = new const_expr (cb->m_cur_sctx, loc, xqp_double::nan());

      expr_t ret = new if_expr (cb->m_cur_sctx,
                                loc,
                                new castable_expr(cb->m_cur_sctx, loc,
                                                  &*tv,
                                                  GENV_TYPESYSTEM.DOUBLE_TYPE_ONE),
                                new cast_expr(cb->m_cur_sctx, loc,
                                              &*tv,
                                              GENV_TYPESYSTEM.DOUBLE_TYPE_ONE),
                                nan_expr);

      expr_t data_expr = wrap_in_atomization(arguments[0]);

      nodestack.push(&*wrap_in_let_flwor(new treat_expr(cb->m_cur_sctx,
                                                        loc,
                                                        data_expr,
                                                        GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION,
                                                        XPTY0004),
                                         tv,
                                         ret));
      return;
    }
    else if (sz == 0 && xquery_fns_def_dot.find(fname) != xquery_fns_def_dot.end()) 
    {
      arguments.push_back(DOT_VAR);
    }
    else if (fname == "static-base-uri") 
    {
      if (sz != 0)
        ZORBA_ERROR_LOC_PARAM( XPST0017, loc, "fn:static-base-uri", sz );

      xqp_string baseuri = sctx_p->final_baseuri ();
      if (baseuri.empty ())
        nodestack.push (create_seq (loc));
      else
        nodestack.push (new cast_expr (cb->m_cur_sctx, loc,
                                       new const_expr (cb->m_cur_sctx, loc, baseuri),
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
      rchandle<const_expr> constExpr = new const_expr(cb->m_cur_sctx, loc, xqpString(" " ));

      normExpr = new fo_expr(cb->m_cur_sctx, loc, LOOKUP_FN("fn", "normalize-space", 1));
      normExpr->add(flworVarExpr);
      tokenExpr = new fo_expr(cb->m_cur_sctx, loc, LOOKUP_FN("fn", "tokenize", 2));
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
    else if (sz == 1 && fname == "resolve-uri") 
    {
      arguments.insert (arguments.begin (), new const_expr (cb->m_cur_sctx, loc, sctx_p->final_baseuri()));
    }
    else if (sz == 1 && fname == "parse") 
    {
      arguments.insert (arguments.begin (), new const_expr (cb->m_cur_sctx, loc, sctx_p->final_baseuri()));
    }
    else if (fname == "concat")
    {
      if (sz < 2)
        ZORBA_ERROR_LOC_PARAM (XPST0017, loc, "concat", to_string (sz));
    }
    else if (fname == "doc")
    {
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
  }
  else if (fn_ns->byteEqual(ZORBA_FN_NS)) 
  {
    if (fname == "inline-xml" && sz == 1) {
      nodestack.push (new eval_expr(cb->m_cur_sctx, loc, create_cast_expr (loc, arguments [0], GENV_TYPESYSTEM.STRING_TYPE_ONE, true)));
      return;
    }
  }

  sz = arguments.size();  // recompute size

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
  {
    function* f = LOOKUP_FN(prefix, fname, sz);
    if (f == NULL)
      ZORBA_ERROR_LOC_PARAM(XPST0017,
                            loc,
                            (prefix.empty () ? prefix : (prefix + ":")) + fname,
                            to_string(sz));
    
    if (NULL != dynamic_cast<user_function *> (f)) 
    {
      // a udf function
      if (! fn_decl_stack.empty()) 
      {
        user_function *udf = dynamic_cast<user_function *> (fn_decl_stack.back ());
        ZORBA_ASSERT (udf != NULL);
        udf->setLeaf(false);
        // cout << "UDF " << udf->get_fname ()->getStringValue () << " non-leaf due to " << f->get_fname ()->getStringValue () << endl;
      }
    }

    rchandle<fo_expr> fo_h = new fo_expr (cb->m_cur_sctx, loc, f);

    // TODO this should be a const iterator
    vector<expr_t>::reverse_iterator iter = arguments.rbegin();
    for(; iter != arguments.rend(); ++iter)
      fo_h->add(*iter);

    nodestack.push(&*fo_h);
  }
}


/*******************************************************************************
  [116a] ArgList := ExprSingle ("," ExprSingle)*
********************************************************************************/
void *begin_visit (const ArgList& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ArgList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************

  Node Construction

  [117] Constructor ::= DirectConstructor | ComputedConstructor

  [118] DirectConstructor ::= DirElemConstructor |
                              DirCommentConstructor |
                              DirPIConstructor

********************************************************************************/


/*******************************************************************************
  [119]  DirElemConstructor ::= "<" QName DirAttributeList?
                                ("/>" |
                                 (">" DirElemContentList? "</" QName S? ">")) 
********************************************************************************/
void *begin_visit (const DirElemConstructor& v) 
{
  TRACE_VISIT();
  push_scope();
  push_elem_scope();
  return no_state;
}

void end_visit (const DirElemConstructor& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  expr_t nameExpr;
  expr_t attrExpr;
  expr_t contentExpr;

  rchandle<QName> end_tag = v.get_end_name();
  rchandle<QName> start_tag = v.get_elem_name ();

  if (end_tag != NULL && start_tag->get_qname() != end_tag->get_qname ())
    ZORBA_ERROR_LOC_DESC(XPST0003, loc, string("Start tag ") + start_tag->get_qname() + " does not match end tag " + end_tag->get_qname());

  if (v.get_dir_content_list() != NULL)
    contentExpr = pop_nodestack();

  if (v.get_attr_list() != NULL)
    attrExpr = pop_nodestack();

  nameExpr = new const_expr(cb->m_cur_sctx,
                            loc,
                            sctx_p->lookup_elem_qname(v.get_elem_name()->get_qname(),
                                                      loc));

  nodestack.push(new elem_expr(cb->m_cur_sctx,
                               loc,
                               nameExpr,
                               attrExpr,
                               contentExpr,
                               ns_ctx));
  pop_elem_scope();
  pop_scope();
}


/*******************************************************************************
   [120] DirAttributeList ::= DirAttr | DirAttributeList  DirAttr
********************************************************************************/
void *begin_visit (const DirAttributeList& v) 
{
  TRACE_VISIT ();

  nodestack.push(NULL);

  // visit namespace declaratrion attributes first
  for (int visitType = 0; visitType < 2; visitType++)
  {
    for (int i = 0; i < v.size (); i++) 
    {
      const DirAttr* attr = v[i];
      const QName* qname = attr->get_name().getp();
      bool isPrefix = qname->get_qname() == "xmlns" || qname->get_prefix() == "xmlns";

      if ((isPrefix && visitType == 0) || (! isPrefix && visitType == 1))
        attr->accept(*this);
    }
  }

  unsigned long numAttrs = 0;
  vector<rchandle<attr_expr> > attributes;
  while(true) 
  {
    expr_t expr = pop_nodestack();
    if (expr == NULL)
      break;

    attr_expr* attrExpr = expr.dyn_cast<attr_expr> ().getp();

    for (unsigned long i = 0; i < numAttrs; i++) 
    {
      if (attributes[i]->getQName()->equals(attrExpr->getQName()))
         ZORBA_ERROR_LOC( XQST0040, loc);
    }

    attributes.push_back(attrExpr);
    numAttrs++;
  }

  if (attributes.size() == 1)
  {
    nodestack.push(attributes[0].getp());
  }
  else
  {
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

void end_visit (const DirAttributeList& v, void* /*visit_state*/) 
{
  // begin_visit() rejects visitor
  ZORBA_ASSERT (false);
}


/*******************************************************************************
  [120a] DirAttr ::= (S (QName S? "=" S? DirAttributeValue)
********************************************************************************/
void *begin_visit (const DirAttr& v) 
{
  TRACE_VISIT ();
  // boundary is needed because the value of an attribute might be empty
  nodestack.push(NULL);
  return no_state;
}

void end_visit (const DirAttr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  expr_t valueExpr = pop_nodestack();

  if (valueExpr != NULL) 
  {
    // delete boundary
    nodestack.pop();
  }

  QName* qname = v.get_name().getp();

  if (qname->get_qname() == "xmlns" || qname->get_prefix() == "xmlns") 
  {
    xqpStringStore_t prefix;

    if (qname->get_qname() != "xmlns") 
    {
      prefix = new xqpStringStore(qname->get_localname());
      if (prefix->byteEqual("xmlns"))
        ZORBA_ERROR_LOC (XQST0070, loc);
    }
    else
    {
      // else we have a defult-namespace declaration
      prefix = new xqpStringStore("");
    }

    const_expr* constValueExpr = valueExpr.dyn_cast<const_expr> ().getp();
    if (constValueExpr != NULL) 
    {
      xqpStringStore_t uri = constValueExpr->get_val()->getStringValue();

      if (prefix->byteEqual("xml") && !uri->byteEqual(XML_NS))
        ZORBA_ERROR_LOC (XQST0070, loc);

      sctx_p->bind_ns(prefix.getp(), uri.getp(), XQST0071);
      ns_ctx->bind_ns(prefix, uri);
    }
    else if (valueExpr == NULL)
    {
      if (prefix->byteEqual("xml"))
        ZORBA_ERROR_LOC(XQST0070, loc);

      // unbind the prefix
      xqpStringStore_t uri = new xqpStringStore("");
      sctx_p->bind_ns(prefix.getp(), "", XQST0071);
      ns_ctx->bind_ns(prefix, uri);
    }
    else
    {
      ZORBA_ERROR_LOC( XQST0022, loc);
    }
  }
  else
  {
    expr_t nameExpr = new const_expr(cb->m_cur_sctx,
                                     loc,
                                     sctx_p->lookup_qname("",
                                                          qname->get_qname(),
                                                          qname->get_location()));

    expr_t attrExpr = new attr_expr(cb->m_cur_sctx, loc, nameExpr, valueExpr);

    nodestack.push(attrExpr);
  }
}


/*******************************************************************************
  [119a] DirElemContentList ::= DirElemContent |
                                DirElemContentList DirElemContent
********************************************************************************/
void *begin_visit (const DirElemContentList& v) 
{
  TRACE_VISIT ();
  nodestack.push(NULL);
  return no_state;
}

void end_visit (const DirElemContentList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  rchandle<fo_expr> expr_list = create_seq (loc);
  while (true) 
  {
    expr_t e_h = pop_nodestack();
    if (e_h == NULL)
      break;
    expr_list->add(e_h);
  }

  if (expr_list->size() == 1)
    nodestack.push(*expr_list->begin());
  else 
  {
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
      expr_t content = new const_expr (cb->m_cur_sctx, loc, v.get_elem_content());
      nodestack.push (new text_expr(cb->m_cur_sctx, loc,
                                    text_expr::text_constructor,
                                    content));
    }
  }
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



void *begin_visit (const CDataSection& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CDataSection& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  expr_t content = new const_expr (cb->m_cur_sctx, loc, v.get_cdata_content ());
  nodestack.push (new text_expr (cb->m_cur_sctx, loc, text_expr::text_constructor, content));
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
    nodestack.push(new const_expr (cb->m_cur_sctx, loc, content));

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

    expr_t lConstExpr = new const_expr(cb->m_cur_sctx, loc, content);
    nodestack.push(lConstExpr);
    break;
  }
  case ParseConstants::cont_escape_lbrace:
    {
    // we always create a text node here because if we are in an attribute, we atomice
    // the text node into its string value
    xqpString content("{");
    expr_t lConstExpr = new const_expr(cb->m_cur_sctx, loc, content);
    nodestack.push ( lConstExpr );
    break;
  }
  case ParseConstants::cont_escape_rbrace:
  {
    // we always create a text node here because if we are in an attribute, we atomice
    // the text node into its string value
    xqpString content("}");
    expr_t lConstExpr = new const_expr(cb->m_cur_sctx, loc, content);
    nodestack.push ( lConstExpr );
    break;
  }
  case ParseConstants::cont_expr:
  {
    break;
  }
  }
}


void *begin_visit (const DirCommentConstructor& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const DirCommentConstructor& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  xqpString str = v.get_comment();
  expr_t content = new const_expr (cb->m_cur_sctx, loc, str);
  nodestack.push (new text_expr(cb->m_cur_sctx, loc,
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
    target = new const_expr (cb->m_cur_sctx, loc, target_str),
    content = new const_expr (cb->m_cur_sctx, loc, v.get_pi_content ());
  nodestack.push (new pi_expr (cb->m_cur_sctx, loc, target,  content));
}


void *begin_visit (const CompDocConstructor& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CompDocConstructor& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  expr_t lContent = pop_nodestack();

  fo_expr *lEnclosed = new fo_expr(cb->m_cur_sctx, loc, CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
  lEnclosed->add(lContent);

  nodestack.push (new doc_expr (cb->m_cur_sctx, loc, lEnclosed ));
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

    fo_expr *lEnclosed = new fo_expr(cb->m_cur_sctx, loc, CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
    lEnclosed->add(contentExpr);
    contentExpr = lEnclosed;
  }

  QName* constQName = v.get_qname_expr().dyn_cast<QName> ().getp();

  if (constQName != NULL) {
    nameExpr = new const_expr(cb->m_cur_sctx, loc,
                              sctx_p->lookup_elem_qname(constQName->get_qname(), loc));
      } else {
    nameExpr = pop_nodestack();

    rchandle<fo_expr> atomExpr = (fo_expr*)wrap_in_atomization (nameExpr).getp();
    nameExpr = new name_cast_expr(cb->m_cur_sctx, loc, atomExpr.getp(), ns_ctx);
      }

  nodestack.push (new elem_expr(cb->m_cur_sctx, loc, nameExpr, contentExpr, ns_ctx));
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

    fo_expr* enclosedExpr = new fo_expr(cb->m_cur_sctx, loc, CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
    enclosedExpr->add(valueExpr);

    valueExpr = enclosedExpr;
    }

  QName* constQName = v.get_qname_expr().dyn_cast<QName> ().getp();

  if (constQName != NULL) {
    nameExpr = new const_expr(cb->m_cur_sctx, loc,
                              sctx_p->lookup_qname("", constQName->get_qname(), constQName->get_location()));
  } else {
    nameExpr = pop_nodestack();

    rchandle<fo_expr> atomExpr = (fo_expr*)wrap_in_atomization (nameExpr).getp();

    expr_t castExpr = new name_cast_expr(cb->m_cur_sctx, loc,
                                         atomExpr.getp(),
                                         ns_ctx);
    nameExpr = castExpr;
      }

  attrExpr = new attr_expr(cb->m_cur_sctx, loc, nameExpr, valueExpr);

  nodestack.push(attrExpr);
    }


void *begin_visit (const CompCommentConstructor& v) {
  TRACE_VISIT ();
  return no_state;
    }

void end_visit (const CompCommentConstructor& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  expr_t inputExpr = pop_nodestack();

  rchandle<fo_expr> enclosedExpr = new fo_expr(cb->m_cur_sctx, loc,
                                               CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
  enclosedExpr->add(inputExpr);

  expr_t textExpr = new text_expr(cb->m_cur_sctx, loc,
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

    rchandle<fo_expr> enclosedExpr = new fo_expr(cb->m_cur_sctx, loc, CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
    enclosedExpr->add(content);

    content = enclosedExpr;
  }

  if (v.get_target_expr() != NULL) {
    target = pop_nodestack();

    rchandle<fo_expr> atomExpr = (fo_expr*)wrap_in_atomization (target).getp();

    rchandle<cast_expr> castExpr =
      new cast_expr(cb->m_cur_sctx, loc, atomExpr.getp(),
                    GENV_TYPESYSTEM.NCNAME_TYPE_ONE);

    rchandle<fo_expr> enclosedExpr = new fo_expr(cb->m_cur_sctx, loc, CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
    enclosedExpr->add(castExpr.getp());

    target = enclosedExpr;
  }

  expr_t e = (v.get_target_expr () != NULL ?
              new pi_expr (cb->m_cur_sctx, loc, target, content) :
              new pi_expr (cb->m_cur_sctx, loc, new const_expr (cb->m_cur_sctx, loc, v.get_target()), content));

  nodestack.push (e);
}


void *begin_visit (const CompTextConstructor& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CompTextConstructor& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();

  expr_t inputExpr = pop_nodestack();

  rchandle<fo_expr> enclosedExpr = new fo_expr(cb->m_cur_sctx, loc,
                                               CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
  enclosedExpr->add(inputExpr);

  expr_t textExpr = new text_expr(cb->m_cur_sctx, loc,
                                  text_expr::text_constructor,
                                  enclosedExpr.getp());

  nodestack.push(textExpr);
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
      fo = new fo_expr(cb->m_cur_sctx, v.get_location(), LOOKUP_RESOLVED_FN(ZORBA_OPEXTENSIONS_NS, "build-index", 1));
      break;

    case IndexStatement::create_stmt:
      fo = new fo_expr(cb->m_cur_sctx, v.get_location(), LOOKUP_RESOLVED_FN(ZORBA_OPEXTENSIONS_NS, "create-index", 1));
      break;

    case IndexStatement::drop_stmt:
      fo = new fo_expr(cb->m_cur_sctx, v.get_location(), LOOKUP_RESOLVED_FN(ZORBA_OPEXTENSIONS_NS, "drop-index", 1));
      break;
  }
  store::Item_t uri_item;
  GENV_ITEMFACTORY->createAnyURI(uri_item, v.get_uri().c_str());
  expr_t uri(new const_expr(cb->m_cur_sctx, v.get_location(), uri_item));
  fo->add(uri);
  nodestack.push((const rchandle<fo_expr>&)fo);

  TRACE_VISIT_OUT ();
}




void reorder_globals () {
  // STEP 1: Floyd-Warshall transitive closure of edges starting from functions
  for (list<function *>::iterator k = prolog_fn_decls.begin ();
       k != prolog_fn_decls.end (); k++)
  {
    string kkey = "F" + static_context::qname_internal_key ((*k)->get_fname ());
    strset_t kedges;    
    if (! thePrologDeps.get (kkey, kedges))
      continue;

    for (set<string>::iterator j = kedges->begin (); j != kedges->end (); j++) {
      string jkey = *j;
      for (list<function *>::iterator i = prolog_fn_decls.begin ();
           i != prolog_fn_decls.end (); i++)
      {
        string ikey = "F" + static_context::qname_internal_key ((*i)->get_fname ());
        strset_t iedges, new_iedges;
        if (thePrologDeps.get (ikey, iedges)
            && iedges->find (kkey) != iedges->end ()
            && iedges->find (jkey) == iedges->end ()) {
          // cout << "Added " << ikey << " -> " << kkey << " -> " << jkey << endl;
          iedges->insert (jkey);
        }
      }
    }
  }

  // STEP 2: add var -> fn -> var dependencies found above
  for (list<string>::iterator i = prolog_var_decls.begin ();
       i != prolog_var_decls.end (); i++)
  {
    string ikey = "V" + *i;
    strset_t iedges;
    if (! thePrologDeps.get (ikey, iedges))
      continue;
    set<string> new_iedges;
    for (set<string>::iterator k = iedges->begin (); k != iedges->end (); k++) {
      string kkey = *k;
      strset_t kedges;
      if (kkey [0] == 'F' && thePrologDeps.get (kkey, kedges))
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
  for (list<string>::iterator i = prolog_var_decls.begin ();
       i != prolog_var_decls.end (); i++)
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
        if (thePrologDeps.get ("V" + ikey, iedges)) {
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

  // STEP 4: reorder thePrologVars according to topological order
  #if 1
  map<string, global_binding> gvmap;
  for (list<global_binding>::iterator i = thePrologVars.begin ();
       i != thePrologVars.end (); i++)
  {
    store::Item_t qname = (*i).first->get_varname ();
    gvmap [static_context::qname_internal_key (qname)] = *i;
  }
  thePrologVars.clear ();
  for (list<string>::iterator i = topsorted_vars.begin ();
       i != topsorted_vars.end (); i++) {
    map<string, global_binding>::iterator p = gvmap.find (*i);
    if (p != gvmap.end ())
      thePrologVars.push_back ((*p).second);
  }
  #endif
}




/*******************************************************************************


********************************************************************************/


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

void end_visit (const OccurrenceIndicator& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


void *begin_visit (const AtomicType& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const AtomicType& v, void* /*visit_state*/) 
{
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

   KindTest

********************************************************************************/


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
    rchandle<match_expr> me = new match_expr(cb->m_cur_sctx, loc);
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
      match = new match_expr(cb->m_cur_sctx, loc);
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
                                               false,
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
    rchandle<match_expr> me = new match_expr(cb->m_cur_sctx, loc);
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
                                                nillable,
                                                false);
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

    rchandle<match_expr> match = new match_expr(cb->m_cur_sctx, loc);
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
    rchandle<match_expr> match = new match_expr(cb->m_cur_sctx, loc);
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
                                                false,
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

    rchandle<match_expr> match = new match_expr(cb->m_cur_sctx, loc);
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
    rchandle<match_expr> match = new match_expr(cb->m_cur_sctx, loc);
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
    rchandle<match_expr> match = new match_expr(cb->m_cur_sctx, loc);
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
    rchandle<match_expr> match = new match_expr(cb->m_cur_sctx, loc);
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
                                                    false,
                                                    false);
      tstack.push (t);
    }
  }
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
  expr_t aDelete = new delete_expr(cb->m_cur_sctx, loc, lTarget);
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
  fo_expr* lEnclosed = new fo_expr(cb->m_cur_sctx, loc, CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
  lEnclosed->add(lSource);
  lSource = lEnclosed;

  expr_t lInsert = new insert_expr(cb->m_cur_sctx, loc, v.getType(), lSource, lTarget);
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
  nameExpr = new name_cast_expr(cb->m_cur_sctx, loc, atomExpr.getp(), ns_ctx);

  expr_t renameExpr = new rename_expr(cb->m_cur_sctx, loc, targetExpr, nameExpr);

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
    fo_expr* lEnclosed = new fo_expr(cb->m_cur_sctx, loc, CACHED (op_enclosed_expr, LOOKUP_OP1 ("enclosed-expr")));
    lEnclosed->add(lReplacement);
    lReplacement = lEnclosed;
  }

  expr_t lReplace = new replace_expr(cb->m_cur_sctx, loc,
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

  std::auto_ptr<transform_expr> lTransform(new transform_expr(cb->m_cur_sctx, loc, lModify, lReturn));

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

    copy_clause* copyClause = new copy_clause(lVarExpr, lExpr);
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
  nodestack.push(new trycatch_expr(cb->m_cur_sctx, loc));
  return no_state;
}

void end_visit (const TryExpr& v, void* visit_state) {
  TRACE_VISIT_OUT ();
}


void *begin_visit (const EvalExpr& v) 
{
  TRACE_VISIT ();
  if (xquery_version <= StaticContextConsts::xquery_version_1_0)
    ZORBA_ERROR_LOC (XPST0003, loc);
  return no_state;
}

void end_visit (const EvalExpr& v, void* visit_state) 
{
  TRACE_VISIT_OUT ();

  rchandle<eval_expr> result =
    new eval_expr(cb->m_cur_sctx,
                  loc,
                  create_cast_expr(loc,
                                   pop_nodestack(),
                                   GENV_TYPESYSTEM.STRING_TYPE_ONE,
                                   true));

  rchandle<VarGetsDeclList> vgdl = v.get_vars ();
  
  for (size_t i = 0; i < vgdl->size(); i++) 
  {
    varref_t ve = pop_nodestack ().dyn_cast<var_expr> ();
    ve->set_kind (var_expr::eval_var);
    expr_t val = pop_nodestack ();

    if (ve->get_type () != NULL)
      val = new treat_expr(cb->m_cur_sctx,
                           val->get_loc(),
                           val,
                           ve->get_type(),
                           XPTY0004);

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

  if (v.getVarErrorDescr() != "") {
      varref_t dv = bind_var(loc, v.getVarErrorDescr(), var_expr::catch_var, GENV_TYPESYSTEM.STRING_TYPE_QUESTION);
      cc->set_errordesc_var_h(dv);
      if (v.getVarErrorVal() != "") {
        varref_t vv = bind_var(loc, v.getVarErrorVal(), var_expr::catch_var, GENV_TYPESYSTEM.ITEM_TYPE_QUESTION);
        cc->set_errorobj_var_h(vv);
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


void *begin_visit (const AssignExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const AssignExpr& v, void* visit_state) 
{
  TRACE_VISIT_OUT ();

  // TODO: add treat_expr to check var type
  const function *ctx_set = LOOKUP_OP2 ("ctxvar-assign");
  varref_t ve = lookup_ctx_var (v.get_varname (), loc);
  if (ve->get_kind() != var_expr::local_var && ve->get_kind() != var_expr::prolog_var)
    ZORBA_ERROR_LOC (XPST0003, loc);

  expr_t qname_expr = new const_expr(cb->m_cur_sctx,
                                     ve->get_loc(),
                                     dynamic_context::var_key (&*ve));

  nodestack.push (new fo_expr (cb->m_cur_sctx, loc, ctx_set, qname_expr, pop_nodestack ()));
}


void *begin_visit (const ExitExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ExitExpr& v, void* visit_state) {
  TRACE_VISIT_OUT ();
  nodestack.push (new exit_expr (cb->m_cur_sctx, loc, pop_nodestack ()));
}

void *begin_visit (const WhileExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const WhileExpr& v, void* visit_state) {
  TRACE_VISIT_OUT ();
  rchandle<sequential_expr> body = pop_nodestack ().cast<sequential_expr> ();
  expr_t cond = pop_nodestack ();
  body->push_front (new if_expr (cb->m_cur_sctx, loc, cond, create_seq (loc), new flowctl_expr (cb->m_cur_sctx, loc, flowctl_expr::BREAK)));
  nodestack.push (new while_expr (cb->m_cur_sctx, loc, body.getp()));
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
  nodestack.push (new flowctl_expr (cb->m_cur_sctx, loc, a));
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


public:

expr_t result () 
{
  if (nodestack.size () != 1) 
  {
    cout << "Error: extra nodes on translator stack:\n";
    while (! nodestack.empty ()) 
    {
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

  if (scope_depth != 0) 
  {
    cout << "Error: scope depth " << scope_depth << endl;
    ZORBA_ASSERT (false);
  }

  return pop_nodestack ();
}

};


expr_t translate_aux(
    const parsenode& root,
    CompilerCB* aCompilerCB,
    ModulesInfo* minfo,
    set<string> mod_stack,
    bool isLibModule) 
{
  auto_ptr<TranslatorImpl> t(new TranslatorImpl(aCompilerCB,
                                                minfo,
                                                mod_stack,
                                                isLibModule));

  root.accept (*t);

  rchandle<expr> result = t->result ();

  if (aCompilerCB->m_config.translate_cb != NULL)
    aCompilerCB->m_config.translate_cb (&*result, "XQuery program");

  return result;
}


expr_t translate (const parsenode& root, CompilerCB* aCompilerCB) 
{
  set<string> mod_stack;

  if (typeid (root) != typeid (MainModule))
    ZORBA_ERROR_LOC_DESC(XPST0003,
                         root.get_location(),
                         "Module declaration must not be used in a main module");

  ModulesInfo minfo (aCompilerCB);

  return translate_aux (root, aCompilerCB, &minfo, mod_stack, false);
}

} /* namespace zorba */

