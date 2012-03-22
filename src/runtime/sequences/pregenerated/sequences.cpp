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
const char* FnConcatIterator::class_name_str = "FnConcatIterator";
FnConcatIterator::class_factory<FnConcatIterator>
FnConcatIterator::g_class_factory;

const serialization::ClassVersion 
FnConcatIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnConcatIterator::class_versions_count =
sizeof(FnConcatIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnIndexOfIterator::class_name_str = "FnIndexOfIterator";
FnIndexOfIterator::class_factory<FnIndexOfIterator>
FnIndexOfIterator::g_class_factory;

const serialization::ClassVersion 
FnIndexOfIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnIndexOfIterator::class_versions_count =
sizeof(FnIndexOfIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnEmptyIterator::class_name_str = "FnEmptyIterator";
FnEmptyIterator::class_factory<FnEmptyIterator>
FnEmptyIterator::g_class_factory;

const serialization::ClassVersion 
FnEmptyIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnEmptyIterator::class_versions_count =
sizeof(FnEmptyIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnExistsIterator::class_name_str = "FnExistsIterator";
FnExistsIterator::class_factory<FnExistsIterator>
FnExistsIterator::g_class_factory;

const serialization::ClassVersion 
FnExistsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnExistsIterator::class_versions_count =
sizeof(FnExistsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnDistinctValuesIterator::class_name_str = "FnDistinctValuesIterator";
FnDistinctValuesIterator::class_factory<FnDistinctValuesIterator>
FnDistinctValuesIterator::g_class_factory;

const serialization::ClassVersion 
FnDistinctValuesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnDistinctValuesIterator::class_versions_count =
sizeof(FnDistinctValuesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnInsertBeforeIterator::class_name_str = "FnInsertBeforeIterator";
FnInsertBeforeIterator::class_factory<FnInsertBeforeIterator>
FnInsertBeforeIterator::g_class_factory;

const serialization::ClassVersion 
FnInsertBeforeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnInsertBeforeIterator::class_versions_count =
sizeof(FnInsertBeforeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnRemoveIterator::class_name_str = "FnRemoveIterator";
FnRemoveIterator::class_factory<FnRemoveIterator>
FnRemoveIterator::g_class_factory;

const serialization::ClassVersion 
FnRemoveIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnRemoveIterator::class_versions_count =
sizeof(FnRemoveIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnReverseIterator::class_name_str = "FnReverseIterator";
FnReverseIterator::class_factory<FnReverseIterator>
FnReverseIterator::g_class_factory;

const serialization::ClassVersion 
FnReverseIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnReverseIterator::class_versions_count =
sizeof(FnReverseIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnSubsequenceIterator::class_name_str = "FnSubsequenceIterator";
FnSubsequenceIterator::class_factory<FnSubsequenceIterator>
FnSubsequenceIterator::g_class_factory;

const serialization::ClassVersion 
FnSubsequenceIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnSubsequenceIterator::class_versions_count =
sizeof(FnSubsequenceIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* SubsequenceIntIterator::class_name_str = "SubsequenceIntIterator";
SubsequenceIntIterator::class_factory<SubsequenceIntIterator>
SubsequenceIntIterator::g_class_factory;

const serialization::ClassVersion 
SubsequenceIntIterator::class_versions[] ={{ 1, 0x000905, false}};

const int SubsequenceIntIterator::class_versions_count =
sizeof(SubsequenceIntIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* SequencePointAccessIterator::class_name_str = "SequencePointAccessIterator";
SequencePointAccessIterator::class_factory<SequencePointAccessIterator>
SequencePointAccessIterator::g_class_factory;

const serialization::ClassVersion 
SequencePointAccessIterator::class_versions[] ={{ 1, 0x000905, false}};

const int SequencePointAccessIterator::class_versions_count =
sizeof(SequencePointAccessIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnZeroOrOneIterator::class_name_str = "FnZeroOrOneIterator";
FnZeroOrOneIterator::class_factory<FnZeroOrOneIterator>
FnZeroOrOneIterator::g_class_factory;

const serialization::ClassVersion 
FnZeroOrOneIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnZeroOrOneIterator::class_versions_count =
sizeof(FnZeroOrOneIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnOneOrMoreIterator::class_name_str = "FnOneOrMoreIterator";
FnOneOrMoreIterator::class_factory<FnOneOrMoreIterator>
FnOneOrMoreIterator::g_class_factory;

const serialization::ClassVersion 
FnOneOrMoreIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnOneOrMoreIterator::class_versions_count =
sizeof(FnOneOrMoreIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnExactlyOneIterator::class_name_str = "FnExactlyOneIterator";
FnExactlyOneIterator::class_factory<FnExactlyOneIterator>
FnExactlyOneIterator::g_class_factory;

const serialization::ClassVersion 
FnExactlyOneIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnExactlyOneIterator::class_versions_count =
sizeof(FnExactlyOneIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnDeepEqualIterator::class_name_str = "FnDeepEqualIterator";
FnDeepEqualIterator::class_factory<FnDeepEqualIterator>
FnDeepEqualIterator::g_class_factory;

const serialization::ClassVersion 
FnDeepEqualIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnDeepEqualIterator::class_versions_count =
sizeof(FnDeepEqualIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* HashSemiJoinIterator::class_name_str = "HashSemiJoinIterator";
HashSemiJoinIterator::class_factory<HashSemiJoinIterator>
HashSemiJoinIterator::g_class_factory;

const serialization::ClassVersion 
HashSemiJoinIterator::class_versions[] ={{ 1, 0x000905, false}};

const int HashSemiJoinIterator::class_versions_count =
sizeof(HashSemiJoinIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* SortSemiJoinIterator::class_name_str = "SortSemiJoinIterator";
SortSemiJoinIterator::class_factory<SortSemiJoinIterator>
SortSemiJoinIterator::g_class_factory;

const serialization::ClassVersion 
SortSemiJoinIterator::class_versions[] ={{ 1, 0x000905, false}};

const int SortSemiJoinIterator::class_versions_count =
sizeof(SortSemiJoinIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnCountIterator::class_name_str = "FnCountIterator";
FnCountIterator::class_factory<FnCountIterator>
FnCountIterator::g_class_factory;

const serialization::ClassVersion 
FnCountIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnCountIterator::class_versions_count =
sizeof(FnCountIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnAvgIterator::class_name_str = "FnAvgIterator";
FnAvgIterator::class_factory<FnAvgIterator>
FnAvgIterator::g_class_factory;

const serialization::ClassVersion 
FnAvgIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnAvgIterator::class_versions_count =
sizeof(FnAvgIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnSumIterator::class_name_str = "FnSumIterator";
FnSumIterator::class_factory<FnSumIterator>
FnSumIterator::g_class_factory;

const serialization::ClassVersion 
FnSumIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnSumIterator::class_versions_count =
sizeof(FnSumIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnSumDoubleIterator::class_name_str = "FnSumDoubleIterator";
FnSumDoubleIterator::class_factory<FnSumDoubleIterator>
FnSumDoubleIterator::g_class_factory;

const serialization::ClassVersion 
FnSumDoubleIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnSumDoubleIterator::class_versions_count =
sizeof(FnSumDoubleIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnSumFloatIterator::class_name_str = "FnSumFloatIterator";
FnSumFloatIterator::class_factory<FnSumFloatIterator>
FnSumFloatIterator::g_class_factory;

const serialization::ClassVersion 
FnSumFloatIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnSumFloatIterator::class_versions_count =
sizeof(FnSumFloatIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnSumDecimalIterator::class_name_str = "FnSumDecimalIterator";
FnSumDecimalIterator::class_factory<FnSumDecimalIterator>
FnSumDecimalIterator::g_class_factory;

const serialization::ClassVersion 
FnSumDecimalIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnSumDecimalIterator::class_versions_count =
sizeof(FnSumDecimalIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnSumIntegerIterator::class_name_str = "FnSumIntegerIterator";
FnSumIntegerIterator::class_factory<FnSumIntegerIterator>
FnSumIntegerIterator::g_class_factory;

const serialization::ClassVersion 
FnSumIntegerIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnSumIntegerIterator::class_versions_count =
sizeof(FnSumIntegerIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* OpToIterator::class_name_str = "OpToIterator";
OpToIterator::class_factory<OpToIterator>
OpToIterator::g_class_factory;

const serialization::ClassVersion 
OpToIterator::class_versions[] ={{ 1, 0x000905, false}};

const int OpToIterator::class_versions_count =
sizeof(OpToIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnIdIterator::class_name_str = "FnIdIterator";
FnIdIterator::class_factory<FnIdIterator>
FnIdIterator::g_class_factory;

const serialization::ClassVersion 
FnIdIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnIdIterator::class_versions_count =
sizeof(FnIdIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnElementWithIdIterator::class_name_str = "FnElementWithIdIterator";
FnElementWithIdIterator::class_factory<FnElementWithIdIterator>
FnElementWithIdIterator::g_class_factory;

const serialization::ClassVersion 
FnElementWithIdIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnElementWithIdIterator::class_versions_count =
sizeof(FnElementWithIdIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnIdRefIterator::class_name_str = "FnIdRefIterator";
FnIdRefIterator::class_factory<FnIdRefIterator>
FnIdRefIterator::g_class_factory;

const serialization::ClassVersion 
FnIdRefIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnIdRefIterator::class_versions_count =
sizeof(FnIdRefIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnDocIterator::class_name_str = "FnDocIterator";
FnDocIterator::class_factory<FnDocIterator>
FnDocIterator::g_class_factory;

const serialization::ClassVersion 
FnDocIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnDocIterator::class_versions_count =
sizeof(FnDocIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnDocAvailableIterator::class_name_str = "FnDocAvailableIterator";
FnDocAvailableIterator::class_factory<FnDocAvailableIterator>
FnDocAvailableIterator::g_class_factory;

const serialization::ClassVersion 
FnDocAvailableIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnDocAvailableIterator::class_versions_count =
sizeof(FnDocAvailableIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnAvailableEnvironmentVariablesIterator::class_name_str = "FnAvailableEnvironmentVariablesIterator";
FnAvailableEnvironmentVariablesIterator::class_factory<FnAvailableEnvironmentVariablesIterator>
FnAvailableEnvironmentVariablesIterator::g_class_factory;

const serialization::ClassVersion 
FnAvailableEnvironmentVariablesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnAvailableEnvironmentVariablesIterator::class_versions_count =
sizeof(FnAvailableEnvironmentVariablesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnEnvironmentVariableIterator::class_name_str = "FnEnvironmentVariableIterator";
FnEnvironmentVariableIterator::class_factory<FnEnvironmentVariableIterator>
FnEnvironmentVariableIterator::g_class_factory;

const serialization::ClassVersion 
FnEnvironmentVariableIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnEnvironmentVariableIterator::class_versions_count =
sizeof(FnEnvironmentVariableIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnUnparsedTextIterator::class_name_str = "FnUnparsedTextIterator";
FnUnparsedTextIterator::class_factory<FnUnparsedTextIterator>
FnUnparsedTextIterator::g_class_factory;

const serialization::ClassVersion 
FnUnparsedTextIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnUnparsedTextIterator::class_versions_count =
sizeof(FnUnparsedTextIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnUnparsedTextAvailableIterator::class_name_str = "FnUnparsedTextAvailableIterator";
FnUnparsedTextAvailableIterator::class_factory<FnUnparsedTextAvailableIterator>
FnUnparsedTextAvailableIterator::g_class_factory;

const serialization::ClassVersion 
FnUnparsedTextAvailableIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnUnparsedTextAvailableIterator::class_versions_count =
sizeof(FnUnparsedTextAvailableIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* FnUnparsedTextLinesIterator::class_name_str = "FnUnparsedTextLinesIterator";
FnUnparsedTextLinesIterator::class_factory<FnUnparsedTextLinesIterator>
FnUnparsedTextLinesIterator::g_class_factory;

const serialization::ClassVersion 
FnUnparsedTextLinesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnUnparsedTextLinesIterator::class_versions_count =
sizeof(FnUnparsedTextLinesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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


