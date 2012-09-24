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
#include "store/api/index.h"
#include "store/api/iterator.h"

#include "shared_types.h"

#include "zorbautils/hashmap.h"

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

public:
  IndexImpl(const store::Item_t& qname, const store::IndexSpecification& spec);

  IndexImpl();

public:
  virtual ~IndexImpl();

  //
  // Store api methods
  //

  store::Item* getName() const { return theQname.getp(); }

  const store::IndexSpecification& getSpecification() const { return theSpec; }

  csize getNumColumns() const { return theSpec.getNumColumns(); }

  long getTimezone() const { return theSpec.theTimezone; }

  const std::vector<std::string>& getCollations() const { return theSpec.theCollations; }

  virtual csize size() const = 0;

  virtual KeyIterator_t keys() const = 0;

  virtual void clear() = 0;

  store::IndexCondition_t createCondition(store::IndexCondition::Kind k);

  //
  // Simplestore methods
  //

  bool isUnique() const { return theSpec.theIsUnique; }

  bool isSorted() const { return theSpec.theIsSorted; }

  bool isTemporary() const { return theSpec.theIsTemp; }

  bool isThreadSafe() const { return theSpec.theIsThreadSafe; }

  bool isGeneral() const { return theSpec.theIsGeneral; }
};


/*******************************************************************************

********************************************************************************/
class IndexConditionImpl : public store::IndexCondition
{
  friend class ProbeValueTreeIndexIterator;
  friend class ProbeValueHashIndexIterator;
  friend class ProbeGeneralIndexIterator;
  friend class ProbeGeneralHashIndexIterator;
  friend class ProbeGeneralTreeIndexIterator;

protected:
  struct RangeFlags
  {
    bool  theHaveLowerBound;
    bool  theHaveUpperBound;
    bool  theLowerBoundIncl;
    bool  theUpperBoundIncl;

    RangeFlags()
      :
      theHaveLowerBound(false),
      theHaveUpperBound(false),
      theLowerBoundIncl(true),
      theUpperBoundIncl(true)
    {
    }
  };

public:
  static store::Item_t         theNegInf;
  static store::Item_t         thePosInf;

protected:
  rchandle<IndexImpl>          theIndex;

  store::IndexCondition::Kind  theKind;

public:
  static std::string getKindString(store::IndexCondition::Kind k);

public:
  IndexConditionImpl(IndexImpl* idx, store::IndexCondition::Kind kind);

  store::IndexCondition::Kind getKind() const { return theKind; }

  std::string getKindString() const { return getKindString(theKind); }

  virtual void pushItem(store::Item_t& item);

  virtual void pushRange(
      store::Item_t& lower,
      store::Item_t& upper,
      bool haveLower,
      bool haveUpper,
      bool lowerIncl,
      bool upperIncl);
  
  virtual void pushBound(store::Item_t& bound, bool isLower, bool boundIncl);
};


/*******************************************************************************
  Repesents a search condition on a general index.

  theKind:
  --------
  The kind of the condition (one of POINT_VALUE, POINT_GENERAL, BOX_VALUE, or
  BOX_GENERAL).

  theIsSet:
  ---------
  Set to true the 1st time one of the pushXXX methods is called and reset to
  false by the clear() method. Used to check that the user is not trying to
  push more than once.

  theKey:
  ------------
  The search key for the POINT conditions. It is non-NULL and points to an
  atomic item.

  theRangeFlags:
  --------------
  Use only for the BOX conditions. Specifies the kind of operator and whether
  the lower/upper bound is INFINITY or not.

  theLowerBound:
  --------------
  The search key that serves as the lower bound for the BOX conditions. If,
  according to theRangeFlags, the bound is not -INFINITY, theLowerBound is 
  not NULL and points to an atomicitem; otherwise, the value of theLowerBound
  is irrelevant (is not used).

  theUpperBound:
  --------------
  The search key that serves as the upper bound for the BOX conditions. If, 
  according to theRangeFlags, the bound is not +INFINITY, theUpperBound is 
  not NULL and points to an atomic item; otherwise, the value of theUpperBound
  is irrelevant (is not used).
********************************************************************************/
class GeneralIndexCondition : public IndexConditionImpl
{
  friend class ProbeGeneralIndexIterator;
  friend class ProbeGeneralHashIndexIterator;
  friend class ProbeGeneralTreeIndexIterator;

  friend std::ostream& operator<<(std::ostream& os, const GeneralIndexCondition& c);

protected:
  bool                         theIsSet;

  AtomicItem_t                 theKey;

  RangeFlags                   theRangeFlags;
  AtomicItem_t                 theLowerBound;
  AtomicItem_t                 theUpperBound;

public:
  GeneralIndexCondition(IndexImpl* idx, store::IndexCondition::Kind);

  std::string toString() const;

  void clear();

  void pushItem(store::Item_t& item);

  void pushRange(
      store::Item_t& lower,
      store::Item_t& upper,
      bool haveLower,
      bool haveUpper,
      bool lowerIncl,
      bool upperIncl);

  void pushBound(store::Item_t& bound, bool isLower, bool boundIncl);
};


std::ostream& operator<<(std::ostream& os, const GeneralIndexCondition& cond);


/*******************************************************************************

********************************************************************************/
class IndexPointCondition : public IndexConditionImpl
{
  friend class ProbeValueTreeIndexIterator;
  friend class ProbeValueHashIndexIterator;
  friend class ProbeGeneralHashIndexIterator;
  friend class ProbeGeneralTreeIndexIterator;

protected:
  store::IndexKey theKey;

public:
  IndexPointCondition(IndexImpl* idx, store::IndexCondition::Kind kind) 
    :
    IndexConditionImpl(idx, kind)
  {
  }

  const store::IndexKey& getKey() const { return theKey; }

  void clear();

  void pushItem(store::Item_t& item);

  bool test(const store::IndexKey& key) const;

  std::string toString() const;
};


std::ostream& operator<<(std::ostream& os, const IndexPointCondition& cond);


/*******************************************************************************
  It represents a condition that is satisfied by the index keys inside a
  user-specified "box".

  Let M be the number of key columns. Then, an M-dimensional box is defined as
  a conjuction of M range conditions on columns 0 to M-1. Each range condition
  specifies a range of acceptable values for some key column. Specifically, a
  range is defined as the set of all key values K such that

  lower_bound <? K <? upper_bound, where <? is either the lt or the le operator.

  The lower bound may be -INFINITY and the upper bound may be +INFINTY.
********************************************************************************/
class IndexBoxValueCondition : public IndexConditionImpl
{
  friend class ValueTreeIndex;
  friend class ProbeValueTreeIndexIterator;
  friend class ProbeGeneralTreeIndexIterator;

  friend std::ostream& operator<<(std::ostream& os, const IndexBoxValueCondition& c);

protected:
  std::vector<RangeFlags>  theRangeFlags;
  store::IndexKey          theLowerBounds;
  store::IndexKey          theUpperBounds;

public:
  IndexBoxValueCondition(IndexImpl* idx, store::IndexCondition::Kind kind)
    :
    IndexConditionImpl(idx, kind)
  {
  }

  csize numRanges() const { return theLowerBounds.size(); }

  void clear();

  void pushRange(
      store::Item_t& lower,
      store::Item_t& upper,
      bool haveLower,
      bool haveUpper,
      bool lowerIncl,
      bool upperIncl);

  bool test(const store::IndexKey& key) const;

  std::string toString() const;
};


std::ostream& operator<<(std::ostream& os, const IndexBoxValueCondition& cond);


/**************************************************************************//**
  A index delta is a set of [domain-node, associated-key(s)] pairs.
*******************************************************************************/
class IndexDeltaImpl : public store::IndexDelta 
{
public:
  typedef std::vector<store::IndexDelta::ValuePair>::iterator
  ValueIterator;

  typedef std::vector<store::IndexDelta::ValuePair>::reverse_iterator
  ReverseValueIterator;

  typedef std::vector<store::IndexDelta::GeneralPair>::iterator
  GeneralIterator;

  typedef std::vector<store::IndexDelta::GeneralPair>::reverse_iterator
  ReverseGeneralIterator;

public:
  IndexDeltaImpl() { }

  ValueDelta& getValueDelta() { return theValueDelta; }

  GeneralDelta& getGeneralDelta() { return theGeneralDelta; }
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
