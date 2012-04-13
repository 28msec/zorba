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
AbsIterator::class_factory<AbsIterator>
AbsIterator::g_class_factory;


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
CeilingIterator::class_factory<CeilingIterator>
CeilingIterator::g_class_factory;


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
FloorIterator::class_factory<FloorIterator>
FloorIterator::g_class_factory;


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
RoundIterator::class_factory<RoundIterator>
RoundIterator::g_class_factory;


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
RoundHalfToEvenIterator::class_factory<RoundHalfToEvenIterator>
RoundHalfToEvenIterator::g_class_factory;


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
FormatNumberIterator::class_factory<FormatNumberIterator>
FormatNumberIterator::g_class_factory;


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
FormatIntegerIterator::class_factory<FormatIntegerIterator>
FormatIntegerIterator::g_class_factory;


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


