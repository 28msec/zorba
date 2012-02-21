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
#include "runtime/random/random.h"
#include "system/globalenv.h"



namespace zorba {

// <SeededRandomIterator>
const char* SeededRandomIterator::class_name_str = "SeededRandomIterator";
SeededRandomIterator::class_factory<SeededRandomIterator>
SeededRandomIterator::g_class_factory;

const serialization::ClassVersion 
SeededRandomIterator::class_versions[] ={{ 1, 0x000905, false}};

const int SeededRandomIterator::class_versions_count =
sizeof(SeededRandomIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void SeededRandomIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SeededRandomIterator::~SeededRandomIterator() {}

SeededRandomIteratorState::SeededRandomIteratorState() {}

SeededRandomIteratorState::~SeededRandomIteratorState() {}


void SeededRandomIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void SeededRandomIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </SeededRandomIterator>


// <RandomIterator>
const char* RandomIterator::class_name_str = "RandomIterator";
RandomIterator::class_factory<RandomIterator>
RandomIterator::g_class_factory;

const serialization::ClassVersion 
RandomIterator::class_versions[] ={{ 1, 0x000905, false}};

const int RandomIterator::class_versions_count =
sizeof(RandomIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void RandomIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

RandomIterator::~RandomIterator() {}

RandomIteratorState::RandomIteratorState() {}

RandomIteratorState::~RandomIteratorState() {}


void RandomIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void RandomIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </RandomIterator>


// <UuidIterator>
const char* UuidIterator::class_name_str = "UuidIterator";
UuidIterator::class_factory<UuidIterator>
UuidIterator::g_class_factory;

const serialization::ClassVersion 
UuidIterator::class_versions[] ={{ 1, 0x000905, false}};

const int UuidIterator::class_versions_count =
sizeof(UuidIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void UuidIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

UuidIterator::~UuidIterator() {}

// </UuidIterator>



}


