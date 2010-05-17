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
  theIsGeneral    : Whether the index is "general" or not. 
  theIsUnique     : Whether the index is unique, i.e., there is exactly one
                    value associated with each key.
  theIsSorted     : Whether the index is sorted by its key values or not.
  theIsTemp       : Whether the index is temporary or not.
  theIsThreadSafe : Whether the index can be shared among multiple threads or not
  theIsAutomatic  : Whether the index must be maintained during/after each apply-
                    updates or not.

  theSources      : The qnames of the collections accessed by the defining exprs
                    of this index.
********************************************************************************/
class IndexSpecification
{
public:
  std::vector<store::Item_t>     theKeyTypes;
  store::Item_t                  theValueType;
  std::vector<std::string>       theCollations;
  long                           theTimezone;

  bool                           theIsGeneral;
  bool                           theIsUnique;
  bool                           theIsSorted;
  bool                           theIsTemp;
  bool                           theIsThreadSafe;
  bool                           theIsAutomatic;

  std::vector<store::Item_t>     theSources;

public:
  IndexSpecification()
    :
    theTimezone(0),
    theIsGeneral(false),
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
    theIsGeneral(false),
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
    theIsGeneral = theIsUnique = theIsSorted = theIsTemp = theIsThreadSafe = false;
  }

  void resize(ulong numColumns)
  {
    theKeyTypes.resize(numColumns);
    theCollations.resize(numColumns);
  }
};


/**************************************************************************//**
  Class IndexKey represents an index key as a vector of item handles. 
*******************************************************************************/
class IndexKey : public ItemVector
{
public:
  IndexKey(ulong size = 0) : ItemVector(size) {}
};


/**************************************************************************//**
  Class ValueSet represents a value set as a vector of item handles.
*******************************************************************************/
class IndexValue : public store::ItemVector
{
public:
  IndexValue(ulong size = 0) : store::ItemVector(size) {}
};


/**************************************************************************//**
  An index delta is a set of [domain-node, associated-key] pairs. 
*******************************************************************************/
typedef std::vector<std::pair<store::Item_t, store::IndexKey*> > IndexDelta;


/**************************************************************************//**

  Abstract index class. It represents both "value" and "general" indexes.

  From the store's point of view, a "value index" is a container that implements
  an N:1 mapping (i.e., a function) from item tuples to item bags. (In practice,
  the mapping is 1:1, but the store does not enforce this). 

  The tuples that appear in an index are referred to as "key tuples", and they
  satisfy the following constraints:

  1. All key tuples in a value index have the same fixed number of items, say M.
     Given this constraint, we can define the i-th "key column" of a value index
     as the set of items that appear in the i-th position of each key tuple. If
     an index has N tuples, then there are M key columns, each containing N items. 
  2. All items in a key tuple are atomic items.
  3. The items in each key column must be comparable with each other using the
     Item::equals() method and/or the Item::compare() method. This implies that
     all items in a key column must belong to the same branch of the XMLSchema
     type hierarchy.

  The bag of items associated with each key tuple is referred to as an "index 
  value". The number of items in each index value can shrink or grow over time
  independently from other index values. 

*******************************************************************************/
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
   * Return the qname of the index.
   */
  virtual Item* getName() const = 0;

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

  Class IndexCondition represents a condition on the keys of an index. An
  instance of IndexCondition is given as a parameter to the init() method of
  an IndexProbeIterator (see iterator.h), which can then iterate over the
  items in the value of each index key that satisfies the condition.

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

  Let M be the number of key columns. Then, an M-dimensional box is defined as
  a conjuction of M range conditions on columns 0 to M-1. Each range condition
  specifies a range of acceptable values for some key column. Specifically, a
  range is defined as the set of all values X such that 

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


/*******************************************************************************
 An abstract class that provides a callback method for the store to call in order
 to perform index maintenance.  The method computes [domain_item, associated-key]
 pairs for a given node that has some relationship to the domain expression.
********************************************************************************/
class IndexEntryCreator : public SimpleRCObject
{
public:
  virtual ~IndexEntryCreator() { }

  virtual void createIndexEntries(Item* item, IndexDelta& delta) = 0;
};


}
}

#endif


/*
 * Local variables:
 * mode: c++
 * End:
 */
