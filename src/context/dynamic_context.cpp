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
 * @file context/dynamic_context.cpp
 *
 */

#include <assert.h>
#include <time.h>
#include <zorba/iterator.h>

#include "system/globalenv.h"
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "system/zorba.h"
#include "types/root_typemanager.h"
#include "store/api/item_factory.h"

using namespace std;
namespace zorba {

bool dynamic_context::static_init = false;

void dynamic_context::init()
{
	if (!dynamic_context::static_init) {
		dynamic_context::static_init = true;
	}
}


dynamic_context::dynamic_context(dynamic_context *parent)
{
	this->parent = parent;
	if(!parent)
	{
		time_t		t0 = time(NULL);
#if defined (WIN32)
		struct	::tm	gmtm;
		//gmtime_s(&gmtm, &t0);//thread safe gmtime on Windows
    localtime_s(&gmtm, &t0);//thread safe localtime on Windows
#else
		struct	::tm	gmtm;
		//gmtime_r(&t0, &gmtm);//thread safe gmtime on Linux
    localtime_r(&t0, &gmtm);//thread safe localtime on Linux
#endif

		//execution_date_time = gmtm;
		tzset();
    //execution_timezone_seconds = _timezone;//global var set by _tzset in C runtime
    set_execution_date_time(gmtm, -timezone);
    
		implicit_timezone = 0;

		ctxt_position = 0;
	}
	else
	{
		execution_date_time_item = parent->execution_date_time_item;
		execution_timezone_seconds = parent->execution_timezone_seconds;
		implicit_timezone = parent->implicit_timezone;
		default_collection_uri = parent->default_collection_uri;

		ctxt_item = parent->ctxt_item;
		ctxt_position = parent->ctxt_position;
	}
}

dynamic_context::~dynamic_context()
{
	///free the pointers from ctx_value_t from keymap
	checked_vector<hashmap<dctx_value_t>::entry>::const_iterator it;
	const char		*keybuff;//[50];
	const dctx_value_t* val;

	for(it = keymap.begin(); it != keymap.end(); it++)
	{
		///it is an entry
		//keymap.getentryKey(*it, keybuff, sizeof(keybuff)-1);
		keybuff = (*it).key.c_str();
		if(!strncmp(keybuff, "var:", 4))
		{
			val = &(*it).val;
			val->var_iterator->removeReference(val->var_iterator->getSharedRefCounter()
                                         SYNC_PARAM2(val->var_iterator->getRCLock()));
		}
	}
}


xqp_string dynamic_context::expand_varname(static_context	*sctx, xqp_string qname) const
{
  pair<xqp_string, xqp_string> rqname = parse_qname (qname);
	if(!rqname.first.empty())
	{
		if(!sctx)
		{
			///actually the whole static context is missing
			ZORBA_ERROR_ALERT(ZorbaError::XPST0001, NULL, DONT_CONTINUE_EXECUTION, "entire static context");
			return (const char*)NULL;
		}
		return rqname.second + ":" + sctx->lookup_ns(rqname.first);
	}
  return rqname.second;
	
}


/*______________________________________________________________________
|  
|	XQuery 1.0 context
|	[http://www.w3.org/TR/xquery/#id-xq-context-components]
|_______________________________________________________________________*/
/*
pair<xqp_string, xqp_string> parse_qname (xqp_string qname);
xqp_string qname_internal_key2 (xqp_string ns, xqp_string local);

xqp_string dynamic_context::qname_internal_key (QNameItem_t qname) const {
  return qname_internal_key2 (qname->getNamespace (), qname->getLocalName ());
}
xqp_string dynamic_context::qname_internal_key (xqp_string default_ns, xqp_string prefix, xqp_string local) const {
  return qname_internal_key2
    (prefix.empty () ? default_ns : sctx->lookup_ns (prefix), local);
}
xqp_string dynamic_context::qname_internal_key (xqp_string default_ns, xqp_string qname) const {
  pair<xqp_string, xqp_string> rqname = parse_qname (qname);
  return qname_internal_key (default_ns, rqname.first, rqname.second);
}
*/

void dynamic_context::set_context_item(store::Item_t context_item, unsigned long position)
{
	this->ctxt_item = context_item;
	this->ctxt_position = position;
}

store::Item_t dynamic_context::context_item() const 
{
	return ctxt_item;
}

unsigned long dynamic_context::context_position()
{
	return ctxt_position;
}

xqtref_t dynamic_context::context_item_type() const
{
	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}

//daniel DECL_ENUM_PARAM (dynamic_context, ordering_mode)

void dynamic_context::set_context_item_type(
	xqtref_t v)
{
}

void	dynamic_context::set_execution_date_time(struct ::tm datetime_value, long tz_seconds)
{
//	this->execution_date_time = t;
	store::ItemFactory* item_factory = Zorba::getItemFactory();
	this->execution_timezone_seconds = tz_seconds + datetime_value.tm_isdst ? 1 : 0;
	execution_date_time_item = 
    item_factory->createDateTime(
					datetime_value.tm_year+1900, datetime_value.tm_mon, datetime_value.tm_mday,
					datetime_value.tm_hour, datetime_value.tm_min, datetime_value.tm_sec,
					(short)execution_timezone_seconds/60/60);
}

store::Item_t	dynamic_context::get_execution_date_time()
{
	return execution_date_time_item;
}

void  dynamic_context::set_implicit_timezone(long tzone_seconds)
{
	this->implicit_timezone = tzone_seconds;
}

long  dynamic_context::get_implicit_timezone()
{
#if 0
  // If this is to be taken from the dynamic ctx, it kills optimization
  // (const folding) as datetime code calls this from all over the place.
  return implicit_timezone;
#else
	return 0;
#endif
}

/*
var_name is expanded name localname:nsURI
constructed by static_context::qname_internal_key( .. )
*/
void	dynamic_context::add_variable(xqp_string var_name, Iterator* var_iterator)
{
  var_iterator->addReference(var_iterator->getSharedRefCounter()
                             SYNC_PARAM2(var_iterator->getRCLock()));

  dctx_value_t v = { var_iterator };
  keymap.put ("var:" + var_name, v);
}

Iterator_t	dynamic_context::get_variable(xqp_string var_name)
{
	return lookup_var_iter("var:" + var_name);
}


Iterator* dynamic_context::lookup_var_iter(xqp_string key) const
{ 
	dctx_value_t val;

	if(!keymap.get (key, val))
	{
		if(parent)
			return parent->lookup_var_iter(key);
		else
			return NULL;///variable not found
	}
	return val.var_iterator;
}


xqp_string dynamic_context::get_default_collection()
{
	return default_collection_uri;
}

void dynamic_context::set_default_collection(xqp_string default_collection_uri)
{
	this->default_collection_uri = default_collection_uri;
}


}	/* namespace zorba */

