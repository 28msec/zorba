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
#include "context/standard_uri_resolvers.h"

#include "compiler/translator/translator.h"
#include "compiler/api/compilercb.h"
#include "compiler/api/compiler_api.h"
#include "compiler/codegen/plan_visitor.h"
#include "compiler/parser/util.h"
#include "compiler/parsetree/parsenodes.h"
#include "compiler/parser/parse_constants.h"
#include "compiler/parsetree/parsenode_visitor.h"
#include "compiler/expression/expr.h"
#include "compiler/expression/fo_expr.h"
#include "compiler/expression/var_expr.h"
#include "compiler/expression/flwor_expr.h"
#include "compiler/expression/path_expr.h"
#include "compiler/rewriter/framework/rewriter_context.h"
#include "compiler/rewriter/framework/rewriter.h"
#include "compiler/indexing/value_index.h"
#include "compiler/indexing/value_ic.h"

#include "context/statically_known_collection.h"

#include "system/globalenv.h"

#include "functions/library.h"
#include "functions/signature.h"
#include "functions/external_function_adapters.h"

#include "store/api/item.h"
#include "store/api/update_consts.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "runtime/api/plan_wrapper.h"

#include "debugger/zorba_debugger_commons.h"

using namespace std;

#define NODE_SORT_OPT

namespace zorba 
{

class ModulesInfo;


static expr_t translate_aux(
    const parsenode& root,
    static_context* rootSctx,
    short rootSctxId,
    ModulesInfo* minfo,
    set<string> mod_stack,
    bool isLibModule);

#ifndef NDEBUG

#define TRACE_VISIT()                                              \
  const QueryLoc& loc = v.get_location(); (void)loc;               \
                                                                   \
  if (Properties::instance()->traceTranslator())                   \
    cout << string(++print_depth, ' ') << TRACE << ", stk size "   \
         << nodestack.size() << ", tstk size: " << theTypeStack.size()   \
         << ", scope depth " << scope_depth << endl;


#define TRACE_VISIT_OUT()                                          \
  const QueryLoc& loc = v.get_location(); (void)loc;               \
                                                                   \
  if (Properties::instance()->traceTranslator())                   \
    cout << string(print_depth--, ' ') << TRACE << ", stk size: "  \
         << nodestack.size() << ", tstk size: " << theTypeStack.size()   \
         << ", scope depth " << scope_depth << endl;

#else

#define TRACE_VISIT()                                              \
  const QueryLoc& loc = v.get_location(); (void)loc;               \


#define TRACE_VISIT_OUT()                                          \
  const QueryLoc& loc = v.get_location(); (void)loc;               \

#endif


/*******************************************************************************
  Lookup in the sctx the function object for a function with a given prefix
  local name and arity. Return NULL if such a function is not found 
********************************************************************************/
#define LOOKUP_FN( pfx, local, arity ) (sctx_p->lookup_fn (pfx, local, arity))


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

#define DOT_VAR lookup_ctx_var(DOT_VARNAME, loc).getp()

#define DOT_REF new wrapper_expr(this->sctxid(), loc, DOT_VAR)


/*******************************************************************************

********************************************************************************/
static inline void checkNonUpdating(const expr* lExpr)
{
  if (lExpr != 0 && lExpr->is_updating())
    ZORBA_ERROR_LOC(XUST0001, lExpr->get_loc());
}


/*******************************************************************************

********************************************************************************/
template<class T> T& peek_stack(stack<T> &stk) 
{
  ZORBA_ASSERT(! stk.empty());
  return stk.top();
}


template <typename T> T pop_stack(stack<T> &stk) 
{
  T x = peek_stack(stk);
  stk.pop();
  return x;
}


template <typename T> T pop_stack(list<T> &stk) 
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



/*******************************************************************************
  Class to represent a vertex in the dependency graph among var and udfs decls
  in the prolog of a module. A vertex is represented as a pointer to either a
  var_expr (if var decl) or a function obj (if udf decl).
********************************************************************************/
class PrologGraphVertex
{
public:
  typedef enum { VAR, FUN } Kind;

  typedef union
  {
    const var_expr* var;
    const function* fun;
  } Key;

public:
  Key   theKey;
  Kind  theKind;

public:
  PrologGraphVertex() : theKind(VAR)
  {
    theKey.var = NULL;
  }

  PrologGraphVertex(const var_expr* v) : theKind(VAR)
  {
    theKey.var =v;
  }

  PrologGraphVertex(const function* f) : theKind(FUN)
  {
    theKey.fun = f;
  }

  bool isNull() const { return theKey.var == NULL; }

  void setNull() { theKey.var = NULL; }

  Kind getKind() const { return theKind; }

  const function* getFunction() const { return theKey.fun; }

  const var_expr* getVarExpr() const { return theKey.var; }

  bool operator==(const PrologGraphVertex& other) const
  {
    return (theKey.var == other.theKey.var);
  }
};


/*******************************************************************************
  Class to represent an edge in the dependency graph among var and udfs decls
  in the prolog of a module. An edge is represented as a pair of vertices, where
  the first vertex in the pair depends on the second vertex. 
********************************************************************************/
class PrologGraphEdge
{
public:
  std::pair<PrologGraphVertex, PrologGraphVertex> theEdge;

public:
  PrologGraphEdge() : theEdge() { }

  PrologGraphEdge(const PrologGraphVertex& v1, const PrologGraphVertex& v2)
    :
    theEdge(v1, v2)
  {
  }

  bool operator==(const PrologGraphEdge& other) const
  {
    return (theEdge.first == other.theEdge.first &&
            theEdge.second == other.theEdge.second);
  }

  bool startsAt(const PrologGraphVertex& v) const
  {
    return v == theEdge.first;
  }

  const PrologGraphVertex& getStart() const { return theEdge.first; }

  const PrologGraphVertex& getEnd() const { return theEdge.second; }
};


/*******************************************************************************

********************************************************************************/
class PrologGraph
{
private:
  static_context               * theModuleSctx;

  std::vector<PrologGraphEdge>   theEdges;

  std::vector<const var_expr*>   theVarDecls;
  std::vector<const function*>   theFuncDecls;

public:
  PrologGraph(static_context* sctx) : theModuleSctx(sctx) { }

  void addVarVertex(const var_expr* v) { theVarDecls.push_back(v); }

  void addFuncVertex(const function* v) { theFuncDecls.push_back(v); }

  void addEdge(const PrologGraphVertex& v1, const PrologGraphVertex& v2)
  {
    PrologGraphEdge edge(v1, v2);
    if (std::find(theEdges.begin(), theEdges.end(), edge) == theEdges.end())
      theEdges.push_back(edge);
  }

  void reorder_globals(std::list<global_binding>& prologVarBindings);
};


/*******************************************************************************
  This method is part of the mechanism for detecting cycles in the dependency
  graph among prolog variables. The method does not actually detect the cycles
  but re-orders the declarations of prolog vars (i.e., reorders theGlobalVars
  list) so that if var v2 depends on var v1, then v1 appears before v2 in the
  list (and as a result, v1 will be evaluated before v2 during runtime).

  Circular dependencies among prolog vars can appear only when udfs are invloved.
  Here is an example:
 
  declare variable $var := local:func1();

  declare function local:func1()
  {
    local:func2()
  };

  declare function local:func2()
  {
    local:func3()
  };

  declare variable $var2 := local:func2();

  declare function local:func3()
  {
    $var2
  };

  boolean($var)


  In this query, the following cycle exists : var2 --> func2 --> func3 --> var2
********************************************************************************/
void PrologGraph::reorder_globals(std::list<global_binding>& prologVarBindings)
{
  std::string moduleNS = theModuleSctx->get_module_namespace();
  std::string msg(" Cyclic dendencies found among the declaration in the prolog of ");
  if (!moduleNS.empty())
  {
    msg += "module ";
    msg += moduleNS;
  }
  else
  {
    msg += "the main module.";
  }

  // STEP 1: Floyd-Warshall transitive closure of edges starting from functions
  // At each substep we are adding fn2 -> fn1 -> var/fn dependencies. The resulting
  // graph has the following property: If there is a path P in the original graph
  // such that P starts at a udf node F, ends at a var node V and contains only
  // udf nodes in between, then in the augmented graph there is a direct edge
  // F --> V. As a result, to go from one variable to another, we never need to
  // cross 2 or more consequtive udf nodes.
  std::vector<const function*>::const_iterator f1Ite = theFuncDecls.begin();
  std::vector<const function*>::const_iterator f1End = theFuncDecls.end();
  for (; f1Ite != f1End; ++f1Ite)
  {
    const function* f1 = *f1Ite;

    std::vector<const function*>::const_iterator f2Ite = theFuncDecls.begin();
    std::vector<const function*>::const_iterator f2End = theFuncDecls.end();
    for (; f2Ite != f2End; ++f2Ite)
    {
      const function* f2 = *f2Ite;

      // if f2 depends on f1, then f2 depends on every var/udf that f1 depends on.
      ulong numEdges = theEdges.size();
      for (ulong i = 0; i < numEdges; ++i)
      {
        const PrologGraphEdge& edge = theEdges[i];

        if (edge.startsAt(f1))
        {
          addEdge(f2, edge.getEnd());
        }
      }
    }
  }

  // STEP 2: Add "1-step" var -> fn -> var/fn dependencies. Steps 1 & 2 together
  // guarantee that if there is a path P from variable v1 to variable v2 in the
  // original graph, then in the augmented graph there is a path P' from v1 to
  // v2 such that P' does not contain any udfs. Therefore, the augmented graph
  // contains a subgraph VG that consists of edges among variables only and which
  // which reflects the same (direct and transitive) dependencies among vars as
  // the original graph.

  ulong numEdges = theEdges.size();

  std::vector<const var_expr*>::const_iterator vIte = theVarDecls.begin();
  std::vector<const var_expr*>::const_iterator vEnd = theVarDecls.end();
  for (; vIte != vEnd; ++vIte)
  {
    const var_expr* v1 = *vIte;

    for (ulong i = 0; i < numEdges; ++i)
    {
      const PrologGraphEdge& edge1 = theEdges[i];

      if (edge1.startsAt(v1))
      {
        const PrologGraphVertex& f = edge1.getEnd();

        if (f.getKind() == PrologGraphVertex::FUN)
        {
          for (ulong j = 0; j < numEdges; ++j)
          {
            const PrologGraphEdge& edge2 = theEdges[j];

            if (edge2.startsAt(f))
            {
              const PrologGraphVertex& v2 = edge2.getEnd();

              if (v2.getKind() == PrologGraphVertex::VAR)
              {
                if (v2 == v1)
                {
                  ZORBA_ERROR_DESC(XQST0054, msg);
                }

                addEdge(v1, v2);
              }
            }
          }
        }
      }
    }
  }

  numEdges = theEdges.size();

  // STEP 3 Check for cycles (TODO: use faster algorithm)
  std::vector<PrologGraphEdge> edges;
  std::set<const var_expr*> varDecls;

  for (ulong i = 0; i < numEdges; ++i)
  {
    const PrologGraphEdge& edge = theEdges[i];

    if (edge.getStart().getKind() == PrologGraphVertex::VAR &&
        edge.getEnd().getKind() == PrologGraphVertex::VAR)
    {
      edges.push_back(edge);
      varDecls.insert(edge.getStart().getVarExpr());
      varDecls.insert(edge.getEnd().getVarExpr());
    }
  }

  while (!edges.empty())
  {
    ulong numEdges = edges.size();
    const var_expr* var = NULL;

    std::set<const var_expr*>::iterator vIte = varDecls.begin();
    std::set<const var_expr*>::iterator vEnd = varDecls.end();
   
    for (; vIte != vEnd; ++vIte)
    {
      ulong j;
      for (j = 0; j < numEdges; ++j)
      {
        if (edges[j].getStart() == *vIte)
          break;
      }

      if (j == numEdges)
      {
        var = *vIte;
        varDecls.erase(vIte);
        break;
      }
    }

    if (var == NULL)
    {
      ZORBA_ERROR_DESC(XQST0054, msg);
    }

    for (ulong j = 0; j < numEdges; ++j)
    {
      if (edges[j].getEnd() == var)
      {
        edges.erase(edges.begin() + j);
        --numEdges;
        --j;
      }
    }
  }

  // STEP 4: topologically sort global vars.
  // Implemented using non-recursive (stack-based) DFS traversal. This algorithm
  // unfortunately does not detect cycles.
  // Note that steps 1 & 2 are required: we cannot sort the entire set of prolog
  // vars + udfs, because functions are allowed to be mutually recursive.
  std::vector<const var_expr*> topsorted_vars;  // dependencies first
  std::set<const var_expr*> visited;

  std::stack<std::pair<ulong, const var_expr*> > todo;  // format: action code + var_expr

  vIte = theVarDecls.begin();
  for (; vIte != vEnd; ++vIte)
  {
    todo.push(std::pair<ulong, const var_expr*>(1, (*vIte)));
  }

  while (! todo.empty()) 
  {
    const var_expr* var = todo.top().second;
    ulong action = todo.top().first;
    todo.pop();

    switch (action) 
    {
    case 0:  // finish notification
    {
      topsorted_vars.push_back(var);
      break;
    }
    case 1:  // visit request
    {
      if (visited.find(var) == visited.end()) 
      {
        visited.insert(var);
        todo.push(std::pair<ulong, const var_expr*>(0, var));

        for (ulong i = 0; i < numEdges; ++i)
        {
          const PrologGraphEdge& edge = theEdges[i];

          if (edge.startsAt(var))
          {
            const PrologGraphVertex& v2 = edge.getEnd();

            if (v2.getKind() == PrologGraphVertex::VAR)
            {
              todo.push(std::pair<ulong, const var_expr*>(1, v2.getVarExpr()));
            }
          }
        }
      }
      break;
    }
    default: 
      assert(false);
    }
  }

  // STEP 5: reorder thePrologVars according to topological order
  std::map<const var_expr*, global_binding> gvmap;
  std::list<global_binding>::iterator bindIte = prologVarBindings.begin();
  for (; bindIte != prologVarBindings.end(); ++bindIte)
  {
    gvmap[(*bindIte).first] = *bindIte;
  }

  prologVarBindings.clear();

  for (std::vector<const var_expr*>::iterator i = topsorted_vars.begin();
       i != topsorted_vars.end(); ++i) 
  {
    std::map<const var_expr*, global_binding>::iterator p = gvmap.find(*i);
    if (p != gvmap.end())
      prologVarBindings.push_back((*p).second);
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

  init_exprs    : Contains the initializing expr for each prolog var in each
                  module participating in the compilation (see method
                  wrap_in_globalvar_assigh())

********************************************************************************/
class ModulesInfo 
{
public:
  CompilerCB                * theCCB;
  hashmap<static_context_t>   mod_sctx_map;
  hashmap<string>             mod_ns_map;
  checked_vector<expr_t>      init_exprs;
  auto_ptr<static_context>    globals;

public:
  ModulesInfo(CompilerCB* topCompilerCB)
    :
    theCCB(topCompilerCB),
    globals(static_cast<static_context *>
            (topCompilerCB->theRootSctx->get_parent())->create_child_context())
  {
  }
};



/*******************************************************************************

  A new instance of TranslatorImpl is created for the translation of each
  module participating in a query. The instance is destroyed when the translation
  of the associated module is finished.

  theCCB               : The control block for the whole query. (see
                         compiler/api/compilercb.h). 

  theModulesInfo       : Pointer to the unique ModulesInfo instance (see class
                         ModulesInfo above).

  theModulesStack      : A set containing the ns uris of all the modules in the
                         chain of module imports from this module up to the main
                         module. It is used to check that there are no cycles
                         in a chain of module imports.

  theImportedModules   : A set containing the ns uris for all the modules 
                         directly imported by this module. Used to check that
                         the same module is not imported twice by this module.

  theModuleNamespace   : If this translator is working on a library module,
                         theModuleNamespace is the namespace uri of that module.
  theModulePrefix      : If this translator is working on a library module, 
                         theModulePrefix is the prefix associated with the ns
                         uri of that module.

  theBuiltInModules    : Set of ns uris for all internal pre-defined modules. 
                         If a module (i.e. a .xq file), containing external
                         function declarations, is shipped with Zorba, this
                         namespace must not be registered in this set.

  theImportedSchemas   : Set of ns uris for all schemas directly imported by
                         this module. Used to check that the same schema is not
                         imported twice by this module.

  theCurrSctxId        : The numeric id of the last sctx that was added to
                         theSctxMap of the query (see api/xqueryimpl.h). Every
                         time an expr is created, the current value of theCurSctxId
                         is stored in the expr obj, so that each expr will be
                         executed in the appropriate sctx.

  sctx_p               : The "current" static context node. It is initialized
                         with the root static context of the associated module.

  theSctxList:         : A list of static contexts which need to be kept alive
                         during the translation of a module only. It's managed
                         in push_scope and pop_scope. In DEBUGGER mode, this
                         list remains empty.

  theSctxIdStack       : In non-DEBUGGER mode, this stack remains empty.

  export_sctx          : In case this is a library module translator, export_sctx
                         is populated with the variable and function declarations
                         that are exported by the module, i.e., the var and udf
                         declarations that appear in the prolog of this module.
                         The export_sctx is created by the importing module,
                         populated by the imported module, and then merged by
                         the importing module into its own sctx. export_sctx is
                         "shared" between importing and imported modules via the
                         theModulesInfo->mod_sctx_map. export_sctx is needed
                         because module import is not transitive: If M1 imports
                         M2 and M2 imports M3, then the vars and functions are
                         seen by M2, but not by M3. This means, that the regular
                         root sctx S2 of M2 will contain the decls from both M2
                         and M3. So, M1 should not import S2 into its own sctx
                         S1. Instead, we create ES2 for M2 and register in there
                         the decls of M2 only; then, we import ES2 to S1.
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

  thePrologVars :
  ---------------

  thePrologVars vector contains one entry for each var V declared in the prolog
  of this module. The entry maps the var_expr for V to the expr E that initializes
  V (E is NULL for vars without init expr). At the end of each module translation,
  the method wrap_in_globalvar_assign() creates appropriate initialization exprs
  for each var in thePrologVars and registers them in theModulesInfo->init_exprs,
  so that they will be incorporated in the whole query plan at the end of the
  translation of the root module.

  thePrologGraph :
  ---------------

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
  respectively. It is used in building the thePrologGraph: if the theCurrentPrologVFDecl string
  is not the empty, then the translator knows that it is in the scope of a var
  or function decl, and if that declaration references another var V or calls
  another function F, then it creates a dependency between the var or function
  specified by theCurrentPrologVFDecl and V or F.

  theTempVarCounter :
  -----------------

  Counter used to generate names for internally generated variables. The names
  are unique within this translator.

  nodestack            : If E is the expr that is currently being built, then
                         nodestack contains all the ancestors (or ancestor
                         place-holdres) of E in the expr tree.

  theTypeStack         : Stack of the static types for some of the exprs in the
                         nodestack.

  theFlworClausesStack :

  theNodeSortStack     :

  theIndexDecl         : Used during the translation of an index declaration to
                         hold the ValueIndex obj.
  theIsInIndexDomain   : Set to true just before translating the domain expr, and
                         set back to false right after the translation of the
                         domain expr is finished. It is used to check that the
                         domain expr does not reference any external context item.

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

********************************************************************************/
class TranslatorImpl : public parsenode_visitor
{
protected:
  RootTypeManager                    & theRTM;

  CompilerCB                         * theCCB;

  ModulesInfo                        * theModulesInfo;
  set<string>                          theModulesStack;
  set<string>                          theImportedModules;
  string                               theModuleNamespace;
  string                               theModulePrefix;
  set<string>                          theBuiltInModules;

  set<string>                          theImportedSchemas;

  short                                theCurrSctxId;

  static_context                     * theRootSctx;

  static_context                     * sctx_p;

  std::vector<static_context_t>        theSctxList;

  stack<short>                         theSctxIdStack;

  static_context                     * export_sctx;

  rchandle<namespace_context>          ns_ctx;

  uint32_t                             print_depth;
  int                                  scope_depth;

  varref_t                             theDotVar;

  xqtref_t                             ctx_item_type;

  list<global_binding>                 thePrologVars;

  PrologGraph                          thePrologGraph;
  PrologGraphVertex                    theCurrentPrologVFDecl;

  int                                  theTempVarCounter;

  stack<expr_t>                        nodestack;

  stack<xqtref_t>                      theTypeStack; 

  std::vector<flwor_clause_t>          theFlworClausesStack;

  stack<NodeSortInfo>                  theNodeSortStack;

  list<function *>                     fn_decl_stack;

  ValueIndex_t                         theIndexDecl;
  bool                                 theIsInIndexDomain;

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

  function                           * op_concatenate;
  function                           * op_enclosed;
  function                           * var_decl; 
  function                           * var_set;
  function                           * var_get;
  function                           * var_exists;
  
public:

TranslatorImpl(
    static_context* rootSctx,
    short rootSctxId,
    ModulesInfo* minfo,
    set<string> mod_stack,
    bool isLibModule)
  :
  theRTM(GENV_TYPESYSTEM),
  theCCB(minfo->theCCB),
  theModulesInfo(minfo),
  theModulesStack(mod_stack),
  theCurrSctxId(rootSctxId),
  theRootSctx(rootSctx),
  sctx_p(rootSctx),
  export_sctx(NULL),
  ns_ctx(new namespace_context(sctx_p)),
  print_depth(0),
  scope_depth(0),
  thePrologGraph(rootSctx),
  theTempVarCounter(1),
  theIsInIndexDomain(false),
  hadBSpaceDecl(false),
  hadBUriDecl(false),
  hadConstrDecl(false),
  hadCopyNSDecl(false),
  hadDefNSDecl(false),
  hadEmptyOrdDecl(false),
  hadOrdModeDecl(false),
  hadRevalDecl(false)
{
  xquery_fns_def_dot.insert ("string-length");
  xquery_fns_def_dot.insert ("normalize-space");
  xquery_fns_def_dot.insert ("root");
  xquery_fns_def_dot.insert ("base-uri");
  xquery_fns_def_dot.insert ("namespace-uri");
  xquery_fns_def_dot.insert ("local-name");
  xquery_fns_def_dot.insert ("name");
  xquery_fns_def_dot.insert ("string");
  
  op_concatenate = GET_BUILTIN_FUNCTION(OP_CONCATENATE_N);
  assert(op_concatenate != NULL);

  op_enclosed = GET_BUILTIN_FUNCTION(OP_ENCLOSED_1);
  assert(op_enclosed != NULL);

  var_decl = GET_BUILTIN_FUNCTION(OP_VAR_DECLARE_1);
  var_set = GET_BUILTIN_FUNCTION(OP_VAR_ASSIGN_1);
  var_get = GET_BUILTIN_FUNCTION(OP_VAR_REF_1);
  var_exists = GET_BUILTIN_FUNCTION(OP_VAR_EXISTS_1);
  assert(var_decl != NULL && var_set != NULL && var_get != NULL && var_exists != NULL);

  theBuiltInModules.insert (ZORBA_OP_NS);
  theBuiltInModules.insert (ZORBA_REST_FN_NS);
  theBuiltInModules.insert (ZORBA_MATH_FN_NS);
  theBuiltInModules.insert (ZORBA_NODEREF_FN_NS);
  theBuiltInModules.insert (ZORBA_ALEXIS_FN_NS);
  theBuiltInModules.insert (ZORBA_JSON_FN_NS);
  theBuiltInModules.insert (ZORBA_JSON_ML_FN_NS);
  theBuiltInModules.insert (ZORBA_FOP_FN_NS);
  
  ctx_item_type = GENV_TYPESYSTEM.ITEM_TYPE_ONE;
}


/*******************************************************************************
  Pop the top n exprs from the nodestack and return the last expr that was popped.
********************************************************************************/
expr_t pop_nodestack(int n = 1) 
{
  ZORBA_ASSERT(n >= 0);

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
var_expr_t pop_nodestack_var() 
{
  expr_t e = pop_nodestack();
  assert (e == NULL || e->get_expr_kind() == var_expr_kind);
  return static_cast<var_expr *> (e.getp());
}


/*******************************************************************************
  Return rchandle to the expr at the top of the nodestack, or NULL if the
  nodestack is empty.
********************************************************************************/
expr_t peek_nodestk_or_null() 
{
  return (nodestack.empty()) ? expr_t (NULL) : peek_stack(nodestack);
}


/*******************************************************************************
  Check if the top expr in thenodestack is an axis_step, and if so return
  rchandle to it (but do not pop). Otherwise, raise error.
********************************************************************************/
rchandle<axis_step_expr> expect_axis_step_top() 
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
  return pop_stack(theTypeStack); 
}


/*******************************************************************************

********************************************************************************/
inline bool inLibraryModule()
{
  return export_sctx != NULL;
}


/*******************************************************************************

********************************************************************************/
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
  sctx_p = sctx_p->create_child_context(); 
 
  if (theCCB->theDebuggerCommons != NULL) 
  {
    // in debug mode, we remember all static contexts
    // this allows the debugger to introspect (during runtime)
    // all variables in scope
    theSctxIdStack.push(sctxid());
    theCurrSctxId = theCCB->theSctxMap->size() + 1;
    (*theCCB->theSctxMap)[sctxid()] = sctx_p; 
  }
  else
  {
    // in non-debug mode, we need to make sure that the scoped
    // contexts are kept around for the compilation of this module.
    // The static context available at runtime will be the root context
    // in which the module is compiled. Keeping all contexts around during
    // runtime seems to be overhead.
    theSctxList.push_back(sctx_p);
  }
  ++scope_depth;
}


/*******************************************************************************
  Make the parent of the current sctx be the current sctx for the current module.
********************************************************************************/
void pop_scope()
{
  if (theCCB->theDebuggerCommons != NULL) 
  {
    theCurrSctxId = theSctxIdStack.top();
    sctx_p = (*theCCB->theSctxMap)[sctxid()];
    theSctxIdStack.pop();
  }
  else
  {
    // pop one scope, howerver the static context is kept around in the theSctxList
    static_context* parent = (static_context *) sctx_p->get_parent();
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
xqpString tempname() 
{
  return "$$temp" + to_string(theTempVarCounter++);
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
  varref_t e = new var_expr(sctxid(), loc, kind, qname);

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
  return create_var(loc, qname, kind, type);
}
  

/*******************************************************************************
  Create a var_expr for an internal variable with a given kind.
********************************************************************************/
varref_t tempvar(const QueryLoc& loc, var_expr::var_kind kind)
{
  xqpString lname(tempname());
  return create_var(loc, lname, kind);
}


/*******************************************************************************
  Create a binding in the given sctx between a var qname item and a var_expr.
  Raise error if a var with the same expanded qname item is already in the given
  sctx obj.
********************************************************************************/
void bind_var(var_expr_t e, static_context* sctx) 
{
  assert(sctx != NULL);

  const store::Item* qname = e->get_name();

  if (! sctx->bind_var(qname, e.getp()))
  {
    if(e->get_kind() == var_expr::let_var)
    {
      ZORBA_ERROR_LOC_PARAM(XQST0039, e->get_loc(), qname->getStringValue(), "");
    }
    else
    {
      ZORBA_ERROR_LOC_PARAM(XQST0049, e->get_loc(), qname->getStringValue(), "");
    }
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
    string varname,
    var_expr::var_kind kind,
    xqtref_t type = NULL) 
{
  var_expr_t e = create_var(loc, varname, kind, type);
  bind_var(e, sctx_p);
  return e;
}


var_expr_t bind_var(
    const QueryLoc& loc,
    store::Item* varname,
    var_expr::var_kind kind,
    xqtref_t type = NULL) 
{
  varref_t e = create_var(loc, varname, kind, type);
  bind_var(e, sctx_p);
  return e;
}


/*******************************************************************************
  Create a var_expr for a variable with a given qname item, kind, and type.
  Then, create a binding in the given sctx between the var qname item and the
  var_expr. Finally, push the var_expr to the nodestack. Raise error if a var
  with the same expanded qname is already in the given context.
********************************************************************************/
varref_t bind_var_and_push(
    const QueryLoc& loc,
    store::Item* varname,
    var_expr::var_kind kind,
    xqtref_t type = NULL) 
{
  varref_t e = bind_var(loc, varname, kind, type);
  nodestack.push(&*e);
  return e;
}


varref_t bind_var_and_push(
    const QueryLoc& loc,
    string varname,
    var_expr::var_kind kind,
    xqtref_t type = NULL) 
{
  return bind_var_and_push(loc, sctx_p->lookup_var_qname(varname, loc), kind, type);
}


/*******************************************************************************
  Lookup variable by qname (expanded or not). Search starts from the "current"
  ctx and moves upwards the ancestor path until the first instance (if any) of
  the variable is found.

  The first method raises error if var not found, the other 2 methods return NULL.
********************************************************************************/
varref_t lookup_ctx_var(xqp_string name, const QueryLoc& loc) 
{
  expr* ve = sctx_p->lookup_var(name);
  if (ve != NULL)
    return (var_expr *) ve;

  if (theIsInIndexDomain)
  {
    ZORBA_ERROR_LOC_PARAM(XDST0032_INDEX_REFERENCES_CTX_ITEM, loc, 
                          theIndexDecl->getName()->getStringValue(), "");
  }
  else
  {
    ZORBA_ERROR_LOC_PARAM(XPDY0002, loc, name, "");
  }
}


var_expr* lookup_var(string varname) 
{
  return static_cast<var_expr *>(sctx_p->lookup_var(varname));
}


var_expr* lookup_var(const store::Item* varname) 
{
  return static_cast<var_expr *>(sctx_p->lookup_var(varname));
}



/*******************************************************************************
  Create a binding in the given sctx obj between the given (function qname item,
  arity) pair and the given function object. Raise error if such a binding
  exists already in the sctx.
********************************************************************************/
void bind_udf(
    store::Item_t qname,
    function* f,
    int nargs,
    static_context* sctx,
    const QueryLoc& loc) 
{
  if (! sctx->bind_fn(qname, f, nargs))
  {
    ZORBA_ERROR_LOC_PARAM(XQST0034, loc,
                          qname->getStringValue(),
                          loc.getFilenameBegin());
  }
}
  

/*******************************************************************************
  Create a binding between the given (function qname item, arity) pair and the
  given function object. The binding is created in (a) the current sctx of this 
  module, (b) the query-level sctx that gathers all declaration of functions and
  variables from all modules, and (c) the export_sctx (if any). Raise error if 
  such a binding exists already in any of these sctxs.
********************************************************************************/
void bind_udf(store::Item_t qname, function* f, int nargs, const QueryLoc& loc) 
{
  bind_udf(qname, f, nargs, sctx_p, loc);
  bind_udf(qname, f, nargs, theModulesInfo->globals.get (), loc);

  if (export_sctx != NULL) 
  {
    bind_udf(qname, f, nargs, export_sctx, loc);
  }
}
  

/*******************************************************************************
  Create an fn:concatenate() expr
********************************************************************************/
fo_expr* create_seq(const QueryLoc& loc) 
{
  return fo_expr::create_seq(sctxid(), loc);
}


/*******************************************************************************

********************************************************************************/
void normalize_fo(fo_expr* foExpr)
{
  const signature& sign = foExpr->get_signature();

  ulong n = foExpr->num_args();

  const function* func = foExpr->get_func();

  if (func->getKind() == FunctionConsts::FN_ZORBA_DDL_PROBE_INDEX_RANGE_N &&
      (n == 0 || (n - 1) % 6 != 0))
  {
    const store::Item* qname = NULL;

    if (n > 0)
      qname = foExpr->get_arg(0)->getQName(sctx_p);

    if (qname != NULL)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS,
                            foExpr->get_loc(),
                            qname->getStringValue()->c_str(), "");
    }
    else
    {
      ZORBA_ERROR_LOC_DESC(XDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS,
                           foExpr->get_loc(),
                           "Invalid number of arguments in index probe");
    }
  }

  for(ulong i = 0; i < n; ++i) 
  {
    expr::expr_t argExpr = foExpr->get_arg(i, true);

    xqtref_t paramType;

    if (func->getKind() == FunctionConsts::FN_ZORBA_DDL_PROBE_INDEX_POINT_N)
    {
      if (i == 0)
        paramType = sign[i];
      else
        paramType = theRTM.ANY_ATOMIC_TYPE_ONE;
    }
    else if (func->getKind() == FunctionConsts::FN_ZORBA_DDL_PROBE_INDEX_RANGE_N)
    {
      if (i == 0)
        paramType = sign[i];
      else if (i % 6 == 1 || i % 6 == 2)
        paramType = theRTM.ANY_ATOMIC_TYPE_QUESTION;
      else
        paramType = theRTM.BOOLEAN_TYPE_ONE;
    }
    else
    {
      paramType = sign[i];
    }

    xqtref_t param_prime_type = TypeOps::prime_type(*paramType);

    if (TypeOps::is_subtype(*param_prime_type, *theRTM.ANY_ATOMIC_TYPE_ONE)) 
    {
      argExpr = wrap_in_atomization(argExpr);
      argExpr = wrap_in_type_promotion(argExpr, paramType);
    }
    else
    {
      argExpr = wrap_in_type_match(argExpr, paramType);
    }

    foExpr->set_arg(i, argExpr);
  }
}


/*******************************************************************************
  Wrap the given expr in an fn:data() function
********************************************************************************/
expr_t wrap_in_atomization(expr* e) 
{
  if (e->is_sequential())
  {
    const QueryLoc& loc = e->get_loc();

    rchandle<flwor_expr> flworExpr = new flwor_expr(sctxid(), loc, false);

    let_clause_t lc = wrap_in_letclause(e);

    expr_t retExpr = new fo_expr(sctxid(),
                                 loc,
                                 GET_BUILTIN_FUNCTION(FN_DATA_1),
                                 lc->get_var());

    flworExpr->add_clause(lc);

    flworExpr->set_return_expr(retExpr);

    return flworExpr;
  }
  else
  {
    return new fo_expr(sctxid(),
                       e->get_loc(),
                       GET_BUILTIN_FUNCTION(FN_DATA_1),
                       e);
  }
}


/*******************************************************************************

********************************************************************************/
expr_t wrap_in_type_promotion(expr_t e, xqtref_t type)
{
  return new promote_expr(sctxid(), e->get_loc(), e, type);
}


/*******************************************************************************

********************************************************************************/
expr_t wrap_in_type_match(expr_t e, xqtref_t type, XQUERY_ERROR errorCode = XPTY0004)
{
  // treat_expr should be avoided for updating expressions too,
  // but in that case "type" will be item()* anyway
  return (TypeOps::is_subtype(*theRTM.ITEM_TYPE_STAR, *type) ?
          e :
          new treat_expr(sctxid(), e->get_loc(), e, type, errorCode));
}



/*******************************************************************************

********************************************************************************/
expr_t wrap_in_bev(expr_t e)
{
  fo_expr* fo = new fo_expr(sctxid(),
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

  rchandle<fo_expr> dos = new fo_expr(sctxid(),
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

  return new let_clause(sctx_p, sctxid(), e->get_loc(), lv, e.getp());
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
  assert(fv->get_kind () == var_expr::for_var);
  if (pv != NULL)
  {
    assert(pv->get_kind() == var_expr::pos_var);
  }

  return new for_clause(sctx_p, sctxid(), e->get_loc(), fv, e, pv);
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
  the following flwor expr is built:

  let $lv := domExpr
  return retExpr

********************************************************************************/
rchandle<flwor_expr> wrap_in_let_flwor(expr_t domExpr, varref_t lv, expr_t retExpr) 
{
  rchandle<flwor_expr> fe = new flwor_expr(sctxid(), lv->get_loc(), false);

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

  rchandle<flwor_expr> flworExpr = new flwor_expr(sctxid(), loc, false);

  if (withContextSize) 
  {
    // create a LET var equal to the seq returned by the input epxr
    let_clause_t lcInputSeq = wrap_in_letclause(inputExpr);

    // compute the size of the input seq
    rchandle<fo_expr> countExpr = new fo_expr(sctxid(),
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


/*******************************************************************************
  In this expression branch, we create the debugger expressions.
  Furthermore, we create an entry for all expressions in the map
  of breakable expressions. This is done here, in order to be able,
  to set breakpoints of expressions which are not translated at the
  beginning (e.g. inside functions).
********************************************************************************/
void wrap_in_debugger_expr(expr_t& aExpr) 
{
  if (theCCB->theDebuggerCommons != NULL) 
  {
    DebugLocation_t lLocation;
    std::auto_ptr<debugger_expr> lExpr(new debugger_expr(sctxid(),
                                                         aExpr->get_loc(), 
                                                         aExpr,
                                                         thePrologVars));

    lLocation.theFileName = aExpr->get_loc().getFilename();
    lLocation.theLineNumber = aExpr->get_loc().getLineno();
    lLocation.theQueryLocation = aExpr->get_loc();
    theCCB->theDebuggerCommons->theLocationMap.insert(
      std::pair<DebugLocation_t, bool>(lLocation, false));

    // retrieve all variables that are in the current scope
    typedef std::vector<var_expr_t> VarExprVector;
    VarExprVector lAllInScopeVars;
    sctx_p->getVariables(lAllInScopeVars);

    // for each var, create a eval_var and add it to
    // the debugger expression
    for (VarExprVector::iterator lIter = lAllInScopeVars.begin();
         lIter != lAllInScopeVars.end(); 
         ++lIter) 
    {
      store::Item* lVarname = (*lIter)->get_name();
      if (std::string(lVarname->getStringValue()->c_str()) == "$$dot") 
      {
        continue;
      }

      var_expr_t ve = create_var(lLocation.theQueryLocation,
                                 lVarname,
                                 var_expr::eval_var,
                                 NULL).dyn_cast<var_expr>();

      var_expr* lVe = lookup_var(ve->get_name());

      expr_t val = new wrapper_expr(sctxid(),
                                    lLocation.theQueryLocation,
                                    rchandle<expr>(lVe));
      lExpr->add_var(eval_expr::eval_var(&*ve, val));
    }

    aExpr = lExpr.release();
  }
}


/*******************************************************************************
  Collect the var_exprs for all variables that (a) are defined by some clause
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
      const WindowClause& wc = *static_cast<const WindowClause *>(&c);
      vars.insert(lookup_var(wc.get_var()->get_varname()));
      for (int j = 1; j >= 0; j--) 
      {
        const FLWORWinCond* cond = &*wc[j];
        if (cond != NULL) 
        {
          const WindowVars* wv = &*cond->get_winvars();
          if (wv != NULL) 
          {
            if (! wv->get_next ().empty ())
              vars.insert (lookup_var (wv->get_next()));
            if (! wv->get_prev ().empty ())
              vars.insert (lookup_var (wv->get_prev()));
            if (! wv->get_curr ().empty ())
              vars.insert (lookup_var (wv->get_curr()));
            if (wv->get_posvar () != NULL)
              vars.insert(lookup_var(wv->get_posvar()->get_varname()));
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
  module and put these exprs in theModulesInfo->init_exprs. Then create a sequential
  expr with its children being all the init exprs in theModulesInfo->init_exprs  plus
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
      ++i)
  {
    declare_var(*i, theModulesInfo->init_exprs);
  }

  expr_t preloadedInitExpr = static_cast<static_context*>(sctx_p->get_parent())->
                             get_query_expr();

  if (!theModulesInfo->init_exprs.empty() || preloadedInitExpr != NULL) 
  {
    sequential_expr* seqExpr =
    new sequential_expr(sctxid(), e->get_loc(), theModulesInfo->init_exprs, e);

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

     In this case, the ctxvar-exists function checks if a value has been assigned
     to the extranal value via the c++ api. If so, this value overrides the
     initializing expr in the prolog.

  3. ctxvar-declare(varName)

  4. nothing

     In this case, the variable must be initialized via the c++ api, and it is 
     this intialization that will add an entry for the var in the dynamic ctx.

  If the var declaration includes a type declaration, then the following expr
  is also created and added to stmts:

  treat(ctxvariable(varName), type)
********************************************************************************/
void declare_var(const global_binding& b, std::vector<expr_t>& stmts) 
{
  var_expr_t var = b.first;
  expr_t initExpr = b.second;

  ulong sctxid = this->sctxid();
  const QueryLoc& loc = var->get_loc();

  xqpStringStore dot (".");

  expr_t qnameExpr = new const_expr(sctxid,
                                    loc,
                                    var->get_name()->getStringValue()->equals(&dot) ?
                                    "." : dynamic_context::var_key(&*var));

  expr_t declExpr = new fo_expr(sctxid, loc, var_decl, qnameExpr->clone());
  
  if (initExpr != NULL) 
  {
    if (initExpr->is_updating())
      ZORBA_ERROR_LOC(XUST0001, initExpr->get_loc());

    initExpr = new fo_expr(sctxid, loc, var_set, qnameExpr->clone(), initExpr);

    initExpr = new sequential_expr(sctxid, var->get_loc(), declExpr, initExpr);

    if (b.is_extern()) 
    {
      expr_t existsExpr = new fo_expr(sctxid, loc, var_exists, qnameExpr->clone());

      initExpr = new if_expr(sctxid, loc, sctx_p, existsExpr, create_seq(loc), initExpr);
    }

    stmts.push_back(initExpr);
  }
  else 
  {
    if (! b.is_extern())
      stmts.push_back(declExpr);
  }

  xqtref_t varType = var->get_type();

  if (varType != NULL && (b.is_extern() || b.second != NULL)) 
  {
    // check type for vars that are external or have an init expr
    expr_t getExpr = new fo_expr(sctxid, loc, var_get, qnameExpr->clone());

    stmts.push_back(new treat_expr(sctxid, loc, getExpr, varType, XPTY0004));
  }
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


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Module, VersionDecl, MainModule, LibraryModule, ModuleDecl                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  [1] Module ::= 	VersionDecl? (LibraryModule | MainModule)
********************************************************************************/
void* begin_visit(const Module& v) 
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const Module& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();
}


/******************************************************************************
  [2] VersionDecl ::= XQUERY ENCODING STRING_LITERAL SEMI |
                      XQUERY VERSION STRING_LITERAL SEMI |
                      XQUERY VERSION STRING_LITERAL ENCODING STRING_LITERAL SEMI
********************************************************************************/
void* begin_visit(const VersionDecl& v) 
{
  TRACE_VISIT();
  if (! xqp_string (v.get_encoding ()).matches ("^[A-Za-z]([A-Za-z0-9._]|[-])*$", ""))
    ZORBA_ERROR_LOC (XQST0087, loc);

  sctx_p->set_xquery_version(v.get_version());
  if (sctx_p->xquery_version() == StaticContextConsts::xquery_version_unknown)
    ZORBA_ERROR_LOC(XQST0031, loc);

  return no_state;
}

void end_visit(const VersionDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  [3] MainModule ::= Prolog  QueryBody | QueryBody
********************************************************************************/
void* begin_visit(const MainModule & v) 
{
  TRACE_VISIT();

  theDotVar = bind_var(loc, DOT_VARNAME, var_expr::prolog_var, ctx_item_type);
  
  return no_state;
}

void end_visit(const MainModule & v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  [4] LibraryModule ::= ModuleDecl  Prolog
********************************************************************************/
void* begin_visit(const LibraryModule& v) 
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const LibraryModule& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  // Note: There is no real reason to put the expr returned by 
  // wrap_in_globalvar_assign() in the nodestack. The only reason is for the
  // translate_aux() function to be able to pick that expr from the stack in
  // order to print it.
  nodestack.push(wrap_in_globalvar_assign(create_seq(loc)));
}


/******************************************************************************
  [5] ModuleDecl ::= MODULE NAMESPACE  NCNAME  EQ  URI_LITERAL  SEMI
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
    ZORBA_ERROR_LOC (XQST0088, loc);

  if (theModulePrefix == "xml" || theModulePrefix == "xmlns")
    ZORBA_ERROR_LOC (XQST0070, loc);

  sctx_p->bind_ns(theModulePrefix, theModuleNamespace);

  static_context_t lTmpCtx;
  bool found = theModulesInfo->mod_sctx_map.get(sctx_p->entity_retrieval_url(), lTmpCtx);
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

  [6d] VFO_Decl ::= VarDecl | ContextItemDecl | FunctionDecl | CollectionDecl 
                  | IndexDecl | OptionDecl
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
  [6a] SIND_DeclList ::= SIND_Decl Separator | SIND_DeclList SIND_Decl Separator
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
void* begin_visit(const BoundarySpaceDecl& v) 
{
  TRACE_VISIT();
  CHK_SINGLE_DECL (hadBSpaceDecl, XQST0068);
  sctx_p->set_boundary_space_mode(v.get_boundary_space_mode());
  return NULL;
}

void end_visit(const BoundarySpaceDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  [14] OrderingModeDecl ::= DECLARE_ORDERING  ( ORDERED | UNORDERED )
********************************************************************************/
void* begin_visit(const OrderingModeDecl& v) 
{
  TRACE_VISIT();
  CHK_SINGLE_DECL (hadOrdModeDecl, XQST0065);
  sctx_p->set_ordering_mode(v.get_mode());
  return NULL;
}


void end_visit(const OrderingModeDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  [15] EmptyOrderDecl ::= DECLARE_DEFAULT_ORDER  EMPTY_GREATEST |
                          DECLARE_DEFAULT_ORDER  EMPTY_LEAST
********************************************************************************/
void* begin_visit(const EmptyOrderDecl& v) 
{
  TRACE_VISIT();
  CHK_SINGLE_DECL (hadEmptyOrdDecl, XQST0069);
  sctx_p->set_order_empty_mode(v.get_mode());
  return no_state;
}

void end_visit (const EmptyOrderDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  [16] CopyNamespacesDecl ::= DECLARE_COPY_NAMESPACES PreserveMode COMMA InheritMode

  [19] PreserveMode ::= "preserve" | "no-preserve"
  [20] InheritMode ::=  "inherit" | "no-inherit"
********************************************************************************/
void* begin_visit(const CopyNamespacesDecl& v) 
{
  TRACE_VISIT();
  CHK_SINGLE_DECL(hadCopyNSDecl, XQST0055);
  return no_state;
}

void end_visit(const CopyNamespacesDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();
 sctx_p->set_inherit_mode(v.get_inherit_mode ());
 sctx_p->set_preserve_mode(v.get_preserve_mode ());
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
void* begin_visit(const DecimalFormatNode& v) 
{
  // cout << "Got DecimalFormat declaration: " << std::endl;
  TRACE_VISIT();

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

void end_visit(const DecimalFormatNode& v, void* /*visit_state*/) 
{
  // std::cout << "end_visit() Got DecimalFormat declaration: " << std::endl;
  TRACE_VISIT_OUT();
}


/*******************************************************************************
  [21] DefaultCollationDecl ::=	DECLARE_DEFAULT_COLLATION  URI_LITERAL
********************************************************************************/
void* begin_visit(DefaultCollationDecl const& v) 
{
  TRACE_VISIT();

  string uri = v.get_collation();
  sctx_p->set_default_collation_uri(uri);
  return NULL;
}

void end_visit(const DefaultCollationDecl& v, void* /*visit_state*/) 
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
void* begin_visit(DefaultNamespaceDecl const& v) 
{
  TRACE_VISIT();

  switch (v.get_mode()) 
  {
  case ParseConstants::ns_element_default:
    sctx_p->set_default_elem_type_ns(v.get_default_namespace());
    break;
  case ParseConstants::ns_function_default:
    sctx_p->set_default_function_ns(v.get_default_namespace().c_str(),
                                    &v.get_location());
    break;
  }
  return NULL;
}

void end_visit(const DefaultNamespaceDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();
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

  if (! theImportedSchemas.insert(target_ns).second)
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
  
  InternalSchemaURIResolver* lSchemaResolver = GENV.getSchemaURIResolver();
  
  try 
  {
    std::string lSchemaUri;
    lSchemaUri = lSchemaResolver->resolve(lTargetNamespace, sctx_p,
      lAtURIList);

    // Create a Schema obj and register it in the typemanger, if the typemanager
    // does not have a schema obj already
    CTXTS->initializeSchema();
    Schema* schema_p = CTXTS->getSchema();

    // Make Xerxes load and parse the xsd file and create a Xerces
    // representaton of it.
    schema_p->registerXSD(lTargetNamespace->getStringValue()->c_str(),
      lSchemaUri, loc);
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
void* begin_visit(const ModuleImport& v) 
{
  TRACE_VISIT();
  return no_state;
}


void end_visit(const ModuleImport& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  string pfx = v.get_prefix();
  string target_ns = v.get_uri();

  // The namespace prefix specified in a module import must not be xml or xmlns
  // [err:XQST0070]
  if (pfx == "xml" || pfx == "xmlns")
    ZORBA_ERROR_LOC(XQST0070, loc);

  // The first URILiteral in a module import must be of nonzero length [err:XQST0088]
  if (target_ns.empty())
    ZORBA_ERROR_LOC(XQST0088, loc);

  // It is a static error [err:XQST0047] if more than one module import in a
  // Prolog specifies the same target namespace
  if (! theImportedModules.insert(target_ns).second)
    ZORBA_ERROR_LOC(XQST0047, loc);

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

  rchandle<URILiteralList> ats = v.get_uri_list();

  // Handle pre-defined modules
  if (ats == NULL && theBuiltInModules.find(target_ns) != theBuiltInModules.end())
    return;

  // Create a list of absolute uris identifying the locations of modules in
  // the target ns. If there are no "at" clauses, use the target namespace.
  vector<xqpStringStore_t> lURIs;
  if (ats == NULL || ats->size() == 0)
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

  InternalModuleURIResolver* lStandardModuleResolver = GENV.getModuleURIResolver();

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
    set<string> mod_stk1 = theModulesStack;
    if (! mod_stk1.insert(resolveduri->str()).second)
      ZORBA_ERROR_LOC (XQST0073, loc);
    
    string imported_ns; // the target namespace of the imported module
    static_context_t imported_sctx = NULL;

    // Check whether we have already imported a module from the current location
    // uri. If so, check that the target ns of what we imported before is the
    // same as what we are trying to import now.
    if (theModulesInfo->mod_ns_map.get(resolveduri->str(), imported_ns)) 
    {
      bool found = theModulesInfo->mod_sctx_map.get(resolveduri->str(), imported_sctx);
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
      auto_ptr<istream> modfile;
      
      modfile.reset(lStandardModuleResolver->resolve(aturiitem, sctx_p, &lFileUri));

      if (modfile.get () == NULL || ! *modfile) 
      {
        ZORBA_ERROR_LOC_PARAM(XQST0059, loc, resolveduri, target_ns);
      }

      // Get the query-level sctx. This is the user-specified sctx (if any) or
      // the zorba default (root) sctx (if no user-specified sctx).
      static_context_t independent_sctx = 
      static_cast<static_context *>(theCCB->theRootSctx->get_parent());

      // Create the root sctx for the imported module as a child of the
      // query-level sctx. Register this sctx in the query-level sctx map.
      static_context* moduleRootSctx = independent_sctx->create_child_context();
      moduleRootSctx->set_entity_retrieval_url(resolveduri->str());
      ulong moduleRootSctxId = theCCB->theSctxMap->size() + 1;
      (*theCCB->theSctxMap)[moduleRootSctxId] = moduleRootSctx;

      // Create an sctx where the imported module is going to register all the
      // variable and function declarations that appear in its prolog. After the
      // translation of the imported module is done, this sctx will be merged
      // with the sctx of the importing module.
      imported_sctx = independent_sctx->create_child_context();
      imported_sctx->set_module_namespace(imported_ns);

      // Register the imported_sctx in theModulesInfo->mod_sctx_map so that it is
      // accessible by both the importing and the imported modules.
      theModulesInfo->mod_sctx_map.put(resolveduri->str(), imported_sctx);

      // Parse the imported module
      XQueryCompiler xqc(theCCB);
      xqpString lFileName(aturiitem->getStringValue());
      if (lFileUri.size() != 0) 
      {
        lFileName = lFileUri.c_str();
      }
      rchandle<parsenode> ast = xqc.parse(*modfile, lFileName);

      // Get the target namespace that appears in the module declaration
      // of the imported module and check that this ns is the same as the
      // target ns in the module import statement.
      // Also make sure that the imported module is a library module
      LibraryModule* mod_ast = dynamic_cast<LibraryModule *>(&*ast);
      if (mod_ast == NULL)
        ZORBA_ERROR_LOC_PARAM(XQST0059, loc, resolveduri, target_ns);

      imported_ns = mod_ast->get_decl()->get_target_namespace();
      
      if (imported_ns.empty())
        ZORBA_ERROR_LOC(XQST0088, loc);

      if (imported_ns != target_ns)
        ZORBA_ERROR_LOC_PARAM(XQST0059, loc, resolveduri, target_ns);

      moduleRootSctx->set_module_namespace(imported_ns);

      // translate the imported module
      translate_aux(*ast,
                    moduleRootSctx, 
                    moduleRootSctxId,
                    theModulesInfo,
                    mod_stk1,
                    true);

      // Register the mapping between the current location uri and the
      // target namespace.
      theModulesInfo->mod_ns_map.put(resolveduri->str(), imported_ns);

      // If we compile in debug mode, we add the namespace uri into a map, that
      // allows the debugger to set breakpoints at a namespace uri and line
      // number
      if (theCCB->theDebuggerCommons) 
      {
        theCCB->theDebuggerCommons->addModuleUriMapping(imported_ns,
                                                           lFileUri.c_str());
      }
    }

    // Merge the exported sctx of the imported module into the sctx of the
    // current module. Note: We catch duplicate functions / vars in 
    // theModulesInfo->globals. We can safely ignore the return value. We might even
    // be able to assert() here (not sure though).
    sctx_p->import_module(imported_sctx.getp(), loc);

  } // for (vector<xqpStringStore_t>::iterator lIter = lURIs.begin();
}


/*******************************************************************************
  [6b] VFO_DeclList ::= VFO_Decl Separator | VFO_DeclList VFO_Decl Separator

  [6d] VFO_Decl ::= VarDecl | ContextItemDecl | FunctionDecl | IndexDecl | OptionDecl
********************************************************************************/
void* begin_visit(const VFO_DeclList& v) 
{
  TRACE_VISIT();

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

    for (vector<rchandle<Param> >::const_iterator it = params->begin();
         it != params->end();
         ++it)
    {
      const Param* param = (*it).getp();
      const SequenceType* param_type = param->get_typedecl().getp();
      if (param_type == NULL) 
      {
        arg_types.push_back(GENV_TYPESYSTEM.ITEM_TYPE_STAR);
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
    else if (func_decl->get_type() == ParseConstants::fn_extern_update)
    {
      return_type = theRTM.EMPTY_TYPE;
    }

    // Expand the function qname (error is raised if qname resolution fails).
    store::Item_t qname = sctx_p->lookup_fn_qname(func_decl->get_name()->get_prefix(),
                                                  func_decl->get_name()->get_localname(),
                                                  func_decl->get_name()->get_location());
    {
      xqp_string ns = qname->getNamespace();

      // function must be declared in a non-NULL namespace
      if(ns.empty())
        ZORBA_ERROR_LOC (XQST0060, loc);

      // Function must not be in any of the reserved namespaces
      if (ns == XQUERY_FN_NS || ns == XML_NS || ns == XML_SCHEMA_NS || ns == XSI_NS)
        ZORBA_ERROR_LOC_PARAM(XQST0045, func_decl->get_location(),
                              qname->getLocalName()->str(), "");

      // In a module, all exports must be inside the target ns
      if (! theModuleNamespace.empty() && ns != theModuleNamespace)
        ZORBA_ERROR_LOC(XQST0048, loc);
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
      // 1. lookup if the function is a built-in function
      f = sctx_p->lookup_resolved_fn(qname->getNamespace(),
                                     qname->getLocalName(),
                                     nargs);
      if (f.getp() != 0) 
      {
        // in debug mode, we make sure that the types of the functions
        // and the return type are equal to the one that is declared in
        // the module
        const signature& s = f->get_signature();
        if (!sig.equals(s)) 
        {
          ZORBA_ERROR_LOC_DESC_OSS(XQP0028_FUNCTION_IMPL_NOT_FOUND,
              loc,
              "The signature of the (registered) function ("
              << qname->getNamespace()->str() 
              << ":" << qname->getLocalName()->str()
              << ") does not match the signature of the function that is "
              << "declared in the module.");
        }
        // return because we don't add already built-in functions to the
        // static context
        continue;
      }

      // 2. if no built-in function is there, we check the static context
      // to see if the user has registered an external function
      StatelessExternalFunction* ef = 0;
      try 
      {
        ef = sctx_p->lookup_stateless_external_function(qname->getNamespace(),
                                                        qname->getLocalName());
      }
      catch (error::ZorbaError& e) 
      {
        ZORBA_ERROR_LOC_DESC(e.theErrorCode,
                             loc, e.theDescription);
      }
      // The external function must be registered already in the static context
      // via the StaticContextImpl::registerExternalModule() user api.
      if (ef == NULL) 
      {
        ZORBA_ERROR_LOC_PARAM(XQP0028_FUNCTION_IMPL_NOT_FOUND,
                              loc,
                              qname->getNamespace()->str(),
                              qname->getLocalName()->str());
      }

      ZORBA_ASSERT(ef != NULL);

      bool updating = (func_decl->get_type() == ParseConstants::fn_extern_update);

      f = new stateless_external_function_adapter(sig, ef, updating, qname->getPrefix());
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


void end_visit(const VFO_DeclList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  thePrologGraph.reorder_globals(thePrologVars);
}


/*******************************************************************************
  [13] OptionDecl ::= DECLARE_OPTION  QNAME  STRING_LITERAL
********************************************************************************/
void* begin_visit(const OptionDecl& v) 
{
  TRACE_VISIT();

  //check if namespace for option is valid
  rchandle<QName> qn = v.get_qname();
  xqpString option_ns = sctx_p->lookup_ns(qn->get_prefix(), loc);

  // ignore if an error occurs
  sctx_p->bind_option(option_ns, qn->get_localname(), v.get_val());

  return no_state;
}

void end_visit(const OptionDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();
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
void* begin_visit(const VarDecl& v) 
{
  TRACE_VISIT();

  store::Item_t qnameItem = sctx_p->lookup_var_qname(v.get_varname(), loc);
  var_expr_t ve;

  if (v.is_global()) 
  {
    ve = create_var(loc, qnameItem, var_expr::prolog_var);

    thePrologGraph.addVarVertex(ve);
    theCurrentPrologVFDecl = PrologGraphVertex(ve);
  }
  else
  {
    ve = create_var(loc, qnameItem, var_expr::local_var);

    // TODO: create dep graph for local vars too
  }

  nodestack.push(ve);
  return no_state;
}


void end_visit(const VarDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  if (v.is_global())
    theCurrentPrologVFDecl.setNull();

  expr_t initExpr = (v.get_initexpr() == NULL ? expr_t(NULL) : pop_nodestack());

  var_expr_t ve = pop_nodestack();

  // The declared type of a global or external is never tightened based on
  // type inference because globals are mutable.
  xqtref_t type;
  if (v.get_typedecl() != NULL)
  {
    type = pop_tstack();

    ve->set_type(type);
  }

  // Put a mapping between the var name and the var_expr in the local sctx.
  // Raise error if var name exists already in local sctx obj.
  bind_var(ve, sctx_p);

  if (v.is_global()) 
  {
    // All vars declared in a module must be in the same namespace as the module
    if (! theModuleNamespace.empty() &&
        ve->get_name()->getNamespace()->str() != theModuleNamespace)
      ZORBA_ERROR_LOC(XQST0048, loc);

    // Make sure that there is no other prolog var with the same name in any of
    // modules transalted so far.
    bind_var(ve, theModulesInfo->globals.get());

    // If this is a library module, register the var in the exported sctx as well.
    if (export_sctx != NULL)
      bind_var(ve, export_sctx);

    thePrologVars.push_back(global_binding(ve, initExpr, v.is_extern()));
  }
  else
  {
    nodestack.push(ve.cast<expr>());
    nodestack.push(initExpr);
  }
}


/*******************************************************************************
  [29] ContextItemDecl ::= "declare" "context" "item" ("as" ItemType)?
                           ((":=" VarValue) |
                            ("external" (":=" VarDefaultValue)?))
********************************************************************************/
void* begin_visit(const CtxItemDecl& v) 
{
  TRACE_VISIT();

  if (sctx_p->xquery_version() <= StaticContextConsts::xquery_version_1_0)
    ZORBA_ERROR_LOC (XPST0003, loc);

  return no_state;
}

void end_visit(const CtxItemDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  expr_t ctx_item_default;
  if (v.get_expr() != NULL)
    ctx_item_default = pop_nodestack();

  if (v.get_type () != NULL)
    ctx_item_type = pop_tstack();

  if (v.get_type() != NULL || v.get_expr() != NULL) 
  {
    store::Item_t dotname;
    varref_t var = create_var (loc, ".", var_expr::prolog_var, ctx_item_type);
    global_binding b (var, ctx_item_default, true);

    declare_var(b, theModulesInfo->init_exprs);
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
void* begin_visit(const FunctionDecl& v) 
{
  TRACE_VISIT();

  push_scope();

  // Get function obj out of function qname (will raise error if prefix in qname
  // is not bound to a namespace).
  function* f = sctx_p->lookup_fn(v.get_name()->get_prefix(),
                                  v.get_name()->get_localname(),
                                  v.get_param_count());

  thePrologGraph.addFuncVertex(f);
  theCurrentPrologVFDecl = PrologGraphVertex(f);

  fn_decl_stack.push_front(f);

  return no_state;
}


void end_visit(const FunctionDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  theCurrentPrologVFDecl.setNull();

  pop_stack(fn_decl_stack);

  expr_t body;
  ParseConstants::function_type_t lFuncType = v.get_type();
  bool is_external = (lFuncType == ParseConstants::fn_extern ||
                      lFuncType == ParseConstants::fn_extern_update ||
                      lFuncType == ParseConstants::fn_extern_sequential);
  if (! is_external)
    body = pop_nodestack();

  if (v.get_return_type() != NULL)
    pop_tstack();

  // If function has any params, they have been wraped in a flwor expr. Set the
  // return clause of the flwor to the body expr of the function, and then make
  // this flwor be the actual body of the function.
  int nargs = v.get_param_count();
  vector<varref_t> args;
  if (nargs > 0) 
  {
    rchandle<flwor_expr> flwor = pop_nodestack().dyn_cast<flwor_expr>();
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
      ZORBA_ERROR_LOC_DESC_OSS(XPST0003, loc,
                               "Only a sequential function can have a body that "
                               << "is sequential expression");
    }

    // Under section 2.2.2 "Category Rules", it states: If the body of a
    // sequential function is a Block it must be either a sequential or
    // simple expression."
    // TODO: the error code has not yet been decided by the w3c
    if ( lFuncType == ParseConstants::fn_sequential && body->is_updating() ) 
    {
      ZORBA_ERROR_LOC_DESC_OSS(XPTY0004, loc,
                               "A sequential function cannot have a body that "
                               << "returns a pending update list");
    }

    if (lFuncType == ParseConstants::fn_read) 
    {
      if (body->is_updating())
        ZORBA_ERROR_LOC(XUST0001, loc);
    }
    else if (lFuncType == ParseConstants::fn_update) 
    {
      if (! body->is_updating_or_vacuous())
        ZORBA_ERROR_LOC(XUST0002, loc);
    } 

    user_function* udf = dynamic_cast<user_function *>(
                         LOOKUP_FN(v.get_name()->get_prefix(),
                                   v.get_name()->get_localname(),
                                   nargs));
    ZORBA_ASSERT(udf != NULL);

    // Optimize the function body. This has to be done here because
    // we have the correct static context here (udfs declared in a library module
    // must be compiled in the contex tof that module).
    xqtref_t returnType = udf->get_signature().return_type();

    if (TypeOps::is_builtin_simple(*returnType)) 
    {
      body = wrap_in_atomization(body);
      body = wrap_in_type_promotion(body, returnType);
    }
    else 
    {
      body = wrap_in_type_match(body, returnType);
    }

    if (theCCB->theConfig.translate_cb != NULL)
      theCCB->theConfig.translate_cb(&*body, v.get_name()->get_qname());

    if (theCCB->theConfig.opt_level == CompilerCB::config::O1) 
    {
      RewriterContext rCtx(theCCB, body);
      GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rCtx);
      body = rCtx.getRoot();

      if (theCCB->theConfig.optimize_cb != NULL)
        theCCB->theConfig.optimize_cb(&*body, v.get_name()->get_qname());
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
    nodestack.push(new flwor_expr(sctxid(), loc, false));
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


/*******************************************************************************
  [*] CollectionDecl ::= "declare" CollProperties "collection" QName 
                         ("as" CollectionTypeDecl)?
                         ("with" NodeModifier "nodes")? 

  [*] CollProperties ::= ("const" | "mutable" | "append-only" | "queue" |
                          "ordered" | "unordered")*

  [*] NodeModifier ::= ("read-only" | "mutable")

  [*] CollectionTypeDecl ::= KindTest OccurenceIndicator? 
********************************************************************************/
void* begin_visit(const CollectionDecl& v)
{
  TRACE_VISIT();
 
  return no_state;
}

void end_visit(const CollectionDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  // a collection declaration must allways be in a library module
  if (!inLibraryModule())
  {
    ZORBA_ERROR_LOC(XDST0003_COLLECTION_DECL_IN_MAIN_MODULE, v.get_location());
  }

  const QName* lName = v.getName();

  // Expand the collection qname (error is raised if qname resolution fails).
  store::Item_t lExpandedQName = sctx_p->lookup_fn_qname(lName->get_prefix(),
                                                         lName->get_localname(),
                                                         lName->get_location());
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
    lNodeType = TypeOps::prime_type(*lCollectionType);
    quant = lCollectionType->get_quantifier();
  }

  // Get the order and update properties of the collection
  StaticContextConsts::declaration_property_t lUpdateMode = v.getUpdateMode();
  StaticContextConsts::declaration_property_t lOrderMode = v.getOrderMode();

  if (lOrderMode == StaticContextConsts::decl_unordered &&
      (lUpdateMode == StaticContextConsts::decl_queue ||
       lUpdateMode == StaticContextConsts::decl_append_only))
  {
    ZORBA_ERROR_LOC_PARAM(XDST0005_COLLECTION_PROPERTIES_CONFLICT, loc,
                          lName->get_qname(), "");
  }

  // Get the node modifier
  StaticContextConsts::node_modifier_t lNodeModifier = 
    (v.getNodeModifier() == 0 ?
     StaticContextConsts::mutable_node :
     v.getNodeModifier()->getModifier());

  // Create the collection object and register it in the static context
  StaticallyKnownCollection_t lColl = new StaticallyKnownCollection(
                                            lExpandedQName,
                                            lUpdateMode,
                                            lOrderMode,
                                            lNodeModifier,
                                            lNodeType,
                                            lCollectionType);

  sctx_p->bind_collection(lColl, v.get_location());

  assert(export_sctx);
  export_sctx->bind_collection(lColl, v.get_location());

  // Create an IC to check that the cardinality of the collection matches its
  // declared type.
  if (quant != TypeConstants::QUANT_STAR)
  {
    // TODO
  }
}


/***************************************************************************//**
  NodeModifier ::=  ("read-only" | "mutable " )
********************************************************************************/
void* begin_visit(const NodeModifier& v)
{ 
  TRACE_VISIT();
  return no_state; 
}

void end_visit(const NodeModifier& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();
}


/***************************************************************************//**
  IndexDecl ::= "declare" IndexPropertyList "index" QName
                "on" "nodes" IndexDomainExpr "by" IndexKeyList

  IndexPropertyList := ("unique" | "non" "unique" |
                        "value" "range" | "value" "equality" | 
                        "automatically" "maintained" | "manually" "maintained")*

  IndexDomainExpr := PathExpr

  IndexKeyList := IndexKeySpec+

  IndexKeySpec := PathExpr AtomicType IndexKeyOrderModifier

  AtomicType := QName

  IndexKeyOrderModifier := ("ascending" | "descending")? ("collation" UriLiteral)?

  Translation of an index declaration involves the creation and setting-up of
  a ValueIndex obj (see compiler/indexing/value_index.h) and the creation in
  the current sctx (which is the root sctx of the current module) of a binding
  between the index uri and this ValueIndex obj.
********************************************************************************/
void* begin_visit(const IndexDecl& v) 
{
  TRACE_VISIT();

  const QName* qname = v.getName();

  if (!inLibraryModule())
  {
    ZORBA_ERROR_LOC_PARAM(XDST0023_INDEX_DECL_IN_MAIN_MODULE, v.get_location(), 
                          qname->get_qname(), "");
  }

  // Expand the index qname (error is raised if qname resolution fails).
  store::Item_t qnameItem = sctx_p->lookup_fn_qname(qname->get_prefix(),
                                                    qname->get_localname(),
                                                    qname->get_location());

  ValueIndex_t index = new ValueIndex(sctx_p, loc, qnameItem);
  index->setUnique(v.isUnique());
  index->setMethod(v.isOrdered() ? ValueIndex::TREE : ValueIndex::HASH);
  if (v.isAutomatic())
    index->setMaintenanceMode(ValueIndex::REBUILD);

  theIndexDecl = index;
  theIsInIndexDomain = true;

  return no_state;
}

void end_visit(const IndexDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  ValueIndex_t index = theIndexDecl;
  theIndexDecl = NULL;

  index->analyze();

  // Register the index in the sctx of the current module. Raise error if such
  // a binding exists already in the sctx.
  sctx_p->bind_index(index->getName(), index, loc);

  // If this is a library module, register the index in the exported sctx as well.
  if (export_sctx != NULL)
    export_sctx->bind_index(index->getName(), index, loc);
}


/***************************************************************************//**
  IndexKeyList ::= IndexKeySpec (COMMA IndexKeySpec)*
********************************************************************************/
void* begin_visit(const IndexKeyList& v) 
{
  TRACE_VISIT();

  theIsInIndexDomain = false;

  ValueIndex* index = theIndexDecl;

  expr_t domainExpr = pop_nodestack();

  if (!domainExpr->is_simple())
  {
    ZORBA_ERROR_LOC_PARAM(XDST0033_INDEX_NON_SIMPLE_EXPR, domainExpr->get_loc(),
                          index->getName()->getStringValue(), "");
  }

  domainExpr = wrap_in_type_match(domainExpr, 
                                  theRTM.ANY_NODE_TYPE_STAR,
                                  XDTY0010_INDEX_DOMAIN_TYPE_ERROR);

  domainExpr = new fo_expr(sctxid(),
                           domainExpr->get_loc(),
                           GET_BUILTIN_FUNCTION(OP_DISTINCT_NODES_1),
                           domainExpr);

  std::string msg = "domain expr for index " + index->getName()->getStringValue()->str();

  if (theCCB->theConfig.translate_cb != NULL)
    theCCB->theConfig.translate_cb(domainExpr.getp(), msg);

  // Optimize the domain expr
  if (theCCB->theConfig.opt_level == CompilerCB::config::O1) 
  {
    RewriterContext rCtx(theCCB, domainExpr);
    GENV_COMPILERSUBSYS.getDefaultOptimizingRewriter()->rewrite(rCtx);
    domainExpr = rCtx.getRoot();

    if (theCCB->theConfig.optimize_cb != NULL)
      theCCB->theConfig.optimize_cb(&*domainExpr, msg);
  }

  index->setDomainExpr(domainExpr);

  push_scope();

  index->setDomainVariable(bind_var(loc, DOT_VARNAME, var_expr::for_var));

  index->setDomainPositionVariable(bind_var(loc, DOT_POS_VARNAME, var_expr::pos_var));

  return no_state;
}

void end_visit(const IndexKeyList& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  ulong numColumns = v.size();

  std::vector<expr_t> keyExprs(numColumns);
  std::vector<xqtref_t> keyTypes(numColumns);
  std::vector<OrderModifier> keyModifiers(numColumns);

  ValueIndex* index = theIndexDecl;

  for(int i = numColumns - 1; i >= 0; --i) 
  {
    const IndexKeySpec* keySpec = v.getKeySpec(i);
    const OrderCollationSpec* collationSpec = keySpec->getCollationSpec();

    xqtref_t type = pop_tstack();

    if (TypeOps::is_equal(*type, *theRTM.ANY_ATOMIC_TYPE_ONE) ||
        TypeOps::is_equal(*type, *theRTM.UNTYPED_ATOMIC_TYPE_ONE))
    {
      ZORBA_ERROR_LOC_PARAM(XDST0027_INDEX_BAD_KEY_TYPE, keySpec->get_location(),
                            index->getName()->getStringValue(), "");
    }

    if (index->getMethod() == ValueIndex::TREE &&
        (TypeOps::is_subtype(*type, *theRTM.QNAME_TYPE_ONE) ||
         TypeOps::is_subtype(*type, *theRTM.NOTATION_TYPE_ONE) ||
         TypeOps::is_subtype(*type, *theRTM.BASE64BINARY_TYPE_ONE) ||
         TypeOps::is_subtype(*type, *theRTM.HEXBINARY_TYPE_ONE) ||
         TypeOps::is_subtype(*type, *theRTM.GYEAR_MONTH_TYPE_ONE) ||
         TypeOps::is_subtype(*type, *theRTM.GYEAR_TYPE_ONE) ||
         TypeOps::is_subtype(*type, *theRTM.GMONTH_TYPE_ONE) ||
         TypeOps::is_subtype(*type, *theRTM.GMONTH_DAY_TYPE_ONE) ||
         TypeOps::is_subtype(*type, *theRTM.GDAY_TYPE_ONE)))
    {
      ZORBA_ERROR_LOC_PARAM(XDST0027_INDEX_BAD_KEY_TYPE, keySpec->get_location(),
                            index->getName()->getStringValue(), "");
    }

    keyTypes[i] = type;

    string collation = sctx_p->default_collation_uri();

    if (collationSpec != NULL)
    {
      collation = collationSpec->get_uri();

      if (! sctx_p->has_collation_uri(collation))
        ZORBA_ERROR_LOC(XQST0076, keySpec->get_location());
    }

    keyModifiers[i].theAscending = true;
    keyModifiers[i].theEmptyLeast = true;
    keyModifiers[i].theCollation = collation;

    expr_t keyExpr = pop_nodestack();

    keyExpr = wrap_in_atomization(keyExpr);
    keyExpr = wrap_in_type_match(keyExpr, type, XDTY0011_INDEX_KEY_TYPE_ERROR);

    std::ostringstream msg;
    msg << "key expr " << i << " for index " << index->getName()->getStringValue()->str();

    if (theCCB->theConfig.translate_cb != NULL)
      theCCB->theConfig.translate_cb(keyExpr.getp(), msg.str());

    // Normalize and optimize the key expr
    //normalize_expr_tree(msg.str().c_str(), theCCB, keyExpr, NULL);

    if (theCCB->theConfig.opt_level == CompilerCB::config::O1) 
    {
      RewriterContext rCtx(theCCB, keyExpr);
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
  IndexKeySpec ::= ExprSingle TypeDeclaration? 
                              ("empty" ("greatest" | "least"))?
                              ("collation" UriLiteral)?
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
  setting-up of a ValueIndex obj (see indexing/value_index.h) and the creation
  in the current sctx (which is the root sctx of the current module) of a
  binding between the index uri and this ValueIndex obj.
*******************************************************************************/
void* begin_visit(const IntegrityConstraintDecl& v) 
{
  TRACE_VISIT();

  if (!inLibraryModule())
  {
    ZORBA_ERROR_LOC_PARAM(XDST0044_IC_DECL_IN_MAIN_MODULE, v.get_location(), 
                          v.getName()->get_qname(), "");
  }

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
    expr_t qnameStrExpr = new const_expr(sctxid(), loc, 
                                         ic.getCollName()->get_qname() );
      
    string prefixStr = ic.getCollName()->get_prefix();
    xqp_string uriStr = sctx_p->lookup_ns(prefixStr);
      

    expr_t uriStrExpr = new const_expr(sctxid(), loc, uriStr );
      
    // fn:QName("uri", "example:coll1")
    fo_expr_t qnameExpr = new fo_expr(sctxid(), loc,
                                      GET_BUILTIN_FUNCTION(FN_QNAME_2),
                                      uriStrExpr, qnameStrExpr);

    // dc:collection(xs:QName("example:coll1"))
    function* fn_collection = sctx_p->lookup_resolved_fn(
                                                         xqp_string("http://www.zorba-xquery.com/modules/xqddf"), 
                                                         xqp_string("collection"), 1);
    ZORBA_ASSERT(fn_collection != NULL);
    std::vector<expr_t> argColl;      
    argColl.push_back(qnameExpr.getp());
    fo_expr_t collExpr = new fo_expr(sctxid(), loc, fn_collection, argColl);
    
    // $x 
    const QName* varQName = ic.getCollVarName();
    var_expr_t varExpr = bind_var(loc, varQName->get_qname(), 
                                  var_expr::let_var, NULL);

    // let $x := dc:collection(xs:QName("example:coll1")) 
    let_clause* lc = new let_clause(sctx_p,
                                    sctxid(),
                                    loc,
                                    varExpr,
                                    collExpr.getp());

    flwor_expr_t flworExpr = new flwor_expr(sctxid(), loc, false);
    flworExpr->add_clause(lc);     
    // flworExpr-> return clause to be set in end_visitor

    nodestack.push(flworExpr.getp());      
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
    expr_t qnameStrExpr = new const_expr(sctxid(), loc,
                                         ic.getCollName()->get_qname() );
    
    string prefixStr = ic.getCollName()->get_prefix();
    xqp_string uriStr = sctx_p->lookup_ns(prefixStr);

    expr_t uriStrExpr = new const_expr(sctxid(), loc, uriStr );

    // fn:QName("org-uri", "org:employees")
    fo_expr_t qnameExpr = new fo_expr(sctxid(), loc,
                                      GET_BUILTIN_FUNCTION(FN_QNAME_2),
                                      uriStrExpr, qnameStrExpr);

    // dc:collection(xs:QName("org:employees"))
    function* fn_collection = sctx_p->lookup_resolved_fn(
                                                         xqp_string("http://www.zorba-xquery.com/modules/xqddf"),
                                                         xqp_string("collection"),
                                                         1);
    ZORBA_ASSERT(fn_collection != NULL);
    std::vector<expr_t> argColl;
    argColl.push_back(qnameExpr.getp());
    fo_expr_t collExpr = new fo_expr(sctxid(), loc, fn_collection, argColl);
    
    // $x 
    const QName* varQName = ic.getNodeVarName();
    store::Item_t varItem = sctx_p->lookup_fn_qname(varQName->get_prefix(),
                                                    varQName->get_localname(), varQName->get_location());
    
    
    // every $x_ in $x satisfies exists ...
    // every is implemented as a flowr expr
    push_scope();
    flwor_expr_t evFlworExpr = new flwor_expr(sctxid(), loc, false);
    evFlworExpr->set_return_expr(new const_expr(sctxid(), loc, true));
    
    // $x_ in dc:collection( xs:QName("org:employees") )      
    var_expr_t evVarExpr = bind_var(loc, 
                                    varQName->get_qname()/*varItem.getp()*/, 
                                    var_expr::for_var, NULL);
    
    // maybe make one more collExpr?
    evFlworExpr->add_clause(wrap_in_forclause(collExpr.getp(), evVarExpr, NULL));
    
    pop_scope();
    // end every
    
    // let $x := dc:collection(xs:QName("org:employees")) 
    //   return 
    var_expr_t varExpr = bind_var(loc, varQName->get_qname()
                                  /*varItem.getp()*/, var_expr::let_var, 
                                  NULL);
    
    let_clause* letClause = new let_clause(sctx_p,
                                           sctxid(),
                                           loc,
                                           varExpr,
                                           collExpr.getp());
    flwor_expr_t flworExpr = new flwor_expr(sctxid(), loc, false);
    
    
    
    flworExpr->add_clause(letClause);      
    // flworExpr->set_return_expr( andExpr ); done in end_visit
    
    // push evFlworExpr because where clause must be set
    nodestack.push(evFlworExpr.getp());
    // push the top expresion
    nodestack.push(flworExpr.getp());
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
    expr_t qnameStrExpr = new const_expr(sctxid(), loc, 
                                         ic.getCollName()->get_qname() );
    
    string prefixStr = ic.getCollName()->get_prefix();
    xqp_string uriStr = sctx_p->lookup_ns(prefixStr);
    
    expr_t uriStrExpr = new const_expr(sctxid(), loc, uriStr );
    
    // fn:QName("org-uri", "org:transactions")
    fo_expr_t qnameExpr = new fo_expr(sctxid(), loc,
                                      GET_BUILTIN_FUNCTION(FN_QNAME_2),
                                      uriStrExpr, qnameStrExpr);
    
    // dc:collection(xs:QName("org:transactions"))
    function* fn_collection = sctx_p->lookup_resolved_fn(
                                                         xqp_string("http://www.zorba-xquery.com/modules/xqddf"), 
                                                         xqp_string("collection"), 
                                                         1);
    ZORBA_ASSERT(fn_collection != NULL);
    std::vector<expr_t> argColl;      
    argColl.push_back(qnameExpr.getp());
    fo_expr_t collExpr = new fo_expr(sctxid(), loc, fn_collection, argColl);
    
    // every $x_ in $x satisfies exists ...
    // every is implemented as a flowr expr
    //push_scope();
    flwor_expr_t evFlworExpr = new flwor_expr(sctxid(), loc, false);
    evFlworExpr->set_return_expr(new const_expr(sctxid(), loc, true));
    
    // $x 
    const QName* varQName = ic.getCollVarName();
    
    // $x_ in dc:collection( xs:QName("org:employees") )      
    var_expr_t evVarExpr = bind_var(loc, varQName->get_qname(), 
                                    var_expr::for_var, NULL);
    
    // maybe make one more collExpr?
    evFlworExpr->add_clause(wrap_in_forclause(collExpr.getp(), evVarExpr, 
                                              NULL));
    
    //pop_scope();
    // end every
    nodestack.push(evFlworExpr.getp());
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
    expr_t toQnameStrExpr = new const_expr(sctxid(), loc, 
                                           ic.getToCollName()->get_qname() );
    string toPrefixStr = ic.getToCollName()->get_prefix();
    xqp_string toUriStr = sctx_p->lookup_ns(toPrefixStr);
    
    expr_t toUriStrExpr = new const_expr(sctxid(), loc, toUriStr );
      
    // xs:QName("org:employees")
    fo_expr_t toQnameExpr = new fo_expr(sctxid(), loc,
                                        GET_BUILTIN_FUNCTION(FN_QNAME_2),
                                        toUriStrExpr, toQnameStrExpr);
    
    // dc:collection(xs:QName("org:employees"))
    function* toFnCollection = sctx_p->lookup_resolved_fn(
                                                          xqp_string("http://www.zorba-xquery.com/modules/xqddf"), 
                                                          xqp_string("collection"), 
                                                          1);
    ZORBA_ASSERT(toFnCollection != NULL);
    std::vector<expr_t> toArgColl;      
    toArgColl.push_back(toQnameExpr.getp());
    fo_expr_t toCollExpr = new fo_expr(sctxid(), loc, toFnCollection, 
                                       toArgColl);
    
    // some $y in dc:collection( xs:QName("org:employees") )
    // satisfies ... eq ...
    // implemented using flowr
    flwor_expr_t someFlworExpr = new flwor_expr(sctxid(), loc, false);
    someFlworExpr->set_return_expr(new const_expr(sctxid(), loc, true));
    
    // $y 
    const QName* toVarQName = ic.getToNodeVarName();
    var_expr_t toVarExpr = bind_var(loc, toVarQName->get_qname(), 
                                    var_expr::for_var, NULL);
    
    // for $y in dc:collection(xs:QName("org:employees")) 
    someFlworExpr->add_clause(wrap_in_forclause(toCollExpr.getp(), toVarExpr,
                                                NULL));
    
    
    // FROM part
    // "org:transactions"
    expr_t fromQnameStrExpr = new const_expr(sctxid(), loc, 
                                             ic.getFromCollName()->get_qname() );
    
    string fromPrefixStr = ic.getFromCollName()->get_prefix();
    xqp_string fromUriStr = sctx_p->lookup_ns(fromPrefixStr);
    
    expr_t fromUriStrExpr = new const_expr(sctxid(), loc, fromUriStr );
    
    // fn:QName("org-uri", "org:transactions")
    fo_expr_t fromQnameExpr = new fo_expr(sctxid(), loc,
                                          GET_BUILTIN_FUNCTION(FN_QNAME_2),
                                          fromUriStrExpr, fromQnameStrExpr);
    
    // dc:collection(xs:QName("org:transactions"))
    function* fromFnCollection = sctx_p->lookup_resolved_fn(
                                                            xqp_string("http://www.zorba-xquery.com/modules/xqddf"), 
                                                            xqp_string("collection"), 
                                                            1);
    ZORBA_ASSERT(fromFnCollection != NULL);
    std::vector<expr_t> fromArgColl;      
    fromArgColl.push_back(fromQnameExpr.getp());
    fo_expr_t fromCollExpr = new fo_expr(sctxid(), loc, fromFnCollection, 
                                         fromArgColl);
    
    // every $x in dc:collection( xs:QName("org:transactions") )
    // satisfies ...
    // implemented using flowr
    flwor_expr_t evFlworExpr = new flwor_expr(sctxid(), loc, false);
    evFlworExpr->set_return_expr(new const_expr(sctxid(), loc, true));
    
    // $x
    const QName* fromVarQName = ic.getFromNodeVarName();
    var_expr_t fromVarExpr = bind_var(loc, fromVarQName->get_qname(), 
                                      var_expr::for_var, NULL);
    
    // for $x in dc:collection(xs:QName("org:transactions")) 
    evFlworExpr->add_clause(wrap_in_forclause(fromCollExpr.getp(), 
                                              fromVarExpr, NULL));
    
    
    nodestack.push(someFlworExpr.getp());
    nodestack.push(evFlworExpr.getp());      
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
      flworExpr->set_return_expr(icExpr);

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
      fo_expr_t fnDataExpr = new fo_expr(sctxid(), loc, 
                                         GET_BUILTIN_FUNCTION(FN_DATA_1), 
                                         uniKeyExpr);      

      xqp_string coment1Str("#trace fnExistsInput");
      expr_t coment1Expr = new const_expr(sctxid(), loc, coment1Str);
      fo_expr_t fnTrace1Expr = new fo_expr(sctxid(),
                                         loc,
                                         GET_BUILTIN_FUNCTION(FN_TRACE_2),
                                         uniKeyExpr, coment1Expr);
      

      // exists( $x/@id )
      expr_t existsExpr = new fo_expr(sctxid(), loc, 
                                      GET_BUILTIN_FUNCTION(FN_EXISTS_1), 
                                      fnTrace1Expr /*uniKeyExpr*/);

      xqp_string commentStr("#trace fnExists");
      expr_t comentExpr = new const_expr(sctxid(), loc, commentStr);
      fo_expr_t fnTraceExpr = new fo_expr(sctxid(),
                                         loc,
                                         GET_BUILTIN_FUNCTION(FN_TRACE_2),
                                         existsExpr, comentExpr);
      

      // every ... satisfies evTestExpr
      fo_expr_t fnNotExpr = new fo_expr(sctxid(),
                                        loc,
                                        GET_BUILTIN_FUNCTION(FN_NOT_1),
                                        fnTraceExpr /*existsExpr*/);

      evFlworExpr->add_where(fnNotExpr.getp());

      fo_expr_t everyExpr = new fo_expr(sctxid(),
                                        loc,
                                        GET_BUILTIN_FUNCTION(FN_EMPTY_1),
                                        evFlworExpr.getp());

      // functx:are-distinct-values( $x/@id )
      // implemented as count(distinct-values($seq)) = count($seq)      
      //distinct-values($seq)
      fo_expr_t distinctValuesExpr = new fo_expr(sctxid(), loc, 
                                 GET_BUILTIN_FUNCTION(FN_DISTINCT_VALUES_1), 
                                                 fnDataExpr);      

      // count($sec)
      fo_expr_t countSecExpr = new fo_expr(sctxid(), loc, 
                                           GET_BUILTIN_FUNCTION(FN_COUNT_1), 
                                           fnDataExpr /*uniKeyExpr*/);
      // count(distinct-values($sec))
      fo_expr_t countDVExpr = new fo_expr(sctxid(), loc, 
                                          GET_BUILTIN_FUNCTION(FN_COUNT_1), 
                                          distinctValuesExpr);

      // countDV = countSec
      fo_expr_t equalExpr = new fo_expr(sctxid(), loc, 
                                        GET_BUILTIN_FUNCTION(OP_EQUAL_2), 
                                        countDVExpr, countSecExpr);      
      // (...) and (...)
      fo_expr_t andExpr = new fo_expr(sctxid(), loc, 
                                      GET_BUILTIN_FUNCTION(OP_AND_2), 
                                      everyExpr, equalExpr);

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
      expr_t evTestExpr = pop_nodestack();

      // flwor expr
      flwor_expr_t evFlworExpr = 
        dynamic_cast<flwor_expr*>(pop_nodestack().getp());
      
      // fn:not
      fo_expr_t fnNotExpr = new fo_expr(sctxid(),
                                        loc,
                                        GET_BUILTIN_FUNCTION(FN_NOT_1),
                                        evTestExpr);

      // where not( exists($x/sale gt 0) )
      evFlworExpr->add_where(fnNotExpr.getp());

      // fn:empty
      fo_expr_t emptyExpr = new fo_expr(sctxid(),
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
      expr_t toKeyExpr = pop_nodestack();
      
      // $x//sale/empid
      expr_t fromKeyExpr = pop_nodestack();
      
      // result expr
      flwor_expr_t evFlworExpr = 
        dynamic_cast<flwor_expr*>(pop_nodestack().getp());

      // some flwor expr
      flwor_expr_t someFlworExpr = 
        dynamic_cast<flwor_expr*>(pop_nodestack().getp());


      // maybe add fn:data ?
      // $y/id eq $x//sale/empid
      fo_expr_t eqExpr = new fo_expr(sctxid(),
                                     loc,
                                     GET_BUILTIN_FUNCTION(OP_VALUE_EQUAL_2),
                                     toKeyExpr,
                                     fromKeyExpr);
      normalize_fo(eqExpr);    

      expr_t someTestExpr = eqExpr;      
      someTestExpr = wrap_in_bev(someTestExpr);            
      someFlworExpr->add_where(someTestExpr);

      // fn:exists
      fo_expr_t fnExistsExpr = new fo_expr(sctxid(), loc,
                                           GET_BUILTIN_FUNCTION(FN_EXISTS_1),
                                           someFlworExpr.getp());
      



      // fn:not()
      fo_expr_t evFnNotExpr = new fo_expr(sctxid(),
                                          loc,
                                          GET_BUILTIN_FUNCTION(FN_NOT_1),
                                          fnExistsExpr);

      evFlworExpr->add_where(evFnNotExpr.getp());

      // fn:empty
      fo_expr_t fnEmptyExpr = new fo_expr(sctxid(),
                                        loc,
                                        GET_BUILTIN_FUNCTION(FN_EMPTY_1),
                                        evFlworExpr.getp());


      body = fnEmptyExpr;
    }
    break;

  default:
    ZORBA_ASSERT(false);
  }



  std::string msg = "entry-creator expr for integrity constraint " + 
    qname->get_localname();
  
  if (theCCB->theConfig.optimize_cb != NULL)
    theCCB->theConfig.optimize_cb(body.getp(), msg);
 
  PlanIter_t icIter = codegen("integrity constraint", body, theCCB);

  store::Iterator_t icPlanWrapper = 
    new PlanWrapper(icIter, theCCB, NULL /*dctx*/, NULL);

  // Update static context
  store::Item_t qnameItem = sctx_p->lookup_fn_qname(qname->get_prefix(),
                                                    qname->get_localname(),
                                                    qname->get_location());


  ValueIC_t vic;
  if ( v.getICKind() == IntegrityConstraintDecl::foreign_key )
  {
    const ICForeignKey ic = dynamic_cast<const ICForeignKey&>(v);

    const QName* fromQname = ic.getFromCollName();
    store::Item_t fromQnameItem = 
      sctx_p->lookup_fn_qname(fromQname->get_prefix(), 
                              fromQname->get_localname(),
                              fromQname->get_location());

    const QName* toQname = ic.getToCollName();
    store::Item_t toQnameItem = 
      sctx_p->lookup_fn_qname(toQname->get_prefix(), 
                              toQname->get_localname(),
                              toQname->get_location());

    vic = new ValueIC(sctx_p, qnameItem, fromQnameItem, toQnameItem, 
                      icPlanWrapper);
  }
  else
  {
    const ICColl* ic = dynamic_cast<const ICColl*>(&v);

    const QName* collQname = ic->getCollName();
    store::Item_t collQnameItem = 
      sctx_p->lookup_fn_qname(collQname->get_prefix(), 
                              collQname->get_localname(),
                              collQname->get_location());

    vic = new ValueIC(sctx_p, qnameItem, collQnameItem, icPlanWrapper);
  }   

  sctx_p->bind_ic(qnameItem, vic, loc);     

  // if this is a library module, register in exported module as well
  if (export_sctx != NULL)
    export_sctx->bind_ic(qnameItem, vic, loc);
}

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  EnclosedExpr, QueryBody, Expr, ExprSingle, Block                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  [36] EnclosedExpr ::= "{" Expr "}"

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

  fo_expr* foExpr = new fo_expr(sctxid(), loc, op_enclosed, lContent);

  nodestack.push(foExpr);
}


/*******************************************************************************
  [37] QueryBody ::= Expr
********************************************************************************/
void* begin_visit(const QueryBody& v) 
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const QueryBody& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  expr_t resultExpr = wrap_in_globalvar_assign(pop_nodestack());

  nodestack.push(resultExpr);

  if (theModulesInfo->theCCB->isLoadPrologQuery())
    sctx_p->set_query_expr(resultExpr);
}


/*******************************************************************************
  [38]  Expr ::= ApplyExpr | ConcatExpr

  [38a] ApplyExpr ::= (ConcatExpr ";")+

  [38b] ConcatExpr ::= ExprSingle ("," ExprSingle)*

  There are no ApplyExpr or ConcatExpr parsenodes. Instead:

  - If the Expr is an ApplyExpr, no Expr parsenode is generated. Instead, a
    BlockBody parsenode is generated, whose children are the ConcatExprs that
    comprise the ApplyExpr. 

  - If the Expr is a ConcatExpr, then an Expr parsenode is generated, whose
    children are the ExprSingles that comparise the ConcatExpr. In this case,
    if Expr has either 0 or more than 1 children, it is translated as an
    fn:concatenate expr. Otherwise, it is translated to its unique child.
********************************************************************************/
void* begin_visit(const Expr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const Expr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  if (v.numberOfChildren() > 1) 
  {
    std::vector<expr_t> args;

    for (int i = 0; i < v.numberOfChildren(); ++i) 
    {
      expr_t e = pop_nodestack();
      args.push_back(e);
    }

    fo_expr_t concatExpr = new fo_expr(sctxid(),
                                       v.get_location(),
                                       op_concatenate,
                                       args);
    normalize_fo(concatExpr.getp());

    nodestack.push(concatExpr.getp());
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

  ** scripting
                      BlockExpr |
                      ExitExpr |
                      WhileExpr |
                      AssignExpr |
                      FlowCtlStatement |

  ** eval
                      EvalExpr |

  ** updates
                      InsertExpr |
                      DeleteExpr |
                      RenameExpr |
                      ReplaceExpr |
                      TransformExpr

********************************************************************************/


/*******************************************************************************

  Block ::= "{" BlockDecls BlockBody "}"

  BlockDecls ::= (BlockVarDecl ";")*

  BlockVarDecl ::= "declare" "$" VarName TypeDeclaration? (":=" ExprSingle)?
                    ("," "$" VarName TypeDeclaration? (":=" ExprSingle)?)*

  BlockBody ::= Expr


  - Synactically, BlockBody appears only in Block, and Block appears in
    BlockExpr, WhileExpr, and FunctionDecl iff the function is declared as
    sequential:

  BlockExpr ::= "block" Block

  WhileExpr ::= "while" "(" ExprSingle ")" Block

  FunctionDecl ::= "declare" ("deterministic" | "nondeterministic")?
                   "sequential" "function" QName "(" ParamList? ")" ("as" SequenceType)?
                    Bock


  - There is no parsenode class for BlockExpr or for Block; instead, the parser
    generates:

  1. BlockBody, if BlockDecls is not empty. The "decls" data member of this
     BlockBody stores the var declarations.

  2. BlockBody, if BlockDecls is empty and Expr is an ApplyExpr.

  3. Expr, if BlockDecls is empty and Expr is a ConcatExpr.

  In addition to cases 1 and 2 above, a BlockBody node is also generated

  4. In the case of any Expr that is an ApplyExpr.

  4. In the case of a WhileExpr if the Block that appears in the WhileExpr
     syntax did not generate a BlockBody itself (i.e., case 3 above). In this 
     case, the BlockBody has a single child, which is the Expr node generated
     by Block.


  - There are no parsenode classes for BlockVarDecl and BlockDecls; instead
    the parser generates VarDecl and VFO_DeclList parsenodes.

********************************************************************************/
void* begin_visit(const BlockBody& v) 
{
  TRACE_VISIT();

  push_scope();
  return no_state;
}

void end_visit(const BlockBody& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  vector<expr_t> stmts;

  for (int i = 0; i < v.size(); i++)
    stmts.push_back(pop_nodestack());

  rchandle<VFO_DeclList> decls = v.get_decls();

  if (decls != NULL)
  {
    for (int i = decls->size() - 1; i >= 0; --i) 
    {
      expr_t val = pop_nodestack();
      var_expr_t ve = pop_nodestack().cast<var_expr> ();
      global_binding b(ve, val, false);

      vector<expr_t> stmts1;
      declare_var(b, stmts1);

      reverse(stmts1.begin(), stmts1.end());

      stmts.insert(stmts.end(), stmts1.begin(), stmts1.end());
    }
  }

  reverse(stmts.begin(), stmts.end());

  nodestack.push(new sequential_expr(sctxid(), loc, stmts));

  pop_scope();
}



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

  if (sctx_p->xquery_version() <= StaticContextConsts::xquery_version_1_0 && 
      v.is_non_10()) 
  {
    ZORBA_ERROR_LOC(XPST0003, loc);
  }

  rchandle<flwor_expr> flwor = new flwor_expr(sctxid(), loc, v.is_general());

  expr_t retExpr = pop_nodestack();
  
  wrap_in_debugger_expr(retExpr);

  flwor->set_return_expr(retExpr);

  ulong curClausePos = theFlworClausesStack.size() - 1;

  while(theFlworClausesStack[curClausePos] != NULL)
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

  ulong numClauses = theFlworClausesStack.size();

  for (ulong i = curClausePos + 1; i < numClauses; ++i)
    flwor->add_clause(theFlworClausesStack[i]);

  theFlworClausesStack.resize(curClausePos);

  nodestack.push(&*flwor);
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

  if (v.is_outer())
  {
    if (sctx_p->xquery_version() < StaticContextConsts::xquery_version_1_1)
      ZORBA_ERROR_LOC_DESC(XPST0003, loc,
        "The outer-for clause is available in XQuery 1.1 or later.");

    theFlworClausesStack.push_back(NULL);
  }

  return no_state;
}


void end_visit(const ForClause& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  if (v.is_outer())
  {
    ulong curClause = theFlworClausesStack.size() - 1;
    while(theFlworClausesStack[curClause] != NULL)
    {
      static_cast<for_clause*>(theFlworClausesStack[curClause].getp())->set_outer(true);
      --curClause;
    }

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

  // debugger bugfix
  // it's important to insert the debugger before
  // the scope is pushed. Otherwise, the variable in
  // question would already be in scope for the debugger
  // but no value would be bound
  expr_t domainExpr = pop_nodestack();

  if (domainExpr->is_updating())
    ZORBA_ERROR_LOC(XUST0001, loc);

  wrap_in_debugger_expr(domainExpr);

  push_scope();

  xqp_string varname = v.get_varname();
  store::Item_t varQName = sctx_p->lookup_var_qname(varname, loc);

  xqtref_t type = (v.get_typedecl() == NULL ? NULL : pop_tstack());

  var_expr_t varExpr = bind_var(loc, varQName, var_expr::for_var, type);
  var_expr_t posVarExpr;

  const PositionalVar* pv = v.get_posvar();
  if (pv != NULL) 
  {
    xqp_string pvarname = pv->get_varname();
    store::Item_t pvarQName = sctx_p->lookup_var_qname(pvarname, loc);
    if (pvarQName->equals(varQName.getp()))
      ZORBA_ERROR_LOC (XQST0089, loc);

    posVarExpr = bind_var(pv->get_location(), pvarQName, var_expr::pos_var);
  }

  for_clause* fc = new for_clause(sctx_p,
                                  sctxid(),
                                  v.get_location(),
                                  varExpr,
                                  domainExpr,
                                  posVarExpr);

  theFlworClausesStack.push_back(fc);
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

  xqtref_t type = (v.get_typedecl() == NULL ? NULL : pop_tstack());

  if (v.get_kind() == VarGetsDecl::let_var)
  {
    // debugger bugfix
    // it's important to insert the debugger before
    // the scope is pushed. Otherwise, the variable in
    // question would already be in scope for the debugger
    // but no value would be bound
    expr_t domainExpr = pop_nodestack();

    if (domainExpr->is_updating())
      ZORBA_ERROR_LOC(XUST0001, loc);

    wrap_in_debugger_expr(domainExpr);

    push_scope();

    var_expr_t varExpr = bind_var(loc, v.get_varname(), var_expr::let_var, type);

    let_clause* clause = new let_clause(sctx_p,
                                        sctxid(),
                                        v.get_location(),
                                        varExpr,
                                        domainExpr);

    theFlworClausesStack.push_back(clause);
  }
  else
  {
    push_scope();
    nodestack.push(&*create_var(loc, v.get_varname(), var_expr::let_var, type));
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

  if (sctx_p->xquery_version() < StaticContextConsts::xquery_version_1_1)
    ZORBA_ERROR_LOC_DESC (XPST0003, loc,
      "The window clause is a feature that is available in XQuery 1.1 or later.");

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

  window_clause* clause = new window_clause(sctx_p,
                                            sctxid(),
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
      
      conds[i] = new flwor_wincond(sctx_p,
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
    posVarExpr = bind_var(pv->get_location(), pv->get_varname(), pvarKind);
    posVarExpr->set_flwor_clause(windowClause);
    nodestack.push(posVarExpr.getp());
  }

  if (! v.get_curr().empty())
  {
    curVarExpr = bind_var(loc, v.get_curr(), varKind);
    curVarExpr->set_flwor_clause(windowClause);
    nodestack.push(curVarExpr.getp());
  }

  if (! v.get_prev().empty())
  {
    prevVarExpr = bind_var(loc, v.get_prev(), varKind);
    prevVarExpr->set_flwor_clause(windowClause);
    nodestack.push(prevVarExpr.getp());
  }

  if (! v.get_next().empty())
  {
    nextVarExpr = bind_var(loc, v.get_next(), varKind);
    nextVarExpr->set_flwor_clause(windowClause);
    nodestack.push(nextVarExpr.getp());
  }
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

  bind_var_and_push(loc, v.get_varname(), var_expr::win_var, type);
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
void *begin_visit(const GroupByClause& v) 
{
  TRACE_VISIT ();

  const FLWORExpr& flwor = *v.get_flwor ();
  const FLWORClauseList& clauses = *flwor.get_clause_list ();

  set<const var_expr *> all_vars;
  set<const var_expr *> group_vars;
  set<const var_expr *> non_group_vars;

  // Collect the var_exprs for all the vars that have been defined by all
  // clauses before this GroupByClause.
  collect_flwor_vars (flwor, all_vars, &*clauses[0], &v, false);

  // Collect the var_exprs for all the grouping vars specified in this GroupByClause.
  GroupSpecList* lList = v.get_spec_list();
  for (size_t i = 0; i < lList->size(); ++i) 
  {
    GroupSpec* spec = (*lList)[i];
    string varname = spec->get_var_name();
    const var_expr* ve = lookup_var(varname);
    if (ve == NULL)
      ZORBA_ERROR_LOC_PARAM( XPST0008, loc, varname, "");

    group_vars.insert(ve);
  }

  // The non-grouping vars are the vars in the difference of the 2 sets above.
  set_difference(all_vars.begin(), all_vars.end(),
                 group_vars.begin(), group_vars.end(),
                 inserter(non_group_vars, non_group_vars.begin()));

  // For each var_expr X that does not appear in the group-by clause, create
  // a new var_exp ngX and push ngX and X in the node stack.

  nodestack.push(NULL);

  for (set<const var_expr *>::iterator i = non_group_vars.begin();
       i != non_group_vars.end();
       ++i)
  {
    nodestack.push(const_cast<var_expr *>(*i));

    push_scope();

    bind_var_and_push(loc, (*i)->get_name(), var_expr::non_groupby_var);
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
    input_wrapper = new wrapper_expr(sctxid(),
                                     v.get_location(),
                                     static_cast<expr*>(input_var.getp()));

    grouping_rebind.push_back(pair<wrapper_expr_t, var_expr_t>(input_wrapper,
                                                               output_var));
  }

  reverse(collations.begin(), collations.end());
  reverse(grouping_rebind.begin(), grouping_rebind.end());

  while (NULL != (output_var = pop_nodestack_var())) 
  {
    input_var = pop_nodestack_var();

    wrapper_expr_t input_wrapper;
    input_wrapper = new wrapper_expr(sctxid(),
                                     v.get_location(),
                                     static_cast<expr*>(input_var.getp()));

    nongrouping_rebind.push_back(pair<wrapper_expr_t, var_expr_t>(input_wrapper,
                                                                  output_var));
  }

  group_clause* clause = new group_clause(sctxid(),
                                          v.get_location(),
                                          grouping_rebind,
                                          nongrouping_rebind,
                                          collations);
  theFlworClausesStack.push_back(clause);
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

  // Create a new var_expr gX, corresponding to the input-stream var X that 
  // is referenced by this group spec. gX represents X in the output stream.
  // Push the var_exprs for both X and gX into the nodestack.
  push_scope();

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

  const OrderSpecList& orderSpecs = *v.get_spec_list();
  unsigned numOrderSpecs = orderSpecs.size();

  std::vector<OrderModifier> modifiers(numOrderSpecs);
  std::vector<expr_t> orderExprs(numOrderSpecs);

  for (int i = numOrderSpecs - 1; i >= 0; --i) 
  {
    OrderSpec* spec = orderSpecs[i];
    const OrderModifierPN* mod = spec->get_modifier();

    ParseConstants::dir_spec_t dirSpec = ParseConstants::dir_ascending;
    if (mod && mod->get_dir_spec() != NULL)
      dirSpec = mod->get_dir_spec()->getValue();

    StaticContextConsts::order_empty_mode_t emptySpec = sctx_p->order_empty_mode();
    if (mod && mod->get_empty_spec() != NULL)
      emptySpec = mod->get_empty_spec()->getValue();

    string collation = sctx_p->default_collation_uri();
    if (mod && mod->get_collation_spec() != NULL)
    {
      collation = mod->get_collation_spec()->get_uri();

      if (! sctx_p->has_collation_uri(collation))
        ZORBA_ERROR_LOC(XQST0076, loc);
    }

    expr_t orderExpr = pop_nodestack();

    if (orderExpr->is_updating())
      ZORBA_ERROR_LOC(XUST0001, loc);

    orderExpr = wrap_in_atomization(orderExpr);

    modifiers[i].theAscending = (dirSpec == ParseConstants::dir_ascending);
    modifiers[i].theEmptyLeast = (emptySpec == StaticContextConsts::empty_least);
    modifiers[i].theCollation = collation;

    orderExprs[i] = orderExpr;
  }

  orderby_clause* clause = new orderby_clause(sctxid(),
                                              v.get_location(),
                                              v.get_stable_bit(),
                                              modifiers,
                                              orderExprs);
  theFlworClausesStack.push_back(clause);
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


void *begin_visit(const OrderCollationSpec& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderCollationSpec& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const OrderDirSpec& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const OrderDirSpec& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}

void *begin_visit(const OrderEmptySpec& v) 
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
    ZORBA_ERROR_LOC(XUST0001, loc);

  whereExpr = wrap_in_bev(whereExpr);

  wrap_in_debugger_expr(whereExpr);

  where_clause* clause = new where_clause(sctxid(),
                                          v.get_location(),
                                          whereExpr);

  theFlworClausesStack.push_back(clause);
}


/*******************************************************************************
  CountClause ::= "count" "$" VarName
********************************************************************************/
void *begin_visit (const CountClause& v) 
{
  TRACE_VISIT ();

  if (sctx_p->xquery_version() < StaticContextConsts::xquery_version_1_1)
    ZORBA_ERROR_LOC_DESC (XPST0003, loc,
      "The count clause is a feature that is only available in XQuery 1.1 or later.");

  return no_state;
}

void end_visit (const CountClause& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  var_expr_t varExpr = bind_var(loc, v.get_varname(), var_expr::count_var, NULL);

  count_clause* clause = new count_clause(sctxid(),
                                          v.get_location(), 
                                          varExpr);

  theFlworClausesStack.push_back(clause);
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
void* begin_visit(const QuantifiedExpr& v) 
{
  TRACE_VISIT();

  rchandle<flwor_expr> flwor(new flwor_expr(sctxid(), loc, false));

  flwor->set_return_expr(new const_expr(sctxid(), loc, true));

  nodestack.push(flwor.getp());

  return no_state;
}


void end_visit(const QuantifiedExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  rchandle<expr> testExpr = pop_nodestack();

  if (v.get_qmode() == ParseConstants::quant_every) 
  {
    rchandle<fo_expr> uw = new fo_expr(sctxid(),
                                       v.get_expr()->get_location(),
                                       GET_BUILTIN_FUNCTION(FN_NOT_1),
                                       testExpr);
    testExpr = uw.getp();
  }
  else
  {
    testExpr = wrap_in_bev(testExpr);
  }

  for (int i = 0; i < v.get_decl_list()->size(); ++i) 
  {
    pop_scope();
  }

  flwor_expr_t flworExpr = dynamic_cast<flwor_expr*>(pop_nodestack().getp());
  ZORBA_ASSERT(flworExpr != NULL);

  flworExpr->add_where(testExpr);

  rchandle<fo_expr> quant = new fo_expr(sctxid(),
                                        loc,
                                        v.get_qmode() == ParseConstants::quant_every ?
                                        GET_BUILTIN_FUNCTION(FN_EMPTY_1) :
                                        GET_BUILTIN_FUNCTION(FN_EXISTS_1),
                                        flworExpr.getp());
  nodestack.push(&*quant);
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

  push_scope();
  xqtref_t type;
  if (v.get_typedecl() != NULL)
    type = pop_tstack();

  expr_t domainExpr = pop_nodestack();
  var_expr_t varExpr = bind_var(loc, v.get_name(), var_expr::for_var, type);

  flwor_expr* flworExpr = dynamic_cast<flwor_expr*>(nodestack.top().getp());
  ZORBA_ASSERT(flworExpr != NULL);

  flworExpr->add_clause(wrap_in_forclause(domainExpr, varExpr, NULL));
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

  var_expr_t sv = tempvar(v.get_switch_expr()->get_location(), var_expr::let_var);

  v.get_switch_expr()->accept(*this);

  expr_t se = pop_nodestack();

  if (se->is_updating()) 
  {
    ZORBA_ERROR_LOC(XUST0001, loc);
  }

  // flworExpr = [let $sv := E return NULL]
  expr_t retExpr;
  expr_t flworExpr = wrap_in_let_flwor(se, sv, retExpr);

  string defvar_name = v.get_default_varname();
  var_expr_t defvar;

  if (! defvar_name.empty())
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

  if (!defvar_name.empty()) 
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
  for (vector<rchandle<CaseClause> >::const_reverse_iterator it = clauses->rbegin();
       it != clauses->rend();
       ++it)
  {
    const CaseClause* caseClause = &**it;
    const QueryLoc& loc = caseClause->get_location();
    expr_t clauseExpr;

    caseClause->get_type()->accept(*this);
    xqtref_t type = pop_tstack();

    string varname = caseClause->get_varname();
    varref_t caseVar;

    if (! varname.empty())
    {
      push_scope();

      caseVar = bind_var(loc, varname, var_expr::let_var);

      expr_t treatExpr = new treat_expr(sctxid(),
                                        loc,
                                        sv.getp(),
                                        type,
                                        XPDY0050);

      // clauseExpr = [let $caseVar := cast($sv, caseType) return NULL]
      clauseExpr = wrap_in_let_flwor(treatExpr, caseVar, NULL);
    }

    caseClause->get_expr()->accept(*this);
    expr_t caseExpr = pop_nodestack();

    if (! varname.empty()) 
    {
      pop_scope();

      // clauseExpr = [let $caseVar := cast($sv, caseType) return NULL]
      static_cast<flwor_expr*>(clauseExpr.getp())->set_return_expr(caseExpr);
    }
    else
    {
      // clauseExpr = [caseExpr]
      clauseExpr = caseExpr;
    }

    // retExpr = [if (instance_of($sv, type)) then clauseExpr else retExpr]
    retExpr = new if_expr(sctxid(),
                          loc,
                          sctx_p,
                          new instanceof_expr(sctxid(), loc, &*sv, type),
                          clauseExpr,
                          retExpr);
  }

  static_cast<flwor_expr*>(flworExpr.getp())->set_return_expr(retExpr);

  nodestack.push(flworExpr);

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
  [67] CaseClause ::= "case" ("$" VarName "as")? SequenceType "return" ExprSingle
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


/*******************************************************************************
  [68] IfExpr ::= "if" "(" Expr ")" "then" ExprSingle "else" ExprSingle
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

  wrap_in_debugger_expr(e_h);
  wrap_in_debugger_expr(t_h);
  wrap_in_debugger_expr(c_h);

  if_expr* ifExpr = new if_expr(sctxid(), loc, sctx_p, c_h, t_h, e_h);

  nodestack.push(ifExpr);
}


/*******************************************************************************
  [69] OrExpr ::= AndExpr ( "or" AndExpr )*
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

  fo_expr* fo = new fo_expr(sctxid(), loc, GET_BUILTIN_FUNCTION(OP_OR_2), e2, e1);

  nodestack.push(fo);
}


/*******************************************************************************
  [70] AndExpr ::= ComparisonExpr ( "and" ComparisonExpr )*
********************************************************************************/
void* begin_visit(const AndExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const AndExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  rchandle<expr> e1 = pop_nodestack();
  rchandle<expr> e2 = pop_nodestack();

  fo_expr* fo = new fo_expr(sctxid(), loc, GET_BUILTIN_FUNCTION(OP_AND_2), e2, e1);

  nodestack.push(fo);
}


/*******************************************************************************
  [71] ComparisonExpr ::= RangeExpr
                          ((ValueComp | GeneralComp | NodeComp) RangeExpr)?

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

  fo_expr* fo = new fo_expr(sctxid(), loc, f, e2, e1);

  normalize_fo(fo);

  nodestack.push(fo);

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

  fo_expr* e = new fo_expr(sctxid(), loc, GET_BUILTIN_FUNCTION(OP_TO_2), e2, e1);

  normalize_fo(e);

  nodestack.push(e);
}


/*******************************************************************************
  [73] AdditiveExpr ::= MultiplicativeExpr ( ("+" | "-") MultiplicativeExpr )*
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

  fo_expr* foExpr = new fo_expr(sctxid(), loc, func, e2, e1);

  normalize_fo(foExpr);

  nodestack.push(foExpr);
}


/*******************************************************************************
  [74] MultiplicativeExpr ::= UnionExpr (("*" | "div" | "idiv" | "mod") UnionExpr)*
********************************************************************************/
void* begin_visit(const MultiplicativeExpr& v) 
{
  TRACE_VISIT ();
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

  fo_expr* foExpr = new fo_expr(sctxid(), loc, f, e2, e1);

  normalize_fo(foExpr);

  nodestack.push(foExpr);
}


/*******************************************************************************
  [75] UnionExpr ::= IntersectExceptExpr (("union" | "|") IntersectExceptExpr)*
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

  fo_expr* foExpr = new fo_expr(sctxid(), loc, GET_BUILTIN_FUNCTION(OP_UNION_2), e2, e1);

  normalize_fo(foExpr);

  // Union is implemented by a concat iterator, so we have to do node sorting
  // and duplicate elimi
  nodestack.push(new fo_expr(sctxid(),
                             loc,
                             GET_BUILTIN_FUNCTION(OP_SORT_DISTINCT_NODES_ASC_1),
                             foExpr));
}


/*******************************************************************************
  [76] IntersectExceptExpr ::= InstanceofExpr
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

  fo_expr* foExpr = new fo_expr(sctxid(), loc, f, e2, e1);

  normalize_fo(foExpr);

  nodestack.push(new fo_expr(sctxid(),
                             loc,
                             GET_BUILTIN_FUNCTION(OP_SORT_DISTINCT_NODES_ASC_1),
                             foExpr));
}


/*******************************************************************************
  [77] InstanceofExpr ::= TreatExpr ( "instance" "of" SequenceType )?
********************************************************************************/
void* begin_visit(const InstanceofExpr& v) 
{
  TRACE_VISIT();
  return no_state;
}

void end_visit (const InstanceofExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  nodestack.push(new instanceof_expr(sctxid(),
                                     loc,
                                     pop_nodestack(),
                                     pop_tstack()));
}


/*******************************************************************************
  [78] TreatExpr ::= CastableExpr ( "treat" "as" SequenceType )?
********************************************************************************/
void* begin_visit(const TreatExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const TreatExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  nodestack.push(new treat_expr(sctxid(),
                                loc,
                                pop_nodestack(),
                                pop_tstack(),
                                XPDY0050));
}


/*******************************************************************************
  [79] CastableExpr ::= CastExpr ( "castable" "as" SingleType )?
********************************************************************************/
void* begin_visit(const CastableExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CastableExpr& v, void* /*visit_state*/)
{
  TRACE_VISIT_OUT();

  nodestack.push(create_cast_expr(loc, pop_nodestack(), pop_tstack(), false));
}


expr_t create_cast_expr(const QueryLoc& loc, expr_t node, xqtref_t type, bool isCast)
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
          if(e.theQueryLine == 0)
          {
            e.theQueryColumn = loc.getColumnBegin();
            e.theQueryFileName = loc.getFilenameBegin();
            e.theQueryLine = loc.getLineBegin();
          }
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
        return new const_expr(sctxid(), loc, castLiteral);
      else
        return new const_expr(sctxid(), loc, castLiteral != NULL);
    }
    else
    {
      
      xqtref_t qnameType = (type->get_quantifier() == TypeConstants::QUANT_ONE ?
                            GENV_TYPESYSTEM.QNAME_TYPE_ONE :
                            GENV_TYPESYSTEM.QNAME_TYPE_QUESTION);

      // when casting to type T, where T is QName or subtype of, and the input
      // is not a const expr, then the input MUST be of type T or subtype of.
      if (isCast)
        return new treat_expr(sctxid(), loc, node, qnameType, XPTY0004);
      else
        return new instanceof_expr(sctxid(), loc, node, qnameType);
    }
  }
  else
  {
    if (isCast)
      return new cast_expr(sctxid(), loc, wrap_in_atomization(node), type);
    else
      return new castable_expr(sctxid(), loc, node, type);
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
void* begin_visit(const UnaryExpr& v) 
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const UnaryExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  rchandle<expr> e1 = pop_nodestack();

  fo_expr* foExpr = new fo_expr(sctxid(),
                                loc,
                                (v.get_signlist()->get_sign() ?
                                 GET_BUILTIN_FUNCTION(OP_UNARY_PLUS_1) :
                                 GET_BUILTIN_FUNCTION(OP_UNARY_MINUS_1)),
                                e1);
  normalize_fo(foExpr);

  nodestack.push(foExpr);
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

  nodestack.push(new validate_expr(sctxid(),
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
void *begin_visit (const PathExpr& v) 
{
  TRACE_VISIT();

  const PathExpr& pe = v;

  ParseConstants::pathtype_t pe_type = pe.get_type();

  expr_t result;
  rchandle<relpath_expr> path_expr = NULL;

  // Put a NULL in the stack to mark the beginning of a PathExp tree.
  nodestack.push(NULL);

  theNodeSortStack.push(NodeSortInfo());

  // In cases 2, 3, and 4 create a new relpath_expr, which will be put to the nodestack.
  if (pe_type != ParseConstants::path_leading_lone_slash) 
  {
    path_expr = new relpath_expr(sctxid(), loc);

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
    rchandle<relpath_expr> ctx_path_expr = new relpath_expr(sctxid(), loc);

    expr_t sourceExpr = new treat_expr(sctxid(),
                                       loc,
                                       DOT_REF,
                                       GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
                                       XPTY0020);

    ctx_path_expr->add_back(sourceExpr);

    rchandle<match_expr> me = new match_expr(sctxid(), loc);
    me->setTestKind(match_anykind_test);
    rchandle<axis_step_expr> ase = new axis_step_expr(sctxid(), loc);
    ase->setAxis(axis_kind_self);
    ase->setTest(me);

    ctx_path_expr->add_back(&*ase);

    rchandle<fo_expr> fo = new fo_expr(sctxid(),
                                       loc,
                                       GET_BUILTIN_FUNCTION(FN_ROOT_1),
                                       ctx_path_expr.getp());
    result = fo.getp();

    if (path_expr != NULL) 
    {
      path_expr->add_back(&*fo);
      result = path_expr.getp();

      theNodeSortStack.top().theNumSteps++;
    }

    if (pe_type == ParseConstants::path_leading_slashslash) 
    {
      rchandle<axis_step_expr> ase = new axis_step_expr(sctxid(), loc);
      rchandle<match_expr> me = new match_expr(sctxid(), loc);
      me->setTestKind(match_anykind_test);
      ase->setAxis(axis_kind_descendant_or_self);
      ase->setTest(me);

      path_expr->add_back(&*ase);

      theNodeSortStack.top().theNumSteps++;
    }
  }

  nodestack.push(result.getp());

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
    nodestack.push(wrap_in_dos_and_dupelim(arg2, true));
  }
  else
  {
    rchandle<fo_expr> checkExpr = 
      new fo_expr(sctxid(),
                  arg2->get_loc(),
                  GET_BUILTIN_FUNCTION(OP_EITHER_NODES_OR_ATOMICS_1),
                  arg2);

    nodestack.push(checkExpr.getp());
  }
#else
  // wrap in atomics_or_node_distinc_sort_asc
  nodestack.push(wrap_in_dos_and_dupelim(arg2, true));
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
    // If the path expr is of the form "axis::test/...." or "axis::test[pred]/...."
    // then the input expr to the this path expr is "treat . as node()"
    if (axisStep != NULL) 
    {
      expr_t sourceExpr = new treat_expr(sctxid(),
                                         loc,
                                         DOT_REF,
                                         GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
                                         XPTY0020);
      pathExpr->add_back(sourceExpr);

      if (axisStep->get_predicate_list() == NULL) 
      {
        // "axis::test/...." ==> push [ pathExpr(sourceExpr) ] to the nodestack. 
        nodestack.push(pathExpr);
      }
      else 
      {
        // "axis::test[pred]/...." ==> push [ for $dot at $pos in pathExpr(sourceExpr.) ]
        // to the nodestack.
        rchandle<flwor_expr> flworExpr = wrap_expr_in_flwor(pathExpr, false);
        nodestack.push(flworExpr.getp());
      }
    }
    // "source_expr/...." ==> push pathExpr() to the nodestack. 
    else 
    {
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
  // [ for $$dot at $$pos in node_distinc_sort_asc(pathExpr) ]
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

#ifdef NODE_SORT_OPT
    if (pathExpr->size() == 0) 
    {
      XQUERY_ERROR errCode = XPTY0019;

      if (stepExpr->get_expr_kind() == wrapper_expr_kind)
      {
        wrapper_expr* tmp = static_cast<wrapper_expr*>(stepExpr.getp());
        if (tmp->get_expr() == lookup_var(DOT_VARNAME))
          errCode = XPTY0020;
      }

      expr_t sourceExpr = new treat_expr(sctxid(),
                                         stepExpr->get_loc(),
                                         stepExpr,
                                         GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR,
                                         errCode);

      if (TypeOps::type_max_cnt(*sourceExpr->return_type(sctx_p)) > 1)
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

    pathExpr = new relpath_expr(sctxid(), loc);
    pathExpr->add_back(flworExpr);
  }

  // Convert // to /descendant-or-self::node()/
  if (rpe.get_step_type() == ParseConstants::st_slashslash)
  {
    rchandle<axis_step_expr> ase = new axis_step_expr(sctxid(), loc);
    rchandle<match_expr> me = new match_expr(sctxid(), loc);
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

  rchandle<axis_step_expr> ase = new axis_step_expr(sctxid(), loc);
  nodestack.push(ase.getp());

  theNodeSortStack.top().theNumSteps++;

  return no_state;
}


void post_axis_visit(const AxisStep& v, void* /*visit_state*/)
{
  // This method is called from AxisStep::accept() after the step itself is
  // translated, but before the associated predicate list (if any) is translated.

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
    nodestack.push(e);
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
  // If the axis is a forward one:
  //
  // [ for $$dot at $$pos in node_distinc_sort_asc(pathExpr-(i-1)) 
  //   let $$predInput := $$dot/axis::test ]
  //
  // Else, if it is a reverse axis:
  //
  // [ for $$dot at $$pos in node_distinc_sort_asc(pathExpr-(i-1)) 
  //   let $$predInput := node_distinct_sort_desc($$dot/axis::test) ]
  //
  // The $$predInput var will compute and store for each $$dot, the input seq for
  // the preds the follow the axis step.
  //
  // The flworExpr as well as the $$predInput varExpr are pushed to the nodestack.
  const for_clause* fcOuterDot = reinterpret_cast<const for_clause*>((*flworExpr)[0]);
  rchandle<relpath_expr> predPathExpr = new relpath_expr(sctxid(), loc);
  predPathExpr->add_back(new wrapper_expr(sctxid(), loc, fcOuterDot->get_var()));
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
    rchandle<match_expr> matchExpr = new match_expr(sctxid(), loc);;
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

    nodestack.push(flworExpr);
    nodestack.push(lcPredSeq->get_var());
  }

  // Else, this filter expr is the very first step (i.e., the source expr) of
  // a path expr.
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

  //  let $$temp := predInputSeq
  //  let $$last-idx := count($$temp)
  //  for $$dot at $$pos in $$temp
  rchandle<flwor_expr> flworExpr = wrap_expr_in_flwor(inputSeqExpr, true);

  nodestack.push(flworExpr.getp());
}


void post_predicate_visit(const PredicateList& v, void* /*visit_state*/)
{
  // This method is called from PredicateList::accept(), after calling accept()
  // on each predicate in the list

  ulong sctxid = this->sctxid();
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  expr_t predExpr = pop_nodestack();

  expr_t f = pop_nodestack();
  flwor_expr* flworExpr = f.dyn_cast<flwor_expr>();
  ZORBA_ASSERT(flworExpr != NULL);

  const QueryLoc& loc = predExpr->get_loc();

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
  //   if 

  // Check if the pred expr returns a numeric result
  expr_t e1 = new instanceof_expr(sctxid, loc, predvar, rtm.DECIMAL_TYPE_ONE);
  expr_t e2 = new instanceof_expr(sctxid, loc, predvar, rtm.DOUBLE_TYPE_ONE);
  expr_t e3 = new instanceof_expr(sctxid, loc, predvar, rtm.FLOAT_TYPE_ONE);

  fo_expr_t condExpr;
  condExpr = new fo_expr(sctxid, loc, GET_BUILTIN_FUNCTION(OP_OR_2), e1, e2);
  condExpr = new fo_expr(sctxid, loc, GET_BUILTIN_FUNCTION(OP_OR_2), &*condExpr, e3);

  // If so: return $dot if the value of the pred expr is equal to the value
  // of $dot_pos var, otherwise return the empty seq.
  fo_expr_t eqExpr = new fo_expr(sctxid,
                                 loc,
                                 GET_BUILTIN_FUNCTION(OP_VALUE_EQUAL_2),
                                 lookup_ctx_var(DOT_POS_VARNAME, loc).getp(),
                                 predvar);
  normalize_fo(eqExpr);

  expr_t thenExpr = new if_expr(sctxid,
                                loc,
                                sctx_p,
                                eqExpr.getp(),
                                DOT_REF,
                                create_seq(loc));

  // Else, return $dot if the the value of the pred expr is true, otherwise
  // return the empty seq.
  expr_t elseExpr = new if_expr(sctxid, loc, sctx_p, predvar, DOT_REF, create_seq(loc));

  // The outer if
  expr_t ifExpr = new if_expr(sctxid, loc, sctx_p, condExpr.getp(), thenExpr, elseExpr);

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
    nodestack.push(new const_expr(sctxid(), loc, v.get<xqp_integer>()));
    break;
  }
  case ParseConstants::num_decimal: 
  {
    nodestack.push(new const_expr(sctxid(), loc, v.get<xqp_decimal>()));
    break;
  }
  case ParseConstants::num_double: 
  {
    nodestack.push(new const_expr(sctxid(), loc, v.get<xqp_double>()));
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
  nodestack.push(new const_expr(sctxid(), loc,v.get_strval()));
}


/*******************************************************************************
  [110] VarRef ::= "$" VarName
  [111] VarName ::= QName
********************************************************************************/
void* begin_visit(const VarRef& v) 
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const VarRef& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  var_expr* ve = lookup_var(v.get_varname());

  if (ve == NULL)
    ZORBA_ERROR_LOC_PARAM (XPST0008, loc, v.get_varname (), "");

  if (ve->get_kind() == var_expr::prolog_var && !theCurrentPrologVFDecl.isNull()) 
  {
    thePrologGraph.addEdge(theCurrentPrologVFDecl, ve);
  }

  nodestack.push(new wrapper_expr(sctxid(), v.get_location(), rchandle<expr>(ve)));
}


/*******************************************************************************
  [112] ParenthesizedExpr ::= "(" Expr? ")"
********************************************************************************/
void* begin_visit(const ParenthesizedExpr& v) 
{
  TRACE_VISIT();

  nodestack.push(NULL);
  return no_state;
}

void end_visit(const ParenthesizedExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  expr_t expr = pop_nodestack();

  if (expr != NULL) 
  {
    pop_nodestack();
    nodestack.push(expr);
  }
  else 
  {
    fo_expr* lSeq = create_seq(loc);
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

  nodestack.push(DOT_REF);
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

  nodestack.push(new order_expr(sctxid(),
                                loc,
                                order_expr::ordered,
                                pop_nodestack()));
}


/*******************************************************************************
  [115] UnorderedExpr ::= "unordered" "{" Expr "}"
********************************************************************************/
void* begin_visit(const UnorderedExpr& v) 
{
  TRACE_VISIT();
  return no_state;
}

void end_visit (const UnorderedExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  nodestack.push(new order_expr(sctxid(),
                                loc,
                                order_expr::unordered,
                                pop_nodestack()));
}


/*******************************************************************************
  [116] FunctionCall ::= QName "(" ArgList? ")"
********************************************************************************/
void* begin_visit(const FunctionCall& v) 
{
  TRACE_VISIT();

  rchandle<QName> qn_h = v.get_fname();
  string prefix = qn_h->get_prefix();
  string fname = qn_h->get_localname();

  if (!theCurrentPrologVFDecl.isNull())
  {
    ulong numArgs = 0;
    if (v.get_arg_list() != NULL)
      numArgs = v.get_arg_list()->size();

    function* f = LOOKUP_FN(prefix, fname, numArgs);

    if (f != NULL)
      thePrologGraph.addEdge(theCurrentPrologVFDecl, f);
  }

  nodestack.push(NULL);
  return no_state;
}

void end_visit(const FunctionCall& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  // Collect the arguments of this function in reverse order
  std::vector<expr_t> arguments;

  while (true) 
  {
    expr_t argExpr = pop_nodestack();

    if (argExpr == NULL)
      break;

    arguments.push_back(argExpr);
  }

  ulong numArgs = arguments.size();

  rchandle<QName> qn_h = v.get_fname();
  string prefix = qn_h->get_prefix();
  string fname = qn_h->get_localname();

  store::Item_t fn_qname = sctx_p->lookup_fn_qname(prefix, fname, loc);
  const xqpStringStore* fn_ns = fn_qname->getNamespace();

  // Some special processing is required for certain "fn" functions
  if (fn_ns->byteEqual(XQUERY_FN_NS)) 
  {
    if (fname == "position" && numArgs == 0)  
    {
      nodestack.push(lookup_ctx_var(DOT_POS_VARNAME, loc).getp());
      return;
    }
    else if (fname == "last" && numArgs == 0)
    {
      nodestack.push(lookup_ctx_var(LAST_IDX_VARNAME, loc).getp());
      return;
    }
    else if (fname == "number") 
    {
      switch (numArgs) 
      {
      case 0:
      {
        arguments.push_back(DOT_REF);
        break;
      }
      case 1:
        break;
      default:
        ZORBA_ERROR_LOC_PARAM(XPST0017, loc, "fn:number", numArgs);
      }

      varref_t tv = tempvar(loc, var_expr::let_var);

      expr_t nanExpr = new const_expr(sctxid(), loc, xqp_double::nan());

      expr_t condExpr = new castable_expr(sctxid(), loc, &*tv, theRTM.DOUBLE_TYPE_ONE);

      expr_t castExpr = create_cast_expr(loc, tv.getp(), theRTM.DOUBLE_TYPE_ONE, true);

      expr_t ret = new if_expr(sctxid(), loc, sctx_p, condExpr, castExpr, nanExpr);

      expr_t data_expr = wrap_in_atomization(arguments[0]);

      nodestack.push(&*wrap_in_let_flwor(new treat_expr(sctxid(),
                                                        loc,
                                                        data_expr,
                                                        theRTM.ANY_ATOMIC_TYPE_QUESTION,
                                                        XPTY0004),
                                         tv,
                                         ret));
      return;
    }
    else if (numArgs == 0 &&
             xquery_fns_def_dot.find(fname) != xquery_fns_def_dot.end()) 
    {
      arguments.push_back(DOT_REF);
    }
    else if (fname == "static-base-uri") 
    {
      if (numArgs != 0)
        ZORBA_ERROR_LOC_PARAM(XPST0017, loc, "fn:static-base-uri", numArgs);

      xqp_string baseuri = sctx_p->final_baseuri ();
      if (baseuri.empty())
        nodestack.push(create_seq(loc));
      else
        nodestack.push(new cast_expr(sctxid(),
                                     loc,
                                     new const_expr(sctxid(), loc, baseuri),
                                     GENV_TYPESYSTEM.ANY_URI_TYPE_ONE));
      return;
    }
    else if (fname == "id")
    {
      if (numArgs == 1)
      {
        arguments.insert(arguments.begin(), DOT_REF);
      }

      expr_t idsExpr = arguments[1];

      rchandle<flwor_expr> flworExpr = wrap_expr_in_flwor(idsExpr, false);

      const for_clause* fc = reinterpret_cast<const for_clause*>((*flworExpr.getp())[0]);
      expr* flworVarExpr = fc->get_var();

      fo_expr_t normExpr;
      fo_expr_t tokenExpr;
      rchandle<const_expr> constExpr = new const_expr(sctxid(), loc, xqpString(" "));

      normExpr = new fo_expr(sctxid(),
                             loc,
                             GET_BUILTIN_FUNCTION(FN_NORMALIZE_SPACE_1), 
                             flworVarExpr);
      normalize_fo(normExpr);

      tokenExpr = new fo_expr(sctxid(),
                              loc,
                              GET_BUILTIN_FUNCTION(FN_TOKENIZE_2),
                              normExpr.getp(),
                              constExpr.getp());
      normalize_fo(tokenExpr);

      flworExpr->set_return_expr(tokenExpr.getp());

      pop_scope();

      arguments[1] = flworExpr;
    }
    else if (numArgs == 1 && fname == "idref")
    {
      arguments.insert(arguments.begin(), DOT_REF);
    } 
    else if (numArgs == 1 && fname == "lang") 
    {
      arguments.insert(arguments.begin(), DOT_REF);
    } 
    else if (numArgs == 1 && fname == "resolve-uri") 
    {
      arguments.insert(arguments.begin(), new const_expr(sctxid(), loc, sctx_p->final_baseuri()));
    }
    else if (numArgs == 1 && fname == "parse") 
    {
      arguments.insert(arguments.begin(), new const_expr(sctxid(), loc, sctx_p->final_baseuri()));
    }
    else if (fname == "concat")
    {
      if (numArgs < 2)
        ZORBA_ERROR_LOC_PARAM (XPST0017, loc, "concat", to_string(numArgs));
    }
    else if (fname == "doc")
    {
      if (numArgs > 0) 
      {
        expr_t  doc_uri = arguments[0];
        //validate uri
        if(doc_uri->get_expr_kind() == const_expr_kind)
        {
          const_expr* const_uri = reinterpret_cast<const_expr*>(doc_uri.getp());
          const store::Item* uri_value = const_uri->get_val();
          xqpStringStore_t uri_string = uri_value->getStringValue();
          try
          {
            xqpString xqp_uri_string(uri_string);
            //xqpString   xqp_base_uri("http://website/");
            //URI   baseURI(xqp_base_uri, false);
            if(uri_string->indexOf(":/") >= 0)
            {
              URI docURI(xqp_uri_string, true);//with validate`
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

  //  Some special processing is required for certain "zorba" functions
  else if (fn_ns->byteEqual(ZORBA_OP_NS)) 
  {
    if (fname == "inline-xml" && numArgs == 1) 
    {
      nodestack.push(new eval_expr(sctxid(),
                                   loc,
                                   create_cast_expr(loc,
                                                    arguments[0],
                                                    theRTM.STRING_TYPE_ONE,
                                                    true)));
      return;
    }
  }

  numArgs = arguments.size();  // recompute size

  // Check if this is a call to a builtin constructor function
  xqtref_t type = CTXTS->create_named_type(sctx_p->lookup_elem_qname(prefix, fname, loc),
                                           TypeConstants::QUANT_QUESTION);

  if (type != NULL) 
  {
    if (numArgs != 1 ||
        TypeOps::is_equal(*type, *GENV_TYPESYSTEM.NOTATION_TYPE_QUESTION) ||
        TypeOps::is_equal(*type, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_QUESTION))
    {
      ZORBA_ERROR_LOC_PARAM(XPST0017, loc, prefix + ":" + fname, numArgs);
    }

    nodestack.push(create_cast_expr(loc, arguments[0], type, true));
  }

  // It is not a builtin constructor function
  else 
  {
    function* f = LOOKUP_FN(prefix, fname, numArgs);
    if (f == NULL)
    {
      ZORBA_ERROR_LOC_PARAM(XPST0017,
                            loc,
                            (prefix.empty () ? prefix : (prefix + ":")) + fname,
                            to_string(numArgs));
    }

    // If this is a udf that is invoked from another udf, mark that other udf
    // as a non-leaf function.
    if (NULL != dynamic_cast<user_function*>(f)) 
    {
      if (! fn_decl_stack.empty()) 
      {
        user_function* udf = dynamic_cast<user_function *>(fn_decl_stack.back());
        ZORBA_ASSERT(udf != NULL);
        udf->setLeaf(false);
      }
    }

    std::reverse(arguments.begin(), arguments.end());

    fo_expr_t foExpr = new fo_expr(sctxid(), loc, f, arguments);

    normalize_fo(foExpr);

    if (f->getKind() == FunctionConsts::FN_ZORBA_DDL_PROBE_INDEX_RANGE_N ||
        f->getKind() == FunctionConsts::FN_ZORBA_DDL_PROBE_INDEX_POINT_N)
    {
      FunctionConsts::FunctionKind fkind = FunctionConsts::OP_SORT_NODES_ASC_1;

      foExpr = new fo_expr(sctxid(),
                           foExpr->get_loc(),
                           BuiltinFunctionLibrary::getFunction(fkind),
                           foExpr);
    }

    nodestack.push(foExpr.getp());
  }
}


/*******************************************************************************
  [116a] ArgList := ExprSingle ("," ExprSingle)*
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
  rchandle<QName> start_tag = v.get_elem_name ();

  if (end_tag != NULL && start_tag->get_qname() != end_tag->get_qname ())
    ZORBA_ERROR_LOC_DESC_OSS(XPST0003, loc,
                             "Start tag " << start_tag->get_qname()
                             << " does not match end tag " << end_tag->get_qname());

  if (v.get_dir_content_list() != NULL)
    contentExpr = pop_nodestack();

  if (v.get_attr_list() != NULL)
    attrExpr = pop_nodestack();

  nameExpr = new const_expr(sctxid(),
                            loc,
                            sctx_p->lookup_elem_qname(v.get_elem_name()->get_qname(),
                                                      loc));

  nodestack.push(new elem_expr(sctxid(),
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
void* begin_visit(const DirAttributeList& v) 
{
  TRACE_VISIT();

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

    attr_expr* attrExpr = expr.dyn_cast<attr_expr>().getp();

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
    std::vector<expr_t> args; 
    for (vector<rchandle<attr_expr> >::reverse_iterator it = attributes.rbegin();
         it != attributes.rend();
         ++it)
    {
      args.push_back((*it).getp());
    }

    fo_expr* expr_list = new fo_expr(sctxid(),
                                     v.get_location(),
                                     op_concatenate,
                                     args);

    normalize_fo(expr_list);

    nodestack.push(expr_list);
  }

  return NULL;  // reject visitor -- everything done
}

void end_visit(const DirAttributeList& v, void* /*visit_state*/) 
{
  // begin_visit() rejects visitor
  ZORBA_ASSERT(false);
}


/*******************************************************************************
  [120a] DirAttr ::= (S (QName S? "=" S? DirAttributeValue)
********************************************************************************/
void* begin_visit(const DirAttr& v) 
{
  TRACE_VISIT();
  // boundary is needed because the value of an attribute might be empty
  nodestack.push(NULL);
  return no_state;
}

void end_visit(const DirAttr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

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

    const_expr* constValueExpr = valueExpr.dyn_cast<const_expr>().getp();
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
    expr_t nameExpr = new const_expr(sctxid(),
                                     loc,
                                     sctx_p->lookup_qname("",
                                                          qname->get_qname(),
                                                          qname->get_location()));

    fo_expr* foExpr;
    if ((foExpr = dynamic_cast<fo_expr*>(valueExpr.getp())) != NULL &&
        foExpr->get_func()->getKind() == FunctionConsts::OP_ENCLOSED_1)
    {
      foExpr->set_arg(0, wrap_in_atomization(foExpr->get_arg(0, false)));
    }
    else if (valueExpr != NULL)
    {
      valueExpr = wrap_in_atomization(valueExpr);
    }

    expr_t attrExpr = new attr_expr(sctxid(), loc, nameExpr, valueExpr);

    nodestack.push(attrExpr);
  }
}


/*******************************************************************************
  [119a] DirElemContentList ::= DirElemContent |
                                DirElemContentList DirElemContent
********************************************************************************/
void* begin_visit(const DirElemContentList& v) 
{
  TRACE_VISIT();

  nodestack.push(NULL);
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
    nodestack.push(args[0]);
  }
  else 
  {
    fo_expr_t expr_list = new fo_expr(sctxid(),
                                      v.get_location(),
                                      op_concatenate,
                                      args);
    
    normalize_fo(expr_list.getp());

    nodestack.push(expr_list.getp());
  }
}


void* begin_visit(const DirElemContent& v) 
{
  TRACE_VISIT();

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
      expr_t content = new const_expr (sctxid(), loc, v.get_elem_content());
      nodestack.push (new text_expr(sctxid(), loc,
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
  expr_t content = new const_expr (sctxid(), loc, v.get_cdata_content ());
  nodestack.push (new text_expr (sctxid(), loc, text_expr::text_constructor, content));
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
    nodestack.push(args[0]);
  }
  else if (args.size() > 1)
  {
    fo_expr_t expr_list = new fo_expr(sctxid(),
                                      loc,
                                      op_concatenate,
                                      args);
    normalize_fo(expr_list.getp());

    nodestack.push(expr_list.getp());
  }
}


void* begin_visit(const QuoteAttrContentList& v) 
{
  TRACE_VISIT();

  nodestack.push(NULL);
  return no_state;
}

void end_visit(const QuoteAttrContentList& v, void* visit_state) 
{
  TRACE_VISIT_OUT ();
  attr_content_list(loc, visit_state);
}


void *begin_visit(const AposAttrContentList& v) 
{
  TRACE_VISIT ();

  nodestack.push(NULL);
  return no_state;
}

void end_visit (const AposAttrContentList& v, void* visit_state) 
{
  TRACE_VISIT_OUT ();
  attr_content_list (loc, visit_state);
}


void attr_val_content (const QueryLoc& loc, const CommonContent *cc, xqpString content)
{
  if (cc == NULL) 
  {
    nodestack.push(new const_expr (sctxid(), loc, content));
  }
  else
  {
    // nothing to be done because when common content != NULL,
    // the corresponding expr is already on the stack
  }
}


void *begin_visit (const QuoteAttrValueContent& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const QuoteAttrValueContent& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
  attr_val_content (loc, v.get_common_content(), v.get_quot_atcontent());
}


void *begin_visit (const AposAttrValueContent& v) 
{
  TRACE_VISIT ();
  return no_state;
}
 
void end_visit (const AposAttrValueContent& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
  attr_val_content (loc, v.get_common_content(), v.get_apos_atcontent());
}


void* begin_visit (const CommonContent& v) 
{
  TRACE_VISIT ();

  return no_state;
}

void end_visit (const CommonContent& v, void* /*visit_state*/) 
{
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

    expr_t lConstExpr = new const_expr(sctxid(), loc, content);
    nodestack.push(lConstExpr);
    break;
  }
  case ParseConstants::cont_escape_lbrace:
    {
    // we always create a text node here because if we are in an attribute, we atomice
    // the text node into its string value
    xqpString content("{");
    expr_t lConstExpr = new const_expr(sctxid(), loc, content);
    nodestack.push ( lConstExpr );
    break;
  }
  case ParseConstants::cont_escape_rbrace:
  {
    // we always create a text node here because if we are in an attribute, we atomice
    // the text node into its string value
    xqpString content("}");
    expr_t lConstExpr = new const_expr(sctxid(), loc, content);
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
  expr_t content = new const_expr (sctxid(), loc, str);
  nodestack.push (new text_expr(sctxid(), loc,
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
    target = new const_expr (sctxid(), loc, target_str),
    content = new const_expr (sctxid(), loc, v.get_pi_content ());
  nodestack.push (new pi_expr (sctxid(), loc, target,  content));
}


void *begin_visit (const CompDocConstructor& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const CompDocConstructor& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  expr_t lContent = pop_nodestack();

  fo_expr* lEnclosed = new fo_expr(sctxid(), loc, op_enclosed, lContent);

  nodestack.push(new doc_expr(sctxid(), loc, lEnclosed));
}


void *begin_visit (const CompElemConstructor& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const CompElemConstructor& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();

  expr_t nameExpr;
  expr_t contentExpr;

  if (v.get_content_expr() != 0) 
  {
    contentExpr = pop_nodestack();

    fo_expr* lEnclosed = new fo_expr(sctxid(), loc, op_enclosed, contentExpr);
    contentExpr = lEnclosed;
  }

  QName* constQName = v.get_qname_expr().dyn_cast<QName> ().getp();

  if (constQName != NULL) 
  {
    nameExpr = new const_expr(sctxid(), loc,
                              sctx_p->lookup_elem_qname(constQName->get_qname(), loc));
  }
  else 
  {
    nameExpr = pop_nodestack();

    expr_t atomExpr = wrap_in_atomization(nameExpr);
    nameExpr = new name_cast_expr(sctxid(), loc, atomExpr.getp(), ns_ctx);
  }

  nodestack.push (new elem_expr(sctxid(), loc, nameExpr, contentExpr, ns_ctx));
}


void* begin_visit(const CompAttrConstructor& v) 
{
  TRACE_VISIT ();
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

    fo_expr* enclosedExpr = new fo_expr(sctxid(), loc, op_enclosed, valueExpr);
    valueExpr = enclosedExpr;
  }

  QName* constQName = v.get_qname_expr().dyn_cast<QName>().getp();

  if (constQName != NULL)
  {
    nameExpr = new const_expr(sctxid(), loc,
                              sctx_p->lookup_qname("",
                                                   constQName->get_qname(),
                                                   constQName->get_location()));
  }
  else
  {
    nameExpr = pop_nodestack();
    expr_t atomExpr = wrap_in_atomization(nameExpr);
    nameExpr = new name_cast_expr(sctxid(), loc, atomExpr.getp(), ns_ctx);
  }

  attrExpr = new attr_expr(sctxid(), loc, nameExpr, valueExpr);

  nodestack.push(attrExpr);
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

  fo_expr_t enclosedExpr = new fo_expr(sctxid(), loc, op_enclosed, inputExpr);

  expr_t textExpr = new text_expr(sctxid(), loc,
                                  text_expr::comment_constructor,
                                  enclosedExpr.getp());

  nodestack.push(textExpr);
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
    content = create_seq(loc);
  }
  else 
  {
    content = pop_nodestack();

    fo_expr_t enclosedExpr = new fo_expr(sctxid(), loc, op_enclosed, content);
    content = enclosedExpr;
  }

  if (v.get_target_expr() != NULL) 
  {
    target = pop_nodestack();

    expr_t castExpr = create_cast_expr(loc, target.getp(), theRTM.NCNAME_TYPE_ONE, true);

    fo_expr_t enclosedExpr = new fo_expr(sctxid(), loc, op_enclosed, castExpr.getp());
    target = enclosedExpr;
  }

  expr_t e = (v.get_target_expr () != NULL ?
              new pi_expr(sctxid(), loc, target, content) :
              new pi_expr(sctxid(), loc, new const_expr(sctxid(), loc, v.get_target()), content));

  nodestack.push (e);
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

  fo_expr_t enclosedExpr = new fo_expr(sctxid(), loc, op_enclosed, inputExpr);

  expr_t textExpr = new text_expr(sctxid(), loc,
                                  text_expr::text_constructor,
                                  enclosedExpr.getp());

  nodestack.push(textExpr);
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
    theTypeStack.push(CTXTS->create_type(*pop_tstack(), TypeConstants::QUANT_QUESTION));
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
    theTypeStack.push (GENV_TYPESYSTEM.EMPTY_TYPE);
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
    theTypeStack.push (CTXTS->create_type (*pop_tstack (), q));

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
    theTypeStack.push (t);
}


void *begin_visit (const ItemType& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ItemType& v, void* /*visit_state*/) {
  TRACE_VISIT_OUT ();
  theTypeStack.push (GENV_TYPESYSTEM.ITEM_TYPE_ONE);
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
    rchandle<match_expr> me = new match_expr(sctxid(), loc);
    me->setTestKind(match_anykind_test);
    axisExpr->setTest(me);
  } else {
    theTypeStack.push(GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE);
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
      match = new match_expr(sctxid(), loc);
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
        
    xqtref_t docTest = CTXTS->create_node_type(store::StoreConsts::documentNode,
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
    rchandle<match_expr> me = new match_expr(sctxid(), loc);
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
    theTypeStack.push(seqmatch);
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

    rchandle<match_expr> match = new match_expr(sctxid(), loc);
    match->setTestKind(match_xs_elem_test);
    match->setQName(elemQNameItem);
    match->setTypeName(typeQNameItem);

    axisExpr->setTest(match);
  }
  else
  {
    try {
      xqtref_t seqmatch = CTXTS->create_schema_element_type(elemQNameItem,
          TypeConstants::QUANT_ONE);
      theTypeStack.push(seqmatch);
    } catch (error::ZorbaError& e) {
      ZORBA_ERROR_LOC_DESC(e.theErrorCode, v.get_location(), e.theDescription);
    }
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
    rchandle<match_expr> match = new match_expr(sctxid(), loc);
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

    theTypeStack.push(seqmatch);
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

    rchandle<match_expr> match = new match_expr(sctxid(), loc);
    match->setTestKind(match_xs_attr_test);
    match->setQName(attrQNameItem);
    match->setTypeName(typeQNameItem);

    axisExpr->setTest(match);
  }
  else 
  {
    xqtref_t seqmatch = CTXTS->create_schema_attribute_type(attrQNameItem,
                                                            TypeConstants::QUANT_ONE);

    theTypeStack.push(seqmatch);
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
    rchandle<match_expr> match = new match_expr(sctxid(), loc);
    match->setTestKind(match_text_test);
    axisExpr->setTest(match);
  }
  else 
  {
    theTypeStack.push(GENV_TYPESYSTEM.TEXT_TYPE_ONE);
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
    rchandle<match_expr> match = new match_expr(sctxid(), loc);
    match->setTestKind(match_comment_test);
    axisExpr->setTest(match);
  }
  else 
  {
    theTypeStack.push(GENV_TYPESYSTEM.COMMENT_TYPE_ONE);
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
    rchandle<match_expr> match = new match_expr(sctxid(), loc);
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


/* update-related */
void *begin_visit (const DeleteExpr& v) {
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const DeleteExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  expr_t lTarget = pop_nodestack();
  if (lTarget->is_updating()) 
  {
    ZORBA_ERROR_LOC(XUST0001, loc);
  }

  expr_t aDelete = new delete_expr(sctxid(), loc, lTarget);
  nodestack.push(aDelete);
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

  if (lTarget->is_updating() || lSource->is_updating()) 
  {
    ZORBA_ERROR_LOC(XUST0001, loc);
  }

  fo_expr_t lEnclosed = new fo_expr(sctxid(), loc, op_enclosed, lSource);
  lSource = lEnclosed;

  expr_t lInsert = new insert_expr(sctxid(), loc, v.getType(), lSource, lTarget);
  nodestack.push(lInsert);
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

  if (nameExpr->is_updating() || targetExpr->is_updating()) {
    ZORBA_ERROR_LOC(XUST0001, loc);
  }

  rchandle<fo_expr> atomExpr = (fo_expr*)wrap_in_atomization (nameExpr).getp();
  nameExpr = new name_cast_expr(sctxid(), loc, atomExpr.getp(), ns_ctx);

  expr_t renameExpr = new rename_expr(sctxid(), loc, targetExpr, nameExpr);

  nodestack.push(renameExpr);
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
  if (lReplacement->is_updating() || lTarget->is_updating()) 
  {
    ZORBA_ERROR_LOC(XUST0001, loc);
  }

  if (v.getType() == store::UpdateConsts::NODE) 
  {
    fo_expr_t lEnclosed = new fo_expr(sctxid(), loc, op_enclosed, lReplacement);
    lReplacement = lEnclosed;
  }

  expr_t lReplace = new replace_expr(sctxid(), loc,
                                     v.getType(),
                                     lTarget,
                                     lReplacement);
  nodestack.push(lReplace);
}


void* begin_visit(const RevalidationDecl& v) 
{
  TRACE_VISIT();

  CHK_SINGLE_DECL (hadBUriDecl, XUST0003);
  sctx_p->set_validation_mode(v.get_mode());
  return no_state;
}

void end_visit (const RevalidationDecl& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT ();
}


void* begin_visit(const TransformExpr& v) 
{
  TRACE_VISIT();

  transform_expr* transformExpr = new transform_expr(sctxid(),
                                                     loc,
                                                     NULL,
                                                     NULL);
  nodestack.push(transformExpr);

  return no_state;
}

void end_visit(const TransformExpr& v, void* /*visit_state*/) 
{
  TRACE_VISIT_OUT();

  expr_t returnExpr = pop_nodestack();
  if (returnExpr->is_updating()) 
  {
    ZORBA_ERROR_LOC(XUST0001, loc);
  }

  expr_t modifyExpr = pop_nodestack();
  if (! modifyExpr->is_updating_or_vacuous()) 
  {
    ZORBA_ERROR_LOC(XUST0002, loc);
  }

  transform_expr* transformExpr = dynamic_cast<transform_expr*>(nodestack.top().getp());
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
  bind_var_and_push(loc, v.get_varname(), var_expr::copy_var);

  return no_state;
}

void end_visit (const VarBinding& v, void*) 
{
  TRACE_VISIT_OUT ();

  expr_t sourceExpr = pop_nodestack();
  if (sourceExpr->is_updating()) 
  {
    ZORBA_ERROR_LOC(XUST0001, loc);
  }

  var_expr_t varExpr = pop_nodestack_var();

  transform_expr* transformExpr = dynamic_cast<transform_expr*>(nodestack.top().getp());
  assert(transformExpr != NULL);

  copy_clause* copyClause = new copy_clause(varExpr, sourceExpr);

  transformExpr->add_back(copyClause);
}


/*******************************************************************************
  [169] TryCatchExpr ::= TryClause CatchClauseList

  [170] TryClause ::= "try" "{" TryTargetExpr "}"

  [171] TryTargetExpr ::= Expr
********************************************************************************/
void* begin_visit(const TryExpr& v) 
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const TryExpr& v, void* visit_state) 
{
  TRACE_VISIT_OUT();
}


void* begin_visit(const CatchListExpr& v) 
{
  TRACE_VISIT();

  expr_t tryExpr = pop_nodestack();

  trycatch_expr* tce = new trycatch_expr(sctxid(), loc, tryExpr);

  nodestack.push(tce);

  return no_state;
}

void end_visit(const CatchListExpr& v, void* visit_state) 
{
  TRACE_VISIT_OUT();
  
  trycatch_expr* tce = static_cast<trycatch_expr*>(nodestack.top().getp());

  tce->compute_scripting_kind();
}


void* begin_visit(const CatchExpr& v) 
{
  TRACE_VISIT();

  trycatch_expr* tce = dynamic_cast<trycatch_expr *>(&*nodestack.top());

  catch_clause_t cc = new catch_clause();

  push_scope();

  if (v.getVarErrorCode() != "") 
  {
    varref_t ev = bind_var(loc,
                           v.getVarErrorCode(),
                           var_expr::catch_var,
                           theRTM.QNAME_TYPE_QUESTION);

    cc->set_error_code_var(ev);

    if (v.getVarErrorDescr() != "") 
    {
      varref_t dv = bind_var(loc,
                             v.getVarErrorDescr(),
                             var_expr::catch_var,
                             theRTM.STRING_TYPE_QUESTION);

      cc->set_error_desc_var(dv);

      if (v.getVarErrorVal() != "") 
      {
        varref_t vv = bind_var(loc,
                               v.getVarErrorVal(), 
                               var_expr::catch_var,
                               theRTM.ITEM_TYPE_QUESTION);

        cc->set_error_item_var(vv);
      }
    }
  }

  tce->add_clause_in_front(cc);

  return no_state;
}

void end_visit(const CatchExpr& v, void* visit_state) 
{
  TRACE_VISIT_OUT();

  expr_t ce = pop_nodestack();
  trycatch_expr* tce = dynamic_cast<trycatch_expr *>(&*nodestack.top());

  catch_clause* cc = &*(*tce)[0];
  cc->set_catch_expr(ce);

  pop_scope();
}



void* begin_visit(const EvalExpr& v) 
{
  TRACE_VISIT();
  if (sctx_p->xquery_version() < StaticContextConsts::xquery_version_1_1)
    ZORBA_ERROR_LOC_DESC(XPST0003, loc,
                         "Eval is a feature that is only available in XQuery 1.1 or later.");
  return no_state;
}

void end_visit(const EvalExpr& v, void* visit_state) 
{
  TRACE_VISIT_OUT();

  rchandle<eval_expr> result =
    new eval_expr(sctxid(),
                  loc,
                  create_cast_expr(loc, pop_nodestack(), theRTM.STRING_TYPE_ONE, true));

  rchandle<VarGetsDeclList> vgdl = v.get_vars ();
  
  for (size_t i = 0; i < vgdl->size(); i++) 
  {
    varref_t ve = pop_nodestack ().dyn_cast<var_expr> ();
    ve->set_kind (var_expr::eval_var);
    expr_t val = pop_nodestack ();

    if (ve->get_type () != NULL)
      val = new treat_expr(sctxid(),
                           val->get_loc(),
                           val,
                           ve->get_type(),
                           XPTY0004);

    result->add_var (eval_expr::eval_var (&*ve, val));

    pop_scope ();
  }

  nodestack.push (&*result);
}



void *begin_visit (const AssignExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const AssignExpr& v, void* visit_state) 
{
  TRACE_VISIT_OUT();

  // TODO: add treat_expr to check var type
  varref_t ve = lookup_ctx_var (v.get_varname (), loc);
  if (ve->get_kind() != var_expr::local_var && ve->get_kind() != var_expr::prolog_var)
    ZORBA_ERROR_LOC (XPST0003, loc);

  expr_t qname_expr = new const_expr(sctxid(),
                                     ve->get_loc(),
                                     dynamic_context::var_key(&*ve));

  nodestack.push(new fo_expr(sctxid(), loc, var_set, qname_expr, pop_nodestack()));
}


void* begin_visit(const ExitExpr& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit(const ExitExpr& v, void* visit_state) 
{
  TRACE_VISIT_OUT();
  nodestack.push (new exit_expr(sctxid(), loc, pop_nodestack()));
}


void* begin_visit(const WhileExpr& v) 
{
  TRACE_VISIT();
  return no_state;
}

void end_visit(const WhileExpr& v, void* visit_state) 
{
  TRACE_VISIT_OUT();

  expr_t body = pop_nodestack();
  expr_t cond = pop_nodestack();

  sequential_expr* seqBody = NULL;

  if (body->get_expr_kind() != sequential_expr_kind)
  {
    seqBody = new sequential_expr(body->get_sctx_id(), body->get_loc());
    seqBody->push_back(body);
    body = seqBody;
  }
  else
  {
    seqBody = static_cast<sequential_expr*>(body.getp());
  }

  seqBody->push_front(new if_expr(sctxid(),
                                  loc,
                                  sctx_p,
                                  cond,
                                  create_seq(loc),
                                  new flowctl_expr(sctxid(), loc, flowctl_expr::BREAK)));

  nodestack.push(new while_expr(sctxid(), loc, seqBody));
}


void *begin_visit (const FlowCtlStatement& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const FlowCtlStatement& v, void* visit_state) 
{
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
  nodestack.push (new flowctl_expr (sctxid(), loc, a));
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

void *begin_visit (const ParseErrorNode& v) 
{
  TRACE_VISIT ();
  return no_state;
}

void end_visit (const ParseErrorNode& v, void* /*visit_state*/) 
{
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

  ZORBA_ASSERT (theTypeStack.size () == 0);

  if (scope_depth != 0) 
  {
    cout << "Error: scope depth " << scope_depth << endl;
    ZORBA_ASSERT (false);
  }

  return pop_nodestack ();
}

};


/*******************************************************************************
  Translate a module.
********************************************************************************/
expr_t translate_aux(
    const parsenode& root,
    static_context* rootSctx,
    short rootSctxId,
    ModulesInfo* minfo,
    set<string> mod_stack,
    bool isLibModule) 
{
  auto_ptr<TranslatorImpl> t(new TranslatorImpl(rootSctx,
                                                rootSctxId,
                                                minfo,
                                                mod_stack,
                                                isLibModule));

  root.accept(*t);

  rchandle<expr> result = t->result();

  CompilerCB* ccb = minfo->theCCB;
  if (ccb->theConfig.translate_cb != NULL)
    ccb->theConfig.translate_cb(&*result, "XQuery program");

  return result;
}


expr_t translate(const parsenode& root, CompilerCB* ccb) 
{
  set<string> mod_stack;

  if (typeid(root) != typeid(MainModule))
  {
    ZORBA_ERROR_LOC_DESC(XPST0003,
                         root.get_location(),
                         "Module declaration must not be used in a main module");
  }

  ModulesInfo minfo(ccb);

  return translate_aux(root,
                       ccb->theRootSctx,
                       ccb->theSctxMap->size(),
                       &minfo,
                       mod_stack,
                       false);
}

} /* namespace zorba */

