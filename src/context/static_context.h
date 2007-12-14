/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *		http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 * ========================================================================
 *
 * @author John Cowan,Paul Pedersen (pcp071098@yahoo.com)
 * @file context/static_context.h
 *
 */

#ifndef XQP_STATIC_CONTEXT_H
#define XQP_STATIC_CONTEXT_H

#include "common.h"
#include "context/context.h"
#include "context/context_impl.h"
#include "functions/signature.h"
#include "errors/Error.h"
#include "store/api/item.h"
#include "store/api/store.h"
#include "types/typesystem.h"

#include "zorba_api.h"

// MS Visual Studio does not fully support throw(), and issues a warning
#ifndef _MSC_VER
#define THROW_XQP_EXCEPTION		throw(xqp_exception)
#else
#define THROW_XQP_EXCEPTION		
#endif


namespace xqp {

class namespace_node;

/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

// External API interface is in class public StaticQueryContext
class static_context : public context
{
protected:
  static const char *default_ns_initializers [];

	static_context (const char **);
  xqp_string qname_internal_key (const QNameItem *qname) const;
  xqp_string qname_internal_key (xqp_string default_ns, xqp_string prefix, xqp_string local) const;
  xqp_string qname_internal_key (xqp_string default_ns, xqp_string qname) const;
  static xqp_string fn_internal_key (int arity);

	xqp_string		make_absolute_uri(xqp_string uri, xqp_string base_uri);
	void					compute_current_absolute_baseuri();
public:
	static void init();
  static_context()
		: context (root_static_context ()) {}
  static_context (static_context *_parent)
    : context (_parent) {}

	~static_context();

  static static_context *root_static_context ();


public:
  xqp_string default_function_namespace() const;
	void set_default_function_namespace(xqp_string);
  xqp_string default_elem_type_ns () const;
  void set_default_elem_type_ns (xqp_string);

  xqp_string lookup_ns (xqp_string prefix) const;
  void bind_ns (xqp_string prefix, xqp_string ns);

  QNameItem_t lookup_qname (xqp_string default_ns, xqp_string name) const;
  QNameItem_t lookup_qname (xqp_string default_ns, xqp_string pfx, xqp_string local) const;
  QNameItem_t lookup_elem_qname (xqp_string name) const {
    return lookup_qname (default_elem_type_ns (), name);
  }
  QNameItem_t lookup_elem_qname (xqp_string pfx, xqp_string local) const {
    return lookup_qname (default_elem_type_ns (), pfx, local);
  }
  QNameItem_t lookup_fn_qname (xqp_string pfx, xqp_string local) const {
    return lookup_qname (default_function_namespace (), pfx, local);
  }

  expr *lookup_var (xqp_string prefix, xqp_string local) const {
    return lookup_expr ("var:" + qname_internal_key ("", prefix, local));
  }
  expr *lookup_var (xqp_string varname) const {
    return lookup_expr ("var:" + qname_internal_key ("", varname));
  }
  void bind_var (const QNameItem *qname, expr *expr) {
    bind_expr ("var:" + qname_internal_key (qname), expr);
  }
  void bind_var (xqp_string prefix, xqp_string local, expr *expr) {
    bind_expr ("var:" + qname_internal_key ("", prefix, local), expr);
  }
  void bind_var (xqp_string varname, expr *expr) {
    bind_expr ("var:" + qname_internal_key ("", varname), expr);
  }
  function *lookup_fn (xqp_string prefix, xqp_string local, int arity) const {
    function *f = lookup_func (fn_internal_key (arity) + qname_internal_key (default_function_namespace (), prefix, local));
    if (f != NULL) return f;
    else {
      f = lookup_func (fn_internal_key (VARIADIC_SIG_SIZE) + qname_internal_key (default_function_namespace (), prefix, local));
      if (f == NULL)
        ZORBA_ERROR_ALERT (error_messages::XPST0017_STATIC_FUNCTION_NOT_FOUND,
                           error_messages::STATIC_ERROR, NULL);
      return f;
    }
  }
  static function *lookup_builtin_fn (xqp_string local, int arity);
  void bind_fn (xqp_string prefix, xqp_string local, function *f, int arity) {
    bind_func (fn_internal_key (arity) + qname_internal_key (default_function_namespace (), prefix, local), f);
  }
  void bind_fn (xqp_string fname, function *f, int arity) {
    bind_func (fn_internal_key (arity) + qname_internal_key (default_function_namespace (), fname), f);
  }

	void add_variable_type( const QNameItem *var_name, TypeSystem::xqtref_t var_type);
	TypeSystem::xqtref_t  get_variable_type( QNameItem *var_name );

	void bind_type( xqp_string key, TypeSystem::xqtref_t t);
	TypeSystem::xqtref_t  lookup_type (xqp_string key);

	COLLATION_OBJ	*lookup_collation(xqp_string coll_uri);
	void		bind_collation(xqp_string coll_uri, COLLATION_OBJ*);

  #if 0
  PlanIter_t namespaces() const;
	PlanIter_t in_scope_schema_types() const;
	PlanIter_t in_scope_element_decls() const;
	PlanIter_t in_scope_attribute_decls() const;
	PlanIter_t collations() const;
  #endif

	StaticQueryContext::xpath1_0compatib_mode_t xpath1_0compatib_mode() const;
	StaticQueryContext::construction_mode_t construction_mode() const;
	StaticQueryContext::order_empty_mode_t order_empty_mode() const;
	StaticQueryContext::boundary_space_mode_t boundary_space_mode() const;
	StaticQueryContext::inherit_mode_t inherit_mode() const;
	StaticQueryContext::preserve_mode_t preserve_mode() const;
	
	void set_xpath1_0compatib_mode(StaticQueryContext::xpath1_0compatib_mode_t v);
	void set_construction_mode(StaticQueryContext::construction_mode_t v);
	void set_order_empty_mode(StaticQueryContext::order_empty_mode_t v);
	void set_boundary_space_mode(StaticQueryContext::boundary_space_mode_t v);
	void set_inherit_mode(StaticQueryContext::inherit_mode_t v);
	void set_preserve_mode(StaticQueryContext::preserve_mode_t v);

  xqp_string default_collation_uri() const;
	void set_default_collation_uri(xqp_string);
	::Collator*	get_collation(xqp_string collation_uri, bool error_if_not_found = true);
	void add_collation(xqp_string collation_uri, 
										std::string  coll_string, 
										::Collator::ECollationStrength coll_strength,
										::Collator *coll,
										bool is_user_created);
	::Collator *getDefaultCollation();

	void set_context_item_static_type(TypeSystem::xqtref_t t);
	TypeSystem::xqtref_t		context_item_static_type();

	void set_default_collection_type(TypeSystem::xqtref_t t);
	TypeSystem::xqtref_t		default_collection_type();

	void set_function_type(const QNameItem *qname, TypeSystem::xqtref_t t);
  TypeSystem::xqtref_t get_function_type(const QNameItem_t);
	
	void set_document_type(xqp_string docURI, TypeSystem::xqtref_t t);
  TypeSystem::xqtref_t get_document_type(const xqp_string);
	
	void set_collection_type(xqp_string collURI, TypeSystem::xqtref_t t);
  TypeSystem::xqtref_t get_collection_type(const xqp_string);
	
	StaticQueryContext::ordering_mode_t ordering_mode() const;
	void set_ordering_mode(StaticQueryContext::ordering_mode_t v);

  xqp_string baseuri() const;
	void set_baseuri(xqp_string, bool from_prolog = true);
  xqp_string current_absolute_baseuri() const;
	void set_current_absolute_baseuri(xqp_string);
  xqp_string encapsulating_entity_baseuri() const;
	void set_encapsulating_entity_baseuri(xqp_string);
  xqp_string entity_file_uri() const;
	void set_entity_file_uri(xqp_string);
	
	xqp_string		resolve_relative_uri( xqp_string uri );

};

pair<xqp_string, xqp_string> parse_qname (xqp_string qname);


}	/* namespace xqp */
#endif /*	XQP_STATIC_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
