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
#include "stdafx.h"

#include <sstream>
#include <iterator>
#include <stack>
#include <map>
#include <bitset>

#include <zorba/config.h>
#include <zorba/diagnostic_list.h>


#include "common/common.h"

#include "store/api/item.h"
#include "store/api/update_consts.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"

#include "runtime/api/plan_wrapper.h"

#include "compiler/translator/prolog_graph.h"
#include "compiler/translator/translator.h"
#include "compiler/translator/module_version.h"
#include "compiler/api/compilercb.h"
#include "compiler/api/compiler_api.h"
#include "compiler/codegen/plan_visitor.h"
#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/parsetree/parsenode_visitor.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/script_exprs.h"
#include "compiler/expression/update_exprs.h"
#ifndef ZORBA_NO_FULL_TEXT
#include "compiler/expression/ft_expr.h"
#include "compiler/expression/ftnode.h"
#endif /* ZORBA_NO_FULL_TEXT */
#include "compiler/expression/var_expr.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/path_expr.h"
#include "compiler/expression/function_item_expr.h"
#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/rewriter/framework/rewriter.h"
#include "compiler/xqddf/value_index.h"
#include "compiler/xqddf/value_ic.h"
#include "compiler/xqddf/collection_decl.h"

#include "system/globalenv.h"
#include "system/properties.h"

#include "functions/library.h"
#include "functions/signature.h"
#include "functions/udf.h"
#include "functions/external_function.h"

#include "annotations/annotations.h"

#include "context/static_context.h"
#include "context/static_context_consts.h"
#include "context/namespace_context.h"

#include "types/node_test.h"
#include "types/casting.h"
#include "types/typeops.h"
#include "types/typemanagerimpl.h"
#include "types/schema/schema.h"

#include "zorbatypes/URI.h"
#include "zorbatypes/numconversions.h"

#ifdef ZORBA_WITH_DEBUGGER
#include "debugger/debugger_commons.h"
#endif

#include "zorbautils/string_util.h"
#include "zorbautils/fatal.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/dict.h"
#include "diagnostics/util_macros.h"

#include "util/ascii_util.h"
#include "util/stl_util.h"
#include "util/string_util.h"
#include "util/tracer.h"
#include "util/utf8_util.h"
#include "util/xml_util.h"
#include "util/hashmap.h"


#define NODE_SORT_OPT


namespace zorba
{

class ModulesInfo;
class TranslatorImpl;

static expr_t translate_aux(
    TranslatorImpl* rootTranslator,
    const parsenode& root,
    static_context* rootSctx,
    short rootSctxId,
    ModulesInfo* minfo,
    const std::map<zstring, zstring>& modulesStack,
    bool isLibModule,
    StaticContextConsts::xquery_version_t maxLibModuleVersion =
      StaticContextConsts::xquery_version_unknown);

/*******************************************************************************

********************************************************************************/
#ifndef NDEBUG

#define TRACE_VISIT()                                                   \
  const QueryLoc& loc = v.get_location(); (void)loc;                    \
                                                                        \
  if (Properties::instance()->traceTranslator())                        \
    std::cout << std::string(++thePrintDepth, ' ') << TRACE << ", stk size "   \
              << theNodeStack.size() << ", tstk size: " << theTypeStack.size() \
              << ", scope depth " << theScopeDepth << std::endl;


#define TRACE_VISIT_OUT()                                               \
  const QueryLoc& loc = v.get_location(); (void)loc;                    \
                                                                        \
  if (Properties::instance()->traceTranslator())                        \
    std::cout << std::string(thePrintDepth--, ' ') << TRACE << ", stk size: "  \
              << theNodeStack.size() << ", tstk size: " << theTypeStack.size() \
              << ", scope depth " << theScopeDepth << std::endl;

#else

#define TRACE_VISIT()                                              \
  const QueryLoc& loc = v.get_location(); (void)loc;               \


#define TRACE_VISIT_OUT()                                          \
  const QueryLoc& loc = v.get_location(); (void)loc;               \

#endif


/*******************************************************************************

********************************************************************************/
#define ZANN_CONTAINS( ann ) theAnnotations->contains(AnnotationInternal::ann)


/*******************************************************************************
  Check/set certain bool data members of TranslatorImpl: raise error if true
  already otherwise set to true.
********************************************************************************/
#define CHK_SINGLE_DECL( state, err ) \
do { if (state) throw XQUERY_EXCEPTION(err); state = true; } while (0)


/*******************************************************************************

********************************************************************************/
#define ITEM_FACTORY (GENV.getStore().getItemFactory())

#define CTX_TM theSctx->get_typemanager()


/*******************************************************************************
  Internal names for certain implicit vars
********************************************************************************/
#define DOT_VARNAME getDotVarName()
#define DOT_POS_VARNAME getDotPosVarName()
#define LAST_IDX_VARNAME getLastIdxVarName()

#define DOT_REF                                             \
  new wrapper_expr(theRootSctx,                             \
                   loc,                                     \
                   lookup_ctx_var(DOT_VARNAME, loc).getp())

namespace translator_ns
{

/*******************************************************************************

********************************************************************************/
template<class T> T& peek_stack(std::stack<T> &stk)
{
  ZORBA_ASSERT(! stk.empty());
  return stk.top();
}


template <typename T> T pop_stack(std::stack<T> &stk)
{
  T x = translator_ns::peek_stack(stk);
  stk.pop();
  return x;
}
}


/*******************************************************************************

********************************************************************************/
struct NodeSortInfo
{
  bool    theSingleInput;
  bool    theOnlyChildAxes;
  bool    theHaveFilterSteps;
  ulong   theNumSteps;

  NodeSortInfo()
    :
    theSingleInput(true),
    theOnlyChildAxes(true),
    theHaveFilterSteps(false),
    theNumSteps(0)
  {
  }
};

/*******************************************************************************

  There is only one ModulesInfo instance per compilation. It is created on the
  stack by the translate() method.

  theCCB        : The control block for the whole query.
                  (see compiler/api/compilercb.h).

  mod_ns_map    : Maps resolved module location uris to target namespaces.
                  Used to skip compilation of a module that has been compiled
                  already (for example this is the case when 2 imported modules
                  both import a common module). It is also used to make sure
                  that a location uri does not appear in two module import
                  statements with different target namespaces.

  mod_sctx_map  : Maps resolved module location uris to sctx objs containing
                  the var and udf declarations that are exported by the
                  modules corresponding to the location uris.

  theInitExprs  : Contains the initializing expr for each prolog var in each
                  module participating in the compilation (see method
                  wrap_in_globalvar_assigh())

  globalSctx    : A single static_context which contains ALL function and
                  variable declarations from ALL imported modules. This is
                  used to catch conflicting definitions.

********************************************************************************/
class ModulesInfo
{
public:
  CompilerCB                        * theCCB;
  hashmap<zstring, static_context_t>  mod_sctx_map;
  hashmap<zstring, zstring>           mod_ns_map;
  checked_vector<expr_t>              theInitExprs;
  std::auto_ptr<static_context>       globalSctx;

public:
  ModulesInfo(CompilerCB* topCompilerCB)
    :
    theCCB(topCompilerCB),
    globalSctx(static_cast<static_context *>
               (topCompilerCB->theRootSctx->get_parent())->create_child_context())
  {
  }
};



/*******************************************************************************

  A new instance of TranslatorImpl is created for the translation of each
  module component participating in a query. The instance is destroyed when
  the translation of the associated module component is finished.

  theRootTranslator :
  -------------------
  Pointer to the root translator (The root translator points to itself).

  theRTM :
  --------
  Reference to the root type manager (cached here for convenience).

  theCCB :
  --------
  The control block for the whole query. (see compiler/api/compilercb.h).

  theModulesInfo :
  ----------------
  Pointer to the unique ModulesInfo instance (see class ModulesInfo above).

  theModulesStack :
  -----------------
  A map containing the URLs of all the module components in the chain of module
  imports from this module component up to the main module. For each such URL,
  the map also stores the target namespace URI of module component. This map is
  used to handle cycles in a chain of module imports.

  theHaveModuleImportCycle :
  --------------------------

  theImportedModules :
  --------------------
  A set containing the target namespace uris of the modules directly imported
  by this  module. Used to check that the same module is not imported twice by
  this module.

  theModuleNamespace :
  --------------------
  If this translator is working on a library module, theModuleNamespace is the
  namespace uri of that module.

  theModulePrefix :
  -----------------
  If this translator is working on a library module, theModulePrefix is the
  prefix associated with the ns uri of that module.

  theImportedSchemas :
  --------------------
   Set of ns uris for all schemas directly imported by this module. Used to
  check that the same schema is not imported twice by this module.

  theCurrSctxId :
  ---------------
  The numeric id of the last sctx that was added to theSctxMap of the query
  (see api/xqueryimpl.h).

  theRootSctx :
  -------------
  The root sctx obj of the module that is being translated by this translator.
  Every time an expr is created, theRootSctx is stored in the expr obj, so that
  each expr will be executed in the appropriate sctx.

  theSctx :
  ---------
  The "current" static context node. It is initialized with theRootSctx.

  theSctxList :
  -------------
  A list of static contexts which need to be kept alive only during the
  translation of a module. It's managed in push_scope and pop_scope. In
  DEBUGGER mode, this list remains empty.

  theSctxIdStack :
  ----------------
  In non-DEBUGGER mode, this stack remains empty.

  export_sctx :
  -------------

  In case this is a library module translator, export_sctx is populated with
  the variable, function, and xqddf declarations that are exported by the
  module, i.e., the var, udf, and xqddf declarations that appear in the prolog
  of this module. The export_sctx is created by the importing module, populated
  by the imported module, and then merged by the importing module into its own
  sctx. export_sctx is "shared" between importing and imported modules via the
  theModulesInfo->mod_sctx_map. export_sctx is needed because module import is
  not transitive: If M1 imports M2 and M2 imports M3, then M3's declarations
  must be seen by M2, but not by M1. This means, that the regular root sctx
  S2 of M2 will contain the decls from both M2 and M3. So, M1 should not import
  S2 into its own sctx S1. Instead, we create ES2 for M2 and register in there
  the decls of M2 only; then, we import ES2 to S1.

  theNSCtx :
  ----------

  The "current" namespace bindings node. It is initialized with a newly allocated
  theNSCtx node, which points to the initial sctx node. The initial sctx node
  stores all ns bindings that are declared in the prolog. theNSCtx nodes are
  created to store ns bindings declared in element constructors. In general, the
  theNSCtx hierarchy (of which the initial sctx node and its ancestors are
  considered to be part of) defines the namepsace bindings that are in scope
  for each expr. theNSCtx nodes are kept separate from sctx nodes because sctx
  nodes may disappear after translation is done, whereas certain exprs need to
  know their theNSCtx in later compilation phases as well.

  thePrintDepth :
  ---------------
   For pretty tracing

  theScopeDepth :
  ---------------
  Incremented/Decremented every time a scope is pushed/popped. Used for some
  sanity checking only.

  thePrologVars :
  ---------------
  thePrologVars vector contains one entry for each var V declared in the prolog
  of this module. The entry maps the var_expr for V to the expr E that initializes
  V (E is NULL for vars without init expr). At the end of each module translation,
  the method wrap_in_globalvar_assign() creates appropriate initialization exprs
  for each var in thePrologVars and registers them in theModulesInfo->theInitExprs,
  so that they will be incorporated in the whole query plan at the end of the
  translation of the root module.

  thePrologGraph :
  ----------------

  A data struct implementing the dependency graph among the variables and udfs
  declared in the prolog of a module. An edge (v1, v2) in this graph indicates
  that v1 depends on v2 (where v1 and v2 may represent either var or udf decls).
  Examples:
  - $x := $y + g($z)  :  $x --> ($y, g, $z)
  - f { $y + g($z) }  :  f  --> ($y, g, $z)
  Initially only direct dependencies are registered. The graph is later expanded
  by the reorder_globals() method to include transitive dependencies as well.
  Then, the graph is used to sort thePrologVars so that vars are initialized
  before they are referenced.

  theCurrentPrologVFDecl :
  ------------------------

  During the translation of a variable or function declaration in the prolog,
  theCurrentPrologVFDecl stores a ptr to associated var_expr or function obj,
  respectively. It is used in building the thePrologGraph: if theCurrentPrologVFDecl
  is not NULL, then the translator knows that it is in the scope of a var
  or function decl, and if that declaration references another var V or calls
  another function F, then it creates a dependency between the var or function
  specified by theCurrentPrologVFDecl and V or F. The same mechanism is used to
  detect "leaf" udfs, i.e., udfs that do not invoke other udfs. Such udfs are
  inlined by the optimizer.

  theHaveUpdatingExitExprs :
  --------------------------

  theHaveSequentialExitExprs :
  ----------------------------

  theAssignedVars :
  -------------------

  Local or global variables which are currently in-scope and for which (a)
  an assignment statement has been encountered, and (b) the block expr that
  declares the var has not been exited yet. This is used to determine the
  category of expressions.

  theTempVarCounter :
  -------------------

  Counter used to generate names for internally generated variables. The names
  are unique within this translator.

  theNodestack :
  --------------

  If E is the expr that is currently being built, then theNodeStack contains all
  the ancestors (or ancestor place-holdres) of E in the expr tree.

  theTypeStack :
  --------------

  Stack of the static types for some of the exprs in theNodeStack.

  theFlworClausesStack :
  ----------------------

  theTryStack :
  ------------------

  Stack of try exprs. It is used to detect cases where a LET or window var is
  referenced inside a try block, but defined outside that block. In such cases,
  lazy materialization of the var must be disabled.

  theNodeSortStack :
  ------------------

  theAnnotations :
  ----------------

  Annotations belonging to the "current" variable or function declaration.
  After the variable or function has been translated, this member is set
  to null again.

  theIndexDecl :
  --------------

  Used during the translation of an index declaration to hold the IndexDecl obj.

  theIsInIndexDomain :
  --------------------

  Set to true just before translating the domain expr, and set back to false
  right after the translation of the domain expr is finished. It is used to
  check that the domain expr does not reference any external context item.

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

  xquery_fns_def_dot   : Set of the names of all built-in functions accepting
                         "." as their default arg. TODO: should be static

  theIsWSBoundaryStack : Saves true if the previous DirElemContent is a boundary
                         for whitespace (DirElemConstructor or EnclosedExpr).
  thePossibleWSContentStack: Saves the previous DirElemContent if it might be
                         bounded whitespace (if it contains whitespace and its
                         previous item is a whitespace boundary). It must be
                         checked if the next item is a whitespace boundary.

  op_concatenate       : Cached ptr to the function obj for the concat func
  op_enclosed_expr     : Cached ptr to the function obj for the enclosed_expr op

  theMaxLibModuleVersion  : This specifies the maximum module version for an
                         imported library. In case a version 1.0 module tries
                         to import a version 1.1 library, an error must be raised.
                         A value of xquery_version_unknown is interpreted as
                         "don't care".

********************************************************************************/
class TranslatorImpl : public parsenode_visitor
{
protected:
  TranslatorImpl                       * theRootTranslator;

  RootTypeManager                      & theRTM;

  CompilerCB                           * theCCB;

  ModulesInfo                          * theModulesInfo;
  std::map<zstring, zstring>             theModulesStack;
  bool                                   theHaveModuleImportCycle;
  std::set<std::string>                  theImportedModules;
  zstring                                theModuleNamespace;
  zstring                                theModulePrefix;

  std::set<std::string>                  theImportedSchemas;

  short                                  theCurrSctxId;

  static_context                       * theRootSctx;

  static_context                       * theSctx;

  std::vector<static_context_t>          theSctxList;

  std::stack<short>                      theSctxIdStack;

  static_context                       * export_sctx;

  rchandle<namespace_context>            theNSCtx;

  ulong                                  thePrintDepth;
  int                                    theScopeDepth;

  std::list<GlobalBinding>               thePrologVars;

  PrologGraph                            thePrologGraph;
  PrologGraphVertex                      theCurrentPrologVFDecl;

  bool                                   theHaveUpdatingExitExprs;

  bool                                   theHaveSequentialExitExprs;

  std::vector<std::vector<var_expr*> >   theAssignedVars;

  int                                    theTempVarCounter;

  std::stack<expr_t>                     theNodeStack;

#ifndef ZORBA_NO_FULL_TEXT
  std::stack<ftnode*>                    theFTNodeStack;
#endif

  std::stack<xqtref_t>                   theTypeStack;

  std::vector<flwor_clause_t>            theFlworClausesStack;

  std::vector<const parsenode*>          theTryStack;

  std::stack<NodeSortInfo>               theNodeSortStack;

  std::stack<bool>                       theInWhileStack;

  rchandle<AnnotationList>               theAnnotations;

  IndexDecl_t                            theIndexDecl;
  bool                                   theIsInIndexDomain;

  bool                                   hadBSpaceDecl;
  bool                                   hadBUriDecl;
  bool                                   hadConstrDecl;
  bool                                   hadCopyNSDecl;
  bool                                   hadDefNSDecl;
  bool                                   hadEmptyOrdDecl;
  bool                                   hadOrdModeDecl;
  bool                                   hadRevalDecl;

  std::stack<bool>                       theIsWSBoundaryStack;
  std::stack<const DirElemContent*>      thePossibleWSContentStack;

  std::bitset<FunctionConsts::FN_MAX_FUNC> xquery_fns_def_dot;

  function                           * op_concatenate;
  function                           * op_enclosed;

  rchandle<QName>                      theDotVarName;
  rchandle<QName>                      theDotPosVarName;
  rchandle<QName>                      theLastIdxVarName;

  std::vector<var_expr_t>              theScopedVars;

  StaticContextConsts::xquery_version_t theMaxLibModuleVersion;

public:

TranslatorImpl(
    TranslatorImpl* rootTranslator,
    static_context* rootSctx,
    short rootSctxId,
    ModulesInfo* minfo,
    const std::map<zstring, zstring>& modulesStack,
    bool isLibModule,
    StaticContextConsts::xquery_version_t maxLibModuleVersion =
      StaticContextConsts::xquery_version_unknown)
  :
  theRootTranslator(rootTranslator),
  theRTM(GENV_TYPESYSTEM),
  theCCB(minfo->theCCB),
  theModulesInfo(minfo),
  theModulesStack(modulesStack),
  theHaveModuleImportCycle(false),
  theCurrSctxId(rootSctxId),
  theRootSctx(rootSctx),
  theSctx(rootSctx),
  export_sctx(NULL),
  theNSCtx(new namespace_context(theSctx)),
  thePrintDepth(0),
  theScopeDepth(0),
  thePrologGraph(rootSctx),
  theHaveUpdatingExitExprs(false),
  theHaveSequentialExitExprs(false),
  theTempVarCounter(1),
  theIsInIndexDomain(false),
  hadBSpaceDecl(false),
  hadBUriDecl(false),
  hadConstrDecl(false),
  hadCopyNSDecl(false),
  hadDefNSDecl(false),
  hadEmptyOrdDecl(false),
  hadOrdModeDecl(false),
  hadRevalDecl(false),
  theMaxLibModuleVersion(maxLibModuleVersion)
{
  xquery_fns_def_dot.set(FunctionConsts::FN_STRING_LENGTH_0);
  xquery_fns_def_dot.set(FunctionConsts::FN_NORMALIZE_SPACE_0);
  xquery_fns_def_dot.set(FunctionConsts::FN_ROOT_0);
  xquery_fns_def_dot.set(FunctionConsts::FN_BASE_URI_0);
  xquery_fns_def_dot.set(FunctionConsts::FN_NAMESPACE_URI_0);
  xquery_fns_def_dot.set(FunctionConsts::FN_LOCAL_NAME_0);
  xquery_fns_def_dot.set(FunctionConsts::FN_NAME_0);
  xquery_fns_def_dot.set(FunctionConsts::FN_STRING_0);
  xquery_fns_def_dot.set(FunctionConsts::FN_GENERATE_ID_0);
  xquery_fns_def_dot.set(FunctionConsts::FN_DATA_0);
  xquery_fns_def_dot.set(FunctionConsts::FN_DOCUMENT_URI_0);
  xquery_fns_def_dot.set(FunctionConsts::FN_NODE_NAME_0);

  op_concatenate = GET_BUILTIN_FUNCTION(OP_CONCATENATE_N);
  assert(op_concatenate != NULL);

  op_enclosed = GET_BUILTIN_FUNCTION(OP_ENCLOSED_1);
  assert(op_enclosed != NULL);

  if (rootTranslator == NULL)
  {
    QueryLoc loc;
    theDotVarName = new QName(loc, static_context::DOT_VAR_NAME);
    theDotPosVarName = new QName(loc, static_context::DOT_POS_VAR_NAME);
    theLastIdxVarName = new QName(loc, static_context::DOT_SIZE_VAR_NAME);

    theRootTranslator = this;
  }
}

~TranslatorImpl() {
#ifndef ZORBA_NO_FULL_TEXT
  while ( !theFTNodeStack.empty() )
    delete ztd::pop_stack( theFTNodeStack );
#endif
}


const QName* getDotVarName() const
{
  return theRootTranslator->theDotVarName.getp();
}


const QName* getDotPosVarName() const
{
  return theRootTranslator->theDotPosVarName.getp();
}


const QName* getLastIdxVarName() const
{
  return theRootTranslator->theLastIdxVarName.getp();
}



/*******************************************************************************
  Pop the top n exprs from theNodeStack and return the last expr that was popped.
********************************************************************************/
expr_t pop_nodestack(int n = 1)
{
  ZORBA_ASSERT(n >= 0);

  expr_t e_h;

  for (; n > 0; --n)
  {
    ZORBA_FATAL(! theNodeStack.empty(), "");
    e_h = theNodeStack.top();
    theNodeStack.pop();

#ifndef NDEBUG
    if (Properties::instance()->traceTranslator())
    {
      std::cout << "Popped from nodestack:\n";
      if (e_h != NULL)
        e_h->put(std::cout) << std::endl;
      else
        std::cout << "NULL" << std::endl;
    }
#endif
  }
  return e_h;
}


/*******************************************************************************
  Push the given expr into theNodeStack.
********************************************************************************/
inline void push_nodestack(const expr_t& e)
{
  theNodeStack.push(e);

#ifndef NDEBUG
  if (Properties::instance()->traceTranslator())
  {
    std::cout << "Pushed to nodestack: \n";
    if (e.getp() != NULL)
      e->put(std::cout) << std::endl;
    else
      std::cout << "NULL" << std::endl;
  }
#endif
}


/*******************************************************************************
  Assert that the top expr in theNodeStack is a var_expr and pop it.
********************************************************************************/
var_expr_t pop_nodestack_var()
{
  expr_t e = pop_nodestack();
  assert (e == NULL || e->get_expr_kind() == var_expr_kind);
  return static_cast<var_expr *>(e.getp());
}


/*******************************************************************************
  Return rchandle to the expr at the top of theNodeStack, or NULL if theNodeStack
  is empty.
********************************************************************************/
expr_t peek_nodestk_or_null()
{
  return (theNodeStack.empty()) ? expr_t(NULL) : theNodeStack.top();
}


/*******************************************************************************
  Return rchandle to the expr at the top of theNodeStack (crash if theNodeStack
  is empty).
********************************************************************************/
expr_t top_nodestack()
{
  ZORBA_FATAL( !theNodeStack.empty(), "" );
  return theNodeStack.top();
}


/*******************************************************************************
  Check if the top expr in theNodeStack is an axis_step, and if so return
  rchandle to it (but do not pop). Otherwise, raise error.
********************************************************************************/
rchandle<axis_step_expr> expect_axis_step_top()
{
  rchandle<axis_step_expr> axisExpr = peek_nodestk_or_null().dyn_cast<axis_step_expr>();
  if (axisExpr == NULL)
  {
    std::cout << "Expecting axis step on top of stack; ";
    if (theNodeStack.top() != NULL)
      std::cout << "typeid(top()) = " << typeid(*theNodeStack.top()).name() << std::endl;
    else
      std::cout << "top is null\n";
    ZORBA_ASSERT (false);
  }
  return axisExpr;
}


/*******************************************************************************

********************************************************************************/
xqtref_t pop_tstack()
{
  return translator_ns::pop_stack(theTypeStack);
}


#ifndef ZORBA_NO_FULL_TEXT
/*****************************************************************************
  Pop the top count ftnodes from theFTNodeStack and return the last expr that
  was popped.
******************************************************************************/
ftnode* pop_ftstack(int count = 1)
{
  ZORBA_ASSERT(count >= 0);

  ftnode *n = NULL;
  while ( count-- > 0 )
  {
    ZORBA_FATAL( !theFTNodeStack.empty(), "" );
    n = theFTNodeStack.top();
    theFTNodeStack.pop();

#ifndef NDEBUG
    if ( Properties::instance()->traceTranslator() )
    {
      std::cout << "Popped from ftnode stack:\n";
      if ( n )
        std::cout << *n << std::endl;
      else
        std::cout << "NULL" << std::endl;
    }
#endif
  }
  return n;
}


/******************************************************************************
  Push the given expr into theFTNodeStack.
 ******************************************************************************/
inline void push_ftstack( ftnode *n )
{
  theFTNodeStack.push( n );
}


inline ftnode* top_ftstack()
{
  ZORBA_FATAL( !theFTNodeStack.empty(), "" );
  return theFTNodeStack.top();
}
#endif /* ZORBA_NO_FULL_TEXT */


/******************************************************************************

*******************************************************************************/
inline bool inLibraryModule()
{
  return export_sctx != NULL;
}


/******************************************************************************

*******************************************************************************/
inline bool inUDFBody()
{
  return !theCurrentPrologVFDecl.isNull();
}


/******************************************************************************

*******************************************************************************/
inline short sctxid()
{
  return theCurrSctxId;
}


/*******************************************************************************
  Create new static context, make it the current one for the current module, and
  register it into the query-level sctx map.
********************************************************************************/
void push_scope()
{
  // create a new static context for the new scope
  theSctx = theSctx->create_child_context();

#ifdef ZORBA_WITH_DEBUGGER
  if (theCCB->theDebuggerCommons != NULL)
  {
    // in debug mode, we remember all static contexts
    // this allows the debugger to introspect (during runtime)
    // all variables in scope
    theSctxIdStack.push(sctxid());
    theCurrSctxId = (short)theCCB->theSctxMap.size() + 1;
    (theCCB->theSctxMap)[sctxid()] = theSctx;
  }
  else
  {
#endif
    // in non-debug mode, we need to make sure that the scoped
    // contexts are kept around for the compilation of this module.
    // The static context available at runtime will be the root context
    // in which the module is compiled. Keeping all contexts around during
    // runtime seems to be overhead.
    theSctxList.push_back(theSctx);
#ifdef ZORBA_WITH_DEBUGGER
  }
#endif

  ++theScopeDepth;
}


/*******************************************************************************
  Make the parent of the current sctx be the current sctx for the current module.
********************************************************************************/
void pop_scope()
{
#ifdef ZORBA_WITH_DEBUGGER
  if (theCCB->theDebuggerCommons != NULL)
  {
    theCurrSctxId = theSctxIdStack.top();
    theSctx = (theCCB->theSctxMap)[sctxid()];
    theSctxIdStack.pop();
  }
  else
  {
#endif
    static_context* parent = (static_context *) theSctx->get_parent();
    theSctx = parent;
    theSctxList.pop_back();
#ifdef ZORBA_WITH_DEBUGGER
  }
#endif

  --theScopeDepth;
}


/*******************************************************************************

********************************************************************************/
void push_elem_scope()
{
  theNSCtx = new namespace_context(&*theNSCtx);
}


/*******************************************************************************

********************************************************************************/
void pop_elem_scope()
{
  theNSCtx = theNSCtx->get_parent();
}


/*******************************************************************************
  Convert a lexical qname identifying a function to an expanded qname item.
  If the lexical qname does not have a prefix, the default function namespace
  (if any) will be used to build the expanded qname item.
********************************************************************************/
void expand_function_qname(
    store::Item_t& qnameItem,
    const QName* qname,
    const QueryLoc& loc) const
{
  theSctx->expand_qname(qnameItem,
                        (qname->is_eqname() ?
                         qname->get_namespace() :
                         theSctx->default_function_ns()),
                        qname->get_prefix(),
                        qname->get_localname(),
                        loc);
}


/*******************************************************************************
  Convert a lexical qname representing an element tag name or a type name to an
  expanded qname item. If the lexical qname does not have a prefix, the default
  element namespace (if any) will be used to build the expanded qname item.
********************************************************************************/
void expand_elem_qname(
    store::Item_t& qnameItem,
    const QName* qname,
    const QueryLoc& loc) const
{
  theSctx->expand_qname(qnameItem,
                        (qname->is_eqname() ?
                         qname->get_namespace() :
                         theSctx->default_elem_type_ns()),
                        qname->get_prefix(),
                        qname->get_localname(),
                        loc);
}


/*******************************************************************************

********************************************************************************/
void expand_no_default_qname(
    store::Item_t& qnameItem,
    const QName* qname,
    const QueryLoc& loc) const
{
  theSctx->expand_qname(qnameItem,
                        qname->get_namespace(),
                        qname->get_prefix(),
                        qname->get_localname(),
                        loc);
}


/*******************************************************************************
  Create a var_expr for a variable with a given qname item, kind, and type
********************************************************************************/
var_expr_t create_var(
    const QueryLoc& loc,
    store::Item* qname,
    var_expr::var_kind kind,
    xqtref_t type = NULL)
{
  var_expr_t e = new var_expr(theRootSctx, loc, kind, qname);

  if (kind == var_expr::pos_var ||
      kind == var_expr::count_var ||
      kind == var_expr::wincond_out_pos_var ||
      kind == var_expr::wincond_in_pos_var)
  {
    type = GENV_TYPESYSTEM.POSITIVE_INTEGER_TYPE_ONE;
  }

  e->set_type(type);
  return e;
}


/*******************************************************************************
  Create a var_expr for a variable with a given qname, kind, and type. The
  given qname is expanded to a qname item. An error is raised if the qname
  expansion fails (because there is no namespace binding for the given prefix).
********************************************************************************/
var_expr_t create_var(
    const QueryLoc& loc,
    const QName* qname,
    var_expr::var_kind kind,
    xqtref_t type = NULL)
{
  store::Item_t qnameItem;
  expand_no_default_qname(qnameItem, qname, loc);
  return create_var(loc, qnameItem, kind, type);
}


/*******************************************************************************
  Create a var_expr for an internal variable with a given kind. The name to be
  used for the internally generated variable is unique within this translator.
********************************************************************************/
var_expr_t create_temp_var(const QueryLoc& loc, var_expr::var_kind kind)
{
  std::string localName = "$$temp" + ztd::to_string(theTempVarCounter++);

  store::Item_t qnameItem;
  GENV_ITEMFACTORY->createQName(qnameItem, "", "", localName.c_str());

  return create_var(loc, qnameItem, kind);
}


/*******************************************************************************
  Create a binding in the given sctx between a var qname item and a var_expr.
  Raise error if a var with the same expanded qname is already in the given
  sctx obj.
********************************************************************************/
void bind_var(var_expr_t e, static_context* sctx)
{
  assert(sctx != NULL);

  if(e->get_kind() == var_expr::let_var)
  {
    sctx->bind_var(e, e->get_loc(), err::XQST0039);
  }
  else
  {
    sctx->bind_var(e, e->get_loc(), err::XQST0049);
  }
}


/*******************************************************************************
  Create a var_expr for a variable with a given qname item, kind, and type.
  Then, create a binding in the given sctx between the var qname item and the
  var_expr. Raise error if a var with the same expanded qname item is already
  in the given sctx obj.
********************************************************************************/
var_expr_t bind_var(
    const QueryLoc& loc,
    store::Item* qname,
    var_expr::var_kind kind,
    xqtref_t type = NULL)
{
  var_expr_t e = create_var(loc, qname, kind, type);
  bind_var(e, theSctx);
  return e;
}


/*******************************************************************************
  Create a var_expr for a variable with a given qname, kind, and type. Then,
  create a binding in the given sctx between the var qname item and the var_expr.
  Raise error if a var with the same expanded qname item is already in the
  given sctx obj or if the expansion of the given qname to a qname item fails.
********************************************************************************/
var_expr_t bind_var(
    const QueryLoc& loc,
    const QName* qname,
    var_expr::var_kind kind,
    xqtref_t type = NULL)
{
  var_expr_t e = create_var(loc, qname, kind, type);
  bind_var(e, theSctx);
  return e;
}


/*******************************************************************************
  Lookup a context variable, i.e., the var (if any) representing the context
  item, or the context position, or the context size. The variable is identified
  by its lexical qname (DOT_VARNAME, or DOT_POS_VARNAME, or LAST_IDX_VARNAME).

  Search starts from the "current" sctx and moves upwards the ancestor path
  until the first instance (if any) of the variable is found.

  If var is not found, the method raises appropriate error.
********************************************************************************/
var_expr_t lookup_ctx_var(const QName* qname, const QueryLoc& loc)
{
  if (theIsInIndexDomain)
  {
    try
    {
      return lookup_var(qname, loc, err::XPDY0002);
    }
    catch (ZorbaException const& e)
    {
      if (e.diagnostic() == err::XPDY0002)
      {
        RAISE_ERROR(zerr::ZDST0032_INDEX_REFERENCES_CTX_ITEM, loc,
        ERROR_PARAMS(theIndexDecl->getName()->getStringValue()));
      }
      throw;
    }
  }
  else
  {
    return lookup_var(qname, loc, err::XPDY0002);
  }
}


/*******************************************************************************
  Lookup variable by lexical qname. Search starts from the "current" ctx and
  moves upwards the ancestor path until the first instance (if any) of the var
  is found.

  If the lexical qname has a prefix for which no namespace binding exists, the
  method raises error.

  If var is not found, the method raises the given error, unless the given error
  is MAX_ZORBA_ERROR_CODE, in which case it returns NULL.
********************************************************************************/
var_expr* lookup_var(
    const QName* qname,
    const QueryLoc& loc,
    const Error& err)
{
  store::Item_t qnameItem;
  expand_no_default_qname(qnameItem, qname, loc);

  return theSctx->lookup_var(qnameItem.getp(), loc, err);
}


/*******************************************************************************
  Lookup variable by expanded qname. Search starts from the "current" sctx and
  moves upwards the ancestor path until the first instance (if any) of the var
  is found.

  If var is not found, the method raises the given error, unless the given error
  is MAX_ZORBA_ERROR_CODE, in which case it returns NULL.
********************************************************************************/
var_expr* lookup_var(
    const store::Item* qname,
    const QueryLoc& loc,
    const Error& err)
{
  return theSctx->lookup_var(qname, loc, err);
}



/*******************************************************************************
  Create a binding between the given (function qname item, arity) pair and the
  given function object. The binding is created in (a) the current sctx of this
  module, (b) the query-level sctx that gathers all declaration of functions and
  variables from all modules, and (c) the export_sctx (if any). Raise error if
  such a binding exists already in any of these sctxs.
********************************************************************************/
void bind_fn(
    function_t& f,
    ulong nargs,
    const QueryLoc& loc)
{
  theSctx->bind_fn(f, nargs, loc);

  theModulesInfo->globalSctx->bind_fn(f, nargs, loc);

  if (export_sctx != NULL)
  {
    export_sctx->bind_fn(f, nargs, loc);
  }
}


/*******************************************************************************
  Lookup in the sctx the function object for a function with a given prefix
  local name and arity. Return NULL if such a function is not found
********************************************************************************/
function* lookup_fn(const QName* qname, ulong arity, const QueryLoc& loc)
{
  store::Item_t qnameItem;
  expand_function_qname(qnameItem, qname, loc);

  return theSctx->lookup_fn(qnameItem, arity);
}


/*******************************************************************************
  Create an fn:concatenate() expr
********************************************************************************/
fo_expr* create_empty_seq(const QueryLoc& loc)
{
  return fo_expr::create_seq(theRootSctx, loc);
}


/*******************************************************************************

********************************************************************************/
void normalize_fo(fo_expr* foExpr)
{
  const QueryLoc& loc = foExpr->get_loc();

  TypeManager* tm = foExpr->get_type_manager();

  const signature& sign = foExpr->get_signature();

  ulong n = foExpr->num_args();

  const function* func = foExpr->get_func();

  if (func->getKind() == FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_RANGE_VALUE_N &&
      (n < 7 || (n - 1) % 6 != 0))
  {
    const store::Item* qname = NULL;

    if (n > 0)
      qname = foExpr->get_arg(0)->getQName(theSctx);

    if (qname != NULL)
    {
      RAISE_ERROR(zerr::ZDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS, loc,
      ERROR_PARAMS(
        qname->getStringValue(),
        "index",
        n-1,
        "multiple of 6"
      )
      );
    }
    else
    {
      RAISE_ERROR(
          zerr::ZDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS, loc,
          ERROR_PARAMS(
            "anonymous",
            "index",
            n-1,
            "multiple of 6"
          )
      );
    }
  }

  for (ulong i = 0; i < n; ++i)
  {
    expr::expr_t argExpr = foExpr->get_arg(i);

    xqtref_t paramType;

    if (func->getKind() == FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_POINT_VALUE_N)
    {
      if (i == 0)
        paramType = sign[i];
      else
        paramType = theRTM.ANY_ATOMIC_TYPE_QUESTION;
    }
    else if (func->getKind() == FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_RANGE_VALUE_N)
    {
      if (i == 0)
        paramType = sign[i];
      else if (i % 6 == 1 || i % 6 == 2)
        paramType = theRTM.ANY_ATOMIC_TYPE_QUESTION;
      else
        paramType = theRTM.BOOLEAN_TYPE_ONE;
    }
    else if (func->getKind() == FunctionConsts::FN_ZORBA_INVOKE_N ||
             func->getKind() == FunctionConsts::FN_ZORBA_INVOKE_N_N ||
             func->getKind() == FunctionConsts::FN_ZORBA_INVOKE_U_N ||
             func->getKind() == FunctionConsts::FN_ZORBA_INVOKE_S_N)
    {
      if (i == 0)
        paramType = sign[i];
      else
        paramType = NULL; // Nothing to check as the target function is not known
    }
    else
    {
      paramType = sign[i];
    }

    // A NULL value for the parameter's type to signal that no type promotion
    // or match should be added. This is used by the reflection:invoke() function,
    if (paramType != NULL)
    {
      if (TypeOps::is_subtype(tm,
                              *paramType,
                              *theRTM.ANY_ATOMIC_TYPE_STAR,
                              loc))
      {
        argExpr = wrap_in_atomization(argExpr);
        argExpr = wrap_in_type_promotion(argExpr, paramType);
      }
      else
      {
        argExpr = wrap_in_type_match(argExpr, paramType, loc);
      }
    }

    foExpr->set_arg(i, argExpr);
  }
}


/*******************************************************************************
  Wrap the given expr in an fn:data() function
********************************************************************************/
expr_t wrap_in_atomization(expr* e)
{
  return new fo_expr(theRootSctx,
                     e->get_loc(),
                     GET_BUILTIN_FUNCTION(FN_DATA_1),
                     e);
}


/*******************************************************************************

********************************************************************************/
expr_t wrap_in_type_promotion(expr_t e, xqtref_t type, store::Item_t fnQName = NULL)
{
  return new promote_expr(theRootSctx, e->get_loc(), e, type, fnQName);
}


/*******************************************************************************

********************************************************************************/
expr_t wrap_in_type_match(
    expr_t e,
    xqtref_t type,
    const QueryLoc& loc,
    const Error& errorCode = err::XPTY0004,
    store::Item_t fnQName = NULL)
{
  TypeManager* tm = e->get_type_manager();

  // treat_expr should be avoided for updating expressions too,
  // but in that case "type" will be item()* anyway
  return (TypeOps::is_subtype(tm, *theRTM.ITEM_TYPE_STAR, *type, loc) ?
          e :
          new treat_expr(theRootSctx, e->get_loc(), e, type, errorCode, true, fnQName));
}



/*******************************************************************************

********************************************************************************/
expr_t wrap_in_bev(expr_t e)
{
  fo_expr* fo = new fo_expr(theRootSctx,
                            e->get_loc(),
                            GET_BUILTIN_FUNCTION(FN_BOOLEAN_1),
                            e);
  return fo;
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
  FunctionConsts::FunctionKind fkind;

  if (reverse && atomics)
  {
    fkind = FunctionConsts::OP_SORT_DISTINCT_NODES_DESC_OR_ATOMICS_1;
  }
  else if (reverse)
  {
    fkind = FunctionConsts::OP_SORT_DISTINCT_NODES_DESC_1;
  }
  else if (atomics)
  {
    fkind = FunctionConsts::OP_SORT_DISTINCT_NODES_ASC_OR_ATOMICS_1;
  }
  else
  {
    fkind = FunctionConsts::OP_SORT_DISTINCT_NODES_ASC_1;
  }

  rchandle<fo_expr> dos = new fo_expr(theRootSctx,
                                      expr->get_loc(),
                                      BuiltinFunctionLibrary::getFunction(fkind),
                                      expr);
  normalize_fo(dos.getp());

  return &*dos;
}


/*******************************************************************************
  Create a LET clause for the given LET variable "lv", with the given expr "e" as
  its defining expression.
********************************************************************************/
let_clause_t wrap_in_letclause(expr_t e, var_expr_t lv)
{
  assert (lv->get_kind () == var_expr::let_var);

  return new let_clause(theRootSctx, e->get_loc(), lv, e.getp());
}


/*******************************************************************************
  Create a var_expr for a LET var with the given qname and add that var to the
  local sctx obj. Then, create a LET clause for this new var_expr, with the given
  expr "e" as its defining expression.
********************************************************************************/
let_clause_t wrap_in_letclause(
    expr_t e,
    const QueryLoc& loc,
    const QName* qname)
{
  return wrap_in_letclause(e, bind_var(loc, qname, var_expr::let_var));
}


/*******************************************************************************
  Create a var_expr for a new internal LET var and then create a LET clause for
  this new var_expr, with the given expr "e" as its defining expression. NOTE:
  the internal var is not registered in the sctx.
********************************************************************************/
let_clause_t wrap_in_letclause(expr_t e)
{
  return wrap_in_letclause(e, create_temp_var(e->get_loc(), var_expr::let_var));
}


/*******************************************************************************
  Create a FOR clause for the given FOR variable "fv" and its associated POS var
  "pv" (pv may be NULL). Use the given expr "e" as the defining expr for "fv".
********************************************************************************/
for_clause_t wrap_in_forclause(expr_t e, var_expr_t fv, var_expr_t pv)
{
  assert(fv->get_kind () == var_expr::for_var);
  if (pv != NULL)
  {
    assert(pv->get_kind() == var_expr::pos_var);
  }

  return new for_clause(theRootSctx, e->get_loc(), fv, e, pv);
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
    const QName* fv_qname,
    const QName* pv_qname)
{
  return wrap_in_forclause(expr,
                           bind_var(loc, fv_qname, var_expr::for_var),
                           bind_var(loc, pv_qname, var_expr::pos_var));
}


/*******************************************************************************
  Create a var_expr for a new internal FOR var and then create a FOR clause for
  this new var_expr, with the given expr as its defining expression. NOTE:
  the internal var is not registered in the sctx.
********************************************************************************/
for_clause_t wrap_in_forclause(expr_t expr, bool add_posvar)
{
  var_expr_t fv = create_temp_var(expr->get_loc(), var_expr::for_var);

  var_expr_t pv = (add_posvar ?
                   create_temp_var(expr->get_loc(), var_expr::pos_var) :
                   var_expr_t(NULL));

  return wrap_in_forclause(expr, fv, pv);
}


/*******************************************************************************
  Create a flwor expr with a single let clause and a return expr. In particular,
  the following flwor expr is built:

  let $lv := domExpr
  return retExpr

********************************************************************************/
rchandle<flwor_expr> wrap_in_let_flwor(
    expr_t domExpr,
    var_expr_t lv,
    expr_t retExpr)
{
  rchandle<flwor_expr> fe = new flwor_expr(theRootSctx, lv->get_loc(), false);

  fe->add_clause(wrap_in_letclause(domExpr, lv));

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
rchandle<flwor_expr> wrap_expr_in_flwor(
    expr* inputExpr,
    bool withContextSize)
{
  const QueryLoc& loc = inputExpr->get_loc();

  push_scope();

  rchandle<flwor_expr> flworExpr = new flwor_expr(theRootSctx, loc, false);

  if (withContextSize)
  {
    // create a LET var equal to the seq returned by the input epxr
    let_clause_t lcInputSeq = wrap_in_letclause(inputExpr);

    // compute the size of the input seq
    rchandle<fo_expr> countExpr = new fo_expr(theRootSctx,
                                              loc,
                                              GET_BUILTIN_FUNCTION(FN_COUNT_1),
                                              lcInputSeq->get_var());
    normalize_fo(countExpr);

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

QueryLoc
expandQueryLoc(const QueryLoc aLocationFrom, const QueryLoc& aLocationTo)
{
  QueryLoc lExpandedLocation(aLocationFrom);
  lExpandedLocation.setColumnEnd(aLocationTo.getColumnEnd());
  lExpandedLocation.setLineEnd(aLocationTo.getLineEnd());
  return lExpandedLocation;
}

/*******************************************************************************
  In this expression branch, we create the debugger expressions.
  Furthermore, we create an entry for all expressions in the map
  of breakable expressions. This is done here, in order to be able,
  to set breakpoints of expressions which are not translated at the
  beginning (e.g. inside functions).
********************************************************************************/
void wrap_in_debugger_expr(
  expr_t& aExpr,
  const QueryLoc& aLoc,
  bool aAddBreakable = true,
  bool aIsVarDeclaration = false)
{
#ifdef ZORBA_WITH_DEBUGGER
  if (theCCB->theDebuggerCommons != NULL)
  {
    std::auto_ptr<debugger_expr> lExpr(new debugger_expr(theSctx,
                                                         aLoc,
                                                         aExpr,
                                                         thePrologVars,
                                                         theNSCtx,
                                                         aIsVarDeclaration));

    // add the breakable expression in the debugger commons as a possible
    // breakpoint location
    Breakable lBreakable(aLoc);
    if (aAddBreakable) {
      theCCB->theDebuggerCommons->addBreakable(lBreakable);
    }

    // retrieve all variables that are in the current scope
    typedef std::vector<var_expr_t> VarExprVector;
    VarExprVector lAllInScopeVars;
    theSctx->getVariables(lAllInScopeVars);

    // for each var, create a eval_var and add it to
    // the debugger expression
    for (VarExprVector::iterator lIter = lAllInScopeVars.begin();
         lIter != lAllInScopeVars.end();
         ++lIter)
    {
      store::Item* lVarname = (*lIter)->get_name();
      if (lVarname->getStringValue() == "$$dot")
      {
        continue;
      }

      var_expr_t ve = create_var(lBreakable.getLocation(),
                                 lVarname,
                                 var_expr::eval_var,
                                 NULL).dyn_cast<var_expr>();

      var_expr* lVe = lookup_var(ve->get_name(), QueryLoc::null, err::XPST0008);

      expr_t val = new wrapper_expr(theRootSctx,
                                    lBreakable.getLocation(),
                                    rchandle<expr>(lVe));
      lExpr->add_var(ve, val);
    }

    aExpr = lExpr.release();
  }
#endif
}


/*******************************************************************************
  Collect the var_exprs for all variables that (a) are defined by some clause
  in a given range of clauses, and (b) are in-scope when this method is called.
********************************************************************************/
void collect_flwor_vars (
    const FLWORExpr& e,
    std::set<const var_expr *>& vars,
    const FLWORClause* start,
    const FLWORClause* end,
    const QueryLoc& loc)
{
  const FLWORClauseList& clauses = *e.get_clause_list();

  // Find the ordinal number of the "end-1" clause.
  int i;
  for (i = (int)clauses.size () - 1; i >= 0; --i)
  {
    if (&*clauses [i] == end)
    {
      --i;
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
      const VarInDeclList& lV = *(static_cast<const ForClause*>(&c)->get_vardecl_list());
      for (int j =  (int)lV.size() - 1; j >= 0; --j)
      {
        vars.insert(lookup_var(lV[j]->get_name(), loc, err::XPST0008));
      }
    }
    else if (typeid (c) == typeid (LetClause))
    {
      const VarGetsDeclList& lV = *(static_cast<const LetClause*>(&c)->get_vardecl_list());
      for (int j =  (int)lV.size() - 1; j >= 0; --j)
      {
        vars.insert(lookup_var(lV[j]->get_name(), loc, err::XPST0008));
      }
    }
    else if (typeid(c) == typeid(WindowClause))
    {
      const WindowClause& wc = *static_cast<const WindowClause *>(&c);
      vars.insert(lookup_var(wc.get_var()->get_name(), loc, err::XPST0008));
      for (int j = 1; j >= 0; j--)
      {
        const FLWORWinCond* cond = &*wc[j];
        if (cond != NULL)
        {
          const WindowVars* wv = &*cond->get_winvars();
          if (wv != NULL)
          {
            if (wv->get_next())
              vars.insert(lookup_var(wv->get_next(), loc, err::XPST0008));
            if (wv->get_prev())
              vars.insert(lookup_var(wv->get_prev(), loc, err::XPST0008));
            if (wv->get_curr())
              vars.insert(lookup_var(wv->get_curr(), loc, err::XPST0008));
            if (wv->get_posvar() != NULL)
              vars.insert(lookup_var(wv->get_posvar()->get_name(), loc, err::XPST0008));
          }
        }
      }
    }
    else if (typeid(c) == typeid(CountClause))
    {
      vars.insert(lookup_var(static_cast<const CountClause*>(&c)->get_varname(),
                             loc,
                             err::XPST0008));
    }
    else if (typeid(c) == typeid(OrderByClause))
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
      collect_flwor_vars(e, vars, &*clauses [0], &c, loc);
      break;
    }

    if (&c == start)
      break;
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

  1. var_decl_expr(varExpr, initExpr)

  2. var_decl_expr(varExpr, initExpr)

     In this case, the var_decl_expr will be a NOOP if a value has been assigned
     to the external var via the c++ api. If so, this value overrides the
     initializing expr in the prolog.

  3. var_decl_expr(varExpr)

  4. var_decl_expr(varExpr)

     In this case, the variable must be initialized via the c++ api before the
     query is executed, and it is this external intialization that will declare
     the var, ie, add an entry for the var in the dynamic ctx. Nevertheless, we
     need to generate the var_decl_expr because it is when this expr is
     encounered during codegen that an id will be assigned to the var (and
     stored in the var_expr). This id is needed in order to register the var
     in the dyn ctx.

  If the var declaration includes a type declaration, then the following expr
  is also created and added to stmts:

  treat(ctxvar-get(varName), type)

********************************************************************************/
void declare_var(const GlobalBinding& b, std::vector<expr_t>& stmts)
{
  function* varGet = GET_BUILTIN_FUNCTION(OP_VAR_GET_1);

  expr_t initExpr = b.second;
  var_expr_t varExpr = b.first;

  const QueryLoc& loc = varExpr->get_loc();

  xqtref_t varType = varExpr->get_type();

  if (varType == NULL &&
      varExpr->get_name()->getLocalName() == static_context::DOT_VAR_NAME)
  {
    varType = GENV_TYPESYSTEM.ITEM_TYPE_ONE;
  }

  expr_t declExpr = new var_decl_expr(theRootSctx, loc, varExpr, initExpr);

  stmts.push_back(declExpr);

  // check type for vars that are external or have an init expr
  if (varType != NULL && (b.is_extern() || b.second != NULL))
  {
    expr_t getExpr = new fo_expr(theRootSctx, loc, varGet, varExpr);

    stmts.push_back(new treat_expr(theRootSctx, loc, getExpr, varType, err::XPTY0004));
  }
}


/*******************************************************************************
  Create declaration/initialization exprs for each prolog variable of this
  module and put these exprs in theModulesInfo->theInitExprs. Then create a
  sequential expr with its children being all the init exprs in
  theModulesInfo->theInitExprs plus the given expr "e" as its last child.

  The method is called at the end of the translation of each module. The returned
  expr is the result of the module translation. For the root module, the given
  "program" expr is the result of translating the MainModule Program. For non-root
  modules, "program" is an empty fn:concatenate() expr.
********************************************************************************/
expr_t wrap_in_globalvar_assign(const expr_t& program)
{
  assert(theAssignedVars.size() == 1);

  for (std::list<GlobalBinding>::iterator i = thePrologVars.begin();
      i != thePrologVars.end();
      ++i)
  {
    declare_var(*i, theModulesInfo->theInitExprs);
  }

  expr_t preloadedInitExpr = static_cast<static_context*>(theSctx->get_parent())->
                             get_query_expr();

  if (!theModulesInfo->theInitExprs.empty() || preloadedInitExpr != NULL)
  {
    std::vector<expr_t> args;
    args.reserve(2 + theModulesInfo->theInitExprs.size());

    if (preloadedInitExpr)
      args.push_back(preloadedInitExpr);

    args.insert(args.end(),
                theModulesInfo->theInitExprs.begin(),
                theModulesInfo->theInitExprs.end());

    if (!inLibraryModule())
    {
      args.push_back(program);
    }

    block_expr* res = new block_expr(theRootSctx,
                                     program->get_loc(),
                                     theCCB->theIsEval,
                                     args,
                                     &theAssignedVars[0]);

    assert(theAssignedVars[0].empty());

    return res;
  }
  else
  {
    return program;
  }
}


/*******************************************************************************
  Imports a given schema
********************************************************************************/
void* import_schema(
    const QueryLoc& loc,
    const SchemaPrefix* prefix,
    const zstring& targetNS,
    const URILiteralList* atlist)
{
#ifndef ZORBA_NO_XMLSCHEMA

  if (! theImportedSchemas.insert(targetNS.str()).second)
    throw XQUERY_EXCEPTION(err::XQST0058, ERROR_LOC(loc));

  if (prefix != NULL)
  {
    if (!prefix->get_default_bit() && targetNS.empty())
    {
      throw XQUERY_EXCEPTION( err::XQST0057, ERROR_LOC(loc));
    }

    zstring pfx = prefix->get_prefix();

    if (pfx == "xml" || pfx == "xmlns")
      RAISE_ERROR(err::XQST0070, loc, ERROR_PARAMS(pfx, ZED(NoRebindPrefix)));

    if (prefix->get_default_bit())
      theSctx->set_default_elem_type_ns(targetNS, loc);

    if (! pfx.empty())
      theSctx->bind_ns(pfx, targetNS, loc, err::XQST0033);
  }

  store::Item_t targetNSItem = NULL;
  zstring tmp = targetNS;
  ITEM_FACTORY->createAnyURI(targetNSItem, tmp);
  ZORBA_ASSERT(targetNSItem != NULL);

  // Form up a vector of candidate URIs: any location hints, followed
  // by the imported URI itself.
  std::vector<zstring> lCandidates;

  if (atlist != NULL)
  {
    for (ulong i = 0; i < atlist->size(); ++i)
    {
      // If current uri is relative, turn it to an absolute one, using the
      // base uri from the sctx.
      lCandidates.push_back(theSctx->resolve_relative_uri((*atlist)[i]));
    }
  }

  zstring lNsURI = targetNSItem->getStringValue();
  lCandidates.push_back(lNsURI);

  try
  {
    std::auto_ptr<internal::Resource> lSchema;
    internal::StreamResource* lStream = NULL;
    zstring lErrorMessage;
    for (std::vector<zstring>::iterator lIter = lCandidates.begin();
         lIter != lCandidates.end();
         ++lIter)
    {
      lSchema = theSctx->resolve_uri(*lIter, internal::EntityData::SCHEMA,
                                     lErrorMessage);
      lStream = dynamic_cast<internal::StreamResource*>(lSchema.get());
      if (lStream != NULL)
      {
        break;
      }
    }

    if ( lStream == NULL ) {
      throw XQUERY_EXCEPTION(err::XQST0059, ERROR_PARAMS(lNsURI, lErrorMessage));
    }

    // If we got this far, we have a valid StreamResource.

    // Create a Schema obj and register it in the typemanger, if the typemanager
    // does not have a schema obj already
    TypeManager* tm = theSctx->get_typemanager();
    tm->initializeSchema();
    Schema* schema_p = tm->getSchema();

    // Make Xerxes load and parse the xsd file and create a Xerces
    // representaton of it.
    schema_p->registerXSD(lNsURI.c_str(), theSctx, lStream, loc);

  }
  catch (XQueryException& e)
  {
    set_source(e, loc);
    throw;
  }

  return no_state;

#else
  throw XQUERY_EXCEPTION(err::XQST0009, ERROR_LOC(loc));
#endif
}


/*******************************************************************************
  Imports a given schema allocating it as prefix the last step in the URI path
  suffixed with "_"'s if such a prefix is already bound.
********************************************************************************/
void*
import_schema_auto_prefix(
  const QueryLoc& aLoc,
  const zstring& aTargetNs,
  const URILiteralList* atlist)
{
#ifndef ZORBA_NO_XMLSCHEMA

  if (theImportedSchemas.find(aTargetNs.str()) == theImportedSchemas.end())
  {
    // take as prefix the last segment of the URI
    std::size_t lLastSlash = aTargetNs.find_last_of("/");
    zstring lPrefixStr;
    if (lLastSlash + 1 < aTargetNs.size())
    {
      lPrefixStr = aTargetNs.substr(lLastSlash + 1);
    }
    // do not allow a "default" namespace binding
    if (lPrefixStr == "")
    {
      lPrefixStr = "_";
    }

    // search for name clashes with already existing prefixes
    store::NsBindings lNsBindings;
    theSctx->get_namespace_bindings(lNsBindings);
    store::NsBindings::iterator lIter = lNsBindings.begin();
    store::NsBindings::iterator lEnd = lNsBindings.end();
    for (; lIter != lEnd; lIter++)
    {
      // TODO: can be done more efficient by not starting from the beginning,
      // but since the chances are small that more than 1 restart is needed,
      // it probably compensates to the performance degradation by allocating
      // another vector
      if (lIter->first == lPrefixStr) {
        lPrefixStr += "_";
        lIter = lNsBindings.begin();
      }
    }

    // now import the schema
    SchemaPrefix lPrefix(aLoc, lPrefixStr);
    import_schema(aLoc, &lPrefix, aTargetNs, atlist);
  }

  return no_state;

#else
  throw XQUERY_EXCEPTION(err::XQST0009, ERROR_LOC(aLoc));
#endif
}

/******************************************************************************
  Wraps an expression in a validate expression. If the schema URI is a
  non-empty string, the corresponding schema is imported. If the location is
  QueryLoc::null, the wrapped expression's location will be used.
*******************************************************************************/
expr_t
wrap_in_validate_expr_strict(
  expr* aExpr,
  std::string aSchemaURI)
{
  QueryLoc lLoc = aExpr->get_loc();
  import_schema_auto_prefix(lLoc, zstring(aSchemaURI.c_str()), NULL);

  store::Item_t qname;
  return new validate_expr(
    theRootSctx, lLoc, ParseConstants::val_strict,
    qname, aExpr, theSctx->get_typemanager());
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Module, VersionDecl, MainModule, LibraryModule, ModuleDecl                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Module ::= 	VersionDecl? (LibraryModule | MainModule)
********************************************************************************/

/******************************************************************************
  VersionDecl ::= XQUERY ENCODING STRING_LITERAL SEMI |
                  XQUERY VERSION STRING_LITERAL SEMI |
                  XQUERY VERSION STRING_LITERAL ENCODING STRING_LITERAL SEMI
********************************************************************************/
void* begin_visit(const VersionDecl& v)
{
  TRACE_VISIT();

  if (v.get_encoding().length() != 0 &&
      !utf8::match_whole(v.get_encoding(), "^[A-Za-z]([A-Za-z0-9._]|[-])*$"))
    RAISE_ERROR(err::XQST0087, loc, ERROR_PARAMS(v.get_encoding()));

  std::string versionStr = v.get_version().str();

  StaticContextConsts::xquery_version_t version;

  if (versionStr == "1.0")
  {
    version = StaticContextConsts::xquery_version_1_0;
  }

  else if (versionStr == "1.1" || versionStr == "3.0") //1.1 is the same as 3.0
  {
    version = StaticContextConsts::xquery_version_3_0;
  }
  else
  {
    version = StaticContextConsts::xquery_version_unknown;
  }

  if (theMaxLibModuleVersion != StaticContextConsts::xquery_version_unknown
      &&
      version > theMaxLibModuleVersion)
  {
    zstring maxversion;
    if (theMaxLibModuleVersion == StaticContextConsts::xquery_version_3_0)
      maxversion = "3.0";
    else
      maxversion = "1.0";

    // TODO: the error code might need to be changed after W3C solves
    // the bug report concerning modules of version 1.0 importing v3.0 libraries.
    RAISE_ERROR(err::XQST0031, loc,
    ERROR_PARAMS(versionStr, ZED(LibModVersionMismatch_3 ), maxversion));
  }

  if (version == StaticContextConsts::xquery_version_unknown)
  {
    RAISE_ERROR(err::XQST0031, loc,
    ERROR_PARAMS(versionStr, ZED(BadXQueryVersion)));
  }

  theSctx->set_xquery_version(version);

  return no_state;
}

void end_visit(const VersionDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  MainModule ::= Prolog Program
********************************************************************************/
void* begin_visit(const MainModule& v)
{
  TRACE_VISIT();

  theAssignedVars.resize(theAssignedVars.size() + 1);

  // Make sure that the context item is always in-scope inside the main module.
  // However, do not create a ver_decl expr for it, because this will create a
  // treat_as expr as well, so the ctx item will always appear as being used,
  // and as a result it will always have to be set.
  var_expr_t var = bind_var(loc,
                            DOT_VARNAME,
                            var_expr::prolog_var,
                            GENV_TYPESYSTEM.ITEM_TYPE_ONE);
  //var->set_external(true);
  var->set_unique_id(1);

  //GlobalBinding b(var, NULL, true);
  //declare_var(b, theModulesInfo->theInitExprs);

  return no_state;
}

void end_visit(const MainModule& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t program = pop_nodestack();

  assert(theCCB->theIsEval || !program->is_updating());

  // the main module debug iterator has no location otherwise
  // this would take precedence over a child debug iterator
  // starting in the same line
  wrap_in_debugger_expr(program, program->get_loc(), false);

  program = wrap_in_globalvar_assign(program);

  push_nodestack(program);

  theAssignedVars.pop_back();

  if (theModulesInfo->theCCB->isLoadPrologQuery())
    theSctx->set_query_expr(program);
}


/*******************************************************************************
  LibraryModule ::= ModuleDecl  Prolog
********************************************************************************/
void* begin_visit(const LibraryModule& v)
{
  TRACE_VISIT();

  theAssignedVars.resize(theAssignedVars.size() + 1);

  return no_state;
}

void end_visit(const LibraryModule& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t program = wrap_in_globalvar_assign(create_empty_seq(loc));

  theAssignedVars.pop_back();

  // Note: There is no real reason to put the expr returned by
  // wrap_in_globalvar_assign() in theNodeStack. The only reason is for the
  // translate_aux() function to be able to pick that expr from the stack in
  // order to print it.
  push_nodestack(program);
}


/******************************************************************************
  ModuleDecl ::= MODULE NAMESPACE  NCNAME  EQ  URI_LITERAL  SEMI
********************************************************************************/
void* begin_visit(const ModuleDecl& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const ModuleDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  theModulePrefix = v.get_prefix();
  theModuleNamespace = v.get_target_namespace();

  if (theModuleNamespace.empty())
    throw XQUERY_EXCEPTION(err::XQST0088, ERROR_LOC(loc));

  if (static_context::is_reserved_module(theModuleNamespace))
  {
    throw XQUERY_EXCEPTION(
      zerr::ZXQP0016_RESERVED_MODULE_TARGET_NAMESPACE,
      ERROR_PARAMS( theModuleNamespace ),
      ERROR_LOC( loc )
    );
  }

  if (theModulePrefix == "xml" || theModulePrefix == "xmlns")
    throw XQUERY_EXCEPTION(
      err::XQST0070,
      ERROR_PARAMS( theModulePrefix, ZED( NoRebindPrefix ) ),
      ERROR_LOC( loc )
    );

  theSctx->bind_ns(theModulePrefix, theModuleNamespace, loc);

  zstring uri;
  bool found = theSctx->get_entity_retrieval_uri(uri);
  ZORBA_ASSERT(found);
  // Note: in future, this will be problematic. When we consider supporting
  // importing multiple incompatible versions of modules, mod_sctx_map is
  // going to become a more complex multi-keyed structure, where the keys will
  // be the namespace URI and the version of the module being imported. However,
  // the version is defined by a "declare option", which will not have been
  // parsed yet. So at this point, we do not have the full key to look up the
  // appropriate static_context.
  static_context_t lTmpCtx;
  found = theModulesInfo->mod_sctx_map.get(uri, lTmpCtx);
  ZORBA_ASSERT(found);

  export_sctx = lTmpCtx.getp();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Prolog                                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

  Prolog ::= SIND_DeclList? VFO_DeclList?

  SIND_DeclList ::= SIND_Decl Separator | SIND_DeclList SIND_Decl Separator

  SIND_Decl ::= Setter | NamespaceDecl | DefaultNamespaceDecl | Import

  VFO_DeclList ::= VFO_Decl Separator | VFO_DeclList VFO_Decl Separator

  VFO_Decl ::= ContextItemDecl | AnnotatedDecl | OptionDecl |
               CollectionDecl | IndexDecl | IntegrityConstraintDecl

  AnnotatedDecl ::= "declare" Annotation* (VarDecl | FunctionDecl)

  Annotation ::= "%" EQName ("(" Literal ("," Literal)* ")")?

********************************************************************************/
void* begin_visit(const Prolog& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const Prolog& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  SIND_DeclList ::= SIND_Decl Separator | SIND_DeclList SIND_Decl Separator
********************************************************************************/
void* begin_visit(const SIND_DeclList& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const SIND_DeclList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  SIND_Decl ::= Setter | NamespaceDecl | DefaultNamespaceDecl | Import
********************************************************************************/


/******************************************************************************

  Setter ::= BoundarySpaceDecl |
             OrderingModeDecl |
             EmptyOrderDecl |
             CopyNamespacesDecl |
             DecimalFormatDecl |
             DefaultCollationDecl |
             BaseURIDecl |
             ConstructionDecl |

             RevalidationDecl // update extension

********************************************************************************/


/*******************************************************************************
  BoundarySpaceDecl ::= DECLARE_BOUNDARY_SPACE  ( PRESERVE | STRIP )
********************************************************************************/
void* begin_visit(const BoundarySpaceDecl& v)
{
  TRACE_VISIT();
  CHK_SINGLE_DECL (hadBSpaceDecl, err::XQST0068);
  theSctx->set_boundary_space_mode(v.get_boundary_space_mode());
  return NULL;
}

void end_visit(const BoundarySpaceDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  OrderingModeDecl ::= DECLARE_ORDERING  ( ORDERED | UNORDERED )
********************************************************************************/
void* begin_visit(const OrderingModeDecl& v)
{
  TRACE_VISIT();
  CHK_SINGLE_DECL(hadOrdModeDecl, err::XQST0065);
  theSctx->set_ordering_mode(v.get_mode());
  return NULL;
}


void end_visit(const OrderingModeDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  EmptyOrderDecl ::= DECLARE_DEFAULT_ORDER  EMPTY_GREATEST |
                     DECLARE_DEFAULT_ORDER  EMPTY_LEAST
********************************************************************************/
void* begin_visit(const EmptyOrderDecl& v)
{
  TRACE_VISIT();

  CHK_SINGLE_DECL(hadEmptyOrdDecl, err::XQST0069);

  theSctx->set_empty_order_mode(v.get_mode());
  return no_state;
}

void end_visit(const EmptyOrderDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  CopyNamespacesDecl ::= DECLARE_COPY_NAMESPACES PreserveMode COMMA InheritMode

  PreserveMode ::= "preserve" | "no-preserve"
  InheritMode ::=  "inherit" | "no-inherit"
********************************************************************************/
void* begin_visit(const CopyNamespacesDecl& v)
{
  TRACE_VISIT();
  CHK_SINGLE_DECL(hadCopyNSDecl, err::XQST0055);
  return no_state;
}

void end_visit(const CopyNamespacesDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
  theSctx->set_inherit_mode(v.get_inherit_mode ());
  theSctx->set_preserve_mode(v.get_preserve_mode ());
}


/******************************************************************************
  DecimalFormatDecl ::= "declare"
                        (("decimal-format" QName) | ("default" "decimal-format"))
                        (DFPropertyName "=" StringLiteral)*

  DFPropertyName ::= "decimal-separator" | "grouping-separator" |
                     "infinity" | "minus-sign" | "NaN" | "percent" |
                     "per-mille" | "zero-digit" | "digit" |
                     "pattern-separator"
********************************************************************************/
void* begin_visit(const DecimalFormatNode& v)
{
  TRACE_VISIT();

  store::Item_t qnameItem;

  if (!v.is_default)
  {
    expand_no_default_qname(qnameItem, v.format_name, loc);
  }

  DecimalFormat_t df = new DecimalFormat(v.is_default, qnameItem, v.param_list);
  df->validate(loc);
  theSctx->add_decimal_format(df, loc);

  return no_state;
}

void end_visit(const DecimalFormatNode& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  DefaultCollationDecl ::=	DECLARE_DEFAULT_COLLATION  URI_LITERAL
********************************************************************************/
void* begin_visit(DefaultCollationDecl const& v)
{
  TRACE_VISIT();

  theSctx->set_default_collation(v.get_collation().str(), loc);
  return NULL;
}

void end_visit(const DefaultCollationDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  BaseURIDecl ::= DECLARE_BASE_URI  URI_LITERAL
********************************************************************************/
void* begin_visit(const BaseURIDecl& v)
{
  TRACE_VISIT();

  CHK_SINGLE_DECL(hadBUriDecl, err::XQST0032);

  zstring uri(v.get_base_uri());
  try
  {
    theSctx->set_base_uri(uri);
  }
  catch (ZorbaException& e)
  {
    e.set_diagnostic( err::XQST0046 );
    set_source( e, loc );
    throw;
  }
  return NULL;
}


void end_visit(const BaseURIDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  ConstructionDecl ::= DECLARE_CONSTRUCTION  PRESERVE
                       DECLARE_CONSTRUCTION  STRIP
********************************************************************************/
void* begin_visit(const ConstructionDecl& v)
{
  TRACE_VISIT();

  CHK_SINGLE_DECL(hadConstrDecl, err::XQST0067);
  theSctx->set_construction_mode(v.get_mode());
  return NULL;
}

void end_visit (const ConstructionDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  RevalidationDecl ::= "declare" "revalidation" ("string" | "lax" | "skip")
********************************************************************************/
void* begin_visit(const RevalidationDecl& v)
{
  TRACE_VISIT();

  CHK_SINGLE_DECL (hadBUriDecl, err::XUST0003);
  theSctx->set_validation_mode(v.get_mode());
  return no_state;
}

void end_visit(const RevalidationDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  NamespaceDecl ::= ::= DECLARE_NAMESPACE  NCNAME  EQ  URI_LITERAL
********************************************************************************/
void* begin_visit(const NamespaceDecl& v)
{
  TRACE_VISIT();

  zstring pre = v.get_prefix();
  zstring uri = v.get_uri();

  if (pre == "xml" || pre == "xmlns")
  {
    throw XQUERY_EXCEPTION(
      err::XQST0070,
      ERROR_PARAMS( pre, ZED( NoRebindPrefix ) ),
      ERROR_LOC( loc )
    );
  }
  else if (uri == XML_NS || uri == XMLNS_NS)
  {
    throw XQUERY_EXCEPTION(
      err::XQST0070,
      ERROR_PARAMS( uri, ZED( NoBindURI ) ),
      ERROR_LOC( loc )
    );
  }

  theSctx->bind_ns(pre, uri, loc);

  return NULL;
}

void end_visit(const NamespaceDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  DefaultNamespaceDecl ::= DECLARE DEFAULT ELEMENT NAMESPACE URILiteral |
                           DECLARE DEFAULT FUNCTION NAMESPACE URILiteral
********************************************************************************/
void* begin_visit(DefaultNamespaceDecl const& v)
{
  TRACE_VISIT();

  switch (v.get_mode())
  {
  case ParseConstants::ns_element_default:
    theSctx->set_default_elem_type_ns(v.get_default_namespace(), loc);
    break;
  case ParseConstants::ns_function_default:
    theSctx->set_default_function_ns(v.get_default_namespace(), loc);
    break;
  }
  return NULL;
}

void end_visit(const DefaultNamespaceDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  Import ::= SchemaImport | ModuleImport
********************************************************************************/


/*******************************************************************************
  SchemaImport ::= "import" "schema" SchemaPrefix? URILiteral
                   ("at"  URILiteralList)?
********************************************************************************/
void* begin_visit(const SchemaImport& v)
{
  TRACE_VISIT();

  return import_schema(loc, v.get_prefix(), v.get_uri(), v.get_at_list());
}

void end_visit (const SchemaImport& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


/******************************************************************************
  URLLiteralList ::= URI_LITERAL | URILiteralList  COMMA  URI_LITERAL
********************************************************************************/
void* begin_visit(const URILiteralList& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const URILiteralList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/******************************************************************************
  SchemaPrefix ::= ("namespace" NCName "=") | ("default" "element" "namespace")
********************************************************************************/
void* begin_visit(const SchemaPrefix& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const SchemaPrefix& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  ModuleImport ::= "import" "module" ("namespace" NCName "=")? URILiteral
                   ("at" URILiteralList)?
********************************************************************************/
void* begin_visit(const ModuleImport& v)
{
  TRACE_VISIT();
  return no_state;
}


void end_visit(const ModuleImport& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  // Create a ModuleVersion based on the input namespace URI.
  const ModuleVersion modVer(v.get_uri());

  // targetNS is the target namespace *without* any
  // version-declaration fragment.
  zstring const targetNS = modVer.namespace_uri();
  zstring const pfx = (!v.get_prefix().empty()) ? v.get_prefix() : "";

  if (static_context::is_reserved_module(targetNS))
  {
    RAISE_ERROR(zerr::ZXQP0016_RESERVED_MODULE_TARGET_NAMESPACE, loc,
    ERROR_PARAMS(targetNS));
  }

  // The namespace prefix specified in a module import must not be xml or xmlns
  // [err:XQST0070]
  if (!pfx.empty() && (pfx == "xml" || pfx == "xmlns"))
    RAISE_ERROR(err::XQST0070, loc,
    ERROR_PARAMS(pfx, ZED(NoRebindPrefix)));

  // The first URILiteral in a module import must be of nonzero length
  // [err:XQST0088]
  if (targetNS.empty())
    throw XQUERY_EXCEPTION(err::XQST0088, ERROR_LOC(loc));

  // It is a static error [err:XQST0047] if more than one module import in a
  // Prolog specifies the same target namespace. Note: by checking this here,
  // we disallow importing two different versions of the same module from
  // within a single module. It is not clear how we could support that anyway,
  // since after import, they would both have the same namespace URI, and hence
  // any references to that namespace would be ambiguous.
  if (! theImportedModules.insert(targetNS.str()).second)
    RAISE_ERROR(err::XQST0047, loc, ERROR_PARAMS(targetNS));

  // The namespace prefix specified in a module import must not be the same as
  // any namespace prefix bound in the same module by another module import,
  // a schema import, a namespace declaration, or a module declaration with a
  // different target namespace [err:XQST0033].
  if (! pfx.empty() &&
      ! (pfx == theModulePrefix &&
         targetNS == theModuleNamespace))
  {
    theSctx->bind_ns(pfx, targetNS, loc, err::XQST0033);
  }

  const URILiteralList* atlist = v.get_at_list();

  // If the imported module X is a "pure builtin" one (i.e., contains
  // decalrations of zorba builtin functions only), then we don't need
  // to process it. We just need to record in the root sctx of the
  // importing module that X has been imported.
  if (atlist == NULL && static_context::is_builtin_module(targetNS))
  {
    theRootSctx->add_imported_builtin_module(targetNS);
#ifdef NDEBUG
    // We cannot skip the math or the sctx introspection modules because they
    // contain some non-external functions as well.
    if (!static_context::is_non_pure_builtin_module(targetNS))
    {
      return;
    }
#else
    if (static_context::is_builtin_virtual_module(targetNS))
    {
      return;
    }
#endif
  }

  // Create a list of absolute uris identifying the components of the module
  // being imported. If there are no "at" clauses, try to generate the
  // component URI from the target namespace. This is done using one or more
  // user-provided module resolvers. If no such resolvers were provided, or if
  // they don't know about the target namespace, the original target namespace
  // (including version fragment, if any) itself will be used as the (sole)
  // component URI. If there are "at" clauses, then any relative URIs that are
  // listed there are converted to absolute ones, using the base uri from the
  // sctx.

  std::vector<zstring> compURIs;
  if (atlist == NULL || atlist->size() == 0)
  {
    // Note the use of versioned_uri() here, so that the namespace with any
    // version fragment will be passed through to the mappers.
    theSctx->get_component_uris(modVer.versioned_uri(),
                                internal::EntityData::MODULE, compURIs);
  }
  else
  {
    for (ulong i = 0; i < atlist->size(); ++i)
    {
      compURIs.push_back(theSctx->resolve_relative_uri((*atlist)[i]).str());
    }
  }

  // Take each of the URIs collected above and import the module's functions
  // and variables into the current static context.
  for (std::vector<zstring>::const_iterator ite = compURIs.begin();
       ite != compURIs.end();
       ++ite)
  {
    // Create a ModuleVersion for the current component URI.
    const ModuleVersion compModVer(*ite);

    // Get the location uri for the module to import (minus version fragment,
    // if any). This will be the key for mod_ns_map and mod_sctx_map. Note:
    // if in future we support loading multiple versions of the same module,
    // this key will have to change.
    const zstring compURI = compModVer.namespace_uri();

    // If this import forms a cycle in a chain of module imports, skip it.
    // If the importing module is referencing any variable or function of
    // the skipped module, an XQST0093 error will be raised when the translator
    // tries to process that var or function reference.
    std::map<zstring, zstring> modulesStack = theModulesStack;
#if 0
    std::map<zstring, zstring>::iterator ite = modulesStack.begin();
    std::map<zstring, zstring>::iterator end = modulesStack.end();
    for (; ite != end; ++ite)
    {
      std::cout << "[" << (*ite).first << ", " << (*ite).second << "]" << std::endl;
    }
    std::cout << std::endl;
#endif
    if (! modulesStack.insert(std::pair<zstring, zstring>(compURI, targetNS)).second)
    {
      theHaveModuleImportCycle = true;
      return;
    }

    // importedNS is the target namespace of the imported module, as declared
    // inside the module itself.
    zstring importedNS;
    static_context_t importedSctx = NULL;

    // Check whether we have already imported a module component from
    // the current uri. If so, check that the target ns of what we
    // imported before is the same as what we are trying to import
    // now.
    if (theModulesInfo->mod_ns_map.get(compURI, importedNS))
    {
      if (importedNS != targetNS)
        RAISE_ERROR(err::XQST0059, loc, ERROR_PARAMS(targetNS, compURI));

      bool found = theModulesInfo->mod_sctx_map.get(compURI, importedSctx);
      ZORBA_ASSERT(found);
    }

    // We are importing a module for the 1st time.
    else
    {
      // Open the file containing the imported module.
      zstring compURL;
      std::istream* modfile;

      // Resolve the URI. Again, note the use of versioned_uri() here,
      // rather than using compURI directly, because we want the version
      // fragment to be passed to the mappers.
      zstring lErrorMessage;
      std::auto_ptr<internal::Resource> lResource =
      theSctx->resolve_uri(compModVer.versioned_uri(),
                           internal::EntityData::MODULE,
                           lErrorMessage);

      internal::StreamResource* lStreamResource =
      dynamic_cast<internal::StreamResource*> (lResource.get());

      if (lStreamResource != NULL)
      {
        modfile = lStreamResource->getStream();
        compURL = lStreamResource->getStreamUrl();
      }
      else
      {
        RAISE_ERROR(err::XQST0059, loc, ERROR_PARAMS(targetNS, compURI, lErrorMessage));
      }

      // Get the parent of the query root sctx. This is the user-specified sctx
      // (if any) or the zorba root sctx (if no user-specified sctx).
      static_context_t independentSctx =
      static_cast<static_context *>(theCCB->theRootSctx->get_parent());

      // Create the root sctx for the imported module as a child of the
      // independentSctx. Register this sctx in the query-level sctx map.
      static_context* moduleRootSctx;
      if (theCCB->isLoadPrologQuery())
        moduleRootSctx = theCCB->theRootSctx->create_child_context();
      else
        moduleRootSctx = independentSctx->create_child_context();

      moduleRootSctx->set_entity_retrieval_uri(compURI);
      moduleRootSctx->set_module_namespace(targetNS);
      moduleRootSctx->set_typemanager(new TypeManagerImpl(&GENV_TYPESYSTEM));
      short moduleRootSctxId = (short)theCCB->theSctxMap.size() + 1;
      (theCCB->theSctxMap)[moduleRootSctxId] = moduleRootSctx;

      // Create an sctx where the imported module is going to register
      // all the variable and function declarations that appear in its
      // prolog. After the translation of the imported module is done,
      // this sctx will be merged with the sctx of the importing
      // module.
      importedSctx = independentSctx->create_child_context();
      importedSctx->set_module_namespace(targetNS);

      // Register the imported_sctx in theModulesInfo->mod_sctx_map so
      // that it is accessible by both the importing and the imported
      // modules.
      theModulesInfo->mod_sctx_map.put(compURI, importedSctx);

      // Parse the imported module. fileURL is information only - it is used
      // by the parser when creating query locations, etc.
      XQueryCompiler xqc(theCCB);
      zstring fileURL;
      if (compURL.size() != 0)
      {
        fileURL = compURL;
      }
      else
      {
        fileURL = compURI;
      }

      rchandle<parsenode> ast = xqc.parse(*modfile, fileURL);

      // Get the target namespace that appears in the module declaration
      // of the imported module and check that this ns is the same as the
      // target ns in the module import statement.
      // Also make sure that the imported module is a library module
      LibraryModule* mod_ast = dynamic_cast<LibraryModule *>(&*ast);
      if (mod_ast == NULL)
        RAISE_ERROR(err::XQST0059, loc, ERROR_PARAMS(targetNS, compURI));

      importedNS = mod_ast->get_decl()->get_target_namespace().str();

      if (importedNS.empty())
        throw XQUERY_EXCEPTION(err::XQST0088, ERROR_LOC(loc));

      if (importedNS != targetNS)
        RAISE_ERROR(err::XQST0059, loc, ERROR_PARAMS(targetNS, compURI));

      // translate the imported module
      translate_aux(theRootTranslator,
                    *ast,
                    moduleRootSctx,
                    moduleRootSctxId,
                    theModulesInfo,
                    modulesStack,
                    true,
                    theSctx->xquery_version());

      // Determine the imported version, and verify that it satisfies the
      // import specification (if any). QQQ this really should be done whether
      // the module was newly-imported or already imported; it should be done
      // below just before "Merge the exported sctx". However, currently at
      // least, "declare option" information is not stored in the sctx that is
      // in mod_sctx_map; therefore, when dealing with an already-imported
      // sctx, there's no way to know what version it is. SF bug# 3312333.
      if (modVer.is_valid_version())
      {
        store::Item_t lMajorOpt;
        theSctx->expand_qname(lMajorOpt,
                              zstring(ZORBA_VERSIONING_NS),
                              zstring(""),
                              zstring(ZORBA_OPTION_MODULE_VERSION),
                              loc);
        zstring lImportedVersion;
        if (!moduleRootSctx->lookup_option(lMajorOpt.getp(), lImportedVersion))
        {
          lImportedVersion = "0.0";
        }
        ModuleVersion lImportedModVer(compURI, lImportedVersion);
        if (! lImportedModVer.is_valid_version())
        {
          RAISE_ERROR(zerr::ZXQP0039_INVALID_VERSION_SPECIFICATION, loc,
          ERROR_PARAMS(lImportedVersion));
        }

        if (!lImportedModVer.satisfies(modVer))
        {
          RAISE_ERROR(zerr::ZXQP0037_INAPPROPRIATE_MODULE_VERSION, loc,
          ERROR_PARAMS(modVer.versioned_uri(), lImportedVersion));
        }
      }

      // Register the mapping between the current location uri and the
      // target namespace.
      theModulesInfo->mod_ns_map.put(compURI, importedNS);

#ifdef ZORBA_WITH_DEBUGGER
      // If we compile in debug mode, we add the namespace uri into a
      // map, that allows the debugger to set breakpoints at a
      // namespace uri and line number
      if (theCCB->theDebuggerCommons)
      {
        theCCB->theDebuggerCommons->addModuleUriMapping
          (importedNS.str(), compURL.c_str());
      }
#endif
    }

    // Merge the exported sctx of the imported module into the sctx of the
    // current module. Note: We catch duplicate functions / vars in
    // theModulesInfo->globalSctx. We can safely ignore the return value.
    // We might even be able to assert() here (not sure though).
    theSctx->import_module(importedSctx.getp(), loc);

  } // for (vector<zstring>::iterator ite = lURIs.begin();
}


/*******************************************************************************
  VFO_DeclList ::= VFO_Decl Separator | VFO_DeclList VFO_Decl Separator

  VFO_Decl ::= ContextItemDecl | AnnotatedDecl | OptionDecl |
               CollectionDecl | IndexDecl | IntegrityConstraintDecl

  AnnotatedDecl ::= "declare" Annotation* (VarDecl | FunctionDecl)

  Annotation ::= "%" EQName ("(" Literal ("," Literal)* ")")?

********************************************************************************/
void* begin_visit(const VFO_DeclList& v)
{
  TRACE_VISIT();

  TypeManager* tm = CTX_TM;

  // Function declaration translation must be done in two passes because of
  // mutually recursive functions and also because the defining expr of a declared
  // var may reference a function that is declared after the var. So, here's the
  // 1st pass; it translates
  //  (1) the annotations of variable and function declarations
  //  (2) the type declarations for the params and return value of functions
  //  (3) and then creates the udf object and binds it in the sctx.
  // The 1st pass also binds all options, so that the module version information
  // is available if we try to load external function libraries.
  // 2nd pass;  happens when accept() is called on each individual FunctionDecl
  // node in the list.

  for (std::vector<rchandle<parsenode> >::const_iterator it = v.begin();
       it != v.end();
       ++it)
  {
    const OptionDecl* opt_decl = it->dyn_cast<OptionDecl>().getp();

    if (opt_decl != NULL)
    {
      store::Item_t qnameItem;
      zstring value = opt_decl->get_val().str();

      expand_no_default_qname(qnameItem, opt_decl->get_qname(), loc);

      if (qnameItem->getPrefix().empty() && qnameItem->getNamespace().empty())
        RAISE_ERROR(err::XPST0081, loc, ERROR_PARAMS(qnameItem->getStringValue()));

      theSctx->bind_option( qnameItem, value, opt_decl->get_location() );
      continue;
    }

    const FunctionDecl* func_decl = it->dyn_cast<FunctionDecl>().getp();

    // skip variable and option declarations.
    if (func_decl == NULL)
      continue;

    AnnotationListParsenode* lAnns = func_decl->get_annotations();
    if (lAnns)
    {
      if (theSctx->xquery_version() < StaticContextConsts::xquery_version_3_0)
      {
        RAISE_ERROR(err::XPST0003, loc,
        ERROR_PARAMS("functions and variables annotations only available in XQuery 1.1 or later"));
      }

      lAnns->accept(*this);
    }

    const QueryLoc& loc = func_decl->get_location();

    // Expand the function qname (error is raised if qname resolution fails)
    // and check it for errors. The following conditions are checked:
    // - Function must be declared in a non-NULL namespace.
    // - Function must not be in any of the reserved namespaces.
    // - In a module, all exports must be inside the target ns.
    const QName* fname = func_decl->get_name().getp();
    store::Item_t qnameItem;
    expand_function_qname(qnameItem, fname, fname->get_location());

    const zstring& ns = qnameItem->getNamespace();

    if (ns.empty())
      RAISE_ERROR(err::XQST0060, loc, ERROR_PARAMS(qnameItem->getStringValue()));

    if (ns == static_context::W3C_FN_NS ||
        ns == XML_NS ||
        ns == XML_SCHEMA_NS ||
        ns == XSI_NS ||
        ns == XQUERY_MATH_FN_NS)
    {
      RAISE_ERROR(err::XQST0045, func_decl->get_location(),
      ERROR_PARAMS(qnameItem->getLocalName()));
    }

    if (! theModuleNamespace.empty() && ns != theModuleNamespace)
      RAISE_ERROR(err::XQST0048, loc, ERROR_PARAMS(qnameItem->getStringValue()));

    // Process the parameter types and the return type in order to create the
    // function signature.
    rchandle<ParamList> params = func_decl->get_paramlist();
    if (params == NULL)
      params = new ParamList(loc);

    csize numParams = params->size();

    std::vector<xqtref_t> paramTypes;

    for (std::vector<rchandle<Param> >::const_iterator it = params->begin();
         it != params->end();
         ++it)
    {
      const Param* param = (*it).getp();
      const SequenceType* paramType = param->get_typedecl().getp();
      if (paramType == NULL)
      {
        paramTypes.push_back(GENV_TYPESYSTEM.ITEM_TYPE_STAR);
      }
      else
      {
        paramType->accept(*this);
        paramTypes.push_back(pop_tstack());
      }
    }

    xqtref_t returnType = GENV_TYPESYSTEM.ITEM_TYPE_STAR;

    if (func_decl->get_return_type() != NULL)
    {
      func_decl->get_return_type()->accept(*this);
      returnType = pop_tstack();
    }
    else if (func_decl->is_updating())
    {
      // TODO: should we have a different default?
      // TODO: if returnType is set to something other than ITEM_TYPE_STAR
      // the body of the udf will be wrapped in a treat expr. So, we will
      // have an updating expr as input to a treat expr, which is not allowed
      // yet.
      //returnType = theRTM.EMPTY_TYPE;
    }

    // Create the function signature.
    bool isVariadic = (theAnnotations ?
                       ZANN_CONTAINS(zann_variadic):
                       false);

    signature sig(qnameItem, paramTypes, returnType, isVariadic);

    // Get the scripting kind of the function
    bool isSequential = (theAnnotations ?
                         ZANN_CONTAINS(zann_sequential) :
                         false);

    expr_script_kind_t scriptKind = SIMPLE_EXPR;

    if (func_decl->is_updating())
      scriptKind = UPDATING_EXPR;
    else if (isSequential)
      scriptKind = SEQUENTIAL_FUNC_EXPR;

    // create the function object
    function_t f;

    if (func_decl->is_external())
    {
      // 1. lookup if the function is a built-in function
      f = theSctx->lookup_fn(qnameItem, numParams);

      if (f.getp() != 0)
      {
        // We make sure that the types of the parameters and the return type
        // are subtypes of the ones declared in the module
        const signature& s = f->getSignature();
        if (!s.subtype(tm, sig, loc))
        {
          RAISE_ERROR(zerr::ZXQP0007_FUNCTION_SIGNATURE_NOT_EQUAL, loc,
          ERROR_PARAMS(BUILD_STRING('{',
                                    qnameItem->getNamespace(),
                                    '}',
                                    qnameItem->getLocalName())));
        }

        if (isSequential && !f->isSequential())
        {
          RAISE_ERROR(zerr::ZXQP0010_FUNCTION_NOT_SEQUENTIAL, loc,
          ERROR_PARAMS(BUILD_STRING('{',
                                    qnameItem->getNamespace(),
                                    '}',
                                    qnameItem->getLocalName())));
        }

        f->setAnnotations(theAnnotations);
        theAnnotations = NULL; // important to reset

        // continue with the next declaration, because we don't add already
        // built-in functions to the static context
        continue;
      }

      // 2. if no built-in function is there, we check the static context
      // to see if the user has registered an external function
      ExternalFunction* ef = 0;
      try
      {
        ef = theSctx->lookup_external_function(qnameItem->getNamespace(),
                                               qnameItem->getLocalName());
      }
      catch (XQueryException& e)
      {
        set_source(e, loc);
        throw;
      }

      // The external function must be registered already in the static context
      // via the StaticContextImpl::registerExternalModule() user api.
      if (ef == NULL)
      {
        RAISE_ERROR(zerr::ZXQP0008_FUNCTION_IMPL_NOT_FOUND, loc,
        ERROR_PARAMS(BUILD_STRING('{',
                                  qnameItem->getNamespace(),
                                  '}',
                                  qnameItem->getLocalName(),
                                  isVariadic?"variadic":"#", numParams)));
      }
      else
      {
        if (ef->getLocalName().compare(qnameItem->getLocalName().str()) != 0)
        {
          RAISE_ERROR(zerr::ZXQP0009_FUNCTION_LOCALNAME_MISMATCH, loc,
          ERROR_PARAMS(qnameItem->getLocalName(), ef->getLocalName()));
        }
      }

      ZORBA_ASSERT(ef != NULL);

      f = new external_function(loc,
                                theSctx,
                                qnameItem->getNamespace(),
                                sig,
                                scriptKind,
                                ef);
    }
    else // Process UDF (non-external) function declaration
    {
      f = new user_function(loc, sig, NULL, scriptKind); // no body for now
    }

    f->setAnnotations(theAnnotations);
    theAnnotations = NULL; // important to reset

    // Create bindings between (function qname item, arity) and function obj
    // in the current sctx of this module and, if this is a lib module, in its
    // export sctx as well.
    bind_fn(f, numParams, loc);
  }

  return no_state;
}


void end_visit(const VFO_DeclList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  thePrologGraph.reorder_globals(thePrologVars);
}


/*******************************************************************************

  AnnotatedDecl ::= "declare" Annotation* (VarDecl | FunctionDecl)

  Annotation ::= "%" EQName ("(" Literal ("," Literal)* ")")?

  FunctionDecl ::= "function" EQName "(" ParamList? ")" ("as" SequenceType)?
                        (BlockExpr | "external")

  BlockExpr ::= "{" Statements Expr "}"

  Note: the applicable annotations are private vs public, sequential vs
  non-sequential, and deterministic vs nondeterministic.
********************************************************************************/
void* begin_visit(const FunctionDecl& v)
{
  TRACE_VISIT();

  push_scope();

  // Get function obj out of function qname (will raise error if prefix in qname
  // is not bound to a namespace).
  function* f = lookup_fn(v.get_name(), v.get_param_count(), loc);

  assert(f);

  thePrologGraph.addFuncVertex(f);
  theCurrentPrologVFDecl = PrologGraphVertex(f);

  theHaveUpdatingExitExprs = false;
  theHaveSequentialExitExprs = false;

  return no_state;
}


void end_visit(const FunctionDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  theCurrentPrologVFDecl.setNull();

  const zstring& fname = v.get_name()->get_qname();

  csize numParams = v.get_param_count();

  function* lFunc = lookup_fn(v.get_name(), numParams, loc);

  // TODO: remove this error
  if (lFunc && lFunc->isUpdating() && v.get_return_type() != 0)
    RAISE_ERROR(err::XUST0028, loc, ERROR_PARAMS(fname));

  if (v.get_return_type() != NULL)
    pop_tstack();

  expr_t body;
  user_function* udf = NULL;

  if (!v.is_external())
  {
    udf = dynamic_cast<user_function *>(lFunc);

    body = pop_nodestack();

    wrap_in_debugger_expr(body, v.get_name()->get_location());

    ZORBA_ASSERT(udf != NULL);
    assert(body != NULL);
    assert(! (body->get_scripting_detail() & BREAKING_EXPR));

    // Mark the body as non-sequential if the only reason it is marked sequential
    // is because it contains exit exprs.
    body->set_not_exiting();

    // Check for scripting category inconsistency between the udf declaration
    // and its body.
    if (udf->isSequential())
    {
      if (body->is_updating() || theHaveUpdatingExitExprs)
      {
        RAISE_ERROR(zerr::XSST0002, loc, ERROR_PARAMS(fname));
      }

      if (!body->is_sequential())
      {
        theCCB->theXQueryDiagnostics->add_warning(
        NEW_XQUERY_WARNING(zwarn::ZWST0003_FAKE_SEQUENTIAL_FUNCTION,
                           WARN_PARAMS(fname),
                           WARN_LOC(loc)));
      }
    }
    else if (udf->isUpdating())
    {
      if (body->is_sequential() || theHaveSequentialExitExprs)
      {
        RAISE_ERROR(zerr::XSST0003, loc, ERROR_PARAMS(fname));
      }

      if (!body->is_updating_or_vacuous())
      {
        RAISE_ERROR(err::XUST0002, loc, ERROR_PARAMS(ZED(XUST0002_UDF_2), fname));
      }
    }
    else if (body->is_sequential() || theHaveSequentialExitExprs)
    {
      RAISE_ERROR(zerr::XSST0004, loc, ERROR_PARAMS(fname));
    }
    else if (body->is_updating() || theHaveUpdatingExitExprs)
    {
      RAISE_ERROR(err::XUST0001, loc, ERROR_PARAMS(ZED(XUST0001_UDF_2), fname));
    }

    // sequential udfs are implicitly declared as non-deterministic (even if
    // they are actuall deterministic). We do this to avoid having to declare
    // a udf as both sequential and non-deterministic. It is OK to do this,
    // because the optimization constraints imposed by sequential are a superset
    // of those imposed by non-deterministic.
    if (udf->isSequential())
      udf->setDeterministic(false);

    // If function has any params, they have been wraped in a flwor expr. Set the
    // return clause of the flwor to the body expr of the function, and then make
    // this flwor be the actual body of the function.
    std::vector<var_expr_t> args;
    if (numParams > 0)
    {
      rchandle<flwor_expr> flwor = pop_nodestack().dyn_cast<flwor_expr>();
      ZORBA_ASSERT(flwor != NULL);

      for (csize i = 0; i < numParams; ++i)
      {
        const let_clause* lc = dynamic_cast<const let_clause*>((*flwor)[i]);
        var_expr* argVar = dynamic_cast<var_expr*>(lc->get_expr());
        ZORBA_ASSERT(argVar != NULL);
        args.push_back(argVar);
      }

      flwor->set_return_expr(body);
      body = flwor.getp();

      udf->setArgVars(args);
    }

    if (udf->isExiting())
    {
      body = new exit_catcher_expr(theRootSctx, loc, body);
    }

    // Wrap the UDF body to the type-related expr that enforce the declared
    // return type.
    xqtref_t returnType = udf->getSignature().returnType();

    if (TypeOps::is_builtin_simple(CTX_TM, *returnType))
    {
      body = wrap_in_atomization(body);
      body = wrap_in_type_promotion(body, returnType, udf->getName());
      body->set_loc(v.get_return_type()->get_location());
    }
    else
    {
      body = wrap_in_type_match(body, returnType, loc, err::XPTY0004, udf->getName());
    }

    udf->setBody(body);

    if (theCCB->theConfig.translate_cb != NULL)
      theCCB->theConfig.translate_cb(&*body, fname.str());
  }
  else
  {
    // The flwor expr representing the params is created even for external
    // functions. But in this case, it is not really needed. We must still
    // pop it from the node stack, but then we just discard it.
    if (numParams > 0)
    {
      rchandle<flwor_expr> flwor = pop_nodestack().dyn_cast<flwor_expr>();
      ZORBA_ASSERT(flwor != NULL);
    }
  }

  pop_scope();
}


/*******************************************************************************
  ParamList ::= Param ("," Param)*
********************************************************************************/
void* begin_visit(const ParamList& v)
{
  TRACE_VISIT();

  if (v.size() > 0)
  {
    rchandle<flwor_expr> flwor = new flwor_expr(theRootSctx, loc, false);
    push_nodestack(flwor.getp());
  }
  return no_state;
}


void end_visit(const ParamList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  Param ::= "$" QName TypeDeclaration?
********************************************************************************/
void* begin_visit(const Param& v)
{
  TRACE_VISIT();
  return no_state;
}


void end_visit(const Param& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  rchandle<flwor_expr> flwor = theNodeStack.top().cast<flwor_expr> ();
  ZORBA_ASSERT(flwor != NULL);

  store::Item_t qnameItem;
  expand_no_default_qname(qnameItem, v.get_name(), loc);

  var_expr_t arg_var = create_var(loc, qnameItem, var_expr::arg_var);
  var_expr_t subst_var = bind_var(loc, qnameItem, var_expr::let_var);

  let_clause_t lc = wrap_in_letclause(&*arg_var, subst_var);

  // theCurrentPrologVFDecl might be null in case of inline functions
  // inline functions currently can't be sequential anyway
  // hence, we can always lazy evaluation
  if (!theCurrentPrologVFDecl.isNull())
  {
    //const function* f = theCurrentPrologVFDecl.getFunction();
    //lc->setLazyEval(!f->isSequential());
  }
  else
  {
    //lc->setLazyEval(true);
  }

  flwor->add_clause(lc);

  // Set the decalred type of the arg and let vars. Note: we do this after
  // creating the let clause, so the let clause itself does not do any type
  // checking. Type checking will be done by other means before the args
  // are bound to the params.
  if (v.get_typedecl() != NULL)
  {
    arg_var->set_type(pop_tstack());
    subst_var->set_type(arg_var->get_type());
  }
}


/*******************************************************************************

  VarDecl is used to represent both global and block-local var declarations.

  Global declarations:
  --------------------

  AnnotatedDecl ::= "declare" Annotation* (VarDecl | FunctionDecl)

  Annotation ::= "%" EQName ("(" Literal ("," Literal)* ")")?

  VarDecl ::= variable" "$" VarName TypeDeclaration?
              ((":=" VarValue) | ("external" (":=" VarDefaultValue)?))

  VarValue ::= ExprSingle

  VarDefaultValue ::= ExprSingle

  Note: The ExprSingle in VarValue and VarDefaultValue must be a simple expr.

  Note: the applicable annotations are private vs public, and assignable vs
  non-assignable.


  Local declarations:
  -------------------

  VarDeclStatement ::= ("local" Annotation*)? "variable"
                       "$" VarName TypeDeclaration? (":=" ExprSingle)?
                       ("," "$" VarName TypeDeclaration? (":=" ExprSingle)?)* ";"

  Note: The initializing ExprSingle in VarValue must be a non-updating expr.

  Note: The applicable annotations are assignable vs non-assignable.

  Note: Local var decls may appear only as direct operands of block exprs.
********************************************************************************/
void* begin_visit(const VarDecl& v)
{
  TRACE_VISIT();

  store::Item_t qnameItem;
  expand_no_default_qname(qnameItem, v.get_name(), loc);

  var_expr_t ve;

  if (v.is_global())
  {
    ve = create_var(loc, qnameItem, var_expr::prolog_var);

    if (v.is_extern())
      ve->set_external(true);

    thePrologGraph.addVarVertex(ve);
    theCurrentPrologVFDecl = PrologGraphVertex(ve);
  }
  else
  {
    if (theNodeStack.top()->get_expr_kind() != block_expr_kind)
    {
      ZORBA_ASSERT(false);
    }

    ve = create_var(loc, qnameItem, var_expr::local_var);
  }

  push_nodestack(ve.getp());
  return no_state;
}


void end_visit(const VarDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  if (v.is_global())
    theCurrentPrologVFDecl.setNull();

  expr_t initExpr = (v.get_initexpr() == NULL ? expr_t(NULL) : pop_nodestack());

  var_expr_t ve = dynamic_cast<var_expr*>(pop_nodestack().getp());

  if (theAnnotations)
  {
    if (v.is_global())
    {
      if (ZANN_CONTAINS(fn_private))
        ve->set_private(true);
    }

    if (ZANN_CONTAINS(zann_assignable))
    {
      ve->set_mutable(true);
    }
    else if (ZANN_CONTAINS(zann_nonassignable))
    {
      ve->set_mutable(false);
    }
    else if (v.is_global())
    {
      ve->set_mutable(theSctx->is_feature_set(feature::scripting));
    }
  }
  else if (v.is_global())
  {
    ve->set_mutable(theSctx->is_feature_set(feature::scripting));
  }

  xqtref_t type;
  if (v.get_typedecl() != NULL)
  {
    type = pop_tstack();

    ve->set_type(type);
  }

  // Put a mapping between the var name and the var_expr in the local sctx.
  // Raise error if var name exists already in local sctx obj.
  bind_var(ve, theSctx);

  if (v.is_global())
  {
    // All vars declared in a module must be in the same namespace as the module
    if (! theModuleNamespace.empty() &&
        ve->get_name()->getNamespace() != theModuleNamespace)
    {
      RAISE_ERROR(err::XQST0048, loc, ERROR_PARAMS(ve->get_name()->getStringValue()));
    }

    // Make sure that there is no other prolog var with the same name in any of
    // modules translated so far.
    bind_var(ve, theModulesInfo->globalSctx.get());

    // Make sure the initExpr is a simple expr.
    if (initExpr != NULL)
    {
      expr::checkSimpleExpr(initExpr);
      ve->setHasInitializer(true);
    }

    // If this is a library module, register the var in the exported sctx as well.
    if (export_sctx != NULL)
      bind_var(ve, export_sctx);

#ifdef ZORBA_WITH_DEBUGGER
    if (initExpr != NULL && theCCB->theDebuggerCommons != NULL) 
    {
      QueryLoc lExpandedLocation = expandQueryLoc(v.get_name()->get_location(),
                                                  initExpr->get_loc());

      wrap_in_debugger_expr(initExpr, lExpandedLocation, true, true);
    }
#endif

    // The ve and its associated intExpr will be put into var_decl_expr that
    // will creaated by the wrap_in_globalvar_assign() method when it is called
    // at the end of the translation of each module.
    thePrologVars.push_back(GlobalBinding(ve, initExpr, v.is_extern()));
  }
  else
  {
    // The ve and its associated intExpr will be put into var_decl_expr that
    // will be created by the translation of the parent block expr, immediately
    // after returning from this method.
    push_nodestack(ve.getp());

#ifdef ZORBA_WITH_DEBUGGER
    if (initExpr != NULL && theCCB->theDebuggerCommons != NULL)
    {
      QueryLoc lExpandedLocation = expandQueryLoc(v.get_name()->get_location(),
                                                  initExpr->get_loc());

      wrap_in_debugger_expr(initExpr, lExpandedLocation, true, true);
    }
#endif

    push_nodestack(initExpr);
  }
  theAnnotations = NULL;

}


/*******************************************************************************
  AnnotationList := Annotation*

  Annotation ::= "%" EQName  ("(" Literal  ("," Literal)* ")")?
********************************************************************************/

void* begin_visit(const AnnotationListParsenode& v)
{
  TRACE_VISIT();

  assert(theAnnotations == NULL);

  theAnnotations = new AnnotationList();

  return no_state;
}


void end_visit(const AnnotationListParsenode& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  // detect duplicates and conflicting declarations
  theAnnotations->checkConflictingDeclarations(loc);
}


void* begin_visit(const AnnotationParsenode& v)
{
  TRACE_VISIT();

  return no_state;
}

void end_visit(const AnnotationParsenode& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  store::Item_t lExpandedQName;
  expand_function_qname(lExpandedQName, v.get_qname().getp(), loc);

  zstring annotNS = lExpandedQName->getNamespace();

  if (annotNS == static_context::W3C_XML_NS ||
      annotNS == XML_SCHEMA_NS ||
      annotNS == XSI_NS ||
      annotNS == static_context::W3C_FN_NS ||
      annotNS == XQUERY_MATH_FN_NS ||
      annotNS == ZORBA_ANNOTATIONS_NS)
  {
    if (AnnotationInternal::lookup(lExpandedQName) == AnnotationInternal::zann_end)
    {
      RAISE_ERROR(err::XQST0045, loc,
      ERROR_PARAMS( "%" + (lExpandedQName->getPrefix().empty() ?
                           "\'" + lExpandedQName->getNamespace() + "\'"
                           : lExpandedQName->getPrefix())
                    + ":" + lExpandedQName->getLocalName()));
    }
  }
  else
  {
    // annotation in unknown namespace -- generate a warning
    theCCB->theXQueryDiagnostics->add_warning(
      NEW_XQUERY_WARNING(
        zwarn::ZWST0002_UNKNOWN_ANNOTATION,
        WARN_PARAMS( "%" + (lExpandedQName->getPrefix().empty() ?
                      "\'" + lExpandedQName->getNamespace() + "\'"
                      : lExpandedQName->getPrefix())
                      + ":" + lExpandedQName->getLocalName()),
        WARN_LOC(loc)));
  }

  std::vector<rchandle<const_expr> > lLiterals;

  if (v.get_literals())
  {
    std::vector<rchandle<exprnode> >::const_iterator lIter;

    for (lIter = v.get_literals()->begin();
         lIter != v.get_literals()->end();
         ++lIter)
    {
      rchandle<const_expr> lLiteral = dynamic_cast<const_expr*>(pop_nodestack().getp());
      lLiterals.insert(lLiterals.begin(), lLiteral);
    }
  }

  theAnnotations->push_back(lExpandedQName, lLiterals);
}


void* begin_visit(const AnnotationLiteralListParsenode& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const AnnotationLiteralListParsenode& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}



/*******************************************************************************
  ContextItemDecl ::= "declare" "context" "item" ("as" ItemType)?
                      ((":=" VarValue) |
                      ("external" (":=" VarDefaultValue)?))
********************************************************************************/
void* begin_visit(const CtxItemDecl& v)
{
  TRACE_VISIT();

  if (theSctx->xquery_version() <= StaticContextConsts::xquery_version_1_0)
    throw XQUERY_EXCEPTION(
      err::XPST0003,
      ERROR_PARAMS(
        ZED( XQueryVersionAtLeast10_2 ), theSctx->xquery_version()
      ),
      ERROR_LOC( loc )
    );

  return no_state;
}

void end_visit(const CtxItemDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t initExpr;
  if (v.get_expr() != NULL)
    initExpr = pop_nodestack();

  xqtref_t type = GENV_TYPESYSTEM.ITEM_TYPE_ONE;
  if (v.get_type() != NULL)
    type = pop_tstack();

  var_expr_t var;

  if (inLibraryModule())
  {
    var = bind_var(loc, DOT_VARNAME, var_expr::prolog_var, type);
  }
  else
  {
    var = lookup_ctx_var(DOT_VARNAME, loc);
    assert(var);
  }

  var->set_external(v.is_external());
  var->set_type(type);

  GlobalBinding b(var, initExpr, true);
  declare_var(b, theModulesInfo->theInitExprs);
}


/*******************************************************************************
  OptionDecl ::= DECLARE_OPTION  QNAME  STRING_LITERAL
********************************************************************************/
void* begin_visit(const OptionDecl& v)
{
  TRACE_VISIT();

  // Actual binding of options was already done at VFO_DeclList time; here we
  // take actions based on certain specific options.

  // TODO probably we should have some kind of option-callback mechanism,
  // rather than processing all built-in Zorba options here
  //store::Item_t qnameItem;
  //zstring value = v.get_val().str();

  //expand_no_default_qname(qnameItem, v.get_qname(), loc);

  return no_state;
}

void end_visit(const OptionDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  [*] CollectionDecl ::= "declare" Annotation* "collection" QName
                         ("as" CollectionTypeDecl)?

  [*] CollectionTypeDecl ::= KindTest OccurenceIndicator?
********************************************************************************/
void* begin_visit(const CollectionDecl& v)
{
  TRACE_VISIT();

  if ( !theSctx->is_feature_set(feature::ddl) )
  {
    RAISE_ERROR(zerr::ZXQP0050_FEATURE_NOT_AVAILABLE, loc,
    ERROR_PARAMS("data-definition (ddl)"));
  }

  return no_state;
}

void end_visit(const CollectionDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  TypeManager* tm = CTX_TM;

  const QName* lName = v.getName();

  // a collection declaration must allways be in a library module
  if (!inLibraryModule())
  {
    RAISE_ERROR(zerr::ZDST0003_COLLECTION_DECL_IN_MAIN_MODULE, loc,
    ERROR_PARAMS(lName->get_qname()));
  }

  // Expand the collection qname (error is raised if qname resolution fails).
  store::Item_t lExpandedQName;
  expand_function_qname(lExpandedQName, lName, lName->get_location());

  if (lExpandedQName->getNamespace() != theModuleNamespace)
  {
    RAISE_ERROR(zerr::ZDST0007_COLLECTION_DECL_IN_FOREIGN_MODULE, loc,
    ERROR_PARAMS(lName->get_qname()));
  }

  // Get the static type of the root nodes
  xqtref_t lNodeType;
  xqtref_t lCollectionType;
  TypeConstants::quantifier_t quant;
  if (v.getType() == 0)
  {
    lNodeType = theRTM.DOCUMENT_UNTYPED_TYPE_ONE;
    lCollectionType = theRTM.DOCUMENT_UNTYPED_TYPE_STAR;
    quant = TypeConstants::QUANT_STAR;
  }
  else
  {
    lCollectionType = pop_tstack();
    lNodeType = TypeOps::prime_type(tm, *lCollectionType);
    quant = lCollectionType->get_quantifier();
  }

  AnnotationListParsenode* lAnns = v.get_annotations();
  if (lAnns)
  {
    lAnns->accept(*this);
  }

  if ( !theAnnotations )
  {
    theAnnotations = new AnnotationList();
  }

  // compute (redundant) enum values and assign
  // default annotations if no annotation for a group
  // of annotations exists:
  // update mode: mutable
  // order mode: unordered
  // node modifier: mutable nodes
  StaticContextConsts::declaration_property_t lUpdateMode;
  StaticContextConsts::declaration_property_t lOrderMode;
  StaticContextConsts::node_modifier_t lNodeModifier;

  std::vector<rchandle<const_expr> > lLiterals;
  if (ZANN_CONTAINS(zann_queue))
  {
    lUpdateMode = StaticContextConsts::decl_queue;
  }
  else if (ZANN_CONTAINS(zann_append_only))
  {
    lUpdateMode = StaticContextConsts::decl_append_only;
  }
  else if (ZANN_CONTAINS(zann_const))
  {
    lUpdateMode = StaticContextConsts::decl_const;
  }
  else if (ZANN_CONTAINS(zann_mutable))
  {
    lUpdateMode = StaticContextConsts::decl_mutable;
  }
  else
  {
    theAnnotations->
    push_back(AnnotationInternal::lookup(AnnotationInternal::zann_mutable),
              lLiterals);

    lUpdateMode = StaticContextConsts::decl_mutable;
  }

  if (ZANN_CONTAINS(zann_ordered))
  {
    lOrderMode = StaticContextConsts::decl_ordered;
  }
  else if (ZANN_CONTAINS(zann_unordered))
  {
    lOrderMode = StaticContextConsts::decl_unordered;
  }
  else
  {
    theAnnotations->
    push_back(AnnotationInternal::lookup(AnnotationInternal::zann_unordered),
              lLiterals);

    lOrderMode = StaticContextConsts::decl_unordered;
  }

  if (ZANN_CONTAINS(zann_read_only_nodes))
  {
    lNodeModifier = StaticContextConsts::read_only;
  }
  else if (ZANN_CONTAINS(zann_mutable_nodes))
  {
    lNodeModifier = StaticContextConsts::mutable_node;
  }
  else
  {
    theAnnotations->
    push_back(AnnotationInternal::lookup(AnnotationInternal::zann_mutable_nodes),
              lLiterals);

    lNodeModifier = StaticContextConsts::mutable_node;
  }

  // Create the collection object and register it in the static context
  StaticallyKnownCollection_t lColl = new StaticallyKnownCollection(
                                            lExpandedQName,
                                            theAnnotations,
                                            lNodeType,
                                            lCollectionType,
                                            lUpdateMode,
                                            lOrderMode,
                                            lNodeModifier);

  theAnnotations = NULL; // important to reset

  theSctx->bind_collection(lColl, loc);

  assert(export_sctx);
  export_sctx->bind_collection(lColl, loc);

  // Create an IC to check that the cardinality of the collection matches its
  // declared type.
  if (quant != TypeConstants::QUANT_STAR)
  {
    // TODO
  }
}


/***************************************************************************//**
  IndexDecl ::= "declare" Annotation* "index" QName
                "on" "nodes" IndexDomainExpr "by" IndexKeyList

  IndexDomainExpr := PathExpr

  IndexKeyList := IndexKeySpec+

  IndexKeySpec := PathExpr (TypeDeclaration)? ("collation" UriLiteral)?

  Translation of an index declaration involves the creation and setting-up of
  a IndexDecl obj (see compiler/indexing/value_index.h) and the creation in
  the current sctx (which is the root sctx of the current module) of a binding
  between the index uri and this IndexDecl obj.
********************************************************************************/
void* begin_visit(const AST_IndexDecl& v)
{
  TRACE_VISIT();

  if ( !theSctx->is_feature_set(feature::ddl) )
  {
    RAISE_ERROR(zerr::ZXQP0050_FEATURE_NOT_AVAILABLE, v.get_location(),
    ERROR_PARAMS("data-definition (ddl)"));
  }

  const QName* qname = v.getName();

  if (!inLibraryModule())
  {
    RAISE_ERROR(zerr::ZDST0023_INDEX_DECL_IN_MAIN_MODULE, loc,
    ERROR_PARAMS(qname->get_qname()));
  }

  // Expand the index qname (error is raised if qname resolution fails).
  store::Item_t qnameItem;
  expand_function_qname(qnameItem, qname, qname->get_location());

  if (qnameItem->getNamespace() != theModuleNamespace)
  {
    RAISE_ERROR(zerr::ZDST0036_INDEX_DECL_IN_FOREIGN_MODULE, loc,
    ERROR_PARAMS(qname->get_qname()));
  }

  IndexDecl_t index = new IndexDecl(theSctx, loc, qnameItem);
  index->setGeneral(false);
  index->setUnique(false);
  index->setMethod(IndexDecl::HASH);
  index->setMaintenanceMode(IndexDecl::MANUAL);

  AnnotationListParsenode* lAnns = v.get_annotations();
  if (lAnns)
  {
    lAnns->accept(*this);
  }

  if (theAnnotations)
  {
    if (ZANN_CONTAINS(zann_general_equality) ||
        ZANN_CONTAINS(zann_general_range))
    {
      index->setGeneral(true);
    }
    if (ZANN_CONTAINS(zann_general_range) ||
        ZANN_CONTAINS(zann_value_range))
    {
      index->setMethod(IndexDecl::TREE);
    }
    if (ZANN_CONTAINS(zann_unique))
    {
      index->setUnique(true);
    }
    if (ZANN_CONTAINS(zann_automatic))
    {
      index->setMaintenanceMode(IndexDecl::REBUILD);
    }
  }

  theAnnotations = NULL;

  theIndexDecl = index;
  theIsInIndexDomain = true;

  return no_state;
}

void end_visit(const AST_IndexDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  IndexDecl_t index = theIndexDecl;
  theIndexDecl = NULL;

  index->analyze();

  // Register the index in the sctx of the current module. Raise error if such
  // a binding exists already in the sctx.
  theSctx->bind_index(index, loc);

  // If this is a library module, register the index in the exported sctx as well.
  if (export_sctx != NULL)
    export_sctx->bind_index(index, loc);
}


/***************************************************************************//**
  IndexKeyList ::= IndexKeySpec (COMMA IndexKeySpec)*
********************************************************************************/
void* begin_visit(const IndexKeyList& v)
{
  TRACE_VISIT();

  theIsInIndexDomain = false;

  IndexDecl* index = theIndexDecl;

  expr_t domainExpr = pop_nodestack();

  if (!domainExpr->is_simple())
  {
    RAISE_ERROR(zerr::ZDST0033_INDEX_NON_SIMPLE_EXPR, domainExpr->get_loc(),
    ERROR_PARAMS(index->getName()->getStringValue()));
  }

  domainExpr = wrap_in_type_match(domainExpr,
                                  theRTM.ANY_NODE_TYPE_STAR,
                                  loc,
                                  zerr::ZDTY0010_INDEX_DOMAIN_TYPE_ERROR);

  // For general indexes, the domain expression must not return duplicate nodes.
  // To see why, consider the following examples:
  //
  // for $book in collection("books")
  // where $book//price > 10
  // return $book
  //
  // An index to optimize the above query would have collection("books") as
  // its domain expr, and .//price as its key expr. In this case, the donaim
  // expr does not return duplicate nodes, but if books are allowed to have
  // multiple  prices, then probing the index for, say prices > 10, may return
  // a book B multiple times, if B has more than one price that is > 10. So,
  // to get the same result as with no index use, the probe function must do
  // duplicate elimination.
  //
  // Now, consider the following query:
  //
  // let $xBook := <book>....</book>
  // for $book in ($xBook, $xBook, $xBook)
  // where $book//price > 10
  // return $book
  //
  // If $xBook has a price > 10, the result of this query will be $xBook 3
  // times. If we were using an index for this query, and the probe does
  // duplicate as required by the previous example, we would get $xBook only
  // once.
  //
  // So, to decide whether the probe function should do duplicate elimination
  // or not, we must be able to distinguish between the above 2 cases. This
  // is not easy/possible, so we decide to err in favor of the first example
  // and not allow the domain expr to return duplicate nodes.
  if (index->isGeneral())
  {
    domainExpr = new fo_expr(theRootSctx,
                             domainExpr->get_loc(),
                             GET_BUILTIN_FUNCTION(OP_CHECK_DISTINCT_NODES_1),
                             domainExpr);
  }

  std::string msg = "Domain expr for index " + index->getName()->getStringValue().str();

  if (theCCB->theConfig.translate_cb != NULL)
    theCCB->theConfig.translate_cb(domainExpr.getp(), msg);

  // Optimize the domain expr. We do this even if the optimizer is off.
  // if (theCCB->theConfig.opt_level == CompilerCB::config::O1)
  {
    RewriterContext rCtx(theCCB, domainExpr, NULL, msg, false);
    GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rCtx);
    domainExpr = rCtx.getRoot();

    if (theCCB->theConfig.optimize_cb != NULL)
      theCCB->theConfig.optimize_cb(&*domainExpr, msg);
  }

  index->setDomainExpr(domainExpr);

  push_scope();

  index->setDomainVariable(bind_var(loc, DOT_VARNAME, var_expr::for_var));

  index->setDomainPositionVariable(bind_var(loc,
                                            DOT_POS_VARNAME,
                                            var_expr::pos_var));

  return no_state;
}

void end_visit(const IndexKeyList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  TypeManager* tm = CTX_TM;

  ulong numColumns = v.size();

  std::vector<expr_t> keyExprs(numColumns);
  std::vector<xqtref_t> keyTypes(numColumns);
  std::vector<OrderModifier> keyModifiers(numColumns);

  IndexDecl* index = theIndexDecl;

  for (long i = numColumns - 1; i >= 0; --i)
  {
    const IndexKeySpec* keySpec = v.getKeySpec(i);
    const OrderCollationSpec* collationSpec = keySpec->getCollationSpec();

    const QueryLoc& kloc = keySpec->get_location();

    expr_t keyExpr = pop_nodestack();

    if (!keyExpr->is_simple())
    {
      RAISE_ERROR(zerr::ZDST0033_INDEX_NON_SIMPLE_EXPR, keyExpr->get_loc(),
      ERROR_PARAMS(index->getName()->getStringValue()));
    }

    keyExpr = wrap_in_atomization(keyExpr);

    xqtref_t type;
    xqtref_t ptype;

    if (keySpec->getType() == NULL)
    {
      if (!index->isGeneral())
      {
        RAISE_ERROR(zerr::ZDST0027_INDEX_BAD_KEY_TYPE, kloc,
        ERROR_PARAMS(index->getName()->getStringValue()));
      }
    }
    else
    {
      type = pop_tstack();
      ptype = TypeOps::prime_type(tm, *type);
      TypeConstants::quantifier_t quant = type->get_quantifier();

      if (!TypeOps::is_subtype(tm, *ptype, *theRTM.ANY_ATOMIC_TYPE_STAR, kloc))
      {
        RAISE_ERROR(zerr::ZDST0027_INDEX_BAD_KEY_TYPE, kloc,
        ERROR_PARAMS(index->getName()->getStringValue()));
      }

      if (!index->isGeneral() &&
          (TypeOps::is_equal(tm, *ptype, *theRTM.ANY_ATOMIC_TYPE_ONE, kloc) ||
           TypeOps::is_equal(tm, *ptype, *theRTM.UNTYPED_ATOMIC_TYPE_ONE, kloc)))
      {
        RAISE_ERROR(zerr::ZDST0027_INDEX_BAD_KEY_TYPE, kloc,
        ERROR_PARAMS(index->getName()->getStringValue()));
      }

      if (!index->isGeneral() &&
          quant != TypeConstants::QUANT_ONE &&
          quant != TypeConstants::QUANT_QUESTION)
      {
        RAISE_ERROR(zerr::ZDST0027_INDEX_BAD_KEY_TYPE, kloc,
        ERROR_PARAMS(index->getName()->getStringValue()));
      }

      if (index->getMethod() == IndexDecl::TREE &&
          (TypeOps::is_subtype(tm, *ptype, *theRTM.UNTYPED_ATOMIC_TYPE_ONE, kloc) ||
           TypeOps::is_subtype(tm, *ptype, *theRTM.QNAME_TYPE_ONE, kloc) ||
           TypeOps::is_subtype(tm, *ptype, *theRTM.NOTATION_TYPE_ONE, kloc) ||
           TypeOps::is_subtype(tm, *ptype, *theRTM.BASE64BINARY_TYPE_ONE, kloc) ||
           TypeOps::is_subtype(tm, *ptype, *theRTM.HEXBINARY_TYPE_ONE, kloc) ||
           TypeOps::is_subtype(tm, *ptype, *theRTM.GYEAR_MONTH_TYPE_ONE, kloc) ||
           TypeOps::is_subtype(tm, *ptype, *theRTM.GYEAR_TYPE_ONE, kloc) ||
           TypeOps::is_subtype(tm, *ptype, *theRTM.GMONTH_TYPE_ONE, kloc) ||
           TypeOps::is_subtype(tm, *ptype, *theRTM.GMONTH_DAY_TYPE_ONE, kloc) ||
           TypeOps::is_subtype(tm, *ptype, *theRTM.GDAY_TYPE_ONE, kloc)))
      {
        RAISE_ERROR(zerr::ZDST0027_INDEX_BAD_KEY_TYPE, kloc,
        ERROR_PARAMS(index->getName()->getStringValue()));
      }

      keyExpr = wrap_in_type_match(keyExpr,
                                   type,
                                   loc,
                                   zerr::ZDTY0011_INDEX_KEY_TYPE_ERROR);

      keyTypes[i] = ptype->getBaseBuiltinType();
    }

    if (index->isGeneral())
    {
      // Eliminate duplicate key values, as they don't play any role in a
      // general comparison predicate.
      keyExpr = new fo_expr(theRootSctx,
                            keyExpr->get_loc(),
                            GET_BUILTIN_FUNCTION(FN_DISTINCT_VALUES_1),
                            keyExpr);
    }

    std::string collationUri;

    if (collationSpec != NULL)
    {
      collationUri = collationSpec->get_uri().str();

      if (! theSctx->is_known_collation(collationUri))
        RAISE_ERROR(err::XQST0076, kloc,
        ERROR_PARAMS(collationUri));
    }
    else if (ptype != NULL &&
             TypeOps::is_subtype(tm, *ptype, *theRTM.STRING_TYPE_ONE, loc))
    {
      collationUri = theSctx->get_default_collation(loc);
    }

    keyModifiers[i].theAscending = true;
    keyModifiers[i].theEmptyLeast = true;
    keyModifiers[i].theCollation = collationUri;

    std::ostringstream msg;
    msg << "key expr " << i << " for index " << index->getName()->getStringValue();

    if (theCCB->theConfig.translate_cb != NULL)
      theCCB->theConfig.translate_cb(keyExpr.getp(), msg.str());

    // Optimize the key expr. We do this even if the optimizer is off.
    // if (theCCB->theConfig.opt_level == CompilerCB::config::O1)
    {
      RewriterContext rCtx(theCCB, keyExpr, NULL, msg.str(), false);
      GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rCtx);
      keyExpr = rCtx.getRoot();

      if (theCCB->theConfig.optimize_cb != NULL)
        theCCB->theConfig.optimize_cb(&*keyExpr, msg.str());
    }

    keyExprs[i] = keyExpr;
  }

  index->setKeyExpressions(keyExprs);
  index->setKeyTypes(keyTypes);
  index->setOrderModifiers(keyModifiers);

  pop_scope();
}


/***************************************************************************//**
  IndexKeySpec ::= PathExpr TypeDeclaration? ("collation" UriLiteral)?
********************************************************************************/
void* begin_visit(const IndexKeySpec& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const IndexKeySpec& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/***************************************************************************//**
  IntegrityConstraintDecl ::= "declare" "integrity" "constraint"
      QName ICType
  ICType ::= ICCollSimpleCheck | ICCollUniqueKey | ICCollForeachNode |
             ICNodeOfType | ICForeighKey
  ICCollSimpleCheck ::= "on" "collection" QName "$" QName "check" ExprSimple
  ICCollUniqueKey   ::= "on" "collection" QNAME "$" QName "check" "unique"
                        "key" "(" Expr ")"
  ICCollForeachNode ::= "on" "collection" QNAME "foreach" "node" "$" QName
                        "check" ExprSingle
  ICNodeOfType      ::= "on" "node" QName "of""type" KindTest "check" ExprSingle
  ICForeighKey      ::= "on" "foreign" "key"
                        "from" "collection" QName "node" "$" QName "keys"
                           "(" Expr ")"
                        "to" "collection" QName "node" "$" QName "keys"
                           "(" Expr ")"

  Translation of an integrity constraint declaration involves the creation and
  setting-up of a IndexDecl obj (see indexing/value_index.h) and the creation
  in the current sctx (which is the root sctx of the current module) of a
  binding between the index uri and this IndexDecl obj.
*******************************************************************************/
void* begin_visit(const IntegrityConstraintDecl& v)
{
  TRACE_VISIT();

  if ( !theSctx->is_feature_set(feature::ddl) )
  {
    throw XQUERY_EXCEPTION(
      zerr::ZXQP0050_FEATURE_NOT_AVAILABLE,
      ERROR_PARAMS( "data-definition (ddl)" ),
      ERROR_LOC( v.get_location() )
    );
  }

  if (!inLibraryModule())
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDST0044_IC_DECL_IN_MAIN_MODULE,
      ERROR_PARAMS( v.getName()->get_qname() ),
      ERROR_LOC( loc )
    );
  }

  push_scope();

  switch( v.getICKind() )
  {
  case IntegrityConstraintDecl::coll_check_simple:
  {
    const ICCollSimpleCheck& ic = dynamic_cast<const ICCollSimpleCheck&>(v);
    /**********************
       declare integrity constraint example:ic1
         on collection example:coll1 $x check sum($x/size) le 1000;

       sum( dc:collection(example:coll1)/size ) le 1000

       let $x := dc:collection(xs:QName("example:coll1"))
       return sum($x/size) le 1000;
    **********************/

    // "example:coll1"
    expr_t qnameStrExpr = new const_expr(theRootSctx, loc,
                                         ic.getCollName()->get_qname().str());

    zstring prefixStr = ic.getCollName()->get_prefix();
    zstring uriStr;
    theSctx->lookup_ns(uriStr, prefixStr, loc);

    expr_t uriStrExpr = new const_expr(theRootSctx, loc, uriStr);

    // fn:QName("uri", "example:coll1")
    fo_expr_t qnameExpr = new fo_expr(theRootSctx, loc,
                                      GET_BUILTIN_FUNCTION(FN_QNAME_2),
                                      uriStrExpr, qnameStrExpr);

    // dc:collection(xs:QName("example:coll1"))
    function* fn_collection = GET_BUILTIN_FUNCTION(ZORBA_STORE_COLLECTIONS_STATIC_DML_COLLECTION_1);
    ZORBA_ASSERT(fn_collection != NULL);
    std::vector<expr_t> argColl;
    argColl.push_back(qnameExpr.getp());
    fo_expr_t collExpr = new fo_expr(theRootSctx, loc, fn_collection, argColl);

    // $x
    const QName* varQName = ic.getCollVarName();
    var_expr_t varExpr = bind_var(loc, varQName, var_expr::let_var, NULL);

    // let $x := dc:collection(xs:QName("example:coll1"))
    let_clause* lc = new let_clause(theRootSctx,
                                    loc,
                                    varExpr,
                                    collExpr.getp());

    flwor_expr_t flworExpr = new flwor_expr(theRootSctx, loc, false);
    flworExpr->add_clause(lc);
    // flworExpr-> return clause to be set in end_visitor

    push_nodestack(flworExpr.getp());
  }
  break;

  case IntegrityConstraintDecl::coll_check_unique_key:
  {
    /**********************
       declare integrity constraint org:icEmployeesIds
         on collection org:employees node $x check unique key $x/@id ;

       let $x := dc:collection( xs:QName("org:employees") )
       return
         (
           every $x_ in $x
           satisfies
             exists( $x_/@id )
         )
         and
         (  functx:are-distinct-values( $x/@id )  )

      implemented as:
       let $x := dc:collection( xs:QName("org:employees") )
       return
         (
           fn:empty(
             for $x_ in dc:collection( xs:QName("org:employees") )
             where not( exists($x_/@id) )
             return true)
         )
         and
         (  count(distinct-values( $x/@id )) = count($x/@id)  )
    **********************/

    const ICCollUniqueKeyCheck& ic =
      dynamic_cast<const ICCollUniqueKeyCheck&>(v);

    // "org:employees"
    expr_t qnameStrExpr = new const_expr(theRootSctx,
                                         loc,
                                         ic.getCollName()->get_qname().str());

    zstring prefixStr = ic.getCollName()->get_prefix();
    zstring uriStr;
    theSctx->lookup_ns(uriStr, prefixStr, loc);

    expr_t uriStrExpr = new const_expr(theRootSctx, loc, uriStr);

    // fn:QName("org-uri", "org:employees")
    fo_expr_t qnameExpr = new fo_expr(theRootSctx, loc,
                                      GET_BUILTIN_FUNCTION(FN_QNAME_2),
                                      uriStrExpr, qnameStrExpr);

    // dc:collection(xs:QName("org:employees"))
    function* fn_collection = GET_BUILTIN_FUNCTION(ZORBA_STORE_COLLECTIONS_STATIC_DML_COLLECTION_1);
    ZORBA_ASSERT(fn_collection != NULL);
    std::vector<expr_t> argColl;
    argColl.push_back(qnameExpr.getp());
    fo_expr_t collExpr = new fo_expr(theRootSctx, loc, fn_collection, argColl);

    // $x
    const QName* varQName = ic.getNodeVarName();
    store::Item_t varItem;
    expand_no_default_qname(varItem, varQName, varQName->get_location());

    // every $x_ in $x satisfies exists ...
    // every is implemented as a flowr expr
    push_scope();
    flwor_expr_t evFlworExpr = new flwor_expr(theRootSctx, loc, false);
    evFlworExpr->set_return_expr(new const_expr(theRootSctx, loc, true));

    // $x_ in dc:collection( xs:QName("org:employees") )
    var_expr_t evVarExpr = bind_var(loc,
                                    varItem,
                                    var_expr::for_var,
                                    NULL);

    // maybe make one more collExpr?
    evFlworExpr->add_clause(wrap_in_forclause(collExpr.getp(), evVarExpr, NULL));

    pop_scope();
    // end every

    // let $x := dc:collection(xs:QName("org:employees"))
    //   return
    var_expr_t varExpr = bind_var(loc,
                                  varItem.getp(),
                                  var_expr::let_var,
                                  NULL);

    let_clause* letClause = new let_clause(theRootSctx,
                                           loc,
                                           varExpr,
                                           collExpr.getp());
    flwor_expr_t flworExpr = new flwor_expr(theRootSctx, loc, false);



    flworExpr->add_clause(letClause);
    // flworExpr->set_return_expr( andExpr ); done in end_visit

    // push evFlworExpr because where clause must be set
    push_nodestack(evFlworExpr.getp());
    // push the top expresion
    push_nodestack(flworExpr.getp());
  }
  break;

  case IntegrityConstraintDecl::coll_foreach_node:
  {
    /**********************
       declare integrity constraint org:icTransactionsSale
         on collection org:transactions foreach node $x
           check $x/sale > 0 ;

       every $x in dc:collection( xs:QName("org:transactions") )
       satisfies $x/sale > 0

       implemented as:
         fn:empty(
           for $x in dc:collection( xs:QName("org:transactions") )
           where not( $x/sale > 0 )
           return true )
    **********************/

    const ICCollForeachNode& ic =
      dynamic_cast<const ICCollForeachNode&>(v);

    // "org:transactions"
    expr_t qnameStrExpr = new const_expr(theRootSctx, loc,
                                         ic.getCollName()->get_qname().str());

    zstring prefixStr = ic.getCollName()->get_prefix();
    zstring uriStr;
    theSctx->lookup_ns(uriStr, prefixStr, loc);

    expr_t uriStrExpr = new const_expr(theRootSctx, loc, uriStr);

    // fn:QName("org-uri", "org:transactions")
    fo_expr_t qnameExpr = new fo_expr(theRootSctx, loc,
                                      GET_BUILTIN_FUNCTION(FN_QNAME_2),
                                      uriStrExpr, qnameStrExpr);

    // dc:collection(xs:QName("org:transactions"))
    function* fn_collection = GET_BUILTIN_FUNCTION(ZORBA_STORE_COLLECTIONS_STATIC_DML_COLLECTION_1);
    ZORBA_ASSERT(fn_collection != NULL);
    std::vector<expr_t> argColl;
    argColl.push_back(qnameExpr.getp());
    fo_expr_t collExpr = new fo_expr(theRootSctx, loc, fn_collection, argColl);

    // every $x_ in $x satisfies exists ...
    // every is implemented as a flowr expr
    //push_scope();
    flwor_expr_t evFlworExpr = new flwor_expr(theRootSctx, loc, false);
    evFlworExpr->set_return_expr(new const_expr(theRootSctx, loc, true));

    // $x
    const QName* varQName = ic.getCollVarName();

    // $x_ in dc:collection( xs:QName("org:employees") )
    var_expr_t evVarExpr = bind_var(loc, varQName, var_expr::for_var, NULL);

    // maybe make one more collExpr?
    evFlworExpr->add_clause(wrap_in_forclause(collExpr.getp(),
                                              evVarExpr,
                                              NULL));

    //pop_scope();
    // end every
    push_nodestack(evFlworExpr.getp());
  }
  break;

  case IntegrityConstraintDecl::foreign_key:
  {
    /**********************
       declare integrity constraint org:icEmpSalesForeignKey
         foreign key
           from collection org:transactions node $x key $x//sale/empid
           to   collection org:employees node $y key $y/id

       every $x in dc:collection( xs:QName("org:transactions") )
       satisfies
         some $y in dc:collection( xs:QName("org:employees") )
         satisfies $y/id eq $x//sale/empid

       i.e. using flwor impl:
         fn:empty(
           for $x in dc:collection( xs:QName("org:transactions") )
           where not(
             fn:exists(
               for $y in dc:collection( xs:QName("org:employees") )
               where $y/id eq $x//sale/empid
               return true) )
           return true)
    **********************/

    const ICForeignKey& ic = dynamic_cast<const ICForeignKey&>(v);

    // TO part
    // "org:employees"
    expr_t toQnameStrExpr = new const_expr(theRootSctx, loc,
                                           ic.getToCollName()->get_qname().str());
    zstring toPrefixStr = ic.getToCollName()->get_prefix();
    zstring toUriStr;
    theSctx->lookup_ns(toUriStr, toPrefixStr, loc);

    expr_t toUriStrExpr = new const_expr(theRootSctx, loc, toUriStr);

    // xs:QName("org:employees")
    fo_expr_t toQnameExpr = new fo_expr(theRootSctx, loc,
                                        GET_BUILTIN_FUNCTION(FN_QNAME_2),
                                        toUriStrExpr, toQnameStrExpr);

    // dc:collection(xs:QName("org:employees"))
    function* toFnCollection = GET_BUILTIN_FUNCTION(ZORBA_STORE_COLLECTIONS_STATIC_DML_COLLECTION_1);
    ZORBA_ASSERT(toFnCollection != NULL);
    std::vector<expr_t> toArgColl;
    toArgColl.push_back(toQnameExpr.getp());
    fo_expr_t toCollExpr = new fo_expr(theRootSctx, loc, toFnCollection,
                                       toArgColl);

    // some $y in dc:collection( xs:QName("org:employees") )
    // satisfies ... eq ...
    // implemented using flowr
    flwor_expr_t someFlworExpr = new flwor_expr(theRootSctx, loc, false);
    someFlworExpr->set_return_expr(new const_expr(theRootSctx, loc, true));

    // $y
    const QName* toVarQName = ic.getToNodeVarName();
    var_expr_t toVarExpr = bind_var(loc, toVarQName, var_expr::for_var, NULL);

    // for $y in dc:collection(xs:QName("org:employees"))
    someFlworExpr->add_clause(wrap_in_forclause(toCollExpr.getp(),
                                                toVarExpr,
                                                NULL));


    // FROM part
    // "org:transactions"
    expr_t fromQnameStrExpr = new const_expr(theRootSctx, loc,
                                             ic.getFromCollName()->get_qname().str());

    zstring fromPrefixStr = ic.getFromCollName()->get_prefix();
    zstring fromUriStr;
    theSctx->lookup_ns(fromUriStr, fromPrefixStr, loc);

    expr_t fromUriStrExpr = new const_expr(theRootSctx, loc, fromUriStr);

    // fn:QName("org-uri", "org:transactions")
    fo_expr_t fromQnameExpr = new fo_expr(theRootSctx, loc,
                                          GET_BUILTIN_FUNCTION(FN_QNAME_2),
                                          fromUriStrExpr, fromQnameStrExpr);

    // dc:collection(xs:QName("org:transactions"))
    function* fromFnCollection = GET_BUILTIN_FUNCTION(ZORBA_STORE_COLLECTIONS_STATIC_DML_COLLECTION_1);
    ZORBA_ASSERT(fromFnCollection != NULL);
    std::vector<expr_t> fromArgColl;
    fromArgColl.push_back(fromQnameExpr.getp());
    fo_expr_t fromCollExpr = new fo_expr(theRootSctx,
                                         loc,
                                         fromFnCollection,
                                         fromArgColl);

    // every $x in dc:collection( xs:QName("org:transactions") )
    // satisfies ...
    // implemented using flowr
    flwor_expr_t evFlworExpr = new flwor_expr(theRootSctx, loc, false);
    evFlworExpr->set_return_expr(new const_expr(theRootSctx, loc, true));

    // $x
    const QName* fromVarQName = ic.getFromNodeVarName();
    var_expr_t fromVarExpr = bind_var(loc, fromVarQName, var_expr::for_var, NULL);

    // for $x in dc:collection(xs:QName("org:transactions"))
    evFlworExpr->add_clause(wrap_in_forclause(fromCollExpr.getp(),
                                              fromVarExpr, NULL));


    push_nodestack(someFlworExpr.getp());
    push_nodestack(evFlworExpr.getp());
  }
  break;

  default:
    ZORBA_ASSERT(false);
  }

  return no_state;
}


void end_visit(const IntegrityConstraintDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  //fill in the body of the function
  expr_t body;
  const QName* qname = v.getName();

  // todo cezar: error if user expresions are sequential

  // for each type of IC a different check Expr is constructed
  switch( v.getICKind() )
  {
  case IntegrityConstraintDecl::coll_check_simple:
    {
      //const ICCollSimpleCheck ic = dynamic_cast<const ICCollSimpleCheck&>(v);

      expr_t icExpr = pop_nodestack();

      flwor_expr_t flworExpr =
        dynamic_cast<flwor_expr*>(pop_nodestack().getp());

      // let ... return ...
      flworExpr->set_return_expr( wrap_in_atomization(icExpr.getp()) );

      body = flworExpr;
    }
    break;

  case IntegrityConstraintDecl::coll_check_unique_key:
    {
      /**********************
       declare integrity constraint org:icEmployeesIds
         on collection org:employees node $x check unique key $x/@id ;

       let $x := dc:collection( xs:QName("org:employees") )
       return
         (
           every $x_ in $x
           satisfies
             exists( $x_/@id )
         )
         and
         (  functx:are-distinct-values( $x/@id )  )

      implemented as:
       let $x := dc:collection( xs:QName("org:employees") )
       return
         (
           fn:empty(
             for $x_ in dc:collection( xs:QName("org:employees") )
             where not( exists($x_/@id) )
             return true)
         )
         and
         (  count(distinct-values( $x/@id )) = count($x/@id)  )
      **********************/

      //////  Get data from stack
      // $x/@id
      expr_t uniKeyExpr = pop_nodestack();

      // flwor result expr
      flwor_expr_t flworExpr =
        dynamic_cast<flwor_expr*>(pop_nodestack().getp());

      // flwor implementing every
      flwor_expr_t evFlworExpr =
        dynamic_cast<flwor_expr*>(pop_nodestack().getp());


      ////// Set latest details

      //fn:data( userExpr )
      expr_t atomizedUniKeyExpr = wrap_in_atomization(uniKeyExpr.getp());

      // exists( $x/@id )
      expr_t existsExpr = new fo_expr(theRootSctx, loc,
                                      GET_BUILTIN_FUNCTION(FN_EXISTS_1),
                                      uniKeyExpr.getp());

#if 0
      zstring commentStr("#trace fnExists");
      expr_t comentExpr = new const_expr(theRootSctx, loc, commentStr);
      fo_expr_t fnTraceExpr = new fo_expr(theRootSctx,
                                         loc,
                                         GET_BUILTIN_FUNCTION(FN_TRACE_2),
                                         existsExpr.getp(), comentExpr.getp());
#endif


      // every ... satisfies evTestExpr
      fo_expr_t fnNotExpr = new fo_expr(theRootSctx,
                                        loc,
                                        GET_BUILTIN_FUNCTION(FN_NOT_1),
                                        existsExpr);

      evFlworExpr->add_where(fnNotExpr.getp());

      fo_expr_t everyExpr = new fo_expr(theRootSctx,
                                        loc,
                                        GET_BUILTIN_FUNCTION(FN_EMPTY_1),
                                        evFlworExpr.getp());

      // functx:are-distinct-values( $x/@id )
      // implemented as count(distinct-values($seq)) = count($seq)
      //distinct-values($seq)
      fo_expr_t distinctValuesExpr = new fo_expr(theRootSctx, loc,
                                 GET_BUILTIN_FUNCTION(FN_DISTINCT_VALUES_1),
                                                 atomizedUniKeyExpr.getp());

      // count($sec)
      fo_expr_t countSecExpr = new fo_expr(theRootSctx, loc,
                                           GET_BUILTIN_FUNCTION(FN_COUNT_1),
                                           atomizedUniKeyExpr.getp());
      // count(distinct-values($sec))
      fo_expr_t countDVExpr = new fo_expr(theRootSctx, loc,
                                          GET_BUILTIN_FUNCTION(FN_COUNT_1),
                                          distinctValuesExpr.getp());

      // countDV = countSec
      fo_expr_t equalExpr = new fo_expr(theRootSctx, loc,
                                        GET_BUILTIN_FUNCTION(OP_EQUAL_2),
                                        countDVExpr.getp(), countSecExpr.getp());
      // (...) and (...)
      fo_expr_t andExpr = new fo_expr(theRootSctx, loc,
                                      GET_BUILTIN_FUNCTION(OP_AND_N),
                                      everyExpr.getp(), equalExpr.getp());

      flworExpr->set_return_expr(andExpr.getp());

      body = flworExpr;
    }
    break;

  case IntegrityConstraintDecl::coll_foreach_node:
    {
      /**********************
       declare integrity constraint org:icTransactionsSale
         on collection org:transactions foreach node $x
           check $x/sale gt 0 ;

       every $x in dc:collection( xs:QName("org:transactions") )
       satisfies $x/sale gt 0

       implemented as:
         fn:empty(
           for $x in dc:collection( xs:QName("org:transactions") )
           where not( $x/sale gt 0 )
           return true )
       **********************/

      //////  Get data from stack
      // $x/sale gt 0
      expr_t evTestExpr = wrap_in_atomization(pop_nodestack());

      // flwor expr
      flwor_expr_t evFlworExpr =
        dynamic_cast<flwor_expr*>(pop_nodestack().getp());

      // fn:not
      fo_expr_t fnNotExpr = new fo_expr(theRootSctx,
                                        loc,
                                        GET_BUILTIN_FUNCTION(FN_NOT_1),
                                        evTestExpr.getp());

      // where not( exists($x/sale gt 0) )
      evFlworExpr->add_where(fnNotExpr.getp());

      // fn:empty
      fo_expr_t emptyExpr = new fo_expr(theRootSctx,
                                        loc,
                                        GET_BUILTIN_FUNCTION(FN_EMPTY_1),
                                        evFlworExpr.getp());

      body = emptyExpr;
    }
    break;

  case IntegrityConstraintDecl::foreign_key:
    {
      //////  Get data from stack
      // $y/id
      expr_t toKeyExpr = wrap_in_atomization(pop_nodestack());

      // $x//sale/empid
      expr_t fromKeyExpr = wrap_in_atomization(pop_nodestack());

      // result expr
      flwor_expr_t evFlworExpr = dynamic_cast<flwor_expr*>(pop_nodestack().getp());

      // some flwor expr
      flwor_expr_t someFlworExpr = dynamic_cast<flwor_expr*>(pop_nodestack().getp());


      // maybe add fn:data ?
      // $y/id eq $x//sale/empid
      fo_expr_t eqExpr = new fo_expr(theRootSctx,
                                     loc,
                                     GET_BUILTIN_FUNCTION(OP_VALUE_EQUAL_2),
                                     toKeyExpr.getp(),
                                     fromKeyExpr.getp());
      normalize_fo(eqExpr);

      expr_t someTestExpr = eqExpr.getp();
      someTestExpr = wrap_in_bev(someTestExpr.getp());
      someFlworExpr->add_where(someTestExpr.getp());

      // fn:exists
      fo_expr_t fnExistsExpr = new fo_expr(theRootSctx, loc,
                                           GET_BUILTIN_FUNCTION(FN_EXISTS_1),
                                           someFlworExpr.getp());
      // fn:not()
      fo_expr_t evFnNotExpr = new fo_expr(theRootSctx,
                                          loc,
                                          GET_BUILTIN_FUNCTION(FN_NOT_1),
                                          fnExistsExpr.getp());

      evFlworExpr->add_where(evFnNotExpr.getp());

      // fn:empty
      fo_expr_t fnEmptyExpr = new fo_expr(theRootSctx,
                                        loc,
                                        GET_BUILTIN_FUNCTION(FN_EMPTY_1),
                                        evFlworExpr.getp());


      body = fnEmptyExpr;
    }
    break;

  default:
    ZORBA_ASSERT(false);
  }

  pop_scope();


  zstring msg = "entry-creator expr for integrity constraint " +
    qname->get_localname();

  if (theCCB->theConfig.optimize_cb != NULL)
    theCCB->theConfig.optimize_cb(body.getp(), msg.str());

  ulong nextVarId = 1;
  PlanIter_t icIter = codegen("integrity constraint", body, theCCB, nextVarId);

  // Update static context
  store::Item_t qnameItem;
  expand_function_qname(qnameItem, qname, qname->get_location());

  if (qnameItem->getNamespace() != theModuleNamespace)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDST0048_IC_DECL_IN_FOREIGN_MODULE,
      ERROR_PARAMS( qname->get_qname() ),
      ERROR_LOC( loc )
    );
  }

  ValueIC_t vic;
  if ( v.getICKind() == IntegrityConstraintDecl::foreign_key )
  {
    const ICForeignKey& ic = dynamic_cast<const ICForeignKey&>(v);

    const QName* fromQname = ic.getFromCollName();

    store::Item_t fromQnameItem;
    expand_function_qname(fromQnameItem, fromQname, fromQname->get_location());

    const QName* toQname = ic.getToCollName();

    store::Item_t toQnameItem;
    expand_function_qname(toQnameItem, toQname, toQname->get_location());

    vic = new ValueIC(theSctx, qnameItem, fromQnameItem, toQnameItem,
                      icIter, theCCB);
  }
  else
  {
    const ICColl* ic = dynamic_cast<const ICColl*>(&v);

    const QName* collQname = ic->getCollName();
    store::Item_t collQnameItem;
    expand_function_qname(collQnameItem, collQname, collQname->get_location());

    vic = new ValueIC(theSctx, qnameItem, collQnameItem, icIter, theCCB);
  }

  theSctx->bind_ic(vic, loc);

  // if this is a library module, register in exported module as well
  if (export_sctx != NULL)
    export_sctx->bind_ic(vic, loc);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  QueryBody,                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  QueryBody ::= StatementsAndOptionalExpr

  StatementsAndOptionalExpr ::= StatementsAndExpr | Statements?

  StatementsAndExpr := Statements? Expr

  Statements ::= Statement+

  Expr ::=  ExprSingle ("," ExprSingle)*
********************************************************************************/
void* begin_visit(const QueryBody& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const QueryBody& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t program = pop_nodestack();

  // Mark the program as non-sequential if the only reason it is marked sequential
  // is because it contains exit exprs.
  program->set_not_exiting();

  if (program->is_updating())
  {
    theModulesInfo->theCCB->setIsUpdating(true);
  }

  if(program->is_sequential())
  {
    theModulesInfo->theCCB->setIsSequential(true);
  }

  if (program->is_updating() && !theCCB->theIsEval)
  {
    program = new apply_expr(theRootSctx,
                             program->get_loc(),
                             program,
                             false); // don't discard XDM
  }

  push_nodestack(program);
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Scripting Extensions                                                      //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

  QueryBody ::= StatementsAndOptionalExpr

  StatementsAndOptionalExpr ::= StatementsAndExpr | Statements?

  StatementsAndExpr := Statements? Expr

  Statements ::= Statement+

  Statement ::= BlockStatement |
                VarDeclStatement |
                AssignStatement |
                ApplyStatement |
                ExitStatement |
                WhileExpr |
                FlowCtlStatement |

                FLWORStatement |
                IfStatement |
                TypeswitchStatement |
                SwitchStatement |
                TryStatement

  Expr ::=  ExprSingle ("," ExprSingle)*

  Note: In the StatementsAndOptionalExpr, StatementsAndExpr, and Statements rules,
  if any statements are actually present, the parser generates a subtree rooted
  at a BockBody parsenode. A single BlockBody parsenode (with no children) is
  also generated if there are no statements and no Expr either.

********************************************************************************/


/*******************************************************************************
  A BlockBody parse node is generated as the result of the following grammar
  rules:

  1. StatementsAndOptionalExpr ::= StatementsAndExpr | Statements?
     If any statements are actually present or if neither statements nor an
     expr are present.

  2. StatementsAndExpr := Statements? Expr
     If any statements are actually present.

  3. Statements ::= Statement+

  4. EnclosedStatementsAndOptionalExpr ::= "{" StatementsAndOptionalExpr "}"

  5. BlockStatement ::= "{" Statements "}"

  6. BlockExpr ::= "{" StatementsAndOptionalExpr "}

********************************************************************************/
void* begin_visit(const BlockBody& v)
{
  TRACE_VISIT();

  if (v.size() == 0)
  {
    push_nodestack(create_empty_seq(loc));
    return NULL;
  }

  if ( !theSctx->is_feature_set(feature::scripting) )
  {
    throw XQUERY_EXCEPTION(
      err::XPST0003,
      ERROR_LOC( v.get_location() )
    );
  }

  bool topLevel = v.isTopLevel();
  bool inEval = theCCB->theIsEval;
  bool allowLastUpdating = false;

  std::vector<expr_t> stmts;

  // push a dummy block_expr in the node stack so that local var decls can
  // assert that their parent is a block expr.
  expr_t dummyBlock = new block_expr(theRootSctx, loc, false, stmts, NULL);
  push_nodestack(dummyBlock);

  push_scope();

  ulong numScopes = theAssignedVars.size();

  theAssignedVars.resize(numScopes + 1);

  ulong numExprs = v.size();
  bool declaresVars = false;

  for (ulong i = 0; i < numExprs; ++i)
  {
    v[i]->accept(*this);

    if (dynamic_cast<const VarDecl*>(v[i]) != NULL)
    {
      expr_t val = pop_nodestack();
      var_expr_t ve = pop_nodestack().cast<var_expr>();

      GlobalBinding b(ve, val, false);

      declare_var(b, stmts);

      declaresVars = true;
    }
    else
    {
      expr_t childExpr = pop_nodestack();

      // If the last child is an updating expr
      if (topLevel && i == numExprs - 1 && childExpr->is_updating())
      {
        if (inEval)
        {
          allowLastUpdating = true;
        }
        else
        {
          childExpr = new apply_expr(theRootSctx, loc, childExpr, false);
        }
      }

      stmts.push_back(childExpr);
    }
  }

  // pop the dummy block expr from the stack.
  dummyBlock = pop_nodestack();
  assert(dummyBlock->get_expr_kind() == block_expr_kind);

  // Flatten-out a block expr if it has only one child and that child is
  // not a var decl expr.
  if (stmts.size() == 1 && !declaresVars)
  {
    push_nodestack(stmts[0]);

    theAssignedVars.pop_back();
    pop_scope();

    return NULL;
  }

  // Create the block expr
  std::vector<var_expr*>& prevAssignedVars = theAssignedVars[numScopes-1];
  std::vector<var_expr*>& lastAssignedVars = theAssignedVars[numScopes];

  expr_t blockExpr = new block_expr(theRootSctx,
                                    loc,
                                    allowLastUpdating,
                                    stmts,
                                    &lastAssignedVars);

  push_nodestack(blockExpr);

  prevAssignedVars.insert(prevAssignedVars.end(),
                          lastAssignedVars.begin(),
                          lastAssignedVars.end());

  theAssignedVars.pop_back();
  pop_scope();

  return NULL;
}


void end_visit(const BlockBody& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  VarDeclStatement ::= ("local" Annotation*)? "variable"
                       "$" VarName TypeDeclaration? (":=" ExprSingle)?
                       ("," "$" VarName TypeDeclaration? (":=" ExprSingle)?)* ";"

  Note: the initializing ExprSingle of each var decl must be non-updating.

  Note: Each individual var decl in a VarDeclStatement is parsed into a VarDecl
  parsenode.

  Note: The parser makes sure that if a VarDeclStatement does not appear as a
  direct child of a BlockBody, it is wrapped by a BlockBody. Furthermore, the
  parser will flatten-out the VarDeclStatement parsenode by placing its children
  as direct children of the enclosing BlockBody. As a result, VarDeclStatement
  parsenodes do not appear at all in the final AST.
********************************************************************************/


/*******************************************************************************
  AssignStatement ::= "$" VarName ":=" ExprSingle ";"

  Note: the ExprSingle must be non-updating.
********************************************************************************/
void* begin_visit(const AssignExpr& v)
{
  TRACE_VISIT();

  if ( !theSctx->is_feature_set(feature::scripting) )
  {
    throw XQUERY_EXCEPTION(
      err::XPST0003,
      ERROR_LOC( v.get_location() )
    );
  }
  return no_state;
}

void end_visit(const AssignExpr& v, void* visit_state)
{
  TRACE_VISIT_OUT();

  var_expr_t ve = lookup_var(v.get_name(), loc, err::XPST0008);

  if ((ve->get_kind() != var_expr::local_var &&
       ve->get_kind() != var_expr::prolog_var) ||
      !ve->is_mutable())
  {
    RAISE_ERROR(zerr::XSST0007, loc,
    ERROR_PARAMS(ve->get_name()->getStringValue()));
  }

  xqtref_t varType = ve->get_type();

  expr_t valueExpr = pop_nodestack();

  if (varType != NULL)
    valueExpr = new treat_expr(theRootSctx, loc, valueExpr, varType, err::XPTY0004);

  push_nodestack(new var_set_expr(theRootSctx, loc, ve, valueExpr));

  theAssignedVars.back().push_back(ve.getp());
}


/*******************************************************************************
  ApplyStatement ::= ExprSingle ";"
********************************************************************************/
void* begin_visit(const ApplyExpr& v)
{
  TRACE_VISIT();

  return no_state;
}

void end_visit(const ApplyExpr& v, void* visit_state)
{
  expr_t param = pop_nodestack();

  push_nodestack(new apply_expr(theRootSctx,
                                param->get_loc(),
                                param,
                                true)); // discard XDM

  TRACE_VISIT_OUT();
}


/*******************************************************************************

********************************************************************************/
void* begin_visit(const ExitExpr& v)
{
  TRACE_VISIT();

  return no_state;
}


void end_visit(const ExitExpr& v, void* visit_state)
{
  TRACE_VISIT_OUT();

  expr_t childExpr = pop_nodestack();

  if (childExpr->is_updating())
  {
    theHaveUpdatingExitExprs = true;

    if (!inUDFBody() && !theCCB->theIsEval)
    {
      childExpr = new apply_expr(theRootSctx, loc, childExpr, false);
    }
  }
  else if (childExpr->is_sequential())
  {
    theHaveSequentialExitExprs = true;
  }

  if (inUDFBody())
  {
    function* f = const_cast<function*>(theCurrentPrologVFDecl.getFunction());
    assert(f->isUdf());
    user_function* udf = static_cast<user_function*>(f);

    udf->setExiting(true);
  }

  push_nodestack(new exit_expr(theRootSctx, loc, childExpr));
}


/*******************************************************************************
  WhileExpr ::= "while" "(" Expr ")" Statement
********************************************************************************/
void* begin_visit(const WhileExpr& v)
{
  TRACE_VISIT();

  theInWhileStack.push(true);

  return no_state;
}


void end_visit(const WhileExpr& v, void* visit_state)
{
  TRACE_VISIT_OUT();

  expr_t bodyExpr = pop_nodestack();
  expr_t condExpr = pop_nodestack();

  condExpr = new if_expr(theRootSctx,
                         loc,
                         condExpr,
                         create_empty_seq(loc),
                         new flowctl_expr(theRootSctx, loc, flowctl_expr::BREAK));

  block_expr* seqBody = NULL;

  std::vector<expr_t> stmts;

  stmts.push_back(condExpr);
  stmts.push_back(bodyExpr);

  seqBody = new block_expr(bodyExpr->get_sctx(), loc, false, stmts, NULL);

  push_nodestack(new while_expr(theRootSctx, loc, seqBody));

  theInWhileStack.pop();
}


/*******************************************************************************

********************************************************************************/
void* begin_visit(const FlowCtlStatement& v)
{
  TRACE_VISIT();

  return no_state;
}

void end_visit(const FlowCtlStatement& v, void* visit_state)
{
  TRACE_VISIT_OUT();

  enum flowctl_expr::action a;

  switch (v.get_action())
  {
  case FlowCtlStatement::BREAK:
  {
    if (theInWhileStack.empty())
    {
      RAISE_ERROR_NO_PARAMS(zerr::XSST0009, loc);
    }
    a = flowctl_expr::BREAK;
    break;
  }
  case FlowCtlStatement::CONTINUE:
  {
    if (theInWhileStack.empty())
    {
      RAISE_ERROR_NO_PARAMS(zerr::XSST0010, loc);
    }
    a = flowctl_expr::CONTINUE;
    break;
  }
  default:
    ZORBA_FATAL(false, "");
  }

  push_nodestack(new flowctl_expr(theRootSctx, loc, a));
}



/*******************************************************************************
  Expr ::=  ExprSingle ("," ExprSingle)*

  If there is only one ExprSingle, no Expr parsenode is generated. Otherwise, an
  Expr parsenode is generated, whose children are the ExprSingles.
********************************************************************************/
void* begin_visit(const Expr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const Expr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  assert(v.numberOfChildren() > 1);

  std::vector<expr_t> args;

  for (int i = 0; i < v.numberOfChildren(); ++i)
  {
    expr_t e = pop_nodestack();
    args.push_back(e);
  }

  fo_expr_t concatExpr = new fo_expr(theRootSctx,
                                     loc,
                                     op_concatenate,
                                     args);
  normalize_fo(concatExpr.getp());

  push_nodestack(concatExpr.getp());
}


/*******************************************************************************

  ExprSingle ::= ExprSimple |
                 FLWORExpr  |
                 SwitchExpr |
                 TypeswitchExpr |
                 IfExpr |
                 TryCatchExpr

  ExprSimple ::= QuantifiedExpr |
                 OrExpr |

                 InsertExpr |
                 DeleteExpr |
                 RenameExpr |
                 ReplaceExpr |
                 TransformExpr

********************************************************************************/



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  FLWOR                                                                      //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************

  FLWORExpr ::= InitialClause FLWORClauseList? ReturnClause

  - For the Generalized FLWOR:

  InitialClause ::= ForClause | LetClause | WindowClause

  FLWORClauseList ::= FLWORClause*

  FLWORClause ::= ForClause |
                  LetClause |
                  WindowClause |
                  WhereClause |
                  GroupByClause |
                  OrderByClause |
                  CountClause

  - For the traditional FLWOR:

  InitialClause ::= ForClause | LetClause

  FLWORClauseList ::= (ForClause | LetClause)*
                      WhereCluase?
                      GroupByClause?
                      OrderByClause?

********************************************************************************/
void* begin_visit(const FLWORExpr& v)
{
  TRACE_VISIT();

  theFlworClausesStack.push_back(NULL);

  return no_state;
}


void end_visit(const FLWORExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  if (theSctx->xquery_version() <= StaticContextConsts::xquery_version_1_0 &&
      v.is_non_10())
  {
    RAISE_ERROR(err::XPST0003, loc,
    ERROR_PARAMS(ZED(XQueryVersionAtLeast10_2), theSctx->xquery_version()));
  }

  rchandle<flwor_expr> flwor = new flwor_expr(theRootSctx, loc, v.is_general());

  expr_t retExpr = pop_nodestack();

  wrap_in_debugger_expr(retExpr, retExpr->get_loc());

  flwor->set_return_expr(retExpr);

  ulong curClausePos = (ulong)theFlworClausesStack.size() - 1;

  while (theFlworClausesStack[curClausePos] != NULL)
  {
    flwor_clause* curClause = theFlworClausesStack[curClausePos];

    switch (curClause->get_kind())
    {
    case flwor_clause::for_clause:
    case flwor_clause::let_clause:
    {
      pop_scope();
      break;
    }
    case flwor_clause::window_clause:
    {
      // window var + output window condition vars
      pop_scope();
      pop_scope();
      break;
    }
    case flwor_clause::group_clause:
    {
      group_clause* gc = static_cast<group_clause*>(curClause);

      ulong numGVars = gc->getNumGroupingVars();
      ulong numNGVars = gc->getNumNonGroupingVars();

      for (ulong i = 0; i < numGVars; ++i)
        pop_scope();

      for (ulong i = 0; i < numNGVars; ++i)
        pop_scope();

      break;
    }
    case flwor_clause::order_clause:
    case flwor_clause::where_clause:
    case flwor_clause::count_clause:
    {
      break;
    }
    default:
      ZORBA_ASSERT(false);
    }

    --curClausePos;
  }

  ulong numClauses = (ulong)theFlworClausesStack.size();

  for (ulong i = curClausePos + 1; i < numClauses; ++i)
    flwor->add_clause(theFlworClausesStack[i]);

  theFlworClausesStack.resize(curClausePos);

  push_nodestack(flwor.getp());
}


/*******************************************************************************
  - For the Generalized FLWOR:

  FLWORClauseList ::= FLWORClause*

  - For the traditional FLWOR:

  FLWORClauseList ::= (ForClause | LetClause)*
                      WhereCluase?
                      GroupByClause?
                      OrderByClause?
********************************************************************************/
void* begin_visit(const FLWORClauseList& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const FLWORClauseList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  ForClause ::= "outer"? "for" "$"  VarInDeclList
********************************************************************************/
void* begin_visit(const ForClause& v)
{
  TRACE_VISIT();

  if (v.has_allowing_empty())
  {
    if (theSctx->xquery_version() < StaticContextConsts::xquery_version_3_0)
      RAISE_ERROR(err::XPST0003, loc, ERROR_PARAMS(ZED(OuterForClause11)));

    theFlworClausesStack.push_back(NULL);
  }

  return no_state;
}


void end_visit(const ForClause& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  if (v.has_allowing_empty())
  {
    ulong curClause = (ulong)theFlworClausesStack.size() - 1;
    while(theFlworClausesStack[curClause] != NULL)
      --curClause;

    theFlworClausesStack.erase(theFlworClausesStack.begin() + curClause);
  }
}


/*******************************************************************************
  VarInDeclList ::= VarInDecl | VarInDeclList  ","  "$"  VarInDecl
********************************************************************************/
void* begin_visit(const VarInDeclList& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const VarInDeclList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  VarInDecl ::= VarName TypeDeclaration? PositionalVar? FTScoreVar? "in" ExprSingle
********************************************************************************/
void* begin_visit(const VarInDecl& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const VarInDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t domainExpr = pop_nodestack();

  if (domainExpr->is_updating())
    throw XQUERY_EXCEPTION(err::XUST0001, ERROR_LOC(loc));

  // it's important to insert the debugger before the scope is pushed.
  // Otherwise, the variable in question would already be in scope for
  // the debugger but no value would be bound
  QueryLoc lExpandedLocation = expandQueryLoc(
    v.get_name()->get_location(),
    domainExpr->get_loc());
  wrap_in_debugger_expr(domainExpr, lExpandedLocation);

  push_scope();

  xqtref_t type = (v.get_typedecl() == NULL ? NULL : pop_tstack());

  var_expr_t varExpr = bind_var(loc, v.get_name(), var_expr::for_var, type);
  var_expr_t posVarExpr;

  const PositionalVar* pv = v.get_posvar();
  if (pv != NULL)
  {
    store::Item_t pvarQName;
    expand_no_default_qname(pvarQName, pv->get_name(), loc);

    if (pvarQName->equals(varExpr->get_name()))
      throw XQUERY_EXCEPTION(
        err::XQST0089, ERROR_PARAMS(pvarQName->getStringValue()), ERROR_LOC(loc)
      );

    posVarExpr = bind_var(pv->get_location(), pvarQName, var_expr::pos_var);
  }

  for_clause* fc = new for_clause(theRootSctx,
                                  loc,
                                  varExpr,
                                  domainExpr,
                                  posVarExpr,
                                  NULL,
                                  v.get_allowing_empty());

  theFlworClausesStack.push_back(fc);
}


/*******************************************************************************
  PositionalVar ::= "at" "$"  VarName
********************************************************************************/
void* begin_visit(const PositionalVar& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const PositionalVar& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  LetClause ::= "let" "$" VarGetsDeclList | "let" "score $" VarGetsDeclList
********************************************************************************/
void* begin_visit(const LetClause& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const LetClause& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  VarGetsDeclList ::= VarGetsDecl | VarGetsDeclList ","  "$"  VarGetsDecl
********************************************************************************/
void* begin_visit(const VarGetsDeclList& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const VarGetsDeclList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  VarGetsDecl	::= VarName TypeDeclaration? ":=" ExprSingle |
                  VarName TypeDeclaration? FTScoreVar ":=" ExprSingle
********************************************************************************/
void* begin_visit(const VarGetsDecl& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const VarGetsDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  xqtref_t type = (v.get_typedecl() == NULL ? NULL : pop_tstack());

  if (v.get_kind() == VarGetsDecl::let_var)
  {
    expr_t domainExpr = pop_nodestack();

    if (domainExpr->is_updating())
      throw XQUERY_EXCEPTION(err::XUST0001, ERROR_LOC(loc));

    // it's important to insert the debugger before the scope is pushed.
    // Otherwise, the variable in question would already be in scope for
    // the debugger but no value would be bound
    QueryLoc lExpandedLocation = expandQueryLoc(
      v.get_name()->get_location(),
      domainExpr->get_loc());
    wrap_in_debugger_expr(domainExpr, lExpandedLocation);

    push_scope();

    var_expr_t varExpr = bind_var(loc, v.get_name(), var_expr::let_var, type);

    let_clause* clause = new let_clause(theRootSctx,
                                        loc,
                                        varExpr,
                                        domainExpr);

    theFlworClausesStack.push_back(clause);
  }
  else
  {
    push_scope();
    push_nodestack(create_var(loc, v.get_name(), var_expr::let_var, type).getp());
  }
}


/*******************************************************************************
  WindowClause ::= "for" (TumblingWindowClause | SlidingWindowClause)

  TumblingWindowClause ::= "tumbling" "window" WindowVarDecl
                           WindowStartCondition WindowEndCondition?

  SlidingWindowClause ::= "sliding" "window" WindowVarDecl
                          WindowStartCondition WindowEndCondition

  Note: The accept() method of WindowClause translates the window domain expr
  first, then the conditions, and finally the window variable.
********************************************************************************/
void* begin_visit(const WindowClause& v)
{
  TRACE_VISIT();

  if (theSctx->xquery_version() < StaticContextConsts::xquery_version_3_0)
    throw XQUERY_EXCEPTION(
      err::XPST0003, ERROR_PARAMS( ZED( WindowClause11 ) ), ERROR_LOC( loc )
    );

  return no_state;
}


void intermediate_visit(const WindowClause& v, void* /*visit_state*/)
{
  // This method is called after translating the window domain expr, but before
  // translating the window conditions and the window var.

  // Pop the window the domain expr.
  expr_t windowDomainExpr = pop_nodestack();

  window_clause::window_t winKind = (v.get_wintype() == WindowClause::tumbling_window ?
                                     window_clause::tumbling_window :
                                     window_clause::sliding_window);

  window_clause* clause = new window_clause(theRootSctx,
                                            v.get_location(),
                                            winKind,
                                            NULL,
                                            windowDomainExpr,
                                            NULL,
                                            NULL);

  theFlworClausesStack.push_back(clause);

  // Create scope for the input window-condition vars. These vars are visible
  // inside the WindowStartCondition and WindowEndCondition only, so the scope
  // created here will be destroyed as soon as we start processing the
  // WindowVarDecl (see below).
  push_scope();
}


void end_visit(const WindowClause& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  window_clause* windowClause = dynamic_cast<window_clause*>(
                                theFlworClausesStack.back().getp());
  assert(windowClause != NULL);

  // Pop the window var and associate it with this window clause
  var_expr_t windowVarExpr = pop_nodestack_var();
  windowVarExpr->set_flwor_clause(windowClause);

  // Create scope for the output window-condition vars. These vars are visible
  // outside the window clause only.
  push_scope();

  // Create var_exprs for output window-condition vars, associate them with this
  // window clause, and push them to the nodestack.
  rchandle<FLWORWinCond> cond;
  for (int i = 0; i < 2; i++)
  {
    if (NULL != (cond = v[i]))
    {
      rchandle<WindowVars> vars = cond->get_winvars();
      if (vars != NULL)
        bind_wincond_vars(*vars, windowClause, false);
    }
  }

  // Collect the output window-condition vars from the nodestack and store
  // them in a flwor_wincond::vars obj.
  flwor_wincond::vars outputCondVarExprs[2];

  for (int i = 1; i >= 0; i--)
  {
    rchandle<FLWORWinCond> cond = v[i];
    if (cond != NULL)
    {
      rchandle<WindowVars> vars = cond->get_winvars();
      pop_wincond_vars(vars, outputCondVarExprs[i]);
    }
  }

  // Collect the input window-condition vars from the nodestack and store
  // them in a flwor_wincond::vars obj. Also pop the condition expr and
  // create a flwor_wincond obj for each condition.
  flwor_wincond::vars inputCondVarExprs[2];
  flwor_wincond_t conds[2];

  for (int i = 1; i >= 0; i--)
  {
    rchandle<FLWORWinCond> cond = v[i];
    if (cond != NULL)
    {
      expr_t condExpr = pop_nodestack();

      rchandle<WindowVars> vars = cond->get_winvars();
      pop_wincond_vars(vars, inputCondVarExprs[i]);

      conds[i] = new flwor_wincond(theSctx,
                                   cond->is_only(),
                                   inputCondVarExprs[i],
                                   outputCondVarExprs[i],
                                   condExpr);
    }
  }

  windowClause->set_var(windowVarExpr);
  windowClause->set_win_start(conds[0]);
  windowClause->set_win_stop(conds[1]);
}



void bind_wincond_vars(const WindowVars& v, flwor_clause* windowClause, bool input)
{
  const QueryLoc& loc = v.get_location();

  enum var_expr::var_kind varKind = (input ?
                                     var_expr::wincond_in_var :
                                     var_expr::wincond_out_var);

  enum var_expr::var_kind pvarKind = (input ?
                                      var_expr::wincond_in_pos_var :
                                      var_expr::wincond_out_pos_var);

  var_expr_t posVarExpr;
  var_expr_t curVarExpr;
  var_expr_t nextVarExpr;
  var_expr_t prevVarExpr;

  rchandle<PositionalVar> pv = v.get_posvar();
  if (pv != NULL)
  {
    posVarExpr = bind_var(pv->get_location(), pv->get_name(), pvarKind);

    posVarExpr->set_flwor_clause(windowClause);
    push_nodestack(posVarExpr.getp());
  }

  if (v.get_curr())
  {
    curVarExpr = bind_var(loc, v.get_curr(), varKind);

    curVarExpr->set_flwor_clause(windowClause);
    push_nodestack(curVarExpr.getp());
  }

  if (v.get_prev())
  {
    prevVarExpr = bind_var(loc, v.get_prev(), varKind);

    prevVarExpr->set_flwor_clause(windowClause);
    push_nodestack(prevVarExpr.getp());
  }

  if (v.get_next())
  {
    nextVarExpr = bind_var(loc, v.get_next(), varKind);

    nextVarExpr->set_flwor_clause(windowClause);
    push_nodestack(nextVarExpr.getp());
  }
}


void pop_wincond_vars(rchandle<WindowVars> node, flwor_wincond::vars& vars)
{
  if (node != NULL)
  {
    if (node->get_next())
      vars.next = pop_nodestack_var();

    if (node->get_prev())
      vars.prev = pop_nodestack_var();

    if (node->get_curr())
      vars.curr = pop_nodestack_var();

    if (node->get_posvar() != NULL)
      vars.posvar = pop_nodestack_var();
  }
}


/*******************************************************************************
  WindowVarDecl ::= "$" VarName TypeDeclaration? "in"  ExprSingle
********************************************************************************/
void* begin_visit(const WindowVarDecl& v)
{
  TRACE_VISIT();

  // Done with input window condition vars.
  pop_scope();

  return no_state;
}

void end_visit(const WindowVarDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  // Create scope for the window var
  push_scope();

  xqtref_t type = (v.get_typedecl() == NULL ? NULL : pop_tstack());

  var_expr_t ve = bind_var(loc, v.get_name(), var_expr::win_var, type);
  push_nodestack(ve.getp());
}


/*******************************************************************************
  WindowStartCondition ::= "start" WindowVars "when" ExprSingle

  WindowEndCondition ::= "only"? "end" WindowVars "when" ExprSingle
********************************************************************************/
void* begin_visit(const FLWORWinCond& v)
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
void* begin_visit(const WindowVars& v)
{
  TRACE_VISIT();
  return no_state;
}


void end_visit(const WindowVars& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  // Create var_exprs for the input window-condition vars, associate them with
  // the current window clause, and push them to the nodestack.

  flwor_clause* windowClause = theFlworClausesStack.back();
  bind_wincond_vars(v, windowClause, true);
}



/*******************************************************************************
  GroupByClause ::= "group" "by" GroupingSpecList
********************************************************************************/
void* begin_visit(const GroupByClause& v)
{
  TRACE_VISIT();

  const FLWORExpr& flwor = *v.get_flwor ();
  const FLWORClauseList& clauses = *flwor.get_clause_list ();

  std::set<const var_expr *> all_vars;
  std::set<const var_expr *> group_vars;
  std::set<const var_expr *> non_group_vars;

  // Collect the var_exprs for all the vars that have been defined by all
  // clauses before this GroupByClause.
  collect_flwor_vars(flwor, all_vars, &*clauses[0], &v, loc);

  // Collect the var_exprs for all the grouping vars specified in this GroupByClause.
  GroupSpecList* lList = v.get_spec_list();
  for (int i = 0; i < (int)lList->size(); ++i)
  {
    GroupSpec* spec = (*lList)[i];
    const QName* varname = spec->get_var_name();
    const var_expr* ve = lookup_var(varname, loc, err::XPST0008);
    group_vars.insert(ve);
  }

  // The non-grouping vars are the vars in the difference of the 2 sets above.
  set_difference(all_vars.begin(), all_vars.end(),
                 group_vars.begin(), group_vars.end(),
                 inserter(non_group_vars, non_group_vars.begin()));

  // For each var_expr X that does not appear in the group-by clause, create
  // a new var_exp ngX and push ngX and X in the node stack.

  push_nodestack(NULL);

  for (std::set<const var_expr *>::iterator i = non_group_vars.begin();
       i != non_group_vars.end();
       ++i)
  {
    push_nodestack(const_cast<var_expr *>(*i));

    push_scope();

    var_expr_t ve = bind_var(loc, (*i)->get_name(), var_expr::non_groupby_var);
    push_nodestack(ve.getp());
  }

  return no_state;
}


void end_visit(const GroupByClause& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  // At this point, the nodestack contains a pair of var_exprs for each var X
  // defined by any clauses appearing before this GroupByClause. The first
  // var_expr in the pair corresponds to the input-stream var X, and the second
  // var_expr corresponds to the associated output-stream var. The pairs for
  // the grouping vars appear first (i.e., at the top of the odestack), followed
  // by the pairs for the non-grouping vars.

  const GroupSpecList& groupSpecs = *v.get_spec_list();
  size_t numGroupSpecs = groupSpecs.size();

  std::vector<std::string> collations;
  group_clause::rebind_list_t grouping_rebind;
  group_clause::rebind_list_t nongrouping_rebind;
  var_expr_t input_var;
  var_expr_t output_var;

  for (int i = (int)numGroupSpecs - 1; i >= 0; i--)
  {
    const GroupSpec& groupSpec = *groupSpecs[i];

    output_var = pop_nodestack_var();
    input_var = pop_nodestack_var();

    if (groupSpec.group_coll_spec() != NULL)
      collations.push_back(groupSpec.group_coll_spec()->get_uri().str());
    else
      collations.push_back ("");

    wrapper_expr_t input_wrapper;
    input_wrapper = new wrapper_expr(theRootSctx,
                                     loc,
                                     static_cast<expr*>(input_var.getp()));

    grouping_rebind.push_back(std::pair<wrapper_expr_t, var_expr_t>(input_wrapper,
                                                                    output_var));
  }

  reverse(collations.begin(), collations.end());
  reverse(grouping_rebind.begin(), grouping_rebind.end());

  while (NULL != (output_var = pop_nodestack_var()))
  {
    input_var = pop_nodestack_var();

    wrapper_expr_t input_wrapper;
    input_wrapper = new wrapper_expr(theRootSctx,
                                     loc,
                                     static_cast<expr*>(input_var.getp()));

    nongrouping_rebind.push_back(std::pair<wrapper_expr_t, var_expr_t>(input_wrapper,
                                                                       output_var));
  }

  group_clause* clause = new group_clause(theRootSctx,
                                          loc,
                                          grouping_rebind,
                                          nongrouping_rebind,
                                          collations);
  theFlworClausesStack.push_back(clause);
}


/*******************************************************************************
  GroupSpecList ::= 	GroupingSpec ("," GroupingSpec)*
********************************************************************************/
void* begin_visit(const GroupSpecList& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const GroupSpecList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  GroupSpec ::= "$" VarName ("collation" URILiteral)?
********************************************************************************/
void* begin_visit(const GroupSpec& v)
{
  TRACE_VISIT();

  var_expr* e = lookup_var(v.get_var_name(), loc, err::XPST0008);

  // Create a new var_expr gX, corresponding to the input-stream var X that
  // is referenced by this group spec. gX represents X in the output stream.
  // Push the var_exprs for both X and gX into the nodestack.
  push_scope();

  push_nodestack(e);

  var_expr_t ve = bind_var(loc, v.get_var_name(), var_expr::groupby_var);
  push_nodestack(ve.getp());

  return no_state;
}

void end_visit(const GroupSpec& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************

********************************************************************************/
void* begin_visit(const GroupCollationSpec& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const GroupCollationSpec& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
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

  const OrderSpecList& orderSpecs = *v.get_spec_list();
  unsigned numOrderSpecs = (unsigned)orderSpecs.size();

  std::vector<OrderModifier> modifiers(numOrderSpecs);
  std::vector<expr_t> orderExprs(numOrderSpecs);

  for (int i = numOrderSpecs - 1; i >= 0; --i)
  {
    OrderSpec* spec = orderSpecs[i];
    const OrderModifierPN* mod = spec->get_modifier();

    ParseConstants::dir_spec_t dirSpec = ParseConstants::dir_ascending;
    if (mod && mod->get_dir_spec() != NULL)
      dirSpec = mod->get_dir_spec()->getValue();

    StaticContextConsts::empty_order_mode_t emptySpec = theSctx->empty_order_mode();
    if (mod && mod->get_empty_spec() != NULL)
      emptySpec = mod->get_empty_spec()->getValue();

    std::string collationUri = theSctx->get_default_collation(loc);

    if (mod && mod->get_collation_spec() != NULL)
    {
      collationUri = mod->get_collation_spec()->get_uri().str();

      if (! theSctx->is_known_collation(collationUri))
        throw XQUERY_EXCEPTION(
          err::XQST0076, ERROR_PARAMS( collationUri ), ERROR_LOC( loc )
        );
    }

    expr_t orderExpr = pop_nodestack();

    if (orderExpr->is_updating())
      throw XQUERY_EXCEPTION(err::XUST0001, ERROR_LOC(loc));

    orderExpr = wrap_in_atomization(orderExpr);

    modifiers[i].theAscending = (dirSpec == ParseConstants::dir_ascending);
    modifiers[i].theEmptyLeast = (emptySpec == StaticContextConsts::empty_least);
    modifiers[i].theCollation = collationUri;

    orderExprs[i] = orderExpr;
  }

  orderby_clause* clause = new orderby_clause(theRootSctx,
                                              loc,
                                              v.get_stable_bit(),
                                              modifiers,
                                              orderExprs);
  theFlworClausesStack.push_back(clause);
}


/*******************************************************************************
  OrderSpecList ::=	OrderSpec ("," OrderSpec)*
********************************************************************************/
void* begin_visit(const OrderSpecList& v)
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
void* begin_visit(const OrderSpec& v)
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
void* begin_visit(const OrderModifierPN& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const OrderModifierPN& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


void* begin_visit(const OrderCollationSpec& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderCollationSpec& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void* begin_visit(const OrderDirSpec& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderDirSpec& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}

void* begin_visit(const OrderEmptySpec& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderEmptySpec& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


/*******************************************************************************
  WhereClause ::= "where"  ExprSingle
********************************************************************************/
void* begin_visit(const WhereClause& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const WhereClause& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  expr_t whereExpr = pop_nodestack();

  if (whereExpr->is_updating())
    throw XQUERY_EXCEPTION(err::XUST0001, ERROR_LOC(loc));

  whereExpr = wrap_in_bev(whereExpr);

  wrap_in_debugger_expr(whereExpr, whereExpr->get_loc());

  where_clause* clause = new where_clause(theRootSctx,
                                          loc,
                                          whereExpr);

  theFlworClausesStack.push_back(clause);
}


/*******************************************************************************
  CountClause ::= "count" "$" VarName
********************************************************************************/
void* begin_visit(const CountClause& v)
{
  TRACE_VISIT ();

  if (theSctx->xquery_version() < StaticContextConsts::xquery_version_3_0)
    throw XQUERY_EXCEPTION(
      err::XPST0003, ERROR_PARAMS( ZED( CountClause11 ) ), ERROR_LOC( loc )
    );

  return no_state;
}

void end_visit(const CountClause& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  var_expr_t varExpr = bind_var(loc, v.get_varname(), var_expr::count_var, NULL);

  count_clause* clause = new count_clause(theRootSctx,
                                          loc,
                                          varExpr);

  theFlworClausesStack.push_back(clause);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Switch                                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////



/*******************************************************************************
  SwitchExpr ::= "switch" "(" Expr ")"
                  SwitchCaseClause+
                  "default" "return" ExprSingle

  SwitchCaseClause ::= ("case" SwitchCaseOperand)+ "return" ExprSingle

  A switch expr is translated into a flwor expr. For example, a switch of
  the following form:

  switch E
  case $c11 return E1
  case $c21
  case $c22 return E2
  ......
  case $cn1 return En
  default return Ed

  is translated into:

  let $sv := E
  return if ($sv = $c11 or $sv = $c12 or ...) then
           return E1
         else if ($sv = $c21 or $sv = $c22 or ...) then
           return E2
         ....
         else if ($sv = $cn1 or $sv = $cn2 or ...) then
           return En
         else
           return Ed
********************************************************************************/
void* begin_visit(const SwitchExpr& v)
{
  TRACE_VISIT();

  if (theSctx->xquery_version() < StaticContextConsts::xquery_version_3_0)
  {
    throw XQUERY_EXCEPTION(err::XPST0003,
                           ERROR_PARAMS(ZED(SwitchExpr11)),
                           ERROR_LOC(loc));
  }

  v.get_switch_expr()->accept(*this);

  expr_t se = pop_nodestack();

  se = wrap_in_atomization(se);

  // atomizedFlwor = [let $atomv := data(E) return NULL]
  var_expr_t atomv = create_temp_var(v.get_switch_expr()->get_location(),
                                     var_expr::let_var);

  expr_t atomizedFlwor = wrap_in_let_flwor(se, atomv, NULL);

  // TODO: cast as xs:string should not really be necessary
  // atomizedFlwor =
  //  [let $atomv := data(E)
  //   return
  //     let $sv :=
  //          if ($atomv instanceof xs:untypedAtomic)
  //          then $atomv cast as xs:string
  //          else $atomv
  //     return NULL]
  static_cast<flwor_expr*>(atomizedFlwor.getp())->set_return_expr(
    new if_expr(theRootSctx,
                loc,
                new instanceof_expr(theRootSctx,
                                    loc,
                                    atomv.getp(),
                                    theRTM.UNTYPED_ATOMIC_TYPE_ONE),
                new cast_expr(theRootSctx,
                              loc,
                              atomv.getp(),
                              theRTM.STRING_TYPE_ONE),
                atomv.getp()));

  // flworExpr = [let $sv := atomizedFlwor return NULL]
  var_expr_t sv = create_temp_var(v.get_switch_expr()->get_location(), var_expr::let_var);
  expr_t flworExpr = wrap_in_let_flwor(atomizedFlwor, sv, NULL);

  // retExpr = [Ed]
  v.get_default_expr()->accept(*this);
  expr_t retExpr = pop_nodestack();

  const SwitchCaseClauseList* clauses = v.get_clause_list();
  std::vector<rchandle<SwitchCaseClause> >::const_reverse_iterator it;

  for (it = clauses->rbegin(); it != clauses->rend(); ++it)
  {
    const SwitchCaseClause* switchCaseClause = &**it;
    const QueryLoc& loc = switchCaseClause->get_location();

    const SwitchCaseOperandList* operands = switchCaseClause->get_operand_list();

    expr_t condExpr = NULL;
    std::vector<expr_t> condOperands;
    condOperands.reserve(operands->size());

    for (std::vector<rchandle<exprnode> >::const_iterator it = operands->begin();
         it != operands->end();
         ++it)
    {
      const exprnode* operand = &**it;
      operand->accept(*this);

      expr_t operandExpr = pop_nodestack();
      operandExpr = wrap_in_atomization(operandExpr);
      operandExpr = new fo_expr(theRootSctx, loc,
                                GET_BUILTIN_FUNCTION(OP_ATOMIC_VALUES_EQUIVALENT_2),
                                sv,
                                operandExpr);

      condOperands.push_back(operandExpr);
    } // for

    if (condOperands.size() == 1)
    {
      condExpr = condOperands[0];
    }
    else if (condOperands.size() > 1)
    {
      condExpr = new fo_expr(theRootSctx,
                             loc,
                             GET_BUILTIN_FUNCTION(OP_OR_N),
                             condOperands);
    }

    switchCaseClause->get_return_expr()->accept(*this);
    expr_t caseReturnExpr = pop_nodestack();

    // retExpr = [if (condExpr) then caseReturnExpr else retExpr]
    retExpr = new if_expr(theRootSctx, loc, condExpr, caseReturnExpr, retExpr);

  } // for

  static_cast<flwor_expr*>(flworExpr.getp())->set_return_expr(retExpr);
  push_nodestack(flworExpr);

  // Return NULL so that SwitchExpr::accept() will not call accept() on the
  // children of the SwitchExpr parsenode.
  return NULL;
}

void end_visit (const SwitchExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  // shouldn't get here, begin_visit() rejects visitor
  ZORBA_ASSERT (false);
}

void* begin_visit(const SwitchCaseClause& v)
{
  TRACE_VISIT();

  return NULL;
}

void end_visit (const SwitchCaseClause& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  // shouldn't get here, begin_visit() rejects visitor
  ZORBA_ASSERT (false);
}

void* begin_visit(const SwitchCaseClauseList& v)
{
  TRACE_VISIT();
  // shouldn't get here
  ZORBA_ASSERT(false);
  return no_state;
}

void end_visit(const SwitchCaseClauseList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}

void* begin_visit(const SwitchCaseOperandList& v)
{
  TRACE_VISIT();
  // shouldn't get here
  ZORBA_ASSERT(false);
  return no_state;
}

void end_visit(const SwitchCaseOperandList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  TypeSwitch                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  TypeswitchExpr ::= "typeswitch" "(" Expr ")"
                     CaseClauseList
                    "default" ("$" VarName)? "return" ExprSingle

  CaseClauseList := CaseClause+

  CaseClause ::= "case" ("$" VarName "as")? SequenceType "return" ExprSingle


  A typeswitch expr is translated into a flwor expr. For example, a typeswitch of
  the following form:

  typeswitch E
  case $v1 as type1 return E1
  ......
  case $vn as typen return En
  default $def return Ed

  is translated into:

  let $sv := E
  return if (instance_of($sv, type1)) then
           let $v1 := treat_as($sv, type1) return E1
         else if (instance_of($sv, type2)) then
           let $v2 := treat_as($sv, type2) return E2
         ....
         else if instance_of($sv, typen)) then
           let $vn := treat_as($sv, typen) return En
         else
           let $def := sv return Ed
********************************************************************************/
void* begin_visit(const TypeswitchExpr& v)
{
  TRACE_VISIT();

  var_expr_t sv = create_temp_var(v.get_switch_expr()->get_location(), var_expr::let_var);

  v.get_switch_expr()->accept(*this);

  expr_t se = pop_nodestack();

  // flworExpr = [let $sv := E return NULL]
  expr_t retExpr;
  expr_t flworExpr = wrap_in_let_flwor(se, sv, retExpr);

  const QName* defvar_name = v.get_default_varname();
  var_expr_t defvar;

  if (defvar_name)
  {
    push_scope();
    defvar = bind_var(v.get_default_clause()->get_location(),
                      defvar_name,
                      var_expr::let_var);

    // retExpr = [let $def := $sv return NULL]
    retExpr = &*wrap_in_let_flwor(&*sv, defvar, NULL);
  }

  v.get_default_clause()->accept(*this);

  expr_t defExpr = pop_nodestack();

  if (defvar_name)
  {
    pop_scope();

    // retExpr = [let $def := $sv return Ed]
    static_cast<flwor_expr*>(retExpr.getp())->set_return_expr(defExpr);
  }
  else
  {
    // retExpr = [Ed]
    retExpr = defExpr;
  }

  const CaseClauseList* clauses = v.get_clause_list();
  for (std::vector<rchandle<CaseClause> >::const_reverse_iterator it = clauses->rbegin();
       it != clauses->rend();
       ++it)
  {
    const CaseClause* caseClause = &**it;
    const QueryLoc& loc = caseClause->get_location();
    expr_t clauseExpr;

    caseClause->get_type()->accept(*this);
    xqtref_t type = pop_tstack();

    const QName* varname = caseClause->get_varname();
    var_expr_t caseVar;

    if (varname)
    {
      push_scope();

      caseVar = bind_var(loc, varname, var_expr::let_var);

      expr_t treatExpr = new treat_expr(theRootSctx,
                                        loc,
                                        sv.getp(),
                                        type,
                                        err::XPDY0050);

      // clauseExpr = [let $caseVar := treat_as($sv, caseType) return NULL]
      clauseExpr = wrap_in_let_flwor(treatExpr, caseVar, NULL);
    }

    caseClause->get_expr()->accept(*this);
    expr_t caseExpr = pop_nodestack();

    if (varname)
    {
      pop_scope();

      // clauseExpr = [let $caseVar := treat_as($sv, caseType) return NULL]
      static_cast<flwor_expr*>(clauseExpr.getp())->set_return_expr(caseExpr);
    }
    else
    {
      // clauseExpr = [caseExpr]
      clauseExpr = caseExpr;
    }

    // retExpr = [if (instance_of($sv, type)) then clauseExpr else retExpr]
    retExpr = new if_expr(theRootSctx,
                          loc,
                          new instanceof_expr(theRootSctx, loc, &*sv, type),
                          clauseExpr,
                          retExpr);
  }

  static_cast<flwor_expr*>(flworExpr.getp())->set_return_expr(retExpr);

  push_nodestack(flworExpr);

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
void* begin_visit(const CaseClauseList& v)
{
  TRACE_VISIT();
  // shouldn't get here
  ZORBA_ASSERT(false);
  return no_state;
}


void end_visit(const CaseClauseList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  CaseClause ::= "case" ("$" VarName "as")? SequenceType "return" ExprSingle
********************************************************************************/
void* begin_visit(const CaseClause& v)
{
  TRACE_VISIT();
  // shouldn't get here
  ZORBA_ASSERT(false);
  return no_state;
}


void end_visit(const CaseClause& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  If                                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  IfExpr ::= "if" "(" Expr ")" "then" ExprSingle "else" ExprSingle
********************************************************************************/
void* begin_visit(const IfExpr& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const IfExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t e_h = pop_nodestack();
  expr_t t_h = pop_nodestack();
  expr_t c_h = pop_nodestack();

  wrap_in_debugger_expr(e_h, e_h->get_loc());
  wrap_in_debugger_expr(t_h, t_h->get_loc());
  wrap_in_debugger_expr(c_h, c_h->get_loc());

  if_expr* ifExpr = new if_expr(theRootSctx, loc, c_h, t_h, e_h);

  push_nodestack(ifExpr);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  TryCatch                                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  [169] TryCatchExpr ::= TryClause CatchClauseList

  [170] TryClause ::= "try" "{" TryTargetExpr "}"

  [171] TryTargetExpr ::= Expr
********************************************************************************/
void* begin_visit(const TryExpr& v)
{
  TRACE_VISIT();

  if (theSctx->xquery_version() < StaticContextConsts::xquery_version_3_0)
  {
    throw XQUERY_EXCEPTION(err::XPST0003,
                           ERROR_PARAMS(ZED(TryCatchExpr11)),
                           ERROR_LOC(loc));
  }

  theTryStack.push_back(&v);

  return no_state;
}

void end_visit(const TryExpr& v, void* visit_state)
{
  TRACE_VISIT_OUT();

  theTryStack.pop_back();
}


/*******************************************************************************
  CatchClauseList := CatchClause+
********************************************************************************/
void* begin_visit(const CatchListExpr& v)
{
  TRACE_VISIT();

  expr_t tryExpr = pop_nodestack();

  trycatch_expr* tce = new trycatch_expr(theRootSctx, loc, tryExpr);

  push_nodestack(tce);

  return no_state;
}

void end_visit(const CatchListExpr& v, void* visit_state)
{
  TRACE_VISIT_OUT();

  trycatch_expr* tce = static_cast<trycatch_expr*>(theNodeStack.top().getp());

  tce->compute_scripting_kind();
}


/*******************************************************************************
  [172] CatchClause ::= "catch" CatchErrorList "{" Expr "}"

  [173] CatchErrorList ::= NameTest ("|" NameTest)*
********************************************************************************/
void* begin_visit(const CatchExpr& v)
{
  TRACE_VISIT();

  trycatch_expr* tce = dynamic_cast<trycatch_expr *>(theNodeStack.top().getp());

  catch_clause_t cc = new catch_clause();

  push_scope();

  store::Item_t lCode, lDesc, lValue, lModule, lLineNo, lColumnNo, lStackTrace;

  GENV_ITEMFACTORY->createQName(lCode, XQUERY_ERR_NS, "", "code");
  GENV_ITEMFACTORY->createQName(lDesc, XQUERY_ERR_NS, "", "description");
  GENV_ITEMFACTORY->createQName(lValue, XQUERY_ERR_NS, "", "value");
  GENV_ITEMFACTORY->createQName(lModule, XQUERY_ERR_NS, "", "module");
  GENV_ITEMFACTORY->createQName(lLineNo, XQUERY_ERR_NS, "", "line-number");
  GENV_ITEMFACTORY->createQName(lColumnNo, XQUERY_ERR_NS, "", "column-number");
  GENV_ITEMFACTORY->createQName(lStackTrace, ZORBA_ERR_NS, "", "stack-trace");

  cc->add_var(catch_clause::err_code,
      bind_var(loc, lCode.getp(), var_expr::catch_var, theRTM.QNAME_TYPE_ONE) );
  cc->add_var(catch_clause::err_desc,
      bind_var(loc, lDesc.getp(), var_expr::catch_var, theRTM.STRING_TYPE_QUESTION) );
  cc->add_var(catch_clause::err_value,
      bind_var(loc, lValue.getp(), var_expr::catch_var, theRTM.ITEM_TYPE_STAR) );
  cc->add_var(catch_clause::err_module,
      bind_var(loc, lModule.getp(), var_expr::catch_var, theRTM.STRING_TYPE_QUESTION) );
  cc->add_var(catch_clause::err_line_no,
      bind_var(loc, lLineNo.getp(), var_expr::catch_var, theRTM.INTEGER_TYPE_QUESTION) );
  cc->add_var(catch_clause::err_column_no,
      bind_var(loc, lColumnNo.getp(), var_expr::catch_var, theRTM.INTEGER_TYPE_QUESTION) );
  cc->add_var(catch_clause::zerr_stack_trace,
      bind_var(loc, lStackTrace.getp(), var_expr::catch_var, theRTM.ITEM_TYPE_QUESTION) );

  tce->add_clause(cc);

  return no_state;
}

void end_visit(const CatchExpr& v, void* visit_state)
{
  TRACE_VISIT_OUT();

  expr_t ce = pop_nodestack();
  trycatch_expr* tce = dynamic_cast<trycatch_expr *>(theNodeStack.top().getp());

  tce->add_catch_expr(ce);

  pop_scope();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Quantified                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  QuantifiedExpr ::= ("some" | "every") QVarInDeclList "satisfies" ExprSingle

  QVarInDeclList ::= "$" VarName TypeDeclaration? "in" ExprSingle
                     ("," "$" VarName TypeDeclaration? "in" ExprSingle)*

  A universally quantified expr is translated into a flwor expr:

  fn:empty(for $v1 in expr1, ... vn in exprn
           where not(testExpr)
           return true)

  An existentially quantified expr is translated into a flwor expr:

  fn:exists(for $v1 in expr1, ... vn in exprn
            where testExpr
            return true)

********************************************************************************/
void* begin_visit(const QuantifiedExpr& v)
{
  TRACE_VISIT();

  rchandle<flwor_expr> flwor(new flwor_expr(theRootSctx, loc, false));

  flwor->set_return_expr(new const_expr(theRootSctx, loc, true));

  push_nodestack(flwor.getp());

  return no_state;
}


void end_visit(const QuantifiedExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  rchandle<expr> testExpr = pop_nodestack();

  if (v.get_qmode() == ParseConstants::quant_every)
  {
    rchandle<fo_expr> uw = new fo_expr(theRootSctx,
                                       v.get_expr()->get_location(),
                                       GET_BUILTIN_FUNCTION(FN_NOT_1),
                                       testExpr);
    testExpr = uw.getp();
  }
  else
  {
    testExpr = wrap_in_bev(testExpr);
  }

  for (int i = 0; i < (int)v.get_decl_list()->size(); ++i)
  {
    pop_scope();
  }

  flwor_expr_t flworExpr = dynamic_cast<flwor_expr*>(pop_nodestack().getp());
  ZORBA_ASSERT(flworExpr != NULL);

  flworExpr->add_where(testExpr);

  rchandle<fo_expr> quant = new fo_expr(theRootSctx,
                                        loc,
                                        v.get_qmode() == ParseConstants::quant_every ?
                                        GET_BUILTIN_FUNCTION(FN_EMPTY_1) :
                                        GET_BUILTIN_FUNCTION(FN_EXISTS_1),
                                        flworExpr.getp());
  push_nodestack(quant.getp());
}


/*******************************************************************************
  QVarInDeclList := QVarInDecl ("," QVarInDecl)*
********************************************************************************/
void* begin_visit(const QVarInDeclList& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const QVarInDeclList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  QVarInDecl := "$" VarName TypeDeclaration? "in" ExprSingle
********************************************************************************/
void* begin_visit(const QVarInDecl& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const QVarInDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  push_scope();
  xqtref_t type;
  if (v.get_typedecl() != NULL)
    type = pop_tstack();

  expr_t domainExpr = pop_nodestack();
  var_expr_t varExpr = bind_var(loc, v.get_name(), var_expr::for_var, type);

  flwor_expr* flworExpr = dynamic_cast<flwor_expr*>(theNodeStack.top().getp());
  ZORBA_ASSERT(flworExpr != NULL);

  flworExpr->add_clause(wrap_in_forclause(domainExpr, varExpr, NULL));
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  OrExpr                                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  OrExpr ::= AndExpr ( "or" AndExpr )*
********************************************************************************/
void* begin_visit(const OrExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  rchandle<expr> e1 = pop_nodestack();
  rchandle<expr> e2 = pop_nodestack();

  std::vector<expr_t> args;
  args.reserve(2);

  if (e2->get_expr_kind() == fo_expr_kind)
  {
    fo_expr* foArg = static_cast<fo_expr*>(e2.getp());

    if (foArg->get_func()->getKind() == FunctionConsts::OP_OR_N)
    {
      ulong numArgs = foArg->num_args();
      for (ulong i = 0; i < numArgs; ++i)
        args.push_back(foArg->get_arg(i));
    }
    else
    {
      args.push_back(e2);
    }
  }
  else
  {
    args.push_back(e2);
  }

  if (e1->get_expr_kind() == fo_expr_kind)
  {
    fo_expr* foArg = static_cast<fo_expr*>(e1.getp());

    if (foArg->get_func()->getKind() == FunctionConsts::OP_OR_N)
    {
      ulong numArgs = foArg->num_args();
      for (ulong i = 0; i < numArgs; ++i)
        args.push_back(foArg->get_arg(i));
    }
    else
    {
      args.push_back(e1);
    }
  }
  else
  {
    args.push_back(e1);
  }

  fo_expr* fo = new fo_expr(theRootSctx, loc, GET_BUILTIN_FUNCTION(OP_OR_N), args);

  push_nodestack(fo);
}


/*******************************************************************************
  AndExpr ::= ComparisonExpr ( "and" ComparisonExpr )*
********************************************************************************/
void* begin_visit(const AndExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const AndExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t e1 = pop_nodestack();
  expr_t e2 = pop_nodestack();

  std::vector<expr_t> args;
  args.reserve(2);

  if (e2->get_expr_kind() == fo_expr_kind)
  {
    fo_expr* foArg = static_cast<fo_expr*>(e2.getp());

    if (foArg->get_func()->getKind() == FunctionConsts::OP_AND_N)
    {
      ulong numArgs = foArg->num_args();
      for (ulong i = 0; i < numArgs; ++i)
        args.push_back(foArg->get_arg(i));
    }
    else
    {
      args.push_back(e2);
    }
  }
  else
  {
    args.push_back(e2);
  }

  if (e1->get_expr_kind() == fo_expr_kind)
  {
    fo_expr* foArg = static_cast<fo_expr*>(e1.getp());

    if (foArg->get_func()->getKind() == FunctionConsts::OP_AND_N)
    {
      ulong numArgs = foArg->num_args();
      for (ulong i = 0; i < numArgs; ++i)
        args.push_back(foArg->get_arg(i));
    }
    else
    {
      args.push_back(e1);
    }
  }
  else
  {
    args.push_back(e1);
  }

  fo_expr* fo = new fo_expr(theRootSctx, loc, GET_BUILTIN_FUNCTION(OP_AND_N), args);

  push_nodestack(fo);
}


/*******************************************************************************
  ComparisonExpr ::= RangeExpr ((ValueComp | GeneralComp | NodeComp) RangeExpr)?

  Note: For the full-text extension, the rule for ComparisonExpr is:

  ComparisonExpr ::= FTContainsExpr
                     ((ValueComp | GeneralComp | NodeComp) FTContainsExpr)?

********************************************************************************/
void* begin_visit(const ComparisonExpr& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const ComparisonExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  function* f = NULL;

  if (v.get_gencomp() != NULL)
  {
    switch (v.get_gencomp()->get_type())
    {
    case ParseConstants::op_eq:
      f = GET_BUILTIN_FUNCTION(OP_EQUAL_2);
      break;
    case ParseConstants::op_ne:
      f = GET_BUILTIN_FUNCTION(OP_NOT_EQUAL_2);
      break;
    case ParseConstants::op_lt:
      f = GET_BUILTIN_FUNCTION(OP_LESS_2);
      break;
    case ParseConstants::op_le:
     f = GET_BUILTIN_FUNCTION(OP_LESS_EQUAL_2);
     break;
    case ParseConstants::op_gt:
      f = GET_BUILTIN_FUNCTION(OP_GREATER_2);
      break;
    case ParseConstants::op_ge:
      f = GET_BUILTIN_FUNCTION(OP_GREATER_EQUAL_2);
      break;
    }
  }
  else if (v.get_valcomp() != NULL)
  {
    switch (v.get_valcomp()->get_type())
    {
    case ParseConstants::op_val_eq:
      f = GET_BUILTIN_FUNCTION(OP_VALUE_EQUAL_2);
      break;
    case ParseConstants::op_val_ne:
      f = GET_BUILTIN_FUNCTION(OP_VALUE_NOT_EQUAL_2);
      break;
    case ParseConstants::op_val_lt:
      f = GET_BUILTIN_FUNCTION(OP_VALUE_LESS_2);
      break;
    case ParseConstants::op_val_le:
     f = GET_BUILTIN_FUNCTION(OP_VALUE_LESS_EQUAL_2);
     break;
    case ParseConstants::op_val_gt:
      f = GET_BUILTIN_FUNCTION(OP_VALUE_GREATER_2);
      break;
    case ParseConstants::op_val_ge:
      f = GET_BUILTIN_FUNCTION(OP_VALUE_GREATER_EQUAL_2);
      break;
    }
  }
  else if (v.get_nodecomp() != NULL)
  {
    switch (v.get_nodecomp()->get_type())
    {
    case ParseConstants::op_is:
      f = GET_BUILTIN_FUNCTION(OP_IS_SAME_NODE_2);
      break;
    case ParseConstants::op_precedes:
      f = GET_BUILTIN_FUNCTION(OP_NODE_BEFORE_2);
      break;
    case ParseConstants::op_follows:
      f = GET_BUILTIN_FUNCTION(OP_NODE_AFTER_2);
      break;
    }
  }

  rchandle<expr> e1 = pop_nodestack();
  rchandle<expr> e2 = pop_nodestack();

  fo_expr* fo = new fo_expr(theRootSctx, loc, f, e2, e1);

  normalize_fo(fo);

  push_nodestack(fo);

#undef M
}


/*******************************************************************************
  GeneralComp ::= "=" | "!=" | "<" | "<=" | ">" | ">="
********************************************************************************/
void* begin_visit(const GeneralComp& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const GeneralComp& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  ValueComp ::= "eq" | "ne" | "lt" | "le" | "gt" | "ge"
********************************************************************************/
void* begin_visit(const ValueComp& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const ValueComp& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  NodeComp ::= "is" | "<<" | ">>"
********************************************************************************/
void* begin_visit(const NodeComp& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const NodeComp& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  RangeExpr ::= AdditiveExpr ( "to" AdditiveExpr )?
********************************************************************************/
void* begin_visit(const RangeExpr& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const RangeExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  rchandle<expr> e1 = pop_nodestack();
  rchandle<expr> e2 = pop_nodestack();

  fo_expr* e = new fo_expr(theRootSctx, loc, GET_BUILTIN_FUNCTION(OP_TO_2), e2, e1);

  normalize_fo(e);

  push_nodestack(e);
}


/*******************************************************************************
  AdditiveExpr ::= MultiplicativeExpr ( ("+" | "-") MultiplicativeExpr )*
********************************************************************************/
void* begin_visit(const AdditiveExpr& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const AdditiveExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  rchandle<expr> e1 = pop_nodestack();
  rchandle<expr> e2 = pop_nodestack();

  function* func = NULL;

  switch (v.get_add_op())
  {
  case ParseConstants::op_plus:
    func = GET_BUILTIN_FUNCTION(OP_ADD_2);
    break;
  case ParseConstants::op_minus:
    func = GET_BUILTIN_FUNCTION(OP_SUBTRACT_2);
    break;
  }

  fo_expr* foExpr = new fo_expr(theRootSctx, loc, func, e2, e1);

  normalize_fo(foExpr);

  push_nodestack(foExpr);
}


/*******************************************************************************
  MultiplicativeExpr ::= UnionExpr (("*" | "div" | "idiv" | "mod") UnionExpr)*
********************************************************************************/
void* begin_visit(const MultiplicativeExpr& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const MultiplicativeExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  rchandle<expr> e1 = pop_nodestack();
  rchandle<expr> e2 = pop_nodestack();

  function* f = NULL;
  switch (v.get_mult_op())
  {
  case ParseConstants::op_mul:
    f = GET_BUILTIN_FUNCTION(OP_MULTIPLY_2);
    break;
  case ParseConstants::op_div:
    f = GET_BUILTIN_FUNCTION(OP_DIVIDE_2);
    break;
  case ParseConstants::op_idiv:
    f = GET_BUILTIN_FUNCTION(OP_INTEGER_DIVIDE_2);
    break;
  case ParseConstants::op_mod:
    f = GET_BUILTIN_FUNCTION(OP_MOD_2);
    break;
  }

  fo_expr* foExpr = new fo_expr(theRootSctx, loc, f, e2, e1);

  normalize_fo(foExpr);

  push_nodestack(foExpr);
}


/*******************************************************************************
  UnionExpr ::= IntersectExceptExpr (("union" | "|") IntersectExceptExpr)*
********************************************************************************/
void* begin_visit(const UnionExpr& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const UnionExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  rchandle<expr> e1 = pop_nodestack();
  rchandle<expr> e2 = pop_nodestack();

  fo_expr* foExpr = new fo_expr(theRootSctx,
                                loc,
                                GET_BUILTIN_FUNCTION(OP_UNION_2),
                                e2,
                                e1);

  normalize_fo(foExpr);

  // Union is implemented by a concat iterator, so we have to do node sorting
  // and duplicate elimi
  push_nodestack(new fo_expr(theRootSctx,
                             loc,
                             GET_BUILTIN_FUNCTION(OP_SORT_DISTINCT_NODES_ASC_1),
                             foExpr));
}


/*******************************************************************************
  IntersectExceptExpr ::= InstanceofExpr
                          (("intersect" | "except") InstanceofExpr)*
********************************************************************************/
void* begin_visit(const IntersectExceptExpr& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const IntersectExceptExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  rchandle<expr> e1 = pop_nodestack();
  rchandle<expr> e2 = pop_nodestack();

  function* f = NULL;
  switch (v.get_intex_op())
  {
  case ParseConstants::op_intersect:
    f = GET_BUILTIN_FUNCTION(OP_INTERSECT_2);
    break;
  case ParseConstants::op_except:
    f = GET_BUILTIN_FUNCTION(OP_EXCEPT_2);
    break;
  }

  fo_expr* foExpr = new fo_expr(theRootSctx, loc, f, e2, e1);

  normalize_fo(foExpr);

  push_nodestack(new fo_expr(theRootSctx,
                             loc,
                             GET_BUILTIN_FUNCTION(OP_SORT_DISTINCT_NODES_ASC_1),
                             foExpr));
}


/*******************************************************************************
  InstanceofExpr ::= TreatExpr ( "instance" "of" SequenceType )?
********************************************************************************/
void* begin_visit(const InstanceofExpr& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit (const InstanceofExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  push_nodestack(new instanceof_expr(theRootSctx,
                                     loc,
                                     pop_nodestack(),
                                     pop_tstack()));
}


/*******************************************************************************
  TreatExpr ::= CastableExpr ( "treat" "as" SequenceType )?
********************************************************************************/
void* begin_visit(const TreatExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const TreatExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  push_nodestack(new treat_expr(theRootSctx,
                                loc,
                                pop_nodestack(),
                                pop_tstack(),
                                err::XPDY0050));
}


/*******************************************************************************
  CastableExpr ::= CastExpr ( "castable" "as" SingleType )?
********************************************************************************/
void* begin_visit(const CastableExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CastableExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  push_nodestack(create_cast_expr(loc, pop_nodestack(), pop_tstack(), false));
}


expr_t create_cast_expr(const QueryLoc& loc, expr_t node, xqtref_t type, bool isCast)
{
  TypeManager* tm = CTX_TM;

  if (TypeOps::is_equal(tm, *type, *GENV_TYPESYSTEM.NOTATION_TYPE_ONE, loc) ||
      TypeOps::is_equal(tm, *type, *GENV_TYPESYSTEM.NOTATION_TYPE_QUESTION, loc) ||
      TypeOps::is_equal(tm, *type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE, loc) ||
      TypeOps::is_equal(tm, *type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION, loc))
  {
    RAISE_ERROR(err::XPST0080, loc, ERROR_PARAMS(type->toString()));
  }

  if (TypeOps::is_subtype(tm, *type, *GENV_TYPESYSTEM.QNAME_TYPE_QUESTION, loc))
  {
    const const_expr* ce = node.dyn_cast<const_expr>().getp();

    if (ce != NULL &&
        TypeOps::is_equal(tm,
                          *tm->create_value_type(ce->get_val()),
                          *GENV_TYPESYSTEM.STRING_TYPE_ONE,
                          loc))
    {
      store::Item_t castLiteral;
      try
      {
        GenericCast::instance()->castToQName(castLiteral,
                                             ce->get_val(),
                                             theNSCtx,
                                             false,
                                             CTX_TM,
                                             loc);
      }
      catch (ZorbaException& e)
      {
        if (isCast)
        {
          throw;
        }
        else
        {
          if (e.diagnostic() == err::FORG0001)
            throw;// XQUERY_EXCEPTION(err::XPST0003, ERROR_LOC(loc));
          else
            RAISE_ERROR(err::XPST0081, loc,
            ERROR_PARAMS(castLiteral->getStringValue()));
        }
      }

      assert(castLiteral != NULL || ! isCast);

      if (isCast)
        return new const_expr(theRootSctx, loc, castLiteral);
      else
        return new const_expr(theRootSctx, loc, castLiteral != NULL);
    }
    else
    {
      xqtref_t qnameType = (type->get_quantifier() == TypeConstants::QUANT_ONE ?
                            GENV_TYPESYSTEM.QNAME_TYPE_ONE :
                            GENV_TYPESYSTEM.QNAME_TYPE_QUESTION);

      // when casting to type T, where T is QName or subtype of, and the input
      // is not a const expr, then the input MUST be of type T or subtype of.
      if (isCast)
        return new treat_expr(theRootSctx, loc, node, qnameType, err::XPTY0004);
      else
        return new instanceof_expr(theRootSctx, loc, node, qnameType);
    }
  }
  else
  {
    if (isCast)
      return new cast_expr(theRootSctx, loc, wrap_in_atomization(node), type);
    else
      return new castable_expr(theRootSctx, loc, wrap_in_atomization(node), type);
  }
}


/*******************************************************************************
  CastExpr ::= UnaryExpr ( "cast" "as" SingleType )?
********************************************************************************/
void* begin_visit(const CastExpr& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const CastExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  push_nodestack(create_cast_expr(loc, pop_nodestack(), pop_tstack(), true));
}


/*******************************************************************************
  UnaryExpr ::= ("-" | "+")* ValueExpr
********************************************************************************/
void* begin_visit(const UnaryExpr& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const UnaryExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  rchandle<expr> e1 = pop_nodestack();

  fo_expr* foExpr = new fo_expr(theRootSctx,
                                loc,
                                (v.get_signlist()->get_sign() ?
                                 GET_BUILTIN_FUNCTION(OP_UNARY_PLUS_1) :
                                 GET_BUILTIN_FUNCTION(OP_UNARY_MINUS_1)),
                                e1);
  normalize_fo(foExpr);

  push_nodestack(foExpr);
}


void* begin_visit(const SignList& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const SignList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  ValueExpr ::= ValidateExpr | PathExpr | ExtensionExpr
********************************************************************************/


/*******************************************************************************
  ValidateExpr ::= "validate" (ValidationMode | ("as" TypeName))? "{" Expr "}"
  ValidationMode ::= "lax" | "strict"
********************************************************************************/
void* begin_visit(const ValidateExpr& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const ValidateExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  store::Item_t qname;
  if (v.get_type_name() != NULL)
  {
    const zstring& prefix = v.get_type_name()->get_prefix();
    zstring ns;
    theNSCtx->findBinding(prefix, ns);

    GENV_ITEMFACTORY->createQName(qname,
                                  ns.c_str(),
                                  prefix.c_str(),
                                  v.get_type_name()->get_localname().c_str());
  }

  push_nodestack(new validate_expr(theRootSctx,
                                   loc,
                                   v.get_valmode(),
                                   qname,
                                   pop_nodestack(),
                                   theSctx->get_typemanager()));
}


/*******************************************************************************
  ExtensionExpr ::= PragmaList "{" Expr? "}"
********************************************************************************/
void* begin_visit(const ExtensionExpr& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const ExtensionExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
  if (v.get_expr() == NULL)
    throw XQUERY_EXCEPTION( err::XQST0079, ERROR_LOC(loc) );
}


/*******************************************************************************
  PragmaList ::= Pragma | PragmaList  Pragma
********************************************************************************/
void* begin_visit(const PragmaList& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const PragmaList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  Pragma ::= "(#" S? QName (S PragmaContents)? "#)"  // ws: explicitXQ
  PragmaContents ::= (Char* - (Char* '#)' Char*))
********************************************************************************/
void* begin_visit(const Pragma& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const Pragma& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  // may raise XPST0081
  if (!v.get_name()->is_eqname())
  {
    zstring ns;
    theSctx->lookup_ns(ns, v.get_name()->get_prefix(), loc);
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  PathExpr                                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

  Path Expressions

  PathExpr ::= ("/" RelativePathExpr?) |
               ("//" RelativePathExpr) |
               RelativePathExpr 	// gn: leading-lone-slashXQ

  RelativePathExpr ::= StepExpr (("/" | "//") StepExpr)*

  StepExpr ::= PostfixExpr | AxisStep

  AxisStep ::= (ReverseStep | ForwardStep) PredicateList

  ForwardStep ::= (ForwardAxis NodeTest) | AbbrevForwardStep

  ForwardAxis ::= ("child" "::") |
                  ("descendant" "::") |
                  ("attribute" "::") |
                  ("self" "::") |
                  ("descendant-or-self" "::") |
                  ("following-sibling" "::") |
                  ("following" "::")

  AbbrevForwardStep ::= "@"? NodeTest

  ReverseStep ::= (ReverseAxis NodeTest) | AbbrevReverseStep

  ReverseAxis ::= ("parent" "::") |
                  ("ancestor" "::") |
                  ("preceding-sibling" "::") |
                  ("preceding" "::") |
                  ("ancestor-or-self" "::")

  AbbrevReverseStep ::= ".."

  NodeTest ::= KindTest | NameTest

  NameTest ::= QName | Wildcard

  Wildcard ::= "*" | (NCName ":" "*") | ("*" ":" NCName)

  PostfixExpr ::= PrimaryExpr (Predicate | ArgumentList)*

  PredicateList ::= Predicate*

  Predicate ::= "[" Expr "]"


  If a path expr is actually a standalone filter expr, then no PathExpr parsenode
  (and parse subtree) is generated. Otherwise, the syntax tree for a generic
  PathExpr looks like this:

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

  In cases 2 and 3 step1 is missing, i.e., the syntax tree is like this:

       PathExpr
           |
         rpe1
        /    \
      NULL   rpe2
            /    \
          step2  rpe3
                /    \
              step3  step4

  where, the type of PathExpr is path_relative and rpe1 designates a "/". In
  these cases, the translator behaves as if step1 was either
  fn:root(./self::node()) in case 2, or
  fn:root(./self::node())/descendant-or-self::node() in case 3.

  In general, a path expression is translated into a combination of relpath_exprs
  and flwor_exprs. relpath_exprs are created to represent the portions of a path
  expression whose steps consist of AxisSteps with no predicates. flwor_exprs
  are are created to represent steps that are FilterExprs or AxisSteps with
  predicates.

  For example, the expr:

  sourceExpr/a/b/c[predExpr]/d

  is translated into:

  (
  for $dot1 in sourceExpr/a/b
  let $temp := $dot1/c
  return for $dot2 at $pos in $temp
         return if (predExpr instance of numeric)
                then if ($pos eq predExpr) then $dot2 else ()
                else if (predExpr) then $dot2 else ()
  )/d


  If predExpr is a numeric constant, then during optimization the above flwor
  will go through the following rewrites:

  for $dot1 in sourceExpr/a/b
  let $temp := $dot1/c
  return for $dot2 at $pos in $temp
         return if ($pos eq predExpr) then $dot2 else ()

  for $dot1 in sourceExpr/a/b
  let $temp := $dot1/c
  return for $dot2 at $pos in $temp
         where ($pos eq predExpr)
         return $dot2

  for $dot1 in sourceExpr/a/b
  let $temp := $dot1/c
  return for $dot2 in subsequence($temp, predExpr, 1)
         return $dot2

  for $dot1 in sourceExpr/a/b
  return for $dot2 in subsequence($dot1/c, predExpr, 1)
         return $dot2
********************************************************************************/
void* begin_visit(const PathExpr& v)
{
  TRACE_VISIT();

  const PathExpr& pe = v;

  ParseConstants::pathtype_t pe_type = pe.get_type();

  rchandle<relpath_expr> pathExpr = NULL;

  // Put a NULL in the stack to mark the beginning of a PathExp tree.
  push_nodestack(NULL);

  theNodeSortStack.push(NodeSortInfo());

  // In cases 2, 3, and 4 create a new empty relpath_expr
  if (pe_type != ParseConstants::path_leading_lone_slash)
  {
    pathExpr = new relpath_expr(theRootSctx, loc);
  }

  // If path expr starts with / or // (cases 1, 2, or 3), create an expr
  // R = fn:root(./self::node()).
  //
  // In case 1, just push R to the nodestack.
  //
  // In case 2 and 3, put empty relpath_expr and R to the nodestact
  //
  // In case 4, put empty relpath_expr to the nodestack

  if (pe_type != ParseConstants::path_relative)
  {
    rchandle<relpath_expr> ctx_path_expr = new relpath_expr(theRootSctx, loc);

    expr_t sourceExpr = new treat_expr(theRootSctx,
                                       loc,
                                       DOT_REF,
                                       GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
                                       err::XPTY0020);

    ctx_path_expr->add_back(sourceExpr);

    rchandle<match_expr> me = new match_expr(theRootSctx, loc);
    me->setTestKind(match_anykind_test);
    rchandle<axis_step_expr> ase = new axis_step_expr(theRootSctx, loc);
    ase->setAxis(axis_kind_self);
    ase->setTest(me);

    ctx_path_expr->add_back(&*ase);

    fo_expr_t fnroot = new fo_expr(theRootSctx,
                                   loc,
                                   GET_BUILTIN_FUNCTION(FN_ROOT_1),
                                   ctx_path_expr.getp());
    normalize_fo(fnroot);

    if (pathExpr != NULL)
    {
      // cases 2 or 3
      push_nodestack(pathExpr.getp());
      push_nodestack(fnroot.getp());

      theNodeSortStack.top().theNumSteps++;
    }
    else
    {
      // case 1
      expr_t result = new treat_expr(theRootSctx,
                                     loc,
                                     fnroot.getp(),
                                     GENV_TYPESYSTEM.DOCUMENT_TYPE_ONE,
                                     err::XPDY0050);
      push_nodestack(result.getp());
    }
  }
  else
  {
    // case 4
    push_nodestack(pathExpr.getp());
  }

  return no_state;
}


void end_visit(const PathExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t arg2 = pop_nodestack();
  expr_t arg1 = pop_nodestack();

  ZORBA_ASSERT(arg1 == NULL);

#ifdef NODE_SORT_OPT
  NodeSortInfo& nodeSortInfo = theNodeSortStack.top();

  if (!nodeSortInfo.theSingleInput ||
      nodeSortInfo.theHaveFilterSteps ||
      (nodeSortInfo.theNumSteps > 1 && !nodeSortInfo.theOnlyChildAxes))
  {
    // wrap in atomics_or_node_distinc_sort_asc
    push_nodestack(wrap_in_dos_and_dupelim(arg2, true));
  }
  else
  {
    rchandle<fo_expr> checkExpr =
      new fo_expr(theRootSctx,
                  arg2->get_loc(),
                  GET_BUILTIN_FUNCTION(OP_EITHER_NODES_OR_ATOMICS_1),
                  arg2);

    push_nodestack(checkExpr.getp());
  }
#else
  // wrap in atomics_or_node_distinc_sort_asc
  push_nodestack(wrap_in_dos_and_dupelim(arg2, true));
#endif

  theNodeSortStack.pop();
}


/*******************************************************************************

  [92] RelativePathExpr ::= StepExpr (("/" | "//") StepExpr)*

  Note: If a RelativePathExpr consists of a single StepExpr, a RelativePathExpr
  node is generated whose left child is a ContextItemExpr and its right child
  is the StepExpr.

********************************************************************************/
void* begin_visit(const RelativePathExpr& v)
{
  TRACE_VISIT();

  const RelativePathExpr& rpe = v;

  rchandle<exprnode> step = rpe.get_step_expr();

  if (step == NULL)
    return no_state;

  AxisStep* axisStep = step.dyn_cast<AxisStep>();

  // Let rpe be the i-th rpe in the Path Tree. Then pathExpr represents the
  // translation of step-1/.../step-(i-1)/.
  expr_t e = pop_nodestack();
  relpath_expr* pathExpr = e.dyn_cast<relpath_expr>();
  ZORBA_ASSERT(pathExpr != NULL);

  // If case 4 and i = 1, then pathExpr is empty.
  if (pathExpr->size() == 0)
  {
    // If the path expr is of the form "axis::test/...." or "axis::test[pred]/...."
    // then the input expr to the this path expr is "treat . as node()"
    if (axisStep != NULL)
    {
      expr_t sourceExpr = new treat_expr(theRootSctx,
                                         loc,
                                         DOT_REF,
                                         GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
                                         err::XPTY0020);
      pathExpr->add_back(sourceExpr);

      if (axisStep->get_predicate_list() == NULL)
      {
        // "axis::test/...." ==> push [ pathExpr(sourceExpr) ] to the nodestack.
        push_nodestack(pathExpr);
      }
      else
      {
        // "axis::test[pred]/...." ==> push [ for $dot at $pos in pathExpr(sourceExpr) ]
        // to the nodestack.
        rchandle<flwor_expr> flworExpr = wrap_expr_in_flwor(pathExpr, false);
        push_nodestack(flworExpr.getp());
      }
    }
    // "source_expr/...." ==> push pathExpr() to the nodestack.
    else
    {
      push_nodestack(pathExpr);
    }
  }

  // Else if step-i is an axis step with no repdicates, just put pathExpr(...)
  // back in the stack.
  else if (axisStep != NULL && axisStep->get_predicate_list() == NULL)
  {
    push_nodestack(pathExpr);
  }

  // Else, step-i is an axis step with predicates or a filter expr, and is not
  // the very 1st step in the path expr. In this case, pathExpr becomes the
  // input to a new flwor expr that will compute, once for each node in pathExpr,
  // the next step in the path. In particular, the following expr is pushed to
  // the stack:
  //
  // [ for $$dot at $$pos in node_distinc_sort_asc(pathExpr) ]
  else
  {
    expr_t inputExpr = wrap_in_dos_and_dupelim(pathExpr, true);
    rchandle<flwor_expr> flworExpr = wrap_expr_in_flwor(inputExpr, false);
    push_nodestack(flworExpr.getp());
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

#ifdef NODE_SORT_OPT
    if (pathExpr->size() == 0)
    {
      Error const *errCode = &err::XPTY0019;

      if (stepExpr->get_expr_kind() == wrapper_expr_kind)
      {
        wrapper_expr* tmp = static_cast<wrapper_expr*>(stepExpr.getp());
        var_expr* dotVar = lookup_var(DOT_VARNAME, loc, zerr::ZXQP0000_NO_ERROR);
        if (tmp->get_expr() == dotVar)
          errCode = &err::XPTY0020;
      }

      expr_t sourceExpr = new treat_expr(theRootSctx,
                                         stepExpr->get_loc(),
                                         stepExpr,
                                         GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
                                         *errCode);

      if (TypeOps::type_max_cnt(pathExpr->get_type_manager(),
                                *sourceExpr->get_return_type()) > 1)
        theNodeSortStack.top().theSingleInput = false;

      pathExpr->add_back(sourceExpr);
    }
    else
    {
      pathExpr->add_back(stepExpr);
    }
#else
    pathExpr->add_back(stepExpr);
#endif
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

    pathExpr = new relpath_expr(theRootSctx, loc);

    expr_t sourceExpr = flworExpr;

    // If step-i was a reverse axis with predicates, we must reorder the
    // result of flworExpr because it is going to be produced in reverse
    // doc order.
    AxisStep* axisStep = dynamic_cast<AxisStep*>(rpe.get_step_expr().getp());
    if (axisStep != NULL && axisStep->get_reverse_step() != NULL)
    {
      sourceExpr = wrap_in_dos_and_dupelim(sourceExpr, true);
    }

    if (axisStep == NULL)
      theNodeSortStack.top().theHaveFilterSteps = true;

    pathExpr->add_back(sourceExpr);
  }

  // Convert // to /descendant-or-self::node()/
  if (rpe.get_step_type() == ParseConstants::st_slashslash)
  {
    rchandle<axis_step_expr> ase = new axis_step_expr(theRootSctx, loc);
    rchandle<match_expr> me = new match_expr(theRootSctx, loc);
    me->setTestKind(match_anykind_test);
    ase->setAxis(axis_kind_descendant_or_self);
    ase->setTest(me);
    pathExpr->add_back(ase.getp());

    theNodeSortStack.top().theNumSteps++;
    theNodeSortStack.top().theOnlyChildAxes = false;
  }

  rchandle<exprnode> child2 = rpe.get_relpath_expr();
  ZORBA_ASSERT(child2 != NULL);
  AxisStep* axisStep = child2.dyn_cast<AxisStep>();

  // If the second child of rpe-i is another rpe or an axis step with no
  // predicates, then we push the current path_expr to the stack.
  if (child2.dyn_cast<RelativePathExpr>() != NULL ||
      (axisStep != NULL && axisStep->get_predicate_list() == NULL))
  {
    push_nodestack(pathExpr);
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
    push_nodestack(flworExpr.getp());
  }
}


void end_visit(const RelativePathExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

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

  axis_step_expr* axisExpr = stepExpr.dyn_cast<axis_step_expr>();
  relpath_expr* pathExpr = curExpr.dyn_cast<relpath_expr>();
  flwor_expr* flworExpr = curExpr.dyn_cast<flwor_expr>();

  // If curExpr is a path expr, step-(i+1) was an axis step with no predicates.
  if (pathExpr != NULL)
  {
    ZORBA_ASSERT(axisExpr != NULL);

    pathExpr->add_back(stepExpr);
    push_nodestack(pathExpr);
  }
  else
  {
    ZORBA_ASSERT(flworExpr != NULL);
    ZORBA_ASSERT(stepExpr != NULL);

    if (child2.dyn_cast<AxisStep>() == NULL)
      theNodeSortStack.top().theHaveFilterSteps = true;

    flworExpr->set_return_expr(stepExpr);
    pop_scope();

    push_nodestack(flworExpr);
  }
}


/*******************************************************************************
  StepExpr ::= PostfixExpr | AxisStep
********************************************************************************/


/*******************************************************************************
  AxisStep ::= (ReverseStep | ForwardStep) PredicateList
********************************************************************************/
void* begin_visit(const AxisStep& v)
{
  TRACE_VISIT();

  rchandle<axis_step_expr> ase = new axis_step_expr(theRootSctx, loc);
  push_nodestack(ase.getp());

  theNodeSortStack.top().theNumSteps++;

  return no_state;
}


/*******************************************************************************
  This method is called from AxisStep::accept() after the step itself is
  translated, but before the associated predicate list (if any) is translated.
********************************************************************************/
void post_axis_visit(const AxisStep& v, void* /*visit_state*/)
{
  expr_t e = pop_nodestack();
  rchandle<axis_step_expr> axisExpr = e.dyn_cast<axis_step_expr>();
  ZORBA_ASSERT(axisExpr != NULL);
  axis_kind_t axisKind = axisExpr->getAxis();

  if (axisKind != axis_kind_child)
    theNodeSortStack.top().theOnlyChildAxes = false;

  PredicateList* pl = v.get_predicate_list().getp();

  // Nothing to do if there are no predicates
  if (pl == NULL || pl->size() == 0)
  {
    push_nodestack(e);
    return;
  }

  const QueryLoc& loc = v.get_location();

  e = pop_nodestack();
  flwor_expr* flworExpr = e.dyn_cast<flwor_expr>();
  ZORBA_ASSERT(flworExpr != NULL);

  // The flworExpr was created in begin_visit(const RelativePathExpr& v), and
  // it is of the form:
  //
  // [ for $$dot at $$pos in node_distinc_sort_asc(pathExpr-(i-1)) ]
  //
  // Here, we add a let clause to the flworExpr:
  //
  // [ for $$dot at $$pos in node_distinc_sort_asc(pathExpr-(i-1))
  //   let $$predInput := $$dot/axis::test ]
  //
  // Furthermore, if it is a reverse axis, we set theReverseOrder flag of the
  // axist_step_expr to true
  //
  // The $$predInput var will compute and store for each $$dot, the input seq for
  // the preds that follow the axis step.
  //
  // The flworExpr as well as the $$predInput varExpr are pushed to the nodestack.
  const for_clause* fcOuterDot = reinterpret_cast<const for_clause*>((*flworExpr)[0]);
  rchandle<relpath_expr> predPathExpr = new relpath_expr(theRootSctx, loc);
  predPathExpr->add_back(new wrapper_expr(theRootSctx, loc, fcOuterDot->get_var()));
  predPathExpr->add_back(axisExpr.getp());

  expr_t predInputExpr = predPathExpr;

  if (axisExpr->is_reverse_axis())
  {
    axisExpr->set_reverse_order();
  }

  rchandle<let_clause> lcPredInput = wrap_in_letclause(predInputExpr.getp());

  flworExpr->add_clause(lcPredInput);

  push_nodestack(flworExpr);
  push_nodestack(lcPredInput->get_var());
}


void end_visit(const AxisStep& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  ForwardStep ::= (ForwardAxis NodeTest) | AbbrevForwardStep
********************************************************************************/
void* begin_visit(const ForwardStep& v)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const ForwardStep& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  AbbrevForwardStep ::= "@"? NodeTest
********************************************************************************/
void* begin_visit(const AbbrevForwardStep& v)
{
  TRACE_VISIT();

  rchandle<axis_step_expr> ase = expect_axis_step_top();

  if (v.get_attr_bit())
  {
    ase->setAxis(axis_kind_attribute);
  }
  else
  {
    const parsenode* nodeTest = v.get_node_test();

    if (dynamic_cast<const AttributeTest*>(nodeTest) == NULL &&
        dynamic_cast<const SchemaAttributeTest*>(nodeTest) == NULL)
    {
      ase->setAxis(axis_kind_child);
    }
    else
    {
      ase->setAxis(axis_kind_attribute);
    }
  }

  return no_state;
}


void end_visit(const AbbrevForwardStep& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  ReverseStep ::= (ReverseAxis NodeTest) | AbbrevReverseStep
  AbbrevReverseStep ::= ".."
********************************************************************************/
void* begin_visit(const ReverseStep& v)
{
  TRACE_VISIT();
  return no_state;
}


void end_visit(const ReverseStep& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************

********************************************************************************/
void* begin_visit(const ForwardAxis& v)
{
  TRACE_VISIT();
  return no_state;
}


void end_visit(const ForwardAxis& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

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
  default:
    ZORBA_ASSERT(false);
  }
}


/*******************************************************************************

********************************************************************************/
void* begin_visit(const ReverseAxis& v)
{
  TRACE_VISIT();
  return no_state;
}


void end_visit(const ReverseAxis& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

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
  default:
    ZORBA_ASSERT(false);
  }
}


/*******************************************************************************
  NodeTest ::= KindTest | NameTest
********************************************************************************/


/*******************************************************************************
  NameTest ::= QName | Wildcard
********************************************************************************/
void* begin_visit (const NameTest& v)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const NameTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr* top = theNodeStack.top().getp();

  axis_step_expr* axisExpr = NULL;
  trycatch_expr* tce = NULL;

  if ((axisExpr = dynamic_cast<axis_step_expr *>(top)) != NULL)
  {
    // Construct name-test match expr
    rchandle<match_expr> matchExpr = new match_expr(theRootSctx, loc);;
    matchExpr->setTestKind(match_name_test);

    if (v.getQName() != NULL)
    {
      store::Item_t qnItem;

      if (axisExpr->getAxis() == axis_kind_attribute)
      {
        expand_no_default_qname(qnItem, v.getQName(), v.getQName()->get_location());
      }
      else
      {
        expand_elem_qname(qnItem, v.getQName(), v.getQName()->get_location());
      }

      matchExpr->setQName(qnItem);
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
        matchExpr->setWildName(wildcard->getNsOrPrefix());

        zstring localname(":wildcard");
        store::Item_t qnItem;
        zstring ns;
        zstring prefix = wildcard->getNsOrPrefix();

        if (axisExpr->getAxis() != axis_kind_attribute)
        {
          ns = theSctx->default_elem_type_ns();
          if (wildcard->isEQnameMatch())
          {
            ns = prefix;
            prefix = zstring();
          }
        }

        theSctx->expand_qname(qnItem,
            ns,
            prefix,
            localname,
            wildcard->get_location());

        matchExpr->setQName(qnItem);

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
    catch_clause* cc = &*(*tce)[0];
    if (v.getQName() != NULL)
    {
      store::Item_t qnItem;
      expand_elem_qname(qnItem, v.getQName(), loc);

      cc->add_nametest_h(new NodeNameTest(qnItem));
    }
    else
    {
      rchandle<Wildcard> wildcard = v.getWildcard();
      ZORBA_ASSERT(wildcard != NULL);


      switch (wildcard->getKind())
      {
        case ParseConstants::wild_all:
          cc->add_nametest_h(new NodeNameTest(zstring(), zstring()));
          break;
        case ParseConstants::wild_elem: {
          // bugfix #3138633; expand the qname and use the namespace instead of the prefix
          zstring localname(":wildcard");
          store::Item_t qnItem;
          theSctx->expand_qname(qnItem,
                                theSctx->default_elem_type_ns(),
                                wildcard->getNsOrPrefix(),
                                localname,
                                wildcard->get_location());
          cc->add_nametest_h(new NodeNameTest(qnItem->getNamespace(), zstring()));
          break;
        }
        case ParseConstants::wild_prefix:
          cc->add_nametest_h(new NodeNameTest(zstring(), wildcard->getLocalName()));
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
  Wildcard ::= "*" | (NCName ":" "*") | ("*" ":" NCName)
********************************************************************************/
void* begin_visit(const Wildcard& v)
{
  TRACE_VISIT();
  return no_state;
}


void end_visit(const Wildcard& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  PostfixExpr ::= PrimaryExpr (Predicate | ArgumentList)*
********************************************************************************/
void* begin_visit(const FilterExpr& v)
{
  TRACE_VISIT();

  return no_state;
}


void post_primary_visit(const FilterExpr& v, void* /*visit_state*/)
{
  // This method is called from FilterExpr::accept() after the primary expr is
  // translated, but before the associated predicate list, if any, is translated.

  // Nothing to do if this is a standalone filter expr (i.e., it does not appear
  // as a step of a path expr).
  if (!v.isPathStep())
    return;

  theNodeSortStack.top().theHaveFilterSteps = true;

  PredicateList* pl = v.get_pred_list().getp();

  ZORBA_ASSERT(pl != NULL && pl->size() > 0);

  expr_t primaryExpr = pop_nodestack();
  expr_t e = pop_nodestack();
  flwor_expr* flworExpr = e.dyn_cast<flwor_expr>();

  // If this filter expr is not the 1st step of a path expr, ...
  if (flworExpr != NULL)
  {
    // for each item in the input seq compute the input seq for the pred
    // (= outer_dot/primaryExpr)
    let_clause_t lcPredSeq = wrap_in_letclause(primaryExpr.getp());

    flworExpr->add_clause(lcPredSeq);

    push_nodestack(flworExpr);
    push_nodestack(lcPredSeq->get_var());
  }

  // Else, this filter expr is the very first step (i.e., the source expr) of
  // a path expr.
  else
  {
     relpath_expr* pathExpr = e.dyn_cast<relpath_expr>();
     ZORBA_ASSERT(pathExpr != NULL && pathExpr->size() == 0);

     push_nodestack(pathExpr);
     push_nodestack(primaryExpr);
  }
}


void end_visit(const FilterExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  PredicateList ::= Predicate*
  Predicate ::= "[" Expr "]"
********************************************************************************/
void* begin_visit(const PredicateList& v)
{
  TRACE_VISIT();
  return no_state;
}


void end_visit(const PredicateList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


void pre_predicate_visit(const PredicateList& v, void* /*visit_state*/)
{
  // This method is called from PredicateList::accept(), before calling accept()
  // on each predicate in the list

  // get the predicate input seq
  expr_t inputSeqExpr = pop_nodestack();

  //  let $$temp := predInputSeq
  //  let $$last-idx := count($$temp)
  //  for $$dot at $$pos in $$temp
  rchandle<flwor_expr> flworExpr = wrap_expr_in_flwor(inputSeqExpr, true);

  push_nodestack(flworExpr.getp());
}


void post_predicate_visit(const PredicateList& v, void* /*visit_state*/)
{
  // This method is called from PredicateList::accept(), after calling accept()
  // on each predicate in the list

  RootTypeManager& rtm = GENV_TYPESYSTEM;

  expr_t predExpr = pop_nodestack();

  expr_t f = pop_nodestack();
  flwor_expr* flworExpr = f.dyn_cast<flwor_expr>();
  ZORBA_ASSERT(flworExpr != NULL);

  const QueryLoc& loc = predExpr->get_loc();

  // let $predVar := predExpr
  let_clause_t lcPred = wrap_in_letclause(predExpr);
  var_expr* predvar = lcPred->get_var();

  flworExpr->add_clause(lcPred);

  // Construct the return expr of the flworExpr:
  //
  // if ($predVar instance-of xs:decimal or
  //     $predVar instance-of xs:double or
  //     $predVar instance-of xs:float)
  // then
  //   if (fn:boolean($dot_pos eq $predVar) then $dot else ()
  // else
  //   if (fn:boolean($predVar) then $dot else ()

  // Check if the pred expr returns a numeric result
  fo_expr_t condExpr;
  std::vector<expr_t> condOperands(3);

  condOperands[0] =
  new instanceof_expr(theRootSctx, loc, predvar, rtm.DECIMAL_TYPE_QUESTION, true);

  condOperands[1] =
  new instanceof_expr(theRootSctx, loc, predvar, rtm.DOUBLE_TYPE_QUESTION, true);

  condOperands[2] =
  new instanceof_expr(theRootSctx, loc, predvar, rtm.FLOAT_TYPE_QUESTION, true);

  condExpr = new fo_expr(theRootSctx, loc, GET_BUILTIN_FUNCTION(OP_OR_N), condOperands);

  // If so: return $dot if the value of the pred expr is equal to the value
  // of $dot_pos var, otherwise return the empty seq.
  fo_expr_t eqExpr = new fo_expr(theRootSctx,
                                 loc,
                                 GET_BUILTIN_FUNCTION(OP_VALUE_EQUAL_2),
                                 lookup_ctx_var(DOT_POS_VARNAME, loc),
                                 predvar);
  normalize_fo(eqExpr);

  expr_t thenExpr = new if_expr(theRootSctx,
                                loc,
                                eqExpr.getp(),
                                DOT_REF,
                                create_empty_seq(loc));

  // Else, return $dot if the the value of the pred expr is true, otherwise
  // return the empty seq.
  expr_t elseExpr = new if_expr(theRootSctx,
                                loc,
                                predvar,
                                DOT_REF,
                                create_empty_seq(loc));

  // The outer if
  expr_t ifExpr = new if_expr(theRootSctx, loc, condExpr.getp(), thenExpr, elseExpr);

  flworExpr->set_return_expr(ifExpr);

  push_nodestack(flworExpr);

  pop_scope();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Primary                                                                    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  PrimaryExpr ::= Literal |
                  VarRef |
                  ParenthesizedExpr |
                  ContextItemExpr |
                  FunctionCall |
                  OrderedExpr |
                  UnorderedExpr |
                  Constructor |
                  FunctionItemExpr
********************************************************************************/


/*******************************************************************************
  Literal ::= NumericLiteral | StringLiteral
********************************************************************************/
void* begin_visit(const Literal& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const Literal& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  NumericLiteral ::= IntegerLiteral | DecimalLiteral | DoubleLiteral

  IntegerLiteral ::= Digits

  DecimalLiteral :: ("." Digits) | (Digits "." [0-9]*)

  DoubleLiteral ::= (("." Digits) | (Digits ("." [0-9]*)?)) [eE] [+-]? Digits
********************************************************************************/
void* begin_visit(const NumericLiteral& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const NumericLiteral& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  switch (v.get_type())
  {
  case ParseConstants::num_integer:
  {
    push_nodestack(new const_expr(theRootSctx, loc, v.get<xs_integer>()));
    break;
  }
  case ParseConstants::num_decimal:
  {
    push_nodestack(new const_expr(theRootSctx, loc, v.get<xs_decimal>()));
    break;
  }
  case ParseConstants::num_double:
  {
    push_nodestack(new const_expr(theRootSctx, loc, v.get<xs_double>()));
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
void* begin_visit(const StringLiteral& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const StringLiteral& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  push_nodestack(new const_expr(theRootSctx, loc,v.get_strval().str()));
}


/*******************************************************************************
  VarRef ::= "$" VarName
  VarName ::= QName
********************************************************************************/
void* begin_visit(const VarRef& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const VarRef& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  var_expr* ve = NULL;

  try
  {
    ve = lookup_var(v.get_name(), loc, err::XPST0008);
  }
  catch (const ZorbaException& e)
  {
    if (e.diagnostic() == err::XPST0008 && theHaveModuleImportCycle)
    {
      store::Item_t qnameItem;
      expand_no_default_qname(qnameItem, v.get_name(), loc);

      const zstring& var_ns = qnameItem->getNamespace();

      std::map<zstring, zstring>::const_iterator ite = theModulesStack.begin();
      std::map<zstring, zstring>::const_iterator end = theModulesStack.end();

      --end;
      assert((*end).second == theModuleNamespace);

      for (; ite != end; ++ite)
      {
        if ((*ite).second == var_ns)
          RAISE_ERROR(err::XQST0093, loc, ERROR_PARAMS(theModuleNamespace));
      }
    }

    throw;
  }

  if (ve->get_kind() == var_expr::prolog_var)
  {
    TypeManager* tm = CTX_TM;

    xqtref_t declaredType = ve->get_type();

    if (declaredType != NULL && !TypeOps::is_in_scope(tm, *declaredType))
    {
      const Error& error = (declaredType->get_manager() == tm ?
                            err::XPTY0004 : err::XQST0036);

      if (theModuleNamespace.empty())
      {
        throw XQUERY_EXCEPTION_VAR(
          error,
          ERROR_PARAMS(
            ZED( BadType_23o ),
            *declaredType,
            ZED( NoTypeInMainModule_4 ),
            ve->get_name()->getStringValue()
          ),
          ERROR_LOC( loc )
        );
      }
      else
      {
        throw XQUERY_EXCEPTION_VAR(
          error,
          ERROR_PARAMS(
            ZED( BadType_23o ),
            *declaredType,
            ZED( NoTypeInModule_45 ),
            ve->get_name()->getStringValue(),
            theModuleNamespace
          ),
          ERROR_LOC( loc )
        );
      }
    }

    if (!theCurrentPrologVFDecl.isNull())
    {
      thePrologGraph.addEdge(theCurrentPrologVFDecl, ve);
    }
  }

  push_nodestack(new wrapper_expr(theRootSctx, loc, rchandle<expr>(ve)));
}


/*******************************************************************************
  ParenthesizedExpr ::= "(" Expr? ")"
********************************************************************************/
void* begin_visit(const ParenthesizedExpr& v)
{
  TRACE_VISIT();

  push_nodestack(NULL);
  return no_state;
}

void end_visit(const ParenthesizedExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t expr = pop_nodestack();

  if (expr != NULL)
  {
    pop_nodestack();
    push_nodestack(expr);
  }
  else
  {
    fo_expr* lSeq = create_empty_seq(loc);
    push_nodestack(lSeq);
  }
}


/*******************************************************************************
  ContextItemExpr ::= "."
********************************************************************************/
void* begin_visit(const ContextItemExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ContextItemExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  push_nodestack(DOT_REF);
}


/*******************************************************************************
  OrderedExpr ::= "ordered" "{" Expr "}"
********************************************************************************/
void* begin_visit(const OrderedExpr& v)
{
  TRACE_VISIT();

  return no_state;
}

void end_visit(const OrderedExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  push_nodestack(new order_expr(theRootSctx,
                                loc,
                                order_expr::ordered,
                                pop_nodestack()));
}


/*******************************************************************************
  UnorderedExpr ::= "unordered" "{" Expr "}"
********************************************************************************/
void* begin_visit(const UnorderedExpr& v)
{
  TRACE_VISIT();

  return no_state;
}

void end_visit(const UnorderedExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  push_nodestack(new order_expr(theRootSctx,
                                loc,
                                order_expr::unordered,
                                pop_nodestack()));
}


/*******************************************************************************
  FunctionCall ::= QName "(" ArgList? ")"
********************************************************************************/
void* begin_visit(const FunctionCall& v)
{
  TRACE_VISIT();

  rchandle<QName> qname = v.get_fname();

  ulong numArgs = 0;
  if (v.get_arg_list() != NULL)
    numArgs = v.get_arg_list()->size();

  function* f = lookup_fn(qname, numArgs, loc);

  // Note : f maybe NULL if it is a constructor of a builtin type

  if (f != NULL && f->getXQueryVersion() > theSctx->xquery_version())
  {
    zstring version =
    (f->getXQueryVersion() == StaticContextConsts::xquery_version_1_0 ? "1.0" : "3.0");

    throw XQUERY_EXCEPTION(err::XPST0017,
                           ERROR_PARAMS(f->getName()->getStringValue(),
                                        ZED(FnOnlyInXQueryVersion_3),
                                        version),
                           ERROR_LOC(loc));
  }

  if (f != NULL && !theCurrentPrologVFDecl.isNull())
  {
    if (f->isUdf())
      thePrologGraph.addEdge(theCurrentPrologVFDecl, f);
  }

  if (f != NULL && (f->isUdf() || f->isExternal()))
  {
    TypeManager* tm = CTX_TM;

    const signature& sign = f->getSignature();

    xqtref_t retType = sign.returnType();

    if (!TypeOps::is_in_scope(tm, *retType))
    {
      if (theModuleNamespace.empty())
      {
        RAISE_ERROR(err::XQST0036, loc,
        ERROR_PARAMS(ZED(BadType_23o),
                     *retType,
                     ZED(NoTypeInMainModule_4),
                     f->getName()->getStringValue()));
      }
      else
      {
        RAISE_ERROR(err::XQST0036, loc,
        ERROR_PARAMS(ZED(BadType_23o),
                     *retType,
                     ZED(NoTypeInModule_45),
                     f->getName()->getStringValue(),
                     theModuleNamespace));
      }
    }

    size_t numParams = f->getArity();

    for (ulong i = 0; i < numParams; ++i)
    {
      xqtref_t type = sign[i];
      if (!TypeOps::is_in_scope(tm, *type))
      {
        if (theModuleNamespace.empty())
        {
          RAISE_ERROR(err::XQST0036, loc,
          ERROR_PARAMS(ZED(BadType_23o),
                       *type,
                       ZED(NoTypeInMainModule_4),
                       f->getName()->getStringValue()));
        }
        else
        {
          RAISE_ERROR(err::XQST0036, loc,
          ERROR_PARAMS(ZED(BadType_23o),
                       *retType,
                       ZED(NoTypeInModule_45),
                       f->getName()->getStringValue(),
                       theModuleNamespace));
        }
      }
    }
  }

  push_nodestack(NULL);
  return no_state;
}

void end_visit(const FunctionCall& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  TypeManager* tm = CTX_TM;

  // Expand the function qname
  rchandle<QName> qname = v.get_fname();

  store::Item_t qnameItem;
  expand_function_qname(qnameItem, qname, loc);

  const zstring& fn_ns = qnameItem->getNamespace();

  if (static_context::is_reserved_module(fn_ns))
  {
    RAISE_ERROR(zerr::ZXQP0016_RESERVED_MODULE_TARGET_NAMESPACE, loc,
    ERROR_PARAMS(fn_ns));
  }

  // Collect the arguments of this function in reverse order
  std::vector<expr_t> arguments;

  while (true)
  {
    expr_t argExpr = pop_nodestack();

    if (argExpr == NULL)
      break;

    arguments.push_back(argExpr);
  }

  ulong numArgs = (ulong)arguments.size();

  function* f = lookup_fn(qname, numArgs, loc);

  if (fn_ns == static_context::W3C_FN_NS)
  {
    // Some special processing is required for certain "fn" functions
    if (f == NULL)
    {
      RAISE_ERROR(err::XPST0017, loc,
      ERROR_PARAMS(qname->get_qname(),
                   ZED(FunctionUndeclared_3),
                   numArgs));
    }

    switch (f->getKind())
    {
      case FunctionConsts::FN_HEAD_1:
      {
        arguments.push_back(new const_expr(theRootSctx, loc, xs_integer(1)));
        arguments.push_back(new const_expr(theRootSctx, loc, xs_integer(1)));
        function* f = GET_BUILTIN_FUNCTION(OP_ZORBA_SUBSEQUENCE_INT_3);
        fo_expr_t foExpr = new fo_expr(theRootSctx, loc, f, arguments);
        normalize_fo(foExpr);
        push_nodestack(foExpr.getp());
        return;
      }
      case FunctionConsts::FN_TAIL_1:
      {
        arguments.push_back(new const_expr(theRootSctx, loc, xs_integer(2)));
        function* f = GET_BUILTIN_FUNCTION(OP_ZORBA_SUBSEQUENCE_INT_2);
        fo_expr_t foExpr = new fo_expr(theRootSctx, loc, f, arguments);
        normalize_fo(foExpr);
        push_nodestack(foExpr.getp());
        return;
      }
      case FunctionConsts::FN_SUBSEQUENCE_2:
      case FunctionConsts::FN_SUBSEQUENCE_3:
      case FunctionConsts::FN_SUBSTRING_2:
      case FunctionConsts::FN_SUBSTRING_3:
      {
        std::reverse(arguments.begin(), arguments.end());

        xqtref_t posType = arguments[1]->get_return_type();

        if (numArgs == 2)
        {
          if (TypeOps::is_subtype(tm, *posType, *GENV_TYPESYSTEM.INTEGER_TYPE_STAR, loc))
          {
            if(f->getKind() == FunctionConsts::FN_SUBSTRING_2)
              f = GET_BUILTIN_FUNCTION(OP_SUBSTRING_INT_2);
            else
              f = GET_BUILTIN_FUNCTION(OP_ZORBA_SUBSEQUENCE_INT_2);
          }
        }
        else
        {
          xqtref_t lenType = arguments[2]->get_return_type();

          if (TypeOps::is_subtype(tm, *posType, *GENV_TYPESYSTEM.INTEGER_TYPE_STAR, loc) &&
              TypeOps::is_subtype(tm, *lenType, *GENV_TYPESYSTEM.INTEGER_TYPE_STAR, loc))
          {
            if(f->getKind() == FunctionConsts::FN_SUBSTRING_3)
              f = GET_BUILTIN_FUNCTION(OP_SUBSTRING_INT_3);
            else
              f = GET_BUILTIN_FUNCTION(OP_ZORBA_SUBSEQUENCE_INT_3);
          }
        }

        fo_expr_t foExpr = new fo_expr(theRootSctx, loc, f, arguments);
        normalize_fo(foExpr);
        push_nodestack(foExpr.getp());
        return;
      }
      case FunctionConsts::FN_POSITION_0:
      {
        push_nodestack(lookup_ctx_var(DOT_POS_VARNAME, loc).getp());
        return;
      }
      case FunctionConsts::FN_LAST_0:
      {
        push_nodestack(lookup_ctx_var(LAST_IDX_VARNAME, loc).getp());
        return;
      }
      case FunctionConsts::FN_NUMBER_0:
      case FunctionConsts::FN_NUMBER_1:
      {
        switch (numArgs)
        {
        case 0:
        {
          arguments.push_back(DOT_REF);
          f = GET_BUILTIN_FUNCTION(FN_NUMBER_1);
          break;
        }
        case 1:
          break;
        default:
          RAISE_ERROR(err::XPST0017, loc,
          ERROR_PARAMS("fn:number", ZED(FunctionUndeclared_3), numArgs));
        }

        var_expr_t tv = create_temp_var(loc, var_expr::let_var);

        expr_t nanExpr = new const_expr(theRootSctx, loc, xs_double::nan());

        expr_t condExpr = new castable_expr(theRootSctx, loc, &*tv, theRTM.DOUBLE_TYPE_ONE);

        expr_t castExpr = create_cast_expr(loc, tv.getp(), theRTM.DOUBLE_TYPE_ONE, true);

        expr_t ret = new if_expr(theRootSctx, loc, condExpr, castExpr, nanExpr);

        expr_t data_expr = wrap_in_atomization(arguments[0]);

        push_nodestack(&*wrap_in_let_flwor(new treat_expr(theRootSctx,
                                                          loc,
                                                          data_expr,
                                                          theRTM.ANY_ATOMIC_TYPE_QUESTION,
                                                          err::XPTY0004),
                                           tv,
                                           ret));
        return;
      }
      case FunctionConsts::FN_STATIC_BASE_URI_0:
      {
        if (numArgs != 0)
          RAISE_ERROR(err::XPST0017, loc,
          ERROR_PARAMS("fn:static-base-uri",
                       ZED(FunctionUndeclared_3),
                       numArgs));

        zstring baseuri = theSctx->get_base_uri();
        if (baseuri.empty())
          push_nodestack(create_empty_seq(loc));
        else
          push_nodestack(new cast_expr(theRootSctx,
                                       loc,
                                       new const_expr(theRootSctx, loc, baseuri),
                                       GENV_TYPESYSTEM.ANY_URI_TYPE_ONE));
        return;
      }
      case FunctionConsts::FN_ID_1:
      case FunctionConsts::FN_ID_2:
      case FunctionConsts::FN_ELEMENT_WITH_ID_1:
      case FunctionConsts::FN_ELEMENT_WITH_ID_2:
      {
        if (numArgs == 1)
        {
          arguments.insert(arguments.begin(), DOT_REF);
          f = lookup_fn(qname, 2, loc);
        }

        expr_t idsExpr = arguments[1];

        rchandle<flwor_expr> flworExpr = wrap_expr_in_flwor(idsExpr, false);

        const for_clause* fc = reinterpret_cast<const for_clause*>((*flworExpr.getp())[0]);
        expr* flworVarExpr = fc->get_var();

        fo_expr_t normExpr;
        fo_expr_t tokenExpr;
        zstring space(" ");
        rchandle<const_expr> constExpr = new const_expr(theRootSctx, loc, space);

        normExpr = new fo_expr(theRootSctx,
                               loc,
                               GET_BUILTIN_FUNCTION(FN_NORMALIZE_SPACE_1),
                               flworVarExpr);
        normalize_fo(normExpr);

        tokenExpr = new fo_expr(theRootSctx,
                                loc,
                                GET_BUILTIN_FUNCTION(FN_TOKENIZE_2),
                                normExpr.getp(),
                                constExpr.getp());
        normalize_fo(tokenExpr);

        flworExpr->set_return_expr(tokenExpr.getp());

        pop_scope();

        arguments[1] = flworExpr;
        break;
      }
      case FunctionConsts::FN_IDREF_1:
      {
        arguments.insert(arguments.begin(), DOT_REF);
        f = GET_BUILTIN_FUNCTION(FN_IDREF_2);
        break;
      }
      case FunctionConsts::FN_LANG_1:
      {
        arguments.insert(arguments.begin(), DOT_REF);
        f = GET_BUILTIN_FUNCTION(FN_LANG_2);
        break;
      }
      case FunctionConsts::FN_RESOLVE_URI_1:
      {
        zstring baseUri = theSctx->get_base_uri();
        arguments.insert(arguments.begin(), new const_expr(theRootSctx, loc, baseUri));
        f = GET_BUILTIN_FUNCTION(FN_RESOLVE_URI_2);
        break;
      }
      case FunctionConsts::FN_CONCAT_N:
      {
        if (numArgs < 2)
          RAISE_ERROR(err::XPST0017, loc,
            ERROR_PARAMS("concat", ZED(FunctionUndeclared_3), numArgs));
        break;
      }
      case FunctionConsts::FN_DOC_1:
      {
        if (numArgs > 0)
        {
          expr_t  doc_uri = arguments[0];

          //validate uri
          if(doc_uri->get_expr_kind() == const_expr_kind)
          {
            const_expr* const_uri = reinterpret_cast<const_expr*>(doc_uri.getp());
            const store::Item* uri_value = const_uri->get_val();
            zstring uri_string = uri_value->getStringValue();

            try
            {
              if (uri_string.find(":/", 0, 3) != zstring::npos)
              {
                URI docURI(uri_string, true);//with validate
              }
            }
            catch(XQueryException& e)
            {
              set_source(e, loc);
              throw;
            }
          }
        }
        break;
      }
      default: {}
    }
  }

  if (f != NULL && f->getKind() ==  FunctionConsts::FN_APPLY_1)
  {
    expr_t applyExpr = new apply_expr(theRootSctx, loc, arguments[0], false);
    push_nodestack(applyExpr);
    return;
  }

  // add context-item for functions with zero arguments which implicitly
  // take the context-item as argument
  if (f != NULL && xquery_fns_def_dot.test(f->getKind()))
  {
    arguments.push_back(DOT_REF);
    f = lookup_fn(qname, 1, loc);
  }

  //  Check if it is a zorba builtin function, and if so,
  // make sure that the module it belongs to has been imported.
  if (f != NULL &&
           f->isBuiltin() &&
           fn_ns != static_context::W3C_FN_NS &&
           fn_ns != XQUERY_MATH_FN_NS &&
           fn_ns != theModuleNamespace)
  {
    if (! theSctx->is_imported_builtin_module(fn_ns))
    {
      RAISE_ERROR(err::XPST0017, loc,
      ERROR_PARAMS(qname->get_qname(), ZED(FunctionUndeclared_3), numArgs));
    }
  }

  numArgs = (ulong)arguments.size();  // recompute size

  // Check if this is a call to a type constructor function
  xqtref_t type = CTX_TM->create_named_type(qnameItem,
                                            TypeConstants::QUANT_QUESTION);

  if (type != NULL)
  {
    if (numArgs != 1 ||
        TypeOps::is_equal(tm, *type, *GENV_TYPESYSTEM.NOTATION_TYPE_QUESTION, loc) ||
        TypeOps::is_equal(tm, *type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION, loc))
    {
      RAISE_ERROR(err::XPST0017, loc,
      ERROR_PARAMS(qname->get_qname(), ZED(FunctionUndeclared_3), numArgs));
    }

    push_nodestack(create_cast_expr(loc, arguments[0], type, true));
  }

  // It is not a builtin constructor function
  else
  {
    if (f == NULL)
    {
      if (theHaveModuleImportCycle)
      {
        std::map<zstring, zstring>::const_iterator ite = theModulesStack.begin();
        std::map<zstring, zstring>::const_iterator end = theModulesStack.end();

        --end;
        assert((*end).second == theModuleNamespace);

        for (; ite != end; ++ite)
        {
          if ((*ite).second == fn_ns)
            RAISE_ERROR(err::XQST0093, loc, ERROR_PARAMS(theModuleNamespace));
        }
      }

      RAISE_ERROR(err::XPST0017, loc,
      ERROR_PARAMS(qname->get_qname(), ZED(FunctionUndeclared_3), numArgs));
    }

    // If this is a udf that is invoked from another udf, mark that other udf
    // as a non-leaf function.
    if (f->isUdf())
    {
      if (! theCurrentPrologVFDecl.isNull() &&
          theCurrentPrologVFDecl.getKind() == PrologGraphVertex::FUN)
      {
        function* f1 = const_cast<function*>(theCurrentPrologVFDecl.getFunction());
        user_function* udf = dynamic_cast<user_function*>(f1);
        ZORBA_ASSERT(udf != NULL);
        udf->setLeaf(false);
      }
    }

    // Create and normalize the fo expr
    std::reverse(arguments.begin(), arguments.end());

    fo_expr_t foExpr = new fo_expr(theRootSctx, loc, f, arguments);

    normalize_fo(foExpr);

    expr_t resultExpr = foExpr.getp();

    if (f->isExternal())
    {
      const xqtref_t& resultType = f->getSignature().returnType();

      resultExpr = wrap_in_type_match(foExpr.getp(), resultType, loc);
    }

    // Some further normalization is required for certain builtin functions
    FunctionConsts::FunctionKind lKind = f->getKind();
    switch (lKind)
    {
      case FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_RANGE_VALUE_N:
      case FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_POINT_VALUE_N:
      {
        FunctionConsts::FunctionKind fkind = FunctionConsts::OP_SORT_NODES_ASC_1;

        resultExpr = new fo_expr(theRootSctx,
                                 foExpr->get_loc(),
                                 BuiltinFunctionLibrary::getFunction(fkind),
                                 foExpr);
        break;
      }
      case FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_POINT_GENERAL_N:
      case FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_RANGE_GENERAL_N:
      {
        FunctionConsts::FunctionKind fkind = FunctionConsts::OP_SORT_DISTINCT_NODES_ASC_1;

        resultExpr = new fo_expr(theRootSctx,
                                 foExpr->get_loc(),
                                 BuiltinFunctionLibrary::getFunction(fkind),
                                 foExpr);

        break;
      }
      case FunctionConsts::FN_ANALYZE_STRING_2:
      case FunctionConsts::FN_ANALYZE_STRING_3:
      {
        resultExpr = wrap_in_validate_expr_strict(
          foExpr.getp(),
          "http://www.w3.org/2005/xpath-functions");

        break;
      }
      case FunctionConsts::FN_SERIALIZE_2:
      {
        import_schema_auto_prefix(
          loc,
          "http://www.w3.org/2010/xslt-xquery-serialization",
          NULL);

        break;
      }
      case FunctionConsts::FN_ZORBA_EVAL_1:
      case FunctionConsts::FN_ZORBA_EVAL_N_1:
      case FunctionConsts::FN_ZORBA_EVAL_U_1:
      case FunctionConsts::FN_ZORBA_EVAL_S_1:
      {
        expr_script_kind_t scriptingKind;

        if (lKind == FunctionConsts::FN_ZORBA_EVAL_1 ||
            lKind == FunctionConsts::FN_ZORBA_EVAL_N_1)
        {
          scriptingKind = SIMPLE_EXPR;
        }
        else if (lKind == FunctionConsts::FN_ZORBA_EVAL_U_1)
        {
          scriptingKind = UPDATING_EXPR;
        }
        else
        {
          scriptingKind = SEQUENTIAL_FUNC_EXPR;
        }

        rchandle<eval_expr> evalExpr = new eval_expr(theRootSctx,
                                                     loc,
                                                     foExpr->get_arg(0),
                                                     scriptingKind,
                                                     theNSCtx);
        resultExpr = evalExpr;

        std::vector<var_expr_t> inscopeVars;
        theSctx->getVariables(inscopeVars);
        ulong numVars = inscopeVars.size();

        for (ulong i = 0; i < numVars; ++i)
        {
          if (inscopeVars[i]->get_kind() == var_expr::prolog_var)
            continue;

          var_expr_t evalVar = create_var(loc,
                                          inscopeVars[i]->get_name(),
                                          var_expr::eval_var,
                                          inscopeVars[i]->get_return_type());

          // At this point, the domain expr of an eval var is always another var.
          // However, that other var may be later inlined, so in general, the domain
          // expr of an eval var may be any expr.
          expr_t valueExpr = inscopeVars[i].getp();

          evalExpr->add_var(evalVar, valueExpr);
        }

        break;
      }
      case FunctionConsts::FN_ZORBA_INVOKE_N:
      case FunctionConsts::FN_ZORBA_INVOKE_N_N:
      case FunctionConsts::FN_ZORBA_INVOKE_U_N:
      case FunctionConsts::FN_ZORBA_INVOKE_S_N:
      {
        /*
           invoke(qnameExpr, arg1Expr, ...., argNExpr)

           is rewritten internally as:

           let $temp_invoke_var1   := data(qnameExpr) treat as xs:QName
           let $temp_invoke_var2   := arg1Expr
           ...
           let $temp_invoke_varN+1 := argNExpr
           let $query := concat("\"",
                                string(namespace-uri-from-QName(temp_invoke_var1)),
                                "\":",
                                string(local-name-from-QName(temp_invoke_var1)),
                                "($temp_invoke_var2, ..., $temp_invoke_varN+1)")
           return eval { $query }
        */

        expr_script_kind_t scriptingKind = SIMPLE_EXPR; // avoid warning
        zstring query_params;
        std::vector<var_expr_t> temp_vars;

        if (lKind == FunctionConsts::FN_ZORBA_INVOKE_N ||
            lKind == FunctionConsts::FN_ZORBA_INVOKE_N_N)
        {
          scriptingKind = SIMPLE_EXPR;
        }
        else if (lKind == FunctionConsts::FN_ZORBA_INVOKE_U_N)
        {
          scriptingKind = UPDATING_EXPR;
        }
        else if (lKind == FunctionConsts::FN_ZORBA_INVOKE_S_N)
        {
          scriptingKind = SEQUENTIAL_FUNC_EXPR;
        }

        if (numArgs == 0)
        {
          RAISE_ERROR(err::XPST0017, loc,
          ERROR_PARAMS("invoke", ZED(FunctionUndeclared_3), numArgs));
        }

        // create a flwor with LETs to hold the parameters
        flwor_expr_t flworExpr = new flwor_expr(theRootSctx, loc, false);

        // wrap function's QName
        expr_t qnameExpr = wrap_in_atomization(arguments[0]);
        qnameExpr        = wrap_in_type_promotion(arguments[0], theRTM.QNAME_TYPE_ONE);

        for (unsigned int i = 0; i<numArgs ; i++)
        {
          let_clause_t lc;
          store::Item_t qnameItem;

          // cannot use create_temp_var() as the variables created there are not accessible
          // use a special name but check for name clashes
          do
          {
            std::string localName = "temp_invoke_var" + ztd::to_string(theTempVarCounter++);
            GENV_ITEMFACTORY->createQName(qnameItem, "", "", localName.c_str());
          }
          while (lookup_var(qnameItem.getp(), loc, zerr::ZXQP0000_NO_ERROR) != NULL);

          var_expr_t var = create_var(loc, qnameItem, var_expr::let_var);
          temp_vars.push_back(var);

          if (i == 0)
            lc = wrap_in_letclause(qnameExpr, var);
          else
            lc = wrap_in_letclause(arguments[i], var);

          flworExpr->add_clause(lc);

          // add the parameters to the eval's query string
          if (i>1)
            query_params += ",";
          if (i>0)
            query_params += "$" + var->get_name()->getStringValue();
        }

        query_params = "(" + query_params + ")";

        // Expanded QName's namespace URI
        expr_t namespaceExpr =
        new fo_expr(theRootSctx,
                    loc,
                    GET_BUILTIN_FUNCTION(FN_NAMESPACE_URI_FROM_QNAME_1),
                    temp_vars[0]);

        namespaceExpr =
        new fo_expr(theRootSctx,
                    loc,
                    GET_BUILTIN_FUNCTION(FN_STRING_1),
                    namespaceExpr);

        // Expanded QName's local name
        expr_t localExpr =
        new fo_expr(theRootSctx,
                    loc,
                    GET_BUILTIN_FUNCTION(FN_LOCAL_NAME_FROM_QNAME_1),
                    temp_vars[0]);

        localExpr =
        new fo_expr(theRootSctx, loc, GET_BUILTIN_FUNCTION(FN_STRING_1), localExpr);

        // qnameExpr := concat("\"", namespaceExpr, "\":", localExpr, "$temp_invoke_var2,$temp_invoke_var3,...)")
        std::vector<expr_t> concat_args;
        concat_args.push_back(new const_expr(theRootSctx, loc, "\""));
        concat_args.push_back(namespaceExpr);
        concat_args.push_back(new const_expr(theRootSctx, loc, "\":"));
        concat_args.push_back(localExpr);
        concat_args.push_back(new const_expr(theRootSctx, loc, query_params));

        qnameExpr = new fo_expr(theRootSctx,
                                loc,
                                GET_BUILTIN_FUNCTION(FN_CONCAT_N),
                                concat_args);

        rchandle<eval_expr> evalExpr = new eval_expr(theRootSctx,
                                                     loc,
                                                     qnameExpr,
                                                     scriptingKind,
                                                     theNSCtx);

        flworExpr->set_return_expr(evalExpr.getp());
        resultExpr = flworExpr;

        std::vector<var_expr_t> inscopeVars;
        theSctx->getVariables(inscopeVars);
        ulong numVars = inscopeVars.size();

        for (ulong i = 0; i < numVars; ++i)
        {
          if (inscopeVars[i]->get_kind() == var_expr::prolog_var)
            continue;

          var_expr_t evalVar = create_var(loc,
                                          inscopeVars[i]->get_name(),
                                          var_expr::eval_var,
                                          inscopeVars[i]->get_return_type());

          // At this point, the domain expr of an eval var is always another var.
          // However, that other var may be later inlined, so in general, the domain
          // expr of an eval var may be any expr.
          expr_t valueExpr = inscopeVars[i].getp();
          evalExpr->add_var(evalVar, valueExpr);
        }

        for (ulong i=0; i<temp_vars.size(); i++)
        {
          var_expr_t evalVar = create_var(loc,
                                          temp_vars[i]->get_name(),
                                          var_expr::eval_var,
                                          temp_vars[i]->get_return_type());

          expr_t valueExpr = temp_vars[i].getp();
          evalExpr->add_var(evalVar, valueExpr);
        }

        break;
      }

      default: {}

    } // switch

    push_nodestack(resultExpr.getp());
  }
}


/*******************************************************************************
  ArgList := ExprSingle ("," ExprSingle)*
********************************************************************************/
void* begin_visit(const ArgList& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const ArgList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  PostfixExpr ::= PrimaryExpr (Predicate | ArgumentList)*

	ArgumentList ::= "(" (Argument ("," Argument)*)? ")"

  Argument ::= ExprSingle

  As shown above, there is no grammar rule for DynamicFunctionInvocation. A
  PostfinExpr becomes a dynamic function invocation if the PrimaryExpr is
  followed by an ArgumentList, in which case, the PrimaryExpr is supposed to
  return a function item.
********************************************************************************/
void* begin_visit(const DynamicFunctionInvocation& v)
{
  TRACE_VISIT();
  if ( !theSctx->is_feature_set(feature::hof) )
  {
    throw XQUERY_EXCEPTION(
      zerr::ZXQP0050_FEATURE_NOT_AVAILABLE,
      ERROR_PARAMS( "higher-order functions (hof)" ),
      ERROR_LOC( v.get_location() )
    );
  }
  return no_state;
}

void end_visit(const DynamicFunctionInvocation& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  // Collect the arguments of the dynamic function invocation
  std::vector<expr_t> arguments;
  if (v.getArgList() != 0)
  {
    size_t lSize = v.getArgList()->size();
    for (size_t i = lSize; i > 0; --i)
    {
      arguments.push_back(pop_nodestack());
    }
  }

  // Get the function item expr
  expr_t lItem = pop_nodestack();
  ZORBA_ASSERT(lItem != 0);

  expr_t lDynFuncInvocation = new dynamic_function_invocation_expr(
                                    theRootSctx,
                                    loc,
                                    lItem,
                                    arguments);
  push_nodestack(lDynFuncInvocation);
}


/*******************************************************************************
  LiteralFunctionItem ::= QName "#" IntegerLiteral
********************************************************************************/
void* begin_visit(const LiteralFunctionItem& v)
{
  TRACE_VISIT();

  if ( !theSctx->is_feature_set(feature::hof) )
  {
    RAISE_ERROR(zerr::ZXQP0050_FEATURE_NOT_AVAILABLE, v.get_location(),
    ERROR_PARAMS("higher-order functions (hof)"));
  }
  return no_state;
}


void end_visit(const LiteralFunctionItem& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  rchandle<QName> qname = v.getQName();
  uint32_t arity = 0;

  try
  {
    arity = to_xs_unsignedInt(v.getArity());
  }
  catch ( std::range_error const& )
  {
    RAISE_ERROR(err::XPST0017, loc,
    ERROR_PARAMS(v.getArity(), ZED(NoParseFnArity)));
  }

  // Get function implementation
  function* fn = lookup_fn(qname, arity, loc);

  // raise XPST0017 if function could not be found
  if (fn == 0)
  {
    RAISE_ERROR(err::XPST0017, loc,
    ERROR_PARAMS(qname->get_qname(), ZED(FunctionUndeclared_3), arity));
  }

  // If it is a builtin function F with signature (R, T1, ..., TN) , wrap it
  // in a udf UF: function UF(x1 as T1, ..., xN as TN) as R { F(x1, ... xN) }
  if (!fn->isUdf())
  {
    std::vector<expr_t> foArgs(arity);
    std::vector<var_expr_t> udfArgs(arity);

    for (ulong i = 0; i < arity; ++i)
    {
      var_expr_t argVar = create_temp_var(loc, var_expr::arg_var);

      udfArgs[i] = argVar;
      foArgs[i] = argVar.getp();
    }

    expr_t body = new fo_expr(theRootSctx, loc, fn, foArgs);

    user_function* udf = new user_function(loc,
                                           fn->getSignature(),
                                           body,
                                           fn->getScriptingKind());
    udf->setArgVars(udfArgs);

    fn = udf;
  }

  expr_t fiExpr = new function_item_expr(theRootSctx, loc, fn->getName(), fn, arity);

  push_nodestack(fiExpr.getp());
}


/*******************************************************************************
  InlineFunction ::= "function" "(" ParamList? ")"
                     ("as" SequenceType)? EnclosedExpr
********************************************************************************/
void* begin_visit(const InlineFunction& v)
{
  TRACE_VISIT();

  if ( !theSctx->is_feature_set(feature::hof) )
  {
    throw XQUERY_EXCEPTION(
      zerr::ZXQP0050_FEATURE_NOT_AVAILABLE,
      ERROR_PARAMS( "higher-order functions (hof)" ),
      ERROR_LOC( v.get_location() )
    );
  }

  // Get the in-scope vars of the scope before opening the new scope for the
  // function devl
  std::vector<var_expr_t> scopedVars;
  theSctx->getVariables(scopedVars);

  push_scope();

  function_item_expr* fiExpr = new function_item_expr(theRootSctx, loc);

  push_nodestack(fiExpr);

  flwor_expr_t flwor;

  // Handle function parameters. Translation of the params, if any, results to
  // a flwor expr with one let binding for each function parameter:
  //
  // let $x1 as T1 := _x1
  // .....
  // let $xN as TN := _xN
  //
  // where each _xi is an arg var.
  rchandle<ParamList> params = v.getParamList();
  if (params)
  {
    params->accept(*this);

    flwor = pop_nodestack().cast<flwor_expr>();
  }
  else
  {
    flwor = new flwor_expr(theRootSctx, loc, false);
  }

  // Handle inscope variables. For each inscope var, a let binding is added to
  // the flwor.
  std::vector<var_expr_t>::iterator ite = scopedVars.begin();
  for(; ite != scopedVars.end(); ++ite)
  {
    var_expr* varExpr = (*ite);
    var_expr::var_kind kind = varExpr->get_kind();

    if (kind == var_expr::prolog_var || kind == var_expr::local_var)
    {
      continue;
    }

    store::Item_t qname = varExpr->get_name();

    var_expr_t arg_var = create_var(loc, qname, var_expr::arg_var);
    var_expr_t subst_var = bind_var(loc, qname, var_expr::let_var);

    let_clause_t lc = wrap_in_letclause(&*arg_var, subst_var);

    arg_var->set_type(varExpr->get_return_type());

    // TODO: this could probably be done lazily in some cases
    //lc->setLazyEval(true);
    flwor->add_clause(lc);

    fiExpr->add_variable(varExpr);

    // ???? What about inscope vars that are hidden by param vars ???
  }

  if (flwor->num_clauses() > 0)
    push_nodestack(flwor.getp());
  else
    push_nodestack(NULL);

  return no_state;
}


void end_visit(const InlineFunction& v, void* aState)
{
  TRACE_VISIT_OUT();

  std::vector<var_expr_t> argVars;

  // Get the return tyoe
  xqtref_t returnType = GENV_TYPESYSTEM.ITEM_TYPE_STAR;
  if(v.getReturnType() != 0)
  {
    returnType = pop_tstack();
  }

  // Get the inline function body and wrap it in appropriate type op.
  expr_t body = pop_nodestack();
  ZORBA_ASSERT(body != 0);

  if (TypeOps::is_builtin_simple(CTX_TM, *returnType))
  {
    body = wrap_in_atomization(body);
    body = wrap_in_type_promotion(body, returnType);
  }
  else
  {
    body = wrap_in_type_match(body, returnType, loc);
  }

  // Make the body be the return expr of the flwor that binds the function params.
  flwor_expr_t flwor = pop_nodestack().cast<flwor_expr>();

  if (flwor != NULL)
  {
    flwor->set_return_expr(body);

    body = flwor;

    // Parameters and inscope vars have been wrapped into a flwor expression (see
    // begin_visit). We need to add these to the udf obj so that they will bound
    // at runtime. We must do this here (before we optimize the inline function
    // body, because optimization may remove clauses from the flwor expr
    for (ulong i = 0; i < flwor->num_clauses(); ++i)
    {
      const flwor_clause* lClause = (*flwor)[i];
      const let_clause* letClause = dynamic_cast<const let_clause*>(lClause);
      ZORBA_ASSERT(letClause != 0); // can only be a parameter bound using let
      var_expr* argVar = dynamic_cast<var_expr*>(letClause->get_expr());
      argVars.push_back(argVar);
    }
  }

  if (theCCB->theConfig.opt_level == CompilerCB::config::O1)
  {
    RewriterContext rCtx(theCCB,
                         body,
                         NULL,
                         "Inline function",
                         (theSctx->ordering_mode() == StaticContextConsts::ordered));
    GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rCtx);
    body = rCtx.getRoot();
  }

  // Translate the type declarations for the function params
  std::vector<xqtref_t> paramTypes;
  rchandle<ParamList> params = v.getParamList();
  if(params != 0)
  {
    std::vector<rchandle<Param> >::const_iterator lIt = params->begin();
    for(; lIt != params->end(); ++lIt)
    {
      const Param* param = lIt->getp();
      const SequenceType* paramType = param->get_typedecl().getp();
      if(paramType == 0)
      {
        paramTypes.push_back(GENV_TYPESYSTEM.ITEM_TYPE_STAR);
      }
      else
      {
        paramType->accept(*this);
        paramTypes.push_back(pop_tstack());
      }
    }
  }

  // Create the udf obj.
  user_function_t udf(new user_function(loc,
                                        signature(0, paramTypes, returnType),
                                        body.getp(),
                                        body->get_scripting_detail()));
  udf->setArgVars(argVars);
  udf->setOptimized(true);

  // Get the function_item_expr and set its function to the udf created above.
  function_item_expr* fiExpr = dynamic_cast<function_item_expr*>(
                               theNodeStack.top().getp());
  assert(fiExpr != NULL);

  fiExpr->set_function(udf);

  // pop the scope.
  pop_scope();
}


/*******************************************************************************

  Node Construction

  Constructor ::= DirectConstructor | ComputedConstructor

  DirectConstructor ::= DirElemConstructor |
                        DirCommentConstructor |
                        DirPIConstructor

********************************************************************************/


/*******************************************************************************
  EnclosedExpr ::= "{" Expr "}"

  Although EnclosedExpr appears in several grammar rules, an EnclosedExpr
  parsenode is created only in the case of direct and computed node constructors.
********************************************************************************/
void* begin_visit(const EnclosedExpr& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit (const EnclosedExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t lContent = pop_nodestack();

  fo_expr* foExpr = new fo_expr(theRootSctx, loc, op_enclosed, lContent);

  push_nodestack(foExpr);
}


/*******************************************************************************
  DirElemConstructor ::= "<" QName DirAttributeList?
                         ("/>" | (">" DirElemContentList? "</" QName S? ">"))
********************************************************************************/
void* begin_visit(const DirElemConstructor& v)
{
  TRACE_VISIT();

  push_scope();
  push_elem_scope();
  return no_state;
}

void end_visit(const DirElemConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t nameExpr;
  expr_t attrExpr;
  expr_t contentExpr;

  rchandle<QName> end_tag = v.get_end_name();
  rchandle<QName> start_tag = v.get_elem_name();

  if (end_tag != NULL && start_tag->get_qname() != end_tag->get_qname())
  {
    RAISE_ERROR(err::XPST0003, loc,
    ERROR_PARAMS(ZED(StartEndTagMismatch_23),
                 start_tag->get_qname(),
                 end_tag->get_qname()));
  }

  if (v.get_dir_content_list() != NULL)
    contentExpr = pop_nodestack();

  if (v.get_attr_list() != NULL)
    attrExpr = pop_nodestack();

  store::Item_t qnameItem;
  expand_elem_qname(qnameItem, v.get_elem_name(), loc);

  nameExpr = new const_expr(theRootSctx, loc, qnameItem);

  push_nodestack(new elem_expr(theRootSctx,
                               loc,
                               nameExpr,
                               attrExpr,
                               contentExpr,
                               theNSCtx));
  pop_elem_scope();
  pop_scope();
}


/*******************************************************************************
   [120] DirAttributeList ::= DirAttr | DirAttributeList  DirAttr
********************************************************************************/
void* begin_visit(const DirAttributeList& v)
{
  TRACE_VISIT();

  push_nodestack(NULL);

  // visit namespace declaratrion attributes first
  for (int visitType = 0; visitType < 2; visitType++)
  {
    for (int i = 0; i < (int)v.size(); ++i)
    {
      const DirAttr* attr = v[i];
      const QName* qname = attr->get_name().getp();
      bool isPrefix = qname->get_qname() == "xmlns" || qname->get_prefix() == "xmlns";

      if ((isPrefix && visitType == 0) || (! isPrefix && visitType == 1))
        attr->accept(*this);
    }
  }

  unsigned long numAttrs = 0;
  std::vector<rchandle<attr_expr> > attributes;
  while(true)
  {
    expr_t expr = pop_nodestack();
    if (expr == NULL)
      break;

    attr_expr* attrExpr = expr.dyn_cast<attr_expr>().getp();
    store::Item const *const attExprName = attrExpr->getQName();

    for (unsigned long i = 0; i < numAttrs; i++)
    {
      store::Item const *const attName = attributes[i]->getQName();
      if (attName->equals(attExprName))
        throw XQUERY_EXCEPTION(
          err::XQST0040, ERROR_PARAMS( attName->getStringValue() ), ERROR_LOC(loc)
        );
    }

    attributes.push_back(attrExpr);
    numAttrs++;
  }

  if (attributes.size() == 1)
  {
    push_nodestack(attributes[0].getp());
  }
  else
  {
    std::vector<expr_t> args;
    for (std::vector<rchandle<attr_expr> >::reverse_iterator it = attributes.rbegin();
         it != attributes.rend();
         ++it)
    {
      args.push_back((*it).getp());
    }

    fo_expr* expr_list = new fo_expr(theRootSctx,
                                     loc,
                                     op_concatenate,
                                     args);

    normalize_fo(expr_list);

    push_nodestack(expr_list);
  }

  return NULL;  // reject visitor -- everything done
}

void end_visit(const DirAttributeList& v, void* /*visit_state*/)
{
  // begin_visit() rejects visitor
  ZORBA_ASSERT(false);
}


/*******************************************************************************
  DirAttr ::= (S (QName S? "=" S? DirAttributeValue)
********************************************************************************/
void* begin_visit(const DirAttr& v)
{
  TRACE_VISIT();
  // boundary is needed because the value of an attribute might be empty
  push_nodestack(NULL);
  return no_state;
}

void end_visit(const DirAttr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t valueExpr = pop_nodestack();

  if (valueExpr != NULL)
  {
    // delete boundary
    pop_nodestack();
  }

  QName* qname = v.get_name().getp();

  // Namespace direct attribute
  if (qname->get_qname() == "xmlns" || qname->get_prefix() == "xmlns")
  {
    zstring prefix;
    zstring uri;
    bool have_uri = false;

    if (qname->get_qname() != "xmlns")
    {
      prefix = qname->get_localname();

      if (ZSTREQ(prefix, "xmlns"))
        throw XQUERY_EXCEPTION(
          err::XQST0070,
          ERROR_PARAMS( prefix, ZED( NoRebindPrefix ) ),
          ERROR_LOC( loc )
        );
    }

    const_expr* constValueExpr = valueExpr.dyn_cast<const_expr>().getp();
    fo_expr* foExpr = valueExpr.dyn_cast<fo_expr>().getp();
    if (foExpr != NULL && foExpr->get_func() != op_concatenate)
      foExpr = NULL;

    if (constValueExpr != NULL)
    {
      constValueExpr->get_val()->getStringValue2(uri);
      have_uri = true;
    }
    else if (foExpr != NULL)
    {
      for (unsigned int i=0; i<foExpr->num_args(); i++)
      {
        const_expr* constValueExpr = dynamic_cast<const_expr*>(foExpr->get_arg(i));
        if (constValueExpr != NULL)
        {
          constValueExpr->get_val()->appendStringValue(uri);
        }
        else
        {
          fo_expr* foExpr2 = dynamic_cast<fo_expr*>(foExpr->get_arg(i));
          if (foExpr2 != NULL &&
              foExpr2->get_func()->getKind() == FunctionConsts::OP_ENCLOSED_1 &&
              (qname->get_qname() == "xmlns" || qname->get_prefix() == "xmlns"))
          {
            throw XQUERY_EXCEPTION(err::XQST0022, ERROR_LOC(loc));
          }
        }
      }
      have_uri = true;
    }

    if (have_uri)
    {
      if ((ZSTREQ(prefix, "xml") && !ZSTREQ(uri, XML_NS)))
      {
        throw XQUERY_EXCEPTION(
          err::XQST0070,
          ERROR_PARAMS( prefix, ZED( NoRebindPrefix ) ),
          ERROR_LOC( loc )
        );
      }

      if ((ZSTREQ(uri, XML_NS) && !ZSTREQ(prefix, "xml")) ||
           ZSTREQ(uri, XMLNS_NS))
      {
        throw XQUERY_EXCEPTION(
          err::XQST0070, ERROR_PARAMS( uri, ZED( NoBindURI ) ), ERROR_LOC( loc )
        );
      }

      theSctx->bind_ns(prefix, uri, loc, err::XQST0071);
      theNSCtx->bind_ns(prefix, uri);

      if (prefix.empty())
        theSctx->set_default_elem_type_ns(uri, loc);
    }
    else if (valueExpr == NULL)
    {
      if (ZSTREQ(prefix, "xml"))
        throw XQUERY_EXCEPTION(
          err::XQST0070,
          ERROR_PARAMS( prefix, ZED( NoRebindPrefix ) ),
          ERROR_LOC( loc )
        );

      // unbind the prefix
      zstring empty;
      theSctx->bind_ns(prefix, empty, loc, err::XQST0071);
      theNSCtx->bind_ns(prefix, empty);

      if (prefix.empty())
        theSctx->set_default_elem_type_ns(empty, loc);
    }
    else
    {
      throw XQUERY_EXCEPTION(err::XQST0022, ERROR_LOC(loc));
    }
  }
  else
  // Plain direct attribute
  {
    store::Item_t qnameItem;
    expand_no_default_qname(qnameItem, qname, qname->get_location());

    expr_t nameExpr = new const_expr(theRootSctx, loc, qnameItem);

    fo_expr* foExpr;
    if ((foExpr = dynamic_cast<fo_expr*>(valueExpr.getp())) != NULL &&
        foExpr->get_func()->getKind() == FunctionConsts::OP_ENCLOSED_1)
    {
      foExpr->set_arg(0, wrap_in_atomization(foExpr->get_arg(0)));
    }
    else if (valueExpr != NULL)
    {
      valueExpr = wrap_in_atomization(valueExpr);
    }

    expr_t attrExpr = new attr_expr(theRootSctx, loc, nameExpr, valueExpr);

    push_nodestack(attrExpr);
  }
}


/*******************************************************************************
  DirElemContentList ::= DirElemContent | DirElemContentList DirElemContent
********************************************************************************/
void* begin_visit(const DirElemContentList& v)
{
  TRACE_VISIT();

  push_nodestack(NULL);
  return no_state;
}

void end_visit(const DirElemContentList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  std::vector<expr_t> args;
  while (true)
  {
    expr_t e = pop_nodestack();
    if (e == NULL)
      break;

    args.push_back(e);
  }

  if (args.size() == 1)
  {
    push_nodestack(args[0]);
  }
  else
  {
    fo_expr_t expr_list = new fo_expr(theRootSctx,
                                      loc,
                                      op_concatenate,
                                      args);

    normalize_fo(expr_list.getp());

    push_nodestack(expr_list.getp());
  }
}


void* begin_visit(const DirElemContent& v)
{
  TRACE_VISIT();

  return no_state;
}

void end_visit(const DirElemContent& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  if (v.get_direct_cons() != NULL)
  {
    // nothing to be done, the content expression is already on the stack
  }
  else if (v.get_cdata() != NULL)
  {
  }
  else if (v.get_common_content() != NULL)
  {
  }
  else
  {
    if (!v.isStripped())
    {
      expr_t content = new const_expr(theRootSctx, loc, v.get_elem_content().str());

      push_nodestack(new text_expr(theRootSctx, loc,
                                   text_expr::text_constructor,
                                   content));
    }
  }
}


/**
 * Inserts an entry in theIsWSBoundaryStack and thePossibleWSContentStack to save
 * information during boundary whitespace checking.
 */
void begin_check_boundary_whitespace()
{
  if (theSctx->boundary_space_mode() == StaticContextConsts::strip_space)
{
    theIsWSBoundaryStack.push(true);
    thePossibleWSContentStack.push(0);
  }
}


/*******************************************************************************
  Whitespace checking. Checks if v might be a whitespace (check of the following
  boundary can only be checked during the next invocation), and if the items
  saved in thePossibleWSContentStack is really boundary whitespace.
********************************************************************************/
void check_boundary_whitespace(const DirElemContent& v)
{
  v.setIsStripped(false);
  if (theSctx->boundary_space_mode() == StaticContextConsts::strip_space)
  {
    bool lPrevIsBoundary = translator_ns::pop_stack (theIsWSBoundaryStack);
    const DirElemContent* lPrev = translator_ns::peek_stack(thePossibleWSContentStack);
    thePossibleWSContentStack.pop();

    if (v.get_direct_cons() != 0 ||
        (v.get_common_content() != 0 && v.get_common_content()->get_expr() != 0))
    {
      thePossibleWSContentStack.push(0);
      theIsWSBoundaryStack.push(true);
      if (lPrev != 0) {
        lPrev->setIsStripped(true);
      }
    }
    else if (v.get_common_content() != 0 || v.get_cdata() != 0)
    {
      thePossibleWSContentStack.push(0);
      theIsWSBoundaryStack.push(false);
    }
    else
    {
      bool lCouldBe = false;
      if (lPrevIsBoundary) {
        zstring content = v.get_elem_content().str();
        utf8::trim_whitespace(content);

        // Filtering out of whitespaces
        if (content.empty()) {
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
void end_check_boundary_whitespace()
{
  if (theSctx->boundary_space_mode() == StaticContextConsts::strip_space)
  {
    const DirElemContent* lPrev = translator_ns::pop_stack (thePossibleWSContentStack);
    if (lPrev != 0)
    {
      lPrev->setIsStripped(true);
    }
    theIsWSBoundaryStack.pop();
  }
}



void* begin_visit(const CDataSection& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const CDataSection& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
  std::string lCDATA_content = v.get_cdata_content().str();
  // Skip empty CDATA sections
  if(!lCDATA_content.empty())
  {
    expr_t content = new const_expr(theRootSctx, loc, lCDATA_content);
    push_nodestack(new text_expr(theRootSctx, loc, text_expr::text_constructor, content));
  }
}


void* begin_visit(const DirAttributeValue& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const DirAttributeValue& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


void attr_content_list(const QueryLoc& loc, void* /*visit_state*/)
{
  std::vector<expr_t> args;
  while(true)
  {
    expr_t e = pop_nodestack();
    if (e == NULL)
      break;

    args.push_back(e);
  }

  if (args.size() == 1)
  {
    push_nodestack(args[0]);
  }
  else if (args.size() > 1)
  {
    fo_expr_t expr_list = new fo_expr(theRootSctx,
                                      loc,
                                      op_concatenate,
                                      args);
    normalize_fo(expr_list.getp());

    push_nodestack(expr_list.getp());
  }
}


void* begin_visit(const QuoteAttrContentList& v)
{
  TRACE_VISIT();

  push_nodestack(NULL);
  return no_state;
}

void end_visit(const QuoteAttrContentList& v, void* visit_state)
{
  TRACE_VISIT_OUT();
  attr_content_list(loc, visit_state);
}


void* begin_visit(const AposAttrContentList& v)
{
  TRACE_VISIT();

  push_nodestack(NULL);
  return no_state;
}

void end_visit(const AposAttrContentList& v, void* visit_state)
{
  TRACE_VISIT_OUT();
  attr_content_list (loc, visit_state);
}


void attr_val_content(const QueryLoc& loc, const CommonContent *cc, zstring content)
{
  if (cc == NULL)
  {
    push_nodestack(new const_expr (theRootSctx, loc, content));
  }
  else
  {
    // nothing to be done because when common content != NULL,
    // the corresponding expr is already on the stack
  }
}


void* begin_visit(const QuoteAttrValueContent& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const QuoteAttrValueContent& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
  attr_val_content(loc, v.get_common_content(), v.get_quot_atcontent().str());
}


void* begin_visit(const AposAttrValueContent& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const AposAttrValueContent& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
  attr_val_content(loc, v.get_common_content(), v.get_apos_atcontent().str());
}


void* begin_visit(const CommonContent& v)
{
  TRACE_VISIT();

  return no_state;
}

void end_visit(const CommonContent& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  switch (v.get_type())
  {
  case ParseConstants::cont_entity:
  {
    ZORBA_ASSERT (false);
    break;
  }
  case ParseConstants::cont_charref:
  {
    std::string content;
    std::string charrefs = v.get_ref().str();

    const char* curRef = charrefs.c_str();
    const char* end = curRef + charrefs.size();

    while (curRef < end)
    {
      int d = xml::parse_entity(curRef, &content);
      if (d < 0)
      {
        RAISE_ERROR(err::XQST0090, loc,
        ERROR_PARAMS(curRef, theSctx->xquery_version()));
      }
      curRef += d;

      if (curRef >= end)
        break;

      if (*curRef == '&')
        curRef++;
    }

    expr_t lConstExpr = new const_expr(theRootSctx, loc, content);
    push_nodestack(lConstExpr);
    break;
  }
  case ParseConstants::cont_escape_lbrace:
  {
    // we always create a text node here because if we are in an attribute, we atomice
    // the text node into its string value
    zstring content("{");
    expr_t lConstExpr = new const_expr(theRootSctx, loc, content);
    push_nodestack ( lConstExpr );
    break;
  }
  case ParseConstants::cont_escape_rbrace:
  {
    // we always create a text node here because if we are in an attribute, we atomice
    // the text node into its string value
    zstring content("}");
    expr_t lConstExpr = new const_expr(theRootSctx, loc, content);
    push_nodestack ( lConstExpr );
    break;
  }
  case ParseConstants::cont_expr:
  {
    break;
  }
  }
}


void* begin_visit(const DirCommentConstructor& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const DirCommentConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  zstring str = v.get_comment().str();
  expr_t content = new const_expr (theRootSctx, loc, str);
  push_nodestack (new text_expr(theRootSctx, loc,
                                text_expr::comment_constructor,
                                content));
}


void* begin_visit(const DirPIConstructor& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const DirPIConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  zstring target_str = v.get_pi_target().str();
  zstring target_upper;
  utf8::to_upper(target_str, &target_upper);

  if (target_upper == "XML")
    throw XQUERY_EXCEPTION(err::XPST0003, ERROR_LOC(loc));

  expr_t target = new const_expr(theRootSctx, loc, target_str);
  expr_t content = new const_expr(theRootSctx, loc, v.get_pi_content().str());

  push_nodestack(new pi_expr(theRootSctx, loc, target,  content));
}


void* begin_visit(const CompDocConstructor& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const CompDocConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t lContent = pop_nodestack();

  fo_expr* lEnclosed = new fo_expr(theRootSctx, loc, op_enclosed, lContent);

  push_nodestack(new doc_expr(theRootSctx, loc, lEnclosed));
}


void* begin_visit(const CompElemConstructor& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const CompElemConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t nameExpr;
  expr_t contentExpr;

  if (v.get_content_expr() != 0)
  {
    contentExpr = pop_nodestack();

    fo_expr* lEnclosed = new fo_expr(theRootSctx, loc, op_enclosed, contentExpr);
    contentExpr = lEnclosed;
  }

  QName* constQName = v.get_qname_expr().dyn_cast<QName>().getp();

  if (constQName != NULL)
  {
    store::Item_t qnameItem;
    expand_elem_qname(qnameItem, constQName, loc);

    nameExpr = new const_expr(theRootSctx, loc, qnameItem);
  }
  else
  {
    nameExpr = pop_nodestack();

    expr_t atomExpr = wrap_in_atomization(nameExpr);
    nameExpr = new name_cast_expr(theRootSctx, loc, atomExpr.getp(), theNSCtx, false);
  }

  push_nodestack (new elem_expr(theRootSctx, loc, nameExpr, contentExpr, theNSCtx));
}


void* begin_visit(const CompAttrConstructor& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const CompAttrConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t nameExpr;
  expr_t valueExpr;
  expr_t attrExpr;

  if (v.get_val_expr() != 0)
  {
    valueExpr = pop_nodestack();
    valueExpr = wrap_in_atomization(valueExpr);

    fo_expr* enclosedExpr = new fo_expr(theRootSctx, loc, op_enclosed, valueExpr);
    valueExpr = enclosedExpr;
  }

  QName* constQName = v.get_qname_expr().dyn_cast<QName>().getp();

  if (constQName != NULL)
  {
    store::Item_t qnameItem;
    expand_no_default_qname(qnameItem, constQName, constQName->get_location());

    nameExpr = new const_expr(theRootSctx, loc, qnameItem);
  }
  else
  {
    nameExpr = pop_nodestack();
    expr_t atomExpr = wrap_in_atomization(nameExpr);
    nameExpr = new name_cast_expr(theRootSctx, loc, atomExpr.getp(), theNSCtx, true);
  }

  attrExpr = new attr_expr(theRootSctx, loc, nameExpr, valueExpr);

  push_nodestack(attrExpr);
}


void* begin_visit(const CompCommentConstructor& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const CompCommentConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t inputExpr = pop_nodestack();

  fo_expr_t enclosedExpr = new fo_expr(theRootSctx, loc, op_enclosed, inputExpr);

  expr_t textExpr = new text_expr(theRootSctx, loc,
                                  text_expr::comment_constructor,
                                  enclosedExpr.getp());

  push_nodestack(textExpr);
}


void* begin_visit(const CompPIConstructor& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const CompPIConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t target;
  expr_t content;

  if (v.get_content_expr() == NULL)
  {
    content = create_empty_seq(loc);
  }
  else
  {
    content = pop_nodestack();

    fo_expr_t enclosedExpr = new fo_expr(theRootSctx, loc, op_enclosed, content);
    content = enclosedExpr;
  }

  if (v.get_target_expr() != NULL)
  {
    target = pop_nodestack();

    expr_t castExpr = create_cast_expr(loc, target.getp(), theRTM.NCNAME_TYPE_ONE, true);

    fo_expr_t enclosedExpr = new fo_expr(theRootSctx, loc, op_enclosed, castExpr.getp());
    target = enclosedExpr;
  }

  expr_t e = (v.get_target_expr () != NULL ?
              new pi_expr(theRootSctx, loc, target, content) :
              new pi_expr(theRootSctx, loc, new const_expr(theRootSctx, loc, v.get_target().str()), content));

  push_nodestack (e);
}


void* begin_visit(const CompTextConstructor& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const CompTextConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t inputExpr = pop_nodestack();

  fo_expr_t enclosedExpr = new fo_expr(theRootSctx, loc, op_enclosed, inputExpr);

  expr_t textExpr = new text_expr(theRootSctx, loc,
                                  text_expr::text_constructor,
                                  enclosedExpr.getp());

  push_nodestack(textExpr);
}


/*******************************************************************************

********************************************************************************/

void* begin_visit(const SingleType& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const SingleType& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
  if (v.get_hook_bit())
    theTypeStack.push(CTX_TM->create_type(*pop_tstack(), TypeConstants::QUANT_QUESTION));
  // else leave type as it is on tstack
}


void* begin_visit(const TypeName& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const TypeName& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Sequence Type Matching                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

  A SequenceType parsenode has 2 children: The right child is always an
  OccurrenceIndicator node. The left child may be either an AtomicType node,
  or one of the 9 kind-test nodes (elementTest, documentTest, ... etc), or
  an ItemType node. ItemType respesents the expression item().

********************************************************************************/

void* begin_visit(const SequenceType& v)
{
  TRACE_VISIT();

  if (v.get_itemtype() == NULL && v.get_occur() == NULL)
  {
    theTypeStack.push(GENV_TYPESYSTEM.EMPTY_TYPE);
    return NULL;
  }

  return no_state;
}

void end_visit (const SequenceType& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
}


void* begin_visit(const OccurrenceIndicator& v)
{
  TRACE_VISIT();

  TypeConstants::quantifier_t q = TypeConstants::QUANT_STAR;
  switch(v.get_type())
  {
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
    theTypeStack.push (CTX_TM->create_type (*pop_tstack (), q));

  return no_state;
}

void end_visit(const OccurrenceIndicator& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


void* begin_visit(const AtomicType& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const AtomicType& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  rchandle<QName> qname = v.get_qname();
  store::Item_t qnameItem;
  expand_elem_qname(qnameItem, qname, loc);

  xqtref_t t = CTX_TM->create_named_atomic_type(qnameItem, TypeConstants::QUANT_ONE);

  // some types that should never be parsed, like xs:untyped, are;
  // we catch them with is_simple()
  if (t == NULL)
  {
    RAISE_ERROR(err::XPST0051, loc, ERROR_PARAMS(qname->get_qname()));
  }
  else
  {
    theTypeStack.push (t);
  }
}


void* begin_visit(const ItemType& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const ItemType& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
  theTypeStack.push (GENV_TYPESYSTEM.ITEM_TYPE_ONE);
}


/*******************************************************************************

   KindTest

********************************************************************************/


void* begin_visit(const QName& v)
{
  TRACE_VISIT();
  return no_state;
}


void end_visit(const QName& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


void* begin_visit(const AnyKindTest& v)
{
  TRACE_VISIT();
  // no action needed here
  return no_state;
}


void end_visit(const AnyKindTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  // if the top of the stack is an axis step expr, add a node test expr to it.
  axis_step_expr* axisExpr = peek_nodestk_or_null().dyn_cast<axis_step_expr>();
  if (axisExpr != NULL)
  {
    rchandle<match_expr> me = new match_expr(theRootSctx, loc);
    me->setTestKind(match_anykind_test);
    axisExpr->setTest(me);
  }
  else
  {
    theTypeStack.push(GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE);
  }
}


/*******************************************************************************

  DocumentTest ::= "document-node" "(" (ElementTest | SchemaElementTest)? ")"

********************************************************************************/
void* begin_visit(const DocumentTest& v)
{
  TRACE_VISIT();
  return no_state;
}


void end_visit(const DocumentTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  ElementTest* elemTest = v.get_elem_test().getp();
  SchemaElementTest* schemaTest = v.get_schema_elem_test().getp();
  axis_step_expr* axisExpr = peek_nodestk_or_null().dyn_cast<axis_step_expr>();
  rchandle<match_expr> match;

  if (elemTest == NULL && schemaTest == NULL)
  {
    if (axisExpr != NULL)
    {
      match = new match_expr(theRootSctx, loc);
      match->setTestKind(match_doc_test);

      axisExpr->setTest(match);
    }
    else
    {
      theTypeStack.push(GENV_TYPESYSTEM.DOCUMENT_TYPE_ONE);
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

    xqtref_t docTest = CTX_TM->create_node_type(store::StoreConsts::documentNode,
                                                NULL,
                                                elementOrSchemaTest,
                                                TypeConstants::QUANT_ONE,
                                                false,
                                                false);
    theTypeStack.push(docTest);
  }
}


/*******************************************************************************

	ElementTest ::= "element" "("
                     (ElementNameOrWildcard ("," TypeName "?"?)?)?
                  ")"

  ElementNameOrWildcard ::= ElementName | "*"

********************************************************************************/
void* begin_visit(const ElementTest& v)
{
  TRACE_VISIT();
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
    expand_elem_qname(elemNameItem, elemName.getp(), loc);

  if (typeName != NULL)
    expand_elem_qname(typeNameItem, typeName->get_name(), loc);

  // if the top of the stack is an axis step expr, add a node test expr to it.
  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();

  xqtref_t contentType;

  if (typeName != NULL)
  {
    contentType = CTX_TM->create_named_type(typeNameItem, TypeConstants::QUANT_ONE);

    if (contentType == NULL)
    {
      throw XQUERY_EXCEPTION(
        err::XPST0008,
        ERROR_PARAMS( typeNameItem->getStringValue(), ZED( ElementName ) ),
        ERROR_LOC( loc )
      );
    }
  }

  if (axisExpr != NULL)
  {
    rchandle<match_expr> me = new match_expr(theRootSctx, loc);
    me->setTestKind(match_elem_test);
    me->setQName(elemNameItem);
    me->setTypeName(typeNameItem);
    me->setNilledAllowed(nillable);

    axisExpr->setTest(me);
  }

  // Else, create a sequence-type match
  else
  {
    xqtref_t seqmatch = CTX_TM->create_node_type(store::StoreConsts::elementNode,
                                                 elemNameItem,
                                                 contentType,
                                                 TypeConstants::QUANT_ONE,
                                                 nillable,
                                                 false);
    theTypeStack.push(seqmatch);
  }
}


/*******************************************************************************

  SchemaElementTest ::= "schema-element" "(" ElementDeclaration ")"

  ElementDeclaration ::= ElementName

********************************************************************************/
void* begin_visit(const SchemaElementTest& v)
{
  TRACE_VISIT();

#ifndef ZORBA_NO_XMLSCHEMA
  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  rchandle<QName> elemName = v.get_elem();
  ZORBA_ASSERT(elemName != NULL);

  store::Item_t elemQNameItem;
  expand_elem_qname(elemQNameItem, elemName, loc);

  if (axisExpr != NULL)
  {
    store::Item_t typeQNameItem;
    CTX_TM->get_schema_element_typename(elemQNameItem, typeQNameItem, loc);

    rchandle<match_expr> match = new match_expr(theRootSctx, loc);
    match->setTestKind(match_xs_elem_test);
    match->setQName(elemQNameItem);
    match->setTypeName(typeQNameItem);

    axisExpr->setTest(match);
  }
  else
  {
    xqtref_t seqmatch = CTX_TM->create_schema_element_type(elemQNameItem,
                                                           TypeConstants::QUANT_ONE,
                                                           loc);
    theTypeStack.push(seqmatch);
  }
#else /* ZORBA_NO_XMLSCHEMA */
  throw XQUERY_EXCEPTION(
    zerr::ZXQP0005_NOT_ENABLED,
    ERROR_PARAMS( ZED( XMLSchema ) ),
    ERROR_LOC( loc )
  );
#endif /* ZORBA_NO_XMLSCHEMA */
  return no_state;
}


void end_visit(const SchemaElementTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


void* begin_visit(const AttributeTest& v)
{
  TRACE_VISIT();
  return no_state;
}


void end_visit(const AttributeTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  rchandle<QName> attrName = v.get_attr_name();
  rchandle<TypeName> typeName = v.get_type_name();

  store::Item_t attrNameItem;
  store::Item_t typeNameItem;
  xqtref_t contentType;

  if (attrName != NULL)
  {
    expand_no_default_qname(attrNameItem, attrName,  attrName->get_location());
  }

  if (typeName != NULL)
  {
    expand_elem_qname(typeNameItem, typeName->get_name(), typeName->get_location());

    contentType = CTX_TM->create_named_type(typeNameItem, TypeConstants::QUANT_ONE);

    if (contentType == NULL)
    {
      throw XQUERY_EXCEPTION(
        err::XPST0008,
        ERROR_PARAMS( typeNameItem->getStringValue(), ZED( AttributeName ) ),
        ERROR_LOC( loc )
      );
    }
  }

  // if the top of the stack is an axis step expr, add a node test expr to it.
  axis_step_expr* axisExpr = peek_nodestk_or_null().dyn_cast<axis_step_expr> ();
  if (axisExpr != NULL)
  {
    rchandle<match_expr> match = new match_expr(theRootSctx, loc);
    match->setTestKind(match_attr_test);

    if (attrName != NULL)
      match->setQName(attrNameItem);

    if (typeName != NULL)
      match->setTypeName(typeNameItem);

    axisExpr->setTest(match);
  }
  else
  {
    xqtref_t seqmatch = CTX_TM->create_node_type(store::StoreConsts::attributeNode,
                                                 attrNameItem.getp(),
                                                 contentType,
                                                 TypeConstants::QUANT_ONE,
                                                 false,
                                                 false);

    theTypeStack.push(seqmatch);
  }
}


void* begin_visit(const SchemaAttributeTest& v)
{
  TRACE_VISIT();

#ifndef ZORBA_NO_XMLSCHEMA
  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  rchandle<QName> attrName = v.get_attr();
  ZORBA_ASSERT(attrName != NULL);

  store::Item_t attrQNameItem;
  expand_no_default_qname(attrQNameItem, attrName, attrName->get_location());

  if (axisExpr != NULL)
  {
    store::Item_t typeQNameItem;
    CTX_TM->get_schema_attribute_typename(attrQNameItem, typeQNameItem, loc);

    rchandle<match_expr> match = new match_expr(theRootSctx, loc);
    match->setTestKind(match_xs_attr_test);
    match->setQName(attrQNameItem);
    match->setTypeName(typeQNameItem);

    axisExpr->setTest(match);
  }
  else
  {
    xqtref_t seqmatch = CTX_TM->create_schema_attribute_type(attrQNameItem,
                                                             TypeConstants::QUANT_ONE,
                                                             loc);

    theTypeStack.push(seqmatch);
  }

#else /* ZORBA_NO_XMLSCHEMA */
  throw XQUERY_EXCEPTION(
    zerr::ZXQP0005_NOT_ENABLED,
    ERROR_PARAMS( ZED( XMLSchema ) ),
    ERROR_LOC( loc )
  );
#endif /* ZORBA_NO_XMLSCHEMA */
  return no_state;
}


void end_visit(const SchemaAttributeTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


void* begin_visit(const TextTest& v)
{
  TRACE_VISIT();
  // no action needed here
  return no_state;
}


void end_visit(const TextTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  if (axisExpr != NULL)
  {
    rchandle<match_expr> match = new match_expr(theRootSctx, loc);
    match->setTestKind(match_text_test);
    axisExpr->setTest(match);
  }
  else
  {
    theTypeStack.push(GENV_TYPESYSTEM.TEXT_TYPE_ONE);
  }
}


void* begin_visit(const CommentTest& v)
{
  TRACE_VISIT();
  // no action needed here
  return no_state;
}


void end_visit(const CommentTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  if (axisExpr != NULL)
  {
    rchandle<match_expr> match = new match_expr(theRootSctx, loc);
    match->setTestKind(match_comment_test);
    axisExpr->setTest(match);
  }
  else
  {
    theTypeStack.push(GENV_TYPESYSTEM.COMMENT_TYPE_ONE);
  }
}


void* begin_visit(const PITest& v)
{
  TRACE_VISIT();
  return no_state;
}


void end_visit(const PITest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  axis_step_expr* axisExpr = peek_nodestk_or_null ().dyn_cast<axis_step_expr> ();
  std::string target = v.get_target().str();

  store::Item_t qname = NULL;
  if (target != "")
  {
    // bugfix for XQuery 1.1 (fixes test K2-NameTest-22)
    // see W3C bug http://www.w3.org/Bugs/Public/show_bug.cgi?id=6559
    // processing-instruction( N ) matches any processing-instruction node
    // whose PITarget is equal to fn:normalize-space(N). If fn:normalize-space(N)
    // is not in the lexical space of NCName, a type error is raised [err:XPTY0004]

    zstring lNormalizedTarget;
    ascii::normalize_whitespace( target, &lNormalizedTarget );

    if (!GenericCast::instance()->castableToNCName(lNormalizedTarget))
    {
      throw XQUERY_EXCEPTION(
        err::XPTY0004,
        ERROR_PARAMS(
          ZED( BadType_23o ), lNormalizedTarget,
          ZED( NoCastTo_45o ), "NCName"
        ),
        ERROR_LOC( loc )
      );
    }

    // bugfix (see above); pass normalized string instead of original target
    GENV_ITEMFACTORY->createQName(qname, NULL, NULL, lNormalizedTarget.c_str());
  }

  if (axisExpr != NULL)
  {
    rchandle<match_expr> match = new match_expr(theRootSctx, loc);
    match->setTestKind(match_pi_test);
    if (target != "")
      match->setQName(qname);
    axisExpr->setTest(match);
  }
  else
  {
    if (target == "")
    {
      theTypeStack.push(GENV_TYPESYSTEM.PI_TYPE_ONE);
    }
    else
    {
      xqtref_t t = GENV_TYPESYSTEM.create_node_type(store::StoreConsts::piNode,
                                                    qname,
                                                    NULL,
                                                    TypeConstants::QUANT_ONE,
                                                    false,
                                                    false);
      theTypeStack.push (t);
    }
  }
}


void* begin_visit(const AnyFunctionTest& v)
{
  TRACE_VISIT();
  //Nothing to do here
  return no_state;
}

void end_visit(const AnyFunctionTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
  theTypeStack.push(GENV_TYPESYSTEM.ANY_FUNCTION_TYPE_STAR);
}

void* begin_visit(const TypeList& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const TypeList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}

void* begin_visit(const TypedFunctionTest& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const TypedFunctionTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  const rchandle<TypeList>& lParamTypes = v.getArgumentTypes();
  const rchandle<SequenceType>& lRetType = v.getReturnType();

  std::vector<xqtref_t> lParamXQTypes;
  xqtref_t              lRetXQType;

  if (lParamTypes)
  {
    for (int i = 0; i < (int)lParamTypes->size(); ++i)
    {
      const SequenceType* lParamType = (*lParamTypes)[i].getp();
      if (lParamType == 0) {
        lParamXQTypes.push_back(GENV_TYPESYSTEM.ITEM_TYPE_STAR);
      } else {
        lParamType->accept(*this);
        lParamXQTypes.push_back(pop_tstack());
      }
    }
  }

  if (lRetType != 0)
  {
    lRetType->accept(*this);
    lRetXQType = pop_tstack();
  }

  TypeConstants::quantifier_t lQuant = TypeConstants::QUANT_STAR;
  theTypeStack.push (GENV_TYPESYSTEM.create_function_type(
    lParamXQTypes, lRetXQType, lQuant));
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Update Expressions                                                        //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


void* begin_visit(const DeleteExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const DeleteExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t lTarget = pop_nodestack();

  expr_t aDelete = new delete_expr(theRootSctx, loc, lTarget);
  push_nodestack(aDelete);
}


void* begin_visit(const InsertExpr& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const InsertExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
  expr_t lTarget = pop_nodestack();
  expr_t lSource = pop_nodestack();

  fo_expr_t lEnclosed = new fo_expr(theRootSctx, loc, op_enclosed, lSource);
  lSource = lEnclosed;

  expr_t lInsert = new insert_expr(theRootSctx, loc, v.getType(), lSource, lTarget);
  push_nodestack(lInsert);
}


void* begin_visit(const RenameExpr& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const RenameExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t nameExpr = pop_nodestack();
  expr_t targetExpr = pop_nodestack();

  nameExpr = wrap_in_atomization(nameExpr).getp();

  // We use a name_cast_expr here for static typing reasons. However, during codegen,
  // we are not going to generate a NameCastIterator, because we don't always know at
  // compile time whether the target will an element or an attribute node.
  nameExpr = new name_cast_expr(theRootSctx, loc, nameExpr.getp(), theNSCtx, false);

  expr_t renameExpr = new rename_expr(theRootSctx, loc, targetExpr, nameExpr);

  push_nodestack(renameExpr);
}


void* begin_visit (const ReplaceExpr& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const ReplaceExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t lReplacement = pop_nodestack();
  expr_t lTarget = pop_nodestack();

  if (v.getType() == store::UpdateConsts::NODE)
  {
    fo_expr_t lEnclosed = new fo_expr(theRootSctx, loc, op_enclosed, lReplacement);
    lReplacement = lEnclosed;
  }

  expr_t lReplace = new replace_expr(theRootSctx, loc,
                                     v.getType(),
                                     lTarget,
                                     lReplacement);
  push_nodestack(lReplace);
}


void* begin_visit(const TransformExpr& v)
{
  TRACE_VISIT();

  transform_expr* transformExpr = new transform_expr(theRootSctx, loc);

  push_nodestack(transformExpr);

  return no_state;
}

void end_visit(const TransformExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr_t returnExpr = pop_nodestack();
  expr_t modifyExpr = pop_nodestack();

  transform_expr* transformExpr =
  dynamic_cast<transform_expr*>(theNodeStack.top().getp());
  assert(transformExpr != NULL);

  transformExpr->setModifyExpr(modifyExpr);
  transformExpr->setReturnExpr(returnExpr);

  const size_t lSize = v.get_var_list()->size();
  for (size_t i = 0; i < lSize; ++i)
  {
    pop_scope();
  }
}


void* begin_visit(const CopyVarList& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const CopyVarList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


void* begin_visit(const VarBinding& v)
{
  TRACE_VISIT();

  push_scope();
  var_expr_t ve = bind_var(loc, v.get_varname(), var_expr::copy_var);
  push_nodestack(ve.getp());

  return no_state;
}

void end_visit(const VarBinding& v, void*)
{
  TRACE_VISIT_OUT ();

  expr_t sourceExpr = pop_nodestack();
  if (sourceExpr->is_updating())
    throw XQUERY_EXCEPTION(err::XUST0001, ERROR_LOC(loc));

  var_expr_t varExpr = pop_nodestack_var();

  transform_expr* transformExpr =
  dynamic_cast<transform_expr*>(theNodeStack.top().getp());
  assert(transformExpr != NULL);

  copy_clause* copyClause = new copy_clause(varExpr, sourceExpr);

  transformExpr->add_back(copyClause);
}



////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Full-Text                                                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


#ifndef ZORBA_NO_FULL_TEXT
template<typename FTNodeType> bool flatten( ftnode *n ) {
  if ( FTNodeType *const n2 = dynamic_cast<FTNodeType*>( n ) ) {
    typename FTNodeType::ftnode_list_t &list = n2->get_node_list();
    typename FTNodeType::ftnode_list_t::iterator i = list.begin();
    while ( i != list.end() ) {
      push_ftstack( *i );
      i = list.erase( i );
    }
    delete n;
    return true;
  }
  return false;
}
#endif /* ZORBA_NO_FULL_TEXT */

void *begin_visit (const FTAnd& v) {
  TRACE_VISIT ();
#ifndef ZORBA_NO_FULL_TEXT
  push_ftstack( NULL ); // sentinel
#endif /* ZORBA_NO_FULL_TEXT */
  return no_state;
}

void end_visit (const FTAnd& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftand::ftnode_list_t list;
  while ( true ) {
    ftnode *const n = pop_ftstack();
    if ( !n )
      break;
    if ( !flatten<ftand>( n ) ) {
      //
      // We must use push_front() to maintain the original left-to-right order
      // of the query.
      //
      list.push_front( n );
    }
  }
  push_ftstack( new ftand( loc, list ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTAnyallOption& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTAnyallOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  // nothing to do
}

void *begin_visit (const FTBigUnit& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTBigUnit& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  // nothing to do
}

void *begin_visit (const FTCaseOption& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTCaseOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftmatch_options *const mo = dynamic_cast<ftmatch_options*>( top_ftstack() );
  ZORBA_ASSERT( mo );
  if ( mo->get_case_option() )
    throw XQUERY_EXCEPTION(
      err::FTST0019, ERROR_PARAMS( "case" ), ERROR_LOC( loc )
    );
  mo->set_case_option( new ftcase_option( loc, v.get_mode() ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTContainsExpr& v) {
  TRACE_VISIT ();
#ifdef ZORBA_NO_FULL_TEXT
  throw XQUERY_EXCEPTION(
    err::XPST0003, ERROR_PARAMS( ZED( FullTextNotEnabled ) ), ERROR_LOC( loc )
  );
#endif /* ZORBA_NO_FULL_TEXT */
  return no_state;
}

void end_visit (const FTContainsExpr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  expr_t ftignore = NULL;
  if ( v.get_ignore() )
    ftignore = pop_nodestack();

  ftselection *const selection = dynamic_cast<ftselection*>( pop_ftstack() );
  ZORBA_ASSERT( selection );

  expr_t range = pop_nodestack();
  ZORBA_ASSERT( range );

  ftcontains_expr *const e =
    new ftcontains_expr( theRootSctx, loc, range, selection, ftignore );
  push_nodestack( e );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTContent& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTContent& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  push_ftstack( new ftcontent_filter( loc, v.get_mode() ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTDiacriticsOption& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTDiacriticsOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftmatch_options *const mo = dynamic_cast<ftmatch_options*>( top_ftstack() );
  ZORBA_ASSERT( mo );
  if ( mo->get_diacritics_option() )
    throw XQUERY_EXCEPTION(
      err::FTST0019, ERROR_PARAMS( "diacriticics" ), ERROR_LOC( loc )
    );
  mo->set_diacritics_option( new ftdiacritics_option( loc, v.get_mode() ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTDistance& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTDistance& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftdistance_filter *const df = new ftdistance_filter(
    loc, dynamic_cast<ftrange*>( pop_ftstack() ), v.get_unit()->get_unit()
  );
  push_ftstack( df );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTExtensionOption& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTExtensionOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  rchandle<QName> const &qname = v.get_qname();
  zstring ns;
  theSctx->lookup_ns( ns, qname->get_prefix(), loc );

  ftmatch_options *const mo = dynamic_cast<ftmatch_options*>( top_ftstack() );
  ZORBA_ASSERT( mo );
  mo->add_extension_option( new ftextension_option( loc, qname, v.get_val() ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTExtensionSelection& v) {
  TRACE_VISIT ();
  // TODO
  return no_state;
}

void end_visit (const FTExtensionSelection& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftselection *const s = dynamic_cast<ftselection*>( top_ftstack() );
  if ( s )
    pop_ftstack();
  else
    throw XQUERY_EXCEPTION( err::XQST0079, ERROR_LOC( loc ) );
  push_ftstack( new ftextension_selection( loc, v.get_pragma_list(), s ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTIgnoreOption& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTIgnoreOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  expr_t e( pop_nodestack() );
  push_nodestack( wrap_in_type_promotion( e, theRTM.ANY_NODE_TYPE_STAR ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTLanguageOption& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTLanguageOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftmatch_options *const mo = dynamic_cast<ftmatch_options*>( top_ftstack() );
  ZORBA_ASSERT( mo );
  if ( mo->get_language_option() )
    throw XQUERY_EXCEPTION(
      err::FTST0019, ERROR_PARAMS( "language" ), ERROR_LOC( loc )
    );
  mo->set_language_option( new ftlanguage_option( loc, v.get_language() ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTMatchOptions& v) {
  TRACE_VISIT ();
#ifndef ZORBA_NO_FULL_TEXT
  push_ftstack( new ftmatch_options( loc ) );
#endif /* ZORBA_NO_FULL_TEXT */
  return no_state;
}

void end_visit (const FTMatchOptions& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  // nothing to do
}

void *begin_visit (const FTMildNot& v) {
  TRACE_VISIT ();
#ifndef ZORBA_NO_FULL_TEXT
  push_ftstack( NULL ); // sentinel
#endif /* ZORBA_NO_FULL_TEXT */
  return no_state;
}

void end_visit (const FTMildNot& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftmild_not::ftnode_list_t list;
  while ( true ) {
    ftnode *const n = pop_ftstack();
    if ( !n )
      break;
    if ( !flatten<ftmild_not>( n ) ) {
      //
      // We must use push_front() to maintain the original left-to-right order
      // of the query.
      //
      list.push_front( n );
    }
  }
  push_ftstack( new ftmild_not( loc, list ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTOptionDecl& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTOptionDecl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftmatch_options *const mo = dynamic_cast<ftmatch_options*>( pop_ftstack() );
  ZORBA_ASSERT( mo );
  theSctx->set_match_options( mo );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTOr& v) {
  TRACE_VISIT ();
#ifndef ZORBA_NO_FULL_TEXT
  push_ftstack( NULL ); // sentinel
#endif /* ZORBA_NO_FULL_TEXT */
  return no_state;
}

void end_visit (const FTOr& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftor::ftnode_list_t list;
  while ( true ) {
    ftnode *const n = pop_ftstack();
    if ( !n )
      break;
    if ( !flatten<ftor>( n ) ) {
      //
      // We must use push_front() to maintain the original left-to-right order
      // of the query.
      //
      list.push_front( n );
    }
  }
  push_ftstack( new ftor( loc, list ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTOrder& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTOrder& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  push_ftstack( new ftorder_filter( loc ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTPrimaryWithOptions& v) {
  TRACE_VISIT ();
#ifndef ZORBA_NO_FULL_TEXT
  push_ftstack( new ftprimary_with_options( loc ) );
#endif /* ZORBA_NO_FULL_TEXT */
  return no_state;
}

void end_visit (const FTPrimaryWithOptions& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftweight *const w = dynamic_cast<ftweight*>( top_ftstack() );
  if ( w )
    pop_ftstack();

  ftmatch_options *const mo = dynamic_cast<ftmatch_options*>( top_ftstack() );
  if ( mo )
    pop_ftstack();

  ftprimary *const p = dynamic_cast<ftprimary*>( pop_ftstack() );
  ZORBA_ASSERT( p );

  ftprimary_with_options *const pwo =
    dynamic_cast<ftprimary_with_options*>( top_ftstack() );
  ZORBA_ASSERT( pwo );

  pwo->set_primary( p );
  if ( mo )
    pwo->set_match_options( mo );
  if ( w )
    pwo->set_weight( w );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTRange& v) {
  TRACE_VISIT ();
#ifndef ZORBA_NO_FULL_TEXT
  push_nodestack( NULL ); // sentinel
#endif /* ZORBA_NO_FULL_TEXT */
  return no_state;
}

void end_visit (const FTRange& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  expr_t e2 = pop_nodestack();
  expr_t e1 = pop_nodestack();
  if ( e1 )
    pop_nodestack(); // pop the sentinel
  else {
    e1 = e2;
    e2 = NULL;
  }

  if ( e1 ) {
    e1 = wrap_in_atomization( e1 );
    e1 = wrap_in_type_promotion( e1, theRTM.INTEGER_TYPE_ONE );
  }
  if ( e2 ) {
    e2 = wrap_in_atomization( e2 );
    e2 = wrap_in_type_promotion( e2, theRTM.INTEGER_TYPE_ONE );
  }

  ftrange *const r = new ftrange( loc, v.get_mode(), e1, e2 );
  push_ftstack( r );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTScope& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTScope& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftscope_filter *const sf =
    new ftscope_filter( loc, v.get_scope(), v.get_big_unit()->get_unit() );
  push_ftstack( sf );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTScoreVar& v) {
  TRACE_VISIT ();
  throw XQUERY_EXCEPTION(
    zerr::ZXQP0004_NOT_IMPLEMENTED, ERROR_PARAMS( "score" ), ERROR_LOC( loc )
  );
}

void end_visit (const FTScoreVar& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  // TODO
}

void *begin_visit (const FTSelection& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTSelection& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftselection::ftpos_filter_list_t list;
  while ( true ) {
    ftnode *const n = pop_ftstack();
    if ( ftpos_filter *const pf = dynamic_cast<ftpos_filter*>( n ) ) {
      //
      // We must use push_front() to maintain the original left-to-right order
      // of the query.
      //
      list.push_front( pf );
    } else {
      push_ftstack( new ftselection( loc, n, list ) );
      break;
    }
  }
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTStemOption& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTStemOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftmatch_options *const mo = dynamic_cast<ftmatch_options*>( top_ftstack() );
  ZORBA_ASSERT( mo );
  if ( mo->get_stem_option() )
    throw XQUERY_EXCEPTION(
      err::FTST0019, ERROR_PARAMS( "stem" ), ERROR_LOC( loc )
    );
  mo->set_stem_option( new ftstem_option( loc, v.get_mode() ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTStopWords& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTStopWords& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftstop_words *const sw = new ftstop_words(
    loc, v.get_uri(), v.get_stop_words()
  );
  push_ftstack( sw );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTStopWordsInclExcl& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTStopWordsInclExcl& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftstop_words *const sw = dynamic_cast<ftstop_words*>( top_ftstack() );
  ZORBA_ASSERT( sw );
  sw->set_mode( v.get_mode() );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTStopWordOption& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTStopWordOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  if ( v.get_mode() == ft_stop_words_mode::without )
    return;
  ftstop_word_option::list_t stop_words;
  while ( true ) {
    ftnode *const n = top_ftstack();
    if ( ftstop_words *const sw = dynamic_cast<ftstop_words*>( n ) ) {
      //
      // We must use push_front() to maintain the original left-to-right order
      // of the query.
      //
      stop_words.push_front( sw );
      pop_ftstack();
    } else
      break;
  }
  ftmatch_options *const mo = dynamic_cast<ftmatch_options*>( top_ftstack() );
  ZORBA_ASSERT( mo );
  if ( mo->get_stop_word_option() )
    throw XQUERY_EXCEPTION(
      err::FTST0019, ERROR_PARAMS( "stop words" ), ERROR_LOC( loc )
    );
  ftstop_word_option *const sw =
    new ftstop_word_option( loc, stop_words, v.get_mode() );
  mo->set_stop_word_option( sw );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTThesaurusID& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTThesaurusID& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftrange *levels;
  if ( v.get_levels() ) {
    levels = dynamic_cast<ftrange*>( pop_ftstack() );
    ZORBA_ASSERT( levels );
  } else
    levels = NULL;

  ftthesaurus_id *const tid = new ftthesaurus_id(
    loc, v.get_uri(), v.get_relationship(), levels
  );
  push_ftstack( tid );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTThesaurusOption& v) {
  TRACE_VISIT ();
#ifndef ZORBA_NO_FULL_TEXT
  push_ftstack( NULL ); // sentinel
#endif /* ZORBA_NO_FULL_TEXT */
  return no_state;
}

void end_visit (const FTThesaurusOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftthesaurus_id *default_tid = NULL;
  if ( v.includes_default() ) {
    default_tid = new ftthesaurus_id( loc, "##default" );
  }

  ftthesaurus_option::thesaurus_id_list_t list;
  while ( true ) {
    ftthesaurus_id *const tid = dynamic_cast<ftthesaurus_id*>( pop_ftstack() );
    if ( tid )
      list.push_back( tid );
    else
      break;
  }
  ftmatch_options *const mo = dynamic_cast<ftmatch_options*>( top_ftstack() );
  ZORBA_ASSERT( mo );
  if ( mo->get_thesaurus_option() )
    throw XQUERY_EXCEPTION(
      err::FTST0019, ERROR_PARAMS( "thesaurus" ), ERROR_LOC( loc )
    );
  ftthesaurus_option *const t =
    new ftthesaurus_option( loc, default_tid, list, v.no_thesaurus() );
  mo->set_thesaurus_option( t );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTTimes& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTTimes& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  // nothing to do
}

void *begin_visit (const FTUnaryNot& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTUnaryNot& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  push_ftstack( new ftunary_not( loc, pop_ftstack() ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTUnit& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTUnit& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  // nothing to do
}

void *begin_visit (const FTWeight& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTWeight& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  expr_t e( pop_nodestack() );
  e = wrap_in_atomization( e );
  e = wrap_in_type_promotion( e, theRTM.DOUBLE_TYPE_ONE );
  push_ftstack( new ftweight( loc, e ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTWildCardOption& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTWildCardOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftmatch_options *const mo = dynamic_cast<ftmatch_options*>( top_ftstack() );
  ZORBA_ASSERT( mo );
  if ( mo->get_wild_card_option() )
    throw XQUERY_EXCEPTION(
      err::FTST0019, ERROR_PARAMS( "wildcards" ), ERROR_LOC( loc )
    );
  mo->set_wild_card_option( new ftwild_card_option( loc, v.get_mode() ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTWindow& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTWindow& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  expr_t e( pop_nodestack() );
  e = wrap_in_atomization( e );
  e = wrap_in_type_promotion( e, theRTM.INTEGER_TYPE_ONE );
  push_ftstack( new ftwindow_filter( loc, e, v.get_unit()->get_unit() ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTWords& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTWords& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  expr_t e( pop_nodestack() );
  e = wrap_in_atomization( e );
  e = wrap_in_type_promotion( e, theRTM.STRING_TYPE_STAR );
  push_ftstack( new ftwords( loc, e, v.get_any_all_option()->get_option() ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTWordsTimes& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTWordsTimes& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftrange *const times = dynamic_cast<ftrange*>( top_ftstack() );
  if ( times )
    pop_ftstack();
  ftwords *const words = dynamic_cast<ftwords*>( pop_ftstack() );
  push_ftstack( new ftwords_times( loc, words, times ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTWordsValue& v) {
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTWordsValue& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  // nothing to do
}

///////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void* begin_visit(const ParseErrorNode& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const ParseErrorNode& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************

********************************************************************************/
void* begin_visit(const exprnode& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const exprnode& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


public:

/*******************************************************************************

********************************************************************************/
expr_t result()
{
  if (theNodeStack.size() != 1)
  {
    std::cout << "Error: extra nodes on translator stack:\n";
    while (! theNodeStack.empty())
    {
      expr_t e_h = pop_nodestack();
#ifndef NDEBUG
      if (! Properties::instance()->traceTranslator())
      {
        if (e_h != NULL)
          e_h->put(std::cout) << std::endl;
        else
          std::cout << "NULL" << std::endl;
      }
#endif
    }
    ZORBA_ASSERT (false);
  }

  ZORBA_ASSERT(theTypeStack.size() == 0);

  if (theScopeDepth != 0)
  {
    std::cout << "Error: scope depth " << theScopeDepth << std::endl;
    ZORBA_ASSERT(false);
  }

  return pop_nodestack();
}

};


/*******************************************************************************
  Translate a module.
********************************************************************************/
expr_t translate_aux(
    TranslatorImpl* rootTranslator,
    const parsenode& root,
    static_context* rootSctx,
    short rootSctxId,
    ModulesInfo* minfo,
    const std::map<zstring, zstring>& modulesStack,
    bool isLibModule,
    StaticContextConsts::xquery_version_t maxLibModuleVersion)
{
  std::auto_ptr<TranslatorImpl> t(new TranslatorImpl(rootTranslator,
                                                     rootSctx,
                                                     rootSctxId,
                                                     minfo,
                                                     modulesStack,
                                                     isLibModule,
                                                     maxLibModuleVersion));

  root.accept(*t);

  rchandle<expr> result = t->result();

  CompilerCB* ccb = minfo->theCCB;
  if (ccb->theConfig.translate_cb != NULL)
    ccb->theConfig.translate_cb(&*result, "XQuery program");

  return result;
}



/*******************************************************************************
  Translate a main module.
********************************************************************************/
expr_t translate(const parsenode& root, CompilerCB* ccb)
{
  std::map<zstring, zstring> modulesStack;

  if (typeid(root) != typeid(MainModule))
    throw XQUERY_EXCEPTION(
      err::XPST0003, ERROR_PARAMS( ZED( ModuleDeclNotInMain ) ),
      ERROR_LOC( root.get_location() )
    );

  ModulesInfo minfo(ccb);

  return translate_aux(NULL,
                       root,
                       ccb->theRootSctx,
                       (short)ccb->theSctxMap.size(),
                       &minfo,
                       modulesStack,
                       false);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
