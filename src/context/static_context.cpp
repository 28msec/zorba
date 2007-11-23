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

#include <assert.h>
#include "system/globalenv.h"
#include "context/static_context.h"
#include "context/common.h"
#include "util/zorba.h"

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

#define ITEM_FACTORY (Store::getInstance().getItemFactory())

  static_context *static_context::root_static_context () {
    static static_context *p = new static_context (default_ns_initializers);
		p->set_order_empty_mode (StaticQueryContext::empty_least);
    p->set_default_collation ("");
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

	DECL_ENUM_PARAM (static_context, ordering_mode)

  pair<xqpString, xqpString> parse_qname (xqpString qname) {
    int n = static_cast<std::string> (qname).find (':');
    return (n == string::npos)
      ? pair<xqpString, xqpString> ("", qname)
      : pair<xqpString, xqpString> (qname.substr (0, n), qname.substr (n+1));
  }

  static xqpString qname_internal_key2 (xqpString ns, xqpString local) {
    return local + ":" + ns;
  }
  QNameItem_t static_context::lookup_qname (xqpString default_ns, xqpString prefix, xqpString local) const {
    xqpStringStore *ssns = new xqpStringStore (prefix.empty () ? default_ns : lookup_ns (prefix)),
      *sspfx = new xqpStringStore (prefix), *sslocal = new xqpStringStore (local);
    return ITEM_FACTORY.createQName (ssns, sspfx, sslocal);
  }
  QNameItem_t static_context::lookup_qname (xqpString default_ns, xqpString qname) const {
    pair<xqpString, xqpString> rqname = parse_qname (qname);
    return lookup_qname (default_ns, rqname.first, rqname.second);
  }
  xqpString static_context::qname_internal_key (QNameItem_t qname) const {
    return qname_internal_key2 (qname->getNamespace (), qname->getLocalName ());
  }
  xqpString static_context::qname_internal_key (xqpString default_ns, xqpString prefix, xqpString local) const {
    return qname_internal_key2
      (prefix.empty () ? default_ns : lookup_ns (prefix), local);
  }
  xqpString static_context::qname_internal_key (xqpString default_ns, xqpString qname) const {
    pair<xqpString, xqpString> rqname = parse_qname (qname);
    return qname_internal_key (default_ns, rqname.first, rqname.second);
  }
  xqpString static_context::fn_internal_key (int arity) {
    ostringstream o;
    o << "fn:" << arity << "/";
    return o.str ();
  }

  xqpString static_context::lookup_ns (xqpString prefix) const {
    xqpString ns;
    Assert (context_value ("ns:" + prefix, ns));
    return ns;
  }
  void static_context::bind_ns (xqpString prefix, xqpString ns) {
    bind_str ("ns:" + prefix, ns);
  }

  function *static_context::lookup_builtin_fn (xqpString local, int arity) {
    return root_static_context ()->lookup_func (fn_internal_key (arity) + qname_internal_key2 (XQUERY_FN_NS, local));
  }

TypeSystem::xqtref_t static_context::get_function_type(
	const Item* qname_p) const
THROW_XQP_EXCEPTION
{
	// TODO
	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}

TypeSystem::xqtref_t static_context::get_document_type(
	const xqpString& doctype) const
THROW_XQP_EXCEPTION
{
	// TODO
	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}

TypeSystem::xqtref_t static_context::get_collection_type(
	const xqpString& colltype) const
THROW_XQP_EXCEPTION
{
	// TODO
	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}


}	/* namespace xqp */

