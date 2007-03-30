/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: static_context.h,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#ifndef XQP_STATIC_CONTEXT_H
#define XQP_STATIC_CONTEXT_H

#include "common.h"
#include "abstract_context.h"
#include "../runtime/abstract_iterator.h"
#include "../values/abstract_qname.h"
#include "../values/abstract_nodes.h"
#include "../values/abstract_value_factory.h"

#include "../util/fxhashmap.h"
#include "../util/rchandle.h"
#include "../util/xqp_exception.h"


namespace xqp {

class itemstore;

/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

class static_context : public abstract_context
{
public:	// types
	enum construction_mode_t		{ cons_preserve, cons_strip };
	enum ordering_mode_t				{ ordered, unordered };
	enum order_empty_mode_t			{ empty_greatest, empty_least };
	enum boundary_space_mode_t	{ preserve_space, strip_space };
	enum inherit_mode_t					{ inherit_ns, no_inherit_ns };
	enum preserve_mode_t				{ preserve_ns, no_preserve_ns };

protected:
	fxhash64map<iterator_t> keymap;
	rchandle<abstract_context> parent_h;
	abstract_value_factory* vf_p;

	static bool static_init;
	static qnamekey_t default_function_ns_key;
	static qnamekey_t default_collation_key;
	static qnamekey_t in_scope_schema_types_key;
	static qnamekey_t in_scope_element_decls_key;
	static qnamekey_t in_scope_attribute_decls_key;
	static qnamekey_t collations_key;
	static qnamekey_t construction_mode_key;
	static qnamekey_t order_empty_mode_key;
	static qnamekey_t boundary_space_mode_key;
	static qnamekey_t inherit_mode_key;
	static qnamekey_t preserve_mode_key;
	static qnamekey_t baseuri_key;

public:
	void init(itemstore&) const;
	static_context();
	~static_context();

public:
	// context interface
	rchandle<abstract_context> parent() const;
	iterator_t context_value(qnamekey_t context_key) const;

public:
	// XQuery 1.0 static context
	abstract_namespace_node* default_function_namespace() const;
	void set_default_function_namespace(abstract_namespace_node*);

  iterator_t namespaces() const;
	iterator_t in_scope_schema_types() const;
	iterator_t in_scope_element_decls() const;
	iterator_t in_scope_attribute_decls() const;
	iterator_t collations() const;

	enum construction_mode_t construction_mode() const;
	enum order_empty_mode_t order_empty_mode() const;
	enum boundary_space_mode_t boundary_space_mode() const;
	enum inherit_mode_t inherit_mode() const;
	enum preserve_mode_t preserve_mode() const;
	
	void set_construction_mode(enum construction_mode_t v);
	void set_order_empty_mode(enum order_empty_mode_t v);
	void set_boundary_space_mode(enum boundary_space_mode_t v);
	void set_inherit_mode(enum inherit_mode_t v);
	void set_preserve_mode(enum preserve_mode_t v);

	const abstract_qname* get_default_collation() const;
	std::string get_baseuri() const;

	void set_default_collation(const std::string&);
	void set_baseuri(const std::string&);
	
	sequence_type_t get_function_type(const abstract_qname*) 
		const throw (xqp_exception);
	sequence_type_t get_document_type(const std::string&) 
	  const throw (xqp_exception);
	sequence_type_t get_collection_type(const std::string&) 
	  const throw (xqp_exception);
	
};


}	/* namespace xqp */
#endif /*	XQP_STATIC_CONTEXT_H */

