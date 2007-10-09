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
 * @file context/context.h
 *
 */


#ifndef XQP_CONTEXT_H
#define XQP_CONTEXT_H

#include "common.h"
#include "runtime/item_iterator.h"
#include "util/fxhashmap.h"
#include "util/rchandle.h"
#include "errors/Error.h"
#include "../store/api/item_factory.h"

namespace xqp {

class zorba;

/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

class context : public rcobject
{
protected:
	rchandle<context> parent_h;
	fxhash64map<Iterator_t> keymap;

public: // context interface
  context (context *_parent = NULL) : parent_h (_parent) {}
	rchandle<context> parent() const { return parent_h; }

	Iterator_t context_value(qnamekey_t key) const
	{
		Iterator_t it_h;
		if (!keymap.get(key, it_h)) return NULL;
		return it_h;
	}

};


}	/* namespace xqp */
#endif /*	XQP_CONTEXT_H */

