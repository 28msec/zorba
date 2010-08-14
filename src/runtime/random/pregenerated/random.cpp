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
#include "runtime/random/random.h"
#include "system/globalenv.h"



namespace zorba {

// <NumGenIterator>
const char* NumGenIterator::class_name_str = "NumGenIterator";
NumGenIterator::class_factory<NumGenIterator>
NumGenIterator::g_class_factory;

const serialization::ClassVersion 
NumGenIterator::class_versions[] ={{ 1, 0x000905, false}};

const int NumGenIterator::class_versions_count =
sizeof(NumGenIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void NumGenIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  

  v.endVisit(*this);
}

NumGenIterator::~NumGenIterator() {}

NumGenIteratorState::NumGenIteratorState() {}

NumGenIteratorState::~NumGenIteratorState() {}


void NumGenIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theCurNumber = 0;
}

void NumGenIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theCurNumber = 0;
}
// </NumGenIterator>


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

// </RandomIterator>


// <PseudoRandomIterator>
const char* PseudoRandomIterator::class_name_str = "PseudoRandomIterator";
PseudoRandomIterator::class_factory<PseudoRandomIterator>
PseudoRandomIterator::g_class_factory;

const serialization::ClassVersion 
PseudoRandomIterator::class_versions[] ={{ 1, 0x000905, false}};

const int PseudoRandomIterator::class_versions_count =
sizeof(PseudoRandomIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void PseudoRandomIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

PseudoRandomIterator::~PseudoRandomIterator() {}

// </PseudoRandomIterator>


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


