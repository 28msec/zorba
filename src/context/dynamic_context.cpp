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
 * @file context/dynamic_context.cpp
 *
 */

#include "context/dynamic_context.h"
#include <assert.h>

using namespace std;
namespace xqp {

bool dynamic_context::static_init = false;

void dynamic_context::init()
{
	if (!dynamic_context::static_init) {
		dynamic_context::static_init = true;
	}
}


/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/


sequence_type_t dynamic_context::context_item_type() const
{
	return xs_anyType; //stub
}

DECL_PARAM2 (dynamic_context, ordering_mode)

void dynamic_context::set_context_item_type(
	sequence_type_t v)
{
}

}	/* namespace xqp */

