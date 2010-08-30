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
  Specification for creating a value or general index.

  theNumKeyColumns: The number of columns in each key.
  theKeyTypes     : The data types of the key columns. Each type must be a 
                    builtin atomic type, and for sorted indices, it must have
                    an ordering.
  theCollations   : The names (uris) of the collations to use when comparing the
                    string columns of two keys. The size of this vector is equal
                    to theNumKeyColumns; if a type of a key column is not string, 
                    the associated entry in theCollations is the empty string.   
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
  ulong                          theNumKeyColumns;
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
  An index delta is a set of [domain-node, associated-key] pairs. 
*******************************************************************************/
typedef std::vector<std::pair<store::Item_t, store::IndexKey*> > IndexDelta;


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
  range is defined as the set of all values X such that 

  lower_bound <? X <? upper_bound, where <? is either the lt or the le operator.

  The lower bound may be -INFINITY and the upper bound may be +INFINTY. 

  BOX_GENERAL :
  -------------

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
   * Create an index condition (see class IndexCondition below)
   */
  virtual IndexCondition_t createCondition(IndexCondition::Kind k) = 0;
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
