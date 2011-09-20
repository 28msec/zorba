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

#include "diagnostics/xquery_diagnostics.h"

#include "store/api/collection.h"
#include "store/api/item.h"
#include "system/globalenv.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"

#include "context/static_context.h"

#include "runtime/util/flowctl_exception.h"

#ifndef ZORBA_NO_FULL_TEXT
#include "stemmer_wrapper.h"
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
  initStaticContext();
  initializeItemFactory();

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
void
XmlDataManagerImpl::initializeItemFactory()
{
  // assumption: Zorba is already initialized
  // otherwise there was no chance for the user to get this data manager
  Zorba* lZorba = Zorba::getInstance(0);
  theFactory = lZorba->getItemFactory();
}


/*******************************************************************************

********************************************************************************/
void
XmlDataManagerImpl::initStaticContext(DiagnosticHandler* aDiagnosticHandler)
{
  // assumption: Zorba is already initialized
  // otherwise there was no chance for the user to get this data manager
  Zorba* lZorba = Zorba::getInstance(0);

  theContext = lZorba->createStaticContext(aDiagnosticHandler);

  Zorba_CompilerHints_t lHints;
  std::ostringstream lProlog;
  lProlog
    << "import module namespace d = '" << static_context::ZORBA_FETCH_FN_NS  << "';"
    << "import module namespace x = '" << static_context::ZORBA_XML_FN_NS << "';";
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
DocumentManager*
XmlDataManagerImpl::getDocumentManager() const
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
CollectionManager*
XmlDataManagerImpl::getCollectionManager() const
{
  if (!theColManager) 
  {
    theColManager = new CollectionManagerImpl(
        theContext,
        theFactory,
        theDiagnosticHandler,
        "http://www.zorba-xquery.com/modules/store/dynamic/collections/ddl",
        "http://www.zorba-xquery.com/modules/store/dynamic/collections/dml");
  }
  return theColManager;
}


/*******************************************************************************

********************************************************************************/
CollectionManager*
XmlDataManagerImpl::getW3CCollectionManager() const
{
  if (!theW3CColManager) 
  {
    theW3CColManager = new CollectionManagerImpl(
        theContext,
        theFactory,
        theDiagnosticHandler,
        "http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/ddl",
        "http://www.zorba-xquery.com/modules/store/dynamic/collections/w3c/dml");
  }
  return theW3CColManager;
}


/*******************************************************************************

********************************************************************************/
static void
streamReleaser(std::istream* stream)
{
  // it's the user's responsibility to manage the lifetime
}


/*******************************************************************************

********************************************************************************/
Item
XmlDataManagerImpl::parseXML(std::istream& aStream) const
{
  ZORBA_DM_TRY
  {
    Item lQName = theFactory->createQName(static_context::W3C_FN_NS.c_str(),
                                          "parse-xml");

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
Item
XmlDataManagerImpl::parseXML(
    std::istream& aStream,
    const String& aBaseURI) const
{
  ZORBA_DM_TRY
  {
    Item lQName = theFactory->createQName(static_context::W3C_FN_NS.c_str(),
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
ItemSequence_t
XmlDataManagerImpl::parseXML(
    std::istream& aStream,
    XmlDataManager::ParseOptions& aOptions) const
{
  ZORBA_DM_TRY
  {
    Item lQName = theFactory->createQName(static_context::ZORBA_XML_FN_NS.c_str(),
                                          "parse-xml-fragment");

    // create a streamable string item
    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(
    new SingletonItemSequence(theFactory->createStreamableString(aStream,
                                                                 &streamReleaser)));

    std::ostringstream lOptions;
    lOptions << (aOptions.isDtdValidationEnabled()?"d":"D");

    lOptions << (aOptions.isExternalEntityProcessingEnabled()?"e":"E");

    lArgs.push_back(
    new SingletonItemSequence(theFactory->createString(lOptions.str())));

    return theContext->invoke(lQName, lArgs);
  }
  ZORBA_DM_CATCH
  return 0;
}


/*******************************************************************************

********************************************************************************/
ItemSequence_t
XmlDataManagerImpl::parseXML(
    std::istream& aStream,
    const String& aBaseURI,
    ParseOptions& aOptions) const
{
  ZORBA_DM_TRY
  {
    Item lQName = theFactory->createQName(static_context::ZORBA_XML_FN_NS.c_str(),
                                          "parse-xml-fragment");

    // create a streamable string item
    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(
    new SingletonItemSequence(theFactory->createStreamableString(aStream,
                                                                 &streamReleaser)));
    lArgs.push_back(
    new SingletonItemSequence(theFactory->createString(aBaseURI)));

    std::ostringstream lOptions;
    lOptions << (aOptions.isDtdValidationEnabled()?"d":"D");

    lOptions << (aOptions.isExternalEntityProcessingEnabled()?"e":"E");

    lArgs.push_back(
    new SingletonItemSequence(theFactory->createString(lOptions.str())));

    return theContext->invoke(lQName, lArgs);
  }
  ZORBA_DM_CATCH
  return 0;
}


/*******************************************************************************

********************************************************************************/
Item
XmlDataManagerImpl::fetch(const String& aURI) const
{
  ZORBA_DM_TRY
  {
    Item lQName = theFactory->createQName(static_context::ZORBA_FETCH_FN_NS.c_str(),
                                          "content");

    // create a streamable string item
    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(
    new SingletonItemSequence(theFactory->createString(aURI)));

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
void XmlDataManagerImpl::registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler)
{
  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)

  theContext = new StaticContextImpl(aDiagnosticHandler);
  if (!theUserDiagnosticHandler)
    delete theDiagnosticHandler;

  theDiagnosticHandler = aDiagnosticHandler;
  theUserDiagnosticHandler = true;

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
  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)
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
  SYNC_CODE(AutoLatch lock(theLatch, Latch::WRITE);)
  theStore->setTokenizerProvider( p );
}
#endif /* ZORBA_NO_FULL_TEXT */

} // namespace zorba
/* vim:set et sw=2 ts=2: */
