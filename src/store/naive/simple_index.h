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
  store::Item_t theUri;

  bool          theIsTemp;
  bool          theIsThreadSafe;

public:
  IndexImpl(const xqpStringStore_t& uri);

  virtual ~IndexImpl() {}

  store::Item* getUri() const { return theUri.getp(); }

  virtual bool isUnique() const { return false; }

  virtual bool isOrdering() const { return false; }

  bool isThreadSafe() const { return theIsThreadSafe; }

  bool isTemporary() const { return theIsTemp; }
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

protected:
  HashIndex(
        const xqpStringStore_t& uri,
        ulong numKeys,
        long timezone,
        const std::vector<XQPCollator*>& collators)
    :
    IndexImpl(uri),
    theCompFunction(numKeys, timezone, collators),
    theMap(theCompFunction, 1024, theIsThreadSafe)
  {
  }

  ~HashIndex() {}

  bool insert(store::IndexKey* key, store::Item_t& value);

  bool remove(store::IndexKey* key, store::Item_t& value);
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
  {
    theIndex = reinterpret_cast<HashIndex*>(index.getp());
  }

  void init(store::IndexKey& key);

  void open();

  store::Item* next();
    
  bool next(store::Item_t& result);
  
  void reset();

  void close();
};

}
}

#endif
