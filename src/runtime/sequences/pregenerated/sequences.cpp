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

#include "stdafx.h"
#include "zorbatypes/rchandle.h"
#include "zorbatypes/zstring.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/sequences/sequences.h"
#include "system/globalenv.h"


#include "runtime/util/handle_hashset_item_value.h"

namespace zorba {

// <FnConcatIterator>
FnConcatIterator::class_factory<FnConcatIterator>
FnConcatIterator::g_class_factory;


void FnConcatIterator::accept(PlanIterVisitor& v) const {
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

// </FnConcatIterator>


// <FnIndexOfIterator>
FnIndexOfIterator::class_factory<FnIndexOfIterator>
FnIndexOfIterator::g_class_factory;


void FnIndexOfIterator::accept(PlanIterVisitor& v) const {
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
// </FnIndexOfIterator>


// <FnEmptyIterator>
FnEmptyIterator::class_factory<FnEmptyIterator>
FnEmptyIterator::g_class_factory;


void FnEmptyIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnEmptyIterator::~FnEmptyIterator() {}

// </FnEmptyIterator>


// <FnExistsIterator>
FnExistsIterator::class_factory<FnExistsIterator>
FnExistsIterator::g_class_factory;


void FnExistsIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnExistsIterator::~FnExistsIterator() {}

// </FnExistsIterator>


// <FnDistinctValuesIterator>
FnDistinctValuesIterator::class_factory<FnDistinctValuesIterator>
FnDistinctValuesIterator::g_class_factory;


void FnDistinctValuesIterator::accept(PlanIterVisitor& v) const {
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
// </FnDistinctValuesIterator>


// <FnInsertBeforeIterator>
FnInsertBeforeIterator::class_factory<FnInsertBeforeIterator>
FnInsertBeforeIterator::g_class_factory;


void FnInsertBeforeIterator::accept(PlanIterVisitor& v) const {
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
  theCurrentPos = xs_integer::zero();
  thePosition = xs_integer::zero();
  theTargetItem = NULL;
}

void FnInsertBeforeIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurrentPos = xs_integer::zero();
  thePosition = xs_integer::zero();
  theTargetItem = NULL;
}
// </FnInsertBeforeIterator>


// <FnRemoveIterator>
FnRemoveIterator::class_factory<FnRemoveIterator>
FnRemoveIterator::g_class_factory;


void FnRemoveIterator::accept(PlanIterVisitor& v) const {
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
  theCurrentPos = xs_integer::zero();
  thePosition = xs_integer::zero();
  theCollator = 0;
}

void FnRemoveIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurrentPos = xs_integer::zero();
  thePosition = xs_integer::zero();
  theCollator = 0;
}
// </FnRemoveIterator>


// <FnReverseIterator>
FnReverseIterator::class_factory<FnReverseIterator>
FnReverseIterator::g_class_factory;


void FnReverseIterator::accept(PlanIterVisitor& v) const {
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

// </FnReverseIterator>


// <FnSubsequenceIterator>
FnSubsequenceIterator::class_factory<FnSubsequenceIterator>
FnSubsequenceIterator::g_class_factory;


void FnSubsequenceIterator::accept(PlanIterVisitor& v) const {
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
// </FnSubsequenceIterator>


// <SubsequenceIntIterator>
SubsequenceIntIterator::class_factory<SubsequenceIntIterator>
SubsequenceIntIterator::g_class_factory;


void SubsequenceIntIterator::accept(PlanIterVisitor& v) const {
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
// </SubsequenceIntIterator>


// <SequencePointAccessIterator>
SequencePointAccessIterator::class_factory<SequencePointAccessIterator>
SequencePointAccessIterator::g_class_factory;


void SequencePointAccessIterator::accept(PlanIterVisitor& v) const {
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
// </SequencePointAccessIterator>


// <FnZeroOrOneIterator>
FnZeroOrOneIterator::class_factory<FnZeroOrOneIterator>
FnZeroOrOneIterator::g_class_factory;


void FnZeroOrOneIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnZeroOrOneIterator::~FnZeroOrOneIterator() {}

// </FnZeroOrOneIterator>


// <FnOneOrMoreIterator>
FnOneOrMoreIterator::class_factory<FnOneOrMoreIterator>
FnOneOrMoreIterator::g_class_factory;


void FnOneOrMoreIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnOneOrMoreIterator::~FnOneOrMoreIterator() {}

// </FnOneOrMoreIterator>


// <FnExactlyOneIterator>
FnExactlyOneIterator::class_factory<FnExactlyOneIterator>
FnExactlyOneIterator::g_class_factory;


void FnExactlyOneIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnExactlyOneIterator::~FnExactlyOneIterator() {}

// </FnExactlyOneIterator>


// <FnDeepEqualIterator>
FnDeepEqualIterator::class_factory<FnDeepEqualIterator>
FnDeepEqualIterator::g_class_factory;


void FnDeepEqualIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnDeepEqualIterator::~FnDeepEqualIterator() {}

// </FnDeepEqualIterator>


// <HashSemiJoinIterator>
HashSemiJoinIterator::class_factory<HashSemiJoinIterator>
HashSemiJoinIterator::g_class_factory;


void HashSemiJoinIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

HashSemiJoinIterator::~HashSemiJoinIterator() {}

// </HashSemiJoinIterator>


// <SortSemiJoinIterator>
SortSemiJoinIterator::class_factory<SortSemiJoinIterator>
SortSemiJoinIterator::g_class_factory;


void SortSemiJoinIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SortSemiJoinIterator::~SortSemiJoinIterator() {}

// </SortSemiJoinIterator>


// <FnCountIterator>
FnCountIterator::class_factory<FnCountIterator>
FnCountIterator::g_class_factory;


void FnCountIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnCountIterator::~FnCountIterator() {}

// </FnCountIterator>


// <FnAvgIterator>
FnAvgIterator::class_factory<FnAvgIterator>
FnAvgIterator::g_class_factory;


void FnAvgIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnAvgIterator::~FnAvgIterator() {}

// </FnAvgIterator>


// <FnSumIterator>
FnSumIterator::class_factory<FnSumIterator>
FnSumIterator::g_class_factory;


void FnSumIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnSumIterator::~FnSumIterator() {}

// </FnSumIterator>


// <FnSumDoubleIterator>
FnSumDoubleIterator::class_factory<FnSumDoubleIterator>
FnSumDoubleIterator::g_class_factory;


void FnSumDoubleIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnSumDoubleIterator::~FnSumDoubleIterator() {}

// </FnSumDoubleIterator>


// <FnSumFloatIterator>
FnSumFloatIterator::class_factory<FnSumFloatIterator>
FnSumFloatIterator::g_class_factory;


void FnSumFloatIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnSumFloatIterator::~FnSumFloatIterator() {}

// </FnSumFloatIterator>


// <FnSumDecimalIterator>
FnSumDecimalIterator::class_factory<FnSumDecimalIterator>
FnSumDecimalIterator::g_class_factory;


void FnSumDecimalIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnSumDecimalIterator::~FnSumDecimalIterator() {}

// </FnSumDecimalIterator>


// <FnSumIntegerIterator>
FnSumIntegerIterator::class_factory<FnSumIntegerIterator>
FnSumIntegerIterator::g_class_factory;


void FnSumIntegerIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnSumIntegerIterator::~FnSumIntegerIterator() {}

// </FnSumIntegerIterator>


// <OpToIterator>
OpToIterator::class_factory<OpToIterator>
OpToIterator::g_class_factory;


void OpToIterator::accept(PlanIterVisitor& v) const {
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
  theCurInt = xs_integer::zero();
  theFirstVal = xs_integer::zero();
  theLastVal = xs_integer::zero();
}

void OpToIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurInt = xs_integer::zero();
  theFirstVal = xs_integer::zero();
  theLastVal = xs_integer::zero();
}
// </OpToIterator>


// <FnIdIterator>
FnIdIterator::class_factory<FnIdIterator>
FnIdIterator::g_class_factory;


void FnIdIterator::accept(PlanIterVisitor& v) const {
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

// </FnIdIterator>


// <FnElementWithIdIterator>
FnElementWithIdIterator::class_factory<FnElementWithIdIterator>
FnElementWithIdIterator::g_class_factory;


void FnElementWithIdIterator::accept(PlanIterVisitor& v) const {
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

// </FnElementWithIdIterator>


// <FnIdRefIterator>
FnIdRefIterator::class_factory<FnIdRefIterator>
FnIdRefIterator::g_class_factory;


void FnIdRefIterator::accept(PlanIterVisitor& v) const {
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

// </FnIdRefIterator>


// <FnDocIterator>
FnDocIterator::class_factory<FnDocIterator>
FnDocIterator::g_class_factory;


void FnDocIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnDocIterator::~FnDocIterator() {}

// </FnDocIterator>


// <FnDocAvailableIterator>
FnDocAvailableIterator::class_factory<FnDocAvailableIterator>
FnDocAvailableIterator::g_class_factory;


void FnDocAvailableIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnDocAvailableIterator::~FnDocAvailableIterator() {}

// </FnDocAvailableIterator>


// <FnAvailableEnvironmentVariablesIterator>
FnAvailableEnvironmentVariablesIterator::class_factory<FnAvailableEnvironmentVariablesIterator>
FnAvailableEnvironmentVariablesIterator::g_class_factory;


void FnAvailableEnvironmentVariablesIterator::accept(PlanIterVisitor& v) const {
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

// </FnAvailableEnvironmentVariablesIterator>


// <FnEnvironmentVariableIterator>
FnEnvironmentVariableIterator::class_factory<FnEnvironmentVariableIterator>
FnEnvironmentVariableIterator::g_class_factory;


void FnEnvironmentVariableIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnEnvironmentVariableIterator::~FnEnvironmentVariableIterator() {}

// </FnEnvironmentVariableIterator>


// <FnUnparsedTextIterator>
FnUnparsedTextIterator::class_factory<FnUnparsedTextIterator>
FnUnparsedTextIterator::g_class_factory;


void FnUnparsedTextIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnUnparsedTextIterator::~FnUnparsedTextIterator() {}

// </FnUnparsedTextIterator>


// <FnUnparsedTextAvailableIterator>
FnUnparsedTextAvailableIterator::class_factory<FnUnparsedTextAvailableIterator>
FnUnparsedTextAvailableIterator::g_class_factory;


void FnUnparsedTextAvailableIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnUnparsedTextAvailableIterator::~FnUnparsedTextAvailableIterator() {}

// </FnUnparsedTextAvailableIterator>


// <FnUnparsedTextLinesIterator>
FnUnparsedTextLinesIterator::class_factory<FnUnparsedTextLinesIterator>
FnUnparsedTextLinesIterator::g_class_factory;


void FnUnparsedTextLinesIterator::accept(PlanIterVisitor& v) const {
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

// </FnUnparsedTextLinesIterator>



}


