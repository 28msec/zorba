/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_CONTEXT_H
#define ZORBA_CONTEXT_H

#include "zorbatypes/xqpstring.h"
#include "zorbatypes/representations.h"

#include "util/rchandle.h"

#include "util/hashmap.h"

namespace zorba {

  class expr; class var_expr;
  class function;
	class XQType;
  class StatelessExternalFunction;
/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

class context : public SimpleRCObject
{
protected:
  typedef union { 
    expr             * exprValue;
    function         * functionValue;
    int                intValue;
    bool               boolValue;
		const XQType     * typeValue; ///do manual ref counting on this
    StatelessExternalFunction* stateless_function;
  } ctx_value_t;

  typedef xqp_string (* str_param_t) ();
  
protected:
	context              * parent;
	hashmap<ctx_value_t>   keymap;
	hashmap<xqp_string>    str_keymap;

  bool lookup_once (xqp_string key, xqp_string &val) const
  { return str_keymap.get (key, val); }

  bool lookup_once (xqp_string key, ctx_value_t &val) const
  { return keymap.get (key, val); }

	template<class V> bool context_value(xqp_string key, V &val) const
	{
		if (lookup_once (key, val))
      return true;
    else
      return parent == NULL ? false : parent->context_value (key, val);
	}

  StatelessExternalFunction*
  lookup_stateless_function(xqp_string key) const {
    ctx_value_t v;
    return context_value (key, v) ? v.stateless_function : NULL;
  }

  expr *lookup_expr (xqp_string key) const {
    ctx_value_t val;
    return context_value (key, val) ? val.exprValue : NULL;
  }

  // unlike other lookups, failure does not raise an assertion
  function *lookup_func (xqp_string key) const {
    ctx_value_t val;
    return (context_value (key, val)) ? val.functionValue : NULL;
  }

  // defined in in static_context.cpp
  void bind_expr (xqp_string key, expr *e);
  void bind_func (xqp_string key, function *f);

  bool bind_stateless_function(xqp_string key, StatelessExternalFunction* f) {
    ctx_value_t v;
    v.stateless_function = f;
    if (lookup_once (key, v))
      return false;
    keymap.put (key, v);
    return true;
  }

  void bind_str (xqp_string key, xqp_string v, XQUERY_ERROR err = XQP0019_INTERNAL_ERROR) {
    xqp_string old;
    if (err != MAX_ZORBA_ERROR_CODE && lookup_once (key, old))
      ZORBA_ERROR(err);
    str_keymap.put (key, v);
  }

public:
  context (context *_parent = NULL) : parent (_parent) {}
	context *get_parent() const { return parent; }
};


}	/* namespace zorba */

#endif /*	ZORBA_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
