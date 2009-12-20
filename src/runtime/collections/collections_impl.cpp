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
#include "runtime/collections/collections.h"

#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_messages.h"

#include "zorbatypes/URI.h"
#include "zorbatypes/numconversions.h"

#include "system/globalenv.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"
#include "context/internal_uri_resolvers.h"
#include "context/statically_known_collection.h"
#include "context/static_context_consts.h"

#include "runtime/api/runtimecb.h"

#include "store/api/pul.h"
#include "store/api/copymode.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"
#include "store/api/store.h"
#include "store/api/collection.h"

#include "types/typeops.h"

namespace zorba {

// Forward declarations
store::Collection_t getCollection(
    const static_context* aSctx,
    const store::Item_t,
    const QueryLoc&);

const StaticallyKnownCollection* getDeclColl(
    const static_context* aSctx,
    const store::Item_t aName,
    const QueryLoc& aLoc);

void checkNodeType(
    const store::Item_t& aNode, 
    const static_context* aSctx,
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


bool ZorbaCollectionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       lName;
  store::Collection_t coll;

  ZorbaCollectionIteratorState* state;
  DEFAULT_STACK_INIT(ZorbaCollectionIteratorState, state, planState);

  consumeNext(lName, theChildren[0].getp(), planState);

  coll = getCollection(theSctx, lName, loc);

  /** return the nodes of the collection */
  state->theIterator = coll->getIterator();
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
  declare function index-of($target as node()) as xs:integer

  declare function index-of($uri as xs:string?,
                            $target as node()) as xs:integer

  The function will return the index of the  $target node within the collection
  identified by $uri.

  Error condition:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the node does not belong to the given collection, an error is raised
    (API0029_NODE_DOES_NOT_BELONG_TO_COLLECTION - the node does not belong
    to the given collection).
********************************************************************************/
bool
ZorbaIndexOfIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       item;
  ulong               pos = 1;
  bool                found;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(item, theChildren[0].getp(), planState);
  theColl = getCollection(theSctx, item, loc);

  if (consumeNext(item, theChildren[theChildren.size()-1].getp(), planState))
  {
    found = theColl->findNode(item, pos);

    if (!found)
      ZORBA_ERROR_LOC_DESC(API0029_NODE_DOES_NOT_BELONG_TO_COLLECTION,
                           loc,
                           "The node does not belong to collection.");

    STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, Integer::parseInt(pos)),
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
  store::Item_t             lName;

  store::Item_t             node;
  store::Item_t             copyNode;
  store::Collection_t       coll;
  std::auto_ptr<store::PUL> pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);

  // check a collection is in the set of statically known collection with this name
  if ( theSctx->lookup_collection(lName.getp()) == 0 ) 
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0001_COLLECTION_NOT_DECLARED, loc,
                          lName->getStringValue(), "");
  }

  // check if the collection already exists
  try
  {
    coll = getCollection(theSctx, lName, loc);
  }
  catch (error::ZorbaError& e)
  {
    if (e.theErrorCode != XDDY0003_COLLECTION_DOES_NOT_EXIST)
    {
      throw;
    }
    // we come here if the collection is not available (but is declared)
  }

  if (coll != NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0002_COLLECTION_EXISTS_ALREADY, loc,
                          lName->getStringValue(), "");
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addCreateCollection(lName);

  // also add some optional nodes to the collection
  if(theChildren.size() == 2) 
  {
    store::CopyMode lCopyMode;
    bool typePreserve;
    bool nsPreserve;
    bool nsInherit;
    
    typePreserve = (theSctx->construction_mode() == StaticContextConsts::cons_preserve ?
                    true : false);
    nsPreserve = (theSctx->preserve_mode() == StaticContextConsts::preserve_ns ?
                  true : false);
    nsInherit = (theSctx->inherit_mode() == StaticContextConsts::inherit_ns ?
                 true : false);

    lCopyMode.set(true, typePreserve, nsPreserve, nsInherit);

    const StaticallyKnownCollection* lDeclColl = getDeclColl(theSctx, lName, loc);;

    while (consumeNext(node, theChildren[1].getp(), aPlanState))
    {
      checkNodeType(node, theSctx, lDeclColl, loc);
      copyNode = node->copy(NULL, 0, lCopyMode);
      pul->addInsertIntoCollection(lName, copyNode);
    }
  }

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
  declare updating function delete-collection($name as xs:QName) as none

  The function will delete the collection identified by the given URI.

  Error conditions:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
  - If the collection does not exist, an error is raised.
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
********************************************************************************/
bool
ZorbaDeleteCollectionIterator::nextImpl(store::Item_t& result, PlanState& aPlanState) const
{
  PlanIteratorState         *state;
  store::Item_t             item;
  store::Collection_t       coll;
  std::auto_ptr<store::PUL> pul;

  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(item, theChildren[0].getp(), aPlanState);

  coll = getCollection(theSctx, item, loc);

  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addDeleteCollection(item);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}

/*******************************************************************************
  declare updating function
  insert-nodes($name as xs:QName, $newnode as node()*) as none

  The function will insert the given node(s) to the given collection.
********************************************************************************/
bool
ZorbaInsertNodesIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t              coll;
  const StaticallyKnownCollection* lDeclColl;
  store::Item_t                    lName;
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

  consumeNext(lName, theChildren[0].getp(), planState);

  lDeclColl = getDeclColl(theSctx, lName, loc);
  coll = getCollection(theSctx, lName, loc);

  // checking collection modifiers
  switch(lDeclColl->getUpdateProperty())
  {
  case StaticContextConsts::decl_const:
    ZORBA_ERROR_LOC_PARAM(XDDY0004_COLLECTION_CONST_UPDATE, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_append_only:
    ZORBA_ERROR_LOC_PARAM(XDDY0005_COLLECTION_APPEND_BAD_INSERT, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_queue:
    ZORBA_ERROR_LOC_PARAM(XDDY0006_COLLECTION_QUEUE_BAD_INSERT, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_mutable:
    // good to go
    break;

  default:
    ZORBA_ASSERT(false);
  }

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState))
  {
    checkNodeType(node, theSctx, lDeclColl, loc);
    copyNode = node->copy(NULL, 0, lCopyMode);
    nodes.push_back(copyNode);
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addInsertLastIntoCollection(lName, nodes);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}

/*******************************************************************************
  declare updating function
  insert-nodes-first($name as xs:QName, $newnode as node()*) as none

  The function will insert the given node(s) as the first node(s) of the given
  collection. If multiple nodes are inserted, the nodes remain adjacent and
  their order preserves the node ordering of the source expression.

  Error conditions:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
********************************************************************************/
bool
ZorbaInsertNodesFirstIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t              coll;
  const StaticallyKnownCollection* lDeclColl;
  store::Item_t                    lName;
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

  consumeNext(lName, theChildren[0].getp(), planState);

  lDeclColl = getDeclColl(theSctx, lName, loc);
  coll = getCollection(theSctx, lName, loc);

  // checking collection modifiers
  switch(lDeclColl->getUpdateProperty())
  {
  case StaticContextConsts::decl_const:
    ZORBA_ERROR_LOC_PARAM(XDDY0004_COLLECTION_CONST_UPDATE, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_append_only:
    ZORBA_ERROR_LOC_PARAM(XDDY0005_COLLECTION_APPEND_BAD_INSERT, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_queue:
    ZORBA_ERROR_LOC_PARAM(XDDY0006_COLLECTION_QUEUE_BAD_INSERT, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_mutable:
    // good to go
    break;

  default:
    ZORBA_ASSERT(false);
  }

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState))
  {
    checkNodeType(node, theSctx, lDeclColl, loc);
    copyNode = node->copy(NULL, 0, lCopyMode);
    nodes.push_back(copyNode);
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addInsertFirstIntoCollection(lName, nodes);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
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
bool
ZorbaInsertNodesLastIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t              coll;
  const StaticallyKnownCollection* lDeclColl;
  store::Item_t                    lName;
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

  consumeNext(lName, theChildren[0].getp(), planState);

  lDeclColl = getDeclColl(theSctx, lName, loc);
  coll = getCollection(theSctx, lName, loc);

  // checking collection modifiers
  switch(lDeclColl->getUpdateProperty()) 
  {
  case StaticContextConsts::decl_const:
    ZORBA_ERROR_LOC_PARAM(XDDY0004_COLLECTION_CONST_UPDATE, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_append_only:
  case StaticContextConsts::decl_queue:
  case StaticContextConsts::decl_mutable:
    // good to go
    break;

  default:
    ZORBA_ASSERT(false);
  }

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState))
  {
    checkNodeType(node, theSctx, lDeclColl, loc);
    copyNode = node->copy(NULL, 0, lCopyMode);
    nodes.push_back(copyNode);
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addInsertLastIntoCollection(lName, nodes);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
  declare updating function
  insert-nodes-before($name as xs:QName,
                      $target   as node()+,
                      $newnode  as node()*) as none


  The inserted nodes become the preceding (or following) nodes of the target.
  The $target should be a non-updating expression (e.g. an XPath expression)
  identifying a node that is part of the given collection at the top-level.
  If the expression returns more than one node, the first one is used. If 
  multiple nodes are inserted by a single insert expression, the nodes remain
  adjacent and their order preserves the node ordering of the source expression.

  Error conditions:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the target node is not part of the collection, an error is raised
    (API0029_NODE_DOES_NOT_BELONG_TO_COLLECTION - the node does not belong
    to the given collection).
  - If any of the new nodes is already part of the collection an error is
    raised (API0031_NODE_ALREADY_IN_COLLECTION).
********************************************************************************/
bool
ZorbaInsertNodesBeforeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t              coll;
  const StaticallyKnownCollection* lDeclColl;
  store::Item_t                    lName;
  store::Item_t                    targetNode, tmpItem;
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

  consumeNext(lName, theChildren[0].getp(), planState);

  lDeclColl = getDeclColl(theSctx, lName, loc);
  coll = getCollection(theSctx, lName, loc);

  // checking collection modifiers
  switch(lDeclColl->getUpdateProperty()) 
  {
  case StaticContextConsts::decl_const:
    ZORBA_ERROR_LOC_PARAM(XDDY0004_COLLECTION_CONST_UPDATE, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_append_only:
    ZORBA_ERROR_LOC_PARAM(XDDY0005_COLLECTION_APPEND_BAD_INSERT, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_queue:
    ZORBA_ERROR_LOC_PARAM(XDDY0006_COLLECTION_QUEUE_BAD_INSERT, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_mutable:
    // good to go
    break;

  default:
    ZORBA_ASSERT(false);
  }

  if(!consumeNext(targetNode, theChildren[theChildren.size()-2].getp(), planState)) 
  {
    ZORBA_ERROR_LOC_DESC(XQP0000_DYNAMIC_RUNTIME_ERROR, loc,
                         "The empty-sequence is not allowed as second argument to insert-nodes-before");
  }

  if(consumeNext(tmpItem, theChildren[theChildren.size()-2].getp(), planState)) 
  {
    ZORBA_ERROR_LOC_DESC(XQP0000_DYNAMIC_RUNTIME_ERROR, loc,
                         "A sequence with more then one item is not allowed as second argument to insert-nodes-before");
  }

  ulong targetPos;

  if (!coll->findNode(targetNode.getp(), targetPos)) 
  {
    ZORBA_ERROR_LOC_DESC_OSS(XQP0000_DYNAMIC_RUNTIME_ERROR, loc,
                         "The target node passed as second parameter to insert-nodes-before does not exist in the given collection "
                         << lName->getStringValue());
  }

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState))
  {
    checkNodeType(node, theSctx, lDeclColl, loc);
    copyNode = node->copy(NULL, 0, lCopyMode);
    nodes.push_back(copyNode);
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addInsertBeforeIntoCollection(lName,
                                     targetNode,
                                     nodes);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-2]->reset(planState);
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
  declare updating function insert-nodes-after( $name      as xs:QName,
                                                $target   as node()+,
                                                $newnode  as node()*) as none

  The inserted nodes become the following nodes of the $target.
  The $target should be a non-updating expression (e.g. an XPath expression)
  identifying a node that is part of the given collection at the top-level.
  If the expression returns more than one node, the first one is used.
  A predicate can be used to select a different node in this case.
  If multiple nodes are inserted by a single insert expression,
  the nodes remain adjacent and their order preserves the node ordering of
  the source expression.

Error conditions:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
********************************************************************************/
bool
ZorbaInsertNodesAfterIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t              coll;
  const StaticallyKnownCollection* lDeclColl;
  store::Item_t                    lName;
  store::Item_t                    targetNode;
  store::Item_t                    tmpItem;
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

  consumeNext(lName, theChildren[0].getp(), planState);

  lDeclColl = getDeclColl(theSctx, lName, loc);
  coll = getCollection(theSctx, lName, loc);

  // checking collection modifiers
  switch(lDeclColl->getUpdateProperty())
  {
  case StaticContextConsts::decl_const:
    ZORBA_ERROR_LOC_PARAM(XDDY0004_COLLECTION_CONST_UPDATE, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_append_only:
    ZORBA_ERROR_LOC_PARAM(XDDY0005_COLLECTION_APPEND_BAD_INSERT, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_queue:
    ZORBA_ERROR_LOC_PARAM(XDDY0006_COLLECTION_QUEUE_BAD_INSERT, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_mutable:
    // good to go
    break;

  default:
    ZORBA_ASSERT(false);
  }

  if(!consumeNext(targetNode, theChildren[theChildren.size()-2].getp(), planState)) 
  {
    ZORBA_ERROR_LOC_DESC(XQP0000_DYNAMIC_RUNTIME_ERROR, loc, 
                         "The empty-sequence is not allowed as second argument to insert-nodes-after");
  }

  if(consumeNext(tmpItem, theChildren[theChildren.size()-2].getp(), planState)) 
  {
    ZORBA_ERROR_LOC_DESC(XQP0000_DYNAMIC_RUNTIME_ERROR, loc, 
                         "A sequence with more then one item is not allowed as second argument to insert-nodes-after");
  }

  ulong targetPos;

  if (!coll->findNode(targetNode.getp(), targetPos)) 
  {
    ZORBA_ERROR_LOC_DESC_OSS(XQP0000_DYNAMIC_RUNTIME_ERROR, loc, 
                         "The target node passed as second parameter to insert-nodes-before does not exist in the given collection "
                         << lName->getStringValue());
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState))
  {
    checkNodeType(node, theSctx, lDeclColl, loc);
    copyNode = node->copy(NULL, 0, lCopyMode);
    nodes.push_back(copyNode);
  }

  pul->addInsertAfterIntoCollection(lName, targetNode, nodes);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-2]->reset(planState);
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************
  declare updating function delete-nodes($name     as xs:QName,
                                         $target  as node()+) as none

  The function will remove the node(s) identified by the $target expression
  from the given collection. The nodes themselves will not be deleted and
  they may remain as parts of other collections. If the expression identifies
  more than one node, all of them will be removed from the collection. 

  Error conditions:
  - If the collection URI is empty and the default collection
    is not defined in the dynamic context, FODC0002 is raised
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the given expression points to a node that is not part of the collection,
    an error is raised (API0029_NODE_DOES_NOT_BELONG_TO_COLLECTION - the node
    does not belong to the given collection). 
********************************************************************************/
bool
ZorbaDeleteNodesIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t              coll;
  const StaticallyKnownCollection* lDeclColl;
  store::Item_t                    lName;
  store::Item_t                    node;
  std::vector<store::Item_t>       nodes;
  std::auto_ptr<store::PUL>        pul;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lName, theChildren[0].getp(), planState);

  lDeclColl = getDeclColl(theSctx, lName, loc);
  coll = getCollection(theSctx, lName, loc);

  while (consumeNext(node, theChildren[theChildren.size()-1].getp(), planState)) 
  {
    ulong pos;
    if (!coll->findNode(node.getp(), pos))
      ZORBA_ERROR_LOC_DESC_OSS(API0029_NODE_DOES_NOT_BELONG_TO_COLLECTION, loc, 
                               "The node passed as second parameter to remove-nodes "
                               << "does not exist in the given collection "
                               << lName->getStringValue());

    nodes.push_back(node);
  }

  // checking collection modifiers
  switch(lDeclColl->getUpdateProperty()) 
  {
  case StaticContextConsts::decl_const:
    ZORBA_ERROR_LOC_PARAM(XDDY0004_COLLECTION_CONST_UPDATE, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_append_only:
    ZORBA_ERROR_LOC_PARAM(XDDY0007_COLLECTION_APPEND_BAD_DELETE, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_queue:
    // checks if the deleted items are a prefix of the collection
    for (size_t i = 0; i < nodes.size(); ++i) 
    {
      store::Item* lCurToDelete = nodes[i].getp();
      store::Item* lNodeAtPos = coll->nodeAt(i+1).getp();
      if (lCurToDelete != lNodeAtPos)
        ZORBA_ERROR_LOC_PARAM(XDDY0009_COLLECTION_QUEUE_BAD_DELETE, loc, 
                              lName->getStringValue()->c_str(), "");
    }
    break;

  case StaticContextConsts::decl_mutable:
    // good to go
    break;

  default:
    ZORBA_ASSERT(false);
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  pul->addDeleteFromCollection(lName, nodes);

  // this should not be necessary. we reset everything in the sequential iterator
  theChildren[theChildren.size()-1]->reset(planState);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool
ZorbaDeleteNodeFirstIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t              coll;
  const StaticallyKnownCollection* lDeclColl;
  store::Item_t                    lName;
  std::vector<store::Item_t>       lNodes;
  std::auto_ptr<store::PUL>        pul;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lName, theChildren[0].getp(), planState);

  lDeclColl = getDeclColl(theSctx, lName, loc);
  coll = getCollection(theSctx, lName, loc);

  // checking collection modifiers
  switch(lDeclColl->getUpdateProperty()) 
  {
  case StaticContextConsts::decl_const:
    ZORBA_ERROR_LOC_PARAM(XDDY0004_COLLECTION_CONST_UPDATE, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_append_only:
    ZORBA_ERROR_LOC_PARAM(XDDY0007_COLLECTION_APPEND_BAD_DELETE, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_queue:
  case StaticContextConsts::decl_mutable:
    // good to go
    break;

  default:
    ZORBA_ASSERT(false);
  }

  if (coll->size() == 0) 
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0011_COLLECTION_NODE_NOT_FOUND, loc,
                          lName->getStringValue()->c_str(), "");
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  lNodes.push_back(coll->nodeAt(1));
  pul->addDeleteFromCollection(lName, lNodes);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool
ZorbaDeleteNodeLastIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t              coll;
  const StaticallyKnownCollection* lDeclColl;
  store::Item_t                    lName;
  std::vector<store::Item_t>       lNodes;
  std::auto_ptr<store::PUL>        pul;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lName, theChildren[0].getp(), planState);

  lDeclColl = getDeclColl(theSctx, lName, loc);
  coll = getCollection(theSctx, lName, loc);

  // checking collection modifiers
  switch(lDeclColl->getUpdateProperty()) 
  {
  case StaticContextConsts::decl_const:
    ZORBA_ERROR_LOC_PARAM(XDDY0004_COLLECTION_CONST_UPDATE, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_append_only:
    ZORBA_ERROR_LOC_PARAM(XDDY0007_COLLECTION_APPEND_BAD_DELETE, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_queue:
    ZORBA_ERROR_LOC_PARAM(XDDY0008_COLLECTION_QUEUE_BAD_DELETE, loc, 
                          lName->getStringValue()->c_str(), "");
    break;

  case StaticContextConsts::decl_mutable:
    // good to go
    break;

  default:
    ZORBA_ASSERT(false);
  }

  if (coll->size() == 0) 
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0011_COLLECTION_NODE_NOT_FOUND, loc,
                          lName->getStringValue()->c_str(), "");
  }

  // create the pul and add the primitive
  pul.reset(GENV_ITEMFACTORY->createPendingUpdateList());

  lNodes.push_back(coll->nodeAt(coll->size()));
  pul->addDeleteFromCollection(lName, lNodes);

  result = pul.release();
  STACK_PUSH( result != NULL, state);

  STACK_END (state);
}


store::Collection_t getCollection(
    const static_context* aSctx,
    const store::Item_t aName,
    const QueryLoc& aLoc)
{
  if (aSctx->lookup_collection(aName.getp()) == 0) 
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0001_COLLECTION_NOT_DECLARED, aLoc,
                          aName->getStringValue(), "");
  }

  store::Collection_t lCollection = GENV_STORE.getCollection(aName);
  if (lCollection == NULL) 
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0003_COLLECTION_DOES_NOT_EXIST, aLoc, 
                          aName->getStringValue(), "");
  }

  return lCollection;
}


const StaticallyKnownCollection* getDeclColl(
    const static_context* aSctx,
    const store::Item_t aName,
    const QueryLoc& aLoc)
{
  const StaticallyKnownCollection* lDeclColl = aSctx->lookup_collection(aName);
  if (lDeclColl == 0) 
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0001_COLLECTION_NOT_DECLARED, aLoc,
                          aName->getStringValue(), "");
  }
  return lDeclColl;
}


void checkNodeType(
    const store::Item_t& aNode, 
    const static_context* aSctx,
    const StaticallyKnownCollection* aColl,
    const QueryLoc& aLoc)
{
  const TypeManager* lTypeManager = aSctx->get_typemanager();
  if (!TypeOps::is_treatable(aNode, *(aColl->getNodeType()), lTypeManager)) 
  {
    ZORBA_ERROR_LOC_DESC_OSS(XPTY0004, aLoc, 
      "Cannot treat "
      << TypeOps::toString(*lTypeManager->create_value_type(aNode))
      << " as " << TypeOps::toString(*(aColl->getNodeType())));
  }
}



} /* namespace zorba */
