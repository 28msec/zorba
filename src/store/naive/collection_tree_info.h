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

#ifndef ZORBA_STORE_COLLECTION_TREE_INFO_H
#define ZORBA_STORE_COLLECTION_TREE_INFO_H

#include <zorba/config.h>

namespace zorba
{

namespace simplestore
{

class Collection;
class StructuredItem;

/******************************************************************************
  Contains info about an XML or JSON tree that belongs to a collection, either
  directly or indirectly. A tree belongs to a collection "directly" if the
  collection stores a "pointer" to the root of the tree.  A tree belongs to a
  collection "indirectly" if it is pointed-to by a tree that belongs to the
  collection directly. Such indirect membership happens only when an XML tree
  is pointed-to by a JSON tree that belongs to a collection directly. Indirect
  membership cannot happen for JSON trees.

  A tree may belong to at most one collection at a time.

  A CollectionTreeInfo instance is created when a tree is attached to a collection
  (directly or indirectly) and is destroyed when the tree is detached from the
  collection. For XML trees, a pointer to this CollectionTreeInfo is stored in
  the XmlTree obj representing the tree. For JSON trees, a pointer to the
  CollectionTreeInfo is stored in each node of the tree. 

  Each tree within a collection must have an id that uniquely identifies the
  tree within the collection. 

  XML trees need a tree id even if they don't belong to a collection. As a
  result, XML trees store their id inside their associated XmlTree object.
  When an XML tree does not belong to a collection, its id uniquely identifies
  the tree among all the trees that do not belong to any collection. When an
  XML tree enters a collection, its tree id is updated so that is becomes
  unique within the target collection. When an XML tree exits a collection,
  its id is again updated appropriately.

  JSON trees need a tree id only while inside a collection. For this purpose,
  the CollectionTreeInfoWithTreeId subclass is use to provide the storage for
  the tree id.

  theCollection:
  --------------
  The collection where this tree belongs to.

  theRoot:
  --------
  The xml or json node that is directly stored in the collection. For JSON trees
  this is the root node of the tree. For XML trees, it is the root node of the 
  tree, if the tree belongs to the collection directly, or it is the root of a
  JSON tree that belongs to the collection directly and also points to the XML
  tree.

  thePosition:
  ------------
  The position of this tree within its containing collection. It is used as a
  hint to quickly retrieve the tree of a node within a collection.

  Very simple API (just getters and setters for each of the data members).
*******************************************************************************/

class CollectionTreeInfo
{
protected:
  Collection*     theCollection;
  xs_integer      thePosition;
  StructuredItem* theRoot;

public:
  CollectionTreeInfo()
    :
    theCollection(NULL),
    thePosition(0),
    theRoot(NULL)
  {
  }

  simplestore::Collection* getCollection() const
  {
    return theCollection;
  }

  void setCollection(simplestore::Collection* aCollection)
  {
    theCollection = aCollection;
  }

  StructuredItem* getRoot() const
  {
    return theRoot;
  }

  void setRoot(StructuredItem* aRoot)
  {
    theRoot = aRoot;
  }
  
  const xs_integer& getPosition() const
  {
    return thePosition;
  }

  void setPosition(const xs_integer& aPosition)
  {
    thePosition = aPosition;
  }
};


/******************************************************************************

*******************************************************************************/
class CollectionTreeInfoWithTreeId : public CollectionTreeInfo
{
private:
  TreeId  theTreeId;

public:
  CollectionTreeInfoWithTreeId() : theTreeId() {}

  simplestore::Collection* getCollection() const
  {
    return theCollection;
  }

  void setCollection(simplestore::Collection* aCollection)
  {
    theCollection = aCollection;
  }

  const TreeId& getTreeId() const
  {
    return theTreeId;
  }

  void setTreeId(const TreeId& aId)
  {
    theTreeId = aId;
  }

  StructuredItem* getRoot() const
  {
    return theRoot;
  }

  void setRoot(StructuredItem* aRoot)
  {
    theRoot = aRoot;
  }
  
  const xs_integer& getPosition() const
  {
    return thePosition;
  }

  void setPosition(const xs_integer& aPosition)
  {
    thePosition = aPosition;
  }
};


} // namespace simplestore
} // namespace zorba
#endif /* ZORBA_STORE_COLLECTION_TREE_INFO_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */

