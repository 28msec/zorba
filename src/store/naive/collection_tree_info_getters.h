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

#ifndef ZORBA_STORE_COLLECTION_TREE_INFO_GETTERS_H
#define ZORBA_STORE_COLLECTION_TREE_INFO_GETTERS_H

#include <zorba/config.h>

#include "json_items.h"
#include "node_items.h"

namespace zorba
{

namespace simplestore
{

class CollectionTreeInfoGetters
{
public:
  static StructuredItem* getRoot(const store::Item* lItem)
  {
    if (lItem->isNode())
    {
      const simplestore::XmlNode* lNode =
          static_cast<const simplestore::XmlNode*>(lItem);
      CollectionTreeInfoWithoutTreeId* lInfo = lNode->getTree()->theCollectionInfo;
      return lInfo ? lInfo->getRoot() : NULL;
    }
    if (lItem->isJSONItem())
    {
      const simplestore::json::JSONItem* lJSON =
          static_cast<const simplestore::json::JSONItem*>(lItem);
      CollectionTreeInfo* lInfo = lJSON->theCollectionInfo;
      return lInfo ? lInfo->getRoot() : NULL;
    }
    assert(false);
    return NULL;
  }

  static StructuredItem* getRoot(const simplestore::XmlTree* aTree)
  {
    CollectionTreeInfoWithoutTreeId* lInfo = aTree->theCollectionInfo;
    return lInfo ? lInfo->getRoot() : NULL;
  }
};


} // namespace simplestore
} // namespace zorba
#endif /* ZORBA_STORE_COLLECTION_TREE_INFO_GETTERS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */

