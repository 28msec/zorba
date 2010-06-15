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
#ifndef ZORBA_CONTEXT_STATIC_CONTEXT_H
#define ZORBA_CONTEXT_STATIC_CONTEXT_H

#include <memory>
#include <set>

#include <zorba/api_shared_types.h>

#ifdef WIN32
#include "store/api/item.h"
#include "compiler/expression/expr_base.h"
#include "types/typemanager.h"
#endif

#include "context/static_context_consts.h"
#include "context/decimal_format.h"
#include "context/internal_uri_resolvers.h"

#include "common/shared_types.h"


namespace zorba
{

class expr;
class ftmatch_options;
class var_expr;
class function;
class XQType;
class ExternalModule;
class IndexDecl;
class QueryLoc;
class namespace_node;
class user_function;
class TypeManager;
class XQPCollator;

template <class V> class serializable_ItemPointerHashMap;
template <class V> class serializable_HashMapStrHandle;

class IndexDecl;
typedef rchandle<IndexDecl> IndexDecl_t;

class ValueIC;
typedef rchandle<ValueIC> ValueIC_t;

class StaticallyKnownCollection;
typedef rchandle<StaticallyKnownCollection> StaticallyKnownCollection_t;


/*******************************************************************************
  Base Uri Computation

  from_prolog_baseuri          --> uri
  baseuri                      --> uri
  encapsulating_entity_baseuri --> uri
  entity_retrieval_url         --> uri

  current_absolute_baseuri     --> uri

  The from_prolog_baseuri is the one declared in the prolog. The baseuri is set
  explicitly from the C++/C api. If both the from_prolog_baseuri and the baseuri
  are set, the from_prolog_baseuri hides the baseuri.

  The entity_retrieval_url is set by default to the name of file containing the
  query we are running. It may also be set explicitly from the C++/C api.
********************************************************************************/
struct BaseUriInfo : public ::zorba::serialization::SerializeBaseClass
{
  xqpStringStore_t thePrologBaseUri;
  xqpStringStore_t theApplicationBaseUri;
  xqpStringStore_t theEntityRetrievalUri;
  xqpStringStore_t theEncapsulatingEntityUri;

  xqpStringStore_t theBaseUri;

public:
  SERIALIZABLE_CLASS(BaseUriInfo)
  SERIALIZABLE_CLASS_CONSTRUCTOR(BaseUriInfo)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  BaseUriInfo() {}
};


/*******************************************************************************

********************************************************************************/
struct PrologOption : public ::zorba::serialization::SerializeBaseClass
{
  store::Item_t    theName;
  xqpStringStore_t theValue;

public:
  SERIALIZABLE_CLASS(PrologOption)
  SERIALIZABLE_CLASS_CONSTRUCTOR(PrologOption)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  PrologOption() {}

  PrologOption(const store::Item* name, const xqpStringStore* value)
    :
    theName(const_cast<store::Item*>(name)),
    theValue(const_cast<xqpStringStore*>(value))
  {
  }
};


/***************************************************************************//**
  XQuery 1.1 static context
	[http://www.w3.org/TR/xquery/#id-xq-context-components]

  Class static_context implements a node in the hierarchy of static contextes.
  The root of this hierarchy is a global (singleton) sctx that is shared by all
  queries. This global root sctx is created during engine statrtup and is
  initialized with the default values specified by the W3C spec. After its
  creation, it is accessible via the singleton GlobalEnvironment obj (see
  GENV_ROOT_STATIC_CONTEXT macro in src/system/globalenv.h). We call this the
  "zorba root sctx".

  An application can create sctx objs using the Zorba::createStaticContext()
  API method. The application can then set various components of such an sctx
  obj using the API methods provided by the StaticContext class (which is a
  wrapper of the internal static_context class). All application-created sctx
  objs are created as children of the zorba root sctx.

  For a particular query, its root sctx may be (a) a child of an application-
  created sctx obj, or (b) if the query is a load-prolog query, the application
  created sctx obj itself, or (c) if the app did not provide any sctx, a child
  of zorba's root sctx. In cases (a) and (b) the application provides its sctx
  to the query via the Zorba:compileQuery() or the XQuery::compile() API methods.
  The query root sctx is populated with the declarations found in the prolog of
  the main module and the declarations that are imported from the modules that
  the main module imports.

  Each library module participating in a query has its a root sctx as well,
  which is a child of the zorba root sctx, or the application provided sctx
  (if any). (This implies that an application provided sctx is "visible" to
  all the modules of a query). A module root sctx contains the declarations
  found in the prolog of the associated module and the declarations that are
  imported from other modules.

  Additional sctx objs may be created under the query or module root sctxs. Such
  expression-level sctx objs provide scoping contextes for variables, namespace
  bindings, etc. They both inherit and hide information from their ancestor sctxs.

  Expression-level sctx objs are created and maintained only during the
  translation of a module; afterwards they are discarded. In contrast, query
  and module root sctx objs stay around for the whole life of a query (including
  runtime). Such sctxs are registered in XQueryImpl::theSctxMap.


  Data Members of Class static_context:


  theParent :
  -----------

  Pointer to the parent sctx object in the sctx hierarchy.

  theTraceStream :
  ----------------

  Output stream that is used by the fn:trace function. std::cerr is the default
  if the user didn't provide one.

  theQueryExpr :
  --------------

  If this sctx is the root sctx for a mainModule, theQueryExpr is the result
  of the translation of that mainModule. It is used in implementing the
  loadProlog api.

  theModuleNamespace :
  --------------------

  If this is the root sctx of a library module, theModuleNamespace stores the
  target namespace URI of that module.

  theBaseUriInfo :
  ----------------

  Stores various URIs that participate in the computation of the module's base
  URI, as described in the W3C spec.

  theDocResolver :
  ----------------

  URI resolver used for retrieving documents (used by fn:doc and fn:doc-available).

  theColResolver :
  ----------------

  URI resolver used for retrieving W3C collections (used by fn:collection).

  theSchemaResolvers :
  -------------------

  Vector of URI resolvers used for retrieving a schema given the schema's target
  namespace and an optional list of URLs that may store the schema.

  theModuleResolvers :
  -------------------

  Vector of URI resolvers used for retrieving (a) the URIs of the components of
  a module given the module's target namespece and then (b) a module component
  given its URI. Actually, the URI resolvers registered in this vector are used
  by the (singleton) StandardModuleURIResolver, which implements the full module
  resolution protocol (see ./standard_uri_resolvers.cpp). Normally, the URI
  resolvers registered here are user-provided ones.

  theModulePaths :
  ----------------

  Vector of absolute directory pathnames for directories that contain module
  files and/or schema files and/or library files that contain the implementations
  of external functions. The Zorba root sctx stores a number of predefined paths.
  Applications may register additional paths in their own sctx objs. These
  directory pathnames are used by the StandardModuleURIResolver and the
  StandardSchemaURIResolver, which implement the full resulution protocol for
  modules and schemas, respectively.

  theExternalModulesMap :
  -----------------------

  theTypemgr :
  ------------

  If non NULL, then "this" is the root sctx of a module, and theTypemgr stores
  the schemas that are imported by the associated module (in-scope element
  declarations, in-scope attribute declarations and in-scope type declarations).

  theNamespaceBindings :
  ----------------------

  A hash map whose entries map qname prefixes to namespace URIs.

  theDefaultElementNamespace :
  ----------------------------

  The namespace URI to be used for element and type qnames whose prefix is empty.

  theDefaultFunctionNamespace :
  -----------------------------

  The namespace URI to be used for function qnames whose prefix is empty.

  theCtxItemType :
  ----------------

  theVariablesMap :
  -----------------

  theFunctionMap :
  ----------------

  An entry of this hash map maps an expanded qname to the function object with
  that qname. The qname of a function does not fully identify the function; the
  arity is needed together with the qname for a full id. But, most functions
  have a single arity, so for better performance, such functions are registered
  in this map. Functions that have multiple arities, have one of their associated
  function objs registered here and the rest are stored in theFunctionArityMap.

  theFunctionArityMap :
  ---------------------

  An entry of this hash map maps an expanded qname to a vector of function
  objects with that qname. The function ojbects in this vector correspond to
  different versions of a function that all share the same qname but have
  different arities. One of these versions is stored in the theFunctionMap,
  and the rest are regisreded in theFunctionArityMap.

  theCollectionMap :
  ------------------

  A hash mash map mapping XQDDF collection qnames to the objs storing the info
  from the declaration of the associated collections.

  theCollectionCallback :
  -----------------------

  theCollectionCallbackData :
  ---------------------------

  theW3CCollectionMap :
  ---------------------

  theDefaultW3CCollectionType :
  -----------------------------

  theIndexMap :
  -------------

  A hash mash map mapping XQDDF index qnames to the objs storing the info from
  the declaration of the associated index.

  theIndexCallback :
  ------------------

  theIndexCallbackData :
  ----------------------

  theICMap :
  ----------

  A hash mash map mapping XQDDF integrity constraint qnames to the objs storing
  the info from the declaration of the associated integrity constraint.

  theDocumentMap :
  ----------------

  theCollationMap :
  -----------------

  theDefaultCollation :
  ---------------------

  theDecimalFormats :
  -------------------

  Set of decimal formats. Each decimal format is identified by a qname.
  theDecimalFormats must not contain two decimal formats with the same qname.
  If an ancestor sctx contains a decimal format with the same qname as a
  decimal format in "this" sctx, then the decimal format of the ancestor is
  hidden by the decimal format in "this". The set of in-scope decimal formats
  is the union of all decimal foramts in "this" and its ancestors, minus the
  decimal foramts that are hidden by inner-scope decimal formats.


  Note: URI resolvers are not serialized if the plan is serialized. Instead,
  they are set again if the query is loaded. If the user has provided a resolver
  before, he needs to make sure that the resolver is available using the
  SerializationCallback class. The latter also yields for ExternalModules and
  the TraceStream.

********************************************************************************/

class static_context : public SimpleRCObject
{
  typedef serializable_ItemPointerHashMap<StaticallyKnownCollection_t> CollectionMap;

  typedef serializable_ItemPointerHashMap<IndexDecl_t> IndexMap;

  typedef serializable_ItemPointerHashMap<ValueIC_t> ICMap;

  typedef serializable_ItemPointerHashMap<var_expr_t> VariableMap;

  typedef serializable_ItemPointerHashMap<function_t> FunctionMap;

  typedef serializable_ItemPointerHashMap<std::vector<function_t>* > FunctionArityMap;

  typedef serializable_ItemPointerHashMap<PrologOption> OptionMap;

  typedef serializable_HashMapStrHandle<xqpStringStore_t> NamespaceBindings;

  typedef serializable_HashMapStrHandle<xqtref_t> DocumentMap;

  typedef serializable_HashMapStrHandle<xqtref_t> W3CCollectionMap;

  typedef std::map<std::string, XQPCollator*> CollationMap;


public:

  struct ctx_module_t : public ::zorba::serialization::SerializeBaseClass
  {
    ExternalModule * module;
    bool             dyn_loaded_module;
    static_context * sctx;

  public:
    SERIALIZABLE_CLASS(ctx_module_t)
    SERIALIZABLE_CLASS_CONSTRUCTOR(ctx_module_t)
    void serialize(::zorba::serialization::Archiver& ar);

    ctx_module_t() : module(0), dyn_loaded_module(false) {}

    virtual ~ctx_module_t() {}
  };

  typedef serializable_HashMapStrHandle<ctx_module_t> ExternalModuleMap;

protected:
  static_context                        * theParent;

  std::ostream                          * theTraceStream;

  expr_t                                  theQueryExpr;

  std::string                             theModuleNamespace;

  BaseUriInfo                           * theBaseUriInfo;

  InternalDocumentURIResolver           * theDocResolver;

  InternalCollectionURIResolver         * theColResolver;

  std::vector<InternalSchemaURIResolver*> theSchemaResolvers;

  std::vector<InternalModuleURIResolver*> theModuleResolvers;

  checked_vector<std::string>             theModulePaths;

	ExternalModuleMap                     * theExternalModulesMap;

  rchandle<TypeManager>                   theTypemgr;

  NamespaceBindings                     * theNamespaceBindings;
  xqpStringStore_t                        theDefaultElementNamespace;
  xqpStringStore_t                        theDefaultFunctionNamespace;

  xqtref_t                                theCtxItemType;

  VariableMap                           * theVariablesMap;

  FunctionMap                           * theFunctionMap;
  FunctionArityMap                      * theFunctionArityMap;

  CollectionMap                         * theCollectionMap;
  CollectionCallback                      theCollectionCallback;
  void                                  * theCollectionCallbackData;

  W3CCollectionMap                      * theW3CCollectionMap;
  xqtref_t                                theDefaultW3CCollectionType;

  IndexMap                              * theIndexMap;
  IndexCallback                           theIndexCallback;
  void                                  * theIndexCallbackData;

  ICMap                                 * theICMap;

  DocumentMap                           * theDocumentMap;

  CollationMap                          * theCollationMap;
  std::string                           * theDefaultCollation;

  OptionMap                             * theOptionMap;

  ftmatch_options                       * theFTMatchOptions;

  StaticContextConsts::xquery_version_t      theXQueryVersion;

  StaticContextConsts::xpath_compatibility_t theXPathCompatibility;

  StaticContextConsts::construction_mode_t   theConstructionMode;

  StaticContextConsts::inherit_mode_t        theInheritMode;

  StaticContextConsts::preserve_mode_t       thePreserveMode;

  StaticContextConsts::ordering_mode_t       theOrderingMode;

  StaticContextConsts::empty_order_mode_t    theEmptyOrderMode;

  StaticContextConsts::boundary_space_mode_t theBoundarySpaceMode;

  StaticContextConsts::validation_mode_t     theValidationMode;

  std::vector<DecimalFormat_t>             * theDecimalFormats;

public:
  SERIALIZABLE_CLASS(static_context);

  void serialize_resolvers(serialization::Archiver& ar);

  void serialize_tracestream(serialization::Archiver& ar);

  void serialize(serialization::Archiver& ar);

public:
  static_context(::zorba::serialization::Archiver& ar);

  ~static_context();

  static_context* get_parent() const { return theParent; }

  static_context* create_child_context();

  bool is_global_root_sctx() const;

  expr_t get_query_expr() const;

  void set_query_expr(expr_t expr);

  void set_trace_stream(std::ostream&);

  std::ostream* get_trace_stream() const;

  void set_module_namespace(std::string& ns) { theModuleNamespace = ns; }

  const std::string& get_module_namespace() const { return theModuleNamespace; }

  //
  // Base uri
  //
  xqpStringStore_t get_implementation_baseuri() const;

  xqpStringStore_t get_encapsulating_entity_uri() const;

  void set_encapsulating_entity_uri(const xqpStringStore_t& uri);

  xqpStringStore_t get_entity_retrieval_uri() const;

  void set_entity_retrieval_uri(const xqpStringStore_t& uri);

  xqpStringStore_t get_base_uri() const;

  void set_base_uri(const xqpStringStore_t& uri, bool from_prolog = true);

  void compute_base_uri();

  xqpStringStore_t resolve_relative_uri(
        const xqpStringStore_t& uri,
        bool validate = true);

  //
  // URI Resolution
  //
  void set_document_uri_resolver(InternalDocumentURIResolver*);

  InternalDocumentURIResolver* get_document_uri_resolver();

  void set_collection_uri_resolver(InternalCollectionURIResolver*);

  InternalCollectionURIResolver* get_collection_uri_resolver();

  void add_schema_uri_resolver(InternalSchemaURIResolver*);

  void get_schema_uri_resolvers(std::vector<InternalSchemaURIResolver*>& resolvers);

  void remove_schema_uri_resolver(InternalSchemaURIResolver*);

  void add_module_uri_resolver(InternalModuleURIResolver*);

  void remove_module_uri_resolver(InternalModuleURIResolver*);

  void get_module_uri_resolvers(std::vector<InternalModuleURIResolver*>& resolvers) const;

  void set_module_paths(const std::vector<std::string>& aModulePaths);

  void get_module_paths(std::vector<std::string>& aModulePaths) const;

  void get_full_module_paths(std::vector<std::string>& aFullModulePaths) const;

  //
  // Type management
  //
  TypeManager* get_typemanager() const;

  TypeManager* get_local_typemanager() const;

  void set_typemanager(rchandle<TypeManager>);

  //
  // Namespace Bindings
  //
  const xqpStringStore_t& default_elem_type_ns() const;

  void set_default_elem_type_ns(const xqpStringStore_t& ns, const QueryLoc& loc);

  const xqpStringStore_t& default_function_ns() const;

  void set_default_function_ns(const xqpStringStore_t& ns, const QueryLoc& loc);

  void bind_ns(
        xqpStringStore_t& prefix,
        xqpStringStore_t& ns,
        const QueryLoc& loc,
        const XQUERY_ERROR& err = XQST0033);

  bool lookup_ns(
        xqpStringStore_t& ns,
        const xqpStringStore_t& prefix,
        const QueryLoc& loc,
        const XQUERY_ERROR& err = XPST0081) const;

  void expand_qname(
        store::Item_t& qname,
        const xqpStringStore_t& default_ns,
        const xqpStringStore_t& pfx,
        const xqpStringStore_t& local,
        const QueryLoc& loc) const;

  void get_namespace_bindings(
        std::vector<std::pair<xqpStringStore_t, xqpStringStore_t> >& bindings) const;

  //
  // Variables
  //
  void bind_var(
        const store::Item* qname,
        var_expr_t& expr,
        const QueryLoc& loc,
        const XQUERY_ERROR& err);

  var_expr* lookup_var(
        const store::Item* qname,
        const QueryLoc& loc,
        const XQUERY_ERROR& err) const;

  void getVariables(std::vector<std::string>& aVarialeList) const;

  void getVariables(std::vector<var_expr_t>& aVarialeList) const;

	void set_context_item_type(xqtref_t& t);

	const XQType* get_context_item_type();


  //
  // Functions
  //
  void bind_fn(
        const store::Item* qname,
        function_t& f,
        ulong arity,
        const QueryLoc& loc);

  void unbind_fn(const store::Item* qname, ulong arity);

  function* lookup_fn(const store::Item* qname, ulong arity);

  void get_functions(std::vector<function*>& functions) const;

  void find_functions(
        const store::Item* qname,
        std::vector<function*>& functions) const;

  void bind_external_module(
        ExternalModule* aModule,
        bool aDynamicallyLoaded = false);

  StatelessExternalFunction* lookup_stateless_external_function(
        const xqpStringStore_t& prefix,
        const xqpStringStore_t& local);


  //
  // Documents
  //
	void bind_document(xqpStringStore_t& uri, xqtref_t& t);

  const XQType* lookup_document(const xqpStringStore_t& uri);

  void get_all_documents(std::vector<xqpStringStore_t>& documents);

  //
  // W3C Collections
  //
	void bind_w3c_collection(xqpStringStore_t& uri, xqtref_t& t);

  const XQType* lookup_w3c_collection(const xqpStringStore_t& uri);

	void set_default_w3c_collection_type(xqtref_t& t);

	const XQType* get_default_w3c_collection_type();

  //
  // XQDDF Collections
  //
  void bind_collection(StaticallyKnownCollection_t& aCollection, const QueryLoc& aLoc);

  const StaticallyKnownCollection* lookup_collection(const store::Item* aName) const;

  store::Iterator_t collection_names() const;

  //
  // XQDDF Indexes
  //
  void bind_index(const store::Item* qname, IndexDecl_t& vi, const QueryLoc& loc);

  IndexDecl* lookup_index(const store::Item* qname) const;

  store::Iterator_t index_names() const;


  //
  // XQDDF Integrity Constraints
  //
  void bind_ic(const store::Item* qname, ValueIC_t& vic, const QueryLoc& loc);

  ValueIC_t lookup_ic(const store::Item* qname) const;

  store::Iterator_t ic_names() const;


  //
  // Collations
  //
	void add_collation(const std::string& uri, const QueryLoc& loc);

  bool is_known_collation(const std::string& uri);

  XQPCollator* get_collator(const std::string& uri, const QueryLoc& loc);

  void set_default_collation(const std::string& uri, const QueryLoc& loc);

  const std::string& get_default_collation(const QueryLoc& loc) const;

  XQPCollator* get_default_collator(const QueryLoc& loc);

  void get_collations(std::vector<std::string>& collations) const;


  //
  // Options
  //
  void bind_option(const store::Item* qname, const xqpStringStore* option);

  bool lookup_option(const store::Item* qname, xqpStringStore_t& option) const;


  //
  //  Misc
  //
  StaticContextConsts::xquery_version_t xquery_version() const;

  void set_xquery_version(StaticContextConsts::xquery_version_t v);

  void set_xquery_version(const std::string& v);

	StaticContextConsts::xpath_compatibility_t xpath_compatibility() const;

	void set_xpath_compatibility(StaticContextConsts::xpath_compatibility_t v);

	StaticContextConsts::construction_mode_t construction_mode() const;

	void set_construction_mode(StaticContextConsts::construction_mode_t v);

	StaticContextConsts::inherit_mode_t inherit_mode() const;

  void set_inherit_mode(StaticContextConsts::inherit_mode_t v);

	StaticContextConsts::preserve_mode_t preserve_mode() const;

  void set_preserve_mode(StaticContextConsts::preserve_mode_t v);

	StaticContextConsts::ordering_mode_t ordering_mode() const;

	void set_ordering_mode(StaticContextConsts::ordering_mode_t v);

	StaticContextConsts::empty_order_mode_t empty_order_mode() const;

	void set_empty_order_mode(StaticContextConsts::empty_order_mode_t v);

	StaticContextConsts::boundary_space_mode_t boundary_space_mode() const;

	void set_boundary_space_mode(StaticContextConsts::boundary_space_mode_t v);

  StaticContextConsts::validation_mode_t validation_mode() const;

  void set_validation_mode(StaticContextConsts::validation_mode_t v);

  void add_decimal_format(const DecimalFormat_t& format, const QueryLoc& loc);

  DecimalFormat_t get_decimal_format(const store::Item_t& qname);

  ftmatch_options const* get_match_options() const {
    return theFTMatchOptions;
  }

  void set_match_options( ftmatch_options *mo ) {
    theFTMatchOptions = mo;
  }

  //
  // Merge in the static context of a module
  //
  void import_module (const static_context* module, const QueryLoc& loc);

  void set_collection_callback (
      CollectionCallback aCallbackFunction,
      void* aCallbackData);

  void call_collection_callback(const StaticallyKnownCollection_t& coll);

  void set_index_callback(
      IndexCallback aCallbackFunction,
      void* aCallbackData);

  void call_index_callback(const IndexDecl_t& index);

protected:
  static_context();

  static_context(static_context* parent);

  CollectionMap* collection_map() const { return theCollectionMap; }

  IndexMap* index_map() const { return theIndexMap; }

  ICMap* ic_map() const { return theICMap; }

  //serialization helpers
  bool check_parent_is_root();

  void set_parent_as_root();
};


}
#endif /*	ZORBA_CONTEXT_STATIC_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
