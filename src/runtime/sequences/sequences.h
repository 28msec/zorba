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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************

#ifndef ZORBA_RUNTIME_SEQUENCES_SEQUENCES_H
#define ZORBA_RUNTIME_SEQUENCES_SEQUENCES_H

#include "runtime/base/narybase.h"

#include "runtime/core/path_iterators.h"

namespace zorba {

namespace store{
  class NodeHashSet;
}

/**
 * op:concatenate
 * 
 * Author: Zorba Team * 
 */
class FnConcatIteratorState : public PlanIteratorState
{
public:
  uint32_t theCurIter; //the current iterator

  void init(PlanState&);
  void reset(PlanState&);
};

class FnConcatIterator: public NaryBaseIterator <FnConcatIterator, FnConcatIteratorState> {
protected:
  bool theIsUpdating; //
public:
  SERIALIZABLE_CLASS(FnConcatIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnConcatIterator,
  NaryBaseIterator<FnConcatIterator, FnConcatIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnConcatIterator, FnConcatIteratorState>*)this);

    ar & theIsUpdating;
  }

  FnConcatIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren,
  bool aIsUpdating)
  :
  NaryBaseIterator<FnConcatIterator, FnConcatIteratorState>
  (sctx, loc, aChildren),
  theIsUpdating(aIsUpdating){}

  virtual ~FnConcatIterator();

  virtual bool isUpdating() const { return theIsUpdating; }

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Summary: Returns a sequence of positive integers giving the positions within the sequence $seqParam of items that are equal to $srchParam. The collation used by the invocation of this function is determined according to the rules in 7.3.1 Collations. The collation is used when string comparison is required. The items in the sequence $seqParam are compared with $srchParam under the rules for the 'eq' operator. Values that cannot be compared, i.e. the 'eq' operator is not defined for their types, are considered to be distinct. If an item compares equal, then the position of that item in the sequence $seqParam is included in the result. If the value of $seqParam is the empty sequence, or if no item in $seqParam matches $srchParam, then the empty sequence is returned. The first item in a sequence is at position 1, not position 0. The result sequence is in ascending numeric order. fn:index-of($seqParam as xs:anyAtomicType*, $srchParam as xs:anyAtomicType) as xs:integer* fn:index-of($seqParam as xs:anyAtomicType*, $srchParam as xs:anyAtomicType, $collation as xs:string) as xs:integer*
 * 
 * Author: Zorba Team * 
 */
class FnIndexOfIteratorState : public PlanIteratorState
{
public:
  uint32_t theCurrentPos; //the current position in the sequence
  store::Item_t theSearchItem; //the item to search for
  XQPCollator* theCollator; //the collator

  void init(PlanState&);
  void reset(PlanState&);
};

class FnIndexOfIterator: public NaryBaseIterator <FnIndexOfIterator, FnIndexOfIteratorState> {
public:
  SERIALIZABLE_CLASS(FnIndexOfIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnIndexOfIterator,
  NaryBaseIterator<FnIndexOfIterator, FnIndexOfIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnIndexOfIterator, FnIndexOfIteratorState>*)this);

  }

  FnIndexOfIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnIndexOfIterator, FnIndexOfIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnIndexOfIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * If the value of $arg is the empty sequence, the function returns true; otherwise, the function returns false.
 * 
 * Author: Zorba Team * 
 */
class FnEmptyIterator: public NaryBaseIterator <FnEmptyIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(FnEmptyIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnEmptyIterator,
  NaryBaseIterator<FnEmptyIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnEmptyIterator, PlanIteratorState>*)this);

  }

  FnEmptyIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnEmptyIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnEmptyIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * If the value of $arg is not the empty sequence, the function returns true; otherwise, the function returns false.
 * 
 * Author: Zorba Team * 
 */
class FnExistsIterator: public NaryBaseIterator <FnExistsIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(FnExistsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnExistsIterator,
  NaryBaseIterator<FnExistsIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnExistsIterator, PlanIteratorState>*)this);

  }

  FnExistsIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnExistsIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnExistsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Returns a new sequence constructed from the value of the first parameter with the value of third parameter inserted at the position specified by the value of the second parameter.
 * 
 * Author: Zorba Team * 
 */
class FnInsertBeforeIteratorState : public PlanIteratorState
{
public:
  xqp_integer theCurrentPos; //the current position in the sequence
  xqp_integer thePosition; //
  store::Item_t theTargetItem; //

  void init(PlanState&);
  void reset(PlanState&);
};

class FnInsertBeforeIterator: public NaryBaseIterator <FnInsertBeforeIterator, FnInsertBeforeIteratorState> {
public:
  SERIALIZABLE_CLASS(FnInsertBeforeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnInsertBeforeIterator,
  NaryBaseIterator<FnInsertBeforeIterator, FnInsertBeforeIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnInsertBeforeIterator, FnInsertBeforeIteratorState>*)this);

  }

  FnInsertBeforeIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnInsertBeforeIterator, FnInsertBeforeIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnInsertBeforeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Returns a new sequence constructed from the value of aTarget with the item at the position specified by the value of aPosition removed.
 * 
 * Author: Zorba Team * 
 */
class FnRemoveIteratorState : public PlanIteratorState
{
public:
  xqp_integer theCurrentPos; //the current position in the sequence
  xqp_integer thePosition; //the position to delete
  XQPCollator* theCollator; //the collator

  void init(PlanState&);
  void reset(PlanState&);
};

class FnRemoveIterator: public NaryBaseIterator <FnRemoveIterator, FnRemoveIteratorState> {
public:
  SERIALIZABLE_CLASS(FnRemoveIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnRemoveIterator,
  NaryBaseIterator<FnRemoveIterator, FnRemoveIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnRemoveIterator, FnRemoveIteratorState>*)this);

  }

  FnRemoveIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnRemoveIterator, FnRemoveIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnRemoveIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:reverse
 * 
 * Author: Zorba Team * 
 */
class FnReverseIteratorState : public PlanIteratorState
{
public:
  std::stack<store::Item_t> theStack; //

  void init(PlanState&);
  void reset(PlanState&);
};

class FnReverseIterator: public NaryBaseIterator <FnReverseIterator, FnReverseIteratorState> {
public:
  SERIALIZABLE_CLASS(FnReverseIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnReverseIterator,
  NaryBaseIterator<FnReverseIterator, FnReverseIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnReverseIterator, FnReverseIteratorState>*)this);

  }

  FnReverseIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnReverseIterator, FnReverseIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnReverseIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:subsequence
 * 
 * Author: Zorba Team * 
 */
class FnSubsequenceIteratorState : public PlanIteratorState
{
public:
  xqp_integer theRemaining; //

  void init(PlanState&);
  void reset(PlanState&);
};

class FnSubsequenceIterator: public NaryBaseIterator <FnSubsequenceIterator, FnSubsequenceIteratorState> {
public:
  SERIALIZABLE_CLASS(FnSubsequenceIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnSubsequenceIterator,
  NaryBaseIterator<FnSubsequenceIterator, FnSubsequenceIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnSubsequenceIterator, FnSubsequenceIteratorState>*)this);

  }

  FnSubsequenceIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnSubsequenceIterator, FnSubsequenceIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnSubsequenceIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:zero-or-one
 * 
 * Author: Zorba Team * 
 */
class FnZeroOrOneIterator: public NaryBaseIterator <FnZeroOrOneIterator, PlanIteratorState> {
protected:
  bool theDoDistinct; //
public:
  SERIALIZABLE_CLASS(FnZeroOrOneIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnZeroOrOneIterator,
  NaryBaseIterator<FnZeroOrOneIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnZeroOrOneIterator, PlanIteratorState>*)this);

    ar & theDoDistinct;
  }

  FnZeroOrOneIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren,
  bool doDistinct = false)
  :
  NaryBaseIterator<FnZeroOrOneIterator, PlanIteratorState>
  (sctx, loc, aChildren),
  theDoDistinct(doDistinct){}

  virtual ~FnZeroOrOneIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:one-or-more
 * 
 * Author: Zorba Team * 
 */
class FnOneOrMoreIterator: public NaryBaseIterator <FnOneOrMoreIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(FnOneOrMoreIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnOneOrMoreIterator,
  NaryBaseIterator<FnOneOrMoreIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnOneOrMoreIterator, PlanIteratorState>*)this);

  }

  FnOneOrMoreIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnOneOrMoreIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnOneOrMoreIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:exactly-one
 * 
 * Author: Zorba Team * 
 */
class FnExactlyOneIterator: public NaryBaseIterator <FnExactlyOneIterator, PlanIteratorState> {
protected:
  bool theRaiseError; //
  bool theDoDistinct; //
public:
  SERIALIZABLE_CLASS(FnExactlyOneIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnExactlyOneIterator,
  NaryBaseIterator<FnExactlyOneIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnExactlyOneIterator, PlanIteratorState>*)this);

    ar & theRaiseError;
    ar & theDoDistinct;
  }

  FnExactlyOneIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren,
  bool raiseError = true,
  bool doDistinct = false)
  :
  NaryBaseIterator<FnExactlyOneIterator, PlanIteratorState>
  (sctx, loc, aChildren),
  theRaiseError(raiseError),
  theDoDistinct(doDistinct){}

  virtual ~FnExactlyOneIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:deep-equal
 * 
 * Author: Zorba Team * 
 */
class FnDeepEqualIterator: public NaryBaseIterator <FnDeepEqualIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(FnDeepEqualIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnDeepEqualIterator,
  NaryBaseIterator<FnDeepEqualIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnDeepEqualIterator, PlanIteratorState>*)this);

  }

  FnDeepEqualIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnDeepEqualIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnDeepEqualIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * op:union : implemented using concat and sort op:intersect : implemented by the HashSemiJoinIterator below op:except : implemented by the HashSemiJoinIterator below Hashing semi/anti join iterator. First producer goes in the result if a match in the second producer is found/not found. The order of the first producer is retained. No duplicate elimination is performed.
 * 
 * Author: Zorba Team * 
 */
class HashSemiJoinIteratorState : public PlanIteratorState
{
public:
  store::NodeHashSet* theRightInput; //

  HashSemiJoinIteratorState();

  ~HashSemiJoinIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class HashSemiJoinIterator: public NaryBaseIterator <HashSemiJoinIterator, HashSemiJoinIteratorState> {
protected:
  bool theAntijoin; //
public:
  SERIALIZABLE_CLASS(HashSemiJoinIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(HashSemiJoinIterator,
  NaryBaseIterator<HashSemiJoinIterator, HashSemiJoinIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<HashSemiJoinIterator, HashSemiJoinIteratorState>*)this);

    ar & theAntijoin;
  }

  HashSemiJoinIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren,
  bool antijoin = false)
  :
  NaryBaseIterator<HashSemiJoinIterator, HashSemiJoinIteratorState>
  (sctx, loc, aChildren),
  theAntijoin(antijoin){}

  virtual ~HashSemiJoinIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Sortmerge based semijoin iterator. First producer goes in the result if a match in the second producer is found. Precondition: both inputs must be sorted. Postcondition: the order of the first producer is retained. If either of the inputs is guaranteed to contain no duplicates, then the output will be duplicate-free. Otherwise the output may contain duplicates.
 * 
 * Author: Zorba Team * 
 */
class SortSemiJoinIterator: public NaryBaseIterator <SortSemiJoinIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(SortSemiJoinIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(SortSemiJoinIterator,
  NaryBaseIterator<SortSemiJoinIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<SortSemiJoinIterator, PlanIteratorState>*)this);

  }

  SortSemiJoinIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<SortSemiJoinIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~SortSemiJoinIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:count
 * 
 * Author: Zorba Team * 
 */
class FnCountIterator: public NaryBaseIterator <FnCountIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(FnCountIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnCountIterator,
  NaryBaseIterator<FnCountIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnCountIterator, PlanIteratorState>*)this);

  }

  FnCountIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnCountIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnCountIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:avg
 * 
 * Author: Zorba Team * 
 */
class FnAvgIterator: public NaryBaseIterator <FnAvgIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(FnAvgIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnAvgIterator,
  NaryBaseIterator<FnAvgIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnAvgIterator, PlanIteratorState>*)this);

  }

  FnAvgIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnAvgIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnAvgIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:sum
 * 
 * Author: Zorba Team * 
 */
class FnSumIterator: public NaryBaseIterator <FnSumIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(FnSumIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnSumIterator,
  NaryBaseIterator<FnSumIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnSumIterator, PlanIteratorState>*)this);

  }

  FnSumIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnSumIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnSumIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:sum with arguments xs:double
 * 
 * Author: Zorba Team * 
 */
class FnSumDoubleIterator: public NaryBaseIterator <FnSumDoubleIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(FnSumDoubleIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnSumDoubleIterator,
  NaryBaseIterator<FnSumDoubleIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnSumDoubleIterator, PlanIteratorState>*)this);

  }

  FnSumDoubleIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnSumDoubleIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnSumDoubleIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:sum with arguments xs:float
 * 
 * Author: Zorba Team * 
 */
class FnSumFloatIterator: public NaryBaseIterator <FnSumFloatIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(FnSumFloatIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnSumFloatIterator,
  NaryBaseIterator<FnSumFloatIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnSumFloatIterator, PlanIteratorState>*)this);

  }

  FnSumFloatIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnSumFloatIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnSumFloatIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:sum with arguments xs:decimal
 * 
 * Author: Zorba Team * 
 */
class FnSumDecimalIterator: public NaryBaseIterator <FnSumDecimalIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(FnSumDecimalIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnSumDecimalIterator,
  NaryBaseIterator<FnSumDecimalIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnSumDecimalIterator, PlanIteratorState>*)this);

  }

  FnSumDecimalIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnSumDecimalIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnSumDecimalIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:sum with arguments xs:integer
 * 
 * Author: Zorba Team * 
 */
class FnSumIntegerIterator: public NaryBaseIterator <FnSumIntegerIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(FnSumIntegerIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnSumIntegerIterator,
  NaryBaseIterator<FnSumIntegerIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnSumIntegerIterator, PlanIteratorState>*)this);

  }

  FnSumIntegerIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnSumIntegerIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnSumIntegerIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * op:to
 * 
 * Author: Zorba Team * 
 */
class OpToIteratorState : public PlanIteratorState
{
public:
  xqp_integer theCurInt; //the current integer
  xqp_integer theFirstVal; //first integer
  xqp_integer theLastVal; //last integer

  void init(PlanState&);
  void reset(PlanState&);
};

class OpToIterator: public NaryBaseIterator <OpToIterator, OpToIteratorState> {
public:
  SERIALIZABLE_CLASS(OpToIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(OpToIterator,
  NaryBaseIterator<OpToIterator, OpToIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<OpToIterator, OpToIteratorState>*)this);

  }

  OpToIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<OpToIterator, OpToIteratorState>
  (sctx, loc, aChildren){}

  virtual ~OpToIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:doc
 * 
 * Author: Zorba Team * 
 */
class FnDocIterator: public NaryBaseIterator <FnDocIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(FnDocIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnDocIterator,
  NaryBaseIterator<FnDocIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnDocIterator, PlanIteratorState>*)this);

  }

  FnDocIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnDocIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnDocIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * fn:doc-available
 * 
 * Author: Zorba Team * 
 */
class FnDocAvailableIterator: public NaryBaseIterator <FnDocAvailableIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(FnDocAvailableIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnDocAvailableIterator,
  NaryBaseIterator<FnDocAvailableIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnDocAvailableIterator, PlanIteratorState>*)this);

  }

  FnDocAvailableIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnDocAvailableIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnDocAvailableIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * Zorba-defined parse function
 * 
 * Author: Zorba Team * 
 */
class FnParseIterator: public NaryBaseIterator <FnParseIterator, PlanIteratorState> {
public:
  SERIALIZABLE_CLASS(FnParseIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(FnParseIterator,
  NaryBaseIterator<FnParseIterator, PlanIteratorState>);

  void serialize(::zorba::serialization::Archiver& ar){
    serialize_baseclass(ar,
    (NaryBaseIterator<FnParseIterator, PlanIteratorState>*)this);

  }

  FnParseIterator(static_context* sctx, const QueryLoc& loc,
  std::vector<PlanIter_t>& aChildren)
  :
  NaryBaseIterator<FnParseIterator, PlanIteratorState>
  (sctx, loc, aChildren){}

  virtual ~FnParseIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};



}

#endif 
