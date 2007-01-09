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

#include "namespace.h"
#include "../datamodel/qname.h"
#include "../datamodel/collation.h"
#include "../util/hashmap.h"
#include "../util/rchandle.h"
#include "../util/URI.h"
#include "../util/xqp_exception.h"
#include "../values/values.h"

using namespace std;
namespace xqp {

  
///////////////////////////////
//  var_binding
///////////////////////////////

var_binding::var_binding()
:
  qid(),
  vartype(item_type())
{
}

var_binding::var_binding(
	rchandle<QName> qname_h,
	item_type const& t)
:
	qid(qnameid::put_qname(qname_h)),
	vartype(t)
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
	
item_type context::get_document_type(
	string const& doc_uri) const
throw (xqp_exception)
{
  item_type t;
  if (!statically_known_documents.get(doc_uri,t)) {
    throw xqp_exception(__FUNCTION__,
      "no static document type for: "+doc_uri);
  }
  return t;
}
	
item_type context::get_collection_type(
	string const& col_uri) const
throw (xqp_exception)
{
  item_type t;
  if (!statically_known_collections.get(col_uri,t)) {
    throw xqp_exception(__FUNCTION__,
      "no static collection type for: "+col_uri);
  }
  return t;
}
	
item_iterator context::get_var_value(
	QName const& qname) const
throw (xqp_exception)
{
  return empty_sequence();
}

function_impl const* context::get_function(
	signature const& sig) const
throw (xqp_exception)
{
	return NULL;
}

item_iterator context::get_document(
	string const& doc_uri) const
throw (xqp_exception)
{
  return empty_sequence();
}

item_iterator context::get_collection(
	string const& col_uri) const
throw (xqp_exception)
{
  return empty_sequence();
}

item_iterator context::get_default_collection() const
throw (xqp_exception)
{
  return empty_sequence();
}


}	/* namespace xqp */
