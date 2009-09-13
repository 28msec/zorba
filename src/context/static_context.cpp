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
#include "context/decimal_format.h"


#include "compiler/expression/expr_base.h"
#include "compiler/expression/var_expr.h"

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

#include "indexing/value_index.h"


using namespace std;
namespace zorba {

#define ITEM_FACTORY (GENV.getStore().getItemFactory())

SERIALIZABLE_CLASS_VERSIONS(context)
END_SERIALIZABLE_CLASS_VERSIONS(context)

SERIALIZABLE_CLASS_VERSIONS(context::ctx_value_t)
END_SERIALIZABLE_CLASS_VERSIONS(context::ctx_value_t)

SERIALIZABLE_CLASS_VERSIONS(static_context)
END_SERIALIZABLE_CLASS_VERSIONS(static_context)


/*******************************************************************************
  Class context methods
********************************************************************************/
function* context::lookup_fmap_func (xqp_string key, int arity) const 
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
  if (str_keymap.put (key, v))
    if (err != MAX_ZORBA_ERROR_CODE)
      ZORBA_ERROR(err);
}


void context::bind_str2 (
    const char *key1,
    xqp_string key2,
    xqp_string v,
    XQUERY_ERROR err) 
{
  if (str_keymap.put2 (key1, key2, v))
    if (err != MAX_ZORBA_ERROR_CODE)
      ZORBA_ERROR(err);
}


bool context::bind_expr (xqp_string key, expr *e) 
{
  ctx_value_t v(CTX_EXPR);
  v.exprValue = e;
  if (keymap.put (key, v, false))
    return false;
  RCHelper::addReference (e);
  return true;
}


bool context::bind_expr2 (const char *key1, xqp_string key2, expr *e) 
{
  ctx_value_t v(CTX_EXPR);
  v.exprValue = e;
  if (keymap.put2 (key1, key2, v, false))
    return false;
  RCHelper::addReference (e);
  return true;
}


bool context::bind_func (xqp_string key, function *f) 
{
  ctx_value_t v(CTX_FUNCTION);
  v.functionValue = f;
  if (keymap.put (key, v, false))
    return false;
  RCHelper::addReference (f);
  return true;
}


bool context::bind_func2 (const char *key1, xqp_string key2, function *f) 
{
  ctx_value_t v(CTX_FUNCTION);
  v.functionValue = f;
  if (keymap.put2 (key1, key2, v, false))
    return false;
  RCHelper::addReference (f);
  return true;
}


bool context::bind_stateless_function(xqp_string key, StatelessExternalFunction* f) 
{
  ctx_value_t v(CTX_STATELESS_EXTERNAL_FUNC);
  v.stateless_function = f;
  if (keymap.put (key, v, false))
    return false;
  return true;
}

bool context::bind_index(const char *key1, const xqp_string& key2, ValueIndex *vi)
{
  ctx_value_t v(CTX_VALUE_INDEX);
  v.valueIndex = vi;
  if (keymap.put2 (key1, key2, v, false))
    return false;
  RCHelper::addReference (vi);
  return true;
}

bool context::check_parent_is_root()
{
  return parent == (context*)&GENV_ROOT_STATIC_CONTEXT;
}

void context::set_parent_as_root()
{
  parent = &GENV_ROOT_STATIC_CONTEXT;
}

void context::ctx_value_t::serialize(::zorba::serialization::Archiver &ar)
{
  SERIALIZE_ENUM(enum ctx_value_type, type);
  switch(type)
  {
  case CTX_EXPR:
    //if(!ar.is_serializing_out())
    //  exprValue = NULL;//don't serialize this
    ar & exprValue;
    if(!ar.is_serializing_out() && exprValue)
      RCHelper::addReference (exprValue);
    break;
  case CTX_FUNCTION:
  {
      //if(!ar.is_serializing_out())
    //  functionValue = NULL;//don't serialize this
    //ar & functionValue;
    SERIALIZE_FUNCTION(functionValue);
    if(!ar.is_serializing_out() && functionValue)
      RCHelper::addReference (functionValue);
  }
    break;
  case CTX_ARITY:
    ar & fmapValue;
    break;
  case CTX_INT:
    ar & intValue;
    break;
  case CTX_BOOL:
    ar & boolValue;
    break;
  case CTX_VALUE_INDEX:
    ar & valueIndex;
    if(!ar.is_serializing_out() && valueIndex)
      RCHelper::addReference (valueIndex);
    break;
  case CTX_XQTYPE:
  case CTX_STATELESS_EXTERNAL_FUNC:
  default:
    if(!ar.is_serializing_out())
      typeValue = NULL;//don't serialize this
    break;
  }
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
  theModuleResolver(0),
  theTraceStream(0),
  theCollationCache(0)
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
  theModuleResolver(0),
  theTraceStream(0),
  theCollationCache(0)
{
  if (parent != NULL)
    RCHelper::addReference (parent);
}


static_context::static_context(::zorba::serialization::Archiver &ar)
  :
  context(ar)
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
  checked_vector<serializable_hashmap<ctx_value_t>::entry>::const_iterator   it;
  const char    *keybuff;
  
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
      } else if (0 == strncmp(keybuff, "vindex:", 7)) {
        RCHelper::removeReference(const_cast<ValueIndex *>(val->valueIndex));
      }
    }
  }

  set_document_uri_resolver(0);
  set_collection_uri_resolver(0);
  set_schema_uri_resolver(0);
  set_module_uri_resolver(0);

  if (parent)
    RCHelper::removeReference (parent);
}


/*******************************************************************************

********************************************************************************/
void static_context::serialize(::zorba::serialization::Archiver &ar)
{
  serialize_baseclass(ar, (context*)this);
  SERIALIZE_TYPEMANAGER_RCHANDLE(TypeManager, typemgr);
  //+ar & theDocResolver;
  //+ar & theColResolver;
  //+ar & theSchemaResolver;
  //+ar & theModuleResolver;
  if(!ar.is_serializing_out())
  {
    theDocResolver = NULL;
    theColResolver = NULL;
    theSchemaResolver = NULL;
    theModuleResolver = NULL;//user has to set up again the uri resolvers after reloading the plan
    theTraceStream = &std::cerr;
  }
  //+ar & theGlobalVars;
  //+ar & theDecimalFormats;
  ar & theCollationCache;
}


/*******************************************************************************

********************************************************************************/
void static_context::set_typemanager(rchandle<TypeManager> typemgr_)
{
  typemgr = typemgr_;
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

DECL_STR_PARAM (static_context, default_function_namespace, XQST0066)
DECL_STR_PARAM (static_context, default_elem_type_ns, XQST0066)

DECL_STR_PARAM (static_context, current_absolute_baseuri, MAX_ZORBA_ERROR_CODE)

DECL_STR_PARAM_TRIGGER (static_context, encapsulating_entity_baseuri, MAX_ZORBA_ERROR_CODE, set_current_absolute_baseuri (""))


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
  namespace uri. It return false if no such mapping is found, or the ns uri in the
  mapping is empty. Otherwise, it returns true and the associated uri.

********************************************************************************/
bool static_context::lookup_ns (xqp_string prefix, xqp_string &ns) const 
{
  return context_value2 ("ns:", prefix, ns) && ! ns.empty();
}

bool
static_context::lookup_option(const xqp_string& ns, const xqp_string& localname, xqp_string& option) const
{
  xqp_string s = ns + localname;
  if (lookup_once2("option:", s, option))
    return true;
  return parent == NULL ? false : dynamic_cast<static_context*>(parent)->lookup_option(ns, localname, option);
}

bool
static_context::bind_option(const xqp_string& ns, const xqp_string& localname, const xqp_string& option)
{
  xqp_string s = ns + localname;
  return str_keymap.put2("option:", s, option);
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


xqp_string static_context::lookup_ns (xqp_string prefix, const QueryLoc& loc, const XQUERY_ERROR& err) const 
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


store::Item_t static_context::lookup_fn_qname (xqp_string pfx, xqp_string local, const QueryLoc& loc) const 
{
  store::Item_t ret;
  try 
  {
    ret = lookup_qname (default_function_namespace (), pfx, local, loc);
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
  return "fmap:";
}


bool static_context::bind_fn (
    const store::Item *qname,
    function *f,
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


function* static_context::lookup_builtin_fn (xqp_string local, int arity)
{
  function* f = GENV.getRootStaticContext().
                lookup_fn_int (qname_internal_key2 (XQUERY_FN_NS, local), arity);

  if (f == NULL)
    ZORBA_NOT_IMPLEMENTED ("built-in `" + local + "/" + to_string (arity) + "'");
  return f;
}


function* static_context::lookup_fn (
    xqp_string prefix,
    xqp_string local,
    int arity) const 
{
  return lookup_fn_int (qname_internal_key (default_function_namespace (),
                                            prefix,
                                            local),
                        arity);
}


function* static_context::lookup_resolved_fn (
    xqp_string ns,
    xqp_string local,
    int arity) const 
{
  return lookup_fn_int (qname_internal_key2 (ns, local), arity);
}


function* static_context::lookup_fn_int (xqp_string key, int arity) const
{
  function* f = lookup_fmap_func (fn_internal_key() + key, arity);
  if (f != NULL)
  {
    return f;
  }
  else
  {
    f = lookup_fmap_func (fn_internal_key () + key, VARIADIC_SIG_SIZE);
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


bool static_context::bind_stateless_external_function(
    StatelessExternalFunction* aExternalFunction) 
{
  xqpString lLocalName = Unmarshaller::getInternalString(aExternalFunction->getLocalName());
  xqpString lURI = Unmarshaller::getInternalString(aExternalFunction->getURI());

  return bind_stateless_function(xqpString::concat(lLocalName,":",lURI), aExternalFunction);
}


StatelessExternalFunction * static_context::lookup_stateless_external_function(
    xqp_string aPrefix,
    xqp_string aLocalName)
{
  return lookup_stateless_function(qname_internal_key(default_function_namespace(),
                                                      aPrefix,
                                                      aLocalName)); 
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


void static_context::add_variable_type(
    const xqp_string var_name, 
    xqtref_t var_type)
{
  bind_type("type:var:" + qname_internal_key("", var_name), var_type);
}


xqtref_t static_context::get_variable_type(store::Item *var_name)
{
  return lookup_type2("type:var:", qname_internal_key("",
                                                      var_name->getPrefix(),
                                                      var_name->getLocalName()));
}


void static_context::set_context_item_static_type(xqtref_t t)
{
  bind_type("type:context:", t);
}


xqtref_t static_context::context_item_static_type()
{
  return lookup_type("type:context:");
}


void static_context::set_function_type(const store::Item *qname, xqtref_t t)
{
  bind_type("type:fun:" + qname_internal_key(default_function_namespace(),
                                             qname->getPrefix(),
                                             qname->getLocalName()),
            t);
}


xqtref_t static_context::get_function_type(const store::Item_t qname) 
{
  return lookup_type2("type:fun:", qname_internal_key(default_function_namespace(),
                                                      qname->getPrefix(),
                                                      qname->getLocalName()));
}


void static_context::set_document_type(xqp_string docURI, xqtref_t t)
{
  bind_type("type:doc:" + docURI, t);
}


xqtref_t static_context::get_document_type(const xqp_string docURI) 
{
  return lookup_type2("type:doc:", docURI);
}


void static_context::set_default_collection_type(xqtref_t t)
{
  bind_type("type:defcollection:", t);
}


xqtref_t    static_context::default_collection_type()
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


xqp_string static_context::entity_retrieval_url () const 
{ 
  xqp_string val; 
  GET_CONTEXT_VALUE (entity_retrieval_url, val); 
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
bool static_context::import_module (const static_context *module) 
{
  checked_vector<serializable_hashmap<ctx_value_t>::entry>::const_iterator   it;
  const char    *keybuff;
  
  for(it = module->keymap.begin(); it!=module->keymap.end(); it++) 
  {
    keybuff = (*it).key.c_str();
    const ctx_value_t *val = &(*it).val;

    if (0 == strncmp(keybuff, "var:", 4) && 0 != strncmp(keybuff, "var:$$", 6)) {
      if (! bind_expr (keybuff, val->exprValue))
        return false;
    } else if (0 == strncmp(keybuff, "fn:", 3)) {
      if (! bind_func (keybuff, val->functionValue))
        return false;
    } else if (0 == strncmp(keybuff, "fmap:", 5)) {
      ctx_value_t val2(CTX_ARITY);
      val2.fmapValue = new ArityFMap (*val->fmapValue);
      keymap.put (keybuff, val2);
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
  return dynamic_cast<static_context*>(parent)->get_document_uri_resolver();
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
  return dynamic_cast<static_context*>(parent)->get_collection_uri_resolver();
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
  return dynamic_cast<static_context*>(parent)->get_schema_uri_resolver();
}

void
static_context::set_module_uri_resolver(InternalModuleURIResolver* aModuleResolver)
{
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
    if (lKey.find("var:") == 0) {
      aResult.push_back("local");
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

