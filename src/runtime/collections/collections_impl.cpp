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

#include <algorithm>

#include "diagnostics/assert.h"
#include "diagnostics/xquery_diagnostics.h"

#include "zorbatypes/URI.h"
#include "zorbatypes/numconversions.h"

#include "system/globalenv.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"
#include "context/uri_resolver.h"
#include "context/static_context_consts.h"

#include "compiler/xqddf/value_ic.h"

#include "runtime/collections/collections.h"
#include "runtime/collections/collections_impl.h"
#include "runtime/core/apply_updates.h"
#include "runtime/base/plan_iterator.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/pul.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"
#include "store/api/ic.h"
#include "store/api/index.h"
#include "store/api/annotation.h"
#include "store/api/shared_types.h"
#include "types/typeops.h"
#include "types/root_typemanager.h"


namespace zorba {

void
getCopyMode(
    store::CopyMode& aCopyMode,
    const static_context* aSctx);

void checkNodeType(
    const static_context* aSctx,
    const store::Item_t& aNode,
    const StaticallyKnownCollection* aColl,
    const QueryLoc& aLoc,
    bool  dyn_coll);


/*******************************************************************************
  fn:collection() as node()*
  fn:collection($uri as xs:string?) as node()*
********************************************************************************/
FnCollectionIteratorState::~FnCollectionIteratorState()
{
  if ( theIterator != NULL )
  {
    // closing the iterator is necessary here if an exception occurs
    // in the producer or if the iterator is not fully consumed
    if (theIteratorOpened)
    {
      theIterator->close();
      theIteratorOpened = false;
    }
    theIterator = NULL;
  }
}


void FnCollectionIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theIterator = NULL;
}


void FnCollectionIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);

  if ( theIterator != NULL )
  {
    // closing the iterator is necessary here if an exception occurs
    // in the producer or if the iterator is not fully consumed
    if (theIteratorOpened)
    {
      theIterator->close();
      theIteratorOpened = false;
    }
    theIterator = NULL;
  }
}


bool FnCollectionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lURI, resolvedURIItem;
  store::Collection_t coll;
  std::auto_ptr<internal::Resource> lResource;
  internal::CollectionResource* lCollResource;
  zstring resolvedURIString;
  zstring lErrorMessage;

  FnCollectionIteratorState *state;
  DEFAULT_STACK_INIT(FnCollectionIteratorState, state, planState);

  if (theChildren.size() == 1 &&
      consumeNext(lURI, theChildren[0].getp(), planState))
  {
    try
    {
      resolvedURIString = theSctx->resolve_relative_uri(lURI->getStringValue());
    }
    catch (ZorbaException const&)
    {
      throw XQUERY_EXCEPTION(
        err::FODC0004,
        ERROR_PARAMS( lURI->getStringValue(), ZED( BadAnyURI ) ),
        ERROR_LOC( loc )
      );
    }
  }
  else
  {
    resolvedURIItem = planState.theGlobalDynCtx->get_default_collection();

    if (NULL == resolvedURIItem)
      throw XQUERY_EXCEPTION(
        err::FODC0002,
        ERROR_PARAMS( ZED( DefaultCollation ), ZED( NotDefInDynamicCtx ) ),
        ERROR_LOC( loc )
      );

    resolvedURIString = theSctx->resolve_relative_uri(resolvedURIItem->getStringValue());
  }

  lResource = theSctx->resolve_uri(resolvedURIString,
                                   internal::EntityData::COLLECTION,
                                   lErrorMessage);

  lCollResource = dynamic_cast<internal::CollectionResource*>(lResource.get());

  if ( lCollResource == 0 || !(coll = lCollResource->getCollection()) )
  {
    throw XQUERY_EXCEPTION(
      err::FODC0004,
      ERROR_PARAMS( resolvedURIString, lErrorMessage ),
      ERROR_LOC( loc )
    );
  }

  /** return the nodes of the collection */
  state->theIterator = coll->getIterator();
  ZORBA_ASSERT(state->theIterator!=NULL);
  state->theIterator->open();
  state->theIteratorOpened = true;

  while(state->theIterator->next(result))
    STACK_PUSH (true, state);

  // close as early as possible
  state->theIterator->close();
  state->theIteratorOpened = false;

  STACK_END (state);
}


/*******************************************************************************
  Iterator for optimizing fn:count when applied to collections
********************************************************************************/
CountCollectionIterator::CountCollectionIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    CollectionType collectionType)
  :
  NaryBaseIterator<CountCollectionIterator, PlanIteratorState>(sctx, loc, children),
  theCollectionType(collectionType)
{
}


CountCollectionIterator::~CountCollectionIterator() 
{
}


void CountCollectionIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<CountCollectionIterator, PlanIteratorState>*)this);

  SERIALIZE_ENUM(enum CollectionType, theCollectionType);
}


bool CountCollectionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t coll;
  store::Item_t qName;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (this->isZorbaCollection())
    coll = getZorbaCollection(planState);
  else
    coll = getW3CCollection(planState);

  STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, coll->size()), state);

  STACK_END(state);
}


store::Collection_t CountCollectionIterator::getW3CCollection(PlanState& planState) const
{
  store::Item_t lURI;
  store::Collection_t coll;
  std::auto_ptr<internal::Resource> lResource;
  internal::CollectionResource* lCollResource;
  zstring resolvedURIString;
  zstring lErrorMessage;

  if (!theChildren.empty()) //if a URI was given
  {
    ZORBA_ASSERT(consumeNext(lURI, theChildren[0].getp(), planState));

    try
    {
      resolvedURIString = theSctx->resolve_relative_uri(lURI->getStringValue());
    }
    catch (ZorbaException const&)
    {
      throw XQUERY_EXCEPTION(
        err::FODC0004,
        ERROR_PARAMS(lURI->getStringValue(), ZED(BadAnyURI)),
        ERROR_LOC( loc )
      );
    }
  }
  else
  {
    lURI = planState.theGlobalDynCtx->get_default_collection();

    if( NULL == lURI)
      throw XQUERY_EXCEPTION(
        err::FODC0002,
        ERROR_PARAMS( ZED( DefaultCollation ), ZED( NotDefInDynamicCtx ) ),
        ERROR_LOC( loc )
      );

    resolvedURIString = theSctx->resolve_relative_uri(lURI->getStringValue());
  }


  lResource = theSctx->resolve_uri(resolvedURIString, 
                                   internal::EntityData::COLLECTION,
                                   lErrorMessage);

  lCollResource = dynamic_cast<internal::CollectionResource*>(lResource.get());

  if ( lCollResource == 0 || !(coll = lCollResource->getCollection()) )
  {
    throw XQUERY_EXCEPTION(
      err::FODC0004,
      ERROR_PARAMS(resolvedURIString, lErrorMessage),
      ERROR_LOC( loc )
    );
  }

  return coll;
}


store::Collection_t CountCollectionIterator::getZorbaCollection(
    PlanState& planState) const
{
  store::Item_t qName;
  store::Collection_t coll;

  ZORBA_ASSERT(consumeNext(qName, theChildren[0].getp(), planState));

  if (theSctx->lookup_collection(qName) == 0  && ! this->isDynamicCollection())
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0001_COLLECTION_NOT_DECLARED,
      ERROR_PARAMS( qName->getStringValue() ),
      ERROR_LOC( loc )
    );
  }

  coll = GENV_STORE.getCollection(qName, isDynamicCollection());

  if (coll == NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0003_COLLECTION_DOES_NOT_EXIST,
      ERROR_PARAMS( qName->getStringValue() ),
      ERROR_LOC( loc )
    );
  }

  return coll;
}


SERIALIZABLE_CLASS_VERSIONS(CountCollectionIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CountCollectionIterator)


NARY_ACCEPT(CountCollectionIterator);


/*******************************************************************************

********************************************************************************/
ZorbaCollectionIteratorState::~ZorbaCollectionIteratorState()
{
  if ( theIterator != NULL )
  {
    // closing the iterator is necessary here if an exception occurs
    // in the producer or if the iterator is not fully consumed
    if (theIteratorOpened)
    {
      theIterator->close();
      theIteratorOpened = false;
    }
    theIterator = NULL;
  }
}


void ZorbaCollectionIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theIterator = NULL;
}


void ZorbaCollectionIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);

  if (theIterator != NULL)
  {
    // closing the iterator is necessary here if an exception occurs
    // in the producer or if the iterator is not fully consumed
    if (theIteratorOpened)
    {
      theIterator->close();
      theIteratorOpened = false;
    }
    theIterator = NULL;
  }
}


bool ZorbaCollectionIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t collectionName;
  store::Collection_t collection;

  ZorbaCollectionIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaCollectionIteratorState, state, planState);

  consumeNext(collectionName, theChildren[0].getp(), planState);

  (void)getCollection(theSctx, collectionName, loc, theDynamicCollection, collection);

  // return the nodes of the collection
  state->theIterator = collection->getIterator();
  ZORBA_ASSERT(state->theIterator != NULL);
  state->theIterator->open();
  state->theIteratorOpened = true;

  while(state->theIterator->next(result))
    STACK_PUSH(true, state);

  // close as early as possible
  state->theIterator->close();
  state->theIteratorOpened = false;

  STACK_END(state);
}

const StaticallyKnownCollection*
ZorbaCollectionIterator::getCollection(
    const static_context* aSctx,
    const store::Item_t& aName,
    const QueryLoc& aLoc,
    bool aDynamicCollection,
    store::Collection_t& coll) const
{
  const StaticallyKnownCollection* collectionDecl = aSctx->lookup_collection(aName);
  if (collectionDecl == 0  && !aDynamicCollection)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0001_COLLECTION_NOT_DECLARED,
      ERROR_PARAMS( aName->getStringValue() ),
      ERROR_LOC( aLoc )
    );
  }

  coll = GENV_STORE.getCollection(aName, aDynamicCollection);

  if (coll == NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0003_COLLECTION_DOES_NOT_EXIST,
      ERROR_PARAMS( aName->getStringValue() ),
      ERROR_LOC( aLoc )
    );
  }

  return collectionDecl;
}


/*******************************************************************************
  declare function index-of($name as xs:QName,
                            $target as node()) as xs:integer

  The function will return the index of the $target node within the collection
  identified by $name. Note: the function uses index numbers starting at 1.
********************************************************************************/
bool ZorbaIndexOfIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Collection_t collection;
  store::Item_t node;
  xs_integer pos = 1;
  bool found;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(node, theChildren[0].getp(), planState))
  {
    collection = node->getCollection();

    if (!collection)
      throw XQUERY_EXCEPTION( zerr::ZDDY0017_NODE_IS_ORPHAN, ERROR_LOC( loc ) );

    found = collection->findNode(node, pos);
    ZORBA_ASSERT(found);
    STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, pos+xs_integer(1)),
               state);
  }

  STACK_END (state);
}

const StaticallyKnownCollection*
ZorbaIndexOfIterator::getCollection(
    const static_context* aSctx,
    const store::Item_t& aName,
    const QueryLoc& aLoc,
    bool aDynamicCollection,
    store::Collection_t& coll) const
{
  const StaticallyKnownCollection* collectionDecl = aSctx->lookup_collection(aName);
  if (collectionDecl == 0  && !aDynamicCollection)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0001_COLLECTION_NOT_DECLARED,
      ERROR_PARAMS( aName->getStringValue() ),
      ERROR_LOC( aLoc )
    );
  }

  coll = GENV_STORE.getCollection(aName, aDynamicCollection);

  if (coll == NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0003_COLLECTION_DOES_NOT_EXIST,
      ERROR_PARAMS( aName->getStringValue() ),
      ERROR_LOC( aLoc )
    );
  }

  return collectionDecl;
}

/*******************************************************************************
  declare updating function
  create($name as xs:QName) as empty-sequence()

  declare updating function
  create($name as xs:QName, $nodes as node()*) as empty-sequence()

  The first function will create a new, empty, collection. The second function
  will create a new collection and will add the given nodes to it.
********************************************************************************/
bool ZorbaCreateCollectionIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t collectionName;
  store::Collection_t collection;
  const StaticallyKnownCollection* collectionDecl;
  store::Item_t node;
  store::Item_t copyNode;
  std::auto_ptr<store::PUL> pul;
  store::Item_t lNodeType;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(collectionName, theChildren[0].getp(), aPlanState);

  collectionDecl = getCollection(
      theSctx, collectionName, loc, theDynamicCollection, collection);

  if (collection != NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0002_COLLECTION_ALREADY_EXISTS,
      ERROR_PARAMS( collectionName->getStringValue() ),
      ERROR_LOC( loc )
    );
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  if (theDynamicCollection)
  {
    std::vector<store::Annotation_t> lAnnotations;
    store::Annotation_t lAnn = 0;

    // dynamic collections have some default properties
    lAnn = new store::Annotation();
    lAnn->theName = AnnotationInternal::lookup(AnnotationInternal::zann_mutable);
    lAnnotations.push_back(lAnn);

    lAnn = new store::Annotation();
    lAnn->theName = AnnotationInternal::lookup(AnnotationInternal::zann_ordered);
    lAnnotations.push_back(lAnn);

    lAnn = new store::Annotation();
    lAnn->theName = AnnotationInternal::lookup(AnnotationInternal::zann_mutable_nodes);
    lAnnotations.push_back(lAnn);

    pul->addCreateCollection(
        &loc,
        collectionName,
        lAnnotations,
        NULL,
        true);
  }
  else
  {
    std::vector<store::Annotation_t> lAnnotations;
    AnnotationList* lDeclaredAnnotations = collectionDecl->getAnnotations();

    for (size_t i = 0; i < lDeclaredAnnotations->size(); ++i)
    {
      store::Annotation_t lAnn = new store::Annotation();
      AnnotationInternal* lTmp = lDeclaredAnnotations->getAnnotation(i);

      lAnn->theName = lTmp->getQName();

      for (csize j = 0; j < lTmp->getNumLiterals(); ++j)
      {
        lAnn->theLiterals.push_back(lTmp->getLiteral(j));
      }
      lAnnotations.push_back(lAnn);
    }

    lNodeType = collectionDecl->getNodeType()->get_qname();

    pul->addCreateCollection(
        &loc,
        collectionName,
        lAnnotations,
        lNodeType,
        false);
  }

  // also add some optional nodes to the collection
  if (theChildren.size() == 2)
  {
    store::CopyMode copymode;
    getCopyMode(copymode, theSctx);
    std::vector<store::Item_t> nodes;
    ulong numNodes = 0;

    while (consumeNext(node, theChildren[1].getp(), aPlanState))
    {
      checkNodeType(theSctx, node, collectionDecl, loc, theDynamicCollection);

      copyNode = node->copy(NULL, copymode);

      nodes.resize(numNodes+1);
      nodes[numNodes++].transfer(copyNode);
    }

    pul->addInsertIntoCollection(&loc, collectionName, nodes, theDynamicCollection);
  }

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END(state);
}

const StaticallyKnownCollection*
ZorbaCreateCollectionIterator::getCollection(
    const static_context* aSctx,
    const store::Item_t& aName,
    const QueryLoc& aLoc,
    bool aDynamicCollection,
    store::Collection_t& coll) const
{
  const StaticallyKnownCollection* collectionDecl = aSctx->lookup_collection(aName);
  if (collectionDecl == 0  && !aDynamicCollection)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0001_COLLECTION_NOT_DECLARED,
      ERROR_PARAMS( aName->getStringValue() ),
      ERROR_LOC( aLoc )
    );
  }

  coll = GENV_STORE.getCollection(aName, aDynamicCollection);

  return collectionDecl;
}

/*******************************************************************************
  declare updating function delete($name as xs:QName)

  The function will delete the collection identified by the given URI.
********************************************************************************/
bool ZorbaDeleteCollectionIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t collectionName;
  store::Collection_t collection;
  std::auto_ptr<store::PUL> pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(collectionName, theChildren[0].getp(), aPlanState);

  (void)getCollection(theSctx, collectionName, loc, theDynamicCollection, collection);

  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addDeleteCollection(&loc, collectionName, theDynamicCollection);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END(state);
}

const StaticallyKnownCollection*
ZorbaDeleteCollectionIterator::getCollection(
    const static_context* aSctx,
    const store::Item_t& aName,
    const QueryLoc& aLoc,
    bool aDynamicCollection,
    store::Collection_t& coll) const
{
  const StaticallyKnownCollection* collectionDecl = aSctx->lookup_collection(aName);
  if (collectionDecl == 0  && !aDynamicCollection)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0001_COLLECTION_NOT_DECLARED,
      ERROR_PARAMS( aName->getStringValue() ),
      ERROR_LOC( aLoc )
    );
  }
  coll = GENV_STORE.getCollection(aName, aDynamicCollection);
  if (coll == NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0003_COLLECTION_DOES_NOT_EXIST,
      ERROR_PARAMS( aName->getStringValue() ),
      ERROR_LOC( aLoc )
    );
  }
  return collectionDecl;
}

/*******************************************************************************
  declare updating function
  insert-nodes($name as xs:QName, $newnode as node()*)

  The function will insert the given nodes to the given collection.
********************************************************************************/
bool ZorbaInsertNodesIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  std::vector<store::Item_t>       nodes;
  std::auto_ptr<store::PUL>        pul;
  store::Item_t                    collectionName;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  checkCollectionAndCopyNodes(planState, collectionName, nodes);

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  if (nodes.size() > 0)
    pul->addInsertIntoCollection(&loc, collectionName, nodes, theDynamicCollection);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END(state);
}

const StaticallyKnownCollection*
ZorbaInsertNodesIterator::getCollection(
    const static_context* aSctx,
    const store::Item_t& aName,
    const QueryLoc& aLoc,
    bool aDynamicCollection,
    store::Collection_t& coll) const
{
  const StaticallyKnownCollection* collectionDecl =
    ZorbaCollectionIteratorHelper<ZorbaInsertNodesIterator, PlanIteratorState>::getCollection(
        aSctx, aName, aLoc, aDynamicCollection, coll);

  if (!aDynamicCollection) {
    // checking collection update mode
    switch(collectionDecl->getUpdateProperty())
    {
      case StaticContextConsts::decl_const:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0004_COLLECTION_CONST_UPDATE,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_append_only:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0005_COLLECTION_APPEND_BAD_INSERT,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_queue:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0006_COLLECTION_QUEUE_BAD_INSERT,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_mutable:
        // good to go
        break;

      default:
        ZORBA_ASSERT(false);
    }
  }

  return collectionDecl;
}


/*******************************************************************************
  declare updating function
  insert-nodes-first($name as xs:QName, $newnode as node()*) as none

  The function will insert the given node(s) as the first node(s) of the given
  collection. If multiple nodes are inserted, the nodes remain adjacent and
  their order preserves the node ordering of the source expression.
********************************************************************************/
bool ZorbaInsertNodesFirstIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  std::vector<store::Item_t>       nodes;
  std::auto_ptr<store::PUL>        pul;
  store::Item_t                    collectionName;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  checkCollectionAndCopyNodes(planState, collectionName, nodes);

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addInsertFirstIntoCollection(&loc, collectionName, nodes, theDynamicCollection);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END(state);
}

const StaticallyKnownCollection*
ZorbaInsertNodesFirstIterator::getCollection(
    const static_context* aSctx,
    const store::Item_t& aName,
    const QueryLoc& aLoc,
    bool aDynamicCollection,
    store::Collection_t& coll) const
{
  const StaticallyKnownCollection* collectionDecl =
    ZorbaCollectionIteratorHelper<ZorbaInsertNodesFirstIterator, PlanIteratorState>::
      getCollection(aSctx, aName, aLoc, aDynamicCollection, coll);

  if (!aDynamicCollection) {
    switch(collectionDecl->getUpdateProperty())
    {
      case StaticContextConsts::decl_const:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0004_COLLECTION_CONST_UPDATE,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_append_only:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0005_COLLECTION_APPEND_BAD_INSERT,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_queue:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0006_COLLECTION_QUEUE_BAD_INSERT,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_mutable:
        // good to go
        break;

      default:
        ZORBA_ASSERT(false);
    }
    if (collectionDecl->getOrderProperty() == StaticContextConsts::decl_unordered)
    {
      throw XQUERY_EXCEPTION(
        zerr::ZDDY0012_COLLECTION_UNORDERED_BAD_OPERATION,
        ERROR_PARAMS( aName->getStringValue(), "insert" ),
        ERROR_LOC( loc )
      );
    }
  }
  return collectionDecl;
}

/*******************************************************************************
  declare updating function
  insert-nodes-last($name as xs:QName, $newnode as node()*) as none

  The function will insert the given node(s) as the last node(s) of the given
  collection. If multiple nodes are inserted, the nodes remain adjacent and
  their order preserves the node ordering of the source expression.

  Error conditions:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
  - If the specified collection does not exist, an error is raised
    (ZAPI0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the node is already in the collection, an error is raised
    (ZAPI0031_NODE_ALREADY_IN_COLLECTION)
********************************************************************************/
bool ZorbaInsertNodesLastIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  std::vector<store::Item_t>       nodes;
  std::auto_ptr<store::PUL>        pul;
  store::Item_t                    collectionName;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  checkCollectionAndCopyNodes(planState, collectionName, nodes);

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addInsertLastIntoCollection(&loc, collectionName, nodes, theDynamicCollection);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}

const StaticallyKnownCollection*
ZorbaInsertNodesLastIterator::getCollection(
    const static_context* aSctx,
    const store::Item_t& aName,
    const QueryLoc& aLoc,
    bool aDynamicCollection,
    store::Collection_t& coll) const
{
  const StaticallyKnownCollection* collectionDecl =
    ZorbaCollectionIteratorHelper<ZorbaInsertNodesLastIterator, PlanIteratorState>::getCollection(
        aSctx, aName, aLoc, aDynamicCollection, coll);

  if (!aDynamicCollection) {
    switch(collectionDecl->getUpdateProperty())
    {
      case StaticContextConsts::decl_const:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0004_COLLECTION_CONST_UPDATE,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_append_only:
      case StaticContextConsts::decl_queue:
      case StaticContextConsts::decl_mutable:
        // good to go
        break;

      default:
        ZORBA_ASSERT(false);
    }

    if (collectionDecl->getOrderProperty() == StaticContextConsts::decl_unordered)
    {
      throw XQUERY_EXCEPTION(
        zerr::ZDDY0012_COLLECTION_UNORDERED_BAD_OPERATION,
        ERROR_PARAMS( aName->getStringValue(), "insert" ),
        ERROR_LOC( loc )
      );
    }
  }
  return collectionDecl;
}

/*******************************************************************************
  declare updating function
  insert-nodes-before($name as xs:QName,
                      $target as node(),
                      $newnodes as node()*)

  The inserted nodes become the preceding (or following) nodes of the target.
  The $target should be a non-updating expression (e.g. an XPath expression)
  identifying a node that is part of the given collection at the top-level.
  If multiple nodes are inserted by a single insert expression, the nodes remain
  adjacent and their order preserves the node ordering of the source expression.
********************************************************************************/
bool ZorbaInsertNodesBeforeIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t                    collectionName;
  store::Item_t                    targetNode;
  store::Item_t                    node;
  std::vector<store::Item_t>       nodes;
  std::auto_ptr<store::PUL>        pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  checkCollectionAndCopyNodes(planState, collectionName, nodes, targetNode, true);
  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addInsertBeforeIntoCollection(&loc, collectionName, targetNode, nodes, theDynamicCollection);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-2]->reset(planState);
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END(state);
}

const StaticallyKnownCollection*
ZorbaInsertNodesBeforeIterator::getCollection(
    const static_context* aSctx,
    const store::Item_t& aName,
    const QueryLoc& aLoc,
    bool aDynamicCollection,
    store::Collection_t& coll) const
{
  const StaticallyKnownCollection* collectionDecl =
    ZorbaCollectionIteratorHelper<ZorbaInsertNodesBeforeIterator, PlanIteratorState>::getCollection(
        aSctx, aName, aLoc, aDynamicCollection, coll);

  if (!aDynamicCollection) {
    switch(collectionDecl->getUpdateProperty())
    {
      case StaticContextConsts::decl_const:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0004_COLLECTION_CONST_UPDATE,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_append_only:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0005_COLLECTION_APPEND_BAD_INSERT,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_queue:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0006_COLLECTION_QUEUE_BAD_INSERT,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_mutable:
        // good to go
        break;

      default:
        ZORBA_ASSERT(false);
    }

    if (collectionDecl->getOrderProperty() == StaticContextConsts::decl_unordered)
    {
      throw XQUERY_EXCEPTION(
        zerr::ZDDY0012_COLLECTION_UNORDERED_BAD_OPERATION,
        ERROR_PARAMS( aName->getStringValue(), "insert" ),
        ERROR_LOC( loc )
      );
    }
  }
  return collectionDecl;
}

/*******************************************************************************
  declare updating function
  insert-nodes-after($name as xs:QName,
                     $target as node(),
                     $newnode as node()*)

  The inserted nodes become the following nodes of the $target. The $target
  should be a non-updating expression (e.g. an XPath expression) identifying a
  node that is part of the given collection at the top-level. If multiple nodes
  are inserted by a single insert expression, the nodes remain adjacent and
  their order preserves the node ordering of the source expression.
********************************************************************************/
bool ZorbaInsertNodesAfterIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t                    collectionName;
  std::vector<store::Item_t>       nodes;
  std::auto_ptr<store::PUL>        pul;
  store::Item_t                    targetNode;

  store::CopyMode lCopyMode;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  checkCollectionAndCopyNodes(planState, collectionName, nodes, targetNode, true);

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addInsertAfterIntoCollection(&loc, collectionName, targetNode, nodes, theDynamicCollection);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-2]->reset(planState);
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END(state);
}

const StaticallyKnownCollection*
ZorbaInsertNodesAfterIterator::getCollection(
    const static_context* aSctx,
    const store::Item_t& aName,
    const QueryLoc& aLoc,
    bool aDynamicCollection,
    store::Collection_t& coll) const
{
  const StaticallyKnownCollection* collectionDecl =
    ZorbaCollectionIteratorHelper<ZorbaInsertNodesAfterIterator, PlanIteratorState>::getCollection(
        aSctx, aName, aLoc, aDynamicCollection, coll);

  if (!aDynamicCollection) {
    // checking collection modifiers
    switch(collectionDecl->getUpdateProperty())
    {
      case StaticContextConsts::decl_const:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0004_COLLECTION_CONST_UPDATE,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_append_only:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0005_COLLECTION_APPEND_BAD_INSERT,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_queue:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0006_COLLECTION_QUEUE_BAD_INSERT,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_mutable:
        // good to go
        break;

      default:
        ZORBA_ASSERT(false);
    }

    if (collectionDecl->getOrderProperty() == StaticContextConsts::decl_unordered)
    {
      throw XQUERY_EXCEPTION(
        zerr::ZDDY0011_COLLECTION_NODE_NOT_FOUND,
        ERROR_PARAMS( aName->getStringValue() ),
        ERROR_LOC( loc )
      );
    }
  }
  return collectionDecl;
}

/*******************************************************************************
  declare sequential function
  apply-insert-nodes($name as xs:QName, $newnode as node()*)

********************************************************************************/
ZorbaApplyInsertNodesIteratorState::~ZorbaApplyInsertNodesIteratorState()
{
  nodes.clear();
}


void ZorbaApplyInsertNodesIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  nodes.clear();
}


void ZorbaApplyInsertNodesIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  nodes.clear();
}

bool ZorbaApplyInsertNodesIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  std::auto_ptr<store::PUL>        pul;
  std::vector<store::Item_t>       nodes;
  store::Item_t                    collectionName;

  ZorbaApplyInsertNodesIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaApplyInsertNodesIteratorState, state, planState);

  checkCollectionAndCopyNodes(planState, collectionName, nodes);

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  if (nodes.size() > 0) {
    // addInsertIntoCollection removes the nodes from the vector.
    // hence, we also store them in a separate vector in the state
    state->nodes.resize(nodes.size());
    std::copy(nodes.begin(), nodes.end(), state->nodes.begin());
    pul->addInsertIntoCollection(&loc, collectionName, nodes, theDynamicCollection);
  }

  if (pul.get()) {
    apply_updates(planState.theCompilerCB, planState.theGlobalDynCtx, theSctx, pul.get(), loc);
    pul.reset();
  }

  state->iterator = state->nodes.begin();

  while (state->iterator != state->nodes.end()) {
    result = *state->iterator;
    ++(state->iterator);
    STACK_PUSH(true, state);
  }

  STACK_PUSH(false, state);


  STACK_END(state);
}


/*******************************************************************************
  declare sequential function
  apply-insert-nodes-first($name as xs:QName, $newnode as node()*)

********************************************************************************/
ZorbaApplyInsertNodesFirstIteratorState::~ZorbaApplyInsertNodesFirstIteratorState()
{
  nodes.clear();
}


void ZorbaApplyInsertNodesFirstIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  nodes.clear();
}


void ZorbaApplyInsertNodesFirstIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  nodes.clear();
}

bool ZorbaApplyInsertNodesFirstIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  std::auto_ptr<store::PUL>        pul;
  std::vector<store::Item_t>       nodes;
  store::Item_t                    collectionName;

  ZorbaApplyInsertNodesFirstIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaApplyInsertNodesFirstIteratorState, state, planState);

  checkCollectionAndCopyNodes(planState, collectionName, nodes);

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  if (nodes.size() > 0) {
    state->nodes.resize(nodes.size());
    std::copy(nodes.begin(), nodes.end(), state->nodes.begin());
    pul->addInsertFirstIntoCollection(&loc, collectionName, nodes, theDynamicCollection);
  }

  if (pul.get()) {
    apply_updates(planState.theCompilerCB, planState.theGlobalDynCtx, theSctx, pul.get(), loc);
    pul.reset();
  }

  state->iterator = state->nodes.begin();

  while (state->iterator != state->nodes.end()) {
    result = *state->iterator;
    ++(state->iterator);
    STACK_PUSH(true, state);
  }

  STACK_PUSH(false, state);

  STACK_END(state);
}

/*******************************************************************************
  declare sequential function
  apply-insert-nodes-last($name as xs:QName, $newnode as node()*)

********************************************************************************/
ZorbaApplyInsertNodesLastIteratorState::~ZorbaApplyInsertNodesLastIteratorState()
{
  nodes.clear();
}


void ZorbaApplyInsertNodesLastIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  nodes.clear();
}


void ZorbaApplyInsertNodesLastIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  nodes.clear();
}

bool
ZorbaApplyInsertNodesLastIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  std::auto_ptr<store::PUL>        pul;
  std::vector<store::Item_t>       nodes;
  store::Item_t                    collectionName;

  ZorbaApplyInsertNodesLastIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaApplyInsertNodesLastIteratorState, state, planState);

  checkCollectionAndCopyNodes(planState, collectionName, nodes);

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  if (nodes.size() > 0) {
    state->nodes.resize(nodes.size());
    std::copy(nodes.begin(), nodes.end(), state->nodes.begin());
    pul->addInsertLastIntoCollection(&loc, collectionName, nodes, theDynamicCollection);
  }

  if (pul.get()) {
    apply_updates(planState.theCompilerCB, planState.theGlobalDynCtx, theSctx, pul.get(), loc);
    pul.reset();
  }

  state->iterator = state->nodes.begin();

  while (state->iterator != state->nodes.end()) {
    result = *state->iterator;
    ++(state->iterator);
    STACK_PUSH(true, state);
  }

  STACK_PUSH(false, state);

  STACK_END(state);
}


/*******************************************************************************
  declare sequential function
  apply-insert-nodes-before($name as xs:QName, $newnode as node()*)

********************************************************************************/
ZorbaApplyInsertNodesBeforeIteratorState::~ZorbaApplyInsertNodesBeforeIteratorState()
{
  nodes.clear();
}


void ZorbaApplyInsertNodesBeforeIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  nodes.clear();
}


void ZorbaApplyInsertNodesBeforeIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  nodes.clear();
}

bool
ZorbaApplyInsertNodesBeforeIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  std::auto_ptr<store::PUL>        pul;
  std::vector<store::Item_t>       nodes;
  store::Item_t                    collectionName;
  store::Item_t                    targetNode;

  ZorbaApplyInsertNodesIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaApplyInsertNodesIteratorState, state, planState);

  checkCollectionAndCopyNodes(planState, collectionName, nodes, targetNode, true);

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  if (nodes.size() > 0) {
    state->nodes.resize(nodes.size());
    std::copy(nodes.begin(), nodes.end(), state->nodes.begin());
    pul->addInsertBeforeIntoCollection(&loc, collectionName, targetNode, nodes, theDynamicCollection);
  }

  if (pul.get()) {
    apply_updates(planState.theCompilerCB, planState.theGlobalDynCtx, theSctx, pul.get(), loc);
    pul.reset();
  }

  state->iterator = state->nodes.begin();

  while (state->iterator != state->nodes.end()) {
    result = *state->iterator;
    ++(state->iterator);
    STACK_PUSH(true, state);
  }

  STACK_PUSH(false, state);


  STACK_END(state);
}

/*******************************************************************************
  declare sequential function
  apply-insert-nodes-after($name as xs:QName, $newnode as node()*)

********************************************************************************/
ZorbaApplyInsertNodesAfterIteratorState::~ZorbaApplyInsertNodesAfterIteratorState()
{
  nodes.clear();
}


void ZorbaApplyInsertNodesAfterIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  nodes.clear();
}


void ZorbaApplyInsertNodesAfterIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  nodes.clear();
}

bool
ZorbaApplyInsertNodesAfterIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  std::auto_ptr<store::PUL>        pul;
  std::vector<store::Item_t>       nodes;
  store::Item_t                    collectionName;
  store::Item_t                    targetNode;

  ZorbaApplyInsertNodesIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaApplyInsertNodesIteratorState, state, planState);

  checkCollectionAndCopyNodes(planState, collectionName, nodes, targetNode, true);

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  if (nodes.size() > 0) {
    state->nodes.resize(nodes.size());
    std::copy(nodes.begin(), nodes.end(), state->nodes.begin());
    pul->addInsertAfterIntoCollection(&loc, collectionName, targetNode, nodes, theDynamicCollection);
  }

  if (pul.get()) {
    apply_updates(planState.theCompilerCB, planState.theGlobalDynCtx, theSctx, pul.get(), loc);
    pul.reset();
  }

  state->iterator = state->nodes.begin();

  while (state->iterator != state->nodes.end()) {
    result = *state->iterator;
    ++(state->iterator);
    STACK_PUSH(true, state);
  }

  STACK_PUSH(false, state);


  STACK_END(state);
}

/*******************************************************************************
  declare updating function
  delete-nodes($name as xs:QName, $target as node()*)

  The function will remove the node(s) identified by the $target expression
  from the given collection. The nodes themselves will not be deleted until all
  references to them have been removed.
********************************************************************************/
bool ZorbaDeleteNodesIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Collection_t              collection;
  const StaticallyKnownCollection* collectionDecl;
  store::Item_t                    collectionName;
  store::Item_t                    node;
  std::vector<store::Item_t>       nodes;
  std::auto_ptr<store::PUL>        pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState))
  {
    if (! node->getCollection()) {
      throw XQUERY_EXCEPTION( zerr::ZDDY0017_NODE_IS_ORPHAN, ERROR_LOC( loc ) );
    }
    if (collection && collection != node->getCollection()) {
      throw XQUERY_EXCEPTION(
        zerr::ZDDY0018_NODES_NOT_IN_SAME_COLLECTION, ERROR_LOC( loc )
      );
    }
    collection = node->getCollection();

    nodes.push_back(node);
  }

  if (!nodes.empty())
  {
    collectionName = collection->getName();

    collectionDecl = getCollection(theSctx,
                                   collectionName,
                                   loc,
                                   theDynamicCollection,
                                   collection);

    // create the pul and add the primitive
    pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

    pul->addDeleteFromCollection(&loc, collectionName, nodes, false, theDynamicCollection);

    // this should not be necessary. we reset everything in the sequential iterator
    theChildren[theChildren.size()-1]->reset(planState);

    result = pul.release();
    STACK_PUSH(result != NULL, state);
  }

  STACK_END(state);
}

const StaticallyKnownCollection*
ZorbaDeleteNodesIterator::getCollection(
    const static_context* aSctx,
    const store::Item_t& aName,
    const QueryLoc& aLoc,
    bool aDynamicCollection,
    store::Collection_t& coll) const
{
  const StaticallyKnownCollection* collectionDecl = aSctx->lookup_collection(aName);
  if (collectionDecl == 0 && !aDynamicCollection)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0001_COLLECTION_NOT_DECLARED,
      ERROR_PARAMS( aName->getStringValue() ),
      ERROR_LOC( aLoc )
    );
  }

  if (!aDynamicCollection) {
    switch(collectionDecl->getUpdateProperty())
    {
      case StaticContextConsts::decl_const:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0004_COLLECTION_CONST_UPDATE,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_append_only:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0007_COLLECTION_APPEND_BAD_DELETE,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_queue:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0009_COLLECTION_QUEUE_BAD_DELETE,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_mutable:
        // good to go
        break;

      default:
        ZORBA_ASSERT(false);
    }
  }
  coll = GENV_STORE.getCollection(aName, aDynamicCollection);
  if (coll == NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0003_COLLECTION_DOES_NOT_EXIST,
      ERROR_PARAMS( aName->getStringValue() ),
      ERROR_LOC( aLoc )
    );
  }

  return collectionDecl;
}

/*******************************************************************************

********************************************************************************/
bool ZorbaDeleteNodesFirstIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Collection_t              collection;
  const StaticallyKnownCollection* collectionDecl;
  store::Item_t                    collectionName;
  store::Item_t                    numNodesItem;
  xs_integer                       numNodes = 1;
  std::vector<store::Item_t>       nodes;
  std::auto_ptr<store::PUL>        pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(collectionName, theChildren[0].getp(), planState))
    ZORBA_ASSERT(false);

  collectionDecl = getCollection(
      theSctx, collectionName, loc, theDynamicCollection, collection);

  if (theChildren.size() > 1)
  {
    if (!consumeNext(numNodesItem, theChildren[1].getp(), planState))
      ZORBA_ASSERT(false);

    numNodes = numNodesItem->getIntegerValue();
  }

  if (collection->size() < numNodes)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0011_COLLECTION_NODE_NOT_FOUND,
      ERROR_PARAMS( collectionName->getStringValue() ),
      ERROR_LOC( loc )
    );
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  for (xs_integer i = 0; i < numNodes; ++i)
    nodes.push_back(collection->nodeAt(i));

  pul->addDeleteFromCollection(&loc, collectionName, nodes, false, theDynamicCollection);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END(state);
}

const StaticallyKnownCollection*
ZorbaDeleteNodesFirstIterator::getCollection(
    const static_context* aSctx,
    const store::Item_t& aName,
    const QueryLoc& aLoc,
    bool aDynamicCollection,
    store::Collection_t& coll) const
{
  const StaticallyKnownCollection* collectionDecl = aSctx->lookup_collection(aName);
  if (collectionDecl == 0 && !aDynamicCollection)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0001_COLLECTION_NOT_DECLARED,
      ERROR_PARAMS( aName->getStringValue() ),
      ERROR_LOC( aLoc )
    );
  }

  if (!aDynamicCollection) {
    switch(collectionDecl->getUpdateProperty())
    {
      case StaticContextConsts::decl_const:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0004_COLLECTION_CONST_UPDATE,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_append_only:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0007_COLLECTION_APPEND_BAD_DELETE,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_queue:
      case StaticContextConsts::decl_mutable:
        // good to go
        break;

      default:
        ZORBA_ASSERT(false);
    }
  }
  coll = GENV_STORE.getCollection(aName, aDynamicCollection);
  if (coll == NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0003_COLLECTION_DOES_NOT_EXIST,
      ERROR_PARAMS( aName->getStringValue() ),
      ERROR_LOC( aLoc )
    );
  }
  if (collectionDecl &&
      collectionDecl->getOrderProperty() == StaticContextConsts::decl_unordered)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0012_COLLECTION_UNORDERED_BAD_OPERATION,
      ERROR_PARAMS( aName->getStringValue(), "delete" ),
      ERROR_LOC(loc)
    );
  }

  return collectionDecl;
}

/*******************************************************************************

********************************************************************************/
bool ZorbaDeleteNodesLastIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Collection_t              collection;
  const StaticallyKnownCollection* collectionDecl;
  store::Item_t                    collectionName;
  store::Item_t                    numNodesItem;
  xs_integer                       numNodes = 1;
  std::vector<store::Item_t>       nodes;
  std::auto_ptr<store::PUL>        pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(collectionName, theChildren[0].getp(), planState);

  collectionDecl = getCollection(
      theSctx, collectionName, loc, theDynamicCollection, collection);

  if (theChildren.size() > 1)
  {
    if (!consumeNext(numNodesItem, theChildren[1].getp(), planState))
      ZORBA_ASSERT(false);
    numNodes = numNodesItem->getIntegerValue();
  }

  if (collection->size() < numNodes)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0011_COLLECTION_NODE_NOT_FOUND,
      ERROR_PARAMS( collectionName->getStringValue() ),
      ERROR_LOC( loc )
    );
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  for (xs_integer i = numNodes; i > xs_integer(0); --i)
    nodes.push_back(collection->nodeAt(collection->size() - i));

  pul->addDeleteFromCollection(&loc, collectionName, nodes, true, theDynamicCollection);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/
bool ZorbaCollectionNameIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t                    item;
  store::Collection_t              collection;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(item, theChildren[0].getp(), planState);

  collection = item->getCollection();

  if (!collection) {
    throw XQUERY_EXCEPTION( zerr::ZDDY0017_NODE_IS_ORPHAN, ERROR_LOC( loc ) );
  }

  result = collection->getName();

  STACK_PUSH( true, state);

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
const StaticallyKnownCollection*
ZorbaDeleteNodesLastIterator::getCollection(
    const static_context* aSctx,
    const store::Item_t& aName,
    const QueryLoc& aLoc,
    bool aDynamicCollection,
    store::Collection_t& coll) const
{
  const StaticallyKnownCollection* collectionDecl = aSctx->lookup_collection(aName);
  if (collectionDecl == 0 && !aDynamicCollection)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0001_COLLECTION_NOT_DECLARED,
      ERROR_PARAMS( aName->getStringValue() ),
      ERROR_LOC( aLoc )
    );
  }

  if (!aDynamicCollection) {
    switch(collectionDecl->getUpdateProperty())
    {
      case StaticContextConsts::decl_const:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0004_COLLECTION_CONST_UPDATE,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_append_only:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0007_COLLECTION_APPEND_BAD_DELETE,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_queue:
        throw XQUERY_EXCEPTION(
          zerr::ZDDY0008_COLLECTION_QUEUE_BAD_DELETE,
          ERROR_PARAMS( aName->getStringValue() ),
          ERROR_LOC( loc )
        );

      case StaticContextConsts::decl_mutable:
        // good to go
        break;

      default:
        ZORBA_ASSERT(false);
    }
  }
  coll = GENV_STORE.getCollection(aName, aDynamicCollection);
  if (coll == NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0003_COLLECTION_DOES_NOT_EXIST,
      ERROR_PARAMS( aName->getStringValue() ),
      ERROR_LOC( aLoc )
    );
  }
  if (collectionDecl &&
      collectionDecl->getOrderProperty() == StaticContextConsts::decl_unordered)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0012_COLLECTION_UNORDERED_BAD_OPERATION,
      ERROR_PARAMS( aName->getStringValue(), "delete" ),
      ERROR_LOC(loc)
    );
  }
  return collectionDecl;
}

/*******************************************************************************

********************************************************************************/
bool
IsAvailableCollectionIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t       lName;
  store::Collection_t lCollection;
  bool                res = true;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lName, theChildren[0].getp(), planState);

  try
  {
    (void)getCollection(theSctx, lName, loc, theDynamicCollection, lCollection);
  }
  catch (ZorbaException const& e)
  {
    if (e.diagnostic() != zerr::ZDDY0003_COLLECTION_DOES_NOT_EXIST)
    {
      throw;
    }

    // collection is not available if the getCollection helper function throws
    // error ZDDY0003_COLLECTION_DOES_NOT_EXIST
    res = false;
  }

  GENV_ITEMFACTORY->createBoolean(result, res);
  STACK_PUSH(true, state );

  STACK_END (state);
}

const StaticallyKnownCollection*
IsAvailableCollectionIterator::getCollection(
    const static_context* aSctx,
    const store::Item_t& aName,
    const QueryLoc& aLoc,
    bool aDynamicCollection,
    store::Collection_t& coll) const
{
  const StaticallyKnownCollection* collectionDecl = aSctx->lookup_collection(aName);
  if (collectionDecl == 0 && !aDynamicCollection)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0001_COLLECTION_NOT_DECLARED,
      ERROR_PARAMS( aName->getStringValue() ),
      ERROR_LOC( aLoc )
    );
  }
  coll = GENV_STORE.getCollection(aName, aDynamicCollection);
  if (coll == NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0003_COLLECTION_DOES_NOT_EXIST,
      ERROR_PARAMS( aName->getStringValue() ),
      ERROR_LOC( aLoc )
    );
  }
  return collectionDecl;
}

/*******************************************************************************

********************************************************************************/
AvailableCollectionsIteratorState::~AvailableCollectionsIteratorState()
{
  if ( nameItState != NULL )
  {
    nameItState->close();
    nameItState = NULL;
  }
}


void AvailableCollectionsIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  nameItState = NULL;
}


void AvailableCollectionsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if ( nameItState != NULL ) {
    nameItState->close();
    nameItState = NULL;
  }
}


bool
AvailableCollectionsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  AvailableCollectionsIteratorState * state;
  store::Item_t              nameItem;

  DEFAULT_STACK_INIT(AvailableCollectionsIteratorState, state, planState);

  if (theDynamicCollection)
  {
    for ((state->nameItState = GENV_STORE.listCollectionNames(theDynamicCollection))->open ();
         state->nameItState->next(nameItem);)
    {
      result = nameItem;
      STACK_PUSH( true, state);
    }
  }
  else
  {
    // static collections have to exist and need to be declared
    for ((state->nameItState = theSctx->collection_names())->open ();
         state->nameItState->next(nameItem);)
    {
      if (!GENV_STORE.getCollection(nameItem.getp()))
      {
        continue;
      }
      else
      {
        result = nameItem;
        STACK_PUSH( true, state);
      }
    }
  }

  state->nameItState->close();

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool IsAvailableIndexIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t lName;
  bool res = false;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lName, theChildren[0].getp(), planState);

  {
    store::Index_t lIndex = GENV_STORE.getIndex(lName);
    res = (lIndex != 0);
  }

  GENV_ITEMFACTORY->createBoolean(result, res);
  STACK_PUSH(true, state);

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
AvailableIndexesIteratorState::~AvailableIndexesIteratorState()
{
  if ( nameItState != NULL ) {
    nameItState->close();
    nameItState = NULL;
  }
}

void
AvailableIndexesIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  nameItState = NULL;
}

void
AvailableIndexesIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if ( nameItState != NULL ) {
    nameItState->close();
    nameItState = NULL;
  }
}

bool
AvailableIndexesIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t              nameItem;

  AvailableIndexesIteratorState * state;
  DEFAULT_STACK_INIT(AvailableIndexesIteratorState, state, planState);

  for ((state->nameItState = GENV_STORE.listIndexNames())->open ();
       state->nameItState->next(nameItem); )
  {
    result = nameItem;
    STACK_PUSH( true, state);
  }

  state->nameItState->close();

  STACK_END (state);
}

/*******************************************************************************
*******************************************************************************/
bool IsActivatedICIterator::nextImpl(store::Item_t& result,
                                     PlanState& planState) const
{
  PlanIteratorState  *state;
  store::Item_t       lName;
  bool                res = false;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lName, theChildren[0].getp(), planState);

  {
    store::IC_t lIc = GENV_STORE.getIC(lName);
    res = (lIc != 0);
  }

  GENV_ITEMFACTORY->createBoolean(result, res);
  STACK_PUSH(true, state );

  STACK_END (state);
}

/*******************************************************************************
*******************************************************************************/
ActivatedICsIteratorState::~ActivatedICsIteratorState()
{
  if ( nameItState != NULL ) {
    nameItState->close();
    nameItState = NULL;
  }
}

void
ActivatedICsIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  nameItState = NULL;
}

void
ActivatedICsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if ( nameItState != NULL ) {
    nameItState->close();
    nameItState = NULL;
  }
}

bool
ActivatedICsIterator::nextImpl(store::Item_t& result,
                               PlanState& planState) const
{
  store::Item_t              nameItem;

  ActivatedICsIteratorState * state;
  DEFAULT_STACK_INIT(ActivatedICsIteratorState, state, planState);

  for ((state->nameItState = GENV_STORE.listActiveICNames())->open ();
       state->nameItState->next(nameItem); )
  {
    result = nameItem;
    STACK_PUSH( true, state);
  }

  state->nameItState->close();

  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/
bool IsDeclaredCollectionIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  store::Item_t      lName;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);

  if (theSctx->lookup_collection(lName.getp()) == 0)
  {
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(aResult, false), lState);
  }
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(aResult, true), lState);
  }
  STACK_END (lState);
}


/*******************************************************************************

********************************************************************************/
DeclaredCollectionsIteratorState::~DeclaredCollectionsIteratorState()
{
  if ( nameItState != NULL )
  {
    nameItState->close();
    nameItState = NULL;
  }
}


void DeclaredCollectionsIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  nameItState = NULL;
}


void DeclaredCollectionsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if ( nameItState != NULL )
  {
    nameItState->close();
    nameItState = NULL;
  }
}


bool DeclaredCollectionsIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  store::Item_t lName;

  DeclaredCollectionsIteratorState* lState;
  DEFAULT_STACK_INIT(DeclaredCollectionsIteratorState, lState, aPlanState);

  for ((lState->nameItState = theSctx->collection_names())->open();
       lState->nameItState->next(lName); )
  {
    aResult = lName;
    STACK_PUSH(true, lState);
  }

  lState->nameItState->close();

  STACK_END(lState);
}


/*******************************************************************************
*******************************************************************************/
bool
IsDeclaredICIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState)
  const
{
  PlanIteratorState *lState;
  store::Item_t      lName;

  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);
  consumeNext(lName, theChildren[0].getp(), aPlanState);
  if (theSctx->lookup_ic(lName.getp()) == 0) {
    STACK_PUSH (GENV_ITEMFACTORY->createBoolean ( aResult, false ), lState);
  }
  else {
    STACK_PUSH (GENV_ITEMFACTORY->createBoolean ( aResult, true ), lState);
  }
  STACK_END (lState);
}


/*******************************************************************************
********************************************************************************/
bool
DeclaredICsIterator::nextImpl(store::Item_t& aResult, PlanState& aPlanState)
  const
{
  DeclaredICsIteratorState * lState;
  store::Item_t              lName;

  DEFAULT_STACK_INIT(DeclaredICsIteratorState, lState, aPlanState);

  for ((lState->nameItState = theSctx->ic_names())->open ();
       lState->nameItState->next(lName); )
  {
    aResult = lName;
    STACK_PUSH( true, lState);
  }

  lState->nameItState->close();

  STACK_END (lState);
}

DeclaredICsIteratorState::~DeclaredICsIteratorState()
{
  if ( nameItState != NULL ) {
    nameItState->close();
    nameItState = NULL;
  }
}

void DeclaredICsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if ( nameItState != NULL ) {
    nameItState->close();
    nameItState = NULL;
  }
}


/*******************************************************************************

********************************************************************************/
bool IsDeclaredIndexIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  store::Item_t      lName;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);

  if (theSctx->lookup_index(lName.getp()) == 0)
  {
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(aResult, false), lState);
  }
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(aResult, true), lState);
  }

  STACK_END(lState);
}


/*******************************************************************************

********************************************************************************/
DeclaredIndexesIteratorState::~DeclaredIndexesIteratorState()
{
  if (nameItState != NULL)
  {
    nameItState->close();
    nameItState = NULL;
  }
}


void DeclaredIndexesIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if (nameItState != NULL)
  {
    nameItState->close();
    nameItState = NULL;
  }
}


bool DeclaredIndexesIterator::nextImpl(
    store::Item_t& aResult,
    PlanState& aPlanState) const
{
  store::Item_t lName;

  DeclaredIndexesIteratorState* lState;
  DEFAULT_STACK_INIT(DeclaredIndexesIteratorState, lState, aPlanState);

  for ((lState->nameItState = theSctx->index_names())->open();
       lState->nameItState->next(lName); )
  {
    aResult = lName;
    STACK_PUSH(true, lState);
  }

  lState->nameItState->close();

  STACK_END(lState);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
