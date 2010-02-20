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
#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_messages.h"

#include "zorbatypes/URI.h"
#include "zorbatypes/numconversions.h"

#include "system/globalenv.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"
#include "context/internal_uri_resolvers.h"
#include "context/static_context_consts.h"

#include "compiler/xqddf/collection_decl.h"

#include "runtime/api/runtimecb.h"
#include "runtime/collections/collections.h"

#include "store/api/pul.h"
#include "store/api/copymode.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"
#include "store/api/store.h"
#include "store/api/collection.h"

#include "types/typeops.h"
#include "types/typeimpl.h"


namespace zorba {

// Forward declarations
store::Collection_t getCollection(
    const static_context* aSctx,
    const store::Item_t,
    const QueryLoc&);

const StaticallyKnownCollection* getCollectionDecl(
    const static_context* aSctx,
    const store::Item_t aName,
    const QueryLoc& aLoc);

void checkNodeType(
    const static_context* aSctx,
    const store::Item_t& aNode, 
    const StaticallyKnownCollection* aColl,
    const QueryLoc& aLoc);


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
  store::Item_t       lURI, resolvedURIItem;
  store::Collection_t coll;
  xqpStringStore_t    resolvedURIString, tt;

  FnCollectionIteratorState *state;
  DEFAULT_STACK_INIT(FnCollectionIteratorState, state, planState);

  if (theChildren.size() == 1 &&
      consumeNext(lURI, theChildren[0].getp(), planState)) 
  {
    try 
    {
      tt = lURI->getStringValue();
      resolvedURIString = theSctx->resolve_relative_uri(lURI->getStringValueP(),
                                                        xqp_string()).getStore();

      GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
    }
    catch (error::ZorbaError&) 
    {
      ZORBA_ERROR_LOC_DESC(FODC0002, loc, "Error retrieving resource.");
    }
  }
  else 
  {
    resolvedURIItem = planState.theRuntimeCB->theDynamicContext->
                      get_default_collection();

    if( NULL == resolvedURIItem)
      ZORBA_ERROR_LOC_DESC(FODC0002, loc,
                           "Default collection is undefined in the dynamic context.");
  }

  coll =  theSctx->get_collection_uri_resolver()->
          resolve(resolvedURIItem, theSctx);

  if (coll == 0) 
  {
    ZORBA_ERROR_LOC_PARAM(FODC0004, loc,
                          resolvedURIItem->getStringValue()->c_str(), "");
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
  declare function xqddf:collection($name as xs:QName) as node()*

  TODO descrition
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

  (void)getCollectionDecl(theSctx, collectionName, loc);

  collection = getCollection(theSctx, collectionName, loc);

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
  store::Item_t collectionName;
  store::Collection_t collection;
  store::Item_t node;
  ulong pos = 1;
  bool found;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(collectionName, theChildren[0].getp(), planState);

  (void)getCollectionDecl(theSctx, collectionName, loc);

  collection = getCollection(theSctx, collectionName, loc);

  if (consumeNext(node, theChildren[1].getp(), planState))
  {
    found = collection->findNode(node, pos);

    if (!found)
      ZORBA_ERROR_LOC_DESC(XDDY0011_COLLECTION_NODE_NOT_FOUND,
                           loc,
                           "The node does not belong to collection.");

    STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, Integer::parseInt(pos+1)),
               state);
  }

  STACK_END (state);
}


/*******************************************************************************
  declare updating function
  create-collection($name as xs:QName) as empty-sequence()

  declare updating function
  create-collection($name as xs:QName, $nodes as node()*) as empty-sequence()

  The first function will create a new, empty, collection. The second function
  will create a new collection and will add the given nodes to it.

  Error conditions:
  -  If the collection already exists, an error is raised
     (API0005_COLLECTION_ALREADY_EXISTS - collection already exists).
  - XQP0000_DYNAMIC_RUNTIME_ERROR if the argument is the empty sequence
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

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(collectionName, theChildren[0].getp(), aPlanState);

  // check a collection is in the set of statically known collection with this name
  collectionDecl = getCollectionDecl(theSctx, collectionName, loc);

  // check if the collection already exists
  try
  {
    collection = getCollection(theSctx, collectionName, loc);
  }
  catch (error::ZorbaError& e)
  {
    if (e.theErrorCode != XDDY0003_COLLECTION_DOES_NOT_EXIST)
    {
      throw;
    }
    // we come here if the collection is not available (but is declared)
  }

  if (collection != NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0002_COLLECTION_EXISTS_ALREADY, loc,
                          collectionName->getStringValue(), "");
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addCreateCollection(collectionName);

  // also add some optional nodes to the collection
  if(theChildren.size() == 2) 
  {
    store::CopyMode copymode;
    bool typePreserve;
    bool nsPreserve;
    bool nsInherit;
    std::vector<store::Item_t> nodes;
    ulong numNodes = 0;

    typePreserve = (theSctx->construction_mode() == StaticContextConsts::cons_preserve ?
                    true : false);
    nsPreserve = (theSctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                  true : false);
    nsInherit = (theSctx->inherit_mode() == StaticContextConsts::inherit_ns ?
                 true : false);

    copymode.set(true, typePreserve, nsPreserve, nsInherit);

    while (consumeNext(node, theChildren[1].getp(), aPlanState))
    {
      checkNodeType(theSctx, node, collectionDecl, loc);

      copyNode = node->copy(NULL, 0, copymode);

      nodes.resize(numNodes+1);
      nodes[numNodes++].transfer(copyNode);
    }

    pul->addInsertIntoCollection(collectionName, nodes);
  }

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END(state);
}


/*******************************************************************************
  declare updating function delete-collection($name as xs:QName)

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

  (void)getCollectionDecl(theSctx, collectionName, loc);

  collection = getCollection(theSctx, collectionName, loc);

  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addDeleteCollection(collectionName);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END(state);
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
  store::Collection_t              collection;
  const StaticallyKnownCollection* collectionDecl;
  store::Item_t                    collectionName;
  store::Item_t                    node;
  store::Item_t                    copyNode;
  std::vector<store::Item_t>       nodes;
  std::auto_ptr<store::PUL>        pul;

  store::CopyMode lCopyMode;
  bool typePreserve;
  bool nsPreserve;
  bool nsInherit;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  typePreserve = (theSctx->construction_mode() == StaticContextConsts::cons_preserve ?
                  true : false);
  nsPreserve = (theSctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                true : false);
  nsInherit = (theSctx->inherit_mode() == StaticContextConsts::inherit_ns ?
               true : false);

  lCopyMode.set(true, typePreserve, nsPreserve, nsInherit);

  consumeNext(collectionName, theChildren[0].getp(), planState);

  collectionDecl = getCollectionDecl(theSctx, collectionName, loc);

  collection = getCollection(theSctx, collectionName, loc);

  // checking collection update mode
  switch(collectionDecl->getUpdateProperty())
  {
  case StaticContextConsts::decl_const:
    ZORBA_ERROR_LOC_PARAM(XDDY0004_COLLECTION_CONST_UPDATE, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_append_only:
    ZORBA_ERROR_LOC_PARAM(XDDY0005_COLLECTION_APPEND_BAD_INSERT, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_queue:
    ZORBA_ERROR_LOC_PARAM(XDDY0006_COLLECTION_QUEUE_BAD_INSERT, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_mutable:
    // good to go
    break;

  default:
    ZORBA_ASSERT(false);
  }

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState))
  {
    checkNodeType(theSctx, node, collectionDecl, loc);
    copyNode = node->copy(NULL, 0, lCopyMode);
    nodes.push_back(copyNode);
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  if (nodes.size() > 0)
    pul->addInsertIntoCollection(collectionName, nodes);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END(state);
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
  store::Collection_t              collection;
  const StaticallyKnownCollection* collectionDecl;
  store::Item_t                    collectionName;
  store::Item_t                    node;
  store::Item_t                    copyNode;
  std::vector<store::Item_t>       nodes;
  std::auto_ptr<store::PUL>        pul;

  store::CopyMode lCopyMode;
  bool typePreserve;
  bool nsPreserve;
  bool nsInherit;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  typePreserve = (theSctx->construction_mode() == StaticContextConsts::cons_preserve ?
                  true : false);
  nsPreserve = (theSctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                true : false);
  nsInherit = (theSctx->inherit_mode() == StaticContextConsts::inherit_ns ?
               true : false);

  lCopyMode.set(true, typePreserve, nsPreserve, nsInherit);

  consumeNext(collectionName, theChildren[0].getp(), planState);

  collectionDecl = getCollectionDecl(theSctx, collectionName, loc);

  collection = getCollection(theSctx, collectionName, loc);

  // checking collection modifiers
  switch(collectionDecl->getUpdateProperty())
  {
  case StaticContextConsts::decl_const:
    ZORBA_ERROR_LOC_PARAM(XDDY0004_COLLECTION_CONST_UPDATE, loc, 
                          collectionName->getStringValue(), "");
    break;

  case StaticContextConsts::decl_append_only:
    ZORBA_ERROR_LOC_PARAM(XDDY0005_COLLECTION_APPEND_BAD_INSERT, loc, 
                          collectionName->getStringValue(), "");
    break;

  case StaticContextConsts::decl_queue:
    ZORBA_ERROR_LOC_PARAM(XDDY0006_COLLECTION_QUEUE_BAD_INSERT, loc, 
                          collectionName->getStringValue(), "");
    break;

  case StaticContextConsts::decl_mutable:
    // good to go
    break;

  default:
    ZORBA_ASSERT(false);
  }

  if (collectionDecl->getOrderProperty() == StaticContextConsts::decl_unordered)
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0012_COLLECTION_UNORDERED_BAD_INSERT, loc,
                          collectionName->getStringValue(), "");
  }

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState))
  {
    checkNodeType(theSctx, node, collectionDecl, loc);
    copyNode = node->copy(NULL, 0, lCopyMode);
    nodes.push_back(copyNode);
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addInsertFirstIntoCollection(collectionName, nodes);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END(state);
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
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the node is already in the collection, an error is raised
    (API0031_NODE_ALREADY_IN_COLLECTION) 
********************************************************************************/
bool ZorbaInsertNodesLastIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Collection_t              collection;
  const StaticallyKnownCollection* collectionDecl;
  store::Item_t                    collectionName;
  store::Item_t                    node;
  store::Item_t                    copyNode;
  std::vector<store::Item_t>       nodes;
  std::auto_ptr<store::PUL>        pul;

  store::CopyMode lCopyMode;
  bool typePreserve;
  bool nsPreserve;
  bool nsInherit;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  typePreserve = (theSctx->construction_mode() == StaticContextConsts::cons_preserve ?
                  true : false);
  nsPreserve = (theSctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                true : false);
  nsInherit = (theSctx->inherit_mode() == StaticContextConsts::inherit_ns ?
               true : false);

  lCopyMode.set(true, typePreserve, nsPreserve, nsInherit);

  consumeNext(collectionName, theChildren[0].getp(), planState);

  collectionDecl = getCollectionDecl(theSctx, collectionName, loc);

  collection = getCollection(theSctx, collectionName, loc);

  // checking collection modifiers
  switch(collectionDecl->getUpdateProperty()) 
  {
  case StaticContextConsts::decl_const:
    ZORBA_ERROR_LOC_PARAM(XDDY0004_COLLECTION_CONST_UPDATE, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

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
    ZORBA_ERROR_LOC_PARAM(XDDY0012_COLLECTION_UNORDERED_BAD_INSERT, loc,
                          collectionName->getStringValue(), "");
  }

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState))
  {
    checkNodeType(theSctx, node, collectionDecl, loc);
    copyNode = node->copy(NULL, 0, lCopyMode);
    nodes.push_back(copyNode);
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addInsertLastIntoCollection(collectionName, nodes);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
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
  store::Collection_t              collection;
  const StaticallyKnownCollection* collectionDecl;
  store::Item_t                    collectionName;
  store::Item_t                    targetNode;
  store::Item_t                    node;
  store::Item_t                    copyNode;
  std::vector<store::Item_t>       nodes;
  std::auto_ptr<store::PUL>        pul;
  ulong                            targetPos;

  store::CopyMode lCopyMode;
  bool typePreserve;
  bool nsPreserve;
  bool nsInherit;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  typePreserve = (theSctx->construction_mode() == StaticContextConsts::cons_preserve ?
                  true : false);
  nsPreserve = (theSctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                true : false);
  nsInherit = (theSctx->inherit_mode() == StaticContextConsts::inherit_ns ?
               true : false);

  lCopyMode.set(true, typePreserve, nsPreserve, nsInherit);

  consumeNext(collectionName, theChildren[0].getp(), planState);

  collectionDecl = getCollectionDecl(theSctx, collectionName, loc);

  collection = getCollection(theSctx, collectionName, loc);

  // checking collection modifiers
  switch(collectionDecl->getUpdateProperty()) 
  {
  case StaticContextConsts::decl_const:
    ZORBA_ERROR_LOC_PARAM(XDDY0004_COLLECTION_CONST_UPDATE, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_append_only:
    ZORBA_ERROR_LOC_PARAM(XDDY0005_COLLECTION_APPEND_BAD_INSERT, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_queue:
    ZORBA_ERROR_LOC_PARAM(XDDY0006_COLLECTION_QUEUE_BAD_INSERT, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_mutable:
    // good to go
    break;

  default:
    ZORBA_ASSERT(false);
  }

  if (collectionDecl->getOrderProperty() == StaticContextConsts::decl_unordered)
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0012_COLLECTION_UNORDERED_BAD_INSERT, loc,
                          collectionName->getStringValue(), "");
  }

  if(!consumeNext(targetNode, theChildren[theChildren.size()-2].getp(), planState)) 
  {
    ZORBA_ASSERT(false);
  }

  if (!collection->findNode(targetNode.getp(), targetPos)) 
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0011_COLLECTION_NODE_NOT_FOUND, loc,
                          collectionName->getStringValue(), "");
  }

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState))
  {
    checkNodeType(theSctx, node, collectionDecl, loc);

    copyNode = node->copy(NULL, 0, lCopyMode);
    nodes.push_back(copyNode);
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addInsertBeforeIntoCollection(collectionName, targetNode, nodes);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-2]->reset(planState);
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END(state);
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
  store::Collection_t              collection;
  const StaticallyKnownCollection* collectionDecl;
  store::Item_t                    collectionName;
  store::Item_t                    targetNode;
  store::Item_t                    node;
  store::Item_t                    copyNode;
  std::vector<store::Item_t>       nodes;
  std::auto_ptr<store::PUL>        pul;
  ulong                            targetPos;

  store::CopyMode lCopyMode;
  bool typePreserve;
  bool nsPreserve;
  bool nsInherit;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  typePreserve = (theSctx->construction_mode() == StaticContextConsts::cons_preserve ?
                  true : false);
  nsPreserve = (theSctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                true : false);
  nsInherit = (theSctx->inherit_mode() == StaticContextConsts::inherit_ns ?
               true : false);

  lCopyMode.set(true, typePreserve, nsPreserve, nsInherit);

  consumeNext(collectionName, theChildren[0].getp(), planState);

  collectionDecl = getCollectionDecl(theSctx, collectionName, loc);

  collection = getCollection(theSctx, collectionName, loc);

  // checking collection modifiers
  switch(collectionDecl->getUpdateProperty())
  {
  case StaticContextConsts::decl_const:
    ZORBA_ERROR_LOC_PARAM(XDDY0004_COLLECTION_CONST_UPDATE, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_append_only:
    ZORBA_ERROR_LOC_PARAM(XDDY0005_COLLECTION_APPEND_BAD_INSERT, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_queue:
    ZORBA_ERROR_LOC_PARAM(XDDY0006_COLLECTION_QUEUE_BAD_INSERT, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_mutable:
    // good to go
    break;

  default:
    ZORBA_ASSERT(false);
  }

  if (collectionDecl->getOrderProperty() == StaticContextConsts::decl_unordered)
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0012_COLLECTION_UNORDERED_BAD_INSERT, loc,
                          collectionName->getStringValue(), "");
  }

  if(!consumeNext(targetNode, theChildren[theChildren.size()-2].getp(), planState)) 
  {
    ZORBA_ASSERT(false);
  }

  if (!collection->findNode(targetNode.getp(), targetPos)) 
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0011_COLLECTION_NODE_NOT_FOUND, loc, 
                          collectionName->getStringValue(), "");
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState))
  {
    checkNodeType(theSctx, node, collectionDecl, loc);

    copyNode = node->copy(NULL, 0, lCopyMode);
    nodes.push_back(copyNode);
  }

  pul->addInsertAfterIntoCollection(collectionName, targetNode, nodes);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-2]->reset(planState);
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

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

  consumeNext(collectionName, theChildren[0].getp(), planState);

  collectionDecl = getCollectionDecl(theSctx, collectionName, loc);

  collection = getCollection(theSctx, collectionName, loc);

  // checking collection modifiers
  switch(collectionDecl->getUpdateProperty()) 
  {
  case StaticContextConsts::decl_const:
    ZORBA_ERROR_LOC_PARAM(XDDY0004_COLLECTION_CONST_UPDATE, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_append_only:
    ZORBA_ERROR_LOC_PARAM(XDDY0007_COLLECTION_APPEND_BAD_DELETE, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_queue:
    ZORBA_ERROR_LOC_PARAM(XDDY0009_COLLECTION_QUEUE_BAD_DELETE, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_mutable:
    // good to go
    break;

  default:
    ZORBA_ASSERT(false);
  }

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState)) 
  {
    ulong pos;
    if (!collection->findNode(node.getp(), pos))
      ZORBA_ERROR_LOC_PARAM(XDDY0011_COLLECTION_NODE_NOT_FOUND, loc, 
                            collectionName->getStringValue(), "");

    nodes.push_back(node);
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addDeleteFromCollection(collectionName, nodes, false);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END(state);
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
  ulong                            collectionSize;
  store::Item_t                    numNodesItem;
  ulong                            numNodes = 1;
  std::vector<store::Item_t>       nodes;
  std::auto_ptr<store::PUL>        pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(collectionName, theChildren[0].getp(), planState))
    ZORBA_ASSERT(false);

  if (theChildren.size() > 1)
  {
    if (!consumeNext(numNodesItem, theChildren[1].getp(), planState))
      ZORBA_ASSERT(false);

    numNodes = numNodesItem->getUnsignedLongValue();
  }

  collectionDecl = getCollectionDecl(theSctx, collectionName, loc);

  collection = getCollection(theSctx, collectionName, loc);

  collectionSize = collection->size();

  // checking collection modifiers
  switch(collectionDecl->getUpdateProperty()) 
  {
  case StaticContextConsts::decl_const:
    ZORBA_ERROR_LOC_PARAM(XDDY0004_COLLECTION_CONST_UPDATE, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_append_only:
    ZORBA_ERROR_LOC_PARAM(XDDY0007_COLLECTION_APPEND_BAD_DELETE, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_queue:
  case StaticContextConsts::decl_mutable:
    // good to go
    break;

  default:
    ZORBA_ASSERT(false);
  }

  if (collectionSize < numNodes)
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0011_COLLECTION_NODE_NOT_FOUND, loc,
                          collectionName->getStringValue()->c_str(), "");
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  for (ulong i = 0; i < numNodes; ++i)
    nodes.push_back(collection->nodeAt(i));

  pul->addDeleteFromCollection(collectionName, nodes, false);

  result = pul.release();
  STACK_PUSH(result != NULL, state);

  STACK_END(state);
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
  ulong                            collectionSize;
  store::Item_t                    numNodesItem;
  ulong                            numNodes = 1;
  std::vector<store::Item_t>       nodes;
  std::auto_ptr<store::PUL>        pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(collectionName, theChildren[0].getp(), planState);

  if (theChildren.size() > 1)
  {
    if (!consumeNext(numNodesItem, theChildren[1].getp(), planState))
      ZORBA_ASSERT(false);

    numNodes = numNodesItem->getUnsignedLongValue();
  }

  collectionDecl = getCollectionDecl(theSctx, collectionName, loc);

  collection = getCollection(theSctx, collectionName, loc);

  collectionSize = collection->size();

  // checking collection modifiers
  switch(collectionDecl->getUpdateProperty()) 
  {
  case StaticContextConsts::decl_const:
    ZORBA_ERROR_LOC_PARAM(XDDY0004_COLLECTION_CONST_UPDATE, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_append_only:
    ZORBA_ERROR_LOC_PARAM(XDDY0007_COLLECTION_APPEND_BAD_DELETE, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_queue:
    ZORBA_ERROR_LOC_PARAM(XDDY0008_COLLECTION_QUEUE_BAD_DELETE, loc, 
                          collectionName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_mutable:
    // good to go
    break;

  default:
    ZORBA_ASSERT(false);
  }

  if (collectionSize < numNodes) 
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0011_COLLECTION_NODE_NOT_FOUND, loc,
                          collectionName->getStringValue()->c_str(), "");
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  for (ulong i = numNodes; i > 0; --i)
    nodes.push_back(collection->nodeAt(collectionSize - i));

  pul->addDeleteFromCollection(collectionName, nodes, true);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
  Check that a collection with the given name appears in the store. If so,
  return the collection container. Otherwise, raise an error.
********************************************************************************/
store::Collection_t getCollection(
    const static_context* aSctx,
    const store::Item_t aName,
    const QueryLoc& aLoc)
{
  store::Collection_t lCollection = GENV_STORE.getCollection(aName);
  if (lCollection == NULL) 
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0003_COLLECTION_DOES_NOT_EXIST, aLoc, 
                          aName->getStringValue(), "");
  }

  return lCollection;
}


/*******************************************************************************
  Check that a collection with the given name appears in the static context.
  If so, return the collection declaration. Otherwise, raise an error.
********************************************************************************/
const StaticallyKnownCollection* getCollectionDecl(
    const static_context* aSctx,
    const store::Item_t aName,
    const QueryLoc& aLoc)
{
  const StaticallyKnownCollection* collectionDecl = aSctx->lookup_collection(aName);
  if (collectionDecl == 0) 
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0001_COLLECTION_NOT_DECLARED, aLoc,
                          aName->getStringValue(), "");
  }
  return collectionDecl;
}


/*******************************************************************************
  Check that the type of a node to be inserted into a collection matches with 
  the statically declared type of the collection nodes. If not, raise an error.
********************************************************************************/
void checkNodeType(
    const static_context* sctx,
    const store::Item_t& node, 
    const StaticallyKnownCollection* collectionDecl,
    const QueryLoc& loc)
{
  const TypeManager* tm = sctx->get_typemanager();

  if (!TypeOps::is_treatable(node, *(collectionDecl->getNodeType()), tm)) 
  {
    ZORBA_ERROR_LOC_PARAM(XDTY0001_COLLECTION_INVALID_NODE_TYPE, loc, 
                          collectionDecl->getName()->getStringValue(),
                          TypeOps::toString(*tm->create_value_type(node)));
  }
}



} /* namespace zorba */
