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
 * @file context/dynamic_context.h
 *
 */

#ifndef XQP_DYNAMIC_CONTEXT_H
#define XQP_DYNAMIC_CONTEXT_H

#include "common.h"
#include "context.h"
#include "functions/library.h"
#include "util/rchandle.h"
#include "runtime/item_iterator.h"
#include "values/nodes.h"
#include "values/value_factory.h"

namespace xqp {

class itemstore;

class dynamic_context : public context
{
public:
	enum ordering_mode_t	{ ordered, unordered };
	
protected:
	static bool static_init;
	static qnamekey_t namespaces_key;
	static qnamekey_t default_element_type_ns_key;
	static qnamekey_t context_item_key;
	static qnamekey_t context_item_type_key;
	static qnamekey_t ordering_mode_key;
	static qnamekey_t current_time_key;
	static qnamekey_t implicit_timezone_key;

	zorba* zorp;
	value_factory* vfactory_p;
	library* lib;

public:
	static void init(value_factory*);
	dynamic_context(zorba* _zorp, value_factory* v_p)
		: zorp(_zorp), vfactory_p(v_p) {}
	~dynamic_context() {}

public:
	// return the value of a variable by QName
	iterator_t var_value(const qname*) const;

	// set/get the function library
	void set_library(library* _lib) { lib = _lib; }
	library* get_library() const { return lib; }

public:
	// XQuery 1.0 dynamic context 
	item_t context_item() const;

	sequence_type_t context_item_type() const;
	uint32_t context_position() const;
	uint32_t context_size() const;

	void set_context_item(item_t);
	void set_context_item_type(sequence_type_t );

	iterator_t namespaces() const;
	void add_namespace(namespace_node&);

	const namespace_node& default_element_type_namespace() const;
	void set_default_element_type_namespace(namespace_node&);

	enum ordering_mode_t ordering_mode() const;
	void set_ordering_mode(enum ordering_mode_t v);

	const function* get_function(qnamekey_t key) { return lib->get(key); }

};


}	/* namespace xqp */
#endif /*	XQP_DYNAMIC_CONTEXT_H */

