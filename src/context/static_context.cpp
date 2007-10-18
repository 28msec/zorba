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
 * @file context/static_context.cpp
 *
 */

#include "context/static_context.h"
#include "context/common.h"
#include "store/api/item.h"

// MS Visual Studio does not fully support throw(), and issues a warning
#ifndef _MSC_VER
#define THROW_XQP_EXCEPTION		throw(xqp_exception)
#else
#define THROW_XQP_EXCEPTION		
#endif

using namespace std;
namespace xqp {

bool static_context::static_init = false;


void static_context::init()
{
	
	if (!static_context::static_init) {
		static_context::static_init = true;
	}
}
  
  DECL_ENUM_PARAM (static_context, construction_mode)
  DECL_ENUM_PARAM (static_context, order_empty_mode)
  DECL_ENUM_PARAM (static_context, boundary_space_mode)
  DECL_ENUM_PARAM (static_context, inherit_mode)
  DECL_ENUM_PARAM (static_context, preserve_mode)

  DECL_STR_PARAM (static_context, baseuri)
  DECL_STR_PARAM (static_context, default_collation)
  DECL_STR_PARAM (static_context, default_function_namespace)

/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

sequence_type_t static_context::get_function_type(
	const Item* qname_p) const
THROW_XQP_EXCEPTION
{
	//stub
	return xs_anyType;
}

sequence_type_t static_context::get_document_type(
	const string& doctype) const
THROW_XQP_EXCEPTION
{
	//stub
	return xs_anyType;
}

sequence_type_t static_context::get_collection_type(
	const string& colltype) const
THROW_XQP_EXCEPTION
{
	//stub
	return xs_anyType;
}


}	/* namespace xqp */

