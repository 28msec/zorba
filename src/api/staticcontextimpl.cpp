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
#include "api/staticcontextimpl.h"

#include <zorba/error.h>
#include <zorba/external_module.h>
#include <zorba/default_error_handler.h>
#include <zorba/static_context_consts.h>
#include <zorba/typeident.h>
#include <zorba/util/path.h>

#include "store/api/item_factory.h"

#include "zorbatypes/xqpstring.h"
#include "zorbaerrors/error_manager.h"

#include "api/unmarshaller.h"
#include "api/zorbaimpl.h"
#include "api/functionimpl.h"
#include "api/xqueryimpl.h"

#include "context/static_context.h"
#include "context/static_context_consts.h"
#include "context/uri_resolver_wrapper.h"

#include "system/globalenv.h"

#include "types/casting.h"
#include "types/typeops.h"

#include "runtime/util/flowctl_exception.h"

#include "compiler/parser/query_loc.h"

namespace zorba {


/*******************************************************************************
  Create a StaticContextImpl obj as well as an internal static_context obj S.
  S is created as a child of the zorba root sctx. The new StaticContextImpl obj
  owns S, and should delete it during destruction. This constructor is used
  when the application wants to create its own static context to pass it as
  input to one or more queries.
********************************************************************************/
StaticContextImpl::StaticContextImpl(ErrorHandler* aErrorHandler)
  :
  theCtx(0),
  theUserStaticContext(false),
  theErrorHandler(aErrorHandler),
  theUserErrorHandler(true)
{
  theCtx = GENV.getRootStaticContext().create_child_context();
  RCHelper::addReference (theCtx);
  if ( ! theErrorHandler ) 
  {
    theErrorHandler = new DefaultErrorHandler();
    theUserErrorHandler = false;
  }
}


/*******************************************************************************
  Create a StaticContextImpl obj to wrap a given internal static_context obj S.
  The new StaticContextImpl obj does not own S, and should not delete it during
  destruction. This constructor is used when the static context of a query is
  returned to the application (see XQueryImpl::getStaticContext()).
********************************************************************************/
StaticContextImpl::StaticContextImpl(static_context* aCtx, ErrorHandler* aErrorHandler)
  :
  theCtx(aCtx),
  theUserStaticContext(true),
  theErrorHandler(aErrorHandler),
  theUserErrorHandler(true)
{
  if ( ! theErrorHandler ) 
  {
    theErrorHandler = new DefaultErrorHandler();
    theUserErrorHandler = false;
  }
}


StaticContextImpl::StaticContextImpl(const StaticContextImpl& aStaticContext)
  :
  StaticContext(),
  theCtx(0), 
  theUserStaticContext(false), // we are responsible to delete it
  theErrorHandler(aStaticContext.theErrorHandler),
  theUserErrorHandler(aStaticContext.theUserErrorHandler)
{
  // hierarchy of contexts
  theCtx = aStaticContext.theCtx->create_child_context();
  RCHelper::addReference (theCtx);

  // bugfix
  // if it's a default error handler, we need to create a new
  // one since every context has it's own non-user error handler
  // which he also needs to delete
  if ( ! theUserErrorHandler ) {
    theErrorHandler = new DefaultErrorHandler();
  }

  for (std::map<ModuleURIResolver*, ModuleURIResolverWrapper*>::const_iterator
         lIter = aStaticContext.theModuleWrappers.begin();
       lIter != aStaticContext. theModuleWrappers.end(); ++lIter) 
  {
    addModuleURIResolver(lIter->first);
  }
  for (std::map<SchemaURIResolver*, SchemaURIResolverWrapper*>::const_iterator
        lIter = aStaticContext.theSchemaWrappers.begin();
        lIter != aStaticContext. theSchemaWrappers.end(); ++lIter) {
    addSchemaURIResolver(lIter->first);
  }
}


StaticContextImpl::~StaticContextImpl()
{
  for (std::map<ModuleURIResolver*, ModuleURIResolverWrapper*>::iterator
        lIter = theModuleWrappers.begin();
        lIter != theModuleWrappers.end(); ++lIter) {
      theCtx->remove_module_uri_resolver(lIter->second);
      delete lIter->second;
  }
  theModuleWrappers.clear();
  for (std::map<SchemaURIResolver*, SchemaURIResolverWrapper*>::iterator
        lIter = theSchemaWrappers.begin();
        lIter != theSchemaWrappers.end(); ++lIter) {
      theCtx->remove_schema_uri_resolver(lIter->second);
      delete lIter->second;
  }
  theSchemaWrappers.clear();

  if ( ! theUserStaticContext )
    RCHelper::removeReference (theCtx);

  if ( ! theUserErrorHandler )
    delete theErrorHandler;
}


StaticContext_t
StaticContextImpl::createChildContext() const
{
  try {
    StaticContext_t lContext(new StaticContextImpl(*this));
    return lContext;
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  } catch (std::exception& e) {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return StaticContext_t();
}

  
bool   
StaticContextImpl::addNamespace( const String& aPrefix, const String& aURI )
{
  ZORBA_TRY
    xqpStringStore_t lPrefix = Unmarshaller::getInternalString(aPrefix);
    xqpStringStore_t lURI = Unmarshaller::getInternalString(aURI);
    QueryLoc loc;
    theCtx->bind_ns(lPrefix, lURI, loc);
    return true;
  ZORBA_CATCH
  return false;
}

  
String   
StaticContextImpl::getNamespaceURIByPrefix( const String& aPrefix ) const
{
  try 
  {
    xqpStringStore_t lPrefix = Unmarshaller::getInternalString(aPrefix);
    QueryLoc loc;
    xqpStringStore_t ns;
    theCtx->lookup_ns(ns, lPrefix, loc);
    return ns.getp();
  }
  catch (error::ZorbaError& e)
  {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
  catch (std::exception& e) 
  {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return "";
}


bool   
StaticContextImpl::setDefaultElementAndTypeNamespace( const String& aURI )
{
  ZORBA_TRY
    xqpStringStore_t lURI = Unmarshaller::getInternalString(aURI);
    QueryLoc loc;
    theCtx->set_default_elem_type_ns(lURI, loc);
    return true;
  ZORBA_CATCH
  return false;
}

  
String   
StaticContextImpl::getDefaultElementAndTypeNamespace( ) const
{
  try 
  {
    return theCtx->default_elem_type_ns().getp();
  }
  catch (error::ZorbaError& e)
  {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
  catch (std::exception& e)
  {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return "";
}


bool   
StaticContextImpl::setDefaultFunctionNamespace( const String& aURI )
{
  ZORBA_TRY
    xqpStringStore_t lURI = Unmarshaller::getInternalString(aURI);
    QueryLoc loc;
    theCtx->set_default_function_ns(lURI, loc);
    return true;
  ZORBA_CATCH
  return false;
}

  
String   
StaticContextImpl::getDefaultFunctionNamespace( ) const
{
  try 
  {
    return theCtx->default_function_ns().getp();
  }
  catch (error::ZorbaError& e) 
  {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
  catch (std::exception& e) 
  {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return "";
}


void
StaticContextImpl::addCollation( const String& URI )
{
  ZORBA_TRY
    xqpStringStore* lURI = Unmarshaller::getInternalString(URI);
    theCtx->add_collation(lURI->str(), QueryLoc::null);
  ZORBA_CATCH
}


void   
StaticContextImpl::setDefaultCollation( const String& URI )
{
  ZORBA_TRY
    xqpStringStore* lURI = Unmarshaller::getInternalString(URI);
    theCtx->set_default_collation(lURI->str(), QueryLoc::null); 
  ZORBA_CATCH
}


String 
StaticContextImpl::getDefaultCollation() const
{
  try 
  {
    return theCtx->get_default_collation(QueryLoc::null);
  }
  catch (error::ZorbaError& e)
  {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
  catch (std::exception& e)
  {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return "";
}


bool   
StaticContextImpl::setXQueryVersion(xquery_version_t version)
{
  ZORBA_TRY
    if ( version == xquery_version_1_0)
      theCtx->set_xquery_version(StaticContextConsts::xquery_version_1_0);
    else
      theCtx->set_xquery_version(StaticContextConsts::xquery_version_1_1);
    return true;
  ZORBA_CATCH
  return false;
}


xquery_version_t  
StaticContextImpl::getXQueryVersion() const
{
  try {
    return theCtx->xquery_version()==StaticContextConsts::xquery_version_1_0?
      xquery_version_1_0:xquery_version_1_1;
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  } catch (std::exception& e) {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return xquery_version_1_0;
}


bool   
StaticContextImpl::setXPath1_0CompatibMode( xpath1_0compatib_mode_t mode )
{
  ZORBA_TRY
    if ( mode == xpath1_0)
      theCtx->set_xpath_compatibility(StaticContextConsts::xpath1_0_only);
    else
      theCtx->set_xpath_compatibility(StaticContextConsts::xpath2_0);
    return true;
  ZORBA_CATCH
  return false;
}


xpath1_0compatib_mode_t  
StaticContextImpl::getXPath1_0CompatibMode( ) const
{
  try 
  {
    return (theCtx->xpath_compatibility() == StaticContextConsts::xpath1_0_only?
            xpath1_0 :
            xpath2_0);
  }
  catch (error::ZorbaError& e) 
  {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
  catch (std::exception& e) 
  {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return xpath2_0;
}


bool   
StaticContextImpl::setConstructionMode( construction_mode_t mode )
{
  ZORBA_TRY
      if ( mode == preserve_cons)
        theCtx->set_construction_mode(StaticContextConsts::cons_preserve);
      else
        theCtx->set_construction_mode(StaticContextConsts::cons_strip);
      return true;
  ZORBA_CATCH
  return false;
}


construction_mode_t  
StaticContextImpl::getConstructionMode( ) const
{
  try {
    return theCtx->construction_mode()==StaticContextConsts::cons_preserve?
      preserve_cons:strip_cons;
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  } catch (std::exception& e) {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return preserve_cons;
}


bool   
StaticContextImpl::setOrderingMode( ordering_mode_t mode )
{
  ZORBA_TRY
    if ( mode == ordered)
      theCtx->set_ordering_mode(StaticContextConsts::ordered);
    else
      theCtx->set_ordering_mode(StaticContextConsts::unordered);
    return true;
  ZORBA_CATCH
  return false;
}


ordering_mode_t  
StaticContextImpl::getOrderingMode( ) const
{
  try {
    return theCtx->ordering_mode()==StaticContextConsts::ordered?ordered:unordered;
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  } catch (std::exception& e) {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return ordered;
}


bool   
StaticContextImpl::setDefaultOrderForEmptySequences(order_empty_mode_t mode )
{
  ZORBA_TRY
    if ( mode == empty_greatest)
      theCtx->set_empty_order_mode(StaticContextConsts::empty_greatest);
    else
      theCtx->set_empty_order_mode(StaticContextConsts::empty_least);
      return true;
  ZORBA_CATCH
  return false;
}


order_empty_mode_t   
StaticContextImpl::getDefaultOrderForEmptySequences( ) const
{
  try {
    return theCtx->empty_order_mode()==StaticContextConsts::empty_greatest?
      empty_greatest:empty_least;
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  } catch (std::exception& e) {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return empty_greatest;
}


bool   
StaticContextImpl::setBoundarySpacePolicy( boundary_space_mode_t mode )
{
  ZORBA_TRY
    if ( mode == preserve_space)
      theCtx->set_boundary_space_mode(StaticContextConsts::preserve_space);
    else
      theCtx->set_boundary_space_mode(StaticContextConsts::strip_space);
    return true;
  ZORBA_CATCH
  return false;
}


boundary_space_mode_t  
StaticContextImpl::getBoundarySpacePolicy( ) const
{
  try {
    return theCtx->boundary_space_mode()==StaticContextConsts::preserve_space?
      preserve_space:strip_space;
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  } catch (std::exception& e) {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return preserve_space;
}
  

bool   
StaticContextImpl::setCopyNamespacesMode( preserve_mode_t preserve, 
                                          inherit_mode_t inherit )
{
  ZORBA_TRY
    if ( preserve == preserve_ns )
      theCtx->set_preserve_mode(StaticContextConsts::preserve_ns);
    else
      theCtx->set_preserve_mode(StaticContextConsts::no_preserve_ns);

    if ( inherit == inherit_ns )
      theCtx->set_inherit_mode(StaticContextConsts::inherit_ns);
    else
      theCtx->set_inherit_mode(StaticContextConsts::no_inherit_ns);
    return true;
  ZORBA_CATCH
  return false;
}


void   
StaticContextImpl::getCopyNamespacesMode( preserve_mode_t& preserve, 
                                          inherit_mode_t& inherit ) const
{
  ZORBA_TRY
    preserve = theCtx->preserve_mode()==StaticContextConsts::preserve_ns?
                    preserve_ns:no_preserve_ns;
    inherit = theCtx->inherit_mode()==StaticContextConsts::inherit_ns?
                    inherit_ns:no_inherit_ns;
  ZORBA_CATCH
}


bool   
StaticContextImpl::setBaseURI( const String& aBaseURI )
{
  try 
  {
    xqpStringStore_t lBaseURI = Unmarshaller::getInternalString(aBaseURI);
    xqpStringStore_t lBaseURI2 = lBaseURI;
    
    if(!GenericCast::instance()->isCastable(lBaseURI,
                                            &*GENV_TYPESYSTEM.ANY_URI_TYPE_ONE)) 
    {
      ZORBA_ERROR_DESC(XQP0020_INVALID_URI, lBaseURI);
    }
    theCtx->set_base_uri(lBaseURI2, false);
  }
  catch (error::ZorbaError& e) 
  {
    ZorbaImpl::notifyError(theErrorHandler, e);
    return false;
  }
  catch (std::exception& e) 
  {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
    return false;
  }
  return true;
}


/*******************************************************************************

********************************************************************************/
String   
StaticContextImpl::getBaseURI( ) const
{
  try 
  {
    xqpStringStore_t lBaseURI = theCtx->get_base_uri();
    return lBaseURI.getp();
  }
  catch (error::ZorbaError& e)
  {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
  catch (std::exception& e)
  {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return "";
}


/*******************************************************************************

********************************************************************************/
validation_mode_t
StaticContextImpl::getRevalidationMode() const
{
  return validate_lax;
}


/*******************************************************************************

********************************************************************************/
void
StaticContextImpl::setRevalidationMode(validation_mode_t aMode)
{
  ZORBA_TRY
    if (aMode == validate_skip)
      theCtx->set_validation_mode(StaticContextConsts::skip_validation);
    else if (aMode == validate_lax)
      theCtx->set_validation_mode(StaticContextConsts::lax_validation);
    else
      theCtx->set_validation_mode(StaticContextConsts::strict_validation);
  ZORBA_CATCH
}


/*******************************************************************************

********************************************************************************/
bool 
StaticContextImpl::registerModule(ExternalModule* aModule)
{
  try 
  {
    theCtx->bind_external_module(aModule);
  }
  catch (error::ZorbaError& e)
  {
    ZorbaImpl::notifyError(theErrorHandler, e);
    return false;
  }
  return true;
}


/*******************************************************************************

********************************************************************************/
void
StaticContextImpl::setDocumentURIResolver(DocumentURIResolver* aDocumentURIResolver)
{
  try 
  {
    theCtx->set_document_uri_resolver(new DocumentURIResolverWrapper(aDocumentURIResolver));
  } 
  catch (error::ZorbaError& e) 
  {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
}


/*******************************************************************************

********************************************************************************/
DocumentURIResolver*
StaticContextImpl::getDocumentURIResolver() const
{
  DocumentURIResolverWrapper* lWrapper = dynamic_cast<DocumentURIResolverWrapper*>(theCtx->get_document_uri_resolver());
  if (lWrapper) { // if it's the user's resolver
    return lWrapper->theDocResolver;
  }
  return 0;
}


/*******************************************************************************

********************************************************************************/
void
StaticContextImpl::setDocumentType(const String& aDocUri, TypeIdentifier_t type)
{
  xqtref_t xqType = NULL;
  if (type != NULL) {
    xqType = theCtx->get_typemanager()->create_type(*type);
  }

  xqpStringStore_t uri = Unmarshaller::getInternalString(aDocUri);
  theCtx->bind_document(uri, xqType);
}


/*******************************************************************************

********************************************************************************/
TypeIdentifier_t
StaticContextImpl::getDocumentType(const String& aDocUri) const
{
  xqtref_t xqType = theCtx->lookup_document(Unmarshaller::getInternalString(aDocUri));
  TypeIdentifier_t type = NULL;
  if (xqType == NULL) {
    return NULL;
  }
  return TypeOps::get_type_identifier(*xqType);
}


/*******************************************************************************

********************************************************************************/
void
StaticContextImpl::setCollectionURIResolver(CollectionURIResolver* aCollectionUriResolver)
{
  try {
    theCtx->set_collection_uri_resolver(new CollectionURIResolverWrapper(aCollectionUriResolver));
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
}


/*******************************************************************************

********************************************************************************/
CollectionURIResolver*
StaticContextImpl::getCollectionURIResolver() const
{
  CollectionURIResolverWrapper* lWrapper = dynamic_cast<CollectionURIResolverWrapper*>(theCtx->get_collection_uri_resolver());
  if (lWrapper) { // if it's the user's resolver
    return lWrapper->theColResolver;
  }
  return 0;
}


/*******************************************************************************

********************************************************************************/
void
StaticContextImpl::setCollectionType(const String& aCollectionUri, TypeIdentifier_t type)
{
  xqtref_t xqType = NULL;
  if (type != NULL) 
  {
    xqType = theCtx->get_typemanager()->create_type(*type);
  }
  xqpStringStore_t uri = Unmarshaller::getInternalString(aCollectionUri);
  theCtx->bind_w3c_collection(uri, xqType);
}


/*******************************************************************************

********************************************************************************/
TypeIdentifier_t
StaticContextImpl::getCollectionType(const String& aCollectionUri) const
{
  const XQType* xqType = theCtx->lookup_w3c_collection(Unmarshaller::getInternalString(aCollectionUri));
  TypeIdentifier_t type = NULL;
  if (xqType == NULL) 
  {
    return NULL;
  }
  return TypeOps::get_type_identifier(*xqType);
}


/*******************************************************************************

********************************************************************************/
void
StaticContextImpl::addModuleURIResolver(ModuleURIResolver* aModuleUriResolver)
{
  try 
  {
    // do nothing if the resolver is already registered
    if (theModuleWrappers[aModuleUriResolver]) 
    {
      return;
    }

    ModuleURIResolverWrapper* lWrapper =
    new ModuleURIResolverWrapper(aModuleUriResolver);

    // put the wrapper in the map (ownership of the wrapper belongs to "this")
    theModuleWrappers[aModuleUriResolver] = lWrapper;

    // register the wrapper in the internal context
    theCtx->add_module_uri_resolver(lWrapper);
  }
  catch (error::ZorbaError& e)
  {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
}


/*******************************************************************************

********************************************************************************/
std::vector<ModuleURIResolver*>
StaticContextImpl::getModuleURIResolvers() const
{
  std::vector<ModuleURIResolver*> lResolvers;
  try 
  {
    // get all resovlers (from the internal context upwards to its parent)
    std::vector<InternalModuleURIResolver*> lResolverWrappers;
    theCtx->get_module_uri_resolvers(lResolverWrappers);

    // create a vector containing the pointers to all resolvers
    // owned by the user
    for (std::vector<InternalModuleURIResolver*>::iterator lIter 
          = lResolverWrappers.begin();
         lIter != lResolverWrappers.end(); ++lIter) 
    {
      ModuleURIResolverWrapper* lWrapper 
        = dynamic_cast<ModuleURIResolverWrapper*>(*lIter);
      assert(lWrapper);
      lResolvers.push_back(lWrapper->theModuleResolver);
    }
  }
  catch (error::ZorbaError& e) 
  {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
  return lResolvers;
}


/*******************************************************************************

********************************************************************************/
void
StaticContextImpl::removeModuleURIResolver(ModuleURIResolver* aModuleUriResolver)
{
  try {
    // look for a resolver, if found
    // (1) remove it from the internal context
    // (2) delete the wrapper
    // (3) remove the entry from the map
    for (std::map<ModuleURIResolver*, ModuleURIResolverWrapper*>::iterator
          lIter = theModuleWrappers.begin();
          lIter != theModuleWrappers.end(); ++lIter) {
      if (lIter->first == aModuleUriResolver) { // pointer equality
        theCtx->remove_module_uri_resolver(lIter->second);
        delete lIter->second;
        theModuleWrappers.erase(lIter);
        return;
      }
    }
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
}


/*******************************************************************************

********************************************************************************/
std::vector<SchemaURIResolver*>
StaticContextImpl::getSchemaURIResolvers() const
{
  std::vector<SchemaURIResolver*> lResult;
  std::vector<InternalSchemaURIResolver*> lResolvers;
  try {
    theCtx->get_schema_uri_resolvers(lResolvers);
    std::vector<InternalSchemaURIResolver*>::iterator lIter;
    for (lResolvers.begin(); lIter != lResolvers.end(); ++lIter) {
      SchemaURIResolverWrapper* lWrapper =
        dynamic_cast<SchemaURIResolverWrapper*>(*lIter);
      if (lWrapper) { // if it's the user's resolver
        lResult.push_back(lWrapper->theSchemaResolver);
      }
    }
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
  return lResult;
}


/*******************************************************************************

********************************************************************************/
void
StaticContextImpl::addSchemaURIResolver(SchemaURIResolver* aSchemaUriResolver)
{
  try {
    // do nothing if the resolver is already registered
    if (theSchemaWrappers[aSchemaUriResolver]) 
    {
      return;
    }

    SchemaURIResolverWrapper* lWrapper =
      new SchemaURIResolverWrapper(aSchemaUriResolver);

    // put the wrapper in the map (ownership of the wrapper belongs to "this")
    theSchemaWrappers[aSchemaUriResolver] = lWrapper;

    // register the wrapper in the internal context
    theCtx->add_schema_uri_resolver(lWrapper);
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
}


/*******************************************************************************

********************************************************************************/
void
StaticContextImpl::removeSchemaURIResolver(SchemaURIResolver* aSchemaUriResolver)
{
  try {
    // look for a resolver, if found
    // (1) remove it from the internal context
    // (2) delete the wrapper
    // (3) remove the entry from the map
    for (std::map<SchemaURIResolver*, SchemaURIResolverWrapper*>::iterator
          lIter = theSchemaWrappers.begin();
          lIter != theSchemaWrappers.end(); ++lIter) {
      if (lIter->first == aSchemaUriResolver) { // pointer equality
        theCtx->remove_schema_uri_resolver(lIter->second);
        delete lIter->second;
        theSchemaWrappers.erase(lIter);
        return;
      }
    }
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
}


/*******************************************************************************

********************************************************************************/
bool
StaticContextImpl::containsFunction(
    const String& aFnNameUri,
    const String& aFnNameLocal, 
    int arity) const
{
  xqpStringStore_t prefix = new xqpStringStore("");

  store::Item_t qnameItem;
  GENV_ITEMFACTORY->createQName(qnameItem,
                                Unmarshaller::getInternalString(aFnNameUri),
                                prefix,
                                Unmarshaller::getInternalString(aFnNameLocal));

  const function* fn = theCtx->lookup_fn(qnameItem, arity);

  return fn != NULL;
}


/*******************************************************************************

********************************************************************************/
void
StaticContextImpl::findFunctions(const Item& aQName, std::vector<Function_t>& aFunctions) const
{
  try {
    store::Item* lQName = Unmarshaller::getInternalItem(aQName);

    std::vector<function*> lInternalFunctions;

    theCtx->find_functions(lQName, lInternalFunctions);

    for (std::vector<function*>::const_iterator lIter = lInternalFunctions.begin();
         lIter != lInternalFunctions.end(); ++lIter) 
    {
      Function_t lFunc(new FunctionImpl(*lIter, theErrorHandler));
      aFunctions.push_back(lFunc);
    }

    assert ( aFunctions.size() == lInternalFunctions.size() );
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
}


void
StaticContextImpl::disableFunction(const Function_t& aFunction)
{
  disableFunction(aFunction->getFunctionName(), aFunction->getArity());
}


void
StaticContextImpl::disableFunction(const Item& aQName, int arity)
{
  theCtx->unbind_fn(Unmarshaller::getInternalItem(aQName), arity);
}


void
StaticContextImpl::setContextItemStaticType(TypeIdentifier_t type)
{
  xqtref_t xqType = NULL;
  if (type != NULL) {
    xqType = theCtx->get_typemanager()->create_type(*type);
  }
  theCtx->set_context_item_type(xqType);
}


TypeIdentifier_t
StaticContextImpl::getContextItemStaticType() const
{
  xqtref_t type = theCtx->get_context_item_type();
  if (type == NULL) {
    return NULL;
  }
  return TypeOps::get_type_identifier(*type);
}


void
StaticContextImpl::setTraceStream(std::ostream& os)
{
  theCtx->set_trace_stream(os);
}


void
StaticContextImpl::resetTraceStream()
{
  theCtx->set_trace_stream(std::cerr);
}


bool
StaticContextImpl::getOption(const Item& aQName, String& aOptionValue) const
{
  try 
  {
    const store::Item* lQName = Unmarshaller::getInternalItem(aQName);
    xqpStringStore_t lOption;
    if (theCtx->lookup_option(lQName, lOption)) 
    {
      aOptionValue = String(lOption);
      return true;
    } 
    else
    {
      return false;
    }
  }
  catch (error::ZorbaError& e)
  {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
  return false;
}


void
StaticContextImpl::declareOption(const Item& aQName, const String& aOptionValue)
{
  try 
  {
    const store::Item* lQName = Unmarshaller::getInternalItem(aQName);
    xqpStringStore_t lOptionValue = Unmarshaller::getInternalString(aOptionValue);
    
    theCtx->bind_option(lQName, lOptionValue);
  }
  catch (error::ZorbaError& e) 
  {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
}


void
StaticContextImpl::loadProlog(const String& prolog, const Zorba_CompilerHints_t& hints)
{
  // Create and compile an internal query whose prolog is the given prolog and
  // its body is just the emtpy sequence expression: "()".
  XQueryImpl impl;
  impl.loadProlog(prolog, this, hints);

  // Copy theSctxMap of the internal query into "this". When "this" is then passed
  // as an input to a user query Q, theSctxMap of Q will be initialized as a copy
  // of this->theSctxMap. 
  theSctxMap = impl.theSctxMap;
}

void
StaticContextImpl::setModulePaths( const std::vector<String>& aModulePaths )
{
  try {
    std::vector<std::string> lModulePaths;

    for (std::vector<String>::const_iterator lIter = aModulePaths.begin();
         lIter != aModulePaths.end(); ++lIter) {
      if (lIter->length()!=0) {
        lModulePaths.push_back(Unmarshaller::getInternalString(*lIter)->c_str());
        std::string& lPath = lModulePaths.back();
        if (lPath.rfind(filesystem_path::get_path_separator()) != std::string::npos) {
          lPath.append(filesystem_path::get_path_separator());
        }
      }

    }
    
    theCtx->set_module_paths(lModulePaths);
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
}

void
StaticContextImpl::getModulePaths( std::vector<String>& aModulePaths ) const
{
  try {
    std::vector<std::string> lModulePaths;

    theCtx->get_module_paths(lModulePaths);

    for (std::vector<std::string>::const_iterator lIter = lModulePaths.begin();
         lIter != lModulePaths.end(); ++lIter) {
      aModulePaths.push_back(lIter->c_str());
    }
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
}

void
StaticContextImpl::getFullModulePaths( std::vector<String>& aFullModulePaths ) const
{
  try {
    std::vector<std::string> lFullModulePaths;

    theCtx->get_full_module_paths(lFullModulePaths);

    for (std::vector<std::string>::const_iterator lIter = lFullModulePaths.begin();
         lIter != lFullModulePaths.end(); ++lIter) {
      aFullModulePaths.push_back(lIter->c_str());
    }
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
}


String
StaticContextImpl::resolve(const String& aBaseUri, const String& aRelativeURI) const 
{
  xqpStringStore_t lBaseUri = Unmarshaller::getInternalString(aBaseUri);
  xqpStringStore_t lRelativeUri = Unmarshaller::getInternalString(aRelativeURI);

  xqpStringStore_t lResolved = theCtx->resolve_relative_uri(lRelativeUri, lBaseUri);

  return lResolved.getp();
}

void
StaticContextImpl::setDeclaredCollectionCallback (
    CollectionCallback aCallbackFunction,
    void* aCallbackData )
{
  theCtx->set_collection_callback(aCallbackFunction, aCallbackData);
}

void
StaticContextImpl::setDeclaredIndexCallback (
    IndexCallback aCallbackFunction,
    void* aCallbackData )
{
  theCtx->set_index_callback(aCallbackFunction, aCallbackData);
}

} /* namespace zorba */
