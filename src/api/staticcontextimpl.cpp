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
#include <zorba/stateless_function.h>
#include <zorba/default_error_handler.h>

#include "zorbatypes/xqpstring.h"
#include "api/unmarshaller.h"
#include "context/static_context.h"
#include "context/static_context_consts.h"
#include "context/uri_resolver_wrapper.h"
#include "system/globalenv.h"
#include <zorba/typeident.h>
#include "zorbaerrors/error_manager.h"
#include "api/zorbaimpl.h"
#include "types/casting.h"

namespace zorba {


/*******************************************************************************
  Create a StaticContextImpl obj as well as an internal static_context obj S.
  S is created as a child of the zorba root sctx. The new StaticContextImpl obj
  owns S, and should delete it during destruction. This constructor is used
  when the application wants to create a new static context.
********************************************************************************/
StaticContextImpl::StaticContextImpl(ErrorHandler* aErrorHandler)
  :
  theCtx(0),
  theUserStaticContext(false),
  theErrorHandler(aErrorHandler),
  theUserErrorHandler(true)
{
  theCtx = GENV.getRootStaticContext().create_child_context();
  if ( ! theErrorHandler ) {
    theErrorHandler = new DefaultErrorHandler();
    theUserErrorHandler = false;
  }
}


/*******************************************************************************
  Create a StaticContextImpl obj to wrap a given internal static_context obj S.
  The new StaticContextImpl obj does not own S, and should not delete it during
  destruction. This constructor is used when the static context of a query is
  returned to the application.
********************************************************************************/
StaticContextImpl::StaticContextImpl(static_context* aCtx, ErrorHandler* aErrorHandler)
  :
  theCtx(aCtx),
  theUserStaticContext(true),
  theErrorHandler(aErrorHandler),
  theUserErrorHandler(true)
{
  if ( ! theErrorHandler ) {
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
}


StaticContextImpl::~StaticContextImpl()
{
  if ( ! theUserStaticContext )
    delete theCtx;

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
      xqpString lPrefix = Unmarshaller::getInternalString(aPrefix);
      xqpString lURI = Unmarshaller::getInternalString(aURI);
      theCtx->bind_ns(lPrefix, lURI);
      return true;
  ZORBA_CATCH
  return false;
}

  
String   
StaticContextImpl::getNamespaceURIByPrefix( const String& aPrefix ) const
{
  try {
    xqpString lPrefix = Unmarshaller::getInternalString(aPrefix);
    return &*theCtx->lookup_ns(lPrefix).theStrStore;
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  } catch (std::exception& e) {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return "";
}


bool   
StaticContextImpl::setDefaultElementAndTypeNamespace( const String& aURI )
{
  ZORBA_TRY
      xqpString lURI = Unmarshaller::getInternalString(aURI);
      theCtx->set_default_elem_type_ns(lURI);
      return true;
  ZORBA_CATCH
  return false;
}

  
String   
StaticContextImpl::getDefaultElementAndTypeNamespace( ) const
{
  try {
    return &*theCtx->default_elem_type_ns().theStrStore;
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
    } catch (std::exception& e) {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return "";
}


bool   
StaticContextImpl::setDefaultFunctionNamespace( const String& aURI )
{
  ZORBA_TRY
      xqpString lURI = Unmarshaller::getInternalString(aURI);
      theCtx->set_default_function_namespace(lURI);
      return true;
  ZORBA_CATCH
  return false;
}

  
String   
StaticContextImpl::getDefaultFunctionNamespace( ) const
{
  try {
    return &*theCtx->default_function_namespace().theStrStore;
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  } catch (std::exception& e) {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return "";
}


bool   
StaticContextImpl::addCollation( const String& URI )
{
  ZORBA_TRY
      xqpString lURI = xqpString(Unmarshaller::getInternalString(URI));
      theCtx->add_collation(lURI);
      return true;
  ZORBA_CATCH
  return false;
}


bool   
StaticContextImpl::setDefaultCollation( const String& URI )
{
  ZORBA_TRY
      xqpString lURI = xqpString(Unmarshaller::getInternalString(URI));
      theCtx->set_default_collation_uri(lURI); 
      return true;
  ZORBA_CATCH
  return false;
}


String 
StaticContextImpl::getDefaultCollation() const
{
  try {
    return &*theCtx->default_collation_uri().theStrStore;
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  } catch (std::exception& e) {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return "";
}


bool   
StaticContextImpl::setXPath1_0CompatibMode( xpath1_0compatib_mode_t mode )
{
  ZORBA_TRY
      if ( mode == xpath1_0)
        theCtx->set_xpath1_0compatib_mode(StaticContextConsts::xpath1_0_only);
      else
        theCtx->set_xpath1_0compatib_mode(StaticContextConsts::xpath2_0);
      return true;
  ZORBA_CATCH
  return false;
}


xpath1_0compatib_mode_t  
StaticContextImpl::getXPath1_0CompatibMode( ) const
{
  try {
    return theCtx->xpath1_0compatib_mode()==StaticContextConsts::xpath1_0_only?
      xpath1_0:xpath2_0;
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  } catch (std::exception& e) {
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
    return theCtx->ordering_mode()==StaticContextConsts::ordered?
      ordered:unordered;
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  } catch (std::exception& e) {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return ordered;
}


bool   
StaticContextImpl::setDefaultOrderForEmptySequences( order_empty_mode_t mode )
{
  ZORBA_TRY
      if ( mode == empty_greatest)
        theCtx->set_order_empty_mode(StaticContextConsts::empty_greatest);
      else
        theCtx->set_order_empty_mode(StaticContextConsts::empty_least);
        return true;
  ZORBA_CATCH
  return false;
}


order_empty_mode_t   
StaticContextImpl::getDefaultOrderForEmptySequences( ) const
{
  try {
    return theCtx->order_empty_mode()==StaticContextConsts::empty_greatest?
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
  try {
    xqpStringStore_t lBaseURI = Unmarshaller::getInternalString(aBaseURI);
    xqpStringStore_t lBaseURI2 = lBaseURI;
    
    if(!GenericCast::instance()->isCastable(lBaseURI, &*GENV_TYPESYSTEM.ANY_URI_TYPE_ONE)) {
      ZORBA_ERROR_DESC(XQP0020_INVALID_URI, lBaseURI);
    }
    theCtx->set_baseuri(lBaseURI2.getp(), false);
  }
  catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
    return false;
  }
  catch (std::exception& e) {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
    return false;
  }
  return true;
}


String   
StaticContextImpl::getBaseURI( ) const
{
  try {
    xqpString lBaseURI = theCtx->baseuri();
    return &*lBaseURI.theStrStore;
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  } catch (std::exception& e) {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }
  return "";
}


bool 
StaticContextImpl::registerStatelessExternalFunction(StatelessExternalFunction* aExternalFunction)
{
  try {
    if ( ! theCtx->bind_stateless_external_function(aExternalFunction) ) {
      xqpString lLocalName = Unmarshaller::getInternalString(aExternalFunction->getLocalName());
      xqpString lMsg = lLocalName +" is already registered";

      ZORBA_ERROR_DESC(API0019_FUNCTION_ALREADY_REGISTERED, String(lMsg.theStrStore));
    }
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
    return false;
  }
  return true;
}


void
StaticContextImpl::setDocumentURIResolver(DocumentURIResolver* aDocumentURIResolver)
{
  try {
    theCtx->set_document_uri_resolver(new DocumentURIResolverWrapper(aDocumentURIResolver));
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
}

DocumentURIResolver*
StaticContextImpl::getDocumentURIResolver()
{
  DocumentURIResolverWrapper* lWrapper = dynamic_cast<DocumentURIResolverWrapper*>(theCtx->get_document_uri_resolver());
  if (lWrapper) { // if it's the user's resolver
    return lWrapper->theDocResolver;
  }
  return 0;
}


void
StaticContextImpl::setCollectionURIResolver(CollectionURIResolver* aCollectionUriResolver)
{
  try {
    theCtx->set_collection_uri_resolver(new CollectionURIResolverWrapper(aCollectionUriResolver));
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
}

CollectionURIResolver*
StaticContextImpl::getCollectionURIResolver()
{
  CollectionURIResolverWrapper* lWrapper = dynamic_cast<CollectionURIResolverWrapper*>(theCtx->get_collection_uri_resolver());
  if (lWrapper) { // if it's the user's resolver
    return lWrapper->theColResolver;
  }
  return 0;
}

void
StaticContextImpl::setModuleURIResolver(ModuleURIResolver* aModuleUriResolver)
{
  try {
    theCtx->set_module_uri_resolver(new ModuleURIResolverWrapper(aModuleUriResolver));
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
}

SchemaURIResolver*
StaticContextImpl::getSchemaURIResolver()
{
  SchemaURIResolverWrapper* lWrapper = dynamic_cast<SchemaURIResolverWrapper*>(theCtx->get_schema_uri_resolver());
  if (lWrapper) { // if it's the user's resolver
    return lWrapper->theSchemaResolver;
  }
  return 0;
}

void
StaticContextImpl::setSchemaURIResolver(SchemaURIResolver* aSchemaUriResolver)
{
  try {
    theCtx->set_schema_uri_resolver(new SchemaURIResolverWrapper(aSchemaUriResolver));
  } catch (error::ZorbaError& e) {
    ZorbaImpl::notifyError(theErrorHandler, e);
  }
}

ModuleURIResolver*
StaticContextImpl::getModuleURIResolver()
{
  ModuleURIResolverWrapper* lWrapper = dynamic_cast<ModuleURIResolverWrapper*>(theCtx->get_module_uri_resolver());
  if (lWrapper) { // if it's the user's resolver
    return lWrapper->theModuleResolver;
  }
  return 0;
}

bool
StaticContextImpl::containsFunction(const String& aFnNameUri, const String& aFnNameLocal, int arity) const
{
    const function *fn = theCtx->lookup_resolved_fn(Unmarshaller::getInternalString(aFnNameUri), Unmarshaller::getInternalString(aFnNameLocal), arity);
    if (fn == NULL) {
        return false;
    }
    return true;
}

} /* namespace zorba */
