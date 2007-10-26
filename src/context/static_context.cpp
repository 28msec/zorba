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

/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/

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

  const char *static_context::default_ns_initializers [] = {
    "fn", XQUERY_FN_NS,
    "xml", "http://www.w3.org/XML/1998/namespace",
    "xs", "http://www.w3.org/2001/XMLSchema",
    "xsi", "http://www.w3.org/2001/XMLSchema-instance",
    "local", "http://www.w3.org/2005/xquery-local-functions",
    NULL, NULL
  };

  static_context *static_context::root_static_context () {
    static static_context *p = new static_context (default_ns_initializers);
    return p;
  }
  
  static_context::static_context (const char **p) {
    for (; *p != NULL; p += 2)
      bind_ns (p [0], p [1]);
    set_default_function_namespace (lookup_ns ("fn"));
    set_default_elem_type_ns ("");
  }

  void static_context::init () {
  }
  
  DECL_ENUM_PARAM (static_context, construction_mode)
  DECL_ENUM_PARAM (static_context, order_empty_mode)
  DECL_ENUM_PARAM (static_context, boundary_space_mode)
  DECL_ENUM_PARAM (static_context, inherit_mode)
  DECL_ENUM_PARAM (static_context, preserve_mode)

  DECL_STR_PARAM (static_context, baseuri)
  DECL_STR_PARAM (static_context, default_collation)
  DECL_STR_PARAM (static_context, default_function_namespace)
  DECL_STR_PARAM (static_context, default_elem_type_ns)

  string static_context::lookup_ns (string prefix) const {
    string ns;
    Assert (context_value ("ns:" + prefix, ns));
    return ns;
  }
  void static_context::bind_ns (string prefix, string ns) {
    bind_str ("ns:" + prefix, ns);
  }

  function *static_context::lookup_builtin_fn (string local) const {
    return lookup_func ("fn:" + make_expanded_qname (XQUERY_FN_NS, local));
  }
  string static_context::expand_qname (string default_ns, string prefix, string local) const {
    return make_expanded_qname
      (prefix.empty () ? default_ns : lookup_ns (prefix), local);
  }
  string static_context::expand_qname (string default_ns, string qname) const {
    string::size_type n = qname.find(':');
    return (n == string::npos) ?
      expand_qname (default_ns, "", qname) :
      expand_qname (default_ns, qname.substr (0, n), qname.substr (n+1));
  }

sequence_type_t static_context::get_function_type(
	const Item* qname_p) const
THROW_XQP_EXCEPTION
{
	// TODO
	return xs_anyType;
}

sequence_type_t static_context::get_document_type(
	const string& doctype) const
THROW_XQP_EXCEPTION
{
	// TODO
	return xs_anyType;
}

sequence_type_t static_context::get_collection_type(
	const string& colltype) const
THROW_XQP_EXCEPTION
{
	// TODO
	return xs_anyType;
}


}	/* namespace xqp */

