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
#include "context.h"
#include "context/context_impl.h"
#include "errors/Error.h"
#include "../store/api/item.h"
#include "../store/api/store.h"
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
  std::string qname_internal_key (QNameItem_t qname) const;
  std::string qname_internal_key (std::string default_ns, std::string prefix, std::string local) const;
  std::string qname_internal_key (std::string default_ns, std::string qname) const;
  static std::string fn_internal_key (int arity);
  
public:
	static void init();
  static_context()
		: context (root_static_context ()) {}
  static_context (static_context *_parent)
    : context (_parent) {}

	~static_context() {}

  static static_context *root_static_context ();

public:
  std::string default_function_namespace() const;
	void set_default_function_namespace(std::string);
  std::string default_elem_type_ns () const;
  void set_default_elem_type_ns (std::string);

  std::string lookup_ns (std::string prefix) const;
  void bind_ns (std::string prefix, std::string ns);

  QNameItem_t lookup_qname (string default_ns, string name) const;
  QNameItem_t lookup_qname (string default_ns, string pfx, string local) const;
  QNameItem_t lookup_elem_qname (string name) const {
    return lookup_qname (default_elem_type_ns (), name);
  }
  QNameItem_t lookup_elem_qname (string pfx, string local) const {
    return lookup_qname (default_elem_type_ns (), pfx, local);
  }

  expr *lookup_var (std::string prefix, std::string local) const {
    return lookup_expr ("var:" + qname_internal_key ("", prefix, local));
  }
  expr *lookup_var (std::string varname) const {
    return lookup_expr ("var:" + qname_internal_key ("", varname));
  }
  void bind_var (QNameItem_t qname, expr *expr) {
    bind_expr ("var:" + qname_internal_key (qname), expr);
  }
  void bind_var (std::string prefix, std::string local, expr *expr) {
    bind_expr ("var:" + qname_internal_key ("", prefix, local), expr);
  }
  void bind_var (std::string varname, expr *expr) {
    bind_expr ("var:" + qname_internal_key ("", varname), expr);
  }

  function *lookup_fn (std::string prefix, std::string local, int arity) const {
    return lookup_func (fn_internal_key (arity) + qname_internal_key (default_function_namespace (), prefix, local));
  }
  static function *lookup_builtin_fn (std::string local, int arity);
  void bind_fn (std::string prefix, std::string local, function *f, int arity) {
    bind_func (fn_internal_key (arity) + qname_internal_key (default_function_namespace (), prefix, local), f);
  }
  void bind_fn (std::string fname, function *f, int arity) {
    bind_func (fn_internal_key (arity) + qname_internal_key (default_function_namespace (), fname), f);
  }

  #if 0
  PlanIter_t namespaces() const;
	PlanIter_t in_scope_schema_types() const;
	PlanIter_t in_scope_element_decls() const;
	PlanIter_t in_scope_attribute_decls() const;
	PlanIter_t collations() const;
  #endif

	StaticQueryContext::construction_mode_t construction_mode() const;
	StaticQueryContext::order_empty_mode_t order_empty_mode() const;
	StaticQueryContext::boundary_space_mode_t boundary_space_mode() const;
	StaticQueryContext::inherit_mode_t inherit_mode() const;
	StaticQueryContext::preserve_mode_t preserve_mode() const;
	
	void set_construction_mode(StaticQueryContext::construction_mode_t v);
	void set_order_empty_mode(StaticQueryContext::order_empty_mode_t v);
	void set_boundary_space_mode(StaticQueryContext::boundary_space_mode_t v);
	void set_inherit_mode(StaticQueryContext::inherit_mode_t v);
	void set_preserve_mode(StaticQueryContext::preserve_mode_t v);

  std::string default_collation() const;
	void set_default_collation(std::string);

  std::string baseuri() const;
	void set_baseuri(std::string);
	
    TypeSystem::xqtref_t get_function_type(const Item*) 
		const THROW_XQP_EXCEPTION;
    TypeSystem::xqtref_t get_document_type(const std::string&) 
	  const THROW_XQP_EXCEPTION;
    TypeSystem::xqtref_t get_collection_type(const std::string&) 
	  const THROW_XQP_EXCEPTION;
	
	StaticQueryContext::ordering_mode_t ordering_mode() const;
	void set_ordering_mode(StaticQueryContext::ordering_mode_t v);

};


}	/* namespace xqp */
#endif /*	XQP_STATIC_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
