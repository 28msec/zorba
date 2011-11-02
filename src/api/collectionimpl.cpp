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

#include "api/collectionimpl.h"

#include <vector>
#include <zorba/item.h>
#include <zorba/item_factory.h>
#include <zorba/diagnostic_handler.h>
#include <zorba/item_sequence.h>
#include <zorba/static_context.h>
#include <zorba/iterator.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/typeident.h>

#include "api/zorbaimpl.h"
#include "api/unmarshaller.h"

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/zorba_exception.h"

// The following includes are needed for getAnnotations and getType
// might later be done using invoke 
#include "system/globalenv.h"

#include "store/api/store.h"
#include "store/api/collection.h"
#include "store/api/annotation.h"
#include "annotations/annotations.h"
#include "api/annotationimpl.h"

#include "context/static_context.h"

#include "types/typeimpl.h"
#include "types/typeops.h"

#include "compiler/xqddf/collection_decl.h"

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
CollectionImpl::CollectionImpl(
    const StaticContext_t& aSctx,
    ItemFactory* aFactory,
    const Item& aQName,
    DiagnosticHandler* aDiagnosticHandler,
    const std::string& aDMLNS)
  :
  theContext(aSctx->createChildContext()),
  theFactory(aFactory),
  theQName(aQName),
  theDiagnosticHandler(aDiagnosticHandler),
  theNS(aDMLNS)
{
  initStaticContext();
}


/*******************************************************************************

********************************************************************************/
CollectionImpl::~CollectionImpl()
{
}


/*******************************************************************************

********************************************************************************/
void
CollectionImpl::initStaticContext()
{
  Zorba_CompilerHints_t lHints;
  std::ostringstream lProlog;
  lProlog << "import module namespace d = '" << theNS << "';";
  theContext->loadProlog(lProlog.str(), lHints);
}


/*******************************************************************************

********************************************************************************/
void
CollectionImpl::invoke(
    const char* aLocalName,
    const std::vector<ItemSequence_t>& aArgs) const
{
  Item lFunc = theFactory->createQName(theNS, aLocalName);

  ItemSequence_t lSeq = theContext->invoke(lFunc, aArgs);
  Iterator_t lIter = lSeq->getIterator();
  lIter->open();
  Item lRes;
  lIter->next(lRes);
}


/*******************************************************************************

********************************************************************************/
void
CollectionImpl::insertNodesFirst(const ItemSequence_t& aNodes)
{
  ZORBA_DM_TRY
  {
    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(theQName));
    lArgs.push_back(aNodes);

    invoke("insert-nodes-first", lArgs);
  }
  ZORBA_DM_CATCH
}


/*******************************************************************************

********************************************************************************/
void
CollectionImpl::insertNodesLast(const ItemSequence_t& aNodes)
{
  ZORBA_DM_TRY
  {
    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(theQName));
    lArgs.push_back(aNodes);

    invoke("insert-nodes-last", lArgs);
  }
  ZORBA_DM_CATCH
}


/*******************************************************************************

********************************************************************************/
void
CollectionImpl::insertNodesBefore(
    const Item& aTarget,
    const ItemSequence_t& aNodes)
{
  ZORBA_DM_TRY
  {
    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(theQName));
    lArgs.push_back(new SingletonItemSequence(aTarget));
    lArgs.push_back(aNodes);

    invoke("insert-nodes-before", lArgs);
  }
  ZORBA_DM_CATCH
}


/*******************************************************************************

********************************************************************************/
void
CollectionImpl::insertNodesAfter(
    const Item& aTarget,
    const ItemSequence_t& aNodes)
{
  ZORBA_DM_TRY
  {
    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(theQName));
    lArgs.push_back(new SingletonItemSequence(aTarget));
    lArgs.push_back(aNodes);
    
    invoke("insert-nodes-after", lArgs);
  }
  ZORBA_DM_CATCH
}


/*******************************************************************************

********************************************************************************/
void
CollectionImpl::deleteNodes(const ItemSequence_t& aNodes)
{
  ZORBA_DM_TRY
  {
    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(theQName));
    lArgs.push_back(aNodes);
    
    invoke("delete-nodes", lArgs);
  }
  ZORBA_DM_CATCH
}


/*******************************************************************************

********************************************************************************/
void
CollectionImpl::deleteNodeFirst()
{
  ZORBA_DM_TRY
  {
    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(theQName));
    
    invoke("delete-node-first", lArgs);
  }
  ZORBA_DM_CATCH
}


/*******************************************************************************

********************************************************************************/
void
CollectionImpl::deleteNodesFirst(unsigned long aNumNodes)
{
  ZORBA_DM_TRY
  {
    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(theQName));
    lArgs.push_back(new SingletonItemSequence(theFactory->createUnsignedLong(aNumNodes)));
    
    invoke("delete-nodes-first", lArgs);
  }
  ZORBA_DM_CATCH
}


/*******************************************************************************

********************************************************************************/
void
CollectionImpl::deleteNodeLast()
{
  ZORBA_DM_TRY
  {
    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(theQName));

    invoke("delete-node-last", lArgs);
  }
  ZORBA_DM_CATCH
}


/*******************************************************************************

********************************************************************************/
void
CollectionImpl::deleteNodesLast(unsigned long aNumNodes)
{
  ZORBA_DM_TRY
  {
    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(theQName));
    lArgs.push_back(new SingletonItemSequence(theFactory->createUnsignedLong(aNumNodes)));
    
    invoke("delete-nodes-last", lArgs);
  }
  ZORBA_DM_CATCH
}


/*******************************************************************************

********************************************************************************/
long long
CollectionImpl::indexOf(const Item& aNode)
{
  ZORBA_DM_TRY
  {
    // some consistency checking
    // (1) given node needs to be in a collection and
    // (2) the collection needs to be the same as the given collection
    store::Item_t lNode = Unmarshaller::getInternalItem(aNode);
    const store::Collection* aColl = lNode->getCollection();
    if (!aColl) 
    {
      throw ZORBA_EXCEPTION(zerr::ZSTR0009_COLLECTION_NOT_FOUND);
    }
    store::Item_t lName1 = Unmarshaller::getInternalItem(aNode.getCollectionName());
    store::Item_t lName2 = Unmarshaller::getInternalItem(theQName);
    if (lName1 != lName2) 
    {
      throw ZORBA_EXCEPTION(zerr::ZDDY0011_COLLECTION_NODE_NOT_FOUND,
      ERROR_PARAMS(lName1->getStringValue()));
    }

    Item lFunc = theFactory->createQName(theNS, "index-of");

    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(aNode));

    ItemSequence_t lSeq = theContext->invoke(lFunc, lArgs);
    Iterator_t lIter = lSeq->getIterator();
    lIter->open();
    Item lRes;
    lIter->next(lRes);

    return lRes.getLongValue();
  }
  ZORBA_DM_CATCH
  return -1;
}


/*******************************************************************************

********************************************************************************/
ItemSequence_t
CollectionImpl::contents()
{
  ZORBA_DM_TRY
  {
    Item lFunc = theFactory->createQName(theNS, "collection");

    std::vector<ItemSequence_t> lArgs;
    lArgs.push_back(new SingletonItemSequence(theQName));

    return theContext->invoke(lFunc, lArgs);
  }
  ZORBA_DM_CATCH
  return 0;
}


/*******************************************************************************

********************************************************************************/
const Item
CollectionImpl::getName() const
{
  return theQName;
}


/*******************************************************************************

********************************************************************************/
TypeIdentifier_t
CollectionImpl::getType() const
{
  ZORBA_DM_TRY
  {
    store::Item* lQName = Unmarshaller::getInternalItem(theQName);

    static_context* lCtx = Unmarshaller::getInternalStaticContext(theContext);

    const StaticallyKnownCollection* lColl = lCtx->lookup_collection(lQName);
    if (!lColl)
    {
      return 0;
    }

    const XQType* lType = lColl->getCollectionType();

    return TypeOps::get_type_identifier(lCtx->get_typemanager(), *lType);

  }
  ZORBA_DM_CATCH
  return 0;
}


/*******************************************************************************

********************************************************************************/
bool
CollectionImpl::isStatic() const
{
  ZORBA_DM_TRY
  {
    store::Item* lQName = Unmarshaller::getInternalItem(theQName);

    static_context* lCtx = Unmarshaller::getInternalStaticContext(theContext);

    const StaticallyKnownCollection* lColl = lCtx->lookup_collection(lQName);
    return (lColl != NULL);
  }
  ZORBA_DM_CATCH
  return false;
}


/*******************************************************************************

********************************************************************************/
void
CollectionImpl::getAnnotations(std::vector<Annotation_t>& aAnnotations) const
{
  ZORBA_DM_TRY
  {
    store::Item* lQName = Unmarshaller::getInternalItem(theQName);

    store::Store* lStore = & GENV_STORE;

    store::Collection_t lColl = lStore->getCollection(lQName);

    if (!lColl)
    {
      lColl = lStore->getCollection(lQName, true);
    }
    // must exist because otherwise we wouldn't have an instance of this class
    ZORBA_ASSERT(lColl);

    std::vector<store::Annotation_t> lAnns;
    std::vector<store::Annotation_t>::const_iterator lIter;
    lColl->getAnnotations(lAnns);

    for (lIter = lAnns.begin(); lIter != lAnns.end(); ++lIter)
    {
      store::Annotation_t lSAnn = *lIter;

      std::vector<store::Item_t> lLiterals = lSAnn->theLiterals;

      aAnnotations.push_back(
      new AnnotationImpl(new AnnotationInternal(lSAnn->theName, lLiterals)));
    }
  }
  ZORBA_DM_CATCH
}


/*******************************************************************************

********************************************************************************/
void
CollectionImpl::registerDiagnosticHandler(
    DiagnosticHandler* aDiagnosticHandler)
{
  theDiagnosticHandler = aDiagnosticHandler;
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
