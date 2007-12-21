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
#include "util/utf8/Unicode_util.h"
#include "context/collation_manager.h"
#include "functions/library.h"

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
    set_default_collation_uri ("");
		set_construction_mode(StaticQueryContext::cons_strip);
		set_ordering_mode(StaticQueryContext::ordered);
		set_order_empty_mode(StaticQueryContext::empty_greatest);
		set_boundary_space_mode(StaticQueryContext::preserve_space);
		set_inherit_mode(StaticQueryContext::no_inherit_ns);
		set_preserve_mode(StaticQueryContext::no_preserve_ns);
		set_order_empty_mode (StaticQueryContext::empty_least);
		set_default_collection_type(GENV_TYPESYSTEM.create_any_type());
  }

	static_context::~static_context()
	{
		//debug
		//test_obj.use_me();
		//end debug

		///free the pointers from ctx_value_t from keymap
		fxvector<fxhashmap<ctx_value_t>::entry>::const_iterator		it;
		char		keybuff[50];
		const ctx_value_t *val;
		zorba	*z = zorba::getZorbaForCurrentThread();

		keybuff[sizeof(keybuff)-1] = 0;
		for(it = keymap.begin();it!=keymap.end();it++)
		{
			///it is an entry
			keymap.getentryKey(*it, keybuff, sizeof(keybuff)-1);
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
						z->coll_manager->removeReference(
																					val->collationValue->coll_string,
																					val->collationValue->coll_strength);
					}
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
  DECL_STR_PARAM (static_context, default_function_namespace)
  DECL_STR_PARAM (static_context, default_elem_type_ns)
  DECL_STR_PARAM (static_context, current_absolute_baseuri)
  DECL_STR_PARAM (static_context, encapsulating_entity_baseuri)
  DECL_STR_PARAM (static_context, entity_file_uri)



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

  QNameItem_t static_context::lookup_qname (xqp_string default_ns, xqp_string prefix, xqp_string local) const
  {
    return ITEM_FACTORY.createQName ((prefix.empty () ? default_ns : lookup_ns (prefix)), prefix, local);
  }

  QNameItem_t static_context::lookup_qname (xqp_string default_ns, xqp_string qname) const
  {
    pair<xqp_string, xqp_string> rqname = parse_qname (qname);
    return lookup_qname (default_ns, rqname.first, rqname.second);
  }

  xqp_string static_context::qname_internal_key (const QNameItem *qname) const
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
    ostringstream o;
    o << "fn:" << arity << "/";
    return o.str ();
  }

  function *static_context::lookup_fn (xqp_string prefix, xqp_string local, int arity) const {
    function *f = lookup_func (fn_internal_key (arity) + qname_internal_key (default_function_namespace (), prefix, local));
    if (f != NULL) return f;
    else {
      f = lookup_func (fn_internal_key (VARIADIC_SIG_SIZE) + qname_internal_key (default_function_namespace (), prefix, local));
      if (f == NULL)
        ZORBA_ERROR_ALERT (error_messages::XPST0017, NULL, false, local, to_string (arity));
      return f;
    }
  }

  xqp_string static_context::lookup_ns (xqp_string prefix) const
  {
    xqp_string ns;
    if(!context_value ("ns:" + prefix, ns))
		{
			ZORBA_ERROR_ALERT(error_messages::XQST0048);
		}
    return ns;
  }

  void static_context::bind_ns (xqp_string prefix, xqp_string ns)
  {
    bind_str ("ns:" + prefix, ns);
  }

  function *static_context::lookup_builtin_fn (xqp_string local, int arity)
  {
    return root_static_context ()->lookup_func (fn_internal_key (arity) + qname_internal_key2 (XQUERY_FN_NS, local));
  }

	TypeSystem::xqtref_t static_context::lookup_type( xqp_string key)
	{
    ctx_value_t val;
    Assert (context_value (key, val));
    return val.typeValue;
	}

	void	static_context::bind_type(xqp_string key, TypeSystem::xqtref_t t)
	{
		ctx_value_t v;
    v.typeValue = &*t;
    keymap.put (key, v);
		t->addReference();///will be decremented in static context destructor
	}

	void static_context::add_variable_type(
		const xqp_string var_name, 
		TypeSystem::xqtref_t var_type)
	{
		bind_type("type:var:" + qname_internal_key("", var_name), var_type);
	}

	TypeSystem::xqtref_t	static_context::get_variable_type(
		QNameItem *var_name)
	{
		return lookup_type( "type:var:" + qname_internal_key("", var_name->getPrefix(), var_name->getLocalName()));
	}

	void static_context::set_context_item_static_type(TypeSystem::xqtref_t t)
	{
		bind_type("type:context:", t);
	}

	TypeSystem::xqtref_t		static_context::context_item_static_type()
	{
		return lookup_type("type:context:");
	}

	void static_context::set_default_collection_type(TypeSystem::xqtref_t t)
	{
		bind_type("type:defcollection:", t);
	}

	TypeSystem::xqtref_t		static_context::default_collection_type()
	{
		return lookup_type("type:defcollection:");
	}

void static_context::set_function_type(const QNameItem *qname, TypeSystem::xqtref_t t)
{
	bind_type("type:fun:"+qname_internal_key( default_function_namespace(), qname->getPrefix(), qname->getLocalName()), t);
}

TypeSystem::xqtref_t static_context::get_function_type(
	const QNameItem_t qname) 
{
	// TODO
	//return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
	return lookup_type("type:fun:" + qname_internal_key( default_function_namespace(), qname->getPrefix(), qname->getLocalName()));
}

void static_context::set_document_type(xqp_string docURI, TypeSystem::xqtref_t t)
{
	bind_type("type:doc:"+docURI, t);
}

TypeSystem::xqtref_t static_context::get_document_type(
	const xqp_string docURI) 
{
	// TODO
//	return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
	return lookup_type("type:doc:" + docURI);

}

void static_context::set_collection_type(xqp_string collURI, TypeSystem::xqtref_t t)
{
	bind_type("type:collection:"+collURI, t);
}

TypeSystem::xqtref_t static_context::get_collection_type(
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
	bind_str("def_collation_uri:", def_uri);
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
				ZORBA_ERROR_ALERT( error_messages::XQST0076, NULL);
			}
			return NULL;///collation non-existant
		}

		::Collator *coll = zorba::getZorbaForCurrentThread()->coll_manager->getCollation(def_coll->coll_string, def_coll->coll_strength);
		if(!coll)
		{
		//	ZORBA_ERROR_ALERT(
		//			error_messages::XQST0076_STATIC_UNRECOGNIZED_COLLATION,
		//			error_messages::STATIC_ERROR,
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
		cinfo->coll = zorba::getZorbaForCurrentThread()->coll_manager->getCollation(cinfo->coll_string, cinfo->coll_strength);
		if(!cinfo->coll)
		{
		//	ZORBA_ERROR_ALERT(
		//			error_messages::XQST0076_STATIC_UNRECOGNIZED_COLLATION,
		//			error_messages::STATIC_ERROR,
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
		ZORBA_ERROR_ALERT( error_messages::XQST0076, NULL);
		return NULL;///collation non-existant
	}

	///else create it with root/::Collator::PRIMARY

	coll = zorba::getZorbaForCurrentThread()->coll_manager->getCollation(
																													"root", ::Collator::PRIMARY);
	if(!coll)
	{
	//	ZORBA_ERROR_ALERT(
	//			error_messages::XQST0076_STATIC_UNRECOGNIZED_COLLATION,
	//			error_messages::STATIC_ERROR,
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
  bool found = context_value ("int:" "baseuri", val);    
//  assert (found);                                    
  return val;
}

void static_context::set_baseuri (xqp_string val, bool from_prolog) 
{
	if(from_prolog)
	{
		///check if base uri already has been added from prolog
		///only one baseuri definition is allowed in prolog
		xqp_string str;                                        
		bool found = context_value ("int:" "from_prolog_baseuri", str);    
		if(found)
		{
			ZORBA_ERROR_ALERT(error_messages::XQST0032);
			return;
		}
		str_keymap.put ("int:" "from_prolog_baseuri", "");
	}
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

	abs_uri = base_uri;
//	"./../relativ/rel.exe"
//	"http://gfd/sdf/gsd/sdfg/gfds/sdfg/fgds/"

	if(base_uri.endsWith("/"))
	{
	}
	return base_uri + uri;
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
		ZORBA_ERROR_ALERT(error_messages::XPST0001);
		return "";
	}

	return make_absolute_uri(uri, abs_base_uri);
}

}	/* namespace xqp */

