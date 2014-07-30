/*
 * Copyright 2006-2012 The FLWOR Foundation.
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


#include "stdafx.h"
#include "zorbatypes/rchandle.h"
#include "zorbatypes/zstring.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/sequences/sequences.h"
#include "system/globalenv.h"


#include "zorbautils/hashset_atomic_itemh.h"

namespace zorba {

// <FnConcatIterator>
SERIALIZABLE_CLASS_VERSIONS(FnConcatIterator)

void FnConcatIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnConcatIterator, FnConcatIteratorState>*)this);
}


void FnConcatIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnConcatIterator::~FnConcatIterator() {}

FnConcatIteratorState::FnConcatIteratorState() {}

FnConcatIteratorState::~FnConcatIteratorState() {}


zstring FnConcatIterator::getNameAsString() const {
  return "op:concatenate";
}
// </FnConcatIterator>


// <FnIndexOfIterator>
SERIALIZABLE_CLASS_VERSIONS(FnIndexOfIterator)

void FnIndexOfIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnIndexOfIterator, FnIndexOfIteratorState>*)this);

    ar & theFastComp;
}


void FnIndexOfIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnIndexOfIterator::~FnIndexOfIterator() {}

FnIndexOfIteratorState::FnIndexOfIteratorState() {}

FnIndexOfIteratorState::~FnIndexOfIteratorState() {}


void FnIndexOfIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theCurrentPos = 0;
  theSearchItem = NULL;
  theCollator = 0;
}

void FnIndexOfIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurrentPos = 0;
  theSearchItem = NULL;
  theCollator = 0;
}

zstring FnIndexOfIterator::getNameAsString() const {
  return "fn:index-of";
}
// </FnIndexOfIterator>


// <FnEmptyIterator>
SERIALIZABLE_CLASS_VERSIONS(FnEmptyIterator)

void FnEmptyIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnEmptyIterator, PlanIteratorState>*)this);
}


void FnEmptyIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnEmptyIterator::~FnEmptyIterator() {}


zstring FnEmptyIterator::getNameAsString() const {
  return "fn:empty";
}
// </FnEmptyIterator>


// <FnExistsIterator>
SERIALIZABLE_CLASS_VERSIONS(FnExistsIterator)

void FnExistsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnExistsIterator, PlanIteratorState>*)this);
}


void FnExistsIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnExistsIterator::~FnExistsIterator() {}


zstring FnExistsIterator::getNameAsString() const {
  return "fn:exists";
}
// </FnExistsIterator>


// <FnDistinctValuesIterator>
SERIALIZABLE_CLASS_VERSIONS(FnDistinctValuesIterator)

void FnDistinctValuesIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnDistinctValuesIterator, FnDistinctValuesIteratorState>*)this);
}


void FnDistinctValuesIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnDistinctValuesIterator::~FnDistinctValuesIterator() {}

FnDistinctValuesIteratorState::FnDistinctValuesIteratorState() {}

FnDistinctValuesIteratorState::~FnDistinctValuesIteratorState() {}


void FnDistinctValuesIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theHasNaN = false;
}

zstring FnDistinctValuesIterator::getNameAsString() const {
  return "fn:distinct-values";
}
// </FnDistinctValuesIterator>


// <FnInsertBeforeIterator>
SERIALIZABLE_CLASS_VERSIONS(FnInsertBeforeIterator)

void FnInsertBeforeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnInsertBeforeIterator, FnInsertBeforeIteratorState>*)this);
}


void FnInsertBeforeIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnInsertBeforeIterator::~FnInsertBeforeIterator() {}

FnInsertBeforeIteratorState::FnInsertBeforeIteratorState() {}

FnInsertBeforeIteratorState::~FnInsertBeforeIteratorState() {}


void FnInsertBeforeIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theCurrentPos = numeric_consts<xs_integer>::zero();
  thePosition = numeric_consts<xs_integer>::zero();
  theTargetItem = NULL;
}

void FnInsertBeforeIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurrentPos = numeric_consts<xs_integer>::zero();
  thePosition = numeric_consts<xs_integer>::zero();
  theTargetItem = NULL;
}

zstring FnInsertBeforeIterator::getNameAsString() const {
  return "fn:insert-before";
}
// </FnInsertBeforeIterator>


// <FnRemoveIterator>
SERIALIZABLE_CLASS_VERSIONS(FnRemoveIterator)

void FnRemoveIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnRemoveIterator, FnRemoveIteratorState>*)this);
}


void FnRemoveIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnRemoveIterator::~FnRemoveIterator() {}

FnRemoveIteratorState::FnRemoveIteratorState() {}

FnRemoveIteratorState::~FnRemoveIteratorState() {}


void FnRemoveIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theCurrentPos = numeric_consts<xs_integer>::zero();
  thePosition = numeric_consts<xs_integer>::zero();
  theCollator = 0;
}

void FnRemoveIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurrentPos = numeric_consts<xs_integer>::zero();
  thePosition = numeric_consts<xs_integer>::zero();
  theCollator = 0;
}

zstring FnRemoveIterator::getNameAsString() const {
  return "fn:remove";
}
// </FnRemoveIterator>


// <FnReverseIterator>
SERIALIZABLE_CLASS_VERSIONS(FnReverseIterator)

void FnReverseIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnReverseIterator, FnReverseIteratorState>*)this);
}


void FnReverseIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnReverseIterator::~FnReverseIterator() {}

FnReverseIteratorState::FnReverseIteratorState() {}

FnReverseIteratorState::~FnReverseIteratorState() {}


zstring FnReverseIterator::getNameAsString() const {
  return "fn:reverse";
}
// </FnReverseIterator>


// <FnSubsequenceIterator>
SERIALIZABLE_CLASS_VERSIONS(FnSubsequenceIterator)

void FnSubsequenceIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnSubsequenceIterator, FnSubsequenceIteratorState>*)this);
}


void FnSubsequenceIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnSubsequenceIterator::~FnSubsequenceIterator() {}

FnSubsequenceIteratorState::FnSubsequenceIteratorState() {}

FnSubsequenceIteratorState::~FnSubsequenceIteratorState() {}


void FnSubsequenceIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theRemaining = 0;
  theIsChildReset = false;
}

void FnSubsequenceIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theRemaining = 0;
  theIsChildReset = false;
}

zstring FnSubsequenceIterator::getNameAsString() const {
  return "fn:subsequence";
}
// </FnSubsequenceIterator>


// <SubsequenceIntIterator>
SERIALIZABLE_CLASS_VERSIONS(SubsequenceIntIterator)

void SubsequenceIntIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SubsequenceIntIterator, SubsequenceIntIteratorState>*)this);
}


void SubsequenceIntIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SubsequenceIntIterator::~SubsequenceIntIterator() {}

SubsequenceIntIteratorState::SubsequenceIntIteratorState() {}

SubsequenceIntIteratorState::~SubsequenceIntIteratorState() {}


void SubsequenceIntIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theRemaining = 0;
  theIsChildReset = false;
}

void SubsequenceIntIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theRemaining = 0;
  theIsChildReset = false;
}

zstring SubsequenceIntIterator::getNameAsString() const {
  return "op-zorba:subsequence-int";
}
// </SubsequenceIntIterator>


// <SequencePointAccessIterator>
SERIALIZABLE_CLASS_VERSIONS(SequencePointAccessIterator)

void SequencePointAccessIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SequencePointAccessIterator, SequencePointAccessIteratorState>*)this);
}


void SequencePointAccessIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SequencePointAccessIterator::~SequencePointAccessIterator() {}

SequencePointAccessIteratorState::SequencePointAccessIteratorState() {}

SequencePointAccessIteratorState::~SequencePointAccessIteratorState() {}


void SequencePointAccessIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theIsChildReset = false;
}

void SequencePointAccessIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theIsChildReset = false;
}

zstring SequencePointAccessIterator::getNameAsString() const {
  return "op-zorba:sequence-point-access";
}
// </SequencePointAccessIterator>


// <FnZeroOrOneIterator>
SERIALIZABLE_CLASS_VERSIONS(FnZeroOrOneIterator)

void FnZeroOrOneIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnZeroOrOneIterator, PlanIteratorState>*)this);

    ar & theDoDistinct;
}


void FnZeroOrOneIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnZeroOrOneIterator::~FnZeroOrOneIterator() {}


zstring FnZeroOrOneIterator::getNameAsString() const {
  return "fn:zero-or-one";
}
// </FnZeroOrOneIterator>


// <FnOneOrMoreIterator>
SERIALIZABLE_CLASS_VERSIONS(FnOneOrMoreIterator)

void FnOneOrMoreIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnOneOrMoreIterator, PlanIteratorState>*)this);
}


void FnOneOrMoreIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnOneOrMoreIterator::~FnOneOrMoreIterator() {}


zstring FnOneOrMoreIterator::getNameAsString() const {
  return "fn:one-or-more";
}
// </FnOneOrMoreIterator>


// <FnExactlyOneIterator>
SERIALIZABLE_CLASS_VERSIONS(FnExactlyOneIterator)

void FnExactlyOneIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnExactlyOneIterator, PlanIteratorState>*)this);

    ar & theRaiseError;
    ar & theDoDistinct;
}


void FnExactlyOneIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnExactlyOneIterator::~FnExactlyOneIterator() {}


zstring FnExactlyOneIterator::getNameAsString() const {
  return "FnExactlyOneIterator";
}
// </FnExactlyOneIterator>


// <FnDeepEqualIterator>
SERIALIZABLE_CLASS_VERSIONS(FnDeepEqualIterator)

void FnDeepEqualIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnDeepEqualIterator, PlanIteratorState>*)this);
}


void FnDeepEqualIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnDeepEqualIterator::~FnDeepEqualIterator() {}


zstring FnDeepEqualIterator::getNameAsString() const {
  return "fn:deep-equal";
}
// </FnDeepEqualIterator>


// <HashSemiJoinIterator>
SERIALIZABLE_CLASS_VERSIONS(HashSemiJoinIterator)

void HashSemiJoinIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<HashSemiJoinIterator, HashSemiJoinIteratorState>*)this);

    ar & theAntijoin;
}


void HashSemiJoinIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

HashSemiJoinIterator::~HashSemiJoinIterator() {}


zstring HashSemiJoinIterator::getNameAsString() const {
  return "HashSemiJoinIterator";
}
// </HashSemiJoinIterator>


// <SortSemiJoinIterator>
SERIALIZABLE_CLASS_VERSIONS(SortSemiJoinIterator)

void SortSemiJoinIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SortSemiJoinIterator, PlanIteratorState>*)this);
}


void SortSemiJoinIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SortSemiJoinIterator::~SortSemiJoinIterator() {}


zstring SortSemiJoinIterator::getNameAsString() const {
  return "SortSemiJoinIterator";
}
// </SortSemiJoinIterator>


// <FnCountIterator>
SERIALIZABLE_CLASS_VERSIONS(FnCountIterator)

void FnCountIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnCountIterator, PlanIteratorState>*)this);
}


void FnCountIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnCountIterator::~FnCountIterator() {}


zstring FnCountIterator::getNameAsString() const {
  return "fn:count";
}
// </FnCountIterator>


// <FnAvgIterator>
SERIALIZABLE_CLASS_VERSIONS(FnAvgIterator)

void FnAvgIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnAvgIterator, PlanIteratorState>*)this);
}


void FnAvgIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnAvgIterator::~FnAvgIterator() {}


zstring FnAvgIterator::getNameAsString() const {
  return "fn:avg";
}
// </FnAvgIterator>


// <FnSumIterator>
SERIALIZABLE_CLASS_VERSIONS(FnSumIterator)

void FnSumIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnSumIterator, PlanIteratorState>*)this);
}


void FnSumIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnSumIterator::~FnSumIterator() {}


zstring FnSumIterator::getNameAsString() const {
  return "fn:sum";
}
// </FnSumIterator>


// <FnSumDoubleIterator>
SERIALIZABLE_CLASS_VERSIONS(FnSumDoubleIterator)

void FnSumDoubleIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnSumDoubleIterator, PlanIteratorState>*)this);
}


void FnSumDoubleIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnSumDoubleIterator::~FnSumDoubleIterator() {}


zstring FnSumDoubleIterator::getNameAsString() const {
  return "op:sum_double";
}
// </FnSumDoubleIterator>


// <FnSumFloatIterator>
SERIALIZABLE_CLASS_VERSIONS(FnSumFloatIterator)

void FnSumFloatIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnSumFloatIterator, PlanIteratorState>*)this);
}


void FnSumFloatIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnSumFloatIterator::~FnSumFloatIterator() {}


zstring FnSumFloatIterator::getNameAsString() const {
  return "op:sum_float";
}
// </FnSumFloatIterator>


// <FnSumDecimalIterator>
SERIALIZABLE_CLASS_VERSIONS(FnSumDecimalIterator)

void FnSumDecimalIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnSumDecimalIterator, PlanIteratorState>*)this);
}


void FnSumDecimalIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnSumDecimalIterator::~FnSumDecimalIterator() {}


zstring FnSumDecimalIterator::getNameAsString() const {
  return "op:sum_decimal";
}
// </FnSumDecimalIterator>


// <FnSumIntegerIterator>
SERIALIZABLE_CLASS_VERSIONS(FnSumIntegerIterator)

void FnSumIntegerIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnSumIntegerIterator, PlanIteratorState>*)this);
}


void FnSumIntegerIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnSumIntegerIterator::~FnSumIntegerIterator() {}


zstring FnSumIntegerIterator::getNameAsString() const {
  return "op:sum_integer";
}
// </FnSumIntegerIterator>


// <OpToIterator>
SERIALIZABLE_CLASS_VERSIONS(OpToIterator)

void OpToIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<OpToIterator, OpToIteratorState>*)this);
}


void OpToIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

OpToIterator::~OpToIterator() {}

OpToIteratorState::OpToIteratorState() {}

OpToIteratorState::~OpToIteratorState() {}


void OpToIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theCurInt = numeric_consts<xs_integer>::zero();
  theFirstVal = numeric_consts<xs_integer>::zero();
  theLastVal = numeric_consts<xs_integer>::zero();
}

void OpToIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurInt = numeric_consts<xs_integer>::zero();
  theFirstVal = numeric_consts<xs_integer>::zero();
  theLastVal = numeric_consts<xs_integer>::zero();
}

zstring OpToIterator::getNameAsString() const {
  return "op:to";
}
// </OpToIterator>


// <FnIdIterator>
SERIALIZABLE_CLASS_VERSIONS(FnIdIterator)

void FnIdIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnIdIterator, FnIdIteratorState>*)this);
}


void FnIdIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnIdIterator::~FnIdIterator() {}

FnIdIteratorState::FnIdIteratorState() {}

FnIdIteratorState::~FnIdIteratorState() {}


zstring FnIdIterator::getNameAsString() const {
  return "fn:id";
}
// </FnIdIterator>


// <FnElementWithIdIterator>
SERIALIZABLE_CLASS_VERSIONS(FnElementWithIdIterator)

void FnElementWithIdIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnElementWithIdIterator, FnElementWithIdIteratorState>*)this);
}


void FnElementWithIdIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnElementWithIdIterator::~FnElementWithIdIterator() {}

FnElementWithIdIteratorState::FnElementWithIdIteratorState() {}

FnElementWithIdIteratorState::~FnElementWithIdIteratorState() {}


zstring FnElementWithIdIterator::getNameAsString() const {
  return "fn:element-with-id";
}
// </FnElementWithIdIterator>


// <FnIdRefIterator>
SERIALIZABLE_CLASS_VERSIONS(FnIdRefIterator)

void FnIdRefIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnIdRefIterator, FnIdRefIteratorState>*)this);
}


void FnIdRefIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnIdRefIterator::~FnIdRefIterator() {}

FnIdRefIteratorState::FnIdRefIteratorState() {}

FnIdRefIteratorState::~FnIdRefIteratorState() {}


zstring FnIdRefIterator::getNameAsString() const {
  return "fn:idref";
}
// </FnIdRefIterator>


// <FnDocIterator>
SERIALIZABLE_CLASS_VERSIONS(FnDocIterator)

void FnDocIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnDocIterator, PlanIteratorState>*)this);
}


void FnDocIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnDocIterator::~FnDocIterator() {}


zstring FnDocIterator::getNameAsString() const {
  return "fn:doc";
}
// </FnDocIterator>


// <FnDocAvailableIterator>
SERIALIZABLE_CLASS_VERSIONS(FnDocAvailableIterator)

void FnDocAvailableIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnDocAvailableIterator, PlanIteratorState>*)this);
}


void FnDocAvailableIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnDocAvailableIterator::~FnDocAvailableIterator() {}


zstring FnDocAvailableIterator::getNameAsString() const {
  return "fn:doc-available";
}
// </FnDocAvailableIterator>


// <FnAvailableEnvironmentVariablesIterator>
SERIALIZABLE_CLASS_VERSIONS(FnAvailableEnvironmentVariablesIterator)

void FnAvailableEnvironmentVariablesIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnAvailableEnvironmentVariablesIterator, FnAvailableEnvironmentVariablesIteratorState>*)this);
}


void FnAvailableEnvironmentVariablesIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnAvailableEnvironmentVariablesIterator::~FnAvailableEnvironmentVariablesIterator() {}

FnAvailableEnvironmentVariablesIteratorState::FnAvailableEnvironmentVariablesIteratorState() {}

FnAvailableEnvironmentVariablesIteratorState::~FnAvailableEnvironmentVariablesIteratorState() {}


zstring FnAvailableEnvironmentVariablesIterator::getNameAsString() const {
  return "fn:available-environment-variables";
}
// </FnAvailableEnvironmentVariablesIterator>


// <FnEnvironmentVariableIterator>
SERIALIZABLE_CLASS_VERSIONS(FnEnvironmentVariableIterator)

void FnEnvironmentVariableIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnEnvironmentVariableIterator, PlanIteratorState>*)this);
}


void FnEnvironmentVariableIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnEnvironmentVariableIterator::~FnEnvironmentVariableIterator() {}


zstring FnEnvironmentVariableIterator::getNameAsString() const {
  return "fn:environment-variable";
}
// </FnEnvironmentVariableIterator>


// <FnUnparsedTextIterator>
SERIALIZABLE_CLASS_VERSIONS(FnUnparsedTextIterator)

void FnUnparsedTextIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnUnparsedTextIterator, PlanIteratorState>*)this);
}


void FnUnparsedTextIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnUnparsedTextIterator::~FnUnparsedTextIterator() {}


zstring FnUnparsedTextIterator::getNameAsString() const {
  return "fn:unparsed-text";
}
// </FnUnparsedTextIterator>


// <FnUnparsedTextAvailableIterator>
SERIALIZABLE_CLASS_VERSIONS(FnUnparsedTextAvailableIterator)

void FnUnparsedTextAvailableIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnUnparsedTextAvailableIterator, PlanIteratorState>*)this);
}


void FnUnparsedTextAvailableIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnUnparsedTextAvailableIterator::~FnUnparsedTextAvailableIterator() {}


zstring FnUnparsedTextAvailableIterator::getNameAsString() const {
  return "fn:unparsed-text-available";
}
// </FnUnparsedTextAvailableIterator>


// <FnUnparsedTextLinesIterator>
SERIALIZABLE_CLASS_VERSIONS(FnUnparsedTextLinesIterator)

void FnUnparsedTextLinesIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FnUnparsedTextLinesIterator, FnUnparsedTextLinesIteratorState>*)this);
}


void FnUnparsedTextLinesIterator::accept(PlanIterVisitor& v) const
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnUnparsedTextLinesIterator::~FnUnparsedTextLinesIterator() {}

FnUnparsedTextLinesIteratorState::FnUnparsedTextLinesIteratorState() {}


zstring FnUnparsedTextLinesIterator::getNameAsString() const {
  return "fn:unparsed-text-lines";
}
// </FnUnparsedTextLinesIterator>



}


