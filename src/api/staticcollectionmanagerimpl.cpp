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

#include "api/staticcollectionmanagerimpl.h"

#include <zorba/zorba_string.h>
#include <zorba/item.h>
#include <zorba/item_sequence.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/iterator.h>
#include <zorba/options.h>
#include <zorba/item_factory.h>
#include <zorba/diagnostic_list.h>

#include "api/collectionmanagerimpl.h"
#include "api/item_sequence_chainer.h"
#include "api/collectionimpl.h"
#include "api/unmarshaller.h"
#include "api/zorbaimpl.h"
#include "api/staticcontextimpl.h"
#include "api/annotationimpl.h"

#include "diagnostics/xquery_diagnostics.h"
#include "context/static_context.h"

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
StaticCollectionManagerImpl::StaticCollectionManagerImpl(
  const StaticContextImpl* aCtx,
  ItemFactory* aFactory)
  : theFactory(aFactory),
    theColDDLNamespace("http://www.zorba-xquery.com/modules/store/static/collections/ddl"),
    theColDMLNamespace("http://www.zorba-xquery.com/modules/store/static/collections/dml")
{
  // the context passed as parameter is not used anywhere in here.
  // it's just used to create a child of the passed context
  // Note that callers (e.g. in XQueryImpl::getStaticCollectionManager)
  // can destroy the object because only internal static contexts
  // are needed.
  theContext = aCtx->createChildContext();
  theCollMgr = new CollectionManagerImpl(
      theContext, theFactory, theColDDLNamespace, theColDMLNamespace);
  initStaticContext(theContext);
}

/*******************************************************************************

********************************************************************************/
StaticCollectionManagerImpl::~StaticCollectionManagerImpl()
{
  delete theCollMgr;
}

/*******************************************************************************

********************************************************************************/
void
StaticCollectionManagerImpl::createCollection(const Item& aQName)
{
  theCollMgr->createCollection(aQName);
}

/*******************************************************************************

********************************************************************************/
void
StaticCollectionManagerImpl::createCollection(
    const Item& aQName,
    const ItemSequence_t& aContents)
{
  // do a check here in order to get better (non-confusing) error messages
  if (!isDeclaredCollection(aQName)) {
    throw ZORBA_EXCEPTION( zerr::ZDDY0001_COLLECTION_NOT_DECLARED,
      ERROR_PARAMS( aQName.getStringValue() )
    );
  }
  theCollMgr->createCollection(aQName, aContents);
}

/*******************************************************************************

********************************************************************************/
void
StaticCollectionManagerImpl::deleteCollection(const Item& aQName)
{
  // do a check here in order to get better (non-confusing) error messages
  if (!isDeclaredCollection(aQName)) {
    throw ZORBA_EXCEPTION( zerr::ZDDY0001_COLLECTION_NOT_DECLARED,
      ERROR_PARAMS( aQName.getStringValue() )
    );
  }
  theCollMgr->deleteCollection(aQName);
}

/*******************************************************************************

********************************************************************************/
Collection_t
StaticCollectionManagerImpl::getCollection(const Item& aQName) const
{
  return theCollMgr->getCollection(aQName);
}

/*******************************************************************************

********************************************************************************/
ItemSequence_t
StaticCollectionManagerImpl::availableCollections() const
{
  return theCollMgr->availableCollections();
}

/*******************************************************************************

********************************************************************************/
bool
StaticCollectionManagerImpl::isAvailableCollection(const Item& aQName) const
{
  // do a check here in order to get better (non-confusing) error messages
  if (!isDeclaredCollection(aQName)) {
    throw ZORBA_EXCEPTION( zerr::ZDDY0001_COLLECTION_NOT_DECLARED,
      ERROR_PARAMS( aQName.getStringValue() )
    );
  }
  return theCollMgr->isAvailableCollection(aQName);
}


/*******************************************************************************

********************************************************************************/
ItemSequence_t
StaticCollectionManagerImpl::declaredCollections() const
{
  ZORBA_DM_TRY
  {
    Item lFunc = theFactory->createQName(
        theColDDLNamespace,
        "declared-collections");

    std::vector<ItemSequence_t> lArgs;
    return theContext->invoke(lFunc, lArgs);
  }
  ZORBA_DM_CATCH
  return 0;
}


/*******************************************************************************

********************************************************************************/
bool
StaticCollectionManagerImpl::isDeclaredCollection(const Item& aQName) const
{
  ZORBA_DM_TRY
  {
    Item lFunc = theFactory->createQName(
        theColDDLNamespace,
        "is-declared-collection");

    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(aQName));

    ItemSequence_t lSeq = theContext->invoke(lFunc, lArgs);
    Iterator_t lIter = lSeq->getIterator();
    lIter->open();
    Item lRes;
    lIter->next(lRes);
    return lRes.getBooleanValue();
  }
  ZORBA_DM_CATCH
  return false;
}

/*******************************************************************************

********************************************************************************/
void
StaticCollectionManagerImpl::initStaticContext(StaticContext_t& aCtx)
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
StaticCollectionManagerImpl::registerDiagnosticHandler(
    DiagnosticHandler* aDiagnosticHandler)
{
  theDiagnosticHandler = aDiagnosticHandler;
  theCollMgr->registerDiagnosticHandler(aDiagnosticHandler);
}

/*******************************************************************************

********************************************************************************/
StaticCollectionManagerSetImpl::StaticCollectionManagerSetImpl(MgrSet& aSet)
  : theMgrs(aSet)
{
}

/*******************************************************************************

********************************************************************************/
StaticCollectionManagerSetImpl::~StaticCollectionManagerSetImpl()
{
  for (MgrSet::iterator lIter = theMgrs.begin();
       lIter != theMgrs.end();
       ++lIter) {
    delete (*lIter);
  }
}

/*******************************************************************************

********************************************************************************/
void
StaticCollectionManagerSetImpl::createCollection(const Item& aQName)
{
  for (MgrSet::iterator lIter = theMgrs.begin();
       lIter != theMgrs.end();
       ++lIter) {
    // do a check here in order to get better (non-confusing) error messages
    if ((*lIter)->isDeclaredCollection(aQName)) {
        (*lIter)->createCollection(aQName);
        return;
    }
  }
  throw ZORBA_EXCEPTION( zerr::ZDDY0001_COLLECTION_NOT_DECLARED,
    ERROR_PARAMS( aQName.getStringValue() )
  );
}

/*******************************************************************************

********************************************************************************/
void
StaticCollectionManagerSetImpl::createCollection(
    const Item& aQName,
    const ItemSequence_t& aContents)
{
  for (MgrSet::iterator lIter = theMgrs.begin();
       lIter != theMgrs.end();
       ++lIter) {
    // do a check here in order to get better (non-confusing) error messages
    if ((*lIter)->isDeclaredCollection(aQName)) {
        (*lIter)->createCollection(aQName, aContents);
        return;
    }
  }
  throw ZORBA_EXCEPTION( zerr::ZDDY0001_COLLECTION_NOT_DECLARED,
    ERROR_PARAMS( aQName.getStringValue() )
  );
}

/*******************************************************************************

********************************************************************************/
void
StaticCollectionManagerSetImpl::deleteCollection(const Item& aQName)
{
  for (MgrSet::iterator lIter = theMgrs.begin();
       lIter != theMgrs.end();
       ++lIter) {
    // do a check here in order to get better (non-confusing) error messages
    if ((*lIter)->isDeclaredCollection(aQName)) {
        (*lIter)->deleteCollection(aQName);
        return;
    }
  }
  throw ZORBA_EXCEPTION( zerr::ZDDY0001_COLLECTION_NOT_DECLARED,
    ERROR_PARAMS( aQName.getStringValue() )
  );
}

/*******************************************************************************

********************************************************************************/
Collection_t
StaticCollectionManagerSetImpl::getCollection(const Item& aQName) const
{
  for (MgrSet::const_iterator lIter = theMgrs.begin();
       lIter != theMgrs.end();
       ++lIter) {
    // do a check here in order to get better (non-confusing) error messages
    if ((*lIter)->isDeclaredCollection(aQName)) {
      return (*lIter)->getCollection(aQName);
    }
  }
  throw ZORBA_EXCEPTION( zerr::ZDDY0001_COLLECTION_NOT_DECLARED,
    ERROR_PARAMS( aQName.getStringValue() )
  );
}

/*******************************************************************************

********************************************************************************/
ItemSequence_t
StaticCollectionManagerSetImpl::availableCollections() const
{
  std::vector<ItemSequence_t> lSequences;
  if (theMgrs.begin() != theMgrs.end())
  {
    lSequences.push_back((*theMgrs.begin())->availableCollections());
  }
  return new ItemSequenceChainer(lSequences);
}

/*******************************************************************************

********************************************************************************/
bool
StaticCollectionManagerSetImpl::isAvailableCollection(const Item& aQName) const
{
  for (MgrSet::const_iterator lIter = theMgrs.begin();
       lIter != theMgrs.end(); ++lIter) {
    // do a check here in order to get better (non-confusing) error messages
    if ((*lIter)->isDeclaredCollection(aQName) &&
        (*lIter)->isAvailableCollection(aQName)) {
      return true;
    }
  }
  return false;
}


/*******************************************************************************

********************************************************************************/
ItemSequence_t
StaticCollectionManagerSetImpl::declaredCollections() const
{
  std::vector<ItemSequence_t> lSequences;
  for (MgrSet::const_iterator lIter = theMgrs.begin();
       lIter != theMgrs.end(); ++lIter) {
    lSequences.push_back((*lIter)->declaredCollections());
  }
  // we need to do duplicate elimination of the sequence because
  // the contexts might contain the declaration of a collection
  // multiple times. This happens if the set of contexts contains
  // the context that declares the collection as well as some
  // contexts that result from compiling modules that import
  // the module declaring the collection.
  return new ItemSequenceChainer(lSequences, true);
}

/*******************************************************************************

********************************************************************************/
bool
StaticCollectionManagerSetImpl::isDeclaredCollection(const Item& aQName) const
{
  for (MgrSet::const_iterator lIter = theMgrs.begin();
       lIter != theMgrs.end(); ++lIter) {
    if ((*lIter)->isDeclaredCollection(aQName)) {
      return true;
    }
  }
  return false;
}


/*******************************************************************************

********************************************************************************/
void
StaticCollectionManagerSetImpl::registerDiagnosticHandler(
    DiagnosticHandler* aDiagnosticHandler)
{
  for (MgrSet::const_iterator lIter = theMgrs.begin();
       lIter != theMgrs.end(); ++lIter) {
    (*lIter)->registerDiagnosticHandler(aDiagnosticHandler);
  }
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
