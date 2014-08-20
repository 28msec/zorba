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

#include "api/xmldatamanagerimpl.h"

#include <fstream>

#include <zorba/config.h>
#include <zorba/zorba_string.h>
#include <zorba/item.h>
#include <zorba/item_sequence.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/iterator.h>
#include <zorba/diagnostic_handler.h>

#include "api/zorbaimpl.h"
#include "api/unmarshaller.h"
#include "api/collectionimpl.h"
#include "api/staticcontextimpl.h"
#include "api/documentmanagerimpl.h"
#include "api/collectionmanagerimpl.h"
#include "context/static_context.h"
#include "diagnostics/xquery_diagnostics.h"
#include "runtime/util/flowctl_exception.h"
#include "store/api/collection.h"
#include "store/api/item.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "zorbamisc/ns_consts.h"

#ifndef ZORBA_NO_FULL_TEXT
#include "stemmer_wrappers.h"
#endif /* ZORBA_NO_FULL_TEXT */

namespace zorba {


#define ZORBA_DM_TRY                                    \
  try

#define ZORBA_DM_CATCH                                         \
  catch (ZorbaException const& e)                              \
  {                                                            \
    ZorbaImpl::notifyError(theDiagnosticHandler, e);           \
  }                                                            \
  catch (std::exception const& e)                              \
  {                                                            \
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());    \
  }                                                            \
  catch (...)                                                  \
  {                                                            \
    ZorbaImpl::notifyError(theDiagnosticHandler);              \
  }


/*******************************************************************************

********************************************************************************/
XmlDataManagerImpl::XmlDataManagerImpl()
  :
  theDocManager(0),
  theColManager(0),
  theW3CColManager(0)
#ifndef ZORBA_NO_FULL_TEXT
  , theStemmerProviderWrapper(0)
#endif /* ZORBA_NO_FULL_TEXT */
{
  Zorba* lZorba = Zorba::getInstance(0);
  theFactory = lZorba->getItemFactory();

  initStaticContext();

  theDiagnosticHandler = new DiagnosticHandler();
  theUserDiagnosticHandler = false;

  ZORBA_TRY
  {
    theStore = & GENV_STORE;
  }
  ZORBA_CATCH
}


/*******************************************************************************

********************************************************************************/
void XmlDataManagerImpl::initStaticContext(DiagnosticHandler* aDiagnosticHandler)
{
  // assumption: Zorba is already initialized
  // otherwise there was no chance for the user to get this data manager
  Zorba* lZorba = Zorba::getInstance(0);

  theContext = lZorba->createStaticContext(aDiagnosticHandler);

  Zorba_CompilerHints_t lHints;
  std::ostringstream lProlog;
  lProlog
    << "import module namespace x = '" << static_context::ZORBA_XML_FN_NS << "';"
    << "import schema namespace opt = '" << static_context::ZORBA_XML_FN_OPTIONS_NS << "';";

  theContext->loadProlog(lProlog.str(), lHints);
}


/*******************************************************************************

********************************************************************************/
XmlDataManagerImpl::~XmlDataManagerImpl()
{
  if (!theUserDiagnosticHandler)
    delete theDiagnosticHandler;

  delete theDocManager;
  delete theColManager;
  delete theW3CColManager;
}


/*******************************************************************************

********************************************************************************/
DocumentManager* XmlDataManagerImpl::getDocumentManager() const
{
  if (!theDocManager)
  {
    theDocManager = new DocumentManagerImpl(theContext, theFactory);
    theDocManager->registerDiagnosticHandler(theDiagnosticHandler);
  }
  return theDocManager;
}


/*******************************************************************************

********************************************************************************/
CollectionManager* XmlDataManagerImpl::getCollectionManager() const
{
  if (!theColManager)
  {
    theColManager = new CollectionManagerImpl(
        theContext,
        theFactory,
        theDiagnosticHandler,
        "http://zorba.io/modules/store/dynamic/collections/ddl",
        "http://zorba.io/modules/store/dynamic/collections/dml");
  }
  return theColManager;
}


/*******************************************************************************

********************************************************************************/
CollectionManager* XmlDataManagerImpl::getW3CCollectionManager() const
{
  if (!theW3CColManager)
  {
    theW3CColManager = new CollectionManagerImpl(
        theContext,
        theFactory,
        theDiagnosticHandler,
        "http://zorba.io/modules/store/dynamic/collections/w3c/ddl",
        "http://zorba.io/modules/store/dynamic/collections/w3c/dml");
  }
  return theW3CColManager;
}


/*******************************************************************************

********************************************************************************/
static void streamReleaser(std::istream* stream)
{
  // it's the user's responsibility to manage the lifetime
}


/*******************************************************************************

********************************************************************************/
Item XmlDataManagerImpl::parseXML(std::istream& aStream) const
{
  ZORBA_DM_TRY
  {
    Item lQName = theFactory->createQName(static_context::W3C_FN_NS, "parse-xml");

    // create a streamable string item
    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(
    new SingletonItemSequence(theFactory->createStreamableString(aStream,
                                                                 &streamReleaser)));

    ItemSequence_t lSeq = theContext->invoke(lQName, lArgs);
    Iterator_t lIter = lSeq->getIterator();
    lIter->open();
    Item lRes;
    lIter->next(lRes);
    return lRes;
  }
  ZORBA_DM_CATCH
  return 0;
}


/*******************************************************************************

********************************************************************************/
Item XmlDataManagerImpl::parseXML(
    std::istream& aStream,
    const String& aBaseURI) const
{
  ZORBA_DM_TRY
  {
    Item lQName = theFactory->createQName(static_context::W3C_FN_NS,
                                          "parse-xml");

    // create a streamable string item
    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(
    new SingletonItemSequence(theFactory->createStreamableString(aStream,
                                                                 &streamReleaser)));
    lArgs.push_back(
    new SingletonItemSequence(theFactory->createString(aBaseURI)));

    ItemSequence_t lSeq = theContext->invoke(lQName, lArgs);
    Iterator_t lIter = lSeq->getIterator();
    lIter->open();
    Item lRes;
    lIter->next(lRes);
    return lRes;
  }
  ZORBA_DM_CATCH
  return 0;
}


/*******************************************************************************

********************************************************************************/
ItemSequence_t XmlDataManagerImpl::parseXML(
    std::istream& aStream,
    XmlDataManager::ParseOptions& aOptions) const
{
  ZORBA_DM_TRY
  {
    Item lQName = theFactory->createQName(static_context::ZORBA_XML_FN_NS, "parse");

    // create a streamable string item
    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(
        theFactory->createStreamableString(aStream, &streamReleaser)));

    Item empty_item;
    Item validated_options;
    NsBindings nsPairs;
    Item untyped_type = theFactory->createQName(static_context::W3C_XML_SCHEMA_NS,
                                                "",
                                                "untyped");
    Item options_node = theFactory->createElementNode(empty_item,
        theFactory->createQName(static_context::ZORBA_XML_FN_OPTIONS_NS, "options"),
        untyped_type, false, false, nsPairs);

    if (aOptions.isDtdValidationEnabled())
      theFactory->createElementNode(options_node,
          theFactory->createQName(static_context::ZORBA_XML_FN_OPTIONS_NS, "DTD-validate"),
          untyped_type, false, false, nsPairs);

    if (aOptions.isExternalEntityProcessingEnabled())
      theFactory->createElementNode(options_node,
          theFactory->createQName(static_context::ZORBA_XML_FN_OPTIONS_NS, "parse-external-parsed-entity"),
          untyped_type, false, false, nsPairs);

    theContext->validate(options_node, validated_options, validate_strict);

    lArgs.push_back(new SingletonItemSequence(validated_options));

    return theContext->invoke(lQName, lArgs);
  }
  ZORBA_DM_CATCH
  return 0;
}


/*******************************************************************************

********************************************************************************/
ItemSequence_t XmlDataManagerImpl::parseXML(
    std::istream& aStream,
    const String& aBaseURI,
    ParseOptions& aOptions) const
{
  ZORBA_DM_TRY
  {
    Item lQName = theFactory->createQName(static_context::ZORBA_XML_FN_NS,
                                          "parse");

    // create a streamable string item
    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(
                    theFactory->createStreamableString(aStream, &streamReleaser)));

    Item empty_item;
    Item validated_options;
    NsBindings nsPairs;

    Item untyped_type = theFactory->createQName(static_context::W3C_XML_SCHEMA_NS,
                                                "",
                                                "untyped");

    Item options_node =
    theFactory->createElementNode(
                empty_item,
                theFactory->createQName(static_context::ZORBA_XML_FN_OPTIONS_NS,
                                        "options"),
                untyped_type, false, false, nsPairs);

    if (aOptions.isDtdValidationEnabled())
      theFactory->createElementNode(
                  options_node,
                  theFactory->createQName(static_context::ZORBA_XML_FN_OPTIONS_NS,
                                          "DTD-validate"),
                  untyped_type, false, false, nsPairs);

    if (aOptions.isExternalEntityProcessingEnabled())
      theFactory->createElementNode(
                  options_node,
                  theFactory->createQName(static_context::ZORBA_XML_FN_OPTIONS_NS,
                                          "parse-external-parsed-entity"),
                  untyped_type, false, false, nsPairs);
    
    Item base_uri_node = 
    theFactory->createElementNode(
                options_node,
                theFactory->createQName(static_context::ZORBA_XML_FN_OPTIONS_NS,
                                        "base-uri"),
                untyped_type, false, false, nsPairs);

    theFactory->createAttributeNode(
                base_uri_node,
                theFactory->createQName(static_context::ZORBA_XML_FN_OPTIONS_NS, "value"),
                Item(),
                theFactory->createString(aBaseURI));

    theContext->validate(options_node, validated_options, validate_strict);

    lArgs.push_back(new SingletonItemSequence(validated_options));

    return theContext->invoke(lQName, lArgs);
  }
  ZORBA_DM_CATCH
  return 0;
}


/*******************************************************************************

********************************************************************************/
void XmlDataManagerImpl::registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler)
{
  if (!theUserDiagnosticHandler)
    delete theDiagnosticHandler;

  theDiagnosticHandler = aDiagnosticHandler;
  theUserDiagnosticHandler = true;

  initStaticContext(aDiagnosticHandler);

  if (theColManager)
  {
    theColManager->registerDiagnosticHandler(theDiagnosticHandler);
  }
  if (theDocManager)
  {
    theDocManager->registerDiagnosticHandler(theDiagnosticHandler);
  }
  if (theW3CColManager)
  {
    theW3CColManager->registerDiagnosticHandler(theDiagnosticHandler);
  }
}

#ifndef ZORBA_NO_FULL_TEXT
/*******************************************************************************

********************************************************************************/
void XmlDataManagerImpl::registerStemmerProvider(StemmerProvider const *p)
{
  if ( theStemmerProviderWrapper )
  {
    if ( theStemmerProviderWrapper->get_provider() == p )
      return;
    delete theStemmerProviderWrapper;
    theStemmerProviderWrapper = nullptr;
  }
  if ( p )
  {
    theStemmerProviderWrapper = new internal::StemmerProviderWrapper( p );
    theStore->setStemmerProvider( theStemmerProviderWrapper );
  }
}


/*******************************************************************************

********************************************************************************/
void XmlDataManagerImpl::registerTokenizerProvider(TokenizerProvider const *p)
{
  theStore->setTokenizerProvider( p );
}
#endif /* ZORBA_NO_FULL_TEXT */

} // namespace zorba
/* vim:set et sw=2 ts=2: */
