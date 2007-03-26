/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: abstract_context.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_ABSTRACT_CONTEXT_H
#define XQP_ABSTRACT_CONTEXT_H

#include "common.h"
#include "../runtime/abstract_iterator.h"
#include "../util/rchandle.h"
#include "../util/xqp_exception.h"

namespace xqp {

/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

class abstract_context : public rcobject
{
public:	// types
	enum construction_mode_t {
		cons_preserve,
		cons_strip
	};

	enum ordering_mode_t {
		ordered,
		unordered
	};

	enum order_empty_mode_t {
		empty_greatest,
		empty_least
	};

	enum boundary_space_mode_t {
		preserve_space,
		strip_space
	};

	enum inherit_mode_t {
		inherit_ns,
		no_inherit_ns
	};

	enum preserve_mode_t {
		preserve_ns,
		no_preserve_ns
	};

public:	// context interface
	virtual rchandle<abstract_context> parent() const = 0;
	virtual iterator_t context_value(abstract_qname* context_key) const = 0;

	// XQuery 1.0 static context
	virtual const abstract_namespace_node* default_element_type_namespace() const = 0;
	virtual const abstract_namespace_node* default_function_namespace() const = 0;

	virtual void set_default_element_type_namespace(const abstract_namespace_node*) = 0;
	virtual void set_default_function_namespace(const abstract_namespace_node*) = 0;
	virtual void add_namespace(const abstract_namespace_node*) = 0;

  virtual iterator_t namespaces() const
	virtual iterator_t in_scope_schema_types() const = 0;
	virtual iterator_t in_scope_element_decls const = 0;
	virtual iterator_t in_scope_attribute_decls() const = 0;
	virtual iterator_t in_scope_vars() const = 0;
	virtual iterator_t collations() const = 0;

	virtual sequence_type_t context_item_type() const = 0;
	virtual enum construction_mode_t construction_mode() const = 0;
	virtual enum ordering_mode_t ordering_mode() const = 0;
	virtual enum order_empty_mode_t order_empty_mode() const = 0;
	virtual enum boundary_space_mode_t boundary_space_mode() const = 0;
	virtual enum inherit_mode_t inherit_mode() const = 0;
	virtual enum preserve_mode_t preserve_mode() const = 0;
	
	virtual void set_context_item_type(sequence_type_t v) = 0;
	virtual void set_construction_mode(enum construction_mode_t v) = 0;
	virtual void set_ordering_mode(enum ordering_mode_t v) = 0;
	virtual void set_order_empty_mode(enum order_empty_mode_t v) = 0;
	virtual void set_boundary_space_mode(enum boundary_space_mode_t v) = 0;
	virtual void set_inherit_mode(enum inherit_mode_t v) = 0;
	virtual void set_preserve_mode(enum preserve_mode_t v) = 0;

	virtual const abstract_qname* get_default_collation() const = 0;
	virtual std::string get_baseuri() const = 0;

	virtual void set_default_collation(const abstract_qname*) = 0;
	virtual void set_baseuri(const std::string&) = 0;
	
	virtual sequence_type_t get_function_type(const abstract_qname*) 
		const throw (xqp_exception) = 0;
	virtual sequence_type_t get_document_type(const std::string&) 
	  const throw (xqp_exception) = 0;
	virtual sequence_type_t get_collection_type(const std::string&) 
	  const throw (xqp_exception) = 0;
	
	// XQuery 1.0 dynamic context 
	virtual const abstract_item* context_item() const = 0;
	virtual uint32_t context_position() const = 0;
	virtual uint32_t context_size() const = 0;
	virtual iterator_t var_value(const abstract_qname*) = 0;
	
};


}	/* namespace xqp */
#endif /*	XQP_ABSTRACT_CONTEXT_H */

