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
#include "compiler/expression/json_exprs.h"
#include "compiler/expression/update_exprs.h"
#ifndef ZORBA_NO_FULL_TEXT
#include "compiler/expression/ft_expr.h"
#include "compiler/expression/ftnode.h"
#endif /* ZORBA_NO_FULL_TEXT */
#include "compiler/expression/var_expr.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/path_expr.h"
#include "compiler/expression/function_item_expr.h"
#include "compiler/expression/pragma.h"
#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/rewriter/framework/rewriter.h"
#include "compiler/rewriter/tools/expr_tools.h"
#include "compiler/xqddf/value_index.h"
#include "compiler/xqddf/value_ic.h"
#include "compiler/xqddf/collection_decl.h"

#include "system/globalenv.h"
#include "system/properties.h"

#include "functions/library.h"
#include "functions/signature.h"
#include "functions/udf.h"
#include "functions/external_function.h"
#include "functions/func_ft_module.h"
#include "functions/func_ft_module_impl.h"

#include "annotations/annotations.h"

#include "context/static_context.h"
#include "context/static_context_consts.h"
#include "context/namespace_context.h"
#include "context/dynamic_context.h"

#include "types/node_test.h"
#include "types/casting.h"
#include "types/typeops.h"
#include "types/typemanagerimpl.h"
#include "types/schema/schema.h"

#include "zorbatypes/URI.h"
#include "zorbatypes/numconversions.h"
#include "zorbamisc/ns_consts.h"

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

static expr* translate_aux(
    TranslatorImpl* rootTranslator,
    const parsenode& root,
    static_context* rootSctx,
    csize rootSctxId,
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
#define CREATE(kind) theExprManager->create_##kind##_expr


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
  theExprManager->create_wrapper_expr(theRootSctx,          \
                                      theUDF,               \
                                      loc,                  \
                                      lookup_ctx_var(DOT_VARNAME, loc))

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
  checked_vector<expr*>              theInitExprs;
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

  theExitExprs:
  -------------
  This vector stores the exit_exprs that are encountered during the translation
  of the body of a UDF. It is used to associated those exot_exprs with the
  exit_catcher_expr that is added at the top of the UDF body.

  theHaveUpdatingExitExprs :
  --------------------------

  theHaveSequentialExitExprs :
  ----------------------------

  theHaveContextItemDecl :
  ------------------------

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

  ExprManager                          * theExprManager;

  ModulesInfo                          * theModulesInfo;
  std::map<zstring, zstring>             theModulesStack;
  bool                                   theHaveModuleImportCycle;
  std::set<std::string>                  theImportedModules;
  zstring                                theModuleNamespace;
  zstring                                theModulePrefix;

  std::set<std::string>                  theImportedSchemas;

  csize                                  theCurrSctxId;

  static_context                       * theRootSctx;

  static_context                       * theSctx;

  std::vector<static_context_t>          theSctxList;

  std::stack<csize>                      theSctxIdStack;

  static_context                       * export_sctx;

  rchandle<namespace_context>            theNSCtx;

  ulong                                  thePrintDepth;
  int                                    theScopeDepth;

  user_function                        * theUDF;

  std::list<GlobalBinding>               thePrologVars;

  PrologGraph                            thePrologGraph;
  PrologGraphVertex                      theCurrentPrologVFDecl;

  std::vector<expr*>                     theExitExprs;

  bool                                   theHaveUpdatingExitExprs;

  bool                                   theHaveSequentialExitExprs;

  bool                                   theHaveContextItemDecl;

  std::vector<std::vector<var_expr*> >   theAssignedVars;

  int                                    theTempVarCounter;

  std::stack<expr*>                      theNodeStack;

#ifndef ZORBA_NO_FULL_TEXT
  std::stack<ftnode*>                    theFTNodeStack;
#endif

  std::stack<xqtref_t>                   theTypeStack;

  std::vector<flwor_clause*>             theFlworClausesStack;

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

  rchandle<QName>                      theDotVarName;
  rchandle<QName>                      theDotPosVarName;
  rchandle<QName>                      theLastIdxVarName;

  std::vector<var_expr*>              theScopedVars;

  std::vector<pragma*>                theScopedPragmas;

  StaticContextConsts::xquery_version_t theMaxLibModuleVersion;

public:

TranslatorImpl(
    TranslatorImpl* rootTranslator,
    static_context* rootSctx,
    csize rootSctxId,
    ModulesInfo* minfo,
    const std::map<zstring, zstring>& modulesStack,
    bool isLibModule,
    StaticContextConsts::xquery_version_t maxLibModuleVersion =
      StaticContextConsts::xquery_version_unknown)
  :
  theRootTranslator(rootTranslator),
  theRTM(GENV_TYPESYSTEM),
  theCCB(minfo->theCCB),
  theExprManager(theCCB->theEM),
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
  theUDF(NULL),
  thePrologGraph(rootSctx),
  theHaveUpdatingExitExprs(false),
  theHaveSequentialExitExprs(false),
  theHaveContextItemDecl(false),
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
  xquery_fns_def_dot.set(FunctionConsts::FN_NILLED_0);
  xquery_fns_def_dot.set(FunctionConsts::FN_HAS_CHILDREN_0);
  xquery_fns_def_dot.set(FunctionConsts::FN_PATH_0);
  xquery_fns_def_dot.set(FunctionConsts::FN_NUMBER_0);


  op_concatenate = BUILTIN_FUNC(OP_CONCATENATE_N);
  assert(op_concatenate != NULL);

  if (rootTranslator == NULL)
  {
    QueryLoc loc;
    theDotVarName = new QName(loc, static_context::DOT_VAR_NAME);
    theDotPosVarName = new QName(loc, static_context::DOT_POS_VAR_NAME);
    theLastIdxVarName = new QName(loc, static_context::DOT_SIZE_VAR_NAME);

    theRootTranslator = this;
  }
}


~TranslatorImpl()
{
#ifndef ZORBA_NO_FULL_TEXT
  while (!theFTNodeStack.empty())
    delete ztd::pop_stack(theFTNodeStack);
#endif
}


const QName* getDotVarName() const
{
  return theRootTranslator->theDotVarName;
}


const QName* getDotPosVarName() const
{
  return theRootTranslator->theDotPosVarName;
}

const QName* getLastIdxVarName() const
{
  return theRootTranslator->theLastIdxVarName;
}



/*******************************************************************************
  Pop the top n exprs from theNodeStack and return the last expr that was popped.
********************************************************************************/
expr* pop_nodestack(int n = 1)
{
  ZORBA_ASSERT(n >= 0);

  expr* e_h;

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
inline void push_nodestack(expr* e)
{
  theNodeStack.push(e);

#ifndef NDEBUG
  if (Properties::instance()->traceTranslator())
  {
    std::cout << "Pushed to nodestack: \n";
    if (e != NULL)
      e->put(std::cout) << std::endl;
    else
      std::cout << "NULL" << std::endl;
  }
#endif
}


/*******************************************************************************
  Assert that the top expr in theNodeStack is a var_expr and pop it.
********************************************************************************/
var_expr* pop_nodestack_var()
{
  expr* e = pop_nodestack();
  assert (e == NULL || e->get_expr_kind() == var_expr_kind);
  return static_cast<var_expr *>(e);
}


/*******************************************************************************
  Return rchandle to the expr at the top of theNodeStack, or NULL if theNodeStack
  is empty.
********************************************************************************/
expr* peek_nodestk_or_null()
{
  return (theNodeStack.empty()) ? NULL : theNodeStack.top();
}


/*******************************************************************************
  Return rchandle to the expr at the top of theNodeStack (crash if theNodeStack
  is empty).
********************************************************************************/
expr* top_nodestack()
{
  ZORBA_FATAL( !theNodeStack.empty(), "" );
  return theNodeStack.top();
}


/*******************************************************************************
  Check if the top expr in theNodeStack is an axis_step, and if so return
  rchandle to it (but do not pop). Otherwise, raise error.
********************************************************************************/
axis_step_expr* expect_axis_step_top()
{
  axis_step_expr* axisExpr =
    dynamic_cast<axis_step_expr*>(peek_nodestk_or_null());

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

  ftnode *n = nullptr;
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
  return (!theCurrentPrologVFDecl.isNull() && theCurrentPrologVFDecl.isUDF());
}


/******************************************************************************

*******************************************************************************/
inline csize sctxid()
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
    theCurrSctxId = theCCB->theSctxMap.size() + 1;
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

  Raise error is the prefix is non-empty and there is no ns associated with it.

  This method is used during the processing of function declarations (when the
  function object is not supposed to exist already).
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

********************************************************************************/
void expand_type_qname(
    store::Item_t& qnameItem,
    const QName* qname,
    const QueryLoc& loc) const
{
  if (!qname->get_prefix().empty() ||
      theSctx->language_kind() == StaticContextConsts::language_kind_xquery)
  {
    expand_elem_qname(qnameItem, qname, loc);
  }
  else
  {
    zstring local = qname->get_localname();
    zstring ns;

    if (local == "null")
    {
      ns = static_context::JSONIQ_DM_NS;
    }
    else if (local == "atomic")
    {
      ns = XML_SCHEMA_NS;
      local = "anyAtomicType";
    }
    else
    {
      ns = XML_SCHEMA_NS;
    }

    GENV_ITEMFACTORY->createQName(qnameItem, ns, "", local);
  }
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
var_expr* create_var(
    const QueryLoc& loc,
    store::Item* qname,
    var_expr::var_kind kind,
    xqtref_t type = NULL)
{
  var_expr* e = theExprManager->
  create_var_expr(theRootSctx, theUDF, loc, kind, qname);

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
var_expr* create_var(
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
var_expr* create_temp_var(const QueryLoc& loc, var_expr::var_kind kind)
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
void bind_var(var_expr* e, static_context* sctx)
{
  assert(sctx != NULL);

  sctx->bind_var(e, e->get_loc());
}


/*******************************************************************************
  Create a var_expr for a variable with a given qname item, kind, and type.
  Then, create a binding in the given sctx between the var qname item and the
  var_expr. Raise error if a var with the same expanded qname item is already
  in the given sctx obj.
********************************************************************************/
var_expr* bind_var(
    const QueryLoc& loc,
    store::Item* qname,
    var_expr::var_kind kind,
    xqtref_t type = NULL)
{
  var_expr* e = create_var(loc, qname, kind, type);
  bind_var(e, theSctx);
  return e;
}


/*******************************************************************************
  Create a var_expr for a variable with a given qname, kind, and type. Then,
  create a binding in the given sctx between the var qname item and the var_expr.
  Raise error if a var with the same expanded qname item is already in the
  given sctx obj or if the expansion of the given qname to a qname item fails.
********************************************************************************/
var_expr* bind_var(
    const QueryLoc& loc,
    const QName* qname,
    var_expr::var_kind kind,
    xqtref_t type = NULL)
{
  var_expr* e = create_var(loc, qname, kind, type);
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
var_expr* lookup_ctx_var(const QName* qname, const QueryLoc& loc)
{
  store::Item_t qnameItem;
  expand_no_default_qname(qnameItem, qname, loc);

  VarInfo* var = theSctx->lookup_var(qnameItem.getp());

  if (var == NULL)
  {
    if (theIsInIndexDomain)
    {
      RAISE_ERROR(zerr::ZDST0032_INDEX_REFERENCES_CTX_ITEM, loc,
      ERROR_PARAMS(theIndexDecl->getName()->getStringValue()));
    }
    else
    {
      zstring varName = static_context::var_name(qnameItem);
      RAISE_ERROR(err::XPDY0002, loc, 
      ERROR_PARAMS(ZED(XPDY0002_ContextUndeclared_2), varName));
    }
  }

  return var->getVar();
}


/*******************************************************************************
  Lookup variable by lexical qname. Search starts from the "current" ctx and
  moves upwards the ancestor path until the first instance (if any) of the var
  is found.

  If the lexical qname has a prefix for which no namespace binding exists, the
  method raises error.

  If var is not found, the method raises XPST0008, unless the raiseError param
  is alse, in which case it returns NULL.
********************************************************************************/
var_expr* lookup_var(const QName* qname, const QueryLoc& loc, bool raiseError)
{
  store::Item_t qnameItem;
  expand_no_default_qname(qnameItem, qname, loc);

  VarInfo* var = theSctx->lookup_var(qnameItem.getp());

  if (!var)
  {
    if (raiseError)
    {
      zstring varName = static_context::var_name(qnameItem);
      RAISE_ERROR(err::XPST0008, loc,
      ERROR_PARAMS(ZED(XPST0008_VariableName_2), varName));
    }

    return NULL;
  }

  return var->getVar();
}


/*******************************************************************************
  Lookup variable by expanded qname. Search starts from the "current" sctx and
  moves upwards the ancestor path until the first instance (if any) of the var
  is found.

  If var is not found, the method raises XPST0008, unless the raiseError param
  is alse, in which case it returns NULL.
********************************************************************************/
var_expr* lookup_var(const store::Item* qname, const QueryLoc& loc, bool raiseError)
{
  VarInfo* var = theSctx->lookup_var(qname);

  if (!var)
  {
    if (raiseError)
    {
      zstring varName = static_context::var_name(qname);
      RAISE_ERROR(err::XPST0008, loc,
      ERROR_PARAMS(ZED(XPST0008_VariableName_2), varName));
    }

    return NULL;
  }

  return var->getVar();
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
    csize nargs,
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
  local name and arity. Raise error if the prefix is non-empty and does not have
  an associated namespace. Return NULL if such a function is not found.
********************************************************************************/
function* lookup_fn(const QName* qname, csize arity, const QueryLoc& loc)
{
  return theSctx->lookup_fn(qname->get_namespace(),
                            qname->get_prefix(),
                            qname->get_localname(),
                            arity,
                            loc);
}


/*******************************************************************************
  Create an fn:concatenate() expr
********************************************************************************/
fo_expr* create_empty_seq(const QueryLoc& loc)
{
  return theExprManager->create_seq(theRootSctx, theUDF, loc);
}


/*******************************************************************************

********************************************************************************/
expr* wrap_in_coercion(
    xqtref_t targetType,
    expr* theExpr,
    const QueryLoc& loc,
    CompilerCB* theCCB,
    bool is_func_return = false)
{
  const FunctionXQType* func_type = static_cast<const FunctionXQType*>(targetType.getp());

  // Create the dynamic call body

  static_context* closureSctx = theRootSctx->create_child_context();
  theCCB->theSctxMap[theCCB->theSctxMap.size() + 1] = closureSctx;
  function_item_expr* fiExpr = theExprManager->create_function_item_expr(theRootSctx, theUDF, loc, closureSctx, true, false, true /* isCoercion */);
  push_nodestack(fiExpr);

  push_scope();

  // handle the function item expression
  flwor_expr* fnItem_flwor = theExprManager->create_flwor_expr(theRootSctx, theUDF, loc, false);
  for_clause* fnItem_fc = wrap_in_forclause(theExpr, NULL);
  var_expr* fnItem_var = fnItem_fc->get_var();
  fnItem_flwor->add_clause(fnItem_fc);
  var_expr* inner_subst_var = bind_var(loc, fnItem_var->get_name(), var_expr::hof_var);
  fiExpr->add_variable(fnItem_var, inner_subst_var, fnItem_var->get_name(), 0 /*var is not global*/);

  // bind the function item variable in the inner flwor
  flwor_expr* inner_flwor = theExprManager->create_flwor_expr(theRootSctx, theUDF, loc, false);
  var_expr* inner_arg_var = create_var(loc, fnItem_var->get_name(), var_expr::let_var);
  inner_arg_var->set_param_pos(inner_flwor->num_clauses());

  // Handle parameters. For each parameter, a let binding is added to the inner flwor.
  std::vector<expr*> arguments;    // Arguments to the dynamic function call
  for(unsigned i = 0; i<func_type->get_number_params(); i++)
  {
    xqtref_t paramType = func_type->operator[](i);

    var_expr* arg_var = create_temp_var(loc, var_expr::arg_var);
    var_expr* subst_var = bind_var(loc, arg_var->get_name(), var_expr::let_var);
    let_clause* lc = wrap_in_letclause(&*arg_var, subst_var);

    arg_var->set_param_pos(inner_flwor->num_clauses());
    arg_var->set_type(paramType);

    inner_flwor->add_clause(lc);

    arguments.push_back(theExprManager->create_wrapper_expr(theRootSctx, theUDF, loc, subst_var));
  }

  if (inner_flwor->num_clauses() == 0)
  {
    inner_flwor = NULL;
  }

  expr* body = CREATE(dynamic_function_invocation)(
                theRootSctx,
                theUDF,
                loc,
                CREATE(wrapper)(theRootSctx, theUDF, loc, inner_subst_var),
                arguments,
                NULL);

  create_inline_function(body,
                         inner_flwor,
                         func_type->get_param_types(),
                         func_type->get_return_type(),
                         loc,
                         true);

  theExpr = pop_nodestack();
  fnItem_flwor->set_return_expr(theExpr);
  theExpr = fnItem_flwor;

  // pop the scope.
  pop_scope();

  return theExpr;
}


/*******************************************************************************

********************************************************************************/
expr* normalize_fo_arg(
    csize i,
    expr* argExpr,
    const function* func,
    const QueryLoc& loc)
{
  xqtref_t paramType;

  const signature& sign = func->getSignature();

  TypeManager* tm = argExpr->get_type_manager();

  switch (func->getKind())
  {
  case FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_POINT_VALUE_N:
  {
    if (i == 0)
      paramType = sign[i];
    else
      paramType = theRTM.ANY_ATOMIC_TYPE_QUESTION;

    break;
  }
  case FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_POINT_VALUE_SKIP_N:
  {
    if (i <= 1)
      paramType = sign[i];
    else
      paramType = theRTM.ANY_ATOMIC_TYPE_QUESTION;

    break;
  }
  case FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_RANGE_VALUE_N:
  {
    if (i == 0)
      paramType = sign[i];
    else if (i % 6 == 1 || i % 6 == 2)
      paramType = theRTM.ANY_ATOMIC_TYPE_QUESTION;
    else
      paramType = theRTM.BOOLEAN_TYPE_ONE;

    break;
  }
  case FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_RANGE_VALUE_SKIP_N:
  {
    if (i <= 1)
      paramType = sign[i];
    else if (i % 6 == 2 || i % 6 == 3)
      paramType = theRTM.ANY_ATOMIC_TYPE_QUESTION;
    else
      paramType = theRTM.BOOLEAN_TYPE_ONE;

    break;
  }
  case FunctionConsts::FN_ZORBA_INVOKE_N:
  case FunctionConsts::FN_ZORBA_INVOKE_N_N:
  case FunctionConsts::FN_ZORBA_INVOKE_U_N:
  case FunctionConsts::FN_ZORBA_INVOKE_S_N:
  {
    if (i == 0)
      paramType = sign[i];
    else
      paramType = NULL; // Nothing to check as the target function is not known

    break;
  }
  default:
  {
    paramType = sign[i];
  }
  }

  // A NULL value for the parameter's type to signal that no type promotion
  // or match should be added. This is used by the reflection:invoke() function,
  if (paramType != NULL)
  {
    if (TypeOps::is_subtype(tm, *paramType, *theRTM.ANY_ATOMIC_TYPE_STAR, loc))
    {
      argExpr = wrap_in_type_promotion(argExpr,
                                       paramType,
                                       PROMOTE_FUNC_PARAM,
                                       func->getName());
    }
    else
    {
      if (paramType->type_kind() == XQType::FUNCTION_TYPE_KIND)
      {
        // function coercion
        argExpr = wrap_in_coercion(paramType, argExpr, loc, theCCB);
      }

      argExpr = wrap_in_type_match(argExpr,
                                   paramType,
                                   loc,
                                   TREAT_FUNC_PARAM,
                                   func->getName());
    }
  }

  return argExpr;
}


/*******************************************************************************

********************************************************************************/
void normalize_fo(fo_expr* foExpr)
{
  const QueryLoc& loc = foExpr->get_loc();

  csize n = foExpr->num_args();

  const function* func = foExpr->get_func();
  FunctionConsts::FunctionKind fkind = func->getKind();

  if (fkind == FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_RANGE_VALUE_N ||
      fkind == FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_RANGE_VALUE_SKIP_N)
  {
    csize nStarterParams =
    (fkind == FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_RANGE_VALUE_N  ? 1 : 2);

    if  (n < (6 + nStarterParams) || (n - nStarterParams) % 6 != 0)
    {
      const store::Item* qname = NULL;

      if (n > 0)
        qname = foExpr->get_arg(0)->getQName();

      zstring lMsgPart;
      ztd::to_string(nStarterParams, &lMsgPart);
      lMsgPart += " + multiple of 6";
      if (qname != NULL)
      {
        RAISE_ERROR(zerr::ZDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS, loc,
        ERROR_PARAMS(qname->getStringValue(), "index", n, lMsgPart));
      }
      else
      {
        RAISE_ERROR(zerr::ZDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS, loc,
        ERROR_PARAMS("anonymous", "index", n, lMsgPart));
      }
    }
  }

  for (csize i = 0; i < n; ++i)
  {
    expr* argExpr = foExpr->get_arg(i);

    argExpr = normalize_fo_arg(i, argExpr, func, loc);

    foExpr->set_arg(i, argExpr);
  }
}


/*******************************************************************************
  Wrap the given expr in an fn:data() function
********************************************************************************/
expr* wrap_in_atomization(expr* e)
{
  return CREATE(fo)(theRootSctx, theUDF, e->get_loc(), BUILTIN_FUNC(FN_DATA_1), e);
}


/*******************************************************************************

********************************************************************************/
expr* wrap_in_type_promotion(
    expr* e,
    const xqtref_t& type,
    PromoteErrorKind errorKind,
    store::Item* qname = NULL)
{
  e = wrap_in_atomization(e);

  return CREATE(promote)(theRootSctx,
                         theUDF,
                         e->get_loc(),
                         e,
                         type,
                         errorKind,
                         qname);
}


/*******************************************************************************

********************************************************************************/
expr* wrap_in_type_match(
    expr* e,
    const xqtref_t& type,
    const QueryLoc& loc,
    TreatErrorKind errorKind,
    store::Item_t qname = NULL)
{
  TypeManager* tm = e->get_type_manager();

  // treat_expr should be avoided for updating expressions, but in that case
  // "type" will be item()* anyway
  if (TypeOps::is_subtype(tm, *theRTM.ITEM_TYPE_STAR, *type, loc))
  {
    return e;
  }
  else
  {
    return theExprManager->create_treat_expr(theRootSctx,
                                             theUDF,
                                             e->get_loc(),
                                             e,
                                             type,
                                             errorKind,
                                             true,
                                             qname);
}
}


/*******************************************************************************

********************************************************************************/
fo_expr* wrap_in_enclosed_expr(expr* contentExpr, const QueryLoc& loc)
{
  return theExprManager->create_fo_expr(theRootSctx,
                                        theUDF,
                                        loc,
                                        BUILTIN_FUNC(OP_ENCLOSED_1),
                                        contentExpr);
}


/*******************************************************************************

********************************************************************************/
expr* wrap_in_bev(expr * e)
{
  fo_expr* fo = theExprManager->create_fo_expr(theRootSctx,
                                               theUDF,
                                               e->get_loc(),
                                               BUILTIN_FUNC(FN_BOOLEAN_1),
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
expr* wrap_in_dos_and_dupelim(expr* expr, bool atomics, bool reverse = false)
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

  fo_expr* dos = theExprManager->
  create_fo_expr(theRootSctx,
                 theUDF,
                 expr->get_loc(),
                 BuiltinFunctionLibrary::getFunction(fkind),
                 expr);

  normalize_fo(dos);

  return &*dos;
}


/*******************************************************************************
  Create a LET clause for the given LET variable "lv", with the given expr "e" as
  its defining expression.
********************************************************************************/
forlet_clause* wrap_in_letclause(expr* e, var_expr* lv)
{
  assert (lv->get_kind () == var_expr::let_var);

  return theExprManager->create_let_clause(theRootSctx, e->get_loc(), lv, e);
}


/*******************************************************************************
  Create a var_expr for a LET var with the given qname and add that var to the
  local sctx obj. Then, create a LET clause for this new var_expr, with the given
  expr "e" as its defining expression.
********************************************************************************/
forlet_clause* wrap_in_letclause(
    expr* e,
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
forlet_clause* wrap_in_letclause(expr* e)
{
  return wrap_in_letclause(e, create_temp_var(e->get_loc(), var_expr::let_var));
}


/*******************************************************************************
  Create a FOR clause for the given FOR variable "fv" and its associated POS var
  "pv" (pv may be NULL). Use the given expr "e" as the defining expr for "fv".
********************************************************************************/
forlet_clause* wrap_in_forclause(expr* e, var_expr* fv, var_expr* pv)
{
  assert(fv->get_kind () == var_expr::for_var);
  if (pv != NULL)
  {
    assert(pv->get_kind() == var_expr::pos_var);
  }

  return theExprManager->create_for_clause(theRootSctx, e->get_loc(), fv, e, pv);
}


/*******************************************************************************
  Create var_exprs for a FOR var with the given qname and its associated POS
  var, whose qname is also given. Then add those vars to the local sctx obj.
  Then, create a FOR clause for these new var_exprs, with the given expr as the
  defining expression of the FOR var.
********************************************************************************/
forlet_clause* wrap_in_forclause(
    expr* expr,
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
forlet_clause* wrap_in_forclause(expr* expr, bool add_posvar)
{
  var_expr* fv = create_temp_var(expr->get_loc(), var_expr::for_var);

  var_expr* pv = (add_posvar ?
                   create_temp_var(expr->get_loc(), var_expr::pos_var) :
                   NULL);

  return wrap_in_forclause(expr, fv, pv);
}


/*******************************************************************************
  Create a flwor expr with a single let clause and a return expr. In particular,
  the following flwor expr is built:

  let $lv := domExpr
  return retExpr

********************************************************************************/
flwor_expr* wrap_in_let_flwor(
    expr* domExpr,
    var_expr* lv,
    expr* retExpr)
{
  flwor_expr* fe = theExprManager->
  create_flwor_expr(theRootSctx, theUDF, lv->get_loc(), false);

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
flwor_expr* wrap_expr_in_flwor(
    expr* inputExpr,
    bool withContextSize)
{
  const QueryLoc& loc = inputExpr->get_loc();

  push_scope();

  flwor_expr* flworExpr = theExprManager->
  create_flwor_expr(theRootSctx, theUDF, loc, false);

  if (withContextSize)
  {
    // create a LET var whose domain expr is the input epxr
    let_clause* lcInputSeq = wrap_in_letclause(inputExpr);
    var_expr* lcInputVar = lcInputSeq->get_var();

    // compute the size of the input seq
    expr* varWrapper = CREATE(wrapper)(theRootSctx, theUDF, loc, lcInputVar);

    fo_expr* countExpr = CREATE(fo)(theRootSctx,
                                    theUDF,
                                    loc,
                                    BUILTIN_FUNC(FN_COUNT_1),
                                    varWrapper);

    normalize_fo(countExpr);

    forlet_clause* lcLast = wrap_in_letclause(countExpr, loc, LAST_IDX_VARNAME);

    // Iterate over the input seq
    varWrapper = CREATE(wrapper)(theRootSctx, theUDF, loc, lcInputVar);

    for_clause* fcDot = wrap_in_forclause(varWrapper,
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
    for_clause* fcDot = wrap_in_forclause(inputExpr,
                                          loc,
                                          DOT_VARNAME,
                                          DOT_POS_VARNAME);
    flworExpr->add_clause(fcDot);
  }

  return flworExpr;
}


QueryLoc expandQueryLoc(const QueryLoc& aLocationFrom, const QueryLoc& aLocationTo)
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
  expr* aExpr,
  const QueryLoc& aLoc,
  bool aIsMainModuleBreakable = false,
  bool aIsVarDeclaration = false)
{
#ifdef ZORBA_WITH_DEBUGGER
  if (theCCB->theDebuggerCommons != NULL)
  {
    std::auto_ptr<debugger_expr> lExpr(theExprManager->
    create_debugger_expr(theSctx,
                         theUDF,
                         aLoc,
                         aExpr,
                         theNSCtx,
                         aIsVarDeclaration));

    // add the breakable expression in the debugger commons as a possible
    // breakpoint location
    Breakable lBreakable(aLoc);
    theCCB->theDebuggerCommons->addBreakable(lBreakable, aIsMainModuleBreakable);

    // retrieve all variables that are in the current scope
    typedef std::vector<VarInfo*> VarExprVector;
    VarExprVector lAllInScopeVars;
    theSctx->getVariables(lAllInScopeVars);

    // for each var, create a eval_var and add it to
    // the debugger expression
    for (VarExprVector::iterator lIter = lAllInScopeVars.begin();
         lIter != lAllInScopeVars.end();
         ++lIter)
    {
      var_expr* argVar = (*lIter)->getVar();

      store::Item* lVarname = argVar->get_name();

      if (lVarname->getStringValue() == "$$dot")
      {
        continue;
      }

      var_expr* evalVar = create_var(lBreakable.getLocation(),
                                      lVarname,
                                      var_expr::eval_var,
                                      NULL);

      expr* argExpr = theExprManager->
      create_wrapper_expr(theRootSctx,
                          theUDF,
                          lBreakable.getLocation(),
                          argVar);

      lExpr->add_var(evalVar, argExpr);
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
  for (i = (int)clauses.size() - 1; i >= 0; --i)
  {
    if (&*clauses[i] == end)
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

    if (typeid(c) == typeid(ForClause))
    {
      const VarInDeclList& varDecls =
      *(static_cast<const ForClause*>(&c)->get_vardecl_list());

      for (int j =  (int)varDecls.size() - 1; j >= 0; --j)
      {
        VarInDecl* varDecl = varDecls[j];

        vars.insert(lookup_var(varDecl->get_var_name(), loc, true));

        if (varDecl->get_posvar() != NULL)
          vars.insert(lookup_var(varDecl->get_posvar()->get_name(), loc, true));
      }
    }
    else if (typeid(c) == typeid(LetClause))
    {
      const VarGetsDeclList& lV =
      *(static_cast<const LetClause*>(&c)->get_vardecl_list());

      for (int j =  (int)lV.size() - 1; j >= 0; --j)
      {
        vars.insert(lookup_var(lV[j]->get_var_name(), loc, true));
      }
    }
    else if (typeid(c) == typeid(WindowClause))
    {
      const WindowClause& wc = *static_cast<const WindowClause *>(&c);
      vars.insert(lookup_var(wc.get_var()->get_var_name(), loc, true));
      for (int j = 1; j >= 0; j--)
      {
        const FLWORWinCond* cond = &*wc[j];
        if (cond != NULL)
        {
          const WindowVars* wv = &*cond->get_winvars();
          if (wv != NULL)
          {
            if (wv->get_next())
              vars.insert(lookup_var(wv->get_next(), loc, true));
            if (wv->get_prev())
              vars.insert(lookup_var(wv->get_prev(), loc, true));
            if (wv->get_curr())
              vars.insert(lookup_var(wv->get_curr(), loc, true));
            if (wv->get_posvar() != NULL)
              vars.insert(lookup_var(wv->get_posvar()->get_name(), loc, true));
          }
        }
      }
    }
    else if (typeid(c) == typeid(CountClause))
    {
      vars.insert(lookup_var(static_cast<const CountClause*>(&c)->get_varname(),
                             loc,
                             true));
    }
    else if (typeid(c) == typeid(OrderByClause))
    {
      // Nothing to do; orderby does not define any vars.
    }
    else if (typeid (c) == typeid (GroupByClause))
    {
      const GroupByClause groupClause = *static_cast<const GroupByClause*>(&c);

      //Group-by clauses may define new variables, otherwise it shadows existing vars.
      for(size_t gSpecPos = 0; gSpecPos < groupClause.get_spec_list()->size(); gSpecPos++)
      {
        GroupSpec* groupSpec = (*(groupClause.get_spec_list()))[gSpecPos];
        if (groupSpec->get_binding_expr() != NULL)
          vars.insert(lookup_var(groupSpec->get_var_name(), loc, true));
      }

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
void declare_var(const GlobalBinding& b, std::vector<expr*>& stmts)
{
  function* varGet = BUILTIN_FUNC(OP_VAR_GET_1);

  expr* initExpr = b.theExpr;
  var_expr* varExpr = b.theVar;

  const QueryLoc& loc = varExpr->get_loc();

  xqtref_t varType = varExpr->get_type();

  if (varType == NULL &&
      varExpr->get_name()->getLocalName() == static_context::DOT_VAR_NAME)
  {
    varType = GENV_TYPESYSTEM.ITEM_TYPE_ONE;
  }

  if (initExpr != NULL && varType != NULL && !b.is_extern())
  {
    initExpr = theExprManager->
    create_treat_expr(theRootSctx,
                      theUDF,
                      loc,
                      initExpr,
                      varType,
                      TREAT_TYPE_MATCH);
  }

  expr* declExpr = theExprManager->
  create_var_decl_expr(theRootSctx, theUDF, loc, varExpr, initExpr);

  stmts.push_back(declExpr);

  // check type for vars that are external
  if (varType != NULL && b.is_extern())
  {
    expr* getExpr = theExprManager->
    create_fo_expr(theRootSctx, theUDF, loc, varGet, varExpr);

    expr* treatExpr = theExprManager->
    create_treat_expr(theRootSctx,
                      theUDF,
                      loc,
                      getExpr,
                      varType,
                      TREAT_TYPE_MATCH);

    stmts.push_back(treatExpr);
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
expr* wrap_in_globalvar_assign(expr* program)
{
  assert(theAssignedVars.size() == 1);

  for (std::list<GlobalBinding>::iterator i = thePrologVars.begin();
       i != thePrologVars.end();
       ++i)
  {
    declare_var(*i, theModulesInfo->theInitExprs);
  }

  expr* preloadedInitExpr = static_cast<static_context*>(theSctx->get_parent())->
                             get_query_expr();

  if (!theModulesInfo->theInitExprs.empty() || preloadedInitExpr != NULL)
  {
    std::vector<expr*> args;
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

    block_expr* res = theExprManager->
    create_block_expr(theRootSctx,
                      theUDF,
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
      theSctx->set_default_elem_type_ns(targetNS, true, loc);

    if (! pfx.empty())
      theSctx->bind_ns(pfx, targetNS, loc);
  }

  zstring xsdTNS = zstring(XML_SCHEMA_NS);
  if ( xsdTNS.compare(targetNS)==0 )
  {
    // Xerces doesn't like importing XMLSchema.xsd schema4schema, so we skip it
    // see Xerces-C++ bug: https://issues.apache.org/jira/browse/XERCESC-1980
    return no_state;
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

    if (lStream == NULL)
    {
      RAISE_ERROR(err::XQST0059, loc,
      ERROR_PARAMS(ZED(XQST0059_SpecificationMessage), lNsURI, "", lErrorMessage));
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
expr* wrap_in_validate_expr_strict(
    expr* aExpr,
    const zstring& aSchemaURI)
{
  QueryLoc lLoc = aExpr->get_loc();
  import_schema_auto_prefix(lLoc, aSchemaURI.c_str(), NULL);

  store::Item_t qname;
  return theExprManager->create_validate_expr(theRootSctx,
                                              theUDF,
                                              lLoc,
                                              ParseConstants::val_strict,
                                              qname,
                                              aExpr,
                                              theSctx->get_typemanager());
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

  if (v.get_language_kind() == VersionDecl::jsoniq)
  {
    theSctx->set_language_kind(StaticContextConsts::language_kind_jsoniq);
    std::string versionStr = v.get_version().str();
    if (versionStr == "1.0")
      theSctx->set_jsoniq_version(StaticContextConsts::jsoniq_version_1_0);
    else
      theSctx->set_jsoniq_version(StaticContextConsts::jsoniq_version_unknown);
    return no_state;
  }

  if (v.get_encoding() != "utf-8" &&
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
  var_expr* var1 = bind_var(loc,
                            DOT_VARNAME,
                            var_expr::prolog_var,
                            theSctx->get_context_item_type());
  var_expr* var2 = bind_var(loc,
                            DOT_POS_VARNAME,
                            var_expr::prolog_var,
                            theRTM.INTEGER_TYPE_ONE);
  var_expr* var3 = bind_var(loc,
                            LAST_IDX_VARNAME,
                            var_expr::prolog_var,
                            theRTM.INTEGER_TYPE_ONE);

  var1->set_external(true);
  var2->set_external(true);
  var3->set_external(true);

  var1->set_unique_id(dynamic_context::IDVAR_CONTEXT_ITEM);
  var2->set_unique_id(dynamic_context::IDVAR_CONTEXT_ITEM_POSITION);
  var3->set_unique_id(dynamic_context::IDVAR_CONTEXT_ITEM_SIZE);

  //GlobalBinding b(var, NULL, true);
  //declare_var(b, theModulesInfo->theInitExprs);

  return no_state;
}

void end_visit(const MainModule& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr* program = pop_nodestack();

  assert(theCCB->theIsEval || !program->is_updating());

  // If an appliaction set a type for the context item via the c++ api, then
  // create a full declaration for it in order to enforce that type.
  if (!theHaveContextItemDecl &&
      theRTM.ITEM_TYPE_ONE != theSctx->get_context_item_type())
  {
    var_expr* var = lookup_ctx_var(DOT_VARNAME, loc);
    var->set_external(true);
    GlobalBinding b(var, NULL, true);
    declare_var(b, theModulesInfo->theInitExprs);
  }

  // the main module debug iterator has no location otherwise
  // this would take precedence over a child debug iterator
  // starting in the same line
  wrap_in_debugger_expr(program, program->get_loc(), true);

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

  expr* program = wrap_in_globalvar_assign(create_empty_seq(loc));

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

  export_sctx = lTmpCtx;
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
  theSctx->set_inherit_ns(v.inherit_ns());
  theSctx->set_preserve_ns(v.preserve_ns());
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
    theSctx->set_default_elem_type_ns(v.get_default_namespace(), true, loc);
    break;
  case ParseConstants::ns_function_default:
    theSctx->set_default_function_ns(v.get_default_namespace(), true, loc);
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
  {
    RAISE_ERROR(err::XQST0070, loc, ERROR_PARAMS(pfx, ZED(NoRebindPrefix)));
  }

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
    theSctx->bind_ns(pfx, targetNS, loc);
  }

  const URILiteralList* atlist = v.get_at_list();

  // If the imported module X is a "pure builtin" one (i.e., contains
  // decalrations of zorba builtin functions only), then we don't need
  // to process it. We just need to record in the root sctx of the
  // importing module that X has been imported.
  if (atlist == NULL && static_context::is_builtin_module(targetNS))
  {
    // just a test, this will throw, if the access is denied
    std::vector<zstring> candidateURIs;
    theRootSctx->get_candidate_uris(targetNS,
                                    internal::EntityData::MODULE,
                                    candidateURIs);
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
        RAISE_ERROR(err::XQST0059, loc,
        ERROR_PARAMS(ZED(XQST0059_SpecificationMessage), targetNS, compURI));

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
      std::auto_ptr<internal::Resource> lResource;
      internal::StreamResource* lStreamResource = NULL;

      try
      {
        lResource =
        theSctx->resolve_uri(compModVer.versioned_uri(),
                             internal::EntityData::MODULE,
                             lErrorMessage);

        lStreamResource =
        dynamic_cast<internal::StreamResource*> (lResource.get());
      }
      catch (ZorbaException& e)
      {
        set_source(e, loc);
        throw;
      }

      if (lStreamResource != NULL)
      {
        modfile = lStreamResource->getStream();
        compURL = lStreamResource->getStreamUrl();
      }
      else
      {
        throw XQUERY_EXCEPTION(
          err::XQST0059,
          ERROR_PARAMS(
            ZED( XQST0059_SpecificationMessage ),
            targetNS, compURI, lErrorMessage
          ),
          ERROR_LOC( loc )
        );
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
      csize moduleRootSctxId = theCCB->theSctxMap.size() + 1;
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
        throw XQUERY_EXCEPTION(
          err::XQST0059,
          ERROR_PARAMS(
            ZED( XQST0059_SpecificationMessage ),
            targetNS, compURI
          ),
          ERROR_LOC( loc )
        );

      importedNS = mod_ast->get_decl()->get_target_namespace().str();

      if (importedNS.empty())
        throw XQUERY_EXCEPTION(err::XQST0088, ERROR_LOC(loc));

      if (importedNS != targetNS)
        throw XQUERY_EXCEPTION(
          err::XQST0059,
          ERROR_PARAMS(
            ZED( XQST0059_SpecificationMessage ),
            targetNS, compURI
          ),
          ERROR_LOC( loc )
        );

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
                              static_context::ZORBA_VERSIONING_NS,
                              zstring(""),
                              zstring(ZORBA_OPTION_MODULE_VERSION),
                              loc);
        zstring lImportedVersion;
        if (!moduleRootSctx->lookup_option(lMajorOpt, lImportedVersion))
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
    theSctx->import_module(importedSctx, loc);

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
  // The 2nd pass happens when accept() is called on each individual FunctionDecl
  // node in the list.

  for (std::vector<rchandle<parsenode> >::const_iterator it = v.begin();
       it != v.end();
       ++it)
  {
    const OptionDecl* opt_decl = it->dyn_cast<OptionDecl>();

    if (opt_decl != NULL)
    {
      store::Item_t qnameItem;
      zstring value = opt_decl->get_val().str();

      rchandle<QName> lQName = opt_decl->get_qname();
      if (theSctx->xquery_version() >= StaticContextConsts::xquery_version_3_0 &&
          lQName->get_namespace().empty() && lQName->get_prefix().empty())
      {
        theSctx->expand_qname(
           qnameItem,
           static_context::XQUERY_OPTION_NS,
           "",
           lQName->get_localname(),
           lQName->get_location());
      }
      else
      {
        expand_no_default_qname(qnameItem, lQName, loc);
        if (qnameItem->getPrefix().empty() && qnameItem->getNamespace().empty())
        {
          RAISE_ERROR(err::XPST0081, loc, ERROR_PARAMS(qnameItem->getStringValue()));
        }
      }


      if (qnameItem->getNamespace() == static_context::ZORBA_OPTION_FEATURE_NS &&
          value == "http-uri-resolution")
      {
        RAISE_ERROR(zerr::ZXQP0061_DISABLE_HTTP_OPTION_IN_QUERY, loc,
                    ERROR_PARAMS(value));
      }
      theSctx->bind_option(qnameItem, value, opt_decl->get_location());

      if (qnameItem->getNamespace() == static_context::ZORBA_OPTION_OPTIM_NS &&
          value == "for-serialization-only")
      {
        if (qnameItem->getLocalName() == "enable")
          theCCB->theConfig.for_serialization_only = true;
        else
          theCCB->theConfig.for_serialization_only = false;
      }

      continue;
    }

#if 1
    const GlobalVarDecl* var_decl = it->dyn_cast<GlobalVarDecl>().getp();

    if (var_decl != NULL &&
        theSctx->xquery_version() >= StaticContextConsts::xquery_version_3_0)
    {
      const QueryLoc& loc = var_decl->get_location();

      store::Item_t qnameItem;
      expand_no_default_qname(qnameItem, var_decl->get_var_name(), loc);

      // All vars declared in a module must be in the same namespace as the module
      if (! theModuleNamespace.empty() &&
          qnameItem->getNamespace() != theModuleNamespace)
      {
        RAISE_ERROR(err::XQST0048, loc, ERROR_PARAMS(qnameItem->getStringValue()));
      }

      var_expr* ve = create_var(loc, qnameItem, var_expr::prolog_var);

      if (var_decl->is_extern())
        ve->set_external(true);

      xqtref_t type;
      if (var_decl->get_var_type() != NULL)
      {
        var_decl->get_var_type()->accept(*this);

        type = pop_tstack();

        ve->set_type(type);
      }

      AnnotationListParsenode* annotations = var_decl->get_annotations();
      if (annotations)
      {
        if (theSctx->xquery_version() < StaticContextConsts::xquery_version_3_0)
        {
          RAISE_ERROR(err::XPST0003, loc, ERROR_PARAMS(ZED(XPST0003_Annotations)));
        }

        annotations->accept(*this);

        if (theAnnotations)
        {
          if (ZANN_CONTAINS(fn_private))
            ve->set_private(true);

          if (ZANN_CONTAINS(zann_assignable))
          {
            ve->set_mutable(true);
          }
          else if (ZANN_CONTAINS(zann_nonassignable))
          {
            ve->set_mutable(false);
          }
          else
          {
            ve->set_mutable(theSctx->is_feature_set(feature::scripting));
          }
        }
        else
        {
          ve->set_mutable(theSctx->is_feature_set(feature::scripting));
        }
      }
      else
      {
        ve->set_mutable(theSctx->is_feature_set(feature::scripting));
      }

      theAnnotations = NULL;

      // Put a mapping between the var name and the var_expr in the local sctx.
      // Raise error if var name exists already in local sctx obj.
      bind_var(ve, theSctx);

      // Make sure that there is no other prolog var with the same name in any of
      // modules translated so far.
      bind_var(ve, theModulesInfo->globalSctx.get());

      // If this is a library module, register the var in the exported sctx as well.
      if (export_sctx != NULL)
        bind_var(ve, export_sctx);

      continue;
    }
#endif

    const FunctionDecl* func_decl = it->dyn_cast<FunctionDecl>().getp();

    if (func_decl == NULL)
      continue;

    AnnotationListParsenode* annotations = func_decl->get_annotations();
    if (annotations)
    {
      if (theSctx->xquery_version() < StaticContextConsts::xquery_version_3_0)
      {
        RAISE_ERROR(err::XPST0003, loc, ERROR_PARAMS(ZED(XPST0003_Annotations)));
      }

      annotations->accept(*this);
    }

    const QueryLoc& loc = func_decl->get_location();

    // Expand the function qname (error is raised if qname resolution fails)
    // and check it for errors. The following conditions are checked:
    // - Function must be declared in a non-NULL namespace.
    // - Function must not be in any of the reserved namespaces.
    // - In a module, all exports must be inside the target ns.
    const QName* fname = func_decl->get_name();
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
      ERROR_PARAMS(qnameItem->getLocalName(), ZED(FUNCTION), ns));
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
      const Param* param = (*it);
      const SequenceType* paramType = param->get_typedecl();
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
    bool isVariadic = (theAnnotations ? ZANN_CONTAINS(zann_variadic): false);

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
      f = theSctx->lookup_fn(qnameItem, numParams, false);

      if (f != 0)
      {
        if (f->isUdf())
        {
          RAISE_ERROR(err::XQST0034, loc, ERROR_PARAMS(qnameItem->getStringValue()));
        }

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
                                theRootSctx,
                                qnameItem->getNamespace(),
                                sig,
                                scriptKind,
                                ef);
    }
    else // Process UDF (non-external) function declaration
    {
      f = new user_function(loc, sig, NULL, scriptKind, theCCB); // no body for now
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
  store::Item_t qnameItem;
  expand_function_qname(qnameItem, v.get_name(), v.get_name()->get_location());

  function* f = theSctx->lookup_fn(qnameItem, v.get_param_count(), false);

  assert(f);

  if (f->isUdf())
    theUDF = static_cast<user_function*>(f);

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

  expr* body = NULL;
  user_function* udf = NULL;

  if (!v.is_external())
  {
    udf = dynamic_cast<user_function *>(lFunc);

    assert(udf == theUDF);

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

    // Get the return type
    xqtref_t returnType = udf->getSignature().returnType();

    // Wrap in coercion if the return type is a function item
    if (returnType->type_kind() == XQType::FUNCTION_TYPE_KIND)
    {
      body = wrap_in_coercion(returnType, body, loc, theCCB, true);
    }

    // If function has any params, they have been wraped in a flwor expr. Set the
    // return clause of the flwor to the body expr of the function, and then make
    // this flwor be the actual body of the function.
    std::vector<var_expr*> args;
    if (numParams > 0)
    {
      flwor_expr* flwor = dynamic_cast<flwor_expr*>(pop_nodestack());
      ZORBA_ASSERT(flwor != NULL);

      for (csize i = 0; i < numParams; ++i)
      {
        const let_clause* lc = dynamic_cast<const let_clause*>(flwor->get_clause(i));
        var_expr* argVar = dynamic_cast<var_expr*>(lc->get_expr());
        ZORBA_ASSERT(argVar != NULL);
        args.push_back(argVar);
      }

      flwor->set_return_expr(body);
      body = flwor;

      udf->setArgVars(args);
    }

    if (udf->isExiting())
    {
      body = theExprManager->
      create_exit_catcher_expr(theRootSctx, theUDF, loc, body, theExitExprs);
    }

    // Wrap the UDF body to the type-related expr that enforce the declared
    // return type.
    returnType = udf->getSignature().returnType();

    if (returnType->isBuiltinAtomicAny())
    {
      body = wrap_in_type_promotion(body,
                                    returnType,
                                    PROMOTE_FUNC_RETURN,
                                    udf->getName());
      body->set_loc(v.get_return_type()->get_location());
    }
    else
    {
      body = wrap_in_type_match(body,
                                returnType,
                                loc,
                                TREAT_FUNC_RETURN,
                                udf->getName());
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
      flwor_expr* flwor = dynamic_cast<flwor_expr*>(pop_nodestack());
      ZORBA_ASSERT(flwor != NULL);
    }
  }

  pop_scope();

  theUDF = NULL;
}


/*******************************************************************************
  ParamList ::= Param ("," Param)*
********************************************************************************/
void* begin_visit(const ParamList& v)
{
  TRACE_VISIT();

  if (v.size() > 0)
  {
    flwor_expr* flwor = theExprManager->
    create_flwor_expr(theRootSctx, theUDF, loc, false);

    push_nodestack(flwor);
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

  flwor_expr* flwor = static_cast<flwor_expr*> (theNodeStack.top());
  ZORBA_ASSERT(flwor != NULL);

  store::Item_t qnameItem;
  expand_no_default_qname(qnameItem, v.get_name(), loc);

  var_expr* arg_var = create_var(loc, qnameItem, var_expr::arg_var);
  var_expr* subst_var = bind_var(loc, qnameItem, var_expr::let_var);

  let_clause* lc = wrap_in_letclause(&*arg_var, subst_var);

  // theCurrentPrologVFDecl might be null in case of inline functions
  // inline functions currently can't be sequential anyway
  // hence, we can always lazy evaluation
  if (inUDFBody())
  {
    //lc->setLazyEval(!f->isSequential());
    arg_var->set_param_pos(flwor->num_clauses());
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
********************************************************************************/
void* begin_visit(const GlobalVarDecl& v)
{
  TRACE_VISIT();

  store::Item_t qnameItem;
  expand_no_default_qname(qnameItem, v.get_var_name(), loc);

  var_expr* ve = NULL;

  if (theSctx->xquery_version() >= StaticContextConsts::xquery_version_3_0)
  {
    ve = lookup_var(qnameItem, loc, true);

    assert(ve);
  }
  else
  {
    ve = create_var(loc, qnameItem, var_expr::prolog_var);

    if (v.is_extern())
      ve->set_external(true);
  }

  thePrologGraph.addVarVertex(ve);
  theCurrentPrologVFDecl = PrologGraphVertex(ve);

  push_nodestack(ve);

  return no_state;
}


void end_visit(const GlobalVarDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  theCurrentPrologVFDecl.setNull();

  expr* initExpr = (v.get_binding_expr() == NULL ? NULL : pop_nodestack());

  var_expr* ve = dynamic_cast<var_expr*>(pop_nodestack());

  if (theSctx->xquery_version() < StaticContextConsts::xquery_version_3_0)
  {
    // All vars declared in a module must be in the same namespace as the module
    if (! theModuleNamespace.empty() &&
        ve->get_name()->getNamespace() != theModuleNamespace)
    {
      RAISE_ERROR(err::XQST0048, loc, ERROR_PARAMS(ve->get_name()->getStringValue()));
    }

    ve->set_mutable(false);

    theAnnotations = NULL;

    // Put a mapping between the var name and the var_expr in the local sctx.
    // Raise error if var name exists already in local sctx obj.
    bind_var(ve, theSctx);

    // Make sure that there is no other prolog var with the same name in any of
    // modules translated so far.
    bind_var(ve, theModulesInfo->globalSctx.get());

    // If this is a library module, register the var in the exported sctx as well.
    if (export_sctx != NULL)
      bind_var(ve, export_sctx);
  }

  xqtref_t declaredType;
  if (v.get_var_type() != NULL)
  {
    declaredType = pop_tstack();
    ve->set_type(declaredType);
  }

  // Make sure the initExpr is a simple expr.
  if (initExpr != NULL)
  {
    expr::checkSimpleExpr(initExpr);
    ve->set_has_initializer(true);

    if (!ve->is_mutable() && !ve->is_external())
    {
      xqtref_t derivedType = initExpr->get_return_type();

      if (declaredType == NULL)
      {
        ve->set_type(initExpr->get_return_type());
      }
    }
  }

#ifdef ZORBA_WITH_DEBUGGER
  if (initExpr != NULL && theCCB->theDebuggerCommons != NULL)
  {
    QueryLoc lExpandedLocation =
    expandQueryLoc(v.get_var_name()->get_location(), initExpr->get_loc());

    wrap_in_debugger_expr(initExpr, lExpandedLocation, false, true);
  }
#endif

  // The ve and its associated intExpr will be put into var_decl_expr that
  // will creaated by the wrap_in_globalvar_assign() method when it is called
  // at the end of the translation of each module.
  thePrologVars.push_back(GlobalBinding(ve, initExpr, v.is_extern()));
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

  //bool recognised = false;

  store::Item_t expandedQName;
  expand_function_qname(expandedQName, v.get_qname(), loc);

  zstring annotNS = expandedQName->getNamespace();

  if (annotNS == static_context::W3C_XML_NS ||
      annotNS == XML_SCHEMA_NS ||
      annotNS == XSI_NS ||
      annotNS == static_context::W3C_FN_NS ||
      annotNS == XQUERY_MATH_FN_NS ||
      annotNS == ZORBA_ANNOTATIONS_NS)
  {
    if (AnnotationInternal::lookup(expandedQName) == AnnotationInternal::zann_end)
    {
      RAISE_ERROR(err::XQST0045, loc,
      ERROR_PARAMS(expandedQName->getLocalName(), ZED(ANNOTATION), annotNS));
    }

    //recognised = true;
  }

  std::vector<const_expr*> lLiterals;

  if (v.get_literals())
  {
    std::vector<rchandle<exprnode> >::const_iterator lIter;

    for (lIter = v.get_literals()->begin();
         lIter != v.get_literals()->end();
         ++lIter)
    {
      const_expr* lLiteral = dynamic_cast<const_expr*>(pop_nodestack());
      lLiterals.insert(lLiterals.begin(), lLiteral);
    }
  }

  //if (recognised)
  theAnnotations->push_back(expandedQName, lLiterals);
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
    RAISE_ERROR(err::XPST0003, loc,
    ERROR_PARAMS(ZED(XPST0003_XQueryVersionAtLeast30_2), theSctx->xquery_version()));

  theHaveContextItemDecl = true;

  return no_state;
}

void end_visit(const CtxItemDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr* initExpr = NULL;
  if (v.get_expr() != NULL)
    initExpr = pop_nodestack();

  xqtref_t type;

  if (v.get_type() != NULL)
  {
    type = pop_tstack();
    theSctx->set_context_item_type(type, loc);
  }
  else
  {
    type = theSctx->get_context_item_type();
    assert(type != NULL);
  }

  var_expr* var = NULL;

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
    lNodeType = theRTM.ANY_NODE_UNTYPED_TYPE_ONE;
    lCollectionType = theRTM.ANY_NODE_UNTYPED_TYPE_STAR;
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

  std::vector<const_expr* > lLiterals;
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

  IndexDecl_t index = new IndexDecl(theSctx, theCCB,  loc, qnameItem);
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

  expr* domainExpr = pop_nodestack();

  if (!domainExpr->is_simple())
  {
    RAISE_ERROR(zerr::ZDST0033_INDEX_NON_SIMPLE_EXPR, domainExpr->get_loc(),
    ERROR_PARAMS(index->getName()->getStringValue()));
  }

#ifdef ZORBA_WITH_JSON
  domainExpr = wrap_in_type_match(domainExpr,
                                  theRTM.STRUCTURED_ITEM_TYPE_STAR,
                                  loc,
                                  TREAT_INDEX_DOMAIN,
                                  index->getName());
#else
  domainExpr = wrap_in_type_match(domainExpr,
                                  theRTM.ANY_NODE_TYPE_STAR,
                                  loc,
                                  TREAT_INDEX_DOMAIN,
                                  index->getName());
#endif

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
    domainExpr = theExprManager->
    create_fo_expr(theRootSctx,
                   theUDF,
                   domainExpr->get_loc(),
                   BUILTIN_FUNC(OP_CHECK_DISTINCT_NODES_1),
                   domainExpr);
  }

  std::string msg = "Domain expr for index " + index->getName()->getStringValue().str();

  if (theCCB->theConfig.translate_cb != NULL)
    theCCB->theConfig.translate_cb(domainExpr, msg);

  // Optimize the domain expr. We do this even if the optimizer is off.
  // if (theCCB->theConfig.opt_level == CompilerCB::config::O1)
  {
    RewriterContext rCtx(theCCB, domainExpr, NULL, msg, false);
    rCtx.setForSerializationOnly(false);

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

  std::vector<expr*> keyExprs(numColumns);
  std::vector<xqtref_t> keyTypes(numColumns);
  std::vector<OrderModifier> keyModifiers(numColumns);

  IndexDecl* index = theIndexDecl;

  for (long i = numColumns - 1; i >= 0; --i)
  {
    const IndexKeySpec* keySpec = v.getKeySpec(i);
    const OrderCollationSpec* collationSpec = keySpec->getCollationSpec();

    const QueryLoc& kloc = keySpec->get_location();

    expr* keyExpr = pop_nodestack();

    if (!keyExpr->is_simple())
    {
      RAISE_ERROR(zerr::ZDST0033_INDEX_NON_SIMPLE_EXPR, keyExpr->get_loc(),
      ERROR_PARAMS(index->getName()->getStringValue()));
    }

    xqtref_t type;
    xqtref_t ptype;

    if (keySpec->getType() == NULL)
    {
      if (!index->isGeneral())
      {
        RAISE_ERROR(zerr::ZDST0027_INDEX_BAD_KEY_TYPE, kloc,
        ERROR_PARAMS(index->getName()->getStringValue(),
                     ZED(ZDST0027_NO_KEY_TYPE_DECL)));
      }

      keyExpr = wrap_in_atomization(keyExpr);
    }
    else
    {
      type = pop_tstack();
      ptype = TypeOps::prime_type(tm, *type);
      TypeConstants::quantifier_t quant = type->get_quantifier();

      if (!TypeOps::is_subtype(tm, *ptype, *theRTM.ANY_ATOMIC_TYPE_STAR, kloc))
      {
        RAISE_ERROR(zerr::ZDST0027_INDEX_BAD_KEY_TYPE, kloc,
        ERROR_PARAMS(index->getName()->getStringValue(),
                     ZED(ZDST0027_NON_ATOMIC_KEY_TYPE)));
      }

      if (!index->isGeneral() &&
          quant != TypeConstants::QUANT_ONE &&
          quant != TypeConstants::QUANT_QUESTION)
      {
        RAISE_ERROR(zerr::ZDST0027_INDEX_BAD_KEY_TYPE, kloc,
        ERROR_PARAMS(index->getName()->getStringValue(),
                     ZED(ZDST0027_MULTI_VALUED_KEY_TYPE_DECL)));
      }

      if (!index->isGeneral() &&
          (TypeOps::is_equal(tm, *ptype, *theRTM.ANY_ATOMIC_TYPE_ONE, kloc) ||
           TypeOps::is_equal(tm, *ptype, *theRTM.UNTYPED_ATOMIC_TYPE_ONE, kloc)))
      {
        RAISE_ERROR(zerr::ZDST0027_INDEX_BAD_KEY_TYPE, kloc,
        ERROR_PARAMS(index->getName()->getStringValue(),
                     ZED(ZDST0027_NON_SPECIFIC_KEY_TYPE_DECL)));
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
        ERROR_PARAMS(index->getName()->getStringValue(),
                     ZED(ZDST0027_NON_ORDERED_KEY_TYPE),
                     ptype->toSchemaString()));
      }

      if (!index->isGeneral() &&
          (TypeOps::is_subtype(tm, *ptype, *theRTM.STRING_TYPE_ONE, kloc) ||
           TypeOps::is_subtype(tm, *ptype, *theRTM.DOUBLE_TYPE_ONE, kloc) ||
           TypeOps::is_subtype(tm, *ptype, *theRTM.FLOAT_TYPE_ONE, kloc)))
      {
        keyExpr = wrap_in_type_promotion(keyExpr,
                                         type,
                                         PROMOTE_INDEX_KEY,
                                         index->getName());
      }
      else
      {
        keyExpr = wrap_in_atomization(keyExpr);

        keyExpr = wrap_in_type_match(keyExpr,
                                     type,
                                     loc,
                                     TREAT_INDEX_KEY,
                                     index->getName());
      }

      keyTypes[i] = ptype->getBaseBuiltinType();
    }

    if (index->isGeneral())
    {
      // Eliminate duplicate key values, as they don't play any role in a
      // general comparison predicate.
      keyExpr = CREATE(fo)(theRootSctx,
                           theUDF,
                           keyExpr->get_loc(),
                           BUILTIN_FUNC(FN_DISTINCT_VALUES_1),
                           keyExpr);
    }

    std::string collationUri;

    if (collationSpec != NULL)
    {
      collationUri = collationSpec->get_uri().str();

      if (! theSctx->is_known_collation(collationUri))
        RAISE_ERROR(err::XQST0076, kloc, ERROR_PARAMS(collationUri));
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
      theCCB->theConfig.translate_cb(keyExpr, msg.str());

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
    expr* qnameStrExpr = theExprManager->
    create_const_expr(theRootSctx, theUDF, loc, ic.getCollName()->get_qname().str());

    zstring prefixStr = ic.getCollName()->get_prefix();
    zstring uriStr;
    theSctx->lookup_ns(uriStr, prefixStr, loc);

    expr* uriStrExpr = theExprManager->
    create_const_expr(theRootSctx, theUDF, loc, uriStr);

    // fn:QName("uri", "example:coll1")
    fo_expr* qnameExpr = theExprManager->
    create_fo_expr(theRootSctx,
                   theUDF,
                   loc,
                   BUILTIN_FUNC(FN_QNAME_2),
                   uriStrExpr,
                   qnameStrExpr);

    // dc:collection(xs:QName("example:coll1"))
    function* fn_collection = BUILTIN_FUNC(STATIC_COLLECTIONS_DML_COLLECTION_1);
    ZORBA_ASSERT(fn_collection != NULL);
    std::vector<expr*> argColl;
    argColl.push_back(qnameExpr);

    fo_expr* collExpr = theExprManager->
    create_fo_expr(theRootSctx, theUDF, loc, fn_collection, argColl);

    // $x
    const QName* varQName = ic.getCollVarName();
    var_expr* varExpr = bind_var(loc, varQName, var_expr::let_var, NULL);

    // let $x := dc:collection(xs:QName("example:coll1"))
    let_clause* lc = theExprManager->
    create_let_clause(theRootSctx, loc, varExpr, collExpr);

    flwor_expr* flworExpr = theExprManager->
    create_flwor_expr(theRootSctx, theUDF, loc, false);

    flworExpr->add_clause(lc);
    // flworExpr-> return clause to be set in end_visitor

    push_nodestack(flworExpr);
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
    expr* qnameStrExpr = theExprManager->
    create_const_expr(theRootSctx,
                      theUDF,
                      loc,
                      ic.getCollName()->get_qname().str());

    zstring prefixStr = ic.getCollName()->get_prefix();
    zstring uriStr;
    theSctx->lookup_ns(uriStr, prefixStr, loc);

    expr* uriStrExpr = theExprManager->
    create_const_expr(theRootSctx, theUDF, loc, uriStr);

    // fn:QName("org-uri", "org:employees")
    fo_expr* qnameExpr = theExprManager->
    create_fo_expr(theRootSctx,
                   theUDF,
                   loc,
                   BUILTIN_FUNC(FN_QNAME_2),
                   uriStrExpr, qnameStrExpr);

    // dc:collection(xs:QName("org:employees"))
    function* fn_collection = BUILTIN_FUNC(STATIC_COLLECTIONS_DML_COLLECTION_1);
    ZORBA_ASSERT(fn_collection != NULL);
    std::vector<expr*> argColl;
    argColl.push_back(qnameExpr);
    fo_expr* collExpr = theExprManager->
    create_fo_expr(theRootSctx, theUDF, loc, fn_collection, argColl);

    // $x
    const QName* varQName = ic.getNodeVarName();
    store::Item_t varItem;
    expand_no_default_qname(varItem, varQName, varQName->get_location());

    // every $x_ in $x satisfies exists ...
    // every is implemented as a flowr expr
    push_scope();

    flwor_expr* evFlworExpr = theExprManager->
    create_flwor_expr(theRootSctx, theUDF, loc, false);

    evFlworExpr->set_return_expr(CREATE(const)(theRootSctx, theUDF, loc, true));

    // $x_ in dc:collection( xs:QName("org:employees") )
    var_expr* evVarExpr = bind_var(loc, varItem, var_expr::for_var, NULL);

    // maybe make one more collExpr?
    evFlworExpr->add_clause(wrap_in_forclause(collExpr, evVarExpr, NULL));

    pop_scope();
    // end every

    // let $x := dc:collection(xs:QName("org:employees"))
    //   return
    var_expr* varExpr = bind_var(loc,
                                  varItem,
                                  var_expr::let_var,
                                  NULL);

    let_clause* letClause = theExprManager->
    create_let_clause(theRootSctx, loc, varExpr, collExpr);

    flwor_expr* flworExpr = theExprManager->
    create_flwor_expr(theRootSctx, theUDF, loc, false);



    flworExpr->add_clause(letClause);
    // flworExpr->set_return_expr( andExpr ); done in end_visit

    // push evFlworExpr because where clause must be set
    push_nodestack(evFlworExpr);
    // push the top expresion
    push_nodestack(flworExpr);
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
    expr* qnameStrExpr = theExprManager->
    create_const_expr(theRootSctx, theUDF, loc, ic.getCollName()->get_qname().str());

    zstring prefixStr = ic.getCollName()->get_prefix();
    zstring uriStr;
    theSctx->lookup_ns(uriStr, prefixStr, loc);

    expr* uriStrExpr = theExprManager->
    create_const_expr(theRootSctx, theUDF, loc, uriStr);

    // fn:QName("org-uri", "org:transactions")
    fo_expr* qnameExpr = theExprManager->
    create_fo_expr(theRootSctx,
                   theUDF,
                   loc,
                   BUILTIN_FUNC(FN_QNAME_2),
                   uriStrExpr,
                   qnameStrExpr);

    // dc:collection(xs:QName("org:transactions"))
    function* fn_collection = BUILTIN_FUNC(STATIC_COLLECTIONS_DML_COLLECTION_1);
    ZORBA_ASSERT(fn_collection != NULL);
    std::vector<expr*> argColl;
    argColl.push_back(qnameExpr);
    fo_expr* collExpr = theExprManager->
    create_fo_expr(theRootSctx, theUDF, loc, fn_collection, argColl);

    // every $x_ in $x satisfies exists ...
    // every is implemented as a flowr expr
    //push_scope();
    flwor_expr* evFlworExpr = theExprManager->
    create_flwor_expr(theRootSctx, theUDF, loc, false);

    evFlworExpr->set_return_expr(theExprManager->create_const_expr(theRootSctx,
                                                                   theUDF,
                                                                   loc,
                                                                   true));
    // $x
    const QName* varQName = ic.getCollVarName();

    // $x_ in dc:collection( xs:QName("org:employees") )
    var_expr* evVarExpr = bind_var(loc, varQName, var_expr::for_var, NULL);

    // maybe make one more collExpr?
    evFlworExpr->add_clause(wrap_in_forclause(collExpr,
                                              evVarExpr,
                                              NULL));

    //pop_scope();
    // end every
    push_nodestack(evFlworExpr);
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
    expr* toQnameStrExpr = theExprManager->
    create_const_expr(theRootSctx, theUDF, loc, ic.getToCollName()->get_qname().str());

    zstring toPrefixStr = ic.getToCollName()->get_prefix();
    zstring toUriStr;
    theSctx->lookup_ns(toUriStr, toPrefixStr, loc);

    expr* toUriStrExpr = theExprManager->
    create_const_expr(theRootSctx, theUDF, loc, toUriStr);

    // xs:QName("org:employees")
    fo_expr* toQnameExpr = theExprManager->
    create_fo_expr(theRootSctx,
                   theUDF,
                   loc,
                   BUILTIN_FUNC(FN_QNAME_2),
                   toUriStrExpr,
                   toQnameStrExpr);

    // dc:collection(xs:QName("org:employees"))
    function* toFnCollection = BUILTIN_FUNC(STATIC_COLLECTIONS_DML_COLLECTION_1);
    ZORBA_ASSERT(toFnCollection != NULL);
    std::vector<expr*> toArgColl;
    toArgColl.push_back(toQnameExpr);
    fo_expr* toCollExpr = theExprManager->
    create_fo_expr(theRootSctx, theUDF, loc, toFnCollection, toArgColl);

    // some $y in dc:collection( xs:QName("org:employees") )
    // satisfies ... eq ...
    // implemented using flowr
    flwor_expr* someFlworExpr = theExprManager->
    create_flwor_expr(theRootSctx, theUDF, loc, false);

    someFlworExpr->set_return_expr(theExprManager->create_const_expr(theRootSctx,
                                                                     theUDF,
                                                                     loc,
                                                                     true));
    // $y
    const QName* toVarQName = ic.getToNodeVarName();
    var_expr* toVarExpr = bind_var(loc, toVarQName, var_expr::for_var, NULL);

    // for $y in dc:collection(xs:QName("org:employees"))
    someFlworExpr->add_clause(wrap_in_forclause(toCollExpr, toVarExpr, NULL));

    // FROM part
    // "org:transactions"
    expr* fromQnameStrExpr = theExprManager->
    create_const_expr(theRootSctx,
                      theUDF,
                      loc,
                      ic.getFromCollName()->get_qname().str());

    zstring fromPrefixStr = ic.getFromCollName()->get_prefix();
    zstring fromUriStr;
    theSctx->lookup_ns(fromUriStr, fromPrefixStr, loc);

    expr* fromUriStrExpr = theExprManager->
    create_const_expr(theRootSctx, theUDF, loc, fromUriStr);

    // fn:QName("org-uri", "org:transactions")
    fo_expr* fromQnameExpr = theExprManager->
    create_fo_expr(theRootSctx,
                   theUDF,
                   loc,
                   BUILTIN_FUNC(FN_QNAME_2),
                   fromUriStrExpr,
                   fromQnameStrExpr);

    // dc:collection(xs:QName("org:transactions"))
    function* fromFnCollection = BUILTIN_FUNC(STATIC_COLLECTIONS_DML_COLLECTION_1);
    ZORBA_ASSERT(fromFnCollection != NULL);
    std::vector<expr*> fromArgColl;
    fromArgColl.push_back(fromQnameExpr);
    fo_expr* fromCollExpr = theExprManager->
    create_fo_expr(theRootSctx,
                   theUDF,
                   loc,
                   fromFnCollection,
                   fromArgColl);

    // every $x in dc:collection( xs:QName("org:transactions") )
    // satisfies ...
    // implemented using flowr
    flwor_expr* evFlworExpr = theExprManager->
      create_flwor_expr(theRootSctx, theUDF, loc, false);

    evFlworExpr->set_return_expr(theExprManager->create_const_expr(theRootSctx,
                                                                   theUDF,
                                                                   loc,
                                                                   true));

    // $x
    const QName* fromVarQName = ic.getFromNodeVarName();
    var_expr* fromVarExpr = bind_var(loc, fromVarQName, var_expr::for_var, NULL);

    // for $x in dc:collection(xs:QName("org:transactions"))
    evFlworExpr->add_clause(wrap_in_forclause(fromCollExpr,
                                              fromVarExpr, NULL));


    push_nodestack(someFlworExpr);
    push_nodestack(evFlworExpr);
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
  expr* body = NULL;
  const QName* qname = v.getName();

  // todo cezar: error if user expresions are sequential

  // for each type of IC a different check Expr is constructed
  switch( v.getICKind() )
  {
  case IntegrityConstraintDecl::coll_check_simple:
    {
      //const ICCollSimpleCheck ic = dynamic_cast<const ICCollSimpleCheck&>(v);

      expr* icExpr = pop_nodestack();

      flwor_expr* flworExpr =
        dynamic_cast<flwor_expr*>(pop_nodestack());

      // let ... return ...
      flworExpr->set_return_expr( wrap_in_atomization(icExpr) );

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
      expr* uniKeyExpr = pop_nodestack();

      // flwor result expr
      flwor_expr* flworExpr =
        dynamic_cast<flwor_expr*>(pop_nodestack());

      // flwor implementing every
      flwor_expr* evFlworExpr =
        dynamic_cast<flwor_expr*>(pop_nodestack());


      ////// Set latest details

      //fn:data( userExpr )
      expr* atomizedUniKeyExpr = wrap_in_atomization(uniKeyExpr);

      // exists( $x/@id )
      expr* existsExpr = theExprManager->
      create_fo_expr(theRootSctx,
                     theUDF,
                     loc,
                     BUILTIN_FUNC(FN_EXISTS_1),
                     uniKeyExpr);

      // every ... satisfies evTestExpr
      fo_expr* fnNotExpr = theExprManager->
      create_fo_expr(theRootSctx,
                     theUDF,
                     loc,
                     BUILTIN_FUNC(FN_NOT_1),
                     existsExpr);

      evFlworExpr->add_where(fnNotExpr);

      fo_expr* everyExpr = theExprManager->
      create_fo_expr(theRootSctx,
                     theUDF,
                     loc,
                     BUILTIN_FUNC(FN_EMPTY_1),
                     evFlworExpr);

      // functx:are-distinct-values( $x/@id )
      // implemented as count(distinct-values($seq)) = count($seq)
      //distinct-values($seq)
      fo_expr* distinctValuesExpr = theExprManager->
      create_fo_expr(theRootSctx,
                     theUDF,
                     loc,
                     BUILTIN_FUNC(FN_DISTINCT_VALUES_1),
                     atomizedUniKeyExpr);

      // count($sec)
      fo_expr* countSecExpr = theExprManager->
      create_fo_expr(theRootSctx,
                     theUDF,
                     loc,
                     BUILTIN_FUNC(FN_COUNT_1),
                     atomizedUniKeyExpr);

      // count(distinct-values($sec))
      fo_expr* countDVExpr = theExprManager->
      create_fo_expr(theRootSctx,
                     theUDF,
                     loc,
                     BUILTIN_FUNC(FN_COUNT_1),
                     distinctValuesExpr);

      // countDV = countSec
      fo_expr* equalExpr = theExprManager->
      create_fo_expr(theRootSctx,
                     theUDF,
                     loc,
                     BUILTIN_FUNC(OP_EQUAL_2),
                     countDVExpr,
                     countSecExpr);

      // (...) and (...)
      fo_expr* andExpr = theExprManager->
      create_fo_expr(theRootSctx,
                     theUDF,
                     loc,
                     BUILTIN_FUNC(OP_AND_N),
                     everyExpr,
                     equalExpr);

      flworExpr->set_return_expr(andExpr);

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
      expr* evTestExpr = wrap_in_atomization(pop_nodestack());

      // flwor expr
      flwor_expr* evFlworExpr =
        dynamic_cast<flwor_expr*>(pop_nodestack());

      // fn:not
      fo_expr* fnNotExpr = theExprManager->
      create_fo_expr(theRootSctx,
                     theUDF,
                     loc,
                     BUILTIN_FUNC(FN_NOT_1),
                     evTestExpr);

      // where not( exists($x/sale gt 0) )
      evFlworExpr->add_where(fnNotExpr);

      // fn:empty
      fo_expr* emptyExpr = theExprManager->
      create_fo_expr(theRootSctx,
                     theUDF,
                     loc,
                     BUILTIN_FUNC(FN_EMPTY_1),
                     evFlworExpr);

      body = emptyExpr;
    }
    break;

  case IntegrityConstraintDecl::foreign_key:
    {
      //////  Get data from stack
      // $y/id
      expr* toKeyExpr = wrap_in_atomization(pop_nodestack());

      // $x//sale/empid
      expr* fromKeyExpr = wrap_in_atomization(pop_nodestack());

      // result expr
      flwor_expr* evFlworExpr = dynamic_cast<flwor_expr*>(pop_nodestack());

      // some flwor expr
      flwor_expr* someFlworExpr = dynamic_cast<flwor_expr*>(pop_nodestack());


      // maybe add fn:data ?
      // $y/id eq $x//sale/empid
      fo_expr* eqExpr = theExprManager->
      create_fo_expr(theRootSctx,
                     theUDF,
                     loc,
                     BUILTIN_FUNC(OP_VALUE_EQUAL_2),
                     toKeyExpr,
                     fromKeyExpr);

      normalize_fo(eqExpr);

      expr* someTestExpr = eqExpr;
      someTestExpr = wrap_in_bev(someTestExpr);
      someFlworExpr->add_where(someTestExpr);

      // fn:exists
      fo_expr* fnExistsExpr = theExprManager->
      create_fo_expr(theRootSctx,
                     theUDF,
                     loc,
                     BUILTIN_FUNC(FN_EXISTS_1),
                     someFlworExpr);
      // fn:not()
      fo_expr* evFnNotExpr = theExprManager->
      create_fo_expr(theRootSctx,
                     theUDF,
                     loc,
                     BUILTIN_FUNC(FN_NOT_1),
                     fnExistsExpr);

      evFlworExpr->add_where(evFnNotExpr);

      // fn:empty
      fo_expr* fnEmptyExpr = theExprManager->
      create_fo_expr(theRootSctx,
                     theUDF,
                     loc,
                     BUILTIN_FUNC(FN_EMPTY_1),
                     evFlworExpr);


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
    theCCB->theConfig.optimize_cb(body, msg.str());

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

  expr* program = pop_nodestack();

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
    program = theExprManager->create_apply_expr(theRootSctx,
                                                theUDF,
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

  if (!theSctx->is_feature_set(feature::scripting))
  {
    RAISE_ERROR(err::XPST0003, loc, ERROR_PARAMS(ZED(XPST0003_Scripting)));
  }

  bool topLevel = v.isTopLevel();
  bool inEval = theCCB->theIsEval;
  bool allowLastUpdating = false;

  std::vector<expr*> stmts;

  // push a dummy block_expr in the node stack so that local var decls can
  // assert that their parent is a block expr.
  expr* dummyBlock = theExprManager->
  create_block_expr(theRootSctx, theUDF, loc, false, stmts, NULL);

  push_nodestack(dummyBlock);

  push_scope();

  csize numScopes = theAssignedVars.size();

  theAssignedVars.resize(numScopes + 1);

  csize numExprs = v.size();
  bool declaresVars = false;

  for (csize i = 0; i < numExprs; ++i)
  {
    v[i]->accept(*this);

    if (dynamic_cast<const LocalVarDecl*>(v[i]) != NULL)
    {
      expr* val = pop_nodestack();
      var_expr* ve = static_cast<var_expr*>(pop_nodestack());

      GlobalBinding b(ve, val, false);

      declare_var(b, stmts);

      declaresVars = true;
    }
    else
    {
      expr* childExpr = pop_nodestack();

      // If the last child is an updating expr
      if (topLevel && i == numExprs - 1 && childExpr->is_updating())
      {
        if (inEval)
        {
          allowLastUpdating = true;
        }
        else
        {
          childExpr = theExprManager->
          create_apply_expr(theRootSctx, theUDF, loc, childExpr, false);
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
  // hack?
  // this has been removed to allow for blocks containing only an expression
  // to be treated as JSON object constructors
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

  expr* blockExpr = theExprManager->create_block_expr(theRootSctx,
                                                      theUDF,
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

  Note: The applicable annotations are assignable vs non-assignable.

  Note: The parser makes sure that if a VarDeclStatement does not appear as a
  direct child of a BlockBody, it is wrapped by a BlockBody. Furthermore, the
  parser will flatten-out the VarDeclStatement parsenode by placing its children
  as direct children of the enclosing BlockBody. As a result, VarDeclStatement
  parsenodes do not appear at all in the final AST, and local var decls may
  appear only as direct operands of block exprs.
********************************************************************************/
void* begin_visit(const LocalVarDecl& v)
{
  TRACE_VISIT();

  store::Item_t qnameItem;
  expand_no_default_qname(qnameItem, v.get_var_name(), loc);

  if (theNodeStack.top()->get_expr_kind() != block_expr_kind)
  {
    ZORBA_ASSERT(false);
  }

  var_expr* ve = create_var(loc, qnameItem, var_expr::local_var);

  push_nodestack(ve);

  return no_state;
}


void end_visit(const LocalVarDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr* initExpr = (v.get_binding_expr() == NULL ? NULL : pop_nodestack());

  var_expr* ve = dynamic_cast<var_expr*>(pop_nodestack());

  if (theAnnotations)
  {
    if (ZANN_CONTAINS(zann_assignable))
    {
      ve->set_mutable(true);
    }
    else if (ZANN_CONTAINS(zann_nonassignable))
    {
      ve->set_mutable(false);
    }
  }

  xqtref_t type;
  if (v.get_var_type() != NULL)
  {
    type = pop_tstack();

    ve->set_type(type);
  }

  // Put a mapping between the var name and the var_expr in the local sctx.
  // Raise error if var name exists already in local sctx obj.
  bind_var(ve, theSctx);

  // The ve and its associated intExpr will be put into var_decl_expr that
  // will be created by the translation of the parent block expr, immediately
  // after returning from this method.
  push_nodestack(ve);

#ifdef ZORBA_WITH_DEBUGGER
  if (initExpr != NULL && theCCB->theDebuggerCommons != NULL)
  {
    QueryLoc lExpandedLocation =
    expandQueryLoc(v.get_var_name()->get_location(), initExpr->get_loc());

    wrap_in_debugger_expr(initExpr, lExpandedLocation, false, true);
  }
#endif

  push_nodestack(initExpr);

  theAnnotations = NULL;
}


/*******************************************************************************
  AssignStatement ::= "$" VarName ":=" ExprSingle ";"

  Note: the ExprSingle must be non-updating.
********************************************************************************/
void* begin_visit(const AssignExpr& v)
{
  TRACE_VISIT();

  if (!theSctx->is_feature_set(feature::scripting))
  {
    RAISE_ERROR(err::XPST0003, loc, ERROR_PARAMS(ZED(XPST0003_Scripting)));
  }
  return no_state;
}

void end_visit(const AssignExpr& v, void* visit_state)
{
  TRACE_VISIT_OUT();

  var_expr* ve = lookup_var(v.get_name(), loc, true);

  if ((ve->get_kind() != var_expr::local_var &&
       ve->get_kind() != var_expr::prolog_var) ||
      !ve->is_mutable())
  {
    RAISE_ERROR(zerr::XSST0007, loc,
    ERROR_PARAMS(ve->get_name()->getStringValue()));
  }

  xqtref_t varType = ve->get_type();

  expr* valueExpr = pop_nodestack();

  if (varType != NULL)
    valueExpr = theExprManager->create_treat_expr(theRootSctx,
                                                  theUDF,
                                                  loc,
                                                  valueExpr,
                                                  varType,
                                                  TREAT_TYPE_MATCH);

  push_nodestack(theExprManager->create_var_set_expr(theRootSctx,
                                                     theUDF,
                                                     loc,
                                                     ve,
                                                     valueExpr));

  theAssignedVars.back().push_back(ve);
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
  expr* param = pop_nodestack();

  push_nodestack(theExprManager->create_apply_expr(theRootSctx,
                                                   theUDF,
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

  expr* childExpr = pop_nodestack();

  if (childExpr->is_updating())
  {
    theHaveUpdatingExitExprs = true;

    if (!inUDFBody() && !theCCB->theIsEval)
    {
      childExpr = theExprManager->
      create_apply_expr(theRootSctx, theUDF, loc, childExpr, false);
    }
  }
  else if (childExpr->is_sequential())
  {
    theHaveSequentialExitExprs = true;
  }

  expr* exitExpr = theExprManager->
  create_exit_expr(theRootSctx, theUDF, loc, childExpr);

  if (inUDFBody())
  {
    function* f = const_cast<function*>(theCurrentPrologVFDecl.getFunction());
    assert(f->isUdf());
    user_function* udf = static_cast<user_function*>(f);

    udf->setExiting(true);
    theExitExprs.push_back(exitExpr);
  }

  push_nodestack(exitExpr);
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

  expr* bodyExpr = pop_nodestack();
  expr* condExpr = pop_nodestack();

  expr* breakExpr = theExprManager->
  create_flowctl_expr(theRootSctx, theUDF, loc, FLOW_BREAK);

  condExpr = theExprManager->
  create_if_expr(theRootSctx, theUDF, loc, condExpr, create_empty_seq(loc), breakExpr);

  block_expr* seqBody = NULL;

  std::vector<expr*> stmts;

  stmts.push_back(condExpr);
  stmts.push_back(bodyExpr);

  seqBody = theExprManager->
  create_block_expr(bodyExpr->get_sctx(), theUDF, loc, false, stmts, NULL);

  push_nodestack(theExprManager->create_while_expr(theRootSctx, theUDF, loc, seqBody));

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

  FlowCtlAction a;

  switch (v.get_action())
  {
  case FlowCtlStatement::BREAK:
  {
    if (theInWhileStack.empty())
    {
      RAISE_ERROR_NO_PARAMS(zerr::XSST0009, loc);
    }
    a = FLOW_BREAK;
    break;
  }
  case FlowCtlStatement::CONTINUE:
  {
    if (theInWhileStack.empty())
    {
      RAISE_ERROR_NO_PARAMS(zerr::XSST0010, loc);
    }
    a = FLOW_CONTINUE;
    break;
  }
  default:
    ZORBA_FATAL(false, "");
  }

  push_nodestack(CREATE(flowctl)(theRootSctx, theUDF, loc, a));
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

  std::vector<expr*> args;

  for (int i = 0; i < v.numberOfChildren(); ++i)
  {
    expr* e = pop_nodestack();
    args.push_back(e);
  }

  fo_expr* concatExpr = theExprManager->
  create_fo_expr(theRootSctx, theUDF, loc, op_concatenate, args);

  normalize_fo(concatExpr);

  push_nodestack(concatExpr);
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
    ERROR_PARAMS(ZED(XPST0003_XQueryVersionAtLeast30_2), theSctx->xquery_version()));
  }

  flwor_expr* flwor = theExprManager->
  create_flwor_expr(theRootSctx, theUDF, loc, v.is_general());

  expr* retExpr = pop_nodestack();

  wrap_in_debugger_expr(retExpr, retExpr->get_loc());

  flwor->set_return_expr(retExpr);

  csize curClausePos = theFlworClausesStack.size() - 1;

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
      break;
    }
    case flwor_clause::groupby_clause:
    {
      groupby_clause* gc = static_cast<groupby_clause*>(curClause);

      csize numGVars = gc->numGroupingVars();

      for (csize i = 0; i < numGVars; ++i)
        pop_scope();

      pop_scope();
      break;
    }
    case flwor_clause::orderby_clause:
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

  csize numClauses = theFlworClausesStack.size();

  for (csize i = curClausePos + 1; i < numClauses; ++i)
    flwor->add_clause(theFlworClausesStack[i]);

  theFlworClausesStack.resize(curClausePos);

  push_nodestack(flwor);
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
      RAISE_ERROR(err::XPST0003, loc, ERROR_PARAMS(ZED(XPST0003_OuterForClause30)));

    theFlworClausesStack.push_back(NULL);
  }

  return no_state;
}


void end_visit(const ForClause& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  if (v.has_allowing_empty())
  {
    csize curClause = theFlworClausesStack.size() - 1;
    while (theFlworClausesStack[curClause] != NULL)
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

  expr* domainExpr = pop_nodestack();

  if (domainExpr->is_updating())
    throw XQUERY_EXCEPTION(err::XUST0001, ERROR_LOC(loc));

  // it's important to insert the debugger before the scope is pushed.
  // Otherwise, the variable in question would already be in scope for
  // the debugger but no value would be bound
  QueryLoc lExpandedLocation =
  expandQueryLoc(v.get_var_name()->get_location(), domainExpr->get_loc());

  wrap_in_debugger_expr(domainExpr, lExpandedLocation);

  push_scope();

  xqtref_t type = (v.get_var_type() == NULL ? NULL : pop_tstack());

  var_expr* varExpr = bind_var(loc, v.get_var_name(), var_expr::for_var, type);
  var_expr* posVarExpr = NULL;

  const PositionalVar* pv = v.get_posvar();

  if (pv != NULL)
  {
    store::Item_t pvarQName;
    expand_no_default_qname(pvarQName, pv->get_name(), loc);

    if (pvarQName->equals(varExpr->get_name()))
      RAISE_ERROR(err::XQST0089, loc, ERROR_PARAMS(pvarQName->getStringValue()));

    posVarExpr = bind_var(pv->get_location(), pvarQName, var_expr::pos_var);
  }

  for_clause* fc = theExprManager->create_for_clause(theRootSctx,
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

void create_let_clause(
    const QueryLoc loc,
    const QName* varName,
    expr* domainExpr,
    xqtref_t type)
{
  if (domainExpr->is_updating())
    throw XQUERY_EXCEPTION(err::XUST0001, ERROR_LOC(loc));

  // it's important to insert the debugger before the scope is pushed.
  // Otherwise, the variable in question would already be in scope for
  // the debugger but no value would be bound
  QueryLoc lExpandedLocation = expandQueryLoc(varName->get_location(),
                                              domainExpr->get_loc());

  wrap_in_debugger_expr(domainExpr, lExpandedLocation);

  push_scope();

  var_expr* varExpr = bind_var(loc, varName, var_expr::let_var, type);

  let_clause* clause = theExprManager->create_let_clause(theRootSctx,
                                                         loc,
                                                         varExpr,
                                                         domainExpr);

  theFlworClausesStack.push_back(clause);
}


void end_visit(const VarGetsDecl& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  xqtref_t type = (v.get_var_type() == NULL ? NULL : pop_tstack());

  if (v.get_kind() == VarGetsDecl::let_var)
  {
    expr* domainExpr = pop_nodestack();

    create_let_clause(loc, v.get_var_name(), domainExpr, type);
  }
  else
  {
    push_scope();
    push_nodestack(create_var(loc, v.get_var_name(), var_expr::let_var, type));
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
    RAISE_ERROR(err::XPST0003, loc, ERROR_PARAMS(ZED(XPST0003_WindowClause30)));

  return no_state;
}


void intermediate_visit(const WindowClause& v, void* /*visit_state*/)
{
  // This method is called after translating the window domain expr, but before
  // translating the window conditions and the window var.

  // Pop the window the domain expr.
  expr* windowDomainExpr = pop_nodestack();

  WindowKind winKind = (v.get_wintype() == WindowClause::tumbling_window ?
                        tumbling_window :
                        sliding_window);

  window_clause* clause = theExprManager->create_window_clause(theRootSctx,
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

  assert(theFlworClausesStack.back()->get_kind() == flwor_clause::window_clause);

  window_clause* windowClause = 
  static_cast<window_clause*>(theFlworClausesStack.back());

  // Pop the window var and associate it with this window clause
  var_expr* windowVarExpr = pop_nodestack_var();
  windowVarExpr->set_flwor_clause(windowClause);

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
  flwor_wincond* conds[2];

  for (int i = 1; i >= 0; i--)
  {
    rchandle<FLWORWinCond> cond = v[i];
    if (cond != NULL)
    {
      expr* condExpr = pop_nodestack();

      rchandle<WindowVars> vars = cond->get_winvars();
      pop_wincond_vars(vars, inputCondVarExprs[i]);

      conds[i] = theExprManager->create_flwor_wincond(theSctx,
                                                      cond->is_only(),
                                                      inputCondVarExprs[i],
                                                      outputCondVarExprs[i],
                                                      condExpr);
    }
    else
    {
      conds[i] = NULL;
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

  var_expr* posVarExpr = NULL;
  var_expr* curVarExpr = NULL;
  var_expr* nextVarExpr = NULL;
  var_expr* prevVarExpr = NULL;

  rchandle<PositionalVar> pv = v.get_posvar();
  if (pv != NULL)
  {
    posVarExpr = bind_var(pv->get_location(), pv->get_name(), pvarKind);

    posVarExpr->set_flwor_clause(windowClause);
    push_nodestack(posVarExpr);
  }

  if (v.get_curr())
  {
    curVarExpr = bind_var(loc, v.get_curr(), varKind);

    curVarExpr->set_flwor_clause(windowClause);
    push_nodestack(curVarExpr);
  }

  if (v.get_prev())
  {
    prevVarExpr = bind_var(loc, v.get_prev(), varKind);

    prevVarExpr->set_flwor_clause(windowClause);
    push_nodestack(prevVarExpr);
  }

  if (v.get_next())
  {
    nextVarExpr = bind_var(loc, v.get_next(), varKind);

    nextVarExpr->set_flwor_clause(windowClause);
    push_nodestack(nextVarExpr);
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

  // Create scope for the window var and the output window-condition vars
  push_scope();

  xqtref_t type = (v.get_var_type() == NULL ? NULL : pop_tstack());

  var_expr* ve = bind_var(loc, v.get_var_name(), var_expr::win_var, type);

  push_nodestack(ve);
}


/*******************************************************************************
  GroupByClause ::= "group" "by" GroupingSpecList

  GroupSpecList ::= 	GroupingSpec ("," GroupingSpec)*

  GroupSpec ::= "$" VarName (TypeDeclaration? ":=" ExprSingle)?
                ("collation" URILiteral)?

  NOTE: For every group spec that has a binding expression, a let variable will
  be created and placed before the groupby clause.
********************************************************************************/
void* begin_visit(const GroupByClause& v)
{
  TRACE_VISIT();

  const FLWORExpr& flwor = *v.get_flwor ();
  const FLWORClauseList& clauses = *flwor.get_clause_list ();

  std::set<const var_expr *> all_vars;
  std::set<const var_expr *> group_vars;
  std::set<const var_expr *> non_group_vars;

  // Compute the set of non-grouping var_exprs. To do this, we first collect
  // the var_exprs for all the vars that have been defined by all clauses
  // before this GroupByClause. Then we collect the var_exprs for the var
  // names specified in the GroupByClause. The non-grouping vars are the vars
  // in the difference of the 2 sets above.
  //
  // NOTE: If a group spec does not have a binding expression, then a var
  // for the name appearing in the spec should exist already (i.e., be in
  // scope and have a var_expr). Otherwise, the var may or may not exist
  // already. In this case, if a var V exists already, it will be hidden
  // by the new var of the same name defined by the group spec, and so V
  // should not be included in the set of non-grouping vars.
  collect_flwor_vars(flwor, all_vars, &*clauses[0], &v, loc);

  GroupSpecList* speclist = v.get_spec_list();

  for (csize i = 0; i < speclist->size(); ++i)
  {
    GroupSpec* spec = (*speclist)[i];

    const QName* varname = spec->get_var_name();

    const var_expr* ve = NULL;

    if (spec->get_binding_expr() == NULL)
    {
      ve = lookup_var(varname, loc, true);

      if (all_vars.find(ve) == all_vars.end())
      {
        RAISE_ERROR(err::XQST0094, loc,
        ERROR_PARAMS(ve->get_name()->getStringValue()));
      }
    }
    else
    {
      ve = lookup_var(varname, loc, false);
    }

    if (ve != NULL)
      group_vars.insert(ve);
  }

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

    var_expr* ve = create_var(loc, (*i)->get_name(), var_expr::non_groupby_var);
    push_nodestack(ve);
  }

  return no_state;
}


void end_visit(const GroupByClause& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  const GroupSpecList& groupSpecs = *v.get_spec_list();
  csize numGroupSpecs = groupSpecs.size();

  std::vector<std::string> collations;
  groupby_clause::rebind_list_t grouping_rebind;
  groupby_clause::rebind_list_t nongrouping_rebind;

  static_context* sctx = theSctx;

  for (csize i = 0; i < numGroupSpecs; ++i)
  {
    const GroupSpec& groupSpec = *groupSpecs[i];

    csize j;
    for (j = 0; j < i; ++j)
    {
      const GroupSpec& prevSpec = *groupSpecs[j];

      if (*groupSpec.get_var_name() == *prevSpec.get_var_name())
      {
        if (groupSpec.get_collation_spec() == NULL &&
            prevSpec.get_collation_spec() == NULL)
          break;

        if (groupSpec.get_collation_spec() != NULL &&
            prevSpec.get_collation_spec() != NULL &&
            groupSpec.get_collation_spec()->get_uri() ==
            prevSpec.get_collation_spec()->get_uri())
          break;
      }
    }

    if (j == i)
    {
      const QueryLoc& specLoc = groupSpec.get_location();

      // Since group specs can add let vars, and change the value of the
      // input_expr after the expr has been read, we delegate the actual looking
      // up of the variable until now, to get the most recent and correct value.

      store::Item_t varName;
      expand_no_default_qname(varName, groupSpec.get_var_name(), specLoc);

      VarInfo* var = sctx->lookup_var(varName.getp());
      if (!var)
      {
        RAISE_ERROR(err::XPST0008, specLoc,
        ERROR_PARAMS(ZED(XPST0008_VariableName_2), varName->getStringValue()));
      }

      expr* inputExpr = var->getVar();

      assert(inputExpr->get_expr_kind() == var_expr_kind);

      inputExpr = CREATE(wrapper)(theRootSctx, theUDF, specLoc, inputExpr);

      inputExpr = wrap_in_atomization(inputExpr);

      inputExpr = wrap_in_type_match(inputExpr,
                                     theRTM.ANY_ATOMIC_TYPE_QUESTION,
                                     specLoc,
                                     TREAT_MULTI_VALUED_GROUPING_KEY);

      // We need to do this to handle grouping vars with same names but
      // different collations.
      push_scope();

      var_expr* gVar = bind_var(specLoc,
                                groupSpec.get_var_name(),
                                var_expr::groupby_var,
                                inputExpr->get_return_type());

      grouping_rebind.push_back(std::pair<expr*, var_expr*>(inputExpr, gVar));

      if (groupSpec.get_collation_spec() != NULL)
      {
        std::string collationUri = groupSpec.get_collation_spec()->get_uri().str();

        if (! theSctx->is_known_collation(collationUri))
          RAISE_ERROR(err::XQST0076, specLoc, ERROR_PARAMS(collationUri));

        collations.push_back(collationUri);
      }
      else
      {
        collations.push_back ("");
      }
    }
  }

  // At this point, the nodestack contains a pair of var_exprs for each
  // non-grouping var. The 1stvar_expr in the pair corresponds to the
  // input-stream var X, and the 2nd var_expr corresponds to the associated
  // output-stream var.

  push_scope();

  var_expr* ngVar = NULL;

  while (NULL != (ngVar = pop_nodestack_var()))
  {
    var_expr* inputVar = pop_nodestack_var();

    bind_var(ngVar, theSctx);

    expr* inputExpr =
    theExprManager->create_wrapper_expr(theRootSctx, theUDF, loc, inputVar);

    nongrouping_rebind.push_back(std::pair<expr*, var_expr*>(inputExpr, ngVar));
  }

  groupby_clause* clause = theExprManager->
  create_groupby_clause(theRootSctx,
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
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  GroupSpec ::= "$" VarName (TypeDeclaration? ":=" ExprSingle)?
                ("collation" URILiteral)?
********************************************************************************/
void* begin_visit(const GroupSpec& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const GroupSpec& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  xqtref_t type = NULL;

  if (v.get_binding_expr() != NULL)
  {
    expr* domainExpr = pop_nodestack();

    if (v.get_var_type() != NULL)
      type = pop_tstack();

    create_let_clause(loc, v.get_var_name(), domainExpr, type);
  }
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
void* begin_visit(const OrderByClause& v)
{
  TRACE_VISIT ();
  return no_state;
}


void end_visit(const OrderByClause& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  const OrderSpecList& orderSpecs = *v.get_spec_list();
  csize numOrderSpecs = orderSpecs.size();

  std::vector<OrderModifier> modifiers(numOrderSpecs);
  std::vector<expr*> orderExprs(numOrderSpecs);

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
        RAISE_ERROR(err::XQST0076, loc, ERROR_PARAMS(collationUri));
    }

    expr* orderExpr = pop_nodestack();

    if (orderExpr->is_updating())
      throw XQUERY_EXCEPTION(err::XUST0001, ERROR_LOC(loc));

    orderExpr = wrap_in_atomization(orderExpr);

    modifiers[i].theAscending = (dirSpec == ParseConstants::dir_ascending);
    modifiers[i].theEmptyLeast = (emptySpec == StaticContextConsts::empty_least);
    modifiers[i].theCollation = collationUri;

    orderExprs[i] = orderExpr;
  }

  orderby_clause* clause = theExprManager->
  create_orderby_clause(theRootSctx,
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

  expr* whereExpr = pop_nodestack();

  if (whereExpr->is_updating())
    throw XQUERY_EXCEPTION(err::XUST0001, ERROR_LOC(loc));

  whereExpr = wrap_in_bev(whereExpr);

  wrap_in_debugger_expr(whereExpr, whereExpr->get_loc());

  where_clause* clause = theExprManager->create_where_clause(theRootSctx,
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
    RAISE_ERROR(err::XPST0003, loc, ERROR_PARAMS(ZED(XPST0003_CountClause30)));

  return no_state;
}

void end_visit(const CountClause& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  var_expr* varExpr = bind_var(loc, v.get_varname(), var_expr::count_var, NULL);

  count_clause* clause = theExprManager->create_count_clause(theRootSctx,
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
    RAISE_ERROR(err::XPST0003, loc, ERROR_PARAMS(ZED(XPST0003_SwitchExpr30)));
  }

  v.get_switch_expr()->accept(*this);

  expr* se = pop_nodestack();

  se = wrap_in_atomization(se);

  // atomizedFlwor = [let $atomv := data(E) return NULL]
  var_expr* atomv = create_temp_var(v.get_switch_expr()->get_location(),
                                     var_expr::let_var);

  expr* atomizedFlwor = wrap_in_let_flwor(se, atomv, NULL);

  // TODO: cast as xs:string should not really be necessary
  // atomizedFlwor =
  //  [let $atomv := data(E)
  //   return
  //     let $sv :=
  //          if ($atomv instanceof xs:untypedAtomic)
  //          then $atomv cast as xs:string
  //          else $atomv
  //     return NULL]
  static_cast<flwor_expr*>(atomizedFlwor)->set_return_expr(
      CREATE(if)(theRootSctx,
                 theUDF,
                 loc,
                 CREATE(instanceof)(theRootSctx,
                                    theUDF,
                                    loc,
                                    atomv,
                                    theRTM.UNTYPED_ATOMIC_TYPE_ONE),
                 CREATE(cast)(theRootSctx,
                              theUDF,
                              loc,
                              atomv,
                              theRTM.STRING_TYPE_ONE,
                              false),
                 atomv));

  // flworExpr = [let $sv := atomizedFlwor return NULL]
  var_expr* sv = create_temp_var(v.get_switch_expr()->get_location(), var_expr::let_var);
  expr* flworExpr = wrap_in_let_flwor(atomizedFlwor, sv, NULL);

  // retExpr = [Ed]
  v.get_default_expr()->accept(*this);
  expr* retExpr = pop_nodestack();

  const SwitchCaseClauseList* clauses = v.get_clause_list();
  std::vector<rchandle<SwitchCaseClause> >::const_reverse_iterator it;

  for (it = clauses->rbegin(); it != clauses->rend(); ++it)
  {
    const SwitchCaseClause* switchCaseClause = &**it;
    const QueryLoc& loc = switchCaseClause->get_location();

    const SwitchCaseOperandList* operands = switchCaseClause->get_operand_list();

    expr* condExpr = NULL;
    std::vector<expr*> condOperands;
    condOperands.reserve(operands->size());

    for (std::vector<rchandle<exprnode> >::const_iterator it = operands->begin();
         it != operands->end();
         ++it)
    {
      const exprnode* operand = &**it;
      operand->accept(*this);

      expr* operandExpr = pop_nodestack();
      operandExpr = wrap_in_atomization(operandExpr);
      operandExpr = CREATE(fo)(theRootSctx,
                               theUDF,
                               loc,
                               BUILTIN_FUNC(OP_ATOMIC_VALUES_EQUIVALENT_2),
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
      condExpr = theExprManager->
      create_fo_expr(theRootSctx,
                     theUDF,
                     loc,
                     BUILTIN_FUNC(OP_OR_N),
                     condOperands);
    }

    switchCaseClause->get_return_expr()->accept(*this);
    expr* caseReturnExpr = pop_nodestack();

    // retExpr = [if (condExpr) then caseReturnExpr else retExpr]
    retExpr = theExprManager->
    create_if_expr(theRootSctx, theUDF, loc, condExpr, caseReturnExpr, retExpr);

  } // for

  static_cast<flwor_expr*>(flworExpr)->set_return_expr(retExpr);
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

  CaseClause ::= "case" ("$" VarName "as")? SequenceTypeList "return" ExprSingle


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

  var_expr* sv = create_temp_var(v.get_switch_expr()->get_location(),
                                 var_expr::let_var);

  v.get_switch_expr()->accept(*this);

  expr* se = pop_nodestack();

  // flworExpr = [let $sv := E return NULL]
  expr* retExpr = NULL;
  expr* flworExpr = wrap_in_let_flwor(se, sv, retExpr);

  const QName* defVarName = v.get_default_varname();
  var_expr* defvar = NULL;

  if (defVarName)
  {
    push_scope();
    defvar = bind_var(v.get_default_clause()->get_location(),
                      defVarName,
                      var_expr::let_var);

    // retExpr = [let $def := $sv return NULL]
    retExpr = &*wrap_in_let_flwor(&*sv, defvar, NULL);
  }

  v.get_default_clause()->accept(*this);

  expr* defExpr = pop_nodestack();

  if (defVarName)
  {
    pop_scope();

    // retExpr = [let $def := $sv return Ed]
    static_cast<flwor_expr*>(retExpr)->set_return_expr(defExpr);
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
    expr* clauseExpr = NULL;
    expr* condExpr;

    csize numTypes = caseClause->num_types();
    xqtref_t type;
    std::vector<expr*> typeCheckExprs;
    typeCheckExprs.reserve(numTypes);
    for (csize i = 0; i < numTypes; ++i)
    {
      caseClause->get_type(i)->accept(*this);

      type = pop_tstack();

      expr* e = CREATE(instanceof)(theRootSctx, theUDF, loc, &*sv, type);
      typeCheckExprs.push_back(e);
    }

    if (numTypes > 1)
    {
      if (theSctx->xquery_version() < StaticContextConsts::xquery_version_3_0)
      {
        RAISE_ERROR(err::XPST0003, loc, ERROR_PARAMS(ZED(XPST0003_SwitchExpr30)));
      }

      function* orFunc = BUILTIN_FUNC(OP_OR_N);
      condExpr = CREATE(fo)(theRootSctx, theUDF, loc, orFunc, typeCheckExprs);
    }
    else
    {
      condExpr = typeCheckExprs[0];
    }

    const QName* varname = caseClause->get_varname();
    var_expr* caseVar = NULL;

    if (varname)
    {
      push_scope();

      caseVar = bind_var(loc, varname, var_expr::let_var);

      if (numTypes == 1)
      {
        expr* treatExpr = CREATE(treat)(theRootSctx,
                                        theUDF,
                                        loc,
                                        sv,
                                        type,
                                        TREAT_EXPR);

        // clauseExpr = [let $caseVar := treat_as($sv, caseType) return NULL]
        clauseExpr = wrap_in_let_flwor(treatExpr, caseVar, NULL);
      }
      else
      {
        // clauseExpr = [let $caseVar := $sv return NULL]
        clauseExpr = wrap_in_let_flwor(sv, caseVar, NULL);
      }
    }

    caseClause->get_expr()->accept(*this);
    expr* caseExpr = pop_nodestack();

    if (varname)
    {
      pop_scope();

      // clauseExpr = [let $caseVar := treat_as($sv, caseType) return caseExpr]
      static_cast<flwor_expr*>(clauseExpr)->set_return_expr(caseExpr);
    }
    else
    {
      // clauseExpr = [caseExpr]
      clauseExpr = caseExpr;
    }

    // retExpr = [if (instance_of($sv, type)) then clauseExpr else retExpr]
    retExpr = CREATE(if)(theRootSctx, theUDF, loc, condExpr, clauseExpr, retExpr);
  }

  static_cast<flwor_expr*>(flworExpr)->set_return_expr(retExpr);

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

  expr* e_h = pop_nodestack();
  expr* t_h = pop_nodestack();
  expr* c_h = pop_nodestack();

  wrap_in_debugger_expr(e_h, e_h->get_loc());
  wrap_in_debugger_expr(t_h, t_h->get_loc());
  wrap_in_debugger_expr(c_h, c_h->get_loc());

  if_expr* ifExpr = theExprManager->create_if_expr(theRootSctx, theUDF, loc, c_h, t_h, e_h);

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
    RAISE_ERROR(err::XPST0003, loc, ERROR_PARAMS(ZED(XPST0003_TryCatchExpr30)));
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

  expr* tryExpr = pop_nodestack();

  trycatch_expr* tce = theExprManager->create_trycatch_expr(theRootSctx, theUDF, loc, tryExpr);

  push_nodestack(tce);

  return no_state;
}

void end_visit(const CatchListExpr& v, void* visit_state)
{
  TRACE_VISIT_OUT();

  trycatch_expr* tce = static_cast<trycatch_expr*>(theNodeStack.top());

  tce->compute_scripting_kind();
}


/*******************************************************************************
  [172] CatchClause ::= "catch" CatchErrorList "{" Expr "}"

  [173] CatchErrorList ::= NameTest ("|" NameTest)*
********************************************************************************/
void* begin_visit(const CatchExpr& v)
{
  TRACE_VISIT();

  trycatch_expr* tce = dynamic_cast<trycatch_expr *>(theNodeStack.top());

  catch_clause* cc = theExprManager->create_catch_clause();

  push_scope();

  store::Item_t lCode, lDesc, lValue, lModule, lLineNo, lColumnNo,
                lDataURI, lDataLineNo, lDataColumnNo, lLineNoEnd, lColumnNoEnd, lStackTrace;

  GENV_ITEMFACTORY->createQName(lCode, XQUERY_ERR_NS, "", "code");
  GENV_ITEMFACTORY->createQName(lDesc, XQUERY_ERR_NS, "", "description");
  GENV_ITEMFACTORY->createQName(lValue, XQUERY_ERR_NS, "", "value");
  GENV_ITEMFACTORY->createQName(lModule, XQUERY_ERR_NS, "", "module");
  GENV_ITEMFACTORY->createQName(lLineNo, XQUERY_ERR_NS, "", "line-number");
  GENV_ITEMFACTORY->createQName(lColumnNo, XQUERY_ERR_NS, "", "column-number");
  GENV_ITEMFACTORY->createQName(lDataURI, ZORBA_ERR_NS, "", "data-uri");
  GENV_ITEMFACTORY->createQName(lDataLineNo, ZORBA_ERR_NS, "", "data-line-number");
  GENV_ITEMFACTORY->createQName(lDataColumnNo, ZORBA_ERR_NS, "", "data-column-number");
  GENV_ITEMFACTORY->createQName(lLineNoEnd, ZORBA_ERR_NS, "", "line-number-end");
  GENV_ITEMFACTORY->createQName(lColumnNoEnd, ZORBA_ERR_NS, "", "column-number-end");
  GENV_ITEMFACTORY->createQName(lStackTrace, ZORBA_ERR_NS, "", "stack-trace");

  cc->add_var(catch_clause::err_code,
      bind_var(loc, lCode, var_expr::catch_var, theRTM.QNAME_TYPE_ONE));

  cc->add_var(catch_clause::err_desc,
      bind_var(loc, lDesc, var_expr::catch_var, theRTM.STRING_TYPE_QUESTION));

  cc->add_var(catch_clause::err_value,
      bind_var(loc, lValue, var_expr::catch_var, theRTM.ITEM_TYPE_STAR));

  cc->add_var(catch_clause::err_module,
      bind_var(loc, lModule, var_expr::catch_var, theRTM.STRING_TYPE_QUESTION));

  cc->add_var(catch_clause::err_line_no,
      bind_var(loc, lLineNo, var_expr::catch_var, theRTM.INTEGER_TYPE_QUESTION));

  cc->add_var(catch_clause::err_column_no,
      bind_var(loc, lColumnNo, var_expr::catch_var, theRTM.INTEGER_TYPE_QUESTION));

  cc->add_var(catch_clause::zerr_data_uri,
      bind_var(loc, lDataURI, var_expr::catch_var, theRTM.STRING_TYPE_QUESTION));

  cc->add_var(catch_clause::zerr_data_line_no,
      bind_var(loc, lDataLineNo, var_expr::catch_var, theRTM.INTEGER_TYPE_QUESTION));

  cc->add_var(catch_clause::zerr_data_column_no,
      bind_var(loc, lDataColumnNo, var_expr::catch_var, theRTM.INTEGER_TYPE_QUESTION));

  cc->add_var(catch_clause::zerr_line_no_end,
      bind_var(loc, lLineNoEnd, var_expr::catch_var, theRTM.INTEGER_TYPE_QUESTION));

  cc->add_var(catch_clause::zerr_column_no_end,
      bind_var(loc, lColumnNoEnd, var_expr::catch_var, theRTM.INTEGER_TYPE_QUESTION));

  cc->add_var(catch_clause::zerr_stack_trace,
      bind_var(loc, lStackTrace, var_expr::catch_var, theRTM.ITEM_TYPE_QUESTION));

  tce->add_clause(cc);

  return no_state;
}

void end_visit(const CatchExpr& v, void* visit_state)
{
  TRACE_VISIT_OUT();

  expr* ce = pop_nodestack();
  trycatch_expr* tce = dynamic_cast<trycatch_expr *>(theNodeStack.top());

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

  flwor_expr* flwor(theExprManager->create_flwor_expr(theRootSctx, theUDF, loc, false));

  flwor->set_return_expr(theExprManager->create_const_expr(theRootSctx, theUDF, loc, true));

  push_nodestack(flwor);

  return no_state;
}


void end_visit(const QuantifiedExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr* testExpr = pop_nodestack();

  if (v.get_qmode() == ParseConstants::quant_every)
  {
    fo_expr* uw = theExprManager->create_fo_expr(theRootSctx, theUDF,
                                       v.get_expr()->get_location(),
                                       BUILTIN_FUNC(FN_NOT_1),
                                       testExpr);
    testExpr = uw;
  }
  else
  {
    testExpr = wrap_in_bev(testExpr);
  }

  for (int i = 0; i < (int)v.get_decl_list()->size(); ++i)
  {
    pop_scope();
  }

  flwor_expr* flworExpr = dynamic_cast<flwor_expr*>(pop_nodestack());
  ZORBA_ASSERT(flworExpr != NULL);

  flworExpr->add_where(testExpr);

  fo_expr* quant = theExprManager->create_fo_expr(theRootSctx, theUDF,
                                        loc,
                                        v.get_qmode() == ParseConstants::quant_every ?
                                        BUILTIN_FUNC(FN_EMPTY_1) :
                                        BUILTIN_FUNC(FN_EXISTS_1),
                                        flworExpr);
  push_nodestack(quant);
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

  expr* domainExpr = pop_nodestack();
  var_expr* varExpr = bind_var(loc, v.get_name(), var_expr::for_var, type);

  flwor_expr* flworExpr = dynamic_cast<flwor_expr*>(theNodeStack.top());
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

  expr* e1 = pop_nodestack();
  expr* e2 = pop_nodestack();

  std::vector<expr*> args;
  args.reserve(2);

  if (e2->get_expr_kind() == fo_expr_kind)
  {
    fo_expr* foArg = static_cast<fo_expr*>(e2);

    if (foArg->get_func()->getKind() == FunctionConsts::OP_OR_N)
    {
      csize numArgs = foArg->num_args();
      for (csize i = 0; i < numArgs; ++i)
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
    fo_expr* foArg = static_cast<fo_expr*>(e1);

    if (foArg->get_func()->getKind() == FunctionConsts::OP_OR_N)
    {
      csize numArgs = foArg->num_args();
      for (csize i = 0; i < numArgs; ++i)
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

  fo_expr* fo = CREATE(fo)(theRootSctx, theUDF, loc, BUILTIN_FUNC(OP_OR_N), args);

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

  expr* e1 = pop_nodestack();
  expr* e2 = pop_nodestack();

  std::vector<expr*> args;
  args.reserve(2);

  if (e2->get_expr_kind() == fo_expr_kind)
  {
    fo_expr* foArg = static_cast<fo_expr*>(e2);

    if (foArg->get_func()->getKind() == FunctionConsts::OP_AND_N)
    {
      csize numArgs = foArg->num_args();
      for (csize i = 0; i < numArgs; ++i)
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
    fo_expr* foArg = static_cast<fo_expr*>(e1);

    if (foArg->get_func()->getKind() == FunctionConsts::OP_AND_N)
    {
      csize numArgs = foArg->num_args();
      for (csize i = 0; i < numArgs; ++i)
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

  fo_expr* fo = CREATE(fo)(theRootSctx, theUDF, loc, BUILTIN_FUNC(OP_AND_N), args);

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
      f = BUILTIN_FUNC(OP_EQUAL_2);
      break;
    case ParseConstants::op_ne:
      f = BUILTIN_FUNC(OP_NOT_EQUAL_2);
      break;
    case ParseConstants::op_lt:
      f = BUILTIN_FUNC(OP_LESS_2);
      break;
    case ParseConstants::op_le:
     f = BUILTIN_FUNC(OP_LESS_EQUAL_2);
     break;
    case ParseConstants::op_gt:
      f = BUILTIN_FUNC(OP_GREATER_2);
      break;
    case ParseConstants::op_ge:
      f = BUILTIN_FUNC(OP_GREATER_EQUAL_2);
      break;
    }
  }
  else if (v.get_valcomp() != NULL)
  {
    switch (v.get_valcomp()->get_type())
    {
    case ParseConstants::op_val_eq:
      f = BUILTIN_FUNC(OP_VALUE_EQUAL_2);
      break;
    case ParseConstants::op_val_ne:
      f = BUILTIN_FUNC(OP_VALUE_NOT_EQUAL_2);
      break;
    case ParseConstants::op_val_lt:
      f = BUILTIN_FUNC(OP_VALUE_LESS_2);
      break;
    case ParseConstants::op_val_le:
     f = BUILTIN_FUNC(OP_VALUE_LESS_EQUAL_2);
     break;
    case ParseConstants::op_val_gt:
      f = BUILTIN_FUNC(OP_VALUE_GREATER_2);
      break;
    case ParseConstants::op_val_ge:
      f = BUILTIN_FUNC(OP_VALUE_GREATER_EQUAL_2);
      break;
    }
  }
  else if (v.get_nodecomp() != NULL)
  {
    switch (v.get_nodecomp()->get_type())
    {
    case ParseConstants::op_is:
      f = BUILTIN_FUNC(OP_IS_SAME_NODE_2);
      break;
    case ParseConstants::op_precedes:
      f = BUILTIN_FUNC(OP_NODE_BEFORE_2);
      break;
    case ParseConstants::op_follows:
      f = BUILTIN_FUNC(OP_NODE_AFTER_2);
      break;
    }
  }

  expr* e1 = pop_nodestack();
  expr* e2 = pop_nodestack();

  fo_expr* fo = theExprManager->create_fo_expr(theRootSctx, theUDF, loc, f, e2, e1);

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

  expr* e1 = pop_nodestack();
  expr* e2 = pop_nodestack();

  fo_expr* e = theExprManager->create_fo_expr(theRootSctx, theUDF, loc, BUILTIN_FUNC(OP_TO_2), e2, e1);

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

  expr* e1 = pop_nodestack();
  expr* e2 = pop_nodestack();

  function* func = NULL;

  switch (v.get_add_op())
  {
  case ParseConstants::op_plus:
    func = BUILTIN_FUNC(OP_ADD_2);
    break;
  case ParseConstants::op_minus:
    func = BUILTIN_FUNC(OP_SUBTRACT_2);
    break;
  }

  fo_expr* foExpr = theExprManager->create_fo_expr(theRootSctx, theUDF, loc, func, e2, e1);

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

  expr* e1 = pop_nodestack();
  expr* e2 = pop_nodestack();

  function* f = NULL;
  switch (v.get_mult_op())
  {
  case ParseConstants::op_mul:
    f = BUILTIN_FUNC(OP_MULTIPLY_2);
    break;
  case ParseConstants::op_div:
    f = BUILTIN_FUNC(OP_DIVIDE_2);
    break;
  case ParseConstants::op_idiv:
    f = BUILTIN_FUNC(OP_INTEGER_DIVIDE_2);
    break;
  case ParseConstants::op_mod:
    f = BUILTIN_FUNC(OP_MOD_2);
    break;
  }

  fo_expr* foExpr = theExprManager->create_fo_expr(theRootSctx, theUDF, loc, f, e2, e1);

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

  expr* e1 = pop_nodestack();
  expr* e2 = pop_nodestack();

  fo_expr* foExpr = theExprManager->create_fo_expr(theRootSctx, theUDF,
                                loc,
                                BUILTIN_FUNC(OP_UNION_2),
                                e2,
                                e1);

  normalize_fo(foExpr);

  // Union is implemented by a concat iterator, so we have to do node sorting
  // and duplicate elimi
  push_nodestack(theExprManager->create_fo_expr(theRootSctx, theUDF,
                             loc,
                             BUILTIN_FUNC(OP_SORT_DISTINCT_NODES_ASC_1),
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

  expr* e1 = pop_nodestack();
  expr* e2 = pop_nodestack();

  function* f = NULL;
  switch (v.get_intex_op())
  {
  case ParseConstants::op_intersect:
    f = BUILTIN_FUNC(OP_INTERSECT_2);
    break;
  case ParseConstants::op_except:
    f = BUILTIN_FUNC(OP_EXCEPT_2);
    break;
  }

  fo_expr* foExpr = CREATE(fo)(theRootSctx, theUDF, loc, f, e2, e1);

  normalize_fo(foExpr);

  push_nodestack(CREATE(fo)(theRootSctx, theUDF,
                            loc,
                            BUILTIN_FUNC(OP_SORT_DISTINCT_NODES_ASC_1),
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

  push_nodestack(CREATE(instanceof)(theRootSctx,
                                    theUDF,
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

  push_nodestack(CREATE(treat)(theRootSctx,
                               theUDF,
                               loc,
                               pop_nodestack(),
                               pop_tstack(),
                               TREAT_EXPR));
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

  bool allowsEmpty = v.singletype()->get_hook_bit();

  expr* castableExpr = 
  create_cast_expr(loc, pop_nodestack(), pop_tstack(), allowsEmpty, false);

  push_nodestack(castableExpr);
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

  bool allowsEmpty = v.get_singletype()->get_hook_bit();

  expr* castExpr = 
  create_cast_expr(loc, pop_nodestack(), pop_tstack(), allowsEmpty, true);

  push_nodestack(castExpr);
}


/*******************************************************************************
	SingleType ::= SimpleTypeName "?"?

  SimpleTypeName ::= EQNAME
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
  {
    xqtref_t type = pop_tstack();

    assert(type->get_quantifier() == TypeConstants::QUANT_ONE ||
           type->get_quantifier() == TypeConstants::QUANT_STAR);

    if (type->get_quantifier() == TypeConstants::QUANT_ONE)
    {
      theTypeStack.push(CTX_TM->create_type(*type, TypeConstants::QUANT_QUESTION));
    }
  }
  // else leave type as it is on tstack
}


/*******************************************************************************
  SimpleTypeName ::= EQNAME
********************************************************************************/
void* begin_visit(const SimpleType& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const SimpleType& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  rchandle<QName> qname = v.get_qname();
  store::Item_t qnameItem;
  expand_type_qname(qnameItem, qname, loc);

  xqtref_t t = CTX_TM->create_named_simple_type(qnameItem);

  if (t == NULL)
  {
    if (theSctx->xquery_version() < StaticContextConsts::xquery_version_3_0)
    {
      RAISE_ERROR(err::XPST0051, loc,
      ERROR_PARAMS(ZED(XPST0051_Atomic_2), qname->get_qname()));
    }
    else
    {
      RAISE_ERROR(err::XQST0052, loc, ERROR_PARAMS(qname->get_qname()));
    }
  }
  else
  {
    theTypeStack.push(t);
  }
}


/*******************************************************************************

********************************************************************************/
expr* create_cast_expr(
    const QueryLoc& loc,
    expr* node,
    const xqtref_t& type,
    bool allowsEmpty,
    bool isCast)
{
  TypeManager* tm = CTX_TM;

  if (!type->isAtomicAny())
  {
    if (theSctx->xquery_version() < StaticContextConsts::xquery_version_3_0)
    {
      RAISE_ERROR(err::XPST0051, loc,
      ERROR_PARAMS(ZED(XPST0051_Atomic_2), type->toSchemaString()));
    }
  }

  if (TypeOps::is_equal(tm, *type, *theRTM.NOTATION_TYPE_ONE, loc) ||
      TypeOps::is_equal(tm, *type, *theRTM.NOTATION_TYPE_QUESTION, loc) ||
      TypeOps::is_equal(tm, *type, *theRTM.ANY_ATOMIC_TYPE_ONE, loc) ||
      TypeOps::is_equal(tm, *type, *theRTM.ANY_ATOMIC_TYPE_QUESTION, loc))
  {
    RAISE_ERROR(err::XPST0080, loc, ERROR_PARAMS(type->toString()));
  }

  if (TypeOps::is_subtype(tm, *type, *theRTM.QNAME_TYPE_QUESTION, loc))
  {
    if (node->get_expr_kind() == const_expr_kind)
    {
      const const_expr* ce = static_cast<const_expr*>(node);

      if (ce->get_val()->getTypeCode() == store::XS_STRING)
      {
        store::Item_t result;
        try
        {
          GenericCast::castToQName(result, ce->get_val(), theNSCtx, false, tm, loc);
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
              ERROR_PARAMS(ce->get_val()->getStringValue()));
          }
        }

        if (type->type_kind() == XQType::USER_DEFINED_KIND)
        {
          const UserDefinedXQType* udt = 
          static_cast<const UserDefinedXQType*>(type.getp());

          store::Item_t tmp = result;
          store::Item_t typeName = udt->getQName();
          GENV_ITEMFACTORY->createUserTypedAtomicItem(result, tmp, typeName);
        }

        assert(result != NULL || ! isCast);
        return (isCast ?
                CREATE(const)(theRootSctx, theUDF, loc, result) :
                CREATE(const)(theRootSctx, theUDF, loc, result != NULL));
      }
    }

    xqtref_t inputType = node->get_return_type();

    if (theSctx->xquery_version() < StaticContextConsts::xquery_version_3_0)
    {
      // when casting to type T, where T is QName or subtype of, and the input
      // is not a const expr, then the input MUST be of type T or subtype of.
      if (isCast)
      {
        if (TypeOps::is_subtype(tm, *inputType, *theRTM.QNAME_TYPE_STAR, loc))
        {
          return CREATE(cast)(theRootSctx, theUDF, loc, node, type, allowsEmpty);
        }
        else
        {
          return CREATE(treat)(theRootSctx, theUDF, loc, node, type, TREAT_TYPE_MATCH);
        }
      }
      else
      {
        return CREATE(instanceof)(theRootSctx, theUDF, loc, node, type);
      }
    }

    expr* input = wrap_in_atomization(node);

    if (TypeOps::is_subtype(tm, *inputType, *theRTM.ANY_NODE_TYPE_PLUS, loc))
    {
      if (isCast)
      {
        RAISE_ERROR(err::XPTY0117, loc, ERROR_PARAMS(ZED(XPTY0117_NodeCast)));
      }
      else
      {
        return CREATE(const)(theRootSctx, theUDF, loc, false);
      }
    }

    if (isCast)
      return CREATE(cast)(theRootSctx, theUDF, loc, input, type, allowsEmpty);
    else
      return CREATE(castable)(theRootSctx, theUDF, loc, input, type, allowsEmpty);
  }
  else
  {
    expr* input = wrap_in_atomization(node);

    if (isCast)
      return CREATE(cast)(theRootSctx, theUDF, loc, input, type, allowsEmpty);
    else
      return CREATE(castable)(theRootSctx, theUDF, loc, input, type, allowsEmpty);
  }
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

  expr* e1 = pop_nodestack();

  fo_expr* foExpr = theExprManager->create_fo_expr(theRootSctx, theUDF,
                                loc,
                                (v.get_signlist()->get_sign() ?
                                 BUILTIN_FUNC(OP_UNARY_PLUS_1) :
                                 BUILTIN_FUNC(OP_UNARY_MINUS_1)),
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

  push_nodestack(theExprManager->create_validate_expr(theRootSctx, theUDF,
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

  if (v.get_expr() == NULL)
  {
    throw XQUERY_EXCEPTION( err::XQST0079, ERROR_LOC(loc) );
  }

  return no_state;
}

void end_visit(const ExtensionExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  size_t lNumPragmas = v.get_pragma_list()->get_pragmas().size();
  theScopedPragmas.resize(theScopedPragmas.size() - lNumPragmas);
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
  store::Item_t lQName;
  expand_no_default_qname(lQName, v.get_name(), v.get_name()->get_location());

  if (lQName->getPrefix().empty() && lQName->getNamespace().empty())
  {
    RAISE_ERROR(err::XPST0081, loc, ERROR_PARAMS(lQName->getStringValue()));
  }

  pragma* lPragma = theExprManager->create_pragma(lQName, v.get_pragma_lit());

  // popped in end_visit(ExtensionExpr)
  theScopedPragmas.push_back(lPragma);

  return no_state;
}

void end_visit(const Pragma& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  SimpleMapExpr :: PathExpr |
                   SimpleMapExpr "!" PathExpr

  This creates a left-deep tree of SimpleMapExpr nodes: the right child of each
  such node is a PathExpr, and the left child is another SimpleMapExpr except
  from the left-most SimpleMapExpr node, whose left chils is a PathExpr.
********************************************************************************/
void* begin_visit(const SimpleMapExpr& v)
{
  TRACE_VISIT();

  v.get_left_expr()->accept(*this);

  expr* left  = pop_nodestack();

  flwor_expr* flworExpr = wrap_expr_in_flwor(left, true);

  v.get_right_expr()->accept(*this);

  expr* right = pop_nodestack();

  flworExpr->set_return_expr(right);

  pop_scope();

  push_nodestack(flworExpr);

  return NULL;
}

void end_visit(const SimpleMapExpr& v, void* /* visit_state */)
{
  TRACE_VISIT_OUT();
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

  relpath_expr* pathExpr = NULL;

  // Put a NULL in the stack to mark the beginning of a PathExp tree.
  push_nodestack(NULL);

  theNodeSortStack.push(NodeSortInfo());

  // In cases 2, 3, and 4 create a new empty relpath_expr
  if (pe_type != ParseConstants::path_leading_lone_slash)
  {
    pathExpr = theExprManager->create_relpath_expr(theRootSctx, theUDF, loc);
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
    relpath_expr* ctx_path_expr = theExprManager->create_relpath_expr(theRootSctx, theUDF, loc);

    expr* sourceExpr = theExprManager->create_treat_expr(theRootSctx, theUDF,
                                       loc,
                                       DOT_REF,
                                       GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
                                       TREAT_PATH_DOT);

    ctx_path_expr->add_back(sourceExpr);

    match_expr* me = CREATE(match)(theRootSctx, theUDF, loc);
    me->setTestKind(match_anykind_test);
    axis_step_expr* ase = CREATE(axis_step)(theRootSctx, theUDF, loc);
    ase->setAxis(axis_kind_self);
    ase->setTest(me);

    ctx_path_expr->add_back(&*ase);

    fo_expr* fnroot = CREATE(fo)(theRootSctx,
                                 theUDF,
                                 loc,
                                 BUILTIN_FUNC(FN_ROOT_1),
                                 ctx_path_expr);
    normalize_fo(fnroot);

    if (pathExpr != NULL)
    {
      // cases 2 or 3
      push_nodestack(pathExpr);
      push_nodestack(fnroot);

      theNodeSortStack.top().theNumSteps++;
    }
    else
    {
      // case 1
      expr* result = CREATE(treat)(theRootSctx,
                                   theUDF,
                                   loc,
                                   fnroot,
                                   GENV_TYPESYSTEM.DOCUMENT_TYPE_ONE,
                                   TREAT_EXPR);
      push_nodestack(result);
    }
  }
  else
  {
    // case 4
    push_nodestack(pathExpr);
  }

  return no_state;
}


void end_visit(const PathExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr* arg2 = pop_nodestack();
  expr* arg1 = pop_nodestack();

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
    fo_expr* checkExpr =
      theExprManager->create_fo_expr(theRootSctx, theUDF,
                  arg2->get_loc(),
                  BUILTIN_FUNC(OP_EITHER_NODES_OR_ATOMICS_1),
                  arg2);

    push_nodestack(checkExpr);
  }
#else
  // wrap in atomics_or_node_distinc_sort_asc
  push_nodestack(wrap_in_dos_and_dupelim(arg2, true));
#endif

  theNodeSortStack.pop();
}


/*******************************************************************************

  RelativePathExpr ::= StepExpr (("/" | "//") StepExpr)*

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
  expr* e = pop_nodestack();
  relpath_expr* pathExpr = dynamic_cast<relpath_expr*>(e);
  ZORBA_ASSERT(pathExpr != NULL);

  // If case 4 and i = 1, then pathExpr is empty.
  if (pathExpr->size() == 0)
  {
    // If the path expr is of the form "axis::test/...." or "axis::test[pred]/...."
    // then the input expr to the this path expr is "treat . as node()"
    if (axisStep != NULL)
    {
      expr* sourceExpr = theExprManager->create_treat_expr(theRootSctx, theUDF,
                                         loc,
                                         DOT_REF,
                                         GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
                                         TREAT_PATH_DOT);
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
        flwor_expr* flworExpr = wrap_expr_in_flwor(pathExpr, false);
        push_nodestack(flworExpr);
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
    expr* inputExpr = wrap_in_dos_and_dupelim(pathExpr, true);
    flwor_expr* flworExpr = wrap_expr_in_flwor(inputExpr, false);
    push_nodestack(flworExpr);
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
  expr* stepExpr = pop_nodestack();
  expr* curExpr = pop_nodestack();
  relpath_expr* pathExpr = dynamic_cast<relpath_expr*>(curExpr);
  flwor_expr* flworExpr = dynamic_cast<flwor_expr*>(curExpr);

  // If curExpr is a path expr, step-i was an axis step with no predicates, or
  // the path expr is of the form "source_expr/...." and i = 1.
  if (pathExpr != NULL)
  {
    axis_step_expr* axisExpr = dynamic_cast<axis_step_expr*>(stepExpr);
    ZORBA_ASSERT(axisExpr != NULL || pathExpr->size() == 0);

#ifdef NODE_SORT_OPT
    if (pathExpr->size() == 0)
    {
      TreatErrorKind errKind = TREAT_PATH_STEP;

      if (stepExpr->get_expr_kind() == wrapper_expr_kind)
      {
        var_expr* dotVar = lookup_var(DOT_VARNAME, loc, false);
        if (static_cast<wrapper_expr*>(stepExpr)->get_input() == dotVar)
          errKind = TREAT_PATH_DOT;
      }

      expr* sourceExpr = theExprManager->create_treat_expr(theRootSctx, theUDF,
                                         stepExpr->get_loc(),
                                         stepExpr,
                                         GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
                                         errKind);

      if (sourceExpr->get_return_type()->max_card() > 1)
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

    pathExpr = theExprManager->create_relpath_expr(theRootSctx, theUDF, loc);

    expr* sourceExpr = flworExpr;

    // If step-i was a reverse axis with predicates, we must reorder the
    // result of flworExpr because it is going to be produced in reverse
    // doc order.
    AxisStep* axisStep = dynamic_cast<AxisStep*>(rpe.get_step_expr());

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
    axis_step_expr* ase = theExprManager->create_axis_step_expr(theRootSctx, theUDF, loc);
    match_expr* me = theExprManager->create_match_expr(theRootSctx, theUDF, loc);
    me->setTestKind(match_anykind_test);
    ase->setAxis(axis_kind_descendant_or_self);
    ase->setTest(me);
    pathExpr->add_back(ase);

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
    expr* inputSeqExpr = wrap_in_dos_and_dupelim(pathExpr, false);
    flwor_expr* flworExpr = wrap_expr_in_flwor(inputSeqExpr, (axisStep == NULL));
    push_nodestack(flworExpr);
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
  expr* stepExpr = pop_nodestack();
  expr* curExpr = pop_nodestack();

  axis_step_expr* axisExpr = dynamic_cast<axis_step_expr*>(stepExpr);
  relpath_expr* pathExpr = dynamic_cast<relpath_expr*>(curExpr);
  flwor_expr* flworExpr = dynamic_cast<flwor_expr*>(curExpr);

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

  axis_step_expr* ase = theExprManager->create_axis_step_expr(theRootSctx, theUDF, loc);
  push_nodestack(ase);

  theNodeSortStack.top().theNumSteps++;

  return no_state;
}


/*******************************************************************************
  This method is called from AxisStep::accept() after the step itself is
  translated, but before the associated predicate list (if any) is translated.
********************************************************************************/
void post_axis_visit(const AxisStep& v, void* /*visit_state*/)
{
  expr* e = pop_nodestack();
  axis_step_expr* axisExpr = dynamic_cast<axis_step_expr*>(e);
  ZORBA_ASSERT(axisExpr != NULL);
  axis_kind_t axisKind = axisExpr->getAxis();

  if (axisKind != axis_kind_child)
    theNodeSortStack.top().theOnlyChildAxes = false;

  PredicateList* pl = v.get_predicate_list();

  // Nothing to do if there are no predicates
  if (pl == NULL || pl->size() == 0)
  {
    push_nodestack(e);
    return;
  }

  const QueryLoc& loc = v.get_location();

  e = pop_nodestack();
  flwor_expr* flworExpr = dynamic_cast<flwor_expr*>(e);
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
  const for_clause* fcOuterDot = static_cast<const for_clause*>(flworExpr->get_clause(0));
  relpath_expr* predPathExpr = theExprManager->create_relpath_expr(theRootSctx, theUDF, loc);
  predPathExpr->add_back(theExprManager->create_wrapper_expr(theRootSctx, theUDF, loc, fcOuterDot->get_var()));
  predPathExpr->add_back(axisExpr);

  expr* predInputExpr = predPathExpr;

  if (axisExpr->is_reverse_axis())
  {
    axisExpr->set_reverse_order();
  }

  let_clause* lcPredInput = wrap_in_letclause(predInputExpr);

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

  axis_step_expr* ase = expect_axis_step_top();

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

  axis_step_expr* ase = expect_axis_step_top ();

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

  axis_step_expr* ase = expect_axis_step_top ();

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

  expr* top = theNodeStack.top();

  axis_step_expr* axisExpr = NULL;
  trycatch_expr* tce = NULL;

  if ((axisExpr = dynamic_cast<axis_step_expr *>(top)) != NULL)
  {
    // Construct name-test match expr
    match_expr* matchExpr = theExprManager->create_match_expr(theRootSctx, theUDF, loc);
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
      case ParseConstants::wild_elem: // pre:*
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
      case ParseConstants::wild_prefix: // *:name
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
    catch_clause* cc = const_cast<catch_clause*>((*tce)[0]);
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
        case ParseConstants::wild_elem:
        {
          // bugfix #3138633; expand the qname and use the namespace instead of the prefix
          zstring localname(":wildcard");

          if (wildcard->isEQnameMatch())
          {
            cc->add_nametest_h(new NodeNameTest(wildcard->getNsOrPrefix(), zstring()));
          }
          else
          {
            store::Item_t qnItem;
            theSctx->expand_qname(qnItem,
                                  theSctx->default_elem_type_ns(),
                                  wildcard->getNsOrPrefix(),
                                  localname,
                                  wildcard->get_location());
            cc->add_nametest_h(new NodeNameTest(qnItem->getNamespace(), zstring()));
          }
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

  PredicateList* pl = v.get_pred_list();

  ZORBA_ASSERT(pl != NULL && pl->size() > 0);

  expr* primaryExpr = pop_nodestack();
  expr* e = pop_nodestack();
  flwor_expr* flworExpr = dynamic_cast<flwor_expr*>(e);

  // If this filter expr is not the 1st step of a path expr, ...
  if (flworExpr != NULL)
  {
    // for each item in the input seq compute the input seq for the pred
    // (= outer_dot/primaryExpr)
    let_clause* lcPredSeq = wrap_in_letclause(primaryExpr);

    flworExpr->add_clause(lcPredSeq);

    push_nodestack(flworExpr);
    push_nodestack(lcPredSeq->get_var());
  }

  // Else, this filter expr is the very first step (i.e., the source expr) of
  // a path expr.
  else
  {
     relpath_expr* pathExpr = dynamic_cast<relpath_expr*>(e);
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
  // This method is called from PredicateList::accept(). It is called once
  // for each predicate in the list, before calling accept() on the predicate
  // expression itself.


  // get the predicate input seq
  expr* inputSeqExpr = pop_nodestack();

  //  let $$temp := predInputSeq
  //  let $$last-idx := count($$temp)
  //  for $$dot at $$pos in $$temp
  flwor_expr* flworExpr = wrap_expr_in_flwor(inputSeqExpr, true);

  push_nodestack(flworExpr);
}


void post_predicate_visit(const PredicateList& v, void* /*visit_state*/)
{
  // This method is called from PredicateList::accept(). It is called once
  // for each predicate in the list, after calling accept() on the predicate
  // expression itself.

  RootTypeManager& rtm = GENV_TYPESYSTEM;
  TypeManager* tm = CTX_TM;

  expr* predExpr = pop_nodestack();

  expr* f = pop_nodestack();
  flwor_expr* flworExpr = dynamic_cast<flwor_expr*>(f);
  ZORBA_ASSERT(flworExpr != NULL && flworExpr->num_clauses() == 3);

  const QueryLoc& loc = predExpr->get_loc();

  xqtref_t predType = predExpr->get_return_type();

  if (TypeOps::is_subtype(tm, *predType, *rtm.INTEGER_TYPE_QUESTION, loc))
  {
    flwor_clause* clause = flworExpr->get_clause(0);
    ZORBA_ASSERT(clause->get_kind() == flwor_clause::let_clause);
    let_clause* sourceClause = static_cast<let_clause*>(clause);

    clause = flworExpr->get_clause(1);
    ZORBA_ASSERT(clause->get_kind() == flwor_clause::let_clause);
    let_clause* sizeClause = static_cast<let_clause*>(clause);

    clause = flworExpr->get_clause(2);
    ZORBA_ASSERT(clause->get_kind() == flwor_clause::for_clause);
    for_clause* dotClause = static_cast<for_clause*>(clause);

    var_expr* sizeVar = sizeClause->get_var();
    var_expr* posVar = dotClause->get_pos_var();
    var_expr* dotVar = dotClause->get_var();

    if (expr_tools::count_variable_uses(predExpr, posVar, 1, NULL) == 0 &&
        expr_tools::count_variable_uses(predExpr, dotVar, 1, NULL) == 0)
    {
      flworExpr->remove_clause(2);

      if (expr_tools::count_variable_uses(predExpr, sizeVar, 1, NULL) == 0)
      {
        expr* sourceExpr = sourceClause->get_expr();

        fo_expr* pointExpr = theExprManager->
        create_fo_expr(sourceExpr->get_sctx(),
                       theUDF,
                       sourceExpr->get_loc(),
                       BUILTIN_FUNC(OP_ZORBA_SEQUENCE_POINT_ACCESS_2),
                       sourceExpr,
                       predExpr);

        push_nodestack(pointExpr);
      }
      else
      {
        expr* sourceExpr = sourceClause->get_var();

        fo_expr* pointExpr = theExprManager->
        create_fo_expr(sourceExpr->get_sctx(),
                       theUDF,
                       sourceExpr->get_loc(),
                       BUILTIN_FUNC(OP_ZORBA_SEQUENCE_POINT_ACCESS_2),
                       sourceExpr,
                       predExpr);

        flworExpr->set_return_expr(pointExpr);

        push_nodestack(flworExpr);
      }
    }
    else
    {
      // let $predVar := predExpr
      let_clause* lcPred = wrap_in_letclause(predExpr);
      var_expr* predvar = lcPred->get_var();

      flworExpr->add_clause(lcPred);

      // return if ($$dot eq $$predVar) then $$dot else ()
      fo_expr* eqExpr = theExprManager->
      create_fo_expr(theRootSctx,
                     theUDF,
                     loc,
                     BUILTIN_FUNC(OP_VALUE_EQUAL_2),
                     lookup_ctx_var(DOT_POS_VARNAME, loc),
                     predvar);

      normalize_fo(eqExpr);

      expr* retExpr = theExprManager->
      create_if_expr(theRootSctx, theUDF, loc, eqExpr, DOT_REF, create_empty_seq(loc));

      flworExpr->set_return_expr(retExpr);

      push_nodestack(flworExpr);
    }

    pop_scope();

    return;
  }

  // let $predVar := predExpr
  let_clause* lcPred = wrap_in_letclause(predExpr);
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
  fo_expr* condExpr = NULL;
  std::vector<expr*> condOperands(3);

  condOperands[0] = 
  CREATE(instanceof)(theRootSctx, theUDF, loc, predvar, rtm.DECIMAL_TYPE_QUESTION, true);

  condOperands[1] = 
  CREATE(instanceof)(theRootSctx, theUDF, loc, predvar, rtm.DOUBLE_TYPE_QUESTION, true);

  condOperands[2] =
  CREATE(instanceof)(theRootSctx, theUDF, loc, predvar, rtm.FLOAT_TYPE_QUESTION, true);

  condExpr = 
  CREATE(fo)(theRootSctx, theUDF, loc, BUILTIN_FUNC(OP_OR_N), condOperands);

  // If so: return $dot if the value of the pred expr is equal to the value
  // of $dot_pos var, otherwise return the empty seq.
  fo_expr* eqExpr = theExprManager->
  create_fo_expr(theRootSctx,
                 theUDF,
                 loc,
                 BUILTIN_FUNC(OP_VALUE_EQUAL_2),
                 lookup_ctx_var(DOT_POS_VARNAME, loc),
                 predvar);

  normalize_fo(eqExpr);

  expr* thenExpr = theExprManager->
  create_if_expr(theRootSctx, theUDF, loc, eqExpr, DOT_REF, create_empty_seq(loc));

  // Else, return $dot if the the value of the pred expr is true, otherwise
  // return the empty seq.
  expr* elseExpr = theExprManager->
  create_if_expr(theRootSctx, theUDF, loc, predvar, DOT_REF, create_empty_seq(loc));

  // The outer if
  expr* ifExpr = theExprManager->
  create_if_expr(theRootSctx, theUDF, loc, condExpr, thenExpr, elseExpr);

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
    push_nodestack(CREATE(const)(theRootSctx, theUDF, loc, v.get<xs_integer>()));
    break;
  }
  case ParseConstants::num_decimal:
  {
    push_nodestack(CREATE(const)(theRootSctx, theUDF, loc, v.get<xs_decimal>()));
    break;
  }
  case ParseConstants::num_double:
  {
    push_nodestack(CREATE(const)(theRootSctx, theUDF, loc, v.get<xs_double>()));
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

  push_nodestack(theExprManager->create_const_expr(theRootSctx, theUDF, loc, v.get_strval().str()));
}


/*******************************************************************************
********************************************************************************/
void* begin_visit(const BooleanLiteral& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const BooleanLiteral& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  push_nodestack(
      theExprManager->create_const_expr(
        theRootSctx, theUDF, loc, v.get_boolval()));
}

/*******************************************************************************
********************************************************************************/
void* begin_visit(const NullLiteral& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const NullLiteral& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  store::Item_t lNull;
  GENV_ITEMFACTORY->createJSONNull(lNull);
  push_nodestack(
      theExprManager->create_const_expr(
        theRootSctx, theUDF, loc, lNull));
}

/*******************************************************************************
   StringConcatExpr ::= RangeExpr ( "||" RangeExpr )*
*******************************************************************************/
void* begin_visit(const StringConcatExpr& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const StringConcatExpr& v, void* /* visit_state */)
{
  TRACE_VISIT_OUT();
  std::vector<expr*> concat_args;
  expr* right = pop_nodestack();
  expr* left  = pop_nodestack();
  concat_args.push_back(left);

  //If the right leaf is the concat expr,
  //we add directly its leafs to the new concat expr.
  bool rightLeafIsConcatExpr = false;
  if(right->get_expr_kind() == fo_expr_kind)
  {
    fo_expr* lFoExpr = dynamic_cast<fo_expr*>(right);
    if(lFoExpr->get_func() == BUILTIN_FUNC(FN_CONCAT_N))
    {
      rightLeafIsConcatExpr = true;
      csize i = 0;
      for(i = 0; i < lFoExpr->num_args(); ++i)
      {
        concat_args.push_back(lFoExpr->get_arg(i));
      }
    }
  }

  if(!rightLeafIsConcatExpr)
  {
    concat_args.push_back(right);
  }

  expr* concat =
  theExprManager->create_fo_expr(theRootSctx,
                                 theUDF,
                                 loc,
                                 BUILTIN_FUNC(FN_CONCAT_N),
                                 concat_args);
  push_nodestack(concat);
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
    ve = lookup_var(v.get_name(), loc, true);
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

    if (declaredType != NULL && !TypeOps::is_in_scope(tm, *declaredType) &&
        theSctx->xquery_version() == StaticContextConsts::xquery_version_1_0)
    {
      if (declaredType->get_manager() == tm)
      {
        if (theModuleNamespace.empty())
        {
          RAISE_ERROR(err::XPTY0004, loc,
          ERROR_PARAMS(ZED(BadType_23o),
                       *declaredType,
                       ZED(NoTypeInMainModule_4),
                       ve->get_name()->getStringValue()));
        }
        else
        {
          RAISE_ERROR(err::XPTY0004, loc,
          ERROR_PARAMS(ZED(BadType_23o),
                       *declaredType,
                       ZED(NoTypeInModule_45),
                       ve->get_name()->getStringValue(),
                       theModuleNamespace));
        }
      }
      else
      {
        if (theModuleNamespace.empty())
        {
          RAISE_ERROR(err::XQST0036, loc,
          ERROR_PARAMS(ZED(BadType_23o),
                       *declaredType,
                       ZED(NoTypeInMainModule_4),
                       ve->get_name()->getStringValue()));
        }
        else
        {
          RAISE_ERROR(err::XQST0036, loc,
          ERROR_PARAMS(ZED(BadType_23o),
                       *declaredType,
                       ZED(NoTypeInModule_45),
                       ve->get_name()->getStringValue(),
                       theModuleNamespace));
        }
      }
    }

    if (!theCurrentPrologVFDecl.isNull())
    {
      thePrologGraph.addEdge(theCurrentPrologVFDecl, ve);
    }
  }

  push_nodestack(theExprManager->create_wrapper_expr(theRootSctx, theUDF,
                                                     loc,
                                                     ve));
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

  expr* expr = pop_nodestack();

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

  push_nodestack(theExprManager->create_order_expr(theRootSctx, theUDF,
                                loc,
                                doc_ordered,
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

  push_nodestack(theExprManager->create_order_expr(theRootSctx, theUDF,
                                loc,
                                doc_unordered,
                                pop_nodestack()));
}


/*******************************************************************************
  FunctionCall ::= QName "(" ArgList? ")"

  Note: The parser makes sure that ArgList does not contain any place holder.
********************************************************************************/
void* begin_visit(const FunctionCall& v)
{
  TRACE_VISIT();

  rchandle<QName> qname = v.get_fname();

  csize numArgs = 0;
  if (v.get_arg_list() != NULL)
    numArgs = v.get_arg_list()->size();

  function* f = lookup_fn(qname, numArgs, loc);

  // Note : f maybe NULL if it is a constructor of a builtin type
  if (f == NULL)
  {
    push_nodestack(NULL);
    return no_state;
  }

  if (f->getXQueryVersion() > theSctx->xquery_version())
  {
    zstring version =
    (f->getXQueryVersion() == StaticContextConsts::xquery_version_1_0 ? "1.0" : "3.0");

    RAISE_ERROR(err::XPST0017, loc,
    ERROR_PARAMS(f->getName()->getStringValue(),
                 ZED(FnOnlyInXQueryVersion_3),
                 version));
  }

  if (f->isUdf() && !theCurrentPrologVFDecl.isNull())
  {
    thePrologGraph.addEdge(theCurrentPrologVFDecl, f);
  }

  if (f->isUdf() || f->isExternal())
  {
    TypeManager* tm = CTX_TM;

    const signature& sign = f->getSignature();

    xqtref_t retType = sign.returnType();

    if (!TypeOps::is_in_scope(tm, *retType) &&
        theSctx->xquery_version() == StaticContextConsts::xquery_version_1_0)
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

    csize numParams = f->getArity();

    for (csize i = 0; i < numParams; ++i)
    {
      xqtref_t type = sign[i];

      if (!TypeOps::is_in_scope(tm, *type) &&
          theSctx->xquery_version() == StaticContextConsts::xquery_version_1_0)
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

  // Collect the arguments of this function in reverse order
  std::vector<expr*> arguments;

  while (true)
  {
    expr* argExpr = pop_nodestack();

    if (argExpr == NULL)
      break;

    arguments.push_back(argExpr);
  }

  csize numArgs = arguments.size();

  // Lookup the function
  store::Item_t qnameItem;
  const QName* qname = v.get_fname();

  function* f = lookup_fn(qname, numArgs, loc);

  expr* resultExpr = generate_fncall(qname, f, arguments, loc);
  
  push_nodestack(resultExpr);
}


/*******************************************************************************
  The function will process a FunctionDecl to handle all the special function
  cases. 
********************************************************************************/
expr* generate_fncall(
    const QName* qname,
    function* f,
    std::vector<expr*>& arguments,
    const QueryLoc& loc)
{
  TypeManager* tm = CTX_TM;

  expr* resultExpr = NULL;

  store::Item_t qnameItem;
  zstring fn_ns;
  
  csize numArgs = arguments.size();

  if (f == NULL)
  {
    // Check if this is a call to a type constructor function; if not raise error
    expand_type_qname(qnameItem, qname, loc);

    xqtref_t type = 
    tm->create_named_type(qnameItem, TypeConstants::QUANT_QUESTION, loc);

    if (type != NULL)
    {
      if (numArgs != 1 ||
          TypeOps::is_equal(tm, *type, *theRTM.NOTATION_TYPE_QUESTION, loc) ||
          TypeOps::is_equal(tm, *type, *theRTM.ANY_ATOMIC_TYPE_QUESTION, loc))
      {
        RAISE_ERROR(err::XPST0017, loc,
        ERROR_PARAMS(qnameItem->getStringValue(), ZED(FunctionUndeclared_3), numArgs));
      }

      return create_cast_expr(loc, arguments[0], type, true, true);
    }

    if (theHaveModuleImportCycle)
    {
      fn_ns = qnameItem->getNamespace();

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
    ERROR_PARAMS(qnameItem->getStringValue(), ZED(FunctionUndeclared_3), numArgs));
  }

  qnameItem = f->getName();
  fn_ns = qnameItem->getNamespace();

  if (static_context::is_reserved_module(fn_ns))
  {
    RAISE_ERROR(zerr::ZXQP0016_RESERVED_MODULE_TARGET_NAMESPACE, loc,
    ERROR_PARAMS(fn_ns));
  }

  // Add context-item for functions with zero arguments which implicitly
  // take the context-item as argument
  if (xquery_fns_def_dot.test(f->getKind())) 
  {
    arguments.push_back(DOT_REF);
    f = theSctx->lookup_fn(qnameItem, 1, loc);
  }

  // Check if it is a zorba builtin function, and if so,
  // make sure that the module it belongs to has been imported.
  if (f->isBuiltin() &&
      fn_ns != static_context::W3C_FN_NS &&
#ifdef ZORBA_WITH_JSON
      fn_ns != static_context::JSONIQ_FN_NS &&
#endif
      fn_ns != XQUERY_MATH_FN_NS &&
      fn_ns != theModuleNamespace)
  {
    if (! theSctx->is_imported_builtin_module(fn_ns))
    {
      RAISE_ERROR(err::XPST0017, loc,
      ERROR_PARAMS(qnameItem->getStringValue(), ZED(FunctionUndeclared_3), numArgs));
    }
  }

  // Special processing for certain builtin functions
  switch (f->getKind())
  {
  case FunctionConsts::FN_HEAD_1:
  case FunctionConsts::FN_TAIL_1:
  case FunctionConsts::FN_NUMBER_1:
  case FunctionConsts::FN_POSITION_0:
  case FunctionConsts::FN_LAST_0:
  case FunctionConsts::FN_STATIC_BASE_URI_0:
  case FunctionConsts::FN_APPLY_1:
  {
    resultExpr = generate_fn_body(f, arguments, loc);
    break;
  }
  case FunctionConsts::FN_IDREF_1:
  {
    arguments.insert(arguments.begin(), DOT_REF);
    f = BUILTIN_FUNC(FN_IDREF_2);
    break;
  }
  case FunctionConsts::FN_LANG_1:
  {
    arguments.insert(arguments.begin(), DOT_REF);
    f = BUILTIN_FUNC(FN_LANG_2);
    break;
  }
  case FunctionConsts::FN_RESOLVE_URI_1:
  {
    zstring baseUri = theSctx->get_base_uri();
    arguments.insert(arguments.begin(),
                     CREATE(const)(theRootSctx, theUDF, loc, baseUri));
    f = BUILTIN_FUNC(FN_RESOLVE_URI_2);
    break;
  }
  case FunctionConsts::FN_SUBSEQUENCE_2:
  case FunctionConsts::FN_SUBSEQUENCE_3:
  case FunctionConsts::FN_SUBSTRING_2:
  case FunctionConsts::FN_SUBSTRING_3:
  {
    if (numArgs == 2)
    {
      xqtref_t posType = arguments[0]->get_return_type();

      if (TypeOps::is_subtype(tm, *posType, *theRTM.INTEGER_TYPE_STAR, loc))
      {
        if (f->getKind() == FunctionConsts::FN_SUBSTRING_2)
          f = BUILTIN_FUNC(OP_SUBSTRING_INT_2);
        else
          f = BUILTIN_FUNC(OP_ZORBA_SUBSEQUENCE_INT_2);
      }
    }
    else
    {
      xqtref_t posType = arguments[1]->get_return_type();
      xqtref_t lenType = arguments[0]->get_return_type();

      if (TypeOps::is_subtype(tm, *posType, *theRTM.INTEGER_TYPE_STAR, loc) &&
          TypeOps::is_subtype(tm, *lenType, *theRTM.INTEGER_TYPE_STAR, loc))
      {
        if (f->getKind() == FunctionConsts::FN_SUBSTRING_3)
          f = BUILTIN_FUNC(OP_SUBSTRING_INT_3);
        else
          f = BUILTIN_FUNC(OP_ZORBA_SUBSEQUENCE_INT_3);
      }
    }

    break;
  }
  case FunctionConsts::FN_ID_1:
  case FunctionConsts::FN_ID_2:
  case FunctionConsts::FN_ELEMENT_WITH_ID_1:
  case FunctionConsts::FN_ELEMENT_WITH_ID_2:
  {
    if (numArgs == 1)
    {
      arguments.insert(arguments.begin(), DOT_REF);
      f = theSctx->lookup_fn(qnameItem, 2, loc);
    }

    expr* idsExpr = arguments[1];

    flwor_expr* flworExpr = wrap_expr_in_flwor(idsExpr, false);

    const for_clause* fc = static_cast<const for_clause*>(flworExpr->get_clause(0));
    expr* flworVarExpr = fc->get_var();

    fo_expr* normExpr = NULL;
    fo_expr* tokenExpr = NULL;
    zstring space(" ");
    const_expr* constExpr = CREATE(const)(theRootSctx, theUDF, loc, space);
    
    normExpr = CREATE(fo)(theRootSctx, theUDF, loc,
                          BUILTIN_FUNC(FN_NORMALIZE_SPACE_1),
                          flworVarExpr);
    normalize_fo(normExpr);

    tokenExpr = CREATE(fo)(theRootSctx, theUDF, loc,
                           BUILTIN_FUNC(FN_TOKENIZE_2),
                           normExpr,
                           constExpr);
    normalize_fo(tokenExpr);

    flworExpr->set_return_expr(tokenExpr);

    pop_scope();
 
    arguments[1] = flworExpr;
    break;
  }
  case FunctionConsts::FN_FOLD_RIGHT_3:
  {
    // Because arguments are reversed, the 3rd argument is actually arguments[0]
    arguments[0] = CREATE(fo)(theRootSctx, theUDF, loc,
                              BUILTIN_FUNC(FN_REVERSE_1),
                              arguments[0]);
    break;
  }
  case FunctionConsts::FN_CONCAT_N:
  {
    if (numArgs < 2)
    {
      RAISE_ERROR(err::XPST0017, loc,
      ERROR_PARAMS("concat", ZED(FunctionUndeclared_3), numArgs));
    }
    break;
  }
  case FunctionConsts::FN_DOC_1:
  {
    expr*  doc_uri = arguments[0];

    //validate uri
    if (doc_uri->get_expr_kind() == const_expr_kind)
    {
      const_expr* const_uri = reinterpret_cast<const_expr*>(doc_uri);
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
    break;
  }
  default: 
  {
  }
  }

  if (resultExpr)
  {
    f->processPragma(resultExpr, theScopedPragmas);
    return resultExpr;
  }

  numArgs = arguments.size();  // recompute size

  // If this is a udf that is invoked from another udf, mark that other udf
  // as a non-leaf function.
  if (f->isUdf())
  {
    if (inUDFBody())
    {
      function* f1 = const_cast<function*>(theCurrentPrologVFDecl.getFunction());
      assert(f1->isUdf());
      user_function* udf = static_cast<user_function*>(f1);
      udf->setLeaf(false);
    }
  }

  // Create and normalize the fo expr
  std::reverse(arguments.begin(), arguments.end());

  fo_expr* foExpr = CREATE(fo)(theRootSctx, theUDF, loc, f, arguments);
  normalize_fo(foExpr);

  resultExpr = foExpr;

  if (f->isExternal())
  {
    const xqtref_t& resType = f->getSignature().returnType();

    resultExpr = 
    wrap_in_type_match(foExpr, resType, loc, TREAT_FUNC_RETURN, f->getName());
  }

  // Some further normalization is required for certain builtin functions
  FunctionConsts::FunctionKind fKind = f->getKind();
  switch (fKind)
  {
  case FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_POINT_GENERAL_N:
  case FunctionConsts::FN_ZORBA_XQDDF_PROBE_INDEX_RANGE_GENERAL_N:
  {
    resultExpr = CREATE(fo)(theRootSctx, theUDF, foExpr->get_loc(),
                            BUILTIN_FUNC(OP_SORT_DISTINCT_NODES_ASC_1),
                            foExpr);
        
    break;
  }
  case FunctionConsts::FN_ANALYZE_STRING_2:
  case FunctionConsts::FN_ANALYZE_STRING_3:
  {
    resultExpr =
    wrap_in_validate_expr_strict(foExpr, "http://www.w3.org/2005/xpath-functions");

    break;
  }
  case FunctionConsts::FN_SERIALIZE_2:
  {
    import_schema_auto_prefix(loc,
                              "http://www.w3.org/2010/xslt-xquery-serialization",
                              NULL);

    break;
  }
  case FunctionConsts::FN_MAP_2:
  case FunctionConsts::FN_FILTER_2:
  {
    std::vector<expr*> args(foExpr->get_args());
    resultExpr = generate_fn_body(f, args, loc);
    break;
  }
  case FunctionConsts::FN_ZORBA_EVAL_1:
  case FunctionConsts::FN_ZORBA_EVAL_N_1:
  case FunctionConsts::FN_ZORBA_EVAL_U_1:
  case FunctionConsts::FN_ZORBA_EVAL_S_1:
  {
    expr_script_kind_t scriptKind;

    if (fKind == FunctionConsts::FN_ZORBA_EVAL_1 ||
        fKind == FunctionConsts::FN_ZORBA_EVAL_N_1)
    {
      scriptKind = SIMPLE_EXPR;
    }
    else if (fKind == FunctionConsts::FN_ZORBA_EVAL_U_1)
    {
      scriptKind = UPDATING_EXPR;
    }
    else
    {
      scriptKind = SEQUENTIAL_FUNC_EXPR;
    }
    
    eval_expr* evalExpr = 
    CREATE(eval)(theRootSctx, theUDF, loc, foExpr->get_arg(0), scriptKind, theNSCtx);

    std::vector<VarInfo*> inscopeVars;
    theSctx->getVariables(inscopeVars);
    
    csize numVars = inscopeVars.size();
    
    for (csize i = 0; i < numVars; ++i)
    {
      evalExpr->add_var(inscopeVars[i]->getVar());
    }
    
    resultExpr = evalExpr;
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
      let $query := concat("Q{",
                           string(namespace-uri-from-QName(temp_invoke_var1)),
                           "}",
                           string(local-name-from-QName(temp_invoke_var1)),
                           "($temp_invoke_var2, ..., $temp_invoke_varN+1)")
      return eval { $query }
    */
    
    expr_script_kind_t scriptingKind = SIMPLE_EXPR; // avoid warning
    zstring query_params;
    std::vector<var_expr*> temp_vars;

    if (fKind == FunctionConsts::FN_ZORBA_INVOKE_N ||
        fKind == FunctionConsts::FN_ZORBA_INVOKE_N_N)
    {
      scriptingKind = SIMPLE_EXPR;
    }
    else if (fKind == FunctionConsts::FN_ZORBA_INVOKE_U_N)
    {
      scriptingKind = UPDATING_EXPR;
    }
    else if (fKind == FunctionConsts::FN_ZORBA_INVOKE_S_N)
    {
      scriptingKind = SEQUENTIAL_FUNC_EXPR;
    }

    if (numArgs == 0)
    {
      RAISE_ERROR(err::XPST0017, loc,
       ERROR_PARAMS("invoke", ZED(FunctionUndeclared_3), numArgs));
    }

    // create a flwor with LETs to hold the parameters
    flwor_expr* flworExpr = CREATE(flwor)(theRootSctx, theUDF, loc, false);
    
    // wrap function's QName
    expr* qnameExpr = wrap_in_type_promotion(arguments[0],
                                             theRTM.QNAME_TYPE_ONE,
                                             PROMOTE_TYPE_PROMOTION);
    
    for (csize i = 0; i < numArgs ; ++i)
    {
      let_clause* lc;
      store::Item_t qnameItem;
      
      // cannot use create_temp_var() as the variables created there are not
      // accessible. use a special name but check for name clashes
      do
      {
        std::string localName = "temp_invoke_var" +
                                ztd::to_string(theTempVarCounter++);
        GENV_ITEMFACTORY->createQName(qnameItem, "", "", localName.c_str());
      }
      while (lookup_var(qnameItem, loc, false) != NULL);

      var_expr* var = create_var(loc, qnameItem, var_expr::let_var);
      temp_vars.push_back(var);
      
      if (i == 0)
        lc = wrap_in_letclause(qnameExpr, var);
      else
        lc = wrap_in_letclause(arguments[i], var);

      flworExpr->add_clause(lc);

      // add the parameters to the eval's query string
      if (i > 1)
        query_params += ",";
      if (i > 0)
        query_params += "$" + var->get_name()->getStringValue();
    }

    query_params = "(" + query_params + ")";

    // Expanded QName's namespace URI
    expr* namespaceExpr = CREATE(fo)(theRootSctx, theUDF, loc,
                                     BUILTIN_FUNC(FN_NAMESPACE_URI_FROM_QNAME_1),
                                     temp_vars[0]);

    namespaceExpr = CREATE(fo)(theRootSctx, theUDF, loc,
                               BUILTIN_FUNC(FN_STRING_1),
                               namespaceExpr);
    
    // Expanded QName's local name
    expr* localExpr = CREATE(fo)(theRootSctx, theUDF, loc,
                                 BUILTIN_FUNC(FN_LOCAL_NAME_FROM_QNAME_1),
                                 temp_vars[0]);

    localExpr = CREATE(fo)(theRootSctx, theUDF, loc,
                           BUILTIN_FUNC(FN_STRING_1),
                           localExpr);

    // qnameExpr := concat("Q{",
    //                     namespaceExpr,
    //                     "}",
    //                     localExpr,
    //                     "($temp_invoke_var2, $temp_invoke_var3,...)")
    std::vector<expr*> concat_args;
    concat_args.push_back(CREATE(const)(theRootSctx, theUDF, loc, "Q{"));
    concat_args.push_back(namespaceExpr);
    concat_args.push_back(CREATE(const)(theRootSctx, theUDF, loc, "}"));
    concat_args.push_back(localExpr);
    concat_args.push_back(CREATE(const)(theRootSctx, theUDF, loc, query_params));
    
    qnameExpr = CREATE(fo)(theRootSctx, theUDF, loc,
                           BUILTIN_FUNC(FN_CONCAT_N),
                           concat_args);

    eval_expr* evalExpr = CREATE(eval)(theRootSctx, theUDF, loc,
                                       qnameExpr,
                                       scriptingKind,
                                       theNSCtx);

    flworExpr->set_return_expr(evalExpr);
    resultExpr = flworExpr;

    for (csize i = 0; i < temp_vars.size(); ++i)
    {
      evalExpr->add_var(temp_vars[i]);
    }
    
    break;
  }
  default:
  {
  }
  }
  
  f->processPragma(resultExpr, theScopedPragmas);

  return resultExpr;

}


/******************************************************************************
  Will generate the body of a function that does not have an associated 
  iterator and is created in the translator using expressions. Such functions
  are e.g. fn:map(), fn:filter() and others.
*******************************************************************************/
expr* generate_fn_body(
    function* f,
    std::vector<expr*>& arguments,
    const QueryLoc& loc)
{
  expr* resultExpr = NULL;
  
  switch (f->getKind())
  {
  case FunctionConsts::FN_POSITION_0:
  {
    resultExpr = lookup_ctx_var(DOT_POS_VARNAME, loc);
    break;
  }
  case FunctionConsts::FN_LAST_0:
  {
    resultExpr = lookup_ctx_var(LAST_IDX_VARNAME, loc);
    break;
  }
  case FunctionConsts::FN_HEAD_1:
  {
    arguments.push_back(CREATE(const)(theRootSctx, theUDF, loc, xs_integer::one()));
    arguments.push_back(CREATE(const)(theRootSctx, theUDF, loc, xs_integer::one()));

    function* f = BUILTIN_FUNC(OP_ZORBA_SUBSEQUENCE_INT_3);

    fo_expr* foExpr = CREATE(fo)(theRootSctx, theUDF, loc, f, arguments);
    normalize_fo(foExpr);

    resultExpr = foExpr;
    break;
  }
  case FunctionConsts::FN_TAIL_1:
  {
    arguments.push_back(CREATE(const)(theRootSctx, theUDF, loc, xs_integer(2)));

    function* f = BUILTIN_FUNC(OP_ZORBA_SUBSEQUENCE_INT_2);

    fo_expr* foExpr = CREATE(fo)(theRootSctx, theUDF, loc, f, arguments);
    normalize_fo(foExpr);
    
    resultExpr = foExpr;
    break;
  }
  case FunctionConsts::FN_NUMBER_1:
  {
    var_expr* tv = create_temp_var(loc, var_expr::let_var);

    expr* nanExpr = CREATE(const)(theRootSctx, theUDF, loc, xs_double::nan());

    expr* condExpr = CREATE(castable)(theRootSctx, theUDF, loc,
                                      tv,
                                      theRTM.DOUBLE_TYPE_ONE,
                                      false);

    expr* castExpr = create_cast_expr(loc, tv, theRTM.DOUBLE_TYPE_ONE, false, true);

    expr* ret = CREATE(if)(theRootSctx, theUDF, loc, condExpr, castExpr, nanExpr);

    expr* dataExpr = 
    wrap_in_type_promotion(arguments[0], 
                           theRTM.ANY_ATOMIC_TYPE_QUESTION,
                           PROMOTE_FUNC_PARAM,
                           f->getName());

    resultExpr = wrap_in_let_flwor(dataExpr, tv, ret);
    break;
  }
  case FunctionConsts::FN_STATIC_BASE_URI_0:
  {
    zstring baseuri = theSctx->get_base_uri();
    if (baseuri.empty())
      resultExpr = create_empty_seq(loc);
    else
      resultExpr = CREATE(cast)(theRootSctx, theUDF, loc,
                                CREATE(const)(theRootSctx, theUDF, loc, baseuri),
                                theRTM.ANY_URI_TYPE_ONE, false);
    break;
  }
  case FunctionConsts::FN_MAP_2:
  {
    //  map(function, sequence) is rewritten internally as:
    //
    //  for $item in $sequence
    //  return dynamic_function_invocation[ $function, $item ]
    
    flwor_expr* flwor = CREATE(flwor)(theRootSctx, theUDF, loc, false);
    for_clause* seq_fc = wrap_in_forclause(arguments[1], false);
    flwor->add_clause(seq_fc);
    
    std::vector<expr*> fncall_args;
    fncall_args.push_back(CREATE(wrapper)(theRootSctx, theUDF, loc, seq_fc->get_var()));

    expr* dynamic_fncall = 
    CREATE(dynamic_function_invocation)(theRootSctx, theUDF, loc,
                                        arguments[0],
                                        fncall_args,
                                        NULL);
    
    flwor->set_return_expr(dynamic_fncall);

    resultExpr = flwor;
    break;
  }
  case FunctionConsts::FN_FILTER_2:
  {
    //  filter(function, sequence) is rewritten internally as:
    //
    //  for $item in $sequence
    //  return
    //    if (dynamic_function_invocation[ $function, $item])
    //    then $item
    //    else ()
    
    flwor_expr* flwor = CREATE(flwor)(theRootSctx, theUDF, loc, false);
    for_clause* seq_fc = wrap_in_forclause(arguments[1], true);
    flwor->add_clause(seq_fc);
    
    std::vector<expr*> fncall_args;
    fncall_args.push_back(CREATE(wrapper)(theRootSctx, theUDF, loc, seq_fc->get_var()));
    
    expr* dynamic_fncall =
    CREATE(dynamic_function_invocation)(theRootSctx, theUDF, loc,
                                        arguments[0],
                                        fncall_args,
                                        NULL);

    expr* if_expr = 
    CREATE(if)(theRootSctx, theUDF, loc,
               dynamic_fncall,
               CREATE(wrapper)(theRootSctx, theUDF, loc, seq_fc->get_var()),
               create_empty_seq(loc));
      
    flwor->set_return_expr(if_expr);

    resultExpr = flwor;
    break;
  }
  case FunctionConsts::FN_APPLY_1:
  {
    resultExpr = CREATE(apply)(theRootSctx, theUDF, loc, arguments[0], false);
    break;
  }
  default:
  {
    ZORBA_ASSERT(false);
  }
  } // switch (lKind)
  
  return resultExpr;
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
  ArgumentPlaceholder := "?"
********************************************************************************/
void* begin_visit(const ArgumentPlaceholder& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const ArgumentPlaceholder& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
  push_nodestack(CREATE(argument_placeholder)(theRootSctx, theUDF, loc));
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
  return no_state;
}


void end_visit(const DynamicFunctionInvocation& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  // Collect the arguments of the dynamic function invocation
  csize numArgs = 0;
  std::vector<expr*> arguments;
  if (v.getArgList() != 0)
  {
    numArgs = v.getArgList()->size();
    for (csize i = numArgs; i > 0; --i)
    {
      arguments.push_back(pop_nodestack());
    }

    std::reverse(arguments.begin(), arguments.end());
  }

  // Get the function item expr
  expr* sourceExpr = pop_nodestack();
  ZORBA_ASSERT(sourceExpr != 0);

  if (v.normalizeArgs() && sourceExpr->get_expr_kind() == function_item_expr_kind)
  {
    function_item_expr* fiExpr = static_cast<function_item_expr*>(sourceExpr);
    const function* fn = fiExpr->get_function();

    for (csize i = 0; i < arguments.size(); i++)
    {
      if (arguments[i]->get_expr_kind() != argument_placeholder_expr_kind)
        arguments[i] = normalize_fo_arg(i, arguments[i], fn, loc);
    }
  }

   expr* dotVar = NULL;
   if (lookup_var(getDotVarName(), loc, false))
     dotVar = DOT_REF;

   // Implementing implicit iteration over the sequence returned by the source expr
  flwor_expr* flworExpr = wrap_expr_in_flwor(sourceExpr, false);

  for_clause* fc = reinterpret_cast<for_clause*>(flworExpr->get_clause(0));

  // This is needed to make sure that the flwor is not thrown away by the optimizer
  // when the FunctionItem expression is an empty sequence.
  fc->set_allowing_empty(true); 

  expr* flworVarExpr = CREATE(wrapper)(theRootSctx, theUDF, loc, fc->get_var());

#ifdef ZORBA_WITH_JSON
  TypeManager* tm = sourceExpr->get_type_manager();
  xqtref_t srcType = sourceExpr->get_return_type();

  if (TypeOps::is_subtype(tm, *srcType, *theRTM.JSON_ITEM_TYPE_STAR))
  {
    if (numArgs > 1)
    {
      RAISE_ERROR_NO_PARAMS(jerr::JNTY0018, loc);
    }

    function* func;

    if (TypeOps::is_subtype(tm, *srcType, *theRTM.JSON_ARRAY_TYPE_STAR))
    {
      func = (numArgs == 1 ?
              BUILTIN_FUNC(FN_JSONIQ_MEMBER_2) :
              BUILTIN_FUNC(FN_JSONIQ_MEMBERS_1));
    }
    else if (TypeOps::is_subtype(tm, *srcType, *theRTM.JSON_OBJECT_TYPE_STAR))
    {
      func = (numArgs == 1 ?
              BUILTIN_FUNC(FN_JSONIQ_VALUE_2) :
              BUILTIN_FUNC(FN_JSONIQ_KEYS_1));
    }
    else
    {
      func = (numArgs == 1 ?
              BUILTIN_FUNC(OP_ZORBA_JSON_ITEM_ACCESSOR_2) :
              BUILTIN_FUNC(OP_ZORBA_JSON_ITEM_ACCESSOR_1));
    }

    fo_expr* accessorExpr = 
    (numArgs == 1 ?
     CREATE(fo)(theRootSctx, theUDF, loc, func, flworVarExpr, arguments[0]) :
     CREATE(fo)(theRootSctx, theUDF, loc, func, flworVarExpr));

    normalize_fo(accessorExpr);

    flworExpr->set_return_expr(accessorExpr);
  }
  else
#endif
  {
    expr* dynFuncInvocation =
    CREATE(dynamic_function_invocation)(theRootSctx, theUDF, loc,
                                        flworVarExpr,
                                        arguments,
                                        dotVar);

    flworExpr->set_return_expr(dynFuncInvocation);
  }

  pop_scope();

  push_nodestack(flworExpr);
}


/*******************************************************************************
  LiteralFunctionItem ::= QName "#" IntegerLiteral
********************************************************************************/
void* begin_visit(const LiteralFunctionItem& v)
{
  TRACE_VISIT();
  return no_state;
}


void end_visit(const LiteralFunctionItem& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  rchandle<QName> qname = v.getQName();
  uint32_t arity = 0;
  store::Item_t qnameItem;

  try
  {
    arity = to_xs_unsignedInt(v.getArity());
  }
  catch ( std::range_error const& )
  {
    RAISE_ERROR(err::XPST0017, loc,
    ERROR_PARAMS(v.getArity(), ZED(NoParseFnArity)));
  }

  expand_function_qname(qnameItem, qname, loc);

  expr* fiExpr = generate_literal_function(qnameItem, arity, loc, false);

  push_nodestack(fiExpr);
}


/*******************************************************************************

********************************************************************************/
expr* generate_literal_function(
    store::Item_t& qnameItem,
    csize arity,
    const QueryLoc& loc,
    bool errIfContextDependent)
{
  xqtref_t type;
  user_function* udf = NULL;
  bool needs_context_item = false;
  
  // Get function implementation
  function* f = theSctx->lookup_fn(qnameItem, arity, loc);

  // Raise XPST0017 if function could not be found, unless it is a type constructor
  // function
  if (f == NULL)
  {
    type = CTX_TM->create_named_type(qnameItem,
                                     TypeConstants::QUANT_QUESTION,
                                     loc);

    if (type == NULL ||
        arity != 1 ||
        TypeOps::is_equal(CTX_TM, *type, *GENV_TYPESYSTEM.NOTATION_TYPE_QUESTION, loc) ||
        TypeOps::is_equal(CTX_TM, *type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION, loc))
    {
      RAISE_ERROR(err::XPST0017, loc,
      ERROR_PARAMS(qnameItem->getStringValue(), ZED(FunctionUndeclared_3), arity));
    }

    std::vector<var_expr*> udfArgs(1);
    var_expr* argVar = create_temp_var(loc, var_expr::arg_var);
    argVar->set_param_pos(0);
    udfArgs[0] = argVar;
    expr* body = CREATE(cast)(theRootSctx, udf, loc, argVar, type, false);

    udf = new user_function(loc,
                            signature(qnameItem, theRTM.ITEM_TYPE_QUESTION, type),
                            body,
                            SIMPLE_EXPR,
                            theCCB);

    udf->setArgVars(udfArgs);
    udf->setOptimized(true);
    f = udf;
  }
  else
  {
    // validate the number of parameters on certain functions
    switch (f->getKind())
    {
      case FunctionConsts::FN_CONCAT_N:
      {
        if (arity < 2)
        {
          RAISE_ERROR(err::XPST0017, loc,
          ERROR_PARAMS("concat", ZED(FunctionUndeclared_3), arity));
        }
        break;
      }
      default:
        break;
    }

    //  Check if it is a zorba builtin function, and if so, make sure that
    // the module it belongs to has been imported.
    const zstring& fn_ns = qnameItem->getNamespace();

    if (f->isBuiltin() &&
        fn_ns != static_context::W3C_FN_NS &&
#ifdef ZORBA_WITH_JSON
        fn_ns != static_context::JSONIQ_FN_NS &&
#endif
        fn_ns != XQUERY_MATH_FN_NS &&
        fn_ns != theModuleNamespace)
    {
      if (! theSctx->is_imported_builtin_module(fn_ns))
      {
        RAISE_ERROR(err::XPST0017, loc,
        ERROR_PARAMS(qnameItem->getStringValue(), ZED(FunctionUndeclared_3), arity));
      }
    }

    // If it is a builtin function F with signature (R, T1, ..., TN) , wrap it
    // in a udf UF: function UF(x1 as T1, ..., xN as TN) as R { F(x1, ... xN) }
    if (!f->isUdf())
    {
      FunctionConsts::FunctionKind fKind = f->getKind();

      // Add context-item for functions with zero arguments which implicitly
      // take the context-item as argument
      if (xquery_fns_def_dot.test(fKind) || 
          fKind == FunctionConsts::FN_LANG_1 || 
          fKind == FunctionConsts::FN_ID_1 ||
          fKind == FunctionConsts::FN_ELEMENT_WITH_ID_1 ||
          fKind == FunctionConsts::FN_IDREF_1)
      {
        arity++;
        f = theSctx->lookup_fn(qnameItem, arity, loc);
        needs_context_item = true;
      }

      udf = new user_function(loc,
                              f->getSignature(),
                              NULL, // no body for now
                              f->getScriptingKind(),
                              theCCB);

      std::vector<expr*> foArgs(arity);
      std::vector<var_expr*> udfArgs(arity);

      for (csize i = 0; i < arity; ++i)
      {
        var_expr* argVar = create_temp_var(loc, var_expr::arg_var);
        argVar->set_param_pos(i);
        udfArgs[i] = argVar;
        foArgs[i] = argVar;
      }
      
      expr* body;
      // process pure builtin functions that have no associated iterator
      switch (f->getKind())
      {
      case FunctionConsts::FN_NUMBER_1:
      case FunctionConsts::FN_HEAD_1:
      case FunctionConsts::FN_TAIL_1:
      case FunctionConsts::FN_MAP_2:
      case FunctionConsts::FN_FILTER_2:
      case FunctionConsts::FN_STATIC_BASE_URI_0:
      {
        // create the function flwor, wrap params in for clauses
        flwor_expr* flwor = CREATE(flwor)(theSctx, theUDF, loc, false);
        std::vector<expr*> arguments;
        for (csize i = 0; i < foArgs.size(); i++)
        {          
          let_clause* lc = wrap_in_letclause(&*udfArgs[i]); // FN_HEAD and FN_TAIL need this to be a LET clause
          udfArgs[i]->set_param_pos(flwor->num_clauses());
          flwor->add_clause(lc);
          arguments.push_back(lc->get_var());
        }
        
        flwor->set_return_expr(generate_fn_body(f, arguments, loc));
          
        body = flwor;
          
        if (flwor->num_clauses() == 0)
          body = flwor->get_return_expr();
        
        break;
      }
      case FunctionConsts::FN_RESOLVE_URI_1:
      {
        zstring baseUri = theSctx->get_base_uri();
        foArgs.push_back(CREATE(const)(theRootSctx, theUDF, loc, baseUri));
        f = BUILTIN_FUNC(FN_RESOLVE_URI_2);

        fo_expr* fo = CREATE(fo)(theRootSctx, udf, loc, f, foArgs);
        normalize_fo(fo);

        body = fo;
        break;
      }
      default:
      {
        fo_expr* fo = CREATE(fo)(theRootSctx, udf, loc, f, foArgs);
        normalize_fo(fo);

        body = fo;
        break;
      }
      } // switch 

      udf->setArgVars(udfArgs);
      udf->setBody(body);
      udf->setOptimized(true); // TODO: this is needed because otherwise the optimizer would get into an infinte cycle

      f = udf;
    } // if builtin function
  }

  static_context* closureSctx = theRootSctx->create_child_context();
  theCCB->theSctxMap[theCCB->theSctxMap.size() + 1] = closureSctx;

  expr* fiExpr = CREATE(function_item)(theRootSctx, theUDF, loc,
                                       closureSctx,
                                       f,
                                       f->getName(),
                                       arity,
                                       false,
                                       needs_context_item,
                                       false);

  return fiExpr;
}


/*******************************************************************************
  InlineFunction ::= "function" "(" ParamList? ")"
                     ("as" SequenceType)? EnclosedExpr
********************************************************************************/
void* begin_visit(const InlineFunction& v)
{
  TRACE_VISIT();

  // Get the in-scope vars of the scope before opening the new scope for the
  // function devl
  std::vector<VarInfo*> scopedVars;
  theSctx->getVariables(scopedVars);

  push_scope();

  static_context* closureSctx = theRootSctx->create_child_context();
  theCCB->theSctxMap[theCCB->theSctxMap.size() + 1] = closureSctx;

  function_item_expr* fiExpr =
  CREATE(function_item)(theRootSctx, theUDF, loc, closureSctx, true, false, false);

  push_nodestack(fiExpr);

  // Translate the return tyoe
  xqtref_t returnType = GENV_TYPESYSTEM.ITEM_TYPE_STAR;
  if (v.getReturnType() != 0)
  {
    v.getReturnType()->accept(*this);
    returnType = pop_tstack();
  }

  // Translate the type declarations for the function params
  rchandle<ParamList> params = v.getParamList();
  std::vector<xqtref_t> paramTypes;

  if (params != 0)
  {
    std::vector<rchandle<Param> >::const_iterator lIt = params->begin();
    for(; lIt != params->end(); ++lIt)
    {
      const Param* param = lIt->getp();
      const SequenceType* paramType = param->get_typedecl();
      if (paramType == 0)
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

  flwor_expr* flwor = NULL;

  // Handle function parameters. Translation of the params, if any, results to
  // a flwor expr with one let binding for each function parameter:
  //
  // let $x1 as T1 := _x1
  // .....
  // let $xN as TN := _xN
  //
  // where each _xi is an arg var.
  if (params)
  {
    params->accept(*this);
    flwor = static_cast<flwor_expr*>(pop_nodestack());
  }
  else
  {
    flwor = theExprManager->create_flwor_expr(theRootSctx, theUDF, loc, false);
  }

  // Handle inscope variables. For each inscope var, a let binding is added to
  // the flwor.
  std::vector<VarInfo*>::iterator ite = scopedVars.begin();

  for(; ite != scopedVars.end(); ++ite)
  {
    var_expr* varExpr = (*ite)->getVar();
    var_expr::var_kind kind = varExpr->get_kind();

    if (kind == var_expr::local_var)
    {
      continue;
    }

    store::Item_t qname = varExpr->get_name();

    var_expr* subst_var;
    if (kind != var_expr::prolog_var)
    {
      try 
      {
        subst_var = bind_var(loc, qname, var_expr::hof_var);
      }
      catch(XQueryException& e)
      {
        if (e.diagnostic() == err::XQST0049)
          continue;
        else
          throw;
      }
    }
    else
    {
      subst_var = varExpr;
    }

    if (kind == var_expr::prolog_var)
      fiExpr->add_variable(NULL, subst_var, varExpr->get_name(), 1 /*var is global if it's a prolog var*/);
    else
      fiExpr->add_variable(varExpr, subst_var, varExpr->get_name(), 0);
  }

  if (flwor->num_clauses() > 0)
    push_nodestack(flwor);
  else
    push_nodestack(NULL);

  return no_state;
}


void end_visit(const InlineFunction& v, void* aState)
{
  TRACE_VISIT_OUT();

  // Get the return tyoe
  xqtref_t returnType = GENV_TYPESYSTEM.ITEM_TYPE_STAR;
  if(v.getReturnType() != 0)
  {
    returnType = pop_tstack();
  }

  // Get the inline function body.
  expr* body = pop_nodestack();
  ZORBA_ASSERT(body != 0);

  // Make the body be the return expr of the flwor that binds the function params.
  flwor_expr* flwor = static_cast<flwor_expr*>(pop_nodestack());

  // Translate the type declarations for the function params
  std::vector<xqtref_t> paramTypes;
  rchandle<ParamList> params = v.getParamList();
  if (params != 0)
  {
    std::vector<rchandle<Param> >::const_iterator lIt = params->begin();
    for(; lIt != params->end(); ++lIt)
    {
      const Param* param = lIt->getp();
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
  }

  create_inline_function(body, flwor, paramTypes, returnType, loc, false);

  // pop the scope.
  pop_scope();
}


/*******************************************************************************

********************************************************************************/
void create_inline_function(
    expr* body,
    flwor_expr* flwor,
    const std::vector<xqtref_t>& paramTypes,
    xqtref_t returnType,
    const QueryLoc& loc,
    bool is_coercion)
{
  std::vector<var_expr*> argVars;

  // Wrap the body in appropriate type op.
  if (returnType->isBuiltinAtomicAny())
  {
    body = wrap_in_type_promotion(body, returnType, PROMOTE_TYPE_PROMOTION);
  }
  else
  {
    body = wrap_in_type_match(body, returnType, loc, TREAT_TYPE_MATCH);
  }

  // Create the udf obj.
  user_function_t udf = 
  new user_function(loc,
                    signature(function_item_expr::create_inline_fname(loc),
                              paramTypes,
                              returnType),
                    NULL,
                    SIMPLE_EXPR,
                    theCCB);

  if (flwor != NULL)
  {
    flwor->set_return_expr(body);

    body = flwor;

    // Parameters and inscope vars have been wrapped into a flwor expression (see
    // begin_visit). We need to add these to the udf obj so that they will bound
    // at runtime. We must do this here (before we optimize the inline function
    // body, because optimization may remove clauses from the flwor expr
    for (csize i = 0; i < flwor->num_clauses(); ++i)
    {
      flwor_clause* lClause = flwor->get_clause(i);
      let_clause* letClause = dynamic_cast<let_clause*>(lClause);
      ZORBA_ASSERT(letClause != 0); // can only be a parameter bound using let
      var_expr* argVar = dynamic_cast<var_expr*>(letClause->get_expr());
      argVars.push_back(argVar);
      
      // Since the inline function items can be created in one place but then 
      // invoked in many other places, it is not possible to perform function
      // call normalization. Instead the domain expressions of arg vars is 
      // wrapped in type matches.
      if (!is_coercion) 
        letClause->set_expr(normalize_fo_arg(i,
                                             letClause->get_expr(),
                                             udf.getp(),
                                             loc));
    }
  }

  /* TODO: optimizing the HoF here is a very bad idea. This code can be safely removed
           anyways because the UDF optimization should take care of it.
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
  */

  udf->setBody(body);
  udf->setScriptingKind(body->get_scripting_detail());
  udf->setArgVars(argVars);
  udf->setOptimized(true); // TODO: this should not be set here

  // Get the function_item_expr and set its function to the udf created above.
  function_item_expr* fiExpr = dynamic_cast<function_item_expr*>(theNodeStack.top());
  assert(fiExpr != NULL);
  fiExpr->set_function(udf);

  if (theCCB->theConfig.translate_cb != NULL && theCCB->theConfig.optimize_cb == NULL)
    theCCB->theConfig.translate_cb(udf->getBody(),
                                   udf->getName()->getStringValue().c_str());

  if (theCCB->theConfig.optimize_cb != NULL)
    theCCB->theConfig.optimize_cb(udf->getBody(),
                                  udf->getName()->getStringValue().c_str());
}

/*******************************************************************************
   FilterExpr ::= FilterExpr
   (. (NCName | ParenthesizedExpr | VarRef | StringLiteral)
********************************************************************************/
void* begin_visit(const JSONObjectLookup& v)
{
  TRACE_VISIT();
  return no_state;
}


void end_visit(const JSONObjectLookup& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr* selectExpr = 0;
  if (v.get_selector_expr())
    selectExpr = pop_nodestack();

  expr* objectExpr = pop_nodestack();
  ZORBA_ASSERT(objectExpr != 0);

  flwor_expr* flworExpr = wrap_expr_in_flwor(objectExpr, false);

  for_clause* fc = reinterpret_cast<for_clause*>(flworExpr->get_clause(0));

  expr* flworVarExpr = CREATE(wrapper)(theRootSctx, theUDF, loc, fc->get_var());

  function* func = 
    selectExpr ?
      BUILTIN_FUNC(FN_JSONIQ_VALUE_2) :
      BUILTIN_FUNC(FN_JSONIQ_KEYS_1);

  fo_expr* accessorExpr = 
    selectExpr ?
      CREATE(fo)(theRootSctx, theUDF, loc, func, flworVarExpr, selectExpr) :
      CREATE(fo)(theRootSctx, theUDF, loc, func, flworVarExpr);

  normalize_fo(accessorExpr);

  flworExpr->set_return_expr(accessorExpr);

  pop_scope();

  push_nodestack(flworExpr);
}

/*******************************************************************************
  JSONConstructor ::= ArrayConstructor |
                      SimpleObjectUnion |
                      AccumulatorObjectUnion |
                      DirectObjectConstructor
********************************************************************************/


/*******************************************************************************
  ArrayConstructor ::= "[" Expr? "]"

  The Expr may return a sequence of zero or more items. If any of these items
  is a structured item, it is copied first, and the copy is inserted into the
  new array.
********************************************************************************/
void* begin_visit(const JSONArrayConstructor& v)
{
  TRACE_VISIT();

#ifndef ZORBA_WITH_JSON
  RAISE_ERROR_NO_PARAMS(err::XPST0003, loc);
#endif

  return no_state;
}

void end_visit(const JSONArrayConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

#ifdef ZORBA_WITH_JSON
  expr* contentExpr = NULL;

  if (v.get_expr() != NULL)
  {
    contentExpr = pop_nodestack();
  }

  push_nodestack(theExprManager->create_json_array_expr(theRootSctx, theUDF, loc, contentExpr));
#endif
}


/*******************************************************************************
  SimpleObjectUnion ::= "{|" Expr? "|}"

  AccumulatorObjectUnion ::= "{[" Expr? "]}"

  The Expr must return a sequence of zero or more objects
********************************************************************************/
void* begin_visit(const JSONObjectConstructor& v)
{
  TRACE_VISIT();
#ifndef ZORBA_WITH_JSON
  RAISE_ERROR_NO_PARAMS(err::XPST0003, loc);
#endif
  return no_state;
}

void end_visit(const JSONObjectConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

#ifdef ZORBA_WITH_JSON
  expr* contentExpr = NULL;

  if (v.get_expr() != NULL)
  {
    contentExpr = pop_nodestack();

    contentExpr = CREATE(treat)(theRootSctx,
                                theUDF,
                                contentExpr->get_loc(),
                                contentExpr,
                                GENV_TYPESYSTEM.JSON_OBJECT_TYPE_STAR,
                                TREAT_TYPE_MATCH,
                                true,
                                NULL);
  }

  expr* jo = CREATE(json_object)(theRootSctx,
                                 theUDF,
                                 loc,
                                 contentExpr,
                                 v.get_accumulate());

  push_nodestack(jo);
#endif
}


/*******************************************************************************
  DirectObjectConstructor ::= "{" PairConstructor ("," PairConstructor )* "}"

  PairConstructor ::= ExprSingle ":" ExprSingle
********************************************************************************/
void* begin_visit(const JSONDirectObjectConstructor& v)
{
  TRACE_VISIT();
#ifndef ZORBA_WITH_JSON
  RAISE_ERROR_NO_PARAMS(err::XPST0003, loc);
#endif
  return no_state;
}

void end_visit(const JSONDirectObjectConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

#ifdef ZORBA_WITH_JSON
  csize numPairs = v.numPairs();
  std::vector<expr*> names(numPairs);
  std::vector<expr*> values(numPairs);

  for (csize i = numPairs; i > 0; --i)
  {
    names[i-1] = pop_nodestack();
    values[i-1] = pop_nodestack();
  }

  expr* jo = theExprManager->
  create_json_direct_object_expr(theRootSctx, theUDF, loc, names, values);

  push_nodestack(jo);
#endif
}


/*******************************************************************************
  PairList ::= PairConstructor | PairList COMMA PairConstructor
********************************************************************************/
void* begin_visit(const JSONPairList& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const JSONPairList& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  PairConstructor ::= ExprSingle ":" ExprSingle

  The PairConstructor production can appear only on the RHS of a
  DirectObjectConstructor or in the source list of a JSONObjectInsertExpr

  The 1st ExprSingle must return exactly one item castable to string after
  atomization. The 2nd ExprSingle may return any kind of sequence; if the
  sequence is empty, it is replaced by the null item; if the sequence contains
  more than one item, it is boxed into an array.
********************************************************************************/
void* begin_visit(const JSONPairConstructor& v)
{
  TRACE_VISIT ();
#ifndef ZORBA_WITH_JSON
  RAISE_ERROR_NO_PARAMS(err::XPST0003, loc);
#else
#endif

  return no_state;
}

void end_visit(const JSONPairConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

#ifdef ZORBA_WITH_JSON
  expr* nameExpr = pop_nodestack();
  expr* valueExpr = pop_nodestack();

  nameExpr = wrap_in_atomization(nameExpr);

  nameExpr = CREATE(cast)(theRootSctx,
                          theUDF,
                          nameExpr->get_loc(),
                          nameExpr,
                          GENV_TYPESYSTEM.STRING_TYPE_ONE,
                          false);

  valueExpr = CREATE(fo)(theRootSctx,
                         theUDF,
                         valueExpr->get_loc(),
                         BUILTIN_FUNC(OP_ZORBA_JSON_BOX_1),
                         valueExpr);

  push_nodestack(valueExpr);
  push_nodestack(nameExpr);
#endif
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

  expr* contentExpr = pop_nodestack();

  fo_expr* foExpr = wrap_in_enclosed_expr(contentExpr, loc);

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

  expr* nameExpr = NULL;
  expr* attrExpr = NULL;
  expr* contentExpr = NULL;

  rchandle<QName> end_tag = v.get_end_name();
  rchandle<QName> start_tag = v.get_elem_name();

  if (end_tag != NULL && start_tag->get_qname() != end_tag->get_qname())
  {
    RAISE_ERROR(err::XPST0003, loc,
    ERROR_PARAMS(ZED(XPST0003_StartEndTagMismatch_23),
                 start_tag->get_qname(),
                 end_tag->get_qname()));
  }

  if (v.get_dir_content_list() != NULL)
    contentExpr = pop_nodestack();

  if (v.get_attr_list() != NULL)
    attrExpr = pop_nodestack();

  store::Item_t qnameItem;
  expand_elem_qname(qnameItem, v.get_elem_name(), loc);

  nameExpr = CREATE(const)(theRootSctx, theUDF, loc, qnameItem);

  bool copyNodes = (theCCB->theConfig.opt_level < CompilerCB::config::O1 ||
                    !Properties::instance()->noCopyOptim());

  push_nodestack(CREATE(elem)(theRootSctx,
                              theUDF,
                              loc,
                              nameExpr,
                              attrExpr,
                              contentExpr,
                              theNSCtx,
                              copyNodes));
  pop_elem_scope();
  pop_scope();
}


/*******************************************************************************
   [120] DirAttributeList ::= DirAttr | DirAttributeList DirAttr
********************************************************************************/
void* begin_visit(const DirAttributeList& v)
{
  TRACE_VISIT();

  push_nodestack(NULL);

  // visit namespace declaratrion attributes first
  for (int visitType = 0; visitType < 2; ++visitType)
  {
    for (csize i = 0; i < v.size(); ++i)
    {
      const DirAttr* attr = v[i];
      const QName* qname = attr->get_name();
      bool isPrefix = qname->get_qname() == "xmlns" || qname->get_prefix() == "xmlns";

      if ((isPrefix && visitType == 0) || (! isPrefix && visitType == 1))
        attr->accept(*this);
    }
  }

  csize numAttrs = 0;
  std::vector<attr_expr*> attributes;
  while(true)
  {
    expr* expr = pop_nodestack();
    if (expr == NULL)
      break;

    attr_expr* attrExpr = dynamic_cast<attr_expr*>(expr);
    const store::Item* attExprName = attrExpr->getQName();

    for (csize i = 0; i < numAttrs; ++i)
    {
      const store::Item* attName = attributes[i]->getQName();
      if (attName->equals(attExprName))
        RAISE_ERROR(err::XQST0040, loc, ERROR_PARAMS(attName->getStringValue()));
    }

    attributes.push_back(attrExpr);
    ++numAttrs;
  }

  if (attributes.size() == 1)
  {
    push_nodestack(attributes[0]);
  }
  else
  {
    std::vector<expr*> args;
    for (std::vector<attr_expr*>::reverse_iterator it = attributes.rbegin();
         it != attributes.rend();
         ++it)
    {
      args.push_back((*it));
    }

    fo_expr* expr_list = 
    CREATE(fo)(theRootSctx, theUDF, loc, op_concatenate, args);

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

  expr* valueExpr = pop_nodestack();

  if (valueExpr != NULL)
  {
    // delete boundary
    pop_nodestack();
  }

  QName* qname = v.get_name();

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
        RAISE_ERROR(err::XQST0070, loc,
        ERROR_PARAMS(prefix, ZED(NoRebindPrefix)));
    }

    const_expr* constValueExpr = dynamic_cast<const_expr*>(valueExpr);
    fo_expr* foExpr = dynamic_cast<fo_expr*>(valueExpr);

    if (foExpr != NULL && foExpr->get_func() != op_concatenate)
      foExpr = NULL;

    if (constValueExpr != NULL)
    {
      constValueExpr->get_val()->getStringValue2(uri);
      have_uri = true;
    }
    else if (foExpr != NULL)
    {
      for (csize i = 0; i < foExpr->num_args(); ++i)
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
        RAISE_ERROR(err::XQST0070, loc,
        ERROR_PARAMS(prefix, ZED(NoRebindPrefix)));
      }

      if ((ZSTREQ(uri, XML_NS) && !ZSTREQ(prefix, "xml")) ||
           ZSTREQ(uri, XMLNS_NS))
      {
        RAISE_ERROR(err::XQST0070, loc, ERROR_PARAMS(uri, ZED(NoBindURI)));
      }

      theSctx->bind_ns(prefix, uri, loc);
      theNSCtx->bind_ns(prefix, uri);

      if (prefix.empty())
        theSctx->set_default_elem_type_ns(uri, true, loc);
    }
    else if (valueExpr == NULL)
    {
      if (ZSTREQ(prefix, "xml"))
      {
        RAISE_ERROR(err::XQST0070, loc,
        ERROR_PARAMS(prefix, ZED(NoRebindPrefix)));
      }

      // unbind the prefix
      zstring empty;
      theSctx->bind_ns(prefix, empty, loc);
      theNSCtx->bind_ns(prefix, empty);

      if (prefix.empty())
        theSctx->set_default_elem_type_ns(empty, true, loc);
    }
    else
    {
      throw XQUERY_EXCEPTION(err::XQST0022, ERROR_LOC(loc));
    }
  }
  // Plain direct attribute
  else
  {
    store::Item_t qnameItem;
    expand_no_default_qname(qnameItem, qname, qname->get_location());

    expr* nameExpr = CREATE(const)(theRootSctx, theUDF, loc, qnameItem);

    fo_expr* foExpr = NULL;
    if ((foExpr = dynamic_cast<fo_expr*>(valueExpr)) != NULL &&
        foExpr->get_func()->getKind() == FunctionConsts::OP_ENCLOSED_1)
    {
      foExpr->set_arg(0, wrap_in_atomization(foExpr->get_arg(0)));
    }
    else if (valueExpr != NULL)
    {
      valueExpr = wrap_in_atomization(valueExpr);
    }

    expr* attrExpr = theExprManager->create_attr_expr(theRootSctx, theUDF, loc, nameExpr, valueExpr);

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

  std::vector<expr*> args;
  while (true)
  {
    expr* e = pop_nodestack();
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
    fo_expr* expr_list = CREATE(fo)(theRootSctx, theUDF, loc, op_concatenate, args);

    normalize_fo(expr_list);

    push_nodestack(expr_list);
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
      expr* content = CREATE(const)(theRootSctx, theUDF, loc, v.get_elem_content().str());

      push_nodestack(CREATE(text)(theRootSctx, theUDF, loc, text_constructor, content));
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


/*******************************************************************************

********************************************************************************/
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
    expr* content = CREATE(const)(theRootSctx, theUDF, loc, lCDATA_content);
    push_nodestack(CREATE(text)(theRootSctx, theUDF, loc, text_constructor, content));
  }
}


/*******************************************************************************

********************************************************************************/
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
  std::vector<expr*> args;
  while(true)
  {
    expr* e = pop_nodestack();
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
    fo_expr* expr_list = theExprManager->
    create_fo_expr(theRootSctx, theUDF, loc, op_concatenate, args);

    normalize_fo(expr_list);

    push_nodestack(expr_list);
  }
}


/*******************************************************************************

********************************************************************************/
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


/*******************************************************************************

********************************************************************************/
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
    push_nodestack(theExprManager->create_const_expr (theRootSctx, theUDF, loc, content));
  }
  else
  {
    // nothing to be done because when common content != NULL,
    // the corresponding expr is already on the stack
  }
}


/*******************************************************************************

********************************************************************************/
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


/*******************************************************************************

********************************************************************************/
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


/*******************************************************************************

********************************************************************************/
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

    expr* lConstExpr = theExprManager->create_const_expr(theRootSctx, theUDF, loc, content);
    push_nodestack(lConstExpr);
    break;
  }
  case ParseConstants::cont_escape_lbrace:
  {
    // we always create a text node here because if we are in an attribute, we atomice
    // the text node into its string value
    zstring content("{");
    expr* lConstExpr = theExprManager->create_const_expr(theRootSctx, theUDF, loc, content);
    push_nodestack ( lConstExpr );
    break;
  }
  case ParseConstants::cont_escape_rbrace:
  {
    // we always create a text node here because if we are in an attribute, we atomice
    // the text node into its string value
    zstring content("}");
    expr* lConstExpr = CREATE(const)(theRootSctx, theUDF, loc, content);
    push_nodestack ( lConstExpr );
    break;
  }
  case ParseConstants::cont_expr:
  {
    break;
  }
  }
}


/*******************************************************************************

********************************************************************************/
void* begin_visit(const DirCommentConstructor& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const DirCommentConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  zstring str = v.get_comment().str();
  expr* content = CREATE(const)(theRootSctx, theUDF, loc, str);

  push_nodestack (CREATE(text)(theRootSctx,
                               theUDF,
                               loc,
                               comment_constructor,
                               content));
}


/*******************************************************************************

********************************************************************************/
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
    RAISE_ERROR(err::XPST0003, loc, ERROR_PARAMS(ZED(XPST0003_PiTarget)));

  expr* target = theExprManager->create_const_expr(theRootSctx, theUDF, loc, target_str);
  expr* content = theExprManager->create_const_expr(theRootSctx, theUDF, loc, v.get_pi_content().str());

  push_nodestack(theExprManager->create_pi_expr(theRootSctx, theUDF, loc, target,  content));
}


/*******************************************************************************

********************************************************************************/
void* begin_visit(const CompDocConstructor& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const CompDocConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr* content = pop_nodestack();

  fo_expr* enclosed = wrap_in_enclosed_expr(content, loc);

  bool copyNodes = (theCCB->theConfig.opt_level < CompilerCB::config::O1 ||
                    !Properties::instance()->noCopyOptim());

  push_nodestack(CREATE(doc)(theRootSctx, theUDF, loc, enclosed, copyNodes));
}


/*******************************************************************************

********************************************************************************/
void* begin_visit(const CompElemConstructor& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const CompElemConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr* nameExpr = NULL;
  expr* contentExpr = NULL;

  if (v.get_content_expr() != 0)
  {
    contentExpr = pop_nodestack();

    fo_expr* enclosed = wrap_in_enclosed_expr(contentExpr, loc);

    contentExpr = enclosed;
  }

  QName* constQName = v.get_qname_expr().dyn_cast<QName>();

  if (constQName != NULL)
  {
    store::Item_t qnameItem;
    expand_elem_qname(qnameItem, constQName, loc);

    nameExpr = CREATE(const)(theRootSctx, theUDF, loc, qnameItem);
  }
  else
  {
    nameExpr = pop_nodestack();
    nameExpr = wrap_in_atomization(nameExpr);
    nameExpr = 
    CREATE(name_cast)(theRootSctx, theUDF, loc, nameExpr, theNSCtx, false);
  }

  bool copyNodes = (theCCB->theConfig.opt_level < CompilerCB::config::O1 ||
                    !Properties::instance()->noCopyOptim());

  push_nodestack(CREATE(elem)(theRootSctx,
                              theUDF,
                              loc,
                              nameExpr,
                              contentExpr,
                              theNSCtx,
                              copyNodes));
}


/*******************************************************************************

********************************************************************************/
void* begin_visit(const CompAttrConstructor& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const CompAttrConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr* nameExpr = NULL;
  expr* valueExpr = NULL;
  expr* attrExpr = NULL;

  if (v.get_val_expr() != 0)
  {
    valueExpr = pop_nodestack();
    valueExpr = wrap_in_enclosed_expr(valueExpr, loc);
  }

  QName* constQName = v.get_qname_expr().dyn_cast<QName>();

  if (constQName != NULL)
  {
    store::Item_t qnameItem;
    expand_no_default_qname(qnameItem, constQName, constQName->get_location());

    nameExpr = CREATE(const)(theRootSctx, theUDF, loc, qnameItem);
  }
  else
  {
    nameExpr = pop_nodestack();
    nameExpr = wrap_in_atomization(nameExpr);
    nameExpr =
    CREATE(name_cast)(theRootSctx, theUDF, loc, nameExpr, theNSCtx, true);
  }

  attrExpr = CREATE(attr)(theRootSctx, theUDF, loc, nameExpr, valueExpr);

  push_nodestack(attrExpr);
}


/*******************************************************************************

********************************************************************************/
void* begin_visit(const CompNamespaceConstructor& v)
{
  TRACE_VISIT();

  if (theSctx->xquery_version() < StaticContextConsts::xquery_version_3_0)
  {
    RAISE_ERROR(err::XPST0003, loc, ERROR_PARAMS(ZED(XPST0003_CompNS)));
  }

  return no_state;
}

void end_visit(const CompNamespaceConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr* uriExpr = pop_nodestack();
  uriExpr = create_cast_expr(loc, uriExpr, theRTM.ANY_URI_TYPE_ONE, false, true);

  expr* prefixExpr;

  if (v.get_prefix_expr() != NULL)
  {
    prefixExpr = pop_nodestack();
    prefixExpr = wrap_in_type_promotion(prefixExpr,
                                        theRTM.STRING_TYPE_QUESTION,
                                        PROMOTE_TYPE_PROMOTION);
  }
  else
  {
    store::Item_t qnameItem;
    GENV_ITEMFACTORY->createQName(qnameItem, "", "", v.get_prefix());
    prefixExpr = CREATE(const)(theRootSctx, theUDF, loc, qnameItem);
  }

  expr* nsExpr = CREATE(namespace)(theRootSctx, theUDF, loc, prefixExpr, uriExpr);

  push_nodestack(nsExpr);
}


/*******************************************************************************

********************************************************************************/
void* begin_visit(const CompTextConstructor& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const CompTextConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr* inputExpr = pop_nodestack();

  fo_expr* enclosedExpr = wrap_in_enclosed_expr(inputExpr, loc);

  expr* textExpr = 
  CREATE(text)(theRootSctx, theUDF, loc, text_constructor, enclosedExpr);

  push_nodestack(textExpr);
}


/*******************************************************************************

********************************************************************************/
void* begin_visit(const CompCommentConstructor& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const CompCommentConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr* inputExpr = pop_nodestack();

  fo_expr* enclosedExpr = wrap_in_enclosed_expr(inputExpr, loc);

  expr* textExpr = 
  CREATE(text)(theRootSctx, theUDF, loc, comment_constructor, enclosedExpr);

  push_nodestack(textExpr);
}


/*******************************************************************************

********************************************************************************/
void* begin_visit(const CompPIConstructor& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const CompPIConstructor& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr* target = NULL;
  expr* content = NULL;

  if (v.get_content_expr() == NULL)
  {
    content = create_empty_seq(loc);
  }
  else
  {
    content = pop_nodestack();

    content = wrap_in_enclosed_expr(content, loc);
  }

  if (v.get_target_expr() != NULL)
  {
    target = pop_nodestack();

    expr* castExpr = 
    create_cast_expr(loc, target, theRTM.NCNAME_TYPE_ONE, false, true);

    target = wrap_in_enclosed_expr(castExpr, loc);
  }

  expr* e;

  if (v.get_target_expr() != NULL)
  {
    e = CREATE(pi)(theRootSctx, theUDF, loc, target, content);
  }
  else
  {
    e = CREATE(pi)(theRootSctx, theUDF, loc,
                   CREATE(const)(theRootSctx, theUDF, loc, v.get_target().str()),
                   content);
  }

  push_nodestack(e);
}



/*******************************************************************************

********************************************************************************/
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
  OccurrenceIndicator node. The left child may be either a GeneralizedAtomicType
  node, or one of the 9 kind-test nodes (elementTest, documentTest, ... etc), or
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

void end_visit(const SequenceType& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
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
    ZORBA_ASSERT(false);
  }

  if (q != TypeConstants::QUANT_ONE)
    theTypeStack.push(CTX_TM->create_type(*pop_tstack(), q));

  return no_state;
}

void end_visit(const OccurrenceIndicator& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


void* begin_visit(const GeneralizedAtomicType& v)
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const GeneralizedAtomicType& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  rchandle<QName> qname = v.get_qname();
  store::Item_t qnameItem;
  expand_type_qname(qnameItem, qname, loc);

  xqtref_t t = CTX_TM->create_named_simple_type(qnameItem);

  if (t == NULL ||
      t->get_quantifier() != TypeConstants::QUANT_ONE)
  {
    RAISE_ERROR(err::XPST0051, loc,
    ERROR_PARAMS(ZED(XPST0051_GenAtomic_2), qname->get_qname()));
  }
  else
  {
    theTypeStack.push(t);
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
  theTypeStack.push(GENV_TYPESYSTEM.ITEM_TYPE_ONE);
}


void* begin_visit(const StructuredItemType& v)
{
  TRACE_VISIT();
#ifndef ZORBA_WITH_JSON
  RAISE_ERROR_NO_PARAMS(err::XPST0003, loc);
#endif
  return no_state;
}

void end_visit(const StructuredItemType& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
#ifdef ZORBA_WITH_JSON
  theTypeStack.push(GENV_TYPESYSTEM.STRUCTURED_ITEM_TYPE_ONE);
#endif
}


/*******************************************************************************

  JSONTest

  JSONTest ::= JSONItemTest | JSONObjectTest | JSONArrayTest

  JSONItemTest ::= "json-item" "(" ")"
  JSONObjectTest ::= "object" "(" ")"
  JSONArrayTest ::= "array" "(" ")"

********************************************************************************/

void* begin_visit(const JSON_Test& v)
{
  TRACE_VISIT();
#ifndef ZORBA_WITH_JSON
  RAISE_ERROR_NO_PARAMS(err::XPST0003, loc);
#endif
  return no_state;
}

void end_visit(const JSON_Test& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
#ifdef ZORBA_WITH_JSON
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  switch (v.get_kind())
  {
  case store::StoreConsts::jsonObject:
  {
    theTypeStack.push(rtm.JSON_OBJECT_TYPE_ONE);
    break;
  }
  case store::StoreConsts::jsonArray:
  {
    theTypeStack.push(rtm.JSON_ARRAY_TYPE_ONE);

    break;
  }
  case store::StoreConsts::jsonItem:
  {
    theTypeStack.push(rtm.JSON_ITEM_TYPE_ONE);
    break;
  }
  default:
    ZORBA_ASSERT(false);
  }
#endif /* ZORBA_WITH_JSON */
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
  axis_step_expr* axisExpr = dynamic_cast<axis_step_expr*>(peek_nodestk_or_null());

  if (axisExpr != NULL)
  {
    match_expr* me = theExprManager->create_match_expr(theRootSctx, theUDF, loc);
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

  ElementTest* elemTest = v.get_elem_test();
  SchemaElementTest* schemaTest = v.get_schema_elem_test();
  axis_step_expr* axisExpr =
    dynamic_cast<axis_step_expr*>(peek_nodestk_or_null());
  match_expr* match = NULL;

  if (elemTest == NULL && schemaTest == NULL)
  {
    if (axisExpr != NULL)
    {
      match = theExprManager->create_match_expr(theRootSctx, theUDF, loc);
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


void end_visit(const ElementTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();

  bool nillable =  v.isNilledAllowed();
  rchandle<QName> elemName = v.getElementName();
  rchandle<TypeName> typeName = v.getTypeName();
  store::Item_t elemNameItem;
  store::Item_t typeNameItem;

  if (elemName != NULL)
    expand_elem_qname(elemNameItem, elemName, loc);

  if (typeName != NULL)
    expand_elem_qname(typeNameItem, typeName->get_name(), loc);

  // if the top of the stack is an axis step expr, add a node test expr to it.
  axis_step_expr* axisExpr = dynamic_cast<axis_step_expr*> (peek_nodestk_or_null ());

  xqtref_t contentType;

  if (typeName != NULL)
  {
    contentType = CTX_TM->create_named_type(typeNameItem,
                                            TypeConstants::QUANT_ONE,
                                            loc);

    if (contentType == NULL)
    {
      RAISE_ERROR(err::XPST0008, loc,
      ERROR_PARAMS(typeNameItem->getStringValue(), ZED(ElementName)));
    }
  }

  if (axisExpr != NULL)
  {
    match_expr* me = theExprManager->create_match_expr(theRootSctx, theUDF, loc);
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
  axis_step_expr* axisExpr = dynamic_cast<axis_step_expr*> (peek_nodestk_or_null ());
  rchandle<QName> elemName = v.get_elem();
  ZORBA_ASSERT(elemName != NULL);

  store::Item_t elemQNameItem;
  expand_elem_qname(elemQNameItem, elemName, loc);

  if (axisExpr != NULL)
  {
    store::Item_t typeQNameItem;
    CTX_TM->get_schema_element_typename(elemQNameItem, typeQNameItem, loc);

    match_expr* match = theExprManager->create_match_expr(theRootSctx, theUDF, loc);
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
  RAISE_ERROR(zerr::ZXQP0005_NOT_ENABLED, loc, ERROR_PARAMS(ZED(XMLSchema)));
#endif /* ZORBA_NO_XMLSCHEMA */
  return no_state;
}


void end_visit(const SchemaElementTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  AttributeTest ::= "attribute" "(" (AttribNameOrWildcard ("," TypeName)?)? ")"

  AttribNameOrWildcard ::= AttributeName | "*"
********************************************************************************/
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

    contentType = CTX_TM->create_named_type(typeNameItem,
                                            TypeConstants::QUANT_ONE,
                                            loc);

    if (contentType == NULL)
    {
      RAISE_ERROR(err::XPST0008, loc,
      ERROR_PARAMS(typeNameItem->getStringValue(), ZED(AttributeName)));
    }
  }

  // if the top of the stack is an axis step expr, add a node test expr to it.
  axis_step_expr* axisExpr = dynamic_cast<axis_step_expr*> (peek_nodestk_or_null());

  if (axisExpr != NULL)
  {
    match_expr* match = theExprManager->create_match_expr(theRootSctx, theUDF, loc);
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
                                                 attrNameItem,
                                                 contentType,
                                                 TypeConstants::QUANT_ONE,
                                                 false,
                                                 false);

    theTypeStack.push(seqmatch);
  }
}


/*******************************************************************************
  SchemaAttributeTest ::= "schema-attribute" "(" AttributeDeclaration ")"

  SchemaDeclaration ::= AttributeName
********************************************************************************/
void* begin_visit(const SchemaAttributeTest& v)
{
  TRACE_VISIT();

#ifndef ZORBA_NO_XMLSCHEMA
  axis_step_expr* axisExpr = dynamic_cast<axis_step_expr*>(peek_nodestk_or_null());

  rchandle<QName> attrName = v.get_attr();
  ZORBA_ASSERT(attrName != NULL);

  store::Item_t attrQNameItem;
  expand_no_default_qname(attrQNameItem, attrName, attrName->get_location());

  if (axisExpr != NULL)
  {
    store::Item_t typeQNameItem;
    CTX_TM->get_schema_attribute_typename(attrQNameItem, typeQNameItem, loc);

    match_expr* match = theExprManager->create_match_expr(theRootSctx, theUDF, loc);
    match->setTestKind(match_xs_attr_test);
    match->setQName(attrQNameItem);
    match->setTypeName(typeQNameItem);

    axisExpr->setTest(match);
  }
  else
  {
    xqtref_t seqmatch = CTX_TM->
    create_schema_attribute_type(attrQNameItem, TypeConstants::QUANT_ONE, loc);

    theTypeStack.push(seqmatch);
  }

#else /* ZORBA_NO_XMLSCHEMA */
  RAISE_ERROR(zerr::ZXQP0005_NOT_ENABLED, loc, ERROR_PARAMS(ZED(XMLSchema)));
#endif /* ZORBA_NO_XMLSCHEMA */
  return no_state;
}


void end_visit(const SchemaAttributeTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();
}


void* begin_visit(const NamespaceTest& v)
{
  TRACE_VISIT();
  // no action needed here
  return no_state;
}


void end_visit(const NamespaceTest& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  axis_step_expr* axisExpr =
  dynamic_cast<axis_step_expr*>(peek_nodestk_or_null());

  if (axisExpr != NULL)
  {
    RAISE_ERROR(zerr::ZXQP0004_NOT_IMPLEMENTED, loc, ERROR_PARAMS("namespace axis"));
  }
  else
  {
    theTypeStack.push(GENV_TYPESYSTEM.NAMESPACE_TYPE_ONE);
  }
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

  axis_step_expr* axisExpr =
  dynamic_cast<axis_step_expr*>(peek_nodestk_or_null());

  if (axisExpr != NULL)
  {
    match_expr* match = theExprManager->create_match_expr(theRootSctx, theUDF, loc);
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

  axis_step_expr* axisExpr =
    dynamic_cast<axis_step_expr*> (peek_nodestk_or_null ());
  if (axisExpr != NULL)
  {
    match_expr* match = theExprManager->create_match_expr(theRootSctx, theUDF, loc);
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

  axis_step_expr* axisExpr = dynamic_cast<axis_step_expr*>(peek_nodestk_or_null());

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
    ascii::normalize_whitespace(target, &lNormalizedTarget);

    if (!GenericCast::castableToNCName(lNormalizedTarget))
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(BadType_23o), lNormalizedTarget, ZED(NoCastTo_45o), "NCName"));
    }

    // bugfix (see above); pass normalized string instead of original target
    GENV_ITEMFACTORY->createQName(qname, NULL, NULL, lNormalizedTarget.c_str());
  }

  if (axisExpr != NULL)
  {
    match_expr* match = theExprManager->create_match_expr(theRootSctx, theUDF, loc);
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
      theTypeStack.push(t);
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
      const SequenceType* lParamType = (*lParamTypes)[i];

      if (lParamType == 0)
      {
        lParamXQTypes.push_back(GENV_TYPESYSTEM.ITEM_TYPE_STAR);
      }
      else
      {
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

  TypeConstants::quantifier_t lQuant = TypeConstants::QUANT_ONE;
  theTypeStack.push (GENV_TYPESYSTEM.create_function_type(
    lParamXQTypes, lRetXQType, lQuant));
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Update Expressions                                                        //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////



/*******************************************************************************
  JSONObjectInsertExpr ::=
  "insert" "json" "{" PairConstructor ("," PairConstructor)* "}"
********************************************************************************/
void* begin_visit(const JSONObjectInsertExpr& v)
{
  TRACE_VISIT();
#ifndef ZORBA_WITH_JSON
  RAISE_ERROR_NO_PARAMS(err::XPST0003, loc);
#endif
  return no_state;
}


void end_visit(const JSONObjectInsertExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

#ifdef ZORBA_WITH_JSON
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  expr* targetExpr = pop_nodestack();
  expr* contentExpr = pop_nodestack();

  targetExpr = wrap_in_type_match(targetExpr,
                                  rtm.JSON_OBJECT_TYPE_ONE,
                                  loc,
                                  TREAT_JSONIQ_OBJECT_UPDATE_TARGET, // JNUP0008
                                  NULL);

  contentExpr = wrap_in_type_match(contentExpr,
                                  rtm.JSON_OBJECT_TYPE_STAR,
                                  loc,
                                  TREAT_JSONIQ_OBJECT_UPDATE_CONTENT, // JNUP0019
                                  NULL);

  std::vector<expr*> args(2);
  args[0] = targetExpr;
  args[1] = CREATE(json_object)(theRootSctx, theUDF, loc, contentExpr, false);

  expr* updExpr = CREATE(fo)(theRootSctx,
                             theUDF,
                             loc,
                             BUILTIN_FUNC(OP_ZORBA_JSON_OBJECT_INSERT_2),
                             args);

  push_nodestack(updExpr);
#endif
}


/*******************************************************************************
  JSONArrayInsertExpr ::=
  "insert" "json" "[" ExprSingle "]" "into" ExprSingle "at" "position" ExprSingle
********************************************************************************/
void* begin_visit(const JSONArrayInsertExpr& v)
{
  TRACE_VISIT();
#ifndef ZORBA_WITH_JSON
  RAISE_ERROR_NO_PARAMS(err::XPST0003, loc);
#endif
  return no_state;
}


void end_visit(const JSONArrayInsertExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

#ifdef ZORBA_WITH_JSON
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  expr* posExpr = pop_nodestack();
  expr* targetExpr = pop_nodestack();
  expr* sourceExpr = pop_nodestack();

  posExpr = wrap_in_type_promotion(posExpr,
                                   rtm.INTEGER_TYPE_ONE,
                                   PROMOTE_JSONIQ_ARRAY_SELECTOR); // JNUP0007

  targetExpr = wrap_in_type_match(targetExpr,
                                  rtm.JSON_ARRAY_TYPE_ONE,
                                  loc,
                                  TREAT_JSONIQ_ARRAY_UPDATE_TARGET, // JNUP0008
                                  NULL);

  std::vector<expr*> args(3);
  args[0] = targetExpr;
  args[1] = posExpr;
  args[2] = sourceExpr;

  fo_expr* updExpr = theExprManager->
  create_fo_expr(theRootSctx, theUDF,
                 loc,
                 BUILTIN_FUNC(OP_ZORBA_JSON_ARRAY_INSERT_3),
                 args);

  normalize_fo(updExpr);

  push_nodestack(updExpr);
#endif
}


/*******************************************************************************

********************************************************************************/
void* begin_visit(const JSONArrayAppendExpr& v)
{
  TRACE_VISIT();
#ifndef ZORBA_WITH_JSON
  RAISE_ERROR_NO_PARAMS(err::XPST0003, loc);
#endif
  return no_state;
}


void end_visit(const JSONArrayAppendExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

#ifdef ZORBA_WITH_JSON
  expr* targetExpr = pop_nodestack();
  expr* contentExpr = pop_nodestack();

  targetExpr = wrap_in_type_match(targetExpr,
                                  theRTM.JSON_ARRAY_TYPE_ONE,
                                  loc,
                                  TREAT_JSONIQ_ARRAY_UPDATE_TARGET, // JNUP0008
                                  NULL);

  fo_expr* updExpr = CREATE(fo)(theRootSctx,
                                theUDF,
                                loc,
                                BUILTIN_FUNC(OP_ZORBA_JSON_ARRAY_APPEND_2),
                                targetExpr,
                                contentExpr);

  normalize_fo(updExpr);

  push_nodestack(updExpr);
#endif
}


/*******************************************************************************
  JSONDeleteExpr ::= "delete" "json" FilterExpr

  The parser makes sure that the FileterExpr is actually a dynamic  function
  invocation, i.e., :

  FilterExpr := PrimaryExpr ("(" ArgList ")")+

  The parser also makes sure that each ArgList contains exactly one arg.

  If there are N ArgLists, the last one is considered to be the selector expr
  and the PrimaryExpr together with the N-1 ArgLists constitute the target expr.
********************************************************************************/
void* begin_visit(const JSONDeleteExpr& v)
{
  TRACE_VISIT();
#ifndef ZORBA_WITH_JSON
  RAISE_ERROR_NO_PARAMS(err::XPST0003, loc);
#endif
  return no_state;
}


void end_visit(const JSONDeleteExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

#ifdef ZORBA_WITH_JSON
  expr* selExpr = pop_nodestack();
  expr* targetExpr = pop_nodestack();

  selExpr = wrap_in_type_promotion(selExpr,
                                   theRTM.ANY_ATOMIC_TYPE_ONE,
                                   PROMOTE_JSONIQ_SELECTOR, // JNUP0007
                                   NULL);

  targetExpr = wrap_in_type_match(targetExpr,
                                  theRTM.JSON_ITEM_TYPE_ONE,
                                  loc,
                                  TREAT_JSONIQ_UPDATE_TARGET, // JNUP0008
                                  NULL);

  fo_expr* updExpr = theExprManager->
  create_fo_expr(theRootSctx, theUDF,
                 loc,
                 BUILTIN_FUNC(OP_ZORBA_JSON_DELETE_2),
                 targetExpr,
                 selExpr);

  push_nodestack(updExpr);
#endif
}


/*******************************************************************************
  JSONReplaceExpr ::= "replace" "json" "value" "of" FilterExpr "with" ExprSingle
********************************************************************************/
void* begin_visit(const JSONReplaceExpr& v)
{
  TRACE_VISIT();
#ifndef ZORBA_WITH_JSON
  RAISE_ERROR_NO_PARAMS(err::XPST0003, loc);
#endif
  return no_state;
}


void end_visit(const JSONReplaceExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

#ifdef ZORBA_WITH_JSON
  expr* valueExpr = pop_nodestack();
  expr* selExpr = pop_nodestack();
  expr* targetExpr = pop_nodestack();

  std::vector<expr*> args(3);

  args[0] = wrap_in_type_match(targetExpr,
                               theRTM.JSON_ITEM_TYPE_ONE,
                               loc,
                               TREAT_JSONIQ_UPDATE_TARGET, // JNUP0008
                               NULL);

  args[1] = wrap_in_type_promotion(selExpr,
                                   theRTM.ANY_ATOMIC_TYPE_ONE,
                                   PROMOTE_JSONIQ_SELECTOR, // JNUP0007
                                   NULL);

  args[2] = theExprManager->create_fo_expr(theRootSctx, theUDF,
                                           valueExpr->get_loc(),
                                           BUILTIN_FUNC(OP_ZORBA_JSON_BOX_1),
                                           valueExpr);

  fo_expr* updExpr = theExprManager->
  create_fo_expr(theRootSctx, theUDF,
                 loc,
                 BUILTIN_FUNC(OP_ZORBA_JSON_REPLACE_VALUE_3),
                 args);

  push_nodestack(updExpr);
#endif
}


/*******************************************************************************
  JSONRenameExpr ::= "rename" "json" FilterExpr "as" ExprSingle
********************************************************************************/
void* begin_visit(const JSONRenameExpr& v)
{
  TRACE_VISIT();
#ifndef ZORBA_WITH_JSON
  RAISE_ERROR_NO_PARAMS(err::XPST0003, loc);
#endif
  return no_state;
}


void end_visit(const JSONRenameExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

#ifdef ZORBA_WITH_JSON
  expr* newNameExpr = pop_nodestack();
  expr* nameExpr = pop_nodestack();
  expr* targetExpr = pop_nodestack();

  std::vector<expr*> args(3);

  args[0] = wrap_in_type_match(targetExpr,
                               theRTM.JSON_OBJECT_TYPE_ONE,
                               loc,
                               TREAT_JSONIQ_OBJECT_UPDATE_TARGET, // JNUP0008
                               NULL);

  args[1] = wrap_in_type_promotion(nameExpr,
                                   theRTM.STRING_TYPE_ONE,
                                   PROMOTE_JSONIQ_OBJECT_SELECTOR); // JNUP0007

  args[2] = wrap_in_type_promotion(newNameExpr,
                                   theRTM.STRING_TYPE_ONE,
                                   PROMOTE_JSONIQ_OBJECT_SELECTOR); // JNUP0007

  fo_expr* updExpr = CREATE(fo)(theRootSctx,
                                theUDF,
                                loc,
                                BUILTIN_FUNC(OP_ZORBA_JSON_RENAME_3),
                                args);

  push_nodestack(updExpr);
#endif
}


/*******************************************************************************

********************************************************************************/
void* begin_visit(const DeleteExpr& v)
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const DeleteExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr* lTarget = pop_nodestack();

  expr* aDelete = theExprManager->create_delete_expr(theRootSctx, theUDF, loc, lTarget);
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
  expr* lTarget = pop_nodestack();
  expr* lSource = pop_nodestack();

  lSource = wrap_in_enclosed_expr(lSource, loc);

  expr* lInsert = theExprManager->
  create_insert_expr(theRootSctx, theUDF, loc, v.getType(), lSource, lTarget);

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

  expr* nameExpr = pop_nodestack();
  expr* targetExpr = pop_nodestack();

  nameExpr = wrap_in_atomization(nameExpr);

  // We use a name_cast_expr here for static typing reasons. However, during codegen,
  // we are not going to generate a NameCastIterator, because we don't always know at
  // compile time whether the target will an element or an attribute node.
  nameExpr = CREATE(name_cast)(theRootSctx, theUDF, loc, nameExpr, theNSCtx, false);

  expr* renameExpr = CREATE(rename)(theRootSctx, theUDF, loc, targetExpr, nameExpr);

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

  expr* lReplacement = pop_nodestack();
  expr* lTarget = pop_nodestack();

  if (v.getType() == store::UpdateConsts::NODE)
  {
    lReplacement = wrap_in_enclosed_expr(lReplacement, loc);
  }

  expr* lReplace = theExprManager->
  create_replace_expr(theRootSctx, theUDF, loc, v.getType(), lTarget, lReplacement);

  push_nodestack(lReplace);
}


void* begin_visit(const TransformExpr& v)
{
  TRACE_VISIT();

  transform_expr* transformExpr =
  theExprManager->create_transform_expr(theRootSctx, theUDF, loc);

  push_nodestack(transformExpr);

  return no_state;
}

void end_visit(const TransformExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  expr* returnExpr = pop_nodestack();
  expr* modifyExpr = pop_nodestack();

  transform_expr* transformExpr =
  dynamic_cast<transform_expr*>(theNodeStack.top());
  assert(transformExpr != NULL);

  transformExpr->setModifyExpr(modifyExpr);
  transformExpr->setReturnExpr(returnExpr);

  const csize lSize = v.get_var_list()->size();
  for (csize i = 0; i < lSize; ++i)
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

  return no_state;
}

void end_visit(const VarBinding& v, void*)
{
  TRACE_VISIT_OUT();

  expr* sourceExpr = pop_nodestack();

  if (sourceExpr->is_updating())
    throw XQUERY_EXCEPTION(err::XUST0001, ERROR_LOC(loc));

  push_scope();

  var_expr* varExpr = bind_var(loc, v.get_varname(), var_expr::copy_var);

  transform_expr* transformExpr =
  dynamic_cast<transform_expr*>(theNodeStack.top());
  assert(transformExpr != NULL);

  copy_clause* copyClause = theExprManager->create_copy_clause(varExpr, sourceExpr);

  transformExpr->add_back(copyClause);
}



////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Full-Text                                                                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


#ifndef ZORBA_NO_FULL_TEXT
template<typename FTNodeType> bool flatten( ftnode *n )
{
  if ( FTNodeType *const n2 = dynamic_cast<FTNodeType*>( n ) )
  {
    typename FTNodeType::ftnode_list_t &list = n2->get_node_list();
    typename FTNodeType::ftnode_list_t::iterator i = list.begin();
    while ( i != list.end() )
    {
      push_ftstack( *i );
      i = list.erase( i );
    }
    delete n;
    return true;
  }
  return false;
}
#endif /* ZORBA_NO_FULL_TEXT */

void* begin_visit (const FTAnd& v)
{
  TRACE_VISIT ();
#ifndef ZORBA_NO_FULL_TEXT
  push_ftstack( nullptr ); // sentinel
#endif /* ZORBA_NO_FULL_TEXT */
  return no_state;
}

void end_visit (const FTAnd& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftand::ftnode_list_t list;
  while ( true )
  {
    ftnode *const n = pop_ftstack();
    if ( !n )
      break;
    if ( !flatten<ftand>( n ) )
    {
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


void *begin_visit (const FTAnyallOption& v)
{
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}


void end_visit (const FTAnyallOption& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  // nothing to do
}


void *begin_visit (const FTBigUnit& v)
{
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}


void end_visit (const FTBigUnit& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  // nothing to do
}

void *begin_visit (const FTCaseOption& v)
{
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}


void end_visit (const FTCaseOption& v, void* /*visit_state*/)
{
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


void *begin_visit (const FTContainsExpr& v)
{
  TRACE_VISIT ();
#ifdef ZORBA_NO_FULL_TEXT
  throw XQUERY_EXCEPTION(
    err::XPST0003, ERROR_PARAMS( ZED( FullTextNotEnabled ) ), ERROR_LOC( loc )
  );
#endif /* ZORBA_NO_FULL_TEXT */
  return no_state;
}

void end_visit (const FTContainsExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  expr* ftignore = NULL;
  if ( v.get_ignore() )
    ftignore = pop_nodestack();

  ftselection *const selection = dynamic_cast<ftselection*>( pop_ftstack() );
  ZORBA_ASSERT( selection );

  expr* range = pop_nodestack();
  ZORBA_ASSERT( range );

  ftcontains_expr *const e =
    theExprManager->create_ftcontains_expr(theRootSctx, theUDF, loc, range, selection, ftignore );
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
  expr* e( pop_nodestack() );
  push_nodestack( wrap_in_type_match(e,
                                     theRTM.ANY_NODE_TYPE_STAR,
                                     e->get_loc(),
                                     TREAT_TYPE_MATCH));
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
  push_ftstack( nullptr ); // sentinel
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
  push_ftstack( nullptr ); // sentinel
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
  expr* e2 = pop_nodestack();
  expr* e1 = pop_nodestack();
  if ( e1 )
    pop_nodestack(); // pop the sentinel
  else {
    e1 = e2;
    e2 = NULL;
  }

  if ( e1 ) {
    e1 = wrap_in_type_promotion(e1,
                                theRTM.INTEGER_TYPE_ONE,
                                PROMOTE_TYPE_PROMOTION);
  }
  if ( e2 ) {
    e2 = wrap_in_type_promotion(e2,
                                theRTM.INTEGER_TYPE_ONE,
                                PROMOTE_TYPE_PROMOTION);
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
  zstring const &uri = v.get_uri();
  zstring error_msg;
  std::auto_ptr<internal::Resource> rsrc(
    theSctx->resolve_uri( uri, internal::EntityData::THESAURUS, error_msg )
  );
  if ( !rsrc.get() )
    throw XQUERY_EXCEPTION(
      err::FTST0018, ERROR_PARAMS( uri ), ERROR_LOC( loc )
    );

  ftrange *levels;
  if ( v.get_levels() ) {
    levels = dynamic_cast<ftrange*>( pop_ftstack() );
    ZORBA_ASSERT( levels );
  } else
    levels = nullptr;

  ftthesaurus_id *const tid =
    new ftthesaurus_id( loc, uri, v.get_relationship(), levels );
  push_ftstack( tid );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTThesaurusOption& v) {
  TRACE_VISIT ();
#ifndef ZORBA_NO_FULL_TEXT
  push_ftstack( nullptr ); // sentinel
#endif /* ZORBA_NO_FULL_TEXT */
  return no_state;
}

void end_visit (const FTThesaurusOption& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftthesaurus_id *const default_tid = v.includes_default() ?
    new ftthesaurus_id( loc, "##default" ) : nullptr;

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
  expr* e( pop_nodestack() );
  e = wrap_in_type_promotion(e,
                             theRTM.DOUBLE_TYPE_ONE,
                             PROMOTE_TYPE_PROMOTION);
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
  expr* e( pop_nodestack() );
  e = wrap_in_type_promotion(e,
                             theRTM.INTEGER_TYPE_ONE,
                             PROMOTE_TYPE_PROMOTION);
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
  expr* e( pop_nodestack() );
  e = wrap_in_type_promotion(e,
                             theRTM.STRING_TYPE_STAR,
                             PROMOTE_TYPE_PROMOTION);
  push_ftstack( new ftwords( loc, e, v.get_any_all_option()->get_option() ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTWordsTimes& v)
{
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTWordsTimes& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
#ifndef ZORBA_NO_FULL_TEXT
  ftrange *const times = dynamic_cast<ftrange*>( top_ftstack() );
  if ( times )
    pop_ftstack();
  ftwords *const words = dynamic_cast<ftwords*>( pop_ftstack() );
  push_ftstack( new ftwords_times( loc, words, times ) );
#endif /* ZORBA_NO_FULL_TEXT */
}

void *begin_visit (const FTWordsValue& v)
{
  TRACE_VISIT ();
  // nothing to do
  return no_state;
}

void end_visit (const FTWordsValue& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT ();
  // nothing to do
}


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
expr* result()
{
  if (theNodeStack.size() != 1)
  {
    std::cout << "Error: extra nodes on translator stack:\n";
    while (! theNodeStack.empty())
    {
#ifndef NDEBUG
      expr* e_h = pop_nodestack();

      if (! Properties::instance()->traceTranslator())
      {
        if (e_h != NULL)
          e_h->put(std::cout) << std::endl;
        else
          std::cout << "NULL" << std::endl;
      }
#else
      (void)pop_nodestack();
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
expr* translate_aux(
    TranslatorImpl* rootTranslator,
    const parsenode& root,
    static_context* rootSctx,
    csize rootSctxId,
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

  expr* result = t->result();

  CompilerCB* ccb = minfo->theCCB;
  if (ccb->theConfig.translate_cb != NULL)
    ccb->theConfig.translate_cb(&*result, "XQuery program");

  return result;
}


/*******************************************************************************
  Translate a main module.
********************************************************************************/
expr* translate(const parsenode& root, CompilerCB* ccb)
{
  std::map<zstring, zstring> modulesStack;

  if (typeid(root) != typeid(MainModule))
    RAISE_ERROR(err::XPST0003, root.get_location(),
    ERROR_PARAMS(ZED(XPST0003_ModuleDeclNotInMain)));

  ModulesInfo minfo(ccb);

  return translate_aux(NULL,
                       root,
                       ccb->theRootSctx,
                       (int)ccb->theSctxMap.size(),
                       &minfo,
                       modulesStack,
                       false);
}


/*******************************************************************************
  Globally accesible translation function: translate a function call
********************************************************************************/
expr* Translator::translate_literal_function(
    store::Item_t& qname,
    unsigned int arity,
    CompilerCB* ccb,
    const QueryLoc& loc,
    bool errIfContextDependent)
{
  std::map<zstring, zstring> modulesStack;
  
  ModulesInfo minfo(ccb);
  
  std::auto_ptr<TranslatorImpl> t(new TranslatorImpl(NULL,
                                                     ccb->theRootSctx,
                                                     ccb->theSctxMap.size(),
                                                     &minfo,
                                                     modulesStack,
                                                     false,
                                                     StaticContextConsts::xquery_version_unknown));
  
  return t->generate_literal_function(qname, arity, loc, errIfContextDependent);
}



} // namespace zorba
/* vim:set et sw=2 ts=2: */
