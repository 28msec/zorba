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

#include "context/common.h"
#include "util/fx/fxhashmap.h"
#include "util/rchandle.h"
#include "errors/Error.h"

namespace xqp {

  class zorba;
  class expr;

/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

class context : public rcobject
{
protected:
  typedef union { 
    expr *exprValue;
    int intValue;
    bool boolValue;
  } ctx_value_t;
  
protected:
	context *parent;
	fxhashmap<ctx_value_t> keymap;
	fxhashmap<string> str_keymap;

public: // context interface
  context (context *_parent = NULL) : parent (_parent) {}
	context *get_parent() const { return parent; }

	template<class V> V context_value(const fxhashmap<V> &keymap, string key, bool *found) const
	{
    V val;
		if (keymap.get(key, val)) {
      *found = true;
      return val;
    } else
      if (parent != NULL)
        return parent->context_value (keymap, key, found);
      else {
        *found = false;
        return val;
      }
	}

  expr *lookup_expr (string key) const {
    bool found;
    ctx_value_t e = context_value (keymap, key, &found);
    return found ? e.exprValue : NULL;
  }

  void bind_var (string name, expr *e) {
    ctx_value_t v = { e };
    keymap.put (name, v);
  }

};


}	/* namespace xqp */

#endif /*	XQP_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
