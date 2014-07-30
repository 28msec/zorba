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
#include "runtime/numerics/numerics.h"
#include "system/globalenv.h"



namespace zorba {

// <AbsIterator>
SERIALIZABLE_CLASS_VERSIONS(AbsIterator)

void AbsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<AbsIterator, PlanIteratorState>*)this);
}


void AbsIterator::accept(PlanIterVisitor& v) const
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

AbsIterator::~AbsIterator() {}


zstring AbsIterator::getNameAsString() const {
  return "fn:abs";
}
// </AbsIterator>


// <CeilingIterator>
SERIALIZABLE_CLASS_VERSIONS(CeilingIterator)

void CeilingIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<CeilingIterator, PlanIteratorState>*)this);
}


void CeilingIterator::accept(PlanIterVisitor& v) const
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

CeilingIterator::~CeilingIterator() {}


zstring CeilingIterator::getNameAsString() const {
  return "fn:ceiling";
}
// </CeilingIterator>


// <FloorIterator>
SERIALIZABLE_CLASS_VERSIONS(FloorIterator)

void FloorIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FloorIterator, PlanIteratorState>*)this);
}


void FloorIterator::accept(PlanIterVisitor& v) const
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

FloorIterator::~FloorIterator() {}


zstring FloorIterator::getNameAsString() const {
  return "fn:floor";
}
// </FloorIterator>


// <RoundIterator>
SERIALIZABLE_CLASS_VERSIONS(RoundIterator)

void RoundIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<RoundIterator, PlanIteratorState>*)this);
}


void RoundIterator::accept(PlanIterVisitor& v) const
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

RoundIterator::~RoundIterator() {}


zstring RoundIterator::getNameAsString() const {
  return "fn:round";
}
// </RoundIterator>


// <RoundHalfToEvenIterator>
SERIALIZABLE_CLASS_VERSIONS(RoundHalfToEvenIterator)

void RoundHalfToEvenIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<RoundHalfToEvenIterator, PlanIteratorState>*)this);
}


void RoundHalfToEvenIterator::accept(PlanIterVisitor& v) const
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

RoundHalfToEvenIterator::~RoundHalfToEvenIterator() {}


zstring RoundHalfToEvenIterator::getNameAsString() const {
  return "fn:round-half-to-even";
}
// </RoundHalfToEvenIterator>


// <FormatNumberIterator>
SERIALIZABLE_CLASS_VERSIONS(FormatNumberIterator)

void FormatNumberIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FormatNumberIterator, PlanIteratorState>*)this);
}


void FormatNumberIterator::accept(PlanIterVisitor& v) const
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

FormatNumberIterator::~FormatNumberIterator() {}


zstring FormatNumberIterator::getNameAsString() const {
  return "fn:format-number";
}
// </FormatNumberIterator>


// <FormatIntegerIterator>
SERIALIZABLE_CLASS_VERSIONS(FormatIntegerIterator)

void FormatIntegerIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<FormatIntegerIterator, PlanIteratorState>*)this);
}


void FormatIntegerIterator::accept(PlanIterVisitor& v) const
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

FormatIntegerIterator::~FormatIntegerIterator() {}


zstring FormatIntegerIterator::getNameAsString() const {
  return "fn:format-integer";
}
// </FormatIntegerIterator>



}


