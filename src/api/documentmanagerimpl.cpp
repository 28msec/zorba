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

#include "api/documentmanagerimpl.h"

#include <zorba/zorba_string.h>
#include <zorba/item.h>
#include <zorba/item_sequence.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/iterator.h>
#include <zorba/static_context.h>
#include <zorba/options.h>
#include <zorba/item_factory.h>

#include "api/unmarshaller.h"

#include "api/zorbaimpl.h"
#include "diagnostics/xquery_diagnostics.h"

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
std::string DocumentManagerImpl::theDocNamespace =
  "http://www.zorba-xquery.com/modules/store/dynamic/documents";

/*******************************************************************************

********************************************************************************/
DocumentManagerImpl::DocumentManagerImpl(
  const StaticContext_t& aSctx,
  ItemFactory* aFactory
  )
  : theContext(aSctx->createChildContext()),
    theFactory(aFactory)
{
  initStaticContext();
}

/*******************************************************************************

********************************************************************************/
void
DocumentManagerImpl::initStaticContext()
{
  Zorba_CompilerHints_t lHints;
  std::ostringstream lProlog;
  lProlog
    << "import module namespace d = '" << theDocNamespace << "';";
  theContext->loadProlog(lProlog.str(), lHints);
}

/*******************************************************************************

********************************************************************************/
DocumentManagerImpl::~DocumentManagerImpl()
{
}

/*******************************************************************************

********************************************************************************/
void
DocumentManagerImpl::put(const String& aURI, const Item& aDoc)
{
  ZORBA_DM_TRY
  {
    Item lQName = theFactory->createQName(theDocNamespace, "put");

    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(theFactory->createAnyURI(aURI)));
    lArgs.push_back(new SingletonItemSequence(aDoc));

    ItemSequence_t lSeq = theContext->invoke(lQName, lArgs);
    Iterator_t lIter = lSeq->getIterator();
    lIter->open();
    Item lRes;
    lIter->next(lRes);
  }
  ZORBA_DM_CATCH
}

/*******************************************************************************

********************************************************************************/
void
DocumentManagerImpl::remove(const String& aURI)
{
  ZORBA_DM_TRY
  {
    Item lQName = theFactory->createQName(theDocNamespace, "remove");

    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(theFactory->createAnyURI(aURI)));

    ItemSequence_t lSeq = theContext->invoke(lQName, lArgs);
    Iterator_t lIter = lSeq->getIterator();
    lIter->open();
    Item lRes;
    lIter->next(lRes);
  }
  ZORBA_DM_CATCH
}

/*******************************************************************************

********************************************************************************/
Item
DocumentManagerImpl::document(const String& aURI) const
{
  ZORBA_DM_TRY
  {
    Item lQName = theFactory->createQName(theDocNamespace, "document");

    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(theFactory->createAnyURI(aURI)));

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
DocumentManagerImpl::availableDocuments() const
{
  ZORBA_DM_TRY
  {
    Item lQName = theFactory->createQName(
        theDocNamespace,
        "available-documents");

    std::vector<ItemSequence_t> lArgs;

    return theContext->invoke(lQName, lArgs);
  }
  ZORBA_DM_CATCH
  return 0;
}

/*******************************************************************************

********************************************************************************/
bool
DocumentManagerImpl::isAvailableDocument(const String& aURI) const
{
  ZORBA_DM_TRY
  {
    Item lQName = theFactory->createQName(
        theDocNamespace,
        "is-available-document");

    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(theFactory->createAnyURI(aURI)));

    ItemSequence_t lSeq = theContext->invoke(lQName, lArgs);
    Iterator_t lIter = lSeq->getIterator();
    lIter->open();
    Item lRes;
    if (!lIter->next(lRes))
      return false;
    return lRes.getBooleanValue();
  }
  ZORBA_DM_CATCH
  return false;
}

/*******************************************************************************

********************************************************************************/
void
DocumentManagerImpl::registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler)
{
  theDiagnosticHandler = aDiagnosticHandler;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
