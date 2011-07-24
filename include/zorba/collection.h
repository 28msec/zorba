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

/** \brief A Collection is a persistent sequence of node items.
 *
 * Instances of this class can be used to modify or retrieve the contents
 * of a collection.
 *
 * The variable aNodes passed to any of the insert functions is evaluated
 * as though it were an enclosed expression in an element constructor.
 * The result of this step is a sequence of nodes to be inserted into the collection.
 *
 * Note: This class is reference counted. When writing multi-threaded clients,
 * it is the responibility of the client code to synchronize assignments to the
 * SmartPtr holding this object.
 */
class ZORBA_DLL_PUBLIC Collection : public SmartObject
{
 public:
  /**
   * \brief Get the name of the collection.
   *
   * @return The name of the collection.
   */
  virtual const Item
  getName() const = 0;

  /**
   * This function inserts copies of the
   * given nodes at the beginning of the collection.
   *
   * @param aNodes The sequences of nodes whose copies
   *        should be added to the collection.
   *
   */
  virtual void
  insertNodesFirst(const ItemSequence_t& aNodes) = 0;
  
  /**
   * This function inserts copies of the
   * given nodes at the end of the collection.
   *
   * @param aNodes The sequences of nodes whose copies
   *        should be added to the collection.
   *
   */
  virtual void
  insertNodesLast(const ItemSequence_t& aNodes) = 0;
  
  /**
   * This function inserts copies of the given
   * nodes into a collection at the position directly preceding the
   * given target node.
   *
   * @param aTarget the node in the collection before which the
   *        sequence should be inserted.
   * @param aNodes The sequences of nodes whose copies should
   *        be added to the collection.
   *
   * @throw XDDY0011 if any nodes in the sequence is not a member of a collection
   *        or not all nodes of the sequence belong to the same collection.
   *
   */
  virtual void
  insertNodesBefore(
      const Item& aTarget,
      const ItemSequence_t& aNodes) = 0;

  /**
   * This function inserts copies of the given
   * nodes into a collection at the position directly following the
   * given target node.
   *
   * @param aTarget the node in the collection after which the
   *        sequence should be inserted.
   * @param aNodes The sequences of nodes whose copies should
   *        be added to the collection.
   *
   * @throw XDDY0011 if any nodes in the sequence is not a member of a collection
   *        or not all nodes of the sequence belong to the same collection.
   *
   */
  virtual void
  insertNodesAfter(
      const Item& aTarget,
      const ItemSequence_t& aNodes) = 0;
  
  /**
   * This function deletes zero of more nodes from a collection. 
   *
   * @param aNodes the nodes in the collection that should be deleted.
   *
   * @throw XDDY0011 if any nodes in the given sequence is not a member of a collection
   *        or not all nodes of the sequence belong to the same collection.
   *
   */
  virtual void
  deleteNodes(const ItemSequence_t& aNodes) = 0;
  
  /**
   * This function deletes the first node from a collection.
   *
   * @throw XDDY0011 if the collection doesn't contain any node.
   *
   */
  virtual void
  deleteNodeFirst() = 0;
  
  /**
   * This function deletes the n first nodes from a collection.
   *
   * @throw XDDY0011 if the collection doesn't contain any node.
   *
   */
  virtual void
  deleteNodesFirst(unsigned long aNumNodes) = 0;
  
  /**
   * This function deletes the last node from a collection.
   *
   * @throw XDDY0011 if the collection doesn't contain any node.
   *
   */
  virtual void
  deleteNodeLast() = 0;
  
  /**
   * This function deletes the n last nodes from a collection.
   *
   * @throw XDDY0011 if the collection doesn't contain any node.
   *
   */
  virtual void
  deleteNodesLast(unsigned long aNumNodes) = 0;
  
  /**
   * This function returns the index of the given node in the collection.
   *
   * @param aNode The node to retrieve the index from.
   *
   * @return Returns the position of the given node in the collection.
   *
   * @throw XDDY0011 if node is not contained in any collection.
   *
   */
  virtual long long
  indexOf(const Item& aNode) = 0;
  
  /**
   * This function returns the sequence of nodes of the collection.
   *
   * @return The sequence contained in the given collection.
   *
   */
  virtual ItemSequence_t
  contents() = 0;

  /**
   * \brief Destructor.
   */
  virtual ~Collection() {}

};
  
} /* namespace zorba */

#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
