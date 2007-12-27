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

#include "system/globalenv.h"
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include <assert.h>

using namespace std;
namespace xqp {

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
		execution_date_time = 0;
		implicit_timezone = 0;
	}
	else
	{
		execution_date_time = parent->execution_date_time;
		implicit_timezone = parent->implicit_timezone;
		default_collection_uri = parent->default_collection_uri;
	}
}

dynamic_context::~dynamic_context()
{
	///free the pointers from ctx_value_t from keymap
	fxvector<fxhashmap<dctx_value_t>::entry>::const_iterator		it;
	char		keybuff[50];
	const dctx_value_t *val;
//	zorba	*z = zorba::getZorbaForCurrentThread();

	keybuff[sizeof(keybuff)-1] = 0;
	for(it = keymap.begin();it!=keymap.end();it++)
	{
		///it is an entry
		keymap.getentryKey(*it, keybuff, sizeof(keybuff)-1);
		if(!strncmp(keybuff, "var:", 4))
		{
			val = &(*it).val;
			val->var_iterator->removeReference();
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
			ZORBA_ERROR_ALERT(AlertCodes::XPST0001);
			return NULL;
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
Iterator* dynamic_context::lookup_var_iter (xqp_string key ) const
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

void dynamic_context::bind_var_iter (xqp_string key, Iterator *it) {
  dctx_value_t v = { it };
	it->addReference();
  keymap.put (key, v);
}


TypeSystem::xqtref_t dynamic_context::context_item_type() const
{
	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}

//daniel DECL_ENUM_PARAM (dynamic_context, ordering_mode)

void dynamic_context::set_context_item_type(
	TypeSystem::xqtref_t v)
{
}

void	dynamic_context::set_execution_date_time(time_t t)
{
	this->execution_date_time = t;
}

time_t	dynamic_context::get_execution_date_time()
{
	if(execution_date_time == 0)
		if(parent)
			return parent->get_execution_date_time();
		else
			return 0;
	else
		return execution_date_time;
}

void	dynamic_context::set_implicit_timezone(int tzone)
{
	this->implicit_timezone = tzone;
}

int	dynamic_context::get_implicit_timezone()
{
	if(implicit_timezone == 0)
		if(parent)
			return parent->get_implicit_timezone();
		else
			return 0;
	else
		return implicit_timezone;
}

/*
var_name is expanded name localname:nsURI
constructed by static_context::qname_internal_key( .. )
*/
void	dynamic_context::add_variable(xqp_string var_name, Iterator_t var_iterator)
{
	var_iterator->addReference();
	bind_var_iter("var:" + var_name, var_iterator.get_ptr());
}

Iterator_t	dynamic_context::get_variable(xqp_string var_name)
{
	return lookup_var_iter("var:" + var_name);
}

xqp_string dynamic_context::get_default_collection()
{
	return default_collection_uri;
}

void dynamic_context::set_default_collection(xqp_string default_collection_uri)
{
	this->default_collection_uri = default_collection_uri;
}


}	/* namespace xqp */

