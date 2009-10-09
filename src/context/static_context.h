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
#include <list>
#include <set>

#include <zorba/api_shared_types.h>

#include "store/api/item.h" // TODO remove by moving all functions into the cpp file

#include "context/static_context_consts.h"
#include "context/context.h"
#include "context/decimal_format.h"
#include "context/collation_cache.h"
#include "context/internal_uri_resolvers.h"

#include "compiler/expression/expr_base.h"

#include "types/typemanager.h"

#include "zorbaerrors/Assert.h"
#include "zorbautils/hashmap_itemp.h"

#include "common/shared_types.h"


namespace zorba {

class namespace_node;
class user_function;
class TypeManager;

template <class V> class serializable_ItemPointerHashMap;

class ValueIndex;
typedef rchandle<ValueIndex> ValueIndex_t;

class StaticallyKnownCollection;
typedef rchandle<StaticallyKnownCollection> StaticallyKnownCollection_t;

/*******************************************************************************
  XQuery 1.0 context
	[http://www.w3.org/TR/xquery/#id-xq-context-components]

  Note: External API interface is in abstract class public StaticContext
        which is implemented in StaticContextImpl

  theDocResolver    : URI resolver which is used for retrieving documents
                      (used by fn:doc and fn:doc-available) 
  theColResolver    : URI resolver which is used for retrieving collections
                      (used by fn:collection and any of the updating
                      collection functions)
  theSchemaResolver : URI resolver which is used for retrieving a schema
                      (used in the translator)
  theModuleResolver : URI resolver which is used for retrieving a module
                      (used in the translator)
  Note: All URI resolvers have standard implementations in the classes
        Standard*URIResolver.
        Optionally, the user can provide resolvers which are wrapped by the
        *URIResolverWrapper classes.

  Note: URI resolvers are not serialized if the plan is
        serialized. Instead, they are set again if the query is loaded.
        If the user has provided a resolver before, he needs to make sure
        that the resolver is available using the SerializationCallback class.
        The latter also yields for ExternalModules and the TraceStream.

  theQueryExpr      : If this sctx is the root sctx for a mainModule,
                      theQueryExpr is the resul of the translation of
                      that mainModule. It is used in implementing the
                      loadProlog api.
  theDecimalFormats :
  theTraceStream    : Output stream that is used by the fn:trace function.
                      std::cerr is the default if the user didn't provide one.
                      For serialization: see note above.
  theCollationCache :
********************************************************************************/

// exported for testing purposes only
class ZORBA_DLL_PUBLIC static_context : public context
{
  typedef ItemPointerHashMap<rchandle<StaticallyKnownCollection> > CollectionMap;
  typedef serializable_ItemPointerHashMap<rchandle<ValueIndex> > IndexMap;

protected:
  rchandle<TypeManager>           typemgr;

  InternalDocumentURIResolver   * theDocResolver;
  InternalCollectionURIResolver * theColResolver;
  InternalSchemaURIResolver     * theSchemaResolver;

  std::vector<InternalModuleURIResolver*> theModuleResolvers;

  CollectionMap                 * theCollectionMap;

  IndexMap                      * theIndexMap;

  expr_t                          theQueryExpr;

  std::vector<DecimalFormat_t>    theDecimalFormats;

  std::ostream                  * theTraceStream;
  CollationCache                * theCollationCache;

public:
  SERIALIZABLE_CLASS(static_context);
  static_context(::zorba::serialization::Archiver& ar);

  void
  serialize_resolvers(serialization::Archiver& ar);

  void
  serialize_tracestream(serialization::Archiver& ar);

  void
  serialize(serialization::Archiver &ar);

public:
  ~static_context();

  static_context* create_child_context();

  TypeManager* get_typemanager();

  TypeManager* get_local_typemanager() const { return typemgr.getp(); }

  void set_typemanager(rchandle<TypeManager>);
  
  void add_decimal_format(const DecimalFormat_t& decimal_format);

  DecimalFormat_t get_decimal_format(const store::Item_t qname);

  expr_t get_query_expr() const;

  void set_query_expr(expr_t expr);

  StaticContextConsts::xquery_version_t xquery_version() const;
	StaticContextConsts::xpath1_0compatib_mode_t xpath1_0compatib_mode() const;
	StaticContextConsts::construction_mode_t construction_mode() const;
	StaticContextConsts::order_empty_mode_t order_empty_mode() const;
	StaticContextConsts::boundary_space_mode_t boundary_space_mode() const;
	StaticContextConsts::inherit_mode_t inherit_mode() const;
	StaticContextConsts::preserve_mode_t preserve_mode() const;
	StaticContextConsts::ordering_mode_t ordering_mode() const;
  StaticContextConsts::validation_mode_t validation_mode() const;
  bool revalidation_enabled () const;
  xqp_string default_elem_type_ns () const;

  void set_xquery_version(StaticContextConsts::xquery_version_t v);

  // parse and set the xquery version
  // StaticContextConsts::xquery_version_unknown is set
  // if the persion could not be parsed
  void set_xquery_version(const std::string& v);

	void set_xpath1_0compatib_mode(StaticContextConsts::xpath1_0compatib_mode_t v);
	void set_construction_mode(StaticContextConsts::construction_mode_t v);
	void set_order_empty_mode(StaticContextConsts::order_empty_mode_t v);
	void set_boundary_space_mode(StaticContextConsts::boundary_space_mode_t v);
	void set_inherit_mode(StaticContextConsts::inherit_mode_t v);
	void set_preserve_mode(StaticContextConsts::preserve_mode_t v);
	void set_ordering_mode(StaticContextConsts::ordering_mode_t v);
  void set_validation_mode(StaticContextConsts::validation_mode_t v);
  void set_revalidation_enabled (bool);
  void set_default_elem_type_ns (xqp_string);


  //
  // Prefix-to-Namespace resolution
  //
  void
  bind_ns (xqp_string prefix, xqp_string ns, const XQUERY_ERROR& err = XQST0033);

  bool
  lookup_ns (xqp_string prefix, xqp_string &ns) const;

  xqp_string
  lookup_ns (xqp_string prefix, const XQUERY_ERROR& err = XPST0081) const;

  xqp_string
  lookup_ns (xqp_string prefix, const QueryLoc& loc, const XQUERY_ERROR& err = XPST0081) const;

  xqp_string
  lookup_ns_or_default (xqp_string prefix, xqp_string default_ns) const;

  bool
  lookup_elem_ns(const xqp_string pfx, xqp_string& ns) const;

  bool
  lookup_option(const xqp_string& prefix, const xqp_string& localname, xqp_string& option) const;

  bool
  bind_option(const xqp_string& prefix, const xqp_string& localname, const xqp_string& option);

  store::Item_t
  lookup_qname (xqp_string default_ns, xqp_string name, const QueryLoc& loc) const;

  store::Item_t
  lookup_qname (xqp_string default_ns, xqp_string pfx, xqp_string local, const QueryLoc& loc) const;

  store::Item_t
  lookup_fn_qname (xqp_string pfx, xqp_string local, const QueryLoc& loc) const;

  store::Item_t
  lookup_elem_qname (xqp_string qname, const QueryLoc& loc) const 
  {
    return lookup_qname(lookup_ns_or_default("", default_elem_type_ns()), qname, loc);
  }

  store::Item_t
  lookup_elem_qname (xqp_string pfx, xqp_string local, const QueryLoc& loc) const 
  {
    return lookup_qname(lookup_ns_or_default("", default_elem_type_ns()), pfx, local, loc);
  }

  store::Item_t
  lookup_var_qname (xqp_string qname, const QueryLoc& loc) const 
  {
    return lookup_qname ("", qname, loc);
  }

  //
  // Normalized qname construction
  //
  static xqp_string
  qname_internal_key (const store::Item *qname);

  xqp_string
  qname_internal_key (xqp_string default_ns, xqp_string prefix, xqp_string local) const;

  xqp_string
  qname_internal_key (xqp_string default_ns, xqp_string qname) const;

  static std::pair<xqp_string /*local*/, xqp_string /*uri*/>
  decode_qname_internal_key (xqp_string key);


  //
  // Var QName --> Var Expr
  //
  bool
  bind_var (const store::Item *qname, expr *expr) 
  {
    return bind_expr2 ("var:", qname_internal_key (qname), expr);
  }

  expr*
  lookup_var (xqp_string qname) const 
  {
    return lookup_expr2 ("var:", qname_internal_key ("", qname));
  }

  expr*
  lookup_var (store::Item_t qname) 
  {
    return lookup_expr2 ("var:", qname_internal_key (qname));
  }

  expr*
  lookup_var_nofail (xqp_string qname) const 
  {
    expr *e = lookup_var (qname);
    ZORBA_ASSERT (e != NULL);
    return e;
  }


  //
  // Function QName, Arity --> Function Object
  //
  bool
  bind_fn (const store::Item *qname, function *f, int arity, bool override = false);

  static function*
  lookup_builtin_fn (xqp_string local, int arity);

  function*
  lookup_fn (xqp_string prefix, xqp_string local, int arity) const;

  function*
  lookup_resolved_fn (xqp_string ns, xqp_string local, int arity) const;

  function*
  lookup_fn_int (xqp_string key, int arity) const;

  void
  find_functions (const store::Item *qname, std::vector<function *>& functions) const;

  // bind a module registered by the user
  // this module can be used to retrieve external functions defined
  // in the namespace of the module
  bool
  bind_external_module(ExternalModule* aModule, bool aDynamicallyLoaded = false);
  
  StatelessExternalFunction *
  lookup_stateless_external_function(const xqp_string& prefix,
                                     const xqp_string& local);

  //
  // Type Management : Entity Name --> Type 
  // where entity may be variable, the context item, function, document, collection
  //
  void
  bind_type( xqp_string key, xqtref_t t);

  xqtref_t
  lookup_type (xqp_string key);

  xqtref_t
  lookup_type2 (const char *key1, xqp_string key2);

  xqtref_t
  get_variable_type( store::Item *var_name );

	void
  set_context_item_static_type(xqtref_t t);

	xqtref_t
	context_item_static_type();

	void
  set_function_type(const store::Item *qname, xqtref_t t);

  xqtref_t
  get_function_type(const store::Item_t);

	void
  set_document_type(xqp_string docURI, xqtref_t t);

  xqtref_t
  get_document_type(const xqp_string);
	
	void
  set_default_collection_type(xqtref_t t);

	xqtref_t
  default_collection_type();

	void
  set_collection_type(xqp_string collURI, xqtref_t t);

  xqtref_t
  get_collection_type(const xqp_string);

  //
  // Collections
  //
  void add_declared_collection( StaticallyKnownCollection_t& aCollection, const QueryLoc& aLoc);

  //
  // Index
  //
  void bind_index(const store::Item* qname, ValueIndex_t& vi, const QueryLoc& loc);

  ValueIndex* lookup_index(const store::Item* qname) const;


  //
  // Collations
  //
  void bind_collation(const xqp_string& aCollURI)
  {
    bind_str2("coll:", aCollURI, "");
  }

  bool lookup_collation(const xqp_string& aCollURI) const
  {
    // TODO better use a hashmap for collation itself
    xqpString lTmp;
    return context_value2<xqp_string>("coll:", aCollURI, lTmp);  
  }

  void bind_default_collation(const xqp_string& aCollURI)
  {
    bind_str("coll:default:", aCollURI, XQST0038);
  }

  bool lookup_default_collation(xqp_string& aCollURI) const
  {
    return context_value<xqp_string>("coll:default:", aCollURI);
  }

  bool has_collation_uri(const xqp_string& aURI) const;

  xqp_string default_collation_uri() const;

  void set_default_collation_uri(const xqp_string& uri);

	void add_collation(const xqp_string& uri);

  CollationCache* get_collation_cache();

  XQPCollator* create_collator(const xqp_string& aURI);


  //
  // Base uri
  //
  xqp_string
  final_baseuri ();

  xqp_string
  current_absolute_baseuri() const;

  void
  set_current_absolute_baseuri(xqp_string);

	void
  compute_current_absolute_baseuri();

  xqp_string
  baseuri() const;

  void
  set_baseuri(xqp_string, bool from_prolog = true);

  xqp_string
  encapsulating_entity_baseuri() const;

  void
  set_encapsulating_entity_baseuri(xqp_string);

  xqp_string
  entity_retrieval_url() const;

  void
  set_entity_retrieval_url(xqp_string);

  xqp_string
  implementation_baseuri () const { return "http://www.zorba-xquery.com/"; }

  // TODO: move this method to URI class in zorbatypes
  static xqp_string
  make_absolute_uri(xqp_string uri, xqp_string base_uri, bool validate = true);

  xqp_string
  resolve_relative_uri( xqp_string uri, xqp_string abs_base_uri, bool validate = true);


  //
  // Merge in the static context of a module
  //
  bool
  import_module (const static_context* module, const QueryLoc& loc);


  //
  // URI Resolver functions
  //
  void
  set_document_uri_resolver(InternalDocumentURIResolver*);

  InternalDocumentURIResolver*
  get_document_uri_resolver();

  void
  set_collection_uri_resolver(InternalCollectionURIResolver*);

  InternalCollectionURIResolver*
  get_collection_uri_resolver();

  void
  set_schema_uri_resolver(InternalSchemaURIResolver*);

  InternalSchemaURIResolver*
  get_schema_uri_resolver();

  void
  add_module_uri_resolver(InternalModuleURIResolver*);

  void
  get_module_uri_resolvers(std::vector<InternalModuleURIResolver*>& lResolvers);

  void
  remove_module_uri_resolver(InternalModuleURIResolver*);

  void
  set_trace_stream(std::ostream&);

  std::ostream*
  get_trace_stream() const;

  /**
  * @brief This method gets all variable names from this static context
  * and its parents.
  *
  * This method gets all variables in the scope of this static context.
  * Therefore it gets recursively all variables names from its parent,
  * adds them to aVariableList and then adds the variables saved in the
  * asked static context to aVariableList.
  *
  * @sa getVariables::getVariables(std::vector<var_expr_t>& aVarialeList)
  * @param aVariableList a vector of strings, where the variable names
  *  are put into.
  * @post aVariableList contains all variable names reachable from the
  *  scope from the current static context.
  */
  void getVariables(std::vector<std::string>& aVarialeList) const;

  /**
  * @brief This method gets all variable expressions from this static
  * context and its parents.
  *
  * This method gets all variables in the scope of this static context.
  * Therefore it gets recursively all variables expressions from its parent,
  * adds them to aVariableList and then adds the variables saved in the
  * asked static context to aVariableList.
  *
  * @sa getVariables::getVariables(std::vector<std::string>& aVarialeList)
  * @param aVariableList a vector of variable expressions, where the
  *  variable names are put into.
  * @post aVariableList contains all variable expressions reachable from the
  *  scope from the current static context.
  */
  void getVariables(std::vector<var_expr_t>& aVarialeList) const;

protected:
  static_context();

  static_context(static_context* parent);
 
  void find_functions_int(
        xqp_string key,
                      std::vector<function *>& functions,
                      std::set<int> &found) const;

  static xqp_string fn_internal_key();
};


std::pair<xqp_string, xqp_string> parse_qname (xqp_string qname);



}	/* namespace zorba */
#endif /*	ZORBA_CONTEXT_STATIC_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
