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

/*******************************************************************************
  declare function collection-exists($uri as xs:anyURI) as xs:boolean
  
  Returns true if a collection with the requested $uri is found in the collection
  pool, false otherwise.
********************************************************************************/
bool
ZorbaCollectionExistsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState  *state;
  store::Item_t       item, resolvedURIItem;
  xqpStringStore_t    resolvedURIString;
  store::Collection_t lCollection;
  bool                res = false;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState )) 
  {
    try 
    {
      resolvedURIString = planState.sctx()->
                          resolve_relative_uri(item->getStringValueP(),
                                               xqp_string()).getStore();

      GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
    }
    catch (error::ZorbaError&) 
    {
      ZORBA_ERROR_LOC_PARAM(XQST0046,
                            loc,
                            item->getStringValue()->c_str(),
                            "URI literal empty or is not in the lexical space of xs:anyURI" );
    }

    lCollection = planState.sctx()->get_collection_uri_resolver()->
                  resolve(resolvedURIItem, planState.sctx());
    res = (lCollection != NULL);

    GENV_ITEMFACTORY->createBoolean(result, res);
    STACK_PUSH(true, state );
  }

  STACK_END (state);
}


/*******************************************************************************
  declare function import-xml($uri as xs:anyURI) as none

  This function will create a new collection and import a given XML document
  into it. The document to import is identified by the $uri parameter; this uri
  will be used as the uri of the collection. If the $uri is found in the 
  collection poll no import is done.

  Error conditions:
  - If the XML file specified by the $uri parameter does not exist, an error is
    raised (API0033_FILE_OR_FOLDER_DOES_NOT_EXIST - the file or folder does not
    exist).
  - If the XML file cannot be opened, an error is raised 
    (API0034_FILE_OR_FOLDER_CANNOT_BE_OPENED - a file or folder cannot be opened).
********************************************************************************/
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
    // ????
    theColl = getCollection(planState, itemURI->getStringValue(), loc);

    try 
    {
      resolvedURIString = planState.sctx()->
                          resolve_relative_uri(itemURI->getStringValueP(),
                                               xqp_string()).getStore();

      itemXML = GENV_STORE.getDocument(resolvedURIString);
    }
    catch (error::ZorbaError& e) 
    {
      ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
    }

    if (itemXML == NULL) 
    {
      try 
      {
        GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
      }
      catch (error::ZorbaError& e) 
      {
        ZORBA_ERROR_LOC_DESC(FODC0005, loc, e.theDescription);
      }

      try 
      {
        itemXML = planState.sctx()->get_document_uri_resolver()->
                  resolve(resolvedURIItem, planState.sctx(), false, false);
      }
      catch (error::ZorbaError& e) 
      {
        ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
      }
    }

    strURI = itemURI->getStringValue();
    theColl = GENV_STORE.createCollection(strURI);
    theColl->addNode(itemXML, 1);
  }

  STACK_END (state);
}


/*******************************************************************************
  declare function import-catalog($uri as xs:anyURI) as none

  The function will open the given XML file and interpret it as a catalog.
  Assuming $uri is 'file://localhost/home/user_1/catalog.xml', it must have the
  following structure:
  <catalog>
  <doc href="file1.xml"/>
  <doc href="path/file2.xml"/>
  <doc href="path/file3.xml"/>
  ...
  </catalog>

  Each of the documents referenced in the <doc> tags is first looked up in the
  store. If it is already present, nothing is done; otherwise the doc is loaded,
  a new collection is created for it with the same uri, and the doc is added to
  this new collection.

  The URIs of the catalog and the files may include a protocol specification,
  such as "file://" or "http://". 

  The function will not validate the catalog file's structure. In case it is
  malformed - no XML files will be imported (actually, zorba will crash ???).

  In case a href attribute contains no path, only the name of the file (see the
  first href attribute in the example above) the file will be looked in the same
  path as the catalog ('file://localhost/home/user_1/file1.xml' in the example
  above).

  Error conditions:
  - If the catalog file specified by the $uri parameter or any of the files
    specified by the href attributes does not exist, an error is raised
    (API0033_FILE_OR_FOLDER_DOES_NOT_EXIST - the file or folder does not exist).
  - If the catalog file or the href files cannot be opened, an error is raised
    (API0034_FILE_OR_FOLDER_CANNOT_BE_OPENED - a file or folder cannot be opened)

********************************************************************************/
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

  // Load the catalog document, if it has not been loaded before
  try 
  {
    inNode = GENV_STORE.getDocument(itemURI->getStringValue());
  }
  catch (error::ZorbaError& e) 
  {
    ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
  }

  if (inNode == NULL) 
  {
    try 
    {
      resolvedURIString = planState.sctx()->
                          resolve_relative_uri(uriString.getp(),
                                               xqp_string()).getStore();

      GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
    }
    catch (error::ZorbaError& e) 
    {
      ZORBA_ERROR_LOC_DESC(FODC0005, loc, e.theDescription);
    }
    try 
    {
      inNode = planState.sctx()->get_document_uri_resolver()->
               resolve(resolvedURIItem, planState.sctx(), false, false);
    }
    catch (error::ZorbaError& e) 
    {
      ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
    }
  }

  // Navigate the catalog doc to extract the uri of each data doc and then, if
  // the data doc is not loaded already, create a collection for it, load the
  // doc, and add it to its associated collection.
  if(inNode->getNodeKind() == store::StoreConsts::documentNode) 
  {
    theIterator = inNode->getChildren();
    theIterator->open();
    theIterator->next(intt);
    theIterator->close();

    theIterator = intt->getChildren();
    theIterator->open();

    while(theIterator->next(inArg)) 
    {
      if(inArg->getNodeKind() == store::StoreConsts::elementNode &&
         inArg->getNodeName()->getLocalName()->byteEqual("doc", 3)) 
      {
        theAttributes = inArg->getAttributes();
        theAttributes->open();
        for (; theAttributes->next(attr); ) 
        {
          attrName = attr->getNodeName()->getStringValue()->str();
          if(attr->getNodeName()->getLocalName()->byteEqual("href", 4)) 
          {
            if (attr->getStringValue()->indexOf("/") == -1)
              uriFile = URI(uriCatalog, attr->getStringValue().getp());
            else
              uriFile = URI(attr->getStringValue().getp());

            fileString = uriFile.toString().getStore();

            try 
            {
              itemXML = GENV_STORE.getDocument(fileString);
            }
            catch (error::ZorbaError& e) 
            {
              ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
            }

            if (itemXML == NULL) 
            {
              try 
              {
                resolvedURIString = fileString;
                GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
              }
              catch (error::ZorbaError& e) 
              {
                ZORBA_ERROR_LOC_DESC(FODC0005, loc, e.theDescription);
              }
              try 
              {
                itemXML = planState.sctx()->get_document_uri_resolver()->
                          resolve(resolvedURIItem, planState.sctx(), false, false);
              }
              catch (error::ZorbaError& e) 
              {
                ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
              }
            }

            xqpStringStore_t    collectionUri = uriFile.toString().getStore();
            theColl = GENV_STORE.createCollection(collectionUri);
            theColl->addNode(itemXML, 1);
          }
        }
        theAttributes->close();
      }
    }
    theIterator->close();
  }

  STACK_END (state);
}


/*******************************************************************************
  declare function import-folder($uri as xs:anyURI) as none

  The function will scan the given folder and import the specified XML files.
  The URI may also have a number of query parameters, written in the form:
  "file:///path/folder?parameter=value&parameter=value&..."
 
  Supported parameters are:
  recurse   yes | no (default)    searches folders recursively for files.
  select    pattern               controls which files will be opened.
                                  Wildcards such as "*.xml" can be used.

  Error conditions:
  - If the folder specified by the $uri parameter does not exist, an error is
    raised (API0033_FILE_OR_FOLDER_DOES_NOT_EXIST - the file or folder does
    not exist).
  - If the folder or the any of the files selected by the parameters cannot
    be opened, an error is raised (API0034_FILE_OR_FOLDER_CANNOT_BE_OPENED -
    a file or folder cannot be opened)
********************************************************************************/
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
    ZORBA_ERROR_LOC_DESC (FOER0000,
                          loc,
                          "ZorbaImportFolderIterator implemented only for 'file' scheme.");

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
ZorbaListCollectionsState::~ZorbaListCollectionsState()
{
  if ( uriItState != NULL ) {
    uriItState->close();
    uriItState = NULL;
  }
}


/*******************************************************************************

********************************************************************************/
void
ZorbaListCollectionsState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  uriItState = NULL;
}


/*******************************************************************************

********************************************************************************/
void
ZorbaListCollectionsState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if ( uriItState != NULL ) {
    uriItState->close();
    uriItState = NULL;
  }
}


/*******************************************************************************
  declare function list-collections() as xs:anyURI*

  The function will return a sequence of URIs of all currently known collections.
********************************************************************************/
bool
ZorbaListCollectionsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  ZorbaListCollectionsState * state;
  store::Item_t               uriItem;

  DEFAULT_STACK_INIT(ZorbaListCollectionsState, state, planState);

  for ((state->uriItState = GENV_STORE.listCollectionUris())->open ();
       state->uriItState->next(uriItem); ) 
  {
    result = uriItem;
    STACK_PUSH( true, state);
  }

  state->uriItState->close();

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function create-collection($uri as xs:anyURI) as none

  declare sequential function create-collection($uri as xs:anyURI,
                                                $nodes as node()*) as none

  The first function will create a new, empty, collection. The second function
  will create a new collection and will add the given nodes to it.

  Error conditions:
  If the collection already exists, an error is raised
  (API0005_COLLECTION_ALREADY_EXISTS - collection already exists).
********************************************************************************/
bool
ZorbaCreateCollectionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       item;
  xqpStringStore_t    resolvedURIString;
  store::Collection_t theColl = NULL;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState))
  {
    try 
    {
      resolvedURIString = planState.sctx()->
                          resolve_relative_uri(item->getStringValueP(),
                                               xqp_string()).getStore();
    }
    catch (error::ZorbaError& e) 
    {
      ZORBA_ERROR_LOC_DESC(FODC0005, loc, e.theDescription);
    }
    try 
    {
      theColl = getCollection(planState, resolvedURIString, loc);
    }
    catch (error::ZorbaError&) 
    {
      // we come here if the collection does not exist already
    }

    if (theColl != NULL)
      ZORBA_ERROR_LOC_DESC(API0005_COLLECTION_ALREADY_EXISTS,
                           loc,
                           "The collection already exists.");

    theColl = GENV_STORE.createCollection(resolvedURIString);

    if(theChildren.size() == 2) 
    {
      //add the nodes to the newly created collection
      while (consumeNext(item, theChildren[1].getp(), planState))
        theColl.getp()->addNode(item.getp(), -1);
    }
  }

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function delete-collection($uri as xs:anyURI) as none

  The function will delete the collection identified by the given URI.

  Error conditions:
  If the collection does not exist, an error is raised.
  (API0006_COLLECTION_NOT_FOUND - collection does not exist).
********************************************************************************/
bool
ZorbaDeleteCollectionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState  *state;
  store::Item_t       item;
  store::Collection_t coll;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState )) 
  {
    coll = getCollection(planState, item->getStringValue(), loc);

    GENV_STORE.deleteCollection(coll->getUri()->getStringValue());
  }

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function delete-all-collections() as none

  The function will delete all existing collections.
********************************************************************************/
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

  uriItState->close();

  it = vectorUri.begin();
  end = vectorUri.end();

  for (; it != end; ++it)
  {
    GENV_STORE.deleteCollection(*it);
  }

  vectorUri.clear();

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function insert-nodes-first($uri as xs:anyURI,
                                                 $newnode as node()*) as none

  The function will insert the given node(s) as the first node(s) of the given
  collection. If multiple nodes are inserted, the nodes remain adjacent and
  their order preserves the node ordering of the source expression.

  Error conditions:
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the node is already in the collection, an error is raised
    (API0031_NODE_ALREADY_IN_COLLECTION)
********************************************************************************/
bool
ZorbaInsertNodeFirstIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       item;
  int                 pos = 1;
  std::vector<store::Item_t> nodes(64);
  ulong numNodes = 0;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState)) 
  {
    theColl = getCollection(planState, item->getStringValue(), loc);

    //add the nodes to the newly created collection
    while (consumeNext(item, theChildren[1].getp(), planState))
    {
      nodes.resize(numNodes + 1);
      nodes[numNodes].transfer(item);
      numNodes++;
    }

    theChildren[1]->reset(planState);
  }

  for (ulong i = 0; i < numNodes; i++)
  {
    theColl.getp()->addNode(nodes[i], pos++);
  }

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function insert-nodes-last($uri as xs:anyURI,
                                                $newnode as node()*) as none

  The function will insert the given node(s) as the last node(s) of the given
  collection. If multiple nodes are inserted, the nodes remain adjacent and 
  their order preserves the node ordering of the source expression.

  Error conditions:
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the node is already in the collection, an error is raised
    (API0031_NODE_ALREADY_IN_COLLECTION) 
********************************************************************************/
bool
ZorbaInsertNodeLastIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       item;
  xqpStringStore_t    strURI;
  std::vector<store::Item_t> nodes(64);
  ulong numNodes = 0;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState)) 
  {
    theColl = getCollection(planState, item->getStringValue(), loc);

    //add the nodes to the newly created collection
    while (consumeNext(item, theChildren[1].getp(), planState))
    {
      nodes.resize(numNodes + 1);
      nodes[numNodes].transfer(item);
      numNodes++;
    }

    theChildren[1]->reset(planState);
  }

  for (ulong i = 0; i < numNodes; i++)
  {
    theColl.getp()->addNode(nodes[i], -1);
  }

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function insert-nodes-before($uri as xs:anyURI,
                                                  $target as node()+,
                                                  $newnode as node()*) as none


  The inserted nodes become the preceding (or following) nodes of the target.
  The $target should be a non-updating expression (e.g. an XPath expression)
  identifying a node that is part of the given collection at the top-level.
  If the expression returns more than one node, the first one is used. If 
  multiple nodes are inserted by a single insert expression, the nodes remain
  adjacent and their order preserves the node ordering of the source expression.

  Error conditions:
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the target node is not part of the collection, an error is raised
    (API0029_NODE_DOES_NOT_BELONG_TO_COLLECTION - the node does not belong
    to the given collection).
  - If any of the new nodes is already part of the collection an error is
    raised (API0031_NODE_ALREADY_IN_COLLECTION).
********************************************************************************/
bool
ZorbaInsertNodeBeforeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       itemUri, itemTarget, itemNewNode;
  std::vector<store::Item_t> nodes(64);
  ulong numNodes = 0;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState)) 
  {
    theColl = getCollection(planState, itemUri->getStringValue(), loc);

    if(consumeNext(itemTarget, theChildren[1].getp(), planState))
    {
      theChildren[1]->reset(planState);

      //add the nodes to the newly created collection
      while (consumeNext(itemNewNode, theChildren[2].getp(), planState))
      {
        nodes.resize(numNodes + 1);
        nodes[numNodes].transfer(itemNewNode);
        numNodes++;
      }

      theChildren[2]->reset(planState);

      for (ulong i = 0; i < numNodes; i++)
      {
        theColl.getp()->addNode(nodes[i], itemTarget, true);
      }
    }
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool
ZorbaInsertNodeAfterIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       itemUri, itemTarget, itemNewNode;
  std::vector<store::Item_t> nodes(64);
  ulong numNodes = 0;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState)) 
  {
    theColl = getCollection(planState, itemUri->getStringValue(), loc);

    if(consumeNext(itemTarget, theChildren[1].getp(), planState))
    {
      theChildren[1]->reset(planState);

      //add the nodes to the newly created collection
      while (consumeNext(itemNewNode, theChildren[2].getp(), planState))
      {
        nodes.resize(numNodes + 1);
        nodes[numNodes].transfer(itemNewNode);
        numNodes++;
      }

      theChildren[2]->reset(planState);

      for (ulong i = 0; i < numNodes; i++)
      {
        theColl.getp()->addNode(nodes[i], itemTarget, false);
      }
    }
  }

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function insert-nodes-at($uri as xs:anyURI,
                                              $position as xs:integer,
                                              $newnode as node()*) as none

  Inserts the node(s) into the given collection, at the specified position.
  If $position is negative, the node(s) will be inserted at the beginning of
  the collection. If $position is greater or equal to the number of nodes in
  the collection, the node(s) will be inserted as the last node(s) of the
  collection.

  Error conditions:
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the node is already part of the collection an error is raised
    (API0031_NODE_ALREADY_IN_COLLECTION).
********************************************************************************/
bool
ZorbaInsertNodeAtIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       itemUri, itemPos, itemNode;
  uint32_t            pos = 1;
  std::vector<store::Item_t> nodes(64);
  ulong numNodes = 0;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState)) 
  {
    theColl = getCollection(planState, itemUri->getStringValue(), loc);

    if(consumeNext(itemPos, theChildren[1].getp(), planState))
    {
      theChildren[1]->reset(planState);

      if(itemPos->getIntegerValue() > Integer::zero())
        NumConversions::strToUInt(itemPos->getIntegerValue().toString(), pos);

      //add the nodes to the newly created collection
      while (consumeNext(itemNode, theChildren[2].getp(), planState))
      {
        nodes.resize(numNodes + 1);
        nodes[numNodes].transfer(itemNode);
        numNodes++;
      }

      theChildren[2]->reset(planState);

      for (ulong i = 0; i < numNodes; i++)
      {
        theColl.getp()->addNode(nodes[i], pos++); 
      }
    }
  }

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function remove-nodes($uri as xs:anyURI,
                                           $target as node()+) as none

  The function will remove the node(s) identified by the $target expression
  from the given collection. The nodes themselves will not be deleted and
  they may remain as parts of other collections. If the expression identifies
  more than one node, all of them will be removed from the collection. 

  Error conditions:
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the given expression points to a node that is not part of the collection,
    an error is raised (API0029_NODE_DOES_NOT_BELONG_TO_COLLECTION - the node
    does not belong to the given collection). 
********************************************************************************/
bool
ZorbaRemoveNodeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t                     theColl;
  store::Item_t                           item;
  checked_vector<int>                     toBeRemoved;
  checked_vector<int>::reverse_iterator   it, end, begin;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState)) 
  {
    theColl = getCollection(planState, item->getStringValue(), loc);

    //delete the nodes
    while (consumeNext(item, theChildren[1].getp(), planState))
      toBeRemoved.push_back(theColl->indexOf(item));

    theChildren[1]->reset(planState);

    begin = toBeRemoved.rbegin();
    end = toBeRemoved.rend();

    for (it = begin; it != end; it++)
      theColl.getp()->removeNode(*it);
  }

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function remove-node-at($uri as xs:anyURI,
                                             $position as xs:integer) as none

  The function will remove from the given collection the node positioned at
  $position.

  Error conditions:
  - If the specified collection does not exist, an error is raised 
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).

  - If the collection has fewer nodes than $position + 1, nothing is removed
    and an error is raised (API0030_NO_NODE_AT_GIVEN_POSITION - there is no
    node at the given position, the collection has fewer nodes). 
********************************************************************************/
bool
ZorbaRemoveNodeAtIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       item;
  uint32_t            lpos;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState)) 
  {
    theColl = getCollection(planState, item->getStringValue(), loc);

    //delete the node
    if (consumeNext(item, theChildren[1].getp(), planState)) 
    {
      if(item->getIntegerValue() >= Integer::zero()) 
      {
        NumConversions::strToUInt(item->getIntegerValue().toString(),lpos);
        theColl.getp()->removeNode(lpos);
      }
    }
  }

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function nodes-count($uri as xs:anyURI) as xs:integer?

  The function returns the number of nodes in the given collection.

  Error conditions:
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
********************************************************************************/
bool
ZorbaNodeCountIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       itemUri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemUri, theChildren[0].getp(), planState)) 
  {
    theColl = getCollection(planState, itemUri->getStringValue(), loc);

    STACK_PUSH(GENV_ITEMFACTORY->createInteger(
              result,
              Integer::parseInt(theColl.getp()->size())), state);
  }

  STACK_END (state);
}


/*******************************************************************************
  declare sequential function node-at($uri as xs:anyURI,
                                      $position as xs:integer) as node()?

  The function will return the node positioned at $position in the given collection.

  Error conditions:
  - If the specified collection does not exist, an error is raised
    (API0006_COLLECTION_NOT_FOUND - collection does not exist).
  - If the collection has fewer nodes than $position + 1 an error is raised
    (API0030_NO_NODE_AT_GIVEN_POSITION - there is no node at the given position,
    the collection has fewer nodes). 
********************************************************************************/
bool
ZorbaNodeAtIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Collection_t theColl;
  store::Item_t       item;
  uint32_t            lpos;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState)) 
  {
    theColl = getCollection(planState, item->getStringValue(), loc);

    if (consumeNext(item, theChildren[1].getp(), planState))
    {
      if(item->getIntegerValue() >= Integer::zero())
      {
        NumConversions::strToUInt(item->getIntegerValue().toString(),lpos);
        result = theColl->nodeAt(lpos);
        STACK_PUSH(true, state);
      }
    }
  }

  STACK_END (state);
}


/*******************************************************************************
  declare function index-of($uri as xs:anyURI, $target as node()) as xs:integer

  The function will return the index of the  $target node within the collection
  identified by $uri.

  Error condition:
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
  int                 pos = 1;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChildren[0].getp(), planState)) 
  {
    theColl = getCollection(planState, item->getStringValue(), loc);

    if (consumeNext(item, theChildren[1].getp(), planState))
    {
      pos = theColl->indexOf(item);

      if( -1 == pos)
        ZORBA_ERROR_LOC_DESC (API0029_NODE_DOES_NOT_BELONG_TO_COLLECTION,
                              loc,
                              "The node does not belong to collection.");

      STACK_PUSH(GENV_ITEMFACTORY->createInteger(
                result,
                Integer::parseInt(pos)), state);
    }
  }

  STACK_END (state);
}


/*******************************************************************************
  declare updating function export-xml($uri as xs:anyURI) as none

  declare updating function export-xml($uri as xs:anyURI,
                                       $targeturi as xs:string) as none

  Saves the given collection to the target URI as an XML file. Intended
  supported targets (protocols) are: "file:///path/file.xml" : (e.g.
  "file://c:/path/folder/file.xml") - saves the collection to a file, in the
  serialized form. "http://www.example.com/path/file.xml" - saves the
  collection to a remote location, via the HTTP PUT request (to be implemented
  by the REST library).

  If the protocol is omitted in the URI, "file://" is assumed.

  The first function will use the collection's URI (the $uri parameter) as the
  target URI.

  The collection will be exported only if it can be serialized correctly - i.e.
  it is a well-formed XML document. In all other cases an error will be returned
  (API0035_COLLECTION_CANNOT_BE_SERIALIZED - the collection cannot be serialized).

********************************************************************************/
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

  if (consumeNext(item, theChildren[0].getp(), planState)) 
  {
    theColl = getCollection(planState, item->getStringValue(), loc);

    if(theChildren.size() == 2 &&
       consumeNext(item, theChildren[1].getp(), planState))
    {
      uri = URI(item->getStringValue().getp());
    }
    else
    {
      uri = URI(theColl->getUri()->getStringValue()->c_str());
    }

    if( uri.get_scheme() != xqpString("file") && !uri.get_scheme().empty())
    {
      ZORBA_ERROR_LOC_DESC (FOER0000,
                            loc,
                            "ZorbaExportXmlIterator implemented only for 'file' scheme.");
    }

    std::auto_ptr<std::ostream> lFileStream (new std::ofstream(uri.get_path().c_str()));
    std::ostream* lOutputStream = lFileStream.get();
    if ( !lOutputStream->good() )
      ZORBA_ERROR_LOC_DESC_OSS (API0033_FILE_OR_FOLDER_DOES_NOT_EXIST,
                                loc,
                                "File or folder does not exist: " << uri.get_path().c_str());

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


/*******************************************************************************

********************************************************************************/
store::Collection_t getCollection(
    PlanState& planState,
    const xqpStringStore_t strURI,
    const QueryLoc loc)
{
  store::Item_t       resolvedURIItem;
  xqpStringStore_t    resolvedURIString;

  try 
  {
    resolvedURIString = planState.sctx()->
                        resolve_relative_uri(strURI.getp(),
                                             xqp_string()).getStore();

    GENV_ITEMFACTORY->createAnyURI(resolvedURIItem, resolvedURIString);
  }
  catch (error::ZorbaError& e) 
  {
    ZORBA_ERROR_LOC_PARAM(API0006_COLLECTION_NOT_FOUND, loc, strURI, e.theDescription);
  }

  store::Collection_t lCollection = planState.sctx()->
                                    get_collection_uri_resolver()->
                                    resolve(resolvedURIItem, planState.sctx());
  if (lCollection == NULL) 
  {
    ZORBA_ERROR_LOC_PARAM(API0006_COLLECTION_NOT_FOUND,
                          loc,
                          strURI,
                          "The requested collection could not be found.");
  }

  return lCollection;
}

} /* namespace zorba */
