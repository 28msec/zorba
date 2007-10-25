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
  typedef std::string (* str_param_t) ();
  
protected:
	context *parent;
	fxhashmap<ctx_value_t> keymap;
	fxhashmap<string> str_keymap;

  bool lookup_once (string key, string &val) const
  { return str_keymap.get (key, val); }
  bool lookup_once (string key, ctx_value_t &val) const
  { return keymap.get (key, val); }

public: // context interface
  context (context *_parent = NULL) : parent (_parent) {}
	context *get_parent() const { return parent; }

	template<class V> bool context_value(string key, V &val) const
	{
		if (lookup_once (key, val))
        return true;
    else
      return parent == NULL ? false : parent->context_value (key, val);
	}

  expr *lookup_expr (string key) const {
    ctx_value_t val;
    return context_value (key, val) ? val.exprValue : NULL;
  }

  void bind_expr (string key, expr *e) {
    ctx_value_t v = { e };
    keymap.put (key, v);
  }
  void bind_str  (string key, string v) {
    str_keymap.put (key, v);
  }

};


}	/* namespace xqp */

#endif /*	XQP_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
