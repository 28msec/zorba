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

#include "zorbatypes/zorbatypesError.h"
#include "zorbatypes/URI.h"
#include "zorbatypes/numconversions.h"

#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/collection.h"

#include "api/collectionimpl.h"

#include "system/globalenv.h"

#include "context/static_context.h"
#include "context/internal_uri_resolvers.h"

#include "CollectionsImpl.h"

#include "api/serialization/serializer.h"

#include <fstream>

namespace zorba {

bool
ZorbaImportXmlIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       itemURI, itemXML, resolvedURIItem;
  xqpStringStore_t    strURI, resolvedURIString;
  store::Collection_t theColl;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemURI, theChildren[0].getp(), planState))
  {
    theColl = getCollection(planState, itemURI->getStringValue(), loc);

    try {
      resolvedURIString = planState.sctx()->resolve_relative_uri(itemURI->getStringValueP()).getStore();
      itemXML = GENV_STORE.getDocument(resolvedURIString);
    } catch (error::ZorbaError& e) {
      ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
    }
    if (itemXML == NULL) {
      try {
        GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
      } catch (error::ZorbaError& e) {
        ZORBA_ERROR_LOC_DESC(FODC0005, loc, e.theDescription);
      }
      try {
        itemXML = planState.sctx()->get_document_uri_resolver()->resolve(resolvedURIItem, planState.sctx());
      } catch (error::ZorbaError& e) {
        ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
      }
    }

    strURI = itemURI->getStringValue();
    theColl = GENV_STORE.createCollection(strURI);
    theColl->addToCollection(itemXML, 0);
  }

  STACK_END (state);
}

bool
ZorbaImportCatalogIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       itemURI, resolvedURIItem, inNode, intt, inArg, attr, itemXML;
  xqp_string          attrName;
  xqpStringStore_t    uriString, resolvedURIString, fileString;
  store::Iterator_t   theIterator, theAttributes;;
  URI                 uriCatalog, uriFile;
  store::Collection_t theColl;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemURI, theChildren[0].getp(), planState))
    uriCatalog = URI(itemURI->getStringValue().getp());

  uriString = uriCatalog.toString().getStore();

  try {
    inNode = GENV_STORE.getDocument(itemURI->getStringValue());
  } catch (error::ZorbaError& e) {
    ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
  }
  if (inNode == NULL) {
    try {
      resolvedURIString = planState.sctx()->resolve_relative_uri(uriString.getp()).getStore();
      GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
    } catch (error::ZorbaError& e) {
      ZORBA_ERROR_LOC_DESC(FODC0005, loc, e.theDescription);
    }
    try {
      inNode = planState.sctx()->get_document_uri_resolver()->resolve(resolvedURIItem,
                              planState.sctx());
    } catch (error::ZorbaError& e) {
      ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
    }
  }

  if(inNode->getNodeKind() == store::StoreConsts::documentNode) {
    theIterator = inNode->getChildren();
    theIterator->open();
    theIterator->next(intt);
    theIterator = intt->getChildren();

    while(theIterator->next(inArg)) {
      if(inArg->getNodeKind() == store::StoreConsts::elementNode &&
         inArg->getNodeName()->getLocalName()->byteEqual("doc", 3)) {
        for ((theAttributes = inArg->getAttributes())->open (); theAttributes->next(attr); ) {
          attrName = attr->getNodeName()->getStringValue()->str();
          if(attr->getNodeName()->getLocalName()->byteEqual("href", 4)) {

            if(attr->getStringValue()->indexOf("/") == -1)
              uriFile = URI(uriCatalog, attr->getStringValue().getp());
            else
              uriFile = URI(attr->getStringValue().getp());

            fileString = uriFile.toString().getStore();

            try {
              itemXML = GENV_STORE.getDocument(fileString);
            } catch (error::ZorbaError& e) {
              ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
            }
            if (itemXML == NULL) {
              try {
                resolvedURIString = fileString;
                GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
              } catch (error::ZorbaError& e) {
                ZORBA_ERROR_LOC_DESC(FODC0005, loc, e.theDescription);
              }
              try {
                itemXML = planState.sctx()->get_document_uri_resolver()->resolve(resolvedURIItem, planState.sctx());
              } catch (error::ZorbaError& e) {
                ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
              }
            }

            xqpStringStore_t    collectionUri = uriFile.toString().getStore();
            theColl = GENV_STORE.createCollection(collectionUri);
            theColl->addToCollection(itemXML, 0);
          }
        }
      }
    }
    theIterator->close();
  }

  STACK_END (state);
}

bool
ZorbaImportFolderIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       itemURI;
  URI                 uri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemURI, theChildren[0].getp(), planState))
    uri = URI(itemURI->getStringValue().getp());

  if( uri.get_scheme() != xqpString("file") && !uri.get_scheme().empty())
    ZORBA_ERROR_LOC_DESC (FOER0000, loc, "ZorbaImportFolderIterator implemented only for 'file' scheme.");

  STACK_END (state);
}

void
ZorbaListCollectionsState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  uriItState = NULL;
}

void
ZorbaListCollectionsState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  uriItState = NULL;
}

bool
ZorbaListCollectionsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  ZorbaListCollectionsState * state;
  store::Item_t               uriItem;

  DEFAULT_STACK_INIT(ZorbaListCollectionsState, state, planState);

  for ((state->uriItState = GENV_STORE.listCollectionUris())->open ();
       state->uriItState->next(uriItem); ) {
    result = uriItem;
    STACK_PUSH( true, state);
  }

  STACK_END (state);
}

bool
ZorbaCreateCollectionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       item;
  xqpStringStore_t    resolvedURIString;
  store::Collection_t theColl;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    try {
      resolvedURIString = planState.sctx()->resolve_relative_uri(item->getStringValueP()).getStore();
    } catch (error::ZorbaError& e) {
      ZORBA_ERROR_LOC_DESC(FODC0005, loc, e.theDescription);
    }
    try {
      theColl = getCollection(planState, resolvedURIString, loc);
    } catch (error::ZorbaError& e) { }

    if(theColl != NULL)
      ZORBA_ERROR_LOC_DESC(API0005_COLLECTION_ALREADY_EXISTS, loc, "Collection already exists");
    else {

      theColl = GENV_STORE.createCollection(resolvedURIString);

      if(theChildren.size() == 2) {
        //add the nodes to the newly created collection
        while (consumeNext(item, theChildren[1].getp(), planState))
          theColl.getp()->addToCollection(item.getp(), -1);
      }
    }
  }

  STACK_END (state);
}

bool
ZorbaDeleteCollectionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState  *state;
  store::Item_t       item;
  store::Collection_t coll;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState )) {
    coll = getCollection(planState, item->getStringValue(), loc);

    GENV_STORE.deleteCollection(coll->getUri()->getStringValue());
  }

  STACK_END (state);
}

bool
ZorbaDeleteAllCollectionsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState                           *state;
  store::Iterator_t                           uriItState;
  store::Item_t                               itemUri;
  checked_vector<xqpStringStore_t>            vectorUri;
  checked_vector<xqpStringStore_t>::iterator  it, end;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  for ((uriItState = GENV_STORE.listCollectionUris())->open ();
        uriItState->next(itemUri); )
    vectorUri.push_back(itemUri->getStringValue());

  it = vectorUri.begin();
  end = vectorUri.end();

  for (; it != end; ++it)
  {
    GENV_STORE.deleteCollection(*it);
  }

  vectorUri.clear();

  STACK_END (state);
}

bool
ZorbaInsertNodeFirstIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       item;
  int                 pos = 0;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState)) {
    theColl = getCollection(planState, item->getStringValue(), loc);

    //add the nodes to the newly created collection
    while (consumeNext(item, theChildren[1].getp(), planState))
      theColl.getp()->addToCollection(item, pos++);
  }

  STACK_END (state);
}

bool
ZorbaInsertNodeLastIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       item;
  xqpStringStore_t    strURI;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState)) {
    theColl = getCollection(planState, item->getStringValue(), loc);

    //add the nodes to the newly created collection
    while (consumeNext(item, theChildren[1].getp(), planState))
      theColl.getp()->addToCollection(item, -1);
  }

  STACK_END (state);
}

bool
ZorbaInsertNodeBeforeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       itemUri, itemTarget, itemNewNode;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState)) {
    theColl = getCollection(planState, itemUri->getStringValue(), loc);

    if(consumeNext(itemTarget, theChildren[1].getp(), planState))
    {
      //add the nodes to the newly created collection
      while (consumeNext(itemNewNode, theChildren[2].getp(), planState))
        theColl.getp()->addNode(itemNewNode, itemTarget, true);
    }
  }

  STACK_END (state);
}

bool
ZorbaInsertNodeAfterIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       itemUri, itemTarget, itemNewNode;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState)) {
    theColl = getCollection(planState, itemUri->getStringValue(), loc);

    if(consumeNext(itemTarget, theChildren[1].getp(), planState))
    {
      //add the nodes to the newly created collection
      while (consumeNext(itemNewNode, theChildren[2].getp(), planState))
        theColl.getp()->addNode(itemNewNode, itemTarget, false);
    }
  }

  STACK_END (state);
}

bool
ZorbaInsertNodeAtIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       itemUri, itemPos, itemNode;
  int                 pos = 0;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState)) {
    theColl = getCollection(planState, itemUri->getStringValue(), loc);

    if(consumeNext(itemPos, theChildren[1].getp(), planState))
    {
      if(itemPos->getIntegerValue() < Integer::zero())
        pos = itemPos->getIntValue();

      //add the nodes to the newly created collection
      while (consumeNext(itemNode, theChildren[2].getp(), planState))
        theColl.getp()->addToCollection(itemNode, pos++);
    }
  }

  STACK_END (state);
}

bool
ZorbaRemoveNodeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t                     theColl;
  store::Item_t                           item;
  checked_vector<int>                     toBeRemoved;
  checked_vector<int>::reverse_iterator   it, end, begin;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState)) {
    theColl = getCollection(planState, item->getStringValue(), loc);

    //delete the nodes
    while (consumeNext(item, theChildren[1].getp(), planState))
      toBeRemoved.push_back(theColl->indexOf(item));

    begin = toBeRemoved.rbegin();
    end = toBeRemoved.rend();

    for (it = begin; it != end; it++)
      theColl.getp()->removeFromCollection(*it);
  }

  STACK_END (state);
}

bool
ZorbaRemoveNodeAtIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       item;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState)) {
    theColl = getCollection(planState, item->getStringValue(), loc);

    //delete the node
    if (consumeNext(item, theChildren[1].getp(), planState))
      if(item->getIntegerValue() >= Integer::zero())
        theColl.getp()->removeFromCollection(item->getIntValue());

  }

  STACK_END (state);
}

bool
ZorbaNodeCountIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       itemUri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState)) {
    theColl = getCollection(planState, itemUri->getStringValue(), loc);

    STACK_PUSH(GENV_ITEMFACTORY->createInteger(
              result,
              Integer::parseInt(theColl.getp()->size())), state);
  }

  STACK_END (state);
}

bool
ZorbaNodeAtIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       item;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState)) {
    theColl = getCollection(planState, item->getStringValue(), loc);

    if (consumeNext(item, theChildren[1].getp(), planState))
    {
      if(item->getIntegerValue() >= Integer::zero())
      {
        result = theColl->nodeAt(item->getIntValue());
        STACK_PUSH(true, state);
      }
    }
  }

  STACK_END (state);
}

bool
ZorbaIndexOfIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       item;
  int                 pos = 0;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState)) {
    theColl = getCollection(planState, item->getStringValue(), loc);

    if (consumeNext(item, theChildren[1].getp(), planState))
    {
      pos = theColl->indexOf(item);

      if( -1 == pos)
        ZORBA_ERROR_LOC_DESC (API0029_NODE_DOES_NOT_BELONG_TO_COLLECTION, loc, "The node does not belong to collection.");

      STACK_PUSH(GENV_ITEMFACTORY->createInteger(
                result,
                Integer::parseInt(pos)), state);
    }
  }

  STACK_END (state);
}

bool
ZorbaExportXmlIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       item;
  store::Iterator_t   collIterator;
  std::ostringstream  ss;
  error::ErrorManager lErrorManager;
  URI                 uri;
  serializer          ser(&lErrorManager);

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState)) {
    theColl = getCollection(planState, item->getStringValue(), loc);

    if(theChildren.size() == 2 && consumeNext(item, theChildren[1].getp(), planState))
      uri = URI(item->getStringValue().getp());
    else
      uri = URI(theColl->getUri()->getStringValue()->c_str());

    if( uri.get_scheme() != xqpString("file") && !uri.get_scheme().empty())
      ZORBA_ERROR_LOC_DESC (FOER0000, loc, "ZorbaExportXmlIterator implemented only for 'file' scheme.");

    std::auto_ptr<std::ostream> lFileStream (new std::ofstream(uri.get_path().c_str()));
    std::ostream* lOutputStream = lFileStream.get();
    if ( !lOutputStream->good() )
      ZORBA_ERROR_LOC_DESC_OSS (API0033_FILE_OR_FOLDER_DOES_NOT_EXIST, loc, "File or folder does not exist: " << uri.get_path().c_str());

    collIterator = theColl->getIterator(true);

    ser.set_parameter("omit-xml-declaration", "yes");

    collIterator->open();
    while (collIterator->next(item))
      ser.serialize(item, ss);

    collIterator->close();

    *lOutputStream << ss.str() << std::endl;
  }
  STACK_END (state);
}

store::Collection_t getCollection(PlanState& planState, const xqpStringStore_t strURI, const QueryLoc  loc)
{
  store::Item_t       resolvedURIItem;
  xqpStringStore_t    resolvedURIString;

  try {
    resolvedURIString = planState.sctx()->resolve_relative_uri(strURI.getp()).getStore();
    GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
  } catch (error::ZorbaError& e) {
    ZORBA_ERROR_LOC_PARAM(API0006_COLLECTION_NOT_FOUND, loc, strURI, "");
  }

  try {
    return planState.sctx()->get_collection_uri_resolver()->resolve(resolvedURIItem,
                             planState.sctx());
  } catch (error::ZorbaError& e) {
    ZORBA_ERROR_LOC_PARAM(API0006_COLLECTION_NOT_FOUND, loc, strURI, "");
  }

  return NULL;
}

} /* namespace zorba */
