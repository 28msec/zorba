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

#include "store/api/shared_types.h"

#include "zorbautils/hashmap.h"

#include "store/api/index.h"
#include "store/api/iterator.h"


namespace zorba 
{ 

namespace simplestore 
{

class IndexPointConditionImpl;
class IndexBoxConditionImpl;


/******************************************************************************

********************************************************************************/
class IndexImpl : public store::Index
{
protected:  
  store::Item_t                   theQname;
  store::IndexSpecification       theSpec;
  ulong                           theNumColumns;
  std::vector<XQPCollator*>       theCollators;

  std::vector<store::Item_t>      theSources;

public:
  IndexImpl(const store::Item_t& qname, const store::IndexSpecification& spec);

  virtual ~IndexImpl();

  store::Item* getName() const { return theQname.getp(); }

  const store::IndexSpecification& getSpecification() const { return theSpec; }

  ulong getNumColumns() const { return theNumColumns; }

  long getTimezone() const { return theSpec.theTimezone; }

  const std::vector<XQPCollator*>& getCollators() const { return theCollators; }

  const XQPCollator* getCollator(ulong i) const { return theCollators[i]; }
 
  bool isUnique() const { return theSpec.theIsUnique; }

  bool isSorted() const { return theSpec.theIsSorted; }

  bool isTemporary() const { return theSpec.theIsTemp; }

  bool isThreadSafe() const { return theSpec.theIsThreadSafe; }

  store::IndexPointCondition_t createPointCondition();

  store::IndexBoxCondition_t createBoxCondition();

  virtual bool insert(const store::IndexKey* key, store::Item_t& item) = 0;

  virtual bool remove(const store::IndexKey* key, store::Item_t& item) = 0;
};



/******************************************************************************

********************************************************************************/
class HashIndex : public IndexImpl
{
  friend class SimpleStore;
  friend class HashProbeIterator;

public:

  class CompareFunction
  {
    friend class HashIndex;

  private:
    ulong                              theNumColumns;
    long                               theTimezone;
    const std::vector<XQPCollator*>&   theCollators;

  public:
    CompareFunction(
       ulong numCols,
       long timezone,
       const std::vector<XQPCollator*>& collators)
      :
      theNumColumns(numCols),
      theTimezone(timezone),
      theCollators(collators)
    {
    }

    uint32_t hash(const store::IndexKey* key) const;

    bool equal(const store::IndexKey* key1, const store::IndexKey* key2) const;
  };


public:
  typedef HashMap<const store::IndexKey*, store::IndexValue*, CompareFunction> IndexMap;


private:
  CompareFunction   theCompFunction;
  IndexMap          theMap;

public:
  void clear();

  bool probe(const store::IndexKey& key, store::Item_t& result);

  bool insert(const store::IndexKey* key, store::Item_t& item);

  bool remove(const store::IndexKey* key, store::Item_t& item);

protected:
  HashIndex(
        const store::Item_t& qname,
        const store::IndexSpecification& spec);

  ~HashIndex();
};


/******************************************************************************

********************************************************************************/
class STLMapIndex : public IndexImpl
{
  friend class SimpleStore;
  friend class STLMapProbeIterator;

  typedef std::pair<const store::IndexKey*, store::IndexValue*> STLMapPair;

protected:

  class CompareFunction
  {
    friend class OrdringIndex;

  private:
    ulong                              theNumKeyComps;
    long                               theTimezone;
    const std::vector<XQPCollator*>&   theCollators;

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

    long compare(const store::IndexKey* key1, const store::IndexKey* key2) const;
  };


public:
  typedef std::map<const store::IndexKey*, store::IndexValue*, CompareFunction> IndexMap;

private:
  CompareFunction   theCompFunction;
  IndexMap          theMap;
  SYNC_CODE(Mutex   theMapMutex;)

public:
  void clear();

  bool probe(const store::IndexKey& key, store::Item_t& result);

  bool insert(const store::IndexKey* key, store::Item_t& item);

  bool remove(const store::IndexKey* key, store::Item_t& item);

protected:
  STLMapIndex(
        const store::Item_t& qname,
        const store::IndexSpecification& spec);

  ~STLMapIndex();
};


/******************************************************************************

********************************************************************************/
class HashProbeIterator : public store::IndexProbeIterator
{
protected:
  rchandle<HashIndex>                    theIndex;

  rchandle<IndexPointConditionImpl>      theCondition;

  store::IndexValue                    * theResultSet;
  store::IndexValue::const_iterator      theIte;
  store::IndexValue::const_iterator      theEnd;

public:
  HashProbeIterator(const store::Index_t& index) : theResultSet(NULL)
  {
    theIndex = static_cast<HashIndex*>(index.getp());
  }

  void init(const store::IndexCondition_t& cond);

  void open();

  bool next(store::Item_t& result);
  
  void reset();

  void close();
};


/*******************************************************************************

********************************************************************************/
class STLMapProbeIterator : public store::IndexProbeIterator
{
protected:
  rchandle<STLMapIndex>                    theIndex;

  rchandle<IndexPointConditionImpl>        thePointCond;
  rchandle<IndexBoxConditionImpl>          theBoxCond;

  bool                                     theDoExtraFiltering;

  STLMapIndex::IndexMap::const_iterator    theMapBegin;
  STLMapIndex::IndexMap::const_iterator    theMapEnd;
  STLMapIndex::IndexMap::const_iterator    theMapIte;

  store::IndexValue                      * theResultSet;
  store::IndexValue::const_iterator        theIte;
  store::IndexValue::const_iterator        theEnd;

public:
  STLMapProbeIterator(const store::Index_t& index) 
    :
    theDoExtraFiltering(true),
    theResultSet(NULL)
  {
    theIndex = reinterpret_cast<STLMapIndex*>(index.getp());
  }

  void init(const store::IndexCondition_t& cond);

  void open();

  bool next(store::Item_t& result);
  
  void reset();

  void close();

protected:
  void initExact();

  void initBox();
};



/*******************************************************************************

********************************************************************************/
class IndexPointConditionImpl : public store::IndexPointCondition
{
  friend class STLMapProbeIterator;
  friend class HashProbeIterator;

protected:
  rchandle<IndexImpl>   theIndex;
  store::IndexKey       theKey;
  ulong                 theNumColumns;

public:
  IndexPointConditionImpl(IndexImpl* idx) 
    :
    theIndex(idx),
    theNumColumns(idx->getNumColumns())
  {
  }

  const store::IndexKey&  getKey() const { return theKey; }

  void clear();

  void pushItem(store::Item_t& item);

  bool test(const store::IndexKey& key) const;

  std::string toString() const;
};


std::ostream& operator<<(std::ostream& os, const IndexPointConditionImpl& cond);


/*******************************************************************************

********************************************************************************/
class IndexBoxConditionImpl : public store::IndexBoxCondition
{
  friend class STLMapIndex;
  friend class STLMapProbeIterator;

  friend std::ostream& operator<<(std::ostream& os, const IndexBoxConditionImpl& cond);

public:
  static store::Item_t  theNegInf;
  static store::Item_t  thePosInf;

protected:
  struct RangeFlags
  {
    bool  theHaveLowerBound;
    bool  theHaveUpperBound;
    bool  theLowerBoundIncl;
    bool  theUpperBoundIncl;
  };

  rchandle<IndexImpl>      theIndex;
  store::IndexKey          theLowerBounds;
  store::IndexKey          theUpperBounds;
  std::vector<RangeFlags>  theRangeFlags;

public:
  IndexBoxConditionImpl(IndexImpl* idx) : theIndex(idx) { }

  void clear();

  IndexConditionKind getKind() const { return BOX_SCAN; }

  std::string getKindString() const { return "BOX_SCAN"; }

  ulong numRanges() const { return theLowerBounds.size(); }

  bool test(const store::IndexKey& key) const;

  void pushRange(
        store::Item_t& lower,
        store::Item_t& upper,
        bool haveLower,
        bool haveUpper,
        bool lowerIncl,
        bool upperIncl);

  std::string toString() const;
};


std::ostream& operator<<(std::ostream& os, const IndexBoxConditionImpl& cond); 



}
}

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
