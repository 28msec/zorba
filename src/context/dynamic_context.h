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
#include "util/rchandle.h"
#include "types/sequence_type.h"

namespace xqp {

class itemstore;

class dynamic_context : public context
{
public:
	typedef enum { ordered, unordered } ordering_mode_t;
	
protected:
	//daniel: these serve as constant global keys
	static bool static_init;

public:
	static void init();
	dynamic_context() {}
	~dynamic_context() {}

public:
	// XQuery 1.0 dynamic context 
	Item_t context_item() const;

	sequence_type_t context_item_type() const;
	uint32_t context_position() const;
	uint32_t context_size() const;

	void set_context_item(Item_t);
	void set_context_item_type(sequence_type_t );

  #if 0
  // return the value of a variable by QName
	PlanIter_t var_value(const Item*) const;

	const Item& default_element_type_namespace() const;
	void set_default_element_type_namespace(Item&);
	PlanIter_t namespaces() const;
	void add_namespace(Item&);
  #endif

	ordering_mode_t ordering_mode() const;
	void set_ordering_mode(ordering_mode_t v);
};


}	/* namespace xqp */
#endif /*	XQP_DYNAMIC_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
