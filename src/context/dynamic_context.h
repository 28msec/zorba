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

#include "context/common.h"
#include "context/context.h"
#include "context/context_impl.h"
#include "functions/library.h"
#include "store/api/item.h"
#include "util/rchandle.h"
#include "types/typesystem.h"

namespace xqp {

//class itemstore;
class static_context;

class dynamic_context// : public context
{
protected:
	typedef union
	{
		Iterator		*var_iterator;
	}dctx_value_t;
protected:
	static bool static_init;

	dynamic_context	*parent;
	hashmap<dctx_value_t> keymap;
	time_t	execution_date_time;
	int			implicit_timezone;

//	static_context	*sctx;

	xqp_string		default_collection_uri;//default URI for fn:collection()

protected:
  xqp_string qname_internal_key (Item_t qname) const;
  xqp_string qname_internal_key (xqp_string default_ns, xqp_string prefix, xqp_string local) const;
  xqp_string qname_internal_key (xqp_string default_ns, xqp_string qname) const;

  Iterator* lookup_var_iter (xqp_string key ) const;

  void bind_var_iter (xqp_string key, Iterator *it);
public:
	static void init();
	dynamic_context(dynamic_context *parent=NULL);
	~dynamic_context();

  xqp_string expand_varname(static_context	*sctx, xqp_string qname) const;

public:
	// XQuery 1.0 dynamic context 
	Item_t context_item() const;

	TypeSystem::xqtref_t context_item_type() const;
	uint32_t context_position() const;
	uint32_t context_size() const;

	void set_context_item(Item_t);
	void set_context_item_type(TypeSystem::xqtref_t );

  #if 0
  // return the value of a variable by QName
	PlanIter_t var_value(const Item*) const;

	const Item& default_element_type_namespace() const;
	void set_default_element_type_namespace(Item&);
	PlanIter_t namespaces() const;
	void add_namespace(Item&);
  #endif


//daniel: get the function directly from library object
//	const function* get_function(qnamekey_t key) { return lib->get(key); }

	void		set_execution_date_time(time_t t);
	time_t	get_execution_date_time();
	void		set_implicit_timezone(int tzone);
	int			get_implicit_timezone();

	void				add_variable(xqp_string varname, Iterator_t var_iterator);
	Iterator_t	get_variable(xqp_string varname);

	xqp_string get_default_collection();
	void set_default_collection(xqp_string default_collection_uri);

};


}	/* namespace xqp */
#endif /*	XQP_DYNAMIC_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
