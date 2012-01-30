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
#include "stdafx.h"

#include "common/common.h"
#include "api/staticcontextimpl.h"

#include <zorba/error.h>
#include <zorba/external_module.h>
#include <zorba/diagnostic_handler.h>
#include <zorba/static_context_consts.h>
#include <zorba/typeident.h>
#include <zorba/util/path.h>
#include <zorba/empty_sequence.h>

#include "store/api/item_factory.h"
#include "store/api/temp_seq.h"

#include "api/unmarshaller.h"
#include "api/zorbaimpl.h"
#include "api/functionimpl.h"
#include "api/annotationimpl.h"
#include "api/xqueryimpl.h"
#include "api/invoke_item_sequence.h"
#include "api/staticcollectionmanagerimpl.h"
#include "api/vectoriterator.h"

#include "context/static_context.h"
#include "context/static_context_consts.h"
#ifndef ZORBA_NO_FULL_TEXT
#include "context/stemmer_wrappers.h"
#include "context/thesaurus_wrappers.h"
#endif /* ZORBA_NO_FULL_TEXT */
#include "uri_resolver_wrappers.h"

#include "compiler/parser/query_loc.h"
#include "compiler/api/compilercb.h"
#include "compiler/expression/var_expr.h"

#include "functions/function.h"

#include "system/globalenv.h"

#include "types/casting.h"
#include "types/typeops.h"

#include "diagnostics/xquery_diagnostics.h"

#include "runtime/util/flowctl_exception.h"


namespace zorba {


/*******************************************************************************
  Create a StaticContextImpl obj as well as an internal static_context obj S.
  S is created as a child of the zorba root sctx. This constructor is used
  when the application wants to create its own static context to pass it as
  input to one or more queries.
********************************************************************************/
StaticContextImpl::StaticContextImpl(DiagnosticHandler* aDiagnosticHandler)
  :
  theDiagnosticHandler(aDiagnosticHandler),
  theUserDiagnosticHandler(true),
  theCollectionMgr(0)
{
  theCtx = GENV.getRootStaticContext().create_child_context();

  if ( ! theDiagnosticHandler )
  {
    theDiagnosticHandler = new DiagnosticHandler();
    theUserDiagnosticHandler = false;
  }
}


/*******************************************************************************
  Create a StaticContextImpl obj to wrap a given internal static_context obj S.
  This constructor is used when the static context of a query is returned to
  the application (see XQueryImpl::getStaticContext()).
********************************************************************************/
StaticContextImpl::StaticContextImpl(
    static_context* aCtx,
    DiagnosticHandler* aDiagnosticHandler)
  :
  theCtx(aCtx),
  theDiagnosticHandler(aDiagnosticHandler),
  theUserDiagnosticHandler(true),
  theCollectionMgr(0)
{
  if ( ! theDiagnosticHandler )
  {
    theDiagnosticHandler = new DiagnosticHandler();
    theUserDiagnosticHandler = false;
  }
}


/*******************************************************************************
  Create a StaticContextImpl obj as well as an internal static_context obj S.
  S is created as a child of the static_context obj associated with the given
  StaticContextImpl obj. This is a private constructor that is invoked by the
  StaticContextImpl::createChildContext() method.
********************************************************************************/
StaticContextImpl::StaticContextImpl(const StaticContextImpl& aStaticContext)
  :
  StaticContext(),
  theDiagnosticHandler(aStaticContext.theDiagnosticHandler),
  theUserDiagnosticHandler(aStaticContext.theUserDiagnosticHandler),
  theCollectionMgr(0)
{
  // hierarchy of contexts
  theCtx = aStaticContext.theCtx->create_child_context();

  // bugfix
  // if it's a default error handler, we need to create a new
  // one since every context has it's own non-user error handler
  // which he also needs to delete
  if ( ! theUserDiagnosticHandler )
  {
    theDiagnosticHandler = new DiagnosticHandler();
  }
}


/*******************************************************************************

********************************************************************************/
StaticContextImpl::~StaticContextImpl()
{
  if ( ! theUserDiagnosticHandler )
    delete theDiagnosticHandler;

  if ( theCollectionMgr )
  {
    delete theCollectionMgr;
  }
}


/*******************************************************************************

********************************************************************************/
StaticContext_t StaticContextImpl::createChildContext() const
{
  try
  {
    StaticContext_t lContext(new StaticContextImpl(*this));
    return lContext;
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
  catch (std::exception const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());
  }
  return StaticContext_t();
}


/*******************************************************************************

********************************************************************************/
bool
StaticContextImpl::addNamespace( const String& aPrefix, const String& aURI )
{
  ZORBA_TRY
    const zstring& lPrefix = Unmarshaller::getInternalString(aPrefix);
    const zstring& lURI = Unmarshaller::getInternalString(aURI);
    QueryLoc loc;
    theCtx->bind_ns(lPrefix, lURI, loc);
    return true;
  ZORBA_CATCH
  return false;
}


/*******************************************************************************

********************************************************************************/
String
StaticContextImpl::getNamespaceURIByPrefix(const String& aPrefix) const
{
  try
  {
    QueryLoc loc;
    const zstring& lPrefix = Unmarshaller::getInternalString(aPrefix);
    zstring ns;
    theCtx->lookup_ns(ns, lPrefix, loc);
    return Unmarshaller::newString( ns );
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
  catch (std::exception const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());
  }
  return "";
}


/*******************************************************************************

********************************************************************************/
bool
StaticContextImpl::setDefaultElementAndTypeNamespace(const String& aURI)
{
  ZORBA_TRY
    const zstring& lURI = Unmarshaller::getInternalString(aURI);
    theCtx->set_default_elem_type_ns(lURI, false, QueryLoc::null);
    return true;
  ZORBA_CATCH
  return false;
}


/*******************************************************************************

********************************************************************************/
String
StaticContextImpl::getDefaultElementAndTypeNamespace() const
{
  try
  {
    return theCtx->default_elem_type_ns().str();
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
  catch (std::exception const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());
  }
  return "";
}


/*******************************************************************************

********************************************************************************/
bool
StaticContextImpl::setDefaultFunctionNamespace(const String& aURI)
{
  ZORBA_TRY
    const zstring& lURI = Unmarshaller::getInternalString(aURI);
    QueryLoc loc;
    theCtx->set_default_function_ns(lURI, false, loc);
    return true;
  ZORBA_CATCH
  return false;
}


/*******************************************************************************

********************************************************************************/
String
StaticContextImpl::getDefaultFunctionNamespace( ) const
{
  try
  {
    return theCtx->default_function_ns().str();
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
  catch (std::exception const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());
  }
  return "";
}


/*******************************************************************************

********************************************************************************/
void
StaticContextImpl::addCollation( const String& URI )
{
  ZORBA_TRY
    const zstring& lURI = Unmarshaller::getInternalString(URI);
    theCtx->add_collation(lURI.str(), QueryLoc::null);
  ZORBA_CATCH
}


/*******************************************************************************

********************************************************************************/
void StaticContextImpl::setDefaultCollation( const String& URI )
{
  ZORBA_TRY
    const zstring& lURI = Unmarshaller::getInternalString(URI);
    theCtx->set_default_collation(lURI.str(), QueryLoc::null);
  ZORBA_CATCH
}


/*******************************************************************************

********************************************************************************/
String StaticContextImpl::getDefaultCollation() const
{
  try
  {
    return theCtx->get_default_collation(QueryLoc::null);
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
  catch (std::exception const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());
  }
  return "";
}


/*******************************************************************************

********************************************************************************/
bool StaticContextImpl::setXQueryVersion(xquery_version_t version)
{
  ZORBA_TRY
    if ( version == xquery_version_1_0)
      theCtx->set_xquery_version(StaticContextConsts::xquery_version_1_0);
    else
      theCtx->set_xquery_version(StaticContextConsts::xquery_version_3_0);
    return true;
  ZORBA_CATCH
  return false;
}


/*******************************************************************************

********************************************************************************/
xquery_version_t StaticContextImpl::getXQueryVersion() const
{
  try {
    return theCtx->xquery_version()==StaticContextConsts::xquery_version_1_0?
      xquery_version_1_0:xquery_version_3_0;
  } catch (ZorbaException const& e) {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  } catch (std::exception const& e) {
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());
  }
  return xquery_version_1_0;
}


/*******************************************************************************

********************************************************************************/
bool StaticContextImpl::setXPath1_0CompatibMode( xpath1_0compatib_mode_t mode )
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


/*******************************************************************************

********************************************************************************/
xpath1_0compatib_mode_t StaticContextImpl::getXPath1_0CompatibMode( ) const
{
  try
  {
    return (theCtx->xpath_compatibility() == StaticContextConsts::xpath1_0_only?
            xpath1_0 :
            xpath2_0);
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
  catch (std::exception const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());
  }
  return xpath2_0;
}


/*******************************************************************************

********************************************************************************/
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
  } catch (ZorbaException const& e) {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  } catch (std::exception const& e) {
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());
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
  } catch (ZorbaException const& e) {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  } catch (std::exception const& e) {
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());
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
  } catch (ZorbaException const& e) {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  } catch (std::exception const& e) {
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());
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
  } catch (ZorbaException const& e) {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  } catch (std::exception const& e) {
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());
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
    const zstring& baseURI = Unmarshaller::getInternalString(aBaseURI);
    zstring baseURI2 = baseURI;

    if(!GenericCast::instance()->isCastable(baseURI2,
                                            &*GENV_TYPESYSTEM.ANY_URI_TYPE_ONE,
                                            &GENV_TYPESYSTEM))
    {
      throw ZORBA_EXCEPTION(
        zerr::ZXQP0020_INVALID_URI, ERROR_PARAMS( baseURI )
      );
    }

    theCtx->set_base_uri(baseURI, false);
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
    return false;
  }
  catch (std::exception const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());
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
    zstring lBaseURI = theCtx->get_base_uri();
    return lBaseURI.str();
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
  catch (std::exception const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());
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
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
    return false;
  }
  return true;
}


/*******************************************************************************
 URI Mapper
*******************************************************************************/
void
StaticContextImpl::registerURIMapper(URIMapper* aMapper)
{
  // QQQ memory management?
  theCtx->add_uri_mapper(new URIMapperWrapper(*aMapper));
}

/*******************************************************************************
 URL Resolver
*******************************************************************************/
void
StaticContextImpl::registerURLResolver(URLResolver* aResolver)
{
  // QQQ memory management?
  theCtx->add_url_resolver(new URLResolverWrapper(*aResolver));
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

  const zstring& uri = Unmarshaller::getInternalString(aDocUri);
  theCtx->bind_document(uri, xqType);
}


/*******************************************************************************

********************************************************************************/
TypeIdentifier_t
StaticContextImpl::getDocumentType(const String& aDocUri) const
{
  const zstring& uri = Unmarshaller::getInternalString(aDocUri);
  xqtref_t xqType = theCtx->lookup_document(uri);
  TypeIdentifier_t type = NULL;
  if (xqType == NULL)
  {
    return NULL;
  }

  return TypeOps::get_type_identifier(theCtx->get_typemanager(), *xqType);
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
  zstring& uri = Unmarshaller::getInternalString(aCollectionUri);
  theCtx->bind_w3c_collection(uri, xqType);
}


/*******************************************************************************

********************************************************************************/
TypeIdentifier_t
StaticContextImpl::getCollectionType(const String& aCollectionUri) const
{

  const zstring& uri = Unmarshaller::getInternalString(aCollectionUri);
  const XQType* xqType = theCtx->lookup_w3c_collection(uri);
  TypeIdentifier_t type = NULL;
  if (xqType == NULL)
  {
    return NULL;
  }
  return TypeOps::get_type_identifier(theCtx->get_typemanager(), *xqType);
}

/*******************************************************************************

********************************************************************************/
bool StaticContextImpl::containsFunction(
    const String& aFnNameUri,
    const String& aFnNameLocal,
    int arity) const
{
  store::Item_t qnameItem;
  GENV_ITEMFACTORY->createQName(qnameItem,
                                Unmarshaller::getInternalString(aFnNameUri),
                                zstring(),
                                Unmarshaller::getInternalString(aFnNameLocal));

  const function* fn = theCtx->lookup_fn(qnameItem, arity);

  return fn != NULL;
}


/*******************************************************************************

********************************************************************************/
void StaticContextImpl::findFunctions(
    const Item& aQName,
    std::vector<Function_t>& aFunctions) const
{
  try
  {
    store::Item* lQName = Unmarshaller::getInternalItem(aQName);

    std::vector<function*> lInternalFunctions;

    theCtx->find_functions(lQName, lInternalFunctions);

    for (std::vector<function*>::const_iterator lIter = lInternalFunctions.begin();
         lIter != lInternalFunctions.end(); ++lIter)
    {
      Function_t lFunc(new FunctionImpl(*lIter, theDiagnosticHandler));
      aFunctions.push_back(lFunc);
    }

    assert ( aFunctions.size() == lInternalFunctions.size() );
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
}


void
StaticContextImpl::disableFunction(const Function_t& aFunction)
{
  disableFunction(aFunction->getQName(), aFunction->getArity());
}


void
StaticContextImpl::disableFunction(const Item& aQName, int arity)
{
  theCtx->unbind_fn(Unmarshaller::getInternalItem(aQName), arity);
}


void
StaticContextImpl::getFunctionAnnotations(
    const Item& aQName,
    int arity,
    std::vector<Annotation_t>& aAnnotations) const
{
  aAnnotations.clear();

  const function* f = theCtx->lookup_fn(Unmarshaller::getInternalItem(aQName), arity);
  if (f == NULL)
    return;

  const AnnotationList* ann_list = f->getAnnotationList();
  if (ann_list == NULL)
    return;

  try
  {
    for (unsigned int i = 0; i < ann_list->size(); i++)
      aAnnotations.push_back(new AnnotationImpl(ann_list->get(i)));
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
}


void
StaticContextImpl::setContextItemStaticType(TypeIdentifier_t type)
{
  xqtref_t xqType = NULL;
  if (type != NULL) 
  {
    xqType = theCtx->get_typemanager()->create_type(*type);
  }
  theCtx->set_context_item_type(xqType);
}


TypeIdentifier_t
StaticContextImpl::getContextItemStaticType() const
{
  xqtref_t type = theCtx->get_context_item_type();
  if (type == NULL)
  {
    return NULL;
  }
  return TypeOps::get_type_identifier(theCtx->get_typemanager(), *type);
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
    zstring lOption;
    if (theCtx->lookup_option(lQName, lOption))
    {
      aOptionValue = lOption.str();
      return true;
    }
    else
    {
      return false;
    }
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
  return false;
}


void
StaticContextImpl::declareOption(const Item& aQName, const String& aOptionValue)
{
  try
  {
    const store::Item* lQName = Unmarshaller::getInternalItem(aQName);
    const zstring& lOptionValue = Unmarshaller::getInternalString(aOptionValue);
    theCtx->bind_option(lQName, lOptionValue, QueryLoc::null);
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
}


void StaticContextImpl::loadProlog(
    const String& prolog,
    const Zorba_CompilerHints_t& hints)
{
  // Create and compile an internal query whose prolog is the given prolog and
  // its body is just the emtpy sequence expression: "()".
  XQueryImpl impl;
  impl.loadProlog(prolog, this, hints);

  // Copy theSctxMap of the internal query into "this". When "this" is then passed
  // as an input to a user query Q, theSctxMap of Q will be initialized as a copy
  // of this->theSctxMap.
  theSctxMap = impl.theCompilerCB->theSctxMap;
}

static void
toInternalPath(const std::vector<String>& aPublicStrings,
               std::vector<zstring>& aInternalStrings)
{
  for (std::vector<String>::const_iterator lIter = aPublicStrings.begin();
       lIter != aPublicStrings.end(); ++lIter)
  {
    if (lIter->length() != 0)
    {
      aInternalStrings.push_back(Unmarshaller::getInternalString(*lIter).c_str());
      zstring& lPath = aInternalStrings.back();
      if (lPath[lPath.length() - 1] != *filesystem_path::get_directory_separator())
      {
        lPath.append(filesystem_path::get_directory_separator());
      }
    }
  }
}

static void
toPublicPath(const std::vector<zstring>& aInternalStrings,
             std::vector<String>& aPublicStrings)
{
  for (std::vector<zstring>::const_iterator lIter = aInternalStrings.begin();
       lIter != aInternalStrings.end(); ++lIter)
  {
    aPublicStrings.push_back(lIter->c_str());
  }
}

void
StaticContextImpl::setURIPath(const std::vector<String> &aURIPath)
{
  try
  {
    std::vector<zstring> lInternalURIPath;
    toInternalPath(aURIPath, lInternalURIPath);
    theCtx->set_uri_path(lInternalURIPath);
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
}

void
StaticContextImpl::getURIPath(std::vector<String> &aURIPath) const
{
  try
  {
    std::vector<zstring> lInternalURIPath;
    theCtx->get_uri_path(lInternalURIPath);
    toPublicPath(lInternalURIPath, aURIPath);
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
}

void
StaticContextImpl::getFullURIPath(std::vector<String> &aURIPath) const
{
  try
  {
    std::vector<zstring> lInternalURIPath;
    theCtx->get_full_uri_path(lInternalURIPath);
    toPublicPath(lInternalURIPath, aURIPath);
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
}

void
StaticContextImpl::setLibPath(const std::vector<String> &aLibPath)
{
  try
  {
    std::vector<zstring> lInternalLibPath;
    toInternalPath(aLibPath, lInternalLibPath);
    theCtx->set_lib_path(lInternalLibPath);
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
}

void
StaticContextImpl::getLibPath(std::vector<String> &aLibPath) const
{
  try
  {
    std::vector<zstring> lInternalLibPath;
    theCtx->get_lib_path(lInternalLibPath);
    toPublicPath(lInternalLibPath, aLibPath);
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
}

void
StaticContextImpl::getFullLibPath(std::vector<String> &aLibPath) const
{
  try
  {
    std::vector<zstring> lInternalLibPath;
    theCtx->get_full_lib_path(lInternalLibPath);
    toPublicPath(lInternalLibPath, aLibPath);
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
}

void StaticContextImpl::setModulePaths(const std::vector<String>& aModulePaths)
{
  try
  {
    std::vector<zstring> lInternalModulePath;
    toInternalPath(aModulePaths, lInternalModulePath);
    theCtx->set_lib_path(lInternalModulePath);
    theCtx->set_uri_path(lInternalModulePath);
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
}

void StaticContextImpl::getModulePaths(std::vector<String>& aModulePaths) const
{
  try
  {
    std::vector<zstring> lInternalModulePath;
    theCtx->get_lib_path(lInternalModulePath);
    toPublicPath(lInternalModulePath, aModulePaths);
    lInternalModulePath.clear();
    theCtx->get_uri_path(lInternalModulePath);
    toPublicPath(lInternalModulePath, aModulePaths);
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
}


void
StaticContextImpl::getFullModulePaths( std::vector<String>& aFullModulePaths ) const
{
  try
  {
    std::vector<zstring> lInternalModulePath;
    theCtx->get_full_lib_path(lInternalModulePath);
    toPublicPath(lInternalModulePath, aFullModulePaths);
    lInternalModulePath.clear();
    theCtx->get_full_uri_path(lInternalModulePath);
    toPublicPath(lInternalModulePath, aFullModulePaths);
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
}

void
StaticContextImpl::setJVMClassPath(const std::vector<String> &aClassPath)
{
  try
  {
    std::vector<zstring> lInternalClassPath;
    toInternalPath(aClassPath, lInternalClassPath);
    theCtx->set_jvm_class_path(lInternalClassPath);
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
}

void
StaticContextImpl::getJVMClassPath(std::vector<String> &aClassPath) const
{
  try
  {
    std::vector<zstring> lInternalClassPath;
    theCtx->get_jvm_class_path(lInternalClassPath);
    toPublicPath(lInternalClassPath, aClassPath);
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
}


String
StaticContextImpl::resolve(const String& aRelativeUri) const
{
  zstring lResolved;
  try
  {
    const zstring& lRelativeUri = Unmarshaller::getInternalString(aRelativeUri);
    lResolved = theCtx->resolve_relative_uri(lRelativeUri, true);
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
    return "";
  }
  return lResolved.str();
}


String
StaticContextImpl::resolve(const String& aRelativeUri, const String& aBaseUri) const
{
  zstring lResolved;
  try
  {
    const zstring& lRelativeUri = Unmarshaller::getInternalString(aRelativeUri);
    const zstring& lBaseUri = Unmarshaller::getInternalString(aBaseUri);
    lResolved = theCtx->resolve_relative_uri(lRelativeUri, lBaseUri, true);
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
    return "";
  }
  return lResolved.str();
}


bool
StaticContextImpl::validate(
    const Item& rootElement,
    Item& validatedResult,
    validation_mode_t validationMode) const
{
  try
  {
    StaticContextConsts::validation_mode_t valMode;

    switch( validationMode)
    {
      case validate_lax:
        valMode = StaticContextConsts::lax_validation;
        break;
      case validate_skip:
        valMode = StaticContextConsts::skip_validation;
        break;
      case validate_strict:
      default:
        valMode = StaticContextConsts::strict_validation;
        break;
    }

    store::Item_t lRes(Unmarshaller::getInternalItem(validatedResult));
    bool lResBool = theCtx->validate(Unmarshaller::getInternalItem(rootElement),
                            lRes,
                            valMode);
    validatedResult = lRes;
    return lResBool;
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
    return false;
  }
}


bool
StaticContextImpl::validate(
    const Item& rootElement,
    Item& validatedResult,
    const String& targetNamespace,
    validation_mode_t validationMode) const
{
  try
  {
    StaticContextConsts::validation_mode_t valMode;

    switch( validationMode)
    {
      case validate_lax:
        valMode = StaticContextConsts::lax_validation;
        break;
      case validate_skip:
        valMode = StaticContextConsts::skip_validation;
        break;
      case validate_strict:
      default:
        valMode = StaticContextConsts::strict_validation;
        break;
    }

    store::Item_t lRes(Unmarshaller::getInternalItem(validatedResult));
    zstring lTns = Unmarshaller::getInternalString(targetNamespace);
    bool lResBool = theCtx->validate(
        Unmarshaller::getInternalItem(rootElement),
        lRes, lTns, valMode);
    validatedResult = lRes;
    return lResBool;
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
    return false;
  }
}


bool
StaticContextImpl::validateSimpleContent(
    const String& stringValue,
    const Item& typeQName,
    std::vector<Item>& resultList) const
{
  try {
    bool res;
    std::vector<store::Item_t> tmpResList;
    zstring lTextValue = Unmarshaller::getInternalString(stringValue);

    res = theCtx->validateSimpleContent(lTextValue,
                                        Unmarshaller::getInternalItem(typeQName),
                                        tmpResList);

    if (!res)
      return false;

    for(std::vector<Item>::size_type i = 0; i < tmpResList.size(); ++i)
    {
      store::Item_t item = tmpResList[i];
      resultList.push_back(Item(item));
    }

    return true;
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
    return false;
  }
}


/**
 * construct the query to call invoke
 * for the QName of the function and for each argument,
 * the query declares an external variable ($qname, $arg_1, ..., $arg_n)
 * which needs to be bound before execution.
 */
String
StaticContextImpl::createInvokeQuery(const Function_t& aFunc, size_t aArity) const
{
  std::ostringstream lOut;

  // prolog
  lOut
    << "import module namespace ref = 'http://www.zorba-xquery.com/modules/reflection';"
    << std::endl
    << "declare variable $xxx-func-name as xs:QName" << " external;" << std::endl;

  for (size_t i = 0; i < aArity; ++i)
  {
    lOut << "declare variable $arg" << i << " external;" << std::endl;
  }

  // body

  // call updating, sequential, or simple invoke function
  lOut << "ref:invoke";

  if (aFunc->isUpdating())
    lOut << "-u";
  else if (aFunc->isSequential())
    lOut << "-s";
  else if (!aFunc->isDeterministic())
    lOut << "-n";

  // args
  lOut << "($xxx-func-name";
  for (size_t i = 0; i < aArity; ++i)
  {
    lOut << ", $arg" << i;
  }
  lOut << ")";
  return lOut.str();
}


Function_t
StaticContextImpl::checkInvokable(const Item& aQName, size_t aNumArgs) const
{
  Item lType = aQName.getType();
  if (lType.getStringValue() != "xs:QName")
  {
    throw XQUERY_EXCEPTION(
      err::XPTY0004, ERROR_PARAMS( ZED( BadType_23o ), "xs:QName" )
    );
  }

  // test if function with given #args exists
  Function_t lFunc;
  std::vector<Function_t> lFunctions;
  findFunctions(aQName, lFunctions);
  if (lFunctions.empty())
  {
    throw XQUERY_EXCEPTION(
      err::XPST0017,
      ERROR_PARAMS(
        aQName.getStringValue(), ZED( FunctionUndeclared_3 ), aNumArgs
      )
    );
  }

  for (std::vector<Function_t>::const_iterator lIter = lFunctions.begin();
       lIter != lFunctions.end(); ++lIter)
  {
    if ((*lIter)->isVariadic() || (*lIter)->getArity() == aNumArgs)
    {
      lFunc = (*lIter);
      break;
    }
  }

  if (!lFunc)
  {
    throw XQUERY_EXCEPTION(
      err::XPST0017,
      ERROR_PARAMS(
        aQName.getStringValue(), ZED( FunctionUndeclared_3 ), aNumArgs
      )
    );
  }

  return lFunc;
}


ItemSequence_t
StaticContextImpl::invoke(
    const Item& aQName,
    const std::vector<ItemSequence_t>& aArgs) const
{
  try
  {
    Function_t lFunc = checkInvokable(aQName, aArgs.size());

    String lStr = createInvokeQuery(lFunc, aArgs.size());

    std::auto_ptr<XQueryImpl> impl(new XQueryImpl());

    // compile without any hints
    Zorba_CompilerHints_t lHints;
    StaticContext_t lSctx = new StaticContextImpl(*this);

    impl->compile(lStr, lSctx, lHints);

    // bind qname and params
    DynamicContext* lDCtx = impl->getDynamicContext();
    lDCtx->setVariable("xxx-func-name", aQName);
    for (size_t i = 0; i < aArgs.size(); ++i)
    {
      std::ostringstream lArgName;
      lArgName << "arg" << i;
      lDCtx->setVariable(lArgName.str(), aArgs[i]->getIterator());
    }

    // the XQueryImpl object needs to live as long as its iterator
    // because the iterator returned as a result of the query
    // contains a reference to the query in order to do cleanup work
    Iterator_t lIter = impl->iterator();
    return new InvokeItemSequence(impl.release(), lIter);
  } 
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
    return 0;
  }
}


StaticCollectionManager*
StaticContextImpl::getStaticCollectionManager() const
{
  // assumption: Zorba is already initialized
  // otherwise there was no chance for the user to get this XQuery object
  Zorba* lZorba = Zorba::getInstance(0);
  ItemFactory* lFactory = lZorba->getItemFactory();

  if (!theCollectionMgr)
  {
    theCollectionMgr = new StaticCollectionManagerImpl(this,
                                                       lFactory,
                                                       theDiagnosticHandler);
  }
  return theCollectionMgr;
}


void
StaticContextImpl::setAuditEvent(audit::Event* anEvent)
{
  theCtx->set_audit_event(anEvent);
}


audit::Event*
StaticContextImpl::getAuditEvent() const
{
  return theCtx->get_audit_event();
}


void
StaticContextImpl::getExternalVariables(Iterator_t& aVarsIter) const
{
  ZORBA_TRY
  std::vector<var_expr_t> lVars;
  theCtx->getVariables(lVars, true, false, true);

  std::vector<var_expr_t>::const_iterator lIte = lVars.begin();
  std::vector<var_expr_t>::const_iterator lEnd = lVars.end();
  std::vector<store::Item_t> lExVars;

  for (; lIte != lEnd; ++lIte) 
  { 
    lExVars.push_back(lIte->getp()->get_name());        
  }

  Iterator_t vIter = new VectorIterator(lExVars, theDiagnosticHandler);
  aVarsIter = vIter; 
  ZORBA_CATCH
}

} /* namespace zorba */
/* vim:set et sw=2 ts=2: */
