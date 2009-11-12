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

#include "runtime/visitors/planiter_visitor.h"
#include "runtime/sequences/sequences.h"
#include "system/globalenv.h"



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


void FnConcatIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theCurIter = 0;
}

void FnConcatIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurIter = 0;
}
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


void FnInsertBeforeIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theCurrentPos = xqp_integer::parseInt(0);
  thePosition = xqp_integer::parseInt(0);
  theTargetItem = NULL;
}

void FnInsertBeforeIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurrentPos = xqp_integer::parseInt(0);
  thePosition = xqp_integer::parseInt(0);
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


void FnRemoveIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theCurrentPos = xqp_integer::parseInt(0);
  thePosition = xqp_integer::parseInt(0);
  theCollator = 0;
}

void FnRemoveIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurrentPos = xqp_integer::parseInt(0);
  thePosition = xqp_integer::parseInt(0);
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


void FnSubsequenceIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theRemaining = xqp_integer::parseInt(0);
}

void FnSubsequenceIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theRemaining = xqp_integer::parseInt(0);
}
// </FnSubsequenceIterator>


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


void OpToIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theCurInt = xqp_integer::parseInt(0);
  theFirstVal = xqp_integer::parseInt(0);
  theLastVal = xqp_integer::parseInt(0);
}

void OpToIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurInt = xqp_integer::parseInt(0);
  theFirstVal = xqp_integer::parseInt(0);
  theLastVal = xqp_integer::parseInt(0);
}
// </OpToIterator>


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


// <FnParseIterator>
const char* FnParseIterator::class_name_str = "FnParseIterator";
FnParseIterator::class_factory<FnParseIterator>
FnParseIterator::g_class_factory;

const serialization::ClassVersion 
FnParseIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FnParseIterator::class_versions_count =
sizeof(FnParseIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FnParseIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FnParseIterator::~FnParseIterator() {}

// </FnParseIterator>



}