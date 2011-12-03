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

#ifndef ZORBA_STORE_JSON_ITEMS_H
#define ZORBA_STORE_JSON_ITEMS_H

#include <vector>
#include <set>

#include <zorba/config.h>
#include "atomic_items.h"
#include "store/api/item_handle.h"


namespace zorba
{

namespace store
{
class CopyMode;
}

namespace simplestore
{

namespace json
{

class JSONItem;
class JSONObject;
class JSONArray;
class JSONObjectPair;
class JSONArrayPair;

typedef store::ItemHandle<JSONItem>       JSONItem_t;
typedef store::ItemHandle<JSONObject>     JSONObject_t;
typedef store::ItemHandle<JSONArray>      JSONArray_t;
typedef store::ItemHandle<JSONObjectPair> JSONObjectPair_t;
typedef store::ItemHandle<JSONArrayPair>  JSONArrayPair_t;

/******************************************************************************

*******************************************************************************/

class JSONNull : public AtomicItem
{
protected:
  SYNC_CODE(mutable RCLock  theRCLock;)

public:
  JSONNull() : AtomicItem() { }

  virtual ~JSONNull() {}

  SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })

  zstring getStringValue() const { return "null"; }

  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  store::Item* getType() const;

  SchemaTypeCode getTypeCode() const;

  bool getBooleanValue() const { return false; }
};


/******************************************************************************

*******************************************************************************/

class JSONTree
{
protected:
  mutable long              theRefCount;
  SYNC_CODE(mutable RCLock  theRCLock;)

public:
  JSONTree();

  ~JSONTree() {}

  void free();

  long getRefCount() const { return theRefCount; }

  long& getRefCount()      { return theRefCount; }

  SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })
};


/******************************************************************************

*******************************************************************************/

class JSONItem : public store::Item
{
public:
  virtual ~JSONItem() {}

private:
  void setTree(const JSONTree* t)
  {
    theUnion.treeRCPtr = (long*)t;
  }
};


/******************************************************************************

*******************************************************************************/

class JSONObject : public JSONItem
{
protected:
  struct JSONObjectPairComparator
  {
    bool operator() (
      const JSONObjectPair& lhs,
      const JSONObjectPair& rhs) const;
  };

  std::set<JSONObjectPair_t, JSONObjectPairComparator>  thePairs;

public:
  virtual ~JSONObject() {}

  // accessors
  virtual store::Iterator_t
  pairs() const;

  bool getBooleanValue() const { return true; }

  virtual Item*
  getType() const;

  // 
  // convenience accessors pushed down for performance
  virtual store::Item*
  lookup(const store::Item_t& name) const;

  //
  //
  bool equals(
        const store::Item*,
        long = 0,
        const XQPCollator* = 0) const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  virtual store::Item* copy(
        store::Item* parent,
        const store::CopyMode&) const;
};


/******************************************************************************

*******************************************************************************/

class JSONArray : public JSONItem
{
protected:
  std::vector<JSONArrayPair_t> theContent;

public:
  virtual ~JSONArray() {}

  // accessors
  virtual store::Iterator_t
  pairs() const;

  bool getBooleanValue() const { return true; }

  virtual store::Item*
  getType() const;

  // 
  // convenience accessors pushed down for performance
  virtual store::Item*
  lookup(const store::Item_t& index) const;

};


/******************************************************************************

*******************************************************************************/

class JSONObjectPair : public JSONItem
{
protected:
  store::Item_t theName;
  store::Item_t theValue;
  JSONObject*   theContainer;

public:
  virtual ~JSONObjectPair() {}

  store::Item*
  getName() const { return theName.getp(); }

  store::Item*
  getValue() const { return theValue.getp(); }

  store::Item*
  getContainer() const { return theContainer; }
};


/******************************************************************************

*******************************************************************************/

class JSONArrayPair : public JSONItem
{
protected:
  store::Item_t thePosition;
  store::Item_t theValue;
  JSONArray*    theContainer;

public:
  virtual ~JSONArrayPair() {}

  store::Item*
  getPosition() const { return thePosition.getp(); }

  store::Item*
  getValue() const { return theValue.getp(); }

  store::Item*
  getContainer() const { return theContainer; }
};

} // namespace json
} // namespace simplestore
} // namespace zorba
#endif /* ZORBA_STORE_JSON_ITEMS_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
