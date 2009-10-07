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
#ifndef ZORBA_STORE_INDEX
#define ZORBA_STORE_INDEX

#include "store/api/shared_types.h"
#include "store/util/item_vector.h"
#include "zorbatypes/xqpstring.h"

namespace zorba 
{

class XQPCollator;


namespace store 
{

class IndexSpecification;
class IndexKeyCompareFunction;
class IndexColumnRange;
class IndexEntryCreator;
class Iterator;

typedef rchandle<IndexEntryCreator> IndexEntryCreator_t;


typedef std::pair<xqpStringStore_t, IndexEntryCreator_t> PatternIECreatorPair;


/***************************************************************************//**
  Specification for creating a value index.

  theKeyTypes     : The data types of the key columns. Each type must be atomic,
                    and for sorted indices, it must have an ordering.
  theValueType    : The data type of the items associated with the keys.
  theCollations   : The names of the collations to use when comparing the string
                    columns of two keys. The size of this vector is the same as
                    that of theKeyTypes; if a type of a key column is not string, 
                    the associated entry in theCollations is simply ignored.   
  theTimezone     : The timezone is needed to compare date/time key values.
  theIsUnique     : Whether the index is unique, i.e., there is exactly one
                    value associated with each key.
  theIsSorted     : Whether the index is sorted by its key values or not.
  theIsTemp       : Whether the index is temporary or not.
  theIsThreadSafe : Whether the index can be shared among multiple threads or not
  theIECreators   : A vector of pattern-creator pairs that the store can use to
                    compute index entries.
********************************************************************************/
class IndexSpecification
{
public:
  std::vector<store::Item_t>                theKeyTypes;
  store::Item_t                             theValueType;
  std::vector<std::string>                  theCollations;
  long                                      theTimezone;
  bool                                      theIsUnique;
  bool                                      theIsSorted;
  bool                                      theIsTemp;
  bool                                      theIsThreadSafe;
  std::vector<PatternIECreatorPair>         theIECreators;

public:
  IndexSpecification()
    :
    theTimezone(0),
    theIsUnique(false),
    theIsSorted(false),
    theIsTemp(false),
    theIsThreadSafe(false)
  {
  }

  IndexSpecification(ulong numColumns)
    :
    theKeyTypes(numColumns),
    theCollations(numColumns),
    theTimezone(0),
    theIsUnique(false),
    theIsSorted(false),
    theIsTemp(false),
    theIsThreadSafe(false)
  {
  }

  void clear()
  {
    theKeyTypes.clear();
    theValueType = NULL;
    theCollations.clear();
    theTimezone = 0;
    theIsUnique = theIsSorted = theIsTemp = theIsThreadSafe = false;
    theIECreators.clear();
  }

  void resize(ulong numColumns)
  {
    theKeyTypes.resize(numColumns);
    theCollations.resize(numColumns);
  }

};



/***************************************************************************//**

  Abstract value index class.

  Class Index represents indices that implement a 1:1 mapping from item tuples
  to item sets. All tuples in such an index have the same fixed number of items,
  and the items in the i-th column of each tuple must all have the same data
  type (for i = 0, 1, ..., N-1). Such tuples are refered to as "index keys". For
  any given index, its keys are unique. Each such index key is associated with
  a set of items, which is refered to as the "value set" of the key. Value sets
  can shrink or grow over time independently from each other. It is possible for
  an item to appear in the value set of multiple keys. It is also possible
  for the same item to appear multiple times in the same value set (so,
  technically, value sets are actually multisets).

  Index instances are created (but not populated) via the store::createIndex()
  method; they are populated via the Index::insert() and Index::remove() methods,
  and are probed via IndexProbeIterators (see iterator.h and iterator_factory.h).

********************************************************************************/
class Index : public RCObject
{
protected:
  SYNC_CODE(mutable RCLock theRCLock;)

public:
  SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })

  long* getSharedRefCounter() const { return NULL; } 

public:

  virtual ~Index() {}

  /**
   *  Return a reference to the specification object that describes this index. 
   */
  virtual const IndexSpecification& getSpecification() const = 0;

  /**
   *  Return the number of columns in the jeys of this index.
   */
  virtual ulong getNumColumns() const = 0;

  /**
   *  Return pointer to the collator used by this index when comparing items at
   *  its i-th column (return NULL if no collator is used for the i-th column).
   */
  virtual const XQPCollator* getCollator(ulong i) const = 0;

  /**
   * Create an index condition for a exact-key probe (see class 
   * IndexExactKeyCondition below)
   */
  virtual IndexPointCondition_t createPointCondition() = 0;

  /**
   * Create an index condition for a box probe (see class 
   * IndexBoxCondition below)
   */
  virtual IndexBoxCondition_t createBoxCondition() = 0;

  /**
   *  Insert the given item in the value set of the given key. If the key
   *  is not in the index already, then the key itself is inserted as well.
   *
   *  @param  key The key to insert (if not already in the index).
   *  @param  item The item to insert in the value set of the key.
   *  @return True if the key was already in the index, false otherwise.
   */
  virtual bool insert(IndexKey& key, Item_t& item) = 0;

  /**
   *  Remove the given item from the value set of the given key. If the
   *  value set of the key becomes empty, then the key itself is removed
   *  from the index.
   *
   *  @param  key The key to remove (if its value set becomes empty).
   *  @param  item The item to from the value set of the key.
   *  @retrun False if the item is not in the value set of the key, or if
   *          key itself is not in the index; true otherwise.
   */
  virtual bool remove(const IndexKey& key, Item_t& item) = 0;

  /**
   *  Fast-track probing method. Given an index key, return the first item in
   *  the associated value set. This method is most useful in the case of unique
   *  indices (i.e., when the value set of each key consists of a single item),
   *  as it avoids the overhead of creating an IndexProbeIterator and iterating
   *  over the result set.
   *
   *  @param key The key we are searching for.
   *  @param result The first item in the value set of the key.
   *  @return True if the key was actually in the index. False otherwise.
   */
  virtual bool probe(const IndexKey& key, Item_t& result) = 0;
};


/***************************************************************************//**
  Class IndexKey represents an index key as a vector of item handles. 
********************************************************************************/
class IndexKey : public ItemVector
{
public:
  IndexKey(ulong size = 0) : ItemVector(size) {}
};


/***************************************************************************//**
  Class IndexEntryReceiver is used to perform index bulk load. It allows an
  index to be populated in ways that may be more efficient than a series of
  invidual (stateless) insertions. This is done by explicitly stating the 
  start and the end of a bulk load session, and implemententing a receive()
  method as a way to do deferred insertions.
********************************************************************************/
class IndexEntryReceiver : public SimpleRCObject 
{
protected:
  Index_t  theIndex;

public:
  virtual ~IndexEntryReceiver() {}

  /**
   *  Receive an index entry to be inserted in the associated index. The 
   *  implementation of this method may choose to insert the given entry to
   *  the index immediately, or store it on the side and insert it at a
   *  later time.
   *
   *  @param  key The key to insert (if not already in the index).
   *  @param  item The item to insert in the value set of the key.
   */
  virtual void receive(store::IndexKey& key, store::Item_t& value) = 0;

  /**
   * Marks the end of the bulk load. Any deferred insertions must be performed
   * before the method returns.
   */
  virtual void commit() = 0;

  /**
   *  Discard any deferred insertions and remove from the index any entries
   *  that have already been inserted by this bulk load session. 
   */
  virtual void abort() = 0;
};


/*******************************************************************************
 Class IndexEntryCreator is used to compute (key, domain_expr) pairs for a
 given node that has a certain relationship to the domain expression.
********************************************************************************/
class IndexEntryCreator : public SimpleRCObject
{
public:
  typedef std::pair<store::IndexKey, store::Item_t> IndexEntry;

  virtual ~IndexEntryCreator() { }

  /**
   * Generate index entries for the given item.
   */
  virtual void appendIndexEntries(
        store::Item_t& item,
        std::vector<IndexEntry>& entries) = 0;
};


/***************************************************************************//**

  Class IndexCondition represents a condition on the keys of an index. An
  instance of IndexCondition is given as a parameter to the init() method of
  an IndexProbeIterator (see iterator.h), which can then iterate over the
  items in the value set of each index key that satisfies the condition.

********************************************************************************/
class IndexCondition : public SimpleRCObject 
{
public:
  enum IndexConditionKind
  {
    EXACT_KEY,
    BOX_SCAN
  };

public:
  virtual ~IndexCondition() {}

  /**
   * Clear the internal data of this condition object, so that it can be
   * rebuilt and reused.
   */
  virtual void clear() = 0;

  /**
   *  Return the kind of the condition. For now, there are only 2 kinds,
   *  EXACT_KEY and BOX_SCAN, which are repesented by subclasses
   *  IndexExactKeyCondition and IndexBoxCondition, respectively.
   */
  virtual IndexConditionKind getKind() const = 0;

  /**
   *  Return the kind of the condition as a string.
   */
  virtual std::string getKindString() const = 0;

  /**
   *  Check if a given index key satisfies this condition.
   *
   *  @param key The index key to test the condition on.
   *  @return True is key satisfies the condition; false otherwise.
   */
  virtual bool test(const IndexKey& key) const = 0;

  /**
   *  Serialize this condition.
   */
  virtual std::string toString() const = 0;
};


/***************************************************************************//**

  Class IndePointCondition represents a condition that is satisfied by at most
  one index key, namely the index key (if it exists) that is equal to a user
  specified key.

  Note: IndexPointCondition is actually a special case of IndexBoxCondition,
  but it is provided for convenience and because it saves some of the overhead
  of IndexBoxCondition.

********************************************************************************/
class IndexPointCondition : public IndexCondition
{
public:
  virtual ~IndexPointCondition() {}

  IndexConditionKind getKind() const { return EXACT_KEY; }

  std::string getKindString() const { return "EXACT_KEY"; }

  /**
   * The key associated with this condition is built one item at a time using
   * the pushItem() method.
   */
  virtual void pushItem(Item_t& item) = 0;
};


/***************************************************************************//**

  Class IndexBoxCondition represents a condition that is satisfied by the index
  keys inside a user-specified "box". 

  Let N be the number of key columns. Then, an M-dimensional box is defined as
  a conjuction of M range conditions on columns 0 to M-1, for some M <= N. Each
  range condition specifies a range of acceptable values for some key column.
  Specifically, A range is defined as the set of all values X such that 

  lower_bound <? X <? upper_bound, where <? is either < or <=.

  The lower bound may be -INFINITY and the upper bound may be +INFINTY. 

********************************************************************************/
class IndexBoxCondition : public IndexCondition
{
public:
  virtual ~IndexBoxCondition() {}

  IndexConditionKind getKind() const { return BOX_SCAN; }

  std::string getKindString() const { return "BOX_SCAN"; }

  /**
   * The box associated with this condition is built one range at a time using
   * the pushRange() method.
   *
   * @param lower The lower bound of the range. May be NULL, which indicates
   *        either the empty sequence or -INFINITY. The haveLower parameter is
   *        used to distinguish between these two cases.
   * @param upper The upper bound of the range. May be NULL, which indicates
   *        either the empty sequence or +INFINITY. The haveUpper parameter is
   *        used to distinguish between these two cases.
   * @param haveLower False if the lower bound is -INFINITY. True otherwise.
   * @param haveUpper False if the upper bound is +INFINITY. True otherwise.
   * @param lowerIncl True if the lower bound is included in the range. False
   *        otherwise.
   * @param upperIncl True if the upper bound is included in the range. False
   *        otherwise.
   */
  virtual void pushRange(
        Item_t& lower,
        Item_t& upper,
        bool haveLower,
        bool haveUpper,
        bool lowerIncl,
        bool upperIncl) = 0;
};


}
}

#endif


/*
 * Local variables:
 * mode: c++
 * End:
 */
