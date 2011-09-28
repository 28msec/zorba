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
#include "runtime/numerics/numerics.h"
#include "system/globalenv.h"



namespace zorba {

// <AbsIterator>
const char* AbsIterator::class_name_str = "AbsIterator";
AbsIterator::class_factory<AbsIterator>
AbsIterator::g_class_factory;

const serialization::ClassVersion 
AbsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int AbsIterator::class_versions_count =
sizeof(AbsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void AbsIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

AbsIterator::~AbsIterator() {}

// </AbsIterator>


// <CeilingIterator>
const char* CeilingIterator::class_name_str = "CeilingIterator";
CeilingIterator::class_factory<CeilingIterator>
CeilingIterator::g_class_factory;

const serialization::ClassVersion 
CeilingIterator::class_versions[] ={{ 1, 0x000905, false}};

const int CeilingIterator::class_versions_count =
sizeof(CeilingIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void CeilingIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

CeilingIterator::~CeilingIterator() {}

// </CeilingIterator>


// <FloorIterator>
const char* FloorIterator::class_name_str = "FloorIterator";
FloorIterator::class_factory<FloorIterator>
FloorIterator::g_class_factory;

const serialization::ClassVersion 
FloorIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FloorIterator::class_versions_count =
sizeof(FloorIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FloorIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FloorIterator::~FloorIterator() {}

// </FloorIterator>


// <RoundIterator>
const char* RoundIterator::class_name_str = "RoundIterator";
RoundIterator::class_factory<RoundIterator>
RoundIterator::g_class_factory;

const serialization::ClassVersion 
RoundIterator::class_versions[] ={{ 1, 0x000905, false}};

const int RoundIterator::class_versions_count =
sizeof(RoundIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void RoundIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

RoundIterator::~RoundIterator() {}

// </RoundIterator>


// <RoundHalfToEvenIterator>
const char* RoundHalfToEvenIterator::class_name_str = "RoundHalfToEvenIterator";
RoundHalfToEvenIterator::class_factory<RoundHalfToEvenIterator>
RoundHalfToEvenIterator::g_class_factory;

const serialization::ClassVersion 
RoundHalfToEvenIterator::class_versions[] ={{ 1, 0x000905, false}};

const int RoundHalfToEvenIterator::class_versions_count =
sizeof(RoundHalfToEvenIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void RoundHalfToEvenIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

RoundHalfToEvenIterator::~RoundHalfToEvenIterator() {}

// </RoundHalfToEvenIterator>


// <FormatNumberIterator>
const char* FormatNumberIterator::class_name_str = "FormatNumberIterator";
FormatNumberIterator::class_factory<FormatNumberIterator>
FormatNumberIterator::g_class_factory;

const serialization::ClassVersion 
FormatNumberIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FormatNumberIterator::class_versions_count =
sizeof(FormatNumberIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FormatNumberIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FormatNumberIterator::~FormatNumberIterator() {}

// </FormatNumberIterator>


// <FormatIntegerIterator>
const char* FormatIntegerIterator::class_name_str = "FormatIntegerIterator";
FormatIntegerIterator::class_factory<FormatIntegerIterator>
FormatIntegerIterator::g_class_factory;

const serialization::ClassVersion 
FormatIntegerIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FormatIntegerIterator::class_versions_count =
sizeof(FormatIntegerIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FormatIntegerIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

FormatIntegerIterator::~FormatIntegerIterator() {}

// </FormatIntegerIterator>



}


