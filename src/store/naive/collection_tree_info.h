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
  Contains info about a tree that is in a collection. Very simple API (just
  four fields and getters and setters for each of them).
*******************************************************************************/

class CollectionTreeInfo
{
private:
  Collection*     theCollection;
  TreeId          theId;
  xs_integer      thePosition;
  StructuredItem* theRoot;

public:
  CollectionTreeInfo()
    : theCollection(NULL),
      theId(),
      thePosition(0),
      theRoot(NULL)
  {}

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
    return theId;
  }

  void setTreeId(const TreeId& aId)
  {
    theId = aId;
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

