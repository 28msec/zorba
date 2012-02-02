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
#pragma once
#ifndef ZORBA_CONTEXT_STATIC_CONTEXT_H
#define ZORBA_CONTEXT_STATIC_CONTEXT_H

#include <deque>
#include <map>
#include <memory>
#include <set>
#include <vector>

#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/function.h>

#ifdef WIN32
#include "store/api/item.h"
#include "compiler/expression/expr_base.h"
#include "types/typemanager.h"
#endif

#include "context/static_context_consts.h"
#include "context/decimal_format.h"
#include "context/uri_resolver.h"
#include "context/features.h"

#include "zorbautils/hashmap_zstring.h"

#include "common/shared_types.h"
#include "util/stl_util.h"
#include "util/auto_vector.h"


namespace zorba
{

class expr;
#ifndef ZORBA_NO_FULL_TEXT
class ftmatch_options;
#endif /* ZORBA_NO_FULL_TEXT */
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

class IndexDecl;
typedef rchandle<IndexDecl> IndexDecl_t;

class ValueIC;
typedef rchandle<ValueIC> ValueIC_t;

class StaticallyKnownCollection;
typedef rchandle<StaticallyKnownCollection> StaticallyKnownCollection_t;


/*******************************************************************************
  Base Uri Computation

  thePrologBaseUri is the one declared in the prolog. theApplicationBaseUri
  is set explicitly from the C++/C api. If both thePrologBaseUri and
  theApplicationBaseUri are set, thePrologBaseUri hides theApplicationBaseUri.

  theEncapsulatingEntityUri is currently not used, except in one special case:
  to make the baseURI property of the file module sctx be the full pathname of
  the query file (see translator.cpp).

  theEntityRetrievalUri is set by default to the full pathname of the file
  containing the query we are running (for the main module) or the url of
  the module component (for lib modules). It may also be set explicitly
  from the C++/C api.
********************************************************************************/
struct BaseUriInfo : public ::zorba::serialization::SerializeBaseClass
{
  zstring thePrologBaseUri;
  zstring theApplicationBaseUri;
  zstring theEncapsulatingEntityUri;
  zstring theEntityRetrievalUri;

  zstring theBaseUri;

  bool    theHavePrologBaseUri;
  bool    theHaveApplicationBaseUri;
  bool    theHaveEncapsulatingEntityUri;
  bool    theHaveEntityRetrievalUri;
  bool    theHaveBaseUri;

public:
  SERIALIZABLE_CLASS(BaseUriInfo)
  SERIALIZABLE_CLASS_CONSTRUCTOR(BaseUriInfo)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  BaseUriInfo()
    :
    theHavePrologBaseUri(false),
    theHaveApplicationBaseUri(false),
    theHaveEncapsulatingEntityUri(false),
    theHaveEntityRetrievalUri(false),
    theHaveBaseUri(false)
  {
  }
};


/*******************************************************************************

********************************************************************************/
struct FunctionInfo : public ::zorba::serialization::SerializeBaseClass
{
  function_t  theFunction;
  bool        theIsDisabled;

public:
  SERIALIZABLE_CLASS(FunctionInfo)

  FunctionInfo(::zorba::serialization::Archiver& ar);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  FunctionInfo();

  FunctionInfo(const function_t& f, bool disabled = false);

  ~FunctionInfo();
};


/*******************************************************************************

********************************************************************************/
struct PrologOption : public ::zorba::serialization::SerializeBaseClass
{
  store::Item_t    theName;
  zstring theValue;

public:
  SERIALIZABLE_CLASS(PrologOption)
  SERIALIZABLE_CLASS_CONSTRUCTOR(PrologOption)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  PrologOption() {}

  PrologOption(const store::Item* name, const zstring& value)
    :
    theName(const_cast<store::Item*>(name)),
    theValue(const_cast<zstring&>(value))
  {
  }
};


/***************************************************************************//**
  XQuery 3.0 static context
	[http://www.w3.org/TR/2010/WD-xquery-30-20101214/#static_context]

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

  theImportedBuiltinModules :
  ---------------------------
  If this is the root sctx of a module, theImportedBuiltinModules stores the
  namespaces of "builtin" modules that have been imported by this module.
  Builtin modules are modules that declare user-visible zorba builtin functions
  (see also ns_consts.h)

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

  theTypeMnager :
  ---------------
  If non NULL, then "this" is the root sctx of a module, and theTypeManager stores
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

  theContextItemType :
  --------------------

  theVariablesMap :
  -----------------
  
  theImportedPrivateVariablesMap :
  --------------------------------

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

  theFeatures:
  ------------
  Feature flags that are used when a particular feature (e.g. scripting
  or ddl) is enabled. The definition of the features is located in
  context/featueres.h.

********************************************************************************/

class static_context : public SimpleRCObject
{
  typedef serializable_ItemPointerHashMap<StaticallyKnownCollection_t> CollectionMap;

  typedef serializable_ItemPointerHashMap<IndexDecl_t> IndexMap;

  typedef serializable_ItemPointerHashMap<ValueIC_t> ICMap;

  typedef serializable_ItemPointerHashMap<var_expr_t> VariableMap;

  typedef serializable_ItemPointerHashMap<FunctionInfo> FunctionMap;

  typedef serializable_ItemPointerHashMap<std::vector<FunctionInfo>* > FunctionArityMap;

  typedef serializable_ItemPointerHashMap<PrologOption> OptionMap;

  typedef serializable_HashMapZString<zstring> NamespaceBindings;

  typedef serializable_HashMapZString<xqtref_t> DocumentMap;

  typedef serializable_HashMapZString<xqtref_t> W3CCollectionMap;

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

  typedef serializable_HashMapZString<ctx_module_t> ExternalModuleMap;

public:
  static const zstring DOT_VAR_NAME;
  static const zstring DOT_POS_VAR_NAME;
  static const zstring DOT_SIZE_VAR_NAME;


  //
  // W3C namespaces
  //
  static const char* W3C_NS_PREFIX; // http://www.w3.org/

  static const char* W3C_XML_NS;    // http://www.w3.org/XML/1998/namespace

  static const char* W3C_FN_NS;     // http://www.w3.org/2005/xpath-functions

  //
  // Zorba namespaces
  //

  static const char* ZORBA_NS_PREFIX; // http://www.zorba-xquery.com/

  // Namespaces of external modules declaring zorba builtin functions
  static const char* ZORBA_MATH_FN_NS;
  static const char* ZORBA_BASE64_FN_NS;
  static const char* ZORBA_NODEREF_FN_NS;
  static const char* ZORBA_NODEPOS_FN_NS;
  static const char* ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_FN_NS;
  static const char* ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS;
  static const char* ZORBA_STORE_STATIC_COLLECTIONS_DDL_FN_NS;
  static const char* ZORBA_STORE_STATIC_COLLECTIONS_DML_FN_NS;
  static const char* ZORBA_STORE_STATIC_INDEXES_DDL_FN_NS;
  static const char* ZORBA_STORE_STATIC_INDEXES_DML_FN_NS;
  static const char* ZORBA_STORE_STATIC_INTEGRITY_CONSTRAINTS_DDL_FN_NS;
  static const char* ZORBA_STORE_STATIC_INTEGRITY_CONSTRAINTS_DML_FN_NS;
  static const char* ZORBA_STORE_DYNAMIC_DOCUMENTS_FN_NS;
  static const char* ZORBA_STORE_DYNAMIC_UNORDERED_MAP_FN_NS;
  static const char* ZORBA_SCHEMA_FN_NS;
  static const char* ZORBA_XQDOC_FN_NS;
  static const char* ZORBA_RANDOM_FN_NS;
  static const char* ZORBA_INTROSP_SCTX_FN_NS;
  static const char* ZORBA_REFLECTION_FN_NS;
  static const char* ZORBA_STRING_FN_NS;
  static const char* ZORBA_FETCH_FN_NS;
  static const char* ZORBA_NODE_FN_NS;
  static const char* ZORBA_XML_FN_NS;

  // Namespaces of virtual modules declaring zorba builtin functions
  static const char* ZORBA_UTIL_FN_NS;
  static const char* ZORBA_SCRIPTING_FN_NS;

  // Namespaces of virtual modules declaring internal builtin functions of
  // XQUERY or zorba. Internal functions are not visible to xquery programs.
  static const char* XQUERY_OP_NS;
  static const char* ZORBA_OP_NS;

  // options-related namepsaces
  static const char* ZORBA_OPTIONS_NS;
  static const char* ZORBA_OPTION_WARN_NS;
  static const char* ZORBA_OPTION_FEATURE_NS;
  static const char* ZORBA_OPTION_OPTIM_NS;
  static const char* ZORBA_VERSIONING_NS;

protected:
  static_context                        * theParent;

  std::ostream                          * theTraceStream;

  expr_t                                  theQueryExpr;

  std::string                             theModuleNamespace;

  std::vector<zstring>                  * theImportedBuiltinModules;

  BaseUriInfo                           * theBaseUriInfo;

  ztd::auto_vector<internal::URIMapper>   theURIMappers;

  ztd::auto_vector<internal::URLResolver> theURLResolvers;

  checked_vector<zstring>                 theURIPath;

  checked_vector<zstring>                 theLibPath;

  ExternalModuleMap                     * theExternalModulesMap;

  checked_vector<zstring>                 theJVMClassPath;

  rchandle<TypeManager>                   theTypeManager;

  NamespaceBindings                     * theNamespaceBindings;

  zstring                                 theDefaultElementNamespace;
  bool                                    theHaveDefaultElementNamespace;

  zstring                                 theDefaultFunctionNamespace;
  bool                                    theHaveDefaultFunctionNamespace;

  xqtref_t                                theContextItemType;

  VariableMap                           * theVariablesMap;
  
  VariableMap                           * theImportedPrivateVariablesMap;

  FunctionMap                           * theFunctionMap;
  FunctionArityMap                      * theFunctionArityMap;

  CollectionMap                         * theCollectionMap;

  W3CCollectionMap                      * theW3CCollectionMap;
  xqtref_t                                theDefaultW3CCollectionType;

  IndexMap                              * theIndexMap;

  ICMap                                 * theICMap;

  DocumentMap                           * theDocumentMap;

  CollationMap                          * theCollationMap;
  std::string                           * theDefaultCollation;
  mutable XQPCollator                   * theCachedDefaultCollator;

  OptionMap                             * theOptionMap;

  audit::Event                          * theAuditEvent;

#ifndef ZORBA_NO_FULL_TEXT
  ftmatch_options                       * theFTMatchOptions;
#endif /* ZORBA_NO_FULL_TEXT */

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

  bool                                       theAllWarningsDisabled;

  bool                                       theAllWarningsErrors;

  std::vector<store::Item_t>                 theWarningsAreErrors;

  std::vector<store::Item_t>                 theDisabledWarnings;

  uint32_t                                   theFeatures;

public:
  static bool is_builtin_module(const zstring& ns);

  static bool is_builtin_virtual_module(const zstring& ns);

  static bool is_non_pure_builtin_module(const zstring& ns);

  static bool is_reserved_module(const zstring& ns);

  static zstring var_name(const store::Item*);

public:
  SERIALIZABLE_CLASS(static_context);

  void serialize_resolvers(serialization::Archiver& ar);

  void serialize_tracestream(serialization::Archiver& ar);

  void serialize(serialization::Archiver& ar);

  void prepare_for_serialize(CompilerCB *compiler_cb);

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

  void set_module_namespace(const zstring& ns) { theModuleNamespace = ns.str(); }

  const std::string& get_module_namespace() const { return theModuleNamespace; }

  void add_imported_builtin_module(const zstring& ns);

  bool is_imported_builtin_module(const zstring& ns);

  //
  // Base uri
  //
  zstring get_implementation_baseuri() const;

  bool get_encapsulating_entity_uri(zstring& res) const;

  void set_encapsulating_entity_uri(const zstring& uri);

  bool get_entity_retrieval_uri(zstring& res) const;

  void set_entity_retrieval_uri(const zstring& uri);

  zstring get_base_uri() const;

  void set_base_uri(const zstring& uri, bool from_prolog = true);

  void compute_base_uri();

  zstring
  resolve_relative_uri(
      const zstring& aUri,
      bool aValidate = true) const;

  zstring
  resolve_relative_uri(
      const zstring&  aRelativeUri,
      const zstring&  aBaseUri,
      bool            validate = true) const;

  //
  // URI Resolution
  //

  /**
   * Add a URIMapper to be used by this static context when resolving
   * URIs to resources.
   */
  void add_uri_mapper(internal::URIMapper* aMapper);

  /**
   * Add a URLResolver to be used by this static context when
   * resolving URIs to resources.
   */
  void add_url_resolver(internal::URLResolver* aResolver);

  /**
   * Given a URI, return a Resource for that URI.
   * @param aEntityKind the expected kind of entity expected at this aUri
   */
  std::auto_ptr<internal::Resource> resolve_uri
  (zstring const& aUri, internal::EntityData::Kind aEntityKind, zstring& oErrorMessage) const;

  /**
   * Given a URI, return a Resource for that URI.
   * @param aEntityData an EntityData object to pass to the mappers/resolvers.
   */
  std::auto_ptr<internal::Resource> resolve_uri
  (zstring const& aUri, internal::EntityData const& aEntityData, zstring& oErrorMessage) const;

  /**
   * Given a URI, populate a vector with a list of component URIs.  If
   * no component URIs are available, the vector will be populated
   * with (only) the input URI.
   */
  void get_component_uris
  (zstring const& aUri, internal::EntityData::Kind aEntityKind,
    std::vector<zstring>& oComponents) const;

  void set_uri_path(const std::vector<zstring>& aURIPath);

  void get_uri_path(std::vector<zstring>& oURIPath) const;

  void get_full_uri_path(std::vector<zstring>& oURIPath) const;

  void set_lib_path(const std::vector<zstring>& aLibPath);

  void get_lib_path(std::vector<zstring>& oLibPath) const;

  void get_full_lib_path(std::vector<zstring>& oLibPath) const;

  //
  // JVM classpath
  //
  void set_jvm_class_path(const std::vector<zstring>& aClassPath);

  void get_jvm_class_path(std::vector<zstring>& oClassPath) const;

  void get_full_jvm_class_path(std::vector<zstring>& path) const;

	//
  // Validating Items
  //
  bool validate(
        store::Item* rootElement,
        store::Item_t& validatedResult,
        StaticContextConsts::validation_mode_t validationMode =
            StaticContextConsts::strict_validation) const;

  bool validate(
        store::Item* rootElement,
        store::Item_t& validatedResult,
        const zstring& targetNamespace,
        StaticContextConsts::validation_mode_t validationMode =
            StaticContextConsts::strict_validation) const ;

  bool validateSimpleContent(
        zstring& textValue,
        store::Item* typeQName,
        std::vector<store::Item_t>& resultList) const;

  //
  // Type management
  //
  TypeManager* get_typemanager() const;

  TypeManager* get_local_typemanager() const;

  void set_typemanager(rchandle<TypeManager>);

  //
  // Namespace Bindings
  //
  const zstring& default_elem_type_ns() const;

  void set_default_elem_type_ns(
      const zstring& ns,
      bool raiseError,
      const QueryLoc& loc);

  const zstring& default_function_ns() const;

  void set_default_function_ns(
      const zstring& ns,
      bool raiseError,
      const QueryLoc& loc);

  void bind_ns(
        const zstring& prefix,
        const zstring& ns,
        const QueryLoc& loc,
        const Error& err = err::XQST0033);

  bool lookup_ns(
        zstring& ns,
        const zstring& prefix,
        const QueryLoc& loc,
        const Error& err = err::XPST0081) const;

  void expand_qname(
        store::Item_t& qname,
        const zstring& default_ns,
        const zstring& pfx,
        const zstring& local,
        const QueryLoc& loc) const;

  void get_namespace_bindings(store::NsBindings& bindings) const;

  //
  // Variables
  //
  void bind_var(
        var_expr_t& expr,
        const QueryLoc& loc,
        const Error& err);

  var_expr* lookup_var(
        const store::Item* qname,
        const QueryLoc& loc,
        const Error& err) const;

  void getVariables(
    std::vector<var_expr_t>& variableList,
    bool localsOnly = false,
    bool returnPrivateVars = false,
    bool externalVarsOnly = false) const;

  void set_context_item_type(const xqtref_t& t);

  const XQType* get_context_item_type() const;

  //
  // Functions
  //
  void bind_fn(function_t& f, ulong arity, const QueryLoc& loc);

  void unbind_fn(const store::Item* qname, ulong arity);

  function* lookup_fn(const store::Item* qname, ulong arity);

  function* lookup_local_fn(const store::Item* qname, ulong arity);

  void get_functions(std::vector<function*>& functions) const;

  void find_functions(
        const store::Item* qname,
        std::vector<function*>& functions) const;

  void bind_external_module(
        ExternalModule* aModule,
        bool aDynamicallyLoaded = false);

  ExternalFunction* lookup_external_function(
        const zstring& prefix,
        const zstring& local);


  //
  // Documents
  //
  void bind_document(const zstring& uri, xqtref_t& t);

  const XQType* lookup_document(const zstring& uri);

  void get_all_documents(std::vector<zstring>& documents);

  //
  // W3C Collections
  //
  void bind_w3c_collection(zstring& uri, xqtref_t& t);

  const XQType* lookup_w3c_collection(const zstring& uri);

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
  void bind_index(IndexDecl_t& vi, const QueryLoc& loc);

  IndexDecl* lookup_index(const store::Item* qname) const;

  store::Iterator_t index_names() const;


  //
  // XQDDF Integrity Constraints
  //
  void bind_ic(ValueIC_t& vic, const QueryLoc& loc);

  ValueIC_t lookup_ic(const store::Item* qname) const;

  store::Iterator_t ic_names() const;


  //
  // Collations
  //
  void add_collation(const std::string& uri, const QueryLoc& loc);

  bool is_known_collation(const std::string& uri) const;

  XQPCollator* get_collator(const std::string& uri, const QueryLoc& loc) const;

  void set_default_collation(const std::string& uri, const QueryLoc& loc);

  const std::string& get_default_collation(const QueryLoc& loc) const;

  XQPCollator* get_default_collator(const QueryLoc& loc) const;

  void get_collations(std::vector<std::string>& collations) const;


  //
  // Options
  //
  void bind_option(
      const store::Item* qname,
      const zstring& option,
      const QueryLoc& loc);

  bool lookup_option(const store::Item* qname, zstring& option) const;

protected:
  void process_feature_option(
    const zstring& value,
    bool  enable,
    const QueryLoc& loc);

  void process_optim_option(
    const zstring& value,
    bool  enable,
    const QueryLoc& loc);

  void process_warning_option(
    const zstring& value,
    const zstring& name,
    const QueryLoc& loc);

  store::Item_t
  parse_and_expand_qname(
      const zstring& value,
      const char* default_ns,
      const QueryLoc& loc
    ) const;

public:

  //
  // Auditing
  //
  void set_audit_event(audit::Event* ae);

  audit::Event* get_audit_event() const;


  //
  //  Misc
  //
  StaticContextConsts::xquery_version_t xquery_version() const;

  void set_xquery_version(StaticContextConsts::xquery_version_t v);

  StaticContextConsts::xpath_compatibility_t xpath_compatibility() const;

  void set_xpath_compatibility(StaticContextConsts::xpath_compatibility_t v);

  StaticContextConsts::construction_mode_t construction_mode() const;

  void set_construction_mode(StaticContextConsts::construction_mode_t v);

  StaticContextConsts::inherit_mode_t inherit_mode() const;

  void set_inherit_mode(StaticContextConsts::inherit_mode_t v);

  StaticContextConsts::preserve_mode_t preserve_mode() const;

  void set_preserve_mode(StaticContextConsts::preserve_mode_t v);

  StaticContextConsts::ordering_mode_t ordering_mode() const;

  bool is_in_ordered_mode() const;

  void set_ordering_mode(StaticContextConsts::ordering_mode_t v);

  StaticContextConsts::empty_order_mode_t empty_order_mode() const;

  void set_empty_order_mode(StaticContextConsts::empty_order_mode_t v);

  StaticContextConsts::boundary_space_mode_t boundary_space_mode() const;

  void set_boundary_space_mode(StaticContextConsts::boundary_space_mode_t v);

  StaticContextConsts::validation_mode_t validation_mode() const;

  void set_validation_mode(StaticContextConsts::validation_mode_t v);

  void add_decimal_format(const DecimalFormat_t& format, const QueryLoc& loc);

  DecimalFormat_t get_decimal_format(const store::Item_t& qname);

#ifndef ZORBA_NO_FULL_TEXT
  ftmatch_options const* get_match_options() const {
    return theFTMatchOptions;
  }

  void set_match_options( ftmatch_options *mo ) {
    theFTMatchOptions = mo;
  }
#endif /* ZORBA_NO_FULL_TEXT */

  //
  // Merge in the static context of a module
  //
  void import_module (const static_context* module, const QueryLoc& loc);

  //
  // Warnings
  //
  void disableWarning(store::Item_t qname);

  void disableAllWarnings();

  void setWarningAsError(store::Item_t qname);

  bool isWarningDisabled(const char* ns, const char* localname);

  bool isWarningAnError(const char* ns, const char* localname);


protected:
  static_context();

  static_context(static_context* parent);

  CollectionMap* collection_map() const { return theCollectionMap; }

  IndexMap* index_map() const { return theIndexMap; }

  ICMap* ic_map() const { return theICMap; }

  //serialization helpers
  bool check_parent_is_root();

  void set_parent_as_root();

private:

  void apply_uri_mappers(zstring const& aUri,
    internal::EntityData const* aEntityData,
    internal::URIMapper::Kind aMapperKind,
    std::vector<zstring>& oUris) const;

  void apply_url_resolvers(std::vector<zstring>& aUrls,
    internal::EntityData const* aEntityData,
    std::auto_ptr<internal::Resource>& oResource,
    zstring& oErrorMessage) const;

public:
  bool is_feature_set( feature::kind k ) const
  {
    return (theFeatures & k) != 0;
  }

  void set_feature( feature::kind k )
  {
    theFeatures |= k;
  }

  void unset_feature( feature::kind k )
  {
    theFeatures &= ~k;
  }

};


}
#endif /* ZORBA_CONTEXT_STATIC_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
