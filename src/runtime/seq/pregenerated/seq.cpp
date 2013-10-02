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
#include "runtime/seq/seq.h"
#include "system/globalenv.h"


#include "store/api/iterator.h"

namespace zorba {

// <SeqValueIntersectIterator>
SERIALIZABLE_CLASS_VERSIONS(SeqValueIntersectIterator)

void SeqValueIntersectIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SeqValueIntersectIterator, SeqValueIntersectIteratorState>*)this);
}


void SeqValueIntersectIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SeqValueIntersectIterator::~SeqValueIntersectIterator() {}

SeqValueIntersectIteratorState::SeqValueIntersectIteratorState() {}

SeqValueIntersectIteratorState::~SeqValueIntersectIteratorState() {}


void SeqValueIntersectIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void SeqValueIntersectIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </SeqValueIntersectIterator>


// <SeqValueUnionIterator>
SERIALIZABLE_CLASS_VERSIONS(SeqValueUnionIterator)

void SeqValueUnionIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SeqValueUnionIterator, SeqValueUnionIteratorState>*)this);
}


void SeqValueUnionIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SeqValueUnionIterator::~SeqValueUnionIterator() {}

SeqValueUnionIteratorState::SeqValueUnionIteratorState() {}

SeqValueUnionIteratorState::~SeqValueUnionIteratorState() {}


void SeqValueUnionIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void SeqValueUnionIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </SeqValueUnionIterator>


// <SeqValueExceptIterator>
SERIALIZABLE_CLASS_VERSIONS(SeqValueExceptIterator)

void SeqValueExceptIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<SeqValueExceptIterator, SeqValueExceptIteratorState>*)this);
}


void SeqValueExceptIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

SeqValueExceptIterator::~SeqValueExceptIterator() {}

SeqValueExceptIteratorState::SeqValueExceptIteratorState() {}

SeqValueExceptIteratorState::~SeqValueExceptIteratorState() {}


void SeqValueExceptIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void SeqValueExceptIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </SeqValueExceptIterator>



}


