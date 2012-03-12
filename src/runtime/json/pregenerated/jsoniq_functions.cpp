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

  theChild->accept(v);

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
// <JSONValueAccessorIterator>
const char* JSONValueAccessorIterator::class_name_str = "JSONValueAccessorIterator";
JSONValueAccessorIterator::class_factory<JSONValueAccessorIterator>
JSONValueAccessorIterator::g_class_factory;

const serialization::ClassVersion 
JSONValueAccessorIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONValueAccessorIterator::class_versions_count =
sizeof(JSONValueAccessorIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONValueAccessorIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

JSONValueAccessorIterator::~JSONValueAccessorIterator() {}

// </JSONValueAccessorIterator>

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

  theChild->accept(v);

  v.endVisit(*this);
}

JSONSizeIterator::~JSONSizeIterator() {}

// </JSONSizeIterator>

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

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

JSONMemberAccessorIterator::~JSONMemberAccessorIterator() {}

// </JSONMemberAccessorIterator>

#endif
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

  theChild->accept(v);

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
// <JSONItemAccessorIterator>
const char* JSONItemAccessorIterator::class_name_str = "JSONItemAccessorIterator";
JSONItemAccessorIterator::class_factory<JSONItemAccessorIterator>
JSONItemAccessorIterator::g_class_factory;

const serialization::ClassVersion 
JSONItemAccessorIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONItemAccessorIterator::class_versions_count =
sizeof(JSONItemAccessorIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONItemAccessorIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

JSONItemAccessorIterator::~JSONItemAccessorIterator() {}

// </JSONItemAccessorIterator>

#endif
#ifdef ZORBA_WITH_JSON
// <JSONEmptyItemAccessorIterator>
const char* JSONEmptyItemAccessorIterator::class_name_str = "JSONEmptyItemAccessorIterator";
JSONEmptyItemAccessorIterator::class_factory<JSONEmptyItemAccessorIterator>
JSONEmptyItemAccessorIterator::g_class_factory;

const serialization::ClassVersion 
JSONEmptyItemAccessorIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONEmptyItemAccessorIterator::class_versions_count =
sizeof(JSONEmptyItemAccessorIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONEmptyItemAccessorIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

JSONEmptyItemAccessorIterator::~JSONEmptyItemAccessorIterator() {}

JSONEmptyItemAccessorIteratorState::JSONEmptyItemAccessorIteratorState() {}

JSONEmptyItemAccessorIteratorState::~JSONEmptyItemAccessorIteratorState() {}


void JSONEmptyItemAccessorIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}
// </JSONEmptyItemAccessorIterator>

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

  theChild->accept(v);

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
// <JSONNullIterator>
const char* JSONNullIterator::class_name_str = "JSONNullIterator";
JSONNullIterator::class_factory<JSONNullIterator>
JSONNullIterator::g_class_factory;

const serialization::ClassVersion 
JSONNullIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONNullIterator::class_versions_count =
sizeof(JSONNullIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONNullIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  

  v.endVisit(*this);
}

JSONNullIterator::~JSONNullIterator() {}

// </JSONNullIterator>

#endif
#ifdef ZORBA_WITH_JSON
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

#endif
#ifdef ZORBA_WITH_JSON
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

#endif
#ifdef ZORBA_WITH_JSON
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

#endif
#ifdef ZORBA_WITH_JSON
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

#endif
#ifdef ZORBA_WITH_JSON
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

#endif
#ifdef ZORBA_WITH_JSON
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

#endif
#ifdef ZORBA_WITH_JSON
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

#endif
#ifdef ZORBA_WITH_JSON
// <JSONUnboxingIterator>
const char* JSONUnboxingIterator::class_name_str = "JSONUnboxingIterator";
JSONUnboxingIterator::class_factory<JSONUnboxingIterator>
JSONUnboxingIterator::g_class_factory;

const serialization::ClassVersion 
JSONUnboxingIterator::class_versions[] ={{ 1, 0x000905, false}};

const int JSONUnboxingIterator::class_versions_count =
sizeof(JSONUnboxingIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void JSONUnboxingIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

JSONUnboxingIterator::~JSONUnboxingIterator() {}

// </JSONUnboxingIterator>

#endif

}


