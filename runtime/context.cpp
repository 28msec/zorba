/* -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: context.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *
 *  Author: Paul Pedersen
 *
 */

#include "context.h"

#include <sstream>
#include <string>
#include <vector>

#include "../functions/function_impl.h"
#include "../types/qname.h"
#include "../types/collation.h"
#include "../types/builtin_types.h"
#include "../util/hashmap.h"
#include "../util/rchandle.h"
#include "../util/URI.h"
#include "../util/xqp_exception.h"
#include "namespace.h"

using namespace std;
namespace xqp {

  
///////////////////////////////
//  var_binding
///////////////////////////////

var_binding::var_binding()
:
  qname_h(NULL),
  type(xs_string)
{
}

var_binding::var_binding(
	rchandle<QName> _qname_h,
	static_type_t _type)
:
	qname_h(_qname_h),
	type(_type)
{
}



///////////////////////////////
//  context
///////////////////////////////


rchandle<signature> context::get_function_type(
  QName const& fqname, 
  uint32_t arity) const 
throw (xqp_exception)
{
  ostringstream oss;
  fqname.put(oss) << '[' << arity << ']';
  rchandle<signature> sig_h;
  if (!signature_map.get(oss.str(),sig_h)) {
    throw xqp_exception(__FUNCTION__,
      "no signature for: "+fqname.get_prefix()+':'+fqname.get_name());
  }
  return sig_h;
}
	
static_type_t context::get_document_type(
	string const& doc_uri) const
throw (xqp_exception)
{
  static_type_t t;
  if (!statically_known_documents.get(doc_uri,t)) {
    throw xqp_exception(__FUNCTION__,
      "no static document type for: "+doc_uri);
  }
  return t;
}
	
static_type_t context::get_collection_type(
	string const& col_uri) const
throw (xqp_exception)
{
  static_type_t t;
  if (!statically_known_collections.get(col_uri,t)) {
    throw xqp_exception(__FUNCTION__,
      "no static collection type for: "+col_uri);
  }
  return t;
}
	
rchandle<item_iterator> context::get_var_value(
	QName const& qname) const
throw (xqp_exception)
{
  return NULL;
}

rchandle<function_impl> context::get_function(
	signature const& sig) const
throw (xqp_exception)
{
  return NULL;
}

rchandle<item_iterator> context::get_document(
	string const& doc_uri) const
throw (xqp_exception)
{
  return NULL;
}

rchandle<item_iterator> context::get_collection(
	string const& col_uri) const
throw (xqp_exception)
{
  return NULL;
}

rchandle<item_iterator> context::get_default_collection() const
throw (xqp_exception)
{
  return NULL;
}


}	/* namespace xqp */
