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

#include <zorba/external_module.h>
#include <zorba/serialization_callback.h>

#include "context/static_context_consts.h"
#include "context/static_context.h"
#include "context/namespace_context.h"
#include "context/collation_cache.h"
#include "context/context_impl.h"
#include "context/uri_resolver_wrapper.h"
#include "context/standard_uri_resolvers.h"
#include "context/decimal_format.h"
#include "context/statically_known_collection.h"


#include "compiler/expression/expr_base.h"
#include "compiler/expression/var_expr.h"
#include "compiler/indexing/value_index.h"

#include "zorbautils/strutil.h"
#define ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_WITH_SERIALIZATION
#include "zorbautils/hashmap_itemp.h"
#undef ZORBA_ZORBAUTILS_ITEM_POINTER_HASHMAP_WITH_SERIALIZATION

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

SERIALIZABLE_CLASS_VERSIONS(context)
END_SERIALIZABLE_CLASS_VERSIONS(context)

SERIALIZABLE_CLASS_VERSIONS(context::ctx_value_t)
END_SERIALIZABLE_CLASS_VERSIONS(context::ctx_value_t)

SERIALIZABLE_CLASS_VERSIONS(context::ctx_module_t)
END_SERIALIZABLE_CLASS_VERSIONS(context::ctx_module_t)

SERIALIZABLE_CLASS_VERSIONS(static_context)
END_SERIALIZABLE_CLASS_VERSIONS(static_context)


/*******************************************************************************
  Class context methods
********************************************************************************/
void context::serialize(::zorba::serialization::Archiver& ar)
{
  //serialize_baseclass(ar, (SimpleRCObject*)this);
  if(ar.is_serializing_out())
  {
    ar.set_is_temp_field_one_level(true);
    bool  parent_is_root = check_parent_is_root();//(
    ar & parent_is_root;
    ar.set_is_temp_field_one_level(false);
    if(!parent_is_root)
    {
      ar.dont_allow_delay();
      ar & parent;
    }
    else
    {
      //  context *fooctx = NULL;
      //  ar & fooctx;
    }
  }
  else
  {
    //in serialization
    ar.set_is_temp_field_one_level(true);
    bool  parent_is_root;
    ar & parent_is_root;
    ar.set_is_temp_field_one_level(false);
    if(parent_is_root)
    {
      set_parent_as_root();
    }
    else
      ar & parent;
    if(parent)
      parent->addReference(parent->getSharedRefCounter() SYNC_PARAM2(parent->getRCLock()));
  }
  ar & keymap;
  ar & modulemap;
  ar & str_keymap;
  ar & module_paths;
  ar & theDefaultFunctionNamespace;
}
  

function* context::lookup_fmap_func(xqp_string key, int arity) const 
{
  ArityFMap *fmap = lookup_fmap (key);
  if (fmap == NULL)
    return NULL;
  ArityFMap::iterator i = fmap->find (arity);
  return i == fmap->end () ? NULL : (*i).second;
}


void context::bind_str (
    xqp_string key,
    xqp_string v,
    XQUERY_ERROR err) 
{
  if (str_keymap.put(key, v))
  {
    if (err != MAX_ZORBA_ERROR_CODE)
      ZORBA_ERROR(err);
  }
}


void context::bind_str2 (
    const char *key1,
    xqp_string key2,
    xqp_string v,
    XQUERY_ERROR err) 
{
  if (str_keymap.put2 (key1, key2, v))
  {
    if (err != MAX_ZORBA_ERROR_CODE)
      ZORBA_ERROR(err);
  }
}


bool context::bind_expr (xqp_string key, expr *e) 
{
  ctx_value_t v(CTX_EXPR);
  v.exprValue = e;

  // return false if the key was in the map already
  if (keymap.put (key, v, false))
    return false;

  RCHelper::addReference (e);
  return true;
}


bool context::bind_expr2 (const char *key1, xqp_string key2, expr *e) 
{
  ctx_value_t v(CTX_EXPR);
  v.exprValue = e;

  // return false if the key was in the map already
  if (keymap.put2 (key1, key2, v, false))
    return false;

  RCHelper::addReference (e);
  return true;
}


bool context::bind_func (xqp_string key, function *f) 
{
  ctx_value_t v(CTX_FUNCTION);
  v.functionValue = f;

  // return false if the key was in the map already
  if (keymap.put (key, v, false))
    return false;

  RCHelper::addReference (f);
  return true;
}


bool context::bind_func2 (const char *key1, xqp_string key2, function *f) 
{
  ctx_value_t v(CTX_FUNCTION);
  v.functionValue = f;

  // return false if the key was in the map already
  if (keymap.put2 (key1, key2, v, false))
    return false;

  RCHelper::addReference (f);
  return true;
}


bool context::bind_module(xqp_string uri, ExternalModule* m,
                          bool dyn_loaded) 
{
  ctx_module_t v;
  v.module = m;
  v.dyn_loaded_module = dyn_loaded;
  return !modulemap.put (uri, v, false);
}

bool context::check_parent_is_root()
{
  return parent == (context*)&GENV_ROOT_STATIC_CONTEXT;
}


void context::set_parent_as_root()
{
  parent = &GENV_ROOT_STATIC_CONTEXT;
}

void context::ctx_module_t::serialize(serialization::Archiver &ar)
{
  if(ar.is_serializing_out()) {
    // serialize out: the uri of the module that is used in this plan

    xqp_string lURI = Unmarshaller::getInternalString(module->getURI());
    xqpStringStore_t lURIStore = lURI.getStore();
	  ar.set_is_temp_field_one_level(true);
    ar.dont_allow_delay();
    ar & lURIStore;
	  ar.set_is_temp_field_one_level(false);
    ar & dyn_loaded_module;
  } else {
    // serialize in: load the serialized uri of the module and
    //               get the externalmodule from the user's
    //               registered serialization callback
    xqpStringStore_t lURIStore = 0;
	  ar.set_is_temp_field_one_level(true);
    ar & lURIStore;
	  ar.set_is_temp_field_one_level(false);
    ar & dyn_loaded_module;

    if (dyn_loaded_module) {
      InternalModuleURIResolver* lStandardModuleResolver 
        = GENV.getModuleURIResolver();

      module = lStandardModuleResolver->getExternalModule(
                  lURIStore.getp(), 0);

      // no way to get the module
      if (!module) {
        ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                             "Couldn't load pre-compiled query because"
                             << " the external module " << lURIStore 
                             << " is not available to be loaded from a" 
                             << " dynamic library.");
      }
    } else { 
      // class registered by the user
      SerializationCallback* lCallback = ar.getUserCallback();
      if (!lCallback) {
        ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                             "Couldn't load pre-compiled query because"
                             << " the external module " << lURIStore 
                             << " is required but no SerializationCallback is"
                             << " given for retrieving that module.");
      }

      // the life-cycle of the module is managed by the user
      module = lCallback->getExternalModule(lURIStore.getp());
      if (!module) {
        ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                             "Couldn't load pre-compiled query because"
                             << " the external module " << lURIStore 
                             << " is not available using the registered"
                             << " SerializationCallback");
      }
    }
  }
}

void context::ctx_value_t::serialize(::zorba::serialization::Archiver &ar)
{
  SERIALIZE_ENUM(enum ctx_value_type, type);
  switch(type)
  {
  case CTX_EXPR:
    ar.dont_allow_delay();
    ar & exprValue;
    if(!ar.is_serializing_out() && exprValue)
      RCHelper::addReference (exprValue);
    break;
  case CTX_FUNCTION:
    ar.set_serialize_only_for_eval(true);
    ar.dont_allow_delay();
    SERIALIZE_FUNCTION(functionValue);
    if(!ar.is_serializing_out() && functionValue)
      RCHelper::addReference (functionValue);
    ar.set_serialize_only_for_eval(false);
    break;
  case CTX_ARITY:
    ar.set_serialize_only_for_eval(true);
    ar & fmapValue;
    ar.set_serialize_only_for_eval(false);
  /*  if(ar.is_serializing_out())
    {
      printf("out CTX_ARITY %x size=%d\n", fmapValue, fmapValue->size());
      ArityFMap::const_iterator   ar_it;
      for(ar_it = fmapValue->begin(); ar_it != fmapValue->end(); ar_it++)
      {
        printf("    %d    %s:%s\n", ar_it->first, ar_it->second->get_fname()->getLocalName()->c_str(),
                                    ar_it->second->get_fname()->getNamespace()->c_str());
      }
    }
  */
  //  if(!ar.is_serializing_out())
  //    fmapValue = NULL;//don't serialize this
    break;
  case CTX_INT:
    ar & intValue;
    break;
  case CTX_BOOL:
    ar & boolValue;
    break;
  case CTX_XQTYPE:
  default:
    if(!ar.is_serializing_out())
      typeValue = NULL;//don't serialize this
    break;
  }
}


xqpStringStore* context::default_function_ns() const
{
  if (theDefaultFunctionNamespace != NULL || this->parent == NULL)
    return theDefaultFunctionNamespace.getp();
  else
    return parent->default_function_ns();
}


void context::set_default_function_ns(const char* ns, const QueryLoc* loc)
{
  if (theDefaultFunctionNamespace != NULL)
  {
    if (loc)
      ZORBA_ERROR_LOC(XQST0066, *loc);
    else
      ZORBA_ERROR(XQST0066);
  }

  theDefaultFunctionNamespace = new xqpStringStore(ns);
}


/*******************************************************************************
  Constructors/Destructor
********************************************************************************/
static_context::static_context()
  :
  context(NULL),
  theDocResolver(0),
  theColResolver(0),
  theSchemaResolver(0),
  theCollectionMap(0),
  theIndexMap(NULL),
  theTraceStream(0),
  theCollationCache(0)
{
  set_encapsulating_entity_baseuri ("");
  set_entity_retrieval_url ("");
}

  
static_context::static_context (static_context* parent)
  :
  context(parent),
  theDocResolver(0),
  theColResolver(0),
  theSchemaResolver(0),
  theCollectionMap(0),
  theIndexMap(NULL),
  theTraceStream(0),
  theCollationCache(0)
{
  if (parent != NULL)
    RCHelper::addReference(parent);
}


static_context::static_context(::zorba::serialization::Archiver& ar)
  :
  context(ar),
  theDocResolver(0),
  theColResolver(0),
  theSchemaResolver(0),
  theCollectionMap(0),
  theIndexMap(0),
  theTraceStream(0),
  theCollationCache(0)
{
}


static_context::~static_context()
{
  //debug
  //test_obj.use_me();
  //end debug
  //
  delete theCollationCache;

  ///free the pointers from ctx_value_t from keymap
  checked_vector<serializable_hashmap<ctx_value_t>::entry>::const_iterator it;
  const char* keybuff;
  
  //keybuff[sizeof(keybuff)-1] = 0;
  for(it = keymap.begin(); it != keymap.end(); it++)
  {
    ///it is an entry
    //keymap.getentryKey(*it, keybuff, sizeof(keybuff)-1);
    keybuff = (*it).key.c_str();
    const ctx_value_t *val = &(*it).val;
    if(val->exprValue)
    {
      if (0 == strncmp(keybuff, "type:", 5)) {
        RCHelper::removeReference (const_cast<XQType *> (val->typeValue));
      } else if (0 == strncmp(keybuff, "var:", 4)) {
        RCHelper::removeReference (const_cast<expr *> (val->exprValue));
      } else if (0 == strncmp(keybuff, "fn:", 3)) {
        RCHelper::removeReference (const_cast<function *> (val->functionValue));
      } else if (0 == strncmp(keybuff, "fmap:", 5)) {
        delete (const_cast<ArityFMap *> (val->fmapValue));
      }
    }
  }

  checked_vector<serializable_hashmap<ctx_module_t>::entry>::const_iterator   it2;
  for(it2 = modulemap.begin(); it2 != modulemap.end(); it2++)
  {
    const ctx_module_t *val = &(*it2).val;
    if (val->dyn_loaded_module) {
      val->module->destroy();
    }
  }

  set_document_uri_resolver(0);
  set_collection_uri_resolver(0);
  set_schema_uri_resolver(0);

  if (theCollectionMap) {
    delete theCollectionMap; theCollectionMap = 0;
  }

  if (theIndexMap)
    delete theIndexMap;

  if (parent)
    RCHelper::removeReference(parent);
}


/*******************************************************************************

********************************************************************************/
void static_context::serialize_resolvers(serialization::Archiver& ar)
{
  bool lUserDocResolver, lUserColResolver;
  if (ar.is_serializing_out()) 
  {
    // serialize out: remember whether a doc and collection
    //                resolver was registered by the user
    lUserDocResolver = (dynamic_cast<StandardDocumentURIResolver*>(theDocResolver) != NULL); 
    lUserColResolver = (dynamic_cast<StandardCollectionURIResolver*>(theColResolver) != NULL);

	  ar.set_is_temp_field_one_level(true);
    ar & lUserDocResolver;
    ar & lUserColResolver;
	  ar.set_is_temp_field_one_level(false);
  } else {
    // serialize in: set the document and collection resolvers
    //               use one by the user or use the default
    //               if null is returned
    SerializationCallback* lCallback = ar.getUserCallback();

	  ar.set_is_temp_field_one_level(true);
    ar & lUserDocResolver; // doc resolver passed by the user
    ar & lUserColResolver; // col resolver passed by the user
	  ar.set_is_temp_field_one_level(false);

    // callback required but not available
    if ((lUserDocResolver || lUserColResolver) && !lCallback) {
      ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                           "Couldn't load pre-compiled query because"
                           << " a document or collection resolver"
                           << " is required but no SerializationCallback"
                           << " is given for retrieving these resolvers.");
    }

    if (lUserDocResolver) {
      DocumentURIResolver* lDocResolver = lCallback->getDocumentURIResolver();
      if (!lDocResolver) {
        ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                             "Couldn't load pre-compiled query because"
                             " no document URI resolver could be retrieved"
                             " using the given SerializationCallback"); 
      }
      set_document_uri_resolver(new DocumentURIResolverWrapper(lDocResolver));
    }

    if (lUserColResolver) {
      CollectionURIResolver* lColResolver = lCallback->getCollectionURIResolver();
      if (!lColResolver) {
        ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                             "Couldn't load pre-compiled query because"
                             " no collection URI resolver could be retrieved"
                             " using the given SerializationCallback"); 
      }
      set_collection_uri_resolver(new CollectionURIResolverWrapper(lColResolver));
    }
  }
}


void static_context::serialize_tracestream(serialization::Archiver& ar)
{
  bool lUserTraceStream;
  if (ar.is_serializing_out()) 
  {
    // serialize out: remember whether the user registered a trace stream
    lUserTraceStream = (theTraceStream != 0);

	  ar.set_is_temp_field_one_level(true);
    ar & lUserTraceStream;
	  ar.set_is_temp_field_one_level(false);
  } else {
    // serialize in: set the trace stream from the user
    //               std::cerr is used if non was registered
    SerializationCallback* lCallback = ar.getUserCallback();

	  ar.set_is_temp_field_one_level(true);
    ar & lUserTraceStream; // trace stream passed by the user
	  ar.set_is_temp_field_one_level(false);

    // callback required but not available
    if (lUserTraceStream && !lCallback) {
      ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                           "Couldn't load pre-compiled query because "
                           << " a trace stream"
                           << " is required but no SerializationCallback"
                           << " is given for retrieving it.");
    }

    if (lUserTraceStream) {
      bool lTraceStream =  lCallback->getTraceStream(*theTraceStream);
      if (!lTraceStream) {
        ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                             "Couldn't load pre-compiled query because"
                             " no trace stream could be retrieved"
                             " using the given SerializationCallback."); 
      }
    } 
  }
}


void static_context::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (context*)this);
  SERIALIZE_TYPEMANAGER_RCHANDLE(TypeManager, theTypemgr);

  serialize_resolvers(ar);
  serialize_tracestream(ar);

  ar & theCollectionMap;
  ar & theIndexMap;
  ar & theCollationCache;
}


/*******************************************************************************

********************************************************************************/
static_context* static_context::create_child_context() 
{
  return new static_context(this); 
}


/*******************************************************************************

********************************************************************************/
void static_context::set_typemanager(rchandle<TypeManager> typemgr)
{
  theTypemgr = typemgr;
}


TypeManager* static_context::get_typemanager() const
{
  TypeManager* tm = theTypemgr.getp();
  if (tm != NULL) {
    return tm;
  }
  return static_cast<static_context *>(parent)->get_typemanager();
}


TypeManager* static_context::get_local_typemanager() const 
{
  return theTypemgr.getp(); 
}

/*******************************************************************************

********************************************************************************/
expr_t static_context::get_query_expr() const 
{
  return theQueryExpr;
}


void static_context::set_query_expr(expr_t expr) 
{
  theQueryExpr = expr;
}


/*******************************************************************************

********************************************************************************/
void static_context::add_decimal_format(const DecimalFormat_t& decimalFormat)
{
  theDecimalFormats.push_back(decimalFormat);
}


DecimalFormat_t static_context::get_decimal_format(const store::Item_t qname)
{  
  for (std::vector<DecimalFormat_t>::iterator it = theDecimalFormats.begin();
       it != theDecimalFormats.end();
       it++)
  {
    if ((qname.isNull() && (*it)->isDefaultFormat())
        ||
        (!qname.isNull() &&qname->getStringValue()->compare((*it)->getFormatName()->getStringValue()) == 0))
      return (*it);    
  }
  return NULL;
}


/*******************************************************************************
  Methods for setting and retrieving certain "simple" context properties
********************************************************************************/
DECL_ENUM_PARAM (static_context, xquery_version)
DECL_ENUM_PARAM (static_context, xpath1_0compatib_mode)
DECL_ENUM_PARAM (static_context, construction_mode)
DECL_ENUM_PARAM (static_context, order_empty_mode)
DECL_ENUM_PARAM (static_context, boundary_space_mode)
DECL_ENUM_PARAM (static_context, inherit_mode)
DECL_ENUM_PARAM (static_context, preserve_mode)
DECL_ENUM_PARAM (static_context, ordering_mode)
DECL_ENUM_PARAM (static_context, validation_mode)

DECL_INT_PARAM (static_context, revalidation_enabled, bool)

//DECL_STR_PARAM (static_context, default_function_namespace, XQST0066)
DECL_STR_PARAM (static_context, default_elem_type_ns, XQST0066)

DECL_STR_PARAM (static_context, current_absolute_baseuri, MAX_ZORBA_ERROR_CODE)

DECL_STR_PARAM_TRIGGER (static_context, encapsulating_entity_baseuri, MAX_ZORBA_ERROR_CODE, set_current_absolute_baseuri (""))

void
static_context::set_xquery_version(const std::string& v)
{
  StaticContextConsts::xquery_version_t lVersion 
    = StaticContextConsts::xquery_version_unknown;
  if (v == "1.0")
  {
    lVersion = StaticContextConsts::xquery_version_1_0;
  }
  else if (v == "1.1")
  {
    lVersion = StaticContextConsts::xquery_version_1_1;
  }
  set_xquery_version(lVersion);
}

/*******************************************************************************
  Bind the given prefix to the given namaspace uri. The binding is stored in
  "this". If there is already in "this" a binding for the prefix, raise error.
********************************************************************************/
void static_context::bind_ns (xqp_string prefix, xqp_string ns, const XQUERY_ERROR& err)
{
  bind_str2 ("ns:", prefix, ns, err);
}


/*******************************************************************************

  Methods that perform Prefix-to-Namespace resolution.

  The following method searches the static-context tree, starting from "this"
  and moving upwards, looking for the 1st mapping between the given prefix and a
  namespace uri. It returns false if no such mapping is found, or the ns uri in the
  mapping is empty. Otherwise, it returns true and the associated uri.

********************************************************************************/
bool static_context::lookup_ns (xqp_string prefix, xqp_string &ns) const 
{
  return context_value2 ("ns:", prefix, ns) && ! ns.empty();
}


xqp_string static_context::lookup_ns (xqp_string prefix, const XQUERY_ERROR& err) const 
{
  xqp_string ns;
  if (! lookup_ns (prefix, ns)) {
    if (err != MAX_ZORBA_ERROR_CODE)
      ZORBA_ERROR_PARAM(err, prefix, "");
  }
  return ns;
}


xqp_string static_context::lookup_ns(
    xqp_string prefix,
    const QueryLoc& loc,
    const XQUERY_ERROR& err) const 
{
  xqp_string ns;
  if (! lookup_ns (prefix, ns)) {
    if (err != MAX_ZORBA_ERROR_CODE)
      ZORBA_ERROR_LOC_PARAM(err, loc, prefix, "");
  }
  return ns;
}


xqp_string static_context::lookup_ns_or_default (xqp_string prefix, xqp_string default_ns) const 
{
  xqp_string ns;
  if (! lookup_ns (prefix, ns)) {
    return default_ns;
  }
  return ns;
}


bool static_context::lookup_elem_ns(const xqp_string pfx, xqp_string& ns) const 
{
  if (pfx.empty())
  {
    ns = default_elem_type_ns(); 

    if (ns.empty())
      return false;
    else
      return true;
  }
  else 
  {
    return lookup_ns(pfx, ns);
  }
}


store::Item_t static_context::lookup_qname(
    xqp_string default_ns,
    xqp_string prefix,
    xqp_string local,
    const QueryLoc& loc) const
{
  store::Item_t qname;
  xqpStringStore_t ns = (prefix.empty() ?
                         default_ns.theStrStore :
                         lookup_ns(prefix, loc).theStrStore);

  // Note: lookup_ns throws exception if there is no binding for the prefix.
  ITEM_FACTORY->createQName(qname,
                            ns,
                            prefix.theStrStore,
                            local.theStrStore);
  return qname;
}


store::Item_t static_context::lookup_qname (
    xqp_string default_ns,
    xqp_string qname,
    const QueryLoc& loc) const
{
  pair<xqp_string, xqp_string> rqname = parse_qname (qname);
  return lookup_qname(default_ns, rqname.first, rqname.second, loc);
}


store::Item_t static_context::lookup_fn_qname(
    xqp_string pfx,
    xqp_string local,
    const QueryLoc& loc) const 
{
  store::Item_t ret;
  try 
  {
    ret = lookup_qname(default_function_ns(), pfx, local, loc);
  }
  catch (error::ZorbaError& e) 
  {
    // rethrow with current location
    ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
  }
  return ret;
}


/*******************************************************************************

  Methods to create normalized qname stings from prefix and local-name pairs, or
  qname items. Normalized qname stings are strings of the form:

  <local name>:<namespace uri>

********************************************************************************/
xqp_string qname_internal_key2 (xqp_string ns, xqp_string local)
{
  return xqpString::concat(local, ":", ns);
}


pair<xqp_string, xqp_string> parse_qname (xqp_string qname)
{
  std::string::size_type n = static_cast<std::string> (qname).find (':');
  return (n == string::npos)
    ? pair<xqp_string, xqp_string> ("", qname)
    : pair<xqp_string, xqp_string> (qname.substr (0, n), qname.substr (n+1));
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
  pair<xqp_string, xqp_string> rqname = parse_qname(qname);
  return qname_internal_key (default_ns, rqname.first, rqname.second);
}


pair<xqp_string, xqp_string> decode_qname_internal_key (xqp_string key) 
{
  pair<xqp_string, xqp_string> result;
  string skey (key);
  int pos = skey.find (':');
  result.first = key.substr (0, pos);
  result.second = key.substr (pos + 1);
  return result;
}


/*******************************************************************************

  Function QName, Arity --> Function Object

********************************************************************************/
xqp_string static_context::fn_internal_key () 
{
  static xqp_string fmap_xqpstring("fmap:");
  return fmap_xqpstring;
}


bool static_context::bind_fn(
    const store::Item* qname,
    function* f,
    int arity,
    bool allow_override) 
{
  xqp_string key = fn_internal_key () + qname_internal_key (qname);

  bool existed = lookup_fmap_func (key, arity) != NULL;

  if (! allow_override && existed)
    return false;

  ctx_value_t v(CTX_ARITY);
  ArityFMap *fmap = NULL;
  bool newMap = ! lookup_once (key, v);

  fmap = newMap ? new ArityFMap : v.fmapValue;

  (*fmap) [arity] = f;

  if (newMap) 
  {
    v.fmapValue = fmap;
    keymap.put (key, v, false);
  }

  return ! existed;
}


function* static_context::lookup_fn(
    xqp_string prefix,
    xqp_string local,
    int arity) const 
{
  return lookup_fn_int(qname_internal_key(default_function_ns(), prefix, local),
                       arity);
}


function* static_context::lookup_resolved_fn(
    xqp_string ns,
    xqp_string local,
    int arity) const 
{
  return lookup_fn_int(qname_internal_key2(ns, local), arity);
}


function* static_context::lookup_fn_int(xqp_string key, int arity) const
{
  xqp_string full_key = xqpString::concat(fn_internal_key() , key);
  function* f = lookup_fmap_func(full_key, arity);
  if (f != NULL)
  {
    return f;
  }
  else
  {
    f = lookup_fmap_func(full_key, VARIADIC_SIG_SIZE);
    return f;
  }
}


void static_context::find_functions (
    const store::Item* qname,
    std::vector<function *>& functions) const
{
  xqp_string key = fn_internal_key () + qname_internal_key (qname);
  set<int> found;
  find_functions_int (key, functions, found);
}


void static_context::find_functions_int (
    xqp_string key,
    std::vector<function *>& functions,
    set<int> &found) const
{
  ArityFMap *fmap = lookup_fmap(key);

  for (ArityFMap::iterator i = fmap->begin (); i != fmap->end (); i++) 
  {
    int arity = (*i).first;

    if (found.find(arity) == found.end ()) 
    {
      found.insert (arity);
      functions.push_back ((*i).second);
    }
  }

  if (parent != NULL)
    static_cast<static_context *>(parent)->find_functions_int (key, functions, found);
}


bool
static_context::bind_external_module( ExternalModule* aModule,
                                      bool aDynamicallyLoaded)
{
  xqp_string lURI = Unmarshaller::getInternalString(aModule->getURI());

  return bind_module(lURI, aModule, aDynamicallyLoaded);
}


StatelessExternalFunction*
static_context::lookup_stateless_external_function(
    const xqp_string& aURI,
    const xqp_string& aLocalName)
{
  // get the module for the given namespace
  ctx_module_t v;
  bool lRes = lookup_module(aURI, v);
  ExternalModule* lModule = 0;

  // if the module is not yet in the static context
  // we try to get it from the URI resolver
  if (!lRes) {
    InternalModuleURIResolver* lStandardModuleResolver = GENV.getModuleURIResolver();
    lModule = lStandardModuleResolver->getExternalModule(
                entity_retrieval_url().getStore(), this);

    // no way to get the module
    if (!lModule) {
      return NULL;
    }

    // remember the module for future use
    bind_external_module(lModule, true);
  } else  {
    lModule = v.module;
  }

  // get the function from this module.
  // return 0 if not found
  return lModule->getExternalFunction(aLocalName.theStrStore.getp());
}


/*******************************************************************************
  
  Type Management : Entity Name --> Type 
  where entity may be variable, the context item, function, document, collection

********************************************************************************/
void static_context::bind_type(xqp_string key, xqtref_t t)
{
  ctx_value_t v(CTX_XQTYPE);
  v.typeValue = &*t;
  keymap.put (key, v);
  RCHelper::addReference (const_cast<XQType *> (t.getp ()));
}


xqtref_t static_context::lookup_type( xqp_string key)
{
  ctx_value_t val(CTX_XQTYPE);
  ZORBA_ASSERT(context_value (key, val));
  return val.typeValue;
}


xqtref_t static_context::lookup_type2( const char *key1, xqp_string key2)
{
  ctx_value_t val(CTX_XQTYPE);
  ZORBA_ASSERT(context_value2 (key1, key2, val));
  return val.typeValue;
}


void static_context::set_context_item_static_type(xqtref_t t)
{
  bind_type("type:context:", t);
}


xqtref_t static_context::context_item_static_type()
{
  return lookup_type("type:context:");
}

#if 0
void static_context::set_function_type(const store::Item *qname, xqtref_t t)
{
  bind_type("type:fun:" + qname_internal_key(default_function_ns(),
                                             qname->getPrefix(),
                                             qname->getLocalName()),
            t);
}


xqtref_t static_context::get_function_type(const store::Item_t qname) 
{
  return lookup_type2("type:fun:", qname_internal_key(default_function_ns(),
                                                      qname->getPrefix(),
                                                      qname->getLocalName()));
}
#endif

void static_context::set_document_type(xqp_string docURI, xqtref_t t)
{
  bind_type("type:doc:" + docURI, t);
}


xqtref_t static_context::get_document_type(const xqp_string docURI) 
{
  return lookup_type2("type:doc:", docURI);
}


/*******************************************************************************

  collection management

********************************************************************************/
void static_context::set_default_collection_type(xqtref_t t)
{
  bind_type("type:defcollection:", t);
}


xqtref_t static_context::default_collection_type()
{
  return lookup_type("type:defcollection:");
}


void static_context::set_collection_type(xqp_string collURI, xqtref_t t)
{
  bind_type("type:collection:" + collURI, t);
}


xqtref_t static_context::get_collection_type(const xqp_string collURI) 
{
  return lookup_type2("type:collection:", collURI);
}


void static_context::bind_collection(
    StaticallyKnownCollection_t& aCollection,
    const QueryLoc& aLoc)
{
  if (theCollectionMap == 0)
    theCollectionMap = new CollectionMap(0, NULL, 8, false);

  if (!theCollectionMap->insert(aCollection->getName(), aCollection))
  {
    ZORBA_ERROR_LOC_DESC_OSS(XDST0001, aLoc,
                             "It is a static error if the expanded QName ("
                             << aCollection->getName()->getStringValue()
                             << ") of a collection"
                             << " is equal (as defined by the eq operator) to the name of "
                             << "another collection in the set of statically known collections."
                            );
  }
}


const StaticallyKnownCollection* static_context::lookup_collection(const store::Item* aName) const
{
  StaticallyKnownCollection_t lColl;

  if (theCollectionMap && theCollectionMap->get(aName, lColl))
    return lColl.getp();
  else
    return 0;
}


template < typename T>
class NameIterator : public store::Iterator
{
private:
  ItemPointerHashMap<rchandle<T> >*          theItems;
  typename ItemPointerHashMap<rchandle<T> >::iterator theIterator;

public:
  NameIterator(ItemPointerHashMap<rchandle<T> >* aItems)
  : theItems(aItems)
  {}
  virtual ~NameIterator() { close(); }
  virtual void open() {
    if (theItems) {
      theIterator = theItems->begin();
    }
  }
  virtual bool next(store::Item_t& aResult) {
    if (!theItems) {
      return false;
    }

    if (theIterator == theItems->end()) {
       aResult = NULL;
      return false;
    }
    else {
      aResult = (*theIterator).first;
      ++theIterator;
      return true;
    }
  }
  virtual void reset() {
    if (theItems) {
      theIterator = theItems->begin();
    }
  }
  virtual void close() {}
};

store::Iterator_t static_context::list_collection_names() const {
  return new NameIterator<StaticallyKnownCollection>(theCollectionMap);
}


/*******************************************************************************

  index management

********************************************************************************/
void static_context::bind_index(
    const store::Item* qname,
    ValueIndex_t& index,
    const QueryLoc& loc)
{
  if (theIndexMap == NULL)
    theIndexMap = new IndexMap(0, NULL, 8, false);

  if (!theIndexMap->insert((store::Item*)qname, index))
  {
    ZORBA_ERROR_LOC_PARAM(XQP0038_INDEX_IS_ALREADY_DECLARED, loc,
                          qname->getStringValue(),  "");
  }
}


ValueIndex* static_context::lookup_index(const store::Item* qname) const
{
  ValueIndex_t index;

  if (theIndexMap->get(qname, index))
    return index.getp();
  else
    return NULL;
}

store::Iterator_t static_context::list_index_names() const {
  return new NameIterator<ValueIndex>(theIndexMap);
}

/*******************************************************************************

  collation management

********************************************************************************/
bool static_context::has_collation_uri(const xqp_string& aURI) const
{
  return lookup_collation(aURI);
}


xqp_string static_context::default_collation_uri() const
{
  xqp_string lURI;
  if (!lookup_default_collation(lURI))
  {
    lURI = ZORBA_DEF_COLLATION_NS;
  }
  return lURI;
}


void static_context::set_default_collation_uri(const xqp_string& aURI)
{
  xqp_string lURI = resolve_relative_uri(aURI, xqp_string());

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


void static_context::add_collation(const xqp_string& aURI)
{
  xqp_string lURI = resolve_relative_uri(aURI, xqp_string());

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


XQPCollator* static_context::create_collator(const xqp_string& aURI)
{
  return CollationFactory::createCollator(aURI); 
}


CollationCache* static_context::get_collation_cache() 
{
  if (!theCollationCache)
    theCollationCache = new CollationCache(this);

  return  theCollationCache;
}


/*******************************************************************************

  option management

********************************************************************************/
bool static_context::lookup_option(
    const xqp_string& ns,
    const xqp_string& localname,
    xqp_string& option) const
{
  xqp_string s = ns + localname;
  if (lookup_once2("option:", s, option))
    return true;
  return parent == NULL ? false : dynamic_cast<static_context*>(parent)->lookup_option(ns, localname, option);
}


bool static_context::bind_option(
    const xqp_string& ns,
    const xqp_string& localname,
    const xqp_string& option)
{
  xqp_string s = ns + localname;
  return str_keymap.put2("option:", s, option);
}


/*******************************************************************************
  Base Uri Computation

  int:from_prolog_baseuri          --> uri
  int:baseuri                      --> uri
  int:encapsulating_entity_baseuri --> uri
  int:entity_retrieval_url         --> uri

  int:current_absolute_baseuri     --> uri

  The from_prolog_baseuri is the one declared in the prolog. The baseuri is set
  explicitly from the C++/C api. If both the from_prolog_baseuri and the baseuri
  are set, the from_prolog_baseuri hides the baseuri.

  The entity_retrieval_url is set by default to the name of file containing the
  query we are running. It may also be set explicitly from the C++/C api. 
********************************************************************************/
xqp_string static_context::final_baseuri () 
{
  // cached value
  string abs_base_uri = current_absolute_baseuri();

  if(abs_base_uri.empty()) 
  {
    compute_current_absolute_baseuri();
    abs_base_uri = current_absolute_baseuri();
  }

  // won't happen -- we default to a non-empty URI
  if(abs_base_uri.empty()) 
  {
    ZORBA_ERROR_DESC( XPST0001, "empty base URI");
    return "";
  }
  
  return abs_base_uri;
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

  if (!prolog_baseuri.empty()) 
  {
    try 
    {
      URI lCheckValid(prolog_baseuri);
      // is already absolute baseuri
      set_current_absolute_baseuri(lCheckValid.toString());
      return; // valid (absolute) uri
    }
    catch (error::ZorbaError&) 
    {
      // assume it's relative and go on
    }
  }

  if (!prolog_baseuri.empty()) 
  {
    /// is relative, needs to be resolved
    ee_baseuri = encapsulating_entity_baseuri();
    if(!ee_baseuri.empty()) 
    {
      set_current_absolute_baseuri(make_absolute_uri(prolog_baseuri, ee_baseuri));
      return;
    }

    loaded_uri = entity_retrieval_url();
    if(!loaded_uri.empty()) 
    {
      set_current_absolute_baseuri(make_absolute_uri(prolog_baseuri, loaded_uri));
      return;
    }
    
    set_current_absolute_baseuri (make_absolute_uri(prolog_baseuri, implementation_baseuri()));
    return;
  }

  ee_baseuri = encapsulating_entity_baseuri();
  if(!ee_baseuri.empty()) 
  {
    set_current_absolute_baseuri(ee_baseuri);
    return;
  }

  loaded_uri = entity_retrieval_url();
  if(!loaded_uri.empty()) 
  {
    set_current_absolute_baseuri(loaded_uri);
    return;
  }

  set_current_absolute_baseuri (implementation_baseuri());
  return;
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


xqp_string static_context::entity_retrieval_url() const 
{ 
  xqp_string val; 
  GET_CONTEXT_VALUE(entity_retrieval_url, val); 
  return val;                   
}                               
                  
                
void static_context::set_entity_retrieval_url(xqp_string val) 
{ 
  bind_str ("int:entity_retrieval_url", val, MAX_ZORBA_ERROR_CODE);      
  set_current_absolute_baseuri ("");
}


xqp_string static_context::resolve_relative_uri (
    xqp_string uri,
    xqp_string abs_base_uri,
    bool validate) 
{
  return make_absolute_uri (uri,
                            abs_base_uri.empty () ? final_baseuri () : abs_base_uri,
                            validate);
}


xqp_string static_context::make_absolute_uri(
    xqp_string uri,
    xqp_string base_uri,
    bool validate) 
{
  URI resolved_uri(base_uri, uri, validate);
  return resolved_uri.toString();
}


/*******************************************************************************
  Merge the ststic context of a module with this static context. Only functions
  and variables defined in te module are included in this static context. If
  a module variable or function already appears in this context, the method
  returns false.
********************************************************************************/
bool static_context::import_module(const static_context* module, const QueryLoc& loc) 
{
  checked_vector<serializable_hashmap<ctx_value_t>::entry>::const_iterator it;
  const char* keybuff;
  
  for(it = module->keymap.begin(); it != module->keymap.end(); ++it) 
  {
    keybuff = (*it).key.c_str();
    const ctx_value_t *val = &(*it).val;

    if (0 == strncmp(keybuff, "var:", 4) && 0 != strncmp(keybuff, "var:$$", 6)) 
    {
      if (! bind_expr (keybuff, val->exprValue))
        return false;
    }
    else if (0 == strncmp(keybuff, "fn:", 3))
    {
      if (! bind_func (keybuff, val->functionValue))
        return false;
    }
    else if (0 == strncmp(keybuff, "fmap:", 5))
    {
      ctx_value_t val2(CTX_ARITY);
      val2.fmapValue = new ArityFMap (*val->fmapValue);
      keymap.put (keybuff, val2);
    }
  }

  if (module->theCollectionMap)
  {
    CollectionMap::iterator coll_iter = module->theCollectionMap->begin();
    CollectionMap::iterator coll_end = module->theCollectionMap->end();
    for (; coll_iter != coll_end; ++ coll_iter)
    {
      if (theCollectionMap == 0) 
      {
        theCollectionMap = new CollectionMap(0, 0, 8, false);
      }

      std::pair<const store::Item*, StaticallyKnownCollection_t > pair = (*coll_iter);

      if (!theCollectionMap->insert(pair.first, pair.second)) 
      {
        ZORBA_ERROR_LOC_DESC_OSS(XDST0008, loc,
                                 "It is a static error if the expanded QName ("
                                 << pair.second->getName()->getStringValue()
                                 << ") of a collection declared in an imported module is equal "
                                 << "(as defined by the eq operator) to the expanded QName of a "
                                 << "collection declared in the importing module or in another "
                                 << "imported module (even if the declarations are consistent)."
                                );
      }
    }
  }

  if (module->theIndexMap)
  {
    IndexMap::iterator idx_iter = module->theIndexMap->begin();
    IndexMap::iterator idx_end = module->theIndexMap->end();
    for (; idx_iter != idx_end; ++idx_iter)
    {
      std::pair<const store::Item*, rchandle<ValueIndex> > pair = (*idx_iter);

      if (theIndexMap == NULL)
      {
        theIndexMap = new IndexMap(0, NULL, 8, false);
      }

      if (!theIndexMap->insert((store::Item*)pair.first, pair.second))
      {
        ZORBA_ERROR_LOC_PARAM(XQP0038_INDEX_IS_ALREADY_DECLARED, loc,
                              pair.first->getStringValue()->c_str(), "");
      }
    }
  }

  return true;
}


/*******************************************************************************
  URI resolvers
********************************************************************************/
void
static_context::set_document_uri_resolver(InternalDocumentURIResolver* aDocResolver)
{
  delete theDocResolver;

  theDocResolver = aDocResolver;
}

InternalDocumentURIResolver*
static_context::get_document_uri_resolver()
{
  if ( theDocResolver != 0 )
    return theDocResolver;
  return parent!=NULL?dynamic_cast<static_context*>(parent)->get_document_uri_resolver():0;
}

void
static_context::set_collection_uri_resolver(InternalCollectionURIResolver* aColResolver)
{
  delete theColResolver;

  theColResolver = aColResolver;
}

InternalCollectionURIResolver*
static_context::get_collection_uri_resolver()
{
  if ( theColResolver != 0 )
    return theColResolver;
  return parent!=NULL?dynamic_cast<static_context*>(parent)->get_collection_uri_resolver():0;
}

void
static_context::set_schema_uri_resolver(InternalSchemaURIResolver* aSchemaResolver)
{
  delete theSchemaResolver;

  theSchemaResolver = aSchemaResolver;
}

InternalSchemaURIResolver*
static_context::get_schema_uri_resolver()
{
  if ( theSchemaResolver != 0 )
    return theSchemaResolver;
  return parent!=NULL?dynamic_cast<static_context*>(parent)->get_schema_uri_resolver():0;
}

void
static_context::add_module_uri_resolver(InternalModuleURIResolver* aModuleResolver)
{
  theModuleResolvers.push_back(aModuleResolver);
}

void
static_context::get_module_uri_resolvers(
    std::vector<InternalModuleURIResolver*>& lResolvers
  )
{
  if (parent!=NULL) {
    static_cast<static_context*>(parent)->get_module_uri_resolvers(lResolvers);
}
  lResolvers.insert(lResolvers.end(),
                    theModuleResolvers.begin(),
                    theModuleResolvers.end());
}

void
static_context::remove_module_uri_resolver(InternalModuleURIResolver* aResolver)
{
  for (std::vector<InternalModuleURIResolver*>::iterator 
        lIter = theModuleResolvers.begin();
       lIter != theModuleResolvers.end(); ++lIter) {
    if (aResolver == *lIter) {
      theModuleResolvers.erase(lIter);
      return; // no duplicates in the vector
    }
}
}

void
static_context::set_trace_stream(std::ostream& os)
{
  theTraceStream = &os;
}

std::ostream*
static_context::get_trace_stream() const
{
  if (theTraceStream)
    return theTraceStream;
  return parent == NULL ? &std::cerr : dynamic_cast<static_context*>(parent)->get_trace_stream();
}

void
static_context::getVariables(std::vector<std::string>& aResult) const
{
  if (parent)
    static_cast<static_context*>(parent)->getVariables(aResult);

  std::vector<zorba::serializable_hashmap<ctx_value_t>::entry>::const_iterator it;
  for (it = keymap.begin(); it != keymap.end(); it++) {
    const std::string& lKey = (*it).key;
    ctx_value_t lVal = (*it).val;
    if (lKey.find("var:") == 0) {
      ZORBA_ASSERT(dynamic_cast<var_expr*>(lVal.exprValue));
      var_expr* lExpr = static_cast<var_expr*>(lVal.exprValue);
      var_expr::var_kind lKind = lExpr->get_kind();
      if (lKind == var_expr::prolog_var) {
        aResult.push_back("global");
      } else {
        aResult.push_back("local");
      }
      std::string lType;
      if (lExpr->get_type() == NULL || lExpr->get_type()->get_qname() == NULL) {
        lType = "anyType:http://www.w3.org/2001/XMLSchema";
      } else {
        store::Item_t lQname = lExpr->get_type()->get_qname();
        lType = lQname->getLocalName()->c_str();
        lType += ":";
        lType += lQname->getNamespace()->c_str();
      }
      if (lExpr->is_sequential()) {
        lType += "*";
      }
      aResult.push_back(lType);
      aResult.push_back(lKey.substr(4, lKey.size() - 5));
    }
  }
}

void
static_context::getVariables(std::vector<var_expr_t>& aResult) const
{
  if (parent)
    static_cast<static_context*>(parent)->getVariables(aResult);

  std::vector<zorba::serializable_hashmap<ctx_value_t>::entry>::const_iterator it;
  for (it = keymap.begin(); it != keymap.end(); it++) {
    const std::string& lKey = (*it).key;
    if (lKey.find("var:") == 0) {
      aResult.push_back(static_cast<var_expr*>((*it).val.exprValue));
    }
  }
}

} /* namespace zorba */

