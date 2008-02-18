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
#include "context/common.h"
#include "errors/error_factory.h"
#include "system/globalenv.h"
#include "context/static_context.h"
#include "system/zorba.h"
#include "util/utf8/Unicode_util.h"
#include "context/collation_manager.h"
#include "functions/library.h"
#include "system/zorba_engine.h"
#include "types/casting.h"
#include "functions/signature.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"

#include "zorba/functions/stateless_function.h"

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
  
  static_context::static_context()
		: context (root_static_context ()) {}
 
  static_context::static_context (static_context *_parent)
    : context (_parent) {}

  static_context* 
  static_context::root_static_context () {
    static static_context *p = new static_context (default_ns_initializers);
    return p;
  }
  
	///constructor called only for root static context
  static_context::static_context (const char **p) {
		//set up the implementation-default values in the root static context
		set_xpath1_0compatib_mode(StaticQueryContext::xpath2_0);
    for (; *p != NULL; p += 2)
      bind_ns (p [0], p [1]);
    set_default_elem_type_ns ("");		
    set_default_function_namespace (lookup_ns ("fn"));
		set_context_item_static_type(GENV_TYPESYSTEM.create_any_type());
    set_default_collation_uri ("http://www.w3.org/2005/xpath-functions/collation/codepoint");
		set_construction_mode(StaticQueryContext::cons_strip);
		set_ordering_mode(StaticQueryContext::ordered);
		set_order_empty_mode(StaticQueryContext::empty_greatest);
		set_boundary_space_mode(StaticQueryContext::strip_space);
		set_inherit_mode(StaticQueryContext::no_inherit_ns);
		set_preserve_mode(StaticQueryContext::no_preserve_ns);
//		set_order_empty_mode (StaticQueryContext::empty_least);
		set_default_collection_type(GENV_TYPESYSTEM.create_any_type());

    set_current_absolute_baseuri("");
  }

	static_context::~static_context()
	{
		//debug
		//test_obj.use_me();
		//end debug

		///free the pointers from ctx_value_t from keymap
		checked_vector<hashmap<ctx_value_t>::entry>::const_iterator		it;
		const char		*keybuff;
		const ctx_value_t *val;
		Zorba	*z = ZORBA_FOR_CURRENT_THREAD();

		//keybuff[sizeof(keybuff)-1] = 0;
		for(it = keymap.begin();it!=keymap.end();it++)
		{
			///it is an entry
			//keymap.getentryKey(*it, keybuff, sizeof(keybuff)-1);
			keybuff = (*it).key.c_str();
			if(!strncmp(keybuff, "type:", 5))
			{
				val = &(*it).val;
				val->typeValue->removeReference();
			}
			else if(!strncmp(keybuff, "collation:", 10))
			{
				val = &(*it).val;
				if(!val->collationValue->is_user_created)
				{
					if(z)
					{
						z->coll_manager->removeReference(val->collationValue->coll_string, val->collationValue->coll_strength);
					}
          delete val->collationValue;
				}
			}
		}
	}

  void static_context::init () {
  }
  
  DECL_ENUM_PARAM (static_context, construction_mode)
  DECL_ENUM_PARAM (static_context, order_empty_mode)
  DECL_ENUM_PARAM (static_context, boundary_space_mode)
  DECL_ENUM_PARAM (static_context, inherit_mode)
  DECL_ENUM_PARAM (static_context, preserve_mode)
  DECL_ENUM_PARAM (static_context, xpath1_0compatib_mode)
	DECL_ENUM_PARAM (static_context, ordering_mode)

//  DECL_STR_PARAM (static_context, baseuri)
//  DECL_STR_PARAM (static_context, default_collation)
  DECL_STR_PARAM (static_context, default_function_namespace, XQST0066)
  DECL_STR_PARAM (static_context, default_elem_type_ns, XQST0066)
  DECL_STR_PARAM (static_context, current_absolute_baseuri, MAX_ZORBA_ERROR_CODE)
  DECL_STR_PARAM (static_context, encapsulating_entity_baseuri, MAX_ZORBA_ERROR_CODE)
  DECL_STR_PARAM (static_context, entity_file_uri, MAX_ZORBA_ERROR_CODE)



  pair<xqp_string, xqp_string> parse_qname (xqp_string qname)
  {
		std::string::size_type n = static_cast<std::string> (qname).find (':');
    return (n == string::npos)
      ? pair<xqp_string, xqp_string> ("", qname)
      : pair<xqp_string, xqp_string> (qname.substr (0, n), qname.substr (n+1));
  }

xqp_string qname_internal_key2 (xqp_string ns, xqp_string local)
{
  return local + ":" + ns;
}


Item_t static_context::lookup_qname(
    xqp_string default_ns,
    xqp_string prefix,
    xqp_string local) const
{
  // Note: lookup_ns throws exception if there is no binding for the prefix.
  return ITEM_FACTORY.createQName((prefix.empty() ? default_ns : lookup_ns(prefix)),
                                  prefix,
                                  local);
}


Item_t static_context::lookup_qname (xqp_string default_ns, xqp_string qname) const
{
  pair<xqp_string, xqp_string> rqname = parse_qname (qname);
  return lookup_qname (default_ns, rqname.first, rqname.second);
}

  xqp_string static_context::qname_internal_key (const Item *qname) const
  {
    return qname_internal_key2 (qname->getNamespace (), qname->getLocalName ());
  }

  xqp_string static_context::qname_internal_key (xqp_string default_ns, xqp_string prefix, xqp_string local) const
  {
    return qname_internal_key2
      (prefix.empty () ? default_ns : lookup_ns (prefix), local);
  }

  xqp_string static_context::qname_internal_key (xqp_string default_ns, xqp_string qname) const
  {
    pair<xqp_string, xqp_string> rqname = parse_qname (qname);
    return qname_internal_key (default_ns, rqname.first, rqname.second);
  }

  xqp_string static_context::fn_internal_key (int arity) 
  {
    return "fn:" + to_string (arity) + "/";
  }

  function *static_context::lookup_fn (xqp_string prefix, xqp_string local, int arity) const {
    function *f = lookup_func (fn_internal_key (arity) + qname_internal_key (default_function_namespace (), prefix, local));
    if (f != NULL) return f;
    else {
      f = lookup_func (fn_internal_key (VARIADIC_SIG_SIZE) + qname_internal_key (default_function_namespace (), prefix, local));
      if (f == NULL)
        ZORBA_ERROR_ALERT (ZorbaError::XPST0017, NULL, DONT_CONTINUE_EXECUTION, local, to_string (arity));
      return f;
    }
  }

  xqp_string static_context::lookup_ns (xqp_string prefix) const
  {
    xqp_string ns;
    if(!context_value ("ns:" + prefix, ns) || ns.empty())
		{
			ZORBA_ERROR_ALERT(ZorbaError::XPST0081);
		}
    return ns;
  }

  void static_context::bind_ns (xqp_string prefix, xqp_string ns, enum ZorbaError::ErrorCodes err)
  {
    bind_str ("ns:" + prefix, ns, err);
  }

  function *static_context::lookup_builtin_fn (xqp_string local, int arity)
  {
    function *f = root_static_context ()->lookup_func (fn_internal_key (arity) + qname_internal_key2 (XQUERY_FN_NS, local));
    if (f == NULL)
      ZORBA_NOT_IMPLEMENTED ("built-in `" + local + "/" + to_string (arity) + "'");
    return f;
  }

	xqtref_t static_context::lookup_type( xqp_string key)
	{
    ctx_value_t val;
    Assert (context_value (key, val));
    return val.typeValue;
	}

	void	static_context::bind_type(xqp_string key, xqtref_t t)
	{
		ctx_value_t v;
    v.typeValue = &*t;
    keymap.put (key, v);
		t->addReference();///will be decremented in static context destructor
	}

	void static_context::add_variable_type(
		const xqp_string var_name, 
		xqtref_t var_type)
	{
		bind_type("type:var:" + qname_internal_key("", var_name), var_type);
	}

	xqtref_t	static_context::get_variable_type(
		Item *var_name)
	{
		return lookup_type( "type:var:" + qname_internal_key("", var_name->getPrefix(), var_name->getLocalName()));
	}

	void static_context::set_context_item_static_type(xqtref_t t)
	{
		bind_type("type:context:", t);
	}

	xqtref_t		static_context::context_item_static_type()
	{
		return lookup_type("type:context:");
	}

	void static_context::set_default_collection_type(xqtref_t t)
	{
		bind_type("type:defcollection:", t);
	}

	xqtref_t		static_context::default_collection_type()
	{
		return lookup_type("type:defcollection:");
	}

void static_context::set_function_type(const Item *qname, xqtref_t t)
{
	bind_type("type:fun:"+qname_internal_key( default_function_namespace(), qname->getPrefix(), qname->getLocalName()), t);
}

xqtref_t static_context::get_function_type(
	const Item_t qname) 
{
	// TODO
	//return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
	return lookup_type("type:fun:" + qname_internal_key( default_function_namespace(), qname->getPrefix(), qname->getLocalName()));
}

void static_context::set_document_type(xqp_string docURI, xqtref_t t)
{
	bind_type("type:doc:"+docURI, t);
}

xqtref_t static_context::get_document_type(
	const xqp_string docURI) 
{
	// TODO
//	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
	return lookup_type("type:doc:" + docURI);

}

void static_context::set_collection_type(xqp_string collURI, xqtref_t t)
{
	bind_type("type:collection:"+collURI, t);
}

xqtref_t static_context::get_collection_type(
	const xqp_string collURI) 
{
	// TODO
//	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
	return lookup_type("type:collection:" + collURI);
}

void static_context::add_collation(xqp_string collation_uri, 
										std::string  coll_string, 
										::Collator::ECollationStrength coll_strength,
										::Collator *coll,
										bool is_user_created)
{
	COLLATION_OBJ	*cobj;

	cobj = new COLLATION_OBJ;
	cobj->coll_uri = collation_uri;
	cobj->coll_string = coll_string;
	cobj->coll_strength = coll_strength;
	cobj->is_user_created = is_user_created;
	cobj->coll = coll;

	bind_collation(collation_uri, cobj);
}

xqp_string static_context::default_collation_uri() const
{
	xqp_string		def_uri;
	lookup_once("def_collation_uri:", def_uri);
	return def_uri;
}

void static_context::set_default_collation_uri(xqp_string def_uri)
{
	if(!CollationManager::getHardcodedCollator(def_uri) &&
		!lookup_collation(def_uri))
	{
		ZORBA_ERROR_ALERT(ZorbaError::XQST0038);
	}
	bind_str("def_collation_uri:", def_uri, ZorbaError::XQST0038);
}

context::COLLATION_OBJ	*static_context::lookup_collation(xqp_string coll_uri)
{
	xqp_string key;
  ctx_value_t val;

	key = "collation:" + coll_uri;
  if(context_value (key, val))
		return val.collationValue;
	else
		return NULL;
}

void		static_context::bind_collation(xqp_string coll_uri, context::COLLATION_OBJ* cinfo)
{
	xqp_string key;
  ctx_value_t v;

	key = "collation:" + coll_uri;
  v.collationValue = cinfo;
  keymap.put (key, v);
}

::Collator *static_context::get_collation(xqp_string collURI, bool error_if_not_found)
{
	///first search in fxhash
	COLLATION_OBJ*		cinfo;

	cinfo = lookup_collation( collURI );
	if(!cinfo)
	{
		const CollationManager::COLLATION_DESCR	*def_coll;

		def_coll = CollationManager::getHardcodedCollator(collURI);
		if(!def_coll)
		{
			if(error_if_not_found)
			{
				//static context component missing
				ZORBA_ERROR_ALERT( ZorbaError::XPST0001, NULL, CONTINUE_EXECUTION, "collation " + collURI);  //continue execution
			}
			return NULL;///collation non-existant
		}

		::Collator *coll = ZORBA_FOR_CURRENT_THREAD()->coll_manager->getCollation(def_coll->coll_string, def_coll->coll_strength);
		if(!coll)
		{
		//	ZORBA_ERROR_ALERT(
		//			ZorbaError::XQST0076_STATIC_UNRECOGNIZED_COLLATION,
		//			ZorbaError::STATIC_ERROR,
		//			NULL
		//		);
			return NULL;///collation non-existant
		}
		cinfo = new COLLATION_OBJ;
		cinfo->coll_uri = collURI;
		cinfo->coll_string = def_coll->coll_string;
		cinfo->coll_strength = def_coll->coll_strength;
		cinfo->coll = coll;
		cinfo->is_user_created = false;
		bind_collation(collURI, cinfo);
	}
	else if(!cinfo->coll)
	{
		cinfo->coll = ZORBA_FOR_CURRENT_THREAD()->coll_manager->getCollation(cinfo->coll_string, cinfo->coll_strength);
		if(!cinfo->coll)
		{
		//	ZORBA_ERROR_ALERT(
		//			ZorbaError::XQST0076_STATIC_UNRECOGNIZED_COLLATION,
		//			ZorbaError::STATIC_ERROR,
		//			NULL
		//		);
			return NULL;///collation non-existant
		}
		cinfo->is_user_created = false;
	}

	return cinfo->coll;
}

::Collator *static_context::getDefaultCollation()
{
	xqp_string		def_coll_uri;
	::Collator		*coll;

	///look if the default collator is already in static context hash
	///if not, then try to create it

	def_coll_uri = default_collation_uri();

	coll = get_collation( def_coll_uri, false );
	if(coll)
	{
		return coll;
	}
	else if(!def_coll_uri.empty())
	{
		//error, uri not found
		//ZORBA_ERROR_ALERT( ZorbaError::XQST0076, NULL);//only for FLWOR
		return NULL;///collation non-existant
	}

	///else create it with root/::Collator::PRIMARY

	coll = ZORBA_FOR_CURRENT_THREAD()->coll_manager->getCollation(
																													"root", ::Collator::PRIMARY);
	if(!coll)
	{
	//	ZORBA_ERROR_ALERT(
	//			ZorbaError::XQST0076_STATIC_UNRECOGNIZED_COLLATION,
	//			ZorbaError::STATIC_ERROR,
	//			NULL
	//		);
		return NULL;///collation non-existant
	}
	COLLATION_OBJ*		cinfo;
	cinfo = new COLLATION_OBJ;
	cinfo->coll_uri = "";
	cinfo->coll_string = "root";
	cinfo->coll_strength = ::Collator::PRIMARY;
	cinfo->coll = coll;
	cinfo->is_user_created = false;
	bind_collation("", cinfo);

	return coll;
}

/*
  DECL_STR_PARAM (static_context, current_absolute_baseuri)
  DECL_STR_PARAM (static_context, encapsulating_entity_baseuri)
  DECL_STR_PARAM (static_context, entity_file_uri)
*/
xqp_string static_context::baseuri () const 
{
  xqp_string val;                                        
  if(!context_value ("int:" "from_prolog_baseuri", val))  // if not found val remains ""
  {
    context_value("int:" "baseuri", val);
  }
  return val;
}

void static_context::set_baseuri (xqp_string val, bool from_prolog) 
{
	if (from_prolog)
    bind_str ("int:" "from_prolog_baseuri", val, ZorbaError::XQST0032);
  else
    str_keymap.put ("int:" "baseuri", val);
}

void static_context::compute_current_absolute_baseuri()
{
	//if base Uri is present, compute absolute base Uri
	//else if encapsulating_entity_baseuri is present, use that
	//else if entity_file_uri is present, use that
	//else do not set the absolute baseuri (and hope there are no relative uris)

	xqp_string		prolog_baseuri;
	xqp_string		ee_baseuri;
	xqp_string		loaded_uri;

	prolog_baseuri = baseuri();
	if(((std::string)prolog_baseuri).find("://") != std::string::npos)
	{
		//is already absolute baseuri
		set_current_absolute_baseuri(prolog_baseuri);
		return;
	}
	else if(!prolog_baseuri.empty())
	{
		///is relative, needs to be resolved
		ee_baseuri = encapsulating_entity_baseuri();
		if(!ee_baseuri.empty())
		{
			set_current_absolute_baseuri(make_absolute_uri(prolog_baseuri, ee_baseuri));
			return;
		}
		loaded_uri = entity_file_uri();
		if(!loaded_uri.empty())
		{
			set_current_absolute_baseuri(make_absolute_uri(prolog_baseuri, loaded_uri));
			return;
		}

	//	set_current_absolute_baseuri("");
		return;
	}

	ee_baseuri = encapsulating_entity_baseuri();
	if(!ee_baseuri.empty())
	{
		set_current_absolute_baseuri(ee_baseuri);
		return;
	}
	loaded_uri = entity_file_uri();
	if(!loaded_uri.empty())
	{
		set_current_absolute_baseuri(loaded_uri);
		return;
	}
//	set_current_absolute_baseuri("");
}

xqp_string static_context::make_absolute_uri(xqp_string uri, xqp_string base_uri)
{
	xqp_string		abs_uri;

//	assert(false);//not implemented

	abs_uri = base_uri;
//	"./../relativ/rel.exe"
//	"http://gfd/sdf/gsd/sdfg/gfds/sdfg/fgds/"

	if(!abs_uri.endsWith("/") && !abs_uri.endsWith("\\"))
	{
    abs_uri += "/";
	}
  while(!uri.empty())
  {
    if((uri.indexOf("/") == 0) || (uri.indexOf("\\") == 0))
    {
      uri = uri.substr(1);//skip one char
      continue;
    }
    if(uri.indexOf(".") == 0)
    {
      xqp_string  tempuri;
      tempuri = uri.substr(1);
      if((tempuri.indexOf("/") == 0) || (tempuri.indexOf("\\") == 0))
      {
        uri = uri.substr(2);//skip two chars
        continue;
      }
      else if(tempuri.indexOf(".") == 0)
      {
        if((tempuri.indexOf("/") != 1) && (tempuri.indexOf("\\") != 1))
        {
          ZORBA_ERROR_ALERT_OSS(ZorbaError::XQP0020_INVALID_URI, NULL, DONT_CONTINUE_EXECUTION,
                      base_uri << " + " << uri, "");
          return "";
        }
        xqp_string    tempabs;
        tempabs = abs_uri.substr(0, abs_uri.length()-1);
        int32_t   last_slash;
        int32_t   last_backslash;
        last_slash = tempabs.lastIndexOf("/");
        last_backslash = tempabs.lastIndexOf("\\");
        if(last_slash < last_backslash)
          last_slash = last_backslash;
        
        if(last_slash < 0)
        {
          ZORBA_ERROR_ALERT_OSS(ZorbaError::XQP0020_INVALID_URI, NULL, DONT_CONTINUE_EXECUTION,
                      base_uri << " + " << uri, "");
          return "";
        }
        abs_uri = abs_uri.substr(0, last_slash+1);

        uri = uri.substr(3);
        continue;
      }
    }

    int32_t   first_slash;
    int32_t   first_backslash;
    first_slash = uri.indexOf("/");
    first_backslash = uri.indexOf("\\");
    if((first_slash < 0) || 
      (first_slash > first_backslash) && (first_backslash >= 0))
      first_slash = first_backslash;
    if(first_slash < 0)
      first_slash = uri.length();
    else
      first_slash++;//jump over slash
    
    abs_uri += uri.substr(0,first_slash);
    uri = uri.substr(first_slash);
  }

	if(!GenericCast::instance()->isCastable(abs_uri, GENV_TYPESYSTEM.ANY_URI_TYPE_ONE))
  {
    ZORBA_ERROR_ALERT_OSS(ZorbaError::XQP0020_INVALID_URI, NULL, DONT_CONTINUE_EXECUTION,
                base_uri << " + " << uri, "");
    return "";
  }

	return abs_uri;
}

xqp_string		static_context::resolve_relative_uri( xqp_string uri )
{
	///check if it is an absolute URI
	if(((std::string)uri).find("://") != std::string::npos)
		return uri;
	
	xqp_string		abs_base_uri;
	abs_base_uri = current_absolute_baseuri();

	if(abs_base_uri.empty())
		compute_current_absolute_baseuri();

	///try again
	abs_base_uri = current_absolute_baseuri();

	if(abs_base_uri.empty())
	{
		//then error ! cannot resolve relative uri
		ZORBA_ERROR_ALERT(ZorbaError::XPST0001, NULL, DONT_CONTINUE_EXECUTION, "empty base URI");
		return "";
	}

	return make_absolute_uri(uri, abs_base_uri);
}

void 
static_context::bind_stateless_external_function(StatelessExternalFunction_t& aExternalFunction) {
  m_stateless_ext_functions.put(aExternalFunction->getLocalName() +":" +aExternalFunction->getURI(),
                                aExternalFunction);
}

StatelessExternalFunction *
static_context::lookup_stateless_external_function(xqp_string aPrefix, xqp_string aLocalName)
{
  StatelessExternalFunction_t lExtFun;
  return  m_stateless_ext_functions.get(
                 qname_internal_key(default_function_namespace(), aPrefix, aLocalName), lExtFun) 
                 ? lExtFun.getp() : NULL;
}

}	/* namespace xqp */

