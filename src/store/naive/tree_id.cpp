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

#include "tree_id.h"

namespace zorba {
  
ZorbaTreeId::ZorbaTreeId(zorba::store::Item_t aName, ulong id)
: theId(id), theCollectionName(aName)
{};

zstring ZorbaTreeId::toString()
{
  zstring s = "" + theId;
  return s;
}

TreeId* ZorbaTreeId::copy()
{
  return new ZorbaTreeId(theCollectionName, theId);
}

TreeId_t ZorbaTreeIdGenerator::create(
    zorba::store::Item_t aCollectionName) {
  if (aCollectionName == NULL)
  {
    TreeId_t lStoreRes(new ZorbaTreeId(NULL, theNextStoreWideId));
    ++theNextStoreWideId;
    return lStoreRes;
  }
  
  zorba::ItemHandleHashMap<ulong>::iterator lIt =
      theNextIds.find(aCollectionName);
  if (lIt == theNextIds.end())
  {
    ulong lStartingId = 0;
    theNextIds.insert(aCollectionName, lStartingId);
    lIt = theNextIds.find(aCollectionName);
    assert(lIt != theNextIds.end());
  }
  TreeId_t lRes (new ZorbaTreeId(lIt.getKey(), lIt.getValue()));
  lIt.setValue(lIt.getValue() + 1);
  return lRes;
}

bool ZorbaTreeIdGenerator::equals(const TreeId_t& anId,
                                  const TreeId_t& anotherId)
{
  const ZorbaTreeId* lId1 = dynamic_cast<ZorbaTreeId*>(anId.get());
  const ZorbaTreeId* lId2 = dynamic_cast<ZorbaTreeId*>(anotherId.get());
  return ((lId1->theCollectionName == NULL && lId2->theCollectionName == NULL) ||
             lId1->theCollectionName->equals(lId2->theCollectionName)) &&
         lId1->theId == lId2->theId;
}

bool ZorbaTreeIdGenerator::isBefore(const TreeId_t& anId,
                                   const TreeId_t& anotherId)
{
  const ZorbaTreeId* lId1 = dynamic_cast<ZorbaTreeId*>(anId.get());
  const ZorbaTreeId* lId2 = dynamic_cast<ZorbaTreeId*>(anotherId.get());
  assert((lId1->theCollectionName == NULL && lId2->theCollectionName == NULL) ||
      lId1->theCollectionName->equals(lId2->theCollectionName));
  return lId1->theId < lId2->theId;
}

TreeId* ZorbaTreeIdGenerator::fromString(const zstring&)
{
  return NULL;
}

}