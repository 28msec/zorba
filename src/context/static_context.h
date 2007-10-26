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
#include "../types/sequence_type.h"
#include "../store/api/item.h"
#include "../store/api/store.h"

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

class static_context : public context
{
public:	// types
	typedef enum { cons_preserve, cons_strip } construction_mode_t;
	typedef enum { empty_greatest, empty_least } order_empty_mode_t;
	typedef enum { preserve_space, strip_space } boundary_space_mode_t;
	typedef enum { inherit_ns, no_inherit_ns } inherit_mode_t;
	typedef enum { preserve_ns, no_preserve_ns } preserve_mode_t;

protected:
  static const char *default_ns_initializers [];
  static_context (const char **);
  static std::string make_expanded_qname (std::string ns, std::string local) {
    return local + ":" + ns;
  }
  std::string expand_qname (std::string default_ns, std::string prefix, std::string local) const;
  std::string expand_qname (std::string default_ns, std::string qname) const;
  
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

  expr *lookup_var (std::string prefix, std::string local) const {
    return lookup_expr ("var:" + expand_qname ("", prefix, local));
  }
  expr *lookup_var (std::string varname) const {
    return lookup_expr ("var:" + expand_qname ("", varname));
  }
  void bind_var (std::string prefix, std::string local, expr *expr) {
    bind_expr ("var:" + expand_qname ("", prefix, local), expr);
  }
  void bind_var (std::string varname, expr *expr) {
    bind_expr ("var:" + expand_qname ("", varname), expr);
  }

  function *lookup_fn (std::string prefix, std::string local) const {
    return lookup_func ("fn:" + expand_qname (default_function_namespace (), prefix, local));
  }
  function *lookup_builtin_fn (std::string local) const;
  void bind_fn (std::string prefix, std::string local, function *f) {
    bind_func ("fn:" + expand_qname (default_function_namespace (), prefix, local), f);
  }
  void bind_fn (std::string fname, function *f) {
    bind_func ("fn:" + expand_qname (default_function_namespace (), fname), f);
  }

  #if 0
  PlanIter_t namespaces() const;
	PlanIter_t in_scope_schema_types() const;
	PlanIter_t in_scope_element_decls() const;
	PlanIter_t in_scope_attribute_decls() const;
	PlanIter_t collations() const;
  #endif

	construction_mode_t construction_mode() const;
	order_empty_mode_t order_empty_mode() const;
	boundary_space_mode_t boundary_space_mode() const;
	inherit_mode_t inherit_mode() const;
	preserve_mode_t preserve_mode() const;
	
	void set_construction_mode(construction_mode_t v);
	void set_order_empty_mode(order_empty_mode_t v);
	void set_boundary_space_mode(boundary_space_mode_t v);
	void set_inherit_mode(inherit_mode_t v);
	void set_preserve_mode(preserve_mode_t v);

  std::string default_collation() const;
	void set_default_collation(std::string);

  std::string baseuri() const;
	void set_baseuri(std::string);
	
	sequence_type_t get_function_type(const Item*) 
		const THROW_XQP_EXCEPTION;
	sequence_type_t get_document_type(const std::string&) 
	  const THROW_XQP_EXCEPTION;
	sequence_type_t get_collection_type(const std::string&) 
	  const THROW_XQP_EXCEPTION;
	
};


}	/* namespace xqp */
#endif /*	XQP_STATIC_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
