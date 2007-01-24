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

#include "../runtime/item_iterator.h"
#include "../util/rchandle.h"
#include "../util/xqp_exception.h"
#include "../values/values.h"

using namespace std;
namespace xqp {

#define EMPTY_SEQUENCE(X) item_iterator((X))
  

///////////////////////////////
//  var_binding
///////////////////////////////

var_binding::var_binding()
:
  name_h(NULL),
	value_h(NULL),
  type(item_type())
{
}

var_binding::var_binding(
	var_binding &  v)
:
  name_h(v.name_h),
	value_h(v.value_h),
  type(v.type)
{
}

var_binding::var_binding(
	var_binding const&  v)
:
  name_h(v.name_h),
  value_h(v.value_h),
  type(v.type)
{
}

var_binding::var_binding(
	rchandle<QName> _name_h,
	rchandle<item_iterator> _value_h,
	item_type const& _type)
:
	name_h(_name_h),
	value_h(_value_h),
	type(_type)
{
}



///////////////////////////////
//  context
///////////////////////////////

context::context()
:
	parent_h(NULL),

/*
	namespaces(),
	in_scope_schema_types(1024),
	in_scope_elem_decls(1024),
	in_scope_attr_decls(1024),
	in_scope_vars(1024),
	collations(1024),
	statically_known_collection_types(32,0.6),
*/

	signature_map(256,0.6),
	statically_known_documents(256,0.6),
	statically_known_collections(64,0.6),

	context_item(*this),
	context_position(0),
	context_size(0),
	var_values(1024,0.6),
	function_implementations(1024,0.6),
	timezone(-8),
	available_documents(1024,0.6),
	available_collections(1024,0.6),
	default_collection("defcol")
{
}

context::~context()
{
}


void context::push_var(
	rchandle<var_binding> vb_h)
{
	varstackref_t s_p;
	string varname = vb_h->get_qname()->describe(*this);
	if (!var_values.get(varname, s_p)) {
		s_p = new stack<varref_t>;
		var_values.put(varname, s_p);
	}
	s_p->push(vb_h);
}

rchandle<item_iterator> context::get_var_value(
	rchandle<QName> vqn_h) const
throw (xqp_exception)
{
	varstackref_t s_p;
	string varname = vqn_h->describe(*this);
	if (!var_values.get(varname, s_p)) {
  	throw bad_arg(__FUNCTION__,"variable not found");
	}
	else {
		varref_t v_h = s_p->top();
		return v_h->get_value();
	}
}

string context::get_function_type(
  QName const& fqname, 
  uint32_t arity) const 
throw (xqp_exception)
{
  ostringstream oss;
  fqname.put(oss,*this) << '[' << arity << ']';
  string sig_h;
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
  return EMPTY_SEQUENCE(*this);
}

item_iterator context::get_collection(
	string const& col_uri) const
throw (xqp_exception)
{
  return EMPTY_SEQUENCE(*this);
}

item_iterator context::get_default_collection() const
throw (xqp_exception)
{
  return EMPTY_SEQUENCE(*this);
}


}	/* namespace xqp */
