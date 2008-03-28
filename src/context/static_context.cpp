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

#include "zorbatypes/Unicode_util.h"

#include <zorba/stateless_function.h>
#include "context/static_context_consts.h"
#include "zorbatypes/collation_manager.h"

#include "api/unmarshaller.h"

#include "errors/error_manager.h"
#include "system/globalenv.h"
#include "context/static_context.h"
#include "types/typemanager.h"
#include "functions/function.h"
#include "functions/library.h"
#include "types/casting.h"
#include "functions/signature.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "context/collation_cache.h"


// MS Visual Studio does not fully support throw(), and issues a warning
#ifndef _MSC_VER
#define THROW_XQP_EXCEPTION		throw(xqp_exception)
#else
#define THROW_XQP_EXCEPTION		
#endif

using namespace std;
namespace zorba {

#define ITEM_FACTORY (GENV.getStore().getItemFactory())

  static_context::static_context()
  : context(NULL)
  { }
  
  static_context::static_context (static_context *_parent)
  : context (_parent) {}

	static_context::~static_context()
	{
		//debug
		//test_obj.use_me();
		//end debug

		///free the pointers from ctx_value_t from keymap
		checked_vector<hashmap<ctx_value_t>::entry>::const_iterator		it;
		const char		*keybuff;
		const ctx_value_t *val;
    // TODO
		//Zorba	*z = ZORBA_FOR_CURRENT_THREAD();

		//keybuff[sizeof(keybuff)-1] = 0;
		for(it = keymap.begin();it!=keymap.end();it++)
		{
			///it is an entry
			//keymap.getentryKey(*it, keybuff, sizeof(keybuff)-1);
			keybuff = (*it).key.c_str();
			if(!strncmp(keybuff, "type:", 5))
			{
				val = &(*it).val;
				const_cast<XQType *> (val->typeValue)->removeReference(val->typeValue->getSharedRefCounter()
                                        SYNC_PARAM2(val->typeValue->getRCLock()));
			}
			else if(!strncmp(keybuff, "collation:", 10))
			{
			//val = &(*it).val;
			//if(!val->collationValue->is_user_created)
			//{
			//	if(z)
			//	{
			//		z->coll_manager->removeReference(val->collationValue->coll_string, val->collationValue->coll_strength);
			//	}
      //  delete val->collationValue;
			//}
			}
            else if (!strncmp(keybuff, "fn:", 3))
            {
                val = &(*it).val;
                delete val->functionValue;
            }
		}
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

  TypeManager *static_context::get_typemanager ()
  {
    TypeManager *tm = typemgr.get();
    if (tm != NULL) {
      return tm;
    }
    return dynamic_cast<static_context *>(parent)->get_typemanager();
  }

  void static_context::set_typemanager(std::auto_ptr<TypeManager> _typemgr)
  {
    typemgr = _typemgr;
  }


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


store::Item_t static_context::lookup_qname(
    xqp_string default_ns,
    xqp_string prefix,
    xqp_string local) const
{
  // Note: lookup_ns throws exception if there is no binding for the prefix.
  return ITEM_FACTORY->createQName((prefix.empty() ? default_ns.getStore() :
                                                     lookup_ns(prefix).getStore()),
                                   prefix.getStore(),
                                   local.getStore());
}


store::Item_t static_context::lookup_qname (xqp_string default_ns, xqp_string qname) const
{
  pair<xqp_string, xqp_string> rqname = parse_qname (qname);
  return lookup_qname (default_ns, rqname.first, rqname.second);
}

  xqp_string static_context::qname_internal_key (const store::Item *qname) const
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
        ZORBA_ERROR_PARAM ( ZorbaError::XPST0017, local, to_string (arity));
      return f;
    }
  }

  xqp_string static_context::lookup_ns (xqp_string prefix, enum ZorbaError::ErrorCode err) const
  {
    xqp_string ns;
    if(!context_value ("ns:" + prefix, ns) || ns.empty())
		{
			ZORBA_ERROR(err);
		}
    return ns;
  }

  bool static_context::lookup_elem_namespace(const xqp_string pfx, xqp_string& ns) const {
    if (pfx.empty())
    {
      ns = default_elem_type_ns(); 
    } else {
      if (!context_value("ns:" + pfx, ns))
      {
        return false;
      }
    }
    if (ns.empty())
      return false;
    else
      return true;
  }

  void static_context::bind_ns (xqp_string prefix, xqp_string ns, enum ZorbaError::ErrorCode err)
  {
    bind_str ("ns:" + prefix, ns, err);
  }

  function *static_context::lookup_builtin_fn (xqp_string local, int arity)
  {
    function *f = GENV.getRootStaticContext().lookup_func (fn_internal_key (arity) + qname_internal_key2 (XQUERY_FN_NS, local));
    if (f == NULL)
      ZORBA_NOT_IMPLEMENTED ("built-in `" + local + "/" + to_string (arity) + "'");
    return f;
  }

	xqtref_t static_context::lookup_type( xqp_string key)
	{
    ctx_value_t val;
    ZORBA_ASSERT (context_value (key, val));
    return val.typeValue;
	}

	void	static_context::bind_type(xqp_string key, xqtref_t t)
	{
		ctx_value_t v;
    v.typeValue = &*t;
    keymap.put (key, v);
		t->addReference(t->getSharedRefCounter()
                    SYNC_PARAM2(t->getRCLock()));///will be decremented in static context destructor
	}

	void static_context::add_variable_type(
		const xqp_string var_name, 
		xqtref_t var_type)
	{
		bind_type("type:var:" + qname_internal_key("", var_name), var_type);
	}

	xqtref_t	static_context::get_variable_type(
		store::Item *var_name)
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

void static_context::set_function_type(const store::Item *qname, xqtref_t t)
{
	bind_type("type:fun:"+qname_internal_key( default_function_namespace(), qname->getPrefix(), qname->getLocalName()), t);
}

xqtref_t static_context::get_function_type(
	const store::Item_t qname) 
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

/**
 * collation management
 */
void 
static_context::add_collation(const xqp_string& aURI)
{
  // TODO resolve_relative_uri does not work yet
  // xqp_string lURI = resolve_relative_uri(aURI); 
  xqp_string lURI = aURI;
  XQPCollator* lCollator = CollationFactory::createCollator(lURI);
  if (lCollator == 0)
  {
		ZORBA_ERROR_DESC( ZorbaError::XQST0038, "invalid collation uri");
  }
  else
  {
    delete lCollator;
    bind_collation(lURI);
  }
}

CollationCache*
static_context::get_collation_cache() 
{
  return new CollationCache(this);
}

void
static_context::release_collation_cache(CollationCache* aCache)
{
  delete aCache;
}

XQPCollator*
static_context::create_collator(const xqp_string& aURI)
{
  return CollationFactory::createCollator(aURI); 
}

xqp_string 
static_context::default_collation_uri() const
{
  xqp_string lURI;
  if (!lookup_default_collation(lURI))
  {
    lURI = "http://www.flworfound.org/collations/IDENTICAL/en/US";
  }
  return lURI;
}

bool
static_context::has_collation_uri(xqp_string& aURI) const
{
  return lookup_collation(aURI);
}

void 
static_context::set_default_collation_uri(const xqp_string& aURI)
{
  // TODO resolve_relative_uri does not work yet
  // xqp_string lURI = resolve_relative_uri(aURI); 
  xqp_string lURI = aURI;
  XQPCollator* lCollator = CollationFactory::createCollator(lURI);
  if (lCollator == 0)
  {
		ZORBA_ERROR_DESC( ZorbaError::XQST0038, "invalid collation uri " << lURI);
  }
  else
  {
    delete lCollator;
    bind_default_collation(lURI);
  }
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

  // TODO is a collation comparison really necessary here?
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
          ZORBA_ERROR_PARAM( ZorbaError::XQP0020_INVALID_URI, base_uri << " + " << uri, "");
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
          ZORBA_ERROR_PARAM( ZorbaError::XQP0020_INVALID_URI, base_uri << " + " << uri, "");
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
    ZORBA_ERROR_PARAM( ZorbaError::XQP0020_INVALID_URI,  base_uri << " + " << uri, "");
    return "";
  }

	return abs_uri;
}

xqp_string		static_context::resolve_relative_uri( xqp_string uri, xqp_string abs_base_uri )
{
	///check if it is an absolute URI
	if(((std::string)uri).find("://") != std::string::npos)
		return uri;
	
  if(abs_base_uri.empty())
	  abs_base_uri = current_absolute_baseuri();

	if(abs_base_uri.empty())
		compute_current_absolute_baseuri();

	///try again
	abs_base_uri = current_absolute_baseuri();

	if(abs_base_uri.empty())
	{
		//then error ! cannot resolve relative uri
		ZORBA_ERROR_DESC( ZorbaError::XPST0001, "empty base URI");
		return "";
	}

	return make_absolute_uri(uri, abs_base_uri);
}

bool
static_context::bind_stateless_external_function(StatelessExternalFunction* aExternalFunction) {
  xqpString lLocalName = Unmarshaller::getInternalString(aExternalFunction->getLocalName());
  xqpString lURI = Unmarshaller::getInternalString(aExternalFunction->getURI());

  return bind_stateless_function(lLocalName +":" +lURI, aExternalFunction);
}

StatelessExternalFunction *
static_context::lookup_stateless_external_function(xqp_string aPrefix, xqp_string aLocalName)
{
  return lookup_stateless_function( 
    qname_internal_key(default_function_namespace(), aPrefix, aLocalName)); 
}

}	/* namespace zorba */

