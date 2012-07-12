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
#ifndef ZORBA_SIMPLE_STORE_INDEX_HASH_VALUE
#define ZORBA_SIMPLE_STORE_INDEX_HASH_VALUE

#include "simple_index.h"
#include <map>

namespace zorba
{

namespace simplestore
{

/******************************************************************************

********************************************************************************/
class ValueIndexCompareFunction
{
private:
  csize                       theNumColumns;
  long                        theTimezone;
  std::vector<XQPCollator*>   theCollators;

public:
  ValueIndexCompareFunction(
       csize numCols,
       long timezone,
       const std::vector<std::string>& collation);

  ~ValueIndexCompareFunction();

  const XQPCollator* getCollator(ulong i) const { return theCollators[i]; }

  uint32_t hash(const store::IndexKey* key) const;

  bool equal(const store::IndexKey* key1, const store::IndexKey* key2) const;

  long compare(const store::IndexKey* key1, const store::IndexKey* key2) const;

  bool operator()(const store::IndexKey* key1, const store::IndexKey* key2) const
  {
    return compare(key1, key2) < 0;
  }
};


/**************************************************************************//**
  Class ValueIndexValue represents a value set as a vector of item handles.
*******************************************************************************/
class ValueIndexValue : public store::ItemVector
{
public:
  ValueIndexValue(ulong size = 0) : store::ItemVector(size) {}
};


/******************************************************************************

*******************************************************************************/
class ValueIndex : public IndexImpl
{
  friend class Store;

protected:
  ValueIndexCompareFunction   theCompFunction;

protected:
  ValueIndex(const store::Item_t& qname, const store::IndexSpecification& spec);
  
  ValueIndex();

  virtual ~ValueIndex();

public:
  const XQPCollator* getCollator(ulong i) const;

  virtual bool isTreeIndex() = 0;

  virtual bool insert(store::IndexKey*& key, store::Item_t& item) = 0;

  virtual bool remove(
        const store::IndexKey* key,
        const store::Item_t& item,
        bool all = false) = 0;
};


/******************************************************************************

*******************************************************************************/
class ValueHashIndex : public ValueIndex
{
  friend class Store;
  friend class ProbeValueHashIndexIterator;

  typedef HashMap<const store::IndexKey*,
                  ValueIndexValue*,
                  ValueIndexCompareFunction> IndexMap;

protected:

  class KeyIterator : public Index::KeyIterator
  {
  protected:
    IndexMap::iterator   theIterator;
    const IndexMap     & theMap;

  public:
    KeyIterator(const IndexMap& aMap);

    ~KeyIterator();

    void open();
    bool next(store::IndexKey&);
    void close();
  };

  typedef rchandle<KeyIterator> KeyIterator_t;

private:
  IndexMap  theMap;

protected:
  ValueHashIndex(
      const store::Item_t& qname,
      const store::IndexSpecification& spec);
      
  ValueHashIndex();

  ~ValueHashIndex();

public:
  bool isTreeIndex() { return false; }

  void clear();

  ulong size() const;

  Index::KeyIterator_t keys() const;

  bool insert(store::IndexKey*& key, store::Item_t& item);

  bool remove(const store::IndexKey* key, const store::Item_t& item, bool all);
};


/******************************************************************************
  Iterator to probe a hash-based value index
********************************************************************************/
class ProbeValueHashIndexIterator : public store::IndexProbeIterator
{
protected:
  rchandle<ValueHashIndex>               theIndex;

  rchandle<IndexPointCondition>          theCondition;

  ValueIndexValue                      * theResultSet;
  ValueIndexValue::const_iterator        theIte;
  ValueIndexValue::const_iterator        theEnd;

public:
  ProbeValueHashIndexIterator(const store::Index_t& index) : theResultSet(NULL)
  {
    theIndex = static_cast<ValueHashIndex*>(index.getp());
  }

  void init(const store::IndexCondition_t& cond);

  void open();

  bool next(store::Item_t& result);

  void reset();

  void close();

  void count(store::Item_t& result);
};


/******************************************************************************

********************************************************************************/
class ValueTreeIndex : public ValueIndex
{
  friend class Store;
  friend class ProbeValueTreeIndexIterator;

  typedef std::pair<const store::IndexKey*, ValueIndexValue*> IndexMapPair;

  typedef std::map<const store::IndexKey*,
                   ValueIndexValue*,
                   ValueIndexCompareFunction> IndexMap;

  class KeyIterator : public Index::KeyIterator
  {
  protected:
    IndexMap::const_iterator   theIterator;
    const IndexMap           & theMap;

  public:
    KeyIterator(const IndexMap& aMap);
    ~KeyIterator();

    void open();
    bool next(store::IndexKey&);
    void close();
  };

  typedef rchandle<KeyIterator> KeyIterator_t;

private:
  IndexMap          theMap;

  SYNC_CODE(Mutex   theMapMutex;)

protected:
  ValueTreeIndex(
        const store::Item_t& qname,
        const store::IndexSpecification& spec);
        
  ValueTreeIndex();

  ~ValueTreeIndex();

public:
  bool isTreeIndex() { return true; }

  void clear();

  ulong size() const;

  Index::KeyIterator_t keys() const;

  bool insert(store::IndexKey*& key, store::Item_t& item);

  bool remove(const store::IndexKey* key, const store::Item_t& item, bool all = false);
};


/*******************************************************************************
  Iterator to probe a tree-based value index
********************************************************************************/
class ProbeValueTreeIndexIterator : public store::IndexProbeIterator
{
protected:
  rchandle<ValueTreeIndex>                  theIndex;

  rchandle<IndexPointCondition>             thePointCond;
  rchandle<IndexBoxValueCondition>          theBoxCond;

  bool                                      theDoExtraFiltering;

  ValueTreeIndex::IndexMap::const_iterator  theMapBegin;
  ValueTreeIndex::IndexMap::const_iterator  theMapEnd;
  ValueTreeIndex::IndexMap::const_iterator  theMapIte;

  ValueIndexValue                         * theResultSet;
  ValueIndexValue::const_iterator           theIte;
  ValueIndexValue::const_iterator           theEnd;

protected:
  void initExact();

  void initBox();

public:
  ProbeValueTreeIndexIterator(const store::Index_t& index)
    :
    theDoExtraFiltering(true),
    theResultSet(NULL)
  {
    theIndex = reinterpret_cast<ValueTreeIndex*>(index.getp());
  }

  void init(const store::IndexCondition_t& cond);

  void open();

  bool next(store::Item_t& result);

  void reset();

  void close();

  void count(store::Item_t& result);
};


}
}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
