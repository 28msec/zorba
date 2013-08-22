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
#include "runtime/json/jsoniq_functions.h"
#include "system/globalenv.h"



namespace zorba {

// <JSONDecodeFromRoundtripIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONDecodeFromRoundtripIterator)

void JSONDecodeFromRoundtripIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<JSONDecodeFromRoundtripIterator, JSONDecodeFromRoundtripIteratorState>*)this);
}


void JSONDecodeFromRoundtripIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONDecodeFromRoundtripIterator::~JSONDecodeFromRoundtripIterator() {}

JSONDecodeFromRoundtripIteratorState::JSONDecodeFromRoundtripIteratorState() {}

JSONDecodeFromRoundtripIteratorState::~JSONDecodeFromRoundtripIteratorState() {}


void JSONDecodeFromRoundtripIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void JSONDecodeFromRoundtripIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </JSONDecodeFromRoundtripIterator>


// <JSONEncodeForRoundtripIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONEncodeForRoundtripIterator)

void JSONEncodeForRoundtripIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<JSONEncodeForRoundtripIterator, JSONEncodeForRoundtripIteratorState>*)this);
}


void JSONEncodeForRoundtripIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONEncodeForRoundtripIterator::~JSONEncodeForRoundtripIterator() {}

JSONEncodeForRoundtripIteratorState::JSONEncodeForRoundtripIteratorState() {}

JSONEncodeForRoundtripIteratorState::~JSONEncodeForRoundtripIteratorState() {}


void JSONEncodeForRoundtripIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void JSONEncodeForRoundtripIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </JSONEncodeForRoundtripIterator>


// <JSONParseIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONParseIterator)

void JSONParseIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<JSONParseIterator, JSONParseIteratorState>*)this);

    ar & theRelativeLocation;
}


void JSONParseIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONParseIterator::~JSONParseIterator() {}

JSONParseIteratorState::JSONParseIteratorState() {}

// </JSONParseIterator>


// <MultiObjectKeysIterator>
SERIALIZABLE_CLASS_VERSIONS(MultiObjectKeysIterator)

void MultiObjectKeysIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<MultiObjectKeysIterator, MultiObjectKeysIteratorState>*)this);
}


void MultiObjectKeysIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

MultiObjectKeysIterator::~MultiObjectKeysIterator() {}

MultiObjectKeysIteratorState::MultiObjectKeysIteratorState() {}

MultiObjectKeysIteratorState::~MultiObjectKeysIteratorState() {}

// </MultiObjectKeysIterator>


// <SingleObjectKeysIterator>
SERIALIZABLE_CLASS_VERSIONS(SingleObjectKeysIterator)

void SingleObjectKeysIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<SingleObjectKeysIterator, SingleObjectKeysIteratorState>*)this);
}


void SingleObjectKeysIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

SingleObjectKeysIterator::~SingleObjectKeysIterator() {}

SingleObjectKeysIteratorState::SingleObjectKeysIteratorState() {}

SingleObjectKeysIteratorState::~SingleObjectKeysIteratorState() {}


void SingleObjectKeysIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void SingleObjectKeysIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </SingleObjectKeysIterator>


// <MultiObjectLookupIterator>
SERIALIZABLE_CLASS_VERSIONS(MultiObjectLookupIterator)

void MultiObjectLookupIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (BinaryBaseIterator<MultiObjectLookupIterator, MultiObjectLookupIteratorState>*)this);
}


void MultiObjectLookupIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

MultiObjectLookupIterator::~MultiObjectLookupIterator() {}

MultiObjectLookupIteratorState::MultiObjectLookupIteratorState() {}

MultiObjectLookupIteratorState::~MultiObjectLookupIteratorState() {}


void MultiObjectLookupIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void MultiObjectLookupIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </MultiObjectLookupIterator>


// <SingleObjectLookupIterator>
SERIALIZABLE_CLASS_VERSIONS(SingleObjectLookupIterator)

void SingleObjectLookupIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (BinaryBaseIterator<SingleObjectLookupIterator, PlanIteratorState>*)this);
}


void SingleObjectLookupIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

SingleObjectLookupIterator::~SingleObjectLookupIterator() {}

// </SingleObjectLookupIterator>


// <JSONObjectProjectIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONObjectProjectIterator)

void JSONObjectProjectIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (BinaryBaseIterator<JSONObjectProjectIterator, JSONObjectProjectIteratorState>*)this);
}


void JSONObjectProjectIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

JSONObjectProjectIterator::~JSONObjectProjectIterator() {}

JSONObjectProjectIteratorState::JSONObjectProjectIteratorState() {}

JSONObjectProjectIteratorState::~JSONObjectProjectIteratorState() {}


void JSONObjectProjectIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void JSONObjectProjectIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </JSONObjectProjectIterator>


// <JSONObjectTrimIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONObjectTrimIterator)

void JSONObjectTrimIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (BinaryBaseIterator<JSONObjectTrimIterator, JSONObjectTrimIteratorState>*)this);
}


void JSONObjectTrimIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

JSONObjectTrimIterator::~JSONObjectTrimIterator() {}

JSONObjectTrimIteratorState::JSONObjectTrimIteratorState() {}

JSONObjectTrimIteratorState::~JSONObjectTrimIteratorState() {}


void JSONObjectTrimIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void JSONObjectTrimIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </JSONObjectTrimIterator>


// <MultiArrayMembersIterator>
SERIALIZABLE_CLASS_VERSIONS(MultiArrayMembersIterator)

void MultiArrayMembersIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<MultiArrayMembersIterator, MultiArrayMembersIteratorState>*)this);
}


void MultiArrayMembersIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

MultiArrayMembersIterator::~MultiArrayMembersIterator() {}

MultiArrayMembersIteratorState::MultiArrayMembersIteratorState() {}

MultiArrayMembersIteratorState::~MultiArrayMembersIteratorState() {}


void MultiArrayMembersIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void MultiArrayMembersIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </MultiArrayMembersIterator>


// <SingleArrayMembersIterator>
SERIALIZABLE_CLASS_VERSIONS(SingleArrayMembersIterator)

void SingleArrayMembersIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<SingleArrayMembersIterator, SingleArrayMembersIteratorState>*)this);
}


void SingleArrayMembersIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

SingleArrayMembersIterator::~SingleArrayMembersIterator() {}

SingleArrayMembersIteratorState::SingleArrayMembersIteratorState() {}

SingleArrayMembersIteratorState::~SingleArrayMembersIteratorState() {}


void SingleArrayMembersIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void SingleArrayMembersIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </SingleArrayMembersIterator>


// <MultiArrayLookupIterator>
SERIALIZABLE_CLASS_VERSIONS(MultiArrayLookupIterator)

void MultiArrayLookupIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (BinaryBaseIterator<MultiArrayLookupIterator, MultiArrayLookupIteratorState>*)this);
}


void MultiArrayLookupIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

MultiArrayLookupIterator::~MultiArrayLookupIterator() {}

MultiArrayLookupIteratorState::MultiArrayLookupIteratorState() {}

MultiArrayLookupIteratorState::~MultiArrayLookupIteratorState() {}


void MultiArrayLookupIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void MultiArrayLookupIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </MultiArrayLookupIterator>


// <SingleArrayLookupIterator>
SERIALIZABLE_CLASS_VERSIONS(SingleArrayLookupIterator)

void SingleArrayLookupIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (BinaryBaseIterator<SingleArrayLookupIterator, PlanIteratorState>*)this);
}


void SingleArrayLookupIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

SingleArrayLookupIterator::~SingleArrayLookupIterator() {}

// </SingleArrayLookupIterator>


// <JSONArraySizeIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONArraySizeIterator)

void JSONArraySizeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<JSONArraySizeIterator, PlanIteratorState>*)this);
}


void JSONArraySizeIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

JSONArraySizeIterator::~JSONArraySizeIterator() {}

// </JSONArraySizeIterator>


// <JSONArrayFlattenIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONArrayFlattenIterator)

void JSONArrayFlattenIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<JSONArrayFlattenIterator, JSONArrayFlattenIteratorState>*)this);
}


void JSONArrayFlattenIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

JSONArrayFlattenIterator::~JSONArrayFlattenIterator() {}

JSONArrayFlattenIteratorState::JSONArrayFlattenIteratorState() {}

JSONArrayFlattenIteratorState::~JSONArrayFlattenIteratorState() {}


void JSONArrayFlattenIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </JSONArrayFlattenIterator>


// <JSONNullIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONNullIterator)

void JSONNullIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NoaryBaseIterator<JSONNullIterator, PlanIteratorState>*)this);
}


void JSONNullIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  

  v.endVisit(*this);
}

JSONNullIterator::~JSONNullIterator() {}

// </JSONNullIterator>


// <JSONObjectInsertIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONObjectInsertIterator)

void JSONObjectInsertIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<JSONObjectInsertIterator, PlanIteratorState>*)this);
}


void JSONObjectInsertIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONObjectInsertIterator::~JSONObjectInsertIterator() {}

// </JSONObjectInsertIterator>


// <JSONArrayInsertIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONArrayInsertIterator)

void JSONArrayInsertIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<JSONArrayInsertIterator, PlanIteratorState>*)this);
}


void JSONArrayInsertIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONArrayInsertIterator::~JSONArrayInsertIterator() {}

// </JSONArrayInsertIterator>


// <JSONDeleteIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONDeleteIterator)

void JSONDeleteIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (BinaryBaseIterator<JSONDeleteIterator, PlanIteratorState>*)this);
}


void JSONDeleteIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

JSONDeleteIterator::~JSONDeleteIterator() {}

// </JSONDeleteIterator>


// <JSONReplaceValueIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONReplaceValueIterator)

void JSONReplaceValueIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<JSONReplaceValueIterator, PlanIteratorState>*)this);

    ar & theCopyInput;
}


void JSONReplaceValueIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONReplaceValueIterator::~JSONReplaceValueIterator() {}

// </JSONReplaceValueIterator>


// <JSONRenameIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONRenameIterator)

void JSONRenameIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<JSONRenameIterator, PlanIteratorState>*)this);
}


void JSONRenameIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONRenameIterator::~JSONRenameIterator() {}

// </JSONRenameIterator>


// <JSONArrayAppendIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONArrayAppendIterator)

void JSONArrayAppendIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<JSONArrayAppendIterator, PlanIteratorState>*)this);
}


void JSONArrayAppendIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONArrayAppendIterator::~JSONArrayAppendIterator() {}

// </JSONArrayAppendIterator>


// <JSONBoxIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONBoxIterator)

void JSONBoxIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<JSONBoxIterator, PlanIteratorState>*)this);
}


void JSONBoxIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

JSONBoxIterator::~JSONBoxIterator() {}

// </JSONBoxIterator>



}


