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
#include "runtime/json/jsoniq_functions.h"
#include "system/globalenv.h"



namespace zorba {

#ifdef ZORBA_WITH_JSON
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

#endif
#ifdef ZORBA_WITH_JSON
// <JSONEncodeForRoundtripIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONEncodeForRoundtripIterator)

void JSONEncodeForRoundtripIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<JSONEncodeForRoundtripIterator, PlanIteratorState>*)this);
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

// </JSONEncodeForRoundtripIterator>

#endif
#ifdef ZORBA_WITH_JSON
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

#endif
#ifdef ZORBA_WITH_JSON
// <JSONObjectNamesIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONObjectNamesIterator)

void JSONObjectNamesIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<JSONObjectNamesIterator, JSONObjectNamesIteratorState>*)this);
}


void JSONObjectNamesIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

JSONObjectNamesIterator::~JSONObjectNamesIterator() {}

JSONObjectNamesIteratorState::JSONObjectNamesIteratorState() {}

JSONObjectNamesIteratorState::~JSONObjectNamesIteratorState() {}


void JSONObjectNamesIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void JSONObjectNamesIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </JSONObjectNamesIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONObjectValueIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONObjectValueIterator)

void JSONObjectValueIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (BinaryBaseIterator<JSONObjectValueIterator, PlanIteratorState>*)this);
}


void JSONObjectValueIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

JSONObjectValueIterator::~JSONObjectValueIterator() {}

// </JSONObjectValueIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONObjectProjectIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONObjectProjectIterator)

void JSONObjectProjectIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (BinaryBaseIterator<JSONObjectProjectIterator, PlanIteratorState>*)this);
}


void JSONObjectProjectIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

JSONObjectProjectIterator::~JSONObjectProjectIterator() {}

// </JSONObjectProjectIterator>

#endif
#ifdef ZORBA_WITH_JSON
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

#endif
#ifdef ZORBA_WITH_JSON
// <JSONArrayMemberIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONArrayMemberIterator)

void JSONArrayMemberIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (BinaryBaseIterator<JSONArrayMemberIterator, PlanIteratorState>*)this);
}


void JSONArrayMemberIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

JSONArrayMemberIterator::~JSONArrayMemberIterator() {}

// </JSONArrayMemberIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONArrayMembersIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONArrayMembersIterator)

void JSONArrayMembersIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<JSONArrayMembersIterator, JSONArrayMembersIteratorState>*)this);
}


void JSONArrayMembersIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

JSONArrayMembersIterator::~JSONArrayMembersIterator() {}

JSONArrayMembersIteratorState::JSONArrayMembersIteratorState() {}

JSONArrayMembersIteratorState::~JSONArrayMembersIteratorState() {}


void JSONArrayMembersIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void JSONArrayMembersIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </JSONArrayMembersIterator>

#endif
#ifdef ZORBA_WITH_JSON
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

#endif
#ifdef ZORBA_WITH_JSON
// <JSONItemAccessorIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONItemAccessorIterator)

void JSONItemAccessorIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (BinaryBaseIterator<JSONItemAccessorIterator, PlanIteratorState>*)this);
}


void JSONItemAccessorIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

JSONItemAccessorIterator::~JSONItemAccessorIterator() {}

// </JSONItemAccessorIterator>

#endif
#ifdef ZORBA_WITH_JSON
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

#endif
#ifdef ZORBA_WITH_JSON
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

#endif
#ifdef ZORBA_WITH_JSON
// <JSONDeleteIterator>
SERIALIZABLE_CLASS_VERSIONS(JSONDeleteIterator)

void JSONDeleteIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<JSONDeleteIterator, PlanIteratorState>*)this);
}


void JSONDeleteIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONDeleteIterator::~JSONDeleteIterator() {}

// </JSONDeleteIterator>

#endif
#ifdef ZORBA_WITH_JSON
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

#endif
#ifdef ZORBA_WITH_JSON
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

#endif
#ifdef ZORBA_WITH_JSON
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

#endif
#ifdef ZORBA_WITH_JSON
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

#endif

}


