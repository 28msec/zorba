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
#ifndef ZORBA_TREE_ID_H
#define ZORBA_TREE_ID_H

#include "store/naive/shared_types.h"
#include "zorbautils/hashmap_itemh.h"

namespace zorba {

class TreeId {
public:
  virtual ~TreeId() {}
public:
  virtual zstring toString() = 0;
  virtual TreeId* copy() = 0;
};

typedef std::auto_ptr<TreeId> TreeId_t;

class ZorbaTreeId : public TreeId {
friend class ZorbaTreeIdGenerator;
private:
  ulong theId;
  const zorba::store::Item_t theCollectionName;
  ZorbaTreeId(zorba::store::Item_t aName, ulong idKey);
public:
  zstring toString();  
  virtual TreeId* copy();
};

class TreeIdGenerator {
public:
  virtual ~TreeIdGenerator() {};

  virtual TreeId_t create(zorba::store::Item_t aCollectionName) = 0;
  virtual bool equals(const TreeId_t& id1, const TreeId_t& id2) = 0;
  virtual bool isBefore(const TreeId_t& id1, const TreeId_t& id2) = 0;
  virtual TreeId* fromString(const zstring&) = 0;
};

class ZorbaTreeIdGenerator : public TreeIdGenerator {
private:
  zorba::ItemHandleHashMap<ulong> theNextIds;
  ulong theNextStoreWideId;
public:
  ZorbaTreeIdGenerator() : theNextIds(0, NULL, 64, false), theNextStoreWideId(0) {}
  virtual TreeId_t create(zorba::store::Item_t aCollectionName);
  virtual bool equals(const TreeId_t& id1, const TreeId_t& id2);
  virtual bool isBefore(const TreeId_t& id1, const TreeId_t& id2);
  virtual TreeId* fromString(const zstring&);
};

}

#endif /* ZORBA_TREE_ID_H */
