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
#ifndef ZORBA_SIMPLE_STORE_INDEX_HASH_GENERAL
#define ZORBA_SIMPLE_STORE_INDEX_HASH_GENERAL

#include <map>

#include "store/naive/simple_index.h"
#include "store/naive/store_defs.h"

namespace zorba 
{ 

namespace simplestore 
{

class AtomicItem;


/**************************************************************************//**

*******************************************************************************/
class GeneralIndexValue
{
public:
  struct NodeInfo
  {
    store::Item_t theNode;
    bool          theUntyped;
  };

  typedef std::vector<NodeInfo>::const_iterator const_iterator;

protected:
  std::vector<NodeInfo> theNodes;

public:
  GeneralIndexValue(ulong size = 0) : theNodes(size) {}

  void addNode(store::Item_t& node, bool multikey, bool untyped);

  void clear() { theNodes.clear(); }

  const_iterator begin() { return theNodes.begin(); }

  const_iterator end()   { return theNodes.end(); }
};


/******************************************************************************

*******************************************************************************/
class GeneralIndex : public IndexImpl
{
  friend class SimpleStore;

protected:
  IndexCompareFunction        theCompFunction;
  std::vector<store::Item_t>  theEmptyKeyNodes;
  bool                        theUntypedFlag;
  bool                        theMultiKeyFlag;

protected:
  GeneralIndex(
      const store::Item_t& qname,
      const store::IndexSpecification& spec);
};


/******************************************************************************

*******************************************************************************/
class GeneralHashIndex : public GeneralIndex
{
  friend class SimpleStore;
  friend class ProbeGeneralHashIndexIterator;

  typedef HashMap<const store::IndexKey*,
                  GeneralIndexValue*,
                  IndexCompareFunction> IndexMap;

  class KeyIterator : public Index::KeyIterator
  {
  public:
    ~KeyIterator();

    void open();
    bool next(store::IndexKey&);
    void close();
  };

  typedef rchandle<KeyIterator> KeyIterator_t;

private:
  IndexMap  * theMaps[XS_LAST];
  IndexMap  * theSingleMap;

public:
  ulong size() const;

  Index::KeyIterator_t keys() const;

  bool insert(store::IndexKey*& key, store::Item_t& node, bool multikey);

  bool remove(const store::IndexKey* key, store::Item_t& item, bool all = false);

protected:
  GeneralHashIndex(
      const store::Item_t& qname,
      const store::IndexSpecification& spec);

  ~GeneralHashIndex();

  bool isTyped() const { return (theSingleMap != NULL); }

  bool insertInMap(
      store::IndexKey*& key,
      store::Item_t& node,
      IndexMap*& targetMap,
      bool multikey,
      bool untyped);
};


/******************************************************************************
  Iterator to probe a hash-based, general index. The probe itself may be a
  value probe or a general probe.

  theIndex         : The index to probe
  theCondition     : The condition to satisfy. May be a POINT_VALUE or 
                      POINT_GENERAL condition.
  theProbeKind     : 

  theResultSets    : The node sets associated with the keys that match the 
                     condition
  theResultSetsIte :
  theResultSetsEnd :
********************************************************************************/
class ProbeGeneralHashIndexIterator : public store::IndexProbeIterator
{
protected:
  rchandle<GeneralHashIndex>                 theIndex;

  rchandle<IndexPointCondition>              theCondition;
  store::IndexCondition::Kind                theProbeKind;

  bool                                       theIsUntypedProbe;

  std::vector<GeneralIndexValue*>            theResultSets;
  std::vector<GeneralIndexValue*>::iterator  theResultSetsIte;
  std::vector<GeneralIndexValue*>::iterator  theResultSetsEnd;
  GeneralIndexValue::const_iterator          theIte;
  GeneralIndexValue::const_iterator          theEnd;

public:
  ProbeGeneralHashIndexIterator(const store::Index_t& index);

  void init(const store::IndexCondition_t& cond);

  void open();

  bool next(store::Item_t& result);
  
  void reset();

  void close();
};


/******************************************************************************

*******************************************************************************/
class GeneralTreeIndex : public GeneralIndex
{
  friend class SimpleStore;
  friend class ProbeGeneralTreeIndexIterator;

  typedef std::pair<const store::IndexKey*, GeneralIndexValue*> IndexMapPair;

  typedef std::map<const store::IndexKey*,
                   GeneralIndexValue*,
                   IndexCompareFunction> IndexMap;

  class KeyIterator : public Index::KeyIterator
  {
  public:
    ~KeyIterator();

    void open();
    bool next(store::IndexKey&);
    void close();
  };

  typedef rchandle<KeyIterator> KeyIterator_t;

private:
  static const int64_t  theMaxLong;
  static const int64_t  theMinLong;
  static const double   theDoubleMaxLong;
  static const double   theDoubleMinLong;

private:
  IndexMap       * theMaps[XS_LAST];
  IndexMap       * theSingleMap;
  SYNC_CODE(Mutex  theMapMutex;)

public:
  ulong size() const;

  Index::KeyIterator_t keys() const;

  bool insert(store::IndexKey*& key, store::Item_t& node, bool multikey);

  bool remove(const store::IndexKey* key, store::Item_t& item, bool all = false);

protected:
  GeneralTreeIndex(
      const store::Item_t& qname,
      const store::IndexSpecification& spec);

  ~GeneralTreeIndex();

  bool isTyped() const { return (theSingleMap != NULL); }

  bool insertInMap(
      store::IndexKey*& key,
      store::Item_t& node,
      IndexMap*& targetMap,
      bool multikey,
      bool untyped);
};


/******************************************************************************
  Iterator to probe a tree-based, general index. The probe itself may be a
  value probe or a general probe.

  theIndex         : The index to probe
  theCondition     : The condition to satisfy. May be a POINT_VALUE, or 
                      POINT_GENERAL, or BOX_VALUE, or BOX_GENERAL condition.
  theProbeKind     : 

  theResultSets    : The node sets associated with the keys that match the 
                     condition. This is used for point probes only.
  theResultSetsIte : Iterator over theResultSets; points to the "current" result
                     set. This is used for point probes only.
  theResultSetsEnd : The "end" iterator of theResultSets. This is used for 
                     point probes only. 

  theMapBegins     :  A vector that stores an iterator pointing to the 1st 
                      qualifying entry in each tree that has at least one
                      qualifying entry. This is used for range probes only.
  theMapEnds       :  A vector that stores an iterator pointing to the last 
                      qualifying entry in each tree that has at least one
                      qualifying entry. This is used for range probes only.
  theMapIte        :

  theIte           : Iterator over the "current" result set. 
  theEnd           : The "end" iterator of the "current" result set. 

********************************************************************************/
class ProbeGeneralTreeIndexIterator : public store::IndexProbeIterator
{
  typedef std::vector<GeneralIndexValue*> ResultSets;

  typedef GeneralTreeIndex::IndexMap::const_iterator EntryIterator;

  typedef std::vector<EntryIterator> EntryIterators;

protected:
  rchandle<GeneralTreeIndex>                  theIndex;

  store::IndexCondition::Kind                 theProbeKind;
  rchandle<IndexPointCondition>               thePointCondition;
  rchandle<IndexBoxValueCondition>            theBoxValueCondition;
  rchandle<IndexBoxGeneralCondition>          theBoxGeneralCondition;
  bool                                        theIsUntypedProbe;

  ResultSets                                  theResultSets;
  ResultSets::const_iterator                  theResultSetsIte;
  ResultSets::const_iterator                  theResultSetsEnd;

  EntryIterators                              theMapBegins;
  EntryIterators                              theMapEnds;

  ulong                                       theCurrentMap;
  EntryIterator                               theMapIte;

  GeneralIndexValue::const_iterator           theIte;
  GeneralIndexValue::const_iterator           theEnd;

public:
  ProbeGeneralTreeIndexIterator(const store::Index_t& index);

  void init(const store::IndexCondition_t& cond);

  void open();

  bool next(store::Item_t& result);
  
  void reset();

  void close();

protected:
  void initPoint(const store::IndexCondition_t& cond);

  void initValueBox(const store::IndexCondition_t& cond);

  void initGeneralBox(const store::IndexCondition_t& cond);

  void probeMap(
      GeneralTreeIndex::IndexMap* map,
      const store::IndexKey* lowerKey,
      const store::IndexKey* upperKey);

  void doubleToLongProbe(
      const AtomicItem* doubleItem,
      store::Item_t& result) const;

  void checkStringKeyType(AtomicItem* keyItem) const;
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
