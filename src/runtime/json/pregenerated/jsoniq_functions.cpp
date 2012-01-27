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
// <JSONFlattenIterator>
const char* JSONFlattenIterator::class_name_str = "JSONFlattenIterator";
JSONFlattenIterator::class_factory<JSONFlattenIterator>
JSONFlattenIterator::g_class_factory;

const serialization::ClassVersion 
JSONFlattenIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONFlattenIterator::class_versions_count =
sizeof(JSONFlattenIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONFlattenIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONFlattenIterator::~JSONFlattenIterator() {}

JSONFlattenIteratorState::JSONFlattenIteratorState() {}

JSONFlattenIteratorState::~JSONFlattenIteratorState() {}


void JSONFlattenIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </JSONFlattenIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONParseIterator>
const char* JSONParseIterator::class_name_str = "JSONParseIterator";
JSONParseIterator::class_factory<JSONParseIterator>
JSONParseIterator::g_class_factory;

const serialization::ClassVersion 
JSONParseIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONParseIterator::class_versions_count =
sizeof(JSONParseIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONParseIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONParseIterator::~JSONParseIterator() {}

// </JSONParseIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONNamesIterator>
const char* JSONNamesIterator::class_name_str = "JSONNamesIterator";
JSONNamesIterator::class_factory<JSONNamesIterator>
JSONNamesIterator::g_class_factory;

const serialization::ClassVersion 
JSONNamesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONNamesIterator::class_versions_count =
sizeof(JSONNamesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONNamesIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONNamesIterator::~JSONNamesIterator() {}

JSONNamesIteratorState::JSONNamesIteratorState() {}

JSONNamesIteratorState::~JSONNamesIteratorState() {}


void JSONNamesIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void JSONNamesIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </JSONNamesIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONNameIterator>
const char* JSONNameIterator::class_name_str = "JSONNameIterator";
JSONNameIterator::class_factory<JSONNameIterator>
JSONNameIterator::g_class_factory;

const serialization::ClassVersion 
JSONNameIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONNameIterator::class_versions_count =
sizeof(JSONNameIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONNameIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONNameIterator::~JSONNameIterator() {}

// </JSONNameIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONPairsIterator>
const char* JSONPairsIterator::class_name_str = "JSONPairsIterator";
JSONPairsIterator::class_factory<JSONPairsIterator>
JSONPairsIterator::g_class_factory;

const serialization::ClassVersion 
JSONPairsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONPairsIterator::class_versions_count =
sizeof(JSONPairsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONPairsIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONPairsIterator::~JSONPairsIterator() {}

JSONPairsIteratorState::JSONPairsIteratorState() {}

JSONPairsIteratorState::~JSONPairsIteratorState() {}


void JSONPairsIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void JSONPairsIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </JSONPairsIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONPairAccessorIterator>
const char* JSONPairAccessorIterator::class_name_str = "JSONPairAccessorIterator";
JSONPairAccessorIterator::class_factory<JSONPairAccessorIterator>
JSONPairAccessorIterator::g_class_factory;

const serialization::ClassVersion 
JSONPairAccessorIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONPairAccessorIterator::class_versions_count =
sizeof(JSONPairAccessorIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONPairAccessorIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONPairAccessorIterator::~JSONPairAccessorIterator() {}

// </JSONPairAccessorIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONMemberAccessorIterator>
const char* JSONMemberAccessorIterator::class_name_str = "JSONMemberAccessorIterator";
JSONMemberAccessorIterator::class_factory<JSONMemberAccessorIterator>
JSONMemberAccessorIterator::g_class_factory;

const serialization::ClassVersion 
JSONMemberAccessorIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONMemberAccessorIterator::class_versions_count =
sizeof(JSONMemberAccessorIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONMemberAccessorIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONMemberAccessorIterator::~JSONMemberAccessorIterator() {}

// </JSONMemberAccessorIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONPairOrMemberAccessorIterator>
const char* JSONPairOrMemberAccessorIterator::class_name_str = "JSONPairOrMemberAccessorIterator";
JSONPairOrMemberAccessorIterator::class_factory<JSONPairOrMemberAccessorIterator>
JSONPairOrMemberAccessorIterator::g_class_factory;

const serialization::ClassVersion 
JSONPairOrMemberAccessorIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONPairOrMemberAccessorIterator::class_versions_count =
sizeof(JSONPairOrMemberAccessorIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONPairOrMemberAccessorIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONPairOrMemberAccessorIterator::~JSONPairOrMemberAccessorIterator() {}

// </JSONPairOrMemberAccessorIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONSizeIterator>
const char* JSONSizeIterator::class_name_str = "JSONSizeIterator";
JSONSizeIterator::class_factory<JSONSizeIterator>
JSONSizeIterator::g_class_factory;

const serialization::ClassVersion 
JSONSizeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONSizeIterator::class_versions_count =
sizeof(JSONSizeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONSizeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONSizeIterator::~JSONSizeIterator() {}

// </JSONSizeIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONValuesIterator>
const char* JSONValuesIterator::class_name_str = "JSONValuesIterator";
JSONValuesIterator::class_factory<JSONValuesIterator>
JSONValuesIterator::g_class_factory;

const serialization::ClassVersion 
JSONValuesIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONValuesIterator::class_versions_count =
sizeof(JSONValuesIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONValuesIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONValuesIterator::~JSONValuesIterator() {}

JSONValuesIteratorState::JSONValuesIteratorState() {}

JSONValuesIteratorState::~JSONValuesIteratorState() {}


void JSONValuesIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void JSONValuesIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </JSONValuesIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONValueIterator>
const char* JSONValueIterator::class_name_str = "JSONValueIterator";
JSONValueIterator::class_factory<JSONValueIterator>
JSONValueIterator::g_class_factory;

const serialization::ClassVersion 
JSONValueIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONValueIterator::class_versions_count =
sizeof(JSONValueIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONValueIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONValueIterator::~JSONValueIterator() {}

// </JSONValueIterator>

#endif
// <JSONInsertIntoIterator>
const char* JSONInsertIntoIterator::class_name_str = "JSONInsertIntoIterator";
JSONInsertIntoIterator::class_factory<JSONInsertIntoIterator>
JSONInsertIntoIterator::g_class_factory;

const serialization::ClassVersion 
JSONInsertIntoIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONInsertIntoIterator::class_versions_count =
sizeof(JSONInsertIntoIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONInsertIntoIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONInsertIntoIterator::~JSONInsertIntoIterator() {}

// </JSONInsertIntoIterator>


// <JSONInsertAsFirstIterator>
const char* JSONInsertAsFirstIterator::class_name_str = "JSONInsertAsFirstIterator";
JSONInsertAsFirstIterator::class_factory<JSONInsertAsFirstIterator>
JSONInsertAsFirstIterator::g_class_factory;

const serialization::ClassVersion 
JSONInsertAsFirstIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONInsertAsFirstIterator::class_versions_count =
sizeof(JSONInsertAsFirstIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONInsertAsFirstIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONInsertAsFirstIterator::~JSONInsertAsFirstIterator() {}

// </JSONInsertAsFirstIterator>


// <JSONInsertAfterIterator>
const char* JSONInsertAfterIterator::class_name_str = "JSONInsertAfterIterator";
JSONInsertAfterIterator::class_factory<JSONInsertAfterIterator>
JSONInsertAfterIterator::g_class_factory;

const serialization::ClassVersion 
JSONInsertAfterIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONInsertAfterIterator::class_versions_count =
sizeof(JSONInsertAfterIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONInsertAfterIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONInsertAfterIterator::~JSONInsertAfterIterator() {}

// </JSONInsertAfterIterator>


// <JSONInsertBeforeIterator>
const char* JSONInsertBeforeIterator::class_name_str = "JSONInsertBeforeIterator";
JSONInsertBeforeIterator::class_factory<JSONInsertBeforeIterator>
JSONInsertBeforeIterator::g_class_factory;

const serialization::ClassVersion 
JSONInsertBeforeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONInsertBeforeIterator::class_versions_count =
sizeof(JSONInsertBeforeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONInsertBeforeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONInsertBeforeIterator::~JSONInsertBeforeIterator() {}

// </JSONInsertBeforeIterator>


// <JSONInsertAsLastIterator>
const char* JSONInsertAsLastIterator::class_name_str = "JSONInsertAsLastIterator";
JSONInsertAsLastIterator::class_factory<JSONInsertAsLastIterator>
JSONInsertAsLastIterator::g_class_factory;

const serialization::ClassVersion 
JSONInsertAsLastIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONInsertAsLastIterator::class_versions_count =
sizeof(JSONInsertAsLastIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONInsertAsLastIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

JSONInsertAsLastIterator::~JSONInsertAsLastIterator() {}

// </JSONInsertAsLastIterator>


// <JSONDeleteIterator>
const char* JSONDeleteIterator::class_name_str = "JSONDeleteIterator";
JSONDeleteIterator::class_factory<JSONDeleteIterator>
JSONDeleteIterator::g_class_factory;

const serialization::ClassVersion 
JSONDeleteIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONDeleteIterator::class_versions_count =
sizeof(JSONDeleteIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONDeleteIterator::accept(PlanIterVisitor& v) const {
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


// <JSONRenameIterator>
const char* JSONRenameIterator::class_name_str = "JSONRenameIterator";
JSONRenameIterator::class_factory<JSONRenameIterator>
JSONRenameIterator::g_class_factory;

const serialization::ClassVersion 
JSONRenameIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONRenameIterator::class_versions_count =
sizeof(JSONRenameIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONRenameIterator::accept(PlanIterVisitor& v) const {
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


// <JSONReplaceValueIterator>
const char* JSONReplaceValueIterator::class_name_str = "JSONReplaceValueIterator";
JSONReplaceValueIterator::class_factory<JSONReplaceValueIterator>
JSONReplaceValueIterator::g_class_factory;

const serialization::ClassVersion 
JSONReplaceValueIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONReplaceValueIterator::class_versions_count =
sizeof(JSONReplaceValueIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONReplaceValueIterator::accept(PlanIterVisitor& v) const {
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



}


