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

#include <zorba/config.h>
#include "util/unordered_map.h"

#include "diagnostics/assert.h"

#include "store/api/item_handle.h"
#include "store/api/iterator.h"

#include "atomic_items.h"
#include "collection_tree_info.h"
#include "simple_collection.h"
#include "structured_item.h"


namespace zorba
{

namespace store
{
class CopyMode;
}

namespace simplestore
{

class CollectionTreeInfoGetters;

namespace json
{

/******************************************************************************

*******************************************************************************/

class JSONNull : public AtomicItem
{
protected:
  SYNC_CODE(mutable RCLock  theRCLock;)

public:
  JSONNull() : AtomicItem(store::JS_NULL) { }

  virtual ~JSONNull() {}

  SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })

  zstring getStringValue() const { return "null"; }

  void getStringValue2(zstring& val) const { val = "null"; }

  void appendStringValue(zstring& buf) const { buf += "null"; }

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  store::SchemaTypeCode getTypeCode() const { return store::JS_NULL; }

  store::Item* getType() const; 

  bool equals(
      const store::Item* other,
      long timezone = 0,
      const XQPCollator* collation = 0) const;

  uint32_t hash(long timezone = 0, const XQPCollator* aCollation = 0) const;

  bool getEBV() const { return false; }
};


/******************************************************************************

*******************************************************************************/

class JSONItem : public StructuredItem
{
  // Used to access collection tree information.
  friend class zorba::simplestore::CollectionTreeInfoGetters;

protected:
  SYNC_CODE(mutable RCLock  theRCLock;)

  CollectionTreeInfo * theCollectionInfo;

public:
  SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })

  JSONItem() : StructuredItem(store::Item::JSONIQ), theCollectionInfo(NULL) {}

  virtual ~JSONItem();
  
  virtual void free();

  virtual void destroy();

  // StructuredItem API

  void attachToCollection(
      Collection* aCollection,
      const TreeId& aTreeId,
      const xs_integer& aPosition);

  void detachFromCollection();
  
  virtual void setCollectionTreeInfo(CollectionTreeInfo* collectionInfo) = 0;
  
  virtual bool isRoot() const
  {
    return theCollectionInfo != NULL &&
        theCollectionInfo->getRoot() == this;
  }

  virtual long getCollectionTreeRefCount() const;

  const xs_integer& getPosition() const
  {
    ZORBA_ASSERT(theCollectionInfo);
    return theCollectionInfo->getPosition();
  }
  
  void setPosition(const xs_integer& pos)
  {
    ZORBA_ASSERT(theCollectionInfo);
    theCollectionInfo->setPosition(pos); 
  }

  // store API

  const store::Collection* getCollection() const
  {
    return (theCollectionInfo ? theCollectionInfo->getCollection() : NULL);
  }

  virtual bool equals(
      const store::Item* other,
      long timezone = 0,
      const XQPCollator* aCollation = 0) const
  {
    return this == other;
  }

public:
#ifndef NDEBUG
  virtual void assertInvariant() const;

  virtual bool isThisTreeOfAllDescendants(
      const CollectionTreeInfo* collectionInfo) const = 0;
#endif
};


/******************************************************************************

*******************************************************************************/

class JSONObject : public JSONItem
{
public:
  virtual ~JSONObject() {}

  // store API

  virtual store::StoreConsts::JSONItemKind getJSONItemKind() const 
  {
    return store::StoreConsts::jsonObject;
  }

  virtual bool isJSONObject() const { return true; }

  virtual store::Iterator_t getObjectKeys() const = 0;

  virtual store::Item_t getObjectValue(const store::Item_t& aKey) const = 0;

  virtual Item* getType() const;

  // updates
  
  virtual bool add(
      const store::Item_t& aName,
      const store::Item_t& aValue,
      bool accumulate) = 0;

  virtual store::Item_t remove(const store::Item_t& aName) = 0;

  virtual store::Item_t setValue(
    const store::Item_t& aName,
    const store::Item_t& aValue) = 0;
    
  virtual bool rename(
    const store::Item_t& aName,
    const store::Item_t& aNewName) = 0;
};


/******************************************************************************

*******************************************************************************/

class SimpleJSONObject : public JSONObject
{
protected:
  class ConstCharStarHash
  {
  public:
    typedef size_t result_type;
    size_t operator()(const char* a) const
    {
      size_t hash = 5381;
      int c;

      while ((c = *a++))
        hash = ((hash << 5) + hash) + c;

      return hash;
    }
  };

  class ConstCharStarComparator
  {
  public:
    bool operator()(const char* a, const char* b) const
    {
      return strcmp(a, b) == 0;
    }
  };

  typedef std::unordered_map<
    const char*,
    csize,
    ConstCharStarHash,
    ConstCharStarComparator> Keys;
  typedef std::vector<std::pair<store::Item*, store::Item*> > Pairs;

  class KeyIterator : public store::Iterator
  {
    protected:
      SimpleJSONObject_t  theObject;
      Pairs::iterator     theIter;

    public:
      KeyIterator(const SimpleJSONObject_t& aObject) : theObject(aObject) {}

      virtual ~KeyIterator();

      virtual void open();

      virtual bool next(store::Item_t&);

      virtual void reset();

      virtual void close();
  };

private:
  Keys   theKeys;
  Pairs  thePairs;

public:
  SimpleJSONObject()
  {}

  virtual ~SimpleJSONObject();

  // store API

  virtual store::Iterator_t getObjectKeys() const;

  virtual store::Item_t getObjectValue(const store::Item_t& aKey) const;

  virtual store::Item* copy(
      store::Item* parent,
      const store::CopyMode& copymode) const;

  virtual zstring getStringValue() const;

  virtual void getStringValue2(zstring& val) const;

  virtual void appendStringValue(zstring& buf) const;

  virtual void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  // updates
  
  virtual bool add(
      const store::Item_t& aName,
      const store::Item_t& aValue,
      bool accumulate);

  virtual store::Item_t remove(const store::Item_t& aName);

  virtual store::Item_t setValue(
      const store::Item_t& aName,
      const store::Item_t& aValue);
    
  virtual bool rename(
      const store::Item_t& aName,
      const store::Item_t& aNewName);

  // StructuredItem API

  void setCollectionTreeInfo(CollectionTreeInfo* collectionInfo);

  bool isInSubtree(const StructuredItem* aJSONItem) const;

  virtual void swap(store::Item* anotherItem);

  // Invariant handling
#ifndef NDEBUG
  void assertInvariant() const;
  
  bool isThisTreeOfAllDescendants(const CollectionTreeInfo* collectionInfo) const;
#endif
};


/******************************************************************************

*******************************************************************************/

class JSONArray : public JSONItem
{
public:
  JSONArray() : JSONItem() {}

  virtual ~JSONArray() {}

  // store API
  
  bool isJSONArray() const { return true; }

  store::StoreConsts::JSONItemKind
  getJSONItemKind() const { return store::StoreConsts::jsonArray; }

  virtual store::Item*
  getType() const;
  
  virtual xs_integer getArraySize() const = 0;

  virtual store::Item_t getArrayValue(const xs_integer& position) const = 0;

  virtual store::Iterator_t getArrayValues() const = 0;

  // updates

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
};


/******************************************************************************

*******************************************************************************/

class SimpleJSONArray : public JSONArray
{
protected:
  typedef std::vector<store::Item*> Members;

  class ValuesIterator : public store::Iterator
  {
  protected:
    SimpleJSONArray_t theArray;
    Members::iterator theIter;

  public:
    ValuesIterator(const SimpleJSONArray_t& anArray) : theArray(anArray) {}

    virtual ~ValuesIterator();
    
    virtual void open();

    virtual bool next(store::Item_t&);

    virtual void reset();

    virtual void close();
  };

private:
  Members theContent;

public:
  SimpleJSONArray()
  {}

  virtual ~SimpleJSONArray();

  // store API

  xs_integer getArraySize() const;

  store::Item_t getArrayValue(const xs_integer& position) const;
  
  store::Iterator_t getArrayValues() const;

  store::Item* copy(
      store::Item* parent,
      const store::CopyMode& copymode) const;

  zstring getStringValue() const;

  void getStringValue2(zstring& val) const;

  void appendStringValue(zstring& buf) const;

  void getTypedValue(store::Item_t& val, store::Iterator_t& iter) const;

  // updates
  
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

  // StructuredItem API
  
  void setCollectionTreeInfo(CollectionTreeInfo* collectionInfo);

  virtual void swap(Item* anotherItem);

  bool isInSubtree(const StructuredItem* aJSONItem) const;

protected:
  void add(uint64_t pos, const std::vector<store::Item_t>& aNewMembers);

  static uint64_t cast(const xs_integer& i);

  // Invariant handling
public:
#ifndef NDEBUG
  bool isThisTreeOfAllDescendants(const CollectionTreeInfo* colectionInfo) const;
#endif
};


#ifndef NDEBUG
#define ASSERT_INVARIANT() assertInvariant()
#else
#define ASSERT_INVARIANT()
#endif

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

