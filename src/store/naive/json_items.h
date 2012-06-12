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
#include "simple_collection.h"
#include "store/api/item_handle.h"
#include "store/api/iterator.h"


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

  void
  getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  store::SchemaTypeCode getTypeCode() const { return store::JDM_NULL; }

  store::Item* getType() const; 

  bool 
  equals(
      const store::Item* other,
      long timezone = 0,
      const XQPCollator* collation = 0) const;

  uint32_t 
  hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool
  getEBV() const { return false; }
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

  bool 
  equals(
      const store::Item* other,
      long timezone = 0,
      const XQPCollator* aCollation = 0) const
  {
    return this == other;
  }
  
};


/******************************************************************************

*******************************************************************************/

class JSONObject : public JSONItem
{
public:
  virtual ~JSONObject() {}

  store::StoreConsts::JSONItemKind getJSONItemKind() const 
  {
    return store::StoreConsts::jsonObject;
  }

  bool isJSONObject() const { return true; }

  virtual bool add(
      const zstring& aName,
      const store::Item_t& aValue,
      bool accumulate) = 0;

  virtual store::Item_t remove(const zstring& aName) = 0;

  virtual store::Item_t setValue(
    const zstring& aName,
    const store::Item_t& aValue) = 0;
    
  virtual bool rename(
    const zstring& aName,
    const zstring& aNewName) = 0;
    
  virtual store::Iterator_t getObjectKeys() const = 0;

  virtual store::Item_t getObjectValue(
      const zstring& aKey) const = 0;

  bool getBooleanValue() const { return true; }

  virtual Item* getType() const;

  virtual SimpleCollection* getCollection() const = 0;

  virtual void setCollection(SimpleCollection* collection, xs_integer pos) = 0;

#if 0
  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  virtual store::Item* copy(store::Item* parent, const store::CopyMode&) const;
#endif
};


/******************************************************************************

*******************************************************************************/

class SimpleJSONObject : public JSONObject
{
protected:
  typedef std::map<zstring, store::Item_t> Pairs;

  Pairs thePairs;

  SimpleCollection* theCollection;

  class KeyIterator : public store::Iterator
  {
    protected:
      SimpleJSONObject_t    theObject;
      Pairs::iterator theIter;

    public:
      KeyIterator(const SimpleJSONObject_t& aObject) : theObject(aObject) {}

      virtual ~KeyIterator();

      virtual void open();

      virtual bool next(store::Item_t&);

      virtual void reset();

      virtual void close();
  };

public:
  SimpleJSONObject()
    : theCollection(0) {}

  virtual ~SimpleJSONObject();

  bool add(
      const zstring& aName,
      const store::Item_t& aValue,
      bool accumulate);

  store::Item_t remove(const zstring& aName);

  store::Item_t setValue(
    const zstring& aName,
    const store::Item_t& aValue);
    
  bool rename(
    const zstring& aName,
    const zstring& aNewName);

  store::Iterator_t getObjectKeys() const;

  store::Item_t getObjectValue(
      const zstring& aKey) const;

  store::Item* copy(
      store::Item* parent,
      const store::CopyMode& copymode) const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  virtual SimpleCollection* getCollection() const { return theCollection; }

  void setCollection(SimpleCollection* collection, xs_integer pos);
};


/******************************************************************************

*******************************************************************************/

class JSONArray : public JSONItem
{
public:
  JSONArray() : JSONItem() {}

  virtual ~JSONArray() {}

  bool isJSONArray() const { return true; }

  store::StoreConsts::JSONItemKind
  getJSONItemKind() const { return store::StoreConsts::jsonArray; }

  virtual store::Item*
  getType() const;

  virtual void
  push_back(const store::Item_t& aValue) = 0;

  virtual void
  push_back(const std::vector<store::Item_t>& members) = 0;

  virtual void
  push_front(const std::vector<store::Item_t>& members) = 0;

  virtual void
  insert_before(const xs_integer& pos, const store::Item_t& member) = 0;

  virtual void
  insert_before(const xs_integer& pos, const std::vector<store::Item_t>& members) = 0;

  virtual void
  insert_after(const xs_integer& pos, const std::vector<store::Item_t>& members) = 0;

  virtual store::Item_t
  remove(const xs_integer& pos) = 0;

  virtual store::Item_t
  replace(const xs_integer& pos, const store::Item_t& value) = 0;

  virtual store::Item_t getArraySize() const = 0;

  virtual store::Item_t getArrayValue(const xs_integer& position) const = 0;

  virtual store::Iterator_t getArrayValues() const = 0;

  virtual SimpleCollection* getCollection() const = 0;

  virtual void setCollection(SimpleCollection* collection, xs_integer pos) = 0;
};


/******************************************************************************

*******************************************************************************/

class SimpleJSONArray : public JSONArray
{
protected:
  typedef std::vector<store::Item_t> Members;

  Members            theContent;

  SimpleCollection * theCollection;

  class ValuesIterator : public store::Iterator
  {
    protected:
      SimpleJSONArray_t theArray;
      Members::iterator theIter;

    public:
      ValuesIterator(const SimpleJSONArray_t& anArray)
        : theArray(anArray) {}

      virtual ~ValuesIterator();

      virtual void open();

      virtual bool next(store::Item_t&);

      virtual void reset();

      virtual void close();
  };

public:
  SimpleJSONArray()
    :
    theCollection(0)
  {
  }

  virtual ~SimpleJSONArray();

  virtual void
  push_back(const store::Item_t& aValue);

  virtual void
  push_back(const std::vector<store::Item_t>& members);

  virtual void
  push_front(const std::vector<store::Item_t>& members);

  virtual void
  insert_before(const xs_integer& pos, const store::Item_t& member);

  virtual void
  insert_before(const xs_integer& pos, const std::vector<store::Item_t>& members);

  virtual void
  insert_after(const xs_integer& pos, const std::vector<store::Item_t>& members);

  virtual store::Item_t
  remove(const xs_integer& aPos);

  virtual store::Item_t
  replace(const xs_integer& aPos, const store::Item_t& value);

  store::Item_t getArraySize() const;

  store::Item_t getArrayValue(const xs_integer& position) const;
  
  store::Iterator_t getArrayValues() const;

  store::Item* copy(
      store::Item* parent,
      const store::CopyMode& copymode) const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  void
  getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  virtual SimpleCollection* getCollection() const { return theCollection; }

  void setCollection(SimpleCollection* collection, xs_integer pos);

protected:
  void
  add(uint64_t pos, const std::vector<store::Item_t>& aNewMembers);

  static uint64_t
  cast(const xs_integer& i);
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
