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
#include <algorithm>

#include <zorba/external_module.h>
#include <zorba/serialization_callback.h>
#include <zorba/declared_collection.h>
#include <zorba/declared_index.h>

#include "zorbaserialization/serialization_engine.h"

#include "util/string_util.h"

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
#ifndef ZORBA_NO_FULL_TEXT
#include "compiler/expression/ftnode.h"
#endif /* ZORBA_NO_FULL_TEXT */
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
#include "types/typeops.h"
#include "types/schema/validate.h"

#include "functions/function.h"
#include "functions/library.h"
#include "functions/signature.h"

#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"

#include "zorba/module_import_checker.h"


using namespace std;

namespace zorba
{

#define ITEM_FACTORY (GENV.getStore().getItemFactory())


SERIALIZABLE_CLASS_VERSIONS(BaseUriInfo)
END_SERIALIZABLE_CLASS_VERSIONS(BaseUriInfo)

SERIALIZABLE_CLASS_VERSIONS(FunctionInfo)
END_SERIALIZABLE_CLASS_VERSIONS(FunctionInfo)

SERIALIZABLE_CLASS_VERSIONS(PrologOption)
END_SERIALIZABLE_CLASS_VERSIONS(PrologOption)

SERIALIZABLE_CLASS_VERSIONS(static_context::ctx_module_t)
END_SERIALIZABLE_CLASS_VERSIONS(static_context::ctx_module_t)

SERIALIZABLE_CLASS_VERSIONS(static_context)
END_SERIALIZABLE_CLASS_VERSIONS(static_context)


/**************************************************************************//**

*******************************************************************************/
void BaseUriInfo::serialize(::zorba::serialization::Archiver& ar)
{
  ar & thePrologBaseUri;
  ar & theApplicationBaseUri;
  ar & theEntityRetrievalUri;
  ar & theEncapsulatingEntityUri;

  ar & theBaseUri;

  ar & theHavePrologBaseUri;
  ar & theHaveApplicationBaseUri;
  ar & theHaveEntityRetrievalUri;
  ar & theHaveEncapsulatingEntityUri;

  ar & theHaveBaseUri;
}


/**************************************************************************//**

*******************************************************************************/
FunctionInfo::FunctionInfo()
  :
  theIsDisabled(false)
{
}


FunctionInfo::FunctionInfo(const function_t& f, bool disabled)
  :
  theFunction(f),
  theIsDisabled(disabled)
{
}


FunctionInfo::FunctionInfo(::zorba::serialization::Archiver& ar)
  :
  ::zorba::serialization::SerializeBaseClass()
{
}


/**************************************************************************//**

*******************************************************************************/
FunctionInfo::~FunctionInfo()
{
}


/**************************************************************************//**

*******************************************************************************/
void FunctionInfo::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theFunction;
  ar & theIsDisabled;
}


/**************************************************************************//**

*******************************************************************************/
void PrologOption::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theName;
  ar & theValue;
}


/**************************************************************************//**

*******************************************************************************/
void static_context::ctx_module_t::serialize(serialization::Archiver& ar)
{
  if(ar.is_serializing_out())
  {
    // serialize out: the uri of the module that is used in this plan

    zstring lURI = Unmarshaller::getInternalString(module->getURI());
	  ar.set_is_temp_field(true);
    ar.dont_allow_delay();
    ar & lURI;
	  ar.set_is_temp_field(false);
    ar & dyn_loaded_module;
    ar & sctx;
  }
  else
  {
    // serialize in: load the serialized uri of the module and
    //               get the externalmodule from the user's
    //               registered serialization callback
    zstring lURI;
	  ar.set_is_temp_field(true);
    ar & lURI;
	  ar.set_is_temp_field(false);
    ar & dyn_loaded_module;
    ar & sctx;

    if (dyn_loaded_module)
    {
      StandardModuleURIResolver* moduleResolver = GENV.getModuleURIResolver();

      ZORBA_ASSERT(sctx);
      module = moduleResolver->getExternalModule(lURI, *sctx);

      // no way to get the module
      if (!module)
      {
        ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                             "Couldn't load pre-compiled query because"
                             << " the external module " << lURI
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
                             << " the external module " << lURI
                             << " is required but no SerializationCallback is"
                             << " given for retrieving that module.");
      }

      // the life-cycle of the module is managed by the user
      module = lCallback->getExternalModule(lURI.str());
      if (!module)
      {
        ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                             "Couldn't load pre-compiled query because"
                             << " the external module " << lURI
                             << " is not available using the registered"
                             << " SerializationCallback");
      }
    }
  }
}


/***************************************************************************//**
  Target namespaces of zorba builtin modules
********************************************************************************/
#define NS_PRE static_context::ZORBA_NS_PREFIX

const zstring
static_context::ZORBA_NS_PREFIX = "http://www.zorba-xquery.com/";

const zstring
static_context::ZORBA_MATH_FN_NS = NS_PRE + "modules/math";

const zstring
static_context::ZORBA_BASE64_FN_NS = NS_PRE + "modules/base64";

const zstring
static_context::ZORBA_NODEREF_FN_NS = NS_PRE + "modules/node-reference";

const zstring
static_context::ZORBA_XQDDF_FN_NS = static_context::ZORBA_NS_PREFIX + "modules/xqddf";

const zstring
static_context::ZORBA_SCHEMA_FN_NS = static_context::ZORBA_NS_PREFIX + "modules/schema";

const zstring
static_context::ZORBA_TIDY_FN_NS = static_context::ZORBA_NS_PREFIX + "modules/tidy";

const zstring
static_context::ZORBA_JSON_FN_NS = static_context::ZORBA_NS_PREFIX + "modules/json";

const zstring
static_context::ZORBA_XQDOC_FN_NS = static_context::ZORBA_NS_PREFIX + "modules/xqdoc";

const zstring
static_context::ZORBA_RANDOM_FN_NS = static_context::ZORBA_NS_PREFIX + "modules/random";

const zstring
static_context::ZORBA_INTROSP_SCTX_FN_NS = static_context::ZORBA_NS_PREFIX + "modules/introspection/sctx";

const zstring
static_context::ZORBA_INTROSP_DCTX_FN_NS = NS_PRE + "modules/introspection/dctx";

const zstring
static_context::ZORBA_UTIL_FN_NS = NS_PRE + "zorba/util-functions";

const zstring
static_context::ZORBA_FOP_FN_NS = NS_PRE + "zorba/fop-functions";


/***************************************************************************//**
  Target namespaces of zorba reserved modules
********************************************************************************/
const zstring
static_context::XQUERY_OP_NS = ZORBA_NS_PREFIX + "internal/xquery-ops";

const zstring
static_context::ZORBA_OP_NS = ZORBA_NS_PREFIX + "internal/zorba-ops";


/***************************************************************************//**
  Static method to check if a given target namespace identifies a zorba
  builtin module.
********************************************************************************/
bool static_context::is_builtin_module(const zstring& ns)
{
  if (ns.compare(0, ZORBA_NS_PREFIX.size(), ZORBA_NS_PREFIX) == 0)
  {
    return (ns == ZORBA_MATH_FN_NS ||
            ns == ZORBA_BASE64_FN_NS ||
            ns == ZORBA_NODEREF_FN_NS ||
            ns == ZORBA_XQDDF_FN_NS ||
            ns == ZORBA_SCHEMA_FN_NS ||
            ns == ZORBA_TIDY_FN_NS ||
            ns == ZORBA_JSON_FN_NS ||
            ns == ZORBA_XQDOC_FN_NS ||
            ns == ZORBA_RANDOM_FN_NS ||
            ns == ZORBA_INTROSP_SCTX_FN_NS ||
            ns == ZORBA_INTROSP_DCTX_FN_NS ||
            ns == ZORBA_UTIL_FN_NS ||
            ns == ZORBA_FOP_FN_NS);
  }

  return false;
}


/***************************************************************************//**
  Static method to check if a given target namespace identifies a zorba non
  pure builtin module, i.e. a builtin module that, in addition to builtin 
  external functions, contains variable declarations and/or udfs.
********************************************************************************/
bool static_context::is_non_pure_builtin_module(const zstring& ns)
{
  if (ns.compare(0, ZORBA_NS_PREFIX.size(), ZORBA_NS_PREFIX) == 0)
  {
    return (ns == ZORBA_MATH_FN_NS ||
            ns == ZORBA_INTROSP_SCTX_FN_NS);
  }

  return false;
}


/***************************************************************************//**
  Static method to check if a given target namespace identifies a zorba
  reserved module.
********************************************************************************/
bool static_context::is_reserved_module(const zstring& ns)
{
  if (ns.compare(0, ZORBA_NS_PREFIX.size(), ZORBA_NS_PREFIX) == 0)
  {
    return (ns == ZORBA_OP_NS || ns == XQUERY_OP_NS);
  }

  return false;
}


/***************************************************************************//**
  Default Constructor.
********************************************************************************/
static_context::static_context()
  :
  theParent(NULL),
  theTraceStream(NULL),
  theImportedBuiltinModules(NULL),
  theBaseUriInfo(NULL),
  theDocResolver(0),
  theColResolver(0),
  theExternalModulesMap(NULL),
  theNamespaceBindings(NULL),
  theHaveDefaultElementNamespace(false),
  theHaveDefaultFunctionNamespace(false),
  theVariablesMap(NULL),
  theFunctionMap(NULL),
  theFunctionArityMap(NULL),
  theCollectionMap(NULL),
  theCollectionCallback(0),
  theCollectionCallbackData(0),
  theW3CCollectionMap(NULL),
  theIndexMap(NULL),
  theIndexCallback(0),
  theIndexCallbackData(0),
  theICMap(NULL),
  theDocumentMap(NULL),
  theCollationMap(NULL),
  theDefaultCollation(NULL),
  theOptionMap(NULL),
#ifndef ZORBA_NO_FULL_TEXT
  theFTMatchOptions(NULL),
#endif /* ZORBA_NO_FULL_TEXT */
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
  theImportedBuiltinModules(NULL),
  theBaseUriInfo(NULL),
  theDocResolver(0),
  theColResolver(0),
  theExternalModulesMap(NULL),
  theNamespaceBindings(NULL),
  theHaveDefaultElementNamespace(false),
  theHaveDefaultFunctionNamespace(false),
  theVariablesMap(NULL),
  theFunctionMap(NULL),
  theFunctionArityMap(NULL),
  theCollectionMap(0),
  theCollectionCallback(0),
  theCollectionCallbackData(0),
  theW3CCollectionMap(NULL),
  theIndexMap(NULL),
  theIndexCallback(0),
  theIndexCallbackData(0),
  theICMap(NULL),
  theDocumentMap(NULL),
  theCollationMap(NULL),
  theDefaultCollation(NULL),
  theOptionMap(NULL),
#ifndef ZORBA_NO_FULL_TEXT
  theFTMatchOptions(NULL),
#endif /* ZORBA_NO_FULL_TEXT */
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
  theTraceStream(NULL),
  theImportedBuiltinModules(NULL),
  theBaseUriInfo(NULL),
  theDocResolver(0),
  theColResolver(0),
  theExternalModulesMap(NULL),
  theNamespaceBindings(NULL),
  theHaveDefaultElementNamespace(false),
  theHaveDefaultFunctionNamespace(false),
  theVariablesMap(NULL),
  theFunctionMap(NULL),
  theFunctionArityMap(NULL),
  theCollectionMap(0),
  theCollectionCallback(0),
  theCollectionCallbackData(0),
  theW3CCollectionMap(NULL),
  theIndexMap(0),
  theIndexCallback(0),
  theIndexCallbackData(0),
  theICMap(0),
  theDocumentMap(NULL),
  theCollationMap(NULL),
  theDefaultCollation(NULL),
  theOptionMap(NULL),
#ifndef ZORBA_NO_FULL_TEXT
  theFTMatchOptions(NULL),
#endif /* ZORBA_NO_FULL_TEXT */
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
  if (theImportedBuiltinModules)
    delete theImportedBuiltinModules;

  if (theExternalModulesMap)
  {
    ExternalModuleMap::iterator ite = theExternalModulesMap->begin();
    ExternalModuleMap::iterator end = theExternalModulesMap->end();
    for(; ite != end; ++ite)
    {
      const ctx_module_t& val = ite.getValue();
      if (val.dyn_loaded_module)
      {
        val.module->destroy();
      }
    }

    delete theExternalModulesMap;
  }

  set_document_uri_resolver(0);
  set_collection_uri_resolver(0);

  if (theVariablesMap)
    delete theVariablesMap;

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

#ifndef ZORBA_NO_FULL_TEXT
  delete theFTMatchOptions;
#endif /* ZORBA_NO_FULL_TEXT */

  if (theDecimalFormats)
    delete theDecimalFormats;

  if (theBaseUriInfo)
    delete theBaseUriInfo;

  if (theParent)
    RCHelper::removeReference(theParent);

  {
    std::vector<ModuleImportChecker*>::iterator i =
        theModuleImportCheckers.begin();
    for (; i != theModuleImportCheckers.end(); ++i) {
      delete *i;
    }
  }
}


/*******************************************************************************

********************************************************************************/
void static_context::serialize_resolvers(serialization::Archiver& ar)
{
  bool lUserDocResolver, lUserColResolver;
  size_t lNumModuleResolvers;
  if (ar.is_serializing_out())
  {
    // serialize out: remember whether a doc and collection
    //                resolver was registered by the user
    lUserDocResolver = ((theDocResolver != NULL) && (dynamic_cast<StandardDocumentURIResolver*>(theDocResolver) == NULL));
    lUserColResolver = ((theColResolver != NULL) && (dynamic_cast<StandardCollectionURIResolver*>(theColResolver) == NULL));
    lNumModuleResolvers = theModuleResolvers.size();

	  ar.set_is_temp_field(true);
    ar & lUserDocResolver;
    ar & lUserColResolver;
    ar & lNumModuleResolvers;
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
    ar & lNumModuleResolvers; // number of module resolvers passed by the user
	  ar.set_is_temp_field(false);

    // callback required but not available
    if ((lUserDocResolver || lUserColResolver || lNumModuleResolvers) && !lCallback)
    {
      ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                           "Couldn't load pre-compiled query because"
                           << " a document, collection, or module resolver"
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
    if (lNumModuleResolvers) {
      for (size_t i = 0; i < lNumModuleResolvers; ++i) {
        ModuleURIResolver* lModResolver = lCallback->getModuleURIResolver(i);
        if (!lModResolver) {
          ZORBA_ERROR_DESC_OSS(SRL0013_UNABLE_TO_LOAD_QUERY,
                               "Couldn't load pre-compiled query because"
                               " no module URI resolver could be retrieved"
                               " using the given SerializationCallback");
        }
        add_module_uri_resolver(new ModuleURIResolverWrapper(lModResolver));
      }
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
      bool lTraceStream =  lCallback->getTraceStream(theTraceStream);
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
    bool  parent_is_root = check_parent_is_root();
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

  ar & theModuleNamespace;
  ar & theImportedBuiltinModules;

  ar & theBaseUriInfo;

  serialize_resolvers(ar);
  serialize_tracestream(ar);

  ar & theModulePaths;

  ar & theExternalModulesMap;

  SERIALIZE_TYPEMANAGER_RCHANDLE(TypeManager, theTypemgr);

  ar & theNamespaceBindings;
  ar & theDefaultElementNamespace;
  ar & theHaveDefaultElementNamespace;
  ar & theDefaultFunctionNamespace;
  ar & theHaveDefaultFunctionNamespace;

  ar & theCtxItemType;

  ar & theVariablesMap;

  ar.set_serialize_only_for_eval(true);
  ar & theFunctionMap;
  ar & theFunctionArityMap;
  ar.set_serialize_only_for_eval(false);

  ar & theCollectionMap;

  ar & theW3CCollectionMap;
  ar & theDefaultW3CCollectionType;

  ar & theIndexMap;

  ar & theICMap;

  ar & theDocumentMap;

  ar & theCollationMap;
  ar & theDefaultCollation;

  ar & theOptionMap;
#ifndef ZORBA_NO_FULL_TEXT
  ar & theFTMatchOptions;
#endif /* ZORBA_NO_FULL_TEXT */

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


/***************************************************************************//**

********************************************************************************/
void static_context::add_imported_builtin_module(const zstring& ns)
{
  if (theImportedBuiltinModules == NULL)
  {
    theImportedBuiltinModules = new std::vector<zstring>;
  }

  theImportedBuiltinModules->push_back(ns);
}


/***************************************************************************//**

********************************************************************************/
bool static_context::is_imported_builtin_module(const zstring& ns)
{
  static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theImportedBuiltinModules)
    {
      std::vector<zstring>::const_iterator ite = sctx->theImportedBuiltinModules->begin();
      std::vector<zstring>::const_iterator end = sctx->theImportedBuiltinModules->end();
      for (; ite != end; ++ite)
      {
        if (*ite == ns)
          return true;
      }
    }

    sctx = sctx->theParent;
  }

  return false;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Base URI                                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
zstring static_context::get_implementation_baseuri() const
{
  return reinterpret_cast<root_static_context*>(&GENV_ROOT_STATIC_CONTEXT)->
         theImplementationBaseUri;
}


/***************************************************************************//**

********************************************************************************/
bool static_context::get_encapsulating_entity_uri(zstring& res) const
{
  const static_context* sctx = this;
  while (sctx != NULL)
  {
    if (sctx->theBaseUriInfo != NULL &&
        sctx->theBaseUriInfo->theHaveEncapsulatingEntityUri)
    {
      res = sctx->theBaseUriInfo->theEncapsulatingEntityUri;
      return true;
    }

    sctx = sctx->theParent;
  }

  return false;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_encapsulating_entity_uri(const zstring& uri)
{
  if (theBaseUriInfo == NULL)
  {
    theBaseUriInfo = new BaseUriInfo;
  }

  theBaseUriInfo->theEncapsulatingEntityUri = uri;
  theBaseUriInfo->theHaveEncapsulatingEntityUri = true;

  compute_base_uri();
}


/***************************************************************************//**

********************************************************************************/
bool static_context::get_entity_retrieval_uri(zstring& res) const
{
  const static_context* sctx = this;
  while (sctx != NULL)
  {
    if (sctx->theBaseUriInfo != NULL &&
        sctx->theBaseUriInfo->theHaveEntityRetrievalUri)
    {
      res = sctx->theBaseUriInfo->theEntityRetrievalUri;
      return true;
    }

    sctx = sctx->theParent;
  }

  return false;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_entity_retrieval_uri(const zstring& uri)
{
  if (theBaseUriInfo == NULL)
  {
    theBaseUriInfo = new BaseUriInfo;
  }

  theBaseUriInfo->theEntityRetrievalUri = uri;
  theBaseUriInfo->theHaveEntityRetrievalUri = true;

  compute_base_uri();
}


/***************************************************************************//**

********************************************************************************/
zstring static_context::get_base_uri() const
{
  const static_context* sctx = this;
  while (sctx != NULL)
  {
    if (sctx->theBaseUriInfo != NULL &&
        sctx->theBaseUriInfo->theHaveBaseUri)
    {
      return sctx->theBaseUriInfo->theBaseUri;
    }

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_base_uri(const zstring& uri, bool from_prolog)
{
  if (theBaseUriInfo == NULL)
  {
    theBaseUriInfo = new BaseUriInfo;
  }

  if (from_prolog)
  {
    if (theBaseUriInfo->theHavePrologBaseUri)
    {
      ZORBA_ERROR(XQST0032);
    }

    theBaseUriInfo->thePrologBaseUri = uri;
    theBaseUriInfo->theHavePrologBaseUri = true;
  }
  else
  {
    // overwite existing value of application baseuri, if any
    theBaseUriInfo->theApplicationBaseUri = uri;
    theBaseUriInfo->theHaveApplicationBaseUri = true;
  }

  compute_base_uri();
}


/***************************************************************************//**
  Base Uri Computation

  The from_prolog_baseuri is the one declared in the prolog. The baseuri is set
  explicitly from the C++/C api. If both the from_prolog_baseuri and the baseuri
  are set, the from_prolog_baseuri hides the baseuri.

  For the main module, the entity_retrieval_url is set by default to the name
  of file containing the query we are running. For library modules, it is set
  to the location uri of each module component. It may also be set explicitly
  from the C++/C api.
********************************************************************************/
void static_context::compute_base_uri()
{
  if (theBaseUriInfo == NULL)
  {
    theBaseUriInfo = new BaseUriInfo;
  }

  bool found;

  bool foundUserBaseUri = false;
  zstring userBaseUri;
  zstring encapsulatingUri;
  zstring entityUri;

  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theBaseUriInfo != NULL &&
        sctx->theBaseUriInfo->theHavePrologBaseUri)
    {
      userBaseUri = sctx->theBaseUriInfo->thePrologBaseUri;
      foundUserBaseUri = true;
      break;
    }

    sctx = sctx->theParent;
  }

  if (!foundUserBaseUri)
  {
    sctx = this;

    while (sctx != NULL)
    {
      if (sctx->theBaseUriInfo != NULL &&
          sctx->theBaseUriInfo->theHaveApplicationBaseUri)
      {
        userBaseUri = sctx->theBaseUriInfo->theApplicationBaseUri;
        foundUserBaseUri = true;
        break;
      }

      sctx = sctx->theParent;
    }
  }

  if (foundUserBaseUri)
  {
    try
    {
      URI lCheckValid(userBaseUri);
      if (lCheckValid.is_absolute())
      {
        theBaseUriInfo->theBaseUri = lCheckValid.toString();
        theBaseUriInfo->theHaveBaseUri = true;
        return; // valid (absolute) uri
      }
    }
    catch (error::ZorbaError&)
    {
      // assume it's relative and go on
    }

    /// is relative, needs to be resolved
    found = get_encapsulating_entity_uri(encapsulatingUri);
    if (found)
    {
      URI base(encapsulatingUri);
      URI resolvedURI(base, userBaseUri);
      theBaseUriInfo->theBaseUri = resolvedURI.toString();
      theBaseUriInfo->theHaveBaseUri = true;
      return;
    }

    found = get_entity_retrieval_uri(entityUri);
    if (found)
    {
      URI base(entityUri);
      URI resolvedURI(base, userBaseUri);
      theBaseUriInfo->theBaseUri = resolvedURI.toString();
      theBaseUriInfo->theHaveBaseUri = true;
      return;
    }

    URI base(get_implementation_baseuri());
    URI resolvedURI(base, userBaseUri);
    theBaseUriInfo->theBaseUri = resolvedURI.toString();
    theBaseUriInfo->theHaveBaseUri = true;
    return;
  }

  found = get_encapsulating_entity_uri(encapsulatingUri);
  if (found)
  {
    theBaseUriInfo->theBaseUri = encapsulatingUri;
    theBaseUriInfo->theHaveBaseUri = true;
    return;
  }

  found = get_entity_retrieval_uri(entityUri);
  if (found)
  {
    theBaseUriInfo->theBaseUri = entityUri;
    theBaseUriInfo->theHaveBaseUri = true;
    return;
  }

  theBaseUriInfo->theBaseUri = get_implementation_baseuri();
  theBaseUriInfo->theHaveBaseUri = true;
  return;
}


/***************************************************************************//**

********************************************************************************/
zstring
static_context::resolve_relative_uri(
    const zstring& aUri,
    bool aValidate) const
{
  URI lBaseUri(get_base_uri());
  URI lResolvedUri(lBaseUri, aUri, aValidate);
  return lResolvedUri.toString();
}


/***************************************************************************//**

********************************************************************************/
zstring
static_context::resolve_relative_uri(
    const zstring& aRelativeUri,
    const zstring& aBaseUri,
    bool aValidate) const
{
  URI lBaseUri(aBaseUri);
  URI lResolvedUri(lBaseUri, aRelativeUri, aValidate);
  return lResolvedUri.toString();
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
InternalDocumentURIResolver* static_context::get_document_uri_resolver() const
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
InternalCollectionURIResolver* static_context::get_collection_uri_resolver() const
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
    std::vector<InternalSchemaURIResolver*>& aResolvers) const
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
//  Module import chekcers                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

void static_context::addModuleImportChecker(ModuleImportChecker* aChecker)
{
  theModuleImportCheckers.push_back(aChecker);
}

void static_context::removeModuleImportChecker(ModuleImportChecker* aChecker)
{
  std::vector<ModuleImportChecker*> lCheckers = getAllModuleImportCheckers();
  std::vector<ModuleImportChecker*>::iterator lIter =
      lCheckers.begin();
  for (; lIter != lCheckers.end(); ++lIter)
  {
    if (**lIter == *aChecker) {
      theModuleImportCheckers.erase(lIter);
    }
  }
}

std::vector<ModuleImportChecker*> static_context::getAllModuleImportCheckers() const
{
  std::vector<ModuleImportChecker*> lResult;
  lResult.insert(lResult.end(), theModuleImportCheckers.begin(),
                 theModuleImportCheckers.end());
  static_context* lParent = get_parent();
  if (lParent) {
    std::vector<ModuleImportChecker*> lC = lParent->getAllModuleImportCheckers();
    lResult.insert(lResult.end(), lC.begin(), lC.end());
  }
  return lResult;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Validating Items                                                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

bool
static_context::validate(store::Item* rootElement, store::Item* validatedResult)
{
  zstring xsTns(XML_SCHEMA_NS);
  return validate(rootElement, validatedResult, xsTns);
}

bool 
static_context::validate(store::Item* rootElement, store::Item* validatedResult, 
                         const zstring& targetNamespace)
{
  if ( rootElement->isValidated() )
    return false;
  
  if ( rootElement->getNodeKind() != store::StoreConsts::documentNode ||
       rootElement->getNodeKind() != store::StoreConsts::elementNode)
    return false;
     
#ifndef ZORBA_NO_XMLSCHEMA

  TypeManager* tm = this->get_typemanager();
  zstring docUri; 
  rootElement->getDocumentURI(docUri);
  StaticContextConsts::validation_mode_t lValidationMode = this->validation_mode();

  if (!rootElement->isValidated())
  {
    if (lValidationMode != StaticContextConsts::skip_validation)
    {
      store::Item_t validatedNode;
      store::Item_t typeName;
      QueryLoc loc;

      ParseConstants::validation_mode_t mode = 
          (lValidationMode == StaticContextConsts::strict_validation ?
              ParseConstants::val_strict :
              ParseConstants::val_lax );

      store::Item_t tmp = store::Item_t(validatedResult);
      bool success = Validator::effectiveValidationValue(tmp,
                                                         rootElement,
                                                         typeName,
                                                         tm,
                                                         mode,
                                                         this,
                                                         loc);

      return success;
    }
  }
#endif //ZORBA_NO_XMLSCHEMA
  
  return false;
}

bool 
static_context::validateSimpleContent(zstring& stringValue, 
    store::Item* typeQName, 
    std::vector<store::Item_t>& resultList)
{
  store::NsBindings bindings;
  this->get_namespace_bindings(bindings);
  store::Item_t lTypeQName(typeQName);
  
  Validator::processTextValue(this, this->get_typemanager(), bindings, lTypeQName, stringValue, resultList);
  return true;
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
const zstring& static_context::default_elem_type_ns() const
{
  if (theHaveDefaultElementNamespace || theParent == NULL)
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
    const zstring& ns,
    const QueryLoc& loc)
{
  if (!theHaveDefaultElementNamespace)
  {
    theDefaultElementNamespace = ns;
    theHaveDefaultElementNamespace = true;
  }
  else
  {
    ZORBA_ERROR_LOC(XQST0066, loc);
  }
}


/***************************************************************************//**
  Get the default namespace for function qnames.
********************************************************************************/
const zstring& static_context::default_function_ns() const
{
  if (theHaveDefaultFunctionNamespace || theParent == NULL)
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
   const zstring& ns,
   const QueryLoc& loc)
{
  if (!theHaveDefaultFunctionNamespace)
  {
    theDefaultFunctionNamespace = ns;
    theHaveDefaultFunctionNamespace = true;
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
    const zstring& prefix,
    const zstring& ns,
    const QueryLoc& loc,
    const XQUERY_ERROR& err)
{
  if (theNamespaceBindings == NULL)
  {
    theNamespaceBindings = new NamespaceBindings(16, false);
  }

  zstring temp(ns);

  if (!theNamespaceBindings->insert(prefix, temp))
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
    zstring& ns,
    const zstring& prefix,
    const QueryLoc& loc,
    const XQUERY_ERROR& err) const
{
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
  else if (!prefix.empty() && ns.empty())
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
    const zstring& default_ns,
    const zstring& prefix,
    const zstring& local,
    const QueryLoc& loc) const
{
  if (prefix.empty())
  {
    ITEM_FACTORY->createQName(qname, default_ns, prefix, local);
  }
  else
  {
    zstring ns;
    lookup_ns(ns, prefix, loc);
    ITEM_FACTORY->createQName(qname, ns, prefix, local);
  }
}


/***************************************************************************//**

********************************************************************************/
void static_context::get_namespace_bindings(store::NsBindings& bindings) const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theNamespaceBindings != NULL)
    {
      NamespaceBindings::iterator ite = sctx->theNamespaceBindings->begin();
      NamespaceBindings::iterator end = sctx->theNamespaceBindings->end();

      for (; ite != end; ++ite)
      {
        std::pair<zstring, zstring> binding = (*ite);

        // Ignore duplicates
        const zstring& prefix = binding.first;
        ulong numBindings = bindings.size();
        bool found = 0;
        for (unsigned int i = 0; i < numBindings; ++i)
        {
          if (bindings[i].first == prefix)
          {
            found = 1;
            break;
          }
        }

        if (!found)
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
void static_context::bind_var(
    var_expr_t& varExpr,
    const QueryLoc& loc,
    const XQUERY_ERROR& err)
{
  if (theVariablesMap == NULL)
  {
    theVariablesMap = new VariableMap(0, NULL, 8, false);
  }

  store::Item* qname = varExpr->get_name();

  if (!theVariablesMap->insert(qname, varExpr))
  {
    ZORBA_ERROR_LOC_PARAM(err,loc, qname->getStringValue(), "");
  }
}


/***************************************************************************//**

********************************************************************************/
var_expr* static_context::lookup_var(
    const store::Item* qname,
    const QueryLoc& loc,
    const XQUERY_ERROR& err) const
{
  store::Item* qname2 = const_cast<store::Item*>(qname);

  const static_context* sctx = this;
  var_expr_t varExpr;

  while (sctx != NULL)
  {
    if (sctx->theVariablesMap != NULL &&
        sctx->theVariablesMap->get(qname2, varExpr))
    {
      return varExpr.getp();
    }

    sctx = sctx->theParent;
  }

  if (err != MAX_ZORBA_ERROR_CODE)
  {
    ZORBA_ERROR_LOC_PARAM(err, loc, qname->getStringValue().c_str(), "");
  }

  return NULL;
}


/***************************************************************************//**
  This method is used by the debuger
********************************************************************************/
void static_context::getVariables(std::vector<std::string>& aResult) const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theVariablesMap != NULL)
    {
      VariableMap::iterator ite = sctx->theVariablesMap->begin();
      VariableMap::iterator end = sctx->theVariablesMap->end();

      for (; ite != end; ++ite)
      {
        const var_expr* lExpr = ite.getValue();
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
          lType = lQname->getLocalName().str();
          lType += ":";
          lType += lQname->getNamespace().str();
        }

        if (lExpr->is_sequential())
        {
          lType += "*";
        }

        aResult.push_back(lType);

        std::string varName = lExpr->get_name()->getLocalName().str();
        if (! lExpr->get_name()->getNamespace().empty())
        {
          varName += ":";
          varName += lExpr->get_name()->getNamespace().str();
        }
        aResult.push_back(varName);
      }
    }

    sctx = sctx->theParent;
  }
}


/***************************************************************************//**
  This method is used by introspection.
********************************************************************************/
void static_context::getVariables(std::vector<var_expr_t>& vars) const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theVariablesMap != NULL)
    {
      VariableMap::iterator ite = sctx->theVariablesMap->begin();
      VariableMap::iterator end = sctx->theVariablesMap->end();

      for (; ite != end; ++ite)
      {
        ulong numVars = vars.size();
        ulong i = 0;
        for (; i < numVars; ++i)
        {
          if (vars[i]->get_name()->equals((*ite).first))
            break;
        }

        if (i == numVars)
          vars.push_back((*ite).second);
      }
    }

    sctx = sctx->theParent;
  }
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_context_item_type(xqtref_t& t)
{
  theCtxItemType = t;
}


/***************************************************************************//**

********************************************************************************/
const XQType* static_context::get_context_item_type() const
{
  const static_context* sctx = this;
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
    function_t& f,
    ulong arity,
    const QueryLoc& loc)
{
  store::Item* qname = f->getName();

  if (!is_global_root_sctx() && lookup_fn(qname, arity) != NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XQST0034, loc,
                          qname->getStringValue(),
                          loc.getFilename());
  }

  if (theFunctionMap == NULL)
  {
    ulong size = (is_global_root_sctx() ? 500 : 32);
    theFunctionMap = new FunctionMap(0, NULL, size, false);
  }

  FunctionInfo fi(f);

  if (!theFunctionMap->insert(qname, fi))
  {
    // There is already a function F with the given qname in theFunctionMap.
    // First, check if F is the same as f, which implies that f is disabled.
    // In this case, re-enable f. Otherwise, we have to use theFunctionArityMap.
    if (fi.theFunction == f)
    {
      ZORBA_ASSERT(fi.theIsDisabled);
      fi.theIsDisabled = false;
      return;
    }

    fi.theFunction = f;
    fi.theIsDisabled = false;

    ZORBA_ASSERT(!f->isVariadic());

    if (theFunctionArityMap == NULL)
    {
      theFunctionArityMap = new FunctionArityMap(0, NULL, 16, false);
    }

    std::vector<FunctionInfo>* fv = 0;

    if (theFunctionArityMap->get(qname, fv))
    {
      ulong numFunctions = fv->size();
      for (ulong i = 0; i < numFunctions; ++i)
      {
        if ((*fv)[i].theFunction == f)
        {
          ZORBA_ASSERT((*fv)[i].theIsDisabled);
          (*fv)[i].theIsDisabled = false;
          return;
        }
      }

      fv->push_back(fi);
    }
    else
    {
      fv = new std::vector<FunctionInfo>(1);
      (*fv)[0] = fi;
      theFunctionArityMap->insert(qname, fv);
    }
  }
}


/***************************************************************************//**
  Remove the function with the given qname and arity from the in-scope functions
  of this sctx.
********************************************************************************/
void static_context::unbind_fn(
    const store::Item* qname,
    ulong arity)
{
  ZORBA_ASSERT(!is_global_root_sctx());

  function* f = lookup_fn(qname, arity);

  if (f == NULL)
    return;

  if (theFunctionMap == NULL)
  {
    theFunctionMap = new FunctionMap(0, NULL, 32, false);
  }

  FunctionInfo fi(f, true);
  store::Item* qname2 = const_cast<store::Item*>(f->getName());

  if (theFunctionMap->get(qname2, fi))
  {
    if (fi.theFunction.getp() == f)
    {
      fi.theIsDisabled = true;
      theFunctionMap->update(qname2, fi);
      return;
    }

    if (theFunctionArityMap == NULL)
    {
      theFunctionArityMap = new FunctionArityMap(0, NULL, 16, false);
    }

    std::vector<FunctionInfo>* fv = NULL;

    if (theFunctionArityMap->get(qname2, fv))
    {
      ulong numFunctions = fv->size();
      for (ulong i = 0; i < numFunctions; ++i)
      {
        if ((*fv)[i].theFunction.getp() == f)
        {
          (*fv)[i].theIsDisabled = true;
          return;
        }
      }
    }

    fv = new std::vector<FunctionInfo>(1);
    fi.theIsDisabled = true;
    (*fv)[0] = fi;
    theFunctionArityMap->insert(qname2, fv);
  }
  else
  {
    theFunctionMap->insert(qname2, fi);
  }
}


/***************************************************************************//**
  Search the static-context tree, starting from "this" and moving upwards,
  looking for the 1st sctx obj that contains a binding for a function with
  the given qname and arity. If no such binding is found return NULL. Otherwise,
  return the associated function object (which may be NULL if the function
  was disabled).
********************************************************************************/
function* static_context::lookup_fn(
    const store::Item* qname,
    ulong arity)
{
  FunctionInfo fi;
  store::Item* qname2 = const_cast<store::Item*>(qname);

  static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theFunctionMap != NULL && sctx->theFunctionMap->get(qname2, fi))
    {
      function* f = fi.theFunction.getp();

      if (f->getArity() == arity || f->isVariadic())
      {
        return (fi.theIsDisabled ? NULL : f);
      }

      std::vector<FunctionInfo>* fv = NULL;

      if (sctx->theFunctionArityMap != NULL &&
          sctx->theFunctionArityMap->get(qname2, fv))
      {
        ulong numFunctions = fv->size();
        for (ulong i = 0; i < numFunctions; ++i)
        {
          if ((*fv)[i].theFunction->getArity() == arity)
            return ((*fv)[i].theIsDisabled ? NULL : (*fv)[i].theFunction.getp());
        }
      }
    }

    sctx = sctx->theParent;
  }

  return NULL;
}


/***************************************************************************//**
  Find all the in-scope and non-disabled functions in this sctx and its ancestors.
********************************************************************************/
void static_context::get_functions(
    std::vector<function *>& functions) const
{
  std::vector<function*> disabled;
  std::vector<zstring> importedBuiltinModules;

  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theImportedBuiltinModules)
    {
      std::vector<zstring>::const_iterator ite = sctx->theImportedBuiltinModules->begin();
      std::vector<zstring>::const_iterator end = sctx->theImportedBuiltinModules->end();
      for (; ite != end; ++ite)
      {
        importedBuiltinModules.push_back(*ite);
      }
    }

    if (sctx->theFunctionMap != NULL)
    {
      FunctionMap::iterator ite = sctx->theFunctionMap->begin();
      FunctionMap::iterator end = sctx->theFunctionMap->end();

      for (; ite != end; ++ite)
      {
        function* f = (*ite).second.theFunction.getp();

        if (!(*ite).second.theIsDisabled)
        {
          if (std::find(disabled.begin(), disabled.end(), f) == disabled.end())
          {
            // std::cout << "--> adding func: " << f->getName()->getStringValue()
            //           << ", params: " << f->getSignature().paramCount()
            //           << " with addr: " << std::hex << f << std::endl;
            if (f->isBuiltin())
            {
              assert(sctx->is_global_root_sctx());

              const zstring& ns = f->getName()->getNamespace();

              if (ns != XQUERY_FN_NS)
              {
                if (ns == XQUERY_OP_NS || ns == ZORBA_OP_NS)
                  continue;

                std::vector<zstring>::const_iterator ite = importedBuiltinModules.begin();
                std::vector<zstring>::const_iterator end = importedBuiltinModules.end();
                for (; ite != end; ++ite)
                {
                  if (ns == *ite)
                    break;
                }

                if (ite == end)
                  continue;
              }
            }
            else
            {
              assert(!sctx->is_global_root_sctx());
            }

            functions.push_back(f);
          }
        }
        else
        {
          disabled.push_back(f);
        }
      }
    }

    if (sctx->theFunctionArityMap != NULL)
    {
      FunctionArityMap::iterator ite = sctx->theFunctionArityMap->begin();
      FunctionArityMap::iterator end = sctx->theFunctionArityMap->end();

      for (; ite != end; ++ite)
      {
        std::vector<FunctionInfo>* fv = (*ite).second;

        ulong numFunctions = fv->size();
        for (ulong i = 0; i < numFunctions; ++i)
        {
          function* f = (*fv)[i].theFunction.getp();

          if (!(*fv)[i].theIsDisabled)
          {
            if (std::find(disabled.begin(), disabled.end(), f) == disabled.end())
            {
              // std::cout << "--> adding func: " << f->getName()->getStringValue()
              //           << ", params: " << f->getSignature().paramCount()
              //           << " with addr: " << std::hex << f << std::endl;
              if (f->isBuiltin())
              {
                assert(sctx->is_global_root_sctx());

                const zstring& ns = f->getName()->getNamespace();

                if (ns != XQUERY_FN_NS)
                {
                  if (ns == XQUERY_OP_NS || ns == ZORBA_OP_NS)
                    continue;

                  std::vector<zstring>::const_iterator ite = importedBuiltinModules.begin();
                  std::vector<zstring>::const_iterator end = importedBuiltinModules.end();
                  for (; ite != end; ++ite)
                  {
                    if (ns == *ite)
                      break;
                  }

                  if (ite == end)
                    continue;
                }
              }
              else
              {
                assert(!sctx->is_global_root_sctx());
              }

              functions.push_back(f);
            }
          }
          else
          {
            disabled.push_back(f);
          }
        }
      }
    }

    sctx = sctx->theParent;
  }
}


/***************************************************************************//**
  Find all the functions with the given qname.
********************************************************************************/
void static_context::find_functions(
    const store::Item* qname,
    std::vector<function *>& functions) const
{
  FunctionInfo fi;
  store::Item* qname2 = const_cast<store::Item*>(qname);

  if (theFunctionMap != NULL && theFunctionMap->get(qname2, fi))
  {
    if (!fi.theIsDisabled)
      functions.push_back(fi.theFunction.getp());
  }

  std::vector<FunctionInfo>* fv = NULL;

  if (theFunctionArityMap != NULL && theFunctionArityMap->get(qname2, fv))
  {
    ulong numFunctions = fv->size();
    for (ulong i = 0; i < numFunctions; ++i)
    {
      if (!(*fv)[i].theIsDisabled)
        functions.push_back((*fv)[i].theFunction.getp());
    }
  }

  if (theParent != NULL)
    theParent->find_functions(qname2, functions);
}


/***************************************************************************//**
  Register an external module.  This module can be used to retrieve external
  functions defined in the target namespace of the module.

  If aDynamicallyLoaded is false, then the external module to register has been
  created and is provided directly by the application. Otherwise, it is an
  external module that is created and loaded dynamically by zorba from a lib
  file that is stored somewhere in the in-scope module paths (see
  StandardModuleURIResolver::getExternalModule method and how this method is
  invoked by the static_context::lookup_external_function method below).
********************************************************************************/
void static_context::bind_external_module(
    ExternalModule* aModule,
    bool aDynamicallyLoaded)
{
  if (theExternalModulesMap == NULL)
  {
    theExternalModulesMap = new ExternalModuleMap(8, false);
  }

  zstring uri = Unmarshaller::getInternalString(aModule->getURI());
  ctx_module_t modinfo;
  modinfo.module = aModule;
  modinfo.dyn_loaded_module = aDynamicallyLoaded;
  modinfo.sctx = this;

  if (!theExternalModulesMap->insert(uri, modinfo))
  {
    ZORBA_ERROR_DESC_OSS(API0019_FUNCTION_ALREADY_REGISTERED,
                         "The external module with URI "
                         << uri << " is already registered");
  }
}


/***************************************************************************//**
  Find and return the implementation of an external function, given its namespace
  URI and local name.
********************************************************************************/
StatelessExternalFunction* static_context::lookup_external_function(
    const zstring& aURI,
    const zstring& aLocalName)
{
  // get the module for the given namespace
  bool found = false;
  ctx_module_t modinfo;
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theExternalModulesMap != NULL &&
        sctx->theExternalModulesMap->get(aURI, modinfo))
    {
      found = true;
      break;
    }

    sctx = sctx->theParent;
  }

  ExternalModule* lModule = 0;

  // If the module is not yet in the static context we try to get it from the
  // URI resolver
  if (!found)
  {
    StandardModuleURIResolver* moduleResolver = GENV.getModuleURIResolver();
    lModule = moduleResolver->getExternalModule(aURI, *this);

    // no way to get the module
    if (!lModule)
      return NULL;

    // remember the module for future use
    bind_external_module(lModule, true);
  }
  else
  {
    lModule = modinfo.module;
  }

  // get the function from this module.
  // return 0 if not found
  return lModule->getExternalFunction(aLocalName.str());
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Documents                                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**
  This method may be called only on an application-created sctx.
********************************************************************************/
void static_context::bind_document(const zstring& uri, xqtref_t& type)
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
const XQType* static_context::lookup_document(const zstring& uri)
{
  xqtref_t type;

  static_context* sctx = this;
  while (sctx != NULL)
  {
    if (sctx->theDocumentMap && sctx->theDocumentMap->get(uri, type))
      return type.getp();

    sctx = sctx->theParent;
  }

  return NULL;
}

void static_context::get_all_documents(std::vector<zstring>& documents)
{
  static_context* sctx = this;
  documents.clear();

  while (sctx != NULL)
  {
    if (sctx->theDocumentMap != NULL)
    {
      for(DocumentMap::iterator it = sctx->theDocumentMap->begin();
          it != sctx->theDocumentMap->end();
          ++it)
        documents.push_back(it.getKey());
    }

    sctx = sctx->theParent;
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  W3C Collections                                                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**
  This method may be called only on an application-created sctx.
********************************************************************************/
void static_context::bind_w3c_collection(zstring& uri, xqtref_t& type)
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
const XQType* static_context::lookup_w3c_collection(const zstring& uri)
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
    if (sctx->theDefaultW3CCollectionType != NULL)
      return sctx->theDefaultW3CCollectionType.getp();

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

collection_update_property_t
to_collection_update_property(const StaticContextConsts::declaration_property_t& p)
{
  collection_update_property_t lRes;
  switch (p) {
    case StaticContextConsts::decl_const: lRes = coll_const; break;
    case StaticContextConsts::decl_append_only: lRes = coll_append_only; break;
    case StaticContextConsts::decl_queue: lRes = coll_queue; break;
    case StaticContextConsts::decl_mutable: lRes = coll_mutable; break;
    default:
      ZORBA_ASSERT(false);
  }
  return lRes;
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


collection_order_property_t
to_collection_order_property(const StaticContextConsts::declaration_property_t& p)
{
  collection_order_property_t lRes;
  switch (p) {
    case StaticContextConsts::decl_ordered: lRes = coll_ordered; break;
    case StaticContextConsts::decl_unordered: lRes = coll_unordered; break;
    default:
      ZORBA_ASSERT(false);
  }
  return lRes;
}

collection_node_modifier_t
to_collection_node_modifier(const StaticContextConsts::node_modifier_t& p)
{
  collection_node_modifier_t lRes;
  switch (p) {
    case StaticContextConsts::read_only: lRes = coll_node_const; break;
    case StaticContextConsts::mutable_node: lRes = coll_node_mutable; break;
    default:
      ZORBA_ASSERT(false);
  }
  return lRes;
}


/***************************************************************************//**

********************************************************************************/
void static_context::call_collection_callback(const StaticallyKnownCollection_t& aColl)
{
  if (theCollectionCallback)
  {
    // wrap the collection information into an object known in the api
    DeclaredCollection lDeclaredColl;
    lDeclaredColl.theName = aColl->getName();
    lDeclaredColl.theUpdateProperty = to_collection_update_property(aColl->getUpdateProperty());
    lDeclaredColl.theOrderProperty = to_collection_order_property(aColl->getOrderProperty());
    lDeclaredColl.theNodeModifier = to_collection_node_modifier(aColl->getNodeModifier());
    theCollectionCallback(lDeclaredColl, theCollectionCallbackData);
  }
  else
  {
    if (theParent)
    {
      theParent->call_collection_callback(aColl);
    }
  }
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_collection_callback(
    CollectionCallback aCallbackFunction,
    void* aCallbackData)
{
  theCollectionCallback = aCallbackFunction;
  theCollectionCallbackData = aCallbackData;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  XQDDF Indexes                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
void static_context::bind_index(IndexDecl_t& index, const QueryLoc& loc)
{
  store::Item* qname = const_cast<store::Item*>(index->getName());

  if (lookup_index(qname) != NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XDST0021_INDEX_ALREADY_DECLARED, loc,
                          qname->getStringValue(),  "");
  }

  if (theIndexMap == NULL)
    theIndexMap = new IndexMap(0, NULL, 8, false);

  theIndexMap->insert(qname, index);
}


/***************************************************************************//**

********************************************************************************/
IndexDecl* static_context::lookup_index(const store::Item* qname) const
{
  IndexDecl_t index;
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
  return new SctxMapIterator<IndexDecl>(this, &static_context::index_map);
}


/******************************************************************************

********************************************************************************/
index_maintenance_mode_t
to_index_maintenance_mode(const IndexDecl::MaintenanceMode& mode)
{
  index_maintenance_mode_t lRes;
  switch (mode)
  {
  case IndexDecl::MANUAL: lRes = index_manual; break;
  case IndexDecl::REBUILD: lRes = index_automatic; break;
  case IndexDecl::DOC_MAP: lRes = index_manual; break; // TODO
  default: ZORBA_ASSERT(false);
  }
  return lRes;
}

/******************************************************************************

********************************************************************************/
index_container_kind_t
to_index_container_kind(const IndexDecl::ContainerKind& kind)
{
  index_container_kind_t lRes;
  switch (kind)
  {
    case IndexDecl::HASH: lRes = index_hash; break;
    case IndexDecl::TREE: lRes = index_tree; break;
    default: ZORBA_ASSERT(false);
  }
  return lRes;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_index_callback(
    IndexCallback aCallbackFunction,
    void* aCallbackData)
{
  theIndexCallback = aCallbackFunction;
  theIndexCallbackData = aCallbackData;
}


/******************************************************************************

********************************************************************************/
void static_context::call_index_callback(const IndexDecl_t& index)
{
  if (theIndexCallback)
  {
    DeclaredIndex lDeclaredIndex;
    lDeclaredIndex.theName = index->getName();
    lDeclaredIndex.theMaintenanceMode =
      to_index_maintenance_mode(index->getMaintenanceMode());
    lDeclaredIndex.theContainerKind =
      to_index_container_kind(index->getMethod());
    theIndexCallback(lDeclaredIndex, theIndexCallbackData);
  }
  else
  {
    if (theParent)
    {
      static_cast<static_context*>(theParent)->call_index_callback(index);
    }
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  XQDDF Integrity Constraints                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
void static_context::bind_ic(
    ValueIC_t& vic,
    const QueryLoc& loc)
{
  store::Item* qname = vic->getICName();

  if (lookup_ic(qname) != NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XDST0041_IC_IS_ALREADY_DECLARED, loc,
                          qname->getStringValue(),  "");
  }

  if (theICMap == NULL)
    theICMap = new ICMap(0, NULL, 8, false);

  theICMap->insert(qname, vic);
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

  std::string resolvedURI = resolve_relative_uri(uri).str();

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
  std::string resolvedURI = resolve_relative_uri(uri).str();

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
  std::string resolvedURI = resolve_relative_uri(uri).str();

  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theCollationMap != NULL)
    {
      CollationMap::iterator ite = sctx->theCollationMap->find(resolvedURI);

      if (ite != sctx->theCollationMap->end())
      {
        return ite->second;
      }
    }

    sctx = sctx->theParent;
  }

  ZORBA_ERROR_LOC_DESC_OSS(FOCH0002, loc,
                           "Collation " << resolvedURI << " not found in static context.");
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

  zstring resolvedUri = resolve_relative_uri(uri);

  theDefaultCollation = new std::string(resolvedUri.c_str());
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
    const zstring& value)
{
  if (theOptionMap == NULL)
  {
    theOptionMap = new OptionMap(0, NULL, 8, false);
  }

  PrologOption option(qname, value);

  store::Item* qname2 = option.theName.getp();

  if (!theOptionMap->update(qname2, option))
  {
    theOptionMap->insert(qname2, option);
  }
}


/***************************************************************************//**

********************************************************************************/
bool static_context::lookup_option(
    const store::Item* qname,
    zstring& value) const
{
  store::Item* qname2 = const_cast<store::Item*>(qname);
  PrologOption option;
  const static_context* sctx = this;
  while (sctx != NULL)
  {
    if (sctx->theOptionMap && sctx->theOptionMap->get(qname2, option))
    {
      value = option.theValue;
      return true;
    }
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


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Module Import                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**
  Merge the static context of a module with this static context. Only functions
  and variables defined in the module are included in this static context.
********************************************************************************/
void static_context::import_module(const static_context* module, const QueryLoc& loc)
{
  if (module->theVariablesMap)
  {
    if (theVariablesMap == NULL)
    {
      theVariablesMap = new VariableMap(0,
                                        NULL,
                                        module->theVariablesMap->capacity(),
                                        false);
    }

    VariableMap::iterator ite = module->theVariablesMap->begin();
    VariableMap::iterator end = module->theVariablesMap->end();
    for (; ite != end; ++ite)
    {
      var_expr_t ve = ite.getValue();

#if 0
      // This check has been moved to the translator (in the translation of
      // a VarRef).
      xqtref_t type = ve->get_return_type();
      if (!TypeOps::is_in_scope(get_typemanager(), *type))
      {
        ZORBA_ERROR_LOC_DESC_OSS(XQST0036, loc,
                                 "The type " << type->toString()
                                 << " is not among the in-scope types"
                                 << " of the importing module");
      }
#endif

      if (!ve->is_private())
        bind_var(ve, loc, XQST0049);
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
      function_t f = (*ite).second.theFunction;
#if 0
      // This check has been moved to the translator (in the translation of
      // a FunctionCall).
      const signature& sign = f->getSignature();
      ulong numArgs = f->getArity();

      for (ulong i = 0; i < numArgs; ++i)
      {
        xqtref_t type = sign[i];
        if (!TypeOps::is_in_scope(get_typemanager(), *type))
        {
          ZORBA_ERROR_LOC_DESC_OSS(XQST0036, loc,
                                   "The type " << type->toString()
                                   << " is not among the in-scope types"
                                   << " of the importing module");
        }
      }

      xqtref_t type = sign.return_type();
      if (!TypeOps::is_in_scope(get_typemanager(), *type))
      {
        ZORBA_ERROR_LOC_DESC_OSS(XQST0036, loc,
                                 "The type " << type->toString()
                                 << " is not among the in-scope types"
                                 << " of the importing module");
      }
#endif
      if (!f->isPrivate())
        bind_fn(f, f->getArity(), loc);
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
      std::vector<FunctionInfo>* fv = (*ite).second;
      ulong num = fv->size();
      for (ulong i = 0; i < num; ++i)
      {
        function_t f = (*fv)[i].theFunction;

#if 0
      // This check has been moved to the translator (in the translation of
      // a FunctionCall).
        const signature& sign = f->getSignature();
        ulong numArgs = f->getArity();

        for (ulong i = 0; i < numArgs; ++i)
        {
          xqtref_t type = sign[i];
          if (!TypeOps::is_in_scope(get_typemanager(), *type))
          {
            ZORBA_ERROR_LOC_DESC_OSS(XQST0036, loc,
                                     "The type " << type->toString()
                                     << " is not among the in-scope types"
                                     << " of the importing module");
          }
        }

        xqtref_t type = sign.return_type();
        if (!TypeOps::is_in_scope(get_typemanager(), *type))
        {
          ZORBA_ERROR_LOC_DESC_OSS(XQST0036, loc,
                                   "The type " << type->toString()
                                   << " is not among the in-scope types"
                                   << " of the importing module");
        }
#endif

        bind_fn(f, f->getArity(), loc);
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
      std::pair<store::Item*, rchandle<IndexDecl> > pair = (*idx_iter);

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
                              pair.first->getStringValue().c_str(), "");
      }
    }
  }
}



} /* namespace zorba */

