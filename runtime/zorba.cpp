/** -*- mode: c++; indent-tabs-mode: nil -*-
 *
 *  $Id: context.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */

#include "zorba.h"

//#include "../runtime/item_iterator.h"
//#include "../store/store.h"
#include "../context/dynamic_context.h"
#include "../context/static_context.h"
#include "../types/sequence_type.h"
#include "../util/hashfun.h"
#include "../util/tracer.h"
#include "../util/xqp_exception.h"
#include "../values/values.h"
//#include "../zorba/value_factory.h"

#include <stdlib.h>
#include <sstream>
#include <string>


using namespace std;
namespace xqp {


zorba::zorba(
	rchandle<store> _store_h,
	rchandle<value_factory> _vfactory_h)
:
	store_h(_store_h),
	vfactory_h(_vfactory_h),
	static_context_h(new static_context(&*vfactory_h)),
	dynamic_context_h(new dynamic_context(&*vfactory_h)),

	ctx_itemid(0),
	ctx_docid(0),
	ctx_docref(0),

	counters("data/itemid",256),
	nskeymap("data/nskeymap", 0.6f, 6),
	urimap("data/urimap", 0.6f, 6),
	docindex("data/docindex", 0.6f, 6)
{
	//addns("xml","http://www.w3.org/XML/1998/namespace");
	//addns("xmlns","http://www.w3.org/2000/xmlns/");
	//addns("xh","http://www.w3.org/1999/xhtml/");
}


qname* zorba::get_qname(itemid_t id) const { return NULL; }

uint32_t zorba::next_docid() { return (++counters[docid_counter]); }
uint32_t zorba::next_itemid() { return (++counters[itemid_counter]); }
uint32_t zorba::gen() { return (counters[gen_counter]); }
uint32_t zorba::next_gen() { return (++counters[gen_counter]); }

bool zorba::put_dnid( urikey_t uri, itemid_t dnid)
	{ return docindex.put(uri, dnid); }
bool zorba::get_dnid( urikey_t uri, itemid_t & dnid) const
	{ return docindex.get(uri, dnid); }

bool zorba::get_nskey( const string& prefix, nskey_t& key) const
	{ return nskeymap.get(prefix,key); }
bool zorba::put_nskey( const string& prefix, nskey_t key) 
	{ return nskeymap.put(prefix,key); }
bool zorba::get_uri( const string& prefix, string& uri) const
	{ return urimap.get(prefix,uri); }
bool zorba::put_uri( const string& prefix, const string& uri) 
	{ return urimap.put(prefix,uri); }

bool zorba::addns( const string& prefix, const string& uri)
{
	if (!urimap.put(prefix,uri)) return false;
	return nskeymap.put(prefix,hashfun::h64(uri));
}

/*
sequence_type_t zorba::get_function_type(
	const qname* fname_p) const throw (xqp_exception)
{ return xs_untypedValue; }
	
function const* zorba::get_function(
	const qname*) const throw (xqp_exception)
{ return NULL; }
*/

sequence_type_t zorba::get_document_type(
	const string& doc_uri) const throw (xqp_exception)
{ return xs_untypedValue; }
	
rchandle<item_iterator> zorba::get_document(
	const string& doc_uri) const throw (xqp_exception)
{ return NULL; }

sequence_type_t zorba::get_collection_type(
	const string& col_uri) const throw (xqp_exception)
{ return xs_untypedValue; }
	
rchandle<item_iterator> zorba::get_collection(
	const string& col_uri) const throw (xqp_exception)
{ return NULL; }

rchandle<item_iterator> zorba::get_default_collection(
	) const throw (xqp_exception)
{ return NULL; }


}	/* namespace xqp */

