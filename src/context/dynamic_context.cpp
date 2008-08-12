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
#include "common/common.h"
#include <assert.h>
#include <time.h>

#include "store/api/iterator.h"
#include "store/api/temp_seq.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "system/globalenv.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "compiler/expression/var_expr.h"

#include "types/root_typemanager.h"

#include "runtime/api/plan_wrapper.h"

#include "zorbatypes/Unicode_util.h"

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
    // set the current time 
		time_t		t0 = time(NULL);
#if defined (WIN32)
		struct	::tm	gmtm;
    localtime_s(&gmtm, &t0); //thread safe localtime on Windows
#else
		struct	::tm	gmtm;
    localtime_r(&t0, &gmtm); //thread safe localtime on Linux
#endif

		implicit_timezone = 0;

    GENV_ITEMFACTORY->createDateTime(current_date_time_item, gmtm.tm_year + 1900, gmtm.tm_mon + 1, gmtm.tm_mday, 
                                                              gmtm.tm_hour, gmtm.tm_min, gmtm.tm_sec, implicit_timezone);
    
		ctxt_position = 0;
	}
	else
	{
		current_date_time_item = parent->current_date_time_item;
		implicit_timezone = parent->implicit_timezone;
		default_collection_uri = parent->default_collection_uri;

		ctxt_item = parent->ctxt_item;
		ctxt_position = parent->ctxt_position;
	}
}

void dynamic_context::destroy_dctx_value (const dctx_value_t* val) {
  switch (val->type) {
  case dynamic_context::dctx_value_t::no_val:
    break;
  case dynamic_context::dctx_value_t::var_iterator_val:
    RCHelper::removeReference (val->val.var_iterator);
    break;
  case dynamic_context::dctx_value_t::temp_seq_val:
    RCHelper::removeReference (val->val.temp_seq);
    break;
  default:
    ZORBA_ASSERT (false);
  }
}

dynamic_context::~dynamic_context()
{
	///free the pointers from ctx_value_t from keymap
	checked_vector<hashmap<dctx_value_t>::entry>::const_iterator it;
	const char		*keybuff;//[50];

	for(it = keymap.begin(); it != keymap.end(); it++)
	{
		///it is an entry
		keybuff = (*it).key.c_str();
		if(strncmp(keybuff, "var:", 4) == 0)
		{
			destroy_dctx_value (&(*it).val);
		}
	}
}


string dynamic_context::var_key (const void *var) {
  if (var == NULL) return "";
  const var_expr *ve = static_cast<const var_expr *> (var);
  return xqpString::concat(to_string(var), ":", ve->get_varname ()->getStringValue ());
}

xqp_string dynamic_context::expand_varname(static_context	*sctx, xqp_string qname) const
{
  if(!sctx) {
    ///actually the whole static context is missing
    ZORBA_ERROR_PARAM( XPST0001, "entire static context", "");
			return (const char*)NULL;
  }
  void *var = static_cast<void *> (sctx->lookup_var (qname));
  return var_key (var);
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

void dynamic_context::set_context_item_type(
	xqtref_t v)
{
}

void	dynamic_context::set_current_date_time( const store::Item_t& aDateTimeItem )
{
  this->current_date_time_item = aDateTimeItem;
}

store::Item_t	dynamic_context::get_current_date_time()
{
	return current_date_time_item;
}

void  dynamic_context::set_implicit_timezone(int tzone_seconds)
{
	this->implicit_timezone = tzone_seconds;
}

int  dynamic_context::get_implicit_timezone()
{
  return implicit_timezone;
}

/*
var_name is expanded name localname:nsURI
constructed by static_context::qname_internal_key( .. )
*/
void dynamic_context::add_variable(xqp_string var_name, store::Iterator_t var_iterator)
{
  if (var_name.empty()) return;

  // TODO: lazy conversion to a temp sequence
  dctx_value_t v;
  string key = "var:" + var_name;
  if (keymap.get (key, v))
    destroy_dctx_value (&v);

  v.type = dynamic_context::dctx_value_t::no_val;
  v.in_progress = true;
  keymap.put (key, v);

  var_iterator->open ();
  store::TempSeq_t seq = GENV_STORE.createTempSeq (var_iterator.getp());
  var_iterator->close ();
  RCHelper::addReference (seq);
  v.type = dynamic_context::dctx_value_t::temp_seq_val;
  v.in_progress = false;
  v.val.temp_seq = seq.getp();
  keymap.put (key, v);
}


store::Iterator_t	dynamic_context::get_variable(store::Item_t varname) {
	return lookup_var_iter("var:" + xqp_string (&*varname->getStringValue ()));
}


store::Iterator_t dynamic_context::lookup_var_iter(xqp_string key) { 
    dctx_value_t val = {dctx_value_t::no_val, false, {0} };

  if(!keymap.get (key, val))
	{
    if(parent)
      return parent->lookup_var_iter(key);
    else
      return NULL;///variable not found
	}
  if (val.in_progress)
    ZORBA_ERROR (XQST0054);
  assert (val.type == dynamic_context::dctx_value_t::temp_seq_val);
  return val.val.temp_seq->getIterator ();
}


store::Item_t
dynamic_context::get_default_collection()
{
	return default_collection_uri;
}

void dynamic_context::set_default_collection(const store::Item_t& default_collection_uri)
{
	this->default_collection_uri = default_collection_uri;
}


}	/* namespace zorba */

