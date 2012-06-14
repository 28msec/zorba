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

#include "simple_index.h"
#include "store_defs.h"

namespace zorba 
{ 

namespace simplestore 
{

class AtomicItem;


/******************************************************************************
  Acts as a comparison function for the hash or tree map that implements a
  general index.
********************************************************************************/
class GeneralIndexCompareFunction
{
private:
  long               theTimezone;
  const XQPCollator* theCollator;

public:
  GeneralIndexCompareFunction(long timezone, const std::string& collation);

  ~GeneralIndexCompareFunction();

  const XQPCollator* getCollator() const { return theCollator; }

  uint32_t hash(const store::Item* key) const;

  bool equal(const store::Item* key1, const store::Item* key2) const;

  long compare(const store::Item* key1, const store::Item* key2) const;

  bool operator()(const store::Item* key1, const store::Item* key2) const
  {
    return compare(key1, key2) < 0;
  }
};


/**************************************************************************//**
  Stores all the domain nodes associated with a key K. For each such node N, a
  boolean flag is also stored. The flag is true if  K was produced by 
  casting an untypedAtomic key that was found in the result of the key expr
  for node N.
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
  GeneralIndexValue(csize size = 0) : theNodes(size) {}

  void clear() { theNodes.clear(); }

  const_iterator begin() { return theNodes.begin(); }

  const_iterator end()   { return theNodes.end(); }

  void addNode(store::Item_t& node, bool untyped);
};


/******************************************************************************

  theKeyTypeCode:
  ---------------
  The type code for the builtin atomic key type (set to XS_LAST if the index
  is not typed).

  theCompFunction:
  ----------------
  An instance of GeneralIndexCompareFunction that acts as a comparison function
  for the hash or tree map that implements the index.

  theEmptyKeyNodes:
  -----------------
  A vector storing all domain nodes for which the key expr returns the empty
  sequence.

  theUntypedFlag:
  ---------------
  Set to true if there is at least one domain node for which the key expression
  returns an item with type xs:untypedAtomic and that item is sucessfully cast
  to an item with a type other than xs:string.

  theMultiKeyFlag:
  ----------------
  Set to true if there is at least one domain node for which the key expression
  returns more than one items.
*******************************************************************************/
class GeneralIndex : public IndexImpl
{
  friend class IndexImpl;
  friend class GeneralHashIndex;
  friend class GeneralTreeIndex;
  friend class ProbeGeneralIndexIterator;
  friend class ProbeGeneralTreeIndexIterator;

  typedef std::pair<const store::Item*, GeneralIndexValue*> IndexMapPair;

private:
  static const int64_t        theMaxLong;
  static const int64_t        theMinLong;
  static const double         theDoubleMaxLong;
  static const double         theDoubleMinLong;

protected:
  store::SchemaTypeCode       theKeyTypeCode;

  GeneralIndexCompareFunction theCompFunction;

  std::vector<store::Item_t>  theEmptyKeyNodes;

  bool                        theUntypedFlag;

  bool                        theMultiKeyFlag;

protected:
  GeneralIndex(const store::Item_t& name, const store::IndexSpecification& spec);

  virtual ~GeneralIndex();

  bool isTyped() const { return (theKeyTypeCode != store::XS_LAST); }

  bool insertInMap(
      store::Item_t& key,
      store::Item_t& node,
      store::SchemaTypeCode targetMap,
      bool untyped);

  bool probeMap(
      const store::Item* key,
      store::SchemaTypeCode targetMap);

public:
  const XQPCollator* getCollator(csize i) const;

  void setMultiKey() { theMultiKeyFlag = true; }

  csize size() const;

  bool insert(store::Item_t& key, store::Item_t& node);

  bool insert(store::IndexKey*& key, store::Item_t& node);

  virtual bool remove(
      const store::Item_t& key,
      const store::Item_t& node,
      bool all) = 0;
};


/******************************************************************************
  theMaps:
  --------
  One hash map for each builtin atomic type T, except from xs:untypedAtomic 
  and xs:anyAtomicType. TheMaps is indexed by the type code of T.

  theSingleMap:
  -------------
  If the keyspec of the index specifies an atomic type T and T is neither
  xs:untypedAtomic nor xs:anyAtomicType, then theSingleMap points to theMaps
  entry that corresponds to the builtin base type of T. Otherwise, theSingleMap
  is NULL.
*******************************************************************************/
class GeneralHashIndex : public GeneralIndex
{
  friend class GeneralIndex;
  friend class ProbeGeneralIndexIterator;
  friend class ProbeGeneralHashIndexIterator;

  typedef HashMap<const store::Item*,
                  GeneralIndexValue*,
                  GeneralIndexCompareFunction> IndexMap;

  typedef IndexMap::iterator EntryIterator;

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
  IndexMap  * theMaps[store::XS_LAST];
  IndexMap  * theSingleMap;

protected:
  bool insertInMap(
      store::Item_t& key,
      store::Item_t& node,
      IndexMap*& targetMap,
      bool untyped);

public:
  GeneralHashIndex(
      const store::Item_t& name,
      const store::IndexSpecification& spec);

  ~GeneralHashIndex();

  Index::KeyIterator_t keys() const;

  bool remove(const store::Item_t& key, const store::Item_t& node, bool);

  void clear();
};


/******************************************************************************

*******************************************************************************/
class GeneralTreeIndex : public GeneralIndex
{
  friend class GeneralIndex;
  friend class ProbeGeneralIndexIterator;
  friend class ProbeGeneralTreeIndexIterator;

  typedef std::map<const store::Item*,
                   GeneralIndexValue*,
                   GeneralIndexCompareFunction> IndexMap;

  typedef IndexMap::const_iterator EntryIterator;


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
  IndexMap       * theMaps[store::XS_LAST];
  IndexMap       * theSingleMap;
  SYNC_CODE(Mutex  theMapMutex;)

protected:
  bool insertInMap(
      store::Item_t& key,
      store::Item_t& node,
      IndexMap*& targetMap,
      bool untyped);

public:
  GeneralTreeIndex(
      const store::Item_t& qname,
      const store::IndexSpecification& spec);

  ~GeneralTreeIndex();

  Index::KeyIterator_t keys() const;

  bool remove(const store::Item_t& key, const store::Item_t& item, bool all);

  void clear();
};


/******************************************************************************
  Iterator to probe a general index.

  theIndex:
  ---------
  The index to probe

  theProbeKind: 
  --------------
  The kind of condition to satisfy. May be POINT_VALUE, POINT_GENERAL, BOX_VALUE,
  or BOX_GENERAL.

  theCondition:
  -------------
  The condition to satisfy. 

  theIsUntypedProbe:
  ------------------

  theIsFullProbe:
  ---------------
  Set to true if the condition is a range condition with no bounds. In this case,
  domain nodes that appear in the index with their associated "untyped" flag set
  to true must be skipped from the result because they will be just duplicates
  (they appear for sure in the STRING map). This is used for range probes only.
 
  theResultSets:
  --------------
  The node sets associated with the keys that match the condition. This is used
  for point probes only.

  theResultSetsIte:
  -----------------
  Iterator over theResultSets; points to the "current" result set. This is used
  for point probes only.

  theResultSetsEnd:
  -----------------
  The "end" iterator of theResultSets. This is used for point probes only. 

  theMapBegins:
  -------------
  A vector that stores an iterator pointing to the 1st qualifying entry in 
  each tree that has at least one qualifying entry. This is used for range 
  probes only.

  theMapEnds:
  -----------
  A vector that stores an iterator pointing to the last qualifying entry in 
  each tree that has at least one qualifying entry. This is used for range 
  probes only.

  theMapIte:
  ----------

  theIte:
  -------
  For iterating over the domain nodes associated with an index key that satisfies
  the search condition. These domain nodes are returned as results of "this"
  probe iterator.

  theEnd:
  -------
  For marking the end of an iteration over the domain nodes associated with an
  index key that satisfies the search condition..
********************************************************************************/
class ProbeGeneralIndexIterator : public store::IndexProbeIterator
{
  friend class ProbeGeneralHashIndexIterator;
  friend class ProbeGeneralTreeIndexIterator;

  typedef std::vector<GeneralIndexValue*> ResultSets;

  typedef GeneralTreeIndex::EntryIterator EntryIterator;

  typedef std::vector<EntryIterator> EntryIterators;

protected:
  rchandle<GeneralIndex>                theIndex;

  store::IndexCondition::Kind           theProbeKind;

  rchandle<GeneralIndexCondition>       theCondition;

  bool                                  theIsUntypedProbe;

  bool                                  theIsFullProbe;

  ResultSets                            theResultSets;

  ResultSets::const_iterator            theResultSetsIte;

  ResultSets::const_iterator            theResultSetsEnd;

  EntryIterators                        theMapBegins;

  EntryIterators                        theMapEnds;

  csize                                 theCurrentMap;

  EntryIterator                         theMapIte;

  GeneralIndexValue::const_iterator     theIte;
  GeneralIndexValue::const_iterator     theEnd;

protected:
  ProbeGeneralIndexIterator(const store::Index_t& index);

  void initPoint();

  void initBox();

  bool haveMap(store::SchemaTypeCode targetMap) const;

  void probeMap(store::SchemaTypeCode targetMap, const store::Item* key);

  void probeMap(
      const store::SchemaTypeCode targetMap,
      const store::Item* lowerKey,
      const store::Item* upperKey);

  void checkStringKeyType(const AtomicItem* keyItem) const;

  void doubleToLongProbe(
      store::Item_t& result,
      const AtomicItem* doubleItem,
      bool haveLower,
      bool haveUpper) const;

public:
  void init(const store::IndexCondition_t& cond);

  void open();

  void reset();

  void close();

  bool next(store::Item_t& result);

  void count(store::Item_t& result);
};


/******************************************************************************
  Iterator to probe a hash-based, general index. The probe itself may be a
  value probe or a general probe.
********************************************************************************/
class ProbeGeneralHashIndexIterator : public ProbeGeneralIndexIterator
{
  friend class ProbeGeneralIndexIterator;

protected:
  void probeMap(
    const GeneralHashIndex::IndexMap* targetMap,
    const store::Item* key);

public:
  ProbeGeneralHashIndexIterator(const store::Index_t& index);
};


/******************************************************************************
  Iterator to probe a tree-based, general index. The probe itself may be a
  value probe or a general probe.
********************************************************************************/
class ProbeGeneralTreeIndexIterator : public ProbeGeneralIndexIterator
{
  friend class ProbeGeneralIndexIterator;

protected:
  void probeMap(
      const GeneralTreeIndex::IndexMap* targetMap,
      const store::Item* key);

  void probeMap(
      const GeneralTreeIndex::IndexMap* targetMap,
      const store::Item* lowerKey,
      const store::Item* upperKey);

public:
  ProbeGeneralTreeIndexIterator(const store::Index_t& index);
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
