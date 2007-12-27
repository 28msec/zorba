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
#include "util/utf8/xqpString.h"
#include "types/representations.h"

namespace xqp {

  class zorba;
  class expr; class var_expr;
  class function;
	class XQType;
/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

class context : public rcobject
{
protected:
	typedef struct //: public CollationManager::COLLATION_DESCR
	{
		xqp_string		coll_uri;
		std::string		coll_string;
		::Collator::ECollationStrength	coll_strength;

		bool					is_user_created;
		::Collator		*coll;
	}COLLATION_OBJ;

  typedef union { 
    expr *exprValue;
    function *functionValue;
    int intValue;
    bool boolValue;
		XQType		*typeValue;///do manual ref counting on this
		COLLATION_OBJ	*collationValue;
  } ctx_value_t;
  typedef xqp_string (* str_param_t) ();
  
protected:
	context *parent;
	fxhashmap<ctx_value_t> keymap;
	fxhashmap<xqp_string> str_keymap;

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

  expr *lookup_expr (xqp_string key) const {
    ctx_value_t val;
    return context_value (key, val) ? val.exprValue : NULL;
  }
  // unlike other lookups, failure does not raise an assertion
  function *lookup_func (xqp_string key) const {
    ctx_value_t val;
    return (context_value (key, val)) ? val.functionValue : NULL;
  }
  void bind_expr (xqp_string key, expr *e) {
    ctx_value_t v = { e };
    keymap.put (key, v);
  }
  void bind_func (xqp_string key, function *f) {
    ctx_value_t v;
    v.functionValue = f;
    keymap.put (key, v);
  }
  void bind_str  (xqp_string key, xqp_string v) {
    str_keymap.put (key, v);
  }

public:
  context (context *_parent = NULL) : parent (_parent) {}
	context *get_parent() const { return parent; }
};


}	/* namespace xqp */

#endif /*	XQP_CONTEXT_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
