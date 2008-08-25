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
#include <assert.h>

#include <zorba/stateless_function.h>

#include "context/static_context_consts.h"
#include "context/static_context.h"
#include "context/namespace_context.h"
#include "context/collation_cache.h"
#include "context/context_impl.h"
#include "context/uri_resolver_wrapper.h"
#include "context/standard_uri_resolvers.h"


#include "compiler/expression/expr_base.h"

#include "zorbautils/strutil.h"
#include "zorbatypes/collation_manager.h"
#include "zorbatypes/URI.h"

#include "api/unmarshaller.h"

#include "zorbaerrors/error_manager.h"
#include "system/globalenv.h"

#include "types/typemanager.h"
#include "types/casting.h"

#include "functions/function.h"
#include "functions/library.h"
#include "functions/signature.h"

#include "store/api/store.h"
#include "store/api/item_factory.h"


using namespace std;
namespace zorba {

#define ITEM_FACTORY (GENV.getStore().getItemFactory())

static_context::static_context()
  :
  context(NULL),
  theDocResolver(0),
  theColResolver(0),
  theSchemaResolver(0),
  theModuleResolver(0)
{
  set_encapsulating_entity_baseuri ("");
  set_entity_retrieval_url ("");
}

  
static_context::static_context (static_context *_parent)
  :
  context (_parent),
  theDocResolver(0),
  theColResolver(0),
  theSchemaResolver(0),
  theModuleResolver(0)
{
}


static_context::~static_context()
{
  //debug
  //test_obj.use_me();
  //end debug

  ///free the pointers from ctx_value_t from keymap
  checked_vector<hashmap<ctx_value_t>::entry>::const_iterator   it;
  const char    *keybuff;
  
  //keybuff[sizeof(keybuff)-1] = 0;
  for(it = keymap.begin();it!=keymap.end();it++)
  {
    ///it is an entry
    //keymap.getentryKey(*it, keybuff, sizeof(keybuff)-1);
    keybuff = (*it).key.c_str();
    const ctx_value_t *val = &(*it).val;

    if (0 == strncmp(keybuff, "type:", 5)) {
      RCHelper::removeReference (const_cast<XQType *> (val->typeValue));
    } else if (0 == strncmp(keybuff, "var:", 4)) {
      RCHelper::removeReference (const_cast<expr *> (val->exprValue));
    } else if (0 == strncmp(keybuff, "fn:", 3)) {
      RCHelper::removeReference (const_cast<function *> (val->functionValue));
    }
  }

  set_document_uri_resolver(0);
  set_collection_uri_resolver(0);
  set_schema_uri_resolver(0);
  set_module_uri_resolver(0);
}

bool context::bind_expr (xqp_string key, expr *e) {
  ctx_value_t v;
  v.exprValue = e;
  if (keymap.put (key, v, false))
    return false;
  RCHelper::addReference (e);
  return true;
}

bool context::bind_func (xqp_string key, function *f) {
  ctx_value_t v;
  v.functionValue = f;
  if (keymap.put (key, v, false))
    return false;
  RCHelper::addReference (f);
  return true;
}

bool context::bind_expr2 (const char *key1, xqp_string key2, expr *e) {
  ctx_value_t v;
  v.exprValue = e;
  if (keymap.put2 (key1, key2, v, false))
    return false;
  RCHelper::addReference (e);
  return true;
}

bool context::bind_func2 (const char *key1, xqp_string key2, function *f) {
  ctx_value_t v;
  v.functionValue = f;
  if (keymap.put2 (key1, key2, v, false))
    return false;
  RCHelper::addReference (f);
  return true;
}



DECL_ENUM_PARAM (static_context, construction_mode)
DECL_ENUM_PARAM (static_context, order_empty_mode)
DECL_ENUM_PARAM (static_context, boundary_space_mode)
DECL_ENUM_PARAM (static_context, inherit_mode)
DECL_ENUM_PARAM (static_context, preserve_mode)
DECL_ENUM_PARAM (static_context, xpath1_0compatib_mode)
DECL_ENUM_PARAM (static_context, ordering_mode)

// DECL_STR_PARAM (static_context, baseuri)
// DECL_STR_PARAM (static_context, default_collation)
DECL_STR_PARAM (static_context, default_function_namespace, XQST0066)
DECL_STR_PARAM (static_context, default_elem_type_ns, XQST0066)
DECL_STR_PARAM (static_context, current_absolute_baseuri, MAX_ZORBA_ERROR_CODE)
DECL_STR_PARAM_TRIGGER (static_context, encapsulating_entity_baseuri, MAX_ZORBA_ERROR_CODE, set_current_absolute_baseuri (""))
DECL_STR_PARAM_TRIGGER (static_context, entity_retrieval_url, MAX_ZORBA_ERROR_CODE, set_current_absolute_baseuri (""))

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
  return xqpString::concat(local, ":", ns);
}


store::Item_t static_context::lookup_qname(
    xqp_string default_ns,
    xqp_string prefix,
    xqp_string local) const
{
  store::Item_t qname;
  xqpStringStore_t ns = (prefix.empty() ?
                         default_ns.theStrStore :
                         lookup_ns(prefix).theStrStore);

  // Note: lookup_ns throws exception if there is no binding for the prefix.
  ITEM_FACTORY->createQName(qname,
                            ns,
                            prefix.theStrStore,
                            local.theStrStore);
  return qname;
}


store::Item_t static_context::lookup_qname (xqp_string default_ns, xqp_string qname) const
{
  pair<xqp_string, xqp_string> rqname = parse_qname (qname);
  return lookup_qname (default_ns, rqname.first, rqname.second);
}


  xqp_string static_context::qname_internal_key (const store::Item *qname)
  {
    return qname_internal_key2 (qname->getNamespace (), qname->getLocalName ());
  }

  xqp_string static_context::qname_internal_key (xqp_string default_ns, xqp_string prefix, xqp_string local) const
  {
    return qname_internal_key2(prefix.empty () ? default_ns : lookup_ns (prefix),
                               local);
  }

  xqp_string static_context::qname_internal_key (xqp_string default_ns, xqp_string qname) const
  {
    pair<xqp_string, xqp_string> rqname = parse_qname (qname);
    return qname_internal_key (default_ns, rqname.first, rqname.second);
  }

  xqp_string static_context::fn_internal_key (int arity) 
  {
    return xqpString::concat("fn:", to_string (arity).c_str(), "/");
  }


function *static_context::lookup_fn (xqp_string prefix, xqp_string local, int arity) const 
{
  function *f = lookup_func2 (fn_internal_key (arity),
                             qname_internal_key (default_function_namespace (),
                                                 prefix,
                                                 local));
  if (f != NULL)
    return f;
  else 
  {
    f = lookup_func2(fn_internal_key (VARIADIC_SIG_SIZE),
                     qname_internal_key (default_function_namespace (),
                                         prefix,
                                         local));
    if (f == NULL)
      ZORBA_ERROR_PARAM (XPST0017, (prefix.empty () ? prefix : (prefix + ":")) + local, to_string (arity));
    return f;
  }
}

  bool static_context::lookup_ns (xqp_string prefix, xqp_string &ns) const {
    return context_value2 ("ns:", prefix, ns) && ! ns.empty();    
  }

  xqp_string static_context::lookup_ns (xqp_string prefix, const XQUERY_ERROR& err) const {
    xqp_string ns;
    if (! lookup_ns (prefix, ns)) {
      if (err != MAX_ZORBA_ERROR_CODE)
        ZORBA_ERROR_PARAM(err, prefix, "");
    }
    return ns;
  }

  xqp_string static_context::lookup_ns_or_default (xqp_string prefix, xqp_string default_ns) const {
    xqp_string ns;
    if (! lookup_ns (prefix, ns)) {
      return default_ns;
    }
    return ns;
  }

  bool static_context::lookup_elem_namespace(const xqp_string pfx, xqp_string& ns) const {
    if (pfx.empty())
    {
      ns = default_elem_type_ns(); 
    } else {
      if (!context_value2("ns:", pfx, ns))
      {
        return false;
      }
    }
    if (ns.empty())
      return false;
    else
      return true;
  }

  void static_context::bind_ns (xqp_string prefix, xqp_string ns, const XQUERY_ERROR& err)
  {
    bind_str2 ("ns:", prefix, ns, err);
  }

  function *static_context::lookup_builtin_fn (xqp_string local, int arity)
  {
    function *f = GENV.getRootStaticContext().lookup_func2 (fn_internal_key (arity), qname_internal_key2 (XQUERY_FN_NS, local));
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
  xqtref_t static_context::lookup_type2( const char *key1, xqp_string key2)
  {
    ctx_value_t val;
    ZORBA_ASSERT (context_value2 (key1, key2, val));
    return val.typeValue;
  }

  void  static_context::bind_type(xqp_string key, xqtref_t t)
  {
    ctx_value_t v;
    v.typeValue = &*t;
    keymap.put (key, v);
    RCHelper::addReference (const_cast<XQType *> (t.getp ()));
  }

  void static_context::add_variable_type(
    const xqp_string var_name, 
    xqtref_t var_type)
  {
    bind_type("type:var:" + qname_internal_key("", var_name), var_type);
  }

  xqtref_t  static_context::get_variable_type(
    store::Item *var_name)
  {
    return lookup_type2( "type:var:", qname_internal_key("",
                                                         var_name->getPrefix(),
                                                         var_name->getLocalName()));
  }

  void static_context::set_context_item_static_type(xqtref_t t)
  {
    bind_type("type:context:", t);
  }

  xqtref_t    static_context::context_item_static_type()
  {
    return lookup_type("type:context:");
  }

  void static_context::set_default_collection_type(xqtref_t t)
  {
    bind_type("type:defcollection:", t);
  }

  xqtref_t    static_context::default_collection_type()
  {
    return lookup_type("type:defcollection:");
  }

void static_context::set_function_type(const store::Item *qname, xqtref_t t)
{
  bind_type("type:fun:" + qname_internal_key( default_function_namespace(),
                                            qname->getPrefix(),
                                            qname->getLocalName()),
            t);
}

xqtref_t static_context::get_function_type(
  const store::Item_t qname) 
{
  return lookup_type2("type:fun:", qname_internal_key(default_function_namespace(),
                                                      qname->getPrefix(),
                                                      qname->getLocalName()));
}

void static_context::set_document_type(xqp_string docURI, xqtref_t t)
{
  bind_type("type:doc:" + docURI, t);
}

xqtref_t static_context::get_document_type(
  const xqp_string docURI) 
{
  return lookup_type2("type:doc:", docURI);

}

void static_context::set_collection_type(xqp_string collURI, xqtref_t t)
{
  bind_type("type:collection:" + collURI, t);
}

xqtref_t static_context::get_collection_type(
  const xqp_string collURI) 
{
  return lookup_type2("type:collection:", collURI);
}

/**
 * collation management
 */
void 
static_context::add_collation(const xqp_string& aURI)
{
  xqp_string lURI = resolve_relative_uri(aURI); 
  XQPCollator* lCollator = CollationFactory::createCollator(lURI);
  if (lCollator == 0)
  {
    ZORBA_ERROR_DESC( XQST0038, "invalid collation uri");
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
    lURI = ZORBA_DEF_COLLATION_NS;
  }
  return lURI;
}

bool
static_context::has_collation_uri(const xqp_string& aURI) const
{
  return lookup_collation(aURI);
}

void 
static_context::set_default_collation_uri(const xqp_string& aURI)
{
  xqp_string lURI = resolve_relative_uri(aURI); 
  XQPCollator* lCollator = CollationFactory::createCollator(lURI);
  if (lCollator == 0)
  {
    ZORBA_ERROR_DESC_OSS( XQST0038, "invalid collation uri " << lURI);
  }
  else
  {
    delete lCollator;
    bind_default_collation(lURI);
  }
}


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
    // throw XQST0032 if from_prolog_baseuri is already defined
    bind_str ("int:" "from_prolog_baseuri", val, XQST0032);
  else
    // overwite existing value of baseuri, if any
    str_keymap.put ("int:" "baseuri", val);

  compute_current_absolute_baseuri ();
}

void static_context::compute_current_absolute_baseuri()
{
  //if base Uri is present, compute absolute base Uri
  //else if encapsulating_entity_baseuri is present, use that
  //else if entity_retrieval_url is present, use that
  //else do not set the absolute baseuri (and hope there are no relative uris)

  xqp_string    prolog_baseuri;
  xqp_string    ee_baseuri;
  xqp_string    loaded_uri;

  prolog_baseuri = baseuri();

  if (!prolog_baseuri.empty()) {
    try {
      URI lCheckValid(prolog_baseuri);
      // is already absolute baseuri
      set_current_absolute_baseuri(prolog_baseuri);
      return; // valid (absolute) uri
    } catch (error::ZorbaError& e) {
      throw e;
    } // assume it's relative and go on
  }
  if (!prolog_baseuri.empty()) {
    /// is relative, needs to be resolved
    ee_baseuri = encapsulating_entity_baseuri();
    if(!ee_baseuri.empty()) {
      set_current_absolute_baseuri(make_absolute_uri(prolog_baseuri, ee_baseuri));
      return;
    }
    loaded_uri = entity_retrieval_url();
    if(!loaded_uri.empty()) {
      set_current_absolute_baseuri(make_absolute_uri(prolog_baseuri, loaded_uri));
      return;
    }
    
    set_current_absolute_baseuri (make_absolute_uri(prolog_baseuri, implementation_baseuri()));
    return;
  }

  ee_baseuri = encapsulating_entity_baseuri();
  if(!ee_baseuri.empty()) {
    set_current_absolute_baseuri(ee_baseuri);
    return;
  }
  loaded_uri = entity_retrieval_url();
  if(!loaded_uri.empty()) {
    set_current_absolute_baseuri(loaded_uri);
    return;
  }
  set_current_absolute_baseuri (implementation_baseuri());
  return;
}

xqp_string static_context::make_absolute_uri(xqp_string uri, xqp_string base_uri) {
  URI resolved_uri(base_uri, uri);
  return resolved_uri.toString();
}

xqp_string static_context::final_baseuri () {
  // cached value
  string abs_base_uri = current_absolute_baseuri();

  if(abs_base_uri.empty()) {
    compute_current_absolute_baseuri();
    abs_base_uri = current_absolute_baseuri();
  }

  // won't happen -- we default to a non-empty URI
  if(abs_base_uri.empty()) {
    ZORBA_ERROR_DESC( XPST0001, "empty base URI");
    return "";
  }
  
  return abs_base_uri;
}

xqp_string static_context::resolve_relative_uri (xqp_string uri, xqp_string abs_base_uri) {
  return make_absolute_uri (uri, abs_base_uri.empty () ? final_baseuri () : abs_base_uri);
}

bool static_context::import_module (const static_context *module) {
  checked_vector<hashmap<ctx_value_t>::entry>::const_iterator   it;
  const char    *keybuff;
  
  for(it = module->keymap.begin();it!=module->keymap.end();it++) {
    keybuff = (*it).key.c_str();
    const ctx_value_t *val = &(*it).val;

    if (0 == strncmp(keybuff, "var:", 4) && 0 != strncmp(keybuff, "var:$$", 6)) {
      if (! bind_expr (keybuff, val->exprValue))
        return false;
    } else if (0 == strncmp(keybuff, "fn:", 3)) {
      if (! bind_func (keybuff, val->functionValue))
        return false;
    }
  }

  return true;
}


bool
static_context::bind_stateless_external_function(StatelessExternalFunction* aExternalFunction) {
  xqpString lLocalName = Unmarshaller::getInternalString(aExternalFunction->getLocalName());
  xqpString lURI = Unmarshaller::getInternalString(aExternalFunction->getURI());

  return bind_stateless_function(xqpString::concat(lLocalName,":",lURI), aExternalFunction);
}

StatelessExternalFunction *
static_context::lookup_stateless_external_function(xqp_string aPrefix, xqp_string aLocalName)
{
  return lookup_stateless_function( 
    qname_internal_key(default_function_namespace(), aPrefix, aLocalName)); 
}

// URI Resolver
void
static_context::set_document_uri_resolver(InternalDocumentURIResolver* aDocResolver)
{
  if ( theDocResolver )
    delete theDocResolver;

  theDocResolver = aDocResolver;
}

InternalDocumentURIResolver*
static_context::get_document_uri_resolver()
{
  if ( theDocResolver != 0 )
    return theDocResolver;
  return dynamic_cast<static_context*>(parent)->get_document_uri_resolver();
}

void
static_context::set_collection_uri_resolver(InternalCollectionURIResolver* aColResolver)
{
  if ( theColResolver )
    delete theColResolver;

  theColResolver = aColResolver;
}

InternalCollectionURIResolver*
static_context::get_collection_uri_resolver()
{
  if ( theColResolver != 0 )
    return theColResolver;
  return dynamic_cast<static_context*>(parent)->get_collection_uri_resolver();
}

void
static_context::set_schema_uri_resolver(InternalSchemaURIResolver* aSchemaResolver)
{
  if ( theSchemaResolver )
    delete theSchemaResolver;

  theSchemaResolver = aSchemaResolver;
}

InternalSchemaURIResolver*
static_context::get_schema_uri_resolver()
{
  if ( theSchemaResolver != 0 )
    return theSchemaResolver;
  return dynamic_cast<static_context*>(parent)->get_schema_uri_resolver();
}

void
static_context::set_module_uri_resolver(InternalModuleURIResolver* aModuleResolver)
{
  if ( theModuleResolver )
    delete theModuleResolver;

  theModuleResolver = aModuleResolver;
}

InternalModuleURIResolver*
static_context::get_module_uri_resolver()
{
  if ( theModuleResolver != 0 )
    return theModuleResolver;
  return dynamic_cast<static_context*>(parent)->get_module_uri_resolver();
}



} /* namespace zorba */

