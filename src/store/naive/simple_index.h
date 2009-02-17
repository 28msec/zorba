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
#ifndef ZORBA_SIMPLE_STORE_INDEX
#define ZORBA_SIMPLE_STORE_INDEX

#include "common/shared_types.h"

#include "zorbautils/hashmap.h"

#include "store/api/index.h"
#include "store/api/iterator.h"


namespace zorba 
{ 

namespace simplestore 
{

typedef std::vector<store::Item_t> ValueSet;


/******************************************************************************

********************************************************************************/
class IndexImpl : public store::Index
{
protected:  
  store::Item_t                   theUri;
  store::IndexSpecification       theSpec;
  ulong                           theNumKeyComps;
  std::vector<XQPCollator*>       theCollators;

public:
  IndexImpl(
        const xqpStringStore_t& uri,
        const store::IndexSpecification& spec);

  virtual ~IndexImpl();

  store::Item* getUri() const { return theUri.getp(); }

  const store::IndexSpecification& getSpecification() const { return theSpec; }

  bool isUnique() const { return theSpec.theIsUnique; }

  bool isOrdering() const { return theSpec.theIsOrdering; }

  bool isTemporary() const { return theSpec.theIsTemp; }

  bool isThreadSafe() const { return theSpec.theIsThreadSafe; }
};



/******************************************************************************

********************************************************************************/
class HashIndex : public IndexImpl
{
  friend class SimpleStore;
  friend class HashIndexProbeIterator;

protected:

  class CompareFunction
  {
    friend class HashIndex;

  private:
    ulong                       theNumKeyComps;
    long                        theTimezone;
    std::vector<XQPCollator*>   theCollators;

  public:
    CompareFunction(
       ulong numKeyComps,
       long timezone,
       const std::vector<XQPCollator*>& collators)
      :
      theNumKeyComps(numKeyComps),
      theTimezone(timezone),
      theCollators(collators)
    {
    }

    uint32_t hash(const store::IndexKey* key) const;

    bool equal(const store::IndexKey* key1, const store::IndexKey* key2) const;
  };


  typedef  HashMap<store::IndexKey*, ValueSet*, CompareFunction> IndexMap;


private:
  CompareFunction   theCompFunction;
  IndexMap          theMap;

public:
  bool insert(store::IndexKey& key, store::Item_t& value);

  bool remove(const store::IndexKey& key, store::Item_t& value);

protected:
  HashIndex(
        const xqpStringStore_t& uri,
        const store::IndexSpecification& spec);

  ~HashIndex();
};


/******************************************************************************

********************************************************************************/
class HashIndexProbeIterator : public store::IndexProbeIterator
{
protected:
  rchandle<HashIndex>         theIndex;

  store::IndexKey           * theKey;

  ValueSet                  * theResultSet;
  ValueSet::const_iterator    theIte;
  ValueSet::const_iterator    theEnd;

public:
  HashIndexProbeIterator(const store::Index_t& index) 
    :
    theKey(NULL),
    theResultSet(NULL)
  {
    theIndex = reinterpret_cast<HashIndex*>(index.getp());
  }

  void init(store::IndexKey& key);

  void init(
        store::IndexKey& lowKey,
        store::IndexKey& highKey,
        bool lowInclusive,
        bool highInclusive);

  void open();

  store::Item* next();
    
  bool next(store::Item_t& result);
  
  void reset();

  void close();
};


/******************************************************************************

********************************************************************************/
class STLMapIndex : public IndexImpl
{
  friend class SimpleStore;
  friend class STLMapIndexProbeIterator;

  typedef std::pair<store::IndexKey*, ValueSet*> STLMapPair;

protected:

  class CompareFunction
  {
    friend class OrdringIndex;

  private:
    ulong                       theNumKeyComps;
    long                        theTimezone;
    std::vector<XQPCollator*>   theCollators;

  public:
    CompareFunction(
       ulong numKeyComps,
       long timezone,
       const std::vector<XQPCollator*>& collators)
      :
      theNumKeyComps(numKeyComps),
      theTimezone(timezone),
      theCollators(collators)
    {
    }

    bool operator()(const store::IndexKey* key1, const store::IndexKey* key2) const
    {
      return compare(key1, key2) < 0;
    }

    bool operator()(const STLMapPair& val1, const STLMapPair& val2) const
    {
      return compare(val1.first, val2.first) < 0;
    }

    long compare(const store::IndexKey* key1, const store::IndexKey* key2) const;
  };


  typedef std::map<store::IndexKey*, ValueSet*, CompareFunction> IndexMap;

private:
  CompareFunction   theCompFunction;
  IndexMap          theMap;
  SYNC_CODE(Mutex   theMapMutex;)

public:
  bool insert(store::IndexKey& key, store::Item_t& value);

  bool remove(const store::IndexKey& key, store::Item_t& value);

protected:
  STLMapIndex(
        const xqpStringStore_t& uri,
        const store::IndexSpecification& spec);

  ~STLMapIndex();
};


/******************************************************************************

********************************************************************************/
class STLMapIndexProbeIterator : public store::IndexProbeIterator
{
protected:
  rchandle<STLMapIndex>            theIndex;

  store::IndexKey                * theLowKey;
  store::IndexKey                * theHighKey;
  bool                             theLowIncl;
  bool                             theHighIncl;

  STLMapIndex::IndexMap::iterator  theMapBegin;
  STLMapIndex::IndexMap::iterator  theMapEnd;
  STLMapIndex::IndexMap::iterator  theMapIte;

  ValueSet                       * theResultSet;
  ValueSet::const_iterator         theIte;
  ValueSet::const_iterator         theEnd;

public:
  STLMapIndexProbeIterator(const store::Index_t& index) 
    :
    theLowKey(NULL),
    theHighKey(NULL),
    theResultSet(NULL)
  {
    theIndex = reinterpret_cast<STLMapIndex*>(index.getp());
  }

  void init(store::IndexKey& key);

  void init(
        store::IndexKey& lowKey,
        store::IndexKey& highKey,
        bool lowInclusive,
        bool highInclusive);

  void open();

  store::Item* next();
    
  bool next(store::Item_t& result);
  
  void reset();

  void close();
};

}
}

#endif
