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

#include "simple_store.h"
#include "store_defs.h"

#include "simple_collection.h"
#include "simple_collection_set.h"
#include "simple_item_factory.h"
#include "simple_iterator_factory.h"
#include "node_factory.h"
#include "pul_primitive_factory.h"
#include "node_items.h"

#include "diagnostics/zorba_exception.h"
#include "diagnostics/diagnostic.h"
#include <zorba/diagnostic_list.h>

#include "util/uuid/uuid.h"
#include "zorbautils/string_util.h"

#ifdef ZORBA_WITH_JSON
#include "store/naive/json_loader.h"
#endif


namespace zorba
{

namespace simplestore
{

typedef rchandle<store::TempSeq> TempSeq_t;


/*******************************************************************************

********************************************************************************/
SimpleStore::SimpleStore()
  :
  theCollectionCounter(1),
  theNodeToReferencesMap(128, true)
{
}


/*******************************************************************************

********************************************************************************/
SimpleStore::~SimpleStore()
{
  shutdown(false);
}


/*******************************************************************************

********************************************************************************/
void SimpleStore::init()
{
  theCollectionCounter = 1;

  Store::init();
}


void SimpleStore::shutdown(bool soft)
{
  Store::shutdown(soft);

  if (theNumUsers == 0 || soft == false) 
  {
    if (theNodeToReferencesMap.size() > 0)
    {
      NodeRefMap::iterator iter = theNodeToReferencesMap.begin();
      NodeRefMap::iterator end = theNodeToReferencesMap.end();
      for (; iter != end; ++iter)
      {
        std::cerr << "Reference: " << (*iter).second
                  << "is still in the nodes to references map" << std::endl;
      }
      ZORBA_FATAL(0, theNodeToReferencesMap.size() +
                     " node references still in the nodes to references map");
    }

    if (theReferencesToNodeMap.size() > 0)
    {
      RefNodeMap::iterator iter = theReferencesToNodeMap.begin();
      RefNodeMap::iterator end = theReferencesToNodeMap.end();
      for (; iter != end; ++iter)
      {
        std::cerr << "Reference: " << (*iter).first
                  << "is still in the references to nodes map" << std::endl;
      }
      ZORBA_FATAL(0, theReferencesToNodeMap.size() +
                     " node references still in the references to nodes map");
    }
  }
}


/*******************************************************************************

*******************************************************************************/
PULPrimitiveFactory*
SimpleStore::createPULFactory() const
{
  return new PULPrimitiveFactory();
}


/*******************************************************************************

*******************************************************************************/
void
SimpleStore::destroyPULFactory(PULPrimitiveFactory* f) const
{
  delete f;
}


/*******************************************************************************

*******************************************************************************/
TreeIdGeneratorFactory*
SimpleStore::createTreeIdGeneratorFactory() const
{
  return new SimpleTreeIdGeneratorFactory();
}


/*******************************************************************************

*******************************************************************************/
void
SimpleStore::destroyTreeIdGeneratorFactory(TreeIdGeneratorFactory* g) const
{
  delete g;
}


/*******************************************************************************

*******************************************************************************/
CollectionSet* SimpleStore::createCollectionSet() const
{
  return new SimpleCollectionSet();
}


/*******************************************************************************

*******************************************************************************/
void SimpleStore::destroyCollectionSet(CollectionSet* c) const
{
  delete c;
}


/*******************************************************************************

*******************************************************************************/
NodeFactory* SimpleStore::createNodeFactory() const
{
  return new NodeFactory();
}


/*******************************************************************************

*******************************************************************************/
void SimpleStore::destroyNodeFactory(NodeFactory* f) const
{
  delete f;
}


/*******************************************************************************

*******************************************************************************/
store::ItemFactory* SimpleStore::createItemFactory() const
{
  return new BasicItemFactory(theNamespacePool, theQNamePool);
}


/*******************************************************************************

*******************************************************************************/
void SimpleStore::destroyItemFactory(store::ItemFactory* f) const
{
  delete f;
}


/*******************************************************************************

*******************************************************************************/
store::IteratorFactory* SimpleStore::createIteratorFactory() const
{
  return new SimpleIteratorFactory();
}


/*******************************************************************************

*******************************************************************************/
void SimpleStore::destroyIteratorFactory(store::IteratorFactory* f) const
{
  delete f;
}


/*******************************************************************************
  Create an id for a new collection
********************************************************************************/
ulong SimpleStore::createCollectionId()
{
  SYNC_CODE(AutoMutex lock(&theCollectionCounterMutex);)
  return theCollectionCounter++;
}


/*******************************************************************************
  Create a collection with a given QName and return an rchandle to the new
  collection object. If a collection with the given QName exists already, raise
  an error.
********************************************************************************/
store::Collection_t SimpleStore::createCollection(
    const store::Item_t& name,
    const std::vector<store::Annotation_t>& annotations,
    const store::Item_t& nodeType,
    bool isDynamic)
{
  if (name == NULL)
    return NULL;

  store::Collection_t collection(new SimpleCollection(name,
                                                      annotations,
                                                      nodeType,
                                                      isDynamic));

  const store::Item* lName = collection->getName();

  bool inserted = theCollections->insert(lName, collection);

  if (!inserted)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0008_COLLECTION_ALREADY_EXISTS,
    ERROR_PARAMS(lName->getStringValue()));
  }

  return collection;
}


/*******************************************************************************
 Computes the reference of the given node.

 @param node XDM node
 @return the identifier as an item of type xs:anyURI
********************************************************************************/
bool SimpleStore::getNodeReference(store::Item_t& result, const store::Item* node)
{
  const XmlNode* xmlNode = static_cast<const XmlNode*>(node);

  if (xmlNode->haveReference())
  {
    NodeRefMap::iterator resIt = theNodeToReferencesMap.find(xmlNode);

    ZORBA_FATAL(resIt != theNodeToReferencesMap.end(),"Node reference cannot be found");

    zstring id = (*resIt).second;
    return theItemFactory->createAnyURI(result, id);
  }

  uuid_t uuid;
  uuid_create(&uuid);
  zstring uuidStr = uuidToURI(uuid);

  const_cast<XmlNode*>(xmlNode)->setHaveReference();

  theNodeToReferencesMap.insert(xmlNode, uuidStr);
  theReferencesToNodeMap[uuidStr] = node;

  return theItemFactory->createAnyURI(result, uuidStr);
}


/*******************************************************************************
  Returns whether a reference has already been generated for the given node.
 
  @param item XDM node
  @return whether a reference has already been generated for the given node.
********************************************************************************/
bool SimpleStore::hasReference(const store::Item* node)
{
  return static_cast<const XmlNode*>(node)->haveReference();
}


/*******************************************************************************
  Returns the node which is identified by the given reference.

  @param reference an xs:anyURI item
  @result the node identified by the reference, or NULL if no node with the given
          reference exists
  @return false if no node with the given reference exists; true otherwise.
********************************************************************************/
bool SimpleStore::getNodeByReference(store::Item_t& result, const zstring& reference)
{
  if (reference.length() != 45 ||
      !utf8::match_whole(reference, "urn:uuid:[a-f0-9]{8}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{4}-[a-f0-9]{12}"))
  {
    throw ZORBA_EXCEPTION(zerr::ZAPI0028_INVALID_NODE_URI, ERROR_PARAMS(reference));
  }

  RefNodeMap::iterator resIt;

  if ((resIt = theReferencesToNodeMap.find(reference)) != theReferencesToNodeMap.end())
  {
    result = resIt->second;
    return true;
  }

  result = NULL;
  return false;
}


/*******************************************************************************
  Removes a node from the reference-to-nodes and nodes-to-references maps.

  @param node XDM node
  @return whether the node was registered or not.
********************************************************************************/
bool SimpleStore::unregisterReferenceToUnusedNode(XmlNode* node)
{
  if (!node->haveReference())
    return false;

  NodeRefMap::iterator resIt;

  if ((resIt = theNodeToReferencesMap.find(node)) != theNodeToReferencesMap.end())
  {
    zstring value = (*resIt).second;
    theNodeToReferencesMap.erase(resIt);
    node->resetHaveReference();

    theReferencesToNodeMap.erase(value);

    return true;
  }
  else
  {
    return false;
  }
}

/*******************************************************************************
  Does nothing in the simple store.

  @param node XDM node
  @return whether the node was registered or not.
********************************************************************************/
bool SimpleStore::unregisterReferenceToDeletedNode(XmlNode* node)
{
  // Does nothing, since there is no persistency layer. A deleted node can still
  // be retrieved with a reference, so its reference may not be removed from the
  // cache.
  // Merely returns true if entry found, false otherwise.
  
  if (!node->haveReference())
    return false;

  NodeRefMap::iterator resIt;

  if ((resIt = theNodeToReferencesMap.find(node)) != theNodeToReferencesMap.end())
  {
    return true;
  }
  else
  {
    return false;
  }
}


#ifdef ZORBA_WITH_JSON
/*******************************************************************************

********************************************************************************/
store::Item_t SimpleStore::parseJSON(
    std::istream& stream,
    internal::diagnostic::location* relative_error_loc)
{
  json::JSONLoader lLoader(stream, relative_error_loc);
  return lLoader.next();
}
#endif /* ZORBA_WITH_JSON */

} // namespace simplestore
} // namespace zorba
