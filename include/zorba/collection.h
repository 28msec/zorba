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
#ifndef ZORBA_COLLECTION_API_H
#define ZORBA_COLLECTION_API_H

#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/item.h>

namespace zorba {

/** \brief A Collection is a sequence of Node Items.
 *
 * Each Collection is created by the XmlDataManager and referenced by a URI.
 * The URI can be accessed in a query's fn:collection function.
 *
 * Note: This class is reference counted. When writing multi-threaded clients,
 * it is the responibility of the client code to synchronize assignments to the
 * SmartPtr holding this object.
 */
class ZORBA_DLL_PUBLIC Collection : public SmartObject
{
 public:
  /**
   * \brief Destructor.
   */
  virtual ~Collection() {}

  /**
   * \brief Get the URI of the collection as an anyURI Item.
   *
   * @return The URI of the Collection as an anyURI Item.
   */
  virtual Item
  getName() const = 0;

  /** 
   * \brief Returns the number of nodes in the collection.
   *
   * @return The number of nodes in the collection.
   */
  virtual unsigned long
  size() const = 0;

  /** 
   * \brief Adds the document retrieved from the given input stream to the Collection.
   *
   * @param aInStream The input stream from which to parse the document.
   * @param aPosition The position where the node will be inserted at. Positions
   * are numbered starting from 1. If a non-positive position is given, the
   * document will be appended at the end.
   * @return True if the document was added to the collection (e.g. was a
   * valid document), false otherwise.
   */
  virtual bool
  addDocument(std::istream& aInStream, long aPosition = -1) = 0;
    
  /**
   * \brief Adds a copy of a node to the collection. The node must be the root
   * of an xml tree (i.e., it must not have a parent). The copy is deep, i.e.,
   * the whole tree rooted at the given node is copied.
   *
   * Default copy behavior is used: 
   * - construction mode == preserve, 
   * - copy-namespace modes == preserve & inherit
   *
   * @param aNode The node to add.
   * @param aPosition The position where the node will be inserted. Positions
   * are numbered starting from 1. If a non-positive position is given, the
   * document will be appended at the end.
   * @return True if the node was added to the collection, false otherwise.
   */
  virtual bool
  addNode(Item& aNode, long aPosition = -1) = 0;
  
  /** \brief Adds a copy of a node to the Collection before or after another
   * targetNode, which must be in the collection already. The node to add
   * must be the root of an xml tree (i.e., it must not have a parent). The
   * copy is deep, i.e., the whole tree rooted at the given node is copied.
   *
   * Default copy behavior is used:
   * - construction mode == preserve,
   * - copy-namespace modes == preserve & inherit
   *
   * @param aNode The node to add.
   * @param aTargetNode The new node will be added before or after the target node.
   * @param aBefore If true, the new node will be inserted before the target node.
   * Otherwise the new node will be inserted after the target node.
   * @return True if the node was added to the collection, false otherwise.
   */
  virtual bool
  addNode(Item& aNode, const Item& aTargetNode, bool aBefore) = 0;
  
  /** 
   * \brief Adds copies of the nodes retrieved from the given ResultIterator to
   * the Collection. Each of the nodes to add must be root of an xml tree (i.e.,
   * it must not have a parent). The copy is deep, i.e., the whole tree rooted
   * at each retrieved node is copied.
   *
   * Default copy behavior is used:
   * - construction mode == preserve, 
   * - copy-namespace modes == preserve & inherit
   *
   * @param aResultIterator the ResultIterator that produces the nodes to add.
   * @return true if all the nodes of the given ResultIterator were added to
   * the Collection, false otherwise.
   */
  virtual bool
  addNodes(const ResultIterator* aResultIterator) = 0;

  /** 
   * \brief Removes the given node from the collection.
   *
   * @param aNode The node to delete
   * @return true if the given node was in the collection, false otherwise.
   */
  virtual bool
  deleteNode(Item& aNode) = 0;
  
  /** 
   * \brief Removes the node at the given position from the Collection.
   *
   * @param aPosition The position of the node that will be removed from collection.
   * If a non-positive position is given, the last node is removed.
   * @return true if the given Node Item was deleted, false otherwise.
   */
  virtual bool
  deleteNode(long aPosition = -1) = 0;
  
  /** 
   * \brief Get the node at the given position in the collection as a Node Item.
   *
   * @param aPosition The position of the node in the collection.
   * @return the Node Item at the given position.
   */
  virtual Item
  nodeAt(long aPosition) = 0;
};

  
} /* namespace zorba */

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
