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

#include "api/collectionmanagerimpl.h"

#include <zorba/zorba_string.h>
#include <zorba/item.h>
#include <zorba/item_sequence.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/iterator.h>
#include <zorba/static_context.h>
#include <zorba/options.h>
#include <zorba/item_factory.h>

#include "api/collectionimpl.h"

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
CollectionManagerImpl::CollectionManagerImpl(
    const StaticContext_t& aSctx,
    ItemFactory* aFactory,
    DiagnosticHandler* aDiagnosticHandler,
    const std::string& aDDLNamespace,
    const std::string& aDMLNamespace)
  :
  theContext(aSctx->createChildContext()),
  theFactory(aFactory),
  theColDDLNamespace(aDDLNamespace),
  theColDMLNamespace(aDMLNamespace),
  theDiagnosticHandler(aDiagnosticHandler)
{
  initStaticContext(theContext);
}


/*******************************************************************************

********************************************************************************/
CollectionManagerImpl::~CollectionManagerImpl()
{
}

/*******************************************************************************

********************************************************************************/
void
CollectionManagerImpl::initStaticContext(StaticContext_t& aCtx)
{
  Zorba_CompilerHints_t lHints;
  std::ostringstream lProlog;
  lProlog
    << "import module namespace d = '" << theColDDLNamespace << "';";
  aCtx->loadProlog(lProlog.str(), lHints);
}

/*******************************************************************************

********************************************************************************/
void
CollectionManagerImpl::createCollection(const Item& aName)
{
  ZORBA_DM_TRY
  {
    Item lFunc = theFactory->createQName(
        theColDDLNamespace,
        "create");

    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(aName));

    ItemSequence_t lSeq = theContext->invoke(lFunc, lArgs);
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
CollectionManagerImpl::createCollection(
    const Item& aName,
    const ItemSequence_t& aContents)
{
  ZORBA_DM_TRY
  {
    Item lFunc = theFactory->createQName(
        theColDDLNamespace,
        "create");

    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(aName));
    lArgs.push_back(aContents);

    ItemSequence_t lSeq = theContext->invoke(lFunc, lArgs);
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
CollectionManagerImpl::deleteCollection(const Item& aName)
{
  ZORBA_DM_TRY
  {
    if (!isAvailableCollection(aName)) {
      throw ZORBA_EXCEPTION( zerr::ZDDY0003_COLLECTION_DOES_NOT_EXIST,
        ERROR_PARAMS( aName.getStringValue() )
      );
    }

    Item lFunc = theFactory->createQName(
        theColDDLNamespace, "delete");

    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(aName));

    ItemSequence_t lSeq = theContext->invoke(lFunc, lArgs);
    Iterator_t lIter = lSeq->getIterator();
    lIter->open();
    Item lRes;
    lIter->next(lRes);
  }
  ZORBA_DM_CATCH
}

/*******************************************************************************

********************************************************************************/
Collection_t
CollectionManagerImpl::getCollection(const Item& aName) const
{
  ZORBA_DM_TRY
  {
    if (!isAvailableCollection(aName)) {
      throw ZORBA_EXCEPTION( zerr::ZDDY0003_COLLECTION_DOES_NOT_EXIST,
        ERROR_PARAMS( aName.getStringValue() )
      );
    }
    return new CollectionImpl(
        theContext,
        theFactory,
        aName,
        theDiagnosticHandler,
        theColDMLNamespace);
  }
  ZORBA_DM_CATCH
  return 0;
}

/*******************************************************************************

********************************************************************************/
ItemSequence_t
CollectionManagerImpl::availableCollections() const
{
  ZORBA_DM_TRY
  {
    Item lFunc = theFactory->createQName(
        theColDDLNamespace,
        "available-collections");

    std::vector<ItemSequence_t> lArgs;

    return theContext->invoke(lFunc, lArgs);
  }
  ZORBA_DM_CATCH
  return 0;
}

/*******************************************************************************

********************************************************************************/
bool
CollectionManagerImpl::isAvailableCollection(const Item& aName) const
{
  ZORBA_DM_TRY
  {
    Item lFunc = theFactory->createQName(
        theColDDLNamespace,
        "is-available-collection");

    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(aName));

    ItemSequence_t lSeq = theContext->invoke(lFunc, lArgs);
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
CollectionManagerImpl::registerDiagnosticHandler(
    DiagnosticHandler* aDiagnosticHandler)
{
  theDiagnosticHandler = aDiagnosticHandler;
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
