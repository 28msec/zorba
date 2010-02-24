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

#include "zorbaserialization/serialization_engine.h"

#include "zorbautils/strutil.h"
#include "zorbautils/hashmap_strh.h"
#define ZORBA_UTILS_HASHMAP_WITH_SERIALIZATION
#include "zorbautils/hashmap_itemp.h"
#undef ZORBA_UTILS_HASHMAP_WITH_SERIALIZATION

#include "context/static_context_consts.h"
#include "context/static_context.h"
#include "context/root_static_context.h"
#include "context/namespace_context.h"
#include "context/uri_resolver_wrapper.h"
#include "context/standard_uri_resolvers.h"
#include "context/decimal_format.h"
#include "context/sctx_map_iterator.h"

#include "compiler/expression/expr_base.h"
#include "compiler/expression/var_expr.h"
#include "compiler/xqddf/collection_decl.h"
#include "compiler/xqddf/value_index.h"
#include "compiler/xqddf/value_ic.h"

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
#include "store/api/iterator.h"


using namespace std;

namespace zorba 
{

#define ITEM_FACTORY (GENV.getStore().getItemFactory())


SERIALIZABLE_CLASS_VERSIONS(static_context::ctx_value_t)
END_SERIALIZABLE_CLASS_VERSIONS(static_context::ctx_value_t)

SERIALIZABLE_CLASS_VERSIONS(static_context::ctx_module_t)
END_SERIALIZABLE_CLASS_VERSIONS(static_context::ctx_module_t)

SERIALIZABLE_CLASS_VERSIONS(static_context)
END_SERIALIZABLE_CLASS_VERSIONS(static_context)


static pair<xqp_string, xqp_string> parse_qname(xqp_string qname)
{
  std::string::size_type n = static_cast<std::string> (qname).find (':');
  return (n == string::npos)
    ? pair<xqp_string, xqp_string> ("", qname)
    : pair<xqp_string, xqp_string> (qname.substr (0, n), qname.substr (n+1));
}


/***************************************************************************//**
 Debugging purposes
********************************************************************************/
std::ostream& operator<<(std::ostream& stream, const static_context::ctx_value_t& object)
{
  stream << (int)object.type;
  return stream;
}


/***************************************************************************//**

********************************************************************************/
void static_context::ctx_value_t::serialize(::zorba::serialization::Archiver& ar)
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
  default:
    if(!ar.is_serializing_out())
      typeValue = NULL;//don't serialize this
    break;
  }
}


/***************************************************************************//**

********************************************************************************/
void static_context::ctx_module_t::serialize(serialization::Archiver& ar)
{
  if(ar.is_serializing_out())
  {
    // serialize out: the uri of the module that is used in this plan

    xqp_string lURI = Unmarshaller::getInternalString(module->getURI());
    xqpStringStore_t lURIStore = lURI.getStore();
	  ar.set_is_temp_field(true);
    ar.dont_allow_delay();
    ar & lURIStore;
	  ar.set_is_temp_field(false);
    ar & dyn_loaded_module;
  }
  else
  {
    // serialize in: load the serialized uri of the module and
    //               get the externalmodule from the user's
    //               registered serialization callback
    xqpStringStore_t lURIStore = 0;
	  ar.set_is_temp_field(true);
    ar & lURIStore;
	  ar.set_is_temp_field(false);
    ar & dyn_loaded_module;

    if (dyn_loaded_module)
    {
      InternalModuleURIResolver* lStandardModuleResolver
        = GENV.getModuleURIResolver();

      module = lStandardModuleResolver->getExternalModule(
              lURIStore->str(), GENV_ROOT_STATIC_CONTEXT);

      // no way to get the module
      if (!module)
      {
        ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                             "Couldn't load pre-compiled query because"
                             << " the external module " << lURIStore
                             << " is not available to be loaded from a"
                             << " dynamic library.");
      }
    }
    else
    {
      // class registered by the user
      SerializationCallback* lCallback = ar.getUserCallback();
      if (!lCallback)
      {
        ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                             "Couldn't load pre-compiled query because"
                             << " the external module " << lURIStore
                             << " is required but no SerializationCallback is"
                             << " given for retrieving that module.");
      }

      // the life-cycle of the module is managed by the user
      module = lCallback->getExternalModule(lURIStore.getp());
      if (!module)
      {
        ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                             "Couldn't load pre-compiled query because"
                             << " the external module " << lURIStore
                             << " is not available using the registered"
                             << " SerializationCallback");
      }
    }
  }
}


template<class V> bool static_context::context_value(xqp_string key, V &val) const
{
  if (lookup_once(key, val))
    return true;
  else
    return theParent == NULL ? false : theParent->context_value (key, val);
}


// Explicit template instantiation
template bool static_context::context_value<static_context::ctx_value_t>(
    xqp_string key,
    static_context::ctx_value_t& val) const;


bool static_context::bind_expr (xqp_string key, expr *e)
{
  ctx_value_t v(CTX_EXPR);
  v.exprValue = e;

  // return false if the key was in the map already
  if (keymap.put (key, v, false))
    return false;

  RCHelper::addReference (e);
  return true;
}


bool static_context::bind_expr2 (const char *key1, xqp_string key2, expr *e)
{
  ctx_value_t v(CTX_EXPR);
  v.exprValue = e;

  // return false if the key was in the map already
  if (keymap.put2 (key1, key2, v, false))
    return false;

  RCHelper::addReference (e);
  return true;
}


bool static_context::bind_module(xqp_string uri, ExternalModule* m,
                          bool dyn_loaded)
{
  ctx_module_t v;
  v.module = m;
  v.dyn_loaded_module = dyn_loaded;
  return !modulemap.put (uri, v, false);
}


std::vector<xqp_string>* static_context::get_all_keymap_keys() const
{
  std::auto_ptr<std::vector<xqp_string> > keys;
  if (theParent != NULL)
    keys.reset(theParent->get_all_keymap_keys());
  else
    keys.reset(new std::vector<xqp_string>);

  for (unsigned int i=0; i<keymap.size(); i++)
    keys->push_back(keymap.getentryKey(i));

  return keys.release();
}



/***************************************************************************//**
  Default Constructor.
********************************************************************************/
static_context::static_context()
  :
  theParent(NULL),
  theTraceStream(NULL),
  theBaseUriInfo(NULL),
  theDocResolver(0),
  theColResolver(0),
  theNamespaceBindings(NULL),
  theFunctionMap(NULL),
  theFunctionArityMap(NULL),
  theW3CCollectionMap(NULL),
  theCollectionMap(NULL),
  theIndexMap(NULL),
  theICMap(NULL),
  theCollationMap(NULL),
  theDefaultCollation(NULL),
  theOptionMap(NULL),
  theXQueryVersion(StaticContextConsts::xquery_version_unknown),
  theXPathCompatibility(StaticContextConsts::xpath_unknown),
  theConstructionMode(StaticContextConsts::cons_unknown),
  theInheritMode(StaticContextConsts::inherit_unknown),
  thePreserveMode(StaticContextConsts::preserve_unknown),
  theOrderingMode(StaticContextConsts::ordering_unknown),
  theEmptyOrderMode(StaticContextConsts::empty_order_unknown),
  theBoundarySpaceMode(StaticContextConsts::boundary_space_unknown),
  theValidationMode(StaticContextConsts::validation_unknown),
  theDecimalFormats(NULL)
{
}


/*******************************************************************************

********************************************************************************/
static_context::static_context(static_context* parent)
  :
  theParent(parent),
  theTraceStream(NULL),
  theBaseUriInfo(NULL),
  theDocResolver(0),
  theColResolver(0),
  theNamespaceBindings(NULL),
  theFunctionMap(NULL),
  theFunctionArityMap(NULL),
  theW3CCollectionMap(NULL),
  theCollectionMap(0),
  theIndexMap(NULL),
  theICMap(NULL),
  theCollationMap(NULL),
  theDefaultCollation(NULL),
  theOptionMap(NULL),
  theXQueryVersion(StaticContextConsts::xquery_version_unknown),
  theXPathCompatibility(StaticContextConsts::xpath_unknown),
  theConstructionMode(StaticContextConsts::cons_unknown),
  theInheritMode(StaticContextConsts::inherit_unknown),
  thePreserveMode(StaticContextConsts::preserve_unknown),
  theOrderingMode(StaticContextConsts::ordering_unknown),
  theEmptyOrderMode(StaticContextConsts::empty_order_unknown),
  theBoundarySpaceMode(StaticContextConsts::boundary_space_unknown),
  theValidationMode(StaticContextConsts::validation_unknown),
  theDecimalFormats(NULL)
{
  if (theParent != NULL)
    RCHelper::addReference(theParent);
}


/*******************************************************************************

********************************************************************************/
static_context::static_context(::zorba::serialization::Archiver& ar)
  :
  SimpleRCObject(ar),
  keymap(ar),
  theTraceStream(NULL),
  theBaseUriInfo(NULL),
  theDocResolver(0),
  theColResolver(0),
  theNamespaceBindings(NULL),
  theFunctionMap(NULL),
  theFunctionArityMap(NULL),
  theW3CCollectionMap(NULL),
  theCollectionMap(0),
  theIndexMap(0),
  theICMap(0),
  theCollationMap(NULL),
  theDefaultCollation(NULL),
  theOptionMap(NULL),
  theXQueryVersion(StaticContextConsts::xquery_version_unknown),
  theXPathCompatibility(StaticContextConsts::xpath_unknown),
  theConstructionMode(StaticContextConsts::cons_unknown),
  theInheritMode(StaticContextConsts::inherit_unknown),
  thePreserveMode(StaticContextConsts::preserve_unknown),
  theOrderingMode(StaticContextConsts::ordering_unknown),
  theEmptyOrderMode(StaticContextConsts::empty_order_unknown),
  theBoundarySpaceMode(StaticContextConsts::boundary_space_unknown),
  theValidationMode(StaticContextConsts::validation_unknown),
  theDecimalFormats(NULL)
{
}


/***************************************************************************//**
  Destructor.
********************************************************************************/
static_context::~static_context()
{
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
      if (0 == strncmp(keybuff, "type:", 5)) 
      {
        RCHelper::removeReference (const_cast<XQType *> (val->typeValue));
      }
      else if (0 == strncmp(keybuff, "var:", 4)) 
      {
        RCHelper::removeReference (const_cast<expr *> (val->exprValue));
      }
    }
  }

  checked_vector<serializable_hashmap<ctx_module_t>::entry>::const_iterator it2;
  for(it2 = modulemap.begin(); it2 != modulemap.end(); it2++)
  {
    const ctx_module_t *val = &(*it2).val;
    if (val->dyn_loaded_module) 
    {
      val->module->destroy();
    }
  }

  set_document_uri_resolver(0);
  set_collection_uri_resolver(0);

  if (theFunctionMap)
    delete theFunctionMap;

  if (theFunctionArityMap)
  {
    FunctionArityMap::iterator ite = theFunctionArityMap->begin();
    FunctionArityMap::iterator end = theFunctionArityMap->end(); 
    for (; ite != end; ++ite)
    {
      delete (*ite).second;
    }

    delete theFunctionArityMap;
  }

  if (theW3CCollectionMap)
    delete theW3CCollectionMap;

  if (theCollectionMap)
    delete theCollectionMap;

  if (theIndexMap)
    delete theIndexMap;

  if (theICMap)
    delete theICMap;

  if (theNamespaceBindings)
    delete theNamespaceBindings;

  if (theDefaultCollation)
    delete theDefaultCollation;

  if (theCollationMap) 
  {
    CollationMap::iterator ite = theCollationMap->begin();
    CollationMap::iterator end = theCollationMap->end();
    for ( ; ite != end ; ++ite)
    {
      delete ite->second;
    }

    delete theCollationMap;
    theCollationMap = 0;
  }

  if (theOptionMap)
    delete theOptionMap;

  if (theDecimalFormats)
    delete theDecimalFormats;

  if (theBaseUriInfo)
    delete theBaseUriInfo;

  if (theParent)
    RCHelper::removeReference(theParent);
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
    lUserDocResolver = ((theDocResolver != NULL) && (dynamic_cast<StandardDocumentURIResolver*>(theDocResolver) == NULL));
    lUserColResolver = ((theColResolver != NULL) && (dynamic_cast<StandardCollectionURIResolver*>(theColResolver) == NULL));

	  ar.set_is_temp_field(true);
    ar & lUserDocResolver;
    ar & lUserColResolver;
	  ar.set_is_temp_field(false);
  }
  else
  {
    // serialize in: set the document and collection resolvers
    //               use one by the user or use the default
    //               if null is returned
    SerializationCallback* lCallback = ar.getUserCallback();

	  ar.set_is_temp_field(true);
    ar & lUserDocResolver; // doc resolver passed by the user
    ar & lUserColResolver; // col resolver passed by the user
	  ar.set_is_temp_field(false);

    // callback required but not available
    if ((lUserDocResolver || lUserColResolver) && !lCallback) 
    {
      ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                           "Couldn't load pre-compiled query because"
                           << " a document or collection resolver"
                           << " is required but no SerializationCallback"
                           << " is given for retrieving these resolvers.");
    }

    if (lUserDocResolver) {
      DocumentURIResolver* lDocResolver = lCallback->getDocumentURIResolver();
      if (!lDocResolver) 
      {
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


/*******************************************************************************

********************************************************************************/
void static_context::serialize_tracestream(serialization::Archiver& ar)
{
  bool lUserTraceStream;
  if (ar.is_serializing_out())
  {
    // serialize out: remember whether the user registered a trace stream
    lUserTraceStream = (theTraceStream != 0);

	  ar.set_is_temp_field(true);
    ar & lUserTraceStream;
	  ar.set_is_temp_field(false);
  } 
  else 
  {
    // serialize in: set the trace stream from the user
    //               std::cerr is used if non was registered
    SerializationCallback* lCallback = ar.getUserCallback();

	  ar.set_is_temp_field(true);
    ar & lUserTraceStream; // trace stream passed by the user
	  ar.set_is_temp_field(false);

    // callback required but not available
    if (lUserTraceStream && !lCallback) 
    {
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


/*******************************************************************************

********************************************************************************/
void static_context::serialize(::zorba::serialization::Archiver& ar)
{
  if (ar.is_serializing_out())
  {
    ar.set_is_temp_field(true);
    bool  parent_is_root = check_parent_is_root();//(
    ar & parent_is_root;
    ar.set_is_temp_field(false);

    if(!parent_is_root)
    {
      ar.dont_allow_delay();
      ar & theParent;
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
    ar.set_is_temp_field(true);
    bool  parent_is_root;
    ar & parent_is_root;
    ar.set_is_temp_field(false);

    if(parent_is_root)
    {
      set_parent_as_root();
    }
    else
      ar & theParent;

    if(theParent)
      theParent->addReference(theParent->getSharedRefCounter() SYNC_PARAM2(theParent->getRCLock()));
  }

  if(!ar.is_serializing_out())
  {
    assert(modulemap.size() == 0);
  }

  ar & modulemap;
  ar & keymap;

  if (theBaseUriInfo)
  {
    ar & theBaseUriInfo->thePrologBaseUri;
    ar & theBaseUriInfo->theApplicationBaseUri;
    ar & theBaseUriInfo->theEntityRetrievalUri;
    ar & theBaseUriInfo->theEncapsulatingEntityUri;
    ar & theBaseUriInfo->theBaseUri;
  }

  serialize_resolvers(ar);
  serialize_tracestream(ar);

  ar & theModulePaths;

  SERIALIZE_TYPEMANAGER_RCHANDLE(TypeManager, theTypemgr);

  ar & theNamespaceBindings;
  ar & theDefaultElementNamespace;
  ar & theDefaultFunctionNamespace;

  ar & theFunctionMap;
  ar & theFunctionArityMap;

  ar & theW3CCollectionMap;
  ar & theCollectionMap;
  ar & theIndexMap;
  ar & theICMap;

  ar & theCollationMap;
  ar & theDefaultCollation;

  ar & theOptionMap;

  SERIALIZE_ENUM(StaticContextConsts::xquery_version_t, theXQueryVersion);
  SERIALIZE_ENUM(StaticContextConsts::xpath_compatibility_t, theXPathCompatibility);
  SERIALIZE_ENUM(StaticContextConsts::construction_mode_t, theConstructionMode);
  SERIALIZE_ENUM(StaticContextConsts::inherit_mode_t, theInheritMode);
  SERIALIZE_ENUM(StaticContextConsts::preserve_mode_t, thePreserveMode);
  SERIALIZE_ENUM(StaticContextConsts::ordering_mode_t, theOrderingMode);
  SERIALIZE_ENUM(StaticContextConsts::empty_order_mode_t, theEmptyOrderMode);
  SERIALIZE_ENUM(StaticContextConsts::boundary_space_mode_t, theBoundarySpaceMode);
  SERIALIZE_ENUM(StaticContextConsts::validation_mode_t, theValidationMode);

  ar & theDecimalFormats;
}


/***************************************************************************//**
  Create a new static_context obj and make a child of "this" static_context obj.
********************************************************************************/
static_context* static_context::create_child_context()
{
  return new static_context(this);
}


/***************************************************************************//**

********************************************************************************/
bool static_context::is_global_root_sctx() const
{
  return (this == &GENV_ROOT_STATIC_CONTEXT);
}


/***************************************************************************//**

********************************************************************************/
bool static_context::check_parent_is_root()
{
  return theParent == &GENV_ROOT_STATIC_CONTEXT;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_parent_as_root()
{
  theParent = &GENV_ROOT_STATIC_CONTEXT;
}


/***************************************************************************//**

********************************************************************************/
expr_t static_context::get_query_expr() const
{
  return theQueryExpr;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_query_expr(expr_t expr)
{
  theQueryExpr = expr;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_trace_stream(std::ostream& os)
{
  theTraceStream = &os;
}


/***************************************************************************//**

********************************************************************************/
std::ostream* static_context::get_trace_stream() const
{
  if (theTraceStream)
    return theTraceStream;

  return (theParent == NULL ?
          &std::cerr :
          dynamic_cast<static_context*>(theParent)->get_trace_stream());
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Base URI                                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
xqpStringStore_t static_context::get_implementation_baseuri() const 
{
  return reinterpret_cast<root_static_context*>(&GENV_ROOT_STATIC_CONTEXT)->theImplementationBaseUri;
}


/***************************************************************************//**

********************************************************************************/
xqpStringStore_t static_context::get_encapsulating_entity_uri() const
{
  const static_context* sctx = this;
  while (sctx != NULL)
  {
    if (sctx->theBaseUriInfo != NULL &&
        sctx->theBaseUriInfo->theEncapsulatingEntityUri != NULL)
    {
      return sctx->theBaseUriInfo->theEncapsulatingEntityUri;
    }

    sctx = sctx->theParent;
  }

  return NULL;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_encapsulating_entity_uri(const xqpStringStore_t& uri)
{
  if (theBaseUriInfo == NULL)
  {
    theBaseUriInfo = new BaseUriInfo;
  }

  theBaseUriInfo->theEncapsulatingEntityUri = uri;

  compute_base_uri();
}


/***************************************************************************//**

********************************************************************************/
xqpStringStore_t static_context::get_entity_retrieval_uri() const
{
  const static_context* sctx = this;
  while (sctx != NULL)
  {
    if (sctx->theBaseUriInfo != NULL &&
        sctx->theBaseUriInfo->theEntityRetrievalUri != NULL)
    {
      return sctx->theBaseUriInfo->theEntityRetrievalUri;
    }

    sctx = sctx->theParent;
  }

  return NULL;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_entity_retrieval_uri(const xqpStringStore_t& uri)
{
  if (theBaseUriInfo == NULL)
  {
    theBaseUriInfo = new BaseUriInfo;
  }

  theBaseUriInfo->theEntityRetrievalUri = uri;

  compute_base_uri();
}


/***************************************************************************//**

********************************************************************************/
xqpStringStore_t static_context::get_base_uri() const
{
  const static_context* sctx = this;
  while (sctx != NULL)
  {
    if (sctx->theBaseUriInfo != NULL &&
        sctx->theBaseUriInfo->theBaseUri != NULL)
    {
      return sctx->theBaseUriInfo->theBaseUri;
    }

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return NULL;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_base_uri(const xqpStringStore_t& uri, bool from_prolog)
{
  if (theBaseUriInfo == NULL)
  {
    theBaseUriInfo = new BaseUriInfo;
  }

  if (from_prolog)
  {
    if (theBaseUriInfo->thePrologBaseUri != NULL)
    {
      ZORBA_ERROR(XQST0032);
    }

    theBaseUriInfo->thePrologBaseUri = uri;
  }
  else
  {
    // overwite existing value of application baseuri, if any
    theBaseUriInfo->theApplicationBaseUri = uri;
  }

  compute_base_uri();
}


/***************************************************************************//**
  Base Uri Computation

  from_prolog_baseuri          --> uri
  baseuri                      --> uri
  encapsulating_entity_baseuri --> uri
  entity_retrieval_url         --> uri

  current_absolute_baseuri     --> uri

  The from_prolog_baseuri is the one declared in the prolog. The baseuri is set
  explicitly from the C++/C api. If both the from_prolog_baseuri and the baseuri
  are set, the from_prolog_baseuri hides the baseuri.

  For the main module, the entity_retrieval_url is set by default to the name
  of file containing the query we are running. For library modules, it is set
  to the location uri of each module component. It may also be set explicitly from the C++/C api.
********************************************************************************/
void static_context::compute_base_uri()
{
  if (theBaseUriInfo == NULL)
  {
    theBaseUriInfo = new BaseUriInfo;
  }

  xqpStringStore_t userBaseUri;
  xqpStringStore_t encapsulatingUri;
  xqpStringStore_t entityUri;

  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theBaseUriInfo != NULL &&
        sctx->theBaseUriInfo->thePrologBaseUri != NULL)
    {
      userBaseUri = sctx->theBaseUriInfo->thePrologBaseUri;
      break;
    }

    sctx = sctx->theParent;
  }

  if (userBaseUri == NULL)
  {
    sctx = this;

    while (sctx != NULL)
    {
      if (sctx->theBaseUriInfo != NULL &&
          sctx->theBaseUriInfo->theApplicationBaseUri != NULL)
      {
        userBaseUri = sctx->theBaseUriInfo->theApplicationBaseUri;
        break;
      }
      
      sctx = sctx->theParent;
    }
  }

  if (userBaseUri != NULL)
  {
    try
    {
      URI lCheckValid(userBaseUri);
      // is already absolute baseuri
      theBaseUriInfo->theBaseUri = lCheckValid.toString();
      return; // valid (absolute) uri
    }
    catch (error::ZorbaError&)
    {
      // assume it's relative and go on
    }

    /// is relative, needs to be resolved
    encapsulatingUri = get_encapsulating_entity_uri();
    if (encapsulatingUri != NULL)
    {
      URI base(encapsulatingUri);
      URI resolvedURI(base, userBaseUri);
      theBaseUriInfo->theBaseUri = resolvedURI.toString();
      return;
    }

    entityUri = get_entity_retrieval_uri();
    if (entityUri != NULL)
    {
      URI base(entityUri);
      URI resolvedURI(base, userBaseUri);
      theBaseUriInfo->theBaseUri = resolvedURI.toString();
      return;
    }

    URI base(get_implementation_baseuri());
    URI resolvedURI(base, userBaseUri);
    theBaseUriInfo->theBaseUri = resolvedURI.toString();
    return;
  }

  encapsulatingUri = get_encapsulating_entity_uri();
  if (encapsulatingUri != NULL)
  {
    theBaseUriInfo->theBaseUri = encapsulatingUri;
    return;
  }

  entityUri = get_entity_retrieval_uri();
  if (entityUri != NULL)
  {
    theBaseUriInfo->theBaseUri = entityUri;
    return;
  }

  theBaseUriInfo->theBaseUri = get_implementation_baseuri();
  return;
}


/***************************************************************************//**

********************************************************************************/
xqpStringStore_t static_context::resolve_relative_uri(
    const xqpStringStore_t& uri,
    bool validate)
{
  URI base(get_base_uri());
  URI resolved_uri(base, uri, validate);
  return resolved_uri.toString();
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  URI Resolution                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
void static_context::set_document_uri_resolver(InternalDocumentURIResolver* aDocResolver)
{
  delete theDocResolver;

  theDocResolver = aDocResolver;
}


/*******************************************************************************

********************************************************************************/
InternalDocumentURIResolver* static_context::get_document_uri_resolver()
{
  if ( theDocResolver != 0 )
    return theDocResolver;

  return (theParent != NULL ?
          dynamic_cast<static_context*>(theParent)->get_document_uri_resolver() :
          0);
}


/*******************************************************************************

********************************************************************************/
void static_context::set_collection_uri_resolver(
    InternalCollectionURIResolver* aColResolver)
{
  delete theColResolver;

  theColResolver = aColResolver;
}


/*******************************************************************************

********************************************************************************/
InternalCollectionURIResolver* static_context::get_collection_uri_resolver()
{
  if ( theColResolver != 0 )
    return theColResolver;

  return (theParent != NULL ? 
          dynamic_cast<static_context*>(theParent)->get_collection_uri_resolver() :
          0);
}


/*******************************************************************************

********************************************************************************/
void static_context::add_schema_uri_resolver(
    InternalSchemaURIResolver* aSchemaResolver)
{
  theSchemaResolvers.push_back(aSchemaResolver);
}


/*******************************************************************************

********************************************************************************/
void static_context::get_schema_uri_resolvers(
    std::vector<InternalSchemaURIResolver*>& aResolvers)
{
  if (theParent != NULL) 
  {
    static_cast<static_context*>(theParent)->get_schema_uri_resolvers(aResolvers);
  }

  aResolvers.insert(aResolvers.end(),
                    theSchemaResolvers.begin(),
                    theSchemaResolvers.end());
}


/*******************************************************************************

********************************************************************************/
void static_context::remove_schema_uri_resolver(
    InternalSchemaURIResolver* aResolver)
{
  std::vector<InternalSchemaURIResolver*>::iterator ite;
  for (ite = theSchemaResolvers.begin(); ite != theSchemaResolvers.end(); ++ite)
  {
    if (aResolver == *ite)
    {
      theSchemaResolvers.erase(ite);
      return; // no duplicates in the vector
    }
  }
}



/*******************************************************************************

********************************************************************************/
void static_context::add_module_uri_resolver(
    InternalModuleURIResolver* aModuleResolver)
{
  theModuleResolvers.push_back(aModuleResolver);
}


/*******************************************************************************

********************************************************************************/
void static_context::remove_module_uri_resolver(
    InternalModuleURIResolver* aResolver)
{
  std::vector<InternalModuleURIResolver*>::iterator ite;
  for (ite = theModuleResolvers.begin(); ite != theModuleResolvers.end(); ++ite) 
  {
    if (aResolver == *ite)
    {
      theModuleResolvers.erase(ite);
      return; // no duplicates in the vector
    }
  }
}


/*******************************************************************************

********************************************************************************/
void static_context::get_module_uri_resolvers(
    std::vector<InternalModuleURIResolver*>& lResolvers) const
{
  if (theParent != NULL) 
  {
    theParent->get_module_uri_resolvers(lResolvers);
  }

  lResolvers.insert(lResolvers.end(),
                    theModuleResolvers.begin(),
                    theModuleResolvers.end());
}


/*******************************************************************************

********************************************************************************/
void static_context::set_module_paths(const std::vector<std::string>& paths)
{
  theModulePaths = paths;
}


/*******************************************************************************

********************************************************************************/
void static_context::get_module_paths(std::vector<std::string>& paths) const
{
  paths.insert(paths.end(), theModulePaths.begin(), theModulePaths.end());
}


/*******************************************************************************

********************************************************************************/
void static_context::get_full_module_paths(std::vector<std::string>& paths) const
{
  if (theParent != NULL) 
  {
    theParent->get_full_module_paths(paths);
  }

  get_module_paths(paths);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Type Manager                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void static_context::set_typemanager(rchandle<TypeManager> typemgr)
{
  theTypemgr = typemgr;
}


TypeManager* static_context::get_typemanager() const
{
  TypeManager* tm = theTypemgr.getp();
  if (tm != NULL) 
  {
    return tm;
  }
  return static_cast<static_context *>(theParent)->get_typemanager();
}


TypeManager* static_context::get_local_typemanager() const
{
  return theTypemgr.getp();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Namespace Bindings                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**
  Get the default namespace for element and type qnames.
********************************************************************************/
const xqpStringStore_t& static_context::default_elem_type_ns() const
{
  if (theDefaultElementNamespace != NULL || theParent == NULL)
  {
    return theDefaultElementNamespace;
  }
  else
  {
    return theParent->default_elem_type_ns();
  }
}


/***************************************************************************//**
  Set the default namespace for element and type qnames to the given namespace.
********************************************************************************/
void static_context::set_default_elem_type_ns(
    const xqpStringStore_t& ns,
    const QueryLoc& loc)
{
  assert(ns != NULL);

  if (theDefaultElementNamespace == NULL)
  {
    theDefaultElementNamespace = ns;
  }
  else
  {
    ZORBA_ERROR_LOC(XQST0066, loc);
  }
}


/***************************************************************************//**
  Get the default namespace for function qnames.
********************************************************************************/
const xqpStringStore_t& static_context::default_function_ns() const
{
  if (theDefaultFunctionNamespace != NULL || theParent == NULL)
  {
    return theDefaultFunctionNamespace;
  }
  else
  {
    return theParent->default_function_ns();
  }
}


/***************************************************************************//**
 Set the default namespace for function qnames to the given namespace.
********************************************************************************/
void static_context::set_default_function_ns(
   const xqpStringStore_t& ns,
   const QueryLoc& loc)
{
  assert(ns != NULL);

  if (theDefaultFunctionNamespace == NULL)
  {
    theDefaultFunctionNamespace = ns;
  }
  else
  {
      ZORBA_ERROR_LOC(XQST0066, loc);
  }
}


/***************************************************************************//**
  Bind the given prefix to the given namaspace uri. The binding is stored in
  "this". If there is already in "this" a binding for the prefix, raise error.
********************************************************************************/
void static_context::bind_ns(
    xqpStringStore_t& prefix,
    xqpStringStore_t& ns,
    const QueryLoc& loc,
    const XQUERY_ERROR& err)
{
  assert(prefix != NULL);
  assert(ns != NULL);

  if (theNamespaceBindings == NULL)
  {
    theNamespaceBindings = new NamespaceBindings(16, false);
  }

  if (!theNamespaceBindings->insert(prefix, ns))
  {
    ZORBA_ERROR_LOC(err, loc);
  }
}


/***************************************************************************//**
  Search the static-context tree, starting from "this" and moving upwards,
  looking for the 1st namespace binding for the given prefix. If no such
  binding is found, either raise an error (if the given error code is not 
  MAX_ZORBA_ERROR_CODE) or return false. Otherwise, it return true and the
  associated namespace uri.
********************************************************************************/
bool static_context::lookup_ns(
    xqpStringStore_t& ns,
    const xqpStringStore_t& prefix,
    const QueryLoc& loc,
    const XQUERY_ERROR& err) const
{
  assert(prefix != NULL);

  if (theNamespaceBindings == NULL || !theNamespaceBindings->get(prefix, ns))
  {
    if (theParent != NULL)
    {
      return theParent->lookup_ns(ns, prefix, loc, err);
    }
    else if (err != MAX_ZORBA_ERROR_CODE)
    {
      ZORBA_ERROR_LOC_PARAM(err, loc, prefix, "");
    }
    else
    {
      return false;
    }
  }
  else if (!prefix->empty() && ns->empty())
  {
    if (err != MAX_ZORBA_ERROR_CODE)
    {
      ZORBA_ERROR_LOC_PARAM(err, loc, prefix, "");
    }
    else
    {
      return false;
    }
  }

  return true;
}


/***************************************************************************//**
  Convert a [prefix, localName] pair to an expanded QName item, using the given
  default namespace if the prefix is empty.
********************************************************************************/
void static_context::expand_qname(
    store::Item_t& qname,
    const xqpStringStore_t& default_ns,
    const xqpStringStore_t& prefix,
    const xqpStringStore_t& local,
    const QueryLoc& loc) const
{
  assert(prefix != NULL);
  assert(local != NULL);

  if (prefix->empty())
  {
    if (default_ns == NULL)
    {
      xqpStringStore_t def_ns = new xqpStringStore("");
      ITEM_FACTORY->createQName(qname, def_ns, prefix, local);
    }
    else
    {
      ITEM_FACTORY->createQName(qname, default_ns, prefix, local);
    }
  }
  else
  {
    xqpStringStore_t ns;
    lookup_ns(ns, prefix, loc);
    ITEM_FACTORY->createQName(qname, ns, prefix, local);
  }
}


/***************************************************************************//**

********************************************************************************/
void static_context::get_namespace_bindings(
    std::vector<std::pair<xqpStringStore_t, xqpStringStore_t> >& bindings) const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (theNamespaceBindings != NULL)
    {
      NamespaceBindings::iterator ite = theNamespaceBindings->begin();
      NamespaceBindings::iterator end = theNamespaceBindings->end();
      for (; ite !=  end; ++ite)
      {
        std::pair<xqpStringStore_t, xqpStringStore_t> binding = (*ite);
        xqpStringStore* prefix = binding.first.getp();
        ulong numBindings = bindings.size();
        ulong i = 0;
        for (; i < numBindings; ++i)
        {
          if (bindings[i].first->byteEqual(prefix))
            break;
        }

        if (i == numBindings)
          bindings.push_back(binding);
      }
    }

    sctx = sctx->theParent;
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Variables                                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
void static_context::set_context_item_type(xqtref_t& t)
{
  theCtxItemType = t;
}

/***************************************************************************//**

********************************************************************************/
const XQType* static_context::get_context_item_type()
{
  static_context* sctx = this;
  while (sctx != NULL)
  {
    if (theCtxItemType != NULL)
      return theCtxItemType.getp();

    sctx = sctx->theParent;
  }

  return NULL;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Functions                                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
void static_context::bind_fn(
    const store::Item* qname,
    function_t& f,
    ulong arity,
    const QueryLoc& loc)
{
  if (!is_global_root_sctx() && lookup_fn(qname, arity) != NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XQST0034, loc,
                          qname->getStringValue(),
                          loc.getFilename());
  }

  store::Item* qname2 = const_cast<store::Item*>(qname);

  if (theFunctionMap == NULL)
  {
    ulong size = (is_global_root_sctx() ? 500 : 32);
    theFunctionMap = new FunctionMap(0, NULL, size, false);
  }

  function_t f_save = f;

  if (!theFunctionMap->insert(qname2, f))
  {
    f = f_save;

    // There is already a function with the given qname in theFunctionMap. So,
    // we have to use theFunctionArityMap.
    if (theFunctionArityMap == NULL)
    {
      theFunctionArityMap = new FunctionArityMap(0, NULL, 16, false);
    }

    std::vector<function_t>* functions;

    if (theFunctionArityMap->get(qname2, functions))
    {
      functions->push_back(f);
    }
    else
    {
      functions = new std::vector<function_t>(1);
      (*functions)[0] = f;
      theFunctionArityMap->insert(qname2, functions);
    }
  }
}


/***************************************************************************//**
  Search the static-context tree, starting from "this" and moving upwards,
  looking for the function with the given qname and arity. If such a function
  is found remove it from the sctx.
********************************************************************************/
void static_context::unbind_fn(
    const store::Item* qname,
    ulong arity)
{
  function_t f;
  store::Item* qname2 = const_cast<store::Item*>(qname);

  if (theFunctionMap != NULL && theFunctionMap->get(qname2, f))
  {
    if (f->get_arity() == arity)
    {
      theFunctionMap->remove(qname2);
      return;
    }

    std::vector<function_t>* fv;

    if (theFunctionArityMap != NULL && theFunctionArityMap->get(qname2, fv))
    {
      ulong numFunctions = fv->size();
      for (ulong i = 0; i < numFunctions; ++i)
      {
        if ((*fv)[i]->get_arity() == arity)
        {
          (*fv).erase((*fv).begin() + i);
          return;
        }
      }
    }
  }

  if (theParent != NULL)
    theParent->unbind_fn(qname2, arity);
}


/***************************************************************************//**
  Search the static-context tree, starting from "this" and moving upwards,
  looking for the function with the given qname and arity. If no such function
  is found return NULL. Otherwise, it return the associated function object.
********************************************************************************/
function* static_context::lookup_fn(
    const store::Item* qname,
    ulong arity)
{
  function_t f;
  store::Item* qname2 = const_cast<store::Item*>(qname);

  if (theFunctionMap != NULL && theFunctionMap->get(qname2, f))
  {
    if (f->get_arity() == arity || f->is_variadic())
      return f.getp();

    std::vector<function_t>* fv;

    if (theFunctionArityMap != NULL && theFunctionArityMap->get(qname2, fv))
    {
      ulong numFunctions = fv->size();
      for (ulong i = 0; i < numFunctions; ++i)
      {
        if ((*fv)[i]->get_arity() == arity)
          return (*fv)[i].getp();
      }
    }
  }

  return (theParent != NULL ? theParent->lookup_fn(qname2, arity) : NULL);
}


/***************************************************************************//**
  Find all the functions with the given qname.
********************************************************************************/
void static_context::find_functions(
    const store::Item* qname,
    std::vector<function *>& functions) const
{
  function_t f;
  store::Item* qname2 = const_cast<store::Item*>(qname);

  if (theFunctionMap != NULL && theFunctionMap->get(qname2, f))
  {
    functions.push_back(f.getp());
  }

  std::vector<function_t>* fv;

  if (theFunctionArityMap != NULL && theFunctionArityMap->get(qname2, fv))
  {
    ulong numFunctions = fv->size();
    for (ulong i = 0; i < numFunctions; ++i)
    {
      functions.push_back((*fv)[i].getp());
    }
  }
  
  if (theParent != NULL)
    theParent->find_functions(qname2, functions);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Documents                                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**
  This method may be called only on an application-created sctx.
********************************************************************************/
void static_context::bind_document(xqpStringStore_t& uri, xqtref_t& type)
{
  if (theDocumentMap == NULL)
  {
    theDocumentMap = new DocumentMap(16, false);
  }

  if (!theDocumentMap->update(uri, type))
  {
    theDocumentMap->insert(uri, type);
  }
}


/***************************************************************************//**

********************************************************************************/
const XQType* static_context::lookup_document(const xqpStringStore_t& uri)
{
  xqtref_t type;

  static_context* sctx = this;
  while (sctx != NULL)
  {
    if (theDocumentMap && theDocumentMap->get(uri, type))
      return type.getp();

    sctx = sctx->theParent;
  }

  return NULL;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  W3C Collections                                                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**
  This method may be called only on an application-created sctx.
********************************************************************************/
void static_context::bind_w3c_collection(xqpStringStore_t& uri, xqtref_t& type)
{
  if (theW3CCollectionMap == NULL)
  {
    theW3CCollectionMap = new W3CCollectionMap(16, false);
  }

  if (!theW3CCollectionMap->update(uri, type))
  {
    theW3CCollectionMap->insert(uri, type);
  }
}


/***************************************************************************//**

********************************************************************************/
const XQType* static_context::lookup_w3c_collection(const xqpStringStore_t& uri)
{
  xqtref_t type;

  if (theW3CCollectionMap && theW3CCollectionMap->get(uri, type))
    return type.getp();
  else
    return (theParent == NULL ? 0 : theParent->lookup_w3c_collection(uri));
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_default_w3c_collection_type(xqtref_t& t)
{
  theDefaultW3CCollectionType = t;
}


/***************************************************************************//**

********************************************************************************/
const XQType* static_context::get_default_w3c_collection_type()
{
  static_context* sctx = this;
  while (sctx != NULL)
  {
    if (theDefaultW3CCollectionType != NULL)
      return theDefaultW3CCollectionType.getp();

    sctx = sctx->theParent;
  }

  return NULL;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  XQDDF Collections                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
void static_context::bind_collection(
    StaticallyKnownCollection_t& aCollection,
    const QueryLoc& aLoc)
{
  if (lookup_collection(aCollection->getName()) != NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XDST0001_COLLECTION_ALREADY_DECLARED, aLoc,
                          aCollection->getName()->getStringValue(), "");
  }

  if (theCollectionMap == 0)
    theCollectionMap = new CollectionMap(0, NULL, 8, false);

  store::Item* qname = const_cast<store::Item*>(aCollection->getName());

  theCollectionMap->insert(qname, aCollection);

}


/***************************************************************************//**

********************************************************************************/
const StaticallyKnownCollection* static_context::lookup_collection(
    const store::Item* qname) const
{
  StaticallyKnownCollection_t lColl;
  store::Item* qname2 = const_cast<store::Item*>(qname);

  if (theCollectionMap && theCollectionMap->get(qname2, lColl))
    return lColl.getp();
  else
    return (theParent == NULL ? 0 : theParent->lookup_collection(qname));
}


/***************************************************************************//**

********************************************************************************/
store::Iterator_t static_context::collection_names() const
{
  return new SctxMapIterator<StaticallyKnownCollection>(
             this,
             &static_context::collection_map);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  XQDDF Indexes                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
void static_context::bind_index(
    const store::Item* qname,
    ValueIndex_t& index,
    const QueryLoc& loc)
{
  if (lookup_index(qname) != NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XDST0021_INDEX_ALREADY_DECLARED, loc,
                          qname->getStringValue(),  "");
  }

  store::Item* qname2 = const_cast<store::Item*>(qname);

  if (theIndexMap == NULL)
    theIndexMap = new IndexMap(0, NULL, 8, false);

  theIndexMap->insert(qname2, index);
}


/***************************************************************************//**

********************************************************************************/
ValueIndex* static_context::lookup_index(const store::Item* qname) const
{
  ValueIndex_t index;
  store::Item* qname2 = const_cast<store::Item*>(qname);

  if (theIndexMap && theIndexMap->get(qname2, index))
    return index.getp();
  else
    return (theParent == NULL ? NULL : theParent->lookup_index(qname));
}


/***************************************************************************//**

********************************************************************************/
store::Iterator_t static_context::index_names() const
{
  return new SctxMapIterator<ValueIndex>(this, &static_context::index_map);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  XQDDF Integrity Constraints                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
void static_context::bind_ic(
    const store::Item* qname,
    ValueIC_t& vic,
    const QueryLoc& loc)
{
  if (lookup_ic(qname) != NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XDST0041_IC_IS_ALREADY_DECLARED, loc,
                          qname->getStringValue(),  "");
  }

  store::Item* qname2 = const_cast<store::Item*>(qname);

  if (theICMap == NULL)
    theICMap = new ICMap(0, NULL, 8, false);

  theICMap->insert(qname2, vic);
}


/***************************************************************************//**

********************************************************************************/
ValueIC_t static_context::lookup_ic(const store::Item* qname) const
{
  ValueIC_t vic;
  store::Item* qname2 = const_cast<store::Item*>(qname);

  if (theICMap != NULL && theICMap->get(qname2, vic))
    return vic;
  else
    return (theParent == NULL ? NULL : theParent->lookup_ic(qname));
}


/***************************************************************************//**

********************************************************************************/
store::Iterator_t static_context::ic_names() const
{
  return new SctxMapIterator<ValueIC>(this, &static_context::ic_map);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Collations                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**
  This method may be called only on the the zorba root sctx or an application-
  created sctx.
********************************************************************************/
void static_context::add_collation(const std::string& uri, const QueryLoc& loc)
{
  if (is_known_collation(uri))
    return;

  xqpStringStore_t tmp = new xqpStringStore(uri);
  std::string resolvedURI = resolve_relative_uri(tmp)->str();

  XQPCollator* collator = CollationFactory::createCollator(resolvedURI);

  if (collator == NULL)
  {
    ZORBA_ERROR_LOC_DESC_OSS(FOCH0002, loc, 
                             "Collation " << uri << " not supported.");
  }
  else
  {
    if (theCollationMap == NULL)
      theCollationMap = new CollationMap();
    
    (*theCollationMap)[resolvedURI] = collator;
  }
}


/***************************************************************************//**

********************************************************************************/
bool static_context::is_known_collation(const std::string& uri)
{
  xqpStringStore_t tmp = new xqpStringStore(uri);
  std::string resolvedURI = resolve_relative_uri(tmp)->str();

  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theCollationMap != NULL &&
        sctx->theCollationMap->find(resolvedURI) != sctx->theCollationMap->end())
    {
      return true;
    }

    sctx = sctx->theParent;
  }

  return false;
}


/***************************************************************************//**

********************************************************************************/
XQPCollator* static_context::get_collator(
     const std::string& uri,
     const QueryLoc& loc)
{
  xqpStringStore_t tmp = new xqpStringStore(uri);
  std::string resolvedURI = resolve_relative_uri(tmp)->str();

  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theCollationMap != NULL)
    {
      CollationMap::iterator ite = sctx->theCollationMap->find(uri);

      if (ite != sctx->theCollationMap->end())
      {
        return ite->second;
      }
    }

    sctx = sctx->theParent;
  }
  
  ZORBA_ERROR_LOC_DESC_OSS(FOCH0002, loc,
                           "Collation " << uri << " not found in static context.");
  return NULL;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_default_collation(
    const std::string& uri,
    const QueryLoc& loc)
{
  if (theDefaultCollation != NULL || !is_known_collation(uri))
  {
    ZORBA_ERROR_LOC(XQST0038, loc);
  }

  xqpStringStore_t tmp = new xqpStringStore(uri);
  xqpStringStore_t resolvedUri = resolve_relative_uri(tmp);

  theDefaultCollation = new std::string(resolvedUri->c_str());
}


/***************************************************************************//**

********************************************************************************/
const std::string& static_context::get_default_collation(const QueryLoc& loc) const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theDefaultCollation != NULL)
    {
      return *sctx->theDefaultCollation;
    }

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return *theDefaultCollation;
}


/***************************************************************************//**

********************************************************************************/
XQPCollator* static_context::get_default_collator(const QueryLoc& loc)
{
  const std::string& default_collation = get_default_collation(loc);
  return get_collator(default_collation, loc);
}


/***************************************************************************//**

********************************************************************************/
void static_context::get_collations(std::vector<std::string>& collations) const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (theCollationMap != NULL)
    {
      CollationMap::const_iterator ite = theCollationMap->begin();
      CollationMap::const_iterator end = theCollationMap->end();
      for (; ite !=  end; ++ite)
      {
        collations.push_back(ite->first);
      }
    }

    sctx = sctx->theParent;
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Options                                                                    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
void static_context::bind_option(
    const store::Item* qname,
    const xqpStringStore_t& option)
{
  if (theOptionMap == NULL)
  {
    theOptionMap = new OptionMap(0, NULL, 8, false);
  }

  store::Item* qname2 = const_cast<store::Item*>(qname);

  if (!theOptionMap->update(qname2, option))
  {
    xqpStringStore_t tmp = option;
    theOptionMap->insert(qname2, tmp);
  }
}


/***************************************************************************//**

********************************************************************************/
bool static_context::lookup_option(
    const store::Item* qname,
    xqpStringStore_t& option) const
{
  store::Item* qname2 = const_cast<store::Item*>(qname);
  const static_context* sctx = this;
  while (sctx != NULL)
  {
    if (theOptionMap && theOptionMap->get(qname2, option))
      return true;

    sctx = sctx->theParent;
  }

  return false;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Miscellaneous                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
StaticContextConsts::xquery_version_t static_context::xquery_version() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theXQueryVersion != StaticContextConsts::xquery_version_unknown)
      return sctx->theXQueryVersion;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::xquery_version_unknown;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_xquery_version(StaticContextConsts::xquery_version_t v)
{
  theXQueryVersion = v;
}


/***************************************************************************//**
  Parse and set the xquery version. StaticContextConsts::xquery_version_unknown
  is set if the persion could not be parsed.
********************************************************************************/
void static_context::set_xquery_version(const std::string& v)
{
  StaticContextConsts::xquery_version_t lVersion;
  lVersion = StaticContextConsts::xquery_version_unknown;

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


/***************************************************************************//**

********************************************************************************/
StaticContextConsts::xpath_compatibility_t static_context::xpath_compatibility() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theXPathCompatibility != StaticContextConsts::xpath_unknown)
      return sctx->theXPathCompatibility;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::xpath_unknown;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_xpath_compatibility(StaticContextConsts::xpath_compatibility_t v)
{
  theXPathCompatibility = v;
}


/***************************************************************************//**

********************************************************************************/
StaticContextConsts::construction_mode_t static_context::construction_mode() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theConstructionMode != StaticContextConsts::cons_unknown)
      return sctx->theConstructionMode;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::cons_unknown;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_construction_mode(StaticContextConsts::construction_mode_t v)
{
  theConstructionMode = v;
}


/***************************************************************************//**

********************************************************************************/
StaticContextConsts::inherit_mode_t static_context::inherit_mode() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theInheritMode != StaticContextConsts::inherit_unknown)
      return sctx->theInheritMode;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::inherit_unknown;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_inherit_mode(StaticContextConsts::inherit_mode_t v)
{
  theInheritMode = v;
}


/***************************************************************************//**

********************************************************************************/
StaticContextConsts::preserve_mode_t static_context::preserve_mode() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->thePreserveMode != StaticContextConsts::preserve_unknown)
      return sctx->thePreserveMode;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::preserve_unknown;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_preserve_mode(StaticContextConsts::preserve_mode_t v)
{
  thePreserveMode = v;
}


/***************************************************************************//**

********************************************************************************/
StaticContextConsts::ordering_mode_t static_context::ordering_mode() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theOrderingMode != StaticContextConsts::ordering_unknown)
      return sctx->theOrderingMode;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::ordering_unknown;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_ordering_mode(StaticContextConsts::ordering_mode_t v)
{
  theOrderingMode = v;
}


/***************************************************************************//**

********************************************************************************/
StaticContextConsts::empty_order_mode_t static_context::empty_order_mode() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theEmptyOrderMode != StaticContextConsts::empty_order_unknown)
      return sctx->theEmptyOrderMode;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::empty_order_unknown;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_empty_order_mode(StaticContextConsts::empty_order_mode_t v)
{
  theEmptyOrderMode = v;
}


/***************************************************************************//**

********************************************************************************/
StaticContextConsts::boundary_space_mode_t static_context::boundary_space_mode() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theBoundarySpaceMode != StaticContextConsts::boundary_space_unknown)
      return sctx->theBoundarySpaceMode;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::boundary_space_unknown;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_boundary_space_mode(StaticContextConsts::boundary_space_mode_t v)
{
  theBoundarySpaceMode = v;
}


/***************************************************************************//**

********************************************************************************/
StaticContextConsts::validation_mode_t static_context::validation_mode() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theValidationMode != StaticContextConsts::validation_unknown)
      return sctx->theValidationMode;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::validation_unknown;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_validation_mode(StaticContextConsts::validation_mode_t v)
{
  theValidationMode = v;
}


/***************************************************************************//**

********************************************************************************/
void static_context::add_decimal_format(
    const DecimalFormat_t& decimalFormat,
    const QueryLoc& loc)
{
  if (theDecimalFormats == NULL)
    theDecimalFormats = new std::vector<DecimalFormat_t>;

  ulong num = theDecimalFormats->size();
  for (ulong i = 0; i < num; ++i)
  {
    const DecimalFormat_t& format = (*theDecimalFormats)[i];

    if ((decimalFormat->isDefault() && format->isDefault()) ||
        (!format->isDefault() &&
         !decimalFormat->isDefault() &&
         format->getName()->equals(decimalFormat->getName())))
    {
      ZORBA_ERROR_LOC(XQST0096, loc);
    }
  }

  theDecimalFormats->push_back(decimalFormat);
}


/***************************************************************************//**

********************************************************************************/
DecimalFormat_t static_context::get_decimal_format(const store::Item_t& qname)
{
  if (theDecimalFormats != NULL)
  {
    ulong num = theDecimalFormats->size();

    for (ulong i = 0; i < num; ++i)
    {
      const DecimalFormat_t& format = (*theDecimalFormats)[i];

      if ((qname == NULL && format->isDefault()) ||
          (qname != NULL && !format->isDefault() && format->getName()->equals(qname)))
      {
        return format;
      }
    }
  }

  return (theParent == NULL ? NULL : theParent->get_decimal_format(qname));
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


xqp_string static_context::qname_internal_key (const store::Item *qname)
{
    return qname_internal_key2 (qname->getNamespace (), qname->getLocalName ());
}


xqp_string static_context::qname_internal_key(
    xqp_string default_ns, 
    xqp_string prefix,
    xqp_string local) const
{
  if (prefix.empty())
  {
    return qname_internal_key2(default_ns, local);
  }
  else
  {
    QueryLoc loc;
    xqpStringStore_t ns;
    lookup_ns(ns, prefix.getStore(), loc);
    return qname_internal_key2(ns.getp(), local);
  }
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





bool static_context::bind_external_module(
    ExternalModule* aModule,
    bool aDynamicallyLoaded)
{
  xqp_string lURI = Unmarshaller::getInternalString(aModule->getURI());

  return bind_module(lURI, aModule, aDynamicallyLoaded);
}


StatelessExternalFunction* static_context::lookup_stateless_external_function(
    const xqp_string& aURI,
    const xqp_string& aLocalName)
{
  // get the module for the given namespace
  ctx_module_t v;
  bool lRes = lookup_module(aURI, v);
  ExternalModule* lModule = 0;

  // if the module is not yet in the static context
  // we try to get it from the URI resolver
  if (!lRes)
  {
    InternalModuleURIResolver* lStandardModuleResolver = GENV.getModuleURIResolver();
    lModule = lStandardModuleResolver->getExternalModule(
                //entity_retrieval_url().getStore(), this);
                                                         aURI.getStore()->str(), *this);

    // no way to get the module
    if (!lModule) {
      return NULL;
    }

    // remember the module for future use
    bind_external_module(lModule, true);
  }
  else
  {
    lModule = v.module;
  }

  // get the function from this module.
  // return 0 if not found
  return lModule->getExternalFunction(aLocalName.theStrStore.getp());
}



/*******************************************************************************
  Merge the static context of a module with this static context. Only functions
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
    const ctx_value_t* val = &(*it).val;

    if (0 == strncmp(keybuff, "var:", 4) && 0 != strncmp(keybuff, "var:$$", 6))
    {
      if (! bind_expr (keybuff, val->exprValue))
        return false;
    }
  }

  if (module->theFunctionMap)
  {
    if (theFunctionMap == NULL)
    {
      theFunctionMap = new FunctionMap(0,
                                       NULL,
                                       module->theFunctionMap->capacity(),
                                       false);
    }

    FunctionMap::iterator ite = module->theFunctionMap->begin();
    FunctionMap::iterator end = module->theFunctionMap->end();
    for (; ite != end; ++ite)
    {
      function_t f = (*ite).second;
      bind_fn((*ite).first, f, f->get_arity(), loc);
    }
  }

  if (module->theFunctionArityMap)
  {
    if (theFunctionArityMap == NULL)
    {
      theFunctionArityMap = new FunctionArityMap(0,
                                                 NULL,
                                                 module->theFunctionArityMap->capacity(),
                                                 false);
    }

    FunctionArityMap::iterator ite = module->theFunctionArityMap->begin();
    FunctionArityMap::iterator end = module->theFunctionArityMap->end();
    for (; ite != end; ++ite)
    {
      std::vector<function_t>* fv = (*ite).second;
      ulong num = fv->size();
      for (ulong i = 0; i < num; ++i)
      {
        function_t& f = (*fv)[i];
        bind_fn((*ite).first, f, f->get_arity(), loc);
      }
    }
  }

  if (module->theCollectionMap)
  {
    if (theCollectionMap == 0)
    {
      theCollectionMap = new CollectionMap(0, 0, 8, false);
    }

    CollectionMap::iterator coll_iter = module->theCollectionMap->begin();
    CollectionMap::iterator coll_end = module->theCollectionMap->end();
    for (; coll_iter != coll_end; ++ coll_iter)
    {
      std::pair<store::Item*, StaticallyKnownCollection_t > pair = (*coll_iter);

      if (!theCollectionMap->insert(pair.first, pair.second))
      {
        ZORBA_ERROR_LOC_PARAM(XDST0002_COLLECTION_ALREADY_IMPORTED, loc,
                              pair.second->getName()->getStringValue(),
                              module->get_module_namespace().c_str());
      }
    }
  }

  if (module->theIndexMap)
  {
    if (theIndexMap == NULL)
    {
      theIndexMap = new IndexMap(0, NULL, 8, false);
    }

    IndexMap::iterator idx_iter = module->theIndexMap->begin();
    IndexMap::iterator idx_end = module->theIndexMap->end();
    for (; idx_iter != idx_end; ++idx_iter)
    {
      std::pair<store::Item*, rchandle<ValueIndex> > pair = (*idx_iter);

      if (!theIndexMap->insert(pair.first, pair.second))
      {
        ZORBA_ERROR_LOC_PARAM(XDST0022_INDEX_ALREADY_IMPORTED, loc,
                              pair.first->getStringValue(),
                              module->get_module_namespace().c_str());
      }
    }
  }

  if (module->theICMap)
  {
    if (theICMap == NULL)
    {
      theICMap = new ICMap(0, NULL, 8, false);
    }

    ICMap::iterator ic_iter = module->theICMap->begin();
    ICMap::iterator ic_end = module->theICMap->end();
    for (; ic_iter != ic_end; ++ic_iter)
    {
      std::pair<store::Item*, rchandle<ValueIC> > pair = (*ic_iter);

      if (!theICMap->insert(pair.first, pair.second))
      {
        ZORBA_ERROR_LOC_PARAM(XDST0041_IC_IS_ALREADY_DECLARED, loc,
                              pair.first->getStringValue()->c_str(), "");
      }
    }
  }

  return true;
}


void static_context::getVariables(std::vector<std::string>& aResult) const
{
  if (theParent)
    static_cast<static_context*>(theParent)->getVariables(aResult);

  std::vector<zorba::serializable_hashmap<ctx_value_t>::entry>::const_iterator it;
  for (it = keymap.begin(); it != keymap.end(); it++) 
  {
    const std::string& lKey = (*it).key;
    ctx_value_t lVal = (*it).val;
    if (lKey.find("var:") == 0) 
    {
      ZORBA_ASSERT(dynamic_cast<var_expr*>(lVal.exprValue));
      var_expr* lExpr = static_cast<var_expr*>(lVal.exprValue);
      var_expr::var_kind lKind = lExpr->get_kind();
      if (lKind == var_expr::prolog_var) 
      {
        aResult.push_back("global");
      }
      else 
      {
        aResult.push_back("local");
      }
      std::string lType;
      if (lExpr->get_type() == NULL || lExpr->get_type()->get_qname() == NULL) 
      {
        lType = "anyType:http://www.w3.org/2001/XMLSchema";
      }
      else
      {
        store::Item_t lQname = lExpr->get_type()->get_qname();
        lType = lQname->getLocalName()->c_str();
        lType += ":";
        lType += lQname->getNamespace()->c_str();
      }
      if (lExpr->is_sequential()) 
      {
        lType += "*";
      }
      aResult.push_back(lType);
      aResult.push_back(lKey.substr(4, lKey.size() - 5));
    }
  }
}


void static_context::getVariables(std::vector<var_expr_t>& aResult) const
{
  if (theParent)
    static_cast<static_context*>(theParent)->getVariables(aResult);

  std::vector<zorba::serializable_hashmap<ctx_value_t>::entry>::const_iterator it;
  for (it = keymap.begin(); it != keymap.end(); it++) {
    const std::string& lKey = (*it).key;
    if (lKey.find("var:") == 0) {
      aResult.push_back(static_cast<var_expr*>((*it).val.exprValue));
    }
  }
}


} /* namespace zorba */

