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

class JSONVisitor;

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

  SchemaTypeCode getTypeCode() const { return XS_UNTYPED_ATOMIC; }

#if 0
  bool equals(
        const store::Item* other,
        long timezone = 0,
        const XQPCollator* collation = 0) const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  store::Item* getType() const;

  SchemaTypeCode getTypeCode() const;

  bool getBooleanValue() const { return false; }
#endif
};


/******************************************************************************

*******************************************************************************/

class JSONItem : public store::Item
{
protected:
  SYNC_CODE(mutable RCLock  theRCLock;)
public:
  SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })

  JSONItem() : store::Item(JSONIQ) {}

  virtual ~JSONItem() {}

  store::StoreConsts::JSONItemKind
  getJSONItemKind() const { return store::StoreConsts::jsonItem; }

  virtual void
  accept(JSONVisitor*) const = 0;
};


/******************************************************************************

*******************************************************************************/

class JSONObject : public JSONItem
{
public:
  virtual ~JSONObject() {}

  bool isJSONObject() const { return true; }

  virtual void
  add(const JSONObjectPair_t& aPair) = 0;

  virtual xs_integer
  getSize() const = 0;

  store::StoreConsts::JSONItemKind
  getJSONItemKind() const { return store::StoreConsts::jsonObject; }

#if 0
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

  bool equals(
        const store::Item*,
        long = 0,
        const XQPCollator* = 0) const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  virtual store::Item* copy(
        store::Item* parent,
        const store::CopyMode&) const;
#endif
};


/******************************************************************************

*******************************************************************************/

class SimpleJSONObject : public JSONObject
{
protected:
  struct JSONObjectPairComparator
  {
    bool operator() (
      const JSONObjectPair_t& lhs,
      const JSONObjectPair_t& rhs) const;
  };

  typedef std::set<JSONObjectPair_t, JSONObjectPairComparator> Pairs;
  typedef Pairs::const_iterator PairsConstIter;
  typedef Pairs::iterator PairsIter;

  Pairs thePairs;

public:
  virtual ~SimpleJSONObject() {}

  void
  add(const JSONObjectPair_t& aPair);

  xs_integer
  getSize() const { return thePairs.size(); }

#if 0
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

  bool equals(
        const store::Item*,
        long = 0,
        const XQPCollator* = 0) const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  virtual store::Item* copy(
        store::Item* parent,
        const store::CopyMode&) const;
#endif

  virtual void
  accept(JSONVisitor*) const;
};


/******************************************************************************

*******************************************************************************/

class JSONArray : public JSONItem
{
public:
  virtual ~JSONArray() {}

  bool isJSONArray() const { return true; }

  store::StoreConsts::JSONItemKind
  getJSONItemKind() const { return store::StoreConsts::jsonArray; }

#if 0
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
#endif

  virtual void
  push_back(const store::Item_t& aValue) = 0;

  virtual xs_integer
  getSize() const = 0;

  virtual const store::Item*
  operator[](xs_integer&) const = 0;


};


/******************************************************************************

*******************************************************************************/

class SimpleJSONArray : public JSONArray
{
protected:
  typedef std::vector<store::Item_t> Pairs;
  typedef Pairs::const_iterator PairsConstIter;
  typedef Pairs::iterator PairsIter;

  Pairs theContent;

public:
  virtual ~SimpleJSONArray() {}

#if 0
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
#endif

  virtual void
  accept(JSONVisitor*) const;

  virtual void
  push_back(const store::Item_t& aValue);

  virtual xs_integer
  getSize() const { return theContent.size(); }

  virtual const store::Item*
  operator[](xs_integer&) const;
};


/******************************************************************************

*******************************************************************************/
class JSONObjectPair : public JSONItem
{
public:
  virtual ~JSONObjectPair() {}

  bool isJSONObject() const { return true; }

  virtual void
  setName(const store::Item_t& aName) = 0;

  virtual void
  setValue(const store::Item_t& aValue)  = 0;

  virtual void
  setContainer(JSONObject* aContainer)  = 0;

  virtual store::Item*
  getName() const = 0;

  virtual store::Item*
  getValue() const = 0;

  virtual store::Item*
  getContainer() const = 0;

  virtual void
  accept(JSONVisitor*) const {}

  store::StoreConsts::JSONItemKind
  getJSONItemKind() const { return store::StoreConsts::jsonPair; }
};


/******************************************************************************

*******************************************************************************/
class SimpleJSONObjectPair : public JSONObjectPair
{
protected:
  store::Item_t theName;
  store::Item_t theValue;
  JSONObject*   theContainer;

public:
  SimpleJSONObjectPair() {}

  SimpleJSONObjectPair(const store::Item_t& aName, const store::Item_t& aValue)
    :
    theName(aName),
    theValue(aValue),
    theContainer(0)
  {
  }

  virtual ~SimpleJSONObjectPair() {}

  zstring getStringValue() const { return theValue->getStringValue(); }

  void getStringValue2(zstring& val) const { theValue->getStringValue2(val); }

  void appendStringValue(zstring& buf) const { theValue->appendStringValue(buf); }
  
  void
  setName(const store::Item_t& aName) { theName = aName; }

  void
  setValue(const store::Item_t& aValue) { theValue = aValue; }

  void
  setContainer(JSONObject* aContainer) { theContainer = aContainer; }

  store::Item*
  getName() const { return theName.getp(); }

  store::Item*
  getValue() const { return theValue.getp(); }

  store::Item*
  getContainer() const { return theContainer; }

  virtual void
  accept(JSONVisitor*) const {}
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
