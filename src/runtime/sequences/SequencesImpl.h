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
#ifndef ZORBA_SEQUENCES_IMPL_H
#define ZORBA_SEQUENCES_IMPL_H

#include <memory>
#include <vector>
#include <stack>

#include "common/shared_types.h"

#include "runtime/base/unarybase.h"
#include "runtime/base/binarybase.h"
#include "runtime/base/narybase.h"
#include "runtime/core/path_iterators.h"

#include "store/api/iterator.h"
#include "store/api/iterator_factory.h"

namespace zorba
{

namespace store 
{
  class NodeHashSet;
}

class ItemValueCollHandleHashSet;
class ValueCollCompareParam;


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  15.1 General Functions and Operators on Sequences                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


// 15.1.1 fn:boolean : see BooleanImpl.h


/*******************************************************************************
  15.1.2 op:concatenate
********************************************************************************/
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
  bool  theIsUpdating;

public:
  SERIALIZABLE_CLASS(FnConcatIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  FnConcatIterator, 
  NaryBaseIterator<FnConcatIterator, FnConcatIteratorState >);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, 
    (NaryBaseIterator<FnConcatIterator, FnConcatIteratorState >*)this);

    ar & theIsUpdating;
  }

public:
  FnConcatIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& aChildren,
        bool aIsUpdating)
    :
    NaryBaseIterator<FnConcatIterator, FnConcatIteratorState>(sctx, loc, aChildren),
    theIsUpdating(aIsUpdating)
  { }                                                               
                                                                        
  virtual ~FnConcatIterator() { }                                               

  virtual bool isUpdating() const { return theIsUpdating; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};



/*******************************************************************************
  15.1.3 fn:index-of

 fn:index-of($seqParam as xs:anyAtomicType*,
             $srchParam as xs:anyAtomicType) as xs:integer*

 fn:index-of($seqParam as xs:anyAtomicType*,
             $srchParam as xs:anyAtomicType,
             $collation as xs:string) as xs:integer*
 	
 Summary: Returns a sequence of positive integers giving the positions 
 within the sequence $seqParam of items that are equal to $srchParam. 
 
 The collation used by the invocation of this function is determined 
 according to the rules in 7.3.1 Collations. The collation is used when 
 string comparison is required. 
 
  The items in the sequence $seqParam are compared with $srchParam under 
 	the rules for the 'eq' operator. Values that cannot be compared, i.e. 
 	the 'eq' operator is not defined for their types, are considered to be 
 	distinct. If an item compares equal, then the position of that item in 
 	the sequence $seqParam is included in the result. 
 
 	If the value of $seqParam is the empty sequence, or if no item in 
 	$seqParam matches $srchParam, then the empty sequence is returned. 
 
 	The first item in a sequence is at position 1, not position 0.
 	The result sequence is in ascending numeric order.
********************************************************************************/
class FnIndexOfIteratorState : public PlanIteratorState 
{
public:  
  uint32_t        theCurrentPos; // the current position in the sequence
  store::Item_t   theSearchItem; // the item to search for
  XQPCollator   * theCollator;

public:
  void init(PlanState&);
  void reset(PlanState&);
};


NARY_ITER_STATE(FnIndexOfIterator, FnIndexOfIteratorState);



/*******************************************************************************
  15.1.4 fn:empty

  If the value of $arg is the empty sequence, the function returns true; 
  otherwise, the function returns false.
********************************************************************************/
NARY_ITER(FnEmptyIterator);


/*******************************************************************************
  15.1.5 fn:exists

  If the value of $arg is not the empty sequence, the function returns true; 
  otherwise, the function returns false.
********************************************************************************/
NARY_ITER(FnExistsIterator);


/*******************************************************************************
  15.1.6 fn:distinct-values

  Returns the sequence that results from removing from arg all but one of a 
  set of values that are eq to one other. The order in which the sequence of
  values is returned is implementation dependent. Here, we return the first
  item that is not a duplicate and throw away the remaining ones.
********************************************************************************/
class FnDistinctValuesIteratorState : public PlanIteratorState 
{
public:  
  bool theHasNaN;
  std::auto_ptr<ItemValueCollHandleHashSet> theAlreadySeenMap;

  FnDistinctValuesIteratorState();

  ~FnDistinctValuesIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};
  

NARY_ITER_STATE(FnDistinctValuesIterator, FnDistinctValuesIteratorState);


/*******************************************************************************
  15.1.7 fn:insert-before

  Returns a new sequence constructed from the value of the first parameter with
  the value of third parameter inserted at the position specified by the value
  of the second parameter. 
********************************************************************************/ 
class FnInsertBeforeIteratorState : public PlanIteratorState 
{ 
public:  
  xqp_integer    theCurrentPos; // the current position in the sequence
  xqp_integer    thePosition;
  store::Item_t  theTargetItem;

  void init(PlanState&);
  void reset(PlanState&);
};

NARY_ITER_STATE(FnInsertBeforeIterator, FnInsertBeforeIteratorState);


/*******************************************************************************
  15.1.8 fn:remove
********************************************************************************/
// Returns a new sequence constructed from the value of aTarget with the item at the position specified by the 
// value of aPosition removed.
class FnRemoveIteratorState : public PlanIteratorState 
{
public:  
  xqp_integer theCurrentPos; // the current position in the sequence
  xqp_integer thePosition; // the position to delete
  XQPCollator* theCollator;

  void init(PlanState&);
  void reset(PlanState&);
};


NARY_ITER_STATE(FnRemoveIterator, FnRemoveIteratorState);


/*******************************************************************************
  15.1.9 fn:reverse
********************************************************************************/
class FnReverseIteratorState : public PlanIteratorState 
{
public:
  std::stack<store::Item_t> theStack;

  void init(PlanState&);
  void reset(PlanState&);
};


NARY_ITER_STATE(FnReverseIterator, FnReverseIteratorState);


/*******************************************************************************
  15.1.10 fn:subsequence

  Returns the contiguous sequence of items in the value of $sourceSeq beginning
  at the position indicated by the value of $startingLoc and continuing for the
  number of items indicated by the value of $length.
********************************************************************************/
class FnSubsequenceIteratorState : public PlanIteratorState 
{
public:
  xqp_integer theRemaining;

  void init(PlanState&);
  void reset(PlanState&);  
};


NARY_ITER_STATE(FnSubsequenceIterator, FnSubsequenceIteratorState);


/*******************************************************************************
  15.1.11 fn:unordered
  no need to implement an operator for his
********************************************************************************/


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  15.2 Functions That Test the Cardinality of Sequences                      //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  15.2.1 fn:zero-or-one
********************************************************************************/
class FnZeroOrOneIterator : public NaryBaseIterator<FnZeroOrOneIterator,
                                                    PlanIteratorState>
{
protected:
  bool theDoDistinct;

public:
  SERIALIZABLE_CLASS(FnZeroOrOneIterator)

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  FnZeroOrOneIterator,
  NaryBaseIterator<FnZeroOrOneIterator, PlanIteratorState >)

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (NaryBaseIterator<FnZeroOrOneIterator,
                                              PlanIteratorState >*)this);
    ar & theDoDistinct;
  }

public:
  FnZeroOrOneIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& args,
        bool doDistinct = false)
    :
    NaryBaseIterator<FnZeroOrOneIterator, PlanIteratorState>(sctx, loc, args),
    theDoDistinct(doDistinct)
  {}
 
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************
  15.2.2 fn:one-or-more
********************************************************************************/
NARY_ITER(FnOneOrMoreIterator);


/*******************************************************************************
  15.2.3 fn:exactly-one
********************************************************************************/
class FnExactlyOneIterator : public NaryBaseIterator<FnExactlyOneIterator,
                                                     PlanIteratorState>
{
protected:
  bool theDoDistinct;
  bool theRaiseError;

public:
  SERIALIZABLE_CLASS(FnExactlyOneIterator)

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  FnExactlyOneIterator,
  NaryBaseIterator<FnExactlyOneIterator, PlanIteratorState >)

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (NaryBaseIterator<FnExactlyOneIterator,
                                              PlanIteratorState >*)this);
    ar & theDoDistinct;
    ar & theRaiseError;
  }

public:
  FnExactlyOneIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& args,
        bool raiseError = true,
        bool doDistinct = false)
    :
    NaryBaseIterator<FnExactlyOneIterator, PlanIteratorState>(sctx, loc, args),
    theDoDistinct(doDistinct),
    theRaiseError(raiseError)
  {}
 
  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  15.3 Deep Equal, Union, Intersection, and Except                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  15.3.1 fn:deep-equal
********************************************************************************/
class FnDeepEqualIterator : public NaryBaseIterator<FnDeepEqualIterator,
                                                    PlanIteratorState>
{
public:
  SERIALIZABLE_CLASS(FnDeepEqualIterator)
  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnDeepEqualIterator,
                                   NaryBaseIterator<FnDeepEqualIterator,
                                                    PlanIteratorState>)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (NaryBaseIterator<FnDeepEqualIterator,
                                              PlanIteratorState >*)this);
  }

public:
  FnDeepEqualIterator(
        static_context* sctx,
        const QueryLoc& loc, 
        std::vector<PlanIter_t>& args) 
    :
    NaryBaseIterator<FnDeepEqualIterator, PlanIteratorState>(sctx, loc, args)
  {
  }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const; 
};



/*******************************************************************************
  15.3.2 op:union : implemented using concat and sort
********************************************************************************/


/*******************************************************************************

  15.3.3 op:intersect : implemented by the HashSemiJoinIterator below

  15.3.4 op:except : implemented by the HashSemiJoinIterator below

  Hashing semi/anti join iterator.
 
  First producer goes in the result if a match in the second producer is 
  found/not found. The order of the first producer is retained. No duplicate
  elimination is performed.
********************************************************************************/
class HashSemiJoinIteratorState : public PlanIteratorState 
{
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
protected:
  bool theAntijoin;

public:
  SERIALIZABLE_CLASS(HashSemiJoinIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  HashSemiJoinIterator,
  NaryBaseIterator<HashSemiJoinIterator, HashSemiJoinIteratorState >);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<HashSemiJoinIterator, HashSemiJoinIteratorState >*)this);

    ar & theAntijoin;
  }

public:
  HashSemiJoinIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& args,
        bool antijoin = false);
 
  ~HashSemiJoinIterator() {}

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& planState) const;
};


/*******************************************************************************
  Sortmerge based semijoin iterator.
 
  First producer goes in the result if a match in the second producer is found.
  Precondition: both inputs must be sorted.
  Postcondition: the order of the first producer is retained.

  If either of the inputs is guaranteed to contain no duplicates, then the
  output will be duplicate-free. Otherwise the output may contain duplicates.
********************************************************************************/
NARY_ITER(SortSemiJoinIterator);


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
// 15.4 Aggregate Functions                                                    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  15.4.1 fn:count
********************************************************************************/
NARY_ITER(FnCountIterator);


/*******************************************************************************
  15.4.2 fn:avg
********************************************************************************/
NARY_ITER(FnAvgIterator);


/*******************************************************************************
  15.4.3 fn:max
  15.4.4 fn:min
********************************************************************************/
class FnMinMaxIterator : public NaryBaseIterator<FnMinMaxIterator, PlanIteratorState> 
{
public:
  enum Type {
    MIN = 0,
    MAX
  };

private:
  Type                       theType;
  CompareConsts::CompareType theCompareType;

public:
  SERIALIZABLE_CLASS(FnMinMaxIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(
  FnMinMaxIterator,
  NaryBaseIterator<FnMinMaxIterator, PlanIteratorState >);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<FnMinMaxIterator, PlanIteratorState >*)this);

    SERIALIZE_ENUM(Type, theType);
    SERIALIZE_ENUM(CompareConsts::CompareType, theCompareType);
  }

public:
  FnMinMaxIterator(
        static_context* sctx,
        const QueryLoc& loc,
        std::vector<PlanIter_t>& aChildren, 
        Type aType);

  Type getType() const { return theType; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/*******************************************************************************
  15.4.5 fn:sum
********************************************************************************/
NARY_ITER(FnSumIterator);

NARY_ITER(FnSumDoubleIterator);

NARY_ITER(FnSumFloatIterator);

NARY_ITER(FnSumDecimalIterator);

NARY_ITER(FnSumIntegerIterator);



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  15.5 Functions and Operators that Generate Sequences                       //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  15.5.1 op:to
********************************************************************************/
class OpToIteratorState : public PlanIteratorState 
{
public:
  xqp_integer theCurInt;
  xqp_integer theFirstVal;
  xqp_integer theLastVal;

  void init(PlanState&);
  void reset(PlanState&);
  
};

NARY_ITER_STATE(OpToIterator, OpToIteratorState);


/*******************************************************************************
  15.5.2 fn:id
********************************************************************************/
class FnIdIteratorState : public DescendantAxisState
{
public:
  bool                                theIsInitialized;
  std::vector<xqpStringStore_t>       theIds;
  store::Item_t                       theDocNode;

  rchandle<store::AttributesIterator> theAttrsIte;

  void init(PlanState&);
  void reset(PlanState&);
};


NARY_ITER_STATE(FnIdIterator, FnIdIteratorState);


/*******************************************************************************
  15.5.3 fn:idref
********************************************************************************/
class FnIdRefIteratorState : public DescendantAxisState
{
public:
  bool                                theIsInitialized;
  std::vector<xqpStringStore_t>       theIds;
  store::Item_t                       theDocNode;

  rchandle<store::AttributesIterator> theAttrsIte;

  void init(PlanState&);
  void reset(PlanState&);
};


NARY_ITER_STATE(FnIdRefIterator, FnIdRefIteratorState);


/*******************************************************************************
  15.5.4 fn:doc

   fn:doc($uri as xs:string?) as document-node()?
 
  Summary: Retrieves a document using an xs:anyURI, which may include a 
  fragment identifier, supplied as an xs:string. If $uri is not a valid 
  xs:anyURI, an error is raised [err:FODC0005]. If it is a relative URI 
  Reference, it is resolved relative to the value of the base URI 
  property from the static context. The resulting absolute URI Reference 
  is promoted to an xs:string. If the Available documents discussed in 
  Section 2.1.2 Dynamic ContextXP provides a mapping from this string to 
  a document node, the function returns that document node. If the 
  Available documents maps the string to an empty sequence, then the 
  function returns an empty sequence. If the Available documents 
  provides no mapping for the string, an error is raised [err:FODC0005]. 
 
  If $uri is the empty sequence, the result is an empty sequence.
********************************************************************************/
NARY_ITER(FnDocIterator);


/*******************************************************************************
  15.5.5 fn:doc-available
********************************************************************************/
NARY_ITER(FnDocAvailableIterator);


/*******************************************************************************
  Zorba-defined parse function
********************************************************************************/
NARY_ITER(FnParseIterator);


} /* namespace zorba */
#endif 

/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
