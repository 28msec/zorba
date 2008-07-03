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

  bool lookup_once2 (const char *key1, xqp_string key2, xqp_string &val) const
  { return str_keymap.get2 (key1, key2, val); }

  bool lookup_once (xqp_string key, ctx_value_t &val) const
  { return keymap.get (key, val); }

  bool lookup_once2 (const char *key1, xqp_string key2, ctx_value_t &val) const
  { return keymap.get2 (key1, key2, val); }

	template<class V> bool context_value(xqp_string key, V &val) const
	{
		if (lookup_once (key, val))
      return true;
    else
      return parent == NULL ? false : parent->context_value (key, val);
	}
	template<class V> bool context_value2(const char *key1, xqp_string key2, V &val) const
	{
		if (lookup_once2 (key1, key2, val))
      return true;
    else
      return parent == NULL ? false : parent->context_value2 (key1, key2, val);
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
  expr *lookup_expr2 (const char *key1, xqp_string key2) const {
    ctx_value_t val;
    return context_value2 (key1, key2, val) ? val.exprValue : NULL;
  }

  // unlike other lookups, failure does not raise an assertion
  function *lookup_func (xqp_string key) const {
    ctx_value_t val;
    return (context_value (key, val)) ? val.functionValue : NULL;
  }
  function *lookup_func2 (xqp_string key1, xqp_string key2) const {
    ctx_value_t val;
    return (context_value2 (key1.c_str(), key2, val)) ? val.functionValue : NULL;
  }

  // defined in in static_context.cpp
  bool bind_expr (xqp_string key, expr *e);
  bool bind_func (xqp_string key, function *f);
  bool bind_expr2 (const char *key1, xqp_string key2, expr *e);
  bool bind_func2 (const char *key1, xqp_string key2, function *f);

  bool bind_stateless_function(xqp_string key, StatelessExternalFunction* f) {
    ctx_value_t v;
    v.stateless_function = f;
    return ! keymap.put (key, v);
  }

  void bind_str (xqp_string key, xqp_string v, XQUERY_ERROR err = XQP0019_INTERNAL_ERROR) {
    if (str_keymap.put (key, v))
      if (err != MAX_ZORBA_ERROR_CODE)
        ZORBA_ERROR(err);
  }
  void bind_str2 (const char *key1, xqp_string key2, xqp_string v, XQUERY_ERROR err = XQP0019_INTERNAL_ERROR) {
    if (str_keymap.put2 (key1, key2, v))
      if (err != MAX_ZORBA_ERROR_CODE)
        ZORBA_ERROR(err);
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
