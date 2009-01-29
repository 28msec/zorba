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

#include "context/static_context_consts.h"
#include <memory>
#include "store/api/item.h" // TODO remove by moving all functions into the cpp file

#include "context/context.h"
#include "context/static_context_consts.h"
#include "types/typemanager.h"
#include "zorbaerrors/Assert.h"

#include <zorba/api_shared_types.h>
#include "common/shared_types.h"


namespace zorba {

class namespace_node;
class user_function;
class TypeManager;
/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

// External API interface is in class public StaticQueryContext
class ZORBA_DLL_PUBLIC static_context : public context
{
protected:
  xqp_string qname_internal_key (xqp_string default_ns, xqp_string prefix, xqp_string local) const;
  xqp_string qname_internal_key (xqp_string default_ns, xqp_string qname) const;
  static xqp_string fn_internal_key ();
  function *lookup_fn_int (xqp_string key, int arity) const;

  rchandle<TypeManager> typemgr;

  static_context();
  static_context (static_context *_parent);

public:
  virtual ~static_context();
  static_context *create_child_context() { return new static_context(this); }
  TypeManager *get_typemanager () {
    TypeManager *tm = typemgr.getp();
    if (tm != NULL) {
      return tm;
    }
    return dynamic_cast<static_context *>(parent)->get_typemanager();
  }

  void set_typemanager(rchandle<TypeManager>);
  
  xqp_string default_function_namespace() const;
	void set_default_function_namespace(xqp_string);
  xqp_string default_elem_type_ns () const;
  void set_default_elem_type_ns (xqp_string);

  bool lookup_ns (xqp_string prefix, xqp_string &ns) const;
  xqp_string lookup_ns (xqp_string prefix, const XQUERY_ERROR& err = XPST0081) const;
  xqp_string lookup_ns (xqp_string prefix, const QueryLoc& loc, const XQUERY_ERROR& err = XPST0081) const;
  xqp_string lookup_ns_or_default (xqp_string prefix, xqp_string default_ns) const;
  void bind_ns (xqp_string prefix, xqp_string ns, const XQUERY_ERROR& err = XQST0033);

  static xqp_string qname_internal_key (const store::Item *qname);
  static std::pair<xqp_string /* local */, xqp_string /* uri */> decode_qname_internal_key (xqp_string key);

  store::Item_t lookup_qname (xqp_string default_ns, xqp_string name, const QueryLoc& loc) const;
  store::Item_t lookup_qname (xqp_string default_ns, xqp_string pfx, xqp_string local, const QueryLoc& loc) const;
  store::Item_t lookup_elem_qname (xqp_string name, const QueryLoc& loc) const {
    return lookup_qname (lookup_ns_or_default ("", default_elem_type_ns ()), name, loc);
  }
  store::Item_t lookup_elem_qname (xqp_string pfx, xqp_string local, const QueryLoc& loc) const {
    return lookup_qname (lookup_ns_or_default ("", default_elem_type_ns ()), pfx, local, loc);
  }
  bool lookup_elem_namespace(const xqp_string pfx, xqp_string& ns) const;

  store::Item_t lookup_fn_qname (xqp_string pfx, xqp_string local, const QueryLoc& loc) const;

  store::Item_t lookup_var_qname (xqp_string varname, const QueryLoc& loc) const {
    return lookup_qname ("", varname, loc);
  }

  expr *lookup_var (xqp_string varname) const {
    return lookup_expr2 ("var:", qname_internal_key ("", varname));
  }
  expr *lookup_var (store::Item_t varname) {
    return lookup_expr2 ("var:", qname_internal_key (varname));
  }
  expr *lookup_var_nofail (xqp_string varname) const {
    expr *e = lookup_var (varname);
    ZORBA_ASSERT (e != NULL);
    return e;
  }
  bool bind_var (const store::Item *qname, expr *expr) {
    return bind_expr2 ("var:", qname_internal_key (qname), expr);
  }
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

  /**
   * bind external functions
   * @return false if the function was already in
   */
  bool bind_stateless_external_function(StatelessExternalFunction* aExternalFunction);
  
  /**
   * lookup an external function by qname
   * returns the external function to that qname or null if it has not been registered
   */
  StatelessExternalFunction *
  lookup_stateless_external_function(xqp_string prefix, xqp_string local);

  function *lookup_fn (xqp_string prefix, xqp_string local, int arity) const;
  function *lookup_resolved_fn (xqp_string ns, xqp_string local, int arity) const;
  static function *lookup_builtin_fn (xqp_string local, int arity);
  void find_functions (const store::Item *qname,
                       std::vector<function *>& functions) const;
  void find_functions_int (xqp_string key,
                           std::vector<function *>& functions,
                           std::set<int> &found) const;
  bool bind_fn (const store::Item *qname, function *f, int arity);

  void add_variable_type( const xqp_string var_name, xqtref_t var_type);
  xqtref_t  get_variable_type( store::Item *var_name );
  
  void bind_type( xqp_string key, xqtref_t t);
  xqtref_t  lookup_type (xqp_string key);
  xqtref_t  lookup_type2 (const char *key1, xqp_string key2);

  /**
   * collation management
   */

	StaticContextConsts::xpath1_0compatib_mode_t xpath1_0compatib_mode() const;
	StaticContextConsts::construction_mode_t construction_mode() const;
	StaticContextConsts::order_empty_mode_t order_empty_mode() const;
	StaticContextConsts::boundary_space_mode_t boundary_space_mode() const;
	StaticContextConsts::inherit_mode_t inherit_mode() const;
	StaticContextConsts::preserve_mode_t preserve_mode() const;
  StaticContextConsts::validation_mode_t validation_mode() const;
  bool revalidation_enabled () const;
	
	void set_xpath1_0compatib_mode(StaticContextConsts::xpath1_0compatib_mode_t v);
	void set_construction_mode(StaticContextConsts::construction_mode_t v);
	void set_order_empty_mode(StaticContextConsts::order_empty_mode_t v);
	void set_boundary_space_mode(StaticContextConsts::boundary_space_mode_t v);
	void set_inherit_mode(StaticContextConsts::inherit_mode_t v);
	void set_preserve_mode(StaticContextConsts::preserve_mode_t v);
  void set_validation_mode(StaticContextConsts::validation_mode_t v);
  void set_revalidation_enabled (bool);

	void set_context_item_static_type(xqtref_t t);
	xqtref_t		context_item_static_type();

	void set_default_collection_type(xqtref_t t);
	xqtref_t		default_collection_type();

	void set_function_type(const store::Item *qname, xqtref_t t);
  xqtref_t get_function_type(const store::Item_t);
	
	void set_document_type(xqp_string docURI, xqtref_t t);
  xqtref_t get_document_type(const xqp_string);
	
	void set_collection_type(xqp_string collURI, xqtref_t t);
  xqtref_t get_collection_type(const xqp_string);
	
	StaticContextConsts::ordering_mode_t ordering_mode() const;
	void set_ordering_mode(StaticContextConsts::ordering_mode_t v);

  CollationCache* get_collation_cache();
  void release_collation_cache(CollationCache*);

  XQPCollator* create_collator(const xqp_string& aURI);

	void add_collation(const xqp_string& uri);
  xqp_string default_collation_uri() const;
  void set_default_collation_uri(const xqp_string& uri);
  bool has_collation_uri(const xqp_string& aURI) const;

protected:
  xqp_string current_absolute_baseuri() const;
	void compute_current_absolute_baseuri();

public:
  xqp_string encapsulating_entity_baseuri() const;
  xqp_string entity_retrieval_url() const;
  void set_encapsulating_entity_baseuri(xqp_string);
  void set_entity_retrieval_url(xqp_string);
  xqp_string implementation_baseuri () const { return "http://www.zorba-xquery.com/"; }
  xqp_string final_baseuri ();
  xqp_string baseuri() const;
  void set_baseuri(xqp_string, bool from_prolog = true);
  void set_current_absolute_baseuri(xqp_string);

  // TODO: move this method to URI class in zorbatypes
  static xqp_string make_absolute_uri(xqp_string uri, xqp_string base_uri, bool validate = true);

  xqp_string resolve_relative_uri( xqp_string uri, xqp_string abs_base_uri, bool validate = true);

  bool import_module (const static_context *module);

// URI Resolver function and members
public:
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
  set_module_uri_resolver(InternalModuleURIResolver*);

  InternalModuleURIResolver*
  get_module_uri_resolver();

protected:
  InternalDocumentURIResolver*   theDocResolver;
  InternalCollectionURIResolver* theColResolver;
  InternalSchemaURIResolver*     theSchemaResolver;
  InternalModuleURIResolver*     theModuleResolver;
};

std::pair<xqp_string, xqp_string> parse_qname (xqp_string qname);



}	/* namespace zorba */
#endif /*	ZORBA_CONTEXT_STATIC_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
