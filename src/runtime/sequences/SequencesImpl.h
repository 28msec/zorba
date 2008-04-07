/**
 * Copyright FLWOR Foundation
 *
 * Author: David Graf (david.graf@28msec.com)
 *         Matthias Brantner (matthias.brantner@28msec.com)
 */

#ifndef ZORBA_SEQUENCES_IMPL_H
#define ZORBA_SEQUENCES_IMPL_H

#include <vector>
#include <stack>

#include "common/shared_types.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/binarybase.h"
#include "runtime/base/narybase.h"
#include "runtime/booleans/compare_types.h"

namespace zorba
{
  namespace store {
    class ItemValueCollHandleHashSet;
    class ValueCollCompareParam;
  }

  /*______________________________________________________________________
  |
  | 15.1 General Functions and Operators on Sequences
  |_______________________________________________________________________*/

//15.1.1 fn:boolean
// see BooleanImpl.h

//15.1.2 op:concatenate
class FnConcatIteratorState : public  PlanIteratorState 
{
public:
  uint32_t theCurIter;

  void init(PlanState&);
  void reset(PlanState&);
};


class FnConcatIterator : public NaryBaseIterator<FnConcatIterator,
                                                 FnConcatIteratorState>
{
protected:
  bool  theIsUpdate;

public:
  FnConcatIterator(const QueryLoc& loc, std::vector<PlanIter_t>& aChildren)
    :
    NaryBaseIterator<FnConcatIterator, FnConcatIteratorState>(loc, aChildren)
  {
    theIsUpdate = (!theChildren.empty() && theChildren[0]->isUpdateIterator());
  }                                                               
                                                                        
  virtual ~FnConcatIterator() { }                                               

  bool isUpdateIterator() const { return theIsUpdate; }

  store::Item_t nextImpl(PlanState& aPlanState) const;

  virtual void accept(PlanIterVisitor& v) const;
};


//15.1.3 fn:index-of
/*
 * If the value of $arg is the empty sequence, the function returns true; 
 * otherwise, the function returns false.
 */
class FnIndexOfIteratorState : public PlanIteratorState {
public:  
  uint32_t theCurrentPos; // the current position in the sequence
  store::Item_t   theSearchItem; // the item to search for
  XQPCollator* theCollator;

  void init(PlanState&);
  void reset(PlanState&);
  
};

NARY_ITER_STATE(FnIndexOfIterator, FnIndexOfIteratorState);

//15.1.4 fn:empty
/*
 * If the value of $arg is the empty sequence, the function returns true; 
 * otherwise, the function returns false.
 */
NARY_ITER(FnEmptyIterator);


//15.1.5 fn:exists
/*
 * If the value of $arg is not the empty sequence, the function returns true; 
 * otherwise, the function returns false.
 */
NARY_ITER(FnExistsIterator);

//15.1.6 fn:distinct-values
class FnDistinctValuesIteratorState : public PlanIteratorState {
public:  
  store::ItemValueCollHandleHashSet* theAlreadySeenMap;
  store::ValueCollCompareParam* theValueCompareParam;

  FnDistinctValuesIteratorState();
  ~FnDistinctValuesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};
  
class FnDistinctValuesIterator : public NaryBaseIterator<FnDistinctValuesIterator, 
                                                         FnDistinctValuesIteratorState>
{

public:
  FnDistinctValuesIterator(const QueryLoc& loc,
                           std::vector<PlanIter_t>& args);
 
  ~FnDistinctValuesIterator();

  store::Item_t 
  nextImpl(PlanState& planState) const;
 
  virtual void 
  accept(PlanIterVisitor&) const;

};



//15.1.7 fn:insert-before
// Returns a new sequence constructed from the value of the first parameter with the value of third parameter inserted 
// at the position specified by the value of the second parameter. 
class FnInsertBeforeIteratorState : public PlanIteratorState { 
public:  
  xqp_integer theCurrentPos; // the current position in the sequence
  xqp_integer thePosition;
  store::Item_t      theTargetItem;

  void init(PlanState&);
  void reset(PlanState&);
};

NARY_ITER_STATE(FnInsertBeforeIterator, FnInsertBeforeIteratorState);

//15.1.8 fn:remove
// Returns a new sequence constructed from the value of aTarget with the item at the position specified by the 
// value of aPosition removed.
class FnRemoveIteratorState : public PlanIteratorState {
public:  
  xqp_integer theCurrentPos; // the current position in the sequence
  xqp_integer thePosition; // the position to delete
  XQPCollator* theCollator;

  void init(PlanState&);
  void reset(PlanState&);
};

NARY_ITER_STATE(FnRemoveIterator, FnRemoveIteratorState);


//15.1.9 fn:reverse
class FnReverseIteratorState : public PlanIteratorState {
  public:
    std::stack<store::Item_t> theStack;

    void init(PlanState&);
    void reset(PlanState&);
};

NARY_ITER_STATE(FnReverseIterator, FnReverseIteratorState);

//15.1.10 fn:subsequence
// Returns the contiguous sequence of items in the value of $sourceSeq beginning at the position indicated by the value 
// of $startingLoc and continuing for the number of items indicated by the value of $length.
class FnSubsequenceIteratorState : public PlanIteratorState {
public:
  xqp_double  theStartingLoc; // second argument (startingLoc)
  xqp_double  theLength; // third optional argument (length)

  xqp_integer theCurrentPos; // the current position in the sequence
  xqp_integer theCurrentLength; // used for returning a specific number of items

  void init(PlanState&);
  void reset(PlanState&);  
};
NARY_ITER_STATE(FnSubsequenceIterator, FnSubsequenceIteratorState);

//15.1.11 fn:unordered
// no need to implement an operator for his


  /*______________________________________________________________________
  |
  | 15.2 Functions That Test the Cardinality of Sequences
  |_______________________________________________________________________*/

//15.2.1 fn:zero-or-one
NARY_ITER(FnZeroOrOneIterator);

//15.2.2 fn:one-or-more
NARY_ITER(FnOneOrMoreIterator);

//15.2.3 fn:exactly-one
class FnExactlyOneIterator
  : public NaryBaseIterator<FnExactlyOneIterator, PlanIteratorState>
{

public:
  FnExactlyOneIterator(const QueryLoc& loc,
                       std::vector<PlanIter_t>& args,
                       bool raise_err_ = true)
    : NaryBaseIterator<FnExactlyOneIterator, PlanIteratorState> (loc, args), raise_err (raise_err_)
  {}
 
  store::Item_t nextImpl(PlanState& planState) const;
 
  virtual void accept(PlanIterVisitor& v) const
  {
    v.beginVisit(*this);
    std::vector<PlanIter_t>::const_iterator iter =  theChildren.begin();
    std::vector<PlanIter_t>::const_iterator lEnd =  theChildren.end();
    for ( ; iter != lEnd; ++iter ) {
      ( *iter )->accept ( v );
    }
    v.endVisit(*this);
  }

protected:
  bool raise_err;

};

  /*______________________________________________________________________
  |
  | 15.3 Equals, Union, Intersection and Except
  |_______________________________________________________________________*/

//15.3.1 fn:deep-equal

NARY_ITER (FnDeepEqualIterator_3);

//15.3.2 op:union
// implemented using concat and sort

//15.3.3 op:intersect
//15.3.4 op:except

namespace store {
    class NodeHashSet;
}

/**
 * Hashing semi(anti)join iterator.
 *
 * First producer goes in the result if a match in the second producer is found/not found.
 * The order of the first producer is retained.
 * No duplicate elimination is performed.
 */
class HashSemiJoinIteratorState : public PlanIteratorState {
public:
  store::NodeHashSet* theRightInput;

  HashSemiJoinIteratorState();
  ~HashSemiJoinIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};


class HashSemiJoinIterator: public NaryBaseIterator<HashSemiJoinIterator, 
                                                HashSemiJoinIteratorState>
{

public:
  HashSemiJoinIterator(const QueryLoc& loc,
                   std::vector<PlanIter_t>& args,
                   bool antijoin = false);
 
  ~HashSemiJoinIterator();

  store::Item_t 
  nextImpl(PlanState& planState) const;
 
  virtual void 
  accept(PlanIterVisitor&) const;

protected:
  bool theAntijoin;

};

/**
 * Sortmerge based semijoin iterator.
 *
 * First producer goes in the result if a match in the second producer is found.
 * Precondition: both inputs must be sorted.
 * Postcondition: the order of the first producer is retained.
 * If either of the inputs is guaranteed to contain no duplicates,
 * then the output will be duplicate-free. Otherwise the output
 * may contain duplicates.
 */
class SortSemiJoinIterator : public NaryBaseIterator<SortSemiJoinIterator, 
                                                     PlanIteratorState>
{

public:
  SortSemiJoinIterator(const QueryLoc& loc, std::vector<PlanIter_t>& args);
 
  ~SortSemiJoinIterator();

  store::Item_t 
  nextImpl(PlanState& planState) const;
 
  virtual void 
  accept(PlanIterVisitor&) const;
};

  /*______________________________________________________________________
  |
  | 15.4 Aggregate Functions
  |_______________________________________________________________________*/

//15.4.1 fn:count
NARY_ITER(FnCountIterator);

//15.4.2 fn:avg
NARY_ITER(FnAvgIterator);

//15.4.3 fn:max & 15.4.4 fn:min
class FnMinMaxIterator : public NaryBaseIterator<FnMinMaxIterator, PlanIteratorState> {
public:
  enum Type {
    MIN = 0,
    MAX
  };

private:
  Type theType;
  CompareConsts::CompareType theCompareType;

public:
    FnMinMaxIterator(const QueryLoc& loc, std::vector<PlanIter_t>& aChildren, Type aType);
    store::Item_t nextImpl(PlanState& aPlanState) const;
    virtual void accept(PlanIterVisitor& v) const;
    Type getType() const { return theType; }
};


//15.4.5 fn:sum
NARY_ITER(FnSumIterator);

  /*______________________________________________________________________
  |
  | 15.5 Functions and Operators that Generate Sequences
  |_______________________________________________________________________*/

//15.5.1 op:to
class OpToIteratorState : public PlanIteratorState {
public:
  xqp_integer theCurInt;
  xqp_integer theFirstVal;
  xqp_integer theLastVal;

  void init(PlanState&);
  void reset(PlanState&);
  
};

NARY_ITER_STATE(OpToIterator, OpToIteratorState);

//15.5.2 fn:id
class FnIdIteratorState : public PlanIteratorState {
  public:
    Iterator_t    theIterator;
    Iterator_t    theTypedValue;
    store::Item_t inNode;
    store::Item_t inArg;

    void init(PlanState&);
    void reset(PlanState&);
};
NARY_ITER_STATE(FnIdIterator, FnIdIteratorState);

//15.5.3 fn:idref
class FnIdRefIteratorState : public PlanIteratorState {
  public:
    Iterator_t    theIterator;
    store::Item_t inNode;
    store::Item_t inArg;

    void init(PlanState&);
    void reset(PlanState&);
};
NARY_ITER_STATE(FnIdRefIterator, FnIdRefIteratorState);

//15.5.4 fn:doc

class FnDocIterator : public UnaryBaseIterator<FnDocIterator, PlanIteratorState>
{
public:
  FnDocIterator(const QueryLoc& loc, PlanIter_t& arg);
  virtual ~FnDocIterator();

  store::Item_t nextImpl(PlanState& planState) const;
  
  virtual void accept(PlanIterVisitor&) const;
};


//15.5.5 fn:doc-available
NARY_ITER(FnDocAvailableIterator);


//15.5.6 fn:collection


  /*______________________________________________________________________
  |
  | Extensions
  |_______________________________________________________________________*/


} /* namespace zorba */
#endif /* ZORBA_SEQUENCES_H */
/* vim:set ts=2 sw=2: */
