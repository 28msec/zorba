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

namespace zorba
{

class XQPCollator;


namespace store
{

class IndexSpecification;
class IndexEntryCreator;
class Iterator;

typedef rchandle<IndexEntryCreator> IndexEntryCreator_t;


/***************************************************************************//**
  Specification for creating a value or general index.

  theNumKeyColumns: 
  -----------------
  The number of columns in each key.

  theKeyTypes:
  ------------
  The data types of the key columns. Each type must be a builtin atomic type,
  and for sorted indices, it must have an ordering.

  theCollations: 
  --------------
  The names (uris) of the collations to use when comparing the string columns 
  of two keys. The size of this vector is equal to theNumKeyColumns; if a type
  of a key column is not string, the associated entry in theCollations is the 
  empty string.

  theTimezone:
  ------------
  The timezone is needed to compare date/time key values.

  theIsGeneral:
  -------------
  Whether the index is "general" or not.

  theIsUnique: 
  ------------
  Whether the index is unique, i.e., there is exactly one value associated with
  each key.

  theIsSorted:
  ------------
  Whether the index is sorted by its key values or not.

  theIsTemp:
  ----------
  Whether the index is temporary or not.

  theIsThreadSafe:
  ----------------
  Whether the index can be shared among multiple threads or not.

  theIsAutomatic:
  ---------------
  Whether the index must be maintained during/after each apply- updates or not.

  theSources:
  -----------
  The qnames of the collections accessed by the defining exprs of this index.
********************************************************************************/
class IndexSpecification
{
public:
  csize                          theNumKeyColumns;
  std::vector<store::Item_t>     theKeyTypes;
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
    theNumKeyColumns(0),
    theTimezone(0),
    theIsGeneral(false),
    theIsUnique(false),
    theIsSorted(false),
    theIsTemp(false),
    theIsThreadSafe(false),
    theIsAutomatic(false)
  {
  }

  void clear()
  {
    theNumKeyColumns = 0;
    theKeyTypes.clear();
    theCollations.clear();
    theTimezone = 0;
    theIsAutomatic = theIsGeneral = theIsUnique = theIsSorted = theIsTemp = theIsThreadSafe = false;
  }

  void resize(csize numColumns)
  {
    theNumKeyColumns = numColumns;
    theKeyTypes.resize(numColumns);
    theCollations.resize(numColumns);
  }

  csize getNumColumns() const { return theNumKeyColumns; }

  long getTimezone() const { return theTimezone; }
};


/**************************************************************************//**
  Class IndexKey represents an index key as a vector of item handles.
*******************************************************************************/
class IndexKey : public ItemVector
{
public:
  IndexKey(csize size = 0) : ItemVector(size) {}
};


/**************************************************************************//**
  A index delta is a set of [domain-node, associated-key(s)] pairs.
*******************************************************************************/
class IndexDelta
{
public:
  typedef std::pair<Item_t, IndexKey*> ValuePair;

  typedef std::vector<ValuePair> ValueDelta;

  typedef std::pair<Item_t, Item_t> GeneralPair;

  typedef std::vector<GeneralPair> GeneralDelta;

protected:
  ValueDelta       theValueDelta;
  GeneralDelta     theGeneralDelta;

public:
  void addValuePair(Item_t& node, IndexKey* key);

  void addGeneralPair(Item_t& node, Item_t& key);

  void clear();

protected:
  IndexDelta() {}
  ~IndexDelta();
};


/***************************************************************************//**

  Class IndexCondition represents a search condition on the keys of an index.
  An instance of IndexCondition is given as a parameter to the init() method
  of an IndexProbeIterator (see iterator.h), which can then iterate over the
  items in the value of each index key that satisfies the condition.

  There are 4 kinds of index conditions:

  POINT_VALUE :
  -------------

  It represents a condition that is satisfied by at most one index key tuple,
  namely the index key tuple K (if it exists) that is equal, according to the
  rules of value equality, to a user specified search key tuple. If any of
  the domain items associated with K is also associated with another key tuples,
  an error os raised.

  POINT_GENERAL:
  --------------

  It represents a condition that is satisfied by all index keys that are equal,
  according to the rules of general equality, to a user specified search key.
  This condition is applicable to general indexes only.


  BOX_VALUE :
  -----------

  It represents a condition that is satisfied by the index keys inside a
  user-specified "box".

  Let M be the number of key columns. Then, an M-dimensional box is defined as
  a conjuction of M range conditions on columns 0 to M-1. Each range condition
  specifies a range of acceptable values for some key column. Specifically, a
  range is defined as the set of all key values K such that

  lower_bound <? K <? upper_bound, where <? is either the lt or the le operator.

  The lower bound may be -INFINITY and the upper bound may be +INFINTY.

  BOX_GENERAL :
  -------------

  It represents the following condition:

  bound op? K, where 

  (a) op? is one of <, <=, >, or >=, 
  (b) K is a key value, and 
  (c) bound is either an atomic item or -INFINITY or +INFINITY.

********************************************************************************/
class IndexCondition : public SimpleRCObject
{
public:
  typedef enum
  {
    POINT_VALUE,
    POINT_GENERAL,
    BOX_VALUE,
    BOX_GENERAL
  } Kind;

public:
  virtual ~IndexCondition() {}

  /**
   * Clear the internal data of this condition object, so that it can be
   * rebuilt and reused.
   */
  virtual void clear() = 0;

  /**
   *  Return the kind of the condition.
   */
  virtual Kind getKind() const = 0;

  /**
   *  Return the kind of the condition as a string.
   */
  virtual std::string getKindString() const = 0;

  /**
   * This method applies to POINT_VALUE and POINT_GENERAL conditions only.
   * The key associated with such conditions is built one item at a time using
   * this method.
   */
  virtual void pushItem(Item_t& item) = 0;

  /**
   * This method applies to BOX_VALUE conditions only.
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

  /**
   * This method applies to BOX_GENERAL conditions only.
   *
   * @param bound An item that constitutes either a lower or an upper bound
   *        for the key values.
   * @param isLower True if the bound is a lower one; false if it is an upper
   *        one.
   * @param boundIncl True if the boundary search key is included in the 
   *        search. False otherwise.
   */
  virtual void pushBound(Item_t& bound, bool isLower, bool boundIncl) = 0;

  /**
   *  Serialize this condition.
   */
  virtual std::string toString() const = 0;
};


/**************************************************************************//**

  Abstract index class. It represents both "value" and "general" indexes.

  Value Indexes:
  --------------

  From the store's point of view, a "value index" is a container that "stores"
  a relation between tuples of atomic items (called key tuples) and items
  (called domain items). The relationship is a function on the domain items,
  i.e., for each domain item there is exactly one key tuple. In general, the
  function is N:1, that is, several domain items may have the same key tuple.

  The key tuples must satisfy the following constraints:

  1. All key tuples in a value index have the same fixed number of items, say M.
     Given this constraint, we can define the i-th "key column" of a value index
     as the set of items that appear in the i-th position of each key tuple. If
     an index has N tuples, then there are M key columns, each containing N items.

  2. The items in each key column must be comparable with each other using the
     Item::equals() method and/or the Item::compare() method. This implies that
     all items in a key column must belong to the same branch of the XMLSchema
     type hierarchy. Furthermore, no key item may have type xs:untypedAtomic or
     xs:anyAtomicType.

  General Indexes:
  ----------------

  From the store's point of view, a "general index" is a container that "stores"
  a relation between tuples of atomic items (called key tuples) and items
  (called domain items). The relationship is N:M, that is, each domain item
  may have more than one associated key tuples and several domain items may
  be associated with the same key tuple.

  Let D be a domain item and K an associated key tuple. In the case of value
  indexes, if K contains a key item whose type is xs:untypedAtomic, an error
  is raised. In contrast, a general index casts the xs:untyped key item to
  every other primitive xml-schema type and for each such successful cast,
  creates a new key tuple by replacing the xs:untypedAtomic item with the
  result of the cast. D is then associated with each of these new tuples. The
  process is repeated until there are no xs:untypedAtomic key items in any
  of the key tuples. Finally, the associations between D and the transformed
  key tuples are stored in the index container.

  After the above transformations, the key tuples must satisfy the same
  constraints as the key tuples of value indexes.


  It is expected that for both value and general indexes, the index container
  is organized in a way that makes it efficient to find all the domain items
  whose associated key tuple(s) satisfy a given search condition (see class
  IndexCondition below).

*******************************************************************************/
class Index : public SyncedRCObject
{
public:
  class KeyIterator : virtual public SimpleRCObject
  {
  public:
    virtual void open() = 0;

    virtual bool next(IndexKey&) = 0;

    virtual void close() = 0;

    virtual ~KeyIterator() {}
  };

  typedef rchandle<KeyIterator> KeyIterator_t;


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
  virtual csize getNumColumns() const = 0;

  /**
   * Return the timezone that is used when comparing date-time related items
   */
  virtual long getTimezone() const = 0;

  /**
   *  Return pointer to the collator used by this index when comparing items at
   *  its i-th column (return NULL if no collator is used for the i-th column).
   */
  virtual const XQPCollator* getCollator(csize i) const = 0;

  /**
   * Create an index condition (see class IndexCondition below)
   */
  virtual IndexCondition_t createCondition(IndexCondition::Kind k) = 0;

  /**
   * Returns the number of entries in the index
   */
  virtual csize size() const = 0;

  /**
   * Returns all keys stored in this index
   */
  virtual KeyIterator_t keys() const = 0;

  /**
   * Insert the given item in the value set of the given key. If the key is not
   * in the index already, then the key itself is inserted as well. Return true
   * if the key was already in the index, false otherwise
   * The index wil take the ownership of the key if it was not already in the
   * index.
   *
   * NOTE: this method is needed here because it is invoked from the
   * UDFunctionCallIterator to implement the function cache.
   *
   * @error ZDDY0035 if a key with more than one item is inserted into
   *  a general index
   */
  virtual bool insert(store::IndexKey*& key, store::Item_t& item) = 0;

  virtual bool remove(
      const store::IndexKey* key,
      const store::Item_t& item,
      bool all = false) = 0;
};



/*******************************************************************************
  An abstract class that provides a callback method for the store to call during
  index maintenance. The method computes [domain_node, associated-key] pairs for
  a given node that has some relationship to the domain expression.

  Instances of IndexEntryCreator are created by the ApplyIterator for each
  incrementally-maintenable index that needs maintenance. Such an instance is
  stored inside the IndexDecl of the associated index, so that it can be
  reused every time the index needs maintenance.

  A concrete implementation of this class is provided in 
  runtime/index/doc_indexer.h
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
/* vim:set et sw=2 ts=2: */
