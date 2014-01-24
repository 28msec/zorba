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
#include "runtime/random/random.h"
#include "system/globalenv.h"



namespace zorba {

// <SeededRandomIterator>
SERIALIZABLE_CLASS_VERSIONS(SeededRandomIterator)

void SeededRandomIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SeededRandomIterator, SeededRandomIteratorState>*)this);
}


void SeededRandomIterator::accept(PlanIterVisitor& v) const
{
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

zstring SeededRandomIterator::getNameAsString() const {
  return "fn-zorba-random:seeded-random";
}
// </SeededRandomIterator>


// <RandomIterator>
SERIALIZABLE_CLASS_VERSIONS(RandomIterator)

void RandomIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<RandomIterator, RandomIteratorState>*)this);
}


void RandomIterator::accept(PlanIterVisitor& v) const
{
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

zstring RandomIterator::getNameAsString() const {
  return "fn-zorba-random:random";
}
// </RandomIterator>


// <UuidIterator>
SERIALIZABLE_CLASS_VERSIONS(UuidIterator)

void UuidIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<UuidIterator, PlanIteratorState>*)this);
}


void UuidIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

UuidIterator::~UuidIterator() {}


zstring UuidIterator::getNameAsString() const {
  return "fn-zorba-util:uuid";
}
// </UuidIterator>



}


